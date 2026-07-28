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
/*!        \file  TcpIp_TlsCoreCommon.h
 *        \brief  Transport Layer Security (TLS) core functions implementation.
 *
 *      \details  This file is part of the TcpIp TLS submodule.
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp module. >> TcpIp.h
 **********************************************************************************************************************/

#if !defined (TCPIP_TLSCORECOMMON_H)
# define TCPIP_TLSCORECOMMON_H

# include "TcpIp_Cfg.h"

# if (TCPIP_SUPPORT_ASRTLS == STD_ON)                                                                                   /* COV_MSR_UNSUPPORTED */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#  include "TcpIp_Lcfg.h"
#  include "TcpIp_Priv_Types.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/* Positions values for the function TcpIp_TlsCoreRl_RxBufferIdxValidityCheck() */
#  define TCPIP_TLS_CALL_POS_DECRYPT 0x01 /* Call position after data was decrypted */
#  define TCPIP_TLS_CALL_POS_FORWARD 0x02 /* Call position after data was forwarded to upper layer (Rx indication) */
#  define TCPIP_TLS_CALL_POS_CONFIRM 0x03 /* Call position after data was confirmed / read by upper layer */

/* TLS constant length information */
#  define TCPIP_TLS_RLHDRLEN                            5u /* Length of the record layer header */
#  define TCPIP_TLS_CT_LEN                              1u /* Length of the content type */
#  define TCPIP_TLS_CBC_PADDING_BYTE_LEN_LEN            1u /* Length of the TLS Padding Byte length */
#  define TCPIP_TLS_MAC_LEN_MAX                        32u /* Maximum length of the MAC */
#  define TCPIP_TLS_RL_SEQUENCE_NUM_LEN                 8u /* Length of the sequence number inside the record layer header */
#  define TCPIP_TLS_HSLEN_LEN                           3u /* Length of the handshake header length field */
#  define TCPIP_TLS_HSLEN_MAX_LEN                       0x00FFFFFFu /* Max length of handshake header length field */
#  define TCPIP_TLS_HSHDRLEN                            4u /* Length of the handshake header */
#  define TCPIP_TLS_RANDOM_LEN                         32u /* Length of the random value in the hello message */
#  define TCPIP_TLS_BLOCK128_AUTHTAG_LEN               16u /* Length of the authentication tag for AEAD BLOCK128 */
#  define TCPIP_TLS_HASH_SHA512_LEN                    64u /* Length of the SHA512 hash, is not used in cipher suites and therefore not considered for TCPIP_TLS_CIPHERSUITE_MAX_HASH_LEN */
#  define TCPIP_TLS_HASH_SHA384_LEN                    48u /* Length of the SHA384 hash */
#  define TCPIP_TLS_HASH_SHA256_LEN                    32u /* Length of the SHA256 hash */
#  define TCPIP_TLS_HASH_SHA1_LEN                      20u /* Length of the SHA1 hash */
#  define TCPIP_TLS_CIPHERSUITE_MAX_HASH_LEN   TCPIP_TLS_HASH_SHA384_LEN /* Maximum hash length of TLS cipher suites */

#  define TCPIP_TLS_MASTER_SECRET_LEN                  48u /* Length of the master secret */
#  define TCPIP_TLS_CCSMSG_LEN                          1u /* Length of the change cipher spec message */

/* TLS 1.3 constant length information */
#  define TCPIP_TLS13_INNERPLAINTEXTCONTENTTYPELEN      1u /* Length of the inner plain text content type */

/* Additional authentication data offsets and lengths */
#  define TCPIP_TLS_ADD_SEQNUM_LEN                      TCPIP_TLS_RL_SEQUENCE_NUM_LEN  /* 8u: length of sequence number */
#  define TCPIP_TLS_ADD_TYPE_LEN                        1u  /* length of type */
#  define TCPIP_TLS_ADD_VER_LEN                         2u  /* length of version */
#  define TCPIP_TLS_ADD_LEN_LEN                         2u  /* length of content data len */

/* TLS key sizes for AEAD Block128 */
#  define TCPIP_TLS_BLOCK128_KEY_LEN                   16u /* Length of the Block128 key */
#  define TCPIP_TLS_AES256_GCM_KEY_LEN                 32u /* Length of the AES256 Gcm key */
#  define TCPIP_TLS_BLOCK128_IMPLICIT_IV_LEN           4u /* The initialization vector (IV) for Block128 is 4 bytes */
#  define TCPIP_TLS_BLOCK128_EXPLICIT_IV_LEN           8u /* Length of the explicit nonce for Block128 */
#  define TCPIP_TLS_BLOCK128_IV_LEN                    (TCPIP_TLS_BLOCK128_IMPLICIT_IV_LEN + TCPIP_TLS_BLOCK128_EXPLICIT_IV_LEN) /* 12u: Length of the total nonce for Block128 */

#  define TCPIP_TLS13_BLOCK128_AADATA_LEN              (TCPIP_TLS_ADD_TYPE_LEN + TCPIP_TLS_ADD_VER_LEN + TCPIP_TLS_ADD_LEN_LEN) /* 5u: Length of the additional authentication data for Block128 in TLS 1.3 */
#  define TCPIP_TLS12_BLOCK128_AADATA_LEN              (TCPIP_TLS_ADD_SEQNUM_LEN + TCPIP_TLS_ADD_TYPE_LEN + TCPIP_TLS_ADD_VER_LEN + TCPIP_TLS_ADD_LEN_LEN) /* 13u: Length of the additional authentication data for Block128 in TLS 1.2 */
#  define TCPIP_TLS_BLOCK128_AADATA_MAXLEN             TCPIP_TLS12_BLOCK128_AADATA_LEN /* 13u: Length of the maximum additional authentication data for Block128, has to be updated if anything with the AA data lengths changes */

#  define TCPIP_TLS_AES_BLOCK_LEN                      16u /* Length of one AES block */
#  define TCPIP_TLS_AES128_IV_LEN                      16u /* The initialization vector (IV) always has the same length as the block */

#  define TCPIP_TLS_IV_MAX_LEN     TCPIP_TLS_AES128_IV_LEN /* Maximum length for IV, possibly has to be adapted if a new crypto method shall be supported. */

#  define TCPIP_TLS_MAX_EXTENSION_LIST_LENGTH          64u /* Maximum length of the extension list in server or client hello message  */

#  define TCPIP_TLS_PUBKEY_COMPRESSION_FLAG                             0x04u

/* Hello message information */
#  define TCPIP_TLS_UNIXTIMESTAMP_LEN                                                4u

/* TLS Supported major and minor version numbers */
#  define TCPIP_TLS_RL_VERSMAJOR                      0x03u
#  define TCPIP_TLS_RL_VERSMINOR                      0x03u

#  define TCPIP_TLS_PROTOCOLVERSION_TLS12                                        0x0303u
#  define TCPIP_TLS_PROTOCOLVERSION_TLS13                                        0x0304u

#  define TCPIP_TLS_MAJORVERS_LEN                                                     1u
#  define TCPIP_TLS_MINORVERS_LEN                                                     1u
#  define TCPIP_TLS_VERSLEN                                                           (TCPIP_TLS_MINORVERS_LEN + TCPIP_TLS_MAJORVERS_LEN)
#  define TCPIP_TLS_SESSIONIDLEN_LEN                                                  1u
#  define TCPIP_TLS_SESSIONIDMAX_LEN                                                 32u
#  define TCPIP_TLS_CIPHERSUITESLEN_LEN                                               2u
#  define TCPIP_TLS_COMPMETHLEN_LEN                                                   1u

/* Maximum length of TLS header fields in a TLS Rl frame */
#  define TCPIP_TLS_RL_FIELDS_LEN_MAX                 (TCPIP_TLS_RLHDRLEN + TCPIP_TLS_AES128_IV_LEN +\
                                                       TCPIP_TLS_MAC_LEN_MAX + TCPIP_TLS_CBC_PADDING_BYTE_LEN_LEN +\
                                                       TCPIP_TLS_AES_BLOCK_LEN)

/* Offsets within the record layer header */
#  define TCPIP_TLS_RLLEN_OFFSET                        3u /* Offset to the length information */
#  define TCPIP_TLS_RLCT_OFFSET                         0u /* Offset to the content type information */
#  define TCPIP_TLS_RLVERSMAJOR_OFFSET                  1u /* Offset to the major version information */
#  define TCPIP_TLS_RLVERSMINOR_OFFSET                  2u /* Offset to the minor version information */
#  define TCPIP_TLS_RLLENHIGH_OFFSET                    3u /* Offset to the length (high byte) information */
#  define TCPIP_TLS_RLLENLOW_OFFSET                     4u /* Offset to the length (low byte) information */

#  define TCPIP_TLS_CONTENT_LENGTH_OFFSET                1u /* Offset to the content type length information */

/* TLS content types - RFC 5246 - Appendix A.1. Protocol Data Structures and Constant Values */
#  define TCPIP_TLS_CT_INVALID                         0x0u  /* TLS content type invalid */
#  define TCPIP_TLS_CT_CCS                            0x14u /* TLS content type Change Cipher Spec (CCS) */
#  define TCPIP_TLS_CT_AL                             0x15u /* TLS content type Alert (AL) */
#  define TCPIP_TLS_CT_HS                             0x16u /* TLS content type Handshake (HS) */
#  define TCPIP_TLS_CT_AD                             0x17u /* TLS content type Application Data (AD) */

#  define TCPIP_TLS_CT_ALERT_LEN                        2u /* Length of the alert type */
/* Offsets within the content type alert */
#  define TCPIP_TLS_ALERTLEVEL_OFFSET                   0u /* Offset to the Alert level */
#  define TCPIP_TLS_ALERTDESCRIPTION_OFFSET             1u /* Offset to the Alert description */

/* Offsets within the Content type Handshake header */
#  define TCPIP_TLS_HSHDRLEN_OFFSET                    1u /* Offset to the length information */

