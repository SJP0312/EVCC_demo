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
/*!     \file  TcpIp_TlsPriv.h
 *      \brief Transport Layer Security (TLS) private functions implementation.
 *
 *   \details  This file is part of the TcpIp TLS submodule.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp module. >> TcpIp.h
 *********************************************************************************************************************/

#if !defined (TCPIP_TLS_PRIV_H)
# define TCPIP_TLS_PRIV_H

# include "TcpIp_Cfg.h"
# if (TCPIP_SUPPORT_ASRTLS == STD_ON)                                                                                   /* COV_MSR_UNSUPPORTED */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#  include "TcpIp_Lcfg.h"
#  include "TcpIp_Tls.h"
#  include "TcpIp_TlsCoreCommon.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#  define TCPIP_TLS_CONNECTION_ID_TO_IDX(TLS_CONNECTION_ID)   ((TcpIp_SizeOfTlsConnectionType)(TLS_CONNECTION_ID))
#  define TCPIP_TLS_CONNECTION_IDX_TO_ID(TLS_CONNECTION_IDX)  ((TcpIp_TlsConnectionIdType)(TLS_CONNECTION_IDX))

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)                                                                              /* COV_MSR_UNSUPPORTED */
/* The certificate ID is always the same as the certificate IDX. */
#   define TCPIP_TLS_CERT_ID_TO_IDX(TLS_CERT_ID)   ((TcpIp_SizeOfTlsKeyMCertificateType)(TLS_CERT_ID))
#   define TCPIP_TLS_CERT_IDX_TO_ID(TLS_CERT_IDX)  ((KeyM_CertElementIdType)(TLS_CERT_IDX))
#  endif

/* Check if write index is valid (>= start index) and if reqSize fits into AdHs buffer.
 * This is the case when the indices from write index till end index are enough to fit reqSize into it (excluding end index).
 * So reqSize <= endIdx - writeIdx or writeIdx + reqSize <= endIdx. */
#  define TCPIP_TLS_HS_CHECK_BUFFER_IDX(TlsConIdx, reqSize) (   (TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx)) >= TcpIp_GetTlsBufferTxAdHsStartIdxOfTlsBufferMgmt(TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx))) \
                                                             && ((TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx)) + (uint64)reqSize) <=  TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx))))

/* Same check for Al buffer, only WriteIdx is now an input parameter. */
#  define TCPIP_TLS_AL_CHECK_BUFFER_IDX(TlsConIdx, WriteIdx, reqSize) (   ( WriteIdx                    >= TcpIp_GetTlsBufferTxAlStartIdxOfTlsBufferMgmt(TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx))) \
                                                                       && ((WriteIdx + (uint64)reqSize) <=  TcpIp_GetTlsBufferTxAlEndIdxOfTlsBufferMgmt(TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx))))

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
 * TcpIp_TlsMsg_AddHsHdr
 *********************************************************************************************************************/
/*! \brief         Writes the TLS handshake type to the start of the transmittable TLS handshake message
 *  \details       -
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]      HsType                  Type of handshake message
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsMsg_AddHsHdr(
  TcpIp_TlsConnectionIterType                 TlsConIdx,
  CONST(TcpIp_TlsMsgHandshakeType, AUTOMATIC) HsType);

/**********************************************************************************************************************
 * TcpIp_TlsHelloMsg_AddProtocolVersionNr
 *********************************************************************************************************************/
/*! \brief         Writes the TLS major and TLS minor version number to the TLS handshake header
 *  \details       -
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsHelloMsg_AddProtocolVersionNr(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsHelloMsg_AddRandomStructure
 *********************************************************************************************************************/
/*! \brief         Write the TLS HelloMessage random structure to the transmittable TLS handshake message
 *  \details       Generates random value to be used for Hello handshake message
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Operation successful
 *  \return        E_NOT_OK                Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsHelloMsg_AddRandomStructure(
  TcpIp_TlsConnectionIterType              TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsHelloMsg_AddRandomStructureGetTime
 *********************************************************************************************************************/
/*! \brief         Add the TLS UNIX time stamp to the TLS HelloMessage random structure.
 *  \details       -
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsHelloMsg_AddRandomStructureGetTime(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsHelloMsg_AddRandomStructureGetRandom
 *********************************************************************************************************************/
/*! \brief         Generate and add a random value to the Tx Buffer at the write idx
 *  \details       -
 *  \param[in]     TlsConIdx                    TLS connection index
 *                                              \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     RequiredRndLen               Length of the random bytes which should be added
 *  \return        E_OK                         Operation successful
 *  \return        E_NOT_OK                     Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsHelloMsg_AddRandomStructureGetRandom(
  TcpIp_TlsConnectionIterType              TlsConIdx,
  uint32                                   RequiredRndLen);

/**********************************************************************************************************************
 * TcpIp_TlsHelloMsg_AddSessionId
 *********************************************************************************************************************/
