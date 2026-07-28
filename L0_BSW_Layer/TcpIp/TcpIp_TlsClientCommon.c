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
/*!        \file  TcpIp_TlsClientCommon.c
 *        \brief  Transport Layer Security (TLS) client functions implementation.
 *
 *      \details  This file implements the TLS handshake until the used TLS version is known.
 *                This file is part of the TcpIp TLS submodule.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp module. >> TcpIp.h
 *********************************************************************************************************************/

#define TCPIP_TLSCLIENTCOMMON_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TcpIp_Cfg.h"

#if (TCPIP_SUPPORT_ASRTLS == STD_ON)                                                                                    /* COV_MSR_UNSUPPORTED */
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
#  include "TcpIp_Tls.h"
#  include "TcpIp_TlsPriv.h"

#  include "TcpIp_Types.h"
#  include "TcpIp_Lcfg.h"
#  include "vstdlib.h"
#  include "TcpIp_TlsCoreCommon.h"
#  include "TcpIp_TlsClientCommon.h"
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#   include "TcpIp_Tls12Client.h"
#  endif
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#   include "TcpIp_Tls13Client.h"
#  endif

#  if (TCPIP_DEV_ERROR_REPORT == STD_ON)
#   include "Det.h"
#  endif /* (TCPIP_DEV_ERROR_REPORT == STD_ON) */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#  define TCPIP_TLSCLIENT_COMPMETHLEN_LEN 1u
#  define TCPIP_TLSCLIENT_COMPMETH_LEN 1u

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#  if !defined (TCPIP_LOCAL)
#   define TCPIP_LOCAL static
#  endif

#  if !defined (TCPIP_LOCAL_INLINE)
#   define TCPIP_LOCAL_INLINE LOCAL_INLINE
#  endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#  define TCPIP_START_SEC_CODE
#  include "TcpIp_MemMap.h"                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  TLS CLIENT INIT FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TLS CLIENT HANDSHAKE STATE MACHINE
 *********************************************************************************************************************/
#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_CheckValidateCertificateStatusPrecondition
 *********************************************************************************************************************/
/*! \brief         Check if all preconditions for the validation of the certificate status are met.
 *  \details       It is checked that the KeyM API KeyM_ServiceCertificate is available.
 *  \param[in]     TlsConIdx                         TLS connection index
 *                                                   \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                              Preconditions are fulfilled, validation can be triggered
 *  \return        E_NOT_OK                          Preconditions are NOT fulfilled, an internal_error alert was set
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_CheckValidateCertificateStatusPrecondition(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_AddDhPubKey
 *********************************************************************************************************************/
/*! \brief         Add the DH public key
 *  \details       -
 *  \param[in]     TlsConIdx                       TLS connection index
 *                                                 \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     MessageType                     The message for which the public key should be added
 *  \param[in]     CurveId                         The curve Id for which the public key should be added
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_AddDhPubKey(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TcpIp_TlsMsgHandshakeType     MessageType,
  TcpIp_TlsEllipticCurveIdType  CurveId);

/**********************************************************************************************************************
 *  TcpIp_TlsClient_CheckSelectedSignAlg
 *********************************************************************************************************************/
/*! \brief         Check selected signature algorithm to be one of the offered algorithms and to be supported.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        TRUE                    Selected signature algorithm is supported
 *  \return        FALSE                   Selected signature algorithm is not supported
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsClient_CheckSelectedSignAlg(
  TcpIp_TlsConnectionIterType TlsConIdx);

#  endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ClientHelloExtAddSupportedGroups
 *********************************************************************************************************************/
/*! \brief         Add supported groups extension to the client hello message
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ClientHelloExtAddSupportedGroups(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ClientHelloExtAddSignatureAlgorithms
 *********************************************************************************************************************/
/*! \brief         Add the signature algorithms extension to the client hello message
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ClientHelloExtAddSignatureAlgorithms(
  TcpIp_TlsConnectionIterType TlsConIdx);

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ClientExtAddTrustedCAIndication
 *********************************************************************************************************************/
/*! \brief         Add trusted ca indication extension to the client hello message
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ClientExtAddTrustedCAIndication(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ClientExtAddTrustedAuthoritiesList
 *********************************************************************************************************************/
/*! \brief         Add list of trusted authorities to the TLS TxBuffer
 *  \details       -
 *  \param[in]     TlsConIdx                    TLS connection index
 *                                              \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     TrustedAuthorityListStartIdx Start index of the Trusted Authority list
 *  \param[in,out] ConsumedLenPtr               Number of bytes which are consumed by this extension
 *  \return        E_OK                         Extension added
 *  \return        E_NOT_OK                     Extension could not be added
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ClientExtAddTrustedAuthoritiesList(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferTxIterType TrustedAuthorityListStartIdx,
  TCPIP_P2V(uint16) ConsumedLenPtr);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ClientExtAddCertSha1Hash
 *********************************************************************************************************************/
/*! \brief         Add Sha1 Hash of a certificate to the TLS TxBuffer
 *  \details       -
 *  \param[in]     CertId                          Certificate Id
 *  \param[in,out] TrustedAuthoritiesListIterPtr   Pointer to the index of the Trusted Authority List
 *  \return        TRUE                            Hash added
 *  \return        FALSE                           Hash not added - could not be found in KeyM or is invalid
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsClientMsg_ClientExtAddCertSha1Hash(
  KeyM_CertificateIdType               CertId,
  TCPIP_P2V(TcpIp_TlsBufferTxIterType) TrustedAuthoritiesListIterPtr);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ClientExtAddKeySha1Hash
 *********************************************************************************************************************/
/*! \brief         Add Sha1 Hash of the public key of a certificate to the TLS TxBuffer
 *  \details       -
 *  \param[in]     CertId                          Certificate Id
 *  \param[in,out] TrustedAuthoritiesListIterPtr   Pointer to the index of the Trusted Authority List
 *  \return        TRUE                            Hash added
 *  \return        FALSE                           Hash not added - could not be found in KeyM or is invalid
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsClientMsg_ClientExtAddKeySha1Hash(
  KeyM_CertificateIdType               CertId,
  TCPIP_P2V(TcpIp_TlsBufferTxIterType) TrustedAuthoritiesListIterPtr);
#   endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ClientExtAddCertificateStatusRequest
 *********************************************************************************************************************/
/*! \brief         Add certificate status request extension to the client hello message
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
  *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ClientExtAddCertificateStatusRequest(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ClientExtAddServerNameIndication
 *********************************************************************************************************************/
/*! \brief         Add server name indication extension to the client hello message
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ClientExtAddServerNameIndication(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ClientExtAddServerNames
 *********************************************************************************************************************/
/*! \brief         Add list of server names to the TLS TxBuffer
 *  \details       -
 *  \param[in]     TlsConIdx                    TLS connection index
 *                                              CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     ServerNameListStartIdx Start index of the Server Name list
 *  \param[in,out] ConsumedLenPtr               Number of bytes which are consumed by this extension
 *  \return        E_OK                         Extension added
 *  \return        E_NOT_OK                     Extension could not be added
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ClientExtAddServerNames(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferTxIterType ServerNameListStartIdx,
  TCPIP_P2V(uint16) ConsumedLenPtr);
#  endif /* TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ClientHelloPrepareExtensionListLen
 *********************************************************************************************************************/
/*! \brief         Prepare the extension list length (extensions length in RFC8446) field for the Client Hello message
 *  \details       Skip the extension list length field for now but save the index to fill it out later
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ClientHelloPrepareExtensionListLen(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ClientHelloAddClientExtensions
 *********************************************************************************************************************/
/*! \brief         Add client extensions to the client hello message
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ClientHelloAddClientExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_PrepareClientHelloAndTriggerPubKeyCalculation
 *********************************************************************************************************************/
/*! \brief         Prepare the client hello message
 *  \details       Prepare the client hello message and trigger the public key calculation for the KeyShare extension
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Operation successful
 *  \return        E_NOT_OK                Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_PrepareClientHelloAndTriggerPubKeyCalculation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientHsStm_SendClientHello
 *********************************************************************************************************************/
/*! \brief         Trigger transmission of client hello message
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientHsStm_SendClientHello(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ClientHelloAddCipherSuites
 *********************************************************************************************************************/
/*! \brief         Add the supported ciphersuites to the client hello message
 *  \details       -
 *  \param[in]     TlsConIdx    TLS connection index
 *                              \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ClientHelloAddCipherSuites(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ClientHelloAddCompressionMethod
 *********************************************************************************************************************/
/*! \brief         Add compression method to the client hello message
 *  \details       -
 *  \param[in]     TlsConIdx    TLS connection index
 *                              \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ClientHelloAddCompressionMethod(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientHsStm_ForwardToStateMachineForActiveVersion
 *********************************************************************************************************************/
/*! \brief         Depending on the active TLS version of the connection delegate to a different Client state machine.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientHsStm_ForwardToStateMachineForActiveVersion(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientHsStm_ParseServerHello
 *********************************************************************************************************************/
/*! \brief         Parse the received RL message with the server hello message
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClientHsStm_ParseServerHello(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ExtractServerHello
 *********************************************************************************************************************/
/*! \brief         Extract the server hello message and set next state of the client HS state machine
 *  \details       -
 *  \param[in]     TlsConIdx                         TLS connection index
 *                                                   \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[out]    NextStatePtr                      Next state of the client HS state machine
 *  \return        E_OK                              Operation successful
 *  \return        E_NOT_OK                          Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ExtractServerHello(
  TcpIp_TlsConnectionIterType        TlsConIdx,
  TCPIP_P2V(TcpIp_TlsHandshakeState) NextStatePtr);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ExtractServerHelloInformation
 *********************************************************************************************************************/
/*! \brief         Extraction the server hello information from the received RL message
 *  \details       -
 *  \param[in]     TlsConIdx                         TLS connection index
 *                                                   \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                              Operation successful
 *  \return        E_NOT_OK                          Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ExtractServerHelloInformation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ServerHelloMsgGetCipherSuite
 *********************************************************************************************************************/
/*! \brief         Get the ciphersuite value from the server hello message
 *  \details       -
 *  \param[in]     TlsConIdx    TLS connection index
 *                              \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     HelloEndIdx  End idx of the server hello message
 *  \return        E_OK         Operation successful
 *  \return        E_NOT_OK     Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloMsgGetCipherSuite(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(TcpIp_TlsBufferRxIterType, AUTOMATIC) HelloEndIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ServerHelloMsgSelectHandshakeReference
 *********************************************************************************************************************/
/*! \brief         Select the handshake reference depending on the selected key exchange method
 *  \details       -
 *  \param[in]     TlsConIdx            TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     TlsCipherWorkerIdx   TLS cipherworker index whose handshake shall be used
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloMsgSelectHandshakeReference(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TcpIp_TlsCipherWorkerIterType TlsCipherWorkerIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ServerHelloMsgGetCompressionMethod
 *********************************************************************************************************************/
/*! \brief         Get compression method from the server hello message
 *  \details       -
 *  \param[in]     TlsConIdx    TLS connection index
 *                              \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     HelloEndIdx  End idx of the server hello message
 *  \return        E_OK         Operation successful
 *  \return        E_NOT_OK     Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloMsgGetCompressionMethod(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(TcpIp_TlsBufferRxIterType, AUTOMATIC) HelloEndIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ServerHelloDetermineNextState
 *********************************************************************************************************************/
/*! \brief         Determine the next state in the server hello message processing
 *  \details       -
 *  \param[in]     TlsConIdx                   TLS connection index
 *                                             \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[out]    NextStatePtr                Next state of the client HS state machine
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloDetermineNextState(
  TcpIp_TlsConnectionIterType        TlsConIdx,
  TCPIP_P2V(TcpIp_TlsHandshakeState) NextStatePtr);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ServerHelloDetermineNextStatePsk
 *********************************************************************************************************************/
/*! \brief         Determine the next state in the server hello message processing for PSK identity
 *  \details       -
 *  \param[in]     TlsConIdx                       TLS connection index
 *                                                 \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[out]    NextStatePtr                    Next state of the client HS state machine
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloDetermineNextStatePsk(
  TcpIp_TlsConnectionIterType        TlsConIdx,
  TCPIP_P2V(TcpIp_TlsHandshakeState) NextStatePtr);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ServerHelloGetExtensions
 *********************************************************************************************************************/
/*! \brief         Extract the extensions from the received server hello message
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     HelloEndIdx     End idx of the server hello message
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloGetExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferRxIterType   HelloEndIdx);

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ServerHelloUpdateOCSPInfo
 *********************************************************************************************************************/
/*! \brief         Updates the OCSP connection state of the connection based on TLS version being used.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloUpdateOCSPInfo(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
#  endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ServerMsgCompareAgainstTransmittedExtensions
 *********************************************************************************************************************/
/*! \brief         Compares the received server extensions against all transmitted client extensions
 *  \details       If received server extension is not contained in client list, return error
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ReceivedExtensionListPtr  Pointer to the list of received Server extensions
 *  \param[in]     ReceivedExtensionCnt      Number of received server extensions
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerMsgCompareAgainstTransmittedExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(TcpIp_TlsExtensionType) ReceivedExtensionListPtr,
  uint8 ReceivedExtensionCnt);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ServerMsgParseReceivedExtensions
 *********************************************************************************************************************/
/*! \brief         Parse all received server extension depending on the extension type.
 *  \details       Forwards the extension to the specific parser, if extension is supported, otherwise return error
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ReceivedExtensionListPtr  Pointer to the list of received Server extensions
 *  \param[in]     ReceivedExtensionCnt      Number of received server extensions
 *  \param[in]     SourceMessage             Type of the message in which the extensions were sent
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerMsgParseReceivedExtensions(
  TcpIp_TlsConnectionIterType       TlsConIdx,
  TCPIP_P2C(TcpIp_TlsExtensionType) ReceivedExtensionListPtr,
  uint8                             ReceivedExtensionCnt,
  TcpIp_TlsMsgHandshakeType         SourceMessage);

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ServerHelloParseExtensionEcPointFormat
 *********************************************************************************************************************/
/*! \brief         Parses an received TLS extension of the type ec_point_formats.
 *  \details       Compares the received extension data against the supported TLS client ones.
 *  \param[in]     EcPointFormatExtension       Extension of type ec point format
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloParseExtensionEcPointFormat(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType EcPointFormatExtension);
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ServerHelloParseExtensionCertificateStatusRequest
 *********************************************************************************************************************/
/*! \brief         Parses a received TLS extension of the type certificate status request.
 *  \details       Compares the received extension data against the supported TLS client ones.
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     CertificateStatusRequest       Extension of type certificate status request
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloParseExtensionCertificateStatusRequest(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType CertificateStatusRequest);

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ServerHelloParseExtensionTrustedCaIndication
 *********************************************************************************************************************/
/*! \brief         Parses a received TLS extension of the type trusted_ca_indication.
 *  \details       Check that the length of the Extension is 0.
 *  \param[in]     TrustedCaIndication       Extension of type trusted ca indication
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloParseExtensionTrustedCaIndication(
  TcpIp_TlsExtensionType TrustedCaIndication);
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */

 /**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ServerHelloParseExtensionServerNameIndication
 *********************************************************************************************************************/
/*! \brief         Parses a received TLS extension of the type server_name.
 *  \details       Check that the length of the Extension is 0.
 *  \param[in]     ServerNameIndication    Extension of type server name indication
 *  \return        E_OK                    Operation successful
 *  \return        E_NOT_OK                Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
 TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloParseExtensionServerNameIndication(
   TcpIp_TlsExtensionType ServerNameIndication);

/**********************************************************************************************************************
 * TcpIp_TlsClientHsStm_PerformNextHsStep
 *********************************************************************************************************************/
/*! \brief         Perform the next HS processing step
 *  \details       Main TLS client handshake state machine handling when the TLS version is not clear yet.
 *                 So only sending ClientHello and receiving ServerHello are processed here.
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientHsStm_PerformNextHsStep(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *   TLS CLIENT HS TRIGGER SM
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsClientTx_ForwardProcessedHsMsgToRl
 *********************************************************************************************************************/
/*! \brief         Forwards the processed TLS handshake message to the record layer for transmission.
 *  \details       The TLS-Client handshake message is specified through the HandshakeType parameter.
 *  \param[in]     TlsConIdx               TLS connection index
 *                                          CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *                 HandshakeType           Type of the handshake message which should be forwarded
 *  \return        TRUE                    TLS message was forwarded to the record layer
 *  \return        FALSE                   TLS message was NOT forwarded to the record layer
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsClientTx_ForwardProcessedHsMsgToRl(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(TcpIp_TlsMsgHandshakeType, AUTOMATIC) HandshakeType);

/**********************************************************************************************************************
 *  TcpIp_TlsClient_GetCurrentTlsConnectionPriority
 *********************************************************************************************************************/
/*! \brief         Determines the priority of a TLS Connection.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                      CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     SocketIdx          Index of the assigned socket
 *  \param[in]     UsedPort           Port which is used to identify the TLS connection
 *  \return        priority           Valid if a matching Tls connection exists
 *  \return        priority           Invalid if no matching Tls connection exists
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(TcpIp_TlsConnectionPrioType, TCPIP_CODE) TcpIp_TlsClient_GetCurrentTlsConnectionPriority(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SocketDynIterType SocketIdx,
  CONST(TcpIp_PortOfTlsListenerType, AUTOMATIC) UsedPort);

/**********************************************************************************************************************
 *  TLS CLIENT ASYNC CONTEXT
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MSA - Master Secret Access
 *********************************************************************************************************************/
#  if ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON))
/**********************************************************************************************************************
 * TcpIp_TlsClientMsa_AddClientRandomToAccessBuffer
 *********************************************************************************************************************/
/*! \brief         Copy the Client Random into the Client MSA_AccessBuffer
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsa_AddClientRandomToAccessBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx);
#  endif /* ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON)) */

#  if ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON))
/**********************************************************************************************************************
 * TcpIp_TlsClientMsa_AddServerSessionIdToAccessBuffer
 *********************************************************************************************************************/
/*! \brief         Copy the Server sessionId into the Client MSA_AccessBuffer
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsa_AddServerSessionIdToAccessBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx);
#  endif /* ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON)) */
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TLS CLIENT INIT FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsClient_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_Init(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsConnectionIterType tlsConIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all configured TLS connections and initialize the submodules. */
  for (tlsConIdx = 0; tlsConIdx < TcpIp_GetSizeOfTlsConnection(); tlsConIdx++)
  {
    if (TcpIp_GetModeOfTlsConnection(tlsConIdx) == TCPIP_TLS_CLIENT)
    {
      TcpIp_TlsClient_InitConnection(tlsConIdx);
    }
  }

} /* TcpIp_TlsClient_Init() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_ConfigTcpSocket
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClient_ConfigTcpSocket(
  TcpIp_SizeOfSocketTcpDynType      SocketTcpIdx,
  TCPIP_P2C(TcpIp_SockAddrBaseType) RemoteAddrPtr)
{
  Std_ReturnType                    retVal = E_OK;

  /* #10 Check if TLS shall be used for this socket. */
    /* Check if the socket already has been dynamically configured to use TLS (by TcpIp_ChangeParameter(TCPIP_PARAMID_TLS_CONNECTION_ASSIGNMENT)). */
  if (TcpIp_IsUseTlsOfSocketTcpDyn(SocketTcpIdx) == FALSE)                                                              /* PRQA S 3415 3 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
  {
    /* TLS is not yet activated on this socket. Check if the remote port is pre-configured for a TLS client connection. */

    uint16 remotePort = RemoteAddrPtr->DomainAndPort.port;

    /* #20 TLS is not yet configured for the socket. Now check if the local port is pre-configured for TLS. */
    /* If the requested remote port is configured for a Tls client, then Tls client connection shall be triggered for the socket */
    if (TcpIp_VIsPortUsedByAsrTls(remotePort, TCPIP_TLS_CLIENT) == TRUE)
    {
      TcpIp_TlsConnectionIterType tlsConIdx = 0u;
      TcpIp_SizeOfSocketDynType socketIdx = TCPIP_TCP_IDX_TO_SOCKET_IDX(SocketTcpIdx);

      TcpIp_SetUseTlsOfSocketTcpDyn(SocketTcpIdx, TRUE);

      retVal = TcpIp_TlsCore_GetNextFreeTlsClientConnection(socketIdx, remotePort, &tlsConIdx);
    }
    else
    {
      /* No TLS is activated on this socket, this is a simple TCP socket. */
      /* retVal is already set to E_OK */
    }
  }
  else
  {
    /* The TLS connection was already assigned to the socket by TcpIp_ChangeParameter. */
    /* retVal is already set to E_OK */
  }
  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsClient_InitConnection
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
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_InitConnection(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientConnectionIdxOfTlsConnectionType tlsClientConnectionIdx
    = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize the handshake message indices */
  TcpIp_TlsClient_InitHsMsgIndices(TlsConIdx);

  /* #20 Initialize the handshake length information */
  TcpIp_TlsClient_InitHsLenInformation(TlsConIdx);

  /* #30 Initialize the ready to send flags */
  TcpIp_TlsClient_InitReadyToSendFlags(TlsConIdx);

  /* #40 Initialize the async context flags */
  TcpIp_TlsClient_InitAsyncFlags(TlsConIdx);

  TcpIp_SetReceivedCipherSuiteIdOfTlsClientConnection(tlsClientConnectionIdx,
    TCPIP_TLS_CIPHER_INVALID);

  TcpIp_SetIdxForNextGroupToCalculatePubKeyOfTlsClientConnection(tlsClientConnectionIdx, 0);

  TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_INIT);

  TcpIp_SetSccPushButtonModeOfTlsClientConnection(tlsClientConnectionIdx, FALSE);

  TcpIp_TlsClient_ResetWorkingSetsOfCipherSuitesAndSignatureAlgorithms(TlsConIdx);

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
  /* #50 Reset the certificate information for the handshake */
  {
    TcpIp_TlsKeyExchangeMethodDataType keyExchangeMethod
      = TcpIp_TlsCoreUtil_ReturnActiveCipherSpecificKeyExchangeMethod(TlsConIdx);

    /* keyExchangeMethod can be TCPIP_TLS_KEYEXCHANGE_METHOD_INVALID if connection was not used before,
     * reset cert chain states then as well */
    if (keyExchangeMethod != TCPIP_TLS_KEYEXCHANGE_METHOD_PSK_PLAIN)
    {
      TcpIp_TlsClient_ResetCertChainStates(TlsConIdx);
    }
  }
#  endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

  /* Init age of the session resumption base connection */
  TcpIp_SetResumptionBaseConnectionAgeOfTlsClientConnection(tlsClientConnectionIdx, 0u);

} /* TcpIp_TlsClient_InitConnection() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_InitHsMsgIndices
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_InitHsMsgIndices(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Init RX handshake Indices */
  TcpIp_SetTlsBufferRxServerHelloIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXSERVERHELLOIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferRxServerRandomIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXSERVERRANDOMIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferRxServerSessionIdIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXSERVERSESSIONIDIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferRxServerCertificatesIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXSERVERCERTIFICATESIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferRxServerCertificateStatusIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXSERVERCERTIFICATESTATUSIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferRxServerKeyExchangeIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXSERVERKEYEXCHANGEIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferRxServerKeyExchangePskParamIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXSERVERKEYEXCHANGEPSKPARAMIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferRxServerKeyExchangePskHintIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXSERVERKEYEXCHANGEPSKHINTIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferRxServerSignatureLenIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXSERVERSIGNATURELENIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferRxServerSignatureIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXSERVERSIGNATUREIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferRxServerCertificateRequestIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXSERVERCERTIFICATEREQUESTIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferRxServerHelloDoneIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXSERVERHELLODONEIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferRxServerFinishedIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXSERVERFINISHEDIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferRxServerFinishedVerifyDataIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXSERVERFINISHEDVERIFYDATAIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferRxServerCertificateRequestCertTypesIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXSERVERFINISHEDVERIFYDATAIDXOFTLSCLIENTBUFFERMGMT);

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  TcpIp_SetTlsBufferRxEncryptedExtensionsIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXENCRYPTEDEXTENSIONSIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferRxServerCertificateVerifyIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXSERVERCERTIFICATEVERIFYIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferTxClientKeyShareExtensionIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERTXCLIENTKEYSHAREEXTENSIONIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferTxClientHelloPreSharedKeyExtBinderIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERTXCLIENTHELLOPRESHAREDKEYEXTBINDERIDXOFTLSCLIENTBUFFERMGMT);
#  endif

  /* #20 Init TX handshake Indices */
  TcpIp_SetTlsBufferTxClientHelloIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERTXCLIENTHELLOIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferTxClientRandomIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERTXCLIENTRANDOMIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferTxClientSessionIdIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERTXCLIENTSESSIONIDIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferTxClientCertificateIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERTXCLIENTCERTIFICATEIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferTxClientKeyExchangeIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERTXCLIENTKEYEXCHANGEIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferTxClientKeyExchangePubKeyIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERTXCLIENTKEYEXCHANGEPUBKEYIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferTxClientKeyExchangePubKeyLenIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERTXCLIENTKEYEXCHANGEPUBKEYLENIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferTxClientFinishedIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERTXCLIENTFINISHEDIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferTxClientFinishedVerifyDataIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERTXCLIENTFINISHEDVERIFYDATAIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferTxClientExtensionsIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERTXCLIENTEXTENSIONSIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferTxClientCertificateVerifyIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERTXCLIENTCERTIFICATEVERIFYIDXOFTLSCLIENTBUFFERMGMT);
  TcpIp_SetTlsBufferTxClientCertVerifySignatureLenIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERTXCLIENTCERTVERIFYSIGNATURELENIDXOFTLSCLIENTBUFFERMGMT);

} /* TcpIp_TlsClient_InitHsMsgIndices() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_InitHsLenInformation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_InitHsLenInformation(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize the TX length information to zero */
  TcpIp_SetClientHelloLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, 0);
  TcpIp_SetClientCertificateLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, 0);
  TcpIp_SetClientKeyExchangeLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, 0);
  TcpIp_SetClientCertificateVerifyLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, 0);
  TcpIp_SetClientFinishedLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, 0);

  /* #20 Initialize the RX length information to zero */
  TcpIp_SetServerHelloLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, 0);
  TcpIp_SetServerCertificatesLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, 0);
  TcpIp_SetServerCertificateStatusLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, 0);
  TcpIp_SetServerCertStatusOcspResponseLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, 0);
  TcpIp_SetServerKeyExchangeLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, 0);
  TcpIp_SetServerCertificateRequestLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, 0);
  TcpIp_SetServerHelloDoneLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, 0);
  TcpIp_SetServerFinishedLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, 0);
  TcpIp_SetServerHelloSessionIdLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, 0);
  TcpIp_SetServerKeyExchangePskHintLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, 0);

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  TcpIp_SetEncryptedExtensionsLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, 0);
  TcpIp_SetServerCertificateVerifyLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, 0);