#  define TCPIP_TLS_CHANGECIPHERSPEC                0x01u /* Content of the change cipher spec message */

/* ALERT PROTOCOL - RFC5246 #Section-7.2 */
#  define TCPIP_TLS_ALERT_MSG_LEN                       2u

/* TLS Extension static length and type information */
#  define TCPIP_TLS_EXTENSION_LENGTH_LEN                                              2u
#  define TCPIP_TLS_EXTENSION_TYPE_LEN                                                2u
#  define TCPIP_TLS_EXTENSION_SUPPORTED_GROUP_LENGTH_LEN                              2u
#  define TCPIP_TLS_SIGNATURE_ALGORITHMS_LENGTH_LEN                                   2u  /* used in hello extensions, cert request, and cert verify */
#  define TCPIP_TLS_SIGNATURE_ALGORITHMS_ALG_ID_LEN                                   2u  /* used in hello extensions, cert request, and cert verify */
#  define TCPIP_TLS_EXTENSION_EC_POINT_FORMATS_LENGTH_LEN                             1u
#  define TCPIP_TLS_EXTENSION_EC_POINT_FORMAT_FIXED_LENGTH                            1u
#  define TCPIP_TLS_EXTENSION_EC_POINT_FORMAT_LENGTH_LEN                              1u
#  define TCPIP_TLS_EXTENSION_EC_POINT_FORMAT_UNCOMPRESSED                            0u
#  define TCPIP_TLS_EXTENSION_RECORD_SIZE_LIMIT_MAX_VALUE                         16384u  /* 2^14 as defined per RFC 8449 */
#  define TCPIP_TLS_EXTENSION_LIST_LEN                                                2u
#  define TCPIP_TLS_EXTENSIONDATALEN_LEN                                              2u

/* RFC 6066 - 3.  Server Name Indication */
#  define TCPIP_TLS_EXTENSION_SERVER_NAME_LIST_LENGTH_LEN                             2u
#  define TCPIP_TLS_EXTENSION_SERVER_NAME_NAME_TYPE_LEN                               1u
#  define TCPIP_TLS_EXTENSION_SERVER_NAME_NAME_LEN_LEN                                2u
#  define TCPIP_TLS_EXTENSION_SERVER_NAME_SERVER_NAME_MIN_LEN  (TCPIP_TLS_EXTENSION_SERVER_NAME_NAME_TYPE_LEN + TCPIP_TLS_EXTENSION_SERVER_NAME_NAME_LEN_LEN)
#  define TCPIP_TLS_EXTENSION_SERVER_NAME_TYPE_HOST_NAME                              0u
#  define TCPIP_TLS_EXTENSION_SERVER_NAME_HOST_NAME_MIN_LEN                           1u
/* RFC 6066 - 6.  Trusted CA Indication */
#  define TCPIP_TLS_EXTENSION_TRUSTED_CA_INDICATION_LIST_LEN                          2u
#  define TCPIP_TLS_EXTENSION_TRUSTED_CA_INDICATION_TYPE_KEY_SHA1_HASH                1u
#  define TCPIP_TLS_EXTENSION_TRUSTED_CA_INDICATION_TYPE_CERT_SHA1_HASH               3u
/* RFC 6066 - 8.  Certificate Status Request */
#  define TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_OCSP_TYPE                    1u
#  define TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_TYPE_LEN                     1u
#  define TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_RESPONDER_ID_LIST_LEN        2u  /* length of the length field of the responder id list */
#  define TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_RESPONDER_ID_LEN_LEN         2u  /* length of the length field of a responder id */
#  define TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_RESPONDER_ID_MIN_LEN         1u
#  define TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_RESPONDER_ID_TOTAL_MIN_LEN  (TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_RESPONDER_ID_LEN_LEN + TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_RESPONDER_ID_MIN_LEN)
#  define TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST_REQUEST_EXTENSIONS_LEN       2u  /* length of the length field of the request extensions */

/* Distinguished names list (used in trustedCA indication extension, certificate request) */
#  define TCPIP_TLS_DIST_NAMES_LENGTH_LEN                                             2u  /* length field for list of distinguished names */
#  define TCPIP_TLS_DIST_NAME_LENGTH_LEN                                              2u  /* length field for a distinguished name */

/* Certificate message information */
#  define TCPIP_TLS_CERTCHAINLEN_LEN                                                  3u
#  define TCPIP_TLS_CERTLEN_LEN                                                       3u

/* Certificate verify information */
#  define TCPIP_TLS_CERTIFICATEVERIFY_REPEATEDOCTET_LEN                               64u
#  define TCPIP_TLS_CERTIFICATEVERIFY_CONTEXTSTRING_LEN                               33u
#  define TCPIP_TLS_CERTIFICATEVERIFY_SEPARATOR_LEN                                    1u
#  define TCPIP_TLS_CERTIFICATEVERIFY_CONTEXT_LEN                                     (TCPIP_TLS_CERTIFICATEVERIFY_REPEATEDOCTET_LEN + TCPIP_TLS_CERTIFICATEVERIFY_CONTEXTSTRING_LEN + TCPIP_TLS_CERTIFICATEVERIFY_SEPARATOR_LEN)
#  define TCPIP_TLS_CERTIFICATEVERIFY_REPEATEDOCTET                                  0x20
#  define TCPIP_TLS_CERTIFICATEVERIFY_SEPARATOR                                      0x00
#  define TCPIP_TLS_CERTVERIFY_SIG_LENGTH_LEN                                          2u
#  define TCPIP_TLS_CERTVERIFY_SIGALGO_LEN                                             2u

#  define TCPIP_TLS_CERTREQUEST_EXTENSIONS_MIN_DATA_LEN                               2u

/* Certificate message information */
#  define TCPIP_TLS_CERTSLEN_LEN_MAX_VALUE                                            0x00FFFFFFu
#  define TCPIP_TLS_CERT_LEN_MAX_VALUE                                                0x00FFFFFFu
/* TLS 1.3 only - RFC 8446 section 4.4.2. */
#  define TCPIP_TLS_CERT_EXTENSION_LEN                                                2u
#  define TCPIP_TLS_CERT_MIN_DATA                                                     1u
#  define TCPIP_TLS_CERT_ENTRY_CERT_MIN_LEN                                          (TCPIP_TLS_CERTLEN_LEN + TCPIP_TLS_CERT_MIN_DATA)

/* Certificate status request information */
#  define TCPIP_TLS_CERTSTATUS_REQUESTTYPE_LEN                                        1u
#  define TCPIP_TLS_CERTSTATUS_REQUESTTYPE_OCSP                                       1u
#  define TCPIP_TLS_CERTSTATUS_OCSPRESPONSE_LEN                                       3u

/* TLS 1.3 only - RFC 8446 section 4.2.3.
 * TLS 1.3 TCPIP_TLS_EXTENSION_SIGNATURE_ALGORITHMS_SUPPORTED_ALGO_LENGTH_LEN = 2u
 * has been replaced with TCPIP_TLS_SIGNATURE_ALGORITHMS_LENGTH_LEN = 2u.
 * TLS 1.3 TCPIP_TLS_EXTENSION_SIGNATURE_ALGORITHMS_SIGNATURESCHEME_LEN = 2u
 * has been replaced with TCPIP_TLS_SIGNATURE_ALGORITHMS_ALG_ID_LEN = 2u.
 */

/* ECC Key Exchange information */
#  define TCPIP_TLS_KEYEXCH_PUBKEYLEN                                                 1u
#  define TCPIP_TLS_KEYEXCH_COMPFLAGLEN                                               1u

/* Certificate request certificate type */
#  define TCPIP_TLS_CERTREQUEST_CERTTYPES_AMOUNT                        0x01u  /* Amount of certificate types currently known to the ECU. Must be updated once new defines are added below. */
#  define TCPIP_TLS_CERTREQUEST_ECDSA_TYPE                              0x40u

/* Global Handshake macros */
#  define TCPIP_TLS_PROTOCOL_MAJOR_VERSION_3                            0x03u
#  define TCPIP_TLS_PROTOCOL_MINOR_VERSION_3                            0x03u
#  define TCPIP_TLS_PROTOCOL_MINOR_VERSION_4                            0x04u
#  define TCPIP_TLS_COMPRESSION_METHOD_NONE                             0x00u

 /* Supported TLS Extensions */
#  define TCPIP_TLS_EXTENSION_SERVER_NAME_INDICATION                  0x0000u
#  define TCPIP_TLS_EXTENSION_SUPPORTED_GROUPS                        0x000Au
#  define TCPIP_TLS_EXTENSION_EC_POINT_FORMAT                         0x000Bu
#  define TCPIP_TLS_EXTENSION_SIGNATURE_ALGORITHMS                    0x000Du
#  define TCPIP_TLS_EXTENSION_TRUSTED_CA_INDICATION                   0x0003u
#  define TCPIP_TLS_EXTENSION_CERTIFICATE_STATUS_REQUEST              0x0005u
#  define TCPIP_TLS_EXTENSION_RECORD_SIZE_LIMIT                       0x001Cu
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#   define TCPIP_TLS_EXTENSION_SUPPORTED_VERSIONS                     0x002Bu
#   define TCPIP_TLS_EXTENSION_CERTIFICATE_AUTHORITIES                0x002Fu
#   define TCPIP_TLS_EXTENSION_KEY_SHARE                              0x0033u
#   define TCPIP_TLS_EXTENSION_PRE_SHARED_KEY                         0x0029u
#   define TCPIP_TLS_EXTENSION_EARLY_DATA                             0x002Au
#   define TCPIP_TLS_EXTENSION_PSK_KEY_EXCHANGE_MODES                 0x002Du


