/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         \file  TcpIp_Udp.c
 *        \brief  Implementation of User Datagram Protocol (UDP)
 *
 *      \details  This file is part of the TcpIp module.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp module. >> TcpIp.h
 *********************************************************************************************************************/


/* PRQA S 0828 EOF */ /* MD_MSR_1.1 */

#define TCPIP_UDP_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TcpIp_Cfg.h"
#include "TcpIp_Udp.h"
#include "TcpIp_Lcfg.h"
#include "TcpIp_Udp_Cbk.h"
#include "TcpIp.h"
#include "TcpIp_Priv.h"
#include "TcpIp_Cbk.h"
#include "IpBase.h"
#if (TCPIP_SUPPORT_IPV4 == STD_ON)                                                                                      /* COV_TCPIP_IPV4_ALWAYS_ON */
# include "TcpIp_IpV4.h"
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)                                                                                      /* COV_MSR_UNSUPPORTED */
# include "TcpIp_IpV6.h"
#endif
#include "IpBase_Copy.h"
#include "IpBase_Sock.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#if !defined (STATIC)                                                                                                   /* COV_TCPIP_COMPATIBILITY */
# define STATIC static
#endif

#define TCPIP_UDP_EMPTY_PORT     0x0000u
#define TCPIP_UDP_EMPTY_CHKSUM   0x0000u

#define TCPIP_UDP_HDR_OFS_SRC_PORT  0u
#define TCPIP_UDP_HDR_OFS_DST_PORT (TCPIP_UDP_HDR_OFS_SRC_PORT + 2u)
#define TCPIP_UDP_HDR_OFS_LENGTH   (TCPIP_UDP_HDR_OFS_DST_PORT + 2u)
#define TCPIP_UDP_HDR_OFS_CHECKSUM (TCPIP_UDP_HDR_OFS_LENGTH   + 2u)
#define TCPIP_UDP_HDR_LENGTH       (TCPIP_UDP_HDR_OFS_CHECKSUM + 2u)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  TcpIp_Udp_RemoveTxReqElemFromReqElemList()
 *********************************************************************************************************************/
/*! \brief      Removes the element at the current read position from the UDP TX request list ring buffer.
 *  \details    -
 *  \param[in]  TxReqElemListIdx    Index of a UDP TX request list.
 *                                  \spec requires TxReqElemListIdx < TcpIp_GetSizeOfTxReqElemList(); \endspec
 *  \note       -
 *  \context    TASK
 *  \reentrant  TRUE
 *  \pre        There must be at least one element in the ring buffer.
 *              [CONSTRAINT: TcpIp_GetFillNumOfTxReqElemListDyn(TxReqElemListIdx) > 0]
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_Udp_RemoveTxReqElemFromReqElemList(TcpIp_SizeOfTxReqElemListDynType TxReqElemListIdx);

/**********************************************************************************************************************
 *  TcpIp_Udp_RemoveTxReqElemFromReqElemList()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_Udp_RemoveTxReqElemFromReqElemList(TcpIp_SizeOfTxReqElemListDynType TxReqElemListIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  TCPIP_ASSERT(TxReqElemListIdx < TcpIp_GetSizeOfTxReqElemList());
  TCPIP_ASSERT(TcpIp_GetReadPosOfTxReqElemListDyn(TxReqElemListIdx) >= TcpIp_GetTxReqElemStartIdxOfTxReqElemList(TxReqElemListIdx));
  TCPIP_ASSERT(TcpIp_GetReadPosOfTxReqElemListDyn(TxReqElemListIdx) <  TcpIp_GetTxReqElemEndIdxOfTxReqElemList(TxReqElemListIdx));
  TCPIP_ASSERT(TcpIp_GetFillNumOfTxReqElemListDyn(TxReqElemListIdx) >  0u);

  /* #10 Set read position to next element of ring buffer considering the wrap-around. */
  TcpIp_IncReadPosOfTxReqElemListDyn(TxReqElemListIdx);

  if (TcpIp_GetReadPosOfTxReqElemListDyn(TxReqElemListIdx) == TcpIp_GetTxReqElemEndIdxOfTxReqElemList(TxReqElemListIdx))
  {
    TcpIp_SetReadPosOfTxReqElemListDyn(TxReqElemListIdx, TcpIp_GetTxReqElemStartIdxOfTxReqElemList(TxReqElemListIdx));
  }

  /* #20 Decrease fill level of ring buffer by one. */
  TcpIp_DecFillNumOfTxReqElemListDyn(TxReqElemListIdx);
}

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "TcpIp_MemMap.h"                                                                                               /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined(TCPIP_ENABLE_INT_DEBUG_COUNTERS)                                                                            /* COV_TCPIP_CANOE_DEBUG */
STATIC VAR(uint32, TCPIP_VAR_NO_INIT) TcpIp_Udp_RxIndCounter;
STATIC VAR(uint32, TCPIP_VAR_NO_INIT) TcpIp_Udp_TransmitCounter;
#endif

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "TcpIp_MemMap.h"                                                                                               /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define TCPIP_START_SEC_CODE
#include "TcpIp_MemMap.h"                                                                                               /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
  TcpIp_Udp_VTransmit()
 *********************************************************************************************************************/
/*! \brief         Transmits or queues the transmission of a UDP datagram.
 *  \details       -
 *  \param[in,out] IpTxReqDescPtr  Pointer to IP TX descriptor that was provided by IpVX_ProvideTxBuffer().
 *  \param[in]     IpPayloadBufPtr Pointer to Buffer where the UDP header and payload will be written.
 *                                 \spec requires $lengthOf(IpPayloadBufPtr) >= (TCPIP_UDP_HDR_LEN_BYTE + UdpPayloadLen); \endspec
 *  \param[in]     UdpPayloadLen   Length of the UDP payload. [bytes]
 *  \param[in]     DestSockAddrPtr Destination IP address and port.
 *  \param[in]     TxReqIdx        TX request index that is passed to the IP layer and will be returned in TX confirmation.
 *  \return        E_OK            UDP datagram transmitted or transmit queued.
 *  \return        E_NOT_OK        Transmit not possible.
 *  \note          The payload of the UDP packet must be written in the provided IP buffer before.
 *  \context       TASK|ISR2
 *  \reentrant     TRUE for different IpTxReqDescPtr->SockIdx.
 *  \pre        -
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Udp_VTransmit(
  TCPIP_P2V(TcpIp_IpTxRequestDescriptorType) IpTxReqDescPtr,
  TCPIP_P2V(uint8)                           IpPayloadBufPtr,
  uint16                                     UdpPayloadLen,
  TCPIP_P2C(TcpIp_SockAddrBaseType)          DestSockAddrPtr,
  uint8                                      TxReqIdx);

/**********************************************************************************************************************
 *  TcpIp_Udp_VTxReqListHandleOverflow()
 *********************************************************************************************************************/
/*! \brief      Verifies that there is sufficient space in the TX request table of a socket.
 *  \details    -
 *  \param[in]  SocketUdpIdx Index of a UDP socket.
 *                           \spec requires SocketUdpIdx < TcpIp_GetSizeOfSocketUdpDyn(); \endspec
 *  \return     E_OK         Appending element to TX request list is possible or no TX request list is required.
 *  \return     E_NOT_OK     TX request list is required and full.
 *  \context    TASK|ISR2
 *  \reentrant  TRUE for different SocketUdpIdx.
 *  \pre        -
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Udp_VTxReqListHandleOverflow(
  TcpIp_SocketUdpDynIterType SocketUdpIdx);

/**********************************************************************************************************************
 *  TcpIp_Udp_VValidateChecksum()
 *********************************************************************************************************************/
/*! \brief      Validates the checksum of a received UDP datagram.
 *  \details    -
 *  \param[in]  ReceivedChecksum  Received checksum value that was stored inside the UDP header.
 *  \param[in]  RxSockLocAddrPtr  Destination IP address of the received UDP packet.
 *  \param[in]  RxSockRemAddrPtr  Source IP address of the received UDP packet.
 *  \param[in]  IpPayloadPtr      Payload of the received IP packet (starting with the UDP header).
 *  \param[in]  IpPayloadLen      Length of the IP payload in bytes.
 *  \return     E_OK              Checksum of received UDP datagram matches ReceivedChecksum.
 *  \return     E_NOT_OK          Checksum of received UDP datagram does not match ReceivedChecksum.
 *  \context    ANY
 *  \reentrant  TRUE
 *  \pre        -
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Udp_VValidateChecksum(
    uint16                            ReceivedChecksum,
    TCPIP_P2C(TcpIp_SockAddrBaseType) RxSockLocAddrPtr,
    TCPIP_P2C(TcpIp_SockAddrBaseType) RxSockRemAddrPtr,
    TCPIP_P2C(uint8)                  IpPayloadPtr,
    uint16                            IpPayloadLen);

/**********************************************************************************************************************
 *  TcpIp_Udp_VStoreRequestInRetryQueue()
 *********************************************************************************************************************/
/*! \brief          Binds a UDP or TCP socket to a local IP address and port.
 *  \details        -
 *  \param[in]      SocketUdpIdx        Index of a UDP socket.
 *                                      \spec requires SocketUdpIdx < TcpIp_GetSizeOfSocketUdpDyn(); \endspec
 *  \param[in]      IpTxReqDescPtr      IP TX descriptor that was provided by IpVX_ProvideTxBuffer().
 *  \param[in]      UdpPayloadLen       Length of the UDP payload. [bytes]
 *  \param[in]      DestSockAddrPtr     IP address and port of the destination.
 *  \param[in]      TxReqIdx            TX request index that is passed to the IP layer and will be returned
 *                                      in TX confirmation.
 *  \return         E_OK                Request successfully stored in retry queue.
 *  \return         E_NOT_OK            Retry queue was full or no retry queue attached to the UDP socket.
 *  \pre            SocketUdpIdx was allocated by <Up>_GetSocket().
 *  \context        TASK
 *  \reentrant      TRUE for different socket IDs.
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Udp_VStoreRequestInRetryQueue(
  TcpIp_SocketUdpDynIterType                 SocketUdpIdx,
  TCPIP_P2C(TcpIp_IpTxRequestDescriptorType) IpTxReqDescPtr,
  uint16                                     UdpPayloadLen,
  TCPIP_P2C(TcpIp_SockAddrBaseType)          DestSockAddrPtr,
  uint8                                      TxReqIdx);

/**********************************************************************************************************************
 *  TcpIp_Udp_VMatchingElementInRetryQueue()
 *********************************************************************************************************************/
