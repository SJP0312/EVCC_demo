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
/*!        \file  TcpIp_Tls13Core.c
 *        \brief  Transport Layer Security (TLS) 1.3 core functions implementation.
 *
 *      \details  This file implements the core routines of the TLS 1.3 stack, which is used by
 *                the Tls13Client. This file is part of the TcpIp TLS submodule.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp module. >> TcpIp.h
 *********************************************************************************************************************/

#define TCPIP_TLS13CORE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TcpIp_Cfg.h"

#if (TCPIP_SUPPORT_ASRTLS == STD_ON)                                                                                    /* COV_MSR_UNSUPPORTED */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#  include "TcpIp_Tls.h"
#  include "TcpIp_Tls13Core.h"
#  include "TcpIp_TlsCoreCommon.h"
#  include "TcpIp_TlsPriv.h"

#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
#   include "TcpIp_Tls13Client.h"
#  endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */

#  include "TcpIp_Types.h"
#  include "TcpIp_Lcfg.h"
#  include "vstdlib.h"

#  if (TCPIP_DEV_ERROR_REPORT == STD_ON)
#   include "Det.h"
#  endif /* (TCPIP_DEV_ERROR_REPORT == STD_ON) */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

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
/* Size equals the maximum length of the HkdfLabel:
 *
 * Length (2 Bytes) + Label length (1 Byte) +  Label (12 Bytes) + Context length (1 Byte) + Context (TCPIP_TLS_HASH_SHA512_LEN)
 *
 * */
#  define MAX_SIZE_OF_HKDF_LABEL                                      (TCPIP_TLS_HASH_SHA512_LEN + 16u)

#  define TCPIP_TLS_INITIAL_PASSWORD_PLAIN_PATTERN                    0u
#  define TCPIP_TLS_HKDF_SECRET_LEN                                   32u

 /* TLS 1.3 HKDF Key Schedule label element lengths (RFC 8446 - 7.1. Key Schedule) */
#  define TCPIP_TLS_HKDFLABEL_LENGTH_LEN                              2u   /* length of the "length" field */
#  define TCPIP_TLS_HKDFLABEL_LABEL_LEN_LEN                           1u   /* length of the "label" length */
#  define TCPIP_TLS_HKDFLABEL_CONTEXT_LEN_LEN                         1u   /* length of the "context" length */

#  define TCPIP_TLS_HKDF_ITERATION_MODE_LEN                           1u   /* length of the extract and expand iteration mode */

/* TLS 1.3 labels used for key derivation */
#  define TCPIP_TLS_ASCII_CHAR_SPACE                                  0x20  /* whitespace */
#  define TCPIP_TLS_ASCII_CHAR_LEN                                    1u    /* single character length */

/* lengths of below constant strings */
#  define TCPIP_TLS_HS_TLS13LABEL_TLS13_LEN                           5u
#  define TCPIP_TLS_HS_TLS13LABEL_DERIVED_LEN                         7u
#  define TCPIP_TLS_HS_TLS13LABEL_HSTRAFFIC_LEN                       12u
#  define TCPIP_TLS_HS_TLS13LABEL_APTRAFFIC_LEN                       12u
#  define TCPIP_TLS_HS_TLS13LABEL_RESMASTERSECRET_LEN                 10u
#  define TCPIP_TLS_HS_TLS13LABEL_RESBINDERKEY_LEN                    10u
#  define TCPIP_TLS_HS_TLS13LABEL_KEY_LEN                             3u
#  define TCPIP_TLS_HS_TLS13LABEL_IV_LEN                              2u
#  define TCPIP_TLS_HS_TLS13LABEL_RESUMPTION_LEN                      10u

/* This define shall have the same value as CRYPTO_30_LIBCV_KE_TARGET_KEY
 * which we can't use directly since we have no access to it. */
#  define TCPIP_CRYPTO_30_LIBCV_KE_TARGET_KEY                         1u

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
#  define TCPIP_START_SEC_CONST_8
#  include "TcpIp_MemMap.h"                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3218 12 */ /* MD_TCPIP_Rule8.9_3218 */
/* Labels according to RFC8446 chapter 7.1 */
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_Hs_Tls13Label_Tls13[] = "tls13"; /* The whitespace is not included in this label, add TCPIP_TLS_ASCII_CHAR_SPACE afterwards. */
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_Hs_Tls13Label_Derived[] = "derived";
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_Hs_Tls13Label_SHsTraffic[] = "s hs traffic";
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_Hs_Tls13Label_CHsTraffic[] = "c hs traffic";
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_Hs_Tls13Label_SApTraffic[] = "s ap traffic";
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_Hs_Tls13Label_CApTraffic[] = "c ap traffic";
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_Hs_Tls13Label_ResMasterSecret[] = "res master";  /* (session) resumption master secret */
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_Hs_Tls13Label_ResBinderKey[] = "res binder";  /* binder key calculation for resumption PSK */
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_Hs_Tls13Label_Key[] = "key";
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_Hs_Tls13Label_Iv[] = "iv";
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_Hs_Tls13Label_Resumption[] = "resumption";

#  define TCPIP_STOP_SEC_CONST_8
#  include "TcpIp_MemMap.h"                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#  define TCPIP_START_SEC_CODE
#  include "TcpIp_MemMap.h"                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DeriveSecretAndShortenHkdfKey
 *********************************************************************************************************************/
/*! \brief          Derive the secrets for the TLS 1.3 handshake and subsequently shorten the Hkdf key
 *  \details        -
 *  \param[in]      TlsConIdx            TLS connection index
 *  \param[in]      DeriveSecretInputPtr Pointer to the input needed for the derive secret calculation
 *  \param[in]      LabelPtr             A pointer to the label that should be used for the key calculation
 *  \param[in]      LabelLen             The length of the label
 *  \param[in]      HashMessages         A boolean that indicates if the hash of all handshake messages should be used
 *                                       for the key calculation (TRUE) or if the hash of an empty string is used (FALSE).
 *                                       For details check the RFC 8446 section 7.1
 *  \return         E_OK                 Operation successful
 *  \return         E_NOT_OK             Operation NOT successful
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_DeriveSecretAndShortenHkdfKey(
  TcpIp_TlsConnectionIterType                     TlsConIdx,
  TCPIP_P2C(TcpIp_Tls13_DeriveSecretInput_Type)   DeriveSecretInputPtr,
  TCPIP_P2C(uint8)                                LabelPtr,
  uint8                                           LabelLen,
  boolean                                         HashMessages);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_CalcHashAndCreateHkdfLabel
 *********************************************************************************************************************/
/*! \brief          Calculate the hash and creates a HKDF Label for key derivation in TLS 1.3.
 *  \details        This function calculates the hash of the handshake messages, if necessary, and creates a HKDF label
 *                  which is provided as AdditionalInfo for the key derivation in TLS 1.3.
 *  \param[in]      TlsConIdx            TLS connection index
 *  \param[in]      DeriveSecretInputPtr Pointer to the input needed for the derive secret calculation
 *  \param[in,out]  HkdfLabelSegmentPtr  A pointer to the buffer of the HKDF-label which should be created
 *  \param[in]      LabelPtr             A pointer to the label that should be used for the key calculation
 *  \param[in]      LabelLen             The length of the label
 *  \param[in]      HashMessages         A boolean that indicates if the hash of all handshake messages should be used
 *                                       for the key calculation (TRUE) or if the hash of an empty string is used (FALSE).
 *                                       For details check the RFC 8446 section 7.1
 *  \return         E_OK                 Calculation of hash and creation of HKDF label was successful
 *  \return         E_NOT_OK             At least one CSM call failed
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_CalcHashAndCreateHkdfLabel(
  TcpIp_TlsConnectionIterType                     TlsConIdx,
  TCPIP_P2C(TcpIp_Tls13_DeriveSecretInput_Type)   DeriveSecretInputPtr,
  TcpIp_SegmentPtrType                            HkdfLabelSegmentPtr,
  TCPIP_P2C(uint8)                                LabelPtr,
  uint8                                           LabelLen,
  boolean                                         HashMessages);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_HkdfCreateLabel
 *********************************************************************************************************************/
/*! \brief          This function creates the HKDF-Label according RFC 8446 section 7.1.
 *  \details        -
 *  \param[in,out]  HkdfLabelSegmentPtr  A pointer to the buffer segment of the HKDF-label which should be created
 *  \param[in]      OutputKeyLen         The length of output keying material
 *  \param[in]      LabelPtr             A pointer to the label that should be used for the HKDF-Label
 *  \param[in]      LabelLen             The length of the label
 *  \param[in]      ContextSegmentPtr    A pointer to the buffer segment of the context that should be used.
 *                                       If there is no context to be added a NULL_PTR can be passed here.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13CoreCtx_HkdfCreateLabel(
  TcpIp_SegmentPtrType                 HkdfLabelSegmentPtr,
  uint16                               OutputKeyLen,
  TCPIP_P2C(uint8)                     LabelPtr,
  uint8                                LabelLen,
  TCPIP_P2C(TcpIp_ConstSegmentType)    ContextSegmentPtr);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_HkdfExtractAndExpand
 *********************************************************************************************************************/
/*! \brief          This function executes the HKDF-Extract and HKDF-Expand function in one step (RFC 5869).
 *  \details        -
 *  \param[in]      TlsConIdx            TLS connection index
 *  \param[in]      DeriveSecretInputPtr Pointer to the input needed for the derive secret calculation
 *  \param[in]      InfoSegmentPtr       A pointer to a segment with the context and application specific information
 *  \return         E_OK                 Expand and extract was successful
 *  \return         E_NOT_OK             At least one CSM call failed while executing the expand and extract
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_HkdfExtractAndExpand(
  TcpIp_TlsConnectionIterType                     TlsConIdx,
  TCPIP_P2C(TcpIp_Tls13_DeriveSecretInput_Type)   DeriveSecretInputPtr,
  TCPIP_P2C(TcpIp_ConstSegmentType)               InfoSegmentPtr);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_HkdfExpand
 *********************************************************************************************************************/
/*! \brief          This function executes the HKDF-Expand function without the HKDF-Extract.
 *  \details        -
 *  \param[in]      HkdfExpandInputPtr   Pointer to the input needed for the HKDF expand calculation
 *  \param[in]      InfoSegmentPtr       A pointer to a segment with the context and application specific information
 *  \return         E_OK                 Expand was successful
 *  \return         E_NOT_OK             At least one CSM call failed while executing the expand
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_HkdfExpand(
  TCPIP_P2C(TcpIp_Tls13_HkdfExpandInput_Type) HkdfExpandInputPtr,
  TCPIP_P2C(TcpIp_ConstSegmentType)           InfoSegmentPtr);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_PrepareTmpExpandInputKey
 *********************************************************************************************************************/
/*! \brief          This function prepares the temporary expand input key for the HKDF expand
 *  \details        Additional info is set and if necessary the input key is copied into the temporary expand input key
 *  \param[in]      HkdfExpandInputPtr   Pointer to the input needed for the HKDF expand calculation
 *  \param[in]      InfoSegmentPtr       A pointer to a segment with the context and application specific information
 *  \return         E_OK                 Preparation of key was successful
 *  \return         E_NOT_OK             At least one CSM call failed while preparing the key
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_PrepareTmpExpandInputKey(
  TCPIP_P2C(TcpIp_Tls13_HkdfExpandInput_Type) HkdfExpandInputPtr,
  TCPIP_P2C(TcpIp_ConstSegmentType)           InfoSegmentPtr);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_CopyTmpExpandOutputKeyToTargetKey
 *********************************************************************************************************************/
/*! \brief          Copies the temporary output key to the target key e.g. after a Hkdf expand operation
 *  \details        This is only done when these are different keys.
 *  \param[in]      HkdfExpandInputPtr   Pointer to the input needed for the HKDF expand calculation
 *  \return         E_OK                 Copying to target key was successful
 *  \return         E_NOT_OK             At least one CSM call failed while copying to the target key
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_CopyTmpExpandOutputKeyToTargetKey(
  TCPIP_P2C(TcpIp_Tls13_HkdfExpandInput_Type) HkdfExpandInputPtr);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_ShortenHkdfKeyToSize
 *********************************************************************************************************************/
/*! \brief          This function shortens the size of a Hkdf key.
 *  \details        This is often necessary after a Hkdf expand or Hkdf extract and expand operation.
 *  \param[in]      TlsConIdx              TLS connection index
 *  \param[in]      HkdfKeyId              The Id of the key which shall be shortened.
 *  \param[in]      DesiredKeyLength       The DesiredKeyLength to which the key should be shortened.
 *  \param[in]      TemporaryKeyId         The Id of a key which can be used to temporarily save the Hkdf data.
 *  \param[in]      TemporaryKeyElementId  The Id of a key element which can be used to temporarily save the Hkdf data.
 *                                         Afterwards the data of this key element is cleared.
 *  \return         E_OK                   Length of key successfully shortened
 *  \return         E_NOT_OK               At least one CSM call failed while shortening the key
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_ShortenHkdfKeyToSize(
  TcpIp_TlsConnectionIterType                     TlsConIdx,
  TcpIp_CsmKeyIdType                              HkdfKeyId,
  uint32                                          DesiredKeyLength,
  TcpIp_CsmKeyIdType                              TemporaryKeyId,
  uint32                                          TemporaryKeyElementId);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_GetLengthOfEcdheSharedSecretFirstCoord
 *********************************************************************************************************************/
/*! \brief          This function returns the length of the calculated ecdhe shared secret's first coordinate
 *  \details        -
 *  \param[in]      TlsConIdx              TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[out]     LengthPtr              The length of the first coordinate of ecdhe shared secret in bytes.
 *  \return         E_OK                   Length could be determined successfully
 *  \return         E_NOT_OK               No valid length found
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_GetLengthOfEcdheSharedSecretFirstCoord(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint8) LengthPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13Core_GetKeyLengthOfActiveCipherSuite
 *********************************************************************************************************************/
/*! \brief         Determines the length of the key for the currently active cipher suite.
 *  \details       -
 *  \param[in]     TlsConIdx              TLS connection index
 *                                        CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[out]    CipherSuiteKeyLenPtr   The key length in number of bytes.
 *  \return        E_OK                   Length of the key could be determined successfully
 *  \return        E_NOT_OK               No valid key length found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Core_GetKeyLengthOfActiveCipherSuite(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint8) CipherSuiteKeyLenPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13Core_GetCipherSuiteKeyLength
 *********************************************************************************************************************/
/*! \brief         Determines the length of the key for the passed cipher suite Id.
 *  \details       -
 *  \param[in]     CipherSuiteId          Cipher suite Id for which the hash length shall be determined
 *  \param[out]    CipherSuiteKeyLenPtr   The key length in number of bytes.
 *  \return        E_OK                   Length of the key could be determined successfully
 *  \return        E_NOT_OK               No valid key length found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Core_GetCipherSuiteKeyLength(
  TcpIp_TlsCipherDataType     CipherSuiteId,
  TCPIP_P2V(uint8)            CipherSuiteKeyLenPtr);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DeriveClientAndServerApplicationKeys
 *********************************************************************************************************************/
/*! \brief         Derives the client and server keys for application traffic
 *  \details       -
 *  \param[in]     TlsConIdx    TLS connection index
 *                              CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     HashLength   The hash length of the active cipher suite
 *  \return        E_OK         Application keys for client and server are calculated successfully
 *  \return        E_NOT_OK     Failure during derivation or calculation of application keys
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_DeriveClientAndServerApplicationKeys(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8                       HashLength);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_PrepareDerivationOfApplicationTrafficSecret
 *********************************************************************************************************************/
/*! \brief         Prepares the derivation of the client and server secrets/keys for application traffic
 *  \details       -
 *  \param[in]     TlsConIdx   TLS connection index
 *                             CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     HashLength  The hash length of the active cipher suite
 *  \return        E_OK        Preparation of derivation for application traffic secrets was not successful
 *  \return        E_NOT_OK    Failure during derivation of shared secrets used for application traffic secrets
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_PrepareDerivationOfApplicationTrafficSecret(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8                       HashLength);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_CalcHandshakeKeysGetParameters
 *********************************************************************************************************************/
/*! \brief         Gets all necessary parameters for the calculation of the handshake keys
 *  \details       -
 *  \param[in]     TlsConIdx                              TLS connection index
 *                                                        CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[out]    HashLengthPtr                          Pointer to the length of the hash
 *  \param[out]    KeyLengthPtr                           Pointer to the length of the key
 *  \param[out]    LengthOfFirstCoordinateECDHESecretPtr  Pointer to the length
 *                                                        of the first coordinate of the shared secret
 *  \return        E_OK                                   Successfully gathered all parameters
 *                                                        necessary for the handshake key calculation
 *  \return        E_NOT_OK                               Could not gather either the length of the hash, key
 *                                                        or first coordinate of the shared secret
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_CalcHandshakeKeysGetParameters(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint8) HashLengthPtr,
  TCPIP_P2V(uint8) KeyLengthPtr,
  TCPIP_P2V(uint8) LengthOfFirstCoordinateECDHESecretPtr);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DeriveClientAndServerHandshakeKeys
 *********************************************************************************************************************/
/*! \brief         Derives the handshake secret for client and server and calculates the keys respectively
 *  \details       -
 *  \param[in]     TlsConIdx  TLS connection index
 *                            CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     HashLength The hash length of the active cipher suite
 *  \return        E_OK       Handshake keys for client and server are calculated successfully
 *  \return        E_NOT_OK   Failure during calculation of handshake keys
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_DeriveClientAndServerHandshakeKeys(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8                       HashLength);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_PrepareDerivationOfHandshakeTrafficSecret
 *********************************************************************************************************************/
/*! \brief         Derives the shared secret and the derived secret used for TLS 1.3 key derivation
 *  \details       -
 *  \param[in]     TlsConIdx                           TLS connection index
 *                                                     CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     HashLength                          The hash length according to the active cipher suite
 *  \param[in]     KeyLength                           The key length according to the active cipher suite
 *  \param[in]     LengthOfFirstCoordinateECDHESecret  The length of the first coordinate of the ecdhe secret
 *  \return        E_OK                                Shared/Derived secrets calculated and saved to CSM keys successfully
 *  \return        E_NOT_OK                            Failure during calculation of secrets
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_PrepareDerivationOfHandshakeTrafficSecret(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8 HashLength,
  uint8 KeyLength,
  uint8 LengthOfFirstCoordinateECDHESecret);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_CalcHandshakeKeys
 *********************************************************************************************************************/
/*! \brief         Calculates the TLS 1.3 handshake traffic keys and IV
 *  \details       Handshake traffic keys and IV are saved in the CSM encrypt / decrypt key container
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK                Handshake keys calculated successfully
 *  \return        E_NOT_OK            Failure during calculation of handshake keys
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_CalcHandshakeKeys(TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_CalculateKeyAndIvForEncryptionAndDecryption
 *********************************************************************************************************************/
/*! \brief         Calculates both the TLS 1.3 handshake traffic keys and IV as the application traffic keys and IV
 *  \details       The traffic keys and IV are saved in the CSM encrypt / decrypt key container
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK                Key and IV calculation successful
 *  \return        E_NOT_OK            Failure during calculation of key or IV
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_CalculateKeyAndIvForEncryptionAndDecryption(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_AreCsmKeyIdsValid
 *********************************************************************************************************************/
/*! \brief          This function checks if the CSM key Ids of the active handshake and active cipherworker are valid
 *  \details        -
 *  \param[in]      TlsConIdx            TLS connection index
 *                                       \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return         TRUE                 CSM key Ids are valid
 *  \return         FALSE                CSM key Ids are NOT valid
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_Tls13CoreCtx_AreCsmKeyIdsValid(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreRl_AddInnerPlaintextContentType
 *********************************************************************************************************************/
/*! \brief          Add the inner plain text ContentType to the transmittable message.
 *  \details        Add the inner content type to the message after making a backup of the original byte value. This is
 *                  done to be able to restore the byte if this was not the end of the message but only the end of a
 *                  fragment (to fit into a record layer frame).
 *  \param[in]      TlsConIdx             TLS connection index
 *                                       \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]      TxPlainTextStartIdx  Start index within the TlsTxBuffer of the transmittable frame
 *  \param[in,out]  TxPlainTextLenPtr    Pointer to the length of the transmittable frame
 *  \param[in,out]  ContentTypePtr       Pointer to the Record Layer ContentType of the transmittable frame
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13CoreRl_AddInnerPlaintextContentType(
  TcpIp_TlsConnectionIterType             TlsConIdx,
  TcpIp_TlsBufferTxIterType               TxPlainTextStartIdx,
  TCPIP_P2V(TcpIp_SizeOfTlsBufferTxType)  TxPlainTextLenPtr,
  TCPIP_P2V(uint8)                        ContentTypePtr);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreRl_FindInnerPlaintextContentType
 *********************************************************************************************************************/