#  endif

} /* TcpIp_TlsClient_InitHsLenInformation() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_InitAsyncFlags
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
 /* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_InitAsyncFlags(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx
    = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize the TLS Client Async trigger flags */
  TcpIp_SetCalcClientFinishedHashAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
  TcpIp_SetCalcServerFinishedHashAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
  TcpIp_SetCalcServerFinishedVerifyDataAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
  TcpIp_SetHsVerifySignatureAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
  TcpIp_SetCertificateStatusOcspValidationAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
  TcpIp_SetCalcClientCertVerifySignatureAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
} /* TcpIp_TlsClient_InitAsyncFlags() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_InitReadyToSendFlags
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_InitReadyToSendFlags(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx
    = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize the TLS-Client ReadyToSend flags */
  TcpIp_SetHelloReadyToSendOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
  TcpIp_SetClientCertificateReadyToSendOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
  TcpIp_SetKeyExchangeReadyToSendOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
  TcpIp_SetClientFinishedReadyToSendOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
  TcpIp_SetChangeCipherSpecReadyToSendOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
  TcpIp_SetCertificateVerifyReadyToSendOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
} /* TcpIp_TlsClient_InitReadyToSendFlags() */

/**********************************************************************************************************************
 *  TLS CLIENT HANDSHAKE STATE MACHINE
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsClient_HandshakeInitCipherWorkingSets
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_HandshakeInitCipherWorkingSets(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  switch (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx))
  {
    case TCPIP_TLS_STATE_HANDSHAKE_INIT:
    {
      /* #10 Build runtime lists for ciphersuites and signature algorithms to support the changeable cipher callout */
      TcpIp_TlsClient_BuildWorkingSetsOfCipherSuitesAndSignatureAlgorithms(TlsConIdx);
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      if (TcpIp_IsTlsSupportVersion13OfTlsConnection(TlsConIdx) == TRUE)
      {
        if (TcpIp_IsTlsUseChangeableCipherCallbackOfTlsConnection(TlsConIdx) == TRUE)
        {
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_INIT_CHANGEABLE_CIPHER_CALLOUT);
        }
        else
        {
          /* Skip callout if not configured */
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_HELLO);
        }
      }
      else
#  endif
      {
        /* Skip callout if TLS 1.3 is not supported by connection */
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_HELLO);
      }
      break;
    }
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    case TCPIP_TLS_STATE_HANDSHAKE_INIT_CHANGEABLE_CIPHER_CALLOUT:
    {
      /* #20 Issue callout to UL */
      if (TcpIp_Tls13Client_IssueChangeableCipherCallout(TlsConIdx) != E_OK)
      {
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
        TcpIp_TlsClientHsStm_HandleErrorDuringPreparation(TlsConIdx);
      }
      break;
    }
#  endif
    default:
    {
      /* This case should not be reached */
      break;
    }
  }
}

/**********************************************************************************************************************
 *  TcpIp_TlsClient_ResetWorkingSetsOfCipherSuitesAndSignatureAlgorithms
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_ResetWorkingSetsOfCipherSuitesAndSignatureAlgorithms(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkingSetMgmtIdxOfTlsConnectionType tlsCipherWorkingSetMgmtIdx
    = TcpIp_GetTlsCipherWorkingSetMgmtIdxOfTlsConnection(TlsConIdx);

  uint8 cipherSuiteIter;
  uint8 signAlgoIter;

  /* ----- Implementation ----------------------------------------------- */
  if (tlsCipherWorkingSetMgmtIdx != TCPIP_NO_TLSCIPHERWORKINGSETMGMTIDXOFTLSCONNECTION)
  {
    TCPIP_P2V(TcpIp_TlsCipherSuiteWorkingSetType) cipherSuitePtr
      = TcpIp_GetAddrCipherSuiteWorkingSetOfTlsCipherWorkingSetMgmt(tlsCipherWorkingSetMgmtIdx);
    TCPIP_P2V(TcpIp_TlsSignatureAlgorithmWorkingSetType) signAlgoPtr
      = TcpIp_GetAddrSignatureAlgorithmWorkingSetOfTlsCipherWorkingSetMgmt(tlsCipherWorkingSetMgmtIdx);

    /* #10 Reset cipher suite working set */
    for (cipherSuiteIter = 0; cipherSuiteIter < TCPIP_TLS_CIPHERSUITE_AMOUNT; cipherSuiteIter++)
    {
      cipherSuitePtr->workingSet[cipherSuiteIter] = TCPIP_TLS_CIPHER_INVALID;
    }
    cipherSuitePtr->workingSetLen = 0u;

    /* #20 Reset signature algorithm working set */
    for (signAlgoIter = 0; signAlgoIter < TCPIP_TLS_SIGNATURE_ALGO_AMOUNT; signAlgoIter++)
    {
      signAlgoPtr->workingSet[signAlgoIter] = (uint16)TCPIP_SIG_ALGO_ID_NONE;
    }
    signAlgoPtr->workingSetLen = 0u;
  }
} /* TcpIp_TlsClient_ResetWorkingSetsOfCipherSuitesAndSignatureAlgorithms() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_BuildWorkingSetsOfCipherSuitesAndSignatureAlgorithms
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_BuildWorkingSetsOfCipherSuitesAndSignatureAlgorithms(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerIndIterType tlsCipherWorkerIndIdx;

  TcpIp_TlsCipherWorkingSetMgmtIdxOfTlsConnectionType tlsCipherWorkingSetMgmtIdx
    = TcpIp_GetTlsCipherWorkingSetMgmtIdxOfTlsConnection(TlsConIdx);

  uint8 cipherSuiteIter = 0;

  /* ----- Implementation ----------------------------------------------- */
  if (tlsCipherWorkingSetMgmtIdx != TCPIP_NO_TLSCIPHERWORKINGSETMGMTIDXOFTLSCONNECTION)
  {
    TCPIP_P2V(TcpIp_TlsCipherSuiteWorkingSetType) cipherSuitePtr
      = TcpIp_GetAddrCipherSuiteWorkingSetOfTlsCipherWorkingSetMgmt(tlsCipherWorkingSetMgmtIdx);

    if (cipherSuitePtr != NULL_PTR)
    {
      for (tlsCipherWorkerIndIdx = TcpIp_GetTlsCipherWorkerIndStartIdxOfTlsConnection(TlsConIdx);
        tlsCipherWorkerIndIdx < TcpIp_GetTlsCipherWorkerIndEndIdxOfTlsConnection(TlsConIdx); tlsCipherWorkerIndIdx++)
      {
        TcpIp_TlsCipherWorkerIterType tlsCipherWorkerIdx = TcpIp_GetTlsCipherWorkerInd(tlsCipherWorkerIndIdx);

        TcpIp_TlsCipherDefinitionIdxOfTlsCipherWorkerType tlsCipherDefinitionIdx
          = TcpIp_GetTlsCipherDefinitionIdxOfTlsCipherWorker(tlsCipherWorkerIdx);
        TcpIp_CipherSuiteIdOfTlsCipherDefinitionType tlsCipherSuiteId
          = TcpIp_GetCipherSuiteIdOfTlsCipherDefinition(tlsCipherDefinitionIdx);

        /* Check if max length of array is not reached yet */
        if ((cipherSuiteIter + 1u) < TCPIP_TLS_CIPHERSUITE_AMOUNT)
        {
          /* #10 Add cipher suite to buffer of working set, if not already there */
          if (TcpIp_TlsClient_IsCipherSuiteInWorkingSet(TlsConIdx, tlsCipherSuiteId) == FALSE)
          {
            cipherSuitePtr->workingSet[cipherSuiteIter] = tlsCipherSuiteId;
            cipherSuiteIter++;
            cipherSuitePtr->workingSetLen = cipherSuiteIter;
          }

          /* #20 Add signature algorithms to working set */
          TcpIp_TlsClient_BuildWorkingSetOfSignatureAlgorithms(TlsConIdx, tlsCipherWorkerIdx);
        }
      }
    }
  }
} /* TcpIp_TlsClient_BuildWorkingSetsOfCipherSuitesAndSignatureAlgorithms() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_BuildWorkingSetOfSignatureAlgorithms
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_BuildWorkingSetOfSignatureAlgorithms(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsCipherWorkerIterType TlsCipherWorkerIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkingSetMgmtIdxOfTlsConnectionType tlsCipherWorkingSetMgmtIdx
    = TcpIp_GetTlsCipherWorkingSetMgmtIdxOfTlsConnection(TlsConIdx);
  TCPIP_P2V(TcpIp_TlsSignatureAlgorithmWorkingSetType) signAlgoPtr
    = TcpIp_GetAddrSignatureAlgorithmWorkingSetOfTlsCipherWorkingSetMgmt(tlsCipherWorkingSetMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  if (signAlgoPtr != NULL_PTR)
  {
    uint8 signAlgoIter = signAlgoPtr->workingSetLen;

    TcpIp_TlsHandshakeIndStartIdxOfTlsCipherWorkerType handshakeStartIdx
      = TcpIp_GetTlsHandshakeIndStartIdxOfTlsCipherWorker(TlsCipherWorkerIdx);
    TcpIp_TlsHandshakeIndEndIdxOfTlsCipherWorkerType handshakeEndIdx
      = TcpIp_GetTlsHandshakeIndEndIdxOfTlsCipherWorker(TlsCipherWorkerIdx);
    TcpIp_TlsHandshakeIndIterType tlsHandshakeIndIdx;

    /* Iterate over all configured handshake for this CipherWorker */
    for (tlsHandshakeIndIdx = handshakeStartIdx; tlsHandshakeIndIdx < handshakeEndIdx; tlsHandshakeIndIdx++)
    {
      /* Get the configured signature algorithm */
      TcpIp_TlsHandshakeIterType tlsHandshakeIdx = TcpIp_GetTlsHandshakeInd(tlsHandshakeIndIdx);
      TcpIp_TlsEllipticCurveIdType currentEllipticCurveId = TcpIp_GetEllipticCurveIdOfTlsHandshake(tlsHandshakeIdx);

      /* If the handshake is configured as PSK (curveId set to TCPIP_CURVE_ID_NO_CURVE) */
      if (currentEllipticCurveId != TCPIP_CURVE_ID_NO_CURVE)
      {
        TcpIp_SignatureAlgorithmIdType tlsSignatureAlgorithmId
          = TcpIp_GetSignatureAlgorithmIdOfTlsHandshake(tlsHandshakeIdx);

        /* Check if max length of array is not reached yet */
        if ((signAlgoIter + 1u) < TCPIP_TLS_SIGNATURE_ALGO_AMOUNT)
        {
          /* #10 Add signature algorithm to buffer of working set, if not already there */
          if (TcpIp_TlsClient_IsSignatureAlgorithmInWorkingSet(TlsConIdx, tlsSignatureAlgorithmId) == FALSE)
          {
            signAlgoPtr->workingSet[signAlgoIter] = (uint16) tlsSignatureAlgorithmId;
            signAlgoIter++;
            signAlgoPtr->workingSetLen = signAlgoIter;
          }
        }
      }
    }
  }
} /* TcpIp_TlsClient_BuildWorkingSetOfSignatureAlgorithms() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_IsSignatureAlgorithmInWorkingSet
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, TCPIP_CODE) TcpIp_TlsClient_IsSignatureAlgorithmInWorkingSet(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SignatureAlgorithmIdType SignAlgoId)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;

  TcpIp_TlsCipherWorkingSetMgmtIdxOfTlsConnectionType tlsCipherWorkingSetMgmtIdx
    = TcpIp_GetTlsCipherWorkingSetMgmtIdxOfTlsConnection(TlsConIdx);
  TCPIP_P2C(TcpIp_TlsSignatureAlgorithmWorkingSetType) signAlgoPtr
    = TcpIp_GetAddrSignatureAlgorithmWorkingSetOfTlsCipherWorkingSetMgmt(tlsCipherWorkingSetMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get Idx of signature algorithm in the working set */
  uint8 idxOfSignAlgo = TcpIp_TlsClient_ReturnIdxOfSignatureAlgorithmInWorkingSet(TlsConIdx, SignAlgoId);
  /* The function call above returns the max length of the array if the element was not found. Therefore, we can assume
   * that an invalid index indicates that the signature algorithm is not in the working set. */
  if (idxOfSignAlgo < signAlgoPtr->workingSetLen)
  {
    retVal = TRUE;
  }
  /* else: retVal is already FALSE */
  return retVal;
} /* TcpIp_TlsClient_IsSignatureAlgorithmInWorkingSet() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_ReturnIdxOfSignatureAlgorithmInWorkingSet
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint8, TCPIP_CODE) TcpIp_TlsClient_ReturnIdxOfSignatureAlgorithmInWorkingSet(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SignatureAlgorithmIdType SignAlgoId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 signAlgoIter;

  TcpIp_TlsCipherWorkingSetMgmtIdxOfTlsConnectionType tlsCipherWorkingSetMgmtIdx
    = TcpIp_GetTlsCipherWorkingSetMgmtIdxOfTlsConnection(TlsConIdx);
  TCPIP_P2C(TcpIp_TlsSignatureAlgorithmWorkingSetType) signAlgoPtr
    = TcpIp_GetAddrSignatureAlgorithmWorkingSetOfTlsCipherWorkingSetMgmt(tlsCipherWorkingSetMgmtIdx);

  /* Initially set to an invalid number */
  uint8 idxOfSignAlgo = signAlgoPtr->workingSetLen;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all signature algorithms in working set */
  for (signAlgoIter = 0; signAlgoIter < signAlgoPtr->workingSetLen; signAlgoIter++)
  {
    if ((uint16)SignAlgoId == signAlgoPtr->workingSet[signAlgoIter])
    {
      /* #20 Signature algorithm is in working set - return the idx of the signature algorithm */
      idxOfSignAlgo = signAlgoIter;
      break;
    }
  }
  return idxOfSignAlgo;
} /* TcpIp_TlsClient_ReturnIdxOfSignatureAlgorithmInWorkingSet() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_WorkingSetIncludesTlsVersion
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, TCPIP_CODE) TcpIp_TlsClient_WorkingSetIncludesTlsVersion(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsVersionType TlsVersion)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerIndIterType tlsCipherWorkerIndIdx;

  boolean tlsVersionIsInWorkingSet = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Find cipherworker in config with the same ciphersuite in the working set and with specific version */
  for (tlsCipherWorkerIndIdx = TcpIp_GetTlsCipherWorkerIndStartIdxOfTlsConnection(TlsConIdx);
       tlsCipherWorkerIndIdx < TcpIp_GetTlsCipherWorkerIndEndIdxOfTlsConnection(TlsConIdx);
       tlsCipherWorkerIndIdx++)
  {
    TcpIp_TlsCipherWorkerIterType tlsCipherWorkerIdx = TcpIp_GetTlsCipherWorkerInd(tlsCipherWorkerIndIdx);
    TcpIp_TlsCipherDefinitionIdxOfTlsCipherWorkerType tlsCipherDefinitionIdx =
      TcpIp_GetTlsCipherDefinitionIdxOfTlsCipherWorker(tlsCipherWorkerIdx);
    TcpIp_TlsVersionType cipherSuiteTlsVersion
      = TcpIp_GetTlsVersionOfTlsCipherDefinition(tlsCipherDefinitionIdx);

    if (cipherSuiteTlsVersion == TlsVersion)
    {
      TcpIp_CipherSuiteIdOfTlsCipherDefinitionType selectedCipherSuiteId
        = TcpIp_GetCipherSuiteIdOfTlsCipherDefinition(tlsCipherDefinitionIdx);

      if (TcpIp_TlsClient_IsCipherSuiteInWorkingSet(TlsConIdx, selectedCipherSuiteId) == TRUE)
      {
        tlsVersionIsInWorkingSet = TRUE;
        break;
      }
    }
  }
  return tlsVersionIsInWorkingSet;
} /* TcpIp_TlsClient_WorkingSetIncludesTlsVersion() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_IsCipherWorkingSetUnavailableOrZeroLength
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(boolean, TCPIP_CODE) TcpIp_TlsClient_IsCipherWorkingSetUnavailableOrZeroLength(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean workingSetUnavailableOrZeroLength = TRUE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if working set is available */
  TcpIp_TlsCipherWorkingSetMgmtIdxOfTlsConnectionType tlsCipherWorkingSetMgmtIdx
    = TcpIp_GetTlsCipherWorkingSetMgmtIdxOfTlsConnection(TlsConIdx);
  if (tlsCipherWorkingSetMgmtIdx != TCPIP_NO_TLSCIPHERWORKINGSETMGMTIDXOFTLSCONNECTION)
  {
    TCPIP_P2C(TcpIp_TlsCipherSuiteWorkingSetType) cipherSuitePtr
      = TcpIp_GetAddrCipherSuiteWorkingSetOfTlsCipherWorkingSetMgmt(tlsCipherWorkingSetMgmtIdx);
    if (cipherSuitePtr != NULL_PTR)
    {
      /* #20 Check the length of the working set */
      if (cipherSuitePtr->workingSetLen != 0u)
      {
        workingSetUnavailableOrZeroLength = FALSE;
      }
    }
  }
  return workingSetUnavailableOrZeroLength;
} /* TcpIp_TlsClient_IsCipherWorkingSetUnavailableOrZeroLength() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_IsCipherSuiteInWorkingSet
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(boolean, TCPIP_CODE) TcpIp_TlsClient_IsCipherSuiteInWorkingSet(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsCipherDataType     CipherSuiteId)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean foundCipherSuite = FALSE;
  uint8 cipherSuiteIter;

  TcpIp_TlsCipherWorkingSetMgmtIdxOfTlsConnectionType tlsCipherWorkingSetMgmtIdx
    = TcpIp_GetTlsCipherWorkingSetMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  if (tlsCipherWorkingSetMgmtIdx != TCPIP_NO_TLSCIPHERWORKINGSETMGMTIDXOFTLSCONNECTION)
  {
    TCPIP_P2C(TcpIp_TlsCipherSuiteWorkingSetType) cipherSuitePtr
      = TcpIp_GetAddrCipherSuiteWorkingSetOfTlsCipherWorkingSetMgmt(tlsCipherWorkingSetMgmtIdx);

    /* #10 Iterate over all cipher suites in working set */
    for (cipherSuiteIter = 0; cipherSuiteIter < cipherSuitePtr->workingSetLen; cipherSuiteIter++)
    {
      if (CipherSuiteId == cipherSuitePtr->workingSet[cipherSuiteIter])
      {
        /* #20 cipher suite is in working set - return TRUE */
        foundCipherSuite = TRUE;
        break;
      }
    }
  }
  return foundCipherSuite;
} /* TcpIp_TlsClient_IsCipherSuiteInWorkingSet() */

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_AddDiffieHellmanParams
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
FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_AddDiffieHellmanParams(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsMsgHandshakeType MessageType,
  TcpIp_TlsEllipticCurveIdType CurveId)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);
  uint8 publicKeyLen;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the length of the calculated Public key, depended on the current selected curve  */
  publicKeyLen = TcpIp_TlsMsg_GetLenOfCurveSpecificPubKey(CurveId);

  /* Check if the compression flag is required */
  if (TcpIp_TlsCoreUtil_CheckPublicKeyCompressionFlagOfEllipticCurve(CurveId) == TRUE)
  {
    publicKeyLen += TCPIP_TLS_KEYEXCH_COMPFLAGLEN;
  }

  if (MessageType == TCPIP_TLS_HSTYPE_CLIENTKEYEXCHANGE)
  {
    /* Save the current Write index for Key Exchange parameter (needed for signature generation) */
    TcpIp_SetTlsBufferTxClientKeyExchangePubKeyIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
      TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

    /* #20 Write the Length of the PublicKey in the TLS TxBuffer */
    IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(
      TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)), 0, publicKeyLen);

    /* Increment the write index by the consumed length (1 Byte) */
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_KEYEXCH_PUBKEYLEN );
  }
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  else if (MessageType == TCPIP_TLS_HSTYPE_CLIENTHELLO)
  {
    /* #30 Write the Length of the PublicKey in the TLS TxBuffer */
    /* In the KeyShare extension the length is an uint16 value different to the ClientKeyExchange message. */
    IpBase_PutUint16(
      TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)),
      0,
      publicKeyLen);

    /* Increment the write index by the consumed length (2 Bytes) */
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_KEY_SHARE_KEY_EXCHANGE_LEN);
  }
#   endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
  else
  {
    TCPIP_ASSERT_UNREACHABLE();
  }

  /* #40 Check if the compression flag is required */
  if (TcpIp_TlsCoreUtil_CheckPublicKeyCompressionFlagOfEllipticCurve(
    CurveId) == TRUE)
  {
    /* #50 if so, write the compression flag */
    IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(
      TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)), 0, TCPIP_TLS_PUBKEY_COMPRESSION_FLAG);

    /* Increment the write index by the consumed length (1 Byte) */
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_KEYEXCH_COMPFLAGLEN);
  }

  /* #60 Call the internal function to write the generated DH public key in the TLS TxBuffer */
  TcpIp_TlsClientMsg_AddDhPubKey(TlsConIdx, MessageType, CurveId);

} /* TcpIp_TlsClientMsg_AddDiffieHellmanParams() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_CheckPreconditionAndTriggerValidateCertificateStatus
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_CheckPreconditionAndTriggerValidateCertificateStatus(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsVersionType        TlsVersion)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_ASSERT(TlsVersion != TCPIP_TLSVERSION_NOTSET);

  /* #10 Check if the precondition for the validation of the certificate status is fulfilled. */
  if (TcpIp_TlsClientMsg_CheckValidateCertificateStatusPrecondition(TlsConIdx) == E_OK)
  {
    /* #20 If so, trigger the correct function depending on the TLS version. */
#   if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#    if(TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    if (TlsVersion == TCPIP_TLSVERSION_12)
#    endif
    {
      TcpIp_Tls12ClientCtx_ValidateCertificateStatus(TlsConIdx);
    }
#   endif
#   if(TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#    if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
    else /* TCPIP_TLSVERSION_13 */
#    endif
    {
      TcpIp_Tls13ClientCtx_ValidateCertificateStatus(TlsConIdx);
    }
#   endif

#   if((TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_OFF) || (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_OFF))
    TCPIP_DUMMY_STATEMENT_CONST(TlsVersion);                                                                            /* PRQA S 1338, 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
#   endif
  }

} /* TcpIp_TlsClientMsg_CheckPreconditionAndTriggerValidateCertificateStatus() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_CheckValidateCertificateStatusPrecondition
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_CheckValidateCertificateStatusPrecondition(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsKeyMServiceCertificateFunctionType serviceCertificateFunc
    = TcpIp_GetKeyMServiceCertificateFuncOfTlsConfig(TCPIP_TLSCONFIG_IDX);

  TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx
    = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the KeyM API KeyM_ServiceCertificate is available. */
  if (serviceCertificateFunc == NULL_PTR)
  {
    /* The value of /KeyM/KeyMGeneral/KeyMServiceCertificateFunctionEnabled must be true. */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);

    /* Reset the processing trigger for the OCSP validation */
    TcpIp_SetCertificateStatusOcspValidationAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_ABORT);
    TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);
  }
  else
  {
    retVal = E_OK;
  }

  return retVal;
} /* TcpIp_TlsClientMsg_CheckValidateCertificateStatusPrecondition() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_IssueCertRequestCallout
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
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_IssueCertRequestCallout(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* Availability of a client certificate */
  TcpIp_TlsClientCertInfoStatusType clientCertInfoStatus = TCPIP_TLS_CLIENT_CERT_INFO_STATUS_NOT_AVAILABLE;

  TcpIp_SizeOfSocketOwnerConfigType socketOwnerConfigIdx = TcpIp_GetSocketOwnerConfigIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_SizeOfSocketDynType socketIdx = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_TlsClientAuthenticationMgmtIdxOfTlsConnectionType tlsClientAuthenticationMgmtIdx
    = TcpIp_GetTlsClientAuthenticationMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx
    = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);
  TCPIP_P2C(TcpIp_TlsCertRequestInfoType) certRequestInfoPtr
    = TcpIp_GetAddrRequestInfoOfTlsClientAuthenticationMgmt(tlsClientAuthenticationMgmtIdx);
  TCPIP_P2V(TcpIp_TlsClientCertInfoType) clientAuthenticationInfoPtr
    = TcpIp_GetAddrClientCertInfoOfTlsClientAuthenticationMgmt(tlsClientAuthenticationMgmtIdx);
  TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx =
    TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));
  TcpIp_TlsCsmJobIterType signatureGenerateTlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
    TcpIp_GetCsmJobIdKeyExchangeSignatureGenerateIdxOfTlsHandshake(activeTlsHandshakeIdx));

  /* ----- Implementation ----------------------------------------------- */

  /* Reset the flag to send a client certificate verify message */
  TcpIp_SetSendCertificateVerifyOfTlsClientConnection(tlsClientConnectionIdx, FALSE);

  /* #10 Issue the client authentication callout if applicable. */
  if (   (tlsClientAuthenticationMgmtIdx != TCPIP_NO_TLSCLIENTAUTHENTICATIONMGMTIDXOFTLSCONNECTION)
      && (TcpIp_GetTlsCertRequestFuncPtrOfSocketOwnerConfig(socketOwnerConfigIdx) != NULL_PTR))
  {
    /* Pre-fill client certificate info structure. Set the certificate list length to the configured maximum. */
    clientAuthenticationInfoPtr->CertIdListLen = TCPIP_TLS_MAX_NUM_CERTS;

    /* #20 Issue the callout. */
    (void)TcpIp_GetTlsCertRequestFuncPtrOfSocketOwnerConfig(socketOwnerConfigIdx)(
      TCPIP_SOCKET_IDX_TO_ID(socketIdx),
      certRequestInfoPtr,
      clientAuthenticationInfoPtr,
      &clientCertInfoStatus);
  }
  else
  {
    /* Client authentication is not enabled for this connection. */
    /* clientCertInfoStatus already is initialized to TCPIP_TLS_CLIENT_CERT_INFO_STATUS_NOT_AVAILABLE */
  }

  /* #30 Proceed depending on the callout status. */
  switch (clientCertInfoStatus)
  {
    case TCPIP_TLS_CLIENT_CERT_INFO_STATUS_PENDING:
    {
      /* The result of the callout is pending. Do nothing, just wait. */
      break;
    }
    case TCPIP_TLS_CLIENT_CERT_INFO_STATUS_READY:
    {
      /* The callout succeeded, and the client cert chain is available. */

      boolean validAlgSelected = FALSE;  /* The socket owner selected a valid signature hash algorithm. */
      boolean validCertListLenSelected = FALSE;  /* The socket owner set a valid certificate list length. */

      /* #40 Check the client authentication info for plausibility. */

      /* Check selected signature algorithm to be one of the offered algorithms and to be supported */
      validAlgSelected = TcpIp_TlsClient_CheckSelectedSignAlg(TlsConIdx);

      /* Check selected certificate list length to be in a valid range. */
      {
        if (   (clientAuthenticationInfoPtr->CertIdListLen <= TCPIP_TLS_MAX_NUM_CERTS)
            && (clientAuthenticationInfoPtr->CertIdListLen != 0u))
        {
          /* Copy the private key from the selected client certificate chain to the key used for the handshake. */
          uint32 csmKeyId = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(signatureGenerateTlsCsmJobIdx);

          if (TCPIP_CSM_KeyElementCopy(clientAuthenticationInfoPtr->PrivKeyId, CRYPTO_KE_SIGNATURE_KEY, csmKeyId, CRYPTO_KE_SIGNATURE_KEY) == E_OK)
          {
            if (TCPIP_CSM_KeySetValid(csmKeyId) == E_OK)
            {
              validCertListLenSelected = TRUE;
            }
          }
        }
      }

      if ((validAlgSelected == TRUE) && (validCertListLenSelected == TRUE))
      {
        /* #50 Switch to next handshake state. */
        /* Client certificates are ready to send, so we also need to send a certificate verify message, later. */
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx,
          TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_PREPARE_FULL_MESSAGE);
        TcpIp_SetSendCertificateVerifyOfTlsClientConnection(tlsClientConnectionIdx, TRUE);
      }
      else
      {
        /* There is an issue with the selected signature algorithm or with the number of certificates. */
        /* Issue an alert (handshake failure) and cancel the handshake */
        TcpIp_TlsClientHsStm_HandleErrorDuringPreparation(TlsConIdx);
      }
      break;
    }
    case TCPIP_TLS_CLIENT_CERT_INFO_STATUS_NOT_AVAILABLE:
    {
      /* The callout succeeded, but no (matching) client cert chain is available. */
      /* Send an empty cert message. */
      clientAuthenticationInfoPtr->CertIdListLen = 0u;
      TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx,
        TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_PREPARE_EMPTY_MESSAGE);
      break;
    }
    default:  /* TCPIP_TLS_CLIENT_CERT_INFO_STATUS_ERROR */
    {
      /* Preparation failed. The socket owner can not process the cert request (e.g. erroneous parameters,
      internal error, ...). Issue an alert (internal error, different than in HandleErrorDuringPreparation) and cancel
      the handshake. */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
      TcpIp_TlsClientHsStm_HandleErrorDuringPreparation(TlsConIdx);
      break;
    }
  }
} /* TcpIp_TlsClient_IssueCertRequestCallout */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_ServerCertRequestMsgFindDistinguishedNameStarts
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClient_ServerCertRequestMsgFindDistinguishedNameStarts(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 DnListLength,
  TCPIP_P2C(uint8) DnListPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientAuthenticationMgmtIdxOfTlsConnectionType tlsClientAuthenticationMgmtIdx
    = TcpIp_GetTlsClientAuthenticationMgmtIdxOfTlsConnection(TlsConIdx);
  TCPIP_P2V(TcpIp_TlsCertRequestInfoType) certRequestInfoPtr
    = TcpIp_GetAddrRequestInfoOfTlsClientAuthenticationMgmt(tlsClientAuthenticationMgmtIdx);
  uint16 numDistNames = 0u;
  TCPIP_P2C(uint8) nextDnElementPtr = DnListPtr;
  uint16 remainingLen = DnListLength;
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Process the distinguished names in the list and fill the cert request info struct. */
  while ((remainingLen != 0u) && (retVal == E_OK))
  {
    /* #20 Check the remaining length and the name length. */
    if (remainingLen >= TCPIP_TLS_DIST_NAME_LENGTH_LEN)
    {
      /* Read the length of the next DN */
      uint16 dnLen = IpBase_GetUint16(nextDnElementPtr, 0u);

      if ((dnLen != 0u) && (dnLen <= (remainingLen - TCPIP_TLS_DIST_NAME_LENGTH_LEN)))
      {
        /* #30 Found a new DN, fill the DN info to the global structure if possible. */
        if (numDistNames < TCPIP_TLS_MAX_NUM_DN)
        {
          certRequestInfoPtr->DistinguishedNameListPtr[numDistNames].DnLen = dnLen;
          certRequestInfoPtr->DistinguishedNameListPtr[numDistNames].DnPtr = &nextDnElementPtr[TCPIP_TLS_DIST_NAME_LENGTH_LEN];

          numDistNames++;
        }
        else
        {
          /* All available struct elements are already filled, so skip adding this new one to the list. */
        }

        /* Prepare the next loop */
        remainingLen -= (dnLen + TCPIP_TLS_DIST_NAME_LENGTH_LEN);
        nextDnElementPtr = &nextDnElementPtr[dnLen + TCPIP_TLS_DIST_NAME_LENGTH_LEN];
      }
      else
      {
        /* Error, the dnLen has length 0, or the DN does not fit into the remaining length */
        retVal = E_NOT_OK;
      }
    }
    else
    {
      /* Error, the remaining length is too short for a length field */
      retVal = E_NOT_OK;
    }
  }

  certRequestInfoPtr->DistinguishedNamesNum = numDistNames;

  return retVal;
} /* TcpIp_TlsClient_ServerCertRequestMsgFindDistinguishedNameStarts */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_AddDhPubKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_AddDhPubKey(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TcpIp_TlsMsgHandshakeType     MessageType,
  TcpIp_TlsEllipticCurveIdType  CurveId)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Handles synchronous CSM call and trigger the calculation of the job in the async context handler */
  if (MessageType == TCPIP_TLS_HSTYPE_CLIENTKEYEXCHANGE)
  {
    TcpIp_SetDhPubKeyKeyExchangeAsyncFlagOfTlsConnectionDyn(TlsConIdx, TRUE);
  }
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  else if (MessageType == TCPIP_TLS_HSTYPE_CLIENTHELLO)
  {
    TcpIp_SetDhPubKeyKeyShareExtCurveAsyncTriggerOfTlsConnectionDyn(TlsConIdx, CurveId);
  }
