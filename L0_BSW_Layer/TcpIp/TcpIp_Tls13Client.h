/***********************************************************************************************************************
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
/*!        \file  TcpIp_Tls13Client.h
 *        \brief  Transport Layer Security (TLS) 1.3 client functions implementation.
 *
 *      \details  This file is part of the TcpIp TLS submodule.
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp module. >> TcpIp.h
 **********************************************************************************************************************/

#if !defined (TCPIP_TLS13CLIENT_H)
# define TCPIP_TLS13CLIENT_H

# include "TcpIp_Cfg.h"

# if (TCPIP_SUPPORT_ASRTLS == STD_ON)                                                                                   /* COV_MSR_UNSUPPORTED */
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#    include "TcpIp_Lcfg.h"
#    include "TcpIp_Tls13Core.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
#    define TCPIP_TLS_EXTENSION_SERVERHELLO_SUPPORTED_VERSIONS_LENGTH                   6u /* Used in the TLS 1.3 ServerHello message */

/* Minimum length of a TLS 1.3 ServerHello message (HelloRetryMsg):
 *   - 2  bytes legacy_version,
 *   - 32 bytes random,
 *   - 1  byte session id length (Session ID <0..32>),
 *   - 2  bytes cipher suite info,
 *   - 1  bytes legacy_compression_method
 *   - 2  bytes extensions length
 *   - 6  bytes supported_version extension
     - 6  bytes keyShareHelloRetryRequest extension */
#    define TCPIP_TLS_13_MIN_SERVERHELLO_MSGLEN ( TCPIP_TLS_VERSLEN + TCPIP_TLS_RANDOM_LEN \
                                          + TCPIP_TLS_SESSIONIDLEN_LEN\
                                          + TCPIP_TLS_CIPHERSUITESLEN_LEN + TCPIP_TLS_COMPMETHLEN_LEN\
                                          + TCPIP_TLS_EXTENSION_LENGTH_LEN\
                                          + TCPIP_TLS_EXTENSION_SERVERHELLO_SUPPORTED_VERSIONS_LENGTH\
                                          + TCPIP_TLS_EXTENSION_TYPE_LEN\
                                          + TCPIP_TLS_EXTENSION_LENGTH_LEN\
                                          + TCPIP_TLS_EXTENSION_KEY_SHARE_GROUP_LEN)

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_Tls13Client_RequestUsageOfSessionResumption
 *********************************************************************************************************************/
/*! \brief         Request usage of session resumption with the given sockets
 *  \details       -
 *  \param[in]     SocketTcpIdx                 Tcp socket index of the derived connection
 *  \param[in]     ResumptionBaseSocketTcpIdx   Tcp socket index of the resumption base connection
 *  \return        E_OK                         Operation successful
 *  \return        E_NOT_OK                     Operation NOT successful (No unused session ticket available)
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_RequestUsageOfSessionResumption(
  TcpIp_SizeOfSocketTcpDynType SocketTcpIdx,
  TcpIp_SizeOfSocketTcpDynType ResumptionBaseSocketTcpIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_IssueChangeableCipherCallout
 *********************************************************************************************************************/
/*! \brief         Issue the changeable cipher callout and trigger further processing depending on the callout result.
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
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_IssueChangeableCipherCallout(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_CheckConsistencyOfCipherSuiteAndSignAlgoWorkingSets
 *********************************************************************************************************************/
/*! \brief         Checks the consistency of the cipher suite and signature algorithm working sets after the changeable cipher callback to the UL
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Cipher suite and signature algorithm working set lengths are consistent
 *  \return        E_NOT_OK                Cipher suite and signature algorithm working set lengths are not consistent
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_CheckConsistencyOfCipherSuiteAndSignAlgoWorkingSets(
  TcpIp_TlsConnectionIterType TlsConIdx);

#    if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ClientHelloExtAddCertificateAuthoritiesList
 *********************************************************************************************************************/