/*! \brief          Checks if there is already an matching element in the retry queue.
 *  \details        -
 *  \param[in]      SocketUdpIdx        Index of a UDP socket.
 *                                      \spec requires SocketUdpIdx < TcpIp_GetSizeOfSocketUdpDyn(); \endspec
 *  \param[in]      DestSockAddrPtr     IP address and port of the destination.
 *  \return         TRUE                Matching element in retry queue.
 *  \return         FALSE               No matching element in retry queue.
 *  \pre            SocketUdpIdx was allocated by <Up>_GetSocket().
 *  \context        TASK
 *  \reentrant      TRUE for different socket IDs.
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(boolean, TCPIP_CODE) TcpIp_Udp_VMatchingElementInRetryQueue(
  TcpIp_SocketUdpDynIterType                 SocketUdpIdx,
  TCPIP_P2C(TcpIp_SockAddrBaseType)          DestSockAddrPtr);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TcpIp_Udp_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(void, TCPIP_CODE) TcpIp_Udp_Init(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SocketUdpDynIterType  socketUdpIdx;
  TcpIp_TxReqElemListIterType txReqElemListIdx;

  /* ----- Implementation ----------------------------------------------- */
#if defined(TCPIP_ENABLE_INT_DEBUG_COUNTERS)                                                                            /* COV_TCPIP_CANOE_DEBUG */
  /* Debug variables: */
  TcpIp_Udp_RxIndCounter = 0;
  TcpIp_Udp_TransmitCounter = 0;
#endif

  /* #10 Reset UDP dynamic port counter. */
  TcpIp_Udp_DynamicPortCount = 0;

  /* #20 Iterate over all UDP request lists and clear them. */
  for (txReqElemListIdx = 0; txReqElemListIdx < TcpIp_GetSizeOfTxReqElemList(); txReqElemListIdx++)
  {
    TcpIp_SetFillNumOfTxReqElemListDyn(txReqElemListIdx, 0);
    TcpIp_SetWritePosOfTxReqElemListDyn(txReqElemListIdx, TcpIp_GetTxReqElemStartIdxOfTxReqElemList(txReqElemListIdx));
    TcpIp_SetReadPosOfTxReqElemListDyn(txReqElemListIdx,  TcpIp_GetTxReqElemStartIdxOfTxReqElemList(txReqElemListIdx));
    TcpIp_SetSocketUdpDynIdxOfTxReqElemListDyn(txReqElemListIdx, TCPIP_NO_SOCKETUDPDYNIDXOFTXREQELEMLISTDYN);
  }

  /* #30 Clear retry queue. */
  if (TcpIp_GetSizeOfUdpTxRetryQueueElements() > 0u)
  {
    TCPIP_ASSERT(TcpIp_HasUdpTxRetryQueuePoolDesc());
    TCPIP_ASSERT(TcpIp_HasUdpTxRetryQueueElementChain());
    TcpIp_DListInitDesc(TcpIp_GetAddrUdpTxRetryQueuePoolDesc(TCPIP_UDP_TX_RETRY_QUEUE_POOL_IDX),
      TcpIp_GetAddrUdpTxRetryQueueElementChain(0),
      TcpIp_GetSizeOfUdpTxRetryQueueElements());
  }
  else
  {
    TCPIP_ASSERT(!TcpIp_HasUdpTxRetryQueuePoolDesc());
    TCPIP_ASSERT(!TcpIp_HasUdpTxRetryQueueElementChain());
  }

  /* #40 Iterate over all UDP sockets. */
  for (socketUdpIdx = 0; socketUdpIdx < TcpIp_GetSizeOfSocketUdpDyn(); socketUdpIdx++)
  {
    /* #50 Unassign TX request list. */
    TcpIp_SetTxReqElemListIdxOfSocketUdpDyn(socketUdpIdx, TCPIP_NO_TXREQELEMLISTIDXOFSOCKETUDPDYN);

    TcpIp_DListInit(TcpIp_GetAddrTxRetrQueueOfSocketUdpDyn(socketUdpIdx),
      TcpIp_GetAddrUdpTxRetryQueuePoolDesc(TCPIP_UDP_TX_RETRY_QUEUE_POOL_IDX));

    /* By default a socket may use all available retry queue elements. The limit may be changed or disabled using TcpIp_ChangeParameter() later. */
    TcpIp_SetTxRetrQueueMaxNumOfSocketUdpDyn(socketUdpIdx, TcpIp_GetSizeOfUdpTxRetryQueueElements());
  }
} /* TcpIp_Udp_Init() */

/**********************************************************************************************************************
 *  TcpIp_Udp_CloseSocket()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(void, TCPIP_CODE) TcpIp_Udp_CloseSocket(
  TcpIp_SocketUdpDynIterType SocketUdpIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TxReqElemListDynIterType txReqElemListIdx;
  TCPIP_P2V(TcpIp_DListType)     rxRetryQueuePtr;

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_ASSERT(SocketUdpIdx < TcpIp_GetSizeOfSocketUdpDyn());

  /* #10 Clear TX request list. */
  txReqElemListIdx = TcpIp_GetTxReqElemListIdxOfSocketUdpDyn(SocketUdpIdx);

  if (txReqElemListIdx < TcpIp_GetSizeOfTxReqElemList())  /* TxConfirmation is enabled */
  {
    /* reset variables */
    TcpIp_SetFillNumOfTxReqElemListDyn(txReqElemListIdx, 0);
    TcpIp_SetWritePosOfTxReqElemListDyn(txReqElemListIdx, TcpIp_GetTxReqElemStartIdxOfTxReqElemList(txReqElemListIdx));
    TcpIp_SetReadPosOfTxReqElemListDyn(txReqElemListIdx,  TcpIp_GetTxReqElemStartIdxOfTxReqElemList(txReqElemListIdx));
    TcpIp_SetSocketUdpDynIdxOfTxReqElemListDyn(txReqElemListIdx, TCPIP_NO_SOCKETUDPDYNIDXOFTXREQELEMLISTDYN);

    TcpIp_SetTxReqElemListIdxOfSocketUdpDyn(SocketUdpIdx, TCPIP_NO_TXREQELEMLISTIDXOFSOCKETUDPDYN);
  }
  else
  {
    /* nothing to do */
    TCPIP_ASSERT(txReqElemListIdx == TCPIP_NO_TXREQELEMLISTIDXOFSOCKETUDPDYN);
  }

  /* #20 Clear TX retry queue. */
  rxRetryQueuePtr = TcpIp_GetAddrTxRetrQueueOfSocketUdpDyn(SocketUdpIdx);

  if (!TCPIP_DLIST_IS_EMPTY(*rxRetryQueuePtr))
  {
    /* cancel transmit of all retry elements for this socket (release ethernet buffers) */
    TcpIp_DListIdxType udpTxRetryQueueElementsIdx = rxRetryQueuePtr->FirstIdx;

    TCPIP_ASSERT(rxRetryQueuePtr->ElementCount > 0u);

    while (udpTxRetryQueueElementsIdx != TCPIP_DLIST_END_IDX)
    {
      TCPIP_ASSERT(TcpIp_GetAddrUdpTxRetryQueueElements(udpTxRetryQueueElementsIdx)->IpTxRequestDesc.AddressFamily ==
                   TcpIp_GetAddrUdpTxRetryQueueElements(udpTxRetryQueueElementsIdx)->Destination.sa_family);

      TCPIP_ASSERT(udpTxRetryQueueElementsIdx < TcpIp_GetSizeOfUdpTxRetryQueueElements());

      TcpIp_VIpTransmitCancel(&TcpIp_GetAddrUdpTxRetryQueueElements(udpTxRetryQueueElementsIdx)->IpTxRequestDesc, 0);

      udpTxRetryQueueElementsIdx = TCPIP_DLIST_GET_NEXT(udpTxRetryQueueElementsIdx, TcpIp_GetTxRetrQueueOfSocketUdpDyn(SocketUdpIdx));
    }

    TcpIp_DListClear(rxRetryQueuePtr);
  }
  else
  {
    TCPIP_ASSERT(rxRetryQueuePtr->ElementCount == 0u);
  }

  /* By default a socket may use all available retry queue elements. The limit may be changed or disabled using TcpIp_ChangeParameter() later. */
  TcpIp_SetTxRetrQueueMaxNumOfSocketUdpDyn(SocketUdpIdx, TcpIp_GetSizeOfUdpTxRetryQueueElements());
}  /* TcpIp_Udp_CloseSocket */

/**********************************************************************************************************************
 *  TcpIp_Udp_RxIndication()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6080, 6050 1 */ /* MD_MSR_STMIF, MD_TcpIp_STCAL_CslAccess */
FUNC(TcpIp_Udp_ReturnType, TCPIP_CODE) TcpIp_Udp_RxIndication(
    TcpIp_LocalAddrIterType           LocalAddrIdx,
    TCPIP_P2C(TcpIp_SockAddrBaseType) RxSockRemAddrPtr,
    TCPIP_P2V(uint8)                  IpPayloadPtr,
    uint16                            IpPayloadLen,
    boolean                           ChecksumValidated)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_Udp_ReturnType retVal = TCPIP_UDP_E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_ASSERT(LocalAddrIdx     <  TcpIp_GetSizeOfLocalAddr());
  TCPIP_ASSERT(RxSockRemAddrPtr != NULL_PTR);
  TCPIP_ASSERT(IpPayloadPtr     != NULL_PTR);

#if defined(TCPIP_ENABLE_INT_DEBUG_COUNTERS)                                                                            /* COV_TCPIP_CANOE_DEBUG */
  /* Debug variable: */
  TcpIp_Udp_RxIndCounter++;