#   endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
  else
  {
    TCPIP_ASSERT_UNREACHABLE();
  }

#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_OFF)
  TCPIP_DUMMY_STATEMENT_CONST(CurveId);                                                                                 /* PRQA S 1338, 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
#   endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_OFF) */

  /* Set the state to ASYNC_PENDING */
  TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_ASYNC_PENDING);

} /* TcpIp_TlsClientMsg_AddDhPubKey() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_CheckSelectedSignAlg
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsClient_CheckSelectedSignAlg(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientAuthenticationMgmtIdxOfTlsConnectionType tlsClientAuthenticationMgmtIdx
    = TcpIp_GetTlsClientAuthenticationMgmtIdxOfTlsConnection(TlsConIdx);
  TCPIP_P2C(TcpIp_TlsCertRequestInfoType) certRequestInfoPtr
    = TcpIp_GetAddrRequestInfoOfTlsClientAuthenticationMgmt(tlsClientAuthenticationMgmtIdx);
  TCPIP_P2C(TcpIp_TlsClientCertInfoType) clientAuthenticationInfoPtr
    = TcpIp_GetAddrClientCertInfoOfTlsClientAuthenticationMgmt(tlsClientAuthenticationMgmtIdx);
  TcpIp_SignatureAlgorithmIdType sigAndHashAlgSelected = clientAuthenticationInfoPtr->SignatureAndHashAlgo;
  uint16 algIter = 0u;
  boolean validAlgSelected = FALSE;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Iterate through all offered algorithms, and check if one of the offered algorithms was selected. */
  for (; algIter < certRequestInfoPtr->SignatureAndHashAlgoNum; algIter++)
  {
    uint16 sigAndHashAlgRawFromEcu =
      IpBase_GetUint16((TCPIP_P2C(uint8)) & (certRequestInfoPtr->SignatureAndHashAlgoListPtr[algIter]), 0u);
    TcpIp_SignatureAlgorithmIdType sigAndHashAlgFromEcu = (TcpIp_SignatureAlgorithmIdType)sigAndHashAlgRawFromEcu;      /* PRQA S 4342 */ /* MD_TcpIp_TlsCore_10.5_4342_a */

    if (sigAndHashAlgFromEcu == sigAndHashAlgSelected)
    {
      validAlgSelected = TRUE;
      break;
    }
  }

  /* #20 Check if the selected algorithm is supported by the ECU. */
  if (validAlgSelected == TRUE)
  {
    TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx =
      TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(
        TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));
    TcpIp_SignatureAlgorithmIdType signAlgOfConnection =
      TcpIp_GetSignatureAlgorithmIdOfTlsHandshake(activeTlsHandshakeIdx);

    if (sigAndHashAlgSelected != signAlgOfConnection)
    {
      /* An algorithm out of the list of algorithms in the cert request was selected, but the selected one does
      not match the one used for signing in the current handshake. */
      validAlgSelected = FALSE;
    }
  }

  return validAlgSelected;
}/* TcpIp_TlsClient_CheckSelectedSignAlg */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_CheckSignatureAlgorithmsLengthConstraints
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClient_CheckSignatureAlgorithmsLengthConstraints(
  uint16 SignatureAlgorithmsLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check that the length is even since the algorithm information is sent pairwise. */
  if ((SignatureAlgorithmsLength % TCPIP_TLS_SIGNATURE_ALGORITHMS_ALG_ID_LEN) != 0u)
  {
    retVal = E_NOT_OK;
  }

  /* #20 Check if received signature algorithm list is non-empty. */
  if (SignatureAlgorithmsLength < TCPIP_TLS_SIGNATURE_ALGORITHMS_ALG_ID_LEN)
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}/* TcpIp_TlsClient_CheckSignatureAlgorithmsLengthConstraints */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_SaveSignatureAlgorithmsInRequestInfoOfTlsClientAuthentication
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
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_SaveSignatureAlgorithmsInRequestInfoOfTlsClientAuthentication(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 SignatureAlgorithmsLength,
  TcpIp_ConstSegmentPtrType SignatureAlgorithmsSegmentPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_RequestInfoOfTlsClientAuthenticationMgmtPtrType certRequestInfoPtr =
    TcpIp_GetAddrRequestInfoOfTlsClientAuthenticationMgmt(
      TcpIp_GetTlsClientAuthenticationMgmtIdxOfTlsConnection(TlsConIdx));

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if certificate request info pointer is uninitialized */
  /* Note:
   * It may happen that the client is receiving both signature_algorithms
   * and signature_algorithms_cert extensions in TLS 1.3. Then, in case the
   * signature_algorithms_cert extension already filled this information,
   * it should not be overwritten as this extension shall be used during
   * client certificate selection done in upper layer.
   * certRequestInfoPtr->SignatureAndHashAlgoListPtr is initialized with a NULL_PTR in TcpIp_TlsCoreConnection_Init
   * and is reset to allow overwriting in
   * TcpIp_Tls13ClientHsStm_ParseCertificateRequestExtensionsSignatureAlgorithmsCert.
   * Therefore for TLS 1.2 certRequestInfoPtr->SignatureAndHashAlgoListPtr will always be NULL_PTR here. */
  if (certRequestInfoPtr->SignatureAndHashAlgoListPtr == NULL_PTR)
  {
    TcpIp_SegmentType tlsSigAlgServerCertReqMsgBuffer = { 0 };

    uint16 signatureAlgorithmsLengthConsidered = SignatureAlgorithmsLength;

    /* The generated certificate request buffer contains uint16 values.
     * To get its size in bytes it has to be multiplied by two (the length of a signature algorithm). */
    const TcpIp_SizeOfTlsSigAlgServerCertReqMsgBufferType sizeOfTlsSigAlgServerCertReqMsgBuffer = (
      TcpIp_GetTlsSigAlgServerCertReqMsgBufferEndIdxOfTlsConnection(TlsConIdx)
      - TcpIp_GetTlsSigAlgServerCertReqMsgBufferStartIdxOfTlsConnection(TlsConIdx)
      ) * TCPIP_TLS_SIGNATURE_ALGORITHMS_ALG_ID_LEN;

    TcpIp_SegmentInit(
      &tlsSigAlgServerCertReqMsgBuffer,
      (uint8*)TcpIp_GetAddrTlsSigAlgServerCertReqMsgBuffer(
        TcpIp_GetTlsSigAlgServerCertReqMsgBufferStartIdxOfTlsConnection(TlsConIdx)),
      sizeOfTlsSigAlgServerCertReqMsgBuffer);

    /* #20 Check if received signature algorithm list fits into buffer and ignore signature algorithms that do not fit */
    if (signatureAlgorithmsLengthConsidered > sizeOfTlsSigAlgServerCertReqMsgBuffer)
    {
      signatureAlgorithmsLengthConsidered = sizeOfTlsSigAlgServerCertReqMsgBuffer;
    }

    /* #30 Copy received signature algorithms into separate buffer to ensure correct alignment */
    TcpIp_SegmentMemCpyFromConstSegment(
      &tlsSigAlgServerCertReqMsgBuffer,
      SignatureAlgorithmsSegmentPtr,
      signatureAlgorithmsLengthConsidered);

    /* #40 Skip signature algorithms that have been ignored */
    const uint16 signatureAlgorithmsLengthIgnored = SignatureAlgorithmsLength - signatureAlgorithmsLengthConsidered;

    TcpIp_ConstSegmentCommit(
      SignatureAlgorithmsSegmentPtr,
      (uint32)signatureAlgorithmsLengthIgnored);

    /* #50 Save memory information of copied signature algorithms in RequestInfo */
    certRequestInfoPtr->SignatureAndHashAlgoListPtr =
      TcpIp_GetAddrTlsSigAlgServerCertReqMsgBuffer(
        TcpIp_GetTlsSigAlgServerCertReqMsgBufferStartIdxOfTlsConnection(TlsConIdx));

    /* #60 Transform number of bytes into number of signature algorithms */
    certRequestInfoPtr->SignatureAndHashAlgoNum =
      (uint16)(tlsSigAlgServerCertReqMsgBuffer.Usage / TCPIP_TLS_SIGNATURE_ALGORITHMS_ALG_ID_LEN);
  }
}/* TcpIp_TlsClient_SaveSignatureAlgorithmsInRequestInfoOfTlsClientAuthentication */
#  endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsClientHsStm_HandleErrorDuringPreparation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsClientHsStm_HandleErrorDuringPreparation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsUserErrorType        hsUserError;
  TcpIp_TlsAlertLevelType       alertLevel;
  TcpIp_TlsAlertDescriptionType alertDescription;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the corresponding error id and report the error to the user */
  hsUserError.FunctionId = TCPIP_TLS_FCTID_CLIENT_HSSTM_PREPARE_HS_MSG;
  hsUserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_INCORRECTHSMSG;
  hsUserError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

  TcpIp_TlsCoreError_ReportUserError(hsUserError);

  /* #20 Set the corresponding alert level and description and trigger the transmission of the occurred alert */
  alertLevel       = TCPIP_TLS_ALERT_LEVEL_FATAL;
  alertDescription = TCPIP_TLS_ALERT_DESC_HANDSHAKE_FAILURE;

  TcpIp_TlsCoreAlert_Set(TlsConIdx, alertLevel, alertDescription);

  /* Change the state to HANDSHAKE_ABORT */
  TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_ABORT);

} /* TcpIp_TlsClientHsStm_HandleErrorDuringPreparation() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ClientHelloAddCompressionMethod
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ClientHelloAddCompressionMethod(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Add compression method length (1 Byte) to TLS TxBuffer */
  IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)),
                  0, TCPIP_TLSCLIENT_COMPMETHLEN_LEN);

  /* Increment the write index by the consumed length (1 Byte) */
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLSCLIENT_COMPMETHLEN_LEN);

  /* #20 The only supported compression method is "no_compression". Add compression method ('0' = no_compression) to TLS TxBuffer */
  IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)),
                  0, TCPIP_TLS_COMPRESSION_METHOD_NONE);

  /* Increment the write index by the consumed length (1 Byte) */
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLSCLIENT_COMPMETH_LEN);

} /* TcpIp_TlsClientMsg_ClientHelloAddCompressionMethod() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ClientHelloExtGetSupportedGroups
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(TcpIp_TlsEllipticCurveIdType, TCPIP_CODE) TcpIp_TlsClientMsg_ClientHelloExtGetSupportedGroups(
  TcpIp_TlsConnectionIterType             TlsConIdx,
  TCPIP_P2V(TcpIp_TlsEllipticCurveIdType) SupportedGroupsPtr,
  TcpIp_TlsEllipticCurveIdType            SupportedGroupsLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsEllipticCurveIdType supportedGroupsCount = 0;

  TcpIp_TlsCipherWorkingSetMgmtIdxOfTlsConnectionType tlsCipherWorkingSetMgmtIdx
    = TcpIp_GetTlsCipherWorkingSetMgmtIdxOfTlsConnection(TlsConIdx);

  TCPIP_P2C(TcpIp_TlsSignatureAlgorithmWorkingSetType) workingSetPtr =
    TcpIp_GetAddrSignatureAlgorithmWorkingSetOfTlsCipherWorkingSetMgmt(tlsCipherWorkingSetMgmtIdx);

  uint8 iterIdx = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* This function should be called by the key_share extension and the supported_groups extension
   * to ensure the same order in these extensions. */
  TCPIP_ASSERT(workingSetPtr->workingSetLen <= SupportedGroupsLen);
  for (iterIdx = 0; iterIdx < workingSetPtr->workingSetLen; iterIdx++)
  {
    boolean ellipticCurveMatchingSigAlgFound = FALSE;
    /* Index must not exceed the supported groups length */
    if (iterIdx < SupportedGroupsLen)
    {
      TcpIp_TlsCipherWorkerIndIterType tlsCipherWorkerIndIdx;
      /* #10 Iterate over all configured CipherWorker for this TLS connection */
      for (tlsCipherWorkerIndIdx = TcpIp_GetTlsCipherWorkerIndStartIdxOfTlsConnection(TlsConIdx);
           tlsCipherWorkerIndIdx < TcpIp_GetTlsCipherWorkerIndEndIdxOfTlsConnection(TlsConIdx);
           tlsCipherWorkerIndIdx++)
      {
        TcpIp_TlsCipherWorkerIterType tlsCipherWorkerIdx = TcpIp_GetTlsCipherWorkerInd(tlsCipherWorkerIndIdx);
        TcpIp_TlsHandshakeIndStartIdxOfTlsCipherWorkerType handshakeStartIdx
          = TcpIp_GetTlsHandshakeIndStartIdxOfTlsCipherWorker(tlsCipherWorkerIdx);
        TcpIp_TlsHandshakeIndEndIdxOfTlsCipherWorkerType handshakeEndIdx
          = TcpIp_GetTlsHandshakeIndEndIdxOfTlsCipherWorker(tlsCipherWorkerIdx);
        TcpIp_TlsHandshakeIndIterType tlsHandshakeIndIdx;

        /* #20 Iterate over all configured handshake for this CipherWorker */
        for (tlsHandshakeIndIdx = handshakeStartIdx; tlsHandshakeIndIdx < handshakeEndIdx; tlsHandshakeIndIdx++)
        {
          /* #30 Get the configured elliptic curve Id */
          TcpIp_TlsHandshakeIterType tlsHandshakeIdx = TcpIp_GetTlsHandshakeInd(tlsHandshakeIndIdx);
          TcpIp_TlsEllipticCurveIdType currentEllipticCurveId = TcpIp_GetEllipticCurveIdOfTlsHandshake(tlsHandshakeIdx);
          /* If the handshake is configured as PSK (curveId set to TCPIP_CURVE_ID_NO_CURVE) we should not add it */
          if (currentEllipticCurveId != TCPIP_CURVE_ID_NO_CURVE)
          {
            TcpIp_SignatureAlgorithmIdType currentSignAlgoId
              = TcpIp_GetSignatureAlgorithmIdOfTlsHandshake(tlsHandshakeIdx);
            /* Check if the configured signature algorithm matches with the current one from the working set. */
            if ((uint16)currentSignAlgoId == workingSetPtr->workingSet[iterIdx])
            {
              /* Set the supported group at the same position as the corresponding signature algorithm.
               * This can be done because every handshake element has exactly one signature algorithm
               * and a corresponding group assigned. */
              SupportedGroupsPtr[iterIdx] = currentEllipticCurveId;
              supportedGroupsCount++;
              ellipticCurveMatchingSigAlgFound = TRUE;
              break;
            }
          }
        }

        if (ellipticCurveMatchingSigAlgFound == TRUE)
        {
          break;
        }
      }

      if (ellipticCurveMatchingSigAlgFound == FALSE)
      {
        SupportedGroupsPtr[iterIdx] = TCPIP_CURVE_ID_NO_CURVE;
      }
    }
    else
    {
      break;
    }
  }

  return supportedGroupsCount;
} /* TcpIp_TlsClientMsg_ClientHelloExtGetSupportedGroups() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ClientHelloExtAddSupportedGroups
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ClientHelloExtAddSupportedGroups(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsEllipticCurveIdType iterIndex;
  TcpIp_SizeOfTlsBufferMgmtType    tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* Extension index information */
  /* Supported Group Extension Format
   *       [ext Type][ext Len][supported Group Len][group 1]            [group n]
   * Byte: 0       1 2      3 4                  5 6      7             (x-1)  x
   *                                                \---consumedExtensionLen---/
  */
  TcpIp_TlsBufferTxIterType extTypeTlsBufferTxIdx               = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_TlsBufferTxIterType extLenTlsBufferTxIdx                = extTypeTlsBufferTxIdx + TCPIP_TLS_EXTENSION_TYPE_LEN;
  TcpIp_TlsBufferTxIterType extSupportedGroupsLenIdx = extLenTlsBufferTxIdx + TCPIP_TLS_EXTENSION_LENGTH_LEN;
  TcpIp_TlsBufferTxIterType extGroupStartIdx         = extSupportedGroupsLenIdx + TCPIP_TLS_EXTENSION_SUPPORTED_GROUP_LENGTH_LEN;

  uint16 consumedExtensionLen = 0u;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Get supported groups in the current connection */
  TcpIp_TlsEllipticCurveIdType supportedGroups[TCPIP_CURVE_ID_AMOUNT];

  /* TcpIp_TlsClientMsg_ClientHelloExtGetSupportedGroups() is called to get the supported groups.
   * This function is also called in the key_share extension,
   * to ensure the order of the groups in both extension are the same (see RFC8446 chapter 4.2.8.).
   * It might return an empty array. */
  TcpIp_TlsEllipticCurveIdType supportedGroupsCount = TcpIp_TlsClientMsg_ClientHelloExtGetSupportedGroups(TlsConIdx, &supportedGroups[0], TCPIP_CURVE_ID_AMOUNT);

  if (supportedGroupsCount < TCPIP_CURVE_ID_AMOUNT)
  {
    /* #20 Iterate through every supported group and add it to the extension */
    for (iterIndex = 0; iterIndex < supportedGroupsCount; iterIndex++)
    {
      /* Add the extension value */
      TcpIp_TlsMsg_AddUint16ValueToDistinctListInTxBuffer(TlsConIdx, supportedGroups[iterIndex],
        extGroupStartIdx, &consumedExtensionLen);
    }

    /* #30 Check if there are extensions added and update the length information in the TLS TxBuffer */
    if (consumedExtensionLen != 0u)
    {
      /* #40 Set the extension type to TCPIP_TLS_EXTENSION_SUPPORTED_GROUPS (0x00au) */
      IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extTypeTlsBufferTxIdx), 0, TCPIP_TLS_EXTENSION_SUPPORTED_GROUPS);
      TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_TYPE_LEN);

      /* #50 Set extension supported group length */
      IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extSupportedGroupsLenIdx), 0, consumedExtensionLen);                 /* TCPIP_CSL_NAME_LENGTH */
      TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_SUPPORTED_GROUP_LENGTH_LEN);

      /* #60 Set extension length */
      IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extLenTlsBufferTxIdx), 0, consumedExtensionLen + TCPIP_TLS_EXTENSION_SUPPORTED_GROUP_LENGTH_LEN);
      TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_LENGTH_LEN);
    }
  }
#  if (TCPIP_DEV_ERROR_REPORT == STD_ON)
  else
  {
    /* Should never happen. TCPIP_CURVE_ID_AMOUNT probably needs to be adapted. */
    /* Report a DET error if configured. */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
  }
