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
/*!        \file  TcpIp_Tls12Core.h
 *        \brief  Transport Layer Security (TLS) 1.2 core functions implementation.
 *
 *      \details  This file is part of the TcpIp TLS submodule.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp module. >> TcpIp.h
 *********************************************************************************************************************/

#if !defined (TCPIP_TLS12CORE_H)
# define TCPIP_TLS12CORE_H

# include "TcpIp_Cfg.h"
# if (TCPIP_SUPPORT_ASRTLS == STD_ON)                                                                                   /* COV_MSR_UNSUPPORTED */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#   include "Std_Types.h"
#   include "TcpIp_Priv_Types.h"
#   include "TcpIp_Lcfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* TLS constant length information */
#   define TCPIP_TLS_CTLEN_LEN                           2u /* Length of the content type length field */
#   define TCPIP_TLS_LABEL_CLIENT_FINISHED_LEN          15u /* Length of the client finished label within the finished message */
#   define TCPIP_TLS_LABEL_SERVER_FINISHED_LEN          15u /* Length of the server finished label within the finished message */
#   define TCPIP_TLS_LABEL_MASTER_SECRET_LEN            13u /* Length of the master secret label */
#   define TCPIP_TLS_LABEL_KEY_EXPENSION_LEN            13u /* Length of the key expansion */
#   define TCPIP_TLS_PRF_COMBINED_LABEL_LEN_MAX        100u /* Length of the combined PRF label */
#   define TCPIP_TLS_CRYPTO_SEED_LEN                    20u /* Length of the Crypto seed */
#   define TCPIP_TLS_FINISHED_VERIFYDATA_LEN            12u /* Length of the Verify Data in Finished Message */
#   define TCPIP_TLS_FINISHED_MESSAGE_LEN               (TCPIP_TLS_FINISHED_VERIFYDATA_LEN + TCPIP_TLS_HSHDRLEN)

#   define TCPIP_TLS_PSK_MAX_KEY_LENGTH                  64u
#   define TCPIP_TLS_PSK_PMS_PSK_LEN_FIELD_LEN           2u /* Length of psk length field in psk premaster secret */
#   define TCPIP_TLS_PSK_PMS_OTHER_SECRET_LEN_FIELD_LEN  2u /* Length of other secret length field in psk premaster secret */
#   define TCPIP_TLS_PSK_PMS_OTHER_SECRET_PLAIN_PATTERN  0u /* Other secret of plain psk premaster secret consists of zero bytes */

/* TLS Key Block sizes - key mat size = 2*(HMAC + AES-KEY + AES-IV) */
#   define TCPIP_TLS_KEY_BLOCK_SIZE_NULL_SHA1           40u             /* Length of the key block with an SHA1 hash eg 0002, C001 */
#   define TCPIP_TLS_KEY_BLOCK_SIZE_NULL_SHA256         64u             /* eg 003B */
#   define TCPIP_TLS_KEY_BLOCK_SIZE_AES128_SHA1         72u             /* 0..19: TX MAC; 20..39: RX MAC; 40..55: TX Key; 56..71: RX Key */
#   define TCPIP_TLS_KEY_BLOCK_SIZE_AES128_SHA256       96u             /* 0..31: TX MAC; 32..63: RX MAC; 64..79: TX Key; 80..95: RX Key */
#   define TCPIP_TLS_KEY_BLOCK_SIZE_AES128_GCM          (2u*(16u + 4u)) /* AES-KEY + SALT (The salt length (SecurityParameters.fixed_iv_length) is 4 octets.) */
#   define TCPIP_TLS_KEY_BLOCK_SIZE_UNSET               0u

#   define TCPIP_TLS_AES128_KEY_LEN                     16u /* Length of the AES128 key */

/* Padding length */
#   define TCPIP_TLS_TLS_PADDING_LEN                    1u /* Length of padding bytes */

/* Global Handshake macros */
#   define TCPIP_TLS_CURVETYPE_NAMED_CURVE             0x03u

#   define TCPIP_TLS_SERVERHELLORANDOM_LEN                                            28u
#   define TCPIP_TLS_SERVERHELLODONE_LEN                                               0u

