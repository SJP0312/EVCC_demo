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
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  TcpIp_TlsServer.h
 *        \brief  Transport Layer Security (TLS) 1.2 server functions implementation.
 *
 *      \details  This file is part of the TcpIp TLS submodule.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp module. >> TcpIp.h
 *********************************************************************************************************************/

#if !defined (TCPIP_TLSSERVER_H)
# define TCPIP_TLSSERVER_H
# include "TcpIp_Cfg.h"

# if (TCPIP_SUPPORT_ASRTLS == STD_ON)                                                                                   /* COV_MSR_UNSUPPORTED */
#  if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#    include "TcpIp_Lcfg.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#    define TCPIP_TLS_MINCIPHERLEN 2u  /* At least one cipher suite ID must be received, therefore the min length is 2 bytes */

/* Minimum ClientHello length: 2 bytes version info, 32 bytes random value, 4 byte cipher suite info, 1 byte session id length, 2 bytes compression method info */
#    define TCPIP_TLS_MIN_CLIENTHELLO_MSGLEN ( TCPIP_TLS_VERSLEN + TCPIP_TLS_RANDOM_LEN + TCPIP_TLS_CIPHERSUITESLEN_LEN \
                                           + TCPIP_TLS_MINCIPHERLEN + TCPIP_TLS_SESSIONIDLEN_LEN + TCPIP_TLSSERVER_COMPMETHLEN_LEN + TCPIP_TLS_COMPMETHLEN_LEN)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * TcpIp_TlsServer_Init
 *********************************************************************************************************************/
/*!  \brief        Initialize the TLS-Server submodule.
 *  \details       -
 *  \param[in]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsServer_Init(void);

/**********************************************************************************************************************
 * TcpIp_TlsServer_ResetConnection
 *********************************************************************************************************************/
/*! \brief         Reset the TLS-Server connection.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsServer_ResetConnection(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerCtx_AsyncHandler
 *********************************************************************************************************************/
/*! \brief         Handle asynchronous context operations for TLS-Server.
 *  \details       Calculates all time consuming operation if the corresponding flags are set
 *  \param[in]     TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK (only called in the context of the TLS background task TcpIp_Tls_MainFunctionLowPrio())
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsServerCtx_AsyncHandler(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerCrypto_SetCsmKeys
 *********************************************************************************************************************/
/*! \brief         Set all relevant CSM keys for the crypto operation within the TLS-Server.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCrypto_SetCsmKeys(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServer_ProcessHandshake
 *********************************************************************************************************************/
/*! \brief         Process the TLS-Server handshake state machine.
 *  \details       Executes the TLS-Server handshake state machine, if all conditions are fulfilled.
 *  \param[in]     TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsServer_ProcessHandshake(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerTx_CheckForTransmittableProcessedHsMsg
 *********************************************************************************************************************/
/*! \brief         Checks if the processed TLS handshake messages are transmittable.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsServerTx_CheckForTransmittableProcessedHsMsg(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerTx_SendChangeCipherSpec
 *********************************************************************************************************************/
/*! \brief         Transmit the TLS-Server ChangeCipherSpec message
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsServerTx_SendChangeCipherSpec(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientHelloStoreSessionIdBufferIndex
 *********************************************************************************************************************/
/*! \brief         Store the buffer index of the received session Id in the ClientHello if it is non-empty
 *  \details       -
 *  \param[in]     TlsConIdx         TLS connection index
 *                                   \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     SessionIdLen      Length of the received session Id in the ServerHello
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloStoreSessionIdBufferIndex(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC)     SessionIdLen);

/**********************************************************************************************************************
 *  TCPIP TLS LISTENER
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsServerListener_Init
 *********************************************************************************************************************/
/*! \brief         Initialize all the configured TlsListeners and their values
 *  \details       -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsServerListener_Init(void);

/**********************************************************************************************************************
 *  TcpIp_TlsServerListener_ResetListener
 *********************************************************************************************************************/
/*! \brief         Reset the given TlsListener to its default values after a reset
 *  \details       -
 *  \param[in]     TlsListenerIdx      TLS Listener index
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsServerListener_ResetListener(
  TcpIp_TlsListenerIterType TlsListenerIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsServerListener_ForwardCloseToTlsConnection
 *********************************************************************************************************************/
