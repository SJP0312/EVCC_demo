/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Scc_SDP_Tx.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements the shared SECCDiscoveryProtocol that is used in Vehicle 2 Grid communication according
 *                to the specifications DIN SPEC 70121, ISO/IEC 15118-2 and customer specific schemas.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_SDP_TX_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
 /*lint -e546 */ /* Suppress the 'Suspicious use of &' warning because the '&' is required by MISRA per Id 1502. */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_SDP.h"
#include "Scc_Priv.h"
#include "Scc_SDP_InterfaceCfg.h"
#include "Scc_SDP_TimerCfg.h"
#include "Scc_Core_Channel.h"
#include "TcpIp.h"
#include "TcpIp_IpV6.h"
#include "Scc_Core_InterfaceCfg.h"
#include "Scc_BufferPool.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

#define SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_LEN                   1u

/**********************************************************************************************************************
 *  LOCAL / GLOBAL DATA
 *********************************************************************************************************************/
 /* 16bit variables no init */
#define SCC_START_SEC_VAR_NO_INIT_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

SCC_LOCAL VAR(uint16, SCC_VAR_NOINIT)  Scc_SDP_Tx_RetransRetriesCnt;

#define SCC_STOP_SEC_VAR_NO_INIT_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SCC_START_SEC_CONST_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* [V2G-DC-165], ISO-DIS: [V2G2-087] */
SCC_LOCAL CONST(uint16, SCC_CONST) Scc_SDP_SupportedPayloadTypesPlc[SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_LEN] = {             /* PRQA S 3218 */ /* MD_Scc_3218 */
  (uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_PLC_RES
};

/* [V2G20-2284] */
#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
SCC_LOCAL CONST(uint16, SCC_CONST) Scc_SDP_SupportedPayloadTypesWireless[SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_LEN] = {        /* PRQA S 3218 */ /* MD_Scc_3218 */
  (uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_WIRELESS_RES
};
/* [V2G20-2281] */
SCC_LOCAL CONST(Scc_SDPEvIdType, SCC_CONST) Scc_SDP_DefaultEvId = { (uint16) sizeof("ZZ00000"), "ZZ00000"};             /* PRQA S 3218 */ /* MD_Scc_3218 */
#endif /* SCC_WIRELESS_SDP */

#define SCC_STOP_SEC_CONST_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_SDP_Tx_SendUdpMessage
 *********************************************************************************************************************/
/*! \brief          Transmits UDP message.
 *  \details        -
 *  \param[in]      MsgPtr                 Pointer to the message
 *  \param[in]      LengthToBeTransmitted  Number of bytes to be Transmitted
 *  \return         E_OK                   Udp sent complete message
 *  \return         E_NOT_OK               Udp did not accepted the request
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_SDP_Tx_SendUdpMessage(P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) MsgPtr,
  uint16 LengthToBeTransmitted);

/**********************************************************************************************************************
 *  Scc_SDP_Tx_SECCDiscoveryProtocolReqPlc
 *********************************************************************************************************************/
/*! \brief          Transmit SECCDiscoveryProtocol message over Plc.
 *  \details        Create SECCDiscoveryProtocol request message and transmit message.
 *  \param[in]      MsgPtr          Pointer to the message
 *  \return         E_OK            Udp send whole message
 *  \return         E_NOT_OK        Udp did not accepted the request
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_SDP_Tx_SECCDiscoveryProtocolReqPlc(P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) MsgPtr,
  P2VAR(Scc_RxConfigStructType, AUTOMATIC, SCC_APPL_DATA) RxConfigPtr);

#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
/**********************************************************************************************************************
 *  Scc_SDP_Tx_SECCDiscoveryProtocolReqWireless
 *********************************************************************************************************************/
/*! \brief          Transmit SECCDiscoveryProtocol message wireless.
 *  \details        Create SECCDiscoveryProtocol request message and transmit.
 *  \param[in]      MsgPtr          Pointer to the message
 *  \param[in]      RxConfigPtr     Pointer to Rx Config
 *  \return         E_OK            Udp send whole message
 *  \return         E_NOT_OK        Udp did not accepted the request
 *  \config         SCC_SCHEMA_ISO_20WPT || SCC_SCHEMA_ISO_20ACDP
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_SDP_Tx_SECCDiscoveryProtocolReqWireless(P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) MsgPtr,
  P2VAR(Scc_RxConfigStructType, AUTOMATIC, SCC_APPL_DATA) RxConfigPtr);

/**********************************************************************************************************************
 *  Scc_SDP_Tx_SECCDiscoveryProtocolReqWirelessAddHeader
 *********************************************************************************************************************/
/*! \brief          Create header for wireless SECCDiscoveryProtocol request.
 *  \details        Add V2GTP header to wireless SECCDiscoveryProtocol request message.
 *  \param[in]      MsgPtr          Pointer to the message
 *  \param[in]      RxConfigPtr     Pointer to Rx Config
 *  \return         E_OK            Header was added successfully
 *  \return         E_NOT_OK        Header has not been added.
 *  \config         SCC_SCHEMA_ISO_20WPT || SCC_SCHEMA_ISO_20ACDP
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_SDP_Tx_SECCDiscoveryProtocolReqWirelessAddHeader(P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
#endif /* SCC_WIRELESS_SDP */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_SDP_Tx_Init
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_SDP_Tx_Init(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Reset the SdpRetransRetriesCnt */
  Scc_SDP_Tx_RetransRetriesCnt = Scc_SDP_TimerCfg_Get_SECCDiscoveryProtocolRetries();
}

/**********************************************************************************************************************
 *  Scc_SDP_Tx_IsRetransRetriesCntExpired
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_SDP_Tx_IsRetransRetriesCntExpired(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retransRetriesCntExpired = TRUE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if SdpRetransRetriesCnt is greater than 0 */
  if (0u < Scc_SDP_Tx_RetransRetriesCnt)
  {
    /* #20 Set retransRetriesCntExpired to FALSE */
    retransRetriesCntExpired = FALSE;
  }

  return retransRetriesCntExpired;
}

/**********************************************************************************************************************
 *  Scc_SDP_Tx_DecrementRetransRetriesCnt
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_SDP_Tx_DecrementRetransRetriesCnt(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if SdpRetransRetriesCnt is greater than 0 */
  if (Scc_SDP_Tx_RetransRetriesCnt > 0u)
  {
    /* #20 Decrement SdpRetransRetriesCnt */
    Scc_SDP_Tx_RetransRetriesCnt--;
  }
}