/* TLS Extension static length and type information */
#   define TCPIP_TLS_EXTENSION_SIGNATURE_ALGORITHMS_SIGNATURE_OFFSET                   1u



/* RFC 6066 - 6.  Trusted CA Indication */
#   define TCPIP_TLS_EXTENSION_TRUSTED_CA_TYPE_PRE_AGREED                              0u
#   define TCPIP_TLS_EXTENSION_TRUSTED_CA_TYPE_KEY_SHA1_HASH                           1u
#   define TCPIP_TLS_EXTENSION_TRUSTED_CA_TYPE_X509_NAME                               2u
#   define TCPIP_TLS_EXTENSION_TRUSTED_CA_TYPE_CERT_SHA1_HASH                          3u
#   define TCPIP_TLS_EXTENSION_TRUSTED_CA_TYPE_LEN                                     1u  /* length of the type field */
#   define TCPIP_TLS_EXTENSION_TRUSTED_CA_DN_LENGTH_LEN                                2u  /* length of distinguished name length field */
#   define TCPIP_TLS_EXTENSION_TRUSTED_CA_DN_MIN_LEN                                   1u  /* distinguished name must be at least 1 byte */
#   define TCPIP_TLS_EXTENSION_RECORD_SIZE_LIMIT_FIXED_LEN                             2u
#   define TCPIP_TLS_EXTENSION_RECORD_SIZE_LIMIT_VALUE_LEN                             2u
#   define TCPIP_TLS_EXTENSION_RECORD_SIZE_LIMIT_MIN_VALUE                            64u

/* Certificate request information */
#   define TCPIP_TLS_CERTREQUEST_CERTTYPESLENGTH_LEN                                   1u                                                   /* length of the cert types length field */
#   define TCPIP_TLS_CERTREQUEST_CERTTYPE_LEN                                          1u                                                   /* length of a cert type field */
#   define TCPIP_TLS_CERTREQUEST_DISTINGUISHEDNAME_AMOUNT                              0u                                                   /* amount of distinguished names, currently set to zero */
#   define TCPIP_TLS_CERTREQUEST_DISTINGUISHEDNAME_MAXLEN                              65535u                                               /* max. length of distinguished name */

/* ECC Key Exchange information */
#   define TCPIP_TLS_KEYEXCH_CURVETYPELEN                                              1u
#   define TCPIP_TLS_KEYEXCH_CURVENAMELEN                                              2u
#   define TCPIP_TLS_KEYEXCH_SIGALGOHASHLEN                                            1u
#   define TCPIP_TLS_KEYEXCH_SIGALGOSIGNLEN                                            1u
#   define TCPIP_TLS_KEYEXCH_SIGLENLEN                                                 2u
#   define TCPIP_TLS_KEYEXCH_PARAMETERLEN (TCPIP_TLS_KEYEXCH_CURVETYPELEN + TCPIP_TLS_KEYEXCH_CURVENAMELEN + TCPIP_TLS_KEYEXCH_PUBKEYLEN)

/* PSK Key Exchange information */
#   define TCPIP_TLS_KEYEXCH_PSKIDLEN                                                 2u
#   define TCPIP_TLS_KEYEXCH_PSKIDMAXLEN                                            128u
#   define TCPIP_TLS_KEYEXCH_PSKIDHINTLEN                                             2u
#   define TCPIP_TLS_KEYEXCH_PSKIDHINTMAXLEN                                        128u

/* HelloDone information */
#   define TCPIP_TLS_HELLODONE_LEN                                                    1u
#   define TCPIP_TLS_HELLOREQUEST_LEN                                                 4u

/* Length of Client/Server Finished length */
#   define TCPIP_TLS_LABEL_FINISHED_LEN                                              15u

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/* PRQA S 3453 FctLikeMacros */ /* MD_MSR_FctLikeMacro */
#   define TCPIP_TLS_GET_HS_SUB_STATE(STATE)                            ( (uint16)STATE & 0xFFF0u )

#   define TCPIP_TLS_HANDSHAKE_ID_IS_VALID(HS_ID)   ((HS_ID)  < TcpIp_GetSizeOfTlsHandshake())

