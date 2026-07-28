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
/*!        \file  TcpIp_TlsServer.c
 *        \brief  Transport Layer Security (TLS) 1.2 Server functions implementation.
 *
 *      \details  This file is part of the TcpIp TLS submodule.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp module. >> TcpIp.h
 *********************************************************************************************************************/

#define TCPIP_TLSSERVER_SOURCE
#include "TcpIp_Cfg.h"

#if (TCPIP_SUPPORT_ASRTLS == STD_ON)                                                                                    /* COV_MSR_UNSUPPORTED */
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#   include "TcpIp_Lcfg.h"
#   include "TcpIp_Tls.h"
#   include "TcpIp_Tls12Core.h"
#   include "TcpIp_TlsCoreCommon.h"
#   include "TcpIp_TlsServer.h"
#   include "TcpIp_TlsPriv.h"
#   include "TcpIp_Tcp.h"
#   include "Csm.h"

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
#    include "KeyM.h"
#   endif

#   if (TCPIP_DEV_ERROR_REPORT == STD_ON)
#    include "Det.h"
#   endif


/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#   define TCPIP_TLSSERVER_PUPKEY_COMPRESSION_FLAG 0x04u
#   define TCPIP_TLSSERVER_CERTLEN_LEN 3u
#   define TCPIP_TLSSERVER_CURVETYPE_LEN 1u
#   define TCPIP_TLSSERVER_CUVEID_LEN 2u
#   define TCPIP_TLSSERVER_PUPKEY_COMPRESSION_LEN 1u
#   define TCPIP_TLSSERVER_PUBKEY_NO_COMPRESSION_LEN 0u
#   define TCPIP_TLSSERVER_PUPKEYLEN_LEN 1u
#   define TCPIP_TLSSERVER_PUPKEY_COMPRESSION_FLAG_LEN 1u
#   define TCPIP_TLSSERVER_SIGNATUREALGO_ID_LEN 2u
#   define TCPIP_TLSSERVER_SIGNATURELEN_LEN 2u
#   define TCPIP_TLSSERVER_COMPMETH_LEN 1u
#   define TCPIP_TLSSERVER_COMPMETHLEN_LEN 1u

/* Length of Client/Server Finished length */
#   define TCPIP_TLS_LABEL_FINISHED_LEN 15u

/* Length values of transmittable server messages used for runtime checks */
/* HandshakeOffset = HandshakeLength(3) + HandshakeType(1) */

#   define TCPIP_TLS_MAX_TX_SERVER_HELLO_MESSAGE_LENGTH        200u /* HandshakeOffset(4) + Version(2) + ServerRandom(32) + SessionId(32) + CipherSuiteMax(30) + ExtensionMax(100) */
#   define TCPIP_TLS_MAX_TX_SERVER_SIGNATURE_PARAMS_LENGTH      75u /* SignatureParams = SignatureAlgorithm(2) + SignatureLength(2) + SignatureMax(70) */
#   define TCPIP_TLS_MAX_TX_SERVER_ENCODED_SIGNATURE_LENGTH    100u /* SignatureParams(75) + Asn1Offset(25) */

#   define TCPIP_TLS_MAX_TX_SERVER_PUBKEY_PARAMS_LENGTH         70u /* PubKeyOffset = CurveType(1) + NamedCurve(2) +  PubKeyLength(1) + PubKeyMax(65) */

#   define TCPIP_TLS_MAX_TX_SERVER_KEY_EXCHANGE_MESSAGE_LENGTH 150u /* HandshakeOffset(4) + SignatureParams(75) + PubKeyOffset(70) */

#   define TCPIP_TLS_MAX_TX_SERVER_FINISHED_MESSAGE_LENGTH      16u /* HandshakeOffset(4) + VerifyDateLength(12) */

#   define TCPIP_TLS_MAX_TX_SERVER_CERTIFICATE_REQUEST_MESSAGE_LENGTH (TCPIP_TLS_HSHDRLEN + TCPIP_TLS_CERTREQUEST_CERTTYPESLENGTH_LEN + (TCPIP_TLS_CERTREQUEST_CERTTYPES_AMOUNT*TCPIP_TLS_CERTREQUEST_CERTTYPE_LEN) + TCPIP_TLS_SIGNATURE_ALGORITHMS_LENGTH_LEN + (TCPIP_TLS_SIGNATURE_ALGORITHMS_ALG_ID_LEN*TCPIP_TLS_SIGNATURE_ALGO_AMOUNT) + TCPIP_TLS_DIST_NAMES_LENGTH_LEN + ((TCPIP_TLS_DIST_NAME_LENGTH_LEN + TCPIP_TLS_CERTREQUEST_DISTINGUISHEDNAME_MAXLEN)*TCPIP_TLS_CERTREQUEST_DISTINGUISHEDNAME_AMOUNT))

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#   if !defined (TCPIP_TLS_LOCAL)
#    define TCPIP_TLS_LOCAL static
#   endif

#   if !defined (TCPIP_TLS_LOCAL_INLINE)
#    define TCPIP_TLS_LOCAL_INLINE LOCAL_INLINE
#   endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#   define TCPIP_START_SEC_CODE
#   include "TcpIp_MemMap.h"                                                                                            /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 * TcpIp_TlsServer_InitReadyToSendFlags
 *********************************************************************************************************************/
/*! \brief         Initialize the transmission trigger flags.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServer_InitReadyToSendFlags(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServer_InitHsMsgIndices
 *********************************************************************************************************************/
/*! \brief         Initialize the TLS handshake message indices.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServer_InitHsMsgIndices(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServer_InitHsLenInformation
 *********************************************************************************************************************/
/*! \brief         Initialize the TLS handshake message length information.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServer_InitHsLenInformation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServer_InitAsyncFlags
 *********************************************************************************************************************/
/*! \brief         Initialize the asynchronous trigger flags.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServer_InitAsyncFlags(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsServer_InitOtherFlags
 *********************************************************************************************************************/
/*! \brief         Initialize miscellaneous flags.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServer_InitOtherFlags(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerTx_ForwardProcessedHsMsgToRl
 *********************************************************************************************************************/
/*! \brief         Forwards the processed TLS handshake message to the record layer for transmission.
 *  \details       The TLS-Client handshake message is specified through the HandshakeType parameter.
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *                 HandshakeType           Type of the handshake message which should be forwarded
 *  \return        TRUE                    TLS message was forwarded to the record layer
 *  \return        FALSE                   TLS message was NOT forwarded to the record layer
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsServerTx_ForwardProcessedHsMsgToRl(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(TcpIp_TlsMsgHandshakeType, AUTOMATIC) HandshakeType);

/**********************************************************************************************************************
 *   TLS SERVER HANDSHAKE STATE MACHINE
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsServerHsStm_PerformNextHsStep
 *********************************************************************************************************************/
/*! \brief         Main function to process the TLS handshake for the TLS-Server.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_PerformNextHsStep(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerHsStm_ParseClientHello
 *********************************************************************************************************************/
/*! \brief         Extract and parse the content of the received ClientHello message.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_ParseClientHello(
  TcpIp_TlsConnectionIterType TlsConIdx);

#   if (TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON)                                                                       /* COV_MSR_UNSUPPORTED */
/**********************************************************************************************************************
 *  TcpIp_TlsServerHsStm_ParseClientHelloFindPskHandshake
 *********************************************************************************************************************/
/*! \brief         Check if the referenced handshake uses a PSK cipher.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        TRUE                    A matching handshake was found
 *  \return        FALSE                   No matching handshake was found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsServerHsStm_ParseClientHelloFindPskHandshake(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif /* PSK */

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)                                                                             /* COV_MSR_UNSUPPORTED */
/**********************************************************************************************************************
 *  TcpIp_TlsServerHsStm_ParseClientHelloFindEcdsaHandshake
 *********************************************************************************************************************/
/*! \brief         Find a matching free handshake with an available certificate.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        TRUE                    A matching handshake was found
 *  \return        FALSE                   No matching handshake was found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsServerHsStm_ParseClientHelloFindEcdsaHandshake(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsServerHsStm_CheckHandshakesForMatchingCert
 *********************************************************************************************************************/
/*! \brief         Check if the passed handshake is compatible with the received ClientHello
 *                 and if a matching certificate can be found. If so, set the handshake as active.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     TlsCipherWorkerIdx      TLS cipherworker index
 *                                         \spec requires TlsCipherWorkerIdx < TcpIp_GetSizeOfTlsCipherWorker(); \endspec
 *  \param[in]     TlsHandshakeIdx         TLS handshake index
 *                                         \spec requires TlsHandshakeIdx < TcpIp_GetSizeOfTlsHandshake(); \endspec
 *  \return        TRUE                    A matching handshake and certificate was found
 *  \return        FALSE                   No matching handshake and certificate was found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsServerHsStm_CheckHandshakesForMatchingCert(
  TcpIp_TlsConnectionIterType     TlsConIdx,
  TcpIp_TlsCipherWorkerIterType   TlsCipherWorkerIdx,
  TcpIp_TlsHandshakeIterType      TlsHandshakeIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsServerHsStm_ParseClientHelloCheckForMatchingCert
 *********************************************************************************************************************/
/*! \brief         Find a free handshake with an available and matching certificate.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     TlsHandshakeIdx         TLS handshake index
 *                                         \spec requires TlsHandshakeIdx < TcpIp_GetSizeOfTlsHandshake(); \endspec
 *  \return        TRUE                    A matching handshake and certificate was found
 *  \return        FALSE                   No matching handshake and certificate was found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsServerHsStm_ParseClientHelloCheckForMatchingCert(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsHandshakeIterType TlsHandshakeIdx);
#   endif /* ECC */

/**********************************************************************************************************************
 * TcpIp_TlsServerHsStm_ParseClientKeyExchange
 *********************************************************************************************************************/
/*! \brief         Extract and parse the content of the received ClientKeyExchange message.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_ParseClientKeyExchange(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerHsStm_ParseClientCcs
 *********************************************************************************************************************/
/*! \brief         Extract and parse the content of the received Client ChangeCipherSpec message.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_ParseClientCcs(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerHsStm_ExtractClientFinished
 *********************************************************************************************************************/
/*! \brief         Extract and parse the content of the received ClientFinished message.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerHsStm_ExtractClientFinished(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerHsStm_SendServerHello
 *********************************************************************************************************************/
/*! \brief         Prepare and trigger the transmission of the ServerHello message.
 *  \details       Transmission is done in context of TcpIp_TlsServerTx_ForwardProcessedHsMsgToRl()
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_SendServerHello(
  TcpIp_TlsConnectionIterType TlsConIdx);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsServerHsStm_SendServerCertificate
 *********************************************************************************************************************/
/*! \brief         Prepare and trigger the transmission of the ServerCertificate message.
 *  \details       Transmission is done in context of TcpIp_TlsServerTx_ForwardProcessedHsMsgToRl()
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_SendServerCertificate(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 * TcpIp_TlsServerHsStm_SendServerKeyExchange
 *********************************************************************************************************************/
/*! \brief         Prepare and trigger the transmission of the ServerKeyExchange message.
 *  \details       Transmission is done in context of TcpIp_TlsServerTx_ForwardProcessedHsMsgToRl()
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_SendServerKeyExchange(
  TcpIp_TlsConnectionIterType TlsConIdx);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsServerHsStm_SendCertificateRequest
 *********************************************************************************************************************/
/*! \brief         Prepare and trigger the transmission of the CertificateRequest message.
 *  \details       Transmission is done in context of TcpIp_TlsServerTx_ForwardProcessedHsMsgToRl()
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_SendCertificateRequest(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 * TcpIp_TlsServerHsStm_SendServerHelloDone
 *********************************************************************************************************************/
/*! \brief         Prepare and trigger the transmission of the ServerHelloDone message.
 *  \details       Transmission is done in context of TcpIp_TlsServerTx_ForwardProcessedHsMsgToRl()
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_SendServerHelloDone(
  TcpIp_TlsConnectionIterType TlsConIdx);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsServerHsStm_ParseClientCertificate
 *********************************************************************************************************************/
/*! \brief         Parse the client's Certificate message
 *  \details       -
 *  \param[in]     TlsConIdx     TLS connection index
 *                               \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_ParseClientCertificate(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerHsStm_ParseClientCertificateVerify
 *********************************************************************************************************************/
/*! \brief         Parse the client's CertificateVerify message
 *  \details       -
 *  \param[in]     TlsConIdx     TLS connection index
 *                               \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_ParseClientCertificateVerify(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 * TcpIp_TlsServerHsStm_ParseClientFinished
 *********************************************************************************************************************/
/*! \brief         Extract and verify the content of the received ClientFinished message.
 *  \details       -
 *  \param[in]     TlsConIdx     TLS connection index
 *                               \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_ParseClientFinished(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerHsStm_SendServerCcs
 *********************************************************************************************************************/
/*! \brief         Prepare and trigger the transmission of the ServerChangeCipherSpec message.
 *  \details       Transmission is done in context of TcpIp_TlsServerTx_ForwardProcessedHsMsgToRl()
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_SendServerCcs(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerHsStm_SendServerFinished
 *********************************************************************************************************************/
/*! \brief         Prepare and trigger the transmission of the ServerFinished message.
 *  \details       Transmission is done in context of TcpIp_TlsServerTx_ForwardProcessedHsMsgToRl()
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_SendServerFinished(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerHsStm_FinalizeHandshake
 *********************************************************************************************************************/
/*! \brief         Finalize the TLS handshake for the TLS-Server and prepare TLS buffer for application data.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_FinalizeHandshake(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerHsStm_VerifyExpectedMinimumMsgLen
 *********************************************************************************************************************/
/*! \brief         Compare the received TLS message length with the expected one.
 *  \details       -
 *  \param[in]     MsgLen               Received message length
 *  \param[in]     ExpectedMsgLen       Expected message length
 *  \return        E_OK                 Length match
 *  \return        E_NOT_OK             Length mismatch
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerHsStm_VerifyExpectedMinimumMsgLen(
  CONST(uint32, AUTOMATIC) MsgLen,
  CONST(uint32, AUTOMATIC) ExpectedMsgLen);

/**********************************************************************************************************************
 * TcpIp_TlsServerHsStm_HandleErrorDuringPreparation
 *********************************************************************************************************************/
/*! \brief         Handles error reporting during preparation of TLS handshake messages.
 *  \details       Generic function, which is called when an error occurs during the preparation of any handshake message
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_HandleErrorDuringPreparation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TLS SERVER HANDSHAKE MESSAGE HANDLING
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ExtractClientHelloInformation
 *********************************************************************************************************************/
/*! \brief         Extract and verify the information of the ClientHello message.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Operation successful
 *  \return        E_NOT_OK                Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ExtractClientHelloInformation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ExtractClientKeyExchangeInformation
 *********************************************************************************************************************/
/*! \brief         Extract and verify the key information of the ClientKeyExchange message.
 *  \details       Depending on the selected key exchange, the ECC or PSK key information is extracted
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Operation successful
 *  \return        E_NOT_OK                Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ExtractClientKeyExchangeInformation(
  TcpIp_TlsConnectionIterType TlsConIdx);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ExtractClientCertificateInformation
 *********************************************************************************************************************/
/*! \brief         Extract the information of the client's Certificate message.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Operation successful
 *  \return        E_NOT_OK                Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ExtractClientCertificateInformation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientCertMsgProcessCertChain
 *********************************************************************************************************************/
/*! \brief         Process the certificate chain in the received client certificate message
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientCertMsgProcessCertChain(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientCertMsgParseAndTriggerVerification
 *********************************************************************************************************************/
/*! \brief         Extract certificates from client certificate message and trigger verification if possible
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientCertMsgParseAndTriggerVerification(
  TcpIp_TlsConnectionIterType         TlsConIdx,
  TcpIp_TlsBufferRxIterType           CertStartIdx,
  uint8                               NumCerts);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientCertMsgCheckSigHashAlgo
 *********************************************************************************************************************/
/*! \brief         Check that the received client leaf certificate is signed
 *                 with a signature algorithm contained in the sent CertificateRequest message
 *  \details       The Id of the signature algorithm is saved in the CSL
 *  \param[in]     TlsConIdx                       TLS connection index
 *                                                 \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                            A valid signature algorithm was used for the signature of the leaf
 *  \return        E_NOT_OK                        An invalid signature was used
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientCertMsgCheckSigHashAlgo(
  TcpIp_TlsConnectionIterType         TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientCertMsgHandleFailedCertGroupValidation
 *********************************************************************************************************************/
/*! \brief         This function is called if the certificate group validation failed
 *  \details       -
 *  \param[in]     TlsConIdx                       TLS connection index
 *                                                 \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ClientCertMsgHandleFailedCertGroupValidation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientCertMsgVerifyCertificateGroup
 *********************************************************************************************************************/
/*! \brief         Verify the certificate group that was loaded into KeyM
 *  \details       The client certificate chain is loaded into the KeyM certificate group
 *  \param[in]     TlsConIdx         TLS connection index
 *                                   \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK              Verifying the cert group succeeded.
 *                 E_NOT_OK          Verifying the cert group failed.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientCertMsgVerifyCertificateGroup(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientCertMsgCheckCertChainOverallResult
 *********************************************************************************************************************/
/*! \brief         Check result of cert chain validation and call validation callback if necessary
 *  \details       -
 *  \param[in]     TlsConIdx         TLS connection index
 *                                   CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     Result            Overall validation result
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ClientCertMsgCheckCertChainOverallResult(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_CertValidationResultType Result);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ExtractClientCertificateVerifyInformation
 *********************************************************************************************************************/
/*! \brief         Extract and verify the information of the client's CertificateVerify message.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Operation successful
 *  \return        E_NOT_OK                Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ExtractClientCertificateVerifyInformation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientCertificateVerifyGetParams
 *********************************************************************************************************************/
/*! \brief         Get client parameters from the CertificateVerify message.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Operation successful
 *  \return        E_NOT_OK                Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientCertificateVerifyGetParams(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ExtractClientFinishedInformation
 *********************************************************************************************************************/
/*! \brief         Extract and verify the information of the ClientFinished message.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Operation successful
 *  \return        E_NOT_OK                Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ExtractClientFinishedInformation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_CalcClientFinishedHash
 *********************************************************************************************************************/
/*! \brief         Trigger calculation of the hash value of all received and transmitted TLS handshake messages.
 *  \details       The calculation of the hash is performed in the TcpIp_TlsServerCtx_AsyncHandler() background task.
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_CalcClientFinishedHash(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_CalcClientFinishedVerifyData
 *********************************************************************************************************************/
/*! \brief         Trigger calculation of the finished verify data via the TLS PRF.
 *  \details       The calculation of the hash is performed in the TcpIp_TlsServerCtx_AsyncHandler() background task.
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_CalcClientFinishedVerifyData(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_CompareFinishedVerifyData
 *********************************************************************************************************************/
/*! \brief         Compares the calculated finished verify data with the received one from the TLS-Client.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Both values match
 *  \return        E_NOT_OK                Values do not match
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_CompareFinishedVerifyData(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientHelloGetCipherSuites
 *********************************************************************************************************************/
/*! \brief         Parse the received cipher suite list and search for matching one in configured TLS-Servers list.
 *  \details       -
 *  \param[in]     TlsConIdx                TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ClientHelloEndIdx        End index in the TLS RxBuffer of this message
 *  \return        E_OK                     Matching cipher suite found
 *  \return        E_NOT_OK                 Error during parsing or no matching cipher worker found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloGetCipherSuites(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(TcpIp_TlsBufferRxClientHelloIdxOfTlsServerBufferMgmtType, AUTOMATIC) ClientHelloEndIdx );

/**********************************************************************************************************************
 * TcpIp_TlsMsg_SelectMatchingCompressionMethod
 *********************************************************************************************************************/
/*! \brief         Select matching local compression method.
 *  \details       -
 *  \param[in]     TlsConIdx                TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     CompressionMethodLen     Length of the received compression method list
 *  \return        E_OK                     Matching compression method found
 *  \return        E_NOT_OK                 Error during parsing or no matching compression method found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsMsg_SelectMatchingCompressionMethod(
  TcpIp_TlsConnectionIterType  TlsConIdx,
  CONST(uint8, AUTOMATIC)      CompressionMethodLen);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientHelloGetCompressionMethods
 *********************************************************************************************************************/
/*! \brief         Parse the received compression methods list and search for matching one in configured TLS-Servers list.
 *  \details       -
 *  \param[in]     TlsConIdx                TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     HelloEndIdx              End index in the TLS RxBuffer of this message
 *  \return        E_OK                     Matching compression method found
 *  \return        E_NOT_OK                 Error during parsing or no matching compression method found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloGetCompressionMethods(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(TcpIp_TlsBufferRxIterType, AUTOMATIC) HelloEndIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientHelloGetExtensions
 *********************************************************************************************************************/
/*! \brief         Parse and verify the received TLS-Client extensions
 *  \details       -
 *  \param[in]     TlsConIdx                TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ClientHelloEndIdx        End index in the TLS RxBuffer of this message
 *  \return        E_OK                     Parsing successful
 *  \return        E_NOT_OK                 Error during parsing
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloGetExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(TcpIp_TlsBufferRxClientHelloIdxOfTlsServerBufferMgmtType, AUTOMATIC) ClientHelloEndIdx );

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientHelloParseAndValidateExtensions
 *********************************************************************************************************************/
/*! \brief         Parse and verify the received TLS-Client extensions list
 *  \details       -
 *  \param[in]     TlsConIdx                TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ExtensionsLen            Length of the received extensions list.
 *  \param[in]     HelloEndIdx              End index in the TLS RxBuffer of this message
 *  \return        E_OK                     Parsing successful
 *  \return        E_NOT_OK                 Error during parsing
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloParseAndValidateExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16                      ExtensionsLen,
  TcpIp_TlsBufferRxIterType   HelloEndIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientHelloParseReceivedExtensions
 *********************************************************************************************************************/
/*! \brief         Iterate over received TLS-Client extensions list and parse each extension
 *  \details       -
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ReceivedExtensionListPtr Pointer to the list of received client extensions
 *  \param[in]     ReceivedExtensionCnt     Number of received client extensions
 *  \return        E_OK                     Parsing successful
 *  \return        E_NOT_OK                 Error during parsing
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloParseReceivedExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(TcpIp_TlsExtensionType) ReceivedExtensionListPtr,
  uint8 ReceivedExtensionCnt);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientHelloParseExtensionServerNameIndication
 *********************************************************************************************************************/
/*! \brief         Parses a received TLS extension of the type server name indication.
 *  \details       -
 *  \param[in]     TlsConIdx                      TLS connection index
 *                                                \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ServerNameIndicationExtension  Extension of type server name indication
 *  \return        E_OK                           Operation successful
 *  \return        E_NOT_OK                       Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloParseExtensionServerNameIndication(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType ServerNameIndicationExtension);

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloExtIsServerNameAcceptable
 *********************************************************************************************************************/
/*! \brief         Analyzes a received server name element. Only the format of the element is checked.
 *  \details       -
 *  \param[in]     TlsConIdx                       TLS connection index
 *                                                 \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ServerNameStartTlsBufferRxIdx   Start Idx of the server name element
 *  \param[in]     ServerNameIndicationEndIdx      End Idx of the extension
 *  \param[out]    ServerNameLenPtr                Length of the server name element (including type field)
 *  \param[in,out] HostNameReceivedPtr             A name type 'host_name' already was received
 *  \return        E_OK                            Well formated server name element received
 *  \return        E_NOT_OK                        Received server name element is mis-formated or invalid
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloExtIsServerNameAcceptable(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferRxIterType ServerNameStartTlsBufferRxIdx,
  TcpIp_TlsBufferRxIterType ServerNameIndicationEndIdx,
  TCPIP_P2V(uint16) ServerNameLenPtr,
  TCPIP_P2V(boolean) HostNameReceivedPtr);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientHelloParseExtensionTrustedCaIndication
 *********************************************************************************************************************/
/*! \brief         Parses a received TLS extension of the type trusted ca indication.
 *  \details       -
 *  \param[in]     TlsConIdx                     TLS connection index
 *                                               \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     TrustedCaIndicationExtension  Extension of type trusted ca indication
 *  \return        E_OK                          Operation successful
 *  \return        E_NOT_OK                      Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloParseExtensionTrustedCaIndication(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType TrustedCaIndicationExtension);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientHelloExtIsTrustedAuthorityAcceptable
 *********************************************************************************************************************/
/*! \brief         Analyzes a received trusted authority element. Only the format of the element is checked.
 *  \details       -
 *  \param[in]     TrustedAuthStartTlsBufferRxIdx   Start Idx of the authority element
 *  \param[in]     TrustedCaIndicationEndIdx        End Idx of the extension
 *  \param[out]    TrustedAuthorityLenPtr           Length of the authority element (including type field)
 *  \return        E_OK                             Well formated authority element received
 *  \return        E_NOT_OK                         Received authority element is mis-formated
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloExtIsTrustedAuthorityAcceptable(
  TcpIp_TlsBufferRxIterType TrustedAuthStartTlsBufferRxIdx,
  TcpIp_TlsBufferRxIterType TrustedCaIndicationEndIdx,
  TCPIP_P2V(uint16) TrustedAuthorityLenPtr);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientHelloParseExtensionCertificateStatusRequest
 *********************************************************************************************************************/
/*! \brief         Parses a received TLS extension of the type certificate status request.
 *  \details       -
 *  \param[in]     TlsConIdx                           TLS connection index
 *                                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     CertificateStatusRequestExtension   Extension of type certificate status request
 *  \return        E_OK                                Operation successful
 *  \return        E_NOT_OK                            Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloParseExtensionCertificateStatusRequest(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType CertificateStatusRequestExtension);

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHello_CheckOcspResponderIdList
 *********************************************************************************************************************/
/*! \brief         Analyzes the received responder id list.
 *  \details       -
 *  \param[in]     ResponderIdsListStartIdx      Start Idx of the responder id list
 *  \param[in]     CertStatusRequestEndIdx       End Idx of the extension
 *  \param[out]    TotalResponderIdListLenPtr    Length of the responder id list (including type field)
 *  \return        E_OK                          Well formated responder id list received
 *  \return        E_NOT_OK                      Received responder id list is mis-formated
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHello_CheckOcspResponderIdList(
  TcpIp_TlsBufferRxIterType ResponderIdsListStartIdx,
  TcpIp_TlsBufferRxIterType CertStatusRequestEndIdx,
  TCPIP_P2V(uint16) TotalResponderIdListLenPtr);

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHello_CheckOcspRequestExtensions
 *********************************************************************************************************************/
/*! \brief         Analyzes the received request extensions.
 *  \details       -
 *  \param[in]     RequestExtStartTlsBufferRxIdx    Start Idx of the request extensions
 *  \param[in]     CertStatusRequestEndIdx          End Idx of the extension
 *  \param[out]    TotalRequestExtensionsLenPtr     Length of the request extensions (including type field)
 *  \return        E_OK                             Well formated request extensions received
 *  \return        E_NOT_OK                         Received request extensions is mis-formated
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHello_CheckOcspRequestExtensions(
  TcpIp_TlsBufferRxIterType RequestExtStartTlsBufferRxIdx,
  TcpIp_TlsBufferRxIterType CertStatusRequestEndIdx,
  TCPIP_P2V(uint16) TotalRequestExtensionsLenPtr);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientHelloParseExtensionSupportedGroups
 *********************************************************************************************************************/
/*! \brief         Parses a received TLS extension of the type supported groups.
 *  \details       -
 *  \param[in]     TlsConIdx                 TLS connection index
 *                                           \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     SupportedGroupsExtension  Extension of type supported groups
 *  \return        E_OK                      Operation successful
 *  \return        E_NOT_OK                  Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloParseExtensionSupportedGroups(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType SupportedGroupsExtension);

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloCheckForMatchingSupportedGroups
 *********************************************************************************************************************/
/*! \brief         Check all received supported groups for being supported by the server, and mark all unused handshakes
 *                 that support these groups / curves.
 *  \details       -
 *  \param[in]     TlsConIdx                 TLS connection index
 *                                           \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ExtGroupStartIdx          Buffer start index for all supported groups
 *  \param[in]     ReceivedSupportedGroupsLen  Length of all supported groups
 *  \return        E_OK                      At least one matching handshake was found
 *  \return        E_NOT_OK                  No matching handshake was found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloCheckForMatchingSupportedGroups(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferRxIterType ExtGroupStartIdx,
  uint16 ReceivedSupportedGroupsLen);

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloExtIsCurveIdConfiguredInUnusedHandshake
 *********************************************************************************************************************/
/*! \brief         Iterate over all handshakes referenced in the passed cipherworker and mark all unused handshakes
 *                 that support the passed group / curve.
 *  \details       -
 *  \param[in]     TlsConIdx                 TLS connection index
 *                                           \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     TlsCipherWorkerIdx        Index of the TLS cipherworker whose handshakes shall be checked
 *                                           \spec requires TlsCipherWorkerIdx < TcpIp_GetSizeOfTlsCipherWorker(); \endspec
 *  \param[in]     ReceivedNamedCurveId      Id of the received named curve
 *  \return        TRUE                      At least one matching handshake was found
 *  \return        FALSE                     No matching handshake was found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloExtIsCurveIdConfiguredInUnusedHandshake(
  TcpIp_TlsConnectionIterType     TlsConIdx,
  TcpIp_TlsCipherWorkerIterType   TlsCipherWorkerIdx,
  TcpIp_TlsEllipticCurveIdType    ReceivedNamedCurveId);

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_GetTlsConfiguredHandshakeForServerConnectionIdx
 *********************************************************************************************************************/
/*! \brief         Iterate over all configured handshakes in the passed TLS connection and find the passed handshake.
 *  \details       -
 *  \param[in]     TlsConIdx                                   TLS connection index
 *                                                             \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     TlsHandshakeIdx                             TLS handshake index to find
 *  \return        ConfiguredHandshakeForServerConnectionIdx   If a matching handshake was found its index is returned,
 *  \return                                                    the invalid value is returned if not matching handshake
 *                                                             can be found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(TcpIp_TlsConfiguredHandshakeForServerConnectionIterType, TCPIP_CODE) TcpIp_TlsServerMsg_GetTlsConfiguredHandshakeForServerConnectionIdx(
  TcpIp_TlsConnectionIterType      TlsConIdx,
  TcpIp_TlsHandshakeIterType       TlsHandshakeIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientHelloExtIsNamedCurveSupported
 *********************************************************************************************************************/
/*! \brief         Compares the given named curve against the configured supported elliptic curves.
 *  \details       Iterate over all configured TcpIpTlsHandshake for each cipher worker for the specific TLS connection
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     NamedCurve              Received named curve ID from the ClientHello extension.
 *  \return        E_OK                    Matching TlsHandshake configuration found.
 *  \return        E_NOT_OK                No matching TlsHandshake configuration found.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloExtIsNamedCurveSupported(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 NamedCurve);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientHelloParseExtensionEcPointFormats
 *********************************************************************************************************************/
/*! \brief         Parses a received TLS extension of the type EC point formats.
 *  \details       -
 *  \param[in]     TlsConIdx                    TLS connection index
 *                                              \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     EcPointFormatExtension       Extension of type EC point formats
 *  \return        E_OK                         Operation successful
 *  \return        E_NOT_OK                     Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloParseExtensionEcPointFormats(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType EcPointFormatExtension);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientHelloParseExtensionSignatureAlgorithms
 *********************************************************************************************************************/
/*! \brief         Parses an received TLS extension of the type signature algorithm.
 *  \details       -
 *  \param[in]     TlsConIdx                      TLS connection index
 *                                                \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     SignatureAlgorithmsExtension   Extension of type signature algorithm
 *  \return        E_OK                           Operation successful
 *  \return        E_NOT_OK                       Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloParseExtensionSignatureAlgorithms(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType SignatureAlgorithmsExtension);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientHelloExtIsSignAndHashAlgSupported
 *********************************************************************************************************************/
/*! \brief         Compares the given signature and hash algorithm ID against the configured supported algorithms.
 *  \details       Iterate over all configured TcpIpTlsHandshake for each cipher worker for the specific TLS connection.
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     SignAndHashAlgId        Received signature and hash algorithm ID from the ClientHello extension
 *  \return        E_OK                    Matching TlsHandshake configuration found.
 *  \return        E_NOT_OK                No matching TlsHandshake configuration found.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloExtIsSignAndHashAlgSupported(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 SignAndHashAlgId);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientHelloExtIsSignAndHashAlgSupportedByThisHandshake
 *********************************************************************************************************************/
/*! \brief         Compares the given signature and hash algorithm ID against the configured supported algorithm
 *                 of the passed TLS handshake.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     SignAndHashAlgId        Received signature and hash algorithm ID from the ClientHello extension
 *  \param[in]     TlsHandshakeIdx         Index of the TLS handshake to check
 *                                         \spec requires TlsHandshakeIdx < TcpIp_GetSizeOfTlsHandshake(); \endspec
 *  \return        TRUE                    Passed TLS handshake has the desired signature algorithm ID configured.
 *  \return        FALSE                   Passed TLS handshake has not the desired configuration.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloExtIsSignAndHashAlgSupportedByThisHandshake(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16                      SignAndHashAlgId,
  TcpIp_TlsHandshakeIterType  TlsHandshakeIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientHelloParseExtensionRecordSizeLimit
 *********************************************************************************************************************/
/*! \brief         Parse and verify the received record size limit extension from the ClienHello message
 *  \details       The received information will then be used to fragment the TX size of RL frames after the CCS message
 *  \param[in]     TlsConIdx                TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     RecordSizeLimitExtension Extension of type record size limit
 *  \return        E_OK                     Extension successfully parsed
 *  \return        E_NOT_OK                 Extension NOT successfully parsed
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloParseExtensionRecordSizeLimit(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType RecordSizeLimitExtension);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientKeyExchangeGetEcdheEcdsaInformation
 *********************************************************************************************************************/
/*! \brief         Parse and verify the received ECDH(E) and ECDSA information from the ClientKeyExchange message
 *  \details       -
 *  \param[in]     TlsConIdx                TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                     Parsing successful
 *  \return        E_NOT_OK                 Error during parsing
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientKeyExchangeGetEcdheEcdsaInformation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientKeyExchangeGetClientParams
 *********************************************************************************************************************/
/*! \brief         Extract received Client key exchange parameter (Public key)
 *  \details       -
 *  \param[in]     TlsConIdx                TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                     Parsing successful
 *  \return        E_NOT_OK                 Error during parsing
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientKeyExchangeGetClientParams(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientKeyExchangeCalcSharedSecret
 *********************************************************************************************************************/
/*! \brief         Trigger calculation of DH shared secret for ECC based key exchange.
 *  \details       Calculation is performed in background task TcpIp_TlsServerCtx_AsyncHandler().
 *  \param[in]     TlsConIdx                TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ClientKeyExchangeCalcSharedSecret(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

#   if (TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientKeyExchangeGetPskInformation
 *********************************************************************************************************************/
/*! \brief         Parse and verify the received PSK information from ClientKeyExchange message.
 *  \details       -
 *  \param[in]     TlsConIdx                TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                     Parsing successful
 *  \return        E_NOT_OK                 Error during parsing
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientKeyExchangeGetPskInformation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_IsPskIdentityLengthValid
 *********************************************************************************************************************/
/*! \brief         Check if a PSK identity length is valid or not.
 *  \details       -
 *  \param[in]     TlsConIdx                TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ClientPskIdentityLen     Length of the PSK identity
 *  \return        TRUE                     Length is valid
 *  \return        FALSE                    Length is invalid
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsServerMsg_IsPskIdentityLengthValid(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 ClientPskIdentityLen);

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ComparePskIdentities
 *********************************************************************************************************************/
/*! \brief         Compare two PSK identities.
 *  \details       -
 *  \param[in]     TlsPskIdentityIdx                   Index of PSK identity which should be compared
 *  \param[in]     ReceivedClientPskIdentityStartIdx   Start index of received PSK identity which should be compared
 *  \param[in]     ReceivedClientPskIdentityLen        Length of received PSK identity
 *  \return        E_OK                                The two PSK identity strings are equal
 *  \return        E_NOT_OK                            Length or character mismatch
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ComparePskIdentities(
  TcpIp_TlsPskIdentityIterType                        TlsPskIdentityIdx,
  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType  ReceivedClientPskIdentityStartIdx,
  uint16                                              ReceivedClientPskIdentityLen);

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientKeyExchangeGetPskParams
 *********************************************************************************************************************/
/*! \brief         Extract received Client key exchange parameter (PSK Identity).
 *  \details       -
 *  \param[in]     TlsConIdx                TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                     Parsing successful
 *  \return        E_NOT_OK                 Error during parsing
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientKeyExchangeGetPskParams(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientKeyExchangeCalcPskPremasterSecret
 *********************************************************************************************************************/
/*! \brief         Trigger calculation of TLS pre master secret for PSK based key exchange.
 *  \details       Calculation is performed in background task TcpIp_TlsServerCtx_AsyncHandler().
 *  \param[in]     TlsConIdx                TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ClientKeyExchangeCalcPskPremasterSecret(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif /* TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON */

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ClientKeyExchangeCalcMasterSecret
 *********************************************************************************************************************/
/*! \brief         Trigger calculation of TLS master secret.
 *  \details       Calculation is performed in background task TcpIp_TlsServerCtx_AsyncHandler().
 *  \param[in]     TlsConIdx                TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ClientKeyExchangeCalcMasterSecret(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_SelectMatchingCipherWorker
 *********************************************************************************************************************/
/*! \brief         Select a suitable cipher worker for the offered cipher suite.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     CipherSuiteLen          Length of the received cipher suite list
 *  \return        E_OK                    Suitable cipher worker selected
 *  \return        E_NOT_OK                No suitable cipher work found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_SelectMatchingCipherWorker(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint16, AUTOMATIC) CipherSuiteLen);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_SearchCipherListForMatchingCipherSuite
 *********************************************************************************************************************/
/*! \brief         Compare received cipher suite against configured Server cipher suites.
 *  \details       -
 *  \param[in]     CipherListStartIdx      Start of the cipher suite within the TLS RxBuffer.
 *  \param[in]     CipherListLen           Length of the received cipher suite list
 *  \param[in]     CipherSuitePattern      Search pattern for the cipher suite (received client cipher suite)
 *  \return        E_OK                    Suitable cipher suite found
 *  \return        E_NOT_OK                No suitable cipher suite found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_SearchCipherListForMatchingCipherSuite(
  TcpIp_TlsBufferRxClientHelloIdxOfTlsServerBufferMgmtType CipherListStartIdx,
  CONST(uint16, AUTOMATIC) CipherListLen,
  CONST(TcpIp_TlsCipherDataType, AUTOMATIC) CipherSuitePattern);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_PrepareServerHello
 *********************************************************************************************************************/
/*! \brief         Build and prepare ServerHello message for transmitting.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Message prepared successfully
 *  \return        E_NOT_OK                Message preparation failed
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_PrepareServerHello(
  TcpIp_TlsConnectionIterType TlsConIdx);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_PrepareCertificateRequest
 *********************************************************************************************************************/
/*! \brief         Build and prepare CertificateRequest message for transmitting.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_PrepareCertificateRequest(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_PrepareServerCertificates
 *********************************************************************************************************************/
/*! \brief         Build and prepare ServerCertificate message for transmitting.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Message prepared successfully
 *  \return        E_NOT_OK                Message preparation failed
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_PrepareServerCertificates(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_PrepareServerKeyExchange
 *********************************************************************************************************************/
/*! \brief         Build and prepare ServerKeyExchange message for transmitting.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Message prepared successfully
 *  \return        E_NOT_OK                Message preparation failed
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_PrepareServerKeyExchange(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_PrepareServerHelloDone
 *********************************************************************************************************************/
/*! \brief         Build and prepare ServerHelloDone message for transmitting.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Message prepared successfully
 *  \return        E_NOT_OK                Message preparation failed
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_PrepareServerHelloDone(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_PrepareServerFinished
 *********************************************************************************************************************/
/*! \brief         Build and prepare ServerFinished message for transmitting.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Message prepared successfully
 *  \return        E_NOT_OK                Message preparation failed
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_PrepareServerFinished(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ServerHelloAddSelectedCipher
 *********************************************************************************************************************/
/*! \brief         Add the selected cipher suite to the TLS TxBuffer in the ServerHello message.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Cipher suite added successfully
 *  \return        E_NOT_OK                Error during adding - no matching cipher found.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ServerHelloAddSelectedCipher(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ServerHelloAddCompressionMethod
 *********************************************************************************************************************/
/*! \brief         Add the selected compression method to the TLS TxBuffer in the ServerHello message.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ServerHelloAddCompressionMethod(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ServerHelloAddServerExtensions
 *********************************************************************************************************************/
/*! \brief         Add the TLS-Server extensions to the TLS TxBuffer in the ServerHello message.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ServerHelloAddServerExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ServerHelloExtAddRecordSizeLimit
 *********************************************************************************************************************/
/*! \brief         -
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ServerHelloExtAddRecordSizeLimit(
  TcpIp_TlsConnectionIterType TlsConIdx);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ServerCertificateAddServerCertificates
 *********************************************************************************************************************/
/*! \brief         Add TLS-Server Certificate message structure and prepare the adding of the certificates.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Certificate added successfully
 *  \return        E_NOT_OK                Error during adding
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ServerCertificateAddServerCertificates(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_AddServerCertificatesAddLoadableCert
 *********************************************************************************************************************/
/*! \brief         Add the next certificate to the chain if available and applicable.
 *  \details       It is configurable if the root certificate is added to the certificate chain.
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] NextCertIdPtr           ID of the certificate that shall be added next
 *  \param[out]    CopiedLenPtr            Number of bytes copied to the TLS TxBuffer
 *  \param[out]    StopAddingCertsPtr      All applicable certs have been added
 *  \return        E_OK                    Certificate added successfully
 *  \return        E_NOT_OK                Error during adding
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_AddServerCertificatesAddLoadableCert(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(TcpIp_CertificateIdType) NextCertIdPtr,
  TCPIP_P2V(uint32) CopiedLenPtr,
  TCPIP_P2V(boolean) StopAddingCertsPtr);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_AddServerCertificatesAddCertChain
 *********************************************************************************************************************/
/*! \brief         Iterate over all installed TLS-Server certificates and add each certificate to the TLS TxBuffer.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] CopiedLenPtr            Number of bytes copied to the TLS TxBuffer
 *  \return        E_OK                    Certificate chain added successfully
 *  \return        E_NOT_OK                Error during adding
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_AddServerCertificatesAddCertChain(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint32) CopiedLenPtr);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_AddServerCertificatesAddSingleCert
 *********************************************************************************************************************/
/*! \brief        Add single certificate to the TLS TxBuffer.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] CopiedLenPtr            Number of bytes copied to the TLS TxBuffer
 *  \param[in]     CertId                  ID of the certificate which should be added
 *  \return        E_OK                    Certificate added successfully
 *  \return        E_NOT_OK                Error during adding
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_AddServerCertificatesAddSingleCert(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint32) CopiedLenPtr,
  CONST(TcpIp_CertificateIdType, AUTOMATIC) CertId);


/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ServerKeyExchangeAddSignatureParams
 *********************************************************************************************************************/
/*! \brief         Add the TLS Signature structure to the TLS TxBuffer.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ServerKeyExchangeAddSignatureParams(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ServerKeyExchangeEncodeSignature
 *********************************************************************************************************************/
/*! \brief         Encode the generated signature into the used format.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ServerKeyExchangeEncodeSignature(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_GetLenOfPubKeyCompression
 *********************************************************************************************************************/
/*! \brief         Return the length of the compression flag for a given curve ID.
 *  \details       If curve does not use compression flag, this returns 0.
 *  \param[in]     CurveId                 ID of the used curve as specified by RFC.
 *  \return        uint8                   Length of the compression flag
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(uint8, TCPIP_CODE) TcpIp_TlsServerMsg_GetLenOfPubKeyCompression(
  CONST(TcpIp_TlsEllipticCurveIdType, AUTOMATIC) CurveId);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ServerKeyExchangeAddDhPubKey
 *********************************************************************************************************************/
/*! \brief         Trigger calculation of Diffie-Hellman public key (ECC based key exchange).
 *  \details       Calculation is performed in background task TcpIp_TlsServerCtx_AsyncHandler().
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ServerKeyExchangeAddDhPubKey(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ServerKeyExchangeAddDiffieHellmanParams
 *********************************************************************************************************************/
/*! \brief         Add the TLS specific DH structure to the TLS TxBuffer.
 *  \details       -
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ServerKeyExchangeAddDiffieHellmanParams(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ServerKeyExchangeAddSignature
 *********************************************************************************************************************/
/*! \brief         Trigger calculation of ECDSA signature for the generated public key (ECC based key exchange).
 *  \details       Calculation is performed in background task TcpIp_TlsServerCtx_AsyncHandler().
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ServerKeyExchangeAddSignature(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ServerKeyExchangeAddEcdheParams
 *********************************************************************************************************************/
/*! \brief         Add TLS specific ECDH(E) parameter to the TLS TxBuffer.
 *  \details       -
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ServerKeyExchangeAddEcdheParams(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

#   if (TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ServerKeyExchangeAddPskIdentityHint
 *********************************************************************************************************************/
/*! \brief         Add PSK Identity hint to the TLS TxBuffer.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    PSK Identity added successfully
 *  \return        E_NOT_OK                Error during adding
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ServerKeyExchangeAddPskIdentityHint(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ServerKeyExchangeAddPskParams
 *********************************************************************************************************************/
/*! \brief         Add PSK parameters to the ServerKeyExchange message
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    PSK parameters added successfully
 *  \return        E_NOT_OK                Error during adding
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ServerKeyExchangeAddPskParams(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif /* TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON */

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ServerFinishedAddServerFinishedData
 *********************************************************************************************************************/
/*! \brief         Add calculated TLS finished verify data to the TLS ServerFinished message in the TLS TxBuffer.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ServerFinishedAddServerFinishedData(
  TcpIp_TlsConnectionIterType TlsConIdx);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsServerCtx_CalcSignatureOfPublicKey
 *********************************************************************************************************************/
/*! \brief         Prepare generation of the signature of the public key (ECDSA).
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK (only called in the context of the TLS background task TcpIp_Tls_MainFunctionLowPrio())
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerCtx_CalcSignatureOfPublicKey(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerCtx_GenerateSignatureOfPublicKey
 *********************************************************************************************************************/
/*! \brief         Generate the signature of the public key (ECDSA).
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Signature successfully generated
 *  \return        E_NOT_OK                Error during generation of signature
 *  \pre           -
 *  \context       TASK (only called in the context of the TLS background task TcpIp_Tls_MainFunctionLowPrio())
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCtx_GenerateSignatureOfPublicKey(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerCtx_PerformVerificationOfClientCertVerifySignature
 *********************************************************************************************************************/
/*! \brief         Manages the signature verification process of the client's CertificateVerify message.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerCtx_PerformVerificationOfClientCertVerifySignature(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerCtx_DecodeAndVerifyClientCertVerifySignature
 *********************************************************************************************************************/
/*! \brief         Decodes and verifies the signature of the client's CertificateVerify message.
 *  \details       -
 *  \param[in]     TlsConIdx                  TLS connection index
 *                                            \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     VerifySignatureCsmJobId    Id of the signature verify Csm job
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCtx_DecodeAndVerifyClientCertVerifySignature(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_CsmJobIdType          VerifySignatureCsmJobId);

/**********************************************************************************************************************
 * TcpIp_TlsServerCtx_VerifyClientCertVerifySignatureSecp
 *********************************************************************************************************************/
/*! \brief         Verifies the signature of the client's CertificateVerify message when using a Secp curve.
 *  \details       -
 *  \param[in]     TlsConIdx                  TLS connection index
 *                                            \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     VerifySignatureCsmJobId    Id of the signature verify Csm job
 *  \param[in]     SignatureBufferSegmentPtr  Pointer to the buffer segment containing the signature to be verified.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCtx_VerifyClientCertVerifySignatureSecp(
  TcpIp_TlsConnectionIterType       TlsConIdx,
  TcpIp_CsmJobIdType                VerifySignatureCsmJobId,
  TCPIP_P2C(TcpIp_ConstSegmentType) SignatureBufferSegmentPtr);

/**********************************************************************************************************************
 * TcpIp_TlsServerCtx_VerifyClientCertVerifySignatureEdwards
 *********************************************************************************************************************/
/*! \brief         Verifies the signature of the client's CertificateVerify message when using an Edwards curve.
 *  \details       -
 *  \param[in]     TlsConIdx                  TLS connection index
 *                                            \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     VerifySignatureCsmJobId    Id of the signature verify Csm job
 *  \param[in]     SignatureBufferSegmentPtr  Pointer to the buffer segment containing the signature to be verified.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCtx_VerifyClientCertVerifySignatureEdwards(
  TcpIp_TlsConnectionIterType       TlsConIdx,
  TcpIp_CsmJobIdType                VerifySignatureCsmJobId,
  TCPIP_P2C(TcpIp_ConstSegmentType) SignatureBufferSegmentPtr);

/**********************************************************************************************************************
 * TcpIp_TlsServerCtx_ClientCertVerifyGetCsmJobId
 *********************************************************************************************************************/
/*! \brief         Get the Id of the signature verify CSM job to process the received client CertificateVerify.
 *  \details       Also checks that the CSM job is configured and the temporary signature buffer has enough space
 *  \param[in]     TlsConIdx                    TLS connection index
 *                                              CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[out]    VerifySignatureCsmJobIdPtr   Pointer to the Id of the signature verify CSM job
 *  \return        E_OK                         CSM job Id found and written into VerifySignatureCsmJobIdPtr
 *  \return        E_NOT_OK                     Operation failed, CSM job Id NOT found or signature buffer too small
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCtx_ClientCertVerifyGetCsmJobId(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TCPIP_P2V(TcpIp_CsmJobIdType) VerifySignatureCsmJobIdPtr);
#   endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 * TcpIp_TlsServerCtx_GetPointerAndLengthOfLinearMessagesInBuffer
 *********************************************************************************************************************/
/*! \brief         Get the pointers and lengths of the TLS handshake messages in the Rx and Tx buffer
 *  \details       Can be used to calculate a hash over these messages
 *                 (ServerFinished, CCS and ClientHello are not considered and have to be added manually if required)
 *  \param[in]     TlsConIdx                       TLS connection index
 *                                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     IncludeClientFinished           Determines if the client finished message shall be considered or not
 *  \param[in]     IncludeClientCertificateVerify  Determines if the certificate verify shall be considered or not
 *  \param[out]    ServerTxPtrPtr                  Pointer to sent server messages in Tx buffer
 *  \param[out]    ServerTxLenPtr                  Length of the sent server messages in Tx buffer with Hs header
 *  \param[out]    ClientRxPtrPtr                  Pointer to received client messages in Rx buffer
 *  \param[out]    ClientRxLenPtr                  Length of the received client messages in Rx buffer with Hs header
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerCtx_GetPointerAndLengthOfLinearMessagesInBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx,
  boolean                     IncludeClientFinished,
  boolean                     IncludeClientCertificateVerify,
  TCPIP_P2V(TcpIp_Uint8P2C)   ServerTxPtrPtr,
  TCPIP_P2V(uint32)           ServerTxLenPtr,
  TCPIP_P2V(TcpIp_Uint8P2C)   ClientRxPtrPtr,
  TCPIP_P2V(uint32)           ClientRxLenPtr);

/**********************************************************************************************************************
 * TcpIp_TlsServerCtx_CalcServerFinishedHash
 *********************************************************************************************************************/
/*! \brief         Generate the finished hash of all received and transmitted TLS handshake messages (Server side).
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK (only called in the context of the TLS background task TcpIp_Tls_MainFunctionLowPrio())
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerCtx_CalcServerFinishedHash(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerCtx_CalcClientFinishedHash
 *********************************************************************************************************************/
 /*! \brief         Generate the finished hash of all received and transmitted TLS handshake messages (Client side).
 *  \details       -
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK (only called in the context of the TLS background task TcpIp_Tls_MainFunctionLowPrio())
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerCtx_CalcClientFinishedHash(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerCtx_CalcClientFinishedVerifyData
 *********************************************************************************************************************/
 /*! \brief        Generate the finished verify data via the TLS PRF.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK (only called in the context of the TLS background task TcpIp_Tls_MainFunctionLowPrio())
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerCtx_CalcClientFinishedVerifyData(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerCrypto_CalcHsFinishedData
 *********************************************************************************************************************/
/*! \brief         Calculate the Verify data for Finished handshake message
 *  \details       Invokes the PRF operation to calculate Verify data for Finished message
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     FinishedMessageType Type of finished message
 *                                      TCPIP_TLS_MSG_HASH_SERVER_FINISHED
 *                                      TCPIP_TLS_MSG_HASH_CLIENT_FINISHED
 *  \param[out]    ResultPtr           Pointer to buffer where Verify Data shall be stored
 *                                      only valid if E_OK returned
 *  \return        E_OK                Result was calculated successfully
 *  \return        E_NOT_OK            Calculation was unsuccessful
 *  \pre           -
 *  \context       TASK (only called in the context of the TLS background task TcpIp_Tls_MainFunctionLowPrio())
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCrypto_CalcHsFinishedData(
  TcpIp_TlsConnectionIterType     TlsConIdx,
  TcpIp_TlsMessageFinishedType    FinishedMessageType,
  TCPIP_P2V(uint8)                ResultPtr);

/**********************************************************************************************************************
 * TcpIp_TlsServerCrypto_GenerateHsHash
 *********************************************************************************************************************/
/*! \brief         Calculate the Hash of all handshake messages until now
 *  \details       Generates Hash using all handshake messages exchanged till now
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     FinishedMessageType Type of finished message
 *                                      TCPIP_TLS_MSG_HASH_SERVER_FINISHED
 *                                      TCPIP_TLS_MSG_HASH_CLIENT_FINISHED
 *  \return        E_OK                Hash was calculated successfully
 *  \return        E_NOT_OK            Calculation of Hash was unsuccessful
 *  \pre           -
 *  \context       TASK (only called in the context of the TLS background task TcpIp_Tls_MainFunctionLowPrio())
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCrypto_GenerateHsHash(
  TcpIp_TlsConnectionIterType     TlsConIdx,
  TcpIp_TlsMessageFinishedType    FinishedMessageType);

/**********************************************************************************************************************
 * TcpIp_TlsServerCrypto_SetCsmKeysAes128CbcStreaming
 *********************************************************************************************************************/
/*! \brief         Set all relevant CSM keys for AES-128-CBC streaming.
 *  \details       Keys are generated via TcpIp_Tls12CoreCrypto_DeriveKeyBlock()
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                CSM keys set successfully
 *  \return        E_NOT_OK            CSM keys set unsuccessful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCrypto_SetCsmKeysAes128CbcStreaming(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerCrypto_SetCsmKeysAes128GcmStreaming
 *********************************************************************************************************************/
/*! \brief         Set all relevant CSM keys for AES-128-GCM streaming.
 *  \details       Keys are generated via TcpIp_Tls12CoreCrypto_DeriveKeyBlock()
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                CSM keys set successfully
 *  \return        E_NOT_OK            CSM keys set unsuccessful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCrypto_SetCsmKeysAes128GcmStreaming(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerCrypto_SetCsmKeysNullStreaming
 *********************************************************************************************************************/
/*! \brief         Set all relevant CSM keys for NULL streaming.
 *  \details       Keys are generated via TcpIp_Tls12CoreCrypto_DeriveKeyBlock()
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                CSM keys set successfully
 *  \return        E_NOT_OK            CSM keys set unsuccessful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCrypto_SetCsmKeysNullStreaming(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TCPIP TLS LISTENER
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsServerListener_GetCurrentTlsConnectionPriority
 *********************************************************************************************************************/
/*! \brief         Determines the priority of a TLS Connection.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     SocketIdx         Index of the assigned socket
 *  \param[in]     UsedPort          Port which is used to identify the TLS connection
 *  \return        priority          Valid if a matching Tls connection exists
 *  \return        priority          Invalid if no matching Tls connection exists
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(TcpIp_TlsConnectionPrioType, TCPIP_CODE) TcpIp_TlsServerListener_GetCurrentTlsConnectionPriority(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SocketDynIterType SocketIdx,
  CONST(TcpIp_PortOfTlsListenerType, AUTOMATIC) UsedPort);

#   if ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON))
/**********************************************************************************************************************
 *  MSA - Master Secret Access
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsServerMsa_AddServerSessionIdToAccessBuffer
 *********************************************************************************************************************/
/*! \brief          Add TLS-Server session ID to MSA Access buffer.
 *  \details        Only active if TcpIpTlsSupportMasterSecretAccess is enabled
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsa_AddServerSessionIdToAccessBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif

#   if ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON))
/**********************************************************************************************************************
 * TcpIp_TlsServerMsa_AddClientRandomToAccessBuffer
 *********************************************************************************************************************/
/*! \brief          Add the received TLS-Client random to MSA Access buffer.
 *  \details        Only active if TcpIpTlsSupportMasterSecretAccess is enabled
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
*********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsa_AddClientRandomToAccessBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_AddCertificateRequestCertTypes
 *********************************************************************************************************************/
/*! \brief          Add a list of the supported certificate types to the TlsTxBuffer
 *  \details        -
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_AddCertificateRequestCertTypes(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_AddCertificateRequestSignatureHashAlgos
 *********************************************************************************************************************/
/*! \brief          Add a list of the supported signature and hash algorithms to the TlsTxBuffer
 *  \details        Add the algorithm of each Ecc handshake referenced in the active cipherworker
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_AddCertificateRequestSignatureHashAlgos(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_AddCertificateRequestDistNames
 *********************************************************************************************************************/
 /*! \brief          Add a distinguished names list of acceptable certificate authorities to the TlsTxBuffer
  *  \details        -
  *  \param[in]      TlsConIdx           TLS connection index
  *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
  *  \pre            -
  *  \context        TASK
  *  \reentrant      FALSE
  *  \synchronous    TRUE
  *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_AddCertificateRequestDistNames(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TLS SERVER IMPLEMENTATION
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsServer_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(void, TCPIP_CODE) TcpIp_TlsServer_Init(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsConnectionIterType tlsConIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all configured TLS connections and initialize the submodules */
  for (tlsConIdx = 0; tlsConIdx < TcpIp_GetSizeOfTlsConnection(); tlsConIdx++)
  {
    if (TcpIp_GetModeOfTlsConnection(tlsConIdx) == TCPIP_TLS_SERVER)
    {
      /* Reset all submodules of this connection */
      TcpIp_TlsServer_ResetConnection(tlsConIdx);
    }
  }

  TcpIp_TlsHandshakeDynIterType tlsHandshakeIdx = 0u;
  /* #20 Reset handshake usage flags for all handshakes */
  for (tlsHandshakeIdx = 0u; tlsHandshakeIdx < TcpIp_GetSizeOfTlsHandshakeDyn(); tlsHandshakeIdx++)
  {
    TcpIp_SetTlsHandshakeInUseOfTlsHandshakeDyn(tlsHandshakeIdx, FALSE);
  }
} /* TcpIp_TlsServer_Init() */

/**********************************************************************************************************************
 *  TcpIp_TlsServer_InitHsMsgIndices
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServer_InitHsMsgIndices(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize the RX/TX messages indices */
  /* Initialize indices of received messages (RX) */
  TcpIp_SetTlsBufferRxClientHelloIdxOfTlsServerBufferMgmt(
    tlsServerBufferMgmtIdx, TCPIP_NO_TLSBUFFERRXCLIENTHELLOIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferRxClientRandomIdxOfTlsServerBufferMgmt(
    tlsServerBufferMgmtIdx, TCPIP_NO_TLSBUFFERRXCLIENTRANDOMIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferRxClientSessionIdIdxOfTlsServerBufferMgmt(
    tlsServerBufferMgmtIdx, TCPIP_NO_TLSBUFFERRXCLIENTSESSIONIDIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferRxClientKeyExchangeIdxOfTlsServerBufferMgmt(
    tlsServerBufferMgmtIdx, TCPIP_NO_TLSBUFFERRXCLIENTKEYEXCHANGEIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferRxClientKeyExchangePubKeyIdxOfTlsServerBufferMgmt(
    tlsServerBufferMgmtIdx, TCPIP_NO_TLSBUFFERRXCLIENTKEYEXCHANGEPUBKEYIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferRxClientKeyExchangePubKeyLenIdxOfTlsServerBufferMgmt(
    tlsServerBufferMgmtIdx, TCPIP_NO_TLSBUFFERRXCLIENTKEYEXCHANGEPUBKEYLENIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferRxClientFinishedIdxOfTlsServerBufferMgmt(
    tlsServerBufferMgmtIdx, TCPIP_NO_TLSBUFFERRXCLIENTFINISHEDIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferRxClientFinishedVerifyDataIdxOfTlsServerBufferMgmt(
    tlsServerBufferMgmtIdx, TCPIP_NO_TLSBUFFERRXCLIENTFINISHEDVERIFYDATAIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferRxClientSignatureIdxOfTlsServerBufferMgmt(
    tlsServerBufferMgmtIdx, TCPIP_NO_TLSBUFFERRXCLIENTSIGNATUREIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferRxClientSignatureLenIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXCLIENTSIGNATURELENIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferRxClientCertificateIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXCLIENTCERTIFICATEIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferRxClientCertificateVerifyIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXCLIENTCERTIFICATEVERIFYIDXOFTLSSERVERBUFFERMGMT);

  /* Initialize indices of transmitted messages (TX) */
  TcpIp_SetTlsBufferTxServerHelloIdxOfTlsServerBufferMgmt(
    tlsServerBufferMgmtIdx, TCPIP_NO_TLSBUFFERTXSERVERHELLOIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferTxServerRandomIdxOfTlsServerBufferMgmt(
    tlsServerBufferMgmtIdx, TCPIP_NO_TLSBUFFERTXSERVERRANDOMIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferTxServerSessionIdIdxOfTlsServerBufferMgmt(
    tlsServerBufferMgmtIdx, TCPIP_NO_TLSBUFFERTXSERVERSESSIONIDIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferTxServerCertificatesIdxOfTlsServerBufferMgmt(
    tlsServerBufferMgmtIdx, TCPIP_NO_TLSBUFFERTXSERVERCERTIFICATESIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferTxServerKeyExchangeIdxOfTlsServerBufferMgmt(
    tlsServerBufferMgmtIdx, TCPIP_NO_TLSBUFFERTXSERVERKEYEXCHANGEIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferTxServerKeyExchangeSignatureLenIdxOfTlsServerBufferMgmt(
    tlsServerBufferMgmtIdx, TCPIP_NO_TLSBUFFERTXSERVERKEYEXCHANGESIGNATURELENIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferTxServerHelloDoneIdxOfTlsServerBufferMgmt(
    tlsServerBufferMgmtIdx, TCPIP_NO_TLSBUFFERTXSERVERHELLODONEIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferTxServerFinishedIdxOfTlsServerBufferMgmt(
    tlsServerBufferMgmtIdx, TCPIP_NO_TLSBUFFERTXSERVERFINISHEDIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferTxServerFinishedVerifyDataIdxOfTlsServerBufferMgmt(
    tlsServerBufferMgmtIdx, TCPIP_NO_TLSBUFFERTXSERVERFINISHEDVERIFYDATAIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferTxCertificateRequestIdxOfTlsServerBufferMgmt(
    tlsServerBufferMgmtIdx, TCPIP_NO_TLSBUFFERTXCERTIFICATEREQUESTIDXOFTLSSERVERBUFFERMGMT);
  TcpIp_SetTlsBufferTxCertificateRequestSignatureAndHashAlgorithmListIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERTXCERTIFICATEREQUESTSIGNATUREANDHASHALGORITHMLISTIDXOFTLSSERVERBUFFERMGMT);
} /* TcpIp_TlsServer_InitHsMsgIndices() */

/**********************************************************************************************************************
 *  TcpIp_TlsServer_InitHsLenInformation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServer_InitHsLenInformation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the RX length information to zero */
  TcpIp_SetClientHelloLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, 0u);
  TcpIp_SetClientCertificateLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, 0u);
  TcpIp_SetClientKeyExchangeLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, 0u);
  TcpIp_SetClientFinishedLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, 0u);

  /* #20 Set the TX length information to zero */
  TcpIp_SetServerHelloLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, 0u);
  TcpIp_SetServerCertificatesLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, 0u);
  TcpIp_SetServerKeyExchangeLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, 0u);
  TcpIp_SetServerHelloDoneLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, 0u);
  TcpIp_SetServerFinishedLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, 0u);
  TcpIp_SetServerHelloSessionIdLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, 0u);
  TcpIp_SetCertificateRequestLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, 0u);
} /* TcpIp_TlsServer_InitHsLenInformation() */

/**********************************************************************************************************************
 *  TcpIp_TlsServer_InitReadyToSendFlags
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServer_InitReadyToSendFlags(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx
    = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize the ready to send flags */
  TcpIp_SetHelloReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
  TcpIp_SetCertificateReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
  TcpIp_SetKeyExchangeReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
  TcpIp_SetHelloDoneReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
  TcpIp_SetServerFinishedReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
  TcpIp_SetChangeCipherSpecReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
  TcpIp_SetCertificateRequestReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, FALSE);

} /* TcpIp_TlsServer_InitReadyToSendFlags() */

/**********************************************************************************************************************
 *  TcpIp_TlsServer_InitAsyncFlags
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
  */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServer_InitAsyncFlags(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx
    = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize the async calculation trigger flags */
  TcpIp_SetHsSignGenAsyncFlagOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
  TcpIp_SetCalcServerFinishedHashAsyncFlagOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
  TcpIp_SetVerifySignatureOfCertificateVerifyAsyncFlagOfTlsServerConnection(tlsServerConnectionIdx, FALSE);


  TcpIp_SetCalcClientFinishedVerifyDataAsyncFlagOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
  TcpIp_SetCalcClientFinishedHashAsyncFlagOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
} /* TcpIp_TlsServer_InitAsyncFlags() */

/**********************************************************************************************************************
 *  TcpIp_TlsServer_InitOtherFlags
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServer_InitOtherFlags(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx
    = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsConfiguredHandshakeForServerConnectionIterType tlsConfiguredHandshakeForServerConnectionIterIdx
    = TcpIp_GetTlsConfiguredHandshakeForServerConnectionStartIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsConfiguredHandshakeForServerConnectionIterType tlsConfiguredHandshakeForServerConnectionEndIdx
    = TcpIp_GetTlsConfiguredHandshakeForServerConnectionEndIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize flags. */
  TcpIp_SetClientAuthSignatureAlgorithmIdOfTlsServerConnection(tlsServerConnectionIdx, TCPIP_SIG_ALGO_ID_NONE);
  TcpIp_SetTlsHandshakeSupportedGroupsExtensionMissingOfTlsServerConnection(tlsServerConnectionIdx, TRUE);

  for (; tlsConfiguredHandshakeForServerConnectionIterIdx < tlsConfiguredHandshakeForServerConnectionEndIdx;
         tlsConfiguredHandshakeForServerConnectionIterIdx++)
  {
    TcpIp_SetMatchesReceivedSignatureAlgorithmsOfTlsConfiguredHandshakeForServerConnectionDyn(
      tlsConfiguredHandshakeForServerConnectionIterIdx, FALSE);
    TcpIp_SetMatchesReceivedSupportedGroupsOfTlsConfiguredHandshakeForServerConnectionDyn(
      tlsConfiguredHandshakeForServerConnectionIterIdx, FALSE);
  }

  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType tlsCipherWorkerIdx
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  if (tlsCipherWorkerIdx < TcpIp_GetSizeOfTlsCipherWorker())
  {
    TcpIp_TlsHandshakeIterType tlsHandshakeIdx
      = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(tlsCipherWorkerIdx);

    if (tlsHandshakeIdx < TcpIp_GetSizeOfTlsHandshake())
    {
      TcpIp_SetTlsHandshakeInUseOfTlsHandshakeDyn(tlsHandshakeIdx, FALSE);
    }
  }
}

/**********************************************************************************************************************
 *  TcpIp_TlsServer_ResetConnection
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
FUNC(void, TCPIP_CODE) TcpIp_TlsServer_ResetConnection(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize the TLS handshake message indices */
  TcpIp_TlsServer_InitHsMsgIndices(TlsConIdx);

  /* #20 Initialize the TLS handshake length information */
  TcpIp_TlsServer_InitHsLenInformation(TlsConIdx);

  /* #30 Initialize the ready to send flags */
  TcpIp_TlsServer_InitReadyToSendFlags(TlsConIdx);

  /* #40 Initialize the async context flags */
  TcpIp_TlsServer_InitAsyncFlags(TlsConIdx);

  /* #50 Initialize other flags */
  TcpIp_TlsServer_InitOtherFlags(TlsConIdx);

  TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_HELLO);

} /* TcpIp_TlsServer_ResetConnection() */

/**********************************************************************************************************************
 *   TLS SERVER ASYNC CONTEXT
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsServerCtx_AsyncHandler
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_TlsStatemachine_STCAL_6050 */
FUNC(void, TCPIP_CODE) TcpIp_TlsServerCtx_AsyncHandler(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx
    = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the trigger for the different ASYNC operations and execute the operation if the trigger is set */
#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
  /* Execute the signature generation operation if the corresponding trigger flag is set */
  if (TcpIp_IsHsSignGenAsyncFlagOfTlsServerConnection(tlsServerConnectionIdx) == TRUE)
  {
    /* generate the Signature of the public key */
    TcpIp_TlsServerCtx_CalcSignatureOfPublicKey(TlsConIdx);
    TcpIp_SetHsSignGenAsyncFlagOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
  }
  /* Execute the signature verify operation if the corresponding trigger flag is set */
  if (TcpIp_IsVerifySignatureOfCertificateVerifyAsyncFlagOfTlsServerConnection(tlsServerConnectionIdx) == TRUE)
  {
    /* Only perform signature verification if certificate has been validated successfully */
    /* [HS Client Certificate Chain Handling StM] Certificate verification complete */
    if (TcpIp_GetHsCertStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CERTCHAIN_COMPLETE)
    {
      /* Verify the received signature of the client certificate verify. */
      TcpIp_TlsServerCtx_PerformVerificationOfClientCertVerifySignature(TlsConIdx);
      TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);
      TcpIp_SetVerifySignatureOfCertificateVerifyAsyncFlagOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
    }
  }
#   endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */
  /* Execute the finished hash operation if the corresponding trigger flag is set */
  if (TcpIp_IsCalcServerFinishedHashAsyncFlagOfTlsServerConnection(tlsServerConnectionIdx) == TRUE)
  {
    /* Calculate the server finished data hash */
    TcpIp_TlsServerCtx_CalcServerFinishedHash(TlsConIdx);
    TcpIp_SetCalcServerFinishedHashAsyncFlagOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
  }
  /* Execute the finished hash operation if the corresponding trigger flag is set */
  if (TcpIp_IsCalcClientFinishedHashAsyncFlagOfTlsServerConnection(tlsServerConnectionIdx) == TRUE)
  {
    /* Calculate the hash till client finished */
    TcpIp_TlsServerCtx_CalcClientFinishedHash(TlsConIdx);
    TcpIp_SetCalcClientFinishedHashAsyncFlagOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
  }
  /* Execute the finished verify operation if the corresponding trigger flag is set */
  if (TcpIp_IsCalcClientFinishedVerifyDataAsyncFlagOfTlsServerConnection(tlsServerConnectionIdx) == TRUE)
  {
    /* Calculate the client finished verify data */
    TcpIp_TlsServerCtx_CalcClientFinishedVerifyData(TlsConIdx);
    TcpIp_SetCalcClientFinishedVerifyDataAsyncFlagOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
  }
} /* TcpIp_TlsServerCtx_AsyncHandler() */

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsServerCtx_CalcSignatureOfPublicKey
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerCtx_CalcSignatureOfPublicKey(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the CSM job for the signature operation is configured */
  if (TcpIp_IsCsmJobIdKeyExchangeSignatureGenerateUsedOfTlsHandshake(activeTlsHandshakeIdx) == TRUE)
  {

    /* #20 Generate the signature of the public key */
    if (TcpIp_TlsServerCtx_GenerateSignatureOfPublicKey(TlsConIdx) == E_OK)
    {
      /* Signature generated - reset context state */
      TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);
    }
    else
    {
      /* #30 Generation of signature failed - handle error during processing */
      TcpIp_TlsAsyncCtx_HandleErrorDuringAsyncJobProcessing(TlsConIdx,
        TCPIP_TLS_FCTID_SERVER_ASYNCCTX_CALC_SIGN_PUBKEY, TCPIP_TLS_ERRORID_CRYPTO_CSM_CALL_FAILED);
    }
  }
  else
  {
    /* #40 CSM job for signature operation is not configured - invalid configuration */
    TcpIp_TlsCoreUtil_HandleInvalidConfiguration(TlsConIdx);
  }
} /* TcpIp_TlsServerCtx_CalcSignatureOfPublicKey() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerCtx_GenerateSignatureOfPublicKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCtx_GenerateSignatureOfPublicKey(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

  TcpIp_TlsTemporarySignatureBufferStartIdxOfTlsConnectionType startTlsTemporarySignatureBufferIdx
    = TcpIp_GetTlsTemporarySignatureBufferStartIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsTemporarySignatureBufferEndIdxOfTlsConnectionType tmpSignatureBufferEndIdx
    = TcpIp_GetTlsTemporarySignatureBufferEndIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsEllipticCurveIdType usedCurveId =
    TcpIp_GetEllipticCurveIdOfTlsHandshake(activeTlsHandshakeIdx);

  /* Get the length of the calculated (raw, without encoding) signature depending on the curve. */
  uint32 ExpectedResultLength = TcpIp_Tls12Msg_GetLenOfCurveSpecificSignature(usedCurveId);

  TcpIp_CsmJobIdType signatureGenerateJobId
    = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdKeyExchangeSignatureGenerateIdxOfTlsHandshake(activeTlsHandshakeIdx));

  /* The CSM does not support in place calculation for the signature generate operation
   - use local buffer for the CSM input */
  /* Size of the Buffer must be big enough to fit the ClientHello random, the ServerHello random */
  /* and the maximum length of the ServerKeyExchange parameter into it. */
  /* This maximum is reached when the public key length is at its maximum and when a compression length field exists */
  uint8 localDataToBeSignedBuf[TCPIP_TLS_RANDOM_LEN + TCPIP_TLS_RANDOM_LEN + TCPIP_TLSSERVER_CURVETYPE_LEN
    + TCPIP_TLSSERVER_CUVEID_LEN + TCPIP_TLSSERVER_PUPKEYLEN_LEN + TCPIP_TLSSERVER_PUPKEY_COMPRESSION_LEN
    + TCPIP_MAX_PUBKEY_LEN];

  /* Destination buffer for the CSM operation */
  TCPIP_P2V(uint8) generatedSignatureDestPtr = TcpIp_GetAddrTlsTemporarySignatureBuffer(startTlsTemporarySignatureBufferIdx);
  uint32 generatedSignatureDestLen = (((uint32)tmpSignatureBufferEndIdx - startTlsTemporarySignatureBufferIdx));

  Std_ReturnType csmRetVal;
  Std_ReturnType retVal = E_NOT_OK;
  /* ----- Implementation ----------------------------------------------- */
  /* RFC8422 - 5.4. Server Key Exchange */
  /*  ServerKeyExchange.signed_params.sha_hash
          SHA(ClientHello.random + ServerHello.random + ServerKeyExchange.params) */

  /* Format of temporary input signature buffer:
  *                                 +-> clientRndDestPtr
  *                                /                   +-> serverRndDestPtr
  *                               /                   /                   +-> keyExchangeDestPtr
  *                              /                   /                   /
  * localDataToBeSignedBuf  : [ (ClientHello random)(ServerHello random)(ServerKeyExchange parameter) ]
  *                           \                                          \-----dhParameterLen------/  /
  *                            \----------------------------------+----------------------------------/
  *                                                               +---> dataToBeSignedLen
  */

  uint8 usedPublicKeyLen = ((TcpIp_TlsMsg_GetLenOfCurveSpecificPubKey(usedCurveId)
    + TcpIp_TlsServerMsg_GetLenOfPubKeyCompression(usedCurveId)));

  uint32 dhParameterLen
    = ((uint32)usedPublicKeyLen + TCPIP_TLSSERVER_CURVETYPE_LEN + TCPIP_TLSSERVER_CUVEID_LEN + TCPIP_TLSSERVER_PUPKEYLEN_LEN);

  uint32 dataToBeSignedLen = (TCPIP_TLS_RANDOM_LEN + TCPIP_TLS_RANDOM_LEN + dhParameterLen);

  TCPIP_P2V(uint8) clientRndDestPtr   = &localDataToBeSignedBuf[0];
  TCPIP_P2V(uint8) serverRndDestPtr   = &localDataToBeSignedBuf[TCPIP_TLS_RANDOM_LEN];
  TCPIP_P2V(uint8) keyExchangeDestPtr = &localDataToBeSignedBuf[TCPIP_TLS_RANDOM_LEN + TCPIP_TLS_RANDOM_LEN];

  /* #10 Generate linear input buffer with the server key exchange data to be signed */
  VStdMemCpy(clientRndDestPtr, TcpIp_GetAddrTlsBufferRx(                                                                /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    TcpIp_GetTlsBufferRxClientRandomIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx)), TCPIP_TLS_RANDOM_LEN);

  VStdMemCpy(serverRndDestPtr, TcpIp_GetAddrTlsBufferTx(                                                                /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    TcpIp_GetTlsBufferTxServerRandomIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx)), TCPIP_TLS_RANDOM_LEN);

  VStdMemCpy(keyExchangeDestPtr, TcpIp_GetAddrTlsBufferTx(                                                              /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    TcpIp_GetTlsBufferTxServerKeyExchangeParamsIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx)), dhParameterLen);

  /* #20 Generate signature over linearized input data */
  csmRetVal = TCPIP_CSM_SignatureGenerate(signatureGenerateJobId, CRYPTO_OPERATIONMODE_SINGLECALL,
    clientRndDestPtr, dataToBeSignedLen, generatedSignatureDestPtr, &generatedSignatureDestLen);

  /* #30 Check the result of the CSM operation */
  if (TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, generatedSignatureDestLen,
    ExpectedResultLength, TCPIP_TLS_FCTID_SERVER_ASYNCCTX_CALC_SIGN_PUBKEY) == E_OK)
  {
    /* Signature successfully generated */
    retVal = E_OK;
  }

  return retVal;
} /* TcpIp_TlsServerCtx_GenerateSignatureOfPublicKey() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerCtx_PerformVerificationOfClientCertVerifySignature
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerCtx_PerformVerificationOfClientCertVerifySignature(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_CsmJobIdType verifySignatureCsmJobId = TCPIP_TLS_CSM_INV_JOB_ID;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the CSM job Id of the signature verify job. */
  if (TcpIp_TlsServerCtx_ClientCertVerifyGetCsmJobId(TlsConIdx, &verifySignatureCsmJobId) == E_OK)
  {
    /* #20 Verify the signature */
    retVal = TcpIp_TlsServerCtx_DecodeAndVerifyClientCertVerifySignature(TlsConIdx, verifySignatureCsmJobId);
  }

  /* #30 Check if an error occurred */
  if (retVal != E_OK)
  {
    /* #40 Raise internal_error alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_ABORT);
  }
} /* TcpIp_TlsServerCtx_PerformVerificationOfClientCertVerifySignature() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerCtx_DecodeAndVerifyClientCertVerifySignature
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCtx_DecodeAndVerifyClientCertVerifySignature(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_CsmJobIdType          VerifySignatureCsmJobId)
{
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);
  const TcpIp_TlsServerConnectionIdxOfTlsConnectionType tlsServerConnectionIdx
    = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);
  const TcpIp_SignatureAlgorithmIdType signatureAlgorithmId
    = TcpIp_GetClientAuthSignatureAlgorithmIdOfTlsServerConnection(tlsServerConnectionIdx);
  /* The memory access for the signature and its length field are valid, the index check was performed in
   * TcpIp_TlsServerMsg_ClientCertificateVerifyGetParams(). */
  const TcpIp_TlsBufferRxIterType signatureBufferIdx
    = TcpIp_GetTlsBufferRxClientSignatureIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);
  const TcpIp_TlsBufferRxIterType signatureLenBufferIdx
    = TcpIp_GetTlsBufferRxClientSignatureLenIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);
  const TcpIp_TlsTemporarySignatureBufferStartIdxOfTlsConnectionType startTlsTemporarySignatureBufferIdx
    = TcpIp_GetTlsTemporarySignatureBufferStartIdxOfTlsConnection(TlsConIdx);
  TCPIP_P2V(uint8) tlsTemporarySignatureBufferPtr
    = TcpIp_GetAddrTlsTemporarySignatureBuffer(startTlsTemporarySignatureBufferIdx);
  TcpIp_SegmentType signatureBufferSegment = { 0 };
  TcpIp_ConstSegmentType signatureBufferConstSegment = { 0 };

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* Create a buffer segment for the signature. */
  TcpIp_SegmentInit(&signatureBufferSegment, tlsTemporarySignatureBufferPtr, TCPIP_TLS_MAX_SIGNATURE_LEN);

  /* #10 Decode the received signature */
  if (TcpIp_TlsCoreMsg_DecodeSignature(&signatureBufferSegment, signatureAlgorithmId,
        signatureBufferIdx, signatureLenBufferIdx) == E_OK)
  {
    /* Get the decoded signature length (just check how many bytes are occupied in the buffer after decoding). */
    TcpIp_ConstSegmentInitWithUsedSegment(&signatureBufferConstSegment, &signatureBufferSegment);
    retVal = E_OK;
  }
  else
  {
    /* Unable to decode the signature, set decrypt_error alert, retVal already E_NOT_OK */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECRYPT_ERROR);
  }

  /* #20 Verify the received signature */
  if (retVal == E_OK)
  {
    /* TcpIp_TlsCoreMsg_DecodeSignature secures that signatureAlgorithmId can only be
     * TCPIP_SIG_ALGO_ID_ECDSA_SECP256R1_SHA256 / TCPIP_SIG_ALGO_ID_ECDSA_SECP521R1_SHA512 or
     * TCPIP_SIG_ALGO_ID_ECDSA_ED448_INTRINSIC / TCPIP_SIG_ALGO_ID_ECDSA_ED448_INTRINSIC. */
    if (   (signatureAlgorithmId == TCPIP_SIG_ALGO_ID_ECDSA_SECP256R1_SHA256)
        || (signatureAlgorithmId == TCPIP_SIG_ALGO_ID_ECDSA_SECP521R1_SHA512))
    {
      retVal = TcpIp_TlsServerCtx_VerifyClientCertVerifySignatureSecp(TlsConIdx, VerifySignatureCsmJobId,
        &signatureBufferConstSegment);
    }
    else
    {
      retVal = TcpIp_TlsServerCtx_VerifyClientCertVerifySignatureEdwards(TlsConIdx, VerifySignatureCsmJobId,
        &signatureBufferConstSegment);
    }
  }

  return retVal;
} /* TcpIp_TlsServerCtx_DecodeAndVerifyClientCertVerifySignature() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerCtx_VerifyClientCertVerifySignatureSecp
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCtx_VerifyClientCertVerifySignatureSecp(
  TcpIp_TlsConnectionIterType       TlsConIdx,
  TcpIp_CsmJobIdType                VerifySignatureCsmJobId,
  TCPIP_P2C(TcpIp_ConstSegmentType) SignatureBufferSegmentPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  Std_ReturnType csmRetVal = E_NOT_OK;
  Crypto_VerifyResultType verifyResult = CSM_E_VER_NOT_OK;

  /* Pointer to the ClientHello message in the TLS RxBuffer */
  TCPIP_P2C(uint8) clientHelloPtr = TcpIp_GetAddrTlsBufferRx(
    TcpIp_GetTlsBufferRxClientHelloIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx));
  uint32 clientHelloLen = ((uint32)TcpIp_GetClientHelloLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx) + TCPIP_TLS_HSHDRLEN);
  TCPIP_P2C(uint8) serverTxPtr = NULL_PTR;
  uint32           serverTxLen = 0u;
  TCPIP_P2C(uint8) clientRxPtr = NULL_PTR;
  uint32           clientRxLen = 0u;
  /* Both client finished and client certificate verify are not considered for the signature.
   * RFC 5246 chapter 7.4.8: "Here handshake_messages refers to all handshake messages sent or received,
   * starting at client hello and up to, but not including, this message [client certificate verify],
   * including the type and length fields of the handshake messages." */
  TcpIp_TlsServerCtx_GetPointerAndLengthOfLinearMessagesInBuffer(TlsConIdx, FALSE, FALSE,
    &serverTxPtr, &serverTxLen, &clientRxPtr, &clientRxLen);

  /* #10 Begin the hash with the clientHello message */
  csmRetVal = TCPIP_CSM_SignatureVerify(VerifySignatureCsmJobId,
    CRYPTO_OPERATIONMODE_START | CRYPTO_OPERATIONMODE_UPDATE, clientHelloPtr, clientHelloLen,
    SignatureBufferSegmentPtr->BasePtr, SignatureBufferSegmentPtr->Size, &verifyResult);

  /* #20 Update the hash with the server messages */
  csmRetVal |= TCPIP_CSM_SignatureVerify(VerifySignatureCsmJobId,
    CRYPTO_OPERATIONMODE_UPDATE, serverTxPtr, serverTxLen,
    SignatureBufferSegmentPtr->BasePtr, SignatureBufferSegmentPtr->Size, &verifyResult);

  /* #30 Update and finalize the hash with the client messages */
  csmRetVal |= TCPIP_CSM_SignatureVerify(VerifySignatureCsmJobId,
    CRYPTO_OPERATIONMODE_UPDATE | CRYPTO_OPERATIONMODE_FINISH, clientRxPtr, clientRxLen,
    SignatureBufferSegmentPtr->BasePtr, SignatureBufferSegmentPtr->Size, &verifyResult);

  /* Check if the CSM operation succeeded */
  retVal = TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal,
    0u, 0u, TCPIP_TLS_FCTID_SERVER_HSSTM_PARSE_CLIENTCERT);

  /* #40 Check if the verification was successful */
  if (verifyResult == CSM_E_VER_NOT_OK)
  {
    /* Invalid Signature - trigger TLS Alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECRYPT_ERROR);
    retVal = E_NOT_OK;
  }

  return retVal;
} /* TcpIp_TlsServerCtx_VerifyClientCertVerifySignatureSecp() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerCtx_VerifyClientCertVerifySignatureEdwards
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCtx_VerifyClientCertVerifySignatureEdwards(
  TcpIp_TlsConnectionIterType       TlsConIdx,
  TcpIp_CsmJobIdType                VerifySignatureCsmJobId,
  TCPIP_P2C(TcpIp_ConstSegmentType) SignatureBufferSegmentPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* Check if the temporary buffer is configured which is used to linearize the handshake messages.
   * This is also ensured by a validator. */
  if (TcpIp_IsTlsTemporaryClientAuthEdCurveBufferUsedOfTlsConnection(TlsConIdx) == TRUE)
  {
    const TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
      = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);
    TcpIp_SegmentType temporaryCertVerifyInputBufferSegment = { 0 };
    TcpIp_TlsTemporaryClientAuthEdCurveBufferIterType tlsTemporaryClientAuthEdCurveBufferStartIdx
      = TcpIp_GetTlsTemporaryClientAuthEdCurveBufferStartIdxOfTlsConnection(TlsConIdx);

    TcpIp_SegmentInit(&temporaryCertVerifyInputBufferSegment,
      TcpIp_GetAddrTlsTemporaryClientAuthEdCurveBuffer(tlsTemporaryClientAuthEdCurveBufferStartIdx),
      (uint32)TcpIp_GetTlsTemporaryClientAuthEdCurveBufferLengthOfTlsConnection(TlsConIdx));

    Std_ReturnType csmRetVal = E_NOT_OK;
    Crypto_VerifyResultType verifyResult = CSM_E_VER_NOT_OK;

    /* Pointer to the ClientHello message in the TLS RxBuffer */
    TCPIP_P2C(uint8) clientHelloPtr = TcpIp_GetAddrTlsBufferRx(
      TcpIp_GetTlsBufferRxClientHelloIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx));
    uint32 clientHelloLen = ((uint32)TcpIp_GetClientHelloLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx)
      + TCPIP_TLS_HSHDRLEN);
    TCPIP_P2C(uint8) serverTxPtr = NULL_PTR;
    uint32           serverTxLen = 0u;
    TCPIP_P2C(uint8) clientRxPtr = NULL_PTR;
    uint32           clientRxLen = 0u;
    /* Both client finished and client certificate verify are not considered for the signature.
     * RFC 5246 chapter 7.4.8: "Here handshake_messages refers to all handshake messages sent or received,
     * starting at client hello and up to, but not including, this message [client certificate verify],
     * including the type and length fields of the handshake messages." */
    TcpIp_TlsServerCtx_GetPointerAndLengthOfLinearMessagesInBuffer(TlsConIdx, FALSE, FALSE,
      &serverTxPtr, &serverTxLen, &clientRxPtr, &clientRxLen);

    /* Check if the buffer size is large enough for all handshake messages.
     * If this check fails the buffer size must be configured to a larger value. */
    if (temporaryCertVerifyInputBufferSegment.AvailLen >= (serverTxLen + clientRxLen + clientHelloLen))
    {
      TcpIp_SegmentMemCpy(&temporaryCertVerifyInputBufferSegment, clientHelloPtr, clientHelloLen);
      TcpIp_SegmentMemCpy(&temporaryCertVerifyInputBufferSegment, serverTxPtr, serverTxLen);
      TcpIp_SegmentMemCpy(&temporaryCertVerifyInputBufferSegment, clientRxPtr, clientRxLen);

      /* For the edwards curves the signature verify only works with a single call.
       * Therefore only in this case the temporary buffer is needed to linearize the handshake messages.
       * When using e.g. a Secp curve the signature verify can be called multiple times with
       * the operation mode CRYPTO_OPERATIONMODE_UPDATE for the handshake messages stored
       * in different areas in the buffer (see TcpIp_TlsServerCtx_VerifyClientCertVerifySignatureSecp). */
      csmRetVal = TCPIP_CSM_SignatureVerify(VerifySignatureCsmJobId,
        CRYPTO_OPERATIONMODE_SINGLECALL, temporaryCertVerifyInputBufferSegment.BasePtr,
        temporaryCertVerifyInputBufferSegment.Usage,
        SignatureBufferSegmentPtr->BasePtr, SignatureBufferSegmentPtr->Size, &verifyResult);

      /* Check if the CSM operation succeeded */
      retVal = TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal,
        0u, 0u, TCPIP_TLS_FCTID_SERVER_HSSTM_PARSE_CLIENTCERT);

      /* #10 Check if the verification was successful */
      if (verifyResult == CSM_E_VER_NOT_OK)
      {
        /* Invalid Signature - trigger TLS Alert */
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECRYPT_ERROR);
        retVal = E_NOT_OK;
      }
    }
    else
    {
      /* Temporary input buffer for certificate verification too small - trigger TLS Alert */
      /* The buffer size can be configured to a larger value to succesfully establish a handshake. */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
    }
  }
  else
  {
    /* Temporary input buffer for certificate verification not generated - trigger TLS Alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
  }

  return retVal;
} /* TcpIp_TlsServerCtx_VerifyClientCertVerifySignatureEdwards() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerCtx_ClientCertVerifyGetCsmJobId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCtx_ClientCertVerifyGetCsmJobId(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TCPIP_P2V(TcpIp_CsmJobIdType) VerifySignatureCsmJobIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_TlsHandshakeIndIterType tlsHandshakeIndIdx = 0u;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Find handshake with the signature algorithm Id received in the CertificateVerify. */
  for (tlsHandshakeIndIdx = TcpIp_GetTlsHandshakeIndStartIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx);
       tlsHandshakeIndIdx < TcpIp_GetTlsHandshakeIndEndIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx);
       tlsHandshakeIndIdx++)
  {
    TcpIp_TlsHandshakeIterType tlsHandshakeIdx = TcpIp_GetTlsHandshakeInd(tlsHandshakeIndIdx);
    if (tlsHandshakeIdx < TcpIp_GetSizeOfTlsHandshake())
    {
      const TcpIp_TlsServerConnectionIdxOfTlsConnectionType tlsServerConnectionIdx
        = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

      if (TcpIp_GetSignatureAlgorithmIdOfTlsHandshake(tlsHandshakeIdx) ==
            TcpIp_GetClientAuthSignatureAlgorithmIdOfTlsServerConnection(tlsServerConnectionIdx))
      {
        /* #20 Found fitting handshake, check if signature verify CSM job is referenced and if the buffer length is large enough. */
        /* Errors are handled inside TcpIp_TlsCoreUtil_PreVerifySignatureChecks(). */
        if (TcpIp_TlsCoreUtil_PreVerifySignatureChecks(TlsConIdx) == E_OK)
        {
          /* #30 Signature verify job found, return its Id. */
          /* If dynamic certificate groups are used, the Csm signature verify job reference cannot be determined from a
           * static configured handshake container. This is because only at runtime you know in which certificate slot
           * KeyM will store the leaf certificate, which is the first received certificate according to RFC5246 7.4.2.
           * Therefore get the certificate ID of the first received certificate and its configured Csm job Id.
           * Both is stored in TlsKeyMCertificate. */
          const TcpIp_TlsKeyMCertificateIterType tlsKeyMCertificateIdx
            = (TcpIp_TlsKeyMCertificateIterType)(TcpIp_GetAddrTlsCertValidationStatusDyn(
              TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx))->CertId);
          *VerifySignatureCsmJobIdPtr = TcpIp_GetCsmCertSignVerifyJobIdOfTlsKeyMCertificate(tlsKeyMCertificateIdx);
          retVal = E_OK;
        }
        break;
      }
    }
  }

  return retVal;
} /* TcpIp_TlsServerCtx_ClientCertVerifyGetCsmJobId() */
#   endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsServerCtx_GetPointerAndLengthOfLinearMessagesInBuffer
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerCtx_GetPointerAndLengthOfLinearMessagesInBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx,
  boolean                     IncludeClientFinished,
  boolean                     IncludeClientCertificateVerify,
  TCPIP_P2V(TcpIp_Uint8P2C)   ServerTxPtrPtr,
  TCPIP_P2V(uint32)           ServerTxLenPtr,
  TCPIP_P2V(TcpIp_Uint8P2C)   ClientRxPtrPtr,
  TCPIP_P2V(uint32)           ClientRxLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  const TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);
  boolean receivedClientCertificate = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the pointer to the transmitted server messages, which are linearized in the TLS TxBuffer */
  /* Messages: ServerHello ServerCertificate ServerKeyExchange ServerHelloDone */
  *ServerTxPtrPtr = TcpIp_GetAddrTlsBufferTx(
    TcpIp_GetTlsBufferTxServerHelloIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx));

  /* #20 Calculate the length of the transmitted server messages */
  /* If the messages are not sent (e.g. with PSK) the corresponding length is set to 0 */
  *ServerTxLenPtr = ((uint32)TcpIp_GetServerHelloLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx)
    + (uint32)TcpIp_GetServerCertificatesLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx)
    + (uint32)TcpIp_GetServerKeyExchangeLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx)
    + (uint32)TcpIp_GetCertificateRequestLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx)
    + (uint32)TcpIp_GetServerHelloDoneLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx));

  /* #30 Get the pointer to the received client messages, which are linearized in the TLS RxBuffer */
  if (TcpIp_GetTlsBufferRxClientCertificateIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx)
      == TCPIP_NO_TLSBUFFERRXCLIENTCERTIFICATEIDXOFTLSSERVERBUFFERMGMT)
  {
    /* The first message is either the client key exchange... */
    *ClientRxPtrPtr = TcpIp_GetAddrTlsBufferRx(
      TcpIp_GetTlsBufferRxClientKeyExchangeIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx));
  }
  else
  {
    /* ...or the client certificate message if client authentication is used in the current connection. */
    *ClientRxPtrPtr = TcpIp_GetAddrTlsBufferRx(
      TcpIp_GetTlsBufferRxClientCertificateIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx));
    receivedClientCertificate = TRUE;
  }

  /* #40 Calculate the length of the clientRx part */
  /* Length of the received client key exchange, client certificate and client certificate verify (if received). */
  if (receivedClientCertificate == TRUE)
  {
    *ClientRxLenPtr
      = ((uint32)TcpIp_GetClientKeyExchangeLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx) + TCPIP_TLS_HSHDRLEN)
      + ((uint32)TcpIp_GetClientCertificateLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx) + TCPIP_TLS_HSHDRLEN);
  }
  else
  {
    *ClientRxLenPtr
      = (uint32)TcpIp_GetClientKeyExchangeLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx) + TCPIP_TLS_HSHDRLEN;
  }

  if (  (IncludeClientCertificateVerify == TRUE)
     && (receivedClientCertificate == TRUE))
  {
    /* IncludeClientCertificateVerify is true,
     * the length of the received client certificate verify must be considered as well (if received). */
    *ClientRxLenPtr += ((uint32)TcpIp_GetClientCertificateVerifyLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx)
      + TCPIP_TLS_HSHDRLEN);
  }
  if (IncludeClientFinished == TRUE)
  {
    /* IncludeClientFinished is true, the length of the received client finished must be considered as well. */
    *ClientRxLenPtr += ((uint32)TcpIp_GetClientFinishedLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx)
      + TCPIP_TLS_HSHDRLEN);
  }
} /* TcpIp_TlsServerCtx_GetPointerAndLengthOfLinearMessagesInBuffer() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerCtx_CalcServerFinishedHash
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerCtx_CalcServerFinishedHash(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 localErrorId = TCPIP_TLS_ERRORID_NOT_SET;                                                                      /* PRQA S 2981 */ /* MD_TCPIP_Rule2.2_RedundantAssignment */
  uint8 finishedVerifyData[TCPIP_TLS_FINISHED_VERIFYDATA_LEN];
  boolean hashCalculated = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Generate the server finished hash which is needed for the finished verify data */
  if (TcpIp_TlsServerCrypto_GenerateHsHash(TlsConIdx, TCPIP_TLS_MSG_HASH_SERVER_FINISHED) == E_OK)
  {
    /* #20 Perform PRF on finished hash to calculate the finished verify data */
    if (TcpIp_TlsServerCrypto_CalcHsFinishedData(TlsConIdx, TCPIP_TLS_MSG_HASH_SERVER_FINISHED, finishedVerifyData) == E_OK)
    {
      /* #30 TLS verify finished data successfully calculated, now copy the finished verify data into the TLS TxBuffer */
      TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
        = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

       TcpIp_TlsBufferTxServerFinishedVerifyDataIdxOfTlsServerBufferMgmtType txServerFinishedVerifyDataIdx
         = TcpIp_GetTlsBufferTxServerFinishedVerifyDataIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

      if(((uint64)txServerFinishedVerifyDataIdx + TCPIP_TLS_FINISHED_VERIFYDATA_LEN) <= TcpIp_GetSizeOfTlsBufferTx())
      {
        TCPIP_P2V(uint8) tlsTxBufferFinishDestPtr = TcpIp_GetAddrTlsBufferTx(txServerFinishedVerifyDataIdx);            /* TCPIP_CSL_NAME_LENGTH */

        /* Copy the result into the TLS TxBuffer buffer */
        VStdMemCpy(tlsTxBufferFinishDestPtr, finishedVerifyData, TCPIP_TLS_FINISHED_VERIFYDATA_LEN);                    /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

        /* Calculation of finished verify data done - reset context state */
        TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);

        hashCalculated = TRUE;
      }
      else
      {
        /* Memory runtime check fails - report DET */
        TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
      }
    }
    else
    {
      /* Error - Calculation of finished verify data failed */
      localErrorId = TCPIP_TLS_ERRORID_CRYPTO_SERVERFINISHED_VERIFY_FAILED;
    }
  }
  else
  {
    /* Error - Calculation of finished hash failed */
    localErrorId = TCPIP_TLS_ERRORID_CRYPTO_SERVERFINISHED_HASH_FAILED;
  }

  if (hashCalculated == FALSE)
  {
    /* #40 Handle error while async CSM processing */
    TcpIp_TlsAsyncCtx_HandleErrorDuringAsyncJobProcessing(TlsConIdx,
      TCPIP_TLS_FCTID_SERVER_ASYNCCTX_CALC_FINISHED_HASH, localErrorId);
  }
} /* TcpIp_TlsServerCtx_CalcServerFinishedHash() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerCtx_CalcClientFinishedHash
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerCtx_CalcClientFinishedHash(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Generate the client finished hash */
  if (TcpIp_TlsServerCrypto_GenerateHsHash(TlsConIdx, TCPIP_TLS_MSG_HASH_CLIENT_FINISHED) == E_OK)
  {
    /* Calculation of finished hash done - reset context state */
    TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);
  }
  else
  {
    /* #20 Error - Calculation of client finished hash failed */
    TcpIp_TlsAsyncCtx_HandleErrorDuringAsyncJobProcessing(TlsConIdx,
      TCPIP_TLS_FCTID_SERVER_ASYNCCTX_CALC_CLIENTFINISHED_HASH, TCPIP_TLS_ERRORID_CRYPTO_CLIENTFINISHED_HASH_FAILED);
  }
} /* TcpIp_TlsServerCtx_CalcClientFinishedHash() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerCtx_CalcClientFinishedVerifyData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerCtx_CalcClientFinishedVerifyData(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TCPIP_P2V(uint8)  clientFinishedDestPtr =
    TcpIp_GetAddrTlsTemporaryFinishedBuffer(TcpIp_GetTlsTemporaryFinishedBufferStartIdxOfTlsConnection(TlsConIdx));

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Calculate the client finished verify data  */
  if (TcpIp_TlsServerCrypto_CalcHsFinishedData(TlsConIdx,
        TCPIP_TLS_MSG_HASH_CLIENT_FINISHED, clientFinishedDestPtr) == E_OK)
  {
    /* Calculation of finished verify data done - reset context state */
    TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);
  }
  else
  {
    /* #20 Error - Calculation of client finished hash failed */
    TcpIp_TlsAsyncCtx_HandleErrorDuringAsyncJobProcessing(TlsConIdx,
      TCPIP_TLS_FCTID_SERVER_ASYNCCTX_CALC_CLIENTFINISHED_VERIFY, TCPIP_TLS_ERRORID_CRYPTO_CLIENTFINISHED_VERIFY_FAILED);
  }
} /* TcpIp_TlsServerCtx_CalcClientFinishedVerifyData() */

/**********************************************************************************************************************
 *   TLS SERVER CRYPTO
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsServerCrypto_GenerateHsHash
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCrypto_GenerateHsHash(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsMessageFinishedType FinishedMessageType)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

  TcpIp_TlsTemporaryFinishedBufferStartIdxOfTlsConnectionType startTlsTemporaryFinishedBufferIdx
    = TcpIp_GetTlsTemporaryFinishedBufferStartIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsTemporaryFinishedBufferEndIdxOfTlsConnectionType endTlsTemporaryFinishedBufferIdx
    = TcpIp_GetTlsTemporaryFinishedBufferEndIdxOfTlsConnection(TlsConIdx);

  uint32 csmHashJobId = TcpIp_GetHashVerifyJobIdOfTlsHandshake(activeTlsHandshakeIdx);

  Std_ReturnType csmRetVal;
  Std_ReturnType retVal;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Prepare the received and transmitted TLS handshake message for the hash calculation */

  /* Use the temporary buffer to store the hash value temporarily */
  TCPIP_P2V(uint8) hsHashDestPtr = TcpIp_GetAddrTlsTemporaryFinishedBuffer(startTlsTemporaryFinishedBufferIdx);
  uint32 hsHashDestSpace = (uint32)endTlsTemporaryFinishedBufferIdx - startTlsTemporaryFinishedBufferIdx;

  /* Pointer to the ClientHello message in the TLS RxBuffer */
  TCPIP_P2C(uint8) clientHelloPtr = TcpIp_GetAddrTlsBufferRx(
    TcpIp_GetTlsBufferRxClientHelloIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx));
  uint32 clientHelloLen = ((uint32)TcpIp_GetClientHelloLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx) + TCPIP_TLS_HSHDRLEN);

  TCPIP_P2C(uint8) serverTxPtr = NULL_PTR;
  uint32           serverTxLen = 0u;
  TCPIP_P2C(uint8) clientRxPtr = NULL_PTR;
  uint32           clientRxLen = 0u;
  /* For server finished hash generation the received client finished must be considered as well. */
  boolean includeClientFinishedMsg = (FinishedMessageType == TCPIP_TLS_MSG_HASH_SERVER_FINISHED);
  /* Get the pointers and lengths of the linear server messages in the Tx buffer
   * and the linear client messages in the Rx buffer.
   * The client certificate verify shall always be considered when received. */
  TcpIp_TlsServerCtx_GetPointerAndLengthOfLinearMessagesInBuffer(TlsConIdx, includeClientFinishedMsg, TRUE,
    &serverTxPtr, &serverTxLen, &clientRxPtr, &clientRxLen);

  /* #20 Calculate the handshake hash */
  /* Begin the hash with the clientHello message */
  csmRetVal = TCPIP_CSM_Hash(csmHashJobId, CRYPTO_OPERATIONMODE_START | CRYPTO_OPERATIONMODE_UPDATE,
    clientHelloPtr, clientHelloLen, NULL_PTR, NULL_PTR);

  /* Update the hash with the server messages */
  csmRetVal |= TCPIP_CSM_Hash(csmHashJobId, CRYPTO_OPERATIONMODE_UPDATE, serverTxPtr, serverTxLen,
    NULL_PTR, NULL_PTR);

  /* Update and finalize the hash with the client messages */
  csmRetVal |= TCPIP_CSM_Hash(csmHashJobId, CRYPTO_OPERATIONMODE_UPDATE | CRYPTO_OPERATIONMODE_FINISH,
    clientRxPtr, clientRxLen, hsHashDestPtr, &hsHashDestSpace);

  /* Check if the CSM operation succeed */
  retVal = TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal,
    hsHashDestSpace, TCPIP_TLS_HASH_SHA256_LEN, TCPIP_TLS_FCTID_SERVER_CRYPTO_CALCHSFINISHEDHASH);

  return retVal;
} /* TcpIp_TlsServerCrypto_GenerateHsHash() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerCrypto_CalcHsFinishedData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCrypto_CalcHsFinishedData(
  TcpIp_TlsConnectionIterType    TlsConIdx,
  TcpIp_TlsMessageFinishedType   FinishedMessageType,
  TCPIP_P2V(uint8)               ResultPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx =
    TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

  TCPIP_P2C(uint8) labelPtr  = &TcpIp_Tls_Hs_FinishedLabel[FinishedMessageType][0];

  TCPIP_P2C(uint8) seedPtr   = TcpIp_GetAddrTlsTemporaryFinishedBuffer(
    TcpIp_GetTlsTemporaryFinishedBufferStartIdxOfTlsConnection(TlsConIdx));

  TcpIp_TlsCsmKeyInfoType msKey;
  TcpIp_TlsCsmKeyInfoType resultKey;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* Retrieve master shared secret to local key element */
  msKey.KeyId        = TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdMasterSecretIdxOfTlsHandshake(activeTlsHandshakeIdx));
  msKey.KeyElementId = TcpIp_GetHsCommonKeyElementIdOfTlsHandshake(activeTlsHandshakeIdx);
  msKey.KeyLen       = TCPIP_TLS_MASTER_SECRET_LEN;

  /* Retrieve Prf result key (contains result of verify data) to local key element */
  resultKey.KeyId        = TcpIp_GetPrfResultPublicKeyIdOfTlsHandshake(activeTlsHandshakeIdx);
  resultKey.KeyElementId = TcpIp_GetHsCommonKeyElementIdOfTlsHandshake(activeTlsHandshakeIdx);
  resultKey.KeyLen       = TCPIP_TLS_FINISHED_VERIFYDATA_LEN;

  /* #10 Calculate the TLS handshake finished data using the PRF with the hash, master secret and label */
  if (TcpIp_Tls12CoreCrypto_Prf(TlsConIdx, &resultKey, &msKey, labelPtr, seedPtr, TCPIP_TLS_LABEL_FINISHED_LEN,
        TCPIP_TLS_HASH_SHA256_LEN, FALSE) == E_OK)
  {
    /* #20 Write the calculated finished data (stored in CSM Key) into destination buffer */
    Std_ReturnType csmRetVal;
    uint32 tmpLen = resultKey.KeyLen;
    csmRetVal = TCPIP_CSM_KeyElementGet( resultKey.KeyId, resultKey.KeyElementId, ResultPtr, &tmpLen);

    /* Check if the CSM operation succeed */
    /* User error handling is done outside of this function */
   retVal = TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, tmpLen, resultKey.KeyLen,
     TCPIP_TLS_FCTID_SERVER_CRYPTO_CALCHSFINISHEDDATA);
  }

  return retVal;
} /* TcpIp_TlsServerCrypto_CalcHsFinishedData() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerCrypto_SetCsmKeys
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
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCrypto_SetCsmKeys(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherStreamingModeDataType selectedStreamingMode
    = TcpIp_TlsCoreUtil_ReturnSelectedCipherSpecificStreamingMode(TlsConIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Select the active streaming method of the used cipher suite */
  switch (selectedStreamingMode)
  {
    case TCPIP_TLS_STREAMING_MODE_AES_128_CBC:
    {
      /* #20 Set CSM keys for AES-128-CBC streaming method */
      /* X_WITH_AES_128_CBC_SHAX
           TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA
           TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256
           TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA
           TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256
      */
      retVal = TcpIp_TlsServerCrypto_SetCsmKeysAes128CbcStreaming(TlsConIdx);
      break;
    } /* case TCPIP_TLS_STREAMING_MODE_AES_128_CBC */

    case TCPIP_TLS_STREAMING_MODE_AES_128_GCM:
    {
      /* #30 Set CSM keys for AES-128-GCM streaming method */
      /* X_WITH_AES_128_GCM_SHAX
           TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA
           TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA256
           TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA
           TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256
      */
      retVal = TcpIp_TlsServerCrypto_SetCsmKeysAes128GcmStreaming(TlsConIdx);
      break;
    } /* case TCPIP_TLS_STREAMING_MODE_AES_128_GCM */

    case TCPIP_TLS_STREAMING_MODE_NULL:
    {
      /* #40 Set CSM keys for NULL streaming method */
      /* X_WITH_NULL_SHAX
           TCPIP_TLS_ECDH_ECDSA_WITH_NULL_SHA
      */
      retVal = TcpIp_TlsServerCrypto_SetCsmKeysNullStreaming(TlsConIdx);
      break;
    } /* case TCPIP_TLS_STREAMING_MODE_NULL */

    default:                                                                                                            /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
    {
      /* Default path is never used since a valid mode was set earlier in the handshake - left blank intentionally */
      break;
    } /* default */

  } /* switch */

  /* #50 Report error in case of invalid active streaming method or setting of CSM keys failed */
  if ( retVal != E_OK)
  {
    TcpIp_TlsUserErrorType userError;

    userError.FunctionId  = TCPIP_TLS_FCTID_SERVER_CRYPTO_SETCSMKEYS;
    userError.UserErrorId = TCPIP_TLS_ERRORID_CRYPTO_SETCSMKEYS_FAILED;
    userError.TlsConId    = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(userError);
  }

  return retVal;
} /* TcpIp_TlsServerCrypto_SetCsmKeys() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerCrypto_SetCsmKeysAes128CbcStreaming
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCrypto_SetCsmKeysAes128CbcStreaming(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx);

  TcpIp_TlsCsmJobIterType macGenerateTlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
    TcpIp_GetCsmJobIdHmacGenerateIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));

  TcpIp_TlsCsmJobIterType macVerifyTlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
    TcpIp_GetCsmJobIdHmacVerifyIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));

  TcpIp_TlsCsmJobIterType decryptTlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
    TcpIp_GetCsmJobIdCipherDecryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));

  TcpIp_TlsCsmJobIterType encryptTlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
    TcpIp_GetCsmJobIdCipherEncryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));

  TcpIp_TlsCsmKeyInfoType keyBlockKey;
  TcpIp_TlsCsmKeyInfoType txHMacShaKey;

  Std_ReturnType csmRetVal;

  /* ----- Implementation ----------------------------------------------- */
  /* Generated keyBlock is the source for all the relevant keys */
  keyBlockKey.KeyId        = TcpIp_GetPrfResultPrivateKeyIdOfTlsHandshake(activeTlsHandshakeIdx);
  keyBlockKey.KeyElementId = TcpIp_GetHsCommonKeyElementIdOfTlsHandshake(activeTlsHandshakeIdx);

  /* #10 Set CSM keys for TX MAC operations - used during transmit of TLS messages */
  txHMacShaKey.KeyId        = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(macGenerateTlsCsmJobIdx);
  txHMacShaKey.KeyElementId = CRYPTO_KE_MAC_KEY;
  txHMacShaKey.KeyLen       = TcpIp_GetCipherMacKeyLengthOfTlsCipherWorker(activeTlsCipherWorkerIdx);

  csmRetVal  = TcpIp_TlsCoreCrypto_ClearCsmKey(TlsConIdx, &txHMacShaKey);
  csmRetVal |= TCPIP_CSM_KeyElementCopyPartial(keyBlockKey.KeyId, keyBlockKey.KeyElementId, txHMacShaKey.KeyLen,
    0, txHMacShaKey.KeyLen, txHMacShaKey.KeyId, txHMacShaKey.KeyElementId);

  if (TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, 0, 0, TCPIP_TLS_FCTID_SERVER_CRYPTO_SETCSMKEYSAES128CBC) == E_OK)
  {
    TcpIp_TlsCsmKeyInfoType rxHMacShaKey;

    (void)TCPIP_CSM_KeySetValid(txHMacShaKey.KeyId);

    /* #20 Set CSM keys for RX MAC operations - used during reception of TLS messages */
    rxHMacShaKey.KeyId = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(macVerifyTlsCsmJobIdx);
    rxHMacShaKey.KeyElementId = CRYPTO_KE_MAC_KEY;
    rxHMacShaKey.KeyLen = TcpIp_GetCipherMacKeyLengthOfTlsCipherWorker(activeTlsCipherWorkerIdx);

    csmRetVal = TcpIp_TlsCoreCrypto_ClearCsmKey(TlsConIdx, &rxHMacShaKey);
    csmRetVal |= TCPIP_CSM_KeyElementCopyPartial(keyBlockKey.KeyId, keyBlockKey.KeyElementId, 0, 0,
      rxHMacShaKey.KeyLen, rxHMacShaKey.KeyId, rxHMacShaKey.KeyElementId);

    if (TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, 0, 0, TCPIP_TLS_FCTID_SERVER_CRYPTO_SETCSMKEYSAES128CBC) == E_OK)
    {
      TcpIp_TlsCsmKeyInfoType txAesKey;

      (void)TCPIP_CSM_KeySetValid(rxHMacShaKey.KeyId);

      /* #30 Set CSM keys for TX AES operations - used during transmit of TLS messages */
      txAesKey.KeyId = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(encryptTlsCsmJobIdx);
      txAesKey.KeyElementId = CRYPTO_KE_CIPHER_KEY;
      txAesKey.KeyLen = TCPIP_TLS_AES128_KEY_LEN;

      csmRetVal = TcpIp_TlsCoreCrypto_ClearCsmKey(TlsConIdx, &txAesKey);
      csmRetVal |= TCPIP_CSM_KeyElementCopyPartial(keyBlockKey.KeyId, keyBlockKey.KeyElementId,
        txHMacShaKey.KeyLen + rxHMacShaKey.KeyLen + txAesKey.KeyLen, 0, txAesKey.KeyLen, txAesKey.KeyId, txAesKey.KeyElementId);

      if (TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, 0, 0, TCPIP_TLS_FCTID_SERVER_CRYPTO_SETCSMKEYSAES128CBC) == E_OK)
      {
        TcpIp_TlsCsmKeyInfoType rxAesKey;

        (void)TCPIP_CSM_KeySetValid(txAesKey.KeyId);

        /* #40 Set CSM keys for RX AES operations - used during reception of TLS messages */
        rxAesKey.KeyId = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(decryptTlsCsmJobIdx);
        rxAesKey.KeyElementId = CRYPTO_KE_CIPHER_KEY;
        rxAesKey.KeyLen = TCPIP_TLS_AES128_KEY_LEN;

        csmRetVal = TcpIp_TlsCoreCrypto_ClearCsmKey(TlsConIdx, &rxAesKey);
        csmRetVal |= TCPIP_CSM_KeyElementCopyPartial(keyBlockKey.KeyId, keyBlockKey.KeyElementId,
          txHMacShaKey.KeyLen + rxHMacShaKey.KeyLen, 0, rxAesKey.KeyLen, rxAesKey.KeyId, rxAesKey.KeyElementId);

        if (TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, 0, 0, TCPIP_TLS_FCTID_SERVER_CRYPTO_SETCSMKEYSAES128CBC) == E_OK)
        {
          (void)TCPIP_CSM_KeySetValid(rxAesKey.KeyId);
        }
      }
    }
  }


  return csmRetVal;
} /* TcpIp_TlsServerCrypto_SetCsmKeysAes128CbcStreaming() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerCrypto_SetCsmKeysAes128GcmStreaming
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCrypto_SetCsmKeysAes128GcmStreaming(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx);

  TcpIp_TlsCsmJobIterType decryptTlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
    TcpIp_GetCsmJobIdCipherDecryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));

  TcpIp_TlsCsmJobIterType encryptTlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
    TcpIp_GetCsmJobIdCipherEncryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));

  TcpIp_TlsCsmKeyInfoType keyBlockKey;
  TcpIp_TlsCsmKeyInfoType txAesKey;

  Std_ReturnType csmRetVal;
  /* ----- Implementation ----------------------------------------------- */
  /* Generated keyBlock is the source for all the relevant keys */
  keyBlockKey.KeyId = TcpIp_GetPrfResultPrivateKeyIdOfTlsHandshake(activeTlsHandshakeIdx);
  keyBlockKey.KeyElementId = TcpIp_GetHsCommonKeyElementIdOfTlsHandshake(activeTlsHandshakeIdx);


  /* For Aes128Gcm the key block is parsed as below
   *  0..15  Client encrypt key
   *  16..31 Server encrypt key
   *  32..35 Client Iv
   *  36..40 Server Iv
   */

  /* #10 Set CSM keys for TX AES operations - used during transmit of TLS messages */
  txAesKey.KeyId        = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(encryptTlsCsmJobIdx);
  txAesKey.KeyElementId = CRYPTO_KE_CIPHER_KEY;
  txAesKey.KeyLen       = TCPIP_TLS_BLOCK128_KEY_LEN;

  csmRetVal  = TcpIp_TlsCoreCrypto_ClearCsmKey(TlsConIdx, &txAesKey);
  csmRetVal |= TCPIP_CSM_KeyElementCopyPartial( keyBlockKey.KeyId, keyBlockKey.KeyElementId, txAesKey.KeyLen, 0,
    txAesKey.KeyLen, txAesKey.KeyId, txAesKey.KeyElementId );

  if (TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, 0, 0, TCPIP_TLS_FCTID_SERVER_CRYPTO_SETCSMKEYSAES128GCM) == E_OK)
  {
    TcpIp_TlsCsmKeyInfoType rxAesKey;

    (void)TCPIP_CSM_KeySetValid(txAesKey.KeyId);

    /* #20 Set CSM keys for RX AES operations - used during reception of TLS messages */
    rxAesKey.KeyId        = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(decryptTlsCsmJobIdx);
    rxAesKey.KeyElementId = CRYPTO_KE_CIPHER_KEY;
    rxAesKey.KeyLen       = TCPIP_TLS_AES128_KEY_LEN;

    csmRetVal = TcpIp_TlsCoreCrypto_ClearCsmKey(TlsConIdx, &rxAesKey);
    csmRetVal |= TCPIP_CSM_KeyElementCopyPartial(keyBlockKey.KeyId, keyBlockKey.KeyElementId, 0, 0,
      rxAesKey.KeyLen, rxAesKey.KeyId, rxAesKey.KeyElementId);

    if (TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, 0, 0, TCPIP_TLS_FCTID_SERVER_CRYPTO_SETCSMKEYSAES128GCM) == E_OK)
    {
      TcpIp_TlsCsmKeyInfoType txHMacShaKey;
      TcpIp_TlsCsmKeyInfoType rxHMacShaKey;

      (void)TCPIP_CSM_KeySetValid(rxAesKey.KeyId);

      /* #30 Set CSM keys for TX IV */
      txHMacShaKey.KeyId        = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(encryptTlsCsmJobIdx);
      txHMacShaKey.KeyElementId = CRYPTO_KE_CIPHER_IV;
      txHMacShaKey.KeyLen       = TCPIP_TLS_BLOCK128_IMPLICIT_IV_LEN;

      csmRetVal = TcpIp_TlsCoreCrypto_ClearCsmKey(TlsConIdx, &txHMacShaKey);
      csmRetVal |= TCPIP_CSM_KeyElementCopyPartial(keyBlockKey.KeyId, keyBlockKey.KeyElementId,
        rxAesKey.KeyLen + txAesKey.KeyLen + txHMacShaKey.KeyLen, 0, txHMacShaKey.KeyLen, txHMacShaKey.KeyId, txHMacShaKey.KeyElementId);

      if (TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, 0, 0, TCPIP_TLS_FCTID_SERVER_CRYPTO_SETCSMKEYSAES128GCM) == E_OK)
      {
        /* IV value does not have to be set valid in CSM, because it is automatically set valid on the first round of AES operation - do nothing */
      }

      /* #40 Set CSM keys for RX IV */
      rxHMacShaKey.KeyId        = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(decryptTlsCsmJobIdx);
      rxHMacShaKey.KeyElementId = CRYPTO_KE_CIPHER_IV;
      rxHMacShaKey.KeyLen       = TCPIP_TLS_BLOCK128_IMPLICIT_IV_LEN;

      csmRetVal = TcpIp_TlsCoreCrypto_ClearCsmKey(TlsConIdx, &rxHMacShaKey);
      csmRetVal |= TCPIP_CSM_KeyElementCopyPartial(keyBlockKey.KeyId, keyBlockKey.KeyElementId,
        rxAesKey.KeyLen + txAesKey.KeyLen, 0, rxHMacShaKey.KeyLen, rxHMacShaKey.KeyId, rxHMacShaKey.KeyElementId);

      if (TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, 0, 0, TCPIP_TLS_FCTID_SERVER_CRYPTO_SETCSMKEYSAES128GCM) == E_OK)
      {
        /* IV value does not have to be set valid in CSM, because it is automatically set valid on the first round of AES operation - do nothing */
      }
    }
  }

  return csmRetVal;
} /* TcpIp_TlsServerCrypto_SetCsmKeysAes128GcmStreaming() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerCrypto_SetCsmKeysNullStreaming
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerCrypto_SetCsmKeysNullStreaming(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx);

  TcpIp_TlsCsmJobIterType macGenerateTlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
    TcpIp_GetCsmJobIdHmacGenerateIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));

  TcpIp_TlsCsmJobIterType macVerifyTlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
    TcpIp_GetCsmJobIdHmacVerifyIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));

  TcpIp_TlsCsmKeyInfoType keyBlockKey;
  TcpIp_TlsCsmKeyInfoType txHMacShaKey;
  TcpIp_TlsCsmKeyInfoType rxHMacShaKey;
  Std_ReturnType csmRetVal;
  /* ----- Implementation ----------------------------------------------- */
  /* Generated keyBlock is the source for all the relevant keys */
  keyBlockKey.KeyId        = TcpIp_GetPrfResultPrivateKeyIdOfTlsHandshake(activeTlsHandshakeIdx);
  keyBlockKey.KeyElementId = TcpIp_GetHsCommonKeyElementIdOfTlsHandshake(activeTlsHandshakeIdx);

  /* #10 Set CSM keys for TX MAC operations - used during transmit of TLS messages */
  txHMacShaKey.KeyId        = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(macGenerateTlsCsmJobIdx);
  txHMacShaKey.KeyElementId = CRYPTO_KE_MAC_KEY;
  txHMacShaKey.KeyLen       = TcpIp_GetCipherMacKeyLengthOfTlsCipherWorker(activeTlsCipherWorkerIdx);

  csmRetVal  = TcpIp_TlsCoreCrypto_ClearCsmKey(TlsConIdx, &txHMacShaKey);
  csmRetVal |= TCPIP_CSM_KeyElementCopyPartial(keyBlockKey.KeyId, keyBlockKey.KeyElementId, txHMacShaKey.KeyLen, 0,
    txHMacShaKey.KeyLen, txHMacShaKey.KeyId, txHMacShaKey.KeyElementId);

  if (TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, 0, 0, TCPIP_TLS_FCTID_SERVER_CRYPTO_SETCSMKEYSNULL) == E_OK)
  {
    (void)TCPIP_CSM_KeySetValid(txHMacShaKey.KeyId);

    /* #20 Set CSM keys for RX MAC operations - used during reception of TLS messages */
    rxHMacShaKey.KeyId = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(macVerifyTlsCsmJobIdx);
    rxHMacShaKey.KeyElementId = CRYPTO_KE_MAC_KEY;
    rxHMacShaKey.KeyLen = TcpIp_GetCipherMacKeyLengthOfTlsCipherWorker(activeTlsCipherWorkerIdx);

    csmRetVal = TcpIp_TlsCoreCrypto_ClearCsmKey(TlsConIdx, &rxHMacShaKey);
    csmRetVal |= TCPIP_CSM_KeyElementCopyPartial(keyBlockKey.KeyId, keyBlockKey.KeyElementId, 0, 0,
      rxHMacShaKey.KeyLen, rxHMacShaKey.KeyId, rxHMacShaKey.KeyElementId);

    if (TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, 0, 0, TCPIP_TLS_FCTID_SERVER_CRYPTO_SETCSMKEYSNULL) == E_OK)
    {
      (void)TCPIP_CSM_KeySetValid(rxHMacShaKey.KeyId);
    }
  }


  return csmRetVal;
} /* TcpIp_TlsServerCrypto_SetCsmKeysNullStreaming() */

/**********************************************************************************************************************
 *   TLS SERVER TX RECORD LAYER FORWARDING
 *********************************************************************************************************************/
 /**********************************************************************************************************************
 *  TcpIp_TlsServerTx_CheckForTransmittableProcessedHsMsg
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
FUNC(void, TCPIP_CODE) TcpIp_TlsServerTx_CheckForTransmittableProcessedHsMsg(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);
  boolean processFurtherHsMsg = TRUE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the ServerHello message is transmittable */
  if (TcpIp_IsHelloReadyToSendOfTlsServerConnection(tlsServerConnectionIdx) == TRUE)
  {
    /* If so, forward ServerHello message to the record layer */
    processFurtherHsMsg = TcpIp_TlsServerTx_ForwardProcessedHsMsgToRl(TlsConIdx, TCPIP_TLS_HSTYPE_SERVERHELLO);
  }

  /* #20 Check if the last message was successfully forwarded to the record layer and if the ServerCertificate message is transmittable */
  if ((processFurtherHsMsg == TRUE) && (TcpIp_IsCertificateReadyToSendOfTlsServerConnection(tlsServerConnectionIdx) == TRUE))
  {
    /* If so, forward ServerCertificate message to the record layer */
    processFurtherHsMsg = TcpIp_TlsServerTx_ForwardProcessedHsMsgToRl(TlsConIdx, TCPIP_TLS_HSTYPE_CERTIFICATE);
  }

  /* #30 Check if the last message was successfully forwarded to the record layer and if the ServerKeyExchange message is transmittable */
  if ((processFurtherHsMsg == TRUE) && (TcpIp_IsKeyExchangeReadyToSendOfTlsServerConnection(tlsServerConnectionIdx) == TRUE))
  {
    /* If so, forward ServerKeyExchange message to the record layer */
    processFurtherHsMsg = TcpIp_TlsServerTx_ForwardProcessedHsMsgToRl(TlsConIdx, TCPIP_TLS_HSTYPE_SERVERKEYEXCHANGE);
  }

  /* #40 Check if the last message was successfully forwarded to the record layer and if the CertificateRequest message is transmittable */
  if ((processFurtherHsMsg == TRUE) && (TcpIp_IsCertificateRequestReadyToSendOfTlsServerConnection(tlsServerConnectionIdx) == TRUE))
  {
    /* If so, forward CertificateRequest message to the record layer */
    processFurtherHsMsg = TcpIp_TlsServerTx_ForwardProcessedHsMsgToRl(TlsConIdx, TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST);
  }

  /* #50 Check if the last message was successfully forwarded to the record layer and if the ServerHelloDone message is transmittable */
  if ((processFurtherHsMsg == TRUE) && (TcpIp_IsHelloDoneReadyToSendOfTlsServerConnection(tlsServerConnectionIdx) == TRUE))
  {
    /* If so, forward ServerHelloDone message to the record layer */
    processFurtherHsMsg = TcpIp_TlsServerTx_ForwardProcessedHsMsgToRl(TlsConIdx, TCPIP_TLS_HSTYPE_SERVERHELLODONE);
  }

  /* #60 Check if the last message was successfully forwarded to the record layer and if the ServerFinished message is transmittable */
  /* When the transmit of the CCS fails, the decryption won't be enabled.
   * If somehow the transmit of the Finished message works we will send unencrypted data.
   * To avoid this check if the CCS flag is already set to false which means the CCS was transmitted successfully. */
  if (   (processFurtherHsMsg == TRUE)
      && (TcpIp_IsServerFinishedReadyToSendOfTlsServerConnection(tlsServerConnectionIdx) == TRUE)
      && (TcpIp_IsChangeCipherSpecReadyToSendOfTlsServerConnection(tlsServerConnectionIdx) == FALSE))
  {
    /* If so, forward ServerFinished message to the record layer; the return value is disregarded */
    (void) TcpIp_TlsServerTx_ForwardProcessedHsMsgToRl(TlsConIdx, TCPIP_TLS_HSTYPE_FINISHED);
  }

} /* TcpIp_TlsServerTx_CheckForTransmittableProcessedHsMsg() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerTx_ForwardProcessedHsMsgToRl
 *********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
  */
/* PRQA S 6030, 6050 1 */ /* MD_TcpIp_TlsStatemachine_STCYC_6030, MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsServerTx_ForwardProcessedHsMsgToRl(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(TcpIp_TlsMsgHandshakeType, AUTOMATIC) HandshakeType)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);
  boolean processFurtherHsMsg = FALSE;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Forward the different handshake messages to the record layer depending on the passed HandshakeType */
  switch (HandshakeType)
  {
    case TCPIP_TLS_HSTYPE_SERVERHELLO:
    {
      /* Forward the ServerHello message to the record layer */
      if (TcpIp_TlsCoreRl_Transmit(TlsConIdx, TcpIp_GetTlsBufferTxServerHelloIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx),
        TcpIp_GetServerHelloLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx), TCPIP_TLS_CT_HS) == E_OK)
      {
        /* If successful, reset the TX indication flag for this message */
        TcpIp_SetHelloReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
        processFurtherHsMsg = TRUE;
      }
      break;
    } /* case TCPIP_TLS_HSTYPE_SERVERHELLO */

    case TCPIP_TLS_HSTYPE_CERTIFICATE:
    {
      /* Forward the ServerCertificate message to the record layer */
      if (TcpIp_TlsCoreRl_Transmit(TlsConIdx, TcpIp_GetTlsBufferTxServerCertificatesIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx),
        TcpIp_GetServerCertificatesLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx), TCPIP_TLS_CT_HS) == E_OK)
      {
        /* If successful, reset the TX indication flag for this message */
        TcpIp_SetCertificateReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
        processFurtherHsMsg = TRUE;
      }
      break;
    } /* case TCPIP_TLS_HSTYPE_CERTIFICATE */

    case TCPIP_TLS_HSTYPE_SERVERKEYEXCHANGE:
    {
      /* Forward the ServerKeyExchange message to the record layer */
      if (TcpIp_TlsCoreRl_Transmit(TlsConIdx, TcpIp_GetTlsBufferTxServerKeyExchangeIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx),
        TcpIp_GetServerKeyExchangeLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx), TCPIP_TLS_CT_HS) == E_OK)
      {
        /* If successful, reset the TX indication flag for this message */
        TcpIp_SetKeyExchangeReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
        processFurtherHsMsg = TRUE;
      }
      break;
    } /* case TCPIP_TLS_HSTYPE_SERVERKEYEXCHANGE */

    case TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST:
    {
      /* Forward the CertificateRequest message to the record layer */
      if (TcpIp_TlsCoreRl_Transmit(TlsConIdx, TcpIp_GetTlsBufferTxCertificateRequestIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx),
        TcpIp_GetCertificateRequestLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx), TCPIP_TLS_CT_HS) == E_OK)
      {
        /* If successful, reset the TX indication flag for this message */
        TcpIp_SetCertificateRequestReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
        processFurtherHsMsg = TRUE;
      }
      break;
    } /* case TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST */

    case TCPIP_TLS_HSTYPE_SERVERHELLODONE:
    {
      /* Forward the ServerHelloDone message to the record layer */
      if (TcpIp_TlsCoreRl_Transmit(TlsConIdx, TcpIp_GetTlsBufferTxServerHelloDoneIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx),
        TcpIp_GetServerHelloDoneLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx), TCPIP_TLS_CT_HS) == E_OK)
      {
        /* If successful, reset the TX indication flag for this message */
        TcpIp_SetHelloDoneReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
        processFurtherHsMsg = TRUE;
      }
      break;
    } /* case TCPIP_TLS_HSTYPE_SERVERHELLODONE */

    case TCPIP_TLS_HSTYPE_FINISHED:
    {
      /* Forward the ServerFinished message to the record layer */
      if (TcpIp_TlsCoreRl_Transmit(TlsConIdx, TcpIp_GetTlsBufferTxServerFinishedIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx),
        TcpIp_GetServerFinishedLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx), TCPIP_TLS_CT_HS) == E_OK)
      {
        /* If successful, reset the TX indication flag for this message */
        TcpIp_SetServerFinishedReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
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

} /* TcpIp_TlsServerTx_ForwardProcessedHsMsgToRl() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerTx_SendChangeCipherSpec
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(void, TCPIP_CODE) TcpIp_TlsServerTx_SendChangeCipherSpec(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferTxCcsStartIdxOfTlsBufferMgmtType ccsStartTlsBufferTxIdx
    = TcpIp_GetTlsBufferTxCcsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Write the TLS CCS payload (0x01) into the TLS Tx CCS Buffer */
  IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(ccsStartTlsBufferTxIdx), 0, TCPIP_TLS_CHANGECIPHERSPEC);

  /* #20 Transmit the frame via the TLS record layer */
  if (TcpIp_TlsCoreRl_Transmit(TlsConIdx, ccsStartTlsBufferTxIdx, TCPIP_TLS_CCSMSG_LEN, TCPIP_TLS_CT_CCS) == E_OK)
  {
    TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

    TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx
      = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

    /* Get the index of the current CipherDefiniton */
    TcpIp_TlsCipherDefinitionIdxOfTlsCipherWorkerType tlsCipherDefinitionIdx
      = TcpIp_GetTlsCipherDefinitionIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx);

    /* Get the corresponding Cipher Id (HexCode) */
    TcpIp_CipherSuiteIdOfTlsCipherDefinitionType selectedCipherSuiteId
      = TcpIp_GetCipherSuiteIdOfTlsCipherDefinition(tlsCipherDefinitionIdx);

    /* Reset the Transmit Flag */
    TcpIp_SetChangeCipherSpecReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, FALSE);

    /* #30 Update the active cipher for the TX direction */
    TcpIp_SetActiveCipherTxOfTlsConnectionDyn(TlsConIdx, selectedCipherSuiteId);
  }
} /* TcpIp_TlsServerTx_SendChangeCipherSpec() */

/**********************************************************************************************************************
 *   TLS SERVER HANDSHAKE STATE MACHINE
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsServer_ProcessHandshake
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsServer_ProcessHandshake(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the current connection is in an active HS state */
  if (   ((TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx)) == (TCPIP_TLS_STATE_CONNECTION_HS_ACTIVE))            /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
      || ((TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx)) == (TCPIP_TLS_STATE_CONNECTION_SERVER_HS_FINALIZING)))
  {
    /* #20 Check that there is no async operation in process */
    if (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_ASYNC_PENDING)
    {
      /* #30 Check if we have at least one trigger to process the HS */
              /* Next state is a TX state */
      if (   (TcpIp_IsHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx) == TRUE)                                              /* PRQA S 3415 6 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
              /* AsyncCtx operation is done, continue HS */
          || (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_DONE)
              /* Unprocessed HS message in the buffer */
          || (TcpIp_GetHsRxIndicationCntOfTlsConnectionDyn(TlsConIdx) != 0u)
              /* Unprocessed CCS message in the buffer */
          || (TcpIp_IsCcsRxIndicationOfTlsConnectionDyn(TlsConIdx) == TRUE))
      {
        /* #40 Perform the next Step within the current HS flow */
        TcpIp_TlsServerHsStm_PerformNextHsStep(TlsConIdx);

      } /* else - otherwise do nothing */
    } /* else - otherwise do nothing */
  } /* else - otherwise do nothing */

} /* TcpIp_TlsServer_ProcessHandshake() */


/**********************************************************************************************************************
 *  TcpIp_TlsServerHsStm_PerformNextHsStep
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030, 6050 1 */ /* MD_MSR_STCYC, MD_TcpIp_TlsStatemachine_STCAL_6050 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_PerformNextHsStep(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Process the TLS-Server handshake depending on the current sate */
  switch (TCPIP_TLS_GET_HS_STATE(TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx)))
  {

    case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_HELLO:
    {
      TcpIp_TlsServerHsStm_ParseClientHello(TlsConIdx);
      break;
    }

    case TCPIP_TLS_STATE_SEND_SERVER_HELLO:
    {
      if(TCPIP_TLS_HS_CHECK_BUFFER_IDX(TlsConIdx, TCPIP_TLS_MAX_TX_SERVER_HELLO_MESSAGE_LENGTH))
      {
        TcpIp_TlsServerHsStm_SendServerHello(TlsConIdx);
      }
      else
      {
        /* Memory runtime check fails - report DET */
        TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
      }
      break;
    }

    case TCPIP_TLS_STATE_SEND_SERVER_CERTIFICATE:
    {
#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)                                                                             /* COV_MSR_UNSUPPORTED */
      if(TCPIP_TLS_HS_CHECK_BUFFER_IDX(TlsConIdx, TcpIp_GetTlsSumLocalCertMaxLengthOfTlsConnection(TlsConIdx)))
      {
        TcpIp_TlsServerHsStm_SendServerCertificate(TlsConIdx);
      }
      else
      {
        /* Memory runtime check fails - report DET */
        TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
      }
#   endif
      break;
    }

    case TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE:
    {
      if(TCPIP_TLS_HS_CHECK_BUFFER_IDX(TlsConIdx, TCPIP_TLS_MAX_TX_SERVER_KEY_EXCHANGE_MESSAGE_LENGTH))
      {
        TcpIp_TlsServerHsStm_SendServerKeyExchange(TlsConIdx);
      }
      else
      {
        /* Memory runtime check fails - report DET */
        TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
      }
      break;
    }

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
    case TCPIP_TLS_STATE_SEND_SERVER_CERTIFICATE_REQUEST:
    {
      if(TCPIP_TLS_HS_CHECK_BUFFER_IDX(TlsConIdx, TCPIP_TLS_MAX_TX_SERVER_CERTIFICATE_REQUEST_MESSAGE_LENGTH))
      {
        TcpIp_TlsServerHsStm_SendCertificateRequest(TlsConIdx);
      }
      break;
    }
#   endif

    case TCPIP_TLS_STATE_SEND_SERVER_HELLO_DONE:
    {
     /* No memory runtime check necessary since the actual message length is zero */
      TcpIp_TlsServerHsStm_SendServerHelloDone(TlsConIdx);
      break;
    }

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
    case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE:
    {
      TcpIp_TlsServerHsStm_ParseClientCertificate(TlsConIdx);
      break;
    }
#   endif

    case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE:
    {
      TcpIp_TlsServerHsStm_ParseClientKeyExchange(TlsConIdx);
      break;
    }

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
    case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFY:
    {
      TcpIp_TlsServerHsStm_ParseClientCertificateVerify(TlsConIdx);
      break;
    }
#   endif

    case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CCS:
    {
      TcpIp_TlsServerHsStm_ParseClientCcs(TlsConIdx);
      break;
    }

    case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_FINISHED:
    {
      TcpIp_TlsServerHsStm_ParseClientFinished(TlsConIdx);
      break;
    }

    case TCPIP_TLS_STATE_SEND_SERVER_CCS:
    {
      /* No memory runtime check necessary since the actual message length is zero */
      TcpIp_TlsServerHsStm_SendServerCcs(TlsConIdx);
      break;
    }

    case TCPIP_TLS_STATE_SEND_SERVER_FINISHED:
    {
      if(TCPIP_TLS_HS_CHECK_BUFFER_IDX(TlsConIdx, TCPIP_TLS_MAX_TX_SERVER_FINISHED_MESSAGE_LENGTH))
      {
        TcpIp_TlsServerHsStm_SendServerFinished(TlsConIdx);
      }
      else
      {
        /* Memory runtime check fails - report DET */
        TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
      }
      break;
    }

    case TCPIP_TLS_STATE_HANDSHAKE_FINALIZING:
    {
      TcpIp_TlsServerHsStm_FinalizeHandshake(TlsConIdx);
      break;
    }

    case TCPIP_TLS_STATE_HANDSHAKE_DONE:
    {
      /* Nothing to do here */                                                                                         /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
      break;
    }

    case TCPIP_TLS_STATE_HANDSHAKE_ABORT:
    {
      /* Nothing to do here */                                                                                         /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
      break;
    }

    default:                                                                                                           /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
    {
      /* Default case left blank intentionally */
      TCPIP_ASSERT_UNREACHABLE();
      break;
    } /* default */
  } /* switch() */

} /* TcpIp_TlsServerHsStm_PerformNextHsStep() */



/**********************************************************************************************************************
*  TcpIp_TlsServerHsStm_ParseClientHello
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_ParseClientHello(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxClientHelloIdxOfTlsServerBufferMgmtType clientHelloIdx =
    TcpIp_GetTlsBufferRxClientHelloIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

  TcpIp_ClientHelloLenOfTlsServerBufferMgmtType clientHelloLen
    = TcpIp_GetClientHelloLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if we received a message with the TLS-Handshake type ClientHello */
  if (clientHelloIdx != TCPIP_NO_TLSBUFFERRXCLIENTHELLOIDXOFTLSSERVERBUFFERMGMT)
  {
    /* #20 Check if we received the absolute minimum length for this type of message and forward the message to the specific parser */
    if (TcpIp_TlsServerHsStm_VerifyExpectedMinimumMsgLen(clientHelloLen, TCPIP_TLS_MIN_CLIENTHELLO_MSGLEN) == E_OK)
    {
      /* #30 Extract the information inside the ClientHello message */
      retVal = TcpIp_TlsServerMsg_ExtractClientHelloInformation(TlsConIdx);

      if (retVal == E_OK)
      {
        /* #40 Find a matching cipher worker for the selected handshake */
        /* Check if a matching handshake is found. Both flags (for supported group and signature algorithm) have to be
           set. Delete the flags after this evaluation to make the handshake elements available again. */

        boolean matchingHandshakeFound;

        /* Start key exchange type dependent processing */
#   if (TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON)                                                                       /* COV_MSR_UNSUPPORTED */
#    if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)                                                                            /* COV_MSR_UNSUPPORTED */
        TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType tlsCipherWorkerIdx  /* active cipher worker */
          = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
        TcpIp_TlsCipherDefinitionIdxOfTlsCipherWorkerType tlsCipherDefinitionIdx  /* active cipher definition */
          = TcpIp_GetTlsCipherDefinitionIdxOfTlsCipherWorker(tlsCipherWorkerIdx);

        if (TcpIp_IsCipherSuiteUsePskOfTlsCipherDefinition(tlsCipherDefinitionIdx) == TRUE)
#    endif /* ECC */
        {
          /* PSK cipher worker */
          matchingHandshakeFound = TcpIp_TlsServerHsStm_ParseClientHelloFindPskHandshake(TlsConIdx);
        }
#    if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)                                                                            /* COV_MSR_UNSUPPORTED */
        else
#    endif /* ECC */
#   endif /* PSK */
#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)                                                                             /* COV_MSR_UNSUPPORTED */
        {
          /* The cipher worker is not a PSK one, so it is an ECDSA cipher worker. */
          matchingHandshakeFound = TcpIp_TlsServerHsStm_ParseClientHelloFindEcdsaHandshake(TlsConIdx);
        }  /* cipher is PSK or ECDSA */
#   endif /* ECC */

        if (matchingHandshakeFound == FALSE)
        {
          /* no matching handshake found */
          retVal = E_NOT_OK;

          /* trigger alert */
          TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_HANDSHAKE_FAILURE);
        }
      }  /* else: client hello information could not be extracted successfully */

      /* #50 Check return value of extract function and switch to next state */
      TcpIp_TlsHsStm_ErrorHandlingAndStateTransition(TlsConIdx, retVal, TCPIP_TLS_STATE_SEND_SERVER_HELLO);

      /* Message processed, decrement the handshake RX indication counter by one */
      TcpIp_DecHsRxIndicationCntOfTlsConnectionDyn(TlsConIdx);

      /* Next state is a transmitting state (either send the ServerHello message or Abort state) so trigger the processing */
      TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, TRUE);
    }
    else
    {
      /* #60 else - length mismatch report an error to the user and trigger TLS-Alert */
      TcpIp_TlsUserErrorType clientHelloUserError;
      clientHelloUserError.FunctionId  = TCPIP_TLS_FCTID_SERVER_HSSTM_PARSE_CLIENTHELLO;
      clientHelloUserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_UNEXPECTEDMSGLEN;
      clientHelloUserError.TlsConId    = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

      TcpIp_TlsCoreError_ReportUserError(clientHelloUserError);

      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
    }

  }
  else
  {
  /* #70 otherwise, we received an unexpected message. Trigger the alert */
  TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
  }
} /* TcpIp_TlsServerHsStm_ParseClientHello() */

#   if (TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON)                                                                       /* COV_MSR_UNSUPPORTED */
/**********************************************************************************************************************
*  TcpIp_TlsServerHsStm_ParseClientHelloFindPskHandshake
*********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsServerHsStm_ParseClientHelloFindPskHandshake(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean matchingHandshakeFound;

  /* ----- Implementation ----------------------------------------------- */
  /* The cipher workers for PSK key exchange may only reference one single handshake element, so this element
     can be marked as active if it is configured correctly. */
  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType tlsCipherWorkerIdx  /* active cipher worker */
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_TlsHandshakeIndStartIdxOfTlsCipherWorkerType handshakeIndStartIdx
    = TcpIp_GetTlsHandshakeIndStartIdxOfTlsCipherWorker(tlsCipherWorkerIdx);

  /* Get the handshake index from the handshake indirection index */
  TcpIp_TlsHandshakeIndIterType tlsHandshakeIndIdx = handshakeIndStartIdx;
  TcpIp_TlsHandshakeIndType    tlsHandshakeIdx = TcpIp_GetTlsHandshakeInd(tlsHandshakeIndIdx);

  /* #10 Check if the referenced handshake uses a PSK cipher */
  if (TcpIp_GetEllipticCurveIdOfTlsHandshake(tlsHandshakeIdx) == TCPIP_CURVE_ID_NO_CURVE)
  {
    /* OK, the handshake is a PSK handshake -> a matching handshake was found */

    /* set the handshake element as active */
    TcpIp_SetTlsHandshakeInUseOfTlsHandshakeDyn(tlsHandshakeIdx, TRUE);
    TcpIp_SetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(tlsCipherWorkerIdx, tlsHandshakeIdx);
    matchingHandshakeFound = TRUE;
  }
  else
  {
    /* The configuration is invalid. */
    matchingHandshakeFound = FALSE;

    /* trigger alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
  }

  return matchingHandshakeFound;
}
#   endif /* PSK */

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)                                                                             /* COV_MSR_UNSUPPORTED */
/**********************************************************************************************************************
*  TcpIp_TlsServerHsStm_ParseClientHelloFindEcdsaHandshake
*********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050, 6080 1 */ /* MD_TcpIp_STCAL_CslAccess, MD_TcpIp_TlsRuntimecheck_STMIF_6080 */
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsServerHsStm_ParseClientHelloFindEcdsaHandshake(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean matchingHandshakeFound = FALSE;

  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType tlsCipherWorkerIdx
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all configured handshake for this CipherWorker */
  if (tlsCipherWorkerIdx < TcpIp_GetSizeOfTlsCipherWorker())
  {
    TcpIp_TlsHandshakeIndStartIdxOfTlsCipherWorkerType handshakeIndStartIdx
      = TcpIp_GetTlsHandshakeIndStartIdxOfTlsCipherWorker(tlsCipherWorkerIdx);
    TcpIp_TlsHandshakeIndEndIdxOfTlsCipherWorkerType handshakeIndEndIdx
      = TcpIp_GetTlsHandshakeIndEndIdxOfTlsCipherWorker(tlsCipherWorkerIdx);
    TcpIp_TlsHandshakeIndIterType tlsHandshakeIndIdx;

    for (tlsHandshakeIndIdx = handshakeIndStartIdx; tlsHandshakeIndIdx < handshakeIndEndIdx; tlsHandshakeIndIdx++)
    {
      /* Get the handshake index from the handshake indirection index */
      TcpIp_TlsHandshakeIterType tlsHandshakeIdx = TcpIp_GetTlsHandshakeInd(tlsHandshakeIndIdx);

      if (tlsHandshakeIdx < TcpIp_GetSizeOfTlsHandshake())
      {
        /* #20 Check if the handshake is not used and if it can be used for the following handshake. */
        if (TcpIp_IsTlsHandshakeInUseOfTlsHandshakeDyn(tlsHandshakeIdx) == FALSE)
        {
          /* The current handshake is not yet used */

          matchingHandshakeFound = TcpIp_TlsServerHsStm_CheckHandshakesForMatchingCert(TlsConIdx,
            tlsCipherWorkerIdx, tlsHandshakeIdx);
          if (matchingHandshakeFound == TRUE)
          {
            break;
          }
        }  /* else: handshake is in use */
      }
    }  /* for-loop, iterate handshakes */
  }

  return matchingHandshakeFound;
}

/**********************************************************************************************************************
 *  TcpIp_TlsServerHsStm_CheckHandshakesForMatchingCert
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsServerHsStm_CheckHandshakesForMatchingCert(
  TcpIp_TlsConnectionIterType     TlsConIdx,
  TcpIp_TlsCipherWorkerIterType   TlsCipherWorkerIdx,
  TcpIp_TlsHandshakeIterType      TlsHandshakeIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;

  TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

  /* Find the configured handshake index corresponding to the handshake index. */
  TcpIp_TlsConfiguredHandshakeForServerConnectionIterType tlsConfiguredHandshakeForServerConnectionIdx
    = TcpIp_TlsServerMsg_GetTlsConfiguredHandshakeForServerConnectionIdx(TlsConIdx, TlsHandshakeIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* Check if TcpIp_TlsServerMsg_GetTlsConfiguredHandshakeForServerConnectionIdx() returned a valid value /
   * the corresponding configured handshake index was found. */
  if(   tlsConfiguredHandshakeForServerConnectionIdx
     <  TcpIp_GetSizeOfTlsConfiguredHandshakeForServerConnection())
  {
    /* #10 Check if both, the signature algorithm and curve flags, are set to indicate a match */
    /* RFC 8422 - Section 4. "The client MUST NOT include these extensions.
     * [..] the server is free to choose any one of the elliptic curves."
     * If the supported_groups extension is missing ignore the flag which indicate a curve match
     * and continue handshake with the first handshake element */
    if (   (TcpIp_IsMatchesReceivedSignatureAlgorithmsOfTlsConfiguredHandshakeForServerConnectionDyn(
              tlsConfiguredHandshakeForServerConnectionIdx) == TRUE)
        && (   (TcpIp_IsMatchesReceivedSupportedGroupsOfTlsConfiguredHandshakeForServerConnectionDyn(
                  tlsConfiguredHandshakeForServerConnectionIdx) == TRUE)
            || (TcpIp_IsTlsHandshakeSupportedGroupsExtensionMissingOfTlsServerConnection(tlsServerConnectionIdx) == TRUE)))
    {
      /* Both flags are set for this handshake, so this is the best matching handshake element. */
      /* Check the loaded server leaf certificates to support the signature and hash algorithm. */
      if (TcpIp_TlsServerHsStm_ParseClientHelloCheckForMatchingCert(TlsConIdx, TlsHandshakeIdx) == TRUE)
      {
        /* #20 A matching cert was found, set the handshake element active. */

        TcpIp_SetTlsHandshakeInUseOfTlsHandshakeDyn(TlsHandshakeIdx, TRUE);
        TcpIp_SetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TlsCipherWorkerIdx,
          (TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType)TlsHandshakeIdx);
        retVal = TRUE;
      }
      else
      {
        /* No matching cert was found for the current handshake. */
        /* Reset flags for signature algorithm and curve so it is not checked again. */
        TcpIp_SetMatchesReceivedSignatureAlgorithmsOfTlsConfiguredHandshakeForServerConnectionDyn(
          tlsConfiguredHandshakeForServerConnectionIdx, FALSE);
        TcpIp_SetMatchesReceivedSupportedGroupsOfTlsConfiguredHandshakeForServerConnectionDyn(
          tlsConfiguredHandshakeForServerConnectionIdx, FALSE);
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
*  TcpIp_TlsServerHsStm_ParseClientHelloCheckForMatchingCert
*********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsServerHsStm_ParseClientHelloCheckForMatchingCert(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsHandshakeIterType TlsHandshakeIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean matchingCertFound = FALSE;  /* a certificate was found that supports the SignatureAlgorithm and the curve */
  TcpIp_TlsLocalKeyMCertInfoIterType tlsLocalKeyMCertInfoIdx;
  boolean stopForLoop = FALSE;
  TcpIp_CertificateIdType certId = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* Check the loaded server leaf certificates to support the signature and hash algorithm. */

  /* #10 Iterate over all configured local certificates for this connection to find the first available server (leaf) certificate. */
  for (tlsLocalKeyMCertInfoIdx = TcpIp_GetTlsLocalKeyMCertInfoStartIdxOfTlsConnection(TlsConIdx);
    ((tlsLocalKeyMCertInfoIdx < TcpIp_GetTlsLocalKeyMCertInfoEndIdxOfTlsConnection(TlsConIdx)) && (stopForLoop == FALSE));
    tlsLocalKeyMCertInfoIdx++)
  {
    certId = TcpIp_GetLeafCertIdOfTlsLocalKeyMCertInfo(tlsLocalKeyMCertInfoIdx);

    /* #20 Check if the certificate matches the signature algorithm and elliptic curve of the passed handshake. */
    matchingCertFound = TcpIp_Tls12CoreUtil_DoesCertificateMatchSigAlgoAndCurve(certId,
      TcpIp_GetSignatureAlgorithmIdOfTlsHandshake(TlsHandshakeIdx),
      TcpIp_GetEllipticCurveIdOfTlsHandshake(TlsHandshakeIdx));
    stopForLoop = matchingCertFound;

  }  /* for (all certs of the connection) */

  if (matchingCertFound)
  {
    /* Store the cert id of the matching cert. */
    TcpIp_SetHsLeafCertIdOfTlsConnectionDyn(TlsConIdx, certId);
  }

  return matchingCertFound;
}
#   endif /* ECC */

/**********************************************************************************************************************
*  TcpIp_TlsServerHsStm_ParseClientKeyExchange
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_ParseClientKeyExchange(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
      = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxClientKeyExchangeIdxOfTlsServerBufferMgmtType clientKeyExchangeIdx =
      TcpIp_GetTlsBufferRxClientKeyExchangeIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if we received a message with the TLS-Handshake type ClientKeyExchange */
  if (clientKeyExchangeIdx != TCPIP_NO_TLSBUFFERRXCLIENTKEYEXCHANGEIDXOFTLSSERVERBUFFERMGMT)
  {
    /* Reset the TX trigger */
    TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);

    /* #20 Forward the message to the specific parser */
    retVal = TcpIp_TlsServerMsg_ExtractClientKeyExchangeInformation(TlsConIdx);

    if (retVal == E_OK)
    {
      /* #30 Message parsed successfully - check if the parsing is completely done and change the state */
      if (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_ASYNC_PENDING)
      {
        /* Async operation pending, nothing to do - just leave the function */
      }
      else
      {
        /* #40 Parsing completely done. Change the state depending on if client authentication is enabled or not. */
        if (TcpIp_IsTlsUseClientAuthenticationRequestOfTlsConnection(TlsConIdx) == TRUE)
        {
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFY);
        }
        else
        {
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CCS);
        }
        TcpIp_DecHsRxIndicationCntOfTlsConnectionDyn(TlsConIdx);
      }
    }
    else
    {
      /* #50 Message parsing failed - handle error */
      TcpIp_TlsHsStm_HandlesUnexpectedHsInformation(TlsConIdx);
    }
  }
  else
  {
    /* #60 otherwise, we received an unexpected message. Trigger the alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
  }
} /* TcpIp_TlsServerHsStm_ParseClientKeyExchange() */

/**********************************************************************************************************************
*  TcpIp_TlsServerHsStm_ParseClientCcs
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_ParseClientCcs(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the received CCS message is valid */
  if (TcpIp_IsCcsRxIndicationOfTlsConnectionDyn(TlsConIdx) == TRUE)
  {
    /* #20 Received CCS message is valid - next state is the parsing of the ClientFinished message */
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_FINISHED);

    /* Lock the reception of a new CCS message after this point */
    TcpIp_SetCcsReceivableOfTlsConnectionDyn(TlsConIdx, FALSE);

    /* Reset the CCS Rx Indication because we processed this message */
    TcpIp_SetCcsRxIndicationOfTlsConnectionDyn(TlsConIdx, FALSE);

    /* #30 Check if the record_size_limit extension is enabled and the server received an offer from the client (via ClientHello message) */
    if (   (TcpIp_IsTlsUseExtensionRecordSizeLimitOfTlsConnection(TlsConIdx) == TRUE)
        && (TcpIp_IsExtensionRecordSizeLimitReceivedOfTlsConnectionDyn(TlsConIdx) == TRUE))                             /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
    {
      /* #40 Extension record size limit enabled, update the TX size */
      /* RFC8449 - 4.  The "record_size_limit" Extension
       *   This value is used to limit the size of records that are created when encoding application data
       *   and the protected handshake message into records. */
      TcpIp_SetActiveMaxTxRlSizeOfTlsConnectionDyn(TlsConIdx,
        TcpIp_GetTxRecordSizeLimitOfTlsConnectionDyn(TlsConIdx));
    }
  }
  else
  {
    /* #50 Received CCS message is invalid - Trigger the transmission of the TLS alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
  }
} /* TcpIp_TlsServerHsStm_ParseClientCcs() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerHsStm_ExtractClientFinished
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerHsStm_ExtractClientFinished(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);

  /* #10 Prepare the message until we are done AND no Async context needs to be computed */
  while (   (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_WAIT_FOR_CLIENT_FINISHED_DONE)     /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
             /* Async operation is trigged (performed in lowPrio task) - leave this context */
         && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_ASYNC_PENDING)
             /* Error during processing of the data - skip further data handling */
         && (retVal == E_OK))
  {

    /* Get the sub state of the TLS message parser */
    switch (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx))
    {
      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_FINISHED:
      {
        /* #20 Extract the verify data value from the message */
        retVal = TcpIp_TlsServerMsg_ExtractClientFinishedInformation(TlsConIdx);
        /* Error handling is done via return value in while condition - prepare next state transition */
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_FINISHED_CALC_HASH);
        break;
      }

      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_FINISHED_CALC_HASH:
      {
        /* #30 Trigger the calculation of finished hash */
        TcpIp_TlsServerMsg_CalcClientFinishedHash(TlsConIdx);
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_FINISHED_CALC_FINISHED);
        /* This operation is processed within the lowPrio function, which means that we are leaving
           this context and return when the operation is DONE */
        break;
      }

      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_FINISHED_CALC_FINISHED:
      {
        /* #40 Trigger calculation of the finished verify data via the PRF */
        TcpIp_TlsServerMsg_CalcClientFinishedVerifyData(TlsConIdx);
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_FINISHED_VERIFY);
        /* This operation is processed within the lowPrio function, which means that we are leaving
           this context and return when the operation is DONE */
        break;
      }

      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_FINISHED_VERIFY:
      {
        /* #50 Compare the calculated finished verify data with the received one */
        retVal = TcpIp_TlsServerMsg_CompareFinishedVerifyData(TlsConIdx);
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_FINISHED_DONE);
        break;
      }

      default:                                                                                                          /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
      {
        /* Default case left blank intentionally */
        TCPIP_ASSERT_UNREACHABLE();
        break;
      } /* default */
    } /* switch */
  } /* while */

  return retVal;
} /* TcpIp_TlsServerHsStm_ExtractClientFinished() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerHsStm_SendServerHello
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_SendServerHello(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  /* ----- Implementation ----------------------------------------------- */
  /* Reset the TX trigger for the next state machine cycle */
  TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);

  /* Set the Tls active version variable. The server only supports protocol version 1.2. */
  TcpIp_SetActiveVersionOfTlsConnectionDyn(TlsConIdx, TCPIP_TLSVERSION_12);

  /* #10 Forward the message to the specific ServerHello preparation handler */
  retVal = TcpIp_TlsServerMsg_PrepareServerHello(TlsConIdx);

  if (retVal == E_OK)
  {

    TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx
      = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

    TcpIp_TlsKeyExchangeMethodDataType keyExchangeMethod
      = TcpIp_TlsCoreUtil_ReturnActiveCipherSpecificKeyExchangeMethod(TlsConIdx);

    TcpIp_SetHelloReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, TRUE);

    /* #20 Message prepared successfully - Determine next state depending on key exchange mode */
    switch (keyExchangeMethod)
    {
      case TCPIP_TLS_KEYEXCHANGE_METHOD_PSK_PLAIN:
      {
        /* #30 Plain PSK based key exchange - Check if PSK hint should be transmitted and set the corresponding state */
        if (TcpIp_IsPskIdentityHintUsedOfTlsPskIdentity(TcpIp_GetTlsPskIdentityDefaultIdxOfTlsConnection(TlsConIdx)))
        {
          /* If default PSK identity is set, send PSK hint in server key exchange message */
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE);
        }
        else
        {
          /* No PSK identity is set - next state is ServerHelloDone */
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_SERVER_HELLO_DONE);
        }
        break;
      }
#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
      case TCPIP_TLS_KEYEXCHANGE_METHOD_ECDHE:
      case TCPIP_TLS_KEYEXCHANGE_METHOD_ECDH:
      {
        /* #40 ECC based key exchange - transition to state TCPIP_TLS_STATE_SEND_SERVER_CERTIFICATE */
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_SERVER_CERTIFICATE);
        break;
      }
#   endif
      default:
      {
        /* Invalid key exchange method. This can never happen, a valid key exchange method has been chosen with the
        active cipher suite selected after receiving the client_hello message. */
        break;
      }
    } /* switch (keyExchangeMethod) */

    /* Next state is a transmitting state (either send the ServerHello message or Abort state) so trigger the processing */
    TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, TRUE);
  }
  else
  {
    /* #50 Message preparation failed - report error and trigger TLS-Alert */
    TcpIp_TlsServerHsStm_HandleErrorDuringPreparation(TlsConIdx);
  }
} /* TcpIp_TlsServerHsStm_SendServerHello() */

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsServerHsStm_SendServerCertificate
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_SendServerCertificate(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* Reset the TX trigger */
  TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);

  /* #10 Forward the message to the specific composer */
  retVal = TcpIp_TlsServerMsg_PrepareServerCertificates(TlsConIdx);

  if (retVal == E_OK)
  {
    /* #20 Message composing successfully - Determine next state depending on key exchange mode */
    TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx
      = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

    TcpIp_SetCertificateReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, TRUE);

    /* Determine next TLS handshake state based on key exchange */
    if (TcpIp_TlsCoreUtil_ReturnActiveCipherSpecificKeyExchangeMethod(TlsConIdx) == TCPIP_TLS_KEYEXCHANGE_METHOD_ECDH)
    {
      /* In case of an ECDH cipher check if client authentication is used. */
      if (TcpIp_IsTlsUseClientAuthenticationRequestOfTlsConnection(TlsConIdx) == TRUE)
      {
        /* ECDH and client authentication enabled, next state is CertificateRequest */
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_SERVER_CERTIFICATE_REQUEST);
      }
      else
      {
        /* ECDH and client authentication disabled, next state is HelloDone */
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_SERVER_HELLO_DONE);
      }
    }
    else /* TCPIP_TLS_KEYEXCHANGE_METHOD_ECDHE */
    {
      /* in case of an ECDHE cipher, key exchange message will be sent */
      TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE);
    }

    /* Next state is a transmitting state (either send the ServerKeyExchange/ServerHelloDone message or Abort state) so trigger the processing */
    TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, TRUE);
  }
  else
  {
    /* #30 Message composing failed - handle error */
    TcpIp_TlsServerHsStm_HandleErrorDuringPreparation(TlsConIdx);
  }
} /* TcpIp_TlsServerHsStm_SendServerCertificate() */
#   endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsServerHsStm_SendServerKeyExchange
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_SendServerKeyExchange(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* Reset the TX trigger */
  TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);

  /* #10 Forward the message to the specific composer */
  retVal = TcpIp_TlsServerMsg_PrepareServerKeyExchange(TlsConIdx);

  if (retVal == E_OK)                                                                                                   /* PRQA S 2991, 2995 */ /* MD_TCPIP_Rule14.3_2741_2742_2991_2992_2995_2996 */
  {
    /* #20 Message composing successfully - check if the preparation is completely done and change the state */
    if (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_ASYNC_PENDING)
    {
      /* Async operation pending, nothing to do - just leave the function */
    }
    else
    {
      /* #30 Preparation completely done. Change the state depending if client authentication is used or not. */
      TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx
        = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

      TcpIp_SetKeyExchangeReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, TRUE);
      /* It is ensured by a validator that there is no PSK cipher configured in a client authentication connection.
       * Therefore there is no need for an extra check if the active cipher is ECC. */
      if (TcpIp_IsTlsUseClientAuthenticationRequestOfTlsConnection(TlsConIdx) == TRUE)
      {
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_SERVER_CERTIFICATE_REQUEST);
      }
      else
      {
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_SERVER_HELLO_DONE);
      }

      /* Next state is a transmitting state (either send the ServerHelloDone message / Certificate Request message
       * or Abort state) so trigger the processing */
      TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, TRUE);
    }
  }
  else
  {
    /* #40 Message composing failed - handle error */
    TcpIp_TlsServerHsStm_HandleErrorDuringPreparation(TlsConIdx);
  }
} /* TcpIp_TlsServerHsStm_SendServerKeyExchange() */

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsServerHsStm_SendCertificateRequest
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_SendCertificateRequest(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
/* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx
    = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Forward the message to the specific preparation function */
  TcpIp_TlsServerMsg_PrepareCertificateRequest(TlsConIdx);

  TcpIp_SetCertificateRequestReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, TRUE);

  /* Next state is sending ServerHelloDone. */
  TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_SERVER_HELLO_DONE);

} /* TcpIp_TlsServerHsStm_SendCertificateRequest() */
#   endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsServerHsStm_SendServerHelloDone
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_SendServerHelloDone(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
/* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx
    = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* Reset the TX trigger */
  TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);

  /* #10 Forward the message to the specific preparation function */
  TcpIp_TlsServerMsg_PrepareServerHelloDone(TlsConIdx);

  TcpIp_SetHelloDoneReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, TRUE);

  /* Next state depends if client authentication is used or not. */
  if (TcpIp_IsTlsUseClientAuthenticationRequestOfTlsConnection(TlsConIdx) == TRUE)
  {
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE);
  }
  else
  {
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE);
  }

} /* TcpIp_TlsServerHsStm_SendServerHelloDone() */

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsServerHsStm_ParseClientCertificate
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_ParseClientCertificate(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferRxClientCertificateIdxOfTlsServerBufferMgmtType clientCertificateIdx =
    TcpIp_GetTlsBufferRxClientCertificateIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if we received a message with the TLS-Handshake type ClientCertificate */
  if (clientCertificateIdx != TCPIP_NO_TLSBUFFERRXCLIENTCERTIFICATEIDXOFTLSSERVERBUFFERMGMT)
  {
    Std_ReturnType retVal;

    /* #20 if so, extract the information inside the client certificate message */
    retVal = TcpIp_TlsServerMsg_ExtractClientCertificateInformation(TlsConIdx);

    /* #30 Check return value from extract function and switch to next state */
    if (retVal == E_OK)
    {
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
        /* Next state is parsing ClientKeyExchange message. */
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE);
        TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_NO_ASYNC);
      }

    }
    else
    {
      TcpIp_TlsHsStm_HandlesUnexpectedHsInformation(TlsConIdx);
    }
  }
  else
  {
    /* #40 otherwise, we received an unexpected message. Trigger the alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
  }
} /* TcpIp_TlsServerHsStm_ParseClientCertificate() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerHsStm_ParseClientCertificateVerify
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_ParseClientCertificateVerify(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx =
    TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxClientCertificateVerifyIdxOfTlsServerBufferMgmtType clientCertificateVerifyIdx =
    TcpIp_GetTlsBufferRxClientCertificateVerifyIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if we received a handshake message with the type ClientCertificateVerify */
  if (clientCertificateVerifyIdx != TCPIP_NO_TLSBUFFERRXCLIENTCERTIFICATEVERIFYIDXOFTLSSERVERBUFFERMGMT)
  {
    Std_ReturnType retVal;

    /* #20 ClientCertificateVerify message received - forward the message to the parser to extract the contained information */
    retVal = TcpIp_TlsServerMsg_ExtractClientCertificateVerifyInformation(TlsConIdx);

    /* #30 Check if the parsing of the message was successful */
    if (retVal == E_OK)
    {
      /* #40 Message parsed successfully - check if the parsing is completely done and change the state */
      if (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_ASYNC_PENDING)
      {
        /* Async operation pending, nothing to do - just leave the function */
      }
      else
      {
        /* #50 Parsing completely done. Change the state to TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CCS */
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CCS);
      }
    }
    else
    {
      /* #60 Parsing failed. Cancel the handshake. */
      TcpIp_TlsHsStm_HandlesUnexpectedHsInformation(TlsConIdx);
    }
  }
  else
  {
    /* #70 otherwise, we received an unexpected message, trigger the alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
  }
} /* TcpIp_TlsServerHsStm_ParseClientCertificateVerify() */
#   endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsServerHsStm_ParseClientFinished
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_ParseClientFinished(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxClientFinishedIdxOfTlsServerBufferMgmtType clientFinishedIdx =
    TcpIp_GetTlsBufferRxClientFinishedIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if we received a message with the TLS-Handshake type ClientFinished */
  if (clientFinishedIdx != TCPIP_NO_TLSBUFFERRXCLIENTFINISHEDIDXOFTLSSERVERBUFFERMGMT)
  {
    /* #20 Forward the message to the specific parser */
    retVal = TcpIp_TlsServerHsStm_ExtractClientFinished(TlsConIdx);

    if (retVal == E_OK)
    {
      /* #30 Check if the message parsing is completely done and change the state accordingly */
      if (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_ASYNC_PENDING)
      {
        /* Async operation pending, nothing to do - just leave the function */
      }
      else
      {
        /* #40 Parsing completely done. Change the state to TCPIP_TLS_STATE_SEND_SERVER_CCS */
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_SERVER_CCS);
        TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, TRUE);
        TcpIp_DecHsRxIndicationCntOfTlsConnectionDyn(TlsConIdx);
      }
    }
    else
    {
      /* #50 Message parsing failed - handle error */
      TcpIp_TlsHsStm_HandlesUnexpectedHsInformation(TlsConIdx);
    }
  }
  else
  {
    /* #60 otherwise, we received an unexpected message. Trigger the alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
  }
} /* TcpIp_TlsServerHsStm_ParseClientFinished() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerHsStm_SendServerCcs
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_SendServerCcs(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx
    = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Trigger the transmission of the TLS-Server CCS message */
  TcpIp_SetChangeCipherSpecReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, TRUE);

  /* Next state is send ServerFinished message */
  TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_SERVER_FINISHED);

  /* #20 Check if the record_size_limit extension is enabled and the server received an offer from the client (via ClientHello message) */
  if (   (TcpIp_IsTlsUseExtensionRecordSizeLimitOfTlsConnection(TlsConIdx) == TRUE)
      && (TcpIp_IsExtensionRecordSizeLimitReceivedOfTlsConnectionDyn(TlsConIdx) == TRUE))                               /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
  {
    /* #30 Update RX size - After this point we should only receive messages smaller than the offered value (via ServerHello message) */
    TcpIp_SetActiveMaxRxRlSizeOfTlsConnectionDyn(TlsConIdx,
      TcpIp_GetRxRecordSizeLimitOfTlsConnectionDyn(TlsConIdx));
  }
} /* TcpIp_TlsServerHsStm_SendServerCcs() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerHsStm_SendServerFinished
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_SendServerFinished(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);

  /* #10 Forward the message to the specific preparation function */
  TcpIp_TlsServerMsg_PrepareServerFinished(TlsConIdx);

  /* #20 Message prepared successfully - check if the parsing is completely done and change the state */
  if (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_ASYNC_PENDING)
  {
    /* Async operation pending, nothing to do - just leave the function */
  }
  else
  {
    /* #30 Preparation completely done - Change the state to Finalize TLS handshake */
    TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx
      = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

    /* Trigger the transmission of the TLS-Server finished message */
    TcpIp_SetServerFinishedReadyToSendOfTlsServerConnection(tlsServerConnectionIdx, TRUE);

    TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_FINALIZING);
    TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CONNECTION_SERVER_HS_FINALIZING);
  }

} /* TcpIp_TlsServerHsStm_SendServerFinished() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerHsStm_FinalizeHandshake
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_FinalizeHandshake(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxAdHsStartIdxOfTlsBufferMgmtType txAdHsStartIdx
    = TcpIp_GetTlsBufferTxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  TcpIp_TlsBufferTxAdHsReadIdxOfTlsBufferMgmtDynType txAdHsReadIdx
    = TcpIp_GetTlsBufferTxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);


  TcpIp_TlsBufferRxAdHsStartIdxOfTlsBufferMgmtType rxAdHsStartIdx
    = TcpIp_GetTlsBufferRxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType rxAdHsReadIdx
    = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);


  /* ----- Implementation ----------------------------------------------- */
  /* The TX Read index is not used during handshake, so set it to the current position of the write index. */
  TcpIp_SetTlsBufferTxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
    TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

  if (TcpIp_IsTlsClearBufferAfterHandshakeOfTlsConfig(TCPIP_TLSCONFIG_IDX) == TRUE)
  {
     /* #10 Clear the TLS TxBuffer if configured */
     if (   (txAdHsStartIdx < TcpIp_GetSizeOfTlsBufferTx())
         && (txAdHsReadIdx < TcpIp_GetSizeOfTlsBufferTx())
         && (txAdHsStartIdx <= txAdHsReadIdx))
         {
           /* Clear the handshake data in the TxBuffer from StartIdx to ReadIdx */
           TcpIp_TlsCoreBuffer_ClearTxBuffer(txAdHsStartIdx, txAdHsReadIdx);
         }

     /* #20 Clear the TLS RxBuffer if configured */
     if (   (rxAdHsStartIdx < TcpIp_GetSizeOfTlsBufferRx())
         && (rxAdHsReadIdx < TcpIp_GetSizeOfTlsBufferRx())
         && (rxAdHsStartIdx <= rxAdHsReadIdx))
     {
       /* Clear the handshake data in the RxBuffer from StartIdx to ReadIdx */
       /* retVal can't be processed here, but a Det error is reported inside the function */
       (void)TcpIp_TlsCoreBuffer_ClearRxBuffer(rxAdHsStartIdx, rxAdHsReadIdx);
     }
  }

  /* Set the UpperLayer RX indication index to the current read index */
  TcpIp_SetTlsBufferRxUlRxIndIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
    TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

  /* #30 Release handshake resource */
  {
    TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType tlsCipherWorkerIdx
      = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

    if (tlsCipherWorkerIdx < TcpIp_GetSizeOfTlsCipherWorker())
    {
      TcpIp_TlsHandshakeIterType tlsHandshakeIdx
        = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(tlsCipherWorkerIdx);

      if (tlsHandshakeIdx < TcpIp_GetSizeOfTlsHandshake())
      {
        TcpIp_SetTlsHandshakeInUseOfTlsHandshakeDyn(tlsHandshakeIdx, FALSE);
      }
    }
  }

  /* Switch the state from FINALIZING to ESTABLISHED */
  TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CONNECTION_ESTABLISHED);
  /* #40 Handshake is done - set state accordingly */
  TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_DONE);

  /* #50 Notify Upper layer via TcpAccepted callback over the established TLS connection */
  TcpIp_Tls12CoreUl_TcpAccepted(TlsConIdx);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
  /* #60 Remove all loaded client certificates by overwriting them with zeros. */
  TcpIp_TlsCore_RemoveLoadedCerts(TlsConIdx);
#   endif
} /* TcpIp_TlsServerHsStm_FinalizeHandshake() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerHsStm_VerifyExpectedMinimumMsgLen
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerHsStm_VerifyExpectedMinimumMsgLen(
  CONST(uint32, AUTOMATIC) MsgLen,
  CONST(uint32, AUTOMATIC) ExpectedMsgLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Compare the received message length against the minimum expected message length */
  if (MsgLen >= ExpectedMsgLen)
  {
    /* Length check OK */
   retVal = E_OK;
  }
  else
  {
    /* Length mismatch - return E_NOT_OK */
  }

  return retVal;
} /* TcpIp_TlsServerHsStm_VerifyExpectedMinimumMsgLen() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerHsStm_HandleErrorDuringPreparation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerHsStm_HandleErrorDuringPreparation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsUserErrorType hsUserError;
  TcpIp_TlsAlertLevelType alertLevel;
  TcpIp_TlsAlertDescriptionType alertDescription;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Prepare the user error and report it */
  hsUserError.FunctionId  = TCPIP_TLS_FCTID_SERVER_HSSTM_PREPARE_HS_MSG;
  hsUserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_INCORRECTHSMSG;
  hsUserError.TlsConId    = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

  TcpIp_TlsCoreError_ReportUserError(hsUserError);

  /* #20 Prepare the TLS alert and trigger the transmission of it */
  alertLevel       = TCPIP_TLS_ALERT_LEVEL_FATAL;
  alertDescription = TCPIP_TLS_ALERT_DESC_HANDSHAKE_FAILURE;

  TcpIp_TlsCoreAlert_Set(TlsConIdx, alertLevel, alertDescription);

  /* #30 Change the TLS connection state to HANDSHAKE_ABORT */
  TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_ABORT);

} /* TcpIp_TlsServerHsStm_HandleErrorDuringPreparation() */

/**********************************************************************************************************************
 *  TLS SERVER HANDSHAKE MESSAGE HANDLING
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ExtractClientHelloInformation
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
/* PRQA S 6010, 6050 1 */ /* MD_TcpIp_TlsStatemachine_STPTH_6010, MD_TcpIp_TlsStatemachine_STCAL_6050 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ExtractClientHelloInformation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* Index of the Start of the ClientHello message */
  TcpIp_TlsBufferRxClientHelloIdxOfTlsServerBufferMgmtType clientHelloStartIdx =
    TcpIp_GetTlsBufferRxClientHelloIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

  /* Length of the received ClientHello message */
  TcpIp_ClientHelloLenOfTlsServerBufferMgmtType clientHelloLen =
    TcpIp_GetClientHelloLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

  /* End index of the received ClientHello message - Need for in range checks inside the parser */
  CONST(TcpIp_TlsBufferRxClientHelloIdxOfTlsServerBufferMgmtType, AUTOMATIC) clientHelloEndIdx
    = clientHelloStartIdx + TCPIP_TLS_HSHDRLEN + clientHelloLen;

  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Validate the HS major and minor TLS version */
  retVal = TcpIp_TlsMsg_HelloMsgGetVersionNr(TlsConIdx);

  if (retVal == E_OK)
  {
    /* #20 Store the received ClientHello random number */
    retVal = TcpIp_TlsMsg_HelloMsgGetAndCheckRandom(TlsConIdx);
  }

  if (retVal == E_OK)
  {
    /* #30 Get received session ID (sessions not supported by this implementation) */
    retVal = TcpIp_TlsMsg_HelloMsgGetAndCheckSessionId(TlsConIdx, clientHelloEndIdx);
  }

  if (retVal == E_OK)
  {
    /* #40 Select a matching cipher suite for this connection */
    retVal = TcpIp_TlsServerMsg_ClientHelloGetCipherSuites(TlsConIdx, clientHelloEndIdx);
  }

  if (retVal == E_OK)
  {
    /* #50 Parse the received Compression Methods */
    retVal = TcpIp_TlsServerMsg_ClientHelloGetCompressionMethods(TlsConIdx, clientHelloEndIdx);
  }

  if (retVal == E_OK)
  {
    /* #60 Parse the received ClientHello extensions */
    retVal = TcpIp_TlsServerMsg_ClientHelloGetExtensions(TlsConIdx, clientHelloEndIdx);
  }

  if (retVal == E_OK)
  {
    /* #70 Check if there is some more unparsed information in the buffer */
    retVal = TcpIp_TlsMsg_CheckMsgForRemainingData(TlsConIdx, clientHelloEndIdx);
  }

#   if ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON))
  /* #80 Add the client random to the Msa_AccessBuffer if enabled */
  if (retVal == E_OK)
  {
    TcpIp_TlsServerMsa_AddClientRandomToAccessBuffer(TlsConIdx);
  }
#   endif

  return retVal;
} /* TcpIp_TlsServerMsg_ExtractClientHelloInformation() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ExtractClientKeyExchangeInformation
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ExtractClientKeyExchangeInformation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Parse the ClientKeyExchange message until we are done AND no Async context needs to be computed */
  while (   (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx)  != TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_DONE)/* PRQA S 3415 3 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
             /* Async operation is triggered in one of the sub states, switch to lowPrio context - leave this function */
         && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_ASYNC_PENDING)
             /* Error during parsing - abort next steps */
         && (retVal == E_OK) )
  {
    /* Sub-state machine for ClientKeyExchange message */
    switch (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx))
    {
      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE:
      {
        /* #20 Select next sub state depending on selected key exchange */
        TcpIp_TlsKeyExchangeMethodDataType keyExchangeMethod;
        TcpIp_TlsHandshakeState nextState = TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE;

        /* At this point its OK to receive the CCS message */
        TcpIp_SetCcsReceivableOfTlsConnectionDyn(TlsConIdx, TRUE);

        keyExchangeMethod = TcpIp_TlsCoreUtil_ReturnActiveCipherSpecificKeyExchangeMethod(TlsConIdx);

        switch (keyExchangeMethod)
        {
#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
          case TCPIP_TLS_KEYEXCHANGE_METHOD_ECDHE:
          case TCPIP_TLS_KEYEXCHANGE_METHOD_ECDH:
          {
            /* ECC based key exchange - Next sub state is processing of ECC parameter */
            nextState = TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_ECDHE_ECDSA_CLIENT_PARAMS;
            break;
          }
#   endif
#   if (TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON)
          case TCPIP_TLS_KEYEXCHANGE_METHOD_PSK_PLAIN:
          {
            /* PSK based key exchange - Next state is processing of PSK parameter */
            nextState = TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_PSK_CLIENT_PARAMS;
            break;
          }
#   endif
          default:
          {
            /* Invalid key exchange method. This can never happen, a valid key exchange method has been chosen with the
            active cipher suite selected after receiving the client_hello message. */
            break;
          }
        }  /* switch (keyExchangeMethod) */

        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, nextState);

          break;
      } /* case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE */
#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_ECDHE_ECDSA_CLIENT_PARAMS:
      {
        /* #30 Processing of ECC parameter */
        retVal = TcpIp_TlsServerMsg_ClientKeyExchangeGetEcdheEcdsaInformation(TlsConIdx);
        /* Error handling is done via return value in while condition - prepare next state transition */
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_CALC_MASTER_SECRET);
        break;
      }
#   endif
#   if (TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON)
      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_PSK_CLIENT_PARAMS:
      {
        /* #40 Processing of PSK parameter */
        retVal = TcpIp_TlsServerMsg_ClientKeyExchangeGetPskInformation(TlsConIdx);
        /* Error handling is done via return value in while condition - prepare next state transition */
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_CALC_MASTER_SECRET);
        break;
      }
#   endif
      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_CALC_MASTER_SECRET:
      {
        /* #50 Trigger calculation of master secret */
        /* This operation is time consuming and thus is calculated in the lowPrio (async) task.
           Trigger the calculation, leave this context and return if the operation is done */
        TcpIp_TlsServerMsg_ClientKeyExchangeCalcMasterSecret(TlsConIdx);
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_WAIT_FOR_ASYNC);
        break;
      }

      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_WAIT_FOR_ASYNC:
      {
        /* #60 Asynchronous validation performed, reset the connection state */
        TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_NO_ASYNC);
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_DONE);
        break;
      }

      default:                                                                                                         /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
      {
        /* Default case left blank intentionally */
        TCPIP_ASSERT_UNREACHABLE();
        break;
      }

    } /* switch() */
  } /* while() */
  return retVal;
}
#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientKeyExchangeGetEcdheEcdsaInformation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientKeyExchangeGetEcdheEcdsaInformation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Prepare the message until we are done AND no Async context needs to be computed */
  while (   (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_DONE) /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
            /* Async operation is triggered in one of the sub states, switch to lowPrio context - leave this function */
         && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_ASYNC_PENDING)
            /* Error during parsing - abort next steps */
        && (retVal == E_OK))
  {
    /* Sub-state machine for Client key exchange message */
    switch (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx))
    {
      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_ECDHE_ECDSA_CLIENT_PARAMS:
      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_ECDHE_ECDSA_CLIENT_PARAMS_GET_PARAMS:
      {
        /* #20 Parse the received ECC Client parameter */
        retVal = TcpIp_TlsServerMsg_ClientKeyExchangeGetClientParams(TlsConIdx);
        /* Error handling is done via return value in while condition - prepare next state transition */
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx,
          TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_ECDHE_ECDSA_CLIENT_PARAMS_CALC_DH_SHARED_SECRET);
        break;
      }

      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_ECDHE_ECDSA_CLIENT_PARAMS_CALC_DH_SHARED_SECRET:
      {
        /* #30 Trigger the calculation of the DH shared secret */
        TcpIp_TlsServerMsg_ClientKeyExchangeCalcSharedSecret(TlsConIdx);
        /* This operation is time consuming and thus is calculated in the lowPrio (async) task.
           Trigger the calculation, leave this context and return if the operation is done */
        break;
      }

      default:                                                                                                           /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
      {
        /* Default case left blank intentionally */
        TCPIP_ASSERT_UNREACHABLE();
        break;
      }

    } /* switch() */
  } /* while() */

  return retVal;
} /* TcpIp_TlsServerMsg_ClientKeyExchangeGetEcdheEcdsaInformation */
#   endif

#   if (TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientKeyExchangeGetPskInformation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientKeyExchangeGetPskInformation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Prepare the message until we are done AND no Async context needs to be computed */
  while (   (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_DONE) /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
             /* Async operation is triggered in one of the sub states, switch to lowPrio context - leave this function */
         && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_ASYNC_PENDING)
             /* Error during parsing - abort next steps */
         && (retVal == E_OK))
  {
    /* Sub-state machine for Client key exchange message */
    switch (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx))
    {
      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_PSK_CLIENT_PARAMS:
      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_PSK_CLIENT_PARAMS_GET_PARAMS:
      {
        /* #20 Parse the received PSK parameter */
        retVal = TcpIp_TlsServerMsg_ClientKeyExchangeGetPskParams(TlsConIdx);
        /* Error handling is done via return value in while condition - prepare next state transition */
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx,
          TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_PSK_CLIENT_PARAMS_CALC_PREMASTER_SECRET);
        break;
      }

      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_PSK_CLIENT_PARAMS_CALC_PREMASTER_SECRET:
      {
        /* #30 Trigger the calculation of the PSK premaster secret */
        /* This operation is time consuming and thus is calculated in the lowPrio (async) task.
           Trigger the calculation, leave this context and return if the operation is done */
        TcpIp_TlsServerMsg_ClientKeyExchangeCalcPskPremasterSecret(TlsConIdx);
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx,
          TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_PSK_CLIENT_PARAMS_DONE);
        break;
      }

      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_KEY_EXCHANGE_PROCESS_PSK_CLIENT_PARAMS_DONE:
      {
        break;
      }

      default:                                                                                                           /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
      {
        /* Default case left blank intentionally */
        TCPIP_ASSERT_UNREACHABLE();
        break;
      }

    } /* switch() */
  } /* while() */

  return retVal;
} /* TcpIp_TlsServerMsg_ClientKeyExchangeGetPskInformation */
#   endif /* TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON */

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ExtractClientCertificateInformation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ExtractClientCertificateInformation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Extract the message information until we are done AND no Async context needs to be computed */
  while (   (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_DONE)  /* PRQA S 3415 6 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
            /* Handshake is not aborted due to processing error */
         && (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_HANDSHAKE_ABORT)
            /* Async operation is pending */
         && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_ASYNC_PENDING)
            /* Next state could not be determine (missing next HS message) - Wait cycle */
         && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_WAIT_CYCLE)
            /* Error during parsing - abort next steps */
         && (retVal == E_OK))
  {
    switch (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx))
    {
      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE:
      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_LOADCERTS:
      {
        /* #20 Extract the certificates from the received chain, store them in the KeyM, and trigger KeyM to verify the cert group */
        if (TcpIp_TlsServerMsg_ClientCertMsgProcessCertChain(TlsConIdx) == E_OK)
        {
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFYGROUP_CHECK);
          TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_WAIT_CYCLE);
        }
        else
        {
          retVal = E_NOT_OK;
        }
        break;
      }

      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFYGROUP_CHECK:
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
          /* The cert chain validation has been finished by the KeyM. Now check the result and calculate an overall status. */
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFYGROUP_STATUS);
        }
        break;
      }

      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFYGROUP_STATUS:
      {
        /* #40 The cert chain validation has been finished by the KeyM. Now check the result and calculate an overall status. */
        retVal = TcpIp_TlsServerMsg_ClientCertMsgVerifyCertificateGroup(TlsConIdx);

        /* Decrement HsRxIndicationCnt since the certificate message is completely parsed */
        TcpIp_DecHsRxIndicationCntOfTlsConnectionDyn(TlsConIdx);
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_DONE);
        break;
      }

      default:                                                                                                           /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
      {
        break;
      } /* default */
    } /* switch() */

  } /* while() */

  return retVal;
} /* TcpIp_TlsServerMsg_ExtractClientCertificateInformation() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientCertMsgProcessCertChain
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientCertMsgProcessCertChain(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_SizeOfTlsServerBufferMgmtType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* If one of the following steps fails send a decode_error alert per default. */
  TcpIp_TlsAlertDescriptionType alertDescription = TCPIP_TLS_ALERT_DESC_DECODE_ERROR;
  uint16 certificatesLength = 0u;
  uint8 numCerts = 0u;  /* Number of received certificates */
  uint16 clientCertificateMsgLen = TcpIp_GetClientCertificateLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the length of the certificate message and read the number of certificates. */
  if (clientCertificateMsgLen == TCPIP_TLS_CERTCHAINLEN_LEN)
  {
    /* According to RFC5246 7.4.6.  Client Certificate a client may send an empty certificate message, if no
     * matching certificate is available. If the client does not send any certificates, the server MAY at its
     * discretion either continue the handshake without client authentication, or respond with a fatal
     * handshake_failure alert.
     * Since the client is not able to authenticate itself and there is currently no way to clarify this case
     * with the upper layer, an empty certificate is treated as an error case. */
    alertDescription = TCPIP_TLS_ALERT_DESC_HANDSHAKE_FAILURE;
  }
  else if (TcpIp_Tls12Msg_RecCertMsgCheckLengthAndReadCertNum(
             TlsConIdx, clientCertificateMsgLen, &certificatesLength, &numCerts) == E_OK)
  {
    /* If the verification of the chain fails an unknown_ca alert should be send. */
    alertDescription = TCPIP_TLS_ALERT_DESC_UNKNOWN_CA;

    /* #20 Extract the certificates from the received chain and store them in the KeyM. */
    retVal = TcpIp_TlsServerMsg_ClientCertMsgParseAndTriggerVerification(TlsConIdx,
      TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx), numCerts);

    /* Update the read index */
    TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, certificatesLength);
  }
  else
  {
    /* retVal is already E_NOT_OK */
  }

  if(retVal != E_OK)
  {
    /* #30 Extraction of server certificates failed, report user error */
    TcpIp_TlsUserErrorType UserError;
    UserError.FunctionId = TCPIP_TLS_FCTID_SERVER_HSSTM_PARSE_CLIENTCERT;
    UserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_INCORRECTHSMSG;
    UserError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(UserError);

    /* Trigger alert protocol_version in case of invalid length of certificate */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, alertDescription);

    retVal = E_NOT_OK;
  }

  return retVal;
} /* TcpIp_TlsServerMsg_ClientCertMsgProcessCertChain */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientCertMsgParseAndTriggerVerification
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientCertMsgParseAndTriggerVerification(
  TcpIp_TlsConnectionIterType         TlsConIdx,
  TcpIp_TlsBufferRxIterType           CertStartIdx,
  uint8                               NumCerts)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ---------------------------------------------- */
  /* TcpIp_TlsCoreUtil_CheckEccKeyMConfiguration() ensures
   * that there is at least one KeyM remote reference for this connection
   * and each remote reference is contained in the same KeyM group.
   * After this check we can rely on only one KeyM group which is referenced through TlsRemoteKeyMCertInfoStartIdx.
   * The function also ensures that the functions KeyM_VerifyGroup() and KeyM_SetCertificateInGroup are available. */
  if (TcpIp_TlsCoreUtil_CheckEccKeyMConfiguration(TlsConIdx) == E_OK)
  {
    TcpIp_CertGroupIdOfTlsRemoteKeyMCertInfoType keyMCertGroupId
      = TcpIp_GetCertGroupIdOfTlsRemoteKeyMCertInfo(TcpIp_GetTlsRemoteKeyMCertInfoStartIdxOfTlsConnection(TlsConIdx));

    /* #10 Set the certificates from the received certificate chain in the KeyM certificate group. */
    retVal = TcpIp_TlsCoreMsg_CertMsgSetCertificatesInGroup(TlsConIdx, CertStartIdx, NumCerts);

    if (retVal == E_OK)
    {
      /* #20 Check if there is a matching signature algorithm in the sent CertificateRequest for the received certificates. */
      retVal = TcpIp_TlsServerMsg_ClientCertMsgCheckSigHashAlgo(TlsConIdx);
    }

    /* #30 If all certificates were successfully extracted and loaded, trigger verification of the leaf certificate */
    if (retVal == E_OK)
    {
      /* Get the KeyM group with TlsRemoteKeyMCertInfoStartIdx. */
      /* It is checked in TcpIp_TlsCoreUtil_CheckEccKeyMConfiguration()
       * that TcpIp_GetKeyMVerifyGroupFuncOfTlsConfig() is not a NULL_PTR. */
      TcpIp_TlsKeyMVerifyGroupFunctionType verifyGroupFunc
        = TcpIp_GetKeyMVerifyGroupFuncOfTlsConfig(TCPIP_TLSCONFIG_IDX);
      if (verifyGroupFunc(keyMCertGroupId) == E_OK)
      {
        /* Update Hs certificate state to in progress */
        /* [HS Client Certificate Chain Handling StM] Certificates loaded successfully and verification triggered  */
        TcpIp_SetHsCertStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CERTCHAIN_IN_PROGRESS);
      }
      else
      {
        /* Verification failed - one reason may be Root or intermediate certificate not found, or KeyM is busy */
        TcpIp_TlsServerMsg_ClientCertMsgHandleFailedCertGroupValidation(TlsConIdx);

        retVal = E_NOT_OK;
      }
    }
  }
  else
  {
    TcpIp_TlsCoreUtil_HandleInvalidConfiguration(TlsConIdx);
  }

  return retVal;
} /* TcpIp_TlsServerMsg_ClientCertMsgParseAndTriggerVerification */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientCertMsgCheckSigHashAlgo
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientCertMsgCheckSigHashAlgo(
  TcpIp_TlsConnectionIterType         TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SignatureAlgorithmIdType receivedSigAlgoId = TCPIP_SIG_ALGO_ID_NONE;
  TcpIp_TlsCertValidationStatusDynStartIdxOfTlsConnectionType tlsCertValidationStatusIdx =
    TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxIterType sigAlgoListLenTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxCertificateRequestSignatureAndHashAlgorithmListIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);
  TcpIp_TlsBufferTxIterType tlsBufferTxSigAlgoStartIdx =
    sigAlgoListLenTlsBufferTxIdx + TCPIP_TLS_SIGNATURE_ALGORITHMS_LENGTH_LEN;
  TcpIp_TlsBufferTxIterType iterTlsBufferTxIdx = tlsBufferTxSigAlgoStartIdx;
  uint16 sigAlgoListLen = 0u;
  TcpIp_SignatureAlgorithmIdType currentReadSigAlgoId = TCPIP_SIG_ALGO_ID_NONE;

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ---------------------------------------------- */
  /* #10 Get the signature and hash algorithm Id used for the leaf certificate. */
  /* We assume for now that the signature algorithm is the same for all certificates in the chain.
   * This is checked later in the KeyM (KeyM_VerifyGroup()). */
  if (TcpIp_TlsCoreUtil_ReadCertSignatureAlgorithm(
    TcpIp_GetAddrTlsCertValidationStatusDyn(tlsCertValidationStatusIdx)->CertId,
    &receivedSigAlgoId) == E_OK)
  {
    /* #20 Iterate through the list of signature hash algorithm Id in the sent CertificateRequest. */
    sigAlgoListLen = IpBase_GetUint16(TcpIp_GetAddrTlsBufferTx(sigAlgoListLenTlsBufferTxIdx), 0u);
    for (; iterTlsBufferTxIdx < (tlsBufferTxSigAlgoStartIdx + ((TcpIp_TlsBufferTxIterType)sigAlgoListLen * TCPIP_TLS_SIGNATURE_ALGORITHMS_ALG_ID_LEN));
           iterTlsBufferTxIdx += TCPIP_TLS_SIGNATURE_ALGORITHMS_ALG_ID_LEN)
    {
      currentReadSigAlgoId
        = (TcpIp_SignatureAlgorithmIdType)IpBase_GetUint16(TcpIp_GetAddrTlsBufferTx(iterTlsBufferTxIdx), 0u);           /* PRQA S 4342 */ /* MD_TcpIp_TlsCore_10.5_4342_a */
      /* #30 Check if one algorithm Id matches the Id of the leaf certificate. */
      if (currentReadSigAlgoId == receivedSigAlgoId)
      {
        /* #40 Matching algorithm Id found, save it and return E_OK. */
        TcpIp_SetClientAuthSignatureAlgorithmIdOfTlsServerConnection(                                                   /* TCPIP_CSL_MISSDETECTION */
          TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx), receivedSigAlgoId);
        retVal = E_OK;
        break;
      }
    }

    if (retVal != E_OK)
    {
      /* #50 No matching algorithm Id found, set illegal_parameter alert and return E_NOT_OK. */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_ILLEGAL_PARAM);
    }
  }
  else
  {
    /* Not able to read algorithm from certificate, set internal_error alert, retVal is already E_NOT_OK. */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
  }

  return retVal;
} /* TcpIp_TlsServerMsg_ClientCertMsgCheckSigHashAlgo */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientCertMsgHandleFailedCertGroupValidation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ClientCertMsgHandleFailedCertGroupValidation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ---------------------------------------------- */
  /* #10 Update Hs certificate state to finished as no further certificate processing will be done */
  /* [HS Client Certificate Chain Handling StM] Certificates loaded successfully and but verification failed */
  TcpIp_SetHsCertStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CERTCHAIN_VERIFY_FAILED);

  /* #20 Received server certificate with unknown CA - trigger TLS error indication */
#    if (TCPIP_SUPPORT_ASRTLS_ERROR_INDICATION == STD_ON)
  TcpIp_TlsCoreError_IndicationTrigger(TlsConIdx, TCPIP_TLS_E_UNKNOWN_CA, TCPIP_TLS_ALERT_UNSET);
#    endif

  /* #30 Trigger alert. Either no matching root cert was found, or cert chain is not consistent in itself. */
  TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNKNOWN_CA);

  /* Update status for certificate chain. Ignore return value because we know that the chain is invalid and the
     handshake will be canceled anyway. */
  (void)TcpIp_TlsCoreUtil_TlsUpdateCertChainStatus(TlsConIdx, TCPIP_TLS_UPDATE_CERT_MODE_CHAIN);
} /* TcpIp_TlsServerMsg_ClientCertMsgHandleFailedCertGroupValidation */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientCertMsgVerifyCertificateGroup
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientCertMsgVerifyCertificateGroup(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Update the KeyM status of each certificate */
  if (TcpIp_TlsCoreUtil_TlsUpdateCertChainStatus(TlsConIdx, TCPIP_TLS_UPDATE_CERT_MODE_CHAIN) == E_OK)
  {
    TcpIp_CertValidationResultType result = TCPIP_TLS_VALIDATION_NOT_OK;

    /* #20 Try to obtain overall validation result and update states */
    TcpIp_TlsCoreUtil_TlsUpdateOverallCertValidationResult(TlsConIdx, &result);

    /* Set certificate chain validation state to finished */
    /* [HS Client Certificate Chain Handling StM] Certificate verification is finished */
    TcpIp_SetHsCertStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CERTCHAIN_FINISHED);

    /* Set the async state to DONE */
    TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);

    /* #30 Check if the overall validation result is OK or NOT_OK.
        If it is NOT_OK check if the validation callback needs to be called here or later. */
    TcpIp_TlsServerMsg_ClientCertMsgCheckCertChainOverallResult(TlsConIdx, result);

    retVal = E_OK;
  }
  else
  {
    /* #40 TlsUpdateCertChainStatus failed, something is wrong with the certificates. Cancel the handshake. */
    retVal = E_NOT_OK;
  }

  return retVal;
} /* TcpIp_TlsServerMsg_ClientCertMsgVerifyCertificateGroup */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientCertMsgCheckCertChainOverallResult
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ClientCertMsgCheckCertChainOverallResult(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_CertValidationResultType Result)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the overall validation result is OK or NOT_OK. */
  if (Result == TCPIP_TLS_VALIDATION_OK)
  {
    /* #20 If certificate validation done successfully, set state to complete */
    /* [HS Client Certificate Chain Handling StM] Certificate has been validated successfully, all steps are complete */
    TcpIp_SetHsCertStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CERTCHAIN_COMPLETE);
  }
  else
  {
    /* The overall result is NOT_OK. The handshake has to be canceled. */
    TcpIp_TlsAlertDescriptionType alertDescription = TCPIP_TLS_ALERT_UNSET;
    TcpIp_TlsCoreUtil_TlsGetAlertForBadCertificateChain(TlsConIdx, &alertDescription);

#    if (TCPIP_SUPPORT_ASRTLS_ERROR_INDICATION == STD_ON)
    if (alertDescription == TCPIP_TLS_ALERT_DESC_CERT_EXPIRED)
    {
      /* Received client certificate is expired - trigger TLS error indication */
      TcpIp_TlsCoreError_IndicationTrigger(TlsConIdx, TCPIP_TLS_E_CLIENT_CERT_EXPIRED, TCPIP_TLS_ALERT_UNSET);
    }
#    endif

    /* #30 If certificate validation was unsuccessful, reset state to INIT */
    /* [HS Client Certificate Chain Handling StM] Certificate not validated successfully, reset StM */
    TcpIp_SetHsCertStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CERTCHAIN_INIT);

    /* #40 Trigger the transmission of the occurred alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, alertDescription);
  }
} /* TcpIp_TlsServerMsg_ClientCertMsgCheckCertChainOverallResult() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ExtractClientCertificateVerifyInformation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ExtractClientCertificateVerifyInformation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Extract the message information until we are done, the handshake must be aborted, or the context should be switched */
  while (   (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFY_DONE)/* PRQA S 3415 4 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
             /* Handshake is not aborted due to processing error */
         && (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_HANDSHAKE_ABORT)
             /* Async operation is pending */
         && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_ASYNC_PENDING)
             /* Error during parsing - abort next steps */
         && (retVal == E_OK))
  {
    switch (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx))
    {
      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFY:
      {
        /* #20 Call the subfunction to parse the received ClientCertificateVerify parameters */
        retVal = TcpIp_TlsServerMsg_ClientCertificateVerifyGetParams(TlsConIdx);
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFY_VERIFY_SIGNATURE);
        break;
      } /* case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFY */

      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFY_VERIFY_SIGNATURE:
      {
        /* This operation is time consuming and thus is calculated in the lowPrio (async) task.
           Trigger the calculation, leave this context and return if the operation is done */

        /* #30 Trigger the calculation of the job in the async context handler and change the handshake state to ASYNC_PENDING */
        TcpIp_SetVerifySignatureOfCertificateVerifyAsyncFlagOfTlsServerConnection(                                      /* TCPIP_CSL_MISSDETECTION */
          TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx), TRUE);
        TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_ASYNC_PENDING);
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFY_WAIT_FOR_ASYNC);

        break;
      } /* case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFY_VERIFY_SIGNATURE */

      case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFY_WAIT_FOR_ASYNC:
      {
        /* #40 Parsing of ClientCertificateVerify message done */
        TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_NO_ASYNC);

        /* Decrement HsRxIndicationCnt since the ClientCertificateVerify message is completely parsed */
        TcpIp_DecHsRxIndicationCntOfTlsConnectionDyn(TlsConIdx);
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFY_DONE);
        break;
      } /* case TCPIP_TLS_STATE_WAIT_FOR_CLIENT_CERTIFICATE_VERIFY_WAIT_FOR_ASYNC */

      default: /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
      {
        break;
      } /* default */
    } /* switch() */
  } /* while() */

  return retVal;
} /* TcpIp_TlsServerMsg_ExtractClientCertificateVerifyInformation() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientCertificateVerifyGetParams
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientCertificateVerifyGetParams(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtDynIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxClientCertificateVerifyIdxOfTlsServerBufferMgmtType clientCertVerifyStartIdx =
    TcpIp_GetTlsBufferRxClientCertificateVerifyIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

  TcpIp_ClientCertificateVerifyLenOfTlsServerBufferMgmtType clientCertVerifyLen =
    TcpIp_GetClientCertificateVerifyLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

  TcpIp_TlsBufferRxClientCertificateVerifyIdxOfTlsServerBufferMgmtType clientCertVerifyEndIdx
    = (clientCertVerifyStartIdx + TCPIP_TLS_HSHDRLEN + clientCertVerifyLen);

  Std_ReturnType retVal = E_NOT_OK;
  TcpIp_SignatureAlgorithmIdType algorithm = TCPIP_SIG_ALGO_ID_NONE;
  uint16 signatureLength = 0u;
  /* ----- Implementation ----------------------------------------------- */
  /* Check that message is long enough to contain the signature algorithm and the length field for the signature. */
  if (   (TcpIp_TlsHs_CheckExpectedMsgLen(clientCertVerifyLen,
            TCPIP_TLS_CERTVERIFY_SIGALGO_LEN + TCPIP_TLS_CERTVERIFY_SIG_LENGTH_LEN) == E_OK)
      && (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx),
            TCPIP_TLS_CERTVERIFY_SIGALGO_LEN, clientCertVerifyEndIdx)))
  {
    /* #10 Read the signature algorithm sent by the client. */
    algorithm = (TcpIp_SignatureAlgorithmIdType) IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(                             /* PRQA S 4342 */ /* MD_TcpIp_TlsCore_10.5_4342_a */
      TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx)), 0u);
    TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx, TCPIP_TLS_CERTVERIFY_SIGALGO_LEN);

    /* #20 Check if the received signature algorithm matches the signature algorithm in the received certificate. */
    if (TcpIp_GetClientAuthSignatureAlgorithmIdOfTlsServerConnection(tlsServerConnectionIdx) == algorithm)
    {
      retVal = E_OK;
    }
    else
    {
      /* retVal already E_NOT_OK, this case specifically needs an illegal_parameter alert instead of a decode_error. */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_ILLEGAL_PARAM);
    }

    /* Check that the received message is long enough to contain a signature with the specified length. */
    if (   (retVal == E_OK)
        && (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx),     /* PRQA S 2995 2 */ /* MD_TcpIp_Tls_2995 */
              TCPIP_TLS_CERTVERIFY_SIG_LENGTH_LEN, clientCertVerifyEndIdx)))
    {
      /* #30 Read the length of the signature. */
      signatureLength
        = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx)), 0u);
      /* Save the index to the length of the signature. */
      TcpIp_SetTlsBufferRxClientSignatureLenIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx,
        TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx));
      TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx, TCPIP_TLS_CERTVERIFY_SIG_LENGTH_LEN);

      if (   (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx),   /* PRQA S 2995 2 */ /* MD_TcpIp_Tls_2995 */
                signatureLength, clientCertVerifyEndIdx))
          && (clientCertVerifyLen
                == (TCPIP_TLS_CERTVERIFY_SIGALGO_LEN + TCPIP_TLS_CERTVERIFY_SIG_LENGTH_LEN + signatureLength)))
      {
        /* Save the index to the signature of the message. */
        TcpIp_SetTlsBufferRxClientSignatureIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx,
          TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx));
        TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx, signatureLength);

        /* Check if all data was consumed. */
        retVal = TcpIp_TlsMsg_CheckMsgForRemainingData(TlsConIdx, clientCertVerifyEndIdx);
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
} /* TcpIp_TlsServerMsg_ClientCertificateVerifyGetParams() */
#   endif /* TCPIP_SUPPORT_ASRTLS_ECC == STD_ON */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ExtractClientFinishedInformation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ExtractClientFinishedInformation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType rxClientFinishedVerifyDataIdx
    = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  /* rxClientFinishedVerifyDataIdx is pointing to the start of the message, therefore -1 is pointing to the length at the beginning */
  uint8 rxClientFinishedVerifyDataLen = TcpIp_GetTlsBufferRx(rxClientFinishedVerifyDataIdx - 1u);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Compare the received Client finished verify data length against the expected one */
  if (rxClientFinishedVerifyDataLen == TCPIP_TLS_FINISHED_VERIFYDATA_LEN)
  {
    /* #20 Received length match - store the index of the finished verify data */
    /* Save the position of the received ClientFinishedVerifyData */
    TcpIp_SetTlsBufferRxClientFinishedVerifyDataIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx,
      rxClientFinishedVerifyDataIdx);

    /* Increment the Rx buffer ReadIdx by the length of the VerifyData (12Byte) */
    TcpIp_SetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
      rxClientFinishedVerifyDataIdx + TCPIP_TLS_FINISHED_VERIFYDATA_LEN);

    retVal = E_OK;
  }
  else
  {
    /* #30 else - Received length mismatch - Report the error to the user and trigger TLS alert */
    TcpIp_TlsUserErrorType UserError;
    UserError.FunctionId  = TCPIP_TLS_FCTID_CLIENT_HSSTM_PARSE_SERVERFINISHED;
    UserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_UNEXPECTEDMSGLEN;
    UserError.TlsConId    = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(UserError);

    /* Trigger alert TCPIP_TLS_ALERT_DESC_DECODE_ERROR in case of invalid length */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
  }

  return retVal;
} /* TcpIp_TlsServerMsg_ExtractClientFinishedInformation() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_CalcClientFinishedHash
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_CalcClientFinishedHash(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx
    = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Handles synchronous CSM call and trigger the calculation of the job in the async context handler */
  TcpIp_SetCalcClientFinishedHashAsyncFlagOfTlsServerConnection(tlsServerConnectionIdx, TRUE);

  /* Set the TLS connection state to ASYNC_PENDING */
  TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_ASYNC_PENDING);

} /* TcpIp_TlsServerMsg_CalcClientFinishedHash() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_CalcClientFinishedVerifyData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_CalcClientFinishedVerifyData(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx
    = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Handles synchronous CSM call and trigger the calculation of the job in the async context handler */
  TcpIp_SetCalcClientFinishedVerifyDataAsyncFlagOfTlsServerConnection(tlsServerConnectionIdx, TRUE);

  /* Set the TLS connection state to ASYNC_PENDING */
  TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_ASYNC_PENDING);

} /* TcpIp_TlsServerMsg_CalcClientFinishedVerifyData() */


/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_CompareFinishedVerifyData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
  */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_CompareFinishedVerifyData(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* Calculated data is present in Temp buffer */
  TCPIP_P2C(uint8) calculatedVerifyDataPtr = TcpIp_GetAddrTlsTemporaryFinishedBuffer(
    TcpIp_GetTlsTemporaryFinishedBufferStartIdxOfTlsConnection(TlsConIdx));

  TCPIP_P2C(uint8) receivedVerifyDataPtr = TcpIp_GetAddrTlsBufferRx(
    TcpIp_GetTlsBufferRxClientFinishedVerifyDataIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx));

  /* #10 Compare the calculated and received TLS finished verify data */
  if (IpBase_StrCmpLen(receivedVerifyDataPtr, calculatedVerifyDataPtr, TCPIP_TLS_FINISHED_VERIFYDATA_LEN) == E_OK)
  {
    /* #20 Values match - return E_OK */
    retVal = E_OK;
  }
  else
  {
    /* #30 Value mismatch - Report an error to the user and trigger TLS alert */
    TcpIp_TlsUserErrorType UserError;
    UserError.FunctionId  = TCPIP_TLS_FCTID_CLIENT_HSSTM_PARSE_SERVERFINISHED;
    UserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_INCORRECTVERIFYDATA;
    UserError.TlsConId    = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(UserError);
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECRYPT_ERROR);
  }
  return retVal;
} /* TcpIp_TlsServerMsg_CompareFinishedVerifyData() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloGetCipherSuites
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloGetCipherSuites(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(TcpIp_TlsBufferRxClientHelloIdxOfTlsServerBufferMgmtType, AUTOMATIC) ClientHelloEndIdx )
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the received cipher suite list length */
  if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx),              /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
        TCPIP_TLS_CIPHERSUITESLEN_LEN, ClientHelloEndIdx))
  {
    /* Get the length of the received cipher suite list */
    uint16 cipherSuitesLen = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(
      TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)), 0u);

    /* Maintain AdHs read index by incrementing the consumed length */
    TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_CIPHERSUITESLEN_LEN);

    /* see RFC5246 - A.5.  The Cipher Suite */
    if ((cipherSuitesLen >= TCPIP_TLS_CIPHERSUITEID_LEN) /* Cipher suite ID contains minimum of 2 bytes */              /* PRQA S 3415 3 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
             /* and the length information is send pairwise, so the length must be even */
      && ((cipherSuitesLen % TCPIP_TLS_CIPHERSUITEID_LEN) == 0u)
      /* Check the range */
      && (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(                                                                              /* PRQA S 2995 2 */ /* MD_TcpIp_Tls_2995 */
        TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx), cipherSuitesLen, ClientHelloEndIdx)))
    {
      /* #20 Cipher suite list length match - Search for a matching cipher worker which suits this connection */
      retVal = TcpIp_TlsServerMsg_SelectMatchingCipherWorker(TlsConIdx, cipherSuitesLen);

      /* Maintain AdHs read index by incrementing the consumed length */
      TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, cipherSuitesLen);
    } /* Range check failed. E_NOT_OK */
  } /* Overall range check failed. E_NOT_OK */

  /* #30 Received cipher suite list length mismatch - Report an error to the user and trigger TLS alert */
  if (retVal != E_OK)
  {
    TcpIp_TlsUserErrorType UserError;
    UserError.FunctionId  = TCPIP_TLS_FCTID_SERVER_HSSTM_PARSE_CLIENTHELLO;
    UserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_INCORRECTCIPHERLEN;
    UserError.TlsConId    = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(UserError);

    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);

    retVal = E_NOT_OK;
  }

  return retVal;
} /* TcpIp_TlsServerMsg_ClientHelloGetCipherSuites() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloGetCompressionMethods
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloGetCompressionMethods(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(TcpIp_TlsBufferRxIterType, AUTOMATIC) HelloEndIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the received compression method length */
  /* Get the length of the received compression method list */
  if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx),              /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
        TCPIP_TLS_COMPMETHLEN_LEN, HelloEndIdx))
  {
    uint8 receivedCompressionMethodsLen = IpBase_GetUint8(
      TcpIp_GetAddrTlsBufferRx(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)), 0u);

    /* Maintain AdHs read index by incrementing the consumed length */
    TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_COMPMETHLEN_LEN);

    /* Accordingly to RFC5246: At least one compression method must be received */
    if ((receivedCompressionMethodsLen >= 1u)
      /* Range check */
      && (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx),          /* PRQA S 3415, 2995 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly, MD_TcpIp_Tls_2995 */
        (TcpIp_TlsBufferRxIterType) receivedCompressionMethodsLen, HelloEndIdx)))
    {
      /* #20 Received compression method length match - Select matching local compression method */
      retVal = TcpIp_TlsMsg_SelectMatchingCompressionMethod(TlsConIdx, receivedCompressionMethodsLen);

      /* Maintain AdHs read index by incrementing the consumed length */
      TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, receivedCompressionMethodsLen);
    } /* Range check failed. E_NOT_OK */
  } /* Overall range check failed. E_NOT_OK */

  /* #30 Received compression method length mismatch - Report an error to the user and trigger TLS-Alert */
  if (retVal != E_OK)
  {
    TcpIp_TlsUserErrorType UserError;
    UserError.FunctionId  = TCPIP_TLS_USERERROR_PARSEHELLO(TlsConIdx);
    UserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_INCORRECTCOMPRESSIONLEN;
    UserError.TlsConId    = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(UserError);

    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
  }

  return retVal;
} /* TcpIp_TlsServerMsg_ClientHelloGetCompressionMethods() */

/**********************************************************************************************************************
 *  TcpIp_TlsMsg_SelectMatchingCompressionMethod
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsMsg_SelectMatchingCompressionMethod(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC)     CompressionMethodLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  uint8_least compressionMethodIter;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all received compression methods and check if we receive at least one supported compression method */
  for (compressionMethodIter = 0; compressionMethodIter < CompressionMethodLen; compressionMethodIter++)
  {
    uint8 receivedCompressionMethod = TcpIp_GetTlsBufferRx(
      TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx) + compressionMethodIter);

    /* #20 Compare received compression method with the supported one NONE(0x00) */
    /* Accordingly to RFC5246 - Section 7.4.1.2 Client Hello at least the NONE method must be supported */
    if (receivedCompressionMethod == TCPIP_TLS_COMPRESSION_METHOD_NONE)
    {
      /* Valid compression method received - return E_OK and skip further processing */
      retVal = E_OK;
      break;
    }
  }

  return retVal;
} /* TcpIp_TlsMsg_SelectMatchingCompressionMethod() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloStoreSessionIdBufferIndex
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloStoreSessionIdBufferIndex(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC)     SessionIdLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Store the buffer index of the session Id if it is non-empty */
  if (SessionIdLen > 0u)
  {
    /* Store the start index of the received client session ID */
    TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
      = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);
    TcpIp_SetTlsBufferRxClientSessionIdIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx,
      TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));
  }
} /* TcpIp_TlsServerMsg_ClientHelloStoreSessionIdBufferIndex() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloGetExtensions
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloGetExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(TcpIp_TlsBufferRxClientHelloIdxOfTlsServerBufferMgmtType, AUTOMATIC) ClientHelloEndIdx )
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  Std_ReturnType retVal = E_NOT_OK;

  uint16 extensionsLen;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the received extensions list length */

  /* #20 Check if we received TLS Hello-Extensions and parse them */

  /* Check if we are already at the end of the message. */
  if (TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx) == ClientHelloEndIdx)
  {
    /* #30 No extensions have been detected */
    /* Valid case - return E_OK */
    retVal = E_OK;
  }
  else
  {
    /* Check the extensions length for validity. */
    if (TcpIp_TlsCoreUtil_GetExtensionsLengthAndCheckForValidity(TlsConIdx, ClientHelloEndIdx, &extensionsLen) == E_OK)
    {
      /* Extensions present, parse them */
      /* #40 Forward all received extensions to the specific parser */
      retVal = TcpIp_TlsServerMsg_ClientHelloParseAndValidateExtensions(TlsConIdx,
        extensionsLen, ClientHelloEndIdx);
    }
  }

  /* #50 Extensions list length mismatch - Report an error to the user and trigger TLS-Alert */
  if (retVal != E_OK)
  {
    TcpIp_TlsUserErrorType UserError;
    UserError.FunctionId  = TCPIP_TLS_FCTID_SERVER_HSSTM_PARSE_CLIENTHELLO;
    UserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_INCORRECTEXTENSIONSLEN;
    UserError.TlsConId    = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(UserError);
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);

  }

  return retVal;
} /* TcpIp_TlsServerMsg_ClientHelloGetExtensions() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloParseAndValidateExtensions
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloParseAndValidateExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16                      ExtensionsLen,
  TcpIp_TlsBufferRxIterType   HelloEndIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsExtensionType listOfReceivedExtensions[TCPIP_TLS_MAX_EXTENSION_LIST_LENGTH] = { 0 };
  uint8 overallNumberOfReceivedExtensions = 0u;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Iterate over the extension data and extract each extension into overall list of received extensions */
  if (TcpIp_TlsMsg_ExtractReceivedExtensions(TlsConIdx, ExtensionsLen, HelloEndIdx,
        &listOfReceivedExtensions[0], &overallNumberOfReceivedExtensions) == E_OK)
  {
    /* #20 Check for duplicated received extensions */
    if (TcpIp_TlsMsg_CheckDuplicatedReceivedExtensions(&listOfReceivedExtensions[0],
          overallNumberOfReceivedExtensions) == E_OK)
    {
      /* #30 Parse received extensions */
      if (TcpIp_TlsServerMsg_ClientHelloParseReceivedExtensions(TlsConIdx, &listOfReceivedExtensions[0],                /* PRQA S 2991, 2995 2 */ /* MD_TCPIP_Rule14.3_2741_2742_2991_2992_2995_2996 */
            overallNumberOfReceivedExtensions) == E_OK)
      {
        /* #40 All extension fully validated and parsed - return E_OK */
        retVal = E_OK;
      }
      /* else - TLS-Alert handling is done in the context of the extension parser */
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


  return retVal;
} /* TcpIp_TlsServerMsg_ClientHelloParseAndValidateExtensions() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloParseReceivedExtensions
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
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloParseReceivedExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(TcpIp_TlsExtensionType) ReceivedExtensionListPtr,
  uint8 ReceivedExtensionCnt)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 rxExtensionIter;
  Std_ReturnType retVal = E_OK;
  TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  TcpIp_SetTlsHandshakeSupportedGroupsExtensionMissingOfTlsServerConnection(tlsServerConnectionIdx, TRUE);

  /* #10 Iterate over all received client extensions */
  for (rxExtensionIter = 0u; rxExtensionIter < ReceivedExtensionCnt; rxExtensionIter++)
  {
    /* Get the next received extension type and parse it depending on the type */
    uint16 currentReceivedExtensionType = ReceivedExtensionListPtr[rxExtensionIter].Type;

    switch (currentReceivedExtensionType)
    {
      case TCPIP_TLS_EXTENSION_SERVER_NAME_INDICATION:
      {
        /* #20 In case of extension type server_name_indication (0) - forward to specific parser */
        retVal = TcpIp_TlsServerMsg_ClientHelloParseExtensionServerNameIndication(TlsConIdx,
          ReceivedExtensionListPtr[rxExtensionIter]);
        break;
      }
      case TCPIP_TLS_EXTENSION_TRUSTED_CA_INDICATION:
      {
        /* #30 In case of extension type trusted_ca_keys (3) - forward to specific parser */
        retVal = TcpIp_TlsServerMsg_ClientHelloParseExtensionTrustedCaIndication(TlsConIdx,
          ReceivedExtensionListPtr[rxExtensionIter]);
        break;
      }
      case TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST:
      {
        /* #40 In case of extension type status_request (5) - forward to specific parser */
        retVal = TcpIp_TlsServerMsg_ClientHelloParseExtensionCertificateStatusRequest(TlsConIdx,
          ReceivedExtensionListPtr[rxExtensionIter]);
        break;
      }
      case TCPIP_TLS_EXTENSION_SUPPORTED_GROUPS:
      {
        /* #50 In case of extension type supported_groups (10) - forward to specific parser */
        /* Set flag to false to indicate missing supported_groups extension.
           The flag is evaluated in TcpIp_TlsServerHsStm_CheckHandshakesForMatchingCert() */
        TcpIp_SetTlsHandshakeSupportedGroupsExtensionMissingOfTlsServerConnection(tlsServerConnectionIdx, FALSE);
        retVal = TcpIp_TlsServerMsg_ClientHelloParseExtensionSupportedGroups(TlsConIdx,
          ReceivedExtensionListPtr[rxExtensionIter]);
        break;
      }
      case TCPIP_TLS_EXTENSION_EC_POINT_FORMAT:
      {
        /* #60 In case of extension type ec_point_formats(11) - forward to specific parser */
        retVal = TcpIp_TlsServerMsg_ClientHelloParseExtensionEcPointFormats(TlsConIdx,
          ReceivedExtensionListPtr[rxExtensionIter]);
        break;
      }
      case TCPIP_TLS_EXTENSION_SIGNATURE_ALGORITHMS:
      {
        /* #70 In case of extension type signature_algorithms (13) - forward to specific parser */
        retVal = TcpIp_TlsServerMsg_ClientHelloParseExtensionSignatureAlgorithms(TlsConIdx,
          ReceivedExtensionListPtr[rxExtensionIter]);
        break;
      }

      case TCPIP_TLS_EXTENSION_RECORD_SIZE_LIMIT:
      {
        /* #80 In case of extension type record_size_limit (28) - forward to specific parser */
        retVal = TcpIp_TlsServerMsg_ClientHelloParseExtensionRecordSizeLimit(TlsConIdx,
          ReceivedExtensionListPtr[rxExtensionIter]);
        break;
      }

      default:
      {
        /* #90 In case of unknown extension type - Skip extension processing */
        break;
      }
    }

    /* Stop processing in case of occurred error during parsing of received extensions */
    if (retVal != E_OK)
    {
      break;
    }
  }

  return retVal;
} /* TcpIp_TlsServerMsg_ClientHelloParseReceivedExtensions() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloParseExtensionServerNameIndication
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_TcpIp_TlsRxLengthChecks_STMIF */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloParseExtensionServerNameIndication(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType ServerNameIndicationExtension)
{

  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsBufferRxIterType extServerNameListLenIdx = ServerNameIndicationExtension.StartIdx;
  uint16 overallExtLength = ServerNameIndicationExtension.Length;
  TcpIp_TlsBufferRxIterType extServerNameIndicationEndIdx = extServerNameListLenIdx + overallExtLength;

  Std_ReturnType retVal = E_NOT_OK;
  /* ----- Implementation ----------------------------------------------- */
  /* Extension index information */
  /* Server Name Indication Extension Format (RFC 6066)
   *
   *
   *                             -> extServerNameListLenIdx
   *                            /                     -> extServerNameStartIdx
   *                           /                     /
   *       [ext Type][ext Len][Server Name List Len][name 1]             [name n]
   * Byte: 0       1 2      3 4                   5 6                    (x-1) x
   *                                                 \---consumedExtensionLen---/
   *                           \---overallExtLength-----------------------------/
   */

  /* Range check before read out the received Server Name List length (2Bytes) */
  if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(extServerNameListLenIdx,
        TCPIP_TLS_EXTENSION_SERVER_NAME_LIST_LENGTH_LEN, extServerNameIndicationEndIdx))
  {
    /* #10 Get the length of the received Server Name Indication list and check against the overall length. */
    uint16 receivedServerNameListLen = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(extServerNameListLenIdx), 0u);           /* TCPIP_CSL_NAME_LENGTH */

    if (overallExtLength == (receivedServerNameListLen + TCPIP_TLS_EXTENSION_SERVER_NAME_LIST_LENGTH_LEN))
    {
      TcpIp_TlsBufferRxIterType extServerNameStartIdx
        = extServerNameListLenIdx + TCPIP_TLS_EXTENSION_SERVER_NAME_LIST_LENGTH_LEN;

      /* #20 Check the length of the received Server Name Indication list for plausibility. */
      /* RFC 6066 - 3.  Server Name Indication */
      if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(extServerNameStartIdx, receivedServerNameListLen, extServerNameIndicationEndIdx))/* PRQA S 2991, 2995 */ /* MD_TCPIP_Rule14.3_2741_2742_2991_2992_2995_2996 */
      {
        TcpIp_TlsBufferRxIterType extServerNameEndIdx = extServerNameStartIdx + receivedServerNameListLen;
        TcpIp_TlsBufferRxIterType extServerNameIter;
        uint16 remainingLen;
        boolean hostNameReceived = FALSE;

        /* #30 Iterate over all received Server Names and check their format to be valid. */
        /* The server name list must contain at least one element. */
        extServerNameIter = extServerNameStartIdx;
        retVal = E_OK;
        remainingLen = receivedServerNameListLen;

        while (   (extServerNameIter < extServerNameEndIdx)
               && (retVal == E_OK)
               && (remainingLen >= TCPIP_TLS_EXTENSION_SERVER_NAME_SERVER_NAME_MIN_LEN)
               && (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(extServerNameIter, TCPIP_TLS_EXTENSION_SERVER_NAME_SERVER_NAME_MIN_LEN,  /* PRQA S 2995 1 */ /* MD_TcpIp_Tls_2995 */
                     extServerNameIndicationEndIdx)))
        {
          uint16 serverNameLen;  /* Length of the server name element (including type field)  */

          retVal = TcpIp_TlsServerMsg_ClientHelloExtIsServerNameAcceptable(TlsConIdx, extServerNameIter,
                     extServerNameIndicationEndIdx, &serverNameLen, &hostNameReceived);
          if (retVal == E_OK)
          {
            /* Increase the position by the length of the server name element. */
            extServerNameIter += (TcpIp_TlsBufferRxIterType)serverNameLen;
            /* Reduce the remaining length for all received server names. */
            remainingLen     -= serverNameLen;
          }
        }  /* while */

        if ((retVal != E_OK) || (remainingLen != 0u) || (extServerNameStartIdx == extServerNameEndIdx))
        {
          /* Format error found in this extension - report error and trigger TLS alert */
          /* There may not be any remaining data in the extension that can not be assigned to a server name, and the
          list of server names may not be empty. */
          TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
        }
      }
      else
      {
        /* Received Server Name Indication length mismatch - report error and trigger TLS alert */
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
      }
    }
    else
    {
      /* Overall received length mismatch - report error and trigger TLS alert */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
    }
  }

  return retVal;
} /* TcpIp_TlsServerMsg_ClientHelloParseExtensionServerNameIndication() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloExtIsServerNameAcceptable
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloExtIsServerNameAcceptable(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferRxIterType ServerNameStartTlsBufferRxIdx,
  TcpIp_TlsBufferRxIterType ServerNameIndicationEndIdx,
  TCPIP_P2V(uint16) ServerNameLenPtr,
  TCPIP_P2V(boolean) HostNameReceivedPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TCPIP_P2C(uint8) serverNamePtr = TcpIp_GetAddrTlsBufferRx(ServerNameStartTlsBufferRxIdx);
  uint8  nameType;  /* Type of the name element */
  uint16 nameLen;   /* Length of the name element (without its length field) */
  TcpIp_TlsBufferRxIterType nameStringStartIdx;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* RFC 6066 defines only one valid name type for server name elements. For this type 'host_name' the name must have a
     length of at least 1 byte.
     Other name types are currently unknown, but their value also must start with a 2 byte length field. These other
     name types shall be ignored by this implementation. */

  /* #10 Read the name type and name length. */
  /* The calling function already checked the availability of the 1 byte for the type and the 2 bytes for the length field. */
  nameType = IpBase_GetUint8(serverNamePtr, 0u);
  nameLen  = IpBase_GetUint16(serverNamePtr, TCPIP_TLS_EXTENSION_SERVER_NAME_NAME_TYPE_LEN);

  /* #20 Check that the name fits into the extension. */
  nameStringStartIdx = ServerNameStartTlsBufferRxIdx + TCPIP_TLS_EXTENSION_SERVER_NAME_SERVER_NAME_MIN_LEN;
  if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(nameStringStartIdx, nameLen, ServerNameIndicationEndIdx))
  {
    /* The name fits into the extension */

    /* #30 Analyze the server name element, depending on its type. */
    switch (nameType)
    {
      case TCPIP_TLS_EXTENSION_SERVER_NAME_TYPE_HOST_NAME:
      {
        /* This is the only supported kind of server name, but the name will be ignored. It is only checked that the length of the name is at least 1. */

        if (   (nameLen >= TCPIP_TLS_EXTENSION_SERVER_NAME_HOST_NAME_MIN_LEN)
            && (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(nameStringStartIdx, nameLen, ServerNameIndicationEndIdx)))              /* PRQA S 2995 */ /* MD_TcpIp_Tls_2995 */
        {
          /* host name format is OK */
          *ServerNameLenPtr = (TCPIP_TLS_EXTENSION_SERVER_NAME_SERVER_NAME_MIN_LEN + nameLen);

          /* #40 Ensure that host name element is only received once. */
          if (*HostNameReceivedPtr == FALSE)
          {
            /* received first server name of type 'host_name' */
            *HostNameReceivedPtr = TRUE;
            retVal = E_OK;
          }
          else
          {
            /* Error, host name received more than once. */
            TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_ILLEGAL_PARAM);
          }
        }
        else
        {
          /* error, the host name format is not OK */
        }
        break;
      }
      default:
      {
        /* Unknown name type. The general format (according to RFC 6066) is OK, no further checks are applied. */
        /* For unknown name types it is not checked that they are only received once. */
        *ServerNameLenPtr = (TCPIP_TLS_EXTENSION_SERVER_NAME_SERVER_NAME_MIN_LEN + nameLen);
        retVal = E_OK;
        break;
      }
    }  /* switch */
  }
  else
  {
    /* Error, the name does not fit into the extension */
  }

  return retVal;
}  /* TcpIp_TlsServerMsg_ClientHelloExtIsTrustedAuthorityAcceptable */


/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloParseExtensionTrustedCaIndication
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_TcpIp_TlsStatemachine_STMIF_6080 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloParseExtensionTrustedCaIndication(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType TrustedCaIndicationExtension)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsBufferRxIterType extTrustedCaIndLenTlsBufferRxIdx = TrustedCaIndicationExtension.StartIdx;
  uint16 overallExtLength = TrustedCaIndicationExtension.Length;
  TcpIp_TlsBufferRxIterType extTrustedCaIndicationEndIdx = extTrustedCaIndLenTlsBufferRxIdx + overallExtLength;

  Std_ReturnType retVal = E_NOT_OK;
  /* ----- Implementation ----------------------------------------------- */
  /* Extension index information */
  /* Trusted CA Indication Extension Format
   *
   *
   *                             -> extTrustedCaIndLenTlsBufferRxIdx
   *                            /                          -> extTrustedCaStartIdx
   *                           /                          /
   *       [ext Type][ext Len][Trusted CA Indication Len][hash 1]             [hash n]
   * Byte: 0       1 2      3 4                        5 6    25              (x-1) x
   *                                                      \---consumedExtensionLen---/
   */

  /* Range check before read out the received Trusted CA Indication length (2Bytes) */
  if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(extTrustedCaIndLenTlsBufferRxIdx,
        TCPIP_TLS_EXTENSION_TRUSTED_CA_INDICATION_LIST_LEN, extTrustedCaIndicationEndIdx))
  {
    /* #10 Get the length of the received Trusted CA Indication list and check against the overall length */
    uint16 receivedTrustedCaIndicationLen = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(extTrustedCaIndLenTlsBufferRxIdx), 0u);

    if (overallExtLength == (receivedTrustedCaIndicationLen + TCPIP_TLS_EXTENSION_TRUSTED_CA_INDICATION_LIST_LEN))
    {
      TcpIp_TlsBufferRxIterType extTrustedCaStartIdx
        = extTrustedCaIndLenTlsBufferRxIdx + TCPIP_TLS_EXTENSION_TRUSTED_CA_INDICATION_LIST_LEN;

      /* #20 Check the length of the received Trusted CA Indication list for plausibility */
      /* RFC 6066 - 6.  Trusted CA Indication */
      if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(extTrustedCaStartIdx, receivedTrustedCaIndicationLen, extTrustedCaIndicationEndIdx))/* PRQA S 2991, 2995 */ /* MD_TCPIP_Rule14.3_2741_2742_2991_2992_2995_2996 */
      {
        TcpIp_TlsBufferRxIterType extTrustedCaEndIdx = extTrustedCaStartIdx + receivedTrustedCaIndicationLen;
        TcpIp_TlsBufferRxIterType extTrustedCaIter;
        uint16 remainingLen;

        /* #30 Iterate over all received Trusted Authorities and check their format to be valid */
        extTrustedCaIter = extTrustedCaStartIdx;
        retVal = E_OK;
        remainingLen = receivedTrustedCaIndicationLen;

        while (   (extTrustedCaIter < extTrustedCaEndIdx)
               && (retVal == E_OK)
               && (remainingLen >= TCPIP_TLS_EXTENSION_TRUSTED_CA_TYPE_LEN)
               && (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(extTrustedCaIter, TCPIP_TLS_EXTENSION_TRUSTED_CA_TYPE_LEN,  /* PRQA S 2995 1 */ /* MD_TcpIp_Tls_2995 */
                     extTrustedCaIndicationEndIdx)))
        {
          uint16 trustedAuthorityLen = 0u;
          retVal = TcpIp_TlsServerMsg_ClientHelloExtIsTrustedAuthorityAcceptable(extTrustedCaIter,
                     extTrustedCaIndicationEndIdx, &trustedAuthorityLen);
          if (retVal == E_OK)
          {
            /* Increase the position by the length of the trusted authority element. */
            extTrustedCaIter += (TcpIp_TlsBufferRxIterType)trustedAuthorityLen;
            /* Reduce the remaining length for all received trusted authorities. */
            remainingLen     -= trustedAuthorityLen;
          }
        }  /* while */

        if (retVal != E_OK)
        {
          /* Format error found in this extension - report error and trigger TLS alert */
          TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
        }
      }
      else
      {
        /* Received Trusted CA Indication length mismatch - report error and trigger TLS alert */
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
      }
    }
    else
    {
      /* Overall received length mismatch - report error and trigger TLS alert */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
    }
  }

  return retVal;

} /* TcpIp_TlsServerMsg_ClientHelloParseExtensionTrustedCaIndication() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloExtIsTrustedAuthorityAcceptable
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloExtIsTrustedAuthorityAcceptable(
  TcpIp_TlsBufferRxIterType TrustedAuthStartTlsBufferRxIdx,
  TcpIp_TlsBufferRxIterType TrustedCaIndicationEndIdx,
  TCPIP_P2V(uint16) TrustedAuthorityLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TCPIP_P2C(uint8) trustedAuthorityPtr = TcpIp_GetAddrTlsBufferRx(TrustedAuthStartTlsBufferRxIdx);
  uint8  identifierType;
  uint16 identifierLen = 0;
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Analyze the trusted authority element, depending on its type. */

  /* Get the received Trusted Authority element type. */
  /* The availability of the 1 byte for the authority type is assured in the calling function. */
  identifierType = IpBase_GetUint8(trustedAuthorityPtr, 0u);

  /* Proceed depending on the type of the trusted authority. */
  switch (identifierType)
  {
    case TCPIP_TLS_EXTENSION_TRUSTED_CA_TYPE_PRE_AGREED:
    {
      /* Pre-agreed trusted authorities */
      /* identifierLen already is set to 0 */
      break;
    }
    case TCPIP_TLS_EXTENSION_TRUSTED_CA_TYPE_KEY_SHA1_HASH:
    {
      /* Hash of the public key */
      identifierLen = TCPIP_TLS_HASH_SHA1_LEN;
      /* This kind of trusted authority hint is not supported and will be ignored. */
      break;
    }
    case TCPIP_TLS_EXTENSION_TRUSTED_CA_TYPE_X509_NAME:
    {
      /* Distinguished name */
      TcpIp_TlsBufferRxIterType distingNameStartTlsBufferRxIdx = TrustedAuthStartTlsBufferRxIdx + TCPIP_TLS_EXTENSION_TRUSTED_CA_TYPE_LEN;

      /* This kind of trusted authority hint is not supported and will be ignored. Only the length of the whole
      distinguished name is checked to be valid. */

      /* Check if at least 2 bytes for the length field are available */
      if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(distingNameStartTlsBufferRxIdx,  /* PRQA S 2995 1 */ /* MD_TcpIp_Tls_2995 */
          TCPIP_TLS_EXTENSION_TRUSTED_CA_DN_LENGTH_LEN, TrustedCaIndicationEndIdx))
      {
        identifierLen = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(distingNameStartTlsBufferRxIdx), 0u)
                        + TCPIP_TLS_EXTENSION_TRUSTED_CA_DN_LENGTH_LEN;

        /* Check that distinguished name is at least 1 byte long. */
        if (identifierLen < (TCPIP_TLS_EXTENSION_TRUSTED_CA_DN_LENGTH_LEN + TCPIP_TLS_EXTENSION_TRUSTED_CA_DN_MIN_LEN))
        {
          retVal = E_NOT_OK;
        }
      }
      else
      {
        /* error, the length field does not fit into the received extension */
        retVal = E_NOT_OK;
      }
      break;
    }
    case TCPIP_TLS_EXTENSION_TRUSTED_CA_TYPE_CERT_SHA1_HASH:
    {
      /* Hash of the complete certificate */
      identifierLen = TCPIP_TLS_HASH_SHA1_LEN;

      /* This is the only kind of trusted authority hints we want to accept. Implementing this feature is not
      yet planned, so this trusted authority hint will be ignored. */
      break;
    }
    default:
    {
      /* error, invalid type */
      retVal = E_NOT_OK;
      break;
    }
  }

  /* #20 Check that the length of the trusted authority element is not too big. */
  if ((retVal == E_OK)
    && (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(((TcpIp_TlsBufferRxIterType)(TrustedAuthStartTlsBufferRxIdx + TCPIP_TLS_EXTENSION_TRUSTED_CA_TYPE_LEN)),/* PRQA S 2995 1 */ /* MD_TcpIp_Tls_2995 */
      identifierLen, TrustedCaIndicationEndIdx)))
  {
    /* OK, length of the TrustedAuthority fits into the received extension */
    /* #30 Set the trusted authority length if the element has a valid format. */
    *TrustedAuthorityLenPtr = (TCPIP_TLS_EXTENSION_TRUSTED_CA_TYPE_LEN + identifierLen);
  }
  else
  {
    /* error, length of the TrustedAuthority does not fit into the received extension */
    retVal = E_NOT_OK;
  }

  return retVal;
}  /* TcpIp_TlsServerMsg_ClientHelloExtIsTrustedAuthorityAcceptable */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloParseExtensionCertificateStatusRequest
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloParseExtensionCertificateStatusRequest(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType CertificateStatusRequestExtension)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsBufferRxIterType extCertStatusTypeTlsBufferRxIdx = CertificateStatusRequestExtension.StartIdx;
  uint16 overallExtLength = CertificateStatusRequestExtension.Length;
  TcpIp_TlsBufferRxIterType extCertStatusRequestEndIdx = extCertStatusTypeTlsBufferRxIdx + overallExtLength;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* Extension index information */
  /* Certificate Status Request Extension Format
   *
   *
   *                              +-> extCertStatusTypeTlsBufferRxIdx
   *                             /                 +-> extResponderIdListIdx
   *                            /                 /                  +-> extRequestExtensionsIdx
   *                           /                 /                  /
   *       [ext Type][ext Len][Cert Status Type][Responder ID List][Request Extensions]
   * Byte: 0       1 2      3 4                 5                   m
   * OCSP:                                      [OCSP StatusRequest                   ]
   */

  /* Range check before read out the received Cert Status Type (1 Byte) */
  if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(extCertStatusTypeTlsBufferRxIdx,
        TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_TYPE_LEN, extCertStatusRequestEndIdx))
  {
    /* #10 Get the type of the received Cert Status Request. */
    uint8 receivedCertStatusType = IpBase_GetUint8(TcpIp_GetAddrTlsBufferRx(extCertStatusTypeTlsBufferRxIdx), 0u);


    /* Check request type */
    switch (receivedCertStatusType)
    {
      case TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_OCSP_TYPE:
      {
        /* #20 Check the responder id list. */

        TcpIp_TlsBufferRxIterType extResponderIdListIdx  /* start index of the responder id list */
          = extCertStatusTypeTlsBufferRxIdx + TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_TYPE_LEN;
        uint16 totalResponderIdListLen;  /* length of the responder id list, including length field */

        retVal = TcpIp_TlsServerMsg_ClientHello_CheckOcspResponderIdList(extResponderIdListIdx,
                   extCertStatusRequestEndIdx, &totalResponderIdListLen);
        if (retVal == E_OK)
        {
          TcpIp_TlsBufferRxIterType extRequestExtensionsIdx = extResponderIdListIdx + totalResponderIdListLen;

          /* #30 Check the request extensions (can be an empty element). */
          uint16 totalRequestExtensionsLen;  /* length of the request extensions, including length field */
          retVal = TcpIp_TlsServerMsg_ClientHello_CheckOcspRequestExtensions(extRequestExtensionsIdx,
                     extCertStatusRequestEndIdx, &totalRequestExtensionsLen);
          if (   (retVal == E_OK)
              && ((TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_TYPE_LEN + totalResponderIdListLen
                   + totalRequestExtensionsLen) == overallExtLength))
          {
            /* The extension is well formated. */
            /* retVal is already set to E_OK. */
          }
          else
          {
            /* Error when processing the request extensions, or there are some bytes remaining after the request
            extensions. */
            retVal = E_NOT_OK;
          }
        }
        else
        {
          /* Error when processing the responder id list */
        }
        break;
      }
      default:
      {
        /* Error, not supported status type */
        break;
      }
    }  /* switch */
  }
  else
  {
    /* Error, extension is too short for the type field. */
  }

  if (retVal != E_OK)
  {
    /* Error when processing the extension, set an alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
  }

  return retVal;
} /* TcpIp_TlsServerMsg_ClientHelloParseExtensionCertificateStatusRequest() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHello_CheckOcspResponderIdList
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
/* PRQA S 6080 1 */ /* MD_TcpIp_TlsRxLengthChecks_STMIF */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHello_CheckOcspResponderIdList(
  TcpIp_TlsBufferRxIterType ResponderIdsListStartIdx,
  TcpIp_TlsBufferRxIterType CertStatusRequestEndIdx,
  TCPIP_P2V(uint16) TotalResponderIdListLenPtr)
{
  /* Analyze OCSP Status Request responder ID list */

  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */

  /* Certificate Status request Extension Format
   *                                             +-> ResponderIdsListStartIdx: total length of all responder IDs
   *                                            /                      +-> list of OCSP responders that the client trusts (optional)
   *                                           /                      /
   *       [ext Type][ext Len][ CertStatusType][responder_id_list Len][responder_id 1]... [request_extensions]
   * Byte: 0       1 2      3               4 5                    6  7                   m
   *                                                                 [id_len][id    ]
   *                                                                  \       \-> extResponderIdContentIdx: responder id
   *                                                                   \-> extResponderIdLenTlsBufferRxIdx: responder id len
   */

  /* #10 Check the responder id list overall length. */
  /* Check that 2 bytes for the responder id list length are available */
  if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(ResponderIdsListStartIdx,
    TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_RESPONDER_ID_LIST_LEN, CertStatusRequestEndIdx))
  {
    uint16 extResponderIdListLen = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(ResponderIdsListStartIdx), 0u);              /* TCPIP_CSL_NAME_LENGTH */
    TcpIp_TlsBufferRxIterType extResponderIdLenTlsBufferRxIdx = ResponderIdsListStartIdx
      + TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_RESPONDER_ID_LIST_LEN;
    uint16 totalResponderIdListLen = TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_RESPONDER_ID_LIST_LEN;

    /* Check that the list of responder ids fits into the extension */
    if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(extResponderIdLenTlsBufferRxIdx,  /* PRQA S 2995 1 */ /* MD_TcpIp_Tls_2995 */
      extResponderIdListLen, CertStatusRequestEndIdx))
    {
      /* #20 Process the responder id list if it is not empty. */
      if (extResponderIdListLen != 0u)
      {
        uint16 remainingListLen = extResponderIdListLen;
        boolean breakLoop = FALSE;

        /* #30 Iterate over all responder ids that are contained in the list. */
        while (   (remainingListLen >= TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_RESPONDER_ID_TOTAL_MIN_LEN)
               && (breakLoop == FALSE))
        {
          /* #40 Check the length of each responder id element. */
          /* Check length of list element, minimum 2 bytes length field and 1 byte responder id */
          if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(extResponderIdLenTlsBufferRxIdx,  /* PRQA S 2995 1 */ /* MD_TcpIp_Tls_2995 */
            TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_RESPONDER_ID_TOTAL_MIN_LEN, CertStatusRequestEndIdx))
          {
            uint16 extResponderIdLen = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(extResponderIdLenTlsBufferRxIdx), 0u);

            /* Check each responder id to have a valid length (min length is 1 byte) and to fit into the responder ID
            list. */
            if (   (extResponderIdLen >= TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_RESPONDER_ID_MIN_LEN)
                && ((extResponderIdLen + TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_RESPONDER_ID_LEN_LEN)
                    <= remainingListLen))
            {
              /* OK! Responder ID has a valid format and fits into the extension. */
              /* Currently no further processing of the ID is done, only skip the ID. */
              uint16 responderIdElementLen = (TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_RESPONDER_ID_LEN_LEN
                                              + extResponderIdLen);
              remainingListLen     -= responderIdElementLen;
              extResponderIdLenTlsBufferRxIdx += (TcpIp_TlsBufferRxIterType)(responderIdElementLen);
            }
            else
            {
              /* Format error, responder id is too short or does not fit into the extension */
              breakLoop = TRUE;
            }
          }
          else
          {
            /* Format error, responder id minimum length does not fit into the extension */
            breakLoop = TRUE;
          }
        }  /* while */

        /* #50 Check the overall result of processing all responder id elements. */
        if ((breakLoop == TRUE) || (remainingListLen != 0u))
        {
          /* Error, stop processing the extension */
        }
        else
        {
          /* OK. Processing the list of responder IDs succeeded. */
          totalResponderIdListLen += extResponderIdListLen;
          *TotalResponderIdListLenPtr = totalResponderIdListLen;
          retVal = E_OK;
        }
      }
      else
      {
        /* OK. The responder id list is empty. */
        *TotalResponderIdListLenPtr = totalResponderIdListLen;
        retVal = E_OK;
      }
    }
    else
    {
      /* Format error, responder id list content does not fit into the extension */
    }
  }
  else
  {
    /* Format error, responder id list length field does not fit into the extension */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHello_CheckOcspRequestExtensions
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHello_CheckOcspRequestExtensions(
  TcpIp_TlsBufferRxIterType RequestExtStartTlsBufferRxIdx,
  TcpIp_TlsBufferRxIterType CertStatusRequestEndIdx,
  TCPIP_P2V(uint16) TotalRequestExtensionsLenPtr)
{
  /* Analyze OCSP Request Extensions */

  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */

  /* Certificate Status request Extension Format
   *                                                               +-> Request Extensions
   *                                                              /
   *       [ext Type][ext Len][CertStatusType][responder_id_list][request_extensions]
   * Byte: 0       1 2      3 4               5                  m
   *                                                             [ext_len][ext      ]
   *                                                              \        \-> extRequestExtensionsIdx: request extensions
   *                                                               \-> RequestExtStartTlsBufferRxIdx: request extensions len
   */

  /* #10 Check the request extensions overall length. */
  /* Check that 2 bytes for the request extensions length are available */
  if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(RequestExtStartTlsBufferRxIdx,
    TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_REQUEST_EXTENSIONS_LEN, CertStatusRequestEndIdx))
  {
    uint16 extRequestExtensionsLen = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(RequestExtStartTlsBufferRxIdx), 0u);
    TcpIp_TlsBufferRxIterType extRequestExtensionsIdx = RequestExtStartTlsBufferRxIdx
      + TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_REQUEST_EXTENSIONS_LEN;

    /* #20 Check that the request extensions content fits into the extension. */
    if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(extRequestExtensionsIdx,  /* PRQA S 2995 1 */ /* MD_TcpIp_Tls_2995 */
      extRequestExtensionsLen, CertStatusRequestEndIdx))
    {
      /* The content of the request extensions fits into the extension. */
      /* #30 Ignore the content of the request extensions, only their length is evaluated. */
      *TotalRequestExtensionsLenPtr = (TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_REQUEST_EXTENSIONS_LEN
                                       + extRequestExtensionsLen);
      retVal = E_OK;
    }
    else
    {
      /* Format error, request extensions content does not fit into the extension */
    }
  }
  else
  {
    /* Format error, request extensions do not fit into the extension */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloParseExtensionSupportedGroups
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050, 6080 1 */ /* MD_TcpIp_STCAL_CslAccess, MD_TcpIp_TlsStatemachine_STMIF_6080 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloParseExtensionSupportedGroups(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType SupportedGroupsExtension)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 receivedSupportedGroupsLen = 0u;
  Std_ReturnType retVal = E_NOT_OK;
  /* ----- Implementation ----------------------------------------------- */
  if(TcpIp_TlsCoreUtil_CheckLengthsOfExtensionSupportedGroups(TlsConIdx,
      SupportedGroupsExtension, &receivedSupportedGroupsLen) == E_OK)
  {
#   if (TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON)                                                                       /* COV_MSR_UNSUPPORTED */
    TcpIp_TlsCipherWorkerIterType tlsCipherWorkerIdx = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
    TcpIp_TlsCipherDefinitionIdxOfTlsCipherWorkerType tlsCipherDefinitionIdx  /* active cipher definition */
      = TcpIp_GetTlsCipherDefinitionIdxOfTlsCipherWorker(tlsCipherWorkerIdx);

    /* #10 Check that the selected cipher suite does not use PSK, otherwise ignore the extension */
    if (TcpIp_IsCipherSuiteUsePskOfTlsCipherDefinition(tlsCipherDefinitionIdx) == TRUE)
    {
      /* Ignore the extension since it is not applicable for PSK. */
      retVal = E_OK;
    }
    else
#   endif
    {
      TcpIp_TlsBufferRxIterType extGroupStartIdx
        = SupportedGroupsExtension.StartIdx + TCPIP_TLS_EXTENSION_SUPPORTED_GROUP_LENGTH_LEN;
      retVal = TcpIp_TlsServerMsg_ClientHelloCheckForMatchingSupportedGroups(TlsConIdx,
        extGroupStartIdx, receivedSupportedGroupsLen);
    }
  }

  return retVal;
} /* TcpIp_TlsServerMsg_ClientHelloParseExtensionSupportedGroups() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloCheckForMatchingSupportedGroups
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloCheckForMatchingSupportedGroups(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferRxIterType ExtGroupStartIdx,
  uint16 ReceivedSupportedGroupsLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerIterType tlsCipherWorkerIdx = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_TlsBufferRxIterType extGroupEndIdx = ExtGroupStartIdx + ReceivedSupportedGroupsLen;
  TcpIp_TlsBufferRxIterType extGroupTlsBufferRxIdx;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  if (tlsCipherWorkerIdx < TcpIp_GetSizeOfTlsCipherWorker())
  {
    /* #10 Iterate over all received supported groups and compare it to servers capabilities */
    for (extGroupTlsBufferRxIdx = ExtGroupStartIdx; extGroupTlsBufferRxIdx < extGroupEndIdx; extGroupTlsBufferRxIdx += TCPIP_CURVE_ID_LEN)
    {
      /* Get the next received supported group (named curve ID) from the list */
      TcpIp_TlsEllipticCurveIdType receivedNamedCurveId = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(extGroupTlsBufferRxIdx), 0u);

      /* #20 Check if the current named curve ID is supported by the TLS-Server */
      /* Compares this entry against the configures TcpIpTlsHandshake worker */
      if (TcpIp_TlsServerMsg_ClientHelloExtIsNamedCurveSupported(TlsConIdx, receivedNamedCurveId) == E_OK)
      {
        /* Received namedCurveId is supported by the TLS-Server - check if curve is configured for any unused handshake element. */

        /* #30 Check if there is an unused handshake in the active cipherworker which has the desired curve configured. */
        if (TcpIp_TlsServerMsg_ClientHelloExtIsCurveIdConfiguredInUnusedHandshake(TlsConIdx, tlsCipherWorkerIdx,
              receivedNamedCurveId) == TRUE)
        {
          retVal = E_OK;
        }
      }
    }

    if (retVal != E_OK)
    {
      /* #40 No suitable TcpIpTlsHandshake configured - report error and trigger TLS alert */
      /* RFC8422 - 5.1.  Client Hello Extensions (Actions of the receiver:)
       *   ... this may result in a fatal handshake failure alert due to the lack of common cipher suites. */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_HANDSHAKE_FAILURE);
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloExtIsCurveIdConfiguredInUnusedHandshake
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloExtIsCurveIdConfiguredInUnusedHandshake(
  TcpIp_TlsConnectionIterType     TlsConIdx,
  TcpIp_TlsCipherWorkerIterType   TlsCipherWorkerIdx,
  TcpIp_TlsEllipticCurveIdType    ReceivedNamedCurveId)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all handshakes and mark the handshakes with a matching supported group attribute */
  TcpIp_TlsHandshakeIndStartIdxOfTlsCipherWorkerType handshakeIndStartIdx
    = TcpIp_GetTlsHandshakeIndStartIdxOfTlsCipherWorker(TlsCipherWorkerIdx);
  TcpIp_TlsHandshakeIndEndIdxOfTlsCipherWorkerType handshakeIndEndIdx
    = TcpIp_GetTlsHandshakeIndEndIdxOfTlsCipherWorker(TlsCipherWorkerIdx);
  TcpIp_TlsHandshakeIndIterType tlsHandshakeIndIdx;

  /* Iterate over all configured handshake for this CipherWorker */
  for (tlsHandshakeIndIdx = handshakeIndStartIdx; tlsHandshakeIndIdx < handshakeIndEndIdx; tlsHandshakeIndIdx++)
  {
    /* Get the handshake index from the handshake indirection index */
    TcpIp_TlsHandshakeIterType tlsHandshakeIdx = TcpIp_GetTlsHandshakeInd(tlsHandshakeIndIdx);

    if (tlsHandshakeIdx < TcpIp_GetSizeOfTlsHandshake())
    {
      /* #20 Only proceed with handshake elements that are not yet used and with the correct curve */
      if (   (TcpIp_IsTlsHandshakeInUseOfTlsHandshakeDyn(tlsHandshakeIdx) == FALSE)
          /* Compare received and configured curve id */
          && (TcpIp_GetEllipticCurveIdOfTlsHandshake(tlsHandshakeIdx) == ReceivedNamedCurveId))
      {
        /* Find the configured handshake index corresponding to the handshake index. */
        TcpIp_TlsConfiguredHandshakeForServerConnectionIterType tlsConfiguredHandshakeForServerConnectionIdx
          = TcpIp_TlsServerMsg_GetTlsConfiguredHandshakeForServerConnectionIdx(TlsConIdx, tlsHandshakeIdx);

        /* Check if TcpIp_TlsServerMsg_GetTlsConfiguredHandshakeForServerConnectionIdx() returned a valid value /
         * the corresponding configured handshake index was found. */
        if (   tlsConfiguredHandshakeForServerConnectionIdx
             < TcpIp_GetSizeOfTlsConfiguredHandshakeForServerConnection())
        {
          /* This handshake element has the same curve id configured
           * as the currently evaluated received curve id from the ClientHello. */
          /* Set the curve flag */
          TcpIp_SetMatchesReceivedSupportedGroupsOfTlsConfiguredHandshakeForServerConnectionDyn(
            tlsConfiguredHandshakeForServerConnectionIdx, TRUE);
          retVal = TRUE;  /* at least one matching handshake was found */
        }
      }
      else
      {
        /* Go ahead. The handshake element is already used by an other connection, or the curve does not match */
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_GetTlsConfiguredHandshakeForServerConnectionIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL_INLINE FUNC(TcpIp_TlsConfiguredHandshakeForServerConnectionIterType, TCPIP_CODE) TcpIp_TlsServerMsg_GetTlsConfiguredHandshakeForServerConnectionIdx(
  TcpIp_TlsConnectionIterType      TlsConIdx,
  TcpIp_TlsHandshakeIterType       TlsHandshakeIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* Return an invalid value if a configured handshake index could not be found. */
  TcpIp_TlsConfiguredHandshakeForServerConnectionIterType configuredHandshakeForServerConnectionIdx
    = TCPIP_NO_TLSCONFIGUREDHANDSHAKEFORSERVERCONNECTIONSTARTIDXOFTLSCONNECTION;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over the configured handshakes for this TLS connection and find the passed handshake index. */
  TcpIp_TlsConfiguredHandshakeForServerConnectionIterType tlsConfiguredHandshakeForServerConnectionIterIdx
    = TcpIp_GetTlsConfiguredHandshakeForServerConnectionStartIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsConfiguredHandshakeForServerConnectionIterType tlsConfiguredHandshakeForServerConnectionEndIdx
    = TcpIp_GetTlsConfiguredHandshakeForServerConnectionEndIdxOfTlsConnection(TlsConIdx);

  for (; tlsConfiguredHandshakeForServerConnectionIterIdx < tlsConfiguredHandshakeForServerConnectionEndIdx;
         tlsConfiguredHandshakeForServerConnectionIterIdx++)
  {
    if (TcpIp_GetTlsHandshakeIdxOfTlsConfiguredHandshakeForServerConnection(
          tlsConfiguredHandshakeForServerConnectionIterIdx) == TlsHandshakeIdx)
    {
      /* One matching handshake was found */
      configuredHandshakeForServerConnectionIdx = tlsConfiguredHandshakeForServerConnectionIterIdx;
      break;
    }
  }

  return configuredHandshakeForServerConnectionIdx;
}

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloExtIsNamedCurveSupported
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloExtIsNamedCurveSupported(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 NamedCurve)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerIndIterType tlsCipherWorkerIndIdx;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all configured cipher worker for this TLS connection */
  for (tlsCipherWorkerIndIdx = TcpIp_GetTlsCipherWorkerIndStartIdxOfTlsConnection(TlsConIdx);
       tlsCipherWorkerIndIdx < TcpIp_GetTlsCipherWorkerIndEndIdxOfTlsConnection(TlsConIdx);
       tlsCipherWorkerIndIdx++)
  {
    TcpIp_TlsCipherWorkerIterType tlsCipherWorkerIdx = TcpIp_GetTlsCipherWorkerInd(tlsCipherWorkerIndIdx);

    TcpIp_TlsHandshakeIndIterType tlsHandshakeIndIdx;

    /* #20 Iterate over all configured handshake for this cipher worker */
    for (tlsHandshakeIndIdx = TcpIp_GetTlsHandshakeIndStartIdxOfTlsCipherWorker(tlsCipherWorkerIdx);
         tlsHandshakeIndIdx < TcpIp_GetTlsHandshakeIndEndIdxOfTlsCipherWorker(tlsCipherWorkerIdx);
         tlsHandshakeIndIdx++)
    {
      /* Get the configured elliptic curve ID (named curve ID) */
      TcpIp_TlsHandshakeIterType tlsHandshakeIdx = TcpIp_GetTlsHandshakeInd(tlsHandshakeIndIdx);
      TcpIp_TlsEllipticCurveIdType configuredEllipticCurveId = TcpIp_GetEllipticCurveIdOfTlsHandshake(tlsHandshakeIdx);

      /* #30 Check if the configured supported elliptic curve for this handshake worker matches with the given one */
      if (configuredEllipticCurveId == NamedCurve)
      {
        /* #40 Configured Handshake reference can support the given named curve ID - Skip all other handshake references */
        retVal = E_OK;
        break;
      }
    } /* Handshake loop */

    /* Previous handshake reference already match - Skip all other cipherWorker */
    if (retVal == E_OK)
    {
      break;
    }

  } /* CipherWorker loop */

  return retVal;
} /* TcpIp_TlsServerMsg_ClientHelloExtIsNamedCurveSupported() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloParseExtensionEcPointFormats
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
/* PRQA S 6080 1 */ /* MD_TcpIp_TlsStatemachine_STMIF_6080 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloParseExtensionEcPointFormats(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType EcPointFormatExtension)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsBufferRxIterType extEcPointFormatsLenIdx = EcPointFormatExtension.StartIdx;
  uint16 overallExtLength = EcPointFormatExtension.Length;
  TcpIp_TlsBufferRxIterType extEcPointFormatsEndIdx = extEcPointFormatsLenIdx + overallExtLength;

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* Extension index information */
  /* EC Point Format Extension Format
   *
   *
   *                             -> extEcPointFormatsLenIdx
   *                            /                               -> extEcPointFormatsStartIdx
   *                           /                               /
   *       [ext Type][ext Len][supported EC point formats len][format 1]          [format n]
   * Byte: 0       1 2      3 4                               5                   x
   *                                                           \---consumedExtensionLen---/
   */

  /* Range check before read out the received EC point formats length (1Bytes) */
  if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(extEcPointFormatsLenIdx,
    TCPIP_TLS_EXTENSION_EC_POINT_FORMATS_LENGTH_LEN, extEcPointFormatsEndIdx))
  {
    /* #10 Get the length of the received EC point formats list and check against the overall length */
    uint8 receivedEcPointFormatsLen = IpBase_GetUint8(TcpIp_GetAddrTlsBufferRx(extEcPointFormatsLenIdx), 0u);             /* TCPIP_CSL_NAME_LENGTH */

    if (overallExtLength == ((uint16)receivedEcPointFormatsLen + TCPIP_TLS_EXTENSION_EC_POINT_FORMATS_LENGTH_LEN))
    {
      TcpIp_TlsBufferRxIterType extEcPointFormatStartIdx
        = extEcPointFormatsLenIdx + TCPIP_TLS_EXTENSION_EC_POINT_FORMATS_LENGTH_LEN;

      /* #20 Check the length of the received EC point formats list for plausibility */
      /* RFC 8422 - 5.1.2.  Supported Point Formats Extension */
      if ((receivedEcPointFormatsLen >= 1u) /* List must include at least one EC point format */
        /* Range check (received list length) */
        && (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(extEcPointFormatStartIdx, receivedEcPointFormatsLen, extEcPointFormatsEndIdx)))/* PRQA S 2995 1 */ /* MD_TcpIp_Tls_2995 */
      {
        TcpIp_TlsBufferRxIterType extEcPointFormatEndIdx = extEcPointFormatStartIdx + receivedEcPointFormatsLen;
        TcpIp_TlsBufferRxIterType extEcPointFormatTlsBufferRxIdx;

        /* #30 Iterate over all received EC point formats and compare them to servers capabilities */
        for (extEcPointFormatTlsBufferRxIdx = extEcPointFormatStartIdx; extEcPointFormatTlsBufferRxIdx < extEcPointFormatEndIdx; extEcPointFormatTlsBufferRxIdx++)
        {
          /* Get the next received EC point format from the list */
          uint8 receivedEcPointFormat = IpBase_GetUint8(TcpIp_GetAddrTlsBufferRx(extEcPointFormatTlsBufferRxIdx), 0u);

          /* #40 Check if the current EC point format is supported by the TLS server */
          /* "uncompressed" is the only format supported by the server */
          if (receivedEcPointFormat == TCPIP_TLS_EXTENSION_EC_POINT_FORMAT_UNCOMPRESSED)
          {
            /* #50 Received EC point format is supported by the TLS server - Skip processing of further entries in the list and return E_OK */
            retVal = E_OK;
            break;
          }
        }

        if (retVal != E_OK)
        {
          /* #60 No suitable EC point format received - report error and trigger TLS alert */
          /* RFC8422 - 5.1.2.  Supported Point Formats Extension
           *   If the client sends the extension and the extension does not contain
           *   the uncompressed point format, ... , then the server MUST abort the handshake and
           *   return an illegal_parameter alert. */
          TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_ILLEGAL_PARAM);
        }
      }
      else
      {
        /* #70 received EC point formats length mismatch - report error and trigger TLS alert */
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
      }
    }
    else
    {
      /* #80 overall received length mismatch - report error and trigger TLS alert */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
    }
  }
  else
  {
    /* The extension it too short to contain the minimum length of 1 byte (for the extension's length field). */
  }

  return retVal;
} /* TcpIp_TlsServerMsg_ClientHelloParseExtensionEcPointFormats() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloParseExtensionSignatureAlgorithms
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
/* PRQA S 6080 1 */ /* MD_TcpIp_TlsStatemachine_STMIF_6080 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloParseExtensionSignatureAlgorithms(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType SignatureAlgorithmsExtension)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsBufferRxIterType extSignAlgoLenTlsBufferRxIdx = SignatureAlgorithmsExtension.StartIdx;
  uint16 overallExtLength = SignatureAlgorithmsExtension.Length;
  TcpIp_TlsBufferRxIterType extSignatureAlgorithmsEndIdx = extSignAlgoLenTlsBufferRxIdx + overallExtLength;

  Std_ReturnType retVal = E_NOT_OK;
  /* ----- Implementation ----------------------------------------------- */
  /* Extension index information */
  /* Signature Algorithms Extension Format
   *
   *
   *                             -> extSignAlgoLenTlsBufferRxIdx
   *                            /                         -> extSignatureAlgorithmStartIdx
   *                           /                         /
   *       [ext Type][ext Len][Signature Algorithms Len][group 1]            [group n]
   * Byte: 0       1 2      3 4                       5 6      7             (x-1)  x
   *                                                     \---consumedExtensionLen---/
   */

  /* Range check before read out the received supported groups length (2Bytes) */
  if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(extSignAlgoLenTlsBufferRxIdx,
        TCPIP_TLS_EXTENSION_SUPPORTED_GROUP_LENGTH_LEN, extSignatureAlgorithmsEndIdx))
  {
    /* #10 Get the length of the received Signature Algorithms list and check against the overall length */
    uint16 receivedSignatureAlgorithmsLen = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(extSignAlgoLenTlsBufferRxIdx), 0u);

    if (overallExtLength == (receivedSignatureAlgorithmsLen + TCPIP_TLS_SIGNATURE_ALGORITHMS_LENGTH_LEN))
    {
      TcpIp_TlsBufferRxIterType extSignatureAlgorithmStartIdx
        = extSignAlgoLenTlsBufferRxIdx + TCPIP_TLS_SIGNATURE_ALGORITHMS_LENGTH_LEN;

      /* #20 Check the length of the received Signature Algorithms list for plausibility */
      /* RFC 5246 - 7.4.1.4.1.  Signature Algorithms */
      if ( /* List must include at least one signature and hash algorithm pair */
           (receivedSignatureAlgorithmsLen >= TCPIP_TLS_SIGNATURE_ALGORITHMS_ALG_ID_LEN)
        /* and the length information is sent pairwise, so the length must be even */
        && ((receivedSignatureAlgorithmsLen % TCPIP_TLS_SIGNATURE_ALGORITHMS_ALG_ID_LEN) == 0u)
        /* Range check (received list length) */
        && (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(extSignatureAlgorithmStartIdx, receivedSignatureAlgorithmsLen,  /* PRQA S 2995 1 */ /* MD_TcpIp_Tls_2995 */
            extSignatureAlgorithmsEndIdx)))
      {
        TcpIp_TlsBufferRxIterType extSignatureAlgorithmEndIdx = extSignatureAlgorithmStartIdx + receivedSignatureAlgorithmsLen;
        TcpIp_TlsBufferRxIterType extSignAlgorTlsBufferRxIdx;

        /* #30 Iterate over all received supported groups and compare it to servers capabilities. */
        for (extSignAlgorTlsBufferRxIdx = extSignatureAlgorithmStartIdx;
             extSignAlgorTlsBufferRxIdx < extSignatureAlgorithmEndIdx;
             extSignAlgorTlsBufferRxIdx += TCPIP_TLS_SIGNATURE_ALGORITHMS_ALG_ID_LEN)
        {
          /* Get the next received Signature And Hash Algorithm ID from the list. */
          uint16 receivedSignAndHashAlgId = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(extSignAlgorTlsBufferRxIdx), 0u);
          uint8  receivedSignatureAlgorithm = IpBase_GetUint8(TcpIp_GetAddrTlsBufferRx(extSignAlgorTlsBufferRxIdx),
                   TCPIP_TLS_EXTENSION_SIGNATURE_ALGORITHMS_SIGNATURE_OFFSET);

          /* #40 Check that the received signature algorithm is not 'anonymous'. */
          if (receivedSignatureAlgorithm == TCPIP_TLS_SIGNATURE_ALGO_ANONYMOUS)
          {
            /* Error, a signature algorithm was received that is not allowed. */
            TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
            retVal = E_NOT_OK;  /* reset return value to NOT OK */
            break;  /* stop the for-loop since */
          }
          else
          {
            /* #50 Check if the current Signature Algorithm ID is supported by the TLS-Server */

            /* Compares this entry against the configured TcpIpTlsHandshake worker. */
            if (TcpIp_TlsServerMsg_ClientHelloExtIsSignAndHashAlgSupported(TlsConIdx, receivedSignAndHashAlgId) == E_OK)
            {
              /* The current Signature Algorithm ID is supported. */
              /* At least one supported Signature Algorithm ID is received. */
              retVal = E_OK;
            }
          }
        }

        if (retVal != E_OK)
        {
          /* #60 No suitable TcpIpTlsHandshake configured - report error and trigger TLS alert */
          /* RFC5246 - 7.2.2.  Error Alerts
           * ... sender was unable to negotiate an acceptable set of security parameters given the options available. */
          TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_HANDSHAKE_FAILURE);
        }
      }
      else
      {
        /* #70 Received Signature Algorithm length mismatch - report error and trigger TLS alert */
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
      }
    }
    else
    {
      /* #80 Overall received length mismatch - report error and trigger TLS alert */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
    }
  }

  return retVal;
} /* TcpIp_TlsServerMsg_ClientHelloParseExtensionSignatureAlgorithms() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloExtIsSignAndHashAlgSupported
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloExtIsSignAndHashAlgSupported(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 SignAndHashAlgId)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerIterType tlsCipherWorkerIdx = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  if (tlsCipherWorkerIdx < TcpIp_GetSizeOfTlsCipherWorker())
  {
    TcpIp_TlsHandshakeIndIterType tlsHandshakeIndIdx;
    /* #10 Iterate over all configured handshakes for this cipher worker */
    for (tlsHandshakeIndIdx = TcpIp_GetTlsHandshakeIndStartIdxOfTlsCipherWorker(tlsCipherWorkerIdx);
         tlsHandshakeIndIdx < TcpIp_GetTlsHandshakeIndEndIdxOfTlsCipherWorker(tlsCipherWorkerIdx);
         tlsHandshakeIndIdx++)
    {
      TcpIp_TlsHandshakeIterType tlsHandshakeIdx = TcpIp_GetTlsHandshakeInd(tlsHandshakeIndIdx);

      if (tlsHandshakeIdx < TcpIp_GetSizeOfTlsHandshake())
      {
        /* #20 Check if the configured supported signature and hash algorithm ID for the current handshake matches with the given one */
        if (TcpIp_TlsServerMsg_ClientHelloExtIsSignAndHashAlgSupportedByThisHandshake(TlsConIdx,
              SignAndHashAlgId, tlsHandshakeIdx) == TRUE)
        {
          retVal = E_OK;
        }
      }
    }
  }
  return retVal;
} /* TcpIp_TlsServerMsg_ClientHelloExtIsSignAndHashAlgSupported() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloExtIsSignAndHashAlgSupported
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloExtIsSignAndHashAlgSupportedByThisHandshake(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16                      SignAndHashAlgId,
  TcpIp_TlsHandshakeIterType  TlsHandshakeIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;

  TcpIp_SignatureAlgorithmIdType configuredSignatureAlgorithmId
    = TcpIp_GetSignatureAlgorithmIdOfTlsHandshake(TlsHandshakeIdx);

  /* ----- Implementation ----------------------------------------------- */
  if (configuredSignatureAlgorithmId == TCPIP_SIG_ALGO_ID_NONE)
  {
    /* If the configured signature algorithm has a NONE value, this means that
     * a PSK cipher is used. In this case no matching algorithm needs to be found
     * and at least one ciphersuite with a matching handshake exists.
     * Therefore, set the return value to TRUE. */
    retVal = TRUE;
  }
  else
  {
    /* Only check handshakes that are not yet in use */
    if (TcpIp_IsTlsHandshakeInUseOfTlsHandshakeDyn(TlsHandshakeIdx) == FALSE)
    {
      /* The current handshake is not yet used */
      /* #10 Check if the configured supported signature and hash algorithm ID for this handshake worker matches with the given one */
      if ((uint16)configuredSignatureAlgorithmId == SignAndHashAlgId)
      {
        /* Find the configured handshake index corresponding to the handshake index. */
        TcpIp_TlsConfiguredHandshakeForServerConnectionIterType tlsConfiguredHandshakeForServerConnectionIdx
          = TcpIp_TlsServerMsg_GetTlsConfiguredHandshakeForServerConnectionIdx(TlsConIdx, TlsHandshakeIdx);

        /* Check if TcpIp_TlsServerMsg_GetTlsConfiguredHandshakeForServerConnectionIdx() returned a valid value /
         * the corresponding configured handshake index was found. */
        if (   tlsConfiguredHandshakeForServerConnectionIdx
             < TcpIp_GetSizeOfTlsConfiguredHandshakeForServerConnection())
        {
          /* This handshake element has the same signature and hash algorithm id configured as the currently evaluated received algorithm id from the ClientHello. */
          /* Set the algorithm flag */
          TcpIp_SetMatchesReceivedSignatureAlgorithmsOfTlsConfiguredHandshakeForServerConnectionDyn(
            tlsConfiguredHandshakeForServerConnectionIdx, TRUE);

          retVal = TRUE; /* at least one matching handshake was found. */
        }
      }
    }
  }
  return retVal;
} /* TcpIp_TlsServerMsg_ClientHelloExtIsSignAndHashAlgSupported() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientHelloParseExtensionRecordSizeLimit
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientHelloParseExtensionRecordSizeLimit(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType RecordSizeLimitExtension)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* RFC8449 Record Size Limit Extension for TLS
  * "record_size_limit" Extension Format:
  *
  *                      +--> (fixed) Extension Length
  *                     /         +--> RlSizeLimit Start Index
  *                    /         /
  *       [ext Type] [ext Len] [RL size limit]
  * Byte: 0        1 2       3 4             5
  *
  * Record Size Limit: Maximum record size that an endpoint is willing to receive (in Bytes).
  *                    Received value effects maximum Tx record size limit
  */
  TcpIp_TlsBufferRxIterType extRecordSizeLimitEndIdx
    = RecordSizeLimitExtension.StartIdx + RecordSizeLimitExtension.Length;

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Compare the received length of the extension with the expected one (2 Byte fixed value) */
  if (RecordSizeLimitExtension.Length == TCPIP_TLS_EXTENSION_RECORD_SIZE_LIMIT_VALUE_LEN)
  {
    /* Check if we received enough byte to read out the value (2 bytes) */
    if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(RecordSizeLimitExtension.StartIdx,                                              /* PRQA S 2995 2 */ /* MD_TcpIp_Tls_2995 */
          TCPIP_TLS_EXTENSION_RECORD_SIZE_LIMIT_FIXED_LEN, extRecordSizeLimitEndIdx))
    {
      /* Get the offered value from the TLS-Client */
      uint16 receivedRecordSizeLimit = IpBase_GetUint16(
        TcpIp_GetAddrTlsBufferRx(RecordSizeLimitExtension.StartIdx), 0u);

      /* #20 Compare the received record size limit with the minimum defined value (64 Bytes) */
      if (receivedRecordSizeLimit >= TCPIP_TLS_EXTENSION_RECORD_SIZE_LIMIT_MIN_VALUE)
      {
        /* #30 Compare the received record size limit with the maximum defined value (2^14 Bytes) */
        if (receivedRecordSizeLimit <= TCPIP_TLS_EXTENSION_RECORD_SIZE_LIMIT_MAX_VALUE)
        {

          /* #40 Extension successfully received - Update Tx information and return E_OK */
          TcpIp_SetTxRecordSizeLimitOfTlsConnectionDyn(TlsConIdx, receivedRecordSizeLimit);

          /* Set Flag which is used to reply to this extension within the ServerHello message */
          TcpIp_SetExtensionRecordSizeLimitReceivedOfTlsConnectionDyn(TlsConIdx, TRUE);

          retVal = E_OK;
        }
        else
        {
          /* #50 Client offers more than 2^14 bytes - Set Tx information to maximum supported value */
          /* RFC8449 - 4.  The "record_size_limit" Extension
           *   For TLS 1.2 and earlier, that limit is 2^14 octets.  TLS 1.3 uses a limit of
           *   2 ^ 14 + 1 octets.Higher values are currently reserved for future
           *   versions of the protocol that may allow larger records; an endpoint
           *   MUST NOT send a value higher than the protocol - defined maximum record
           *   size unless explicitly allowed by such a future version or extension.
           *   A server MUST NOT enforce this restriction; a client might advertise
           *   a higher limit that is enabled by an extension or version the server
           *   does not understand.
           */

          /* Set TX limit to maximum supported value (2^14) */
          TcpIp_SetTxRecordSizeLimitOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_EXTENSION_RECORD_SIZE_LIMIT_MAX_VALUE);

          /* Set Flag which is used to reply to this extension within the ServerHello message */
          TcpIp_SetExtensionRecordSizeLimitReceivedOfTlsConnectionDyn(TlsConIdx, TRUE);

          retVal = E_OK;
        }
      }
      else
      {
        /* #60 Lower record size limit value mismatch - trigger TLS alert */
        /* RFC8449 - 4.  The "record_size_limit" Extension
         *    Endpoints MUST NOT send a "record_size_limit" extension with a value
         *    smaller than 64.  An endpoint MUST treat receipt of a smaller value
         *    as a fatal error and generate an "illegal_parameter" alert.
         */
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_ILLEGAL_PARAM);
      }
    }
    else
    {
      /* #70 Received record size limit length mismatch - trigger TLS alert */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
    }
  }
  else
  {
    /* #80 Received record size limit length mismatch - trigger TLS alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
  }

  return retVal;
} /* TcpIp_TlsServerMsg_ClientHelloParseExtensionRecordSizeLimit() */
#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientKeyExchangeGetClientParams
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
/* PRQA S 6050, 6080 1 */ /* MD_TcpIp_STCAL_CslAccess, MD_MSR_STMIF */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientKeyExchangeGetClientParams(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtDynIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

  TcpIp_TlsBufferRxClientKeyExchangeIdxOfTlsServerBufferMgmtType clientKeyExchangeStartIdx
    = TcpIp_GetTlsBufferRxClientKeyExchangeIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

  TcpIp_TlsEllipticCurveIdType activeCurveId = TcpIp_GetEllipticCurveIdOfTlsHandshake(activeTlsHandshakeIdx);
  /* Length of the received Client KeyExchange  message */
  TcpIp_ClientHelloLenOfTlsServerBufferMgmtType clientKeyExchangeLen
    = TcpIp_GetClientKeyExchangeLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

  /* End index of the received ClientHello message - Need for in range checks inside the parser */
  CONST(TcpIp_TlsBufferRxClientHelloIdxOfTlsServerBufferMgmtType, AUTOMATIC) clientKeyExchangeEndIdx
    = clientKeyExchangeStartIdx + TCPIP_TLS_HSHDRLEN + clientKeyExchangeLen;

  CONST(uint8, AUTOMATIC) expectedPublicKeyLen =
    ( TcpIp_TlsMsg_GetLenOfCurveSpecificPubKey(activeCurveId) + TcpIp_TlsServerMsg_GetLenOfPubKeyCompression(activeCurveId) );

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Compare the received public key with the expected length */
  /* Get the length of the received public key */
  if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx),
        TCPIP_TLSSERVER_PUPKEYLEN_LEN, clientKeyExchangeEndIdx))
  {
    uint8 receivedClientPublicKeyLen = IpBase_GetUint8(TcpIp_GetAddrTlsBufferRx(
      TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx)), 0u);

    /* Check the length of the received public key */
    if (expectedPublicKeyLen == receivedClientPublicKeyLen)
    {
      /* #20 Received public key length match - Range check */
      if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx),       /* PRQA S 2995 2 */ /* MD_TcpIp_Tls_2995 */
           ((TcpIp_TlsBufferRxIterType)((TcpIp_TlsBufferRxIterType)receivedClientPublicKeyLen + TCPIP_TLSSERVER_PUPKEYLEN_LEN)), clientKeyExchangeEndIdx))
      {
        uint8 clientPublicCompFlagLen = TcpIp_TlsServerMsg_GetLenOfPubKeyCompression(activeCurveId);

        if ((receivedClientPublicKeyLen - clientPublicCompFlagLen) == TcpIp_TlsMsg_GetLenOfCurveSpecificPubKey(activeCurveId))
        {
          /* #30 set Len indirection only if length is valid  */
          TcpIp_SetTlsBufferRxClientKeyExchangePubKeyLenIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx,
            TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx));

          /* Maintain AdHs read index by incrementing the consumed length */
          TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx,
            TCPIP_TLSSERVER_PUPKEYLEN_LEN);

          /* #40 Check if the public key is compressed and compare the received compression flag with the expected one */
          if (TcpIp_TlsCoreUtil_CheckPublicKeyCompressionFlagOfEllipticCurve(activeCurveId) == TRUE)
          {
            /* compressed public key format (SECP256) */
            /* Get the compression flag of the received public key */
            uint8 receivedClientCompressionFlag = IpBase_GetUint8(
              TcpIp_GetAddrTlsBufferRx(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx)), 0u);

            /* Maintain AdHs read index by incrementing the consumed length */
            TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx,
              TCPIP_TLSSERVER_PUPKEY_COMPRESSION_FLAG_LEN);

            /* Only supported compression flag is 0x04 */
            if (receivedClientCompressionFlag == TCPIP_TLSSERVER_PUPKEY_COMPRESSION_FLAG)
            {
              /* #50 Valid (compressed) public key received - Store the index to the start of the public key and return E_OK */
              TcpIp_SetTlsBufferRxClientKeyExchangePubKeyIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx,
                TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx));

              /* Maintain AdHs read index by incrementing the consumed length */
              TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx,
                ((TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType)receivedClientPublicKeyLen - TCPIP_TLSSERVER_PUPKEY_COMPRESSION_FLAG_LEN));

              retVal = E_OK;
            }
          }
          else
          {
            /* else - uncompressed public key format (ED25519) */
            /* #60 Valid (uncompressed) public key received - Store the index to the start of the public key and return E_OK */
            TcpIp_SetTlsBufferRxClientKeyExchangePubKeyIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx,
              TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx));

            /* Maintain AdHs read index by incrementing the consumed length */
            TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtDynIdx, receivedClientPublicKeyLen);

            retVal = E_OK;
          }
        } /* else - Received key length does not meet expectations. E_NOT_OK */
      } /* else - Range check failed. E_NOT_OK */
    } /* else - Length mismatch. E_NOT_OK */
  } /* else - Range check failed. E_NOT_OK */

  if (retVal != E_OK)
  {
    /* Parsing of received public key failed - Report error to user and trigger TLS alert */
    TcpIp_TlsUserErrorType UserError;
    UserError.FunctionId  = TCPIP_TLS_FCTID_CLIENT_HSSTM_PARSE_CLIENTKEYEXCHANGE;
    UserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_INCORRECTPUBKEYLEN;
    UserError.TlsConId    = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(UserError);

    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
  }

  return retVal;
} /* TcpIp_TlsServerMsg_ClientKeyExchangeGetClientParams() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientKeyExchangeCalcSharedSecret
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ClientKeyExchangeCalcSharedSecret(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Handles synchronous CSM call and trigger the calculation of the job in the async context handler */
  TcpIp_SetDhSharedSecretAsyncFlagOfTlsConnectionDyn(TlsConIdx, TRUE);

  /* Set the TLS connection state to ASYNC_PENDING */
  TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_ASYNC_PENDING);

} /* TcpIp_TlsServerMsg_ClientKeyExchangeCalcSharedSecret() */
#   endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */
#   if (TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_IsPskIdentityLengthValid
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsServerMsg_IsPskIdentityLengthValid(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 ClientPskIdentityLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxClientKeyExchangeIdxOfTlsServerBufferMgmtType clientKeyExchangeStartIdx
    = TcpIp_GetTlsBufferRxClientKeyExchangeIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

  /* Length of the received ClientKeyExchange message */
  TcpIp_ClientHelloLenOfTlsServerBufferMgmtType clientKeyExchangeLen
    = TcpIp_GetClientKeyExchangeLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

  /* End index of the received ClientKeyExchange message - Needed for in range checks inside the parser */
  CONST(TcpIp_TlsBufferRxClientHelloIdxOfTlsServerBufferMgmtType, AUTOMATIC) clientKeyExchangeEndIdx
    = clientKeyExchangeStartIdx + TCPIP_TLS_HSHDRLEN + clientKeyExchangeLen;

  boolean retVal = FALSE;
  /* ----- Implementation ----------------------------------------------- */
  if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx),
    TCPIP_TLS_KEYEXCH_PSKIDLEN, clientKeyExchangeEndIdx))
  {
    /* Maintain AdHs read index by incrementing the consumed length */
    TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_KEYEXCH_PSKIDLEN);

    /* #10 Compare the received PSK identity length and check the range */
    if (   (ClientPskIdentityLen <= TCPIP_TLS_KEYEXCH_PSKIDMAXLEN)
        && ( (TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx) + ClientPskIdentityLen)
               == clientKeyExchangeEndIdx))
    {
      retVal = TRUE;
    }
  }
  return retVal;
} /* TcpIp_TlsServerMsg_IsPskIdentityLengthValid */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ComparePskIdentities
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ComparePskIdentities(
  TcpIp_TlsPskIdentityIterType                        TlsPskIdentityIdx,
  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType  ReceivedClientPskIdentityStartIdx,
  uint16                                              ReceivedClientPskIdentityLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_PskIdentityPtrType pskIdentityPtr
    = TcpIp_GetAddrPskIdentity(TcpIp_GetPskIdentityStartIdxOfTlsPskIdentity(TlsPskIdentityIdx));

  TcpIp_PskIdentityLengthOfTlsPskIdentityType pskIdentityLength
    = TcpIp_GetPskIdentityLengthOfTlsPskIdentity(TlsPskIdentityIdx);

  Std_ReturnType retVal = E_NOT_OK;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Compare the two string lengths */
  if (ReceivedClientPskIdentityLen == pskIdentityLength)
  {
    /* #20 Compare the strings character by character */
    if (VStdLib_MemCmp(pskIdentityPtr, TcpIp_GetAddrTlsBufferRx(ReceivedClientPskIdentityStartIdx),                     /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* TCPIP_CSL_NAME_LENGTH */
      ReceivedClientPskIdentityLen) == VSTDLIB_MEM_CMP_RES_EQ)
    {
      retVal = E_OK;
    }
  }
  return retVal;
} /* TcpIp_TlsServerMsg_ComparePskIdentities */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientKeyExchangeGetPskParams
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ClientKeyExchangeGetPskParams(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsPskIdentityIndStartIdxOfTlsConnectionType tlsPskIdentityIndStartIdx
    = TcpIp_GetTlsPskIdentityIndStartIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsPskIdentityIndEndIdxOfTlsConnectionType tlsPskIdentityIndEndIdx
    = TcpIp_GetTlsPskIdentityIndEndIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsPskIdentityIndIterType tlsPskIdentityIndIdx;

  boolean  matchingPskIdentityFound = FALSE;

  Std_ReturnType retVal = E_NOT_OK;
  /* ----- Implementation ----------------------------------------------- */
  /* Get the length of the received PSK identity.
   * The AdHs read index is incremented after the length has been checked for validity. */
  uint16 clientPskIdentityLen = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(
    TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)), 0);

  /* #10 Check if the received PSK identity length is valid */
  if (TcpIp_TlsServerMsg_IsPskIdentityLengthValid(TlsConIdx, clientPskIdentityLen) == TRUE)
  {
    /* #20 Get the received PSK identity string from the TLS RxBuffer */
    TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType receivedClientPskIdentityStartIdx
      = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

    /* Maintain AdHs read index by incrementing the consumed length */
    TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, clientPskIdentityLen);

    /* #30 Iterate over all configured PSK Identities and compare the received PSK Identity with the configured one */
    for (tlsPskIdentityIndIdx = tlsPskIdentityIndStartIdx;
         tlsPskIdentityIndIdx < tlsPskIdentityIndEndIdx;
         tlsPskIdentityIndIdx++)
    {
      TcpIp_TlsPskIdentityIterType tlsPskIdentityIdx
        = TcpIp_GetTlsPskIdentityInd(tlsPskIdentityIndIdx);

      if (TcpIp_TlsServerMsg_ComparePskIdentities(tlsPskIdentityIdx, receivedClientPskIdentityStartIdx, clientPskIdentityLen) == E_OK)
      {
        /* #40 If a match is found, mark this PSK identity as active for the current TLS connection */
        TcpIp_SetTlsPskIdentityActiveIdxOfTlsConnectionDyn(TlsConIdx,
          (TcpIp_TlsPskIdentityActiveIdxOfTlsConnectionDynType) tlsPskIdentityIdx);

        matchingPskIdentityFound = TRUE;
        /* Skip further processing of other PSK identities */
        break;
      } /* else - If the strings do not match discard the current PSK and continue with the next in list */
    }
    if (matchingPskIdentityFound == FALSE)
    {
      /* #50  In case of no matching PSK identity, trigger alert */
      TcpIp_TlsAlertLevelType alertLevel = TCPIP_TLS_ALERT_LEVEL_FATAL;
      TcpIp_TlsAlertDescriptionType alertDescription = TCPIP_TLS_ALERT_DESC_DECRYPT_ERROR;
      TcpIp_TlsCoreAlert_Set(TlsConIdx, alertLevel, alertDescription);
    }

    /* Because the alert is set inside this function when no matching PSK identity is found,
     * no error handling outside the function is necessary.
     * So matching PSK identity or not, return E_OK.
     * E_NOT_OK is reserved for an invalid length. */

    retVal = E_OK;

  } /* else - PSK identity length is invalid, return E_NOT_OK */
  return retVal;
} /* TcpIp_TlsServerMsg_ClientKeyExchangeGetPskParams */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientKeyExchangeCalcPskPremasterSecret
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ClientKeyExchangeCalcPskPremasterSecret(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Handles synchronous CSM call and trigger the calculation of the job in the async context handler */
  TcpIp_SetPskPremasterSecretAsyncFlagOfTlsConnectionDyn(TlsConIdx, TRUE);

  /* Set the TLS connection state to ASYNC_PENDING */
  TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_ASYNC_PENDING);

} /* TcpIp_TlsServerMsg_ClientKeyExchangeCalcPskPremasterSecret */

#   endif /* TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON */
/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ClientKeyExchangeCalcMasterSecret
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ClientKeyExchangeCalcMasterSecret(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Handles synchronous CSM call and trigger the calculation of the job in the async context handler */
  TcpIp_SetCalcMasterSecretAsyncFlagOfTlsConnectionDyn(TlsConIdx, TRUE);

  /* Set the TLS connection state to ASYNC_PENDING */
  TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_ASYNC_PENDING);

} /* TcpIp_TlsServerMsg_ClientKeyExchangeCalcMasterSecret() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_SelectMatchingCipher
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_SelectMatchingCipherWorker(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint16, AUTOMATIC) CipherSuiteLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all configured cipherWorker and get the configured cipher suite ID */
  TcpIp_TlsCipherWorkerIndIterType tlsCipherWorkerIndIdx;
  for (tlsCipherWorkerIndIdx = TcpIp_GetTlsCipherWorkerIndStartIdxOfTlsConnection(TlsConIdx);
       tlsCipherWorkerIndIdx < TcpIp_GetTlsCipherWorkerIndEndIdxOfTlsConnection(TlsConIdx);
       tlsCipherWorkerIndIdx++)
  {
    TcpIp_TlsCipherWorkerIndType tlsCipherWorkerIdx = TcpIp_GetTlsCipherWorkerInd(tlsCipherWorkerIndIdx);

    /* Get the index of the current CipherDefiniton */
    TcpIp_TlsCipherDefinitionIdxOfTlsCipherWorkerType tlsCipherDefinitionIdx
      = TcpIp_GetTlsCipherDefinitionIdxOfTlsCipherWorker(tlsCipherWorkerIdx);

    /* Get the corresponding CipherId (HexCode) */
    TcpIp_CipherSuiteIdOfTlsCipherDefinitionType cipherSuiteId
      = TcpIp_GetCipherSuiteIdOfTlsCipherDefinition(tlsCipherDefinitionIdx);

    /* #20 Iterate over received cipher list from the TLS-Client and compare it to the current configured cipher suite ID */
    if (TcpIp_TlsServerMsg_SearchCipherListForMatchingCipherSuite(
         TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx), CipherSuiteLen, cipherSuiteId) == E_OK)
    {
      /* #30 Found a matching cipher between TLS-Server and TLS-Client - Mark this cipher worker as active and return E_OK */
      TcpIp_SetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx, tlsCipherWorkerIdx);


      retVal = E_OK;

      /* Skip further processing of other cipher worker */
      break;
    } /* else - No matching cipher worker found. E_NOT_OK */
  }

  if (retVal != E_OK)
  {
    /* #40 No matching cipher worker found - Report an error to the user and trigger TLS alert */
    TcpIp_TlsUserErrorType UserError;
    UserError.FunctionId  = TCPIP_TLS_FCTID_SERVER_HSSTM_PARSE_CLIENTHELLO;
    UserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_NOMATCHINGCIPHER;
    UserError.TlsConId    = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(UserError);

    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INSUF_SEC);
    retVal = E_NOT_OK;
  }

  return retVal;
} /* TcpIp_TlsServerMsg_SelectMatchingCipher() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_SearchCipherListForMatchingCipherSuite
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_SearchCipherListForMatchingCipherSuite(
  TcpIp_TlsBufferRxClientHelloIdxOfTlsServerBufferMgmtType CipherListStartIdx,
  CONST(uint16, AUTOMATIC) CipherListLen,
  CONST(TcpIp_TlsCipherDataType, AUTOMATIC) CipherSuitePattern)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsBufferRxClientHelloIdxOfTlsServerBufferMgmtType cipherListStartIdTlsBufferRxIdx = CipherListStartIdx;
  TcpIp_TlsBufferRxClientHelloIdxOfTlsServerBufferMgmtType cipherListEndIdx = CipherListStartIdx + CipherListLen;

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 iterate over the complete received Client cipher suite list */
  /* Each cipher suite contains two Byte, so increment by 2 */
  for (; cipherListStartIdTlsBufferRxIdx < cipherListEndIdx; cipherListStartIdTlsBufferRxIdx += TCPIP_TLS_CIPHERSUITEID_LEN)
  {
    /* #20 get the cipher suite id from the list */
    uint16 clientCipherSuite = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(cipherListStartIdTlsBufferRxIdx), 0u);

    /* #30 compare if this cipher suite matches with the server side */
    if (clientCipherSuite == CipherSuitePattern)
    {
      /* #40 matching cipher, break the loop at this point */
      retVal = E_OK;
      break;
    }
  }

  return retVal;
} /* TcpIp_TlsServerMsg_SearchCipherListForMatchingCipherSuite() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_PrepareServerHello
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
/* PRQA S 6050 1 */ /* MD_TcpIp_TlsStatemachine_STCAL_6050 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_PrepareServerHello(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType txAdHsWriteIdx
    = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  TcpIp_TlsBufferTxServerHelloIdxOfTlsServerBufferMgmtType tlsBufferTxServerHelloIdx;

  uint32 serverHelloLen;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* Store the start index of this message to the current write index - used to add the length information after the data is added */
  TcpIp_SetTlsBufferTxServerHelloIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, txAdHsWriteIdx);

  /* #10 ServerHello message - Add generic TLS handshake header type */
  TcpIp_TlsMsg_AddHsHdr(TlsConIdx, TCPIP_TLS_HSTYPE_SERVERHELLO);

  /* #20 ServerHello message - Add generic supported protocol version */
  TcpIp_TlsHelloMsg_AddProtocolVersionNr(TlsConIdx);

  /* #30 ServerHello message - Add random structure */
  retVal = TcpIp_TlsHelloMsg_AddRandomStructure(TlsConIdx);

  if (retVal == E_OK)
  {
    /* #40 ServerHello message - Add TLS session ID */
    retVal = TcpIp_TlsHelloMsg_AddSessionId(TlsConIdx);
  }

  if (retVal == E_OK)
  {
    /* #50 ServerHello message - Add selected cipher suite */
    retVal = TcpIp_TlsServerMsg_ServerHelloAddSelectedCipher(TlsConIdx);
  }

  if (retVal == E_OK)
  {
    /* #60 ServerHello message - Add supported compression method */
    TcpIp_TlsServerMsg_ServerHelloAddCompressionMethod(TlsConIdx);

    /* #70 ServerHello message - Add supported extensions */
    TcpIp_TlsServerMsg_ServerHelloAddServerExtensions(TlsConIdx);

    /* #80 ServerHello message - Update the overall length information in the TLS handshake header */
    txAdHsWriteIdx = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
    tlsBufferTxServerHelloIdx = TcpIp_GetTlsBufferTxServerHelloIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

    /* Write the length information into the HS Header: Message length = WriteIdx - ServerHelloStartIdx */
    serverHelloLen = ((uint32)txAdHsWriteIdx - tlsBufferTxServerHelloIdx);

    TcpIp_SetServerHelloLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, (uint16)serverHelloLen);

    TcpIp_TlsMsg_AddLenToHsHdr(tlsBufferTxServerHelloIdx, (serverHelloLen - TCPIP_TLS_HSHDRLEN));

#   if ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON))
    /* #90 in case of enabled Master Secret Access, copy the generated Session ID to the access buffer */
    TcpIp_TlsServerMsa_AddServerSessionIdToAccessBuffer(TlsConIdx);
#   endif
  }

  return retVal;
} /* TcpIp_TlsServerMsg_PrepareServerHello() */

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_AddCertificateRequestCertTypes
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_AddCertificateRequestCertTypes(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType certTypeTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TCPIP_P2V(uint8) txBufferPtr = TcpIp_GetAddrTlsBufferTx(certTypeTlsBufferTxIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Write the total number of certificate types */
  /* Only ECDSA is supported */
  IpBase_PutUint8(txBufferPtr, 0u, TCPIP_TLS_CERTREQUEST_CERTTYPES_AMOUNT);
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_CERTREQUEST_CERTTYPESLENGTH_LEN);

  /* #20 Write the certificate type list */
  IpBase_PutUint8(txBufferPtr, TCPIP_TLS_CERTREQUEST_CERTTYPESLENGTH_LEN, TCPIP_TLS_CERTREQUEST_ECDSA_TYPE);
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_CERTREQUEST_CERTTYPES_AMOUNT*TCPIP_TLS_CERTREQUEST_CERTTYPE_LEN);
}

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_AddCertificateRequestSignatureHashAlgos
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_AddCertificateRequestSignatureHashAlgos(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType sigAlgoListTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_TlsHandshakeIndIterType tlsHandshakeIndIdx = 0u;
  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  uint16 length = 0u;
  TcpIp_SignatureAlgorithmIdType algo = TCPIP_SIG_ALGO_ID_NONE;

  /* ----- Implementation ----------------------------------------------- */
  /* Save the start index of this list for later use when parsing the client certificate message. */
  TcpIp_SetTlsBufferTxCertificateRequestSignatureAndHashAlgorithmListIdxOfTlsServerBufferMgmt(                          /* TCPIP_CSL_MISSDETECTION */
    TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx), sigAlgoListTlsBufferTxIdx);

  /* #10 Write the signature algorithm list */
  for (tlsHandshakeIndIdx = TcpIp_GetTlsHandshakeIndStartIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx);
       tlsHandshakeIndIdx < TcpIp_GetTlsHandshakeIndEndIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx);
       tlsHandshakeIndIdx++)
  {
    TcpIp_TlsHandshakeIterType tlsHandshakeIdx = TcpIp_GetTlsHandshakeInd(tlsHandshakeIndIdx);
    if (tlsHandshakeIdx < TcpIp_GetSizeOfTlsHandshake())
    {
      algo = TcpIp_GetSignatureAlgorithmIdOfTlsHandshake(tlsHandshakeIdx);

      /* #20 Add algorithm if not already contained */
      /* Two byte are kept free for the length information */
      if (algo != TCPIP_SIG_ALGO_ID_NONE)
      {
        TcpIp_TlsMsg_AddUint16ValueToDistinctListInTxBuffer(
          TlsConIdx,
          (uint16) algo,
          sigAlgoListTlsBufferTxIdx + TCPIP_TLS_SIGNATURE_ALGORITHMS_LENGTH_LEN,
          &length);
      }
    }
  }

  /* #30 Write the total number of signature hash algorithms */
  IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(sigAlgoListTlsBufferTxIdx), 0u, length);

  /* #40 Increment the write index by the length of the signature algorithms length field */
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(
    tlsBufferMgmtIdx,
    TCPIP_TLS_SIGNATURE_ALGORITHMS_LENGTH_LEN);
}

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_AddCertificateRequestDistNames
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_AddCertificateRequestDistNames(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType distNamesTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TCPIP_P2V(uint8) txBufferPtr = TcpIp_GetAddrTlsBufferTx(distNamesTlsBufferTxIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Write the total number of distinguished names */
  IpBase_PutUint16(txBufferPtr, 0u, TCPIP_TLS_CERTREQUEST_DISTINGUISHEDNAME_AMOUNT);
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_DIST_NAMES_LENGTH_LEN);

  /* #20 Write the distinguished names */
  /* Distinguished names list is empty at the moment. */
}

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_PrepareCertificateRequest
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_PrepareCertificateRequest(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);
  uint16 msgLen = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* Store the start index of this message to the current write index - used to add the length information after the data is added */
  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType certRequestStartIdx = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_SetTlsBufferTxCertificateRequestIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, certRequestStartIdx);

  /* #10 CertificateRequest message - Add generic TLS handshake header type */
  TcpIp_TlsMsg_AddHsHdr(TlsConIdx, TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST);

  /* #20 CertificateRequest message - Add certificate types */
  TcpIp_TlsServerMsg_AddCertificateRequestCertTypes(TlsConIdx);

  /* #30 CertificateRequest message - Add supported signature and hash algorithms */
  TcpIp_TlsServerMsg_AddCertificateRequestSignatureHashAlgos(TlsConIdx);

  /* #40 CertificateRequest message - Add distinguished names */
  TcpIp_TlsServerMsg_AddCertificateRequestDistNames(TlsConIdx);

  /* #50 Write the length information into the HS Header. */
  msgLen = (uint16)(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)
                    - certRequestStartIdx);
  TcpIp_TlsMsg_AddLenToHsHdr(certRequestStartIdx, (uint32) msgLen - TCPIP_TLS_HSHDRLEN);
  TcpIp_SetCertificateRequestLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, msgLen);

} /* TcpIp_TlsServerMsg_PrepareCertificateRequest */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_PrepareServerCertificates
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_PrepareServerCertificates(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx           = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType txAdHsWriteIdx
    = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* Store the start index of this message to the current write index - used to add the length information after the data is added */
  TcpIp_SetTlsBufferTxServerCertificatesIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, txAdHsWriteIdx);

  /* #10 ServerCertificate message - Add generic TLS handshake header type */
  TcpIp_TlsMsg_AddHsHdr(TlsConIdx, TCPIP_TLS_HSTYPE_CERTIFICATE);

  /* #20 ServerCertificate message - Add installed Server certificates */
  retVal = TcpIp_TlsServerMsg_ServerCertificateAddServerCertificates(TlsConIdx);

  if (retVal == E_OK)
  {
    uint32 serverCertificateLen;
    TcpIp_TlsBufferTxServerCertificatesIdxOfTlsServerBufferMgmtType serverCertIdx
      = TcpIp_GetTlsBufferTxServerCertificatesIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

    txAdHsWriteIdx = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
    /* #30 ServerCertificate message - Update the overall length information in the TLS handshake header */
    serverCertificateLen = ((uint32)txAdHsWriteIdx - serverCertIdx);

    TcpIp_SetServerCertificatesLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, (uint16)serverCertificateLen);

    TcpIp_TlsMsg_AddLenToHsHdr(serverCertIdx, (serverCertificateLen - TCPIP_TLS_HSHDRLEN));
  }

  return retVal;
} /* TcpIp_TlsServerMsg_PrepareServerCertificates() */
#   endif
/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_PrepareServerKeyExchange
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_PrepareServerKeyExchange(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Prepare the ServerKeyExchange message until we are done AND no Async context needs to be computed */
  while (   (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx)  != TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_DONE)    /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
             /* Async operation is trigged (performed in lowPrio task) - leave this context */
         && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_ASYNC_PENDING)
             /* Error during processing of the data - skip further data handling */
         && (retVal == E_OK))                                                                                           /* PRQA S 2991, 2995 */ /* MD_TCPIP_Rule14.3_2741_2742_2991_2992_2995_2996 */
  {
    /* Processing of sub states for ServerKeyExchange message */
    switch (TCPIP_TLS_GET_HS_SUB_STATE(TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx)))
    {
      case TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE:
      {
        TcpIp_TlsKeyExchangeMethodDataType keyExchangeMethod
          = TcpIp_TlsCoreUtil_ReturnActiveCipherSpecificKeyExchangeMethod(TlsConIdx);

        /* Store the start index of this message to the current write index - used to add the length information after the data is added */
        TcpIp_SetTlsBufferTxServerKeyExchangeIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx,
          TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

        /* #20 ServerKeyExchange message - Add generic TLS handshake header type */
        TcpIp_TlsMsg_AddHsHdr(TlsConIdx, TCPIP_TLS_HSTYPE_SERVERKEYEXCHANGE);

        /* Calculate next state, depending on the selected key exchange */
        switch (keyExchangeMethod)
        {
#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
          case TCPIP_TLS_KEYEXCHANGE_METHOD_ECDHE:
          {
            /* ECC based key exchange - next state: Add ECC parameter */
            TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx,
              TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_ADD_ECDHE_PARAMS);
            break;
          }
#   endif
#   if (TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON)
          case TCPIP_TLS_KEYEXCHANGE_METHOD_PSK_PLAIN:
          {
            /* PSK based key exchange - next state: Add PSK parameter */
            TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx,
              TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_ADD_PSK_PARAMS);
            break;
          }
#   endif
          default:
          {
            /* Invalid key exchange method. This can never happen, a valid key exchange method has been chosen with the
            active cipher suite selected after receiving the client_hello message. */
            break;
          }
        }  /* switch (keyExchangeMethod) */

        break;
      } /* case  TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_ADD_HDR */
#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
      case TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_ADD_ECDHE_PARAMS:
      {
        /* #30 ServerKeyExchange message - Add ECDH(E) parameter */
        TcpIp_TlsServerMsg_ServerKeyExchangeAddEcdheParams(TlsConIdx);
        /* This operation is processed within the lowPrio function, which means that we are leaving
           this context and return when the operation is DONE */
        break;
      }
#   endif
#   if (TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON)
      case TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_ADD_PSK_PARAMS:
      {
        /* #40 ServerKeyExchange message - Add PSK parameter */
        retVal = TcpIp_TlsServerMsg_ServerKeyExchangeAddPskParams(TlsConIdx);
        /* This operation is processed within the lowPrio function, which means that we are leaving
           this context and return when the operation is DONE */
        break;
      }
#   endif
      case TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_TRIGGER_TX:
      {
        /* #50 ServerKeyExchange message - Update the overall length information in the TLS handshake header */
        TcpIp_TlsBufferTxServerKeyExchangeIdxOfTlsServerBufferMgmtType serverKeyExchangeIdx
          = TcpIp_GetTlsBufferTxServerKeyExchangeIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

        uint32 serverKeyExchangeLen = ((uint32)TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)
          - serverKeyExchangeIdx);

        TcpIp_SetServerKeyExchangeLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, (uint16)serverKeyExchangeLen);
        TcpIp_TlsMsg_AddLenToHsHdr(serverKeyExchangeIdx, (serverKeyExchangeLen - TCPIP_TLS_HSHDRLEN));

        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_DONE);
        break;
      }

      default:                                                                                                         /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
      {
        /* Default case left blank intentionally */
        TCPIP_ASSERT_UNREACHABLE();
        break;
      }

    } /* switch () */
  } /* while () */

  return retVal;
} /* TcpIp_TlsServerMsg_PrepareServerKeyExchange() */

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ServerKeyExchangeAddEcdheParams
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_TlsStatemachine_STCAL_6050 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ServerKeyExchangeAddEcdheParams(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Prepare the ServerKeyExchange ECDHE parameter until we are done AND no Async context needs to be computed */
  while (   (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_TRIGGER_TX)/* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
             /* Async operation is trigged (performed in lowPrio task) - leave this context */
         && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_ASYNC_PENDING))
  {

    switch (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx))
    {
      case TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_ADD_ECDHE_PARAMS:
      case TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_ADD_ECDHE_PARAMS_ADD_DH:
      {
        /* #20 ServerKeyExchange message (ECDHE part) - Add Diffie Hellman parameter and trigger ephemeral key calculation */
        TcpIp_TlsServerMsg_ServerKeyExchangeAddDiffieHellmanParams(TlsConIdx);
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx,
          TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_ADD_ECDHE_PARAMS_ADD_SIGNATURE);
        /* This operation is processed within the lowPrio function, which means that we are leaving
           this context and return when the operation is DONE */
        break;
      }

      case TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_ADD_ECDHE_PARAMS_ADD_SIGNATURE:
      {
        /* #30 ServerKeyExchange message (ECDHE part) - Add Signature parameter and trigger signature calculation */
        if(TCPIP_TLS_HS_CHECK_BUFFER_IDX(TlsConIdx, TCPIP_TLS_MAX_TX_SERVER_SIGNATURE_PARAMS_LENGTH))
        {
          TcpIp_TlsServerMsg_ServerKeyExchangeAddSignatureParams(TlsConIdx);
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx,
            TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_ADD_ECDHE_PARAMS_DECODE_SIGNATURE);
          /* This operation is processed within the lowPrio function, which means that we are leaving
             this context and return when the operation is DONE */
        }
        else
        {
          /* Memory runtime check fails - report DET */
          TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
        }
      break;
      }

      case TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_ADD_ECDHE_PARAMS_DECODE_SIGNATURE:
      {
        /* #40 ServerKeyExchange message (ECDHE part) - Encode Signature */
        if(TCPIP_TLS_HS_CHECK_BUFFER_IDX(TlsConIdx, TCPIP_TLS_MAX_TX_SERVER_ENCODED_SIGNATURE_LENGTH))
        {
          TcpIp_TlsServerMsg_ServerKeyExchangeEncodeSignature(TlsConIdx);
          /* State TRIGGER_TX means this part of the message is done with processing */
          TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_TRIGGER_TX);
        }
        else
        {
          /* Memory runtime check fails - report DET */
          TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
        }
      break;
      }

      default:                                                                                                           /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
      {
        /* Default case left blank intentionally */
        TCPIP_ASSERT_UNREACHABLE();
        break;
      }

    } /* switch () */
  } /* while () */

} /* TcpIp_TlsServerMsg_ServerKeyExchangeAddEcdheParams() */
#   endif
#   if (TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsServerMsg_ServerKeyExchangeAddPskParams
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ServerKeyExchangeAddPskParams(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Add PSK identity hint for plain PSK server key exchange */
  retVal = TcpIp_TlsServerMsg_ServerKeyExchangeAddPskIdentityHint(TlsConIdx);

  /* State TRIGGER_TX means this part of the message is done with processing */
  TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx,
    TCPIP_TLS_STATE_SEND_SERVER_KEY_EXCHANGE_TRIGGER_TX);

  return retVal;
} /* TcpIp_TlsServerMsg_ServerKeyExchangeAddPskParams() */
#   endif /* TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON */
/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_PrepareServerHelloDone
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_PrepareServerHelloDone(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxServerHelloDoneIdxOfTlsServerBufferMgmtType serverHelloDoneIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* Store the start index of this message to the current write index - used to add the length information after the data is added */
  TcpIp_SetTlsBufferTxServerHelloDoneIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx,
    TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

  /* #10 ServerHelloDone message - Add generic TLS handshake header type */
  TcpIp_TlsMsg_AddHsHdr(TlsConIdx, TCPIP_TLS_HSTYPE_SERVERHELLODONE);

  /* #20 ServerHelloDone message - Update the overall length information in the TLS handshake header */
  serverHelloDoneIdx = TcpIp_GetTlsBufferTxServerHelloDoneIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);


  TcpIp_SetServerHelloDoneLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx,
    (TCPIP_TLS_SERVERHELLODONE_LEN + TCPIP_TLS_HSHDRLEN));
  TcpIp_TlsMsg_AddLenToHsHdr(serverHelloDoneIdx, TCPIP_TLS_SERVERHELLODONE_LEN);

} /* TcpIp_TlsServerMsg_PrepareServerHelloDone() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_PrepareServerFinished
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_TlsStatemachine_STCAL_6050 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_PrepareServerFinished(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Prepare the ServerFinished message until we are done AND no Async context needs to be computed */
  while (   (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx)  != TCPIP_TLS_STATE_SEND_SERVER_FINISHED_DONE)        /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
             /* Async operation is trigged (performed in lowPrio task) - leave this context */
        && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_ASYNC_PENDING) )
  {
    switch (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx))
    {
      case TCPIP_TLS_STATE_SEND_SERVER_FINISHED:
      {

        /* Store the start index of this message to the current write index - used to add the length information after the data is added */
        TcpIp_SetTlsBufferTxServerFinishedIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx,
          TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

        /* #20 ServerFinished message - Add generic TLS handshake header type */
        TcpIp_TlsMsg_AddHsHdr(TlsConIdx, TCPIP_TLS_HSTYPE_FINISHED);

        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_SERVER_FINISHED_CALC_HASH);
        break;
      }

      case TCPIP_TLS_STATE_SEND_SERVER_FINISHED_CALC_HASH:
      {
        /* #30 ServerFinished message - Add the calculated server finished data */
        TcpIp_TlsServerMsg_ServerFinishedAddServerFinishedData(TlsConIdx);
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_SERVER_FINISHED_TRIGGER_TX);
        /* This operation is processed within the lowPrio function, which means that we are leaving
           this context and return when the operation is DONE */
        break;
      }

      case TCPIP_TLS_STATE_SEND_SERVER_FINISHED_TRIGGER_TX:
      {
        /* #40 ServerFinished message - Update the overall length information in the TLS handshake header */
        TcpIp_TlsBufferTxServerFinishedIdxOfTlsServerBufferMgmtType serverFinishedIdx
          = TcpIp_GetTlsBufferTxServerFinishedIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

        TcpIp_SetServerFinishedLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, TCPIP_TLS_FINISHED_MESSAGE_LEN);
        TcpIp_TlsMsg_AddLenToHsHdr(serverFinishedIdx, TCPIP_TLS_FINISHED_VERIFYDATA_LEN);
        TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_SEND_SERVER_FINISHED_DONE);

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

} /* TcpIp_TlsServerMsg_PrepareServerFinished() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ServerHelloAddSelectedCipher
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ServerHelloAddSelectedCipher(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  Std_ReturnType retVal = E_NOT_OK;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if we found a matching cipher suite */
  /* Selection is performed during parsing of ClientHello message */
  if(activeTlsCipherWorkerIdx != TCPIP_NO_TLSCIPHERWORKERACTIVEIDXOFTLSCONNECTIONDYN)
  {
    TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType adHsWriteTlsBufferTxIdx
      = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

    /* Get the index of the current CipherDefiniton */
    TcpIp_TlsCipherDefinitionIdxOfTlsCipherWorkerType tlsCipherDefinitionIdx
      = TcpIp_GetTlsCipherDefinitionIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx);

    /* Get the corresponding Cipher Id (HexCode) */
    TcpIp_CipherSuiteIdOfTlsCipherDefinitionType cipherSuiteId
      = TcpIp_GetCipherSuiteIdOfTlsCipherDefinition(tlsCipherDefinitionIdx);

    TCPIP_P2V(uint8) txBufferPtr = TcpIp_GetAddrTlsBufferTx(adHsWriteTlsBufferTxIdx);

    /* #20 Write the selected cipher suite to the TLS TxBuffer for transmitting */
    IpBase_PutUint16(txBufferPtr, 0, cipherSuiteId);

    /* Maintain AdHs write index by incrementing the consumed length */
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_CIPHERSUITEID_LEN);

    retVal = E_OK;
  }
  else
  {
    /* This could never happen due to previous checks - left blank intentionally */
  }

  return retVal;
} /* TcpIp_TlsServerMsg_ServerHelloAddSelectedCipher() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ServerHelloAddCompressionMethod
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ServerHelloAddCompressionMethod(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType adHsWriteTlsBufferTxIdx
      = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Write the supported compression method to the TLS TxBuffer for transmitting */
  /* Only the compression method NONE is supported by this implementation */
  IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(adHsWriteTlsBufferTxIdx), 0u, TCPIP_TLS_COMPRESSION_METHOD_NONE);

  /* Maintain AdHs write index by incrementing the consumed length */
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLSSERVER_COMPMETH_LEN);

} /* TcpIp_TlsServerMsg_ServerHelloAddCompressionMethod() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ServerHelloAddServerExtensions
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ServerHelloAddServerExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* Store the extension length field write index for later usage */
  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType extLenStartTlsBufferTxIdx
    = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  uint16 extTotalLen;


  /* RFC5246 7.4.1.4.  Hello Extensions Format
   *
   *                      +--> overall (consumed) Extensions Length (extTotalLen)
   *                     /       +--> Extension Start Index
   *                    /       /
   *       [extensions length] [extension Type 1] [extension Data 1] [extension Type 2] [extension Data 2]  ...
   * Byte: 0                 1 2                3 4                                                           /
   *                           \-------------------------(extTotalLen)---------------------------------------/
   *
   * extensions length - Overall length of all added extension list.
   * extension type - identifies the particular extension type.
   * extension data - contains information specific to the particular extension type.
   */

  /* ----- Implementation ----------------------------------------------- */
  /* Skip the write index for the extension length field (2 Byte), filled out later */
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_LENGTH_LEN);

  /* #10 Add record_size_limit(28) Extension - RFC8449 */
  TcpIp_TlsServerMsg_ServerHelloExtAddRecordSizeLimit(TlsConIdx);

  /* #20 Calculate and set overall extension length */
  extTotalLen = (uint16)(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx) - extLenStartTlsBufferTxIdx
    - TCPIP_TLS_EXTENSION_LENGTH_LEN);

  /* #30 Only include the extensions length if the server wants to transmit extensions */
  if (extTotalLen != 0u)
  {
    TCPIP_P2V(uint8) txBufferPtr = TcpIp_GetAddrTlsBufferTx(extLenStartTlsBufferTxIdx);
    /* TLS-Server extensions added to the transmit buffer - write the overall extensions length */

    IpBase_PutUint16(txBufferPtr, 0, extTotalLen);
  }
  else
  {
    /* No TLS-Server extensions are added - reset the placeholder for the extension length field */
    TcpIp_SetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, extLenStartTlsBufferTxIdx);
  }

} /* TcpIp_TlsServerMsg_ServerHelloAddServerExtensions() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ServerHelloExtAddRecordSizeLimit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
  */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ServerHelloExtAddRecordSizeLimit(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

 /* RFC8449 Record Size Limit Extension for TLS
  * "record_size_limit" Extension Format:
  *
  *                      +--> (fixed) Extension Length
  *                     /         +--> RlSizeLimit Start Index
  *                    /         /
  *       [ext Type] [ext Len] [RL size limit]
  * Byte: 0        1 2       3 4             5
  *
  * Record Size Limit: Maximum record size that an endpoint is willing to receive (in Bytes)
  *                    Configuration parameter: TcpIpTlsMaxFragmentLength
  */
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the extension is enabled for this TLS connection */
  if (TcpIp_IsTlsUseExtensionRecordSizeLimitOfTlsConnection(TlsConIdx) == TRUE)
  {
    /* #20 Check if the extension is received from the TLS-Client in the ClientHello message */
    if (TcpIp_IsExtensionRecordSizeLimitReceivedOfTlsConnectionDyn(TlsConIdx) == TRUE)
    {
      TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

      TcpIp_RxRecordSizeLimitOfTlsConnectionDynType availableRxBufferSize
        = TcpIp_GetRxRecordSizeLimitOfTlsConnectionDyn(TlsConIdx);

      TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType extTypeStartTlsBufferTxIdx
        = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

      TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType extLenTlsBufferTxIdx
        = extTypeStartTlsBufferTxIdx + TCPIP_TLS_EXTENSION_TYPE_LEN;

      TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType rlSizeLimitStartTlsBufferTxIdx
        = extLenTlsBufferTxIdx + TCPIP_TLS_EXTENSION_LENGTH_LEN;

      TCPIP_P2V(uint8) txBufferPtr = TcpIp_GetAddrTlsBufferTx(extTypeStartTlsBufferTxIdx);

      /* #30 Extension enabled for this TLS connection - Write configured information into ServerHello message */
      /* Set the extension type to TCPIP_TLS_EXTENSION_RECORD_SIZE_LIMIT (0x001C) */

      IpBase_PutUint16(txBufferPtr, 0, TCPIP_TLS_EXTENSION_RECORD_SIZE_LIMIT);
      TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_TYPE_LEN);

      txBufferPtr = TcpIp_GetAddrTlsBufferTx(extLenTlsBufferTxIdx);

      /* Set the fixed extension length (2 byte) */

      IpBase_PutUint16(txBufferPtr, 0, TCPIP_TLS_EXTENSION_RECORD_SIZE_LIMIT_FIXED_LEN);
      TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_LENGTH_LEN);

      txBufferPtr = TcpIp_GetAddrTlsBufferTx(rlSizeLimitStartTlsBufferTxIdx);

      /* Set the configured record size limit value */

      IpBase_PutUint16(txBufferPtr, 0, availableRxBufferSize);
      TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
        TCPIP_TLS_EXTENSION_RECORD_SIZE_LIMIT_VALUE_LEN);

    } /* else- Extension is not received from the TLS-Client. Do nothing */
  } /* else - Extension is not enabled. Do nothing. */
} /* TcpIp_TlsServerMsg_ServerHelloExtAddRecordSizeLimit() */
#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ServerCertificateAddServerCertificates
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ServerCertificateAddServerCertificates(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx  = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* Store the current write index, which is the index where the complete certificate
     length should be placed after adding the certificates */
  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType certLenTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TCPIP_P2V(uint8) txBufferPtr = TcpIp_GetAddrTlsBufferTx(certLenTlsBufferTxIdx);
  uint32 totalCertsLen  = 0;
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* Maintain AdHs write index by incrementing the consumed length */
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLSSERVER_CERTLEN_LEN);

  /* #10 Iterate over all configured server certificates in the chain and add the installed certificates into the TLS TxBuffer for transmitting */
  retVal = TcpIp_TlsServerMsg_AddServerCertificatesAddCertChain(TlsConIdx, &totalCertsLen);

  /* #20 Write the total length of all added server certificates */
  IpBase_PutUint24(txBufferPtr, 0, totalCertsLen);

  return retVal;
} /* TcpIp_TlsServerMsg_ServerCertificateAddServerCertificates() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_AddServerCertificatesAddCertChain
 *********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_AddServerCertificatesAddCertChain(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint32) CopiedLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* The ID of the leaf certificate was already determined earlier. */
  TcpIp_CertificateIdType nextCertId = TcpIp_GetHsLeafCertIdOfTlsConnectionDyn(TlsConIdx);
  boolean stopAddingCerts = FALSE;  /* Stop adding further certs to the cert chain, don't even add the current one. */
  Std_ReturnType          retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Load all available certificates into the chain (starting with the leaf cert). Including the root cert depends on the configuration. */
  while ((retVal == E_OK) && (stopAddingCerts == FALSE))
  {
    /* Add the current cert to the chain if applicable */
    retVal = TcpIp_TlsServerMsg_AddServerCertificatesAddLoadableCert(
      TlsConIdx, &nextCertId, CopiedLenPtr, &stopAddingCerts);
  }  /* while-loop */

  return retVal;
} /* TcpIp_TlsServerMsg_AddServerCertificatesAddCertChain */


/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_AddServerCertificatesAddLoadableCert
 *********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_AddServerCertificatesAddLoadableCert(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(TcpIp_CertificateIdType) NextCertIdPtr,
  TCPIP_P2V(uint32) CopiedLenPtr,
  TCPIP_P2V(boolean) StopAddingCertsPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_CertificateIdType currCertId;
  boolean addLastCert = FALSE;
  boolean stopAddingCerts = FALSE;
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  currCertId = *NextCertIdPtr;
  *NextCertIdPtr = TCPIP_CERTID_INV;  /* Reset id of the next cert */


  /* #10 Check if an issuing certificate is available or if the current certificate is a self-signed certificate. */
  if (KeyM_GetIssuerCertId(currCertId, NextCertIdPtr) != E_OK)
  {
    /* No issuing certificate is available. Stop adding further certificates to the cert chain. */

    addLastCert = TRUE;  /* This is the last cert that can be added to the cert chain. */
  }
  else
  {
    /* The issuing cert is available. */

    /* #20 Check if the current certificate is a self-signed certificate. */
    if (currCertId == *NextCertIdPtr)
    {
      /* The current cert is a self-signed root cert. */

      /* Check if the root cert shall be added to the cert chain */
      if (TcpIp_IsIncludeRootCertificateOfTlsConnection(TlsConIdx) == FALSE)
      {
        /* Root certs shall not be added to the cert chain, so stop adding certs now. The current cert is not added to the cert chain. */
        stopAddingCerts = TRUE;
      }
      else
      {
        /* The current cert (root cert) shall be added to the cert chain */
        addLastCert = TRUE;  /* This is the last cert we can add to the cert chain. */
      }
    }
  }

  /* #30 Add the current certificate if it is allowed. */
  if (stopAddingCerts == FALSE)
  {
    /* Add the current certificate */
    if (TcpIp_TlsServerMsg_AddServerCertificatesAddSingleCert(TlsConIdx, CopiedLenPtr, currCertId) != E_OK)
    {
      /* Error, the current cert could not be added to the cert chain for some reason. Cancel the processing here. */
      stopAddingCerts = TRUE;
      retVal = E_NOT_OK;

      /* Set alert INTERNAL_ERROR (a user error is already reported in TcpIp_TlsServerMsg_AddServerCertificatesAddSingleCert). */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
    }
  }

  /* #40 Stop adding further certs if the current cert was the last one to add. */
  if (addLastCert == TRUE)
  {
    /* Our last cert was added, now stop this process. */
    stopAddingCerts = TRUE;
  }

  *StopAddingCertsPtr = stopAddingCerts;
  return retVal;
} /* TcpIp_TlsServerMsg_AddServerCertificatesAddLoadableCert */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_AddServerCertificatesAddSingleCert
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_AddServerCertificatesAddSingleCert(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint32) CopiedLenPtr,
  CONST(TcpIp_CertificateIdType, AUTOMATIC) CertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType certLenTlsBufferTxIdx;
  TcpIp_CertDataType  serverCert;

  uint32 availableSpaceInTxBuf = ((uint32)TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx) -
    TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

  Std_ReturnType  retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* Store the write index where the certificate length should be placed */
  certLenTlsBufferTxIdx = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  /* Maintain AdHs read write by incrementing the consumed length */
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLSSERVER_CERTLEN_LEN);

  /* Prepare the internal struct for the KeyM call */
  serverCert.certDataLength = availableSpaceInTxBuf - TCPIP_TLSSERVER_CERTLEN_LEN;
  serverCert.certData = TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

  /* #10 Retrieve the current certificate from the KeyM and store it into the TLS TxBuffer for transmitting. */
  if (KeyM_GetCertificate(CertId, ( KeyM_CertDataType *)&serverCert) == E_OK)                                           /* PRQA S 0310 */ /* MD_TCPIP_Rule11.3_0310_3305_TcpIp_CertDataType */
  {

    if ((((uint64)certLenTlsBufferTxIdx + TCPIP_TLSSERVER_CERTLEN_LEN) ) <= TcpIp_GetSizeOfTlsBufferTx())
    {
      TCPIP_P2V(uint8) txBufferPtr = TcpIp_GetAddrTlsBufferTx(certLenTlsBufferTxIdx);

      /* #20 Certificate successfully retrieved from KeyM - Update length information and return E_OK. */
      /* Increment the total length by the certificate length and by the length of the CertLenfield (3Byte) */
      *CopiedLenPtr += (serverCert.certDataLength + TCPIP_TLSSERVER_CERTLEN_LEN);

      /* Write the length of this certificates at the saved index */
      IpBase_PutUint24(txBufferPtr, 0u, serverCert.certDataLength);

      /* Maintain AdHs write index by incrementing the consumed length */
      TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, (uint16)serverCert.certDataLength);

      retVal = E_OK;
    }
    else
    {
      /* Memory runtime check fails - report DET */
      TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
    }
  }
  else
  {
    /* #30 Certificate could not be retrieved from KeyM - Report user error and return E_NOT_OK. */
    TcpIp_TlsUserErrorType  userError;
    userError.UserErrorId = TCPIP_TLS_ERRORID_KEYM_GETCERTIFICATE_FAILED;
    userError.TlsConId    = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);
    userError.FunctionId  = TCPIP_TLS_FCTID_SERVER_HSSTM_PREPARE_SERVERCERT_MSG;

    TcpIp_TlsCoreError_ReportUserError(userError);
  }

  return retVal;
} /* TcpIp_TlsServerMsg_AddServerCertificatesAddSingleCert() */


/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ServerKeyExchangeAddDiffieHellmanParams
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ServerKeyExchangeAddDiffieHellmanParams(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
   TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
     = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx =
     TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

   uint8 publicKeyLen;
   uint8 publicKeyCompressionLen;

  /* ----- Implementation ----------------------------------------------- */
  if (TCPIP_TLS_HS_CHECK_BUFFER_IDX(TlsConIdx, TCPIP_TLS_MAX_TX_SERVER_PUBKEY_PARAMS_LENGTH))
  {
   TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType AdHsWriteTlsBufferTxIdx
     = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

    TCPIP_P2V(uint8) tlsTxBufferPtr = TcpIp_GetAddrTlsBufferTx(AdHsWriteTlsBufferTxIdx);
    /* Store the current write index for Key Exchange parameter (needed for signature generation) */
    TcpIp_SetTlsBufferTxServerKeyExchangeParamsIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, AdHsWriteTlsBufferTxIdx);

    /* #10 Write the Curve type (named curve) into the TLS TxBuffer for transmitting */
    IpBase_PutUint8(tlsTxBufferPtr, 0u, TCPIP_TLS_CURVETYPE_NAMED_CURVE);

    /* Maintain AdHs write index by incrementing the consumed length */
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLSSERVER_CURVETYPE_LEN);
    AdHsWriteTlsBufferTxIdx = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
    tlsTxBufferPtr = TcpIp_GetAddrTlsBufferTx(AdHsWriteTlsBufferTxIdx);
    /* #20 Write the configured named curve ID into the TLS TxBuffer for transmitting */

    IpBase_PutUint16(tlsTxBufferPtr, 0u, TcpIp_GetEllipticCurveIdOfTlsHandshake(activeTlsHandshakeIdx));

    /* Maintain AdHs write index by incrementing the consumed length */
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLSSERVER_CUVEID_LEN);
    AdHsWriteTlsBufferTxIdx = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
    tlsTxBufferPtr = TcpIp_GetAddrTlsBufferTx(AdHsWriteTlsBufferTxIdx);
    /* Get the length of the Public key, depended on the current selected curve */
    publicKeyLen = TcpIp_TlsMsg_GetLenOfCurveSpecificPubKey(
      TcpIp_GetEllipticCurveIdOfTlsHandshake(activeTlsHandshakeIdx));

    /* Get the length of the optional compression flag. If no compression is used, publicKeyCompressionLen is 0u */
    publicKeyCompressionLen = TcpIp_TlsServerMsg_GetLenOfPubKeyCompression(
      TcpIp_GetEllipticCurveIdOfTlsHandshake(activeTlsHandshakeIdx));

    /* #30 Write the Length of the generated public key into the TLS TxBuffer for transmitting */

    IpBase_PutUint8(tlsTxBufferPtr, 0u, (publicKeyLen + publicKeyCompressionLen));

    /* Maintain AdHs write index by incrementing the consumed length */
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLSSERVER_PUPKEYLEN_LEN);
    AdHsWriteTlsBufferTxIdx = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
    tlsTxBufferPtr = TcpIp_GetAddrTlsBufferTx(AdHsWriteTlsBufferTxIdx);
    /* #40 Write the compression flag of the public key if the curve uses one into the TLS TxBuffer for transmitting */
    if (TcpIp_TlsCoreUtil_CheckPublicKeyCompressionFlagOfEllipticCurve(
      TcpIp_GetEllipticCurveIdOfTlsHandshake(activeTlsHandshakeIdx)) == TRUE)
    {
      /* Curve uses compression flag - Generated public key only contains the raw data.
         Write the compression flag of public key (04) in front of the key */

      IpBase_PutUint8(tlsTxBufferPtr, 0u, TCPIP_TLSSERVER_PUPKEY_COMPRESSION_FLAG);

      /* Maintain AdHs write index by incrementing the consumed length */
      TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLSSERVER_PUPKEY_COMPRESSION_FLAG_LEN);
    }

    /* #50 Write the generated DH public key into the TLS TxBuffer for transmitting */
    TcpIp_TlsServerMsg_ServerKeyExchangeAddDhPubKey(TlsConIdx);
  }
  else
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
  }
} /* TcpIp_TlsServerMsg_ServerKeyExchangeAddDiffieHellmanParams() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ServerKeyExchangeAddSignatureParams
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ServerKeyExchangeAddSignatureParams(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType adHsWriteTlsBufferTxIdx
    = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx =
    TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_P2V(uint8) tlsTxBufferPtr = TcpIp_GetAddrTlsBufferTx(adHsWriteTlsBufferTxIdx);
  /* The previous async crypto operation is done, so reset the flag */
  TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_NO_ASYNC);

  /* #10 Write the configured named curve ID into the TLS TxBuffer for transmitting */
  IpBase_PutUint16(tlsTxBufferPtr, 0, (uint16)TcpIp_GetSignatureAlgorithmIdOfTlsHandshake(activeTlsHandshakeIdx));

  /* Maintain AdHs write index by incrementing the consumed length */
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLSSERVER_SIGNATUREALGO_ID_LEN);
  adHsWriteTlsBufferTxIdx = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  /* Save the current write index to mark the position where the signature length should be placed. */
  /* The actual length is calculated and set inside the async context */
  TcpIp_SetTlsBufferTxServerKeyExchangeSignatureLenIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, adHsWriteTlsBufferTxIdx);

  /* Maintain AdHs write index by incrementing the consumed length */
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLSSERVER_SIGNATURELEN_LEN);

  /* #20 Write the generated signature into the TLS TxBuffer for transmitting */
  TcpIp_TlsServerMsg_ServerKeyExchangeAddSignature(TlsConIdx);
} /* TcpIp_TlsServerMsg_ServerKeyExchangeAddSignatureParams() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ServerKeyExchangeEncodeSignature
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ServerKeyExchangeEncodeSignature(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferTxServerKeyExchangeSignatureLenIdxOfTlsServerBufferMgmtType tlsServerKeyExchangeSignLenIdx
    = TcpIp_GetTlsBufferTxServerKeyExchangeSignatureLenIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

  TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx =
    TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

  uint8 consumedLen = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* The previous async crypto operation is done, so reset the flag */
  TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_NO_ASYNC);

  /* #10 Forward the encoding of the generated signature to the curve specific encoder function */
  switch (TcpIp_GetSignatureAlgorithmIdOfTlsHandshake(activeTlsHandshakeIdx))
  {
    case TCPIP_SIG_ALGO_ID_ECDSA_SECP256R1_SHA256:
    case TCPIP_SIG_ALGO_ID_ECDSA_SECP521R1_SHA512:
    {
      /* Encoding for SECP256R1 and SECP521R1 based signatures */
      TcpIp_TlsCoreMsg_EncodeSecpSignature(TlsConIdx, &consumedLen);
      break;
    }

    case TCPIP_SIG_ALGO_ID_ECDSA_ED25519_INTRINSIC:
    {
      /* Encoding for ED25519 based signatures */
      TcpIp_TlsCoreMsg_EncodeEd25519Signature(TlsConIdx, &consumedLen);
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

  if(((uint64)tlsServerKeyExchangeSignLenIdx + TCPIP_TLSSERVER_SIGNATURELEN_LEN) <= TcpIp_GetSizeOfTlsBufferTx())
  {
    TCPIP_P2V(uint8) txBufferPtr = TcpIp_GetAddrTlsBufferTx(tlsServerKeyExchangeSignLenIdx);                           /* TCPIP_CSL_NAME_LENGTH */

    /* #20 Update the length of the encoded signature */
    IpBase_PutUint16(txBufferPtr, 0u, consumedLen);

    /* Maintain AdHs write index by incrementing the consumed length */
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, consumedLen);
  }
  else
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
  }
} /* TcpIp_TlsServerMsg_ServerKeyExchangeDecodeSignature() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_GetLenOfPubKeyCompression
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(uint8, TCPIP_CODE) TcpIp_TlsServerMsg_GetLenOfPubKeyCompression(
  CONST(TcpIp_TlsEllipticCurveIdType, AUTOMATIC) CurveId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 lenRetVal = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return the length of the curve specific public key compression flag */
  /* Will return length 0 in case of no compression flag */
  switch (CurveId)
  {
    case TCPIP_CURVE_ID_SECP521R1:
    case TCPIP_CURVE_ID_SECP384R1:
    case TCPIP_CURVE_ID_SECP256R1:
    {
      /* SECP based curved - Compression flag used */
      lenRetVal = TCPIP_TLSSERVER_PUPKEY_COMPRESSION_LEN;
      break;
    } /* case TCPIP_CURVE_ID_SECP521R1 | TCPIP_CURVE_ID_SECP384R1 | TCPIP_CURVE_ID_SECP256R1 */

    case TCPIP_CURVE_ID_X448:
    case TCPIP_CURVE_ID_X25519:
    {
      /* ED based curve - No compression flag used */
      lenRetVal = TCPIP_TLSSERVER_PUBKEY_NO_COMPRESSION_LEN;
      break;
    } /* case TCPIP_CURVE_ID_X25519 | TCPIP_CURVE_ID_X448 */

    default:                                                                                                            /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
    {
      /* Default case left blank intentionally */
      TCPIP_ASSERT_UNREACHABLE();
      break;
    }

  } /* switch */

  return lenRetVal;
} /* TcpIp_TlsServerMsg_GetLenOfPubKeyCompression() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ServerKeyExchangeAddDhPubKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ServerKeyExchangeAddDhPubKey(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Handles synchronous CSM call and trigger the calculation of the job in the async context handler */
  TcpIp_SetDhPubKeyKeyExchangeAsyncFlagOfTlsConnectionDyn(TlsConIdx, TRUE);

  /* Set the TLS connection state to ASYNC_PENDING */
  TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_ASYNC_PENDING);

} /* TcpIp_TlsServerMsg_ServerKeyExchangeAddDhPubKey() */


/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ServerKeyExchangeAddSignature
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ServerKeyExchangeAddSignature(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Handles synchronous CSM call and trigger the calculation of the job in the async context handler */
  TcpIp_SetHsSignGenAsyncFlagOfTlsServerConnection(tlsServerConnectionIdx, TRUE);

  /* Set the TLS connection state to ASYNC_PENDING */
  TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_ASYNC_PENDING);

} /* TcpIp_TlsServerMsg_ServerKeyExchangeAddSignature() */

#   endif

#   if (TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ServerKeyExchangeAddPskIdentityHint
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerMsg_ServerKeyExchangeAddPskIdentityHint(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsPskIdentityDefaultIdxOfTlsConnectionType defaultTlsPskIdentityIdx
    = TcpIp_GetTlsPskIdentityDefaultIdxOfTlsConnection(TlsConIdx);

  TcpIp_PskIdentityHintLengthOfTlsPskIdentityType tlsPskIdentityHintLen
    = TcpIp_GetPskIdentityHintLengthOfTlsPskIdentity(defaultTlsPskIdentityIdx);

  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Compare the PSK identity hint against the maximum supported hint length */
  if (tlsPskIdentityHintLen <= TCPIP_TLS_KEYEXCH_PSKIDHINTMAXLEN)
  {
    /* Write the Length of the PSK Identity Hint length */
    IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)),
      0, tlsPskIdentityHintLen);

    /* Maintain AdHs write index by incrementing the consumed length */
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_KEYEXCH_PSKIDHINTLEN);

    if (tlsPskIdentityHintLen != 0u) /* Do not add a hint to the message if its length is zero */
    {
      /* #20 PSK identity hint length match - add the PSK hint to the TLS TxBuffer for transmitting */
      TcpIp_SizeOfPskIdentityHintType defaultStartPskIdentityHintIdx
        = TcpIp_GetPskIdentityHintStartIdxOfTlsPskIdentity(defaultTlsPskIdentityIdx);

      /* #30 Write the PSK Identity Hint string */
      VStdMemCpy(TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)),        /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
        TcpIp_GetAddrPskIdentityHint(defaultStartPskIdentityHintIdx), tlsPskIdentityHintLen);

      /* Maintain AdHs read index by incrementing the consumed length */
      TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, tlsPskIdentityHintLen);
    }
    retVal = E_OK;
  }
  else
  {
    /* #40 else - PSK hint length mismatch - return E_NOT_OK */
    retVal = E_NOT_OK;
  }

  return retVal;
}/* TcpIp_TlsServerMsg_ServerKeyExchangeAddPskIdentityHint() */
#   endif
/**********************************************************************************************************************
 *  TcpIp_TlsServerMsg_ServerFinishedAddServerFinishedData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsg_ServerFinishedAddServerFinishedData(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
 /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsServerBufferMgmtIterType tlsServerBufMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx
    = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */

  /* Store the position of the verify data (will be set inside the async context function) */
  TcpIp_SetTlsBufferTxServerFinishedVerifyDataIdxOfTlsServerBufferMgmt(tlsServerBufMgmtIdx,
    TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

  /* Maintain AdHs write index by incrementing the consumed length */
  TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_FINISHED_VERIFYDATA_LEN);

  /* #10 Handles synchronous CSM call and trigger the calculation of the job in the async context handler */
  TcpIp_SetCalcServerFinishedHashAsyncFlagOfTlsServerConnection(tlsServerConnectionIdx, TRUE);

  /* Set the TLS connection state to ASYNC_PENDING */
  TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_ASYNC_PENDING);

} /* TcpIp_TlsServerMsg_ServerFinishedAddServerFinishedData() */

/**********************************************************************************************************************
 *  TLS LISTENER
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsServerListener_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsServerListener_Init(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsListenerIterType tlsListenerIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all configured TLS-Listener and initialize their values */
  for (tlsListenerIdx = 0; tlsListenerIdx < TcpIp_GetSizeOfTlsListener(); tlsListenerIdx++)
  {
    TcpIp_TlsServerListener_ResetListener(tlsListenerIdx);
  }
} /* TcpIp_TlsServerListener_Init() */

/**********************************************************************************************************************
*  TcpIp_TlsServerListener_ResetListener
*********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsServerListener_ResetListener(TcpIp_TlsListenerIterType TlsListenerIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Reset TLS-Listener values */
  TcpIp_SetSocketDynIdxOfTlsListener(TlsListenerIdx, TCPIP_NO_SOCKETDYNIDXOFTLSLISTENER);
  TcpIp_SetPortOfTlsListener(TlsListenerIdx, TCPIP_PORT_ANY);

} /* TcpIp_TlsServerListener_ResetListener() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerListener_GetNextFreeListenerIndex
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerListener_GetNextFreeListenerIndex(
  TCPIP_P2V(TcpIp_TlsListenerIterType) TlsListenerPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsListenerIterType tlsListenerIdx;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all configured TLS-Listeners */
  for (tlsListenerIdx = 0; tlsListenerIdx < TcpIp_GetSizeOfTlsListener(); tlsListenerIdx++)
  {
    /* #20 Check if this TLS-Listener entry is free and return the index */
    if (TcpIp_GetSocketDynIdxOfTlsListener(tlsListenerIdx) == TCPIP_NO_SOCKETDYNIDXOFTLSLISTENER)
    {
      /* If so, save the index in the out parameter */
      *TlsListenerPtr = tlsListenerIdx;

      /* Set the return value to true */
      retVal = E_OK;

      /* And exit the loop */
      break;
    }
  }
  return retVal;
} /* TcpIp_TlsServerListener_GetNextFreeListenerIndex() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerListener_GetTlsListenerUsedBySocketIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerListener_GetTlsListenerUsedBySocketIdx(
  TcpIp_SocketDynIterType              SocketIdx,
  TCPIP_P2V(TcpIp_TlsListenerIterType) TlsListenerPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsListenerIterType tlsListenerIdx;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all configured TLS-Listeners and search for matching TLS-Listener with given socket index */
  for (tlsListenerIdx = 0; tlsListenerIdx < TcpIp_GetSizeOfTlsListener(); tlsListenerIdx++)
  {
    /* Check if the given socket index match */
    if (TcpIp_GetSocketDynIdxOfTlsListener(tlsListenerIdx) == SocketIdx)
    {
      /* Return TLS-Listener instance */
      *TlsListenerPtr = tlsListenerIdx;
      retVal = E_OK;
      /* Exit the loop */
      break;
    }
  }
  return retVal;
} /* TcpIp_TlsServerListener_GetTlsListenerUsedBySocketIdx() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerListener_GetTlsConnectionIndexForConnectionAssignment
 *********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
 *
 *
 *
  */
FUNC(TcpIp_TlsConnectionIterType, TCPIP_CODE) TcpIp_TlsServerListener_GetTlsConnectionIndexForConnectionAssignment(
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
    /* #20 Check if the connection is configured as TLS-Server. */
    if (TcpIp_GetModeOfTlsConnection(tlsConIdx) == TCPIP_TLS_SERVER)
    {
      TcpIp_TlsConnectionPrioType tmpPrio
      = TcpIp_TlsServerListener_GetCurrentTlsConnectionPriority(tlsConIdx, SocketIdx, UsedPort);

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
} /* TcpIp_TlsServerListener_GetTlsConnectionIndexForConnectionAssignment() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerListener_GetCurrentTlsConnectionPriority
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
TCPIP_LOCAL FUNC(TcpIp_TlsConnectionPrioType, TCPIP_CODE) TcpIp_TlsServerListener_GetCurrentTlsConnectionPriority(
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

    if (TcpIp_TlsCore_IsTlsConnectionUsedByPortAndFree(TlsConIdx, TCPIP_PORT_ANY) == TRUE)
    {
      /* #40 Found a free connection that has a matching LocalAddrIdx and a wildcard port. */
      priority = TCPIP_TLS_CON_PRIO_THIRD_HIGHEST;
    }
  }
  /* #50 else - Check if a connection without LocalAddrIdx is configured and select the priority via the given port. */
  else if (TcpIp_GetLocalAddrIdxOfTlsConnection(TlsConIdx) == TCPIP_NO_LOCALADDRIDXOFTLSCONNECTION)
  {
    if (TcpIp_TlsCore_IsTlsConnectionUsedByPortAndFree(TlsConIdx, UsedPort) == TRUE)
    {
      /* #60 Found a free connection that has no specified LocalAddrIdx and is used by the given port. */
      priority = TCPIP_TLS_CON_PRIO_FOURTH_HIGHEST;
    }

    if (TcpIp_TlsCore_IsTlsConnectionUsedByPortAndFree(TlsConIdx, TCPIP_PORT_ANY) == TRUE)
    {
      /* #70 Found a free connection that has no specified LocalAddrIdx and a wildcard port. */
      priority = TCPIP_TLS_CON_PRIO_FIFTH_HIGHEST;
    }
  }
  else
  {
    /* Intentionally left blank. */
    /* If the connection doesn't match TCPIP_TLS_CON_PRIO_INVALID is returned. */
  }

  return priority;
} /* TcpIp_TlsServerListener_GetCurrentTlsConnectionPriority() */

/**********************************************************************************************************************
 *  TcpIp_TlsServerListener_Close
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
FUNC(void, TCPIP_CODE) TcpIp_TlsServerListener_Close(
  TcpIp_SocketDynIterType SocketIdx,
  boolean Abort)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfSocketTcpDynType socketTcpIdx = TCPIP_SOCKET_IDX_TO_TCP_IDX(SocketIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Identify the corresponding TLS-Listener by the given socket index */
  if(socketTcpIdx < TcpIp_GetSizeOfSocketTcpDyn())
  {
    TcpIp_TlsListenerIterType tlsListener = 0;
    if (TcpIp_TlsServerListener_GetTlsListenerUsedBySocketIdx(SocketIdx, &tlsListener) == E_OK)
    {
      if(tlsListener < TcpIp_GetSizeOfTlsListener())
      {
        /* #20 Forward the call to the specific TLS-Connection */
        TcpIp_TlsServerListener_ForwardCloseToTlsConnection(tlsListener, Abort);

        /* #30 Mark the TLS-Listener as unused */
        TcpIp_TlsServerListener_ResetListener(tlsListener);

        /* #40 Forward the close to the underlaying TCP socket */
        TcpIp_CloseTcpSocketFromTls(socketTcpIdx, Abort);
      }
      else
      {
        /* Memory runtime check fails - report DET */
        TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
      }
    }
    /* else - This can not happen. If there is a listen socket, then there must be a TlsListenerIdx */
  }
  else
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
  }
} /* TcpIp_TlsServerListener_Close() */


/**********************************************************************************************************************
 *  TcpIp_TlsServerListener_ForwardCloseToTlsConnection
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsServerListener_ForwardCloseToTlsConnection(
  TcpIp_TlsListenerIterType TlsListenerIdx,
  boolean Abort)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsConnectionIterType tlsConIdx;
  TcpIp_SocketDynIdxOfTlsListenerType tlsListenerListenSocket = TcpIp_GetSocketDynIdxOfTlsListener(TlsListenerIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all configured TLS-Connections */
  for (tlsConIdx = 0; tlsConIdx < TcpIp_GetSizeOfTlsConnection(); tlsConIdx++)
  {
    TcpIp_TlsConnectionState tlsConConnectionState = TcpIp_GetConnectionStateOfTlsConnectionDyn(tlsConIdx);

    /* #20 Check if there is an active handshake ongoing on this specific TLS-Connection */
    if (tlsConConnectionState == TCPIP_TLS_STATE_CONNECTION_HS_ACTIVE)
    {
      TcpIp_SocketDynListenIdxOfTlsConnectionDynType tlsConListenSocket
        = TcpIp_GetSocketDynListenIdxOfTlsConnectionDyn(tlsConIdx);

      /* #30 Check if this TLS-Connection is owned by the given TLS Listener and forward the close request to all ongoing TLS handshakes */
      if ((tlsConListenSocket == tlsListenerListenSocket))
      {
        /* Forward the close request for the ongoing TLS handshakes.
         * Actual closing is done in main function context by TcpIp_TlsCoreConState_UserResetRequestedHandler */
        if (Abort == TRUE)
        {
          /* Immediately terminate the ongoing TLS handshakes by sending RST */
          TcpIp_SetConnectionStateOfTlsConnectionDyn(tlsConIdx, TCPIP_TLS_STATE_CONNECTION_ACTIVE_HS_CANCLED);
        }
        else
        {
          /* Gracefully terminate the ongoing TLS handshakes by sending FIN */
          TcpIp_SetConnectionStateOfTlsConnectionDyn(tlsConIdx, TCPIP_TLS_STATE_CONNECTION_ACTIVE_HS_CLOSED);
        }

        break;
      }
    }
  }
} /* TcpIp_TlsServerListener_ForwardCloseToTlsConnection() */

#   if ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON))
/**********************************************************************************************************************
 *  MSA - Master Secret Access
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsServerMsa_AddServerSessionIdToAccessBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsa_AddServerSessionIdToAccessBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  uint8 sessionIdLen
    = TcpIp_GetServerHelloSessionIdLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx);

  TCPIP_P2C(uint8) sessionIdSrcPtr
    = TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxServerSessionIdIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx));

  TCPIP_P2V(uint8) sessionIdDstPtr
    = TcpIp_GetAddrTlsClientSessionIdAccessBuffer(TcpIp_GetTlsClientSessionIdAccessBufferStartIdxOfTlsConnection(TlsConIdx));

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Make transmitted sessionID accessible for MSA readout */
  /* Set the actual received SessionID length and copy the sessionID to the MSA_AccessBuffer */
  TcpIp_SetClientSessionIdAccessBufferLenOfTlsConnectionDyn(TlsConIdx, sessionIdLen);
  if (sessionIdLen != 0u)
  {
    /* Copy from the SessionId start IDX (inside of the TLS TX-Buffer) to the AccessBuffer */
    VStdMemCpy(sessionIdDstPtr, sessionIdSrcPtr, sessionIdLen);                                                         /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
  }

} /* TcpIp_TlsServerMsa_AddServerSessionIdToAccessBuffer() */
#   endif /* ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON)) */
#   if ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON))

/**********************************************************************************************************************
* TcpIp_TlsServerMsa_AddClientRandomToAccessBuffer
*********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsServerMsa_AddClientRandomToAccessBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TCPIP_P2C(uint8) clientRndSrcPtr
    = TcpIp_GetAddrTlsBufferRx(TcpIp_GetTlsBufferRxClientRandomIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx));

  TCPIP_P2V(uint8) clientRndDstPtr
    = TcpIp_GetAddrTlsClientRandomAccessBuffer(TcpIp_GetTlsClientRandomAccessBufferStartIdxOfTlsConnection(TlsConIdx));

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Make received ClientRandom value accessible for MSA readout */
  /* Copy random value (stored inside of TLS RxBuffer) to the AccessBuffer */
  VStdMemCpy(clientRndDstPtr, clientRndSrcPtr, TCPIP_TLS_RANDOM_LEN);                                                   /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

} /* TcpIp_TlsServerMsa_AddClientRandomToAccessBuffer() */

#   endif /* ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON)) */

/**********************************************************************************************************************
* TcpIp_TlsServerListener_ConfigTcpSocket
*********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsServerListener_ConfigTcpSocket(
  TcpIp_SocketDynIterType      SocketIdx)
{
  TcpIp_SocketTcpDynIterType socketTcpIdx = TCPIP_SOCKET_IDX_TO_TCP_IDX(SocketIdx);
  uint16 localPort = TcpIp_GetLocSockOfSocketDyn(SocketIdx).DomainAndPort.port;
  Std_ReturnType retVal = E_OK;

  /* #10 Configure the used TLS listener. */
  if (TcpIp_IsUseTlsOfSocketTcpDyn(socketTcpIdx) == TRUE)
  {
    /* TLS was activated on this socket by ChangeParameter(). */

    /* Find a listener and configure it. */
    retVal = TcpIp_Tls_BindAndListen(SocketIdx, localPort);
  }
  else
  {
    /* TLS is not yet activated on this socket. Check if the local port is pre-configured for a TLS listener. */

    if (TcpIp_VIsPortUsedByAsrTls(localPort, TCPIP_TLS_SERVER) == TRUE)
    {
      TcpIp_SetUseTlsOfSocketTcpDyn(socketTcpIdx, TRUE);

      /* Find a listener and configure it. */
      retVal = TcpIp_Tls_BindAndListen(SocketIdx, localPort);
    }
  }

  return retVal;
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

#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
# endif /* (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON) */
#endif /* (TCPIP_SUPPORT_ASRTLS == STD_ON) */
/**********************************************************************************************************************
 *  END OF FILE: TcpIp_TlsServer.c
 *********************************************************************************************************************/