/*! \brief         Add the distinguished names of the certificates to the certificate_authorities extension.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ExtAuthoritiesStartIdx  Start Idx in TLS TX Buffer for the list of the DNs
 *  \param[out]    ConsumedLenPtr          Pointer to the total byte length of the DN list
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtAddCertificateAuthoritiesList(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferTxIterType   ExtAuthoritiesStartIdx,
  TCPIP_P2V(uint16)           ConsumedLenPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ClientHelloExtAddCertificateAuthorities
 *********************************************************************************************************************/
/*! \brief         Add the certificate authorities extension to the client hello message.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtAddCertificateAuthorities(
  TcpIp_TlsConnectionIterType TlsConIdx);
#    endif

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ClientHelloExtAddSupportedVersions
 *********************************************************************************************************************/
/*! \brief         Add the supported versions extension to the client hello message.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtAddSupportedVersions(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ClientHelloExtAddPreSharedKey
 *********************************************************************************************************************/
/*! \brief         Add the pre_shared_key extension to the client hello message.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtAddPreSharedKey(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ClientHelloExtCopyPskBinderToTxBuffer
 *********************************************************************************************************************/
/*! \brief         Copy the calculated binder from the temporary Hmac buffer to the TLS Tx buffer.
 *  \details       The binder is added to the pre_shared_key extension which is already partially build in the Tx buffer.
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtCopyPskBinderToTxBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ClientHelloExtAddPskKeyExchangeModes
 *********************************************************************************************************************/
/*! \brief         Add the psk_key_exchange_modes extension to the client hello message.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtAddPskKeyExchangeModes(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ClientHelloExtUpdateKeyShareLengthFields
 *********************************************************************************************************************/
/*! \brief         Update the length fields of the KeyShare extension after adding a KeyShareEntry to it
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtUpdateKeyShareLengthFields(
  TcpIp_TlsConnectionIterType TlsConIdx);

#    if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ClientHelloExtAddKeyShare
 *********************************************************************************************************************/
/*! \brief         Add the KeyShare extension to the client hello message
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
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ClientHelloExtAddKeyShare(
  TcpIp_TlsConnectionIterType TlsConIdx);
#    endif

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerHelloChecksBeforeScanForSuppVersExt
 *********************************************************************************************************************/
/*! \brief         Perform Length checks and check if any extensions were received in the ServerHello
 *  \details       If no extensions were received set the active version to 1.2,
 *                 otherwise scan for the supported versions extension and set the active version accordingly
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ServerHelloStartIdx     Start index in Tls RxBuffer of the ServerHello message
 *  \param[in]     ServerHelloEndIdx       End index in Tls RxBuffer of the ServerHello message
 *  \return        E_OK                    Operation successful
 *  \return        E_NOT_OK                Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerHelloChecksBeforeScanForSuppVersExt(
  TcpIp_TlsConnectionIterType                              TlsConIdx,
  TcpIp_TlsBufferRxServerHelloIdxOfTlsClientBufferMgmtType ServerHelloStartIdx,
  TcpIp_TlsBufferRxIterType                                ServerHelloEndIdx);

#    if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerHelloParseExtensionKeyShare
 *********************************************************************************************************************/
/*! \brief         Parses the received TLS key_share extension (only can handle a server key share).
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     KeyShare                Extension of type key_share
 *  \return        E_OK                    Operation successful
 *  \return        E_NOT_OK                Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerHelloParseExtensionKeyShare(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType KeyShare);
#    endif

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerHelloParseExtensionPreSharedKey
 *********************************************************************************************************************/
/*! \brief         Parses the received TLS pre_shared_key extension (only can handle a server pre shared key).
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     PreSharedKey            Extension of type pre_shared_key
 *  \return        E_OK                    Operation successful
 *  \return        E_NOT_OK                Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerHelloParseExtensionPreSharedKey(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType      PreSharedKey);

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerHelloMsgCheckRandomForDowngrade
 *********************************************************************************************************************/