/*! \brief         Add the SessionID to the TLS HelloMessage random structure
 *  \details       -
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                     Operation successful
 *  \return        E_NOT_OK                 Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsHelloMsg_AddSessionId(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsMsg_ExtractReceivedExtensions
 *********************************************************************************************************************/
/*! \brief         Extract all received extensions of the current message from TLS-RxBuffer into separated list
 *  \details       -
 *  \param[in]     TlsConIdx                 TLS connection index
 *                                           \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ExtensionsLen             Length of the extensions data
 *  \param[in]     MsgEndIdx                 End idx of the evaluated message
 *  \param[in,out] ReceivedExtensionListPtr  Pointer to the list of received extensions
 *  \param[in,out] ReceivedExtensionCntPtr   Pointer to the number of received extensions
 *  \return        E_OK                      Operation successful
 *  \return        E_NOT_OK                  Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsMsg_ExtractReceivedExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 ExtensionsLen,
  TcpIp_TlsBufferRxIterType MsgEndIdx,
  TCPIP_P2V(TcpIp_TlsExtensionType) ReceivedExtensionListPtr,
  TCPIP_P2V(uint8) ReceivedExtensionCntPtr);

/**********************************************************************************************************************
 * TcpIp_TlsMsg_CheckDuplicatedReceivedExtensions
 *********************************************************************************************************************/
/*! \brief         Checks the list of received extensions for duplicated entries
 *  \details       -
 *  \param[in]     ReceivedExtensionListPtr  Pointer to the list of received extensions
 *  \param[in]     ReceivedExtensionCnt      Number of received extensions
 *  \return        E_OK                      Operation successful
 *  \return        E_NOT_OK                  Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsMsg_CheckDuplicatedReceivedExtensions(
  TCPIP_P2C(TcpIp_TlsExtensionType) ReceivedExtensionListPtr,
  uint8 ReceivedExtensionCnt);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ServerMsgValidateExtensionListForSourceMessageAndTlsVersion
 *********************************************************************************************************************/
/*! \brief         Checks all received extensions if sent in the correct message and is supported in active version
 *  \details       -
 *  \param[in]     TlsConIdx                 TLS connection index
 *                                           \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ReceivedExtensionListPtr  Pointer to the list of received Server extensions
 *  \param[in]     ReceivedExtensionCnt      Number of received server extensions
 *  \param[in]     SourceMessage             Type of the message in which the extensions were sent
 *  \return        E_OK                      Operation successful
 *  \return        E_NOT_OK                  Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerMsgValidateExtensionListForSourceMessageAndTlsVersion(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(TcpIp_TlsExtensionType) ReceivedExtensionListPtr,
  uint8 ReceivedExtensionCnt,
  TcpIp_TlsMsgHandshakeType SourceMessage);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ServerMsgExtensionValidateSourceMessageAndTlsVersion
 *********************************************************************************************************************/
/*! \brief         Checks all received extensions if sent in the correct message and is supported in active version
 *  \details       -
 *  \param[in]     TlsConIdx                      TLS connection index
 *                                                \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     CurrentReceivedExtensionType   Type of extension which should be checked
 *  \param[in]     SourceMessage                  Type of the message in which the extensions were sent
 *  \return        E_OK                           Operation successful
 *  \return        E_NOT_OK                       Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerMsgExtensionValidateSourceMessageAndTlsVersion(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 CurrentReceivedExtensionType,
  TcpIp_TlsMsgHandshakeType SourceMessage);

/**********************************************************************************************************************
 * TcpIp_TlsMsg_AddLenToHsHdr
 *********************************************************************************************************************/
/*! \brief         Update the TLS handshake header with the given length information
 *  \details       -
 *  \param[in]     Length                   Length information which should be written to the TLS handshake header
 *  \param[in]     HsHdrStartTlsBufferTxIdx Start Index of TLS handshake header
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsMsg_AddLenToHsHdr(
  TcpIp_TlsBufferTxIterType   HsHdrStartTlsBufferTxIdx,
  CONST(uint32, AUTOMATIC)    Length);

/**********************************************************************************************************************
 * TcpIp_TlsHs_CheckExpectedMsgLen
 *********************************************************************************************************************/
/*! \brief         Compares the actual message length with the expected message length
 *  \details       -
 *  \param[in]     MsgLen                   Actual message length
 *  \param[in]     ExpectedMsgLen           Expected message length
 *  \return        E_OK                     If MsgLen is equal to ExpectedMsgLen
 *  \return        E_NOT_OK                 If MsgLen is NOT equal to ExpectedMsgLen
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsHs_CheckExpectedMsgLen(
  CONST(uint32, AUTOMATIC) MsgLen,
  CONST(uint32, AUTOMATIC) ExpectedMsgLen);

/**********************************************************************************************************************
 * TcpIp_TlsHsStm_ErrorHandlingAndStateTransition
 *********************************************************************************************************************/
