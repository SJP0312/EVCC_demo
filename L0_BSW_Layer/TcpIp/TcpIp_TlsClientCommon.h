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
/*!        \file  TcpIp_TlsClientCommon.h
 *        \brief  Transport Layer Security (TLS) client functions implementation.
 *
 *      \details  This file is part of the TcpIp TLS submodule.
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp module. >> TcpIp.h
 **********************************************************************************************************************/

#if !defined (TCPIP_TLSCLIENTCOMMON_H)
# define TCPIP_TLSCLIENTCOMMON_H

# include "TcpIp_Cfg.h"

# if (TCPIP_SUPPORT_ASRTLS == STD_ON)                                                                                   /* COV_MSR_UNSUPPORTED */
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#   include "TcpIp_Lcfg.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
 /* Minimum ServerHello length: 2 bytes version info, 32 bytes random value, 2 byte cipher suite info, 1 byte session id length, 1 bytes compression method info */
#   define TCPIP_TLS_12_MIN_SERVERHELLO_MSGLEN ( TCPIP_TLS_VERSLEN + TCPIP_TLS_RANDOM_LEN \
                                                + TCPIP_TLS_SESSIONIDLEN_LEN\
                                                + TCPIP_TLS_CIPHERSUITEID_LEN + TCPIP_TLS_COMPMETHLEN_LEN)

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
 *  TLS CLIENT INIT FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsClient_Init
 *********************************************************************************************************************/
/*! \brief         Initializes Tls Client
 *  \details       -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_Init(void);

/**********************************************************************************************************************
 * TcpIp_TlsClient_ConfigTcpSocket
 *********************************************************************************************************************/
/*! \brief         Initialize the TLS client parameters of a connection
 *  \details       Calls the init functions for all related TLS client submodules (e.g reset of length information)
 *  \param[in]     SocketTcpIdx            Tcp Socket index
 *                                         \spec requires SocketTcpIdx < TcpIp_GetSizeOfSocketTcp(); \endspec
 *  \param[in]     RemoteAddrPtr           Pointer to the remote address
 *  \return        E_OK                    Operation successful
 *  \return        E_NOT_OK                Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClient_ConfigTcpSocket(
  TcpIp_SizeOfSocketTcpDynType      SocketTcpIdx,
  TCPIP_P2C(TcpIp_SockAddrBaseType) RemoteAddrPtr);

/**********************************************************************************************************************
 * TcpIp_TlsClient_InitConnection
 *********************************************************************************************************************/
/*! \brief         Initialize the TLS client parameters of a connection
 *  \details       Calls the init functions for all related TLS client submodules (e.g reset of length information)
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_InitConnection(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClient_InitHsMsgIndices
 *********************************************************************************************************************/
/*! \brief         Initialize the message indices for the TLS client
 *  \details       Sets all relevant TLS client indices to their NO values
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_InitHsMsgIndices(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClient_InitHsLenInformation
 *********************************************************************************************************************/
/*! \brief         Initialize handshake length parameters for TLS 1.2 and TLS 1.3 client.
 *  \details       Sets all TLS client length information of the received handshake messages to zero
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_InitHsLenInformation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClient_InitAsyncFlags
 *********************************************************************************************************************/
/*! \brief         Initialize the Async flags for TLS client
 *  \details       Sets all TLS client trigger flags for the async context calculation to FALSE
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_InitAsyncFlags(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClient_InitReadyToSendFlags
 *********************************************************************************************************************/
/*! \brief         Initialize Ready to send flags for TLS client
 *  \details       Sets all TLS client trigger flags for the handshake transmit to FALSE
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_InitReadyToSendFlags(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *   TLS CLIENT HANDSHAKE STATE MACHINE
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsClient_HandshakeInitCipherWorkingSets
 *********************************************************************************************************************/
/*! \brief         Inits the cipher working sets for the changeable cipher callout to the upper layer
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_HandshakeInitCipherWorkingSets(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsClient_ResetWorkingSetsOfCipherSuitesAndSignatureAlgorithms
 *********************************************************************************************************************/