/* PRQA L:FctLikeMacros */
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern CONST(uint8, TCPIP_CONST) TcpIp_Tls_Hs_FinishedLabel[2][TCPIP_TLS_LABEL_FINISHED_LEN + 1u];

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/***********************************************************************************************************************
 *  TcpIp_Tls12CoreUtil_DoesCertificateMatchSigAlgoAndCurve
 *********************************************************************************************************************/
 /*! \brief         Checks if the certificate with the passed certificate Id matches
  *                 the passed curve and signature algorithm
  *  \details       -
  *  \param[in]     CertId                Id of the certificate which shall be checked
  *  \param[in]     SignAlgId             Id of the signature algorithm which is checked if the certificate uses it
  *  \param[in]     CurveId               Id of the curve which is checked if the certificate uses it
  *  \return        TRUE                  Certificate matches the curve and signature algorithm
  *  \return        FALSE                 Certificate does NOT match the curve and signature algorithm
  *  \pre           -
  *  \context       TASK|ISR2
  *  \reentrant     FALSE
  *  \synchronous   TRUE
  *********************************************************************************************************************/
FUNC(boolean, TCPIP_CODE) TcpIp_Tls12CoreUtil_DoesCertificateMatchSigAlgoAndCurve(
  TcpIp_CertificateIdType         CertId,
  TcpIp_SignatureAlgorithmIdType  SignAlgId,
  TcpIp_TlsEllipticCurveIdType    CurveId);
#   endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TCPIP TLS INIT FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TLS CORE UPPER LAYER (UL)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_Tls12CoreUl_TcpAccepted
 *********************************************************************************************************************/
/*! \brief         Forwards the TcpIp_TcpAccepted call to the TLS stack
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls12CoreUl_TcpAccepted(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TLS CORE CONTENT TYPE (CT)
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TLS CORE RECORD LAYER (RL)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_Tls12CoreRl_ProcessHsFrame
 *********************************************************************************************************************/
/*! \brief          Skip the parsing of TLS 1.2 handshake message. This will be done in the Hs context.
*                   Only HelloRequest and ClientHelloAfterHandshake are processed here.
 *  \details        Block the Rx decryption when a ServerFinished message was received till it was validated.
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]      HsType                  Received handshake type
 *  \param[in]      HsLen                   Received handshake length
 *                                          It is already checked that both segments together contain HsLen bytes
 *  \return         E_OK                    Message successfully processed
 *  \return         E_NOT_OK                Processing of message failed
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls12CoreRl_ProcessHsFrame(
  TcpIp_TlsConnectionIterType                 TlsConIdx,
  uint8                                       HsType,
  uint32                                      HsLen);

/**********************************************************************************************************************
 * TcpIp_Tls12CoreRl_TxCipherEncryptAes128Cbc
 *********************************************************************************************************************/
/*! \brief         Aes128 Cbc encryption
 *  \details       -
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out]  Seg1Ptr             The optional stored buffer
 *  \param[in,out]  Seg2Ptr             The received data
 *  \return         BUFREQ_OK           Buffer request accomplished successful
 *  \return         BUFREQ_E_NOT_OK     Buffer request not successful. Buffer cannot be accessed
 *  \return         BUFREQ_E_BUSY       Temporarily no buffer available. It's up the requestor to retry request for
 *                                     a certain time
 *  \return         BUFREQ_E_OVFL       No Buffer of the required length can be provided
 *  \pre            Tcp content data is present in the Tls Tx buffer
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, TCPIP_CODE) TcpIp_Tls12CoreRl_TxCipherEncryptAes128Cbc(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        Seg1Ptr,
  TcpIp_SegmentPtrType        Seg2Ptr);

/**********************************************************************************************************************
* TcpIp_Tls12CoreRl_DecryptAndAuthenticateFrameViaCbc
 *********************************************************************************************************************/