/*! \brief         Change the state of the TLS state machine depending on the given internal function return value
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     IntRetVal               Return value of previous called internal function, either E_OK or E_NOT_OK
 *  \param[in]     NextHsState             Next state of TLS state machine if IntRetVal is E_OK
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsHsStm_ErrorHandlingAndStateTransition(
  TcpIp_TlsConnectionIterType      TlsConIdx,
  Std_ReturnType                   IntRetVal,
  TcpIp_TlsHandshakeState          NextHsState);

/**********************************************************************************************************************
 * TcpIp_TlsHsStm_HandlesUnexpectedHsInformation
 *********************************************************************************************************************/
/*! \brief         Handles unexpected TLS handshake information during TLS handshake
 *  \details       -
 *  \param[in]     TlsConIdx                TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsHsStm_HandlesUnexpectedHsInformation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsMsg_HelloMsgGetVersionNr
 *********************************************************************************************************************/
/*! \brief         Checks the received TLS major and TLS minor version number
 *  \details       -
 *  \param[in]     TlsConIdx                TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                     If correct version numbers received
 *  \return        E_NOT_OK                 If incorrect version numbers received
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsMsg_HelloMsgGetVersionNr(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsMsg_HelloMsgGetAndCheckRandom
 *********************************************************************************************************************/
/*! \brief         Checks the received random data within the TLS handshake HelloMessage
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Received random value valid
 *  \return        E_NOT_OK                Received random value invalid
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsMsg_HelloMsgGetAndCheckRandom(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsMsg_HelloMsgGetAndCheckSessionId
 *********************************************************************************************************************/
/*! \brief         Checks the received sessionId data within the TLS handshake HelloMessage
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     HelloEndIdx             End index of the hello message
 *  \return        E_OK                    Received sessionId valid
 *  \return        E_NOT_OK                Received sessionId invalid
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsMsg_HelloMsgGetAndCheckSessionId(
  TcpIp_TlsConnectionIterType  TlsConIdx,
  CONST(TcpIp_TlsBufferRxIterType, AUTOMATIC) HelloEndIdx);

/**********************************************************************************************************************
 * TcpIp_TlsMsg_CheckIfCipherSuiteIdMatches
 *********************************************************************************************************************/
/*! \brief         Checks the receives CipherSuite list and store the matching one as active for this TLS connection
 *  \details       -
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     CipherSuiteSelected      ID of the selected ciphersuite
 *  \return        E_OK                     Matching ciphersuite found
 *  \return        E_NOT_OK                 Matching ciphersuite NOT found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsMsg_CheckIfCipherSuiteIdMatches(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(TcpIp_TlsCipherDataType, AUTOMATIC) CipherSuiteSelected);

#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)                                                                            /* COV_MSR_UNSUPPORTED */

/**********************************************************************************************************************
 * TcpIp_TlsMsg_SelectDefaultHandshakeReference
 *********************************************************************************************************************/
/*! \brief         Select the first handshake reference as active one
 *  \details       The first handshake reference is only used in case of ECDH or PSK. In case of ECDHE the selection is
 *                 performed via the received curve type.
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsMsg_SelectDefaultHandshakeReference(
  TcpIp_TlsConnectionIterType  TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsMsg_SelectDefaultPskIdentity
 *********************************************************************************************************************/
/*! \brief         Select the configured default PSK identity as active
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsMsg_SelectDefaultPskIdentity(
  TcpIp_TlsConnectionIterType  TlsConIdx);
#  endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */

/**********************************************************************************************************************
 * TcpIp_TlsMsg_CheckMsgForRemainingData
 *********************************************************************************************************************/
/*! \brief         Checks if there are remaining data in the received TLS handshake message
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     MsgEndIdx               End index of the message
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsMsg_CheckMsgForRemainingData(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(TcpIp_TlsBufferRxIterType, AUTOMATIC) MsgEndIdx);


/**********************************************************************************************************************
 *  TcpIp_VIsPortUsedByAsrTls()
 **********************************************************************************************************************/
/*! \brief          Checks if the port number is allocated to a Tls connection (Client or Server)
 *  \details        -
 *  \param[in]      Port    Requested Port number
 *  \param[in]      Mode    Requested for TLS Client or TLS server
 *  \return         TRUE    If Port used by TLS
 *  \return         FALSE   If port is not used by TLS
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, TCPIP_CODE) TcpIp_VIsPortUsedByAsrTls(
 uint16                    Port,
 TcpIp_TlsConnectionMode   Mode);


# endif /* (TCPIP_SUPPORT_ASRTLS == STD_ON) */
#endif /* TCPIP_TLS_PRIV_H */

/**********************************************************************************************************************
 *  END OF FILE: TcpIp_TlsPriv.h
 *********************************************************************************************************************/

