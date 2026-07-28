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
/*!        \file  TcpIp_TlsCoreCommon.c
 *        \brief  Transport Layer Security (TLS) core functions implementation.
 *
 *      \details  This file implements the core routines of the TLS stack, which are used both by the TLS version 1.2
 *                and the version 1.3. This file is part of the TcpIp TLS submodule.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp module. >> TcpIp.h
 *********************************************************************************************************************/

#define TCPIP_TLSCORECOMMON_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TcpIp_Cfg.h"

#if (TCPIP_SUPPORT_ASRTLS == STD_ON)                                                                                    /* COV_MSR_UNSUPPORTED */
# include "TcpIp_TlsCoreCommon.h"
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#  include "TcpIp_Tls12Core.h"
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
# include "TcpIp_Tls.h"
# include "TcpIp_TlsPriv.h"

# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#  include "TcpIp_TlsServer.h"
# endif /* (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON) */
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#   include "TcpIp_Tls12Client.h"
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#   include "TcpIp_Tls13Client.h"
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
#  include "TcpIp_TlsClientCommon.h"
# endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#  include "TcpIp_Tls13Core.h"
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
# if (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON)
#  include "TcpIp_Priv.h"
#  include "TcpIp_Udp.h"
#  include "TcpIp_IpV6.h"
# endif /* (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON) */

# include "TcpIp_Types.h"
# include "TcpIp_Lcfg.h"
# include "vstdlib.h"
# include "TcpIp_Tcp_Cbk.h"
# include "TcpIp_Tcp.h"

# if (TCPIP_DEV_ERROR_REPORT == STD_ON)
#  include "Det.h"
# endif /* (TCPIP_DEV_ERROR_REPORT == STD_ON) */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
# define TCPIP_RX_INDICATION_LEN_MAX         (0xFFFFU)
# define TCPIP_TX_INDICATION_LEN_MAX         (0xFFFFU)

# define TCPIP_RX_BUF_SEG_SIZE_TOTAL               2U

 /* PRQA S 3453 3 */ /* MD_MSR_FctLikeMacro */
# define TCPIP_TLS_GET_AES128CBC_PADDING_LEN( AES_INPUT_LEN ) (((AES_INPUT_LEN % TCPIP_TLS_AES_BLOCK_LEN) == 0U) ? 0U : ((uint8)TCPIP_TLS_AES_BLOCK_LEN - (uint8)(AES_INPUT_LEN % TCPIP_TLS_AES_BLOCK_LEN)))
# define TCPIP_TLS_GET_AES128CBC_NROFFULLBLOCKS( BUF_INPUT_LEN) (((BUF_INPUT_LEN % TCPIP_TLS_AES_BLOCK_LEN) == 0U) ? 0U : (TCPIP_TLS_AES_BLOCK_LEN - (BUF_INPUT_LEN % TCPIP_TLS_AES_BLOCK_LEN) -1U))

# if (CPU_TYPE == CPU_TYPE_32)                                                                                          /* COV_TCPIP_HARDWARE_DEPENDING */
typedef uint32 uintPtrTyp;
# elif (CPU_TYPE == CPU_TYPE_64)                                                                                        /* COV_TCPIP_HARDWARE_DEPENDING */
typedef uint64 uintPtrTyp;
# else                                                                                                                  /* COV_TCPIP_HARDWARE_DEPENDING */
/* Only 32 and 64 bit platforms are supported. */
# endif
struct VerifyPtrStructNotForUsage                                                                                       /* PRQA S 3213 */ /* MD_TcpIp_TLS_BUILD_CHECK_STRUCT */
{
  /* Don't use this struct, it only exists to verify at compile time that our pointer size assumption holds on the current platform. */
  /* CM_TCPIP_TLS_R_WRITE_INDEX_AND_BUFFER_AREA_LENGTH_CSL01 */
  uint8 VerifyOperation1[((sizeof(void*) == sizeof(uintPtrTyp)) ? 1 : -1)];                                             /* PRQA S 3493 */ /* MD_TcpIp_TLS_HARDWARE_DEPENDING */ /*lint !e506 */
  uint8 VerifyOperation2[((sizeof(TcpIp_SizeOfTcpTxBufferType) <= sizeof(uint32)) ? 1 : -1)];                           /* PRQA S 3493 */ /* MD_TcpIp_TLS_HARDWARE_DEPENDING */ /*lint !e506 */
  uint8 VerifyOperation3[((sizeof(TcpIp_SizeOfTcpRxBufferType) <= sizeof(uint32)) ? 1 : -1)];                           /* PRQA S 3493 */ /* MD_TcpIp_TLS_HARDWARE_DEPENDING */ /*lint !e506 */
};

# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)

#  define TCPIP_TLS_OID_MAX_LEN            (TCPIP_TLS_OID_ALGO_ID_MAX_LEN + TCPIP_TLS_OID_ALGO_ID_OFFSET + TCPIP_TLS_OID_OBJECT_ID_OFFSET)
#  define TCPIP_TLS_OID_ALGO_ID_MAX_LEN    8u  /* Length for an array to read OIDs from certs. All OIDs that are listed here should fit. */
#  define TCPIP_TLS_OID_OBJECT_ID_OFFSET   2u
#  define TCPIP_TLS_OID_ALGO_ID_OFFSET     2u
#  define TCPIP_TLS_OID_ALGO_ID_LEN        1u
#  define TCPIP_TLS_OID_ALGO_ID_ID         0x06u

/* OID list online (one example): http://www.oid-info.com/get/1.2.840.10045.4.3.2 */                                    /* PRQA S 3108 */ /* MD_TCPIP_Rule3.1_3108 */
/* Signature algorithm IDs */
#  define TCPIP_TLS_OID_SIGNATURE_ALGORITHM_ECDSA_SHA_LEN          8u /* Since TCPIP_TLS_OID_SIGNATURE_ALGORITHM_ECDSA_SHA256_LEN and TCPIP_TLS_OID_SIGNATURE_ALGORITHM_ECDSA_SHA512_LEN have the same length, have one define which can be used for both. */
#  define TCPIP_TLS_OID_SIGNATURE_ALGORITHM_ECDSA_SHA256_LEN       8u
#  define TCPIP_TLS_OID_SIGNATURE_ALGORITHM_ECDSA_SHA512_LEN       8u
#  define TCPIP_TLS_OID_SIGNATURE_ALGORITHM_CURVE_25519_448_LEN    3u /* Length of OID of signature algorithm of curve 25519 and 448 */
#  define TCPIP_TLS_OID_PUBKEY_EC_LEN                              7u
#  define TCPIP_TLS_OID_PUBKEY_NAMED_CURVE_SECP256R1_LEN           8u
#  define TCPIP_TLS_OID_PUBKEY_NAMED_CURVE_SECP521R1_LEN           5u
# endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

# if (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON)
#  define TCPIP_HEX_SPACE                                 0x20u
#  define TCPIP_HEX_SPACE_LEN                             1u
#  define TCPIP_TLS_NSS_FRAME_STATIC_LEN                  ((TCPIP_TLS_RANDOM_LEN * 2u) + (TCPIP_HEX_SPACE_LEN * 2u)) /* Length of RANDOM is doubled due to HEX encoding */
# endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
# if !defined (TCPIP_LOCAL)
#  define TCPIP_LOCAL static
# endif

# if !defined (TCPIP_LOCAL_INLINE)
#  define TCPIP_LOCAL_INLINE LOCAL_INLINE
# endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)

typedef struct
{
  /* This structure is used when analyzing a plain secp signature component and transforming it into a BER encoded
  integer value. */

  TCPIP_P2C(uint8) RawValueSrcPtr;                 /* pointer to the r or s parameter in a raw SECP signature (plain
                                                   signature without any encoding) */
  TcpIp_TlsBufferTxIterType Asn1SequenceStartIdx;  /* Start position of the BER encoded signature coordinate (that will
                                                   be written later) */
  uint8   CoordinateByteLen;                       /* Length of a plain signature component */
  uint8   Asn1Len;                                 /* Length of the BER encoded signature component (only the value) */
  boolean PrependLeadingZero;                      /* Indicates if a leading zero has to be prepended to the raw
                                                   signature component when encoding as an integer value */
  uint8   NumberOfSkippingLeadingZeros;            /* Indicates the number of leading zeros in the plain signature
                                                   component that have to be removed when encoding as an integer value */
} TcpIp_TlsSecpSignCoordinateDescriptorType;

# endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */
/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/* Data array to trace the important buffer indices */
# if ( TCPIP_DEV_ERROR_DETECT == STD_ON )
#  ifndef TCPIP_TLS_RX_BUFFER_IDX_LOG_SIZE
#   define TCPIP_TLS_RX_BUFFER_IDX_LOG_SIZE 20u
#  endif
/* The following information is saved in the array:
   TlsConIdx/CallPos/ContentType(2 byte TlsConIdx, 1 byte CallPos, 1 byte ContentType)
   WriteIdx,
   ReadIdx,
   UlRxIndIdx
*/
#  define TCPIP_TLS_RX_BUFFER_IDX_LOG_INFO_SIZE 4u
/* The current indices will be written at TcpIp_TlsRxBufferIdxLogPos into the array.
 * When TcpIp_TlsRxBufferIdxLogPos reaches TCPIP_TLS_RX_BUFFER_IDX_LOG_SIZE
 * the old indices at the start of the array will be overwritten. */
#  define TCPIP_START_SEC_VAR_NO_INIT_8
#  include "TcpIp_MemMap.h"                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */
TCPIP_LOCAL VAR(uint8, TCPIP_VAR_NO_INIT) TcpIp_TlsRxBufferIdxLogPos;                                                   /* PRQA S 3218 1 */ /* MD_TCPIP_Rule8.9_3218 */
#  define TCPIP_STOP_SEC_VAR_NO_INIT_8
#  include "TcpIp_MemMap.h"                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define TCPIP_START_SEC_VAR_NO_INIT_32
#  include "TcpIp_MemMap.h"                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */
TCPIP_LOCAL VAR(uint32, TCPIP_VAR_NO_INIT) TcpIp_TlsRxBufferIdxLog[TCPIP_TLS_RX_BUFFER_IDX_LOG_SIZE][TCPIP_TLS_RX_BUFFER_IDX_LOG_INFO_SIZE]; /* PRQA S 3218 1 */ /* MD_TCPIP_Rule8.9_3218 */
#  define TCPIP_STOP_SEC_VAR_NO_INIT_32
#  include "TcpIp_MemMap.h"                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif


# define TCPIP_START_SEC_CONST_8
# include "TcpIp_MemMap.h"                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)

/* OID list online (one example): http://www.oid-info.com/get/1.2.840.10045.4.3.2 */                                    /* PRQA S 3108 */ /* MD_TCPIP_Rule3.1_3108 */

/* PRQA S 3218 9 */ /* MD_TCPIP_Rule8.9_3218 */
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_OidSignatureAlgorithmEcdsaSha256[TCPIP_TLS_OID_SIGNATURE_ALGORITHM_ECDSA_SHA256_LEN] = { 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03, 0x02 }; /* 1.2.840.10045.4.3.2 */  /* no specific curve */
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_OidSignatureAlgorithmEcdsaSha512[TCPIP_TLS_OID_SIGNATURE_ALGORITHM_ECDSA_SHA512_LEN] = { 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03, 0x04 }; /* 1.2.840.10045.4.3.4 */  /* no specific curve */
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_OidSignatureAlgorithmCurveEd25519[TCPIP_TLS_OID_SIGNATURE_ALGORITHM_CURVE_25519_448_LEN] = { 0x2b, 0x65, 0x70 }; /* 1.3.101.112 */  /* only curve ED25519 */
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_OidSignatureAlgorithmCurveEd448[TCPIP_TLS_OID_SIGNATURE_ALGORITHM_CURVE_25519_448_LEN] = { 0x2b, 0x65, 0x71 }; /* 1.3.101.113 */  /* only curve ED448 */
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_OidSignatureAlgorithmX25519[TCPIP_TLS_OID_SIGNATURE_ALGORITHM_CURVE_25519_448_LEN] = { 0x2b, 0x65, 0x6e }; /* 1.3.101.110 */  /* only x25519 algorithm */
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_OidSignatureAlgorithmX448[TCPIP_TLS_OID_SIGNATURE_ALGORITHM_CURVE_25519_448_LEN] = { 0x2b, 0x65, 0x6f }; /* 1.3.101.111 */  /* only x448 algorithm */
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_OidPubKeyTypeEc[TCPIP_TLS_OID_PUBKEY_EC_LEN] = { 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x02, 0x01 }; /* 1.2.840.10045.2.1 */
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_OidPubKeyNamedCurveSecp256r1[TCPIP_TLS_OID_PUBKEY_NAMED_CURVE_SECP256R1_LEN] = { 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x03, 0x01, 0x07 }; /* 1.2.840.10045.3.1.7 */
TCPIP_LOCAL CONST(uint8, TCPIP_CONST) TcpIp_Tls_OidPubKeyNamedCurveSecp521r1[TCPIP_TLS_OID_PUBKEY_NAMED_CURVE_SECP521R1_LEN] = { 0x2b, 0x81, 0x04, 0x00, 0x23 }; /* 1.3.132.0.35 */
/* Further public key OIDs:  Ed25519 (1.3.101.112), Ex25519 (1.3.101.110) */
/* There is no named curve for ED25519 */

# endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

# define TCPIP_STOP_SEC_CONST_8
# include "TcpIp_MemMap.h"                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define TCPIP_START_SEC_CODE
# include "TcpIp_MemMap.h"                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  TLS CORE UPPER LAYER (UL)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsCoreUl_RxIndication
 *********************************************************************************************************************/
/*! \brief         Forward the UpperLayer RxIndication to TcpIp in case of pending application data for the user
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     DataPtr             Pointer to the data
 *  \param[in]     DataLenByte         Length of the data
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreUl_RxIndication(
  TcpIp_TlsConnectionIterType       TlsConIdx,
  TCPIP_P2V(uint8)                  DataPtr,
  uint32                            DataLenByte);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUl_CopyTxDataIndirect
 *********************************************************************************************************************/
/*! \brief        Calculate data offsets and forwards the user copyTxData indirect call to the internal function
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     SourceDataLen      Size of buffer requested
 *  \param[in]     SocketIdx          Index of a TCP socket
 *                                    \spec requires SocketIdx < TcpIp_GetSizeOfSocketDyn(); \endspec
 *  \return        E_OK               UpperLayer CopyTxDataIndirect successful
 *  \return        E_NOT_OK           UpperLayer CopyTxDataIndirect NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUl_CopyTxDataIndirect(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint32                      SourceDataLen,
  TcpIp_SizeOfSocketDynType   SocketIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUl_CopyTxDataDirect
 *********************************************************************************************************************/
/*! \brief         Calculate data offsets and forwards the user copyTxData direct call to the internal function
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     SourceDataPtr      Pointer of the source data.
 *  \param[in]     SourceDataLen      Length of the source data.
 *  \return        E_OK               UpperLayer CopyTxDataDirect successful
 *  \return        E_NOT_OK           UpperLayer CopyTxDataDirect NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreUl_CopyTxDataDirect(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(uint8) SourceDataPtr,
  CONST(uint32, AUTOMATIC) SourceDataLen);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUl_CopyTxDataIndirectWithWraparound
 *********************************************************************************************************************/
/*! \brief         Calls the configured UserCopyTxData function under consideration of TLS buffer wraparounds
 *  \details       -
 *  \param[in]     SocketTcpIdx       Index of a TCP socket
 *                                    \spec requires SocketTcpIdx < TcpIp_GetSizeOfSocketTcpDyn(); \endspec
 *  \param[in]     DstChunk1Ptr       Pointer to the first destination data.
 *                                    \spec requires $lengthOf(DstChunk1Ptr) >= *DstChunk1LenPtr; \endspec
 *  \param[in]     DstChunk1LenPtr    Length of the first destination data.
 *  \param[in]     DstChunk2Ptr       Pointer to the second destination data. NULL_PTR if not used
 *                                    \spec requires DstChunk2Ptr == NULL_PTR || $lengthOf(DstChunk2Ptr) >= *DstChunk2LenPtr; \endspec
 *  \param[in]     DstChunk2LenPtr    Length of the second destination data. 0 if not used
 *  \param[in]     UseTlsCopyTxData   If TRUE the TLS internal CopyTxData function is called, otherwise the UpperLayer
 *  \return        E_OK               UpperLayer CopyTxDataIndirect successful
 *  \return        E_NOT_OK           UpperLayer CopyTxDataIndirect NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUl_CopyTxDataIndirectWithWraparound(
  TcpIp_SizeOfSocketTcpDynType SocketTcpIdx,
  TCPIP_P2V(uint8)             DstChunk1Ptr,
  TCPIP_P2V(uint32)            DstChunk1LenPtr,
  TCPIP_P2V(uint8)             DstChunk2Ptr,
  TCPIP_P2V(uint32)            DstChunk2LenPtr,
  CONST(boolean, AUTOMATIC)    UseTlsCopyTxData);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUl_IncrementTlsBufferTxAdHsWriteIdxWithWraparound
 *********************************************************************************************************************/
/*! \brief         Increment the TlsBuffer TX write index by the given value under consideration of buffer wraparounds
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     Value              Length of the source data
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreUl_IncrementTlsBufferTxAdHsWriteIdxWithWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint32                      Value);

/**********************************************************************************************************************
 *  TLS CORE CHANGE PARAMETER
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreChangeParameter_ConnectionAssignment
 *********************************************************************************************************************/
/*! \brief         Allocate a TLS connection for the given socket
 *  \details       -
 *  \param[in]     SocketTcpIdx         Index of a TCP socket
 *                                      \spec requires SocketTcpIdx < TcpIp_GetSizeOfSocketTcpDyn(); \endspec
 *  \param[in]     TlsConIdxPtr         Option parameter
 *  \return        E_OK                 The request has been accepted.
 *  \return        E_NOT_OK             The request has not been accepted.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreChangeParameter_ConnectionAssignment(
  TcpIp_SizeOfSocketTcpDynType SocketTcpIdx,
  TCPIP_P2C(uint8)             TlsConIdxPtr);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreChangeParameter_SessionResumption
 *********************************************************************************************************************/
/*! \brief         Request usage of session resumption for the given sockets
 *  \details       -
 *  \param[in]     SocketTcpIdx                Index of a TCP socket that shall use session resumption
 *                                             \spec requires SocketTcpIdx < TcpIp_GetSizeOfSocketTcpDyn(); \endspec
 *  \param[in]     ResumptionBaseSocketIdPtr   Pointer to the ID of the resumption base socket
 *  \return        E_OK                        The request has been accepted.
 *  \return        E_NOT_OK                    The request has not been accepted.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreChangeParameter_SessionResumption(
  TcpIp_SizeOfSocketTcpDynType SocketTcpIdx,
  TCPIP_P2C(uint8)             ResumptionBaseSocketIdPtr);

/**********************************************************************************************************************
 *  TLS CORE CONTENT TYPE (CT)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsCoreCtHs_VerifyMsgCompleteness
 *********************************************************************************************************************/
/*! \brief         Peeks the length in the TLS handshake message and checks if the complete message is received
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     HsMsgLenPtr        Length of the TLS handshake message
 *  \return        E_OK               TLS message verified successful
 *  \return        E_NOT_OK           TLS message verified NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_VerifyMsgCompleteness(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint32) HsMsgLenPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtHs_ReadMsgLenFromHsMsg
 *********************************************************************************************************************/
/*! \brief         Reads out the length of the TLS handshake message
 *  \details       This function is only called when we ensure that we received the complete length information
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     HsMsgLenPtr        Length of the TLS handshake message
 *  \return        E_OK               Message length was read successfully
 *  \return        E_NOT_OK           Message length was not read because complete message not received
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_ReadMsgLenFromHsMsg(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint32) HsMsgLenPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtHs_ValidateAndForwardMessageToHsHandler
 *********************************************************************************************************************/
/*! \brief         Validates the received TLS handshake message and forwards it.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     HsMsgLen           Length of the TLS handshake message
 *  \return        E_OK               TLS message forwarded successful
 *  \return        E_NOT_OK           TLS message forwarded NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_ValidateAndForwardMessageToHsHandler(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint32, AUTOMATIC) HsMsgLen);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtHs_ValidateTypeField
 *********************************************************************************************************************/
/*! \brief         Validates the TLS handshake type field.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     HsMsgLen           Length of the TLS handshake message
 *  \param[out]    SkipThisMessagePtr Boolean which indicates if this message has already been processed in TcpIp_TlsCoreRl_ProcessHsFrame()
 *  \return        E_OK               TLS handshake message verified successful
 *  \return        E_NOT_OK           TLS handshake message verified NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_ValidateTypeField(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint32, AUTOMATIC) HsMsgLen,
  TCPIP_P2V(boolean) SkipThisMessagePtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivable
 *********************************************************************************************************************/
/*! \brief         Check if the current received TLS handshake message is receivable.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK               TLS handshake message verified successful
 *  \return        E_NOT_OK           TLS handshake message verified NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivable(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivableInThisConnection
 *********************************************************************************************************************/
/*! \brief         Check if the current received TLS handshake message is receivable with the configured connection.
 *  \details       It is checked whether the message fits to the TLS versions of the connection and the connection type
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK               TLS handshake message verified successful
 *  \return        E_NOT_OK           TLS handshake message verified NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivableInThisConnection(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivableInActiveTlsVersion
 *********************************************************************************************************************/
/*! \brief         Check if the current received TLS handshake message is receivable with the active TLS version.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK               TLS handshake message verified successful
 *  \return        E_NOT_OK           TLS handshake message verified NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivableInActiveTlsVersion(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivableInThisKeyExchange
 *********************************************************************************************************************/
/*! \brief         Check if the current received TLS handshake message is receivable in the current key exchange.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK               TLS handshake message verified successful or key exchange not known yet
 *  \return        E_NOT_OK           TLS handshake message verified NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivableInThisKeyExchange(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtHs_CheckForDuplicateMessages
 *********************************************************************************************************************/
/*! \brief         Validate the order of the current received TLS handshake message.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK               TLS handshake message verified successful
 *  \return        E_NOT_OK           TLS handshake message verified NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_CheckForDuplicateMessages(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedType
 *********************************************************************************************************************/
/*! \brief         Check if the read index of the received TLS handshake type is set to NO_VALUE
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK               TLS handshake message NOT duplicated
 *  \return        E_NOT_OK           TLS handshake message duplicated
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedType(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedTypeProtXx
 *********************************************************************************************************************/
/*! \brief         Validate the order of the received handshake messages while the protocol version is not yet set.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedTypeProtXx(
  TcpIp_TlsConnectionIterType TlsConIdx);

# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedTypeClient12
 *********************************************************************************************************************/
/*! \brief         Validate the order of the received handshake messages for the TLS 1.2 client.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedTypeClient12(
  TcpIp_TlsConnectionIterType TlsConIdx);
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
# endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */

# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedTypeServer12
 *********************************************************************************************************************/
/*! \brief         Validate the order of the received handshake messages for the TLS 1.2 server.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedTypeServer12(
  TcpIp_TlsConnectionIterType TlsConIdx);
# endif /* (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON) */

# if ((TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) && (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON))
/**********************************************************************************************************************
 * TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedTypeClient13
 *********************************************************************************************************************/
/*! \brief         Validate the order of the received handshake messages for the TLS 1.3 client.
 *  \details       -
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedTypeClient13(
  TcpIp_TlsConnectionIterType TlsConIdx);
# endif

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtHs_UpdateTypeInformation
 *********************************************************************************************************************/
/*! \brief         Update the Start index and length information of the received TLS handshake type
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     HsMsgLen           Length of the TLS handshake message
 *  \param[out]    SkipThisMessagePtr Boolean which indicates if this message has already been processed in TcpIp_TlsCoreRl_ProcessHsFrame()
 *  \return        E_OK               TLS Type information updated successful
 *  \return        E_NOT_OK           TLS Type information updated NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_UpdateTypeInformation(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint32, AUTOMATIC) HsMsgLen,
  TCPIP_P2V(boolean) SkipThisMessagePtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtHs_HandleInvalidHsMessage
 *********************************************************************************************************************/
/*! \brief         Store an user error and trigger an alert if an invalid TLS handshake message is received
 *  \details       This function is only called if an invalid TLS handshake message is received during the TLS handshake
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtHs_HandleInvalidHsMessage(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_RxIndication
 *********************************************************************************************************************/
/*! \brief         Indicates a reception of new TLS handshake message
 *  \details       This function is called by the TLS RX record layer functions
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtHs_RxIndication(
  TcpIp_TlsConnectionIterType TlsConIdx);

# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_AnalyzeSecpKeyComponente
 *********************************************************************************************************************/
/*! \brief         Analyze the secp signature component to prepare the BER encoding as integer value.
 *  \details       Check the number of leading zeros that have to be removed from the plain component, or if a leading
 *                 zero has to be added. Calculate the length of the BER INTEGER encoded signature component value.
 *  \param[in]     KeyPtr                          Pointer to the plain key component
 *  \param[in,out] SignCoordinateDescriptorPtr     Pointer to the descriptor with all necessary information
 *  \pre           The descriptor struct element CoordinateByteLen is set correctly
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtHs_AnalyzeSecpKeyComponente(
  TCPIP_P2C(uint8) KeyPtr,
  TCPIP_P2V(TcpIp_TlsSecpSignCoordinateDescriptorType) SignCoordinateDescriptorPtr);
# endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TLS CORE CHANGE CIPHER SPEC
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsCoreCtCcs_CheckReceivedCcsData
 *********************************************************************************************************************/
/*! \brief         Checks if the received CCS data has a valid format
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK               ChangeCipherSpec message verified successful
 *  \return        E_NOT_OK           ChangeCipherSpec message verified NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtCcs_CheckReceivedCcsData(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtCcs_ForwardFrameToCCsHandler
 *********************************************************************************************************************/
/*! \brief         Forwards the received TLS CCS message
 *  \details       Checks if the received TLS CCS message is allowed and forwards it
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK               ChangeCipherSpec message verified successful
 *  \return        E_NOT_OK           ChangeCipherSpec message verified NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtCcs_ForwardFrameToCCsHandler(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtCcs_HandleInvalidCcsMessage
 *********************************************************************************************************************/
/*! \brief         Store an user error and trigger an alert if an invalid TLS CCS message is received
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtCcs_HandleInvalidCcsMessage(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TLS CORE CT APPLICATION DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtAd_RxIndication
 *********************************************************************************************************************/
/*! \brief         Indicates an reception of new TLS application
 *  \details       This function is called by the TLS RX application data function
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtAd_RxIndication(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtAd_ForwardDataToAdHandler
 *********************************************************************************************************************/
/*! \brief         Checks the receive buffer and forward the TLS application data
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK               Application data forwarded successful
 *  \return        E_NOT_OK           Application data forwarded NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtAd_ForwardDataToAdHandler(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TLS CORE CT ALERT
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsCoreCtAl_ForwardAlertToTxBuffer
 *********************************************************************************************************************/
/*! \brief         Forwards the received alert to the TLS TX buffer
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     AlertLevel         TLS alert level
 *  \param[in]     AlertDescription   TLS alert description
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtAl_ForwardAlertToTxBuffer(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TcpIp_TlsAlertLevelType       AlertLevel,
  TcpIp_TlsAlertDescriptionType AlertDescription);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtAl_TxAlert
 *********************************************************************************************************************/
/*! \brief         Checks if new TLS alerts are stored in the TLS Tx buffer and forward them to the TLS record layer
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtAl_TxAlert(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtAl_ShallConnectionBeClosedIfTxAlert
 *********************************************************************************************************************/
/*! \brief         Checks if the connection shall be closed after transmitting an alert
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     AlertLevel         Alert level of the transmitted alert
 *  \param[in]     AlertDescription   Alert description of the transmitted alert
 *  \return        TRUE               Connection shall be closed
 *  \return        FALSE              Connection shall not be closed yet
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(boolean, TCPIP_CODE) TcpIp_TlsCoreCtAl_ShallConnectionBeClosedIfTxAlert(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TcpIp_TlsAlertLevelType       AlertLevel,
  TcpIp_TlsAlertDescriptionType AlertDescription);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtAl_SetTlsConnectionStateAfterClosingSocket
 *********************************************************************************************************************/
/*! \brief         Sets the TLS connection state after the TCP socket was closed
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtAl_SetTlsConnectionStateAfterClosingSocket(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtAl_RxIndication
 *********************************************************************************************************************/
/*! \brief         Indicates an reception of new TLS alert
 *  \details       This function is called by the TLS RX alert function
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtAl_RxIndication(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtAl_CheckLengthAndForwardAlertToAlHandler
 *********************************************************************************************************************/
/*! \brief         Checks for new received TLS alerts, check their lengths and forward them.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK               Alert forwarded successful
 *  \return        E_NOT_OK           Alert forwarded NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtAl_CheckLengthAndForwardAlertToAlHandler(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtAl_ParseReceivedAlertTlsVersionDependent
 *********************************************************************************************************************/
/*! \brief         Trigger parsing of new received TLS alerts dependent on the active TLS version
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtAl_ParseReceivedAlertTlsVersionDependent(
  TcpIp_TlsConnectionIterType TlsConIdx);

# if ((TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) && (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON))
/**********************************************************************************************************************
 * TcpIp_TlsCoreCtAl_GetTlsVersionOfParserForReceivedAlert
 *********************************************************************************************************************/
/*! \brief         Get the TLS version of the parser which should be used for the received alert message
 *  \details       Calling this function does only make sense if the active version for the connection is not set yet
 *  \param[in]     TlsConIdx                TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        TCPIP_TLSVERSION_NOTSET  The version of the parser can't be determined conclusively
 *  \return        TCPIP_TLSVERSION_12      The parser for TLS version 1.2 shall be used
 *  \return        TCPIP_TLSVERSION_13      The parser for TLS version 1.3 shall be used
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(TcpIp_TlsVersionType, TCPIP_CODE) TcpIp_TlsCoreCtAl_GetTlsVersionOfParserForReceivedAlert(
  TcpIp_TlsConnectionIterType TlsConIdx);
# endif

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsCore12CtAl_ParseReceivedAlert
 *********************************************************************************************************************/
/*! \brief         Parse new received TLS alerts when active version is TLS 1.2
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCore12CtAl_ParseReceivedAlert(
  TcpIp_TlsConnectionIterType TlsConIdx);
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsCore13CtAl_ParseReceivedAlert
 *********************************************************************************************************************/
/*! \brief         Parse new received TLS alerts when active version is TLS 1.3
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCore13CtAl_ParseReceivedAlert(
  TcpIp_TlsConnectionIterType TlsConIdx);
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtAl_AlertParsingPostProcessing
 *********************************************************************************************************************/
/*! \brief         Process alert message after it has been parsed and handled
 *  \details       Trigger TLS error indication with received alert description and reset Rx Al buffer write index
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     AlertDescription   Received AlertDescription
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtAl_AlertParsingPostProcessing(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8                       AlertDescription);

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsCoreCtAl_CheckAlert
 *********************************************************************************************************************/
/*! \brief         Check the validity of the received Alert level and Alert description
 *  \details       -
 *  \param[in]     AlertLevel            AlertLevel which should be validated
 *  \param[in]     AlertDescription      AlertDescription which should be validated
 *  \return        E_OK                  If both parameter are valid
 *  \return        E_NOT_OK              If AlertLevel or AlertDescription is invalid
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtAl_CheckAlert(
  TcpIp_TlsAlertLevelType AlertLevel,
  TcpIp_TlsAlertDescriptionType AlertDescription);
# endif

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtAl_HandleAllOtherAlerts
 *********************************************************************************************************************/
/*! \brief         Generic TLS alert handler for received TLS alerts
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtAl_HandleAllOtherAlerts(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreCtAl_HandleCloseNotifyAlert
 *********************************************************************************************************************/
/*! \brief         TLS alert handler for CloseNotify alert
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtAl_HandleCloseNotifyAlert(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TLS CORE RECORD LAYER (RL)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_RxIndication
 *********************************************************************************************************************/
/*! \brief         Indicates the reception of new TLS record layer frames.
 *  \details       This function is called by the TLS RX record layer function
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_RxIndication(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_TxConfirmation
 *********************************************************************************************************************/
/*! \brief         Forward the outstanding TxConfirmations to the UpperLayer
 *  \details       This function checks the number of bytes which have to be confirmed to the upper layer
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_TxConfirmation(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_IncrementTlsBufferTxAdHsReadIdxWithWraparound
 *********************************************************************************************************************/
/*! \brief         Increment the AD/HS Tx Buffer
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     Value              Length which should be incremented
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_IncrementTlsBufferTxAdHsReadIdxWithWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SizeOfTlsBufferTxType Value);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_TransmitFrame
 *********************************************************************************************************************/
/*! \brief         Transform a TLS content type (HS,AD,AL) into a TLS record layer frame and forwards to TcpIp
 *  \details       -
 *  \param[in]     TlsConIdx             TLS connection index
 *                                       \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentTypeTxStartIdx Start index of this frame
 *  \param[in]     PlaintextTxLen        Plain text length of this frame
 *  \param[in]     ContentType           ContentType of this frame
 *  \return        E_OK                  Transmit operation successful
 *  \return        E_NOT_OK              Transmit operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_TransmitFrame(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferTxIterType ContentTypeTxStartIdx,
  TcpIp_SizeOfTlsBufferTxType PlaintextTxLen,
  CONST(uint8, AUTOMATIC)     ContentType);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_FragmentFrameAndTransmit
 *********************************************************************************************************************/
/*! \brief         If the given TLS content type has to be fragmented, forwards the parts to the
 *                 TcpIp_TlsCoreRl_TransmitFrame function.
 *  \details       -
 *  \param[in]     TlsConIdx      TLS connection index
 *                                \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     TxStartIdx     Start index of the content in Tls buffer
 *  \param[in]     TxLen          Length of this content
 *  \param[in]     ContentType    ContentType (AD, HS)
 *  \return        E_OK           Transmit operation successful
 *  \return        E_NOT_OK       Transmit operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_FragmentFrameAndTransmit(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferTxIterType TxStartIdx,
  TcpIp_SizeOfTlsBufferTxType TxLen,
  CONST(uint8, AUTOMATIC) ContentType);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_CheckTcpBuffer
 *********************************************************************************************************************/
/*! \brief         Check if there is enough space in the Tcp buffer
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     CipherTextTxLen    Length of the TLS Tx frame (excluding header length)
 *  \return        E_OK               Enough space available in Tcp buffer
 *  \return        E_NOT_OK           NOT enough space available in Tcp buffer
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_CheckTcpBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint32                      CipherTextTxLen);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_TransmitFrameHdr
 *********************************************************************************************************************/
/*! \brief         Transmit the TLS record layer header (5Bytes)
 *  \details       This function calls TcpIp_TcpTransmitInternal via direct data provision
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK               Transmit operation successful
 *  \return        E_NOT_OK           Transmit operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_TransmitFrameHdr(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_TransmitFrameCiphertext
 *********************************************************************************************************************/
/*! \brief         Trigger TCP transmission of the data in the TLS TX buffer
 *  \details       This function calls TcpIp_TcpTransmitInternal via indirect data provision
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK               Transmit operation successful
 *  \return        E_NOT_OK           Transmit operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_TransmitFrameCiphertext(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_CalcContentTypeLenCipherDependent
 *********************************************************************************************************************/
/*! \brief         Calculates the length of TLS contentType under consideration of the selected cipher suite
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentTypeLen     Length of the contentType data without respecting the selected cipher
 *  \param[in]     Cipher             IANA Id of the selected ciphersuite
 *  \return        Calculated TLS ContentType length depending on the selected cipher
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(uint32, TCPIP_CODE) TcpIp_TlsCoreRl_CalcContentTypeLenCipherDependent(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint32, AUTOMATIC)    ContentTypeLen,
  TcpIp_TlsCipherDataType     Cipher);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_CalcHmacCipherDependent
 *********************************************************************************************************************/
/*! \brief         Perform the cipher dependent authentication (if any)
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     TcpBufLength       TCP buffer length
 *  \return        E_OK               HMAC Operation successful
 *  \return        E_NOT_OK           HMAC Operation NOT successful
 *  \pre           Tcp content data is present in the Tls Tx buffer
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_CalcHmacCipherDependent(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 TcpBufLength);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_Init
 *********************************************************************************************************************/
/*! \brief         Initialize the TLS record layer
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_Init(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_EncryptCipherDependent
 *********************************************************************************************************************/
/*! \brief         Perform the cipher dependent encryption (if any)
 *  \details       -
 *  \param[in]     TlsConIdx            TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[out]    BufPtr               TcpIp Tx buffer
 *  \param[in]     BufLength            TcpIp Tx buffer size
 *  \return        BUFREQ_OK            Buffer request accomplished successful
 *  \return        BUFREQ_E_NOT_OK      Buffer request not successful. Buffer cannot be accessed
 *  \return        BUFREQ_E_BUSY        Temporarily no buffer available. It's up the requestor to retry request
 *                                      for a certain time
 *  \return        BUFREQ_E_OVFL        No Buffer of the required length can be provided.
 *  \pre           Tcp content data is present in the Tls Tx buffer
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
  *********************************************************************************************************************/
TCPIP_LOCAL FUNC(BufReq_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_EncryptCipherDependent(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint8)            BufPtr,
  uint16                      BufLength);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_ValidateAndProcessFrame
 *********************************************************************************************************************/
/*! \brief         Validates FrameHdr + Frame and triggers further processing
 *  \details       -
 *  \param[in]     TlsConIdx             TLS connection index
 *                                       \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     TotDataLen            Total data length
 *  \return        E_OK                  Validation successful
 *  \return        E_NOT_OK              Validation NOT successful - alert was already triggered
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_ValidateAndProcessFrame(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint32 totDataLen);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_ValidateFrameHdr
 *********************************************************************************************************************/
/*! \brief         Verify that the received TLS record layer header is correct
 *  \details       -
 *  \param[in]     TlsConIdx             TLS connection index
 *                                       \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     TotDataLen            Total data length
 *  \param[in,out] RlHdrPtr              Pointer to the RL header of the TLS record layer frame
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_ValidateFrameHdr(
  TcpIp_TlsConnectionIterType              TlsConIdx,
  CONST(uint32, AUTOMATIC)                 TotDataLen,
  TCPIP_P2V(uint8)                         RlHdrPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_ValidateRlFragmentLength
 *********************************************************************************************************************/
/*! \brief         Verify that the received RL frame is within correct fragment length
 *  \details       -
 *  \param[in]     TlsConIdx             TLS connection index
 *                                       \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     RlHdrPtr              Pointer to the RL header of the TLS record layer frame
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_ValidateRlFragmentLength(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(uint8) RlHdrPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_ValidateFrameAndTriggerContentSpecificProcess
 *********************************************************************************************************************/
/*! \brief         Check the received frame for completeness and forward it to the upper layer
 *  \details       -
 *  \param[in]     TlsConIdx             TLS connection index
 *                                       \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in] TotDataLen                Total data length
 *  \param[in,out] RlHdrPtr              Pointer to the RL header of the TLS record layer frame
 *  \return        E_OK                  RL frame is validated and content specific processes are triggered
 *  \return        E_NOT_OK              RL frame is not valid
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_ValidateFrameAndTriggerContentSpecificProcess(
  TcpIp_TlsConnectionIterType              TlsConIdx,
  uint32                                   TotDataLen,
  TCPIP_P2C(uint8)                         RlHdrPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_VerifyFrameCompleteness
 *********************************************************************************************************************/
/*! \brief         Verify that the received TLS record layer frame is complete
 *  \details       -
 *  \param[in] TotDataLen                Total data length
 *  \param[in,out] RlHdrPtr              Pointer to the RL header of the TLS record layer frame
 *  \param[in,out] RlHdrLenPtr           Pointer to the length information stored inside of the RL frame header
 *  \return        E_OK                  Operation successful
 *  \return        E_NOT_OK              Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_VerifyFrameCompleteness(
  uint32 TotDataLen,
  TCPIP_P2C(uint8) RlHdrPtr,
  TCPIP_P2V(uint16) RlHdrLenPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_CheckIfFrameIsReceivable
 *********************************************************************************************************************/
/*! \brief         Checks if the TLS stack is in the correct state to process the received TLS frame
 *  \details       -
 *  \param[in]     TlsConIdx             TLS connection index
 *                                       \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] RlHdrPtr              Pointer to the RL header of the TLS record layer frame
 *  \return        E_OK                  if the frame is receivable
 *  \return        E_NOT_OK              if the frame is NOT receivable
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_CheckIfFrameIsReceivable(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(uint8) RlHdrPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_DecryptAndTriggerContentSpecificProcess
 *********************************************************************************************************************/
/*! \brief         Decrypt the received TLS record layer frame and triggers content type specific processing (AD,HS,AL)
 *  \details       -
 *  \param[in]     TlsConIdx             TLS connection index
 *                                       \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] RlHdrPtr              Pointer to the RL header of the TLS record layer frame
 *  \param[in]     RlFrameLen            Length of the TLS record layer frame
 *  \return        E_OK                  Operation successful
 *  \return        E_NOT_OK              Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_DecryptAndTriggerContentSpecificProcess(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(uint8) RlHdrPtr,
  CONST(uint16, AUTOMATIC) RlFrameLen);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_HandleFrameAndTriggerContentSpecificProcess
 *********************************************************************************************************************/
/*! \brief         Executes post decryption handling and triggers further processing depending on content type
 *  \details       -
 *  \param[in]     TlsConIdx             TLS connection index
 *                                       \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ReceivedFrameLength   Length of the received TLS record layer frame, including RL header.
 *  \param[in]     ContentType           TLS Content Type of the received TLS record layer frame
 *  \return        E_OK                  Operation successful
 *  \return        E_NOT_OK              Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_HandleFrameAndTriggerContentSpecificProcess(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint32, AUTOMATIC)    ReceivedFrameLength,
  CONST(uint8, AUTOMATIC)     ContentType);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_ScanForHsTypesAndTriggerHsMsgProcess
 *********************************************************************************************************************/
/*! \brief         Scans for all HS messages in current RL frame. TLS 1.3 Hs messages received
 *                 after the handshake is complete, are processed and removed from the Rx buffer
 *                 to not interfere with received application data. Hs messages received during the handshake
 *                 and TLS 1.2 Hs messages are processed later in the handshake context.
 *  \details       Also checks if any HS messages which precede a key change are contained and checks if they are
 *                 completely received or only partially.
 *                 This function is able to handle wraparounds at any point in a received frame.
 *  \param[in]     TlsConIdx             TLS connection index
 *                                       \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     PlaintextLen          The length of the plaintext in the current RL frame
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_ScanForHsTypesAndTriggerHsMsgProcess(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint32, AUTOMATIC)    PlaintextLen);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_ProcessCompleteHsMessage
 *********************************************************************************************************************/
/*! \brief         Processes a complete handshake message without the handshake header. The read information in the
 *                 header must be passed as input to this function.
 *  \details       Skip over the handshake data to parse it in the Hs context,
 *                 except for TLS 1.3 Hs messages after the handshake is completed which are parsed here.
 *                 If this results in the whole RL frame being parsed, it is removed from the Rx AdHs buffer.
 *                 Generally, if not the whole RL frame is parsed yet, CurrAdHsBufferIdxPtr is updated to point
 *                 to the next Hs header of the RL frame in the buffer. For 1.3 it is also checked that the parsed Hs
 *                 message is not a message preceding a key change which results in a fatal alert.
 *  \param[in]     TlsConIdx                TLS connection index
 *                                          \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]      HsType                  Received handshake type
 *  \param[in]      HsLen                   Received handshake length
 *  \param[in]      SourceSegment1Ptr       Pointer to a buffer segment containing the first part of the Hs message
 *  \param[in]      SourceSegment2Ptr       Pointer to a buffer segment containing the second part of the Hs message
 *                                          It is already checked that both segments together contain HsLen bytes
 *  \param[in,out] CurrAdHsBufferIdxPtr     Pointer to the current processing index in the Rx AdHs buffer
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_ProcessCompleteHsMessage(
  TcpIp_TlsConnectionIterType                 TlsConIdx,
  uint8                                       HsType,
  uint32                                      HsLen,
  TcpIp_ConstSegmentPtrType                   SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                   SourceSegment2Ptr,
  TCPIP_P2V(uint32)                           CurrAdHsBufferIdxPtr);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_ProcessHsFrame
 *********************************************************************************************************************/
/*! \brief          Some handshake messages need to be processed already before the Hs context. This is done here.
 *  \details        -
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]      HsType                  Received handshake type
 *  \param[in]      HsLen                   Received handshake length
 *  \param[in]      SourceSegment1Ptr       Pointer to a buffer segment containing the first part of the Hs message
 *  \param[in]      SourceSegment2Ptr       Pointer to a buffer segment containing the second part of the Hs message
 *                                          It is already checked that both segments together contain HsLen bytes
 *  \return         E_OK                    Message successfully processed
 *  \return         E_NOT_OK                Processing of message failed
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_ProcessHsFrame(
  TcpIp_TlsConnectionIterType                 TlsConIdx,
  uint8                                       HsType,
  uint32                                      HsLen,
  TcpIp_ConstSegmentPtrType                   SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                   SourceSegment2Ptr);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_RemoveDataFromAdHsRxBuffer
 *********************************************************************************************************************/
/*! \brief          Remove (decrypted) data from the AdHs Buffer.
 *  \details        -
 *  \param[in]      TlsConIdx               TLS connection index
 *                                          CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]      PlaintextLen            Plaintext length which shall be removed
 *  \return         E_OK                    Removing succeeded
 *  \return         E_NOT_OK                Removing failed
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_RemoveDataFromAdHsRxBuffer(
  TcpIp_TlsConnectionIterType                 TlsConIdx,
  uint32                                      PlaintextLen);

/**********************************************************************************************************************
 * TcpIp_TlsCore_ExtractHsHeaderInformationFromMultiConstSegment
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCore_ExtractHsHeaderInformationFromMultiConstSegment(
  TcpIp_ConstSegmentPtrType                   SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                   SourceSegment2Ptr,
  TCPIP_P2V(uint8)                            HsTypePtr,
  TCPIP_P2V(uint32)                           HsLenPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_SetParametersForReceivedFrame
 *********************************************************************************************************************/
/*! \brief         Sets various parameters after complete Rl frame was received
 *  \details       -
 *  \param[in]     TlsConIdx             TLS connection index
 *                                       \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ReceivedFrameLength   Length of the received TLS record layer frame, including RL header.
 *  \param[in]     PlaintextLen          Plaintext length of the received record
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_SetParametersForReceivedFrame(
  TcpIp_TlsConnectionIterType                                 TlsConIdx,
  CONST(uint32, AUTOMATIC)                                    ReceivedFrameLength,
  CONST(TcpIp_RlRxCopiedLenOfTlsBufferMgmtDynType, AUTOMATIC) PlaintextLen);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_ParseAndValidateRlHdr
 *********************************************************************************************************************/
/*! \brief         Check the correctness of TLS record layer frame header fields
 *  \details       -
 *  \param[in]     TlsConIdx             TLS connection index
 *                                       \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] RlHdrPtr              Pointer to the RL header of the TLS record layer frame
 *  \param[in]     RlHdrLen              Length of the TLS record layer frame
 *  \return        E_OK                  Operation successful
 *  \return        E_NOT_OK              Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_ParseAndValidateRlHdr(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(uint8) RlHdrPtr,
  CONST(uint8, AUTOMATIC) RlHdrLen);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_DecryptAndAuthenticate
 *********************************************************************************************************************/
/*! \brief         Forward the encrypted TLS record layer frame to decrypt and authentication functions
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     RlFrameLen         Length of the TLS record layer frame
 *  \param[in]     ContentType        TLS ContentType of this frame
 *  \return        E_OK               Operation successful
 *  \return        E_NOT_OK           Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_DecryptAndAuthenticate(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint16, AUTOMATIC) RlFrameLen,
  CONST(uint8, AUTOMATIC) ContentType);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_SetRlFrameStartIdx
 *********************************************************************************************************************/
/*! \brief         Set the Rx Rl Frame start index depending on the content type
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType        TLS ContentType of this frame
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_SetRlFrameStartIdx(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC) ContentType);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_DecryptAndAuthenticateCheckFrame
 *********************************************************************************************************************/
/*! \brief         Executes some checks and forwards the encrypted TLS record layer frame
 *                 to the cipher dependent decrypt and authentication functions
 *  \details       Forward one TCP segment which contains the received encrypted TLS record layer frame
 *                 to the cipher dependent decrypt and authentication functions. This function may be called
 *                 twice for AdHs.
 *  \param[in]     TlsConIdx              TLS connection index
 *                                        \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType            TLS ContentType of this frame
 *  \param[in]     DataPtr                TCP buffer segment which contains the TLS Rl frame
 *  \param[in]     DataLen                Data length of TCP buffer segment
 *  \param[in]     CompleteRlFrameFlag    TRUE  A complete TLS Rl frame is available, Decryption is done.
 *                                        FALSE Only a partial TLS Rl frame is available. Decryption is not done.
 *  \return        E_OK                   Operation successful
 *  \return        E_NOT_OK               Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_DecryptAndAuthenticateCheckFrame(
  TcpIp_TlsConnectionIterType              TlsConIdx,
  CONST(uint8, AUTOMATIC)                  ContentType,
  TCPIP_P2V(uint8)                         DataPtr,
  uint16                                   DataLen,
  boolean                                  CompleteRlFrameFlag);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_DecryptAndAuthenticateFrameViaStreamingMode
 *********************************************************************************************************************/
/*! \brief         Forward the provided TCP buffer segment with data to decrypt to a specific decryption method
 *  \details       -
 *  \param[in]     TlsConIdx            TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType          TLS ContentType of the frame to be decrypted
 *  \param[in]     DataPtr              TCP buffer segment which contains part of or complete TLS Rl frame
 *  \param[in]     DataLen              Data length of TCP buffer segment
 *  \return        E_OK                 Operation successful
 *  \return        E_NOT_OK             Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_DecryptAndAuthenticateFrameViaStreamingMode(
  TcpIp_TlsConnectionIterType              TlsConIdx,
  CONST(uint8, AUTOMATIC)                  ContentType,
  TCPIP_P2C(uint8)                         DataPtr,
  uint16                                   DataLen);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_RxCipherCheckPlaintextRlSizeLimit
 *********************************************************************************************************************/
/*! \brief         Compare the plaintext data length after the CSM decryption with the negotiated RSL
 *  \details       -
 *  \param[in]     TlsConIdx             TLS connection index
 *                                       CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \return        E_OK                  Decrypted plaintext data length match with RSL
 *  \return        E_NOT_OK              Decrypted plaintext data length does NOT match with RSL
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_RxCipherCheckPlaintextRlSizeLimit(
  TcpIp_TlsConnectionIterType  TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_HandleInvalidRlFrame
 *********************************************************************************************************************/
/*! \brief         Store user error and trigger alert in case of invalid TLS record layer frame
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     RlFrameLen         Length of the TLS record layer frame
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_HandleInvalidRlFrame(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint16, AUTOMATIC) RlFrameLen);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_DecryptAndAuthenticateFrameViaNull
 *********************************************************************************************************************/
/*! \brief         Decrypt TLS data using Null streaming mode
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType        TLS ContentType of this frame
 *  \param[in]     DataPtr            Source data pointer
 *  \param[in]     DataLen            Source data length
 *  \return        E_OK               Operation successful
 *  \return        E_NOT_OK           Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_DecryptAndAuthenticateFrameViaNull(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC)     ContentType,
  TCPIP_P2C(uint8)            DataPtr,
  uint16                      DataLen);

/**********************************************************************************************************************
* TcpIp_TlsCoreRl_DecryptAndAuthenticateFrameViaAead
 *********************************************************************************************************************/
/*! \brief         Decrypt TLS data using Aead streaming mode
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType        TLS ContentType of this frame
 *  \param[in]     DataPtr            Source data pointer
 *  \param[in]     DataLen            Source data length
 *  \return        E_OK               Operation successful
 *  \return        E_NOT_OK           Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE)  TcpIp_TlsCoreRl_DecryptAndAuthenticateFrameViaAead(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8                       ContentType,
  TCPIP_P2C(uint8)            DataPtr,
  uint16                      DataLen);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_ExtractAuthTagFromReceivedRlFrame
 *********************************************************************************************************************/
/*! \brief         Extract the authentication tag from the received record layer frame
 *  \details       Authentication tag is copied to the provided buffer segment
 *  \param[in]     TcpSeg1Ptr         Pointer to TCP buffer segment 1
 *  \param[in]     TcpSeg2Ptr         Pointer to TCP buffer segment 2
 *  \param[in,out] AuthTagSegPtr      Pointer to the buffer segment where the authentication tag is copied to
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE)  TcpIp_TlsCoreRl_ExtractAuthTagFromReceivedRlFrame(
  TCPIP_P2V(TcpIp_ConstSegmentType)      TcpSeg1Ptr,
  TCPIP_P2V(TcpIp_ConstSegmentType)      TcpSeg2Ptr,
  TcpIp_SegmentPtrType                   AuthTagSegPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_RlFrameFitsInTlsRxBuffer
 *********************************************************************************************************************/
/*! \brief         Check if Rl frame fits into Tls Rx buffer
 *  \details       -
 *  \param[in]     TlsConIdx         TLS connection index
 *                                   \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType       Type of Rl content
 *  \param[in]     RlFrameLen        Length of the Rl frame
 *  \return        TRUE              Rl frame fits in the Tls Rx buffer
 *  \return        FALSE             Rl frame does not fit in the Tls Rx buffer
 *  \pre           -
 *  \context       TASKTASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsCoreRl_RlFrameFitsInTlsRxBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8                       ContentType,
  uint16                      RlFrameLen);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128
 *********************************************************************************************************************/
/*! \brief         Block128 encryption and authentication
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] Seg1Ptr            The optional stored buffer
 *  \param[in,out] Seg2Ptr            The received data
 *  \return        BUFREQ_OK          Buffer request accomplished successful
 *  \return        BUFREQ_E_NOT_OK    Buffer request not successful. Buffer cannot be accessed
 *  \return        BUFREQ_E_BUSY      Temporarily no buffer available. It's up the requestor to retry request for
 *                                    a certain time
 *  \return        BUFREQ_E_OVFL      No Buffer of the required length can be provided
 *  \pre           Tcp content data is present in the Tls Tx buffer
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(BufReq_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        Seg1Ptr,
  TcpIp_SegmentPtrType        Seg2Ptr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_TxCipherEncryptNull
 *********************************************************************************************************************/
/*! \brief         Null encryption
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] Seg1Ptr             The optional stored buffer
 *  \param[in,out] Seg2Ptr             The received data
 *  \return        BUFREQ_OK           Buffer request accomplished successful
 *  \return        BUFREQ_E_NOT_OK     Buffer request not successful. Buffer cannot be accessed
 *  \return        BUFREQ_E_BUSY       Temporarily no buffer available. It's up the requestor to retry request for
 *                                     a certain time
 *  \return        BUFREQ_E_OVFL       No Buffer of the required length can be provided
 *  \pre           Tcp content data is present in the Tls Tx buffer
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(BufReq_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_TxCipherEncryptNull(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        Seg1Ptr,
  TcpIp_SegmentPtrType        Seg2Ptr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_TxCipherEncryptNullStreamingMode
 *********************************************************************************************************************/
/*! \brief         Null encryption streaming mode
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] Seg1Ptr             The optional stored buffer
 *  \param[in,out] Seg2Ptr             The received data
 *  \pre           Tcp content data is present in the Tls Tx buffer
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_TxCipherEncryptNullStreamingMode(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        Seg1Ptr,
  TcpIp_SegmentPtrType        Seg2Ptr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_CopyHmacToTxBuffer
 *********************************************************************************************************************/
/*! \brief         Copy the Mac into the TcpIp
 *  \details       -
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] Seg1                 Pointer to TcpIp Tx buffer segment 1
 *  \param[in,out] Seg2                 Pointer to TcpIp Tx buffer segment 2
 *  \pre           Mac is present in the Tls temp buffer
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_CopyHmacToTxBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        Seg1,
  TcpIp_SegmentPtrType        Seg2);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128StreamingMode
 *********************************************************************************************************************/
/*! \brief         Handles AesCbc128 encryption of content data
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] Seg1Ptr            The optional stored buffer
 *  \param[in,out] Seg2Ptr            The received data
 *  \return        E_OK               Operation successful
 *  \return        E_NOT_OK           Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128StreamingMode(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        Seg1Ptr,
  TcpIp_SegmentPtrType        Seg2Ptr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128WithTcpWraparound
 *********************************************************************************************************************/
/*! \brief         AEADBlock128 encryption of content data with TCP buffer wraparound
 *  \details       Handles AEADBlock128 encryption of content data when there is TCP buffer wraparound
 *  \param[in]     TlsConIdx        TLS connection index
 *                                  \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] TcpIpSeg1        Pointer to TcpIp first segment buffer
 *  \param[in,out] TcpIpSeg2        Pointer to TcpIp second segment buffer
 *  \return        E_OK             Operation successful
 *  \return        E_NOT_OK         Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128WithTcpWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        TcpIpSeg1,
  TcpIp_SegmentPtrType        TcpIpSeg2);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128WithSingleCall
 *********************************************************************************************************************/
/*! \brief         AEADBlock128 encryption with NO TcpIp wraparound
 *  \details       Performs AEADBlock128 encryption and authentication of content data
 *                 when there is no TcpIp buffer wraparound
 *  \param[in]     TlsConIdx   TLS connection index
 *                             \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] TcpSeg      Pointer to TcpIp buffer segment
 *  \return        E_OK        Operation successful
 *  \return        E_NOT_OK    Operation NOT successful
 *  \pre           Content data is available in Tls Tx buffer
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128WithSingleCall(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        TcpSeg);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_EncryptAEADBlock128ContentDataWoWraparound
 *********************************************************************************************************************/
/*! \brief         AEADBlock128 encryption of content with linear TcpIp buffer (NO wraparound)
 *  \details       This function handles AEADBlock128 encryption of the Rl content data
 *                 when the TcpIp buffer is linear
 *  \param[in]     TlsConIdx              TLS connection index
 *                                        \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] BufSeg                 Pointer to TcpIp buffer segment
 *  \param[in,out] AuthTagSeg             Pointer to authentication tag buffer segment
 *  \return        E_OK                   Operation successful
 *  \return        E_NOT_OK               Operation NOT successful
 *  \pre           Content data is available in Tls Tx buffer
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_EncryptAEADBlock128ContentDataWoWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        BufSeg,
  TcpIp_SegmentPtrType        AuthTagSeg);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_EncryptAEADBlock128ContentDataWithTcpWraparound
 *********************************************************************************************************************/
/*! \brief          AEADBlock128 encryption of content with TcpIp wraparound
 *  \details        This function handles AEADBlock128 encryption of the Rl content data
 *                  when the TcpIp buffer wraps around
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out]  TcpIpSeg1           Pointer to TcpIp first segment buffer
 *  \param[in,out]  TcpIpSeg2           Pointer to TcpIp second segment buffer
 *  \param[in,out]  AuthTagSeg          Pointer to the authentication tag buffer segment
 *  \return         E_OK                Operation successful
 *  \return         E_NOT_OK            Operation NOT successful
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_EncryptAEADBlock128ContentDataWithTcpWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        TcpIpSeg1,
  TcpIp_SegmentPtrType        TcpIpSeg2,
  TcpIp_SegmentPtrType        AuthTagSeg);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_EncryptAEADBlock128AdHsWithTcpWraparound
 *********************************************************************************************************************/
/*! \brief          AEADBlock128 encryption of AdHs with TCP wraparound
 *  \details        This function handles AEADBlock128 encryption of the Rl AdHs data
 *                  when the TcpIp buffer wraps around
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out]  TcpIpSeg1           Pointer to TcpIp first segment buffer
 *  \param[in,out]  TcpIpSeg2           Pointer to TcpIp second segment buffer
 *  \param[in,out]  AuthTagSeg          Pointer to the authentication tag buffer segment
 *  \return         E_OK                Operation successful
 *  \return         E_NOT_OK            Operation NOT successful
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_EncryptAEADBlock128AdHsWithTcpWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        TcpIpSeg1,
  TcpIp_SegmentPtrType        TcpIpSeg2,
  TcpIp_SegmentPtrType        AuthTagSeg);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_EncryptAEADBlock128AdHs
 *********************************************************************************************************************/
/*! \brief          AEADBlock128 encryption of the AdHs content data
 *  \details        Performs AEADBlock128 encryption of AdHs content data
 *                  in the Tls buffer into a linear TcpIp buffer
 *  \param[in]      TlsConIdx              TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out]  BufSeg                 Pointer to TcpIp linear buffer segment (at least size of content data)
 *  \param[in,out]  AuthTagSeg             Pointer to the authentication tag buffer segment
 *  \return         E_OK                   Operation successful
 *  \return         E_NOT_OK               Operation NOT successful
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_EncryptAEADBlock128AdHs(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        BufSeg,
  TcpIp_SegmentPtrType        AuthTagSeg);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_EncryptAEADBlock128Al
 *********************************************************************************************************************/
/*! \brief          AEADBlock128 encryption of the Alert content data
 *  \details        Performs AEADBlock128 encryption of Alert content data
 *                  in the Tls buffer into a linear TcpIp buffer
 *  \param[in]      TlsConIdx              TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out]  BufSeg                 Pointer to TcpIp linear buffer segment (at least size of content data)
 *  \param[in,out]  AuthTagSeg             Pointer to the authentication tag buffer segment
 *  \return         E_OK                   Operation successful
 *  \return         E_NOT_OK               Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_EncryptAEADBlock128Al(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        BufSeg,
  TcpIp_SegmentPtrType        AuthTagSeg);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_EncryptAEADBlock128AlWithTcpWraparound
 *********************************************************************************************************************/
/*! \brief          AEADBlock128 encryption of the alert data
 *  \details        -
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out]  TcpIpSeg1           Pointer to TcpIp first segment buffer
 *  \param[in,out]  TcpIpSeg2           Pointer to TcpIp second segment buffer
 *  \param[in,out]  AuthTagSeg          Pointer to authentication tag buffer segment
 *  \return         E_OK                Operation successful
 *  \return         E_NOT_OK            Operation NOT successful
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_EncryptAEADBlock128AlWithTcpWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        TcpIpSeg1,
  TcpIp_SegmentPtrType        TcpIpSeg2,
  TcpIp_SegmentPtrType        AuthTagSeg);

/**********************************************************************************************************************
 * TcpIp_TlsCore_AEADBlock128GenerateAADataTlsVersionDependentWithPlaintextLen
 *********************************************************************************************************************/
/*! \brief         Trigger the generation of AA data for AEADBlock128 depending on the TLS version
 *  \details       The content length is calculated based on the plaintext data length
 *  \param[in]     TlsConIdx            TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[out]    AddAuthDataSeg       Buffer segment to store additional auth data
 *                                      CONSTRAINT Should be at least TCPIP_TLS_BLOCK128_AADATA_MAXLEN size
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCore_AEADBlock128GenerateAADataTlsVersionDependentWithPlaintextLen(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        AddAuthDataSeg);

/**********************************************************************************************************************
 * TcpIp_TlsCore_AEADBlock128GenerateAADataTlsVersionDependent
 *********************************************************************************************************************/
/*! \brief         Trigger the generation of AA data for AEADBlock128 depending on the TLS version
 *  \details       Calling this function triggers the generation of the additional authentication data for AEAD
 *                 with AEADBlock128 depending on the used TLS version for encryption.
 *  \param[in]     TlsConIdx            TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType          Content type used to generate the AA data
 *  \param[in]     ContentLen           Content length used to generate the AA data
 *  \param[in]     Encrypt              Specifies if the AA data is used for encryption or decryption
 *  \param[out]    AddAuthDataSeg       Buffer segment to store additional auth data
 *                                      CONSTRAINT Should be at least TCPIP_TLS_BLOCK128_AADATA_MAXLEN size
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCore_AEADBlock128GenerateAADataTlsVersionDependent(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8                       ContentType,
  uint16                      ContentLen,
  boolean                     Encrypt,
  TcpIp_SegmentPtrType        AddAuthDataSeg);

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCrypto_AEADBlock128GenerateAAData
 *********************************************************************************************************************/
/*! \brief          Generate the additional authentication data for decryption and encryption
 *  \details        Is called during decryption or encryption to generate the additional authentication data
 *                  for AES GCM ciphers.
 *  \param[in]      ContentLen          TLSCiphertext length
 *  \param[in]      Type                Content type of the record layer frame
 *  \param[in,out]  AddAuthDataPtr      Buffer segment for the additional authentication data
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13CoreCrypto_AEADBlock128GenerateAAData(
  uint16                      ContentLen,
  uint8                       Type,
  TcpIp_SegmentPtrType        AddAuthDataSeg);
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCrypto_AEADDecryptSafe()
 *********************************************************************************************************************/
/*! \brief         Uses the given data to perform an AEAD decryption and stores the plaintext and the result of
 *                 verification in the Tls Rx buffer and VerifyPtr pointer.
 *  \details       -
 *  \param[in]     JobId                  Holds the identifier of the job using the CSM service.
 *  \param[in]     Mode                   Indicates which CSM operation mode(s) to perform.
 *  \param[in]     CiphertextPtr          Contains the pointer to the data to be decrypted.
 *  \param[in]     CiphertextLength       Contains the number of bytes to decrypt.
 *  \param[in]     AssociatedDataPtr      Contains the pointer to the associated data.
 *  \param[in]     AssociatedDataLength   Contains the number of bytes of the associated data.
 *  \param[in]     TagPtr                 Contains the pointer to the data where the Tag shall be stored.
 *  \param[in]     TagLength              Contains the length in bytes of the Tag to be verified.
 *  \param[in]     WriteIdx               Contains the index of the Tls Rx buffer where the data shall be copied to.
 *  \param[in,out] ResultLengthPtr        Holds a pointer to the memory location in which the output length information
 *                                        is stored in bytes. On calling this function, this parameter shall
 *                                        contain the size of the Tls Rx buffer area. When the request has finished,
 *                                        the actual length of the returned value shall be stored.
 *  \param[out]    VerifyPtr              Contains the pointer to the result of the verification.
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCrypto_AEADDecryptSafe(
  uint32                   JobId,
  Crypto_OperationModeType Mode,
  TCPIP_P2C(uint8)         CiphertextPtr,
  uint32                   CiphertextLength,
  TCPIP_P2C(uint8)         AssociatedDataPtr,
  uint32                   AssociatedDataLength,
  TCPIP_P2C(uint8)         TagPtr,
  uint32                   TagLength,
  uint32                   WriteIdx,
  TCPIP_P2V(uint32)        ResultLengthPtr,
  TCPIP_P2V(Crypto_VerifyResultType) VerifyPtr);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCrypto_MacGenerateSafe()
 *********************************************************************************************************************/
/*! \brief         Uses the given data to perform a MAC generation and stores the MAC in the temporary Hmac buffer.
 *  \details       -
 *  \param[in]     JobId                 Holds the identifier of the job using the CSM service.
 *  \param[in]     Mode                  Indicates which CSM operation mode(s) to perform.
 *  \param[in]     DataPtr               Contains the pointer to the data for which the MAC shall be computed.
 *  \param[in]     DataLength            Contains the number of bytes for the MAC generation.
 *  \param[in]     WriteIdx              Contains the index of the temporary Hmac buffer
 *                                       where the data shall be copied to.
 *  \param[in,out] macLengthPtr          Holds a pointer to the memory location in which the output length in bytes is
 *                                       stored. On calling this function, this parameter shall contain the size of the
 *                                       buffer provided by ResultLengthPtr. When the request has finished, the actual
 *                                       length of the returned MAC shall be stored.
 *  \param[in,out] ResultLengthPtr       Holds a pointer to the memory location in which the output length in bytes is
 *                                       stored. On calling this function, this parameter shall contain the size of the
 *                                       temporary Hmac buffer area. When the request has finished, the actual length
 *                                       of the returned MAC shall be stored.
 *  \return        E_OK                  Request successful
 *                 E_NOT_OK              Request failed
 *                 CRYPTO_E_BUSY         Request failed, service is busy
 *                 CRYPTO_E_QUEUE_FULL   Request failed, the queue is full
 *                 CRYPTO_E_SMALL_BUFFER The provided buffer is too small to store the result
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCrypto_MacGenerateSafe(
  uint32                   JobId,
  Crypto_OperationModeType Mode,
  TCPIP_P2C(uint8)         DataPtr,
  uint32                   DataLength,
  uint32                   WriteIdx,
  TCPIP_P2V(uint32)        ResultLengthPtr);

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 * TcpIp_Tls12CoreCrypto_AEADBlock128GenerateAAData
 *********************************************************************************************************************/
/*! \brief         Generate TLS 1.2 AA data for AEADBlock128
 *  \details       -
 *  \param[in]     TlsSeqNum           Tls sequence number (64-bit)
 *  \param[in]     ContentLen          Length of content data
 *  \param[in]     Type                Type of data
 *  \param[out]    AddAuthDataSeg      Buffer segment to store additional auth data
 *                                     CONSTRAINT Should be at least TCPIP_TLS_BLOCK128_AADATA_MAXLEN size
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE)  TcpIp_Tls12CoreCrypto_AEADBlock128GenerateAAData(
  uint64                      TlsSeqNum,
  uint16                      ContentLen,
  uint8                       Type,
  TcpIp_SegmentPtrType        AddAuthDataSeg);
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_GenerateAEADBlock128IvTlsVersionDependent
 *********************************************************************************************************************/
/*! \brief         Call the functions for generating the Iv depending on the TLS version
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[out]    EIvSeg              Pointer to buffer segment where the explicit IV shall be stored in TLS 1.2 case
 *                                     CONSTRAINT Should be at least TCPIP_TLS_BLOCK128_EXPLICIT_IV_LEN size
 *  \return        E_OK                Operation successful
 *  \return        E_NOT_OK            Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE)  TcpIp_TlsCoreRl_GenerateAEADBlock128IvTlsVersionDependent(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TCPIP_P2V(TcpIp_SegmentType)  EIvSeg);

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsCoreCrypto_GenerateAEADBlock128Iv
 *********************************************************************************************************************/
/*! \brief         Generate the Iv for AEADBlock128 and set the CSM key
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] EIvSeg           Pointer to buffer segment where the explicit IV shall be stored
 *                                     CONSTRAINT Should be at least TCPIP_TLS_BLOCK128_EXPLICIT_IV_LEN size
 *  \return        E_OK                Operation successful
 *  \return        E_NOT_OK            Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE)  TcpIp_TlsCoreCrypto_GenerateAEADBlock128Iv(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        EIvSeg);
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_TxCipherAEADGenAndCopyBlock128Iv
 *********************************************************************************************************************/
/*! \brief          Iv generation AEADBlock128 with TcpIp wraparound
 *  \details        The function handles Iv generation for AEADBlock128
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out]  TcpSeg1             Pointer to the first buffer segment
 *  \param[in,out]  TcpSeg2             Pointer to the second buffer segment
 *  \return         E_OK                Operation successful
 *  \return         E_NOT_OK            Operation NOT successful
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE)  TcpIp_TlsCoreRl_TxCipherAEADGenAndCopyBlock128Iv(
  TcpIp_TlsConnectionIterType    TlsConIdx,
  TCPIP_P2V(TcpIp_SegmentType)   TcpSeg1,
  TCPIP_P2V(TcpIp_SegmentType)   TcpSeg2);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_TxCipherEncryptAEADBlock128ContentData
 *********************************************************************************************************************/
/*! \brief          AEADBlock128 encryption of content data with TcpIp wrap around
 *  \details        Handles AEADBlock128 encryption of content data when there is TcpIp wrap around
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out]  TcpIpSeg1           Pointer to TcpIp first segment buffer
 *  \param[in,out]  TcpIpSeg2           Pointer to TcpIp second segment buffer
 *  \param[in,out]  AuthTagSeg          Pointer to authentication tag buffer segment
 *                                      CONSTRAINT: Should have at least TCPIP_TLS_BLOCK128_AUTHTAG_LEN size
 *  \return         E_OK                Operation successful
 *  \return         E_NOT_OK            Operation NOT successful
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE)  TcpIp_TlsCoreRl_TxCipherEncryptAEADBlock128ContentData(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        TcpIpSeg1,
  TcpIp_SegmentPtrType        TcpIpSeg2,
  TcpIp_SegmentPtrType        AuthTagSeg);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_EncryptAEADBlock128AdHsWithoutTlsWraparound
 *********************************************************************************************************************/
/*! \brief          AEADBlock128 encryption of AdHs content with TcpIp wraparound and no Tls wraparound
 *  \details        Handles AEADBlock128 encryption of AdHs content when the TcpIp buffer wraps around,
 *                  but not the TLS buffer
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out]  TcpIpSeg1           Pointer to TcpIp first segment buffer
 *  \param[in,out]  TcpIpSeg2           Pointer to TcpIp second segment buffer
 *  \param[in,out]  AuthTagSeg          Pointer to authentication tag buffer segment
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_EncryptAEADBlock128AdHsWithoutTlsWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        TcpIpSeg1,
  TcpIp_SegmentPtrType        TcpIpSeg2,
  TcpIp_SegmentPtrType        AuthTagSeg);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_EncryptAEADBlock128AdHsWithTlsWraparound
 *********************************************************************************************************************/
/*! \brief          AEADBlock128 encryption of AdHs content TcpIp and Tls wraparound
 *  \details        Handles AEADBlock128 encryption of AdHs content when the Tls and
 *                  TcpIp buffer wraps around
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out]  TcpIpSeg1           Pointer to TcpIp first segment buffer
 *  \param[in,out]  TcpIpSeg2           Pointer to TcpIp second segment buffer
 *  \param[in,out]  AuthTagSeg          Pointer to authentication tag buffer segment
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_EncryptAEADBlock128AdHsWithTlsWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        TcpIpSeg1,
  TcpIp_SegmentPtrType        TcpIpSeg2,
  TcpIp_SegmentPtrType        AuthTagSeg);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_CopyFromTxBufferWithWraparound
 *********************************************************************************************************************/
/*! \brief         Copy the Tx data from Tls buffer into destination TcpIp buffer
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] BufSeg             Pointer to the provided destination buffer segment
 *  \param[in]     CopyCnt            Number of bytes to copy
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_CopyFromTxBufferWithWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        BufSeg,
  uint16                      CopyCnt);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_CopyFromTxBufferAdHsWithWraparound
 *********************************************************************************************************************/
/*! \brief         Copy the data from the AD/HS buffer
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] BufSeg             Pointer to provided destination buffer segment
 *  \param[in]     CopyCnt            Number of bytes to copy
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_CopyFromTxBufferAdHsWithWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        BufSeg,
  uint16                      CopyCnt);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_CopyFromTxBufferCcs
 *********************************************************************************************************************/
/*! \brief         Copy the data from the CCS buffer
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] BufSeg             Pointer to provided destination buffer segment
 *  \param[in]     CopyCnt            Number of bytes to copy
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_CopyFromTxBufferCcs(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        BufSeg,
  uint16                      CopyCnt);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_CopyFromTxBufferAl
 *********************************************************************************************************************/
/*! \brief         Copy the data from the AL buffer
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in,out] BufSeg             Pointer to provided destination buffer segment
 *  \param[in]     CopyCnt            Number of bytes to copy
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_CopyFromTxBufferAl(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        BufSeg,
  uint16                      CopyCnt);

/***********************************************************************************************************************
 *  TcpIp_TlsCoreRl_CalcHmacShaContentTypeDependent
 **********************************************************************************************************************/
/*! \brief         Forward the calculation of the HMAC to the cipher dependent subfunctions
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK               HMAC calculation successful
 *  \return        E_NOT_OK           HMAC calculation NOT successful
 *  \pre           -
 *  \context       TASK
 **********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_CalcHmacShaContentTypeDependent(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_CalcHmacShaAdHs
 *********************************************************************************************************************/
/*! \brief         Calculates the HMAC in case of SHA ciphersuite and TLS AD or TLS HS data
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK               HMAC calculation successful
 *  \return        E_NOT_OK           HMAC calculation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_CalcHmacShaAdHs(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_CalcHmacShaAl
 *********************************************************************************************************************/
/*! \brief         Calculates the HMAC in case of SHA ciphersuite and TLS AL data
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        E_OK               HMAC calculation successful
 *  \return        E_NOT_OK           HMAC calculation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_CalcHmacShaAl(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_HandleErrorWhileTransmit
 *********************************************************************************************************************/
/*! \brief         Handles occurring errors during transmitting of a TLS record layer frame
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ErrorId            Error Id which should be reported
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_HandleErrorWhileTransmit(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsUserErrorIdType ErrorId);

/**********************************************************************************************************************
 *  TCPIP TLS INIT FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCore_ResetConnection
 *********************************************************************************************************************/
/*! \brief         Reset either the Server or Client relevant part and also the all connection variables
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCore_ResetConnection(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsCore_ResetConnectionVariables
 *********************************************************************************************************************/
/*! \brief         Reset all connection relevant variables
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCore_ResetConnectionVariables(
  TcpIp_TlsConnectionIterType TlsConIdx);

# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsCore_InitCertChainStates
 *********************************************************************************************************************/
/*! \brief         Initialize the certificate chain struct and states used for both server and client authentication
 *  \details       Sets all TLS certificate information to their default values
 *  \param[in]     TlsConIdx               TLS connection index
 *                                         \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCore_InitCertChainStates(
  TcpIp_TlsConnectionIterType TlsConIdx);
# endif

/**********************************************************************************************************************
 *  TcpIp_TlsCore_InitAsyncFlags
 *********************************************************************************************************************/
/*! \brief         Initialize the async context flags for the TLS core
 *  \details       Sets all TLS core trigger flags for the async context calculation to FALSE
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCore_InitAsyncFlags(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRxIndication_Init
 *********************************************************************************************************************/
/*! \brief         Initialize the Rx Indications
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRxIndication_Init(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCipher_Init
 *********************************************************************************************************************/
/*! \brief         Initialize the Cipher worker and ciphers
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCipher_Init(TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreConnection_Init
 *********************************************************************************************************************/
/*! \brief         Initialize all TLS connection related variables
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreConnection_Init(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TLS CORE BUFFER
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreBuffer_Init
 *********************************************************************************************************************/
/*! \brief         Initialize all TLS RX and TLS TX buffers
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK|
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreBuffer_Init(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreBufferStruct_Init
 *********************************************************************************************************************/
/*! \brief         Initialize all TLS BufferStruct.
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreBufferStruct_Init(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRxBufStruct_Init()
 **********************************************************************************************************************/
/*! \brief         Initializes a rx buffer struct.
 *  \details       -
 *  \param[in]     TlsBufferMgmtIdx     TLS Buffer management index
 *                                      \spec requires TlsBufferMgmtIdx < TcpIp_GetSizeOfTlsBufferMgmt(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE for different rx buffer structs, FALSE for same rx buffer struct.
 **********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRxBufStruct_Init(
  TcpIp_SizeOfTlsBufferMgmtType TlsBufferMgmtIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRxBufStruct_GetTotLen()
 **********************************************************************************************************************/
/*! \brief         Gets length of all segments in rx buffer struct starting at specified offset.
 *  \details       -
 *  \param[in]     TlsBufferMgmtIdx     TLS Buffer management index
 *                                      \spec requires TlsBufferMgmtIdx < TcpIp_GetSizeOfTlsBufferMgmt(); \endspec
 *  \param[in]     BufSegOffset         Offset in rx buffer struct considering all segments.
 *  \return        TotalLen             Total length of all segments starting at specified offset.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 **********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(uint32, TCPIP_CODE) TcpIp_TlsCoreRxBufStruct_GetTotLen(
  TcpIp_SizeOfTlsBufferMgmtType TlsBufferMgmtIdx,
  uint32 BufSegOffset);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRxBufStruct_Copy2Buf()
 **********************************************************************************************************************/
/*! \brief         Copies segments of RX buffer struct to a provided buffer.
 *  \details       -
 *  \param[in]     TlsBufferMgmtIdx     TLS Buffer management index
 *                                      \spec requires TlsBufferMgmtIdx < TcpIp_GetSizeOfTlsBufferMgmt(); \endspec
 *  \param[in]     BufPtr               Pointer to provided buffer.
 *  \param[in]     BufLen               Length of data to be copied to provided buffer.
 *  \param[in]     BufSegOffset         Offset in RX buffer struct considering all segments.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 **********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRxBufStruct_Copy2Buf(
  TcpIp_SizeOfTlsBufferMgmtType TlsBufferMgmtIdx,
  TCPIP_P2V(uint8) BufPtr,
  uint32 BufLen,
  uint32 BufSegOffset);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRxBufStruct_GetBufSegIdx()
 **********************************************************************************************************************/
/*! \brief           Gets the buffer segment index and segment offset of an rx buffer struct considering a total offset
 *                   of rx buffer struct.
 *  \details         -
 *  \param[in]       TlsBufferMgmtIdx     TLS Buffer management index
 *                                        \spec requires TlsBufferMgmtIdx < TcpIp_GetSizeOfTlsBufferMgmt(); \endspec
 *  \param[in,out]   OffsetPtr            Pointer to offset considering all segments which is overwritten by segment
 *                                        offset.
 *  \param[out]      BufSegIdxPtr         Pointer to buffer segment index.
 *  \pre             -
 *  \context         TASK
 *  \reentrant       FALSE
 **********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRxBufStruct_GetBufSegIdx(
  TcpIp_SizeOfTlsBufferMgmtType TlsBufferMgmtIdx,
  TCPIP_P2V(uint32) OffsetPtr,
  TCPIP_P2V(TcpIp_SizeOfRxBufStructSegType) BufSegIdxPtr);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRxBufStruct_ReleaseSegment()
 **********************************************************************************************************************/
/*! \brief         Releases a specified length of rx buffer struct.
 *  \details       -
 *  \param[in]     TlsBufferMgmtIdx     TLS Buffer management index
 *                                      \spec requires TlsBufferMgmtIdx < TcpIp_GetSizeOfTlsBufferMgmt(); \endspec
 *  \param[in]     Len                  Length of data to be released.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 **********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRxBufStruct_ReleaseSegment(
  TcpIp_SizeOfTlsBufferMgmtType TlsBufferMgmtIdx,
  uint32 Len);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRxBufStruct_WriteSegment()
 **********************************************************************************************************************/
/*! \brief         Writes segment to rx buffer struct to get a local image of the lower layer segmented TCP buffer.
 *  \details       Supports segments and merging if received data is located directly behind the previously received
 *                 segment (i.e. ring buffer logic).
 *  \param[in]     TlsBufferMgmtIdx     TLS Buffer management index
 *                                      \spec requires TlsBufferMgmtIdx < TcpIp_GetSizeOfTlsBufferMgmt(); \endspec
 *  \param[in]     SrcBufPtr            Pointer to linear source buffer.
 *  \param[in]     SrcBufLen            Length of linear source buffer.
 *  \return        E_OK                 Writing to rx buffer struct succeeded.
 *  \return        E_NOT_OK             Writing to rx buffer struct failed.
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     TRUE for different rx buffer structs, FALSE for same rx buffer struct.
 **********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRxBufStruct_WriteSegment(
  TcpIp_SizeOfTlsBufferMgmtType TlsBufferMgmtIdx,
  TCPIP_P2V(uint8) SrcBufPtr,
  uint16 SrcBufLen);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRxBufStruct_WriteAdditionalSegment()
 **********************************************************************************************************************/
/*! \brief         Writes additional segment to rx buffer struct.
 *  \details       -
 *  \param[in]     TlsBufferMgmtIdx     TLS Buffer management index
 *                                      \spec requires TlsBufferMgmtIdx < TcpIp_GetSizeOfTlsBufferMgmt(); \endspec
 *  \param[in]     SrcBufPtr            Pointer to linear source buffer.
 *  \param[in]     SrcBufLen            Length of linear source buffer.
 *  \return        E_OK                 Writing to rx buffer struct succeeded.
 *  \return        E_NOT_OK             Writing to rx buffer struct failed.
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     TRUE for different rx buffer structs, FALSE for same rx buffer struct.
 **********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRxBufStruct_WriteAdditionalSegment(
  TcpIp_SizeOfTlsBufferMgmtType TlsBufferMgmtIdx,
  TCPIP_P2V(uint8) SrcBufPtr,
  uint16 SrcBufLen);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRxBufStruct_CalculateNextSegment()
 **********************************************************************************************************************/
/*! \brief         Calculates next segment depending on a segment index and level.
 *  \details       -
 *  \param[in]     TlsBufferMgmtIdx     TLS Buffer management index
 *                                      \spec requires TlsBufferMgmtIdx < TcpIp_GetSizeOfTlsBufferMgmt(); \endspec
 *  \param[in]     SegmentIndex         Index of segment from which calculation starts.
 *  \param[in]     SegmentLvl           Fill level of rx buffer struct.
 *  \return        NextSegmentIndex     Calculated next index.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 **********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(TcpIp_SizeOfRxBufStructSegType, TCPIP_CODE) TcpIp_TlsCoreRxBufStruct_CalculateNextSegment(
  TcpIp_SizeOfTlsBufferMgmtType TlsBufferMgmtIdx,
  TcpIp_SizeOfRxBufStructSegType SegmentIndex,
  TcpIp_RxBufStructSegLvlOfRxBufStructMgtType SegmentLvl);

/**********************************************************************************************************************
 *  TLS CORE STATES AND EVENTS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsCoreState_UserEventHandler
 *********************************************************************************************************************/
/*! \brief         Main state handler for the TLS module
 *  \details       -
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreState_UserEventHandler(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreState_HandshakeHandler
 *********************************************************************************************************************/
/*! \brief         Main handler for processing the TLS handshake state machine
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreState_HandshakeHandler(
  TcpIp_TlsConnectionIterType TlsConIdx);

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreState_ConnectionHandler
 *********************************************************************************************************************/
/*! \brief         Main handler for processing the TLS connection state machine
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreState_ConnectionHandler(
  TcpIp_TlsConnectionIterType TlsConIdx);
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */

/**********************************************************************************************************************
 * TcpIp_TlsCoreState_TcpEventHandler
 *********************************************************************************************************************/
/*! \brief         Main handler for processing the TCP events
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreState_TcpEventHandler(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreState_UserErrorHandler
 *********************************************************************************************************************/
/*! \brief         Main handler for processing the TLS User errors
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreState_UserErrorHandler(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreState_AlertHandler
 *********************************************************************************************************************/
/*! \brief         Main handler for processing the TLS alert handling
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreState_AlertHandler(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreState_ApplicationDataHandler
 *********************************************************************************************************************/
/*! \brief         Main handler for processing the TLS application data
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreState_ApplicationDataHandler(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreEvent_TcpIpEventCloseWithAbortFalse
 *********************************************************************************************************************/
/*! \brief         Forwards the TcpIp event CLOSE with Abort set to false to the TLS stack
 *  \details       -
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreEvent_TcpIpEventCloseWithAbortFalse(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreEvent_TcpEventReset
 *********************************************************************************************************************/
/*! \brief         Main state handler for TCP reset events
 *  \details       -
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreEvent_TcpEventReset(
TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreEvent_TcpEventClosed
 *********************************************************************************************************************/
/*! \brief         Main state handler for TCP closed events
 *  \details       -
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreEvent_TcpEventClosed(
TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreEvent_InformAboutTcpClosed
 *********************************************************************************************************************/
/*! \brief         Inform about occurred TCP closed event.
 *  \details       -
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreEvent_InformAboutTcpClosed(
TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreEvent_TcpEventFinReceived
 *********************************************************************************************************************/
/*! \brief         Main state handler for TCP FIN received events
 *  \details       -
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreEvent_TcpEventFinReceived(
TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreEvent_InformAboutTcpFin
 *********************************************************************************************************************/
/*! \brief         Inform about occurred TCP FIN event.
 *  \details       -
 *  \param[in]      TlsConIdx           TLS connection index
 *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreEvent_InformAboutTcpFin(
TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TLS CONNECTION STATE HANDLER
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreConState_UserResetRequestedHandler
 *********************************************************************************************************************/
/*! \brief         Main connection state handler for processing the UpperLayer reset requests
 *  \details       This processes the reset request from the UpperLayer
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreConState_UserResetRequestedHandler(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreConState_UserCloseRequestedHandler
 *********************************************************************************************************************/
/*! \brief         Main connection state handler for processing the UpperLayer close requests
 *  \details       This processes the close request from the UpperLayer
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreConState_UserCloseRequestedHandler(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreConState_ForwardCloseToTcp
 *********************************************************************************************************************/
/*! \brief         Forwards the close call to the underlaying TCP module.
 *  \details       -
 *  \param[in]     SocketTcpIdx TCP socket to close
 *  \param[in]     Abort        TRUE: connection will immediately be terminated by sending a RST-Segment and releasing
 *                              all related resources.
 *                              FALSE: connection will be terminated after performing a regular connection termination
 *                              handshake and releasing all related resources.
 *  \param[in]     RemoveTlsSocketInfo TRUE:  Mapping between TLS and TCP will be removed.
 *                                     FALSE: Mapping between TLS and TCP remains.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreConState_ForwardCloseToTcp(
  TcpIp_SizeOfSocketTcpDynType SocketTcpIdx,
  boolean                      Abort,
  boolean                      RemoveTlsSocketInfo);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreConState_TcpCloseRequestedHandler
 *********************************************************************************************************************/
/*! \brief         Main connection state handler for processing the close requests
 *  \details       This processes the close request from TCP
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreConState_TcpCloseRequestedHandler(
  TcpIp_TlsConnectionIterType TlsConIdx);


/**********************************************************************************************************************
 *  TcpIp_TlsCoreConState_TcpResetRequestedHandler
 *********************************************************************************************************************/
/*! \brief         Main connection state handler for processing the reset requests
 *  \details       This processes the reset request from TCP
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreConState_TcpResetRequestedHandler(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TLS CORE MAIN FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtx_AsyncHandler
 *********************************************************************************************************************/
/*! \brief         Asynchronous handler of TLS Core subcomponent
 *  \details       -
 *  \pre           -
 *  \context       TASK (only called in the context of the TLS background task TcpIp_Tls_MainFunctionLowPrio())
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtx_AsyncHandler(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TLS CORE MAIN FUNCTION RX
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsCoreMainFunction_RxRl
 *********************************************************************************************************************/
/*! \brief         Main function for processing the received TLS record layer frames
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_RxRl(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreMainFunction_RxHs
 *********************************************************************************************************************/
/*! \brief         Main function for processing the received TLS handshake frames
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_RxHs(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreMainFunction_RxAl
 *********************************************************************************************************************/
/*! \brief         Main function for processing the received TLS alert frames
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_RxAl(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreMainFunction_RxAd
 *********************************************************************************************************************/
/*! \brief         Main function for processing the received TLS application data frames
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_RxAd(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreMainFunction_RxCcs
 *********************************************************************************************************************/
/*! \brief         Main function for processing the received TLS CCS frames
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_RxCcs(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreUl_RxConfirmedAdDataHandler
 *********************************************************************************************************************/
/*! \brief         Main function for from UL confirmed TLS application data
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreUl_RxConfirmedAdDataHandler(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TLS CORE MAIN FUNCTION TX
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * TcpIp_TlsCoreMainFunction_TxHs
 *********************************************************************************************************************/
/*! \brief         Main function for processing the transmittable TLS handshake frames
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_TxHs(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreMainFunction_TxAl
 *********************************************************************************************************************/
/*! \brief         Main function for processing the transmittable TLS alert frames
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_TxAl(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreMainFunction_TxAd
 *********************************************************************************************************************/
/*! \brief         Main function for processing the transmittable TLS application data frames
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_TxAd(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreMainFunction_TxCcs
 *********************************************************************************************************************/
/*! \brief         Main function for processing the transmittable TLS CCS frames
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_TxCcs(
  TcpIp_TlsConnectionIterType TlsConIdx);

# if (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsCoreMainFunction_TxNss
 *********************************************************************************************************************/
/*! \brief         Main function for processing the transmittable NSS Key Log frame for the TLS secrets
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_TxNss(
  TcpIp_TlsConnectionIterType TlsConIdx);
# endif /* (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON) */

# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsCoreMsg_ExtractNextCertificate
 *********************************************************************************************************************/
/*! \brief         Extract the next certificate from the given certificate index
 *  \details       -
 *  \param[in]     CertStartTlsBufferRxIdx     Read Idx of the Certificate data
 *  \param[out]    CertDataPtr                 Pointer to Certificate data struct
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMsg_ExtractNextCertificate(
  TcpIp_TlsBufferRxIterType           CertStartTlsBufferRxIdx,
  TCPIP_P2V(TcpIp_CertDataType)       CertDataPtr);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMsg_WriteEncodedSecpSignature
 *********************************************************************************************************************/
/*! \brief         Write the BER encoded secp signature component to the message buffer.
 *  \details       The descriptor contains all necessary details that are necessary for the encoding (kind, source,
 *                 destination). Only signature components with a length smaller than 0x80 are supported.
 *  \param[in]     SignCoordinateDescriptorPtr     Pointer to the descriptor with all necessary information
 *  \pre           All struct elements of the descriptor are filled correctly
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMsg_WriteEncodedSecpSignature(
  TCPIP_P2C(TcpIp_TlsSecpSignCoordinateDescriptorType) SignCoordinateDescriptorPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreMsg_DecodeSecpSignature
 *********************************************************************************************************************/
/*! \brief         Decode the received BER encoded Secp signature
 *  \details       -
 *  \param[in]     ReceivedSignatureLen             Length of the received signature
 *  \param[in]     ReceivedSignatureSrcPtr          Pointer to the received signature
 *  \param[in,out] OutputBufferSeg                  Pointer to the buffer segment
 *                                                  where the processed signature shall be stored
 *  \param[in]     CurveId                          Id of the curve which shall be decoded, must be a Secp curve
 *  \return        E_OK                             Decoding of signature successful
 *  \return        E_NOT_OK                         Decoding of signature NOT successful
 *  \pre           The buffer provided to SignOutputPtr must have a minimum length of 2 * coordinate size of the curve
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreMsg_DecodeSecpSignature(
  uint32                       ReceivedSignatureLen,
  TCPIP_P2C(uint8)             ReceivedSignatureSrcPtr,
  TcpIp_SegmentPtrType         OutputBufferSeg,
  TcpIp_TlsEllipticCurveIdType CurveId);

/**********************************************************************************************************************
 * TcpIp_TlsCoreMsg_CheckSecpSignatureSequence
 *********************************************************************************************************************/
/*! \brief         Checks the sequence type and length of a BER encoded Secp signature
 *  \details       -
 *  \param[in]     WorkspacePtr                     Pointer to a initialized IpBase Ber decoding workspace
 *  \param[in]     EleNrReceivedSignatureStartPtr   Pointer to the searched element number
 *                                                  (chapter.section.subsection. ...), here: start of the signature
 *  \param[in]     ReceivedSignaturePtr             Pointer to the received signature
 *  \param[in]     ReceivedSignatureLen             Length of the received signature
 *  \param[in]     CurveId                          Id of the curve which shall be decoded, must be a Secp curve
 *  \return        E_OK                             Sequence type and length of the signature is well formatted
 *  \return        E_NOT_OK                         Sequence type and length of the signature is NOT well formatted
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreMsg_CheckSecpSignatureSequence(
  TCPIP_P2V(IpBase_BerWorkspaceType) WorkspacePtr,
  TCPIP_P2C(uint8)                   EleNrReceivedSignatureStartPtr,
  TCPIP_P2C(uint8)                   ReceivedSignaturePtr,
  uint32                             ReceivedSignatureLen,
  TcpIp_TlsEllipticCurveIdType       CurveId);

/**********************************************************************************************************************
 * TcpIp_TlsCoreMsg_DecodeSecpSignatureRValue
 *********************************************************************************************************************/
/*! \brief         Decodes the r-value of a BER encoded Secp signature
 *  \details       Check the format of the BER encoded r-value
 *  \param[in]     WorkspacePtr                     Pointer to a initialized IpBase Ber decoding workspace
 *  \param[in]     EleNrReceivedSignatureStartPtr   Pointer to the searched element number
 *                                                  (chapter.section.subsection. ...), here: the r-value
 *  \param[in]     ReceivedSignaturePtr             Pointer to the received signature
 *  \param[in]     ReceivedSignatureLen             Length of the received signature
 *  \param[in]     CurveId                          Id of the curve which shall be decoded, must be a Secp curve
 *  \param[in,out] OutputBufferSeg                  Pointer to the buffer segment
 *                                                  where the processed signature shall be stored
 *  \return        E_OK                             R-value is well formatted, the value is copied to SignOutputPtr
 *  \return        E_NOT_OK                         R-value is NOT well formatted, the value is NOT copied
 *  \pre           The buffer provided to SignOutputPtr must have a minimum length of 2 * coordinate size of the curve
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreMsg_DecodeSecpSignatureRValue(
  TCPIP_P2V(IpBase_BerWorkspaceType) WorkspacePtr,
  TCPIP_P2C(uint8)                   EleNrRValuePtr,
  TCPIP_P2C(uint8)                   ReceivedSignaturePtr,
  uint32                             ReceivedSignatureLen,
  TcpIp_TlsEllipticCurveIdType       CurveId,
  TcpIp_SegmentPtrType               OutputBufferSeg);

/**********************************************************************************************************************
 * TcpIp_TlsCoreMsg_DecodeSecpSignatureSValue
 *********************************************************************************************************************/
/*! \brief         Decodes the s-value of a BER encoded Secp signature
 *  \details       Check the format of the BER encoded s-value
 *  \param[in]     WorkspacePtr                     Pointer to a initialized IpBase Ber decoding workspace
 *  \param[in]     EleNrReceivedSignatureStartPtr   Pointer to the searched element number
 *                                                  (chapter.section.subsection. ...), here: the s-value
 *  \param[in]     ReceivedSignaturePtr             Pointer to the received signature
 *  \param[in]     ReceivedSignatureLen             Length of the received signature
 *  \param[in]     CurveId                          Id of the curve which shall be decoded, must be a Secp curve
 *  \param[in,out] OutputBufferSeg                  Pointer to the buffer segment
 *                                                  where the processed signature shall be stored
 *  \return        E_OK                             S-value is well formatted, the value is copied to SignOutputPtr
 *  \return        E_NOT_OK                         S-value is NOT well formatted, the value is NOT copied
 *  \pre           The buffer provided to SignOutputPtr must have a minimum length of 2 * coordinate size of the curve
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreMsg_DecodeSecpSignatureSValue(
  TCPIP_P2V(IpBase_BerWorkspaceType) WorkspacePtr,
  TCPIP_P2C(uint8)                   EleNrSValuePtr,
  TCPIP_P2C(uint8)                   ReceivedSignaturePtr,
  uint32                             ReceivedSignatureLen,
  TcpIp_TlsEllipticCurveIdType       CurveId,
  TcpIp_SegmentPtrType               OutputBufferSeg);

/**********************************************************************************************************************
 * TcpIp_TlsCoreMsg_DecodeEd25519Signature
 *********************************************************************************************************************/
/*! \brief         Decode the received Ed25519 signature
 *  \details       -
 *  \param[in]     ReceivedSignatureLen              Length of the signature
 *  \param[in]     ReceivedSignatureSrcPtr           Pointer to the received signature
 *  \param[in,out] OutputBufferSeg                   Pointer to the buffer segment
 *                                                   where the processed signature shall be stored
 *  \return        E_OK                              Operation successful
 *  \return        E_NOT_OK                          Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreMsg_DecodeEd25519Signature(
  uint32                      ReceivedSignatureLen,
  TCPIP_P2C(uint8)            ReceivedSignatureSrcPtr,
  TcpIp_SegmentPtrType        OutputBufferSeg);

/**********************************************************************************************************************
 * TcpIp_TlsClientMsg_DecodeEd448Signature
 *********************************************************************************************************************/
/*! \brief         Decode the received Ed448 signature
 *  \details       -
 *  \param[in]     ReceivedSignatureLen              Length of the signature
 *  \param[in]     ReceivedSignatureSrcPtr           Pointer to the received signature
 *  \param[in,out] OutputBufferSeg                   Pointer to the buffer segment
 *                                                   where the processed signature shall be stored
 *  \return        E_OK                              Operation successful
 *  \return        E_NOT_OK                          Operation NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_DecodeEd448Signature(
  uint32                      ReceivedSignatureLen,
  TCPIP_P2C(uint8)            ReceivedSignatureSrcPtr,
  TcpIp_SegmentPtrType        OutputBufferSeg);
# endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/***********************************************************************************************************************
 *  TLS CORE STATE AND EVENT
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  TLS CORE ERROR
 **********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreError_Init
 *********************************************************************************************************************/
/*! \brief         Initialize the TLS error handling
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreError_Init(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TLS CORE CRYPTO
 *********************************************************************************************************************/
# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreCrypto_KeyExchangeCalcPubValSafe()
 *********************************************************************************************************************/
/*! \brief         Calculates the public value of the current user for the key exchange and stores the public key in
 *                 the Tls Tx buffer.
 *  \details       -
 *  \param[in]     KeyId                   Holds the identifier of the key which shall be used for the key exchange
 *                                         protocol.
 *  \param[in]     WriteIdx                Contains the index of the Tls Tx buffer where the data shall be copied to.
 *  \param[in,out] ResultLengthPtr         Holds a pointer to the memory location in which the public value length
 *                                         information is stored. On calling this function, this parameter shall
 *                                         contain the size of the Tls Tx buffer area. When the request has finished,
 *                                         the actual length of the returned value shall be stored.
 *  \return        E_OK                    Request successful
 *                 E_NOT_OK                Request failed
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy
 *                 CRYPTO_E_KEY_NOT_AVAILABLE Request failed because the key is not available
 *                 CRYPTO_E_SMALL_BUFFER   Request failed because the provided buffer is too small to store the result
 *  \context       TASK
 *  \reentrant     TRUE, but not for the same keyId
 *  \synchronous   TRUE
 *  \pre           -
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCrypto_KeyExchangeCalcPubValSafe(
  uint32            KeyId,
  uint32            WriteIdx,
  TCPIP_P2V(uint32) ResultLengthPtr);

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtx_CheckCalcDhSharedSecretPrecondition()
 *********************************************************************************************************************/
/*! \brief         Checks if the preconditions for calculating the Diffie-Hellman shared secret are fulfilled or not
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        TRUE               The preconditions are fulfilled, the shared secret can be calculated
 *                 FALSE              The preconditions are NOT fulfilled yet, we have to wait
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsCoreCtx_CheckCalcDhSharedSecretPrecondition(
  TcpIp_TlsConnectionIterType TlsConIdx);
# endif

/**********************************************************************************************************************
 *  TLS ALERT
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreAlert_Init
 *********************************************************************************************************************/
/*! \brief         Initialization function for the TLS alert handling
 *  \details       -
 *  \param[in]     TlsConIdx          TLS connection index
 *                                    \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreAlert_Init(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 *  TLS CORE LOWER LAYER (LL)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TLS CORE UTIL  (HELPER FUNCTIONS)
 *********************************************************************************************************************/
# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsClient_TlsUpdateOcspInformation
 *********************************************************************************************************************/
/*! \brief         Checks if OCSP is enabled and updates the OCSP information
 *  \details       -
 *  \param[in]     TlsConIdx              TLS connection index
 *                                        CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in,out] CertStatusPtr          Pointer to the certificate status struct
 *  \return        E_OK                   Ocsp information updated
 *                 E_NOT_OK               Error occurred in KeyM operation, certificate status set to not available
 *  \pre           Certificate chain validation must be already triggered
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClient_TlsUpdateOcspInformation(
  TcpIp_TlsConnectionIterType                  TlsConIdx,
  TCPIP_P2V(TcpIp_CertValidationStatusType)    CertStatusPtr);

/**********************************************************************************************************************
 * TcpIp_Tls_HandleAlertForOcspCertificateStatus
 *********************************************************************************************************************/
/*! \brief         Decides which alert to send due to status of OCSP response and/or received certificate
 *  \details       Additionally calls the error indication callout if necessary and configured
 *  \param[in]     TlsConIdx                    TLS connection index
 *                                              \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     Alert                        The currently determined alert description
 *  \param[in]     ValidStatusResponseReceived  If the OCSP response was received correctly or not
 *  \param[in,out] AlertDescriptionPtr          Pointer to the alert description which will be send by the ECU
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls_HandleAlertForOcspCertificateStatus(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsAlertDescriptionType Alert,
  boolean ValidStatusResponseReceived,
  TCPIP_P2V(TcpIp_TlsAlertDescriptionType) AlertDescriptionPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreUtil_TlsGetAlertForCertificateStatus
 *********************************************************************************************************************/
/*! \brief         Determine the correct alert description for the given certificate
 *  \details       -
 *  \param[in]     TlsCertValidationStatusIdx         Current index of the certificate.
 *  \return        TCPIP_TLS_ALERT_DESC_UNKNOWN_CA    Certificate is self-signed root
 *                 TCPIP_TLS_ALERT_DESC_CERT_EXPIRED  Certificate validity period check failed
 *                 TCPIP_TLS_ALERT_DESC_UNKNOWN_CA    Certificate contains invalid chain of trust
 *                 TCPIP_TLS_ALERT_DESC_CERT_REVOKED  Certificate is revoked
 *                 TCPIP_TLS_ALERT_DESC_BAD_CERT      Certificate is corrupted or signature validation fails
 *                 TCPIP_TLS_ALERT_UNSET              Certificate valid, no alert should be triggered
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(TcpIp_TlsAlertDescriptionType, TCPIP_CODE) TcpIp_TlsCoreUtil_TlsGetAlertForCertificateStatus(
  TcpIp_TlsCertValidationStatusDynIterType   TlsCertValidationStatusIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreUtil_TlsGetAlertForOcspCertificateStatus
 *********************************************************************************************************************/
/*! \brief         Determine the correct alert description for the OCSP certificate status
 *  \details       -
 *  \param[in]     TlsConIdx                                  TLS connection index
 *                                                            CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     TlsCertValidationStatusIdx                 Current index of the certificate.
 *  \return        TCPIP_TLS_ALERT_DESC_BAD_CERT_STATUS_RESP  OCSP was requested by the TLS Client,
 *                                                            but no OCSP Certificate Status response received
 *                 TCPIP_TLS_ALERT_DESC_CERT_REVOKED          Certificate is revoked
 *                 TCPIP_TLS_ALERT_UNSET                      Certificate valid, no alert should be triggered
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(TcpIp_TlsAlertDescriptionType, TCPIP_CODE) TcpIp_TlsCoreUtil_TlsGetAlertForOcspCertificateStatus(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsCertValidationStatusDynIterType TlsCertValidationStatusIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreUtil_TlsGetAlertForOcspResponseStatus
 *********************************************************************************************************************/
/*! \brief         Determine the correct alert description for the OCSP response status
 *  \details       -
 *  \param[in]     TlsConIdx                                  TLS connection index
 *                                                            CONSTRAINT: [0..TcpIp_GetSizeOfTlsConnection()-1]
 *  \param[in]     TlsCertValidationStatusIdx                 Current index of the certificate.
 *  \return        TCPIP_TLS_ALERT_DESC_BAD_CERT_STATUS_RESP  OCSP was requested by the TLS Client,
 *                                                            but no OCSP Certificate Status response received
 *                 TCPIP_TLS_ALERT_UNSET                      Certificate valid, no alert should be triggered
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(TcpIp_TlsAlertDescriptionType, TCPIP_CODE) TcpIp_TlsCoreUtil_TlsGetAlertForOcspResponseStatus(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsCertValidationStatusDynIterType TlsCertValidationStatusIdx);

/***********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_GetCurveFromPubKeyCurveElement
 *********************************************************************************************************************/
/*! \brief         Returns the used curve of the public key curve element of the certificate with the passed Id
 *  \details       -
 *  \param[in]     CertId                KeyM certificate identifier
 *  \param[out]    CurveIdPtr            Pointer to the found curve Id
 *  \return        E_OK                  A matching curve was found
 *  \return        E_NOT_OK              No matching curve was found
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUtil_GetCurveFromPubKeyCurveElement(
  TcpIp_CertificateIdType                   CertId,
  TCPIP_P2V(TcpIp_TlsEllipticCurveIdType)   CurveIdPtr);
# endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TLS RX BUFFER MANAGEMENT / DECRYPT
 *********************************************************************************************************************/
# if ( TCPIP_DEV_ERROR_DETECT == STD_ON )
/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_RxBufferIdxValidityCheck
 *********************************************************************************************************************/
/*! \brief         Validity checks for the dynamic TLS Rx buffer indices
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     CallPos             Position where the function is called
 *  \param[in]     ContentType         TLS content type
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_RxBufferIdxValidityCheck(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC)     CallPos,
  CONST(uint8, AUTOMATIC)     ContentType);
# endif

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_RxCheckAndRemovePadding
 *********************************************************************************************************************/
/*! \brief         If padding was received in the RL frame, check it and remove it from the Rx buffer
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType         TLS content type
 *  \return        E_OK                Padding is ok and removed
 *  \return        E_NOT_OK            Padding was not ok
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_RxCheckAndRemovePadding(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  CONST(uint8, AUTOMATIC)       ContentType);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_RxCipherDecryptHasPadding
 *********************************************************************************************************************/
/*! \brief         Check if the current decrypt algorithm supports padding or not.
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return        TRUE                The decrypt algorithm uses padding
 *  \return        FALSE               The decrypt algorithm does not use padding
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE)  TcpIp_TlsCoreRl_RxCipherDecryptHasPadding(
  TcpIp_TlsConnectionIterType   TlsConIdx);
# endif

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_RxAuthenticateFrame
 *********************************************************************************************************************/
/*! \brief         If a hash was received in the RL frame, check it and remove it from the Rx buffer
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType         TLS content type
 *  \param[in]     PrevWriteIdx        The Rx buffer WriteIdx before the current frame was decrypted
 *  \return        E_OK                The RL is authenticated
 *  \return        E_NOT_OK            The RL was not authenticated
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_RxAuthenticateFrame(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  CONST(uint8, AUTOMATIC)       ContentType,
  uint32                        PrevWriteIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_CheckIfCipherRequiresVerification
 *********************************************************************************************************************/
/*! \brief         Check if a hash must be verified when using the passed cipher
 *  \details       -
 *  \param[in]     Cipher              Cipher for which to find out if it requires verification
 *  \pre           -
 *  \return        TRUE                The algorithm of the passed cipher uses a separated hash verification
 *  \return        FALSE               The algorithm of the passed cipher does not use a separated hash verification
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsCoreRl_CheckIfCipherRequiresVerification(
  CONST(TcpIp_TlsCipherDataType, AUTOMATIC) Cipher);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_MoveDataOutOfReadMaxArea
 *********************************************************************************************************************/
/*! \brief         If applicable move the encrypted data behind the ReadMaxIdx to the start of the buffer
 *  \details       Always increment the Rx write index by the plaintext length (considering wraparound)
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType         TLS content type
 *  \param[in]     PlaintextLen        Length of the decrypted data
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE)  TcpIp_TlsCoreRl_MoveDataOutOfReadMaxArea(
  TcpIp_TlsConnectionIterType       TlsConIdx,
  CONST(uint8, AUTOMATIC)           ContentType,
  TcpIp_SizeOfTlsBufferRxType       PlaintextLen);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_GetActiveRxBlockSize
 *********************************************************************************************************************/
/*! \brief         Get the blocksize of the active decryption algorithm of a TLS-connection
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \return        TCPIP_TLS_BLOCK128_BLOCKSIZE              Active decryption algorithm uses a Block with 128 bit
 *  \return        TCPIP_TLS_NULL_BLOCKSIZE                  Active decryption algorithm is Null (no actual blocksize)
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(uint8, TCPIP_CODE)  TcpIp_TlsCoreRl_GetActiveRxBlockSize(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_GetAvailableLinearRxBufferSpace
 *********************************************************************************************************************/
/*! \brief         Calculate the size of the next available segment to write to in the TLS Rx Buffer.
 *  \details       Depending on the readIdx and writeIdx, calculate size of next free segment of TLS Rx Buffer.
 *                 This is not the total free space in the circular buffer but from the WriteIdx either to the ReadIdx
 *                 or to the end of the circular buffer.
 *  \param[in]     TlsConIdx         TLS connection index
 *                                   \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \return                          Size of the next free segment to write to in the TLS Rx AdHs buffer
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(TcpIp_SizeOfTlsBufferRxType, TCPIP_CODE)  TcpIp_TlsCoreRl_GetAvailableLinearRxBufferSpace(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  CONST(uint8, AUTOMATIC)       ContentType);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_SetRxWriteIdxForContentType
 *********************************************************************************************************************/
/*! \brief         Store the new Rx buffer WriteIdx depending on the passed content type. No validity check performed.
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType         TLS content type
 *  \param[in]     Value               New write index
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE)  TcpIp_TlsCoreRl_SetRxWriteIdxForContentType(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC)     ContentType,
  TcpIp_SizeOfTlsBufferRxType Value);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_GetRxEndIdxForContentType
 *********************************************************************************************************************/
/*! \brief         Get the Rx buffer EndTlsBufferTxIdx of a TLS-connection depending on content type
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType         TLS content type
 *  \return                            Rx buffer EndTlsBufferTxIdx
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(TcpIp_SizeOfTlsBufferRxType, TCPIP_CODE)  TcpIp_TlsCoreRl_GetRxEndIdxForContentType(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC)     ContentType);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_GetRxReadIdxForContentType
 *********************************************************************************************************************/
/*! \brief         Get the Rx buffer ReadIdx of a TLS-connection depending on content type
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType         TLS content type
 *  \return                            Rx buffer ReadIdx
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(TcpIp_SizeOfTlsBufferRxType, TCPIP_CODE)  TcpIp_TlsCoreRl_GetRxReadIdxForContentType(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC)     ContentType);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_GetRxWriteIdxForContentType
 *********************************************************************************************************************/
/*! \brief         Get the Rx buffer WriteIdx of a TLS-connection depending on content type
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType         TLS content type
 *  \return                            Rx buffer WriteIdx
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(TcpIp_SizeOfTlsBufferRxType, TCPIP_CODE)  TcpIp_TlsCoreRl_GetRxWriteIdxForContentType(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC)     ContentType);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_GetRxStartIdxForContentType
 *********************************************************************************************************************/
/*! \brief         Get the Rx buffer StartTlsBufferTxIdx of a TLS-connection depending on content type
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType         TLS content type
 *  \return                            Rx buffer StartTlsBufferTxIdx
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(TcpIp_SizeOfTlsBufferRxType, TCPIP_CODE)  TcpIp_TlsCoreRl_GetRxStartIdxForContentType(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  CONST(uint8, AUTOMATIC)       ContentType);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_DecryptIntoTlsRxBufferStep
 *********************************************************************************************************************/
/*! \brief         Perform one decryption step with data in the TCP segment.
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType         TLS content type
 *  \param[in]     TcpBufferSegPtr     Pointer to the TCP buffer segment containing the encrypted data
 *  \param[in]     AddDataSegPtr       Pointer to buffer segment containing additional data (in Aead case)
 *  \param[in]     AuthTagSegPtr       Pointer to buffer segment containing the authentication tag (in Aead case)
 *  \param[in]     CsmMode             Prepared CSM modes for this call (Modes might still be adapted in this function)
 *  \return        E_OK                Decryption step successfully executed
 *  \return        E_NOT_OK            Decryption step failed
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE)  TcpIp_TlsCoreRl_DecryptIntoTlsRxBufferStep(
  TcpIp_TlsConnectionIterType              TlsConIdx,
  CONST(uint8, AUTOMATIC)                  ContentType,
  TcpIp_ConstSegmentPtrType                TcpBufferSegPtr,
  TCPIP_P2C(TcpIp_SegmentType)             AddDataSegPtr,
  TCPIP_P2C(TcpIp_SegmentType)             AuthTagSegPtr,
  Crypto_OperationModeType                 CsmMode);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_DecryptTcpSegment
 *********************************************************************************************************************/
/*! \brief         Decrypt the data of a TCP segment stepwise. Not dependent on the decryption algorithm.
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType         TLS content type
 *  \param[in]     TcpBufferSegPtr     Pointer to the TCP buffer segment containing the encrypted data
 *  \param[in]     AddDataSegPtr       Pointer to buffer segment containing additional data (in Aead case)
 *  \param[in]     AuthTagSegPtr       Pointer to buffer segment containing the authentication tag (in Aead case)
 *  \param[in,out] CsmModePtr          Pointer to the current CSM modes
 *  \return        E_OK                Data in TCP segment successfully decrypted
 *  \return        E_NOT_OK            Decrypting data of TCP segment failed
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE)  TcpIp_TlsCoreRl_DecryptTcpSegment(
  TcpIp_TlsConnectionIterType          TlsConIdx,
  CONST(uint8, AUTOMATIC)              ContentType,
  TcpIp_ConstSegmentPtrType            TcpBufferSegPtr,
  TCPIP_P2C(TcpIp_SegmentType)         AddDataSegPtr,
  TCPIP_P2C(TcpIp_SegmentType)         AuthTagSegPtr,
  TCPIP_P2V(Crypto_OperationModeType)  CsmModePtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_DecryptPrepareCsmModeFlags
 *********************************************************************************************************************/
/*! \brief         Prepare the CSM mode flags for the next decryption step.
 *  \details       -
 *  \param[in]     TcpBufferSegPtr     Pointer to the current TCP buffer segment
 *  \param[in,out] CsmModePtr          Pointer to the current CSM modes. These are now adapted for the next call.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE)  TcpIp_TlsCoreRl_DecryptPrepareCsmModeFlags(
  TCPIP_P2C(TcpIp_ConstSegmentType)        TcpBufferSegPtr,
  TCPIP_P2V(Crypto_OperationModeType)      CsmModePtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_CalcDecryptLen
 *********************************************************************************************************************/
/*! \brief         Calculate the amount of encrypted data that shall be decrypted in this step.
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType         TLS content type
 *  \param[in]     Mode                The next CSM modes (Depending on the modes the amount of data to decrypt varies)
 *  \param[in,out] CryptLenPtr         When invoking this function This pointer shall point to the amount of data
 *                                     in the current TCP segment yet to be encrypted. It will be changed
 *                                     to the amount of data which shall be encrypted in the next step.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE)  TcpIp_TlsCoreRl_CalcDecryptLen(
  TcpIp_TlsConnectionIterType                 TlsConIdx,
  CONST(uint8, AUTOMATIC)                     ContentType,
  CONST(Crypto_OperationModeType, AUTOMATIC)  Mode,
  TCPIP_P2V(uint32)                           CryptLenPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_ResetRxDataSplit
 *********************************************************************************************************************/
/*! \brief         Reset the Rx data split element if necessary
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(void, TCPIP_CODE)  TcpIp_TlsCoreRl_ResetRxDataSplit(
  TcpIp_TlsConnectionIterType TlsConIdx);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_DecryptTcpSeg1
 *********************************************************************************************************************/
/*! \brief         Decrypt the data in TCP Segment 1
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType         TLS content type
 *  \param[in,out] CsmModePtr          Pointer to the CSM modes for the next decrypt call
 *                                     (the input is always start and update in the current implementation),
 *                                     these are adapted inside this function
 *  \param[in]     DecryptDataPtr      Pointer to the struct that contains all the required pointers to buffer segments
 *  \return        E_OK                Data in TCP segment 1 successfully decrypted
 *  \return        E_NOT_OK            Decrypting data of TCP segment 1 failed
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_DecryptTcpSeg1(
  TcpIp_TlsConnectionIterType          TlsConIdx,
  CONST(uint8, AUTOMATIC)              ContentType,
  TCPIP_P2V(Crypto_OperationModeType)  CsmModePtr,
  TCPIP_P2C(TcpIp_TlsDecryptDataType)  DecryptDataPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_DecryptTcpSegMix
 *********************************************************************************************************************/
/*! \brief         Decrypt data from the end of TCP segment 1 and from the start of TCP segment 2
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType         TLS content type
 *  \param[in,out] CsmModePtr          Pointer to the CSM modes for the next decrypt call, will be adapted if necessary
 *  \param[in]     DecryptDataPtr      Pointer to the struct that contains all the required pointers to buffer segments
 *  \return        E_OK                Data successfully decrypted
 *  \return        E_NOT_OK            Decrypting data failed
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_DecryptTcpSegMix(
  TcpIp_TlsConnectionIterType          TlsConIdx,
  CONST(uint8, AUTOMATIC)              ContentType,
  TCPIP_P2V(Crypto_OperationModeType)  CsmModePtr,
  TCPIP_P2C(TcpIp_TlsDecryptDataType)  DecryptDataPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_DecryptTcpSeg2
 *********************************************************************************************************************/
/*! \brief         Decrypt the data in TCP Segment 2
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType         TLS content type
 *  \param[in,out] CsmModePtr          Pointer to the CSM modes for the next decrypt call, will be adapted if necessary
 *  \param[in]     DecryptDataPtr      Pointer to the struct that contains all the required pointers to buffer segments
 *  \return        E_OK                Data in TCP segment 2 successfully decrypted
 *  \return        E_NOT_OK            Decrypting data of TCP segment 2 failed
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_DecryptTcpSeg2(
  TcpIp_TlsConnectionIterType          TlsConIdx,
  CONST(uint8, AUTOMATIC)              ContentType,
  TCPIP_P2V(Crypto_OperationModeType)  CsmModePtr,
  TCPIP_P2C(TcpIp_TlsDecryptDataType)  DecryptDataPtr);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_AddRlHeaderForRxAuthentication
 *********************************************************************************************************************/
/*! \brief         Get RL Rx sequence counter, reconstruct the RL header of the received message
 *                 and call CSM Mac Verify job with it
 *  \details       -
 *  \param[in]     TlsConIdx           TLS connection index
 *                                     \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType         TLS content type
 *  \param[in]     DataLen             Length of the data of this RL
 *  \return        E_OK                Mac Verify job was successful
 *  \return        E_NOT_OK            Mac Verify job was NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_AddRlHeaderForRxAuthentication(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  CONST(uint8, AUTOMATIC)       ContentType,
  uint32                        DataLen);

/**********************************************************************************************************************
 * TcpIp_TlsCoreRl_AddDecryptedDataForRxAuthentication
 *********************************************************************************************************************/
/*! \brief         Get received decrypted data from the Rx buffer and call CSM Mac Verify job with it
 *  \details       CSM Mac Verify also gets the received HMAC which was copied to a local buffer
 *  \param[in]     TlsConIdx                    TLS connection index
 *                                              \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
 *  \param[in]     ContentType                  TLS content type
 *  \param[in]     PrevWriteIdx                 The Rx buffer WriteIdx before the current frame was decrypted
 *  \param[in]     ReceivedMacSegPtr            Pointer to buffer segment where received HMAC is located
 *  \return        E_OK                Mac Verify job was successful
 *  \return        E_NOT_OK            Mac Verify job was NOT successful
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_AddDecryptedDataForRxAuthentication(
  TcpIp_TlsConnectionIterType         TlsConIdx,
  CONST(uint8, AUTOMATIC)             ContentType,
  CONST(uint32, AUTOMATIC)            PrevWriteIdx,
  TCPIP_P2C(TcpIp_ConstSegmentType)   ReceivedMacSegPtr);


# if (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCore_ReturnIpBufferForNssFrame
 *********************************************************************************************************************/
 /*! \brief         Returns a pointer to an ethernet buffer for sending a UDP package
  *  \details       -
  *  \param[in]     TlsConIdx            TLS connection index
  *                                      \spec requires TlsConIdx < TcpIp_GetSizeOfTlsConnection(); \endspec
  *  \param[in,out] IpBufferPtrPtr       Double pointer to the IP buffer
  *  \param[in]     RequestedIpBufferLen The requested length of the IP buffer
  *  \param[in,out] IpTxReqestDescrPtr   The pointer to the description of the IP request
  *  \pre           -
  *  \context       TASK
  *  \reentrant     FALSE
  *  \synchronous   TRUE
  *********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCore_ReturnIpBufferForNssFrame(
  TcpIp_TlsConnectionIterType                TlsConIdx,
  TCPIP_P2V(TcpIp_Uint8P2V)                  IpBufferPtrPtr,
  uint16                                     RequestedIpBufferLen,
  TCPIP_P2V(TcpIp_IpTxRequestDescriptorType) IpTxReqestDescrPtr);
# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TLS CORE UPPER LAYER (UL)
 *********************************************************************************************************************/
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreUl_TcpConnected
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreUl_TcpConnected(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SocketDynIterType socketIdx = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_SocketOwnerConfigIterType socketOwnerCfgIdx = TcpIp_GetSocketOwnerConfigIdxOfSocketDyn(socketIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Forward call to TcpIp */
  TcpIp_Tcp_TlsConnected(socketIdx);

  /* AUTOSAR requires additional event notification to the upper layer */
  TcpIp_Tls_TcpIpEventCallout(socketOwnerCfgIdx, socketIdx, TCPIP_TLS_HANDSHAKE_SUCCEEDED);

} /* TcpIp_TlsCoreUl_TcpConnected() */
# endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUl_RxIndication
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreUl_RxIndication(
  TcpIp_TlsConnectionIterType       TlsConIdx,
  TCPIP_P2V(uint8)                  DataPtr,
  uint32                            DataLenByte)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SocketDynIterType socketIdx = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /*
     When this function is called, there is some new unforwarded data in TLS Rx AdHs buffer
           TLS Rx AdHs buffer
        [     xxxxxx*****      ]
              r     u    w

     Unforwarded data = (w -u)
     Data previously forwarded = (u - r)

     After function call, all new data in TLS Rx AdHs buffer has been forwarded
           TLS Rx AdHs buffer
        [     xxxxxxxxxxx      ]
              r         w
                        u
  */
  if (socketIdx < TcpIp_GetSizeOfSocketDyn())
  {
    /* #10 Check if the number of bytes to be forwarded to Ul is smaller than the maximum RX-Indication length */
    if (DataLenByte <= TCPIP_RX_INDICATION_LEN_MAX)
    {
      /*#20 if so, forward the indication to UL (Socket owner) */
      TcpIp_RxIndicationFunctions(socketIdx, TcpIp_GetAddrRemSockOfSocketDyn(socketIdx), DataPtr, (uint16)DataLenByte);
      /* Increment the UlRxIndicationPos with the data that was forwarded */
      TcpIp_TlsCoreRl_IncrementUlRxIndIdxWithWraparound(TlsConIdx, DataLenByte);
    }
    else
    {
      /* #30 otherwise, split the indication into multiple parts and forward the indication to UL (Socket owner) */
      uint16 rxConfLen;
      uint32 remainingRxConfLen = DataLenByte;
      /* Iterate over all given data */
      while (remainingRxConfLen > 0u)
      {
        if (remainingRxConfLen > TCPIP_RX_INDICATION_LEN_MAX)
        {
          rxConfLen = (uint16)TCPIP_RX_INDICATION_LEN_MAX;
        }
        else
        {
          rxConfLen = (uint16)remainingRxConfLen;
        }
        /* Forward indication to UL */
        TcpIp_RxIndicationFunctions(socketIdx, TcpIp_GetAddrRemSockOfSocketDyn(socketIdx), DataPtr, rxConfLen);

        /* Update the Ul RxIndication index with the rxConfLen */
        TcpIp_TlsCoreRl_IncrementUlRxIndIdxWithWraparound(TlsConIdx, rxConfLen);

        /* #40 subtract the already confirmed data */
        remainingRxConfLen -= rxConfLen;
      } /* while */

    }
# if ( TCPIP_DEV_ERROR_DETECT == STD_ON )
    /* Store the current Rx indices and perform some basic range checks */
    TcpIp_TlsCoreRl_RxBufferIdxValidityCheck(TlsConIdx, TCPIP_TLS_CALL_POS_FORWARD, TCPIP_TLS_CT_AD);
# endif
  }
  else
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
  }
} /* TcpIp_TlsCoreUl_RxIndication() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUl_Received
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreUl_Received(
  TcpIp_SocketDynIterType    SocketIdx,
  uint32                     DataLenByte,
  TCPIP_P2V(uint8)           ErrorIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsConnectionIterType tlsConIdx = TcpIp_GetSizeOfTlsConnection();
  uint8 errorId = TCPIP_E_NO_ERROR;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Select the Tls connection of the socket, and update the Tls Ul read index if connection is in state to receive data */
  if ((TcpIp_SocketIdxToTlsConIdx(SocketIdx, &tlsConIdx) == E_OK) && (tlsConIdx < TcpIp_GetSizeOfTlsConnection()))
  {
    /* When the FIN flag was set in the received TCP segment the connection state is close_wait.
     * In this state application data is still forwarded to the upper layer.
     * The same holds for the connection state if a TcpIp_Close is triggered (Abort=True or Abort=False) */
    if (   ((TcpIp_GetConnectionStateOfTlsConnectionDyn(tlsConIdx)) == (TCPIP_TLS_STATE_CONNECTION_ESTABLISHED))        /* PRQA S 3415 5 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
       ||  ((TcpIp_GetConnectionStateOfTlsConnectionDyn(tlsConIdx)) == (TCPIP_TLS_STATE_CONNECTION_CLOSE_WAIT))
       ||  ((TcpIp_GetConnectionStateOfTlsConnectionDyn(tlsConIdx)) == (TCPIP_TLS_STATE_CONNECTION_USER_RESET_REQUESTED))
       ||  ((TcpIp_GetConnectionStateOfTlsConnectionDyn(tlsConIdx)) == (TCPIP_TLS_STATE_CONNECTION_CLOSE_WITH_CLOSENOTIFY_FIN_REQUESTED))
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
       ||  ((TcpIp_GetConnectionStateOfTlsConnectionDyn(tlsConIdx)) == (TCPIP_TLS_STATE_CONNECTION_13_CLOSENOTIFY_SENT))
# endif
       )
    {
      TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(tlsConIdx);

      /* Check if the data length read by Ul fits the Tls buffer size */
      if (DataLenByte < TcpIp_GetTlsBufferRxAdHsLengthOfTlsBufferMgmt(tlsBufferMgmtIdx))
      {
        TcpIp_AddRxUpperlayerReleasedDataLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, DataLenByte);
      }
      else
      {
        /* otherwise, invalid function call */
        errorId = TCPIP_E_INV_ARG;
      }
    }
    else
    {
      /* otherwise, invalid function call */
      errorId = TCPIP_E_INV_ARG;
    }
  }

  /* Set the errorId */
  *ErrorIdPtr = errorId;
} /* TcpIp_TlsCoreUl_Received() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUl_Transmit
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
/* PRQA S 6050, 6080 1 */ /* MD_TcpIp_STCAL_CslAccess, MD_MSR_STMIF */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUl_Transmit(
  TcpIp_SizeOfSocketDynType SocketIdx,
  TCPIP_P2C(uint8)          DataPtr,
  uint32                    Length,
  boolean                   ForceRetrieve)
{
/*
 * Concept:
 * The main usecase here is the application data, which should be transmitted. Therefore the user (socketOwner) can call
 * TcpIp_TcpTransmit either with a direct dataPtr, or with an NULL Ptr, so that the TcpIp calls the users configured
 * CopyTxData. In both ways, the Tls takes care of the wraparound in the TlsBufferTx. The transmission of the data will
 * then take place within the next main function of the Tls ( via TcpIp_TlsCoreMainFunction_TxAd()).
 */

  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsConnectionIterType tlsConIdx = TcpIp_GetSizeOfTlsConnection();
  Std_ReturnType retVal = E_NOT_OK;
  uint32 dynLength = Length;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the corresponding TLS-Connection index for this socket */
  if ((TcpIp_SocketIdxToTlsConIdx(SocketIdx, &tlsConIdx) == E_OK) && (tlsConIdx < TcpIp_GetSizeOfTlsConnection()))
  {
    TcpIp_TlsConnectionState state = TcpIp_GetConnectionStateOfTlsConnectionDyn(tlsConIdx);

    /* #20 Check if there is a TLS connection already established or a TCP-FIN was received or a CloseNotify Alert was
       received (in case of TLS 1.3) */
    if (   (state == TCPIP_TLS_STATE_CONNECTION_ESTABLISHED)
        || (state == TCPIP_TLS_STATE_CONNECTION_CLOSE_WAIT)
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
        || (state == TCPIP_TLS_STATE_CONNECTION_13_CLOSENOTIFY_RECEIVED)
# endif
       )
    {
      /* Remaining space available in TLS Tx AdHs buffer */
      uint32 remainingSpaceInAdHsBuffer = 0u;

      /* #30 Enter critical section */
      TCPIP_VENTER_CRITICAL_SECTION();

      if (TcpIp_TlsCoreBuffer_GetAvailableTxBufferSize(SocketIdx, &remainingSpaceInAdHsBuffer) == E_OK)
      {
# ifdef COMMENT_VECTOR  /* ESCAN00110353 - next check, impl version 15.06.00 */
# endif
        /* #40 Reduce datalength when not enough buffer is available and retrieve is not forced */
        /* Return E_NOT_OK when buffer is completely filled */
        if (   (ForceRetrieve == FALSE)
            && (DataPtr == NULL_PTR)
            && (dynLength > remainingSpaceInAdHsBuffer)
            && (remainingSpaceInAdHsBuffer > 0u))
        {
          dynLength = remainingSpaceInAdHsBuffer;
        }

        /* #50 Check if we can accept the transmit request */
        if (   (dynLength <= remainingSpaceInAdHsBuffer)
            && (remainingSpaceInAdHsBuffer != 0u))
        {
          /* #60 Forward the data (direct/indirect) to CopyTxFunctions */
          if (DataPtr != NULL_PTR)
          {
            /* Forward the call to direct data provision function */
            TcpIp_TlsCoreUl_CopyTxDataDirect(tlsConIdx, DataPtr, dynLength);
            retVal = E_OK;
          }
          else
          {
            /* Forward the call to indirect data provision function */
            retVal = TcpIp_TlsCoreUl_CopyTxDataIndirect(tlsConIdx, dynLength, SocketIdx);
          }
        }
        else if ((remainingSpaceInAdHsBuffer == 0u) && (ForceRetrieve == FALSE))
        {
          /* if no Buffer is available the call was ok, but no data shall be copied. */
          retVal = E_OK;
        }
        else
        {
          /* Nothing to do */
        }
      } /* else - retVal already E_NOT_OK */

      /* #70 Leave critical section */
      TCPIP_VLEAVE_CRITICAL_SECTION();
    }
  }
  return retVal;
} /* TcpIp_TlsCoreUl_Transmit() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUl_CopyTxDataDirect
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050, 6080 1 */ /* MD_TcpIp_STCAL_CslAccess, MD_MSR_STMIF */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreUl_CopyTxDataDirect(
    TcpIp_TlsConnectionIterType TlsConIdx,
    TCPIP_P2C(uint8)            SourceDataPtr,
    CONST(uint32, AUTOMATIC)    SourceDataLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferTxAdHsEndIdxOfTlsBufferMgmtType endTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  TcpIp_TlsBufferTxAdHsStartIdxOfTlsBufferMgmtType startTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType txBufferWriteIdx =
    TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Verify the start and end index of the TX buffer to guarantee a proper calculation of the buffer length. */
  /* \trace TCASE-TCPIP_000725 */
  if (TcpIp_VerifyStartAndEndIndex(startTlsBufferTxIdx, endTlsBufferTxIdx, TcpIp_GetSizeOfTlsBufferTx()) == E_OK)
  {
    uint32 txBufferLen = (uint32)endTlsBufferTxIdx - startTlsBufferTxIdx;
    uint32 txBufferOffset = (uint32)txBufferWriteIdx - startTlsBufferTxIdx;

    /* #20 Treat the TX buffer as a ring buffer and write the data starting at the write index. */
    TcpIp_RingBufferCpySafe(TcpIp_GetAddrTlsBufferTx(startTlsBufferTxIdx), txBufferOffset, txBufferLen,                 /* VCA_TCPIP_TLS_VERIFIED_START_END_IDX */
      SourceDataPtr, SourceDataLen);

    /* #30 Adjust the write index. This function will wraparound the write index if necessary. */
    TcpIp_TlsCoreUl_IncrementTlsBufferTxAdHsWriteIdxWithWraparound(TlsConIdx, SourceDataLen);
  }
  /* else not necessary, Det is called in TcpIp_VerifyStartAndEndIndex already when E_NOT_OK is returned */
} /* TcpIp_TlsCoreUl_CopyTxDataDirect() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUl_CopyTxDataIndirect
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUl_CopyTxDataIndirect(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint32                      SourceDataLen,
  TcpIp_SizeOfSocketDynType   SocketIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferTxAdHsEndIdxOfTlsBufferMgmtType endTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  TcpIp_TlsBufferTxAdHsStartIdxOfTlsBufferMgmtType startTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType writeTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  /* Pointer to TLS segment 1 */
  TCPIP_P2V(uint8) tlsSeg1Ptr;
  /* Length of TLS segment 1 */
  uint32 tlsSeg1Len;
  /* Pointer to TLS segment 2 */
  TCPIP_P2V(uint8) tlsSeg2Ptr;
  /* Length of TLS segment 2 */
  uint32 tlsSeg2Len;

  TcpIp_SizeOfSocketTcpDynType  socketTcpIdx = TCPIP_SOCKET_IDX_TO_TCP_IDX(SocketIdx);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* \trace TCASE-TCPIP_000737 */
  if (socketTcpIdx < TcpIp_GetSizeOfSocketTcpDyn())
  {
    /* Ensure that the SourceDataLen is smaller as the corresponding buffer and the writeIdx is in a valid range. */
    /* \trace TCASE-TCPIP_000738 */
    /* \trace TCASE-TCPIP_000739 */
    if ((SourceDataLen <= ((uint32)endTlsBufferTxIdx - (uint32)startTlsBufferTxIdx)) && (writeTlsBufferTxIdx < endTlsBufferTxIdx))
    {
      /* #10 Check if new data will cause TLS Tx buffer wraparound */
      /* \trace TCASE-TCPIP_000740 */
      if ((writeTlsBufferTxIdx + (uint64)SourceDataLen) <= endTlsBufferTxIdx)
      {
        /* Data can be entirely copied into TLS segment 1 */
        tlsSeg1Ptr = TcpIp_GetAddrTlsBufferTx(writeTlsBufferTxIdx);
        tlsSeg1Len = SourceDataLen;
        /*@ assert $lengthOf(tlsSeg1Ptr) >= tlsSeg1Len; */                                                              /* VCA_TCPIP_TLS_COPY_TX_DATA_FIRST_PAIR */

        /* No need for TLS segment 2 */
        tlsSeg2Ptr = NULL_PTR;
        tlsSeg2Len = 0;
        /*@ assert (tlsSeg2Ptr == NULL_PTR) && (tlsSeg2Len == 0); */                                                    /* VCA_TCPIP_TLS_COPY_TX_DATA_SECOND_PAIR_NULL_PTR */

        /* #20 Data fits linearized into TLS segment 1 - 1 copy call */
        /* Before:
          *  W               W            W               W      W              W
          * [-------] or [-------] or [xxx----] or [---xxx-] or [----xxx] or [xx---xx]
          *  R               R         R               R             R             R
          *
          * After:
          *      W              W            W      W               W             W
          * [****---] or [---***-] or [xxx***-] or [---xxx*] or [***-xxx] or [xx**-xx]
          *  R               R         R               R             R             R
          */

        /* Forward the call to the internal copy function */
        retVal = TcpIp_TlsCoreUl_CopyTxDataIndirectWithWraparound(socketTcpIdx, tlsSeg1Ptr,                             /* VCA_TCPIP_TLS_COPY_TX_DATA */
          &tlsSeg1Len, tlsSeg2Ptr, &tlsSeg2Len, FALSE);
      }
      /* \trace TCASE-TCPIP_000741 */
      else
      {
        /* #30 Wraparound of TxBuffer - 2 copy calls */
        /* Before:
          *      W              W
          * [-------] or [---xxx-]
          *      R           R
          *
          * After
          *    W            W
          * [**--***] or [**-xxx*]
          *      R           R
          */

        /* Ciphertext will be be copied to both TLS segment 1 and 2 */
        tlsSeg1Ptr = TcpIp_GetAddrTlsBufferTx(writeTlsBufferTxIdx);
        tlsSeg1Len = ((uint32)endTlsBufferTxIdx - writeTlsBufferTxIdx);
        /*@ assert $lengthOf(tlsSeg1Ptr) >= tlsSeg1Len; */                                                              /* VCA_TCPIP_TLS_COPY_TX_DATA_FIRST_PAIR_WRAPAROUND */

        /* Second call range is StartTlsBufferTxIdx until remaining data */
        tlsSeg2Ptr = TcpIp_GetAddrTlsBufferTx(startTlsBufferTxIdx);
        tlsSeg2Len = ((TcpIp_SizeOfTlsBufferTxType)SourceDataLen - tlsSeg1Len);
        /*@ assert $lengthOf(tlsSeg2Ptr) >= tlsSeg2Len; */                                                              /* VCA_TCPIP_TLS_COPY_TX_DATA_SECOND_PAIR_WRAPAROUND */

        /* Forward the call to the internal copy function */
        retVal = TcpIp_TlsCoreUl_CopyTxDataIndirectWithWraparound(socketTcpIdx, tlsSeg1Ptr,                             /* VCA_TCPIP_TLS_COPY_TX_DATA */
          &tlsSeg1Len, tlsSeg2Ptr, &tlsSeg2Len, FALSE);
      }

      /* #40 Adjust the WriteIdx. This function will wraparound the WriteIdx */
      if (retVal == E_OK)
      {
        TcpIp_TlsCoreUl_IncrementTlsBufferTxAdHsWriteIdxWithWraparound(TlsConIdx, (tlsSeg1Len + tlsSeg2Len));
      }
    }
  }

  return retVal;

} /* TcpIp_TlsCoreUl_CopyTxDataIndirect() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUl_CopyTxDataIndirectWithWraparound()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6060, 6080 1 */ /* MD_TcpIp_TlsPointerAndLength_STPAR_6060, MD_MSR_STMIF */
TCPIP_LOCAL_INLINE FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUl_CopyTxDataIndirectWithWraparound(
  TcpIp_SizeOfSocketTcpDynType SocketTcpIdx,
  TCPIP_P2V(uint8)             DstChunk1Ptr,
  TCPIP_P2V(uint32)            DstChunk1LenPtr,
  TCPIP_P2V(uint8)             DstChunk2Ptr,
  TCPIP_P2V(uint32)            DstChunk2LenPtr,
  CONST(boolean, AUTOMATIC)    UseTlsCopyTxData)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType            retVal       = E_NOT_OK;
  TcpIp_SizeOfSocketDynType socketIdx    = TCPIP_TCP_IDX_TO_SOCKET_IDX(SocketTcpIdx);
  uint16                    copyLen;

  TCPIP_ASSERT(SocketTcpIdx < TcpIp_GetSizeOfSocketTcpDyn());

  /* ----- Implementation ----------------------------------------------- */
  copyLen = (uint16)*DstChunk1LenPtr;

  /* #10 Copy first chunk of data at the end of buffer. */
  if (TcpIp_CopyTxDataFunctions(socketIdx, DstChunk1Ptr, &copyLen, UseTlsCopyTxData) == BUFREQ_OK)                      /* VCA_TCPIP_TLS_COPY_TX_DATA_FUNCTIONS */
  {
    /* #20 Update *LengthPtr if user provided less data. */
    if (copyLen < *DstChunk1LenPtr)
    {
      /* user provided less data than requested.
      -> data provision complete. */
      *DstChunk1LenPtr = copyLen;
      *DstChunk2LenPtr = 0u;
      retVal = E_OK;
    }
    else if (copyLen > *DstChunk1LenPtr)
    {
      /* user provided more data than requested. */
      retVal = E_NOT_OK;
    }
    /* #30 Copy second chunk at the beginning of buffer, if required. */
    else if ((DstChunk2Ptr != NULL_PTR) && (*DstChunk2LenPtr != 0u))
    {
      copyLen = (uint16)*DstChunk2LenPtr;

      if (TcpIp_CopyTxDataFunctions(socketIdx, DstChunk2Ptr, &copyLen, UseTlsCopyTxData) == BUFREQ_OK)                  /* VCA_TCPIP_TLS_COPY_TX_DATA_FUNCTIONS */
      {
        if (copyLen <= *DstChunk2LenPtr)
        {
          /* #40 Update *DstChunk2LenPtr depending on bytes copied */
          *DstChunk2LenPtr = copyLen;
          retVal = E_OK;
        }
        else
        {
          /* user provided more data than requested */
          retVal = E_NOT_OK;
        }
      }
      /* else: user aborted transmit */
    }
    else
    {
      /* all data was provided in a single chunk. */
      *DstChunk2LenPtr = 0u;
      retVal = E_OK;
    }
  }
  /* else: user aborted transmit */

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUl_IncrementTlsBufferTxAdHsWriteIdxWithWraparound
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreUl_IncrementTlsBufferTxAdHsWriteIdxWithWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint32                      Value)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferTxAdHsEndIdxOfTlsBufferMgmtType txBufferEndIdx =
    TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  TcpIp_TlsBufferTxAdHsStartIdxOfTlsBufferMgmtType txBufferStartIdx =
    TcpIp_GetTlsBufferTxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType txBufferWriteIdx =
    TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  uint32 newWriteIndex = 0u;
  /* #10 Adjust the write index. This function will wraparound the write index if necessary. */
  /* The return value can be ignored here since the indices must be correct. */
  (void)TcpIp_GetIncrementedRingBufferIndex((uint32)txBufferWriteIdx, Value,
    (uint32)txBufferStartIdx, (uint32)txBufferEndIdx, &newWriteIndex);
  TcpIp_SetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
    (TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType)newWriteIndex);
  /* #20 Adjust the Application data fill level by adding the copied bytes */
  TcpIp_AddAdTxFillLevelOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, (TcpIp_SizeOfTlsBufferTxType)Value);
} /* TcpIp_TlsCoreUl_IncrementTlsBufferTxAdHsWriteIdxWithWraparound() */

# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCore_GetNextFreeTlsClientConnection
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCore_GetNextFreeTlsClientConnection(
  TcpIp_SizeOfSocketDynType SocketIdx,
  uint16 RemotePort,
  TCPIP_P2V(TcpIp_TlsConnectionIterType)    TlsConIdxPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  TcpIp_TlsConnectionIterType tlsConIdx;

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_VENTER_CRITICAL_SECTION();

  /* #10 Get the index of the TLS connection which shall be used for connection assignment. */
  tlsConIdx = TcpIp_TlsClient_GetTlsConnectionIndexForConnectionAssignment(SocketIdx, RemotePort);

  /* #20 If there is a connection free and matching, prepare parameters. */
  if (tlsConIdx < TcpIp_GetSizeOfTlsConnection())
  {
    *TlsConIdxPtr = tlsConIdx;
    TcpIp_SetSocketDynComIdxOfTlsConnectionDyn(tlsConIdx, SocketIdx);
    TcpIp_SetTlsConnectionIdxOfSocketTcpDyn(TCPIP_SOCKET_IDX_TO_TCP_IDX(SocketIdx), (TcpIp_SizeOfTlsConnectionDynType) tlsConIdx);
    TcpIp_SetConnectionStateOfTlsConnectionDyn(tlsConIdx, TCPIP_TLS_STATE_CONNECTION_ALLOCATED);
    retVal = E_OK;
  }

  TCPIP_VLEAVE_CRITICAL_SECTION();

  return retVal;
} /* TcpIp_TlsCore_GetNextFreeTlsClientConnection() */
# endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsCore_IsTlsConnectionUsedByPortAndFree
 *********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
 *
 *
  */
FUNC(boolean, TCPIP_CODE) TcpIp_TlsCore_IsTlsConnectionUsedByPortAndFree(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint16, AUTOMATIC) UsedPort)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the port of the given TLS connection matches and if the connection is already used. */
  if (TcpIp_GetPortOfTlsConnection(TlsConIdx) == UsedPort)
  {
    /* Depending if this is a Client or Server connection a different value has to be checked. */
    if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
    {
      if (TcpIp_GetSocketDynListenIdxOfTlsConnectionDyn(TlsConIdx) == TCPIP_NO_SOCKETDYNLISTENIDXOFTLSCONNECTIONDYN)
      {
        /* #20 This TLS connection is not in use - return TRUE. */
        retVal = TRUE;
      }
    }
    else /* TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_CLIENT */
    {
      if (TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx) == TCPIP_NO_SOCKETDYNCOMIDXOFTLSCONNECTIONDYN)
      {
        /* #30 This TLS connection is not in use - return TRUE. */
        retVal = TRUE;
      }
    }
  }

  return retVal;
} /* TcpIp_TlsCore_IsTlsConnectionUsedByPortAndFree() */

/**********************************************************************************************************************
 *  TcpIp_TlsCore_ChangeParameter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCore_ChangeParameter(
  TcpIp_SizeOfSocketTcpDynType SocketTcpIdx,
  uint8                        OptName,
  TCPIP_P2C(uint8)             OptValPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Forward the change parameter request to the corresponding functions depending on the given OptName */
  switch (OptName)
  {
    case TCPIP_PARAMID_TLS_CONNECTION_ASSIGNMENT:
    {
      retVal = TcpIp_TlsCoreChangeParameter_ConnectionAssignment(SocketTcpIdx, OptValPtr);
      break;
    }
    case TCPIP_PARAMID_TLS_CONNECTIONBASED_SESSION_RESUMPTION:
    {
      retVal = TcpIp_TlsCoreChangeParameter_SessionResumption(SocketTcpIdx, OptValPtr);
      break;
    }
    default:                                                                                                              /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
    {
      /* Default case left blank intentionally - Check is performed in caller function */
      break;
    }
  }

  return retVal;
} /* TcpIp_TlsCore_ChangeParameter() */

/**********************************************************************************************************************
 *  TLS CORE CHANGE PARAMETER
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreChangeParameter_ConnectionAssignment
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreChangeParameter_ConnectionAssignment(
  TcpIp_SizeOfSocketTcpDynType SocketTcpIdx,
  TCPIP_P2C(uint8)             TlsConIdxPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  TcpIp_SizeOfSocketDynType socketIdx = TCPIP_TCP_IDX_TO_SOCKET_IDX(SocketTcpIdx);
  /* AUTOSAR missed to specify (SWS_TcpIp) the type used for the TLS connection ID. We define it as uint16. */
  TcpIp_TlsConnectionDynIterType tlsConIdx = (TcpIp_TlsConnectionDynIterType)TCPIP_GET_UINT16_RAW(TlsConIdxPtr, 0u);

  /* #10 Allocate a TLS connection for the socket if possible (TlsConIdx exists, Tls connection not yet in use, ...) */
  if (TcpIp_Tls_AllocateConnection(socketIdx, tlsConIdx) == E_OK)
  {
    TcpIp_SetUseTlsOfSocketTcpDyn(SocketTcpIdx, TRUE);
    retVal = E_OK;
  }

  return retVal;
} /* TcpIp_TlsCoreChangeParameter_ConnectionAssignment() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreChangeParameter_SessionResumption
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreChangeParameter_SessionResumption(
  TcpIp_SizeOfSocketTcpDynType SocketTcpIdx,
  TCPIP_P2C(uint8)             ResumptionBaseSocketIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* Attention: ChangeParameter must use a uint16 for the socket id of the resumption base socket!! */
  TcpIp_SocketIdType resumptionBaseSocketId = (TcpIp_SocketIdType)TCPIP_GET_UINT16_RAW(ResumptionBaseSocketIdPtr, 0u);

  TCPIP_ASSERT(TCPIP_SOCKET_ID_IS_VALID(resumptionBaseSocketId));
  TcpIp_SizeOfSocketDynType resumptionBaseSocketIdx = TCPIP_SOCKET_ID_TO_IDX(resumptionBaseSocketId);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check for valid socket indexes and if they are configured for TLS. */
  if (TCPIP_SOCKET_IDX_IS_TCP(resumptionBaseSocketIdx))
  {
    TcpIp_SizeOfSocketTcpDynType resumptionBaseSocketTcpIdx = TCPIP_SOCKET_IDX_TO_TCP_IDX(resumptionBaseSocketIdx);

    if (   (TcpIp_IsUseTlsOfSocketTcpDyn(SocketTcpIdx) == TRUE)
        && (TcpIp_IsUseTlsOfSocketTcpDyn(resumptionBaseSocketTcpIdx) == TRUE))                                          /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
    {
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      /* #20 Request the usage of session resumption. */
      retVal = TcpIp_Tls13Client_RequestUsageOfSessionResumption(SocketTcpIdx, resumptionBaseSocketTcpIdx);
#  endif
# endif
    }
  }

  return retVal;
} /* TcpIp_TlsCoreChangeParameter_SessionResumption() */

/**********************************************************************************************************************
 *  TLS CORE CONTENT TYPE (CT)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_ProcessMsg
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
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtHs_ProcessMsg(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  uint32 expectedHsMsgLen = 0; /* Holds the message length information peeked from HS-Header */

  /* ----- Implementation ----------------------------------------------- */
 /* #10 Check that we received the complete message - will return E_OK if message is received completely */
  if (TcpIp_TlsCoreCtHs_VerifyMsgCompleteness(TlsConIdx, &expectedHsMsgLen) == E_OK)
  {
    /* Message is received completely */
    /* #20 Check if we can forward the complete message to HS state machine */
    if (TcpIp_TlsCoreCtHs_ValidateAndForwardMessageToHsHandler(TlsConIdx, expectedHsMsgLen) == E_OK)
    {
      TcpIp_TlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDynType rxAdHsWriteIdx
        = TcpIp_GetTlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
      TcpIp_TlsBufferRxAdHsCurrHsMsgEndIdxOfTlsBufferMgmtDynType currentHsMsgEndIdx
        = TcpIp_GetTlsBufferRxAdHsCurrHsMsgEndIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

      /* #30 Only if we processed the complete RL-Frame (which could contain multiple HS messages) we reset the RL RxIndication flag */
      /* If there are any further messages contained in this RL-Frame the currentHsMsgEndIdx is smaller then the WriteIdx */
      if (currentHsMsgEndIdx >= rxAdHsWriteIdx)
      {
        /* There are no further messages in this RL-Frame so we can reset the trigger */
        TcpIp_TlsCore_ResetRlRxIndicationFlag(TlsConIdx, TCPIP_TLS_CT_HS);
      }
    }
    else
    {
      /* #40 In case we received an invalid HS message, report the error to the user */
      TcpIp_TlsCoreCtHs_HandleInvalidHsMessage(TlsConIdx);
    }
  } /* else - no complete message received - nothing to do */
} /* TcpIp_TlsCoreCtHs_ProcessMsg() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_VerifyMsgCompleteness
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_VerifyMsgCompleteness(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint32) HsMsgLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDynType rxAdHsWriteIdx
    = TcpIp_GetTlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType rxAdHsReadIdx
    = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  TcpIp_TlsBufferRxAdHsStartIdxOfTlsBufferMgmtType rxAdHsStartIdx
    = TcpIp_GetTlsBufferRxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  TcpIp_TlsBufferRxAdHsCurrHsMsgEndIdxOfTlsBufferMgmtDynType currentHsEndIdx
    = TcpIp_GetTlsBufferRxAdHsCurrHsMsgEndIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType currentMsgLenInBuffer = (rxAdHsWriteIdx - rxAdHsReadIdx);

  Std_ReturnType retVal = E_NOT_OK;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check that we received at least 4 Bytes to peek the length of the received message */
  if (currentMsgLenInBuffer >= (TCPIP_TLS_HSLEN_LEN + TCPIP_TLS_CONTENT_LENGTH_OFFSET))
  {
    /* #20 Process the message if it is the first received message OR the processing of the last received message is done */
    if (   (rxAdHsReadIdx == rxAdHsStartIdx)
        || (   (rxAdHsReadIdx == currentHsEndIdx)
            && (TcpIp_GetHsRxIndicationCntOfTlsConnectionDyn(TlsConIdx) == 0u)))                                        /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
    {
      /* Read the actual message size from the received HS message */
      retVal = TcpIp_TlsCoreCtHs_ReadMsgLenFromHsMsg(TlsConIdx, HsMsgLenPtr);
    }
    /* else - nothing to do - leave retVal E_NOT_OK */
  }
  /* else - nothing to do - leave retVal E_NOT_OK */
  return retVal;
} /* TcpIp_TlsCoreCtHs_VerifyMsgCompleteness() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_ReadMsgLenFromHsMsg
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_ReadMsgLenFromHsMsg(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint32) HsMsgLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDynType writeTlsBufferRxIdx
    = TcpIp_GetTlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType readTlsBufferRxIdx
    = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType currentDataLenInBuffer = (writeTlsBufferRxIdx - readTlsBufferRxIdx);
  Std_ReturnType retVal = E_NOT_OK;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Peek the length of the received TLS-Handshake message */

  /* Peek the length of the current received handshake message */
  *HsMsgLenPtr = IpBase_GetUint24(TcpIp_GetAddrTlsBufferRx(readTlsBufferRxIdx), TCPIP_TLS_CONTENT_LENGTH_OFFSET);

  /* #20 Check if we received the complete TLS-Handshake message */
  if (((uint32)currentDataLenInBuffer - (uint32)TCPIP_TLS_HSHDRLEN) >= *HsMsgLenPtr)
  {
    /* Complete message has been received */

    /* Update the current Hs message end index */
    TcpIp_SetTlsBufferRxAdHsCurrHsMsgEndIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
      (TcpIp_TlsBufferRxAdHsCurrHsMsgEndIdxOfTlsBufferMgmtDynType)((uint32)readTlsBufferRxIdx + TCPIP_TLS_HSHDRLEN + *HsMsgLenPtr));

    retVal = E_OK;
  }
  else
  {
    /* Handshake message only received partly */
    /* HsMsgLen is not used in any further context, but set it to zero. */
    *HsMsgLenPtr = 0u;
  }

  return retVal;
} /* TcpIp_TlsCoreCtHs_ReadMsgLenFromHsMsg() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_ValidateAndForwardMessageToHsHandler
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_ValidateAndForwardMessageToHsHandler(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint32, AUTOMATIC) HsMsgLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  boolean skipThisMessage = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Validate the received Handshake type and trigger the Handshake RX-Indication */
  if (TcpIp_TlsCoreCtHs_ValidateTypeField(TlsConIdx, HsMsgLen, &skipThisMessage) == E_OK)
  {
    if (skipThisMessage == TRUE)
    {
      /* Valid type field received, but message should be skipped. No RxIndication */
    }
    else
    {
      /* Valid type field received, so inform upper layer about new received HS message */
      TcpIp_TlsCoreCtHs_RxIndication(TlsConIdx);
    }
    retVal = E_OK;
  }


  return retVal;
} /* TcpIp_TlsCoreCtHs_ValidateAndForwardMessageToHsHandler() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_ValidateTypeField
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_ValidateTypeField(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint32, AUTOMATIC) HsMsgLen,
  TCPIP_P2V(boolean) SkipThisMessagePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the received type is valid */
  if (TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivable(TlsConIdx) == E_OK)
  {
    /* #20 Check that the received type has not been received before */
    if (TcpIp_TlsCoreCtHs_CheckForDuplicateMessages(TlsConIdx) == E_OK)
    {
      /* #30 Check that the current Handshake type is in a valid order */
      if (TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedType(TlsConIdx) == E_OK)
      {
        /* #40 Update the type information for the received message */
        if (TcpIp_TlsCoreCtHs_UpdateTypeInformation(TlsConIdx, HsMsgLen, SkipThisMessagePtr) == E_OK)
        {
          /* #50 Handshake message processed, return E_OK */
          retVal = E_OK;
        }
      }
    }
  }

  return retVal;
} /* TcpIp_TlsCoreCtHs_ValidateTypeField() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivable
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivable(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the received TLS handshake type is valid for the configured connection (Server/Client/TLS version) */
  if (TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivableInThisConnection(TlsConIdx) == E_OK)
  {
    /* #20 Check if the received TLS handshake type is valid for the active TLS version */
    if (TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivableInActiveTlsVersion(TlsConIdx) == E_OK)                                 /* PRQA S 2991, 2995 */ /* MD_TcpIp_Tls_2991_2995 */
    {
      /* #30 Check if the received TLS handshake type is valid for the current key exchange */
      retVal = TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivableInThisKeyExchange(TlsConIdx);
    }
  }

  return retVal;
} /* TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivable() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivableInThisConnection
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivableInThisConnection(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType readTlsBufferRxIdx
    = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  uint8 currentReceivedHsType = TcpIp_GetTlsBufferRx(readTlsBufferRxIdx);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the received TLS handshake type is valid for the configured connection (Server/Client) */
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
#  endif
  {
    /* Mode == TCPIP_TLS_SERVER */
    /* Only 1.2 connections supported currently */
    if (   (currentReceivedHsType == TCPIP_TLS_HSTYPE_CLIENTHELLO)
        || (currentReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATE)  /* client certificate */
        || (currentReceivedHsType == TCPIP_TLS_HSTYPE_CLIENTKEYEXCHANGE)
        || (currentReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATEVERIFY)
        || (currentReceivedHsType == TCPIP_TLS_HSTYPE_FINISHED))
    {
      /* #20 Valid type for TLS 1.2 Server connection - return E_OK */
      retVal = E_OK;
    }
  }
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  else
#  endif
# endif
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  {
    /* Mode == TCPIP_TLS_CLIENT */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    if (TcpIp_IsTlsSupportVersion12OfTlsConnection(TlsConIdx) == TRUE)
#   endif
    {
      if (   (currentReceivedHsType == TCPIP_TLS_HSTYPE_SERVERHELLO)
          || (currentReceivedHsType == TCPIP_TLS_HSTYPE_HELLOREQUEST)
          || (currentReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATE)
          || (currentReceivedHsType == TCPIP_TLS_HSTYPE_SERVERKEYEXCHANGE)
          || (currentReceivedHsType == TCPIP_TLS_HSTYPE_SERVERHELLODONE)
          || (currentReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST)
          || (currentReceivedHsType == TCPIP_TLS_HSTYPE_FINISHED)
          || (currentReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATESTATUS))
      {
        /* #30 Valid type for TLS 1.2 Client connection - return E_OK */
        retVal = E_OK;
      }
    }
#  endif
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
    if (TcpIp_IsTlsSupportVersion13OfTlsConnection(TlsConIdx) == TRUE)
#   endif
    {
      if (TcpIp_IsSessionResumptionUsingPskOfTlsConnectionDyn(TlsConIdx) == TRUE)
      {
        if (   (currentReceivedHsType == TCPIP_TLS_HSTYPE_SERVERHELLO)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_NEWSESSIONTICKET)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_ENCRYPTEDEXTENSIONS)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_FINISHED))
        {
          /* #40 Valid type for TLS 1.3 Client PSK connection - return E_OK */
          retVal = E_OK;
        }
      }
      else
      {
        if (   (currentReceivedHsType == TCPIP_TLS_HSTYPE_SERVERHELLO)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_NEWSESSIONTICKET)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_ENCRYPTEDEXTENSIONS)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATE)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATEVERIFY)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_FINISHED))
        {
          /* #50 Valid type for TLS 1.3 Client ECC connection - return E_OK */
          retVal = E_OK;
        }
      }
    }
#  endif
  }
# endif

  if (retVal != E_OK)
  {
    /* In case of invalid or unknown type - report error */
    TcpIp_TlsUserErrorType hsTypeUserError;
    hsTypeUserError.FunctionId = TCPIP_TLS_FCTID_CORE_CTHS_CHECKFRAMETYPE;
    hsTypeUserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_INCORRECTFRAMETYPE;
    hsTypeUserError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(hsTypeUserError);
  }

  return retVal;
} /* TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivableInThisConnection() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivableInActiveTlsVersion
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivableInActiveTlsVersion(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType readTlsBufferRxIdx
    = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  uint8 currentReceivedHsType = TcpIp_GetTlsBufferRx(readTlsBufferRxIdx);
# else
  TCPIP_DUMMY_STATEMENT_CONST(TlsConIdx);                                                                               /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the received TLS handshake type is valid for the configured connection (Server/Client) */
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
#  endif
  {
    /* For the server an active version is not relevant yet, since only 1.2 is supported right now. */
    /* #20 Return E_OK for the server. */
    retVal = E_OK;
  }
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  else
#  endif
# endif
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  {
    /* Mode == TCPIP_TLS_CLIENT */
    switch (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx))
    {
      case TCPIP_TLSVERSION_NOTSET:
      {
        if (   (currentReceivedHsType == TCPIP_TLS_HSTYPE_SERVERHELLO)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_HELLOREQUEST))
        {
          /* #30 Valid type for when the active TLS version is not set yet (before ServerHello is parsed). */
          retVal = E_OK;
        }
        break;
      }
#  if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      case TCPIP_TLSVERSION_12:
      {
        if (   (currentReceivedHsType == TCPIP_TLS_HSTYPE_HELLOREQUEST)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATE)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_SERVERKEYEXCHANGE)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_SERVERHELLODONE)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_FINISHED)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATESTATUS))
        {
          /* Return E_OK for messages which can be received after TLS 1.2 is negotiated with the ServerHello. */
          /* #40 Valid type for when the active TLS version is TLS 1.2. */
          retVal = E_OK;
        }
        break;
      }
#  endif
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      case TCPIP_TLSVERSION_13:
      {
        if (   (currentReceivedHsType == TCPIP_TLS_HSTYPE_NEWSESSIONTICKET)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_ENCRYPTEDEXTENSIONS)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATE)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATEVERIFY)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_FINISHED))
        {
          /* Return E_OK for messages which can be received after TLS 1.3 is negotiated with the ServerHello. */
          /* #50 Valid type for when the active TLS version is TLS 1.3. */
          retVal = E_OK;
        }
        break;
      }
#  endif
      default:                                                                                                           /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
      {
        TCPIP_ASSERT_UNREACHABLE();
        break;
      } /* default */
    } /* switch() */

    if (retVal != E_OK)
    {
      /* In case of invalid or unknown type - report error */
      TcpIp_TlsUserErrorType hsTypeUserError;
      hsTypeUserError.FunctionId = TCPIP_TLS_FCTID_CORE_CTHS_CHECKFRAMETYPE;
      hsTypeUserError.UserErrorId = TCPIP_TLS_ERRORID_CTHS_INCORRECTFRAMETYPE;
      hsTypeUserError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

      TcpIp_TlsCoreError_ReportUserError(hsTypeUserError);
    }
  }
# endif

  return retVal;
} /* TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivableInActiveTlsVersion() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivableInThisKeyExchange
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivableInThisKeyExchange(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType readTlsBufferRxIdx
    = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  uint8 currentReceivedHsType = TcpIp_GetTlsBufferRx(readTlsBufferRxIdx);

  TcpIp_TlsKeyExchangeMethodDataType keyExchangeMethod
    = TcpIp_TlsCoreUtil_ReturnActiveCipherSpecificKeyExchangeMethod(TlsConIdx);

  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* TcpIp_TlsCoreUtil_ReturnActiveCipherSpecificKeyExchangeMethod() returns TCPIP_TLS_KEYEXCHANGE_METHOD_INVALID
   * when no active cipherworker is set yet.
   * In this case the key exchange is not clear yet and therefore specific messages can't be excluded. Return E_OK.*/
  if (keyExchangeMethod != TCPIP_TLS_KEYEXCHANGE_METHOD_INVALID)
  {
    /* #10 Check if the received TLS handshake type is valid for the current key exchange. */
    switch (keyExchangeMethod)
    {
      case TCPIP_TLS_KEYEXCHANGE_METHOD_PSK_PLAIN:
      {
        /* PSK does not support certificate handling,
         * therefore the certificate, the certificate status and the certificate request message are not receivable. */
        if (   (currentReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATE)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST)
            || (currentReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATESTATUS))
        {
          retVal = E_NOT_OK;
        }
        break;
      } /* case TCPIP_TLS_KEYEXCHANGE_METHOD_PSK_PLAIN */
      case TCPIP_TLS_KEYEXCHANGE_METHOD_ECDH:
      {
        /* When using an ECDH key exchange the ServerKeyExchange message is omitted. */
        if (currentReceivedHsType == TCPIP_TLS_HSTYPE_SERVERKEYEXCHANGE)
        {
          retVal = E_NOT_OK;
        }
        break;
      } /* case TCPIP_TLS_KEYEXCHANGE_METHOD_ECDH */
      case TCPIP_TLS_KEYEXCHANGE_METHOD_ECDHE:
      {
        /* When using an ECDHE key exchange we can't exclude a message. */
        break;
      } /* case TCPIP_TLS_KEYEXCHANGE_METHOD_ECDHE */
      default:
      {
        /* Other key exchanges are not implemented right now. */
        retVal = E_NOT_OK;
        break;
      }
    } /* switch */
  } /* else: No active cipherworker set yet, return E_OK.
     * That the first message is either the Server Hello or the Client Hello
     * is validated in TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedType()
     * and therefore does not need to be checked here. */

  return retVal;
} /* TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivableInThisKeyExchange() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_CheckForDuplicateMessages
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030, 6050 1 */ /* MD_TcpIp_TlsStatemachine_STCYC_6030, MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_CheckForDuplicateMessages(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);
# endif

# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);
# endif

  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType readTlsBufferRxIdx
    = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  uint8 currentReceivedHsType = TcpIp_GetTlsBufferRx(readTlsBufferRxIdx);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the received TLS handshake type has not been received before */
  switch (currentReceivedHsType)
  {
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
    case TCPIP_TLS_HSTYPE_CLIENTHELLO:
    {
      /* Check if the received message is the first received Client Hello */
      retVal = (   TcpIp_GetTlsBufferRxClientHelloIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx)
                == TCPIP_NO_TLSBUFFERRXCLIENTHELLOIDXOFTLSSERVERBUFFERMGMT) ? E_OK : E_NOT_OK;
      break;
    } /* case TCPIP_TLS_HSTYPE_CLIENTHELLO */
# endif

# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
    case TCPIP_TLS_HSTYPE_SERVERHELLO:
    {
      /* Check if the received message is the first received Server Hello */
      retVal = (   TcpIp_GetTlsBufferRxServerHelloIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx)
                == TCPIP_NO_TLSBUFFERRXSERVERHELLOIDXOFTLSCLIENTBUFFERMGMT) ? E_OK : E_NOT_OK;
      break;
    } /* case TCPIP_TLS_HSTYPE_SERVERHELLO */

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    case TCPIP_TLS_HSTYPE_ENCRYPTEDEXTENSIONS:
    {
      /* Check if the received message is the first received Encrypted Extensions */
      retVal = (   TcpIp_GetTlsBufferRxEncryptedExtensionsIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx)
                == TCPIP_NO_TLSBUFFERRXENCRYPTEDEXTENSIONSIDXOFTLSCLIENTBUFFERMGMT)  ? E_OK : E_NOT_OK;
      break;
    } /* case TCPIP_TLS_HSTYPE_ENCRYPTEDEXTENSIONS */
#  endif /* TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON */
# endif /* TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON */

    case TCPIP_TLS_HSTYPE_CERTIFICATE:
    {
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
      if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_CLIENT)
      {
        /* Check if the received message is the first received Server Certificate */
        retVal = (   TcpIp_GetTlsBufferRxServerCertificatesIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx)
                  == TCPIP_NO_TLSBUFFERRXSERVERCERTIFICATESIDXOFTLSCLIENTBUFFERMGMT) ? E_OK : E_NOT_OK;
      }
# endif
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
      if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
      {
        /* Check if the received message is the first received Client Certificate */
        retVal = (   TcpIp_GetTlsBufferRxClientCertificateIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx)
                  == TCPIP_NO_TLSBUFFERRXCLIENTCERTIFICATEIDXOFTLSSERVERBUFFERMGMT) ? E_OK : E_NOT_OK;
      }
# endif
      break;
    } /* case TCPIP_TLS_HSTYPE_CERTIFICATE */

# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
    case TCPIP_TLS_HSTYPE_CERTIFICATESTATUS:
    {
      /* Check if the received message is the first received Certificate Status */
      retVal = (   TcpIp_GetTlsBufferRxServerCertificateStatusIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx)
                == TCPIP_NO_TLSBUFFERRXSERVERCERTIFICATESTATUSIDXOFTLSCLIENTBUFFERMGMT) ? E_OK : E_NOT_OK;
      break;
    } /* TCPIP_TLS_HSTYPE_CERTIFICATESTATUS */
#  endif /* TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
    case TCPIP_TLS_HSTYPE_SERVERKEYEXCHANGE:
    {
      /* Check if the received message is the first received Server Key Exchange */
      retVal = (   TcpIp_GetTlsBufferRxServerKeyExchangeIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx)
                == TCPIP_NO_TLSBUFFERRXSERVERKEYEXCHANGEIDXOFTLSCLIENTBUFFERMGMT) ? E_OK : E_NOT_OK;
      break;
    } /* case TCPIP_TLS_HSTYPE_SERVERKEYEXCHANGE */
#  endif /* TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON */

    case TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST:
    {
      /* Check if the received message is the first received Certificate Request */
      retVal = (   TcpIp_GetTlsBufferRxServerCertificateRequestIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx)
                == TCPIP_NO_TLSBUFFERRXSERVERCERTIFICATEREQUESTIDXOFTLSCLIENTBUFFERMGMT) ? E_OK : E_NOT_OK;
      break;
    } /* case TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST */

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
    case TCPIP_TLS_HSTYPE_SERVERHELLODONE:
    {
      /* Check if the received message is the first received Server Hello Done */
      retVal = (   TcpIp_GetTlsBufferRxServerHelloDoneIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx)
                == TCPIP_NO_TLSBUFFERRXSERVERHELLODONEIDXOFTLSCLIENTBUFFERMGMT) ? E_OK : E_NOT_OK;
      break;
    } /* case TCPIP_TLS_HSTYPE_SERVERHELLODONE */
#  endif /* TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON */

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
    case TCPIP_TLS_HSTYPE_HELLOREQUEST:
    {
      /* A Hello Request message can be received multiple times */
      retVal = E_OK;
      break;
    } /* case TCPIP_TLS_HSTYPE_HELLOREQUEST */
#  endif /* TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON */
# endif /* TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON */

    case TCPIP_TLS_HSTYPE_CERTIFICATEVERIFY:
    {
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_CLIENT)
      {
        /* Check if the received message is the first received Server Certificate Verify */
        retVal = (TcpIp_GetTlsBufferRxServerCertificateVerifyIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx)
               == TCPIP_NO_TLSBUFFERRXSERVERCERTIFICATEVERIFYIDXOFTLSCLIENTBUFFERMGMT) ? E_OK : E_NOT_OK;
      }
#  endif /* TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON */
# endif /* TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON */
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
      if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
      {
        /* Check if the received message is the first received Client Certificate Verify */
        retVal = (TcpIp_GetTlsBufferRxClientCertificateVerifyIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx)
               == TCPIP_NO_TLSBUFFERRXCLIENTCERTIFICATEVERIFYIDXOFTLSSERVERBUFFERMGMT) ? E_OK : E_NOT_OK;
      }
# endif /* TCPIP_SUPPORT_ASRTLSSERVER == STD_ON */
      break;
    } /* case TCPIP_TLS_HSTYPE_CERTIFICATEVERIFY */

# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
    case TCPIP_TLS_HSTYPE_CLIENTKEYEXCHANGE:
    {
      /* Check if the received message is the first received Client Key Exchange */
      retVal = (   TcpIp_GetTlsBufferRxClientKeyExchangeIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx)
                == TCPIP_NO_TLSBUFFERRXCLIENTKEYEXCHANGEIDXOFTLSSERVERBUFFERMGMT) ? E_OK : E_NOT_OK;
      break;
    } /* case TCPIP_TLS_HSTYPE_CLIENTKEYEXCHANGE */
# endif

    case TCPIP_TLS_HSTYPE_FINISHED:
    {
      /* Server and client share the finished message - check which message is received */
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
      if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
      {
        /* Check if the received message is the first received Client Finished */
        retVal = (   TcpIp_GetTlsBufferRxClientFinishedIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx)
                  == TCPIP_NO_TLSBUFFERRXCLIENTFINISHEDIDXOFTLSSERVERBUFFERMGMT) ? E_OK : E_NOT_OK;
      }
# endif /* (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON) */
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
      if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_CLIENT)
      {
        /* Check if the received message is the first received Server Finished */
        retVal = (   TcpIp_GetTlsBufferRxServerFinishedIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx)
                 == TCPIP_NO_TLSBUFFERRXSERVERFINISHEDIDXOFTLSCLIENTBUFFERMGMT) ? E_OK : E_NOT_OK;
      }
# endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */
      break;
    } /* case TCPIP_TLS_HSTYPE_FINISHED */

    default:
    {
      /* Invalid type is checked by function TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivableInThisConnection */
      retVal = E_NOT_OK;
      break;
    }
  } /* switch */

  return retVal;
} /* TcpIp_TlsCoreCtHs_CheckForDuplicateMessages() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedType
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedType(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Check if the received TLS handshake type is in order to the last received type */
  switch (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx))
  {
    case TCPIP_TLSVERSION_NOTSET:  /* hello messages */
    {
      /* While receiving the hello message, the active TLS version is not yet set. */
      retVal = TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedTypeProtXx(TlsConIdx);
      break;
    }
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
    case TCPIP_TLSVERSION_12:  /* TLS 1.2 handshake messages */
    {
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
      if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_CLIENT)
#   endif
      {
        /* TLS 1.2 Client */
        /* Validate the order of the received handshake messages for the TLS 1.2 client. */
        retVal = TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedTypeClient12(TlsConIdx);
      }
#   if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
      else
#   endif
#  endif
#  if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
      {
        /* TLS 1.2 Server */
        /* Validate the order of the received handshake messages for the TLS 1.2 server. */
        retVal = TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedTypeServer12(TlsConIdx);
      }
#  endif
      break;
    }
# endif
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    case TCPIP_TLSVERSION_13:  /* TLS 1.3 handshake messages */
    {
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
      if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_CLIENT)
#   endif
      {
        /* TLS 1.3 Client */
        /* Validate the order of the received handshake messages for the TLS 1.3 client. */
        retVal = TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedTypeClient13(TlsConIdx);
      }
#   if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
      else
#   endif
#  endif
#  if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
      {
        /* TLS 1.3 Server */
        /* Error, there is no support for TLS 1.3 server implemented */
      }
#  endif
      break;
    }
# endif
    default:
    {
      /* This is not a valid case and may never occur. */
      break;
    }
  }

  if (retVal != E_OK)
  {
    /* #20 We received an invalid order of Handshake messages and we have to trigger a TLS alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
  }

  return retVal;
} /* TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedType() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedTypeProtXx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedTypeProtXx(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType readTlsBufferRxIdx
    = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  uint8 currentReceivedHsType = TcpIp_GetTlsBufferRx(readTlsBufferRxIdx);
  uint8 lastReceivedHsType = TcpIp_GetLastReceivedHsTypeOfTlsConnectionDyn(TlsConIdx);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* This function is called for all TLS protocol versions, and for client and server connections. */

  /* #10 Check the different receivable messages and their preconditions. */
  switch (currentReceivedHsType)
  {
    case TCPIP_TLS_HSTYPE_CLIENTHELLO:
    {
      /* #20 Check if the ClientHello message is received after an allowed preceding message. */
      if (lastReceivedHsType == TCPIP_TLS_HSTYPE_INVALID)  /* no preceding message */
      {
        retVal = E_OK;
      }
      break;
    }
    case TCPIP_TLS_HSTYPE_SERVERHELLO:
    {
      /* #30 Check if the ServerHello message is received after an allowed preceding message. */
      /* Received messages of type TCPIP_TLS_HSTYPE_HELLOREQUEST are always ignored and not stored as last received
      type. Therefore no check for this type is necessary. */
      if (lastReceivedHsType == TCPIP_TLS_HSTYPE_INVALID)  /* no preceding message */
      {
        retVal = E_OK;
      }
      break;
    }
    case TCPIP_TLS_HSTYPE_HELLOREQUEST:
    {
      /* #40 Check if the HelloRequest message is received after an allowed preceding message. */
      /* The HelloRequest message may be received at any time during the handshake. */
      retVal = E_OK;
      break;
    }
    default:
    {
      /* Not supported message received */
      break;
    }
  }  /* switch */

  return retVal;
}

# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedTypeClient12
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030 1 */ /* MD_TcpIp_TlsStatemachine_STCYC_6030 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedTypeClient12(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType readTlsBufferRxIdx
    = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  uint8 currentReceivedHsType = TcpIp_GetTlsBufferRx(readTlsBufferRxIdx);
  uint8 lastReceivedHsType = TcpIp_GetLastReceivedHsTypeOfTlsConnectionDyn(TlsConIdx);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */

  /* This function is only called for TLS 1.2 Client connections. */

  /* Received messages of type TCPIP_TLS_HSTYPE_HELLOREQUEST are always ignored and not stored as last received type.
     Therefore no check for this type is necessary. */

  /* #10 Check the different receivable messages and their preconditions. */
  switch (currentReceivedHsType)
  {
    case TCPIP_TLS_HSTYPE_CERTIFICATE:
    {
      /* Check if the ServerCertificate message is received after the ServerHello message. */
      if (lastReceivedHsType == TCPIP_TLS_HSTYPE_SERVERHELLO)
      {
        retVal = E_OK;
      }
      break;
    }
    case TCPIP_TLS_HSTYPE_CERTIFICATESTATUS:
    {
      /* Check if the ServerCertificateStatus message is received after the ServerCertificate message. */
      if (lastReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATE)
      {
        retVal = E_OK;
      }
      break;
    }
    case TCPIP_TLS_HSTYPE_SERVERKEYEXCHANGE:
    {
      /* Check if the ServerKeyExchange message is received after the CertificateStatus or ServerCertificate or ServerHello message. */
      if (   (lastReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATESTATUS)  /* connection with OCSP */
          || (lastReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATE)  /* connection without OCSP */
          || (lastReceivedHsType == TCPIP_TLS_HSTYPE_SERVERHELLO)  /* connection with PSK */
        )
      {
        retVal = E_OK;
      }
      break;
    }
    case TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST:
    {
      /* Check if the CertificateRequest message is received after an allowed preceding message. */
      if (   (lastReceivedHsType == TCPIP_TLS_HSTYPE_SERVERKEYEXCHANGE)  /* connection with ECDHE */
          || (lastReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATESTATUS)  /* connection with OCSP */
          || (lastReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATE)  /* connection without OCSP */
        )
      {
        retVal = E_OK;
      }
      break;
    }
    case TCPIP_TLS_HSTYPE_SERVERHELLODONE:
    {
      /* Check if the CertificateRequest message is received after an allowed preceding message. */
      if (   (lastReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST)  /* connection with ECDH(E) and client authentication */
          || (lastReceivedHsType == TCPIP_TLS_HSTYPE_SERVERKEYEXCHANGE)  /* connection with ECDHE or PSK */
          || (lastReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATESTATUS)  /* connection with ECDH and with OCSP */
          || (lastReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATE)  /* connection with ECDH and without OCSP */
          || (lastReceivedHsType == TCPIP_TLS_HSTYPE_SERVERHELLO)  /* connection with PSK */
        )
      {
        retVal = E_OK;
      }
      break;
    }
    case TCPIP_TLS_HSTYPE_FINISHED:
    {
      /* Check if the ServerFinished message is received after the ServerHelloDone message and if a CCS was received
      before. */
      if (   (lastReceivedHsType == TCPIP_TLS_HSTYPE_SERVERHELLODONE)
          && (TcpIp_IsCcsReceivedOfTlsConnectionDyn(TlsConIdx) == TRUE))                                                /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
      {
        retVal = E_OK;
      }
      break;
    }
    case TCPIP_TLS_HSTYPE_HELLOREQUEST:
    {
      /* Check if the HelloRequest message is received after an allowed preceding message. */
      /* The HelloRequest message my be received at any time during the handshake. */
      retVal = E_OK;
      break;
    }
    default:
    {
      /* Not supported message received */
      break;
    }
  }  /* switch */

  return retVal;
}
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
# endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */

# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedTypeServer12
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedTypeServer12(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType readTlsBufferRxIdx
    = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  uint8 currentReceivedHsType = TcpIp_GetTlsBufferRx(readTlsBufferRxIdx);
  uint8 lastReceivedHsType = TcpIp_GetLastReceivedHsTypeOfTlsConnectionDyn(TlsConIdx);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */

  /* This function is only called for TLS 1.2 Server connections. */

  /* #10 Check the different receivable messages and their preconditions. */
  switch (currentReceivedHsType)
  {
    case TCPIP_TLS_HSTYPE_CERTIFICATE:
    {
      /* Check if the ClientCertificate message is received after the ClientHello message. */
      if (lastReceivedHsType == TCPIP_TLS_HSTYPE_CLIENTHELLO)
      {
        retVal = E_OK;
      }
      break;
    }
    case TCPIP_TLS_HSTYPE_CLIENTKEYEXCHANGE:
    {
      /* Check if the ClientKeyExchange message is received after an allowed preceding message. */
      if (   (lastReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATE)  /* connection with client authentication */
          || (lastReceivedHsType == TCPIP_TLS_HSTYPE_CLIENTHELLO)  /* connection without client authentication */
        )
      {
        retVal = E_OK;
      }
      break;
    }
    case TCPIP_TLS_HSTYPE_CERTIFICATEVERIFY:
    {
      /* Check if the ClientCertificateVerify message is received after the ClientKeyExchange message. */
      if (lastReceivedHsType == TCPIP_TLS_HSTYPE_CLIENTKEYEXCHANGE)
      {
        retVal = E_OK;
      }
      break;
    }
    case TCPIP_TLS_HSTYPE_FINISHED:
    {
      /* Check if the ClientFinished message is received after an allowed preceding message. */
      if (   (   (lastReceivedHsType == TCPIP_TLS_HSTYPE_CLIENTKEYEXCHANGE)
              || (lastReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATEVERIFY))
          && (TcpIp_IsCcsReceivedOfTlsConnectionDyn(TlsConIdx) == TRUE))                                                /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
      {
        retVal = E_OK;
      }
      break;
    }
    default:
    {
      /* Not supported message received */
      break;
    }
  }  /* switch */

  return retVal;
}
# endif

# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedTypeClient13
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030 1 */ /* MD_TcpIp_TlsStatemachine_STCYC_6030 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_ValidateOrderOfReceivedTypeClient13(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType readTlsBufferRxIdx
    = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  uint8 currentReceivedHsType = TcpIp_GetTlsBufferRx(readTlsBufferRxIdx);
  uint8 lastReceivedHsType = TcpIp_GetLastReceivedHsTypeOfTlsConnectionDyn(TlsConIdx);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */

  /* This function is only called for TLS 1.3 Client connections. */

  /* #10 Check the different receivable messages and their preconditions. */
  switch (currentReceivedHsType)
  {
    case TCPIP_TLS_HSTYPE_ENCRYPTEDEXTENSIONS:
    {
      /* Check if the EncryptedExtensions message is received after the ServerHello message. */
      if (lastReceivedHsType == TCPIP_TLS_HSTYPE_SERVERHELLO)
      {
        retVal = E_OK;
      }
      break;
    }
    case TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST:
    {
      /* Check if the CertificateRequest message is received after the EncryptedExtensions message. */
      if (lastReceivedHsType == TCPIP_TLS_HSTYPE_ENCRYPTEDEXTENSIONS)
      {
        retVal = E_OK;
      }
      break;
    }
    case TCPIP_TLS_HSTYPE_CERTIFICATE:
    {
      /* Check if the ServerCertificate message is received after the EncryptedExtensions or CertificateRequest message. */
      if (   (lastReceivedHsType == TCPIP_TLS_HSTYPE_ENCRYPTEDEXTENSIONS)
          || (lastReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST))
      {
        retVal = E_OK;
      }
      break;
    }
    case TCPIP_TLS_HSTYPE_CERTIFICATEVERIFY:
    {
      /* Check if the ServerCertificateVerify message is received after the ServerCertificate message. */
      if (lastReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATE)
      {
        retVal = E_OK;
      }
      break;
    }
    case TCPIP_TLS_HSTYPE_FINISHED:
    {
      /* Check if the ServerFinished message is received after the ServerCertificateVerify
       * or the EncryptedExtensions message. */
      if (   (lastReceivedHsType == TCPIP_TLS_HSTYPE_CERTIFICATEVERIFY)
          || (lastReceivedHsType == TCPIP_TLS_HSTYPE_ENCRYPTEDEXTENSIONS))
      {
        retVal = E_OK;
      }
      break;
    }
    case TCPIP_TLS_HSTYPE_NEWSESSIONTICKET:
    {
      /* Check if the NewSessionTicket message is received
       * after the ServerFinished or NewSessionTicket or KeyUpdate message. */
      if (   (lastReceivedHsType == TCPIP_TLS_HSTYPE_FINISHED)
          || (lastReceivedHsType == TCPIP_TLS_HSTYPE_NEWSESSIONTICKET)
          || (lastReceivedHsType == TCPIP_TLS_HSTYPE_KEYUPDATE))
      {
        retVal = E_OK;
      }
      break;
    }
    case TCPIP_TLS_HSTYPE_KEYUPDATE:
    {
      /* Check if the KeyUpdate message is received after the ServerFinished or NewSessionTicket or KeyUpdate message. */
      if (   (lastReceivedHsType == TCPIP_TLS_HSTYPE_FINISHED)
          || (lastReceivedHsType == TCPIP_TLS_HSTYPE_NEWSESSIONTICKET)
          || (lastReceivedHsType == TCPIP_TLS_HSTYPE_KEYUPDATE))
      {
        retVal = E_OK;
      }
      break;
    }
    default:
    {
      /* Not supported message received */
      break;
    }
  }  /* switch */

  return retVal;
}
#  endif
# endif

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_UpdateTypeInformation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050 1 */ /* MD_TcpIp_TlsStatemachine_STPTH_6010, MD_TcpIp_TlsStatemachine_STCYC_6030, MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtHs_UpdateTypeInformation(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint32, AUTOMATIC) HsMsgLen,
  TCPIP_P2V(boolean) SkipThisMessagePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
  TcpIp_TlsServerBufferMgmtIterType tlsServerBufferMgmtIdx
    = TcpIp_GetTlsServerBufferMgmtIdxOfTlsConnection(TlsConIdx);
# endif

# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  TcpIp_TlsClientBufferMgmtIterType tlsClientBufferMgmtIdx
    = TcpIp_GetTlsClientBufferMgmtIdxOfTlsConnection(TlsConIdx);
# endif

  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType readTlsBufferRxIdx
    = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn( tlsBufferMgmtIdx);

  uint8 currentReceivedHsType = TcpIp_GetTlsBufferRx(readTlsBufferRxIdx);
  Std_ReturnType retVal       = E_OK;
  *SkipThisMessagePtr = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Update the Start indices and length information for the given handshake type message */
  switch (currentReceivedHsType)
  {

# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
    case TCPIP_TLS_HSTYPE_CLIENTHELLO:
    {
      TcpIp_SetTlsBufferRxClientHelloIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, readTlsBufferRxIdx);
      TcpIp_SetClientHelloLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, (uint16)HsMsgLen);
      TcpIp_SetLastReceivedHsTypeOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_HSTYPE_CLIENTHELLO);
      break;
    } /* case TCPIP_TLS_HSTYPE_CLIENTHELLO */
# endif /* TCPIP_SUPPORT_ASRTLSSERVER == STD_ON */

# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
    case TCPIP_TLS_HSTYPE_SERVERHELLO:
    {
      TcpIp_SetTlsBufferRxServerHelloIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, readTlsBufferRxIdx);
      TcpIp_SetServerHelloLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, (uint16)HsMsgLen);
      TcpIp_SetLastReceivedHsTypeOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_HSTYPE_SERVERHELLO);
      break;
    } /* case TCPIP_TLS_HSTYPE_SERVERHELLO */

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    case TCPIP_TLS_HSTYPE_ENCRYPTEDEXTENSIONS:
    {
      TcpIp_SetTlsBufferRxEncryptedExtensionsIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, readTlsBufferRxIdx);
      TcpIp_SetEncryptedExtensionsLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, (uint16)HsMsgLen);
      TcpIp_SetLastReceivedHsTypeOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_HSTYPE_ENCRYPTEDEXTENSIONS);
      break;
    } /* case TCPIP_TLS_HSTYPE_ENCRYPTEDEXTENSIONS */
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3) */

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
    case TCPIP_TLS_HSTYPE_CERTIFICATESTATUS:
    {
      TcpIp_SetTlsBufferRxServerCertificateStatusIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, readTlsBufferRxIdx);
      TcpIp_SetServerCertificateStatusLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, (uint16)HsMsgLen);
      TcpIp_SetLastReceivedHsTypeOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_HSTYPE_CERTIFICATESTATUS);
      break;
    } /* TCPIP_TLS_HSTYPE_CERTIFICATESTATUS */

    case TCPIP_TLS_HSTYPE_SERVERKEYEXCHANGE:
    {
      TcpIp_SetTlsBufferRxServerKeyExchangeIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, readTlsBufferRxIdx);
      TcpIp_SetServerKeyExchangeLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, (uint16)HsMsgLen);
      TcpIp_SetLastReceivedHsTypeOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_HSTYPE_SERVERKEYEXCHANGE);
      break;
    } /* case TCPIP_TLS_HSTYPE_SERVERKEYEXCHANGE */
#  endif /* TCPIP_SUPPORT_ASRTLS_VERSION_1_2 */

    case TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST:
    {
      TcpIp_SetTlsBufferRxServerCertificateRequestIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, readTlsBufferRxIdx);
      TcpIp_SetServerCertificateRequestLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, (uint16)HsMsgLen);
      TcpIp_SetLastReceivedHsTypeOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST);
      break;
    } /* case TCPIP_TLS_HSTYPE_CERTIFICATEREQUEST */

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
    case TCPIP_TLS_HSTYPE_SERVERHELLODONE:
    {
      TcpIp_SetTlsBufferRxServerHelloDoneIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, readTlsBufferRxIdx);
      TcpIp_SetServerHelloDoneLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, (uint16)HsMsgLen);
      TcpIp_SetLastReceivedHsTypeOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_HSTYPE_SERVERHELLODONE);
      break;
    } /* case TCPIP_TLS_HSTYPE_SERVERHELLODONE */

    case TCPIP_TLS_HSTYPE_HELLOREQUEST:
    {
      /* Skip this message during handshake. Was already processed in TcpIp_Tls12CoreRl_ProcessHsHelloRequest() */
      *SkipThisMessagePtr = TRUE;
      break;
    } /* case TCPIP_TLS_HSTYPE_HELLOREQUEST */
#  endif /* TCPIP_SUPPORT_ASRTLS_VERSION_1_2 */
# endif /* TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON */

# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
    case TCPIP_TLS_HSTYPE_CLIENTKEYEXCHANGE:
    {
      TcpIp_SetTlsBufferRxClientKeyExchangeIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, readTlsBufferRxIdx);
      TcpIp_SetClientKeyExchangeLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, (uint16)HsMsgLen);
      TcpIp_SetLastReceivedHsTypeOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_HSTYPE_CLIENTKEYEXCHANGE);
      break;
    } /* case TCPIP_TLS_HSTYPE_CLIENTKEYEXCHANGE */
#  endif /* TCPIP_SUPPORT_ASRTLS_VERSION_1_2 */
# endif /* TCPIP_SUPPORT_ASRTLSSERVER == STD_ON */

    case TCPIP_TLS_HSTYPE_CERTIFICATE:
    {
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
      if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
      {
        TcpIp_SetTlsBufferRxClientCertificateIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, readTlsBufferRxIdx);
        TcpIp_SetClientCertificateLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, (uint16)HsMsgLen);
      }
# endif /* TCPIP_SUPPORT_ASRTLSSERVER == STD_ON */
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
      if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_CLIENT)
      {
        TcpIp_SetTlsBufferRxServerCertificatesIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, readTlsBufferRxIdx);
        TcpIp_SetServerCertificatesLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, (uint16)HsMsgLen);
      }
# endif /* TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON */
      TcpIp_SetLastReceivedHsTypeOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_HSTYPE_CERTIFICATE);
      break;
    } /* case TCPIP_TLS_HSTYPE_CERTIFICATE */

    case TCPIP_TLS_HSTYPE_CERTIFICATEVERIFY:
    {
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
      if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
      {
        TcpIp_SetTlsBufferRxClientCertificateVerifyIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, readTlsBufferRxIdx);
        TcpIp_SetClientCertificateVerifyLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, (uint16)HsMsgLen);
      }
# endif /* TCPIP_SUPPORT_ASRTLSSERVER == STD_ON */
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_CLIENT)
      {
        TcpIp_SetTlsBufferRxServerCertificateVerifyIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, readTlsBufferRxIdx);
        TcpIp_SetServerCertificateVerifyLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, (uint16)HsMsgLen);
      }
#  endif /* TCPIP_SUPPORT_ASRTLS_VERSION_1_3 */
# endif /* TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON */
      TcpIp_SetLastReceivedHsTypeOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_HSTYPE_CERTIFICATEVERIFY);
      break;
    } /* case TCPIP_TLS_HSTYPE_CERTIFICATEVERIFY */

    case TCPIP_TLS_HSTYPE_FINISHED:
    {
      /* Server and client share the finished message - check which message is received */
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
      if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
      {
        /* Update finished message information for server (received message = ClientFinished) */
        TcpIp_SetTlsBufferRxClientFinishedIdxOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, readTlsBufferRxIdx);
        TcpIp_SetClientFinishedLenOfTlsServerBufferMgmt(tlsServerBufferMgmtIdx, (uint16)HsMsgLen);
      }
# endif /* TCPIP_SUPPORT_ASRTLSSERVER == STD_ON */
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
      if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_CLIENT)
      {
        /* Update finished information for client (received message = ServerFinished) */
        TcpIp_SetTlsBufferRxServerFinishedIdxOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, readTlsBufferRxIdx);
        TcpIp_SetServerFinishedLenOfTlsClientBufferMgmt(tlsClientBufferMgmtIdx, (uint16)HsMsgLen);
      }
# endif /* TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON */

      TcpIp_SetLastReceivedHsTypeOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_HSTYPE_FINISHED);
      break;
    } /* case TCPIP_TLS_HSTYPE_FINISHED */

    default:
    {
      /* Invalid type is checked by function TcpIp_TlsCoreCtHs_CheckIfTypeIsReceivableInThisConnection */
      retVal = E_NOT_OK;
      break;
    }
  } /* switch */

  if (retVal == E_OK)
  {
    /* #20 Increment read pointer by the 1 byte content type and by the 3 byte handshake type_len length */
    TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, (TCPIP_TLS_CT_LEN + TCPIP_TLS_HSLEN_LEN));
  }

  return retVal;
} /* TcpIp_TlsCoreCtHs_UpdateTypeInformation() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_HandleInvalidHsMessage
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtHs_HandleInvalidHsMessage(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsUserErrorType hsUserError;
  TcpIp_TlsAlertLevelType alertLevel;
  TcpIp_TlsAlertDescriptionType alertDescription;

  /* ----- Implementation ----------------------------------------------- */
  /* Set the corresponding error id */
  hsUserError.FunctionId = TCPIP_TLS_FCTID_CORE_MAINFCT_RXHS;
  hsUserError.UserErrorId = TCPIP_TLS_ERRORID_RXINCORRECTHSMESSAGE;
  hsUserError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

  /* #10 Report the error to the user */
  TcpIp_TlsCoreError_ReportUserError(hsUserError);

  /* Set the corresponding alert level and description */
  alertLevel       = TCPIP_TLS_ALERT_LEVEL_FATAL;
  alertDescription = TCPIP_TLS_ALERT_DESC_UNEXP_MSG;

  /* #20 Trigger the transmission of the occurred alert */
  TcpIp_TlsCoreAlert_Set(TlsConIdx, alertLevel, alertDescription);
} /* TcpIp_TlsCoreCtHs_HandleInvalidHsMessage() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_RxIndication
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtHs_RxIndication(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Update the Handshake RX-Indication */
  TcpIp_IncHsRxIndicationCntOfTlsConnectionDyn(TlsConIdx);
} /* TcpIp_TlsCoreCtHs_RxIndication() */

# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtHs_AnalyzeSecpKeyComponente
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtHs_AnalyzeSecpKeyComponente(
  TCPIP_P2C(uint8) KeyPtr,
  TCPIP_P2V(TcpIp_TlsSecpSignCoordinateDescriptorType) SignCoordinateDescriptorPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least keyIter;

  /* ----- Implementation ----------------------------------------------- */
  SignCoordinateDescriptorPtr->NumberOfSkippingLeadingZeros = 0u;
  SignCoordinateDescriptorPtr->PrependLeadingZero = FALSE;

  /* #10 Iterate over the complete key component and count the number of leading zeros which must be prepended. */
  for (keyIter = 0u; keyIter < SignCoordinateDescriptorPtr->CoordinateByteLen; keyIter++)
  {
    /* Check if the current byte is not zero */
    if (KeyPtr[keyIter] != 0x00u)
    {
      /* Check if the current byte is greater than or equal to 0x80 */
      if (KeyPtr[keyIter] >= TCPIP_TLS_ASN1_INTEGER_STARTVALUE_LEADINGZERO)
      {
        /* A different behavior is needed if this is the first byte of the signature */
        if (keyIter == 0u)
        {
          /* Inform the caller that he has to prepend a leading zero */
          SignCoordinateDescriptorPtr->PrependLeadingZero = TRUE;
        }
        else
        {
          /* Decrement the number of leading zeros */
          SignCoordinateDescriptorPtr->NumberOfSkippingLeadingZeros--;
        }
      }

      /* End the processing */
      break;
    }
    else
    {
      /* Increment the number of leading zeros */
      SignCoordinateDescriptorPtr->NumberOfSkippingLeadingZeros++;
    }
  }

  /* #20 Calculate the ASN length of the component. */
  SignCoordinateDescriptorPtr->Asn1Len = SignCoordinateDescriptorPtr->CoordinateByteLen - SignCoordinateDescriptorPtr->NumberOfSkippingLeadingZeros;

  if (SignCoordinateDescriptorPtr->PrependLeadingZero == TRUE)
  {
    /* Due to the leading zero, key size is increased by one byte */
    SignCoordinateDescriptorPtr->Asn1Len += 1u;
  }
}
# endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TLS CORE CT CHANGE CIPHER SPEC
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtCcs_CheckReceivedCcsData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtCcs_CheckReceivedCcsData(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */

  uint8 ccsLen = (uint8)(TcpIp_GetTlsBufferRxCcsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)
    - TcpIp_GetTlsBufferRxCcsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

  /* #10 Check if we have received some data in the CCS RX-Buffer */
  if (ccsLen == TCPIP_TLS_CCSMSG_LEN)
  {
    uint8 receivedCcsData = TcpIp_GetTlsBufferRx(TcpIp_GetTlsBufferRxCcsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

    /* #20 Check if the received data has the format of the CCS message */
    if (receivedCcsData == TCPIP_TLS_CHANGECIPHERSPEC)
    {
      /* #30 if so, forward frame to CCS handler */
      retVal = TcpIp_TlsCoreCtCcs_ForwardFrameToCCsHandler(TlsConIdx);
    }
    else
    {
      /* Invalid CCS data received */
      /* RFC8446 section 5 Record Protocol:
       * 'An implementation which receives any other change_cipher_spec value [...]
       *  MUST abort the handshake with an 'unexpected_message' alert.'
       * Note that in RFC5246 section 7.1 Change Cipher Spec Protocol no specific alert is mentioned for TLS 1.2.
       * Therefore, the 'unexpected_message' alert is chosen for both TLS 1.2 and TLS 1.3.
      */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
    }
  }
  else
  {
    /* Invalid CCS length received */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
  }
  return retVal;
} /* TcpIp_TlsCoreCtCcs_CheckReceivedCcsData() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtCcs_ForwardFrameToCCsHandler
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
/* PRQA S 6050, 6080 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtCcs_ForwardFrameToCCsHandler(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
  {
    /* RFC8446 section 5: "An implementation may receive an unencrypted record of type change_cipher_spec
     * consisting of the single byte value 0x01 at any time after the first ClientHello message has been sent
     * and before the peer's Finished message has been received and MUST simply drop it without further processing."
     * As described in the TechRef this implementation
     * deviates from this statement and only ignores records of type change_cipher_spec
     * after the ServerHello has been received and the TLS version 1.3 has been negotiated.
     * Earlier CCS records do not really make sense since they do not announce a switch of keys,
     * since the unencrypted ServerHello follows and in connections which support both TLS 1.2 and 1.3
     * it is not even sure yet that a TLS 1.3 handshake is performed.*/
    /* The last received Hs type is initialized to invalid.
     * Therefore a reception of a CCS before the ServerHello is detected by checking against the invalid value. */
    /* #10 When the TLS version is 1.3, check if the CCS message was received at a valid time. */
    if (   (TcpIp_GetLastHsMsgTypeOfLastReceivedHsRlFrameOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_HSTYPE_FINISHED)
        && (TcpIp_GetLastHsMsgTypeOfLastReceivedHsRlFrameOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_HSTYPE_INVALID))    /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
    {
      /* In TLS 1.3 no additional checks are needed
       * (a CCS message gets ignored even when the compatibility mode is disabled)
       * and nothing has to be triggered or done here. */
      /* #20 If so, ignore the message. */
      retVal = E_OK;
    }
    else
    {
      /* #30 Otherwise, trigger the transmission of the occurred alert */
      TcpIp_TlsCoreCtCcs_HandleInvalidCcsMessage(TlsConIdx);
    }
  }
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  else if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_12)
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  {
    /* #40 When the TLS version is 1.2, check if we are allowed to received the CCS message */
    if (TcpIp_IsCcsReceivableOfTlsConnectionDyn(TlsConIdx) == TRUE)
    {
      TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx
        = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

      TcpIp_TlsCipherDefinitionIdxOfTlsCipherWorkerType tlsCipherDefinitionIdx
        = TcpIp_GetTlsCipherDefinitionIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx); /* Get the index of the current CipherDefiniton */

      TcpIp_CipherSuiteIdOfTlsCipherDefinitionType selectedCipherSuiteId
        = TcpIp_GetCipherSuiteIdOfTlsCipherDefinition(tlsCipherDefinitionIdx);   /* Get the corresponding Cipher Id (HexCode) */

      /* #50 If so, check if the last received message is not the finished message */
      /* Use TcpIp_GetLastHsMsgTypeOfLastReceivedHsRlFrameOfTlsConnectionDyn instead of
       * TcpIp_GetLastReceivedHsTypeOfTlsConnectionDyn here, since it is directly set in the RxRl context while
       * TcpIp_GetLastHsMsgTypeOfLastReceivedHsRlFrameOfTlsConnectionDyn is set in the Hs context which is
       * blocked when async operations are pending and therefore might not be up to date. */
      if (TcpIp_GetLastHsMsgTypeOfLastReceivedHsRlFrameOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_HSTYPE_FINISHED)
      {
        /* #60 If so, set CCS message RxIndication */
        TcpIp_SetCcsRxIndicationOfTlsConnectionDyn(TlsConIdx, TRUE);

        /* #70 Change the RX cipher spec to the negotiated cipher ID */
        TcpIp_SetActiveCipherRxOfTlsConnectionDyn(TlsConIdx, selectedCipherSuiteId);

        /* #80 Reset the RX RL Sequence Counter */
        TcpIp_SetRlRxSequenceCounterOfTlsConnectionDyn(TlsConIdx, 0u);

        retVal = E_OK;
      }
      else
      {
        /* #90 Otherwise, trigger the transmission of the occurred alert */
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
      }
    }
    else
    {
      /* CCS message received in an invalid state (CCs not receivable) */
      TcpIp_TlsCoreCtCcs_HandleInvalidCcsMessage(TlsConIdx);
    }
  }
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  else
  {
    /* The TLS version is not set yet. This means the ServerHello has not been parsed yet.
     * RFC8446 section 5 states that the TLS client may receive an unencrypted record of type change_cipher_spec
     * consisting of the single byte value 0x01 at any time after the first ClientHello message has been sent
     * and before the peer's Finished message has been received. As described in the TechRef this implementation
     * deviates from this statement and only ignores records of type change_cipher_spec
     * after the ServerHello has been received and the TLS version 1.3 has been negotiated.
     * Earlier CCS records do not really make sense since they do not announce a switch of keys,
     * since the unencrypted ServerHello follows and in connections which support both TLS 1.2 and 1.3
     * it is not even sure yet that a TLS 1.3 handshake is performed.
     * To ignore also the CCS records received before the ServerHello (and therefore complying with the RFC8446)
     * only this else-path needs to be removed. */
    /* Trigger the transmission of the occurred alert */
    TcpIp_TlsCoreCtCcs_HandleInvalidCcsMessage(TlsConIdx);
  }
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */

  if (retVal == E_OK)
  {
    /* This block is executed for all TLS versions if the CCS message was valid. */
    /* Reset the CCS write index */
    TcpIp_SetTlsBufferRxCcsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TcpIp_GetTlsBufferRxCcsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx));
  }

  return retVal;
} /* TcpIp_TlsCoreCtCcs_ForwardFrameToCCsHandler() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtCcs_HandleInvalidCcsMessage
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtCcs_HandleInvalidCcsMessage(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsUserErrorType alUserError;

  /* ----- Implementation ----------------------------------------------- */
  /* Set the corresponding error id */
  alUserError.FunctionId = TCPIP_TLS_FCTID_CORE_MAINFCT_CCS;
  alUserError.UserErrorId = TCPIP_TLS_ERRORID_RL_INCORRECT_CT;
  alUserError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

  /* #10 Report the error to the user */
  TcpIp_TlsCoreError_ReportUserError(alUserError);

  /* #20 Trigger the transmission of the occurred alert */
  TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);

} /* TcpIp_TlsCoreCtCcs_HandleInvalidCcsMessage() */

/**********************************************************************************************************************
 *  TLS CORE CT APPLICATION DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtAd_RxIndication
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtAd_RxIndication(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Update the Application data RX-Indication */
  TcpIp_SetAdRxIndicationOfTlsConnectionDyn(TlsConIdx, TRUE);
} /* TcpIp_TlsCoreCtAd_RxIndication() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtAd_ForwardDataToAdHandler
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtAd_ForwardDataToAdHandler(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If there is new plaintext in TLS Rx AdHs buffer that has not been forwarded to Ul, trigger RxIndication */
  if (TcpIp_GetAdUlRxIndLevelOfTlsBufferMgmtDyn(tlsBufferMgmtIdx) != 0u)
  {
    /* Trigger the Ad RxIndicaiton */
    TcpIp_TlsCoreCtAd_RxIndication(TlsConIdx);
    retVal = E_OK;
  }
  return retVal;
} /* TcpIp_TlsCoreCtAd_ForwardDataToAdHandler() */

/**********************************************************************************************************************
 *  TLS CORE CT ALERT
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreAlert_Set
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
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreAlert_Set(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TcpIp_TlsAlertLevelType       AlertLevel,
  TcpIp_TlsAlertDescriptionType AlertDescription)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TxAlertTriggerOfTlsConnectionDynType alertTrigger =
    TcpIp_IsTxAlertTriggerOfTlsConnectionDyn(TlsConIdx);

  TcpIp_TxCloseNotifyTriggerOfTlsConnectionDynType closeNotifyTrigger =
    TcpIp_IsTxCloseNotifyTriggerOfTlsConnectionDyn(TlsConIdx);

  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx =
    TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferTxAlWriteIdxOfTlsBufferMgmtDynType alWriteTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxAlWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_VENTER_CRITICAL_SECTION();

  /* #10 Check if there is a current alert set, and if it can be over written. */
  if (alertTrigger == TRUE)
  {
    /* Current write idx is pointing to the last set alert level */
    TcpIp_TlsAlertLevelType lastAlertLevel = (TcpIp_TlsAlertLevelType)TcpIp_GetTlsBufferTx(alWriteTlsBufferTxIdx);

    /* #20 Check if the last alert had the level warning */
    if (lastAlertLevel == TCPIP_TLS_ALERT_LEVEL_WARNING)
    {
      /* #30 If so, check if the last alert was a CloseNotify */
      if (closeNotifyTrigger == TRUE)
      {
        /* #40 If so, check if the new alert has the level fatal */
        if (AlertLevel == TCPIP_TLS_ALERT_LEVEL_FATAL)
        {
          /* #50 If so, overwrite the alert with the new one */
          TcpIp_TlsCoreCtAl_ForwardAlertToTxBuffer(TlsConIdx, AlertLevel, AlertDescription);
          /* #60 Reset CloseNotify trigger, because after this alert the connection is closed and the CloseNotify will not be sent */
          TcpIp_SetTxCloseNotifyTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);
        }
        /* else: AlertLevel = TCPIP_TLS_ALERT_LEVEL_WARNING, don't overwrite CloseNotify with other warning */
      }
      else /* closeNotifyTrigger == FALSE */
      {
        /* #70 Alerts with level warning besides CloseNotify can be overwritten */
        TcpIp_TlsCoreCtAl_ForwardAlertToTxBuffer(TlsConIdx, AlertLevel, AlertDescription);
      }
    }
    /* else: lastAlertLevel = TCPIP_TLS_ALERT_LEVEL_FATAL, don't overwrite fatal alert */
  }
  else /* alertTrigger == FALSE */
  {
    /* #80 No alert set yet, forward new alert to Tx buffer */
    TcpIp_TlsCoreCtAl_ForwardAlertToTxBuffer(TlsConIdx, AlertLevel, AlertDescription);
  }

  TCPIP_VLEAVE_CRITICAL_SECTION();
} /* TcpIp_TlsCoreAlert_Set() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtAl_ForwardAlertToTxBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtAl_ForwardAlertToTxBuffer(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TcpIp_TlsAlertLevelType       AlertLevel,
  TcpIp_TlsAlertDescriptionType AlertDescription)
{
  /* ----- Local Variables ---------------------------------------------- */
    TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
      = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
    TcpIp_TlsBufferTxAlWriteIdxOfTlsBufferMgmtDynType alWriteTlsBufferTxIdx
      = TcpIp_GetTlsBufferTxAlWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Trigger the transmission of this alert */
  if (TCPIP_TLS_AL_CHECK_BUFFER_IDX(TlsConIdx, alWriteTlsBufferTxIdx, TCPIP_TLS_ALERT_MSG_LEN))
  {
    TcpIp_SetTxAlertTriggerOfTlsConnectionDyn(TlsConIdx, TRUE);

    if ((AlertLevel == TCPIP_TLS_ALERT_LEVEL_WARNING) && (AlertDescription == TCPIP_TLS_ALERT_DESC_CLOSE_NOTIFY))
    {
      TcpIp_SetTxCloseNotifyTriggerOfTlsConnectionDyn(TlsConIdx, TRUE);
    }
    /* Write the AlertLevel into Alert TX-Buffer */
    IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(alWriteTlsBufferTxIdx), TCPIP_TLS_ALERTLEVEL_OFFSET, AlertLevel);

    /* Write the Alert Description into Alert TX-Buffer */
    IpBase_PutUint8(TcpIp_GetAddrTlsBufferTx(alWriteTlsBufferTxIdx), TCPIP_TLS_ALERTDESCRIPTION_OFFSET, AlertDescription);

    /* TLS-Alert will be raised - trigger TLS error indication with transmitted alert description */
    TcpIp_TlsCoreError_IndicationTrigger(TlsConIdx, TCPIP_TLS_E_TX_ALERT, AlertDescription);
  }
  else
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
  }
} /* TcpIp_TlsCoreCtAl_ForwardAlertToTxBuffer() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtAl_TxAlert
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtAl_TxAlert(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferTxAlWriteIdxOfTlsBufferMgmtDynType alWriteTlsBufferTxIdx
    = TcpIp_GetTlsBufferTxAlWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  TcpIp_TlsBufferTxAlStartIdxOfTlsBufferMgmtType txAlStartIdx
    = TcpIp_GetTlsBufferTxAlStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Forward the alert to the record layer and transmit the frame */
  if (TcpIp_TlsCoreRl_Transmit(TlsConIdx, alWriteTlsBufferTxIdx, TCPIP_TLS_ALERT_MSG_LEN, TCPIP_TLS_CT_AL) == E_OK)
  {
    /* Current write idx is pointing to the set alert level */
    TcpIp_TlsAlertLevelType alertLevel = TcpIp_GetTlsBufferTx(alWriteTlsBufferTxIdx);
    TcpIp_TlsAlertDescriptionType alertDescription = TcpIp_GetTlsBufferTx(alWriteTlsBufferTxIdx + TCPIP_TLS_ALERTDESCRIPTION_OFFSET);

    /* #20 Decide if the connection shall be closed now */
    if (TcpIp_TlsCoreCtAl_ShallConnectionBeClosedIfTxAlert(TlsConIdx, alertLevel, alertDescription) == TRUE)
    {
      /* Close the Tcp socket from TLS - No more data should be exchanged */
      TcpIp_Tls_CloseInternal(TlsConIdx);


      /* #30 Change the TLS-Connection state to TCPIP_TLS_STATE_CONNECTION_CLOSING depending on connection mode (Server/Client) */
      /* With the final TcpEvent CLOSED this state is updated to TCPIP_TLS_STATE_CONNECTION_CLOSED (TcpIp_TlsCoreEvent_TcpEventClosed) */
      TcpIp_TlsCoreCtAl_SetTlsConnectionStateAfterClosingSocket(TlsConIdx);

      /* Reset the TxCloseNotifyTrigger. */
      if (TcpIp_IsTxCloseNotifyTriggerOfTlsConnectionDyn(TlsConIdx) == TRUE)
      {
        TcpIp_SetTxCloseNotifyTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);
      }
    } /* else - the connection shall not be closed yet */

    /* Reset the alert trigger and the alert write index, if transmission was successful */
    TcpIp_SetTlsBufferTxAlWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, txAlStartIdx);
    TcpIp_SetTxAlertTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);
  }
  /* If the transmit call return E_NOT_OK, we will try to transmit the alert in the next main function cycle again */
} /* TcpIp_TlsCoreCtAl_TxAlert() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtAl_ShallConnectionBeClosedIfTxAlert
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL_INLINE FUNC(boolean, TCPIP_CODE) TcpIp_TlsCoreCtAl_ShallConnectionBeClosedIfTxAlert(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TcpIp_TlsAlertLevelType       AlertLevel,
  TcpIp_TlsAlertDescriptionType AlertDescription)
{
  /* ----- Local Variables ---------------------------------------------- */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  TcpIp_TlsConnectionState state = TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx);
# else
  TCPIP_DUMMY_STATEMENT_CONST(TlsConIdx);                                                                               /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
# endif
  boolean shallConnectionBeClosed = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the connection is TLS 1.2 or TLS 1.3 and what kind of alert was sent */
  /* If any alert is sent and the active version is TLS 1.2 or not yet set, we have to close the connection.
   * The connection should also be closed in the case the active version is TLS 1.3
   * and any alert with the alert level "fatal" was sent or a close notify is send after already receiving one.
   * In this case the state is TCPIP_TLS_STATE_CONNECTION_CLOSENOTIFY_WAIT.
   * If the active version is TLS 1.3 and a close notify is send without a close notify received before
   * (state = TCPIP_TLS_STATE_CONNECTION_13_ACTIVE_CLOSE_REQUESTED), the TCP connection should not be closed. */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  if (   (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_12)
      || (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_NOTSET)                               /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
      || (AlertLevel == TCPIP_TLS_ALERT_LEVEL_FATAL)
      || (state == TCPIP_TLS_STATE_CONNECTION_CLOSENOTIFY_WAIT))
# endif
  {
    /* #20 Only close the connection when a fatal alert or a CloseNotify alert is send */
    if ((AlertLevel == TCPIP_TLS_ALERT_LEVEL_FATAL) || (AlertDescription == TCPIP_TLS_ALERT_DESC_CLOSE_NOTIFY))
    {
      shallConnectionBeClosed = TRUE;
    }
    /* else: alert level set to warning and description is not CloseNotify, do not close the connection */
  }
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  else
  {
    /* A close notify was sent. The write side is closed now. Receiving data is still possible until
     * we received a close notify alert */
    TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CONNECTION_13_CLOSENOTIFY_SENT);
  }
# endif
  return shallConnectionBeClosed;
} /* TcpIp_TlsCoreCtAl_ShallConnectionBeClosedIfTxAlert() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtAl_SetTlsConnectionStateAfterClosingSocket
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtAl_SetTlsConnectionStateAfterClosingSocket(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
  TcpIp_TlsConnectionState state = TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx);
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Change the TLS-Connection state to TCPIP_TLS_STATE_CONNECTION_CLOSING depending on connection mode (Server/Client) */
  /* With the final TcpEvent CLOSED this state is updated to TCPIP_TLS_STATE_CONNECTION_CLOSED (TcpIp_TlsCoreEvent_TcpEventClosed) */
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
#  endif
  {
    /* TLS-Server */
    /* In case of an TLS-Server, the forwarding of the event to the upper layer depends on the current connection state */
    if (   (state == TCPIP_TLS_STATE_CONNECTION_ESTABLISHED)
        || (state == TCPIP_TLS_STATE_CONNECTION_CLOSENOTIFY_WAIT))
    {
      /* TLS connection established - the upper layer should be informed about the event */
      TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CONNECTION_CLOSING);
    }
    else
    {
      /* TLS handshake active - the upper layer MUST NOT be informed about the event */
      TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx,
        TCPIP_TLS_STATE_CONNECTION_CLOSING_WITHOUT_UPPERLAYER_EVENT_FORWARDING);
    }
  }
# endif
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
  else
#  endif
  {
    /* TLS-Client */
    /* In case of an TLS-Client, the upper layer should be informed about the event */
    TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CONNECTION_CLOSING);
  }
# endif
} /* TcpIp_TlsCoreCtAl_SetTlsConnectionStateAfterClosingSocket() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtAl_RxIndication
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtAl_RxIndication(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Update the Alert RX-Indication */
  TcpIp_SetAlRxIndicationOfTlsConnectionDyn(TlsConIdx, TRUE);
} /* TcpIp_TlsCoreCtAl_RxIndication() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtAl_CheckLengthAndForwardAlertToAlHandler
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtAl_CheckLengthAndForwardAlertToAlHandler(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx                   = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferRxAlReadIdxOfTlsBufferMgmtDynType  rxAlReadIdx  = TcpIp_GetTlsBufferRxAlReadIdxOfTlsBufferMgmtDyn(
                                                                        tlsBufferMgmtIdx);
  TcpIp_TlsBufferRxAlWriteIdxOfTlsBufferMgmtDynType rxAlWriteIdx = TcpIp_GetTlsBufferRxAlWriteIdxOfTlsBufferMgmtDyn(
                                                                        tlsBufferMgmtIdx);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if we have unprocessed Alert data and trigger the Alert Rx-Indication */
  if (rxAlReadIdx != rxAlWriteIdx)
  {
    /* #20 Check length of alert message */
    if ((rxAlWriteIdx - rxAlReadIdx) == TCPIP_TLS_ALERT_MSG_LEN)
    {
      /* Trigger the Al Rx-Indication */
      TcpIp_TlsCoreCtAl_RxIndication(TlsConIdx);

      retVal = E_OK;
    }
    else
    {
      /* invalid alert message length */
      TcpIp_TlsUserErrorType userError;

      userError.FunctionId = TCPIP_TLS_FCTID_CORE_MAINFCT_AL;
      userError.UserErrorId = TCPIP_TLS_ERRORID_ALERT_LENGTH_INVALID;
      userError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

      TcpIp_TlsCoreError_ReportUserError(userError);

      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
    }
  }
  return retVal;
} /* TcpIp_TlsCoreCtAl_CheckLengthAndForwardAlertToAlHandler() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtAl_ParseReceivedAlertTlsVersionDependent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtAl_ParseReceivedAlertTlsVersionDependent(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* If both TLS versions are STD_ON we need to check which version is active.
   * Otherwise the TLS version specific parser is invoked directly. */
# if ((TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) && (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON))
  TcpIp_TlsVersionType invokeThisVersionsSpecificParser = TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Decide the active TLS version */
  if (invokeThisVersionsSpecificParser == TCPIP_TLSVERSION_NOTSET)
  {
    invokeThisVersionsSpecificParser = TcpIp_TlsCoreCtAl_GetTlsVersionOfParserForReceivedAlert(TlsConIdx);
  }
# endif

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  switch (invokeThisVersionsSpecificParser)
  {
    case TCPIP_TLSVERSION_12:
    {
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
      /* #20 Call TLS 1.2 alert parsing function */
      TcpIp_TlsCore12CtAl_ParseReceivedAlert(TlsConIdx);
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      break;
    }
    case TCPIP_TLSVERSION_13:
    {
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      /* #30 Call TLS 1.3 alert parsing function */
      TcpIp_TlsCore13CtAl_ParseReceivedAlert(TlsConIdx);
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      break;
    }
    default: /* TCPIP_TLSVERSION_NOTSET */
    {
      /* It was decided that when the active version is not set yet
       * and it's also not predetermined through the ciphers that the TLS 1.3 parser shall be invoked. */
      /* #40 TLS version not known yet, call TLS 1.3 alert parsing function */
      TcpIp_TlsCore13CtAl_ParseReceivedAlert(TlsConIdx);
      break;
    }
  }
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
} /* TcpIp_TlsCoreCtAl_ParseReceivedAlertTlsVersionDependent() */

# if ((TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) && (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON))
/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtAl_GetTlsVersionOfParserForReceivedAlert
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
TCPIP_LOCAL FUNC(TcpIp_TlsVersionType, TCPIP_CODE) TcpIp_TlsCoreCtAl_GetTlsVersionOfParserForReceivedAlert(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsVersionType tlsVersionOfParser = TCPIP_TLSVERSION_NOTSET;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check which versions are supported by the TLS connection. */
  if (   (TcpIp_IsTlsSupportVersion13OfTlsConnection(TlsConIdx) == TRUE)
      && (TcpIp_IsTlsSupportVersion12OfTlsConnection(TlsConIdx) == TRUE))
  {
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
    /* #20 If both are, check if a cipher working set with a non-zero length exists. */
    if (TcpIp_TlsClient_IsCipherWorkingSetUnavailableOrZeroLength(TlsConIdx) == FALSE)
    {
      /* #30 If it exists, check the working set for its TLS versions. */
      if (   (TcpIp_TlsClient_WorkingSetIncludesTlsVersion(TlsConIdx, TCPIP_TLSVERSION_13) == TRUE)
          && (TcpIp_TlsClient_WorkingSetIncludesTlsVersion(TlsConIdx, TCPIP_TLSVERSION_12) == FALSE))                   /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
      {
        /* #40 Only ciphers with TLS version 1.3 are included */
        tlsVersionOfParser = TCPIP_TLSVERSION_13;
      }
      else if (   (TcpIp_TlsClient_WorkingSetIncludesTlsVersion(TlsConIdx, TCPIP_TLSVERSION_12) == TRUE)
               && (TcpIp_TlsClient_WorkingSetIncludesTlsVersion(TlsConIdx, TCPIP_TLSVERSION_13) == FALSE))              /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
      {
        /* #50 Only ciphers with TLS version 1.2 are included */
        tlsVersionOfParser = TCPIP_TLSVERSION_12;
      }
      else
      {
        /* TLS version can't be determined, tlsVersionOfParser shall be TCPIP_TLSVERSION_NOTSET. */
      }
    } /* else - TLS version can't be determined, tlsVersionOfParser shall be TCPIP_TLSVERSION_NOTSET. */
#  endif
  }
  else if (TcpIp_IsTlsSupportVersion12OfTlsConnection(TlsConIdx) == TRUE)
  {
    tlsVersionOfParser = TCPIP_TLSVERSION_12;
  }
  else
  {
    tlsVersionOfParser = TCPIP_TLSVERSION_13;
  }
  return tlsVersionOfParser;
} /* TcpIp_TlsCoreCtAl_GetTlsVersionOfParserForReceivedAlert() */
# endif

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCore12CtAl_ParseReceivedAlert
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCore12CtAl_ParseReceivedAlert(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxAdHsStartIdxOfTlsBufferMgmtType alStartTlsBufferRxIdx
    = TcpIp_GetTlsBufferRxAlStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* Get the received alert level from the TLS RxBuffer */
  uint8 alertLevel = IpBase_GetUint8(TcpIp_GetAddrTlsBufferRx(alStartTlsBufferRxIdx), TCPIP_TLS_ALERTLEVEL_OFFSET);

  /* Get the received alert description from the TLS RxBuffer */
  uint8 alertDescription
    = IpBase_GetUint8(TcpIp_GetAddrTlsBufferRx(alStartTlsBufferRxIdx), TCPIP_TLS_ALERTDESCRIPTION_OFFSET);

  /* #10 Check if the received alert is valid and forward it to the internal processing */
  if (TcpIp_TlsCoreCtAl_CheckAlert(alertLevel, alertDescription) == E_OK)
  {
    /* Valid Alert received */
    /* #20 Check if the incoming alert is a Close_Notify alert */
    if ((alertLevel == TCPIP_TLS_ALERT_LEVEL_WARNING) && (alertDescription == TCPIP_TLS_ALERT_DESC_CLOSE_NOTIFY))
    {
      /* #30 If so, forward the alert to the Close_Notify handler */
      TcpIp_TlsCoreCtAl_HandleCloseNotifyAlert(TlsConIdx);
    }
    else if (alertLevel == TCPIP_TLS_ALERT_LEVEL_WARNING)
    {
      /* In TLS 1.2 we treat all incoming warning alerts as fatal */
      /* FIN is transmitted automatically when sending the Alert in TcpIp_TlsCoreMainFunction_TxAl */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
    }
    else
    {
      /* #40 Otherwise, forward the alert to the generic alert handler */
      TcpIp_TlsCoreCtAl_HandleAllOtherAlerts(TlsConIdx);
    }

    TcpIp_TlsCoreCtAl_AlertParsingPostProcessing(TlsConIdx, alertDescription);
  }
  else
  {
    /* invalid Alert received , respond with an decode_error alert */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
  }
} /* TcpIp_TlsCore12CtAl_ParseReceivedAlert() */
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCore13CtAl_ParseReceivedAlert
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCore13CtAl_ParseReceivedAlert(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxAdHsStartIdxOfTlsBufferMgmtType alStartTlsBufferRxIdx
    = TcpIp_GetTlsBufferRxAlStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* Get the received alert description from the TLS RxBuffer */
  uint8 alertDescription
    = IpBase_GetUint8(TcpIp_GetAddrTlsBufferRx(alStartTlsBufferRxIdx), TCPIP_TLS_ALERTDESCRIPTION_OFFSET);

  /* The alert level is not relevant in TLS 1.3 anymore, see RFC8446 chapter 6:
   * "In TLS 1.3, the severity is implicit in the type of alert being sent,
   *  and the "level" field can safely be ignored." */

  /* #10 Check if the incoming alert is a Close_Notify alert */
  if (alertDescription == TCPIP_TLS_ALERT_DESC_CLOSE_NOTIFY)
  {
    /* #20 If so, forward the alert to the Close_Notify handler */
    TcpIp_TlsCoreCtAl_HandleCloseNotifyAlert(TlsConIdx);
  }
  /* #30 Check if the incoming alert is a User_Canceled alert */
  else if (alertDescription == TCPIP_TLS_ALERT_DESC_USER_CANCELED)
  {
    /* #40 If so, answer with an internal_error alert */
    /* In TLS 1.3 we do not support the reception of a user_canceled alert as described in RFC8446 chapter 6.1.
     * Instead we answer with an internal_error alert. */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
  }
  else
  {
    /* The alertDescription in TLS 1.3 must not be known to handle it, see RFC chapter 6:
     * "Unknown Alert types MUST be treated as error alerts. " */
    /* #50 Otherwise, forward the alert to the generic alert handler */
    TcpIp_TlsCoreCtAl_HandleAllOtherAlerts(TlsConIdx);
  }

  TcpIp_TlsCoreCtAl_AlertParsingPostProcessing(TlsConIdx, alertDescription);
} /* TcpIp_TlsCore13CtAl_ParseReceivedAlert() */
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtAl_AlertParsingPostProcessing
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtAl_AlertParsingPostProcessing(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8                       AlertDescription)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxAdHsStartIdxOfTlsBufferMgmtType rxAlBufferStartIdx
    = TcpIp_GetTlsBufferRxAlStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Reset the write index because we processed the alert */
  TcpIp_SetTlsBufferRxAlWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, rxAlBufferStartIdx);

  /* #20 Received TLS-Alert - trigger TLS error indication with received alert description */
  TcpIp_TlsCoreError_IndicationTrigger(TlsConIdx, TCPIP_TLS_E_RX_ALERT, AlertDescription);
} /* TcpIp_TlsCoreCtAl_AlertParsingPostProcessing() */

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtAl_CheckAlert
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtAl_CheckAlert(
  TcpIp_TlsAlertLevelType AlertLevel,
  TcpIp_TlsAlertDescriptionType AlertDescription)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the AlertLevel */
  if ((AlertLevel == TCPIP_TLS_ALERT_LEVEL_WARNING) || (AlertLevel == TCPIP_TLS_ALERT_LEVEL_FATAL))
  {
    /* #20 Check the AlertDescription */
    switch (AlertDescription)
    {
      /* Fall through all possible valid Alert descriptions */
      case TCPIP_TLS_ALERT_DESC_CLOSE_NOTIFY:
      case TCPIP_TLS_ALERT_DESC_UNEXP_MSG:
      case TCPIP_TLS_ALERT_DESC_BAD_RECORD_MAC:
      case TCPIP_TLS_ALERT_DESC_DECR_FAILED_RESERVED:
      case TCPIP_TLS_ALERT_DESC_RECORD_OVERFLOW:
      case TCPIP_TLS_ALERT_DESC_DECOMP_FAILURE:
      case TCPIP_TLS_ALERT_DESC_HANDSHAKE_FAILURE:
      case TCPIP_TLS_ALERT_DESC_NO_CERT_RESERVED:
      case TCPIP_TLS_ALERT_DESC_BAD_CERT:
      case TCPIP_TLS_ALERT_DESC_UNSUP_CERT:
      case TCPIP_TLS_ALERT_DESC_CERT_REVOKED:
      case TCPIP_TLS_ALERT_DESC_CERT_EXPIRED:
      case TCPIP_TLS_ALERT_DESC_CERT_UNKNOWN:
      case TCPIP_TLS_ALERT_DESC_ILLEGAL_PARAM:
      case TCPIP_TLS_ALERT_DESC_UNKNOWN_CA:
      case TCPIP_TLS_ALERT_DESC_ACCESS_DENIED:
      case TCPIP_TLS_ALERT_DESC_DECODE_ERROR:
      case TCPIP_TLS_ALERT_DESC_DECRYPT_ERROR:
      case TCPIP_TLS_ALERT_DESC_EXP_RESTR_FAILURE:
      case TCPIP_TLS_ALERT_DESC_PROT_VERSION:
      case TCPIP_TLS_ALERT_DESC_INSUF_SEC:
      case TCPIP_TLS_ALERT_DESC_INT_ERROR:
      case TCPIP_TLS_ALERT_DESC_USER_CANCELED:
      case TCPIP_TLS_ALERT_DESC_NO_RENEGOT:
      case TCPIP_TLS_ALERT_DESC_UNSUP_EXT:
      case TCPIP_TLS_ALERT_DESC_CERT_UNOBTAINABLE:
      case TCPIP_TLS_ALERT_DESC_UNRECOGNIZED_NAME:
      case TCPIP_TLS_ALERT_DESC_BAD_CERT_STATUS_RESP:
      case TCPIP_TLS_ALERT_DESC_BAD_CERT_HASH_VALUE:
      case TCPIP_TLS_ALERT_DESC_UNKNOWN_PSK_IDENTITY:
      {
        /* Valid Alert Description */
        retVal = E_OK;
        break;
      }

      default:
      {
        /* Invalid Alert Description */
        retVal = E_NOT_OK;
        break;
      }
    } /* switch */
  }
  else
  {
    /* Invalid AlertLeve - set retVal to E_NOT_OK */
    retVal = E_NOT_OK;
  }

  return retVal;
} /* TcpIp_TlsCoreCtAl_CheckAlert() */
# endif

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtAl_HandleCloseNotifyAlert
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtAl_HandleCloseNotifyAlert(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if it is a TLS 1.2 or TLS 1.3 connection */
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  if (   (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_NOTSET)
#  if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      || (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_12)                                   /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
#  endif
     )
# endif
  {
    /* #20 Check the current connection state */
    if (   (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_ESTABLISHED)            /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
        || (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_CLOSE_WAIT)
        || (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_CLOSENOTIFY_WAIT))
    {
      /* #30 TLS connection is established and a valid CloseNotify is received. Respond with an CloseNotify alert */
      /* RFC5246 - 7.2.1.  Closure Alerts */
      /* The other party MUST respond with a close_notify alert of its own and close down the connection immediately,
       * discarding any pending writes. */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_WARNING, TCPIP_TLS_ALERT_DESC_CLOSE_NOTIFY);

      /* State TCPIP_TLS_STATE_CONNECTION_CLOSENOTIFY_WAIT is used to transmit the CloseNotify Alert (in MainFunction_TxAl).
       * After the transmit, the state is changed to CLOSE_REQUESTED, where the FIN is triggered. */
      TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CONNECTION_CLOSENOTIFY_WAIT);
    }
    else
    {
      /* #40 TLS handshake is active - Receiving of CloseNotify is not allowed - Respond with TLS alert */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
    }
  }
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  else
  {
    /* Received a CloseNotify Alert. Check if we already sent an CloseNotify alert. */
    if (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_13_CLOSENOTIFY_SENT)
    {
      /* We sent a CloseNotify alert and received a CloseNotify alert WITHOUT a TCP FIN flag.
       * That means we have to close the TCP connection now. */
      TcpIp_Tls_CloseInternal(TlsConIdx);
    }
    else if (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_CLOSING)
    {
      /* We sent a CloseNotify alert and received a CloseNotify alert WITH a TCP FIN flag.
       * That means the TCP layer closes the connection and sends a FIN flag. */
    }
    else if (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_HS_ACTIVE)
    {
      /* We received a CloseNotify alert during the handshake. This is neither explicitly allowed nor
       * forbidden by the RFC8446 chapter 6.1.
       * But a CloseNotify during the handshake simply doesn't make much sense, since this alert should
       * be used to close an open connection. Therefore, answer with a fatal unexpected_message alert
       * and close the connection. This ensures a clear behavior and that the handshake is not continued. */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
    }
    else
    {
      TcpIp_SizeOfSocketDynType                 socketIdx = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);
      TcpIp_SizeOfSocketOwnerConfigType socketOwnerCfgIdx = TcpIp_GetSocketOwnerConfigIdxOfTlsConnectionDyn(TlsConIdx);

      /* We received a CLoseNotify alert. That means we have to close the read side and ignore the incoming messages.
       * Inform the upper layer about the CloseNotify. Transmitting data is possible until a CloseNotify was sent. */
      TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CONNECTION_13_CLOSENOTIFY_RECEIVED);

      /* Inform the upper layer about the close notify */
      TcpIp_Tls_TcpIpEventCallout(socketOwnerCfgIdx, socketIdx, TCPIP_TLS_EVENT_CLOSENOTIFY_RECEIVED);
    }
  }
# endif
} /* TcpIp_TlsCoreCtAl_HandleCloseNotifyAlert() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtAl_HandleAllOtherAlerts
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtAl_HandleAllOtherAlerts(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* Only if the user is not already informed we should trigger the Event */
  if ((TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_CONNECTION_CLOSE_WAIT))
  {
    /* Connection already closed on TCP side */

    /* #10 Inform the upper layer depending on the TLS connection mode and the state of the connection */
    if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_CLIENT)
    {
      /* #20 TLS-Client - Gracefully close the TCP connection (FIN) */
      /* Event forwarding (FIN_RECEIVED, CLOSED) is done in TcpIp_TlsCoreConState_TcpCloseRequestedHandler() */
      TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CONNECTION_GRACEFULLY_TCP_CLOSE_REQUESTED);
    }
    else
    {
      /* #30 TLS-Server - Gracefully close the TCP connection (FIN) - Event forwarding is done depending on the current connection state */
      if ((TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_ESTABLISHED))
      {
        TcpIp_SizeOfSocketDynType socketIdx
          = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);

        TcpIp_SizeOfSocketOwnerConfigType socketOwnerCfgIdx
          = TcpIp_GetSocketOwnerConfigIdxOfTlsConnectionDyn(TlsConIdx);

        if ((socketIdx <  TcpIp_GetSizeOfSocketDyn()) && (socketOwnerCfgIdx <  TcpIp_GetSizeOfSocketOwnerConfig()))
        {
          /* TLS connection is established - UpperLayer should be informed */
          /* Manually trigger FIN_RECEIVED event, since the initial event is not directly forwarded by the TcpIP */
          TcpIp_Tls_TcpIpEventCallout(socketOwnerCfgIdx, socketIdx, IPBASE_TCP_EVENT_FIN_RECEIVED);
          TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CONNECTION_GRACEFULLY_TCP_CLOSE_REQUESTED);
        }
        else
        {
          /* Memory runtime check fails - report DET */
          TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
        }
      }
      else
      {
        /* TLS handshake is active - UpperLayer MUST NOT be informed */
        TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx,
          TCPIP_TLS_STATE_CONNECTION_GRACEFULLY_TCP_CLOSE_REQUESTED_WITHOUT_UPPERLAYER_EVENT_FORWARDING);
      }
    }
  }
  else
  {
    TcpIp_SizeOfSocketDynType socketIdx = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);
    TcpIp_SizeOfSocketTcpDynType socketTcpIdx = TCPIP_SOCKET_IDX_TO_TCP_IDX(socketIdx);

    if((socketIdx < TcpIp_GetSizeOfSocketDyn()) && (socketTcpIdx < TcpIp_GetSizeOfSocketTcpDyn()))
    {
      /* Connection not yet closed on TCP side - trigger close from TLS */
      TcpIp_CloseTcpSocketFromTls(socketTcpIdx, FALSE);
    }
    else
    {
      /* Memory runtime check fails - report DET */
      TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
    }
  }
} /* TcpIp_TlsCoreCtAl_HandleAllOtherAlerts() */

/**********************************************************************************************************************
 *  TLS CORE RECORD LAYER (RL)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_Init(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxAdHsLengthOfTlsBufferMgmtType configuredRxAdHsBufferSize
    = TcpIp_GetTlsBufferRxAdHsLengthOfTlsBufferMgmt(tlsBufferMgmtIdx);

  /* Actual available RX buffer size is calculated by the Configured RX buffer minus the additional overhead
   * (maximum HMAC size + sliding end index) which is reserved in the RX buffer */
  TcpIp_TlsBufferRxAdHsLengthOfTlsBufferMgmtType availableRxAdHsBufferSize
    = (configuredRxAdHsBufferSize - TCPIP_TLS_ADDITIONAL_RX_BUFFER_OVERHEAD);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialization of Record Layer values */
  /* RL TX Information */
  TcpIp_SetRlTxCopiedLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, 0);
  TcpIp_SetRlTxFragmentLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, 0);
  TcpIp_SetRlTxContentTypeOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_CT_INVALID);
  TcpIp_SetTlsBufferTxRlSendIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERTXRLSENDIDXOFTLSBUFFERMGMTDYN);
  TcpIp_SetRlTxInnerPlaintextContentTypeOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_CT_INVALID);
  TcpIp_SetTxInnerContentTypeAddedOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, FALSE);

  /* RL RX Information */
  TcpIp_SetRlRxCopiedLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, 0);
  TcpIp_SetTlsBufferRxRlFrameStartIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
    TCPIP_NO_TLSBUFFERRXRLFRAMESTARTIDXOFTLSBUFFERMGMTDYN);
  TcpIp_SetRxUpperlayerReleasedDataLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, 0u);

  /* RL Sequence counter */
  TcpIp_SetRlRxSequenceCounterOfTlsConnectionDyn(TlsConIdx, 0);
  TcpIp_SetRlTxSequenceCounterOfTlsConnectionDyn(TlsConIdx, 0);

  TcpIp_SetLastRlRxSequenceCounterOfTlsConnectionDyn(TlsConIdx, 0);
  TcpIp_SetLastRlTxSequenceCounterOfTlsConnectionDyn(TlsConIdx, 0);

  /* The RxBufferSize can be larger then the maximum supported limit for this extension
   * - The value is offered via the record_size_limit extension to the peer */
  if (availableRxAdHsBufferSize <= TCPIP_TLS_EXTENSION_RECORD_SIZE_LIMIT_MAX_VALUE)
  {
    /* RX Record size limit is set to the available value (Configured RxBuffer size minus the additional overhead) */
    TcpIp_SetRxRecordSizeLimitOfTlsConnectionDyn(TlsConIdx, (uint16)availableRxAdHsBufferSize);
  }
  else
  {
    /* TLS1.2 maximum support 2^14 byte as record_size_limit extension */
    TcpIp_SetRxRecordSizeLimitOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_EXTENSION_RECORD_SIZE_LIMIT_MAX_VALUE);
  }

  /* The active maximum RX size for one RL frame is set to the minimum of
   * the available RxBuffer size of this connection and the maximum allowed plaintext length (= 2^14). */
  /* The additional reserved space is added in the TcpIp_TlsCoreRl_ValidateRlFragmentLength() function. */
  /* TLS 1.3 allows one more byte in form of the inner plain text ContentType (see RFC8446 chapter 5.4).
   * This is accounted for when the TLS version is known during parsing of the ServerHello message
   * (see TcpIp_Tls13ClientMsg_ServerHelloParseExtensionSupportedVersions()). */
  if (availableRxAdHsBufferSize <= TCPIP_TLS12_RECORD_LAYER_PLAINTEXT_LEN_MAX)
  {
    TcpIp_SetActiveMaxRxRlSizeOfTlsConnectionDyn(TlsConIdx, availableRxAdHsBufferSize);
  }
  else
  {
    TcpIp_SetActiveMaxRxRlSizeOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS12_RECORD_LAYER_PLAINTEXT_LEN_MAX);
  }

  /* TX Record size limit is initial set to 0 and then updated by the received extension during the TLS handshake */
  TcpIp_SetTxRecordSizeLimitOfTlsConnectionDyn(TlsConIdx, 0u);

  /* The active maximum TX size for one RL frame is set to the maximum defined value (2^14),
   * which means that there is no limitation. This value is updated later in the TLS handshake */
  TcpIp_SetActiveMaxTxRlSizeOfTlsConnectionDyn(TlsConIdx,
    TCPIP_TLS_EXTENSION_RECORD_SIZE_LIMIT_MAX_VALUE);

  /* Reset the indication flag, which is used to determine if the extension is received from the peer connection */
  TcpIp_SetExtensionRecordSizeLimitReceivedOfTlsConnectionDyn(TlsConIdx, FALSE);

  /* Reset the flags for blocking decryption with current keys (or none) till new keys are calculated */
  TcpIp_SetBlockDecryptOperationsUntilKeysAreCalculatedOfTlsConnectionDyn(TlsConIdx, FALSE);
  TcpIp_SetMsgPrecedingKeyChangePartiallyReceivedOfTlsConnectionDyn(TlsConIdx, FALSE);
  TcpIp_SetMsgPrecedingKeyChangeNotAlignWithBoundaryOfTlsConnectionDyn(TlsConIdx, FALSE);
} /* TcpIp_TlsCoreRl_Init() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_EncryptAndAuthFrame
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(BufReq_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_EncryptAndAuthFrame(
  TcpIp_SocketDynIterType SocketIdx,
  TCPIP_P2V(uint8)        BufPtr,
  uint16                  BufLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  BufReq_ReturnType            retVal = BUFREQ_E_NOT_OK;
  TcpIp_SizeOfSocketTcpDynType socketTcpIdx = TCPIP_SOCKET_IDX_TO_TCP_IDX(SocketIdx);
  TcpIp_TlsConnectionIterType  tlsConIdx = TcpIp_GetTlsConnectionIdxOfSocketTcpDyn(socketTcpIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Determine the appropriate Tls connection and perform authentication and encryption */
  if (tlsConIdx < TcpIp_GetSizeOfTlsConnection())
  {
    /* Calculate the MAC for the Tx data in the Tls buffer and store in temp buffer */

    if (TcpIp_TlsCoreRl_CalcHmacCipherDependent(tlsConIdx, BufLength) == E_OK)
    {
      /* Perform encryption and copy to the provided TcpIp buffer */
      retVal = TcpIp_TlsCoreRl_EncryptCipherDependent(tlsConIdx, BufPtr, BufLength); /*lint !e655 */
    }
    else
    {
      /* retVal already set to BUFREQ_E_NOT_OK */
    }

    if (retVal != BUFREQ_OK)
    {
      /* CSM call (either HMAC calculation or encryption) did not return E_OK.
       * Since from this time on, all sent frames must be encrypted and authenticated,
       * we can not do anything at TLS layer.
       * Instead we are immediately closing the connection via TCP RST. */
      TcpIp_CloseTcpSocketFromTls(socketTcpIdx, TRUE);
    }
  }
  else
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
    /* retVal already set to E_NOT_OK */
  }
  return retVal;
} /* TcpIp_TlsCoreRl_EncryptAndAuthFrame() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_EncryptCipherDependent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6010, 6050 1 */ /* MD_TcpIp_TlsStreaming_STPTH_6010, MD_TcpIp_TlsStreaming_STCAL_6050 */
TCPIP_LOCAL FUNC(BufReq_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_EncryptCipherDependent(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint8)            BufPtr,
  uint16                      BufLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Depending on the active cipher, perform the encryption */
  TcpIp_SegmentType seg1Ptr;
  TcpIp_SegmentType seg2Ptr;
  TCPIP_P2V(uint8)  seg2bufPtr = BufPtr;

  { /* Init seg1 */
    /* Pointer to TCP buffer segment 1 */
    TCPIP_P2V(uint8) segPtr = TcpIp_GetAddrTxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataPtr;
    /* Length of TCP buffer segment 1 */
    uint16           segLen = TcpIp_GetAddrTxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataLen;

    TcpIp_SegmentInitWithTcpTxBufferInRangeCheck(&seg1Ptr, &segPtr, segLen);

    if (segPtr == NULL_PTR)
    {
      /* Initialize empty segment with dummy address and zero length. Used in NULL cipher context. */
      TcpIp_SegmentInit(&seg1Ptr, TcpIp_GetAddrTcpTxBuffer(0), 0u);
    }

    /* Reset the Data split struct */
    TcpIp_GetAddrTxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataPtr = NULL_PTR;
    TcpIp_GetAddrTxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataLen = 0u;
  }

  { /* Init seg2 */
    TcpIp_SegmentInitWithTcpTxBufferInRangeCheck(&seg2Ptr, &seg2bufPtr, BufLength);
  }

  if(seg2bufPtr != NULL_PTR)
  {
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    if (   (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
        && (TcpIp_GetRlTxContentTypeOfTlsBufferMgmtDyn(tlsBufferMgmtIdx) == TCPIP_TLS_CT_CCS))
    {
      /* When negotiating TLS 1.3 in the compatibility mode an unencrypted dummy CCS record is send by the client
       * (see RFC8446 section 5, appendix D.4). Such a record if received with valid format will be ignored afterwards.
       * This implementation will also process and ignore
       * unencrypted CCS records when the compatibility mode is disabled. */
      retVal = TcpIp_TlsCoreRl_TxCipherEncryptNull(TlsConIdx, &seg1Ptr, &seg2Ptr);
    }
    else
# endif
    {
      switch (TcpIp_GetActiveCipherTxOfTlsConnectionDyn(TlsConIdx))
      {
        case TCPIP_TLS_NULL_WITH_NULL_NULL:
        case TCPIP_TLS_ECDHE_ECDSA_WITH_NULL_SHA:
        case TCPIP_TLS_ECDH_ECDSA_WITH_NULL_SHA:
        case TCPIP_TLS_PSK_WITH_NULL_SHA:
        case TCPIP_TLS_PSK_WITH_NULL_SHA256:
        {
          /* Null encryption */
          retVal = TcpIp_TlsCoreRl_TxCipherEncryptNull(TlsConIdx, &seg1Ptr, &seg2Ptr);
          break;
        }
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
        case TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256:
        case TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256:
        case TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA:
        case TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA:
        case TCPIP_TLS_PSK_WITH_AES_128_CBC_SHA256:
        case TCPIP_TLS_PSK_WITH_AES_128_CBC_SHA:
        {
          /* Aes128 CBC encryption */
          retVal = TcpIp_Tls12CoreRl_TxCipherEncryptAes128Cbc(TlsConIdx, &seg1Ptr, &seg2Ptr);
          break;
        }
# endif
        case TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256:
        case TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA256:
        case TCPIP_TLS_PSK_WITH_AES_128_GCM_SHA256:
        case TCPIP_TLS_AES_128_GCM_SHA256:
        case TCPIP_TLS_AES_256_GCM_SHA384:
        case TCPIP_TLS_CHACHA20_POLY1305_SHA256:
        {
          /* AEADBlock128 encryption */
          retVal = TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128(TlsConIdx, &seg1Ptr, &seg2Ptr);
          break;
        }
        default:    /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
        {
          /* Default case left blank intentionally */
          break;
        }
      } /* switch */
    }
  }

  return retVal;
} /* TcpIp_TlsCoreRl_EncryptCipherDependent */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(BufReq_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        Seg1Ptr,
  TcpIp_SegmentPtrType        Seg2Ptr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_RlTxFragmentLenOfTlsBufferMgmtDynType requestedRlTxLen
    = TcpIp_GetRlTxFragmentLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  /* Total size of the TCP buffer segments */
  uint32 totalTcpBufLen = Seg2Ptr->AvailLen + Seg1Ptr->AvailLen;

  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if provided buffer(s) has sufficient space and trigger Block128 streaming */
  if (totalTcpBufLen < requestedRlTxLen)
  {
    /* The provided TCP buffer segment is not sufficient, store this buffer into DataSplit struct for the next call */
    TcpIp_GetAddrTxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataPtr = Seg2Ptr->AvailPtr;
    TcpIp_GetAddrTxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataLen = (uint16)Seg2Ptr->AvailLen;
    retVal = BUFREQ_OK;
  }
  else
  {
    /* Sufficient TCP buffer available, trigger AEADBlock128 streaming */
    if (TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128StreamingMode(TlsConIdx, Seg1Ptr, Seg2Ptr) == E_OK)
    {
      retVal = BUFREQ_OK;
    }
  }

  return retVal;
} /* TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_TxCipherEncryptNull
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(BufReq_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_TxCipherEncryptNull(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        Seg1Ptr,
  TcpIp_SegmentPtrType        Seg2Ptr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType               tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_RlTxFragmentLenOfTlsBufferMgmtDynType requestedLen = TcpIp_GetRlTxFragmentLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  /* Total length of the TCP buffer segments */
  uint32 totalTcpBufLen = Seg2Ptr->AvailLen + Seg1Ptr->AvailLen;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if provided buffer has sufficient space and trigger Null streaming */
  if (totalTcpBufLen < requestedLen)
  {
    /* Store provided buffer info into the Tx data split struct */
    TcpIp_GetAddrTxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataPtr = Seg2Ptr->AvailPtr;
    TcpIp_GetAddrTxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataLen = (uint16)Seg2Ptr->AvailLen;
  }
  else
  {
    /* Sufficient TCP buffer available, trigger Null streaming */
    TcpIp_TlsCoreRl_TxCipherEncryptNullStreamingMode(TlsConIdx, Seg1Ptr, Seg2Ptr);
  }

  return BUFREQ_OK;
} /* TcpIp_TlsCoreRl_TxCipherEncryptNull() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_FixGetTcpTxBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(TCPIP_P2V(uint8), TCPIP_CODE) TcpIp_TlsCoreRl_FixGetTcpTxBuffer(TCPIP_P2C(uint8) Buffer, uint32 BufLen)
{
  TCPIP_P2V(uint8) retBufferPtr = NULL_PTR;
  const uintPtrTyp cfgStartAddr = (uintPtrTyp)TcpIp_GetAddrTcpTxBuffer(0);                                              /* PRQA S 0306 */ /* MD_TcpIp_TLS_PTR_ADDR_CAST */
  const uintPtrTyp bufferStart = (uintPtrTyp)Buffer;                                                                    /* PRQA S 0306 */ /* MD_TcpIp_TLS_PTR_ADDR_CAST */
  const uintPtrTyp bufferLen = (uintPtrTyp)BufLen;                                                                      /* PRQA S 0306 */ /* MD_TcpIp_TLS_PTR_ADDR_CAST */

  /* #10 Verify that address is greater or equal the start address */
  /* \trace TCASE-TCPIP_000697 */
  if(bufferStart >= cfgStartAddr)
  {
    /* #20 Calculate index and get buffer */
    /* \trace TCASE-TCPIP_000698 */
    uintPtrTyp tcpBuffIdx = bufferStart - cfgStartAddr;
    /* \trace TCASE-TCPIP_000698 */
    if ((tcpBuffIdx + bufferLen) <= (uintPtrTyp)TcpIp_GetSizeOfTcpTxBuffer())                                           /* PRQA S 0306 */ /* MD_TcpIp_TLS_PTR_ADDR_CAST */
    {
      retBufferPtr = TcpIp_GetAddrTcpTxBuffer((TcpIp_TcpTxBufferIterType)tcpBuffIdx);
    }
  }

  return retBufferPtr;
} /* TcpIp_TlsCoreRl_FixGetTcpTxBuffer */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_CheckTcpTxBufferInRange
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_CheckTcpTxBufferInRange(
  TCPIP_P2C(uint8) Buffer,
  uint32           BufLen)
{
  Std_ReturnType retVal = E_NOT_OK;
  /* #10 Verify that ptr is not NULL_PTR */
  /* \trace TCASE-TCPIP_000702 */
  if(Buffer != NULL_PTR)
  {
    const uintPtrTyp cfgStartAddr = (uintPtrTyp)TcpIp_GetAddrTcpTxBuffer(0);                                            /* PRQA S 0306 */ /* MD_TcpIp_TLS_PTR_ADDR_CAST */
    const uintPtrTyp cfgEndAddr   = (uintPtrTyp)TcpIp_GetAddrTcpTxBuffer(TcpIp_GetSizeOfTcpTxBuffer());                 /* PRQA S 0306 */ /* MD_TcpIp_TLS_PTR_ADDR_CAST */
    const uintPtrTyp reqEndAddr   = (uintPtrTyp)Buffer + (uintPtrTyp)BufLen;                                            /* PRQA S 0306 */ /* MD_TcpIp_TLS_PTR_ADDR_CAST */
    const uintPtrTyp bufferStart  = (uintPtrTyp)Buffer;                                                                 /* PRQA S 0306 */ /* MD_TcpIp_TLS_PTR_ADDR_CAST */
    /* Verify that our buffer pointer assumption holds. */
    /*@ assert (sizeof(void*) == sizeof(uintPtrTyp)); */

    /* #20 Verify that ptr is part of the TCP Tx buffer */
    if (
        /* Test for an overflow in the calculation */
        /* \trace TCASE-TCPIP_000712 */
        (bufferStart <= reqEndAddr)

        /* The buffer must end after or at the start of the TCP tx buffer */
        /* \trace TCASE-TCPIP_000703 */
        && (reqEndAddr >= cfgStartAddr)

        /* The buffer must start before the end of the TCP tx buffer */
        /* \trace TCASE-TCPIP_000700 */
        && (bufferStart < cfgEndAddr)

        /* The buffer must end before or at the end of the TCP tx buffer */
        /* \trace TCASE-TCPIP_000701 */
        && (reqEndAddr <= cfgEndAddr)

        /* The buffer must start after or at the start of the TCP tx buffer */
        /* \trace TCASE-TCPIP_000699 */
        && (bufferStart >= cfgStartAddr))

        /* Buffer in TCP range, corner cases */
        /* \trace TCASE-TCPIP_000720 */
        /* \trace TCASE-TCPIP_000721 */
    {
      retVal = E_OK;
    }
  }

  return retVal;
} /* TcpIp_TlsCoreRl_CheckTcpTxBufferInRange */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_TxCipherEncryptNullStreamingMode
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_TxCipherEncryptNullStreamingMode(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        Seg1Ptr,
  TcpIp_SegmentPtrType        Seg2Ptr)
{
   /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  /* Length of the total plain text in TLS buffer */
  uint32  plainTextLen = TcpIp_GetRlTxContentTypeLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  /* Length of the MAC */
  uint8  macLen = TcpIp_TlsCoreUtil_GetTxCipherMacLen(TlsConIdx);
  /* Length of plaintext in TCP segment 1 */
  uint32 plainTextLenInSeg1;
  /* Length of plaintext in TCP segment 2 */
  uint32 plainTextLenInSeg2;

  /* ----- Implementation ----------------------------------------------- */
  /* Write data and MAC to the TCP buffer. Depending on existing data in the TCP buffer there are one or two segments
     of the buffer:
     [xxxxxx<  seg2  >xxxxxxx] There is one linear block of free buffer somewhere in the middle of the buffer.
     [< seg2 >xxxxxxx< seg1 >] There is free space at the end and at the beginning of the TCP (ring-)buffer.
  */
  TCPIP_ASSERT((Seg1Ptr->AvailLen + Seg2Ptr->AvailLen) >= (uint16)(plainTextLen + macLen));

  /* Calculate the lengths of the plaintext that will be copied into the TCP buffer segment(s) */
  plainTextLenInSeg1 = TCPIP_MIN(Seg1Ptr->AvailLen, plainTextLen);
  /* If plainTextLenInSeg2 > 0, then the plaintext is split between the two segments (or entirely in segment 2).
   * Otherwise the plaintext is entirely in segment 1. */
  plainTextLenInSeg2 = plainTextLen - plainTextLenInSeg1;

  /* #10 If TCP segment 1 exists, copy plain text to fill segment 1 */
  if (plainTextLenInSeg1 != 0u)
  {
    /* Copy plaintext from TLS buffer into TCP segment 1, considering TLS buffer wraparound */
    TcpIp_TlsCoreRl_CopyFromTxBufferWithWraparound(TlsConIdx, Seg1Ptr, (uint16)plainTextLenInSeg1);
  }
  /* #20 If more plaintext present in TLS buffer, copy to segment 2 */
  if (plainTextLenInSeg2 != 0u)
  {
    /* Copy plaintext from TLS buffer into TCP segment 2, considering TLS buffer wraparound */
    TcpIp_TlsCoreRl_CopyFromTxBufferWithWraparound(TlsConIdx, Seg2Ptr, (uint16)plainTextLenInSeg2);
  }

  /* #30 Copy the Mac into the TCP buffer segment(s) if available */
  if (macLen > 0u)
  {
    TcpIp_TlsCoreRl_CopyHmacToTxBuffer(TlsConIdx, Seg1Ptr, Seg2Ptr);
  }

  TCPIP_DUMMY_STATEMENT_CONST(Seg2Ptr->AvailLen);                                                                       /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
} /* TcpIp_TlsCoreRl_TxCipherEncryptNullStreamingMode() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_CopyHmacToTxBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_CopyHmacToTxBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        Seg1,
  TcpIp_SegmentPtrType        Seg2)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  TCPIP_P2C(uint8) macPtr = TcpIp_GetAddrTlsTemporaryHmacBuffer(
    TcpIp_GetTlsTemporaryHmacBufferStartIdxOfTlsConnection(TlsConIdx));
  uint8 macLen = TcpIp_GetCipherMacKeyLengthOfTlsCipherWorker(activeTlsCipherWorkerIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Copy the Mac into the provided TCP buffer */
  TcpIp_SegmentMultiTargetMemCpy(Seg1, Seg2, macPtr, macLen);
} /* TcpIp_TlsCoreRl_CopyHmacToTxBuffer */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128WithTcpWraparound
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_TcpIp_TlsStreaming_STMIF_6080 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128WithTcpWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        TcpIpSeg1,
  TcpIp_SegmentPtrType        TcpIpSeg2)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8                       authTag[TCPIP_TLS_BLOCK128_AUTHTAG_LEN];
  TcpIp_SegmentType           authTagSeg;
  Std_ReturnType              retVal;

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_ASSERT(TcpIpSeg1->AvailLen != 0u);
  TCPIP_ASSERT(TcpIpSeg2->AvailLen != 0u);

  /* #10 Generate the Iv and copy into TcpIp buffer */
  retVal = TcpIp_TlsCoreRl_TxCipherAEADGenAndCopyBlock128Iv(TlsConIdx, TcpIpSeg1, TcpIpSeg2);

  if (retVal == E_OK)
  {
    TcpIp_SegmentInit(&authTagSeg, &authTag[0], TCPIP_TLS_BLOCK128_AUTHTAG_LEN);
    /* If TCP seg1 only contains IV, then seg1Len is 0 and seg1Ptr is not used below */
    /* #20 Encrypt the content data into the TCP buffer segment(s), and generate authentication tag */
    retVal = TcpIp_TlsCoreRl_TxCipherEncryptAEADBlock128ContentData(TlsConIdx, TcpIpSeg1, TcpIpSeg2, &authTagSeg);

    /* #30 Copy the authentication tag into TCP buffer segments */
    if (retVal == E_OK)
    {
      TcpIp_SegmentMultiTargetMemCpy(TcpIpSeg1, TcpIpSeg2, authTagSeg.BasePtr, authTagSeg.Usage);
    }
  }

  return retVal;
} /* TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128WithTcpWraparound */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128StreamingMode
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128StreamingMode(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        Seg1Ptr,
  TcpIp_SegmentPtrType        Seg2Ptr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the TCP buffer has wraparound and trigger Block128 encryption */
  if (Seg1Ptr->AvailLen  == 0u)
  {
    /* Scenario 1: Encryption with no TCP buffer wrap around */
    retVal = TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128WithSingleCall(TlsConIdx, Seg2Ptr);
  }
  else
  {
    /* Scenario 2: Encryption with TCP buffer wrap around */
    retVal = TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128WithTcpWraparound(TlsConIdx, Seg1Ptr, Seg2Ptr);
  }

  return retVal;
} /* TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128StreamingMode() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128WithSingleCall
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128WithSingleCall(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        TcpSeg)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Generate IV and set the CSM Key */
  retVal = TcpIp_TlsCoreRl_GenerateAEADBlock128IvTlsVersionDependent(TlsConIdx, TcpSeg);

  if (retVal == E_OK)
  {
    uint8  authTag[TCPIP_TLS_BLOCK128_AUTHTAG_LEN];
    TcpIp_SegmentType authTagSeg;

    TcpIp_SegmentInit(&authTagSeg, &authTag[0], TCPIP_TLS_BLOCK128_AUTHTAG_LEN);

    /* #20 Perform Block128 encryption, generate authentication tag */
    retVal = TcpIp_TlsCoreRl_EncryptAEADBlock128ContentDataWoWraparound(TlsConIdx, TcpSeg, &authTagSeg);

    /* \trace TCASE-TCPIP_000649 */
    if (retVal == E_OK)
    {
      /* #30 Copy the authentication tag into the TcpIp buffer */
      TcpIp_SegmentMemCpy(TcpSeg, authTagSeg.BasePtr, authTagSeg.Usage);
      /* Done, RL message completely inside TcpIpBuffer */
    }
  }

  return retVal;
} /* TcpIp_TlsCoreRl_TxCipherAEADEncryptBlock128WithSingleCall() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_TxCipherAEADGenAndCopyBlock128Iv
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE)  TcpIp_TlsCoreRl_TxCipherAEADGenAndCopyBlock128Iv(
  TcpIp_TlsConnectionIterType    TlsConIdx,
  TCPIP_P2V(TcpIp_SegmentType)   TcpSeg1,
  TCPIP_P2V(TcpIp_SegmentType)   TcpSeg2)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType                 retVal = E_NOT_OK;
  uint8                          tmpBlock128Iv[TCPIP_TLS_BLOCK128_EXPLICIT_IV_LEN];
  TcpIp_SegmentType              tmpBlock128IvSeg;

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_ASSERT((TcpSeg1->Size + TcpSeg2->Size) >= TCPIP_TLS_AES128_IV_LEN);

  TcpIp_SegmentInit(&tmpBlock128IvSeg, &tmpBlock128Iv[0], TCPIP_TLS_BLOCK128_EXPLICIT_IV_LEN);

  /* #10 Generate Block128 IV and set it to the CSM Key, and copy into the TcpIp buffer */
  if (TcpIp_TlsCoreRl_GenerateAEADBlock128IvTlsVersionDependent(TlsConIdx, &tmpBlock128IvSeg) == E_OK)
  {
    retVal = E_OK;
    /* For TLS 1.2 copy the generated Iv into TcpIpBuffer, considering TcpIp buffer wraparound */
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#  if(TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_12)
#  endif
    {
      TcpIp_SegmentMultiTargetMemCpy(TcpSeg1, TcpSeg2, tmpBlock128IvSeg.BasePtr, tmpBlock128IvSeg.Usage);
    }
# else
    TCPIP_DUMMY_STATEMENT(*TcpSeg1);                                                                                    /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
    TCPIP_DUMMY_STATEMENT(*TcpSeg2);                                                                                    /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
# endif
  }

  return retVal;
} /* TcpIp_TlsCoreRl_TxCipherAEADGenAndCopyBlock128Iv */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_TxCipherEncryptAEADBlock128ContentData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE)  TcpIp_TlsCoreRl_TxCipherEncryptAEADBlock128ContentData(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        TcpIpSeg1,
  TcpIp_SegmentPtrType        TcpIpSeg2,
  TcpIp_SegmentPtrType        AuthTagSeg)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType                  retVal;
  TcpIp_SizeOfTlsBufferMgmtType   tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  uint32                          plaintextDataLen = TcpIp_GetRlTxContentTypeLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the provided buffer and AEADBlock128 encrypt the content data */
  /* TcpIpSeg1->AvailLen might become zero after initialization but TcpIpSeg1->Size must be != 0 then. */
  TCPIP_ASSERT(TcpIpSeg1->Size != 0u);
  if (TcpIpSeg1->AvailLen > (plaintextDataLen + TCPIP_TLS_BLOCK128_BLOCKSIZE))
  {
    /* Scenario 1: Encrypt the data into the first segment */
    retVal = TcpIp_TlsCoreRl_EncryptAEADBlock128ContentDataWoWraparound(TlsConIdx, TcpIpSeg1, AuthTagSeg);
  }
  else /* AvailLen greater then zero, but less or equal DataLen + AES blocksize */
  {
    /* Scenario 2: Encrypt the data into both the segments */
    retVal = TcpIp_TlsCoreRl_EncryptAEADBlock128ContentDataWithTcpWraparound(TlsConIdx,
      TcpIpSeg1, TcpIpSeg2, AuthTagSeg);
  }

  return retVal;
} /* TcpIp_TlsCoreRl_TxCipherEncryptAEADBlock128ContentData */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_EncryptAEADBlock128AdHsWithoutTlsWraparound
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6010, 6030, 6050 1 */ /* MD_TcpIp_TlsStreaming_STPTH_6010, MD_TcpIp_TlsStreaming_STCYC_6030, MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_EncryptAEADBlock128AdHsWithoutTlsWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        TcpIpSeg1,
  TcpIp_SegmentPtrType        TcpIpSeg2,
  TcpIp_SegmentPtrType        AuthTagSeg)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType                                        csmRetVal;
  TcpIp_SizeOfTlsBufferMgmtType                  tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_CsmJobIdType                              encryptionJobId = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdCipherEncryptIdxOfTlsCipherWorker(
                                                                      activeTlsCipherWorkerIdx));
  TcpIp_TlsBufferTxRlSendIdxOfTlsBufferMgmtDynType      rlSendTlsBufferTxIdx = TcpIp_GetTlsBufferTxRlSendIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TCPIP_P2C(uint8)                               plaintextDataPtr = TcpIp_GetAddrTlsBufferTx(rlSendTlsBufferTxIdx);
  uint32                                         plaintextDataLen = TcpIp_GetRlTxContentTypeLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  uint32                                 availableSpaceAuthTagSeg = AuthTagSeg->AvailLen;
  uint32                                        contentDataOffset = 0u;
  uint32                                     contentDataRemaining = plaintextDataLen;
  boolean                                            finishedFlag = FALSE;
  uint32                                       availableSpaceSeg2 = 0u;
  uint8                    addAuthData[TCPIP_TLS_BLOCK128_AADATA_MAXLEN];
  TCPIP_P2C(uint8)                                 addAuthDataPtr = addAuthData;
  uint32                                           addAuthDataLen = 0u;
  TcpIp_SegmentType                                addAuthDataSeg;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Generate the AAD and Aes 128 encrypt the content data into the two TcpIp segments */

  TcpIp_SegmentInit(&addAuthDataSeg, &addAuthData[0], TCPIP_TLS_BLOCK128_AADATA_MAXLEN);
  /* Generate the AAD depending on the TLS version. */
  TcpIp_TlsCore_AEADBlock128GenerateAADataTlsVersionDependentWithPlaintextLen(TlsConIdx, &addAuthDataSeg);
  addAuthDataLen = addAuthDataSeg.Usage;

  /* Check if there is enough space in the first segment to start streaming */
  if (TcpIpSeg1->AvailLen > TCPIP_TLS_BLOCK128_BLOCKSIZE)
  {
    /* Feed one block less to start streaming */
    uint32 seg1Len = TcpIpSeg1->AvailLen - TCPIP_TLS_BLOCK128_BLOCKSIZE;
    uint32 availableSpaceSeg1 = TcpIpSeg1->AvailLen;

    /* Encrypt data which can fit into the first segment */
    csmRetVal = TCPIP_CSM_AEADEncrypt(encryptionJobId, CRYPTO_OPERATIONMODE_STREAMSTART,                                /* VCA_TCPIP_TLS_BUFFER_SEGMENT */
      plaintextDataPtr, seg1Len,
      addAuthDataPtr, addAuthDataLen,
      TcpIpSeg1->AvailPtr, &availableSpaceSeg1,
      AuthTagSeg->AvailPtr, &availableSpaceAuthTagSeg);

    TcpIp_SegmentCommit(TcpIpSeg1, availableSpaceSeg1);
    /* TcpIp_SegmentCommit() is not called for AuthTagSeg here since the CSM mode is not CRYPTO_OPERATIONMODE_FINISH or
     * CRYPTO_OPERATIONMODE_SINGLECALL. Therefore the parameter tagLengthPtr is optional and gets ignored by the CSM.
     * So if availableSpaceAuthTagSeg = 16, the CSM returns also availableSpaceAuthTagSeg = 16
     * even though there wasn't anything written to AuthTagSeg->AvailPtr. */

    contentDataOffset = seg1Len;
    contentDataRemaining -= seg1Len;
    /* Aad has been loaded into Csm */
    addAuthDataPtr = NULL_PTR;
    addAuthDataLen = 0;
  }
  else
  {
    /* Start encryption without feeding in any plaintext */
    csmRetVal = TCPIP_CSM_AEADEncrypt(encryptionJobId, CRYPTO_OPERATIONMODE_START,                                      /* VCA_TCPIP_TLS_BUFFER_SEGMENT */
      NULL_PTR, 0u,
      NULL_PTR, 0u,
      NULL_PTR, NULL_PTR,
      AuthTagSeg->AvailPtr, &availableSpaceAuthTagSeg);

    /* TcpIp_SegmentCommit() is not called for AuthTagSeg here since the CSM mode is not CRYPTO_OPERATIONMODE_FINISH or
     * CRYPTO_OPERATIONMODE_SINGLECALL. Therefore the parameter tagLengthPtr is optional and gets ignored by the CSM.
     * So if availableSpaceAuthTagSeg = 16, the CSM returns also availableSpaceAuthTagSeg = 16
     * even though there wasn't anything written to AuthTagSeg->AvailPtr. */
  }

  /* Encrypt 32 byte chunks of data until the first segment is filled up or all plaintext has been consumed */
  do
  {
    uint32 availableSpaceTmpBuf = 0;
    uint8 tmpBuffer[(TCPIP_TLS_BLOCK128_BLOCKSIZE * 4u)];
    /* TCPIP_TLS_BLOCK128_BLOCKSIZE * 2u is in value range of uint8,
     * and therefore the minimum must also be in uint8 range.
     * Therefore the cast of contentDataRemaining to uint8 is valid. */
    uint8 tmpBufLen = (uint8)TCPIP_MIN(contentDataRemaining, (TCPIP_TLS_BLOCK128_BLOCKSIZE * 2u));
    TcpIp_SegmentType tmpBufferSeg;
    TcpIp_SegmentInit(&tmpBufferSeg, &tmpBuffer[0], (TCPIP_TLS_BLOCK128_BLOCKSIZE * 4u));
    availableSpaceTmpBuf = tmpBufferSeg.AvailLen;

    /* Check if all data has been consumed, and encrypt chunks of 32 bytes into temp buffer */
    availableSpaceAuthTagSeg = AuthTagSeg->AvailLen;
    if (contentDataRemaining > 0u)
    {
      csmRetVal |= TCPIP_CSM_AEADEncrypt(encryptionJobId, CRYPTO_OPERATIONMODE_UPDATE,                                  /* VCA_TCPIP_TLS_BUFFER_SEGMENT */
        &plaintextDataPtr[contentDataOffset], tmpBufLen,
        addAuthDataPtr, addAuthDataLen,
        tmpBufferSeg.AvailPtr, &availableSpaceTmpBuf,
        AuthTagSeg->AvailPtr, &availableSpaceAuthTagSeg);

      TcpIp_SegmentCommit(&tmpBufferSeg, availableSpaceTmpBuf);
      /* TcpIp_SegmentCommit() is not called for AuthTagSeg here since the CSM mode is not CRYPTO_OPERATIONMODE_FINISH or
       * CRYPTO_OPERATIONMODE_SINGLECALL. Therefore the parameter tagLengthPtr is optional and gets ignored by the CSM.
       * So if availableSpaceAuthTagSeg = 16, the CSM returns also availableSpaceAuthTagSeg = 16
       * even though there wasn't anything written to AuthTagSeg->AvailPtr. */

      contentDataOffset += tmpBufLen;
      contentDataRemaining -= tmpBufLen;
      /* Aad has been loaded into Csm */
      addAuthDataPtr = NULL_PTR;
      addAuthDataLen = 0;
    }
    else
    {
      /* All plaintext has been consumed, stop streaming and extract the remaining ciphertext */
      csmRetVal |= TCPIP_CSM_AEADEncrypt(encryptionJobId, CRYPTO_OPERATIONMODE_FINISH,                                  /* VCA_TCPIP_TLS_BUFFER_SEGMENT */
        NULL_PTR, 0u,
        NULL_PTR, 0u,
        tmpBufferSeg.AvailPtr, &availableSpaceTmpBuf,
        AuthTagSeg->AvailPtr, &availableSpaceAuthTagSeg);

      TcpIp_SegmentCommit(&tmpBufferSeg, availableSpaceTmpBuf);
      TcpIp_SegmentCommit(AuthTagSeg, availableSpaceAuthTagSeg);
      /* Set streaming finished flag */
      finishedFlag = TRUE;
    }

    /* Copy the encrypted data from temp buffer into the provided segments */
    TcpIp_SegmentMultiTargetMemCpy(TcpIpSeg1, TcpIpSeg2, tmpBufferSeg.BasePtr, tmpBufferSeg.Usage);

    /* If streaming is complete, break */
  } while ((TcpIpSeg1->AvailLen > 0u) && (finishedFlag == FALSE));

  availableSpaceSeg2 = TcpIpSeg2->AvailLen;
  availableSpaceAuthTagSeg = AuthTagSeg->AvailLen;
  /* Encrypt rest of plaintext data if available, and stop streaming */
  if (contentDataRemaining > 0u)
  {
    csmRetVal |= TCPIP_CSM_AEADEncrypt(encryptionJobId, CRYPTO_OPERATIONMODE_UPDATE | CRYPTO_OPERATIONMODE_FINISH,      /* VCA_TCPIP_TLS_BUFFER_SEGMENT */
      &plaintextDataPtr[contentDataOffset], contentDataRemaining,
      NULL_PTR, 0u,
      TcpIpSeg2->AvailPtr, &availableSpaceSeg2,
      AuthTagSeg->AvailPtr, &availableSpaceAuthTagSeg);

    TcpIp_SegmentCommit(TcpIpSeg2, availableSpaceSeg2);
    TcpIp_SegmentCommit(AuthTagSeg, availableSpaceAuthTagSeg);
  }
  else if (finishedFlag == FALSE)
  {
    csmRetVal |= TCPIP_CSM_AEADEncrypt(encryptionJobId, CRYPTO_OPERATIONMODE_FINISH,                                    /* VCA_TCPIP_TLS_BUFFER_SEGMENT */
      NULL_PTR, 0u,
      NULL_PTR, 0u,
      TcpIpSeg2->AvailPtr, &availableSpaceSeg2,
      AuthTagSeg->AvailPtr, &availableSpaceAuthTagSeg);

    TcpIp_SegmentCommit(TcpIpSeg2, availableSpaceSeg2);
    TcpIp_SegmentCommit(AuthTagSeg, availableSpaceAuthTagSeg);
  }
  else
  {
    /* Streaming is finished, nothing to do */
  }

  return csmRetVal;
} /* TcpIp_TlsCoreRl_EncryptAEADBlock128AdHsWithoutTlsWraparound */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_EncryptAEADBlock128AdHsWithTlsWraparound
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
/* PRQA S 6010, 6030, 6050 1 */ /* MD_TcpIp_TlsStreaming_STPTH_6010, MD_TcpIp_TlsStreaming_STCYC_6030, MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_EncryptAEADBlock128AdHsWithTlsWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        TcpIpSeg1,
  TcpIp_SegmentPtrType        TcpIpSeg2,
  TcpIp_SegmentPtrType        AuthTagSeg)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType                               csmRetVal;
  TcpIp_SizeOfTlsBufferMgmtType         tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx =
    TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_CsmJobIdType encryptionJobId =
    TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdCipherEncryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));
  TcpIp_TlsBufferTxRlSendIdxOfTlsBufferMgmtDynType      rlSendTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxRlSendIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_TlsBufferTxAdHsEndIdxOfTlsBufferMgmtType   endTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);
  TcpIp_TlsBufferTxAdHsEndIdxOfTlsBufferMgmtType startTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);
  /* Total remaining plaintext in TLS buffer */
  uint32 plaintextDataLen = TcpIp_GetRlTxContentTypeLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  /* Indicates if TLS buffer has wrapped around */
  boolean switchTlswrapround = FALSE;
  /* Save length of the AuthTag buffer into local variable so it can be passed to the CSM */
  uint32 availableSpaceAuthTagSeg = AuthTagSeg->AvailLen;
  /* Plaintext consumed from TLS segment 1 */
  uint32 plaintextConsumedTlsSeg1Len = 0u;
  /* Pointer to TLS segment 1 */
  TCPIP_P2C(uint8) tlsSeg1Ptr = TcpIp_GetAddrTlsBufferTx(rlSendTlsBufferTxIdx);
  /* Pointer to TLS segment 2 */
  TCPIP_P2C(uint8) tlsSeg2Ptr = TcpIp_GetAddrTlsBufferTx(startTlsBufferTxIdx);
  /* Length of TLS segment 1 */
  uint32 tlsSeg1Len = ((uint32)endTlsBufferTxIdx - rlSendTlsBufferTxIdx);
  /* Temporary buffer */
  uint8 tmpBuffer[TCPIP_TLS_MIN_BUFFER_SIZE];
  /* Temp buffer length */
  uint32 tmpBufLen;
  TcpIp_SegmentType tmpBufferSeg;
  TcpIp_SegmentType addAuthDataSeg;
  /* AAD buffer */
  uint8 addAuthData[TCPIP_TLS_BLOCK128_AADATA_MAXLEN];
  /* Pointer to the AAD buffer */
  TCPIP_P2C(uint8) addAuthDataPtr = &addAuthData[0];
  /* Expected length of AAD */
  uint32 addAuthDataLen = 0u;
  /* Length of the ciphertext output buffer for next Csm call */
  uint32 ciphertextOutBufLen = 0u;

  /* ----- Implementation ----------------------------------------------- */
  TcpIp_SegmentInit(&tmpBufferSeg, &tmpBuffer[0], TCPIP_TLS_MIN_BUFFER_SIZE);
  TcpIp_SegmentInit(&addAuthDataSeg, &addAuthData[0], TCPIP_TLS_BLOCK128_AADATA_MAXLEN);

  /* #10 Generate the AAD */
  TcpIp_TlsCore_AEADBlock128GenerateAADataTlsVersionDependentWithPlaintextLen(TlsConIdx, &addAuthDataSeg);
  addAuthDataLen = addAuthDataSeg.Usage;

  /* For AEADBlock128, the destination buffer should be at least one block more than the data buffer */
  /* #20 Start AEADBlock128 streaming, and encrypt data before TLS wrap around if possible */
  if ((tlsSeg1Len + TCPIP_TLS_BLOCK128_BLOCKSIZE) < TcpIpSeg1->AvailLen)
  {
    /* Encrypt all data before TLS wraparound */
    ciphertextOutBufLen = TcpIpSeg1->AvailLen;
    csmRetVal = TCPIP_CSM_AEADEncrypt(encryptionJobId, CRYPTO_OPERATIONMODE_STREAMSTART,                                /* VCA_TCPIP_TLS_BUFFER_SEGMENT */
      tlsSeg1Ptr, tlsSeg1Len,
      addAuthDataPtr, addAuthDataLen,
      TcpIpSeg1->AvailPtr, &ciphertextOutBufLen,
      AuthTagSeg->AvailPtr, &availableSpaceAuthTagSeg);

    TcpIp_SegmentCommit(TcpIpSeg1, ciphertextOutBufLen);
    /* TcpIp_SegmentCommit() is not called for AuthTagSeg here since the CSM mode is not CRYPTO_OPERATIONMODE_FINISH or
     * CRYPTO_OPERATIONMODE_SINGLECALL. Therefore the parameter tagLengthPtr is optional and gets ignored by the CSM.
     * So if availableSpaceAuthTagSeg = 16, the CSM returns also availableSpaceAuthTagSeg = 16
     * even though there wasn't anything written to AuthTagSeg->AvailPtr. */

    /* Update total remaining plaintext in TLS buffer */
    plaintextDataLen -= tlsSeg1Len;
    /* No more plaintext in TLS segment 1 */
    tlsSeg1Len = 0u;
    /* Aad has been loaded */
    addAuthDataPtr = NULL_PTR;
    addAuthDataLen = 0u;
  }
  else if (TcpIpSeg1->AvailLen > TCPIP_TLS_BLOCK128_BLOCKSIZE)
  {
    uint32 copyPlainText = TcpIpSeg1->AvailLen - TCPIP_TLS_BLOCK128_BLOCKSIZE;
    /* Encrypt as much plaintext possible into the TCP segment 1 */
    ciphertextOutBufLen = TcpIpSeg1->AvailLen;
    csmRetVal = TCPIP_CSM_AEADEncrypt(encryptionJobId, CRYPTO_OPERATIONMODE_STREAMSTART,                                /* VCA_TCPIP_TLS_BUFFER_SEGMENT */
      tlsSeg1Ptr, copyPlainText,
      addAuthDataPtr, addAuthDataLen,
      TcpIpSeg1->AvailPtr, &ciphertextOutBufLen,
      AuthTagSeg->AvailPtr, &availableSpaceAuthTagSeg);

    TcpIp_SegmentCommit(TcpIpSeg1, ciphertextOutBufLen);
    /* TcpIp_SegmentCommit() is not called for AuthTagSeg here since the CSM mode is not CRYPTO_OPERATIONMODE_FINISH or
     * CRYPTO_OPERATIONMODE_SINGLECALL. Therefore the parameter tagLengthPtr is optional and gets ignored by the CSM.
     * So if availableSpaceAuthTagSeg = 16, the CSM returns also availableSpaceAuthTagSeg = 16
     * even though there wasn't anything written to AuthTagSeg->AvailPtr. */

    /* Update remaining plaintext in TLS segment 1 */
    tlsSeg1Len -= copyPlainText;
    /* Update plaintext consumed in TLS segment 1 */
    plaintextConsumedTlsSeg1Len = copyPlainText;
    /* Update total remaining plaintext in TLS buffer */
    plaintextDataLen -= copyPlainText;
    /* Aad has been loaded */
    addAuthDataPtr = NULL_PTR;
    addAuthDataLen = 0u;
  }
  else
  {
    /* Start streaming without feeding any data */
    csmRetVal = TCPIP_CSM_AEADEncrypt(encryptionJobId, CRYPTO_OPERATIONMODE_START,                                      /* VCA_TCPIP_TLS_BUFFER_SEGMENT */
      NULL_PTR, 0,
      NULL_PTR, 0u,
      NULL_PTR, NULL_PTR,
      AuthTagSeg->AvailPtr, &availableSpaceAuthTagSeg);

    /* TcpIp_SegmentCommit() is not called for AuthTagSeg here since the CSM mode is not CRYPTO_OPERATIONMODE_FINISH or
     * CRYPTO_OPERATIONMODE_SINGLECALL. Therefore the parameter tagLengthPtr is optional and gets ignored by the CSM.
     * So if availableSpaceAuthTagSeg = 16, the CSM returns also availableSpaceAuthTagSeg = 16
     * even though there wasn't anything written to AuthTagSeg->AvailPtr. */
  }

  /* #30 For remaining space in TCP segment 1, encrypt 32 byte chunks of data until TCP
         segment 1 is filled or all plaintext is consumed */
  while ((TcpIpSeg1->AvailLen > 0u)
    && (plaintextDataLen > 0u))
  {
    /* Pointer to next plaintext buffer to consume */
    TCPIP_P2C(uint8) plaintextPtr;
    /* Size of temp buffer */
    uint32 availableSpaceTmpBuf = tmpBufferSeg.AvailLen;
    availableSpaceAuthTagSeg = AuthTagSeg->AvailLen;

    /* Calculate how much content data can be consumed */
    if (tlsSeg1Len != 0u)
    {
      tmpBufLen = TCPIP_MIN(tlsSeg1Len, (TCPIP_TLS_BLOCK128_BLOCKSIZE * 2u));
    }
    else
    {
      tmpBufLen = TCPIP_MIN(plaintextDataLen, (TCPIP_TLS_BLOCK128_BLOCKSIZE * 2u));
    }

    /* Wrap around TLS buffer and update plaintext pointer, if necessary */
    if (   (switchTlswrapround == FALSE)
        && (tlsSeg1Len == 0u))
    {
      /* Wrap around TLS buffer and use TLS segment 2 */
      switchTlswrapround = TRUE;
      plaintextConsumedTlsSeg1Len = 0u;
      /* Update the plaintext pointer to TLS segment 2 */
      plaintextPtr = &tlsSeg2Ptr[0];
    }
    else if (tlsSeg1Len != 0u)
    {
      /* Update the plaintext pointer in TLS segment 1 */
      plaintextPtr = &tlsSeg1Ptr[plaintextConsumedTlsSeg1Len];
    }
    else
    {
      /* Update the plaintext pointer in TLS segment 2 */
      plaintextPtr = &tlsSeg2Ptr[plaintextConsumedTlsSeg1Len];
    }

    /* Encrypt plaintext into temporary buffer and copy into TCP segments */
    csmRetVal |= TCPIP_CSM_AEADEncrypt(encryptionJobId, CRYPTO_OPERATIONMODE_UPDATE,                                    /* VCA_TCPIP_TLS_BUFFER_SEGMENT */
      plaintextPtr, tmpBufLen,
      addAuthDataPtr, addAuthDataLen,
      tmpBufferSeg.AvailPtr, &availableSpaceTmpBuf,
      AuthTagSeg->AvailPtr, &availableSpaceAuthTagSeg);

    TcpIp_SegmentCommit(&tmpBufferSeg, availableSpaceTmpBuf);
    /* TcpIp_SegmentCommit() is not called for AuthTagSeg here since the CSM mode is not CRYPTO_OPERATIONMODE_FINISH or
     * CRYPTO_OPERATIONMODE_SINGLECALL. Therefore the parameter tagLengthPtr is optional and gets ignored by the CSM.
     * So if availableSpaceAuthTagSeg = 16, the CSM returns also availableSpaceAuthTagSeg = 16
     * even though there wasn't anything written to AuthTagSeg->AvailPtr. */

    /* Update plaintext consumed from current TLS segment */
    plaintextConsumedTlsSeg1Len += tmpBufLen;
    /* Update plaintext remaining to be encrypted */
    plaintextDataLen -= tmpBufLen;
    /* Aad has been loaded */
    addAuthDataPtr = NULL_PTR;
    addAuthDataLen = 0u;
    /* Update the plaintext remaining in TLS segment 1 */
    if (tlsSeg1Len != 0u)
    {
      tlsSeg1Len -= tmpBufLen;
    }

    /* Copy the encrypted data into the TcpIp segments */
    TcpIp_SegmentMultiTargetMemCpy(TcpIpSeg1, TcpIpSeg2, tmpBufferSeg.BasePtr, tmpBufferSeg.Usage);
    /* The data from the temp buffer has been copied and can be overwritten.
     * Initialize the segment again with the same parameters as before to reset the usage and allow an overwrite. */
    TcpIp_SegmentInit(&tmpBufferSeg, tmpBufferSeg.BasePtr, tmpBufferSeg.Size);
  }

  /* #40 If plaintext remaining before TLS buffer wraparound, encrypt directly to the second segment */
  if (tlsSeg1Len > 0u)
  {
    uint32 consumedBytes = TcpIpSeg2->AvailLen;

    availableSpaceAuthTagSeg = AuthTagSeg->AvailLen;
    csmRetVal |= TCPIP_CSM_AEADEncrypt(encryptionJobId, CRYPTO_OPERATIONMODE_UPDATE,                                    /* VCA_TCPIP_TLS_BUFFER_SEGMENT */
      &tlsSeg1Ptr[plaintextConsumedTlsSeg1Len], tlsSeg1Len,
      addAuthDataPtr, addAuthDataLen,
      TcpIpSeg2->AvailPtr, &consumedBytes,
      AuthTagSeg->AvailPtr, &availableSpaceAuthTagSeg);

    TcpIp_SegmentCommit(TcpIpSeg2, consumedBytes);
    /* TcpIp_SegmentCommit() is not called for AuthTagSeg here since the CSM mode is not CRYPTO_OPERATIONMODE_FINISH or
     * CRYPTO_OPERATIONMODE_SINGLECALL. Therefore the parameter tagLengthPtr is optional and gets ignored by the CSM.
     * So if availableSpaceAuthTagSeg = 16, the CSM returns also availableSpaceAuthTagSeg = 16
     * even though there wasn't anything written to AuthTagSeg->AvailPtr. */

    /* Update total remaining plaintext in TLS buffer */
    plaintextDataLen -= tlsSeg1Len;
    /* Aad has been loaded */
    addAuthDataPtr = NULL_PTR;
    addAuthDataLen = 0u;
    /* Wrap around Tls buffer */
    plaintextConsumedTlsSeg1Len = 0;
  }
  else if (switchTlswrapround == FALSE)
  {
    /* Wrap around Tls buffer */
    plaintextConsumedTlsSeg1Len = 0;
  }
  else
  {
    /* nothing to do */
  }

  availableSpaceAuthTagSeg = AuthTagSeg->AvailLen;
  /* Encrypt rest of data into second segment, and stop AEADBlock128 streaming */
  if (plaintextDataLen > 0u)
  {
    /* Encrypt remaining plaintext in TLS segment 2 directly into TCP segment 1 */
    ciphertextOutBufLen = TcpIpSeg2->AvailLen;
    csmRetVal |= TCPIP_CSM_AEADEncrypt(encryptionJobId, CRYPTO_OPERATIONMODE_UPDATE | CRYPTO_OPERATIONMODE_FINISH,      /* VCA_TCPIP_TLS_BUFFER_SEGMENT */
      &tlsSeg2Ptr[plaintextConsumedTlsSeg1Len], plaintextDataLen,
      addAuthDataPtr, addAuthDataLen,
      TcpIpSeg2->AvailPtr, &ciphertextOutBufLen,
      AuthTagSeg->AvailPtr, &availableSpaceAuthTagSeg);

    TcpIp_SegmentCommit(TcpIpSeg2, ciphertextOutBufLen);
    TcpIp_SegmentCommit(AuthTagSeg, availableSpaceAuthTagSeg);
  }
  else
  {
    /* If no plaintext remaining, only 1-2 blocks of ciphertext remaining to be flushed out
       Encrypt into temporary buffer and copy into TCP segments
    */
    tmpBufLen = TCPIP_TLS_BLOCK128_BLOCKSIZE * 2u;  /* is smaller as TCPIP_TLS_MIN_BUFFER_SIZE */
    /*@ assert $lengthOf(tmpBuffer) >= tmpBufLen; */
    csmRetVal |= TCPIP_CSM_AEADEncrypt(encryptionJobId, CRYPTO_OPERATIONMODE_FINISH,                                    /* VCA_TCPIP_TLS_BUFFER_SEGMENT */
      NULL_PTR, 0u,
      NULL_PTR, 0u,
      tmpBufferSeg.AvailPtr, &tmpBufLen,
      AuthTagSeg->AvailPtr, &availableSpaceAuthTagSeg);

    TcpIp_SegmentCommit(&tmpBufferSeg, tmpBufLen);
    TcpIp_SegmentCommit(AuthTagSeg, availableSpaceAuthTagSeg);

    /* Copy the ciphertext from temp buffer into TCP segments */
    TcpIp_SegmentMultiTargetMemCpy(TcpIpSeg1, TcpIpSeg2, tmpBufferSeg.BasePtr, tmpBufferSeg.Usage);
  }

  return csmRetVal;
} /* TcpIp_TlsCoreRl_EncryptAEADBlock128AdHsWithTlsWraparound */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_EncryptAEADBlock128AdHsWithTcpWraparound
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_EncryptAEADBlock128AdHsWithTcpWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        TcpIpSeg1,
  TcpIp_SegmentPtrType        TcpIpSeg2,
  TcpIp_SegmentPtrType        AuthTagSeg)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType                                           retVal;
  Std_ReturnType                                        csmRetVal;
  TcpIp_SizeOfTlsBufferMgmtType                     tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxRlSendIdxOfTlsBufferMgmtDynType      rlSendIdx =
    TcpIp_GetTlsBufferTxRlSendIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_TlsBufferTxAdHsEndIdxOfTlsBufferMgmtType   txBufferEndIdx =
    TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);
  uint32                                       plaintextDataLen =
    TcpIp_GetRlTxContentTypeLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if there is a Tls buffer wraparound and encrypt content into the TcpIp buffer segments */
  if ((rlSendIdx + plaintextDataLen) <= txBufferEndIdx)
  {
    csmRetVal = TcpIp_TlsCoreRl_EncryptAEADBlock128AdHsWithoutTlsWraparound(TlsConIdx, TcpIpSeg1, TcpIpSeg2,
      AuthTagSeg);
  }
  else
  {
    csmRetVal = TcpIp_TlsCoreRl_EncryptAEADBlock128AdHsWithTlsWraparound(TlsConIdx, TcpIpSeg1, TcpIpSeg2,
      AuthTagSeg);
  }

  /* Check if the result of the CSM operation is E_OK */
  retVal = TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, 0, 0, TCPIP_TLS_FCTID_CORE_CRYPTO_ENCRYPTADHSBUFAEADBlock128);

  return retVal;
} /* TcpIp_TlsCoreRl_EncryptAEADBlock128AdHsWithTcpWraparound() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_EncryptAEADBlock128ContentDataWithTcpWraparound
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_EncryptAEADBlock128ContentDataWithTcpWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        TcpIpSeg1,
  TcpIp_SegmentPtrType        TcpIpSeg2,
  TcpIp_SegmentPtrType        AuthTagSeg)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType                retVal = E_NOT_OK;
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxRlSendIdxOfTlsBufferMgmtDynType rlSendIdx =
    TcpIp_GetTlsBufferTxRlSendIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx); /* Start of the rl frame in the TX Buffer */

  /* ----- Implementation ----------------------------------------------- */
  /* rlSendTlsBufferTxIdx is in the range of the complete TlsBufferTx */
  /* #10 Invoke the encrypt function depending on the type of Rl content */
  if (   (rlSendIdx >= TcpIp_GetTlsBufferTxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx))
      && (rlSendIdx < TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx)))
  {
    retVal = TcpIp_TlsCoreRl_EncryptAEADBlock128AdHsWithTcpWraparound(TlsConIdx, TcpIpSeg1, TcpIpSeg2, AuthTagSeg);
  }
  else  if (   (rlSendIdx >= TcpIp_GetTlsBufferTxAlStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx))
            && (rlSendIdx < TcpIp_GetTlsBufferTxAlEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx)))
  {
    retVal = TcpIp_TlsCoreRl_EncryptAEADBlock128AlWithTcpWraparound(TlsConIdx, TcpIpSeg1, TcpIpSeg2, AuthTagSeg);
  }
  else
  {
    /* retVal is already set */
  }

  return retVal;
} /* TcpIp_TlsCoreRl_EncryptAEADBlock128ContentDataWithTcpWraparound() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_EncryptAEADBlock128ContentDataWoWraparound
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_EncryptAEADBlock128ContentDataWoWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        BufSeg,
  TcpIp_SegmentPtrType        AuthTagSeg)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType                retVal = E_NOT_OK;
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxRlSendIdxOfTlsBufferMgmtDynType rlSendIdx =
    TcpIp_GetTlsBufferTxRlSendIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx); /* Start of the rl frame in the TX Buffer */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Invoke the encrypt function depending on the type of Rl content */
  if(    (rlSendIdx >= TcpIp_GetTlsBufferTxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx))
      && (rlSendIdx < TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx)))
  {
    retVal = TcpIp_TlsCoreRl_EncryptAEADBlock128AdHs(TlsConIdx, BufSeg, AuthTagSeg);
  }
  else  if (    (rlSendIdx >= TcpIp_GetTlsBufferTxAlStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx))
             && (rlSendIdx < TcpIp_GetTlsBufferTxAlEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx)))
  {
    retVal = TcpIp_TlsCoreRl_EncryptAEADBlock128Al(TlsConIdx, BufSeg, AuthTagSeg);
  }
  else
  {
    /* retVal is already set */
  }

  return retVal;
} /* TcpIp_TlsCoreRl_EncryptAEADBlock128ContentDataWoWraparound() */

/**********************************************************************************************************************
 *  TcpIp_TlsCore_AEADBlock128GenerateAADataTlsVersionDependentWithPlaintextLen
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCore_AEADBlock128GenerateAADataTlsVersionDependentWithPlaintextLen(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        AddAuthDataSeg)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  uint16 contentLen = (uint16)TcpIp_GetRlTxContentTypeLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  uint8 contentType = TcpIp_GetRlTxContentTypeOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TCPIP_ASSERT(TcpIp_GetRlTxContentTypeLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx) <= 0xFFFF);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Depending on the TLS version the content length is different. */
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#  if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
#  endif
  {
    /* TLS 1.3 */
    contentLen += TCPIP_TLS_BLOCK128_AUTHTAG_LEN;
  }
# endif
  /* #20 Trigger the generation of the additional auth data depending on the TLS version. */
  /* Set Encrypt to true. */
  TcpIp_TlsCore_AEADBlock128GenerateAADataTlsVersionDependent(
    TlsConIdx, contentType, contentLen, TRUE, AddAuthDataSeg);

} /* TcpIp_TlsCore_AEADBlock128GenerateAADataTlsVersionDependentWithPlaintextLen */

/**********************************************************************************************************************
 *  TcpIp_TlsCore_AEADBlock128GenerateAADataTlsVersionDependent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCore_AEADBlock128GenerateAADataTlsVersionDependent(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8                       ContentType,
  uint16                      ContentLen,
  boolean                     Encrypt,
  TcpIp_SegmentPtrType        AddAuthDataSeg)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* TLS sequence number */
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  uint64                        seqNum = 0u;
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Trigger the generation of the additional auth data depending on the TLS version. */
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#  if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
#  endif
  {
    /* TLS 1.3 */
    TcpIp_Tls13CoreCrypto_AEADBlock128GenerateAAData(ContentLen, ContentType, AddAuthDataSeg);
  }
#  if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  else
#  endif
# endif
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  {
    /* TLS 1.2 */
    if (Encrypt == TRUE)
    {
      seqNum = TcpIp_GetRlTxSequenceCounterOfTlsConnectionDyn(TlsConIdx);
    }
    else
    {
      seqNum = TcpIp_GetRlRxSequenceCounterOfTlsConnectionDyn(TlsConIdx);
    }
    TcpIp_Tls12CoreCrypto_AEADBlock128GenerateAAData(seqNum, ContentLen, ContentType, AddAuthDataSeg);
  }
# endif
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_OFF)
  TCPIP_DUMMY_STATEMENT_CONST(TlsConIdx);                                                                               /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
  TCPIP_DUMMY_STATEMENT_CONST(Encrypt);                                                                                 /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
# endif
} /* TcpIp_TlsCore_AEADBlock128GenerateAADataTlsVersionDependent */

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls13CoreCrypto_AEADBlock128GenerateAAData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls13CoreCrypto_AEADBlock128GenerateAAData(
  uint16                      ContentLen,
  uint8                       Type,
  TcpIp_SegmentPtrType        AddAuthDataSeg)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* Even though the legacy_record_version was not validated
   * to match the fixed constant value in TcpIp_TlsCoreRl_ParseAndValidateRlHdr(),
   * we still can assume that it is 0x0303 since otherwise the peer violates RFC8446 chapter 5.2:
   * "The legacy_record_version field" (for the TlsCiphertext) "is always 0x0303".
   * This could lead to a decrypt alert if the peer sends a different legacy_record_version. */
  uint16                        version = ((uint16)(TCPIP_TLS_RL_VERSMAJOR) << 8u) | (uint16)(TCPIP_TLS_RL_VERSMINOR);

  /* ----- Implementation ----------------------------------------------- */
  /* Structure of the additional authentication data for TLS 1.3 is -
   * additional_data = TLSCiphertext.opaque_type || TLSCiphertext.legacy_record_version || TLSCiphertext.length
   *
   * see RFC 8446, 5.2. Record Payload Protection
   */
  /* #10 Generate the additional authentication data and copy it into the provided buffer */
  /* Copy the type to the authdata */
  TcpIp_SegmentPutUint8(AddAuthDataSeg, Type);

  /* Copy the version to the authdata */
  TcpIp_SegmentPutUint16(AddAuthDataSeg, version);

  /* Copy the length to the authdata */
  TcpIp_SegmentPutUint16(AddAuthDataSeg, ContentLen);
} /* TcpIp_Tls13CoreCrypto_AEADBlock128GenerateAAData() */
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_Tls12CoreCrypto_AEADBlock128GenerateAAData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls12CoreCrypto_AEADBlock128GenerateAAData(
  uint64                      TlsSeqNum,
  uint16                      ContentLen,
  uint8                       Type,
  TcpIp_SegmentPtrType        AddAuthDataSeg)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16                        version = ((uint16)(TCPIP_TLS_RL_VERSMAJOR) << 8u) | (uint16)(TCPIP_TLS_RL_VERSMINOR);

  /* ----- Implementation ----------------------------------------------- */
  /* Structure of the additional authentication data is -
   * |Seq No(8)       |type (1)|version(2)|length (2)|
   */
  /* #10 Generate the additional auth data and copy into provided buffer */
  /* Copy the sequence number to the authdata */
  TcpIp_SegmentPutUint64(AddAuthDataSeg, TlsSeqNum);

  /* Copy the type to the authdata */
  TcpIp_SegmentPutUint8(AddAuthDataSeg, Type);

  /* Copy the version to the authdata */
  TcpIp_SegmentPutUint16(AddAuthDataSeg, version);

  /* Copy the length to the authdata */
  TcpIp_SegmentPutUint16(AddAuthDataSeg, ContentLen);

} /* TcpIp_Tls12CoreCrypto_AEADBlock128GenerateAAData */
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_EncryptAEADBlock128AdHs
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_EncryptAEADBlock128AdHs(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        BufSeg,
  TcpIp_SegmentPtrType        AuthTagSeg)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_CsmJobIdType encryptionJobId
    = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdCipherEncryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));

  TcpIp_TlsBufferTxRlSendIdxOfTlsBufferMgmtDynType rlSendTlsBufferTxIdx
    = TcpIp_GetTlsBufferTxRlSendIdxOfTlsBufferMgmtDyn( tlsBufferMgmtIdx);

  TcpIp_TlsBufferTxAdHsEndIdxOfTlsBufferMgmtType endTlsBufferTxIdx
    = TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  TcpIp_TlsBufferTxAdHsEndIdxOfTlsBufferMgmtType startTlsBufferTxIdx
  = TcpIp_GetTlsBufferTxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  TCPIP_P2C(uint8) plaintextDataPtr = TcpIp_GetAddrTlsBufferTx(rlSendTlsBufferTxIdx);
  uint32 plaintextDataLen = TcpIp_GetRlTxContentTypeLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  uint8 addAuthData[TCPIP_TLS_BLOCK128_AADATA_MAXLEN];
  uint32 availableBufLen = BufSeg->AvailLen;
  uint32 availableAuthLen = AuthTagSeg->AvailLen;
  TcpIp_SegmentType addAuthDataSeg;

  Std_ReturnType csmRetVal = E_NOT_OK;
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  TcpIp_SegmentInit(&addAuthDataSeg, &addAuthData[0], TCPIP_TLS_BLOCK128_AADATA_MAXLEN);
  /* #10 Generate the AAD depending on the TLS version. */
  TcpIp_TlsCore_AEADBlock128GenerateAADataTlsVersionDependentWithPlaintextLen(TlsConIdx, &addAuthDataSeg);

  /*#20 Perform Aes128 Gcm encryption of data into linear TcpIp buffer considering Tls wraparound */
  if (((uint64)rlSendTlsBufferTxIdx + plaintextDataLen) <= endTlsBufferTxIdx)
  {
    /* Scenario 1: No Tls buffer wraparound */
    csmRetVal = TCPIP_CSM_AEADEncrypt(encryptionJobId, CRYPTO_OPERATIONMODE_SINGLECALL,                                 /* VCA_TCPIP_TLS_BUFFER_SEGMENT */
      plaintextDataPtr, plaintextDataLen,
      addAuthDataSeg.BasePtr, addAuthDataSeg.Usage,
      BufSeg->AvailPtr, &availableBufLen,
      AuthTagSeg->AvailPtr, &availableAuthLen);

    TcpIp_SegmentCommit(BufSeg, availableBufLen);
    TcpIp_SegmentCommit(AuthTagSeg, availableAuthLen);
  }
  else
  {
    /* Scenario 2: Tls buffer wraparound */
    uint32 dataLenAtEndOfTxBuf = ((uint32)endTlsBufferTxIdx - rlSendTlsBufferTxIdx);
    uint32 dataLenAtStartOfTxBuf = (plaintextDataLen - dataLenAtEndOfTxBuf);

    /* Feed the data till wraparound */
    csmRetVal = TCPIP_CSM_AEADEncrypt(encryptionJobId, CRYPTO_OPERATIONMODE_STREAMSTART,                                /* VCA_TCPIP_TLS_BUFFER_SEGMENT */
      plaintextDataPtr, dataLenAtEndOfTxBuf,
      addAuthDataSeg.BasePtr, addAuthDataSeg.Usage,
      BufSeg->AvailPtr, &availableBufLen,
      AuthTagSeg->AvailPtr, &availableAuthLen);

    TcpIp_SegmentCommit(BufSeg, availableBufLen);
    /* TcpIp_SegmentCommit() is not called for AuthTagSeg here since the CSM mode is not CRYPTO_OPERATIONMODE_FINISH or
     * CRYPTO_OPERATIONMODE_SINGLECALL. Therefore the parameter tagLengthPtr is optional and gets ignored by the CSM.
     * So if availableSpaceAuthTagSeg = 16, the CSM returns also availableSpaceAuthTagSeg = 16
     * even though there wasn't anything written to AuthTagSeg->AvailPtr. */

    /* Wraparound the Tls buffer */
    plaintextDataPtr = TcpIp_GetAddrTlsBufferTx(startTlsBufferTxIdx);

    availableBufLen = BufSeg->AvailLen;
    availableAuthLen = AuthTagSeg->AvailLen;

    /* Feed the rest of the data */
    csmRetVal |= TCPIP_CSM_AEADEncrypt(encryptionJobId, CRYPTO_OPERATIONMODE_UPDATE | CRYPTO_OPERATIONMODE_FINISH,      /* VCA_TCPIP_TLS_BUFFER_SEGMENT */
        plaintextDataPtr, dataLenAtStartOfTxBuf,
        NULL_PTR, 0u,
        BufSeg->AvailPtr, &availableBufLen,
        AuthTagSeg->AvailPtr, &availableAuthLen);

    TcpIp_SegmentCommit(BufSeg, availableBufLen);
    TcpIp_SegmentCommit(AuthTagSeg, availableAuthLen);
  }

  /* Check if the result of the CSM operation is E_OK */
  retVal = TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, 0, 0, TCPIP_TLS_FCTID_CORE_CRYPTO_ENCRYPTADHSBUFAEADBlock128);

  return retVal;
} /* TcpIp_TlsCoreRl_EncryptAEADBlock128AdHs() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_EncryptAEADBlock128Al
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_EncryptAEADBlock128Al(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        BufSeg,
  TcpIp_SegmentPtrType        AuthTagSeg)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_CsmJobIdType encryptionJobId =
    TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdCipherEncryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));
  TcpIp_TlsBufferTxRlSendIdxOfTlsBufferMgmtDynType rlSendTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxRlSendIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx); /* Start of the rl frame in the TX Buffer */
  TCPIP_P2C(uint8) plainTextDataPtr = TcpIp_GetAddrTlsBufferTx(rlSendTlsBufferTxIdx);
  uint32 plainTextDataLen = TcpIp_GetRlTxContentTypeLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  Std_ReturnType retVal;
  Std_ReturnType csmRetVal;
  uint8 addAuthData[TCPIP_TLS_BLOCK128_AADATA_MAXLEN];
  uint32 availableBufferLen = BufSeg->AvailLen;
  uint32 availableAuthLen = AuthTagSeg->AvailLen;
  TcpIp_SegmentType addAuthDataSeg;

  /* ----- Implementation ----------------------------------------------- */
  TcpIp_SegmentInit(&addAuthDataSeg, &addAuthData[0], TCPIP_TLS_BLOCK128_AADATA_MAXLEN);

  /* #10 Generate the AAD depending on the TLS version. */
  TcpIp_TlsCore_AEADBlock128GenerateAADataTlsVersionDependentWithPlaintextLen(TlsConIdx, &addAuthDataSeg);

  /* #20 Encrypt the data into the provided buffer and check the operation result */
  csmRetVal = TCPIP_CSM_AEADEncrypt(encryptionJobId, CRYPTO_OPERATIONMODE_SINGLECALL,                                   /* VCA_TCPIP_TLS_BUFFER_SEGMENT */
    plainTextDataPtr, plainTextDataLen,
    addAuthDataSeg.BasePtr, addAuthDataSeg.Usage,
    BufSeg->AvailPtr, &availableBufferLen,
    AuthTagSeg->AvailPtr, &availableAuthLen);

  TcpIp_SegmentCommit(BufSeg, availableBufferLen);
  TcpIp_SegmentCommit(AuthTagSeg, availableAuthLen);

  /* Check if the result of the CSM operation is E_OK */
  retVal = TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, 0, 0, TCPIP_TLS_FCTID_CORE_CRYPTO_ENCRYPTADHSBUFAEADBlock128);

  return retVal;
} /* TcpIp_TlsCoreRl_EncryptAEADBlock128Al() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_EncryptAEADBlock128AlWithTcpWraparound
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_EncryptAEADBlock128AlWithTcpWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        TcpIpSeg1,
  TcpIp_SegmentPtrType        TcpIpSeg2,
  TcpIp_SegmentPtrType        AuthTagSeg)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_CsmJobIdType encryptionJobId =
    TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdCipherEncryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));
  /* Current sendIdx */
  TcpIp_TlsBufferTxRlSendIdxOfTlsBufferMgmtDynType rlSendTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxRlSendIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  /* TLS Buffer containing plaintext data */
  TCPIP_P2C(uint8) plaintextDataPtr = TcpIp_GetAddrTlsBufferTx(rlSendTlsBufferTxIdx);
  /* Length of plaintext data */
  uint32 plaintextDataLen = TcpIp_GetRlTxContentTypeLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  /* Length of the alert ciphertext buffer */
  uint32 cipherTextDataLen = TCPIP_TLS_MIN_BUFFER_SIZE;
  Std_ReturnType csmRetVal;
  /* Buffer to store AAD */
  uint8 addAuthData[TCPIP_TLS_BLOCK128_AADATA_MAXLEN];
  /* Buffer to store the alert ciphertext temporarily */
  uint8 cipherTextBuffer[TCPIP_TLS_MIN_BUFFER_SIZE];
  /* Save length of the AuthTag buffer into local variable so it can be passed to the CSM */
  uint32 availableSpaceAuthTagSeg = AuthTagSeg->AvailLen;
  TcpIp_SegmentType cipherTextBufferSeg;
  TcpIp_SegmentType addAuthDataSeg;

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_ASSERT(plaintextDataLen <= (TcpIpSeg1->AvailLen + TcpIpSeg2->AvailLen));

  TcpIp_SegmentInit(&cipherTextBufferSeg, &cipherTextBuffer[0], TCPIP_TLS_MIN_BUFFER_SIZE);
  TcpIp_SegmentInit(&addAuthDataSeg, &addAuthData[0], TCPIP_TLS_BLOCK128_AADATA_MAXLEN);

  /* #10 Generate the AAD depending on the TLS version. */
  TcpIp_TlsCore_AEADBlock128GenerateAADataTlsVersionDependentWithPlaintextLen(TlsConIdx, &addAuthDataSeg);

  /* #20 Start AEADBlock128 streaming and encrypt alert data into the TcpIp segments */
  csmRetVal = TCPIP_CSM_AEADEncrypt(encryptionJobId, CRYPTO_OPERATIONMODE_SINGLECALL, plaintextDataPtr,
    plaintextDataLen, addAuthDataSeg.BasePtr, addAuthDataSeg.Usage, cipherTextBufferSeg.AvailPtr, &cipherTextDataLen,
    AuthTagSeg->AvailPtr, &availableSpaceAuthTagSeg);

  TcpIp_SegmentCommit(&cipherTextBufferSeg, cipherTextDataLen);
  TcpIp_SegmentCommit(AuthTagSeg, availableSpaceAuthTagSeg);

  if (csmRetVal == E_OK)
  {
    TCPIP_ASSERT(cipherTextDataLen <= (TcpIpSeg1->AvailLen + TcpIpSeg2->AvailLen));

    /* Copy the ciphertext into the TCP segments */
    TcpIp_SegmentMultiTargetMemCpy(TcpIpSeg1, TcpIpSeg2, cipherTextBufferSeg.BasePtr, cipherTextBufferSeg.Usage);
  }

  /* Check if the result of the CSM operation is E_OK */
  retVal = TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, 0, 0, TCPIP_TLS_FCTID_CORE_CRYPTO_ENCRYPTADHSBUFAEADBlock128);

  return retVal;
} /* TcpIp_TlsCoreRl_EncryptAEADBlock128AlWithTcpWraparound() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_GenerateAEADBlock128IvTlsVersionDependent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE)  TcpIp_TlsCoreRl_GenerateAEADBlock128IvTlsVersionDependent(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TCPIP_P2V(TcpIp_SegmentType)  EIvSeg)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Depending on the active TLS version generate the AEADIv. */
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#  if(TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_12)
#  endif
    {
      /* Tls 1.2 */
      retVal = TcpIp_TlsCoreCrypto_GenerateAEADBlock128Iv(TlsConIdx, EIvSeg);
    }
# endif
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#  if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
    else /* TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13 */
#  endif
    {
      /* Tls 1.3 */
      retVal = TcpIp_Tls13CoreCrypto_GenerateAEADBlock128Iv(TlsConIdx, TRUE);
    }
# endif
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_OFF)
  TCPIP_DUMMY_STATEMENT(*EIvSeg);                                                                                       /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* TcpIp_TlsCoreRl_GenerateAEADBlock128IvTlsVersionDependent() */

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreCrypto_GenerateAEADBlock128Iv
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE)  TcpIp_TlsCoreCrypto_GenerateAEADBlock128Iv(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        EIvSeg)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx);
  TcpIp_TlsCsmJobIterType encryptTlsCsmJobIdx = (TcpIp_TlsCsmJobIterType)TcpIp_GetCsmJobId(
    TcpIp_GetCsmJobIdCipherEncryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));
  TcpIp_TlsCsmKeyInfoType tmpKey; /* Temporary CSM key element */
  Std_ReturnType retVal;
  TcpIp_TlsCsmKeyInfoType txIvKey;
  uint8 txSeqNumArray[TCPIP_TLS_BLOCK128_EXPLICIT_IV_LEN];  /* tx sequence number is used as Explicit Iv (8 byte) */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Load Iv (implicit Iv + explicit Iv) into the key element */

  /* Copy the tx sequence number to the explicitIv array. */
  IpBase_PutUint64(&txSeqNumArray[0], 0, TcpIp_GetRlTxSequenceCounterOfTlsConnectionDyn(TlsConIdx));

  /* Nonce for Block128 is 12 bytes and is constructed as
   * |    Iv | Tls seq No.|
   * |0     3|4         11|
   */

  tmpKey.KeyId = TcpIp_GetHsTemporaryBufferKeyIdOfTlsHandshake(activeTlsHandshakeIdx);
  tmpKey.KeyElementId = TcpIp_GetHsCommonKeyElementIdOfTlsHandshake(activeTlsHandshakeIdx);
  tmpKey.KeyLen = 0;

  /* Copy the sequence number as explicit Iv into the tmp key */
  retVal = TcpIp_TlsCoreCrypto_ClearCsmKey(TlsConIdx, &tmpKey);
  retVal |= TCPIP_CSM_KeyElementSet(tmpKey.KeyId, tmpKey.KeyElementId, &txSeqNumArray[0], TCPIP_TLS_BLOCK128_EXPLICIT_IV_LEN);

  txIvKey.KeyId = TcpIp_GetCsmReferencedKeyIdOfTlsCsmJob(encryptTlsCsmJobIdx);
  txIvKey.KeyElementId = CRYPTO_KE_CIPHER_IV;

  /* Copy explicit Iv (sequence no.) from tmp key into key and set key to valid */
  retVal |= TCPIP_CSM_KeyElementCopyPartial(
    tmpKey.KeyId,
    tmpKey.KeyElementId,
    0,
    TCPIP_TLS_BLOCK128_IMPLICIT_IV_LEN,
    TCPIP_TLS_BLOCK128_EXPLICIT_IV_LEN,
    txIvKey.KeyId,
    txIvKey.KeyElementId
  );

  retVal |= TCPIP_CSM_KeySetValid(txIvKey.KeyId);

  /* #20 If key is valid, copy the explicit Iv into provided buffer */
  if (retVal == E_OK)
  {
    TcpIp_SegmentMemCpy(EIvSeg, &txSeqNumArray[0], TCPIP_TLS_BLOCK128_EXPLICIT_IV_LEN);
  }
  else
  {
    /* if not successful, report user error */
    TcpIp_TlsUserErrorType userError;

    userError.FunctionId = TCPIP_TLS_FCTID_CORE_CRYPTO_SETAESIVVALUE;
    userError.UserErrorId = TCPIP_TLS_ERRORID_CRYPTO_SETAESIVVALUE_FAILED;
    userError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(userError);
  }

  return retVal;
} /* TcpIp_TlsCoreCrypto_GenerateAEADBlock128Iv() */
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_CopyFromTxBufferWithWraparound
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_CopyFromTxBufferWithWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        BufSeg,
  uint16                      CopyCnt)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Invoke the copy function depending on the Rl content type */
  switch (TcpIp_GetRlTxContentTypeOfTlsBufferMgmtDyn(tlsBufferMgmtIdx))
  {
    case TCPIP_TLS_CT_HS:
    case TCPIP_TLS_CT_AD:
    {
      TcpIp_TlsCoreRl_CopyFromTxBufferAdHsWithWraparound(TlsConIdx, BufSeg, CopyCnt);
      break;
    } /* case TCPIP_TLS_CT_HS | TCPIP_TLS_CT_AD */
    case TCPIP_TLS_CT_CCS:
    {
      TcpIp_TlsCoreRl_CopyFromTxBufferCcs(TlsConIdx, BufSeg, CopyCnt);
      break;
    } /* case TCPIP_TLS_CT_CCS */
    case TCPIP_TLS_CT_AL:
    {
      TcpIp_TlsCoreRl_CopyFromTxBufferAl(TlsConIdx, BufSeg, CopyCnt);
      break;
    } /* case TCPIP_TLS_CT_AL */
    default:    /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
    {
      /* Default case left blank intentionally */
      break;
    }
  } /* switch */
} /* TcpIp_TlsCoreRl_CopyFromTxBufferWithWraparound() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_CopyFromTxBufferAdHsWithWraparound
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_CopyFromTxBufferAdHsWithWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        BufSeg,
  uint16                      CopyCnt)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxRlSendIdxOfTlsBufferMgmtDynType rlSendTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxRlSendIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx); /* Start of the rl frame in the TX Buffer */

  TcpIp_TlsBufferTxAdHsEndIdxOfTlsBufferMgmtType endTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx); /* End of the complete TX Buffer */

  TcpIp_TlsBufferTxAdHsStartIdxOfTlsBufferMgmtType startTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx); /* Start of the TX Buffer */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Copy requested data into provided buffer considering wraparound, and update Rl send Idx */
  if ((rlSendTlsBufferTxIdx + CopyCnt) < endTlsBufferTxIdx)
  {
    /* Data lies linear in the TLS tx buffer without wrapping around */
    TcpIp_SegmentMemCpy(BufSeg, TcpIp_GetAddrTlsBufferTx(rlSendTlsBufferTxIdx), CopyCnt);
    TcpIp_AddTlsBufferTxRlSendIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, CopyCnt);
  }
  else
  {
    /* Data in the TLS Tx buffer is either wrapped around or aligned to the end of the buffer (SendIdx == EndTlsBufferTxIdx) */
    uint32 firstCopyLen = ((uint32)endTlsBufferTxIdx - rlSendTlsBufferTxIdx); /* first length to be copied */
    uint32 secondCopyLen = (CopyCnt - firstCopyLen); /* second length to be copied */

    TcpIp_SegmentMemCpy(BufSeg, TcpIp_GetAddrTlsBufferTx(rlSendTlsBufferTxIdx), firstCopyLen);
    TcpIp_SegmentMemCpy(BufSeg, TcpIp_GetAddrTlsBufferTx(startTlsBufferTxIdx), secondCopyLen);

    TcpIp_SetTlsBufferTxRlSendIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, (startTlsBufferTxIdx + (uint16)secondCopyLen));
  }
} /* TcpIp_TlsCoreRl_CopyFromTxBufferAdHsWithWraparound() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_CopyFromTxBufferCcs
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_CopyFromTxBufferCcs(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        BufSeg,
  uint16                      CopyCnt)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxRlSendIdxOfTlsBufferMgmtDynType rlSendTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxRlSendIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx); /* Start of the RL frame in the TX Buffer */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Copy Ccs data into provided buffer */
  TcpIp_SegmentMemCpy(BufSeg, TcpIp_GetAddrTlsBufferTx(rlSendTlsBufferTxIdx), CopyCnt);

} /* TcpIp_TlsCoreRl_CopyFromTxBufferCcs() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_CopyFromTxBufferAl
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_CopyFromTxBufferAl(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SegmentPtrType        BufSeg,
  uint16                      CopyCnt)
{
  /* ----- Local Variables ---------------------------------------------- */
 TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsBufferTxRlSendIdxOfTlsBufferMgmtDynType rlSendTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxRlSendIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx); /* Start of the RL frame in the TX Buffer */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Copy alert data into provided buffer */
  TcpIp_SegmentMemCpy(BufSeg, TcpIp_GetAddrTlsBufferTx(rlSendTlsBufferTxIdx), CopyCnt);

  /* Update SendIdx with copied length. */
  TcpIp_SetTlsBufferTxRlSendIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, (rlSendTlsBufferTxIdx + CopyCnt));

} /* TcpIp_TlsCoreRl_CopyFromTxBufferAl() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_Transmit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_Transmit(
  TcpIp_TlsConnectionIterType             TlsConIdx,
  TcpIp_TlsBufferTxIterType               TxStartIdx,
  TcpIp_SizeOfTlsBufferTxType             TxLen,
  uint8                                   ContentType)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_ActiveMaxTxRlSizeOfTlsConnectionDynType activeMaxTxRlSize
    = TcpIp_GetActiveMaxTxRlSizeOfTlsConnectionDyn(TlsConIdx);

  uint8 rlContentType = ContentType;

  TcpIp_SizeOfTlsBufferTxType localTxLen = TxLen;

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the transmitted length exceeds the maximum supported record layer limit. */
  /* This limit can be negotiated via the TLS extension in the hello messages */
  if (localTxLen <= activeMaxTxRlSize)
  {
    /* #20 Frame fits into one record layer frame - start transmitting of single record layer frame */
    retVal = TcpIp_TlsCoreRl_TransmitFrame(TlsConIdx, TxStartIdx, localTxLen, rlContentType);
  }
  else
  {
    /* #30 Frame must be fragmented into multiple record layer frames */
    retVal = TcpIp_TlsCoreRl_FragmentFrameAndTransmit(TlsConIdx, TxStartIdx, localTxLen, rlContentType);
  }


  return retVal;
} /* TcpIp_TlsCoreRl_Transmit() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_IncrementTlsBufferTxAdHsReadIdxWithWraparound
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_IncrementTlsBufferTxAdHsReadIdxWithWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_SizeOfTlsBufferTxType Value)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferTxAdHsReadIdxOfTlsBufferMgmtDynType txAdHsReadIdx
    = TcpIp_GetTlsBufferTxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  TcpIp_TlsBufferTxAdHsEndIdxOfTlsBufferMgmtType txAdHsEndIdx
    = TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  TcpIp_TlsBufferTxAdHsStartIdxOfTlsBufferMgmtType txAdHsStartIdx
    = TcpIp_GetTlsBufferTxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_VENTER_CRITICAL_SECTION();

  uint32 newReadIndex = 0u;
  /* #10 Adjust the AdHs Read Index under consideration of wraparound at the end of the TxBuffer */
  /* The return value can be ignored here since the indices must be correct. */
  (void)TcpIp_GetIncrementedRingBufferIndex((uint32)txAdHsReadIdx, (uint32)Value,
    (uint32)txAdHsStartIdx, (uint32)txAdHsEndIdx, &newReadIndex);
  TcpIp_SetTlsBufferTxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
    (TcpIp_TlsBufferTxAdHsReadIdxOfTlsBufferMgmtDynType)newReadIndex);

  /* fillLevel should never be negative */
  TCPIP_ASSERT(((sint64)TcpIp_GetAdTxFillLevelOfTlsBufferMgmtDyn(tlsBufferMgmtIdx) - Value) >= 0u);

  /* #20 Adjust the Application data fill level by subtracting the copied bytes */
  TcpIp_SubAdTxFillLevelOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, Value);

  TCPIP_VLEAVE_CRITICAL_SECTION();

} /* TcpIp_TlsCoreRl_IncrementTlsBufferTxAdHsReadIdxWithWraparound() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_IncrementRxAdHsReadIdxWithWraparound
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_IncrementRxAdHsReadIdxWithWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint32 Length)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType rxAdHsReadIdx
    = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  TcpIp_SizeOfTlsBufferRxType rxAdHsReadMaxIdx
    = TcpIp_TlsCoreRl_GetReadMaxIdxForContentType(TlsConIdx, TCPIP_TLS_CT_AD);

  TcpIp_TlsBufferRxAdHsStartIdxOfTlsBufferMgmtType rxAdHsStartIdx
    = TcpIp_GetTlsBufferRxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Update Rx read index considering buffer wraparound */
  if ((rxAdHsReadIdx + Length) < rxAdHsReadMaxIdx)
  {
    TcpIp_SetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
      ((TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType)(rxAdHsReadIdx + Length)));
  }
  else
  {
    /* If wraparound, calculate the new length at the beginning of the buffer and wrap the buffer around */
    uint32 newStartOffset = (Length - ((uint32)rxAdHsReadMaxIdx - rxAdHsReadIdx));

    TcpIp_SetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
      ((TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType)(rxAdHsStartIdx + newStartOffset)));

  }

} /* TcpIp_TlsCoreRl_IncrementRxAdHsReadIdxWithWraparound() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_IncrementUlRxIndIdxWithWraparound
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_IncrementUlRxIndIdxWithWraparound(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint32 Length)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* Variable to store the position of unforwarded data in TLS Rx AdHs buffer */
  TcpIp_TlsBufferRxUlRxIndIdxOfTlsBufferMgmtDynType ulRxIndIdx
    = TcpIp_GetTlsBufferRxUlRxIndIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  TcpIp_SizeOfTlsBufferRxType rxAdHsReadMaxIdx
    = TcpIp_TlsCoreRl_GetReadMaxIdxForContentType(TlsConIdx, TCPIP_TLS_CT_AD);

  TcpIp_TlsBufferRxAdHsStartIdxOfTlsBufferMgmtType rxAdHsStartIdx
    = TcpIp_GetTlsBufferRxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Update ulRxIndIdx with data forwarded considering buffer wraparound */
  if ((ulRxIndIdx + Length) < rxAdHsReadMaxIdx)
  {
    TcpIp_SetTlsBufferRxUlRxIndIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
      ((TcpIp_TlsBufferRxUlRxIndIdxOfTlsBufferMgmtDynType)(ulRxIndIdx + Length)));
  }
  else /* if ((ulRxIndIdx + Length) >= rxAdHsLastEndIdx) */
  {
    /* Data is wrapped around, so recalculate new newUlRxIndIdx */
    uint32 newUlRxIndIdx = (Length - ((uint32)rxAdHsReadMaxIdx - ulRxIndIdx));

    TcpIp_SetTlsBufferRxUlRxIndIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
      ((TcpIp_TlsBufferRxUlRxIndIdxOfTlsBufferMgmtDynType)(rxAdHsStartIdx + newUlRxIndIdx)));
  }
} /* TcpIp_TlsCoreRl_IncrementUlRxIndIdxWithWraparound() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_TransmitFrame
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_TransmitFrame(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferTxIterType ContentTypeTxStartIdx,
  TcpIp_SizeOfTlsBufferTxType PlaintextTxLen,
  CONST(uint8, AUTOMATIC) ContentType)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  uint32 encryptedTxFragLen;
  TcpIp_SizeOfTlsBufferTxType localPlaintextTxLen = PlaintextTxLen;
  uint8 localContentType = ContentType;
  Std_ReturnType retVal = E_NOT_OK;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 For TLS 1.3, add the inner context type and change the content type used in the RL header. */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
  {
    TcpIp_Tls13CoreRl_AddInnerPlaintextContentTypeIfNecessary(TlsConIdx, ContentTypeTxStartIdx, &localPlaintextTxLen, &localContentType);
  }
# endif

  encryptedTxFragLen = TcpIp_TlsCoreRl_CalcContentTypeLenCipherDependent(TlsConIdx, (uint32)localPlaintextTxLen,
    TcpIp_GetActiveCipherTxOfTlsConnectionDyn(TlsConIdx));
  /* Set the total length requested for this transmit call */
  TcpIp_SetRlTxFragmentLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, encryptedTxFragLen);
  /* Set the startIdx of the Tx data for this transmit call */
  TcpIp_SetTlsBufferTxRlSendIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, (TcpIp_TlsBufferTxRlSendIdxOfTlsBufferMgmtDynType)ContentTypeTxStartIdx);
  /* Set the content type for this transmit call */
  TcpIp_SetRlTxContentTypeOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, localContentType);
  /* Set the length of the data for this transmit call */
  TcpIp_SetRlTxContentTypeLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, (uint32)localPlaintextTxLen);

  /* #20 If enough space is available in TcpIp buffer, trigger transmission of RL header and data, and notify upper layer if successful. */
  if (TcpIp_TlsCoreRl_CheckTcpBuffer(TlsConIdx, encryptedTxFragLen) == E_OK)
  {
    /* Trigger transmission of RL header and data frame */
    if (   (TcpIp_TlsCoreRl_TransmitFrameHdr(TlsConIdx) == E_OK)                                                        /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
        && (TcpIp_TlsCoreRl_TransmitFrameCiphertext(TlsConIdx) == E_OK))
    {
      /* Notify upper layer about transmitted data, if the content type is application data
       * (in the TLS 1.3 case the inner plaintext content type). */
      if (ContentType == TCPIP_TLS_CT_AD)
      {
        TcpIp_TlsCoreRl_TxConfirmation(TlsConIdx);

        /* #30 Increment the ReadIdx of the TX Buffer under consideration of the wraparound */
        /* Use PlaintextTxLen so that in the TLS 1.3 case the inner plaintext content type is not included. */
        TcpIp_TlsCoreRl_IncrementTlsBufferTxAdHsReadIdxWithWraparound(TlsConIdx, PlaintextTxLen);
      }

      /* Increment the RL Sequence counter for the transmit direction */
      TcpIp_IncRlTxSequenceCounterOfTlsConnectionDyn(TlsConIdx);

      /* Reset the frame specific variables */
      TcpIp_SetRlTxCopiedLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, 0u);
      TcpIp_SetRlTxFragmentLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, 0u);
      TcpIp_SetTlsBufferTxRlSendIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_NO_TLSBUFFERTXRLSENDIDXOFTLSBUFFERMGMTDYN);
      TcpIp_SetRlTxContentTypeOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_CT_INVALID);
      TcpIp_SetRlTxContentTypeLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, 0u);
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
      {
        /* It is possible that the active version is already set to 1.3 (ServerHello received and parsed),
         * but the handshake keys are not yet calculated.
         * If in this state a message needs to be transmitted (most likely an alert) it won't be encrypted
         * and therefore no inner plaintext needs to be reset. */
        if (TcpIp_GetActiveCipherTxOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_NULL_WITH_NULL_NULL)
        {
          TcpIp_SetRlTxInnerPlaintextContentTypeOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_CT_INVALID);

          /* Write the stored and overwritten payload byte back to the TxBuffer. This is needed for fragmented data if a
           * payload byte was temporarily overwritten by the inner content type. */
          TcpIp_MemSetSafe(TcpIp_GetAddrTlsBufferTx(0),
            TcpIp_GetTlsBufferTxByteOverwrittenByInnerPlainTextContentTypeIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx),
            TcpIp_GetSizeOfTlsBufferTx(),
            TcpIp_GetRlTxValueOfByteOverwrittenByInnerPlainTextContentTypeOfTlsBufferMgmtDyn(tlsBufferMgmtIdx),
            TCPIP_TLS13_INNERPLAINTEXTCONTENTTYPELEN);

          TcpIp_SetTxInnerContentTypeAddedOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, FALSE);
        }
      }
# endif

      retVal = E_OK;
    }
    else
    {
      /* Trigger Alert if tx fails */
      TcpIp_TlsCoreRl_HandleErrorWhileTransmit(TlsConIdx, (TcpIp_TlsUserErrorIdType)TCPIP_TLS_ERRORID_RL_TX_FAILED);
    }
  }
  else
  {
    /* Not enough space in TCP buffer, retry later */
  }

  return retVal;
} /* TcpIp_TlsCoreRl_TransmitFrame() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_FragmentFrameAndTransmit
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_FragmentFrameAndTransmit(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferTxIterType TxStartIdx,
  TcpIp_SizeOfTlsBufferTxType TxLen,
  CONST(uint8, AUTOMATIC) ContentType)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferTxAdHsStartIdxOfTlsBufferMgmtType txAdHsStartIdx
    = TcpIp_GetTlsBufferTxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  TcpIp_TlsBufferTxAdHsEndIdxOfTlsBufferMgmtType txAdHsEndIdx
    = TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  TcpIp_SizeOfTlsBufferTxType txFragmentLen; /* Length of the current record layer fragment */
  TcpIp_SizeOfTlsBufferTxType totalTxLen = 0u; /* Total length of plaintext queued for Tx */
  TcpIp_TlsBufferTxIterType txFragmentStartIdx = TxStartIdx; /* Start index of the plaintext to be transmitted */

  TcpIp_ActiveMaxTxRlSizeOfTlsConnectionDynType activeMaxTxRlSize
    = TcpIp_GetActiveMaxTxRlSizeOfTlsConnectionDyn(TlsConIdx);

  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Repeatedly invoke the TcpIp_TlsCoreRl_TransmitFrame until all the plaintext has been queued for transmission */
  while (totalTxLen < TxLen)
  {
    /* #20 Calculate how much plaintext can fit into the current RL fragment */
    if ((TxLen - totalTxLen) < activeMaxTxRlSize)
    {
      /* If less than max fragment length of data left, update the tx fragment length */
      txFragmentLen = TxLen - totalTxLen;
    }
    else
    {
      /* Else transmit maximum fragment length */
      txFragmentLen = activeMaxTxRlSize;
    }

    /* #30 Send possible plaintext in the current RL frame */
    if (TcpIp_TlsCoreRl_TransmitFrame(TlsConIdx, txFragmentStartIdx, txFragmentLen, ContentType) == E_OK)
    {
      /* #40 If transmission successfully queued, point to the next data */
      if ((txFragmentStartIdx + txFragmentLen) <= txAdHsEndIdx)
      {
        txFragmentStartIdx += txFragmentLen;
      }
      else
      {
        txFragmentStartIdx = txAdHsStartIdx + txFragmentLen - (txAdHsEndIdx - txFragmentStartIdx);
      }

      /* Increment total length transmitted */
      totalTxLen += txFragmentLen;
    }
    else
    {
      /* #50 If transmission failed, break and return */
      retVal = E_NOT_OK;
      break;
    }
  }

  return retVal;
} /* TcpIp_TlsCoreRl_FragmentFrameAndTransmit() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_CheckTcpBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_CheckTcpBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint32                      CipherTextTxLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  TcpIp_SizeOfSocketTcpDynType socketTcpIdx = TCPIP_SOCKET_IDX_TO_TCP_IDX(TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(
                                                TlsConIdx));
  TcpIp_SizeOfTcpTxBufferDescType tcpTxBufferDescIdx = TcpIp_GetTcpTxBufferDescIdxOfSocketTcpDyn(socketTcpIdx);
  TcpIp_SizeOfTcpTxBufferType     tcpTxBufferSize = TcpIp_GetTcpTxBufferLengthOfTcpTxBufferDesc(tcpTxBufferDescIdx);
  TcpIp_SizeOfTcpTxBufferType     tcpTxBufferFillLevel = TcpIp_GetFillLevelOfTcpTxBufferDescDyn(tcpTxBufferDescIdx);

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_ASSERT(tcpTxBufferDescIdx < TcpIp_GetSizeOfTcpTxBufferDesc());
  TCPIP_ASSERT(tcpTxBufferSize >= tcpTxBufferFillLevel);

  /* #10 Check that the total ciphertext data fits into the remaining space in the TCP ring buffer. */
  if ((CipherTextTxLen + TCPIP_TLS_RLHDRLEN) <= (uint32)(tcpTxBufferSize - tcpTxBufferFillLevel))
  {
    retVal = E_OK;
  }

  return retVal;
} /* TcpIp_TlsCoreRl_CheckTcpBuffer() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_TransmitFrameHdr
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_TransmitFrameHdr(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_SizeOfSocketDynType socketIdx  = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  if (socketIdx < TcpIp_GetSizeOfSocketDyn())
  {
    uint16 recordLayerLen = (uint16)TcpIp_GetRlTxFragmentLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
    uint8 contentType = TcpIp_GetRlTxContentTypeOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
    uint8 rlHdr[TCPIP_TLS_RLHDRLEN];

    /* #10 Build the Rl header */
    /* Copy the Content Type of this frame */
    IpBase_PutUint8(&rlHdr[TCPIP_TLS_RLCT_OFFSET], 0, contentType);

    /* Copy the Major and Minor version number */
    IpBase_PutUint8(&rlHdr[TCPIP_TLS_RLVERSMAJOR_OFFSET], 0, TCPIP_TLS_RL_VERSMAJOR);
    IpBase_PutUint8(&rlHdr[TCPIP_TLS_RLVERSMINOR_OFFSET], 0, TCPIP_TLS_RL_VERSMINOR);

    /* Copy the length of this frame */
    IpBase_PutUint16(&rlHdr[TCPIP_TLS_RLLEN_OFFSET], 0, recordLayerLen );

    /* #20 Transmit the frame via direct data provision */
    if (TcpIp_TcpTransmitInternal(socketIdx, &rlHdr[0], TCPIP_TLS_RLHDRLEN, FALSE) == E_OK)
    {
      /* Frame transmitted succesfully - return E_OK */
      retVal = E_OK;
    }
  }
  else
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);

    /* retVal already set */
  }

  return retVal;
} /* TcpIp_TlsCoreRl_TransmitFrameHdr() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_TransmitFrameCiphertext
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_TransmitFrameCiphertext(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfSocketDynType socketIdx = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  if (socketIdx < TcpIp_GetSizeOfSocketDyn())
  {
    TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
    uint32 txLength = TcpIp_GetRlTxFragmentLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

    /* #10 Trigger TCP transmission of the data in the Tls buffer */
    if (TcpIp_TcpTransmitInternal(socketIdx, NULL_PTR, txLength, TRUE) == E_OK)
    {
      /* Frame transmitted succesfully - return E_OK */
      retVal = E_OK;
    }
  }
  else
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);

    /* retVal already set */
  }

  return retVal;
} /* TcpIp_TlsCoreRl_TransmitFrameCiphertext() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_CalcContentTypeLenCipherDependent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL_INLINE FUNC(uint32, TCPIP_CODE) TcpIp_TlsCoreRl_CalcContentTypeLenCipherDependent(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint32, AUTOMATIC)    ContentTypeLen,
  TcpIp_TlsCipherDataType     Cipher)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 calculatedLen = 0;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Calculate length, including authentication and padding */
  switch (Cipher)
  {
    case TCPIP_TLS_NULL_WITH_NULL_NULL:
    {
      calculatedLen = ContentTypeLen;
      break;
    }
    case TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256:
    case TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256:
    case TCPIP_TLS_PSK_WITH_AES_128_CBC_SHA256:
    {
      uint32 calcAesInputLen = (ContentTypeLen + TCPIP_TLS_HASH_SHA256_LEN + TCPIP_TLS_CBC_PADDING_BYTE_LEN_LEN);
      TcpIp_SetAes128CbcPaddingByteOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_GET_AES128CBC_PADDING_LEN(calcAesInputLen));
      calculatedLen = (calcAesInputLen + TCPIP_TLS_AES128_IV_LEN + TcpIp_GetAes128CbcPaddingByteOfTlsConnectionDyn(TlsConIdx));
      break;
    }
    case TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256:
    case TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA256:
    case TCPIP_TLS_PSK_WITH_AES_128_GCM_SHA256:
    case TCPIP_TLS_PSK_WITH_AES_256_GCM_SHA384:
    {
      calculatedLen = (TCPIP_TLS_BLOCK128_EXPLICIT_IV_LEN + ContentTypeLen + TCPIP_TLS_BLOCK128_AUTHTAG_LEN);
      break;
    }
    case TCPIP_TLS_AES_128_GCM_SHA256:
    case TCPIP_TLS_AES_256_GCM_SHA384:
    case TCPIP_TLS_CHACHA20_POLY1305_SHA256:
    {
      calculatedLen = (ContentTypeLen + TCPIP_TLS_BLOCK128_AUTHTAG_LEN);
      break;
    }
    case TCPIP_TLS_ECDHE_ECDSA_WITH_NULL_SHA:
    case TCPIP_TLS_ECDH_ECDSA_WITH_NULL_SHA:
    case TCPIP_TLS_PSK_WITH_NULL_SHA:
    {
      calculatedLen = (ContentTypeLen + TCPIP_TLS_HASH_SHA1_LEN);
      break;
    }
    case TCPIP_TLS_PSK_WITH_NULL_SHA256:
    {
      calculatedLen = (ContentTypeLen + TCPIP_TLS_HASH_SHA256_LEN);
      break;
    }
    case TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA:
    case TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA:
    case TCPIP_TLS_PSK_WITH_AES_128_CBC_SHA:
    {
      uint32 calcAesInputLen = (ContentTypeLen + TCPIP_TLS_HASH_SHA1_LEN + TCPIP_TLS_CBC_PADDING_BYTE_LEN_LEN);

      TcpIp_SetAes128CbcPaddingByteOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_GET_AES128CBC_PADDING_LEN(calcAesInputLen));
      calculatedLen = (calcAesInputLen + TCPIP_TLS_AES128_IV_LEN + TcpIp_GetAes128CbcPaddingByteOfTlsConnectionDyn(TlsConIdx));
      break;
    }
    default:    /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
    {
      /* This case is never reached */
      break;
    }
  }

  return calculatedLen;
} /* TcpIp_TlsCoreRl_CalcContentTypeLenCipherDependent() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_CalcHmacCipherDependent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_CalcHmacCipherDependent(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 TcpBufLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherDataType activeCipherIdx = TcpIp_GetActiveCipherTxOfTlsConnectionDyn(TlsConIdx);
  Std_ReturnType retVal = E_OK;
  boolean skipHmacCalculation;

  /* Check if HMAC calculation can be skipped. If the input data is split in two parts, the HMAC calculation can be done
  during the second call. */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_RlTxFragmentLenOfTlsBufferMgmtDynType requestedRlTxLen;
  uint32 totalTcpBufLen;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if all input data is available to do the MAC calculation. */
  requestedRlTxLen = TcpIp_GetRlTxFragmentLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  totalTcpBufLen = (uint32)TcpBufLength + (uint32)TcpIp_GetAddrTxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataLen;

  /* Check if provided TCP buffer(s) has sufficient space and trigger MAC calculation. */
  if (totalTcpBufLen < requestedRlTxLen)
  {
    /* This is the first part of a message split in the TLS TxBuffer, so the MAC calculation can be skipped. */
    skipHmacCalculation = TRUE;
  }
  else
  {
    skipHmacCalculation = FALSE;
  }

  /* #20 Invoke the appropriate MAC calculation function. */
  if (TcpIp_TlsCoreRl_CheckIfCipherRequiresVerification(activeCipherIdx) == TRUE)
  {
    if (skipHmacCalculation == FALSE)
    {
      retVal = TcpIp_TlsCoreRl_CalcHmacShaContentTypeDependent(TlsConIdx);
    }
  }

  return retVal;
} /* TcpIp_TlsCoreRl_CalcHmacCipherDependent() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_RxIndication
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_RxIndication(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  if (   (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)                                   /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
      && (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_ESTABLISHED)
      && (TcpIp_GetLastReceivedContentTypeOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CT_HS) /* inner content type */ )
    {
      /* #10 Do not set a flag to trigger content specific processing. */

      /* Special handling for handshake messages after the TLS handshake is completed.
       * Because all encrypted messages in TLS 1.3 have the outer content type "application data",
       * they are all decrypted into the same Rx plaintext buffer.
       * Handshake messages that are received after the handshake has completed have to be handled and removed from the
       * Rx buffer immediately, and obviously they shall not be processed further in TcpIp_TlsCoreMainFunction_RxHs. */
    }
    else
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
    {
      /* #20 Set the Rx Indication flag to TRUE */
      /* The content specific Rx main functions are triggered through setting the Rx Indication flag to TRUE
       * and setting the LastReceivedContentType to the corresponding content type. */
      TcpIp_SetRlRxIndicationFlagOfTlsConnectionDyn(TlsConIdx, TRUE);
    }
} /* TcpIp_TlsCoreRl_RxIndication() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_TxConfirmation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_TcpIp_TlsRuntimecheck_STMIF_6080 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_TxConfirmation(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SocketDynIterType socketIdx = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  if (socketIdx < TcpIp_GetSizeOfSocketDyn())
  {
    TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
    uint32 contentTypeTxLen = TcpIp_GetRlTxContentTypeLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

    /* Remove the inner content type field from content length in TLS 1.3 case. */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
    {
      contentTypeTxLen--;
    }
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */

    /* #10 If connection is established, forward Tx confirmation to upper layer */
    if ((TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_ESTABLISHED))
    {
      /* Forward the Tx confirmation for the content data */
      if (contentTypeTxLen <= TCPIP_TX_INDICATION_LEN_MAX)
      {
        TcpIp_Tcp_TlsTxConfirmation(socketIdx, (uint16)contentTypeTxLen);
      }
      else
      {
        /* If content data has multiple parts, forward confirmation sufficient times to UL */
        uint16 txConfLen;
        uint32 remainingTxConfLen = contentTypeTxLen;
        /* Iterate over all given data */
        while (remainingTxConfLen > 0u)
        {
          if (remainingTxConfLen > TCPIP_TX_INDICATION_LEN_MAX)
          {
            txConfLen = (uint16)TCPIP_TX_INDICATION_LEN_MAX;
          }
          else
          {
            txConfLen = (uint16)remainingTxConfLen;
          }
          /* Forward indication to UL */
          TcpIp_Tcp_TlsTxConfirmation(socketIdx, (uint16)txConfLen);
          /* Subtract the already confirmed data */
          remainingTxConfLen -= txConfLen;
        }
      }
    }
  }
  else
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
  }
} /* TcpIp_TlsCoreRl_TxConfirmation() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_ValidateAndProcessFrame
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_ValidateAndProcessFrame(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint32 totDataLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 rlHdr[TCPIP_TLS_RLHDRLEN]; /* Filled with the received RL-Header */

  /* ----- Implementation ----------------------------------------------- */
  if (TcpIp_TlsCoreRl_ValidateFrameHdr(TlsConIdx, totDataLen, &rlHdr[0]) == E_OK)
  {
    if (totDataLen >= TCPIP_TLS_RLHDRLEN)
    {
      /* #10 Check that the received RL length is valid. */
      if (TcpIp_TlsCoreRl_ValidateRlFragmentLength(TlsConIdx, &rlHdr[0]) == E_OK)
      {
        /* #20 If we receive an valid TLS RL header, validate the received RL frame and trigger the content specific processing (AD, HS, AL, CCS) */
        if (TcpIp_TlsCoreRl_ValidateFrameAndTriggerContentSpecificProcess(TlsConIdx, totDataLen, &rlHdr[0]) == E_OK)
        {
          retVal = E_OK;
        }
      }
    }
    else
    {
      /* No complete RL Hdr has been received yet. Wait for next RL frame */
      retVal = E_OK;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_ValidateFrameHdr
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_ValidateFrameHdr(
  TcpIp_TlsConnectionIterType              TlsConIdx,
  CONST(uint32, AUTOMATIC)                 TotDataLen,
  TCPIP_P2V(uint8)                         RlHdrPtr)
{
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  uint8 rlHdrLen;
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Validate the received Rl header and copy into Tls buffer */
  if (TotDataLen != 0u)
  {
    /* Check if a complete Rl header was received */
    if (TotDataLen >= TCPIP_TLS_RLHDRLEN)
    {
      rlHdrLen = TCPIP_TLS_RLHDRLEN;
      TcpIp_TlsCoreRxBufStruct_Copy2Buf(tlsBufferMgmtIdx, RlHdrPtr, rlHdrLen, 0);
    }
    else
    {
      /* There is something in the buffer, but smaller than the RL HDR. Check the first byte if it is a valid RL Frame */
      rlHdrLen = (uint8)TotDataLen;
      TcpIp_TlsCoreRxBufStruct_Copy2Buf(tlsBufferMgmtIdx, RlHdrPtr, rlHdrLen, 0);
    }

    /* Parse and validate the received Rl header */
    if (TcpIp_TlsCoreRl_ParseAndValidateRlHdr(TlsConIdx, RlHdrPtr, rlHdrLen) == E_OK)
    {
      retVal = E_OK;
    }
    else
    {
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_PROT_VERSION);
    }
  }

  return retVal;
} /* TcpIp_TlsCoreRl_ValidateFrameHdr() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_ValidateRlFragmentLength
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_ValidateRlFragmentLength(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(uint8) RlHdrPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* The maximum length of a plaintext RL fragment that can be received */
  TcpIp_SizeOfTlsBufferRxType activePlaintextMaxRxRlSize
    = TcpIp_GetActiveMaxRxRlSizeOfTlsConnectionDyn(TlsConIdx);

  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* Calculate maximum overall length which can be received. This contains the plaintext size plus the TLS overhead */
  uint32 maxRlFragmentLen = TcpIp_TlsCoreRl_CalcContentTypeLenCipherDependent(TlsConIdx,
    (uint32)activePlaintextMaxRxRlSize, TcpIp_GetActiveCipherRxOfTlsConnectionDyn(TlsConIdx));

  /* Get the received record layer length from the header */
  uint16 rlFragmentLen = IpBase_GetUint16(RlHdrPtr, TCPIP_TLS_RLLEN_OFFSET);

  /* #10 Check if the received record layer frame fits in the maximum fragment length */
  if (rlFragmentLen <= maxRlFragmentLen)
  {
    /* #20 Frame fits, return E_OK */
    retVal = E_OK;
  }
  else
  {
    /* #30 Frame does not fit - return E_NOT_OK and trigger TLS alert */
    retVal = E_NOT_OK;

    /* RFC8449 - 4. The "record_size_limit" Extension
     *   A TLS endpoint that receives a record larger than its advertised limit MUST
     *   generate a fatal "record_overflow" alert;
     */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_RECORD_OVERFLOW);
  }
  return retVal;
} /* TcpIp_TlsCoreRl_ValidateRlFragmentLength() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_ValidateFrameAndTriggerContentSpecificProcess
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_ValidateFrameAndTriggerContentSpecificProcess(
  TcpIp_TlsConnectionIterType              TlsConIdx,
  uint32                                   TotDataLen,
  TCPIP_P2C(uint8)                         RlHdrPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check that TLS connection is in the correct state */
  if (TcpIp_TlsCoreRl_CheckIfFrameIsReceivable(TlsConIdx, RlHdrPtr) == E_OK)
  {
    uint16 expectedRlLen = 0; /* Stores the length information peeked from RL-Header */

    /* #20 If so, check that we received the full RL frame */
    if (TcpIp_TlsCoreRl_VerifyFrameCompleteness(TotDataLen, RlHdrPtr, &expectedRlLen) == E_OK)
    {
      uint8 contentType = RlHdrPtr[TCPIP_TLS_RLCT_OFFSET];

      /* #30 If so, check if the current frame fits into the TLS Rx buffer */
      if (TcpIp_TlsCoreRl_RlFrameFitsInTlsRxBuffer(TlsConIdx, contentType, expectedRlLen) == TRUE)
      {
        /* #40 If so, validate the frame and trigger the content specific processing (AD, HS, AL, CCS) */
        if (TcpIp_TlsCoreRl_DecryptAndTriggerContentSpecificProcess(TlsConIdx,
              RlHdrPtr, expectedRlLen) == E_OK)
        {
          /* #50 Successfully validated the frame and triggered the content specific processing. */
          retVal = E_OK;
        }
        else
        {
          /* #60 Otherwise return E_NOT_OK. The caller handles the reception of a invalid RL frame */
          /* retVal is already E_NOT_OK */
        }
      }
      else
      {
        if (contentType == TCPIP_TLS_CT_AD)
        {
          /* Only TLS application data are stored until the upper layer frees the TLS RxBuffer via TcpIp_TcpReceived() */
          /* Valid case: Wait with decryption for next main function cycle */
          retVal = E_OK;
        }
        else
        {
          /* All other frames must fit into the buffer */
          /* Received frame fits not into the buffer - Set record layer alert description */
          TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
        }
      }
    }
    else
    {
      /* #70 Otherwise do nothing and wait for the next cycle */
      retVal = E_OK;
    }
  } /* else - retVal is E_NOT_OK, invoking function will set an alert */

  return retVal;
} /* TcpIp_TlsCoreRl_ValidateFrameAndTriggerContentSpecificProcess() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_VerifyFrameCompleteness
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_VerifyFrameCompleteness(
  uint32 TotDataLen,
  TCPIP_P2C(uint8) RlHdrPtr,
  TCPIP_P2V(uint16) RlHdrLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if we received the complete frame */
  *RlHdrLenPtr = IpBase_GetUint16(RlHdrPtr, TCPIP_TLS_RLLEN_OFFSET);

  if (TotDataLen >= (uint32)(TCPIP_TLS_RLHDRLEN + (uint32)(*RlHdrLenPtr)))
  {
    retVal = E_OK;
  }

  return retVal;
} /* TcpIp_TlsCoreRl_VerifyFrameCompleteness() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_CheckIfFrameIsReceivable
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_CheckIfFrameIsReceivable(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(uint8) RlHdrPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  TcpIp_TlsConnectionState currentConnectionState = TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Check if connection is in valid state to receive AD frame */
  if (RlHdrPtr[TCPIP_TLS_RLCT_OFFSET] == TCPIP_TLS_CT_AD)
  {
    switch (currentConnectionState)
    {
      /* If the connection is in state HS_ACTIVE we have to differentiate between TLS 1.2 and 1.3. */
      case TCPIP_TLS_STATE_CONNECTION_HS_ACTIVE:
      {
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
        if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
        {
          /* TLS 1.3 */
          /* The version is set to 1.3 after parsing the Server Hello message.
           * Therefore, encrypted messages are expected with the Record Layer
           * ContentType set to Application Data and the frame is receivable. */
          retVal = E_OK;
        }
        else
# endif
        {
          /* TLS 1.2 or TLS version not set yet */
          /* We should not receive any TLS AD before the handshake is done.
           * Set the TLS Alert to 'unexpected_message' */
          TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
          /* Frame is not receivable */
          retVal = E_NOT_OK;

        }
        break;
      }

      /* If the connection is in state ESTABLISHED or FINALIZING TLS handshake it is OK to receive TLS AD */
      case TCPIP_TLS_STATE_CONNECTION_ESTABLISHED:
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)                                                                             /* COV_TCPIP_ASRTLSSERVER_ALWAYS_ON */
      case TCPIP_TLS_STATE_CONNECTION_SERVER_HS_FINALIZING:
# endif
      {
        /* Frame is receivable */
        retVal = E_OK;
        break;
      }

      /* If connection is in other states, nothing to do */
      default:
      {
        /* do nothing */
        break;
      }
    }
  }
  else if (RlHdrPtr[TCPIP_TLS_RLCT_OFFSET] == TCPIP_TLS_CT_CCS)
  {
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
    /* #20 Check if the received CCS is the first CCS we received in TLS 1.2 */
    if (   (TcpIp_IsCcsReceivedOfTlsConnectionDyn(TlsConIdx) == TRUE)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
        && (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_12)                                 /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
#  endif
       )
    {
      /* In this case a duplicated CCS message was received.
       * Since we do not support renegotiation this is an error case.
       * Therefore trigger an unexpected message alert. */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
      retVal = E_NOT_OK;
    }
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    if (   (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_ESTABLISHED)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
        && (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)                                 /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
#  endif
       )
    {
      /* This function returns E_OK for CCS during the TLS 1.3 handshake.
       * That a CCS is received at a valid time is dependent on the last received handshake type and can't be checked
       * here easily. Instead it is checked in TcpIp_TlsCoreMainFunction_RxCcs().
       * But CCS messages after the handshake are always invalid according to RFC8446 chapter 5:
       * If an implementation receives a change_cipher_spec record after peer's Finished message,
       * it MUST be treated as an unexpected record type. Therefore trigger an unexpected message alert in this case. */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
      retVal = E_NOT_OK;
    }
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
  }
  else
  {
    /* We know that the RL header is valid, so no additional checks needed here.
     * All other content types can pass and retVal is set to E_OK */
  }

  return retVal;
} /* TcpIp_TlsCoreRl_CheckIfFrameIsReceivable() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_DecryptAndTriggerContentSpecificProcess
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_DecryptAndTriggerContentSpecificProcess(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(uint8) RlHdrPtr,
  CONST(uint16, AUTOMATIC) RlFrameLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 contentType                            = RlHdrPtr[TCPIP_TLS_RLCT_OFFSET];
  Std_ReturnType retVal                        = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Decrypt and authenticate the received Rl frame */
  if (TcpIp_TlsCoreRl_DecryptAndAuthenticate(TlsConIdx, RlFrameLen, contentType) == E_OK)
  {
    /* #20 Handle the received frame and trigger the content type specific processing and Ul RxIndication if necessary */
    if (TcpIp_TlsCoreRl_HandleFrameAndTriggerContentSpecificProcess(TlsConIdx, ((uint32)RlFrameLen + TCPIP_TLS_RLHDRLEN),
      contentType) == E_OK)
    {
      /* Frame successfully received - return E_OK */
      retVal = E_OK;
    }
  }

  return retVal;
} /* TcpIp_TlsCoreRl_DecryptAndTriggerContentSpecificProcess() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_HandleFrameAndTriggerContentSpecificProcess
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_HandleFrameAndTriggerContentSpecificProcess(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint32, AUTOMATIC) ReceivedFrameLength,
  CONST(uint8, AUTOMATIC) ContentType)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  TcpIp_SocketDynComIdxOfTlsConnectionDynType socketIdx
    = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_RlRxCopiedLenOfTlsBufferMgmtDynType plaintextLen
    = TcpIp_GetRlRxCopiedLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  if ((socketIdx < TcpIp_GetSizeOfSocketDyn()) && (TCPIP_SOCKET_IDX_IS_TCP(socketIdx) == TRUE))
  {
    retVal = E_OK;

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
    {
      if (ContentType == TCPIP_TLS_CT_AD)
      {
        /* If Tls 1.3 is active and a message with Record Layer ContentType Application Data is received,
         * various post decryption actions are necessary (e.g. reading the inner plaintext content type).
         * This is the only valid path where the last ContentType is not set directly.
         * It will be set in TcpIp_Tls13CoreRl_ProcessAdFrameAfterDecryption() to the inner plaintext ContentType. */
        /* #10 Process post decryption actions for 1.3 application data frame. */
        if (TcpIp_Tls13CoreRl_ProcessAdFrameAfterDecryption(TlsConIdx, &plaintextLen) != E_OK)
        {
          TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
          retVal = E_NOT_OK;
        }
      }
      else
      {
        TcpIp_SetLastReceivedContentTypeOfTlsConnectionDyn(TlsConIdx, ContentType);
      }
    }
    else
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
    {
      TcpIp_SetLastReceivedContentTypeOfTlsConnectionDyn(TlsConIdx, ContentType);
    }
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    if (retVal == E_OK)
# endif
    {
      if (TcpIp_GetLastReceivedContentTypeOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CT_HS)
      {
        /* Scan of handshake types in current record layer to accomplish the following:
         *  - Scan for messages after which the decryption must be blocked -> In TLS 1.3 messages preceding a key change,
         *                                                                    in TLS 1.2 the ServerFinished
         *  - Save type of last handshake message in this frame -> used for validating reception of CCS
         *  - Handshake messages after a TLS handshake was completed are directly parsed
         *    and removed from the AdHs buffer
         *  - HelloRequest at any time in TLS 1.2 */
        TcpIp_TlsCoreRl_ScanForHsTypesAndTriggerHsMsgProcess(TlsConIdx, plaintextLen);
      }

      /* #20 Trigger content specific processing since a complete RL frame was received. */
      /* The content specific Rx main functions are triggered through setting the Rx Indication flag to TRUE
       * and setting the LastReceivedContentType to the corresponding content type. */
      TcpIp_TlsCoreRl_RxIndication(TlsConIdx);

      /* #30 Set various parameters since complete Rl frame was received. */
      TcpIp_TlsCoreRl_SetParametersForReceivedFrame(TlsConIdx, ReceivedFrameLength, plaintextLen);
    }
  }
  else
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
    /* retVal already set */
  }

  /* Reset Rl frame start index */
  TcpIp_SetTlsBufferRxRlFrameStartIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_NO_TLSBUFFERRXRLFRAMESTARTIDXOFTLSBUFFERMGMTDYN);

  return retVal;
} /* TcpIp_TlsCoreRl_HandleFrameAndTriggerContentSpecificProcess() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_ScanForHsTypesAndTriggerHsMsgProcess
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
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_ScanForHsTypesAndTriggerHsMsgProcess(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint32, AUTOMATIC)    PlaintextLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType localRetVal = E_OK;

  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  uint32 rlFrameStartTlsBufferRxIdx = (uint32)TcpIp_GetTlsBufferRxRlFrameStartIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  uint32 rxAdHsWriteIdx = (uint32)TcpIp_GetTlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  uint32 rxAdHsReadMaxIdx = (uint32)TcpIp_TlsCoreRl_GetReadMaxIdxForContentType(TlsConIdx, TCPIP_TLS_CT_AD);
  uint32 rxAdHsStartIdx = (uint32)TcpIp_GetTlsBufferRxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  uint8  hsType = TCPIP_TLS_HSTYPE_INVALID;
  uint32 hsLen = 0u;
  uint32 linearLength = 0u;
  uint32 endOfBufferLength = 0u;
  TcpIp_ConstSegmentType linearRxAdHsBufferConstSeg = { 0 };
  TcpIp_ConstSegmentType endOfRxAdHsBufferConstSeg = { 0 };

  /* ----- Implementation ----------------------------------------------- */
  if (   (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_HANDSHAKE_FINALIZING)                 /* PRQA S 3415 1 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
      || (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_HANDSHAKE_DONE))
  {
    /* #10 Add PlaintextLen to variable to track how much buffer is occupied by HS messages which must be removed after parsing. */
    /* Hs messages only need to be removed from the buffer if the connection is already established. */
    TcpIp_AddRemainingHsPlaintextLenInRxBufOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, PlaintextLen);
  }

  /* #20 Set currIdx to the start of the received plaintext data. */
  uint32 currIdx = rlFrameStartTlsBufferRxIdx;
  if (TcpIp_GetReceivedBytesOfLastHsMsgPartiallyReceivedOfTlsConnectionDyn(TlsConIdx) > 0u)
  {
    /* #30 Decrement currIdx to end of last complete HS message if last HS message was not received completely */
    /* ReceivedBytesOfLastHsMsgPartiallyReceived is only set if a complete HS header was received.
     * Therefore we can add the bytes for the HS header here. */
    (void)TcpIp_GetDecrementedRingBufferIndex(currIdx,
      (TcpIp_GetReceivedBytesOfLastHsMsgPartiallyReceivedOfTlsConnectionDyn(TlsConIdx) + TCPIP_TLS_HSHDRLEN),
      rxAdHsStartIdx, rxAdHsReadMaxIdx, &currIdx);
    /* Complete handshake header was received, reset the amount of received HS header bytes from last frame. */
    TcpIp_SetReceivedBytesOfLastHsHeaderPartiallyReceivedOfTlsConnectionDyn(TlsConIdx, 0);
  }

  /* #40 Check if last HS message is now received completely */
  /* Technically it is checked if we received the remaining data of a HS message with a complete HS header.
   * If the last RL frame did only contain part of a HS header RemainingBytesOfLastHsMsgPartiallyReceived is 0
   * and we traverse the else-path even if the message is not completely received now. */
  if (TcpIp_GetRemainingBytesOfLastHsMsgPartiallyReceivedOfTlsConnectionDyn(TlsConIdx) > PlaintextLen)
  {
    /* #50 If not, wait for the next and reduce amount of bytes which are expected in the next RL frame. */
    /* The last HS message is still not received completely in this frame */
    TcpIp_SubRemainingBytesOfLastHsMsgPartiallyReceivedOfTlsConnectionDyn(TlsConIdx, PlaintextLen);
    TcpIp_AddReceivedBytesOfLastHsMsgPartiallyReceivedOfTlsConnectionDyn(TlsConIdx, PlaintextLen);
  }
  else
  {
    /* Last HS-Message received completely or the last message only contained part of the HS header.
     * Set currIdx to HS header start in case the last record layer included the HS header only partially.
     * If TcpIp_GetReceivedBytesOfLastHsHeaderPartiallyReceivedOfTlsConnectionDyn(TlsConIdx) == 0,
     * currIdx is not changed. */
    (void)TcpIp_GetDecrementedRingBufferIndex(currIdx,
      TcpIp_GetReceivedBytesOfLastHsHeaderPartiallyReceivedOfTlsConnectionDyn(TlsConIdx),
      rxAdHsStartIdx, rxAdHsReadMaxIdx, &currIdx);

    /* Make two constant segments out of the record layer to consider wraparounds. */
    (void)TcpIp_GetSplitLengthInRingBuffer(rxAdHsWriteIdx, currIdx, rxAdHsStartIdx, rxAdHsReadMaxIdx,
      &linearLength, &endOfBufferLength);
    /* Initialize a const segment for reading the data at the end of the buffer.
       This segment might have zero length
       if the whole data is located at the start of the buffer or in the middle of it.
       If the length is not zero, the data starts in this segment, therefore it must be the first
       segment when invoking e.g. TcpIp_Tls13ClientMsg_ExtractNewSessionTicketInformation(). */
    TcpIp_ConstSegmentInit(&endOfRxAdHsBufferConstSeg,
      TcpIp_GetAddrTlsBufferRx((TcpIp_TlsBufferRxIterType)currIdx), endOfBufferLength);
    /* Initialize a const segment for reading the data at the start and middle of the buffer.
       This segment might have zero length if the whole data is located at the end of the buffer.
       No underflow possible since this data is linear, see TcpIp_GetSplitLengthInRingBuffer(). */
    TcpIp_ConstSegmentInit(&linearRxAdHsBufferConstSeg,
      TcpIp_GetAddrTlsBufferRx((TcpIp_TlsBufferRxIterType)(rxAdHsWriteIdx - linearLength)), linearLength);

    /* Reset flags before processing frame. */
    boolean isLastHsMsgDataInRlFragmented = FALSE;

    /* #60 If so, loop through all HS messages in current RL frame until a complete HS-Header does not fit in the RL frame anymore. */
    while (   (TcpIp_TlsCore_ExtractHsHeaderInformationFromMultiConstSegment(
                 &endOfRxAdHsBufferConstSeg, &linearRxAdHsBufferConstSeg, &hsType, &hsLen) == E_OK)
              /* If parsing failed stop the loop. */
           && (localRetVal == E_OK))
    {
      /* #70 Save type of HS message - used for CCS handling */
      TcpIp_SetLastHsMsgTypeOfLastReceivedHsRlFrameOfTlsConnectionDyn(TlsConIdx, hsType);

      /* Check if only a handshake header (with non zero length) was received but without any data. */
      if (   (((uint64)endOfRxAdHsBufferConstSeg.AvailLen + (uint64)linearRxAdHsBufferConstSeg.AvailLen) == 0u)
          && (hsLen != 0u))
      {
        /* In this case ReceivedBytesOfLastHsHeaderPartiallyReceived needs to be set
         * to the length of the handshake header, since otherwise when the data is received
         * there is no indication that its header was already received earlier.
         * TcpIp_GetSplitLengthInMultiConstSegment() will always return E_NOT_OK since there is no more data left.
         * Therefore ReceivedBytesOfLastHsMsgPartiallyReceived will be set to zero
         * and RemainingBytesOfLastHsMsgPartiallyReceived will be set to the read handshake length. */
        TcpIp_SetReceivedBytesOfLastHsHeaderPartiallyReceivedOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_HSHDRLEN);
      }
      else
      {
        /* Otherwise reset the amount of received HS header bytes from last frame.
         * A complete handshake header was received. */
        TcpIp_SetReceivedBytesOfLastHsHeaderPartiallyReceivedOfTlsConnectionDyn(TlsConIdx, 0);
      }

      /* #80 Check if complete message is received. */
      uint32 hsLenInEndOfBufSeg = 0;
      uint32 hsLenInLinBufSeg = 0;
      if (TcpIp_GetSplitLengthInMultiConstSegment(&endOfRxAdHsBufferConstSeg, &linearRxAdHsBufferConstSeg,
            hsLen, &hsLenInEndOfBufSeg, &hsLenInLinBufSeg) == E_OK)
      {
        /* #90 Complete message received. Process the message. */
        localRetVal = TcpIp_TlsCoreRl_ProcessCompleteHsMessage(TlsConIdx, hsType, hsLen, &endOfRxAdHsBufferConstSeg,
          &linearRxAdHsBufferConstSeg, &currIdx);
      }
      else
      {
        /* #100 Message received only partially. Set the amount of bytes left of this HS message and the amount already received. */
        TcpIp_SetReceivedBytesOfLastHsMsgPartiallyReceivedOfTlsConnectionDyn(
          TlsConIdx, endOfRxAdHsBufferConstSeg.AvailLen + linearRxAdHsBufferConstSeg.AvailLen);
        TcpIp_SetRemainingBytesOfLastHsMsgPartiallyReceivedOfTlsConnectionDyn(TlsConIdx,
          hsLen - TcpIp_GetReceivedBytesOfLastHsMsgPartiallyReceivedOfTlsConnectionDyn(TlsConIdx));
        isLastHsMsgDataInRlFragmented = TRUE;
        /* #110 Must be the last message in the RL. Therefore break out of loop and wait for remaining part of message in next RL. */
        break;
      }
    }
    /* #120 Check if there is part of a HS header in the received RL frame. */
    /* This is the case when the last HS message was not received only partially,
     * but its end did not align with the RL end. This means there must be some bytes left,
     * but not enough for a complete HS header since then the last HS message would be received partially. */
    if (   (isLastHsMsgDataInRlFragmented == FALSE)
        && (((uint64)endOfRxAdHsBufferConstSeg.AvailLen + (uint64)linearRxAdHsBufferConstSeg.AvailLen) > 0u)
        && (localRetVal == E_OK))
    {
      /* #130 If so, set amount of received HS header bytes. */
      /* TcpIp_TlsCore_ExtractHsHeaderInformationFromMultiConstSegment() returns only E_NOT_OK
       * if the available length of both segments is smaller than the handshake header length.
       * Therefore the cast to uint8 can be done. */
      TCPIP_ASSERT(   ((uint64)endOfRxAdHsBufferConstSeg.AvailLen + (uint64)linearRxAdHsBufferConstSeg.AvailLen)
                      < TCPIP_TLS_HSHDRLEN);
      TcpIp_SetReceivedBytesOfLastHsHeaderPartiallyReceivedOfTlsConnectionDyn(
        TlsConIdx, ((uint8)endOfRxAdHsBufferConstSeg.AvailLen + (uint8)linearRxAdHsBufferConstSeg.AvailLen));
    }
    else
    {
      /* Do nothing. */
    }
  }
} /* TcpIp_TlsCoreRl_ScanForHsTypesAndTriggerHsMsgProcess() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_ProcessCompleteHsMessage
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_ProcessCompleteHsMessage(
  TcpIp_TlsConnectionIterType                 TlsConIdx,
  uint8                                       HsType,
  uint32                                      HsLen,
  TcpIp_ConstSegmentPtrType                   SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                   SourceSegment2Ptr,
  TCPIP_P2V(uint32)                           CurrAdHsBufferIdxPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  uint32 rxAdHsReadMaxIdx = (uint32)TcpIp_TlsCoreRl_GetReadMaxIdxForContentType(TlsConIdx, TCPIP_TLS_CT_AD);
  uint32 rxAdHsStartIdx = (uint32)TcpIp_GetTlsBufferRxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Process the handshake message. */
  Std_ReturnType retVal = TcpIp_TlsCoreRl_ProcessHsFrame(TlsConIdx, HsType, HsLen, SourceSegment1Ptr,
    SourceSegment2Ptr);

  /* Reset the amount of remaining HS message data bytes left of this HS message */
  TcpIp_SetRemainingBytesOfLastHsMsgPartiallyReceivedOfTlsConnectionDyn(TlsConIdx, 0);
  TcpIp_SetReceivedBytesOfLastHsMsgPartiallyReceivedOfTlsConnectionDyn(TlsConIdx, 0);

  if (retVal == E_OK)
  {
    /* #20 Check if current HS message ends at the RL frame end. */
    if (((uint64)SourceSegment1Ptr->AvailLen + (uint64)SourceSegment2Ptr->AvailLen) == 0u)
    {
      /* #30 If so, remove the HS data from the RX buffer. */
      /* During the handshake and for TLS 1.2
       * RemainingHsPlaintextLenInRxBuf is zero and nothing will be removed. */
      retVal = TcpIp_TlsCoreRl_RemoveDataFromAdHsRxBuffer(
        TlsConIdx, (uint32)TcpIp_GetRemainingHsPlaintextLenInRxBufOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));
      /* Reset variable which tracks the buffer occupation. */
      TcpIp_SetRemainingHsPlaintextLenInRxBufOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, 0);
      /* The while loop in TcpIp_TlsCoreRl_ScanForHsTypesAndTriggerHsMsgProcess()
       * will not be continued since there is no more data in the segments. */
    }
    else
    {
      /* #40 There is more data available in the RL. Step to next HS message in the current RL frame. */
      (void)TcpIp_GetIncrementedRingBufferIndex(
        *CurrAdHsBufferIdxPtr, TCPIP_TLS_HSHDRLEN + HsLen, rxAdHsStartIdx, rxAdHsReadMaxIdx, CurrAdHsBufferIdxPtr);

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      /* Messages preceding a key change shall always be aligned with a RL boundary in TLS 1.3.
       * Check if this is the case. */
      retVal = TcpIp_Tls13CoreRl_HandleHsMsgNotAlignedWithRlBoundary(TlsConIdx);
# endif
    }
  }
  return retVal;
} /* TcpIp_TlsCoreRl_ProcessCompleteHsMessage() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_ProcessHsFrame
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_ProcessHsFrame(
  TcpIp_TlsConnectionIterType                 TlsConIdx,
  uint8                                       HsType,
  uint32                                      HsLen,
  TcpIp_ConstSegmentPtrType                   SourceSegment1Ptr,
  TcpIp_ConstSegmentPtrType                   SourceSegment2Ptr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  boolean hsMsgAlreadySkipped = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the TLS version of the connection and process the handshake frame differently dependent on it. */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  if (   (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)                                   /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
      || (   (TcpIp_IsTlsSupportVersion13OfTlsConnection(TlsConIdx) == TRUE)
          && (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_NOTSET)))
#  endif
  {
    retVal = TcpIp_Tls13CoreRl_ProcessHsFrame(TlsConIdx, HsType, HsLen,
      SourceSegment1Ptr, SourceSegment2Ptr, &hsMsgAlreadySkipped);
  }
# endif
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLSVERSION_13)
#  endif
  {
    retVal = TcpIp_Tls12CoreRl_ProcessHsFrame(TlsConIdx, HsType, HsLen);
  }
# endif

  /* Only skip data in segments if it has not already been "consumed" in the processing function */
  if (hsMsgAlreadySkipped == FALSE)                                                                                     /* PRQA S 2991, 2995 */ /* MD_TCPIP_Rule14.3_2741_2742_2991_2992_2995_2996 */
  {
    if (retVal == E_OK)
    {
      /* #20 Skip the handshake message data since it's handled later. */
      /* Handshake messages for TLS 1.2 are handled later in the handshake context.
       * Only ClientHelloAfterHandshake and HelloRequest are processed in this context.
       * Skip the Hs message data since we need to check
       * if we received more handshake data in the same RL / const segments after that data.
       * In TcpIp_TlsCoreRl_ScanForHsTypesAndTriggerHsMsgProcess() it was already checked that the const segments
       * contain data with at least the length of HsLen. So this check should never fail. */
      retVal = TcpIp_SkipDataInMultiConstSegment(SourceSegment1Ptr, SourceSegment2Ptr, HsLen);
    }
    else
    {
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
    }
  }
  return retVal;
} /* TcpIp_TlsCoreRl_ProcessHsFrame() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_BlockDecryption
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_BlockDecryption(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Block decryption till keys are calculated and reset other flags */
  TcpIp_SetBlockDecryptOperationsUntilKeysAreCalculatedOfTlsConnectionDyn(TlsConIdx, TRUE);
  TcpIp_SetMsgPrecedingKeyChangePartiallyReceivedOfTlsConnectionDyn(TlsConIdx, FALSE);
} /* TcpIp_TlsCoreRl_BlockDecryption() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_RemoveDataFromAdHsRxBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_RemoveDataFromAdHsRxBuffer(
  TcpIp_TlsConnectionIterType                 TlsConIdx,
  uint32                                      PlaintextLen)
{
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  uint32 rxAdHsWriteIdx = (uint32) TcpIp_GetTlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  uint32 rxAdHsReadMaxIdx = (uint32) TcpIp_TlsCoreRl_GetReadMaxIdxForContentType(TlsConIdx, TCPIP_TLS_CT_AD);

  uint32 rxAdHsStartIdx = (uint32) TcpIp_GetTlsBufferRxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  uint32 newRxAdHsWriteIdx = 0u;

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Remove data from the Rx AdHs buffer by resetting the write index and therefore allowing the data to be overwritten. */
  if (TcpIp_GetDecrementedRingBufferIndex(rxAdHsWriteIdx, PlaintextLen, rxAdHsStartIdx, rxAdHsReadMaxIdx,
        &newRxAdHsWriteIdx) == E_OK)
  {
    retVal = E_OK;
    TcpIp_SetTlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
      (TcpIp_TlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDynType) newRxAdHsWriteIdx);
  }
  else
  {
    /* retVal already E_NOT_OK */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsCore_ExtractHsHeaderInformationFromMultiConstSegment
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCore_ExtractHsHeaderInformationFromMultiConstSegment(
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
} /* TcpIp_TlsCore_ExtractHsHeaderInformationFromMultiConstSegment */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_SetParametersForReceivedFrame
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_SetParametersForReceivedFrame(
  TcpIp_TlsConnectionIterType                                 TlsConIdx,
  CONST(uint32, AUTOMATIC)                                    ReceivedFrameLength,
  CONST(TcpIp_RlRxCopiedLenOfTlsBufferMgmtDynType, AUTOMATIC) PlaintextLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SocketDynComIdxOfTlsConnectionDynType socketIdx
    = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Release the received data from the RX data structures. */
  /* Release the TCP buffers of the processed Rl frame */
  TcpIp_TlsCoreRxBufStruct_ReleaseSegment(tlsBufferMgmtIdx, ReceivedFrameLength);
  /* Notify TCP that TLS has consumed the current Rl frame */
  TcpIp_Tcp_TlsReceived(socketIdx, ReceivedFrameLength);

  /* #20 Update RX information indices. */
  /* Increment the RX sequence counter */
  TcpIp_IncRlRxSequenceCounterOfTlsConnectionDyn(TlsConIdx);

  if (TcpIp_GetLastReceivedContentTypeOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CT_AD)
  {
    TcpIp_AddAdUlRxIndLevelOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, PlaintextLen);
    TcpIp_AddAdRxFillLevelOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, PlaintextLen);
  }

  /* Reset the copied length since RxIndication has been triggered */
  TcpIp_SetRlRxCopiedLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, 0u);

} /* TcpIp_TlsCoreRl_SetParametersForReceivedFrame() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_ParseAndValidateRlHdr
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_TcpIp_TlsStatemachine_STMIF_6080 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_ParseAndValidateRlHdr(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(uint8) RlHdrPtr,
  CONST(uint8, AUTOMATIC) RlHdrLen)
{

  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsUserErrorType rLHeaderUserError;
  uint8 contentType = RlHdrPtr[TCPIP_TLS_RLCT_OFFSET];
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */

  /* Prepare user error */
  rLHeaderUserError.FunctionId = TCPIP_TLS_FCTID_CORE_RL_CHECKHDR;
  rLHeaderUserError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);
  /* ErrorId will be set to the possible occurring errors */


  /* #10 Check the TLS content type of the received RL frame. */
  /* If the active TLS version has already been set to TLS 1.3, the ServerHello message was received and parsed.
   * Every following frame in TLS 1.3 MUST either be encrypted with the record layer content type application data
   * or is a CCS message. */
  if (    (contentType == TCPIP_TLS_CT_AD)
       || (contentType == TCPIP_TLS_CT_CCS)
       || (   (   (contentType == TCPIP_TLS_CT_HS)
               || (contentType == TCPIP_TLS_CT_AL))
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
           && (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLSVERSION_13)                              /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
# endif
    ))
  {
    /* #20 Check if we receive the 2 bytes version number */
    if (RlHdrLen > TCPIP_TLS_RLVERSMINOR_OFFSET)
    {
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      if (   (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_12)                               /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
          || (!TcpIp_TlsClient_WorkingSetIncludesTlsVersion(TlsConIdx, TCPIP_TLSVERSION_13))
#  endif
        )
# endif
      {
        /* Active TLS version is either TLS 1.2 or the active TLS version is not set yet,
         * but the possible ciphersuites do not include any 1.3 ciphers. */
        /* #30 Check the TLS major version number (must match exactly with 0x03) */
        if (RlHdrPtr[TCPIP_TLS_RLVERSMAJOR_OFFSET] == TCPIP_TLS_RL_VERSMAJOR)
        {
          /* #40 Check the TLS minor version number depending on the TLS mode (Server/ Client) */
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
          if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
#  endif
          {
            /* Mode == TCPIP_TLS_SERVER */
            /* Server accept any minor version number only in the ClientHello message */
            if (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_WAIT_FOR_CLIENT_HELLO)
            {
              retVal = E_OK;
            }
            else
            {
              /* Every other message than ClientHello must contain exactly the minor version number of 0x03.
               * See RFC 8446 chapter 5.1. Record Layer (TLS 1.3) and RFC 5246 6.2.1. Fragmentation (TLS 1.2) */
              if (RlHdrPtr[TCPIP_TLS_RLVERSMINOR_OFFSET] == TCPIP_TLS_RL_VERSMINOR)
              {
                retVal = E_OK;
              }
              else
              {
                /* TLS Server invalid minor version number */
                rLHeaderUserError.UserErrorId = TCPIP_TLS_ERRORID_RL_INCORRECT_MINORVERSNR;
              }
            }
          }
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
          else
#  endif
# endif
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
          {
            /* Mode == TCPIP_TLS_CLIENT */
            /* Client TLS minor version number must match exactly with 0x03 */
            if (RlHdrPtr[TCPIP_TLS_RLVERSMINOR_OFFSET] == TCPIP_TLS_RL_VERSMINOR)
            {
              retVal = E_OK;
            }
            else
            {
              /* TLS Client invalid minor version number */
              rLHeaderUserError.UserErrorId = TCPIP_TLS_ERRORID_RL_INCORRECT_MINORVERSNR;
            }
          }
# endif

        }
        else
        {
          /* Received wrong major version, set errorId */
          rLHeaderUserError.UserErrorId = TCPIP_TLS_ERRORID_RL_INCORRECT_MAJORVERSNR;
        }
      }
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      else
      {
        /* Active TLS version is either TLS 1.3 or it is not set yet
         * and the possible ciphersuites make a TLS 1.3 handshake feasible. */
        /* According to RFC8446 section 4.2.1, clients MUST ignore the legacy_record_version value of the TLSPlaintext
         * (so the ServerHello message).
         * For the TLSCiphertext in the appendix D. of RFC8446 it is stated that the legacy_record_version MAY be
         * ignored or MAY be validated to match the fixed constant value.
         * For this implementation it was decided that the value will be ignored. */
        retVal = E_OK;
      }
# endif
    }
    else
    {
      /* No full record layer header received */
      retVal = E_OK;
    }
  }
  else
  {
    /* Received wrong Content Type, set errorId */
    rLHeaderUserError.UserErrorId = TCPIP_TLS_ERRORID_RL_INCORRECT_CT;

    /* Set Alert to unexpected_message, see RFC5246 chapter 6 and RFC8446 chapter 5:
     * "If a TLS implementation receives an unexpected record type, it MUST send an unexpected_message alert." */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNEXP_MSG);
  }

  if (retVal != E_OK)
  {
    TcpIp_TlsCoreError_ReportUserError(rLHeaderUserError);
  }

  return retVal;
} /* TcpIp_TlsCoreRl_ParseAndValidateRlHdr() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_DecryptAndAuthenticate
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6080, 6050, 6030 1 */ /* MD_TcpIp_TlsRuntimecheck_STMIF_6080, MD_TcpIp_STCAL_CslAccess, MD_TcpIp_TlsStreaming_STCYC_6030 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_DecryptAndAuthenticate(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint16, AUTOMATIC) RlFrameLen,
  CONST(uint8, AUTOMATIC) ContentType)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType                 retVal                 = E_NOT_OK;
  TcpIp_SizeOfTlsBufferMgmtType  tlsBufferMgmtIdx       = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  /* Variable to store the length of the Rl frame segment */
  uint16                         rxRlFrameSegLen        = RlFrameLen;
  /* Offset of the RL frame segment */
  uint16                         rxRlFrameSegOffset     = TCPIP_TLS_RLHDRLEN;
  /* Rx buffer segment index */
  TcpIp_SizeOfRxBufStructSegType rxBufStructSegIdx      = 0u;
  /* Flag to indicate if a complete Rl frame is available */
  boolean                        completeRlFrameFlag    = FALSE;
  /* Local variables to store TCP Rx buffer segment information */
  TCPIP_P2V(uint8)               bufSegPtr;
  /* Bytes to process from the current TCP Rx buffer segment */
  uint16                         bytesToCopy;
  uint32                         segOffset;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set start index of current record layer frame */
  TcpIp_TlsCoreRl_SetRlFrameStartIdx(TlsConIdx, ContentType);

  if (rxRlFrameSegLen != 0u)
  {
    /* #20 Decrypt and authenticate the current frame */
    while (rxRlFrameSegLen > 0u)
    {
      /* Set offset to the start of the TLS payload */
      segOffset = rxRlFrameSegOffset;

      /* Get index of TcpIp segment where current frame is available, considering offset */
      if (TcpIp_TlsCoreRxBufStruct_GetBufSegIdx(tlsBufferMgmtIdx, &segOffset, &rxBufStructSegIdx) == E_OK)
      {

        /* Extract the TCP segment */
        bufSegPtr = TcpIp_GetDataPtrOfRxBufStructSeg(rxBufStructSegIdx);
        bytesToCopy = (uint16)(TcpIp_GetLenOfRxBufStructSeg(rxBufStructSegIdx) - segOffset);

        /* Check if a complete TLS Rl frame is present in the current TCP segment */
        if (rxRlFrameSegLen < bytesToCopy)
        {
          /* Only forward the complete Rl frame */
          bytesToCopy = rxRlFrameSegLen;
        }

        /* Check if a whole Rl frame has been extracted */
        if (rxRlFrameSegLen == bytesToCopy)
        {
          /* Complete TLS Rl frame extracted, decryption and authentication can be completed in this call */
          completeRlFrameFlag = TRUE;
        }
        if(bufSegPtr != NULL_PTR)
        {
          if (TcpIp_TlsCoreRl_DecryptAndAuthenticateCheckFrame(TlsConIdx, ContentType, &bufSegPtr[segOffset], bytesToCopy,
                completeRlFrameFlag) == E_OK)
          {
            rxRlFrameSegLen -= bytesToCopy;
            rxRlFrameSegOffset += bytesToCopy;
            retVal = E_OK;
          }
          else
          {
            rxRlFrameSegLen = 0;  /* Set to 0 as exit the while-loop. */
            retVal = E_NOT_OK;
          }
        }
        else
        {
          TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
        }
      }
      else
      {
        rxRlFrameSegLen = 0;  /* Set to 0 as exit the while-loop. */
        retVal = E_NOT_OK;
      }
    } /* while (rxRlFrameSegLen > 0u) */
  }
  else
  {
    /* Received zero length frame - Set record layer alert description */
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
  }

  if (retVal != E_OK)
  {
    /* Reset Rl frame start index if something went wrong.
     * Otherwise it is reset in TcpIp_TlsCoreRl_HandleFrameAndTriggerContentSpecificProcess(). */
    TcpIp_SetTlsBufferRxRlFrameStartIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_NO_TLSBUFFERRXRLFRAMESTARTIDXOFTLSBUFFERMGMTDYN);
  }

  return retVal;
} /* TcpIp_TlsCoreRl_DecryptAndAuthenticate() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_SetRlFrameStartIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_SetRlFrameStartIdx(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC) ContentType)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType  tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set start index of current record layer frame */
  if ((ContentType == TCPIP_TLS_CT_HS) || (ContentType == TCPIP_TLS_CT_AD))
  {
    TcpIp_SetTlsBufferRxRlFrameStartIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
                                                 TcpIp_GetTlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));
  }
  else if (ContentType == TCPIP_TLS_CT_AL)
  {
    TcpIp_SetTlsBufferRxRlFrameStartIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
                                                 TcpIp_GetTlsBufferRxAlStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx));
  }
  else if (ContentType ==  TCPIP_TLS_CT_CCS)
  {
    TcpIp_SetTlsBufferRxRlFrameStartIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
      TcpIp_GetTlsBufferRxCcsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx));
  }
  else
  {
    /* This could not happen - left blank intentionally */
  }

} /* TcpIp_TlsCoreRl_SetRlFrameStartIdx() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_DecryptAndAuthenticateCheckFrame
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
/* PRQA S 6060 1 */ /* MD_TcpIp_TlsPointerAndLength_STPAR_6060 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_DecryptAndAuthenticateCheckFrame(
  TcpIp_TlsConnectionIterType              TlsConIdx,
  CONST(uint8, AUTOMATIC)                  ContentType,
  TCPIP_P2V(uint8)                         DataPtr,
  uint16                                   DataLen,
  boolean                                  CompleteRlFrameFlag)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if complete TLS record layer frame is received */
  if (CompleteRlFrameFlag == FALSE)
  {
    TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
    /* #20 Only partial TLS record layer frame available, store the buffer information for next call */
    TcpIp_GetAddrRxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataPtr = DataPtr;
    TcpIp_GetAddrRxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataLen = DataLen;
    /* retVal already E_OK */
  }
  else
  {
    /* #30 Complete frame received. */
    /* Decrypt the TLS frame in the provided TCP buffer directly into the TLS buffer */
    /* #40 Forward to specific decryption method */
    retVal = TcpIp_TlsCoreRl_DecryptAndAuthenticateFrameViaStreamingMode(TlsConIdx, ContentType, DataPtr, DataLen);

    if (retVal == E_OK)
    {
      /* #50 If a complete TLS frame has been decrypted, trigger further processing of received message */
      retVal = TcpIp_TlsCoreRl_RxCipherCheckPlaintextRlSizeLimit(TlsConIdx);
    }
    else
    {
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
    }
  }

  return retVal;
} /* TcpIp_TlsCoreRl_DecryptAndAuthenticateCheckFrame() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_DecryptAndAuthenticateFrameViaStreamingMode
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_DecryptAndAuthenticateFrameViaStreamingMode(
  TcpIp_TlsConnectionIterType              TlsConIdx,
  CONST(uint8, AUTOMATIC)                  ContentType,
  TCPIP_P2C(uint8)                         DataPtr,
  uint16                                   DataLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  TcpIp_TlsCipherStreamingModeDataType activeStreamingMode =
    TcpIp_TlsCoreUtil_ReturnCipherSpecificStreamingMode(TcpIp_GetActiveCipherRxOfTlsConnectionDyn(TlsConIdx));

  /* ----- Implementation ----------------------------------------------- */
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  if (   (ContentType == TCPIP_TLS_CT_CCS)
      && (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13))                                  /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
  {
    /* #10 Ensure that CCS in TLS 1.3 is decrypted with Null. */
    /* If ContentType is CCS and active TLS Version is 1.3 the message is unencrypted and no decryption is needed.
     * Therefore, set activeStreamingMode for this case to TCPIP_TLS_STREAMING_MODE_NULL. */
    activeStreamingMode = TCPIP_TLS_STREAMING_MODE_NULL;
  }
# endif

  /* #20 Depending on active cipher, decrypt the provided data into TLS buffer */
  switch (activeStreamingMode)
  {
    case TCPIP_TLS_STREAMING_MODE_NULL:
    {
      /* Data processing done by NULL cipher, also used for handshake and CCS messages */
      TcpIp_SetDecryptAlgoTypeOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_DECRYPT_ALGO_TYPE_NULL);
      retVal = TcpIp_TlsCoreRl_DecryptAndAuthenticateFrameViaNull(TlsConIdx, ContentType, DataPtr, DataLen);
      break;
    } /* case Null streaming */
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
    case TCPIP_TLS_STREAMING_MODE_AES_128_CBC:
    {
      TcpIp_SetDecryptAlgoTypeOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_DECRYPT_ALGO_TYPE_CBC);
      retVal = TcpIp_Tls12CoreRl_DecryptAndAuthenticateFrameViaCbc(TlsConIdx, ContentType, DataPtr, DataLen);
      break;
    } /* case Aes128Cbc streaming */
# endif
    case TCPIP_TLS_STREAMING_MODE_AES_128_GCM:
    case TCPIP_TLS_STREAMING_MODE_AES_256_GCM:
    case TCPIP_TLS_STREAMING_MODE_CHACHA20_POLY1305:
    {
      TcpIp_SetDecryptAlgoTypeOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_DECRYPT_ALGO_TYPE_AEAD);
      retVal = TcpIp_TlsCoreRl_DecryptAndAuthenticateFrameViaAead(TlsConIdx, ContentType, DataPtr, DataLen);
      break;
    } /* case AEADBlock128 streaming */
    default:
    {
      /* unsupported streaming mode */
      break;
    } /* default */
  } /* switch */

  if (retVal == E_OK)
  {
    /* Reset the DataSplit struct, if necessary */
    TcpIp_TlsCoreRl_ResetRxDataSplit(TlsConIdx);
  }
  return retVal;
} /* TcpIp_TlsCoreRl_DecryptAndAuthenticateFrameViaStreamingMode */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_RxCipherCheckPlaintextRlSizeLimit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_RxCipherCheckPlaintextRlSizeLimit(
  TcpIp_TlsConnectionIterType  TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_SizeOfTlsBufferRxType activeMaxRlSize = TcpIp_GetActiveMaxRxRlSizeOfTlsConnectionDyn(TlsConIdx);
  /* The length of possibly received HMAC or CBC padding are already subtracted from RlRxCopiedLen. */
  TcpIp_SizeOfTlsBufferRxType processedCopiedLen = TcpIp_GetRlRxCopiedLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Compare the decrypted plaintext data length of the TLS frame with the maximum negotiated RL size */
  /* If RSL is not used, activeMaxRlSize is set to the smaller value of the available buffer size
   * and the maximum plaintext size defined in RFC5246 chapter 6.2.1 via TcpIp_TlsCoreRl_Init(). */
  if ((processedCopiedLen) <= activeMaxRlSize)
  {
    /* Plaintext data length of the TLS frame match with negotiated RL size - return E_OK */
    retVal = E_OK;
  }
  else
  {
    /* Plaintext data length does not match with the negotiated RL size - Trigger TLS-Alert */
    /* RFC8449 - 4. The "record_size_limit" Extension
     *   A TLS endpoint that receives a record larger than its advertised limit MUST
     *   generate a fatal "record_overflow" alert;
     */
    retVal = E_NOT_OK;
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_RECORD_OVERFLOW);
  }

  return retVal;
} /* TcpIp_TlsCoreRl_RxCipherCheckPlaintextRlSizeLimit */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_HandleInvalidRlFrame
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_HandleInvalidRlFrame(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint16, AUTOMATIC) RlFrameLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SocketDynComIdxOfTlsConnectionDynType socketIdx = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  if ((socketIdx < TcpIp_GetSizeOfSocketDyn()) && (TCPIP_SOCKET_IDX_IS_TCP(socketIdx) == TRUE))
  {
    TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
    TcpIp_TlsUserErrorType  rlUserError;

    /* Set the corresponding error id */
    rlUserError.FunctionId = TCPIP_TLS_FCTID_CORE_MAINFCT_RXRL;
    rlUserError.UserErrorId = TCPIP_TLS_ERRORID_RXINCORRECTRLFRAME;
    rlUserError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    /* #10 Report the error to the user */
    TcpIp_TlsCoreError_ReportUserError(rlUserError);

    /* Release the buffers */
    TcpIp_TlsCoreRxBufStruct_ReleaseSegment(tlsBufferMgmtIdx, RlFrameLen);
    TcpIp_Tcp_TlsReceived(socketIdx, (uint16)(RlFrameLen));
  }
  else
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
  }
} /* TcpIp_TlsCoreRl_HandleInvalidRlFrame() */

/***********************************************************************************************************************
 *  TLS CORE RL - CIPHERS
 **********************************************************************************************************************/
/**********************************************************************************************************************
 *   TcpIp_TlsCoreRl_DecryptAndAuthenticateFrameViaNull
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE)  TcpIp_TlsCoreRl_DecryptAndAuthenticateFrameViaNull(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC)     ContentType,
  TCPIP_P2C(uint8)            DataPtr,
  uint16                      DataLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Create decrypt data struct */
  /* This data struct was created in order to be able to pass the data segments
   * compactly to the lower hierarchical functions. */
  TcpIp_TlsDecryptDataType  decryptData = { 0 };

  /* addAuthData and authSeg are not needed in null decryption,
   * nevertheless create segments with zero length (which are not used) to avoid the need for a special handling. */
  TcpIp_SegmentType         addAuthData = { 0 };
  TcpIp_SegmentType         authSeg = { 0 };

  TcpIp_ConstSegmentType    tcpSeg1 = { 0 };
  TcpIp_ConstSegmentType    tcpSeg2 = { 0 };
  TCPIP_P2C(uint8)          tcpSeg1Ptr = TcpIp_GetAddrRxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataPtr;
  uint16                    tcpSeg1Len = TcpIp_GetAddrRxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataLen;
  /* Initialize const buffer segments with their lengths. */
  TcpIp_ConstSegmentInit(&tcpSeg1, &tcpSeg1Ptr[0u], tcpSeg1Len);
  TcpIp_ConstSegmentInit(&tcpSeg2, &DataPtr[0u], DataLen);

  decryptData.TcpSeg1Ptr = &tcpSeg1;
  decryptData.TcpSeg2Ptr = &tcpSeg2;
  decryptData.AddAuthDataSegPtr = &addAuthData;
  decryptData.AuthSegPtr = &authSeg;

  /* #20 Call decrypt function */
  return TcpIp_TlsCoreRl_DecryptAndAuthenticateFrame(TlsConIdx, ContentType, &decryptData);
} /*  TcpIp_TlsCoreRl_DecryptAndAuthenticateFrameViaNull() */

/**********************************************************************************************************************
 *   TcpIp_TlsCoreRl_DecryptAndAuthenticateFrameViaAead
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE)  TcpIp_TlsCoreRl_DecryptAndAuthenticateFrameViaAead(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8                       ContentType,
  TCPIP_P2C(uint8)            DataPtr,
  uint16                      DataLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* Store pointer to TCP segment 1 */
  TCPIP_P2C(uint8)              tcpSeg1Ptr = TcpIp_GetAddrRxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataPtr;
  /* Store length of TCP segment 1 */
  uint16                        tcpSeg1Len = TcpIp_GetAddrRxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataLen;
  /* Store pointer to TCP segment 2 */
  TCPIP_P2C(uint8)              tcpSeg2Ptr = DataPtr;
  /* Store length of TCP segment 2 */
  uint16                        tcpSeg2Len = DataLen;
  /* Local buffer to store AAD bytes, needs enough space for the AA data of all TLS versions */
  uint8                         addAuthData[TCPIP_TLS_BLOCK128_AADATA_MAXLEN] = { 0 };
  /* Local buffer to store authentication tag */
  uint8                         authTag[TCPIP_TLS_BLOCK128_AUTHTAG_LEN] = { 0 };
  /* Explicit Iv length, different between the TLS versions, initialize with the value for TLS 1.2 */
  uint16                        explicitIvLength = TCPIP_TLS_BLOCK128_EXPLICIT_IV_LEN;
  /* Length of the Iv present in the TCP buffer segment 1 */
  uint16                        ivInTcpSeg1Len = 0u;
  /* Length of the Iv present in the TCP buffer segment 2 */
  uint16                        ivInTcpSeg2Len = 0u;
  /* Buffer segment for additional authentication data */
  TcpIp_SegmentType             addAuthDataSeg;
  /* Buffer segment for authentication tag */
  TcpIp_SegmentType             authTagSeg;
  /* Content length used for generating AA data */
  uint16                        contentLen = 0u;
  TcpIp_ConstSegmentType        tcpSeg1;
  TcpIp_ConstSegmentType        tcpSeg2;


  /* Both segments added can't be greater than the buffer length which is uint16 */
  uint16 overallDataLen = tcpSeg1Len + tcpSeg2Len;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#  if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
#  endif
  {
    /* TLS 1.3 */
    /* Explicit Iv does not exist in TLS 1.3 */
    explicitIvLength = 0u;
  }
# endif
  TcpIp_ConstSegmentInit(&tcpSeg1, tcpSeg1Ptr, tcpSeg1Len);
  TcpIp_ConstSegmentInit(&tcpSeg2, tcpSeg2Ptr, tcpSeg2Len);
  TcpIp_TlsCoreRl_GetIvLengthInBufferSegments(&tcpSeg1, explicitIvLength, &ivInTcpSeg1Len, &ivInTcpSeg2Len);

  /* Streaming is active - check if we received at least the minimum number of bytes for an encrypted message */
  if (overallDataLen >= (explicitIvLength + TCPIP_TLS_BLOCK128_AUTHTAG_LEN))                                            /* PRQA S 2991, 2995 */ /* MD_TCPIP_Rule14.3_2741_2742_2991_2992_2995_2996 */
  {
    TcpIp_SegmentInit(&addAuthDataSeg, &addAuthData[0], TCPIP_TLS_BLOCK128_AADATA_MAXLEN);
    TcpIp_SegmentInit(&authTagSeg, &authTag[0], TCPIP_TLS_BLOCK128_AUTHTAG_LEN);
    /* #10 Extract the Iv from the TCP segment(s), and set the key element */
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#  if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
    if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
#  endif
    {
      /* TLS 1.3 */
      /* The nonce and the additional authentication data (AAD) differ in TLS 1.2 and TLS 1.3. */

      /* Total length of ciphertext in the TCP segment(s) */
      contentLen = tcpSeg1Len + tcpSeg2Len;

      /* Generate IV and set into the respective key element */
      retVal = TcpIp_Tls13CoreCrypto_GenerateAEADBlock128Iv(TlsConIdx, FALSE);
    }
# endif
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#  if(TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    else
#  endif
    {
      /* TLS 1.2 */
      /* Total length of ciphertext in the TCP segment(s) */
      contentLen = tcpSeg1Len + tcpSeg2Len - explicitIvLength - TCPIP_TLS_BLOCK128_AUTHTAG_LEN;

      /* Extract Iv from TCP segment(s) and set into the respective key element */
      retVal = TcpIp_Tls12CoreRl_LocateIvInBufferAndSetIvKeyElement(TlsConIdx,
        &tcpSeg1, ivInTcpSeg1Len, &tcpSeg2, ivInTcpSeg2Len);
    }
# endif
    /* #20 Generate AAD for the received TLS Rl frame */
    /* Encrypt has to be set to false */
    TcpIp_TlsCore_AEADBlock128GenerateAADataTlsVersionDependent(
      TlsConIdx, ContentType, contentLen, FALSE, &addAuthDataSeg);

    /* #30 Extract plaintext authentication tag from received TLS Rl frame */
    TcpIp_TlsCoreRl_ExtractAuthTagFromReceivedRlFrame(&tcpSeg1, &tcpSeg2, &authTagSeg);

    /* #40 Perform Block128 decryption of data considering wraparound of TcpIp and Tls buffer */
    if (retVal == E_OK)
    {
      /* #50 Create decrypt data struct */
      /* This data struct was created in order to be able to pass the data segments
       * compactly to the lower hierarchical functions. */
      TcpIp_TlsDecryptDataType  decryptData = { 0 };

      /* Clear the segments so that only they only contain the ciphertext, not the IV and authentication tag anymore. */
      TcpIp_ConstSegmentClear(&tcpSeg1);
      TcpIp_ConstSegmentClear(&tcpSeg2);

      decryptData.TcpSeg1Ptr = &tcpSeg1;
      decryptData.TcpSeg2Ptr = &tcpSeg2;
      decryptData.AddAuthDataSegPtr = &addAuthDataSeg;
      decryptData.AuthSegPtr = &authTagSeg;

      retVal = TcpIp_TlsCoreRl_DecryptAndAuthenticateFrame(TlsConIdx, ContentType, &decryptData);
    }
  }
  return retVal;
} /* TcpIp_TlsCoreRl_DecryptAndAuthenticateFrameViaAead */

/**********************************************************************************************************************
 *   TcpIp_TlsCoreRl_GetIvLengthInBufferSegments
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE)  TcpIp_TlsCoreRl_GetIvLengthInBufferSegments(
  TCPIP_P2C(TcpIp_ConstSegmentType)      TcpSeg1Ptr,
  uint16                                 ExplicitIvLen,
  TCPIP_P2V(uint16)                      TcpSeg1IvLenPtr,
  TCPIP_P2V(uint16)                      TcpSeg2IvLenPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check how Iv is located in the two buffer segments and update their lengths accordingly. */
  /* ExplicitIvLen = 0 is allowed, else-path will be executed
   * where *TcpSeg1IvLenPtr = *TcpSeg2IvLenPtr = 0 will be set. */
  if (TcpSeg1Ptr->Size < ExplicitIvLen)
  {
    /* Iv is split between TCP segment 1 and 2 */

    *TcpSeg1IvLenPtr = (uint16)TcpSeg1Ptr->Size;
    *TcpSeg2IvLenPtr = ExplicitIvLen - (uint16)TcpSeg1Ptr->Size;
  }
  else /* (TcpSeg1Ptr->Size >= ExplicitIvLen) */
  {
    /* Iv is entirely in TCP segment 1 */
    *TcpSeg1IvLenPtr = ExplicitIvLen;
    *TcpSeg2IvLenPtr = 0u;
  }
} /* TcpIp_TlsCoreRl_GetIvLengthInBufferSegments() */

/**********************************************************************************************************************
 *   TcpIp_TlsCoreRl_ExtractAuthTagFromReceivedRlFrame
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE)  TcpIp_TlsCoreRl_ExtractAuthTagFromReceivedRlFrame(
  TCPIP_P2V(TcpIp_ConstSegmentType)      TcpSeg1Ptr,
  TCPIP_P2V(TcpIp_ConstSegmentType)      TcpSeg2Ptr,
  TcpIp_SegmentPtrType                   AuthTagSegPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Extract plaintext authentication tag from received TLS Rl frame */
  /* Authentication tag is located at the end of the Rl frame. */
  if (TcpSeg2Ptr->Size < TCPIP_TLS_BLOCK128_AUTHTAG_LEN)
  {
    /* Authentication tag is split between the two TCP segments */
    uint16 tcpSeg1AuthTagLenPtr = (TCPIP_TLS_BLOCK128_AUTHTAG_LEN - (uint16) TcpSeg2Ptr->Size);
    uint16 tcpSeg2AuthTagLenPtr = (uint16) TcpSeg2Ptr->Size;

    /* Copy authentication tag in the two TCP segments into authentication tag buffer segment */
    TcpIp_SegmentMemCpyFromEndOfConstSegment(AuthTagSegPtr, TcpSeg1Ptr, tcpSeg1AuthTagLenPtr);
    TcpIp_SegmentMemCpyFromConstSegment(AuthTagSegPtr, TcpSeg2Ptr, tcpSeg2AuthTagLenPtr);
  }
  else
  {
    /* Authentication tag is entirely in TCP segment 2 */
    /* Copy the authentication tag to the buffer segment */
    TcpIp_SegmentMemCpyFromEndOfConstSegment(AuthTagSegPtr, TcpSeg2Ptr, TCPIP_TLS_BLOCK128_AUTHTAG_LEN);
  }
} /* TcpIp_TlsCoreRl_ExtractAuthTagFromReceivedRlFrame() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_RlFrameFitsInTlsRxBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsCoreRl_RlFrameFitsInTlsRxBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint8                       ContentType,
  uint16                      RlFrameLen)
{
  /* ----- Local Variables----------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* Flag indicates if the Rl frame fits into the buffer */
  boolean fitFlag;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Depending on the content type, check if Rx buffer has sufficient space */
  switch (ContentType)
  {
    case TCPIP_TLS_CT_HS:
    case TCPIP_TLS_CT_AD:
    {
      /* Since the AdHs buffer is a ring buffer, calculate the space available based on the fill level. */
      /* Calculate the total free space available in the TLS Rx AdHs buffer. */
      TcpIp_TlsBufferRxIterType totalFreeSpace =
        ((TcpIp_TlsBufferRxIterType)TcpIp_GetTlsBufferRxAdHsLengthOfTlsBufferMgmt(tlsBufferMgmtIdx)
        - (TcpIp_TlsBufferRxIterType)TcpIp_GetAdRxFillLevelOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

      /* If possible also request for 4 blocks of additional data */
      if (totalFreeSpace > TCPIP_TLS_MIN_BUFFER_SIZE)
      {
        /* Decrement the free space by 4 blocks, since these are reserved for the [Sliding End Index] */
        totalFreeSpace -= TCPIP_TLS_MIN_BUFFER_SIZE;
      }

      if (RlFrameLen <= totalFreeSpace)
      {
        fitFlag = TRUE;
      }
      else
      {
        fitFlag = FALSE;
      }
      break;
    }
    case TCPIP_TLS_CT_AL:
    {
      /* Alert buffer is linear and always overwritten so just check against whole buffer */
      if (RlFrameLen <= TcpIp_GetTlsBufferRxAlLengthOfTlsBufferMgmt(tlsBufferMgmtIdx))
      {
        fitFlag = TRUE;
      }
      else
      {
        fitFlag = FALSE;
      }
      break;
    }
    case TCPIP_TLS_CT_CCS:
    {
      /* Ccs buffer is linear and always overwritten so just check against whole buffer */
      if (RlFrameLen <= TcpIp_GetTlsBufferRxCcsLengthOfTlsBufferMgmt(tlsBufferMgmtIdx))
      {
        fitFlag = TRUE;
      }
      else
      {
        fitFlag = FALSE;
      }
      break;
    }
    default:
    {
      /* Invalid content type */
      fitFlag = FALSE;
      break;
    }
  }

  return fitFlag;
} /* TcpIp_TlsCoreRl_RlFrameFitsInTlsRxBuffer */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_CalcHmacShaContentTypeDependent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_CalcHmacShaContentTypeDependent(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType  tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  uint8                          contentType = TcpIp_GetRlTxContentTypeOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Depending on content type, calculate the Mac */
  if ((contentType == TCPIP_TLS_CT_HS) || (contentType == TCPIP_TLS_CT_AD))
  {
    /* HMAC and data is in the AdHs */
    retVal = TcpIp_TlsCoreRl_CalcHmacShaAdHs(TlsConIdx);
  }
  else if (contentType == TCPIP_TLS_CT_AL)
  {
    /* HMAC and data is in the Al */
    retVal = TcpIp_TlsCoreRl_CalcHmacShaAl(TlsConIdx);
  }
  else
  {
    /* Should never happen. ContentType Check is done by Record Layer Rx functions */
  }

  return retVal;
} /* TcpIp_TlsCoreRl_CalcHmacShaContentTypeDependent() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_CalcHmacShaAdHs
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_CalcHmacShaAdHs(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_TlsBufferTxRlSendIdxOfTlsBufferMgmtDynType rlFrameStartTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxRlSendIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  TcpIp_TlsBufferTxAdHsEndIdxOfTlsBufferMgmtType endTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  TcpIp_TlsBufferTxAdHsStartIdxOfTlsBufferMgmtType startTlsBufferTxIdx =
    TcpIp_GetTlsBufferTxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  TcpIp_SizeOfTlsTemporaryHmacBufferType bufferStartIdx =
    TcpIp_GetTlsTemporaryHmacBufferStartIdxOfTlsConnection(TlsConIdx);

  uint32 macOutLen = (uint32)TcpIp_GetTlsTemporaryHmacBufferEndIdxOfTlsConnection(TlsConIdx) - bufferStartIdx;

  uint32 expectedMacLen = TcpIp_GetCipherMacKeyLengthOfTlsCipherWorker(activeTlsCipherWorkerIdx);
  uint32 plaintextLen = TcpIp_GetRlTxContentTypeLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  /* local array that contains the sequence counter and the record layer header */
  uint8               tmpSeqCounterAndRlHdr[TCPIP_TLS_RL_SEQUENCE_NUM_LEN + TCPIP_TLS_RLHDRLEN];
  TCPIP_P2V(uint8)    seqCounterPtr = &tmpSeqCounterAndRlHdr[0];
  TCPIP_P2V(uint8)    rlHdrPtr      = &tmpSeqCounterAndRlHdr[TCPIP_TLS_RL_SEQUENCE_NUM_LEN];

  TcpIp_CsmJobIdType csmJobIdMacGenerate
    = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHmacGenerateIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));

  TCPIP_P2C(uint8) tlsSeg1Ptr = TcpIp_GetAddrTlsBufferTx(rlFrameStartTlsBufferTxIdx);
  uint32 tlsSeg1Len = plaintextLen;

  Std_ReturnType retVal;
  Std_ReturnType csmRetVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Start the HMAC generation and feed the sequence number and the record layer header as first input. */
  /* Copy the rx sequence number to a local byte array. */
  IpBase_PutUint64(seqCounterPtr, 0, TcpIp_GetRlTxSequenceCounterOfTlsConnectionDyn(TlsConIdx));

  /* Build the RL Header into the local byte array. */
  rlHdrPtr[TCPIP_TLS_RLCT_OFFSET] = TcpIp_GetRlTxContentTypeOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  rlHdrPtr[TCPIP_TLS_RLVERSMAJOR_OFFSET] = TCPIP_TLS_RL_VERSMAJOR;
  rlHdrPtr[TCPIP_TLS_RLVERSMINOR_OFFSET] = TCPIP_TLS_RL_VERSMINOR;
  IpBase_PutUint16(&rlHdrPtr[TCPIP_TLS_RLLENHIGH_OFFSET], 0, (uint16)plaintextLen);

  /* Start the MAC generation */
  csmRetVal = TCPIP_CSM_MacGenerate(csmJobIdMacGenerate, CRYPTO_OPERATIONMODE_STREAMSTART, &tmpSeqCounterAndRlHdr[0],
   (TCPIP_TLS_RL_SEQUENCE_NUM_LEN + TCPIP_TLS_RLHDRLEN), NULL_PTR, NULL_PTR);

  /* #20 Considering Tls wraparound, feed the MAC and stop MAC generation */
  if ((rlFrameStartTlsBufferTxIdx + plaintextLen) <= endTlsBufferTxIdx)
  {
    /* Generate MAC for plaintext in TLS segment 1 */
    csmRetVal |= TcpIp_TlsCoreCrypto_MacGenerateSafe(csmJobIdMacGenerate, CRYPTO_OPERATIONMODE_UPDATE | CRYPTO_OPERATIONMODE_FINISH,
      tlsSeg1Ptr, tlsSeg1Len, bufferStartIdx, &macOutLen);
  }
  else
  {
    /* Part of plaintext is present in TLS segment 2 */
    TCPIP_P2C(uint8) tlsSeg2Ptr;
    uint32 tlsSeg2Len;

    /* Calculate length of plaintext in TLS segment 1 */
    tlsSeg1Len = ((uint32)endTlsBufferTxIdx - rlFrameStartTlsBufferTxIdx);
    /* Calculate length of plaintext in TLS segment 2 */
    tlsSeg2Ptr = TcpIp_GetAddrTlsBufferTx(startTlsBufferTxIdx);
    tlsSeg2Len = (plaintextLen - tlsSeg1Len);

    /* Generate Mac for plaintext in TLS segment 1  */
    csmRetVal |= TCPIP_CSM_MacGenerate(csmJobIdMacGenerate, CRYPTO_OPERATIONMODE_UPDATE, tlsSeg1Ptr, tlsSeg1Len,
      NULL_PTR, NULL_PTR);

    /* Update and Finish the Mac generation for plaintext in TLS segment 2 */
    csmRetVal |= TcpIp_TlsCoreCrypto_MacGenerateSafe(csmJobIdMacGenerate, CRYPTO_OPERATIONMODE_UPDATE | CRYPTO_OPERATIONMODE_FINISH,
      tlsSeg2Ptr, tlsSeg2Len, bufferStartIdx, &macOutLen);
  }

  /* Check if the result of the CSM operation and the expected length match */
  retVal = TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, macOutLen, expectedMacLen,
    TCPIP_TLS_FCTID_CORE_CRYPTO_CALC_HMAC);

  return retVal;
} /* TcpIp_TlsCoreRl_CalcHmacShaAdHs() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_CalcHmacShaAl
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_CalcHmacShaAl(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_SizeOfTlsTemporaryHmacBufferType bufferStartIdx = TcpIp_GetTlsTemporaryHmacBufferStartIdxOfTlsConnection(TlsConIdx);
  uint32 macLen = (uint32)TcpIp_GetTlsTemporaryHmacBufferEndIdxOfTlsConnection(TlsConIdx) - bufferStartIdx;
  uint8 contentType = TcpIp_GetRlTxContentTypeOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  uint32 txLen = TcpIp_GetRlTxContentTypeLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  uint32 expectedMacLen = TcpIp_GetCipherMacKeyLengthOfTlsCipherWorker(activeTlsCipherWorkerIdx);
  TcpIp_TlsBufferTxRlSendIdxOfTlsBufferMgmtDynType rlFrameStartTlsBufferTxIdx
    = TcpIp_GetTlsBufferTxRlSendIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  /* local array that contains the sequence counter, the record layer header and the alert data */
  uint8            tmpLocalArray[TCPIP_TLS_RL_SEQUENCE_NUM_LEN + TCPIP_TLS_RLHDRLEN + TCPIP_TLS_CT_ALERT_LEN];
  const uint32     tmpLocalArrayLen = TCPIP_TLS_RL_SEQUENCE_NUM_LEN + TCPIP_TLS_RLHDRLEN + TCPIP_TLS_CT_ALERT_LEN;
  TCPIP_P2C(uint8) tmpLocalArrayPtr = &tmpLocalArray[0];
  TCPIP_P2V(uint8) seqCounterPtr    = &tmpLocalArray[0];
  TCPIP_P2V(uint8) rlHdrPtr         = &tmpLocalArray[TCPIP_TLS_RL_SEQUENCE_NUM_LEN];
  TCPIP_P2V(uint8) alertDataPtr     = &tmpLocalArray[TCPIP_TLS_RL_SEQUENCE_NUM_LEN + TCPIP_TLS_RLHDRLEN];

  TcpIp_CsmJobIdType csmJobIdMacGenerate
    = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHmacGenerateIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));

  TCPIP_P2C(uint8) dataPart1Ptr = TcpIp_GetAddrTlsBufferTx(rlFrameStartTlsBufferTxIdx);

  Std_ReturnType retVal;
  Std_ReturnType csmRetVal;

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_ASSERT(txLen == TCPIP_TLS_CT_ALERT_LEN);

  /* #10 Copy sequence number, RL header and alert data to prepare the MAC generation. */
  /* Copy the tx sequence number into tmpLocalArray. */
  IpBase_PutUint64(seqCounterPtr, 0, TcpIp_GetRlTxSequenceCounterOfTlsConnectionDyn(TlsConIdx));

  /* Build the record layer header into tmpLocalArray. */
  rlHdrPtr[TCPIP_TLS_RLCT_OFFSET] = contentType;
  rlHdrPtr[TCPIP_TLS_RLVERSMAJOR_OFFSET] = TCPIP_TLS_RL_VERSMAJOR;
  rlHdrPtr[TCPIP_TLS_RLVERSMINOR_OFFSET] = TCPIP_TLS_RL_VERSMINOR;
  IpBase_PutUint16(&rlHdrPtr[TCPIP_TLS_RLLENHIGH_OFFSET], 0, (uint16)txLen);

  /* Copy the alert data into tmpLocalArray. */
  alertDataPtr[0] = dataPart1Ptr[0];
  alertDataPtr[1] = dataPart1Ptr[1];

  /* #20 Use all merged data for the MAC generation. */
  csmRetVal = TcpIp_TlsCoreCrypto_MacGenerateSafe(csmJobIdMacGenerate, CRYPTO_OPERATIONMODE_SINGLECALL,
    tmpLocalArrayPtr, tmpLocalArrayLen, bufferStartIdx, &macLen);

  /* Check result of CSM operation, and report user error if necessary */
  if (TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, macLen, expectedMacLen,
        TCPIP_TLS_FCTID_CORE_CRYPTO_CALC_HMAC) == E_OK)
  {
    retVal = E_OK;
  }
  else
  {
    /* if not successful, report the user error */
    TcpIp_TlsUserErrorType userError;

    userError.FunctionId = TCPIP_TLS_FCTID_CORE_CRYPTO_CALC_HMAC;
    userError.UserErrorId = TCPIP_TLS_ERRORID_CRYPTO_CALCHMAC_FAILED;
    userError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(userError);
    retVal = E_NOT_OK;
  }

  return retVal;
} /* TcpIp_TlsCoreRl_CalcHmacShaAl() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_HandleErrorWhileTransmit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_HandleErrorWhileTransmit(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsUserErrorIdType ErrorId)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsUserErrorType userError;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Update the Error ID and report user error */
  userError.FunctionId = TCPIP_TLS_FCTID_CORE_RL_TRANSMIT;
  userError.UserErrorId = ErrorId;
  userError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

  TcpIp_TlsCoreError_ReportUserError(userError);

} /* TcpIp_TlsCoreRl_HandleErrorWhileTransmit() */

/**********************************************************************************************************************
 *  TCPIP TLS INIT FUNCTIONS
 *********************************************************************************************************************/
# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCore_RemoveLoadedCerts
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsCore_RemoveLoadedCerts(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCertValidationStatusDynIterType tlsCertValidationStatusIdx
    = TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  if (tlsCertValidationStatusIdx != TCPIP_NO_TLSCERTVALIDATIONSTATUSDYNSTARTIDXOFTLSCONNECTION)
  {
    TCPIP_ASSERT(TcpIp_GetTlsCertValidationStatusDynValidEndIdxOfTlsConnectionDyn(TlsConIdx) <= TcpIp_GetTlsCertValidationStatusDynEndIdxOfTlsConnection(TlsConIdx));

    /* #10 Clear all loaded certificates */
    /* Iterate over all TLS certificates */
    for (; tlsCertValidationStatusIdx < TcpIp_GetTlsCertValidationStatusDynValidEndIdxOfTlsConnectionDyn(TlsConIdx);
           tlsCertValidationStatusIdx++)
    {
      /* Delete current loaded certificate */
      /* KeyM API available since version 4.03.00 - Change in TcpIp version 16.09.00 */
      (void)KeyM_CertDelete(TcpIp_GetAddrTlsCertValidationStatusDyn(tlsCertValidationStatusIdx)->CertId);
    }
  }
} /* TcpIp_TlsCore_RemoveLoadedCerts() */
# endif /* TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsCore_Init
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
FUNC(void, TCPIP_CODE) TcpIp_TlsCore_Init(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsConnectionIterType tlsConIdx;
  TcpIp_TlsCipherWorkerIterType tlsCipherWorkerIdx;
  TcpIp_SocketTcpDynIterType socketTcpIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all configured TLS-Connections and initialize the submodules */
  for (tlsConIdx = 0; tlsConIdx < TcpIp_GetSizeOfTlsConnection(); tlsConIdx++)
  {
    TcpIp_TlsCore_ResetConnectionVariables(tlsConIdx);

    TcpIp_SetSocketDynComIdxOfTlsConnectionDyn(tlsConIdx, TCPIP_NO_SOCKETDYNCOMIDXOFTLSCONNECTIONDYN);
  }

  /* #20 Iterate over all configured Sockets and initialize the tls variable to the default values */
  for (socketTcpIdx = 0; socketTcpIdx < TcpIp_GetSizeOfSocketTcpDyn(); socketTcpIdx++)
  {
    TcpIp_SetTlsConnectionIdxOfSocketTcpDyn(socketTcpIdx, TCPIP_NO_TLSCONNECTIONIDXOFSOCKETTCPDYN);
  }

  /* #30 Iterate over all configured CipherWorker and initialize the variable to the default values */
  for (tlsCipherWorkerIdx = 0; tlsCipherWorkerIdx < TcpIp_GetSizeOfTlsCipherWorker(); tlsCipherWorkerIdx++)
  {
    TcpIp_SetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(tlsCipherWorkerIdx,
      TCPIP_NO_TLSHANDSHAKEACTIVEIDXOFTLSCIPHERWORKERDYN);
  }

# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
  /* #40 Initialize the global TLS-Listener */
  TcpIp_TlsServerListener_Init();
# endif

# if ( TCPIP_DEV_ERROR_DETECT == STD_ON )
  /* #50 Initialize the buffer idx log table */
  TcpIp_TlsRxBufferIdxLogPos = 0u;

  /* Set all items of the table to 0u */
  for(uint16 arrIdx = 0u; arrIdx < TCPIP_TLS_RX_BUFFER_IDX_LOG_SIZE; arrIdx++)
  {
    for(uint8 itemIdx = 0u; itemIdx < TCPIP_TLS_RX_BUFFER_IDX_LOG_INFO_SIZE; itemIdx++)
    {
      TcpIp_TlsRxBufferIdxLog[arrIdx][itemIdx] = 0u;
    }
  }
# endif

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  /* #60 Init all PSK identities */
  TcpIp_Tls13PskIdentityIterType pskIterIdx = 0;

  for (; (pskIterIdx < TcpIp_GetSizeOfTls13PskIdentity()); pskIterIdx++)
  {
    TcpIp_Tls13Core_InitializePskIdentity(pskIterIdx);
  }

# endif
} /* TcpIp_TlsCore_Init() */

/**********************************************************************************************************************
 *  TcpIp_TlsCore_ResetConnection
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCore_ResetConnection(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Reset Connection variables depending on mode of this TLS-Connection */
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
#  endif
  {
    /* Mode == TCPIP_TLS_SERVER */
    TcpIp_TlsServer_ResetConnection(TlsConIdx);
  }
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  else
#  endif
# endif
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  {
    /* Mode == TCPIP_TLS_CLIENT */
    TcpIp_TlsClient_InitConnection(TlsConIdx);
  }
# endif

# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
  /* Remove all loaded server / client certificates */
  TcpIp_TlsCore_RemoveLoadedCerts(TlsConIdx);
# endif

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
#  endif
  {
    /* Delete connection keys if connection was TLS version 1.3 - ISO15118-20: [V2G20-2046]+ [V2G20-2047] */
    (void)TcpIp_Tls13CoreCtx_DeleteConnectionKeys(TlsConIdx);
  }

  /* Reset session resumption PSK identity which is in use if the connection was a resumed connection */
  TcpIp_Tls13PskIdentityIterType activeTls13PskIdentityIdx
    = TcpIp_GetTls13PskIdentityActiveIdxOfTlsConnectionDyn(TlsConIdx);
  if (activeTls13PskIdentityIdx != TCPIP_NO_TLS13PSKIDENTITYACTIVEIDXOFTLSCONNECTIONDYN)
  {
    TcpIp_Tls13Core_InitializePskIdentity(activeTls13PskIdentityIdx);
  }
# endif

  TcpIp_TlsCore_ResetConnectionVariables(TlsConIdx);
} /* TcpIp_TlsCore_ResetConnection() */

/**********************************************************************************************************************
 *  TcpIp_TlsCore_ResetConnectionVariables
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_TlsResetConnection_STCAL_6050 */
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCore_ResetConnectionVariables(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Reset the Tls core connection variables */
  TcpIp_TlsCoreBuffer_Init(TlsConIdx);

  TcpIp_TlsCoreBufferStruct_Init(TlsConIdx);

  TcpIp_TlsCoreAlert_Init(TlsConIdx);

  TcpIp_TlsCoreError_Init(TlsConIdx);

  TcpIp_TlsCoreRl_Init(TlsConIdx);

  TcpIp_TlsCoreRxIndication_Init(TlsConIdx);

  TcpIp_TlsCoreCipher_Init(TlsConIdx);

  TcpIp_TlsCoreConnection_Init(TlsConIdx);

  TcpIp_TlsCore_InitAsyncFlags(TlsConIdx);

# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
  TcpIp_TlsCore_InitCertChainStates(TlsConIdx);
# endif

# if ((TCPIP_SUPPORT_ASRTLS_MASTER_SECRET_ACCESS == STD_ON) && (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON))
  TcpIp_Tls12Core_ClearMasterSecretBuffer(TlsConIdx);
# endif

} /* TcpIp_TlsCore_ResetConnectionVariables() */

# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCore_InitCertChainStates
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCore_InitCertChainStates(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCertValidationStatusDynIterType tlsCertValidationStatusIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Clear all certificate statuses */
  for (tlsCertValidationStatusIdx = TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx);
       tlsCertValidationStatusIdx < TcpIp_GetTlsCertValidationStatusDynEndIdxOfTlsConnection(TlsConIdx);
       tlsCertValidationStatusIdx++)
  {
    TcpIp_GetAddrTlsCertValidationStatusDyn(tlsCertValidationStatusIdx)->CertId         = TCPIP_CERTID_INV;
    TcpIp_GetAddrTlsCertValidationStatusDyn(tlsCertValidationStatusIdx)->CertStatus     = KEYM_CERTIFICATE_NOT_AVAILABLE;
    TcpIp_GetAddrTlsCertValidationStatusDyn(tlsCertValidationStatusIdx)->IsSelfSigned   = FALSE;

    /* Ocsp information */
    TcpIp_GetAddrTlsCertValidationStatusDyn(tlsCertValidationStatusIdx)->CertStatusResponse.OcspCertStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;
    TcpIp_GetAddrTlsCertValidationStatusDyn(tlsCertValidationStatusIdx)->CertStatusResponse.OcspMode = TCPIP_TLS_OCSP_MODE_NONE;
    TcpIp_GetAddrTlsCertValidationStatusDyn(tlsCertValidationStatusIdx)->CertStatusResponse.OcspResponseStatus = TCPIP_TLS_OCSP_RESPONSE_STATUS_INVALID;
    TcpIp_GetAddrTlsCertValidationStatusDyn(tlsCertValidationStatusIdx)->CertStatusResponse.OcspConnectionState = TCPIP_TLS_OCSP_CONNECTION_STATE_INACTIVE;
  }

  /* Reset the leaf cert Id */
  TcpIp_SetHsLeafCertIdOfTlsConnectionDyn(TlsConIdx, TCPIP_CERTID_INV);

  /* Reset the valid end idx of the certificate chain struct */
  TcpIp_SetTlsCertValidationStatusDynValidEndIdxOfTlsConnectionDyn(TlsConIdx,
    TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx));

  TcpIp_SetTlsCertValidationStatusDynCurrentIdxOfTlsConnectionDyn(TlsConIdx,
    TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx));

  /* Initialize the process state of the remote certificate chain */
  /* [HS Server Certificate Chain Handling StM] / [HS Client Certificate Chain Handling StM]
   * Init state, no certificates received */
  TcpIp_SetHsCertStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CERTCHAIN_INIT);

} /* TcpIp_TlsCore_InitCertChainStates */
# endif

/**********************************************************************************************************************
 *  TcpIp_TlsCore_InitAsyncFlags
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCore_InitAsyncFlags(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize the async context flags with the default values */
  TcpIp_SetDhPubKeyKeyExchangeAsyncFlagOfTlsConnectionDyn(TlsConIdx, FALSE);
  TcpIp_SetDhPubKeyKeyShareExtCurveAsyncTriggerOfTlsConnectionDyn(TlsConIdx, TCPIP_CURVE_ID_NO_CURVE);
  TcpIp_SetDhSharedSecretAsyncFlagOfTlsConnectionDyn(TlsConIdx, FALSE);
  TcpIp_SetCalcMasterSecretAsyncFlagOfTlsConnectionDyn(TlsConIdx, FALSE);
  TcpIp_SetPskPremasterSecretAsyncFlagOfTlsConnectionDyn(TlsConIdx, FALSE);

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  TcpIp_SetCalcApplTrafficKeysAsyncFlagOfTlsConnectionDyn(TlsConIdx, FALSE);
  TcpIp_SetCalcHsTrafficKeysAsyncFlagOfTlsConnectionDyn(TlsConIdx, FALSE);
  TcpIp_SetCalcResumptionMasterSecretAsyncFlagOfTlsConnectionDyn(TlsConIdx, FALSE);
  TcpIp_SetCalcPskValueAsyncFlagOfTlsConnectionDyn(TlsConIdx, FALSE);
# endif
} /* TcpIp_TlsCore_InitAsyncFlags() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRxIndication_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRxIndication_Init(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize RX-Indication flags */
  TcpIp_SetRlRxIndicationFlagOfTlsConnectionDyn(TlsConIdx, FALSE);
  TcpIp_SetCcsRxIndicationOfTlsConnectionDyn(TlsConIdx, FALSE);
  TcpIp_SetAlRxIndicationOfTlsConnectionDyn(TlsConIdx, FALSE);
  TcpIp_SetAdRxIndicationOfTlsConnectionDyn(TlsConIdx, FALSE);
  TcpIp_SetHsRxIndicationCntOfTlsConnectionDyn(TlsConIdx, 0u);
} /* TcpIp_TlsCoreRxIndication_Init() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCipher_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCipher_Init(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize RX and TX ciphers selection */
  TcpIp_SetActiveCipherRxOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_NULL_WITH_NULL_NULL);
  TcpIp_SetActiveCipherTxOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_NULL_WITH_NULL_NULL);
  TcpIp_SetCcsReceivableOfTlsConnectionDyn(TlsConIdx, FALSE);
  TcpIp_SetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx, TCPIP_NO_TLSCIPHERWORKERACTIVEIDXOFTLSCONNECTIONDYN);
  TcpIp_SetDecryptAlgoTypeOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_DECRYPT_ALGO_TYPE_NULL);

} /* TcpIp_TlsCoreCipher_Init() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreConnection_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreConnection_Init(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize TLS-Connection variables */
  TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_NO_ASYNC);

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  /* Initialize session resumption variables. */
  /* Note: This needs to be done before resetting the SocketOwnerConfigIdx, because SocketOwnerConfigIdx is used in the
     SessionTicketUpdateCallout. */
  TcpIp_SetSessionResumptionUsingPskOfTlsConnectionDyn(TlsConIdx, FALSE);
  TcpIp_SetTls13PskIdentityActiveIdxOfTlsConnectionDyn(TlsConIdx,
    TCPIP_NO_TLS13PSKIDENTITYACTIVEIDXOFTLSCONNECTIONDYN);
  /* For resumption base connection iterate over all referenced PSK identities. */
  TcpIp_Tls13PskIdentityIndIterType tls13PskIdentityIndIdx
    = TcpIp_GetTls13PskIdentityIndStartIdxOfTlsConnection(TlsConIdx);
  for (; tls13PskIdentityIndIdx < TcpIp_GetTls13PskIdentityIndEndIdxOfTlsConnection(TlsConIdx);
         tls13PskIdentityIndIdx++)
  {
    TcpIp_Tls13PskIdentityIndType tls13PskIdentityIdx = TcpIp_GetTls13PskIdentityInd(tls13PskIdentityIndIdx);
    TcpIp_TlsSessionTicketStateType state = TcpIp_GetSessionTicketStateOfTls13PskIdentityDyn(tls13PskIdentityIdx);
    /* If a session ticket was received for a PSK identity but not used, reset the PSK identity. */
    if (state == TCPIP_TLS_SESSION_TICKET_AVAILABLE)
    {
      TcpIp_Tls13Core_InitializePskIdentity(tls13PskIdentityIdx);
      TcpIp_Tls13Client_SessionTicketUpdateCallout(TlsConIdx);
    }
  }
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */

# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
  /* Clear client authentication callout info struct */
  TcpIp_TlsClientAuthenticationMgmtIdxOfTlsConnectionType tlsClientAuthenticationMgmtIdx
    = TcpIp_GetTlsClientAuthenticationMgmtIdxOfTlsConnection(TlsConIdx);

  if (tlsClientAuthenticationMgmtIdx != TCPIP_NO_TLSCLIENTAUTHENTICATIONMGMTIDXOFTLSCONNECTION)
  {
    TCPIP_CP2V(TcpIp_TlsCertRequestInfoType) certRequestInfoPtr
      = TcpIp_GetAddrRequestInfoOfTlsClientAuthenticationMgmt(tlsClientAuthenticationMgmtIdx);

    certRequestInfoPtr->SignatureAndHashAlgoListPtr = (TCPIP_P2C(uint16))NULL_PTR;
    certRequestInfoPtr->SignatureAndHashAlgoNum = 0u;
  }
# endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

  /* Initialize the Listen Socket and mark TLS-Connection as unused */
  TcpIp_SetSocketDynListenIdxOfTlsConnectionDyn(TlsConIdx, TCPIP_NO_SOCKETDYNLISTENIDXOFTLSCONNECTIONDYN);
  TcpIp_SetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx, TCPIP_NO_SOCKETDYNCOMIDXOFTLSCONNECTIONDYN);
  TcpIp_SetSocketOwnerConfigIdxOfTlsConnectionDyn(TlsConIdx, TCPIP_NO_SOCKETOWNERCONFIGIDXOFTLSCONNECTIONDYN);

  /* Initialize the KeyBlock size information */
  TcpIp_SetKeyBlockSizeOfTlsConnectionDyn(TlsConIdx, 0);
  TcpIp_SetCalcKeyMaterialStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CALC_KEY_MATERIAL_INIT);

  /* Reset the Tls connection state variable */
  TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CONNECTION_HS_INACTIVE);

  /* Reset the Tls active version variable */
  TcpIp_SetActiveVersionOfTlsConnectionDyn(TlsConIdx, TCPIP_TLSVERSION_NOTSET);

  /* Reset the variables for partially received messages */
  TcpIp_SetReceivedBytesOfLastHsMsgPartiallyReceivedOfTlsConnectionDyn(TlsConIdx, 0u);
  TcpIp_SetRemainingBytesOfLastHsMsgPartiallyReceivedOfTlsConnectionDyn(TlsConIdx, 0u);
  TcpIp_SetReceivedBytesOfLastHsHeaderPartiallyReceivedOfTlsConnectionDyn(TlsConIdx, 0u);

  /* Reset the trigger for the version specific state machine */
  TcpIp_SetVersionSpecificHsStmTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);

  /* Reset the handshake state machine TX trigger variable */
  TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);

  /* Initialize the AES-128-CBC padding value */
  TcpIp_SetAes128CbcPaddingByteOfTlsConnectionDyn(TlsConIdx, 0u);

  /* Initialize CCS variables */
  TcpIp_SetCcsReceivedOfTlsConnectionDyn(TlsConIdx, FALSE);
  TcpIp_SetLastHsMsgTypeOfLastReceivedHsRlFrameOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_HSTYPE_INVALID);

  /* Initialize NSS variables */
# if (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  TcpIp_SetNssMasterSecretReadyToSendOfTlsConnectionDyn(TlsConIdx, FALSE);
#  endif
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  TcpIp_SetNssHandshakeTrafficSecretReadyToSendOfTlsConnectionDyn(TlsConIdx, FALSE);
  TcpIp_SetNssApplicationTrafficSecretReadyToSendOfTlsConnectionDyn(TlsConIdx, FALSE);
#  endif
# endif

} /* TcpIp_TlsCoreConnection_Init() */

/**********************************************************************************************************************
 *  TLS CORE BUFFER
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreBuffer_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreBuffer_Init(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize all buffer related variables */
  /* RX Buffer read/write index */
  {
    TcpIp_TlsBufferRxAdHsStartIdxOfTlsBufferMgmtType rxAdHsStartIdx
      = TcpIp_GetTlsBufferRxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

    TcpIp_TlsBufferRxAlStartIdxOfTlsBufferMgmtType rxAlStartIdx
      = TcpIp_GetTlsBufferRxAlStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

    TcpIp_TlsBufferRxCcsStartIdxOfTlsBufferMgmtType rxCcsStartIdx
      = TcpIp_GetTlsBufferRxCcsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

    TcpIp_SetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, rxAdHsStartIdx);
    TcpIp_SetTlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, rxAdHsStartIdx);
    TcpIp_SetTlsBufferRxUlRxIndIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, rxAdHsStartIdx);
    TcpIp_SetTlsBufferRxAdHsCurrHsMsgEndIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, rxAdHsStartIdx);

    /*
     RX-Buffer handling:

     R - ReadIdx                  Indicates the end of all data consumed by the upper layer.
                                  Data after this index is not yet consumed by the upper layer.
     W - WriteIdx                 Indicates the position where the last byte of data is written.
                                  New data can be written after this position into the TLS buffer.
     E - EndTlsBufferTxIdx        Indicates the end of the buffer (this index stays always the same)
     U - UpperlayerIndicationIdx  Indicates the position till which the received data was forwarded to the upper layer.
     M - ReadMax                  Indicates the position till which the buffer is actually filled with data.
                                  This index is not saved in the CSL, but calculated depending on the streaming mode in
                                  TcpIp_TlsCoreRl_GetReadMaxIdxForContentType (EndTlsBufferTxIdx minus two block sizes).

     TLS Rx buffer is a circular buffer. The CSM module decrypts ciphertext
     directly into the TLS Rx buffer during TLS Rx handling. However, CSM does not support the buffer wraparound,
     and always expects sufficient output buffer space to decrypt.
     The buffer from M to E can be used to decrypt data, but the application shall never access that.
     This means that directly after the encryption, data in the area M to E must be copied to the start
     of the buffer. R, W and U must always be in range from start to M.

     Decrypted data is pictured as xxxxx.

     Normal buffer situation when some data was already forwarded to the upper layer (from R till U)
     but not read yet and some data (from U till W) still needs to be forwarded:

       R       U       W                                 M       E
     --V-------V-------V---------------------------------V-------v
     | xxxxxxxxxxxxxxxx        TLS Rx Buffer                     |
     -------------------------------------------------------------

     Buffer situation after the upper layer has read all the received data:

                       R
                       U
                       W                                 M       E
     ------------------V---------------------------------V-------v
     | xxxxxxxxxxxxxxxx        TLS Rx Buffer                     |
     -------------------------------------------------------------

     Special situation during decryption of received TLS AdHs frame when CSM needs the additional space from M to E:

                                               R
                                               U         M    W  E
     ------------------------------------------V---------V----V--v
     |                         TLS Rx Buffer   xxxxxxxxxxxxxxx   |
     -------------------------------------------------------------

     Then in TcpIp_TlsCoreRl_MoveDataOutOfReadMaxArea() the data after M is moved to the start of the buffer.
     Afterwards the data can be forwarded to the upper layer:

                                               R
           W                                   U         M       E
     ------V-----------------------------------V---------V-------v
     |xxxxx                    TLS Rx Buffer   xxxxxxxxxx        |
     -------------------------------------------------------------

     */

    /* Initialize the Rx Read and Write index to 0 */
    TcpIp_SetTlsBufferRxAlReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, rxAlStartIdx);
    TcpIp_SetTlsBufferRxAlWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, rxAlStartIdx);

    TcpIp_SetTlsBufferRxCcsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, rxCcsStartIdx);
    TcpIp_SetTlsBufferRxCcsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, rxCcsStartIdx);

    /* Initialize the Rx Data Split struct */
    TcpIp_GetAddrRxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataPtr = NULL_PTR;
    TcpIp_GetAddrRxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataLen = 0u;

    /* Initialize the fill levels */
    TcpIp_SetAdUlRxIndLevelOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, 0u);
    TcpIp_SetAdRxFillLevelOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, 0u);

    TcpIp_SetRemainingHsPlaintextLenInRxBufOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, 0u);
  }

  /* TX Buffer read/write index */
  {
    TcpIp_TlsBufferTxAdHsStartIdxOfTlsBufferMgmtType txAdHsStartIdx
      = TcpIp_GetTlsBufferTxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

    TcpIp_TlsBufferTxAlStartIdxOfTlsBufferMgmtType txAlStartIdx
      = TcpIp_GetTlsBufferTxAlStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

    TcpIp_TlsBufferTxCcsStartIdxOfTlsBufferMgmtType txCcsStartIdx
      = TcpIp_GetTlsBufferTxCcsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

    /* Initialize the Tx Read and Write index to 0 */
    TcpIp_SetTlsBufferTxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, txAdHsStartIdx);
    TcpIp_SetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, txAdHsStartIdx);

    TcpIp_SetTlsBufferTxAlReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, txAlStartIdx);
    TcpIp_SetTlsBufferTxAlWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, txAlStartIdx);

    TcpIp_SetTlsBufferTxCcsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, txCcsStartIdx);
    TcpIp_SetTlsBufferTxCcsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, txCcsStartIdx);

    /* Initialize the Tx Data Split struct */
    TcpIp_GetAddrTxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataPtr = NULL_PTR;
    TcpIp_GetAddrTxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataLen = 0u;

    /* Initialize the fill levels */
    TcpIp_SetAdTxFillLevelOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, 0u);
  }

  TcpIp_SetLastReceivedHsTypeOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_HSTYPE_INVALID);

} /* TcpIp_TlsCoreBuffer_Init() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreBufferStruct_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreBufferStruct_Init(TcpIp_TlsConnectionIterType TlsConIdx)
{
   TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

   /* #10 Initialize the Rx buffer structures */
   TcpIp_TlsCoreRxBufStruct_Init(tlsBufferMgmtIdx);

} /* TcpIp_TlsCoreBufferStruct_Init() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRxBufStruct_Init()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRxBufStruct_Init(
  TcpIp_SizeOfTlsBufferMgmtType TlsBufferMgmtIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfRxBufStructMgtType rxBufStructMgtIdx = TcpIp_GetRxBufStructMgtIdxOfTlsBufferMgmt(TlsBufferMgmtIdx);
  TcpIp_SizeOfRxBufStructSegType rxBufStructSegIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize buffer struct. */
  TcpIp_SetRxBufStructSegIdxOfRxBufStructMgt(rxBufStructMgtIdx, TcpIp_GetRxBufStructSegStartIdxOfTlsBufferMgmt(
                                                               TlsBufferMgmtIdx));
  TcpIp_SetRxBufStructSegLvlOfRxBufStructMgt(rxBufStructMgtIdx, 0u);

  /* #20 Initialize each buffer segment. */
  for (rxBufStructSegIdx = TcpIp_GetRxBufStructSegStartIdxOfTlsBufferMgmt(TlsBufferMgmtIdx);
       rxBufStructSegIdx < TcpIp_GetRxBufStructSegEndIdxOfTlsBufferMgmt(TlsBufferMgmtIdx);
       rxBufStructSegIdx++)
  {
    TcpIp_SetDataPtrOfRxBufStructSeg(rxBufStructSegIdx, NULL_PTR);
    TcpIp_SetLenOfRxBufStructSeg(rxBufStructSegIdx, 0);
  }

} /* TcpIp_TlsCoreRxBufStruct_Init() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreBuffer_ClearRxBuffer()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreBuffer_ClearRxBuffer(
  CONST(TcpIp_TlsBufferRxIterType, AUTOMATIC) StartTlsBufferRxIdx,
  CONST(TcpIp_TlsBufferRxIterType, AUTOMATIC) EndIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Verify the start and end index of the TX buffer to guarantee a proper calculation of the buffer length. */
  /* \trace TCASE-TCPIP_000726 */
  if (TcpIp_VerifyStartAndEndIndex(StartTlsBufferRxIdx, EndIdx, TcpIp_GetSizeOfTlsBufferRx()) == E_OK)
  {
    TcpIp_TlsBufferRxIterType clearLen = (EndIdx - StartTlsBufferRxIdx);

    /* #20 Clear the buffer from the beginning of the passed start index with the passed length */
    VStdLib_MemClr(TcpIp_GetAddrTlsBufferRx(StartTlsBufferRxIdx), clearLen);                                            /* VCA_TCPIP_TLS_VERIFIED_START_END_IDX */ /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

    retVal = E_OK;
  }

  return retVal;
} /* TcpIp_TlsCoreBuffer_ClearRxBuffer() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreBuffer_ClearTxBuffer()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreBuffer_ClearTxBuffer(
  CONST(TcpIp_TlsBufferTxIterType, AUTOMATIC) StartTlsBufferTxIdx,
  CONST(TcpIp_TlsBufferTxIterType, AUTOMATIC) EndTlsBufferTxIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsBufferTxIterType clearLen;
  /* ----- Implementation ----------------------------------------------- */
  TCPIP_ASSERT(StartTlsBufferTxIdx < TcpIp_GetSizeOfTlsBufferTx());
  TCPIP_ASSERT(EndTlsBufferTxIdx   < TcpIp_GetSizeOfTlsBufferTx());
  TCPIP_ASSERT(StartTlsBufferTxIdx <= EndTlsBufferTxIdx);

  clearLen = (EndTlsBufferTxIdx - StartTlsBufferTxIdx);
  /* #10 Clear the buffer from the beginning of the passed start index with the passed length */
  VStdLib_MemClr(TcpIp_GetAddrTlsBufferTx(StartTlsBufferTxIdx), clearLen);                                              /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
} /* TcpIp_TlsCoreBuffer_ClearTxBuffer() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRxBufStruct_WriteRxBufSegment()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRxBufStruct_WriteRxBufSegment(
  TcpIp_SizeOfRxBufStructSegType RxBufStructSegIdx,
  TCPIP_P2V(uint8) SrcBufPtr,
  uint16 SrcBufLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Update length and data pointer of rxBufStruct. */
  TcpIp_SetLenOfRxBufStructSeg(RxBufStructSegIdx, SrcBufLen);
  TcpIp_SetDataPtrOfRxBufStructSeg(RxBufStructSegIdx, SrcBufPtr);

} /* TcpIp_TlsCoreRxBufStruct_WriteRxBufSegment() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRxBufStruct_GetTotLen()
 **********************************************************************************************************************/
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
TCPIP_LOCAL_INLINE FUNC(uint32, TCPIP_CODE) TcpIp_TlsCoreRxBufStruct_GetTotLen(
  TcpIp_SizeOfTlsBufferMgmtType TlsBufferMgmtIdx,
  uint32 BufSegOffset)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32                         localBufSegOffset = BufSegOffset;
  uint32                         totalLen = 0u;
  TcpIp_RxBufStructSegIterType   bufSegIter;
  TcpIp_SizeOfRxBufStructMgtType rxBufStructMgtIdx = TcpIp_GetRxBufStructMgtIdxOfTlsBufferMgmt(TlsBufferMgmtIdx);
  TcpIp_SizeOfRxBufStructSegType rxBufStructSegIdx = TcpIp_GetRxBufStructSegIdxOfRxBufStructMgt(rxBufStructMgtIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all segments to get the segment of the specified offset. */
  for (bufSegIter = 0u;
       bufSegIter < TcpIp_GetRxBufStructSegLvlOfRxBufStructMgt(rxBufStructMgtIdx);
       bufSegIter++)
  {
    /* #20 Check if offset is in next buffer segment. */
    if (localBufSegOffset >= TcpIp_GetLenOfRxBufStructSeg(rxBufStructSegIdx))
    {
      /* #30 Decrement offset by length of current segment. */
      localBufSegOffset -= TcpIp_GetLenOfRxBufStructSeg(rxBufStructSegIdx);
    }
    /* #40 Consider current buffer segment otherwise. */
    else
    {
      /* #50 Increment total length. */
      totalLen += (uint32)(TcpIp_GetLenOfRxBufStructSeg(rxBufStructSegIdx) - localBufSegOffset);

      /* #60 Set offset to zero to increment total length by whole segment length of next segments. */
      localBufSegOffset = 0u;
    }

    /* #70 Calculate next segment index considering buffer struct wrap around. */
    if ((rxBufStructSegIdx + 1u) == TcpIp_GetRxBufStructSegEndIdxOfTlsBufferMgmt(TlsBufferMgmtIdx))
    {
      rxBufStructSegIdx = TcpIp_GetRxBufStructSegStartIdxOfTlsBufferMgmt(TlsBufferMgmtIdx);
    }
    else
    {
      rxBufStructSegIdx++;
    }
  }

  return totalLen;
} /* TcpIp_TlsCoreRxBufStruct_GetTotLen() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRxBufStruct_Copy2Buf()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRxBufStruct_Copy2Buf(
  TcpIp_SizeOfTlsBufferMgmtType TlsBufferMgmtIdx,
  TCPIP_P2V(uint8) BufPtr,
  uint32 BufLen,
  uint32 BufSegOffset)
{
  /* ----- Local Variables ---------------------------------------------- */
  TCPIP_P2C(uint8)               bufSegPtr;
  uint32                         localBufLen = BufLen;
  uint32                         localBufSegOffset = BufSegOffset;
  uint32                         bytesToCopy = 0xffffu;
  uint32                         bytesCopied = 0u;
  uint32                         segOffset;
  TcpIp_SizeOfRxBufStructSegType rxBufStructSegIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate until all data is copied to provided buffer. */
  while (localBufLen > 0u)
  {
    /* #20 Get index of segment from which shall be copied considering offset. */
    segOffset = localBufSegOffset;
    /* \trace TCASE-TCPIP_000691 */
    /* \trace TCASE-TCPIP_000692 */
    if (   (TcpIp_TlsCoreRxBufStruct_GetBufSegIdx(TlsBufferMgmtIdx, &segOffset, &rxBufStructSegIdx) == E_OK)
        && (rxBufStructSegIdx < TcpIp_GetSizeOfRxBufStructSeg()))
    {
      /* #30 Calculate available data length of segment. */
      bytesToCopy = (uint32)(TcpIp_GetLenOfRxBufStructSeg(rxBufStructSegIdx) - segOffset);

      /* #40 Calculate data length to be copied for this segment. */
      if (localBufLen < bytesToCopy)
      {
        bytesToCopy = localBufLen;
      }

      /* #50 Copy data from current segment to provided buffer. */
      bufSegPtr = TcpIp_GetDataPtrOfRxBufStructSeg(rxBufStructSegIdx);
      TcpIp_MemCpySafe(&BufPtr[0], bytesCopied, BufLen, &bufSegPtr[segOffset], bytesToCopy);
    }
    else
    {
      /* Memory runtime check fails - report DET */
      TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
      break;
    }

    localBufLen -= bytesToCopy;
    bytesCopied += bytesToCopy;
    localBufSegOffset += bytesToCopy;
  }
} /* TcpIp_TlsCoreRxBufStruct_Copy2Buf() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRxBufStruct_GetBufSegIdx()
 **********************************************************************************************************************/
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
TCPIP_LOCAL_INLINE FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRxBufStruct_GetBufSegIdx(
  TcpIp_SizeOfTlsBufferMgmtType TlsBufferMgmtIdx,
  TCPIP_P2V(uint32) OffsetPtr,
  TCPIP_P2V(TcpIp_SizeOfRxBufStructSegType) BufSegIdxPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32                         offset = *OffsetPtr;
  TcpIp_RxBufStructSegIterType   bufSegIter;
  TcpIp_SizeOfRxBufStructMgtType rxBufStructMgtIdx = TcpIp_GetRxBufStructMgtIdxOfTlsBufferMgmt(TlsBufferMgmtIdx);
  TcpIp_SizeOfRxBufStructSegType rxBufStructSegIdx = TcpIp_GetRxBufStructSegIdxOfRxBufStructMgt(rxBufStructMgtIdx);
  Std_ReturnType                 retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  if (rxBufStructSegIdx < TcpIp_GetSizeOfRxBufStructSeg())
  {
    /* #10 Iterate over all segments to get the segment of the specified offset. */
    for (bufSegIter = 0u;
         bufSegIter < TcpIp_GetRxBufStructSegLvlOfRxBufStructMgt(rxBufStructMgtIdx);
         bufSegIter++)
    {
      /* #20 Check if offset is in next buffer segment. */
      if (offset >= TcpIp_GetLenOfRxBufStructSeg(rxBufStructSegIdx))
      {
        /* #30 Decrement offset by length of current segment. */
        offset -= TcpIp_GetLenOfRxBufStructSeg(rxBufStructSegIdx);

        /* #40 Calculate next segment index considering buffer struct wrap around. */
        if ((rxBufStructSegIdx + 1u) == TcpIp_GetRxBufStructSegEndIdxOfTlsBufferMgmt(TlsBufferMgmtIdx))
        {
          rxBufStructSegIdx = TcpIp_GetRxBufStructSegStartIdxOfTlsBufferMgmt(TlsBufferMgmtIdx);
        }
        else
        {
          rxBufStructSegIdx++;
        }
      }
      /* #50 Return current index otherwise. */
      else
      {
        *BufSegIdxPtr = rxBufStructSegIdx;
        *OffsetPtr = offset;
        retVal = E_OK;
        break;
      }
    }
  }
  else
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
  }

  return retVal;
} /* TcpIp_TlsCoreRxBufStruct_GetBufSegIdx() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRxBufStruct_ReleaseSegment()
 **********************************************************************************************************************/
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
TCPIP_LOCAL_INLINE FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRxBufStruct_ReleaseSegment(
  TcpIp_SizeOfTlsBufferMgmtType TlsBufferMgmtIdx,
  uint32 Len)
{
  /* ----- Local Variables ---------------------------------------------- */
  TCPIP_P2V(uint8)                             bufSegPtr;
  uint32                                       localLen = Len;
  TcpIp_RxBufStructSegIterType                 bufSegIter;
  /* Optional indirection: Refer to parameter value range in function description. */
  TcpIp_SizeOfRxBufStructMgtType               rxBufStructMgtIdx = TcpIp_GetRxBufStructMgtIdxOfTlsBufferMgmt(TlsBufferMgmtIdx);
  TcpIp_RxBufStructSegLvlOfRxBufStructMgtType  bufSegLvl = TcpIp_GetRxBufStructSegLvlOfRxBufStructMgt(rxBufStructMgtIdx);
  TcpIp_SizeOfRxBufStructSegType               rxBufStructSegIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all segments. */
  for (bufSegIter = 0u; bufSegIter < bufSegLvl; bufSegIter++)
  {
    rxBufStructSegIdx = TcpIp_GetRxBufStructSegIdxOfRxBufStructMgt(rxBufStructMgtIdx);

    if (rxBufStructSegIdx < TcpIp_GetSizeOfRxBufStructSeg())
    {
      bufSegPtr = TcpIp_GetDataPtrOfRxBufStructSeg(rxBufStructSegIdx);

      /* #20 Release in current segment and stop iteration if segment length is bigger than length to be released. */
      if (localLen < TcpIp_GetLenOfRxBufStructSeg(rxBufStructSegIdx))
      {
        TcpIp_TlsCoreRxBufStruct_WriteRxBufSegment(rxBufStructSegIdx, &bufSegPtr[localLen],
          (TcpIp_LenOfRxBufStructSegType)(TcpIp_GetLenOfRxBufStructSeg(rxBufStructSegIdx) - localLen));

        break;
      }
      /* #30 Release segment completely otherwise. */
      else
      {
        /* #40 Reset segment length and decrement length to be released. */
        localLen -= TcpIp_GetLenOfRxBufStructSeg(rxBufStructSegIdx);
        TcpIp_SetLenOfRxBufStructSeg(rxBufStructSegIdx, 0u);
        TcpIp_DecRxBufStructSegLvlOfRxBufStructMgt(rxBufStructMgtIdx);

        /* #50 Calculate next segment index considering buffer struct wrap around. */
        if ((rxBufStructSegIdx + 1u) == TcpIp_GetRxBufStructSegEndIdxOfTlsBufferMgmt(TlsBufferMgmtIdx))
        {
          TcpIp_SetRxBufStructSegIdxOfRxBufStructMgt(rxBufStructMgtIdx, TcpIp_GetRxBufStructSegStartIdxOfTlsBufferMgmt(
                                                                        TlsBufferMgmtIdx));
        }
        else
        {
          TcpIp_SetRxBufStructSegIdxOfRxBufStructMgt(rxBufStructMgtIdx, (TcpIp_RxBufStructSegIdxOfRxBufStructMgtType)
            (TcpIp_GetRxBufStructSegIdxOfRxBufStructMgt(rxBufStructMgtIdx) + 1u));
        }
      }
    }
    else
    {
      /* Memory runtime check fails - report DET */
      TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
    }
  }
} /* TcpIp_TlsCoreRxBufStruct_ReleaseSegment() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRxBufStruct_WriteSegment()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL_INLINE FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRxBufStruct_WriteSegment(
  TcpIp_SizeOfTlsBufferMgmtType TlsBufferMgmtIdx,
  TCPIP_P2V(uint8) SrcBufPtr,
  uint16 SrcBufLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* Optional indirection: Refer to parameter value range in function description. */
  TcpIp_SizeOfRxBufStructMgtType rxBufStructMgtIdx = TcpIp_GetRxBufStructMgtIdxOfTlsBufferMgmt(TlsBufferMgmtIdx);
  TcpIp_SizeOfRxBufStructSegType rxBufStructSegIdx = TcpIp_GetRxBufStructSegIdxOfRxBufStructMgt(rxBufStructMgtIdx);
  Std_ReturnType                 retVal;

  /* ----- Implementation ----------------------------------------------- */
  if (rxBufStructSegIdx < TcpIp_GetSizeOfRxBufStructSeg())
  {
    /* #10 Check if new data is available. */
    if (SrcBufLen > 0u)
    {
      /* #20 Write first buffer struct segment if struct is empty. */
      if (TcpIp_GetRxBufStructSegLvlOfRxBufStructMgt(rxBufStructMgtIdx) == 0u)
      {
        TcpIp_TlsCoreRxBufStruct_WriteRxBufSegment(rxBufStructSegIdx, SrcBufPtr, SrcBufLen);
        TcpIp_IncRxBufStructSegLvlOfRxBufStructMgt(rxBufStructMgtIdx);

        retVal = E_OK;
      }
      /* #30 Write additional segment otherwise. */
      else
      {
        retVal = TcpIp_TlsCoreRxBufStruct_WriteAdditionalSegment(TlsBufferMgmtIdx, SrcBufPtr, SrcBufLen);
      }
    }
    /* #40 Succeed call without any further action otherwise. */
    else
    {
      retVal = E_OK;
    }
  }
  else
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);

    retVal = E_NOT_OK;
  }

  return retVal;
} /* TcpIp_TlsCoreRxBufStruct_WriteSegment() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRxBufStruct_WriteAdditionalSegment()
 **********************************************************************************************************************/
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
/* PRQA S 6050, 6080 1 */ /* MD_TcpIp_STCAL_CslAccess, MD_TcpIp_TlsRuntimecheck_STMIF_6080 */
TCPIP_LOCAL_INLINE FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRxBufStruct_WriteAdditionalSegment(
  TcpIp_SizeOfTlsBufferMgmtType TlsBufferMgmtIdx,
  TCPIP_P2V(uint8) SrcBufPtr,
  uint16 SrcBufLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  TCPIP_P2C(uint8)                             bufSegPtr;
  /* Optional indirection: Refer to parameter value range in function description. */
  TcpIp_SizeOfRxBufStructMgtType               rxBufStructMgtIdx = TcpIp_GetRxBufStructMgtIdxOfTlsBufferMgmt(TlsBufferMgmtIdx);
  TcpIp_SizeOfRxBufStructSegType               lastRxBufStructSegIdx;
  TcpIp_SizeOfRxBufStructSegType               writeRxBufStructSegIdx;
  TcpIp_RxBufStructSegLvlOfRxBufStructMgtType  lastLvl;
  Std_ReturnType                               retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Calculate index of last segment. */
  lastLvl = (TcpIp_RxBufStructSegLvlOfRxBufStructMgtType)(TcpIp_GetRxBufStructSegLvlOfRxBufStructMgt(rxBufStructMgtIdx) - 1u);

  lastRxBufStructSegIdx = TcpIp_TlsCoreRxBufStruct_CalculateNextSegment(
    TlsBufferMgmtIdx, TcpIp_GetRxBufStructSegIdxOfRxBufStructMgt(rxBufStructMgtIdx), lastLvl);

  if (lastRxBufStructSegIdx < TcpIp_GetSizeOfRxBufStructSeg())
  {
    bufSegPtr = TcpIp_GetDataPtrOfRxBufStructSeg(lastRxBufStructSegIdx);

    /* #20 Ignore adding segment if function is called with last segment (used to continue reception in main context). */
    if (&SrcBufPtr[0] == &bufSegPtr[0u])
    {
      retVal = E_OK;
    }
    /* #30 Check if new segment is in same memory segment like last segment otherwise. */
    else if (&SrcBufPtr[0] == &bufSegPtr[TcpIp_GetLenOfRxBufStructSeg(lastRxBufStructSegIdx)])
    {
      /* #40 Update length of last segment. */
      TcpIp_SetLenOfRxBufStructSeg(lastRxBufStructSegIdx, TcpIp_GetLenOfRxBufStructSeg(lastRxBufStructSegIdx) + SrcBufLen);

      retVal = E_OK;
    }
    /* #50 Check if struct size is sufficient for new segment otherwise. */

    else if (TCPIP_RX_BUF_SEG_SIZE_TOTAL > TcpIp_GetRxBufStructSegLvlOfRxBufStructMgt(rxBufStructMgtIdx))
    {
     /* #60 Get next segment. */
     writeRxBufStructSegIdx = TcpIp_TlsCoreRxBufStruct_CalculateNextSegment(TlsBufferMgmtIdx,
       TcpIp_GetRxBufStructSegIdxOfRxBufStructMgt(rxBufStructMgtIdx),
       TcpIp_GetRxBufStructSegLvlOfRxBufStructMgt(rxBufStructMgtIdx));

      if (writeRxBufStructSegIdx < TcpIp_GetSizeOfRxBufStructSeg())
      {
        /* #70 Write new segment. */
        TcpIp_TlsCoreRxBufStruct_WriteRxBufSegment(writeRxBufStructSegIdx, SrcBufPtr, SrcBufLen);
        TcpIp_IncRxBufStructSegLvlOfRxBufStructMgt(rxBufStructMgtIdx);

        retVal = E_OK;
      }
      else
      {
        /* Memory runtime check fails - report DET */
        TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
        retVal = E_NOT_OK;
      }
    }
    /* #80 Reject request otherwise. */
    else
    {
      retVal = E_NOT_OK;
    }
  }
  else
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
    retVal = E_NOT_OK;
  }

  return retVal;
} /* TcpIp_TlsCoreRxBufStruct_WriteAdditionalSegment() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRxBufStruct_CalculateNextSegment()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL_INLINE FUNC(TcpIp_SizeOfRxBufStructSegType, TCPIP_CODE) TcpIp_TlsCoreRxBufStruct_CalculateNextSegment(
  TcpIp_SizeOfTlsBufferMgmtType TlsBufferMgmtIdx,
  TcpIp_SizeOfRxBufStructSegType SegmentIndex,
  TcpIp_RxBufStructSegLvlOfRxBufStructMgtType SegmentLvl)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfRxBufStructSegType NextSegmentIndex;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Calculate next segment index if struct wraps around. */
  if ((SegmentIndex + SegmentLvl) >= TcpIp_GetRxBufStructSegEndIdxOfTlsBufferMgmt(TlsBufferMgmtIdx))
  {
    NextSegmentIndex = (TcpIp_SizeOfRxBufStructSegType)(TcpIp_GetRxBufStructSegStartIdxOfTlsBufferMgmt(TlsBufferMgmtIdx) +
      (SegmentLvl - (TcpIp_GetRxBufStructSegEndIdxOfTlsBufferMgmt(TlsBufferMgmtIdx) - SegmentIndex)));
  }
  /* #20 Calculate next segment index if struct does not wrap around otherwise. */
  else
  {
    NextSegmentIndex = (TcpIp_SizeOfRxBufStructSegType)(SegmentIndex + SegmentLvl);
  }

  return NextSegmentIndex;
} /* TcpIp_TlsCoreRxBufStruct_CalculateNextSegment() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreBuffer_GetAvailableTxBufferSize
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
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreBuffer_GetAvailableTxBufferSize(
  TcpIp_SocketDynIterType SocketIdx,
  TCPIP_P2V(uint32) AvailableTxBufferSizePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsConnectionIterType tlsConIdx = TcpIp_GetSizeOfTlsConnection();
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if there is a valid TLS connection for this socket. */
  if ((TcpIp_SocketIdxToTlsConIdx(SocketIdx, &tlsConIdx) == E_OK) && (tlsConIdx < TcpIp_GetSizeOfTlsConnection()))
  {
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
    TcpIp_TlsListenerIterType tlsListenerIdx;
    boolean isTlsListenSocket = FALSE;

    /* #20 Check if a listener is assigned to this socket. */
    /* Iterate over all configured TLS-Listeners */
    for (tlsListenerIdx = 0; tlsListenerIdx < TcpIp_GetSizeOfTlsListener(); tlsListenerIdx++)
    {
      /* Check if this TLS-Listener entry is free and return the index */
      if (TcpIp_GetSocketDynIdxOfTlsListener(tlsListenerIdx) == SocketIdx)
      {
        /* The socket is used as a listener, so there are no buffers assigned to this socket. */
        isTlsListenSocket = TRUE;
        break;
      }
    }

    if (isTlsListenSocket == TRUE)
    {
      /* #30 If the socket is a listen socket, no tx buffer is available. */
      *AvailableTxBufferSizePtr = 0u;
    }
    else
# endif
    {
      /* #40 If the socket is a client socket or a socket derived from a listen socket, read the available buffer size. */
      TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx;
      TcpIp_SizeOfTlsBufferTxType   remainingSpaceInAdHsBuffer;  /* Remaining space available in TLS Tx AdHs buffer */

      tlsBufferMgmtIdx           = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(tlsConIdx);
      remainingSpaceInAdHsBuffer = (TcpIp_GetTlsBufferTxAdHsLengthOfTlsBufferMgmt(tlsBufferMgmtIdx)
                                   - TcpIp_GetAdTxFillLevelOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      /* #50 If there is no inner content type byte set, reduce the available buffer by one to reserve the byte. */
      if (   (TcpIp_GetActiveVersionOfTlsConnectionDyn(tlsConIdx) == TCPIP_TLSVERSION_13)
          && (TcpIp_IsTxInnerContentTypeAddedOfTlsBufferMgmtDyn(tlsBufferMgmtIdx) == FALSE)
          && (remainingSpaceInAdHsBuffer > 0u))
      {
        remainingSpaceInAdHsBuffer--;
      }
# endif

      *AvailableTxBufferSizePtr = (uint32)remainingSpaceInAdHsBuffer;
    }

    retVal = E_OK;
  }
  else
  {
    /* There is no TLS connection for this socket. */
    retVal = E_NOT_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TLS CORE MAIN FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreMainFunction_Rx
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
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_Rx(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsConnectionIterType tlsConIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all configured TLS connections reception of TLS protocol */
# if (defined __VCA__ && defined __SMOKETEST_VCA__)                                                                     /* COV_TCPIP_VCA_SMOKETEST */
  tlsConIdx = TCPIP_TLS_CONNECTION_COUNT - 1;
# else
#  if defined __VCA__                                                                                                   /* COV_TCPIP_VCA_EXCLUDE */
#   pragma unroll TCPIP_TLS_CONNECTION_COUNT
#  endif
  for (tlsConIdx = 0; tlsConIdx < TcpIp_GetSizeOfTlsConnection(); tlsConIdx++)
# endif
  {
    /* #20 Handles reception of record layer */
    TcpIp_TlsCoreMainFunction_RxRl(tlsConIdx);

    /* #30 Check if the TLS connection is not in state inactive */
    if (TcpIp_GetConnectionStateOfTlsConnectionDyn(tlsConIdx) != TCPIP_TLS_STATE_CONNECTION_HS_INACTIVE)
    {
      /* #40 Handles reception of change cipher spec */
      TcpIp_TlsCoreMainFunction_RxCcs(tlsConIdx);


      /* #50 Handles reception of handshake */
      TcpIp_TlsCoreMainFunction_RxHs(tlsConIdx);


      /* #60 Handles reception of alerts */
      TcpIp_TlsCoreMainFunction_RxAl(tlsConIdx);

      /* #70 Handles confirmation of application data */
      /* The confirmations shall be handled before the reception of application data is handled, because after
         that step, may more Rx buffer is available. */
      TcpIp_TlsCoreUl_RxConfirmedAdDataHandler(tlsConIdx);

      /* #80 Handles reception of application data */
      TcpIp_TlsCoreMainFunction_RxAd(tlsConIdx);
    }
  }
} /* TcpIp_TlsCoreMainFunction_Rx() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMainFunction_State
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
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_State(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsConnectionIterType tlsConIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all configured TLS connections and handle TLS substates */

# if (defined __VCA__ && defined __SMOKETEST_VCA__)
  tlsConIdx = TCPIP_TLS_CONNECTION_COUNT - 1;
# else
#  if defined __VCA__
#   pragma unroll TCPIP_TLS_CONNECTION_COUNT
#  endif
  for (tlsConIdx = 0; tlsConIdx < TcpIp_GetSizeOfTlsConnection(); tlsConIdx++)
# endif
  {
    /* #20 Handle User events */
    TcpIp_TlsCoreState_UserEventHandler(tlsConIdx);

    /* #30 Handle TCP events */
    TcpIp_TlsCoreState_TcpEventHandler(tlsConIdx);

    /* #40 Handle TLS Handshake related states */
    TcpIp_TlsCoreState_HandshakeHandler(tlsConIdx);

    /* #50 Handle TLS User error related states */
    TcpIp_TlsCoreState_UserErrorHandler(tlsConIdx);

    /* #60 Handle TLS Alert related states */
    TcpIp_TlsCoreState_AlertHandler(tlsConIdx);

    /* #70 Handle TLS Application data states */
    TcpIp_TlsCoreState_ApplicationDataHandler(tlsConIdx);

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    /* #80 Handle TLS Connection related states */
    TcpIp_TlsCoreState_ConnectionHandler(tlsConIdx);
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
  }
} /* TcpIp_TlsCoreMainFunction_State() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMainFunction_Tx
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
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_Tx(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsConnectionIterType tlsConIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all configured TLS-Connections and handle transmission of TLS protocol */
# if (defined __VCA__ && defined __SMOKETEST_VCA__)
    tlsConIdx = TCPIP_TLS_CONNECTION_COUNT - 1;
# else
#  if defined __VCA__
#   pragma unroll TCPIP_TLS_CONNECTION_COUNT
#  endif
  for (tlsConIdx = 0; tlsConIdx < TcpIp_GetSizeOfTlsConnection(); tlsConIdx++)
# endif
  {
    /* #20 Check if the TLS connection is not in state inactive */
    if (TcpIp_GetConnectionStateOfTlsConnectionDyn(tlsConIdx) != TCPIP_TLS_STATE_CONNECTION_HS_INACTIVE)
    {
      if (TCPIP_SOCKET_IDX_TO_TCP_IDX(TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(tlsConIdx)) < TcpIp_GetSizeOfSocketTcpDyn())
      {
        /* #30 Handles transmission of alert frames */
        TcpIp_TlsCoreMainFunction_TxAl(tlsConIdx);

        /* #40 Handles transmission of handshake frames */
        TcpIp_TlsCoreMainFunction_TxHs(tlsConIdx);

        /* #50 Handles transmission of application data frames */
        TcpIp_TlsCoreMainFunction_TxAd(tlsConIdx);

        /* #60 Handles transmission of ChangeCipherSpec frames */
        TcpIp_TlsCoreMainFunction_TxCcs(tlsConIdx);

# if (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON)
        /* #70 Handles transmission of NSS Key Log frames */
        TcpIp_TlsCoreMainFunction_TxNss(tlsConIdx);
# endif
      }
    }
  }
} /* TcpIp_TlsCoreMainFunction_Tx() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMainFunction_LowPrio
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_LowPrio(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsConnectionIterType tlsConIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all configured TLS connections and handle low prio context */
# if (defined __VCA__ && defined __SMOKETEST_VCA__)
    tlsConIdx = TCPIP_TLS_CONNECTION_COUNT - 1;
# else
#  if defined __VCA__
#   pragma unroll TCPIP_TLS_CONNECTION_COUNT
#  endif
  for (tlsConIdx = 0; tlsConIdx < TcpIp_GetSizeOfTlsConnection(); tlsConIdx++)
# endif
  {
    /* Invoke Core async context handler */
    TcpIp_TlsCoreCtx_AsyncHandler(tlsConIdx);

# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
    if (TcpIp_GetModeOfTlsConnection(tlsConIdx) == TCPIP_TLS_SERVER)
#  endif
    {
      /* Mode == TCPIP_TLS_SERVER */
      /* Invoke Server async context handler */
      TcpIp_TlsServerCtx_AsyncHandler(tlsConIdx);
    }
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
    else
#  endif
# endif
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
    {
      /* Mode == TCPIP_TLS_CLIENT */
      /* Invoke Client async context handler */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      if (TcpIp_GetActiveVersionOfTlsConnectionDyn(tlsConIdx) == TCPIP_TLSVERSION_12)
#   endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
      {
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
        /* TLS 1.2 */
        TcpIp_Tls12ClientCtx_AsyncHandler(tlsConIdx);
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      }
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      else
#   endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
      {
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
        /* TLS 1.3 */
        TcpIp_Tls13ClientCtx_AsyncHandler(tlsConIdx);
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
      }
    }
# endif
  }
} /* TcpIp_TlsCoreMainFunction_LowPrio() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtx_AsyncHandler
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6010, 6030, 6050 1 */ /* MD_TcpIp_TlsStatemachine_STPTH_6010, MD_TcpIp_TlsStatemachine_STCYC_6030, MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtx_AsyncHandler(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Invoke async handlers if trigger flag has been set. */
# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
  /* If triggered, calculate Diffie-Hellman public key and reset the flag */
  if (TcpIp_IsDhPubKeyKeyExchangeAsyncFlagOfTlsConnectionDyn(TlsConIdx) == TRUE)
  {
    TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx =
      TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));
    TcpIp_TlsCoreCtx_CalcDiffieHellmanPublicKey(TlsConIdx, activeTlsHandshakeIdx);
    TcpIp_SetDhPubKeyKeyExchangeAsyncFlagOfTlsConnectionDyn(TlsConIdx, FALSE);
  }

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  if (TcpIp_GetDhPubKeyKeyShareExtCurveAsyncTriggerOfTlsConnectionDyn(TlsConIdx) != TCPIP_CURVE_ID_NO_CURVE)
  {
    TcpIp_Tls13ClientCtx_AddPubKeyToKeyShareExtension(TlsConIdx);
  }
#   endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */


#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  /* If triggered, calculate the PSK value and the binder for the TLS 1.3 session resumption. */
  if (TcpIp_IsCalcPskValueAsyncFlagOfTlsConnectionDyn(TlsConIdx) == TRUE)
  {
    TcpIp_Tls13ClientCtx_CalcPskValueAndBinder(TlsConIdx);
  }
#   endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */


  /* If triggered, calculate Diffie-Hellman shared secret and reset the flag */
  if (TcpIp_IsDhSharedSecretAsyncFlagOfTlsConnectionDyn(TlsConIdx) == TRUE)
  {
    /* Calculate the DH shared secret if the precondition is fulfilled */
    if (TcpIp_TlsCoreCtx_CheckCalcDhSharedSecretPrecondition(TlsConIdx) == TRUE)                                        /* PRQA S 2991, 2995 */ /* MD_TCPIP_Rule14.3_2741_2742_2991_2992_2995_2996 */
    {
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
      {
#   endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
        TcpIp_Tls13CoreCtx_CalcDhSharedSecret(TlsConIdx);
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      }
      else
#   endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      {
        TcpIp_Tls12CoreCtx_CalcDhSharedSecret(TlsConIdx);
      }
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
      TcpIp_SetDhSharedSecretAsyncFlagOfTlsConnectionDyn(TlsConIdx, FALSE);
    }
    /* else - wait for next cycle */
  }

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  if (TcpIp_IsCalcHsTrafficKeysAsyncFlagOfTlsConnectionDyn(TlsConIdx) == TRUE)
  {
    /* DhSharedSecret and CalcHsTrafficKeys flags are set at same time.
     * But Hs traffic keys can only be calculated when Dh shared secret calculation is done. */
    if (TcpIp_IsDhSharedSecretAsyncFlagOfTlsConnectionDyn(TlsConIdx) == FALSE)
    {
      /* Calculate and immediately switch to the handshake keys.
       * The return value can not be processed here. */
      (void) TcpIp_Tls13CoreCtx_SwitchToHandshakeKeys(TlsConIdx);
    }
    /* else - Dh shared secret has to be calculated first, wait for next cycle */
  }
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */

# endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

# if ((TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON) || (TCPIP_SUPPORT_ASRTLSCLIENT_PSK == STD_ON))
  /* If triggered, calculate premaster secret using PSK and reset the flag */
  if (TcpIp_IsPskPremasterSecretAsyncFlagOfTlsConnectionDyn(TlsConIdx) == TRUE)
  {
    TcpIp_Tls12CoreCtx_CalcPskPremasterSecret(TlsConIdx);
    TcpIp_SetPskPremasterSecretAsyncFlagOfTlsConnectionDyn(TlsConIdx, FALSE);
  }
# endif /* (TCPIP_SUPPORT_ASRTLSSERVER_PSK == STD_ON) || (TCPIP_SUPPORT_ASRTLSCLIENT_PSK == STD_ON) */

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  if (TcpIp_IsCalcApplTrafficKeysAsyncFlagOfTlsConnectionDyn(TlsConIdx) == TRUE)
  {
    /* Calculate application keys but only switch the decrypt key for now.
     * The return value can not be processed here */
    (void)TcpIp_Tls13CoreCtx_SwitchToApplicationKeyRx(TlsConIdx);
  }

  /* If triggered, calculate the session resumption secret. */
  if (TcpIp_IsCalcResumptionMasterSecretAsyncFlagOfTlsConnectionDyn(TlsConIdx) == TRUE)
  {
    TcpIp_Tls13CoreCtx_DeriveResumptionMasterSecret(TlsConIdx);

    /* Resumption master secret - reset context state */
    TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);
    TcpIp_SetCalcResumptionMasterSecretAsyncFlagOfTlsConnectionDyn(TlsConIdx, FALSE);
  }

# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  /* If triggered, calculate the Master Secret and reset the flag */
  if (TcpIp_IsCalcMasterSecretAsyncFlagOfTlsConnectionDyn(TlsConIdx) == TRUE)
  {
    TcpIp_Tls12CoreCtx_CalcMasterSecret(TlsConIdx);
    TcpIp_SetCalcMasterSecretAsyncFlagOfTlsConnectionDyn(TlsConIdx, FALSE);
  }
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
} /* TcpIp_TlsCoreCtx_AsyncHandler() */

/**********************************************************************************************************************
 *  TLS CORE MAIN FUNCTION RX
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreMainFunction_RxRl
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_RxRl(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  uint32 totDataLen;  /* Stores the length information over all received data stored in RxBufStruct */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check that we are in the correct state to process the RL frame */
  if (   (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_CONNECTION_CLOSING)
      && (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_ASYNC_PENDING)                         /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
      /* Only process record layer frame if decryption is not blocked */
      && (TcpIp_IsBlockDecryptOperationsUntilKeysAreCalculatedOfTlsConnectionDyn(TlsConIdx) == FALSE))
  {
    totDataLen = TcpIp_TlsCoreRxBufStruct_GetTotLen(tlsBufferMgmtIdx, 0u);

    if (totDataLen != 0u)
    {
      /* #20 Check the received RL header (or header part) if it is valid */
      /* This function peeks the received bytes of the RL header and sets the AlertDescription if it is not valid. */
      /* If we do not received the complete RL header so far, this function simply returns E_OK and we wait until the next cycle */
      if (TcpIp_TlsCoreRl_ValidateAndProcessFrame(TlsConIdx, totDataLen) != E_OK)
      {
        TcpIp_TlsCoreRl_HandleInvalidRlFrame(TlsConIdx, (uint16)totDataLen);
      }
    }
  }
} /* TcpIp_TlsCoreMainFunction_RxRl() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMainFunction_RxHs
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_RxHs(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Process Rx HS function only if the current connection is in an active HS state */
  if ((TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx)) == (TCPIP_TLS_STATE_CONNECTION_HS_ACTIVE))
  {
    /* #20 Check if there is an async operation pending */
    if (   (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CTX_ASYNC_PENDING)
        /* [HS Server Certificate Chain Handling StM] Only handle reception if certificate processing is not in progress */
        && (TcpIp_GetHsCertStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_CERTCHAIN_IN_PROGRESS))                      /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
    {
      /* #30 Check if we received at least one record layer frame or the last frame is not completely parsed */
      if (TcpIp_IsRlRxIndicationFlagOfTlsConnectionDyn(TlsConIdx) == TRUE)
      {
        /* All conditions are valid, we can now try to process the message */
        TcpIp_TlsCoreCtHs_ProcessMsg(TlsConIdx);
      } /* else - no record layer frame received - nothing to do */
    } /* else - async operation pending - nothing to do */
  } /* else - no handshake active on this connection - nothing to do */

} /* TcpIp_TlsCoreMainFunction_RxHs() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMainFunction_RxAl
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_RxAl(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Process Rx AL function if the current connection is established, in an active HS state or in state close_wait */
  /* Close_wait is necessary to still process alerts when a FIN flag was set in the received TCP segment.
   * In case of TLS 1.3, CLOSENOTIFY states are necessary to still process alerts after
     sending or receiving a CloseNotify alert. */
  if (  (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_HS_ACTIVE)                 /* PRQA S 3415 5 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
     || (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_ESTABLISHED)
     || (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_CLOSE_WAIT)
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
     || (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_13_CLOSENOTIFY_SENT)
     || (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_13_CLOSENOTIFY_RECEIVED)
# endif
     )
  {
    if ((TcpIp_IsRlRxIndicationFlagOfTlsConnectionDyn(TlsConIdx) == TRUE))
    {
      /* #20 Check if we can forward the alert to the upper layer */
      if (TcpIp_TlsCoreCtAl_CheckLengthAndForwardAlertToAlHandler(TlsConIdx) == E_OK)
      {
        /* #30 if so, we forward this message to the AL handler so reset the RL RxIndication flag */
        TcpIp_SetRlRxIndicationFlagOfTlsConnectionDyn(TlsConIdx, FALSE);
      }
      else
      {
        /* #40 otherwise, no alert message received  - do nothing */
      }
    }
  }
} /* TcpIp_TlsCoreMainFunction_RxAl() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMainFunction_RxAd
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_RxAd(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  TcpIp_TlsConnectionState state = TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx);
  /* #10 Check if the connection is established (Handshake done) or in case of TLS 1.3 a CloseNotify was sent  or connection state is close_wait */
  /* When the FIN flag was set in the received TCP segment the connection state is close_wait.
   * In this state received application data must be forwarded to the upper layer still
   * and therefore must be processed here.
   * The same holds for the connection state if a TcpIp_Close is triggered (Abort=True or Abort=False).
   * Additionally, the handshake must not have failed to indicate new application data. */
  if (   (   (state == TCPIP_TLS_STATE_CONNECTION_ESTABLISHED)
          || (state == TCPIP_TLS_STATE_CONNECTION_CLOSE_WAIT)
          || (state == TCPIP_TLS_STATE_CONNECTION_USER_RESET_REQUESTED)
          || (state == TCPIP_TLS_STATE_CONNECTION_CLOSE_WITH_CLOSENOTIFY_FIN_REQUESTED)
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
          || (state == TCPIP_TLS_STATE_CONNECTION_13_CLOSENOTIFY_SENT)
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
         )                                                                                                              /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
      && (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_HANDSHAKE_ABORT)
      && (TcpIp_IsRlRxIndicationFlagOfTlsConnectionDyn(TlsConIdx) == TRUE))
  {
    /* #20 if so, forward the data to the upper layer */
    if (TcpIp_TlsCoreCtAd_ForwardDataToAdHandler(TlsConIdx) == E_OK)
    {
      /* #30 We processed this messaged so reset the RL RxIndication flag */
      TcpIp_SetRlRxIndicationFlagOfTlsConnectionDyn(TlsConIdx, FALSE);
    }
    else
    {
      /* otherwise - no AD data received - do nothing */
    }
  }
} /* TcpIp_TlsCoreMainFunction_RxAd() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMainFunction_RxCcs
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_RxCcs(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check that we are in the correct state to receive the CCS message */
  if ((TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx)) == (TCPIP_TLS_STATE_CONNECTION_HS_ACTIVE))
  {
    if ((TcpIp_IsRlRxIndicationFlagOfTlsConnectionDyn(TlsConIdx) == TRUE))
    {
      /* #20 If so, check if a CCS was received */
      if (TcpIp_GetLastReceivedContentTypeOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CT_CCS)
      {
        /* #30 If so, check if we can forward the CCS message to the upper layer */
        if (TcpIp_TlsCoreCtCcs_CheckReceivedCcsData(TlsConIdx) == E_OK)
        {
          TcpIp_SetCcsReceivedOfTlsConnectionDyn(TlsConIdx, TRUE);
          /* #40 If so, we processed this messaged so reset the RL RxIndication flag */
          TcpIp_TlsCore_ResetRlRxIndicationFlag(TlsConIdx, TCPIP_TLS_CT_CCS);
        }
      }
    }
  }
} /* TcpIp_TlsCoreMainFunction_RxCcs() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUl_RxConfirmedAdDataHandler
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreUl_RxConfirmedAdDataHandler(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  uint32 dataLenByte = 0u;

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_VENTER_CRITICAL_SECTION();
  dataLenByte = TcpIp_GetRxUpperlayerReleasedDataLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  /* #10 Verify if any new data was confirmed since the last main function */
  if (dataLenByte != 0u)
  {
    TcpIp_SizeOfTlsBufferRxType rxFillLvl = TcpIp_GetAdRxFillLevelOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
    TcpIp_SetRxUpperlayerReleasedDataLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, 0);

    /* If the upper layer reads more data than available, just consume all the available data. */
    dataLenByte = TCPIP_MIN(dataLenByte, rxFillLvl);

    /* #20 Decrement the Rx AdHs fill level since data has been consumed */
    TcpIp_SubAdRxFillLevelOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, (TcpIp_SizeOfTlsBufferRxType)dataLenByte);

    /* When the FIN flag was set in the received TCP segment the connection state is close_wait.
     * In this state application data is still forwarded to the upper layer. */
    /* #30 Update the index, which maintain the confirmed upper layer read data */
    /* Plaintext in the TLS Rx AdHs buffer has been read by UL, readIdx can be incremented with bytes consumed */
    TcpIp_TlsCoreRl_IncrementRxAdHsReadIdxWithWraparound(TlsConIdx, dataLenByte);

# if ( TCPIP_DEV_ERROR_DETECT == STD_ON )
    /* Store the current Rx indices and perform some basic range checks */
    TcpIp_TlsCoreRl_RxBufferIdxValidityCheck(TlsConIdx, TCPIP_TLS_CALL_POS_CONFIRM, TCPIP_TLS_CT_AD);
# endif
  }
  /* Else: No data was consumed by the Ul since the last main function */

  TCPIP_VLEAVE_CRITICAL_SECTION();

} /* TcpIp_TlsCoreUl_RxConfirmedAdDataHandler() */

/**********************************************************************************************************************
 *  TcpIp_TlsCore_ResetRlRxIndicationFlag
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsCore_ResetRlRxIndicationFlag(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC)     TriggerContentType)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDynType rxAdHsWriteIdx
    = TcpIp_GetTlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_TlsBufferRxAdHsReadIdxOfTlsBufferMgmtDynType rxAdHsReadIdx
    = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  TcpIp_TlsBufferRxAlWriteIdxOfTlsBufferMgmtDynType rxAlWriteIdx
    = TcpIp_GetTlsBufferRxAlWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_TlsBufferRxAlReadIdxOfTlsBufferMgmtDynType rxAlReadIdx
    = TcpIp_GetTlsBufferRxAlReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  TcpIp_TlsBufferRxCcsWriteIdxOfTlsBufferMgmtDynType rxCcsWriteIdx
    = TcpIp_GetTlsBufferRxCcsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  TcpIp_TlsBufferRxCcsReadIdxOfTlsBufferMgmtDynType rxCcsReadIdx
    = TcpIp_GetTlsBufferRxCcsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  boolean resetRlRxIndicationFlag = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  boolean allAlMessagesProcessed = (rxAlWriteIdx == rxAlReadIdx);
  boolean allCcsMessagesProcessed = (rxCcsWriteIdx == rxCcsReadIdx);
  boolean allAdHsMessagesProcessed = (rxAdHsWriteIdx == rxAdHsReadIdx);

  /* The RL indication trigger is relevant for AdHs, Ccs and Al messages,
   * do not reset it when another content type still needs to be processed. */
  switch (TriggerContentType)
  {
    case TCPIP_TLS_CT_AD:
    case TCPIP_TLS_CT_HS:
    {
      resetRlRxIndicationFlag = allAlMessagesProcessed && allCcsMessagesProcessed;
      break;
    }
    case TCPIP_TLS_CT_AL:
    {
      resetRlRxIndicationFlag = allAdHsMessagesProcessed && allCcsMessagesProcessed;
      break;
    }
    case TCPIP_TLS_CT_CCS:
    {
      resetRlRxIndicationFlag = allAdHsMessagesProcessed && allAlMessagesProcessed;
      break;
    }
    default:
    {
      /* Left blank intentionally. */
      break;
    }
  }

  /* #10 Check if all record with other content types are processed. */
  if (resetRlRxIndicationFlag == TRUE)
  {
    /* #20 If so, reset the RlRx indication trigger. */
    TcpIp_SetRlRxIndicationFlagOfTlsConnectionDyn(TlsConIdx, FALSE);
  } /* else: valid case, just wait for all records to be processed before reseting the flag */
} /* TcpIp_TlsCore_ResetRlRxIndicationFlag() */

/**********************************************************************************************************************
 *  TcpIp_TlsAsyncCtx_HandleErrorDuringAsyncJobProcessing
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsAsyncCtx_HandleErrorDuringAsyncJobProcessing(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16 FunctionId,
  uint16 ErrorId)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsAlertLevelType alertLevel;
  TcpIp_TlsAlertDescriptionType alertDescription;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Report the error to the user, if set */
  if (ErrorId != TCPIP_TLS_ERRORID_NOT_SET)
  {
    TcpIp_TlsUserErrorType userError;

    userError.FunctionId = FunctionId;
    userError.UserErrorId = ErrorId;
    userError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(userError);
  }

  /* #20 Set the corresponding alert level and description */
  alertLevel = TCPIP_TLS_ALERT_LEVEL_FATAL;
  alertDescription = TCPIP_TLS_ALERT_DESC_INT_ERROR;

  /* #30 Trigger the transmission of the occurred alert */
  TcpIp_TlsCoreAlert_Set(TlsConIdx, alertLevel, alertDescription);

  /* #40 Change the state to HANDSHAKE_ABORT */
  TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_ABORT);

  TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);

} /* TcpIp_TlsAsyncCtx_HandleErrorDuringAsyncJobProcessing() */

# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreMsg_CertMsgSetCertificatesInGroup
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreMsg_CertMsgSetCertificatesInGroup(
  TcpIp_TlsConnectionIterType         TlsConIdx,
  TcpIp_TlsBufferRxIterType           CertStartIdx,
  uint8                               NumCerts)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsBufferRxIterType certReadTlsBufferRxIdx = CertStartIdx;
  Std_ReturnType retVal = E_NOT_OK;
  uint8 certIter = 0;
  TcpIp_TlsCertValidationStatusDynStartIdxOfTlsConnectionType tlsCertValidationStatusIdx
    = TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx);

  /* TcpIp_TlsCoreUtil_CheckEccKeyMConfiguration() was invoked before which ensures that in client case there is only
   * one remote certificate and in server case each remote certificate has the same cert group Id.
   * Therefore we can just take the group Id of the start remote certificate. */
  TcpIp_CertificateGroupIdType groupId
    = TcpIp_GetCertGroupIdOfTlsRemoteKeyMCertInfo(TcpIp_GetTlsRemoteKeyMCertInfoStartIdxOfTlsConnection(TlsConIdx));

  /* ----- Implementation ---------------------------------------------- */
  TCPIP_ASSERT(NumCerts <= (TcpIp_GetTlsCertValidationStatusDynEndIdxOfTlsConnection(TlsConIdx) - TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx)));

  /* #10 Iterate through all the certificates in the received chain */
  for (certIter = 0; certIter < NumCerts; certIter++)
  {
    uint32                   certLength = IpBase_GetUint24(TcpIp_GetAddrTlsBufferRx(certReadTlsBufferRxIdx), 0);
    TcpIp_CertDataType       certData;
    TcpIp_CertificateIdType  certId = TCPIP_CERTID_INV;

    /* #20 Extract the current certificate information */
    TcpIp_TlsCoreMsg_ExtractNextCertificate(certReadTlsBufferRxIdx, &certData);

    /* It is checked in TcpIp_TlsCoreUtil_CheckEccKeyMConfiguration()
     * that TcpIp_GetKeyMSetCertificateInGroupFuncOfTlsConfig() is not a NULL_PTR. */
    TcpIp_TlsKeyMSetCertificateInGroupFunctionType setCertificateInGroupFunc
      = TcpIp_GetKeyMSetCertificateInGroupFuncOfTlsConfig(TCPIP_TLSCONFIG_IDX);

    /* #30 Set the certificates in the remote certificate group */
    if (setCertificateInGroupFunc(groupId, certData.certData, certData.certDataLength, &certId) == E_OK)
    {
      /* Certificate loaded successfully, continue loading next certificate */
      retVal = E_OK;
    }
    else
    {
      /* Certificate could not be loaded successfully */
      retVal = E_NOT_OK;
      /* Break if error occurred. */
      break;
    }

    /* Certificate has been loaded, update the cert struct with the certificate Id */
    TcpIp_GetAddrTlsCertValidationStatusDyn(tlsCertValidationStatusIdx)->CertId = certId;

    /* Increment the cert status idx and the valid Idx */
    tlsCertValidationStatusIdx++;

    /* Increment readIdx */
    certReadTlsBufferRxIdx += (TcpIp_TlsBufferRxIterType)certLength + TCPIP_TLS_CERTLEN_LEN;

#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
    {
      /* In TLS 1.3 the Certificate Entry additionally contains extensions.
       * These are not needed to set the certificate into a group. Therefore skip over.*/
      uint16 extensionLength = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(certReadTlsBufferRxIdx), 0);
      certReadTlsBufferRxIdx += (TcpIp_TlsBufferRxIterType)extensionLength + TCPIP_TLS_EXTENSION_LENGTH_LEN;
    }
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
  }

  /* Update the valid end idx of the cert chain struct to last certificate loaded */
  TcpIp_SetTlsCertValidationStatusDynValidEndIdxOfTlsConnectionDyn(TlsConIdx, tlsCertValidationStatusIdx);

  return retVal;
} /* TcpIp_TlsCoreMsg_CertMsgSetCertificatesInGroup */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMsg_ExtractNextCertificate
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMsg_ExtractNextCertificate(
  TcpIp_TlsBufferRxIterType           CertStartTlsBufferRxIdx,
  TCPIP_P2V(TcpIp_CertDataType)       CertDataPtr
)
{
  /* ----- Implementation ---------------------------------------------- */
  /* #10 Load the certificate into the KeyM struct */
  CertDataPtr->certDataLength = IpBase_GetUint24(TcpIp_GetAddrTlsBufferRx(CertStartTlsBufferRxIdx), 0);
  CertDataPtr->certData = TcpIp_GetAddrTlsBufferRx(CertStartTlsBufferRxIdx + TCPIP_TLS_CERTLEN_LEN);
} /* TcpIp_TlsCoreMsg_ExtractNextCertificate */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMsg_EncodeSecpSignature
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
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMsg_EncodeSecpSignature(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint8) ConsumedLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferTxIterType encodedSignStartTlsBufferTxIdx
    = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  TcpIp_TlsTemporarySignatureBufferStartIdxOfTlsConnectionType signatureRawValueStartIdx
    = TcpIp_GetTlsTemporarySignatureBufferStartIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_TlsHandshakeIterType tlsHandshakeIdx = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx);
  TcpIp_TlsEllipticCurveIdType ellipticCurveId = TcpIp_GetEllipticCurveIdOfTlsHandshake(tlsHandshakeIdx);

  /* Pointer to the start of the s coordinate of the plain signature -  Output from CSM, stored in temporary buffer */
  TCPIP_P2C(uint8) r_RawValueSrcPtr = TcpIp_GetAddrTlsTemporarySignatureBuffer(signatureRawValueStartIdx);  /* TCPIP_CSL_NAME_LENGTH */

  uint8 signatureLengthLen = 0;  /* Length of the length field of the BER encoded signature */
  uint8 coordinateByteLen = 0;   /* Length of one plain signature component */
  uint8 sumEncodedCoordinateLengths = 0u;  /* length of both BER-encoded signature coordinates */

  /* variables to store details about the signature components */
  TcpIp_TlsSecpSignCoordinateDescriptorType r_SignCoordinateDescriptor;
  TcpIp_TlsSecpSignCoordinateDescriptorType s_SignCoordinateDescriptor;

  /* Example encoded signature:
   *
   *            +--> encodedSignStartTlsBufferTxIdx
   *            |
   *            +--> ASN1 Tag SEQUENCE (asn1SequenceTagPtr)
   *           /  +--> Overall length (overallAsn1SignatureLen)
   *          /  /  +--> ASN1 Tag INTEGER (r_Asn1TypePtr)
   *         30 46 /
   *             02 21 -->   r Length (r_Asn1Len): r Value length + number of leading zeros for r
   *  r_StartIdx-->  00 -->  Leading zero(s) for r value
   *                 B2 57 AA 5D 34 48 2F 45 D5 FC B6 A5 FD B4 A2 4D \
   *                                                                  +--> r Value (r_ValuePtr)
   *                 F6 58 81 EB BF B8 67 EA 11 98 9A 4A 89 D7 C6 92 /
   *             02 21 --> s Length (s_Asn1Len): s Value length + number of leading zeros for s
   *  s_StardIdx--|->00 --> Leading zero(s) for s value
   *              |  E4 8C E6 22 88 F7 6E 0D 1E 95 D6 19 29 CA 69 37 \
   *              |                                                   +--> s Value (s_ValuePtr)
   *              |  AC 97 80 E5 D8 A4 74 0F 50 ED 7B 04 E2 E0 4D 58 /
   *               \
   *                +-->  ASN1 Tag INTEGER (s_Asn1TypePtr)
   *
   */

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Determine elliptic curve coordinate length. */
  switch (ellipticCurveId)
  {
    case TCPIP_CURVE_ID_SECP256R1:
    {
      coordinateByteLen = TCPIP_CURVE_ID_SECP256R1_SIGN_BERELEM_LEN;
      break;
    }
    case TCPIP_CURVE_ID_SECP521R1:
    {
      coordinateByteLen = TCPIP_CURVE_ID_SECP521R1_SIGN_BERELEM_LEN;
      break;
    }
    default:
    {
      /* This path is never reached since the function is only called with valid / supported curve types. */
      break;
    }
  }

  /* #20 Analyze both signature components to prepare the BER encoding. */
  {
    /* Analyze the position of the first significant bit of the signature component values, and calculate their
    resulting integer length values. */

    /* Analyze the r value. */
    {
      r_SignCoordinateDescriptor.RawValueSrcPtr = r_RawValueSrcPtr;
      r_SignCoordinateDescriptor.CoordinateByteLen = coordinateByteLen;

      TcpIp_TlsCoreCtHs_AnalyzeSecpKeyComponente(r_RawValueSrcPtr, &r_SignCoordinateDescriptor);
    }

    /* Analyze the s value. */
    {
      /* Pointer to the start of the s coordinate of the plain signature */
      TCPIP_P2C(uint8) s_RawValueSrcPtr = TcpIp_GetAddrTlsTemporarySignatureBuffer(
        signatureRawValueStartIdx + coordinateByteLen);

      s_SignCoordinateDescriptor.RawValueSrcPtr = s_RawValueSrcPtr;
      s_SignCoordinateDescriptor.CoordinateByteLen = coordinateByteLen;

      TcpIp_TlsCoreCtHs_AnalyzeSecpKeyComponente(s_RawValueSrcPtr, &s_SignCoordinateDescriptor);
    }
  }

  /* #30 Determine the length of the BER length field for the total signature length. */
  {
    /* sumEncodedCoordinateLengths: Type + LenField + r coordinate + Type + LenField + s coordinate */

    /* Each signature component has a length of less than 0x80, even for Secp521r1, so 1 byte is enough for the length
    field of one signature component. For the supported curves (up to Secp521r1), the overall length will not exceed
    255 bytes. For Secp256r1 the total length can always be encoded with one byte length field, but for Secp521r1
    usually a two byte length field is needed (since the length is bigger than 0x7F). */

    sumEncodedCoordinateLengths =
      (TCPIP_TLS_ASN1TAG_TYPEID_LEN + TCPIP_TLS_ASN1LENGTH_MINLEN + r_SignCoordinateDescriptor.Asn1Len)
      + (TCPIP_TLS_ASN1TAG_TYPEID_LEN + TCPIP_TLS_ASN1LENGTH_MINLEN + s_SignCoordinateDescriptor.Asn1Len);

    if (sumEncodedCoordinateLengths >= TCPIP_TLS_ASN1_INTEGER_STARTVALUE_LEADINGZERO)
    {
      /* long length format */
      signatureLengthLen = 2u;  /* The length field needs two bytes, one for the count and one for the length value
                                (less than 256 bytes). */
    }
    else
    {
      /* short length format */
      signatureLengthLen = 1u;
    }
  }

  /* 40 Copy the encoded signature components to the encoded struct. */
  {
    /* Copy the r value. */
    r_SignCoordinateDescriptor.Asn1SequenceStartIdx = (encodedSignStartTlsBufferTxIdx + TCPIP_TLS_ASN1TAG_TYPEID_LEN
      + signatureLengthLen);

    TcpIp_TlsCoreMsg_WriteEncodedSecpSignature(&r_SignCoordinateDescriptor);

    /* Copy the s value. */
    s_SignCoordinateDescriptor.Asn1SequenceStartIdx = r_SignCoordinateDescriptor.Asn1SequenceStartIdx + TCPIP_TLS_ASN1TAG_TYPEID_LEN + TCPIP_TLS_ASN1LENGTH_MINLEN + r_SignCoordinateDescriptor.Asn1Len;
    s_SignCoordinateDescriptor.RawValueSrcPtr = &(r_SignCoordinateDescriptor.RawValueSrcPtr)[coordinateByteLen];

    TcpIp_TlsCoreMsg_WriteEncodedSecpSignature(&s_SignCoordinateDescriptor);
  }

  /* #40 Generate the ASN1 Tag SEQUENCE and SEQUENCE length. */
  {
    /* ASN1 Tag SEQUENCE - Start of encoded signature */
    TCPIP_P2V(uint8) asn1SequenceTagPtr = TcpIp_GetAddrTlsBufferTx(encodedSignStartTlsBufferTxIdx);
    /* ASN1 SEQUENCE length starts behind ASN1 Tag SEQUENCE */
    TCPIP_P2V(uint8) overallAsn1SignatureLenPtr = TcpIp_GetAddrTlsBufferTx(
      encodedSignStartTlsBufferTxIdx + TCPIP_TLS_ASN1TAG_TYPEID_LEN);

    /* Write Type of ASN1 signature */
    IpBase_PutUint8(asn1SequenceTagPtr, 0u, TCPIP_TLS_ASN1TAG_SEQUENCE_ID);

    /* Write overall ASN1 encoded signature length */
    if (signatureLengthLen == 1u)
    {
      /* One byte is enough for the length field */
      IpBase_PutUint8(overallAsn1SignatureLenPtr, 0u, sumEncodedCoordinateLengths);
    }
    else
    {
      /* The length field needs two bytes, one for the count and one for the length value (less than 256 bytes). */
      IpBase_PutUint8(overallAsn1SignatureLenPtr, 0u, 0x81);  /* The first bit indicates the long length format, the rest
                                                           indicates the number of bytes needed for the length value. */
      IpBase_PutUint8(overallAsn1SignatureLenPtr, 1u, sumEncodedCoordinateLengths);
    }

    /* #50 Update the overall consumed length. */
    /* Consumed length contains the overall length + the length of the ASN1 Tag SEQUENCE */
    *ConsumedLenPtr = sumEncodedCoordinateLengths + TCPIP_TLS_ASN1TAG_TYPEID_LEN + signatureLengthLen;
  }
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMsg_WriteEncodedSecpSignature
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMsg_WriteEncodedSecpSignature(
  TCPIP_P2C(TcpIp_TlsSecpSignCoordinateDescriptorType) SignCoordinateDescriptorPtr)
{
  /* Each signature component has a length of less than 0x80, even for Secp521r1, so 1 byte is enough for the length
  field of one signature component. */
  /* Only signatures with coordinate size of less than 0x80 are supported. */

  /* ----- Implementation ----------------------------------------------- */
  /* Ensure that at least the BER elements (type, length, value) fit into the buffer.
     The write access for the component value is protected via TcpIp_MemCpySafe(). */
  if(TcpIp_GetSizeOfTlsBufferTx() >
    (SignCoordinateDescriptorPtr->Asn1SequenceStartIdx + TCPIP_TLS_ASN1TAG_TYPEID_LEN + TCPIP_TLS_ASN1LENGTH_MINLEN))
  {
    /* #10 Set the type field of the BER element to INTEGER. */
    IpBase_PutUint8(
      TcpIp_GetAddrTlsBufferTx(0u),
      SignCoordinateDescriptorPtr->Asn1SequenceStartIdx,
      TCPIP_TLS_ASN1TAG_INTEGER_ID);

    /* #20 Copy the component and handle the leading zeros. */
    if (SignCoordinateDescriptorPtr->PrependLeadingZero == TRUE)
    {
      /* Write leading zero */
      IpBase_PutUint8(
        TcpIp_GetAddrTlsBufferTx(0u),
        (uint32_least)(SignCoordinateDescriptorPtr->Asn1SequenceStartIdx) + TCPIP_TLS_ASN1TAG_TYPEID_LEN + TCPIP_TLS_ASN1LENGTH_MINLEN,
        0x00u);

      /* Copy component value behind leading zero */
      /* If a zero has to be prepended, no leading zeros need to be skipped. */
      TcpIp_MemCpySafe(
        TcpIp_GetAddrTlsBufferTx(0),
        (uint32)SignCoordinateDescriptorPtr->Asn1SequenceStartIdx
          + TCPIP_TLS_ASN1TAG_TYPEID_LEN + TCPIP_TLS_ASN1LENGTH_MINLEN + 1u,
        TcpIp_GetSizeOfTlsBufferTx(),
        &(SignCoordinateDescriptorPtr->RawValueSrcPtr)[0],
        SignCoordinateDescriptorPtr->CoordinateByteLen);

      /* Write the overall length of the component value */
      IpBase_PutUint8(
        TcpIp_GetAddrTlsBufferTx(0u),
        (uint32_least)(SignCoordinateDescriptorPtr->Asn1SequenceStartIdx) + TCPIP_TLS_ASN1TAG_TYPEID_LEN,
        (SignCoordinateDescriptorPtr->CoordinateByteLen + 1u));
    }
    else
    {
      /* No leading zero must be added, directly copy the component value of the SECP based key */
      TcpIp_MemCpySafe(
        TcpIp_GetAddrTlsBufferTx(0),
        (uint32)SignCoordinateDescriptorPtr->Asn1SequenceStartIdx
          + TCPIP_TLS_ASN1TAG_TYPEID_LEN + TCPIP_TLS_ASN1LENGTH_MINLEN,
        TcpIp_GetSizeOfTlsBufferTx(),
        &(SignCoordinateDescriptorPtr->RawValueSrcPtr)[SignCoordinateDescriptorPtr->NumberOfSkippingLeadingZeros],
        SignCoordinateDescriptorPtr->Asn1Len);

      /* Write the overall length of the component value. */
      IpBase_PutUint8(
        TcpIp_GetAddrTlsBufferTx(0u),
        (uint32_least)(SignCoordinateDescriptorPtr->Asn1SequenceStartIdx) + TCPIP_TLS_ASN1TAG_TYPEID_LEN,
        SignCoordinateDescriptorPtr->Asn1Len);
    }
  }
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMsg_EncodeEd25519Signature
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMsg_EncodeEd25519Signature(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint8) ConsumedLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TCPIP_P2V(uint8) signatureDestPtr
    = TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

  TCPIP_P2C(uint8) signatureSrcPtr
    = TcpIp_GetAddrTlsTemporarySignatureBuffer(TcpIp_GetTlsTemporarySignatureBufferStartIdxOfTlsConnection(TlsConIdx));

  /* ----- Implementation ----------------------------------------------- */
  /* #10 ED25519 based signatures are not ASN1 encoded - copy the generated signature into the TLS TxBuffer for transmitting */
  VStdMemCpy(signatureDestPtr, signatureSrcPtr, TCPIP_CURVE_ID_ED25519_SIGNATURE_LEN);                                  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

  /* Update the consumed length information */
  *ConsumedLenPtr += TCPIP_CURVE_ID_ED25519_SIGNATURE_LEN;

} /* TcpIp_TlsCoreMsg_EncodeEd25519Signature() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMsg_EncodeEd448Signature
 *********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
  */
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMsg_EncodeEd448Signature(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2V(uint8) ConsumedLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TCPIP_P2V(uint8) signatureDestPtr
    = TcpIp_GetAddrTlsBufferTx(TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx));

  TCPIP_P2C(uint8) signatureSrcPtr
    = TcpIp_GetAddrTlsTemporarySignatureBuffer(TcpIp_GetTlsTemporarySignatureBufferStartIdxOfTlsConnection(TlsConIdx));

  /* ----- Implementation ----------------------------------------------- */
  /* #10 ED448 based signatures are not ASN1 encoded - copy the generated signature into the TLS TxBuffer for transmitting */
  VStdMemCpy(signatureDestPtr, signatureSrcPtr, TCPIP_CURVE_ID_ED448_SIGNATURE_LEN);                                    /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

  /* Update the consumed length information */
  *ConsumedLenPtr += TCPIP_CURVE_ID_ED448_SIGNATURE_LEN;

} /* TcpIp_TlsCoreMsg_EncodeEd448Signature() */

/**********************************************************************************************************************
 *  TcpIp_TlsMsg_GetLenOfCurveSpecificPubKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(uint8, TCPIP_CODE) TcpIp_TlsMsg_GetLenOfCurveSpecificPubKey(
  CONST(TcpIp_TlsEllipticCurveIdType, AUTOMATIC) CurveId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 lenRetVal = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return the length of the specific public key value depending on the given Curve ID */
  switch (CurveId)
  {
    case TCPIP_CURVE_ID_SECP256R1: {
      lenRetVal = TCPIP_CURVE_ID_SECP256R1_PUBKEY_LEN;
      break;
    } /* case TCPIP_CURVE_ID_SECP256R1 */
    case TCPIP_CURVE_ID_SECP384R1: {
      lenRetVal = TCPIP_CURVE_ID_SECP384R1_PUBKEY_LEN;
      break;
    } /* case TCPIP_CURVE_ID_SECP384R1 */
    case TCPIP_CURVE_ID_SECP521R1: {
      lenRetVal = TCPIP_CURVE_ID_SECP521R1_PUBKEY_LEN;
      break;
    } /* case TCPIP_CURVE_ID_SECP521R1 */
    case TCPIP_CURVE_ID_X25519: {
      lenRetVal = TCPIP_CURVE_ID_X25519_PUBKEY_LEN;
      break;
    } /* case TCPIP_CURVE_ID_X25519 */
    case TCPIP_CURVE_ID_X448: {
      lenRetVal = TCPIP_CURVE_ID_X448_PUBKEY_LEN;
      break;
    } /* case TCPIP_CURVE_ID_X448 */
    default: {                                                                                                           /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
      break;
    } /* default */
  } /* switch */

  return lenRetVal;
} /* TcpIp_TlsMsg_GetLenOfCurveSpecificPubKey() */
# endif /* TCPIP_SUPPORT_ASRTLS_ECC == STD_ON */

/**********************************************************************************************************************
 *  TcpIp_TlsMsg_AddUint16ValueToDistinctListInTxBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsMsg_AddUint16ValueToDistinctListInTxBuffer(
  TcpIp_TlsConnectionIterType TlsConIdx,
  uint16                      Value,
  TcpIp_TlsBufferTxIterType   ListStartIdx,
  TCPIP_P2V(uint16)           ConsumedLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if this specific value is already present */
  TcpIp_TlsBufferTxIterType ListEndTlsBufferTxIdx = (ListStartIdx + *ConsumedLenPtr);

  if (TcpIp_TlsMsg_IsUint16ValueAlreadyPresentInTxBufferList(ListStartIdx,
        ListEndTlsBufferTxIdx, Value) == FALSE)
  {
    /* #20 If it is not present, add the value at the end of the list and update the consumed length information */
    IpBase_PutUint16(TcpIp_GetAddrTlsBufferTx(ListEndTlsBufferTxIdx), 0, Value);

    /* Increment the write index by the consumed length (2 Byte) */
    TcpIp_AddTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
      (TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType) sizeof(Value));
    *ConsumedLenPtr += (uint16) sizeof(Value);
  }

} /* TcpIp_TlsMsg_AddUint16ValueToDistinctListInTxBuffer() */

/**********************************************************************************************************************
 *  TcpIp_TlsMsg_IsUint16ValueAlreadyPresentInTxBufferList
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, TCPIP_CODE) TcpIp_TlsMsg_IsUint16ValueAlreadyPresentInTxBufferList(
  TcpIp_TlsBufferTxIterType ListStartIdx,
  TcpIp_TlsBufferTxIterType ListEndIdx,
  uint16                    Value)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean valueAlreadyPresent = FALSE;
  TcpIp_TlsBufferTxIterType listStartTlsBufferTxIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over TLS TxBuffer (beginning at StartIdx) and check if the given value is already added */
  for (listStartTlsBufferTxIdx = ListStartIdx;
       listStartTlsBufferTxIdx < ListEndIdx;
       listStartTlsBufferTxIdx += (TcpIp_TlsBufferTxIterType)sizeof(Value))
  {
    uint16 alreadyAddedValue = IpBase_GetUint16(TcpIp_GetAddrTlsBufferTx(listStartTlsBufferTxIdx), 0);

    if (alreadyAddedValue == Value)
    {
      valueAlreadyPresent = TRUE;
      break;
    }
  }
  return valueAlreadyPresent;
} /* TcpIp_TlsMsg_IsUint16ValueAlreadyPresentInTxBufferList() */

# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreMsg_DecodeSignature
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreMsg_DecodeSignature(
  TcpIp_SegmentPtrType           TemporarySignatureBufferSeg,
  TcpIp_SignatureAlgorithmIdType SignatureAlgorithmId,
  TcpIp_TlsBufferRxIterType      SignatureTlsBufferRxIdx,
  TcpIp_TlsBufferRxIterType      SignatureLenTlsBufferRxIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TCPIP_P2C(uint8) receivedSignaturePtr = TcpIp_GetAddrTlsBufferRx(SignatureTlsBufferRxIdx);
  uint16 receivedSignatureLen = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(SignatureLenTlsBufferRxIdx), 0u);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Decode the signature based on the curve type */
  switch (SignatureAlgorithmId)
  {
    case TCPIP_SIG_ALGO_ID_ECDSA_SECP256R1_SHA256:
    {
      retVal = TcpIp_TlsCoreMsg_DecodeSecpSignature((uint32)receivedSignatureLen, receivedSignaturePtr,
        TemporarySignatureBufferSeg, TCPIP_CURVE_ID_SECP256R1);
      break;
    } /* case TCPIP_SIG_ALGO_ID_ECDSA_SECP256R1_SHA256 */
    case TCPIP_SIG_ALGO_ID_ECDSA_SECP521R1_SHA512:
    {
      retVal = TcpIp_TlsCoreMsg_DecodeSecpSignature((uint32)receivedSignatureLen, receivedSignaturePtr,
        TemporarySignatureBufferSeg, TCPIP_CURVE_ID_SECP521R1);
      break;
    } /* case TCPIP_SIG_ALGO_ID_ECDSA_SECP521R1_SHA512 */
    case TCPIP_SIG_ALGO_ID_ECDSA_ED25519_INTRINSIC:
    {
      retVal = TcpIp_TlsCoreMsg_DecodeEd25519Signature(receivedSignatureLen, receivedSignaturePtr,
        TemporarySignatureBufferSeg);
      break;
    } /* case TCPIP_SIG_ALGO_ID_ECDSA_ED25519_INTRINSIC */
    case TCPIP_SIG_ALGO_ID_ECDSA_ED448_INTRINSIC:
    {
      retVal = TcpIp_TlsClientMsg_DecodeEd448Signature(receivedSignatureLen, receivedSignaturePtr,
        TemporarySignatureBufferSeg);
      break;
    } /* case TCPIP_SIG_ALGO_ID_ECDSA_ED448_INTRINSIC */

    default: /* PRQA S 2016 3 */ /* MD_MSR_EmptyClause */
    {
      /* Not (yet) supported algorithm
        - TCPIP_SIG_ALGO_ID_RSA_PKCS1_SHA256
        - TCPIP_SIG_ALGO_ID_RSA_PKCS1_SHA384
        - TCPIP_SIG_ALGO_ID_RSA_PKCS1_SHA512
        - TCPIP_SIG_ALGO_ID_ECDSA_SECP384R1_SHA384
        - ...
      */
      break;
    }
  } /* switch */

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMsg_DecodeSecpSignature
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreMsg_DecodeSecpSignature(
  uint32                       ReceivedSignatureLen,
  TCPIP_P2C(uint8)             ReceivedSignatureSrcPtr,
  TcpIp_SegmentPtrType         OutputBufferSeg,
  TcpIp_TlsEllipticCurveIdType CurveId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* format of the encoded signature:
   || Type | Length | Type(r) | Length(r) | (r-parameter) | Type(s) | Length(s) | (s-parameter) ||
   ||  1   | 1 or 2 |    1    |     1     |    rLength    |    1    |     1     |    sLength    ||
  */
  if (ReceivedSignatureLen >= TCPIP_TLS_ASN1_MIN_BERENCODEDSIGNATURE)
  {
    IpBase_BerWorkspaceType     workspace;
    IpBase_BerStackElementType  berStack[TCPIP_TLS_BERENCODED_SIGNATURE_MAX_DEPTH];
    CONST(uint8, AUTOMATIC) eleNrReceivedSignatureStart[1] = { 1 };      /* chapter 1: start of the signature */
    CONST(uint8, AUTOMATIC) eleNrRValue[2] = { 1, 1 };                   /* chapter 1.1: first coordinate / r-value */
    CONST(uint8, AUTOMATIC) eleNrSValue[2] = { 1, 2 };                   /* chapter 1.2: second coordinate / s-value */

    /* #10 Init the BER decoding workspace. */
    IpBase_BerInitWorkspace(&workspace, &berStack[0], TCPIP_TLS_BERENCODED_SIGNATURE_MAX_DEPTH);

    /* #20 Check that the sequence type and length of the signature is well formatted. */
    if (TcpIp_TlsCoreMsg_CheckSecpSignatureSequence(&workspace, &eleNrReceivedSignatureStart[0],
      ReceivedSignatureSrcPtr, ReceivedSignatureLen, CurveId) == E_OK)
    {
      /* #30 Decode the r-value of the signature and save it so it can be verified later. */
      if (TcpIp_TlsCoreMsg_DecodeSecpSignatureRValue(&workspace, &eleNrRValue[0],
        ReceivedSignatureSrcPtr, ReceivedSignatureLen, CurveId, OutputBufferSeg) == E_OK)
      {
        /* #40 Decode the s-value of the signature and save it so it can be verified later. */
        if (TcpIp_TlsCoreMsg_DecodeSecpSignatureSValue(&workspace, &eleNrSValue[0],
          ReceivedSignatureSrcPtr, ReceivedSignatureLen, CurveId, OutputBufferSeg) == E_OK)
        {
          retVal = E_OK;
        }
      }
    }
  }

  return retVal;
} /* TcpIp_TlsCoreMsg_DecodeSecpSignature */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMsg_CheckSecpSignatureSequence
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreMsg_CheckSecpSignatureSequence(
  TCPIP_P2V(IpBase_BerWorkspaceType) WorkspacePtr,
  TCPIP_P2C(uint8)                   EleNrReceivedSignatureStartPtr,
  TCPIP_P2C(uint8)                   ReceivedSignaturePtr,
  uint32                             ReceivedSignatureLen,
  TcpIp_TlsEllipticCurveIdType       CurveId)
{
  /* ----- Local Variables ---------------------------------------------- */
  IpBase_BerElementType       eleDesc;
  Std_ReturnType              retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Find the position of the signature's first chapter and write the index information into eleDesc. */
  if (IpBase_BerGetElement(WorkspacePtr, &eleDesc, EleNrReceivedSignatureStartPtr,
        TCPIP_TLS_BERENCODED_SIGNATURE_DEPTH_ONE, ReceivedSignaturePtr, ReceivedSignatureLen) == IPBASE_E_OK)
  {
    /* now, eleDesc contains the index information */
    /* chapter one */
    /* Check that the signature only contains one chapter / one sequence. */
    if (ReceivedSignatureLen == (eleDesc.EndIdx - eleDesc.Idx))
    {
      /* The minimum sequence length for a secp curve (each coordinate with only one byte). */
      uint32 minSequenceLen = (TCPIP_TLS_ASN1_MIN_SEQUENCELENGTH_BERENCODEDSIGNATURE + (2u * 1u));
      /* The maximum valid sequence length depends on the used curve. */
      uint32 maxSequenceLen;
      if (CurveId == TCPIP_CURVE_ID_SECP256R1)
      {
        maxSequenceLen = TCPIP_TLS_ASN1_SECP256R1_MAX_SEQUENCELENGTH;
      }
      else /* (CurveId == TCPIP_CURVE_ID_SECP521R1) */
      {
        /* This function can only be called with those two values for the CurveId.
         * This is checked in TcpIp_TlsCoreMsg_DecodeSignature(). */
        maxSequenceLen = TCPIP_TLS_ASN1_SECP521R1_MAX_SEQUENCELENGTH;
      }
      /* #20 Check that eleDesc contains the expected information for type and length. */
      if (TcpIp_TlsCoreUtil_HasIpBaseBerElementExpectedValues(&eleDesc, TCPIP_TLS_ASN1TAG_SEQUENCE_ID,
            minSequenceLen, maxSequenceLen, ReceivedSignaturePtr) == TRUE)
      {
        retVal = E_OK;
      }
    }
  }
  return retVal;

} /* TcpIp_TlsCoreMsg_CheckSecpSignatureSequence */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMsg_DecodeSecpSignatureRValue
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6060 1 */ /* MD_TcpIp_TlsPointerAndLength_STPAR_6060 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreMsg_DecodeSecpSignatureRValue(
  TCPIP_P2V(IpBase_BerWorkspaceType) WorkspacePtr,
  TCPIP_P2C(uint8)                   EleNrRValuePtr,
  TCPIP_P2C(uint8)                   ReceivedSignaturePtr,
  uint32                             ReceivedSignatureLen,
  TcpIp_TlsEllipticCurveIdType       CurveId,
  TcpIp_SegmentPtrType               OutputBufferSeg)
{
  /* ----- Local Variables ---------------------------------------------- */
  IpBase_BerElementType       eleDesc;
  Std_ReturnType              retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Find the position of the signature's 'r-value' chapter and write the index information into eleDesc. */
  if (IpBase_BerGetElement(WorkspacePtr, &eleDesc, EleNrRValuePtr, TCPIP_TLS_BERENCODED_SIGNATURE_DEPTH_TWO,
        ReceivedSignaturePtr, ReceivedSignatureLen) == IPBASE_E_OK)
  {
    /* now, eleDesc contains the index information */
    /* chapter 1.1: r-value */
    uint32 rLength = eleDesc.EndIdx - eleDesc.ContentIdx;
    /* Check that after the r-value chapter there is enough data for the s-value.
     * The s-value needs at least one byte. */
    if (ReceivedSignatureLen >= ((uint32)TCPIP_TLS_ASN1_MIN_BERENCODEDSIGNATURE + rLength + 1u))
    {
      uint32 maxCoordLen;
      uint8 coordSize;
      boolean leadingZero = FALSE;
      uint32 leadingZeroOffset = 0u;
      retVal = E_OK;
      if (CurveId == TCPIP_CURVE_ID_SECP256R1)
      {
        /* The coordinates of the secp256 curve when Ber encoded might contain a leading zero,
         * which leads to a maximum coordinate length of 33 byte.
         * A leading zero is added in case the first byte >= 0x80. */
        maxCoordLen = TCPIP_CURVE_ID_SECP256R1_SIGN_BERELEM_LEN + 1u;
        /* The actual coordinates are only 32 byte large though. */
        coordSize = TCPIP_CURVE_ID_SECP256R1_SIGN_BERELEM_LEN;
        /* The coordinates in the secp256 case can only have maximum length with a leading zero. */
        /* That the length is not larger than the maximum
         * is checked in TcpIp_Tls12CoreUtil_HasIpBaseBerElementExpectedValues(). */
        if (rLength == maxCoordLen)
        {
          /* If there is a leading zero, reduce the parameter length and increment the offset. */
          leadingZero = TRUE;
          leadingZeroOffset++;
          rLength--;
        }
        if ((leadingZero == TRUE) && (ReceivedSignaturePtr[eleDesc.ContentIdx] != 0u))
        {
          retVal = E_NOT_OK;
        }
      }
      else /* (CurveId == TCPIP_CURVE_ID_SECP521R1) */
      {
        /* This function can only be called with those two values for the CurveId.
         * This is checked in TcpIp_TlsCoreMsg_DecodeSignature(). */
        maxCoordLen = TCPIP_CURVE_ID_SECP521R1_SIGN_BERELEM_LEN;
        coordSize = TCPIP_CURVE_ID_SECP521R1_SIGN_BERELEM_LEN;
        /* The coordinates with the Secp521 curve can have a length of 521 bit,
         * which corresponds to 65 byte and 1 bit.
         * When rLength is at its maximum with 66 bytes, only the last bit of the first byte can be set to one. */
        if ((rLength == maxCoordLen) && (ReceivedSignaturePtr[eleDesc.ContentIdx] > 1u))
        {
          retVal = E_NOT_OK;
        }
      }
      if (retVal == E_OK)
      {
        retVal = E_NOT_OK;
        /* #20 Check that eleDesc contains the expected information for type and length. */
        /* Check for a minimum length of one byte. The type must be an integer. */
        if (TcpIp_TlsCoreUtil_HasIpBaseBerElementExpectedValues(&eleDesc,
              TCPIP_TLS_ASN1TAG_INTEGER_ID, 1u, maxCoordLen, ReceivedSignaturePtr) == TRUE)
        {
          /* #30 Fill start of signature parameter with zero bytes if necessary. */
          TcpIp_SegmentMemSet(OutputBufferSeg, 0u, (coordSize - (uint32)rLength));

          /* #40 Copy the value of the signature parameter. */
          TcpIp_SegmentMemCpy(OutputBufferSeg, &ReceivedSignaturePtr[eleDesc.ContentIdx + leadingZeroOffset], rLength);

          retVal = E_OK;
        }
      }
    }
  }
  return retVal;

} /* TcpIp_TlsCoreMsg_DecodeSecpSignatureRValue */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMsg_DecodeSecpSignatureSValue
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6060 1 */ /* MD_TcpIp_TlsPointerAndLength_STPAR_6060 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreMsg_DecodeSecpSignatureSValue(
  TCPIP_P2V(IpBase_BerWorkspaceType) WorkspacePtr,
  TCPIP_P2C(uint8)                   EleNrSValuePtr,
  TCPIP_P2C(uint8)                   ReceivedSignaturePtr,
  uint32                             ReceivedSignatureLen,
  TcpIp_TlsEllipticCurveIdType       CurveId,
  TcpIp_SegmentPtrType               OutputBufferSeg)
{
  /* ----- Local Variables ---------------------------------------------- */
  IpBase_BerElementType       eleDesc;
  Std_ReturnType              retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Find the position of the signature's 's-value' chapter and write the index information into eleDesc. */
  if (IpBase_BerGetElement(WorkspacePtr, &eleDesc, EleNrSValuePtr, TCPIP_TLS_BERENCODED_SIGNATURE_DEPTH_TWO,
    ReceivedSignaturePtr, ReceivedSignatureLen) == IPBASE_E_OK)
  {
    /* now, eleDesc contains the index information */
    /* chapter 1.2: s-value */
    uint32 sLength = eleDesc.EndIdx - eleDesc.ContentIdx;

    /* There shouldn't be any data in the signature after the s-value. */
    if (ReceivedSignatureLen == eleDesc.EndIdx)
    {
      uint32 maxCoordLen;
      uint8 coordSize;
      boolean leadingZero = FALSE;
      uint32 leadingZeroOffset = 0u;
      retVal = E_OK;
      if (CurveId == TCPIP_CURVE_ID_SECP256R1)
      {
        /* The coordinates of the secp256 curve when Ber encoded might contain a leading zero,
         * which leads to a maximum coordinate length of 33 byte.
         * A leading zero is added in case the first byte >= 0x80. */
        maxCoordLen = TCPIP_CURVE_ID_SECP256R1_SIGN_BERELEM_LEN + 1u;
        /* The actual coordinates are only 32 byte large though. */
        coordSize = TCPIP_CURVE_ID_SECP256R1_SIGN_BERELEM_LEN;
        /* The coordinates in the secp256 case can only have maximum length with a leading zero. */
        /* That the length is not larger than the maximum
         * is checked in TcpIp_Tls12CoreUtil_HasIpBaseBerElementExpectedValues(). */
        if (sLength == maxCoordLen)
        {
          /* If there is a leading zero, reduce the parameter length and increment the offset. */
          leadingZero = TRUE;
          leadingZeroOffset++;
          sLength--;
        }
        if ((leadingZero == TRUE) && (ReceivedSignaturePtr[eleDesc.ContentIdx] != 0u))
        {
          retVal = E_NOT_OK;
        }
      }
      else /* (CurveId == TCPIP_CURVE_ID_SECP521R1) */
      {
        /* This function can only be called with those two values for the CurveId.
         * This is checked in TcpIp_TlsCoreMsg_DecodeSignature(). */
        maxCoordLen = TCPIP_CURVE_ID_SECP521R1_SIGN_BERELEM_LEN;
        coordSize = TCPIP_CURVE_ID_SECP521R1_SIGN_BERELEM_LEN;
        /* The coordinates with the Secp521 curve can have a length of 521 bit,
         * which corresponds to 65 byte and 1 bit.
         * When rLength is at its maximum with 66 bytes, only the last bit of the first byte can be set to one. */
        if ((sLength == maxCoordLen) && (ReceivedSignaturePtr[eleDesc.ContentIdx] > 1u))
        {
          retVal = E_NOT_OK;
        }
      }
      if (retVal == E_OK)
      {
        retVal = E_NOT_OK;
        /* #20 Check that eleDesc contains the expected information for type and length. */
        /* Check for a minimum length of one byte. The type must be an integer. */
        if (TcpIp_TlsCoreUtil_HasIpBaseBerElementExpectedValues(&eleDesc,
              TCPIP_TLS_ASN1TAG_INTEGER_ID, 1u, maxCoordLen, ReceivedSignaturePtr) == TRUE)
        {
          /* #30 Fill start of signature parameter with zero bytes if necessary. */
          TcpIp_SegmentMemSet(OutputBufferSeg, 0u, (coordSize - (uint32)sLength));

          /* #40 Copy the value of the signature parameter. */
          TcpIp_SegmentMemCpy(OutputBufferSeg, &ReceivedSignaturePtr[eleDesc.ContentIdx + leadingZeroOffset], sLength);

          retVal = E_OK;
        }
      }
    }
  }
  return retVal;

} /* TcpIp_TlsCoreMsg_DecodeSecpSignatureSValue */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMsg_DecodeEd25519Signature
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreMsg_DecodeEd25519Signature(
  uint32                      ReceivedSignatureLen,
  TCPIP_P2C(uint8)            ReceivedSignatureSrcPtr,
  TcpIp_SegmentPtrType        OutputBufferSeg)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the length of the received signature */
  if (ReceivedSignatureLen == TCPIP_CURVE_ID_ED25519_SIGNATURE_LEN)
  {
    /* #20 Copy the signature element directly into temp buffer since there is no actual decoding */
    TcpIp_SegmentMemCpy(OutputBufferSeg, ReceivedSignatureSrcPtr, TCPIP_CURVE_ID_ED25519_SIGNATURE_LEN);
    retVal = E_OK;
  }

  return retVal;
} /* TcpIp_TlsCoreMsg_DecodeEd25519Signature */

/**********************************************************************************************************************
 *  TcpIp_TlsClientMsg_DecodeEd448Signature
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClientMsg_DecodeEd448Signature(
  uint32                      ReceivedSignatureLen,
  TCPIP_P2C(uint8)            ReceivedSignatureSrcPtr,
  TcpIp_SegmentPtrType        OutputBufferSeg)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the length of the received signature */
  if (ReceivedSignatureLen == TCPIP_CURVE_ID_ED448_SIGNATURE_LEN)
  {
    /* #20 Copy the signature element directly into temp buffer since there is no actual decoding */
    TcpIp_SegmentMemCpy(OutputBufferSeg, ReceivedSignatureSrcPtr, TCPIP_CURVE_ID_ED448_SIGNATURE_LEN);
    retVal = E_OK;
  }

  return retVal;
} /* TcpIp_TlsClientMsg_DecodeEd448Signature */
# endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TLS CORE MAIN FUNCTION TX
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreMainFunction_TxHs
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_TxHs(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Process TX function only if we are in an active TLS handshake state */
  if (   ((TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx)) == TCPIP_TLS_STATE_CONNECTION_HS_ACTIVE)
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
      /* HS finalizing is also an active Hs state */
      || ((TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx)) == TCPIP_TLS_STATE_CONNECTION_SERVER_HS_FINALIZING)   /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
# endif
    )
  {
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
    if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
#  endif
    {
      /* Connection is configured as TLS Server */
      /* #20 Forward processing of TX messages to TLS Server */
      TcpIp_TlsServerTx_CheckForTransmittableProcessedHsMsg(TlsConIdx);
    }
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
    else
#  endif
# endif
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
    {
      /* Connection is configured as TLS Client */
      /* #30 Forward processing of TX messages to TLS Client */
      TcpIp_TlsClientTx_CheckForTransmittableProcessedHsMsg(TlsConIdx);
    }
# endif
  }
} /* TcpIp_TlsCoreMainFunction_TxHs() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMainFunction_TxAl
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_TxAl(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ----------------------------------------------- */
  TcpIp_TlsConnectionState activeConnectionState = TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Process TX Alert function if the current Tls connection is in a valid state */
  if (   (TcpIp_IsTxAlertTriggerOfTlsConnectionDyn(TlsConIdx) == TRUE)
      && (   /* Alert can be triggered when connection is established */
             (activeConnectionState == TCPIP_TLS_STATE_CONNECTION_ESTABLISHED)
             /* Alert can be triggered when Hs is active */
          || (activeConnectionState == TCPIP_TLS_STATE_CONNECTION_HS_ACTIVE)
              /* Alert can be triggered when TLS connection is waiting to close */
          || (activeConnectionState == TCPIP_TLS_STATE_CONNECTION_CLOSENOTIFY_WAIT)
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
          || (activeConnectionState == TCPIP_TLS_STATE_CONNECTION_13_ACTIVE_CLOSE_REQUESTED)
             /* Alert can still be triggered if Tx Path is already closed. */
          || (activeConnectionState == TCPIP_TLS_STATE_CONNECTION_13_CLOSENOTIFY_SENT)
             /* Alert can still be triggered if Rx Path is already closed. */
          || (activeConnectionState == TCPIP_TLS_STATE_CONNECTION_13_CLOSENOTIFY_RECEIVED)
# endif
         ))
  {
    /* Forward the TX to the internal function */
    TcpIp_TlsCoreCtAl_TxAlert(TlsConIdx);
  }
} /* TcpIp_TlsCoreMainFunction_TxAl() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMainFunction_TxAd
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_TxAd(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsConnectionState state = TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the state and the version of the TLS connection */
  if (   (state == TCPIP_TLS_STATE_CONNECTION_ESTABLISHED)
      || (state == TCPIP_TLS_STATE_CONNECTION_CLOSE_WAIT)
      || (state == TCPIP_TLS_STATE_CONNECTION_CLOSE_WITH_CLOSENOTIFY_FIN_REQUESTED)
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      || (state == TCPIP_TLS_STATE_CONNECTION_13_ACTIVE_CLOSE_REQUESTED)
      || (state == TCPIP_TLS_STATE_CONNECTION_13_CLOSENOTIFY_RECEIVED)
# endif
     )
  {
    TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
    TcpIp_TlsBufferTxAdHsReadIdxOfTlsBufferMgmtDynType txAdHsReadIdx
      = TcpIp_GetTlsBufferTxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

    TcpIp_SizeOfTlsBufferTxType applicationDataFillLvl = TcpIp_GetAdTxFillLevelOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

    /* #20 If the TLS connection is established, check if there is new data to be transmitted */
    if (applicationDataFillLvl != 0u)
    {
      /* #30 If there is data in the transmit buffer, forward the data to the record layer */
      (void)TcpIp_TlsCoreRl_Transmit(TlsConIdx, txAdHsReadIdx, applicationDataFillLvl, TCPIP_TLS_CT_AD);
    }
    /* #40 else - otherwise no AD data to transmit */
  }
  /* #50  else - otherwise no connection is established, nothing to do */
} /* TcpIp_TlsCoreMainFunction_TxAd() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMainFunction_TxCcs
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_TxCcs(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* Check the state of the TLS connection */
  if ((TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx)) == TCPIP_TLS_STATE_CONNECTION_HS_ACTIVE)
  {
  /* #10 Depending on the type of connection, trigger sending of CCS message */
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
    if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
#  endif
    {
      /* Mode == TCPIP_TLS_SERVER */
      TcpIp_TlsServerConnectionIterType tlsServerConnectionIdx = TcpIp_GetTlsServerConnectionIdxOfTlsConnection(TlsConIdx);

      /* Trigger sending CCS, if the flag is set */
      if (TcpIp_IsChangeCipherSpecReadyToSendOfTlsServerConnection(tlsServerConnectionIdx) == TRUE)
      {
        TcpIp_TlsServerTx_SendChangeCipherSpec(TlsConIdx);
        /* Reset the Sequence counter */
        TcpIp_SetRlTxSequenceCounterOfTlsConnectionDyn(TlsConIdx, 0);
      }
    }
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
    else
#  endif
# endif
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
    {
      /* Mode == TCPIP_TLS_CLIENT */
      TcpIp_TlsClientConnectionIterType tlsClientConnectionIdx = TcpIp_GetTlsClientConnectionIdxOfTlsConnection(TlsConIdx);

      /* Trigger sending CCS, if the flag is set */
      if (TcpIp_IsChangeCipherSpecReadyToSendOfTlsClientConnection(tlsClientConnectionIdx) == TRUE)
      {
        TcpIp_TlsClientTx_SendChangeCipherSpec(TlsConIdx);
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
        if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_12)
#   endif
        {
          /* Reset the Sequence counter */
          TcpIp_SetRlTxSequenceCounterOfTlsConnectionDyn(TlsConIdx, 0);
        }
#  endif
      }
    }
# endif
  } /* else - otherwise no handshake is active, nothing to do */
} /* TcpIp_TlsCoreMainFunction_TxCcs() */

/**********************************************************************************************************************
 *  TLS CORE STATES AND EVENTS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreState_UserEventHandler
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreState_UserEventHandler(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* User<EVENT>Handler:  Handles events which are triggered from UpperLayer (User) */
  /* Tcp<EVENT>Handler:   Handles events which are triggered from LowerLayer (Tcp) */

  /* #10 Handle User close requests */
  TcpIp_TlsCoreConState_UserCloseRequestedHandler(TlsConIdx);

  /* #20 Handle User reset requests */
  TcpIp_TlsCoreConState_UserResetRequestedHandler(TlsConIdx);
} /* TcpIp_TlsCoreState_UserEventHandler() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreState_HandshakeHandler
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreState_HandshakeHandler(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Process the TLS handshake state machine depending on the TLS-Connection Mode (Server/Client) */
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
#  endif
  {
    /* Connection is configured as TLS-Server */
    TcpIp_TlsServer_ProcessHandshake(TlsConIdx);
  }
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  else
#  endif
# endif
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  {
    /* Connection is configured as TLS-Client */
    TcpIp_TlsClient_ProcessHandshake(TlsConIdx);
  }
# endif
} /* TcpIp_TlsCoreState_HandshakeHandler() */

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreState_ConnectionHandler
 *********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
  */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreState_ConnectionHandler(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Process the TLS handshake state machine depending on the TLS-Connection Mode (Server/Client) */
#  if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
#   endif
  {
    /* Connection is configured as TLS-Server */
    /* Nothing to do */
  }
#   if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  else
#   endif
#  endif
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  {
    /* Connection is configured as TLS-Client */
    TcpIp_TlsClient_ProcessConnection(TlsConIdx);
  }
#  endif
}
# endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */


/**********************************************************************************************************************
 *  TcpIp_TlsCoreState_TcpEventHandler
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreState_TcpEventHandler(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* User<EVENT>Handler:  Handles events which are triggered from UpperLayer (User) */
  /* Tcp<EVENT>Handler:   Handles events which are triggered from LowerLayer (Tcp) */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Handle TCP close requests */
  TcpIp_TlsCoreConState_TcpCloseRequestedHandler(TlsConIdx);

  /* #20 Handle TCP reset requests */
  TcpIp_TlsCoreConState_TcpResetRequestedHandler(TlsConIdx);

} /* TcpIp_TlsCoreState_TcpEventHandler() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreState_UserErrorHandler
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreState_UserErrorHandler(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsUserErrorBufferWriteIdxOfTlsConnectionDynType tlsUserErrorBufferWriteIdx =
                                                       TcpIp_GetTlsUserErrorBufferWriteIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_TlsUserErrorBufferStartIdxOfTlsConnectionType tlsUserErrorBufferStartIdx =
                                                       TcpIp_GetTlsUserErrorBufferStartIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Notify upper layer if user error buffer is not empty. */
  if (tlsUserErrorBufferWriteIdx != tlsUserErrorBufferStartIdx)
  {
    TcpIp_TlsCoreError_UserErrorCallout(TlsConIdx);
  }
} /* TcpIp_TlsCoreState_UserErrorHandler() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreState_AlertHandler
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreState_AlertHandler(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if we received an Alert */
  if (TcpIp_IsAlRxIndicationOfTlsConnectionDyn(TlsConIdx) == TRUE)
  {
    /* #20 if so, parse the Alert content */
    TcpIp_TlsCoreCtAl_ParseReceivedAlertTlsVersionDependent(TlsConIdx);

    /* #30 Reset the AL RxIndication */
    TcpIp_SetAlRxIndicationOfTlsConnectionDyn(TlsConIdx, FALSE);
  }
} /* TcpIp_TlsCoreState_AlertHandler() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreState_ApplicationDataHandler
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreState_ApplicationDataHandler(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDynType rxAdHsWriteIdx
    = TcpIp_GetTlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  TcpIp_SizeOfTlsBufferRxType rxAdHsReadMaxIdx = TcpIp_TlsCoreRl_GetReadMaxIdxForContentType(TlsConIdx, TCPIP_TLS_CT_AD);

  TcpIp_TlsBufferRxAdHsStartIdxOfTlsBufferMgmtType rxAdHsStartIdx
    = TcpIp_GetTlsBufferRxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);

  /* Position of unforwarded data in TLS Rx AdHs buffer */
  TcpIp_TlsBufferRxUlRxIndIdxOfTlsBufferMgmtDynType ulRxIndTlsBufferRxIdx
    = TcpIp_GetTlsBufferRxUlRxIndIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

  TcpIp_TlsConnectionState state = TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if this TLS connection is already established or in case of TLS 1.3 a CloseNotify was sent */
  /* When the FIN flag was set in the received TCP segment the connection state is close_wait.
   * In this state received application data must be forwarded to the upper layer still
   * and therefore must be processed here.
   * The same holds for the connection state if a TcpIp_Close is triggered (Abort=True or Abort=False) */
  if (   (state == TCPIP_TLS_STATE_CONNECTION_ESTABLISHED)
      || (state == TCPIP_TLS_STATE_CONNECTION_CLOSE_WAIT)
      || (state == TCPIP_TLS_STATE_CONNECTION_USER_RESET_REQUESTED)
      || (state == TCPIP_TLS_STATE_CONNECTION_CLOSE_WITH_CLOSENOTIFY_FIN_REQUESTED)
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      || (state == TCPIP_TLS_STATE_CONNECTION_13_CLOSENOTIFY_SENT)
# endif
     )
  {
    /* #20 Check if there is new data in TLS Rx AdHs buffer to forward to Ul */
    /* this flag is only set if the UL Rxindication fill level is not 0 */
    if (TcpIp_IsAdRxIndicationOfTlsConnectionDyn(TlsConIdx) == TRUE)
    {
      /* TLS Ad RxIndication flag is set - This means there is new unforwarded data in the TLS Rx AdHs buffer */

      if (   (ulRxIndTlsBufferRxIdx == rxAdHsWriteIdx)                                                                  /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
          && (   (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_USER_RESET_REQUESTED)
              || (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_CLOSE_WITH_CLOSENOTIFY_FIN_REQUESTED)))
      {
        /* Skip RxIndications if no other application data is received and in any state after TcpIp_Close was called.
         *
         * If any plaintext, no matter what content type (see TcpIp_TlsCoreRl_SetParametersForReceivedFrame(),
         * is left in the RxBuffer, the value of AdUlRxIndLevelOfTlsBufferMgmtDyn is not 0.
         * Therefore, a AdRxIndication is still invoked due to the additional data left (see TcpIp_TlsCoreCtAd_ForwardDataToAdHandler()).
         * If this data is not from type application_data (e.g. alert from the peer) the writeTlsBufferRxIdx
         * is not incremented and no upper layer RxIndication must be invoked.
         * Thus, this can be checked and ensured here. */
      }
      else
      {
        /* #30 Depending on the UlRxIndication index, forward unforwarded data to the upper layer */
        uint32 unforwardedDataLinear = 0u;
        uint32 unforwardedDataAtEndOfBuffer = 0u;
        /* The return value can be ignored here since the indices must be correct. */
        (void) TcpIp_GetSplitLengthInRingBuffer(rxAdHsWriteIdx, ulRxIndTlsBufferRxIdx, rxAdHsStartIdx, rxAdHsReadMaxIdx,
          &unforwardedDataLinear, &unforwardedDataAtEndOfBuffer);
        /* Invoked UL Rx indication for data at the end, if present */
        if (unforwardedDataAtEndOfBuffer != 0u)
        {
          TcpIp_TlsCoreUl_RxIndication(TlsConIdx, TcpIp_GetAddrTlsBufferRx(ulRxIndTlsBufferRxIdx),
            (TcpIp_SizeOfTlsBufferRxType)unforwardedDataAtEndOfBuffer);
        }

        /* Invoked UL Rx indication for data in front of writeTlsBufferRxIdx.
         * Can either be at the start of the buffer or in the middle of it. */
        if (unforwardedDataLinear != 0u)
        {
          /* No underflow possible since this data is linear, see TcpIp_GetSplitLengthInRingBuffer(). */
          TcpIp_TlsCoreUl_RxIndication(TlsConIdx,
            TcpIp_GetAddrTlsBufferRx((TcpIp_TlsBufferRxIterType)(rxAdHsWriteIdx - unforwardedDataLinear)),
            unforwardedDataLinear);
        }

        /* Decrement RxIndication fill level with the total length of forwarded data */
        TcpIp_SubAdUlRxIndLevelOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
          (TcpIp_SizeOfTlsBufferRxType)(unforwardedDataLinear + unforwardedDataAtEndOfBuffer));
      }
      /* Set Ad RxIndication flag to false, since all new data has been forwarded to Ul */
      TcpIp_SetAdRxIndicationOfTlsConnectionDyn(TlsConIdx, FALSE);
    }
  }
} /* TcpIp_TlsCoreState_ApplicationDataHandler() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreEvent_TcpIpEventForwarding
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreEvent_TcpIpEventForwarding(
  TcpIp_SocketDynIterType SocketIdx,
  IpBase_TcpIpEventType   Event)
{
  /* ----- Local Variables ---------------------------------------------- */
   TcpIp_TlsConnectionIterType tlsConIdx = TcpIp_GetSizeOfTlsConnection();

  /* ----- Implementation ----------------------------------------------- */
  /* This function only "stores" the received Events. The handling is done in TcpIp_TlsCoreMainFunction_State */
  /* #10 Set the given TCP Event in the corresponding TLS connection identified by the given socket ID */
  if (TcpIp_SocketIdxToTlsConIdx(SocketIdx, &tlsConIdx) == E_OK)
  {
    if(tlsConIdx < TcpIp_GetSizeOfTlsConnection())
    {
      switch(Event)
      {
        case IPBASE_TCP_EVENT_RESET:
        {
          TcpIp_TlsCoreEvent_TcpEventReset(tlsConIdx);
          break;
        } /* case IPBASE_TCP_EVENT_RESET */

        case IPBASE_TCP_EVENT_CLOSED:
        {
          TcpIp_TlsCoreEvent_TcpEventClosed(tlsConIdx);
          break;
        } /* case IPBASE_TCP_EVENT_CLOSED */

        case IPBASE_TCP_EVENT_FIN_RECEIVED:
        {
          TcpIp_TlsCoreEvent_TcpEventFinReceived(tlsConIdx);
          break;
        } /* case IPBASE_TCP_EVENT_FIN_RECEIVED */

        default:
        {
          /* do nothing */
          break;
        } /* default */
      } /* switch() */
    }
    else
    {
      TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
    }
  }
} /* TcpIp_TlsCoreEvent_TcpIpEventForwarding() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreEvent_TcpIpEventClose
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreEvent_TcpIpEventClose(
  TcpIp_SocketDynIterType SocketIdx,
  boolean Abort)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* Enter critical section */
  TCPIP_VENTER_CRITICAL_SECTION();


  {
    TcpIp_TlsConnectionIterType tlsConIdx;
    /* The actual closing of the connection is done within TcpIp_TlsCoreState_<>EventHandler() */
    /* #10 The close request is on an active socket, check if there is an active TLS connection and update the TLS state */
    if (TcpIp_SocketIdxToTlsConIdx(SocketIdx, &tlsConIdx) == E_OK)
    {
      if(tlsConIdx < TcpIp_GetSizeOfTlsConnection())
      {
        if (Abort == TRUE)
        {
          /* User wants to send RST */
          TcpIp_SetConnectionStateOfTlsConnectionDyn(tlsConIdx, TCPIP_TLS_STATE_CONNECTION_USER_RESET_REQUESTED);
        }
        else
        {
          TcpIp_TlsCoreEvent_TcpIpEventCloseWithAbortFalse(tlsConIdx);
        }
      }
      else
      {
        TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
      }
    }
  }
  /* Leave critical section */
  TCPIP_VLEAVE_CRITICAL_SECTION();

} /* TcpIp_TlsCoreEvent_TcpIpEventClose() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreEvent_TcpIpEventCloseWithAbortFalse
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreEvent_TcpIpEventCloseWithAbortFalse(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the current status of the TLS connection */
  TcpIp_TlsConnectionState state = TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx);
  if (   (state != TCPIP_TLS_STATE_CONNECTION_HS_ACTIVE)
      && (state != TCPIP_TLS_STATE_CONNECTION_SERVER_HS_FINALIZING)
      && (state != TCPIP_TLS_STATE_CONNECTION_ACTIVE_HS_CANCLED)
      && (state != TCPIP_TLS_STATE_CONNECTION_ACTIVE_HS_CLOSED))
  {
    /* #20 TLS handshake is already done */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    /* #30 Check if the upper layer triggered a close but no CloseNotify was received and TLS 1.3 is used */
    if (   (state == TCPIP_TLS_STATE_CONNECTION_ESTABLISHED)
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
        && (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)                                 /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
#  endif
       )
    {
      /* #40 If so, send a CloseNotify but keep the TCP connection open (no FIN should be sent) */
      TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx,
        TCPIP_TLS_STATE_CONNECTION_13_ACTIVE_CLOSE_REQUESTED);
    }
    else
# endif
    {
      /* #50 Otherwise, we should trigger the CloseNotify */
      /* Setting this state will trigger the CloseNotify */
      TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx,
        TCPIP_TLS_STATE_CONNECTION_CLOSE_WITH_CLOSENOTIFY_FIN_REQUESTED);
    }
  }
  else
  {
    /* #60 TLS connection is during TLS handshake - no CloseNotify is sent */
    /* Triggers gracefully TCP Close */
    TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx,
      TCPIP_TLS_STATE_CONNECTION_GRACEFULLY_TCP_CLOSE_REQUESTED);
  }
} /* TcpIp_TlsCoreEvent_TcpIpEventCloseWithAbortFalse() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreEvent_TcpEventReset
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreEvent_TcpEventReset(
TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsConnectionState tlsState = TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the socket owner triggered a TCP RST (TcpIp_Close with Abort set to TRUE) and change the state. */
  if (tlsState == TCPIP_TLS_STATE_CONNECTION_USER_RESET_WAIT)
  {
    /* #20 User triggered RST - User is already informed about the received RST, therefore set the state to inactive. */
    TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CONNECTION_HS_INACTIVE);
  }
  else
  {
    /* #30 We received a RST which must be processed - Check if the event shall be forwarded to the upper layer
     * depending on the mode and state of the TLS connection. */
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
    if (TcpIp_TlsCoreUtil_IsUlEventForwardingNeededDuringClosing(TlsConIdx) == FALSE)
    {
      /* #40 TLS-Server during handshake - upper layer must not be informed about RST. */
      TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx,
        TCPIP_TLS_STATE_CONNECTION_TCP_RESET_REQUESTED_WITHOUT_UPPERLAYER_EVENT_FORWARDING);
    }
    else
# endif
    {
      /* #50 TLS-Client or TLS-Server after handshake done - Inform upper layer about RST. */
      TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CONNECTION_TCP_RESET_REQUESTED);
    }
  }
} /* TcpIp_TlsCoreEvent_TcpEventReset() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreEvent_TcpEventClosed
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreEvent_TcpEventClosed(
TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_VENTER_CRITICAL_SECTION();

  /* #10 TLS received CLOSED event from TcpIp - Forward the event depending on the connection mode and state (Server/Client) */
  if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
  {
    /* TLS-Server */

    if (    (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_HS_ACTIVE)             /* PRQA S 3415 4 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
         || (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_SERVER_HS_FINALIZING)
         || (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_CLOSING_WITHOUT_UPPERLAYER_EVENT_FORWARDING)
         || (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_GRACEFULLY_TCP_CLOSE_REQUESTED_WITHOUT_UPPERLAYER_EVENT_FORWARDING)
         || (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_ACTIVE_HS_CLOSED))
    {
      /* TLS handshake is active - Upper layer MUST not be informed about received CLOSED event */
      /* Silently discard the event */
    }
    else
    {
      /* TLS connection is established - Upper layer should be informed about received CLOSED event */
      TcpIp_TlsCoreEvent_InformAboutTcpClosed(TlsConIdx);
    }
  }
  else
  {
    /* TLS-Client - Upper layer should be informed about received CLOSED event */
    TcpIp_TlsCoreEvent_InformAboutTcpClosed(TlsConIdx);
  }

  /* #20 TLS connection is CLOSED - Reset the connection and mark it as unused */
  TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CONNECTION_CLOSED);

  TcpIp_SizeOfSocketTcpDynType socketTcpIdx
    = TCPIP_SOCKET_IDX_TO_TCP_IDX(TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx));

  if (socketTcpIdx < TcpIp_GetSizeOfSocketTcpDyn())
  {
    TcpIp_SetTlsConnectionIdxOfSocketTcpDyn(socketTcpIdx, TCPIP_NO_TLSCONNECTIONIDXOFSOCKETTCPDYN);
  }
  else
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
  }

  TcpIp_TlsCore_ResetConnection(TlsConIdx);

  TCPIP_VLEAVE_CRITICAL_SECTION();

} /* TcpIp_TlsCoreEvent_TcpEventClosed() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreEvent_InformAboutTcpClosed
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreEvent_InformAboutTcpClosed(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfSocketDynType socketIdx
    = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_SizeOfSocketOwnerConfigType socketOwnerCfgIdx
    = TcpIp_GetSocketOwnerConfigIdxOfTlsConnectionDyn(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  if ((socketIdx < TcpIp_GetSizeOfSocketDyn()) && (socketOwnerCfgIdx < TcpIp_GetSizeOfSocketOwnerConfig()))
  {
    /* #10 TLS connection is established - Upper layer should be informed about received CLOSED event */
    TcpIp_Tls_TcpIpEventCallout(socketOwnerCfgIdx, socketIdx, IPBASE_TCP_EVENT_CLOSED);
  }
  else
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
  }
} /* TcpIp_TlsCoreEvent_InformAboutTcpClosed() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreEvent_TcpEventFinReceived
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreEvent_TcpEventFinReceived(
TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 TLS-Server/TLS-Client connection is already established - User should decide how to proceed */
  if ((TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx)) == (TCPIP_TLS_STATE_CONNECTION_ESTABLISHED))
  {
    /* TLS connections is already established, the user should decide how to proceed (either trigger FIN or RST) */
    TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CONNECTION_CLOSE_WAIT);
  }
  /* #20 TLS-Server/TLS-Client connection is already in correct state - Do nothing just wait */
             /* These states can be reached when we received a CloseNotify alert */
  else if (  (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_CLOSE_WAIT)           /* PRQA S 3415 17 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
          || (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_13_CLOSENOTIFY_RECEIVED)
# endif
             /* This state could be reached when TcpIp_Close(abort=True) is called shortly before receiving a FIN */
          || (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_USER_RESET_REQUESTED)
             /* These state could be reached when TcpIp_Close(abort=False) is called shortly before receiving a FIN */
          || (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_CLOSE_WITH_CLOSENOTIFY_FIN_REQUESTED)
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
          || (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_13_ACTIVE_CLOSE_REQUESTED)
# endif
             /* These states can be reached when we already received a fatal alert before receiving a FIN */
          || (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_GRACEFULLY_TCP_CLOSE_REQUESTED_WITHOUT_UPPERLAYER_EVENT_FORWARDING)
          || (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_STATE_CONNECTION_GRACEFULLY_TCP_CLOSE_REQUESTED)
          )
  {
  }
  /* #30 TLS-Server/TLS-Client handshake is active */
  else
  {
    if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
    {
      /* TLS-Server during handshake - Close the TCP connection, but do NOT inform the upper layer */
      TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx,
        TCPIP_TLS_STATE_CONNECTION_GRACEFULLY_TCP_CLOSE_REQUESTED_WITHOUT_UPPERLAYER_EVENT_FORWARDING);
    }
    else
    {
      /* TLS-Client during handshake - Close the TCP connection, and inform the upper layer */
      TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx,
        TCPIP_TLS_STATE_CONNECTION_GRACEFULLY_TCP_CLOSE_REQUESTED);
    }
  }


  /* #40 Check if the received FIN event should be forwarded to the upper layer */
  if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
  {
    if (   (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_CONNECTION_HS_ACTIVE)              /* PRQA S 3415 9 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
        && (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_CONNECTION_SERVER_HS_FINALIZING)
        && (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_CONNECTION_TCP_RESET_REQUESTED_WITHOUT_UPPERLAYER_EVENT_FORWARDING)
        && (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_CONNECTION_GRACEFULLY_TCP_CLOSE_REQUESTED_WITHOUT_UPPERLAYER_EVENT_FORWARDING)
        && (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_CONNECTION_CLOSING_WITHOUT_UPPERLAYER_EVENT_FORWARDING)
        && (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_CONNECTION_ACTIVE_HS_CANCLED)
        && (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_CONNECTION_ACTIVE_HS_CLOSED)
        /* For the state TCPIP_TLS_STATE_CONNECTION_GRACEFULLY_TCP_CLOSE_REQUESTED there is no need to forward the Fin received event,
         * since it was already manually triggered for the server in TcpIp_TlsCoreCtAl_HandleAllOtherAlerts(). */
        && (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_CONNECTION_GRACEFULLY_TCP_CLOSE_REQUESTED))
    {
      /* TLS Server should forward the event only if the connection is established */
      TcpIp_TlsCoreEvent_InformAboutTcpFin(TlsConIdx);
    }
    /* else - TLS handshake on Server active - Do not forward the event */
  }
  else
  {
    /* TLS Client should forward the event */
    TcpIp_TlsCoreEvent_InformAboutTcpFin(TlsConIdx);

    /* TLS-Alert will be raised - trigger TLS error indication with transmitted alert description */
    TcpIp_TlsCoreError_IndicationTrigger(TlsConIdx, TCPIP_TLS_E_SERVER_TERMINATED, TCPIP_TLS_ALERT_UNSET);
  }

} /* TcpIp_TlsCoreEvent_TcpEventFinReceived() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreEvent_InformAboutTcpFin
 *********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
  */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreEvent_InformAboutTcpFin(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfSocketDynType socketIdx
    = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);

  TcpIp_SizeOfSocketOwnerConfigType socketOwnerCfgIdx
    = TcpIp_GetSocketOwnerConfigIdxOfTlsConnectionDyn(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  if ((socketIdx < TcpIp_GetSizeOfSocketDyn()) && (socketOwnerCfgIdx < TcpIp_GetSizeOfSocketOwnerConfig()))
  {
    /* #10 TLS connection is established - Upper layer should be informed about received FIN event */
    TcpIp_Tls_TcpIpEventCallout(socketOwnerCfgIdx, socketIdx, IPBASE_TCP_EVENT_FIN_RECEIVED);
  }
  else
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
  }
} /* TcpIp_TlsCoreEvent_InformAboutTcpFin() */

/**********************************************************************************************************************
 *  TLS CONNECTION STATE HANDLER
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreConState_UserResetRequestedHandler
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
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreConState_UserResetRequestedHandler(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* Save the socket index in a local variable before it gets reset in TcpIp_TlsCore_ResetConnection(). */
  TcpIp_SocketDynComIdxOfTlsConnectionDynType socketIdx
    = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_SizeOfSocketTcpDynType socketTcpIdx = TCPIP_SOCKET_IDX_TO_TCP_IDX(socketIdx);


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if there is any async operation pending and no active AdRx Indication */
  if (   (   (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_NO_ASYNC)                          /* PRQA S 3415 3 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
          || (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_DONE))
      && (TcpIp_IsAdRxIndicationOfTlsConnectionDyn(TlsConIdx) == FALSE))
  {
    /* #20 No async operation pending - process the User RST */

    /* #30 Check if the upper layer (User) wants to RST the connection */
    /* TcpIp_Close(Abort=TRUE) on active TLS connection, either TLS-Server or TLS-Client */
    if ((TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx)) == (TCPIP_TLS_STATE_CONNECTION_USER_RESET_REQUESTED))
    {
      /* #40 Handle upper layer (User) RST on active TLS connection, reset the TLS connection and close the TCP socket */
      /* We have to wait until the RST is sent (and then get informed by Tcp) via event forwarding */
      TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CONNECTION_USER_RESET_WAIT);

      TcpIp_TlsCore_ResetConnection(TlsConIdx);

      /* TLS connection already reset, so TCP will handle the RST and forward the event to the upper layer */
      /* Remove the mapping between TLS and TCP */
      TcpIp_TlsCoreConState_ForwardCloseToTcp(socketTcpIdx, TRUE, TRUE);
    }

    /* #50 Process forwarding of TLS handshake cancellation (RST) from TLS-Listener */
    /* TcpIp_Close(Abort=TRUE) on active TLS handshake, TLS-Server */
    else if ((TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx)) == (TCPIP_TLS_STATE_CONNECTION_ACTIVE_HS_CANCLED))
    {
      /* #60 TLS handshake active - Close the TCP socket with RST */
      TcpIp_TlsCoreConState_ForwardCloseToTcp(socketTcpIdx, TRUE, FALSE);
    }
    /* #70 Process forwarding of TLS handshake closing (FIN) from TLS-Listener */
    /* TcpIp_Close(Abort=FALSE) on active TLS handshake, TLS-Server */
    else if ((TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx)) == (TCPIP_TLS_STATE_CONNECTION_ACTIVE_HS_CLOSED))
    {
      /* #80 TLS handshake active - Close the TCP socket with FIN */
      TcpIp_TlsCoreConState_ForwardCloseToTcp(socketTcpIdx, FALSE, FALSE);
    }
    else
    {
      /* nothing to do - left blank intentionally */
    }
  } /* else - Async operation pending. Do nothing, just wait one cycle */
} /* TcpIp_TlsCoreConState_UserResetRequestedHandler() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreConState_UserCloseRequestedHandler
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreConState_UserCloseRequestedHandler(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if there is no active AdRxIndication */
  if (TcpIp_IsAdRxIndicationOfTlsConnectionDyn(TlsConIdx) == FALSE)
  {
    /* RFC5246 chapter 7.2.1 / RFC8446 chapter 6.1 states:
     * "It is assumed that closing (the write side of) a connection reliably delivers pending data before destroying the transport."
     * Therefore do not trigger a close_notify if the transmit of the pending data is not completed.
     * New data however cannot be requested, the fill level does not increase from now on.
     * This is ensured in TcpIp_TlsCoreUl_Transmit(). */
    /* #20 Check if there is no pending data to be send. */
    if (TcpIp_GetAdTxFillLevelOfTlsBufferMgmtDyn(TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx)) == 0u)
    {
      /* #30 Check if we should trigger the transmit of the CloseNotify */
      if ((TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx)) == (TCPIP_TLS_STATE_CONNECTION_CLOSE_WITH_CLOSENOTIFY_FIN_REQUESTED))
      {
        /* #40 Trigger a CloseNotify alert and set the connection state to TCPIP_TLS_STATE_CONNECTION_CLOSENOTIFY_WAIT */
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_WARNING, TCPIP_TLS_ALERT_DESC_CLOSE_NOTIFY);

        /* State TCPIP_TLS_STATE_CONNECTION_CLOSENOTIFY_WAIT is used to transmit the CloseNotify Alert (in MainFunction_TxAl).
         * After the transmit, the state is changed to CLOSE_REQUESTED, where the FIN is triggered. */
        TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CONNECTION_CLOSENOTIFY_WAIT);
      }
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      else if ((TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx)) == (TCPIP_TLS_STATE_CONNECTION_13_ACTIVE_CLOSE_REQUESTED))
      {
        /* #50 Trigger a CloseNotify alert */
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_WARNING, TCPIP_TLS_ALERT_DESC_CLOSE_NOTIFY);
      }
# endif
      else
      {
        /* Nothing to do here */
      }
    }
  }
} /* TcpIp_TlsCoreConState_UserCloseRequestedHandler() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreConState_ForwardCloseToTcp
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreConState_ForwardCloseToTcp(
  TcpIp_SizeOfSocketTcpDynType SocketTcpIdx,
  boolean                      Abort,
  boolean                      RemoveTlsSocketInfo)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  if (SocketTcpIdx < TcpIp_GetSizeOfSocketTcpDyn())
  {
    /* #10 Forward the CLOSE request to the TCP module. */
    TcpIp_CloseTcpSocketFromTls(SocketTcpIdx, Abort);

    if (RemoveTlsSocketInfo == TRUE)
    {
      /* Remove the mapping between TCP socket and TLS connection. */
      TcpIp_SetTlsConnectionIdxOfSocketTcpDyn(SocketTcpIdx, TCPIP_NO_TLSCONNECTIONIDXOFSOCKETTCPDYN);
    }
    /* else - Mapping remains */
  }
  else
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
  }
} /* TcpIp_TlsCoreConState_ForwardCloseToTcp() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreConState_TcpCloseRequestedHandler
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreConState_TcpCloseRequestedHandler(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 TLS connection closing WITH upper layer information */
  if ((TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx)) == (TCPIP_TLS_STATE_CONNECTION_GRACEFULLY_TCP_CLOSE_REQUESTED))
  {
    /* #20 Check if there is any async operation pending and handle the close request */
    if (   (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_NO_ASYNC)                            /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
        || (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_DONE))
    {

      /* Call close for corresponding underlying TCP socket */
      TcpIp_Tls_CloseInternal(TlsConIdx);

      /* Reset of the connection is done when the CLOSED event is received */
      /* Finally set the connection state to CLOSING */
      TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CONNECTION_CLOSING);
    }
    else
    {
      /* #30 An async operation is pending, wait for this function to finish */
    }
  }

  /* #40 TLS connection closing WITHOUT upper layer information (TLS-Server during handshake) */
  else if (    (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx))
            == (TCPIP_TLS_STATE_CONNECTION_GRACEFULLY_TCP_CLOSE_REQUESTED_WITHOUT_UPPERLAYER_EVENT_FORWARDING))
  {
    /* #50 Check if there is any async operation pending and handle the close request */
    if (    (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_NO_ASYNC)                           /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
         || (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_DONE))
    {

      /* Call close for corresponding underlying TCP socket */
      TcpIp_Tls_CloseInternal(TlsConIdx);

      /* Finally set the connection state to CLOSING but do not forward the Event to the upper layer */
      TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx,
        TCPIP_TLS_STATE_CONNECTION_CLOSING_WITHOUT_UPPERLAYER_EVENT_FORWARDING);
    }
    else
    {
      /* #60 An async operation is pending, wait for this function to finish */
    }
  }
  else
  {
    /* nothing to do - left blank intentionally */
  }
} /* TcpIp_TlsCoreConState_TcpCloseRequestedHandler() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreConState_TcpResetRequestedHandler
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
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreConState_TcpResetRequestedHandler(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if there is any async operation pending */
  if (   (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_NO_ASYNC)                              /* PRQA S 3415 2 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
      || (TcpIp_GetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CTX_DONE))
  {
    /* #20 No async operation pending - process the RST */

    /* #30 Check if the RST event should be forwarded to the upper layer */
    if ((TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx)) == (TCPIP_TLS_STATE_CONNECTION_TCP_RESET_REQUESTED))
    {
      /* #40 Upper layer should be informed - Reset the connection, trigger event callout function and set the connection state to CLOSED */
      TcpIp_SizeOfSocketDynType socketIdx
      = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);

      TcpIp_SizeOfSocketOwnerConfigType socketOwnerCfgIdx
      = TcpIp_GetSocketOwnerConfigIdxOfTlsConnectionDyn(TlsConIdx);

      TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CONNECTION_CLOSED);

      /* Reset the TLS connection */
      TcpIp_TlsCore_ResetConnection(TlsConIdx);

      if ((socketIdx < TcpIp_GetSizeOfSocketDyn()) && (socketOwnerCfgIdx < TcpIp_GetSizeOfSocketOwnerConfig()))
      {
        /* Inform <UpperLayer> Socket Owner over RST event */
        TcpIp_Tls_TcpIpEventCallout(socketOwnerCfgIdx, socketIdx, IPBASE_TCP_EVENT_RESET);
      }
      else
      {
        /* Memory runtime check fails - report DET */
        TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
      }
    }
    else if (   (TcpIp_GetConnectionStateOfTlsConnectionDyn(TlsConIdx))
             == (TCPIP_TLS_STATE_CONNECTION_TCP_RESET_REQUESTED_WITHOUT_UPPERLAYER_EVENT_FORWARDING))
    {
      /* #50 Upper layer should NOT be informed (TLS-Server during handshake) - Reset the connection and set the connection state to CLOSED */
      TcpIp_SetConnectionStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_CONNECTION_CLOSED);

      /* Reset the TLS connection */
      TcpIp_TlsCore_ResetConnection(TlsConIdx);
    }
    else
    {
      /* nothing to do - left blank intentionally */
    }
  } /* else - Async operation pending. Do nothing, just wait one cycle */
} /* TcpIp_TlsCoreConState_TcpResetRequestedHandler() */

/**********************************************************************************************************************
 *  TLS CORE ERROR
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreError_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreError_Init(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Call function to clear User error buffer. */
  TcpIp_TlsCoreError_ClearUserError(TlsConIdx);

} /* TcpIp_TlsCoreError_Init() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreError_GetUserError
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
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreError_GetUserError(
  TcpIp_TlsConnectionIterType        TlsConIdx,
  TCPIP_P2V(TcpIp_TlsUserErrorType)  UserErrorMemoryPtr,
  TCPIP_P2V(uint32)                  NumOfUserErrorPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsUserErrorBufferIterType tlsUserErrorBufferIdx;
  TcpIp_TlsUserErrorBufferIterType writeErrorBufferIdx = 0;
  uint32 userErrorsToBeRead;
  TCPIP_P2C(TcpIp_TlsUserErrorType) userErrorBufferPtr;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Verify if user error reporting is configured. */
  if (TcpIp_GetTlsUserErrorCalloutFunctionOfTlsConfig(TCPIP_TLSCONFIG_IDX) != NULL_PTR)
  {
    /* #20 Calculate length of buffer. */
    userErrorsToBeRead = ((uint32)TcpIp_GetTlsUserErrorBufferWriteIdxOfTlsConnectionDyn(TlsConIdx)
      - TcpIp_GetTlsUserErrorBufferStartIdxOfTlsConnection(TlsConIdx));
    /* #30 Verify the number of user error entries that should be read. */
    if (*NumOfUserErrorPtr < userErrorsToBeRead)
    {
      /* Only a part of the user errors can be read, since not enough buffer is provided by the requester. */
      userErrorsToBeRead = *NumOfUserErrorPtr;
    }
    else
    {
      *NumOfUserErrorPtr = userErrorsToBeRead;
    }
    /* #40 Write User error entries into the given user buffer. */
    for (tlsUserErrorBufferIdx = TcpIp_GetTlsUserErrorBufferStartIdxOfTlsConnection(TlsConIdx);
         tlsUserErrorBufferIdx < (TcpIp_GetTlsUserErrorBufferStartIdxOfTlsConnection(TlsConIdx) + userErrorsToBeRead);
         tlsUserErrorBufferIdx++)
    {
      userErrorBufferPtr = TcpIp_GetAddrTlsUserErrorBuffer(tlsUserErrorBufferIdx);

      UserErrorMemoryPtr[writeErrorBufferIdx].FunctionId = userErrorBufferPtr->FunctionId;
      UserErrorMemoryPtr[writeErrorBufferIdx].UserErrorId = userErrorBufferPtr->UserErrorId;
      writeErrorBufferIdx++;
    }
    /* #50 Clear the whole buffer. */
    TcpIp_TlsCoreError_ClearUserError(TlsConIdx);
    retVal = E_OK;
  }


  return retVal;
} /* TcpIp_TlsCoreError_GetUserError() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreError_ClearUserError
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
*/
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreError_ClearUserError(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsUserErrorBufferPtrType userErrorEntryPtr;
  TcpIp_TlsUserErrorBufferIterType tlsUserErrorBufferIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over whole user error buffer and clear each element of the buffer. */
  for (tlsUserErrorBufferIdx = TcpIp_GetTlsUserErrorBufferStartIdxOfTlsConnection(TlsConIdx);
       tlsUserErrorBufferIdx < TcpIp_GetTlsUserErrorBufferEndIdxOfTlsConnection(TlsConIdx);
       tlsUserErrorBufferIdx++)
  {
    userErrorEntryPtr = TcpIp_GetAddrTlsUserErrorBuffer(tlsUserErrorBufferIdx);

    userErrorEntryPtr->FunctionId = 0;
    userErrorEntryPtr->UserErrorId = 0;
  }
  /* #20 Clear Write index of User error buffer. */
  TcpIp_SetTlsUserErrorBufferWriteIdxOfTlsConnectionDyn(TlsConIdx, TcpIp_GetTlsUserErrorBufferStartIdxOfTlsConnection(TlsConIdx));
} /* TcpIp_TlsCoreError_ClearUserError() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreError_ReportUserError
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
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreError_ReportUserError(
  CONST(TcpIp_TlsUserErrorType, AUTOMATIC) UserError)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsConnectionIterType tlsConIdx;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Enter critical section */
  TCPIP_VENTER_CRITICAL_SECTION();

  tlsConIdx = TCPIP_TLS_CONNECTION_ID_TO_IDX(UserError.TlsConId);
  /* #20 Verify if User Error Reporting is configured. */
  if (TcpIp_GetTlsUserErrorCalloutFunctionOfTlsConfig(TCPIP_TLSCONFIG_IDX) != NULL_PTR)
  {
    /* #30 Verify if buffer is full. */
    if (   TcpIp_GetTlsUserErrorBufferWriteIdxOfTlsConnectionDyn(tlsConIdx)
        == TcpIp_GetTlsUserErrorBufferEndIdxOfTlsConnection(tlsConIdx))
    {
      /* Error buffer is full, just return */
    }
    /* #40 Otherwise: Write User error into Buffer. */
    else
    {
      TcpIp_TlsUserErrorBufferWriteIdxOfTlsConnectionDynType wrtiteTlsUserErrorBufferIdx = TcpIp_GetTlsUserErrorBufferWriteIdxOfTlsConnectionDyn(tlsConIdx);
      if (wrtiteTlsUserErrorBufferIdx < TcpIp_GetSizeOfTlsUserErrorBuffer())
      {
        TcpIp_SetTlsUserErrorBuffer(wrtiteTlsUserErrorBufferIdx, UserError);
        TcpIp_IncTlsUserErrorBufferWriteIdxOfTlsConnectionDyn(tlsConIdx);
      }
      CANOE_WRITE_STRING_3("[User Error Report] FunctionId: 0x%x - ErrorId: 0x%x - TlsConIdx: %d", UserError.FunctionId,
                           UserError.UserErrorId, TCPIP_TLS_CONNECTION_ID_TO_IDX(UserError.TlsConId));
    }
  }

  /* #50 Leave critical section */
  TCPIP_VLEAVE_CRITICAL_SECTION();

} /* TcpIp_TlsCoreError_ReportUserError() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreError_UserErrorCallout
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreError_UserErrorCallout(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsUserErrorCalloutFunctionType funcPtr;
  TcpIp_SizeOfTlsUserErrorBufferType userErrorCnt;

  /* ----- Implementation ----------------------------------------------- */
  funcPtr = TcpIp_GetTlsUserErrorCalloutFunctionOfTlsConfig(TCPIP_TLSCONFIG_IDX);

  /* #10 Calculate the number of user error entries saved in user error buffer. */
  userErrorCnt = (TcpIp_GetTlsUserErrorBufferWriteIdxOfTlsConnectionDyn(TlsConIdx)
                  - TcpIp_GetTlsUserErrorBufferStartIdxOfTlsConnection(TlsConIdx));
  /* #20 Notify upper layer to read user errors saved in user error buffer, if callout is configured. */
  if (funcPtr != NULL_PTR)
  {
    funcPtr((uint32) TlsConIdx, userErrorCnt);
  }
} /* TcpIp_TlsCoreError_UserErrorCallout() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreError_IndicationTrigger
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreError_IndicationTrigger(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_Tls_ErrorIndicationType ErrorIndication,
  TcpIp_TlsAlertDescriptionType AlertDescription)
{
  /* #10 Check if the TLS error indication is enabled in this configuration */
# if (TCPIP_SUPPORT_ASRTLS_ERROR_INDICATION == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SocketDynIterType socketIdx = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_SocketIdType socketId = TCPIP_SOCKET_IDX_TO_ID(socketIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 TLS error indication enabled - forward information to callout function */
  TcpIp_Tls_ErrorIndicationCalloutFunction(socketId, ErrorIndication, AlertDescription);

# else
  /* #30 TLS error indication is disabled in this configuration - Avoid compiler warnings. */
  TCPIP_DUMMY_STATEMENT_CONST(TlsConIdx);                                                                               /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
  TCPIP_DUMMY_STATEMENT_CONST(ErrorIndication);                                                                         /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
  TCPIP_DUMMY_STATEMENT_CONST(AlertDescription);                                                                        /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */

# endif /* TCPIP_SUPPORT_ASRTLS_ERROR_INDICATION == STD_ON */
} /* TcpIp_TlsCoreError_IndicationTrigger() */

/**********************************************************************************************************************
 *  TLS CORE CRYPTO
 *********************************************************************************************************************/
# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)                                                                               /* COV_MSR_UNSUPPORTED */
/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtx_CalcDiffieHellmanPublicKey
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
 *
 */
/* PRQA S 6050, 6080 1 */ /* MD_TcpIp_STCAL_CslAccess, MD_TcpIp_TlsRuntimecheck_STMIF_6080 */
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreCtx_CalcDiffieHellmanPublicKey(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsHandshakeIterType  TlsHandshakeIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  Std_ReturnType retVal = E_NOT_OK;
  uint16 localErrorId = TCPIP_TLS_ERRORID_NOT_SET;                                                                      /* PRQA S 2981 */ /* MD_TCPIP_Rule2.2_RedundantAssignment */
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the Csm key for the Key Exchange operation is configured */
  if (TcpIp_IsCsmKeyIdKeyExchangeUsedOfTlsHandshake(TlsHandshakeIdx) == TRUE)
  {
    uint32 keyExchangePubKeyLen;
    uint32 keyExchangeCsmKey = TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdKeyExchangeIdxOfTlsHandshake(TlsHandshakeIdx));
    TcpIp_SizeOfTlsBufferTxType writeIdx = TcpIp_GetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

    /* #20 Get the available space in the TX buffer */
    keyExchangePubKeyLen = (uint32)TcpIp_GetTlsBufferTxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx) - writeIdx;

    /* #30 Set the current key valid */
    if (TCPIP_CSM_KeySetValid(keyExchangeCsmKey) == E_OK)
    {
      /* #40 Calculate the Diffie-Hellman public key and write it directly into the TX buffer */
      if (TcpIp_TlsCoreCrypto_KeyExchangeCalcPubValSafe(keyExchangeCsmKey,
        writeIdx, &keyExchangePubKeyLen) == E_OK)
      {
        /* #50 CSM call OK, check the length of the new calculated public key to match the expected key length for the used curve */
        if (keyExchangePubKeyLen == TcpIp_TlsMsg_GetLenOfCurveSpecificPubKey(TcpIp_GetEllipticCurveIdOfTlsHandshake(TlsHandshakeIdx)))
        {
          /* Increment the write index by the consumed length  */
          TcpIp_SetTlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
            (TcpIp_TlsBufferTxAdHsWriteIdxOfTlsBufferMgmtDynType)(writeIdx + keyExchangePubKeyLen));

          /* #60 key have the expected length */
          retVal = E_OK;
        }
        else
        {
          /* #70 Error Public key length mismatch */
          localErrorId = TCPIP_TLS_ERRORID_CRYPTO_CSM_LEN_MISMATCH;
        }
      }
      else
      {
        /* #80 Error Crypto CSM call failed */
        localErrorId = TCPIP_TLS_ERRORID_CRYPTO_CSM_CALL_FAILED;
      }
    }
    else
    {
      /* #90 Error Crypt CSM Key set valid failed */
      localErrorId = TCPIP_TLS_ERRORID_CRYPTO_SET_VALID_FAILED;
    }

    /* #100 If all sub-functions returned E_OK */
    if (retVal == E_OK)
    {
      /* #110 Set the async state to DONE */
      TcpIp_SetHsAsyncCtxStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_CTX_DONE);
    }
    else
    {
      /* #120 otherwise, handles error while async CSM processing */
      TcpIp_TlsAsyncCtx_HandleErrorDuringAsyncJobProcessing(TlsConIdx, TCPIP_TLS_FCTID_CORE_ASYNCCTX_CALC_DH_PUBKEY, localErrorId);
    }
  }
  else
  {
    /* #130 Csm Key for KeyExchange operation is not configured - invalid configuration */
    TcpIp_TlsCoreUtil_HandleInvalidConfiguration(TlsConIdx);
  }
} /* TcpIp_TlsCoreCtx_CalcDiffieHellmanPublicKey() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCrypto_KeyExchangeCalcPubValSafe
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCrypto_KeyExchangeCalcPubValSafe(
  uint32            KeyId,
  uint32            WriteIdx,
  TCPIP_P2V(uint32) ResultLengthPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
#  if ( TCPIP_DEV_ERROR_DETECT == STD_ON )
  /* #10 Verify that WriteIdx and ResultLengthPtr are in range of the Tls Tx buffer. */
  /* \trace TCASE-TCPIP_000732 */
  if ((WriteIdx + (uint64)(*ResultLengthPtr)) > TcpIp_GetSizeOfTlsBufferTx())
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
  }
  else
#  endif
  {
    TCPIP_P2V(uint8) resultPtr = TcpIp_GetAddrTlsBufferTx((TcpIp_TlsBufferTxIterType)WriteIdx);

    /* #20 Calculate the Diffie-Hellman public key and write it directly into the TX buffer. */
    retVal = TCPIP_CSM_KeyExchangeCalcPubVal(KeyId, resultPtr, ResultLengthPtr);                                        /* VCA_TCPIP_TLS_CSM_KEY_EXCHANGE_CSL01 */
  }

  return retVal;
} /* TcpIp_TlsCoreCrypto_KeyExchangeCalcPubValSafe() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtx_AsyncHandler
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsCoreCtx_CheckCalcDhSharedSecretPrecondition(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  boolean dhPreconditionFullfilled = FALSE;                                                                             /* PRQA S 2981 */ /* MD_TCPIP_Rule2.2_RedundantAssignment */

  /* #10 Check connection mode */
#  if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
    if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
#   endif
    {
      /* Mode == TCPIP_TLS_SERVER */
      /* #20 In case of an TLS-Server, no additional preconditions must be checked */
      dhPreconditionFullfilled = TRUE;
    }
#   if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
    else
#   endif
#  endif
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
    {
      /* Mode == TCPIP_TLS_CLIENT */
      /* #30 In case of an TLS-Client and the ECDH key exchange we must check the status of the received server certificate
       * that contains the public key which is needed for the next calculation */
      if (TcpIp_TlsClientHsStm_ReturnReceivedCipherSpecificKeyExchangeMethod(TlsConIdx)
            == TCPIP_TLS_KEYEXCHANGE_METHOD_ECDH)
      {
        /* [HS Server Certificate Chain Handling StM] Cert chain processing is completed, proceed with further steps */
        if (TcpIp_GetHsCertStateOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLS_CERTCHAIN_COMPLETE)
        {

          dhPreconditionFullfilled = TRUE;
        }
        /* else - received Server certificate is not ready. Wait for next cycle */
      }
      else
      {
        /* All other key exchange methods - no further preconditions */
        dhPreconditionFullfilled = TRUE;
      }
    }
#  endif
#  if ((TCPIP_SUPPORT_ASRTLSSERVER == STD_ON) && (TCPIP_SUPPORT_ASRTLSCLIENT == STD_OFF))
    TCPIP_DUMMY_STATEMENT_CONST(TlsConIdx);                                                                             /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
#  endif

    return dhPreconditionFullfilled;
} /* TcpIp_TlsCoreCtx_AsyncHandler() */
# endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCrypto_DeleteCsmKeyElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCrypto_DeleteCsmKeyElement(
  TcpIp_CsmKeyIdType csmKeyId,
  uint32 csmKeyElementId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  CONST(uint8, TCPIP_CONST) dummyValue[1] = { 0u };
  uint8 dummyLen = 1u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set first byte of key element to 0x00 and set key to valid to persist change */
  retVal = TcpIp_TlsCoreCrypto_SetCsmKeyElementAndSetKeyValid(csmKeyId, csmKeyElementId, dummyValue, dummyLen);
  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCrypto_SetCsmKeyElementAndSetKeyValid
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCrypto_SetCsmKeyElementAndSetKeyValid(
  uint32               KeyId,
  uint32               ElementId,
  TCPIP_P2C(uint8)     KeyElementPtr,
  uint32               KeyElementLength)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Set the key element to the passed bytes in KeyElementPtr.*/
  Std_ReturnType csmRetVal = TCPIP_CSM_KeyElementSet(
    KeyId,
    ElementId,
    KeyElementPtr,
    KeyElementLength);

  if (csmRetVal == E_OK)
  {
    /* #20 Set the key valid. */
    csmRetVal = TCPIP_CSM_KeySetValid(KeyId);
  }

  if (csmRetVal == E_OK)
  {
    retVal = E_OK;
  }

  return retVal;
} /* TcpIp_TlsCoreCrypto_SetCsmKeyElementAndSetKeyValid() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCrypto_ClearCsmKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCrypto_ClearCsmKey(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TCPIP_P2C(TcpIp_TlsCsmKeyInfoType) KeyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmRetVal;
  Std_ReturnType retVal;
  uint8 dummyBuffer = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Clear the given CSM Key */
  /* Set first byte of the key to 0. This is required because TCPIP_CSM_KeyElementCopyPartial does not shorten the
   * length of the destination key, it can only increment it.
   */
  csmRetVal  = TcpIp_TlsCoreCrypto_SetCsmKeyElementAndSetKeyValid(KeyPtr->KeyId, KeyPtr->KeyElementId, &dummyBuffer, 1u);

  /* #20 Check if the result of the CSM operation is E_OK */
  retVal = TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, 0, 0, TCPIP_TLS_FCTID_CORE_CRYPTO_CLEARCSMKEY);

  if (retVal != E_OK)
  {
    /* #30 if not so, report the user error */
    TcpIp_TlsUserErrorType userError;

    userError.FunctionId = TCPIP_TLS_FCTID_CORE_CRYPTO_CLEARCSMKEY;
    userError.UserErrorId = TCPIP_TLS_ERRORID_CRYPTO_CLEARCSMKEY_FAILED;
    userError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);
    TcpIp_TlsCoreError_ReportUserError(userError);
  }

  return retVal;
} /* TcpIp_TlsCoreCrypto_ClearCsmKey() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCrypto_AEADDecryptFromConstSegmentSafe
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6060 1 */ /* MD_TcpIp_WrapperFunction_STPAR_6060 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCrypto_AEADDecryptFromConstSegmentSafe(
  uint32                              JobId,
  Crypto_OperationModeType            Mode,
  TcpIp_ConstSegmentPtrType           CiphertextSegPtr,
  uint32                              CiphertextLength,
  TCPIP_P2C(uint8)                    AssociatedDataPtr,
  uint32                              AssociatedDataLength,
  TCPIP_P2C(uint8)                    TagPtr,
  uint32                              TagLength,
  uint32                              WriteIdx,
  TCPIP_P2V(uint32)                   ResultLengthPtr,
  TCPIP_P2V(Crypto_VerifyResultType)  VerifyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
# if ( TCPIP_DEV_ERROR_DETECT == STD_ON )
  /* #10 Verify that ciphertext segment has enough space for the ciphertext length. */
  if (CiphertextSegPtr->AvailLen < CiphertextLength)
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
  }
  else
# endif
  {
    /* #20 Decrypt the data with a range check that we will only write into the TLS Rx buffer. */
    TCPIP_P2C(uint8) cipherPtr = CiphertextSegPtr->AvailPtr;
    CONST(uint8, AUTOMATIC) dummyData = 0u;

    if (CiphertextLength == 0u) /* For no data 'cipherPtr == NULL_PTR' must be true. */
    {
      /* CSM can not handle a NULL_PTR with length 0.
       * Point to local dummy data instead which will not be used since the length remains 0. */
      cipherPtr = &dummyData;
    }

    retVal = TcpIp_TlsCoreCrypto_AEADDecryptSafe(JobId, Mode,
               cipherPtr, CiphertextLength,
               AssociatedDataPtr, AssociatedDataLength,
               TagPtr, TagLength,
               WriteIdx, ResultLengthPtr,
               VerifyPtr);

    if ((retVal == E_OK) && (*VerifyPtr == CSM_E_VER_OK))
    {
      /* If decryption was successful commit the read length into the const segment. */
      TcpIp_ConstSegmentCommit(CiphertextSegPtr, CiphertextLength);
    }
  }

  return retVal;
} /* TcpIp_TlsCoreCrypto_AEADDecryptFromConstSegmentSafe() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCrypto_AEADDecryptSafe
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6060 1 */ /* MD_TcpIp_WrapperFunction_STPAR_6060 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCrypto_AEADDecryptSafe(
  uint32                   JobId,
  Crypto_OperationModeType Mode,
  TCPIP_P2C(uint8)         CiphertextPtr,
  uint32                   CiphertextLength,
  TCPIP_P2C(uint8)         AssociatedDataPtr,
  uint32                   AssociatedDataLength,
  TCPIP_P2C(uint8)         TagPtr,
  uint32                   TagLength,
  uint32                   WriteIdx,
  TCPIP_P2V(uint32)        ResultLengthPtr,
  TCPIP_P2V(Crypto_VerifyResultType) VerifyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
# if ( TCPIP_DEV_ERROR_DETECT == STD_ON )
  /* #10 Verify that WriteIdx and ResultLengthPtr are in range of the Tls Rx buffer. */
  /* \trace TCASE-TCPIP_000730 */
  if ((WriteIdx + (uint64)(*ResultLengthPtr)) > TcpIp_GetSizeOfTlsBufferRx())
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
  }
  else
# endif
  {
    TCPIP_P2V(uint8) resultPtr = TcpIp_GetAddrTlsBufferRx((TcpIp_TlsBufferRxIterType)WriteIdx);
    /* #20 Decrypt the data in the provided buffer using Block128. */
    retVal = TCPIP_CSM_AEADDecrypt(JobId, Mode,                                                                         /* VCA_TCPIP_TLS_CSM_AEAD_DECRYPT_CSL01 */
               CiphertextPtr, CiphertextLength,
               AssociatedDataPtr, AssociatedDataLength,
               TagPtr, TagLength,
               resultPtr, ResultLengthPtr,
               VerifyPtr);
  }

  return retVal;
} /* TcpIp_TlsCoreCrypto_AEADDecryptSafe() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCrypto_MacGenerateSafe
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6060 1 */ /* MD_TcpIp_TlsPointerAndLength_STPAR_6060 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCrypto_MacGenerateSafe(
  uint32                   JobId,
  Crypto_OperationModeType Mode,
  TCPIP_P2C(uint8)         DataPtr,
  uint32                   DataLength,
  uint32                   WriteIdx,
  TCPIP_P2V(uint32)        ResultLengthPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
# if ( TCPIP_DEV_ERROR_DETECT == STD_ON )
  /* #10 Verify that WriteIdx and ResultLengthPtr are in range of the Tls Rx buffer. */
  /* \trace TCASE-TCPIP_000734 */
  if ((WriteIdx + (uint64)(*ResultLengthPtr)) > TcpIp_GetSizeOfTlsTemporaryHmacBuffer())
  {
    /* Memory runtime check fails - report DET */
    TcpIp_Tls_CallDetReportError(TCPIP_TLS_API_ID_TLS_DATA_PROCESSING, TCPIP_TLS_E_INV_RUNTIME_CHECK);
  }
  else
# endif
  {
    TCPIP_P2V(uint8) resultPtr = TcpIp_GetAddrTlsTemporaryHmacBuffer((TcpIp_TlsTemporaryHmacBufferIterType)WriteIdx);

    /* Perform a MAC generation and stores the MAC in the temporary Hmac buffer. */
    retVal = TCPIP_CSM_MacGenerate(JobId, Mode, DataPtr, DataLength,                                                    /* VCA_TCPIP_TLS_CSM_MAC_GENERATE_CSL01 */
      resultPtr, ResultLengthPtr);
  }

  return retVal;
} /* TcpIp_TlsCoreCrypto_MacGenerateSafe() */

/**********************************************************************************************************************
 *  TLS CORE ALERT
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreAlert_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreAlert_Init(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize the Alert layer */
  TcpIp_SetTxCloseNotifyTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);
  TcpIp_SetTxAlertTriggerOfTlsConnectionDyn(TlsConIdx, FALSE);
} /* TcpIp_TlsCoreAlert_Init() */

/**********************************************************************************************************************
 *  TLS CORE LOWER LAYER (LL)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreLl_RxIndication
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreLl_RxIndication(
  TcpIp_SizeOfSocketTcpDynType SocketTcpIdx,
  TCPIP_P2V(uint8) DataPtr,
  uint16           DataLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = TCPIP_TLS_E_NO_ERROR;
  TcpIp_TlsConnectionIterType tlsConIdx = TcpIp_GetSizeOfTlsConnection();
  TcpIp_SizeOfSocketDynType socketIdx = TCPIP_TCP_IDX_TO_SOCKET_IDX(SocketTcpIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the corresponding TLS-Connection index to the given TCP socket */
  if ((TcpIp_SocketIdxToTlsConIdx(socketIdx, &tlsConIdx) == E_OK) && (tlsConIdx < TcpIp_GetSizeOfTlsConnection()))
  {
    TcpIp_TlsBufferMgmtIdxOfTlsConnectionType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(tlsConIdx);

    /* #20 Add the data to the RxBufStruct of this TLS-Connection */
    if (TcpIp_TlsCoreRxBufStruct_WriteSegment(tlsBufferMgmtIdx, DataPtr, DataLen) != E_OK)
    {
      errorId = TCPIP_TLS_E_NO_BUF;
    }
  }

  /* ----- Development Error Report ------------------------------------- */
# if (TCPIP_DEV_ERROR_REPORT == STD_ON)
  /* #30 Report an error if necessary. */
  if (errorId != TCPIP_TLS_E_NO_ERROR)
  {
    (void)Det_ReportError(TCPIP_MODULE_ID, TCPIP_TLS_VINSTANCE_ID, TCPIP_TLS_API_ID_RX_INDICATION, errorId);
  }
# else
  TCPIP_DUMMY_STATEMENT(errorId);                                                                                       /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
# endif /* TCPIP_DEV_ERROR_REPORT */
} /* TcpIp_TlsCoreLl_RxIndication() */

# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreLl_TcpConnected
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreLl_TcpConnected(
  TcpIp_SizeOfSocketDynType      SocketIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SocketOwnerConfigIdxOfSocketDynType socketOwnerCfgIdx = TcpIp_GetSocketOwnerConfigIdxOfSocketDyn(SocketIdx);
  TcpIp_TlsConnectionIterType tlsConIdx;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all client connections and find the one that is assigned to the current socket. There always is a connection that is assigned. */
  /* Iterate over all configured TLS-Connections */
  for (tlsConIdx = 0; tlsConIdx < TcpIp_GetSizeOfTlsConnection(); tlsConIdx++)
  {
    /* Check if connection is configured as TLS-Client */
    if (TcpIp_GetModeOfTlsConnection(tlsConIdx) == TCPIP_TLS_CLIENT)
    {
      /* Check if the connection is already assigned to the current socket. */
      if (TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(tlsConIdx) == SocketIdx)
      {
        /* OK, matching connection found */
        retVal = E_OK;
        break;  /* stop the for-loop */
      }
    }
  }

  /* #20 Fully allocate the connection to the socket if a matching connection was found. */
  if (retVal == E_OK)
  {
    /* Set the socket owner index of this connection */
    TcpIp_SetSocketOwnerConfigIdxOfTlsConnectionDyn(tlsConIdx, socketOwnerCfgIdx);
    /* Set the Connection State for this connection */
    TcpIp_SetConnectionStateOfTlsConnectionDyn(tlsConIdx, TCPIP_TLS_STATE_CONNECTION_HS_ACTIVE);

    /* Set the TLS Handshake State for this connection */
    TcpIp_SetHandshakeStateOfTlsConnectionDyn(tlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_INIT);

    /* Set the Transmission Required flag */
    TcpIp_SetHsStmTxTriggerOfTlsConnectionDyn(tlsConIdx, TRUE);

    retVal = E_OK;
  }

  return retVal;
} /* TcpIp_TlsCoreLl_TcpConnected() */
# endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */

/**********************************************************************************************************************
 *  TLS CORE UTIL  (HELPER FUNCTIONS)
 *********************************************************************************************************************/
# if (TCPIP_SUPPORT_ASRTLSSERVER == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_IsUlEventForwardingNeededDuringClosing
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, TCPIP_CODE)  TcpIp_TlsCoreUtil_IsUlEventForwardingNeededDuringClosing(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = TRUE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if TLS should forward an event to the upper layer during closing a connection. */
  if (   (TcpIp_GetHandshakeStateOfTlsConnectionDyn(TlsConIdx) != TCPIP_TLS_STATE_HANDSHAKE_DONE)
#  if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
      && (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)                                                  /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_CslReadOnly */
#  endif
    )
  {
    /* TLS-Server during handshake --> upper layer must not be informed about events. */
    retVal = FALSE;
  }
  /* Inform upper layer about events in all other cases. */
  return retVal;
}
# endif

/**********************************************************************************************************************
 *  TcpIp_SocketIdxToTlsConIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_SocketIdxToTlsConIdx(
  TcpIp_SocketDynIterType                SocketIdx,
  TCPIP_P2V(TcpIp_TlsConnectionIterType) TlsConIdxPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  TcpIp_TlsConnectionIterType tlsConIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all configured TLS-Connections and return the matching TLS-Connections to the given socket index */
  for (tlsConIdx = 0; tlsConIdx < TcpIp_GetSizeOfTlsConnection(); tlsConIdx++)
  {
    /* Search for the matching socket index */
    if (TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(tlsConIdx) == SocketIdx)
    {
      /* If found, return the corresponding TLS-Connection index */
      *TlsConIdxPtr = tlsConIdx;

      retVal = E_OK;

      /* Exit the loop */
      break;
    }
  }

  return retVal;
} /* TcpIp_SocketIdxToTlsConIdx() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_HandleInvalidConfiguration
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreUtil_HandleInvalidConfiguration(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsUserErrorType invalidCfgUserError;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Trigger an 'internal' alert */
  TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);

  /* #20 Report the error to the user */
  invalidCfgUserError.FunctionId = TCPIP_TLS_FCTID_INVALID_CONFIG;
  invalidCfgUserError.UserErrorId = TCPIP_TLS_ERRORID_INVALID_CONFIG;
  invalidCfgUserError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

  TcpIp_TlsCoreError_ReportUserError(invalidCfgUserError);


  /* #30 Change the state to TLS handshake abort */
  TcpIp_SetHandshakeStateOfTlsConnectionDyn(TlsConIdx, TCPIP_TLS_STATE_HANDSHAKE_ABORT);

  /* ----- Development Error Report ------------------------------------- */
# if (TCPIP_DEV_ERROR_REPORT == STD_ON)
  /* #40 Report a DET error if configured. */
  (void)Det_ReportError(TCPIP_MODULE_ID, TCPIP_TLS_VINSTANCE_ID,
    TCPIP_TLS_API_ID_TLS_INV_CONFIG, TCPIP_TLS_E_INV_CONFIG);
# endif

} /* TcpIp_TlsCoreUtil_HandleInvalidConfiguration() */

# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_CheckEccKeyMConfiguration
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUtil_CheckEccKeyMConfiguration(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsRemoteKeyMCertInfoStartIdxOfTlsConnectionType startTlsRemoteKeyMCertInfoIdx
    = TcpIp_GetTlsRemoteKeyMCertInfoStartIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsRemoteKeyMCertInfoEndIdxOfTlsConnectionType endTlsRemoteKeyMCertInfoIdx
    = TcpIp_GetTlsRemoteKeyMCertInfoEndIdxOfTlsConnection(TlsConIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ---------------------------------------------- */
  /* #10 Check the remote KeyM references. */
  /* For an Ecc client connection or an Ecc server connection with client authentication
   * a remote KeyM reference must be configured.
   * This is also ensured by a validator in the config. */
  if (   (startTlsRemoteKeyMCertInfoIdx == TCPIP_NO_TLSREMOTEKEYMCERTINFOSTARTIDXOFTLSCONNECTION)
      || (endTlsRemoteKeyMCertInfoIdx == TCPIP_NO_TLSREMOTEKEYMCERTINFOENDIDXOFTLSCONNECTION))
  {
     /* intentionally left blank, retVal already E_NOT_OK */
  }
  else
  {
    if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_SERVER)
    {
      TcpIp_CertGroupIdOfTlsRemoteKeyMCertInfoType certGroupIdOfStart
        = TcpIp_GetCertGroupIdOfTlsRemoteKeyMCertInfo(startTlsRemoteKeyMCertInfoIdx);
      retVal = E_OK;
      /* Server connection with client authentication:
       * Assert that each remote KeyM info references the same KeyM group.
       * Otherwise the certificate chain validation may fail depending on the certificate the client sends. */
      for (TcpIp_TlsRemoteKeyMCertInfoIterType iterTlsRemoteKeyMCertInfoIdx = startTlsRemoteKeyMCertInfoIdx + 1u;
          iterTlsRemoteKeyMCertInfoIdx < endTlsRemoteKeyMCertInfoIdx;
          iterTlsRemoteKeyMCertInfoIdx++)
      {
        if (TcpIp_GetCertGroupIdOfTlsRemoteKeyMCertInfo(iterTlsRemoteKeyMCertInfoIdx) != certGroupIdOfStart)
        {
          retVal = E_NOT_OK;
          break;
        }
      }
    }
    else /* TCPIP_TLS_CLIENT */
    {
      /* Tls client connection:
       * Assert that exactly one remote KeyM info is referenced by the TLS connection.
       * This is also ensured by a validator right now. */
      if ((endTlsRemoteKeyMCertInfoIdx - startTlsRemoteKeyMCertInfoIdx) == 1u)
      {
        retVal = E_OK;
      }
    }
  }

  /* #20 Check that the KeyM_VerifyGroup() and KeyM_SetCertificateInGroup functions are available. */
  /* These functions should not be accessed directly since they are implemented inside a precompile switch in the KeyM
   * which would lead to a compile error if there is no KeyM certificate group configured.
   * If no certificate group is configured this point of the implementation shall never be reached.
   * Ensure this with the following runtime check. */
  TcpIp_TlsKeyMVerifyGroupFunctionType verifyGroupFunc
    = TcpIp_GetKeyMVerifyGroupFuncOfTlsConfig(TCPIP_TLSCONFIG_IDX);
  TcpIp_TlsKeyMSetCertificateInGroupFunctionType setCertInGroupFunc
    = TcpIp_GetKeyMSetCertificateInGroupFuncOfTlsConfig(TCPIP_TLSCONFIG_IDX);

  if ((verifyGroupFunc == NULL_PTR) || (setCertInGroupFunc == NULL_PTR))
  {
    retVal = E_NOT_OK;
  }

  return retVal;
} /* TcpIp_TlsCoreUtil_CheckEccKeyMConfiguration */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_PreVerifySignatureChecks
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUtil_PreVerifySignatureChecks(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

#  if ( TCPIP_DEV_ERROR_DETECT == STD_ON )
  TcpIp_TlsTemporarySignatureBufferStartIdxOfTlsConnectionType tlsTmpSignStartIdx =
    TcpIp_GetTlsTemporarySignatureBufferStartIdxOfTlsConnection(TlsConIdx);

  TcpIp_TlsTemporarySignatureBufferEndIdxOfTlsConnectionType tlsTmpSignEndIdx =
    TcpIp_GetTlsTemporarySignatureBufferEndIdxOfTlsConnection(TlsConIdx);
#  endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the temporary signature buffer */
  /* The Tls temporary signature buffer should have at least the length of the maximum possible signature.
   * The size of the buffer is set to a constant in the generator. */
#  if ( TCPIP_DEV_ERROR_DETECT == STD_ON )
  if (TCPIP_TLS_MAX_SIGNATURE_LEN <= ((uint16)(tlsTmpSignEndIdx - tlsTmpSignStartIdx)))
#  endif
  {
    retVal = E_OK;
  }
#  if ( TCPIP_DEV_ERROR_DETECT == STD_ON )
  else
  {
    /* Constant size of Tls temporary signature buffer in the generator set to a too small value.
     * This should never happen. */
    TcpIp_CallDetReportError(TCPIP_API_ID_SEGMENT_OPERATION, TCPIP_E_INV_RUNTIME_CHECK);
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
  }
#  else
  TCPIP_DUMMY_STATEMENT_CONST(TlsConIdx);                                                                               /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
} /* TcpIp_TlsCoreUtil_PreVerifySignatureChecks() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_CheckPublicKeyCompressionFlagOfEllipticCurve
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, TCPIP_CODE) TcpIp_TlsCoreUtil_CheckPublicKeyCompressionFlagOfEllipticCurve(
  CONST(TcpIp_TlsEllipticCurveIdType, AUTOMATIC) CurveId)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean CurveUsedCompressionFlag;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the curve ID and return TRUE if the compression flag is used */
  switch (CurveId)
  {
    case TCPIP_CURVE_ID_SECP521R1:
    case TCPIP_CURVE_ID_SECP384R1:
    case TCPIP_CURVE_ID_SECP256R1:
    {
      CurveUsedCompressionFlag = TRUE;
      break;
    } /* case TCPIP_CURVE_ID_SECP521R1 | TCPIP_CURVE_ID_SECP384R1 | TCPIP_CURVE_ID_SECP256R1 */

    case TCPIP_CURVE_ID_X448:
    case TCPIP_CURVE_ID_X25519:
    {
      CurveUsedCompressionFlag = FALSE;
      break;
    } /* case TCPIP_CURVE_ID_X25519 | TCPIP_CURVE_ID_X448 */

    default:
    {
      CurveUsedCompressionFlag = FALSE;
      break;
    } /* default */
  } /* switch */
  return CurveUsedCompressionFlag;
} /* TcpIp_TlsCoreUtil_CheckPublicKeyCompressionFlagOfEllipticCurve() */
# endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/***********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_ReturnCipherSpecificStreamingMode
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(TcpIp_TlsCipherStreamingModeDataType, TCPIP_CODE) TcpIp_TlsCoreUtil_ReturnCipherSpecificStreamingMode(
  TcpIp_TlsCipherDataType Cipher)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherStreamingModeDataType streamingMode;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the cipher and return its streaming mode */
  switch (Cipher)
  {
  case TCPIP_TLS_NULL_WITH_NULL_NULL:
  case TCPIP_TLS_ECDHE_ECDSA_WITH_NULL_SHA:
  case TCPIP_TLS_ECDH_ECDSA_WITH_NULL_SHA:
  case TCPIP_TLS_PSK_WITH_NULL_SHA:
  case TCPIP_TLS_PSK_WITH_NULL_SHA256:
    {
      streamingMode = TCPIP_TLS_STREAMING_MODE_NULL;
      break;
    }
  case TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256:
  case TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256:
  case TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA:
  case TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA:
  case TCPIP_TLS_PSK_WITH_AES_128_CBC_SHA256:
  case TCPIP_TLS_PSK_WITH_AES_128_CBC_SHA:
    {
      streamingMode = TCPIP_TLS_STREAMING_MODE_AES_128_CBC;
      break;
    }
  case TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256:
  case TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA256:
  case TCPIP_TLS_PSK_WITH_AES_128_GCM_SHA256:
  case TCPIP_TLS_AES_128_GCM_SHA256:
    {
      streamingMode = TCPIP_TLS_STREAMING_MODE_AES_128_GCM;
      break;
    }
  case TCPIP_TLS_AES_256_GCM_SHA384:
    {
      streamingMode = TCPIP_TLS_STREAMING_MODE_AES_256_GCM;
      break;
    }
  case TCPIP_TLS_CHACHA20_POLY1305_SHA256:
    {
      streamingMode = TCPIP_TLS_STREAMING_MODE_CHACHA20_POLY1305;
      break;
    }
  default:
    {
      streamingMode = TCPIP_TLS_STREAMING_MODE_INVALID;
      break;
    }
  }

  return streamingMode;
} /* TcpIp_TlsCoreUtil_ReturnCipherSpecificStreamingMode() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_ReturnSelectedCipherSpecificStreamingMode
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(TcpIp_TlsCipherStreamingModeDataType, TCPIP_CODE) TcpIp_TlsCoreUtil_ReturnSelectedCipherSpecificStreamingMode(
  TcpIp_TlsConnectionIterType       TlsConIdx)
{
  /* #10 Return the streaming mode of the selected cipher on this TLS connection */
  return TcpIp_TlsCoreUtil_ReturnCipherSpecificStreamingMode(
           TcpIp_GetCipherSuiteIdOfTlsCipherDefinition(
             TcpIp_GetTlsCipherDefinitionIdxOfTlsCipherWorker(
               TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx))));

} /* TcpIp_TlsCoreUtil_ReturnSelectedCipherSpecificStreamingMode() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_ReturnCipherSpecificKeyExchangeMethod
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(TcpIp_TlsKeyExchangeMethodDataType, TCPIP_CODE) TcpIp_TlsCoreUtil_ReturnCipherSpecificKeyExchangeMethod(
  TcpIp_TlsCipherDataType Cipher)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsKeyExchangeMethodDataType keyExchangeMethod;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return the key exchange mode of the passed cipher */
  switch (Cipher)
  {
# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
    case TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256:
    case TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256:
    case TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA:
    case TCPIP_TLS_ECDHE_ECDSA_WITH_NULL_SHA:
    /* TLS 1.3 */
    case TCPIP_TLS_AES_128_GCM_SHA256:
    case TCPIP_TLS_AES_256_GCM_SHA384:
    case TCPIP_TLS_CHACHA20_POLY1305_SHA256:
    {
      keyExchangeMethod = TCPIP_TLS_KEYEXCHANGE_METHOD_ECDHE;
      break;
    }
    case TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256:
    case TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA256:
    case TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA:
    case TCPIP_TLS_ECDH_ECDSA_WITH_NULL_SHA:
    {
      keyExchangeMethod = TCPIP_TLS_KEYEXCHANGE_METHOD_ECDH;
      break;
    }
# endif
    case TCPIP_TLS_PSK_WITH_AES_128_CBC_SHA256:
    case TCPIP_TLS_PSK_WITH_AES_128_GCM_SHA256:
    case TCPIP_TLS_PSK_WITH_NULL_SHA:
    case TCPIP_TLS_PSK_WITH_NULL_SHA256:
    case TCPIP_TLS_PSK_WITH_AES_128_CBC_SHA:
    {
      keyExchangeMethod = TCPIP_TLS_KEYEXCHANGE_METHOD_PSK_PLAIN;
      break;
    }
    default:
    {
      /* Invalid key exchange method. This can never happen, a valid key exchange method has been chosen with the active
      cipher suite received in the server_hello message. */
      keyExchangeMethod = TCPIP_TLS_KEYEXCHANGE_METHOD_INVALID;
      break;
    }
  }

  return keyExchangeMethod;
} /* TcpIp_TlsCoreUtil_ReturnCipherSpecificKeyExchangeMethod() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_ReturnActiveCipherSpecificKeyExchangeMethod
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(TcpIp_TlsKeyExchangeMethodDataType, TCPIP_CODE) TcpIp_TlsCoreUtil_ReturnActiveCipherSpecificKeyExchangeMethod(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsKeyExchangeMethodDataType retVal = TCPIP_TLS_KEYEXCHANGE_METHOD_INVALID;

  /* ----- Implementation ----------------------------------------------- */
  if (TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx) != TCPIP_NO_TLSCIPHERWORKERACTIVEIDXOFTLSCONNECTIONDYN)
  {
    /* #10 Extract and return the key exchange of the active cipher suite for the connection */
    retVal = TcpIp_TlsCoreUtil_ReturnCipherSpecificKeyExchangeMethod(
      TcpIp_GetCipherSuiteIdOfTlsCipherDefinition(
        TcpIp_GetTlsCipherDefinitionIdxOfTlsCipherWorker(
          TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx))));
  }
  return retVal;
} /* TcpIp_TlsCoreUtil_ReturnActiveCipherSpecificKeyExchangeMethod() */

/***********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_ReturnCipherSpecificAuthenticationMode
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(TcpIp_TlsMessageAuthenticationModeDataType, TCPIP_CODE) TcpIp_TlsCoreUtil_ReturnCipherSpecificAuthenticationMode(
  TcpIp_TlsCipherDataType Cipher)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsMessageAuthenticationModeDataType authMode;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the cipher and return its authentication mode */
  switch (Cipher)
  {
    case TCPIP_TLS_NULL_WITH_NULL_NULL:
    {
      authMode = TCPIP_TLS_MSG_AUTH_MODE_NONE;
      break;
    }
    case TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256:
    case TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256:
    case TCPIP_TLS_PSK_WITH_AES_128_CBC_SHA256:
    case TCPIP_TLS_PSK_WITH_NULL_SHA256:
    {
      authMode = TCPIP_TLS_MSG_AUTH_MODE_SHA256;
      break;
    }
    case TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256:
    case TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA256:
    case TCPIP_TLS_PSK_WITH_AES_128_GCM_SHA256:
    case TCPIP_TLS_AES_128_GCM_SHA256:
    case TCPIP_TLS_AES_256_GCM_SHA384:
    case TCPIP_TLS_CHACHA20_POLY1305_SHA256:
    {
      /* For AEAD cipher suites, authentication is performed along with encryption */
      authMode = TCPIP_TLS_MSG_AUTH_MODE_NONE;
      break;
    }
    case TCPIP_TLS_ECDHE_ECDSA_WITH_NULL_SHA:
    case TCPIP_TLS_ECDH_ECDSA_WITH_NULL_SHA:
    case TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA:
    case TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA:
    case TCPIP_TLS_PSK_WITH_NULL_SHA:
    case TCPIP_TLS_PSK_WITH_AES_128_CBC_SHA:
    {
      authMode = TCPIP_TLS_MSG_AUTH_MODE_SHA1;
      break;
    }
    default:
    {
      /* Unknown cipher suite */
      authMode = TCPIP_TLS_MSG_AUTH_MODE_INVALID;
      break;
    }
  }

  return authMode;
} /* TcpIp_TlsCoreUtil_ReturnCipherSpecificAuthenticationMode() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_GetExtensionsLengthAndCheckForValidity
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUtil_GetExtensionsLengthAndCheckForValidity(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsBufferRxIterType MsgEndIdx,
  TCPIP_P2V(uint16) ExtensionsLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Check that we are not already at the end of the message */
  if (TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx) != MsgEndIdx)
  {
    /* Message is not empty, extensions have been detected */
    /* #20 Check if there is enough space for an extensions length. */
    if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx),
      TCPIP_TLS_EXTENSION_LIST_LEN, MsgEndIdx))
    {
      *ExtensionsLenPtr = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(
        TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)), 0u);

      /* Maintain AdHs read index by incrementing the consumed length */
      TcpIp_AddTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, TCPIP_TLS_EXTENSION_LIST_LEN);

      /* #30 Check if there is enough space for the whole extensions length. */
      if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx),          /* PRQA S 2995 2 */ /* MD_TcpIp_Tls_2995 */
        (TcpIp_TlsBufferRxIterType)*ExtensionsLenPtr, MsgEndIdx))
      {
        retVal = E_OK;
      } /* Range check extension length */
    } /* Range check overall extension length */
  } /* Check if message is empty */

  return retVal;
} /* TcpIp_TlsCoreUtil_GetExtensionsLengthAndCheckForValidity() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_CheckLengthsOfExtensionSupportedGroups
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUtil_CheckLengthsOfExtensionSupportedGroups(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsExtensionType      SupportedGroupsExtension,
  TCPIP_P2V(uint16)           ReceivedSupportedGroupsLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsBufferRxIterType extSupportedGroupsLenIdx = SupportedGroupsExtension.StartIdx;
  uint16 overallExtLength = SupportedGroupsExtension.Length;
  TcpIp_TlsBufferRxIterType extSupportedGroupsEndIdx = extSupportedGroupsLenIdx + overallExtLength;

  Std_ReturnType retVal = E_NOT_OK;
  /* ----- Implementation ----------------------------------------------- */
  /* Extension index information */
  /* Supported Group Extension Format
   *
   *
   *                             -> extSupportedGroupsLenIdx
   *                            /                    -> extGroupStartIdx
   *                           /                    /
   *       [ext Type][ext Len][supported Group Len][group 1]            [group n]
   * Byte: 0       1 2      3 4                  5 6      7             (x-1)  x
   *                                                \---consumedExtensionLen---/
   */

  /* Range check before read out the received supported groups length (2Bytes) */
  if (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(extSupportedGroupsLenIdx,
        TCPIP_TLS_EXTENSION_SUPPORTED_GROUP_LENGTH_LEN, extSupportedGroupsEndIdx))
  {
    /* #10 Get the length of the received supported groups list and check against the overall length */
    *ReceivedSupportedGroupsLenPtr = IpBase_GetUint16(TcpIp_GetAddrTlsBufferRx(extSupportedGroupsLenIdx), 0u);         /* TCPIP_CSL_NAME_LENGTH */

    if (overallExtLength == (*ReceivedSupportedGroupsLenPtr + TCPIP_TLS_EXTENSION_SUPPORTED_GROUP_LENGTH_LEN))
    {
      TcpIp_TlsBufferRxIterType extGroupStartIdx
        = extSupportedGroupsLenIdx + TCPIP_TLS_EXTENSION_SUPPORTED_GROUP_LENGTH_LEN;

      /* #20 Check the length of the received supported groups list for plausibility */
      /* RFC 8422 - 5.1.1.  Supported Elliptic Curves Extension */
      if (   (*ReceivedSupportedGroupsLenPtr >= 2u) /* List must include at least one group */
          /* and the length information is sent pairwise, so the length must be even */
          && ((*ReceivedSupportedGroupsLenPtr % 2u) == 0u)
          /* Range check (received list length) */
          && (TCPIP_TLS_RXBUFFER_ISIDXINRANGE(extGroupStartIdx,                                                         /* PRQA S 2995 2 */ /* MD_TcpIp_Tls_2995 */
                *ReceivedSupportedGroupsLenPtr, extSupportedGroupsEndIdx)))
      {
        retVal = E_OK;
      }
      else
      {
        /* #30 received supported group length mismatch - report error and trigger TLS alert */
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
      }
    }
    else
    {
      /* #40 overall received length mismatch - report error and trigger TLS alert */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_DECODE_ERROR);
    }
  }

  return retVal;
} /* TcpIp_TlsCoreUtil_CheckLengthsOfExtensionSupportedGroups() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_GetTxCipherMacLen
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(uint8, TCPIP_CODE) TcpIp_TlsCoreUtil_GetTxCipherMacLen(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the active Tx cipher and return the length of its hash */
  return TcpIp_TlsCoreUtil_GetCiphersuiteHashLen(TcpIp_GetActiveCipherTxOfTlsConnectionDyn(TlsConIdx));
} /* TcpIp_TlsCoreUtil_GetTxCipherMacLen() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_GetCiphersuiteHashLen
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(uint8, TCPIP_CODE) TcpIp_TlsCoreUtil_GetCiphersuiteHashLen(
  TcpIp_TlsCipherDataType     Ciphersuite)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 hashLen;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Depending on the passed cipher return the length of the hash */
  switch (Ciphersuite)
  {
    case TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256:
    case TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256:
    case TCPIP_TLS_PSK_WITH_AES_128_CBC_SHA256:
    case TCPIP_TLS_PSK_WITH_NULL_SHA256:
    {
      hashLen = TCPIP_TLS_HASH_SHA256_LEN;
      break;
    }
    case TCPIP_TLS_ECDHE_ECDSA_WITH_NULL_SHA:
    case TCPIP_TLS_ECDH_ECDSA_WITH_NULL_SHA:
    case TCPIP_TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA:
    case TCPIP_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA:
    case TCPIP_TLS_PSK_WITH_NULL_SHA:
    case TCPIP_TLS_PSK_WITH_AES_128_CBC_SHA:
    {
      hashLen = TCPIP_TLS_HASH_SHA1_LEN;
      break;
    }
    case TCPIP_TLS_NULL_WITH_NULL_NULL:
    default:
    {
      hashLen = 0u;
      break;
    }
  }

  return hashLen;
} /* TcpIp_TlsCoreUtil_GetCiphersuiteHashLen() */

# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_ConnectionUseEccCipherSuite
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, TCPIP_CODE) TcpIp_TlsCoreUtil_ConnectionUseEccCipherSuite(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerIndIterType tlsCipherWorkerIndIdx;
  boolean connectionUseEccCipherSuite = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all configured CipherWorker for this TLS connection and check if it uses ECC cipher suites */
  for (tlsCipherWorkerIndIdx = TcpIp_GetTlsCipherWorkerIndStartIdxOfTlsConnection(TlsConIdx);
       tlsCipherWorkerIndIdx < TcpIp_GetTlsCipherWorkerIndEndIdxOfTlsConnection(TlsConIdx);
       tlsCipherWorkerIndIdx++)
  {
    TcpIp_TlsCipherWorkerIterType tlsCipherWorkerIdx = TcpIp_GetTlsCipherWorkerInd(tlsCipherWorkerIndIdx);
    TcpIp_TlsCipherDefinitionIdxOfTlsCipherWorkerType tlsCipherDefinitionIdx =
      TcpIp_GetTlsCipherDefinitionIdxOfTlsCipherWorker(tlsCipherWorkerIdx);

    if (TcpIp_IsCipherSuiteUsePskOfTlsCipherDefinition(tlsCipherDefinitionIdx) == FALSE)
    {
      /* At least one cipherworker does not use PSK - therefore it must use ECC */
      connectionUseEccCipherSuite = TRUE;
      break;
    }
  }
  return connectionUseEccCipherSuite;
} /* TcpIp_TlsCoreUtil_ConnectionUseEccCipherSuite() */
# endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_CheckAndGetRootCertificateId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUtil_CheckAndGetRootCertificateId(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TCPIP_P2V(uint16)             CertIdPtr                                                                               /* PRQA S 3673 */ /* MD_TCPIP_Rule8.13_CfgSpecific */
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
# if (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON)
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the TLS connection uses a TLS client. */
  if (TcpIp_GetModeOfTlsConnection(TlsConIdx) == TCPIP_TLS_CLIENT)
  {
    TcpIp_TlsKeyExchangeMethodDataType keyExchange =
      TcpIp_TlsCoreUtil_ReturnActiveCipherSpecificKeyExchangeMethod(TlsConIdx);

    /* #20 Check which key exchange algortihm is used and return the certificate ID. */
    switch (keyExchange)
    {
      case TCPIP_TLS_KEYEXCHANGE_METHOD_ECDH:
      case TCPIP_TLS_KEYEXCHANGE_METHOD_ECDHE:
      {
        retVal = TcpIp_TlsClient_GetRootCertificateId(TlsConIdx, CertIdPtr);
        break;
      }

      case TCPIP_TLS_KEYEXCHANGE_METHOD_PSK_PLAIN:
      default:
      {
        /* Nothing to do here. Return E_NOT_OK because the selected key exchange algorithm
         * does not supported certificates. */
        break;
      }
    }
  }
  else
  {
    /* Nothing to do here. The API call is not supported for TLS Server. Return E_NOT_OK. */
  }
# else
  TCPIP_DUMMY_STATEMENT_CONST(TlsConIdx);                                                                               /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
  TCPIP_DUMMY_STATEMENT_CONST(CertIdPtr);                                                                               /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
# endif /* (TCPIP_SUPPORT_ASRTLSCLIENT == STD_ON) */
  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_IsActiveHandshakeSet
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, TCPIP_CODE) TcpIp_TlsCoreUtil_IsActiveHandshakeSet(
  TcpIp_TlsConnectionIterType   TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx =
    TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  boolean isActiveHandshakeSet = FALSE;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the active handshake is set to a value different than the initial value */
  if (activeTlsCipherWorkerIdx != TCPIP_NO_TLSCIPHERWORKERACTIVEIDXOFTLSCONNECTIONDYN)
  {
    TcpIp_TlsHandshakeActiveIdxOfTlsCipherWorkerDynType activeTlsHandshakeIdx
      = TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(activeTlsCipherWorkerIdx);

    if (activeTlsHandshakeIdx != TCPIP_NO_TLSHANDSHAKEACTIVEIDXOFTLSCIPHERWORKERDYN)
    {
      isActiveHandshakeSet = TRUE;
    }
  }
  return isActiveHandshakeSet;
}

# if (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_TlsUpdateCertChainStatus
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
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUtil_TlsUpdateCertChainStatus(
  TcpIp_TlsConnectionIterType           TlsConIdx,
  TcpIp_Tls_CertStatusUpdateModeType    CertStatusUpdateMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_CertificateIdType issuerCertId;
  TcpIp_TlsCertValidationStatusDynIterType tlsCertValidationStatusIdx;

  Std_ReturnType retVal = E_OK;

  TCPIP_ASSERT(TcpIp_GetTlsCertValidationStatusDynValidEndIdxOfTlsConnectionDyn(TlsConIdx)
    <= TcpIp_GetTlsCertValidationStatusDynEndIdxOfTlsConnection(TlsConIdx));

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all the received certificates and update the current status */
  for (tlsCertValidationStatusIdx = TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx);
       tlsCertValidationStatusIdx < TcpIp_GetTlsCertValidationStatusDynValidEndIdxOfTlsConnectionDyn(TlsConIdx);
       tlsCertValidationStatusIdx++)
  {
    /* Pointer to the certificate status struct */
    TCPIP_P2V(TcpIp_CertValidationStatusType)  certStatusPtr = TcpIp_GetAddrTlsCertValidationStatusDyn(
      tlsCertValidationStatusIdx);

    if (CertStatusUpdateMode == TCPIP_TLS_UPDATE_CERT_MODE_CHAIN)
    {
      /* #20 Retrieve the current KeyM status of the certificate */
      if (KeyM_CertGetStatus(certStatusPtr->CertId, &(certStatusPtr->CertStatus)) != E_OK)
      {
        certStatusPtr->CertStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;
        retVal = E_NOT_OK;
      }
    }
    else /* CertStatusUpdateMode = TCPIP_TLS_UPDATE_CERT_MODE_OCSP */
    {
      /* #30 Check if OCSP is enabled and update OCSP information */
      retVal = TcpIp_TlsClient_TlsUpdateOcspInformation(TlsConIdx, certStatusPtr);
    }

    /* #40 Check if the current certificate is a self-signed root certificate */
    if (KeyM_GetIssuerCertId(certStatusPtr->CertId, &issuerCertId) == E_OK)
    {
      if (issuerCertId == certStatusPtr->CertId)
      {
        certStatusPtr->IsSelfSigned = TRUE;
      }
    }
    else
    {
      /* Trigger alert. Either no matching root cert was found, or cert chain is not consistent in itself. */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_UNKNOWN_CA);

      retVal = E_NOT_OK;
    }

    /* Break execution in case of failure */
    if (retVal != E_OK)
    {
      /* Reset the certificate status since it could not be set successfully */
      certStatusPtr->IsSelfSigned = FALSE;
      break;
    }
  }

  return retVal;
} /* TcpIp_TlsCoreUtil_TlsUpdateCertChainStatus() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_TlsUpdateOcspInformation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClient_TlsUpdateOcspInformation(
  TcpIp_TlsConnectionIterType                  TlsConIdx,
  TCPIP_P2V(TcpIp_CertValidationStatusType)    CertStatusPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the Certificate Status Request feature is enabled */
  if (TcpIp_IsTlsUseExtensionCertificateStatusRequestOfTlsConnection(TlsConIdx) == TRUE)
  {
    KeyM_CertificateIdType leafCertId = TcpIp_GetAddrTlsCertValidationStatusDyn(
      TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx))->CertId;

    /* OCSP is currently only implemented for leaf server certificate (RFC6066 TLS Single Certificate Status Request) */
    if (CertStatusPtr->CertId == leafCertId)
    {
      /* #20 OCSP enabled, check if the OCSP Certificate Status is received */
      if (CertStatusPtr->CertStatusResponse.OcspConnectionState == TCPIP_TLS_OCSP_CONNECTION_STATE_STATUS_RECEIVED)
      {
        /* Reset return value for next function calls */
        retVal = E_NOT_OK;
        /* #30 Update OCSP information which are then provided to upper layer via validation callback */
        if (TcpIp_TlsClient_TlsUpdateOcspCertificateStatus(CertStatusPtr) == E_OK)
        {
          /* Update successfully performed - return E_OK */
          retVal = E_OK;
        } /* else - retVal already set to E_NOT_OK */
      } /* else - No OCSP response received, nothing to do */
    } /* else - other then leaf certificate, nothing to do */
  } /* else - OCSP not enabled, nothing to do */

  return retVal;
} /* TcpIp_TlsClient_TlsUpdateOcspInformation() */

/**********************************************************************************************************************
 *  TcpIp_TlsClient_TlsUpdateOcspCertificateStatus
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
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsClient_TlsUpdateOcspCertificateStatus(
  TCPIP_P2V(TcpIp_CertValidationStatusType) CertStatusPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if OCSP response status is other than successful */
  if (CertStatusPtr->CertStatusResponse.OcspResponseStatus != TCPIP_TLS_OCSP_RESPONSE_STATUS_SUCCESSFUL)
  {
    /* #20 Set the certificate status to invalid */
    CertStatusPtr->CertStatusResponse.OcspCertStatus = KEYM_CERTIFICATE_INVALID;
    retVal = E_OK;
  }
  /* #30 Otherwise */
  else
  {
    KeyM_CertificateInfoType certInfoType = KEYM_CERT_INFO_OCSP_RESPONSE_CERT_STATUS;

    uint32 ocspCertificateStatusLength = 1u;
    uint8 ocspCertificateStatusAsn1Coded = 0xffu;

    /* #40 Update the OCSP certificate status for the given certificate */
    if (KeyM_CertInfoGet(CertStatusPtr->CertId, certInfoType, &ocspCertificateStatusAsn1Coded,
         &ocspCertificateStatusLength) == E_OK)
    {
      retVal = E_OK;

      /* #50 Map ASN1 coded status codes into the KeyM specific certificate status */
      switch (ocspCertificateStatusAsn1Coded)
      {
        case TCPIP_TLS_OCSP_ASN1_CERT_STATUS_GOOD:
        {
          /* Certificate status was 'good (0)' - Certificate is valid */
          CertStatusPtr->CertStatusResponse.OcspCertStatus = KEYM_CERTIFICATE_VALID;
          break;
        }
        case TCPIP_TLS_OCSP_ASN1_CERT_STATUS_REVOKED:
        {
          /* Certificate status was 'revoked (1)' - Certificate is revoked */
          CertStatusPtr->CertStatusResponse.OcspCertStatus = KEYM_E_CERTIFICATE_REVOKED;
          break;
        }
        case TCPIP_TLS_OCSP_ASN1_CERT_STATUS_UNKOWN:
        {
          /* Certificate status was 'unknown (2)' - Certificate is unknown state */
          CertStatusPtr->CertStatusResponse.OcspCertStatus = TCPIP_TLS_OCSP_CERTIFICATE_STATUS_UNKOWN;
          break;
        }
        default:
        {
          /* All other values - Certificate is invalid */
          CertStatusPtr->CertStatusResponse.OcspCertStatus = KEYM_CERTIFICATE_INVALID;
          /* Reset return value to E_NOT_OK */
          retVal = E_NOT_OK;
          break;
        }
      }
    }
  } /* else - return value already set to E_NOT_OK */

  return retVal;
} /* TcpIp_TlsClient_TlsUpdateOcspCertificateStatus() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_TlsUpdateOverallCertValidationResult
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreUtil_TlsUpdateOverallCertValidationResult(
  TcpIp_TlsConnectionIterType                TlsConIdx,
  TCPIP_P2V(TcpIp_CertValidationResultType)  CertValidResultPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* Number of invalid certificates in the certificate chain */
  uint8 invalidCertCnt = 0u;
  /* Iterator for certificate status struct */
  TcpIp_TlsCertValidationStatusDynIterType tlsCertValidationStatusDynIdx;
  boolean selfSignedRootPresent = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_ASSERT(TcpIp_GetTlsCertValidationStatusDynValidEndIdxOfTlsConnectionDyn(TlsConIdx)
    <= TcpIp_GetTlsCertValidationStatusDynEndIdxOfTlsConnection(TlsConIdx));

  /* Overall validation result is unknown at this point */
  *CertValidResultPtr = TCPIP_TLS_VALIDATION_UNKNOWN;

  /* #10 Iterate over all the certificate status and provide an overall validation result */
  for (tlsCertValidationStatusDynIdx = TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx);
       tlsCertValidationStatusDynIdx < TcpIp_GetTlsCertValidationStatusDynValidEndIdxOfTlsConnectionDyn(TlsConIdx);
       tlsCertValidationStatusDynIdx++)
  {
    /* Check if any received certificate is a self-signed root */
    if (TcpIp_GetAddrTlsCertValidationStatusDyn(tlsCertValidationStatusDynIdx)->IsSelfSigned == TRUE)
    {
      selfSignedRootPresent = TRUE;
    }

    /* Process the current certificate status */
    switch (TcpIp_GetAddrTlsCertValidationStatusDyn(tlsCertValidationStatusDynIdx)->CertStatus)
    {
      case KEYM_CERTIFICATE_VALID:
      {
        /* This status implies certificate is valid */
        break;
      }
      case KEYM_CERTIFICATE_PARSED_NOT_VALIDATED:
      {
        /* Certificate is not validated. Probably this is because an other one is recognized as not valid, and the
        further certificates were not processed any more. At least one other certificate will have a more 'advanced' state. */
        break;
      }
      case KEYM_CERTIFICATE_INVALID:
      case KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL:
      case KEYM_E_CERTIFICATE_SIGNATURE_FAIL:
      case KEYM_E_CERTIFICATE_INVALID_CHAIN_OF_TRUST:
      case KEYM_E_CERTIFICATE_INVALID_TYPE:
      case KEYM_E_CERTIFICATE_INVALID_FORMAT:
      case KEYM_E_CERTIFICATE_INVALID_CONTENT:
      case KEYM_E_CERTIFICATE_REVOKED:
      default:
      {
        /* These status implies certificate is invalid */
        invalidCertCnt++;
        break;
      }
    } /* switch() */
  } /* for() */

  /* #20 Determine overall validation status */
  if ((invalidCertCnt != 0u) || (selfSignedRootPresent == TRUE))
  {
    /* If invalid certificates present or self-signed root is present, fail the validation */
    *CertValidResultPtr = TCPIP_TLS_VALIDATION_NOT_OK;
  }
  else
  {
    *CertValidResultPtr = TCPIP_TLS_VALIDATION_OK;
  }

} /* TcpIp_TlsCoreUtil_TlsUpdateOverallCertValidationResult() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_TlsGetAlertForBadCertificateChain
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
FUNC(void, TCPIP_CODE) TcpIp_TlsCoreUtil_TlsGetAlertForBadCertificateChain(
  TcpIp_TlsConnectionIterType                TlsConIdx,
  TCPIP_P2V(TcpIp_TlsAlertDescriptionType)   AlertDescriptionPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* Iterator for certificate status struct */
  TcpIp_TlsCertValidationStatusDynIterType certStatusIdx;

  /* The local variable tempAlert is only used to determine the description of the alert which should be sent.
   * Which alert description will ultimately be send is set in function TcpIp_Tls_HandleAlertForOcspCertificateStatus()
   * and is stored at the location of AlertDescriptionPtr */
  TcpIp_TlsAlertDescriptionType tempAlert = TCPIP_TLS_ALERT_UNSET;

  /* Initially set the status response received flag to true.
   * If OCSP is disabled it does not matter if the status response is received or not. */
  boolean validStatusResponseReceived = TRUE;

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_ASSERT(TcpIp_GetTlsCertValidationStatusDynValidEndIdxOfTlsConnectionDyn(TlsConIdx)
    <= TcpIp_GetTlsCertValidationStatusDynEndIdxOfTlsConnection(TlsConIdx));

  /* #10 Iterate over all the certificate status and determine an alert description */
  for (certStatusIdx = TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx);
       certStatusIdx < TcpIp_GetTlsCertValidationStatusDynValidEndIdxOfTlsConnectionDyn(TlsConIdx);
       certStatusIdx++)
  {
    /* #20 Determine alert for certificate status */
    tempAlert = TcpIp_TlsCoreUtil_TlsGetAlertForCertificateStatus(certStatusIdx);

    /* #30 Determine alert for OCSP certificate status */
    if (tempAlert == TCPIP_TLS_ALERT_UNSET)
    {
      tempAlert = TcpIp_TlsCoreUtil_TlsGetAlertForOcspCertificateStatus(TlsConIdx, certStatusIdx);
    }

    /* #40 Check if status response for the certificate was received */
    if (tempAlert == TCPIP_TLS_ALERT_DESC_BAD_CERT_STATUS_RESP)
    {
      validStatusResponseReceived = FALSE;
    }

    /* #50 Determine alert for OCSP response status */
    if (tempAlert == TCPIP_TLS_ALERT_UNSET)
    {
      tempAlert = TcpIp_TlsCoreUtil_TlsGetAlertForOcspResponseStatus(TlsConIdx, certStatusIdx);
    }

    /* If a status response was received and any alert occurred stop processing the other certificates.
     * If no status response was received and alert is unknown_ca (self-signed certificate) stop processing.
     * The second OR-case is needed for SCC's Private Environment use case, where OCSP is enabled but no status
     * response is sent. The missing status response should be ignored if a self-signed certificate is present. */
    if   (((validStatusResponseReceived == TRUE) && (tempAlert != TCPIP_TLS_ALERT_UNSET))
      || ((validStatusResponseReceived == FALSE) && (tempAlert == TCPIP_TLS_ALERT_DESC_UNKNOWN_CA)))
    {
      break;
    }
  } /* for() */

  /* If no status response has been received and no self-signed certificate is used,
   * change alert to bad_cert_status_response. */
  if ((validStatusResponseReceived == FALSE) && (tempAlert != TCPIP_TLS_ALERT_DESC_UNKNOWN_CA))
  {
    tempAlert = TCPIP_TLS_ALERT_DESC_BAD_CERT_STATUS_RESP;
  }

  /* #60 Check if alert must be changed or error indication must be triggered based on results of above implementation */
  TcpIp_Tls_HandleAlertForOcspCertificateStatus(TlsConIdx, tempAlert, validStatusResponseReceived, AlertDescriptionPtr);

} /* TcpIp_TlsCoreUtil_TlsGetAlertForBadCertificateChain() */

/**********************************************************************************************************************
 *  TcpIp_Tls_HandleAlertForOcspCertificateStatus
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_Tls_HandleAlertForOcspCertificateStatus(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsAlertDescriptionType Alert,
  boolean ValidStatusResponseReceived,
  TCPIP_P2V(TcpIp_TlsAlertDescriptionType) AlertDescriptionPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if an alert has been set and update the AlertDescriptionPtr */
  if (Alert == TCPIP_TLS_ALERT_UNSET)
  {
    *AlertDescriptionPtr = TCPIP_TLS_ALERT_DESC_CERT_UNKNOWN;
  }
  else
  {
    *AlertDescriptionPtr = Alert;

#  if (TCPIP_SUPPORT_ASRTLS_ERROR_INDICATION == STD_ON)
    if (   (TcpIp_IsTlsUseExtensionCertificateStatusRequestOfTlsConnection(TlsConIdx) == TRUE)
        && (ValidStatusResponseReceived == TRUE))
    {
      /* Trigger error indication if status of OCSP is not set to good */
      TcpIp_TlsCoreError_IndicationTrigger(TlsConIdx, TCPIP_TLS_E_OCSP_RESP_NOT_GOOD, TCPIP_TLS_ALERT_UNSET);
    }
#  else
    TCPIP_DUMMY_STATEMENT_CONST(TlsConIdx);                                                                             /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
    TCPIP_DUMMY_STATEMENT_CONST(ValidStatusResponseReceived);                                                           /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
#  endif
  }
} /* TcpIp_Tls_HandleAlertForOcspCertificateStatus() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_TlsGetAlertForCertificateStatus
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(TcpIp_TlsAlertDescriptionType, TCPIP_CODE) TcpIp_TlsCoreUtil_TlsGetAlertForCertificateStatus(
  TcpIp_TlsCertValidationStatusDynIterType   TlsCertValidationStatusIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsAlertDescriptionType localAlert = TCPIP_TLS_ALERT_UNSET;

  TCPIP_P2C(TcpIp_CertValidationStatusType) currentCertStatusPtr
    = TcpIp_GetAddrTlsCertValidationStatusDyn(TlsCertValidationStatusIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Determine alert for certificate status */
  /* Check if any received certificate is a self-signed root */
  if (currentCertStatusPtr->IsSelfSigned == TRUE)
  {
    /* Since self-signed root is present, alert is unkown_ca */
    localAlert = TCPIP_TLS_ALERT_DESC_UNKNOWN_CA;
  }
  else
  {
    /* For other certificates process the certificate status */
    switch (currentCertStatusPtr->CertStatus)
    {
      case KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL:
      {
        /* Validity period check failed, alert is certificate_expired */
        localAlert = TCPIP_TLS_ALERT_DESC_CERT_EXPIRED;
        break;
      }
      case KEYM_E_CERTIFICATE_INVALID_CHAIN_OF_TRUST:
      {
        /* Invalid chain of trust, alert is unknown_ca */
        localAlert = TCPIP_TLS_ALERT_DESC_UNKNOWN_CA;
        break;
      }
      case KEYM_E_CERTIFICATE_REVOKED:
      {
        /* Certificate has been revoked, alert is certificate_revoked */
        localAlert = TCPIP_TLS_ALERT_DESC_CERT_REVOKED;
        break;
      }
      case KEYM_E_CERTIFICATE_SIGNATURE_FAIL:
      case KEYM_E_CERTIFICATE_INVALID_TYPE:
      case KEYM_E_CERTIFICATE_INVALID_FORMAT:
      case KEYM_E_CERTIFICATE_INVALID_CONTENT:
      {
        /* Certificate is corrupt or signature verification failed , alert is bad_certificate */
        localAlert = TCPIP_TLS_ALERT_DESC_BAD_CERT;
        break;
      }
      case KEYM_CERTIFICATE_INVALID:
      default:
      {
        /* Cannot decide alert using this status, continue and check next certificate status */
        localAlert = TCPIP_TLS_ALERT_UNSET;
        break;
      }
    } /* switch() */
  }
  return localAlert;
} /* TcpIp_TlsCoreUtil_TlsGetAlertForCertificateStatus() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_TlsGetAlertForOcspCertificateStatus
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(TcpIp_TlsAlertDescriptionType, TCPIP_CODE) TcpIp_TlsCoreUtil_TlsGetAlertForOcspCertificateStatus(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsCertValidationStatusDynIterType TlsCertValidationStatusIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsAlertDescriptionType localAlert = TCPIP_TLS_ALERT_UNSET;

  TCPIP_P2C(TcpIp_CertValidationStatusType) currentCertStatusPtr
    = TcpIp_GetAddrTlsCertValidationStatusDyn(TlsCertValidationStatusIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the Certificate Status Request feature is enabled */
  if (TcpIp_IsTlsUseExtensionCertificateStatusRequestOfTlsConnection(TlsConIdx) == TRUE)
  {
    /* #20 OCSP enabled, determine the alert description for the given certificate */
    if (currentCertStatusPtr->CertStatusResponse.OcspConnectionState == TCPIP_TLS_OCSP_CONNECTION_STATE_REQUESTED)
    {
      /* OCSP was requested by the TLS Client, but no OCSP Certificate Status response received */
      localAlert = TCPIP_TLS_ALERT_DESC_BAD_CERT_STATUS_RESP;
    }

    if (currentCertStatusPtr->CertStatusResponse.OcspConnectionState == TCPIP_TLS_OCSP_CONNECTION_STATE_STATUS_RECEIVED)
    {
      /* OCSP Certificate Status response received, check the state of the certificate */
      switch (currentCertStatusPtr->CertStatusResponse.OcspCertStatus)
      {
        case KEYM_E_CERTIFICATE_REVOKED:
        {
          /* Certificate is revoked via OCSP */
          localAlert = TCPIP_TLS_ALERT_DESC_CERT_REVOKED;
          break;
        }
        default:
        {
          /* No reason for alert, continue */
          localAlert = TCPIP_TLS_ALERT_UNSET;
          break;
        }
      } /* switch */
    } /* else - No OCSP response received, nothing to do */
  } /* else - OCSP not enabled, nothing to do */

  return localAlert;
} /* TcpIp_TlsCoreUtil_TlsGetAlertForOcspCertificateStatus() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_TlsGetAlertForOcspResponseStatus
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(TcpIp_TlsAlertDescriptionType, TCPIP_CODE) TcpIp_TlsCoreUtil_TlsGetAlertForOcspResponseStatus(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsCertValidationStatusDynIterType TlsCertValidationStatusIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsAlertDescriptionType localAlert = TCPIP_TLS_ALERT_UNSET;

  TCPIP_P2C(TcpIp_CertValidationStatusType) currentCertStatusPtr
    = TcpIp_GetAddrTlsCertValidationStatusDyn(TlsCertValidationStatusIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the Certificate Status Request feature is enabled */
  if (TcpIp_IsTlsUseExtensionCertificateStatusRequestOfTlsConnection(TlsConIdx) == TRUE)
  {
    /* #20 OCSP enabled, check if the OCSP Certificate Status is received */
    if (currentCertStatusPtr->CertStatusResponse.OcspConnectionState == TCPIP_TLS_OCSP_CONNECTION_STATE_STATUS_RECEIVED)
    {
      /* #30 Valid OCSP Response received, check the OCSP response status and determine the alert description for the given certificate */
      switch (currentCertStatusPtr->CertStatusResponse.OcspResponseStatus)
      {
        case TCPIP_TLS_OCSP_RESPONSE_STATUS_MALFORMEDREQUEST:
        case TCPIP_TLS_OCSP_RESPONSE_STATUS_INTERNALERROR:
        case TCPIP_TLS_OCSP_RESPONSE_STATUS_TRYLATER:
        case TCPIP_TLS_OCSP_RESPONSE_STATUS_SIGREQUIRED:
        case TCPIP_TLS_OCSP_RESPONSE_STATUS_UNAUTHORIZED:
        case TCPIP_TLS_OCSP_RESPONSE_STATUS_INVALID:

        {
          /* Certificate is revoked via OCSP */
          localAlert = TCPIP_TLS_ALERT_DESC_BAD_CERT_STATUS_RESP;
          break;
        }
        default:
        {
          /* TCPIP_TLS_OCSP_RESPONSE_STATUS_SUCCESSFUL */
          /* No reason for alert, continue and check next certificate status */
          localAlert = TCPIP_TLS_ALERT_UNSET;
          break;
        }
      } /* switch */
    } /* else - No OCSP response received, nothing to do */
  } /* else - OCSP not enabled, nothing to do */

  return localAlert;
} /* TcpIp_TlsCoreUtil_TlsGetAlertForOcspResponseStatus() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_GetCurveFromCertificate
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUtil_GetCurveFromCertificate(
  TcpIp_CertificateIdType                   CertId,
  TCPIP_P2V(TcpIp_TlsEllipticCurveIdType)   CurveIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsKeyMCertificateType tlsKeyMCertificateIdx = TCPIP_TLS_CERT_ID_TO_IDX(CertId);
  uint8  oidString[TCPIP_TLS_OID_MAX_LEN];  /* array to read all relevant OIDs from the certs */
  uint32 oidLen = TCPIP_TLS_OID_MAX_LEN;    /* init with max length */
  TCPIP_P2V(uint8) oidPtr = &oidString[0];
  Std_ReturnType retVal = E_NOT_OK;
  Std_ReturnType localRetVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Read the public key algorithm. */
  localRetVal = KeyM_CertElementGet(CertId,
    TcpIp_GetPubKeyAlgorithmElementIdOfTlsKeyMCertificate(tlsKeyMCertificateIdx), oidPtr, &oidLen);

  if (localRetVal == E_OK)
  {
    /* #20 Check length and content for the public key. */
    switch (oidLen)
    {
      case TCPIP_TLS_OID_SIGNATURE_ALGORITHM_CURVE_25519_448_LEN:
      {
        /* The length matches the length of an Ed25519 / X25519 / Ed448 / x448 algorithm. Check if the object Id also checks out.
         * The object Id is different for Ed25519 or X25519 (Ed488 or X448 respectively), but the curve to be returned is the same. */
        if (   (IpBase_StrCmpLen(oidPtr, &TcpIp_Tls_OidSignatureAlgorithmCurveEd25519[0], (uint16)oidLen)               /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
                  == IPBASE_CMP_EQUAL)
            || (IpBase_StrCmpLen(oidPtr, &TcpIp_Tls_OidSignatureAlgorithmX25519[0], (uint16)oidLen)                     /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
                  == IPBASE_CMP_EQUAL))
        {
          /* 25519 curve: Nothing more to be checked, since public key curve element does not exist in this case. */
          *CurveIdPtr = TCPIP_CURVE_ID_X25519;
          retVal = E_OK;
        }
        else if (   (IpBase_StrCmpLen(oidPtr, &TcpIp_Tls_OidSignatureAlgorithmCurveEd448[0], (uint16)oidLen)            /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
                       == IPBASE_CMP_EQUAL)
                 || (IpBase_StrCmpLen(oidPtr, &TcpIp_Tls_OidSignatureAlgorithmX448[0], (uint16)oidLen)                  /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
                       == IPBASE_CMP_EQUAL))
        {
          /* 448 curve: Nothing more to be checked, since public key curve element does not exist in this case. */
          *CurveIdPtr = TCPIP_CURVE_ID_X448;
          retVal = E_OK;
        }
        else
        {
          /* else - unknown public key algorithm */
        }
        break;
      } /* case TCPIP_TLS_OID_SIGNATURE_ALGORITHM_CURVE_25519_448_LEN */
      case TCPIP_TLS_OID_PUBKEY_EC_LEN:
      {
        /* The length matches the length of an Elliptic curve algorithm. Check if the object Id also checks out. */
        if (IpBase_StrCmpLen(oidPtr, &TcpIp_Tls_OidPubKeyTypeEc[0], (uint16)oidLen) == IPBASE_CMP_EQUAL)                /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
        {
          /* The public key algorithm of the certificate is "elliptic curve public key cryptography"
           * Right now we support Secp256 and Secp521 as curves for this algorithm. */
           /* #30 Read the curve type. */
          if (TcpIp_TlsCoreUtil_GetCurveFromPubKeyCurveElement(CertId, CurveIdPtr) == E_OK)
          {
            retVal = E_OK;
          }
        } /* else - unknown public key algorithm */
        break;
      } /* case TCPIP_TLS_OID_PUBKEY_EC_LEN */
      default:
      {
        /* Unknown public key algorithm, retVal already set to E_NOT_OK, intentionally left blank */
        break;
      }
    } /* switch */
  }
  return retVal;
} /* TcpIp_TlsCoreUtil_GetCurveFromCertificate */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_GetCurveFromPubKeyCurveElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_TcpIp_STCAL_CslAccess */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUtil_GetCurveFromPubKeyCurveElement(
  TcpIp_CertificateIdType                   CertId,
  TCPIP_P2V(TcpIp_TlsEllipticCurveIdType)   CurveIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsKeyMCertificateType tlsKeyMCertificateIdx = TCPIP_TLS_CERT_ID_TO_IDX(CertId);
  uint8  oidString[TCPIP_TLS_OID_MAX_LEN];  /* array to read all relevant OIDs from the certs */
  uint32 oidLen = TCPIP_TLS_OID_MAX_LEN;    /* init with max length */
  TCPIP_P2V(uint8) oidPtr = &oidString[0];
  Std_ReturnType retVal = E_NOT_OK;
  Std_ReturnType localRetVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Read the curve type. */
  oidLen = TCPIP_TLS_OID_MAX_LEN;
  localRetVal = KeyM_CertElementGet(CertId,
    TcpIp_GetPubKeyCurveElementIdOfTlsKeyMCertificate(tlsKeyMCertificateIdx), oidPtr, &oidLen);

  if (localRetVal == E_OK)
  {
    /* #20 Check length and content for the curve type. */
    switch (oidLen)
    {
      case TCPIP_TLS_OID_PUBKEY_NAMED_CURVE_SECP256R1_LEN:
      {
        /* The length matches the length of the Secp256 curve element. Check if the object Id also checks out. */
        if (IpBase_StrCmpLen(oidPtr, &TcpIp_Tls_OidPubKeyNamedCurveSecp256r1[0], (uint16)oidLen) == IPBASE_CMP_EQUAL)   /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
        {
          /* Curve is Secp256. */
          *CurveIdPtr = TCPIP_CURVE_ID_SECP256R1;
          retVal = E_OK;
        } /* else - unknown curve */
        break;
      } /* case TCPIP_TLS_OID_PUBKEY_NAMED_CURVE_SECP256R1_LEN */
      case TCPIP_TLS_OID_PUBKEY_NAMED_CURVE_SECP521R1_LEN:
      {
        /* The length matches the length of the Secp521 curve element. Check if the object Id also checks out. */
        if (IpBase_StrCmpLen(oidPtr, &TcpIp_Tls_OidPubKeyNamedCurveSecp521r1[0], (uint16)oidLen) == IPBASE_CMP_EQUAL)   /* PRQA S 3415 */ /* MD_TCPIP_Rule13.5_3415_ReadOnly */
        {
          /* Curve is Secp521. */
          *CurveIdPtr = TCPIP_CURVE_ID_SECP521R1;
          retVal = E_OK;
        } /* else - unknown curve */
        break;
      } /* case TCPIP_TLS_OID_PUBKEY_NAMED_CURVE_SECP521R1_LEN */
      default:
      {
        /* Unknown curve, retVal already set to E_NOT_OK, intentionally left blank */
        break;
      }
    } /* switch */
  }
  return retVal;
} /* TcpIp_TlsCoreUtil_GetCurveFromPubKeyCurveElement */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_CheckSignatureAlgorithmAgainstCertificateAlgorithm
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUtil_CheckSignatureAlgorithmAgainstCertificateAlgorithm(
  TcpIp_TlsConnectionIterType    TlsConIdx,
  TcpIp_SignatureAlgorithmIdType SignatureAlgorithm)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  TcpIp_SignatureAlgorithmIdType remoteCertSigAlg = TCPIP_SIG_ALGO_ID_NONE;
  TcpIp_TlsCertValidationStatusDynStartIdxOfTlsConnectionType tlsCertValidationStatusIdx
    = TcpIp_GetTlsCertValidationStatusDynStartIdxOfTlsConnection(TlsConIdx);
  TcpIp_CertificateIdType certId = 0u;

  /* ----- Implementation ----------------------------------------------- */
  if (tlsCertValidationStatusIdx < TCPIP_NO_TLSCERTVALIDATIONSTATUSDYNSTARTIDXOFTLSCONNECTION)
  {
    certId = TcpIp_GetAddrTlsCertValidationStatusDyn(tlsCertValidationStatusIdx)->CertId;
    /* #10 Read the signature algorithm of the received certificate. */
    if (TcpIp_TlsCoreUtil_ReadCertSignatureAlgorithm(certId, &remoteCertSigAlg) == E_OK)
    {
      /* #20 Check if the signature algorithm of the certificate matches the signature algorithm.*/
      if (SignatureAlgorithm == remoteCertSigAlg)
      {
        retVal = E_OK;
      }
    }
  }

  return retVal;
} /* TcpIp_TlsCoreUtil_CheckSignatureAlgorithmAgainstCertificateAlgorithm() */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_ReadCertSignatureAlgorithm
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreUtil_ReadCertSignatureAlgorithm(
  TcpIp_CertificateIdType CertId,
  TCPIP_P2V(TcpIp_SignatureAlgorithmIdType) SignAlgIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 oidString[TCPIP_TLS_OID_MAX_LEN];  /* array to read all relevant OIDs from the certs */
  uint32 oidLen = TCPIP_TLS_OID_MAX_LEN;   /* init with max length */
  TCPIP_P2V(uint8) oidPtr = &oidString[0];
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Read the signature algorithm id from the cert. */
  retVal = KeyM_CertStructureGet(CertId, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID, oidPtr, &oidLen);

  if (retVal == E_OK)
  {
    /* The KeyM returns every byte of the requested structure including the structure/object identifiers upfront in the certificate.
     * In this case, this leads to an offset of 2 Bytes (AlgorithmIdentifier (0x30, <length_byte>)).
     * Check if ObjectIdentifier indicates the signature algorithm (0x06) */
    if (oidPtr[TCPIP_TLS_OID_ALGO_ID_OFFSET] == TCPIP_TLS_OID_ALGO_ID_ID)
    {
      /* Read length field of the object */
      uint8 sigAlgoOidLen = oidPtr[TCPIP_TLS_OID_ALGO_ID_OFFSET + TCPIP_TLS_OID_ALGO_ID_LEN];
      /* Set signature algorithm pointer to byte after the length field of the object */
      TCPIP_P2C(uint8) sigAlgoOidPtr = &oidPtr[TCPIP_TLS_OID_ALGO_ID_OFFSET + TCPIP_TLS_OID_OBJECT_ID_OFFSET];

      *SignAlgIdPtr = TCPIP_SIG_ALGO_ID_NONE;

      /* #20 Process the signature algorithm OID id depending on the length of the id. */
      if (sigAlgoOidLen == TCPIP_TLS_OID_SIGNATURE_ALGORITHM_ECDSA_SHA_LEN)  /* len = 8 */
      {
        /* OID EcdsaSha256 and EcdsaSha512 both have this length */
        if (   IpBase_StrCmpLen(sigAlgoOidPtr, &TcpIp_Tls_OidSignatureAlgorithmEcdsaSha256[0], (uint16)sigAlgoOidLen)
            == IPBASE_CMP_EQUAL)
        {
          /* The signature algorithm of the certificate is EcdsaSha256 */
          *SignAlgIdPtr = TCPIP_SIG_ALGO_ID_ECDSA_SECP256R1_SHA256;
        }
        else if (   IpBase_StrCmpLen(sigAlgoOidPtr, &TcpIp_Tls_OidSignatureAlgorithmEcdsaSha512[0], (uint16)sigAlgoOidLen)
                 == IPBASE_CMP_EQUAL)
        {
          /* The signature algorithm of the certificate is EcdsaSha512 */
          *SignAlgIdPtr = TCPIP_SIG_ALGO_ID_ECDSA_SECP521R1_SHA512;
        }
        else
        {
          /* Unknown signature algorithm */
          /* SignAlgIdPtr is already set to TCPIP_SIG_ALGO_ID_NONE */
        }
      }
      else if (sigAlgoOidLen == TCPIP_TLS_OID_SIGNATURE_ALGORITHM_CURVE_25519_448_LEN)  /* len = 3 */
      {
        /* length of OID CurveEd25519/Ed448 */
        if (   IpBase_StrCmpLen(sigAlgoOidPtr, &TcpIp_Tls_OidSignatureAlgorithmCurveEd25519[0], (uint16)sigAlgoOidLen)
            == IPBASE_CMP_EQUAL)
        {
          /* The signature algorithm of the certificate is CurveEd25519 */
          *SignAlgIdPtr = TCPIP_SIG_ALGO_ID_ECDSA_ED25519_INTRINSIC;
        }
        else if (   IpBase_StrCmpLen(sigAlgoOidPtr, &TcpIp_Tls_OidSignatureAlgorithmCurveEd448[0], (uint16)sigAlgoOidLen)
                 == IPBASE_CMP_EQUAL)
        {
          /* The signature algorithm of the certificate is CurveEd25519 */
          *SignAlgIdPtr = TCPIP_SIG_ALGO_ID_ECDSA_ED448_INTRINSIC;
        }
        else
        {
          /* else: unknown signature algorithm */
        }
      }
      else  /* other OID lengths */
      {
        /* unknown OID length */
        /* SignAlgIdPtr is already set to TCPIP_SIG_ALGO_ID_NONE */
      }
    }
    /* object can not be identified to include the signature algorithm */
  }

  return retVal;
} /* TcpIp_TlsCoreUtil_ReadCertSignatureAlgorithm */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreUtil_HasIpBaseBerElementExpectedValues
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(boolean, TCPIP_CODE) TcpIp_TlsCoreUtil_HasIpBaseBerElementExpectedValues(
  TCPIP_P2C(IpBase_BerElementType)    EleDescPtr,
  uint8                               ContentType,
  uint32                              MinContentLen,
  uint32                              MaxContentLen,
  TCPIP_P2C(uint8)                    ReceivedSignaturePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 ContentLen = EleDescPtr->EndIdx - EleDescPtr->ContentIdx;
  boolean retVal = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the type matches the expectation and that content length is within the defined boundaries. */
  if ((EleDescPtr->Type == ContentType) && (ContentLen <= MaxContentLen) && (ContentLen >= MinContentLen))
  {
    retVal = TRUE;
    /* When the content type is integer there are a few more rules, which are currently not checked by the IpBase. */
    /* The content length must be greater than zero for these additional checks. */
    if ((ContentType == TCPIP_TLS_ASN1TAG_INTEGER_ID) && (ContentLen > 0u))
    {
      /* #20 Check integer specific rules. */
      if (ReceivedSignaturePtr[EleDescPtr->ContentIdx] >= TCPIP_TLS_ASN1_INTEGER_STARTVALUE_LEADINGZERO)
      {
        /* The first byte must not be greater or equal to 0x80. Such a byte must be preceded by a leading zero. */
        retVal = FALSE;
      }
      /* Make sure that the content length is greater than 1 byte before checking the following rule. */
      if (   (ContentLen > 1u)
          && (ReceivedSignaturePtr[EleDescPtr->ContentIdx] == 0u)
          && (ReceivedSignaturePtr[EleDescPtr->ContentIdx + 1u] < TCPIP_TLS_ASN1_INTEGER_STARTVALUE_LEADINGZERO))
      {
        /* If there is a leading zero, the following byte must be greater or equal to 0x80. */
        /* A integer value can consist only out of a zero,
         * in this case we would not enter this case since the content length would be 1 byte. */
        retVal = FALSE;
      }
    }
  }

  return retVal;
} /* TcpIp_TlsCoreUtil_HasIpBaseBerElementExpectedValues */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCtx_ForwardKeyToCsmForDhSharedSecretCalculation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCtx_ForwardKeyToCsmForDhSharedSecretCalculation(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  TCPIP_P2C(uint8)              PublicKeyPtr,
  uint32                        PublicKeyLen,
  TCPIP_P2V(uint16)             LocalErrorIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsHandshakeIterType activeTlsHandshakeIdx =
    TcpIp_GetTlsHandshakeActiveIdxOfTlsCipherWorkerDyn(TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx));
  uint32 keyExchangeCsmKey = TcpIp_GetCsmKeyId(TcpIp_GetCsmKeyIdKeyExchangeIdxOfTlsHandshake(activeTlsHandshakeIdx));
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the current key valid */
  if (TCPIP_CSM_KeySetValid(keyExchangeCsmKey) == E_OK)
  {
    /* #20 Calculate the Diffie-Hellman shared secret  */
    if (TCPIP_CSM_KeyExchangeCalcSecret(keyExchangeCsmKey, PublicKeyPtr, PublicKeyLen) == E_OK)
    {
      retVal = E_OK;
    }
    else
    {
      /* Error crypto CSM call failed */
      *LocalErrorIdPtr = TCPIP_TLS_ERRORID_CRYPTO_CSM_CALL_FAILED;
    }
  }
  else
  {
    /* Error Crypt CSM Key set valid failed */
    *LocalErrorIdPtr = TCPIP_TLS_ERRORID_CRYPTO_SET_VALID_FAILED;
  }
  return retVal;

} /* TcpIp_TlsCoreCtx_ForwardKeyToCsmForDhSharedSecretCalculation() */
# endif /* (TCPIP_SUPPORT_ASRTLS_ECC == STD_ON) */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreCrypto_CheckCsmResult
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreCrypto_CheckCsmResult(
  TcpIp_TlsConnectionIterType TlsConIdx,
  Std_ReturnType CsmRetVal,
  uint32 CsmResultLength,
  uint32 ExpectedResultLength,
  TcpIp_TlsFunctionIdType ApiId)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsUserErrorIdType errorID = TCPIP_TLS_ERRORID_NOT_SET;                                                         /* PRQA S 2981 */ /* MD_TCPIP_Rule2.2_RedundantAssignment */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check CSM return value and set the errorId */
  /* For CSM calls the return value could also be BUSY, in that case it should be handled as E_NOT_OK. */
  if (CsmRetVal == E_OK)
  {
    /* if E_OK, check if the CSM Call return length is the expected length */
    if (CsmResultLength == ExpectedResultLength)
    {
      /* Set retVal to E_OK */
      retVal = E_OK;
    }
    else
    {
      /* set the user error code to length mismatch */
      errorID = TCPIP_TLS_ERRORID_CRYPTO_CSM_LEN_MISMATCH;
    }
  }
  else
  {
    /* set the user error code to call failed */
    errorID = TCPIP_TLS_ERRORID_CRYPTO_CSM_CALL_FAILED;
  }

  /* #20 Report user error if necessary */
  if (retVal != E_OK)
  {
    /* report the user error */
    TcpIp_TlsUserErrorType userError;

    userError.FunctionId = ApiId;
    userError.UserErrorId = errorID;
    userError.TlsConId = TCPIP_TLS_CONNECTION_IDX_TO_ID(TlsConIdx);

    TcpIp_TlsCoreError_ReportUserError(userError);
  }

  return retVal;
} /* TcpIp_TlsCoreCrypto_CheckCsmResult() */

/**********************************************************************************************************************
 *  TLS RX BUFFER MANAGEMENT / DECRYPT
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_GetRxWriteIdxForContentType
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(TcpIp_SizeOfTlsBufferRxType, TCPIP_CODE)  TcpIp_TlsCoreRl_GetRxWriteIdxForContentType(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC)     ContentType)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferRxType retVal = 0u;
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return write index based on ContentType */
  if ((ContentType == TCPIP_TLS_CT_HS) || (ContentType == TCPIP_TLS_CT_AD))
  {
    /* Application data and handshake share the same buffer.
     * To get the write index this function can be called with either content type. */
    retVal = TcpIp_GetTlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  }
  else if (ContentType == TCPIP_TLS_CT_CCS)
  {
    retVal = TcpIp_GetTlsBufferRxCcsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  }
  else if (ContentType == TCPIP_TLS_CT_AL)
  {
    retVal = TcpIp_GetTlsBufferRxAlWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  }
  else
  {
    /* should not be reached */
    TcpIp_CallDetReportError(TCPIP_API_ID_CBK_RX_INDICATION, TCPIP_E_INV_RUNTIME_CHECK);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_GetRxReadIdxForContentType
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(TcpIp_SizeOfTlsBufferRxType, TCPIP_CODE)  TcpIp_TlsCoreRl_GetRxReadIdxForContentType(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC)     ContentType)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferRxType retVal = 0u;
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return read index based on ContentType */
  if ((ContentType == TCPIP_TLS_CT_HS) || (ContentType == TCPIP_TLS_CT_AD))
  {
    /* Application data and handshake share the same buffer.
     * To get the read index this function can be called with either content type. */
    retVal = TcpIp_GetTlsBufferRxAdHsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  }
  else if (ContentType == TCPIP_TLS_CT_CCS)
  {
    retVal = TcpIp_GetTlsBufferRxCcsReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  }
  else if (ContentType == TCPIP_TLS_CT_AL)
  {
    retVal = TcpIp_GetTlsBufferRxAlReadIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);
  }
  else
  {
    /* should not be reached */
    TcpIp_CallDetReportError(TCPIP_API_ID_CBK_RX_INDICATION, TCPIP_E_INV_RUNTIME_CHECK);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_GetRxEndIdxForContentType
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(TcpIp_SizeOfTlsBufferRxType, TCPIP_CODE)  TcpIp_TlsCoreRl_GetRxEndIdxForContentType(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC)     ContentType)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferRxType retVal = 0u;
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return Rx buffer end index based on ContentType */
  if ((ContentType == TCPIP_TLS_CT_HS) || (ContentType == TCPIP_TLS_CT_AD))
  {
    /* Application data and handshake share the same buffer.
     * To get the end index this function can be called with either content type. */
    retVal = TcpIp_GetTlsBufferRxAdHsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);
  }
  else if (ContentType == TCPIP_TLS_CT_CCS)
  {
    retVal = TcpIp_GetTlsBufferRxCcsEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);
  }
  else if (ContentType == TCPIP_TLS_CT_AL)
  {
    retVal = TcpIp_GetTlsBufferRxAlEndIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);
  }
  else
  {
    /* should not be reached */
    TcpIp_CallDetReportError(TCPIP_API_ID_CBK_RX_INDICATION, TCPIP_E_INV_RUNTIME_CHECK);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_SetRxWriteIdxForContentType
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE)  TcpIp_TlsCoreRl_SetRxWriteIdxForContentType(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC)     ContentType,
  TcpIp_SizeOfTlsBufferRxType Value)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set write index based on ContentType */
  if ((ContentType == TCPIP_TLS_CT_HS) || (ContentType == TCPIP_TLS_CT_AD))
  {
    /* Application data and handshake share the same buffer.
     * To set the write index this function can be called with either content type. */
    TcpIp_SetTlsBufferRxAdHsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, Value);
  }
  else if (ContentType == TCPIP_TLS_CT_CCS)
  {
    TcpIp_SetTlsBufferRxCcsWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, Value);
  }
  else if (ContentType == TCPIP_TLS_CT_AL)
  {
    TcpIp_SetTlsBufferRxAlWriteIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, Value);
  }
  else
  {
    /* should not be reached */
    TcpIp_CallDetReportError(TCPIP_API_ID_CBK_RX_INDICATION, TCPIP_E_INV_RUNTIME_CHECK);
  }
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_GetReadMaxIdxForContentType
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(TcpIp_SizeOfTlsBufferRxType, TCPIP_CODE)  TcpIp_TlsCoreRl_GetReadMaxIdxForContentType(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  CONST(uint8, AUTOMATIC)       ContentType)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferRxType retVal = TcpIp_TlsCoreRl_GetRxEndIdxForContentType(TlsConIdx, ContentType);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get buffer end index based on ContentType */
  if ((ContentType == TCPIP_TLS_CT_HS) || (ContentType == TCPIP_TLS_CT_AD) || (ContentType == TCPIP_TLS_CT_AL))
  {
    /* This two blocks should be kept free for the CSM decrypt jobs.
     * One block is in some situation for CBC not enough because up to one block must be subtracted to avoid that
     * the algorithm keeps the last block in memory. */
# if ( TCPIP_DEV_ERROR_DETECT == STD_ON )
    if (retVal <= ((TcpIp_SizeOfTlsBufferRxType)TcpIp_TlsCoreRl_GetActiveRxBlockSize(TlsConIdx) * 2u))
    {
      /* This path shall never be reached. This is ensured by the generator implementation. */
      TcpIp_CallDetReportError(TCPIP_API_ID_CBK_RX_INDICATION, TCPIP_E_INV_RUNTIME_CHECK);
    }
    else
# endif
    {
      /* #20 Subtract two block sizes and return this value. */
      retVal -= (TcpIp_SizeOfTlsBufferRxType)(TcpIp_TlsCoreRl_GetActiveRxBlockSize(TlsConIdx)) * 2u;
    }
  }
  else if (ContentType == TCPIP_TLS_CT_CCS)
  {
    /* Return the end index for the CCS buffer since we do not support a wraparound in this buffer
     * and CCS messages are never decrypted therefore we also do not need extra space for CSM decrypt calls.
     * The end index is returned since this is the maximum index till data can be read in this buffer. */
  }
  else
  {
    /* Other content types are not expected. */
    TcpIp_CallDetReportError(TCPIP_API_ID_CBK_RX_INDICATION, TCPIP_E_INV_RUNTIME_CHECK);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_GetRxStartIdxForContentType
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(TcpIp_SizeOfTlsBufferRxType, TCPIP_CODE)  TcpIp_TlsCoreRl_GetRxStartIdxForContentType(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  CONST(uint8, AUTOMATIC)       ContentType)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferRxType retVal = 0u;
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx
    = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the buffer start index based on ContentType */
  if ((ContentType == TCPIP_TLS_CT_HS) || (ContentType == TCPIP_TLS_CT_AD))
  {
    /* Application data and handshake share the same buffer.
     * To get the start index this function can be called with either content type. */
    retVal = TcpIp_GetTlsBufferRxAdHsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);
  }
  else if (ContentType == TCPIP_TLS_CT_AL)
  {
    retVal = TcpIp_GetTlsBufferRxAlStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);
  }
  else if (ContentType == TCPIP_TLS_CT_CCS)
  {
    retVal = TcpIp_GetTlsBufferRxCcsStartIdxOfTlsBufferMgmt(tlsBufferMgmtIdx);
  }
  else
  {
    /* Other content types are not expected. */
    TcpIp_CallDetReportError(TCPIP_API_ID_CBK_RX_INDICATION, TCPIP_E_INV_RUNTIME_CHECK);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_GetActiveRxBlockSize
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(uint8, TCPIP_CODE)  TcpIp_TlsCoreRl_GetActiveRxBlockSize(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherStreamingModeDataType activeStreamingMode =
    TcpIp_TlsCoreUtil_ReturnCipherSpecificStreamingMode(TcpIp_GetActiveCipherRxOfTlsConnectionDyn(TlsConIdx));
  uint8 retVal = TCPIP_TLS_NULL_BLOCKSIZE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the blocksize of the algorithm specified by the streaming mode */
  switch (activeStreamingMode)
  {
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
    case TCPIP_TLS_STREAMING_MODE_AES_128_CBC:
# endif
    case TCPIP_TLS_STREAMING_MODE_AES_128_GCM:
# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    case TCPIP_TLS_STREAMING_MODE_AES_256_GCM:
    case TCPIP_TLS_STREAMING_MODE_CHACHA20_POLY1305:
# endif
    {
      retVal = TCPIP_TLS_BLOCK128_BLOCKSIZE;
      break;
    } /* case Block128 streaming */
    case TCPIP_TLS_STREAMING_MODE_NULL:
    {
      /* retVal is already set to TCPIP_TLS_NULL_BLOCKSIZE */
      break;
    } /* case Null streaming */
    default:
    {
      /* unsupported streaming mode */
      TcpIp_CallDetReportError(TCPIP_API_ID_CBK_RX_INDICATION, TCPIP_E_INV_RUNTIME_CHECK);
      break;
    } /* default */
  } /* switch */

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_CheckIfCipherRequiresVerification
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE) TcpIp_TlsCoreRl_CheckIfCipherRequiresVerification(
  CONST(TcpIp_TlsCipherDataType, AUTOMATIC) Cipher)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Depending on the active cipher, check if hash verify is required */
  switch (TcpIp_TlsCoreUtil_ReturnCipherSpecificAuthenticationMode(Cipher))
  {
    case TCPIP_TLS_MSG_AUTH_MODE_SHA1:
    case TCPIP_TLS_MSG_AUTH_MODE_SHA256:
    case TCPIP_TLS_MSG_AUTH_MODE_SHA384:
    {
      retVal = TRUE;
      break;
    } /* case Sha authentication */
    case TCPIP_TLS_MSG_AUTH_MODE_NONE:
    {
      /* Nothing to do, retVal is already set to FALSE */
      break;
    }
    default:
    {
      /* unsupported authentication mode */
      TcpIp_CallDetReportError(TCPIP_API_ID_CBK_RX_INDICATION, TCPIP_E_INV_RUNTIME_CHECK);
      break;
    } /* default */
  } /* switch */

  return retVal;
} /* TcpIp_TlsCoreRl_CheckIfCipherRequiresVerification */

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_GetAvailableLinearRxBufferSpace
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(TcpIp_SizeOfTlsBufferRxType, TCPIP_CODE)  TcpIp_TlsCoreRl_GetAvailableLinearRxBufferSpace(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  CONST(uint8, AUTOMATIC)       ContentType)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferRxType writeIdx = TcpIp_TlsCoreRl_GetRxWriteIdxForContentType(TlsConIdx, ContentType);
  TcpIp_SizeOfTlsBufferRxType readIdx = TcpIp_TlsCoreRl_GetRxReadIdxForContentType(TlsConIdx, ContentType);
  TcpIp_SizeOfTlsBufferRxType endIdx = TcpIp_TlsCoreRl_GetRxEndIdxForContentType(TlsConIdx, ContentType);

  TcpIp_SizeOfTlsBufferRxType retVal = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Depending on position of read and write index, calculate size of free space to write to in TLS Rx buffer */
  if (writeIdx >= readIdx)
  {
    /* #20 Calculate space till end of buffer */
    /* Use the end idx instead of read max idx to calculate how many bytes can be written. */
    retVal = endIdx - writeIdx;
  }
  else
  {
    /* #30 Calculate space till unread data */
    retVal = readIdx - writeIdx;
  }

  if ((ContentType == TCPIP_TLS_CT_AD) || (ContentType == TCPIP_TLS_CT_HS))
  {
    /* The generator creates an TLS buffer that is at least four blocks larger as the configured buffer.
       The readMaxArea is two blocks large, and the area between writeIdx and readidx is also at least two blocks large. */
    TCPIP_ASSERT(retVal >= TcpIp_TlsCoreRl_GetActiveRxBlockSize(TlsConIdx));
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_MoveDataOutOfReadMaxArea
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE)  TcpIp_TlsCoreRl_MoveDataOutOfReadMaxArea(
  TcpIp_TlsConnectionIterType       TlsConIdx,
  CONST(uint8, AUTOMATIC)           ContentType,
  TcpIp_SizeOfTlsBufferRxType       PlaintextLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 readMaxIdx = (uint32) TcpIp_TlsCoreRl_GetReadMaxIdxForContentType(TlsConIdx, ContentType);
  uint32 writeIdx   = (uint32) TcpIp_TlsCoreRl_GetRxWriteIdxForContentType(TlsConIdx, ContentType);
  uint32 startIdx   = (uint32) TcpIp_TlsCoreRl_GetRxStartIdxForContentType(TlsConIdx, ContentType);
  uint32 newWriteIdx = 0u;
  /* ----- Implementation ----------------------------------------------- */
  /* The return value can be ignored here since the indices must be correct. */
  (void) TcpIp_GetIncrementedRingBufferIndex(writeIdx, (uint32) PlaintextLen, startIdx, readMaxIdx, &newWriteIdx);

  if (newWriteIdx < writeIdx)
  {
    /* #10 In wraparound case copy remaining data beyond readMaxIdx to start of buffer */
    /* Since the new write index was already calculated we just have to fill the buffer
    * from start index to new write index. This length equals the length of the data beyond the ReadMaxIdx. */
    uint32 cpyLen = newWriteIdx - startIdx;

    /* For this and the next function for cpyLen == 0u nothing is done.
     * But the writeIdx shall be set to the buffer start */
    TcpIp_MemCpySafe(TcpIp_GetAddrTlsBufferRx(0), startIdx,
      TcpIp_GetSizeOfTlsBufferRx(), TcpIp_GetAddrTlsBufferRx((TcpIp_TlsBufferRxIterType)readMaxIdx), cpyLen);

    VStdLib_MemClr(TcpIp_GetAddrTlsBufferRx((TcpIp_TlsBufferRxIterType)readMaxIdx), cpyLen);
  }

  /* #20 Set new Rx buffer write index */
  TcpIp_TlsCoreRl_SetRxWriteIdxForContentType(TlsConIdx, ContentType, (TcpIp_SizeOfTlsBufferRxType) newWriteIdx);
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_DecryptIntoTlsRxBufferStep
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE)  TcpIp_TlsCoreRl_DecryptIntoTlsRxBufferStep(
  TcpIp_TlsConnectionIterType              TlsConIdx,
  CONST(uint8, AUTOMATIC)                  ContentType,
  TcpIp_ConstSegmentPtrType                TcpBufferSegPtr,
  TCPIP_P2C(TcpIp_SegmentType)             AddDataSegPtr,
  TCPIP_P2C(TcpIp_SegmentType)             AuthTagSegPtr,
  Crypto_OperationModeType                 CsmMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx =
    TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);

  uint32 availableSpace = (uint32)TcpIp_TlsCoreRl_GetAvailableLinearRxBufferSpace(TlsConIdx, ContentType);
  uint32 writeIdx = (uint32)TcpIp_TlsCoreRl_GetRxWriteIdxForContentType(TlsConIdx, ContentType);
  Std_ReturnType csmRetVal = E_NOT_OK;
  uint32 useCryptLen = TcpBufferSegPtr->AvailLen;

  /* The CsmMode flags are copied locally to modify them for only this decrypt call. */
  Crypto_OperationModeType csmMode = CsmMode;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Calculate decrypt length for this step. */
  TcpIp_TlsCoreRl_CalcDecryptLen(TlsConIdx, ContentType, csmMode, &useCryptLen);

  /* If the crypt-length is reduced, the finish flag must be removed from the csmMode */
  if (useCryptLen != TcpBufferSegPtr->AvailLen)
  {
    TCPIP_REMOVE_FLAG(csmMode, CRYPTO_OPERATIONMODE_FINISH);
  }

  /* #20 Call CSM/Copy function */
  switch (TcpIp_GetDecryptAlgoTypeOfTlsConnectionDyn(TlsConIdx))
  {
    case TCPIP_TLS_DECRYPT_ALGO_TYPE_NULL:
    {
      TcpIp_MemCpyFromConstSegmentSafe(TcpIp_GetAddrTlsBufferRx(0u), writeIdx, TcpIp_GetSizeOfTlsBufferRx(),
                       TcpBufferSegPtr, useCryptLen);

      /* For NULL case this must be done manually, for the other cases the CSM does this. */
      availableSpace = useCryptLen;
      csmRetVal = E_OK;
      break;
    }
# if(TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) /* AES-CBC is only available for TLS 1.2 */
    case TCPIP_TLS_DECRYPT_ALGO_TYPE_CBC:
    {
      TcpIp_CsmJobIdType decryptJobId = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdCipherDecryptIdxOfTlsCipherWorker(
         activeTlsCipherWorkerIdx));
      csmRetVal = TcpIp_Tls12CoreCrypto_DecryptFromConstSegmentSafe(decryptJobId, csmMode, TcpBufferSegPtr,
                               useCryptLen, writeIdx, &availableSpace);
      break;
    }
# endif
    case TCPIP_TLS_DECRYPT_ALGO_TYPE_AEAD:
    {
      /* CSM only sets verifyResult to CSM_E_VER_OK when finish flag is set.
       * To not complicate thing initialize it with CSM_E_VER_OK. CSM will still set it if something went wrong. */
      Crypto_VerifyResultType verifyResult = CSM_E_VER_OK;
      TcpIp_CsmJobIdType decryptJobId
        = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdCipherDecryptIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));
      TCPIP_P2C(uint8) addDataPtr = AddDataSegPtr->BasePtr;
      uint32 addDataLen = AddDataSegPtr->Usage;

      /* Additional data are only allowed for the CSM call with mode contain Start */
      if (!TCPIP_IS_FLAG_SET(csmMode, CRYPTO_OPERATIONMODE_START))
      {
        addDataPtr = NULL_PTR;
        addDataLen = 0;
      }

      csmRetVal = TcpIp_TlsCoreCrypto_AEADDecryptFromConstSegmentSafe(decryptJobId, csmMode,
        TcpBufferSegPtr, useCryptLen,
        addDataPtr, addDataLen,
        AuthTagSegPtr->BasePtr, AuthTagSegPtr->Usage,
        writeIdx, &availableSpace,
        &verifyResult);

      if (verifyResult != CSM_E_VER_OK)
      {
        /* RFC 5246 specifies in chapter 6.2.3.3 for AEAD ciphers that
         * if decryption fails a bad_record_mac alert MUST be send. */
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_BAD_RECORD_MAC);
        csmRetVal = E_NOT_OK;
      }
      break;
    }
    default:
    {
      /* Shall not be called, csmRetVal is already E_NOT_OK */
      TcpIp_CallDetReportError(TCPIP_API_ID_CBK_RX_INDICATION, TCPIP_E_INV_RUNTIME_CHECK);
      break;
    }
  }

  if (csmRetVal == E_OK)
  {
    /* #30 Move data from behind the ReadMaxIdx to the start of the buffer and store the new Rx write index */
    TcpIp_TlsCoreRl_MoveDataOutOfReadMaxArea(TlsConIdx, ContentType, (TcpIp_SizeOfTlsBufferRxType)availableSpace);
  }

  /* #40 Check decrypt issues */
  /* csmRetVal is not directly returned since it might be BUSY. */
  return TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, 0u, 0u, TCPIP_TLS_FCTID_CORE_MAINFCT_RXRL);
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_DecryptPrepareCsmModeFlags
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE)  TcpIp_TlsCoreRl_DecryptPrepareCsmModeFlags(
  TCPIP_P2C(TcpIp_ConstSegmentType)        TcpBufferSegPtr,
  TCPIP_P2V(Crypto_OperationModeType)      CsmModePtr)
{
  /* #10 Remove the start flag */
  /* After the first CSM call, the CSM start flag is not longer allowed */
  TCPIP_REMOVE_FLAG(*CsmModePtr, CRYPTO_OPERATIONMODE_START);

  /* #20 If no more data is available, remove the finish flag to signal that process is done. */
  /* The while loop in function TcpIp_TlsCoreRl_DecryptTcpSegment is only exited when the finish flag not set. */
  if (TcpBufferSegPtr->AvailLen == 0u)
  {
    TCPIP_REMOVE_FLAG(*CsmModePtr, CRYPTO_OPERATIONMODE_FINISH);
  }
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_CalcDecryptLen
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE)  TcpIp_TlsCoreRl_CalcDecryptLen(
  TcpIp_TlsConnectionIterType                 TlsConIdx,
  CONST(uint8, AUTOMATIC)                     ContentType,
  CONST(Crypto_OperationModeType, AUTOMATIC)  Mode,
  TCPIP_P2V(uint32)                           CryptLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* Get the size of the next available linear segment to write to in the TLS Rx Buffer. */
  uint32 availableSpace = (uint32)TcpIp_TlsCoreRl_GetAvailableLinearRxBufferSpace(TlsConIdx, ContentType);
  uint8 blockSize = TcpIp_TlsCoreRl_GetActiveRxBlockSize(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Ensure that for finish calls the amount of data increased to a full block is not larger as the available space */
  if (   (    (ContentType == TCPIP_TLS_CT_AD) /* This is only required for the AdHs buffer */
           || (ContentType == TCPIP_TLS_CT_HS))
      && (TCPIP_IS_FLAG_SET(Mode, CRYPTO_OPERATIONMODE_FINISH))
      && (*CryptLenPtr > blockSize)
      && (TCPIP_IN_RANGE(availableSpace, *CryptLenPtr, (*CryptLenPtr + blockSize))))
  {
    /* Some Crypto algorithm need for the last data chunk to be encrypted more buffer space available
       than what is actually written with the decrypt operation.
       The length of the available buffer space shall be divisible by the block size,
       e.g. *CryptLenPtr = 100 (length of data to be encrypted) -> min space = 112 = roundUp(100 / 16) * 16 = 7 * 16
       Since we cannot increase the amount of available buffer,
       we have to decrease the amount of data we encrypt in this call.
       So reduce *CryptLenPtr to the next smaller length which is divisible by the block size.
    */
    uint8 unalignedBytes = (uint8)(*CryptLenPtr % blockSize); /* Typecast to uint8 because blocksize is < 0xFF */
    /* If the packet fits the blocksize perfectly, let one entire block free. */
    if (unalignedBytes == 0u) /* Size 0u means that the size is block aligned. */
    {
      unalignedBytes = blockSize;
    }
    *CryptLenPtr -= unalignedBytes;
    /* Keep the Finish flag set at the CsmModePtr, so that for the following call, Finish is still set.
     * For this call the Finish flag is removed in TcpIp_TlsCoreRl_DecryptIntoTlsRxBufferStep(). */
  }
  /* #20 If more data shall be decrypted as space available, let one block free to the end. */
  else if (availableSpace < *CryptLenPtr)
  {
    /* availableSpace is always at least two blocks, see TcpIp_TlsCoreRl_GetAvailableLinearRxBufferSpace() */
    *CryptLenPtr = availableSpace - blockSize;
  }
  else
  {
    /* Nothing to do */
    /* The encrypted data can be completely encrypted in this step. */
  }

  /* #30 While Finish is not set only use complete blocks */
  if (!TCPIP_IS_FLAG_SET(Mode, CRYPTO_OPERATIONMODE_FINISH))
  {
    *CryptLenPtr -= *CryptLenPtr % blockSize; /* Subtract the amount of data till the last complete block */
  }
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_DecryptTcpSegment
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE)  TcpIp_TlsCoreRl_DecryptTcpSegment(
  TcpIp_TlsConnectionIterType          TlsConIdx,
  CONST(uint8, AUTOMATIC)              ContentType,
  TcpIp_ConstSegmentPtrType            TcpBufferSegPtr,
  TCPIP_P2C(TcpIp_SegmentType)         AddDataSegPtr,
  TCPIP_P2C(TcpIp_SegmentType)         AuthTagSegPtr,
  TCPIP_P2V(Crypto_OperationModeType)  CsmModePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Call decrypt TCP data while more than one block is available, or till the end, if the Finish flag is set. */
  /* For calls with finish flag set but total TCP length 0u, the CSM function
   * must be called once to verify the hash (for AEAD CSM jobs). The finish flag is removed
   * in TcpIp_TlsCoreRl_DecryptPrepareCsmModeFlags() after the CSM job was called with finish. */
  while (   (TcpBufferSegPtr->AvailLen >= TcpIp_TlsCoreRl_GetActiveRxBlockSize(TlsConIdx))
         || (TCPIP_IS_FLAG_SET(*CsmModePtr, CRYPTO_OPERATIONMODE_FINISH)))
  {
    /* #20 Call the decrypt function */
    retVal = TcpIp_TlsCoreRl_DecryptIntoTlsRxBufferStep(TlsConIdx, ContentType, TcpBufferSegPtr,
                                                       AddDataSegPtr, AuthTagSegPtr, *CsmModePtr);

    /* #30 Prepare the CSM mode flags for the next decrypt call. */
    TcpIp_TlsCoreRl_DecryptPrepareCsmModeFlags(TcpBufferSegPtr, CsmModePtr);

    /* #40 Verify if anything goes wrong */
    if (retVal != E_OK)
    {
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_DecryptAndAuthenticateFrame
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
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_DecryptAndAuthenticateFrame(
  TcpIp_TlsConnectionIterType          TlsConIdx,
  CONST(uint8, AUTOMATIC)              ContentType,
  TCPIP_P2C(TcpIp_TlsDecryptDataType)  DecryptDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  /* The CSM mode is the flag collection for the next CSM decrypt call. The finish flag will be set later. */
  Crypto_OperationModeType mode = CRYPTO_OPERATIONMODE_START | CRYPTO_OPERATIONMODE_UPDATE;
  TcpIp_SizeOfTlsBufferRxType prevWriteIdx = TcpIp_TlsCoreRl_GetRxWriteIdxForContentType(TlsConIdx, ContentType);
  TCPIP_P2C(TcpIp_ConstSegmentType) tcpSeg1Ptr = DecryptDataPtr->TcpSeg1Ptr;
  TCPIP_P2C(TcpIp_ConstSegmentType) tcpSeg2Ptr = DecryptDataPtr->TcpSeg2Ptr;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Decrypt data from Tcp Segment 1, could be empty */
  Std_ReturnType retVal = TcpIp_TlsCoreRl_DecryptTcpSeg1(TlsConIdx, ContentType, &mode, DecryptDataPtr);

  /* #20 If there is data in TCP segment 1 remaining, decrypt together with some data of TCP segment 2 */
  if (retVal == E_OK)
  {
    retVal = TcpIp_TlsCoreRl_DecryptTcpSegMix(TlsConIdx, ContentType, &mode, DecryptDataPtr);
  }

  /* #30 If TCP segment 2 contains data, decrypt it. */
  if (retVal == E_OK)
  {
    retVal = TcpIp_TlsCoreRl_DecryptTcpSeg2(TlsConIdx, ContentType, &mode, DecryptDataPtr);
  }

  /* #40 Save length of plaintext data */
  if (retVal == E_OK)
  {
    /* Since currently we only support algorithms where the encrypted and decrypted message have the same length,
     * we can use the combined encrypted length of both Tcp segments to set RlRxCopiedLen.
     * The lengths of a possibly received HMAC or CBC padding are subtracted from RlRxCopiedLen in the following
     * functions. */
    TcpIp_SetRlRxCopiedLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
        (TcpIp_RlRxCopiedLenOfTlsBufferMgmtDynType)(tcpSeg1Ptr->Usage + tcpSeg2Ptr->Usage));
  }

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
  /* #50 Remove padding from buffer */
  if (retVal == E_OK)
  {
    retVal = TcpIp_TlsCoreRl_RxCheckAndRemovePadding(TlsConIdx, ContentType);
  }
# endif

  /* #60 Check and remove hash */
  if (retVal == E_OK)
  {
    retVal = TcpIp_TlsCoreRl_RxAuthenticateFrame(TlsConIdx, ContentType, prevWriteIdx);
  }

# if ( TCPIP_DEV_ERROR_DETECT == STD_ON )
  /* Store the current Rx indices and perform some basic range checks */
  TcpIp_TlsCoreRl_RxBufferIdxValidityCheck(TlsConIdx, TCPIP_TLS_CALL_POS_DECRYPT, ContentType);
# endif

  /* #70 Handle error case */
  if (retVal != E_OK)
  {
    TcpIp_SetRlRxCopiedLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx, 0u);
    TcpIp_TlsCoreRl_SetRxWriteIdxForContentType(TlsConIdx, ContentType, prevWriteIdx);
  }
  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_DecryptTcpSeg1
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_DecryptTcpSeg1(
  TcpIp_TlsConnectionIterType          TlsConIdx,
  CONST(uint8, AUTOMATIC)              ContentType,
  TCPIP_P2V(Crypto_OperationModeType)  CsmModePtr,
  TCPIP_P2C(TcpIp_TlsDecryptDataType)  DecryptDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  if (DecryptDataPtr->TcpSeg2Ptr->AvailLen == 0u)
  {
    /* If Tcp Segment 2 is empty, the Finish flag can be set. */
    TCPIP_SET_FLAG(*CsmModePtr, CRYPTO_OPERATIONMODE_FINISH);
  }

  /* #10 Decrypt data of TCP segment 1 */
  /* Empty segments will be covered inside */
  return TcpIp_TlsCoreRl_DecryptTcpSegment(TlsConIdx, ContentType, DecryptDataPtr->TcpSeg1Ptr,
                         DecryptDataPtr->AddAuthDataSegPtr, DecryptDataPtr->AuthSegPtr, CsmModePtr);
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_DecryptTcpSegMix
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_DecryptTcpSegMix(
  TcpIp_TlsConnectionIterType          TlsConIdx,
  CONST(uint8, AUTOMATIC)              ContentType,
  TCPIP_P2V(Crypto_OperationModeType)  CsmModePtr,
  TCPIP_P2C(TcpIp_TlsDecryptDataType)  DecryptDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if Data is available */
  if (DecryptDataPtr->TcpSeg1Ptr->AvailLen != 0u)
  {
    /* #20 Fill the tmp buffer with up to one blocksize of data */
    /* Calculate the lengths of datas that shall be copied to the temp buffer */
    uint32 remainingLen = TcpIp_TlsCoreRl_GetActiveRxBlockSize(TlsConIdx) - DecryptDataPtr->TcpSeg1Ptr->AvailLen;
    uint32 copySeg2Len = TCPIP_MIN(DecryptDataPtr->TcpSeg2Ptr->AvailLen, remainingLen);
    TcpIp_ConstSegmentType tmpConstSeg;
    TcpIp_SegmentType      tmpSeg;
    uint8 tmpBuffer[TCPIP_TLS_BLOCK128_BLOCKSIZE] = { 0 }; /* Use the size of the biggest supported blocksize */
    TcpIp_SegmentInit(&tmpSeg, &tmpBuffer[0], TCPIP_TLS_BLOCK128_BLOCKSIZE);

    /* Copy data to temp buffer and create buffer segment */
    TcpIp_SegmentMemCpyFromConstSegment(&tmpSeg, DecryptDataPtr->TcpSeg1Ptr, DecryptDataPtr->TcpSeg1Ptr->AvailLen);
    TcpIp_SegmentMemCpyFromConstSegment(&tmpSeg, DecryptDataPtr->TcpSeg2Ptr, copySeg2Len);
    TcpIp_ConstSegmentInitWithUsedSegment(&tmpConstSeg, &tmpSeg);

    /* #30 Call decrypt for the tmp data */
    /* If all data are used, use finish for next call */
    if (DecryptDataPtr->TcpSeg2Ptr->AvailLen == 0u)
    {
      TCPIP_SET_FLAG(*CsmModePtr, CRYPTO_OPERATIONMODE_FINISH);
    }
    retVal = TcpIp_TlsCoreRl_DecryptTcpSegment(TlsConIdx, ContentType, &tmpConstSeg,
                DecryptDataPtr->AddAuthDataSegPtr, DecryptDataPtr->AuthSegPtr, CsmModePtr);
  }
  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_DecryptTcpSeg2
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_DecryptTcpSeg2(
  TcpIp_TlsConnectionIterType          TlsConIdx,
  CONST(uint8, AUTOMATIC)              ContentType,
  TCPIP_P2V(Crypto_OperationModeType)  CsmModePtr,
  TCPIP_P2C(TcpIp_TlsDecryptDataType)  DecryptDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if Data is available */
  if (DecryptDataPtr->TcpSeg2Ptr->AvailLen != 0u)
  {
    /* #20 Call decrypt for that data */
    /* This data must contain the end of the RL, so finish must be set */
    TCPIP_SET_FLAG(*CsmModePtr, CRYPTO_OPERATIONMODE_FINISH);
    retVal = TcpIp_TlsCoreRl_DecryptTcpSegment(TlsConIdx, ContentType, DecryptDataPtr->TcpSeg2Ptr,
      DecryptDataPtr->AddAuthDataSegPtr, DecryptDataPtr->AuthSegPtr, CsmModePtr);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_AddRlHeaderForRxAuthentication
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_AddRlHeaderForRxAuthentication(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  CONST(uint8, AUTOMATIC)       ContentType,
  uint32                        DataLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_CsmJobIdType csmJobIdVerify
    = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHmacVerifyIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));
  uint8               tmpSeqCounterAndRlHdr[TCPIP_TLS_RL_SEQUENCE_NUM_LEN + TCPIP_TLS_RLHDRLEN];
  TCPIP_P2V(uint8)    seqCounterPtr = &tmpSeqCounterAndRlHdr[0];
  TCPIP_P2V(uint8)    rlHdrPtr = &tmpSeqCounterAndRlHdr[TCPIP_TLS_RL_SEQUENCE_NUM_LEN];
  Std_ReturnType      csmRetVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Build tmp buffer with sequence counter for Rx authentication */
  IpBase_PutUint64(seqCounterPtr, 0, TcpIp_GetRlRxSequenceCounterOfTlsConnectionDyn(TlsConIdx));

  /* #20 Create RL-header and add it to the tmp buffer */
  rlHdrPtr[TCPIP_TLS_RLCT_OFFSET] = ContentType;
  rlHdrPtr[TCPIP_TLS_RLVERSMAJOR_OFFSET] = TCPIP_TLS_RL_VERSMAJOR;
  rlHdrPtr[TCPIP_TLS_RLVERSMINOR_OFFSET] = TCPIP_TLS_RL_VERSMINOR;
  IpBase_PutUint16(&rlHdrPtr[TCPIP_TLS_RLLENHIGH_OFFSET], 0, (uint16)DataLen); /* typecast because 2^14 is max RL-size */

  /* #30 Call CSM-Verify with tmp buffer */
  csmRetVal = TCPIP_CSM_MacVerify(csmJobIdVerify, CRYPTO_OPERATIONMODE_STREAMSTART, &tmpSeqCounterAndRlHdr[0],
    (TCPIP_TLS_RL_SEQUENCE_NUM_LEN + TCPIP_TLS_RLHDRLEN), NULL_PTR, 0, NULL_PTR);

  /* csmRetVal is not directly returned since it might be BUSY. */
  return TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, csmRetVal, 0u, 0u, TCPIP_TLS_FCTID_CORE_RL_VERIFYHMACADHS);
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_AddDecryptedDataForRxAuthentication
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
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_AddDecryptedDataForRxAuthentication(
  TcpIp_TlsConnectionIterType         TlsConIdx,
  CONST(uint8, AUTOMATIC)             ContentType,
  CONST(uint32, AUTOMATIC)            PrevWriteIdx,
  TCPIP_P2C(TcpIp_ConstSegmentType)   ReceivedMacSegPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  TcpIp_TlsCipherWorkerIterType activeTlsCipherWorkerIdx
    = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_CsmJobIdType csmJobIdVerify
    = TcpIp_GetCsmJobId(TcpIp_GetCsmJobIdHmacVerifyIdxOfTlsCipherWorker(activeTlsCipherWorkerIdx));
  /* The verify job was already called with mode START in function TcpIp_TlsCoreRl_AddRlHeaderForRxAuthentication(). */
  Crypto_OperationModeType mode = CRYPTO_OPERATIONMODE_UPDATE;
  uint32 macLenInBits = ReceivedMacSegPtr->Size * TCPIP_BITS_IN_BYTE; /* The CSM requires the length of hash in bits */
  TcpIp_SizeOfTlsBufferRxType startIdx = TcpIp_TlsCoreRl_GetRxStartIdxForContentType(TlsConIdx, ContentType);
  TcpIp_SizeOfTlsBufferRxType writeIdx = TcpIp_TlsCoreRl_GetRxWriteIdxForContentType(TlsConIdx, ContentType);
  TcpIp_SizeOfTlsBufferRxType readMaxIdx = TcpIp_TlsCoreRl_GetReadMaxIdxForContentType(TlsConIdx, ContentType);
  uint32 linearDecryptedDataLen = 0u;
  uint32 endOfBufferDecryptedDataLen = 0u;

  Crypto_VerifyResultType csmResult = CSM_E_VER_NOT_OK;
  Std_ReturnType retValCsm = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Calculate the decrypted data length with and without wraparound */
  /* PrevWriteIdx and writeIdx can only be equal for 0u bytes of received data length. */
  /* The return value can be ignored here since the indices must be correct. */
  (void) TcpIp_GetSplitLengthInRingBuffer(writeIdx, PrevWriteIdx, startIdx, readMaxIdx,
    &linearDecryptedDataLen, &endOfBufferDecryptedDataLen);

  if (endOfBufferDecryptedDataLen != 0u)
  {
    if (linearDecryptedDataLen == 0u)
    {
      /* Decrypted data end aligns perfectly with buffer end (ReadMaxIdx) */
      /* #20 Set Finish flag for final CSM call. */
      TCPIP_SET_FLAG(mode, CRYPTO_OPERATIONMODE_FINISH);
    }

    /* #30 Calculate hash till wraparound if applicable */
    retValCsm = TCPIP_CSM_MacVerify(csmJobIdVerify, mode,
      TcpIp_GetAddrTlsBufferRx((TcpIp_TlsBufferRxIterType)PrevWriteIdx),
      endOfBufferDecryptedDataLen, ReceivedMacSegPtr->BasePtr, macLenInBits, &csmResult);
  }

  if (   (retValCsm == E_OK)
         /* If the decrypted data length is zero (linearDecryptedDataLen = endOfBufferDecryptedDataLen = 0u)
          * we still have to call TCPIP_CSM_MacVerify(). */
      && ((linearDecryptedDataLen != 0u) || (endOfBufferDecryptedDataLen == 0u)))
  {
    /* #40 Set Finish flag for final CSM call. */
    TCPIP_SET_FLAG(mode, CRYPTO_OPERATIONMODE_FINISH);

    /* #50 Calculate hash with linear data */
    /* This data is either at the start or in the middle of the buffer */
    /* No underflow possible since this data is linear, see TcpIp_GetSplitLengthInRingBuffer(). */
    retValCsm = TCPIP_CSM_MacVerify(csmJobIdVerify, mode,
      TcpIp_GetAddrTlsBufferRx(writeIdx - (TcpIp_TlsBufferRxIterType)linearDecryptedDataLen),
      linearDecryptedDataLen, ReceivedMacSegPtr->BasePtr, macLenInBits, &csmResult);
  }

  /* #60 Subtract the mac length from the TLS buffer, so that it is not forwarded to the UL */
  TcpIp_SubRlRxCopiedLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
    (TcpIp_RlRxCopiedLenOfTlsBufferMgmtDynType) ReceivedMacSegPtr->Size);

  /* #70 Set Alert if hash do not fit */
  if (csmResult != CSM_E_VER_OK)
  {
    TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_BAD_RECORD_MAC);
    retValCsm = E_NOT_OK;
  }
  /* csmRetVal is not directly returned since it might be BUSY. */
  return TcpIp_TlsCoreCrypto_CheckCsmResult(TlsConIdx, retValCsm, 0u, 0u, TCPIP_TLS_FCTID_CORE_RL_VERIFYHMACADHS);
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_RxAuthenticateFrame
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_RxAuthenticateFrame(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  CONST(uint8, AUTOMATIC)       ContentType,
  uint32                        PrevWriteIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* Check if Verification is required */
  if (TcpIp_TlsCoreRl_CheckIfCipherRequiresVerification(TcpIp_GetActiveCipherRxOfTlsConnectionDyn(TlsConIdx)) == TRUE)
  {
    TcpIp_SizeOfTlsBufferRxType startIdx = TcpIp_TlsCoreRl_GetRxStartIdxForContentType(TlsConIdx, ContentType);
    TcpIp_SizeOfTlsBufferRxType writeIdx = TcpIp_TlsCoreRl_GetRxWriteIdxForContentType(TlsConIdx, ContentType);
    TcpIp_SizeOfTlsBufferRxType readMaxIdx = TcpIp_TlsCoreRl_GetReadMaxIdxForContentType(TlsConIdx, ContentType);

    TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
    TcpIp_TlsCipherWorkerActiveIdxOfTlsConnectionDynType activeTlsCipherWorkerIdx
      = TcpIp_GetTlsCipherWorkerActiveIdxOfTlsConnectionDyn(TlsConIdx);
    uint8 macLen = TcpIp_GetCipherMacKeyLengthOfTlsCipherWorker(activeTlsCipherWorkerIdx);
    uint32 frameLengthWithMac = (uint32)TcpIp_GetRlRxCopiedLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

    if (frameLengthWithMac >= macLen)
    {
      uint8 receivedMacBuffer[TCPIP_TLS_MAC_LEN_MAX] = { 0 };
      TcpIp_SegmentType receivedMacBufferSeg = { 0 };
      TcpIp_SegmentInit(&receivedMacBufferSeg, &receivedMacBuffer[0u], TCPIP_TLS_MAC_LEN_MAX);
      /* #10 Read mac from TLS buffer */
      {
        uint8 macLenPart1 = (uint8)TCPIP_MIN(macLen, writeIdx - startIdx); /* Typecast is ok because macLen is uint8 */
        uint8 macLenPart2 = macLen - macLenPart1; /* Could be 0 if the mac is completely contained in part1 */
        uint32 newWriteIdx = 0u;

        TcpIp_SegmentMemCpy(&receivedMacBufferSeg, TcpIp_GetAddrTlsBufferRx(readMaxIdx - macLenPart2), macLenPart2);
        TcpIp_SegmentMemCpy(&receivedMacBufferSeg, TcpIp_GetAddrTlsBufferRx(writeIdx - macLenPart1), macLenPart1);

        VStdLib_MemClr(TcpIp_GetAddrTlsBufferRx(readMaxIdx - macLenPart2), macLenPart2);
        VStdLib_MemClr(TcpIp_GetAddrTlsBufferRx(writeIdx - macLenPart1), macLenPart1);

        /* The return value can be ignored here since the indices must be correct. */
        (void) TcpIp_GetDecrementedRingBufferIndex((uint32)writeIdx, (uint32)macLen, (uint32)startIdx, (uint32)readMaxIdx,
          &newWriteIdx);
        TcpIp_TlsCoreRl_SetRxWriteIdxForContentType(TlsConIdx, ContentType, (TcpIp_SizeOfTlsBufferRxType)newWriteIdx);
      }

      /* #20 Add RL-Header to hash calculation */
      /* For the RL length the HMAC length needs to be subtracted */
      retVal = TcpIp_TlsCoreRl_AddRlHeaderForRxAuthentication(TlsConIdx, ContentType, frameLengthWithMac - macLen);

      if (retVal == E_OK)
      {
        /* Initialize const buffer segment since from now the written data in receivedMacBufferSeg is only read. */
        TcpIp_ConstSegmentType receivedMacBufferConstSeg = { 0 };
        TcpIp_ConstSegmentInitWithUsedSegment(&receivedMacBufferConstSeg, &receivedMacBufferSeg);
        retVal = TcpIp_TlsCoreRl_AddDecryptedDataForRxAuthentication(TlsConIdx, ContentType, PrevWriteIdx,
          &receivedMacBufferConstSeg);
      }

      /* #30 Set Alert if Error occurs */
      if (retVal != E_OK)
      {
        TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_INT_ERROR);
      }
    }
    else
    {
      /* RL frame too small for HMAC, send bad_record_mac, retVal already E_NOT_OK */
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_BAD_RECORD_MAC);
    }
  }
  else
  {
    /* Valid case: Active Rx cipher does not require verification. */
    retVal = E_OK;
  }

  return retVal;
}

# if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_RxCheckAndRemovePadding
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCoreRl_RxCheckAndRemovePadding(
  TcpIp_TlsConnectionIterType   TlsConIdx,
  CONST(uint8, AUTOMATIC)       ContentType)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Verify if the algorithm require padding */
  if (TcpIp_TlsCoreRl_RxCipherDecryptHasPadding(TlsConIdx) == TRUE)
  {
    TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
    uint32 startIdx   = (uint32) TcpIp_TlsCoreRl_GetRxStartIdxForContentType(TlsConIdx, ContentType);
    uint32 writeIdx   = (uint32) TcpIp_TlsCoreRl_GetRxWriteIdxForContentType(TlsConIdx, ContentType);
    uint32 readMaxIdx = (uint32) TcpIp_TlsCoreRl_GetReadMaxIdxForContentType(TlsConIdx, ContentType);

    /* The lenPos is the last previous written byte. */
    uint32 lenPos = 0u;
    uint8 paddingLen = 0u;
    uint8 paddingVal = 0u;

    /* The return value can be ignored here since the indices must be correct. */
    (void) TcpIp_GetDecrementedRingBufferIndex(writeIdx, TCPIP_TLS_CBC_PADDING_BYTE_LEN_LEN,
      startIdx, readMaxIdx, &lenPos);

    /* The max value of the padding length is 0xFF */
    paddingLen = TcpIp_GetTlsBufferRx((TcpIp_TlsBufferRxIterType)lenPos);

    /* The padding ends with the paddingLen-byte and contains previously as many bytes as the value of paddingLen.
     * Each of these bytes has also the value of paddingLen.
     * Both length and padding combine to (paddingLen + 1) bytes with paddingLen as value. */
    /* See: RFC5246 section-6.2.3.2 */
    paddingVal = paddingLen; /* The max value of the padding is 0xFF */

    /* #20 Verify that the length of the decrypted data is large enough for the whole padding (+ length) */
    if (   TcpIp_GetRlRxCopiedLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)
        >= ((TcpIp_RlRxCopiedLenOfTlsBufferMgmtDynType)paddingLen + TCPIP_TLS_CBC_PADDING_BYTE_LEN_LEN))
    {
      uint16 i; /* uint16 because paddingVal could be 0xFF,  */
      /* #30 Verify padding and set padding to 0x00 */
      for (i = 0; i <= paddingLen; i++)
      {
        /* The return value can be ignored here since the indices must be correct. */
        (void) TcpIp_GetDecrementedRingBufferIndex(writeIdx, 1u, startIdx, readMaxIdx, &writeIdx);
        if (TcpIp_GetTlsBufferRx((TcpIp_TlsBufferRxIterType)writeIdx) != paddingVal)
        {
          retVal = E_NOT_OK;
          break;
        }
        TcpIp_SetTlsBufferRx((TcpIp_TlsBufferRxIterType)writeIdx, 0u);
      }

      if (retVal == E_OK)
      {
        /* Remove the padding length from Rx copiedLen so that Rx copiedLen equals the total plaintext length
         * (after the hash length is removed as well). */
        TcpIp_SubRlRxCopiedLenOfTlsBufferMgmtDyn(tlsBufferMgmtIdx,
            /* Cast before +1 because paddingLen + 1 could be 0x100 for paddingLen == 0xFF. */
            (TcpIp_RlRxCopiedLenOfTlsBufferMgmtDynType)(paddingLen) + TCPIP_TLS_CBC_PADDING_BYTE_LEN_LEN);

        /* Set write index to allow overwriting of padding bytes. */
        TcpIp_TlsCoreRl_SetRxWriteIdxForContentType(TlsConIdx, ContentType, (TcpIp_SizeOfTlsBufferRxType) writeIdx);
      }
    }
    else
    {
      retVal = E_NOT_OK;
    }

    /* According to RFC 5246, 7.2.2., the alert 'bad_record_mac' must be sent for invalid padding */
    if (retVal != E_OK)
    {
      TcpIp_TlsCoreAlert_Set(TlsConIdx, TCPIP_TLS_ALERT_LEVEL_FATAL, TCPIP_TLS_ALERT_DESC_BAD_RECORD_MAC);
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_RxCipherDecryptHasPadding
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(boolean, TCPIP_CODE)  TcpIp_TlsCoreRl_RxCipherDecryptHasPadding(
  TcpIp_TlsConnectionIterType   TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Only CBC of our supported algorithms contains a padding */
  if (   TcpIp_TlsCoreUtil_ReturnCipherSpecificStreamingMode(TcpIp_GetActiveCipherRxOfTlsConnectionDyn(TlsConIdx))
      == TCPIP_TLS_STREAMING_MODE_AES_128_CBC)
  {
    retVal = TRUE;
  }

  return retVal;
}
# endif

# if ( TCPIP_DEV_ERROR_DETECT == STD_ON )
/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_RxBufferIdxValidityCheck
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreRl_RxBufferIdxValidityCheck(
  TcpIp_TlsConnectionIterType TlsConIdx,
  CONST(uint8, AUTOMATIC)     CallPos,
  CONST(uint8, AUTOMATIC)     ContentType)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);
  uint32 startIdx = (uint32)TcpIp_TlsCoreRl_GetRxStartIdxForContentType(TlsConIdx, ContentType);
  uint32 readMaxIdx = (uint32)TcpIp_TlsCoreRl_GetReadMaxIdxForContentType(TlsConIdx, ContentType);
  uint32 writeIdx = TcpIp_TlsCoreRl_GetRxWriteIdxForContentType(TlsConIdx, ContentType);
  uint32 readIdx = TcpIp_TlsCoreRl_GetRxReadIdxForContentType(TlsConIdx, ContentType);
  /* The UlRxIndIdx is only for HS or AD contents available. For other the value in the log shall be 0u */
  uint32 ulIndIdx = 0u;

  TCPIP_P2V(uint32) logPositionPtr = &(TcpIp_TlsRxBufferIdxLog[TcpIp_TlsRxBufferIdxLogPos][0u]);
  TCPIP_P2V(uint8) firstItemOfLogPtr = (TCPIP_P2V(uint8))logPositionPtr;

  /* ----- Implementation ----------------------------------------------- */
  TCPIP_DUMMY_STATEMENT_CONST((TcpIp_TlsRxBufferIdxLog[0][0])); /* required to prevent unreaded variables */

  /* #10 Check WriteIdx */
  if (!TCPIP_IN_RANGE(writeIdx, startIdx, readMaxIdx))
  {
    TcpIp_CallDetReportError(TCPIP_API_ID_CBK_RX_INDICATION, TCPIP_E_INV_RUNTIME_CHECK);
  }

  /* #20 Check ReadIdx */
  if (!TCPIP_IN_RANGE(readIdx, startIdx, readMaxIdx))
  {
    TcpIp_CallDetReportError(TCPIP_API_ID_CBK_RX_INDICATION, TCPIP_E_INV_RUNTIME_CHECK);
  }

  /* #30 Check UpperLayerIndicationIdx */
  if ((ContentType == TCPIP_TLS_CT_HS) || (ContentType == TCPIP_TLS_CT_AD))
  {
    ulIndIdx = TcpIp_GetTlsBufferRxUlRxIndIdxOfTlsBufferMgmtDyn(tlsBufferMgmtIdx);

    if (!TCPIP_IN_RANGE(ulIndIdx, startIdx, readMaxIdx))
    {
      TcpIp_CallDetReportError(TCPIP_API_ID_CBK_RX_INDICATION, TCPIP_E_INV_RUNTIME_CHECK);
    }
  }

  /* #40 Store current Idx */
  /* The stored indices can be used to indicate issues */
  {/* Write logPositionPtr[0u] */
    IpBase_PutUint16(&firstItemOfLogPtr[0u], 0u, (uint16)TlsConIdx);
    firstItemOfLogPtr[2u] = CallPos;
    firstItemOfLogPtr[3u] = ContentType;
  }
  logPositionPtr[1u] = writeIdx;
  logPositionPtr[2u] = readIdx;
  logPositionPtr[3u] = ulIndIdx;

  /* Set Idx to next position, also handle wraparound */
  TcpIp_TlsRxBufferIdxLogPos++;
  if (TcpIp_TlsRxBufferIdxLogPos >= TCPIP_TLS_RX_BUFFER_IDX_LOG_SIZE)
  {
    TcpIp_TlsRxBufferIdxLogPos = 0u;
  }
  logPositionPtr = &(TcpIp_TlsRxBufferIdxLog[TcpIp_TlsRxBufferIdxLogPos][0u]);

  /* Write 0xFFFFFFFF to the new position to make it easier to find the current position */
  logPositionPtr[0u] = 0xFFFFFFFFu;
  logPositionPtr[1u] = 0xFFFFFFFFu;
  logPositionPtr[2u] = 0xFFFFFFFFu;
  logPositionPtr[3u] = 0xFFFFFFFFu;
}
# endif

/**********************************************************************************************************************
 *  TcpIp_TlsCoreRl_ResetRxDataSplit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE)  TcpIp_TlsCoreRl_ResetRxDataSplit(
  TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfTlsBufferMgmtType tlsBufferMgmtIdx = TcpIp_GetTlsBufferMgmtIdxOfTlsConnection(TlsConIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if any data is stored. If so, reset it. */
  if (TcpIp_GetAddrRxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataLen != 0u)
  {
    TcpIp_GetAddrRxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataPtr = NULL_PTR;
    TcpIp_GetAddrRxDataSplitOfTlsBufferMgmtDyn(tlsBufferMgmtIdx)->DataLen = 0u;
  }
}

/**********************************************************************************************************************
 *  TCPIP TLS CORE SECRET ACCESS
 *********************************************************************************************************************/


# if (TCPIP_SUPPORT_ASRTLS_SECRET_ACCESS == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCore_ReadTlsSecrets
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCore_ReadTlsSecrets(
  TcpIp_SocketDynIterType SocketIdx,
  TCPIP_P2C(TcpIp_Tls12_Secret_Type) Tls12_SecretPtr,
  TCPIP_P2C(TcpIp_Tls13_Secret_Type) Tls13_SecretPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  TcpIp_TlsConnectionDynIterType tlsConIdx = TcpIp_GetSizeOfTlsConnection();

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Forward to version specific handler */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  if (TcpIp_SocketIdxToTlsConIdx(SocketIdx, &tlsConIdx) == E_OK)
  {
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
    /* #20 Check if there is a valid TLS connection for this socket. */
    if (TcpIp_GetActiveVersionOfTlsConnectionDyn(tlsConIdx) == TCPIP_TLSVERSION_13)
    {
#   endif
#  endif
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
      if (Tls13_SecretPtr != NULL_PTR)
      {
        retVal = TcpIp_Tls13Core_ReadHandshakeAndApplicationTrafficSecrets(
          tlsConIdx,
          Tls13_SecretPtr);
      }
#  endif
#  if ((TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) && (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON))
    }
    else
    {
#  endif
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
      if (Tls12_SecretPtr != NULL_PTR)
      {
        retVal = TcpIp_Tls12Core_ReadHandshakeParameter(
          SocketIdx,
          Tls12_SecretPtr->MasterSecretPtr,
          Tls12_SecretPtr->ClientRandomPtr,
          Tls12_SecretPtr->SessionIdPtr,
          Tls12_SecretPtr->SessionIdLenPtr);
      }
#  endif
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
    }
#   endif
  }
#  endif
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_OFF)
  TCPIP_DUMMY_STATEMENT_CONST(Tls12_SecretPtr);                                                                         /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
#  endif
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_OFF)
  TCPIP_DUMMY_STATEMENT_CONST(Tls13_SecretPtr);                                                                         /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
  TCPIP_DUMMY_STATEMENT_CONST(tlsConIdx);                                                                               /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */
#  endif
  return retVal;
}


/**********************************************************************************************************************
 *  TcpIp_TlsCore_IssueKeyUpdateCallout
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCore_IssueKeyUpdateCallout(
  TcpIp_TlsConnectionIterType TlsConIdx,
  TcpIp_TlsKeyUpdateType KeyUpdateType)
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_SizeOfSocketOwnerConfigType socketOwnerConfigIdx = TcpIp_GetSocketOwnerConfigIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_SizeOfSocketDynType socketIdx = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);

  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Issue the key update callout if applicable. */
  if ((socketIdx < TcpIp_GetSizeOfSocketDyn()) && (socketOwnerConfigIdx < TcpIp_GetSizeOfSocketOwnerConfig()))
  {
    if (TcpIp_GetTlsKeyUpdateCalloutFuncPtrOfSocketOwnerConfig(socketOwnerConfigIdx) != NULL_PTR)
    {
      /* #20 Issue the callout. */
      TcpIp_GetTlsKeyUpdateCalloutFuncPtrOfSocketOwnerConfig(socketOwnerConfigIdx)(
        TCPIP_SOCKET_IDX_TO_ID(socketIdx),
        KeyUpdateType);

      retVal = E_OK;
    }
  }
  return retVal;
} /* TcpIp_TlsCore_IssueKeyUpdateCallout() */
# endif

# if (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON)
/**********************************************************************************************************************
 *  TcpIp_TlsCore_ReturnIpBufferForNssFrame
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCore_ReturnIpBufferForNssFrame(
  TcpIp_TlsConnectionIterType                TlsConIdx,
  TCPIP_P2V(TcpIp_Uint8P2V)                  IpBufferPtrPtr,
  uint16                                     RequestedIpBufferLen,
  TCPIP_P2V(TcpIp_IpTxRequestDescriptorType) IpTxReqestDescrPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  BufReq_ReturnType bufRetValue = BUFREQ_E_NOT_OK;
  Std_ReturnType retVal = E_NOT_OK;

  uint16 ipBufferLen = RequestedIpBufferLen;

  TcpIp_SocketDynIterType socketIdx = TcpIp_GetSocketDynComIdxOfTlsConnectionDyn(TlsConIdx);
  TcpIp_SizeOfLocalAddrType localAddrIdx = TcpIp_GetLocalAddrBindIdxOfSocketDyn(socketIdx);
  TcpIp_SockAddrBaseType destSockAddr;                                                                                  /* PRQA S 0759 */ /* MD_MSR_Union */

  /* ----- Implementation ----------------------------------------------- */
  /* Store the transport protocol information in the tx descriptor */
  IpTxReqestDescrPtr->XptProtocol = TCPIP_PROTOCOL_UDP;

  /* #10 Get IpvX Buffer */
#  if (TCPIP_SUPPORT_IPV4 == STD_ON)
  if (TCPIP_LOCAL_ADDR_IDX_IS_IPV4(localAddrIdx))
  {
    TcpIp_LocalAddrV4IterType ipV4AddrIdx = TcpIp_GetTxIpAddrIdxOfSocketDyn(socketIdx);
    destSockAddr.SockAddrIn.sin_addr = TCPIP_INADDR_BROADCAST;

    bufRetValue = IpV4_Ip_ProvideTxBuffer(
      &ipV4AddrIdx,
      socketIdx,
      &destSockAddr.SockAddrIn,
      IpBufferPtrPtr,
      &ipBufferLen,
      IpTxReqestDescrPtr,
      FALSE);
  }
#  endif
#  if (TCPIP_SUPPORT_IPV6 == STD_ON)
  if (TCPIP_LOCAL_ADDR_IDX_IS_IPV6(localAddrIdx))
  {
    TcpIp_LocalAddrV6IterType ipV6AddrIdx = TcpIp_GetTxIpAddrIdxOfSocketDyn(socketIdx);
    destSockAddr.SockAddrIn6.sin6_addr = IpV6_AddrAllNodesLL;

    /* Initialize EthBufferCnt to 1.
     * This variable is not used in Ipv6 and therefore not initialized in IpV6_ProvideTxBuffer().*/
    IpTxReqestDescrPtr->EthBufferCnt = 1u;

    bufRetValue = IpV6_ProvideTxBuffer(
      &ipV6AddrIdx,
      socketIdx,
      &destSockAddr.SockAddrIn6.sin6_addr,
      IpBufferPtrPtr,
      &ipBufferLen,
      IpTxReqestDescrPtr,
      TCPIP_PROTOCOL_UDP,
      FALSE);
  }
#  endif

  if (bufRetValue == BUFREQ_OK)
  {
    /* #20 Check if no fragmentation occurs and buffer is big enough - else report DET error */
    if (   (IpTxReqestDescrPtr->EthBufferCnt > 1u)
        || (ipBufferLen < RequestedIpBufferLen))
    {
      retVal = E_NOT_OK;
    }
    else
    {
      /* No error - return E_OK */
      retVal = E_OK;
    }
  }
  return retVal;
}
/**********************************************************************************************************************
 *  TcpIp_TlsCore_SendSecretViaNssFrame
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TlsCore_SendSecretViaNssFrame(
  TcpIp_TlsConnectionIterType                   TlsConIdx,
  TcpIp_CsmKeyIdType                            CsmKeyId,
  TcpIp_HsCommonKeyElementIdOfTlsHandshakeType  CsmKeyElementId,
  TCPIP_P2C(uint8)                              LabelPtr,
  uint8                                         LabelLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  TCPIP_P2V(uint8) ipBufferPtr = NULL_PTR;
  uint16 ipBufferLen = 0u;

  /* Port can be configured in TcpIpTlsConfig (using the same port as source port has no impact) */
  uint16 srcPort = (uint16)TcpIp_GetNssKeyLogPortOfTlsConfig(TCPIP_TLSCONFIG_IDX);
  uint16 dstPort = (uint16)TcpIp_GetNssKeyLogPortOfTlsConfig(TCPIP_TLSCONFIG_IDX);

  uint8 key[TCPIP_TLS_MAX_SIZE_OF_TLS_SECRET] = { 0u };
  uint32 keyLen = TCPIP_TLS_MAX_SIZE_OF_TLS_SECRET;
  /* Set default length to TLS 1.2 master secret */
  uint8 secretLen = TCPIP_TLS_MASTER_SECRET_LEN;

  TcpIp_IpTxRequestDescriptorType ipTxReqestDescr;

  /* ----- Implementation ----------------------------------------------- */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
  if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_13)
  {
    retVal = TcpIp_Tls13Core_GetHashLengthOfActiveCipherSuite(TlsConIdx, &secretLen);
  }
  if (retVal == E_OK)
#  endif
  {
    /* Set retVal to E_NOT_OK by default */
    retVal = E_NOT_OK;

    /* <UDP-HDR><Label><space><ClientRandom><space><Secret>
     * Because <ClientRandom> and <Secret> are HEX encoded (therefore, byte-length is doubled the size of original
     * length) and IpBase_ConvArray2HexStringBase() terminates the string with 0x00, we need the total length + 1 Byte.
     * Nonetheless, this last byte will not be sent. */
    ipBufferLen
      =   TCPIP_UDP_HDR_LEN_BYTE
        + TCPIP_TLS_NSS_FRAME_STATIC_LEN
        + (uint16)LabelLen
        + (secretLen * (uint16)2u)
        + (uint16)1u;

    if (TcpIp_TlsCore_ReturnIpBufferForNssFrame(TlsConIdx, &ipBufferPtr, ipBufferLen, &ipTxReqestDescr) == E_OK)
    {
      /* Temporary writeOffset */
      uint8 writeOffset = 0u;

      /* #10 Add UDP Header */
      /* Source port */
      TCPIP_PUT_UINT16(ipBufferPtr, writeOffset, srcPort);
      writeOffset += 2u;
      /* Destination port */
      TCPIP_PUT_UINT16(ipBufferPtr, writeOffset, dstPort);
      writeOffset += 2u;
      /* Length of UDP package (see comment on ipBufferLen initialization)  */
      TCPIP_PUT_UINT16(ipBufferPtr, writeOffset, ipBufferLen - 1u);
      writeOffset += 2u;
      /* Checksum is calculated later - see below */
      TCPIP_PUT_UINT16(ipBufferPtr, writeOffset, 0u);
      writeOffset += 2u;

      /* Set point of time for checksum calculation to completion */
      if (ipTxReqestDescr.ChecksumHwCalced == TCPIP_IP_PROTOCOL_CHECKSUM_CHECK_COPY)
      {
        ipTxReqestDescr.ChecksumHwCalced = TCPIP_IP_PROTOCOL_CHECKSUM_CHECK_COMPLETE;
      }

      /* NSS Key Frame Layout:
       * <Label><space><ClientRandom><space><Secret>
       */

      /* #20 Copy Label to buffer */
      VStdLib_MemCpy(&ipBufferPtr[writeOffset], LabelPtr, LabelLen);
      writeOffset += LabelLen;

      /* Add space (0x20) after label */
      TCPIP_PUT_UINT8(ipBufferPtr, writeOffset, TCPIP_HEX_SPACE);
      writeOffset += TCPIP_HEX_SPACE_LEN;

      /* #30 Copy ClientRandom to buffer */
      if (IpBase_ConvArray2HexStringBase(
            TcpIp_GetAddrTlsClientRandomAccessBuffer(
              TcpIp_GetTlsClientRandomAccessBufferStartIdxOfTlsConnection(TlsConIdx)),
            TCPIP_TLS_RANDOM_LEN,
            &ipBufferPtr[writeOffset]) == E_OK)
      {
        writeOffset += (TCPIP_TLS_RANDOM_LEN * 2u);

        /* Add space (0x20) after ClientRandom */
        TCPIP_PUT_UINT8(ipBufferPtr, writeOffset, TCPIP_HEX_SPACE);
        writeOffset += TCPIP_HEX_SPACE_LEN;

        /* #40 Read key from CSM and copy to buffer */
        if (   (TCPIP_CSM_KeyElementGet(CsmKeyId, (uint32)CsmKeyElementId, &key[0], &keyLen) == E_OK)
            && (keyLen == secretLen))
        {
          if (IpBase_ConvArray2HexStringBase(&key[0], (uint16)keyLen, &ipBufferPtr[writeOffset]) == E_OK)
          {
            /* #50 Send UDP Frame (see comment on ipBufferLen initialization) */
            /* No flags are set on transmission. We do not want TX confirmation/retry. */
            if (TcpIp_VIpTransmit(&ipTxReqestDescr, ipBufferLen - 1u, TCPIP_PROTOCOL_UDP, 0u, 0u) == TCPIP_OK)
            {
              retVal = E_OK;
            }
          }
        }
      }
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  TcpIp_TlsCoreMainFunction_TxNss
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_TlsCoreMainFunction_TxNss(TcpIp_TlsConnectionIterType TlsConIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  if (TcpIp_TlsCoreUtil_IsActiveHandshakeSet(TlsConIdx) == TRUE)
  {
    /* #10 Depending on the version of TLS connection, trigger different main function */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON)
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    if (TcpIp_GetActiveVersionOfTlsConnectionDyn(TlsConIdx) == TCPIP_TLSVERSION_12)
#   endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
    {
      /* TLS Version 1.2 */
      TcpIp_Tls12CoreMainFunction_TxNss(TlsConIdx);
    }
#   if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    else
#   endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_2 == STD_ON) */
#  if (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON)
    {
      /* TLS Version 1.3 */
      TcpIp_Tls13CoreMainFunction_TxNss(TlsConIdx);
    }
#  endif /* (TCPIP_SUPPORT_ASRTLS_VERSION_1_3 == STD_ON) */
  } /* else - otherwise no handshake is active, nothing to do */
} /* TcpIp_TlsCoreMainFunction_TxNss() */
# endif /* (TCPIP_SUPPORT_ASRTLS_SECRETS_NSS_FRAME == STD_ON) */

# define TCPIP_STOP_SEC_CODE
# include "TcpIp_MemMap.h"                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SILENTBSW JUSTIFICATIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  COVERAGE JUSTIFICATIONS
 *********************************************************************************************************************/

#endif /* (TCPIP_SUPPORT_ASRTLS == STD_ON) */
/**********************************************************************************************************************
 *  END OF FILE: TcpIp_TlsCoreCommon.c
 *********************************************************************************************************************/