/*! \brief         Find and read the inner plain text ContentType from a received message
 *  \details       Remove the inner plain text padding and get the inner plain text ContentType
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[out]    PaddingLen          Returns the length of the padding
 *  \return        E_OK                Saved the inner plain text ContentType successfully
 *  \return        E_NOT_OK            Invalid format, could not find the inner plain text ContentType
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreRl_FindInnerPlaintextContentType(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint16) PaddingLen);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreRl_ReadInnerPlaintextContentType
 *********************************************************************************************************************/
/*! \brief         Read and save the inner plain text ContentType from a position in the Rx AdHs Buffer
 *  \details       -
 *  \param[in]     TlsConIdx            TLS connection index
 *                                      CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     ReadTlsBufferRxIdx   The index of the Rx AdHs Buffer where the inner plain text ContentType is located
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13CoreRl_ReadInnerPlaintextContentType(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferRxIterType   ReadTlsBufferRxIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreRl_CopyPlaintextToAlertBuffer
 *********************************************************************************************************************/
/*! \brief         Copy the alert plaintext from the Rx AdHs buffer to the Rx Alert buffer
 *  \details       The inner plain text content type and padding are not copied
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     PlaintextLen        Length of the plaintext which is to be copied
 *  \return        E_OK                Successfully copied plaintext into Rx Alert buffer
 *  \return        E_NOT_OK            Plaintext was NOT copied,
 *                                     Either Plaintext too long or its length does not match PlaintextLen
 *  \pre           Rx AdHs write index shall be set to the inner plain text content type
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreRl_CopyPlaintextToAlertBuffer(
  TcpIp_TlsConnectionIterType                     TlsConIdx,
  TcpIp_RlRxCopiedLenOfTlsBufferMgmtDynType       PlaintextLen);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreRl_ProcessHsFrameAfterHandshake
 *********************************************************************************************************************/
/*! \brief          Process handshake messages after the handshake is already complete.
 *  \details        -
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]      HsType                  Handshake type
 *  \param[in]      HsLen                   Handshake length
 *  \param[in]      SourceSegment1Ptr       First buffer segment (wraparound case: data at the end of the buffer)
 *  \param[in]      SourceSegment2Ptr       Second buffer segment (wraparound case: data at the start of the buffer)
 *  \return         E_OK                    Message successfully processed
 *  \return         E_NOT_OK                Processing of message failed
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreRl_ProcessHsFrameAfterHandshake(
  TcpIp_TlsConnectionIterType                 TlsConIdx,
  uint8                                       HsType,
  uint32                                      HsLen,
  TcpIp_ConstSegmentPtrType                   SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                   SourceSegment2Ptr);

/**********************************************************************************************************************
 * TcpIp_Tls13CoreCrypto_CalculatePerRecordNonce
 *********************************************************************************************************************/
/*! \brief         Calculate the TLS 1.3 Per-Record Nonce
 *  \details       -
 *  \param[in]     TlsConIdx                      TLS connection index
 *                                                CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     KeyId                          The Id of the key that shall be used for decryption / encryption.
 *  \param[in]     SequenceNumber                 Current sequence number
 *  \param[in]     LastSequenceNumberInBytesPtr   Pointer to an array containing the sequence number used for
 *                                                the last nonce calculation
 *  \param[out]    NoncePtr                       Pointer to an array that contains the calculated per record nonce
 *  \return        E_OK                           Operation successful
 *  \return        E_NOT_OK                       Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCrypto_CalculatePerRecordNonce(
  TcpIp_TlsConnectionIterType                     TlsConIdx,
  TcpIp_CsmKeyIdType                              KeyId,
  uint64                                          SequenceNumber,
  TCPIP_P2C(uint8)                                LastSequenceNumberInBytesPtr,
  TCPIP_P2V(uint8)                                NoncePtr);

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_SetPublicKeyPtrAndLength
 *********************************************************************************************************************/
/*! \brief           Set the passed public key pointer pointer to the address in the Rx buffer
 *                   where the public key is located and set the passed public key length pointer to its length
 *  \details         Is called in asynchronous handler for TLS 1.3 calculation of the Diffie-Hellman shared secret
 *  \param[in]       TlsConIdx            TLS connection index
 *                                        CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in,out]   PublicKeyPtrPtr      Pointer to the pointer of the public key
 *  \param[in,out]   PublicKeyLenPtr      Pointer for the length of the public key
 *  \return          E_OK                 Operation successful
 *  \return          E_NOT_OK             Operation NOT successful
 *  \pre             -
 *  \context         TASK (only called in the context of the TLS background task TcpIp_Tls_MainFunctionLowPrio())
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_SetPublicKeyPtrAndLength(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TCPIP_P2V(TcpIp_Uint8P2C)     PublicKeyPtrPtr,
  TCPIP_P2V(uint16)             PublicKeyLenPtr);
#  endif

#  if (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_SendTrafficSecretsViaNssFrame
 *********************************************************************************************************************/
/*! \brief         Sends two NSS Frames of respectively the TLS 1.3 server and the TLS 1.3 client secret.
 *  \details       -
 *  \param[in]     TlsConIdx             TLS connection index
 *                                       \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ServerSecretCsmKeyId  The keyId of the server secret which should be sent via NSS Frame
 *  \param[in]     ClientSecretCsmKeyId  The keyId of the client secret which should be sent via NSS Frame
 *  \param[in]     SendingType           Specifies if handshake traffic secrets or application traffic secrets shall be send
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_SendTrafficSecretsViaNssFrame(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TcpIp_CsmKeyIdType            ServerSecretCsmKeyId,
  TcpIp_CsmKeyIdType            ClientSecretCsmKeyId,
  TcpIp_TlsNssFrameSendingType  SendingType);
#  endif /* (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DeleteHandshakeKeys
 *********************************************************************************************************************/
/*! \brief         Deletes all keys and secrets used for the handshake of a specific TLS connection
 *  \details       -
 *  \param[in]     TlsConIdx            TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                 Operation successful
 *  \return        E_NOT_OK             Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_DeleteHandshakeKeys(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DeleteApplicationTrafficKeys
 *********************************************************************************************************************/
/*! \brief         Deletes all keys and secrets used for the application traffic of a specific TLS connection
 *  \details       -
 *  \param[in]     TlsConIdx            TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                 Operation successful
 *  \return        E_NOT_OK             Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_DeleteApplicationTrafficKeys(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DeleteTemporaryKeys
 *********************************************************************************************************************/
/*! \brief         Deletes all temporary keys and secrets of a specific TLS connection
 *  \details       -
 *  \param[in]     TlsConIdx            TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                 Operation successful
 *  \return        E_NOT_OK             Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_DeleteTemporaryKeys(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DeleteResumptionKeys
 *********************************************************************************************************************/
/*! \brief         Deletes all session resumption related keys of a specific TLS connection
 *  \details       -
 *  \param[in]     TlsConIdx            TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                 Operation successful
 *  \return        E_NOT_OK             Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_DeleteResumptionKeys(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DeleteResumptionKeysFromResumedConnection
 *********************************************************************************************************************/
/*! \brief         Deletes all session resumption related keys of a specific TLS connection.
 *  \details       The TLS connection is configured as a resumed connection.
 *  \param[in]     TlsConIdx            TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                 Operation successful
 *  \return        E_NOT_OK             Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_DeleteResumptionKeysFromResumedConnection(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DeriveSecretAndShortenHkdfKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_DeriveSecretAndShortenHkdfKey(
  TcpIp_TlsConnectionIterType                     TlsConIdx,
  TCPIP_P2C(TcpIp_Tls13_DeriveSecretInput_Type)   DeriveSecretInputPtr,
  TCPIP_P2C(uint8)                                LabelPtr,
  uint8                                           LabelLen,
  boolean                                         HashMessages)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 hkdfLabelDest[MAX_SIZE_OF_HKDF_LABEL] = { 0 };
  TcpIp_SegmentType hkdfLabelSegment = { 0 };
  TcpIp_ConstSegmentType hkdfLabelConstSegment = { 0 };

  /* ----- Implementation ----------------------------------------------- */
  TcpIp_SegmentInit(&hkdfLabelSegment, &hkdfLabelDest[0], MAX_SIZE_OF_HKDF_LABEL);
  /* #10 Calculate the hash and create a HKDF Label. */
  Std_ReturnType retVal = TcpIp_Tls13CoreCtx_CalcHashAndCreateHkdfLabel(
      TlsConIdx,
      DeriveSecretInputPtr,
      &hkdfLabelSegment,
      LabelPtr,
      LabelLen,
      HashMessages);

  if (retVal == E_OK)
  {
    /* From now on the HKDF label is only read.
     * Therefore use a const segment which is initialized with the non-const segment. */
    TcpIp_ConstSegmentInitWithUsedSegment(&hkdfLabelConstSegment, &hkdfLabelSegment);

    /* #20 Call the Hkdf-ExtractAndExpand function to derive the secret. */
    retVal = TcpIp_Tls13CoreCtx_HkdfExtractAndExpand(
      TlsConIdx,
      DeriveSecretInputPtr,
      &hkdfLabelConstSegment);
  }

  if (retVal == E_OK)
  {
    /* The KeyDerive Job in the CSM checks the length of the target key (66 Bytes) and executes the HKDF-Expand to
     * this size. The actual key size for the derived secret and the handshake/application traffic keys depends on
     * the used cipher suite. Therefore, the size of the derived key must be manually shortened. */
    /* #30 Shorten the Hkdf key according to the determined hash length. */
    retVal = TcpIp_Tls13CoreCtx_ShortenHkdfKeyToSize(TlsConIdx, DeriveSecretInputPtr->TargetKeyId,
      DeriveSecretInputPtr->HkdfHashLen, DeriveSecretInputPtr->TemporaryKeyId, DeriveSecretInputPtr->TemporaryKeyElementId);
  }

  return retVal;
} /* TcpIp_Tls13CoreCtx_DeriveSecretAndShortenHkdfKey () */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_CalcHashAndCreateHkdfLabel
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_CalcHashAndCreateHkdfLabel(
  TcpIp_TlsConnectionIterType                     TlsConIdx,
  TCPIP_P2C(TcpIp_Tls13_DeriveSecretInput_Type)   DeriveSecretInputPtr,
  TcpIp_SegmentPtrType                            HkdfLabelSegmentPtr,
  TCPIP_P2C(uint8)                                LabelPtr,
  uint8                                           LabelLen,
  boolean                                         HashMessages)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* Hash shall be stored into the Tls temporary buffer and used to generate the hash */
  TCPIP_P2V(uint8) hsHashDestPtr = TcpIp_GetAddrTlsTemporaryHashBuffer(
    TcpIp_GetTlsTemporaryHashBufferStartIdxOfTlsConnection(TlsConIdx));

  uint32 hsHashDestSpace = TcpIp_GetTlsTemporaryHashBufferEndIdxOfTlsConnection(TlsConIdx)
    - (uint32)TcpIp_GetTlsTemporaryHashBufferStartIdxOfTlsConnection(TlsConIdx);

  TcpIp_SegmentType hsHashSegmentPtr = { 0 };

  TcpIp_ConstSegmentType hsHashConstSegmentPtr = { 0 };

  /* ----- Implementation ----------------------------------------------- */
  TcpIp_SegmentInit(&hsHashSegmentPtr, hsHashDestPtr, hsHashDestSpace);
  /* #10 Check if a hash over all handshake messages should be calculated or not. */
  if (HashMessages == TRUE)
  {
    /* #20 Calculate a hash over all handshake messages. */
    /* Calculate hash of "messages". Could be "ClientHello" or "ClientHello ... ServerHello" or
     * "ClientHello ... Server Finished" or "ClientHello ... Client Finished" */
    retVal = TcpIp_Tls13Client_CalculateHashOfHsMessages(TlsConIdx,
      DeriveSecretInputPtr->HkdfHashLen, &hsHashSegmentPtr);
  }
  else
  {
    /* #30 Calculate hash over the string "". */
    CONST(uint8, TCPIP_CONST) dummyElement = 0u;

    retVal = TcpIp_Tls13CoreCrypto_HashIntoSegment(TlsConIdx, DeriveSecretInputPtr->HashMessagesJobId,
      CRYPTO_OPERATIONMODE_SINGLECALL, &dummyElement, 0u, DeriveSecretInputPtr->HkdfHashLen, &hsHashSegmentPtr);
  }

  /* #40 Call the HkdfCreateLabel function. */
  if (retVal == E_OK)
  {
    /* From now on the hash is only read.
     * Therefore use a const segment which is initialized with the non-const segment. */
    TcpIp_ConstSegmentInitWithUsedSegment(&hsHashConstSegmentPtr, &hsHashSegmentPtr);

    TcpIp_Tls13CoreCtx_HkdfCreateLabel(HkdfLabelSegmentPtr, DeriveSecretInputPtr->HkdfHashLen, LabelPtr, LabelLen,
      &hsHashConstSegmentPtr);
  }

  return retVal;
} /* TcpIp_Tls13CoreCtx_CalcHashAndCreateHkdfLabel() */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_HkdfExpandLabel
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6060 1 */ /* MD_TcpIp_Tls13KeyDerivation_STPAR_6060 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_HkdfExpandLabel(
  TCPIP_P2C(TcpIp_Tls13_HkdfExpandInput_Type) HkdfExpandInputPtr,
  TCPIP_P2C(uint8) LabelPtr,
  uint8 LabelLen,
  TCPIP_P2C(uint8) ContextPtr,
  uint8 ContextLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 hkdfLabelDestPtr[MAX_SIZE_OF_HKDF_LABEL] = { 0u };
  TcpIp_SegmentType hkdfLabelSegment = { 0 };
  TcpIp_ConstSegmentType hkdfLabelConstSegment = { 0 };
  TcpIp_ConstSegmentType contextConstSegment = { 0 };
  TCPIP_P2C(TcpIp_ConstSegmentType) contextConstSegmentPtr = NULL_PTR;

  /* ----- Implementation ----------------------------------------------- */
  TcpIp_SegmentInit(&hkdfLabelSegment, &hkdfLabelDestPtr[0], MAX_SIZE_OF_HKDF_LABEL);
  if (ContextPtr != NULL_PTR)
  {
    TcpIp_ConstSegmentInit(&contextConstSegment, ContextPtr, ContextLen);
    contextConstSegmentPtr = &contextConstSegment;
  }

  /* #10 Create the HKDF label. */
  TcpIp_Tls13CoreCtx_HkdfCreateLabel(&hkdfLabelSegment, HkdfExpandInputPtr->TargetKeyElementLen, LabelPtr, LabelLen,
    contextConstSegmentPtr);

  /* From now on the HKDF label is only read.
   * Therefore use a const segment which is initialized with the non-const segment. */
  TcpIp_ConstSegmentInitWithUsedSegment(&hkdfLabelConstSegment, &hkdfLabelSegment);

  /* #20 Call the HKDF-Expand function. */
  return TcpIp_Tls13CoreCtx_HkdfExpand(HkdfExpandInputPtr, &hkdfLabelConstSegment);
} /* TcpIp_Tls13CoreCtx_HkdfExpandLabel() */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_HkdfCreateLabel
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13CoreCtx_HkdfCreateLabel(
  TcpIp_SegmentPtrType                 HkdfLabelSegmentPtr,
  uint16                               OutputKeyLen,
  TCPIP_P2C(uint8)                     LabelPtr,
  uint8                                LabelLen,
  TCPIP_P2C(TcpIp_ConstSegmentType)    ContextSegmentPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 labelTotalLen = (LabelLen + TCPIP_TLS_HS_TLS13LABEL_TLS13_LEN + TCPIP_TLS_ASCII_CHAR_LEN);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Create the Hkdf-Label. */
  /* Add the length of output keying material (2 Byte) (RFC 8446 / RFC 5869) */
  TcpIp_SegmentPutUint16(HkdfLabelSegmentPtr, OutputKeyLen);
  /* Add the total length of the label (1 Byte) */
  TcpIp_SegmentPutUint8(HkdfLabelSegmentPtr, labelTotalLen);
  /* Add the label prefix (5 Byte) and one space character */
  TcpIp_SegmentMemCpy(HkdfLabelSegmentPtr, &TcpIp_Tls_Hs_Tls13Label_Tls13[0], TCPIP_TLS_HS_TLS13LABEL_TLS13_LEN);
  TcpIp_SegmentPutUint8(HkdfLabelSegmentPtr, TCPIP_TLS_ASCII_CHAR_SPACE); /* single ASCII space character */
  /* Add the label extension (max 256 Byte) */
  TcpIp_SegmentMemCpy(HkdfLabelSegmentPtr, &LabelPtr[0], LabelLen);
  if (ContextSegmentPtr == NULL_PTR)
  {
    /* Add zero for the length of the context (1 Byte) */
    TcpIp_SegmentPutUint8(HkdfLabelSegmentPtr, 0u);
  }
  else
  {
    /* Add the length of the context (1 Byte) */
    TcpIp_SegmentPutUint8(HkdfLabelSegmentPtr, (uint8)ContextSegmentPtr->Size);
    /* Add the context (0-255 Byte) if available */
    TcpIp_SegmentMemCpy(HkdfLabelSegmentPtr, ContextSegmentPtr->BasePtr, ContextSegmentPtr->Size);
  }
}

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_HkdfExpand
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_HkdfExpand(
  TCPIP_P2C(TcpIp_Tls13_HkdfExpandInput_Type) HkdfExpandInputPtr,
  TCPIP_P2C(TcpIp_ConstSegmentType)           InfoSegmentPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* The temporary expand input key is the referenced key in the CSM expand job.
   * The HKDF expand of the CSM_JobKeyDerive can only work with the input stored in that key. */
  TcpIp_CsmKeyIdType tmpExpandInKeyId =
    TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob((TcpIp_TlsCsmJobIterType) HkdfExpandInputPtr->HkdfExpandJobId);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Prepare the temporary expand input key */
  /* Add additional information, copy the input key into the temporary expand input key if they are different keys
   * and set the temporary expand input key to valid. */
  Std_ReturnType csmRetVal = TcpIp_Tls13CoreCtx_PrepareTmpExpandInputKey(HkdfExpandInputPtr, InfoSegmentPtr);

  /* #20 Expand keys */
  if (csmRetVal == E_OK)
  {
    csmRetVal = TCPIP_CSM_JobKeyDerive(HkdfExpandInputPtr->HkdfExpandJobId, HkdfExpandInputPtr->TempExpandOutKeyId);
  }

  /* #30 Write output keys */
  if (csmRetVal == E_OK)
  {
    csmRetVal = TcpIp_Tls13CoreCtx_CopyTmpExpandOutputKeyToTargetKey(HkdfExpandInputPtr);
  }

  /* #40 Reset temp keys */
  /* The temp keys are no longer needed and shouldn't contain the key material anymore. */
  if (csmRetVal == E_OK)
  {
    csmRetVal = TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(HkdfExpandInputPtr->TempExpandOutKeyId,
      TCPIP_CRYPTO_30_LIBCV_KE_TARGET_KEY);
  }
  if (csmRetVal == E_OK)
  {
    csmRetVal = TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(tmpExpandInKeyId,
      CRYPTO_KE_CUSTOM_KEYDERIVATION_ADDITIONAL_INFO);
  }

  if (csmRetVal == E_OK)
  {
    retVal = E_OK;
  }
  return retVal;
} /* TcpIp_Tls13CoreCtx_HkdfExpand() */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_PrepareTmpExpandInputKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_PrepareTmpExpandInputKey(
  TCPIP_P2C(TcpIp_Tls13_HkdfExpandInput_Type) HkdfExpandInputPtr,
  TCPIP_P2C(TcpIp_ConstSegmentType)           InfoSegmentPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* The HKDF expand of the CSM_JobKeyDerive can only work when the input is in the referenced key of the job.
   * This key is referred to as temporary expand input key in difference to the input key
   * where the input is currently located since it might not be feasible
   * to have the input already in the temporary expand input key. */
  TcpIp_CsmKeyIdType tmpExpandInputKeyId
    = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob((TcpIp_TlsCsmJobIterType) HkdfExpandInputPtr->HkdfExpandJobId);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set additional info in temporary expand input key. */
   Std_ReturnType csmRetVal = TCPIP_CSM_KeyElementSet(tmpExpandInputKeyId,
     CRYPTO_KE_CUSTOM_KEYDERIVATION_ADDITIONAL_INFO, InfoSegmentPtr->BasePtr, InfoSegmentPtr->Size);

  if (   (csmRetVal == E_OK)
         /* #20 Check if the input key is different to the temporary expand input key. */
      && (tmpExpandInputKeyId != HkdfExpandInputPtr->InputKeyId))
  {
    /* #30 If so, copy the input key into the temporary expand input key. */
    csmRetVal = TCPIP_CSM_KeyElementCopyPartial(HkdfExpandInputPtr->InputKeyId, CRYPTO_KE_KEYDERIVATION_PASSWORD,
      0u, 0u, (uint32)HkdfExpandInputPtr->HkdfHashLen, tmpExpandInputKeyId, CRYPTO_KE_KEYDERIVATION_PASSWORD);
  }

  if (csmRetVal == E_OK)
  {
    /* #40 Set temporary expand input key valid. */
    csmRetVal = TCPIP_CSM_KeySetValid(tmpExpandInputKeyId);
  }

  if (csmRetVal == E_OK)
  {
    retVal = E_OK;
  }

  return retVal;
} /* TcpIp_Tls13CoreCtx_PrepareTmpExpandInputKey() */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_CopyTmpExpandOutputKeyToTargetKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_CopyTmpExpandOutputKeyToTargetKey(
  TCPIP_P2C(TcpIp_Tls13_HkdfExpandInput_Type) HkdfExpandInputPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Std_ReturnType csmRetVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Copy the key value from the temporary expand output key to the actual output key at the expected place. */
  csmRetVal = TCPIP_CSM_KeyElementCopyPartial(HkdfExpandInputPtr->TempExpandOutKeyId,
    TCPIP_CRYPTO_30_LIBCV_KE_TARGET_KEY, 0u, 0u, (uint32) HkdfExpandInputPtr->TargetKeyElementLen,
    HkdfExpandInputPtr->TargetKeyId, HkdfExpandInputPtr->TargetKeyElementId);

  if (csmRetVal == E_OK)
  {
    /* #20 Set target key valid. */
    csmRetVal = TCPIP_CSM_KeySetValid(HkdfExpandInputPtr->TargetKeyId);
  }

  if (csmRetVal == E_OK)
  {
    retVal = E_OK;
  }
  return retVal;
} /* TcpIp_Tls13CoreCtx_CopyTmpExpandOutputKeyToTargetKey() */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_HkdfExtractAndExpand
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_HkdfExtractAndExpand(
  TcpIp_TlsConnectionIterType                     TlsConIdx,
  TCPIP_P2C(TcpIp_Tls13_DeriveSecretInput_Type)   DeriveSecretInputPtr,
  TCPIP_P2C(TcpIp_ConstSegmentType)               InfoSegmentPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmRetVal = E_OK;
  const uint8 iteration = 2u; /* Two Step variant, see RFC8446 chapter 7.1 (page 92) */
  TcpIp_CsmKeyIdType inputKeyId
    = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob((TcpIp_TlsCsmJobIterType) DeriveSecretInputPtr->HkdfCalcJobId);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the key elements needed for the key derivation. */

  /* Set the Info aka KeyDerivation_Salt only if it's provided in a different key. */
  if (inputKeyId != DeriveSecretInputPtr->SaltKeyId)
  {
    csmRetVal = TCPIP_CSM_KeyElementCopy(DeriveSecretInputPtr->SaltKeyId, CRYPTO_KE_KEYDERIVATION_PASSWORD,
      inputKeyId, CRYPTO_KE_KEYDERIVATION_SALT);
  }

  if (csmRetVal == E_OK)
  {
    /* Set the modus for the key derivation */
    csmRetVal = TcpIp_TlsCoreCrypto_SetCsmKeyElementAndSetKeyValid(inputKeyId,
      CRYPTO_KE_KEYDERIVATION_ITERATIONS, &iteration, TCPIP_TLS_HKDF_ITERATION_MODE_LEN);
  }

  /* Set the Info aka KeyDerivation_AdditionalInfo if available */
  if ((csmRetVal == E_OK) && (InfoSegmentPtr != NULL_PTR))
  {
    csmRetVal = TcpIp_TlsCoreCrypto_SetCsmKeyElementAndSetKeyValid(inputKeyId,
      DeriveSecretInputPtr->AdditionalInfoKeyElementId, InfoSegmentPtr->BasePtr, InfoSegmentPtr->Size);
  }

  if (csmRetVal == E_OK)
  {
    /* #20 Perform the key derivation. */
    csmRetVal = TCPIP_CSM_JobKeyDerive(DeriveSecretInputPtr->HkdfCalcJobId, DeriveSecretInputPtr->TargetKeyId);
  }

  return TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, 0u, 0u,
    TCPIP_TLS_FCTID_CORE_CRYPTO_HKDF_EXTRACTANDEXPAND);
} /* TcpIp_Tls13CoreCtx_HkdfExtractAndExpand() */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_ShortenHkdfKeyToSize
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_ShortenHkdfKeyToSize(
  TcpIp_TlsConnectionIterType                     TlsConIdx,
  TcpIp_CsmKeyIdType                              HkdfKeyId,
  uint32                                          DesiredKeyLength,
  TcpIp_CsmKeyIdType                              TemporaryKeyId,
  uint32                                          TemporaryKeyElementId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmRetVal = E_NOT_OK;

  CONST(uint8, TCPIP_CONST) dummyData[1] = { 0u };
  uint8 dummyLen = 1u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Copy key to temp buffer with specified length */
  csmRetVal = TCPIP_CSM_KeyElementCopyPartial(HkdfKeyId, CRYPTO_KE_KEYDERIVATION_PASSWORD,
    0, 0, DesiredKeyLength, TemporaryKeyId, TemporaryKeyElementId);

  if (csmRetVal == E_OK)
  {
    /* #20 Reset key container to 0 */
    csmRetVal = TCPIP_CSM_KeyElementSet(HkdfKeyId, CRYPTO_KE_KEYDERIVATION_PASSWORD,
      &dummyData[0], dummyLen);
  }

  if (csmRetVal == E_OK)
  {
    /* #30 Copy key from temp buffer back to original key container */
    csmRetVal = TCPIP_CSM_KeyElementCopyPartial(TemporaryKeyId,
      TemporaryKeyElementId, 0, 0, DesiredKeyLength, HkdfKeyId, CRYPTO_KE_KEYDERIVATION_PASSWORD);
  }

  if (csmRetVal == E_OK)
  {
    /* #40 Set the key with the correct length to valid */
    csmRetVal = TCPIP_CSM_KeySetValid(HkdfKeyId);
  }

  if (csmRetVal == E_OK)
  {
    /* #50 Reset temp buffer */
    csmRetVal = TCPIP_CSM_KeyElementSet(TemporaryKeyId, TemporaryKeyElementId, &dummyData[0], dummyLen);
  }
  return TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, 0, 0, TCPIP_TLS_FCTID_CORE_CRYPTO_REDUCEKEY);
} /* TcpIp_Tls13CoreCtx_ShortenHkdfKeyToSize() */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_GetLengthOfEcdheSharedSecretFirstCoord
 *********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
 *
  */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_GetLengthOfEcdheSharedSecretFirstCoord(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint8) LengthPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize length */
  *LengthPtr = 0u;

  if (TcpIp_TlsCoreUtil_IsActiveHandshakeSet(TlsConIdx) == TRUE)
  {
    TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx
      = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

    TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx
      = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx);

    TcpIp_TlsEllipticCurveIdType namedGroup = TcpIp_GetEllipticCurveIdOfTlsHandshake(activeTlsHandshakeIdx);

    switch (namedGroup)
    {
      /* #20 Set length according to selected group in handshake */
      case TCPIP_CURVE_ID_SECP521R1:
        *LengthPtr = TCPIP_CURVE_ID_SECP521R1_SHAREDKEY_LEN;
        retVal = E_OK;
        break;
      case TCPIP_CURVE_ID_SECP256R1:
        *LengthPtr = TCPIP_CURVE_ID_SECP256R1_SHAREDKEY_LEN;
        retVal = E_OK;
        break;
      case TCPIP_CURVE_ID_X25519:
        *LengthPtr = TCPIP_CURVE_ID_X25519_SHAREDKEY_LEN;
        retVal = E_OK;
        break;
      case TCPIP_CURVE_ID_X448:
        *LengthPtr = TCPIP_CURVE_ID_X448_SHAREDKEY_LEN;
        retVal = E_OK;
        break;
      default:
        /* Not supported curve */
        break;
    }
  }
  return retVal;
} /* TcpIp_Tls13CoreCtx_GetLengthOfEcdheSharedSecretFirstCoord() */