/*! \brief         Resets the working sets of cipher suites and signature algorithms
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_ResetWorkingSetsOfCipherSuitesAndSignatureAlgorithms(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsClient_BuildWorkingSetsOfCipherSuitesAndSignatureAlgorithms
 *********************************************************************************************************************/
/*! \brief         Prefills runtime lists with configured ciphersuites and signature algorithms
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_BuildWorkingSetsOfCipherSuitesAndSignatureAlgorithms(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsClient_BuildWorkingSetOfSignatureAlgorithms
 *********************************************************************************************************************/
/*! \brief         Prefills runtime lists with configured signature algorithms
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     TlsCipherWorkerIdx      TLS cipherworker index
 *                                         \spec requires TlsCipherWorkerIdx < TcpIp_GetSizeOfTlsCipherWorker(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_BuildWorkingSetOfSignatureAlgorithms(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsCipherWorkerIterType TlsCipherWorkerIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsClient_IsSignatureAlgorithmInWorkingSet
 *********************************************************************************************************************/
/*! \brief         Checks if signature algorithm is in working set of TLS connection
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     SignAlgoId              The id of the signature algorithm to check if it is in the working set
 *  \return        TRUE                    The signature algorithm is in the working set
 *  \return        FALSE                   The signature algorithm is NOT in the working set
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(boolean, TCPIP_CODE) TcpIp_TlsClient_IsSignatureAlgorithmInWorkingSet(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SignatureAlgorithmIdType SignAlgoId);

/**********************************************************************************************************************
 *  TcpIp_TlsClient_ReturnIdxOfSignatureAlgorithmInWorkingSet
 *********************************************************************************************************************/
/*! \brief         Returns index of signature algorithm in working set of TLS connection
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     SignAlgoId              The id of the signature algorithm for which the index in the working set shall be found
 *  \return        uint8                   The index of the signature algorithm in the working set - return length if not found in working set
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(uint8, TCPIP_CODE) TcpIp_TlsClient_ReturnIdxOfSignatureAlgorithmInWorkingSet(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SignatureAlgorithmIdType SignAlgoId);

/**********************************************************************************************************************
 *  TcpIp_TlsClient_WorkingSetIncludesTlsVersion
 *********************************************************************************************************************/
/*! \brief          Checks if working set contains at least one ciphersuite supporting the TLS version
 *  \details        -
 *  \param[in]      TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]      TlsVersion        The specific TLS version to check
 *  \return         TRUE              The TLS version is supported by the ciphersuites in the working set
 *                  FALSE             The TLS version is not supported by the ciphersuites in the working set
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, TCPIP_CODE) TcpIp_TlsClient_WorkingSetIncludesTlsVersion(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsVersionType TlsVersion);

/**********************************************************************************************************************
 *  TcpIp_TlsClient_IsCipherWorkingSetUnavailableOrZeroLength
 *********************************************************************************************************************/
/*! \brief          Checks if working set is unavailable or contains zero ciphersuites
 *  \details        -
 *  \param[in]      TlsConIdx         TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return         TRUE              Working set is unavailable or contains zero ciphersuites
 *                  FALSE             Working set is available and contains at least one ciphersuite
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, TCPIP_CODE) TcpIp_TlsClient_IsCipherWorkingSetUnavailableOrZeroLength(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsClient_IsCipherSuiteInWorkingSet
 *********************************************************************************************************************/
/*! \brief         Checks if cipher suite is in working set of TLS connection
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     SignAlgId               The id of the cipher suite to check if it is in the working set
 *  \return        TRUE                    The cipher suite is in the working set
 *  \return        FALSE                   The cipher suite is not in the working set
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(boolean, TCPIP_CODE) TcpIp_TlsClient_IsCipherSuiteInWorkingSet(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsCipherDataType     CipherSuiteId);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_AddDiffieHellmanParams
 *********************************************************************************************************************/
/*! \brief         Add the DH parameters either to the client key exchange message or the KeyShare extension
 *  \details       -
 *  \param[in]     TlsConIdx                         TLS connection index
 *                                                   \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     MessageType                       The message to which the parameters should be added
 *  \param[in]     CurveId                           The curve Id for which the public key should be calculated
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_AddDiffieHellmanParams(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsMsgHandshakeType MessageType,
  TcpIp_TlsEllipticCurveIdType CurveId);

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_CheckPreconditionAndTriggerValidateCertificateStatus
 *********************************************************************************************************************/
