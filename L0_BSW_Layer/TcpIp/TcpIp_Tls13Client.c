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
/*!        \file  TcpIp_Tls13Client.c
 *        \brief  Transport Layer Security (TLS) 1.3 client functions implementation.
 *
 *      \details  This file is part of the TcpIp TLS submodule.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp module. >> TcpIp.h
 *********************************************************************************************************************/

#define TCPIP_TLS13CLIENT_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TcpIp_Cfg.h"

#if (TCPIP_SUPPORT_ASRTLS == STD_ON)                                                                                    /* COV_MSR_UNSUPPORTED */
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#   include "TcpIp_Tls.h"
#   include "TcpIp_Tls13Core.h"
#   include "TcpIp_TlsPriv.h"
#   include "TcpIp_Tls13Client.h"
#   include "TcpIp_TlsCoreCommon.h"
#   include "TcpIp_TlsClientCommon.h"

#   include "TcpIp_Types.h"
#   include "TcpIp_Lcfg.h"
#   include "vstdlib.h"

#   if (TCPIP_DEV_ERROR_REPORT == STD_ON)
#    include "Det.h"
#   endif /* (TCPIP_DEV_ERROR_REPORT == STD_ON) */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#   define TCPIP_TLS_CERT_REQUEST_CONTEXT_LEN_LEN                 1u  /* Length of the cert context length field inside cert request message */


/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#   if !defined (TCPIP_LOCAL)
#    define TCPIP_LOCAL static
#   endif

#   if !defined (TCPIP_LOCAL_INLINE)
#    define TCPIP_LOCAL_INLINE LOCAL_INLINE
#   endif

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
 *  LOCAL DATA
 *********************************************************************************************************************/
#   define TCPIP_START_SEC_CONST_8
#   include "TcpIp_MemMap.h"                                                                                            /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* RFC8446 chapter 4.4.3 Certificate Verify:
 * The context string for a server signature is "TLS 1.3, server CertificateVerify". */
/* PRQA S 3218 1 */ /* MD_TCPIP_Rule8.9_3218 */
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls13_ServerCertificateVerifyContextString[] = "TLS 1.3, server CertificateVerify";
/* RFC8446 chapter 4.4.3 Certificate Verify:
 * The context string for a client signature is "TLS 1.3, client CertificateVerify". */
/* PRQA S 3218 1 */ /* MD_TCPIP_Rule8.9_3218 */
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls13_ClientCertificateVerifyContextString[] = "TLS 1.3, client CertificateVerify";

/* PRQA S 3218 2 */ /* MD_TCPIP_Rule8.9_3218 */
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_Hs_Tls13Label_Finished[] = "finished";
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_Hs_Tls13Label_Finished_Len = 8u;

#   define TCPIP_STOP_SEC_CONST_8
#   include "TcpIp_MemMap.h"                                                                                            /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#   define TCPIP_START_SEC_CODE
#   include "TcpIp_MemMap.h"                                                                                            /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * TcpIp_Tls13Client_AssignPskIdentityToResumedConnection
 *********************************************************************************************************************/
/*! \brief         Assign the passed PSK identity to the passed resumed connection
 *  \details       Check that resumed connection is in correct state, copy the resumption master secret from the base
 *                 connection, mark the PSK as reserved and issue the callback for the number of available tickets
 *  \param[in]     ResumptionBaseTlsConIdx      TLS connection index of the resumption base connection
 *                                              \spec requires ResumptionBaseTlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ResumedTlsConIdx             Index of the TLS connection where the session shall be resumed
 *                                              \spec requires ResumedTlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     AvailableTls13PskIdentityIdx Index of the PSK identity which shall be assigned
 *                                              \spec requires AvailableTls13PskIdentityIdx < TcpIp_GetSizeOfTls13PskIdentity(); \endspec
 *  \return        E_OK                         PSK identity successfully assigned to the resumed connection
 *  \return        E_NOT_OK                     PSK identity could NOT be assigned to the resumed connection
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AssignPskIdentityToResumedConnection(
  TcpIp_TlsConnectionIterType     ResumptionBaseTlsConIdx,
  TcpIp_TlsConnectionIterType     ResumedTlsConIdx,
  TcpIp_Tls13PskIdentityIterType  AvailableTls13PskIdentityIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13Client_CopySessionResumptionMasterSecret
 *********************************************************************************************************************/
/*! \brief         Copy the resumption master secret from the resumption base connection to the resumed connection
 *  \details       This shall be called in the context of the ChangeParameter where session resumption is requested
 *  \param[in]     ResumptionBaseTlsConIdx      TLS connection index of the resumption base connection
 *                                              \spec requires ResumptionBaseTlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ResumedTlsConIdx             Index of the TLS connection where the session shall be resumed
 *                                              \spec requires ResumedTlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                         Resumption master secret successfully copied
 *  \return        E_NOT_OK                     Copying of resumption master secret failed
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_CopySessionResumptionMasterSecret(
  TcpIp_TlsConnectionIterType  ResumptionBaseTlsConIdx,
  TcpIp_TlsConnectionIterType  ResumedTlsConIdx);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ClientHelloExtWriteDnToTxBuffer
 *********************************************************************************************************************/
/*! \brief         Write the distinguished name of the certificate with the passed Id to the Tls Tx buffer
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ExtAuthoritiesStartIdx  Start Idx in TLS TX Buffer for the list of the DNs
 *  \param[in]     CertId                  Id of the certificate whose distinguished name shall be added to the buffer
 *  \param[out]    ConsumedLenPtr          Pointer to the current byte length of the DN list
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtWriteDnToTxBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferTxIterType   ExtAuthoritiesStartIdx,
  KeyM_CertificateIdType      CertId,
  TCPIP_P2V(uint16)           ConsumedLenPtr);
#   endif

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ClientHelloExtCalcObfuscatedTicketAge
 *********************************************************************************************************************/
/*! \brief         Calculate the obfuscated ticket age for the pre_shared_key extension
 *  \details       According to RFC8446 chapter 4.2.11.1
 *  \param[in]     Tls13PskIdentityIdx    Index of the PSK identity for which the obfuscated ticket age shall be calculated
 *                                        \spec requires PskIdentityIdx < TcpIp_GetSizeOfTls13PskIdentity(); \endspec
 *  \return                               Calculated obfuscated ticket age
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(uint32, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtCalcObfuscatedTicketAge(
  TcpIp_Tls13PskIdentityIterType Tls13PskIdentityIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ClientHelloExtPrepareKeyShareFields
 *********************************************************************************************************************/
/*! \brief         Prepare the length and type fields of the KeyShare extension
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtPrepareKeyShareFields(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerHelloScanForSupportedVersionsExt
 *********************************************************************************************************************/
/*! \brief         Scan extensions of Server Hello for the supported versions extension and parse it if it was received
 *  \details       Parses the supported version extension and stores the received protocol version
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ServerHelloEndIdx       End index in Tls RxBuffer of the ServerHello message
 *  \return        E_OK                    Operation successful
 *  \return        E_NOT_OK                Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerHelloScanForSupportedVersionsExt(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferRxIterType   ServerHelloEndIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerHelloFindAndParseSupportedVersionsExtension
 *********************************************************************************************************************/
/*! \brief         Finds the supported_versions extension in the received extension list and sets active TLS version
 *  \details       -
 *  \param[in]     TlsConIdx                         TLS connection index
 *                                                   \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ReceivedExtensionListPtr          Pointer to the list of the received extensions
 *  \param[in]     OverallNumberOfReceivedExtensions Number of received extensions in the server hello
 *  \return        E_OK                              Operation successful
 *  \return        E_NOT_OK                          Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerHelloFindAndParseSupportedVersionsExtension(
  TcpIp_TlsConnectionIterType       TlsConIdx,
  TCPIP_P2C(TcpIp_TlsExtensionType) ReceivedExtensionListPtr,
  uint8                             OverallNumberOfReceivedExtensions);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ServerHelloParseExtensionSupportedVersions
 *********************************************************************************************************************/
/*! \brief         Parses a received TLS extension of the type supported_versions.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     SupportedVersions       Extension of type supported_versions
 *  \return        E_OK                    Operation successful
 *  \return        E_NOT_OK                Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerHelloParseExtensionSupportedVersions(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType      SupportedVersions);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_SetActiveVersionTo12With13Enabled
 *********************************************************************************************************************/
/*! \brief         Sets the active version to TLS 1.2 if this is a valid choice while TLS 1.3 is also enabled
 *  \details       Setting the active version to 1.2 is only valid if no supported_versions extension was received
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Active version was set to TLS 1.2
 *  \return        E_NOT_OK                The send ClientHello does not allow for a TLS 1.2 handshake, an alert is set
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_SetActiveVersionTo12With13Enabled(
  TcpIp_TlsConnectionIterType TlsConIdx);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerHelloKeyShareExtensionStorePositionOfKeyAndKeyLength
 *********************************************************************************************************************/
/*! \brief         Stores the Key and the key length of the public key from the key_share extensions
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     KeyShare                The key_share extensions
 *  \param[in]     ActiveTlsHandshakeIdx   Idx of active Tls Handshake
 *  \return        E_OK                    Operation successful
 *  \return        E_NOT_OK                Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerHelloKeyShareExtensionStorePositionOfKeyAndKeyLength(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType KeyShare,
  TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType ActiveTlsHandshakeIdx);
#   endif

/**********************************************************************************************************************
 * TcpIp_Tls13ClientHsStm_ParseEncryptedExtensions
 *********************************************************************************************************************/
/*! \brief         Parse the encrypted extensions message
 *  \details       -
 *  \param[in]     TlsConIdx         TLS connection index
 *                                   CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseEncryptedExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ExtractEncryptedExtensionsInformation
 *********************************************************************************************************************/
/*! \brief         Extract the encrypted extensions information from the message
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ExtractEncryptedExtensionsInformation(
  TcpIp_TlsConnectionIterType TlsConIdx);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_Tls13ClientHsStm_ParseServerCertificate
 *********************************************************************************************************************/
/*! \brief         Parse the TLS 1.3 Server certificate message
 *  \details       -
 *  \param[in]     TlsConIdx         TLS connection index
 *                                   CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseServerCertificate(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_CheckSignatureAlgorithmInCertificateVerifyMsg
 *********************************************************************************************************************/
/*! \brief         Check if a Signature Algorithm is valid for the CertificateVerify Msg
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     SignatureAlgorithm Signature Algorithm that should be checked
 *  \return        E_OK               Signature Algorithm valid
 *  \return        E_NOT_OK           Signature Algorithm invalid
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_CheckSignatureAlgorithmInCertificateVerifyMsg(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SignatureAlgorithmIdType SignatureAlgorithm);

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientUtil_CheckSignatureAlgorithmsExtensionForEntry
 *********************************************************************************************************************/
/*! \brief         Check if a Signature Algorithm exists in the list sent in the Extension Signature Algorithms
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     SignatureAlgorithm Signature Algorithm that should be checked
 *  \return        E_OK               Signature Algorithm exists in the sent list
 *  \return        E_NOT_OK           Signature Algorithm does NOT exist in the sent list
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientUtil_CheckSignatureAlgorithmsExtensionForEntry(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SignatureAlgorithmIdType SignatureAlgorithm);
#   endif

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_HandleWaitCertCR
 *********************************************************************************************************************/
/*! \brief         Implements the WAIT_CERT_CR state of RFC 8466 A.1.
 *  \details       -
 *  \param[in]     TlsConIdx         TLS connection index
 *                                   CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_HandleWaitCertCR(
  TcpIp_TlsConnectionIterType TlsConIdx);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseServerCertificateRequest
 *********************************************************************************************************************/
/*! \brief         Parses the server CertificateRequest message
 *  \details       -
 *  \param[in]     TlsConIdx         TLS connection index
 *                                   CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseServerCertificateRequest(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestCertificateRequestContext
 *********************************************************************************************************************/
/*! \brief         Parses the message element CertificateRequest.certificate_request_context
 *  \details       -
 *  \param[in]     TlsConIdx         TLS connection index
 *                                   CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK              Operation successful
 *  \return        E_NOT_OK          Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestCertificateRequestContext(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestExtensions
 *********************************************************************************************************************/
/*! \brief         Parses the message element CertificateRequest.extensions
 *  \details       -
 *  \param[in]     TlsConIdx         TLS connection index
 *                                   CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK              Operation successful
 *  \return        E_NOT_OK          Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestExtensionsEntries
 *********************************************************************************************************************/
/*! \brief         Parses the extensions contained in message element CertificateRequest.extensions
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     ExtensionsLen   The length of the extension element
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsBufferRx()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestExtensionsEntries(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 ExtensionsLen);

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestProcessExtensions
 *********************************************************************************************************************/
/*! \brief         Implements the processing/dispatching of received extensions of
 *                 message element CertificateRequest.extensions
 *  \details       -
 *  \param[in]     TlsConIdx         TLS connection index
 *                                   CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     ExtensionsPtr     Pointer to a list of received extensions.
 *  \param[in]     ExtensionsPtrCnt  Number of extensions entries provided in the ExtensionsPtr.
 *  \return        E_OK              Operation successful
 *  \return        E_NOT_OK          Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestProcessExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(TcpIp_TlsExtensionType) ExtensionsPtr,
  uint8 ExtensionsPtrCnt);

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseCertificateRequestExtensionsSignatureAlgorithms
 *********************************************************************************************************************/
/*! \brief         Parses a signature_algorithms extension of message element CertificateRequest.extensions
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     ExtensionPtr    Pointer to an already parsed extension.
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseCertificateRequestExtensionsSignatureAlgorithms(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(TcpIp_TlsExtensionType) ExtensionPtr);

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseCertificateRequestExtensionsSignatureAlgorithmsCert
 *********************************************************************************************************************/
/*! \brief         Parses a signature_algorithms_cert extension of message element CertificateRequest.extensions
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     ExtensionPtr    Pointer to an already parsed extension.
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseCertificateRequestExtensionsSignatureAlgorithmsCert(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(TcpIp_TlsExtensionType) ExtensionPtr);


/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseCertificateRequestExtensionsCertificateAuthorities
 *********************************************************************************************************************/
/*! \brief         Parses a certificate_authorities extension of message element CertificateRequest.extensions
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     ExtensionPtr    Pointer to an already parsed extension.
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseCertificateRequestExtensionsCertificateAuthorities(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(TcpIp_TlsExtensionType) ExtensionPtr);
#   endif

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ParseExtension
 *********************************************************************************************************************/
/*! \brief         Parses a generic extension that is currently stored in the RX buffer.
 *  \details       -
 *  \param[in]     TlsConIdx                      TLS connection index
 *                                                CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     ExtensionStartTlsBufferRxIdx   Index to start index of Rx buffer to start parsing from.
 *                                                CONSTRAINT: [0..TcpIp_GetSizeOfTlsBufferRx()-1]
 *  \param[in]     AvailableInputDataLen          Remaining data length that can be used to parse an extension.
 *  \param[out]    ParsedExtensionPtr             Pointer that contains the parsed extension once API succeeded.
 *  \return        E_OK                           Operation successful
 *  \return        E_NOT_OK                       Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ParseExtension(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferRxIterType ExtensionStartTlsBufferRxIdx,
  uint16 AvailableInputDataLen,
  TCPIP_P2V(TcpIp_TlsExtensionType) ParsedExtensionPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ServerCertRequestMsgCheckSignatureAlgorithmsLengthConsistency
 *********************************************************************************************************************/
/*! \brief         Check if the passed signature algorithm length is consistent with other received data.
 *  \details       -
 *  \param[in]     TlsExtensionPtr            Pointer to a pre-parsed generic extension
 *  \param[in]     SignatureAlgorithmsLength  Length of signature algorithms
 *  \return        E_OK                       Passed signature algorithm length is valid
 *  \return        E_NOT_OK                   Passed signature algorithm length is invalid
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerCertRequestMsgCheckSignatureAlgorithmsLengthConsistency(
  TCPIP_P2C(TcpIp_TlsExtensionType) TlsExtensionPtr,
  uint16 SignatureAlgorithmsLength);

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ParseExtensions
 *********************************************************************************************************************/
/*! \brief         Parses a list of generic extensions.
 *  \details       -
 *  \param[in]     TlsConIdx         TLS connection index
 *                                   CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     ExtensionLen      Length of the extensions list in bytes.
 *  \param[out]    ExtensionsPtr     Pointer to a list of extensions where parsed extensions shall be stored.
 *  \param[in,out] ExtensionsPtrCnt  In: Max. number of list entries of ExtensionsPtr.
 *                                   Out: The number of parsed extensions.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ParseExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 ExtensionLen,
  TCPIP_P2V(TcpIp_TlsExtensionType) ExtensionsPtr,
  TCPIP_P2V(uint8) ExtensionsPtrCnt);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ExtractServerCertificateInformation
 *********************************************************************************************************************/
/*! \brief         Extract the server certificate information from the message when using TLS 1.3
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ExtractServerCertificateInformation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13Client_TlsUpdateOcspInformation
 *********************************************************************************************************************/
/*! \brief         Updates the OCSP information for certificates received in a Server Certificate message.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_TlsUpdateOcspInformation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ServerCertMsgProcessCertChain
 *********************************************************************************************************************/
/*! \brief         Process the certificate chain in the received server cert message when using TLS 1.3
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerCertMsgProcessCertChain(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ServerCertMsgCheckLengths
 *********************************************************************************************************************/
/*! \brief         Check various length field of the TLS 1.3 server cert message
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[out]    CertListLenPtr  Pointer to the length of the certificate list which is read from the buffer
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerCertMsgCheckLengths(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint32)           CertListLenPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13Client_GetNumOfCertificates
 *********************************************************************************************************************/
/*! \brief         Obtain the number of certificates in the received certificate chain when using TLS 1.3
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     CertChainLen    Length of the certificate chain
 *  \param[in]     CertEndIdx      End Idx of the certificate data
 *  \param[out]    NumCertPtr      Number of certificates in the chain
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_GetNumOfCertificates(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint32                      CertChainLen,
  TcpIp_TlsBufferRxIterType   CertEndIdx,
  TCPIP_P2V(uint8)            NumCertPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ServerCertMsgParseAndTriggerVerification
 *********************************************************************************************************************/
/*! \brief         Extract certificates from TLS 1.3 server certificate message and trigger verification if possible
 *  \details       -
 *  \param[in]     TlsConIdx                       TLS connection index
 *                                                 \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     CertStartIdx                    Start Idx of the certificate data
 *  \param[in]     NumCerts                        Number of certificates in cert chain
 *  \return        E_OK                            Operation successful
 *  \return        E_NOT_OK                        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerCertMsgParseAndTriggerVerification(
  TcpIp_TlsConnectionIterType         TlsConIdx,
  TcpIp_TlsBufferRxIterType           CertStartIdx,
  uint8                               NumCerts);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ServerCertMsgCheckIfSigAlgoIsSupported
 *********************************************************************************************************************/
 /*! \brief         Get the signature algorithm of the received leaf certificate and check if it is supported
  *  \details       -
  *  \param[in]     TlsConIdx              TLS connection index
  *                                        \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
  *  \return        E_OK                   SigAlgoId successfully extracted and supported by the ECU
  *                 E_NOT_OK               Either SigAlgo is not supported or SigAlgo could not be extracted
  *  \pre           -
  *  \context       TASK
  *  \reentrant     FALSE
  *  \synchronous   TRUE
  *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerCertMsgCheckIfSigAlgoIsSupported(
  TcpIp_TlsConnectionIterType         TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ServerCertMsgCheckIfCurveMatchesKeyShareExt
 *********************************************************************************************************************/
/*! \brief         Get the curve from the received leaf certificate and check if it matches the curve from the received
 *                 Key Share extension
 *  \details       -
 *  \param[in]     TlsConIdx              TLS connection index
 *                                        \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                   Curve successfully extracted and matches the Key Share extension
 *                 E_NOT_OK               Either curve does not match Key Share or curve could not be extracted
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerCertMsgCheckIfCurveMatchesKeyShareExt(
  TcpIp_TlsConnectionIterType         TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerCertStatusTriggerOcspValidation
 *********************************************************************************************************************/
/*! \brief         Triggers the OCSP validation in async context.
 *  \details       -
 *  \param[in]     TlsConIdx              TLS connection index
 *                                        \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK,
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerCertStatusTriggerOcspValidation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientHsStm_ParseServerCertificateVerify
 *********************************************************************************************************************/
/*! \brief         Parse the Server certificate verify message
 *  \details       -
 *  \param[in]     TlsConIdx         TLS connection index
 *                                   CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseServerCertificateVerify(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ExtractServerCertificateVerifyInformation
 *********************************************************************************************************************/
/*! \brief         Extract the server certificate verify information from the message
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ExtractServerCertificateVerifyInformation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseCertificateVerifyMsg
 *********************************************************************************************************************/
/*! \brief         Parse the CertificateVerify message sent by the server.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK               Operation successful.
 *  \return        E_NOT_OK           Operation NOT successful.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseCertificateVerifyMsg(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_AddHelloMessagesToHash
 *********************************************************************************************************************/
/*! \brief         Initialize the Hash function and add the Hello messages to the Hash function.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK               The Hash function could be initialized and the messages were added.
 *  \return        E_NOT_OK           The Hash function could not be initialized or the messages could not be added.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AddHelloMessagesToHash(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_AddTruncatedClientHelloMessageToHash
 *********************************************************************************************************************/
/*! \brief         Initialize the Hash function and add the truncated ClientHello message to the Hash function.
 *  \details       This functionality is needed to calculate a binder for the pre_shared_key extension
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     HashLength         Expected hash length
 *  \return        E_OK               The Hash function could be initialized and the message was added.
 *  \return        E_NOT_OK           The Hash function could not be initialized or the message could not be added.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AddTruncatedClientHelloMessageToHash(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8                       HashLength);

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_AddEncryptedExtensionsMsgToHash
 *********************************************************************************************************************/
/*! \brief         Add the EncryptedExtensions message to the Hash function.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK               The Hash function could be updated.
 *  \return        E_NOT_OK           The Hash function could not be updated.
 *  \pre           TcpIp_Tls13Client_AddHelloMessagesToHash has been called.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AddEncryptedExtensionsMsgToHash(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_AddServerCertificateMsgToHash
 *********************************************************************************************************************/
/*! \brief         Add the Server Certificate message to the Hash function.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK               The Hash function could be updated.
 *  \return        E_NOT_OK           The Hash function could not be updated.
 *  \pre           TcpIp_Tls13Client_AddHelloMessagesToHash has been called.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AddServerCertificateMsgToHash(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_AddServerCertificateVerifyMsgToHash
 *********************************************************************************************************************/
/*! \brief         Add the Server CertificateVerify message to the Hash function.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK               The Hash function could be updated.
 *  \return        E_NOT_OK           The Hash function could not be updated.
 *  \pre           TcpIp_Tls13Client_AddHelloMessagesToHash has been called.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AddServerCertificateVerifyMsgToHash(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_AddServerFinishedMsgToHash
 *********************************************************************************************************************/
/*! \brief         Add the ServerFinished message to the Hash function.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK               The Hash function could be updated.
 *  \return        E_NOT_OK           The Hash function could not be updated.
 *  \pre           TcpIp_Tls13Client_AddHelloMessagesToHash has been called.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AddServerFinishedMsgToHash(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_AddClientCertificateToHash
 *********************************************************************************************************************/
/*! \brief         Add the ClientCertificate message to the hash function if message was sent.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK               The Hash function could be updated.
 *  \return        E_NOT_OK           The Hash function could not be updated.
 *  \pre           TcpIp_Tls13Client_AddHelloMessagesToHash has been called.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AddClientCertificateToHash(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_AddClientCertificateVerifyToHash
 *********************************************************************************************************************/
/*! \brief         Add the ClientCertificateVerify message to the hash function if message was sent.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK               The Hash function could be updated.
 *  \return        E_NOT_OK           The Hash function could not be updated.
 *  \pre           TcpIp_Tls13Client_AddHelloMessagesToHash has been called.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AddClientCertificateVerifyToHash(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_AddClientFinishedToHash
 *********************************************************************************************************************/
/*! \brief         Add the ClientFinished message to the hash function.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK               The Hash function could be updated.
 *  \return        E_NOT_OK           The Hash function could not be updated.
 *  \pre           TcpIp_Tls13Client_AddHelloMessagesToHash has been called.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AddClientFinishedToHash(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_FinalizeHashOfHsMessages
 *********************************************************************************************************************/
/*! \brief         Finalize the hash and save it.
 *  \details       Check that the hash length is as long as expected.
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     HashCsmJobId       Id of the CSM hash job
 *  \param[in]     HashLength         Expected length of the final hash
 *  \param[in,out] TargetSegmentPtr   Pointer to a buffer segment where the calculated hash shall be written to
 *  \return        E_OK               The Hash was calculated and saved.
 *  \return        E_NOT_OK           The Hash could not be calculated.
 *  \pre           TcpIp_Tls13Client_AddHelloMessagesToHash or TcpIp_Tls13Client_AddTruncatedClientHelloMessageToHash
 *                 has been called.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_FinalizeHashOfHsMessages(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_CsmJobIdType          HashCsmJobId,
  uint8                       HashLength,
  TcpIp_SegmentPtrType        TargetSegmentPtr);

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_CalculateFinishedVerifyData
 *********************************************************************************************************************/
/*! \brief         Calculate the Finished verifyData (RFC 8446 chapter 4.4.4.).
 *  \details       -
 *  \param[in]     TlsConIdx            TLS connection index
 *                                      CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK                 VerifyData was calculated and saved.
 *  \return        E_NOT_OK             VerifyData could not be calculated.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_CalculateFinishedVerifyData(
  TcpIp_TlsConnectionIterType TlsConIdx);

/***********************************************************************************************************************
 *  TcpIp_Tls13Client_CalculateFinishedKey
 *********************************************************************************************************************/
/*! \brief         Calculate the Finished key (RFC 8446 chapter 4.4.4.)
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK               No error occurred.
 *  \return        E_NOT_OK           Calculating the Finished key failed.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_CalculateFinishedKey(
  TcpIp_TlsConnectionIterType TlsConIdx);

/***********************************************************************************************************************
 *  TcpIp_Tls13Client_GetCalcFinishedInfoFromActiveCipher
 *********************************************************************************************************************/
/*! \brief         Get the information which is needed to calculate the Finished key / Finished verify data
 *  \details       Two things are needed: the Id of the Csm MAC generate job and expected length of the hash
 *  \param[in]     TlsConIdx              TLS connection index
 *                                        CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[out]    MacGenerateCsmJobIdPtr Pointer to the Id of the Csm MAC generate job
 *  \param[out]    HashLengthPtr          Pointer to the expected hash length
 *  \return        E_OK                   No error occurred.
 *  \return        E_NOT_OK               Failed to acquire the calculation information
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_GetCalcFinishedInfoFromActiveCipher(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TCPIP_P2V(TcpIp_CsmJobIdType) MacGenerateCsmJobIdPtr,
  TCPIP_P2V(uint8)              HashLengthPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientHsStm_ParseServerFinished
 *********************************************************************************************************************/
/*! \brief         Receive the server finished message.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseServerFinished(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ExtractNewSessionTicketInformation
 *********************************************************************************************************************/
/*! \brief         Extract the NewSessionTicket information from the message and save it into a struct.
 *  \details       -
 *  \param[in]     TlsConIdx                  TLS connection index
 *                                            CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     HsLen                      Handshake length
 *  \param[in]     SourceSegment1Ptr          First buffer segment (wraparound case: data at the end of the buffer)
 *  \param[in]     SourceSegment2Ptr          Second buffer segment (wraparound case: data at the start of the buffer)
 *  \param[out]    NewSessionTicketInfoPtr    Pointer to a struct where the extracted information is saved
 *  \param[out]    RejectNewSessionTicketPtr  Pointer where it can be stored if this NewSessionTicket shall be ignored
 *  \return        E_OK                       Operation successful
 *  \return        E_NOT_OK                   Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ExtractNewSessionTicketInformation(
  TcpIp_TlsConnectionIterType                   TlsConIdx,
  uint32                                        HsLen,
  TcpIp_ConstSegmentPtrType                     SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                     SourceSegment2Ptr,
  TCPIP_P2V(TcpIp_TlsNewSessionTicketInfoType)  NewSessionTicketInfoPtr,
  TCPIP_P2V(boolean)                            RejectNewSessionTicketPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ExtractTicketInformationFromNewSessionTicket
 *********************************************************************************************************************/
/*! \brief         Extract ticket_lifetime and ticket_age_add from the received NewSessionTicket message.
 *  \details       Also check that the lifetime is not smaller than the configured minimum or greater than the maximum.
 *  \param[in]     TlsConIdx                  TLS connection index
 *                                            CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     SourceSegment1Ptr          Pointer to the first buffer segment containing the NewSessionTicket msg
 *  \param[in]     SourceSegment2Ptr          Pointer to the second buffer segment containing the NewSessionTicket msg
 *  \param[out]    NewSessionTicketInfoPtr    Pointer to a struct where the extracted information is saved
 *  \param[out]    RejectNewSessionTicketPtr  If the NewSessionTicket is correctly formatted but does not fit to the
 *                                            config it should be rejected / ignored.
 *                                            This is the pointer for the corresponding bool value.
 *  \return        E_OK                       Operation successful
 *  \return        E_NOT_OK                   Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ExtractTicketInformationFromNewSessionTicket(
  TcpIp_TlsConnectionIterType                   TlsConIdx,
  TcpIp_ConstSegmentPtrType                     SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                     SourceSegment2Ptr,
  TCPIP_P2V(TcpIp_TlsNewSessionTicketInfoType)  NewSessionTicketInfoPtr,
  TCPIP_P2V(boolean)                            RejectNewSessionTicketPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ExtractNonceInformationFromNewSessionTicket
 *********************************************************************************************************************/
/*! \brief         Read, check and save the received nonce length, skip over the nonce.
 *  \details       Only the position and length of the nonce in the buffer is saved, the value will be processed later.
 *  \param[in]     SourceSegment1Ptr          Pointer to the first buffer segment containing the NewSessionTicket msg
 *  \param[in]     SourceSegment2Ptr          Pointer to the second buffer segment containing the NewSessionTicket msg
 *  \param[out]    NewSessionTicketInfoPtr    Pointer to a struct where the extracted information is saved
 *  \return        E_OK                       Operation successful
 *  \return        E_NOT_OK                   Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ExtractNonceInformationFromNewSessionTicket(
  TcpIp_ConstSegmentPtrType                     SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                     SourceSegment2Ptr,
  TCPIP_P2V(TcpIp_TlsNewSessionTicketInfoType)  NewSessionTicketInfoPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ExtractIdentityInformationFromNewSessionTicket
 *********************************************************************************************************************/
/*! \brief         Read, check and save the received identity length, skip over the identity.
 *  \details       Only the position and length of the identity in the buffer is saved, the value will be processed later.
 *  \param[in]     SourceSegment1Ptr          Pointer to the first buffer segment containing the NewSessionTicket msg
 *  \param[in]     SourceSegment2Ptr          Pointer to the second buffer segment containing the NewSessionTicket msg
 *  \param[out]    NewSessionTicketInfoPtr    Pointer to a struct where the extracted information is saved
 *  \param[out]    RejectNewSessionTicketPtr  If the NewSessionTicket is correctly formatted but does not fit to the
 *                                            config it should be rejected / ignored.
 *                                            This is the pointer for the corresponding bool value.
 *  \return        E_OK                       Operation successful
 *  \return        E_NOT_OK                   Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ExtractIdentityInformationFromNewSessionTicket(
  TcpIp_ConstSegmentPtrType                     SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                     SourceSegment2Ptr,
  TCPIP_P2V(TcpIp_TlsNewSessionTicketInfoType)  NewSessionTicketInfoPtr,
  TCPIP_P2V(boolean)                            RejectNewSessionTicketPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ExtractExtensionsInformationFromNewSessionTicket
 *********************************************************************************************************************/
/*! \brief         Skip over attached extensions to the received NewSessionTicket. Check for early_data extension.
 *  \details       Perform length checks and check for duplicated extensions. Other extension information is ignored.
 *  \param[in]     SourceSegment1Ptr          Pointer to the first buffer segment containing the NewSessionTicket msg
 *  \param[in]     SourceSegment2Ptr          Pointer to the second buffer segment containing the NewSessionTicket msg
 *  \param[out]    RejectNewSessionTicketPtr  It can be configured that NewSessionTickets containing an early_data
 *                                            extension are rejected / ignored. Pointer to the corresponding bool value
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ExtractExtensionsInformationFromNewSessionTicket(
  TcpIp_ConstSegmentPtrType                   SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                   SourceSegment2Ptr,
  TCPIP_P2V(boolean)                          RejectNewSessionTicketPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ProcessSingleExtensionInformationFromNewSessionTicket
 *********************************************************************************************************************/
/*! \brief         Skip over single extension of NewSessionTicket. Check for early_data extension.
 *  \details       Perform length checks and check if extension is duplicated. Other extension information is ignored.
 *  \param[in]     SourceSegment1Ptr          Pointer to the first buffer segment containing the NewSessionTicket msg
 *  \param[in]     SourceSegment2Ptr          Pointer to the second buffer segment containing the NewSessionTicket msg
 *  \param[in]     CurrentExtensionIndex      Index of the extension which shall be processed
 *                                            \spec requires $lengthOf(ExtensionTypeListPtr) >= CurrentExtensionIndex; \endspec
 *  \param[out]    RejectNewSessionTicketPtr  It can be configured that NewSessionTickets containing an early_data
 *                                            extension are rejected / ignored. Pointer to the corresponding bool value
 *  \param[out]    ExtensionTypeListPtr       Pointer to a list of types of extensions which were already processed.
 *                                            Used to check if current extension is duplicated.
 *                                            Current extension type is added in this function.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ProcessSingleExtensionInformationFromNewSessionTicket(
  TcpIp_ConstSegmentPtrType                   SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                   SourceSegment2Ptr,
  uint8                                       CurrentExtensionIndex,
  TCPIP_P2V(boolean)                          RejectNewSessionTicketPtr,
  TCPIP_P2V(uint16)                           ExtensionTypeListPtr);

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_FindPskForSessionTicketStorage
 *********************************************************************************************************************/
/*! \brief         Find a PSK identity to store the received session ticket.
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[out]    PskIdentityIdxPtr   Pointer to the index of the PSK identity to store the ticket
 *  \return        E_OK                Found a PSK to store the session ticket
 *  \return        E_NOT_OK            No matching PSK found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_FindPskForSessionTicketStorage(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(TcpIp_Tls13PskIdentityIterType)  PskIdentityIdxPtr);

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_IsTicketLifetimeBiggerThanPskRemainingLifetime()
 *********************************************************************************************************************/
/*! \brief         Compare the lifetime of the NewSessionTicket with the remaining lifetime of the PSK identity.
 *  \details       -
 *  \param[in]     NewSessionTicketInfoPtr   Pointer to the session ticket info
 *  \param[in]     Tls13PskIdentityIdx       Idx of the PSK identity that shall be compared
 *  \return        TRUE         New session ticket lifetime is bigger than PSK identity remaining lifetime.
 *  \return        FALSE        New session ticket lifetime is NOT bigger than PSK identity remaining lifetime.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_Tls13Client_IsTicketLifetimeBiggerThanPskRemainingLifetime(
  TCPIP_P2C(TcpIp_TlsNewSessionTicketInfoType) NewSessionTicketInfoPtr,
  TcpIp_Tls13PskIdentityIterType               Tls13PskIdentityIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_CheckPskForSessionTicketStorage
 *********************************************************************************************************************/
/*! \brief         Check if the PSK identity with the passed index is suitable to store the session ticket information
 *  \details       -
 *  \param[in]     CheckThisTls13PskIdentityIdx     Index of the PSK identity which shall be checked if it is suitable
 *  \param[in]     NeededHashAlgorithm              Hash algorithm which must be configured in a suitable PSK identity
 *  \param[in,out] LeastCountDownTicketLifetimePtr  Pointer to the least lifetime in the checked suitable identities
 *  \param[in,out] EmptyPskIdentityFoundPtr         Pointer to a value which specifies if an empty suitable identity
 *                                                  was found in the already checked identities
 *  \param[in,out] AvailablePskIdentityFoundPtr     Pointer to a value which specifies if an available suitable
 *                                                  identity was found in the already checked identities
 *  \param[in,out] UseThisPskIdentityIdxPtr         Pointer to the index of the identity which is currently the best
 *                                                  option to store the session ticket information
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13Client_CheckPskForSessionTicketStorage(
  TcpIp_Tls13PskIdentityIterType            CheckThisTls13PskIdentityIdx,
  TcpIp_TlsHashAlgorithmType                NeededHashAlgorithm,
  TCPIP_P2V(uint32)                         LeastCountDownTicketLifetimePtr,
  TCPIP_P2V(boolean)                        EmptyPskIdentityFoundPtr,
  TCPIP_P2V(boolean)                        AvailablePskIdentityFoundPtr,
  TCPIP_P2V(TcpIp_Tls13PskIdentityIterType) UseThisPskIdentityIdxPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13Client_StoreNewSessionTicketInformation
 *********************************************************************************************************************/
/*! \brief         Store information received in NewSessionTicket message to access during resumed connection HS.
 *  \details       -
 *  \param[in]     TlsConIdx                    TLS connection index
 *                                              CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     StoreInfoTls13PskIdentityIdx Index of the TLS 1.3 PSK identity where the information shall be stored
 *  \param[in]     NewSessionTicketInfoPtr      Pointer to the info struct filled during parsing of NewSessionTicket
 *  \return        E_OK                         Information successfully stored
 *  \return        E_NOT_OK                     Information could not be stored
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_StoreNewSessionTicketInformation(
  TcpIp_TlsConnectionIterType                   TlsConIdx,
  TcpIp_Tls13PskIdentityIterType                StoreInfoTls13PskIdentityIdx,
  TCPIP_P2V(TcpIp_TlsNewSessionTicketInfoType)  NewSessionTicketInfoPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientHsStm_SendClientDummyCcs
 *********************************************************************************************************************/
/*! \brief         Trigger transmission of unencrypted dummy CCS message in the middlebox compatibility mode
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_SendClientDummyCcs(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientHsStm_ParseAndProcessServerFinished
 *********************************************************************************************************************/
/*! \brief         Parse and process the server finished message.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseAndProcessServerFinished(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ExtractServerFinishedInformation
 *********************************************************************************************************************/
/*! \brief         Extract the server finished information from the message
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ExtractServerFinishedInformation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_CompareFinishedVerifyData
 *********************************************************************************************************************/
/*! \brief         Compare the received server finished verify data with the expected one.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_CompareFinishedVerifyData(
  TcpIp_TlsConnectionIterType TlsConIdx);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_Tls13ClientHsStm_SendClientCertificate
 *********************************************************************************************************************/
/*! \brief         Prepares the transmission of the client Certificate message.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_SendClientCertificate(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_PrepareClientCertificateMessage
 *********************************************************************************************************************/
/*! \brief         Prepares the transmission of the client Certificate message.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_PrepareClientCertificateMessage(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_BuildClientCertificateMessage
 *********************************************************************************************************************/
/*! \brief         Sets up message elements.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_BuildClientCertificateMessage(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_BuildClientCertificateMessageAddContext
 *********************************************************************************************************************/
/*! \brief         Sets up message element Certificate.certificate_request_context.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_BuildClientCertificateMessageAddContext(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateList
 *********************************************************************************************************************/
/*! \brief         Sets up message element Certificate.certificate_list.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateList(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateListAddCerts
 *********************************************************************************************************************/
