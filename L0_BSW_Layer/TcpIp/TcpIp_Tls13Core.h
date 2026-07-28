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
/*!        \file  TcpIp_Tls13Core.h
 *        \brief  Transport Layer Security (TLS) 1.3 core functions implementation.
 *
 *      \details  This file is part of the TcpIp TLS submodule.
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp module. >> TcpIp.h
 **********************************************************************************************************************/

#if !defined (TCPIP_TLS13CORE_H)
# define TCPIP_TLS13CORE_H

# include "TcpIp_Cfg.h"

# if (TCPIP_SUPPORT_ASRTLS == STD_ON)                                                                                   /* COV_MSR_UNSUPPORTED */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#   include "TcpIp_Lcfg.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

 /* TLS 1.3 Sequence number offsets */
#   define TCPIP_TLS13_ADD_SEQNUM_OFFSET                         (TCPIP_TLS13_AEADBLOCK128_IV_LEN - 8u) /* Offset for Sequence number */

/* TLS 1.3 Certificate message information */
#   define TCPIP_TLS13_CERTREQCONTEXT_LEN                        1u /* Length of the certificate_request_context */

/* TLS 1.3 only - RFC 8446 section 4.2. */
#   define TCPIP_TLS_EXTENSION_TYPE_SIGNATURE_ALGORITHMS                               13u
#   define TCPIP_TLS_EXTENSION_TYPE_CERTIFICATE_AUTHORITIES                            47u
#   define TCPIP_TLS_EXTENSION_TYPE_SIGNATURE_ALGORITHMS_CERT                          50u

#   define TCPIP_TLS_EXTENSION_KEY_SHARE_GROUP_LEN                                     2u
#   define TCPIP_TLS_EXTENSION_KEY_SHARE_KEY_LENGTH_LEN                                2u
#   define TCPIP_TLS_EXTENSION_KEY_SHARE_KEY_MIN_LEN                                   1u

/* TLS 1.3 only - RFC 8446 section 4.2.4. */
#   define TCPIP_TLS_EXTENSION_CERTIFICATE_AUTHORITIES_LENGTH                          2u
#   define TCPIP_TLS_EXTENSION_CERTIFICATE_AUTHORITIES_MIN_DATA_LEN                    3u

/* TLS 1.3 key sizes for AEAD Aes128 Gcm */
/* RFC 8446, 5.3. Per-Record Nonce:
 * The length of the TLS per-record nonce (iv_length) is set to the larger of 8 bytes and N_MIN = 12
 * for the AEAD algorithm (see [RFC5116], Section 4) => iv_length = 12 */
#   define TCPIP_TLS13_AES128_GCM_NONCE_LEN  TCPIP_AEAD_AES_128_GCM_N_MIN_LEN /* Length of the per-record nonce for Aes128 Gcm */

/* TLS 1.3 block128 size */
#   define TCPIP_TLS13_BLOCK128_NONCE_LEN   12u /* Length of the per-record nonce */
#   define TCPIP_TLS13_AEADBLOCK128_IV_LEN  TCPIP_TLS13_AES128_GCM_NONCE_LEN /* The iv length equals the nonce length */

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
 * TcpIp_Tls13CoreCrypto_HashIntoSegment
 *********************************************************************************************************************/
/*! \brief         Wrapper for the Csm_Hash() function where the output should be written into a buffer segment
 *  \details       If the Csm did write data into the segment, TcpIp_SegmentCommit is called to maintain its fill level
 *  \param[in]     TlsConIdx                      TLS connection index
 *                                                CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     CsmHashJobId                   The Id of the Csm hash job
 *  \param[in]     DataToHashPtr                  The pointer to the input data for the hash operation
 *  \param[in]     DataToHashLength               The length of the input data
 *  \param[in]     ExpectedHashLength             The expected length of the calculated hash
 *  \param[in,out] TargetSegmentPtr               Pointer to a buffer segment where the output data shall be written to
 *  \return        E_OK                           Operation successful
 *  \return        E_NOT_OK                       Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCrypto_HashIntoSegment(
  TcpIp_TlsConnectionIterType                     TlsConIdx,
  TcpIp_CsmJobIdType                              CsmHashJobId,
  Crypto_OperationModeType                        CsmOperationMode,
  TCPIP_P2C(uint8)                                DataToHashPtr,
  uint32                                          DataToHashLength,
  uint32                                          ExpectedHashLength,
  TcpIp_SegmentPtrType                            TargetSegmentPtr);

#   if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_CalcDhSharedSecret
 *********************************************************************************************************************/