/**********************************************************************************************************************
 *  TcpIp_Tls13Core_GetHashLengthOfActiveCipherSuite
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Core_GetHashLengthOfActiveCipherSuite(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint8) CipherSuiteHashLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherDataType cipherSuiteId = TCPIP_TLS_CIPHER_INVALID;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the active ciphersuite. */
  Std_ReturnType retVal = TcpIp_Tls13Core_GetCipherSuiteFromActiveCipherWorker(TlsConIdx, &cipherSuiteId);

  if (retVal == E_OK)
  {
    /* #20 Get the hash length of the active ciphersuite. */
    retVal = TcpIp_Tls13Core_GetCipherSuiteHashLength(cipherSuiteId, CipherSuiteHashLenPtr);
  }

  if (retVal != E_OK)
  {
    *CipherSuiteHashLenPtr = 0u;
  }

  return retVal;
} /* TcpIp_Tls13Core_GetHashLengthOfActiveCipherSuite() */

/**********************************************************************************************************************
 *  TcpIp_Tls13Core_GetHashAlgorithmOfActiveCipherSuite
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Core_GetHashAlgorithmOfActiveCipherSuite(
  TcpIp_TlsConnectionIterType           TlsConIdx,
  TCPIP_P2V(TcpIp_TlsHashAlgorithmType) CipherSuiteHashAlgoPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherDataType cipherSuiteId = TCPIP_TLS_CIPHER_INVALID;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the active ciphersuite. */
  Std_ReturnType retVal = TcpIp_Tls13Core_GetCipherSuiteFromActiveCipherWorker(TlsConIdx, &cipherSuiteId);

  if (retVal == E_OK)
  {
    /* #20 Get the hash algorithm of the active ciphersuite. */
    retVal = TcpIp_Tls13Core_GetCipherSuiteHashAlgorithm(cipherSuiteId, CipherSuiteHashAlgoPtr);
  }

  if (retVal != E_OK)
  {
    *CipherSuiteHashAlgoPtr = TCPIP_HASH_ALGORITHM_NO_HASH;
  }

  return retVal;
} /* TcpIp_Tls13Core_GetHashAlgorithmOfActiveCipherSuite() */

/**********************************************************************************************************************
 *  TcpIp_Tls13Core_GetCipherSuiteHashLength
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Core_GetCipherSuiteHashAlgorithm(
  TcpIp_TlsCipherDataType                 CipherSuiteId,
  TCPIP_P2V(TcpIp_TlsHashAlgorithmType)   CipherSuiteHashAlgoPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* According to RFC 8446 - appendix B.4 */
  /* #10 Derive the hash algorithm of the passed cipher suite. */
  switch (CipherSuiteId)
  {
    case TCPIP_TLS_AES_128_GCM_SHA256:
    case TCPIP_TLS_CHACHA20_POLY1305_SHA256:
    case TCPIP_TLS_AES_128_CCM_SHA256:
    case TCPIP_TLS_AES_128_CCM_8_SHA256:
    {
      *CipherSuiteHashAlgoPtr = TCPIP_HASH_ALGORITHM_SHA256;
      retVal = E_OK;
      break;
    }

    case TCPIP_TLS_AES_256_GCM_SHA384:
    {
      *CipherSuiteHashAlgoPtr = TCPIP_HASH_ALGORITHM_SHA384;
      retVal = E_OK;
      break;
    }

    default:
    {
      /* Unsupported cipher suite */
      *CipherSuiteHashAlgoPtr = TCPIP_HASH_ALGORITHM_NO_HASH;
      retVal = E_NOT_OK;
      break;
    }
  }

  return retVal;
} /* TcpIp_Tls13Core_GetCipherSuiteHashLength() */

/**********************************************************************************************************************
 *  TcpIp_Tls13Core_GetCipherSuiteHashLength
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Core_GetCipherSuiteHashLength(
  TcpIp_TlsCipherDataType     CipherSuiteId,
  TCPIP_P2V(uint8)            CipherSuiteHashLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* According to RFC 8446 - appendix B.4 */
  /* #10 Derive the hash length of the passed cipher suite. */
  switch (CipherSuiteId)
  {
    case TCPIP_TLS_AES_128_GCM_SHA256:
    case TCPIP_TLS_CHACHA20_POLY1305_SHA256:
    case TCPIP_TLS_AES_128_CCM_SHA256:
    case TCPIP_TLS_AES_128_CCM_8_SHA256:
    {
      *CipherSuiteHashLenPtr = TCPIP_TLS_HASH_SHA256_LEN;
      retVal = E_OK;
      break;
    }

    case TCPIP_TLS_AES_256_GCM_SHA384:
    {
      *CipherSuiteHashLenPtr = TCPIP_TLS_HASH_SHA384_LEN;
      retVal = E_OK;
      break;
    }

    default:
    {
      /* Unsupported cipher suite */
      *CipherSuiteHashLenPtr = 0u;
      retVal = E_NOT_OK;
      break;
    }
  }

  return retVal;
} /* TcpIp_Tls13Core_GetCipherSuiteHashLength() */

/**********************************************************************************************************************
 *  TcpIp_Tls13Core_GetKeyLengthOfActiveCipherSuite
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Core_GetKeyLengthOfActiveCipherSuite(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint8) CipherSuiteKeyLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherDataType cipherSuiteId = TCPIP_TLS_CIPHER_INVALID;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the active ciphersuite. */
  Std_ReturnType retVal = TcpIp_Tls13Core_GetCipherSuiteFromActiveCipherWorker(TlsConIdx, &cipherSuiteId);

  if (retVal == E_OK)
  {
    /* #20 Get the hash length of the active ciphersuite. */
    retVal = TcpIp_Tls13Core_GetCipherSuiteKeyLength(cipherSuiteId, CipherSuiteKeyLenPtr);
  }

  if (retVal != E_OK)
  {
    *CipherSuiteKeyLenPtr = 0u;
  }

  return retVal;
} /* TcpIp_Tls13Core_GetKeyLengthOfActiveCipherSuite() */

/**********************************************************************************************************************
 *  TcpIp_Tls13Core_GetCipherSuiteKeyLength
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Core_GetCipherSuiteKeyLength(
  TcpIp_TlsCipherDataType     CipherSuiteId,
  TCPIP_P2V(uint8)            CipherSuiteKeyLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* According to RFC 8446 - appendix B.4 */
  /* #10 Derive the key length of the passed cipher suite. */
  switch (CipherSuiteId)
  {
    case TCPIP_TLS_AES_128_GCM_SHA256:
    case TCPIP_TLS_AES_128_CCM_SHA256:
    case TCPIP_TLS_AES_128_CCM_8_SHA256:
    {
      *CipherSuiteKeyLenPtr = TCPIP_TLS_BLOCK128_KEY_LEN;
      retVal = E_OK;
      break;
    }

    case TCPIP_TLS_AES_256_GCM_SHA384:
    case TCPIP_TLS_CHACHA20_POLY1305_SHA256:
    {
      *CipherSuiteKeyLenPtr = TCPIP_TLS_AES256_GCM_KEY_LEN;
      retVal = E_OK;
      break;
    }

    default:
    {
      /* Unsupported cipher suite */
      *CipherSuiteKeyLenPtr = 0u;
      retVal = E_NOT_OK;
      break;
    }
  }

  return retVal;
} /* TcpIp_Tls13Core_GetCipherSuiteKeyLength() */

/**********************************************************************************************************************
 *  TcpIp_Tls13Core_GetCipherSuiteFromActiveCipherWorker
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Core_GetCipherSuiteFromActiveCipherWorker(
  TcpIp_TlsConnectionIterType        TlsConIdx,
  TCPIP_P2V(TcpIp_TlsCipherDataType) CipherSuiteIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* Check if the active Rx cipher and Tx cipher are the same.
   * If they aren't it is not defined which should be returned. */
  if (TcpIp_GetActiveCipherRxOfTlsConnectionDyn(TlsConIdx) == TcpIp_GetActiveCipherTxOfTlsConnectionDyn(TlsConIdx))
  {
    if (TcpIp_GetActiveCipherRxOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_NULL_WITH_NULL_NULL)
    {
      /* If the active cipher is not set yet (=TCPIP_TLS_NULL_WITH_NULL_NULL),
       * that only means that decryption is not yet activated.
       * Nevertheless it is still possible that an active cipherworker is set
       * and we can return its ciphersuite. */
      TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx =
        TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
      if (activeTlsCipherWorkerIdx != TCPIP_NO_TLSCIPHERWORKERACTIVEIDXOFTLSCONNECTIONDYN)
      {
        TcpIp_TlsCipherDefinitionIdxOfTlsCipherWorkerType tlsCipherDefinitionIdx
          = TcpIp_GetTlsCipherDefinitionIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx);

        /* Get the corresponding Cipher Id (HexCode) */
        TcpIp_CipherSuiteIdOfTlsCipherDefinitionType selectedCipherSuiteId
          = TcpIp_GetCipherSuiteIdOfTlsCipherDefinition(tlsCipherDefinitionIdx);

        /* #10 Return the active cipherworker's ciphersuite. */
        *CipherSuiteIdPtr = selectedCipherSuiteId;
        retVal = E_OK;
      } /* else - No active cipherworker, return E_NOT_OK */
    }
    else
    {
      /* #20 Return the active Rx / Tx cipher. */
      *CipherSuiteIdPtr = TcpIp_GetActiveCipherRxOfTlsConnectionDyn(TlsConIdx);
      retVal = E_OK;
    }
  } /* else - active Rx cipher and Tx cipher are different, return E_NOT_OK */

  if (retVal != E_OK)
  {
    *CipherSuiteIdPtr = TCPIP_TLS_CIPHER_INVALID;
  }

  return retVal;
} /* TcpIp_Tls13Core_GetCipherSuiteFromActiveCipherWorker() */

/**********************************************************************************************************************
 *  TcpIp_Tls13Core_HandleExpiredTls13PskIdentity
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_Tls13Core_HandleExpiredTls13PskIdentity(
  TcpIp_Tls13PskIdentityIterType          Tls13PskIdentityIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsConnectionIterType pskIdentityActiveInThisResumedTlsConIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize the expired PSK identity. */
  TcpIp_Tls13Core_InitializePskIdentity(Tls13PskIdentityIdx);

  /* #20 Check if the PSK identity was already allocated to a TLS connection. */
  /* This is done in the TcpIp_ChangeParameter() call for session resumption
   * when the PSK identity switches to the state TCPIP_TLS_SESSION_TICKET_RESERVED. */
  if (TcpIp_Tls13Core_GetTlsConnectionWithThisActivePskIdentity(Tls13PskIdentityIdx,
        &pskIdentityActiveInThisResumedTlsConIdx) == E_OK)
  {
    /* #30 If so, remove that allocation and set variable that TLS connection must execute an ECC handshake instead. */
    TcpIp_SetTls13PskIdentityActiveIdxOfTlsConnectionDyn(pskIdentityActiveInThisResumedTlsConIdx,
      TCPIP_NO_TLS13PSKIDENTITYACTIVEIDXOFTLSCONNECTIONDYN);
    TcpIp_SetSessionResumptionUsingPskOfTlsConnectionDyn(pskIdentityActiveInThisResumedTlsConIdx, FALSE);
  }

}

/**********************************************************************************************************************
 *  TcpIp_Tls13Core_GetTlsConnectionWithThisActivePskIdentity
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Core_GetTlsConnectionWithThisActivePskIdentity(
  TcpIp_Tls13PskIdentityIterType          Tls13PskIdentityIdx,
  TCPIP_P2V(TcpIp_TlsConnectionIterType)  FoundTlsConIdxPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  TcpIp_TlsConnectionIterType conIdxWithThisActivePskIdentity = TcpIp_GetSizeOfTlsConnection();
  TcpIp_TlsConnectionIterType iterTlsConIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Find the TLS connection index with the passed PSK identity index set as active. */
  for (; iterTlsConIdx < TcpIp_GetSizeOfTlsConnection(); iterTlsConIdx++)
  {
    if (TcpIp_GetTls13PskIdentityActiveIdxOfTlsConnectionDyn(iterTlsConIdx) == Tls13PskIdentityIdx)
    {
      conIdxWithThisActivePskIdentity = iterTlsConIdx;
      retVal = E_OK;
      break;
    }
  }
  *FoundTlsConIdxPtr = conIdxWithThisActivePskIdentity;
  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13Core_InitializePskIdentity
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(void, TCPIP_CODE) TcpIp_Tls13Core_InitializePskIdentity(
  TcpIp_Tls13PskIdentityIterType Tls13PskIdentityIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize a TLS 1.3 PSK identity */
  TcpIp_SetSessionTicketStateOfTls13PskIdentityDyn(Tls13PskIdentityIdx, TCPIP_TLS_SESSION_TICKET_EMPTY);
  TcpIp_SetCountDownTicketLifetimeOfTls13PskIdentityDyn(Tls13PskIdentityIdx, 0u);
  TcpIp_SetMaxTicketAgeOfTls13PskIdentityDyn(Tls13PskIdentityIdx, 0u);
  TcpIp_SetTicketAgeAddOfTls13PskIdentityDyn(Tls13PskIdentityIdx, 0u);
  TcpIp_SetPskIdentityLenOfTls13PskIdentityDyn(Tls13PskIdentityIdx, 0u);
  TcpIp_SetHashLengthOfTls13PskIdentityDyn(Tls13PskIdentityIdx, 0u);
  TcpIp_SetPskNonceLenOfTls13PskIdentityDyn(Tls13PskIdentityIdx, 0u);
  TcpIp_SetPskSetViaSessionTicketOfTls13PskIdentityDyn(Tls13PskIdentityIdx, FALSE);
  TcpIp_SetHkdfAlgorithmOfTls13PskIdentityDyn(Tls13PskIdentityIdx, TCPIP_TLS_MSG_AUTH_MODE_NONE);
  TcpIp_SetUsedCurveOfTls13PskIdentityDyn(Tls13PskIdentityIdx, TCPIP_CURVE_ID_NO_CURVE);
} /* TcpIp_Tls13Core_InitializePskIdentity() */