#  endif
} /* TcpIp_TlsClientMsg_ClientHelloExtAddSupportedGroups() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ClientHelloExtAddSignatureAlgorithms
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ClientHelloExtAddSignatureAlgorithms(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerIndIterType signAlgoIter;
  TcpIp_TlsBufferMgmtIterType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsCipherWorkingSetMgmtIdxOfTlsConnectionType tlsCipherWorkingSetMgmtIdx
    = TcpIp_GetTlsCipherWorkingSetMgmtIdxOfTlsConnection(TlsConIdx);
  TCPIP_P2C(TcpIp_TlsSignatureAlgorithmWorkingSetType) signAlgoPtr
    = TcpIp_GetAddrSignatureAlgorithmWorkingSetOfTlsCipherWorkingSetMgmt(tlsCipherWorkingSetMgmtIdx);

  /* Extension index information */
  /* Supported Signature Algorithm Extension Format
   *       [ext Type][ext Len][Signature Algorithm Len][algorithm 1]    [algorithm n]
   * Byte: 0       1 2      3 4                      5 6          7     (x-1)      x
   *                                                    \---consumedExtensionLen---/
  */
  TcpIp_TlsBufferTxIterType extTypeTlsBufferTxIdx        = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(
                                                            tlsBufferMgmtIdx);
  TcpIp_TlsBufferTxIterType extLenTlsBufferTxIdx         = extTypeTlsBufferTxIdx + TCPIP_TLS_EXTENSION_TYPE_LEN;
  TcpIp_TlsBufferTxIterType extSignAlgoLenTlsBufferTxIdx = extLenTlsBufferTxIdx + TCPIP_TLS_EXTENSION_LENGTH_LEN;
  TcpIp_TlsBufferTxIterType extAlgorithmsStartIdx        = extSignAlgoLenTlsBufferTxIdx
                                                            + TCPIP_TLS_SIGNATURE_ALGORITHMS_LENGTH_LEN;

  uint16 consumedExtensionLen = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* Set the start index of the Signature Algorithms extension for later purpose (e.g. CertificateVerify Msg). */
  TcpIp_SetTlsBufferTxClientSignatureAlgorithmsExtensionIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    (TcpIp_TlsBufferTxClientSignatureAlgorithmsExtensionIdxOfTlsClientBufferMgmtType) extSignAlgoLenTlsBufferTxIdx);

  /* #10 Write all available signature algorithms in the TLS TxBuffer */
  /* Iterate over Signature Algorithm working set of current connection */
  for (signAlgoIter = 0; signAlgoIter < signAlgoPtr->workingSetLen; signAlgoIter++)
  {
    /* Add the extension value considering duplicate value entries */
    TcpIp_TlsMsg_AddUint16ValueToDistinctListInTxBuffer(TlsConIdx, (uint16)signAlgoPtr->workingSet[signAlgoIter],
      extAlgorithmsStartIdx, &consumedExtensionLen);
  }

  /* #20 Check if there are extensions added and update the length information in the TLS TxBuffer */
  if (consumedExtensionLen != 0u)
  {
    /* #30 Set the extension type to TCPIP_TLS_EXTENSION_SIGNATURE_ALGORITHMS (0x000d) */
    IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extTypeTlsBufferTxIdx), 0, TCPIP_TLS_EXTENSION_SIGNATURE_ALGORITHMS);
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_TYPE_LEN);

    /* #40 Set extension signature algorithms length */
    IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extSignAlgoLenTlsBufferTxIdx), 0, consumedExtensionLen);
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
      TCPIP_TLS_SIGNATURE_ALGORITHMS_LENGTH_LEN);

    /* #50 Set extension length */
    IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extLenTlsBufferTxIdx), 0,
      consumedExtensionLen + TCPIP_TLS_SIGNATURE_ALGORITHMS_LENGTH_LEN);
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_LENGTH_LEN);
  }
} /* TcpIp_TlsClientMsg_ClientHelloExtAddSignatureAlgorithms() */

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ClientExtAddTrustedCAIndication
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ClientExtAddTrustedCAIndication(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType    tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* Trusted CA Extension Format
   *                      +--> consumed Extension Length
   *                     /         +--> Trusted Authorities List Start Index
   *                    /         /      /--------Trusted Authorities List Length -------\
   *       [ext Type][ext Len][List Len][ID Type_1][SHA-1 Hash_1][ID Type_2][SHA-1 Hash_2] ...
   * Byte: 0       1 2      3 4       5          6  7         27                         /
   *                          \-----------------consumedExtensionLen--------------------/
   */

  TcpIp_TlsBufferTxIterType extTypeTlsBufferTxIdx = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_TlsBufferTxIterType extLenTlsBufferTxIdx  = extTypeTlsBufferTxIdx + TCPIP_TLS_EXTENSION_TYPE_LEN;
  uint16 consumedExtensionLen          = 0u;

  TcpIp_TlsBufferTxIterType extTrustedAuthoritiesListStartIdx = extLenTlsBufferTxIdx + TCPIP_TLS_EXTENSION_LENGTH_LEN;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Only add this specific extension if one of the referenced cipher worker is configured as ECC cipher worker */
  if (TcpIp_TlsCoreUtil_ConnectionUseEccCipherSuite(TlsConIdx) == TRUE)
  {
    /* #20 Check if the extension is enabled on this TLS connection */
    if (TcpIp_IsTlsUseExtensionTrustedCaIndicationOfTlsConnection(TlsConIdx) == TRUE)
    {
      /* #30 Add the list of all trusted Certificate Authorities (CAs) */
      if (TcpIp_TlsClientMsg_ClientExtAddTrustedAuthoritiesList(TlsConIdx, extTrustedAuthoritiesListStartIdx,
            &consumedExtensionLen) == E_OK)
      {
        /* #40 Extension trusted CA indication added - update overall extension information */
        /* Increment the write index by the consumed extension length */
        TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, consumedExtensionLen);

        /* Set the extension type to TCPIP_TLS_EXTENSION_TRUSTED_CA_INDICATION (0x0003) */
        IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extTypeTlsBufferTxIdx), 0, TCPIP_TLS_EXTENSION_TRUSTED_CA_INDICATION);
        TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_TYPE_LEN);

        /* Set overall extension length */
        IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extLenTlsBufferTxIdx), 0, consumedExtensionLen);
        TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_LENGTH_LEN);
      }
      /* else - no need to trigger alert if something is wrong with the hash calculation. Continue with the TLS handshake */
    }
    /* else - Feature not enabled, nothing to do. */
  }
} /* TcpIp_TlsClientMsg_ClientExtAddTrustedCAIndication() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ClientExtAddTrustedAuthoritiesList
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050, 6080 1 */ /* MD_TcpIp_STCAL_CslAccess, MD_MSR_STMIF */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ClientExtAddTrustedAuthoritiesList(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferTxIterType TrustedAuthorityListStartIdx,
  TCPIP_P2V(uint16) ConsumedLenPtr)
{
  /* RFC6066 - 6. Trusted CA Indication */
  /*
   *   struct {
   *       TrustedAuthority trusted_authorities_list<0..2^16-1>;
   *   } TrustedAuthorities;
   *
   *   struct {
   *         IdentifierType identifier_type;
   *         select (identifier_type) {
   *             case key_sha1_hash: SHA1Hash;
   *             case cert_sha1_hash: SHA1Hash;
   *         } identifier;
   *     } TrustedAuthority;
   *
   *   enum {
   *          pre_agreed(0), key_sha1_hash(1), x509_name(2),
   *          cert_sha1_hash(3), (255)
   *      } IdentifierType;
   *
   *  Currently key_sha1_hash(1) and cert_sha1_hash(3) are supported.
   */

  /* ----- Local Variables----------------------------------------------- */
  KeyM_CertificateStatusType currentCertificateStatus;

  TcpIp_TlsCertIdIssuerStartIdxOfTlsConnectionType issuerTlsCertIdIdx;
  TcpIp_TlsBufferTxIterType trustedAuthoritiesListLengthIdx = TrustedAuthorityListStartIdx;

  TcpIp_TlsBufferTxIterType trustedAuthoritiesListIter
    = trustedAuthoritiesListLengthIdx + TCPIP_TLS_EXTENSION_TRUSTED_CA_INDICATION_LIST_LEN;

  TcpIp_SignatureAlgorithmIdType signAlgId = TCPIP_SIG_ALGO_ID_NONE;

  Std_ReturnType retVal = E_NOT_OK;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 iterate over all referenced issuer certificates of this TLS connection (root certificates) */
  for (issuerTlsCertIdIdx = TcpIp_GetTlsCertIdIssuerStartIdxOfTlsConnection(TlsConIdx);
       issuerTlsCertIdIdx < TcpIp_GetTlsCertIdIssuerEndIdxOfTlsConnection(TlsConIdx);
       issuerTlsCertIdIdx++)
  {
    KeyM_CertificateIdType certId = TcpIp_GetTlsCertId(issuerTlsCertIdIdx);

    if (TcpIp_TlsCoreUtil_ReadCertSignatureAlgorithm(certId, &signAlgId) == E_OK)
    {
      /* Only check if signature algorithm is contained in working set if callout is configured */
      if (   (TcpIp_IsTlsUseChangeableCipherCallbackOfTlsConnection(TlsConIdx) == FALSE)
          || (TcpIp_TlsClient_IsSignatureAlgorithmInWorkingSet(TlsConIdx, signAlgId) == TRUE))                          /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
      {
        /* #20 Check the status of the current selected certificate */
        if (KeyM_CertGetStatus(certId, &currentCertificateStatus) == E_OK)
        {
          if (   (currentCertificateStatus == KEYM_CERTIFICATE_PARSED_NOT_VALIDATED)
              || (currentCertificateStatus == KEYM_CERTIFICATE_VALID))
          {
            /* #30 In case of an valid certificate status, try to add the SHA1 hash to the TlsTxBuffer for this certificate */
            /* Add the CertSha1Hash, if configured in the certificate. */
            boolean certSha1HashAdded
              = TcpIp_TlsClientMsg_ClientExtAddCertSha1Hash(certId, &trustedAuthoritiesListIter);
            /* Add the KeySha1Hash, if configured in the certificate. */
            boolean keySha1HashAdded
              = TcpIp_TlsClientMsg_ClientExtAddKeySha1Hash(certId, &trustedAuthoritiesListIter);

            /* Check if at least one of the hashes was added, so that the extension is not empty.
             * Adding both hashes is also a valid case.*/
            if (   (certSha1HashAdded == TRUE)
                || (keySha1HashAdded == TRUE))
            {
              retVal = E_OK;
            }

            /* If both hashes could not be added (either not found by KeyM or invalid),
             * just continue iterating over the certificates and leave retVal as it is.
             * If for all certificates no hash was added the retVal stays E_NOT_OK
             * the upper hierarchical function will not send this extension. */
          }
          /* else - No need to cancel TLS handshake in case of invalid certificate status */
        }
      }
      /* else - Do not add CA of this certificate to trusted_ca extension */
    }
  }

  /* At least one hash added - update overall length information */
  if (retVal == E_OK)
  {
    uint16 consumedTrustedAuthoritiesListLength
      = (uint16)(trustedAuthoritiesListIter - (trustedAuthoritiesListLengthIdx + TCPIP_TLS_EXTENSION_TRUSTED_CA_INDICATION_LIST_LEN));

    /* Write the Trusted Authorities List Length */
    IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(trustedAuthoritiesListLengthIdx), 0,                                    /* TCPIP_CSL_NAME_LENGTH */
      consumedTrustedAuthoritiesListLength);

    /* Set the consumed overall length */
    *ConsumedLenPtr = (consumedTrustedAuthoritiesListLength + TCPIP_TLS_EXTENSION_TRUSTED_CA_INDICATION_LIST_LEN);
  }

  return retVal;
} /* TcpIp_TlsClientMsg_ClientExtAddTrustedAuthoritiesList() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ClientExtAddCertSha1Hash
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsClientMsg_ClientExtAddCertSha1Hash(
  KeyM_CertificateIdType               CertId,
  TCPIP_P2V(TcpIp_TlsBufferTxIterType) TrustedAuthoritiesListIterPtr)
{
   /* ----- Local Variables----------------------------------------------- */
  boolean hashAdded = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  uint8 tmpSha1Hash[TCPIP_TLS_HASH_SHA1_LEN];
  uint32 tmpSha1HashLen = TCPIP_TLS_HASH_SHA1_LEN;
  /* #10 Try to get the calculated SHA1 hash for the certificate */
  if (KeyM_GetCertHash(CertId, &tmpSha1Hash[0], &tmpSha1HashLen) == E_OK)
  {
    if (tmpSha1HashLen == TCPIP_TLS_HASH_SHA1_LEN)
    {
      /* #20 SHA1 hash for the certificate is valid, add the hash to the TlsTxBuffer */
      /* Format of each trusted authority element: [IdentifierType][cert_sha1_hash] */

      /* Write the identifier type: cert_sha1_hash(3) to the TlsTxBuffer */
      IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(*TrustedAuthoritiesListIterPtr), 0,
        TCPIP_TLS_EXTENSION_TRUSTED_CA_INDICATION_TYPE_CERT_SHA1_HASH);
      (*TrustedAuthoritiesListIterPtr)++;

      /* Write the calculated SHA1 hash to the TlsTxBuffer */
      VStdMemCpy(TcpIp_GetAddrTlsBufferTx(*TrustedAuthoritiesListIterPtr), &tmpSha1Hash[0], TCPIP_TLS_HASH_SHA1_LEN);   /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      *TrustedAuthoritiesListIterPtr += TCPIP_TLS_HASH_SHA1_LEN;

      hashAdded = TRUE;
    }
    /* #30 else - SHA1 hash for the certificate is invalid, do not add this to the extension */
  }
  /* else - No need to skip further processing in case of E_NOT_OK from KeyM, try if another hash can be added */

  return hashAdded;
} /* TcpIp_TlsClientMsg_ClientExtAddCertSha1Hash() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ClientExtAddKeySha1Hash
 *********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
 *
 *
  */
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsClientMsg_ClientExtAddKeySha1Hash(
  KeyM_CertificateIdType               CertId,
  TCPIP_P2V(TcpIp_TlsBufferTxIterType) TrustedAuthoritiesListIterPtr)
{
  /* ----- Local Variables----------------------------------------------- */
  boolean hashAdded = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  uint8 tmpSha1Hash[TCPIP_TLS_HASH_SHA1_LEN];
  uint32 tmpSha1HashLen = TCPIP_TLS_HASH_SHA1_LEN;
  /* #10 Try to get the calculated SHA1 hash for the public key of the certificate */
  if (KeyM_GetPubKeyHash(CertId, &tmpSha1Hash[0], &tmpSha1HashLen) == E_OK)
  {
    if (tmpSha1HashLen == TCPIP_TLS_HASH_SHA1_LEN)
    {
      /* #20 SHA1 hash for the key is valid, add the hash to the TlsTxBuffer */
      /* Format of each trusted authority element: [IdentifierType][key_sha1_hash] */

      /* Write the identifier type: key_sha1_hash(1) to the TlsTxBuffer */
      IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(*TrustedAuthoritiesListIterPtr), 0,
        TCPIP_TLS_EXTENSION_TRUSTED_CA_INDICATION_TYPE_KEY_SHA1_HASH);
      (*TrustedAuthoritiesListIterPtr)++;

      /* Write the calculated SHA1 hash to the TlsTxBuffer */
      VStdMemCpy(TcpIp_GetAddrTlsBufferTx(*TrustedAuthoritiesListIterPtr), &tmpSha1Hash[0], TCPIP_TLS_HASH_SHA1_LEN);   /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      *TrustedAuthoritiesListIterPtr += TCPIP_TLS_HASH_SHA1_LEN;

      hashAdded = TRUE;
    }
    /* #30 else - SHA1 hash for the key is invalid, do not add this to the extension */
  }
  /* else - No need to skip further processing in case of E_NOT_OK from KeyM, try if another hash can be added */

  return hashAdded;
} /* TcpIp_TlsClientMsg_ClientExtAddKeySha1Hash() */
#   endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ClientExtAddCertificateStatusRequest
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
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ClientExtAddCertificateStatusRequest(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType    tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* Certificate Status request Extension Format
   *                                                                                 +-> list of OCSP responders that the client trusts (optional)
   *                      +--> consumed Extension Length                             /              +->  Length of request_extensions list
   *                     /         +--> Certificate status request type             /              /                       +-> OCSP request extensions (optional)
   *                    /         /                     +-> Responder list Length  /              /                       /
   *                   /         /                     /                          /              /                       /
   *       [ext Type][ext Len][CertStatusType][responder_id_list Len][responder_id 1]... [request_extensions Len] [request_extensions 1]...
   * Byte: 0       1 2      3               4 5                    6  7                   7                                            /
   *                          \---------------------------consumedExtensionLen--------------------------------------------------------/
   */

  TcpIp_TlsBufferTxIterType extTypeTlsBufferTxIdx = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_TlsBufferTxIterType extLenTlsBufferTxIdx = extTypeTlsBufferTxIdx + TCPIP_TLS_EXTENSION_TYPE_LEN;
  uint16 consumedExtensionLen = 0u;

  TcpIp_TlsBufferTxIterType extCertStatusRequestStartTlsBufferTxIdx = extLenTlsBufferTxIdx + TCPIP_TLS_EXTENSION_LENGTH_LEN;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Only add this specific extension if one of the referenced cipher worker is configured as ECC cipher worker */
  if (TcpIp_TlsCoreUtil_ConnectionUseEccCipherSuite(TlsConIdx) == TRUE)
  {
    /* #20 Check if the extension is enabled on this TLS connection */
    if (TcpIp_IsTlsUseExtensionCertificateStatusRequestOfTlsConnection(TlsConIdx) == TRUE)
    {
      TcpIp_TlsCertValidationStatusDynIterType curTlsCertValidationStatusIdx = 0u;

      /* RFC6066 - 8.  Certificate Status Request
       * Format of CertificateStatusType:
       * enum { ocsp(1), (255) } CertificateStatusType;
       */
      /* #30 Update CertificateStatusType with type OCSP */
      IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(extCertStatusRequestStartTlsBufferTxIdx), 0,
        TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_OCSP_TYPE);
      extCertStatusRequestStartTlsBufferTxIdx += TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_TYPE_LEN;
      consumedExtensionLen += TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_TYPE_LEN;

      /* RFC6066 - 8.  Certificate Status Request
       *   A zero-length "responder_id_list" sequence has the special meaning that the responders are implicitly known to the server.
       */
      /* #40 Update responder_id_list Len with 0 */
      IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extCertStatusRequestStartTlsBufferTxIdx), 0, 0);
      extCertStatusRequestStartTlsBufferTxIdx += TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_RESPONDER_ID_LIST_LEN;
      consumedExtensionLen += TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_RESPONDER_ID_LIST_LEN;

      /* RFC6066 - 8.  Certificate Status Request
       *   A zero-length "request_extensions" value means that there are no extensions.
       */
      /* #50 Update request_extensions Len with 0 */
      IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extCertStatusRequestStartTlsBufferTxIdx), 0, 0);
      consumedExtensionLen += TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_REQUEST_EXTENSIONS_LEN;

      /* #60 Extension Certificate Status Request - update overall extension information */
      /* Increment the write index by the consumed extension length */
      TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, consumedExtensionLen);

      /* Set the extension type to TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST (0x0005) */
      IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extTypeTlsBufferTxIdx), 0, TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST);
      TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_TYPE_LEN);

      /* Set overall extension length */
      IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extLenTlsBufferTxIdx), 0, consumedExtensionLen);
      TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_LENGTH_LEN);

      /* #70 Update mandatory extension information */
      /* This extensions is mandatory if it is enabled. Used later to check if we receive the extension from the Server. */
      /* Check if we received the extension from the server is done in TcpIp_TlsClientMsg_ServerMsgParseReceivedExtensions
       * Check if we should cancel the handshake is done in ServerHelloDone */
      TcpIp_SetMandatoryReceivedCertificateStatusRequestExtensionOfTlsConnectionDyn(TlsConIdx, TRUE);

      /* First set all available status info to requested. There is a difference beteween
       * Tls 1.2 and 1.3. This difference is handled in TcpIp_TlsClientMsg_ServerHelloUpdateOCSPInfo
       * after it is known which version is selected by the server. */
      for ( curTlsCertValidationStatusIdx = TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx);
            curTlsCertValidationStatusIdx < (TcpIp_TlsCertValidationStatusDynIterType)TcpIp_GetTlsCertValidationStatusDynEndIdxOfTlsConnection(TlsConIdx);
            curTlsCertValidationStatusIdx++)
      {
        TcpIp_GetAddrTlsCertValidationStatusDyn(curTlsCertValidationStatusIdx)
          ->CertStatusResponse.OcspConnectionState = TCPIP_TLS_OCSP_CONNECTION_STATE_REQUESTED;
      }
    }
    /* else - Feature not enabled, nothing to do. */
  }
} /* TcpIp_TlsClientMsg_ClientExtAddCertificateStatusRequest() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ClientExtAddServerNameIndication
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ClientExtAddServerNameIndication(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* Server Name Indication Extension Format
   *                                                                     +--> length of the host name
   *                      +--> consumed Extension Length                 /
   *                     /         +--> Length of the server name list  /
   *                    /         /                     +--> name type /
   *                   /         /                     /              /
   *       [ext Type][ext Len][server_name_list Len][name_type][host_name Len][host_name]
   * Byte: 0       1 2      3  4                  5    6        7           8  9       n  /
   *                          \---------------------------consumedExtensionLen-----------/
   */

  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferTxIterType extTypeTlsBufferTxIdx = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_TlsBufferTxIterType extLenTlsBufferTxIdx = extTypeTlsBufferTxIdx + TCPIP_TLS_EXTENSION_TYPE_LEN;
  TcpIp_TlsBufferTxIterType extServerNameListStartIdx = extLenTlsBufferTxIdx + TCPIP_TLS_EXTENSION_LENGTH_LEN;

  uint16 consumedExtensionLen = 0u;

  /* ----- Implementation ----------------------------------------------- */

    /* #10 Add the configured server name. */
  if (TcpIp_TlsClientMsg_ClientExtAddServerNames(TlsConIdx, extServerNameListStartIdx,
    &consumedExtensionLen) == E_OK)
  {
    /* #20 Extension Server Name Indication - update overall extension information */
    /* Increment the write index by the consumed extension length */
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, consumedExtensionLen);

    /* Set the extension type to TCPIP_TLS_EXTENSION_SERVER_NAME_INDICATION (0x0000) */
    IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extTypeTlsBufferTxIdx), 0, TCPIP_TLS_EXTENSION_SERVER_NAME_INDICATION);
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_TYPE_LEN);

    /* Set overall extension length */
    IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extLenTlsBufferTxIdx), 0, consumedExtensionLen);
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_LENGTH_LEN);

  } /* else - no server name configured, nothing to do. */

} /* TcpIp_TlsClientMsg_ClientExtAddServerNameIndication() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ClientExtAddServerNames
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ClientExtAddServerNames(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferTxIterType ServerNameListStartIdx,
  TCPIP_P2V(uint16) ConsumedLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  TcpIp_TlsBufferTxIterType serverNameListStartIdx = ServerNameListStartIdx;

  TcpIp_TlsServerNameIndicationStartIdxOfTlsConnectionType startTlsServerNameIndicationIdx
    = TcpIp_GetTlsServerNameIndicationStartIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsServerNameIndicationLengthOfTlsConnectionType serverNameLen
  = TcpIp_GetTlsServerNameIndicationLengthOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Only add this specific extension if a server name is configured. */
  if (serverNameLen != 0u)
  {
    TcpIp_TlsBufferTxIterType serverNameTypeTlsBufferTxIdx
      = serverNameListStartIdx + TCPIP_TLS_EXTENSION_SERVER_NAME_LIST_LENGTH_LEN;
    TcpIp_TlsBufferTxIterType nameLenTlsBufferTxIdx
      = serverNameTypeTlsBufferTxIdx + TCPIP_TLS_EXTENSION_SERVER_NAME_NAME_TYPE_LEN;
    TcpIp_TlsBufferTxIterType nameTlsBufferTxIdx
      = nameLenTlsBufferTxIdx + TCPIP_TLS_EXTENSION_SERVER_NAME_NAME_LEN_LEN;
    uint16 serverNameListLen = 0u;

    /* #20 Update the server name */
    /*        RFC6066 - 3.  Server Name Indication
     *        Format of HostName:
     *        "HostName" contains the fully qualified DNS hostname of the server,
     *        as understood by the client.  The hostname is represented as a byte
     *        string using ASCII encoding without a trailing dot. */
    VStdMemCpy(TcpIp_GetAddrTlsBufferTx(nameTlsBufferTxIdx), TcpIp_GetAddrTlsServerNameIndication(startTlsServerNameIndicationIdx), serverNameLen); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    serverNameListLen = serverNameLen;

    /* #30 Update the length of the server name. */
    IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(nameLenTlsBufferTxIdx), 0, serverNameListLen);
    serverNameListLen += TCPIP_TLS_EXTENSION_SERVER_NAME_NAME_LEN_LEN;

    /* #40 Update the type of the server name. */
    /*        RFC6066 - 3.  Server Name Indication
     *        Format of NameType:
     *        enum { host_name(0), (255) } NameType; */
    IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(serverNameTypeTlsBufferTxIdx), 0,
      TCPIP_TLS_EXTENSION_SERVER_NAME_TYPE_HOST_NAME);
    serverNameListLen += TCPIP_TLS_EXTENSION_SERVER_NAME_NAME_TYPE_LEN;

    /* #50 Update the length of the server_name_list. */
    IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(serverNameListStartIdx), 0, serverNameListLen);                           /* TCPIP_CSL_NAME_LENGTH */

    /* #60 Set the consumed overall length. */
    *ConsumedLenPtr = (serverNameListLen + TCPIP_TLS_EXTENSION_SERVER_NAME_LIST_LENGTH_LEN);

    retVal = E_OK;
  }

  return retVal;
} /* TcpIp_TlsClientMsg_ClientExtAddServerNames() */
#  endif /* TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ClientHelloPrepareExtensionListLen
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ClientHelloPrepareExtensionListLen(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Store the start of the transmitted extensions (extensions Len) - Used later to validate the received Server extensions */
  TcpIp_SetTlsBufferTxClientExtensionsIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

  /* #20 Skip the write index for the extensions length field (2 Byte), filled out later */
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_LIST_LEN);

} /* TcpIp_TlsClientMsg_ClientHelloPrepareExtensionListLen() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ClientHelloAddClientExtensions
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
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_TlsStatemachine_STCAL_6050 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ClientHelloAddClientExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* Store the extension length field write index for later usage */
  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType extLenStartTlsBufferTxIdx
    = TcpIp_GetTlsBufferTxClientExtensionsIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);
  uint16 extTotalLen;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Add supported groups extension - TCPIP_TLS_EXTENSION_SUPPORTED_GROUPS */
  TcpIp_TlsClientMsg_ClientHelloExtAddSupportedGroups(TlsConIdx);

  /* #20 Add signature algorithms extension - TCPIP_TLS_EXTENSION_SIGNATURE_ALGORITHMS */
  TcpIp_TlsClientMsg_ClientHelloExtAddSignatureAlgorithms(TlsConIdx);

  /* #30 Add ec supported points format extension - TCPIP_TLS_EXTENSION_EC_SUPPORTED_POINT_FORMAT */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  if (TcpIp_TlsClient_WorkingSetIncludesTlsVersion(TlsConIdx, TCPIP_TLSVERSION_12) == TRUE)
  {
    TcpIp_Tls12ClientMsg_ClientHelloExtAddSupportedPointsFormat(TlsConIdx);
  }
#  endif

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
  /* #40 Add trusted CA indication extension - TCPIP_TLS_EXTENSION_TRUSTED_CA_INDICATION */
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  if (TcpIp_TlsClient_WorkingSetIncludesTlsVersion(TlsConIdx, TCPIP_TLSVERSION_12) == TRUE)
  {
    TcpIp_TlsClientMsg_ClientExtAddTrustedCAIndication(TlsConIdx);
  }
#   endif

  /* #50 Add certificate status request extension - TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST */
  TcpIp_TlsClientMsg_ClientExtAddCertificateStatusRequest(TlsConIdx);

  /* #60 Add server name indication extension - TCPIP_TLS_EXTENSION_SERVER_NAME_INDICATION */
  TcpIp_TlsClientMsg_ClientExtAddServerNameIndication(TlsConIdx);
#  endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  if (TcpIp_TlsClient_WorkingSetIncludesTlsVersion(TlsConIdx, TCPIP_TLSVERSION_13) == TRUE)
  {
    /* #70 Add supported versions extension - TCPIP_TLS_EXTENSION_SUPPORTED_VERSIONS */
    TcpIp_Tls13ClientMsg_ClientHelloExtAddSupportedVersions(TlsConIdx);

    /* #80 Add certificate authorities extension if ECC is enabled */
#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
    if (TcpIp_TlsCoreUtil_ConnectionUseEccCipherSuite(TlsConIdx) == TRUE)
    {
      TcpIp_Tls13ClientMsg_ClientHelloExtAddCertificateAuthorities(TlsConIdx);
    }
#   endif

    if (   (TcpIp_TlsClient_IsResumptionBaseConnection(TlsConIdx) == TRUE)                                              /* PRQA S 3415 4 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
               /* Resumption master secret is referenced in resumption base connection and resumed connection. */
        || (   (TcpIp_IsCsmKeyIdResumptionMasterSecretUsedOfTlsConnection(TlsConIdx) == TRUE)
               /* Only in resumed connection can the following check be true and only if the ticket is still valid. */
            && (TcpIp_IsSessionResumptionUsingPskOfTlsConnectionDyn(TlsConIdx) == TRUE)))
    {
      /* The connection is a resumed connection (where a PSK handshake shall actually be executed)
       * or a resumption base connection. In both cases we offer the psk key exchange modes extension.
       * The RFC implicitly states to send it also in the base connection. Otherwise the server cannot send
       * compatible NewSessionTickets [RFC 8446, 4.2.9.]. */

      /* #90 Add psk key exchange modes extension - TCPIP_TLS_EXTENSION_PSK_KEY_EXCHANGE_MODES */
      TcpIp_Tls13ClientMsg_ClientHelloExtAddPskKeyExchangeModes(TlsConIdx);
    }

    if (TcpIp_IsSessionResumptionUsingPskOfTlsConnectionDyn(TlsConIdx))
    {
      /* #100 Add pre shared keys extension - TCPIP_TLS_EXTENSION_PRE_SHARED_KEY */
      /* This extension MUST be the last extension in the client hello message. */
      TcpIp_Tls13ClientMsg_ClientHelloExtAddPreSharedKey(TlsConIdx);
    }
  }
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */

  /* #110 Calculate and set overall extension length */
  extTotalLen = (uint16)(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx) - extLenStartTlsBufferTxIdx
                 - TCPIP_TLS_EXTENSION_LIST_LEN);
  /* #120 Only include the extensions length if the server wants to transmit extensions */
  if (extTotalLen != 0u)
  {
    /* TLS-Client extensions added to the transmit buffer - write the overall extensions length */
    IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extLenStartTlsBufferTxIdx), 0, extTotalLen);
  }
  else
  {
    /* No TLS-Client extensions are added - reset the placeholder for the extension length field */
    TcpIp_SetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, extLenStartTlsBufferTxIdx);
  }
} /* TcpIp_TlsClientMsg_ClientHelloAddClientExtensions() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ClientHelloAddCipherSuites
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ClientHelloAddCipherSuites(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 cipherWorkerIter;
  TcpIp_SizeOfTlsBufferMgmtType    tlsBufferMgmtIdx    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  uint16                           cipherSuitesCnt     = 0u;
  uint16                           sizeCipherSuiteList;

  TcpIp_TlsCipherWorkingSetMgmtIdxOfTlsConnectionType tlsCipherWorkingSetMgmtIdx
    = TcpIp_GetTlsCipherWorkingSetMgmtIdxOfTlsConnection(TlsConIdx);
  TCPIP_P2C(TcpIp_TlsCipherSuiteWorkingSetType) cipherSuitePtr
    = TcpIp_GetAddrCipherSuiteWorkingSetOfTlsCipherWorkingSetMgmt(tlsCipherWorkingSetMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all cipherWorker in workingset and write the configured cipher suites to the TLS TxBuffer */
  for (cipherWorkerIter = 0; cipherWorkerIter < cipherSuitePtr->workingSetLen; cipherWorkerIter++)
  {
    /* Cipher suite ID as hex value */
    TcpIp_TlsCipherDataType cipherSuiteId =  cipherSuitePtr->workingSet[cipherWorkerIter];
    uint32 cipherSuiteIdWriteOffset
      = (TCPIP_TLS_CIPHERSUITESLEN_LEN + (TCPIP_TLS_CIPHERSUITEID_LEN * (uint32)cipherSuitesCnt));

    /* Write the selected cipher suite to the TX buffer at the correct offset */
    IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)),
                     cipherSuiteIdWriteOffset, cipherSuiteId);

    /* Increment counter of cipher suites supported */
    cipherSuitesCnt++;
  }

  /* Calculate the size of the cipher suite list */
  sizeCipherSuiteList = (TCPIP_TLS_CIPHERSUITEID_LEN * cipherSuitesCnt);

  /* #20 Add the length of cipher suite list to the TLS TxBuffer */
  IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(
    TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)), 0, sizeCipherSuiteList);

  /* Increment the write index by the consumed length  */
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
    (TCPIP_TLS_CIPHERSUITESLEN_LEN + (TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType)sizeCipherSuiteList));

} /* TcpIp_TlsClientMsg_ClientHelloAddCipherSuites() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_PrepareClientHelloAndTriggerPubKeyCalculation
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
 */