/**********************************************************************************************************************
 *  Scc_SDP_Tx_SECCDiscoveryProtocolReq
 *********************************************************************************************************************/
/*!
 *
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
 *
 *
 *
 */
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_SDP_Tx_SECCDiscoveryProtocolReq(
  P2VAR(Scc_RxConfigStructType, AUTOMATIC, SCC_APPL_DATA) RxConfigPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) msgPtr = NULL_PTR;
#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
  Scc_SDPPhysComLayerType physComLayer = Scc_SDPPhysComLayer_Undefined;
#endif /* SCC_WIRELESS_SDP */
  uint32 buffLen = 0;
  uint8 buffPoolId = SCC_INVALID_BUFFER_POOL_ID;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get MsgPtr and MsgPtrSize */
  if (Scc_BufferPoolRequestGetBuffer(SCC_POOL_BUFF_LARGE, &msgPtr, &buffLen, &buffPoolId) != E_OK)
  {
    /* Do nothing. Error already reported */
  }
  else
  {
    Scc_Core_Channel_Set_BufferPoolId(buffPoolId);
#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
    /* #20 Get physical layer type from application */
    Scc_Core_InterfaceCfg_Get_PhysicalLayerTypeRx(&physComLayer);

    /* #30 Propagate physical layer type to StateM */
    Scc_SDP_InterfaceCfg_Set_SDPPhysicalLayerTypeTx(physComLayer);

    /* #40 Check if physical layer type is plc */
    if (physComLayer == Scc_SDPPhysComLayer_PLC)
    {
#endif /* SCC_WIRELESS_SDP */
      /* Since Res len > Req len and the same buffer is used the res len is used */
      /* #50 Check if length is enough to write SDP */
      if (buffLen < SCC_SDP_RES_PLC_LEN)
      {
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_BuffPool_SdpPlcBufferTooSmall);
      }
      else
      {
        /* #60 Call API to transmit SECCDiscoveryProtocolReq over Plc */
        retVal = Scc_SDP_Tx_SECCDiscoveryProtocolReqPlc(msgPtr, RxConfigPtr);
      }
#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
    }
    /* #70 Otherwise check if physical layer type is wireless */
    else if (physComLayer == Scc_SDPPhysComLayer_Wireless)
    {
      /* #80 Check if length is enough to write SDP */
      if (buffLen < SCC_SDP_REQ_WIRELESS_LEN)
      {
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_BuffPool_SdpWirelessBufferTooSmall);
      }
      else
      {
        /* #90 Call API to transmit SECCDiscoveryProtocolReq wireless */
        retVal = Scc_SDP_Tx_SECCDiscoveryProtocolReqWireless(msgPtr, RxConfigPtr);
      }
    }
    /* #100 Otherwise */
    else
    {
      /* Nothing to do, retVal = E_NOT_OK already */
    }