/*! \brief         Calculates the ECDH shared secret.
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13CoreCtx_CalcDhSharedSecret(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_CalcPskValue
 *********************************************************************************************************************/
/*! \brief         Calculates the PSK value.
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK                Calculating PSK successful.
 *  \return        E_NOT_OK            Calculating PSK failed.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_CalcPskValue(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_HkdfExpandLabel
 *********************************************************************************************************************/
/*! \brief          This function creates the HKDF-Label according RFC 8446 section 7.1 and executes the
 *                  HKDF-Expand function (RFC 5869).
 *  \details        -
 *  \param[in]      HkdfExpandInputPtr   Pointer to the input needed for the HKDF expand calculation
 *  \param[in]      LabelPtr             A pointer to the label that should be used for the HKDF-Label
 *  \param[in]      LabelLen             The length of the label
 *  \param[in]      ContextPtr           A pointer to the context that should be used for the HKDF-Label
 *  \param[in]      ContextLen           The length of the context
 *  \return         E_OK                 Expand label was successful
 *  \return         E_NOT_OK             Expand label failed
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_HkdfExpandLabel(
  TCPIP_P2C(TcpIp_Tls13_HkdfExpandInput_Type) HkdfExpandInputPtr,
  TCPIP_P2C(uint8) LabelPtr,
  uint8 LabelLen,
  TCPIP_P2C(uint8) ContextPtr,
  uint8 ContextLen);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DeleteConnectionKeys
 *********************************************************************************************************************/
/*! \brief         Deletes all keys used for this connection
 *  \details       Requirements defined in ISO15118-20: [V2G20-2046]+ [V2G20-2047]
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                Operation successful
 *  \return        E_NOT_OK            Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_DeleteConnectionKeys(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_SwitchToApplicationKeyRx
 *********************************************************************************************************************/
/*! \brief         Calculates the TLS 1.3 application traffic keys and switches to the calculated decrypt key
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK                Successfully calculated and switched to application keys
 *  \return        E_NOT_OK            Operation failed
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_SwitchToApplicationKeyRx(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_SwitchToHandshakeKeys
 *********************************************************************************************************************/
/*! \brief         Calculates the TLS 1.3 handshake traffic keys and switches to those calculated keys
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK                Successfully calculated and switched to handshake keys
 *  \return        E_NOT_OK            Operation failed
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_SwitchToHandshakeKeys(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DerivePskBinderKey
 *********************************************************************************************************************/
/*! \brief         Derives the binder key to calculate a PskBinderEntry for the pre_shared_key extension
 *  \details       -
 *  \param[in]     TlsConIdx  TLS connection index
 *                            CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     HashLength Length of the used hash algorithm
 *  \return        E_OK       Binder key was calculated successfully
 *  \return        E_NOT_OK   Failure during derivation of binder key
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_DerivePskBinderKey(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8                       HashLength);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_CalcApplicationKeys
 *********************************************************************************************************************/
/*! \brief         Calculates the TLS 1.3 application traffic keys and IV on basis of the shared and derived secret
 *                 which have been calculated by TcpIp_Tls13CoreCtx_CalcHandshakeKeys()
 *  \details       Application traffic keys and IV are saved in the CSM encrypt / decrypt key container
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           TcpIp_Tls13CoreCtx_CalcHandshakeKeys() must have been invoked earlier
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13CoreCtx_CalcApplicationKeys(TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_CopyKeyAndIv
 *********************************************************************************************************************/
/*! \brief         Copies the Key elements 'Key' and 'Iv' from the passed source Csm key to the passed target Csm key
 *  \details       -
 *  \param[in]     SourceCsmKeyId           Id for the Csm key whose key elements shall be copied
 *  \param[in]     TargetCsmKeyId           Id for the Csm key where the key elements shall be modified
 *  \return        E_OK                     Operation successful
 *  \return        E_NOT_OK                 Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_CopyKeyAndIv(
  TcpIp_CsmKeyIdType  SourceCsmKeyId,
  TcpIp_CsmKeyIdType  TargetCsmKeyId);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreRl_HandleHsMsgNotAlignedWithRlBoundary
 *********************************************************************************************************************/