/* PRQA S 6030, 6050 1 */ /* MD_TcpIp_TlsStatemachine_STCYC_6030, MD_TcpIp_TlsStatemachine_STCAL_6050 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_PrepareClientHelloAndTriggerPubKeyCalculation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  uint16 clientHelloLen = 0u;
  uint16 writableLength = 0u;
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Prepare the ClientHello message until we are done AND no Async context needs to be computed AND no error occurred */
  while (   (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_SEND_CLIENT_HELLO_DONE)            /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
            /* Async operation is triggered in one of the sub states, switch to lowPrio context - leave this function */
         && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_ASYNC_PENDING)
         && (retVal == E_OK))
  {
    switch (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx))
    {
      case TCPIP_TLS_STATE_SEND_CLIENT_HELLO:
      {
        /* #20 Prepare the ClientHello message by adding all relevant message information */
        /* Set the start index of this message to the current write index */
        /* TlsBufferTxAdHsWriteIdx points to the next free index in the TLS TxBuffer. */
        TcpIp_SetTlsBufferTxClientHelloIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
          TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

        TcpIp_TlsMsg_AddHsHdr(TlsConIdx, TCPIP_TLS_HSTYPE_CLIENTHELLO);

        TcpIp_TlsHelloMsg_AddProtocolVersionNr(TlsConIdx);

        retVal = TcpIp_TlsHelloMsg_AddRandomStructure(TlsConIdx);

        if (retVal == E_OK)
        {
          retVal = TcpIp_TlsHelloMsg_AddSessionId(TlsConIdx);
        }

        if (retVal == E_OK)
        {
          TcpIp_TlsClientMsg_ClientHelloAddCipherSuites(TlsConIdx);

          TcpIp_TlsClientMsg_ClientHelloAddCompressionMethod(TlsConIdx);

          TcpIp_TlsClientMsg_ClientHelloPrepareExtensionListLen(TlsConIdx);

#  if ((TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) && (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON))
          if (TcpIp_TlsClient_WorkingSetIncludesTlsVersion(TlsConIdx, TCPIP_TLSVERSION_13) == TRUE)
          {
            /* The KeyShare extension is only added when TLS 1.3 is supported by the current connection. */
            TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_HELLO_ADD_KEY_SHARE_EXTENSION);
          }
          else
#  endif
          {
            TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_HELLO_ADD_GENERAL_EXTENSIONS);
          }
        }

        break;
      } /* case  TCPIP_TLS_STATE_SEND_CLIENT_HELLO */

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
      case TCPIP_TLS_STATE_SEND_CLIENT_HELLO_ADD_KEY_SHARE_EXTENSION:
      {
        /* Since for the KeyShare extension keys are calculated in the low prio context, it gets a separate state. */
        /* The next state is set in the function. It might trigger the async context to calculate a public key
         * or if all public keys are calculated set the state to CLIENT_HELLO_FINALIZE. */
        /* #30 Add the KeyShare extension */
        retVal = TcpIp_Tls13ClientMsg_ClientHelloExtAddKeyShare(TlsConIdx);
        break;
      } /* case TCPIP_TLS_STATE_SEND_CLIENT_HELLO_ADD_KEY_SHARE_EXTENSION */

      case TCPIP_TLS_STATE_SEND_CLIENT_HELLO_KEY_SHARE_WAIT_FOR_ASYNC:
      {
        /* A public key for the KeyShare extension was calculated in the async context.
         * Update the length fields of the extension and go back to the ADD_KEY_SHARE state.
         * There it gets determined if more public keys need to be calculated. */
        TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_NO_ASYNC);
        TcpIp_Tls13ClientMsg_ClientHelloExtUpdateKeyShareLengthFields(TlsConIdx);
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_HELLO_ADD_KEY_SHARE_EXTENSION);
        break;
      } /* case TCPIP_TLS_STATE_SEND_CLIENT_HELLO_KEY_SHARE_WAIT_FOR_ASYNC */
#   endif
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */

      case TCPIP_TLS_STATE_SEND_CLIENT_HELLO_ADD_GENERAL_EXTENSIONS:
      {
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
        /* Check if session resumption shall be used.
         * If so set the active PSK identity to in use. From now on it can't expire anymore. */
        if (TcpIp_IsSessionResumptionUsingPskOfTlsConnectionDyn(TlsConIdx))
        {
          TcpIp_Tls13PskIdentityIterType activeTls13PskIdentityIdx
            = TcpIp_GetTls13PskIdentityActiveIdxOfTlsConnectionDyn(TlsConIdx);
          TcpIp_SetSessionTicketStateOfTls13PskIdentityDyn(activeTls13PskIdentityIdx,
            TCPIP_TLS_SESSION_TICKET_IN_USE);
        }
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */

        /* #40 Add all other supported extensions */
        TcpIp_TlsClientMsg_ClientHelloAddClientExtensions(TlsConIdx);

        /* #50 Write the length information into the HS Header (Message length = WriteIdx - ServerHelloStartIdx). */
        /* This must be done before the binder can be added for the pre_shared_key extension,
         * since it influences the calculated hash (RFC8446 chapter 4.2.11.2).
         * The length for the binder however is already considered
         * (the write index was already increased by its length). */
        clientHelloLen = (uint16)(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)
          - TcpIp_GetTlsBufferTxClientHelloIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx));
        TcpIp_SetClientHelloLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, clientHelloLen);

        writableLength = clientHelloLen - TCPIP_TLS_HSHDRLEN;
        TcpIp_TlsMsg_AddLenToHsHdr(TcpIp_GetTlsBufferTxClientHelloIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx),
          (uint32)writableLength);

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
        /* If a PSK handshake is requested, trigger PSK calculation, otherwise finalize the hello message. */
        if (TcpIp_IsSessionResumptionUsingPskOfTlsConnectionDyn(TlsConIdx) == TRUE)
        {
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_HELLO_PSK_KEY_CALC);
        }
        else
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
        {
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_HELLO_FINALIZE);
        }
        break;
      }

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      case TCPIP_TLS_STATE_SEND_CLIENT_HELLO_PSK_KEY_CALC:
      {
        /* #60 Trigger PSK calculation. */
        TcpIp_SetCalcPskValueAsyncFlagOfTlsConnectionDyn(TlsConIdx, TRUE);
        TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_ASYNC_PENDING);
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_HELLO_PSK_KEY_WAIT_FOR_ASYNC);
        break;
      }

      case TCPIP_TLS_STATE_SEND_CLIENT_HELLO_PSK_KEY_WAIT_FOR_ASYNC:
      {
        /* A PSK value and a binder were calculated in the async context.
         * Add the binder to the pre_shared_key extension in the Tx buffer. */
        TcpIp_Tls13ClientMsg_ClientHelloExtCopyPskBinderToTxBuffer(TlsConIdx);
        /* Go to the next handshake state. */
        TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_NO_ASYNC);
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_HELLO_FINALIZE);
        break;
      }
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */

      case TCPIP_TLS_STATE_SEND_CLIENT_HELLO_FINALIZE:
      {
#  if ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON))
        /* #70 Add the client random to the Msa_AccessBuffer if enabled */
        TcpIp_TlsClientMsa_AddClientRandomToAccessBuffer(TlsConIdx);
#  endif
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_HELLO_DONE);
        break;
      } /* case TCPIP_TLS_STATE_SEND_CLIENT_HELLO_FINALIZE */

      default:                                                                                                           /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
      {
        /* Default case left blank intentionally */
        break;
      } /* default */
    } /* switch () */
  } /* while () */

  return retVal;

} /* TcpIp_TlsClientMsg_PrepareClientHelloAndTriggerPubKeyCalculation() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientHsStm_SendClientHello
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientHsStm_SendClientHello(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);

  /* #10 Build the ClientHello message and fill the relevant information */
  retVal = TcpIp_TlsClientMsg_PrepareClientHelloAndTriggerPubKeyCalculation(TlsConIdx);

  /* #20 Check if the ClientHello preparation is completed */
                                                                                                                        /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
  if (   (retVal == E_OK) && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_NO_ASYNC)
      && (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_SEND_CLIENT_HELLO_DONE))
  {
    /* #30 Preparation was successful. Change the TLS-Handshake state to TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO and trigger the transmission */
    TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx =
      TcpIp_GetTlsClientConnectionIdxOfTlsConnection( TlsConIdx);

    /* ClientHello message is now ready to send, set the corresponding trigger */
    TcpIp_SetHelloReadyToSendOfTlsClientConnection(tlsClientConnectionIdx, TRUE);

    /* Change the state to TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO */
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO);

  }
  else if (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_ASYNC_PENDING)
  {
    /* #40 Preparation not done yet, an async operation is pending. Nothing to do, just leave the function. */
  }
  else
  {
    /* #50 Preparation failed. Cancel the handshake. */
    TcpIp_TlsClientHsStm_HandleErrorDuringPreparation(TlsConIdx);
  }

} /* TcpIp_TlsClientHsStm_SendClientHello() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientHsStm_ParseServerHello
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
/* PRQA S 6050 1 */ /* MD_TcpIp_TlsStatemachine_STCAL_6050 */
FUNC(void, TCPIP_CODE) TcpIp_TlsClientHsStm_ParseServerHello(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx =
    TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxServerHelloIdxOfTlsClientBufferMgmtType serverHelloIdx =
    TcpIp_GetTlsBufferRxServerHelloIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if a message with the HS Type ServerHello was received */
  if (serverHelloIdx != TCPIP_NO_TLSBUFFERRXSERVERHELLOIDXOFTLSCLIENTBUFFERMGMT)
  {
    TcpIp_TlsHandshakeState nextState = TCPIP_TLS_STATE_HANDSHAKE_INIT;
    Std_ReturnType retVal;

    /* Reset the handshake state machine trigger */
    TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);

    /* #20 if so, try to extract the ServerHello message */
    retVal = TcpIp_TlsClientMsg_ExtractServerHello(TlsConIdx, &nextState);

    if (retVal == E_OK)
    {
      /* #30 Message parsed successfully - check if the parsing is completely done and change the state */
      if (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_ASYNC_PENDING)
      {
        /* Async operation pending, nothing to do - just leave the function */
      }
      else if (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_WAIT_CYCLE)
      {
        /* Next logical HS message not received yet, wait one cycle and try again */
        /* Reset wait cycle for next iteration */
        TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);
      }
      else
      {
        /* #40 Parsing completely done. Change the state depending on the receive message and the key exchange */

        /* next state is: TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE || TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_DONE || TCPIP_TLS_STATE_WAIT_FOR_SERVER_KEY_EXCHANGE */
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, nextState);

        /* All calculations that need to be done in the common state machine are
         * finished. So now the protocol specific state machines should be called. */
        TcpIp_SetVersionSpecificHsStmTriggerOfTlsConnectionDyn(TlsConIdx, TRUE);

      }
    }
    else
    {
      /* #50 Parsing failed. Cancel the handshake. */
      TcpIp_TlsHsStm_HandlesUnexpectedHsInformation(TlsConIdx);
    }
  }
  else
  {
    /* #60 otherwise, we received an unexpected message - Trigger the alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
  }

} /* TcpIp_TlsClientHsStm_ParseServerHello() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ExtractServerHello
 *********************************************************************************************************************/
/*!-
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ExtractServerHello(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(TcpIp_TlsHandshakeState) NextStatePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Extract the message parts until we are done AND no Async context needs to be computed */
  while (   (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx)                                                       /* PRQA S 3415 7 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
              != TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_PARSING_DONE)
         /* Handshake is not aborted due to processing error */
         && (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_HANDSHAKE_ABORT)
         /* Async operation is pending */
         && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_ASYNC_PENDING)
         /* Next state could not be determine (missing next HS message) - Wait cycle */
         && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_WAIT_CYCLE)
         /* Error during parsing - abort next steps */
         && (retVal == E_OK))
  {
    /* Get the current sub state of the extraction */
    switch (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx))
    {
      case TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO:
      {
        /* Extract ServerHello Information */
        retVal = TcpIp_TlsClientMsg_ExtractServerHelloInformation(TlsConIdx);

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
        if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
#   endif
        {
          /* TLS 1.3 - Set the next HS state. */
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx,
            TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_CALC_DH_SHARED_SECRET_AND_HS_KEYS);
        }
#  endif
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
        else
#   endif
        {
         /* TLS 1.2 - Set the next HS state. */
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_STATE_CHANGE);

          /* Decrement HsRxIndicationCnt since the Server Hello message is completely parsed,
           * only the next state is not determined yet. */
          TcpIp_DecHsRxIndicationCntOfTlsConnectionDyn(TlsConIdx);
        }
#  endif
        break;
      }
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      case TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_CALC_DH_SHARED_SECRET_AND_HS_KEYS:
      {
        /* Trigger calculating shared secret and HS traffic keys */

        /* Set Flag for specific crypto operations, and set async pending. We return not until both operations are done. */
        TcpIp_SetDhSharedSecretAsyncFlagOfTlsConnectionDyn(TlsConIdx, TRUE);
        TcpIp_SetCalcHsTrafficKeysAsyncFlagOfTlsConnectionDyn(TlsConIdx, TRUE);
        TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_ASYNC_PENDING);

        /* Set next HS state. */
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_WAIT_FOR_ASYNC);

        break;
      } /* TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_CALC_DH_SHARED_SECRET_AND_HS_KEYS */

      case TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_WAIT_FOR_ASYNC:
      {
        /* Crypto calculation is finished */
        TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_NO_ASYNC);

        /* Set next HS state */
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_STATE_CHANGE);

        /* Decrement HsRxIndicationCnt since the Server Hello message is completely parsed. */
        TcpIp_DecHsRxIndicationCntOfTlsConnectionDyn(TlsConIdx);

        break;
      } /* TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_SWITCH_RL_HANDLING */
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */

      case TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_STATE_CHANGE:
      {
        /* This state could be a WAIT_CYCLE if the next logical TLS message is not received yet */
        /* Next state of HS depends on selected cipher and received message */
        TcpIp_TlsClientMsg_ServerHelloDetermineNextState(TlsConIdx, NextStatePtr);

        break;
      } /* TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_STATE_CHANGE */

      default:                                                                                                            /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
      {
        /* default case left blank intentionally */
        break;
      } /* default */
    } /* switch */
  } /* while */
  return retVal;
} /* TcpIp_TlsClientMsg_ExtractServerHello() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ExtractServerHelloInformation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050 1 */ /* MD_TcpIp_TlsStatemachine_STPTH_6010, MD_TcpIp_TlsStatemachine_STCYC_6030, MD_TcpIp_TlsStatemachine_STCAL_6050 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ExtractServerHelloInformation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxServerHelloIdxOfTlsClientBufferMgmtType serverHelloStartIdx
    = TcpIp_GetTlsBufferRxServerHelloIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  TcpIp_ServerHelloLenOfTlsClientBufferMgmtType serverHelloLen
    = TcpIp_GetServerHelloLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);
  TcpIp_TlsBufferRxServerHelloIdxOfTlsClientBufferMgmtType serverHelloEndIdx
    = (serverHelloStartIdx + TCPIP_TLS_HSHDRLEN + serverHelloLen); /* End index of the received ServerHello message - Need for in range checks inside the parser */

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if we received the absolute minimum length for this type of message and parse all information within the ServerHello message */
  if (TcpIp_TlsHs_CheckExpectedMsgLen(serverHelloLen, TCPIP_TLS_12_MIN_SERVERHELLO_MSGLEN) == E_OK)
  {

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    /* Before we can evaluate other hello parameters, we need to check if the extension "supported versions" is included
     * and contains version "TLS 1.3". With this information we can come back to the start of the message and evaluate
     * all parameters and extensions. */
    retVal = TcpIp_Tls13ClientMsg_ServerHelloChecksBeforeScanForSuppVersExt(TlsConIdx, serverHelloStartIdx, serverHelloEndIdx);

    if ((retVal == E_OK) && (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13))               /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
    {
      /* Check if we received the absolute minimum length for a TLS 1.3 ServerHello message (HelloRequestMsg). */
      retVal = TcpIp_TlsHs_CheckExpectedMsgLen(serverHelloLen, TCPIP_TLS_13_MIN_SERVERHELLO_MSGLEN);
    }

#  else
    TcpIp_SetActiveVersionOfTlsConnectionDyn(TlsConIdx, TCPIP_TLSVERSION_12);
#  endif

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    if (retVal == E_OK)
#  endif
    {
      /* Parse the TLS-Handshake major and minor TLS-Version. */
      retVal = TcpIp_TlsMsg_HelloMsgGetVersionNr(TlsConIdx);
    }

    if (retVal == E_OK)
    {
      /* Parse the received ClientHello random number */
      retVal = TcpIp_TlsMsg_HelloMsgGetAndCheckRandom(TlsConIdx);
    }

    if (retVal == E_OK)
    {
      /* Parse received session ID (sessions not supported by this implementation) */
      retVal = TcpIp_TlsMsg_HelloMsgGetAndCheckSessionId(TlsConIdx, serverHelloEndIdx);
    }

    if (retVal == E_OK)
    {
      /* Parse received cipher suite */
      retVal = TcpIp_TlsClientMsg_ServerHelloMsgGetCipherSuite(TlsConIdx, serverHelloEndIdx);
    }

    if (retVal == E_OK)
    {
      /* Parse the received compression methods */
      retVal = TcpIp_TlsClientMsg_ServerHelloMsgGetCompressionMethod(TlsConIdx, serverHelloEndIdx);
    }

    if (retVal == E_OK)
    {
      /* Parse the received ServerHello extensions, if present */
      retVal = TcpIp_TlsClientMsg_ServerHelloGetExtensions(TlsConIdx, serverHelloEndIdx);
    }

    if (retVal == E_OK)
    {
      /* Check if there is some more information in the buffer */
      retVal = TcpIp_TlsMsg_CheckMsgForRemainingData(TlsConIdx, serverHelloEndIdx);
    }

#  if ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON))
    if (retVal == E_OK)
    {
      /* #20 Add SessionId and SessionId length to Msa_AccessBuffer if enabled */
      TcpIp_TlsClientMsa_AddServerSessionIdToAccessBuffer(TlsConIdx);
    }
#  endif
#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
    if (retVal == E_OK)
    {
      TcpIp_TlsClientMsg_ServerHelloUpdateOCSPInfo(TlsConIdx);
    }
#   endif
#  endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */
  }
  else
  {
    /* #30 otherwise, we do not receive the ServerHello message with the min required length. Report an User Error */
    TcpIp_TlsUserErrorType serverHelloUserError;
    serverHelloUserError.FunctionId  = TCPIP_TLS_FCTID_CLIENT_HSSTM_PARSE_SERVERHELLO;
    serverHelloUserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_UNEXPECTEDMSGLEN;
    serverHelloUserError.TlsConId    = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    /* Report the error to the user */
    TcpIp_TlsCoreError_ReportUserError(serverHelloUserError);

    /* retVal already E_NOT_OK. */
  }

  return retVal;
} /* TcpIp_TlsClientMsg_ExtractServerHelloInformation() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ServerHelloMsgGetCipherSuite
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
/* PRQA S 6050 1 */ /* MD_TcpIp_TlsStatemachine_STCAL_6050 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloMsgGetCipherSuite(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(TcpIp_TlsBufferRxIterType, AUTOMATIC) HelloEndIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx      = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  uint16                        receivedCipherSuite   = TCPIP_TLS_CIPHER_INVALID;
  Std_ReturnType                retVal                = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx),
    (TcpIp_TlsBufferRxIterType)TCPIP_TLS_CIPHERSUITEID_LEN, HelloEndIdx))
  {
    /* #10 Get the received cipher suite */
    receivedCipherSuite = IpBase_GetUint16(
        TcpIp_GetAddrTlsBufferRx(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)), 0);

    /* And increment the read index by the length of the cipher suite length field */
    TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_CIPHERSUITEID_LEN);

    /* And save the received cipher suite since it's needed to choose the right active cipherworker later. */
    TcpIp_SetReceivedCipherSuiteIdOfTlsClientConnection(TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx),  /* TCPIP_CSL_MISSDETECTION */
      receivedCipherSuite);

    /* #20 Check if we received a matching CipherSuite and select the corresponding CipherWorker as active one */
    if (TcpIp_TlsMsg_CheckIfCipherSuiteIdMatches(TlsConIdx, receivedCipherSuite) == E_OK)
    {
      TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx
        = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
      /* #30 Select the active handshake reference if we found a matching cipherWorker */
      TcpIp_TlsClientMsg_ServerHelloMsgSelectHandshakeReference(TlsConIdx, activeTlsCipherWorkerIdx);

      retVal = E_OK;
    }
    else
    {
      /* #40 If there is no matching cipher suite, report an error to the user */
      TcpIp_TlsUserErrorType userError;
      userError.FunctionId = TCPIP_TLS_FCTID_CLIENT_HSSTM_PARSE_SERVERHELLO;
      userError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_NOMATCHINGCIPHER;
      userError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

      TcpIp_TlsCoreError_ReportUserError(userError);

      /* In TLS 1.3 it is specified that in this case an illegal_parameter alert shall be send
        * (see RFC8446 chapter 4.1.3). This alert won't be overwritten by the next alert. */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_ILLEGAL_PARAM);
    }
  }
  else
  {
    /* #50 Report an error to the user */
    TcpIp_TlsUserErrorType UserError;
    UserError.FunctionId = TCPIP_TLS_USERERROR_PARSEHELLO(TlsConIdx);
    UserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_INCORRECTCIPHERLEN;
    UserError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(UserError);

    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);

    retVal = E_NOT_OK;
  }

  return retVal;
} /* TcpIp_TlsClientMsg_ServerHelloMsgGetCipherSuite() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ServerHelloMsgSelectHandshakeReference
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloMsgSelectHandshakeReference(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TcpIp_TlsCipherWorkerIterType TlsCipherWorkerIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsKeyExchangeMethodDataType keyExchangeMethod = TCPIP_TLS_KEYEXCHANGE_METHOD_INVALID;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Select the corresponding handshake reference, depending on the selected key exchange method */
  if (TlsCipherWorkerIdx != TCPIP_NO_TLSCIPHERWORKERACTIVEIDXOFTLSCONNECTIONDYN)
  {
    keyExchangeMethod = TcpIp_TlsCoreUtil_ReturnCipherSpecificKeyExchangeMethod(
      TcpIp_GetCipherSuiteIdOfTlsCipherDefinition(
        TcpIp_GetTlsCipherDefinitionIdxOfTlsCipherWorker(TlsCipherWorkerIdx)));

    switch (keyExchangeMethod)
    {
      case TCPIP_TLS_KEYEXCHANGE_METHOD_PSK_PLAIN:
      {
        /* There is no support for multiple HS references in case of PSK.
          * Select the default (first) handshake reference. */
        TcpIp_TlsMsg_SelectDefaultHandshakeReference(TlsConIdx);
        break;
      }
#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
      case TCPIP_TLS_KEYEXCHANGE_METHOD_ECDHE:
      case TCPIP_TLS_KEYEXCHANGE_METHOD_ECDH:
      {
        /* Selection of correct TlsHandshake container depending on the received curve in the ServerCertificate message
         * is done in TcpIp_TlsClientMsg_SetActiveCipherWorkerAccordingToReceivedServerParams(). */
        break;
      }
#  endif /* TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */
      default:
      {
        /* Invalid key exchange method. This should never happen. */
        break;
      }
    }  /* switch (keyExchangeMethod) */
  }
} /* TcpIp_TlsClientMsg_ServerHelloMsgSelectHandshakeReference() */

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_SetActiveCipherWorkerAccordingToReceivedServerParams
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_SetActiveCipherWorkerAccordingToReceivedServerParams(
  TcpIp_TlsConnectionIterType     TlsConIdx,
  TcpIp_TlsEllipticCurveIdType    CurveId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  boolean foundMatchingCipherworker = FALSE;
  TcpIp_TlsClientConnectionIdxOfTlsConnectionType tlsClientConnectionIdx
    = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsHandshakeIndIterType tlsHandshakeIndIdx;
  TcpIp_TlsCipherWorkerIndIterType tlsCipherWorkerIndIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all configured CipherWorkers and check if their cipher suite matches with the given one */
  for (tlsCipherWorkerIndIdx = TcpIp_GetTlsCipherWorkerIndStartIdxOfTlsConnection(TlsConIdx);
    tlsCipherWorkerIndIdx < TcpIp_GetTlsCipherWorkerIndEndIdxOfTlsConnection(TlsConIdx);
    tlsCipherWorkerIndIdx++)
  {
    TcpIp_TlsCipherWorkerIndType tlsCipherWorkerIdx
      = TcpIp_GetTlsCipherWorkerInd(tlsCipherWorkerIndIdx);
    TcpIp_TlsCipherDefinitionIdxOfTlsCipherWorkerType tlsCipherDefinitionIdx
      = TcpIp_GetTlsCipherDefinitionIdxOfTlsCipherWorker(tlsCipherWorkerIdx);
    TcpIp_CipherSuiteIdOfTlsCipherDefinitionType cipherSuiteId
      = TcpIp_GetCipherSuiteIdOfTlsCipherDefinition(tlsCipherDefinitionIdx);

    if (TcpIp_GetReceivedCipherSuiteIdOfTlsClientConnection(tlsClientConnectionIdx) == cipherSuiteId)
    {
      TcpIp_TlsHandshakeIndStartIdxOfTlsCipherWorkerType handshakeStartIdx
        = TcpIp_GetTlsHandshakeIndStartIdxOfTlsCipherWorker(tlsCipherWorkerIdx);
      TcpIp_TlsHandshakeIndEndIdxOfTlsCipherWorkerType handshakeEndIdx
        = TcpIp_GetTlsHandshakeIndEndIdxOfTlsCipherWorker(tlsCipherWorkerIdx);

      /* #20 Iterate through all available handshakes for this CipherWorker */
      for (tlsHandshakeIndIdx = handshakeStartIdx; tlsHandshakeIndIdx < handshakeEndIdx; tlsHandshakeIndIdx++)
      {
        TcpIp_TlsHandshakeIterType tlsHandshakeIdx = TcpIp_GetTlsHandshakeInd(tlsHandshakeIndIdx);
        TcpIp_SignatureAlgorithmIdType sigAlgoId = TcpIp_GetSignatureAlgorithmIdOfTlsHandshake(tlsHandshakeIdx);

        /* #30 If a handshake with a matching curve is found and the signature algorithm is in the working set, mark the CipherWorker as active */
        if (   (CurveId == TcpIp_GetEllipticCurveIdOfTlsHandshake(tlsHandshakeIdx))
            && (TcpIp_TlsClient_IsSignatureAlgorithmInWorkingSet(TlsConIdx, sigAlgoId) == TRUE))                        /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
        {
          TcpIp_SetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx, tlsCipherWorkerIdx);
          /* Also set the current handshake as active and save its elliptic curve in the TLS connection. */
          TcpIp_SetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(tlsCipherWorkerIdx, (uint8)tlsHandshakeIdx);
          TcpIp_SetEllipticCurveIdOfTlsConnectionDyn(TlsConIdx, TcpIp_GetEllipticCurveIdOfTlsHandshake(tlsHandshakeIdx));
          retVal = E_OK;
          foundMatchingCipherworker = TRUE;
          break;
        }
      }
      if (foundMatchingCipherworker == TRUE)
      {
        break;
      }
    }
  }

  return retVal;
} /* TcpIp_TlsClientMsg_SetActiveCipherWorkerAccordingToReceivedServerParams */
#  endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsClientHsStm_ReturnReceivedCipherSpecificKeyExchangeMethod
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(TcpIp_TlsKeyExchangeMethodDataType, TCPIP_CODE) TcpIp_TlsClientHsStm_ReturnReceivedCipherSpecificKeyExchangeMethod(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientConnectionIdxOfTlsConnectionType tlsClientConnectionIdx
    = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);
  /* Get the received cipher suite from the ServerHello message. */
  TcpIp_ReceivedCipherSuiteIdOfTlsClientConnectionType receivedCipherSuiteId
    = TcpIp_GetReceivedCipherSuiteIdOfTlsClientConnection(tlsClientConnectionIdx);
  TcpIp_TlsKeyExchangeMethodDataType retVal = TCPIP_TLS_KEYEXCHANGE_METHOD_INVALID;

  /* ----- Implementation ----------------------------------------------- */
  /* Check if the received cipher suite is already set / the ServerHello message is already parsed. */
  if (receivedCipherSuiteId != TCPIP_TLS_CIPHER_INVALID)
  {
    /* #10 Get the key exchange method for the cipher suite Id. */
    retVal = TcpIp_TlsCoreUtil_ReturnCipherSpecificKeyExchangeMethod(receivedCipherSuiteId);
  }
  return retVal;
} /* TcpIp_TlsClientHsStm_ReturnReceivedCipherSpecificKeyExchangeMethod() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ServerHelloMsgGetCompressionMethod
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloMsgGetCompressionMethod(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(TcpIp_TlsBufferRxIterType, AUTOMATIC) HelloEndIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx   = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  Std_ReturnType                retVal             = E_OK;
  uint16                        compMethodSelected;

  /* ----- Implementation ----------------------------------------------- */
  if ((TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx),             /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
    (TcpIp_TlsBufferRxIterType)TCPIP_TLS_COMPMETHLEN_LEN, HelloEndIdx)))
  {
    /* Get the received compression method */
    compMethodSelected = IpBase_GetUint8(
      TcpIp_GetAddrTlsBufferRx(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)), 0);

    /* and increment the read index by the length of the compression method field */
    TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_COMPMETHLEN_LEN);

    /* #10 Check if the received compression method is valid. Only 'no_compression (0)' method is allowed */
    if (compMethodSelected != TCPIP_TLS_COMPRESSION_METHOD_NONE)
    {
      /* #20 otherwise, incorrect compression method received - Report an error to the user */
      TcpIp_TlsUserErrorType userError;
      userError.FunctionId = TCPIP_TLS_FCTID_CLIENT_HSSTM_PARSE_SERVERHELLO;
      userError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_INCORRECTCOMPMETHOD;
      userError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

      TcpIp_TlsCoreError_ReportUserError(userError);

      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_ILLEGAL_PARAM);

      retVal = E_NOT_OK;
    }
  }
  else
  {
    /* #30 Report an error to the user */
    TcpIp_TlsUserErrorType UserError;
    UserError.FunctionId = TCPIP_TLS_USERERROR_PARSEHELLO(TlsConIdx);
    UserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_INCORRECTCOMPRESSIONLEN;
    UserError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(UserError);

    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);

    retVal = E_NOT_OK;
  }

  return retVal;
} /* TcpIp_TlsClientMsg_ServerHelloMsgGetCompressionMethod */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ServerHelloCheckSessionIdAndStoreBufferIndex
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloCheckSessionIdAndStoreBufferIndex(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC)     SessionIdLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Store the buffer index of the session Id if it is non-empty */
  if (SessionIdLen > 0u)
  {
    /* Store the start index of the received server session ID */
    TcpIp_SetTlsBufferRxServerSessionIdIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
      TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));
    TcpIp_SetServerHelloSessionIdLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, SessionIdLen);
  }

  /* #20 In case of Tls version 1.3 - check length of session id and if it is the same as sent by the client */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