/*! \brief         Check the precondition for the validation of the certificate status.
 *                 If it is fulfilled trigger the validation.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     TlsVersion              Specifies which is the used TLS version in the current handshake.
 *                                         \spec requires (TlsVersion == TCPIP_TLSVERSION_12) || (TlsVersion == TCPIP_TLSVERSION_13) \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_CheckPreconditionAndTriggerValidateCertificateStatus(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsVersionType        TlsVersion);

/**********************************************************************************************************************
 *  TcpIp_TlsClient_IssueCertRequestCallout
 *********************************************************************************************************************/
/*! \brief         Issue the certificate request callout and trigger further processing depending on the callout result.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_IssueCertRequestCallout(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsClient_ServerCertRequestMsgFindDistinguishedNameStarts
 *********************************************************************************************************************/
/*! \brief         Process the distinguished names in the list and fill the cert request info struct.
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     DnListLength    Length of the list of distinguished names
 *  \param[in]     DnListPtr       Pointer to the list of distinguished names
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClient_ServerCertRequestMsgFindDistinguishedNameStarts(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 DnListLength,
  TCPIP_P2C(uint8) DnListPtr);

/**********************************************************************************************************************
 *  TcpIp_TlsClient_CheckSignatureAlgorithmsLengthConstraints
 *********************************************************************************************************************/
/*! \brief         Check if the constraints for the passed signature algorithm length are fulfilled.
 *  \details       The signature algorithm length must be at least two and also dividable by two according to the RFC.
 *  \param[in]     SignatureAlgorithmsLength    Length of signature algorithm list
 *  \return        E_OK                         Constraints for the passed signature algorithm length are fulfilled
 *  \return        E_NOT_OK                     Constraints for the passed signature algorithm length are NOT fulfilled
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClient_CheckSignatureAlgorithmsLengthConstraints(
  uint16 SignatureAlgorithmsLength);

/**********************************************************************************************************************
 *  TcpIp_TlsClient_SaveSignatureAlgorithmsInRequestInfoOfTlsClientAuthentication
 *********************************************************************************************************************/
/*! \brief         Copy signature algorithms to separate buffer and set RequestInfo of TlsClientAuthentication
 *  \details       If the buffer size is too small for all received algorithms, additional algorithms are ignored.
 *  \param[in]     TlsConIdx                      TLS connection index
 *                                                \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     SignatureAlgorithmsLength      Length of signature algorithms in RX buffer
 *  \param[in]     SignatureAlgorithmsSegmentPtr  Pointer to RX buffer segment for reading signature algorithms
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_SaveSignatureAlgorithmsInRequestInfoOfTlsClientAuthentication(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  uint16                        SignatureAlgorithmsLength,
  TcpIp_ConstSegmentPtrType     SignatureAlgorithmsSegmentPtr);
#   endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 * TcpIp_TlsClientHsStm_HandleErrorDuringPreparation
 *********************************************************************************************************************/
/*! \brief         Handle error during client handshake
 *  \details       Report user error and trigger alert if error occurs during handshake
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClientHsStm_HandleErrorDuringPreparation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ClientHelloExtGetSupportedGroups
 *********************************************************************************************************************/
/*! \brief           Get the supported groups in a fixed order
 *  \details         -
 *  \param[in]       TlsConIdx           TLS connection index
 *                                       CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in,out]   SupportedGroupsPtr  Pointer to an array in which the supported groups should be saved
 *  \param[in]       SupportedGroupsLen  Length of the array
 *  \return                              Amount of supported groups
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
FUNC(TcpIp_TlsEllipticCurveIdType, TCPIP_CODE) TcpIp_TlsClientMsg_ClientHelloExtGetSupportedGroups(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TCPIP_P2V(TcpIp_TlsEllipticCurveIdType) SupportedGroupsPtr,
  TcpIp_TlsEllipticCurveIdType  SupportedGroupsLen);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ServerMsgParseAndValidateExtensions
 *********************************************************************************************************************/