/*! \brief          This function handles the reception of a handshake message which is not aligned with a RL boundary.
 *  \details        Check if the message precedes a key change. In case the active version is set to 1.3, just send
 *                  an alert. If the active version is not determined yet, set a flag which delays sending the alert
 *                  to when the active version is set. If the active version is 1.2, nothing shall be done.
 *  \param[in]      TlsConIdx            TLS connection index
 *                                       \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return         E_OK                 Currently no protocol violation regarding a message preceding a key change
 *  \return         E_NOT_OK             Message preceding a key change was NOT aligned with a RL boundary in TLS 1.3
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreRl_HandleHsMsgNotAlignedWithRlBoundary(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DeriveResumptionMasterSecret
 *********************************************************************************************************************/
/*! \brief         Derives the resumption master secret for a resumption base connection.
 *  \details       A possible error is handled directly in this function
 *  \param[in]     TlsConIdx              TLS connection index
 *                                        CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13CoreCtx_DeriveResumptionMasterSecret(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13Core_GetHashLengthOfActiveCipherSuite
 *********************************************************************************************************************/
/*! \brief         Determines the length of the hash algorithm used in currently active cipher suite.
 *  \details       -
 *  \param[in]     TlsConIdx              TLS connection index
 *                                        CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[out]    CipherSuiteHashLenPtr  The hash length in number of bytes.
 *  \return        E_OK                   Length of hash algorithm could be determined successfully
 *  \return        E_NOT_OK               No valid hash length found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Core_GetHashLengthOfActiveCipherSuite(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint8) CipherSuiteHashLenPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13Core_GetHashAlgorithmOfActiveCipherSuite
 *********************************************************************************************************************/
/*! \brief         Determines the hash algorithm used in currently active cipher suite.
 *  \details       -
 *  \param[in]     TlsConIdx              TLS connection index
 *                                        CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[out]    CipherSuiteHashAlgoPtr Pointer to the determined hash algorithm.
 *  \return        E_OK                   Hash algorithm could be determined successfully.
 *  \return        E_NOT_OK               Not able to determine hash algorithm.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Core_GetHashAlgorithmOfActiveCipherSuite(
  TcpIp_TlsConnectionIterType           TlsConIdx,
  TCPIP_P2V(TcpIp_TlsHashAlgorithmType) CipherSuiteHashAlgoPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13Core_GetCipherSuiteHashAlgorithm
 *********************************************************************************************************************/
/*! \brief         Determines the hash algorithm used in passed cipher suite.
 *  \details       -
 *  \param[in]     CipherSuiteId          Cipher suite Id for which the hash algorithm shall be determined
 *  \param[out]    CipherSuiteHashAlgoPtr Pointer to the determined hash algorithm
 *  \return        E_OK                   Hash algorithm could be determined successfully
 *  \return        E_NOT_OK               Passed ciphersuite was invalid, hash algorithm could not be determined
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Core_GetCipherSuiteHashAlgorithm(
  TcpIp_TlsCipherDataType                 CipherSuiteId,
  TCPIP_P2V(TcpIp_TlsHashAlgorithmType)   CipherSuiteHashAlgoPtr);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreRl_AddInnerPlaintextContentTypeIfNecessary
 *********************************************************************************************************************/
/*! \brief          Check if in the current message an inner plain text ContentType is necessary
 *  \details        If the inner plain text ContentType is necessary,
 *                  call TcpIp_Tls13CoreRl_AddInnerPlaintextContentType() to add it to the message
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]      TxStartIdx          Start index within the TlsTxBuffer of the transmittable frame
 *  \param[in,out]  TxLenPtr            Pointer to the length of the transmittable frame
 *  \param[in,out]  ContentTypePtr      Pointer to the Record Layer ContentType of the transmittable frame
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13CoreRl_AddInnerPlaintextContentTypeIfNecessary(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferTxIterType TxStartIdx,
  TCPIP_P2V(TcpIp_SizeOfTlsBufferTxType) TxLenPtr,
  TCPIP_P2V(uint8) ContentTypePtr);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreRl_ProcessAdFrameAfterDecryption
 *********************************************************************************************************************/