#endif

  /* #10 Check that UDP header is complete. */
  if (IpPayloadLen >= TCPIP_UDP_HDR_LEN_BYTE)
  {
    IpBase_PortType srcPort       = TCPIP_GET_UINT16(IpPayloadPtr, TCPIP_UDP_HDR_OFS_SRC_PORT);
    IpBase_PortType dstPort       = TCPIP_GET_UINT16(IpPayloadPtr, TCPIP_UDP_HDR_OFS_DST_PORT);
    uint16          udpHdrLenByte = TCPIP_GET_UINT16(IpPayloadPtr, TCPIP_UDP_HDR_OFS_LENGTH);
    uint16          checksum      = TCPIP_GET_UINT16(IpPayloadPtr, TCPIP_UDP_HDR_OFS_CHECKSUM);

    /* #20 Check that value of length field inside UDP header is valid. */
    if ((udpHdrLenByte >= TCPIP_UDP_HDR_LEN_BYTE) && (udpHdrLenByte <= IpPayloadLen))
    {
      TcpIp_SockAddrBaseType rxSockLocAddr;                                                                             /* PRQA S 0759 */ /* MD_MSR_Union */
      boolean                skipChecksumCalc = ChecksumValidated;
      boolean                checksumAllowed = TRUE;

      /* #30 Retrieve source IP address of UDP datagram from IP layer. */
      if (TcpIp_GetIpAddr(TCPIP_LOCAL_ADDR_IDX_TO_ID(LocalAddrIdx), &(rxSockLocAddr.TcpIpSockAddr), NULL_PTR, NULL_PTR) == E_OK)
      {
        TcpIp_SocketDynIterType socketIdx       = TcpIp_GetSizeOfSocketDyn();
        TcpIp_SocketUdpDynIterType socketUdpIdx = TcpIp_GetSizeOfSocketUdpDyn();

        rxSockLocAddr.DomainAndPort.port = TCPIP_HTONS(dstPort);

        /* #40 Identify matching socket based on destination IP address and port of datagram. */
        socketIdx = TcpIp_VRxUdpSockIdxIdent(&rxSockLocAddr, LocalAddrIdx);  /* Identify socket */
        socketUdpIdx = TCPIP_SOCKET_IDX_TO_UDP_IDX(socketIdx);

        /* #50 Check if the received packet uses checksum == 0 and this is an allowed value for the socket. */
        if ((checksum == 0u) && (socketUdpIdx < TcpIp_GetSizeOfSocketUdpDyn()))                                         /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
        {
          if (TcpIp_IsUdpChecksumOfSocketUdpDyn(socketUdpIdx) == TRUE)
          {
            /* UDP checksum == 0 is not allowed for this socket. Only accept the packet if the checksum is checked by HW */
            checksumAllowed = ChecksumValidated;
          }
          else
          {
            /* UDP checksum == 0 is allowed for this socket. Checksum verification can be skipped. */
            skipChecksumCalc = TRUE;
          }
        }

        /* #60 Validate checksum of UDP header if not already done by lower layer (hardware). */
        if (   (checksumAllowed == TRUE)                                                                                /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
            && (   (skipChecksumCalc == TRUE)
                || (TcpIp_Udp_VValidateChecksum(TCPIP_HTONS(checksum), &rxSockLocAddr, RxSockRemAddrPtr, IpPayloadPtr, udpHdrLenByte) == E_OK)))
        {
          TcpIp_SockAddrBaseType  rxSockRemAddr;                                                                        /* PRQA S 0759 */ /* MD_MSR_Union */

          (void)IpBase_CopySockAddr(&rxSockRemAddr.SockAddr, &RxSockRemAddrPtr->SockAddr);                              /* VCA_TCPIP_SOCKET_ADDRESS_COPY */
          rxSockRemAddr.DomainAndPort.port = TCPIP_HTONS(srcPort);


          /* #70 Pass datagram to owner of the identified socket. */
          if (socketIdx < TcpIp_GetSizeOfSocketDyn())
          {
            /* Use the given UDP payload length to determine the amount of data which is forwarded to the upper layer.
             * (This might be less data than the maximal possible value (IpPayloadLen - TCPIP_UDP_HDR_LEN_BYTE), if the
             * UDP packet does not fill the entire IP payload.) */
            uint16 udpPayloadLen = udpHdrLenByte - TCPIP_UDP_HDR_LEN_BYTE;

            TcpIp_RxIndicationFunctions(socketIdx, &rxSockRemAddr, &IpPayloadPtr[TCPIP_UDP_HDR_LENGTH], udpPayloadLen);
            retVal = TCPIP_UDP_OK;
          }
          /* #80 Otherwise: Indicate (via retVal) that no matching socket was found. */
          else
          {
            /* there is no corresponding socket found -> drop message, or send ICMP message */
            /* Increment the measurement data counter for dropped UDP message (due not mapped valid LocalIp and Port) */
#if (TCPIP_SUPPORT_MEASUREMENT_DATA == STD_ON)
            TcpIp_VIncMeasurementDataCounter(TCPIP_MEAS_DROP_UDP);
#endif

            /* #90 Report security event to Intrusion Detection System Manager (IdsM) */
            TcpIp_ReportSecurityEvent(TCPIP_SECURITY_EVENT_INV_PORT_UDP); /*lint !e522 */ /* Function may have no side-effects depending on configuration. */

            retVal = TCPIP_UDP_E_NO_MATCHING_SOCKET;
          }
        }
      }
    }
  }

#if (TCPIP_SUPPORT_MEASUREMENT_DATA == STD_ON)
  if(retVal != TCPIP_UDP_OK)
  {
    /* Packet dropped due to invalid UDP packet format or invalid ports or invalid checksum */
    TcpIp_VIncMeasurementDataCounter(TCPIP_MEAS_VENDOR_SPECIFIC_DROP_LAYER4);
  }
#endif

  return retVal;
}
/**********************************************************************************************************************
 *  TcpIp_Udp_VTxReqListHandleOverflow()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL_INLINE FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Udp_VTxReqListHandleOverflow(
  TcpIp_SocketUdpDynIterType SocketUdpIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if TX confirmation is enabled for the socket. */
  if (TcpIp_GetTxReqElemListIdxOfSocketUdpDyn(SocketUdpIdx) != TCPIP_NO_TXREQELEMLISTIDXOFSOCKETUDPDYN)
  {
    TcpIp_SizeOfTxReqElemListDynType txReqElemListIdx = TcpIp_GetTxReqElemListIdxOfSocketUdpDyn(SocketUdpIdx);

    /* #20 Check and if there is enough space in TX request list. */
    if (TcpIp_GetFillNumOfTxReqElemListDyn(txReqElemListIdx) == TcpIp_GetTxReqElemLengthOfTxReqElemList(txReqElemListIdx))
    {
      /* TcpIp_Udp_TxReqList is full */
      retVal = E_NOT_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Udp_RequestTxBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(BufReq_ReturnType, TCPIP_CODE) TcpIp_Udp_RequestTxBuffer(
  TcpIp_SocketUdpDynIterType         SocketUdpIdx,
  TCPIP_P2C(TcpIp_SockAddrBaseType)  DestinationPtr,
  TCPIP_P2V(TcpIp_Uint8P2V)          BufPtr,
  TCPIP_P2V(uint16)                  BufLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  BufReq_ReturnType       bufRetValue = BUFREQ_E_NOT_OK;
  TcpIp_SocketDynIterType socketIdx = TCPIP_UDP_IDX_TO_SOCKET_IDX(SocketUdpIdx);

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_ASSERT(TCPIP_SOCKET_IDX_IS_UDP(SocketUdpIdx));
  TCPIP_ASSERT(DestinationPtr != NULL_PTR);
  TCPIP_ASSERT(BufPtr    != NULL_PTR);
  TCPIP_ASSERT(BufLenPtr != NULL_PTR);

  /* #10 Check if there is sufficient space in the TX request list, if TX confirmation is enabled for the socket.  */
  if (TcpIp_Udp_VTxReqListHandleOverflow(SocketUdpIdx) == E_OK)
  {
    /* there is a valid free request table element available */
    /* -> check if IP can provide a buffer / has already resolved the address */
    uint16           ipBufferLen        = (*BufLenPtr) + TCPIP_UDP_HDR_LEN_BYTE;
    TCPIP_P2V(uint8) ipBufferPtr        = NULL_PTR;
    boolean          forceProvidePuffer = FALSE;

    /* #20 Notify IP layer that it shall provide a buffer even if link-layer address resolution is incomplete,
           if the socket uses a retry queue. */
    if (TcpIp_GetTxRetrQueueMaxNumOfSocketUdpDyn(SocketUdpIdx) > 0u)
    {
      forceProvidePuffer = TRUE;
    }
    /* Else: forceProvidePuffer remains FALSE */

    /* #30 Get TX buffer from IP layer. */
    switch (DestinationPtr->sa_family)
    {
#if (TCPIP_SUPPORT_IPV4 == STD_ON)                                                                                      /* COV_TCPIP_IPV4_ALWAYS_ON */
    case IPBASE_AF_INET:
      {
        TcpIp_LocalAddrV4IterType ipV4AddrIdx = TcpIp_GetTxIpAddrIdxOfSocketDyn(socketIdx);

        /* Store the transport protocol information in the tx descriptor */
        TcpIp_GetAddrIpTxRequestDescriptorOfSocketUdpDyn(SocketUdpIdx)->XptProtocol = IPV4_IP_PROTOCOL_UDP;

        bufRetValue = IpV4_Ip_ProvideTxBuffer(&ipV4AddrIdx, socketIdx, &DestinationPtr->SockAddrIn,
                        &ipBufferPtr, &ipBufferLen,
                        TcpIp_GetAddrIpTxRequestDescriptorOfSocketUdpDyn(SocketUdpIdx), forceProvidePuffer);

        break;
      }
#endif

#if (TCPIP_SUPPORT_IPV6 == STD_ON)                                                                                      /* COV_MSR_UNSUPPORTED */
    case IPBASE_AF_INET6:
      {
        TcpIp_LocalAddrV6IterType ipV6AddrIdx = TcpIp_GetTxIpAddrIdxOfSocketDyn(socketIdx);

        bufRetValue = IpV6_ProvideTxBuffer(&ipV6AddrIdx, socketIdx, &DestinationPtr->SockAddrIn6.sin6_addr,
                        &ipBufferPtr, &ipBufferLen, TcpIp_GetAddrIpTxRequestDescriptorOfSocketUdpDyn(SocketUdpIdx),
                        TCPIP_PROTOCOL_UDP, forceProvidePuffer);

        break;
      }
#endif

    default:
      {
        /* invalid address family */
        bufRetValue = BUFREQ_E_NOT_OK;
        break;
      }
    }

    /* #40 Update output parameters and socket variables. */
    if (ipBufferPtr != NULL_PTR)
    {
      /*@ assert $external(ipBufferPtr); */                                                                             /* VCA_TCPIP_IP_BUFFER_PTR */
      (*BufPtr)     = &ipBufferPtr[TCPIP_UDP_HDR_LEN_BYTE];
      (*BufLenPtr)  = (uint16)(ipBufferLen - TCPIP_UDP_HDR_LEN_BYTE);

      TcpIp_SetTxReqIpBufPtrOfSocketUdpDyn(SocketUdpIdx, ipBufferPtr);
    }
  }
  else
  {
    bufRetValue = BUFREQ_E_BUSY;
  }

  return bufRetValue;
}  /* TcpIp_Udp_RequestTxBuffer */

/**********************************************************************************************************************
 *  TcpIp_Udp_FragmentRequestTxBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Udp_FragmentRequestTxBuffer(
  TcpIp_SocketUdpDynIterType  SocketUdpIdx,
  IpBase_FamilyType           AddrFamily,
  TCPIP_P2V(TcpIp_Uint8P2V)   BufPtrPtr,                                                                                /* PRQA S 3673 */ /* MD_TCPIP_Rule8.13_CfgSpecific */
  TCPIP_P2V(uint16)           BufLenPtr)                                                                                /* PRQA S 3673 */ /* MD_TCPIP_Rule8.13_CfgSpecific */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Forward call to IPv4 module, if addrFamily is INET. */
#if (TCPIP_SUPPORT_IPV4 == STD_ON)                                                                                      /* COV_TCPIP_IPV4_ALWAYS_ON */
  if (AddrFamily == IPBASE_AF_INET)
  {
    retVal = IpV4_Ip_FragmentProvideTxBuffer(TcpIp_GetAddrIpTxRequestDescriptorOfSocketUdpDyn(SocketUdpIdx),
      BufPtrPtr, BufLenPtr);
  }
  /* #20 Otherwise return E_NOT_OK. */
  else
#else
  TCPIP_DUMMY_STATEMENT_CONST(AddrFamily);                                                                              /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
#endif
  {
    /* PRQA S 3112 3 */ /* MD_MSR_DummyStmt */
    TCPIP_DUMMY_STATEMENT_CONST(SocketUdpIdx);                                                                          /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
    TCPIP_DUMMY_STATEMENT_CONST(BufPtrPtr);                                                                             /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
    TCPIP_DUMMY_STATEMENT_CONST(BufLenPtr);                                                                             /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */

    /* Only IPv4 does provide multiple buffer fragments. */
  }

  return retVal;
} /* TcpIp_Udp_FragmentRequestTxBuffer() */