#  if (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13CoreMainFunction_TxNss
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_Tls13CoreMainFunction_TxNss(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* In TcpIp_TlsCoreMainFunction_TxNss() it was checked
   * that the active cipherworker and the active handshake indices are valid. */
  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx =
    TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx);

  /* ----- Implementation ----------------------------------------------- */
  if (TcpIp_IsNssHandshakeTrafficSecretReadyToSendOfTlsConnectionDyn(TlsConIdx) == TRUE)
  {
    TcpIp_CsmKeyIdType serverHandshakeTrafficSecretKeyId =
      TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfServerAdHsTrafficSecretIdxOfTlsHandshake(activeTlsHandshakeIdx));
    TcpIp_CsmKeyIdType clientHandshakeTrafficSecretKeyId =
      TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfClientAdHsTrafficSecretIdxOfTlsHandshake(activeTlsHandshakeIdx));

    /* Handshake traffic secrets shall be send. Therefore, SendingType is set to
     * TCPIP_TLS_NSS_FRAME_SEND_HANDSHAKE_TRAFFIC_SECRETS */
    /* #10 Trigger sending NSS Key Log Frame with handshake traffic secrets */
    if (TcpIp_Tls13CoreCtx_SendTrafficSecretsViaNssFrame(
      TlsConIdx,
      serverHandshakeTrafficSecretKeyId,
      clientHandshakeTrafficSecretKeyId,
      TCPIP_TLS_NSS_FRAME_SEND_HANDSHAKE_TRAFFIC_SECRETS) == E_OK)
    {
      TcpIp_SetNssHandshakeTrafficSecretReadyToSendOfTlsConnectionDyn(TlsConIdx, FALSE);
    }
  }
  else if (TcpIp_IsNssApplicationTrafficSecretReadyToSendOfTlsConnectionDyn(TlsConIdx) == TRUE)
  {
    TcpIp_CsmKeyIdType serverApplicationTrafficSecretKeyId =
      TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfServerAdHsTrafficSecretIdxOfTlsHandshake(activeTlsHandshakeIdx));
    TcpIp_CsmKeyIdType clientApplicationTrafficSecretKeyId =
      TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfClientAdHsTrafficSecretIdxOfTlsHandshake(activeTlsHandshakeIdx));

    /* Application traffic secrets shall be send. Therefore, SendingType is set to
     * TCPIP_TLS_NSS_FRAME_SEND_APPLICATION_TRAFFIC_SECRETS */
    /* #20 Trigger sending NSS Key Log Frame with application traffic secrets */
    if (TcpIp_Tls13CoreCtx_SendTrafficSecretsViaNssFrame(
      TlsConIdx,
      serverApplicationTrafficSecretKeyId,
      clientApplicationTrafficSecretKeyId,
      TCPIP_TLS_NSS_FRAME_SEND_APPLICATION_TRAFFIC_SECRETS) == E_OK)
    {
      TcpIp_SetNssApplicationTrafficSecretReadyToSendOfTlsConnectionDyn(TlsConIdx, FALSE);
    }
  }
  else
  {
    /* No NSS Frame is ready to send - continue */
  }
} /* TcpIp_Tls13CoreMainFunction_TxNss() */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_SendTrafficSecretsViaNssFrame
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_SendTrafficSecretsViaNssFrame(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TcpIp_CsmKeyIdType            ServerSecretCsmKeyId,
  TcpIp_CsmKeyIdType            ClientSecretCsmKeyId,
  TcpIp_TlsNssFrameSendingType  SendingType)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  const uint8 TcpIp_Tls13_NssFrameSecretLabel_CHsTraffic[] = "CLIENT_HANDSHAKE_TRAFFIC_SECRET";
  const uint8 TcpIp_Tls13_NssFrameSecretLabel_SHsTraffic[] = "SERVER_HANDSHAKE_TRAFFIC_SECRET";
  const uint8 TcpIp_Tls13_NssFrameSecretLabel_HsTraffic_Len = 31u;
  const uint8 TcpIp_Tls13_NssFrameSecretLabel_CAdTraffic[] = "CLIENT_TRAFFIC_SECRET_0";
  const uint8 TcpIp_Tls13_NssFrameSecretLabel_SAdTraffic[] = "SERVER_TRAFFIC_SECRET_0";
  const uint8 TcpIp_Tls13_NssFrameSecretLabel_AdTraffic_Len = 23u;
  TCPIP_P2C(uint8) clientlabelPtr = NULL_PTR;
  TCPIP_P2C(uint8) serverlabelPtr = NULL_PTR;
  uint8 labelLen = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the labels and their lengths depending on if handshake or application traffic secrets shall be send. */
  if (SendingType == TCPIP_TLS_NSS_FRAME_SEND_HANDSHAKE_TRAFFIC_SECRETS)
  {
    labelLen = TcpIp_Tls13_NssFrameSecretLabel_HsTraffic_Len;
    clientlabelPtr = &TcpIp_Tls13_NssFrameSecretLabel_CHsTraffic[0];
    serverlabelPtr = &TcpIp_Tls13_NssFrameSecretLabel_SHsTraffic[0];
    retVal = E_OK;
  }
  else if (SendingType == TCPIP_TLS_NSS_FRAME_SEND_APPLICATION_TRAFFIC_SECRETS) /* Send application traffic secrets */
  {
    labelLen = TcpIp_Tls13_NssFrameSecretLabel_AdTraffic_Len;
    clientlabelPtr = &TcpIp_Tls13_NssFrameSecretLabel_CAdTraffic[0];
    serverlabelPtr = &TcpIp_Tls13_NssFrameSecretLabel_SAdTraffic[0];
    retVal = E_OK;
  }
  else
  {
    /* retVal is already E_NOT_OK */
  }

  if (retVal == E_OK)
  {
    /* #20 Send the server secret via NSS frame. */
    retVal = TcpIp_TlsCore_SendSecretViaNssFrame(
      TlsConIdx,
      ServerSecretCsmKeyId,
      CRYPTO_KE_KEYDERIVATION_PASSWORD,
      serverlabelPtr,
      labelLen);
  }

  if (retVal == E_OK)
  {
    /* #30 Send the client secret via NSS frame. */
    retVal = TcpIp_TlsCore_SendSecretViaNssFrame(
      TlsConIdx,
      ClientSecretCsmKeyId,
      CRYPTO_KE_KEYDERIVATION_PASSWORD,
      clientlabelPtr,
      labelLen);
  }

  return retVal;
}
#  endif /* (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DeleteHandshakeKeys
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_DeleteHandshakeKeys(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx
    = TCPIP_NO_TLSHANDSHAKEACTIVEIDXOFTLSCIPHERWORKERDYN;

  /* ----- Implementation ----------------------------------------------- */
  if (TcpIp_TlsCoreUtil_IsActiveHandshakeSet(TlsConIdx) == TRUE)
  {
    activeTlsHandshakeIdx = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx);

    TcpIp_TlsCsmJobIterType signatureGenerateTlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
      TcpIp_GetCsmJobIdKeyExchangeSignatureGenerateIdxOfTlsHandshake(activeTlsHandshakeIdx));

    TcpIp_TlsCsmJobIterType macGenerateTlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
      TcpIp_GetCsmJobIdHmacGenerateIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));

    TcpIp_TlsCsmJobIterType decryptTlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
      TcpIp_GetCsmJobIdCipherDecryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));

    TcpIp_TlsCsmJobIterType encryptTlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
      TcpIp_GetCsmJobIdCipherEncryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));

    /* Return values are connected via or-operation to ensure that all keys were deleted.
     * If one deletion fails, the others are still executed while propagating the failure to the caller. */

    /* #10 Delete Shared Secret */
    retVal = TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
      TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfSharedSecretIdxOfTlsHandshake(activeTlsHandshakeIdx)),
      CRYPTO_KE_KEYDERIVATION_PASSWORD);

    /* #20 Delete Derived Secret */
    retVal |= TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
      TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfDerivedSecretIdxOfTlsHandshake(activeTlsHandshakeIdx)),
      CRYPTO_KE_KEYDERIVATION_PASSWORD);

    /* #30 Delete Client Handshake Secret */
    retVal |= TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
      TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfClientAdHsTrafficSecretIdxOfTlsHandshake(activeTlsHandshakeIdx)),
      CRYPTO_KE_KEYDERIVATION_PASSWORD);

    /* #40 Delete Server Handshake Secret */
    retVal |= TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
      TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfServerAdHsTrafficSecretIdxOfTlsHandshake(activeTlsHandshakeIdx)),
      CRYPTO_KE_KEYDERIVATION_PASSWORD);

    /* #50 Delete Signature Generate Key */
    retVal |= TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
      TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(signatureGenerateTlsCsmJobIdx),
      CRYPTO_KE_SIGNATURE_KEY);

    /* #60 Delete MAC Generate Key */
    retVal |= TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
      TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(macGenerateTlsCsmJobIdx),
      CRYPTO_KE_MAC_KEY);

    /* #70 Delete Client Handshake Active Key */
    retVal |= TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
      TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(encryptTlsCsmJobIdx),
      CRYPTO_KE_CIPHER_KEY);

    /* #80 Delete Server Handshake Active Key */
    retVal |= TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
      TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(decryptTlsCsmJobIdx),
      CRYPTO_KE_CIPHER_KEY);

    /* #90 Delete Client Handshake Passive Key */
    retVal |= TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
      TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdCipherPassiveEncryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx)),
      CRYPTO_KE_CIPHER_KEY);

    /* #100 Delete Server Handshake Passive Key */
    retVal |= TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
      TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdCipherPassiveDecryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx)),
      CRYPTO_KE_CIPHER_KEY);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DeleteApplicationTrafficKeys
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_DeleteApplicationTrafficKeys(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx
    = TCPIP_NO_TLSHANDSHAKEACTIVEIDXOFTLSCIPHERWORKERDYN;

  /* ----- Implementation ----------------------------------------------- */
  if (TcpIp_TlsCoreUtil_IsActiveHandshakeSet(TlsConIdx) == TRUE)
  {
    activeTlsHandshakeIdx = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx);

    TcpIp_TlsCsmJobIterType encryptTlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
      TcpIp_GetCsmJobIdCipherEncryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));

    TcpIp_TlsCsmJobIterType decryptTlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
      TcpIp_GetCsmJobIdCipherDecryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));

    /* Return values are connected via or-operation to ensure that all keys were deleted.
     * If one deletion fails, the others are still executed while propagating the failure to the caller. */

    /* #10 Client Application Secret */
    retVal = TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
      TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfClientAdHsTrafficSecretIdxOfTlsHandshake(activeTlsHandshakeIdx)),
      CRYPTO_KE_KEYDERIVATION_PASSWORD);

    /* #20 Server Application Secret */
    retVal |= TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
      TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfServerAdHsTrafficSecretIdxOfTlsHandshake(activeTlsHandshakeIdx)),
      CRYPTO_KE_KEYDERIVATION_PASSWORD);

    /* #30 Client Application Active Key */
    retVal |= TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
      TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(encryptTlsCsmJobIdx),
      CRYPTO_KE_CIPHER_KEY);

    /* #40 Server Application Active Key */
    retVal |= TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
      TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(decryptTlsCsmJobIdx),
      CRYPTO_KE_CIPHER_KEY);

    /* #50 Client Application Passive Key */
    retVal |= TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
      TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdCipherPassiveEncryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx)),
      CRYPTO_KE_CIPHER_KEY);

    /* #60 Server Application Passive Key */
    retVal |= TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
      TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdCipherPassiveDecryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx)),
      CRYPTO_KE_CIPHER_KEY);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DeleteTemporaryKeys
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_DeleteTemporaryKeys(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx
    = TCPIP_NO_TLSHANDSHAKEACTIVEIDXOFTLSCIPHERWORKERDYN;

  /* ----- Implementation ----------------------------------------------- */
  if (TcpIp_TlsCoreUtil_IsActiveHandshakeSet(TlsConIdx) == TRUE)
  {
    activeTlsHandshakeIdx = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx);

    /* Return values are connected via or-operation to ensure that all keys were deleted.
     * If one deletion fails, the others are still executed while propagating the failure to the caller. */

    /* #10 Temporary Buffer Key */
    retVal = TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
      TcpIp_GetHsTemporaryBufferKeyIdOfTlsHandshake(activeTlsHandshakeIdx),
      TcpIp_GetHsCommonKeyElementIdOfTlsHandshake(activeTlsHandshakeIdx));

    /* #20 Temporary HKDF Key */
    retVal |= TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
      TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdTemporaryHkdfKeyIdxOfTlsHandshake(activeTlsHandshakeIdx)),
      TcpIp_GetHsCommonKeyElementIdOfTlsHandshake(activeTlsHandshakeIdx));
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DeleteResumptionKeys
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_DeleteResumptionKeys(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if connection is configured for session resumption. */
  if (TcpIp_IsCsmKeyIdResumptionMasterSecretUsedOfTlsConnection(TlsConIdx) == TRUE)
  {
    /* The connection is a session resumption capable connection. */

    /* #20 Check what kind of session resumption connection this is. */
    if (TcpIp_GetTlsResumedConnectionIdxOfTlsConnection(TlsConIdx) == TCPIP_NO_TLSRESUMEDCONNECTIONIDXOFTLSCONNECTION)
    {
      /* #30 The connection is a resumption base connection. Delete the resumption master secret. */

      retVal = TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
        TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdResumptionMasterSecretIdxOfTlsConnection(TlsConIdx)),
        CRYPTO_KE_KEYDERIVATION_PASSWORD);

      /* The available tickets that are related to this resumption base connection will be deleted later in TcpIp_TlsCoreConnection_Init() */
    }
    else
    {
      /* #40 The connection is configured to be a resumed connection. Delete its keys if necessary. */
      retVal = TcpIp_Tls13CoreCtx_DeleteResumptionKeysFromResumedConnection(TlsConIdx);
    }
  }
  else
  {
    /* Connection is not related to session resumption, nothing to do. */
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DeleteResumptionKeysFromResumedConnection
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_DeleteResumptionKeysFromResumedConnection(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* The connection is configured to be a resumed connection, but still could be used for other use cases. */

  TcpIp_Tls13PskIdentityIterType activeTls13PskIdentityIdx
    = TcpIp_GetTls13PskIdentityActiveIdxOfTlsConnectionDyn(TlsConIdx);  /* was set in ChangeParameter context */

  /* #10 Check if the connection is used as a resumed connection or without session resumption. */
  if (activeTls13PskIdentityIdx != TCPIP_NO_TLS13PSKIDENTITYACTIVEIDXOFTLSCONNECTIONDYN)  /* has an active PSK identity -> is a resumed connection */
  {
    /* #20 This is a resumed connection. Delete its keys. */

    /* Delete the resumption master secret. */
    retVal = TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
      TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdResumptionMasterSecretIdxOfTlsConnection(TlsConIdx)),
      CRYPTO_KE_KEYDERIVATION_PASSWORD);

    /* Delete the keys of the PSK. */
    TcpIp_TlsSessionTicketStateType sessionTicketState =
      TcpIp_GetSessionTicketStateOfTls13PskIdentityDyn(activeTls13PskIdentityIdx);
    if (sessionTicketState == TCPIP_TLS_SESSION_TICKET_RESERVED)
    {
      /* Ticket is only reserved but no keys are calculated, yet. */
      /* The resumption master secret has already been deleted in the previous step. */
    }
    else if (sessionTicketState == TCPIP_TLS_SESSION_TICKET_IN_USE)
    {
      /* Ticket is in use. The resumption master secret is already deleted. Delete calculated keys. */

      /* Delete keys in the PSK identity */
      retVal |= TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
        TcpIp_GetPskCsmKeyIdOfTls13PskIdentity(activeTls13PskIdentityIdx),  /* preSharedKeyId */
        TCPIP_CRYPTO_30_LIBCV_KE_TARGET_KEY);

      retVal |= TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
        TcpIp_GetPskTemporaryCsmKeyIdOfTls13PskIdentity(activeTls13PskIdentityIdx),  /* temporaryKeyId */
        TCPIP_CRYPTO_30_LIBCV_KE_TARGET_KEY);
    }
    else
    {
      /* invalid state, this should never occur */
      TCPIP_ASSERT_UNREACHABLE();
    }
  }
  else
  {
    /* #30 The connection is not used as a resumed connection -> nothing to do. */
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DeleteConnectionKeys
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_DeleteConnectionKeys(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */

  /* Return values are connected via or-operation to ensure that all keys were deleted.
   * If one deletion fails, the others are still executed while propagating the failure to the caller. */

  /* #10 Delete keys and secrets used in the handshake */
  retVal = TcpIp_Tls13CoreCtx_DeleteHandshakeKeys(TlsConIdx);

  /* #20 Delete keys and secrets used for the application data */
  retVal |= TcpIp_Tls13CoreCtx_DeleteApplicationTrafficKeys(TlsConIdx);

  /* #30 Delete temporary keys and secrets */
  retVal |= TcpIp_Tls13CoreCtx_DeleteTemporaryKeys(TlsConIdx);

  /* #40 Delete resumption related keys and secrets */
  retVal |= TcpIp_Tls13CoreCtx_DeleteResumptionKeys(TlsConIdx);

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_SwitchToApplicationKeyRx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_SwitchToApplicationKeyRx(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx =
    TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_CsmKeyIdType handshakePassiveDecryptKeyId
    = TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdCipherPassiveDecryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));
  TcpIp_TlsCsmJobIterType decryptTlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
    TcpIp_GetCsmJobIdCipherDecryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));
  TcpIp_CsmKeyIdType handshakeDecryptKeyId
    = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(decryptTlsCsmJobIdx);

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Calculate the application traffic secrets and keys */
  TcpIp_Tls13CoreCtx_CalcApplicationKeys(TlsConIdx);

  /* Immediately switch to the calculated decrypt key.
   * For that copy the content of the passive key to the active one.
   * The return value can't be processed here.
   * The encrypt key is not yet switched
   * since the TLS 1.3 client finished is still encrypted with the handshake traffic keys,
   * wait for it to be send before switching to application traffic keys.
   * The switch is implemented in TcpIp_Tls13ClientHsStm_FinalizeHandshake(). */
  retVal = TcpIp_Tls13CoreCtx_CopyKeyAndIv(handshakePassiveDecryptKeyId, handshakeDecryptKeyId);

  /* #20 Reset the rx sequence number, since the key changed. */
  TcpIp_SetRlRxSequenceCounterOfTlsConnectionDyn(TlsConIdx, 0);

  /* The last sequence number is used to get the IV from the CRYPTO_KE_CIPHER_IV element
   * of the CSM Key AdHsTrafficSecret in TcpIp_Tls13CoreCrypto_GenerateAEADBlock128Iv().
   * Normally the last nonce would be written into this element,
   * but TcpIp_Tls13CoreCtx_CalcApplicationKeys writes the newly calculated IV into this element as well.
   * Therefore TcpIp_Tls13CoreCrypto_GenerateAEADBlock128Iv() already gets the IV now.
   * Reset the last rx sequence number to avoid an alteration of the IV
   * in TcpIp_Tls13CoreCrypto_GenerateAEADBlock128Iv(). */
  TcpIp_SetLastRlRxSequenceCounterOfTlsConnectionDyn(TlsConIdx, 0);

  TcpIp_SetCalcApplTrafficKeysAsyncFlagOfTlsConnectionDyn(TlsConIdx, FALSE);

  /* #30 After the new keys are calculated blocking the decryption of new RL frames can be disabled */
  TcpIp_SetBlockDecryptOperationsUntilKeysAreCalculatedOfTlsConnectionDyn(TlsConIdx, FALSE);

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_SwitchToHandshakeKeys
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_SwitchToHandshakeKeys(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx =
    TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  /* Get the selected cipher suite to switch the encryption mode after calculating the keys. */
  TcpIp_TlsCipherDefinitionIdxOfTlsCipherWorkerType tlsCipherDefinitionIdx
    = TcpIp_GetTlsCipherDefinitionIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx);
  TcpIp_CipherSuiteIdOfTlsCipherDefinitionType selectedCipherSuiteId
    = TcpIp_GetCipherSuiteIdOfTlsCipherDefinition(tlsCipherDefinitionIdx); /* Get the corresponding Cipher Id (HexCode) */
  /* Get the Csm key Ids of passive and active de-/encrypt keys. */
  TcpIp_CsmKeyIdType handshakePassiveEncryptKeyId
    = TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdCipherPassiveEncryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));
  TcpIp_CsmKeyIdType handshakePassiveDecryptKeyId
    = TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdCipherPassiveDecryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));
  TcpIp_TlsCsmJobIterType encryptTlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
    TcpIp_GetCsmJobIdCipherEncryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));
  TcpIp_CsmKeyIdType handshakeEncryptKeyId
    = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(encryptTlsCsmJobIdx);
  TcpIp_TlsCsmJobIterType decryptTlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
    TcpIp_GetCsmJobIdCipherDecryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));
  TcpIp_CsmKeyIdType handshakeDecryptKeyId
    = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(decryptTlsCsmJobIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Calculate the handshake traffic secrets and keys. These are saved in the Csm passive key containers. */
  if (TcpIp_Tls13CoreCtx_CalcHandshakeKeys(TlsConIdx) == E_OK)
  {
    /* #20 Immediately switch to the calculated keys. */
    /* For that copy the content of the passive keys to the active ones. */
    /* We also switch to the handshake encrypt key here despite the RFC8446 in appendix A.1 specifying that
     * the Tx key is only switched to handshake when the Server Finished message is received,
     * since it also specifies that clients should rekey to the handshake keys if possible.
     * Since the calculation of the handshake keys was successful it is always possible
     * and we directly switch the keys instead of switching if we want to send something. */
    if ((TcpIp_Tls13CoreCtx_CopyKeyAndIv(handshakePassiveDecryptKeyId, handshakeDecryptKeyId) == E_OK))
    {
      retVal = TcpIp_Tls13CoreCtx_CopyKeyAndIv(handshakePassiveEncryptKeyId, handshakeEncryptKeyId);
    }
  }
  if (retVal == E_OK)
  {
    /* #30 Reset the rx and tx sequence numbers, since the keys changed. */
    TcpIp_SetRlTxSequenceCounterOfTlsConnectionDyn(TlsConIdx, 0);
    TcpIp_SetRlRxSequenceCounterOfTlsConnectionDyn(TlsConIdx, 0);

    /* #40 Trigger the record layer to switch the keys and to start using the encryption for Tx and Rx. */
    TcpIp_SetActiveCipherRxOfTlsConnectionDyn(TlsConIdx, selectedCipherSuiteId);
    TcpIp_SetActiveCipherTxOfTlsConnectionDyn(TlsConIdx, selectedCipherSuiteId);
  }

  TcpIp_SetCalcHsTrafficKeysAsyncFlagOfTlsConnectionDyn(TlsConIdx, FALSE);

  /* After the new keys are calculated blocking the decryption of new RL frames can be disabled */
  TcpIp_SetBlockDecryptOperationsUntilKeysAreCalculatedOfTlsConnectionDyn(TlsConIdx, FALSE);

  return retVal;
} /* TcpIp_Tls13CoreCtx_SwitchToHandshakeKeys */