/*! \brief         Checks the ServerRandom for the downgrade value in the last 8 bytes to indicate a lower TLS version
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
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerHelloMsgCheckRandomForDowngrade(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13ClientMsg_ServerHelloMsgCheckRandomForHelloRetryRequest
 *********************************************************************************************************************/
/*! \brief         Checks the ServerRandom for the special value which indicates a HelloRetryRequest
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        TRUE                    ServerRandom does indicate a HelloRetryRequest - HRR is not supported
 *  \return        FALSE                   ServerRandom is not equal to special value and does not indicate a HelloRetryRequest
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(boolean, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerHelloMsgCheckRandomForHelloRetryRequest(
  TcpIp_TlsConnectionIterType TlsConIdx);

/***********************************************************************************************************************
 *  TcpIp_Tls13Client_CalculateHashOfHsMessagesWithActiveCipherHashLength
 **********************************************************************************************************************/
/*! \brief         Calculate the Hash of the handshake messages.
 *  \details       Check that the calculated hash is equal to the length of hash algorithm used in the active cipher
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK               The Hash was calculated and saved.
 *  \return        E_NOT_OK           The Hash could not be calculated.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_CalculateHashOfHsMessagesWithActiveCipherHashLength(
  TcpIp_TlsConnectionIterType TlsConIdx);

/***********************************************************************************************************************
 *  TcpIp_Tls13Client_CalculateHashOfHsMessages
 **********************************************************************************************************************/
/*! \brief         Calculate the Hash of the handshake messages.
 *  \details       Check that the calculated hash has the expected length.
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     HashLength         The expected hash length
 *  \param[in,out] TargetSegmentPtr   Pointer to a buffer segment where the calculated hash shall be written to
 *  \return        E_OK               The Hash was calculated and saved.
 *  \return        E_NOT_OK           The Hash could not be calculated.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_CalculateHashOfHsMessages(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8                       HashLength,
  TcpIp_SegmentPtrType        TargetSegmentPtr);

/**********************************************************************************************************************
 *  TcpIp_Tls13Client_CalculateVerifyData
 *********************************************************************************************************************/
/*! \brief         Calculate the verifyData.
 *  \details       This is either Finished verifyData (RFC 8446 chapter 4.4.4.) or a PSK binder (chapter 4.2.11.2.)
 *  \param[in]     TlsConIdx            TLS connection index
 *                                      CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     MacGenerateCsmJobId  Id of the CSM MAC generate job
 *  \param[in]     HashLength           Expected length of the final hash
 *  \return        E_OK                 VerifyData was calculated and saved.
 *  \return        E_NOT_OK             VerifyData could not be calculated.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_CalculateVerifyData(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_CsmJobIdType          MacGenerateCsmJobId,
  uint8                       HashLength);

/***********************************************************************************************************************
 *  TcpIp_Tls13Client_CalculateMacGenerateKey
 *********************************************************************************************************************/
/*! \brief         Calculate the key for MAC calculation.
 *  \details       This is either the Finished key (RFC 8446 chapter 4.4.4.) or the PskBinderEntry (chapter 4.2.11.2.)
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK               No error occurred.
 *  \return        E_NOT_OK           Getting the hash length or calculating the MAC generate key failed.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Client_CalculateMacGenerateKey(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_CsmJobIdType          MacGenerateCsmJobId,
  uint8                       HashLength);

#    if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13ClientCtx_ValidateCertificateStatus
 *********************************************************************************************************************/
/*! \brief         Forwards a OCSP response to KeyM for processing.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientCtx_ValidateCertificateStatus(
  TcpIp_TlsConnectionIterType TlsConIdx);
#    endif

/**********************************************************************************************************************
 * TcpIp_Tls13ClientHsStm_PerformNextHsStep
 *********************************************************************************************************************/