/*! \brief         Adds certificates to message element Certificate.certificate_list.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateListAddCerts(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateListAddCertData
 *********************************************************************************************************************/
/*! \brief         Adds certificate data to message element Certificate.certificate_list.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     CertificateId   KeyM certificate ID that is used to fetch certificate data.
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateListAddCertData(
  TcpIp_TlsConnectionIterType TlsConIdx,
  KeyM_CertificateIdType CertificateId);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateListAddCertExt
 *********************************************************************************************************************/
/*! \brief         Adds certificate extensions to message element Certificate.certificate_list.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateListAddCertExt(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientHsStm_SendClientCertificateVerify
 *********************************************************************************************************************/
/*! \brief         Prepares the transmission of the client CertificateVerify message.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_SendClientCertificateVerify(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyAddStaticData
 *********************************************************************************************************************/
/*! \brief         Sets up the static data of the client CertificateVerify message.
 *  \details       Static data means elements that are not affected by the signature calculation.
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyAddStaticData(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyStartSignatureCalc
 *********************************************************************************************************************/
/*! \brief         Prepares the async signature calculation of the client CertificateVerify message.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyStartSignatureCalc(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyWaitAsync
 *********************************************************************************************************************/
/*! \brief         Waits until the async operation has finished.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyWaitAsync(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyEncodeSign
 *********************************************************************************************************************/
/*! \brief         Encodes the calculated signature of the client CertificateVerify message.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyEncodeSign(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyFinalize
 *********************************************************************************************************************/
/*! \brief         Finalizes the creation of the client CertificateVerify message.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyFinalize(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13Client_PerformVerificationOfServerCertVerifySignature
 *********************************************************************************************************************/
/*! \brief         Manages the signature verification process of the server CertificateVerify message.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13Client_PerformVerificationOfServerCertVerifySignature(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13Client_CalcClientCertVerifySignature
 *********************************************************************************************************************/
/*! \brief         Manages the signature generation process of the client CertificateVerify message.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13Client_CalcClientCertVerifySignature(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientCrypto_VerifyServerCertVerifySignature
 *********************************************************************************************************************/
/*! \brief         Verifies the signature of the server CertificateVerify message.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientCrypto_VerifyServerCertVerifySignature(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientCrypto_BuildCertVerifySignedContent
 *********************************************************************************************************************/
/*! \brief         Builds the content which is then signed in the CertificateVerify message.
 *  \details       Can be used for either the server's and the client's CertificateVerify message
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     SegmentPtr      Pointer to the buffer segment where the content gets build
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientCrypto_BuildCertVerifySignedContent(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType SegmentPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientCrypto_CalcClientCertVerifySignatureSignedData
 *********************************************************************************************************************/
/*! \brief         Calculates the signature of the client CertificateVerify message.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientCrypto_CalcClientCertVerifySignatureSignedData(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif

/**********************************************************************************************************************
 * TcpIp_Tls13ClientHsStm_SendClientFinished
 *********************************************************************************************************************/
/*! \brief         Send the client finished message.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_SendClientFinished(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_PrepareClientFinished
 *********************************************************************************************************************/
/*! \brief         Prepare the client finished message.
 *  \details       Add the handshake header, trigger to calculate the verify data, and complete the message generation.
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_PrepareClientFinished(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientHsStm_SendClientFinished
 *********************************************************************************************************************/
/*! \brief         Set the trigger to calculate the clients verify data for the client finished message.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientFinishedAddClientFinishedData(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientHsStm_FinalizeHandshake
 *********************************************************************************************************************/
/*! \brief         Finalize the TLS handshake for the TLS-Client and prepare TLS buffer for application data.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_FinalizeHandshake(
  TcpIp_TlsConnectionIterType TlsConIdx);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13ClientCtx_GetHandshakeIterTypeFromCurveId
 *********************************************************************************************************************/
/*! \brief          Gets a handshake index which curve matches to the passed CurveId
 *  \details        -
 *  \param[in]      TlsConIdx                 TLS connection index
 *                                            CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]      CurveId                   Curve Id which should be matched by the handshake's curve
 *  \param[in,out]  MatchingHandshakeIterPtr  Pointer where the matching handshake index should be saved
 *  \return         E_OK                      Matching handshake index found
 *                  E_NOT_OK                  No matching handshake index found
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientCtx_GetHandshakeIterTypeFromCurveId(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsEllipticCurveIdType CurveId,
  TCPIP_P2V(TcpIp_TlsHandshakeIterType) MatchingHandshakeIterPtr);
#   endif


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_Tls13Client_RequestUsageOfSessionResumption
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_RequestUsageOfSessionResumption(
  TcpIp_SizeOfSocketTcpDynType SocketTcpIdx,
  TcpIp_SizeOfSocketTcpDynType ResumptionBaseSocketTcpIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  TcpIp_Tls13PskIdentityIterType availableTls13PskIdentityIdx = 0;  /* index of the PSK identity that will be used for this connection */
  boolean availablePskIdentityFound = FALSE;  /* keeps track if a ticket with state 'available' was found */

  TcpIp_TlsConnectionIterType resumptionBaseTlsConIdx
    = TcpIp_GetTlsConnectionIdxOfSocketTcpDyn(ResumptionBaseSocketTcpIdx);
  TcpIp_Tls13PskIdentityIndIterType tls13PskIdentityIndIdx
    = TcpIp_GetTls13PskIdentityIndStartIdxOfTlsConnection(resumptionBaseTlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check that the resumption base connection is in state established. */
  if (TcpIp_GetConnectionStateOfTlsConnectionDyn(resumptionBaseTlsConIdx) == TCPIP_TLS_STATE_CONNECTION_ESTABLISHED)
  {
    /* #20 Iterate over all PSK identities for the resumption base connection. */
    for (; tls13PskIdentityIndIdx < TcpIp_GetTls13PskIdentityIndEndIdxOfTlsConnection(resumptionBaseTlsConIdx);
           tls13PskIdentityIndIdx++)
    {
      TcpIp_Tls13PskIdentityIndType tls13PskIdentityIdx = TcpIp_GetTls13PskIdentityInd(tls13PskIdentityIndIdx);
      TcpIp_TlsSessionTicketStateType state = TcpIp_GetSessionTicketStateOfTls13PskIdentityDyn(tls13PskIdentityIdx);

      /* #30 Check if PSK identity is available. */
      if (state == TCPIP_TLS_SESSION_TICKET_AVAILABLE)
      {
        /* found an available PSK identity */
        availablePskIdentityFound = TRUE;
        availableTls13PskIdentityIdx = tls13PskIdentityIdx;

        /* stop the for-loop */
        break;
      }
    }

    /* #40 If an available PSK was found, assign it to the connection and mark it as reserved. */
    if (availablePskIdentityFound == TRUE)
    {
      /* convert SocketTcpIdx to TlsConIdx */
      TcpIp_TlsConnectionIterType resumedTlsConIdx = 0u;
      if (TcpIp_SocketIdxToTlsConIdx(TCPIP_TCP_IDX_TO_SOCKET_IDX(SocketTcpIdx), &resumedTlsConIdx) == E_OK)
      {
        retVal = TcpIp_Tls13Client_AssignPskIdentityToResumedConnection(resumptionBaseTlsConIdx, resumedTlsConIdx,
          availableTls13PskIdentityIdx);
      }
      else
      {
        /* Conversion of SocketTcpIdx to TlsConIdx failed, this should not happen. */
      }
    }
    else
    {
      /* No matching PSK found. No need to issue the session ticket update callback. */
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_AssignPskIdentityToResumedConnection
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AssignPskIdentityToResumedConnection(
  TcpIp_TlsConnectionIterType     ResumptionBaseTlsConIdx,
  TcpIp_TlsConnectionIterType     ResumedTlsConIdx,
  TcpIp_Tls13PskIdentityIterType  AvailableTls13PskIdentityIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check that the resumed connection is allocated */
  if (TcpIp_GetConnectionStateOfTlsConnectionDyn(ResumedTlsConIdx) == TCPIP_TLS_STATE_CONNECTION_ALLOCATED)
  {
    /* #20 Check that this session resumption request is not duplicated on this connection. */
    /* If there was already a handshake using session resumption and the connection was closed again,
     * SessionResumptionUsingPsk will be set to false and the connection can be used again.
     * However if the request is just repeated without an handshake E_NOT_OK will be returned with one exception:
     * If the ticket, which was assigned to the resumed connection with the first request,
     * expired before TcpConnect() was invoked (see TcpIp_Tls13Client_MaintainSessionTicketAge()),
     * SessionResumptionUsingPsk will be set to false
     * and another session resumption request on the same resumed connection can be accepted. */
    if (TcpIp_IsSessionResumptionUsingPskOfTlsConnectionDyn(ResumedTlsConIdx) == FALSE)
    {
      /* #30 Copy the resumption master secret to the resumed connection. */
      if (TcpIp_Tls13Client_CopySessionResumptionMasterSecret(ResumptionBaseTlsConIdx, ResumedTlsConIdx) == E_OK)
      {
        /* #40 Mark PSK as reserved. */
        TcpIp_SetSessionTicketStateOfTls13PskIdentityDyn(AvailableTls13PskIdentityIdx,
          TCPIP_TLS_SESSION_TICKET_RESERVED);

        /* #50 Link PSK to the connection. */
        TcpIp_SetTls13PskIdentityActiveIdxOfTlsConnectionDyn(ResumedTlsConIdx,
          (TcpIp_Tls13PskIdentityActiveIdxOfTlsConnectionDynType)AvailableTls13PskIdentityIdx);
        TcpIp_SetSessionResumptionUsingPskOfTlsConnectionDyn(ResumedTlsConIdx, TRUE);

        /* #60 Issue callback indicating the (new) current number of available tickets. */
        TcpIp_Tls13Client_SessionTicketUpdateCallout(ResumptionBaseTlsConIdx);

        retVal = E_OK;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_CopySessionResumptionMasterSecret
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_CopySessionResumptionMasterSecret(
  TcpIp_TlsConnectionIterType  ResumptionBaseTlsConIdx,
  TcpIp_TlsConnectionIterType  ResumedTlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsResumedConnectionIterType tlsResumedConIdx
    = TcpIp_GetTlsResumedConnectionIdxOfTlsConnection(ResumedTlsConIdx);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  if (tlsResumedConIdx != TCPIP_NO_TLSRESUMEDCONNECTIONIDXOFTLSCONNECTION)
  {
    /* Check that in the config the Id for the resumption base connection of the resumed connection is equal to the
     * Id which was passed as a variable to this function. */
    if (TcpIp_GetTlsConnectionResumptionBaseIdxOfTlsResumedConnection(tlsResumedConIdx) == ResumptionBaseTlsConIdx)
    {
      /* Get the CSM resumption master secret key Ids of both connections. */
      TcpIp_CsmKeyIdType resumedConResumptionMasterSecretKeyId
        = TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdResumptionMasterSecretIdxOfTlsConnection(ResumedTlsConIdx));
      TcpIp_CsmKeyIdType resBaseConResumptionMasterSecretKeyId
        = TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdResumptionMasterSecretIdxOfTlsConnection(ResumptionBaseTlsConIdx));

      /* A validator already secures that the CSM key reference must be configured.
       * Nevertheless it is checked here to ensure it. */
      if (   (resumedConResumptionMasterSecretKeyId != TCPIP_NO_CSMKEYIDRESUMPTIONMASTERSECRETIDXOFTLSCONNECTION)
          && (resBaseConResumptionMasterSecretKeyId != TCPIP_NO_CSMKEYIDRESUMPTIONMASTERSECRETIDXOFTLSCONNECTION))
      {
        uint32 resMasterSecretKeyElementId = CRYPTO_KE_KEYDERIVATION_PASSWORD;

        /* #10 Copy the resumption master secret from the resumption base connection to the resumed connection. */
        Std_ReturnType csmRetVal = TCPIP_CSM_KeyElementCopy(resBaseConResumptionMasterSecretKeyId,
          resMasterSecretKeyElementId, resumedConResumptionMasterSecretKeyId, resMasterSecretKeyElementId);
        csmRetVal |= TCPIP_CSM_KeySetValid(resumedConResumptionMasterSecretKeyId);

        if (csmRetVal == E_OK)
        {
          retVal = E_OK;
        }
      }
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_IssueChangeableCipherCallout
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_IssueChangeableCipherCallout(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfSocketOwnerConfigType socketOwnerConfigIdx = TcpIp_GetSocketOwnerConfigIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_SizeOfSocketDynType socketIdx = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_TlsCipherWorkingSetMgmtIdxOfTlsConnectionType tlsCipherWorkingSetMgmtIdx
    = TcpIp_GetTlsCipherWorkingSetMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsChangeCipherStatusType changeCipherStatus = TCPIP_TLS_CHANGE_CHIPHER_STATUS_PENDING;
  TcpIp_SccPushButtonModeOfTlsClientConnectionType sccPushButtonMode = FALSE;

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Issue the change cipher callout if applicable. */
  if ((socketIdx < TcpIp_GetSizeOfSocketDyn()) && (socketOwnerConfigIdx < TcpIp_GetSizeOfSocketOwnerConfig()))
  {
    if (TcpIp_GetTlsChangeableCipherFuncPtrOfSocketOwnerConfig(socketOwnerConfigIdx) != NULL_PTR)
    {
      /* #20 Issue the callout. */
      if (TcpIp_GetTlsChangeableCipherFuncPtrOfSocketOwnerConfig(socketOwnerConfigIdx)(
        TCPIP_SOCKET_IDX_TO_ID(socketIdx),
        TcpIp_GetAddrCipherSuiteWorkingSetOfTlsCipherWorkingSetMgmt(tlsCipherWorkingSetMgmtIdx),
        TcpIp_GetAddrSignatureAlgorithmWorkingSetOfTlsCipherWorkingSetMgmt(tlsCipherWorkingSetMgmtIdx),
        &sccPushButtonMode,
        &changeCipherStatus) == E_OK)
      {
        /* #30 Proceed depending on the callout status. */
        switch (changeCipherStatus)
        {
          case TCPIP_TLS_CHANGE_CHIPHER_STATUS_PENDING:
          {
            /* The result of the callout is pending. Do nothing, just wait. */
            retVal = E_OK;
            break;
          }
          case TCPIP_TLS_CHANGE_CHIPHER_STATUS_READY:
          {
            /* The callout succeeded, and the prioritized lists of cipher suites and signature algorithms are available. */

            /* #40 Set the flag for the push button mode from SCC */
            TcpIp_SetSccPushButtonModeOfTlsClientConnection(tlsClientConnectionIdx, sccPushButtonMode);

            /* #50 Check consistency of user configured lists */
            if (TcpIp_Tls13Client_CheckConsistencyOfCipherSuiteAndSignAlgoWorkingSets(TlsConIdx) == E_OK)
            {
              /* #60 Switch to next handshake state. */
              TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_HELLO);
              retVal = E_OK;
            }
            else
            {
              /* Issue an alert (handshake failure) and cancel the handshake */
              TcpIp_TlsClientHsStm_HandleErrorDuringPreparation(TlsConIdx);
            }
            break;
          }
          default:  /* TCPIP_TLS_CHANGE_CHIPHER_STATUS_ERROR */
          {
            /* Preparation failed. The socket owner can not process the change request (e.g. erroneous parameters, internal
             * error, ...). Issue an alert (internal error, different than in HandleErrorDuringPreparation) and cancel
             * the handshake. */
            /* retVal is E_NOT_OK by default */
            break;
          }
        }
      }
    }
  }
  return retVal;
} /* TcpIp_Tls13Client_IssueChangeableCipherCallout() */

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_CheckConsistencyOfCipherSuiteAndSignAlgoWorkingSets
 *********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
  */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_CheckConsistencyOfCipherSuiteAndSignAlgoWorkingSets(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  TcpIp_TlsCipherWorkingSetMgmtIdxOfTlsConnectionType tlsCipherWorkingSetMgmtIdx
    = TcpIp_GetTlsCipherWorkingSetMgmtIdxOfTlsConnection(TlsConIdx);

  TCPIP_P2C(TcpIp_TlsCipherSuiteWorkingSetType) cipherSuitePtr
    = TcpIp_GetAddrCipherSuiteWorkingSetOfTlsCipherWorkingSetMgmt(tlsCipherWorkingSetMgmtIdx);
  TCPIP_P2C(TcpIp_TlsSignatureAlgorithmWorkingSetType) signAlgoPtr
    = TcpIp_GetAddrSignatureAlgorithmWorkingSetOfTlsCipherWorkingSetMgmt(tlsCipherWorkingSetMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check that length of working set is not 0 */
  if (   (cipherSuitePtr->workingSetLen == 0u)
      || (signAlgoPtr->workingSetLen == 0u))
  {
    retVal = E_NOT_OK;
  }
  if (   (cipherSuitePtr->workingSetLen > TCPIP_TLS_CIPHERSUITE_AMOUNT)
      || (signAlgoPtr->workingSetLen > TCPIP_TLS_SIGNATURE_ALGO_AMOUNT))
  {
    retVal = E_NOT_OK;
  }

  /* It is possible to add more checks here.
   * Since we assume that the user knows what he does and is responsible to achieve consistency in his reordering/deletion
   * process of the cipher suites and/or signature algorithms, we do not add any more checks for now. */

  return retVal;
}

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ClientHelloExtAddCertificateAuthoritiesList
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtAddCertificateAuthoritiesList(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferTxIterType   ExtAuthoritiesStartIdx,
  TCPIP_P2V(uint16)           ConsumedLenPtr)
{
  /* RFC8446 - 4.2.4. Certificate Authorities */
  /*
   *   opaque DistinguishedName<1..2^16-1>;
   *
   *   struct {
   *      DistinguishedName authorities<3..2^16-1>;
   *   } CertificateAuthoritiesExtension;
   */

  /* ----- Local Variables----------------------------------------------- */
  KeyM_CertificateStatusType currentCertificateStatus;

  TcpIp_TlsCertIdIssuerStartIdxOfTlsConnectionType issuerTlsCertIdIdx;

  TcpIp_SignatureAlgorithmIdType signAlgId = TCPIP_SIG_ALGO_ID_NONE;

  /* ----- Implementation ----------------------------------------------- */
  /* Initialize out-parameter */
  *ConsumedLenPtr = 0u;

  /* #10 iterate over all referenced issuer certificates of this TLS connection (root certificates) */
  for (issuerTlsCertIdIdx = TcpIp_GetTlsCertIdIssuerStartIdxOfTlsConnection(TlsConIdx);
    issuerTlsCertIdIdx < TcpIp_GetTlsCertIdIssuerEndIdxOfTlsConnection(TlsConIdx);
    issuerTlsCertIdIdx++)
  {
    KeyM_CertificateIdType certId = TcpIp_GetTlsCertId(issuerTlsCertIdIdx);

    if (TcpIp_TlsCoreUtil_ReadCertSignatureAlgorithm(certId, &signAlgId) == E_OK)
    {
      /* If the changeable cipher callback is configured the working set could be changed by the upper layer.
       * Therefore, it is checked whether the signature algorithm of the certificate is still in the working set of the
       * signature algorithms. If not, this certificate will be skipped. */
      if (   (TcpIp_IsTlsUseChangeableCipherCallbackOfTlsConnection(TlsConIdx) == FALSE)
          || (TcpIp_TlsClient_IsSignatureAlgorithmInWorkingSet(TlsConIdx, signAlgId) == TRUE))                          /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
      {
        /* #20 Check the status of the current selected certificate */
        if (   (KeyM_CertGetStatus(certId, &currentCertificateStatus) == E_OK)
            && (   (currentCertificateStatus == KEYM_CERTIFICATE_PARSED_NOT_VALIDATED)
                || (currentCertificateStatus == KEYM_CERTIFICATE_VALID)))
        {
          /* #30 Write DN of the certificate to Tx buffer */
          TcpIp_Tls13ClientMsg_ClientHelloExtWriteDnToTxBuffer(TlsConIdx, ExtAuthoritiesStartIdx, certId, ConsumedLenPtr);
        }
        /* else - No need to cancel TLS handshake in case of invalid certificate status */
      }
      /* else - Do not add DN of this certificate to certificate_authorities extension */
    }
  }
} /* TcpIp_Tls13ClientMsg_ClientHelloExtAddCertificateAuthoritiesList() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ClientHelloExtWriteDnToTxBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtWriteDnToTxBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferTxIterType   ExtAuthoritiesStartIdx,
  KeyM_CertificateIdType      CertId,
  TCPIP_P2V(uint16)           ConsumedLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check for configured maximum size of all DNs and calculate free space for the next DN */
  if (   TcpIp_GetTlsMaxSizeDistinguishedNamesOfTlsConnection(TlsConIdx)
      >= (*ConsumedLenPtr + TCPIP_TLS_DIST_NAME_LENGTH_LEN))
  {
    uint32 freeConfiguredSpaceForNextDN =
      TcpIp_GetTlsMaxSizeDistinguishedNamesOfTlsConnection(TlsConIdx)
      - ((uint32)(*ConsumedLenPtr) + TCPIP_TLS_DIST_NAME_LENGTH_LEN);

    /* This value will be passed to KeyM to validate if this is enough to fit the next DN */
    uint32 subjectNameDataLength = freeConfiguredSpaceForNextDN;

    /* Calculate the real free space in the TxBuffer for the next DN */
    uint32 freeRealSpaceForNextDN =
      TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx)
      - ((uint32)ExtAuthoritiesStartIdx + *ConsumedLenPtr + TCPIP_TLS_DIST_NAME_LENGTH_LEN);

    if (freeRealSpaceForNextDN < freeConfiguredSpaceForNextDN)
    {
      /* If the real free space is lower than the space left regarding the config values,
        * it is likely that the TxBuffer size is configured to small.
        * Consider the smallest value of offreeRealSpaceForNextDN and freeConfiguredSpaceForNextDN
        * for the KeyM operation. */
      subjectNameDataLength = freeRealSpaceForNextDN;
    }

    /* #20 Read DN of the certificate from KeyM and write it to Tx buffer */
    if (KeyM_CertStructureGet(CertId,
          KEYM_CERTIFICATE_SUBJECT_NAME,
          TcpIp_GetAddrTlsBufferTx(
            ExtAuthoritiesStartIdx + *ConsumedLenPtr + TCPIP_TLS_DIST_NAME_LENGTH_LEN),
          &subjectNameDataLength) == E_OK)
    {
      /* #30 Write length of DN to Tx Buffer */
      IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(ExtAuthoritiesStartIdx + *ConsumedLenPtr), 0, (uint16)subjectNameDataLength);

      /* Increase consumed length by the length of the length-field and the length of the DN */
      *ConsumedLenPtr += (TCPIP_TLS_DIST_NAME_LENGTH_LEN + (uint16)subjectNameDataLength);
    }
  }
  /* else - distinguished names are longer than maximum configured length of all DNs - do not add DNs anymore */

} /* TcpIp_Tls13ClientMsg_ClientHelloExtWriteDnToTxBuffer() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ClientHelloExtAddCertificateAuthorities
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
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtAddCertificateAuthorities(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);
  TcpIp_SizeOfTlsBufferMgmtType     tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_SccPushButtonModeOfTlsClientConnectionType sccPushButtonMode
    = TcpIp_IsSccPushButtonModeOfTlsClientConnection(tlsClientConnectionIdx);

  /* Extension index information */
  /*    +---> extTypeTlsBufferTxIdx
   *   /         +---> extTlsBufferTxIdx
   *  /         /
   * [Ext Type][Ext Len][Distinguished Names Length][DER certificate Authority_1][DER certificate Authority_2]...
   *                     ^                          \________(optional)_______consumedExtensionLen______________/
   *                     |                          ^
   *                     |                          |
   *                     |                          extAuthoritiesStartIdx
   *                     extCertAuthLenTlsBufferTxIdx

   Format of the DN list:
    0x00, 0xF0,      total length of all DNs (2 bytes length field)
    0x00, 0x76,      length of DN_0          (2 bytes length field)
    0x30, 0x74, ...  <DER encoded DN_0>
    0x00, 0x76,      length of DN_1          (2 bytes length field)
    0x30, 0x74, ...  <DER encoded DN_1>
    ...
   */
  TcpIp_TlsBufferTxIterType extTypeTlsBufferTxIdx = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_TlsBufferTxIterType extTlsBufferTxIdx = extTypeTlsBufferTxIdx + TCPIP_TLS_EXTENSION_TYPE_LEN;
  TcpIp_TlsBufferTxIterType extCertAuthLenTlsBufferTxIdx = extTlsBufferTxIdx + TCPIP_TLS_EXTENSION_LENGTH_LEN;
  TcpIp_TlsBufferTxIterType extAuthoritiesStartIdx = extCertAuthLenTlsBufferTxIdx + TCPIP_TLS_DIST_NAMES_LENGTH_LEN;
  uint16 consumedExtensionLen = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if PushButtonMode is enabled by the SCC */
  if (sccPushButtonMode == TRUE)
  {
    /* PushButtonMode enabled - do not send this extension. */
    /* Nothing to do here. Type and Length field will be set at the bottom of this function
     * and only if any certificate authorities are available. */
  }
  else
  {
    /* PushButtonMode disabled - fill extension with DN's from certificates. */
    TcpIp_Tls13ClientMsg_ClientHelloExtAddCertificateAuthoritiesList(TlsConIdx, extAuthoritiesStartIdx,
      &consumedExtensionLen);
  }

  /* #20 Only add the extension if it is non-empty and update the length information in the TLS TxBuffer */
  if (consumedExtensionLen != 0u)
  {
    /* #30 Set the extension type to TCPIP_TLS_EXTENSION_CERTIFICATE_AUTHORITIES (0x002F) */
    IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extTypeTlsBufferTxIdx), 0, TCPIP_TLS_EXTENSION_CERTIFICATE_AUTHORITIES);
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_TYPE_LEN);

    /* #40 Set extension length */
    IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extTlsBufferTxIdx), 0, consumedExtensionLen + TCPIP_TLS_DIST_NAMES_LENGTH_LEN);
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_LENGTH_LEN);

    /* #50 Set extension certificate authorities length */
    IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extCertAuthLenTlsBufferTxIdx), 0, consumedExtensionLen);
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_DIST_NAMES_LENGTH_LEN);

    /* #60 Set the write idx after the extension (consumedExtensionLen) */
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, consumedExtensionLen);
  }
} /* TcpIp_Tls13ClientMsg_ClientHelloExtAddCertificateAuthorities() */
#   endif

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ClientHelloExtAddSupportedVersions
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
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtAddSupportedVersions(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerIndIterType tlsCipherWorkerIndIdx;
  TcpIp_SizeOfTlsBufferMgmtType     tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* Extension index information */
  /* Client Supported Versions Extension Format
   *       [ext Type][ext Len][Supported Versions Len][version 1]        [version n]
   * Byte: 0       1 2      3 4                      5 6        7         (x-1)    x
   *                                                    \---consumedExtensionLen---/
   */
  TcpIp_TlsBufferTxIterType extTypeTlsBufferTxIdx = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_TlsBufferTxIterType extLenTlsBufferTxIdx = extTypeTlsBufferTxIdx + TCPIP_TLS_EXTENSION_TYPE_LEN;
  TcpIp_TlsBufferTxIterType extSupportedVersionsLenIdx = extLenTlsBufferTxIdx + TCPIP_TLS_EXTENSION_LENGTH_LEN;
  TcpIp_TlsBufferTxIterType extAlgorithmsStartIdx = extSupportedVersionsLenIdx + TCPIP_TLS_EXTENSION_SUPPORTED_VERSIONS_LENGTH_LEN;

  /* The supported versions length is actually an uint8 value,
   * but since TcpIp_Tls12ClientMsg_ClientHelloAddExtensionValue() expects an uint16 value and
   * we won't ever add that many supported versions, we use an uint16 value and cast it to uint8 when adding to the buffer. */
  uint16 consumedExtensionLen = 0;
  boolean configuredTls12Cipher = FALSE;
  boolean configuredTls13Cipher = FALSE;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Write all available supported versions in the TLS TxBuffer */
  /* Iterate over all configured CipherWorker for this TLS connection */
  for (tlsCipherWorkerIndIdx = TcpIp_GetTlsCipherWorkerIndStartIdxOfTlsConnection(TlsConIdx);
    tlsCipherWorkerIndIdx < TcpIp_GetTlsCipherWorkerIndEndIdxOfTlsConnection(TlsConIdx);
    tlsCipherWorkerIndIdx++)
  {
    TcpIp_TlsCipherWorkerIterType tlsCipherWorkerIdx = TcpIp_GetTlsCipherWorkerInd(tlsCipherWorkerIndIdx);
    TcpIp_TlsCipherDefinitionIdxOfTlsCipherWorkerType tlsCipherDefinitionIdx
      = TcpIp_GetTlsCipherDefinitionIdxOfTlsCipherWorker(tlsCipherWorkerIdx);
    TcpIp_TlsVersionType cipherSuiteTlsVersion
      = TcpIp_GetTlsVersionOfTlsCipherDefinition(tlsCipherDefinitionIdx);
    TcpIp_TlsCipherDataType cipherSuiteId
      = TcpIp_GetCipherSuiteIdOfTlsCipherDefinition(tlsCipherDefinitionIdx);

    /* Only check if cipher suite is contained in working set if callout is configured */
    if (   (TcpIp_IsTlsUseChangeableCipherCallbackOfTlsConnection(TlsConIdx) == FALSE)
        || (TcpIp_TlsClient_IsCipherSuiteInWorkingSet(TlsConIdx, cipherSuiteId) == TRUE))                               /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
    {
      if (cipherSuiteTlsVersion == TCPIP_TLSVERSION_13)
      {
        configuredTls13Cipher = TRUE;
      }
      else
      {
        configuredTls12Cipher = TRUE;
      }
    }
  }

  /* Prioritize TLS 1.3 if corresponding cipher is available.
   * According to RFC8466 Section 4.2.1, the client sends the "list of supported
   * versions in preference order, with the most preferred version first." */
  if (configuredTls13Cipher == TRUE)
  {
    TcpIp_TlsMsg_AddUint16ValueToDistinctListInTxBuffer(TlsConIdx, TCPIP_TLS_PROTOCOLVERSION_TLS13,
      extAlgorithmsStartIdx, &consumedExtensionLen);
  }
  if (configuredTls12Cipher == TRUE)
  {
    TcpIp_TlsMsg_AddUint16ValueToDistinctListInTxBuffer(TlsConIdx, TCPIP_TLS_PROTOCOLVERSION_TLS12,
      extAlgorithmsStartIdx, &consumedExtensionLen);
  }

  /* #20 Check if there are extensions added and update the length information in the TLS TxBuffer */
  if (consumedExtensionLen != 0u)
  {
    /* #30 Set the extension type to TCPIP_TLS_EXTENSION_SUPPORTED_VERSIONS (0x002B) */
    IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extTypeTlsBufferTxIdx), 0, TCPIP_TLS_EXTENSION_SUPPORTED_VERSIONS);
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_TYPE_LEN);

    /* #40 Set extension supported versions length */
    IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(extSupportedVersionsLenIdx), 0, (uint8)consumedExtensionLen);              /* TCPIP_CSL_NAME_LENGTH */
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_SUPPORTED_VERSIONS_LENGTH_LEN);

    /* #50 Set extension length */
    IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extLenTlsBufferTxIdx), 0, consumedExtensionLen + TCPIP_TLS_EXTENSION_SUPPORTED_VERSIONS_LENGTH_LEN);
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_LENGTH_LEN);
  }
} /* TcpIp_Tls13ClientMsg_ClientHelloExtAddSupportedVersions() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ClientHelloExtAddPreSharedKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtAddPreSharedKey(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType    tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_SizeOfTlsClientBufferMgmtType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* Extension index information */
  /* Client Pre Shared Keys Extension Format
   *       [ext Type][ext Len][Psk identities Len][Psk identity 1]...[Psk identity n][Psk binders Len][Psk binders]
   * Byte: 0       1 2      3 4                 5 6             x    (x+1)         y (y+1)      (y+2) (y+3)       z
   *
   * Psk identity format
   *       [Psk identity Len][Psk identity][Obfuscated Ticket Age]
   * Byte: 0               1 2           u (u+1)             (u+4)
   */

  /* Right now we only send one identity and the corresponding binder in this extension. */
  TcpIp_Tls13PskIdentityActiveIdxOfTlsConnectionDynType activeTls13PskIdentityIdx
    = TcpIp_GetTls13PskIdentityActiveIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_Tls13PskIdentityBufferStartIdxOfTls13PskIdentityType startTls13PskIdentityBufferIdx
    = TcpIp_GetTls13PskIdentityBufferStartIdxOfTls13PskIdentity(activeTls13PskIdentityIdx);

  uint16 pskIdentityLen = TcpIp_GetPskIdentityLenOfTls13PskIdentityDyn(activeTls13PskIdentityIdx);
  uint16 pskIdentitiesLen = TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_IDENTITIY_LENGTH_LEN
    + pskIdentityLen + TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_OBFUSCATED_TICKET_AGE_LEN;
  uint8 pskBinderLen = TcpIp_GetHashLengthOfTls13PskIdentityDyn(activeTls13PskIdentityIdx);
  uint16 pskBindersLen = TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_BINDER_LENGTH_LEN + (uint16) pskBinderLen;
  uint16 extensionLen = TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_IDENTITIES_LENGTH_LEN + pskIdentitiesLen
                         + TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_BINDERS_LENGTH_LEN + pskBindersLen;

  TcpIp_TlsBufferTxIterType extTypeTlsBufferTxIdx = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_TlsBufferTxIterType extLenTlsBufferTxIdx = extTypeTlsBufferTxIdx + TCPIP_TLS_EXTENSION_TYPE_LEN;
  TcpIp_TlsBufferTxIterType extPskIdentitiesLenIdx = extLenTlsBufferTxIdx + TCPIP_TLS_EXTENSION_LENGTH_LEN;
  TcpIp_TlsBufferTxIterType extPskBindersLenIdx = extPskIdentitiesLenIdx
    + TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_IDENTITIES_LENGTH_LEN + (TcpIp_TlsBufferTxIterType) pskIdentitiesLen;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the extension type to TCPIP_TLS_EXTENSION_PRE_SHARED_KEY (0x0029) */
  IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extTypeTlsBufferTxIdx), 0, TCPIP_TLS_EXTENSION_PRE_SHARED_KEY);
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_TYPE_LEN);

  /* #20 Set extension length */
  IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extLenTlsBufferTxIdx), 0, extensionLen);
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_LENGTH_LEN);

  /* #30 Set PSK identities length */
  IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extPskIdentitiesLenIdx), 0, pskIdentitiesLen);                              /* TCPIP_CSL_NAME_LENGTH */
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
    TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_IDENTITIES_LENGTH_LEN);
  /* Set single PSK identity length */
  IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extPskIdentitiesLenIdx),                                                    /* TCPIP_CSL_NAME_LENGTH */
    TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_IDENTITIES_LENGTH_LEN, pskIdentityLen);
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
    TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_IDENTITIY_LENGTH_LEN);

  /* copy identity and obfuscated ticket age to buffer */
  VStdMemCpy(TcpIp_GetAddrTlsBufferTx((extPskIdentitiesLenIdx
      + TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_IDENTITIES_LENGTH_LEN
      + TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_IDENTITIY_LENGTH_LEN)),
    TcpIp_GetAddrTls13PskIdentityBuffer(startTls13PskIdentityBufferIdx), pskIdentityLen);
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, pskIdentityLen);
  uint32 obfuscatedTicketAge = TcpIp_Tls13ClientMsg_ClientHelloExtCalcObfuscatedTicketAge(activeTls13PskIdentityIdx);
  IpBase_PutUint32(TcpIp_GetAddrTlsBufferTx(extPskIdentitiesLenIdx),                                                    /* TCPIP_CSL_NAME_LENGTH */
    (TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_IDENTITIES_LENGTH_LEN
      + TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_IDENTITIY_LENGTH_LEN + (uint32)pskIdentityLen), obfuscatedTicketAge);
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
    TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_OBFUSCATED_TICKET_AGE_LEN);

  /* #40 Set PSK binders length */
  IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extPskBindersLenIdx), 0, pskBindersLen);                                    /* TCPIP_CSL_NAME_LENGTH */
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
    TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_BINDERS_LENGTH_LEN);
  IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(extPskBindersLenIdx),                                                        /* TCPIP_CSL_NAME_LENGTH */
    TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_BINDERS_LENGTH_LEN, pskBinderLen);
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
    TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_BINDER_LENGTH_LEN);

  /* The binder has to be calculated first before it can be added to the message.
   * Store the current buffer index and already increment the write index for the binder,
   * so that the length fields of the ClientHello can already be set to the correct value.
   * This is necessary to do before the binder is calculated
   * since a hash over the ClientHello contributed to that calculation (RFC8446 chapter 4.2.11.2). */
  TcpIp_SetTlsBufferTxClientHelloPreSharedKeyExtBinderIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, pskBinderLen);
} /* TcpIp_Tls13ClientMsg_ClientHelloExtAddPreSharedKey() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ClientHelloExtCalcObfuscatedTicketAge
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(uint32, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtCalcObfuscatedTicketAge(
  TcpIp_Tls13PskIdentityIterType Tls13PskIdentityIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 maxTicketAgeInMainFunctionCycles
    = TcpIp_GetMaxTicketAgeOfTls13PskIdentityDyn(Tls13PskIdentityIdx) * TCPIP_CYCLES_PER_SECOND;
  uint32 countDownTicketLifetime = TcpIp_GetCountDownTicketLifetimeOfTls13PskIdentityDyn(Tls13PskIdentityIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* No underflow possible, countDownTicketLifetime is set to MaxTicketAge * TCPIP_CYCLES_PER_SECOND
   * and only decremented afterwards. */
  TCPIP_ASSERT(maxTicketAgeInMainFunctionCycles >= countDownTicketLifetime);
  uint32 actualTicketAgeInMainFunctionCycles = maxTicketAgeInMainFunctionCycles - countDownTicketLifetime;
  uint32 actualTicketAgeInMs = actualTicketAgeInMainFunctionCycles * TCPIP_MAIN_FCT_PERIOD_MSEC;
  uint32 ticketAgeAdd = TcpIp_GetTicketAgeAddOfTls13PskIdentityDyn(Tls13PskIdentityIdx);

  /* RFC8446 chapter 4.2.11.1:
   * The "obfuscated_ticket_age" field of each PskIdentity contains an obfuscated version of the ticket age
   * formed by taking the age in milliseconds and adding the "ticket_age_add" value that was included
   * with the ticket(see Section 4.6.1), modulo 2 ^ 32 */
  /* Intentionally do not handle possible overflow to calculate a modulo 2 ^ 32. */
  /* #10 Calculate the obfuscated ticket age. */
  return ticketAgeAdd + actualTicketAgeInMs;

} /* TcpIp_Tls13ClientMsg_ClientHelloExtCalcObfuscatedTicketAge() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ClientHelloExtCopyPskBinderToTxBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtCopyPskBinderToTxBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientBufferMgmtIdxOfTlsConnectionType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_Tls13PskIdentityActiveIdxOfTlsConnectionDynType activeTls13PskIdentityIdx
    = TcpIp_GetTls13PskIdentityActiveIdxOfTlsConnectionDyn(TlsConIdx);

  uint8 hashLength = TcpIp_GetHashLengthOfTls13PskIdentityDyn(activeTls13PskIdentityIdx);

  /* Initialize the verifyData length with the size of the available buffer. */
  uint32 hmacBufferLength = (uint32)TcpIp_GetTlsTemporaryHmacBufferEndIdxOfTlsConnection(TlsConIdx)
    - TcpIp_GetTlsTemporaryHmacBufferStartIdxOfTlsConnection(TlsConIdx);

  TcpIp_ConstSegmentType binderSegment = { 0u };

  /* ----- Implementation ----------------------------------------------- */
  /* Initialize a const segment for the Hmac buffer where the calculated binder is stored. */
  TcpIp_ConstSegmentInit(&binderSegment,
    TcpIp_GetAddrTlsTemporaryHmacBuffer(TcpIp_GetTlsTemporaryHmacBufferStartIdxOfTlsConnection(TlsConIdx)),
    hmacBufferLength);

  /* #10 Copy the calculated binder to the pre_shared_keys extension in the TLS Tx buffer. */
  TcpIp_MemCpyFromConstSegmentSafe(TcpIp_GetAddrTlsBufferTx(
    TcpIp_GetTlsBufferTxClientHelloPreSharedKeyExtBinderIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx)),
    0u, hashLength, &binderSegment, hashLength);

} /* TcpIp_Tls13ClientMsg_ClientHelloExtCopyPskBinderToTxBuffer() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ClientHelloExtAddPskKeyExchangeModes
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtAddPskKeyExchangeModes(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* Currently we only support one key exchange mode: psk_dhe_ke.
   * Thus we only offer this mode. */

  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the extension type to TCPIP_TLS_EXTENSION_PSK_KEY_EXCHANGE_MODES. */
  IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)), 0,
    TCPIP_TLS_EXTENSION_PSK_KEY_EXCHANGE_MODES);
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_TYPE_LEN);

  /* #20 Add the ExtensionDataLength. */
  uint16 extensionDataLength = TCPIP_TLS_EXTENSION_PSKKEM_KEMODES_LENGTH_LEN + TCPIP_TLS_EXTENSION_PSKKEM_KEMODE_LEN;
  IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)), 0,
    extensionDataLength);
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSIONDATALEN_LEN);

  /* #30 Add the length field for one key exchange mode. */
  IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)), 0,
    TCPIP_TLS_EXTENSION_PSKKEM_KEMODE_LEN);
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_PSKKEM_KEMODES_LENGTH_LEN);

  /* #40 Add the one supported key exchange mode: psk_dhe_ke(1) */
  IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)), 0,
    TCPIP_TLS_EXTENSION_PSKKEM_KEMODE_PSK_DHE_KE);
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_PSKKEM_KEMODE_LEN);
} /* TcpIp_Tls13ClientMsg_ClientHelloExtAddPskKeyExchangeModes() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ClientHelloExtPrepareKeyShareFields
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtPrepareKeyShareFields(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxIterType extTypeTlsBufferTxIdx = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_TlsBufferTxIterType extLenIdx = extTypeTlsBufferTxIdx + TCPIP_TLS_EXTENSION_TYPE_LEN;
  TcpIp_TlsBufferTxIterType clientSharesTlsBufferTxIdx = extLenIdx + TCPIP_TLS_EXTENSION_LENGTH_LEN;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Add the extension type. */
  IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extTypeTlsBufferTxIdx), 0u, TCPIP_TLS_EXTENSION_KEY_SHARE);
  /* #20 Set clientSharesLen to 0. It gets constantly updated when new KeyShareEntries are added. */
  IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(clientSharesTlsBufferTxIdx), 0u, 0u);
  /* #30 Update the write index. */
  TcpIp_SetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
    (TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType)(clientSharesTlsBufferTxIdx + TCPIP_TLS_EXTENSION_KEY_SHARE_LENGTH_LEN));

} /* TcpIp_Tls13ClientMsg_ClientHelloExtPrepareKeyShareFields() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ClientHelloExtUpdateKeyShareLengthFields
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtUpdateKeyShareLengthFields(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsClientBufferMgmtIdxOfTlsConnectionType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferTxIterType extTypeIdx
    = TcpIp_GetTlsBufferTxClientKeyShareExtensionIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  TcpIp_TlsBufferTxIterType extLenTlsBufferTxIdx = extTypeIdx + TCPIP_TLS_EXTENSION_TYPE_LEN;

  TcpIp_TlsBufferTxIterType clientSharesTlsBufferTxIdx = extLenTlsBufferTxIdx + TCPIP_TLS_EXTENSION_LENGTH_LEN;

  /* ----- Implementation ----------------------------------------------- */
  uint16 extLen = (uint16)(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx) - clientSharesTlsBufferTxIdx);
  /* #10 Update the extension length */
  IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extLenTlsBufferTxIdx), 0, extLen);
  /* #20 Update clientSharesLen */
  IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(clientSharesTlsBufferTxIdx), 0, extLen - TCPIP_TLS_EXTENSION_KEY_SHARE_LENGTH_LEN);

} /* TcpIp_Tls13ClientMsg_ClientHelloExtUpdateKeyShareLengthFields() */

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ClientHelloExtAddKeyShare
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtAddKeyShare(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* Extension index information */
  /* Key Share Extension Format
   *       [ext Type][ext Len][Client Shares Len][KeyShareEntry 1]        [KeyShareEntry n]
   * Byte: 0       1 2      3 4                5 6            6+k1        (x-kn)          x
   * The KeyShareEntries can have different lengths.
   * KeyShareEntry Format
   *       [NamedGroup][Key Exchange Len][Key Exchange]
   * Byte: 0         1 2               3 4            y
   */

  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsBufferMgmtDynIterType    tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsClientBufferMgmtIdxOfTlsConnectionType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsEllipticCurveIdType supportedGroups[TCPIP_CURVE_ID_AMOUNT];
  TcpIp_TlsEllipticCurveIdType nextGroupIdx
    = TcpIp_GetIdxForNextGroupToCalculatePubKeyOfTlsClientConnection(tlsClientConnectionIdx);
  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* TcpIp_Tls12ClientMsg_ClientHelloExtGetSupportedGroups() is called to get the supported groups.
   * This function is also called in the supported groups extension,
   * to ensure the order of the groups in both extension are the same (see RFC8446 chapter 4.2.8.).
   * Here it can't return an empty array since we only get to this point when the connection supports TLS 1.3
   * where a PSK handshake can't be configured. */
  TcpIp_TlsEllipticCurveIdType supportedGroupsCount
    = TcpIp_TlsClientMsg_ClientHelloExtGetSupportedGroups(TlsConIdx, &supportedGroups[0], TCPIP_CURVE_ID_AMOUNT);

  if (TcpIp_GetTlsBufferTxClientKeyShareExtensionIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx)
        == TCPIP_NO_TLSBUFFERTXCLIENTKEYSHAREEXTENSIONIDXOFTLSCLIENTBUFFERMGMT)
  {
    TcpIp_SetTlsBufferTxClientKeyShareExtensionIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
      TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));
  }

  /* The first time this function is called, the key share fields need to be prepared.
   * Afterwards either the async context is triggered and the idx for the next group is incremented there
   * or the next state is triggered and this function is not called anymore. */
  if (nextGroupIdx == 0u)
  {
    /* #10 Prepare the fields of the KeyShare extension only once. */
    TcpIp_Tls13ClientMsg_ClientHelloExtPrepareKeyShareFields(TlsConIdx);
  }

  if (supportedGroupsCount < TCPIP_CURVE_ID_AMOUNT)
  {
    retVal = E_OK;
    if (nextGroupIdx < supportedGroupsCount)
    {
      /* #20 Check if there are any groups left for which no public key is computed yet */
      /* A KeyShareEntry is added. It consists of the NamedGroup (which is added here)
       * and the Key Exchange (which is added in the async context). */
      IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)),
        0, supportedGroups[nextGroupIdx]);
      TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_CURVE_ID_LEN);

      /* #30 Trigger the async context calculation of the public key with the following function call. */
      TcpIp_TlsClientMsg_AddDiffieHellmanParams(TlsConIdx,
        TCPIP_TLS_HSTYPE_CLIENTHELLO, supportedGroups[nextGroupIdx]);
      TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_HELLO_KEY_SHARE_WAIT_FOR_ASYNC);
    }
    else
    {
      /* When a KeyShareEntry for each supported group was added, trigger the next state. */
      TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_HELLO_ADD_GENERAL_EXTENSIONS);
    }
  }

  return retVal;
} /* TcpIp_Tls13ClientMsg_ClientHelloExtAddKeyShare() */
#   endif

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerHelloChecksBeforeScanForSuppVersExt
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
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerHelloChecksBeforeScanForSuppVersExt(
  TcpIp_TlsConnectionIterType                              TlsConIdx,
  TcpIp_TlsBufferRxServerHelloIdxOfTlsClientBufferMgmtType ServerHelloStartIdx,
  TcpIp_TlsBufferRxIterType                                ServerHelloEndIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  uint8 sessionIdLen = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* The check that the minimum server hello message length fits into the buffer is already done in a previous step. */

  /* #10 Skip the standard parameters(random + protocol version) */
  TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_RANDOM_LEN + TCPIP_TLS_VERSLEN);
  sessionIdLen = TcpIp_GetTlsBufferRx(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));
  if (sessionIdLen > TCPIP_TLS_SESSIONIDMAX_LEN)
  {
    /* #20 Invalid length of sessionId - so stop the handshake */
    /* retVal already is E_NOT_OK, nothing to do here. */
  }
  else
  {
    if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx),
      (TCPIP_TLS_SESSIONIDLEN_LEN + (uint64)sessionIdLen + TCPIP_TLS_CIPHERSUITEID_LEN
        + TCPIP_TLS_COMPMETHLEN_LEN), ServerHelloEndIdx) == TRUE)
    {

      /* #30 Skip the standard parameters(session id, cipher suite, compression method) */
      TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
        ((TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType)sessionIdLen + TCPIP_TLS_SESSIONIDLEN_LEN));
      TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_CIPHERSUITEID_LEN);
      TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_COMPMETHLEN_LEN);

      /* #40 Check if there are any extensions */
      /* If we received just the extensions length field with length zero,
       * we will get into the else-path but nevertheless E_OK is returned and the active version is set to 1.2. */
      if (TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx) == ServerHelloEndIdx)
      {
        /* #50 No extensions in ServerHello present. Set active TLS version to 1.2. */
        /* If E_NOT_OK is returned,
         * an alert was already set inside TcpIp_Tls13ClientMsg_SetActiveVersionTo12With13Enabled(). */
        retVal = TcpIp_Tls13ClientMsg_SetActiveVersionTo12With13Enabled(TlsConIdx);
      }
      else
      {
        /* #60 Scan the extensions for supported_versions extension, parse it if available and set active version. */
        retVal = TcpIp_Tls13ClientMsg_ServerHelloScanForSupportedVersionsExt(TlsConIdx, ServerHelloEndIdx);
      }
      /* #70 Go back to the start of the hello message (before the protocol version) */
      TcpIp_SetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, (ServerHelloStartIdx + TCPIP_TLS_HSHDRLEN));
    }
    else
    {
      /* Error, the message is too short to contain some standard elements. */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
    }
  }

  /* Continue evaluating the parameters with the knowledge of the real used protocol version.*/
  return retVal;
} /* TcpIp_Tls13ClientMsg_ServerHelloChecksBeforeScanForSuppVersExt() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerHelloScanForSupportedVersionsExt
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerHelloScanForSupportedVersionsExt(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferRxIterType  ServerHelloEndIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint16 extensionsLen = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the extensions if it contains the supported_versions extension */
  if (TcpIp_TlsCoreUtil_GetExtensionsLengthAndCheckForValidity(TlsConIdx, ServerHelloEndIdx, &extensionsLen) == E_OK)
  {
    TcpIp_TlsExtensionType listOfReceivedExtensions[TCPIP_TLS_MAX_EXTENSION_LIST_LENGTH] = { 0 };
    uint8 overallNumberOfReceivedExtensions = 0u;
    /* #20 Only check the length of each extension to fit into the message, but skip further extension analysis. */
    if (TcpIp_TlsMsg_ExtractReceivedExtensions(TlsConIdx, extensionsLen, ServerHelloEndIdx,
          &listOfReceivedExtensions[0], &overallNumberOfReceivedExtensions) == E_OK)
    {
      /* #30 Iterate over all received extensions in server hello. If supported_versions is there, parse it and set active version. */
      retVal = TcpIp_Tls13ClientMsg_ServerHelloFindAndParseSupportedVersionsExtension(TlsConIdx,
        &listOfReceivedExtensions[0], overallNumberOfReceivedExtensions);
    }
    else
    {
      /* #40 Invalid formatted received extension - Trigger alert */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
    }
  }

  return retVal;
} /* TcpIp_Tls13ClientMsg_ServerHelloScanForSupportedVersionsExt() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerHelloFindAndParseSupportedVersionsExtension
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerHelloFindAndParseSupportedVersionsExtension(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(TcpIp_TlsExtensionType) ReceivedExtensionListPtr,
  uint8 OverallNumberOfReceivedExtensions
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  boolean foundSupportedVersionsExtension = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  uint8 rxExtensionIter;
  /* #10 Iterate over all received extensions in server hello */
  for (rxExtensionIter = 0u; rxExtensionIter < OverallNumberOfReceivedExtensions; rxExtensionIter++)
  {
    uint16 currentReceivedExtensionType = ReceivedExtensionListPtr[rxExtensionIter].Type;
    /* #20 Skip every extension except the supported_versions - forward to parser */
    if (currentReceivedExtensionType == TCPIP_TLS_EXTENSION_SUPPORTED_VERSIONS)
    {
      foundSupportedVersionsExtension = TRUE;
      if (TcpIp_Tls13ClientMsg_ServerHelloParseExtensionSupportedVersions(TlsConIdx,
        ReceivedExtensionListPtr[rxExtensionIter]) == E_OK)
      {
        /* TcpIp_Tls13ClientMsg_ServerHelloParseExtensionSupportedVersions() sets the active version to TLS 1.3
         * if the extension was well formatted. */
        retVal = E_OK;
      }
      else
      {
        /* retVal is already E_NOT_OK,
         * alert is set inside TcpIp_Tls13ClientMsg_ServerHelloParseExtensionSupportedVersions().
         * Therefore nothing to do here. */
      }
      break;
    }
  }

  if (foundSupportedVersionsExtension == FALSE)
  {
    /* Server did not respond with a supported_versions extension in server hello.
     * Since this extension is mandatory if negotiating TLS version 1.3 (RFC8446 Section 4.2.1.), we must assume
     * that server is only capable of TLS version 1.2. */
    retVal = TcpIp_Tls13ClientMsg_SetActiveVersionTo12With13Enabled(TlsConIdx);
  }
  return retVal;
} /* TcpIp_Tls13ClientMsg_ServerHelloFindAndParseSupportedVersionsExtension() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerHelloParseExtensionSupportedVersions
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerHelloParseExtensionSupportedVersions(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType SupportedVersions)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* RFC8446 - 4.2.1  Supported Versions
   *   The "supported_versions" extension is used by the server to indicate which
   *   version it is using.
   *   A server which negotiates TLS 1.3 MUST respond by sending
   *   a "supported_versions" extension containing the selected version
   *   value (0x0304).*/

   /* Server Supported Versions Extension Format
                                 +--->  Selected Version
                                /
    *       [ext Type][ext Len][Supp Version]
    * Byte: 0       1 2      3  4          5
    */

    /* #10 Process extension only if the length match */
  if (SupportedVersions.Length == (TCPIP_TLS_MAJORVERS_LEN + TCPIP_TLS_MINORVERS_LEN)) /* We MUST receive exactly one supported version */
  {
    uint8 majorVersion = IpBase_GetUint8(TcpIp_GetAddrTlsBufferRx(SupportedVersions.StartIdx), 0);
    uint8 minorVersion = IpBase_GetUint8(TcpIp_GetAddrTlsBufferRx(SupportedVersions.StartIdx + TCPIP_TLS_MAJORVERS_LEN), 0);

    /* If we want Tls Version 1.2 this extensions must not be sent by the server.
     * If this extension is present the Tls Version must be Version 1.3 */
    if ((majorVersion == TCPIP_TLS_PROTOCOL_MAJOR_VERSION_3) && (minorVersion == TCPIP_TLS_PROTOCOL_MINOR_VERSION_4))
    {
      /* This is the only place where the active version is set to TLS 1.3. */
      TcpIp_SetActiveVersionOfTlsConnectionDyn(TlsConIdx, TCPIP_TLSVERSION_13);

      /* Check if ServerHello was aligned with a RL boundary.
       * This flag was set in TcpIp_TlsCoreRl_ScanForHsTypesAndTriggerHsMsgProcess() */
      if (TcpIp_IsMsgPrecedingKeyChangeNotAlignWithBoundaryOfTlsConnectionDyn(TlsConIdx) == TRUE)
      {
        /* According to RFC 8446 Section 5.1, implementations MUST verify that all messages immediately
         * preceding a key change align with a record boundary; if not, then they MUST terminate the
         * connection with an unexpected_message alert. */
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
      }
      else
      {
        /* After the ServerHello message the peer sends decrypted messages,
         * these contain one byte of inner plain text ContentType which can be received additionally
         * to the maximum allowed plain text length (2^14 = TCPIP_TLS12_RECORD_LAYER_PLAINTEXT_LEN_MAX).
         * See RFC8446 chapter 5.4: " the full encoded TLSInnerPlaintext MUST NOT exceed 2^14 + 1 octets."
         * Therefore we have to increase the maximum allowed Rx size
         * but only if the configured buffer size allows this. */
        if (   TcpIp_GetActiveMaxRxRlSizeOfTlsConnectionDyn(TlsConIdx)
            <= ((TcpIp_TlsBufferRxIterType)TcpIp_GetTlsBufferRxAdHsLengthOfTlsBufferMgmt(tlsBufferMgmtIdx)
                  - TCPIP_TLS_ADDITIONAL_RX_BUFFER_OVERHEAD))
        {
          TcpIp_AddActiveMaxRxRlSizeOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS13_INNERPLAINTEXTCONTENTTYPELEN);
        }
        retVal = E_OK;
      }
    }
    else
    {
      /* #20 Tls Version in supported_version extensions from server is not version 1.3 - report TLS-Alert */
      /* According to RFC 8446 Section 4.2.1. the client must abort the handshake and send an illegal parameter
       * alert. Currently, we do not support any newer TLS version than 1.3 */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_ILLEGAL_PARAM);
    }
  }
  else
  {
    /* #30 Received length mismatch - report TLS-Alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
  }
  return retVal;
} /* TcpIp_Tls13ClientMsg_ServerHelloParseExtensionSupportedVersions */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_SetActiveVersionTo12With13Enabled
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_SetActiveVersionTo12With13Enabled(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the send ClientHello supported the choice of TLS 1.2. */
  if (TcpIp_TlsClient_WorkingSetIncludesTlsVersion(TlsConIdx, TCPIP_TLSVERSION_12))
  {
    /* #20 If so, set the active version to 1.2. */
    TcpIp_SetActiveVersionOfTlsConnectionDyn(TlsConIdx, TCPIP_TLSVERSION_12);
    /* In TcpIp_TlsCoreRl_HandleFrameAndTriggerContentSpecificProcess() if both TLS 1.2 and 1.3 is enabled and no
     * active version is set yet, TcpIp_TlsCoreRl_ScanForHsTypesAndTriggerHsMsgProcess() is called
     * where the decryption might be blocked for the following messages since the ServerHello precedes a key change
     * in TLS 1.3. So when the active version shall be set to 1.2 when parsing the ServerHello
     * the decryption must no longer be blocked and the flag can be reset. */
    TcpIp_SetBlockDecryptOperationsUntilKeysAreCalculatedOfTlsConnectionDyn(TlsConIdx, FALSE);
    retVal = E_OK;
  }
  else
  {
    /* #30 If not, send a missing_extension alert. */
    /* The active TLS version is only set to 1.2 if the peer did not send a supported_versions extension in its
     * ServerHello message. This is not a valid case if the ClientHello only contained 1.3 ciphers. */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_MISSING_EXT);
  }
  return retVal;
} /* TcpIp_Tls13ClientMsg_SetActiveVersionTo12With13Enabled */