/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_CalcHandshakeKeysGetParameters
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_CalcHandshakeKeysGetParameters(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint8) HashLengthPtr,
  TCPIP_P2V(uint8) KeyLengthPtr,
  TCPIP_P2V(uint8) LengthOfFirstCoordinateECDHESecretPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Determine the hash length depending on the used cipher suite. */
  Std_ReturnType retVal = TcpIp_Tls13Core_GetHashLengthOfActiveCipherSuite(TlsConIdx, HashLengthPtr);

  if (retVal == E_OK)
  {
    /* #20 Determine the key length depending on the used cipher suite. */
    retVal = TcpIp_Tls13Core_GetKeyLengthOfActiveCipherSuite(TlsConIdx, KeyLengthPtr);
  }

  if (retVal == E_OK)
  {
    /* #30 Determine the length of the first coordinate of the shared secret */
    retVal = TcpIp_Tls13CoreCtx_GetLengthOfEcdheSharedSecretFirstCoord(TlsConIdx,
      LengthOfFirstCoordinateECDHESecretPtr);
  }
  return retVal;
}


/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DeriveClientAndServerHandshakeKeys
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_DeriveClientAndServerHandshakeKeys(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8                       HashLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx =
    TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx);

  TcpIp_CsmKeyIdType serverHandshakeTrafficSecretKeyId =
    TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfServerAdHsTrafficSecretIdxOfTlsHandshake(activeTlsHandshakeIdx));
  TcpIp_CsmKeyIdType clientHandshakeTrafficSecretKeyId =
    TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfClientAdHsTrafficSecretIdxOfTlsHandshake(activeTlsHandshakeIdx));
  TcpIp_CsmKeyIdType derivedSecretKeyId =
    TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfDerivedSecretIdxOfTlsHandshake(activeTlsHandshakeIdx));

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Calculate the Server/Client Handshake Secret. */

  /*                   |
   *                   v
         +-----> Derive-Secret(., "s hs traffic", ClientHello...ServerHello)
         +-----> Derive-Secret(., "c hs traffic", ClientHello...ServerHello)
   *
   */
  TcpIp_Tls13_DeriveSecretInput_Type deriveSecretInput = { 0 };
  {
    /* set general parameters */
    deriveSecretInput.TemporaryKeyId =
      TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdTemporaryHkdfKeyIdxOfTlsHandshake(activeTlsHandshakeIdx));
    deriveSecretInput.TemporaryKeyElementId =
      TcpIp_GetHsCommonKeyElementIdOfTlsHandshake(activeTlsHandshakeIdx);
    deriveSecretInput.AdditionalInfoKeyElementId =
      TcpIp_GetAdditionalInfoKeyElementIdOfTlsHandshake(activeTlsHandshakeIdx);
    deriveSecretInput.HkdfCalcJobId =
      TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfCalculationIdxOfTlsHandshake(activeTlsHandshakeIdx));
    deriveSecretInput.HashMessagesJobId =
      TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfHashMessagesJobIdIdxOfTlsHandshake(activeTlsHandshakeIdx));
    deriveSecretInput.HkdfHashLen = HashLength;
  }
  {
    /* Calculate the server handshake secret */
    deriveSecretInput.TargetKeyId = serverHandshakeTrafficSecretKeyId;
    deriveSecretInput.SaltKeyId = derivedSecretKeyId;
  }
  retVal = TcpIp_Tls13CoreCtx_DeriveSecretAndShortenHkdfKey(TlsConIdx, &deriveSecretInput,
    &TcpIp_Tls_Hs_Tls13Label_SHsTraffic[0], TCPIP_TLS_HS_TLS13LABEL_HSTRAFFIC_LEN, TRUE);

  {
    /* Calculate the client handshake secret */
    deriveSecretInput.TargetKeyId = clientHandshakeTrafficSecretKeyId;
    deriveSecretInput.SaltKeyId = derivedSecretKeyId;
  }
  retVal |= TcpIp_Tls13CoreCtx_DeriveSecretAndShortenHkdfKey(TlsConIdx, &deriveSecretInput,
    &TcpIp_Tls_Hs_Tls13Label_CHsTraffic[0], TCPIP_TLS_HS_TLS13LABEL_HSTRAFFIC_LEN, TRUE);

#  if (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON)
  TcpIp_SetNssHandshakeTrafficSecretReadyToSendOfTlsConnectionDyn(TlsConIdx, TRUE);
#  endif
#  if (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON)
  if (TcpIp_IsTlsUseKeyUpdateCalloutOfTlsConfig(TCPIP_TLSCONFIG_IDX))
  {
    (void)TcpIp_TlsCore_IssueKeyUpdateCallout(TlsConIdx, TCPIP_TLS_KEYUPDATE_NONE_TO_HANDSHAKE);
  }
#  endif

  /* #20 Calculate the Server/Client Handshake Key And IV. */
  retVal |= TcpIp_Tls13CoreCtx_CalculateKeyAndIvForEncryptionAndDecryption(TlsConIdx);

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_PrepareDerivationOfHandshakeTrafficSecret
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_PrepareDerivationOfHandshakeTrafficSecret(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8 HashLength,
  uint8 KeyLength,
  uint8 LengthOfFirstCoordinateECDHESecret)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Std_ReturnType csmRetVal = E_OK;
  /* Initialize the first used keys with 0 */
  uint8 initialPassword[TCPIP_TLS_SHAREDKEY_MAX_LEN];

  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx =
    TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx);

  TcpIp_CsmKeyIdType sharedSecretKeyId = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob((TcpIp_TlsCsmJobIterType)
    TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfCalculationIdxOfTlsHandshake(activeTlsHandshakeIdx)));
  TcpIp_CsmKeyIdType derivedSecretKeyId =
    TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfDerivedSecretIdxOfTlsHandshake(activeTlsHandshakeIdx));


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Calculate the Derived Secret. */

  /*  |
   *  v
     Derive - Secret(., "derived", "")
   *
   */
  VStdMemSet(&initialPassword[0u], TCPIP_TLS_INITIAL_PASSWORD_PLAIN_PATTERN, HashLength);

  /* Use the derivedSecretKeyId to provide the initial password (which is used as salt in input key).
   * This is a "0" string of Hash.length bytes set to zero (RFC8446 chapter 7.1). */
  csmRetVal = TcpIp_TlsCoreCrypto_SetCsmKeyElementAndSetKeyValid(derivedSecretKeyId,
    CRYPTO_KE_KEYDERIVATION_PASSWORD, &initialPassword[0], HashLength);

  if (csmRetVal == E_OK)
  {
    /* Use the sharedSecretKeyId to provide the initial input key for the derivedSecret. */
    if (TcpIp_IsSessionResumptionUsingPskOfTlsConnectionDyn(TlsConIdx) == TRUE)
    {
      /* When session resumption is active use the PSK as initial input. */
      TcpIp_CsmKeyIdType preSharedKeyId
        = TcpIp_GetPskCsmKeyIdOfTls13PskIdentity(TcpIp_GetTls13PskIdentityActiveIdxOfTlsConnectionDyn(TlsConIdx));
      csmRetVal = TCPIP_CSM_KeyElementCopyPartial(preSharedKeyId, CRYPTO_KE_KEYDERIVATION_PASSWORD, 0, 0, HashLength,
        sharedSecretKeyId, CRYPTO_KE_KEYDERIVATION_PASSWORD);

      if (csmRetVal == E_OK)
      {
        csmRetVal = TCPIP_CSM_KeySetValid(sharedSecretKeyId);
      }
    }
    else
    {
      /* If there is no PSK we use the zero filled key again :
       * "If a given secret is not available, then the 0-value consisting of a string of Hash.length bytes
       * set to zeros is used. Note that this does not mean skipping rounds, so if PSK is not in use, Early Secret
       * will still be HKDF - Extract(0, 0)." (RFC 8446 chapter 7.1) */
      csmRetVal = TcpIp_TlsCoreCrypto_SetCsmKeyElementAndSetKeyValid(sharedSecretKeyId,
        CRYPTO_KE_KEYDERIVATION_PASSWORD, &initialPassword[0], HashLength);
    }
  }

  if (csmRetVal == E_OK)
  {
    /* In the first iteration we use the sharedSecretKey for providing the initial key and the derivedSecretKey
     * for providing the initial salt. The derivedSecretKey is also used as output key to store the calculated
     * password. */
    TcpIp_Tls13_DeriveSecretInput_Type deriveSecretInput = { 0 };
    {
      /* set general parameters */
      deriveSecretInput.TemporaryKeyId =
        TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdTemporaryHkdfKeyIdxOfTlsHandshake(activeTlsHandshakeIdx));
      deriveSecretInput.TemporaryKeyElementId =
        TcpIp_GetHsCommonKeyElementIdOfTlsHandshake(activeTlsHandshakeIdx);
      deriveSecretInput.AdditionalInfoKeyElementId =
        TcpIp_GetAdditionalInfoKeyElementIdOfTlsHandshake(activeTlsHandshakeIdx);
      deriveSecretInput.HkdfCalcJobId =
        TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfCalculationIdxOfTlsHandshake(activeTlsHandshakeIdx));
      deriveSecretInput.HashMessagesJobId =
        TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfHashMessagesJobIdIdxOfTlsHandshake(activeTlsHandshakeIdx));
      deriveSecretInput.HkdfHashLen = HashLength;
    }
    {
      deriveSecretInput.TargetKeyId = derivedSecretKeyId;
      deriveSecretInput.SaltKeyId = derivedSecretKeyId;
    }
    csmRetVal = TcpIp_Tls13CoreCtx_DeriveSecretAndShortenHkdfKey(TlsConIdx, &deriveSecretInput,
      &TcpIp_Tls_Hs_Tls13Label_Derived[0], TCPIP_TLS_HS_TLS13LABEL_DERIVED_LEN, FALSE);
  }

  if (csmRetVal == E_OK)
  {
    /* Initialize the sharedSecret with the key length. */
    csmRetVal = TcpIp_TlsCoreCrypto_SetCsmKeyElementAndSetKeyValid(sharedSecretKeyId,
      CRYPTO_KE_KEYDERIVATION_PASSWORD, &initialPassword[0], KeyLength);
  }

  if (csmRetVal == E_OK)
  {
    /* Copy only the X coordinate of the calculated ECDHE secret to the SharedSecret Key. */
    csmRetVal = TCPIP_CSM_KeyElementCopyPartial(
      TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdKeyExchangeIdxOfTlsHandshake(activeTlsHandshakeIdx)),
      CRYPTO_KE_KEYDERIVATION_PASSWORD,
      0,
      0,
      LengthOfFirstCoordinateECDHESecret,
      sharedSecretKeyId,
      CRYPTO_KE_KEYDERIVATION_PASSWORD);
  }

  if (csmRetVal == E_OK)
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_CalcHandshakeKeys
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_CalcHandshakeKeys(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  uint8 hashLength = 0u;
  uint8 keyLength = 0u;
  uint8 lengthOfFirstCoordinateECDHESecret = 0u;

  /* ----- Implementation ----------------------------------------------- */
  if (TcpIp_Tls13CoreCtx_AreCsmKeyIdsValid(TlsConIdx) == TRUE)
  {
    /* #10 Determine the hash and the key length depending on the used cipher suite. */
    if (TcpIp_Tls13CoreCtx_CalcHandshakeKeysGetParameters(
      TlsConIdx, &hashLength, &keyLength, &lengthOfFirstCoordinateECDHESecret) == E_OK)
    {
      /* #20 Derive shared and derived secret for handshake traffic */
      retVal = TcpIp_Tls13CoreCtx_PrepareDerivationOfHandshakeTrafficSecret(
        TlsConIdx,
        hashLength,
        keyLength,
        lengthOfFirstCoordinateECDHESecret);

      if (retVal == E_OK)
      {
        /* Derive handshake traffic secrets and keys for client and server */
        retVal = TcpIp_Tls13CoreCtx_DeriveClientAndServerHandshakeKeys(TlsConIdx, hashLength);
      }

      /* Set the async state to DONE */
      TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);
    }
#  if ( TCPIP_DEV_ERROR_DETECT == STD_ON )
    else
    {
      /* Memory runtime check fails - report DET */
      TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
    }
#  endif
    if (retVal != E_OK)
    {
      /* Trigger alert internal_error */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
    }
  }
  else
  {
    TcpIp_TlsCoreUtil_HandleInvalidConfiguration(TlsConIdx);
  }
  return retVal;
} /* TcpIp_Tls13CoreCtx_CalcHandshakeKeys() */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DeriveClientAndServerApplicationKeys
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_DeriveClientAndServerApplicationKeys(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8                       HashLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx =
    TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx);

  TcpIp_CsmKeyIdType derivedSecretKeyId =
    TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfDerivedSecretIdxOfTlsHandshake(activeTlsHandshakeIdx));
  TcpIp_CsmKeyIdType serverApplicationTrafficSecretKeyId =
    TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfServerAdHsTrafficSecretIdxOfTlsHandshake(activeTlsHandshakeIdx));
  TcpIp_CsmKeyIdType clientApplicationTrafficSecretKeyId =
    TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfClientAdHsTrafficSecretIdxOfTlsHandshake(activeTlsHandshakeIdx));


  /* ----- Implementation ----------------------------------------------- */
  TcpIp_Tls13_DeriveSecretInput_Type deriveSecretInput = { 0 };
  {
    /* set general parameters */
    deriveSecretInput.TemporaryKeyId =
      TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdTemporaryHkdfKeyIdxOfTlsHandshake(activeTlsHandshakeIdx));
    deriveSecretInput.TemporaryKeyElementId =
      TcpIp_GetHsCommonKeyElementIdOfTlsHandshake(activeTlsHandshakeIdx);
    deriveSecretInput.AdditionalInfoKeyElementId =
      TcpIp_GetAdditionalInfoKeyElementIdOfTlsHandshake(activeTlsHandshakeIdx);
    deriveSecretInput.HkdfCalcJobId =
      TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfCalculationIdxOfTlsHandshake(activeTlsHandshakeIdx));
    deriveSecretInput.HashMessagesJobId =
      TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfHashMessagesJobIdIdxOfTlsHandshake(activeTlsHandshakeIdx));
    deriveSecretInput.HkdfHashLen = HashLength;
  }
  {
    /* Calculate the server application secret */
    deriveSecretInput.TargetKeyId = serverApplicationTrafficSecretKeyId;
    deriveSecretInput.SaltKeyId = derivedSecretKeyId;
  }
  retVal = TcpIp_Tls13CoreCtx_DeriveSecretAndShortenHkdfKey(TlsConIdx, &deriveSecretInput,
    &TcpIp_Tls_Hs_Tls13Label_SApTraffic[0], TCPIP_TLS_HS_TLS13LABEL_APTRAFFIC_LEN, TRUE);

  {
    /* Calculate the client application secret */
    deriveSecretInput.TargetKeyId = clientApplicationTrafficSecretKeyId;
    deriveSecretInput.SaltKeyId = derivedSecretKeyId;
  }

  retVal |= TcpIp_Tls13CoreCtx_DeriveSecretAndShortenHkdfKey(TlsConIdx, &deriveSecretInput,
    &TcpIp_Tls_Hs_Tls13Label_CApTraffic[0], TCPIP_TLS_HS_TLS13LABEL_APTRAFFIC_LEN, TRUE);

#  if (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON)
  TcpIp_SetNssApplicationTrafficSecretReadyToSendOfTlsConnectionDyn(TlsConIdx, TRUE);
#  endif
#  if (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON)
  if (TcpIp_IsTlsUseKeyUpdateCalloutOfTlsConfig(TCPIP_TLSCONFIG_IDX))
  {
    (void)TcpIp_TlsCore_IssueKeyUpdateCallout(TlsConIdx, TCPIP_TLS_KEYUPDATE_HANDSHAKE_TO_APPLICATION);
  }