#   define TCPIP_TLS_EXTENSION_SUPPORTED_VERSIONS_LENGTH_LEN               1u
#   define TCPIP_TLS_EXTENSION_KEY_SHARE_LENGTH_LEN                        2u
#   define TCPIP_TLS_EXTENSION_KEY_SHARE_KEY_EXCHANGE_LEN                  2u
#   define TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_IDENTITIES_LENGTH_LEN        2u
#   define TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_IDENTITIY_LENGTH_LEN         2u
#   define TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_BINDERS_LENGTH_LEN           2u
#   define TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_BINDER_LENGTH_LEN            1u
#   define TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_OBFUSCATED_TICKET_AGE_LEN    4u
#   define TCPIP_TLS_EXTENSION_PRE_SHARED_KEY_SELECTED_IDENTITY_LEN        2u

#   define TCPIP_TLS_EXTENSION_PSKKEM_KEMODE_PSK_KE                        0u
#   define TCPIP_TLS_EXTENSION_PSKKEM_KEMODE_PSK_DHE_KE                    1u
#   define TCPIP_TLS_EXTENSION_PSKKEM_KEMODES_LENGTH_LEN                   1u
#   define TCPIP_TLS_EXTENSION_PSKKEM_KEMODE_LEN                           1u

#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */

#  define TCPIP_CERTGROUPID_INV                                                 0xFFFFu
#  define TCPIP_CERTID_INV                                                      0xFFFFu

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#   define TCPIP_TLS13_LEGACYSESSIONIDLEN                                 32u /* For compatibility purposes the session id has 32-byte value in TLS 1.3 (see RFC8446 chapter 4.1.2) */
#   define TCPIP_TLS_SERVERRANDOM_DOWNGRADE_VALUE_LEN                      8u
#   define TCPIP_TLS_SERVERRANDOM_DOWNGRADE_VALUE_START                   (TCPIP_TLS_RANDOM_LEN - TCPIP_TLS_SERVERRANDOM_DOWNGRADE_VALUE_LEN)
#   define TCPIP_TLS_SERVERRANDOM_HELLORETRYREQUEST_VALUE_LEN             32u
#  endif

#  if ((TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON) || (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON))
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#    define TCPIP_TLS_MAX_SIZE_OF_TLS_SECRET              64u
#   else
#    define TCPIP_TLS_MAX_SIZE_OF_TLS_SECRET              TCPIP_TLS_MASTER_SECRET_LEN
#   endif
#  endif

/* RFC5246 chapter 6.2.1 defines the maximum length for a plaintext fragment as 2^14 = 16384. */
#  define TCPIP_TLS12_RECORD_LAYER_PLAINTEXT_LEN_MAX     16384u

/* TLS key sizes for AEAD Aes128 Gcm */
#  define TCPIP_AEAD_AES_128_GCM_N_MIN_LEN                                                              12u

#  define TCPIP_TLSCONFIG_IDX                                                        0u

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/
/* PRQA S 3453 FctLikeMacros */ /* MD_MSR_FctLikeMacro */
#  define TCPIP_TLS_RXBUFFER_ISIDXINRANGE(READIDX, IDXOFFSET, ENDIDX)  (((((uint64)READIDX) + (IDXOFFSET)) <= (ENDIDX))\
                                            && ((ENDIDX) < TcpIp_GetSizeOfTlsBufferRx() ))

#  define TCPIP_TLS_TXBUFFER_ISIDXINRANGE(WRITEIDX, IDXOFFSET, ENDIDX)  \
                                            (    ((ENDIDX) >= (IDXOFFSET)) \
                                              && (((ENDIDX) - (IDXOFFSET)) >= (WRITEIDX)) \
                                              && ((ENDIDX) < TcpIp_GetSizeOfTlsBufferTx()))

#  define TCPIP_TLS_USERERROR_PARSEHELLO(TlsConIdx)                    ((TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_CLIENT)?\
                                                                      TCPIP_TLS_FCTID_CLIENT_HSSTM_PARSE_SERVERHELLO:TCPIP_TLS_FCTID_SERVER_HSSTM_PARSE_CLIENTHELLO)
#  define TCPIP_TLS_GET_HS_STATE(STATE)                                ( (uint16)STATE & 0xFF00u )
/* PRQA L:FctLikeMacros */
/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
typedef struct
{

  uint16 Type;                          /* Extension type */
  uint16 Length;                        /* Extension length */
  TcpIp_TlsBufferRxIterType StartIdx;   /* Extension Start index to the TlsRxBuffer */

} TcpIp_TlsExtensionType; /* Used as internal interpretation of the received Tls Extensions */

typedef struct
{
  TcpIp_ConstSegmentPtrType TcpSeg1Ptr;        /* Pointer to the first Tcp buffer segment containing received encrypted data. */
  TcpIp_ConstSegmentPtrType TcpSeg2Ptr;        /* Pointer to the second Tcp buffer segment containing received encrypted data. */
  TcpIp_SegmentPtrType      AddAuthDataSegPtr; /* Pointer to a local buffer segment containing additional authentication data in AEAD case. */
  TcpIp_SegmentPtrType      AuthSegPtr;        /* Pointer to a local buffer segment containing authentication tag in AEAD case. */
} TcpIp_TlsDecryptDataType;  /* This data struct was created in order to be able to pass the data segments compactly to decrypt functions. */

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsCoreCrypto_DeleteCsmKeyElement
 *********************************************************************************************************************/
/*! \brief          Deletes a CSM key element.
 *  \details        Sets the first byte of the key to 0x00 and persists this change. KeyLength will be updated to 1.
 *  \param[in]      csmKeyId            Holds the identifier of the key which shall be deleted.
 *  \param[in]      KeyElementId        Holds the identifier of the key element to be deleted.
 *  \return         E_OK                Given key element is successfully deleted
 *  \return         E_NOT_OK            Given key can not be deleted successfully
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
  TcpIp_CsmKeyIdType csmKeyId,
  uint32 csmKeyElementId);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCrypto_SetCsmKeyElementAndSetKeyValid
 *********************************************************************************************************************/
/*! \brief          Set a CSM key element to the passed bytes and set the key active
 *  \details        -
 *  \param[in]      KeyId               Holds the identifier of the key for which a new material shall be set.
 *  \param[in]      KeyElementId        Holds the identifier of the key element to be written.
 *  \param[in]      KeyElementPtr       Pointer to the bytes which shall be written into the key element.
 *  \param[in]      KeyElementLength    Length of KeyElementPtr.
 *  \return         E_OK                Set the specified element for the key and successfully set it to valid
 *  \return         E_NOT_OK            Key element could not be set or key could not be set to valid
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCrypto_SetCsmKeyElementAndSetKeyValid(
  uint32               KeyId,
  uint32               ElementId,
  TCPIP_P2C(uint8)     KeyElementPtr,
  uint32               KeyElementLength);

/**********************************************************************************************************************
 *  TLS CORE UPPER LAYER (UL)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsCoreUl_TcpConnected
 *********************************************************************************************************************/
/*! \brief         Forwards the TcpIp_TcpConnected call to the TLS stack
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreUl_TcpConnected(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreUl_Transmit
 *********************************************************************************************************************/
/*! \brief         Forwards the TcpIp_Transmit call to the TLS stack
 *  \details       -
 *  \param[in]     SocketIdx          Index of a TCP socket
 *                                    \spec requires SocketIdx < TcpIp_GetSizeOfSocketDyn(); \endspec
 *  \param[in]     DataPtr            Pointer of the source data.
 *  \param[in]     Length             Length of the source data.
 *  \param[in]     ForceRetrieve      The TCP force retrieve flag.
 *  \return        E_OK               Transmit request was accepted
 *  \return        E_NOT_OK           Transmit request was NOT accepted
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUl_Transmit(
  TcpIp_SizeOfSocketDynType SocketIdx,
  TCPIP_P2C(uint8)          DataPtr,
  uint32                    Length,
  boolean                   ForceRetrieve);

/**********************************************************************************************************************
 * TcpIp_TlsCoreUl_Received
 *********************************************************************************************************************/
/*! \brief         Forwards the TcpIp_TcpReceived call to the TLS stack
 *  \details       -
 *  \param[in]     SocketIdx             Socket identifier of the related local socket resource.
 *  \param[in]     DataLenByte           Received data byte length
 *  \param[out]    ErrorIdPtr           TCPIP_E_NO_ERROR    ReadIdx updated successfully
 *                                      TCPIP_E_INV_ARG     Function called with invalid parameters
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreUl_Received(
  TcpIp_SocketDynIterType    SocketIdx,
  uint32                     DataLenByte,
  TCPIP_P2V(uint8)           ErrorIdPtr);

#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCore_GetNextFreeTlsClientConnection
 *********************************************************************************************************************/
/*! \brief         Returns the corresponding TLS Connection assigned to this socket.
 *  \details       There always is a connection that is assigned to the socket.
 *  \param[in]     SocketIdx           Socket identifier of the related local socket resource.
 *  \param[in]     RemotePort          Remote port of the given socket.
 *  \param[out]    TlsConIdxPtr        Holds the next free TLS Connection Index
 *  \return        E_OK                Free TLS Client connection is found
 *  \return        E_NOT_OK            No free TLS Client connection is found
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCore_GetNextFreeTlsClientConnection(
  TcpIp_SizeOfSocketDynType SocketIdx,
  uint16 RemotePort,
  TCPIP_P2V(TcpIp_TlsConnectionIterType) TlsConIdxPtr);
#  endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsCore_ChangeParameter
 *********************************************************************************************************************/
/*! \brief         Forward the ChangeParameter call to the specific option handler
 *  \details       -
 *  \param[in]     SocketTcpIdx         Index of a TCP socket
 *                                      \spec requires SocketTcpIdx < TcpIp_GetSizeOfSocketTcpDyn(); \endspec
 *  \param[in]     OptName              Option name.  Valid option identifiers are:
 *                                        TCPIP_PARAMID_TLS_CONNECTION_ASSIGNMENT
 *  \param[in]     OptValPtr            Option parameter
 *  \return         E_OK                The request has been accepted.
 *  \return         E_NOT_OK            The request has not been accepted.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCore_ChangeParameter(
  TcpIp_SizeOfSocketTcpDynType SocketTcpIdx,
  uint8                        OptName,
  TCPIP_P2C(uint8)             OptValPtr);

/**********************************************************************************************************************
 *  TcpIp_TlsCore_IsTlsConnectionUsedByPortAndFree
 *********************************************************************************************************************/