#   endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
  {
    if (SessionIdLen == TCPIP_TLS13_LEGACYSESSIONIDLEN)
    {
      /* Non-empty session Id with valid length */
      if (VStdLib_MemCmp(
        TcpIp_GetAddrTlsBufferRx(TcpIp_GetTlsBufferRxServerSessionIdIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx)),
        TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxClientSessionIdIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx)),
        TCPIP_TLS13_LEGACYSESSIONIDLEN) == VSTDLIB_MEM_CMP_RES_EQ)
      {
        retVal = E_OK;
      }
      else
      {
        /* retVal already E_NOT_OK */
        /* A client which receives a legacy_session_id_echo field
         * that does not match what it sent in the ClientHello
         * MUST abort the handshake with an "illegal_parameter" alert. (RFC8446 chapter 4.1.3). */
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_ILLEGAL_PARAM);
      }

    }
    else if (SessionIdLen == 0u)
    {
      /* Empty session Id */
      if (TcpIp_IsMiddleboxCompatibilityModeOfTlsConnection(TlsConIdx) == FALSE)
      {
        /* If compatibility mode is disabled the session Id in the ClientHello
         * must be empty (see RFC8446 chapter 4.1.2).
         * Since we also received an empty session Id, this case is valid. */
        retVal = E_OK;
      }
      else
      {
        /* Compatibility mode enabled, the session Id in the ClientHello must be non-empty (see RFC8446 chapter 4.1.2),
         * but we received an empty session Id, invalid case. */
        /* retVal already E_NOT_OK */
        /* A client which receives a legacy_session_id_echo field
         * that does not match what it sent in the ClientHello
         * MUST abort the handshake with an "illegal_parameter" alert. (RFC8446 chapter 4.1.3). */
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_ILLEGAL_PARAM);
      }
    }
    else
    {
      /* Invalid session Id length, retVal is already E_NOT_OK */
    }
  }
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  else
#   endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
  {
    /* In case of TLS version 1.2 as we do not want to use session resumption - return E_OK and continue with normal handshake */
    retVal = E_OK;
  }
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
  return retVal;
} /* TcpIp_TlsClientMsg_ServerHelloCheckSessionIdAndStoreBufferIndex() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ServerHelloGetExtensions
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloGetExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferRxIterType  HelloEndIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint16 extensionsLen = 0u;
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  boolean extensionsMustBePresent = TRUE;
#  endif

  /* ----- Implementation ----------------------------------------------- */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_12)
#   endif
  {
    /* Check if we are already at the end of the message. */
    if (TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx) == HelloEndIdx)
    {
      /* #10 No extensions have been detected */
      /* Valid case - return E_OK */
      extensionsMustBePresent = FALSE;
      retVal = E_OK;
    }
    else
    {
      /* #20 At least 1 byte extensions have been detected */
      extensionsMustBePresent = TRUE;
    }
  } /* else - TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13:
     * Since the presence of the supported versions extension was checked earlier
     * (TcpIp_Tls13ClientMsg_ServerHelloScanForSupportedVersionsExt()) and is mandatory for TLS 1.3
     * there must be at least the supported versions extension, extensionsMustBePresent is already true. */

  /* Only process extensions when they must be present. */
  if (extensionsMustBePresent == TRUE)
#  endif
  {
    /* Check the extensions length for validity.
     * In a manipulated TLS 1.3 case when no extensions are send we might be already at the end of the message.
     * The following function checks this as well and returns E_NOT_OK if this is the case. */
    if (TcpIp_TlsCoreUtil_GetExtensionsLengthAndCheckForValidity(TlsConIdx, HelloEndIdx, &extensionsLen) == E_OK)
    {
      /* #30 Parse extensions */
      /* Iterate over the extension data and extract extension(s) */
      retVal = TcpIp_TlsClientMsg_ServerMsgParseAndValidateExtensions(TlsConIdx, extensionsLen, HelloEndIdx, TCPIP_TLS_HSTYPE_SERVERHELLO);
    }
  }

  return retVal;
} /* TcpIp_TlsClientMsg_ServerHelloGetExtensions() */

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ServerHelloUpdateOCSPInfo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloUpdateOCSPInfo(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If connection is based on TLS 1.2, reset the OCSP connection state for all certs except leaf */
#    if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_12)
#    endif
  {
    /* If OCSP was requested, only set leaf certificate ID to requested as multi
     * stapling is currently not yet supported. */
    TcpIp_TlsCertValidationStatusDynIterType curTlsCertValidationStatusIdx = 0u;

    /* Deactivate the OCSP connection state for everything except the leaf */
    for (curTlsCertValidationStatusIdx = TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx) + 1u;
         curTlsCertValidationStatusIdx < (TcpIp_TlsCertValidationStatusDynIterType)TcpIp_GetTlsCertValidationStatusDynEndIdxOfTlsConnection(TlsConIdx);
         curTlsCertValidationStatusIdx++)
    {
      TcpIp_GetAddrTlsCertValidationStatusDyn(curTlsCertValidationStatusIdx)
        ->CertStatusResponse.OcspConnectionState = TCPIP_TLS_OCSP_CONNECTION_STATE_INACTIVE;
    }
  }
} /* TcpIp_TlsClientMsg_ServerHelloUpdateOCSPInfo() */
#   endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
#  endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ServerMsgParseAndValidateExtensions
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
 */
/* PRQA S 6050, 6080 1 */ /* MD_TcpIp_TlsStatemachine_STCAL_6050, MD_TcpIp_TlsStatemachine_STMIF_6080 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerMsgParseAndValidateExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16                      ExtensionsLen,
  TcpIp_TlsBufferRxIterType   MsgEndIdx,
  TcpIp_TlsMsgHandshakeType   SourceMessage)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsExtensionType listOfReceivedExtensions[TCPIP_TLS_MAX_EXTENSION_LIST_LENGTH] = { 0 };
  uint8 overallNumberOfReceivedExtensions = 0u;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the received extension length is in range of the TLS RxBuffer */
  if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx),
    (TcpIp_TlsBufferRxIterType)ExtensionsLen, MsgEndIdx))
  {
    /* #20 Iterate over the extension data and extract each extension into overall list of received extensions */
    if (TcpIp_TlsMsg_ExtractReceivedExtensions(TlsConIdx, ExtensionsLen, MsgEndIdx,
      &listOfReceivedExtensions[0], &overallNumberOfReceivedExtensions) == E_OK)
    {
      /* #30 Check for duplicated received extensions */
      if (TcpIp_TlsMsg_CheckDuplicatedReceivedExtensions(&listOfReceivedExtensions[0],
        overallNumberOfReceivedExtensions) == E_OK)
      {
        /* #40 Check if extensions are present in the correct message and if they are supported in the active TLS version */
        if (TcpIp_TlsClientMsg_ServerMsgCompareAgainstTransmittedExtensions(TlsConIdx, &listOfReceivedExtensions[0],
          overallNumberOfReceivedExtensions) == E_OK)
        {
          /* #50 Compare received extensions with the sent one in the ClientHello message */
          if (TcpIp_TlsClientMsg_ServerMsgValidateExtensionListForSourceMessageAndTlsVersion(TlsConIdx, &listOfReceivedExtensions[0],
            overallNumberOfReceivedExtensions, SourceMessage) == E_OK)
          {
            /* #60 Parse received extensions */
            if (TcpIp_TlsClientMsg_ServerMsgParseReceivedExtensions(TlsConIdx, &listOfReceivedExtensions[0],
              overallNumberOfReceivedExtensions, SourceMessage) == E_OK)
            {
              /* #70 All extension fully validated and parsed - return E_OK */
              /* The check if we received all mandatory extensions
               * in TLS 1.2 case is done in the context of the ServerHelloDone
               * (due to the Validation callback to the upper layer).
               * In TLS 1.3 case, if SourceMessage is of type ServerHello, either the pre_shared_key or the
               * key_share or both extensions need to be present.
               * This was checked in TcpIp_TlsClientMsg_ServerMsgParseReceivedExtensions().
               * If the supported_versions extension is missing
               * the handshake was already aborted in TcpIp_Tls13ClientMsg_ServerHelloScanForSupportedVersionsExt().
               * If SourceMessage is of type EncryptedExtensions there are no
               * mandatory extensions. The client must only check for the presence of any forbidden extension,
               * which already has been done in the previous implementation. */
              retVal = E_OK;
            }
            else
            {
              /* Either parsing of extension failed, extension type unknown or not every mandatory extension is there.
               * For the first two cases the alert is already set and won't be overwritten.
               * Trigger alert for missing mandatory extension. */
              /* For a resumed connection in the case of TLS 1.3 session resumption
               * the RFC8446 states in chapter 4.2.11:
               * "Clients MUST verify that the server's selected_identity is within the range supplied by the client,
               * that the server selected a cipher suite indicating a Hash associated with the PSK, and that a server
               * "key_share" extension is present if required by the ClientHello "psk_key_exchange_modes" extension.
               * If these values are not consistent,
               * the client MUST abort the handshake with an "illegal_parameter" alert."
               * It was decided that "values" refers to the selected identity the cipher suite and the Hash
               * and that if the key_share extension is missing, the missing_extension alert shall be send
               * (chapter 6.2) even though it is not explicitly stated in this paragraph. */
              TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_MISSING_EXT);
            }
          }
          else
          {
            /* Extension is known since the request was send in the ClientHello but was received
             * either in the wrong message or the ServerHello chose a TLS version which does not fit to this extension.
             * Set an illegal_parameter alert (see RFC8446 chapter 4.2). */
            TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_ILLEGAL_PARAM);
          }
        }
        else
        {
          /* Received answer to extension which was not transmitted. Can also be unknown extension - Trigger alert */
          TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNSUP_EXT);
        }
      }
      else
      {
        /* Duplicated received extension - Trigger alert */
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
      }
    }
    else
    {
      /* Invalid formatted received extension - Trigger alert */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
    }
  }
  return retVal;
} /* TcpIp_TlsClientMsg_ServerMsgParseAndValidateExtensions() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ServerMsgCompareAgainstTransmittedExtensions
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerMsgCompareAgainstTransmittedExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(TcpIp_TlsExtensionType) ReceivedExtensionListPtr,
  uint8 ReceivedExtensionCnt)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferTxClientExtensionsIdxOfTlsClientBufferMgmtType txExtLenTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxClientExtensionsIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  TcpIp_TlsBufferTxClientExtensionsIdxOfTlsClientBufferMgmtType transmittedExtensionStartIdx =
    txExtLenTlsBufferTxIdx + TCPIP_TLS_EXTENSION_LENGTH_LEN;

  uint8 rxExtensionIter;
  uint16 transmittedExtensionTotalLength;

  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* RFC3456 - 2.3. Hello Extensions */
  /* If a client receives an extension type in ServerHello that it did not
   * request in the associated ClientHello, it MUST abort the handshake */

  /*
   *   Extension Layout in Tls TxBuffer:
   *
   *         (fix) +-> txExtLenTlsBufferTxIdx
   *              /     (change per iteration:)
   *             /            +-> currentTransmittedExtensionType
   *            /            /          +-> currentTransmittedExtensionLength
   *           /            /          /
   *          [FullExtLen] [extType_1][extLen_1][extData_1] [extType_2][extLen_2][extData_2] ...
   *   Bytes:      2           2          2         n           2         2          n
   *   Iter:               ^
   *                       |
   *                       +---> txExtensionOffsetIter
   */

  transmittedExtensionTotalLength = IpBase_GetUint16(TcpIp_GetAddrTlsBufferTx(txExtLenTlsBufferTxIdx), 0);

  /* #10 Iterate over all received server extensions */
  for (rxExtensionIter = 0; rxExtensionIter < ReceivedExtensionCnt; rxExtensionIter++)
  {
    /* Reset Iter and flag per round */
    uint16 txExtensionOffsetIter = 0u;
    boolean isRxExtensionPresentInTxExtensions = FALSE;

    /* Get the next received extension type */
    uint16 currentReceivedExtensionType = ReceivedExtensionListPtr[rxExtensionIter].Type;

    /* #20 Iterate over all transmitted client extension */
    while (txExtensionOffsetIter < transmittedExtensionTotalLength)
    {
      /* Extract the type of the iterated transmitted extension */
      uint16 currentTransmittedExtensionType = IpBase_GetUint16(TcpIp_GetAddrTlsBufferTx(
        transmittedExtensionStartIdx + txExtensionOffsetIter), 0);

      /* Extract the length of the iterated transmitted extension */
      uint16 currentTransmittedExtensionLength = IpBase_GetUint16(TcpIp_GetAddrTlsBufferTx(
        transmittedExtensionStartIdx + TCPIP_TLS_EXTENSION_TYPE_LEN + txExtensionOffsetIter), 0);

      /* Increment the iterator by the consumed type length (2 bytes) */
      txExtensionOffsetIter += TCPIP_TLS_EXTENSION_TYPE_LEN;
      /* Increment the iterator by the consumed length field length (2 bytes) */
      txExtensionOffsetIter += TCPIP_TLS_EXTENSION_LENGTH_LEN;
      /* Increment the iterator by the consumed data length (n bytes ) */
      txExtensionOffsetIter += currentTransmittedExtensionLength;
      /* next round of loop the txExtensionOffsetIter is directing to the next transmitted extension type */

      /* #30 Compare the current received extension against the transmitted extension */
      /* Compare extension type */
      if (currentReceivedExtensionType == currentTransmittedExtensionType)
      {
        /* #40 Extension is present in transmitted ClientHello message */
        isRxExtensionPresentInTxExtensions = TRUE;
        /* Skip all other transmitted extension and continue with the next received one */
        break;
      }
    }

    if (isRxExtensionPresentInTxExtensions == FALSE)
    {
      /* #50 if one received extension is not present - return E_NOT_OK */
      retVal = E_NOT_OK;
      /* Since one received Extension is NOT present in the transmitted extensions, we can skip the others at this point */
      break;
    }
  }

  return retVal;
} /* TcpIp_TlsClientMsg_ServerMsgCompareAgainstTransmittedExtensions() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ServerMsgParseReceivedExtensions
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
 *
 */
/* PRQA S 6050, 6030, 6010 1 */ /* MD_TcpIp_STCAL_CslAccess, MD_TcpIp_TlsStatemachine_STCYC_6030, MD_TcpIp_TlsStatemachine_STPTH_6010 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerMsgParseReceivedExtensions(
  TcpIp_TlsConnectionIterType       TlsConIdx,
  TCPIP_P2C(TcpIp_TlsExtensionType) ReceivedExtensionListPtr,
  uint8                             ReceivedExtensionCnt,
  TcpIp_TlsMsgHandshakeType         SourceMessage)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 rxExtensionIter;
  Std_ReturnType retVal = E_OK;
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  /* Since in TLS 1.3 we only support PSK with (EC)DHE the only mandatory extension is the key_share. */
  boolean mandatoryExtensionsInServerHelloArePresent = FALSE;
  /* In the TLS 1.3 PSK case the server may omit the pre_shared_key extension.
   * In this case we are able to do an standard ECC handshake. */
  boolean preSharedKeyInServerHelloIsPresent = FALSE;