#  endif

  /* #10 Calculate the Server/Client Application Key and IV. */
  retVal |= TcpIp_Tls13CoreCtx_CalculateKeyAndIvForEncryptionAndDecryption(TlsConIdx);

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DeriveResumptionMasterSecret
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_Tls13CoreCtx_DeriveResumptionMasterSecret(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType localRetVal = E_NOT_OK;

  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx =
    TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx);

  TcpIp_CsmKeyIdType derivedSecretKeyId =
    TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfDerivedSecretIdxOfTlsHandshake(activeTlsHandshakeIdx));

  TcpIp_CsmKeyIdType resumptionMasterSecretKeyId = TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdResumptionMasterSecretIdxOfTlsConnection(TlsConIdx));

  uint8 hashLength = 0u;

  /* ----- Implementation ----------------------------------------------- */
  if (TcpIp_Tls13Core_GetHashLengthOfActiveCipherSuite(TlsConIdx, &hashLength) == E_OK)
  {
    TcpIp_Tls13_DeriveSecretInput_Type deriveSecretInput = { 0 };
    {
      /* set general parameters */
      deriveSecretInput.TemporaryKeyId =
        TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdTemporaryHkdfKeyIdxOfTlsHandshake(activeTlsHandshakeIdx));
      deriveSecretInput.TemporaryKeyElementId =
        TcpIp_GetHsCommonKeyElementIdOfTlsHandshake(activeTlsHandshakeIdx);
      deriveSecretInput.AdditionalInfoKeyElementId =
        TcpIp_GetAdditionalInfoKeyElementIdOfTlsHandshake(activeTlsHandshakeIdx);
      deriveSecretInput.HkdfCalcJobId =
        TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfCalculationIdxOfTlsHandshake(activeTlsHandshakeIdx));
      deriveSecretInput.HashMessagesJobId =
        TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfHashMessagesJobIdIdxOfTlsHandshake(activeTlsHandshakeIdx));
      deriveSecretInput.HkdfHashLen = hashLength;
    }
    {
      deriveSecretInput.TargetKeyId = resumptionMasterSecretKeyId;
      deriveSecretInput.SaltKeyId = derivedSecretKeyId;
    }
    /* #10 Derive the resumption master secret. */
    localRetVal = TcpIp_Tls13CoreCtx_DeriveSecretAndShortenHkdfKey(TlsConIdx, &deriveSecretInput,
      &TcpIp_Tls_Hs_Tls13Label_ResMasterSecret[0], TCPIP_TLS_HS_TLS13LABEL_RESMASTERSECRET_LEN, TRUE);

    if (localRetVal == E_OK)
    {
      /* Set resumption master secret key valid. */
      localRetVal = TCPIP_CSM_KeySetValid(resumptionMasterSecretKeyId);
    }
  }

  if (localRetVal != E_OK)
  {
    TcpIp_TlsAsyncCtx_HandleErrorDuringAsyncJobProcessing(TlsConIdx,
      TCPIP_TLS_FCTID_CORE_CRYPTO_PSK_CALC_RESUMPTIONMASTERSECRET,
      TCPIP_TLS_ERRORID_CRYPTO_CALCRESUMPTIONMASTERSECRET_FAILED);
  }
}

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_DerivePskBinderKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_DerivePskBinderKey(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8                       HashLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  /* Initialize the first used keys with 0 */
  uint8 initialPassword[TCPIP_TLS_CIPHERSUITE_MAX_HASH_LEN];

  TcpIp_Tls13PskIdentityActiveIdxOfTlsConnectionDynType activeTls13PskIdentityIdx
    = TcpIp_GetTls13PskIdentityActiveIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_CsmKeyIdType inputKeyId =
    TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(TcpIp_GetPskHkdfCsmJobIdOfTls13PskIdentity(activeTls13PskIdentityIdx));
  TcpIp_CsmKeyIdType temporaryKeyId =
    TcpIp_GetPskTemporaryCsmKeyIdOfTls13PskIdentity(activeTls13PskIdentityIdx);
  /* The pre shared key is the input secret for the calculation of the binder key. */
  TcpIp_CsmKeyIdType preSharedKeyId =
    TcpIp_GetPskCsmKeyIdOfTls13PskIdentity(activeTls13PskIdentityIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Calculate the binder key. */

  /*     |
   *     v
         +-----> Derive-Secret(., "ext binder" | "res binder", "") = binder_key
   *
   */
  VStdMemSet(&initialPassword[0u], TCPIP_TLS_INITIAL_PASSWORD_PLAIN_PATTERN, HashLength);

  /* For the salt the 0-value consisting of a string of Hash.length bytes set to zeros is used
   * (see RFC 8446 chapter 7.1). Write the salt directly into the input key. */
  retVal = TcpIp_TlsCoreCrypto_SetCsmKeyElementAndSetKeyValid(inputKeyId,
    CRYPTO_KE_KEYDERIVATION_SALT, &initialPassword[0], HashLength);

  if (retVal == E_OK)
  {
    /* Copy the PSK to the input key. */
    Std_ReturnType csmRetVal = TCPIP_CSM_KeyElementCopy(preSharedKeyId, TCPIP_CRYPTO_30_LIBCV_KE_TARGET_KEY,
                                                          inputKeyId, CRYPTO_KE_KEYDERIVATION_PASSWORD);
    if (csmRetVal != E_OK)
    {
      retVal = E_NOT_OK;
    }
  }

  if (retVal == E_OK)
  {
    /* We use the inputKey for providing the initial salt and the input in different key elements.
     * It is also used as output key to store the calculated password. */
    TcpIp_Tls13_DeriveSecretInput_Type deriveSecretInput = { 0 };
    {
      deriveSecretInput.TargetKeyId = inputKeyId;
      deriveSecretInput.SaltKeyId = inputKeyId;
      deriveSecretInput.TemporaryKeyId = temporaryKeyId;
      deriveSecretInput.TemporaryKeyElementId = TCPIP_CRYPTO_30_LIBCV_KE_TARGET_KEY;
      deriveSecretInput.AdditionalInfoKeyElementId =
        TcpIp_GetAdditionalInfoKeyElementIdOfTls13PskIdentity(activeTls13PskIdentityIdx);
      deriveSecretInput.HkdfCalcJobId = TcpIp_GetPskHkdfCsmJobIdOfTls13PskIdentity(activeTls13PskIdentityIdx);
      deriveSecretInput.HashMessagesJobId = TcpIp_GetPskHashCsmJobIdOfTls13PskIdentity(activeTls13PskIdentityIdx);
      deriveSecretInput.HkdfHashLen = HashLength;
    }

    /* Currently only resumption PSKs are supported, not external PSKs.
     * Therefore use the resumption binder label (RFC8446 chapter 7.1).
     * Do not hash messages in this calculation. */
    retVal = TcpIp_Tls13CoreCtx_DeriveSecretAndShortenHkdfKey(TlsConIdx, &deriveSecretInput,
      &TcpIp_Tls_Hs_Tls13Label_ResBinderKey[0], TCPIP_TLS_HS_TLS13LABEL_RESBINDERKEY_LEN, FALSE);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_PrepareDerivationOfApplicationTrafficSecret
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_PrepareDerivationOfApplicationTrafficSecret(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8 HashLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  uint8 initialPassword[TCPIP_TLS_SHAREDKEY_MAX_LEN];

  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx =
    TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx);

  TcpIp_CsmKeyIdType sharedSecretKeyId = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob((TcpIp_TlsCsmJobIterType)
    TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfCalculationIdxOfTlsHandshake(activeTlsHandshakeIdx)));
  TcpIp_CsmKeyIdType derivedSecretKeyId =
    TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfDerivedSecretIdxOfTlsHandshake(activeTlsHandshakeIdx));

  /* ----- Implementation ----------------------------------------------- */
  /* Initialize the first password with 0 */
  VStdMemSet(&initialPassword[0u], TCPIP_TLS_INITIAL_PASSWORD_PLAIN_PATTERN, HashLength);
  /* The values in sharedSecretKeyId and derivedSecretKeyId have already been set when calculating
   * the handshake traffic keys. We can reuse these values to skip a few operations.
   * The sharedSecretKey still contains the X coordinate of the calculated ECDHE secret,
   * the derivedSecretKey still contains the password which will be used as salt in the next operation. */

  /* #10 Take the already calculated shared and derived secret and calculate the next Derived Secret. */

  /*  |
   *  v
     Derive - Secret(., "derived", "")
   *
   */

  /* We use the sharedSecretKey for providing the key and the derivedSecretKey for providing the salt.
   * The derivedSecretKey is also used as output key to store the calculated password.
   */
  TcpIp_Tls13_DeriveSecretInput_Type deriveSecretInput = { 0 };
  {
    /* set general parameters */
    deriveSecretInput.TemporaryKeyId =
      TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdTemporaryHkdfKeyIdxOfTlsHandshake(activeTlsHandshakeIdx));
    deriveSecretInput.TemporaryKeyElementId =
      TcpIp_GetHsCommonKeyElementIdOfTlsHandshake(activeTlsHandshakeIdx);
    deriveSecretInput.AdditionalInfoKeyElementId =
      TcpIp_GetAdditionalInfoKeyElementIdOfTlsHandshake(activeTlsHandshakeIdx);
    deriveSecretInput.HkdfCalcJobId =
      TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfCalculationIdxOfTlsHandshake(activeTlsHandshakeIdx));
    deriveSecretInput.HashMessagesJobId =
      TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfHashMessagesJobIdIdxOfTlsHandshake(activeTlsHandshakeIdx));
    deriveSecretInput.HkdfHashLen = HashLength;
  }
  {
    deriveSecretInput.TargetKeyId = derivedSecretKeyId;
    deriveSecretInput.SaltKeyId = derivedSecretKeyId;
  }

  retVal = TcpIp_Tls13CoreCtx_DeriveSecretAndShortenHkdfKey(TlsConIdx, &deriveSecretInput,
    &TcpIp_Tls_Hs_Tls13Label_Derived[0], TCPIP_TLS_HS_TLS13LABEL_DERIVED_LEN, FALSE);

  /* #20 Prepare calculation of the Server/Client Application Traffic Secret. */

  /*                   |
   *                   v
         +-----> Derive-Secret(., "s ap traffic", ClientHello...ServerHello)
         +-----> Derive-Secret(., "c ap traffic", ClientHello...ServerHello)
   *
   */

   /* Use the sharedSecretKeyId to provide the password (filled with zeros). */
  retVal |= TcpIp_TlsCoreCrypto_SetCsmKeyElementAndSetKeyValid(sharedSecretKeyId,
    CRYPTO_KE_KEYDERIVATION_PASSWORD, &initialPassword[0], HashLength);

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_CalcApplicationKeys
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_Tls13CoreCtx_CalcApplicationKeys(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  if (TcpIp_Tls13CoreCtx_AreCsmKeyIdsValid(TlsConIdx) == TRUE)
  {
    /* #10 Determine the hash length depending on the used cipher suite. */
    uint8 hashLength = 0u;
    if (TcpIp_Tls13Core_GetHashLengthOfActiveCipherSuite(TlsConIdx, &hashLength) == E_OK)
    {
      /* #20 Prepare derivation of application traffic secrets */
      retVal = TcpIp_Tls13CoreCtx_PrepareDerivationOfApplicationTrafficSecret(TlsConIdx, hashLength);

      if (retVal == E_OK)
      {
        /* #30 Derive application traffic secrets and keys for client and server */
        retVal = TcpIp_Tls13CoreCtx_DeriveClientAndServerApplicationKeys(TlsConIdx, hashLength);
      }

      /* Set the async state to DONE */
      TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);
    }
#  if ( TCPIP_DEV_ERROR_DETECT == STD_ON )
    else
    {
      /* Memory runtime check fails - report DET */
      TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
    }
#  endif

    if (retVal != E_OK)
    {
      /* Trigger alert internal_error */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
    }
  }
  else
  {
    TcpIp_TlsCoreUtil_HandleInvalidConfiguration(TlsConIdx);
  }
} /* TcpIp_Tls13CoreCtx_CalcApplicationKeys() */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_CalculateKeyAndIvForEncryptionAndDecryption
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_CalculateKeyAndIvForEncryptionAndDecryption(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx =
    TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx);

  TcpIp_CsmKeyIdType passiveEncryptKeyId =
    TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdCipherPassiveEncryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));
  TcpIp_CsmKeyIdType passiveDecryptKeyId =
    TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdCipherPassiveDecryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));

  TcpIp_CsmKeyIdType serverAdHsTrafficSecretKeyId =
    TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfServerAdHsTrafficSecretIdxOfTlsHandshake(activeTlsHandshakeIdx));
  TcpIp_CsmKeyIdType clientAdHsTrafficSecretKeyId =
    TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfClientAdHsTrafficSecretIdxOfTlsHandshake(activeTlsHandshakeIdx));

  uint8 keyLength = 0u;
  uint8 hashLength = 0u;

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  if (   (TcpIp_Tls13Core_GetKeyLengthOfActiveCipherSuite(TlsConIdx, &keyLength) == E_OK)
      && (TcpIp_Tls13Core_GetHashLengthOfActiveCipherSuite(TlsConIdx, &hashLength) == E_OK))                            /* PRQA S 3415 3 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
  {
    /* #10 Calculate the Server/Client Handshake Key. */

    /*              |
     *              v
           [sender]_write_key = HKDF-Expand-Label(Secret, "key", "", key_length)
     *
     */
    /* This function is only used by the TLS client right now.
     * Therefore when decrypting the sender is always the server and the key which is calculated from the
     * server AdHs traffic secret must be saved in the (passive) decrypt key.
     * When encrypting the sender is always the client and therefore the key calculated from the
     * client AdHs traffic secret is saved in the (passive) encrypt key.
     * The same applies to the following IV calculation. */

     /* fill HKDF key struct */
    TcpIp_Tls13_HkdfExpandInput_Type  hkdfExpandInput = { 0 };
    {
      /* set general parameters */
      hkdfExpandInput.TempExpandOutKeyId =
        TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdTemporaryHkdfExpandOutKeyIdxOfTlsHandshake(activeTlsHandshakeIdx));
      hkdfExpandInput.HkdfExpandJobId =
        TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHkdfExpandIdxOfTlsHandshake(activeTlsHandshakeIdx));
      hkdfExpandInput.HkdfHashLen = hashLength;
    }

    {
      /* Calculate decrypt key */
      hkdfExpandInput.InputKeyId = serverAdHsTrafficSecretKeyId;
      hkdfExpandInput.TargetKeyId = passiveDecryptKeyId;
      hkdfExpandInput.TargetKeyElementId = CRYPTO_KE_CIPHER_KEY;
      hkdfExpandInput.TargetKeyElementLen = (uint16) keyLength;
    }
    retVal = TcpIp_Tls13CoreCtx_HkdfExpandLabel(
      &hkdfExpandInput,
      &TcpIp_Tls_Hs_Tls13Label_Key[0],
      TCPIP_TLS_HS_TLS13LABEL_KEY_LEN,
      NULL_PTR,
      0u);

    {
      /* Calculate encrypt key */
      hkdfExpandInput.InputKeyId = clientAdHsTrafficSecretKeyId;
      hkdfExpandInput.TargetKeyId = passiveEncryptKeyId;
      hkdfExpandInput.TargetKeyElementId = CRYPTO_KE_CIPHER_KEY;
      hkdfExpandInput.TargetKeyElementLen = (uint16) keyLength;
    }
    retVal |= TcpIp_Tls13CoreCtx_HkdfExpandLabel(
      &hkdfExpandInput,
      &TcpIp_Tls_Hs_Tls13Label_Key[0],
      TCPIP_TLS_HS_TLS13LABEL_KEY_LEN,
      NULL_PTR,
      0u);

     /* #20 Calculate the Server/Client Handshake IV. */

     /*
      *              |
      *              v
            [sender]_write_iv  = HKDF-Expand-Label(Secret, "iv", "", iv_length)
      *
      */

     {
       /* Calculate decrypt Iv */
       hkdfExpandInput.InputKeyId = serverAdHsTrafficSecretKeyId;
       hkdfExpandInput.TargetKeyId = passiveDecryptKeyId;
       hkdfExpandInput.TargetKeyElementId = CRYPTO_KE_CIPHER_IV;
       hkdfExpandInput.TargetKeyElementLen = TCPIP_TLS13_AEADBLOCK128_IV_LEN;
     }
     retVal |= TcpIp_Tls13CoreCtx_HkdfExpandLabel(
       &hkdfExpandInput,
       &TcpIp_Tls_Hs_Tls13Label_Iv[0],
       TCPIP_TLS_HS_TLS13LABEL_IV_LEN,
       NULL_PTR,
       0u);

     {
       /* Calculate encrypt Iv */
       hkdfExpandInput.InputKeyId = clientAdHsTrafficSecretKeyId;
       hkdfExpandInput.TargetKeyId = passiveEncryptKeyId;
       hkdfExpandInput.TargetKeyElementId = CRYPTO_KE_CIPHER_IV;
       hkdfExpandInput.TargetKeyElementLen = TCPIP_TLS13_AEADBLOCK128_IV_LEN;
     }
     retVal |= TcpIp_Tls13CoreCtx_HkdfExpandLabel(
       &hkdfExpandInput,
       &TcpIp_Tls_Hs_Tls13Label_Iv[0],
       TCPIP_TLS_HS_TLS13LABEL_IV_LEN,
       NULL_PTR,
       0u);
  }

  return retVal;
} /* TcpIp_Tls13CoreCtx_CalculateKeyAndIvForEncryptionAndDecryption() */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_AreCsmKeyIdsValid
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
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_Tls13CoreCtx_AreCsmKeyIdsValid(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx
    = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));

  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx =
    TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  boolean retVal = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check Csm key ID of shared secret */
  retVal = (TcpIp_GetCsmKeyIdHkdfSharedSecretIdxOfTlsHandshake(activeTlsHandshakeIdx) !=
    TCPIP_NO_CSMKEYIDHKDFSHAREDSECRETIDXOFTLSHANDSHAKE);

  /* #20 Check Csm key ID of derived secret */
  if (retVal == TRUE)
  {
    retVal = (TcpIp_GetCsmKeyIdHkdfDerivedSecretIdxOfTlsHandshake(activeTlsHandshakeIdx) !=
      TCPIP_NO_CSMKEYIDHKDFDERIVEDSECRETIDXOFTLSHANDSHAKE);
  }

  /* #30 Check Csm key ID of server handshake traffic secret */
  if (retVal == TRUE)
  {
    retVal = (TcpIp_GetCsmKeyIdHkdfServerAdHsTrafficSecretIdxOfTlsHandshake(activeTlsHandshakeIdx) !=
      TCPIP_NO_CSMKEYIDHKDFSERVERADHSTRAFFICSECRETIDXOFTLSHANDSHAKE);
  }

  /* #40 Check Csm key ID of client handshake traffic secret */
  if (retVal == TRUE)
  {
    retVal = (TcpIp_GetCsmKeyIdHkdfClientAdHsTrafficSecretIdxOfTlsHandshake(activeTlsHandshakeIdx) !=
      TCPIP_NO_CSMKEYIDHKDFCLIENTADHSTRAFFICSECRETIDXOFTLSHANDSHAKE);
  }

  /* #50 Check Csm key ID of passive encrypt key */
  if (retVal == TRUE)
  {
    retVal = (TcpIp_GetCsmKeyIdCipherPassiveEncryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx) !=
      TCPIP_NO_CSMKEYIDCIPHERPASSIVEENCRYPTIDXOFTLSCIPHERWORKER);
  }

  /* #60 Check Csm key ID of passive decrypt key */
  if (retVal == TRUE)
  {
    retVal = (TcpIp_GetCsmKeyIdCipherPassiveDecryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx) !=
      TCPIP_NO_CSMKEYIDCIPHERPASSIVEDECRYPTIDXOFTLSCIPHERWORKER);
  }

  return retVal;
} /* TcpIp_Tls13CoreCtx_AreCsmKeyIdsValid() */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_CopyKeyAndIv
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_CopyKeyAndIv(
  TcpIp_CsmKeyIdType  SourceCsmKeyId,
  TcpIp_CsmKeyIdType  TargetCsmKeyId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmRetVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Copy the key and iv element from source to target key. */
  csmRetVal = TCPIP_CSM_KeyElementCopy(SourceCsmKeyId, CRYPTO_KE_CIPHER_KEY, TargetCsmKeyId, CRYPTO_KE_CIPHER_KEY);
  csmRetVal |= TCPIP_CSM_KeyElementCopy(SourceCsmKeyId, CRYPTO_KE_CIPHER_IV, TargetCsmKeyId, CRYPTO_KE_CIPHER_IV);
  /* #20 Set the target key valid. */
  csmRetVal |= TCPIP_CSM_KeySetValid(TargetCsmKeyId);
  return csmRetVal;
} /* TcpIp_Tls13CoreCtx_CopyKeyAndIv() */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreRl_HandleHsMsgNotAlignedWithRlBoundary
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreRl_HandleHsMsgNotAlignedWithRlBoundary(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 lastHsType = TcpIp_GetLastHsMsgTypeOfLastReceivedHsRlFrameOfTlsConnectionDyn(TlsConIdx);
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check that the active TLS version is not 1.2. */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLSVERSION_12)
#  endif
  {
    /* #20 Check if the message was a message preceding a key change. */
    if (   (lastHsType == TCPIP_TLS_HSTYPE_SERVERHELLO)
        || (lastHsType == TCPIP_TLS_HSTYPE_FINISHED)
        || (lastHsType == TCPIP_TLS_HSTYPE_KEYUPDATE))
    {
      /* According to RFC 8446 Section 5.1, implementations MUST verify that all messages immediately
       * preceding a key change align with a record boundary; if not, then they MUST terminate the
       * connection with an unexpected_message alert. */
      if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
      {
        /* #30 If so, either send unexpected_message alert */
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
        retVal = E_NOT_OK;
      }
      else
      {
        /* #40 Or delay sending the alert after setting the active TLS version */
        /* We can not send the alert just yet, because this check MUST only be done if the active TLS version is 1.3.
         * If TLS 1.3 is selected in TcpIp_Tls13ClientMsg_ServerHelloParseExtensionSupportedVersions() we send an alert.
         * Therefore return E_OK for now. */
        TcpIp_SetMsgPrecedingKeyChangeNotAlignWithBoundaryOfTlsConnectionDyn(TlsConIdx, TRUE);
      }
    }
  } /* else - in TLS 1.2 there is no requirement to check the messages preceding a key change. */
  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreRl_AddInnerPlaintextContentTypeIfNecessary
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_Tls13CoreRl_AddInnerPlaintextContentTypeIfNecessary(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferTxIterType TxStartIdx,
  TCPIP_P2V(TcpIp_SizeOfTlsBufferTxType) TxLenPtr,
  TCPIP_P2V(uint8) ContentTypePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* In TLS 1.3 the inner plain text ContentType is used for encrypted messages.
   * Only Client and Server Hello are not encrypted and only for those messages the TCPIP_TLS_NULL_WITH_NULL_NULL cipher is used. */
  /* #10 Check if the TCPIP_TLS_NULL_WITH_NULL_NULL is not used */
  if (TcpIp_GetActiveCipherTxOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_NULL_WITH_NULL_NULL)
  {
    /* #20 Depending on the ContentType a different behavior is necessary. */
    switch (*ContentTypePtr)
    {
      case TCPIP_TLS_CT_AD:
      case TCPIP_TLS_CT_HS:
      case TCPIP_TLS_CT_AL:
      {
        TcpIp_SetRlTxInnerPlaintextContentTypeOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, *ContentTypePtr);
        /* #30 Add the inner plain text ContentType into the Buffer. */
        TcpIp_Tls13CoreRl_AddInnerPlaintextContentType(TlsConIdx,
                                                       TxStartIdx,
                                                       TxLenPtr,
                                                       ContentTypePtr);
        break;
      }
      case TCPIP_TLS_CT_CCS:
      {
        /* #40 The CCS message does not include an inner plain text ContentType. */
        break;
      }
      default:
      {
        /* Left blank intentionally */
        TCPIP_ASSERT_UNREACHABLE();
        break;
      }
    }
  }

} /* TcpIp_Tls13CoreRl_AddInnerPlaintextContentTypeIfNecessary() */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreRl_AddInnerPlaintextContentType
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13CoreRl_AddInnerPlaintextContentType(
  TcpIp_TlsConnectionIterType             TlsConIdx,
  TcpIp_TlsBufferTxIterType               TxPlainTextStartIdx,
  TCPIP_P2V(TcpIp_SizeOfTlsBufferTxType)  TxPlainTextLenPtr,
  TCPIP_P2V(uint8)                        ContentTypePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType localRetVal = E_NOT_OK;
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  /* Start index of the Tx buffer corresponding to the content of the message, e.g start index of the alert buffer */
  TcpIp_TlsBufferTxIterType startTlsBufferTxIdx = 0u;
  /* End index of the Tx buffer corresponding to the content of the message */
  TcpIp_TlsBufferTxIterType endTlsBufferTxIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_VENTER_CRITICAL_SECTION();

  /* Set marker that inner content type has been added. */
  TcpIp_SetTxInnerContentTypeAddedOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TRUE);

  /* #10 Determine the buffer start and end. */
  switch (*ContentTypePtr)
  {
    case TCPIP_TLS_CT_AD:
    case TCPIP_TLS_CT_HS:
    {
      localRetVal = E_OK;
      startTlsBufferTxIdx = TcpIp_GetTlsBufferTxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);
      endTlsBufferTxIdx = TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);
      break;
    }
    case TCPIP_TLS_CT_AL:
    {
      localRetVal = E_OK;
      startTlsBufferTxIdx = TcpIp_GetTlsBufferTxAlStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);
      endTlsBufferTxIdx = TcpIp_GetTlsBufferTxAlEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);
      break;
    }
    default:
    {
      /* Left blank intentionally */
      TCPIP_ASSERT_UNREACHABLE();
      break;
    }
  }
  if (localRetVal == E_OK)
  {
    /* Get the buffer index right after the plaintext ends (considering wraparound). */
    /* TcpIp_GetIncrementedRingBufferIndex() needs a uint32 pointer.
     * Avoid casting a pointer to not having to worry about byte order. */
    uint32 bufferIndexToOverwriteUint32 = 0u;
    TcpIp_TlsBufferTxIterType overwriteTlsBufferTxIdx = 0u;
    /* The return value can be ignored here since the indices must be correct. */
    (void) TcpIp_GetIncrementedRingBufferIndex((uint32)TxPlainTextStartIdx, (uint32) *TxPlainTextLenPtr,
      (uint32) startTlsBufferTxIdx, (uint32) endTlsBufferTxIdx, &bufferIndexToOverwriteUint32);
    overwriteTlsBufferTxIdx = (TcpIp_TlsBufferTxIterType)bufferIndexToOverwriteUint32;

    /* Backup the buffer content before overwriting it with the content type. */
    TcpIp_SetTlsBufferTxByteOverwrittenByInnerPlainTextContentTypeIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
      (TcpIp_TlsBufferTxByteOverwrittenByInnerPlainTextContentTypeIdxOfTlsBufferMgmtDynType) overwriteTlsBufferTxIdx);
    TcpIp_SetRlTxValueOfByteOverwrittenByInnerPlainTextContentTypeOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
      IpBase_GetUint8(TcpIp_GetAddrTlsBufferTx(overwriteTlsBufferTxIdx), 0u));

    /* #20 Add the inner plain text ContentType to the Tx Buffer */
    TcpIp_PutUint8Safe(TcpIp_GetAddrTlsBufferTx(startTlsBufferTxIdx),
      (uint32) overwriteTlsBufferTxIdx - (uint32) startTlsBufferTxIdx,
      (uint32) endTlsBufferTxIdx - (uint32) startTlsBufferTxIdx, *ContentTypePtr);

    /* The optional inner plain text padding is not added.
     * The plain text length is now one byte larger. */
    (*TxPlainTextLenPtr) += TCPIP_TLS13_INNERPLAINTEXTCONTENTTYPELEN;
    /* The Record Layer ContentType is always Application Data for encrypted messages. See RFC8446 chapter 5.2. */
    *ContentTypePtr = TCPIP_TLS_CT_AD;
  }

  TCPIP_VLEAVE_CRITICAL_SECTION();
} /* TcpIp_Tls13CoreRl_AddInnerPlaintextContentType() */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreRl_ProcessAdFrameAfterDecryption
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreRl_ProcessAdFrameAfterDecryption(
  TcpIp_TlsConnectionIterType                            TlsConIdx,
  TCPIP_P2V(TcpIp_RlRxCopiedLenOfTlsBufferMgmtDynType)   PlaintextLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* Since the plaintext length does not exceed 2^14 + 1 (RFC8446 chapter 5.4),
   * uint16 is sufficient to store the padding length. */
  uint16 paddingLen = 0u;

  TcpIp_LastReceivedContentTypeOfTlsConnectionDynType innerPlainTextContentType = TCPIP_TLS_CT_INVALID;

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* If Tls 1.3 is active and a message with Record Layer ContentType Application Data is received,
   * it also contains a inner plain text ContentType which specifies the actual content of the message. */
  /* #10 Read the inner plain text ContentType from the buffer and save it for later use. */
  if (TcpIp_Tls13CoreRl_FindInnerPlaintextContentType(TlsConIdx, &paddingLen) == E_OK)
  {
    /* 1 byte inner plaintext content type shall not contribute to the fill level
     * since it was already parsed and removed from the plaintext. */
    *PlaintextLenPtr -= TCPIP_TLS13_INNERPLAINTEXTCONTENTTYPELEN;

    /* Subtract length of padding from plaintext to correctly set UlRxIndLvl and RxFillLvl */
    *PlaintextLenPtr -= paddingLen;

    /* #20 Check if the inner plain text ContentType is known and valid. */
    innerPlainTextContentType = TcpIp_GetLastReceivedContentTypeOfTlsConnectionDyn(TlsConIdx);
    switch (innerPlainTextContentType)
    {
      /* #30 Depending on the inner plain text ContentType trigger different processing. */
      case TCPIP_TLS_CT_CCS:
      {
        /* RFC8446 section 5 states that an implementation which receives a protected change_cipher_spec record
         * MUST abort the handshake with an "unexpected_message" alert. */
        /* retVal is already E_NOT_OK */
        break;
      }
      case TCPIP_TLS_CT_HS:
      {
        /* RFC8446 chapter 5.4 states that if a handshake or alert message with zero-length TLSInnerPlaintext.content
         * is received the connection MUST be terminated with an "unexpected_message" alert. */
        /* #40 Check that plaintext length is not zero. */
        if (*PlaintextLenPtr == 0u)
        {
          /* retVal is already E_NOT_OK */
        }
        else
        {
          /* All TLS 1.3 handshake messages are handled in TcpIp_Tls13CoreRl_ProcessHsFrame() which is invoked in
           * ScanForHsTypesAndTriggerHsMsgProcess() which in turn is invoked in
           * TcpIp_TlsCoreRl_HandleFrameAndTriggerContentSpecificProcess(). It cannot be called here since the
           * ServerHello (which is not an AD frame) shall also be handled. */
          retVal = E_OK;
        }
        break;
      }
      case TCPIP_TLS_CT_AD:
      {
        if (   (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_HS_ACTIVE)
            || (TcpIp_GetRemainingBytesOfLastHsMsgPartiallyReceivedOfTlsConnectionDyn(TlsConIdx) > 0u))                 /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
        {
          /* We should not receive any TLS AD before the handshake is done
           * or when we received only an incomplete fragment of a HS message before.
           * RemainingBytesOfLastHsMsgPartiallyReceived describes how many bytes of the last handshake message
           * are still missing for it to be complete. It is maintained in
           * TcpIp_TlsCoreRl_ScanForHsTypesAndTriggerHsMsgProcess().
           * Set the TLS Alert to 'unexpected_message' in the caller function */
        }
        else
        {
          retVal = E_OK;
        }
        break;
      }
      case TCPIP_TLS_CT_AL:
      {
        /* RFC8446 chapter 5.4 states that if a handshake or alert message with zero-length TLSInnerPlaintext.content
         * is received the connection MUST be terminated with an "unexpected_message" alert. */
        if (*PlaintextLenPtr != 0u)
        {
          /* Copy alert plaintext data to the Rx alert buffer where it will be processed. */
          retVal = TcpIp_Tls13CoreRl_CopyPlaintextToAlertBuffer(TlsConIdx, *PlaintextLenPtr);
          if (retVal != E_OK)
          {
            TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
          }
        }
        else
        {
          retVal = E_NOT_OK;
        }
        break;
      }
      default:
      {
        /* Unknown inner plain text ContentType, retVal is already E_NOT_OK
         * According to RFC8446 Section 5. an unexpected_message alert MUST be sent if the implementation receives
         * an unexpected record type. Therefore, the handling of the InnerPlaintext content type is done in the same way. */
        break;
      }
    }
  }
  /* The inner plain text ContentType could not be found. The received message has an invalid format. */
  else
  {
    /* According to RFC 8446, 5.4, if a receiving implementation does not find a non-zero octet in the
     * cleartext, it MUST terminate the connection with an unexpected_message alert. */
    /* retVal is already E_NOT_OK */
  }

  return retVal;
} /* TcpIp_Tls13CoreRl_ProcessAdFrameAfterDecryption() */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreRl_ProcessHsFrame
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreRl_ProcessHsFrame(
  TcpIp_TlsConnectionIterType                 TlsConIdx,
  uint8                                       HsType,
  uint32                                      HsLen,
  TcpIp_ConstSegmentPtrType                   SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                   SourceSegment2Ptr,
  TCPIP_P2V(boolean)                          HsMsgAlreadySkippedPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the handshake is completed. */
  if (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_HANDSHAKE_DONE)
  {
    /* #20 Handshake messages after a complete handshake are handled here immediately. */
    retVal = TcpIp_Tls13CoreRl_ProcessHsFrameAfterHandshake(TlsConIdx, HsType, HsLen, SourceSegment1Ptr,
      SourceSegment2Ptr);

    *HsMsgAlreadySkippedPtr = TRUE;
  }
  else
  {
    retVal = E_OK;
    /* #30 But block the decryption temporarily if a message preceding a key change was received. */
    if (   (HsType == TCPIP_TLS_HSTYPE_SERVERHELLO)
        || (HsType == TCPIP_TLS_HSTYPE_FINISHED)
        || (HsType == TCPIP_TLS_HSTYPE_KEYUPDATE))
    {
      /* Message which indicates a key change afterwards was received - block decryption till new keys are calculated */
      TcpIp_TlsCoreRl_BlockDecryption(TlsConIdx);
    }
  }
  return retVal;
} /* TcpIp_Tls13CoreRl_ProcessHsFrame() */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreRl_ProcessHsFrameAfterHandshake
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreRl_ProcessHsFrameAfterHandshake(
  TcpIp_TlsConnectionIterType                 TlsConIdx,
  uint8                                       HsType,
  uint32                                      HsLen,
  TcpIp_ConstSegmentPtrType                   SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                   SourceSegment2Ptr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* Don't set a flag to handle the rx data later, but immediately handle this handshake data here. This is because we
     have to remove the data from the application data rx buffer as soon as possible to be able to receive and handle
     further new data. */
  /* #10 Check which handshake message was received. */
  switch (HsType)
  {
    case TCPIP_TLS_HSTYPE_NEWSESSIONTICKET:
    {
      /* #20 NewSessionTicket received, parse the message. */
      retVal = TcpIp_Tls13ClientMsg_ParseNewSessionTicket(TlsConIdx, HsLen, SourceSegment1Ptr, SourceSegment2Ptr);

      break;
    }
    case TCPIP_TLS_HSTYPE_KEYUPDATE:
    {
      /* #30 KeyUpdate received. Key update is currently not supported, so send an alert to close the connection. */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
      break;
    }
    default:
    {
      /* #40 Other not expected handshake message received, send unexpected_message alert. */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreRl_FindInnerPlaintextContentType
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreRl_FindInnerPlaintextContentType(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint16) PaddingLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType readIdx
    = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_TlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDynType writeIdx
    = TcpIp_GetTlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_TlsBufferRxAdHsStartIdxOfTlsBufferMgmtType rxBufferStartIdx =
    TcpIp_GetTlsBufferRxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx); /* Start of the Rx Buffer */
  TcpIp_TlsBufferRxAdHsEndIdxOfTlsBufferMgmtType rxBufferReadMaxIdx =
    TcpIp_TlsCoreRl_GetReadMaxIdxForContentType(TlsConIdx, TCPIP_TLS_CT_AD); /* No more data to read after this index */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* The optional inner plain text padding consists of zeros at the end of the message (See RFC8446 chapter 5.2). */
  /* #10 Start at the end of the received message (=writeIdx). */
  /* TcpIp_GetIncrementedRingBufferIndex() needs a uint32 pointer.
   * Avoid casting a pointer to not having to worry about byte order. */
  uint32 tempReadIdxUint32 = 0u;
  TcpIp_TlsBufferRxIterType tempReadTlsBufferRxIdx = 0u;
  /* The return value can be ignored here since the indices must be correct. */
  (void)TcpIp_GetDecrementedRingBufferIndex(writeIdx, 1u, rxBufferStartIdx, rxBufferReadMaxIdx, &tempReadIdxUint32);
  tempReadTlsBufferRxIdx = (TcpIp_TlsBufferRxIterType)tempReadIdxUint32;

  /* Initialize out-parameter padding length */
  *PaddingLen = 0u;

  while (tempReadTlsBufferRxIdx != readIdx)
  {
    /* #20 Go backwards until a byte is not zero. */
    if (TcpIp_GetTlsBufferRx(tempReadTlsBufferRxIdx) != 0u)
    {
      /* #30 This byte is the inner plain text ContentType. Read it from the buffer. */
      TcpIp_Tls13CoreRl_ReadInnerPlaintextContentType(TlsConIdx, tempReadTlsBufferRxIdx);
      retVal = E_OK;
      break;
    }
    else
    {
      /* The return value can be ignored here since the indices must be correct. */
      (void) TcpIp_GetDecrementedRingBufferIndex((uint32)tempReadTlsBufferRxIdx, 1u, (uint32)rxBufferStartIdx,
        (uint32)rxBufferReadMaxIdx, &tempReadIdxUint32);
      tempReadTlsBufferRxIdx = (TcpIp_TlsBufferRxIterType)tempReadIdxUint32;
      (*PaddingLen)++;
    }
  }
  if (tempReadTlsBufferRxIdx == readIdx)
  {
    /* We have not found the inner plain text ContentType yet and there is only one byte left.
     * If the message is well formatted this must be the inner plain text ContentType
     * and the message has no actual content which might be valid. */
    if (TcpIp_GetTlsBufferRx(tempReadTlsBufferRxIdx) != 0u)
    {
      TcpIp_Tls13CoreRl_ReadInnerPlaintextContentType(TlsConIdx, tempReadTlsBufferRxIdx);
      retVal = E_OK;
    } /* else - invalid message, no inner plain text ContentType found */
  }
  return retVal;
} /* TcpIp_Tls13CoreRl_FindInnerPlaintextContentType() */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreRl_ReadInnerPlaintextContentType
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13CoreRl_ReadInnerPlaintextContentType(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferRxIterType   ReadTlsBufferRxIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Read the inner plain text ContentType. */
  TcpIp_LastReceivedContentTypeOfTlsConnectionDynType contentType
    = IpBase_GetUint8(TcpIp_GetAddrTlsBufferRx(ReadTlsBufferRxIdx), 0u);
  TcpIp_SetLastReceivedContentTypeOfTlsConnectionDyn(TlsConIdx, contentType);
  /* Content type is saved, so it can be reseted.
   * The padding bytes don't have to be reseted, they are already zero. */
  VStdLib_MemClr(TcpIp_GetAddrTlsBufferRx(ReadTlsBufferRxIdx), TCPIP_TLS13_INNERPLAINTEXTCONTENTTYPELEN);

  /* #20 Set the RxAdHsWriteIdx to the current position to allow the zeros to be overwritten. */
  TcpIp_SetTlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
    (TcpIp_TlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDynType)ReadTlsBufferRxIdx);

} /* TcpIp_Tls13CoreRl_ReadInnerPlaintextContentType() */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreRl_CopyPlaintextToAlertBuffer
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreRl_CopyPlaintextToAlertBuffer(
  TcpIp_TlsConnectionIterType                     TlsConIdx,
  TcpIp_RlRxCopiedLenOfTlsBufferMgmtDynType       PlaintextLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferRxAlLengthOfTlsBufferMgmtType rxAlertBufferLen
    = TcpIp_GetTlsBufferRxAlLengthOfTlsBufferMgmt(tlsBufferMgmtIdx);
  TcpIp_TlsBufferRxRlFrameStartIdxOfTlsBufferMgmtDynType rlFrameStartTlsBufferRxIdx
    = TcpIp_GetTlsBufferRxRlFrameStartIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_TlsBufferRxAlStartIdxOfTlsBufferMgmtType rxAlertStartTlsBufferRxIdx =
    TcpIp_GetTlsBufferRxAlStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx); /* Start of the Rx Buffer */
  TcpIp_TlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDynType rxAdHsWriteIdx
    = TcpIp_GetTlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_SegmentType alertBufferSegment;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  TcpIp_SegmentInit(&alertBufferSegment, TcpIp_GetAddrTlsBufferRx(rxAlertStartTlsBufferRxIdx), rxAlertBufferLen);
  /* Alert buffer is linear and always overwritten so just check against whole buffer */
  if (PlaintextLen <= rxAlertBufferLen)
  {
    /* #10 Check if the plaintext data wraps around. */
    if (rxAdHsWriteIdx > rlFrameStartTlsBufferRxIdx)
    {
      /* Linear case, no wraparound in the plaintext */
      if ((rxAdHsWriteIdx - rlFrameStartTlsBufferRxIdx) == PlaintextLen)
      {
        /* #20 Copy plaintext into the Rx alert buffer */
        TcpIp_SegmentMemCpy(&alertBufferSegment, TcpIp_GetAddrTlsBufferRx(rlFrameStartTlsBufferRxIdx), PlaintextLen);
        retVal = E_OK;
      }
    }
    else
    {
      /* Plaintext data in Rx AdHs buffer wraps around */
      TcpIp_TlsBufferRxAdHsStartIdxOfTlsBufferMgmtType rxAdHsStartTlsBufferRxIdx
        = TcpIp_GetTlsBufferRxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);
      TcpIp_TlsBufferRxAdHsEndIdxOfTlsBufferMgmtType rxAdHsEndIdx
        = TcpIp_TlsCoreRl_GetReadMaxIdxForContentType(TlsConIdx, TCPIP_TLS_CT_AD);
      if (((rxAdHsEndIdx - rlFrameStartTlsBufferRxIdx) + (rxAdHsWriteIdx - rxAdHsStartTlsBufferRxIdx)) == PlaintextLen)
      {
        /* #30 Copy plaintext in two parts into the Rx alert buffer */
        TcpIp_SegmentMemCpy(&alertBufferSegment, TcpIp_GetAddrTlsBufferRx(rlFrameStartTlsBufferRxIdx),
          (uint32) rxAdHsEndIdx - (uint32) rlFrameStartTlsBufferRxIdx);
        TcpIp_SegmentMemCpy(&alertBufferSegment, TcpIp_GetAddrTlsBufferRx(rxAdHsStartTlsBufferRxIdx),
          (uint32) rxAdHsWriteIdx - (uint32) rxAdHsStartTlsBufferRxIdx);
        retVal = E_OK;
      }
    }
  }
  if (retVal == E_OK)
  {
    /* #40 Set the RxAdHsWriteIdx to the start of the plaintext data to allow it to be overwritten. */
    TcpIp_SetTlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, rlFrameStartTlsBufferRxIdx);
    TcpIp_AddTlsBufferRxAlWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
      (TcpIp_TlsBufferRxAlWriteIdxOfTlsBufferMgmtDynType) alertBufferSegment.Usage);
  }
  return retVal;
} /* TcpIp_Tls13CoreRl_CopyPlaintextToAlertBuffer() */