/**********************************************************************************************************************
 *  TcpIp_Udp_TransmitCancel()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_Udp_TransmitCancel(
  TcpIp_SocketUdpDynIterType SocketUdpIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Forward call to IP layer */
  TcpIp_VIpTransmitCancel(TcpIp_GetAddrIpTxRequestDescriptorOfSocketUdpDyn(SocketUdpIdx), 0);
}

/**********************************************************************************************************************
 *  TcpIp_Udp_Transmit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Udp_Transmit(
  TcpIp_SocketUdpDynIterType        SocketUdpIdx,
  uint16                            UdpPayloadLen,
  TCPIP_P2C(TcpIp_SockAddrBaseType) DestSockAddrPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType                retVal           = E_NOT_OK;
  TcpIp_SizeOfTxReqElemType     txReqElemIdx     = 0u;
  TcpIp_SizeOfTxReqElemListType txReqElemListIdx = TcpIp_GetSizeOfTxReqElemList();
  TCPIP_P2V(uint8)              txReqIpBufPtr = TcpIp_GetTxReqIpBufPtrOfSocketUdpDyn(SocketUdpIdx);;

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_ASSERT(TCPIP_SOCKET_IDX_IS_UDP(SocketUdpIdx));

#if defined(TCPIP_ENABLE_INT_DEBUG_COUNTERS)                                                                            /* COV_TCPIP_CANOE_DEBUG */
  TcpIp_Udp_TransmitCounter++;  /* for debugging purposes only */
#endif

  /* #10 Prepare entry in TX request list, if TxConfirmation is configured. */
  TCPIP_VENTER_CRITICAL_SECTION();

  txReqElemListIdx = TcpIp_GetTxReqElemListIdxOfSocketUdpDyn(SocketUdpIdx);

  if (txReqElemListIdx < TcpIp_GetSizeOfTxReqElemList())  /* TxConfirmation is enabled */
  {
    /* take free TcpIp_Udp_TxReqList element. */
    txReqElemIdx = TcpIp_GetWritePosOfTxReqElemListDyn(txReqElemListIdx);
    /*@ assert txReqElemIdx < TcpIp_GetSizeOfTxReqElem(); */                                                            /* VCA_TCPIP_WritePosOfTxReqElemListDyn */

    TCPIP_ASSERT(txReqElemIdx >= TcpIp_GetTxReqElemStartIdxOfTxReqElemList(txReqElemListIdx));
    TCPIP_ASSERT(txReqElemIdx  < TcpIp_GetTxReqElemEndIdxOfTxReqElemList(txReqElemListIdx));

    /* fill TxReqList element */
    TcpIp_SetTxReqElemDataLenByteOfTxReqElem(txReqElemIdx, UdpPayloadLen);
    TcpIp_SetTxReqElemTransmittedOfTxReqElem(txReqElemIdx, FALSE);
  }
  else
  {
    TCPIP_ASSERT(txReqElemListIdx == TCPIP_NO_TXREQELEMLISTIDXOFSOCKETUDPDYN);
  }

  TCPIP_VLEAVE_CRITICAL_SECTION();

  /* #20 Send UDP message. */
  {
    TCPIP_P2V(TcpIp_IpTxRequestDescriptorType) ipTxReqDescPtr = TcpIp_GetAddrIpTxRequestDescriptorOfSocketUdpDyn(SocketUdpIdx);
    /*@ assert $external(txReqIpBufPtr) && ($lengthOf(txReqIpBufPtr) >= TCPIP_UDP_HDR_LEN_BYTE + UdpPayloadLen); */     /* VCA_TCPIP_IP_BUFFER_PTR_FOR_UDP */

    retVal = TcpIp_Udp_VTransmit(ipTxReqDescPtr, txReqIpBufPtr, UdpPayloadLen, DestSockAddrPtr, txReqElemIdx);          /* VCA_TCPIP_IP_BUFFER_PTR_FOR_UDP */

  }
  /* #30 Update entry in TX request list, if TxConfirmation is configured. */
  if (txReqElemListIdx < TcpIp_GetSizeOfTxReqElemList())
  {
    if (retVal == E_OK)
    {
      TCPIP_VENTER_CRITICAL_SECTION();

      /* update list variables */
      TcpIp_IncWritePosOfTxReqElemListDyn(txReqElemListIdx);

      if (TcpIp_GetWritePosOfTxReqElemListDyn(txReqElemListIdx) == TcpIp_GetTxReqElemEndIdxOfTxReqElemList(txReqElemListIdx))
      {
        TcpIp_SetWritePosOfTxReqElemListDyn(txReqElemListIdx, TcpIp_GetTxReqElemStartIdxOfTxReqElemList(txReqElemListIdx));
      }

      TcpIp_IncFillNumOfTxReqElemListDyn(txReqElemListIdx);

      TCPIP_VLEAVE_CRITICAL_SECTION();
    }
    else
    {
      /* empty TxReqList element */
      TCPIP_ASSERT(txReqElemListIdx == TCPIP_NO_TXREQELEMLISTIDXOFSOCKETUDPDYN);
      TcpIp_SetTxReqElemDataLenByteOfTxReqElem(txReqElemIdx, 0);
    }
  }

  return retVal;
}  /* TcpIp_Udp_Transmit() */

/**********************************************************************************************************************
 *  TcpIp_Udp_TxConfirmation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(void, TCPIP_CODE) TcpIp_Udp_TxConfirmation(
  TcpIp_SocketUdpDynIterType SocketUdpIdx,
  uint8                      TxReqElemIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTxReqElemListDynType txReqElemListIdx;

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_ASSERT(SocketUdpIdx < TcpIp_GetSizeOfSocketUdpDyn());

  txReqElemListIdx = TcpIp_GetTxReqElemListIdxOfSocketUdpDyn(SocketUdpIdx);

  /* #10 Check if a TX request list is assigned to the UDP socket. */
  if (txReqElemListIdx < TcpIp_GetSizeOfTxReqElemList())  /* TxConfirmation is enabled */
  {
    /* #20 Check if TxReqElemIdx is first element of TX request list. */
    if (TcpIp_GetReadPosOfTxReqElemListDyn(txReqElemListIdx) == TxReqElemIdx)
    {
      /* #30 Call TxConfirmation of the socket owner. */
      TcpIp_VSockTxConfirmation(SocketUdpIdx, TcpIp_GetTxReqElemDataLenByteOfTxReqElem(TxReqElemIdx));
      TcpIp_SetTxReqElemDataLenByteOfTxReqElem(TxReqElemIdx, 0);

      TCPIP_VENTER_CRITICAL_SECTION();

      /* #40 Remove element from TX reqiest list. */
      TcpIp_Udp_RemoveTxReqElemFromReqElemList(txReqElemListIdx);

      TCPIP_VLEAVE_CRITICAL_SECTION();
    }
    /* #50 Otherwise: Mark element for later confirmation. */
    else
    {
      TcpIp_SetTxReqElemTransmittedOfTxReqElem(TxReqElemIdx, TRUE);
    }
  }
  else
  {
    TCPIP_ASSERT(txReqElemListIdx == TCPIP_NO_TXREQELEMLISTIDXOFSOCKETUDPDYN);
  }
}  /* TcpIp_Udp_TxConfirmation() */