/*! \brief         Checks if a TLS Connection is configured for the given port or not.
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                          CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     UsedPort            Port which is used to identify the TLS connection
 *  \return        TRUE                TLS Connection is configured for the given port and free to use
 *  \return        FALSE               TLS Connection is not configured for the given port or used
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(boolean, TCPIP_CODE) TcpIp_TlsCore_IsTlsConnectionUsedByPortAndFree(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint16, AUTOMATIC) UsedPort);

/**********************************************************************************************************************
 *  TLS CORE CONTENT TYPE (CT)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsCoreCtHs_ProcessMsg
 *********************************************************************************************************************/
/*! \brief         Checks message for completeness and forwards it to the HS state machine
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtHs_ProcessMsg(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TLS CORE LOWER LAYER (LL)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsCoreLl_RxIndication
 *********************************************************************************************************************/
/*! \brief         Write the data segment into the buffer struct management
 *  \details       -
 *  \param[in]     SocketTcpIdx        Index of a TCP socket
 *                                     \spec requires SocketTcpIdx < TcpIp_GetSizeOfSocketTcpDyn(); \endspec
 *  \param[in]     DataPtr             Pointer to the data
 *  \param[in]     DataLen             Length of the data
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreLl_RxIndication(
  TcpIp_SizeOfSocketTcpDynType SocketTcpIdx,
  TCPIP_P2V(uint8) DataPtr,
  uint16           DataLen);

#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsCoreLl_TcpConnected
 *********************************************************************************************************************/
/*! \brief         Informs TLS layers about the "connect" event on a socket.
 *  \details       Set the Communication socket on the next available TLS-Client Connection and triggers the TLS-HS.
 *  \param[in]     SocketIdx         Index of a TCP socket.
 *                                   \spec requires SocketIdx < TcpIp_GetSizeOfSocketDyn(); \endspec
 *  \return        E_OK              Upper layer has accepted the new connection.
 *  \return        E_NOT_OK          Upper layer has rejected the new connection.
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreLl_TcpConnected(
  TcpIp_SizeOfSocketDynType SocketIdx);
#  endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */

/**********************************************************************************************************************
 *  TLS CORE UTIL  (HELPER FUNCTIONS)
 *********************************************************************************************************************/
#  if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_IsUlEventForwardingNeededDuringClosing
 *********************************************************************************************************************/
/*! \brief         Checks if TLS should forward an event to the upper layer during closing a connection.
 *  \details       Only in case of TLS server during handshake, an event should not be forwarded to the upper layer.
 *  \param[in]     TlsConIdx            TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        TRUE                 TLS should forward events to the upper layer
 *  \return        FALSE                TLS should not forward events to the upper layer
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(boolean, TCPIP_CODE)  TcpIp_TlsCoreUtil_IsUlEventForwardingNeededDuringClosing(
  TcpIp_TlsConnectionIterType TlsConIdx);
#  endif

/**********************************************************************************************************************
 *  TcpIp_SocketIdxToTlsConIdx
 *********************************************************************************************************************/
/*! \brief         Returns the matching TLS connections index to the given socket index
 *  \details       -
 *  \param[in]     SocketIdx            Socket identifier of the related local socket resource.
 *  \param[in,out] TlsConIdxPtr         Pointer of the TLS Connection index of the corresponding socket
 *  \return        E_OK                 If TLS connection successful mapped to socket index
 *  \return        E_NOT_OK             If TLS connection could NOT mapped to socket index
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_SocketIdxToTlsConIdx(
  TcpIp_SocketDynIterType                SocketIdx,
  TCPIP_P2V(TcpIp_TlsConnectionIterType) TlsConIdxPtr);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_HandleInvalidConfiguration
 *********************************************************************************************************************/
/*! \brief         This function is called if an invalid or missing configuration is detected during runtime.
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreUtil_HandleInvalidConfiguration(
  TcpIp_TlsConnectionIterType TlsConIdx);

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsCoreUtil_CheckEccKeyMConfiguration
 *********************************************************************************************************************/
/*! \brief         Checks if the remote certificate reference of a Ecc connection is configured correctly
 *                 and if the KeyM_VerifyGroup() and KeyM_SetCertificateInGroup functions are available.
 *  \details       Adds a runtime check to not rely on a validator in the config.
 *  \param[in]     TlsConIdx                       TLS connection index
 *                                                 \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                            KeyM is configured correctly
 *  \return        E_NOT_OK                        KeyM is NOT configured correctly
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUtil_CheckEccKeyMConfiguration(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreUtil_PreVerifySignatureChecks
 *********************************************************************************************************************/
/*! \brief         Performs runtime checks which ensure valid lengths of temporary signature buffer
 *                 so that the verification of the signature can be performed.
 *  \details       Can be used for the signature of the public key and the signature of the client certificate verify
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK                    Checks are passed successfully
 *  \return        E_NOT_OK                Check failed, the error was handled
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUtil_PreVerifySignatureChecks(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreUtil_CheckPublicKeyCompressionFlagOfEllipticCurve
 *********************************************************************************************************************/
/*! \brief         Checks if the compression flag of the public key of the given curve is expected
 *  \details       -
 *  \param[in]     CurveId   RFC Curve identifier
 *  \return        TRUE if the compression flag is expected, otherwise FALSE
 *  \pre           -
 *  \context       TASK|ISR
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 ********************************************************************************************************************/
FUNC(boolean, TCPIP_CODE) TcpIp_TlsCoreUtil_CheckPublicKeyCompressionFlagOfEllipticCurve(
  CONST(TcpIp_TlsEllipticCurveIdType, AUTOMATIC) CurveId);
#  endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/***********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_ReturnCipherSpecificStreamingMode
 *********************************************************************************************************************/
/*! \brief         Returns the corresponding streaming mode of a given Cipher Suite
 *  \details       -
 *  \param[in]     Cipher                                       Cipher Suite Id
 *  \return        TCPIP_TLS_STREAMING_MODE_INVALID             If no valid active cipher is found
 *  \return        TCPIP_TLS_STREAMING_MODE_AES_128_CBC         For all _AES_128_CBC cipher
 *  \return        TCPIP_TLS_STREAMING_MODE_NULL                For all _NULL cipher
 *  \return        TCPIP_TLS_STREAMING_MODE_AES_128_GCM         For all _AES_128_GCM cipher
 *  \return        TCPIP_TLS_STREAMING_MODE_AES_256_GCM         For all _AES_256_GCM cipher
 *  \return        TCPIP_TLS_STREAMING_MODE_CHACHA20_POLY1305   For all _CHACHA20_POLY1305 cipher
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(TcpIp_TlsCipherStreamingModeDataType, TCPIP_CODE) TcpIp_TlsCoreUtil_ReturnCipherSpecificStreamingMode(
  TcpIp_TlsCipherDataType Cipher);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_ReturnSelectedCipherSpecificStreamingMode
 *********************************************************************************************************************/
/*! \brief         Returns the corresponding cipher mode of the selected CipherSuite for the given TlsConIdx
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        TCPIP_TLS_STREAMING_MODE_INVALID             If no valid active cipher is found
 *  \return        TCPIP_TLS_STREAMING_MODE_AES_128_CBC         For all _AES_128_CBC cipher
 *  \return        TCPIP_TLS_STREAMING_MODE_NULL                For all _NULL cipher
 *  \return        TCPIP_TLS_STREAMING_MODE_AES_128_GCM         For all _AES_128_GCM cipher
 *  \return        TCPIP_TLS_STREAMING_MODE_AES_256_GCM         For all _AES_256_GCM cipher
 *  \return        TCPIP_TLS_STREAMING_MODE_CHACHA20_POLY1305   For all _CHACHA20_POLY1305 cipher
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(TcpIp_TlsCipherStreamingModeDataType, TCPIP_CODE) TcpIp_TlsCoreUtil_ReturnSelectedCipherSpecificStreamingMode(
  TcpIp_TlsConnectionIterType       TlsConIdx);

/***********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_ReturnCipherSpecificKeyExchangeMethod
 *********************************************************************************************************************/
/*! \brief         Returns the corresponding key exchange of the passed CipherSuite
 *  \details       -
 *  \param[in]     Cipher              Cipher which should be used to determine the key exchange method
 *  \return        TCPIP_TLS_KEYEXCHANGE_METHOD_ECDHE       For ECDHE key exchange
 *  \return        TCPIP_TLS_KEYEXCHANGE_METHOD_ECDH        For ECDH key exchange
 *  \return        TCPIP_TLS_KEYEXCHANGE_METHOD_PSK_PLAIN   For plain PSK key exchange
 *  \return        TCPIP_TLS_KEYEXCHANGE_METHOD_INVALID     If no valid key exchange method is found
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(TcpIp_TlsKeyExchangeMethodDataType, TCPIP_CODE) TcpIp_TlsCoreUtil_ReturnCipherSpecificKeyExchangeMethod(
  TcpIp_TlsCipherDataType Cipher);

/***********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_ReturnSelectedCipherSpecificStreamingMode
 *********************************************************************************************************************/