/*! \brief         Perform the next HS processing step
 *  \details       Main TLS 1.3 client handshake state machine handling after Server Hello was parsed
 *                 in TcpIp_TlsClientHsStm_PerformNextHsStep() and the agreed TLS version is 1.3
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientHsStm_PerformNextHsStep(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ParseNewSessionTicket
 *********************************************************************************************************************/
/*! \brief         Parse the TLS 1.3 NewSessionTicket message
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     HsLen                   Handshake length
 *  \param[in]     SourceSegment1Ptr       First buffer segment (wraparound case: data at the end of the buffer)
 *  \param[in]     SourceSegment2Ptr       Second buffer segment (wraparound case: data at the start of the buffer)
 *  \return        E_OK                    Operation successful
 *  \return        E_NOT_OK                Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ParseNewSessionTicket(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint32                      HsLen,
  TcpIp_ConstSegmentPtrType   SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType   SourceSegment2Ptr);

/**********************************************************************************************************************
 * TcpIp_Tls13Client_SessionTicketUpdateCallout
 *********************************************************************************************************************/
/*! \brief         Update the upper layer about the current session tickets
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13Client_SessionTicketUpdateCallout(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13Client_MaintainSessionTicketAge
 *********************************************************************************************************************/
/*! \brief         Maintain and check the ticket age of the passed TLS 1.3 PSK identity
 *  \details       Decrement the lifetime of the passed ticket if it's not in use and handle expiration
 *  \param[in]     TlsConIdx              Index of the TLS connection where the ticket was received
 *                                        CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     Tls13PskIdentityIdx    Index of the PSK identity whose lifetime shall be maintained
 *                                        CONSTRAINT: [0..TcpIp_GetSizeOfTls13PskIdentity()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13Client_MaintainSessionTicketAge(
  TcpIp_TlsConnectionIterType             TlsConIdx,
  TcpIp_Tls13PskIdentityIterType          Tls13PskIdentityIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientCtx_AsyncHandler
 *********************************************************************************************************************/
/*! \brief         Handle async context operations for Tls 1.3 client
 *  \details       Calculates all time consuming operation if the corresponding flags are set
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK (only called in the context of the TLS background task TcpIp_Tls_MainFunctionLowPrio())
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientCtx_AsyncHandler(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientCtx_CalcPskValueAndBinder
 *********************************************************************************************************************/
/*! \brief         Calculate PSK value and binder for TLS 1.3 session resumption
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK (only called in the context of the TLS background task TcpIp_Tls_MainFunctionLowPrio())
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientCtx_CalcPskValueAndBinder(
  TcpIp_TlsConnectionIterType TlsConIdx);

#    if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_Tls13ClientCtx_AddPubKeyToKeyShareExtension
 *********************************************************************************************************************/
/*! \brief         Adds a public key to the key share extension
 *  \details       The public key is written directly into the Tx AdHs buffer (the write index must be set accordingly)
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK (only called in the context of the TLS background task TcpIp_Tls_MainFunctionLowPrio())
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13ClientCtx_AddPubKeyToKeyShareExtension(TcpIp_TlsConnectionIterType TlsConIdx);
#    endif

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ServerEncryptedExtensionsParseExtensionSupportedGroups
 *********************************************************************************************************************/
/*! \brief         Parses a received TLS extension of the type supported_groups.
 *  \details       Compares the received extension data against the supported TLS client ones.
 *  \param[in]     TlsConIdx                      TLS connection index
 *                                                \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     SupportedGroupsExtension       Extension of type supported groups
 *  \return        E_OK                           Operation successful
 *  \return        E_NOT_OK                       Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13ClientMsg_ServerEncryptedExtensionsParseExtensionSupportedGroups(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType SupportedGroupsExtension);

#   endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
#  endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */
# endif /* (TCPIP_SUPPORT_ASRTLS == STD_ON) */
#endif /* TCPIP_TLS13CLIENT_H */


/***********************************************************************************************************************
 *  END OF FILE: TcpIp_Tls13Client.h
 **********************************************************************************************************************/