#endif /* SCC_WIRELESS_SDP */
  }

  /* #110 Check if retVal is NotOk and buffPoolId is valid */
  if ((retVal == E_NOT_OK) && (buffPoolId != SCC_INVALID_BUFFER_POOL_ID))
  {
    /* #120 Release buffer */
    Scc_BufferPoolRelease(buffPoolId);
    Scc_Core_Channel_Set_BufferPoolId(SCC_INVALID_BUFFER_POOL_ID);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_SDP_Tx_SendUdpMessage
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_SDP_Tx_SendUdpMessage(P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) MsgPtr,
  uint16 LengthToBeTransmitted)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  /* create the socket address struct */
  Scc_SockAddrIn6Type IpAddrPortDst;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 create and initialize the socket address struct */
  IpAddrPortDst.domain = SCC_IPvX_IPV6;
  IpAddrPortDst.port = IPBASE_HTON16(SCC_SDP_SERVER_PORT);
  /* copy the IP address */ /* PRQA S 0310,3305,0315 2 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy */
  IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&IpAddrPortDst.addr[0],
    (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&IpV6_AddrAllNodesLL, sizeof(IpV6_AddrAllNodesLL));

  /* #20 transmit SDP request and check if it failed */
  if ((Std_ReturnType)E_OK != TcpIp_UdpTransmit(Scc_SDPSocket, (P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA))&MsgPtr[0],      /* PRQA S 0310 2 */ /* MD_Scc_0310_0314_0316_3305 */
    (P2VAR(Scc_SockAddrType, AUTOMATIC, SCC_APPL_DATA))&IpAddrPortDst, LengthToBeTransmitted))
  {
    Scc_Core_Channel_Set_TxDataSent(0);
    Scc_ReportError(Scc_StackError_TransportLayer, SccDetailedError_General_TransportLayerSdpUdpTransmitFailed);
  }
  else
  {
    Scc_Core_Channel_Set_TxDataSent(LengthToBeTransmitted);
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_SDP_Tx_SECCDiscoveryProtocolReqPlc
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_SDP_Tx_SECCDiscoveryProtocolReqPlc(P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) MsgPtr,
  P2VAR(Scc_RxConfigStructType, AUTOMATIC, SCC_APPL_DATA) RxConfigPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint16 tempSdpRetranRetriesCnt;

  /* ----- Implementation ----------------------------------------------- */
  /* use the exi struct buf to create the v2gtp header */
  /* #10 set the version info */
  MsgPtr[Scc_V2GTPOffsets_Version] = (uint8)SCC_V2G_PROT_VER;
  MsgPtr[Scc_V2GTPOffsets_InverseVersion] = (uint8)((~SCC_V2G_PROT_VER) & 0xFFu);
  /* #20 set the payload type */
  MsgPtr[Scc_V2GTPOffsets_PayloadType] =
    (uint8)(((uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_PLC_REQ & 0xFF00u) >> 8u);
  MsgPtr[Scc_V2GTPOffsets_PayloadType + 1u] =
    (uint8)((uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_PLC_REQ & 0x00FFu);
  /* #30 set the payload length */
  MsgPtr[Scc_V2GTPOffsets_PayloadLength] =
    (uint8)(((uint32)(SCC_SDP_REQ_PLC_LEN - SCC_V2GTP_HDR_LEN) & 0xFF000000u) >> (uint32)24u); /*lint !e572 Excessive shift value */
  MsgPtr[Scc_V2GTPOffsets_PayloadLength + 1u] =
    (uint8)(((uint32)(SCC_SDP_REQ_PLC_LEN - SCC_V2GTP_HDR_LEN) & 0x00FF0000u) >> (uint32)16u); /*lint !e572 Excessive shift value */
  MsgPtr[Scc_V2GTPOffsets_PayloadLength + 2u] =
    (uint8)(((uint32)(SCC_SDP_REQ_PLC_LEN - SCC_V2GTP_HDR_LEN) & 0x0000FF00u) >> (uint32)8u); /*lint !e572 Excessive shift value */
  MsgPtr[Scc_V2GTPOffsets_PayloadLength + 3u] =
    (uint8)((uint32)(SCC_SDP_REQ_PLC_LEN - SCC_V2GTP_HDR_LEN) & 0x000000FFu);

  /* #40 set the security (TLS or TCP) */
  Scc_SDP_InterfaceCfg_Get_SDPSecurityRx(&Scc_SelectedConnectionType);

  /* Scc_SDP_Tx_RetransRetriesCnt is a decrementing counter. Hence < is used */
  /* #50 Check if number of SDP retries with Tls exceeds the threshold */
  tempSdpRetranRetriesCnt = Scc_SDP_TimerCfg_Get_SECCDiscoveryProtocolRetries() - Scc_SDP_TimerCfg_Get_SECCDiscoveryProtocolTlsRetries();


  if ((Scc_SDP_Tx_RetransRetriesCnt <= tempSdpRetranRetriesCnt) && (Scc_SelectedConnectionType == Scc_SDPSecurity_Tls))
  {
    Scc_SelectedConnectionType = Scc_SDPSecurity_None;
    /* #60 Inform upper layer about the change in security type */
    Scc_SDP_InterfaceCfg_Set_SDPSecurityTx(Scc_SelectedConnectionType);                                                 /* PRQA S 3109, 4342 */ /* MD_Scc_Empty_Statement, MD_Scc_Exi_Generic */
  }

  MsgPtr[SCC_V2GTP_HDR_LEN + Scc_SDPReqOffsets_Security] = (uint8)Scc_SelectedConnectionType;
  MsgPtr[SCC_V2GTP_HDR_LEN + Scc_SDPReqOffsets_Protocol] = SCC_SDP_TP_TCP;

  retVal = Scc_SDP_Tx_SendUdpMessage(MsgPtr, SCC_SDP_REQ_PLC_LEN);

  RxConfigPtr->DecodeFct = &Scc_SDP_Rx_SECCDiscoveryProtocolResPlc;
  RxConfigPtr->SupportedPayloadTypeList = Scc_SDP_SupportedPayloadTypesPlc;

  RxConfigPtr->DecodePrepareFct = NULL_PTR;
  RxConfigPtr->SupportedPayloadTypeListLen = SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_LEN;
  RxConfigPtr->PropagteMessage = FALSE;

  return retVal;
}


/**********************************************************************************************************************
 *  Scc_SDP_Tx_SECCDiscoveryProtocolReqWireless
 *********************************************************************************************************************/
/*!
 *
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
 *
 *
 *
 *
 *
 *
 *
 */
#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_SDP_Tx_SECCDiscoveryProtocolReqWireless(P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) MsgPtr,
  P2VAR(Scc_RxConfigStructType, AUTOMATIC, SCC_APPL_DATA) RxConfigPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint16 tempSdpRetranRetriesCnt;

  Scc_SDPP2pPpdType p2pPpd = Scc_SDPP2pPpdT_Undefined;
  Scc_SDPCouplingType couplingType = Scc_SDPCouplingType_Na;
  Scc_SDPEvIdType evId = { 0 };
  Scc_SDPEvseIdType evseId = { 0 };

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Add the V2GTP Header to the Message */
  Scc_SDP_Tx_SECCDiscoveryProtocolReqWirelessAddHeader(MsgPtr);

  /* #20 Get SDP parameters from application */
  Scc_SDP_InterfaceCfg_Get_SDPSecurityRx(&Scc_SelectedConnectionType);

  Scc_SDP_InterfaceCfg_Get_SDPP2pPpd(&p2pPpd);

  Scc_SDP_InterfaceCfg_Get_SDPCouplingTypeRx(&couplingType);

  Scc_SDP_InterfaceCfg_Get_SDPEvId(&evId);

  if ((uint32)p2pPpd < (uint32)Scc_SDPP2pPpdT_Undefined)
  {
  /* [V2G20-2281] If an EVCC cannot provide data for the EVID, the EVID shall be set to "ZZ00000" */
  /* #30 Check if application callback did return an empty EVID */
    if (evId.Length == (uint16)0x00)
    {
      /* #40 Set default value */
      evId = Scc_SDP_DefaultEvId;
    }
    /* #50 Check if application callback did return an invalid EVID length */
    else if (evId.Length > SCC_SDPTYPES_EVID_MAX_SIZE)
    {
      /* #60 Set length to max length */
      evId.Length = (uint16)SCC_SDPTYPES_EVID_MAX_SIZE;
    }
    else
    {
      /* #70 Take EVID from application callback */
    }

    /* [V2G20-4100] For pairing and positioning device support the SDP client shall send SECC discovery request
     * messages with the element EVID set the element PPD/P2PS to "PPD on infrastructure" according to Table 24
     * and leave the element EVSEID free. */
    /* #80 Check if pairing / positioning device is other than PPD on infrastructure */
    if (p2pPpd != Scc_SDPP2pPpdT_Ppd_On_Infrastructure)
    {
      /* #90 Get EvseId from Application */
      Scc_SDP_InterfaceCfg_Get_SDPEvseIdRx(&evseId);

      /* #100 Check if application callback did return an invalid EVSEID length */
      if (evseId.Length > SCC_SDPTYPES_EVSEID_MAX_SIZE)
      {
        /* #110 Set length to max length */
        evseId.Length = SCC_SDPTYPES_EVSEID_MAX_SIZE;
      }
    }

    /* Scc_SDP_Tx_RetransRetriesCnt is a decrementing counter. Hence < is used */
    /* #120 Check if number of SDP retries with Tls exceeds the threshold */
    tempSdpRetranRetriesCnt = Scc_SDP_TimerCfg_Get_SECCDiscoveryProtocolRetries() - Scc_SDP_TimerCfg_Get_SECCDiscoveryProtocolTlsRetries();

    if ((Scc_SDP_Tx_RetransRetriesCnt <= tempSdpRetranRetriesCnt) && (Scc_SelectedConnectionType == Scc_SDPSecurity_Tls))
    {
      Scc_SelectedConnectionType = Scc_SDPSecurity_None;
      /* #130 Inform upper layer about the change in security type */
      Scc_SDP_InterfaceCfg_Set_SDPSecurityTx(Scc_SelectedConnectionType);                                               /* PRQA S 3109, 4342 */ /* MD_Scc_Empty_Statement, MD_Scc_Exi_Generic */
    }

    /* #140 Write SECC request parameters into message */

    MsgPtr[SCC_V2GTP_HDR_LEN + Scc_SDPReqOffsets_Security] = (uint8)Scc_SelectedConnectionType;
    MsgPtr[SCC_V2GTP_HDR_LEN + Scc_SDPReqOffsets_Protocol] = SCC_SDP_TP_TCP;
    MsgPtr[SCC_V2GTP_HDR_LEN + SCC_SDPREQOFFSETS_P2PPPD] = (uint8)p2pPpd;
    /* ISO 15118-20:2022, Table 23 - Byte 4 is reserved for future applications  */
    MsgPtr[SCC_V2GTP_HDR_LEN + SCC_SDPREQOFFSETS_P2PPPD + 1u] = (uint8)0x00u;
    MsgPtr[SCC_V2GTP_HDR_LEN + SCC_SDPREQOFFSETS_COUPLINGTYPE] = (uint8)couplingType;

    IpBase_Copy( /* PRQA S 0310,3305,0315 2 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy */
      (P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) & MsgPtr[SCC_V2GTP_HDR_LEN + SCC_SDPREQOFFSETS_EVID],
      (P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) & evId.Buffer[0],
      evId.Length);

    IpBase_Fill( /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      (P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &MsgPtr[SCC_V2GTP_HDR_LEN + SCC_SDPREQOFFSETS_EVID + evId.Length],
      0x00,
      (uint16)(SCC_SDPREQOFFSETS_EVSEID - SCC_SDPREQOFFSETS_EVID - evId.Length));

    IpBase_Copy( /* PRQA S 0310,3305,0315 2 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy */
      (P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &MsgPtr[SCC_V2GTP_HDR_LEN + SCC_SDPREQOFFSETS_EVSEID],
      (P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &evseId.Buffer[0],
      evseId.Length);

    IpBase_Fill( /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      (P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &MsgPtr[SCC_V2GTP_HDR_LEN + SCC_SDPREQOFFSETS_EVSEID + evseId.Length],
      0x00,
      (uint16)(SCC_SDP_REQ_WIRELESS_LEN - SCC_SDPREQOFFSETS_EVSEID - evseId.Length));

    /* #150 Transmit SECC request message */

    retVal = Scc_SDP_Tx_SendUdpMessage(MsgPtr, SCC_SDP_REQ_WIRELESS_LEN);

    /* #160 Prepare Rx config to process a wireless SDP response */

    RxConfigPtr->DecodeFct = &Scc_SDP_Rx_SECCDiscoveryProtocolResWireless;
    RxConfigPtr->SupportedPayloadTypeList = Scc_SDP_SupportedPayloadTypesWireless;

    RxConfigPtr->DecodePrepareFct = NULL_PTR;
    RxConfigPtr->SupportedPayloadTypeListLen = SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_LEN;
    RxConfigPtr->PropagteMessage = FALSE;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_SDP_Tx_SECCDiscoveryProtocolReqWirelessAddHeader
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_SDP_Tx_SECCDiscoveryProtocolReqWirelessAddHeader(P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* #10 Set header structure according to [V2G20-082] */
  /* #20 Set the protocol version / inverse protocol version according to [V2G20-083] */
  MsgPtr[Scc_V2GTPOffsets_Version] = (uint8)SCC_V2G_PROT_VER;
  MsgPtr[Scc_V2GTPOffsets_InverseVersion] = (uint8)((~SCC_V2G_PROT_VER) & 0xFFu);
  /* #30 Set the payload type to SDPRequestWirelessPayloadID [V2G20-2284] */
  MsgPtr[Scc_V2GTPOffsets_PayloadType] =
    (uint8)(((uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_WIRELESS_REQ & 0xFF00u) >> 8u);
  MsgPtr[Scc_V2GTPOffsets_PayloadType + 1u] =
    (uint8)((uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_WIRELESS_REQ & 0x00FFu);
  /* #40 Set the payload length */
  MsgPtr[Scc_V2GTPOffsets_PayloadLength] =
    (uint8)(((uint32)(SCC_SDP_REQ_WIRELESS_LEN - SCC_V2GTP_HDR_LEN) & 0xFF000000u) >> (uint32)24u); /*lint !e572 Excessive shift value */
  MsgPtr[Scc_V2GTPOffsets_PayloadLength + 1u] =
    (uint8)(((uint32)(SCC_SDP_REQ_WIRELESS_LEN - SCC_V2GTP_HDR_LEN) & 0x00FF0000u) >> (uint32)16u); /*lint !e572 Excessive shift value */
  MsgPtr[Scc_V2GTPOffsets_PayloadLength + 2u] =
    (uint8)(((uint32)(SCC_SDP_REQ_WIRELESS_LEN - SCC_V2GTP_HDR_LEN) & 0x0000FF00u) >> (uint32)8u); /*lint !e572 Excessive shift value */
  MsgPtr[Scc_V2GTPOffsets_PayloadLength + 3u] =
    (uint8)((uint32)(SCC_SDP_REQ_WIRELESS_LEN - SCC_V2GTP_HDR_LEN) & 0x000000FFu);
}
#endif /* SCC_WIRELESS_SDP */

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*lint +e546 */ /* Enable the 'Suspicious use of &' reporting again. */

/**********************************************************************************************************************
 *  END OF FILE: Scc_SDP_Tx.c
 *********************************************************************************************************************/