/*! \brief         Checks all received server extension for plausibility and validity
 *  \details       -
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ExtensionsLen   Length of the extensions data
 *  \param[in]     MsgEndIdx       End idx of the evaluated message
 *  \param[in]     SourceMessage   Type of the message in which the extensions were sent
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerMsgParseAndValidateExtensions(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16                      ExtensionsLen,
  TcpIp_TlsBufferRxIterType   MsgEndIdx,
  TcpIp_TlsMsgHandshakeType   SourceMessage);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_SetActiveCipherWorkerAccordingToReceivedServerParams
 *********************************************************************************************************************/
/*! \brief         Sets cipherworker to active if it matches the parameters from received ServerHello message
 *  \details       Search for a cipherworker matching the received ciphersuite of the ServerHello message
 *                 and the passed curve. If a matching cipherworker is found set it as active.
 *                 The elliptic curve of the connection and the active handshake of the cipherworker are set as well
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     CurveId         Curve which the cipherworker or rather it's handshake shall support
 *  \return        E_OK            Operation successful
 *  \return        E_NOT_OK        Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_SetActiveCipherWorkerAccordingToReceivedServerParams(
  TcpIp_TlsConnectionIterType     TlsConIdx,
  TcpIp_TlsEllipticCurveIdType    CurveId);

#   endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */
/**********************************************************************************************************************
 *  TcpIp_TlsClientHsStm_ReturnReceivedCipherSpecificKeyExchangeMethod
 *********************************************************************************************************************/
/*! \brief         Returns the corresponding cipher mode of the CipherSuite contained in the received ServerHello msg
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        TCPIP_TLS_KEYEXCHANGE_METHOD_ECDHE         For ECDHE key exchange
 *  \return        TCPIP_TLS_KEYEXCHANGE_METHOD_ECDH          For ECDH key exchange
 *  \return        TCPIP_TLS_KEYEXCHANGE_METHOD_PSK_PLAIN     For plain PSK key exchange
 *  \return        TCPIP_TLS_KEYEXCHANGE_METHOD_INVALID       If no valid key exchange method is found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(TcpIp_TlsKeyExchangeMethodDataType, TCPIP_CODE) TcpIp_TlsClientHsStm_ReturnReceivedCipherSpecificKeyExchangeMethod(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ServerHelloCheckSessionIdAndStoreBufferIndex
 *********************************************************************************************************************/
/*! \brief         Check validity of received session Id in the ServerHello and store its buffer index if applicable
 *  \details       Only in a TLS 1.3 handshake a check that the received session Id matches the sent one is performed
 *  \param[in]     TlsConIdx         TLS connection index
 *                                   \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     SessionIdLen      Length of the received session Id in the ServerHello
 *  \return        E_OK              Received session Id is valid
 *                 E_NOT_OK          Received session Id is NOT valid
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerHelloCheckSessionIdAndStoreBufferIndex(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC)     SessionIdLen);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ServerCertMsgHandleFailedCertGroupValidation
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
FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ServerCertMsgHandleFailedCertGroupValidation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClient_ResetCertChainStates
 *********************************************************************************************************************/
/*! \brief         Reset the TLS certificate chain struct and states
 *  \details       Sets all TLS client certificate information to their default values
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_ResetCertChainStates(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ServerCertMsgVerifyCertificateGroup
 *********************************************************************************************************************/
/*! \brief         Verify the certificate group that was loaded into KeyM
 *  \details       The server certificate chain is loaded into the KeyM certificate group
 *  \param[in]     TlsConIdx         TLS connection index
 *                                   \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK              Verifying the cert group succeeded.
 *                 E_NOT_OK          Verifying the cert group failed.
 *  \pre           -
 *  \context       TASK (only called in the context of the TLS background task TcpIp_Tls_MainFunctionLowPrio())
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_ServerCertMsgVerifyCertificateGroup(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClient_StoreReceivedRootCertId
 *********************************************************************************************************************/
/*! \brief         Stores the received root certificate ID of the current TLS connection
 *  \details       -
 *  \param[in]     TlsConIdx              TLS connection index
 *                                        \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           Certificate chain must be received
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_StoreReceivedRootCertId(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClient_TlsCertChainTriggerValidationCallback
 *********************************************************************************************************************/