/**********************************************************************************************************************
 *  TcpIp_Udp_MainFunctionRx()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6050, 6080 1 */ /* MD_TcpIp_STCAL_CslAccess, MD_MSR_STMIF */
FUNC(void, TCPIP_CODE) TcpIp_Udp_MainFunctionRx(TcpIp_OsApplicationType ApplId)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SocketUdpDynIterType socketUdpIdx;

  /* ----- Implementation ----------------------------------------------- */
#if (TCPIP_MULTICORE_SUPPORT_ENABLED == STD_OFF)                                                                        /* COV_TCPIP_MULTICORE_SUPPORT_ALWAYS_OFF */
  TCPIP_DUMMY_STATEMENT_CONST(ApplId);                                                                                  /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
#endif

  /* #10 Iterate over all UDP sockets. */
  for (socketUdpIdx = 0; socketUdpIdx < TcpIp_GetSizeOfSocketUdpDyn(); socketUdpIdx++)
  {
#if (TCPIP_MULTICORE_SUPPORT_ENABLED == STD_ON)                                                                         /* COV_TCPIP_MULTICORE_SUPPORT_NEVER_ON */
    TcpIp_SocketDynIterType socketIdx = TCPIP_UDP_IDX_TO_SOCKET_IDX(socketUdpIdx);

    /* Only process the socket assigned to corresponding application or main application if socket is unassigned */
    if (ApplId == TcpIp_GetApplIdOfSocketDyn(socketIdx))
#endif
    {
      TcpIp_SizeOfTxReqElemListType txReqElemListIdx = TcpIp_GetTxReqElemListIdxOfSocketUdpDyn(socketUdpIdx);
      boolean issueTxConf = (boolean)(txReqElemListIdx < TcpIp_GetSizeOfTxReqElemList());                               /* PRQA S 4304 */ /* MD_MSR_AutosarBoolean */

      /* #20 Iterate over the entries in the TxReqList of the socket, if socket uses optional TxConfirmation feature. */
      while (issueTxConf == TRUE)                                                                                       /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
      {
        /*@ assert txReqElemListIdx < TcpIp_GetSizeOfTxReqElemList(); */                                                /* VCA_TCPIP_RUNTIME_CHECK_PRESENT_IN_SAME_FUNCTION */
        TCPIP_VENTER_CRITICAL_SECTION();

        /* #30 Remove entry from the ReqList, if transmission of request has been confirmed. */
        if (TcpIp_GetFillNumOfTxReqElemListDyn(txReqElemListIdx) > 0u)
        {
          TcpIp_SizeOfTxReqElemType txReqElemIdx = TcpIp_GetReadPosOfTxReqElemListDyn(txReqElemListIdx);
          uint16                    txConfLen    = TcpIp_GetTxReqElemDataLenByteOfTxReqElem(txReqElemIdx);

          if (TcpIp_IsTxReqElemTransmittedOfTxReqElem(txReqElemIdx) == TRUE)
          {
            /* inc ReadPos */
            TcpIp_Udp_RemoveTxReqElemFromReqElemList(txReqElemListIdx);
          }
          else
          {
            issueTxConf = FALSE;
          }

          if (issueTxConf == TRUE)
          {
            /* #40 Forward TxConfirmation to TcpIpSocketOwner. */
            TCPIP_VLEAVE_CRITICAL_SECTION(); /* upper layer must not be called within critical section. */
            TcpIp_VSockTxConfirmation(socketUdpIdx, txConfLen);
          }
          else
          {
            /* no pending element at the start of the list */
            issueTxConf = FALSE;
            TCPIP_VLEAVE_CRITICAL_SECTION();
          }
        }
        else
        {
          /* no list element available */
          issueTxConf = FALSE;
          TCPIP_VLEAVE_CRITICAL_SECTION();
        }
      }
    }
  }
} /* TcpIp_Udp_MainFunctionRx() */

/**********************************************************************************************************************
 * TcpIp_Udp_MainFunctionTx()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_Udp_MainFunctionTx(TcpIp_OsApplicationType ApplId)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SocketUdpDynIterType socketUdpIdx;

  /* ----- Implementation ----------------------------------------------- */
#if (TCPIP_MULTICORE_SUPPORT_ENABLED == STD_OFF)                                                                        /* COV_TCPIP_MULTICORE_SUPPORT_ALWAYS_OFF */
  TCPIP_DUMMY_STATEMENT_CONST(ApplId);                                                                                  /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
#endif

  /* #10 Try to send UDP packets that have been queued because link-layer address resolution was not completed. */
  for (socketUdpIdx = 0; socketUdpIdx < TcpIp_GetSizeOfSocketUdpDyn(); socketUdpIdx++)
  {
#if (TCPIP_MULTICORE_SUPPORT_ENABLED == STD_ON)                                                                         /* COV_TCPIP_MULTICORE_SUPPORT_NEVER_ON */
    TcpIp_SocketDynIterType socketIdx = TCPIP_UDP_IDX_TO_SOCKET_IDX(socketUdpIdx);

    /* Only process the socket assigned to corresponding application or main application if socket is unassigned */
    if (ApplId == TcpIp_GetApplIdOfSocketDyn(socketIdx))
#endif
    {
      if (TcpIp_SocketIsOnHold(TCPIP_SOCKET_IDX_TO_ID(TCPIP_UDP_IDX_TO_SOCKET_IDX(socketUdpIdx))) == FALSE)
      {
        TcpIp_Udp_SendRetryQueueIfPossible(socketUdpIdx);
      }
    }
  }
} /* TcpIp_Udp_MainFunctionTx() */

/**********************************************************************************************************************
 *  TcpIp_Udp_ResetSocket()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_Udp_ResetSocket(TcpIp_SocketUdpDynIterType SocketUdpIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SocketDynIterType         socketIdx = TCPIP_UDP_IDX_TO_SOCKET_IDX(SocketUdpIdx);
  TcpIp_SocketOwnerConfigIterType socketOwnerCfgIdx;

  /* ----- Implementation ----------------------------------------------- */
  socketOwnerCfgIdx = TcpIp_GetSocketOwnerConfigIdxOfSocketDyn(socketIdx);
  /*@ assert socketOwnerCfgIdx < TcpIp_GetSizeOfSocketOwnerConfig(); */                                                 /* VCA_TCPIP_SOCKETOWNERIDX */

  TCPIP_ASSERT(TCPIP_SOCKET_IDX_IS_UDP(socketIdx));
  TCPIP_ASSERT(socketOwnerCfgIdx < TcpIp_GetSizeOfSocketOwnerConfig());

  /* #10 Call TcpIp_Udp_CloseSocket(). */
  TcpIp_Udp_CloseSocket(SocketUdpIdx);

  /* #20 Call TcpIp_TcpIpEvent(TCPIP_UDP_CLOSED) of socket owner. */
  TcpIp_TcpIpEventFunctions(socketOwnerCfgIdx, socketIdx, TCPIP_UDP_CLOSED);
}

/**********************************************************************************************************************
 *  TcpIp_Udp_ChangeParameter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Udp_ChangeParameter(
  TcpIp_SizeOfSocketDynType                  SocketIdx,
  TcpIp_ParamIdType                          ParameterId,
  P2CONST(uint8, AUTOMATIC, TCPIP_APPL_DATA) ParameterValuePtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  TCPIP_ASSERT(SocketIdx < TcpIp_GetSizeOfSocketDyn());

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Set socket option based on ParameterId if the socket is a UDP socket. */
  if (TCPIP_SOCKET_IDX_IS_UDP(SocketIdx))
  {
    TcpIp_SizeOfSocketUdpDynType socketUdpIdx = TCPIP_SOCKET_IDX_TO_UDP_IDX(SocketIdx);
    switch (ParameterId)
    {
    case TCPIP_PARAMID_V_UDP_TXREQLISTSIZE:
    {
      /* #20 Handle Parameter TCPIP_PARAMID_V_UDP_TXREQLISTSIZE (TX confirmation feature). */
      uint8 RequestedListSize = *ParameterValuePtr;
      TcpIp_TxReqElemListDynIterType txReqElemListIdx;

      TCPIP_VENTER_MC_ALWAYS_CRITICAL_SECTION();     /* lock cross core interrupts */

      /* choose a matching rx buffer and assign it to the socket / TCP connection */
      for (txReqElemListIdx = 0; txReqElemListIdx < TcpIp_GetSizeOfTxReqElemList(); txReqElemListIdx++)
      {
        if (   (TcpIp_GetSocketUdpDynIdxOfTxReqElemListDyn(txReqElemListIdx) == TCPIP_NO_SOCKETUDPDYNIDXOFTXREQELEMLISTDYN)/* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
            && (RequestedListSize == TcpIp_GetTxReqElemLengthOfTxReqElemList(txReqElemListIdx)))
        {
          /* found a free and matching TxReqList */
          TcpIp_SetSocketUdpDynIdxOfTxReqElemListDyn(txReqElemListIdx, (TcpIp_SizeOfSocketDynType)socketUdpIdx);
          TcpIp_SetTxReqElemListIdxOfSocketUdpDyn(socketUdpIdx, (TcpIp_SizeOfTxReqElemListDynType)txReqElemListIdx);
          retVal = E_OK;
          break;  /* stop the for-loop */
        }
      }

      TCPIP_VLEAVE_MC_ALWAYS_CRITICAL_SECTION();     /* unlock cross core interrupts */

      break;
    }

    case TCPIP_PARAMID_V_UDP_TXRETRYLISTSIZE:
    {
      /* #30 Handle Parameter TCPIP_PARAMID_V_UDP_TXRETRYLISTSIZE (Retry on ARP/NDP cache miss feature). */
      /* set the maximum number of Eth tx buffers used for buffering messages in case the remote address is not yet resolved */
      uint8 RetryListSizeMax = *ParameterValuePtr;
      if (RetryListSizeMax <= TcpIp_GetSizeOfUdpTxRetryQueueElements())
      {
        TcpIp_SetTxRetrQueueMaxNumOfSocketUdpDyn(socketUdpIdx, RetryListSizeMax);
        retVal = E_OK;
      }
      break;
    }

    case TCPIP_PARAMID_UDP_CHECKSUM:
    {
      /* #40 Handle the Parameter TCPIP_PARAMID_UDP_CHECKSUM */
#if (TCPIP_SUPPORT_IPV6 == STD_ON) && (TCPIP_SUPPORT_IPV4 == STD_OFF)                                                   /* COV_TCPIP_IPV6_ONLY */
      /* IPv6 only variants */
      /* This functionality is only available for IPv4 variants. */
      retVal = E_NOT_OK;
#else
# if (TCPIP_SUPPORT_IPV6 == STD_ON)                                                                                     /* COV_TCPIP_IPV6_ONLY */
      /* Dual Stack - IpV6 and IpV4 enabled */
      /* Check if Socket is IpV4 or IpV6 socket */
      if (TcpIp_GetAddrLocSockOfSocketDyn(SocketIdx)->sa_family == TCPIP_AF_INET)                                       /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
# endif
      {
        /* Ensured that only enabled for IpV4 sockets */
        boolean enabled = (boolean)(ParameterValuePtr[0] == 1u);                                                        /* PRQA S 4304 */ /* MD_MSR_AutosarBoolean */
        TcpIp_SetUdpChecksumOfSocketUdpDyn(socketUdpIdx, enabled);
        retVal = E_OK;
      }
# if (TCPIP_SUPPORT_IPV6 == STD_ON)                                                                                     /* COV_TCPIP_IPV6_ONLY */
      else
      {
        retVal = E_NOT_OK;
      }
# endif
#endif
      break;
    }

    default:
    {
      /* error, do nothing */
      TCPIP_DUMMY_STATEMENT_CONST(ParameterValuePtr);                                                                   /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
      break;
    }
    }
  }
  return retVal;
}/* TcpIp_Udp_ChangeParameter() */