/*! \brief         Check blocksize alignment and decrypt TLS data using Aes128Cbc streaming mode
 *  \details       -
 *  \param[in]     TlsConIdx            TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType          TLS ContentType of this frame
 *  \param[in]     DataPtr              Source data pointer
 *  \param[in]     DataLen              Source data length
 *  \return        E_OK                 Operation successful
 *  \return        E_NOT_OK             Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE)  TcpIp_Tls12CoreRl_DecryptAndAuthenticateFrameViaCbc(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC)     ContentType,
  TCPIP_P2C(uint8)            DataPtr,
  uint16                      DataLen);

/**********************************************************************************************************************
 * TcpIp_Tls12CoreRl_LocateIvInBufferAndSetIvKeyElement
 *********************************************************************************************************************/
/*! \brief         Locate the AEAD Block128 IV in the TCP buffer segments, extract it, and set Csm keys for decryption
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     TcpSeg1Ptr         Pointer to TCP buffer segment 1
 *  \param[in]     IvInTcpSeg1Len     Length of Iv in TCP segment 1
 *  \param[in]     TcpSeg2Ptr         Pointer to TCP buffer segment 2
 *  \param[in]     IvInTcpSeg2Len     Length of Iv in TCP segment 2
 *  \return        E_OK               Operation successful
 *  \return        E_NOT_OK           Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE)  TcpIp_Tls12CoreRl_LocateIvInBufferAndSetIvKeyElement(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_ConstSegmentPtrType   TcpSeg1Ptr,
  uint16                      IvInTcpSeg1Len,
  TcpIp_ConstSegmentPtrType   TcpSeg2Ptr,
  uint16                      IvInTcpSeg2Len);

/**********************************************************************************************************************
 *  TLS CORE BUFFER
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TLS CORE MAIN FUNCTIONS
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  TCPIP TLS CORE STATE AND EVENT
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TCPIP TLS ERROR
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TCPIP TLS CRYPTO
 *********************************************************************************************************************/
#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
*  TcpIp_Tls12CoreCrypto_ReduceSharedKey
*********************************************************************************************************************/
/*! \brief         Reduce the key shared key to the needed size
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                if operation was successful
 *  \return        E_NOT_OK            if operation was NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls12CoreCrypto_ReduceSharedKey(
  TcpIp_TlsConnectionIterType TlsConIdx);

#   endif /* TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_Tls12CoreCrypto_CalcMasterSecret
 *********************************************************************************************************************/
/*! \brief         Calculated the TLS Master secret for this TLS Connection
 *  \details       Depending on the selected key exchange method, the shared value (output of the DH operation) must be
 *                 reduced to 32 byte size. This API handles this with the CSM copy partial operation.
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                if the calculation succeeded
 *  \return        E_NOT_OK            if the calculation was NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls12CoreCrypto_CalcMasterSecret(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls12CoreCrypto_ReduceSharedKey
 *********************************************************************************************************************/
/*! \brief         Derive the crypto key block material for this TLS Connection
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                if the key block could be derived
 *  \return        E_NOT_OK            if the key block could not be derived
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls12CoreCrypto_DeriveKeyBlock(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls12CoreCrypto_SetCsmKeys
 *********************************************************************************************************************/
/*! \brief         Set the CSM keys for HMAC and AES operations
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                if the key could be set
 *  \return        E_NOT_OK            if the key could not be set
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls12CoreCrypto_SetCsmKeys(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls12CoreCrypto_CheckCsmKeyConfiguration
 *********************************************************************************************************************/
/*! \brief         Checks if all necessary keys for the selected cipher are configured.
 *  \details       This function adds a runtime check to the optional CSM parameter for the different CipherSuites.
 *                 In case of an invalid configured CSM key or job, the access to the element must be restricted.
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                If the necessary keys and jobs are configured correctly.
 *  \return        E_NOT_OK            If the necessary keys and jobs are NOT configured correctly.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls12CoreCrypto_CheckCsmKeyConfiguration(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls12CoreCrypto_CalcKeyBlockSize
 *********************************************************************************************************************/
/*! \brief         Calculate the key block size depending on the selected cipher suite
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                if the key block size is calculated correctly
 *  \return        E_NOT_OK            otherwise
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls12CoreCrypto_CalcKeyBlockSize(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls12CoreCrypto_Prf
 *********************************************************************************************************************/