/*! \brief         Notify the socket owner about the certificate chain validation result and update state
 *  \details       After this function call, certificate chain validation is complete
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     AllowOverrule           Allow the socket owner to overrule the validation result
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_TlsCertChainTriggerValidationCallback(
  TcpIp_TlsConnectionIterType TlsConIdx,
  boolean AllowOverrule);
#   endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 * TcpIp_TlsClientTx_SendChangeCipherSpec
 *********************************************************************************************************************/
/*! \brief         Trigger transmission of client CCs message
 *  \details       Forwards the TLS ChangeCipherSpec message to the record layer
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClientTx_SendChangeCipherSpec(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_CertVerifyEncodeSignature
 *********************************************************************************************************************/
/*! \brief         Encodes the generated signature so that it can be used in a client CertificateVerify message.
 *  \details       The encoded signature is immediately written into the Tx buffer
 *  \param[in]     TlsConIdx       TLS connection index
 *                                 CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_CertVerifyEncodeSignature(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClient_ProcessHandshake
 *********************************************************************************************************************/
/*! \brief         Process the TLS handshake state machine
 *  \details       Executes the TLS client handshake state machine, if all conditions are fulfilled.
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_ProcessHandshake(
  TcpIp_TlsConnectionIterType TlsConIdx);

#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsClient_ProcessConnection
 *********************************************************************************************************************/
/*! \brief         Process TLS connection related states.
 *  \details       Check connection and session ticket timings.
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClient_ProcessConnection(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsClient_IsResumptionBaseConnection
 *********************************************************************************************************************/
/*! \brief         Check if the TLS connection with the passed connection index is a resumption base connection
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index of the connection which shall be checked
 *                                         CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        TRUE                    TLS connection is configured as a resumption base connection
 *  \return        FALSE                   TLS connection is no resumption base connection
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(boolean, TCPIP_CODE) TcpIp_TlsClient_IsResumptionBaseConnection(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */

/**********************************************************************************************************************
 *   TLS CLIENT HS TRIGGER SM
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsClientTx_CheckForTransmittableProcessedHsMsg
 *********************************************************************************************************************/
/*! \brief         Checks if the processed TLS handshake messages are transmittable.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsClientTx_CheckForTransmittableProcessedHsMsg(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsClient_GetTlsConnectionIndexForConnectionAssignment
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
FUNC(TcpIp_TlsConnectionIterType, TCPIP_CODE) TcpIp_TlsClient_GetTlsConnectionIndexForConnectionAssignment(
  CONST(TcpIp_SizeOfSocketDynType, AUTOMATIC) SocketIdx,
  CONST(TcpIp_PortOfTlsListenerType, AUTOMATIC) UsedPort);

/**********************************************************************************************************************
 * TcpIp_TlsClient_GetRootCertificateId
 *********************************************************************************************************************/
/*! \brief         Provides the ID of the used root certificate.
 *  \details       -
 *  \param[in]     TlsConIdx         Tls connection Index
 *                                   CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *                                   CONSTRAINT: Mode = TCPIP_TLS_CLIENT
 *  \param[out]    CertIdPtr         Pointer to return the root certificate ID.
 *  \return        E_OK              A root certificate was found. Returned value in CertIdPtr is valid.
 *                 E_NOT_OK          No root certificate was found. Returned value in CertIdPtr is invalid.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 ********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClient_GetRootCertificateId(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TCPIP_P2V(uint16)             CertIdPtr);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_ServerCertMsgCheckCertChainOverallResult
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
FUNC(void, TCPIP_CODE) TcpIp_TlsClientMsg_ServerCertMsgCheckCertChainOverallResult(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_CertValidationResultType Result);

/**********************************************************************************************************************
 *  TLS CLIENT ASYNC CONTEXT
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MSA - Master Secret Access
 *********************************************************************************************************************/

#  endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */
# endif /* (TCPIP_SUPPORT_ASRTLS == STD_ON) */
#endif /* TCPIP_TLSCLIENTCOMMON_H */


/***********************************************************************************************************************
 *  END OF FILE: TcpIp_TlsClientCommon.h
 **********************************************************************************************************************/