/**********************************************************************************************************************
 *  TcpIp_Tcp_InitSock
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_Udp_InitSock(
  TcpIp_SocketUdpDynIterType SocketUdpIdx)
{
  /* #10 Init the socket */
  TcpIp_SetUdpChecksumOfSocketUdpDyn(SocketUdpIdx, TRUE);
} /* TcpIp_Udp_InitSock */

/**********************************************************************************************************************
 *  TcpIp_Udp_VTransmit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Udp_VTransmit(
  TCPIP_P2V(TcpIp_IpTxRequestDescriptorType) IpTxReqDescPtr,
  TCPIP_P2V(uint8)                           IpPayloadBufPtr,
  uint16                                     UdpPayloadLen,
  TCPIP_P2C(TcpIp_SockAddrBaseType)          DestSockAddrPtr,
  uint8                                      TxReqIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16                            ipTransmitLength = UdpPayloadLen + TCPIP_UDP_HDR_LEN_BYTE;
  Std_ReturnType                    retVal = E_NOT_OK;
  TcpIp_SocketUdpDynIterType        socketUdpIdx;
  uint8                             ipTransmitFlags = 0u;
  TcpIp_SocketDynIterType socketIdx = TCPIP_SOCKET_IDX_TO_UDP_IDX(IpTxReqDescPtr->SockIdx); /* Typedef because socket must be UDP, what is verified in previous functions. */
  TCPIP_P2C(TcpIp_SockAddrBaseType) locSockAddrPtr = TcpIp_GetAddrLocSockOfSocketDyn(socketIdx);

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_ASSERT(IpTxReqDescPtr  != NULL_PTR);
  TCPIP_ASSERT(IpPayloadBufPtr != NULL_PTR);
  TCPIP_ASSERT(DestSockAddrPtr != NULL_PTR);
  TCPIP_ASSERT(TCPIP_SOCKET_IDX_IS_UDP(socketIdx));

  socketUdpIdx = TCPIP_SOCKET_IDX_TO_UDP_IDX(socketIdx);
  /*@ assert socketUdpIdx < TcpIp_GetSizeOfSocketUdpDyn(); */                                                           /* VCA_TCPIP_UDP_IDX_FROM_CHECKED_SOCKET_IDX */

  /* #10 Write UDP header. */
  /*@ assert IpPayloadBufPtr != NULL_PTR; */                                                                            /* VCA_TCPIP_WRITE_UDP_HEADER */
  TCPIP_PUT_UINT16_RAW(IpPayloadBufPtr, TCPIP_UDP_HDR_OFS_SRC_PORT, locSockAddrPtr->DomainAndPort.port);
  TCPIP_PUT_UINT16_RAW(IpPayloadBufPtr, TCPIP_UDP_HDR_OFS_DST_PORT, DestSockAddrPtr->DomainAndPort.port);
  TCPIP_PUT_UINT16(IpPayloadBufPtr,     TCPIP_UDP_HDR_OFS_LENGTH,   ipTransmitLength);
  TCPIP_PUT_UINT16(IpPayloadBufPtr,     TCPIP_UDP_HDR_OFS_CHECKSUM, TCPIP_UDP_EMPTY_CHKSUM);

  /* If checksum shall be calculated partial, add the UDP header */
  if (IpTxReqDescPtr->ChecksumHwCalced == TCPIP_IP_PROTOCOL_CHECKSUM_CHECK_COPY)
  {
    IpTxReqDescPtr->TmpChecksum = IpBase_TcpIpChecksumAdd(&IpPayloadBufPtr[0], TCPIP_UDP_HDR_LENGTH,
                                                           IpTxReqDescPtr->TmpChecksum, FALSE);
  }

  if (TcpIp_GetTxReqElemListIdxOfSocketUdpDyn(socketUdpIdx) != TCPIP_NO_TXREQELEMLISTIDXOFSOCKETUDPDYN)
  {
    TCPIP_ASSERT(TcpIp_GetTxReqElemListIdxOfSocketUdpDyn(socketUdpIdx) < TcpIp_GetSizeOfTxReqElemList());
    ipTransmitFlags |= TCPIP_V_IP_TRANSMIT_FLAG_TX_CONFIRMATION;
  }

  ipTransmitFlags |= TCPIP_V_IP_TRANSMIT_FLAG_RETRY_ON_PHYS_ADDR_MISS;

  {
    TcpIp_ReturnType transmitRetVal = TCPIP_E_NOT_OK;

    /* #20 Check if there are other elements already stored in the retry queue. */
    if (TcpIp_Udp_VMatchingElementInRetryQueue(socketUdpIdx, DestSockAddrPtr) == TRUE)
    {
      /* #30 if so, trigger the saving of this element at the end of the queue to maintain the correct order. */
      transmitRetVal = TCPIP_E_PHYS_ADDR_MISS;
    }
    else
    {
      /* #40 otherwise, trigger transmission of UDP datagram via IP layer. */
      TCPIP_ASSERT(DestSockAddrPtr->sa_family == IpTxReqDescPtr->AddressFamily);

      transmitRetVal = TcpIp_VIpTransmit(IpTxReqDescPtr, ipTransmitLength, TCPIP_PROTOCOL_UDP, TxReqIdx, ipTransmitFlags);
    }


    if (transmitRetVal == TCPIP_OK)
    {
      retVal = E_OK;
    }
    else if (transmitRetVal == TCPIP_E_PHYS_ADDR_MISS)
    {
      /* #50 Queue transmission of packet if IP layer could not send the packet due to physical address cache miss, if configured.
       *     Otherwise: Abort transmission. */
       /* add request to the retry list if possible */
      retVal = TcpIp_Udp_VStoreRequestInRetryQueue(socketUdpIdx, IpTxReqDescPtr, UdpPayloadLen, DestSockAddrPtr, TxReqIdx);
    }
    else
    {
      /* Ethernet TX buffer was already released in TcpIp_VIpTransmit(). */
      retVal = E_NOT_OK;
    }
  }

  return retVal;
}  /* TcpIp_Udp_VTransmit */

/**********************************************************************************************************************
 *  TcpIp_Udp_StoreChecksumInHeader()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_Udp_StoreChecksumInHeader(
    uint16           ChecksumNbo,
    TCPIP_P2V(uint8) UdpHdrPtr)
{
  uint16           localChecksumNbo = ChecksumNbo;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Change checksum to 0xFFFF if it is zero (according to [IETF RFC1122 4.1.3.4  UDP Checksums]). */
  if (ChecksumNbo == 0u)
  {
    localChecksumNbo = 0xFFFF;
  }

  /* #20 Store checksum at correct offset inside to UDP header. */
  TCPIP_PUT_UINT16_RAW(UdpHdrPtr, TCPIP_UDP_HDR_OFS_CHECKSUM, localChecksumNbo);
} /* TcpIp_Udp_StoreChecksumInHeader() */