#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerHelloKeyShareExtensionStorePositionOfKeyAndKeyLength
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerHelloKeyShareExtensionStorePositionOfKeyAndKeyLength(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType KeyShare,
  TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType ActiveTlsHandshakeIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferRxIterType keyExchangeLenBufIdx = KeyShare.StartIdx + TCPIP_TLS_EXTENSION_KEY_SHARE_GROUP_LEN;
  TcpIp_TlsBufferRxIterType keyExchangeTlsBufferRxIdx =
    KeyShare.StartIdx + TCPIP_TLS_EXTENSION_KEY_SHARE_GROUP_LEN + TCPIP_TLS_EXTENSION_KEY_SHARE_KEY_LENGTH_LEN;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if we expect a compression flag for this received public key */
  if (TcpIp_TlsCoreUtil_CheckPublicKeyCompressionFlagOfEllipticCurve(TcpIp_GetEllipticCurveIdOfTlsHandshake(ActiveTlsHandshakeIdx)) == TRUE)
  {
    /* #20 if so, read and compare the compression flag of public key with the expected compression flag */
    uint8 receivedCompressionFlag = IpBase_GetUint8(TcpIp_GetAddrTlsBufferRx(
      keyExchangeTlsBufferRxIdx), 0);

    if (receivedCompressionFlag != TCPIP_TLS_PUBKEY_COMPRESSION_FLAG)
    {
      /* invalid compression flag received */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
      retVal = E_NOT_OK;
    }
  }

  /* #30 Set the index to the start of the public key (including compression flag if present) */
  /* Reusing the indirection of the ServerKeyExchangePublicKey (message does not exists in TLS 1.3) */
  TcpIp_SetTlsBufferRxServerKeyExchangePubKeyIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    (TcpIp_TlsBufferRxServerKeyExchangePubKeyIdxOfTlsClientBufferMgmtType)keyExchangeTlsBufferRxIdx);
  TcpIp_SetTlsBufferRxServerKeyExchangePubKeyLenIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
    (TcpIp_TlsBufferRxServerKeyExchangePubKeyLenIdxOfTlsClientBufferMgmtType)keyExchangeLenBufIdx);

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerHelloParseExtensionKeyShare
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
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerHelloParseExtensionKeyShare(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType KeyShare)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx = TCPIP_NO_TLSHANDSHAKEACTIVEIDXOFTLSCIPHERWORKERDYN;

  uint8 expectedPubKeyLen = 0u;
  TcpIp_TlsBufferRxIterType namedGroupTlsBufferRxIdx = KeyShare.StartIdx;
  TcpIp_TlsBufferRxIterType keyExchangeLenTlsBufferRxIdx = namedGroupTlsBufferRxIdx + TCPIP_TLS_EXTENSION_KEY_SHARE_GROUP_LEN;
  uint16 overallExtLength = KeyShare.Length;
  TcpIp_TlsBufferRxIterType extKeyShareEndIdx = namedGroupTlsBufferRxIdx + overallExtLength;

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */

  /* RFC8446 - 4.2.8  Key Share
   *   The "key_share" extension contains the endpoint's cryptographic parameters.
   *
   * struct {
   *     NamedGroup group;
   *     opaque key_exchange<1..2^16-1>;
   * } KeyShareEntry;
   *
   * struct {
   *     KeyShareEntry server_share;
   * } KeyShareServerHello;
   */

  /* Server Key Share Extension Format. This key share contains exactly one key share entry.
                                 +--->  Key Share Entry
                                /
   *       [ext Type][ext Len][namedGroupTlsBufferRxIdx][KeyExchangeLen][keyExchange]
   * Byte: 0       1 2      3 4         5 6             7 8          n
   */
  /* Range check before read out the received named group (2Bytes) and key share length */
  if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(namedGroupTlsBufferRxIdx,
        (TCPIP_TLS_EXTENSION_KEY_SHARE_GROUP_LEN + TCPIP_TLS_EXTENSION_KEY_SHARE_LENGTH_LEN), extKeyShareEndIdx))
  {
    TcpIp_TlsEllipticCurveIdType namedGroup = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(namedGroupTlsBufferRxIdx), 0u);

    /* #10 Get the length of the received key_share and check against the overall length */
    uint16 receivedkeyShareLen = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(keyExchangeLenTlsBufferRxIdx), 0u);

    /* #20 Process extension only if the length matches */
    if (   (receivedkeyShareLen >= TCPIP_TLS_EXTENSION_KEY_SHARE_KEY_MIN_LEN)
      &&   (overallExtLength == (receivedkeyShareLen
              + TCPIP_TLS_EXTENSION_KEY_SHARE_GROUP_LEN + TCPIP_TLS_EXTENSION_KEY_SHARE_LENGTH_LEN)))
    {
      /* #30 Set the active handshake, now that we received the server key that tells us which elliptic curve shall be used.*/
      if (TcpIp_TlsClientMsg_SetActiveCipherWorkerAccordingToReceivedServerParams(TlsConIdx, namedGroup) == E_OK)
      {
        activeTlsHandshakeIdx = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(
          TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

        /* Check if the activeTlsHandshakeIdx is valid */
        if (activeTlsHandshakeIdx != TCPIP_NO_TLSHANDSHAKEACTIVEIDXOFTLSCIPHERWORKERDYN)
        {
          expectedPubKeyLen = (TcpIp_TlsMsg_GetLenOfCurveSpecificPubKey(
            TcpIp_GetEllipticCurveIdOfTlsHandshake(activeTlsHandshakeIdx)));

          if (TcpIp_TlsCoreUtil_CheckPublicKeyCompressionFlagOfEllipticCurve(
            TcpIp_GetEllipticCurveIdOfTlsHandshake(activeTlsHandshakeIdx)) == TRUE)
          {
            /* expected length of public key contains one further byte for compression flag */
            expectedPubKeyLen += TCPIP_TLS_COMPMETHLEN_LEN;
          }

          if (receivedkeyShareLen == expectedPubKeyLen)
          {
            /* #40 store positions of length and key */
            retVal = TcpIp_Tls13ClientMsg_ServerHelloKeyShareExtensionStorePositionOfKeyAndKeyLength(
              TlsConIdx,
              KeyShare,
              activeTlsHandshakeIdx);
          }
          else
          {
            /* #50 Key exchange length does not fit expected key length - report error and trigger TLS alert */
            TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
          }
        }
        else
        {
          /* #60 Received key share length mismatch - report error and trigger TLS alert */
          TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
        }
      }
      else
      {
        /* #70 Selected group is not supported by client and was not sent in the supported_groups extension - report TLS-Alert */
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_ILLEGAL_PARAM);
      }
    }
    else
    {
      /* #80 Overall received length mismatch - report error and trigger TLS alert */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
    }
  }
  else
  {
    /* Range check failed - report error and trigger TLS alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
  }
  return retVal;
}
#   endif

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerHelloParseExtensionPreSharedKey
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
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerHelloParseExtensionPreSharedKey(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType      PreSharedKey)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* Extension index information */
  /* Server Pre Shared Keys Extension Format
   *       [ext Type][ext Len][Selected Psk identity]
   * Byte: 0       1 2      3 4                    5
   */
  /* #10 Check that the received length is valid. */
  if (PreSharedKey.Length == TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_SELECTED_IDENTITY_LEN)
  {
    uint16 selectedIdentity = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(PreSharedKey.StartIdx), 0u);

    /* For a resumed connection in the case of TLS 1.3 session resumption
     * the RFC8446 states in chapter 4.2.11:
     * "Clients MUST verify that the server's selected_identity is within the range supplied by the client [...]
     * If these values are not consistent,
     * the client MUST abort the handshake with an "illegal_parameter" alert." */
    /* Currently only one PSK is send in the client's pre_shared_key extension,
     * see TcpIp_Tls13ClientMsg_ClientHelloExtAddPreSharedKey(). Therefore we must receive an index of zero. */
    /* #20 Check the received selected identity. */
    if (selectedIdentity == 0u)
    {
      TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx
        = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);
      TcpIp_TlsHashAlgorithmType cipherSuiteHashAlgo = TCPIP_HASH_ALGORITHM_NO_HASH;
      TcpIp_TlsCipherDataType receivedCipher
        = TcpIp_GetReceivedCipherSuiteIdOfTlsClientConnection(tlsClientConnectionIdx);
      if (TcpIp_Tls13Core_GetCipherSuiteHashAlgorithm(receivedCipher, &cipherSuiteHashAlgo) == E_OK)
      {
        TcpIp_TlsHashAlgorithmType pskIdentityHashAlgo
          = TcpIp_GetHashAlgorithmOfTls13PskIdentity(TcpIp_GetTls13PskIdentityActiveIdxOfTlsConnectionDyn(TlsConIdx));
        /* For a resumed connection in the case of TLS 1.3 session resumption
         * the RFC8446 states in chapter 4.2.11:
         * "Clients MUST verify [...] that the server selected a cipher suite
         * indicating a Hash associated with the PSK [...]
         * If these values are not consistent,
         * the client MUST abort the handshake with an "illegal_parameter" alert." */
        /* #30 Check that the hash algorithm of the received cipher matches the hash algorithm of the PSK identity. */
        if (pskIdentityHashAlgo == cipherSuiteHashAlgo)
        {
          retVal = E_OK;
        }
        else
        {
          /* #40 Hash algorithm of cipher is different to algorithm of PSK identity - report error and trigger TLS alert */
          TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_ILLEGAL_PARAM);
        }
      }
      else
      {
        /* Not able to find the hash algorithm of the received ciphersuite,
         * even though it was already checked that this cipher was send in the ClientHello. */
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
      }
    }
    else
    {
      /* #50 Selected identity index does not exist in sent pre_shared_key extension - report error and trigger TLS alert */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_ILLEGAL_PARAM);
    }
  }
  else
  {
    /* #60 Key exchange length does not fit expected key length - report error and trigger TLS alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerHelloMsgCheckRandomForHelloRetryRequest
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerHelloMsgCheckRandomForHelloRetryRequest(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean indicateHelloRetryRequest = FALSE;

  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* According to RFC 8446 Section 4.1.3, in TLS 1.3 the HelloRetryRequest uses the same structure like ServerHello
   * messages, but with the Random set to the special value:
   * CF 21 AD 74 E5 9A 61 11 BE 1D 8C 02 1E 65 B8 91 C2 A2 11 16 7A BB 8C 5E 07 9E 09 E2 C8 A8 33 9C */
  CONST(uint8, TCPIP_CONST) TcpIp_Tls13_ServerRandomHelloRetryRequestValue[TCPIP_TLS_SERVERRANDOM_HELLORETRYREQUEST_VALUE_LEN] = {
    0xCF, 0x21, 0xAD, 0x74, 0xE5, 0x9A, 0x61, 0x11,
    0xBE, 0x1D, 0x8C, 0x02, 0x1E, 0x65, 0xB8, 0x91,
    0xC2, 0xA2, 0x11, 0x16, 0x7A, 0xBB, 0x8C, 0x5E,
    0x07, 0x9E, 0x09, 0xE2, 0xC8, 0xA8, 0x33, 0x9C
  };

  /* ----- Implementation ----------------------------------------------- */
  /* According to RFC 8446 Section 4.1.3, in TLS 1.3 the HelloRetryRequest uses the same structure like ServerHello
   * messages, but with the Random set to the special value:
   * CF 21 AD 74 E5 9A 61 11 BE 1D 8C 02 1E 65 B8 91 C2 A2 11 16 7A BB 8C 5E 07 9E 09 E2 C8 A8 33 9C */
  if (VStdLib_MemCmp(
    TcpIp_GetAddrTlsBufferRx(
      TcpIp_GetTlsBufferRxServerRandomIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx)),
    &TcpIp_Tls13_ServerRandomHelloRetryRequestValue[0],
    TCPIP_TLS_SERVERRANDOM_HELLORETRYREQUEST_VALUE_LEN) == VSTDLIB_MEM_CMP_RES_EQ)
  {
    /* #10 Server Random indicates that the message is a HelloRetryRequest - we do not support this message */
    indicateHelloRetryRequest = TRUE;
  }

  return indicateHelloRetryRequest;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerHelloMsgCheckRandomForDowngrade
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerHelloMsgCheckRandomForDowngrade(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxIterType serverRandomDowngradeValueIdx = TcpIp_GetTlsBufferRxServerRandomIdxOfTlsClientBufferMgmt(
    tlsClientBufferMgmtIdx) + TCPIP_TLS_SERVERRANDOM_DOWNGRADE_VALUE_START;

  /* According to RFC 8446 Section 4.1.3, TLS 1.3 clients should check if server random's 8 last bytes are neither of
   * 44 4F 57 4E 47 52 44 01 (Tls 1.3 server indicates Tls 1.2) or
   * 44 4F 57 4E 47 52 44 00 (Tls 1.3 server indicates Tls 1.1) */
  CONST(uint8, TCPIP_CONST) TcpIp_Tls13_ServerRandomDowngradeValueTls12[TCPIP_TLS_SERVERRANDOM_DOWNGRADE_VALUE_LEN]
    = { 0x44, 0x4F, 0x57, 0x4E, 0x47, 0x52, 0x44, 0x01 };
  CONST(uint8, TCPIP_CONST) TcpIp_Tls13_ServerRandomDowngradeValueTls11[TCPIP_TLS_SERVERRANDOM_DOWNGRADE_VALUE_LEN]
    = { 0x44, 0x4F, 0x57, 0x4E, 0x47, 0x52, 0x44, 0x00 };

  /* ----- Implementation ----------------------------------------------- */
  /* According to RFC 8446 Section 4.1.3, TLS 1.3 clients should check if server random's 8 last bytes are neither of
   * 44 4F 57 4E 47 52 44 01 (Tls 1.3 server indicates Tls 1.2) or
   * 44 4F 57 4E 47 52 44 00 (Tls 1.3 server indicates Tls 1.1) */

  if (
    /* #10 Server Random's downgrade value indicates downgrade to TLS version 1.2 - abort handshake */
         (VStdLib_MemCmp(
           TcpIp_GetAddrTlsBufferRx(serverRandomDowngradeValueIdx), &TcpIp_Tls13_ServerRandomDowngradeValueTls12[0],    /* TCPIP_CSL_NAME_LENGTH */
             TCPIP_TLS_SERVERRANDOM_DOWNGRADE_VALUE_LEN) == VSTDLIB_MEM_CMP_RES_EQ)
    /* #20 Server Random's downgrade value indicates downgrade to TLS version 1.1 - abort handshake */
      || (VStdLib_MemCmp(                                                                                               /* PRQA S 3415 3 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
           TcpIp_GetAddrTlsBufferRx(serverRandomDowngradeValueIdx), &TcpIp_Tls13_ServerRandomDowngradeValueTls11[0],    /* TCPIP_CSL_NAME_LENGTH */
             TCPIP_TLS_SERVERRANDOM_DOWNGRADE_VALUE_LEN) == VSTDLIB_MEM_CMP_RES_EQ))
  {
    /* RFC8446 states in chapter 4.1.3 that if a match to an downgrade value is found,
     * "the client MUST abort the handshake with an "illegal_parameter" alert". */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_ILLEGAL_PARAM);
    retVal = E_NOT_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_AddHelloMessagesToHash
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AddHelloMessagesToHash(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

  TcpIp_CsmJobIdType csmHashJobId
    = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfHashMessagesJobIdIdxOfTlsHandshake(activeTlsHandshakeIdx));

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize the Hash function and add the ClientHello message to the Hash function. */
  {
    TCPIP_P2C(uint8) clientHelloPtr = TcpIp_GetAddrTlsBufferTx(
      TcpIp_GetTlsBufferTxClientHelloIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx));

    uint32 clientHelloLen = TcpIp_GetClientHelloLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

    retVal = TCPIP_CSM_Hash(csmHashJobId, CRYPTO_OPERATIONMODE_START | CRYPTO_OPERATIONMODE_UPDATE, clientHelloPtr,
      clientHelloLen, NULL_PTR, NULL_PTR);
  }

  /* #20 Add the ServerHello message to the Hash function. */
  if (retVal == E_OK)
  {
    TCPIP_P2C(uint8) serverHelloPtr = TcpIp_GetAddrTlsBufferRx(
      TcpIp_GetTlsBufferRxServerHelloIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx));

    uint32 serverHelloLen
      = ((uint32)TcpIp_GetServerHelloLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx) + TCPIP_TLS_HSHDRLEN);

    retVal = TCPIP_CSM_Hash(csmHashJobId, CRYPTO_OPERATIONMODE_UPDATE, serverHelloPtr,
      serverHelloLen, NULL_PTR, NULL_PTR);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_AddTruncatedClientHelloMessageToHash
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AddTruncatedClientHelloMessageToHash(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8                       HashLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_Tls13PskIdentityActiveIdxOfTlsConnectionDynType activeTls13PskIdentityIdx
    = TcpIp_GetTls13PskIdentityActiveIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_CsmJobIdType csmHashJobId = TcpIp_GetPskHashCsmJobIdOfTls13PskIdentity(activeTls13PskIdentityIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize the Hash function and add the truncated ClientHello message to the Hash function. */
  {
    TCPIP_P2C(uint8) clientHelloPtr = TcpIp_GetAddrTlsBufferTx(
      TcpIp_GetTlsBufferTxClientHelloIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx));

    uint32 clientHelloLen = TcpIp_GetClientHelloLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);
#   if ( TCPIP_DEV_ERROR_DETECT == STD_ON )                                                                             /* COV_TCPIP_DEV_ERROR_DETECT */
    if (clientHelloLen < (TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_BINDER_LENGTH_LEN + (uint32) HashLength))
    {
      /* This can never happen if this function is called in the correct context. */
      TcpIp_CallDetReportError(TCPIP_API_ID_MEMCPY_OPERATION, TCPIP_E_INV_RUNTIME_CHECK);
    }
    else
#   endif
    {
      /* The truncated ClientHello includes all of the ClientHello
       * but not the binders list itself (RFC8446 chapter 4.2.11.2).
       * Since we only write one binder into the list we need to subtract its length + the length of both length fields.
       * The HashLength equals the length of the binder */
      clientHelloLen -= (TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_BINDERS_LENGTH_LEN
        + TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_BINDER_LENGTH_LEN + (uint32) HashLength);
    }

    Std_ReturnType csmRetVal = TCPIP_CSM_Hash(csmHashJobId, CRYPTO_OPERATIONMODE_START | CRYPTO_OPERATIONMODE_UPDATE,
      clientHelloPtr, clientHelloLen, NULL_PTR, NULL_PTR);

    /* #20 Check if the CSM hash operation succeeded. */
    /* If csmRetVal is E_NOT_OK, retVal will be set to E_NOT_OK as well. */
    retVal = TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, 0u, 0u,
      TCPIP_TLS_FCTID_CLIENT_CRYPTO_CALCHSHASH);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_AddEncryptedExtensionsMsgToHash
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AddEncryptedExtensionsMsgToHash(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

  TcpIp_CsmJobIdType csmHashJobId
    = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfHashMessagesJobIdIdxOfTlsHandshake(activeTlsHandshakeIdx));

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Add the EncryptedExtensions message to the Hash function. */
  {
    TCPIP_P2C(uint8) encryptedExtensionsPtr = TcpIp_GetAddrTlsBufferRx(
      TcpIp_GetTlsBufferRxEncryptedExtensionsIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx));

    uint32 encryptedExtensionsLen
      = ((uint32)TcpIp_GetEncryptedExtensionsLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx) + TCPIP_TLS_HSHDRLEN);

    retVal = TCPIP_CSM_Hash(csmHashJobId, CRYPTO_OPERATIONMODE_UPDATE, encryptedExtensionsPtr,
      encryptedExtensionsLen, NULL_PTR, NULL_PTR);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_AddServerCertificateRequestMsgToHash
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AddServerCertificateRequestMsgToHash(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  const TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

  const TcpIp_CsmJobIdType csmHashJobId
    = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfHashMessagesJobIdIdxOfTlsHandshake(activeTlsHandshakeIdx));

  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Add the Server CertificateRequest message to the Hash function if message was received. */
  if (TcpIp_GetTlsBufferRxServerCertificateRequestIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx)
        == TCPIP_NO_TLSBUFFERRXSERVERCERTIFICATESIDXOFTLSCLIENTBUFFERMGMT)
  {
    /* The message was not received => no update of Hash. */
    retVal = E_OK;
  }
  else
  {
    TCPIP_P2C(uint8) msgPtr = TcpIp_GetAddrTlsBufferRx(
      TcpIp_GetTlsBufferRxServerCertificateRequestIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx));

    const uint32 msgLen = ((uint32)TcpIp_GetServerCertificateRequestLenOfTlsClientBufferMgmt(
                                      tlsClientBufferMgmtIdx) + TCPIP_TLS_HSHDRLEN);

    retVal = TCPIP_CSM_Hash(csmHashJobId, CRYPTO_OPERATIONMODE_UPDATE,
                msgPtr, msgLen, NULL_PTR, NULL_PTR);
  }

  return retVal;
} /* TcpIp_Tls13Client_AddServerCertificateRequestMsgToHash() */

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_AddServerCertificateMsgToHash
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AddServerCertificateMsgToHash(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

  TcpIp_CsmJobIdType csmHashJobId
    = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfHashMessagesJobIdIdxOfTlsHandshake(activeTlsHandshakeIdx));

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Add the Server Certificate message to the Hash function. */
  if (TcpIp_GetTlsBufferRxServerCertificatesIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx) ==
    TCPIP_NO_TLSBUFFERRXSERVERCERTIFICATESIDXOFTLSCLIENTBUFFERMGMT)
  {
    /* The message was not received => no update of Hash. */
    retVal = E_OK;
  }
  else
  {
    TCPIP_P2C(uint8) certMsgPtr = TcpIp_GetAddrTlsBufferRx(
      TcpIp_GetTlsBufferRxServerCertificatesIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx));

    uint32 certMsgLen
      = ((uint32)TcpIp_GetServerCertificatesLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx) + TCPIP_TLS_HSHDRLEN);

    retVal = TCPIP_CSM_Hash(csmHashJobId, CRYPTO_OPERATIONMODE_UPDATE, certMsgPtr,
      certMsgLen, NULL_PTR, NULL_PTR);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_AddServerCertificateVerifyMsgToHash
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AddServerCertificateVerifyMsgToHash(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

  TcpIp_CsmJobIdType csmHashJobId
    = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfHashMessagesJobIdIdxOfTlsHandshake(activeTlsHandshakeIdx));

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Add the Server CertificateVerify message to the Hash function. */
  if (TcpIp_GetTlsBufferRxServerCertificateVerifyIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx) ==
    TCPIP_NO_TLSBUFFERRXSERVERCERTIFICATEVERIFYIDXOFTLSCLIENTBUFFERMGMT)
  {
    /* The message was not received => no update of Hash. */
    retVal = E_OK;
  }
  else
  {
    TCPIP_P2C(uint8) msgPtr = TcpIp_GetAddrTlsBufferRx(
      TcpIp_GetTlsBufferRxServerCertificateVerifyIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx));

    uint32 msgLen
      = ((uint32)TcpIp_GetServerCertificateVerifyLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx) + TCPIP_TLS_HSHDRLEN);

    retVal = TCPIP_CSM_Hash(csmHashJobId, CRYPTO_OPERATIONMODE_UPDATE, msgPtr,
      msgLen, NULL_PTR, NULL_PTR);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_AddServerFinishedMsgToHash
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AddServerFinishedMsgToHash(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

  TcpIp_CsmJobIdType csmHashJobId
    = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfHashMessagesJobIdIdxOfTlsHandshake(activeTlsHandshakeIdx));

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Add the ServerFinished message to the Hash function. */
  {
    TCPIP_P2C(uint8) serverFinishedPtr = TcpIp_GetAddrTlsBufferRx(
      TcpIp_GetTlsBufferRxServerFinishedIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx));

    uint32 serverFinishedLen
      = ((uint32)TcpIp_GetServerFinishedLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx) + TCPIP_TLS_HSHDRLEN);

    retVal = TCPIP_CSM_Hash(csmHashJobId, CRYPTO_OPERATIONMODE_UPDATE, serverFinishedPtr,
      serverFinishedLen, NULL_PTR, NULL_PTR);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_AddClientCertificateToHash
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AddClientCertificateToHash(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Add the client Certificate message to the Hash function if message was sent. */
  if (TcpIp_GetTlsBufferTxClientCertificateIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx)
      == TCPIP_NO_TLSBUFFERTXCLIENTCERTIFICATEIDXOFTLSCLIENTBUFFERMGMT)
  {
    /* The optional message was not send => no update of Hash. */
    retVal = E_OK;
  }
  else
  {
    /* Add the ClientCertificate message to the Hash function. */
    const TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx
      = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(
           TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

    const TcpIp_CsmJobIdType csmHashJobId
      = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfHashMessagesJobIdIdxOfTlsHandshake(activeTlsHandshakeIdx));

    TCPIP_P2C(uint8) clientCertificatePtr = TcpIp_GetAddrTlsBufferTx(
      TcpIp_GetTlsBufferTxClientCertificateIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx));

    const uint32 clientCertificateLen = TcpIp_GetClientCertificateLenOfTlsClientBufferMgmt(
                                            tlsClientBufferMgmtIdx);

    retVal = TCPIP_CSM_Hash(csmHashJobId, CRYPTO_OPERATIONMODE_UPDATE,
                clientCertificatePtr, clientCertificateLen, NULL_PTR, NULL_PTR);
  }

  return retVal;
} /* TcpIp_Tls13Client_AddClientCertificateToHash() */

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_AddClientCertificateVerifyToHash
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AddClientCertificateVerifyToHash(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Add the client CertificateVerify message to the Hash function if message was sent. */
  if (TcpIp_GetTlsBufferTxClientCertificateVerifyIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx)
      == TCPIP_NO_TLSBUFFERTXCLIENTCERTIFICATEVERIFYIDXOFTLSCLIENTBUFFERMGMT)
  {
    /* The optional message was not send => no update of Hash. */
    retVal = E_OK;
  }
  else
  {
    /* Add the ClientCertificate message to the Hash function. */
    const TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx
      = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(
            TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

    const TcpIp_CsmJobIdType csmHashJobId
      = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfHashMessagesJobIdIdxOfTlsHandshake(activeTlsHandshakeIdx));

    TCPIP_P2C(uint8) clientCertificateVerifyPtr = TcpIp_GetAddrTlsBufferTx(
      TcpIp_GetTlsBufferTxClientCertificateVerifyIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx));

    const uint32 clientCertificateVerifyLen = TcpIp_GetClientCertificateVerifyLenOfTlsClientBufferMgmt(
                                                  tlsClientBufferMgmtIdx);

    retVal = TCPIP_CSM_Hash(csmHashJobId, CRYPTO_OPERATIONMODE_UPDATE,
                clientCertificateVerifyPtr, clientCertificateVerifyLen, NULL_PTR, NULL_PTR);
  }

  return retVal;
} /* TcpIp_Tls13Client_AddClientCertificateVerifyToHash() */

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_AddClientFinishedToHash
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_AddClientFinishedToHash(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Add the client finished message to the Hash function. */
  {
    const TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx
      = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(
        TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

    const TcpIp_CsmJobIdType csmHashJobId
      = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfHashMessagesJobIdIdxOfTlsHandshake(activeTlsHandshakeIdx));

    TCPIP_P2C(uint8) clientFinishedPtr = TcpIp_GetAddrTlsBufferTx(
      TcpIp_GetTlsBufferTxClientFinishedIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx));

    const uint32 clientFinishedLen = TcpIp_GetClientFinishedLenOfTlsClientBufferMgmt(
      tlsClientBufferMgmtIdx);

    retVal = TCPIP_CSM_Hash(csmHashJobId, CRYPTO_OPERATIONMODE_UPDATE,
      clientFinishedPtr, clientFinishedLen, NULL_PTR, NULL_PTR);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_FinalizeHashOfHsMessages
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_FinalizeHashOfHsMessages(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_CsmJobIdType          HashCsmJobId,
  uint8                       HashLength,
  TcpIp_SegmentPtrType        TargetSegmentPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Finalize the Hash and save it. */
  return TcpIp_Tls13CoreCrypto_HashIntoSegment(TlsConIdx, HashCsmJobId, CRYPTO_OPERATIONMODE_FINISH, NULL_PTR, 0u,
    HashLength, TargetSegmentPtr);
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_CalculateHashOfHsMessagesWithActiveCipherHashLength
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_CalculateHashOfHsMessagesWithActiveCipherHashLength(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 hashLength = 0u;

  TCPIP_P2V(uint8) hsHashDestPtr = TcpIp_GetAddrTlsTemporaryHashBuffer(
    TcpIp_GetTlsTemporaryHashBufferStartIdxOfTlsConnection(TlsConIdx));

  uint32 hsHashDestSpace = TcpIp_GetTlsTemporaryHashBufferEndIdxOfTlsConnection(TlsConIdx)
    - (uint32)TcpIp_GetTlsTemporaryHashBufferStartIdxOfTlsConnection(TlsConIdx);

  TcpIp_SegmentType hsHashSegmentPtr = { 0 };

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Obtain the hash length of the active cipher. */
  Std_ReturnType retVal = TcpIp_Tls13Core_GetHashLengthOfActiveCipherSuite(TlsConIdx, &hashLength);
  if (retVal == E_OK)
  {
    TcpIp_SegmentInit(&hsHashSegmentPtr, hsHashDestPtr, hsHashDestSpace);
    /* #20 If successful, calculate a hash over handshake message with the obtained length. */
    retVal = TcpIp_Tls13Client_CalculateHashOfHsMessages(TlsConIdx, hashLength, &hsHashSegmentPtr);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_CalculateHashOfHsMessages
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
/* PRQA S 6010, 6030 1 */ /* MD_TcpIp_TlsStatemachine_STPTH_6010, MD_TcpIp_TlsStatemachine_STCYC_6030 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_CalculateHashOfHsMessages(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8                       HashLength,
  TcpIp_SegmentPtrType        TargetSegmentPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  uint16 state = TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */

  /* Calculate the Hash of the handshake messages.
   * Messages in parentheses are optional. Their existence has to be checked.
   *
   * Stored in TxBuffer:  ClientHello ( + ClientCertificate + ClientCertificateVerify )
   * Stored in RxBuffer:  ServerHello + EncryptedExtensions ( + ServerCertificateRequest + ServerCertificate + CertificateVerify ) + ServerFinished
   */

  /* #10 Depending on the handshake state add the Hello messages to the Hash function. */
  /* The current function should only be called from specific states. This is checked here. */
  if (   (state == TCPIP_TLS_STATE_WAIT_FOR_SERVER_HELLO_WAIT_FOR_ASYNC)
      || (state == TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_TRIGGER_TX)
      || (state == TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_CALC_SIGNATURE_WAIT_FOR_ASYNC)
      || (state == TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFY_WAIT_FOR_ASYNC)
      || (state == TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_VERIFY)
      || (state == TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_WAIT_FOR_ASYNC_APPL_KEY)
      || (state == TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_WAIT_FOR_ASYNC_RESUMPTION_MASTER_SECRET))
  {
    retVal = TcpIp_Tls13Client_AddHelloMessagesToHash(TlsConIdx);
  }
  else if (state == TCPIP_TLS_STATE_SEND_CLIENT_HELLO_PSK_KEY_WAIT_FOR_ASYNC)
  {
    retVal = TcpIp_Tls13Client_AddTruncatedClientHelloMessageToHash(TlsConIdx, HashLength);
  }
  else
  {
    /* Invalid state, retVal already E_NOT_OK */
  }

  /* #20 Depending on the handshake state add the EncryptedExtensions message to the Hash function. */
  if (retVal == E_OK)
  {
    if (   (state == TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_TRIGGER_TX)
        || (state == TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_CALC_SIGNATURE_WAIT_FOR_ASYNC)
        || (state == TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFY_WAIT_FOR_ASYNC)
        || (state == TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_VERIFY)
        || (state == TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_WAIT_FOR_ASYNC_APPL_KEY)
        || (state == TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_WAIT_FOR_ASYNC_RESUMPTION_MASTER_SECRET))
    {
      retVal = TcpIp_Tls13Client_AddEncryptedExtensionsMsgToHash(TlsConIdx);
    }
  }

  /* #30 Depending on the handshake state add the ServerCertificateRequest message to the Hash function. */
  if (retVal == E_OK)
  {
    if (   (state == TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_TRIGGER_TX)
        || (state == TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_CALC_SIGNATURE_WAIT_FOR_ASYNC)
        || (state == TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFY_WAIT_FOR_ASYNC)
        || (state == TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_VERIFY)
        || (state == TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_WAIT_FOR_ASYNC_APPL_KEY)
        || (state == TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_WAIT_FOR_ASYNC_RESUMPTION_MASTER_SECRET))
    {
      retVal = TcpIp_Tls13Client_AddServerCertificateRequestMsgToHash(TlsConIdx);
    }
  }

  /* #40 Depending on the handshake state add the ServerCertificate message to the Hash function. */
  if (retVal == E_OK)
  {
    if (   (state == TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_TRIGGER_TX)
        || (state == TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_CALC_SIGNATURE_WAIT_FOR_ASYNC)
        || (state == TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFY_WAIT_FOR_ASYNC)
        || (state == TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_VERIFY)
        || (state == TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_WAIT_FOR_ASYNC_APPL_KEY)
        || (state == TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_WAIT_FOR_ASYNC_RESUMPTION_MASTER_SECRET))
    {
      retVal = TcpIp_Tls13Client_AddServerCertificateMsgToHash(TlsConIdx);
    }
  }

  /* #50 Depending on the handshake state add the ServerCertificateVerify message to the Hash function. */
  if (retVal == E_OK)
  {
    if (   (state == TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_TRIGGER_TX)
        || (state == TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_CALC_SIGNATURE_WAIT_FOR_ASYNC)
        || (state == TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_VERIFY)
        || (state == TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_WAIT_FOR_ASYNC_APPL_KEY)
        || (state == TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_WAIT_FOR_ASYNC_RESUMPTION_MASTER_SECRET))
    {
      retVal = TcpIp_Tls13Client_AddServerCertificateVerifyMsgToHash(TlsConIdx);
    }
  }

  /* #60 Depending on the handshake state add the ServerFinished message to the Hash function. */
  if (retVal == E_OK)
  {
    if (   (state == TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_TRIGGER_TX)
        || (state == TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_CALC_SIGNATURE_WAIT_FOR_ASYNC)
        || (state == TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_WAIT_FOR_ASYNC_APPL_KEY)
        || (state == TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_WAIT_FOR_ASYNC_RESUMPTION_MASTER_SECRET))
    {
      retVal = TcpIp_Tls13Client_AddServerFinishedMsgToHash(TlsConIdx);
    }
  }

  /* #70 Depending on the handshake state add the client Certificate message to the Hash function. */
  if (retVal == E_OK)
  {
    if (   (state == TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_TRIGGER_TX)
        || (state == TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_CALC_SIGNATURE_WAIT_FOR_ASYNC)
        || (state == TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_WAIT_FOR_ASYNC_RESUMPTION_MASTER_SECRET))
    {
      retVal = TcpIp_Tls13Client_AddClientCertificateToHash(TlsConIdx);
    }
  }

  /* #80 Depending on the handshake state add the client CertificateVerify message to the Hash function. */
  if (retVal == E_OK)
  {
    if (   (state == TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_TRIGGER_TX)
        || (state == TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_WAIT_FOR_ASYNC_RESUMPTION_MASTER_SECRET))
    {
      retVal = TcpIp_Tls13Client_AddClientCertificateVerifyToHash(TlsConIdx);
    }
  }

  /* #90 Depending on the handshake state add the ClientFinished message to the Hash function. */
  if (retVal == E_OK)
  {
    if (state == TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_WAIT_FOR_ASYNC_RESUMPTION_MASTER_SECRET)
    {
      retVal = TcpIp_Tls13Client_AddClientFinishedToHash(TlsConIdx);
    }
  }

  /* #100 Finalize and calculate the hash. */
  if (retVal == E_OK)
  {
    TcpIp_CsmJobIdType csmHashJobId = TCPIP_TLS_CSM_INV_JOB_ID;
    if (state == TCPIP_TLS_STATE_SEND_CLIENT_HELLO_PSK_KEY_WAIT_FOR_ASYNC)
    {
      /* For this state a different hash job shall be used than for all the other states. */
      TcpIp_Tls13PskIdentityActiveIdxOfTlsConnectionDynType activeTls13PskIdentityIdx
        = TcpIp_GetTls13PskIdentityActiveIdxOfTlsConnectionDyn(TlsConIdx);
      csmHashJobId = TcpIp_GetPskHashCsmJobIdOfTls13PskIdentity(activeTls13PskIdentityIdx);
    }
    else /* state must be valid since retVal is E_OK */
    {
      const TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(
        TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));
      csmHashJobId = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfHashMessagesJobIdIdxOfTlsHandshake(activeTlsHandshakeIdx));
    }
    retVal = TcpIp_Tls13Client_FinalizeHashOfHsMessages(TlsConIdx, csmHashJobId, HashLength, TargetSegmentPtr);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseEncryptedExtensions
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseEncryptedExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx =
    TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxEncryptedExtensionsIdxOfTlsClientBufferMgmtType encryptedExtensionsIdx =
    TcpIp_GetTlsBufferRxEncryptedExtensionsIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the EncryptedExtensions message is received and forward it to the parser */
  if (encryptedExtensionsIdx != TCPIP_NO_TLSBUFFERRXENCRYPTEDEXTENSIONSIDXOFTLSCLIENTBUFFERMGMT)
  {
    Std_ReturnType retVal;

    TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);

    /* Forward message to parser */
    retVal = TcpIp_Tls13ClientMsg_ExtractEncryptedExtensionsInformation(TlsConIdx);

    if (retVal == E_OK)
    {
      /* #20 Extraction was successful. Change the state depending if PSK is active or not */
      TcpIp_DecHsRxIndicationCntOfTlsConnectionDyn(TlsConIdx);
      if (TcpIp_IsSessionResumptionUsingPskOfTlsConnectionDyn(TlsConIdx) == TRUE)
      {
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED);
      }
      else
      {
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CERT_OR_CERT_REQUEST);
      }
    }
    else
    {
      /* #30 Extraction failed. Cancel the handshake. */
      TcpIp_TlsHsStm_HandlesUnexpectedHsInformation(TlsConIdx);
    }
  }
  else
  {
    /* #40 otherwise, we received an unexpected message, trigger the alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
  }
} /* TcpIp_Tls13ClientHsStm_ParseEncryptedExtensions() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ExtractEncryptedExtensionsInformation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ExtractEncryptedExtensionsInformation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxEncryptedExtensionsIdxOfTlsClientBufferMgmtType encryptedExtensionsStartIdx =
    TcpIp_GetTlsBufferRxEncryptedExtensionsIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  TcpIp_EncryptedExtensionsLenOfTlsClientBufferMgmtType encryptedExtensionsLen =
    TcpIp_GetEncryptedExtensionsLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  TcpIp_TlsBufferRxEncryptedExtensionsIdxOfTlsClientBufferMgmtType encryptedExtensionsEndIdx
    = (encryptedExtensionsStartIdx + TCPIP_TLS_HSHDRLEN + encryptedExtensionsLen);

  Std_ReturnType retVal = E_NOT_OK;

  uint16 extensionsLen;

  /* ----- Implementation ----------------------------------------------- */
  /* Check the extensions length for validity. Also checks that the EncryptedExtensions message is not empty. */
  if (TcpIp_TlsCoreUtil_GetExtensionsLengthAndCheckForValidity(TlsConIdx, encryptedExtensionsEndIdx, &extensionsLen) == E_OK)
  {
    /* #10 Parse extensions */
    /* Iterate over the extension data and extract extension(s) */
    retVal = TcpIp_TlsClientMsg_ServerMsgParseAndValidateExtensions(TlsConIdx,
      extensionsLen, encryptedExtensionsEndIdx, TCPIP_TLS_HSTYPE_ENCRYPTEDEXTENSIONS);
  }

  if (retVal == E_OK)
  {
    /* #20 Check that all data is consumed */
    retVal = TcpIp_TlsMsg_CheckMsgForRemainingData(TlsConIdx, encryptedExtensionsEndIdx);
  }

  return retVal;
} /* TcpIp_Tls13ClientMsg_ExtractEncryptedExtensionsInformation() */

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseServerCertificate
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseServerCertificate(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx =
    TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxServerCertificatesIdxOfTlsClientBufferMgmtType serverCertificatesIdx =
    TcpIp_GetTlsBufferRxServerCertificatesIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the server certificate message is received and forward it to the parser */
  if (serverCertificatesIdx != TCPIP_NO_TLSBUFFERRXSERVERCERTIFICATESIDXOFTLSCLIENTBUFFERMGMT)
  {
    Std_ReturnType retVal;

    TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);

    /* Forward message to parser */
    retVal = TcpIp_Tls13ClientMsg_ExtractServerCertificateInformation(TlsConIdx);

    if (retVal == E_OK)
    {
      if (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_ASYNC_PENDING)
      {
        /* Async operation pending, nothing to do - just leave the function */
      }
      else if (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_WAIT_CYCLE)
      {
        /* KeyM is still busy, wait one cycle and try again */
        /* Reset wait cycle for next iteration */
        TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);
      }
      else
      {
        /* The certificate chain is read from the certificate message and verified by the KeyM. */
        TcpIp_CertValidationResultType result = TCPIP_TLS_VALIDATION_UNKNOWN;

        /* Store the ID of the received root certificate. */
        TcpIp_TlsClient_StoreReceivedRootCertId(TlsConIdx);

        /* #20 Extraction was successful. Change the state to TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFY */
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFY);

        /* #30 Check if the overall result of the certificate chain validation is OK or NOT_OK. If it is NOT_OK check
           if the validation callback needs to be called here or later. */
        TcpIp_TlsCoreUtil_TlsUpdateOverallCertValidationResult(TlsConIdx, &result);
        TcpIp_TlsClientMsg_ServerCertMsgCheckCertChainOverallResult(TlsConIdx, result);
      }
    }
    else
    {
      /* #40 Extraction failed. Cancel the handshake. */
      TcpIp_TlsHsStm_HandlesUnexpectedHsInformation(TlsConIdx);
    }
  }
  else
  {
    /* #50 otherwise, we received an unexpected message, trigger the alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
  }
} /* TcpIp_Tls13ClientHsStm_ParseServerCertificate */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ExtractServerCertificateInformation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6030, 6050 1 */ /* MD_TcpIp_TlsStatemachine_STCYC_6030, MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ExtractServerCertificateInformation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Parse the message ServerCertificate until we are done AND no Async context needs to be computed */
  while (   (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_DONE)  /* PRQA S 3415 6 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
            /* Handshake is in state aborted due to processing error */
         && (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_HANDSHAKE_ABORT)
            /* Async operation is pending */
         && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_ASYNC_PENDING)
            /* KeyM is busy - Wait cycle */
         && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_WAIT_CYCLE)
            /* Error during parsing - abort next steps */
         && (retVal == E_OK))
  {
    switch (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx))
    {
      case TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE:
      case TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_LOADCERTS:
      {
        /* #20 Extract the certificates from the received chain, store them in the KeyM, and trigger KeyM to verify the cert group */
        if (TcpIp_Tls13ClientMsg_ServerCertMsgProcessCertChain(TlsConIdx) == E_OK)
        {
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFYGROUP_CHECK);
          TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_WAIT_CYCLE);
        }
        else
        {
          retVal = E_NOT_OK;
        }
        break;
      }

      case TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFYGROUP_CHECK:
      {
        /* #30 Periodically check if KeyM has finished the cert chain validation */
        if (KeyM_Cert_IsBusy() == TRUE)
        {
          /* The KeyM is still busy to process the cert chain validation */
          /* do nothing, just wait for next main function */
          TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_WAIT_CYCLE);
        }
        else
        {
          /* The cert chain validation has been finished by the KeyM. Go into next state */
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFYGROUP_STATUS);
        }
        break;
      }

      case TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFYGROUP_STATUS:
      {
        /* #40 The cert chain validation has been finished by the KeyM. Now check the result and calculate an overall status. */
        retVal =  TcpIp_TlsClientMsg_ServerCertMsgVerifyCertificateGroup(TlsConIdx);


        if (TcpIp_IsTlsUseExtensionCertificateStatusRequestOfTlsConnection(TlsConIdx) == TRUE)
        {
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_TRIGGER_OCSP_VALIDATION);
          TcpIp_SetTlsCertValidationStatusDynCurrentIdxOfTlsConnectionDyn(TlsConIdx,
            TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx));
          /* Setup the current index and the valid end idx for OCSP responses */
          TcpIp_SetTlsClientOcspBufferMgmtCurrentIdxOfTlsConnectionDyn(TlsConIdx,
            TcpIp_GetTlsClientOcspBufferMgmtStartIdxOfTlsConnection(TlsConIdx));
        }
        else
        {
          /* Skip OCSP processing */
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_DETERMINE_NEXT_STATE);
        }

        break;
      }

      case TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_TRIGGER_OCSP_VALIDATION:
      {
        TcpIp_Tls13ClientMsg_ServerCertStatusTriggerOcspValidation(TlsConIdx);
        /* Continue with updating the status once the OCSP response is processed in async context */
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_UPDATE_CERT_STATUS);
        break;
      }

      case TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_UPDATE_CERT_STATUS:
      {
        const TcpIp_TlsCertValidationStatusDynIterType endIdx
          = TcpIp_GetTlsClientOcspBufferMgmtValidEndIdxOfTlsConnectionDyn(TlsConIdx);

        /* The OCSP information has to be updated directly after it was written to KeyM.
         * This needs to be done as the result of lower certs may be discarded once a
         * an intermediate certificate is revoked. Therefore, writing all OCSPs responses
         * to KeyM and then evaluate the single results does not work. Only the result
         * result of the highest cert being revoked can be fetched then. */
        retVal = TcpIp_Tls13Client_TlsUpdateOcspInformation(TlsConIdx);

        if (retVal == E_OK)
        {
          /* Increment the currentIdx by one so that the next response can be handled */
          TcpIp_IncTlsCertValidationStatusDynCurrentIdxOfTlsConnectionDyn(TlsConIdx);
          TcpIp_IncTlsClientOcspBufferMgmtCurrentIdxOfTlsConnectionDyn(TlsConIdx);

          if (TcpIp_GetTlsClientOcspBufferMgmtCurrentIdxOfTlsConnectionDyn(TlsConIdx) < endIdx)
          {
            TcpIp_Tls13ClientMsg_ServerCertStatusTriggerOcspValidation(TlsConIdx);
          }
          else
          {
            /* All OCSP response are handled, update status and continue with next state */
            TcpIp_SetTlsCertValidationStatusDynCurrentIdxOfTlsConnectionDyn(TlsConIdx, 0);
            TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_DETERMINE_NEXT_STATE);
          }
        }
        break;
      }

      case TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_DETERMINE_NEXT_STATE:
      {
        /* Decrement HsRxIndicationCnt since the certificate message is completely parsed. */
        TcpIp_DecHsRxIndicationCntOfTlsConnectionDyn(TlsConIdx);
        TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_NO_ASYNC);
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_DONE);
        break;
      }

      default:                                                                                                           /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
      {
        break;
      } /* default */
    } /* switch() */

  } /* while() */

  return retVal;
} /* TcpIp_Tls13ClientMsg_ExtractServerCertificateInformation() */

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_TlsUpdateOcspInformation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_TlsUpdateOcspInformation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsCertValidationStatusDynIterType curTlsCertValidationStatusIdx
    = TcpIp_GetTlsCertValidationStatusDynCurrentIdxOfTlsConnectionDyn(TlsConIdx);

  TCPIP_CP2V(TcpIp_CertValidationStatusType) currentCertStatusPtr
    = TcpIp_GetAddrTlsCertValidationStatusDyn(curTlsCertValidationStatusIdx);

  Std_ReturnType retVal = E_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 OCSP enabled, check if the OCSP Certificate Status is received */
  if (currentCertStatusPtr->CertStatusResponse.OcspConnectionState == TCPIP_TLS_OCSP_CONNECTION_STATE_STATUS_RECEIVED)
  {
    /* #20 Update OCSP information which are then provided to upper layer via validation callback */
    retVal = TcpIp_TlsClient_TlsUpdateOcspCertificateStatus(currentCertStatusPtr);

    if (retVal == E_OK)
    {
      /* #30 Check the response status and update the overall validation result */
      if (currentCertStatusPtr->CertStatusResponse.OcspResponseStatus == TCPIP_TLS_OCSP_RESPONSE_STATUS_SUCCESSFUL)
      {
        if (currentCertStatusPtr->CertStatusResponse.OcspCertStatus == KEYM_E_CERTIFICATE_REVOKED)
        {
          TcpIp_SetTlsCertValidationResultOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_VALIDATION_NOT_OK);
        }
      }
      else
      {
        TcpIp_SetTlsCertValidationResultOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_VALIDATION_NOT_OK);
      }
    }
    else
    {
      /* According to RFC 6961, a bad_certificate_status_response alert should be send
       * if an unacceptable OCSP response is received. */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_BAD_CERT_STATUS_RESP);
    }
  }

  return retVal;
} /* TcpIp_Tls13Client_TlsUpdateOcspInformation() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerCertMsgProcessCertChain
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerCertMsgProcessCertChain(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxServerCertificatesIdxOfTlsClientBufferMgmtType serverCertificatesStartIdx =
    TcpIp_GetTlsBufferRxServerCertificatesIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  TcpIp_ServerCertificatesLenOfTlsClientBufferMgmtType serverCertificatesLen =
    TcpIp_GetServerCertificatesLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  TcpIp_TlsBufferRxServerCertificatesIdxOfTlsClientBufferMgmtType serverCertificatesEndIdx
    = (serverCertificatesStartIdx + TCPIP_TLS_HSHDRLEN
        + (TcpIp_TlsBufferRxServerCertificatesIdxOfTlsClientBufferMgmtType) serverCertificatesLen);

  /* If one of the following steps fails, send a decode_error alert per default. */
  TcpIp_TlsAlertDescriptionType alertDescription = TCPIP_TLS_ALERT_DESC_DECODE_ERROR;

  TcpIp_TlsBufferRxIterType certStartIdx = 0u;

  uint8 numCerts = 0u;

  uint32 certListLength = 0u;

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  if (TcpIp_Tls13ClientMsg_ServerCertMsgCheckLengths(TlsConIdx, &certListLength) == E_OK)
  {
    /* Save the current read index (start of the first certificate) in certStartIdx
     * since TcpIp_Tls13ClientMsg_ServerCertMsgParseAndTriggerVerification() needs this.
     * TcpIp_Tls13Client_GetNumOfCertificates() already increments the read index
     * when iterating over the received certificates in the chain. */
    certStartIdx = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
    /* #10 Get number of received certificates */
    if (TcpIp_Tls13Client_GetNumOfCertificates(TlsConIdx, certListLength, serverCertificatesEndIdx, &numCerts) == E_OK)
    {
      /* If the verification of the chain fails an unknown_ca alert should be send. */
      alertDescription = TCPIP_TLS_ALERT_DESC_UNKNOWN_CA;

      /* #20 Extract the certificates from the received chain and store them in the KeyM */
      retVal = TcpIp_Tls13ClientMsg_ServerCertMsgParseAndTriggerVerification(TlsConIdx, certStartIdx, numCerts);
    }
  }

  if (retVal == E_OK)
  {
    /* #30 Check that all data is consumed */
    retVal = TcpIp_TlsMsg_CheckMsgForRemainingData(TlsConIdx, serverCertificatesEndIdx);
  }

  if (retVal != E_OK)
  {
    /* #40 Extraction of server certificates failed, report user error */
    TcpIp_TlsUserErrorType UserError;
    UserError.FunctionId = TCPIP_TLS_FCTID_CLIENT_HSSTM_PARSE_SERVERCERT;
    UserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_INCORRECTHSMSG;
    UserError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(UserError);

    /* Trigger alert protocol_version in case of invalid length of certificate */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, alertDescription);

    retVal = E_NOT_OK;
  }

  return retVal;
} /* TcpIp_Tls13ClientMsg_ServerCertMsgProcessCertChain */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerCertMsgCheckLengths
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerCertMsgCheckLengths(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint32)           CertListLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_ServerCertificatesLenOfTlsClientBufferMgmtType serverCertificatesLen =
    TcpIp_GetServerCertificatesLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  TcpIp_TlsBufferRxAdHsEndIdxOfTlsBufferMgmtType tlsBufferRxAdHsEndIdx
    = TcpIp_GetTlsBufferRxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check that message is long enough to contain the cert request context and the certificate chain. */
  if (   (TcpIp_TlsHs_CheckExpectedMsgLen(
            serverCertificatesLen, (TCPIP_TLS_CERT_REQUEST_CONTEXT_LEN_LEN + TCPIP_TLS_CERTCHAINLEN_LEN)) == E_OK)
    &&   (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx),
            TCPIP_TLS_CERT_REQUEST_CONTEXT_LEN_LEN + TCPIP_TLS_CERTCHAINLEN_LEN, tlsBufferRxAdHsEndIdx)))
  {
    /* The RFC 8446 in chapter 4.4.2 states that when the Certificate message is not in response to a
     * CertificateRequest message (in the case of server authentication),
     * certificate_request_context SHALL be zero length. */
    uint8 contextLen = IpBase_GetUint8(TcpIp_GetAddrTlsBufferRx(
       TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)), 0u);
    TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
       (TCPIP_TLS_CERT_REQUEST_CONTEXT_LEN_LEN + (TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType) contextLen));

    /* #20 Check that the certificate_request_context is zero length. */
    if (contextLen == 0u)
    {
      /* Read cert list length */
      uint32 certListLen = IpBase_GetUint24(
        TcpIp_GetAddrTlsBufferRx(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)), 0u);
      TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_CERTCHAINLEN_LEN);

      /* #30 Check that the cert list length + the length field before it add up to the certificate message length. */
      if ((certListLen + TCPIP_TLS_CERTCHAINLEN_LEN + TCPIP_TLS_CERT_REQUEST_CONTEXT_LEN_LEN)
        == (uint32) TcpIp_GetServerCertificatesLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx))
      {
        *CertListLenPtr = certListLen;
        retVal = E_OK;
      }
    }
    else
    {
      /* Length is not zero - issue illegal_parameter alert */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_ILLEGAL_PARAM);
    }
  }

  return retVal;
} /* TcpIp_Tls13ClientMsg_ServerCertMsgCheckLengths */

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_GetNumOfCertificates
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_GetNumOfCertificates(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint32                      CertChainLen,
  TcpIp_TlsBufferRxIterType   CertEndIdx,
  TCPIP_P2V(uint8)            NumCertPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 numCert = 0u;
  uint32 certBytes = 0u;

  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_SizeOfTlsClientBufferMgmtType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxAdHsEndIdxOfTlsBufferMgmtType tlsBufferRxAdHsEndIdx
    = TcpIp_GetTlsBufferRxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  uint16 extensionsLen = 0u;

  boolean abortParsing = FALSE;

  Std_ReturnType retVal;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Traverse through the received chain and count number of certificates */
  while (certBytes < CertChainLen)
  {
    /* Extract length of the current certificate */
    /* Check if the length of the certificate length fits into the TLS RxBuffer */
    if (  (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx),
             TCPIP_TLS_CERTLEN_LEN,
             tlsBufferRxAdHsEndIdx))
    /* Check that the received certificate length is greater then the expected length */
        && (TcpIp_GetServerCertificatesLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx)
           >= (certBytes + TCPIP_TLS_CERTLEN_LEN + TCPIP_TLS_CERTCHAINLEN_LEN + TCPIP_TLS_CERT_REQUEST_CONTEXT_LEN_LEN)))
    {
      uint32 certLength = IpBase_GetUint24(TcpIp_GetAddrTlsBufferRx(
        TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)), 0);
      /* Increase by length of the current certificate */
      certBytes += certLength + TCPIP_TLS_CERTLEN_LEN;
      /* Increment read index by size of certificate and the length of certLen field */
      TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
        (TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType)(certLength + TCPIP_TLS_CERTLEN_LEN));
      numCert++;

      if (TcpIp_TlsCoreUtil_GetExtensionsLengthAndCheckForValidity(TlsConIdx, CertEndIdx, &extensionsLen) == E_OK)
      {
        /* #20 Parse extensions */
        /* Iterate over the extension data and extract extension(s) */
        if (TcpIp_TlsClientMsg_ServerMsgParseAndValidateExtensions(TlsConIdx, extensionsLen, CertEndIdx, TCPIP_TLS_HSTYPE_CERTIFICATE) == E_OK)
        {
          certBytes += (uint32) extensionsLen + TCPIP_TLS_EXTENSION_LENGTH_LEN;
          /* Increment OCSP status index by one.
           * This is done as for each certificate the ocsp response may be attached.
           * And later on we then can differentiate between the ocsp response and the
           * related certs. As both are incremented.
           * If a cert has no OCSP response the length is set to 0.
           * An invalid ocsp extension aborts the parsing and does not execute this path.
           * */
          TcpIp_IncTlsClientOcspBufferMgmtValidEndIdxOfTlsConnectionDyn(TlsConIdx);
          TcpIp_IncTlsCertValidationStatusDynValidEndIdxOfTlsConnectionDyn(TlsConIdx);
        }
        else
        {
          abortParsing = TRUE;
        }
      }
      else
      {
        abortParsing = TRUE;
      }
    }
    else
    {
      abortParsing = TRUE;
    }

    if (abortParsing == TRUE)
    {
      break;
    }
  }

  if ((CertChainLen == 0u) || (certBytes != CertChainLen) || (abortParsing == TRUE))
  {
    retVal = E_NOT_OK;
  }
  else
  {
    retVal = E_OK;
    *NumCertPtr = numCert;
  }

  return retVal;
} /* TcpIp_Tls13Client_GetNumOfCertificates */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerCertMsgParseAndTriggerVerification
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerCertMsgParseAndTriggerVerification(
  TcpIp_TlsConnectionIterType         TlsConIdx,
  TcpIp_TlsBufferRxIterType           CertStartIdx,
  uint8                               NumCerts)
{
  /* ----- Local Variables ---------------------------------------------- */

  TcpIp_TlsRemoteKeyMCertInfoStartIdxOfTlsConnectionType tlsRemoteKeyMCertInfoIdx
    = TCPIP_NO_TLSLOCALKEYMCERTINFOSTARTIDXOFTLSCONNECTION;

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ---------------------------------------------- */
  /* TcpIp_TlsCoreUtil_CheckEccKeyMConfiguration() ensures
   * that there is exactly one KeyM remote reference for this connection.
   * The behavior for multiple references and therefore multiple KeyM groups is unclear.
   * After this check we can rely on only one KeyM group which is referenced through TlsRemoteKeyMCertInfoStartIdx.
   * The function also ensures that the functions KeyM_VerifyGroup() and KeyM_SetCertificateInGroup are available. */
  if (TcpIp_TlsCoreUtil_CheckEccKeyMConfiguration(TlsConIdx) == E_OK)
  {
    tlsRemoteKeyMCertInfoIdx = TcpIp_GetTlsRemoteKeyMCertInfoStartIdxOfTlsConnection(TlsConIdx);

    /* #10 Set the certificates from the received certificate chain in the KeyM certificate group. */
    retVal = TcpIp_TlsCoreMsg_CertMsgSetCertificatesInGroup(TlsConIdx, CertStartIdx, NumCerts);

    /* Check if the curve of the leaf certificate matches to the curve received in the Key Share extension
     * of the Server Hello message. */
    if (retVal == E_OK)
    {
      retVal = TcpIp_Tls13ClientMsg_ServerCertMsgCheckIfCurveMatchesKeyShareExt(TlsConIdx);
    }

    if (retVal == E_OK)
    {
      retVal = TcpIp_Tls13ClientMsg_ServerCertMsgCheckIfSigAlgoIsSupported(TlsConIdx);
    }

    /* #20 If all certificates were successfully extracted and loaded, trigger verification of the leaf certificate */
    if (retVal == E_OK)
    {
      /* Get the KeyM group with TlsRemoteKeyMCertInfoStartIdx. */
      /* It is checked in TcpIp_TlsCoreUtil_CheckEccKeyMConfiguration()
       * that TcpIp_GetKeyMVerifyGroupFuncOfTlsConfig() is not a NULL_PTR. */
      TcpIp_TlsKeyMVerifyGroupFunctionType verifyGroupFunc
        = TcpIp_GetKeyMVerifyGroupFuncOfTlsConfig(TCPIP_TLSCONFIG_IDX);
      if (verifyGroupFunc(TcpIp_GetCertGroupIdOfTlsRemoteKeyMCertInfo(tlsRemoteKeyMCertInfoIdx)) == E_OK)
      {
        /* Update Hs certificate state to in progress */
        /* [HS Server Certificate Chain Handling StM] Certificates loaded successfully and verification triggered  */
        TcpIp_SetHsCertStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CERTCHAIN_IN_PROGRESS);
      }
      else
      {
        /* Verification failed - one reason may be Root or intermediate certificate not found, or KeyM is busy */
        TcpIp_TlsClientMsg_ServerCertMsgHandleFailedCertGroupValidation(TlsConIdx);

        retVal = E_NOT_OK;
      }
    }
  }
  else
  {
    TcpIp_TlsCoreUtil_HandleInvalidConfiguration(TlsConIdx);
  }

  return retVal;
} /* TcpIp_Tls13ClientMsg_ServerCertMsgParseAndTriggerVerification */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerCertMsgCheckIfSigAlgoIsSupported
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerCertMsgCheckIfSigAlgoIsSupported(
  TcpIp_TlsConnectionIterType         TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SignatureAlgorithmIdType algoId = TCPIP_SIG_ALGO_ID_NONE;
  /* Get the certificate Id of the leaf certificate. */
  TcpIp_TlsCertValidationStatusDynIterType tlsCertValidationStatusIdx
    = TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx);
  KeyM_CertificateIdType certId = TcpIp_GetAddrTlsCertValidationStatusDyn(tlsCertValidationStatusIdx)->CertId;
  KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the certificate is available. */
  if ((KeyM_CertGetStatus(certId, &certStatus) == E_OK) && (certStatus != KEYM_CERTIFICATE_NOT_AVAILABLE))
  {
    /* #20 Get the signature algorithm used for the leaf certificate. */
    /* We assume for now that the signature algorithm is the same for all certificates in the chain.
     * This is checked later in the KeyM (KeyM_VerifyGroup()). */
    if (TcpIp_TlsCoreUtil_ReadCertSignatureAlgorithm(certId, &algoId) == E_OK)
    {
      /* #30 Check if the signature algorithm is present in the current working set, which means it is supported. */
      if (TcpIp_TlsClient_IsSignatureAlgorithmInWorkingSet(TlsConIdx, algoId))
      {
        retVal = E_OK;
      }
      else
      {
        /* retVal is already E_NOT_OK */
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNSUP_CERT);
      }
    }
  }
  return retVal;
} /* TcpIp_Tls13ClientMsg_ServerCertMsgCheckIfSigAlgoIsSupported */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerCertMsgCheckIfCurveMatchesKeyShareExt
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerCertMsgCheckIfCurveMatchesKeyShareExt(
  TcpIp_TlsConnectionIterType         TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsEllipticCurveIdType curveId = TCPIP_CURVE_ID_NO_CURVE;
  /* Get the certificate Id of the leaf certificate. */
  TcpIp_TlsCertValidationStatusDynIterType tlsCertValidationStatusIdx
    = TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx);
  KeyM_CertificateIdType certId = TcpIp_GetAddrTlsCertValidationStatusDyn(tlsCertValidationStatusIdx)->CertId;
  KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the certificate is available. */
  if ((KeyM_CertGetStatus(certId, &certStatus) == E_OK) && (certStatus != KEYM_CERTIFICATE_NOT_AVAILABLE))
  {
    /* #20 Get the curve used in the public key of the leaf certificate. */
    /* We assume for now that the curve is the same for all certificates in the chain.
     * This is checked later in the KeyM (KeyM_VerifyGroup()). */
    if (TcpIp_TlsCoreUtil_GetCurveFromCertificate(certId, &curveId) == E_OK)
    {
      /* #30 Check if the curve of the Key Share extension matches the curve of the leaf certificate. */
      /* The curve of the Key Share extension is saved in the CSL
       * (see TcpIp_Tls13ClientMsg_ServerHelloParseExtensionKeyShare()). */
      if (TcpIp_GetEllipticCurveIdOfTlsConnectionDyn(TlsConIdx) == curveId)
      {
        retVal = E_OK;
      }
    }
  }

  return retVal;
} /* TcpIp_Tls13ClientMsg_ServerCertMsgCheckIfCurveMatchesKeyShareExt */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerCertStatusTriggerOcspValidation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerCertStatusTriggerOcspValidation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx
    = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Trigger the validation of the received OCSP response in the asynchronous task */
  /* Validation performed in TcpIp_Tls13ClientCtx_ValidateCertificateStatus() */
  TcpIp_SetCertificateStatusOcspValidationAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx, TRUE);
  TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_ASYNC_PENDING);

} /* TcpIp_Tls13ClientMsg_ServerCertStatusTriggerOcspValidation() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseServerCertificateVerify
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseServerCertificateVerify(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx =
    TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxServerCertificateVerifyIdxOfTlsClientBufferMgmtType serverCertVerifyIdx =
    TcpIp_GetTlsBufferRxServerCertificateVerifyIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the server certificate verify message is received */
  if (serverCertVerifyIdx != TCPIP_NO_TLSBUFFERRXSERVERCERTIFICATEVERIFYIDXOFTLSCLIENTBUFFERMGMT)
  {
    TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);

    /* # 20 Forward the message to the parser and extract the information */
    if (TcpIp_Tls13ClientMsg_ExtractServerCertificateVerifyInformation(TlsConIdx) != E_OK)
    {
      /* #20 Extraction failed. Cancel the handshake. */
      TcpIp_TlsHsStm_HandlesUnexpectedHsInformation(TlsConIdx);
    } /* else - regular case: ServerCertificateVerify successfully parsed */
  }
  else
  {
    /* #30 Otherwise, we received an unexpected message, trigger the alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
  }
} /* TcpIp_Tls13ClientHsStm_ParseServerCertificateVerify() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ExtractServerCertificateVerifyInformation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ExtractServerCertificateVerifyInformation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx =
    TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  while ( /* Error during parsing - abort next steps. */
            (retVal == E_OK)
          /* State is not in state "TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED" */                                        /* PRQA S 3415 7 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
         && (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED)
         /* Handshake is not aborted due to processing error. */
         && (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_HANDSHAKE_ABORT)
         /* Async operation is pending. */
         && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_ASYNC_PENDING)
         /* Next state could not be determine (missing next HS message) - Wait cycle. */
         && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_WAIT_CYCLE))
  {
    switch (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx))
    {
      case TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFY:
      {
        /* #10 Parse the CertificateVerify message. */
        retVal = TcpIp_Tls13ClientHsStm_ParseCertificateVerifyMsg(TlsConIdx);

        if (retVal == E_OK)
        {
          /* Parsing of the message was successful. Set next state. */
          TcpIp_DecHsRxIndicationCntOfTlsConnectionDyn(TlsConIdx);
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFY_VERIFY_SIGNATURE);
        }

        break;
      }
      case TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFY_VERIFY_SIGNATURE:
      {
        /* #20 Trigger the calculation of the job in the async context handler and change the handshake state to ASYNC_PENDING. */
        TcpIp_SetVerifyCertVerifySignatureAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx, TRUE);

        /* Set the state to ASYNC_PENDING */
        TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_ASYNC_PENDING);

        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFY_WAIT_FOR_ASYNC);
        break;
      }

      case TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFY_WAIT_FOR_ASYNC:
      {
        /* Check if the calculation in the async context is still pending. */
        if (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_ASYNC_PENDING)
        {
          /* The verification of the signature is done. */
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFY_DETERMINE_NEXT_STATE);

          /* Asynchronous validation performed, reset the connection state */
          TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_NO_ASYNC);
        }
        break;
      }

      case TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFY_DETERMINE_NEXT_STATE:
      {
        /* Set the next state TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED. */
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED);
        break;
      }

      default:
      {
        /* Not expected state. */
        retVal = E_NOT_OK;
        break;
      }
    } /* switch() */
  } /* while() */

  return retVal;
} /* TcpIp_Tls13ClientMsg_ExtractServerCertificateVerifyInformation() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseCertificateVerifyMsg
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseCertificateVerifyMsg(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtDynIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxServerCertificateVerifyIdxOfTlsClientBufferMgmtType serverCertVerifyStartIdx =
    TcpIp_GetTlsBufferRxServerCertificateVerifyIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  TcpIp_ServerCertificateVerifyLenOfTlsClientBufferMgmtType serverCertVerifyLen =
    TcpIp_GetServerCertificateVerifyLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  TcpIp_TlsBufferRxServerCertificateVerifyIdxOfTlsClientBufferMgmtType serverCertVerifyEndIdx
    = (serverCertVerifyStartIdx + TCPIP_TLS_HSHDRLEN + serverCertVerifyLen);

  Std_ReturnType retVal = E_NOT_OK;
  TcpIp_SignatureAlgorithmIdType algorithm = TCPIP_SIG_ALGO_ID_NONE;
  uint16 signatureLength = 0u;
  /* ----- Implementation ----------------------------------------------- */
  /* Check that message is long enough to contain the signature algorithm and the length field for the signature. */
  if (   (TcpIp_TlsHs_CheckExpectedMsgLen(serverCertVerifyLen, TCPIP_TLS_CERTVERIFY_SIGALGO_LEN + TCPIP_TLS_CERTVERIFY_SIG_LENGTH_LEN) == E_OK)
      && (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx), TCPIP_TLS_CERTVERIFY_SIGALGO_LEN, serverCertVerifyEndIdx)))
  {
    /* #10 Read the signature algorithm send by the server. */
    algorithm = (TcpIp_SignatureAlgorithmIdType) IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(                             /* PRQA S 4342 */ /* MD_TcpIp_TlsCore_10.5_4342_a */
      TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx)), 0u);
    TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx, TCPIP_TLS_CERTVERIFY_SIGALGO_LEN);

    /* #20 Check if the received signature algorithm is allowed. */
    retVal = TcpIp_Tls13ClientHsStm_CheckSignatureAlgorithmInCertificateVerifyMsg(TlsConIdx, algorithm);

    /* Check that the received message is long enough to contain a signature with the specified length. */
    if (   (retVal == E_OK)
        && (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx),     /* PRQA S 2995 2 */ /* MD_TcpIp_Tls_2995 */
              TCPIP_TLS_CERTVERIFY_SIG_LENGTH_LEN, serverCertVerifyEndIdx)))
    {
      /* #30 Read the length of the signature. */
      signatureLength = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx)), 0u);
      /* Save the index to the length of the signature. */
      TcpIp_SetTlsBufferRxServerSignatureLenIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
        TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx));
      TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx, TCPIP_TLS_CERTVERIFY_SIG_LENGTH_LEN);

      if (   (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx),   /* PRQA S 2995 2 */ /* MD_TcpIp_Tls_2995 */
                signatureLength, serverCertVerifyEndIdx))
          && (serverCertVerifyLen
                == (TCPIP_TLS_CERTVERIFY_SIGALGO_LEN + TCPIP_TLS_CERTVERIFY_SIG_LENGTH_LEN + signatureLength)))
      {
        /* Save the index to the signature of the message. */
        TcpIp_SetTlsBufferRxServerSignatureIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
          TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx));
        TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx, signatureLength);

        /* Check if all data was consumed. */
        retVal = TcpIp_TlsMsg_CheckMsgForRemainingData(TlsConIdx, serverCertVerifyEndIdx);
      }
      else
      {
        /* Length check of signature length failed */
        retVal = E_NOT_OK;
      }
    }
    else
    {
      /* Length check of signature length field failed */
      retVal = E_NOT_OK;
    }
  }

  return retVal;
} /* TcpIp_Tls13ClientHsStm_ParseCertificateVerifyMsg() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_CheckSignatureAlgorithmInCertificateVerifyMsg
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_CheckSignatureAlgorithmInCertificateVerifyMsg(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SignatureAlgorithmIdType SignatureAlgorithm)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the Signature Algorithm is one of the supported algorithms. */
  /* RFC 8446 Section 4.4.3 states that the Signature Algorithm MUST not be SHA-1. */
  if (   (SignatureAlgorithm == TCPIP_SIG_ALGO_ID_ECDSA_SECP256R1_SHA256)
      || (SignatureAlgorithm == TCPIP_SIG_ALGO_ID_ECDSA_SECP521R1_SHA512)
      || (SignatureAlgorithm == TCPIP_SIG_ALGO_ID_ECDSA_ED25519_INTRINSIC)
      || (SignatureAlgorithm == TCPIP_SIG_ALGO_ID_ECDSA_ED448_INTRINSIC))
  {
    /* #20 Check if the Signature Algorithm is one of the algorithms sent in the ClientHello (SignatureAlgorithms Extension). */
    if (TcpIp_Tls13ClientUtil_CheckSignatureAlgorithmsExtensionForEntry(TlsConIdx, SignatureAlgorithm) == E_OK)
    {
      /* #30 Check if the Signature Algorithm matches the signature algorithm in the received certificate. */
      retVal =
        TcpIp_TlsCoreUtil_CheckSignatureAlgorithmAgainstCertificateAlgorithm(TlsConIdx, SignatureAlgorithm);
    }
  }

  if (retVal != E_OK)
  {
    /* The received Signature Algorithm is either not supported, was not offered in the ClientHello message or does
     * not match with the signature algorithm in the received certificate. */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_ILLEGAL_PARAM);
  }

  return retVal;
} /* TcpIp_Tls13ClientHsStm_CheckSignatureAlgorithmInCertificateVerifyMsg() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientUtil_CheckSignatureAlgorithmsExtensionForEntry
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientUtil_CheckSignatureAlgorithmsExtensionForEntry(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SignatureAlgorithmIdType SignatureAlgorithm)
{
  /* ----- Local Variables ---------------------------------------------- */

  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferTxClientSignatureAlgorithmsExtensionIdxOfTlsClientBufferMgmtType sigAlgorithmsLenTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxClientSignatureAlgorithmsExtensionIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  uint16 signatureAlgorithmsLen = IpBase_GetUint16(TcpIp_GetAddrTlsBufferTx(sigAlgorithmsLenTlsBufferTxIdx), 0u);

  TcpIp_TlsBufferTxIterType extAlgorithmsStartIdx = sigAlgorithmsLenTlsBufferTxIdx + TCPIP_TLS_SIGNATURE_ALGORITHMS_LENGTH_LEN;

  TcpIp_TlsBufferTxIterType extAlgorithmsEndIdx = extAlgorithmsStartIdx + signatureAlgorithmsLen;

  TcpIp_TlsBufferTxIterType extAlgorithmsTlsBufferTxIdx = extAlgorithmsStartIdx;

  Std_ReturnType retVal = E_NOT_OK;

  TcpIp_SignatureAlgorithmIdType currentSignatureAlgorithmId = TCPIP_SIG_ALGO_ID_NONE;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Iterate over the sent Signature Algorithms and check if the received one matches */
  for (extAlgorithmsTlsBufferTxIdx = extAlgorithmsStartIdx; extAlgorithmsTlsBufferTxIdx < extAlgorithmsEndIdx;
       extAlgorithmsTlsBufferTxIdx += TCPIP_TLS_SIGNATURE_ALGORITHMS_ALG_ID_LEN)
  {
    currentSignatureAlgorithmId
      = (TcpIp_SignatureAlgorithmIdType) IpBase_GetUint16(TcpIp_GetAddrTlsBufferTx(extAlgorithmsTlsBufferTxIdx), 0u);   /* PRQA S 4342 */ /* MD_TcpIp_TlsCore_10.5_4342_a */

    if (currentSignatureAlgorithmId == SignatureAlgorithm)
    {
      retVal = E_OK;
      break;
    }
  }

  return retVal;
} /* TcpIp_Tls13ClientUtil_CheckSignatureAlgorithmsExtensionForEntry() */
#   endif

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_HandleWaitCertCR
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_HandleWaitCertCR(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
 /*
  * Implements the junction WAIT_CERT_CR of RFC 8466 appendix "A.1. Client"
  *
  * If client has received a EncryptedExtension from server, tls client
  * can receive either a CertificateRequest or Certificate message as next
  * message.
  *
  * Limitations:
  * - PSK path is not implemented. (Should not be implemented here)
  *
  *
  *                | Recv EncryptedExtensions
  *       +--------+--------+
  * Using |                 | Using certificate
  *   PSK |                 v
  *       |            WAIT_CERT_CR
  *       |        Recv |       | Recv CertificateRequest
  *       | Certificate |       v
  *
  */
  /* ----- Local Variables ---------------------------------------------- */


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Choose next state based on received HS type */
  switch (TcpIp_GetLastReceivedHsTypeOfTlsConnectionDyn(TlsConIdx))
  {
    /* #20 CertificateRequest: Update state to TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_REQUEST */
    case TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST:
    {
      TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_REQUEST);
      break;
    }

    /* #30 Certificate: Update state to TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE */
    case TCPIP_TLS_HSTYPE_CERTIFICATE:
    {
      TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE);
      break;
    }

    /* #40 Otherwise: Report unexpected message, trigger associated alert */
    default:
    {
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
      TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_ABORT);
      break;
    }
  }
} /* TcpIp_Tls13ClientHsStm_HandleWaitCertCR() */

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseServerCertificateRequest
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseServerCertificateRequest(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* Implements the parsing of a CertificateRequest message
   * according to RFC 8466 section 4.3.2.
   *
   * Data type according to RFC:
   *  struct {
   *      opaque certificate_request_context<0..2^8-1>;
   *      Extension extensions<2..2^16-1>;
   *  } CertificateRequest;
   *
   */

  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  const TcpIp_TlsBufferRxEncryptedExtensionsIdxOfTlsClientBufferMgmtType certificateRequestIdx
    = TcpIp_GetTlsBufferRxServerCertificateRequestIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  const TcpIp_ServerCertificateRequestLenOfTlsClientBufferMgmtType serverCertRequestLen
    = TcpIp_GetServerCertificateRequestLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  const TcpIp_TlsBufferRxServerCertificateRequestIdxOfTlsClientBufferMgmtType serverCertRequestEndIdx
    = (certificateRequestIdx + TCPIP_TLS_HSHDRLEN + serverCertRequestLen);


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the server CertificateRequest message is received and forward it to the parser */
  if (certificateRequestIdx != TCPIP_NO_TLSBUFFERRXSERVERCERTIFICATEREQUESTIDXOFTLSCLIENTBUFFERMGMT)
  {
    /* #20 Handle certificate_request_context */
    Std_ReturnType retVal = TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestCertificateRequestContext(TlsConIdx);

    /* #30 Handle extensions */
    if (retVal == E_OK)
    {
      retVal = TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestExtensions(TlsConIdx);
    }

    /* #40 Check if unprocessed data is available */
    if (retVal == E_OK)
    {
      retVal = TcpIp_TlsMsg_CheckMsgForRemainingData(TlsConIdx, serverCertRequestEndIdx);
    }

    /* #50 Check if message processing was successful */
    if (retVal == E_OK)
    {
      /* #60 Yes: Continue with TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE */
      TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE);

      /* Decrement HsRxIndicationCnt since the Server Certificate Request message is completely parsed. */
      TcpIp_DecHsRxIndicationCntOfTlsConnectionDyn(TlsConIdx);
    }
    else
    {
      /* #70 No: Raise alert and abort handshake */
      TcpIp_TlsHsStm_HandlesUnexpectedHsInformation(TlsConIdx);
    }
  }
} /* TcpIp_Tls13ClientHsStm_ParseServerCertificateRequest() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestCertificateRequestContext
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestCertificateRequestContext(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* Implements the parsing of certificate_request_context which is part
   * of a CertificateRequest message according to RFC 8466 section 4.3.2.
   *
   * Data type according to RFC:
   *   opaque certificate_request_context<0..2^8-1>;
   *
   * Data type opaque and variable length vector:
   *  <length><value>
   *    <length>: 1 Byte -> 0..255 Bytes in the vector
   *    <value>: <length> number of bytes
   *
   * Limitations:
   *  - post-handshake authentication not supported
   */

  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  const TcpIp_TlsBufferMgmtIterType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  const TcpIp_TlsBufferRxServerCertificateRequestIdxOfTlsClientBufferMgmtType serverCertRequestStartIdx
    = TcpIp_GetTlsBufferRxServerCertificateRequestIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  const TcpIp_ServerCertificateRequestLenOfTlsClientBufferMgmtType serverCertRequestLen
    = TcpIp_GetServerCertificateRequestLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  const TcpIp_TlsBufferRxServerCertificateRequestIdxOfTlsClientBufferMgmtType serverCertRequestEndIdx
    = (serverCertRequestStartIdx + TCPIP_TLS_HSHDRLEN + serverCertRequestLen);

  const TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType requestCtxTlsBufferRxIdx
    = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  /* minimum expected length contained in certificate request message */
  const TcpIp_TlsBufferRxIterType certReqCtxExpectedLength
    = TCPIP_TLS_CERT_REQUEST_CONTEXT_LEN_LEN;

  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the minimum expected length of received certificate_request_context */
  if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(requestCtxTlsBufferRxIdx, certReqCtxExpectedLength, serverCertRequestEndIdx))
  {
    /* #20 Read length information */
    const uint8 ctxLen = IpBase_GetUint8(TcpIp_GetAddrTlsBufferRx(requestCtxTlsBufferRxIdx), 0u);
    TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_CERT_REQUEST_CONTEXT_LEN_LEN);

    /* According to RFC 8446 section 4.3.2.
     * This field SHALL be zero length unless used for the post-handshake authentication
     */
    /* #30 Ensure that the field is zero length */
    if (ctxLen != 0u)
    {
      /* #40 No: Raise alert that parameter is illegal and can not be decoded */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_ILLEGAL_PARAM);
    }
    else
    {
      retVal = E_OK;
    }
  }
  /* #50 Otherwise raise an alert */
  else
  {
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
  }

  return retVal;
} /* TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestCertificateRequestContext() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestExtensions
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* Implements the parsing of extensions which is part
   * of a CertificateRequest message according to RFC 8466 section 4.3.2.
   *
   * Data type according to RFC:
   *   Extension extensions<2..2^16-1>;
   *
   */

  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  const TcpIp_TlsBufferMgmtIterType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  const TcpIp_TlsBufferRxServerCertificateRequestIdxOfTlsClientBufferMgmtType serverCertRequestStartIdx
    = TcpIp_GetTlsBufferRxServerCertificateRequestIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  const TcpIp_ServerCertificateRequestLenOfTlsClientBufferMgmtType serverCertRequestLen
    = TcpIp_GetServerCertificateRequestLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  const TcpIp_TlsBufferRxServerCertificateRequestIdxOfTlsClientBufferMgmtType serverCertRequestEndIdx
    = (serverCertRequestStartIdx + TCPIP_TLS_HSHDRLEN + serverCertRequestLen);

  const TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType extStartTlsBufferRxIdx
    = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  /* minimum expected length contained in certificate request message */
  const TcpIp_TlsBufferRxIterType certReqMinimalLength
    = (TCPIP_TLS_EXTENSION_LENGTH_LEN + TCPIP_TLS_CERTREQUEST_EXTENSIONS_MIN_DATA_LEN);

  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Extract information if expected minimum length of the received extensions element is valid */
  if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(extStartTlsBufferRxIdx, certReqMinimalLength, serverCertRequestEndIdx))
  {
    TcpIp_TlsBufferRxIterType remainingLen = 0u;
    TcpIp_TlsBufferRxIterType currentReadIdx = 0u;

    /* Extensions */
    const uint16 extensionsLen = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(extStartTlsBufferRxIdx), 0u);
    TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_LENGTH_LEN);

    currentReadIdx = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
    remainingLen = serverCertRequestEndIdx - currentReadIdx;

    /* #20 If extension length information is plausible forward to extensions entries parser */
    if (remainingLen < extensionsLen)
    {
      /* No: Error, incomplete extensions. Length bigger than amount of data present - raise alert */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
    }
    else
    {
      retVal = TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestExtensionsEntries(TlsConIdx, extensionsLen);
    }
  }
  /* #30 Otherwise raise an alert */
  else
  {
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
  }

  return retVal;
} /* TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestExtensions() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestExtensionsEntries
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestExtensionsEntries(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 ExtensionsLen)
{
  /* Implements the parsing of single entries of an extension list which is part
   * of a CertificateRequest message according to RFC 8466 section 4.3.2.
   *
   */

  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsExtensionType listOfReceivedExtensions[TCPIP_TLS_MAX_EXTENSION_LIST_LENGTH] = { 0 };
  uint8 listOfReceivedExtensionsCnt = TCPIP_TLS_MAX_EXTENSION_LIST_LENGTH;

  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Parse the available extensions */
  retVal = TcpIp_Tls13ClientMsg_ParseExtensions(
              TlsConIdx, ExtensionsLen,
              &listOfReceivedExtensions[0], &listOfReceivedExtensionsCnt);

  /* #20 If parsing was successful then check for duplicate extension entries */
  if (retVal == E_OK)
  {
    retVal = TcpIp_TlsMsg_CheckDuplicatedReceivedExtensions(
                &listOfReceivedExtensions[0], listOfReceivedExtensionsCnt);
  }

  /* #30 If further parsing was successful then process received extension */
  if (retVal == E_OK)
  {
    retVal = TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestProcessExtensions(
                TlsConIdx,
                &listOfReceivedExtensions[0], listOfReceivedExtensionsCnt);
  }

  /* #40 If parsing failed then raise alert for decoding error */
  if (retVal != E_OK)
  {
    /* This is just the default alert in case none other is raised before */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
  }

  return retVal;
} /* TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestExtensionsEntries() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestProcessExtensions
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
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestProcessExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(TcpIp_TlsExtensionType) ExtensionsPtr,
  uint8 ExtensionsPtrCnt)
{
  /* Implements the processing/dispatching of extensions received as part
   * of a CertificateRequest message according to RFC 8466 section 4.3.2.
   *
   * - The "signature_algorithms" extension MUST be specified
   * - Clients MUST ignore unrecognized extensions.
   */

  /* ----- Local Variables ---------------------------------------------- */
  boolean signatureAlgoFound = FALSE;
  uint8_least extEntryIdx = 0u;

  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */

  /* #10 For each available extension */
  for (extEntryIdx = 0u; extEntryIdx < (uint8_least)ExtensionsPtrCnt; extEntryIdx++)
  {
    TCPIP_P2C(TcpIp_TlsExtensionType) currentEntryPtr = &ExtensionsPtr[extEntryIdx];

    switch (currentEntryPtr->Type)
    {
      /* #20 If current extension is signature_algorithms then parse signature_algorithms extension */
      case TCPIP_TLS_EXTENSION_TYPE_SIGNATURE_ALGORITHMS:
      {
        signatureAlgoFound = TRUE;
        retVal = TcpIp_Tls13ClientHsStm_ParseCertificateRequestExtensionsSignatureAlgorithms(
                    TlsConIdx, currentEntryPtr);
        break;
      }
      /* #30 If current extension is certificate_authorities then parse certificate_authorities extension */
      case TCPIP_TLS_EXTENSION_TYPE_CERTIFICATE_AUTHORITIES:
      {
        retVal = TcpIp_Tls13ClientHsStm_ParseCertificateRequestExtensionsCertificateAuthorities(
                    TlsConIdx, currentEntryPtr);
        break;
      }
      /* #40 If current extension is signature_algorithms_cert then parse signature_algorithms_cert extension */
      case TCPIP_TLS_EXTENSION_TYPE_SIGNATURE_ALGORITHMS_CERT:
      {
        retVal = TcpIp_Tls13ClientHsStm_ParseCertificateRequestExtensionsSignatureAlgorithmsCert(
                    TlsConIdx, currentEntryPtr);
        break;
      }

      /* #50 Otherwise: Ignore other extensions */
      default:
      {
        retVal = E_OK;
        break;
      }
    }

    /* #60 Stop parsing in case of error */
    if (retVal != E_OK)
    {
      break;
    }
  }

  /* #70 Check if mandatory signature_algorithms extension is present */
  if (signatureAlgoFound == FALSE)
  {
    /* #80 No: Indicate error and raise missing_extension alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_MISSING_EXT);
    retVal = E_NOT_OK;
  }

  return retVal;
} /* TcpIp_Tls13ClientHsStm_ParseServerCertificateRequestProcessExtensions() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseCertificateRequestExtensionsSignatureAlgorithms
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseCertificateRequestExtensionsSignatureAlgorithms(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(TcpIp_TlsExtensionType) ExtensionPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  TcpIp_ConstSegmentType signatureAlgorithmsSegment = { 0 };

  uint16 signatureAlgorithmsLength = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* Implements the parsing of the signature_algorithms extension
   * of a CertificateRequest message according to RFC 8466 section 4.3.2. */
  /* #10 Restrict read segment for signature algorithms */
  TcpIp_ConstSegmentInit(
    &signatureAlgorithmsSegment,
    TcpIp_GetAddrTlsBufferRx(0),
    TcpIp_GetTlsBufferRxAdHsEndIdxOfTlsBufferMgmt(TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx)));

  TcpIp_ConstSegmentCommit(
    &signatureAlgorithmsSegment,
    (uint32) ExtensionPtr->StartIdx);

  TcpIp_ConstSegmentClear(&signatureAlgorithmsSegment);

  /* #20 Read length of signature algorithms list and check value */
  TcpIp_GetUint16FromConstSegment(&signatureAlgorithmsSegment, &signatureAlgorithmsLength);
  retVal = TcpIp_TlsClient_CheckSignatureAlgorithmsLengthConstraints(signatureAlgorithmsLength);

  /* #30 Check consistency of signatureAlgorithmsLength */
  if (retVal == E_OK)
  {
    retVal = TcpIp_Tls13ClientMsg_ServerCertRequestMsgCheckSignatureAlgorithmsLengthConsistency(
      ExtensionPtr,
      signatureAlgorithmsLength);
  }

  /* #40 Copy signature algorithms, if client authentication is enabled */
  if (retVal == E_OK)
  {
    if (TcpIp_IsTlsUseClientAuthenticationRequestOfTlsConnection(TlsConIdx))
    {
      /* #50 Copy signature algorithms into dedicated buffer */
      TcpIp_TlsClient_SaveSignatureAlgorithmsInRequestInfoOfTlsClientAuthentication(
        TlsConIdx,
        signatureAlgorithmsLength,
        &signatureAlgorithmsSegment);
    }
  }
  else
  {
    /* Invalid format, send decode_error alert. */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
  }

  return retVal;
} /* TcpIp_Tls13ClientHsStm_ParseCertificateRequestExtensionsSignatureAlgorithms() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseCertificateRequestExtensionsSignatureAlgorithmsCert
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseCertificateRequestExtensionsSignatureAlgorithmsCert(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(TcpIp_TlsExtensionType) ExtensionPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* Implements the parsing of the signature_algorithms_cert extension
   * of a CertificateRequest message according to RFC 8466 section 4.3.2. */

  /* #10 Reset certificate request info since signature_algorithms_cert is the preferred extension. */
  /* This enables overwriting the saved information of a possibly received signature_algorithms extension. */
  const TcpIp_RequestInfoOfTlsClientAuthenticationMgmtPtrType certRequestInfoPtr =
    TcpIp_GetAddrRequestInfoOfTlsClientAuthenticationMgmt(
      TcpIp_GetTlsClientAuthenticationMgmtIdxOfTlsConnection(TlsConIdx));

  certRequestInfoPtr->SignatureAndHashAlgoListPtr = (TCPIP_P2C(uint16))NULL_PTR;
  certRequestInfoPtr->SignatureAndHashAlgoNum = 0u;

  /* #20 Call procedure for extension signature_algorithms. */
  /* The signature_algorithms_cert extension is constructed identically to the signature_algorithms extension.
   * That's why its parsing function can also be used here. */
  return TcpIp_Tls13ClientHsStm_ParseCertificateRequestExtensionsSignatureAlgorithms(TlsConIdx, ExtensionPtr);
} /* TcpIp_Tls13ClientHsStm_ParseCertificateRequestExtensionsSignatureAlgorithmsCert() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseCertificateRequestExtensionsCertificateAuthorities
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseCertificateRequestExtensionsCertificateAuthorities(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(TcpIp_TlsExtensionType) ExtensionPtr)
{
  /* Implements the parsing of the certificate_authorities extension
   * of a CertificateRequest message according to RFC 8466 section 4.3.2.
   *
   * Data type of Extension according to RFC 8446 section 4.2.4:
   *  opaque DistinguishedName<1..2^16-1>;
   *
   *  struct {
   *      DistinguishedName authorities<3..2^16-1>;
   *  } CertificateAuthoritiesExtension;
   */

  /* ----- Local Variables ---------------------------------------------- */
  /* minimum expected length contained in CertificateRequest message */
  const uint8 caMinLen = TCPIP_TLS_EXTENSION_CERTIFICATE_AUTHORITIES_LENGTH
                          + TCPIP_TLS_EXTENSION_CERTIFICATE_AUTHORITIES_MIN_DATA_LEN;

  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Assert that the minimum required length is available in passed extension */
  if (ExtensionPtr->Length >= (TcpIp_TlsBufferRxIterType)caMinLen)
  {
    /* #20 Read length of authorities vector */
    const uint16 caDataLen = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(ExtensionPtr->StartIdx), 0u);

    /* #30 Check if authorities contains at least the minimum required number of bytes */
    if (caDataLen < TCPIP_TLS_EXTENSION_CERTIFICATE_AUTHORITIES_MIN_DATA_LEN)
    {
      /* #40 No: Error, invalid length information. Extension does not have minimum required amount of bytes - raise alert */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
    }
    /* #50 Check if authorities length is plausible */
    else if (caDataLen != (ExtensionPtr->Length - TCPIP_TLS_EXTENSION_CERTIFICATE_AUTHORITIES_LENGTH))
    {
      /* #60 No: Error, invalid length information. Extension does not consume complete amount of data. Element is smaller or bigger than this extension - raise alert */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
    }
    /* #70 Otherwise */
    else
    {
      /* #80 Format is OK */
      /* #90 Check if client authentication is enabled */
      if (TcpIp_IsTlsUseClientAuthenticationRequestOfTlsConnection(TlsConIdx))
      {
        /* #100 Yes: Analyze the distinguished names and update the info pointer */
        const TcpIp_TlsBufferRxIterType caDataStartTlsBufferRxIdx
          = ExtensionPtr->StartIdx + TCPIP_TLS_EXTENSION_CERTIFICATE_AUTHORITIES_LENGTH;

        retVal = TcpIp_TlsClient_ServerCertRequestMsgFindDistinguishedNameStarts(
                    TlsConIdx, caDataLen, TcpIp_GetAddrTlsBufferRx(caDataStartTlsBufferRxIdx));
      }
      else
      {
        retVal = E_OK;
      }
    }
  }

  /* #110 Check if an error occurred */
  if (retVal != E_OK)
  {
    /* #120 Report error and raise alert as some decode error occurred. */
    /* This is the default alert in case nothing more specific was reported before. */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
  }

  return retVal;
} /* TcpIp_Tls13ClientHsStm_ParseCertificateRequestExtensionsCertificateAuthorities() */
#   endif

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_CalculateFinishedVerifyData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_CalculateFinishedVerifyData(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_CsmJobIdType csmJobIdMacGenerate = TCPIP_TLS_CSM_INV_JOB_ID;

  uint8 hashLength = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the needed information for the calculation from the used cipher suite. */
  Std_ReturnType retVal
    = TcpIp_Tls13Client_GetCalcFinishedInfoFromActiveCipher(TlsConIdx, &csmJobIdMacGenerate, &hashLength);
  /* #20 Calculate the verifyData */
  if (retVal == E_OK)
  {
    retVal = TcpIp_Tls13Client_CalculateVerifyData(TlsConIdx, csmJobIdMacGenerate, hashLength);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_CalculateVerifyData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_CalculateVerifyData(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_CsmJobIdType          MacGenerateCsmJobId,
  uint8                       HashLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  TCPIP_P2C(uint8) transcriptHashPtr = TcpIp_GetAddrTlsTemporaryHashBuffer(
    TcpIp_GetTlsTemporaryHashBufferStartIdxOfTlsConnection(TlsConIdx));

  TCPIP_P2V(uint8) hsHashDestPtr = TcpIp_GetAddrTlsTemporaryHashBuffer(
    TcpIp_GetTlsTemporaryHashBufferStartIdxOfTlsConnection(TlsConIdx));

  uint32 hsHashDestSpace = TcpIp_GetTlsTemporaryHashBufferEndIdxOfTlsConnection(TlsConIdx)
    - (uint32)TcpIp_GetTlsTemporaryHashBufferStartIdxOfTlsConnection(TlsConIdx);

  TcpIp_SegmentType hsHashSegmentPtr = { 0 };

  /* ----- Implementation ----------------------------------------------- */

  /* Calculate the verifyData (cf. RFC 8446, 4.4.4.  Finished).
     verify_data =
          HMAC(finished_key,
               Transcript-Hash(Handshake Context,
                               Certificate*, CertificateVerify*)) */

  /* #10 Calculate the FinishedKey and the Transcript-Hash. */
  retVal = TcpIp_Tls13Client_CalculateMacGenerateKey(TlsConIdx, MacGenerateCsmJobId, HashLength);

  if (retVal == E_OK)
  {
    TcpIp_SegmentInit(&hsHashSegmentPtr, hsHashDestPtr, hsHashDestSpace);

    retVal = TcpIp_Tls13Client_CalculateHashOfHsMessages(TlsConIdx, HashLength, &hsHashSegmentPtr);
  }

  /* #20 Calculate and save the verifyData. */
  if (retVal == E_OK)
  {
    TCPIP_P2V(uint8) verifyDataPtr = TcpIp_GetAddrTlsTemporaryHmacBuffer(
      TcpIp_GetTlsTemporaryHmacBufferStartIdxOfTlsConnection(TlsConIdx));

    /* Initialize the verifyData length with the size of the available buffer. */
    uint32 verifyDataLen = (uint32)TcpIp_GetTlsTemporaryHmacBufferEndIdxOfTlsConnection(TlsConIdx)
      - TcpIp_GetTlsTemporaryHmacBufferStartIdxOfTlsConnection(TlsConIdx);

    retVal = E_NOT_OK;

    /* Calculate the HMAC which is the verifyData. */
    if (TCPIP_CSM_MacGenerate(MacGenerateCsmJobId, CRYPTO_OPERATIONMODE_SINGLECALL,
          transcriptHashPtr, HashLength, verifyDataPtr, &verifyDataLen) == E_OK)
    {
      retVal = E_OK;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_CalculateFinishedKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_CalculateFinishedKey(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_CsmJobIdType csmJobIdMacGenerate = TCPIP_TLS_CSM_INV_JOB_ID;

  uint8 hashLength = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the needed information for the calculation from the used cipher suite. */
  Std_ReturnType retVal
    = TcpIp_Tls13Client_GetCalcFinishedInfoFromActiveCipher(TlsConIdx, &csmJobIdMacGenerate, &hashLength);
  /* #20 Calculate the finished key */
  if (retVal == E_OK)
  {
    /* We can use the calculation for a mac generate key. */
    retVal = TcpIp_Tls13Client_CalculateMacGenerateKey(TlsConIdx, csmJobIdMacGenerate, hashLength);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_CalculateMacGenerateKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_CalculateMacGenerateKey(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_CsmJobIdType          MacGenerateCsmJobId,
  uint8                       HashLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx =
    TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx);

  TcpIp_CsmKeyIdType baseKeyId = TCPIP_TLS_CSM_INV_KEY_ID;

  TcpIp_CsmKeyIdType macGenerateCsmKeyId
    = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob((TcpIp_TlsCsmJobIterType)MacGenerateCsmJobId);

  TcpIp_Tls13_HkdfExpandInput_Type hkdfExpandInput = { 0 };

  TcpIp_TlsHandshakeState state = TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the BaseKey depending on the current handshake state. */
  /* The FinishedKey for the Client Finished is also calculated in a state after the ServerFinished was received.
   * Therefore when the Client Finished shall be send,
   * the key does not need to be calculated when we enter this function. Instead simply return E_OK. */
  if (state == TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_TRIGGER_TX)
  {
    retVal = E_OK;
  }

  if (state == TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_WAIT_FOR_ASYNC_FINISHED_KEY)
  {
    /* The ClientFinished is sent, therefore the BaseKey is the ClientSecret. */
    baseKeyId = TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfClientAdHsTrafficSecretIdxOfTlsHandshake(activeTlsHandshakeIdx));
    hkdfExpandInput.TempExpandOutKeyId = TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdTemporaryHkdfExpandOutKeyIdxOfTlsHandshake(activeTlsHandshakeIdx));
    hkdfExpandInput.HkdfExpandJobId = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfExpandIdxOfTlsHandshake(activeTlsHandshakeIdx));
  }

  if (state == TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_VERIFY)
  {
    /* The ServerFinished is received, therefore the BaseKey is the ServerSecret. */
    baseKeyId = TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfServerAdHsTrafficSecretIdxOfTlsHandshake(activeTlsHandshakeIdx));
    hkdfExpandInput.TempExpandOutKeyId = TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdTemporaryHkdfExpandOutKeyIdxOfTlsHandshake(activeTlsHandshakeIdx));
    hkdfExpandInput.HkdfExpandJobId = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfExpandIdxOfTlsHandshake(activeTlsHandshakeIdx));
  }

  if (state == TCPIP_TLS_STATE_SEND_CLIENT_HELLO_PSK_KEY_WAIT_FOR_ASYNC)
  {
    /* The PskBinderEntry shall be calculated, therefore the BaseKey is the binder key. */
    /* In TcpIp_Tls13CoreCtx_DerivePskBinderKey() the binder key
     * was saved in the referenced key of the Csm Hkdf job. */
    TcpIp_Tls13PskIdentityActiveIdxOfTlsConnectionDynType activeTls13PskIdentityIdx
      = TcpIp_GetTls13PskIdentityActiveIdxOfTlsConnectionDyn(TlsConIdx);
    baseKeyId
      = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(TcpIp_GetPskHkdfCsmJobIdOfTls13PskIdentity(activeTls13PskIdentityIdx));
    hkdfExpandInput.TempExpandOutKeyId = TcpIp_GetPskTemporaryCsmKeyIdOfTls13PskIdentity(activeTls13PskIdentityIdx);
    hkdfExpandInput.HkdfExpandJobId = TcpIp_GetPskHkdfExpandCsmJobIdOfTls13PskIdentity(activeTls13PskIdentityIdx);
  }

  /* #20 Trigger key expansion if the base key is valid */
  if (baseKeyId != TCPIP_TLS_CSM_INV_KEY_ID)
  {
    /* Key valid - forward to internal API */
    /* Calculate the FinishedKey (cf. RFC 8446, 4.4.4.  Finished). */
    /* finished_key = HKDF-Expand-Label(BaseKey, "finished", "", Hash.length) */

    /* set general parameters */
    hkdfExpandInput.InputKeyId = baseKeyId;
    hkdfExpandInput.TargetKeyId = macGenerateCsmKeyId;
    hkdfExpandInput.TargetKeyElementId = CRYPTO_KE_MAC_KEY;
    /* The finished key length shall be equal to the hash length. */
    hkdfExpandInput.TargetKeyElementLen = (uint16) HashLength;
    hkdfExpandInput.HkdfHashLen = HashLength;

    retVal = TcpIp_Tls13CoreCtx_HkdfExpandLabel(
      &hkdfExpandInput,
      &TcpIp_Tls_Hs_Tls13Label_Finished[0],
      TcpIp_Tls_Hs_Tls13Label_Finished_Len,
      NULL_PTR,
      0u);

  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_GetCalcFinishedInfoFromActiveCipher
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_GetCalcFinishedInfoFromActiveCipher(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TCPIP_P2V(TcpIp_CsmJobIdType) MacGenerateCsmJobIdPtr,
  TCPIP_P2V(uint8)              HashLengthPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx =
    TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  /* #10 Determine the Mac generate job Id */
  TcpIp_CsmJobIdType csmJobIdMacGenerate
    = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHmacGenerateIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));

  uint8 hashLength = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Determine the hash length depending on the used cipher suite. */
  Std_ReturnType retVal = TcpIp_Tls13Core_GetHashLengthOfActiveCipherSuite(TlsConIdx, &hashLength);
  if (retVal == E_OK)
  {
    *HashLengthPtr = hashLength;
    *MacGenerateCsmJobIdPtr = csmJobIdMacGenerate;
  }
  else
  {
    /* Trigger alert internal_error in case the hash length can not be found. */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
  }

  return retVal;
}

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13ClientCtx_ValidateCertificateStatus
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
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientCtx_ValidateCertificateStatus(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx
    = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

  const TcpIp_TlsClientOcspBufferMgmtCurrentIdxOfTlsConnectionDynType curTlsClientOcspBufferMgmtIdx =
    TcpIp_GetTlsClientOcspBufferMgmtCurrentIdxOfTlsConnectionDyn(TlsConIdx);

  const uint32 ocspResponseLength
    = TcpIp_GetServerCertStatusResponseLenOfTlsClientOcspBufferMgmt(curTlsClientOcspBufferMgmtIdx);

  const TcpIp_TlsBufferRxIterType ocspResponseStartTlsBufferRxIdx
    = TcpIp_GetTlsBufferRxServerCertStatusResponseIdxOfTlsClientOcspBufferMgmt(curTlsClientOcspBufferMgmtIdx);


  TcpIp_TlsUserErrorIdType internalErrorId = TCPIP_TLS_ERRORID_NOT_SET;

  Std_ReturnType retValKeyM = E_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* Process the OCSP response in case one was received for the current certificate */
  if (ocspResponseLength != 0u)
  {
    /* Use the currentIdx of the cert status to be handled */
    const TcpIp_TlsCertValidationStatusDynCurrentIdxOfTlsConnectionDynType curTlsCertValidationStatusIdx
      = TcpIp_GetTlsCertValidationStatusDynCurrentIdxOfTlsConnectionDyn(TlsConIdx);

    TCPIP_CP2V(TcpIp_CertValidationStatusType) currentCertStatusPtr
      = TcpIp_GetAddrTlsCertValidationStatusDyn(curTlsCertValidationStatusIdx);

    KeyM_CertificateStatusType leafCertStatus = { 0 };

    /* Setup default value, will be overwritten once result is available */
    currentCertStatusPtr->CertStatusResponse.OcspResponseStatus = TCPIP_TLS_OCSP_RESPONSE_STATUS_INVALID;

    /* #10 Get the status of the received leaf server certificate */
    if (KeyM_CertGetStatus(currentCertStatusPtr->CertId, &leafCertStatus) == E_OK)
    {
      /* KeyM API needs a certificate name, which is not used within the API. Use some dummy value to satisfy API */
      CONST(uint8, AUTOMATIC) defaultName[2] = { "D" };
      const uint32 defaultNameLength = sizeof(defaultName) - 1u;
      /* Pointer to the received OCSP response within the TLS RxBuffer */
      TCPIP_P2C(uint8) ocspResponsePtr = TcpIp_GetAddrTlsBufferRx(ocspResponseStartTlsBufferRxIdx);

      /* #20 Process the received OCSP response */
      /* It is checked in TcpIp_TlsClientMsg_CheckValidateCertificateStatusPrecondition()
       * that TcpIp_GetKeyMServiceCertificateFuncOfTlsConfig() is not a NULL_PTR. */
      TcpIp_TlsKeyMServiceCertificateFunctionType serviceCertificateFunc
        = TcpIp_GetKeyMServiceCertificateFuncOfTlsConfig(TCPIP_TLSCONFIG_IDX);

      retValKeyM = serviceCertificateFunc(KEYM_SERVICE_CERT_STATUS_OCSP,
        &defaultName[0], defaultNameLength,
        ocspResponsePtr, ocspResponseLength,
        &currentCertStatusPtr->CertStatusResponse.OcspResponseStatus,
        sizeof(TcpIp_CertificateStatusResponseType));

      if (retValKeyM == KEYM_E_BUSY)
      {
        /* Nothing to do, just wait */
      }
      else if (retValKeyM != E_OK)
      {
        /* #30 In case of any occurred error, update the error ID */
        /* Processing of OCSP response failed - KeyM call failed */
        currentCertStatusPtr->CertStatusResponse.OcspResponseStatus = TCPIP_TLS_OCSP_RESPONSE_STATUS_INVALID;
        internalErrorId = TCPIP_TLS_ERRORID_KEYM_SERVICE_OCSP_FAILED;
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_BAD_CERT_STATUS_RESP);
      }
      else
      {
        /* No error occurred */
      }
    }
    else
    {
      /* Get status of Leaf certificate failed - KeyM call failed */
      internalErrorId = TCPIP_TLS_ERRORID_KEYM_GETCERTIFICATESTATUS_FAILED;
    }
  }

  /* #40 Report an error to the user when the error ID is set */
  if (internalErrorId == TCPIP_TLS_ERRORID_NOT_SET)
  {
    if (retValKeyM == KEYM_E_BUSY)
    {
      /* Nothing to do, just wait */
    }
    else
    {
      /* #50 OCSP response successfully validated - reset the asynchronous status */
      TcpIp_SetCertificateStatusOcspValidationAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
      TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);
    }
  }
  else
  {
    /* Reset the processing trigger for the OCSP validation */
    TcpIp_SetCertificateStatusOcspValidationAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx, FALSE);

    TcpIp_TlsAsyncCtx_HandleErrorDuringAsyncJobProcessing(TlsConIdx,
      TCPIP_TLS_FCTID_CLIENT_ASYNCCTX_VALIDATE_CERT_STATUS, internalErrorId);
  }

} /* TcpIp_Tls13ClientCtx_ValidateCertificateStatus() */
#   endif