/**********************************************************************************************************************
 *  TcpIp_Tls13Core_ExtractHsHeaderInformationFromMultiConstSegment
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Core_ExtractHsHeaderInformationFromMultiConstSegment(
  TcpIp_ConstSegmentPtrType                   SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                   SourceSegment2Ptr,
  TCPIP_P2V(uint8)                            HsTypePtr,
  TCPIP_P2V(uint32)                           HsLenPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint32 countSeg1 = 0u;
  uint32 countSeg2 = 0u;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the passed segments contain enough data for a full handshake header. */
  if (TcpIp_GetSplitLengthInMultiConstSegment(SourceSegment1Ptr, SourceSegment2Ptr, TCPIP_TLS_HSHDRLEN,
    &countSeg1, &countSeg2) == E_OK)
  {
    /* #20 Read the HS header considering a wraparound and return the HS length and type through a pointer. */
    /* The return values can be ignored here,
     * since we already checked that the segments contain enough data to read a handshake header. */
    (void) TcpIp_GetUint8FromMultiConstSegment(SourceSegment1Ptr, SourceSegment2Ptr, HsTypePtr);
    (void) TcpIp_GetUint24FromMultiConstSegment(SourceSegment1Ptr, SourceSegment2Ptr, HsLenPtr);
    retVal = E_OK;
  }

  return retVal;
} /* TcpIp_Tls13Core_ExtractHsHeaderInformationFromMultiConstSegment */