/*! \brief         Returns the corresponding cipher mode of the selected CipherSuite for the given TlsConIdx
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return         TCPIP_TLS_KEYEXCHANGE_METHOD_ECDHE       For ECDHE key exchange
 *  \return         TCPIP_TLS_KEYEXCHANGE_METHOD_ECDH        For ECDH key exchange
 *  \return         TCPIP_TLS_KEYEXCHANGE_METHOD_PSK_PLAIN   For plain PSK key exchange
 *  \return         TCPIP_TLS_KEYEXCHANGE_METHOD_INVALID     If no valid key exchange method is found
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(TcpIp_TlsKeyExchangeMethodDataType, TCPIP_CODE) TcpIp_TlsCoreUtil_ReturnActiveCipherSpecificKeyExchangeMethod(
  TcpIp_TlsConnectionIterType       TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreUtil_ReturnCipherSpecificAuthenticationMode
 *********************************************************************************************************************/
/*! \brief         Returns the authentication mode of the given Cipher Suite
 *  \details       -
 *  \param[in]     Cipher                Cipher Suite Id
 *  \return        TCPIP_TLS_MSG_AUTH_MODE_NONE       If no authentication mode
 *  \return        TCPIP_TLS_MSG_AUTH_MODE_SHA256     Sha256 mode
 *  \return        TCPIP_TLS_MSG_AUTH_MODE_SHA1       Sha1 mode
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(TcpIp_TlsMessageAuthenticationModeDataType, TCPIP_CODE) TcpIp_TlsCoreUtil_ReturnCipherSpecificAuthenticationMode(
  TcpIp_TlsCipherDataType Cipher);

/**********************************************************************************************************************
 * TcpIp_TlsCoreUtil_GetExtensionsLengthAndCheckForValidity
 *********************************************************************************************************************/
/*! \brief           Reads the extensions length out of the buffer and checks if it is valid
 *  \details         The readIdx has to point to the beginning of the extensions
 *  \param[in]       TlsConIdx           TLS connection index
 *                                       \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]       MsgEndIdx           End index of the current message
 *                                       (extensions need to be located at the end of that message)
 *  \param[in,out]   ExtensionsLenPtr    Pointer to the extensions length
 *  \return          E_OK                Extensions length read from the buffer is valid
 *  \return          E_NOT_OK            Extensions length read from the buffer is invalid
 *                                       or there are no extensions present (readIdx == MsgEndIdx)
 *  \pre             -
 *  \context         TASK|ISR2
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUtil_GetExtensionsLengthAndCheckForValidity(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferRxIterType MsgEndIdx,
  TCPIP_P2V(uint16) ExtensionsLenPtr);

/**********************************************************************************************************************
 * TcpIp_Tls13ClientMsg_ServerEncryptedExtensionsParseExtensionSupportedGroups
 *********************************************************************************************************************/
/*! \brief         Performs length checks for a received TLS extension of the type supported_groups.
 *  \details       -
 *  \param[in]     TlsConIdx                      TLS connection index
 *                                                \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     SupportedGroupsExtension       Extension of type supported groups
 *  \param[out]    ReceivedSupportedGroupsLenPtr  Pointer to the received supported groups length
 *  \return        E_OK                           All length checks passed
 *  \return        E_NOT_OK                       At least one length check failed
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUtil_CheckLengthsOfExtensionSupportedGroups(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType      SupportedGroupsExtension,
  TCPIP_P2V(uint16)           ReceivedSupportedGroupsLenPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreUtil_GetTxCipherMacLen
 *********************************************************************************************************************/
/*! \brief        Returns the length of the MAC for the active cipher (TX)
 *  \details      -
 *  \param[in]    TlsConIdx           TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return       Length of the TX Cipher Mac
 *  \pre          -
 *  \context      TASK|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(uint8, TCPIP_CODE) TcpIp_TlsCoreUtil_GetTxCipherMacLen(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreUtil_GetCiphersuiteHashLen
 *********************************************************************************************************************/
/*! \brief        Returns the length of the hash for the passed ciphersuite
 *  \details      -
 *  \param[in]    Ciphersuite                     Ciphersuite whose hash length shall be determined
 *  \return       Length of the cipher's hash
 *  \pre          -
 *  \context      TASK|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(uint8, TCPIP_CODE) TcpIp_TlsCoreUtil_GetCiphersuiteHashLen(
  TcpIp_TlsCipherDataType     Ciphersuite);

#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsCoreUtil_ConnectionUseEccCipherSuite
 *********************************************************************************************************************/
/*! \brief         Checks if the given TLS connection uses at least one ECC cipher suite
 *  \details       -
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        TRUE                     if TlsConIdx is using at least one ECC cipher suite
 *  \return        FALSE                    if TlsConIdx is NOT using ECC cipher suite
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(boolean, TCPIP_CODE) TcpIp_TlsCoreUtil_ConnectionUseEccCipherSuite(
  TcpIp_TlsConnectionIterType TlsConIdx);
#  endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */

/**********************************************************************************************************************
 * TcpIp_TlsCoreUtil_CheckAndGetRootCertificateId
 *********************************************************************************************************************/
/*! \brief         Provides the ID of the used root certificate.
 *  \details       -
 *  \param[in]     TlsConIdx         Tls connection Index
 *                                   \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *                                   CONSTRAINT: Mode = TCPIP_TLS_CLIENT
 *  \param[out]    CertIdPtr         Pointer to return the root certificate ID.
 *  \return        E_OK              A root certificate was found. Returned value in CertIdPtr is valid.
 *                 E_NOT_OK          No root certificate was found. Returned value in CertIdPtr is invalid.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUtil_CheckAndGetRootCertificateId(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TCPIP_P2V(uint16)             CertIdPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreUtil_IsActiveHandshakeSet
 *********************************************************************************************************************/
/*! \brief         Checks if the active handshake for the passed TLS connection is set yet
 *  \details       -
 *  \param[in]     TlsConIdx         Tls connection Index
 *                                   \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        TRUE              The active handshake was set to a different value then the initial value.
 *                 FALSE             The active handshake has still its initial value.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(boolean, TCPIP_CODE) TcpIp_TlsCoreUtil_IsActiveHandshakeSet(
  TcpIp_TlsConnectionIterType   TlsConIdx);

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsCoreUtil_TlsUpdateCertChainStatus
 *********************************************************************************************************************/
/*! \brief         Queries the KeyM for the current statuses of certificates in the certificate chain
 *  \details       -
 *  \param[in]     TlsConIdx              TLS connection index
 *                                        \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     CertStatusUpdateMode   Parameter to control which certificate status should be updated:
 *                                        TCPIP_TLS_UPDATE_CERT_MODE_CHAIN: Update certificate chain information.
 *                                        TCPIP_TLS_UPDATE_CERT_MODE_OCSP:  Update OCSP certificate status information.
 *  \return        E_OK                   Certificate chain is valid, certificate status updated
 *                 E_NOT_OK               Error occurred in KeyM operation, certificate status not updated
 *  \pre           Certificate chain validation must be already triggered
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUtil_TlsUpdateCertChainStatus(
  TcpIp_TlsConnectionIterType           TlsConIdx,
  TcpIp_Tls_CertStatusUpdateModeType    CertStatusUpdateMode);

/**********************************************************************************************************************
 * TcpIp_TlsClient_TlsUpdateOcspCertificateStatus
 *********************************************************************************************************************/
/*! \brief         Update the received OCSP certificate status for the given certificate.
 *  \details       Read out the certificate status of the leaf certificate from the KeyM.
 *  \param[in,out] CertStatusPtr          Pointer to the certificate status struct
 *  \return        E_OK                   Successfully update the status.
 *                 E_NOT_OK               Error during update of the status.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClient_TlsUpdateOcspCertificateStatus(
  TCPIP_P2V(TcpIp_CertValidationStatusType) CertStatusPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreUtil_TlsUpdateOverallCertValidationResult
 *********************************************************************************************************************/
/*! \brief         Update the overall validation result of the received certificate chain
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[out]    CertValidResultPtr      Overall validation result of certificate chain
 *                                         All certificates in chain are valid (TCPIP_TLS_VALIDATION_OK)
 *                                         At least one certificate in chain is invalid (TCPIP_TLS_VALIDATION_NOT_OK)
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreUtil_TlsUpdateOverallCertValidationResult(
  TcpIp_TlsConnectionIterType                TlsConIdx,
  TCPIP_P2V(TcpIp_CertValidationResultType)  CertValidResultPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreUtil_TlsGetAlertForBadCertificateChain
 *********************************************************************************************************************/
/*! \brief         Determine the correct alert description for the bad certificate chain
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[out]    AlertDescriptionPtr     Alert description for the bad certificate chain
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreUtil_TlsGetAlertForBadCertificateChain(
  TcpIp_TlsConnectionIterType                TlsConIdx,
  TCPIP_P2V(TcpIp_TlsAlertDescriptionType)   AlertDescriptionPtr);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_GetCurveFromCertificate
 *********************************************************************************************************************/
/*! \brief         Returns the used curve of the public key algorithm of the certificate with the passed Id
 *  \details       -
 *  \param[in]     CertId                  KeyM certificate identifier
 *  \param[out]    CurveIdPtr              Pointer to the found curve Id
 *  \return        E_OK                    A matching curve and certificate was found
 *  \return        E_NOT_OK                No matching curve and certificate was found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUtil_GetCurveFromCertificate(
  TcpIp_CertificateIdType                   CertId,
  TCPIP_P2V(TcpIp_TlsEllipticCurveIdType)   CurveIdPtr);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_CheckSignatureAlgorithmAgainstCertificateAlgorithm
 *********************************************************************************************************************/
/*! \brief         Check if a Signature Algorithm matches the signature algorithm of a certificate
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     SignatureAlgorithm Signature Algorithm that should be checked
 *  \return        E_OK               Signature Algorithm matches
 *  \return        E_NOT_OK           Signature Algorithm does NOT match
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUtil_CheckSignatureAlgorithmAgainstCertificateAlgorithm(
  TcpIp_TlsConnectionIterType    TlsConIdx,
  TcpIp_SignatureAlgorithmIdType SignatureAlgorithm);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_ReadCertSignatureAlgorithm
 *********************************************************************************************************************/