/*! \brief         Pseudo Random Function
 *  \details       Calculates a pseudo random value array to the provided target buffer using the provided seed
 *                 and secret
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ResultKeyIdPtr      CSM key where the output data shall be written to
 *  \param[in]     SecretKeyIdPtr      CSM key where the secret is stored
 *  \param[in]     LabelPtr            pointer to label
 *  \param[in]     SeedPtr             pointer to seed
 *  \param[in]     LabelLen            length of label
 *  \param[in]     SeedLen             length of seed
 *  \param[in]     ResultIsPrivate     TRUE: result key is private; FALSE: Result key is public
 *  \return        E_OK                if random could be generated
 *  \return        E_NOT_OK            if random could not be generated
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
 FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls12CoreCrypto_Prf(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(TcpIp_TlsCsmKeyInfoType) ResultKeyIdPtr,
  TCPIP_P2C(TcpIp_TlsCsmKeyInfoType) SecretKeyIdPtr,
  TCPIP_P2C(uint8) LabelPtr,
  TCPIP_P2C(uint8) SeedPtr,
  uint8 LabelLen,
  uint8 SeedLen,
  boolean ResultIsPrivate);

/**********************************************************************************************************************
 *  TPCIP TLS ALERT
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TCPIP TLS CORE LOWER LAYER (LL)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_Tls12CoreLl_TcpAccepted
 *********************************************************************************************************************/
/*! \brief         Informs TLS layers about a new socket connection on a listen socket.
 *  \details       Set the Listen and Communication socket on the TLS-Connection and triggers the start of the TLS-HS.
 *  \param[in]     SocketTcpIdx          Index of a TCP socket that is in state listen.
 *                                       \spec requires SocketTcpIdx < TcpIp_GetSizeOfSocketTcpDyn(); \endspec
 *  \param[in]     ConnectedSocketTcpIdx Index of a newly allocated TCP socket that represents the accepted connection.
 *                                       \spec requires ConnectedSocketTcpIdx < TcpIp_GetSizeOfSocketTcpDyn(); \endspec
 *  \return        E_OK                  Upper layer has accepted the new connection.
 *  \return        E_NOT_OK              Upper layer has rejected the new connection.
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls12CoreLl_TcpAccepted(
  TcpIp_SocketTcpDynIterType      SocketTcpIdx,
  TcpIp_SocketTcpDynIterType      ConnectedSocketTcpIdx);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_Tls12Msg_GetLenOfCurveSpecificSignature
 *********************************************************************************************************************/
/*! \brief         Returns the length of the signature of the given curve
 *  \details       -
 *  \param[in]     CurveId   RFC Curve identifier
 *  \return        Length of the signature, 0 if curve ID is not supported.
 *  \pre           -
 *  \context       TASK|ISR
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 ********************************************************************************************************************/
FUNC(uint32, TCPIP_CODE) TcpIp_Tls12Msg_GetLenOfCurveSpecificSignature(
  CONST(TcpIp_TlsEllipticCurveIdType, AUTOMATIC) CurveId);

/**********************************************************************************************************************
 * TcpIp_Tls12Msg_GetLenOfCurveSpecificDhSharedKey
 *********************************************************************************************************************/
/*! \brief         Returns the length of the shared key of the given curve
 *  \details       -
 *  \param[in]     CurveId   RFC Curve identifier
 *  \return        Length of the shared key, 0 if curve ID is not supported.
 *  \pre           -
 *  \context       TASK|ISR
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(uint32, TCPIP_CODE) TcpIp_Tls12Msg_GetLenOfCurveSpecificDhSharedKey(
  CONST(TcpIp_TlsEllipticCurveIdType, AUTOMATIC) CurveId);

/**********************************************************************************************************************
 * TcpIp_Tls12Msg_GetNumOfReceivedCertificates
 *********************************************************************************************************************/