/**********************************************************************************************************************
 *   TLS CLIENT HANDSHAKE STATE MACHINE
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_PerformNextHsStep
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030, 6050 1 */ /* MD_MSR_STCYC, MD_TcpIp_TlsStatemachine_STCAL_6050 */
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_PerformNextHsStep(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Process the TLS-CLient Handshake depending on the current state */
  uint16 hsState = TCPIP_TLS_GET_HS_STATE(TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx));
  switch ((TcpIp_TlsHandshakeState)hsState)
  {
    case TCPIP_TLS_STATE_WAIT_FOR_ENCRYPTED_EXTENSIONS:
    {
      TcpIp_Tls13ClientHsStm_ParseEncryptedExtensions(TlsConIdx);
      break;
    }
    case TCPIP_TLS_STATE_WAIT_FOR_CERT_OR_CERT_REQUEST:
    {
      TcpIp_Tls13ClientHsStm_HandleWaitCertCR(TlsConIdx);
      break;
    }
#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
    case TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_REQUEST:
    {
      TcpIp_Tls13ClientHsStm_ParseServerCertificateRequest(TlsConIdx);
      break;
    }
    case TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE:
    {
      TcpIp_Tls13ClientHsStm_ParseServerCertificate(TlsConIdx);
      break;
    }
    case TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFY:
    {
      TcpIp_Tls13ClientHsStm_ParseServerCertificateVerify(TlsConIdx);
      break;
    }
#   endif
    case TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED:
    {
      TcpIp_Tls13ClientHsStm_ParseServerFinished(TlsConIdx);
      break;
    }
    case TCPIP_TLS_STATE_SEND_CLIENT_CCS:
    {
      TcpIp_Tls13ClientHsStm_SendClientDummyCcs(TlsConIdx);
      break;
    }
#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
    case TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE:
    {
      TcpIp_Tls13ClientHsStm_SendClientCertificate(TlsConIdx);
      break;
    }
    case TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY:
    {
      TcpIp_Tls13ClientHsStm_SendClientCertificateVerify(TlsConIdx);
      break;
    }
#   endif
    case TCPIP_TLS_STATE_SEND_CLIENT_FINISHED:
    {
      TcpIp_Tls13ClientHsStm_SendClientFinished(TlsConIdx);
      break;
    }

    case TCPIP_TLS_STATE_HANDSHAKE_FINALIZING:
    {
      TcpIp_Tls13ClientHsStm_FinalizeHandshake(TlsConIdx);
      break;
    }


    default:                                                                                                            /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
    {
      /* This case is only reached if the state is TCPIP_TLS_STATE_HANDSHAKE_ABORT or TCPIP_TLS_STATE_HANDSHAKE_DONE */
      break;
    }
  }
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseServerFinished
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseServerFinished(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Parse and verify the Server Finished message. */
  retVal = TcpIp_Tls13ClientHsStm_ParseAndProcessServerFinished(TlsConIdx);

  /* #20 Check the result of the ServerFinished parsing. */
  if (retVal == E_OK)
  {
    /* #30 Message successfully parsed - Check if there are async operation pending. */
    if (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_ASYNC_PENDING)
    {
      /* Async operation is pending. Nothing to do, just leave the function. */
    }
    else
    {
      const TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
        = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);
      const TcpIp_TlsBufferRxServerCertificateRequestIdxOfTlsClientBufferMgmtType serverCertificateRequestIdx
        = TcpIp_GetTlsBufferRxServerCertificateRequestIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

      /* Decrement the Hs Rx indication counter since the ServerFinished is processed. */
      TcpIp_DecHsRxIndicationCntOfTlsConnectionDyn(TlsConIdx);

      /* #40 Determine next TLS client state */
      if (TcpIp_IsMiddleboxCompatibilityModeOfTlsConnection(TlsConIdx) == TRUE)
      {
        /* The middlebox compatibility mode is enabled. The RFC8446 states in appendix D.4
         * that the client shall send a dummy change_cipher_spec record immediately before its second flight. */
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_CCS);
      }
      else
      {
        /* Compatibility mode is disabled,
         * set next state depending on the received messages (ClientCertificate or ClientFinished). */
        if (serverCertificateRequestIdx != TCPIP_NO_TLSBUFFERRXSERVERCERTIFICATEREQUESTIDXOFTLSCLIENTBUFFERMGMT)
        {
          /* TLS client received certificate request message - Next state is SendClientCertificate */
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE);
        }
        else
        {
          /* Proceed with sending the client finished message */
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_FINISHED);
        }
      }
      TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, TRUE);
    }
  }
  else
  {
    /* #50 Parsing failed. Cancel the handshake. */
    TcpIp_TlsHsStm_HandlesUnexpectedHsInformation(TlsConIdx);
  }
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ParseNewSessionTicket
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ParseNewSessionTicket(
  TcpIp_TlsConnectionIterType  TlsConIdx,
  uint32                       HsLen,
  TcpIp_ConstSegmentPtrType    SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType    SourceSegment2Ptr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsNewSessionTicketInfoType newSessionTicketInfo = { 0u };
  boolean rejectNewSessionTicket = FALSE;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* It was decided that the NewSessionTicket shall be parsed first, before checking and reserving a storage option.
   * This is because the NewSessionTicket might be invalid and otherwise we would already overwrite a possibly
   * valid ticket (with the least remaining lifetime).
   * That's why the information of the NewSessionTicket is temporarily stored in the newSessionTicketInfo struct
   * when parsing the message and only later stored in the CSL. */
  /* #10 Extract NewSessionTicket information */
  if (TcpIp_Tls13ClientMsg_ExtractNewSessionTicketInformation(TlsConIdx, HsLen, SourceSegment1Ptr, SourceSegment2Ptr,
        &newSessionTicketInfo, &rejectNewSessionTicket) == E_OK)
  {
    /* To ignore the NewSessionTicket because of an early_data extension or because it can't be stored is a valid case.
     * No alert shall be send and E_OK shall be returned. */
    retVal = E_OK;
    if (rejectNewSessionTicket == FALSE)
    {
      /* #20 Check if NewSessionTicket can be stored and lifetime is bigger than the remaining lifetime of the PSK identity. */
      TcpIp_Tls13PskIdentityIterType pskIdentityIdx = 0u;
      if (   (TcpIp_Tls13Client_FindPskForSessionTicketStorage(TlsConIdx, &pskIdentityIdx) == E_OK)
          && (TcpIp_Tls13Client_IsTicketLifetimeBiggerThanPskRemainingLifetime(&newSessionTicketInfo, pskIdentityIdx)
              == TRUE))
      {
        /* #30 Proceed with saving extracted information from NewSessionTicket if storage option could be found. */
        retVal = TcpIp_Tls13Client_StoreNewSessionTicketInformation(TlsConIdx, pskIdentityIdx, &newSessionTicketInfo);
        if (retVal == E_OK)
        {
          /* #40 Issue session ticket update callout. */
          TcpIp_Tls13Client_SessionTicketUpdateCallout(TlsConIdx);
        }
        else
        {
          /* Not able to store the NewSessionTicket information even though a storage option was found.
           * This should never happen. */
          TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
        }
      } /* else - No ticket found where info can be stored, or new ticket lifetime is shorter than PSK identity lifetime. Ignore the message */
    } /* else - received an undesirable early_data extension in a valid NewSessionTicket message, ignore the message */
  }
  else
  {
    /* Received manipulated NewSessionTicket, send an alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
  }
  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ExtractNewSessionTicketInformation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ExtractNewSessionTicketInformation(
  TcpIp_TlsConnectionIterType                   TlsConIdx,
  uint32                                        HsLen,
  TcpIp_ConstSegmentPtrType                     SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                     SourceSegment2Ptr,
  TCPIP_P2V(TcpIp_TlsNewSessionTicketInfoType)  NewSessionTicketInfoPtr,
  TCPIP_P2V(boolean)                            RejectNewSessionTicketPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* Save the usage in the segments before the NewSessionTicket is parsed. */
  uint64 usedDataLengthInSegments = (uint64)SourceSegment1Ptr->Usage + (uint64)SourceSegment2Ptr->Usage;
  *RejectNewSessionTicketPtr = FALSE; /* Normally the NewSessionTicket shall not be rejected. */

  /* ----- Implementation ----------------------------------------------- */
  /* For this function it is required that the NewSessionTicket was received completely,
   * meaning that the full HS header is in the Rx AdHs buffer and afterwards there are at least as many bytes
   * as the HS length suggests. The data in the Rx buffer is passed as two const buffer segments.
   * Only in a wraparound case both segments are filled with data.
   * We do not check for a wraparound in this function but read each field of the message out of the two segments.
   * If the first segments does not contain any more data, reading is continued at the second segment.
   * The subfunctions will return E_NOT_OK if both segments do not contain enough data to read the field.
   * In this case a manipulated NewSessionTicket was received and a decode_error alert will be send in the
   * upper hierarchical function TcpIp_Tls13ClientMsg_ParseNewSessionTicket(). */

  /* The HS header was already parsed in TcpIp_TlsCoreRl_ScanForHsTypesAndTriggerHsMsgProcess(). */

  /* #10 Parse the different fields of the NewSessionTicket and save the information. */
  Std_ReturnType retVal = TcpIp_Tls13ClientMsg_ExtractTicketInformationFromNewSessionTicket(TlsConIdx,
    SourceSegment1Ptr, SourceSegment2Ptr, NewSessionTicketInfoPtr, RejectNewSessionTicketPtr);

  if (retVal == E_OK)
  {
    retVal = TcpIp_Tls13ClientMsg_ExtractNonceInformationFromNewSessionTicket(SourceSegment1Ptr,
      SourceSegment2Ptr, NewSessionTicketInfoPtr);
  }

  if (retVal == E_OK)
  {
    retVal = TcpIp_Tls13ClientMsg_ExtractIdentityInformationFromNewSessionTicket(SourceSegment1Ptr,
      SourceSegment2Ptr, NewSessionTicketInfoPtr, RejectNewSessionTicketPtr);
  }

  if (retVal == E_OK)
  {
    retVal = TcpIp_Tls13ClientMsg_ExtractExtensionsInformationFromNewSessionTicket(SourceSegment1Ptr,
      SourceSegment2Ptr, RejectNewSessionTicketPtr);
  }

  if (retVal == E_OK)
  {
    /* The usage of const segments can only be increased. Therefore no possibility for an underflow here. */
    uint64 consumedData
      = (uint64)SourceSegment1Ptr->Usage + (uint64)SourceSegment2Ptr->Usage - usedDataLengthInSegments;
    /* #20 Check that all data is consumed */
    if (consumedData != (uint64) HsLen)
    {
      retVal = E_NOT_OK;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ExtractTicketInformationFromNewSessionTicket
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ExtractTicketInformationFromNewSessionTicket(
  TcpIp_TlsConnectionIterType                   TlsConIdx,
  TcpIp_ConstSegmentPtrType                     SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                     SourceSegment2Ptr,
  TCPIP_P2V(TcpIp_TlsNewSessionTicketInfoType)  NewSessionTicketInfoPtr,
  TCPIP_P2V(boolean)                            RejectNewSessionTicketPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Read and save the value of the max ticket age field. */
  /* TcpIp_GetUint32FromMultiConstSegment() returns E_NOT_OK if the source segments do not contain enough data.
   * This is the case if a manipulated NewSessionTicket was received. */
  Std_ReturnType retVal = TcpIp_GetUint32FromMultiConstSegment(SourceSegment1Ptr, SourceSegment2Ptr,
    &NewSessionTicketInfoPtr->LifetimeSec);

  if (retVal == E_OK)
  {
    /* #20 Check if the lifetime is in the configured range. */
    uint32 ticketLifetimeSec = NewSessionTicketInfoPtr->LifetimeSec;
    if (   (ticketLifetimeSec > TcpIp_GetMaxTicketLifetimeOfTlsConfig(TCPIP_TLSCONFIG_IDX))
        || (ticketLifetimeSec < TcpIp_GetMinTicketLifetimeOfTlsConfig(TCPIP_TLSCONFIG_IDX)))
    {
      /* Lifetime is not in configured range, reject the NewSessionTicket but do not close the connection. */
      /* Don't stop parsing yet. If we detect an invalid length, we must send an alert. */
      *RejectNewSessionTicketPtr = TRUE;
    }
    else
    {
      /* Lifetime is in the configured range. */
      /* #30 Check if ticket lifetime has to be shortened to fulfill the MaxAcceptanceTicketTime limit. */
      TcpIp_TlsClientConnectionIdxOfTlsConnectionType tlsClientConnectionIdx
        = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);
      uint64 resumptionBaseConnectionAgeSec
        = TcpIp_GetResumptionBaseConnectionAgeOfTlsClientConnection(tlsClientConnectionIdx)
        / (uint64)(TCPIP_CYCLES_PER_SECOND);
      uint32 maxTicketAcceptanceTimeSec = TcpIp_GetMaxAcceptanceTicketTimeOfTlsConfig(TCPIP_TLSCONFIG_IDX);
      uint8 minRemainingTicketLifetimeSec = TcpIp_GetMinRemainingTicketLifetimeOfTlsConfig(TCPIP_TLSCONFIG_IDX);

      /* The variable resumptionBaseConnectionAgeSec will never overflow since it can handle some billion years. Adding
      the ticket lifetime (uint32) also won't cause an overflow. */
      if ((resumptionBaseConnectionAgeSec + ticketLifetimeSec) > maxTicketAcceptanceTimeSec)
      {
        /* The ticket lifetime exceeds the MaxAcceptanceTicketTime limit. */
        /* #40 Check if the resumption base connection is too old to accept any valid NewSessionTicket. */
        if ((resumptionBaseConnectionAgeSec + minRemainingTicketLifetimeSec) > maxTicketAcceptanceTimeSec)
        {
          /* Maximum ticket acceptance time reached, reject all new tickets. Also reject tickets that would only have a
          remaining lifetime of MinRemainingTicketLifetime. */
          *RejectNewSessionTicketPtr = TRUE;
        }
        else
        {
          /* Reduce the ticket lifetime to fulfill the overall MaxAcceptanceTicketTime limit. */
          /* resumptionBaseConnectionAgeSec can be mapped to uint32 since here it is smaller than
          maxTicketAcceptanceTimeSec. */
          NewSessionTicketInfoPtr->LifetimeSec = maxTicketAcceptanceTimeSec - (uint32)resumptionBaseConnectionAgeSec;
        }
      }
      else
      {
        /* The full ticket lifetime can be used since it won't exceed the MaxAcceptanceTicketTime limit. The lifetime
        can be stored as it is. */
      }
    }

    /* #50 Read and save the value of the ticket age add field. */
    retVal = TcpIp_GetUint32FromMultiConstSegment(SourceSegment1Ptr, SourceSegment2Ptr,
      &NewSessionTicketInfoPtr->AgeAddMs);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ExtractNonceInformationFromNewSessionTicket
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ExtractNonceInformationFromNewSessionTicket(
  TcpIp_ConstSegmentPtrType                     SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                     SourceSegment2Ptr,
  TCPIP_P2V(TcpIp_TlsNewSessionTicketInfoType)  NewSessionTicketInfoPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Read and save the nonce length */
  /* TcpIp_GetUint8FromMultiConstSegment() returns E_NOT_OK if the source segments do not contain enough data.
   * This is the case if a manipulated NewSessionTicket was received.*/
  Std_ReturnType retVal = TcpIp_GetUint8FromMultiConstSegment(SourceSegment1Ptr, SourceSegment2Ptr,
    &NewSessionTicketInfoPtr->NonceLen);

  if (retVal == E_OK)
  {
    /* #20 Check if the length is valid and save the address of the nonce in the Rx buffer. */
    /* If the NewSessionTicket message is valid and a fitting PSK identity is found
     * the nonce will be copied from the buffer. To facilitate this two (to handle a possible wraparound)
     * const buffer segments are created solely for the nonce. */
    retVal = TcpIp_MultiConstSegmentInitWithSkippedDataInMultiConstSegment(
      &NewSessionTicketInfoPtr->NonceBufferSegment1,
      &NewSessionTicketInfoPtr->NonceBufferSegment2,
      SourceSegment1Ptr,
      SourceSegment2Ptr,
      NewSessionTicketInfoPtr->NonceLen);
  }
  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ExtractIdentityInformationFromNewSessionTicket
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ExtractIdentityInformationFromNewSessionTicket(
  TcpIp_ConstSegmentPtrType                     SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                     SourceSegment2Ptr,
  TCPIP_P2V(TcpIp_TlsNewSessionTicketInfoType)  NewSessionTicketInfoPtr,
  TCPIP_P2V(boolean)                            RejectNewSessionTicketPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Read and save the identity length */
  /* TcpIp_GetUint16FromMultiConstSegment() returns E_NOT_OK if the source segments do not contain enough data.
   * This is the case if a manipulated NewSessionTicket was received.*/
  Std_ReturnType retVal = TcpIp_GetUint16FromMultiConstSegment(SourceSegment1Ptr, SourceSegment2Ptr,
    &NewSessionTicketInfoPtr->IdentityLen);

  /* #20 If the identity length is zero, an alert shall be sent. Set the return value to E_NOT_OK. */
  if (NewSessionTicketInfoPtr->IdentityLen == 0u)
  {
    retVal = E_NOT_OK;
  }

  if (retVal == E_OK)
  {
    if (NewSessionTicketInfoPtr->IdentityLen > TcpIp_GetMaxPskIdentityLenOfTlsConfig(TCPIP_TLSCONFIG_IDX))
    {
      /* Identity length can not be handled, reject the NewSessionTicket but do not close the connection. */
      /* Don't stop parsing yet. If we detect an invalid length, we must send an alert. */
      *RejectNewSessionTicketPtr = TRUE;
    }

    /* #30 Check if the length is valid and save the address of the identity in the Rx buffer. */
    /* If the NewSessionTicket message is valid and a fitting PSK identity is found
     * the identity will be copied from the buffer. To facilitate this two (to handle a possible wraparound)
     * const buffer segments are created solely for the identity. */
    retVal = TcpIp_MultiConstSegmentInitWithSkippedDataInMultiConstSegment(
      &NewSessionTicketInfoPtr->IdentityBufferSegment1,
      &NewSessionTicketInfoPtr->IdentityBufferSegment2,
      SourceSegment1Ptr,
      SourceSegment2Ptr,
      NewSessionTicketInfoPtr->IdentityLen);
  }
  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ExtractExtensionsInformationFromNewSessionTicket
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ExtractExtensionsInformationFromNewSessionTicket(
  TcpIp_ConstSegmentPtrType                   SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                   SourceSegment2Ptr,
  TCPIP_P2V(boolean)                          RejectNewSessionTicketPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 extensionsLen = 0u;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Read the extensions length */
  /* TcpIp_GetUint16FromMultiConstSegment() returns E_NOT_OK if the source segments do not contain enough data.
   * This is the case if a manipulated NewSessionTicket was received.
   * RFC8446 chapter 4.6.1 implies that the extensions length must be send even when no extensions are attached. */
  Std_ReturnType retVal = TcpIp_GetUint16FromMultiConstSegment(SourceSegment1Ptr, SourceSegment2Ptr, &extensionsLen);

  /* If the extensions length is zero, no more parsing necessary */
  if ((retVal == E_OK) && (extensionsLen > 0u))
  {
    uint32 lengthInSegment1 = 0u;
    uint32 lengthInSegment2 = 0u;
    /* TcpIp_GetSplitLengthInMultiConstSegment() checks that two segments contain
     * at least the amount of bytes specified in the extensions length field. */
    retVal = TcpIp_GetSplitLengthInMultiConstSegment(SourceSegment1Ptr, SourceSegment2Ptr, extensionsLen,
      &lengthInSegment1, &lengthInSegment2);

    /* Save the extension types to enable check for duplicated extension. */
    uint16 listOfExtensionTypes[TCPIP_TLS_MAX_EXTENSION_LIST_LENGTH] = { 0 };
    /* combinedUsageBeforeExtParsing is needed to check that the extensions length was correct
     * when we are done with extension parsing */
    uint64 combinedUsageBeforeExtParsing = (uint64)SourceSegment1Ptr->Usage + (uint64)SourceSegment2Ptr->Usage;
    uint8 extensionListIter = 0u;
    /* No underflow possible since usage of segments only increases */
    /* #20 Iterate over received extensions */
    while (   (((uint64)SourceSegment1Ptr->Usage + (uint64)SourceSegment2Ptr->Usage
                  - combinedUsageBeforeExtParsing) < (uint64)extensionsLen)
           /* Stop iterating when message is invalid */
           && (retVal == E_OK))
    {
      if (extensionListIter < TCPIP_TLS_MAX_EXTENSION_LIST_LENGTH)
      {
        /* #30 Process single extension, do length check and duplicate check but skip over content of the extension. */
        /* #40 Also check if early_data extension is present and if NewSessionTicket must be rejected because of it. */
        retVal = TcpIp_Tls13ClientMsg_ProcessSingleExtensionInformationFromNewSessionTicket(SourceSegment1Ptr,
          SourceSegment2Ptr, extensionListIter, RejectNewSessionTicketPtr, &listOfExtensionTypes[0]);
        extensionListIter++;
      }
      else
      {
        retVal = E_NOT_OK;
      }
    }

    if (retVal == E_OK)
    {
      /* #50 Check that extensions length was valid. */
      if (   ((uint64)SourceSegment1Ptr->Usage + (uint64)SourceSegment2Ptr->Usage - combinedUsageBeforeExtParsing)
          != (uint64)extensionsLen)
      {
        retVal = E_NOT_OK;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ProcessSingleExtensionInformationFromNewSessionTicket
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ProcessSingleExtensionInformationFromNewSessionTicket(
  TcpIp_ConstSegmentPtrType                   SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                   SourceSegment2Ptr,
  uint8                                       CurrentExtensionIndex,
  TCPIP_P2V(boolean)                          RejectNewSessionTicketPtr,
  TCPIP_P2V(uint16)                           ExtensionTypeListPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 extensionType = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Read extension type and length. */
  Std_ReturnType retVal = TcpIp_GetUint16FromMultiConstSegment(SourceSegment1Ptr, SourceSegment2Ptr, &extensionType);
  if (retVal == E_OK)
  {
    uint16 extensionLen = 0u;
    retVal = TcpIp_GetUint16FromMultiConstSegment(SourceSegment1Ptr, SourceSegment2Ptr, &extensionLen);
    /* #20 Check if early_data extension is present and if NewSessionTicket must be rejected because of it. */
    if(   (retVal == E_OK)
       && (extensionType == TCPIP_TLS_EXTENSION_EARLY_DATA)
       && (TcpIp_IsTlsRejectEarlyDataExtensionInTicketOfTlsConfig(TCPIP_TLSCONFIG_IDX) == TRUE))
    {
      /* Don't stop parsing yet. If we detect an invalid length, we must send an alert. */
      *RejectNewSessionTicketPtr = TRUE;
    }
    /* #30 Check that we received no duplicated extension */
    for (uint8 i = 0u; i < CurrentExtensionIndex; i++)
    {
      if (ExtensionTypeListPtr[i] == extensionType)
      {
        retVal = E_NOT_OK;
        break;
      }
    }
    ExtensionTypeListPtr[CurrentExtensionIndex] = extensionType;

    if (retVal == E_OK)
    {
      /* #40 Check that the extension length is valid but skip over the content of the extension. */
      retVal = TcpIp_SkipDataInMultiConstSegment(SourceSegment1Ptr, SourceSegment2Ptr, extensionLen);
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_FindPskForSessionTicketStorage()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_FindPskForSessionTicketStorage(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(TcpIp_Tls13PskIdentityIterType) PskIdentityIdxPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_Tls13PskIdentityIndIterType tls13PskIdentityIndIdx
    = TcpIp_GetTls13PskIdentityIndStartIdxOfTlsConnection(TlsConIdx);
  boolean emptyPskIdentityFound = FALSE;      /* at least one ticket with state 'empty' was found */
  boolean availablePskIdentityFound = FALSE;  /* at least one ticket with state 'available' was found */
  TcpIp_Tls13PskIdentityIterType usePskIdentityIdx = 0u;  /* PSK identity that shall be used to store the new ticket */
  uint32 leastCountDownTicketLifetime = 0xFFFFFFFFu;  /* set to max value */
  TcpIp_TlsHashAlgorithmType hashAlgorithm = TCPIP_HASH_ALGORITHM_NO_HASH;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  if (TcpIp_Tls13Core_GetHashAlgorithmOfActiveCipherSuite(TlsConIdx, &hashAlgorithm) == E_OK)
  {
    /* #10 Iterate over all PSK identities for the current connection. */
    for (; (   (tls13PskIdentityIndIdx < TcpIp_GetTls13PskIdentityIndEndIdxOfTlsConnection(TlsConIdx))
            && (emptyPskIdentityFound == FALSE)); tls13PskIdentityIndIdx++)
    {
      TcpIp_Tls13PskIdentityIndType pskIterIdx = TcpIp_GetTls13PskIdentityInd(tls13PskIdentityIndIdx);
      /* #20 Check if the current PSK identity is suitable to store the session ticket. */

      TcpIp_Tls13Client_CheckPskForSessionTicketStorage(pskIterIdx, hashAlgorithm, &leastCountDownTicketLifetime,
        &emptyPskIdentityFound, &availablePskIdentityFound, &usePskIdentityIdx);
    }

    /* #30 Select the best PSK. */
    if (emptyPskIdentityFound == TRUE)
    {
      /* PSK selection is already done. */
      retVal = E_OK;
    }
    else if (availablePskIdentityFound == TRUE)
    {
      /* Found a PSK that can be overwritten to store the new ticket. Use the PSK with the least remaining lifetime. */
      retVal = E_OK;
    }
    else
    {
      /* No PSK to store the new ticket was found, all PSKs are in use. */
    }

    /* Only update the PSK Idx if a PSK was found. */
    if (retVal == E_OK)
    {
      *PskIdentityIdxPtr = usePskIdentityIdx;
    }
  }
  else
  {
    /* Failed to get the hash algorithm of the used ciphersuite. */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_IsTicketLifetimeBiggerThanPskRemainingLifetime()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_Tls13Client_IsTicketLifetimeBiggerThanPskRemainingLifetime(
  TCPIP_P2C(TcpIp_TlsNewSessionTicketInfoType) NewSessionTicketInfoPtr,
  TcpIp_Tls13PskIdentityIterType               Tls13PskIdentityIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Compare the lifetime of the NewSessionTicket with the remaining lifetime of the PSK identity. */
  uint32 pskRemainingLifetimeCycles = TcpIp_GetCountDownTicketLifetimeOfTls13PskIdentityDyn(Tls13PskIdentityIdx);
  /* Ticket age in the NewSessionTicket is specified in seconds (RFC8446 chapter 4.6.1). */
  uint32 newSessionTicketLifetimeCycles = NewSessionTicketInfoPtr->LifetimeSec * TCPIP_CYCLES_PER_SECOND;

  return (newSessionTicketLifetimeCycles > pskRemainingLifetimeCycles);
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_CheckPskForSessionTicketStorage()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13Client_CheckPskForSessionTicketStorage(
  TcpIp_Tls13PskIdentityIterType            CheckThisTls13PskIdentityIdx,
  TcpIp_TlsHashAlgorithmType                NeededHashAlgorithm,
  TCPIP_P2V(uint32)                         LeastCountDownTicketLifetimePtr,
  TCPIP_P2V(boolean)                        EmptyPskIdentityFoundPtr,
  TCPIP_P2V(boolean)                        AvailablePskIdentityFoundPtr,
  TCPIP_P2V(TcpIp_Tls13PskIdentityIterType) UseThisPskIdentityIdxPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  TcpIp_TlsSessionTicketStateType state
    = TcpIp_GetSessionTicketStateOfTls13PskIdentityDyn(CheckThisTls13PskIdentityIdx);

  /* #10 Check if the PSK identity is free or old and unused. */
  switch (state)
  {
    case TCPIP_TLS_SESSION_TICKET_EMPTY:
    {
      /* Check that the PSK identity is configured for the current hash algorithm.
       * Otherwise we won't be able to compute the PSK value / binder in the resumed connection. */
      if (TcpIp_GetHashAlgorithmOfTls13PskIdentity(CheckThisTls13PskIdentityIdx) == NeededHashAlgorithm)
      {
        /* Found an empty element to store the received ticket. */
        *EmptyPskIdentityFoundPtr = TRUE;
        *UseThisPskIdentityIdxPtr = CheckThisTls13PskIdentityIdx;
      }
      break;
    }
    case TCPIP_TLS_SESSION_TICKET_AVAILABLE:
    {
      /* Check that the PSK identity is configured for the current hash algorithm.
       * Otherwise we won't be able to compute the PSK value / binder in the resumed connection. */
      if (TcpIp_GetHashAlgorithmOfTls13PskIdentity(CheckThisTls13PskIdentityIdx) == NeededHashAlgorithm)
      {
        TcpIp_CountDownTicketLifetimeOfTls13PskIdentityDynType currentCountDownTicketLifetime
          = TcpIp_GetCountDownTicketLifetimeOfTls13PskIdentityDyn(CheckThisTls13PskIdentityIdx);

        /* #20 Search for the PSK with the least remaining lifetime. */
        /* This check will always match for the first available entity, since the init value of
         * *LeastCountDownTicketLifetimePtr is set to a value bigger than the allowed maximum (= 7 days). */
        if (currentCountDownTicketLifetime < *LeastCountDownTicketLifetimePtr)
        {
          /* Ticket found with smaller remaining lifetime. */
          *LeastCountDownTicketLifetimePtr = currentCountDownTicketLifetime;
          *UseThisPskIdentityIdxPtr = CheckThisTls13PskIdentityIdx;
        }

        *AvailablePskIdentityFoundPtr = TRUE;
      }
      break;
    }
    default:
    {
      /* Ticket is reserved or in use. Skip this ticket. */
      break;
    }
  }
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_StoreNewSessionTicketInformation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_StoreNewSessionTicketInformation(
  TcpIp_TlsConnectionIterType                   TlsConIdx,
  TcpIp_Tls13PskIdentityIterType                StoreInfoTls13PskIdentityIdx,
  TCPIP_P2V(TcpIp_TlsNewSessionTicketInfoType)  NewSessionTicketInfoPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SegmentType nonceSegment = { 0u };
  TcpIp_SegmentType identitySegment = { 0u };
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Save the information which was extracted from the NewSessionTicket message. */
  TcpIp_SetTicketAgeAddOfTls13PskIdentityDyn(StoreInfoTls13PskIdentityIdx, NewSessionTicketInfoPtr->AgeAddMs);
  TcpIp_SetMaxTicketAgeOfTls13PskIdentityDyn(StoreInfoTls13PskIdentityIdx, NewSessionTicketInfoPtr->LifetimeSec);
  /* Ticket age in the NewSessionTicket is specified in seconds (RFC8446 chapter 4.6.1). */
  TcpIp_SetCountDownTicketLifetimeOfTls13PskIdentityDyn(StoreInfoTls13PskIdentityIdx,
    NewSessionTicketInfoPtr->LifetimeSec * TCPIP_CYCLES_PER_SECOND);
  TcpIp_SetPskNonceLenOfTls13PskIdentityDyn(StoreInfoTls13PskIdentityIdx, NewSessionTicketInfoPtr->NonceLen);
  TcpIp_SetPskIdentityLenOfTls13PskIdentityDyn(StoreInfoTls13PskIdentityIdx, NewSessionTicketInfoPtr->IdentityLen);

  TcpIp_SegmentInit(&nonceSegment,
    TcpIp_GetAddrTls13PskNonceBuffer(
      TcpIp_GetTls13PskNonceBufferStartIdxOfTls13PskIdentity(StoreInfoTls13PskIdentityIdx)),
    TcpIp_GetTls13PskNonceBufferLengthOfTls13PskIdentity(StoreInfoTls13PskIdentityIdx));
  /* This function call can never fail.
   * We secured in TcpIp_Tls13ClientMsg_ExtractNonceInformationFromNewSessionTicket() that the two const segments
   * are large enough for the nonce length. */
  (void) TcpIp_SegmentMemCpyFromMultiConstSegment(&NewSessionTicketInfoPtr->NonceBufferSegment1,
    &NewSessionTicketInfoPtr->NonceBufferSegment2, &nonceSegment, NewSessionTicketInfoPtr->NonceLen);

  TcpIp_SegmentInit(&identitySegment,
    TcpIp_GetAddrTls13PskIdentityBuffer(
      TcpIp_GetTls13PskIdentityBufferStartIdxOfTls13PskIdentity(StoreInfoTls13PskIdentityIdx)),
    TcpIp_GetTls13PskIdentityBufferLengthOfTls13PskIdentity(StoreInfoTls13PskIdentityIdx));
  /* This function call can never fail.
   * We secured in TcpIp_Tls13ClientMsg_ExtractIdentityInformationFromNewSessionTicket() that the two const segments
   * are large enough for the identity length. */
  (void) TcpIp_SegmentMemCpyFromMultiConstSegment(&NewSessionTicketInfoPtr->IdentityBufferSegment1,
    &NewSessionTicketInfoPtr->IdentityBufferSegment2, &identitySegment, NewSessionTicketInfoPtr->IdentityLen);

  TcpIp_SetSessionTicketStateOfTls13PskIdentityDyn(StoreInfoTls13PskIdentityIdx, TCPIP_TLS_SESSION_TICKET_AVAILABLE);
  TcpIp_SetPskSetViaSessionTicketOfTls13PskIdentityDyn(StoreInfoTls13PskIdentityIdx, TRUE);
  TcpIp_TlsCipherDataType cipherSuiteId = TCPIP_TLS_CIPHER_INVALID;
  if (   (TcpIp_Tls13Core_GetCipherSuiteFromActiveCipherWorker(TlsConIdx, &cipherSuiteId) == E_OK)
      && (TcpIp_TlsCoreUtil_IsActiveHandshakeSet(TlsConIdx) == TRUE))                                                   /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
  {
    uint8 hashLength = 0u;
    TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx
      = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
    TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx
      = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx);
    TcpIp_SetHkdfAlgorithmOfTls13PskIdentityDyn(StoreInfoTls13PskIdentityIdx,
      TcpIp_TlsCoreUtil_ReturnCipherSpecificAuthenticationMode(cipherSuiteId));
    TcpIp_SetUsedCurveOfTls13PskIdentityDyn(StoreInfoTls13PskIdentityIdx,
      TcpIp_GetEllipticCurveIdOfTlsHandshake(activeTlsHandshakeIdx));
    if (TcpIp_Tls13Core_GetCipherSuiteHashLength(cipherSuiteId, &hashLength) == E_OK)
    {
      TcpIp_SetHashLengthOfTls13PskIdentityDyn(StoreInfoTls13PskIdentityIdx, hashLength);
      retVal = E_OK;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_MaintainSessionTicketAge()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_Tls13Client_MaintainSessionTicketAge(
  TcpIp_TlsConnectionIterType             TlsConIdx,
  TcpIp_Tls13PskIdentityIterType          Tls13PskIdentityIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_MinRemainingTicketLifetimeOfTlsConfigType minRemainingLifetime
    = TcpIp_GetMinRemainingTicketLifetimeOfTlsConfig(TCPIP_TLSCONFIG_IDX);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the ticket is not already in use. */
  if (TcpIp_GetSessionTicketStateOfTls13PskIdentityDyn(Tls13PskIdentityIdx) != TCPIP_TLS_SESSION_TICKET_IN_USE)
  {
    /* #20 Check if this session ticket timed out. */
    /* This is the case if there was too much time between the reception of the NewSessionTicket
     * and triggering the resumed connection with TcpConnect().
     * The ticket is considered timed out if its lifetime has reached the configured minimum remaining lifetime. */
    if (TcpIp_GetCountDownTicketLifetimeOfTls13PskIdentityDyn(Tls13PskIdentityIdx) == minRemainingLifetime)
    {
      /* #30 The lifetime of this PSK identity has surpassed. Reset the ticket. The lifetime will be reset to zero. */
      TcpIp_Tls13Core_HandleExpiredTls13PskIdentity(Tls13PskIdentityIdx);
      /* Inform the upper layer */
      TcpIp_Tls13Client_SessionTicketUpdateCallout(TlsConIdx);

    }
    else if (TcpIp_GetCountDownTicketLifetimeOfTls13PskIdentityDyn(Tls13PskIdentityIdx) > minRemainingLifetime)
    {
      /* #40 If the lifetime of the ticket is still greater than the configured minimum, decrement it. */
      TcpIp_DecCountDownTicketLifetimeOfTls13PskIdentityDyn(Tls13PskIdentityIdx);
    }
    else
    {
      /* The lifetime of this PSK identity is zero
       * (A lifetime in the interval (0, minRemainingLifetime) is not possible,
       * it's directly set to zero if minRemainingLifetime is reached).
       * No NewSessionTicket is currently stored in it. */
    }
  }
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_SessionTicketUpdateCallout()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_Tls13Client_SessionTicketUpdateCallout(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfSocketOwnerConfigType socketOwnerConfigIdx = TcpIp_GetSocketOwnerConfigIdxOfTlsConnectionDyn(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  if (socketOwnerConfigIdx < TcpIp_GetSizeOfSocketOwnerConfig())
  {
    TcpIp_SocketOwnerTlsSessionTicketUpdateType callbackFuncPtr =
      TcpIp_GetTlsSessionTicketUpdateFuncPtrOfSocketOwnerConfig(socketOwnerConfigIdx);

    /* #10 Check if callback function is configured. */
    if (callbackFuncPtr != NULL_PTR)
    {
      /* #20 Calculate the number of currently available session tickets. */

      TcpIp_TlsSessionTicketUserInfoType sessionTicketInfo = { 0u };
      uint32 availableTicketsNum = 0u;
      TcpIp_Tls13PskIdentityIndIterType tls13PskIdentityIndIdx
        = TcpIp_GetTls13PskIdentityIndStartIdxOfTlsConnection(TlsConIdx);

      /* Iterate over all PSK identities for the current TLS connection and count the available ones. */
      for (; tls13PskIdentityIndIdx < TcpIp_GetTls13PskIdentityIndEndIdxOfTlsConnection(TlsConIdx);
             tls13PskIdentityIndIdx++)
      {
        TcpIp_Tls13PskIdentityIndType tls13PskIdentityIdx = TcpIp_GetTls13PskIdentityInd(tls13PskIdentityIndIdx);

        if (   TcpIp_GetSessionTicketStateOfTls13PskIdentityDyn(tls13PskIdentityIdx)
            == TCPIP_TLS_SESSION_TICKET_AVAILABLE)
        {
          /* Found an available ticket. */
          availableTicketsNum++;
        }
      }

      sessionTicketInfo.currentlyAvailableTicketsNum = availableTicketsNum;

      /* #30 Notify the upper layer */
      uint32 socketIdx = (uint32)TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);
      callbackFuncPtr(TCPIP_SOCKET_IDX_TO_ID(socketIdx), &sessionTicketInfo);
    }
  }
  else
  {
    TCPIP_ASSERT_UNREACHABLE();
  }
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_SendClientDummyCcs
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_SendClientDummyCcs(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx
    = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

  const TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  const TcpIp_TlsBufferRxServerCertificateRequestIdxOfTlsClientBufferMgmtType serverCertificateRequestIdx
    = TcpIp_GetTlsBufferRxServerCertificateRequestIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Trigger the transmission of the CCS message */
  TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, TRUE);
  TcpIp_SetChangeCipherSpecReadyToSendOfTlsClientConnection(tlsClientConnectionIdx, TRUE);
  /* #20 Change the TLS handshake state depending on the received messages (ClientCertificate or ClientFinished) */
  if (serverCertificateRequestIdx != TCPIP_NO_TLSBUFFERRXSERVERCERTIFICATEREQUESTIDXOFTLSCLIENTBUFFERMGMT)
  {
    /* TLS client received certificate request message - Next state is SendClientCertificate */
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE);
  }
  else
  {
    /* Proceed with sending the client finished message */
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_FINISHED);
  }
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_ParseAndProcessServerFinished
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
/* PRQA S 6030, 6050 1 */ /* MD_TcpIp_TlsStatemachine_STCYC_6030, MD_TcpIp_TlsStatemachine_STCAL_6050 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_ParseAndProcessServerFinished(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxServerFinishedIdxOfTlsClientBufferMgmtType serverFinishedIdx =
    TcpIp_GetTlsBufferRxServerFinishedIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx
    = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

  Std_ReturnType retVal = E_OK;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if we received a handshake message with the type ServerFinished */
  if (serverFinishedIdx != TCPIP_NO_TLSBUFFERRXSERVERFINISHEDIDXOFTLSCLIENTBUFFERMGMT)
  {
    /* #20 Extract the ServerFinished message until we are done AND no Async context needs to be computed */
    while (   (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_DONE)   /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
              /* Async operation is trigged (performed in lowPrio task - leave this context */
           && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_ASYNC_PENDING)
              /* Error during processing of the data - skip further data handling */
           && (retVal == E_OK))
    {
      switch (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx))
      {
        case TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED:
        {
#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
          if (TcpIp_IsSessionResumptionUsingPskOfTlsConnectionDyn(TlsConIdx) == FALSE)
          {
            /* #30 Notify the certificate chain validation result to user. */
            /* The ServerFinished is the first non-optional message after the ServerCertificate,
             * therefore the validation callback is triggered here. */
            TcpIp_TlsClient_TlsCertChainTriggerValidationCallback(TlsConIdx, TRUE);
          }
#   endif

          /* #40 Extract the Verify Data value from the message */
          retVal = TcpIp_Tls13ClientMsg_ExtractServerFinishedInformation(TlsConIdx);
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_CALC_HASH_AND_FINISHED);
          break;
        }

        case TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_CALC_HASH_AND_FINISHED:
        {
          /* #50 Trigger calculation of the VerifyData */
           /* Triggers the calculation of the VerifyData in the async context handler */
          TcpIp_SetCalcClientFinishedHashAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx, TRUE);

          /* Set the TLS connection state to ASYNC_PENDING */
          TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_ASYNC_PENDING);

          /* Set the next state that should be executed after the async operation is done */
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_VERIFY);

          /* This operation is processed within the lowPrio function, which means that we are leaving
             this context and return when the operation is DONE */
          break;
        }

        case TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_VERIFY:
        {
          /* #60 Compare the calculated and received VerifyData */
          retVal = TcpIp_Tls13ClientMsg_CompareFinishedVerifyData(TlsConIdx);
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx,
            TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_CALC_CLIENT_FINISHED_KEY);
          break;
        }

        case TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_CALC_CLIENT_FINISHED_KEY:
        {
          /* #70 Trigger the calculation of the FinishedKey for the ClientFinished. */
          /* This is done here, since the handshake secret is needed for this calculation
           * and it's being overwritten when calculating the application traffic keys
           * (This could be solved by adding an additional container in the description,
           * but currently we decided against this). */
          TcpIp_SetCalcFinishedKeyAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx, TRUE);
          TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_ASYNC_PENDING);
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx,
            TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_WAIT_FOR_ASYNC_FINISHED_KEY);
          break;
        }

        case TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_WAIT_FOR_ASYNC_FINISHED_KEY:
        {
          /* Crypto calculation is finished */
          TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_NO_ASYNC);

          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_CALC_APPL_KEYS);
          break;
        }

        case TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_CALC_APPL_KEYS:
        {
          /* #80 Trigger the calculation of the application traffic keys */
          /* Set Flag for specific crypto operation, and set async pending. */
          TcpIp_SetCalcApplTrafficKeysAsyncFlagOfTlsConnectionDyn(TlsConIdx, TRUE);
          TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_ASYNC_PENDING);

          /* Set next HS state. */
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_WAIT_FOR_ASYNC_APPL_KEY);
          break;
        }

        case TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_WAIT_FOR_ASYNC_APPL_KEY:
        {
          /* Crypto calculation is finished */
          TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_NO_ASYNC);

          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_SERVER_FINISHED_DONE);
          break;
        }

        default:                                                                                                        /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
        {
          /* Default case left blank intentionally */
          break;
        }
      }
    }
  }
  else
  {
    /* #90 otherwise, we receive an unexpected message, so trigger the alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ExtractServerFinishedInformation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ExtractServerFinishedInformation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferRxServerFinishedIdxOfTlsClientBufferMgmtType rxServerFinishedStartIdx
    = TcpIp_GetTlsBufferRxServerFinishedIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);
  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType rxServerFinishedVerifyDataIdx
    = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_ServerFinishedLenOfTlsClientBufferMgmtType serverFinishedLen
    = TcpIp_GetServerFinishedLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);
  TcpIp_TlsBufferRxIterType rxServerFinishedEndIdx = rxServerFinishedStartIdx + TCPIP_TLS_HSHDRLEN + serverFinishedLen;
  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  uint8 hmacHashLen = TcpIp_GetCipherMacKeyLengthOfTlsCipherWorker(activeTlsCipherWorkerIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if we received the expected amount of data (Finished message length) and store the information */
  if (   (serverFinishedLen == hmacHashLen)
      && (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx),
            hmacHashLen, rxServerFinishedEndIdx)))
  {
    /* Save the position of the received ClientFinishedVerifyData */
    TcpIp_SetTlsBufferRxServerFinishedVerifyDataIdxOfTlsClientBufferMgmt(
      tlsClientBufferMgmtIdx,
      rxServerFinishedVerifyDataIdx);

    /* Increment the Rx buffer ReadIdx by the length of the VerifyData */
    TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, hmacHashLen);

    retVal = E_OK;
  }
  else
  {
    /* If an error occurs report the error to the user */
    TcpIp_TlsUserErrorType UserError;
    UserError.FunctionId = TCPIP_TLS_FCTID_CLIENT_HSSTM_PARSE_SERVERFINISHED;
    UserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_UNEXPECTEDMSGLEN;
    UserError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(UserError);

    /* #20 Trigger alert TCPIP_TLS_ALERT_DESC_DECODE_ERROR in case of invalid length */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_CompareFinishedVerifyData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_CompareFinishedVerifyData(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  uint8 hmacHashLen = TcpIp_GetCipherMacKeyLengthOfTlsCipherWorker(activeTlsCipherWorkerIdx);

  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* Calculated data is present in Temp buffer */
  TCPIP_P2C(uint8) calcVerifyDataPtr = TcpIp_GetAddrTlsTemporaryHmacBuffer(
    TcpIp_GetTlsTemporaryHmacBufferStartIdxOfTlsConnection(TlsConIdx));

  TCPIP_P2C(uint8) rxVerifyDataPtr = TcpIp_GetAddrTlsBufferRx(
    TcpIp_GetTlsBufferRxServerFinishedVerifyDataIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx));

  /* #10 Compare the calculated finished value and the received finished value */
  if (IpBase_StrCmpLen(rxVerifyDataPtr, calcVerifyDataPtr, (uint16)hmacHashLen) == E_OK)
  {
    retVal = E_OK;
  }
  else
  {
    /* If an error occurs report the error to the user */
    TcpIp_TlsUserErrorType userError;
    userError.FunctionId = TCPIP_TLS_FCTID_CLIENT_HSSTM_PARSE_SERVERFINISHED;
    userError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_INCORRECTVERIFYDATA;
    userError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(userError);

    /* #20 Trigger alert TCPIP_TLS_ALERT_DESC_DECRYPT_ERROR in case of invalid length */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECRYPT_ERROR);

    retVal = E_NOT_OK;
  }
  return retVal;
}

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_SendClientCertificate
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_SendClientCertificate(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Prepare sending of the client cert message, depending on the handshake state. */
  if (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE)
  {
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_ISSUE_CALLOUT);
  }

  if (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_ISSUE_CALLOUT)
  {
    TcpIp_TlsClient_IssueCertRequestCallout(TlsConIdx);
  }

  if ( (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_PREPARE_FULL_MESSAGE)
    || (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_PREPARE_EMPTY_MESSAGE))/* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
  {
    TcpIp_Tls13ClientMsg_PrepareClientCertificateMessage(TlsConIdx);
  }
} /* TcpIp_Tls13ClientHsStm_SendClientCertificate() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_PrepareClientCertificateMessage
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_PrepareClientCertificateMessage(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);

  /* #10 Prepare the ClientCertificate message */
  retVal = TcpIp_Tls13ClientMsg_BuildClientCertificateMessage(TlsConIdx);

  /* #20 Check if the message was prepared successfully */
  if (retVal == E_OK)
  {
    /* #30 Yes:
     *      If certificates are available: Change the state to TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY
     *      Otherwise: Change the state to TCPIP_TLS_STATE_SEND_CLIENT_FINISHED */
    const TcpIp_TlsClientAuthenticationMgmtIdxOfTlsConnectionType tlsClientAuthenticationMgmtIdx
      = TcpIp_GetTlsClientAuthenticationMgmtIdxOfTlsConnection(TlsConIdx);

    TCPIP_P2C(TcpIp_TlsClientCertInfoType) certInfoPtr
      = TcpIp_GetAddrClientCertInfoOfTlsClientAuthenticationMgmt(tlsClientAuthenticationMgmtIdx);

    const TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx
      = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

    TcpIp_SetClientCertificateReadyToSendOfTlsClientConnection(tlsClientConnectionIdx, TRUE);

    if (certInfoPtr->CertIdListLen != 0u)
    {
      TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY);
    }
    else
    {
      TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_FINISHED);
    }

    TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, TRUE);
  }
  /* #40 Otherwise cancel the handshake and raise an alert */
  else
  {
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_ABORT);
  }
} /* TcpIp_Tls13ClientMsg_PrepareClientCertificateMessage() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_BuildClientCertificateMessage
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_BuildClientCertificateMessage(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* Implements the creation of Certificate message
   * according to RFC 8466 section 4.4.2.
   *
   * Data type according to RFC:
   *  struct {
   *      opaque certificate_request_context<0..2^8-1>;
   *      CertificateEntry certificate_list<0..2^24-1>;
   *  } Certificate;
   *
   */
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  const TcpIp_TlsClientBufferMgmtIdxOfTlsConnectionType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  const TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType clientCertificateStartIdx
    = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  Std_ReturnType retVal = E_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Setup the start index of the client certificate message. */
  TcpIp_SetTlsBufferTxClientCertificateIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, clientCertificateStartIdx);

  /* #20 Add generic handshake header */
  TcpIp_TlsMsg_AddHsHdr(TlsConIdx, TCPIP_TLS_HSTYPE_CERTIFICATE);

  /* #30 Add certificate_request_context */
  retVal = TcpIp_Tls13ClientMsg_BuildClientCertificateMessageAddContext(TlsConIdx);

  /* #40 If certificate_request_context was added successfully then add the certificate_list */
  if (retVal == E_OK)
  {
    retVal = TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateList(TlsConIdx);
  }

  /* #50 If message was build successfully then update msg information. */
  if (retVal == E_OK)
  {
    /* Write the length information into the HS Header */
    const TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType currentWriteIdx
      = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
    const uint32 clientCertificateLen  = (uint32)currentWriteIdx - (uint32)clientCertificateStartIdx;

    /* Store message information in header if it can be stored in header */
    if (   ((clientCertificateLen - TCPIP_TLS_HSHDRLEN) > TCPIP_TLS_HSLEN_MAX_LEN)
        || (clientCertificateLen > TCPIP_MAX_CLIENTCERTIFICATELENOFTLSCLIENTBUFFERMGMT))                                /* PRQA S 2992, 2996 */ /* MD_TCPIP_Rule14.3_2741_2742_2991_2992_2995_2996 */
    {
      retVal = E_NOT_OK;
    }
    else
    {
      /* Update total length information in header */
      const uint32 payloadLen = clientCertificateLen - (uint32)TCPIP_TLS_HSHDRLEN;

      TcpIp_SetClientCertificateLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
        (TcpIp_ClientCertificateLenOfTlsClientBufferMgmtType)clientCertificateLen);
      TcpIp_TlsMsg_AddLenToHsHdr((TcpIp_TlsBufferTxIterType)clientCertificateStartIdx, payloadLen);
    }
  }

  /* #60 If an error occurred raise an alert that an internal error occurred */
  if (retVal != E_OK)
  {
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
  }

  return retVal;
} /* TcpIp_Tls13ClientMsg_BuildClientCertificateMessage() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_BuildClientCertificateMessageAddContext
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_BuildClientCertificateMessageAddContext(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* Implements the creation of certificate_request_context of a
   * Certificate message according to RFC 8466 section 4.4.2.
   *
   * Data type according to RFC:
   *      opaque certificate_request_context<0..2^8-1>;
   *
   * Limitations:
   *  - Supports empty context only. During reception of a
   *    CertificateRequest message, a message containing context
   *    data is rejected.
   */

  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  const TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType ctxStartTlsBufferTxIdx
    = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  const TcpIp_TlsBufferTxAdHsEndIdxOfTlsBufferMgmtType tlsBufferTxAdHsEndIdx
    = TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Store certificate_request_context length if TX buffer is big enough. */
  if (TCPIP_TLS_TXBUFFER_ISIDXINRANGE(ctxStartTlsBufferTxIdx, TCPIP_TLS_CERT_REQUEST_CONTEXT_LEN_LEN, tlsBufferTxAdHsEndIdx))
  {
    /* Insert empty certificate_request_context */
    IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(ctxStartTlsBufferTxIdx), 0u, 0u);
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_CERT_REQUEST_CONTEXT_LEN_LEN);

    retVal = E_OK;
  }
  /* #20 Otherwise raise an alert that an internal error occurred (memory allocation failed) */
  else
  {
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
  }

  return retVal;
} /* TcpIp_Tls13ClientMsg_BuildClientCertificateMessageAddContext() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateList
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateList(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* Implements the creation of certificate_list of a
   * Certificate message according to RFC 8466 section 4.4.2.
   *
   * Data type according to RFC:
   *  CertificateEntry certificate_list<0..2^24-1>;
   *
   */

  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  const TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType certListStartTlsBufferTxIdx
    = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  const TcpIp_TlsBufferTxAdHsEndIdxOfTlsBufferMgmtType tlsBufferTxAdHsEndIdx
    = TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Store certificate_list length if TX buffer is big enough. */
  if (TCPIP_TLS_TXBUFFER_ISIDXINRANGE(certListStartTlsBufferTxIdx, TCPIP_TLS_CERTCHAINLEN_LEN, tlsBufferTxAdHsEndIdx))
  {
    TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType certificateListContentStartIdx = 0u;

    /* Add the certificate_list to message data */
    /* Skip total length information as this information is not yet available */
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_CERTCHAINLEN_LEN);
    certificateListContentStartIdx = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

    /* #20 Build certificate_list based on user/client certificates */
    if (TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateListAddCerts(TlsConIdx) == E_OK)
    {
      /* #30 If message data was added successfully then update length information */
      const TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType currentWriteIdx
        = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

      const uint32 certificateListLen = (uint32)currentWriteIdx - (uint32)certificateListContentStartIdx;

      /* Write certificate_list length to TX Buffer if it is valid. */
      if (certificateListLen <= TCPIP_TLS_CERTSLEN_LEN_MAX_VALUE)
      {
        IpBase_PutUint24(TcpIp_GetAddrTlsBufferTx(certListStartTlsBufferTxIdx), 0u, (uint32)certificateListLen);
        retVal = E_OK;
      }
    }
  }

  /* #40 If an error occurred then raise an alert that an internal error occurred */
  if (retVal != E_OK)
  {
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
  }

  return retVal;
} /* TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateList() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateListAddCerts
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateListAddCerts(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* Implements the creation of multiple CertificateEntry entries of a
   * Certificate message according to RFC 8466 section 4.4.2.
   *
   * Data type according to RFC:
   *  struct {
   *      select (certificate_type) {
   *          case RawPublicKey:
   *            # From RFC 7250 ASN.1_subjectPublicKeyInfo
   *            opaque ASN1_subjectPublicKeyInfo<1..2^24-1>;
   *
   *          case X509:
   *            opaque cert_data<1..2^24-1>;
   *      };
   *      Extension extensions<0..2^16-1>;
   *  } CertificateEntry;
   *
   *
   * Limitations:
   *  - Supports empty extensions only.
   *  - Supports X.509 certificates only.
   */
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsClientAuthenticationMgmtIdxOfTlsConnectionType tlsClientAuthenticationMgmtIdx
    = TcpIp_GetTlsClientAuthenticationMgmtIdxOfTlsConnection(TlsConIdx);

  TCPIP_P2C(TcpIp_TlsClientCertInfoType) certInfoPtr
    = TcpIp_GetAddrClientCertInfoOfTlsClientAuthenticationMgmt(tlsClientAuthenticationMgmtIdx);

  Std_ReturnType retVal = E_OK;
  uint8_least certIter = 0u;


  /* ----- Implementation ----------------------------------------------- */
  /* It may be possible that the certIdListLen is set to 0. This is not an error,
   * only the certificate list shall contain no entry. See RFC 8446 section 4.4.2
   *
   * "If the server requests client authentication but no
   * suitable certificate is available, the client MUST send a Certificate
   * message containing no certificates (i.e., with the "certificate_list"
   * field having length 0)"
   */
  /* #10 For each available user/client certificate available */
  for (certIter = 0u; certIter < (uint8_least)certInfoPtr->CertIdListLen; certIter++)
  {
    /* #20 Add certificate data to the message */
    const KeyM_CertificateIdType certId = certInfoPtr->CertIdList[certIter];

    retVal = TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateListAddCertData(TlsConIdx, certId);

    /* #30 If certificate data was added successfully then add extensions to the CertificateEntry */
    if (retVal == E_OK)
    {
      retVal = TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateListAddCertExt(TlsConIdx);
    }

    /* #40 Stop the processing if message creation failed */
    if (retVal != E_OK)
    {
      break;
    }
  }

  /* #50 If an error occurred then raise an alert that something internal went wrong */
  if (retVal != E_OK)
  {
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
  }

  return retVal;
} /* TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateListAddCerts() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateListAddCertData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateListAddCertData(
  TcpIp_TlsConnectionIterType TlsConIdx,
  KeyM_CertificateIdType CertificateId)
{
  /* Implements the creation of a CertificateEntry of a
   * Certificate message according to RFC 8466 section 4.4.2.
   *
   * Data type according to RFC:
   *      select (certificate_type) {
   *          case RawPublicKey:
   *            # From RFC 7250 ASN.1_subjectPublicKeyInfo
   *            opaque ASN1_subjectPublicKeyInfo<1..2^24-1>;
   *
   *          case X509:
   *            opaque cert_data<1..2^24-1>;
   *      };
   *
   *
   * Limitations:
   *  - Supports X.509 certificates only.
   */
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType certLengthStartTlsBufferTxIdx
    = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  const TcpIp_TlsBufferTxAdHsEndIdxOfTlsBufferMgmtType tlsBufferTxAdHsEndIdx
    = TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If TX buffer is big enough to store a CertificateEntry.cert_data then add the cert data */
  if (TCPIP_TLS_TXBUFFER_ISIDXINRANGE(certLengthStartTlsBufferTxIdx, TCPIP_TLS_CERT_ENTRY_CERT_MIN_LEN, tlsBufferTxAdHsEndIdx))
  {
    /* Fetch certificate data from KeyM */
    const TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType certStartTlsBufferTxIdx
      = certLengthStartTlsBufferTxIdx + TCPIP_TLS_CERTLEN_LEN;

    uint32 freeTxBufferLen = (uint32)tlsBufferTxAdHsEndIdx - (uint32)certStartTlsBufferTxIdx;

    KeyM_CertDataType certificateData = { 0 };

    /* Limit size to 24 bit as only 24 bit can be transmitted in data type of RFC */
    if (freeTxBufferLen > TCPIP_TLS_CERT_LEN_MAX_VALUE)                                                                 /* PRQA S 2992, 2996 */ /* MD_TCPIP_Rule14.3_2741_2742_2991_2992_2995_2996 */
    {
      freeTxBufferLen = TCPIP_TLS_CERT_LEN_MAX_VALUE;
    }
    certificateData.certData = TcpIp_GetAddrTlsBufferTx(certStartTlsBufferTxIdx);
    certificateData.certDataLength = freeTxBufferLen;

    /* If certificate data could be fetched then update the TX buffer write index and length information */
    if (KeyM_GetCertificate(CertificateId, &certificateData) == E_OK)
    {
      const TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType certAndLenLength
        = (TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType)(certificateData.certDataLength + TCPIP_TLS_CERTLEN_LEN);

      IpBase_PutUint24(TcpIp_GetAddrTlsBufferTx(certLengthStartTlsBufferTxIdx), 0u, certificateData.certDataLength);
      TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, certAndLenLength);

      retVal = E_OK;
    }
  }

  /* #20 If an error occurred then raise an alert that something internal went wrong */
  if (retVal != E_OK)
  {
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
  }

  return retVal;
} /* TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateListAddCertData() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateListAddCertExt
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateListAddCertExt(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* Implements the creation of a CertificateEntry of a
   * Certificate message according to RFC 8466 section 4.4.2.
   *
   * Data type according to RFC:
   *      Extension extensions<0..2^16-1>;
   *
   *
   * Limitations:
   *  - Supports empty extensions only.
   */

  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  const TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType extStartTlsBufferTxIdx
    = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  const TcpIp_TlsBufferTxAdHsEndIdxOfTlsBufferMgmtType tlsBufferTxAdHsEndIdx
    = TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 If TX buffer is big enough to store CertificateEntry.extensions then add the extension */
  if (TCPIP_TLS_TXBUFFER_ISIDXINRANGE(extStartTlsBufferTxIdx, TCPIP_TLS_CERT_EXTENSION_LEN, tlsBufferTxAdHsEndIdx))
  {
      IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(extStartTlsBufferTxIdx), 0u, 0u);
      TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_CERT_EXTENSION_LEN);
      retVal = E_OK;
  }
  /* #20 Otherwise raise an alert that memory allocation failed */
  else
  {
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
  }

  return retVal;
} /* TcpIp_Tls13ClientMsg_BuildClientCertificateMessageCertificateListAddCertExt() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_SendClientCertificateVerify
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010 1 */ /* MD_TcpIp_TlsStatemachine_STPTH_6010 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_SendClientCertificateVerify(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* Implements the creation of a CertificateVerify message
   * according to RFC 8466 section 4.4.3.
   *
   * Data type according to RFC:
   *   struct {
   *       SignatureScheme algorithm;
   *       opaque signature<0..2^16-1>;
   *   } CertificateVerify;
   *
   *
   */
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;


  /* ----- Implementation ----------------------------------------------- */
  TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);

  /* #10 Prepare the Certificate Verify message by adding all relevant message information */
  if (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY)
  {
    retVal = TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyAddStaticData(TlsConIdx);
  }

  if (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_CALC_SIGNATURE)
  {
    retVal = TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyStartSignatureCalc(TlsConIdx);
  }

  if (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_CALC_SIGNATURE_WAIT_FOR_ASYNC)
  {
    retVal = TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyWaitAsync(TlsConIdx);
  }

  if (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_ENCODE_SIGNATURE)
  {
    retVal = TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyEncodeSign(TlsConIdx);
  }

  if (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_TRIGGER_TX)
  {
    retVal = TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyFinalize(TlsConIdx);
  }

  if (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_DONE)
  {
    /* If the preparation of the CertificateVerify message is done, set the next state to TCPIP_TLS_STATE_SEND_CLIENT_FINISHED */
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_FINISHED);
  }

  /* #20 If an error occurred then raise an alert that something internal went wrong */
  if (retVal != E_OK)
  {
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_ABORT);
  }
} /* TcpIp_Tls13ClientHsStm_SendClientCertificateVerify() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyAddStaticData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyAddStaticData(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* Implements the creation of a CertificateVerify message
   * according to RFC 8466 section 4.4.3.
   *
   * Data type according to RFC:
   *   struct {
   *       SignatureScheme algorithm;
   *       opaque signature<0..2^16-1>;
   *   } CertificateVerify;
   *
   *
   * Notes:
   *  This API adds the algorithm field, the signature
   *  data is added later on.
   */
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  const TcpIp_TlsClientBufferMgmtIdxOfTlsConnectionType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  const TcpIp_TlsBufferTxAdHsEndIdxOfTlsBufferMgmtType tlsBufferTxAdHsEndIdx
    = TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType curWriteTlsBufferTxIdx
    = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* Set the start index of this message to the current write index */
  TcpIp_SetTlsBufferTxClientCertificateVerifyIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, curWriteTlsBufferTxIdx);

  /* #10 Add the generic handshake header */
  TcpIp_TlsMsg_AddHsHdr(TlsConIdx, TCPIP_TLS_HSTYPE_CERTIFICATEVERIFY);

  curWriteTlsBufferTxIdx = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  /* #20 If TX buffer is big enough to store CertificateVerify.algorithm, add the algorithm */
  if (TCPIP_TLS_TXBUFFER_ISIDXINRANGE(curWriteTlsBufferTxIdx, TCPIP_TLS_CERTVERIFY_SIGALGO_LEN, tlsBufferTxAdHsEndIdx))
  {
    const TcpIp_TlsClientAuthenticationMgmtIdxOfTlsConnectionType tlsClientAuthenticationMgmtIdx
      = TcpIp_GetTlsClientAuthenticationMgmtIdxOfTlsConnection(TlsConIdx);

    TCPIP_P2C(TcpIp_TlsClientCertInfoType) certInfoPtr
      = TcpIp_GetAddrClientCertInfoOfTlsClientAuthenticationMgmt(tlsClientAuthenticationMgmtIdx);

    IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(curWriteTlsBufferTxIdx), 0u, (uint16)certInfoPtr->SignatureAndHashAlgo);
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_CERTVERIFY_SIGALGO_LEN);

    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx,
      TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_CALC_SIGNATURE);

    retVal = E_OK;
  }
  /* #30 Otherwise raise an alert that an internal error occurred (memory allocation failed) */
  else
  {
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
  }

  return retVal;
} /* TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyAddStaticData() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyStartSignatureCalc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyStartSignatureCalc(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* Implements the creation of a CertificateVerify message
   * according to RFC 8466 section 4.4.3.
   *
   * Data type according to RFC:
   *   struct {
   *       SignatureScheme algorithm;
   *       opaque signature<0..2^16-1>;
   *   } CertificateVerify;
   *
   *
   * Notes:
   *  This API does not add any message element, only CSM execution in
   *  async handler is prepared/started.
   */
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx =
    TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

  Std_ReturnType retVal = E_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Trigger the calculation of the signature in the async context handler */
  TcpIp_SetCalcClientCertVerifySignatureAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx, TRUE);

  /* #20 Set the async state to ASYNC_PENDING */
  TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_ASYNC_PENDING);

  /* #30 Set the state to TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_CALC_SIGNATURE_WAIT_FOR_ASYNC */
  TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx,
    TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_CALC_SIGNATURE_WAIT_FOR_ASYNC);

  return retVal;
} /* TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyStartSignatureCalc() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyWaitAsync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyWaitAsync(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if async handler has finished */
  if (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_DONE)
  {
    /* Errors are reported directly in the async handler itself and not in this context */

    /* #20 Reset async flag */
    TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_NO_ASYNC);
    /* #30 Set the state to TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_ENCODE_SIGNATURE */
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx,
      TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_ENCODE_SIGNATURE);
  }

  return retVal;
} /* TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyWaitAsync() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyEncodeSign
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyEncodeSign(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* Implements the creation of a CertificateVerify message
   * according to RFC 8466 section 4.4.3.
   *
   * Data type according to RFC:
   *   struct {
   *       SignatureScheme algorithm;
   *       opaque signature<0..2^16-1>;
   *   } CertificateVerify;
   *
   *
   * Notes:
   *  This API adds the signature data only. The signature
   *  is calculated in async handler context and if the
   *  the async handler is finished then the signature data
   *  is going to be handled here.
   */
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsClientBufferMgmtIdxOfTlsConnectionType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  const TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  const TcpIp_TlsBufferTxAdHsEndIdxOfTlsBufferMgmtType tlsBufferTxAdHsEndIdx
    = TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  const TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType currentWriteIdx
    = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 If TX buffer is big enough to store the signature, store it */
  if (TCPIP_TLS_TXBUFFER_ISIDXINRANGE(currentWriteIdx, TCPIP_TLS_CERTVERIFY_SIG_LENGTH_LEN, tlsBufferTxAdHsEndIdx))
  {
    /* Save the current write index to mark the position where the signature length should be placed. */
    TcpIp_SetTlsBufferTxClientCertVerifySignatureLenIdxOfTlsClientBufferMgmt(
      tlsClientBufferMgmtIdx, currentWriteIdx);

    /* Increment the write index by the consumed length (2 Byte) */
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_CERTVERIFY_SIG_LENGTH_LEN);

    /* #20 Encode the calculated signature and add it to the message */
    TcpIp_TlsClientMsg_CertVerifyEncodeSignature(TlsConIdx);

    /* #30 Update state to TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_TRIGGER_TX */
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_TRIGGER_TX);

    retVal = E_OK;
  }

  /* #40 If an error occurred then raise an alert that an internal error occurred */
  if (retVal != E_OK)
  {
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
  }

  return retVal;
} /* TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyEncodeSign() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyFinalize
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyFinalize(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* Implements the creation of a CertificateVerify message
   * according to RFC 8466 section 4.4.3.
   *
   * Data type according to RFC:
   *   struct {
   *       SignatureScheme algorithm;
   *       opaque signature<0..2^16-1>;
   *   } CertificateVerify;
   *
   *
   * Notes:
   *  Message is now completely set up in TX buffer.
   *  This API updates some general information only.
   */
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  const TcpIp_TlsClientBufferMgmtIdxOfTlsConnectionType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  const TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx =
    TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

  const TcpIp_TlsBufferTxIterType currentWriteIdx
    = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  const TcpIp_TlsBufferTxIterType messageStartIdx
    = TcpIp_GetTlsBufferTxClientCertificateVerifyIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

  const TcpIp_TlsBufferTxIterType messageLength
    = currentWriteIdx - messageStartIdx;

  const TcpIp_TlsBufferTxIterType payloadLen
    = messageLength - (TcpIp_TlsBufferTxIterType)TCPIP_TLS_HSHDRLEN;

  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 If message length can be stored in CSL data type */
  if (   (messageLength <= TCPIP_MAX_CLIENTCERTIFICATEVERIFYLENOFTLSCLIENTBUFFERMGMT)                                   /* PRQA S 2991, 2995 2 */ /* MD_TCPIP_Rule14.3_2741_2742_2991_2992_2995_2996 */
      && (payloadLen <= TCPIP_TLS_HSLEN_MAX_LEN))
  {
    /* #20 Write the length information into the HS Header */
    TcpIp_SetClientCertificateVerifyLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
      (TcpIp_ClientCertificateVerifyLenOfTlsClientBufferMgmtType)messageLength);

    TcpIp_TlsMsg_AddLenToHsHdr(messageStartIdx, (uint32)payloadLen);

    /* #30 Client CertificateVerify message is now ready to send, set the corresponding trigger */
    TcpIp_SetCertificateVerifyReadyToSendOfTlsClientConnection(tlsClientConnectionIdx, TRUE);
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY_DONE);
    TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, TRUE);

    retVal = E_OK;
  }
  /* #40 Otherwise raise an alert that an internal error occurred */
  else
  {
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);                     /* PRQA S 2880 */ /* MD_TCPIP_Rule2.1_2880 */
  }

  return retVal;
} /* TcpIp_Tls13ClientHsStm_PrepareClientCertificateVerifyFinalize() */
#   endif

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_SendClientFinished
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_SendClientFinished(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);

  /* #10 Forward the message to the specific preparation function */
  TcpIp_Tls13ClientMsg_PrepareClientFinished(TlsConIdx);

  /* #20 Message prepared successfully - check if the parsing is completely done and change the state */
  if (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_ASYNC_PENDING)
  {
    /* Async operation pending, nothing to do - just leave the function */
  }
  else
  {
    /* #30 Preparation completely done - Change the state to TCPIP_TLS_STATE_HANDSHAKE_FINALIZING */
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_FINALIZING);
    TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, TRUE);
  }
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_PrepareClientFinished
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_PrepareClientFinished(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx
    = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Prepare the ClientFinished message until we are done AND no Async context needs to be computed */
  while (   (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_DONE)         /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
            /* Async operation is trigged (performed in lowPrio task) - leave this context */
         && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_ASYNC_PENDING))
  {
    switch (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx))
    {
      case TCPIP_TLS_STATE_SEND_CLIENT_FINISHED:
      {
        /* Store the current write index as the start index of this message - used to add the length information after the data is added */
        TcpIp_SetTlsBufferTxClientFinishedIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx,
          TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

        /* #20 ClientFinished message - Add generic TLS handshake header */
        TcpIp_TlsMsg_AddHsHdr(TlsConIdx, TCPIP_TLS_HSTYPE_FINISHED);

        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_CALC_HASH);
        break;
      }

      case TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_CALC_HASH:
      {
        /* #30 ClientFinished message - Add the calculated client finished data */
        TcpIp_Tls13ClientMsg_ClientFinishedAddClientFinishedData(TlsConIdx);
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_TRIGGER_TX);
        /* This operation is processed within the lowPrio function, which means that we are leaving
           this context and return when the operation is DONE */
        break;
      }

      case TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_TRIGGER_TX:
      {
        /* #40 ClientFinished message - Update the overall length information in the TLS handshake header */

        /* Determine the hash length depending on the used cipher suite. */
        uint8 hashLength = 0u;
        if(TcpIp_Tls13Core_GetHashLengthOfActiveCipherSuite(TlsConIdx, &hashLength) == E_OK)
        {
          /* Copy the verifyData into the Tx buffer. */
          TCPIP_P2V(uint8) destPtr = TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

          TCPIP_P2C(uint8) verifyDataPtr = TcpIp_GetAddrTlsTemporaryHmacBuffer(
            TcpIp_GetTlsTemporaryHmacBufferStartIdxOfTlsConnection(TlsConIdx));

          VStdMemCpy(destPtr, verifyDataPtr, hashLength);

          /* Maintain AdHs write index by incrementing the consumed length */
          TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, hashLength);

          TcpIp_SetClientFinishedLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, (TCPIP_TLS_HSHDRLEN +
            (TcpIp_ClientFinishedLenOfTlsClientBufferMgmtType) hashLength));

          TcpIp_TlsMsg_AddLenToHsHdr(TcpIp_GetTlsBufferTxClientFinishedIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx),
            hashLength);

          /* Trigger the transmission of the TLS-Client finished message */
          TcpIp_SetClientFinishedReadyToSendOfTlsClientConnection(tlsClientConnectionIdx, TRUE);

          /* Check if connection is a TLS 1.3 resumption base connection. */
          if (TcpIp_TlsClient_IsResumptionBaseConnection(TlsConIdx) == TRUE)
          {
            /* Next calculate the resumption master secret. */
            TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_CALC_RESUMPTION_MASTER_SECRET);
          }
          else
          {
            TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_DONE);
          }
        }
        else
        {
          /* Trigger alert internal_error in case the hash length can not be found. */
          TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_ABORT);
        }
        break;
      }

      case TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_CALC_RESUMPTION_MASTER_SECRET:
      {
        /* #50 Trigger calculating the resumption master secret. */
        TcpIp_SetCalcResumptionMasterSecretAsyncFlagOfTlsConnectionDyn(TlsConIdx, TRUE);
        TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_ASYNC_PENDING);
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_WAIT_FOR_ASYNC_RESUMPTION_MASTER_SECRET);
        break;
      }

      case TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_WAIT_FOR_ASYNC_RESUMPTION_MASTER_SECRET:
      {
        /* #60 Resumption master secret calculation is completed, message handling is completed. */

        /* Start connection lifetime timer. */
        TcpIp_SetResumptionBaseConnectionAgeOfTlsClientConnection(tlsClientConnectionIdx, 1u);

        /* Reset async context. */
        TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_NO_ASYNC);
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_CLIENT_FINISHED_DONE);
        break;
      }

      default:                                                                                                          /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
      {
        /* Default case left blank intentionally */
        TCPIP_ASSERT_UNREACHABLE();
        break;
      }
    } /* switch () */
  } /* while ( ) */
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ClientFinishedAddClientFinishedData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientFinishedAddClientFinishedData(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsClientBufferMgmtIterType tlsClientBufMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx
    = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */

  /* Store the position of the verify data (will be set inside the async context function) */
  TcpIp_SetTlsBufferTxClientFinishedVerifyDataIdxOfTlsClientBufferMgmt(tlsClientBufMgmtIdx,
    TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

  /* #10 Handles synchronous CSM call and triggers the calculation of the job in the async context handler */
  TcpIp_SetCalcClientFinishedHashAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx, TRUE);

  /* Set the TLS connection state to ASYNC_PENDING */
  TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_ASYNC_PENDING);
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientHsStm_FinalizeHandshake
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_FinalizeHandshake(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx =
    TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_CsmKeyIdType handshakePassiveEncryptKeyId
    = TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdCipherPassiveEncryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));
  TcpIp_TlsCsmJobIterType encryptTlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
    TcpIp_GetCsmJobIdCipherEncryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));
  TcpIp_CsmKeyIdType handshakeEncryptKeyId
    = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(encryptTlsCsmJobIdx);

  TcpIp_TlsBufferTxAdHsStartIdxOfTlsBufferMgmtType txAdHsStartIdx
    = TcpIp_GetTlsBufferTxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);
  TcpIp_TlsBufferTxAdHsReadIdxOfTlsBufferMgmtDynType txAdHsReadIdx
    = TcpIp_GetTlsBufferTxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType txAdHsWriteIdx
    = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  TcpIp_TlsBufferRxAdHsStartIdxOfTlsBufferMgmtType rxAdHsStartIdx
    = TcpIp_GetTlsBufferRxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);
  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType rxAdHsReadIdx
    = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* Wait for the Client Finished to be send. */
  if (TcpIp_IsClientFinishedReadyToSendOfTlsClientConnection(
    TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx)) == FALSE)
  {
    /* Now switch to the calculated encrypt application traffic key.
     * For that copy the content of the passive key to the active one.
     * The return value can't be processed here.
     * The decrypt was already switched directly after calculating it in TcpIp_TlsCoreCtx_AsyncHandler(). */
    (void)TcpIp_Tls13CoreCtx_CopyKeyAndIv(handshakePassiveEncryptKeyId, handshakeEncryptKeyId);

    /* Reset the tx sequence number, since the key changed. */
    TcpIp_SetRlTxSequenceCounterOfTlsConnectionDyn(TlsConIdx, 0);

    /* The last sequence number is used to get the IV from the CRYPTO_KE_CIPHER_IV element
     * of the CSM Key AdHsTrafficSecret in TcpIp_Tls13CoreCrypto_GenerateAEADBlock128Iv().
     * Normally the last nonce would be written into this element,
     * but TcpIp_Tls13CoreCtx_CalcApplicationKeys writes the newly calculated IV into this element as well.
     * Therefore TcpIp_Tls13CoreCrypto_GenerateAEADBlock128Iv() already gets the IV now.
     * Reset the last tx sequence number to avoid an alteration of the IV
     * in TcpIp_Tls13CoreCrypto_GenerateAEADBlock128Iv(). */
    TcpIp_SetLastRlTxSequenceCounterOfTlsConnectionDyn(TlsConIdx, 0);

    /* The TX Read index is not used during handshake, so set it to the current position of the write index. */
    TcpIp_SetTlsBufferTxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, txAdHsWriteIdx);

    if (TcpIp_IsTlsClearBufferAfterHandshakeOfTlsConfig(TCPIP_TLSCONFIG_IDX) == TRUE)
    {
      /* #10 Clear the TLS TxBuffer if configured */
      if (   (txAdHsStartIdx < TcpIp_GetSizeOfTlsBufferTx())
          && (txAdHsReadIdx < TcpIp_GetSizeOfTlsBufferTx())
          && (txAdHsStartIdx <= txAdHsReadIdx))
      {
        /* Clear the handshake data in the TxBuffer from StartIdx to current ReadIdx / WriteIdx */
        TcpIp_TlsCoreBuffer_ClearTxBuffer(txAdHsStartIdx, txAdHsReadIdx);
      }

      /* #20 Clear the TLS RxBuffer if configured */
      if (   (rxAdHsStartIdx < TcpIp_GetSizeOfTlsBufferRx())
          && (rxAdHsReadIdx < TcpIp_GetSizeOfTlsBufferRx())
          && (rxAdHsStartIdx <= rxAdHsReadIdx))
      {
        /* Clear the handshake data in the RxBuffer from StartIdx to current ReadIdx */
        /* retVal can't be processed here, but a Det error is reported inside the function */
        (void)TcpIp_TlsCoreBuffer_ClearRxBuffer(rxAdHsStartIdx, rxAdHsReadIdx);
      }
    }

    /* Reset RxBuffer read indices to the start index of the buffer. */
    TcpIp_SetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
      TcpIp_GetTlsBufferRxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx));
    TcpIp_SetTlsBufferRxUlRxIndIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
      TcpIp_GetTlsBufferRxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx));
    /* The Rx Write index is not used during handshake,
    so set it to the current position of the read index = start index */
    TcpIp_SetTlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
      TcpIp_GetTlsBufferRxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx));

    /* Switch the state from FINALIZING to ESTABLISHED */
    TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CONNECTION_ESTABLISHED);
    /* #30 Handshake is done - set state accordingly */
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_DONE);

    /* #40 Notify Upper layer via TcpConnected callback over the established TLS connection */
    TcpIp_TlsCoreUl_TcpConnected(TlsConIdx);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
  /* #50 Remove all loaded certificates by overwriting them with zeros. The root certificate ID was already stored after parsing the ServerCertificate message. */
    TcpIp_TlsCore_RemoveLoadedCerts(TlsConIdx);