/*! \brief          Process the received application data frame after it was successfully decrypted
 *  \details        For example the inner plain text ContentType is read
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in,out]  PlaintextLenPtr         Pointer to the plaintext length of the application data frame
 *  \return         E_OK                    Frame successfully processed
 *  \return         E_NOT_OK                Processing of frame failed - unexpected message alert will be sent by caller
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreRl_ProcessAdFrameAfterDecryption(
  TcpIp_TlsConnectionIterType                            TlsConIdx,
  TCPIP_P2V(TcpIp_RlRxCopiedLenOfTlsBufferMgmtDynType)   PlaintextLenPtr);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreRl_ProcessHsFrame
 *********************************************************************************************************************/
/*! \brief          Process an decrypted application data frame with inner plain text ContentType handshake
 *  \details        Handshake messages received after the handshake is complete are directly handled here. For Hs
 *                  messages received during the handshake the parsing is skipped and will be done in the Hs context.
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]      HsType                  Received handshake type
 *  \param[in]      HsLen                   Received handshake length
 *  \param[in]      SourceSegment1Ptr       Pointer to a buffer segment containing the first part of the Hs message
 *  \param[in]      SourceSegment2Ptr       Pointer to a buffer segment containing the second part of the Hs message
 *                                          It is already checked that both segments together contain HsLen bytes
 *  \param[out]     HsMsgAlreadySkippedPtr  Boolean which indicates if data of HsMsg is already processed/skipped in segments
 *  \return         E_OK                    Message successfully processed
 *  \return         E_NOT_OK                Processing of message failed
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreRl_ProcessHsFrame(
  TcpIp_TlsConnectionIterType                 TlsConIdx,
  uint8                                       HsType,
  uint32                                      HsLen,
  TcpIp_ConstSegmentPtrType                   SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                   SourceSegment2Ptr,
  TCPIP_P2V(boolean)                          HsMsgAlreadySkippedPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13Core_ExtractHsHeaderInformationFromMultiConstSegment
 *********************************************************************************************************************/
/*! \brief         Extract handshake header information from two const segments.
 *  \details       With the two const segments a possible wraparound can be handled.
 *  \param[in]     SourceSegment1Ptr          First buffer segment (wraparound case: data at the end of the buffer)
 *  \param[in]     SourceSegment2Ptr          Second buffer segment (wraparound case: data at the start of the buffer)
 *  \param[out]    HsTypePtr                  Pointer to the read handshake type
 *  \param[out]    HsLenPtr                   Pointer to the read handshake length
 *  \return        E_OK                       Segments have enough space for the HS header,
 *                                            the handshake type and length were read but not checked for validity
 *  \return        E_NOT_OK                   Segments don't have enough space for a complete HS header,
 *                                            neither the handshake type nor the handshake length have been read
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Core_ExtractHsHeaderInformationFromMultiConstSegment(
  TcpIp_ConstSegmentPtrType                   SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                   SourceSegment2Ptr,
  TCPIP_P2V(uint8)                            HsTypePtr,
  TCPIP_P2V(uint32)                           HsLenPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13CoreCrypto_GenerateAEADBlock128Iv
 *********************************************************************************************************************/
/*! \brief         Generate the Iv for Gcm and set the CSM key when TLS 1.3 is used
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     Encrypt             Signalizes if encryption or decryption values shall be used
 *  \return        E_OK                Operation successful
 *  \return        E_NOT_OK            Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCrypto_GenerateAEADBlock128Iv(
  TcpIp_TlsConnectionIterType TlsConIdx,
  boolean                     Encrypt);

/**********************************************************************************************************************
 * TcpIp_Tls13Core_GetCipherSuiteHashLength
 *********************************************************************************************************************/
/*! \brief         Determines the length of the hash algorithm used in passed cipher suite.
 *  \details       -
 *  \param[in]     CipherSuiteId          Cipher suite Id for which the hash length shall be determined
 *  \param[out]    CipherSuiteHashLenPtr  The hash length in number of bytes.
 *  \return        E_OK                   Length of hash algorithm could be determined successfully
 *  \return        E_NOT_OK               No valid hash length found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Core_GetCipherSuiteHashLength(
  TcpIp_TlsCipherDataType     CipherSuiteId,
  TCPIP_P2V(uint8)            CipherSuiteHashLenPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13Core_GetCipherSuiteFromActiveCipherWorker
 *********************************************************************************************************************/