/**********************************************************************************************************************
 *  TcpIp_Udp_SendRetryQueueIfPossible()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(void, TCPIP_CODE) TcpIp_Udp_SendRetryQueueIfPossible(
    TcpIp_SocketUdpDynIterType        SocketUdpIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_DListIdxType                    udpTxRetryQueueElementChainIdx = 0u;
  TcpIp_UdpTxRetryQueueElementsIterType txRetryQElemCount   = 0u;
  TcpIp_UdpTxRetryQueueElementsIterType txRetryQElemIterIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */

  TCPIP_VENTER_CRITICAL_SECTION();

  udpTxRetryQueueElementChainIdx = TcpIp_GetTxRetrQueueOfSocketUdpDyn(SocketUdpIdx).FirstIdx;
  txRetryQElemCount = TcpIp_GetTxRetrQueueOfSocketUdpDyn(SocketUdpIdx).ElementCount;

  TCPIP_ASSERT(   ((txRetryQElemCount == 0u) && (udpTxRetryQueueElementChainIdx == TCPIP_DLIST_END_IDX))
               || ((txRetryQElemCount  > 0u) && (udpTxRetryQueueElementChainIdx != TCPIP_DLIST_END_IDX)));

  /* #10 Iterate over all elements in the TX retry queue of the UDP socket. */
  for (txRetryQElemIterIdx = 0; txRetryQElemIterIdx < txRetryQElemCount; txRetryQElemIterIdx++)
  {
    TcpIp_DListIdxType txRetryQElemNextIdx;
    TCPIP_P2C(TcpIp_Udp_RetryQueueElementType) retryQueueElemPtr;
    uint8 ipTransmitFlags = TCPIP_V_IP_TRANSMIT_FLAG_RETRY_ON_PHYS_ADDR_MISS;

    TCPIP_ASSERT(udpTxRetryQueueElementChainIdx < TcpIp_GetSizeOfUdpTxRetryQueueElements());

    retryQueueElemPtr   = TcpIp_GetAddrUdpTxRetryQueueElements(udpTxRetryQueueElementChainIdx);
    txRetryQElemNextIdx = TcpIp_GetUdpTxRetryQueueElementChain(udpTxRetryQueueElementChainIdx).NextIdx;

    /* #20 Request a TX confirmation for the UDP datagram, if a TX request list is attached to the socket. */
    if (TcpIp_GetTxReqElemListIdxOfSocketUdpDyn(SocketUdpIdx) < TcpIp_GetSizeOfTxReqElemList())
    {
      ipTransmitFlags |= TCPIP_V_IP_TRANSMIT_FLAG_TX_CONFIRMATION;
    }
    else
    {
      TCPIP_ASSERT(TcpIp_GetTxReqElemListIdxOfSocketUdpDyn(SocketUdpIdx) == TCPIP_NO_TXREQELEMLISTIDXOFSOCKETUDPDYN);
    }

    TCPIP_ASSERT(retryQueueElemPtr->Destination.sa_family == retryQueueElemPtr->IpTxRequestDesc.AddressFamily);

    /* #30 Call transmit function of IP layer and remove the element from the retry queue if the transmit was accepted. */
    if (TcpIp_VIpTransmit(&retryQueueElemPtr->IpTxRequestDesc,
          retryQueueElemPtr->UdpPayloadLen + TCPIP_UDP_HDR_LEN_BYTE, TCPIP_PROTOCOL_UDP,
          retryQueueElemPtr->UdpTxReqTabIdx, ipTransmitFlags) != TCPIP_E_PHYS_ADDR_MISS)
    {
      TcpIp_DListRemoveElement(TcpIp_GetAddrTxRetrQueueOfSocketUdpDyn(SocketUdpIdx), udpTxRetryQueueElementChainIdx);
    }

    udpTxRetryQueueElementChainIdx = txRetryQElemNextIdx;
  }

  TCPIP_VLEAVE_CRITICAL_SECTION();
  TCPIP_ASSERT(udpTxRetryQueueElementChainIdx == TCPIP_DLIST_END_IDX);

} /* TcpIp_Udp_SendRetryQueueIfPossible */

/**********************************************************************************************************************
 *  TcpIp_Udp_CancelRetriesForDestination()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(void, TCPIP_CODE) TcpIp_Udp_CancelRetriesForDestination(
  uint8                             CtrlIdx,
  TCPIP_P2C(TcpIp_SockAddrBaseType) RemoteAddrPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TCPIP_P2V(TcpIp_DListType) txRetryQPtr = NULL_PTR;
  TcpIp_DListIdxType udpTxRetryQueueElementsIdx = TcpIp_GetSizeOfUdpTxRetryQueueElements();
  TcpIp_SocketDynIterType socketUdpIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all UDP sockets. */
  for (socketUdpIdx = 0; socketUdpIdx < TcpIp_GetSizeOfSocketUdpDyn(); socketUdpIdx++)
  {
    TCPIP_VENTER_CRITICAL_SECTION();

    txRetryQPtr = TcpIp_GetAddrTxRetrQueueOfSocketUdpDyn(socketUdpIdx);
    udpTxRetryQueueElementsIdx = txRetryQPtr->FirstIdx;

    /* #20 Iterate over TX retry queue elements of the socket. */
    while (udpTxRetryQueueElementsIdx < TcpIp_GetSizeOfUdpTxRetryQueueElements())
    {
      TcpIp_DListIdxType txRetryQElemNextIdx = TCPIP_DLIST_GET_NEXT(udpTxRetryQueueElementsIdx, *txRetryQPtr);
      TCPIP_P2C(TcpIp_Udp_RetryQueueElementType) retryQueueElemPtr = TcpIp_GetAddrUdpTxRetryQueueElements(udpTxRetryQueueElementsIdx);

      TCPIP_ASSERT(txRetryQPtr->ElementCount > 0u);

      /* #30 Check if the retry queue element uses the given CtrlIdx and remote IP address. */
      if (retryQueueElemPtr->IpTxRequestDesc.CtrlIdx == CtrlIdx)
      {
        if (TcpIp_VSockIpAddrIsEqual(&retryQueueElemPtr->Destination, RemoteAddrPtr) == TRUE)
        {
          TCPIP_ASSERT(retryQueueElemPtr->IpTxRequestDesc.AddressFamily == RemoteAddrPtr->sa_family);

          /* #40 Cancel transmit at IP layer and remove element from the retry queue. */
          TcpIp_VIpTransmitCancel(&retryQueueElemPtr->IpTxRequestDesc, 0);
          TcpIp_DListRemoveElement(txRetryQPtr, udpTxRetryQueueElementsIdx);
        }
      }

      udpTxRetryQueueElementsIdx = txRetryQElemNextIdx;
    }
    TCPIP_VLEAVE_CRITICAL_SECTION();
  }
} /* TcpIp_Udp_CancelRetriesForDestination() */