/**********************************************************************************************************************
 *   TcpIp_Tls13CoreCrypto_GenerateAEADBlock128Iv
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCrypto_GenerateAEADBlock128Iv(
  TcpIp_TlsConnectionIterType TlsConIdx,
  boolean                     Encrypt)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 lastSequenceNumberInBytes[TCPIP_TLS13_AEADBLOCK128_IV_LEN] = { 0 };
  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx =
    TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  /* Leave tlsCsmJobIdx uninitialized because type is unknown during compile time.
   * It is ensured that the value gets initialized before usage. */
  TcpIp_TlsCsmJobIterType tlsCsmJobIdx;
  TcpIp_CsmKeyIdType keyId = TCPIP_TLS_CSM_INV_KEY_ID;
  /* Get the tx sequence number for encryption. In case of Encrypt == FALSE it is overwritten. */
  uint64 sequenceNumber = TcpIp_GetRlTxSequenceCounterOfTlsConnectionDyn(TlsConIdx);
  uint8 nonce[TCPIP_TLS13_BLOCK128_NONCE_LEN] = { 0 };

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the sequence number and the key. */
  if (Encrypt == TRUE)
  {
    /* Reconstruct the sequence number that was used for the last encryption. */
    IpBase_PutUint64(&lastSequenceNumberInBytes[0], TCPIP_TLS13_ADD_SEQNUM_OFFSET,
      TcpIp_GetLastRlTxSequenceCounterOfTlsConnectionDyn(TlsConIdx));
    /* Set the current sequence number as the last used sequence number. */
    TcpIp_SetLastRlTxSequenceCounterOfTlsConnectionDyn(TlsConIdx, sequenceNumber);
    /* Get the CSM job for encryption. It references the key which must be used. */
    tlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
      TcpIp_GetCsmJobIdCipherEncryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));
  }
  else
  {
    /* Get the rx sequence number for decryption.
     * Also reconstruct the sequence number that was used for the last decryption. */
    sequenceNumber = TcpIp_GetRlRxSequenceCounterOfTlsConnectionDyn(TlsConIdx);
    IpBase_PutUint64(&lastSequenceNumberInBytes[0], TCPIP_TLS13_ADD_SEQNUM_OFFSET,
      TcpIp_GetLastRlRxSequenceCounterOfTlsConnectionDyn(TlsConIdx));
    /* Set the current sequence number as the last used sequence number. */
    TcpIp_SetLastRlRxSequenceCounterOfTlsConnectionDyn(TlsConIdx, sequenceNumber);
    /* Get the CSM job for decryption. It references the key which must be used. */
    tlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
      TcpIp_GetCsmJobIdCipherDecryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));
  }
  /* Get the CSM key Id from the CSM job. */
  keyId = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(tlsCsmJobIdx);

  /* #20 Calculate the TLS 1.3 per record nonce. */
  retVal = TcpIp_Tls13CoreCrypto_CalculatePerRecordNonce(TlsConIdx, keyId, sequenceNumber,
    &lastSequenceNumberInBytes[0], &nonce[0]);

  /* #30 Load nonce (implicit Iv) into the key element */
  if (retVal == E_OK)
  {
    /* Copy the nonce to the Block128 decrypt key and set the key active.*/
    retVal = TcpIp_TlsCoreCrypto_SetCsmKeyElementAndSetKeyValid(keyId, CRYPTO_KE_CIPHER_IV,
      &nonce[0], TCPIP_TLS13_AEADBLOCK128_IV_LEN);
  }

  return retVal;
} /* TcpIp_Tls13CoreCrypto_GenerateAEADBlock128Iv() */

/**********************************************************************************************************************
 *   TcpIp_Tls13CoreCrypto_CalculatePerRecordNonce
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCrypto_CalculatePerRecordNonce(
  TcpIp_TlsConnectionIterType                     TlsConIdx,
  TcpIp_CsmKeyIdType                              KeyId,
  uint64                                          SequenceNumber,
  TCPIP_P2C(uint8)                                LastSequenceNumberInBytesPtr,
  TCPIP_P2V(uint8)                                NoncePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 sequenceNumberInBytes[TCPIP_TLS13_AEADBLOCK128_IV_LEN] = { 0 };
  uint8 iv[TCPIP_TLS13_AEADBLOCK128_IV_LEN] = { 0 };
  uint32 ivLength = TCPIP_TLS13_AEADBLOCK128_IV_LEN;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the sequence number padded to Iv length. */
  /* RFC 8446, 5.3. Per-Record Nonce:
   * The 64-bit record sequence number is encoded in network byte
   * order and padded to the left with zeros to iv_length. */
  IpBase_PutUint64(&sequenceNumberInBytes[0], TCPIP_TLS13_ADD_SEQNUM_OFFSET, SequenceNumber);

  /* #20 Reconstruct the Iv. */
  /* To reconstruct the Iv, get the last nonce from the csm key element.
   * The nonce is always stored in the Iv element of the csm and the original iv
   * is therefore overwritten. */
  retVal = TCPIP_CSM_KeyElementGet(KeyId, CRYPTO_KE_CIPHER_IV, &iv[0], &ivLength);

  retVal |= TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, retVal, ivLength, TCPIP_TLS13_AEADBLOCK128_IV_LEN,
    TCPIP_TLS_FCTID_CORE_CRYPTO_SETAESIVVALUE);

  if (retVal == E_OK)
  {
    uint8_least nonceIter = 0u;
    /* We need the Iv to calculate the current nonce.
     * The last nonce was created combining the Iv and the sequence number at that point with XOR.
     * To get the Iv we need to reverse that XOR-operation which can be done through using XOR again.
     * When this is the first time the nonce is calculated, the Iv is already in the iv array.
     * But since the last sequence number is initialized with zero, this XOR-operation doesn't overwrite it. */
    for (nonceIter = 0u; nonceIter < TCPIP_TLS13_AEADBLOCK128_IV_LEN; nonceIter++)
    {
      iv[nonceIter] ^= LastSequenceNumberInBytesPtr[nonceIter];
    }

    /* #30 Calculate the per record nonce. */
    /* Now the Iv is in the iv array and sequenceNumberInBytes contains the current sequence number.
     * The nonce can be calculated now. */
    /* RFC 8446, 5.3. Per-Record Nonce:
     * The padded sequence number is XORed with the static iv. */
    for (nonceIter = 0u; nonceIter < TCPIP_TLS13_AEADBLOCK128_IV_LEN; nonceIter++)
    {
      NoncePtr[nonceIter] = sequenceNumberInBytes[nonceIter] ^ iv[nonceIter];
    }
  }

  return retVal;
}/* TcpIp_Tls13CoreCrypto_CalculatePerRecordNonce() */

/**********************************************************************************************************************
 *   TcpIp_Tls13CoreCrypto_HashIntoSegment
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCrypto_HashIntoSegment(
  TcpIp_TlsConnectionIterType                     TlsConIdx,
  TcpIp_CsmJobIdType                              CsmHashJobId,
  Crypto_OperationModeType                        CsmOperationMode,
  TCPIP_P2C(uint8)                                DataToHashPtr,
  uint32                                          DataToHashLength,
  uint32                                          ExpectedHashLength,
  TcpIp_SegmentPtrType                            TargetSegmentPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint32 resultLength = TargetSegmentPtr->AvailLen;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Call Csm_Hash() with the passed arguments. */
  Std_ReturnType csmRetVal = TCPIP_CSM_Hash(CsmHashJobId, CsmOperationMode, DataToHashPtr, DataToHashLength,
    TargetSegmentPtr->AvailPtr, &resultLength);

  if (csmRetVal == E_OK)
  {
    /* The Csm only writes data if the finish flag is set. */
    if (TCPIP_IS_FLAG_SET(CsmOperationMode, CRYPTO_OPERATIONMODE_FINISH) == TRUE)
    {
      /* #20 Maintain the fill level of the passed buffer segment if the Csm did write data into it. */
      TcpIp_SegmentCommit(TargetSegmentPtr, resultLength);
    }
  }
  /* Check if the CSM hash operation succeeded. */
  /* If csmRetVal is E_NOT_OK, retVal will be set to E_NOT_OK as well. */
  retVal = TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, resultLength,
    ExpectedHashLength, TCPIP_TLS_FCTID_CLIENT_CRYPTO_CALCHSHASH);

  return retVal;

}/* TcpIp_Tls13CoreCrypto_HashIntoSegment() */

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_SetPublicKeyPtrAndLength
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_SetPublicKeyPtrAndLength(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(TcpIp_Uint8P2C)   PublicKeyPtrPtr,
  TCPIP_P2V(uint16)           PublicKeyLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx =
    TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));
  Std_ReturnType   retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
#   if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#    if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
#    endif
  {
    /* Mode == TCPIP_TLS_SERVER */
    /* TLS 1.3 server is not yet supported */
    retVal = E_NOT_OK;
  }
#    if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  else
#    endif
#   endif
#   if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  {
    /* Mode == TCPIP_TLS_CLIENT */

    /* #10 Set public key pointer and length of the public key depending on the selected key exchange method. */
    /* The key exchange method is always ECDHE for TLS 1.3. */

    {
      /* ECDHE key exchange */
      TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);

      uint8 compressionFlagLen = 0u;
      if (TcpIp_TlsCoreUtil_CheckPublicKeyCompressionFlagOfEllipticCurve(
        TcpIp_GetEllipticCurveIdOfTlsHandshake(activeTlsHandshakeIdx)) == TRUE)
      {
        /* The current elliptic curve uses a compression flag when the key is sent in the key share.
         * Reduce the key length by one, and increase the key pointer by one. */
        compressionFlagLen = TCPIP_TLS_KEYEXCH_COMPFLAGLEN;
      }

      /* #20 Set public key pointer and key length to the server key received in the ServerKeyExchange message. */
      /* Pointer to the Server public key which is located in the RX Buffer */
      *PublicKeyPtrPtr = TcpIp_GetAddrTlsBufferRx(
        TcpIp_GetTlsBufferRxServerKeyExchangePubKeyIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx) + compressionFlagLen);

      /* Public key length is checked in function TcpIp_Tls12ClientMsg_ServerKeyExchangeMsgGetPubKey() against its boundaries */
      *PublicKeyLenPtr = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(
        TcpIp_GetTlsBufferRxServerKeyExchangePubKeyLenIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx)), 0u) - compressionFlagLen;
    }

  }
#   endif

  return retVal;
} /* TcpIp_Tls13CoreCtx_SetPublicKeyPtrAndLength */

/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_CalcDhSharedSecret
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(void, TCPIP_CODE) TcpIp_Tls13CoreCtx_CalcDhSharedSecret(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx =
    TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));
  uint16           publicKeyLen;
  /* The address of publicKeyPtr is changed in TcpIp_Tls13CoreCtx_SetPublicKeyPtrAndLength()
   * to point to the public key in the Rx buffer.
   * Since the public key in the buffer should not be changed it is declared as pointer to const. */
  TCPIP_P2C(uint8) publicKeyPtr = NULL_PTR;
  uint16           localErrorId = TCPIP_TLS_ERRORID_NOT_SET;
  Std_ReturnType   retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* Check if the necessary key for the DH operation is configured */
  if (TcpIp_IsCsmKeyIdKeyExchangeUsedOfTlsHandshake(activeTlsHandshakeIdx) == TRUE)
  {
    /* Get pointer and length for the received public key */
    if (TcpIp_Tls13CoreCtx_SetPublicKeyPtrAndLength(TlsConIdx, &publicKeyPtr, &publicKeyLen) == E_OK)                   /* PRQA S 2991, 2995 */ /* MD_TCPIP_Rule14.3_2741_2742_2991_2992_2995_2996 */
    {
      /* This function calculates the shared secret. They key must already be copied earlier. */
      /* #10 Forward the public key to the CSM to calculate the Diffie-Hellman shared secret */
      retVal = TcpIp_TlsCoreCtx_ForwardKeyToCsmForDhSharedSecretCalculation(TlsConIdx, publicKeyPtr,
        (uint32)publicKeyLen, &localErrorId);
    }
    else
    {
      /* Error, crypto CSM call failed in prepared keys */
      localErrorId = TCPIP_TLS_ERRORID_CRYPTO_CSM_CALL_FAILED;
    }

    if (retVal == E_OK)
    {
      /* The calculation of the shared secret was successful. Next the keys have to be derived. This will be done right
       * after this function, so stay in the async context for that. */
    }
    else
    {
      /* otherwise, handles error while async CSM processing */
      TcpIp_TlsAsyncCtx_HandleErrorDuringAsyncJobProcessing(TlsConIdx,
        TCPIP_TLS_FCTID_CORE_ASYNCCTX_CALC_DH_SHAREDSECRET, localErrorId);
    }
  }
  else
  {
    /* CSM Key for DH operation is not configured - invalid configuration */
    TcpIp_TlsCoreUtil_HandleInvalidConfiguration(TlsConIdx);
  }

  if (retVal != E_OK)
  {
    /* Normally the handshake keys would be calculated next and we would stay in the async context.
     * Since calculating the shared secret failed, there is no need the calculate the handshake keys.
     * Instead get back in to the handshake context where the error will be processed. */
    TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);
    TcpIp_SetCalcHsTrafficKeysAsyncFlagOfTlsConnectionDyn(TlsConIdx, FALSE);
  }

} /* TcpIp_Tls13CoreCtx_CalcDhSharedSecret() */
#  endif


/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCtx_CalcPskValue
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13CoreCtx_CalcPskValue(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_Tls13PskIdentityActiveIdxOfTlsConnectionDynType activeTls13PskIdentityIdx
    = TcpIp_GetTls13PskIdentityActiveIdxOfTlsConnectionDyn(TlsConIdx);
  /* The resumption master secret of the resumption base connection was copied to the current connection
   * in the context of the ChangeParameter call where session resumption was requested for the current connection. */
  TcpIp_CsmKeyIdType resumptionMasterSecretKeyId
    = TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdResumptionMasterSecretIdxOfTlsConnection(TlsConIdx));
  TcpIp_CsmKeyIdType pskKeyId = TcpIp_GetPskCsmKeyIdOfTls13PskIdentity(activeTls13PskIdentityIdx);
  TcpIp_CsmJobIdType pskJobId = TcpIp_GetPskHkdfExpandCsmJobIdOfTls13PskIdentity(activeTls13PskIdentityIdx);
  TcpIp_CsmKeyIdType temporaryKeyId = TcpIp_GetPskTemporaryCsmKeyIdOfTls13PskIdentity(activeTls13PskIdentityIdx);
  uint8 hashLen = TcpIp_GetHashLengthOfTls13PskIdentityDyn(activeTls13PskIdentityIdx);
  TCPIP_P2C(uint8) ticketNoncePtr
    = TcpIp_GetAddrTls13PskNonceBuffer(TcpIp_GetTls13PskNonceBufferStartIdxOfTls13PskIdentity(activeTls13PskIdentityIdx));
  uint8 ticketNonceLen = TcpIp_GetPskNonceLenOfTls13PskIdentityDyn(activeTls13PskIdentityIdx);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Calculate the PSK value. */

  /* Fill HKDF key struct */
  TcpIp_Tls13_HkdfExpandInput_Type  hkdfExpandInput = { 0 };
  {
    hkdfExpandInput.TempExpandOutKeyId = temporaryKeyId;
    hkdfExpandInput.HkdfExpandJobId = pskJobId;
    hkdfExpandInput.HkdfHashLen = hashLen;

    hkdfExpandInput.InputKeyId = resumptionMasterSecretKeyId;
    hkdfExpandInput.TargetKeyId = pskKeyId;
    hkdfExpandInput.TargetKeyElementId = TCPIP_CRYPTO_30_LIBCV_KE_TARGET_KEY;
    /* The PSK length shall be equal to the hash length. */
    hkdfExpandInput.TargetKeyElementLen = (uint16) hashLen;
  }

  /* Derive the PSK value */
  if (TcpIp_Tls13CoreCtx_HkdfExpandLabel(&hkdfExpandInput, &TcpIp_Tls_Hs_Tls13Label_Resumption[0],
        TCPIP_TLS_HS_TLS13LABEL_RESUMPTION_LEN, ticketNoncePtr, ticketNonceLen) == E_OK)
  {
    /* The calculation of the PSK was successful. Next the binder_key has to be derived. This will be done right
     * after this function, so stay in the async context for that. */
    retVal = E_OK;
  }
  else
  {
    /* Otherwise, handles error while async CSM processing */
    TcpIp_TlsAsyncCtx_HandleErrorDuringAsyncJobProcessing(TlsConIdx,
      TCPIP_TLS_FCTID_CORE_ASYNCCTX_CALC_PSKANDBINDER, TCPIP_TLS_ERRORID_CRYPTO_DERIVEKEYBLOCK_FAILED);
  }

  return retVal;
}

#  if (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13Core_ReadHandshakeAndApplicationTrafficSecrets
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls13Core_ReadHandshakeAndApplicationTrafficSecrets(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(TcpIp_Tls13_Secret_Type) Tls13_MasterSecretPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  uint8 expectedKeyLen = TCPIP_TLS_MAX_SIZE_OF_TLS_SECRET;
  uint32 keyLen = TCPIP_TLS_MAX_SIZE_OF_TLS_SECRET;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Read the Handshake Traffic Secrets from CSM */
  if (TcpIp_TlsCoreUtil_IsActiveHandshakeSet(TlsConIdx) == TRUE)
  {
    TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx
      = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

    TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx =
      TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx);

    if (TcpIp_Tls13Core_GetHashLengthOfActiveCipherSuite(TlsConIdx, &expectedKeyLen) == E_OK)
    {
      if (Tls13_MasterSecretPtr->ClientSecretPtr != NULL_PTR)
      {
        /* #20 Copy Client Secret to user buffer, if buffer is valid. */
        TcpIp_CsmKeyIdType clientSecretKeyId =
          TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfClientAdHsTrafficSecretIdxOfTlsHandshake(activeTlsHandshakeIdx));

        Std_ReturnType csmRetVal = TCPIP_CSM_KeyElementGet(
          clientSecretKeyId,
          CRYPTO_KE_KEYDERIVATION_PASSWORD,
          Tls13_MasterSecretPtr->ClientSecretPtr,
          &keyLen);

        /* Check if the length of the read key match */
        retVal = TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, keyLen, (uint32)expectedKeyLen, TCPIP_TLS_FCTID_CORE_SA_READSECRET);
      }
      if (Tls13_MasterSecretPtr->ServerSecretPtr != NULL_PTR)
      {
        /* #30 Copy Server Secret to user buffer, if buffer is valid. */
        TcpIp_CsmKeyIdType serverSecretKeyId =
          TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdHkdfServerAdHsTrafficSecretIdxOfTlsHandshake(activeTlsHandshakeIdx));

        Std_ReturnType csmRetVal = TCPIP_CSM_KeyElementGet(
          serverSecretKeyId,
          CRYPTO_KE_KEYDERIVATION_PASSWORD,
          Tls13_MasterSecretPtr->ServerSecretPtr,
          &keyLen);

        /* Check if the length of the read key match */
        retVal = TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, keyLen, expectedKeyLen, TCPIP_TLS_FCTID_CORE_SA_READSECRET);
      }
    }
  }
  /* #40 Copy Client Random to user buffer, if buffer is valid. */
  if (Tls13_MasterSecretPtr->ClientRandomPtr != NULL_PTR)
  {
    VStdMemCpy(&Tls13_MasterSecretPtr->ClientRandomPtr[0],                                                            /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      TcpIp_GetAddrTlsClientRandomAccessBuffer(TcpIp_GetTlsClientRandomAccessBufferStartIdxOfTlsConnection(TlsConIdx)),
      TCPIP_TLS_RANDOM_LEN);
  }

  return retVal;
} /* TcpIp_Tls13Core_ReadHandshakeAndApplicationTrafficSecrets() */
#  endif

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

# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
#endif /* (TCPIP_SUPPORT_ASRTLS == STD_ON) */
/**********************************************************************************************************************
 *  END OF FILE: TcpIp_Tls13Core.c
 *********************************************************************************************************************/