/*! \brief         Read the signature algorithm from the leaf cert and map it to an identifier.
 *  \details       -
 *  \param[in]     CertId                  KeyM certificate identifier
 *                                         CONSTRAINT: [0..TcpIp_GetSizeOfTlsKeyMCertificate()-1]
 *  \param[out]    SignAlgIdPtr            Signature Algorithm Identifier
 *  \return        E_OK                    A signature algorithm could be read and identified
 *  \return        E_NOT_OK                Signature algorithm could not be read
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUtil_ReadCertSignatureAlgorithm(
  TcpIp_CertificateIdType CertId,
  TCPIP_P2V(TcpIp_SignatureAlgorithmIdType) SignAlgIdPtr);

/***********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_HasIpBaseBerElementExpectedValues
 *********************************************************************************************************************/
/*! \brief         Checks if the passed BerElement contains expected values
 *  \details       -
 *  \param[in]     EleDescPtr            Pointer to the IpBase BerElement which shall be checked
 *  \param[in]     ContentType           Expected ContentType
 *  \param[in]     MinContentLen         Smallest acceptable content length
 *  \param[in]     MaxContentLen         Largest acceptable content length
 *  \param[in]     ReceivedSignaturePtr  Pointer to the received signature
 *  \return        TRUE                  Passed BerElement contains expected values
 *  \return        FALSE                 Passed BerElement does contain an unexpected value
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(boolean, TCPIP_CODE) TcpIp_TlsCoreUtil_HasIpBaseBerElementExpectedValues(
  TCPIP_P2C(IpBase_BerElementType)    EleDescPtr,
  uint8                               ContentType,
  uint32                              MinContentLen,
  uint32                              MaxContentLen,
  TCPIP_P2C(uint8)                    ReceivedSignaturePtr);
#  endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TLS CORE CT ALERT
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreAlert_Set
 *********************************************************************************************************************/
/*! \brief         Set, prepare and trigger the Alert on the given TLS Connection
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     AlertLevel          Alert Level according to RFC5246
 *  \param[in]     AlertDescription    Alert Description according to RFC5246
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreAlert_Set(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsAlertLevelType AlertLevel,
  TcpIp_TlsAlertDescriptionType AlertDescription);

/**********************************************************************************************************************
 *  TLS CORE RECORD LAYER (RL)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_EncryptAndAuthFrame
 *********************************************************************************************************************/
/*! \brief          Perform encryption and authentication of TCP frame
 *  \details        This function encrypts and authenticates the content data present in the TLS buffer.
 *                  Note, this function could only be called with valid TCP buffers due to the address runtime check.
 *  \param[in]      SocketIdx         Index of TCP socket.
 *                                    \spec requires SocketIdx < TcpIp_GetSizeOfSocketDyn(); \endspec
 *  \param[in]      BufPtr            TCP buffer pointer
 *  \param[in]      BufLength         TCP buffer size
 *  \return         BUFREQ_OK         Data was encrypted and authenticated successfully
 *  \return         BUFREQ_E_NOT_OK   Data was not successfully processed. TCP RST will be sent.
 *  \pre            Raw TCP message is present in the TLS Tx buffer
 *  \context        TASK|ISR2
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_EncryptAndAuthFrame(
  TcpIp_SocketDynIterType SocketIdx,
  TCPIP_P2V(uint8)        BufPtr,
  uint16                  BufLength);

 /**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_FixGetTcpTxBuffer
 *********************************************************************************************************************/
/*! \brief          Return a VCA understandable pointer of input buffer.
 *  \details        The address of the input pointer should be equal to the output pointer. The output could be NULL_PTR
 *  \param[in]      Buffer       Start pointer of the array
 *  \param[in]      BufLen       Length of the array
 *  \return         Not NULL_PTR The pointer is element of the Tcp Tx Buffer
 *  \return         NULL_PTR     The input is invalid
 *  \pre            -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(TCPIP_P2V(uint8), TCPIP_CODE) TcpIp_TlsCoreRl_FixGetTcpTxBuffer(
  TCPIP_P2C(uint8) Buffer,
  uint32           BufLen);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_CheckTcpTxBufferInRange
 *********************************************************************************************************************/
/*! \brief          Check that the complete array is element of the Tcp Tx Buffer
 *  \details        -
 *  \param[in]      Buffer       Start pointer of the array
 *  \param[in]      BufLen       Length of the array
 *  \return         E_OK         The pointer is element of the Tcp Tx Buffer
 *  \return         E_NOT_OK     The input is invalid
 *  \pre            -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_CheckTcpTxBufferInRange(
  TCPIP_P2C(uint8) Buffer,
  uint32           BufLen);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_Transmit
 *********************************************************************************************************************/
/*! \brief         Forwards the transmit request to the TLS record layer
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     TxStartIdx          Start index within the TlsTxBuffer of the transmittable frame
 *  \param[in]     TxLen               Length of the transmittable frame
 *  \param[in]     ContentType         TLS content type of the transmittable frame
 *  \return        E_OK                Transmit request of frame was accepted
 *  \return        E_NOT_OK            Transmit request of frame was not accepted
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_Transmit(
  TcpIp_TlsConnectionIterType             TlsConIdx,
  TcpIp_TlsBufferTxIterType               TxStartIdx,
  TcpIp_SizeOfTlsBufferTxType             TxLen,
  uint8                                   ContentType);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_IncrementRxAdHsReadIdxWithWraparound
 *********************************************************************************************************************/
/*! \brief         Increment the AD/HS Rx Buffer
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     Length             Length which should be incremented
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_IncrementRxAdHsReadIdxWithWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint32 Length);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_IncrementUlRxIndIdxWithWraparound
 *********************************************************************************************************************/
/*! \brief         Increment the Ul RxIndication index considering wraparound
 *  \details       This function will be called when Ul RxIndication is invoked for newly processed data in
 *                 in TLS Rx AdhHs buffer
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     Length             Length of data in TLS Rx AdHs buffer which has been forwarded to Ul
 *                                    CONSTRAINT: Should not be greater than size of the TLS Rx buffer
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_IncrementUlRxIndIdxWithWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint32 Length);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_BlockDecryption
 *********************************************************************************************************************/
/*! \brief         Blocks the decryption of received record layers temporarily till new keys are calculated
 *  \details       Also reset other flags corresponding to the handling of HS messages preceding key changes
 *  \param[in]     TlsConIdx             TLS connection index
 *                                       \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_BlockDecryption(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_GetIvLengthInBufferSegments
 *********************************************************************************************************************/
/*! \brief         Check how much of the Iv is located in the first Tcp buffer segment and how much in the second
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     TcpSeg1Ptr         Pointer to TCP buffer segment 1
 *  \param[in]     ExplicitIvLen      Full Iv length
 *  \param[out]    TcpSeg1IvLenPtr    Pointer to length of Iv in TCP segment 1
 *  \param[out]    TcpSeg2IvLenPtr    Pointer to length of Iv in TCP segment 2
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE)  TcpIp_TlsCoreRl_GetIvLengthInBufferSegments(
  TCPIP_P2C(TcpIp_ConstSegmentType)      TcpSeg1Ptr,
  uint16                                 ExplicitIvLen,
  TCPIP_P2V(uint16)                      TcpSeg1IvLenPtr,
  TCPIP_P2V(uint16)                      TcpSeg2IvLenPtr);

/**********************************************************************************************************************
 *  TCPIP TLS INIT FUNCTIONS
 *********************************************************************************************************************/
#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsCore_RemoveLoadedCerts
 *********************************************************************************************************************/
/*! \brief         Removes all loaded certificates from KeyM
 *  \details       Called by TLS client / server to delete the processed server / client certificates
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCore_RemoveLoadedCerts(
  TcpIp_TlsConnectionIterType TlsConIdx);
#  endif /* TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsCore_Init
 *********************************************************************************************************************/
/*! \brief         Initialize the TLS core component
 *  \details       Iterate over all configured connections and initialize all subcomponents and the TLS Listener
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCore_Init(void);

/**********************************************************************************************************************
 *  TLS CORE BUFFER
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreBuffer_ClearRxBuffer
 *********************************************************************************************************************/
/*! \brief         Clears the TLS Rx buffer in the given range
 *  \details       -
 *  \param[in]     StartTlsBufferRxIdx   Start index within the RX buffer
 *  \param[in]     EndIdx                End index within the RX buffer
 *  \return         E_OK                 Rx buffer cleared successfully.
 *  \return         E_NOT_OK             Invalid input parameters. Buffer was not cleared.
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreBuffer_ClearRxBuffer(
  CONST(TcpIp_TlsBufferRxIterType, AUTOMATIC) StartTlsBufferRxIdx,
  CONST(TcpIp_TlsBufferRxIterType, AUTOMATIC) EndIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreBuffer_ClearTxBuffer
 *********************************************************************************************************************/
/*! \brief         Clears the TLS Tx buffer in the given range
 *  \details       -
 *  \param[in]     StartTlsBufferTxIdx   Start index within the TX buffer
 *                                       \spec requires StartIdx < TcpIp_GetSizeOfTlsBufferTx(); \endspec
 *  \param[in]     EndTlsBufferTxIdx     End index within the TX buffer
 *                                       \spec requires EndIdx < TcpIp_GetSizeOfTlsBufferTx(); \endspec
 *                                       \spec requires StartIdx <= EndIdx; \endspec
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreBuffer_ClearTxBuffer(
  CONST(TcpIp_TlsBufferTxIterType, AUTOMATIC) StartTlsBufferTxIdx,
  CONST(TcpIp_TlsBufferTxIterType, AUTOMATIC) EndTlsBufferTxIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRxBufStruct_WriteRxBufSegment()
 **********************************************************************************************************************/