/*! \brief         Obtain the number of certificates in the received certificate chain when using TLS 1.2
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     CertStartIdx       Start Idx of the certificate data
 *  \param[in]     CertChainLen       Length of the certificate chain
 *  \param[in]     CertificateMsgLen  Length of the whole certificate message
 *  \param[out]    NumCertPtr         Number of certificates in the chain
 *  \return        E_OK               Operation successful
 *  \return        E_NOT_OK           Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls12Msg_GetNumOfReceivedCertificates(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferRxIterType   CertStartIdx,
  uint32                      CertChainLen,
  uint16                      CertificateMsgLen,
  TCPIP_P2V(uint8)            NumCertPtr);

/**********************************************************************************************************************
 * TcpIp_Tls12Msg_RecCertMsgCheckLengthAndReadCertNum
 *********************************************************************************************************************/
/*! \brief         Check the length of the certificate message and read the number of certificates.
 *  \details       -
 *  \param[in]     TlsConIdx                 TLS connection index
 *                                           \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     CertificateMsgLen         Length of the whole certificate message
 *  \param[out]    CertificateChainLenPtr    Length of the certificate chain
 *  \param[out]    NumCertsPtr               Number of received certificates
 *  \return        E_OK                      Operation successful
 *  \return        E_NOT_OK                  Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls12Msg_RecCertMsgCheckLengthAndReadCertNum(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 CertificateMsgLen,
  TCPIP_P2V(uint16) CertificateChainLenPtr,
  TCPIP_P2V(uint8) NumCertsPtr);

/**********************************************************************************************************************
 * TcpIp_Tls12CoreCtx_CalcDhSharedSecret
 *********************************************************************************************************************/
/*! \brief         Asynchronous handler for calculation the Diffie-Hellman shared secret
 *  \details       -
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK (only called in the context of the TLS background task TcpIp_Tls_MainFunctionLowPrio())
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 ********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls12CoreCtx_CalcDhSharedSecret(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif /* TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

#   if ((TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON) || (TCPIP_SUPPORT_ASRTLSCLIENT_PSK == STD_ON))
/**********************************************************************************************************************
 * TcpIp_Tls12CoreCtx_CalcPskPremasterSecret
 *********************************************************************************************************************/
/*! \brief         Asynchronous handler for calculation the TLS pre master secret
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK (only called in the context of the TLS background task TcpIp_Tls_MainFunctionLowPrio())
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls12CoreCtx_CalcPskPremasterSecret(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif /* (TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON) || (TCPIP_SUPPORT_ASRTLSCLIENT_PSK == STD_ON) */

/**********************************************************************************************************************
 * TcpIp_Tls12CoreCtx_CalcMasterSecret
 *********************************************************************************************************************/
/*! \brief         Asynchronous handler for calculation the TLS master secret
 *  \details       -
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK (only called in the context of the TLS background task TcpIp_Tls_MainFunctionLowPrio())
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 ********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls12CoreCtx_CalcMasterSecret(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls12CoreCrypto_DecryptFromConstSegmentSafe()
 *********************************************************************************************************************/
/*! \brief         Decrypts the given encrypted data and stores the decrypted plaintext in the Tls Rx buffer.
 *  \details       The encrypted data is given as a const buffer segment.
 *  \param[in]     JobId              Holds the identifier of the job using the CSM service.
 *  \param[in]     Mode               Indicates which operation mode(s) to perform.
 *  \param[in]     DataSegPtr         Contains the pointer to the buffer segment with data to be decrypted.
 *  \param[in]     DataLength         Contains the number of bytes to decrypt.
 *  \param[in]     WriteIdx           Contains the index of the Tls Rx buffer where the data shall be copied to.
 *  \param[in,out] ResultLengthPtr    Holds a pointer to the memory location in which the output length information is
 *                                    stored in bytes. On calling this function, this parameter shall contain the size
 *                                    of the Tls Rx buffer area. When the request has finished, the actual length of
 *                                    the returned value shall be stored.
 *  \return        E_OK                   Request successful
 *                 E_NOT_OK               Request failed
 *                 CRYPTO_E_BUSY          Request failed, service is busy
 *                 CRYPTO_E_QUEUE_FULL    Request failed, the queue is full
 *                 CRYPTO_E_SMALL_BUFFER  The provided buffer is too small to store the result
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls12CoreCrypto_DecryptFromConstSegmentSafe(
  uint32                      JobId,
  Crypto_OperationModeType    Mode,
  TcpIp_ConstSegmentPtrType   DataSegPtr,
  uint32                      DataLength,
  uint32                      WriteIdx,
  TCPIP_P2V(uint32)           ResultLengthPtr);

/**********************************************************************************************************************
 *  TcpIp_Tls12CoreCrypto_DecryptSafe()
 *********************************************************************************************************************/