#   endif
  } /* else - Just wait for the ClientFinished to be send */
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientCtx_AsyncHandler
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientCtx_AsyncHandler(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx
    = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the trigger for the different ASYNC operations and execute the operation if the trigger is set */

  /* Execute the finished hash operation if the corresponding trigger flag is set */
  if (TcpIp_IsCalcClientFinishedHashAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx) == TRUE)
  {
    /* Calculate the VerifyData for the either the ClientFinished or the ServerFinished message */
    if (TcpIp_Tls13Client_CalculateFinishedVerifyData(TlsConIdx) == E_OK)
    {
      /* hash and verify calculated - reset context state */
      TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);
      TcpIp_SetCalcClientFinishedHashAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
    }
    else
    {
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
      TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_ABORT);
    }

  }

  if (TcpIp_IsCalcFinishedKeyAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx) == TRUE)
  {
    /* Calculate the FinishedKey for the ClientFinished message. */
    if (TcpIp_Tls13Client_CalculateFinishedKey(TlsConIdx) == E_OK)
    {
      /* key calculated - reset context state */
      TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);
      TcpIp_SetCalcFinishedKeyAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
    }
    else
    {
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
      TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_ABORT);
    }
  }

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
  if (TcpIp_IsCertificateStatusOcspValidationAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx) == TRUE)
  {
    TcpIp_TlsClientMsg_CheckPreconditionAndTriggerValidateCertificateStatus(TlsConIdx, TCPIP_TLSVERSION_13);
  }

  /* Execute the client CertificateVerify async signature generation */
  if (TcpIp_IsCalcClientCertVerifySignatureAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx) == TRUE)
  {
    /* Calculate the signature */
    TcpIp_Tls13Client_CalcClientCertVerifySignature(TlsConIdx);

    /* Signature generate - reset context state */
    TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);
    TcpIp_SetCalcClientCertVerifySignatureAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
  }

  /* Execute the verification of the CertificateVerify signature */
  if (TcpIp_IsVerifyCertVerifySignatureAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx) == TRUE)
  {
    /* Verify Signature of the received CertificateVerify message */
    TcpIp_Tls13Client_PerformVerificationOfServerCertVerifySignature(TlsConIdx);

    /* Signature verify - reset context state */
    TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);
    TcpIp_SetVerifyCertVerifySignatureAsyncFlagOfTlsClientConnection(tlsClientConnectionIdx, FALSE);
  }