/*! \brief         Finds the corresponding TLS connection and forwards the close call
 *  \details       -
 *  \param[in]     TlsListenerIdx  TLS Listener index
 *  \param[in]     Abort           TRUE: connection will immediately be terminated by sending a RST-Segment and releasing
 *                                 all related resources.
 *                                 FALSE: connection will be terminated after performing a regular connection termination
 *                                 and releasing all related resources.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsServerListener_ForwardCloseToTlsConnection(
  TcpIp_TlsListenerIterType TlsListenerIdx,
  boolean Abort);

/**********************************************************************************************************************
 *  TcpIp_TlsServerListener_GetNextFreeListenerIndex
 *********************************************************************************************************************/
/*! \brief         Search for the next free TLS Listener
 *  \details       Iterate over all configured Listener and search for the next free entry, which is stored in the Ptr
 *  \param[out]    TlsListenerPtr      Next free TLS Listener
 *  \return        E_OK                If a free TLS Listener is found
 *  \return        E_NOT_OK            If no free TLS Listener is found
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerListener_GetNextFreeListenerIndex(
  TCPIP_P2V(TcpIp_TlsListenerIterType) TlsListenerPtr);

/**********************************************************************************************************************
 *  TcpIp_TlsServerListener_GetTlsListenerUsedBySocketIdx
 *********************************************************************************************************************/
/*! \brief         Returns the corresponding TLS Listener which is used by the given socket index
 *  \details       -
 *  \param[in]     SocketIdx           Socket identifier of the related local socket resource.
 *  \param[out]    TlsListenerPtr      Corresponding TLS Listener by the given socket index
 *  \return        E_OK                If corresponding TLS Listener to the given socket is found
 *  \return        E_NOT_OK            If no corresponding TLS Listener to the given socket is found
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerListener_GetTlsListenerUsedBySocketIdx(
  TcpIp_SocketDynIterType              SocketIdx,
  TCPIP_P2V(TcpIp_TlsListenerIterType) TlsListenerPtr);

/**********************************************************************************************************************
 *  TcpIp_TlsServerListener_GetTlsConnectionIndexForConnectionAssignment
 *********************************************************************************************************************/
/*! \brief         Gets the index of the TLS connection which shall be used for connection assignment.
 *  \details       -
 *  \param[in]     SocketIdx           Socket index which shall be used
 *  \param[in]     UsedPort            Port which shall be used
 *  \return        tlsConIdx           Suitable TLS connection found:
 *                                     TLS connection index is smaller than TcpIp_GetSizeOfTlsConnection()
 *  \return        tlsConIdx           No suitable TLS connection found:
 *                                     TLS connection index equals TcpIp_GetSizeOfTlsConnection()
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(TcpIp_TlsConnectionIterType, TCPIP_CODE) TcpIp_TlsServerListener_GetTlsConnectionIndexForConnectionAssignment(
  CONST(TcpIp_SizeOfSocketDynType, AUTOMATIC) SocketIdx,
  CONST(TcpIp_PortOfTlsListenerType, AUTOMATIC) UsedPort);

/**********************************************************************************************************************
 *  TcpIp_TlsServerListener_Close
 *********************************************************************************************************************/
/*! \brief         Forwards the close call to the TLS connection.
 *  \details       This function is called when TcpIp_Close is called on a TLS Listen socket.
 *  \param[in]     SocketIdx    Socket identifier of the related local socket resource.
 *  \param[in]     Abort        TRUE: connection will immediately be terminated by sending a RST-Segment and releasing
 *                              all related resources.
 *                              FALSE: connection will be terminated after performing a regular connection termination
 *                              and releasing all related resources.
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsServerListener_Close(
  TcpIp_SocketDynIterType SocketIdx,
  boolean Abort);

/**********************************************************************************************************************
 *  TcpIp_TlsServerListener_ConfigTcpSocket
 *********************************************************************************************************************/
/*! \brief         Configure the TCP socket for TLS
 *  \details       This function is called for a TLS Listen socket.
 *  \param[in]     SocketIdx               Socket identifier of the related local socket resource.
 *  \return        E_OK                    Operation successful
 *  \return        E_NOT_OK                Operation NOT successful
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerListener_ConfigTcpSocket(
  TcpIp_SocketDynIterType      SocketIdx);

#   endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
#  endif /* (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON) */
# endif /* (TCPIP_SUPPORT_ASRTLSS == STD_ON) */
#endif /* TCPIP_TLSSERVER_H */
/**********************************************************************************************************************
 *  END OF FILE: TcpIp_TlsServer.h
 *********************************************************************************************************************/