/*! \brief         Writes segment to rx buffer struct.
 *  \details       -
 *  \param[in]     RxBufStructSegIdx    TLS Rx buffer struct index
 *                                      \spec requires RxBufStructSegIdx < TcpIp_GetSizeOfRxBufStructSeg(); \endspec
 *  \param[in]     SrcBufPtr            Pointer to linear source buffer.
 *  \param[in]     SrcBufLen            Length of linear source buffer.
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     TRUE for different rx buffer structs, FALSE for same rx buffer struct.
 *  \synchronous   TRUE
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRxBufStruct_WriteRxBufSegment(
  TcpIp_SizeOfRxBufStructSegType RxBufStructSegIdx,
  TCPIP_P2V(uint8) SrcBufPtr,
  uint16 SrcBufLen);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreBuffer_GetAvailableTxBufferSize
 *********************************************************************************************************************/
/*! \brief          Read the available size of the TLS tx buffer.
 *  \details        Returns the available size of the TLS tx buffer (= buffer size - fill level).
 *                  If this is a listen socket, no buffer size can be read so the size is 0.
 *  \param[in]      SocketIdx                  socket index
 *  \param[out]     AvailableTxBufferSizePtr   Returns the free space in the tx buffer.
 *  \return         E_OK                       The available size could be read successfully.
 *  \return         E_NOT_OK                   Reading was not successful.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreBuffer_GetAvailableTxBufferSize(
  TcpIp_SocketDynIterType SocketIdx,
  TCPIP_P2V(uint32) AvailableTxBufferSizePtr);

/**********************************************************************************************************************
 *  TLS CORE MAIN FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreMainFunction_LowPrio
 *********************************************************************************************************************/
/*! \brief         Processes all time consuming operation in the background context
 *  \details       -
 *  \pre           -
 *  \context       TASK (only called in the context of the TLS background task TcpIp_Tls_MainFunctionLowPrio())
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_LowPrio(void);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMainFunction_Rx
 *********************************************************************************************************************/
/*! \brief         Processes all received data and forwards information to upper layers
 *  \details       -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_Rx(void);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMainFunction_State
 *********************************************************************************************************************/
/*! \brief         Performs all state and timing specific actions
 *  \details       Performs all processing of the TLS handshakes states, the heartbeat handling,
 *                 the error and alert handling as well as the TcpIp Event handling
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_State(void);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMainFunction_Tx
 *********************************************************************************************************************/
/*! \brief         Processes all pending transmit requests from the upper layers and transmits the data
 *  \details       -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_Tx(void);

/**********************************************************************************************************************
 * TcpIp_TlsAsyncCtx_HandleErrorDuringAsyncJobProcessing
 *********************************************************************************************************************/
/*! \brief          Handles occurring errors during an asynchronous processing
 *  \details        -
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]      FunctionId              FunctionId of function which triggers error
 *  \param[in]      ErrorId                 Error Id of occurred error
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 ********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsAsyncCtx_HandleErrorDuringAsyncJobProcessing(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 FunctionId,
  uint16 ErrorId);

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsCoreMsg_CertMsgSetCertificatesInGroup
 *********************************************************************************************************************/
/*! \brief         Set the certificates from the received certificate chain into the KeyM certificate group
 *  \details       -
 *  \param[in]     TlsConIdx                       TLS connection index
 *                                                 \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     CertStartIdx                    Start Idx of the certificate data
 *  \param[in]     NumCerts                        Number of certificates in cert chain
 *  \return        E_OK                            Certificates set successfully
 *  \return        E_NOT_OK                        Not able to set at least one certificate
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreMsg_CertMsgSetCertificatesInGroup(
  TcpIp_TlsConnectionIterType         TlsConIdx,
  TcpIp_TlsBufferRxIterType           CertStartIdx,
  uint8                               NumCerts);

/**********************************************************************************************************************
 * TcpIp_TlsCoreMsg_EncodeSecpSignature
 *********************************************************************************************************************/
/*! \brief         Encode SECP (secp256r1 or secp521r1) based signatures into ASN1 format defined by RFC.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] ConsumedLenPtr          Number of consumed bytes
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMsg_EncodeSecpSignature(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint8) ConsumedLenPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreMsg_EncodeEd25519Signature
 *********************************************************************************************************************/
/*! \brief         Encode ED25519 based signatures into format defined by RFC.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] ConsumedLenPtr          Number of consumed bytes
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMsg_EncodeEd25519Signature(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint8) ConsumedLenPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreMsg_EncodeEd448Signature
 *********************************************************************************************************************/
 /*! \brief         Encode ED448 based signatures into format defined by RFC.
  *  \details       -
  *  \param[in]     TlsConIdx               TLS connection index
  *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
  *  \param[in,out] ConsumedLenPtr          Number of consumed bytes
  *  \pre           -
  *  \context       TASK
  *  \reentrant     FALSE
  *  \synchronous   TRUE
  *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMsg_EncodeEd448Signature(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint8) ConsumedLenPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreMsg_DecodeSignature
 *********************************************************************************************************************/
/*! \brief         Decode the received signature
 *  \details       Depending on the cipher suite perform decode operation
 *  \param[in,out] TemporarySignatureBufferSeg       Pointer to the temporary signature buffer segment (output segment)
 *  \param[in]     SignatureAlgorithmId              Signature algorithm ID
 *  \param[in]     SignatureTlsBufferRxIdx           Buffer index of the received encoded signature
 *  \param[in]     SignatureLenTlsBufferRxIdx        Buffer index of the received encoded signature length
 *  \return        E_OK                              Operation successful
 *  \return        E_NOT_OK                          Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreMsg_DecodeSignature(
  TcpIp_SegmentPtrType           TemporarySignatureBufferSeg,
  TcpIp_SignatureAlgorithmIdType SignatureAlgorithmId,
  TcpIp_TlsBufferRxIterType      SignatureTlsBufferRxIdx,
  TcpIp_TlsBufferRxIterType      SignatureLenTlsBufferRxIdx);
#  endif

/**********************************************************************************************************************
 * TcpIp_TlsCore_ResetRlRxIndicationFlag
 *********************************************************************************************************************/
/*! \brief         Resets the Rl Rx indication flag if all received records are processed
 *  \details       -
 *  \param[in]     TlsConIdx            TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     TriggerContentType   The content type from which the reset is triggered.
 *                                      It is checked that all records with other content types are processed.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCore_ResetRlRxIndicationFlag(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC)     TriggerContentType);

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsMsg_GetLenOfCurveSpecificPubKey
 *********************************************************************************************************************/
/*! \brief         Returns the length of the public key of the given curve
 *  \details       -
 *  \param[in]     CurveId   RFC Curve identifier
 *  \return        Length of the public key, 0 if curve ID is not supported.
 *  \pre           -
 *  \context       TASK|ISR
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 ********************************************************************************************************************/
FUNC(uint8, TCPIP_CODE) TcpIp_TlsMsg_GetLenOfCurveSpecificPubKey(
  CONST(TcpIp_TlsEllipticCurveIdType, AUTOMATIC) CurveId);
#  endif

/**********************************************************************************************************************
 * TcpIp_TlsMsg_AddUint16ValueToDistinctListInTxBuffer
 *********************************************************************************************************************/
/*! \brief         Add an uint16-value to the end of a list of uint16-values in the TLS Tx buffer
 *  \details       If the passed value is already contained in the list, it will not be added
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     Value                   Uint16-value which shall be added
 *  \param[in]     ListStartIdx            Start index of the list in the TLS Tx buffer
 *  \param[in,out] ConsumedLenPtr          Consumed bytes of the list (length of the list in bytes)
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsMsg_AddUint16ValueToDistinctListInTxBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16                      Value,
  TcpIp_TlsBufferTxIterType   ListStartIdx,
  TCPIP_P2V(uint16)           ConsumedLenPtr);

/**********************************************************************************************************************
 * TcpIp_TlsMsg_IsUint16ValueAlreadyPresentInTxBufferList
 *********************************************************************************************************************/
/*! \brief         Check whether given value has already been added to the specified list in TxBuffer
 *  \details       -
 *  \param[in]     ListStartIdx            Start index of the list in TxBuffer
 *  \param[in]     ListEndIdx              End index of the list in TxBuffer
 *  \param[in]     Value                   Value to be checked
 *  \return        TRUE                    Value is present
 *  \return        FALSE                   Value is not present
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(boolean, TCPIP_CODE) TcpIp_TlsMsg_IsUint16ValueAlreadyPresentInTxBufferList(
  TcpIp_TlsBufferTxIterType ListStartIdx,
  TcpIp_TlsBufferTxIterType ListEndIdx,
  uint16                    Value);

/**********************************************************************************************************************
 *  TLS CORE MAIN FUNCTION TX
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TLS CORE STATES AND EVENTS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsCoreEvent_TcpIpEventForwarding
 *********************************************************************************************************************/
/*! \brief         Forwards all occurred TCP events to the TLS stack
 *  \details       -
 *  \param[in]     SocketIdx      Socket identifier of the related local socket resource.
 *  \param[in]     Event          Occurred TCP event
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreEvent_TcpIpEventForwarding(
  TcpIp_SocketDynIterType SocketIdx,
  IpBase_TcpIpEventType   Event);

/**********************************************************************************************************************
 * TcpIp_TlsCoreEvent_TcpIpEventClose
 *********************************************************************************************************************/
/*! \brief         Forwards the TcpIp event CLOSE to the TLS stack
 *  \details       -
 *  \param[in]     SocketId Socket handle identifying the local socket resource.
 *                 \spec requires SocketIdx < TcpIp_GetSizeOfSocketDyn(); \endspec
 *  \param[in]     Abort    TRUE: connection will immediately be terminated
 *                          FALSE: connection will be terminated after performing a regular connection termination
 *                          handshake and releasing all related resources.
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreEvent_TcpIpEventClose(
  TcpIp_SocketDynIterType SocketIdx,
  boolean Abort);

/**********************************************************************************************************************
 *  TLS CONNECTION STATE HANDLER
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TLS CORE ERROR
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreError_GetUserError
 *********************************************************************************************************************/