#   endif
}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientCtx_CalcPskValueAndBinder
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientCtx_CalcPskValueAndBinder(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Calculate PSK value. */
  if (TcpIp_Tls13CoreCtx_CalcPskValue(TlsConIdx) == E_OK)
  {
    TcpIp_Tls13PskIdentityActiveIdxOfTlsConnectionDynType tls13PskIdentityIdx
      = TcpIp_GetTls13PskIdentityActiveIdxOfTlsConnectionDyn(TlsConIdx);

    uint8 hashLen = TcpIp_GetHashLengthOfTls13PskIdentityDyn(tls13PskIdentityIdx);

    /* #20 Derive binder key. */
    if (TcpIp_Tls13CoreCtx_DerivePskBinderKey(TlsConIdx, hashLen) == E_OK)
    {
      TcpIp_CsmJobIdType macGenerateJobId = TcpIp_GetPskMacGenerateCsmJobIdOfTls13PskIdentity(tls13PskIdentityIdx);

      /* #30 Calculate binder. */
      if (TcpIp_Tls13Client_CalculateVerifyData(TlsConIdx, macGenerateJobId, hashLen) != E_OK)
      {
        /* Handle error while async CSM processing */
        TcpIp_TlsAsyncCtx_HandleErrorDuringAsyncJobProcessing(TlsConIdx,
          TCPIP_TLS_FCTID_CORE_ASYNCCTX_CALC_PSKANDBINDER, TCPIP_TLS_ERRORID_CRYPTO_CALCHMAC_FAILED);
      }
    }
    else
    {
      /* Handle error while async CSM processing */
      TcpIp_TlsAsyncCtx_HandleErrorDuringAsyncJobProcessing(TlsConIdx,
        TCPIP_TLS_FCTID_CORE_ASYNCCTX_CALC_PSKANDBINDER, TCPIP_TLS_ERRORID_CRYPTO_DERIVEKEYS_FAILED);
    }
  }

  /* Reset async flag, Set the async state to DONE */
  TcpIp_SetCalcPskValueAsyncFlagOfTlsConnectionDyn(TlsConIdx, FALSE);
  TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);
} /* TcpIp_Tls13ClientCtx_CalcPskValueAndBinder() */

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13ClientCtx_AddPubKeyToKeyShareExtension
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientCtx_AddPubKeyToKeyShareExtension(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsClientConnectionIdxOfTlsConnectionType tlsClientConnectionIdx
    = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsHandshakeIterType tlsHandshakeIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get a handshake index which has a matching elliptic curve Id configured. */
  if (TcpIp_Tls13ClientCtx_GetHandshakeIterTypeFromCurveId(TlsConIdx,
    TcpIp_GetDhPubKeyKeyShareExtCurveAsyncTriggerOfTlsConnectionDyn(TlsConIdx), &tlsHandshakeIdx) == E_OK)
  {
    TcpIp_IncIdxForNextGroupToCalculatePubKeyOfTlsClientConnection(tlsClientConnectionIdx);
    /* #20 Calculate and add the public key to the extension. */
    TcpIp_TlsCoreCtx_CalcDiffieHellmanPublicKey(TlsConIdx, tlsHandshakeIdx);
    TcpIp_SetDhPubKeyKeyShareExtCurveAsyncTriggerOfTlsConnectionDyn(TlsConIdx, TCPIP_CURVE_ID_NO_CURVE);
  }
  else
  {
    TCPIP_ASSERT_UNREACHABLE();
  }
} /* TcpIp_Tls13ClientCtx_AddPubKeyToKeyShareExtension() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientCtx_GetHandshakeIterTypeFromCurveId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientCtx_GetHandshakeIterTypeFromCurveId(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsEllipticCurveIdType CurveId,
  TCPIP_P2V(TcpIp_TlsHandshakeIterType) MatchingHandshakeIterPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerIndIterType tlsCipherWorkerIndIdx;
  Std_ReturnType retVal = E_NOT_OK;
  boolean foundMatchingHandshake = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over every configured cipher worker */
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

      /* #40 If the curve Id matches the passed curve Id, stop iterating and save the handshakeIdx */
      if (currentEllipticCurveId == CurveId)
      {
        *MatchingHandshakeIterPtr = tlsHandshakeIdx;
        retVal = E_OK;
        foundMatchingHandshake = TRUE;
        break;
      }
    }
    if (foundMatchingHandshake == TRUE)
    {
      break;
    }
  }

  return retVal;
} /* TcpIp_Tls13ClientCtx_GetHandshakeIterTypeFromCurveId() */

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_PerformVerificationOfServerCertVerifySignature
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13Client_PerformVerificationOfServerCertVerifySignature(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if transcript hash could be calculated */
  if (TcpIp_Tls13Client_CalculateHashOfHsMessagesWithActiveCipherHashLength(TlsConIdx) == E_OK)
  {
    /* #20 Yes: Verify the signature */
    retVal = TcpIp_Tls13ClientCrypto_VerifyServerCertVerifySignature(TlsConIdx);
  }

  /* #30 Check if an error occurred */
  if (retVal != E_OK)
  {
    /* #40 Raise alert that an internal error occurred */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_ABORT);
  }
} /* TcpIp_Tls13Client_PerformVerificationOfServerCertVerifySignature() */

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_CalcClientCertVerifySignature
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13Client_CalcClientCertVerifySignature(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Prepare the transcript hash */
  retVal = TcpIp_Tls13Client_CalculateHashOfHsMessagesWithActiveCipherHashLength(TlsConIdx);

  /* #20 If transcript hash could be calculated then generate the signature */
  if (retVal == E_OK)
  {
    retVal = TcpIp_Tls13ClientCrypto_CalcClientCertVerifySignatureSignedData(TlsConIdx);
  }

  /* #30 If an error occurred then raise alert that an internal error occurred */
  if (retVal != E_OK)
  {
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_ABORT);
  }
} /* TcpIp_Tls13Client_CalcClientCertVerifySignature() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientCrypto_VerifyServerCertVerifySignature
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientCrypto_VerifyServerCertVerifySignature(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

  TCPIP_P2C(uint8) hsHashDestPtr = TcpIp_GetAddrTlsTemporaryHashBuffer(
    TcpIp_GetTlsTemporaryHashBufferStartIdxOfTlsConnection(TlsConIdx));

  TcpIp_TlsTemporarySignatureBufferStartIdxOfTlsConnectionType receivedSigStartIdx =
    TcpIp_GetTlsTemporarySignatureBufferStartIdxOfTlsConnection(TlsConIdx);

  uint8 signedContent[TCPIP_TLS_CIPHERSUITE_MAX_HASH_LEN + TCPIP_TLS_CERTIFICATEVERIFY_CONTEXT_LEN] = { 0 };

  TcpIp_SegmentType signedContentSegment;
  TcpIp_SegmentType signatureBufferSegment;

  Std_ReturnType retVal = E_NOT_OK;
  Crypto_VerifyResultType verifyResult = CSM_E_VER_NOT_OK;
  uint8 hsHashLen = 0u;
  uint32 signLen = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Perform necessary checks before signature verification can be started. */
  if (TcpIp_TlsCoreUtil_PreVerifySignatureChecks(TlsConIdx) == E_OK)
  {
    /* The memory access for the signature and its length field are valid, the index check was performed in
     * TcpIp_Tls13ClientHsStm_ParseCertificateVerifyMsg(). */
    TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);
    TcpIp_SignatureAlgorithmIdType signatureAlgorithmId = TcpIp_GetSignatureAlgorithmIdOfTlsHandshake(activeTlsHandshakeIdx);
    TcpIp_TlsBufferRxIterType signatureBufferIdx = TcpIp_GetTlsBufferRxServerSignatureIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);
    TcpIp_TlsBufferRxIterType signatureLenBufferIdx = TcpIp_GetTlsBufferRxServerSignatureLenIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx);

    /* If dynamic certificate groups are used, the Csm signature verify job reference cannot be determined from a
     * static configured handshake container. This is because only at runtime you know in which certificate slot
     * KeyM will store the leaf certificate, which is the first received certificate according to RFC8446 4.4.2.
     * Therefore get the certificate ID of the first received certificate and its configured Csm job Id.
     * Both is stored in TlsKeyMCertificate. */
    const TcpIp_TlsKeyMCertificateIterType tlsKeyMCertificateIdx
      = (TcpIp_TlsKeyMCertificateIterType)(TcpIp_GetAddrTlsCertValidationStatusDyn(
          TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx))->CertId);
    const TcpIp_CsmJobIdType signatureVerifyJobId
      = TcpIp_GetCsmCertSignVerifyJobIdOfTlsKeyMCertificate(tlsKeyMCertificateIdx);

    /* Create a buffer segment for the signature. */
    TcpIp_SegmentInit(&signatureBufferSegment, TcpIp_GetAddrTlsTemporarySignatureBuffer(receivedSigStartIdx),           /* TCPIP_CSL_NAME_LENGTH */
      TCPIP_TLS_MAX_SIGNATURE_LEN);

    /* #20 Decode the received signature */
    if (TcpIp_TlsCoreMsg_DecodeSignature(&signatureBufferSegment, signatureAlgorithmId, signatureBufferIdx, signatureLenBufferIdx) == E_OK)
    {
      /* Get the decoded signature length (just check how many bytes are occupied in the buffer after decoding). */
      signLen = signatureBufferSegment.Usage;
      retVal = E_OK;
    }
    else
    {
      /* Unable to decode the signature, set decrypt_error alert, retVal already E_NOT_OK */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECRYPT_ERROR);
    }

    /* #30 Verify the received signature */
    if (retVal == E_OK)
    {
      retVal = TcpIp_Tls13Core_GetHashLengthOfActiveCipherSuite(TlsConIdx, &hsHashLen);
      if (retVal == E_OK)
      {
        /* Create a buffer segment for the signed content. */
        TcpIp_SegmentInit(&signedContentSegment, &signedContent[0],
          TCPIP_TLS_CIPHERSUITE_MAX_HASH_LEN + TCPIP_TLS_CERTIFICATEVERIFY_CONTEXT_LEN);

        /* Build the signed content into the buffer segment. */
        TcpIp_Tls13ClientCrypto_BuildCertVerifySignedContent(TlsConIdx, &signedContentSegment);
        /* Add the calculated hash to the buffer segment. */
        TcpIp_SegmentMemCpy(&signedContentSegment, hsHashDestPtr, hsHashLen);

        /* Verify the signature. */
        /* This has to be done as single call otherwise the Ed25519 won't work. */
        retVal = TCPIP_CSM_SignatureVerify(signatureVerifyJobId, CRYPTO_OPERATIONMODE_SINGLECALL,
          signedContentSegment.BasePtr, signedContentSegment.Usage,
          signatureBufferSegment.BasePtr, signLen, &verifyResult);
      }
    }

    /* #40 Check if the verification was successful */
    if (verifyResult == CSM_E_VER_NOT_OK)
    {
      /* Invalid Signature - trigger TLS Alert */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECRYPT_ERROR);
      retVal = E_NOT_OK;
    }
  }

  return retVal;
} /* TcpIp_Tls13ClientCrypto_VerifyServerCertVerifySignature() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientCrypto_BuildCertVerifySignedContent
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientCrypto_BuildCertVerifySignedContent(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType SegmentPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 iterator = 0u;
  TcpIp_TlsHandshakeState handshakeState = TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx);
  TcpIp_TlsHandshakeState handshakeStateGroup = TCPIP_TLS_GET_HS_STATE(handshakeState);

  /* ----- Implementation ----------------------------------------------- */
  /* RFC 8446 chapter 4.4.3 states that the content to be signed exists of octet "32" string repeated 64 times,
   * followed by the context string, followed by 0x00.
   * The context string for a server signature is "TLS 1.3, server CertificateVerify".
   * The context string for a client signature is "TLS 1.3, client CertificateVerify". */
  /* #10 Add octet "32" string 64 times. */
  for (iterator = 0u; iterator < TCPIP_TLS_CERTIFICATEVERIFY_REPEATEDOCTET_LEN; iterator++)
  {
    TcpIp_SegmentMemSet(SegmentPtr, TCPIP_TLS_CERTIFICATEVERIFY_REPEATEDOCTET, 1u);
  }

  /* #20 Check if the content is build to verify a server's CertificateVerify or to send a client's CertificateVerify. */
  if (handshakeStateGroup == TCPIP_TLS_STATE_WAIT_FOR_SERVER_CERTIFICATE_VERIFY)
  {
    /* #30 Add context string "TLS 1.3, server CertificateVerify". */
    TcpIp_SegmentMemCpy(SegmentPtr, &TcpIp_Tls13_ServerCertificateVerifyContextString[0],
      TCPIP_TLS_CERTIFICATEVERIFY_CONTEXTSTRING_LEN);
  }
  else if (handshakeStateGroup == TCPIP_TLS_STATE_SEND_CLIENT_CERTIFICATE_VERIFY)
  {
    /* #40 Add context string "TLS 1.3, client CertificateVerify". */
    TcpIp_SegmentMemCpy(SegmentPtr, &TcpIp_Tls13_ClientCertificateVerifyContextString[0],
      TCPIP_TLS_CERTIFICATEVERIFY_CONTEXTSTRING_LEN);
  }
  else
  {
    /* Function called in an invalid state, this should never happen. Do not copy anything. */
  }

  /* #50 Add the separator value 0x00. */
  TcpIp_SegmentMemSet(SegmentPtr, TCPIP_TLS_CERTIFICATEVERIFY_SEPARATOR, TCPIP_TLS_CERTIFICATEVERIFY_SEPARATOR_LEN);

}

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientCrypto_CalcClientCertVerifySignatureSignedData
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientCrypto_CalcClientCertVerifySignatureSignedData(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* Implements the signature generation according to RFC 8446  section 4.4.3. */
  /* ----- Local Variables ---------------------------------------------- */
  uint8 signedContent[TCPIP_TLS_CERTIFICATEVERIFY_CONTEXT_LEN + TCPIP_TLS_CIPHERSUITE_MAX_HASH_LEN] = { 0 };
  uint8 hashLength = 0u;
  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Create a buffer segment for the signed content. */
  TcpIp_SegmentType signedContentSegment;
  TcpIp_SegmentInit(&signedContentSegment, &signedContent[0],
    TCPIP_TLS_CIPHERSUITE_MAX_HASH_LEN + TCPIP_TLS_CERTIFICATEVERIFY_CONTEXT_LEN);
  /* #20 Build the static content to be signed in the segment. */
  TcpIp_Tls13ClientCrypto_BuildCertVerifySignedContent(TlsConIdx, &signedContentSegment);

  /* #30 Fetch the hash length of the active cipher suite */
  retVal = TcpIp_Tls13Core_GetHashLengthOfActiveCipherSuite(TlsConIdx, &hashLength);

  if (retVal == E_OK)
  {
    const TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx
      = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

    const TcpIp_CsmJobIdType signatureGenerateJobId
      = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdKeyExchangeSignatureGenerateIdxOfTlsHandshake(activeTlsHandshakeIdx));

    const TcpIp_TlsTemporarySignatureBufferStartIdxOfTlsConnectionType startTlsTemporarySignatureBufferIdx
      = TcpIp_GetTlsTemporarySignatureBufferStartIdxOfTlsConnection(TlsConIdx);

    const TcpIp_TlsTemporarySignatureBufferEndIdxOfTlsConnectionType tmpSignatureBufferEndIdx
      = TcpIp_GetTlsTemporarySignatureBufferEndIdxOfTlsConnection(TlsConIdx);

    TCPIP_CP2V(uint8) generatedSignatureDestPtr = TcpIp_GetAddrTlsTemporarySignatureBuffer(startTlsTemporarySignatureBufferIdx);

    uint32 generatedSignatureDestLen = (((uint32)tmpSignatureBufferEndIdx - startTlsTemporarySignatureBufferIdx));
    /* The temporary hash buffer is filled in another function (TcpIp_Tls13Client_FinalizeHashOfHsMessages).
     * Here the result is used only. */
    const TcpIp_TlsTemporaryHashBufferStartIdxOfTlsConnectionType startTlsTemporaryHashBufferIdx
      = TcpIp_GetTlsTemporaryHashBufferStartIdxOfTlsConnection(TlsConIdx);

    TCPIP_P2C(uint8) transcriptHashPtr = TcpIp_GetAddrTlsTemporaryHashBuffer(startTlsTemporaryHashBufferIdx);


    /* Here the transcript hash is copied into the local array to reduce number of
     * Csm calls. Drawback is an additional copy operation that has to be performed
     * here, but usually this is less expensive than multiple Csm calls. */
    /* #40 Add the calculated hash to the buffer segment. */
    TcpIp_SegmentMemCpy(&signedContentSegment, transcriptHashPtr, hashLength);

    /* #50 Trigger signature generation */
    retVal = TCPIP_CSM_SignatureGenerate(signatureGenerateJobId, CRYPTO_OPERATIONMODE_SINGLECALL,
                signedContentSegment.BasePtr, signedContentSegment.Usage,
                generatedSignatureDestPtr, &generatedSignatureDestLen);
  }

  return retVal;
} /* TcpIp_Tls13ClientCrypto_CalcClientCertVerifySignatureSignedData() */
#   endif

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ParseExtensions
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ParseExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 ExtensionLen,
  TCPIP_P2V(TcpIp_TlsExtensionType) ExtensionsPtr,
  TCPIP_P2V(uint8) ExtensionsPtrCnt)
{
  /* Implements the parsing of a list of extensions.
   *
   * Data type of Extension according to RFC 8446:
   *  Extension extensions<0..2^16-1>
   *
   * Limitations:
   *  - In case a minimum number of bytes is specified, this
   *    needs to be ensured by caller.
   */

  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsBufferMgmtIterType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  uint16_least remainingLen = ExtensionLen;
  uint8_least extListIdx = 0u;
  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over the extension data and extract each extension into overall list of received extensions */
  for (extListIdx = 0u; ((remainingLen != 0u) && (extListIdx < (uint8_least)*ExtensionsPtrCnt)); extListIdx++)
  {
    const TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType extensionStartIdx
      = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

    retVal = TcpIp_Tls13ClientMsg_ParseExtension(TlsConIdx,
                extensionStartIdx, (uint16)remainingLen,
                &ExtensionsPtr[extListIdx]);

    if (retVal == E_OK)
    {
      const TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType currentReadIdx
        = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

      remainingLen -= (uint16)(currentReadIdx - extensionStartIdx);
    }
    else
    {
      break;
    }
  }

  /* #20 If additional data is present, raise alert that decoding was not successful */
  if (remainingLen != 0u)
  {
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
    retVal = E_NOT_OK;
  }
  /* #30 Otherwise propagate length information to caller */
  else
  {
    *ExtensionsPtrCnt = (uint8)extListIdx;
  }

  return retVal;
} /* TcpIp_Tls13ClientMsg_ParseExtensions() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ParseExtension
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ParseExtension(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferRxIterType ExtensionStartTlsBufferRxIdx,
  uint16 AvailableInputDataLen,
  TCPIP_P2V(TcpIp_TlsExtensionType) ParsedExtensionPtr)
{
  /* Implements the parsing of single entries of extensions which is part
   * of a CertificateRequest message according to RFC 8466 section 4.3.2.
   *
   * Data type of Extension according to  RFC 8446 section 4.2:
   *  struct {
   *     ExtensionType extension_type;
   *     opaque extension_data<0..2^16-1>;
   *  } Extension;
   *
   */

  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsBufferMgmtIterType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  const uint32 extensionMinimalLen =
    (TCPIP_TLS_EXTENSION_TYPE_LEN + TCPIP_TLS_EXTENSIONDATALEN_LEN);

  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if sufficient input data is available */
  if (AvailableInputDataLen >= extensionMinimalLen)
  {
    /* #20 Read extension type and data len */
    const uint16 extensionType = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(ExtensionStartTlsBufferRxIdx), 0u);
    const uint16 extensionDataLen = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(ExtensionStartTlsBufferRxIdx),
      TCPIP_TLS_EXTENSION_TYPE_LEN);

    TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
      (TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType)extensionMinimalLen);

    /* Sanity check of extension length is performed here instead in
     * each supported extension so that it needs to be checked only once */
    /* #30 Check if amount of bytes available in RX buffer matches extension length */
    if (extensionDataLen > (AvailableInputDataLen - extensionMinimalLen))
    {
      /* #40 No: Invalid extensions data length. More data specified than available - raise alert */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
    }
    else
    {
      /* #50 Yes: Store extension information in passed ParsedExtensionPtr */
      const TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType readIdx =
        TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

      ParsedExtensionPtr->Type = extensionType;
      ParsedExtensionPtr->Length = extensionDataLen;
      ParsedExtensionPtr->StartIdx = readIdx;

      TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
        (TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType)extensionDataLen);

      retVal = E_OK;
    }
  }
  /* #60 Otherwise raise an alert that message violates syntax */
  else
  {
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
  }

  return retVal;
} /* TcpIp_Tls13ClientMsg_ParseExtension() */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerCertRequestMsgCheckSignatureAlgorithmsLengthConsistency
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerCertRequestMsgCheckSignatureAlgorithmsLengthConsistency(
  TCPIP_P2C(TcpIp_TlsExtensionType) TlsExtensionPtr,
  uint16 SignatureAlgorithmsLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Make sure that the 'length' field is available */
  if (TlsExtensionPtr->Length >= TCPIP_TLS_SIGNATURE_ALGORITHMS_LENGTH_LEN)
  {
    /* #20 Check if supported_signature_algorithms length is plausible */
    if ((TCPIP_TLS_SIGNATURE_ALGORITHMS_LENGTH_LEN + SignatureAlgorithmsLength) == TlsExtensionPtr->Length)
    {
      retVal = E_OK;
    }
  }

  return retVal;
} /* TcpIp_Tls13ClientMsg_ServerCertRequestMsgCheckSignatureAlgorithmsLengthConsistency */

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerEncryptedExtensionsParseExtensionSupportedGroups
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerEncryptedExtensionsParseExtensionSupportedGroups(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType SupportedGroupsExtension)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 receivedSupportedGroupsLen = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return E_OK if all lengths are checked and valid */
  /* According to RFC8446 Section 4.2.7:
   * "Clients MUST NOT act upon any information found in "supported_groups" prior to
   * successful completion of the handshake but MAY use the information learned from
   * a successfully completed handshake to change what groups they use in their
   * "key_share" extension in subsequent connections."
   * Since we do not want to store information about the connection endpoint throughout
   * multiple connection establishments we do not do anything with the supported_groups
   * extension, if sent by the server. */
  return TcpIp_TlsCoreUtil_CheckLengthsOfExtensionSupportedGroups(TlsConIdx,
    SupportedGroupsExtension, &receivedSupportedGroupsLen);
}

#   define TCPIP_STOP_SEC_CODE
#   include "TcpIp_MemMap.h"                                                                                            /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SILENTBSW JUSTIFICATIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  COVERAGE JUSTIFICATIONS
 *********************************************************************************************************************/

#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
# endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */
#endif /* (TCPIP_SUPPORT_ASRTLS == STD_ON) */
/**********************************************************************************************************************
 *  END OF FILE: TcpIp_Tls13Client.c
 *********************************************************************************************************************/