/*! \brief         Decrypts the given encrypted data and stores the decrypted plaintext in the Tls Rx buffer.
 *  \details       -
 *  \param[in]     JobId              Holds the identifier of the job using the CSM service.
 *  \param[in]     Mode               Indicates which operation mode(s) to perform.
 *  \param[in]     DataPtr            Contains the pointer to the data to be decrypted.
 *  \param[in]     DataLength         Contains the number of bytes to decrypt.
 *  \param[in]     WriteIdx           Contains the index of the Tls Rx buffer where the data shall be copied to.
 *  \param[in,out] ResultLengthPtr    Holds a pointer to the memory location in which the output length information is
 *                                    stored in bytes. On calling this function, this parameter shall contain the size
 *                                    of the Tls Rx buffer area. When the request has finished, the actual length of
 *                                    the returned value shall be stored.
 *  \return        E_OK                   Request successful
 *                 E_NOT_OK               Request failed
 *                 CRYPTO_E_BUSY          Request failed, service is busy
 *                 CRYPTO_E_QUEUE_FULL    Request failed, the queue is full
 *                 CRYPTO_E_SMALL_BUFFER  The provided buffer is too small to store the result
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls12CoreCrypto_DecryptSafe(
  uint32                   JobId,
  Crypto_OperationModeType Mode,
  TCPIP_P2C(uint8)         DataPtr,
  uint32                   DataLength,
  uint32                   WriteIdx,
  TCPIP_P2V(uint32)        ResultLengthPtr);

/**********************************************************************************************************************
 *  TCPIP TLS CORE MASTER SECRET ACCESS (MSA)
 *********************************************************************************************************************/
#   if ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON))
/**********************************************************************************************************************
 *  TcpIp_Tls12Core_ClearMasterSecretBuffer
 *********************************************************************************************************************/
/*! \brief         Clear the buffer, used to read the Client random and Session id.
 *  \details       -
 *  \param[in]     TlsConIdx
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls12Core_ClearMasterSecretBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls12Core_ReadHandshakeParameter
 *********************************************************************************************************************/
/*! \brief        User can read Master Secret Key, Client Random number and Session Id.
 *  \details       -
 *  \param[in]     SocketIdx          Socket identifier of the related local socket resource.
 *  \param[in,out] MasterSecretPtr    Pointer to the user buffer, where Master Secret Key shall be stored.
 *  \param[in,out] ClientRandomPtr    Pointer to the user buffer, where Client Random Number shall be stored.
 *  \param[in,out] SessionIdPtr       Pointer to the user buffer, whereSession Id shall be stored.
 *  \param[in,out] SessionIdLenPtr    Pointer to the Session Id Length.
 *  \return        E_OK               if reading is successful.
 *                 E_NOT_OK           Problem occurred at CSM during reading of master secret.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls12Core_ReadHandshakeParameter(
  TcpIp_SocketDynIterType SocketIdx,
  TCPIP_P2V(uint8)        MasterSecretPtr,
  TCPIP_P2V(uint8)        ClientRandomPtr,
  TCPIP_P2V(uint8)        SessionIdPtr,
  TCPIP_P2V(uint8)        SessionIdLenPtr);
#   endif /* ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON)) */

#   if (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls12CoreMainFunction_TxNss
 *********************************************************************************************************************/
/*! \brief         Main function for processing the transmittable NSS Key Log frame for the TLS 1.2 secrets
 *  \details       -
 *  \param[in]     TlsConIdx                    TLS connection index
 *                                              \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls12CoreMainFunction_TxNss(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif /* (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON) */

#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
# endif /* (TCPIP_SUPPORT_ASRTLS == STD_ON) */
#endif /* TCPIP_TLS12CORE_H */
/**********************************************************************************************************************
 *  END OF FILE: TcpIp_Tls12Core.h
 *********************************************************************************************************************/