/*! \brief         Gets the cipher suite Id either from the from the active Rx / Tx cipher if already set
 *                 or otherwise from the active cipherworker when set
 *  \details       -
 *  \param[in]     TlsConIdx              TLS connection index
 *                                        CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[out]    CipherSuiteIdPtr       The active cipher suite Id
 *  \return        E_OK                   Active cipher suite Id could be determined successfully
 *  \return        E_NOT_OK               Either no active cipher or different active ciphers for Rx / Tx
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Core_GetCipherSuiteFromActiveCipherWorker(
  TcpIp_TlsConnectionIterType        TlsConIdx,
  TCPIP_P2V(TcpIp_TlsCipherDataType) CipherSuiteIdPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13Core_HandleExpiredTls13PskIdentity
 *********************************************************************************************************************/
/*! \brief         Resets the passed TLS 1.3 PSK identity in case its lifetime has expired.
 *  \details       -
 *  \param[in]     Tls13PskIdentityIdx    Index of the TLS 1.3 PSK identity whose lifetime has expired.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13Core_HandleExpiredTls13PskIdentity(
  TcpIp_Tls13PskIdentityIterType          Tls13PskIdentityIdx);

/**********************************************************************************************************************
 * TcpIp_Tls13Core_GetTlsConnectionWithThisActivePskIdentity
 *********************************************************************************************************************/
/*! \brief         Gets the TLS connection index which has the passed TLS 1.3 PSK identity index set as active.
 *  \details       Found TLS connection must support session resumption as a resumed connection.
 *  \param[in]     Tls13PskIdentityIdx    TLS 1.3 PSK identity index for which the TLS connection shall be found.
 *  \param[out]    FoundTlsConIdxPtr      The found TLS connection index.
 *  \return        E_OK                   TLS connection found with matching active TLS 1.3 PSK identity.
 *  \return        E_NOT_OK               No TLS connection with a matching active TLS 1.3 PSK identity available.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Core_GetTlsConnectionWithThisActivePskIdentity(
  TcpIp_Tls13PskIdentityIterType          Tls13PskIdentityIdx,
  TCPIP_P2V(TcpIp_TlsConnectionIterType)  FoundTlsConIdxPtr);

/**********************************************************************************************************************
 *  TcpIp_Tls13Core_InitializePskIdentity
 *********************************************************************************************************************/
/*! \brief         Initialize the PSK identity with the passed index
 *  \details       -
 *  \param[in]     Tls13PskIdentityIdx  Index of the TLS PSK identity which is to be initialized
 *                                      \spec requires Tls13PskIdentityIdx < TcpIp_GetSizeOfTls13PskIdentity(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13Core_InitializePskIdentity(
  TcpIp_Tls13PskIdentityIterType Tls13PskIdentityIdx);

#   if (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13CoreMainFunction_TxNss
 *********************************************************************************************************************/
/*! \brief         Main function for processing the transmittable NSS Key Log frame for the TLS 1.3 secrets
 *  \details       -
 *  \param[in]     TlsConIdx                    TLS connection index
 *                                              \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Tls13CoreMainFunction_TxNss(
  TcpIp_TlsConnectionIterType TlsConIdx);
#   endif /* (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON) */

#   if (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON)
/**********************************************************************************************************************
 * TcpIp_Tls13Core_ReadHandshakeAndApplicationTrafficSecrets
 *********************************************************************************************************************/
/*! \brief        User can read Application/Handshake Traffic secrets + Client Random
 *  \details       -
 *  \param[in]     TlsConIdx              TLS connection index
 *                                        \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] Tls13_MasterSecretPtr  Pointer to the user buffer, where the secrets and client random will be stored.
 *  \return        E_OK                   if reading is successful.
 *                 E_NOT_OK               Problem occurred at CSM during reading of master secret.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Core_ReadHandshakeAndApplicationTrafficSecrets(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(TcpIp_Tls13_Secret_Type) Tls13_MasterSecretPtr);
#   endif

#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
# endif /* (TCPIP_SUPPORT_ASRTLS == STD_ON) */
#endif /* TCPIP_TLS13CORE_H */
/***********************************************************************************************************************
 *  END OF FILE: TcpIp_Tls13Core.h
 **********************************************************************************************************************/