/**********************************************************************************************************************
 *  TcpIp_Udp_VValidateChecksum()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL_INLINE FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Udp_VValidateChecksum(
    uint16                            ReceivedChecksum,
    TCPIP_P2C(TcpIp_SockAddrBaseType) RxSockLocAddrPtr,
    TCPIP_P2C(TcpIp_SockAddrBaseType) RxSockRemAddrPtr,
    TCPIP_P2C(uint8)                  IpPayloadPtr,
    uint16                            IpPayloadLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Verify that checksum of received packet is zero, if packet has a checksum. */
  if (ReceivedChecksum != 0u)
  {
    if (TcpIp_VCalcPseudoHdrAndChecksum(RxSockRemAddrPtr, RxSockLocAddrPtr, IpPayloadPtr, IpPayloadLen, TCPIP_SOCK_PROT_UDP) == 0u)
    {
      /* checksum is valid -> OK */
      retVal = E_OK;
    }
  }
  else
  {
    /* #20 Otherwise accept packet only if it is not an IPv6 packet. (Checksum is mandatory in case of IPv6). */
#if (TCPIP_SUPPORT_IPV6 == STD_ON)                                                                                      /* COV_MSR_UNSUPPORTED */
    if (RxSockRemAddrPtr->sa_family != IPBASE_AF_INET6)
#endif
    {
      /* for IPv4 the checksum is optional. */
      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Udp_VStoreRequestInRetryQueue()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL_INLINE FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Udp_VStoreRequestInRetryQueue(
  TcpIp_SocketUdpDynIterType                 SocketUdpIdx,
  TCPIP_P2C(TcpIp_IpTxRequestDescriptorType) IpTxReqDescPtr,
  uint16                                     UdpPayloadLen,
  TCPIP_P2C(TcpIp_SockAddrBaseType)          DestSockAddrPtr,
  uint8                                      TxReqIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  TcpIp_SizeOfUdpTxRetryQueueElementsType txRetryQueueMaxNumForSocket = TcpIp_GetTxRetrQueueMaxNumOfSocketUdpDyn(SocketUdpIdx);

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_ASSERT(IpTxReqDescPtr->AddressFamily == DestSockAddrPtr->sa_family);

  TCPIP_VENTER_CRITICAL_SECTION();

  /* #10 Check if retry queue of the socket has not reached the configured limit. */
  if (TcpIp_GetTxRetrQueueOfSocketUdpDyn(SocketUdpIdx).ElementCount < txRetryQueueMaxNumForSocket)
  {
    TcpIp_DListIdxType udpTxRetryQueueElementsIdx = TCPIP_DLIST_END_IDX;

    /* #20 Insert a new element into the retry queue or abort transmit of UDP datagram if all retry queue elements are in use. */
    if (TcpIp_DListAddElement(TcpIp_GetAddrTxRetrQueueOfSocketUdpDyn(SocketUdpIdx),
          TcpIp_GetTxRetrQueueOfSocketUdpDyn(SocketUdpIdx).LastIdx, &udpTxRetryQueueElementsIdx) == E_OK)
    {
      /* a new element could be added */
      /*@ assert udpTxRetryQueueElementsIdx < TcpIp_GetSizeOfUdpTxRetryQueueElements(); */                              /* VCA_TCPIP_CHECKED_RETURN_DLIST */
      TCPIP_P2V(TcpIp_Udp_RetryQueueElementType) retryQueueElePtr = TcpIp_GetAddrUdpTxRetryQueueElements(udpTxRetryQueueElementsIdx);

      TCPIP_ASSERT(udpTxRetryQueueElementsIdx < TcpIp_GetSizeOfUdpTxRetryQueueElements());

      /* #30 Initialize content of the retry queue element. */
      (void)IpBase_CopySockAddr(&retryQueueElePtr->Destination.SockAddr, &DestSockAddrPtr->SockAddr);                   /* VCA_TCPIP_IPBASE_COPYSOCKADDR */

      retryQueueElePtr->UdpPayloadLen   =  UdpPayloadLen;
      retryQueueElePtr->UdpTxReqTabIdx  =  TxReqIdx;
      retryQueueElePtr->IpTxRequestDesc = *IpTxReqDescPtr;

      /* accept this first send attempt */
      retVal = E_OK;
    }
    else
    {
      TCPIP_ASSERT(udpTxRetryQueueElementsIdx == TCPIP_DLIST_END_IDX);
    }
  }
  TCPIP_VLEAVE_CRITICAL_SECTION();

  if (retVal != E_OK)
  {
    /* Configured limit of retry queue entries for this socket has been reached or retry queue is already full. */
    TcpIp_VIpTransmitCancel(IpTxReqDescPtr, TxReqIdx);
  }

  return retVal;
} /* TcpIp_Udp_VStoreRequestInRetryQueue() */


/**********************************************************************************************************************
 *  TcpIp_Udp_VMatchingElementInRetryQueue()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL_INLINE FUNC(boolean, TCPIP_CODE) TcpIp_Udp_VMatchingElementInRetryQueue(
  TcpIp_SocketUdpDynIterType                 SocketUdpIdx,
  TCPIP_P2C(TcpIp_SockAddrBaseType)          DestSockAddrPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_DListIdxType                    udpTxRetryQueueElementsIdx = TcpIp_GetSizeOfUdpTxRetryQueueElements();
  TcpIp_UdpTxRetryQueueElementsIterType txRetryQElemCount   = 0u;
  TcpIp_UdpTxRetryQueueElementsIterType txRetryQElemIterIdx;
  boolean                               matchFound          = FALSE;

  /* ----- Implementation ----------------------------------------------- */

  TCPIP_VENTER_CRITICAL_SECTION();

  udpTxRetryQueueElementsIdx = TcpIp_GetTxRetrQueueOfSocketUdpDyn(SocketUdpIdx).FirstIdx;
  txRetryQElemCount = TcpIp_GetTxRetrQueueOfSocketUdpDyn(SocketUdpIdx).ElementCount;

  TCPIP_ASSERT(((txRetryQElemCount == 0u) && (udpTxRetryQueueElementsIdx == TCPIP_DLIST_END_IDX))
    || ((txRetryQElemCount > 0u) && (udpTxRetryQueueElementsIdx != TCPIP_DLIST_END_IDX)));

  /* #10 Iterate over all elements in the TX retry queue of the UDP socket. */
  for (txRetryQElemIterIdx = 0; txRetryQElemIterIdx < txRetryQElemCount; txRetryQElemIterIdx++)
  {
    TcpIp_DListIdxType txRetryQElemNextIdx;
    TCPIP_P2C(TcpIp_Udp_RetryQueueElementType) retryQueueElemPtr;

    TCPIP_ASSERT(udpTxRetryQueueElementsIdx < TcpIp_GetSizeOfUdpTxRetryQueueElements());

    retryQueueElemPtr = TcpIp_GetAddrUdpTxRetryQueueElements(udpTxRetryQueueElementsIdx);
    txRetryQElemNextIdx = TcpIp_GetUdpTxRetryQueueElementChain(udpTxRetryQueueElementsIdx).NextIdx;

    /* #20 Check if remote address of retry queue element matches the supplied remote address. */
    if (IpBase_SockIpAddrIsEqual(&DestSockAddrPtr->SockAddr, &retryQueueElemPtr->Destination.SockAddr) == TRUE)
    {
      /* #30 if so, set return value to TRUE and leave the loop. */
      matchFound = TRUE;

      break;
    }

    udpTxRetryQueueElementsIdx = txRetryQElemNextIdx;
  }
  TCPIP_VLEAVE_CRITICAL_SECTION();

  return matchFound;
} /* TcpIp_Udp_VMatchingElementInRetryQueue() */

/**********************************************************************************************************************
 *  TcpIp_UdpTransmitCopyData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6060 1 */ /* MD_MSR_STPAR */
FUNC(boolean, TCPIP_CODE) TcpIp_UdpTransmitCopyData(
  TCPIP_P2V(TcpIp_IpTxRequestDescriptorType) TxRequestDescPtr,
  TCPIP_P2C(uint8)                           DataPtr,
  TCPIP_P2V(uint16)                          DataLenRemainPtr,
  TCPIP_P2V(uint8)                           UdpPayloadPtr,
  uint16                                     UdpPayloadBufferLen,
  TCPIP_P2V(uint16)                          DataPosPtr,
  TCPIP_P2V(uint16)                          DataLenLocalPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfSocketDynType    socketIdx = (TcpIp_SizeOfSocketDynType)(TxRequestDescPtr->SockIdx);
  boolean                      retValue = TRUE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Copy with indirekt algorithm. */
  if (DataPtr != NULL_PTR)
  {
    TCPIP_ASSERT(*DataPosPtr < *DataLenLocalPtr);

    /* directly copy provided data from user into provided UDP buffer */
    if (TxRequestDescPtr->ChecksumHwCalced != TCPIP_IP_PROTOCOL_CHECKSUM_CHECK_HW_OR_NOT_REQ)
    {
      TxRequestDescPtr->TmpChecksum = IpBase_TcpIpChecksumCopyAdd(UdpPayloadPtr, &DataPtr[*DataPosPtr],                 /* VCA_TCPIP_IP_BUFFER_PTR_FOR_UDP */
        UdpPayloadBufferLen, TxRequestDescPtr->TmpChecksum, FALSE);
    }
    else
    {
      IpBase_Copy(UdpPayloadPtr, &DataPtr[*DataPosPtr], UdpPayloadBufferLen);                                           /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_TCPIP_IP_BUFFER_PTR_FOR_UDP */
    }
    *DataPosPtr += UdpPayloadBufferLen;
    *DataLenRemainPtr -= UdpPayloadBufferLen;
  }
  /* #20 Otherwise: Trigger upper layer to copy TX data into buffer by calling CopyTxData. */
  else
  {
    uint16 udpTxDataLen = UdpPayloadBufferLen;

    /* call CopyTxData function of user */

    if (TcpIp_CopyTxDataFunctions(  /* udpPayloadPtr, &udpTxDataLen */                                                  /* VCA_TCPIP_IP_BUFFER_PTR_FOR_UDP */
      socketIdx, UdpPayloadPtr, &udpTxDataLen, FALSE) == BUFREQ_OK)
    {
      if (udpTxDataLen < UdpPayloadBufferLen)
      {
        /* Upper layer provided less data than requested. Adapt requested length and do not copy more data. */
        uint16 trucnLen = *DataLenRemainPtr - udpTxDataLen;
        *DataLenLocalPtr -= trucnLen;
        *DataLenRemainPtr = 0;
      }
      else
      {
        *DataLenRemainPtr -= UdpPayloadBufferLen;
      }
    }
    else
    {
      /* ERROR: CopyTxData of upper layer failed. Transmit will be aborted. */
      retValue = FALSE;
      *DataLenRemainPtr = 0;
    }

    if ((retValue == TRUE) && (TxRequestDescPtr->ChecksumHwCalced == TCPIP_IP_PROTOCOL_CHECKSUM_CHECK_COPY))
    {
      /* For indirect copied UDP data the checksum must be calculated later. */
      TxRequestDescPtr->ChecksumHwCalced = TCPIP_IP_PROTOCOL_CHECKSUM_CHECK_COMPLETE;
    }
  }
  return retValue;
} /* TcpIp_UdpTransmitCopyData */

#define TCPIP_STOP_SEC_CODE
#include "TcpIp_MemMap.h"                                                                                               /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* VCA_JUSTIFICATION_START

  \ID VCA_TCPIP_WRITE_UDP_HEADER
    \DESCRIPTION       The function assumes that it is safe to write up to TCPIP_UDP_HDR_LENGTH bytes at the memory
                       location referenced by a uint8 pointer parameter.
    \COUNTERMEASURE \N The caller ensures that the pointer is not a null pointer and references a memory segment of
                       at least TCPIP_UDP_HDR_LENGTH bytes length.

  \ID VCA_TCPIP_IPBASE_COPYSOCKADDR
    \DESCRIPTION       Function is called with valid parameters.
    \COUNTERMEASURE \N Local function makes it sure that valid parameters are passed to the function call.
                       1: Argument &retryQueueElePtr->Destination.SockAddr is valid as stated below:
                          TcpIp_GetAddrUdpTxRetryQueueElements(udpTxRetryQueueElementsIdx) is used to get the address of an
                          element in the TX retry queue array. A valid index (udpTxRetryQueueElementsIdx) is returned by
                          TcpIp_DListAddElement() if the return code of the function is E_OK.
                          The index is only used if this is the case.
                          TcpIp_DListAddElement() obtains the index from the free list only if a free element exists.
                          If no free element exists the return value is negative and the value is not used.
                       2: Argument &DestSockAddrPtr->SockAddr is a const pointer. The subroutine cannot write to
                          a const pointer.

  \ID VCA_TCPIP_IP_BUFFER_PTR_FOR_UDP
    \DESCRIPTION       The IP payload buffer txReqIpBufPtr is read from a variable and asserted to point to a buffer
                       with sufficient size.
    \COUNTERMEASURE \N The entire Ethernet buffer is requested and valid as described in VCA_TCPIP_LL_PROVIDE_TX_BUFFER.
                       The size of the requested buffer is calculated as sum of the user payload length and the fixed
                       TCPIP_UDP_HDR_LEN_BYTE. The pointer is stored in context of TcpIp_Udp_RequestTxBuffer() function.
                       If the pointer is read in function TcpIp_Udp_Transmit() it is ensured in the calling function
                       that the buffer was requested successfully via TcpIp_Udp_RequestTxBuffer().

  \ID VCA_TCPIP_WritePosOfTxReqElemListDyn
    \DESCRIPTION       ComStackLib array TxReqElem is accessed with txReqElemIdx.
                       The value of txReqElemIdx is read from TcpIp_GetWritePosOfTxReqElemListDyn(txReqElemListIdx).
                       The value txReqElemListIdx is checked to be valid. (txReqElemListIdx < TcpIp_GetSizeOfTxReqElemList())
                       The write position is updated in the following functions to a valid index in the range
                       [TcpIp_GetTxReqElemStartIdxOfTxReqElemList(txReqElemListIdx)..TcpIp_GetTxReqElemEndIdxOfTxReqElemList(txReqElemListIdx)].
                       - TcpIp_Udp_Init
                       - TcpIp_Udp_CloseSocket
                       - TcpIp_Udp_Transmit
    \COUNTERMEASURE \R A runtime check verifies that txReqElemListIdx is vaild.
                       Variable txReqElemIdx is read from TcpIp_GetWritePosOfTxReqElemListDyn(txReqElemListIdx) which is
                       always updated to valid values.

  VCA_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: Udp.c
 *********************************************************************************************************************/