/*! \brief         Reported user errors can be read by the user and stored into the given user buffer.
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] UserErrorMemoryPtr  Pointer to the user buffer, where user error entries will be stored.
 *  \param[in,out] NumOfUserErrorPtr   Number of user errors upper layer wants to read.
 *  \return        E_OK                if reading of user error was successful.
 *                 E_NOT_OK            if reading of user error was NOT successful
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreError_GetUserError(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(TcpIp_TlsUserErrorType) UserErrorMemoryPtr,
  TCPIP_P2V(uint32) NumOfUserErrorPtr);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreError_ClearUserError
 *********************************************************************************************************************/
/*! \brief         Clear all reported user errors.
 *  \details        -
 *  \param[in]      TlsConIdx          TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreError_ClearUserError(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreError_ReportUserError
 *********************************************************************************************************************/
/*! \brief         User errors will be stored into the user error buffer as soon as invalid packet is received.
 *  \details       -
 *  \param[in]     UserError           Combined information about the occurring error.
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreError_ReportUserError(
  CONST(TcpIp_TlsUserErrorType, AUTOMATIC) UserError);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreError_UserErrorCallout
 *********************************************************************************************************************/
/*! \brief         Notify Upper layer for the reported User errors that can be read.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreError_UserErrorCallout(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreError_IndicationTrigger
 *********************************************************************************************************************/
/*! \brief         Forward the raised TLS error indication to the upper layer via callout.
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ErrorIndication     Raised TLS error indication.
 *  \param[in]     AlertDescription    Received/Transmitted TLS-Alert.
 *                                     CONSTRAINT: [only valid if TlsErrorIndication is set to TCPIP_TLS_E_RX_ALERT
 *                                                  or TCPIP_TLS_E_TX_ALERT]
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreError_IndicationTrigger(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_Tls_ErrorIndicationType ErrorIndication,
  TcpIp_TlsAlertDescriptionType AlertDescription);

/**********************************************************************************************************************
 *  TCPIP TLS CRYPTO
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreCrypto_ClearCsmKey
 *********************************************************************************************************************/
/*! \brief         Clears the given Key within the CSM
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     KeyPtr              Pointer to the CMS Key which should be cleared
 *  \return        E_OK                if the key could be cleared
 *  \return        E_NOT_OK            otherwise
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCrypto_ClearCsmKey(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(TcpIp_TlsCsmKeyInfoType) KeyPtr);

#  if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsCoreCtx_CalcDiffieHellmanPublicKey
 *********************************************************************************************************************/
/*! \brief          Asynchronous handler for calculation the Diffie-Hellman public key
 *  \details        -
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]      TlsHandshakeIdx         TLS handshake index for which the public key should be calculated
 *  \pre            -
 *  \context        TASK (only called in the context of the TLS background task TcpIp_Tls_MainFunctionLowPrio())
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 ********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtx_CalcDiffieHellmanPublicKey(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsHandshakeIterType  TlsHandshakeIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtx_ForwardKeyToCsmForDhSharedSecretCalculation
 *********************************************************************************************************************/
/*! \brief           Forward the public key to the Csm for the Diffie-Hellman Shared Secret Calculation
 *  \details         Is called in asynchronous handler
 *  \param[in]       TlsConIdx          TLS connection index
 *                                      CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in,out]   PublicKeyPtr       Pointer to the public key
 *  \param[in]       PublicKeyLen       Length of the public key
 *  \param[in,out]   LocalErrorIdPtr    Pointer where the Id of a local error which might occur can be stored
 *  \pre             -
 *  \context         TASK (only called in the context of the TLS background task TcpIp_Tls_MainFunctionLowPrio())
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtx_ForwardKeyToCsmForDhSharedSecretCalculation(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(uint8)            PublicKeyPtr,
  uint32                      PublicKeyLen,
  TCPIP_P2V(uint16)           LocalErrorIdPtr);
#  endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCrypto_CheckCsmResult
 *********************************************************************************************************************/
/*! \brief         Checks the return value and result length of a CSM call
 *  \details       In case the check fails errors are thrown and connection may be closed.
 *                 In case the result was not relevant set the values to 0.
 *  \param[in]     TlsConIdx            TLS connection index
 *  \param[in]     CsmRetVal            Return value of the CSM call
 *  \param[in]     CsmResultLength      Result length of the CSM call
 *  \param[in]     ExpectedResultLength Expected length of result
 *  \param[in]     ApiId                API in which the CSM call has been made
 *  \param[in]     ErrorId              ErrorId in which the CSM call has been made
 *  \return        E_OK                 If CsmRetVal is set to E_OK and the length match
 *  \return        E_NOT_OK             If either the CsmRetVal is E_NOT or the length does not match
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCrypto_CheckCsmResult(
  TcpIp_TlsConnectionIterType TlsConIdx,
  Std_ReturnType CsmRetVal,
  uint32 CsmResultLength,
  uint32 ExpectedResultLength,
  TcpIp_TlsFunctionIdType ApiId);

/**********************************************************************************************************************
 *  TLS RX BUFFER MANAGEMENT / DECRYPT
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_DecryptAndAuthenticateFrame
 *********************************************************************************************************************/
/*! \brief         Decrypt and authenticate a record layer frame
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *  \param[in]     ContentType         TLS content type
 *  \param[in]     DecryptDataPtr      Pointer to the struct that contains all the required pointers to buffer segments
 *  \return        E_OK                Decryption and authentication of the frame was successful
 *  \return        E_NOT_OK            Decryption or authentication of the frame failed
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_DecryptAndAuthenticateFrame(
  TcpIp_TlsConnectionIterType          TlsConIdx,
  CONST(uint8, AUTOMATIC)              ContentType,
  TCPIP_P2C(TcpIp_TlsDecryptDataType)  DecryptDataPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_GetReadMaxIdxForContentType
 *********************************************************************************************************************/
/*! \brief         Get the Rx buffer ReadMaxIdx of a TLS-connection depending on content type
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType         TLS content type
 *  \return                            ReadMaxIdx
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(TcpIp_SizeOfTlsBufferRxType, TCPIP_CODE)  TcpIp_TlsCoreRl_GetReadMaxIdxForContentType(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  CONST(uint8, AUTOMATIC)       ContentType);

/**********************************************************************************************************************
 *  TCPIP TLS CORE SECRET ACCESS
 *********************************************************************************************************************/

#  if (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsCore_ReadTlsSecrets
 *********************************************************************************************************************/
/*! \brief         User can read secrets for TLS en-/decryption and client random
 *  \details       - TLS 1.2: Master Secret Key, Client Random Number,
                   - TLS 1.3: Client/Server Handshake Traffic Secret, Client/Server Application Traffic Secret
 *  \param[in]     SocketId         Socket identifier of the related local socket resource.
 *  \param[out]    Tls12_SecretPtr  Pointer to the struct which holds the user buffer, where Master Secret Key,
                                    the Client Random value and the Session ID shall be stored.
                                    CONSTRAINT: The pointed user buffer of Master Secret Key must have the size TCPIP_TLS_MASTER_SECRET_LEN
                                    CONSTRAINT: The pointed user buffer for the client random value must have the size TCPIP_TLS_RANDOM_LEN.
                                    CONSTRAINT: The pointed user buffer for the session id must have the size TCPIP_TLS_SESSIONIDMAX_LEN.
 *  \param[out]    Tls13_SecretPtr  Pointer to the struct which holds the user buffer, where Client Traffic Secret,
                                    the Server Traffic Secret and the Client Random value shall be stored.
                                    CONSTRAINT: The pointed user buffer of Client/Server Secret Key must have the size TCPIP_TLS_MAX_SIZE_OF_TLS_SECRET
                                    CONSTRAINT: The pointed user buffer for the client random value must have the size TCPIP_TLS_RANDOM_LEN.
 *  \return        E_OK             If reading was successful.
 *                 E_NOT_OK         If SocketId was invalid or CSM call failed.
 *  \pre           TLS-Connection on this socket must be in the state >= TCPIP_TLS_STATE_CONNECTION_HS_ACTIVE
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCore_ReadTlsSecrets(
  TcpIp_SocketDynIterType SocketIdx,
  TCPIP_P2C(TcpIp_Tls12_Secret_Type) Tls12_SecretPtr,
  TCPIP_P2C(TcpIp_Tls13_Secret_Type) Tls13_SecretPtr);

/**********************************************************************************************************************
*  TcpIp_TlsCore_IssueKeyUpdateCallout
*********************************************************************************************************************/
/*! \brief         Issues the callout to indicate a key update in TLS
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     KeyUpdateType       The type of the Key Update
 *  \return        E_OK                If callout was successful.
 *                 E_NOT_OK            If SocketIdx or FuncPtr was invalid.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCore_IssueKeyUpdateCallout(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsKeyUpdateType KeyUpdateType);
#  endif

#  if (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCore_SendSecretViaNssFrame
 *********************************************************************************************************************/
/*! \brief         Sends a NSS Frame of a TLS 1.3 secret. Layout:  <Label><space><ClientRandom><space><Secret>
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     CsmKeyId            The keyId of the secret which should be sent via NSS Frame
 *  \param[in]     CsmKeyElementId     The elementId of the key
 *  \param[in]     LabelPtr            The pointer to the label string
 *  \param[in]     LabelLen            The length of the label string
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCore_SendSecretViaNssFrame(
  TcpIp_TlsConnectionIterType                   TlsConIdx,
  TcpIp_CsmKeyIdType                            CsmKeyId,
  TcpIp_HsCommonKeyElementIdOfTlsHandshakeType  CsmKeyElementId,
  TCPIP_P2C(uint8)                              LabelPtr,
  uint8                                         LabelLen);
#  endif /* (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON) */

# endif /* (TCPIP_SUPPORT_ASRTLS == STD_ON) */
#endif /* TCPIP_TLSCORECOMMON_H */
/***********************************************************************************************************************
 *  END OF FILE: TcpIp_TlsCoreCommon.h
 **********************************************************************************************************************/