#  endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all received server extensions */
  for (rxExtensionIter = 0u; rxExtensionIter < ReceivedExtensionCnt; rxExtensionIter++)
  {
    /* That the received extension types are valid in the current message and TLS version was already checked
     * in TcpIp_TlsClientMsg_ServerMsgValidateExtensionListForSourceMessageAndTlsVersion().
     * Therefore just get the next received extension type and parse it depending on the type. */
    uint16 currentReceivedExtensionType = ReceivedExtensionListPtr[rxExtensionIter].Type;

    switch (currentReceivedExtensionType)
    {
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      case TCPIP_TLS_EXTENSION_SUPPORTED_GROUPS:
      {
        /* #20 In case of extension type elliptic_curves/supported_groups(10) - forward to specific parser */
        retVal = TcpIp_Tls13ClientMsg_ServerEncryptedExtensionsParseExtensionSupportedGroups(TlsConIdx,
          ReceivedExtensionListPtr[rxExtensionIter]);
        break;
      }
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      case TCPIP_TLS_EXTENSION_EC_POINT_FORMAT:
      {
        /* #30 In case of extension type ec_point_formats(11) - forward to specific parser */
        retVal = TcpIp_TlsClientMsg_ServerHelloParseExtensionEcPointFormat(TlsConIdx,
          ReceivedExtensionListPtr[rxExtensionIter]);
        break;
      }
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      case TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST:
      {
        /* #40 In case of extension type certificate_status_request(5) - forward to specific parser */
        retVal = TcpIp_TlsClientMsg_ServerHelloParseExtensionCertificateStatusRequest(TlsConIdx,
          ReceivedExtensionListPtr[rxExtensionIter]);
        break;
      }
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      case TCPIP_TLS_EXTENSION_TRUSTED_CA_INDICATION:
      {
        /* #50 In case of extension type trusted_ca_indication(3) - forward to specific parser */
        retVal = TcpIp_TlsClientMsg_ServerHelloParseExtensionTrustedCaIndication(
          ReceivedExtensionListPtr[rxExtensionIter]);
        break;
      }
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      case TCPIP_TLS_EXTENSION_SERVER_NAME_INDICATION:
      {
        /* #60 In case of extension type server_name(0) - forward to specific parser */
        retVal = TcpIp_TlsClientMsg_ServerHelloParseExtensionServerNameIndication(
          ReceivedExtensionListPtr[rxExtensionIter]);
        break;
      }
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      case TCPIP_TLS_EXTENSION_SUPPORTED_VERSIONS:
      {
        /* #70 In case of extension type supported_versions(43) - skip parsing because it has already been done */
        /* According to RFC8446 Section 4.2.1.:
         * The supported_versions extension must be parsed by the client prior to processing the rest of the ServerHello.
         * This is done in function TcpIp_Tls13ClientMsg_ServerHelloScanForSupportedVersionsExt() */
        retVal = E_OK;
        break;
      }
#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
      case TCPIP_TLS_EXTENSION_KEY_SHARE:
      {
        /* #80 In case of extension type key_share(51) - forward to specific parser */
        retVal = TcpIp_Tls13ClientMsg_ServerHelloParseExtensionKeyShare(TlsConIdx,
          ReceivedExtensionListPtr[rxExtensionIter]);
        mandatoryExtensionsInServerHelloArePresent = TRUE;
        break;
      }
#   endif
      case TCPIP_TLS_EXTENSION_PRE_SHARED_KEY:
      {
        /* #90 In case of extension type pre_shared_key(41) - forward to specific parser */
        retVal = TcpIp_Tls13ClientMsg_ServerHelloParseExtensionPreSharedKey(TlsConIdx,
          ReceivedExtensionListPtr[rxExtensionIter]);
        preSharedKeyInServerHelloIsPresent = TRUE;
        break;
      }
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
      default:
      {
        /* Unknown extension type. Known extension types which shall not be received (like signature_algorithms(13))
         * are already checked in TcpIp_TlsClientMsg_ServerMsgExtensionValidateSourceMessageAndTlsVersion() */
        retVal = E_NOT_OK;
        break;
      }
    }

    /* #100 If extension type unknown - trigger alert and return E_NOT_OK */
    if (retVal != E_OK)
    {
      /* Unknown received extension - Trigger alert */
      /* When parsing of one extension fails an alert is already set in the subfunctions.
       * The alert won't be overwritten. */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNSUP_EXT);

      /* Skip parsing of all other received extensions */
      break;
    }
  }
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  if (   (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
      && (SourceMessage == TCPIP_TLS_HSTYPE_SERVERHELLO))
  {
    if (mandatoryExtensionsInServerHelloArePresent == FALSE)
    {
      /* In TLS version 1.3 there are mandatory extensions in the ServerHello - check if they are there */
      retVal = E_NOT_OK;
    }
    if (preSharedKeyInServerHelloIsPresent == FALSE)
    {
      /* Do an ECC handshake, valid case (fallback scenario). */
      TcpIp_SetSessionResumptionUsingPskOfTlsConnectionDyn(TlsConIdx, FALSE);
    }
  }
#  endif

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_OFF)
  TCPIP_DUMMY_STATEMENT(SourceMessage);                                                                                 /* PRQA S 1338, 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
#  endif

  return retVal;
} /* TcpIp_TlsClientMsg_ServerMsgParseReceivedExtensions() */

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ServerHelloParseExtensionEcPointFormat
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloParseExtensionEcPointFormat(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType EcPointFormatExtension)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 ecPointFormatIter;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* RFC8422 - 5.2.  Server Hello Extension ec_point_Formats (11)(Supported Point Formats Extension)

   * The server's Supported Point Formats Extension has the same structure
   * as the client's Supported Point Formats Extension (see
   * Section 5.1.2).  Items in ec_point_format_list here are ordered
   * according to the server's preference (favorite choice first).  Note
   * that the server MAY include items that were not found in the client's
   * list.  However, without extensions, this specification allows exactly
   * one point format, so there is not really any opportunity for
   * mismatches.
   */
  /* Supported Point Formats Extension Format
                                +----> Length
                               /                          +--->  ordered values
                              /                          /
  *       [ext Type][ext Len][EC Point Format Len][EC Point Format_1][EC Point Format_2]...
  * Byte: 0       1 2      3                    4                   5                  6
  */
  uint8 ecPointFormatLen = IpBase_GetUint8(TcpIp_GetAddrTlsBufferRx(EcPointFormatExtension.StartIdx), 0);

  /* #10 Process received list only if the length match */
  if (   ( ecPointFormatLen != 0u) /* We MUST received at least one point format */
      && (((uint16)ecPointFormatLen + TCPIP_TLS_EXTENSION_EC_POINT_FORMAT_LENGTH_LEN) == EcPointFormatExtension.Length))
  {
    /* #20 Iterate over (possible) list of received ec Point formats and check if it contains the UNCOMPRESSED format */
    for (ecPointFormatIter = 0u; ecPointFormatIter < ecPointFormatLen; ecPointFormatIter++)
    {
      uint8 ecPointFormat = IpBase_GetUint8(TcpIp_GetAddrTlsBufferRx(
        EcPointFormatExtension.StartIdx + TCPIP_TLS_EXTENSION_EC_POINT_FORMAT_FIXED_LENGTH + ecPointFormatIter), 0);

      /* TLS-Client only support uncompressed formats */
      if (ecPointFormat == TCPIP_TLS_EXTENSION_EC_POINT_FORMAT_UNCOMPRESSED)
      {
        /* #30 List contains uncompressed formats - skip all other items in list and return E_OK */
        retVal = E_OK;
        break;
      }
    }
  }
  else
  {
    /* #40 Received length mismatch - report TLS-Alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
  }
  return retVal;
}
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ServerHelloParseExtensionCertificateStatusRequest
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
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloParseExtensionCertificateStatusRequest(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType CertificateStatusRequest)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  /* RFC6066 - 8.  Certificate Status Request
       If a server returns a "CertificateStatus" message, then the server MUST have included an
       extension of type "status_request" with empty "extension_data" in the extended server hello. */
  /* #10 In case the current connection is TLS 1.2 based */
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_12)
#   endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
  {
    /* #20 Check the received extension type and length */
    if (    (CertificateStatusRequest.Type == TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST)
         && (CertificateStatusRequest.Length == 0u))
    {
      /* Mandatory extension certificate status request received - reset the flag */
      TcpIp_SetMandatoryReceivedCertificateStatusRequestExtensionOfTlsConnectionDyn(TlsConIdx, FALSE);

      /* The client expects a ServerCertficateStatus message after the certificate - used during HsStm state */
      TcpIp_SetExpectServerCertificateStatusMessageOfTlsConnectionDyn(TlsConIdx, TRUE);

      retVal = E_OK;
    }
    /* received Type already checked by caller function */
  }
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  /* #30 In case the current connection is TLS 1.3 based */
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
#   endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
  {
    /* RFC8446 - section 4.4.2.1.  OCSP Status and SCT Extensions
     * The server may append a "status_request" extension of basic type to
     * each CertificateEntry of its server Certificate message. */
    /* #40 Handle the status_request extension in case it is not empty */
    if (   (CertificateStatusRequest.Type == TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST)
        && (CertificateStatusRequest.Length >= (TCPIP_TLS_CERTSTATUS_REQUESTTYPE_LEN + TCPIP_TLS_CERTSTATUS_OCSPRESPONSE_LEN)))
    {
      const TcpIp_TlsClientOcspBufferMgmtIterType validEndTlsClientOcspBufferMgmtIdx
        = TcpIp_GetTlsClientOcspBufferMgmtValidEndIdxOfTlsConnectionDyn(TlsConIdx);

      /* Check if OCSP response can be stored in temporary CSL data types */
      if (validEndTlsClientOcspBufferMgmtIdx < TcpIp_GetTlsClientOcspBufferMgmtEndIdxOfTlsConnection(TlsConIdx))
      {
        /* Get received certificate status request type */
        const uint8 receivedCertStatusType = IpBase_GetUint8(
          TcpIp_GetAddrTlsBufferRx(CertificateStatusRequest.StartIdx), 0);

        /* Get received certificate status request length */
        const uint32 receivedCertStatusLength = IpBase_GetUint24(
          TcpIp_GetAddrTlsBufferRx(CertificateStatusRequest.StartIdx),
          TCPIP_TLS_CERTSTATUS_REQUESTTYPE_LEN);

        /* #50 Process a status_request response which contains an OCSP response */
        if (   (receivedCertStatusType == TCPIP_TLS_CERTSTATUS_REQUESTTYPE_OCSP)
            && (receivedCertStatusLength ==
                  ((uint32)CertificateStatusRequest.Length - (TCPIP_TLS_CERTSTATUS_REQUESTTYPE_LEN + TCPIP_TLS_CERTSTATUS_OCSPRESPONSE_LEN))))
        {
          const TcpIp_TlsCertValidationStatusDynIterType currentTlsCertValidationStatusIdx
            = TcpIp_GetTlsCertValidationStatusDynValidEndIdxOfTlsConnectionDyn(TlsConIdx);

          TCPIP_CP2V(TcpIp_CertValidationStatusType) currentCertStatusPtr
            = TcpIp_GetAddrTlsCertValidationStatusDyn(currentTlsCertValidationStatusIdx);

          /* #60 Update OCSP connection status and set the OCSP mode */
          /* We did receive the OCSP Certificate status response */
          currentCertStatusPtr->CertStatusResponse.OcspConnectionState = TCPIP_TLS_OCSP_CONNECTION_STATE_STATUS_RECEIVED;

          /* Currently RFC6960 TLS status_request extension is supported */
          currentCertStatusPtr->CertStatusResponse.OcspMode = TCPIP_TLS_OCSP_MODE_TLS13;

          /* #70 Store the received OCSP response for later usage */
          /* Used in TcpIp_Tls13ClientCtx_ValidateCertificateStatus() */
          TcpIp_SetTlsBufferRxServerCertStatusResponseIdxOfTlsClientOcspBufferMgmt(
            validEndTlsClientOcspBufferMgmtIdx,
            (TcpIp_TlsBufferRxServerCertStatusResponseIdxOfTlsClientOcspBufferMgmtType)CertificateStatusRequest.StartIdx + TCPIP_TLS_CERTSTATUS_REQUESTTYPE_LEN + TCPIP_TLS_CERTSTATUS_OCSPRESPONSE_LEN);

          TcpIp_SetServerCertStatusResponseLenOfTlsClientOcspBufferMgmt(
            validEndTlsClientOcspBufferMgmtIdx, receivedCertStatusLength);

          retVal = E_OK;
        }
        else
        {
          /* Invalid OCSP response - Trigger alert */
          TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_BAD_CERT_STATUS_RESP);
        }
      }
    }
    else
    {
      /* Invalid extension - Trigger alert */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_BAD_CERT_STATUS_RESP);
    }
  }
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */

  return retVal;
} /* TcpIp_TlsClientMsg_ServerHelloParseExtensionCertificateStatusRequest() */

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ServerHelloParseExtensionTrustedCaIndication
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloParseExtensionTrustedCaIndication(
  TcpIp_TlsExtensionType TrustedCaIndication)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* RFC6066 - 6.  Trusted CA Indication
       Servers that receive a client hello containing the "trusted_ca_keys"
       extension MAY use the information contained in the extension to guide
       their selection of an appropriate certificate chain to return to the
       client.  In this event, the server SHALL include an extension of type
       "trusted_ca_keys" in the (extended) server hello. The
       "extension_data" field of this extension SHALL be empty. */

  /* #10 Check the received extension length */
  if (TrustedCaIndication.Length == 0u)
  {
    /* The "extension_data" field of this extension SHALL be empty. */
    retVal = E_OK;
  }

  return retVal;
} /* TcpIp_TlsClientMsg_ServerHelloParseExtensionTrustedCaIndication */
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ServerHelloParseExtensionServerNameIndication
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloParseExtensionServerNameIndication(
  TcpIp_TlsExtensionType ServerNameIndication)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* RFC6066 - 3.  Server Name Indication
   *   A server that receives a client hello containing the "server_name"
   *   extension MAY use the information contained in the extension to guide
   *   its selection of an appropriate certificate to return to the client,
   *   and/or other aspects of security policy. In this event, the server
   *   SHALL include an extension of type "server_name" in the (extended)
   *   server hello. The "extension_data" field of this extension SHALL be
   *   empty. */

   /* #10 Check the received extension length */
  if (ServerNameIndication.Length == 0u)
  {
    /* The "extension_data" field of this extension SHALL be empty. */
    retVal = E_OK;
  }

  return retVal;
} /* TcpIp_TlsClientMsg_ServerHelloParseExtensionServerNameIndication */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ServerHelloDetermineNextState
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloDetermineNextState(
  TcpIp_TlsConnectionIterType        TlsConIdx,
  TCPIP_P2V(TcpIp_TlsHandshakeState) NextStatePtr)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Determine next handshake state depending on key exchange mode */
  switch (TcpIp_TlsClientHsStm_ReturnReceivedCipherSpecificKeyExchangeMethod(TlsConIdx))
  {
#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
    case TCPIP_TLS_KEYEXCHANGE_METHOD_ECDHE:
    case TCPIP_TLS_KEYEXCHANGE_METHOD_ECDH:  /* ECDH can only occur if the active TLS protocol version is 1.2. */
    {
      /* #20 In case of ECDHE or ECDH we expect the message ServerCertificate or EncryptedExtensions, depending on the active TLS protocol version. */
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#    if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)                                                                    /* COV_MSR_UNSUPPORTED */
      if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_12)
#    endif
      {
        /* Active TLS protocol version is 1.2. */
        *NextStatePtr = TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE;
      }
#    if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)                                                                    /* COV_MSR_UNSUPPORTED */
      else
#    endif
#   endif
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)                                                                     /* COV_MSR_UNSUPPORTED */
      {
        /* Active TLS protocol version is 1.3. */
        *NextStatePtr = TCPIP_TLS_STATE_WAIT_FOR_ENCRYPTED_EXTENSIONS;
      }
#   endif

      TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx,
        TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_PARSING_DONE);
      break;
    }
#  endif
    case TCPIP_TLS_KEYEXCHANGE_METHOD_PSK_PLAIN:
    {
      /* #30 in case of plain PSK, we have to switch the state depending on the received next server message */
      TcpIp_TlsClientMsg_ServerHelloDetermineNextStatePsk(TlsConIdx, NextStatePtr);
      break;
    }
    default:
    {
      /* #40 otherwise, invalid key exchange method. */
      /* Invalid key exchange method. This can never happen, a valid key exchange method has been chosen with the active
      cipher suite received in the server_hello message. */
      break;
    }
  }  /* switch */

} /* TcpIp_TlsClientMsg_ServerHelloDetermineNextState() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ServerHelloDetermineNextStatePsk
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
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloDetermineNextStatePsk(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(TcpIp_TlsHandshakeState) NextStatePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxServerKeyExchangeIdxOfTlsClientBufferMgmtType serverKeyExchangeIdx
    = TcpIp_GetTlsBufferRxServerKeyExchangeIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  TcpIp_TlsBufferRxServerCertificatesIdxOfTlsClientBufferMgmtType serverCertificateIdx
    = TcpIp_GetTlsBufferRxServerCertificatesIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  TcpIp_TlsBufferRxServerCertificateStatusIdxOfTlsClientBufferMgmtType serverCertificateStatusIdx
    = TcpIp_GetTlsBufferRxServerCertificateStatusIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  TcpIp_TlsBufferRxServerCertificateRequestIdxOfTlsClientBufferMgmtType serverCertificateRequestIdx
    = TcpIp_GetTlsBufferRxServerCertificateRequestIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  TcpIp_TlsBufferRxServerHelloDoneIdxOfTlsClientBufferMgmtType serverHelloDoneIdx
    = TcpIp_GetTlsBufferRxServerHelloDoneIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* Reset the context state - in case we did not receive the next message, this will be overwritten to WAIT_CYCLE */
  /* If the next message is received, we must reset it to NO_ASYNC */
  TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_NO_ASYNC);

  /* #10 Check if we already receive the next messages (ServerKeyExchange or ServerHelloDone or ServerCertificate)
         and set the next TLS-Handshake state */
  if (   (serverCertificateIdx != TCPIP_NO_TLSBUFFERRXSERVERCERTIFICATESIDXOFTLSCLIENTBUFFERMGMT)
      || (serverCertificateStatusIdx != TCPIP_NO_TLSBUFFERRXSERVERCERTIFICATESTATUSIDXOFTLSCLIENTBUFFERMGMT)
      || (serverCertificateRequestIdx != TCPIP_NO_TLSBUFFERRXSERVERCERTIFICATEREQUESTIDXOFTLSCLIENTBUFFERMGMT))
  {
    /* #20 If either ServerCertificate, a Certificate Status or a Certificate Status Request message is received,
     * we have to trigger a TLS alert because PSK do not support Certificate handling. */

    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);

    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_ABORT);

  }
  else if (   (serverKeyExchangeIdx == TCPIP_NO_TLSBUFFERRXSERVERKEYEXCHANGEIDXOFTLSCLIENTBUFFERMGMT)
           && (serverHelloDoneIdx   == TCPIP_NO_TLSBUFFERRXSERVERHELLODONEIDXOFTLSCLIENTBUFFERMGMT))
  {
    /* #30 If no message is received yet, wait until next main function. */
    /* Neither the ServerCertificate, ServerKeyExchange message nor the ServerHelloDone message are received,
     * so we can not determine the next state.
     * Wait until next main function cycle to determine next state. */
    TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_WAIT_CYCLE);
  }
  else if (serverKeyExchangeIdx != TCPIP_NO_TLSBUFFERRXSERVERKEYEXCHANGEIDXOFTLSCLIENTBUFFERMGMT)
  {
    /* #40 If we receive a ServerKeyExchange (PSK hint), so we have to process this message */
    *NextStatePtr = TCPIP_TLS_STATE_WAIT_FOR_SERVER_KEY_EXCHANGE;

    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx,
      TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_PARSING_DONE);
  }
  else /* No ServerKeyExchange but ServerHelloDone */
  {
    /* #50 We receive at least a ServerHelloDone, so next state is TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_DONE */
    *NextStatePtr = TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_DONE;

    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx,
      TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_PARSING_DONE);
  }
} /* TcpIp_TlsClientMsg_ServerHelloDetermineNextStatePsk() */

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ServerCertMsgHandleFailedCertGroupValidation
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
FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ServerCertMsgHandleFailedCertGroupValidation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ---------------------------------------------- */
  /* #10 Update Hs certificate state to finished as no further certificate processing will be done */
  /* [HS Server Certificate Chain Handling StM] Certificates loaded successfully and but verification failed */
  TcpIp_SetHsCertStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CERTCHAIN_VERIFY_FAILED);

  /* #20 Received server certificate with unknown CA - trigger TLS error indication */
  TcpIp_TlsCoreError_IndicationTrigger(TlsConIdx, TCPIP_TLS_E_UNKNOWN_CA, TCPIP_TLS_ALERT_UNSET);

  /* #30 Trigger alert. Either no matching root cert was found, or cert chain is not consistent in itself. */
  TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNKNOWN_CA);

  /* Update status for certificate chain. Ignore return value because we know that the chain is invalid and the
     handshake will be canceled anyway. */
  (void)TcpIp_TlsCoreUtil_TlsUpdateCertChainStatus(TlsConIdx, TCPIP_TLS_UPDATE_CERT_MODE_CHAIN);

  TcpIp_SetTlsCertValidationResultOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_VALIDATION_NOT_OK);

  /* #40 Issue validation callback */
  TcpIp_TlsClient_TlsCertChainTriggerValidationCallback(TlsConIdx, FALSE);
} /* TcpIp_TlsClientMsg_ServerCertMsgHandleFailedCertGroupValidation */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_ResetCertChainStates
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
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_ResetCertChainStates(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx
    = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Reset overall validation result */
  TcpIp_SetTlsCertValidationResultOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_VALIDATION_UNKNOWN);

  /* #20 Reset OCSP values */
  TcpIp_SetMandatoryReceivedCertificateStatusRequestExtensionOfTlsConnectionDyn(TlsConIdx, FALSE);

  TcpIp_SetExpectServerCertificateStatusMessageOfTlsConnectionDyn(TlsConIdx, FALSE);

  /* #30 Reset OCSP information for each connection */
  {
    TcpIp_TlsClientOcspBufferMgmtIterType tlsClientOcspBufferMgmtIdx = 0u;

    for (tlsClientOcspBufferMgmtIdx = TcpIp_GetTlsClientOcspBufferMgmtStartIdxOfTlsConnection(TlsConIdx);
         tlsClientOcspBufferMgmtIdx < (TcpIp_TlsClientOcspBufferMgmtIterType)TcpIp_GetTlsClientOcspBufferMgmtEndIdxOfTlsConnection(TlsConIdx);
         tlsClientOcspBufferMgmtIdx++)
    {
      TcpIp_SetServerCertStatusResponseLenOfTlsClientOcspBufferMgmt(tlsClientOcspBufferMgmtIdx, 0);
      TcpIp_SetTlsBufferRxServerCertStatusResponseIdxOfTlsClientOcspBufferMgmt(tlsClientOcspBufferMgmtIdx, 0);
    }

    TcpIp_SetTlsClientOcspBufferMgmtCurrentIdxOfTlsConnectionDyn(TlsConIdx,
      TcpIp_GetTlsClientOcspBufferMgmtStartIdxOfTlsConnection(TlsConIdx));
    TcpIp_SetTlsClientOcspBufferMgmtValidEndIdxOfTlsConnectionDyn(TlsConIdx,
      TcpIp_GetTlsClientOcspBufferMgmtStartIdxOfTlsConnection(TlsConIdx));
  }

  /* #40 Set the ID of the issuer of the certificate to invalid, since it is not known yet. */
  TcpIp_SetRootCertIdOfTlsClientConnection(tlsClientConnectionIdx, TCPIP_CERTID_INV);

  /* #50 Reset the flag to send a client certificate verify message */
  TcpIp_SetSendCertificateVerifyOfTlsClientConnection(tlsClientConnectionIdx, FALSE);

} /* TcpIp_TlsClient_ResetCertChainStates */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ServerCertMsgVerifyCertificateGroup
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
 */
 /* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerCertMsgVerifyCertificateGroup(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Update the KeyM status of each certificate */
  if (TcpIp_TlsCoreUtil_TlsUpdateCertChainStatus(TlsConIdx, TCPIP_TLS_UPDATE_CERT_MODE_CHAIN) == E_OK)
  {
    TcpIp_CertValidationResultType result;

    /* #20 Try to obtain overall validation result and update states */
    TcpIp_TlsCoreUtil_TlsUpdateOverallCertValidationResult(TlsConIdx, &result);

    /* Store the certificate status for invoking validation callback to upper layer later */
    TcpIp_SetTlsCertValidationResultOfTlsConnectionDyn(TlsConIdx, result);

    /* Set certificate chain validation state to finished */
    /* [HS Server Certificate Chain Handling StM] Certificate verification is finished */
    TcpIp_SetHsCertStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CERTCHAIN_FINISHED);

    /* Set the async state to DONE */
    TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);

    /* #30 Check the active TLS version. */
    if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_12)
    {
      /* #40 In case active TLS version is 1.2, check if the overall validation result is OK or NOT_OK.
         If it is NOT_OK check if the validation callback needs to be called here or later. */
      TcpIp_TlsClientMsg_ServerCertMsgCheckCertChainOverallResult(TlsConIdx, result);
    }
    else
    {
      /* #50 In case active TLS version is 1.3, do nothing because the check will be done after processing of OCSP responses. */
    }

    retVal = E_OK;
  }
  else
  {
    /* #60 TlsUpdateCertChainStatus failed, something is wrong with the certificates. Cancel the handshake. */
    /* retVal is already E_NOT_OK */
  }

  return retVal;
} /* TcpIp_TlsClientMsg_ServerCertMsgVerifyCertificateGroup */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_ServerCertMsgCheckCertChainOverallResult
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ServerCertMsgCheckCertChainOverallResult(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_CertValidationResultType Result)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the overall validation result is OK or NOT_OK. */
  if (Result == TCPIP_TLS_VALIDATION_NOT_OK)
  {
    /* The overall result is NOT_OK.
       Find out if we can allow the upper layer to overrule this result, or if the handshake has to be canceled
       here.

       The only (negative) condition we can allow to be overruled is a good cert chain with a self-signed root. In
       all other cases the handshake shall be canceled immediately.
    */

    TcpIp_TlsAlertDescriptionType alertDescription;
    boolean cancelHandshake = TRUE;

    TcpIp_TlsCoreUtil_TlsGetAlertForBadCertificateChain(TlsConIdx, &alertDescription);

    /* #20 Check if the handshake shall be canceled immediately or later when processing ServerHelloDone / ServerFinished. */
    /* If we have a valid cert chain but with an unknown CA, we continue with the handshake. Later when processing
       the ServerHelloDone (TLS 1.2 case) / ServerFinished (TLS 1.3 case) message the handshake will be canceled
       if the socket owner does not overrule this decision in the validation callback (if configured).
       In all other cases the handshake is canceled here immediately. */
    if (alertDescription == TCPIP_TLS_ALERT_DESC_UNKNOWN_CA)
    {
      TcpIp_TlsCertValidationStatusDynIterType lastTlsCertValidationStatusIdx;  /* status index of the last received cert in the cert chain */
      boolean lastCertIsSelfSigned;

      lastTlsCertValidationStatusIdx = (TcpIp_GetTlsCertValidationStatusDynValidEndIdxOfTlsConnectionDyn(TlsConIdx) - 1u);
      lastCertIsSelfSigned = TcpIp_GetAddrTlsCertValidationStatusDyn(lastTlsCertValidationStatusIdx)->IsSelfSigned;

      if (lastCertIsSelfSigned == TRUE)
      {
        /* ok, this is an acceptable condition.
         * Validation callback will be called when processing HelloDone / ServerFinished. */
        cancelHandshake = FALSE;
      }
    }

    if (alertDescription == TCPIP_TLS_ALERT_DESC_CERT_EXPIRED)
    {
      /* Received server certificate is expired - trigger TLS error indication */
      TcpIp_TlsCoreError_IndicationTrigger(TlsConIdx, TCPIP_TLS_E_SERVER_CERT_EXPIRED, TCPIP_TLS_ALERT_UNSET);
    }

    if (cancelHandshake == TRUE)
    {
      /* #30 The handshake has to be canceled immediately. Call validation callback to provide details to the socket owner. */
      TcpIp_TlsClient_TlsCertChainTriggerValidationCallback(TlsConIdx, FALSE);
    }
  }
} /* TcpIp_TlsClientMsg_ServerCertMsgCheckCertChainOverallResult() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_StoreReceivedRootCertId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_StoreReceivedRootCertId(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* #10 Store the root Certificate ID. */
  TcpIp_TlsCertValidationStatusDynIterType tlsCertValidationStatusIdx;
  TCPIP_P2C(TcpIp_CertValidationStatusType) certStatusPtr;
  TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);
  TcpIp_CertificateIdType tlsClientRootCertId = TcpIp_GetRootCertIdOfTlsClientConnection(tlsClientConnectionIdx);

  /* Get the ID of the last certificate in the received chain. */
  tlsCertValidationStatusIdx = TcpIp_GetTlsCertValidationStatusDynValidEndIdxOfTlsConnectionDyn(TlsConIdx) - 1u;
  certStatusPtr = TcpIp_GetAddrTlsCertValidationStatusDyn(tlsCertValidationStatusIdx);

  /* Check if the certificate is self signed. */
  if (certStatusPtr->IsSelfSigned == FALSE)
  {
    /* Check if the certificate is valid. */
    if ((certStatusPtr->CertStatus == KEYM_CERTIFICATE_VALID))
    {
      /* Store the ID of the issuer certificate. */
      if (KeyM_GetIssuerCertId(certStatusPtr->CertId, &tlsClientRootCertId) == E_OK)
      {
        TcpIp_SetRootCertIdOfTlsClientConnection(tlsClientConnectionIdx, tlsClientRootCertId);
      }
      else
      {
        /* Storing not successful. ID is set to invalid. */
        TcpIp_SetRootCertIdOfTlsClientConnection(tlsClientConnectionIdx, TCPIP_CERTID_INV);
      }
    }
  }
} /* TcpIp_TlsClient_StoreReceivedRootCertId() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_TlsCertChainTriggerValidationCallback
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
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_TlsCertChainTriggerValidationCallback(
  TcpIp_TlsConnectionIterType                 TlsConIdx,
  boolean AllowOverrule)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* Socket owner */
  TcpIp_SizeOfSocketOwnerConfigType  socketOwnerConfigIdx = TcpIp_GetSocketOwnerConfigIdxOfTlsConnectionDyn(TlsConIdx);

  /* Socket Idx */
  TcpIp_SizeOfSocketDynType socketIdx = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_SocketOwnerTlsValidationResultType tlsValidationResultFuncPtr
    = TcpIp_GetTlsValidationResultFuncPtrOfSocketOwnerConfig(socketOwnerConfigIdx);

  /* Number of certificates in the received chain */
  TcpIp_SizeOfTlsCertValidationStatusDynType  numCerts =
    TcpIp_GetTlsCertValidationStatusDynValidEndIdxOfTlsConnectionDyn(TlsConIdx) - TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx);

  /* Overall Validation result of the certificate chain */
  TcpIp_CertValidationResultType  validationResult = TcpIp_GetTlsCertValidationResultOfTlsConnectionDyn(TlsConIdx);

  /* Start Idx of the certificate status structure */
  TcpIp_TlsCertValidationStatusDynIterType tlsCertValidationStatusIdx = TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx);


  /* ----- Implementation ----------------------------------------------- */
  /* #10 If configured, notify socket owner about the certificate validation result. The socket owner can change the validation result. */
  if (tlsValidationResultFuncPtr != NULL_PTR)
  {
    TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx =
      TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));
    TcpIp_TlsClientConnectionIdxOfTlsConnectionType tlsClientConnectionIdx =
      TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

    TcpIp_TlsConnectionInfoType tlsConInfo; /* Tls connection info */
    tlsConInfo.RootCertId = TcpIp_GetRootCertIdOfTlsClientConnection(tlsClientConnectionIdx);
    tlsConInfo.CipherSuiteId = TcpIp_GetReceivedCipherSuiteIdOfTlsClientConnection(tlsClientConnectionIdx);
    tlsConInfo.SigAlgoId = TcpIp_GetSignatureAlgorithmIdOfTlsHandshake(activeTlsHandshakeIdx);
    tlsConInfo.TlsVersion = TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx);

    tlsValidationResultFuncPtr(TCPIP_SOCKET_IDX_TO_ID(socketIdx),
      numCerts, TcpIp_GetAddrTlsCertValidationStatusDyn(tlsCertValidationStatusIdx), &validationResult, &tlsConInfo);
  }

  /* #20 Check if the socket owner overruled the result even if it was not allowed. */
  if ((AllowOverrule == FALSE) && (validationResult == TCPIP_TLS_VALIDATION_OK))
  {
    /* When overruling is not allowed, the result must always stay NOT_OK. Reset the result to NOT_OK. */
    validationResult = TCPIP_TLS_VALIDATION_NOT_OK;
  }

  /* #30 Check the validation result and proceed with finalizing handshake */
  if (validationResult == TCPIP_TLS_VALIDATION_OK)
  {
    /* #40 If certificate validation done successfully, set state to complete */
    /* [HS Server Certificate Chain Handling StM] Certificate has been validated successfully, all steps are complete */
    TcpIp_SetHsCertStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CERTCHAIN_COMPLETE);
  }
  else
  {
    TcpIp_TlsAlertLevelType  alertLevel;
    TcpIp_TlsAlertDescriptionType  alertDescription;

    /* #50 If certificate validation was unsuccessful, reset state to INIT */
    /* [HS Server Certificate Chain Handling StM] Certificate not validated successfully, reset StM */
    TcpIp_SetHsCertStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CERTCHAIN_INIT);

    /* Alert level is always set to fatal */
    alertLevel = TCPIP_TLS_ALERT_LEVEL_FATAL;
    /* Determine the appropriate alert description */
    TcpIp_TlsCoreUtil_TlsGetAlertForBadCertificateChain(TlsConIdx, &alertDescription);

    /* Trigger the transmission of the occurred alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, alertLevel, alertDescription);
  }
} /* TcpIp_TlsClient_TlsCertChainTriggerValidationCallback() */
#  endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsClientTx_SendChangeCipherSpec
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(void, TCPIP_CODE) TcpIp_TlsClientTx_SendChangeCipherSpec(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx
    = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_TlsCipherDefinitionIdxOfTlsCipherWorkerType tlsCipherDefinitionIdx
    = TcpIp_GetTlsCipherDefinitionIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx);

  TcpIp_CipherSuiteIdOfTlsCipherDefinitionType selectedCipherSuiteId
    = TcpIp_GetCipherSuiteIdOfTlsCipherDefinition(tlsCipherDefinitionIdx); /* Get the corresponding Cipher Id (HexCode) */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Write the payload (0x01) to the write index of the TLS TX CCS Buffer */
  IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxCcsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx)), 0,
                    TCPIP_TLS_CHANGECIPHERSPEC);

  /* #20 Transmit the frame */
  if (TcpIp_TlsCoreRl_Transmit(TlsConIdx,
    TcpIp_GetTlsBufferTxCcsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx), TCPIP_TLS_CCSMSG_LEN, TCPIP_TLS_CT_CCS) == E_OK)
  {
    /* Reset the Transmit Flag */
    TcpIp_SetChangeCipherSpecReadyToSendOfTlsClientConnection(tlsClientConnectionIdx, FALSE);

    /* Note, there is no need to increment the write index here, since this is the only CCS message */

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_12)
#  endif
    {
      TcpIp_SetActiveCipherTxOfTlsConnectionDyn(TlsConIdx, selectedCipherSuiteId);
    }
  }
} /* TcpIp_TlsClientTx_SendChangeCipherSpec() */

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_CertVerifyEncodeSignature
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_CertVerifyEncodeSignature(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtDynIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx =
    TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

  uint8 consumedLen = 0u;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Forward the encoding of the generated signature to the curve specific encoder function */
  switch (TcpIp_GetSignatureAlgorithmIdOfTlsHandshake(activeTlsHandshakeIdx))
  {
    case TCPIP_SIG_ALGO_ID_ECDSA_SECP256R1_SHA256:
    case TCPIP_SIG_ALGO_ID_ECDSA_SECP521R1_SHA512:
    {
      /* Encoding for SECP based signatures */
      TcpIp_TlsCoreMsg_EncodeSecpSignature(TlsConIdx, &consumedLen);
      break;
    }
    case TCPIP_SIG_ALGO_ID_ECDSA_ED25519_INTRINSIC:
    {
      /* Encoding for ED25519 based signatures */
      TcpIp_TlsCoreMsg_EncodeEd25519Signature(TlsConIdx, &consumedLen);
      break;
    }
    case TCPIP_SIG_ALGO_ID_ECDSA_ED448_INTRINSIC:
    {
      /* Encoding for ED448 based signatures */
      TcpIp_TlsCoreMsg_EncodeEd448Signature(TlsConIdx, &consumedLen);
      break;
    }
    default:                                                                                                            /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
    {
      /* Not (yet) supported algorithms:
      - TCPIP_SIG_ALGO_ID_RSA_PKCS1_SHA256
      - TCPIP_SIG_ALGO_ID_RSA_PKCS1_SHA384
      - TCPIP_SIG_ALGO_ID_RSA_PKCS1_SHA512
      - TCPIP_SIG_ALGO_ID_ECDSA_SECP384R1_SHA384
      - TCPIP_SIG_ALGO_ID_ECDSA_ED448_INTRINSIC
      - ...
      */

      /* Default case is never reached because a valid / supported algorithm was already chosen before  - left blank intentionally */
      TCPIP_ASSERT_UNREACHABLE();
      break;
    }
  } /* switch */

  /* #20 Update the length of the encoded signature */
  IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(
    TcpIp_GetTlsBufferTxClientCertVerifySignatureLenIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx)), 0u, consumedLen);

  /* Maintain AdHs write index by incrementing the consumed length */
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx, consumedLen);
} /* TcpIp_TlsClientMsg_CertVerifyEncodeSignature() */
#  endif

/**********************************************************************************************************************
 *  TcpIp_TlsClient_ProcessHandshake
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_ProcessHandshake(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the current connection is in an active HS state */
  if ((TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx)) == (TCPIP_TLS_STATE_CONNECTION_HS_ACTIVE))
  {
    /* #20 Check that there is no async operation in process */
    if (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_ASYNC_PENDING)
    {
      /* #30 Check if we have at least one trigger to process the HS */
      if (   (TcpIp_IsHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx) == TRUE)          /* Next state is a TX state */      /* PRQA S 3415 3 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
          || (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_DONE)       /* AsyncCtx operation is done, continue HS */
          || (TcpIp_GetHsRxIndicationCntOfTlsConnectionDyn(TlsConIdx) != 0u)                     /* unprocessed HS message in the buffer */
          || (TcpIp_IsCcsRxIndicationOfTlsConnectionDyn(TlsConIdx) == TRUE))                     /* unprocessed CCS message in the buffer */
      {
        /* #40 Depending on the active TLS version relegate to a different state machine. */
        TcpIp_TlsClientHsStm_ForwardToStateMachineForActiveVersion(TlsConIdx);
      } /* else, do nothing */
    } /* else, do nothing */
  } /* else, do nothing */
} /* TcpIp_TlsClient_ProcessHandshake() */

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsClient_ProcessConnection
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_ProcessConnection(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the TLS connection is a resumption base connection. */
  if (TcpIp_TlsClient_IsResumptionBaseConnection(TlsConIdx) == TRUE)
  {
    TcpIp_TlsClientConnectionIdxOfTlsConnectionType tlsClientConnectionIdx
      = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

    TcpIp_Tls13PskIdentityIndIterType tls13PskIdentityIndIdx
      = TcpIp_GetTls13PskIdentityIndStartIdxOfTlsConnection(TlsConIdx);

    /* #20 Check if the resumption base connection reached its max age. */
    if (TcpIp_GetResumptionBaseConnectionAgeOfTlsClientConnection(tlsClientConnectionIdx) != 0u)
    {
      /* Increment the age */
      TcpIp_IncResumptionBaseConnectionAgeOfTlsClientConnection(tlsClientConnectionIdx);
    }

    /* #30 Check and maintain the age of all session tickets / PSK identities. */
    for (; tls13PskIdentityIndIdx < TcpIp_GetTls13PskIdentityIndEndIdxOfTlsConnection(TlsConIdx);
           tls13PskIdentityIndIdx++)
    {
      TcpIp_Tls13PskIdentityIndType tls13PskIdentityIdx = TcpIp_GetTls13PskIdentityInd(tls13PskIdentityIndIdx);
      TcpIp_Tls13Client_MaintainSessionTicketAge(TlsConIdx, tls13PskIdentityIdx);
    }
  }
}

/**********************************************************************************************************************
 *  TcpIp_TlsClient_IsResumptionBaseConnection
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, TCPIP_CODE) TcpIp_TlsClient_IsResumptionBaseConnection(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if TLS connection is a resumption base connection. */
  if (   (TcpIp_IsCsmKeyIdResumptionMasterSecretUsedOfTlsConnection(TlsConIdx) == TRUE)  /* support session resumption */
      && (TcpIp_IsTls13PskIdentityIndUsedOfTlsConnection(TlsConIdx) == TRUE))  /* has TLS 1.3 PSK identity references */
  {
    retVal = TRUE;
  }
  return retVal;
}
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsClientHsStm_ForwardToStateMachineForActiveVersion
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientHsStm_ForwardToStateMachineForActiveVersion(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Depending on the active TLS version forward to a different state machine. */
  if (TcpIp_IsVersionSpecificHsStmTriggerOfTlsConnectionDyn(TlsConIdx) == FALSE)
  {
    /* The common state machine for both TLS 1.2 and TLS 1.3 shall still be processed.
     * This means, the state machine is still in the state 'Send ClientHello' or 'Wait for ServerHello'.
     * This part of the handshake does not behave differently between versions. */
    /* #20 Call the common state machine. */
    TcpIp_TlsClientHsStm_PerformNextHsStep(TlsConIdx);
  }
  else
  {
    /* #30 Depending on the active TLS version forward to the protocol specific state machine. */
#  if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#   if(TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_12)
#   endif
    {
      /* #40 The active version is set to 1.2. Call the 1.2 state machine. */
      TcpIp_Tls12ClientHsStm_PerformNextHsStep(TlsConIdx);
    }
#  endif
#  if(TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#   if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
    else /* TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13 */
#   endif
    {
      /* #50 The active version is set to 1.3. Call the 1.3 state machine. */
      TcpIp_Tls13ClientHsStm_PerformNextHsStep(TlsConIdx);
    }
#  endif
  }
} /* TcpIp_TlsClientHsStm_ForwardToStateMachineForActiveVersion() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientHsStm_PerformNextHsStep
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientHsStm_PerformNextHsStep(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Process the TLS-CLient Handshake depending on the current state */
  uint16 hsState = TCPIP_TLS_GET_HS_STATE(TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx));
  switch ((TcpIp_TlsHandshakeState)hsState)
  {
    case TCPIP_TLS_STATE_HANDSHAKE_INIT:
    {
      TcpIp_TlsClient_HandshakeInitCipherWorkingSets(TlsConIdx);
      break;
    }
    case TCPIP_TLS_STATE_SEND_CLIENT_HELLO:
    {
      TcpIp_TlsClientHsStm_SendClientHello(TlsConIdx);
      break;
    }
    case TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO:
    {
      TcpIp_TlsClientHsStm_ParseServerHello(TlsConIdx);
      break;
    }
    default:                                                                                                           /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
    {
      break;
    }
  } /* switch() */
} /* TcpIp_TlsClientHsStm_PerformNextHsStep() */

/**********************************************************************************************************************
 *   TLS CLIENT HS TRIGGER SM
 *********************************************************************************************************************/
 /**********************************************************************************************************************
 *  TcpIp_TlsClientTx_CheckForTransmittableProcessedHsMsg
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
FUNC(void, TCPIP_CODE) TcpIp_TlsClientTx_CheckForTransmittableProcessedHsMsg(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);
  boolean processFurtherHsMsg = TRUE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the ClientHello message is transmittable */
  if (TcpIp_IsHelloReadyToSendOfTlsClientConnection(tlsClientConnectionIdx) == TRUE)
  {
    /* If so, forward ClientHello message to the record layer */
    processFurtherHsMsg = TcpIp_TlsClientTx_ForwardProcessedHsMsgToRl(TlsConIdx, TCPIP_TLS_HSTYPE_CLIENTHELLO);
  }
  /* #20 Check if the ClientCertificate message is transmittable */
  if (   (processFurtherHsMsg == TRUE)
      && (TcpIp_IsClientCertificateReadyToSendOfTlsClientConnection(tlsClientConnectionIdx) == TRUE))
  {
    /* If so, forward ClientCertificate message to the record layer */
    processFurtherHsMsg = TcpIp_TlsClientTx_ForwardProcessedHsMsgToRl(TlsConIdx, TCPIP_TLS_HSTYPE_CERTIFICATE);
  }
  /* #30 Check if the ClientKeyExchange message is transmittable */
  if ((processFurtherHsMsg == TRUE)
    && (TcpIp_IsKeyExchangeReadyToSendOfTlsClientConnection(tlsClientConnectionIdx) == TRUE))
  {
    /* If so, forward ClientKeyExchange message to the record layer */
    processFurtherHsMsg = TcpIp_TlsClientTx_ForwardProcessedHsMsgToRl(TlsConIdx, TCPIP_TLS_HSTYPE_CLIENTKEYEXCHANGE);
  }
  /* #40 Check if the CertificateVerify message is transmittable */
  if ((processFurtherHsMsg == TRUE)
    && (TcpIp_IsCertificateVerifyReadyToSendOfTlsClientConnection(tlsClientConnectionIdx) == TRUE))
  {
    /* If so, forward CertificateVerify message to the record layer */
    processFurtherHsMsg = TcpIp_TlsClientTx_ForwardProcessedHsMsgToRl(TlsConIdx, TCPIP_TLS_HSTYPE_CERTIFICATEVERIFY);
  }
  /* #50 Check if the ClientFinished message is transmittable */
  /* When the transmit of the CCS fails, the decryption won't be enabled.
   * If somehow the transmit of the Finished message works we will send unencrypted data.
   * To avoid this check if the CCS flag is already set to false which means the CCS was transmitted successfully. */
  if (   (processFurtherHsMsg == TRUE)
      && (TcpIp_IsClientFinishedReadyToSendOfTlsClientConnection(tlsClientConnectionIdx) == TRUE)
      && (TcpIp_IsChangeCipherSpecReadyToSendOfTlsClientConnection(tlsClientConnectionIdx) == FALSE))
  {
    /* If so, forward ClientFinished message to the record layer; the return value is disregarded */
    (void) TcpIp_TlsClientTx_ForwardProcessedHsMsgToRl(TlsConIdx, TCPIP_TLS_HSTYPE_FINISHED);
  }
} /* TcpIp_TlsClientTx_CheckForTransmittableProcessedHsMsg() */

/**********************************************************************************************************************
 *  TcpIp_TlsClientTx_ForwardProcessedHsMsgToRl
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050, 6030 1 */ /* MD_TcpIp_STCAL_CslAccess, MD_TcpIp_TlsStatemachine_STCYC_6030 */
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsClientTx_ForwardProcessedHsMsgToRl(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(TcpIp_TlsMsgHandshakeType, AUTOMATIC) HandshakeType)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);
  boolean processFurtherHsMsg = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Forward the different handshake messages to the record layer depending on the passed HandshakeType */
  switch (HandshakeType)
  {
    case TCPIP_TLS_HSTYPE_CLIENTHELLO:
    {
      /* Forward the ClientHello message to the record layer */
      if (TcpIp_TlsCoreRl_Transmit(TlsConIdx, TcpIp_GetTlsBufferTxClientHelloIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx),
        TcpIp_GetClientHelloLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx), TCPIP_TLS_CT_HS) == E_OK)
      {
        /* If successful, reset the TX indication flag for this message */
        TcpIp_SetHelloReadyToSendOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
        processFurtherHsMsg = TRUE;
      }
      break;
    } /* case TCPIP_TLS_HSTYPE_CLIENTHELLO */

    case TCPIP_TLS_HSTYPE_CERTIFICATE:
    {
      /* Forward the ClientCertificate message to the record layer */
      if (TcpIp_TlsCoreRl_Transmit(TlsConIdx, TcpIp_GetTlsBufferTxClientCertificateIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx),
        TcpIp_GetClientCertificateLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx), TCPIP_TLS_CT_HS) == E_OK)
      {
        /* If successful, reset the TX indication flag for this message */
        TcpIp_SetClientCertificateReadyToSendOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
        processFurtherHsMsg = TRUE;
      }
      break;
    } /* case TCPIP_TLS_HSTYPE_CERTIFICATE */

    case TCPIP_TLS_HSTYPE_CLIENTKEYEXCHANGE:
    {
      /* Forward the ClientKeyExchange message to the record layer */
      if (TcpIp_TlsCoreRl_Transmit(TlsConIdx, TcpIp_GetTlsBufferTxClientKeyExchangeIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx),
        TcpIp_GetClientKeyExchangeLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx), TCPIP_TLS_CT_HS) == E_OK)
      {
        /* If successful, reset the TX indication flag for this message */
        TcpIp_SetKeyExchangeReadyToSendOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
        processFurtherHsMsg = TRUE;
      }
      break;
    } /* case TCPIP_TLS_HSTYPE_CLIENTKEYEXCHANGE */

    case TCPIP_TLS_HSTYPE_CERTIFICATEVERIFY:
    {
      /* Forward the CertificateVerify message to the record layer */
      if (TcpIp_TlsCoreRl_Transmit(TlsConIdx, TcpIp_GetTlsBufferTxClientCertificateVerifyIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx),
        TcpIp_GetClientCertificateVerifyLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx), TCPIP_TLS_CT_HS) == E_OK)
      {
        /* If successful, reset the TX indication flag for this message */
        TcpIp_SetCertificateVerifyReadyToSendOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
        processFurtherHsMsg = TRUE;
      }
      break;
    } /* case TCPIP_TLS_HSTYPE_CERTIFICATEVERIFY */

    case TCPIP_TLS_HSTYPE_FINISHED:
    {
      /* Forward the ClientFinished message to the record layer */
      if (TcpIp_TlsCoreRl_Transmit(TlsConIdx, TcpIp_GetTlsBufferTxClientFinishedIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx),
        TcpIp_GetClientFinishedLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx), TCPIP_TLS_CT_HS) == E_OK)
      {
        /* If successful, reset the TX indication flag for this message */
        TcpIp_SetClientFinishedReadyToSendOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
        processFurtherHsMsg = TRUE;
      }
      break;
    } /* case TCPIP_TLS_HSTYPE_FINISHED */

    default:
    {
      /* Default case left blank intentionally */
      TCPIP_ASSERT_UNREACHABLE();
      break;
    } /* default */
  } /* switch() */

  return processFurtherHsMsg;

} /* TcpIp_TlsClientTx_ForwardProcessedHsMsgToRl() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_GetTlsConnectionIndexForConnectionAssignment
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(TcpIp_TlsConnectionIterType, TCPIP_CODE) TcpIp_TlsClient_GetTlsConnectionIndexForConnectionAssignment(
  CONST(TcpIp_SizeOfSocketDynType, AUTOMATIC) SocketIdx,
  CONST(TcpIp_PortOfTlsListenerType, AUTOMATIC) UsedPort)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsConnectionIterType tlsConIdx;
  TcpIp_TlsConnectionIterType highestPrioTlsConIdx = TcpIp_GetSizeOfTlsConnection();
  TcpIp_TlsConnectionPrioType highestPrio = TCPIP_TLS_CON_PRIO_INVALID;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all TLS connections to find a fitting connection. */
  for (tlsConIdx = 0u; tlsConIdx < TcpIp_GetSizeOfTlsConnection(); tlsConIdx++)
  {
    /* #20 Check if the connection is configured as TLS-Client. */
    if (TcpIp_GetModeOfTlsConnection(tlsConIdx) == TCPIP_TLS_CLIENT)
    {
      TcpIp_TlsConnectionPrioType tmpPrio
        = TcpIp_TlsClient_GetCurrentTlsConnectionPriority(tlsConIdx, SocketIdx, UsedPort);

      if (tmpPrio == TCPIP_TLS_CON_PRIO_HIGHEST)
      {
        /* #30 Break out of the loop since a connection with the highest priority was found. */
        highestPrioTlsConIdx = tlsConIdx;
        break;
      }

      if (tmpPrio > highestPrio)
      {
        /* #40 The current connection has the highest priority found so far and is currently the best match. */
        /* Continue to iterate through the connections and check if a better match can be found. */
        highestPrioTlsConIdx = tlsConIdx;
        highestPrio = tmpPrio;
      }
    }
  }

  return highestPrioTlsConIdx;
} /* TcpIp_TlsClient_GetTlsConnectionIndexForConnectionAssignment() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_GetCurrentTlsConnectionPriority
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
TCPIP_LOCAL FUNC(TcpIp_TlsConnectionPrioType, TCPIP_CODE) TcpIp_TlsClient_GetCurrentTlsConnectionPriority(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SocketDynIterType SocketIdx,
  CONST(TcpIp_PortOfTlsListenerType, AUTOMATIC) UsedPort)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsConnectionPrioType priority = TCPIP_TLS_CON_PRIO_INVALID;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the given TLS connection is assigned via ChangeParameter() and return the highest priority if true. */
  if (TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx) == SocketIdx)
  {
    /* Found a connection that was dynamically assigned to the socket using TcpIp_ChangeParameter.
     * This has the highest priority. */
    priority = TCPIP_TLS_CON_PRIO_HIGHEST;
  }
  /* #20 else - Check if a matching LocalAddrIdx is configured and select the priority via the given port. */
  else if (TcpIp_GetLocalAddrIdxOfTlsConnection(TlsConIdx) == TcpIp_GetLocalAddrBindIdxOfSocketDyn(SocketIdx))
  {
    if (TcpIp_TlsCore_IsTlsConnectionUsedByPortAndFree(TlsConIdx, UsedPort) == TRUE)
    {
      /* #30 Found a free connection that has a matching LocalAddrIdx and is used by the given port. */
      priority = TCPIP_TLS_CON_PRIO_SECOND_HIGHEST;
    }
  }
  /* #40 else - Check if a connection without LocalAddrIdx is configured and select the priority via the given port. */
  else if (TcpIp_GetLocalAddrIdxOfTlsConnection(TlsConIdx) == TCPIP_NO_LOCALADDRIDXOFTLSCONNECTION)
  {
    if (TcpIp_TlsCore_IsTlsConnectionUsedByPortAndFree(TlsConIdx, UsedPort) == TRUE)
    {
      /* #50 Found a free connection that has no specified LocalAddrIdx and is used by the given port. */
      priority = TCPIP_TLS_CON_PRIO_THIRD_HIGHEST;
    }
  }
  else
  {
    /* Intentionally left blank. */
    /* If the connection doesn't match TCPIP_TLS_CON_PRIO_INVALID is returned. */
  }

  return priority;
} /* TcpIp_TlsClient_GetCurrentTlsConnectionPriority() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_GetRootCertificateId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClient_GetRootCertificateId(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TCPIP_P2V(uint16)             CertIdPtr                                                                               /* PRQA S 3673 */ /* MD_TCPIP_Rule8.13_CfgSpecific */
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
  TcpIp_TlsCertValidationStatusDynIterType tlsCertValidationStatusIdx;
  TCPIP_P2C(TcpIp_CertValidationStatusType) certStatusPtr;
  TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);
  TcpIp_CertificateIdType tlsClientRootCertId = TcpIp_GetRootCertIdOfTlsClientConnection(tlsClientConnectionIdx);

  *CertIdPtr = TCPIP_CERTID_INV;

  /* ----- Implementation ----------------------------------------------- */
  /* Get the ID of the last certificate in the received chain. */
  tlsCertValidationStatusIdx = TcpIp_GetTlsCertValidationStatusDynValidEndIdxOfTlsConnectionDyn(TlsConIdx) - 1u;
  certStatusPtr = TcpIp_GetAddrTlsCertValidationStatusDyn(tlsCertValidationStatusIdx);

  /* #10 Check if the certificate is self signed. */
  if (certStatusPtr->IsSelfSigned == FALSE)
  {
    /* #20 Check if the certificate is valid and return the ID of the issuer certificate. */
    if (tlsClientRootCertId != TCPIP_CERTID_INV)
    {
      retVal = E_OK;
      *CertIdPtr = tlsClientRootCertId;
    }
    else
    {
      /* Nothing to do here. Return E_NOT_OK and set CertIdPtr to TCPIP_CERTID_INV. */
    }
  }
  else
  {
    /* Nothing to do here. Return E_NOT_OK and set CertIdPtr to TCPIP_CERTID_INV. */
  }
#  else
   TCPIP_DUMMY_STATEMENT_CONST(TlsConIdx);                                                                              /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
   TCPIP_DUMMY_STATEMENT_CONST(CertIdPtr);                                                                              /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
#  endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */
  return retVal;
}

/**********************************************************************************************************************
 *  TLS CLIENT ASYNC CONTEXT
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MSA - Master Secret Access
 *********************************************************************************************************************/
#  if ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON))
/**********************************************************************************************************************
 * TcpIp_TlsClientMsa_AddClientRandomToAccessBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsa_AddClientRandomToAccessBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TCPIP_P2C(uint8) clientRndSrcPtr
    = TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxClientRandomIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx));

  TCPIP_P2V(uint8) clientRndDstPtr
    = TcpIp_GetAddrTlsClientRandomAccessBuffer(TcpIp_GetTlsClientRandomAccessBufferStartIdxOfTlsConnection(TlsConIdx));

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Make received ClientRandom value accessible for MSA readout */
  /* Copy random value (stored inside of TLS TxBuffer) to the AccessBuffer */
  VStdMemCpy(clientRndDstPtr, clientRndSrcPtr, TCPIP_TLS_RANDOM_LEN);                                                   /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

} /* TcpIp_TlsClientMsa_AddClientRandomToAccessBuffer() */
#  endif /* ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON)) */
#  if ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON))

/**********************************************************************************************************************
 * TcpIp_TlsClientMsa_AddServerSessionIdToAccessBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsa_AddServerSessionIdToAccessBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  uint8 sessionIdLen = TcpIp_GetServerHelloSessionIdLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Make received sessionID accessible for MSA readout */
  /* Set the actual received SessionID length and copy the sessionID to the MSA_AccessBuffer */
  TcpIp_SetClientSessionIdAccessBufferLenOfTlsConnectionDyn(TlsConIdx, sessionIdLen);

  /* The check that the sessionIdLen is smaller or equal than TCPIP_TLS_SESSIONIDMAX_LEN is duplicated.
   * It is already checked in the function TcpIp_TlsMsg_HelloMsgGetAndCheckSessionId().
   * Check it anyway to nullify any chance to write in the wrong memory. */
  if ((sessionIdLen != 0u) && (sessionIdLen <= TCPIP_TLS_SESSIONIDMAX_LEN))
  {
    TCPIP_P2C(uint8) sessionIdSrcPtr
      = TcpIp_GetAddrTlsBufferRx(TcpIp_GetTlsBufferRxServerSessionIdIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx));

    TCPIP_P2V(uint8) sessionIdDstPtr
      = TcpIp_GetAddrTlsClientSessionIdAccessBuffer(TcpIp_GetTlsClientSessionIdAccessBufferStartIdxOfTlsConnection(TlsConIdx));

    /* Copy from the SessionId start IDX (inside of the TLS RX-Buffer) to the AccessBuffer */
    VStdMemCpy(sessionIdDstPtr, sessionIdSrcPtr, sessionIdLen);                                                         /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
  }
} /* TcpIp_TlsClientMsa_AddServerSessionIdToAccessBuffer() */
#  endif /* ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON)) */

#  define TCPIP_STOP_SEC_CODE
#  include "TcpIp_MemMap.h"                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SILENTBSW JUSTIFICATIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  COVERAGE JUSTIFICATIONS
 *********************************************************************************************************************/

# endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */
#endif /* (TCPIP_SUPPORT_ASRTLS == STD_ON) */
/**********************************************************************************************************************
 *  END OF FILE: TcpIp_TlsClientCommon.c
 *********************************************************************************************************************/
