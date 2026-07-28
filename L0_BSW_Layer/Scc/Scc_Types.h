/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Scc_Types.h
 *        \brief  Smart Charging Communication Header File
 *
 *      \details  Implements Vehicle 2 Grid communication according to the specifications ISO/IEC 15118-2,
 *                DIN SPEC 70121 and customer specific schemas.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/
#if !defined (SCC_TYPES_H)
# define SCC_TYPES_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
/* PRQA S 0777 EXT_IDENTIFIER_LENGTH */ /* MD_MSR_Rule5.1 */
/* PRQA S 0779 IDENTIFIER_LENGTH */ /* MD_MSR_Rule5.2 */
/* PRQA S 0789 EOF */ /* MD_MSR_IdentifierLength */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Scc_Cfg.h"

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )                                                                              /* PRQA S 3332 */ /* MD_Scc_3332 */
#include "Slac.h"
#endif /* SCC_ENABLE_SLAC_HANDLING */
#include "Exi_SchemaTypes.h"
#include "IpBase_Types.h"
#include "TcpIp.h"
#if ( (defined(SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
  ||  (defined(SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON)) )
# include "XmlSecurity_Types.h"
#endif
#if ( (defined(SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON) ) \
  ||  (defined(SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON)) )
# include "KeyM_Types.h"
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_TLS */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define Scc_V2GTPOffsets_Version                     0u
#define Scc_V2GTPOffsets_InverseVersion              1u
#define Scc_V2GTPOffsets_PayloadType                 2u
#define Scc_V2GTPOffsets_PayloadLength               4u

#if ( ( (defined SCC_SCHEMA_ISO_20WPT) && (SCC_SCHEMA_ISO_20WPT != 0u) ) \
   || ( (defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u) ) )
#define SCC_WIRELESS_SDP                            STD_ON
#else
#define SCC_WIRELESS_SDP                            STD_OFF
#endif /* SCC_SCHEMA_ISO_20ACDP || SCC_SCHEMA_ISO_20WPT */

#define Scc_SDPReqOffsets_Security                   0u
#define Scc_SDPReqOffsets_Protocol                   1u
#if ( (defined SCC_WIRELESS_SDP) && (SCC_WIRELESS_SDP == STD_ON) )
#define SCC_SDPREQOFFSETS_P2PPPD                     2u
#define SCC_SDPREQOFFSETS_COUPLINGTYPE               4u
#define SCC_SDPREQOFFSETS_EVID                       5u
#define SCC_SDPREQOFFSETS_EVSEID                    25u
#define SCC_SDPTYPES_EVSEID_MAX_SIZE                36u
#define SCC_SDPTYPES_EVID_MAX_SIZE                  20u
#endif /* SCC_WIRELESS_SDP */
#define Scc_SDPResOffsets_IPAddress                  0u
#define Scc_SDPResOffsets_Port                      16u
#define Scc_SDPResOffsets_Security                  18u
#define Scc_SDPResOffsets_Protocol                  19u
#if ( (defined SCC_WIRELESS_SDP) && (SCC_WIRELESS_SDP == STD_ON) )
#define SCC_SDPRESOFFSETS_DIAGSTATUS                20u
#define SCC_SDPRESOFFSETS_COUPLINGTYPE              21u
#define SCC_SDPRESOFFSETS_EVSEID                    22u
#endif /* SCC_WIRELESS_SDP */

#define SCC_IPvX_IPV6                    TCPIP_AF_INET6

#define SCC_SIZE_OF_SERVICE_ID                       2u
#define SCC_SIZE_OF_TIMESTAMP                        4u
#define SCC_MAX_SIZE_OF_EMAID                       15u
#define SCC_MAX_SIZE_OF_SERVICE_NAME_PREFIX         32u
#define SCC_MAX_SIZE_CERTIFICATE                   800u

# define SCC_EVENT_STATUS_PASSED                     0u
# define SCC_EVENT_STATUS_FAILED                     1u

/* Crypto constants */
#define SCC_CRYPTO_BUF_LEN                  132u
#define SCC_BER_STACK_DEPTH                   6u
#define SCC_DOM_COM_TAG_LEN                   3u
#define SCC_SHA256_DIGEST                    32u
#define SCC_AES128_KEY_LEN                   16u
#define SCC_KDF_OTHER_INFO_LEN                3u
#define SCC_KDF_SHARED_SECRET_LEN            32u
#define SCC_KDF_ITERATION_INFO_LEN            4u
#define SCC_MASTER_SECRET_LEN                48u
#define SCC_CLIENT_RANDOM_LEN                32u
#define SCC_PUBLICKEY_UNUSEDBITS_LEN          1u
#define SCC_PUBLICKEY_UNUSEDBITS_OFFSET       0u
#define SCC_PUBLICKEY_COMPRESSEDINFO_LEN      1u
#define SCC_PUBLICKEY_COMPRESSEDINFO_OFFSET   1u
#define SCC_PUBLICKEY_OCTETSTRING_OFFSET      2u

#define SCC_P256R1_PUBLIC_KEY_LEN             64u
#define SCC_P256R1_PRIVATE_KEY_LEN            32u
#define SCC_P256R1_SIGNATURE_LEN              64u

#define SCC_P521R1_PUBLIC_KEY_LEN             132u
#define SCC_P521R1_PRIV_KEY_LEN               66u /* [V2G20-2499] */
#define SCC_P521R1_IV_LEN                     12u /* [V2G20-2499] */
#define SCC_P521R1_TAG_LEN                    16u /* [V2G20-2499] */

#define SCC_X448_PUBLIC_KEY_LEN               57u /* RFC 8032. 5.2.5 */
#define SCC_X448_DH_KEY_LEN                   56u
#define SCC_X448_DH_KEY_OFFSET                77u /* 77 bytes of padded bytes and 56 bytes DHPublicKey = 133 bytes */
#define SCC_ED448_PRIV_KEY_LEN                57u /* RFC 8032. 5.2.5 */
#define SCC_ED448_IV_LEN                      11u /* [V2G20-2502] */
#define SCC_ED448_TAG_LEN                     16u /* [V2G20-2502] */

#define SCC_PUBLICKEY_TMP_LEN_SECP256         (SCC_P256R1_PUBLIC_KEY_LEN + SCC_PUBLICKEY_UNUSEDBITS_LEN + SCC_PUBLICKEY_COMPRESSEDINFO_LEN)
#define SCC_PUBLICKEY_TMP_LEN_SECP521         (SCC_P521R1_PUBLIC_KEY_LEN + SCC_PUBLICKEY_UNUSEDBITS_LEN + SCC_PUBLICKEY_COMPRESSEDINFO_LEN)
#define SCC_PUBLICKEY_TMP_LEN_448             (SCC_X448_PUBLIC_KEY_LEN + SCC_PUBLICKEY_UNUSEDBITS_LEN)

#define SCC_DH_PUBLIC_KEY_SCHEMA_LEN         133u
#define SCC_CERT_VALIDITY_NOTAFTER_MAXLEN    15u
#define SCC_PROVIDER_ID_BUFF_LEN             80u

#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

#if !defined (SCC_LOCAL_INLINE)
# define SCC_LOCAL_INLINE LOCAL_INLINE
#endif

#if !defined (SCC_INLINE)
# define SCC_INLINE INLINE
#endif

#define SCC_CFG_TYPE_STATIC  1u
#define SCC_CFG_TYPE_DYNAMIC 2u
#define SCC_CFG_TYPE_EXTERN  3u

#define SCC_SCHEMALIST_SIZE (SCC_ACTIVE_SCHEMA_CNT + 1u)  /* +1 Due to None termination */

#define SCC_LEN_HASH_512                           64u
#define SCC_MAX_NUM_PRIO_EMAID                     8u

#define SCC_INVALID_BUFFER_POOL_ID                 0xFFu

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#define Scc_SockAddrType    TcpIp_SockAddrType
#define Scc_SockAddrIn6Type TcpIp_SockAddrInet6Type
#define Scc_PbufType        TcpIp_PbufType
#define Scc_SocketType      TcpIp_SocketIdType

typedef unsigned int Scc_BitType;

#define SCC_BITTYPE_TRUE  (1u)
#define SCC_BITTYPE_FALSE (0u)

#define SCC_BOOLEAN_TO_BITTYPE(BoolVal)     (((BoolVal) == TRUE) ? 1u : 0u)
#define SCC_EXIBOOLEAN_TO_BOOLEAN(BoolVal)  (((BoolVal) == Exi_BT_True) ? TRUE : FALSE)
#define SCC_EXIBITTYPE_TO_BOOLEAN(BitVal)   (((BitVal) == 1u) ? TRUE : FALSE)

typedef enum Scc_returnType
{
  Scc_ReturnType_OK      = E_OK,
  Scc_ReturnType_NotOK   = E_NOT_OK,
  Scc_ReturnType_Pending = 2u,
  Scc_ReturnType_Busy    = 3u,
  Scc_ReturnType_InvalidPayloadLen = 4u,
  Scc_ReturnType_InvalidSessionId = 5u
} Scc_ReturnType;

typedef enum Scc_certInGroupReturnType
{
  Scc_CertInGroup_Found = 0u,
  Scc_CertInGroup_GroupEmpty,
  Scc_CertInGroup_NotAvailable,
  Scc_CertInGroup_InvalidCert,
  Scc_CertInGroup_ExpiredCert,
  Scc_CertInGroup_Error
} Scc_CertInGroupReturnType;

typedef enum Scc_sendDataStateType
{
  Scc_SendDataState_Init,           /* Data not yet sent. Initialize and do the first round of encoding. In case buffer is avaialble then write the payload too */
  Scc_SendDataState_WriteV2GHeader, /* Write header. Stay in this state till header is completely copied */
  Scc_SendDataState_WritePayload,   /* This state is not the first round of encoding. Payload could not be written completely or partially earlier. Write payload */
  Scc_SendDataState_Done            /* Scc has finished data transmission and nothing needs to be done anymore */
} Scc_SendDataStateType;

typedef enum Scc_sdpSecurityType
{
  Scc_SDPSecurity_Tls  = 0x00u,
  Scc_SDPSecurity_None = 0x10u
} Scc_SDPSecurityType;

typedef enum Scc_sdpTransportProtocolType
{
  Scc_SDPTransportProtocol_TCP = 0x00,
  Scc_SDPTransportProtocol_UDP = 0x10
} Scc_SDPTransportProtocolType;

typedef enum Scc_sdpPhysComLayerType
{
  Scc_SDPPhysComLayer_PLC       = 0x00u,
#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
  Scc_SDPPhysComLayer_Wireless  = 0x10u,
#endif /* SCC_WIRELESS_SDP */
  Scc_SDPPhysComLayer_Undefined = 0xFFu
} Scc_SDPPhysComLayerType;

#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
typedef enum Scc_sdpP2pPpdType
{
  Scc_SDPP2pPpdT_NoP2PSMeans              = 0x00, /**< According to ISO 15118-20 chapter 7.10.1.11 */
  Scc_SDPP2pPpdT_Ppd_On_Infrastructure    = 0x01, /**< According to ISO 15118-20 Table 24 */
  Scc_SDPP2pPpdT_Ppd_On_Ev                = 0x02, /**< According to ISO 15118-20 Table 24 */
  Scc_SDPP2pPpdT_Wpt_Lf_On_Infrastructure = 0x04, /**< According to ISO 15118-20 Table 24 */
  Scc_SDPP2pPpdT_Wpt_Lf_On_Ev             = 0x08, /**< According to ISO 15118-20 Table 24 */
  Scc_SDPP2pPpdT_Wpt_Cam_On_Ev            = 0x10, /**< According to ISO 15118-20 Table 24 */
  Scc_SDPP2pPpdT_Acd_U_Infrared           = 0x20, /**< According to ISO 15118-20 Table 24 */
  Scc_SDPP2pPpdT_Acd_directed_Wlan        = 0x40, /**< According to ISO 15118-20 Table 24 */
  Scc_SDPP2pPpdT_Undefined                = 0xFF
} Scc_SDPP2pPpdType;

typedef enum Scc_sdpCouplingType
{
  Scc_SDPCouplingType_Infrstr_Mntd_Inv_Panthograph_X          = 0x00,
  Scc_SDPCouplingType_Infrstr_Mntd_Inv_Panthograph_Inln       = 0x01,
  Scc_SDPCouplingType_Infrstr_Mntd_Panthograph_Cntct_Dme      = 0x02,
  Scc_SDPCouplingType_Ev_Mntd_Panthograph                     = 0x03,
  Scc_SDPCouplingType_Acd_Undrnth_EV                          = 0x04,
  Scc_SDPCouplingType_Acd_Sd_Rf_EV                            = 0x05,
  Scc_SDPCouplingType_WPT                                     = 0x10,
  Scc_SDPCouplingType_Acd_U_Mnpltr_On_Infrstr                 = 0x20,
  Scc_SDPCouplingType_Acd_U_Mnpltr_On_EV                      = 0x21,
  Scc_SDPCouplingType_Acd_S                                   = 0x30,
  Scc_SDPCouplingType_Cndctv_Man                              = 0x40,
  Scc_SDPCouplingType_Na                                      = 0xFF
} Scc_SDPCouplingType;

/* ISO 15118-20:2022(E), Table 25 */

typedef struct Scc_SDPEvIdType Scc_SDPEvIdType;
struct Scc_SDPEvIdType
{
  uint16 Length;
  uint8 Buffer[SCC_SDPTYPES_EVID_MAX_SIZE];
};

typedef struct Scc_SDPEvseIdType Scc_SDPEvseIdType;
struct Scc_SDPEvseIdType
{
  uint16 Length;
  uint8 Buffer[SCC_SDPTYPES_EVSEID_MAX_SIZE];
};

typedef enum Scc_sdpDiagDataType
{
  Scc_SDPDiagDataType_Ongoing                 = 0x00u,
  Scc_SDPDiagDataType_Finished_With_EvseId    = 0x01u,
  Scc_SDPDiagDataType_Finished_Without_EvseId = 0x02u,
  Scc_SDPDiagDataType_Error_No_Secc           = 0x10u
} Scc_SDPDiagDataType;
#endif /* SCC_WIRELESS_SDP */

typedef enum Scc_sapSchemaIDType
{
#if ( defined SCC_SCHEMA_OPP_CHARGE ) && ( SCC_SCHEMA_OPP_CHARGE != 0 )
  Scc_SAPSchemaIDs_OppCharge = 0u, /* [V2G2-OC-167_1] */
#endif /* SCC_SCHEMA_OPP_CHARGE */
#if ( defined SCC_SCHEMA_DIN ) && ( SCC_SCHEMA_DIN != 0 )
  Scc_SAPSchemaIDs_DIN = 1u, /* some EVSEs need DIN with SchemaId = 1 */
#endif /* SCC_SCHEMA_DIN */
#if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )
  Scc_SAPSchemaIDs_ISO15118_2 = 2u,
#endif /* SCC_SCHEMA_ISO */
#if ( defined SCC_SCHEMA_ISO_20AC ) && ( SCC_SCHEMA_ISO_20AC != 0 )
  Scc_SAPSchemaIDs_ISO15118_20AC = 3u,
#endif /* SCC_SCHEMA_ISO_20AC */
#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
  Scc_SAPSchemaIDs_ISO15118_20DC = 4u,
#endif /* SCC_SCHEMA_ISO_20DC */
#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
  Scc_SAPSchemaIDs_ISO15118_20WPT = 5u,
#endif /* SCC_SCHEMA_ISO_20WPT */
#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
  Scc_SAPSchemaIDs_ISO15118_20ACDP = 6u,
#endif /* SCC_SCHEMA_ISO_20ACDP */
  Scc_SAPSchemaIDs_TerminationEntry,      /* Always keep one additional entry to terminate the list by using None */
  Scc_SAPSchemaIDs_None = 0xFF
} Scc_SAPSchemaIDType;

typedef struct
{
  Scc_SAPSchemaIDType Schema;   /**< Contains the schema ID of the related schema */
  uint8               Priority; /**< Contains the priority of the related schema */
} Scc_SAP_SchemaInfoStructType;

typedef struct
{
  /* A list of possible schemata that may be supported. The list is terminated by setting the schema
   *  information to None. */
  Scc_SAP_SchemaInfoStructType SchemaList[SCC_SCHEMALIST_SIZE];
}Scc_SAP_SchemaListStructType;


/* [V2G-417], [V2G2-424] */
typedef enum Scc_serviceIDType
{
  Scc_SID_Certificate = 0x02u,
  Scc_SID_Internet = 0x03u
#if ( SCC_ENABLE_ISO15118_2_SERVICE_HPC1 == STD_ON )
  , Scc_SID_HPC1 = 63000u /**< [V2G-PnC-CharIN-012] */
#endif
  , Scc_SID_MaxAllowedValue = 0xFFFFu
} Scc_ServiceIDType;

/* [V2G20-1355] */
typedef enum Scc_ISO15118_20_serviceIDType
{
  Scc_ISO15118_20_SID_ServiceNotSet =  0u, /* Used as initial value and in application call back as "pending" value */
  /* EnergyTransferServices */
  Scc_ISO15118_20_SID_AC             =  1u, /* AC energy transfer, physical layer according to ISO 15118-3/8 */
  Scc_ISO15118_20_SID_DC             =  2u, /* DC energy transfer, physical layer according to ISO 15118-3/8 */
  Scc_ISO15118_20_SID_WPT            =  3u, /* WPT, physical layer according to ISO 15118-8 */
  Scc_ISO15118_20_SID_DC_ACDP        =  4u, /* DC Charging with ACDP, physical layer according to ISO 15118-8 */
  Scc_ISO15118_20_SID_AC_BPT         =  5u, /* AC Charging with BPT, physical layer according to ISO 15118-3/8 */
  Scc_ISO15118_20_SID_DC_BPT         =  6u, /* DC Charging with BPT, physical layer according to ISO 15118-3/8 */
  Scc_ISO15118_20_SID_DC_ACDP_BPT    =  7u, /* DC Charging with ACDP and BPT, physical layer according to ISO 15118-8 */
  /* 8 - 64: Currently unused */
  Scc_ISO15118_20_SID_LastPossibleEnergyTransferServices = 64u, /* Internal: Used for checks */

  /* General services */
  Scc_ISO15118_20_SID_Internet       = 65u, /* Service for standard protocols like HTTP, HTTPs, FTP, etc. */
  Scc_ISO15118_20_SID_ParkingStatus  = 66u, /* Service for approach and departure of EV */
  /* 67 - 32767: Currently unused */

  Scc_ISO15118_20_SID_StopRequestingMoreServices = 32767u, /* ID to announce the Scc to stop requesting more services of this type */
  /* 32768 - 65535: Reserved for implementation specific use -> Customer specific services */
  Scc_ISO15118_20_SID_StartOfCustomerSpecificServices = 32768u
} Scc_ISO15118_20_ServiceIDType;

typedef enum Scc_parameterSetIDType
{
  Scc_ParameterSetID_Certificate_Installation = 0x01u,
  Scc_ParameterSetID_Certificate_Update       = 0x02u,
  Scc_ParameterSetID_Internet_Https           = 0x04u
} Scc_ParameterSetIDType;

typedef enum Scc_plcChipFirmwareStatusType
{
  Scc_PlcChipFirmwareStatus_Unknown,
  Scc_PlcChipFirmwareStatus_ErrorOccurred,
  Scc_PlcChipFirmwareStatus_DownloadDone,
  Scc_PlcChipFirmwareStatus_ReadyForSlac
} Scc_PlcChipFirmwareStatusType;

typedef enum Scc_tcpSocketStateType
{
  Scc_TCPSocketState_Closed,
  Scc_TCPSocketState_Connecting,
  Scc_TCPSocketState_Connected,
  Scc_TCPSocketState_Disconnecting
} Scc_TCPSocketStateType;

typedef union Scc_Exi_structBufType
{ /* PRQA S 0750 */ /* MD_MSR_Union */
  uint8  Buf8[4];
  uint32 Buf32;
} Scc_Exi_StructBufType;
/* Above struct is required since the bytes need to be aligned in memory
 * to a start address divisible by 4. Hence by having uint32 it can be
 * made sure that the addresses are 32 bit aligned.
 * Buf32 is never used in the code */

typedef struct Scc_bufferPointerType
{
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) BufferPtr;
  uint16                                 BufferLen;
} Scc_BufferPointerType;

typedef enum
{
  SCC_POOL_BUFF_SMALL,
  SCC_POOL_BUFF_MEDIUM,
  SCC_POOL_BUFF_LARGE
} Scc_PoolBuffType;

typedef struct Scc_bufferPoolArrayType
{
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) BufferPtr;
  uint32                                 BufferLen;
  Scc_PoolBuffType                       PoolBuffType;
} Scc_BufferPoolArrayType;

typedef struct Scc_txRxBufferPointerType
{
  P2VAR(IpBase_PbufType, AUTOMATIC, SCC_APPL_DATA) PbufPtr;
  boolean                                          FirstPart;
  boolean                                          StreamComplete;
} Scc_TxRxBufferPointerType;


/* Structure representing a reference of a uint8 array */
typedef struct
{
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) BufferPtr;     /**< Pointer to the data */
  P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) BufferPtrLen; /**< Pointer to the data length */
} Scc_BufferReferenceStructType;

/* Structure representing a contract certificate chain */
typedef struct
{
  uint8                         ChoosenContractChainId; /**< Id of the chosen contract chain */
  Scc_BufferReferenceStructType MOContractCert;         /**< Reference of the MO contract certificate */
  Scc_BufferReferenceStructType MOSubCA2;               /**< Reference of the MO Sub-Ca2 certificate */
  Scc_BufferReferenceStructType MOSubCA1;               /**< Reference of the MO Sub-Ca1 certificate */
} Scc_PropagateContrCertsStructType;


#if ((defined SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON)) \
 || ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))

typedef uint32 Scc_ReferenceToCsmKeyType;    /**< Data type to store a reference to a CSM key */
typedef uint32 Scc_ReferenceToCsmJobType;    /**< Data type to store a reference to a CSM job */

typedef enum {
  Scc_CertCurve_unknown,
  Scc_CertCurve_secp256r1,
  Scc_CertCurve_secp521r1,
  Scc_CertCurve_curve448
}Scc_CertificateCurveEnumType;


/* Enum values to indicate the state of a used CSM job */
typedef enum
{
  SCC_CSMJOBSTATE_IDLE,
  SCC_CSMJOBSTATE_PENDING,
  SCC_CSMJOBSTATE_DONE,
  SCC_CSMJOBSTATE_FAILED
} Scc_CsmJobStateEnumType;

/* Enum values to show the mode of a used CSM job */
typedef enum
{
  SCC_CSMJOBMODE_SYNCHRONOUS,  /**< The CSM job is in synchronous mode */
  SCC_CSMJOBMODE_ASYNCHRONOUS  /**< The CSM job is in asynchronous mode */
} Scc_CsmJobModeEnumType;

/* Enum values to manage the user of a CSM job */
typedef enum
{
  SCC_CSMJOBUSAGE_SCC,
  SCC_CSMJOBUSAGE_XML_SIGGEN,
  SCC_CSMJOBUSAGE_XML_SIGVER
} Scc_CsmJobUsageEnumType;

/* Structure storing CSM job related information */
typedef struct
{
  Scc_CsmJobStateEnumType  State; /*!< The state of the associated csm job */
  Scc_CsmJobUsageEnumType  Usage; /*!< Indicates for what the csm job is used */
  boolean                  IsCancelled; /*!< Indicates whether the csm job is cancelled or not */
} Scc_CsmJobInfoType;

/* Structure storing CSM job related information */
typedef struct
{
  Scc_ReferenceToCsmJobType Id;        /*!< The job id of the associated csm job */
  Scc_CsmJobModeEnumType    Mode;      /*!< The mode of the associated csm job */
  Scc_ReferenceToCsmJobType JobInfoId; /*!< The id of the associated info types */
  Scc_ReferenceToCsmKeyType InputKeyId; /*!< The id of the associated info types */
} Scc_CsmJobType;

/* Structure representing the referenced CSM configuration */
typedef struct
{
  CONSTP2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) SignatureGenCsmJobPtr;    /**< Reference to the configured CSM job for signature generation */
  CONSTP2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) SignatureVerifyCsmJobPtr; /**< Reference to the configured CSM job for signature verification */
  CONSTP2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) HashCsmJobPtr;            /**< Reference to the configured CSM job for hash operation */
  CONSTP2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) KeyDeriveFuncCsmJobPtr;      /**< Reference to the configured CSM job for Key derivation function */
} Scc_CsmConfigurationStructType;

typedef struct
{
  TcpIp_TlsVersionType TlsVersionUsed;
}Scc_TLSParamStructType;

#endif /* SCC_ENABLE_TLS || SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0))

typedef union Scc_Exi_tempBufType
{ /* PRQA S 0750 */ /* MD_MSR_Union */
  uint8  Buf8[SCC_EXI_TEMP_BUF_LEN];
  uint32 Buf32[SCC_EXI_TEMP_BUF_LEN/4u];
} Scc_Exi_TempBufType;

typedef struct Scc_timeDTType
{
  /* standard definitions have all values as 'int' */
  uint8 Sec;     /* seconds after the minute - [0,60] 60 is leap second */
  uint8 Min;     /* minutes after the hour - [0,59] */
  uint8 Hour;    /* hours since midnight - [0,23] */
  uint8 Mday;    /* day of the month - [1,31] */
  uint8 Mon;     /* months since January - [0,11] */
  uint16 Year;    /* years since 1900 */
} Scc_TimeDTType;
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_SCHEMA_ISO_20  */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0))
/* Certificate related data types */
typedef uint8_least  Scc_CertArrayIterType;  /**< Data type to iterate over an array of certs */
typedef uint8  Scc_CertArraySizeType;        /**< Data type to store the size of an array */
typedef uint8  Scc_CertArrayIdType;          /**< Data type to store a reference to a configured cert in an array */
typedef uint8 Scc_ContractIdType;            /**< Data type to store a reference to a a certificate */
typedef CONSTP2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) Scc_CertNameType; /**< Data type to store the name of a referenced KeyM root/intermediate certificate */
typedef uint8 Scc_CertNameLenType; /**< Data type to store the length of a certificate name */

typedef struct
{
  Scc_CertArrayIdType    KeyMCertId;        /**< Reference to a certificate id in KeyM */
  boolean                IsProviderIdFound; /**< If KeyMCertId matches a ProviderId received in AuthorizationSetupReq */
} Scc_AvailableCertStructType;

/* Structure representing a root certificate */
typedef struct
{
  KeyM_CertificateIdType      KeyMCertId;      /**< Reference to a certificate id in KeyM */
  KeyM_CertificateGroupIdType KeyMGroupId;     /**< Reference to a certificate id in KeyM */
  Scc_CertNameType            KeyMCertName;    /**< The name of the referenced certificate */
  Scc_CertNameLenType         KeyMCertNameLen; /**< The length of the certificate name to a certificate name in KeyM */
} Scc_NamedCertStructType;

/* Structure representing a multi data type relative distinguished name (RDN) element */
typedef struct
{
  KeyM_CertElementIdType      KeyMElemIdUTF8;            /* Reference to an UTF8 element id in KeyM */
  KeyM_CertElementIdType      KeyMElemIdPrintableString; /* Reference to a PrintableString element id in KeyM */
} Scc_MultiDataTypeRDNStructType;

/* Enum used to manage the expected states of a KeyUsageExtension for a specific certificate */
typedef enum
{
  SCC_KEYMUSAGETYPE_FALSE = FALSE,      /* Flag should be disabled */
  SCC_KEYMUSAGETYPE_TRUE = TRUE,        /* Flag should be enabled */
  SCC_KEYMUSAGETYPE_OPTIONAL = 0xFEu,   /* Flag is optional */
  SCC_KEYMUSAGETYPE_DONTCARE = 0xFFu    /* Flag is not evaluated */
}Scc_CertExtensionFlagState;

/* Structure representing the KeyUsage cert extension with extended data types to store additional states inside */
typedef struct
{
  Scc_CertExtensionFlagState hasKeyUsage;
  Scc_CertExtensionFlagState isCritical;
  Scc_CertExtensionFlagState digitalSignature;
  Scc_CertExtensionFlagState nonRepudiation;
  Scc_CertExtensionFlagState keyEncipherment;
  Scc_CertExtensionFlagState dataEncipherment;
  Scc_CertExtensionFlagState keyAgreement;
  Scc_CertExtensionFlagState keyCertSign;
  Scc_CertExtensionFlagState cRLSign;
  Scc_CertExtensionFlagState encipherOnly;
  Scc_CertExtensionFlagState decipherOnly;
} Scc_Cert_ExtKeyUsageType;

/* Structure representing BasicConstraints certificate extension with
 * extended data types to store additional states inside */
typedef struct
{
  uint8 pathLenConstraint;
  Scc_CertExtensionFlagState hasBasicConstraints;
  Scc_CertExtensionFlagState isCritical;
  Scc_CertExtensionFlagState isCA;
  Scc_CertExtensionFlagState hasPathLenConstraint;
} Scc_Cert_ExtBasicConstraintsType;

/* Structure representing ExtendedKeyUsage certificate extension */
typedef struct
{
  Scc_CertExtensionFlagState HasExtendedKeyUsage;
  Scc_CertExtensionFlagState IsCritical;
} Scc_Cert_ExtExtendedKeyUsageType;

/* Structure representing Authority/Subject KeyIdentifer certificate extension */
typedef struct
{
  Scc_CertExtensionFlagState HasKeyIdentifier;
  Scc_CertExtensionFlagState IsCritical;
  boolean                    HasLengthRestriction;
  uint8                      LengthRestrictionValue;
} Scc_Cert_ExtAkiSkiType;

/* Structure representing a certificate profile for different extensions */
typedef struct
{
  P2CONST(Scc_Cert_ExtAkiSkiType, AUTOMATIC, SCC_CONST)            AuthorityKeyIdentifer; /**< AuthorityKeyIdentifier extension */
  P2CONST(Scc_Cert_ExtAkiSkiType, AUTOMATIC, SCC_CONST)            SubjectKeyIdentifier;  /**< SubjectKeyIdentifier extension */
  P2CONST(Scc_Cert_ExtKeyUsageType, AUTOMATIC, SCC_CONST)          KeyUsage;              /**< KeyUsage extension */
  P2CONST(Scc_Cert_ExtExtendedKeyUsageType, AUTOMATIC, SCC_CONST)  ExtendedKeyUsage;      /**< ExtendedKeyUsage extension */
  P2CONST(Scc_Cert_ExtBasicConstraintsType, AUTOMATIC, SCC_CONST)  BasicConstraints;      /**< BasicConstraints extension */
}Scc_Cert_CertExtensionProfileType;

/**************************************************************/
/* Common data types for both ISO 15118-2 and -20             */
/**************************************************************/

/* Structure representing the configuration of an ExtendedKeyUsage certificate extension */
typedef struct
{
  const KeyM_CertElementIdType KeyMOidElementIdx;           /**< KeyM element Id of OID */
  const KeyM_CertElementIdType KeyMCriticalElementIdx;      /**< KeyM element Id of critical */
  const KeyM_CertElementIdType KeyMKeyPurposeIdsElementIdx; /**< KeyM element Id of KeyPurpose */
} Scc_CertExtensionExtKeyUsageStructType;

/* Structure representing the configuration of an AuthorityKeyIdentifier certificate extension */
typedef struct
{
  const KeyM_CertElementIdType KeyMOidElementIdx;                        /**< KeyM element Id of OID */
  const KeyM_CertElementIdType KeyMCriticalElementIdx;                   /**< KeyM element Id of critical */
  const KeyM_CertElementIdType KeyMKeyIdentifierElementIdx;              /**< KeyM element Id of KeyIdentifier */
  const KeyM_CertElementIdType KeyMAuthorityCertIssuerElementIdx;        /**< KeyM element Id of CertIssuer */
  const KeyM_CertElementIdType KeyMAuthorityCertSerialNumberElementIdx;  /**< KeyM element Id of CertSerialNumber */
  const KeyM_CertElementIdType KeyMAuthorityCertSerialNumber2ElementIdx; /**< KeyM element Id of CertSerialNumber */
} Scc_CertExtensionAkiStructType;

/* Structure representing the configuration of an SubjectKeyIdentifier certificate extension */
typedef struct
{
  const KeyM_CertElementIdType KeyMOidElementIdx;             /**< KeyM element Id of OID */
  const KeyM_CertElementIdType KeyMCriticalElementIdx;        /**< KeyM element Id of critical */
  const KeyM_CertElementIdType KeyMKeyIdentifierElementIdx;   /**< KeyM element Id of KeyIdentifier */
} Scc_CertExtensionSkiStructType;

/* Structure representing the collection of extension configuration data */
typedef struct
{
  Scc_CertExtensionExtKeyUsageStructType  ExtendedKeyUsage;       /**< The element Id of the ExtendedKeyUsage flags that has iterations */
  Scc_CertExtensionAkiStructType          AuthorityKeyIdentifier; /**< The element Id of the AuthorityKeyIdentifier extension */
  Scc_CertExtensionSkiStructType          SubjectKeyIdentifier;   /**< The element Id of the SubjectKeyIdentifier extension */
}Scc_CertExtensionsStructType;

/* Structure representing a basic certificate */
typedef struct
{
  KeyM_CertificateIdType       KeyMCertId; /**< Reference to a certificate id in KeyM */
  Scc_CertExtensionsStructType Extensions; /**< The KeyM configuration to access extensions */
  Scc_CertificateCurveEnumType Curve;      /**< The curve being used for this certificate */
} Scc_CertBasicStructType;

/* Structure representing a KeyM certificate group */
typedef struct
{
  KeyM_CertificateGroupIdType  GroupId;                               /**< Reference to a certificate group id in KeyM */
  uint8                        CertCnt;                               /**< Number of certificate members. */
  CONSTP2CONST(Scc_CertBasicStructType, AUTOMATIC, SCC_CONST) Certs;  /**< The certificates */
} Scc_KeyMGroupStructType;

/* Structure representing a root certificate */
typedef struct
{
  KeyM_CertificateIdType KeyMCertId;                               /**< Reference to a certificate id in KeyM */
  KeyM_CertElementIdType KeyMIssuerCountryElemId;                  /**< Reference to a certificate issuer country element id in KeyM */
  Scc_MultiDataTypeRDNStructType KeyMIssuerOrganizationElem;       /**< Reference to a certificate issuer organization element in KeyM */
  Scc_MultiDataTypeRDNStructType KeyMIssuerOrganizationalUnitElem; /**< Reference to a certificate issuer organizational unit element in KeyM */
  Scc_MultiDataTypeRDNStructType KeyMIssuerCommonNameElem;         /**< Reference to a certificate issuer common name element in KeyM */
  KeyM_CertElementIdType KeyMIssuerDomainComponentElem;            /**< Reference to a certificate issuer domain component element in KeyM */
  KeyM_CertElementIdType KeyMSerialNumberElemId;                   /**< Reference to a certificate serial number element id in KeyM */
} Scc_RootCertStructType;

/* Structure representing a CPS leaf certificate */
typedef struct
{
  KeyM_CertificateIdType       KeyMCertId;                       /**< Reference to a certificate id in KeyM */
  KeyM_CertElementIdType       KeyMSubjectDomainComponentElemId; /**< Reference to the common name element of the certificate */
  KeyM_CertElementIdType       KeyMPublicKeyElemId;              /**< Reference to the public key element of the certificate */
  Scc_ReferenceToCsmKeyType    CsmPublicKeyId;                   /**< Reference to public key in CSM */
  Scc_CertificateCurveEnumType Curve;                            /**< The curve being used for this certificate */
} Scc_ISOCPSProvCertStructType;

/* Structure representing a CPS certificate chain configuration */
typedef struct
{
  uint8                   CPSLeafCnt;     /**< Number of leaf certificates configured in Scc. */
  CONSTP2CONST(Scc_ISOCPSProvCertStructType, AUTOMATIC, SCC_CONST) CPSLeafCerts; /**< The leaf certificates configured in Scc. */
  Scc_KeyMGroupStructType CPSLeafGroup;   /**< Reference to a certificate group id in KeyM */
  uint8                   CPSSubCaCnt;    /**< Number of sub certificates. Range 1-2 */
  Scc_KeyMGroupStructType CPSSubCA2Group; /**< Reference to a certificate group id in KeyM */
  Scc_KeyMGroupStructType CPSSubCA1Group; /**< Reference to a certificate group id in KeyM */
} Scc_ISOCPSCertConfigStructType;

/* Structure representing a MO/EMSP Contract certificate  */
typedef struct {
  KeyM_CertificateIdType         KeyMCertId;                                            /**< Reference to a certificate id in KeyM */
  Scc_MultiDataTypeRDNStructType KeyMCommonNameElem;                                    /**< Reference to common name element in KeyM. Stores the emaid */
  KeyM_CertElementIdType         KeyMSubjectPublicKeyElemId;                            /**< Reference to subject public key bit string element in KeyM.  */
  KeyM_CertElementIdType         KeyMValidityNotAfterKeyElemId;                         /**< Reference to validity NotAfter element in KeyM.  */
  KeyM_CertElementIdType         KeyMExtensionSubjectKeyIdentifierKeyElemId;            /**< Reference to SubjectKeyIdentifier Extension element in KeyM.  */
  Scc_ReferenceToCsmKeyType      CsmPrivateKeyId;                                       /**< Reference to private key in CSM */
  Scc_ReferenceToCsmKeyType      CsmPublicKeyId;                                        /**< Reference to public key in CSM */
  Scc_CertExtensionsStructType   Extensions;                                            /**< The KeyM configuration to access extensions */
  Scc_CertificateCurveEnumType   Curve;                                                 /**< The curve being used for this certificate */
} Scc_ISOContractCertificateStructType;

/* Structure representing a MO/EMSP Contract certificate  */
typedef struct
{
  KeyM_CertificateGroupIdType                                              KeyMGroupId;  /**< Reference to a group id in KeyM */
  uint8                                                                    ContrCertCnt; /**< The number of contract cert slots configured (e.g. secp521r1, ed448) */
  CONSTP2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) ContrCerts;   /**< The contract certificate */
} Scc_ISOContractCertificateGroupStructType;

/* Structure representing a MO/EMSP Sub-CA2 certificate  */
typedef struct
{
  KeyM_CertificateIdType       KeyMCertId;          /**< Reference to a certificate id in KeyM */
  KeyM_CertElementIdType       KeyMPublicKeyElemId; /**< Reference to public key element in KeyM. */
  Scc_ReferenceToCsmKeyType    CsmPublicKeyId;      /**< Reference to public key in Csm */
  Scc_CertExtensionsStructType Extensions;          /**< The KeyM configuration to access extensions */
  Scc_CertificateCurveEnumType Curve;               /**< The curve being used for this certificate */
} Scc_ISOContractSubCa2CertificateStructType;

/* Structure representing a MO/EMSP Sub-CA2 certificate  */
typedef struct
{
  KeyM_CertificateGroupIdType                                                    KeyMGroupId; /**< Reference to a group id in KeyM */
  uint8                                                                          SubCa2Cnt;   /**< The number of contract cert slots configured (e.g. secp521r1, ed448) */
  CONSTP2CONST(Scc_ISOContractSubCa2CertificateStructType, AUTOMATIC, SCC_CONST) SubCa2s;     /**< The contract certificate */
} Scc_ISOContractSubCa2CertificateGroupStructType;

/* Structure representing a MO/EMSP Sub-CA1 certificate  */
typedef struct
{
  KeyM_CertificateIdType       KeyMCertId;      /**< Reference to a certificate id in KeyM */
  Scc_CertExtensionsStructType Extensions;      /**< The KeyM configuration to access extensions */
  Scc_CertificateCurveEnumType Curve;           /**< The curve being used for this certificate */
} Scc_ISOContractSubCa1CertificateStructType;

/* Structure representing a MO/EMSP Sub-CA1 certificate  */
typedef struct
{
  KeyM_CertificateGroupIdType                                                    KeyMGroupId; /**< Reference to a group id in KeyM */
  uint8                                                                          SubCa1Cnt;   /**< The number of contract cert slots configured (e.g. secp521r1, ed448) */
  CONSTP2CONST(Scc_ISOContractSubCa1CertificateStructType, AUTOMATIC, SCC_CONST) SubCa1s;     /**< The contract certificate */
} Scc_ISOContractSubCa1CertificateGroupStructType;

/* Structure representing a configured contract certificate */
typedef struct
{
  Scc_ISOContractCertificateGroupStructType       ContrCert; /**< The contract certificate */
  uint8                                           SubCaCnt;  /**< Number of sub certificates. Range 0-2 */
  Scc_ISOContractSubCa2CertificateGroupStructType SubCa2;    /**< The MO Sub-CA2 certificates */
  Scc_ISOContractSubCa1CertificateGroupStructType SubCa1;    /**< The MO Sub-CA1 in KeyM (May be empty/unused if only one sub certificate is used) */
} Scc_ISOContrCertConfigStructType;
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_SCHEMA_ISO_20 */

#if ((defined SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON))
/**************************************************************/
/* ISO 15118-2 */
/**************************************************************/
/* Structure representing an OEM provisioning certificate  */
typedef struct
{
  KeyM_CertificateIdType      KeyMCertId;      /**< Reference to a certificate in KeyM */
  KeyM_CertificateGroupIdType KeyMGroupId;     /**< Reference to a group id in KeyM */
  Scc_ReferenceToCsmKeyType   CsmPrivateKeyId; /**< Reference to public key in CSM */
} Scc_OEMProvCertificateStructType;

/* Structure representing a configured contract certificate */
typedef struct
{
  Scc_ISOContrCertConfigStructType                                     ContrCertCfg;   /**< The contract certificate chain configuration */
  CONSTP2CONST(Scc_OEMProvCertificateStructType, AUTOMATIC, SCC_CONST) OEMProvCertPtr; /**< Reference to the OEM provisioning certificate used for this contract cert */
} Scc_ISO2ContrCertConfigStructType;


/* Structure storing certificate related configuration data */
typedef struct
{
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST)           RootCertsPtr;        /**< Pointer to an array of root certificates */
  Scc_CertArraySizeType                                                RootCertCnt;         /**< The size of the root certificate array */
  CONSTP2CONST(Scc_ISO2ContrCertConfigStructType, AUTOMATIC, SCC_CONST)ContrCertChainsPtr;  /**< Pointer to an array of contract certificates */
  Scc_CertArraySizeType                                                ContrCertChainCnt;   /**< The size of the contract certificate array */
  CONSTP2CONST(Scc_ISOCPSCertConfigStructType, AUTOMATIC, SCC_CONST)   CPSCertPtr;          /**< Pointer to the configured provisioning certificates. Only used temporary during certificate installation/update to check received message */
} Scc_ISO2CertConfigStructType;
#endif /* SCC_ENABLE_TLS */

#if ((defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0))
/**************************************************************/
/* ISO 15118-20 */
/**************************************************************/
/* Structure representing an OEM certificate  */
typedef struct
{
  KeyM_CertificateIdType       KeyMCertId;              /**< Reference to a certificate in KeyM */
  Scc_MultiDataTypeRDNStructType KeyMSubjectCommonName; /**< Reference to a subject common name element in KeyM */
  Scc_ReferenceToCsmKeyType    CsmPrivateKeyId;         /**< Reference to private key in CSM */
  Scc_CertificateCurveEnumType Curve;                   /**< The curve being used for this certificate */
  Scc_ReferenceToCsmKeyType    DHCsmPrivateKeyId;       /**< Reference to X448 private key in CSM. In case of SECP521R1 will contain CsmPrivateKeyId */
} Scc_ISO20OEMProvCertificateStructType;

/* Structure representing an OEM Sub-CA2 certificate  */
typedef struct
{
  KeyM_CertificateIdType       KeyMCertId;  /**< Reference to a certificate id in KeyM */
  Scc_CertificateCurveEnumType Curve;       /**< The curve being used for this certificate */
} Scc_ISO20OEMSubCa2CertificateStructType;

/* Structure representing an OEM Sub-CA1 certificate  */
typedef struct
{
  KeyM_CertificateIdType       KeyMCertId;  /**< Reference to a certificate id in KeyM */
  Scc_CertificateCurveEnumType Curve;       /**< The curve being used for this certificate */
} Scc_ISO20OEMSubCa1CertificateStructType;

/* Structure representing a configured contract certificate */
typedef struct
{
  Scc_ISO20OEMProvCertificateStructType    LeafCert;  /**< The OEM certificate */
  uint8                                    SubCaCnt;  /**< Number of sub certificates. Range 1-2 */
  Scc_ISO20OEMSubCa2CertificateStructType  SubCa2;    /**< The OEM Sub-CA2 certificate */
  Scc_ISO20OEMSubCa1CertificateStructType  SubCa1;    /**< The OEM Sub-CA1 in KeyM (May be empty/unused if only one sub certificate is used) */
} Scc_ISO20OEMCertConfigStructType;

/* Structure representing a vehicle certificate  */
typedef struct
{
  KeyM_CertificateIdType       KeyMCertId;      /**< Reference to a certificate in KeyM */
  Scc_ReferenceToCsmKeyType    CsmPrivateKeyId; /**< Reference to private key in CSM */
  Scc_CertificateCurveEnumType Curve;           /**< The curve being used for this certificate */
} Scc_ISO20VehicleCertificateStructType;

/* Structure representing a vehicle Sub-CA certificate  */
typedef struct
{
  KeyM_CertificateIdType       KeyMCertId;  /**< Reference to a certificate id in KeyM */
  Scc_CertificateCurveEnumType Curve;       /**< The curve being used for this certificate */
} Scc_ISO20VehicleSubCaCertificateStructType;

/* Structure representing a configured contract certificate */
typedef struct
{
  Scc_ISO20VehicleCertificateStructType        LeafCert;  /**< The Vehicle certificate */
  uint8                                        SubCaCnt;  /**< Number of sub certificates. Range 1-2 */
  Scc_ISO20VehicleSubCaCertificateStructType   SubCa2;    /**< The Vehicle Sub-CA2 certificate */
  Scc_ISO20VehicleSubCaCertificateStructType   SubCa1;    /**< The Vehicle Sub-CA1 in KeyM (May be empty/unused if only one sub certificate is used) */
} Scc_ISO20VehicleCertConfigStructType;

/* Structure storing certificate related configuration data */
typedef struct
{
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST)                RootCertsPtr;    /**< Pointer to an array of root certificates */
  Scc_CertArraySizeType                                                     RootCertCnt;     /**< The size of the root certificate array */
  CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST)      EMSPCertsPtr;    /**< Pointer to an array of contract certificates */
  Scc_CertArraySizeType                                                     EMSPCertCnt;     /**< The number of available contract certificates */
  CONSTP2CONST(Scc_ISO20OEMCertConfigStructType, AUTOMATIC, SCC_CONST)      OEMProvCertsPtr; /**< Pointer to an array of OEM provisioning certificates */
  Scc_CertArraySizeType                                                     OEMProvCertCnt;  /**< The number of available OEM provisioning certificates */
  CONSTP2CONST(Scc_ISO20VehicleCertConfigStructType, AUTOMATIC, SCC_CONST)  VehicleCertsPtr; /**< Pointer to an array of Vehicle certificates */
  Scc_CertArraySizeType                                                     VehicleCertCnt;  /**< The number of available Vehcile certificates */
  CONSTP2CONST(Scc_ISOCPSCertConfigStructType, AUTOMATIC, SCC_CONST)        CPSCertsPtr;     /**< Pointer to the configured CPS certificates. Only used temporary during certificate installation/update to check received message */
} Scc_ISO20CertConfigStructType;

#if (defined(SCC_ENABLE_TLS_ISO20_CLIENTAUTH) && (SCC_ENABLE_TLS_ISO20_CLIENTAUTH == STD_ON))
/* Enum used to manage the states of a vehicle chain during processing of Tls parameters */
typedef enum
{
  SCC_ISO20VEHICLECHAINSTATE_UNUSEABLE,         /**< Vehicle cert can not be used as it does not fit into Tls buffer */
  SCC_ISO20VEHICLECHAINSTATE_FITSINTOTLSBUFFER, /**< Vehicle cert fits into Tls buffer */
  SCC_ISO20VEHICLECHAINSTATE_AVAILABLE,         /**< Vehicle cert is available in ECU */
  SCC_ISO20VEHICLECHAINSTATE_MATCHESALGORITHM,  /**< Vehicle cert matches an algorithm of EVSE */
  SCC_ISO20VEHICLECHAINSTATE_MATCHESROOT        /**< Vehicle cert potentially matches a Root CA supported by EVSE */
}Scc_ISO20VehicleChainState;

/* Structure to manage the chain processing and selection operation */
typedef struct
{
  P2CONST(Scc_ISO20VehicleCertConfigStructType, AUTOMATIC, SCC_CONST) ChainCfg; /**< Related vehicle chain configuration */
  Scc_ISO20VehicleChainState ChainState;  /**< State of the current vehicle chain */
}Scc_ISO20PotentialVehicleChainList;

/* Enum used to communicate with application during checking of certificate to be installed */
typedef enum
{
  SCC_ISO20VEHICLECHAINSELECTION_DONE,   /**< The application finished the selection process */
  SCC_ISO20VEHICLECHAINSELECTION_ABORT,  /**< The application aborted selection */
  SCC_ISO20VEHICLECHAINSELECTION_PENDING /**< The application needs more time to make a decision */
} Scc_ISO20VehicleChainSelectionType;
#endif /* SCC_ENABLE_TLS_ISO20_CLIENTAUTH */
#endif /* SCC_SCHEMA_ISO20 */

#if (defined(SCC_ENABLE_ISO15118_20_TPM_SUPPORT) && (SCC_ENABLE_ISO15118_20_TPM_SUPPORT == STD_ON))

typedef struct
{
  Scc_CertArrayIdType                                               ContrCertChainId;               /**< The contract chain Id. */
  KeyM_CertificateIdType                                            ContractLeafKeyMId;             /**< The KeyM Id of the contract leaf certificate. */
  Scc_ReferenceToCsmKeyType                                         DstDecryptedPrivateKeyCsmKeyId; /**< Csm Key Id in which the the decrypted private key shall be stored. */
  KeyM_CertificateIdType                                            OEMProvCertUsedKeyMId;          /**< The KeyM Id of the OEM provisioning certificate being used. */
  Scc_ReferenceToCsmKeyType                                         OEMProvCertPrivateKeyCsmKeyId;  /**< The Csm Key Id of the OEM provisioning certificate. */
  P2CONST(Scc_BufferReferenceStructType, AUTOMATIC, SCC_VAR_NOINIT) EncryptedPrivateKeyPtr;         /**< Pointer to the encrypted private key that shall be decrypted. */
  P2CONST(Scc_BufferReferenceStructType, AUTOMATIC, SCC_VAR_NOINIT) DHPublicKeyPtr;                 /**< Pointer to DHPublicKey of the CertInstRes message. */
  Scc_CertificateCurveEnumType                                      ECDHCurve;                      /**< Curve being used for DHPublicKey. */
} Scc_ISO20CertInstTPMStructType;

#endif /* SCC_ENABLE_ISO15118_20_TPM_SUPPORT */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/* Structure storing runtime information related to configuration data */
typedef struct Scc_contrCertChainRamType
{
  Scc_CertArrayIdType ContrCertChainId; /**< The chosen contract certificate id */
#if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )
  Scc_CertArrayIdType OemCertId; /**< The chosen provisioning certificate id */
#endif
} Scc_CertRamStructType;

/* Structure storing root certificate lists */
typedef struct {
  Exi_stringType IssuerName;            /**< The issuer name */
  Exi_BigIntType SerialNumber;          /**< The serial number */
  Exi_XMLSIG_X509IssuerSerialType List; /**< The list to build up the root cert list */
} Scc_RootCertListStructType;

/* Structure representing a certificate */
typedef struct Scc_certificateType
{
  struct P2VAR(Scc_certificateType, AUTOMATIC, SCC_VAR_NOINIT) NextCertificatePtr;
  uint16                                                       Position;
  uint16                                                       Length;
} Scc_CertificateType;

/* Enum used to communicate with application during checking of certificate to be installed */
typedef enum
{
  SCC_APPLCHECKCONTRCHAIN_ALLOW,  /**< The applications allows the contract to be installed */
  SCC_APPLCHECKCONTRCHAIN_REJECT, /**< The applications rejects the installation of the contract to be installed */
  SCC_APPLCHECKCONTRCHAIN_PENDING /**< The application needs more time to make a decision */
} Scc_ApplCheckContrChainStateEnumType;

#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_TLS == STD_ON )
/* Structure representing a collection of KeyM elements */
typedef struct
{
  const uint8                                                ElemtsCnt; /**< Number of elements in the certificate */
  CONSTP2CONST(KeyM_CertElementIdType, AUTOMATIC, SCC_CONST) Elemts;    /**< Reference to KeyM elements of the certificate */
} Scc_CertElementListStructType;

/* Structure representing a TLS certificate */
typedef struct
{
  const KeyM_CertificateIdType                               KeyMCertId;             /**< Reference to a certificate id in KeyM */
  Scc_CertElementListStructType                              KeyMSubjectDCElemts;    /**< List of Subject/DomainComponent elements of the certificate */
  Scc_CertExtensionsStructType                               Extensions;             /**< The configured extensions of the certificate based on RFC 5280 */
  Scc_CertificateCurveEnumType                               Curve;                  /**< The curve being used for this certificate */
} Scc_TlsCertStructType;

/* Structure representing a string */
typedef struct
{
  const uint8 StringLen;                               /**< Length of string, excluding null terminator */
  CONSTP2CONST(uint8, AUTOMATIC, SCC_CONST) StringPtr; /**< Pointer to string value */
} Scc_StringStructType;
#endif /* ( SCC_ENABLE_TLS == STD_ON ) */

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON )

typedef enum Scc_StateM_msgStateType
{
  Scc_SMMS_PreparingRequest,
  Scc_SMMS_WaitingForResponse,
  Scc_SMMS_ProcessingResponse
#if ( SCC_ENABLE_STATEM_APPL_CONTROLLED_FLOW == STD_ON )
  , Scc_SMMS_WaitingForApplication
#endif /* SCC_ENABLE_STATEM_APPL_CONTROLLED_FLOW */
} Scc_StateM_MsgStateType;

typedef enum Scc_StateM_chargingControlType
{
  Scc_ChargingControl_None,
  Scc_ChargingControl_NegotiateChargingParameters,
#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
  Scc_ChargingControl_StartPreCharge,
  Scc_ChargingControl_PreChargeCompleted,
#endif /* SCC_CHARGING_DC */
#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
  Scc_ChargingControl_StartFinePositioningSetup,
  Scc_ChargingControl_StartFinePositioning,
  Scc_ChargingControl_WptPairing,
#endif /* SCC_SCHEMA_ISO_20WPT */
  Scc_ChargingControl_StartPowerDelivery,
#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
  Scc_ChargingControl_StartWeldingDetection,
#endif /* SCC_CHARGING_DC */
#if (( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0u )) || (( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0u ))/* PRQA S 3332 */ /* MD_Scc_3332 */
  Scc_ChargingControl_Renegotiation,
#endif /* SCC_SCHEMA_ISO || SCC_SCHEMA_ISO_20 */
#if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0u )
  Scc_ChargingControl_Standby,
  Scc_ChargingControl_Pause,
  Scc_ChargingControl_ServiceRenegotiation,
#endif /* SCC_SCHEMA_ISO_20 */
  Scc_ChargingControl_StopCharging
} Scc_StateM_ChargingControlType;

typedef enum Scc_StateM_functionControlType
{
  Scc_FunctionControl_None,
  Scc_FunctionControl_ChargingMode,
  Scc_FunctionControl_Reset
} Scc_StateM_FunctionControlType;

typedef enum Scc_StateM_stateMachineStatusType
{
  Scc_StateMachineStatus_None,
  Scc_StateMachineStatus_Initialized,
  Scc_StateMachineStatus_SLAC,
  Scc_StateMachineStatus_WaitForIP,
  Scc_StateMachineStatus_SECCDiscoveryProtocol,
  Scc_StateMachineStatus_TLConnection,
  Scc_StateMachineStatus_SupportedAppProtocol,
  Scc_StateMachineStatus_SessionSetup,
#if ( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 )
  Scc_StateMachineStatus_ACDP_VehiclePositioning,
#endif /* SCC_SCHEMA_ISO_20ACDP */
#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
  Scc_StateMachineStatus_FinePositioningSetup,
  Scc_StateMachineStatus_FinePositioning,
  Scc_StateMachineStatus_Pairing,
#endif /* SCC_SCHEMA_ISO_20WPT */
  Scc_StateMachineStatus_ServiceDiscovery,
#if (( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0u ))
  Scc_StateMachineStatus_ReadContractCertificate,
  Scc_StateMachineStatus_ReadRootCertificate,
  Scc_StateMachineStatus_DeterminePaymentOption,
  Scc_StateMachineStatus_VASList,
#endif
#if (( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0u ))
  Scc_StateMachineStatus_AuthorizationSetup,
#endif
#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
  Scc_StateMachineStatus_ReadOEMProvCert,
#endif
#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
  Scc_StateMachineStatus_ReadContrCertChain,
#endif
  Scc_StateMachineStatus_ServiceDetail,
  Scc_StateMachineStatus_PaymentServiceSelection,
  Scc_StateMachineStatus_CertificateInstallation,
  Scc_StateMachineStatus_CertificateUpdate,
  Scc_StateMachineStatus_PaymentDetails,
  Scc_StateMachineStatus_Authorization,
  Scc_StateMachineStatus_ChargeParameterDiscovery,
#if ( ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0u ))
  Scc_StateMachineStatus_ScheduleExchange,
#endif
#if ( ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0u ))
  Scc_StateMachineStatus_AlignmentCheck,
#endif /* SCC_SCHEMA_ISO_20WPT */
  Scc_StateMachineStatus_PowerDelivery,
#if ( ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0u ))
  Scc_StateMachineStatus_ChargeLoop,
#endif
  Scc_StateMachineStatus_MeteringReceipt,
#if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
  Scc_StateMachineStatus_ChargingStatus,
#endif /* SCC_CHARGING_AC */
#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
  Scc_StateMachineStatus_ACDP_Connect,
#endif /* SCC_SCHEMA_ISO_20ACDP */
#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
  Scc_StateMachineStatus_CableCheck,
  Scc_StateMachineStatus_PreCharge,
  Scc_StateMachineStatus_CurrentDemand,
  Scc_StateMachineStatus_WeldingDetection,
#endif /* SCC_CHARGING_DC */
#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
  Scc_StateMachineStatus_ACDP_Disconnect,
#endif /* SCC_SCHEMA_ISO_20ACDP */
#if (( defined SCC_ENABLE_ACDP_SYSTEM_STATUS ) && ( SCC_ENABLE_ACDP_SYSTEM_STATUS != 0 ))
  Scc_StateMachineStatus_ACDP_SystemStatus,
#endif /* SCC_ENABLE_ACDP_SYSTEM_STATUS */
  Scc_StateMachineStatus_SessionStop,
  Scc_StateMachineStatus_StopCommunicationSession,
  Scc_StateMachineStatus_AbortCommunicationSession,
#if ( ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0u ))
  Scc_StateMachineStatus_RestoreOldSessionInformation,
#endif /* SCC_CHARGING_AC */
  Scc_StateMachineStatus_LeavePLCNetwork,
  Scc_StateMachineStatus_Error_LeavePLCNetwork,
  Scc_StateMachineStatus_Finished,
  Scc_StateMachineStatus_WaitingForRetry,
  Scc_StateMachineStatus_Error_WaitingForRetry,
  Scc_StateMachineStatus_Error_Stopped
} Scc_StateM_StateMachineStatusType;


typedef enum Scc_StateM_energyTransferModeType
{
  Scc_EnergyTransferMode_None          = 0x00u,
  Scc_EnergyTransferMode_AC_1P         = 0x01u,
  Scc_EnergyTransferMode_AC_3P         = 0x02u,
  Scc_EnergyTransferMode_DC_Core       = 0x04u,
  Scc_EnergyTransferMode_DC_Extended   = 0x08u,
  Scc_EnergyTransferMode_DC_Combo_Core = 0x10u,
  Scc_EnergyTransferMode_DC_Unique     = 0x20u
} Scc_StateM_EnergyTransferModeType;

typedef enum Scc_StateM_energyTransferServiceIDType
{
  Scc_ET_SID_None         = 0x00u,
  Scc_ET_SID_AC_Charging  = 0x01u,
  Scc_ET_SID_DC_Charging  = 0x02u,
  Scc_ET_SID_ACD_Charging = 0x04u,
  Scc_ET_SID_WPT_Charging = 0x08u,
  Scc_ET_SID_AC_BPT       = 0x10u,
  Scc_ET_SID_DC_BPT       = 0x20u
} Scc_StateM_EnergyTransferServiceIDType;

typedef enum Scc_StateM_vasIDType
{
  Scc_VasId_None                      = 0x00u,
  Scc_VasId_WPT_FinePositioning       = 0x01u,
  Scc_VasId_WPT_Pairing               = 0x02u,
  Scc_VasId_WPT_InitialAlignmentCheck = 0x04u,
  Scc_VasId_Certificate               = 0x08u,
  Scc_VasId_Internet                  = 0x10u,
  Scc_VasId_SystemStatus              = 0x20u,
  Scc_VasId_ParkingAssistance         = 0x40u
} Scc_StateM_VASIDType;

typedef enum Scc_StateM_paymentPrioritizationType
{
  Scc_PaymentPrioritization_OnlyEIM,
  Scc_PaymentPrioritization_OnlyPnC,
  Scc_PaymentPrioritization_PrioritizePnC
} Scc_StateM_PaymentPrioritizationType;

typedef enum Scc_StateM_paymentOptionType
{
  Scc_PaymentOption_None,
  Scc_PaymentOption_EIM,
  Scc_PaymentOption_PnC
} Scc_StateM_PaymentOptionType;

typedef enum Scc_StateM_evseProcessingType
{
  Scc_EVSEProcessing_Ongoing,
  Scc_EVSEProcessing_Finished
} Scc_StateM_EVSEProcessingType;

typedef enum Scc_StateM_pwmStateType
{
  Scc_PWMState_ChargingNotAllowed,
  Scc_PWMState_HLCOptional,
  Scc_PWMState_HLCOptional_BCActive,
  Scc_PWMState_HLCOnly /* 5% duty cycle */
} Scc_StateM_PWMStateType;

typedef enum Scc_StateM_chargeStatusType
{
  Scc_ChargeStatus_Preparing,
  Scc_ChargeStatus_Starting,
  Scc_ChargeStatus_Renegotiating,
#if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0u )
  Scc_ChargeStatus_Standby,
#endif /* SCC_SCHEMA_ISO_20 */
  Scc_ChargeStatus_Stopping
} Scc_StateM_ChargeStatusType;

# if (   ((defined SCC_SCHEMA_DIN) && (SCC_SCHEMA_DIN != 0)) \
      || ((defined SCC_SCHEMA_OPP_CHARGE) && (SCC_SCHEMA_OPP_CHARGE != 0)) )
typedef enum Scc_StateM_evseNotificationType
{
  Scc_EVSENotification_StopCharging,
  Scc_EVSENotification_None
} Scc_StateM_EVSENotificationType;
# endif /* SCC_SCHEMA_DIN || SCC_SCHEMA_OPP_CHARGE */

# if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
typedef struct
{
  uint8 Length;
  uint8 Buffer[SCC_PROVIDER_ID_BUFF_LEN];
}Scc_ISO15118_20_ProviderIdType;

typedef struct
{
  uint8                                      NumOfSupportedProviders;
  Scc_ISO15118_20_ProviderIdType             ProviderId[SCC_MAX_SUPPORTED_PROVIDERS];
}Scc_ISO15118_20_SupportedProvidersType;
# endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
#endif /* SCC_ENABLE_STATE_MACHINE */

typedef enum Scc_ISO_paymentOptionType
{
  SCC_ISO_PAYMENT_OPTION_TYPE_CONTRACT         = 0u,
  SCC_ISO_PAYMENT_OPTION_TYPE_EXTERNAL_PAYMENT = 1u
} Scc_ISO_PaymentOptionType;

typedef enum Scc_ISO_chargingSessionType
{
  SCC_ISO_CHARGING_SESSION_TYPE_TERMINATE = 0u,
  SCC_ISO_CHARGING_SESSION_TYPE_PAUSE     = 1u
} Scc_ISO_ChargingSessionType;

/* [V2G20 - 1356] */
typedef enum Scc_ISO15118_20_controlModeType
{
  SCC_ISO15118_20_CONTROL_MODE_TYPE_SCHEDULED = 1u,
  SCC_ISO15118_20_CONTROL_MODE_TYPE_DYNAMIC   = 2u
} Scc_ISO15118_20_ControlModeType;


typedef uint8 Scc_ConfigType;
/* PRQA L:EXT_IDENTIFIER_LENGTH */
/* PRQA L:IDENTIFIER_LENGTH */

typedef struct Scc_physicalValueType
{
  sint16 Value;
  sint8  Exponent;
} Scc_PhysicalValueType;


typedef enum
{
  SCC_MSGPROC_STEP_INIT,
  SCC_MSGPROC_STEP_PROCESS
} Scc_TxMsgProcStepsEnumType;

typedef struct
{
  Scc_TxMsgProcStepsEnumType Step; /* The current step of the response handling */
  uint16 BufIdx;                   /* A buffer index */
  uint16 payloadType;              /* V2G payload type to be sent */
  Exi_RootElementIdType                   RootElementId; /* message type identifier */
  Exi_EncodeWorkspaceType                 Exi_EncWs;     /* Exi encoding workspace */
  Exi_MemAllocWorkspaceType               Exi_AllocWs;   /* Exi allocation workspace */
  P2VAR(uint8, AUTOMATIC, SCC_VAR_NOINIT) MsgPtr;        /* Pointer to message element. Only used in ISO15118_2_ExiTx */
}Scc_TxMsgProcWSStructType;

typedef struct
{
  Exi_RootElementIdType                   RootElementId; /* message type identifier */
  Exi_DecodeWorkspaceType                 Exi_DecWs;     /* Exi decoding workspace */
}Scc_RxMsgWSStructType;

typedef struct
{
  P2VAR(uint8, AUTOMATIC, SCC_VAR_NOINIT) MsgPtr;        /* Pointer to message to be sent */
  uint32                                  MsgPtrSize;    /* Length of the buffer MsgPtr is pointing to */
  uint8                                   BufferPoolId;  /* BufferPoolId of the buffer used */
}Scc_BufferPoolWSStructType;

#if (( defined SCC_SCHEMA_ISO ) && (SCC_SCHEMA_ISO != 0)) || ( SCC_SCHEMA_ISO_20 != 0 )

typedef enum
{
  SCC_CERTRES_STEP_HANDLERESPONSE,
  SCC_CERTRES_STEP_WARNINGIGNORERESPONSE,
  SCC_CERTRES_STEP_ONGOINGRESPONSE,
  SCC_CERTRES_STEP_CHECKCONTRACTCERTPARAM,
  SCC_CERTRES_STEP_CLEARKEYMCERTS,
  SCC_CERTRES_STEP_HANDLECPSPROVSUBCA1,
  SCC_CERTRES_STEP_HANDLECPSPROVSUBCA2,
  SCC_CERTRES_STEP_HANDLECPSPROVLEAF,
  SCC_CERTRES_STEP_PREPAREXMLSIGNATURE,
  SCC_CERTRES_STEP_VERIFYXMLSIGNATURE,
  SCC_CERTRES_STEP_CPSCHECKDOMAINCOMPONENT,
  SCC_CERTRES_STEP_PROPAGATECONTRTOAPPLICATION,
  SCC_CERTRES_STEP_CHECKAPPLICATION,
  SCC_CERTRES_STEP_DELETEOLDCONTRACT,
  SCC_CERTRES_STEP_HANDLEMOSUBCA1,
  SCC_CERTRES_STEP_HANDLEMOSUBCA2,
  SCC_CERTRES_STEP_HANDLEMOCONTRACT,
  SCC_CERTRES_STEP_PREPAPREKEYDERIVEFUNC,
  SCC_CERTRES_STEP_KEYDERIVEFUNC,
  SCC_CERTRES_STEP_PREPAPREVALIDATEKEYPAIR,
  SCC_CERTRES_STEP_VALIDATEKEYPAIR,
  SCC_CERTRES_STEP_HANDLEPRIVATEKEY,
  SCC_CERTRES_STEP_PROPOGATERESPARAMETERS,
  SCC_CERTRES_STEP_CLEARCONTRACT,
  SCC_CERTRES_STEP_CLEARCPS
} Scc_CertificateResStepsEnumType;

typedef struct
{
  Scc_CertificateResStepsEnumType Step; /*!< The current step of the response handling */
  uint32_least  RootCertId;             /*!< The id of the root certificate which shall be used to verify the received chain */
  uint32 CurrentTime;                   /*!< The time used to verify the chain */
#if (defined(SCC_SCHEMA_ISO) && (SCC_SCHEMA_ISO != 0u))
  P2VAR(Exi_ISO_certificateType, AUTOMATIC, SCC_APPL_DATA) LastCertInChainPtr; /*!< Pointer to the last certificate of the chain */
#endif /* SCC_SCHEMA_ISO */
  Scc_ReturnType InitialRetVal;         /*!< Temporary variable to preserve the retval across multiple main function calls */
}Scc_CertificateResWSStructType;

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
typedef struct {
  uint8                     SignatureEncoded[SCC_P256R1_SIGNATURE_LEN];
  Crypto_VerifyResultType   ValCertChainVerifyResult;
#if (defined(SCC_SCHEMA_ISO) && (SCC_SCHEMA_ISO != 0u))
  P2CONST(Exi_ISO_certificateType, AUTOMATIC, SCC_VAR_NOINIT) ExiCertPtr;
#endif /* SCC_SCHEMA_ISO */
} Scc_PrivValidateCertChainWorkspaceType;

typedef struct {
  uint8                     CryptoBuf[SCC_CRYPTO_BUF_LEN];
  uint8                     Sha256HashBuf[SCC_SHA256_DIGEST];
  Crypto_VerifyResultType   VerifyResult;
  uint32                    SignatureLengthCsm;
  uint16                    PubKeyIdx;
  uint16                    PubKeyLen;
} Scc_PrivValidateKeyPairWorkspaceType;
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

typedef enum
{
  SCC_CHRGPARAMDISC_STEP_HANDLERESPONSE,
  SCC_CHRGPARAMDISC_STEP_CHEKCSASCHEDULELIST,
#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
  SCC_CHRGPARAMDISC_STEP_PNC_CHEKCSASCHEDULELIST,
  SCC_CHRGPARAMDISC_STEP_PNC_VERIFYSIGNATURE,
  SCC_CHRGPARAMDISC_STEP_PNC_REMOVESALESTARIFF,
#endif
  SCC_CHRGPARAMDISC_STEP_SETSASCHEDULELIST,
  SCC_CHRGPARAMDISC_STEP_HANDLECALLBACKS
} Scc_ChargeParameterDiscoveryEnumType;

typedef struct
{
  Scc_ChargeParameterDiscoveryEnumType Step; /*!< The current step of the response handling */
}Scc_ChargeParameterDiscoveryResWSStructType;


typedef uint32 Scc_CsmJobInfoIndirectionType;
#endif /* SCC_SCHEMA_ISO || SCC_SCHEMA_ISO_20 */


typedef enum {
  SCC_V2GTPHEADER_OK,
  SCC_V2GTPHEADER_INVALIDPROTOCOLVERSION,
  SCC_V2GTPHEADER_UNSUPPORTEDPAYLOADTYPE,
  SCC_V2GTPHEADER_INVALIDPAYLOADLENGTH
}Scc_V2GTPHeaderCheckResultEnumType;


/*!
 * The V2GTP header based on [V2G-DC-162], [V2G2-082], [V2G20-082]
 */
typedef struct {
  uint8   ProtocolVersion;
  uint8   InverseProtocolVersion;
  uint16  PayloadType;
  uint32  PayloadLength;
}Scc_V2GTPHeaderStructType;

/* FunctionPointer */

typedef Scc_ReturnType(*Scc_ExiTx_Xyz_PrepareMessageFctType)(
    P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr);

typedef Scc_ReturnType (*Scc_ExiRx_Xyz_DecodeMessageFctType)(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTPHeader,
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);

typedef Scc_ReturnType (*Scc_ExiRx_Xyz_DecodeMessagePrepareFctType)(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTPHeader,
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);

typedef P2CONST(uint16, AUTOMATIC, SCC_APPL_DATA) Scc_RxCurrentSupportedPayloadTypeListPtrType;

typedef void (*Scc_RxQueue_ReleaseDataPtr)(const uint32 Length);

typedef struct {
  Scc_ExiRx_Xyz_DecodeMessageFctType DecodeFct; /*!< Decodes the received message */
  Scc_ExiRx_Xyz_DecodeMessagePrepareFctType DecodePrepareFct; /*!< Prepares the message receiving */
  Scc_RxCurrentSupportedPayloadTypeListPtrType SupportedPayloadTypeList; /*!< A list of supported payload types for the current session */
  uint16 SupportedPayloadTypeListLen; /*!< The length of the supported payload list */
  boolean PropagteMessage;   /*!< Indicates if the message should be propagated to the application */
}Scc_RxConfigStructType;


typedef uint64 Scc_TimestampType;

/*!
 * Ring buffer concept:
 *---------------------
 *
 *  The ring buffer does not store data, it rather stores information pointing to a memory
 *  location where the data to handle is stored. Distributed memory locations can be grouped
 *  to a logical memory section.
 *
 *      ---------------      ---------------     ---------------
 *      | Mem section |      | Mem section |     | Mem section |
 *      ---------------      ---------------     ---------------
 *             ^                   ^                   ^
 *             |                   |                   |
 *             |                   |                   |
 *        |----------|        |----------|        |----------|
 *        | pbuf[0]  |        | pbuf[...]|        | pbuf[n-1]|
 *  |---> |          | ---->  |          | ---->  |          | ----|
 *  |     |          |        |          |        |          |     |
 *  |     |----------|        |----------|        |----------|     |
 *  |                                                              |
 *  |--------------------------------------------------------------|
 *
 */
typedef struct {
  P2VAR(Scc_PbufType, AUTOMATIC, SCC_APPL_DATA) RxStreamPBuf; /**< Pointer to PBuf structure which is used as a ring buffer. Init value: All pbuf elements are 0 */
  uint32 RxStreamPBufLen; /**< Pointer to PBuf structure which is used as a ring buffer. Init value: All pbuf elements are 0 */
  volatile uint32 WriteId;  /**< Contains the Id of the current pbuf to write new data to. Init value: 0 */
  volatile uint32 ReadId;   /**< Contains the Id of the current pbuf to read new data from. Init value: 0 */
  volatile boolean IsEmpty; /**< Flag indicating the emptiness of the rx queue. Init value: TRUE */
  Scc_RxQueue_ReleaseDataPtr ReleaseFctPtr;
}Scc_RxDataQueueStructType;

#if (defined SCC_IPADDR_SELECTION) && (SCC_IPADDR_SELECTION == STD_ON)
typedef enum {
  SCC_IPADDR_SELECTION_ADDRESS1,
  SCC_IPADDR_SELECTION_ADDRESS2,
  SCC_IPADDR_SELECTION_END
} Scc_IpAddressSelectionEnumType;
#endif /* (SCC_IPADDR_SELECTION == STD_ON) */

#if (defined SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON) \
 || (defined(SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON))
typedef enum {
#if (defined SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)
  SCC_PROCCERTINSTRES_ISO15118_2 = 0  /**< Enum constant used to install a ISO/IEC 15118-2 certificate installation response message */
#endif
#if (defined SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON) \
 && (defined(SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON))
,
#endif
# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
  SCC_PROCCERTINSTRES_ISO15118_20 = 1 /**< Enum constant used to install a ISO/IEC 15118-20 certificate installation response message */
# endif
}Scc_ProcessCertInstResEnumType;
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */


typedef enum {
  Scc_StrCmp_Strict,
  Scc_StrCmp_EndsWith
}Scc_StringCompareMode;

/*!
 * Defines the detailed and unique error codes of the Scc stack.
 */
typedef enum
{
  SccDetailedError_No_Error = 0,


  /**************************************************************************************************/
  /***************************************** General ************************************************/
  /**************************************************************************************************/

  /***************************************** Reset **************************************************/
  /*!
   * Description:  A reset was triggered while a CSM job was still pending and therefore the job must
   *                be cancelled.
   * Source:       Internal
   * Reason:       CSM cancel request failed.
   * Note:         May contain Csm error. */
  SccDetailedError_General_ResetCsmJobCancelFailed = 0x00640000,
  /*!
   * Description:  Unable to write key element.
   * Source:       External
   * Reason:       Unable to write key element to Csm. This issue may happen due to a configuration issue in Csm.
   * Note:         May contain Csm error. */
  SccDetailedError_General_ResetSessionResumeSessionWriteFailed = 0x00650000,
  /*!
   * Description:  Unable to write key element.
   * Source:       External
   * Reason:       Unable to write key element to Csm. This issue may happen due to a configuration issue in Csm.
   * Note:         May contain Csm error. */
  SccDetailedError_General_ResetSessionResumeSessionValidWriteFailed = 0x00660000,
  /*!
   * Description:  Unable to write key element.
   * Source:       External
   * Reason:       Unable to write key element to Csm. This issue may happen due to a configuration issue in Csm.
   * Note:         May contain Csm error. */
  SccDetailedError_General_ResetSessionHashWriteFailed = 0x00670000,
  /*!
   * Description:  Unable to write key element.
   * Source:       External
   * Reason:       Unable to write key element to Csm. This issue may happen due to a configuration issue in Csm.
   * Note:         May contain Csm error. */
  SccDetailedError_General_ResetSessionHashValidWriteFailed = 0x00680000,


  /***************************************** Main Function ******************************************/
  /*!
   * Description:  An error occurred while parsing the V2GTP header
   * Source:       Internal
   * Reason:       - */
  SccDetailedError_General_MainRxMessageHeaderParsingFailed = 0x00C80000,
  /*!
   * Description:  An invalid V2GTP header was detected and therefore the message should be discarded
   *               and the associated buffer freed.
   * Source:       Internal
   * Reason:       Releasing the associated buffer failed. */
  SccDetailedError_General_MainRxMessageInvalidV2gtpHeaderReleaseMsgFailed = 0x00C90000,
  /*!
   * Description:  A V2G message was received and should be processed.
   * Source:       Internal
   * Reason:       Unable to fetch message data. */
  SccDetailedError_General_MainRxMessageQueueDataFetchingFailed = 0x00CA0000,
  /*!
   * Description:  A V2G message was processed. The associated buffer should
   *               be released and the reception of new message be enabled.
   * Source:       Internal
   * Reason:       Releasing the associated buffer failed. */
  SccDetailedError_General_MainRxMessageReleaseMsgFailed = 0x00CD0000,
  /*!
   * Description:  An invalid V2GTP header including a faulty protocol version and inverse protocol version
   *               was detected and in case of DIN70121 the connection is going to be terminated due to this.
   * Source:       External
   * Reason:       Erroneous V2GTP header received which was sent by an EVSE. */
  SccDetailedError_General_MainRxMessageDinInvalidV2gtpHeaderProtocol = 0x00CF0000,
  /*!
   * Description:  An invalid V2GTP header including an invalid payload length was detected and in case of
   *               DIN70121 the connection is going to be terminated due to this.
   * Source:       External
   * Reason:       Erroneous V2GTP header received which was sent by an EVSE. */
  SccDetailedError_General_MainRxMessageDinInvalidV2gtpHeaderPayloadlength = 0x00D00000,
  /*!
   * Description:  A V2G message was received with an invalid payload length.
   * Source:       External
   * Reason:       EVSE sent an invalid message. */
  SccDetailedError_General_MainRxMessageDinInvalidPayloadLen = 0x00D30000,
  /*!
   * Description:  A V2GTP header containing an unsupported length was detected, therefore
   *               the message is going to be discarded and the associated buffer freed.
   * Source:       External
   * Reason:       EVSE sent a message with too big payload (payload bigger than 0xFFFFFFF7) */
  SccDetailedError_General_MainRxMessageUnsupportedPayloadLen = 0x00D50000,
  /*!
   * Description:  An unexpected message was received. The received message was received
   *                eventhough no request was sent. The message is going to be discarded
   *                and the associated buffer freed.
   * Source:       External
   * Reason:       EVSE sent a response without a request */
  SccDetailedError_General_MainRxMessageUnexpectedMessage = 0x00D60000,
  /*!
   * Description:  An invalid V2GTP header including a faulty protocol version and inverse protocol version
   *               was detected and in case of OPP Charge the connection is going to be shutdown due to this.
   * Source:       External
   * Reason:       Erroneous V2GTP header received which was sent by an EVSE. */
  SccDetailedError_General_MainRxMessageOppChargeInvalidV2gtpHeaderProtocol = 0x00D70000,
  /*!
   * Description:  A V2G message was received with an invalid payload length.
   * Source:       External
   * Reason:       EVSE sent an invalid message. */
  SccDetailedError_General_MainRxMessageOppChargeInvalidPayloadLen = 0x00D80000,


  /***************************************** Trigger V2G ********************************************/
  /*!
   * Description:  An invalid message trigger is set.
   * Source:       External
   * Reason:       If the application is not using the Vector state machine it may provided a wrong message trigger. */
  SccDetailedError_General_TriggerV2gMsgTriggerInvalid = 0x012C0000,


  /***************************************** Trigger Certs ******************************************/
  /*!
   * Description:  The certificate could not be updated.
   * Source:       External
   * Reason:       The contract certificate could not be updated by KeyM. This issue may happen
   *                due to a configuration issue in KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_General_TriggerReadCertContrFailed = 0x015E0000,
  /*!
   * Description:  The certificate could not be updated.
   * Source:       External
   * Reason:       The configured V2G root certificates could not be updated by KeyM. This issue may happen
   *                due to a configuration issue in KeyM or if no valid Root certificate is available.
   * Note:         May contain KeyM error. */
  SccDetailedError_General_TriggerReadRootCertsFailed = 0x015F0000,
  /*!
   * Description:  The certificate could not be updated.
   * Source:       External
   * Reason:       The configured OEM provisioning certificates of the chosen contract cert chain could
   *                not be updated by KeyM. This issue may happen due to a configuration issue in KeyM
   *                or an empty certificate slot.
   * Note:         May contain KeyM error. */
  SccDetailedError_General_TriggerReadOEMProvCertFailed = 0x01600000,

  /*!
   * Description:  The certificate could not be updated.
   * Source:       External
   * Reason:       The contract certificate SubCa2 could not be updated by KeyM. This issue may happen
   *                due to a configuration issue in KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_General_TriggerReadCertContrSubCa2Failed = 0x01610000,
  /*!
   * Description:  The certificate could not be updated.
   * Source:       External
   * Reason:       The contract certificate SubCa1 could not be updated by KeyM. This issue may happen
   *                due to a configuration issue in KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_General_TriggerReadCertContrSubCa1Failed = 0x01620000,


  /***************************************** Timeout ************************************************/
  /*!
   * Description:  A general timeout occurred.
   * Source:       External
   * Reason:       The SECC did not respond to a request before the end of the timeout. */
  SccDetailedError_GeneralTimeout = 0x01900000,
  /*!
   * Description:  A SECC discovery protocol timeout occurred.
   * Source:       External
   * Reason:       No SECC responded to the SDP request before the end of the timeout. */
  SccDetailedError_General_TimeoutSdp = 0x01910000,


  /***************************************** Transport Layer ****************************************/
  /*!
   * Description:  A V2G communication session is active but the TCP connection was closed.
   * Source:       External
   * Reason:       The SECC closed the communication. This is not allowed. */
  SccDetailedError_General_TransportLayerSeccClosedConnection = 0x01F40000,
  /*!
   * Description:  A V2G communication session is active but the TCP connection was closed.
   * Source:       External
   * Reason:       The SECC closed the communication. This is not allowed. */
  SccDetailedError_General_TransportLayerShutdownSeccClosedConnection = 0x01F50000,
  /*!
   * Description:  While establishing a TLS connection the Scc verifies the used certificate chain.
   * Source:       External
   * Reason:       Tls reports an unsupported validation result to Scc. */
  SccDetailedError_General_TransportLayerUnsupportedTlsValidationResult = 0x01F60000,
  /*!
   * Description:  An active V2G communication was ongoing.
   * Source:       External
   * Reason:       TcpIp reported an address assignment change that indicated the loose of the IP address. */
  SccDetailedError_General_TransportLayerIpAddressLost = 0x01F70000,
  /*!
   * Description:  Unable to read certificate.
   * Source:       External
   * Reason:       Unable to read certificate from KeyM. This issue may happen due to a configuration issue in KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_General_TransportLayerCertificateReadFailed = 0x01F80000,
  /*!
   * Description:  Unable to generate Hash.
   * Source:       External
   * Reason:       Unable to generate Hash in Csm. This issue may happen due to a configuration issue in Csm.
   * Note:         The Csm job to calculate the Hash could not be started. */
  SccDetailedError_General_TransportLayerHashGenerationFailed = 0x01F90000,
  /*!
   * Description:  Unable to read key element.
   * Source:       External
   * Reason:       Unable to read key element from Csm. This issue may happen due to a configuration issue in Csm.
   * Note:         May contain Csm error. */
  SccDetailedError_General_TransportLayerResumeSessionReadFailed = 0x01FA0000,
  /*!
   * Description:  Unable to read key element.
   * Source:       External
   * Reason:       Unable to read key element from Csm. This issue may happen due to a configuration issue in Csm.
   * Note:         May contain Csm error. */
  SccDetailedError_General_TransportLayerHashReadFailed = 0x01FB0000,
  /*!
   * Description:  Unable to write key element.
   * Source:       External
   * Reason:       Unable to write key element to Csm. This issue may happen due to a configuration issue in Csm.
   * Note:         May contain Csm error. */
  SccDetailedError_General_TransportLayerResumeSessionWriteFailed = 0x01FC0000,
  /*!
   * Description:  Unable to write key element.
   * Source:       External
   * Reason:       Unable to write key element to Csm. This issue may happen due to a configuration issue in Csm.
   * Note:         May contain Csm error. */
    SccDetailedError_General_TransportLayerResumeSessionValidWriteFailed = 0x01FD0000,
  /*!
   * Description:  Unable to write key element.
   * Source:       External
   * Reason:       Unable to write key element to Csm. This issue may happen due to a configuration issue in Csm.
   * Note:         May contain Csm error. */
  SccDetailedError_General_TransportLayerHashWriteFailed = 0x01FE0000,
  /*!
   * Description:  Unable to write key element.
   * Source:       External
   * Reason:       Unable to write key element to Csm. This issue may happen due to a configuration issue in Csm.
   * Note:         May contain Csm error. */
  SccDetailedError_General_TransportLayerHashValidWriteFailed = 0x01FF0000,

  /*!
   * Description:  Before the SDP request can be send, the associated socket must be configured.
   * Source:       External
   * Reason:       TcpIp rejected the request to fetch the socket. This may be caused by an configuration issue or no free socket. */
  SccDetailedError_General_TransportLayerSdpGetSocketFailed = 0x02120000,
  /*!
   * Description:  Before the SDP request can be send, the associated socket must be configured.
   * Source:       External
   * Reason:       TcpIp rejected the request to change the tx confirmation list. */
  SccDetailedError_General_TransportLayerSdpChangeParameterFailed = 0x02130000,
  /*!
   * Description:  Before the SDP request can be send, the associated socket must be configured.
   * Source:       External
   * Reason:       TcpIp rejected the request to bind the socket to the IP address configured at: /MICROSAR/Scc/SccGeneral/SccConnectionConfig/SccIPv6AddressRef. */
  SccDetailedError_General_TransportLayerSdpBindFailed = 0x02140000,
  /*!
   * Description:  The SDP request was not sent.
   * Source:       External
   * Reason:       TcpIp rejected the request to data transmission. */
  SccDetailedError_General_TransportLayerSdpUdpTransmitFailed = 0x02150000,
  /*!
    * Description:  The SDP DiagStatus was set to Error - no SECC
    * Source:       External
    * Reason:       SECC was not able to pair the EV */
  SccDetailedError_General_TransportLayerSdpDiagStatusNoSecc = 0x02160000,
  /*!
   * Description:  Before the V2G communication can be established, the associated socket must be configured.
   * Source:       External
   * Reason:       TcpIp rejected the request to fetch the socket. This may be caused by an configuration issue or no free socket. */
  SccDetailedError_General_TransportLayerV2gGetSocketFailed = 0x02300000,
  /*!
   * Description:  Before the V2G communication can be established, the associated socket must be configured.
   * Source:       External
   * Reason:       TcpIp rejected the request to change the tx buffer size. */
  SccDetailedError_General_TransportLayerV2gChangeParameterTxBufferSizeFailed = 0x02310000,
  /*!
   * Description:  Before the V2G communication can be established, the associated socket must be configured.
   * Source:       External
   * Reason:       TcpIp rejected the request to change the rx buffer size. */
  SccDetailedError_General_TransportLayerV2gChangeParameterRxBufferSizeFailed = 0x02320000,
  /*!
   * Description:  Before the V2G communication can be established, the associated socket must be configured.
   * Source:       External
   * Reason:       TcpIp rejected the request to use Tls. */
  SccDetailedError_General_TransportLayerV2gChangeParameterUseTlsFailed = 0x02330000,
  /*!
   * Description:  Before the V2G communication can be established, the associated socket must be configured.
   * Source:       External
   * Reason:       TcpIp rejected the request to change the Tls tx buffer size. */
  SccDetailedError_General_TransportLayerV2gChangeParameterTlsTxBufferSizeFailed = 0x02340000,
  /*!
   * Description:  Before the V2G communication can be established, the associated socket must be configured.
   * Source:       External
   * Reason:       TcpIp rejected the request to change the Tls rx buffer size. */
  SccDetailedError_General_TransportLayerV2gChangeParameterTlsRxBufferSizeFailed = 0x02350000,
  /*!
   * Description:  Before the V2G communication can be established, the associated socket must be configured.
   * Source:       External
   * Reason:       TcpIp rejected the request to bind the socket to the IP address configured at: /MICROSAR/Scc/SccGeneral/SccConnectionConfig/SccIPv6AddressRef. */
  SccDetailedError_General_TransportLayerV2gBindFailed = 0x02360000,
  /*!
   * Description:  Before the V2G communication can be established, the associated socket must be configured.
   * Source:       External
   * Reason:       TcpIp rejected the request to connect the socket with the SECC. */
  SccDetailedError_General_TransportLayerV2gConnectFailed = 0x02370000,
  /*!
   * Description:  A V2G communication is established and should be closed.
   * Source:       External
   * Reason:       TcpIp rejected the request to close the connection. */
  SccDetailedError_General_TransportLayerV2gCloseFailed = 0x02380000,
  /*!
    * Description:  The length of prioritized cipher suite and signature algorithm must be correct.
    * Source:       External
    * Reason:       The length of prioritized cipher suite or signature algorithm is either too short or too long. */
  SccDetailedError_General_TransportLayerChangeCipherSuiteOrSignatureInvalidLength = 0x023A0000,
  /*!
    * Description:  The Tls certificate chain is based on a rejected elliptic curve
    * Source:       External
    * Reason:       The Tls certificate chain (including Ocsp chain) uses a elliptic curve which is rejected by application. */
  SccDetailedError_ISO20_TransportLayerTlsCertChainEllipticCurveRejected = 0x023B0000,


  /***************************************** Slac ***************************************************/
  /*!
   * Description:  Slac failed
   * Source:       External
   * Reason:       Slac reports an erroneous association status. */
  SccDetailedError_General_SlacAssociationStatusError = 0x02580000,
  /*!
   * Description:  Slac needs to establish a link to enable V2G communication.
   * Source:       External
   * Reason:       No link coud be established. */
  SccDetailedError_General_SlacNoLinkEstablished = 0x02590000,
  /*!
   * Description:  Slac handles the firmware download.
   * Source:       External
   * Reason:       Firmware download failed. */
  SccDetailedError_General_SlacFirmwareDownloadFailed = 0x025A0000,
  /*!
   * Description:  Slac should perform a Reset but failed.
   * Source:       External
   * Reason:       Slac failed to reset. This may be caused by reasons inside Slac. */
  SccDetailedError_General_SlacResetFailed = 0x025B0000,
  /*!
   * Description:  Slac should perform Start but failed.
   * Source:       External
   * Reason:       Slac failed to start. This may be caused by reasons inside Slac. */
  SccDetailedError_General_SlacStartFailed = 0x025C0000,
  /*!
   * Description:  Slac should perform a SessionResume but failed.
   * Source:       External
   * Reason:       Slac failed to resume a existing PLC session. This may be caused by reasons inside Slac. */
  SccDetailedError_General_SlacSessionResumeFailed = 0x025D0000,
  /*!
   * Description:  Slac should perform a ResetAndLeave.
   * Source:       External
   * Reason:       Slac failed to reset and leave the PLC Network. This may be caused by reasons inside Slac. */
  SccDetailedError_General_SlacLeavePLCNetworkFailed = 0x025E0000,
  /*!
   * Description:  Slac should perform a Reset during Scc_Reset but failed.
   * Source:       External
   * Reason:       Slac failed to reset. This may be caused by reasons inside Slac. */
  SccDetailedError_General_SlacResetFailedDuringSccReset = 0x025F0000,

  /***************************************** Diagnostics ********************************************/
  /*!
   * Description:  The client random and master secret can be leaked by Scc by sending an UDP frame.
   * Source:       External
   * Reason:       TcpIp rejected the request to fetch the socket. This may be caused by an configuration issue or no free socket. */
  SccDetailedError_General_ClientRandomMasterSecretGetSocketFailed = 0x03220000,
  /*!
   * Description:  The client random and master secret can be leaked by Scc by sending an UDP frame.
   * Source:       External
   * Reason:       TcpIp rejected the request to change the tx confirmation list. */
  SccDetailedError_General_ClientRandomMasterSecretChangeParameterFailed = 0x03230000,
  /*!
   * Description:  The client random and master secret can be leaked by Scc by sending an UDP frame.
   * Source:       External
   * Reason:       TcpIp rejected the request to bind the socket to the IP address configured at: /MICROSAR/Scc/SccGeneral/SccConnectionConfig/SccIPv6AddressRef. */
  SccDetailedError_General_ClientRandomMasterSecretBindFailed = 0x03240000,
  /*!
   * Description:  The client random and master secret can be leaked by Scc by sending an UDP frame.
   * Source:       External
   * Reason:       TcpIp rejected the request to data transmission. */
  SccDetailedError_General_ClientRandomMasterSecretTransmitFailed = 0x03250000,


  /***************************************** Rx Indication ********************************************/
  /*!
   * Description:  Scc is not able to store the currently received message for processing.
   * Source:       Configuration
   * Reason:       The number of configured Tcp segments is too small.
   *               May increase Scc/SccGeneral/SccConnectionConfig/SccV2GTPMaxTcpRxSegments.
   *               Scc can not recover from this, reset is needed */
  SccDetailedError_RxIndication_RxQueueTooSmall = 0x03520000,


  /**************************************************************************************************/
  /************************************ Common ******************************************************/
  /**************************************************************************************************/

  /***************************************** Certificates *******************************************/
  /* 900 - 1000 */
  /*!
   * Description:  The ValidityNotAfter information can not be accessed.
   * Source:       External
   * Reason:       The certificate's validity information can not be accessed by using KeyM.
   *                This may happen due to an configuration issue in KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_Priv_CheckCertTimeExpirationValidityNotAfterNotAccessable = 0x03840000,
  /*!
   * Description:  The received message contains a certificate with an invalid common name.
   * Source:       External
   * Reason:       The certificate's common component can not be accessed by using KeyM.
   *                This may happen due to an configuration issue in KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_Common_CPSCheckConfigurationIssue = 0x03BE0000,
  /*!
   * Description:  The received message contains a certificate with an invalid common name.
   * Source:       External
   * Reason:       The certificate's common name is longer than "CPS".
   * Note:         May contain KeyM error. */
  SccDetailedError_Common_CPSCheckTooLong = 0x03BF0000,
  /*!
   * Description:  The received message contains a certificate with an invalid common name.
   * Source:       External
   * Reason:       The certificate's common name does not match "CPS". */
  SccDetailedError_Common_CPSCheckNoMatch = 0x03C00000,
  /*!
   * Description:  The CPS check for a received message can not be executed.
   * Source:       External
   * Reason:       KeyM acces failed and therefore no CPS check can be performed.
   * Note:         May contain KeyM error. */
  SccDetailedError_Common_CPSCheckKeyMAccessFailed = 0x03C10000,

  /***************************************** Exi ****************************************************/
  /*!
   * Description:  The common error code for an issue while interacting with Exi.
   * Source:       External
   * Reason:       Encoding workspace could not be initialized. */
  SccDetailedError_Common_ExiInitEncodingWsExiInitFailed = 0x03E80000,
  /*!
   * Description:  The common error code for an issue while interacting with Exi.
   * Source:       External
   * Reason:       Encoding an Exi stream failed. */
  SccDetailedError_Common_ExiEncodeStreamExiEncodeFailed = 0x03E90000,
  /*!
   * Description:  The common error code for an issue while interacting with Exi.
   * Source:       External
   * Reason:       Finalizing an Exi stream failed. */
  SccDetailedError_Common_ExiEncodeStreamExiFinalizedFailed = 0x03EA0000,
  /*!
   * Description:  The common error code for an issue while interacting with Exi.
   * Source:       External
   * Reason:       Decoding workspace could not be initialized. */
  SccDetailedError_Common_ExiInitDecodingWsExiInitFailed = 0x04060000,
  /*!
   * Description:  The common error code for an issue while interacting with Exi.
   * Source:       External
   * Reason:       Decoding workspace could not be initialized. The application may provided invalid data. */
  SccDetailedError_Common_ExiInitDecodingWsDataExiInitFailed = 0x04070000,


  /***************************************** Key exchange *****************************************/
  /*!
   * Description:  The common error code for an issue while calculating the shared secret by using ECDH.
   * Source:       External
   * Reason:       The Csm key element could not be set to valid. Therefore, no calculation is possible. */
  SccDetailedError_Common_CalcKeyExchangeCsmSetEcdhKeyValid = 0x044C0000,
  /*!
   * Description:  The common error code for an issue while calculating the shared secret by using ECDH.
   * Source:       External
   * Reason:       The Csm job to calculate the shared secret could not be started. */
  SccDetailedError_Common_CalcKeyExchangeCsmStartCalc = 0x044D0000,


  /***************************************** Decrypt private key **********************************/
  /*!
   * Description:  The common error code for an issue while decrypting the encrypted private key.
   * Source:       External
   * Reason:       The intial key derivation function data could not be set by using the Csm. */
  SccDetailedError_Common_DecryptPrivKeyCsmSetKdfData = 0x04B00000,
  /*!
   * Description:  The common error code for an issue while decrypting the encrypted private key.
   * Source:       External
   * Reason:       The first 32 bytes of the shared secret could not be provided for KDF calculation by using the Csm. */
  SccDetailedError_Common_DecryptPrivKeyCsmCopySharedsecretToKdf = 0x04B10000,
  /*!
   * Description:  The common error code for an issue while decrypting the encrypted private key.
   * Source:       External
   * Reason:       The first 32 bytes of the shared secret could not be provided for KDF calculation by using the Csm. */
  SccDetailedError_Common_DecryptPrivKeyCsmSetKdfKeyValid = 0x04B20000,
  /*!
   * Description:  The common error code for an issue while decrypting the encrypted private key.
   * Source:       External
   * Reason:       The hash calculation based on the intial KDF data could not be started by using the Csm. */
  SccDetailedError_Common_DecryptPrivKeyCsmHash = 0x04B30000,
  /*!
   * Description:  The common error code for an issue while decrypting the encrypted private key.
   * Source:       External
   * Reason:       The hash calculation based on the intial KDF data could not be started by using the Csm. */
  SccDetailedError_Common_DecryptPrivKeyCsmSetAesKeyInitialValid = 0x04C40000,
  /*!
   * Description:  The common error code for an issue while decrypting the encrypted private key.
   * Source:       External
   * Reason:       The key material used for encryption could not be extracted by using the Csm. */
  SccDetailedError_Common_DecryptPrivKeyCsmExtractDecryptKeyMaterial = 0x04C50000,
  /*!
   * Description:  The common error code for an issue while decrypting the encrypted private key.
   * Source:       External
   * Reason:       The initialization vector (IV) for decryption could not be set by using the Csm. */
  SccDetailedError_Common_DecryptPrivKeyCsmSetAesIv = 0x04C60000,
  /*!
   * Description:  The common error code for an issue while decrypting the encrypted private key.
   * Source:       External
   * Reason:       The AES key could not be set to valid by using the Csm. */
  SccDetailedError_Common_DecryptPrivKeyCsmSetAesKeyImdValid = 0x04C70000,
  /*!
   * Description:  The common error code for an issue while decrypting the encrypted private key.
   * Source:       External
   * Reason:       The decryption of the encrypted private key could not be started by using the Csm. */
  SccDetailedError_Common_DecryptPrivKeyCsmDecrypt = 0x04C80000,
  /*!
   * Description:  The common error code for an issue while decrypting the encrypted private key.
   * Source:       External
   * Reason:       The decrypted private key element could not be set to valid by using the Csm. */
  SccDetailedError_Common_DecryptPrivKeyCsmSetAesKeyEncryptedValid = 0x04C90000,
  /*!
   * Description:  The common error code for an issue while decrypting the encrypted private key.
   * Source:       External
   * Reason:       The decrypted private key element could not be copied to the signature's key element by using the Csm. */
  SccDetailedError_Common_DecryptPrivKeyCsmCopyKeySignature = 0x04CA0000,
  /*!
   * Description:  The common error code for an issue while decrypting the encrypted private key.
   * Source:       External
   * Reason:       The signature's key element could not be set to valid by using the Csm. */
  SccDetailedError_Common_DecryptPrivKeyCsmSetSignatureKeyValid = 0x04CB0000,


  /***************************************** Message processing preparation ***********************/
  /*!
   * Description:  An error occurred while preparing the message processing.
   * Source:       External
   * Reason:       The Exi decoding of the received data failed. This may be due to invalid payload data. */
  SccDetailedError_Common_DecodeMsgPrepareExiDecodingFailed = 0x05140000,


  /***************************************** Message processing ***********************************/
  /*!
   * Description:  An error occurred while verifying a received contract certificate.
   * Source:       External
   * Reason:       Either the digest is wrong or the reference could not be resolved. The message's signature was created wrong.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Common_VerifySignatureDigestReferenceInvalid = 0x05AB0000,
  /*!
   * Description:  An error occurred while verifying a received contract certificate.
   * Source:       External
   * Reason:       The signature of the message is wrong. The message's signature was created wrong.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Common_VerifySignatureSignatureInvalid = 0x05AC0000,
  /*!
   * Description:  Internal Xml signature reference list is not big enough.
   * Source:       Internal/External
   * Reason:       The message contained too many body elements. */
  SccDetailedError_Common_XmlSignatureBodyRefListTooSmall = 0x05AD0000,



  /**************************************************************************************************/
  /************************************ Supported App Protocol **************************************/
  /**************************************************************************************************/

  /***************************************** Request **********************************************/
  /*!
   * Description:  While preparing the supported app protocol an error occurred.
   * Source:       External
   * Reason:       The SAP schema list modified by the application is invalid.
   *                This may be an application issue. */
  SccDetailedError_Common_SupportedAppProtocolReqUnsupportedForcedSchema = 0x05DC0000,
  /*!
   * Description:  While preparing the supported app protocol an error occurred.
   * Source:       External
   * Reason:       Unable to build the SAP request due to an unsupported schema.
   *                This may be a configuration or application issue. */
  SccDetailedError_Common_SupportedAppProtocolReqUnsupportedSchema = 0x05DD0000,

  /***************************************** Response *********************************************/
  /*!
   * Description:  An error occurred while processing a supported app protocol response of a SECC.
   * Source:       External
   * Reason:       The SECC sent a response with a negative response code. */
  SccDetailedError_Common_SupportedAppProtocolResNegativeResponseCode = 0x060E0000,
  /*!
   * Description:  An error occurred while processing a supported app protocol response of a SECC.
   * Source:       External
   * Reason:       The SECC sent a response with a missing SchemaID element. This element is used
   *                to select one of the supported protocols that the EVCC sent in its request and
   *                is therefore necessary to establish a charging session. */
  SccDetailedError_Common_SupportedAppProtocolResMissingSchemaId = 0x060F0000,
  /*!
   * Description:  An error occurred while processing a supported app protocol response of a SECC.
   * Source:       External
   * Reason:       The SECC sent a response with an unsupported SchemaID. This is caused by the
   *                SECC due to an invalid selection of the EVCC's supported protocols. The EVSE
   *                choose a schema which wasn't offered by the EVCC. */
  SccDetailedError_Common_SupportedAppProtocolResInvalidSchemaSelection = 0x06100000,


  /**************************************************************************************************/
  /*********************************************** DIN **********************************************/
  /**************************************************************************************************/

  /* TRANSMIT PATH */
  /***************************************** Request **********************************************/
  /*!
   * Description:  Invalid message trigger.
   * Source:       External
   * Reason:       The application may set the message trigger to an invalid value. */
  SccDetailedError_Din_EncodeMessageInvalidMsgTrigger = 0x27110000,
  /*!
   * Description:  Unable to create a request message.
   * Source:       External
   * Reason:       Potential problems are
   *                - The configured Tx buffer in Scc is too small
   *                - Unspecified other error which blocks message creation */
  SccDetailedError_Din_EncodeMessageFailed = 0x27120000,

  /***************************************** Charge Parameter Discovery **************************/
  /*!
   * Description:  The request could not be created due to a missing element.
   * Source:       External
   * Reason:       The application did not set the EVMaximumCurrentLimit flag. */
  SccDetailedError_Din_ChargeParameterDiscoveryReqMissingEvmaximumcurrentlimit = 0x27740000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The request could not be created due to a missing element.
   * Source:       External
   * Reason:       The application did not set the EVMaximumVoltageLimit flag. */
  SccDetailedError_Din_ChargeParameterDiscoveryReqMissingEvmaximumvoltagelimit = 0x27750000, /* PRQA S 1711 */ /* MD_SCC_LongNames */


  /* RECEIVE PATH */
  /***************************************** Response *********************************************/
  /*!
   * Description:  A V2G message was received but the payload length is wrong.
   * Source:       External
   * Reason:       The payload length in the received V2GTP header does not match the contained data length.
   */
  SccDetailedError_Din_DecodeMessageInvalidPayloadLen = 0x27D80000,
  /*!
   * Description:  A V2G message was received but session id is wrong.
   * Source:       External
   * Reason:       A SECC sent a message containing a session id that does not match the preceeding
   *                session ids of the communication session. */
  SccDetailedError_Din_CheckSessionIdSessionIdInvalid = 0x27D90000,
  /*!
   * Description:  A V2G message was received but session id is wrong.
   * Source:       External
   * Reason:       A SECC sent a message containing a session id with an length that does not match
   *                the preceeding session ids of the communication session. */
  SccDetailedError_Din_CheckSessionIdSessionIdLenInvalid = 0x27DA0000,


  /***************************************** Session Setup ****************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source:       External
   * Reason:       An unexpected message was sent by the SECC. This indicates an out of sequence error. The SECC
   *                should stick to the specified message sequences. */
  SccDetailedError_Din_SessionSetupResMessageOutOfSequence = 0x283C0000,
  /*!
   * Description:  An unexpected message was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Din_SessionSetupResNegativeResponseCode = 0x283D0000,


  /***************************************** Service Discovery ************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Din_ServiceDiscoveryResMessageOutOfSequence = 0x28A00000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Din_ServiceDiscoveryResNegativeResponseCode = 0x28A10000,
  /*!
   * Description:  The external payment option is missing.
   * Source:       External
   * Reason:       The external payment option is missing in the payment options. The SECC should include this information. */
  SccDetailedError_Din_ServiceDiscoveryResMissingExternalPayment = 0x09620000,


  /***************************************** Service Payment Selection ****************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Din_ServicePaymentSelectionResMessageOutOfSequence = 0x29040000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Din_ServicePaymentSelectionResNegativeResponseCode = 0x29050000,


  /***************************************** Contract Authentication ******************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Din_ContractAuthenticationResMessageOutOfSequence = 0x29680000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Din_ContractAuthenticationResNegativeResponseCode = 0x29690000,


  /***************************************** Charge Parameter Discovery ***************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Din_ChargeParameterDiscoveryResMessageOutOfSequence = 0x29CC0000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Din_ChargeParameterDiscoveryResNegativeResponseCode = 0x29CD0000,
  /*!
   * Description:  The message does not contain the EVSEChargeParameter.
   * Source:       External
   * Reason:       A SECC sent a message with an invalid/missing EVSEChargeParameter. */
  SccDetailedError_Din_ChargeParameterDiscoveryResDcEvsechargeParameterElemIdInvalid = 0x29CE0000,
  /*!
   * Description:  The message does not contain the EVSEChargeParameter.
   * Source:       External
   * Reason:       The message sent by a SECC is missing the EVSEMaximumPowerLimit of EVSEChargeParameter. */
  SccDetailedError_Din_ChargeParameterDiscoveryResMissingEvsemaximumpowerlimitParameter = 0x29CF0000,


  /***************************************** Power Delivery ***************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Din_PowerDeliveryResMessageOutOfSequence = 0x2A300000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something went
   *                wrong at the SECC. */
  SccDetailedError_Din_PowerDeliveryResNegativeResponseCode = 0x2A310000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A SECC sent a message that is missing the DC_EVSEStatus parameter. */
  SccDetailedError_Din_PowerDeliveryResDcEvsestatusElemIdInvalid = 0x2A320000,


  /***************************************** Session Stop *****************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Din_SessionStopResMessageOutOfSequence = 0x2A940000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Din_SessionStopResNegativeResponseCode = 0x2A950000,


  /***************************************** Cable Check ******************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Din_CableCheckResMessageOutOfSequence = 0x2AF80000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Din_CableCheckResNegativeResponseCode = 0x2AF90000,


  /***************************************** Pre-Charge ******************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Din_PrechargeResMessageOutOfSequence = 0x2B5C0000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Din_PrechargeResNegativeResponseCode = 0x2B5D0000,


  /***************************************** Current Demand **************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Din_CurrentDemandResMessageOutOfSequence = 0x2BC00000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Din_CurrentDemandResNegativeResponseCode = 0x2BC10000,


  /***************************************** Welding Detection ***********************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Din_WeldingDetectionResMessageOutOfSequence = 0x2C240000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Din_WeldingDetectionResNegativeResponseCode = 0x2C250000,


  /**************************************************************************************************/
  /****************************************** OppCharge *********************************************/
  /**************************************************************************************************/

  /* TRANSMIT PATH */
  /***************************************** Request **********************************************/
  /*!
   * Description:  Invalid message trigger.
   * Source:       External
   * Reason:       The application may set the message trigger to an invalid value. */
  SccDetailedError_OppCharge_EncodeMessageInvalidMsgTrigger = 0x30000000,
  /*!
   * Description:  Unable to create a request message.
   * Source:       External
   * Reason:       Potential problems are
   *                - The configured Tx buffer in Scc is too small
   *                - Unspecified other error which blocks message creation */
  SccDetailedError_OppCharge_EncodeMessageFailed = 0x30010000,


  /* RECEIVE PATH */
  /***************************************** Response *********************************************/
  /*!
   * Description:  A V2G message was received but the payload length is wrong.
   * Source:       External
   * Reason:       The payload length in the received V2GTP header does not match the
   *               contained data length (Exi stream). */
  SccDetailedError_OppCharge_DecodeMessageInvalidPayloadLen = 0x31000000,
  /*!
   * Description:  A V2G message was received but session id is wrong.
   * Source:       External
   * Reason:       A SECC sent a message even though the session setup failed. */
  SccDetailedError_OppCharge_CheckSessionIdSessionSetupFailed = 0x31010000,


  /***************************************** Session Setup ****************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source:       External
   * Reason:       An unexpected message was sent by the SECC. This indicates an
   *               out of sequence error. The SECC should stick to the
   *               specified message sequences. */
  SccDetailedError_OppCharge_SessionSetupResMessageOutOfSequence = 0x32000000,
  /*!
   * Description:  A message containing a "FAILED" response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *               went wrong at the SECC. */
  SccDetailedError_OppCharge_SessionSetupResNegativeResponseCode = 0x32010000,


  /***************************************** Service Discovery ************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason:       An unexpected message was sent by the SECC. This indicates an
   *               out of sequence error. The SECC should stick to the
   *               specified message sequences. */
  SccDetailedError_OppCharge_ServiceDiscoveryResMessageOutOfSequence = 0x33000000,
  /*!
   * Description:  A message containing a "FAILED" response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *               went wrong at the SECC. */
  SccDetailedError_OppCharge_ServiceDiscoveryResNegativeResponseCode = 0x33010000,
  /*!
   * Description:  External payment option is missing.
   * Source:       External
   * Reason:       The external payment option is missing as the payment option.
   *               The SECC should include this information. */
  SccDetailedError_OppCharge_ServiceDiscoveryResMissingExternalPayment = 0x33020000,
  /*!
   * Description:  Payment option size is unexpected.
   * Source:       External
   * Reason:       The number of PaymentOption elements is not equal to one. */
  SccDetailedError_OppCharge_ServiceDiscoveryResPaymenOptionCountNotOne = 0x33030000,


  /***************************************** Service Payment Selection ****************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason:       An unexpected message was sent by the SECC. This indicates an
   *               out of sequence error. The SECC should stick to the
   *               specified message sequences. */
  SccDetailedError_OppCharge_ServicePaymentSelectionResMessageOutOfSequence = 0x34000000,
  /*!
   * Description:  A message containing a "FAILED" response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *               went wrong at the SECC. */
  SccDetailedError_OppCharge_ServicePaymentSelectionResNegativeResponseCode = 0x34010000,


  /***************************************** Contract Authentication ******************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an
   *               out of sequence error. The SECC should stick to the
   *               specified message sequences. */
  SccDetailedError_OppCharge_ContractAuthenticationResMessageOutOfSequence = 0x35000000,
  /*!
   * Description:  A message containing a "FAILED" response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *               went wrong at the SECC. */
  SccDetailedError_OppCharge_ContractAuthenticationResNegativeResponseCode = 0x35010000,


  /***************************************** Charge Parameter Discovery ***************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an
   *               out of sequence error. The SECC should stick to the
   *               specified message sequences. */
  SccDetailedError_OppCharge_ChargeParameterDiscoveryResMessageOutOfSequence = 0x36000000,
  /*!
   * Description:  A message containing a "FAILED" response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *               went wrong at the SECC. */
  SccDetailedError_OppCharge_ChargeParameterDiscoveryResNegativeResponseCode = 0x36010000,
  /*!
   * Description:  The message does not contain a DC_EVSEChargeParameter element.
   * Source:       External
   * Reason:       A SECC sent a message with an invalid/missing DC_EVSEChargeParameter. */
  SccDetailedError_OppCharge_ChargeParameterDiscoveryResDcEvsechargeParameterElemIdInvalid = 0x36020000,
  /*!
   * Description:  The message does not contain the EVSEChargeParameter.
   * Source:       External
   * Reason:       The message sent by a SECC is missing the EVSEMaximumPowerLimit of EVSEChargeParameter. */
  SccDetailedError_OppCharge_ChargeParameterDiscoveryResMissingEvsemaximumpowerlimitParameter = 0x36030000,


  /***************************************** Power Delivery ***************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an
   *               out of sequence error. The SECC should stick to the
   *               specified message sequences. */
  SccDetailedError_OppCharge_PowerDeliveryResMessageOutOfSequence = 0x37000000,
  /*!
   * Description:  A message containing a "FAILED" response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something went
   *               wrong at the SECC. */
  SccDetailedError_OppCharge_PowerDeliveryResNegativeResponseCode = 0x37010000,
  /*!
   * Description:  The message does not contain a DC_EVSEStatus element.
   * Source:       External
   * Reason:       A SECC sent a message that is missing the DC_EVSEStatus parameter. */
  SccDetailedError_OppCharge_PowerDeliveryResDcEvsestatusElemIdInvalid = 0x37020000,


  /***************************************** Session Stop *****************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an
   *               out of sequence error. The SECC should stick to the
   *               specified message sequences. */
  SccDetailedError_OppCharge_SessionStopResMessageOutOfSequence = 0x38000000,


  /***************************************** Cable Check ******************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an
   *               out of sequence error. The SECC should stick to the
   *               specified message sequences. */
  SccDetailedError_OppCharge_CableCheckResMessageOutOfSequence = 0x39000000,
  /*!
   * Description:  A message containing a "FAILED" response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something went
   *               wrong at the SECC. */
  SccDetailedError_OppCharge_CableCheckResNegativeResponseCode = 0x39010000,


  /***************************************** Pre-Charge ******************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an
   *               out of sequence error. The SECC should stick to the
   *               specified message sequences. */
  SccDetailedError_OppCharge_PrechargeResMessageOutOfSequence = 0x3A000000,
  /*!
   * Description:  A message containing a "FAILED" response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *               went wrong at the SECC. */
  SccDetailedError_OppCharge_PrechargeResNegativeResponseCode = 0x3A010000,


  /***************************************** Current Demand **************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an
   *               out of sequence error. The SECC should stick to the
   *               specified message sequences. */
  SccDetailedError_OppCharge_CurrentDemandResMessageOutOfSequence = 0x3B000000,
  /*!
   * Description:  A message containing a "FAILED" response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *               went wrong at the SECC. */
  SccDetailedError_OppCharge_CurrentDemandResNegativeResponseCode = 0x3B010000,



  /**************************************************************************************************/
  /*********************************************** ISO-2 ********************************************/
  /**************************************************************************************************/

  /* TRANSMIT PATH */
  /***************************************** Request **********************************************/
  /*!
   * Description:  Invalid message trigger.
   * Source:       External
   * Reason:       The application may set the message trigger to an invalid value. */
  SccDetailedError_Iso_EncodeMessageInvalidMsgTrigger = 0x4E200000,
  /*!
   * Description:  Unable to create a request message.
   * Source:       External
   * Reason:       Potential problems are
   *                - The configured Tx buffer in Scc is too small
   *                - Unspecified other error which blocks message creation */
  SccDetailedError_Iso_EncodeMessageFailed = 0x4E300000,

  /***************************************** Charge Parameter Discovery **************************/
  /*!
   * Description:  The request could not be created due to a missing element.
   * Source:       External
   * Reason:       The application did not set the EVMaximumCurrentLimit flag. */
  SccDetailedError_Iso_ChargeParameterDiscoveryReqMissingEvmaximumcurrentlimit = 0x4E840000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The request could not be created due to a missing element.
   * Source:       External
   * Reason:       The application did not set the EVMaximumVoltageLimit flag. */
  SccDetailedError_Iso_ChargeParameterDiscoveryReqMissingEvmaximumvoltagelimit = 0x4E850000, /* PRQA S 1711 */ /* MD_SCC_LongNames */


  /***************************************** Certificate Installation ****************************/
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The initialization of XmlSecurity workspace failed.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_CertificateInstallationReqXmlsecurityInit = 0x4EE80000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The private key of the chosen contract can not be copied in Csm.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertificateInstallationReqCsmContrKeyElemCopyFailed = 0x4EE90000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The private key of the chosen contract was copied in Csm but could not be set to valid.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertificateInstallationReqCsmContrKeySetValidFailed = 0x4EEA0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The reference could not be added to the XmlSecurity workspace.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_CertificateInstallationReqXmlsecurityAddReference = 0x4EEB0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to setup the Xml Security workspace.
   *                Signature method was not accepted. */
  SccDetailedError_Iso_CertificateInstallationReqXmlsecuritySetSignatureMethod = 0x4EEC0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The used Exi stream buffer could not be set in the XmlSecurity workspace. */
  SccDetailedError_Iso_CertificateInstallationReqXmlsecuritySetExistreambuffer = 0x4EED0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Signature generation by using XmlSecurity failed due to an XmlSecurity error.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_CertificateInstallationReqXmlsecuritySignatureGeneration = 0x4EEE0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to extract the root certificates Ids. This may happen if
   *                no root certificates are stored.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertificateInstallationReqExtractRootCertificateIds = 0x4EEF0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to extract the OEM provisioning certificate data from KeyM.
   *                This may happen if no provisioning or an invalid is stored in KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertificateInstallationReqFetchProvisioningCertFailed = 0x4EF00000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to setup the Xml Security workspace.
   *                Digest method was not accepted. */
  SccDetailedError_Iso_CertificateInstallationReqXmlSecuritySetDigestMethod = 0x4EF10000,


  /***************************************** Certificate Update **********************************/
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Certificate update is only possible if a contract is already installed.
   *                But  no valid MO Sub-CA2 certificate can be fetched from KeyM. */
  SccDetailedError_Iso_CertificateUpdateReqMissingMOSubCa2Certificate = 0x4F4D0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       MO Sub-Ca2 certificate can not be read from KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertificateUpdateReqMOSubCa2AccessFailed = 0x4F4E0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       MO Sub-Ca2 certificate status can not be fetched from KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertificateUpdateReqMOSubCa1GetStatusFailed = 0x4F4F0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Certificate update is only possible if a contract is already installed.
   *                But no valid MO Sub-CA1 certificate can be fetched from KeyM. */
  SccDetailedError_Iso_CertificateUpdateReqMOSubCa1Invalid = 0x4F500000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       MO Sub-Ca1 certificate can not be read from KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertificateUpdateReqMOSubCa1AccessFailed = 0x4F510000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Certificate update is only possible if a contract is already installed.
   *                But no valid MO Contract certificate can be fetched from KeyM. */
  SccDetailedError_Iso_CertificateUpdateReqMOContractCertificateInvalid = 0x4F530000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       MO Contract certificate can not be read from KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertificateUpdateReqMOContractAccessFailed = 0x4F540000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The initialization of XmlSecurity failed.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_CertificateUpdateReqXmlsecurityInit = 0x4F560000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The reference could not be added to the XmlSecurity workspace.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_CertificateUpdateReqXmlsecurityAddReference = 0x4F570000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to setup the Xml Security workspace.
   *                Signature method was not accepted. */
  SccDetailedError_Iso_CertificateUpdateReqXmlsecuritySetSignatureMethod = 0x4F580000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The used Exi stream buffer could not be set in the XmlSecurity workspace. */
  SccDetailedError_Iso_CertificateUpdateReqXmlsecuritySetExistreambuffer = 0x4F590000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Signature generation by using XmlSecurity failed due to an XmlSecurity error.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_CertificateUpdateReqXmlsecuritySignatureGeneration = 0x4F5A0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to extract the root certificates Ids. This may happen if
   *                no root certificates is stored.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertificateUpdateReqExtractRootCertificateIds = 0x4F5B0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to extract the EMAID information from the contract certificate.
   *                This may happen due to a configuration issue in KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertificateUpdateReqExtractEMAIDFailed = 0x4F5C0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to copy the private key of the chosen contract chain to
   *                generate a signature. This may happen due to a configuration issue in Csm.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertificateUpdateReqCopyPrivateKeyFailed = 0x4F5D0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to set the copied private key to valid
   *                This may happen due to an issue in Csm. */
  SccDetailedError_Iso_CertificateUpdateReqSetPrivateKeyValidFailed = 0x4F5E0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable create a request as no sub certificates are configured
   *                for the chosen contract chain. These contracts shall not be used
   *                for public certificate update mechanism defined by ISO.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertificateUpdateReqNoMoSubCa2Configured = 0x4F5F0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to setup the Xml Security workspace.
   *                Digest method was not accepted.*/
  SccDetailedError_Iso_CertificateUpdateReqXmlSecuritySetDigestMethod = 0x4F600000,


  /***************************************** Payment Details *************************************/
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to extract the EMAID information from the contract certificate.
   *                This may happen due to a configuration issue in KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_PaymentDetailsReqLoadContractInfoFailed = 0x4FA60000,


  /***************************************** Authorization ***************************************/
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The initialization of XmlSecurity failed.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_AuthorizationReqXmlsecurityInit = 0x4FB00000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The reference could not be added to the XmlSecurity workspace.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_AuthorizationReqXmlsecurityAddReference = 0x4FB10000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to setup the Xml Security workspace.
   *                Signature method was not accepted. */
  SccDetailedError_Iso_AuthorizationReqXmlsecuritySetSignatureMethod = 0x4FB20000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The used Exi stream buffer could not be set in the XmlSecurity workspace. */
  SccDetailedError_Iso_AuthorizationReqXmlsecuritySetExistreambuffer = 0x4FB30000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Signature generation by using XmlSecurity failed due to an XmlSecurity error.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_AuthorizationReqXmlsecuritySignatureGeneration = 0x4FB40000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The contract's private key could not be copied by CSM.
   *                This may happen due to a configuration issue in CSM.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_AuthorizationReqContractCopyPrivateKeyFailed = 0x4FB50000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The contract's private key could not be set to valid by CSM.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_AuthorizationReqContractPrivKeySetValidFailed = 0x4FB60000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to setup the Xml Security workspace.
   *                Digest method was not accepted. */
  SccDetailedError_Iso_AuthorizationReqXmlSecuritySetDigestMethod = 0x4FB70000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to fetch a valid contract certificate from KeyM.
   *                No contract certificate may be available in chosen contract. */
  SccDetailedError_Iso_AuthorizationReqContractNotAvailable = 0x4FB80000,


  /***************************************** Metering Receipt ************************************/
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The initialization of XmlSecurity failed.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_MeteringReceiptReqXmlsecurityInit = 0x50140000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The reference could not be added to the XmlSecurity workspace.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_MeteringReceiptReqXmlsecurityAddReference = 0x50150000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to setup the Xml Security workspace.
   *                Signature method was not accepted. */
  SccDetailedError_Iso_MeteringReceiptReqXmlsecuritySetSignatureMethod = 0x50160000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The used Csm job could not be set in the XmlSecurity workspace. */
  SccDetailedError_Iso_MeteringReceiptReqXmlsecuritySetExistreambuffer = 0x50170000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Signature generation by using XmlSecurity failed due to an XmlSecurity error.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_MeteringReceiptReqXmlsecuritySignatureGeneration = 0x50180000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to setup the Xml Security workspace.
   *                Digest method was not accepted. */
  SccDetailedError_Iso_MeteringReceiptReqXmlsecuritySetDigestMethod = 0x50190000,


  /* RECEIVE PATH */
  /***************************************** Response *********************************************/
  /*!
   * Description:  A V2G message was received but session id is wrong.
   * Source:       External
   * Reason:       A SECC sent a message containing a session id that does not match the preceeding
   *                session ids of the communication session. */
  SccDetailedError_Iso_CheckSessionIdSessionIdInvalid = 0x50790000,
  /*!
   * Description:  A V2G message was received but session id is wrong.
   * Source:       External
   * Reason:       A SECC sent a message containing a session id with an length that does not match
   *                the preceeding session ids of the communication session. */
  SccDetailedError_Iso_CheckSessionIdSessionIdLenInvalid = 0x507A0000,


  /***************************************** Session Setup ****************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_SessionSetupResMessageOutOfSequence = 0x50DC0000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_SessionSetupResNegativeResponseCode = 0x50DD0000,


  /***************************************** Service Discovery ************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_ServiceDiscoveryResMessageOutOfSequence = 0x51400000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_ServiceDiscoveryResNegativeResponseCode = 0x51410000,


  /***************************************** Service Details **************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_ServiceDetailsResMessageOutOfSequence = 0x51A40000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_ServiceDetailsResNegativeResponseCode = 0x51A50000,


  /***************************************** Payment Service Selection ****************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_PaymentServiceSelectionResMessageOutOfSequence = 0x52080000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_PaymentServiceSelectionResNegativeResponseCode = 0x52090000,



  /***************************************** Certificate Installation *****************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_CertficateInstallationResMessageOutOfSequence = 0x526C0000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_CertficateInstallationResNegativeResponseCode = 0x526D0000,
  /*!
   * Description:  A message containing an invalid provisioning certificate chain was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a provisioning chain
   *                with no sub certificates. But at least the Prov Sub-Ca2 certificate
   *                needs to be present. */
  SccDetailedError_Iso_CertficateInstallationResMissingProvSubCa2Cert = 0x526E0000,
  /*!
   * Description:  The received message is not signed.
   * Source:       External
   * Reason:       The message is missing the mandatory signature. SECC sent an invalid message. */
  SccDetailedError_Iso_CertficateInstallationResMissingSignature = 0x526F0000,
  /*!
   * Description:  The received private and public key are no valid key pair.
   * Source:       External
   * Reason:       The received private and public key are no valid key pair. This may happen
   *                due to an invalid received contract, invalid DH public key or Csm
   *                configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstallationResInvalidKeyPair = 0x52700000,
  /*!
   * Description:  The message can not be handled due to invalid configuration of currently used contract.
   * Source:       External
   * Reason:       The received message can not be handled as no MO-SubCA 2 certificate
   *                is configured for the currently selected contract.
   *                Such a contract configuration shall only be used in restrictred and
   *                controlled environments without certificate installation. */
  SccDetailedError_Iso_CertficateInstallationResNoMoSubCa2Configured = 0x52710000,
  /*!
   * Description:  Scc is not able to clear the temporary certificate slot used for
   *               validating the certificate provisioning service certificates in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for CPS-SubCA 1 certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstallationResClearProvSubCa1Failed = 0x52720000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  Scc is not able to clear the temporary certificate slot used for
   *               validating the certificate provisioning service certificates in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for CPS-SubCA 2 certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstallationResClearProvSubCa2Failed = 0x52730000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  Scc is not able to clear the temporary certificate slot used for
   *               validating the certificate provisioning service certificates in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for leaf certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstallationResClearProvLeafFailed = 0x52740000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The key derivation function call failed by Csm.
   * Source:       External
   * Reason:       The key derivation function failed in Csm.
   *                This may be due to a Csm/Crypto issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstallationResKeyDeriveFuncStartFailed = 0x52750000,
  /*!
   * Description:  The encrypted private could not be decrypted.
   * Source:       External
   * Reason:       The encrypted private could not be decrypted.
   *                This may be due to a non matching private/public key pair or a
   *                Csm/Crypto configuration issue. */
  SccDetailedError_Iso_CertficateInstallationResKeyDeriveFuncFailed = 0x52760000,
  /*!
   * Description:  The private key could not be copied from the key derive function for validation.
   * Source:       External
   * Reason:       The private key can not be copied from the key derivation function key element
   *                CRYPTO_KE_KEYDERIVATION_PASSWORD to the validation function input key element
   *                CRYPTO_KE_SIGNATURE_KEY. This may be Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstallationResPrepareKeyValidationPrivateKeyCsmSetFailed = 0x52770000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The Csm input key for the key validation can not be set to valid.
   * Source:       External
   * Reason:       The Csm input key for the key validation function can not be set to valid.
   *                This may be Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstallationResPrepareKeyValidationInputKeySetValidFailed = 0x52780000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The decrypted private key of the key derivation function can not be cleared.
   * Source:       External
   * Reason:       The Csm key element CRYPTO_KE_KEYDERIVATION_PASSWORD of the key derivation
   *                function can not be set to cleared. This may be Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstallationResPrepareKeyValidationClearDecryptedPrivKeyFailed = 0x52790000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The public key of the key derivation function can not be copied.
   * Source:       External
   * Reason:       The Csm key element CRYPTO_KE_CUSTOM_SCC_CONTRACT_PUBLIC_KEY of the key derivation
   *                function can not be copied to validation function key element
   *                CRYPTO_KE_CERTIFICATE_SUBJECT_PUBLIC_KEY.
   *                This may be Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstallationResPrepareKeyValidationCopyPublicKeyFailed = 0x527A0000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The innput key for the key pair validation can not be set to valid.
   * Source:       External
   * Reason:       The Csm input key for the key pair validation can not be set to valid.
   *                This may be Csm/Crypto issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstallationResPrepareKeyValidationSetInputValidFailed = 0x527B0000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The received MO Leaf(contract) certificate's private key can not be stored.
   * Source:       External
   * Reason:       The MO Leaf(contract) certificate's private key can not be stored in Csm.
   *                This may happen due to a Csm configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstallationResMOLeafStorePrivateKeyFailed = 0x527C0000,
  /*!
   * Description:  The decrypted private could not be set in contract private key in Csm.
   * Source:       External
   * Reason:       The decrypted private could not be set to valid in the associated
   *                private key in Csm.
   *                This may be due to a Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstallationResKeyDecryptedPrivKeySetValidFailed = 0x527D0000,
  /*!
   * Description:  The decrypted private could not be overwritten in Csm.
   * Source:       External
   * Reason:       The decrypted private could not be overwritten in Csm.
   *                This may be due to a Csm/Crypto issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstallationResKeyDeriveFuncOverwriteDecryptedPrivKeyFailed = 0x527E0000,
  /*!
   * Description:  The private key could not be overwritten in Csm.
   * Source:       External
   * Reason:       The decrypted private key could not be overwritten in Csm.
   *                This may be due to a Csm/Crypto issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstallationResClearTmpPrivKeyClearValidationPrivKeyFailed = 0x527F0000,
  /*!
   * Description:  The received message does not contain a Id attribute which is required for
   *                xml signature processing.
   * Source:       External
   * Reason:       EVSE send an invalid message. */
  SccDetailedError_Iso_CertficateInstallationResContractSignatureCertChainWithoutIdAttribute = 0x52800000,
  /*!
   * Description:  The message can not be handled due to invalid configuration of currently used contract.
   * Source:       External
   * Reason:       The received message can not be handled as no contract certificate
   *                is configured for the currently selected contract.
   *                Such a contract configuration shall not be used. */
  SccDetailedError_Iso_CertficateInstallationResNoMContractConfigured = 0x52810000,
  /*!
   * Description:  Scc is not able to clear the temporary certificate slot used for
   *               validating the certificate provisioning service certificates in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for CPS-SubCA 1 certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstallationResClearProvSubCa1Failed2 = 0x52820000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  Scc is not able to clear the temporary certificate slot used for
   *               validating the certificate provisioning service certificates in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for CPS-SubCA 2 certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstallationResClearProvSubCa2Failed2 = 0x52830000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  Scc is not able to clear the temporary certificate slot used for
   *               validating the certificate provisioning service certificates in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for leaf certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstallationResClearProvLeafFailed2 = 0x52840000, /* PRQA S 1711 */ /* MD_SCC_LongNames */


  /***************************************** Certificate Update ***********************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_CertificateUpdateResMessageOutOfSequence = 0x529E0000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_CertificateUpdateResNegativeResponseCode = 0x529F0000,
  /*!
   * Description:  A message containing an invalid provisioning certificate chain was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a provisioning chain
   *                with no sub certificates. But at least the Prov Sub-Ca2 certificate
   *                needs to be present. */
  SccDetailedError_Iso_CertficateUpdateResMissingProvSubCa2Cert = 0x52A00000,
  /*!
   * Description:  The received message is not signed.
   * Source:       External
   * Reason:       The message is missing the mandatory signature. SECC sent an invalid message. */
  SccDetailedError_Iso_CertficateUpdateResMissingSignature = 0x52A10000,
  /*!
   * Description:  The received private and public key are no valid key pair.
   * Source:       External
   * Reason:       The received private and public key are no valid key pair. This may happen
   *                due to an invalid received contract, invalid DH public key or Csm
   *                configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateUpdateResInvalidKeyPair = 0x52A20000,
  /*!
   * Description:  The message can not be handled due to invalid configuration of currently used contract.
   * Source:       External
   * Reason:       The received message can not be handled as no MO-SubCA 2 certificate
   *                is configured for the currently selected contract.
   *                Such a contract configuration shall only be used in restrictred and
   *                controlled environments without certificate update. */
  SccDetailedError_Iso_CertficateUpdateResNoMoSubCa2Configured = 0x52A30000,
  /*!
   * Description:  Scc is not able to clear the temporary certificate slot used for
   *               validating the certificate provisioning service certificates in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for CPS-SubCA 1 certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateUpdateResClearProvSubCa1Failed = 0x52A40000,
  /*!
   * Description:  Scc is not able to clear the temporary certificate slot used for
   *               validating the certificate provisioning service certificates in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for CPS-SubCA 2 certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateUpdateResClearProvSubCa2Failed = 0x52A50000,
  /*!
   * Description:  Scc is not able to clear the temporary certificate slot used for
   *               validating the certificate provisioning service certificates in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for leaf certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateUpdateResClearProvLeafFailed = 0x52A60000,
  /*!
   * Description:  The key derivation function call failed by Csm.
   * Source:       External
   * Reason:       The key derivation function failed in Csm.
   *                This may be due to a Csm/Crypto issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateUpdateResKeyDeriveFuncStartFailed = 0x52A70000,
  /*!
   * Description:  The encrypted private could not be decrypted.
   * Source:       External
   * Reason:       The encrypted private could not be decrypted.
   *                This may be due to a non matching private/public key pair or a
   *                Csm/Crypto configuration issue. */
  SccDetailedError_Iso_CertficateUpdateResKeyDeriveFuncFailed = 0x52A80000,
  /*!
   * Description:  The private key could not be copied from the key derive function for validation.
   * Source:       External
   * Reason:       The private key can not be copied from the key derivation function key element
   *                CRYPTO_KE_KEYDERIVATION_PASSWORD to the validation function input key element
   *                CRYPTO_KE_SIGNATURE_KEY. This may be Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateUpdateResPrepareKeyValidationPrivateKeyCsmSetFailed = 0x52A90000,
  /*!
   * Description:  The Csm input key for the key validation can not be set to valid.
   * Source:       External
   * Reason:       The Csm input key for the key validation function can not be set to valid.
   *                This may be Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateUpdateResPrepareKeyValidationInputKeySetValidFailed = 0x52AA0000,
  /*!
   * Description:  The decrypted private key of the key derivation function can not be cleared.
   * Source:       External
   * Reason:       The Csm key element CRYPTO_KE_KEYDERIVATION_PASSWORD of the key derivation
   *                function can not be set to cleared. This may be Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateUpdateResPrepareKeyValidationClearDecryptedPrivKeyFailed = 0x52AB0000,
  /*!
   * Description:  The public key of the key derivation function can not be copied.
   * Source:       External
   * Reason:       The Csm key element CRYPTO_KE_CUSTOM_SCC_CONTRACT_PUBLIC_KEY of the key derivation
   *                function can not be copied to validation function key element
   *                CRYPTO_KE_CERTIFICATE_SUBJECT_PUBLIC_KEY.
   *                This may be Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateUpdateResPrepareKeyValidationCopyPublicKeyFailed = 0x52AC0000,
  /*!
   * Description:  The innput key for the key pair validation can not be set to valid.
   * Source:       External
   * Reason:       The Csm input key for the key pair validation can not be set to valid.
   *                This may be Csm/Crypto issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateUpdateResPrepareKeyValidationSetInputValidFailed = 0x52AD0000,
  /*!
   * Description:  The received MO Leaf(contract) certificate's private key can not be stored.
   * Source:       External
   * Reason:       The MO Leaf(contract) certificate's private key can not be stored in Csm.
   *                This may happen due to a Csm configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateUpdateResMOLeafStorePrivateKeyFailed = 0x52AE0000,
  /*!
   * Description:  The decrypted private could not be set in contract private key in Csm.
   * Source:       External
   * Reason:       The decrypted private could not be set to valid in the associated
   *                private key in Csm.
   *                This may be due to a Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateUpdateResKeyDecryptedPrivKeySetValidFailed = 0x52AF0000,
  /*!
   * Description:  The decrypted private could not be overwritten in Csm.
   * Source:       External
   * Reason:       The decrypted private could not be overwritten in Csm.
   *                This may be due to a Csm/Crypto issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateUpdateResKeyDeriveFuncOverwriteDecryptedPrivKeyFailed = 0x52B00000,
  /*!
   * Description:  The private key could not be overwritten in Csm.
   * Source:       External
   * Reason:       The decrypted private key could not be overwritten in Csm.
   *                This may be due to a Csm/Crypto issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateUpdateResClearTmpPrivKeyClearValidationPrivKeyFailed = 0x52B10000,
  /*!
   * Description:  The received message does not contain a Id attribute which is required for
   *                xml signature processing.
   * Source:       External
   * Reason:       EVSE send an invalid message. */
  SccDetailedError_Iso_CertficateUpdateResContractSignatureCertChainWithoutIdAttribute = 0x52B20000,
  /*!
   * Description:  The message can not be handled due to invalid configuration of currently used contract.
   * Source:       External
   * Reason:       The received message can not be handled as no contract certificate
   *                is configured for the currently selected contract.
   *                Such a contract configuration shall not be used. */
  SccDetailedError_Iso_CertficateUpdateResNoContractConfigured = 0x52B30000,
  /*!
   * Description:  Scc is not able to clear the temporary certificate slot used for
   *               validating the certificate provisioning service certificates in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for CPS-SubCA 1 certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateUpdateResClearProvSubCa1Failed2 = 0x52B40000,
  /*!
   * Description:  Scc is not able to clear the temporary certificate slot used for
   *               validating the certificate provisioning service certificates in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for CPS-SubCA 2 certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateUpdateResClearProvSubCa2Failed2 = 0x52B50000,
  /*!
   * Description:  Scc is not able to clear the temporary certificate slot used for
   *               validating the certificate provisioning service certificates in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for leaf certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateUpdateResClearProvLeafFailed2 = 0x52B60000,


  /******************************** Certificate Installation/Update *******************************/
  /*!
   * Description:  The encrypted private key has a invalid length.
   * Source:       External
   * Reason:       The encrypted private key length of the received certificate is invalid. */
  SccDetailedError_Iso_CertficateInstUpdtResPrivateKeyLenInvalid = 0x56B80000,
  /*!
   * Description:  DH public key has invalid length.
   * Source:       External
   * Reason:       The received DH public key was set to a wrong length by an EVSE. */
  SccDetailedError_Iso_CertficateInstUpdtResDHPublicKeyLenInvalid = 0x56B90000,
  /*!
   * Description:  A message containing an invalid contract certificate chain was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a contract certificate
   *                with no sub certificates. But at least the MO Sub-Ca2 certificate
   *                needs to be present as it is used for sales tarif signing. */
  SccDetailedError_Iso_CertficateInstUpdtResMissingMOSubCa2Cert = 0x56BA0000,
  /*!
   * Description:  EMAID has invalid length.
   * Source:       External
   * Reason:       The received EMAID included in the message and not in the certificate
   *               is set to a wrong length by an EVSE. */
  SccDetailedError_Iso_CertficateInstUpdtResEMAIDLenInvalid = 0x56BB0000,
  /*!
   * Description:  The public key has an invalid length.
   * Source:       External
   * Reason:       The received public key has an invalid length - too big. A SECC sent an invalid message.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstUpdtResProvLeafPublicKeyLenInvalidTooBig = 0x56BC0000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The public key could not be accessed.
   * Source:       External
   * Reason:       The public key element can not be accessed by using KeyM to prepare XML signature.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstUpdtResProvLeafPublicKeyAccessFailed = 0x56BD0000,
  /*!
   * Description:  The public key has an invalid length.
   * Source:       External
   * Reason:       The received public key has an invalid length - too short. A SECC sent an invalid message. */
  SccDetailedError_Iso_CertficateInstUpdtResProvLeafPublicKeyLenInvalidTooShort = 0x56BE0000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The public key has an invalid length.
   * Source:       External
   * Reason:       The received public key has an invalid length. A SECC sent an invalid message. */
  SccDetailedError_Iso_CertficateInstUpdtResProvLeafPublicKeyLenUnusedBitsInvalid = 0x56BF0000,
  /*!
   * Description:  The signature pointer could not be set.
   * Source:       External
   * Reason:       An error occurred while setting up the signature pointer by using XmlSecurity. */
  SccDetailedError_Iso_CertficateInstUpdtResXmlSecuritySetSignaturePtr = 0x56C00000,
  /*!
   * Description:  The public key has an invalid length.
   * Source:       External
   * Reason:       The received public key has an invalid length - too short. A SECC sent an invalid message.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_CertficateInstUpdtResMOLeafPublicKeyLenInvalidTooShort = 0x56C10000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The public key could not be accessed.
   * Source:       External
   * Reason:       The public key element can not be accessed by using KeyM to prepare key derive function.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstUpdtResMOLeafPublicKeyAccessFailed = 0x56C20000,
  /*!
   * Description:  The public key has an invalid length.
   * Source:       External
   * Reason:       The received public key has an invalid length - too big. A SECC sent an invalid message.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstUpdtResMOLeafPublicKeyLenInvalidTooBig = 0x56C30000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The public key has an invalid length.
   * Source:       External
   * Reason:       The received public key has an invalid length. A SECC sent an invalid message. */
  SccDetailedError_Iso_CertficateInstUpdtResMOLeafPublicKeyLenUnusedBitsInvalid = 0x56C40000,
  /*!
   * Description:  The MO leaf public key has an invalid format.
   * Source:       External
   * Reason:       The received public key uses not a compressed format. A SECC sent an invalid message. */
  SccDetailedError_Iso_CertficateInstUpdtResMOLeafPublicKeyFormatInvalid = 0x56C50000,
  /*!
   * Description:  The MO leaf public key can not be set in CSM key element.
   * Source:       External
   * Reason:       The received public key can not be set in key element
   *                CRYPTO_KE_CUSTOM_SCC_CONTRACT_PUBLIC_KEY. This may be a Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstUpdtResMOLeafPublicKeyCsmSetFailed = 0x56C60000,
  /*!
   * Description:  The OEM provisioning's private key can not be set in CSM key element.
   * Source:       External
   * Reason:       The private key can not be copied from the oem provisioning key element
   *                CRYPTO_KE_SIGNATURE_KEY to the key derive function input key element
   *                CRYPTO_KE_KEYDERIVATION_PASSWORD. This may be Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstUpdtResKeyDerivationFunctionProvPrivateKeyCsmSetFailed = 0x56C70000,
  /*!
   * Description:  The received encrypted private key can not be set in CSM key element.
   * Source:       External
   * Reason:       The encrypted private key can not be set to the key derive function input key element
   *                CRYPTO_KE_CUSTOM_SCC_IV_AND_ENCRYPTED_PRIVATE_KEY. This may be Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstUpdtResEncryptedPrivKeyCsmSetFailed = 0x56C80000,
  /*!
   * Description:  The received DH public key can not be set in CSM key element.
   * Source:       External
   * Reason:       The received DH public key can not be set to the key derive function input key element
   *                CRYPTO_KE_CUSTOM_KEYEXCHANGE_PARTNER_PUB_KEY. This may be Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstUpdtResDHPublicKeyCsmSetFailed = 0x56C90000,
  /*!
   * Description:  The Csm input key for the key derive function can not be set to valid.
   * Source:       External
   * Reason:       The Csm input key for the key derive function can not be set to valid.
   *                This may be Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstUpdtResKeyDeriveFuncInputKeySetValidFailed = 0x56CA0000,
  /*!
   * Description:  The received contract is rejected by application.
   * Source:       External
   * Reason:       The received contract is not installed as it is rejected by application. */
  SccDetailedError_Iso_CertficateInstUpdtResContractRejected = 0x56CF0000,
  /*!
   * Description:  The received Prov Sub-Ca1 certificate is invalid.
   * Source:       External
   * Reason:       The Prov Sub-Ca1 certificate can not be verified by a stored V2G root certificate.
   *                This may happen due to no matching root certificate, KeyM configuration issue
   *                or a format error of the received certificate. */
  SccDetailedError_Iso_CertficateInstUpdtResProvSubCa1Invalid = 0x56D60000,
  /*!
   * Description:  The received Prov Sub-Ca1 certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The Prov Sub-Ca1 certificate can not be written to KeyM. This may happen
   *                due KeyM configuration issue or a format error of the received certificate.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstUpdtResProvSubCa1KeyMAccessFailed = 0x56D70000,
  /*!
   * Description:  The received Prov Sub-Ca1 certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The Prov Sub-Ca1 certificate can not be verified by KeyM. This may happen
   *                due KeyM configuration issue or a format error of the received certificate.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstUpdtResProvSubCa1KeyMStartVerifyFailed = 0x56D80000,
  /*!
   * Description:  The received Prov Sub-Ca2 certificate is invalid.
   * Source:       External
   * Reason:       The Prov Sub_Ca2 certificate can not be verified by the received Prov Sub-Ca1 certificate.
   *                This may happen due to no matching chain of trust, KeyM configuration issue
   *                or a format error of the received certificate. */
  SccDetailedError_Iso_CertficateInstUpdResProvSubCa2Invalid = 0x56D90000,
  /*!
   * Description:  The received Prov Sub-Ca2 certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The Prov Sub-Ca2 certificate can not be written to KeyM. This may happen
   *                due KeyM configuration issue or a format error of the received certificate.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstUpdtResProvSubCa2KeyMAccessFailed = 0x56DA0000,
  /*!
   * Description:  The received Prov Sub-Ca2 certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The Prov Sub-Ca2 certificate verification can not be started by KeyM. This may happen
   *                due KeyM configuration issue or a format error of the received certificate.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstUpdtResProvSubCa2KeyMStartVerifyFailed = 0x56DB0000,
  /*!
   * Description:  The received Prov Leaf(provisioning) certificate is invalid.
   * Source:       External
   * Reason:       The Prov Leaf(provisioning) certificate can not be verified up to a stored V2G root certificate.
   *                This may happen due to no matching chain of trust, KeyM configuration issue
   *                or a format error of the received certificate. */
  SccDetailedError_Iso_CertficateInstUpdtResProvLeafInvalid = 0x56DC0000,
  /*!
   * Description:  The received Prov Leaf(provisioning) certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The Prov Leaf(provisioning) certificate can not be written to KeyM. This may happen
   *                due KeyM configuration issue or a format error of the received certificate.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstUpdtResProvLeafKeyMAccessFailed = 0x56DD0000,
  /*!
   * Description:  The received Prov Leaf(provisioning) certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The Prov Leaf(provisioning) certificate verification can not be started by KeyM.
   *                This may happen due KeyM configuration issue or a format error of the
   *                received certificate.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstUpdtResProvLeafKeyStartVerifyFailed = 0x56DE0000,
  /*!
   * Description:  The received certificate provisioing chain is invalid.
   * Source:       External
   * Reason:       The following reasons may cause this issue:
   *                  - The received chain contains two sub certificates but the sub2 cert is
   *                      issued by a root certificate instead of sub1. */
  SccDetailedError_Iso_CertficateInstUpdtResProvChainInvalid = 0x56DF0000,
  /*!
   * Description:  The issuer of the received Prov Sub-Ca2 certificate can not be fetched from KeyM.
   * Source:       External
   * Reason:       KeyM rejects the call to KeyM_GetIssuerCertId.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstUpdtResProvSubCa2CheckIssuerFailed = 0x56E00000,
  /*!
   * Description:  The received MO Sub-Ca1 certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The MO Sub-Ca1 certificate can not be written to KeyM. This may happen
   *                due KeyM configuration issue or a format error of the received certificate. */
  SccDetailedError_Iso_CertficateInstUpdtResMOSubCa1KeyMAccessFailed = 0x56E10000,
  /*!
   * Description:  The received MO Sub-Ca1 certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The MO Sub-Ca1 certificate verification can not be started by KeyM. This may happen
   *                due KeyM configuration issue or a format error of the received certificate. */
  SccDetailedError_Iso_CertficateInstUpdtResMOSubCa1KeyMStartVerifyFailed = 0x56E20000,
  /*!
   * Description:  The received MO Sub-C12 certificate is invalid.
   * Source:       External
   * Reason:       The MO Sub-Ca1 certificate can not be verified by the received Sub-Ca1 certificate
   *                if the chain contains this certificate. Additionaly this may happen due to
   *                KeyM configuration issue or a format error of the received certificate. */
  SccDetailedError_Iso_CertficateInstUpdtResMOSubCa1Invalid = 0x56E30000,
  /*!
   * Description:  The received MO Sub-Ca2 certificate is invalid.
   * Source:       External
   * Reason:       The MO Sub-Ca2 certificate can not be verified by the received Sub-Ca1 certificate
   *                if the chain contains this certificate. Additionaly this may happen due to
   *                KeyM configuration issue or a format error of the received certificate. */
  SccDetailedError_Iso_CertficateInstUpdtResMOSubCa2Invalid = 0x56E40000,
  /*!
   * Description:  The received MO Sub-Ca2 certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The MO Sub-Ca2 certificate can not be written to KeyM. This may happen
   *                due KeyM configuration issue or a format error of the received certificate. */
  SccDetailedError_Iso_CertficateInstUpdtResMOSubCa2KeyMAccessFailed = 0x56E50000,
  /*!
   * Description:  The received MO Sub-Ca2 certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The MO Sub-Ca2 certificate verification can not be started by KeyM. This may happen
   *                due KeyM configuration issue or a format error of the received certificate. */
  SccDetailedError_Iso_CertficateInstUpdtResMOSubCa2KeyMStartVerifyFailed = 0x56E60000,
  /*!
   * Description:  The received MO Leaf(contract) certificate is invalid.
   * Source:       External
   * Reason:       The MO Leaf(contract) certificate can not be verified by the Sub-Ca2 certificate.
   *                This may happen due to no matching chain of trust, KeyM configuration issue
   *                or a format error of the received certificate. */
  SccDetailedError_Iso_CertficateInstUpdtResMOLeafInvalid = 0x56E70000,
  /*!
   * Description:  The received MO Leaf(contract) certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The MO Leaf(contract) certificate can not be written to KeyM. This may happen
   *                due KeyM configuration issue or a format error of the received certificate.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstUpdtResMOLeafKeyMAccessFailed = 0x56E80000,
  /*!
   * Description:  The received MO Leaf(contract) certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The MO Leaf(contract) certificate verification can not be started by KeyM.
   *                This may happen due KeyM configuration issue or a format error of the
   *                received certificate.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstUpdtResMOLeafKeyMStartVerifyFailed = 0x56E90000,
  /*!
   * Description:  The received contract certificate can not be handled due to unmatching configuration.
   * Source:       External
   * Reason:       The received contract consists of 2 sub certificates but the currently
   *                selected contract has no MO-SubCA 1 certificate configured. */
  SccDetailedError_Iso_CertficateInstUpdtResNoMoSubCa1Configured = 0x56F00000,
  /*!
   * Description:  The received contract certificate can not be handled due to unmatching configuration.
   * Source:       External
   * Reason:       The received contract consists of 2 sub certificates but the currently
   *                selected contract has no MO-SubCA 2 certificate configured. */
  SccDetailedError_Iso_CertficateInstUpdtResNoMoSubCa2Configured = 0x56F10000,
  /*!
   * Description:  The currently selected private key could not be cleared in Csm.
   * Source:       External
   * Reason:       Csm rejected the write request for the private key by Scc.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstUpdtResClearPrivKeyCsmFailed = 0x56F20000,
  /*!
   * Description:  The currently selected contract chain could not be cleared in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for MO-SubCA 1 certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstUpdtResClearMoSubCa1Failed = 0x56F30000,
  /*!
   * Description:  The currently selected contract chain could not be cleared in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for MO-SubCA 2 certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstUpdtResClearMoSubCa2Failed = 0x56F40000,
  /*!
   * Description:  The currently selected contract chain could not be cleared in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for leaf certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstUpdtResClearMoLeafFailed = 0x56F50000,
  /*!
   * Description:  The private key could not be overwritten in Csm.
   * Source:       External
   * Reason:       The contract private could not be overwritten in Csm.
   *                This may be due to a Csm/Crypto issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstUpdtResClearContractPrivKeyFailed = 0x56F60000,
  /*!
   * Description:  The currently selected contract chain could not be cleared in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for MO-SubCA 1 certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstUpdtResHelperClearMoSubCa1Failed = 0x56F70000,
  /*!
   * Description:  The currently selected contract chain could not be cleared in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for MO-SubCA 2 certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstUpdtResHelperClearMoSubCa2Failed = 0x56F80000,
  /*!
   * Description:  The currently selected contract chain could not be cleared in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for leaf certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_CertficateInstUpdtResHelperClearMoLeafFailed = 0x56F90000,
  /*!
   * Description:  The decrypted private could not be overwritten in Csm.
   * Source:       External
   * Reason:       The decrypted private could not be overwritten in Csm.
   *                This may be due to a Csm/Crypto issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstUpdtResHelperKeyDeriveFuncOverwriteDecryptedPrivKeyFailed = 0x56FA0000,
  /*!
   * Description:  The private key could not be overwritten in Csm.
   * Source:       External
   * Reason:       The decrypted private key could not be overwritten in Csm.
   *                This may be due to a Csm/Crypto issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstUpdtResHelperClearTmpPrivKeyClearValidationPrivKeyFailed = 0x56FB0000,
  /*!
   * Description:  The public key used to verify the Xml signature could not be copied to
   *                Xml signature verify Csm job.
   * Source:       External
   * Reason:       Most probably it is an issue in Csm config of the key elements and the access rights.
   *               Make sure that both key elements have a matching configuration.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_CertficateInstUpdtResHelperCopyPublicKeyFailed = 0x56FC0000,
  /*!
   * Description:  The current configuration does not match the received CPS chain.
   * Source:       External
   * Reason:       The received CPS chain has more certificates than configured in KeyM. */
  SccDetailedError_Iso_CertficateInstUpdtResHelperInvalidCPSChainSubCa1Config= 0x56FD0000,
  /*!
   * Description:  The DH public key has an invalid compression format.
   * Source:       External
   * Reason:       The received DH public key has an invalid compression format. A SECC sent an invalid message. */
  SccDetailedError_Iso_CertficateInstUpdtResDHPublicKeyCompressionInvalid = 0x56FE0000,

  /***************************************** Payment Details **************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_PaymentDetailsResMessageOutOfSequence = 0x53340000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_PaymentDetailsResNegativeResponseCode = 0x53350000,


  /***************************************** Authorization ****************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_AuthorizationResMessageOutOfSequence = 0x53980000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_AuthorizationResNegativeResponseCode = 0x53990000,


  /***************************************** Charge Parameter Discovery ***************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_ChargeParameterDiscoveryResMessageOutOfSequence = 0x53FC0000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_ChargeParameterDiscoveryResNegativeResponseCode = 0x53FD0000,
  /*!
   * Description:  The received message is missing a SAScheduleList.
   * Source:       External
   * Reason:       A message was sent by the SECC with no SASchedule. At least one schedule is
   *                needed. */
  SccDetailedError_Iso_ChargeParameterDiscoveryResMissingSaschedulelist = 0x53FE0000,
  /*!
   * Description:  The received message's signature could not be verified.
   * Source:       Internal
   * Reason:       The contract sub cert1 is missing. Therefore, the signature could not be
   *                verified. */
  SccDetailedError_Iso_ChargeParameterDiscoveryResMissingContrsubcert1 = 0x53FF0000,
  /*!
   * Description:  The received message conatins an invalid EVSEChargeParameter element.
   * Source:       Internal
   * Reason:       The EVSEChargeParameter is not of AC type. SECC sent unexpected element. */
  SccDetailedError_Iso_ChargeParameterDiscoveryResAcEvsechargeparameterElemIdInvalid = 0x54010000,
  /*!
   * Description:  The received message conatins an invalid EVSEChargeParameter element.
   * Source:       Internal
   * Reason:       The EVSEChargeParameter is not of DC type. SECC sent unexpected element. */
  SccDetailedError_Iso_ChargeParameterDiscoveryResDcEvsechargeparameterElemIdInvalid = 0x54020000,
  /*!
   * Description:  The received message can not be handled.
   * Source:       External
   * Reason:       No MO Sub-Ca2 certificate is configured for the currently selected contract.
   *               Either enable skipping of sales tariff checks or update configuration and use
   *               a MO Sub-Ca2 certificate. */
  SccDetailedError_Iso_ChargeParameterDiscoveryResNoMoSubCa2 = 0x54040000,
  /*!
   * Description:  The public key used to verify the Xml signature could not be copied to
   *                Xml signature verify Csm job.
   * Source:       External
   * Reason:       Most probably it is an issue in Csm config of the key elements and the access rights.
   *               Make sure that both key elements have a matching configuration.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_ChargeParameterDiscoveryResCopyMOSubCa2PublicKeyFailed = 0x54050000,


  /***************************************** Power Delivery ***************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_PowerDeliveryResMessageOutOfSequence = 0x54600000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_PowerDeliveryResNegativeResponseCode = 0x54610000,
  /*!
   * Description:  The received message conatins an invalid EVSEStatus element.
   * Source:       Internal
   * Reason:       The EVSEStatus is not of type AC_EVSEStatus. SECC sent unexpected element. */
  SccDetailedError_Iso_PowerDeliveryResAcEvsestatusElemIdInvalid = 0x54620000,
  /*!
   * Description:  The received message conatins an invalid EVSEStatus element.
   * Source:       Internal
   * Reason:       The EVSEStatus is not of tpye DC_EVSEStatus. SECC sent unexpected element. */
  SccDetailedError_Iso_PowerDeliveryResDcEvsestatusElemIdInvalid = 0x54630000,


  /***************************************** Metering Receipt *************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_MeteringReceiptResMessageOutOfSequence = 0x54C40000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_MeteringReceiptResNegativeResponseCode = 0x54C50000,
  /*!
   * Description:  The received message conatins an invalid EVSEStatus element.
   * Source:       Internal
   * Reason:       The EVSEStatus is not of type AC_EVSEStatus. SECC sent unexpected element. */
  SccDetailedError_Iso_MeteringReceiptResAcEvsestatusElemIdInvalid = 0x54C60000,
  /*!
   * Description:  The received message conatins an invalid EVSEStatus element.
   * Source:       Internal
   * Reason:       The EVSEStatus is not of type DC_EVSEStatus. SECC sent unexpected element. */
  SccDetailedError_Iso_MeteringReceiptResDcEvsestatusElemIdInvalid = 0x54C70000,


  /***************************************** Session Stop *****************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_SessionStopResMessageOutOfSequence = 0x55280000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_SessionStopResNegativeResponseCode = 0x55290000,


  /***************************************** Charging Status **************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_ChargingStatusResMessageOutOfSequence = 0x558C0000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_ChargingStatusResNegativeResponseCode = 0x558D0000,
  /*!
   * Description:  The response contains an invalid SAScheduleTupleId.
   * Source:       External
   * Reason:       The Id differs from the one sent in the PowerDelivery request. */
  SccDetailedError_Iso_ChargingStatusResUnexpectedSascheduletupleid = 0x558E0000,
  /*!
   * Description:  The response contains no meter info.
   * Source:       External
   * Reason:       A receipt is required by the application but the SECC
   *                does not provide a meter info elment. */
  SccDetailedError_Iso_ChargingStatusResMissingMeterinfoElement = 0x558F0000,


  /***************************************** Cable Check ******************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_CableCheckResMessageOutOfSequence = 0x55F00000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_CableCheckResNegativeResponseCode = 0x55F10000,


  /***************************************** Pre Charge *******************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_PreChargeResMessageOutOfSequence = 0x56540000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_PreChargeResNegativeResponseCode = 0x56550000,


  /***************************************** Current Demand ***************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_CurrentDemandResMessageOutOfSequence = 0x57000000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_CurrentDemandResNegativeResponseCode = 0x57010000,
  /*!
   * Description:  The response contains an invalid SAScheduleTupleId.
   * Source:       External
   * Reason:       The Id differs from the one sent in the PowerDelivery request. */
  SccDetailedError_Iso_CurrentDemandResUnexpectedSascheduletupleid = 0x57020000,
  /*!
   * Description:  The response contains no meter info.
   * Source:       External
   * Reason:       A receipt is required by the application but the SECC
   *                does not provide a meter info elment. */
  SccDetailedError_Iso_CurrentDemandResMissingMeterinfoElement = 0x57030000,


  /***************************************** Welding Detection ************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_WeldingDetectionResMessageOutOfSequence = 0x571C0000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_WeldingDetectionResNegativeResponseCode = 0x571D0000,



  /**************************************************************************************************/
  /*********************************************** ISO-20 *******************************************/
  /**************************************************************************************************/
  /* TRANSMIT PATH */
  /***************************************** Request *****************************/
  /*!
   * Description:  Invalid message trigger.
   * Source:       External
   * Reason:       The application may set the message trigger to an invalid value. */
  SccDetailedError_Iso_20_EncodeMessageInvalidMsgTrigger = 0x75300000,
  /*!
   * Description:  Invalid message trigger.
   * Source:       External
   * Reason:       The application may set the message trigger to an invalid value. */
  SccDetailedError_Iso_20_EncodeCMMessageInvalidMsgTrigger = 0x75310000,
  /*!
   * Description:  Invalid message trigger.
   * Source:       External
   * Reason:       The application may set the message trigger to an invalid value. */
  SccDetailedError_Iso_20_EncodeACMessageInvalidMsgTrigger = 0x75320000,
  /*!
   * Description:  Invalid message trigger.
   * Source:       External
   * Reason:       The application may set the message trigger to an invalid value. */
  SccDetailedError_Iso_20_EncodeDCMessageInvalidMsgTrigger = 0x75330000,
  /*!
   * Description:  Invalid message trigger.
   * Source:       External
   * Reason:       The application may set the message trigger to an invalid value. */
  SccDetailedError_Iso_20_EncodeWPTMessageInvalidMsgTrigger = 0x75340000,
  /*!
   * Description:  Unable to create a request message.
   * Source:       External
   * Reason:       Potential problems are
   *                - The configured Tx buffer in Scc is too small
   *                - Unspecified other error which blocks message creation */
  SccDetailedError_Iso_20_EncodeMessageFailed = 0x75350000,

  /*!
   * Description:  The currently selected private key could not be cleared in Csm.
   * Source:       External
   * Reason:       Csm rejected the write request for the private key by Scc.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_GenerateSignatureClearPrivKeyCsmFailed = 0x75315000,


  /***************************************** Certificate Installation *****************************/
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The initialization of XmlSecurity failed.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_20_CertificateInstallationReqXmlsecurityInit = 0x75940000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The reference could not be added to the XmlSecurity workspace.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_20_CertificateInstallationReqXmlsecurityAddReference = 0x75950000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The used Csm job could not be set in the XmlSecurity workspace. */
  SccDetailedError_Iso_20_CertificateInstallationReqXmlsecuritySetExistreambuffer = 0x75960000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Signature generation by using XmlSecurity failed due to an XmlSecurity error.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_20_CertificateInstallationReqXmlsecuritySignatureGeneration = 0x75970000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to extract the OEM provisioning certificate data from KeyM.
   *                This may happen if no provisioning or an invalid is stored in KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertificateInstallationReqFetchProvisioningCertFailed = 0x75980000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to extract the root certificates Ids. This may happen if
   *                no root certificates are stored.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertificateInstallationReqExtractRootCertificateIds = 0x75990000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to setup the Xml Security workspace.
   *                Digest method was not accepted.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_20_CertificateInstallationReqXmlSecuritySetDigestMethod = 0x759A0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to setup the Xml Security workspace.
   *                Signature method was not accepted.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_20_CertificateInstallationReqXmlsecuritySetSignatureMethod = 0x759B0000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The Leaf(OEM Provisioning) certificate can not be read by KeyM.
   * Source:       External
   * Reason:       The Leaf(OEM Provisioning) certificate status can not be fetched from KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_GetAvailableOemProvCertLeafKeyMAccessFailed = 0x759C0000,
  /*!
   * Description:  The SubCa1(OEM Provisioning) certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The SubCa1(OEM Provisioning) certificate status can not be fetched from KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_GetAvailableOemProvCertSubCa1KeyMAccessFailed = 0x759D0000,
  /*!
   * Description:  The SubCa2(OEM Provisioning) certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The SubCa2(OEM Provisioning) certificate status can not be fetched from KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_GetAvailableOemProvCertSubCa2KeyMAccessFailed = 0x759E0000,
  /*!
   * Description:  The XmlSecurity setup workspace could not be handled.
   * Source:       External
   * Reason:       An unsupported curve was used, therefore Scc is not able to setup XmlSecurity.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_20_CertificateInstallationReqSetupXmlSecWs = 0x759F0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to extract the OEM provisioning certificate SubCa1 data from KeyM.
   *                This may happen if no provisioning or an invalid is stored in KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertificateInstallationReqFetchProvisioningCertSubCa1Failed = 0x75A00000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to extract the OEM provisioning certificate SubCa2 data from KeyM.
   *                This may happen if no provisioning or an invalid is stored in KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertificateInstallationReqFetchProvisioningCertSubCa2Failed = 0x75A10000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The private key of the chosen contract can not be copied in Csm.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertificateInstallationReqCsmContrKeyElemCopyFailed = 0x75A20000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The private key of the chosen contract was copied in Csm but could not be set to valid.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertificateInstallationReqCsmContrKeySetValidFailed = 0x75A30000,
  /*!
    * Description:  The request could not be created.
    * Source:       External
    * Reason:       The OEM provisioning certificate chain uses a elliptic curve which is rejected by application. */
  SccDetailedError_Iso_20_CertificateInstallationReqOEMProvCertChainEllipticCurveRejected = 0x75A40000,


  /***************************************** Authorization  *****************************/
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The initialization of XmlSecurity failed. */
  SccDetailedError_Iso_20_AuthorizationReqXmlsecurityInit = 0x75F80000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The reference could not be added to the XmlSecurity workspace.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_20_AuthorizationReqXmlsecurityAddReference = 0x75F90000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The reference could not be added to the XmlSecurity workspace. */
  SccDetailedError_Iso_20_AuthorizationReqXmlsecuritySetCsmjobid = 0x75FA0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The used Csm job could not be set in the XmlSecurity workspace. */
  SccDetailedError_Iso_20_AuthorizationReqXmlsecuritySetExistreambuffer = 0x75FB0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Signature generation by using XmlSecurity failed due to an XmlSecurity error.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_20_AuthorizationReqXmlsecuritySignatureGeneration = 0x75FC0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to read the contract certificate.
   *                This may happen due to a configuration issue in KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_AuthorizationReqLoadContractInfoFailed = 0x75FD0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to setup the Xml Security workspace.
   *                Digest method was not accepted.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_20_AuthorizationReqXmlSecuritySetDigestMethod = 0x75FF0000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to setup the Xml Security workspace.
   *                Signature method was not accepted.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_20_AuthorizationReqXmlsecuritySetSignatureMethod = 0x76000000,
  /*!
   * Description:  The XmlSecurity setup workspace could not be handled.
   * Source:       External
   * Reason:       An unsupported curve was used, therefore Scc is not able to setup XmlSecurity.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_20_AuthorizationReqSetupXmlSecWs = 0x76020000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The private key of the coosen contract can not be copied in Csm.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_AuthorizationReqCsmContrKeyElemCopyFailed = 0x76030000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The private key of the chosen contract was copied in Csm but could not be set to valid.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_AuthorizationReqCsmContrKeySetValidFailed = 0x76040000,
  /*!
    * Description:  The request could not be created.
    * Source:       External
    * Reason:       The contract certificate chain uses a elliptic curve which is rejected by application. */
  SccDetailedError_Iso_20_AuthorizationReqContractCertChainEllipticCurveRejected = 0x76050000,


  /***************************************** Charge Parameter Discovery ***************************/
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The selected energy transfer mode is not supported. */
  SccDetailedError_Iso_20_ChargeParameterDiscoveryReqUnsupportedEnergytransfermode = 0x765C0000,


  /***************************************** Metering Receipt *************************************/
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The initialization of XmlSecurity failed. */
  SccDetailedError_Iso_20_MeteringReceiptReqXmlsecurityInit = 0x76C00000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The reference could not be added to the XmlSecurity workspace. */
  SccDetailedError_Iso_20_MeteringReceiptReqXmlsecurityAddReference = 0x76C10000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The reference could not be added to the XmlSecurity workspace. */
  SccDetailedError_Iso_20_MeteringReceiptReqXmlsecuritySetCsmjobid = 0x76C20000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The used Csm job could not be set in the XmlSecurity workspace. */
  SccDetailedError_Iso_20_MeteringReceiptReqXmlsecuritySetExistreambuffer = 0x76C30000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Signature generation by using XmlSecurity failed due to an XmlSecurity error. */
  SccDetailedError_Iso_20_MeteringReceiptReqXmlsecuritySignatureGeneration = 0x76C40000,


  /* RECEIVE PATH */
  /***************************************** Response *********************************************/
  /*!
   * Description:  A V2G message was received but session id is wrong.
   * Source:       External
   * Reason:       A SECC sent a message containing a session id that does not match the preceeding
   *                session ids of the communication session. */
  SccDetailedError_Iso_20_CheckSessionIdSessionIdInvalid = 0x77250000,
  /*!
   * Description:  A V2G message was received but session id is wrong.
   * Source:       External
   * Reason:       A SECC sent a message containing a session id with an length that does not match
   *                the preceeding session ids of the communication session. */
  SccDetailedError_Iso_20_CheckSessionIdSessionIdLenInvalid = 0x77260000,
  /*!
   * Description:  A V2G message was received but the payload type is wrong.
   * Source:       External
   * Reason:       The payload type in the received V2GTP header is invalid. */
  SccDetailedError_Iso_20_DecodeMessageInvalidPayloadType = 0x77270000,
  /*!
   * Description:  A V2G message was received but the payload type is wrong.
   * Source:       External
   * Reason:       The payload type in the received V2GTP header is invalid. */
  SccDetailedError_Iso_20_DecodeMessageInvalidPayloadTypeMeteringReceipt = 0x77280000,
  /*!
   * Description:  A V2G message was received but the payload type is wrong.
   * Source:       External
   * Reason:       The payload type in the received V2GTP header is invalid. */
  SccDetailedError_Iso_20_DecodeMessageInvalidPayloadTypeChargeParam = 0x77290000,
  /*!
   * Description:  A V2G message was received but the payload type is wrong.
   * Source:       External
   * Reason:       The payload type in the received V2GTP header is invalid. */
  SccDetailedError_Iso_20_DecodeMessageInvalidPayloadTypePowerDelivery = 0x772A0000,
  /*!
   * Description:  A V2G message was received but the payload type is wrong.
   * Source:       External
   * Reason:       The payload type in the received V2GTP header is invalid. */
  SccDetailedError_Iso_20_DecodeMessagePrepareInvalidPayloadType = 0x772B0000,
  /*!
   * Description:  A V2G message was received but the payload type is wrong.
   * Source:       External
   * Reason:       The payload type in the received V2GTP header is invalid. */
  SccDetailedError_Iso_20_DecodeMessagePrepareInvalidPayloadTypeMeteringReceipt = 0x772C0000,
  /*!
   * Description:  A V2G message was received but the payload type is wrong.
   * Source:       External
   * Reason:       The payload type in the received V2GTP header is invalid. */
  SccDetailedError_Iso_20_DecodeMessagePrepareInvalidPayloadTypePowerDelivery = 0x772D0000,
  /*!
   * Description:  A V2G message was received but the payload type is wrong.
   * Source:       External
   * Reason:       The payload type in the received V2GTP header is invalid. */
  SccDetailedError_Iso_20_DecodeMessagePrepareInvalidPayloadTypeChargeParam = 0x772E0000,
  /*!
   * Description:  A V2G message was received but the payload type is wrong.
   * Source : External
   * Reason : The payload type in the received V2GTP header is invalid. */
  SccDetailedError_Iso_20_DecodeMessagePrepareInvalidPayloadTypeSystemStatus = 0x772F0000,


  /***************************************** Session Setup ****************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_SessionSetupResMessageOutOfSequence = 0x77880000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_SessionSetupResNegativeResponseCode = 0x77890000,
  /*!
   * Description:  Unable to read key element.
   * Source:       External
   * Reason:       Unable to read key element from Csm. This issue may happen due to a configuration issue in Csm.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_SessionSetupResResumeSessionReadFailed = 0x778A0000,
  /*!
   * Description:  Unable to read key element.
   * Source:       External
   * Reason:       Unable to read key element from Csm. This issue may happen due to a configuration issue in Csm.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_SessionSetupReqResumeSessionReadFailed = 0x778B0000,


  /***************************************** Service Discovery ************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_ServiceDiscoveryResMessageOutOfSequence = 0x77EC0000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_ServiceDiscoveryResNegativeResponseCode = 0x77ED0000,


  /***************************************** Service Details **************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_ServiceDetailsResMessageOutOfSequence = 0x78500000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_ServiceDetailsResNegativeResponseCode = 0x78510000,


  /***************************************** Service Selection ************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_ServiceSelectionResMessageOutOfSequence = 0x78B40000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_ServiceSelectionResNegativeResponseCode = 0x78B50000,
  /*!
   * Description:  Invalid user input was provided
   * Source:       External
   * Reason:       The chosen energy transfer service can not be used in combination with
   *                active schema. Application provided invalid input. */
  SccDetailedError_Iso_20_ServiceSelectionReqInvalidEnergyTransferService = 0x78E60000,

  /***************************************** Certificate Installation *****************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_CertficateInstallationResMessageOutOfSequence = 0x79180000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_CertficateInstallationResNegativeResponseCode = 0x79190000,
  /*!
   * Description:  The received message contains a certificate with an invalid domain component.
   * Source:       External
   * Reason:       The certificate's domain component should contain "CPS". A SECC sent an
   *                 invalid certificate. */
  SccDetailedError_Iso_20_CertficateInstallationResDomainComponentInvalid = 0x791A0000,
  /*!
   * Description:  The received message contains an invalid public private key combination.
   * Source:       External
   * Reason:       The certificate's public key does not match the private key contained in the
   *                 message. SECC sent an invalid message. */
  SccDetailedError_Iso_20_CertficateInstallationResMismatchPrivatePublicKey = 0x791B0000,
  /*!
   * Description:  The received message is not signed.
   * Source:       External
   * Reason:       The message is missing the mandatory signature. SECC sent an invalid message. */
  SccDetailedError_Iso_20_CertficateInstallationResMissingSignature = 0x791C0000,
  /*!
   * Description:  The received certificate is missing the EMAID.
   * Source:       External
   * Reason:       The received certificate is missing the EMAID in the subject common name. */
  SccDetailedError_Iso_20_CertficateInstallationResMissingEmaid = 0x791D0000,
  /*!
   * Description:  No matching root certificate available to verify the received provisioning certificate chain.
   * Source:       External
   * Reason:       The received provisioning certificate chain could not be verified due to no matching
   *                root certificate. The provisioning certificate chain does not traces back to a root
   *                certificate known to the EVCC. This may happen if the SECC does not
   *                consider the list of known root certificates sent by the EVCC in the request. */
  SccDetailedError_Iso_20_CertficateInstallationResVerifyProvChainNoMatchingRootCert = 0x791E0000,
  /*!
   * Description:  Preparation of the decryption of the encrypted private key failed.
   * Source:       External
   * Reason:       While propagating the provisioning key to the Csm an error occurred. */
  SccDetailedError_Iso_20_CertficateInstallationResSetupContractCertCsmCopyEncryptedPrivateKey = 0x791F0000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  Preparation of the decryption of the encrypted private key failed.
   * Source:       External
   * Reason:       While propagating the provisioning key to the Csm an error occurred. */
  SccDetailedError_Iso_20_CertficateInstallationResSetupContractCertPrivateKeyLenInvalid = 0x79200000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The public key could not be stored.
   * Source:       External
   * Reason:       The public key element is missing in the received certificate.
   *                A SECC sent an invalid message. */
  SccDetailedError_Iso_20_CertficateInstallationResStorePublicKeyMissingPublicKey = 0x79210000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The received message's signature could not be verified.
   * Source:       Internal
   * Reason:       The contract certificate has an invalid public key length. Therefore, the
   *                signature could not be verified. */
  SccDetailedError_Iso_20_CertficateInstallationResStorePublicKeyPublicKeyLenInvalid = 0x79220000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The public key could not be stored.
   * Source:       External
   * Reason:       An error occurred while setting up the signature pointer by using XmlSecurity. */
  SccDetailedError_Iso_20_CertficateInstallationResStorePublicKeyXmlsecuritySetSignaturePtr = 0x79230000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The message can not be handled due to invalid configuration of currently used contract.
   * Source:       External
   * Reason:       The received message can not be handled as no MO-SubCA 2 certificate
   *                is configured for the currently selected contract.
   *                Such a contract configuration shall only be used in restrictred and
   *                controlled environments without certificate installation. */
  SccDetailedError_Iso_20_CertficateInstallationResNoMoSubCa2Configured                     = 0x79240000,
  /*!
   * Description:  A message containing an invalid provisioning certificate chain was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a provisioning chain
   *                with no sub certificates. But at least the Prov Sub-Ca2 certificate
   *                needs to be present. */
  SccDetailedError_Iso_20_CertficateInstallationResMissingProvSubCa2Cert                    = 0x79250000,
  /*!
   * Description:  Scc is not able to clear the temporary certificate slot used for
   *               validating the certificate provisioning service certificates in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for CPS-SubCA 1 certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResClearProvSubCa1Failed                    = 0x79260000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  Scc is not able to clear the temporary certificate slot used for
   *               validating the certificate provisioning service certificates in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for CPS-SubCA 2 certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResClearProvSubCa2Failed                    = 0x79270000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  Scc is not able to clear the temporary certificate slot used for
   *               validating the certificate provisioning service certificates in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for leaf certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResClearProvLeafFailed                      = 0x79280000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The received contract is rejected by application.
   * Source:       External
   * Reason:       The received contract is not installed as it is rejected by application. */
  SccDetailedError_Iso_20_CertficateInstallationResContractRejected                         = 0x79290000,
  /*!
   * Description:  The currently selected contract chain could not be cleared in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for MO-SubCA 1 certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResClearMoSubCa1Failed                      = 0x792A0000,
  /*!
   * Description:  The currently selected contract chain could not be cleared in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for MO-SubCA 2 certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResClearMoSubCa2Failed                      = 0x792B0000,
  /*!
   * Description:  The currently selected contract chain could not be cleared in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for leaf certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResClearMoLeafFailed                        = 0x792C0000,
  /*!
   * Description:  The public key has an invalid length.
   * Source : External
   * Reason : The received public key has an invalid length - too big.A SECC sent an invalid message.
   * Note : May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResMOLeafPublicKeyLenInvalidTooBig                 = 0x792D0000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The public key could not be accessed.
   * Source:       External
   * Reason:       The public key element can not be accessed by using KeyM to prepare key derive function.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResMOLeafPublicKeyAccessFailed                     = 0x792E0000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The public key has an invalid length.
   * Source:       External
   * Reason:       The received public key has an invalid length - too short. A SECC sent an invalid message. */
  SccDetailedError_Iso_20_CertficateInstallationResMOLeafPublicKeyLenInvalidTooShort               = 0x792F0000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The public key has an invalid length.
   * Source:       External
   * Reason:       The received public key has an invalid length. A SECC sent an invalid message. */
  SccDetailedError_Iso_20_CertficateInstallationResMOLeafPublicKeyLenUnusedBitsInvalid             = 0x79300000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The MO leaf public key has an invalid format.
   * Source:       External
   * Reason:       The received public key uses not a compressed format. A SECC sent an invalid message. */
  SccDetailedError_Iso_20_CertficateInstallationResMOLeafPublicKeyFormatInvalid                    = 0x79310000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The MO leaf public key can not be set in CSM key element.
   * Source:       External
   * Reason:       The received public key can not be set in key element
   *                CRYPTO_KE_CUSTOM_SCC_CONTRACT_PUBLIC_KEY. This may be a Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResMOLeafPublicKeyCsmSetFailed                     = 0x79320000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The OEM provisioning's private key can not be set in CSM key element.
   * Source:       External
   * Reason:       The private key can not be copied from the oem provisioning key element
   *                CRYPTO_KE_SIGNATURE_KEY to the key derive function input key element
   *                CRYPTO_KE_KEYDERIVATION_PASSWORD. This may be Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResKeyDerivationFunctionProvPrivateKeyCsmSetFailed = 0x79330000,
  /*!
   * Description:  The received encrypted private key can not be set in CSM key element.
   * Source:       External
   * Reason:       The encrypted private key can not be set to the key derive function input key element
   *                CRYPTO_KE_CUSTOM_SCC_IV_AND_ENCRYPTED_PRIVATE_KEY. This may be Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResEncryptedPrivKeyCsmSetFailed                    = 0x79340000,
  /*!
   * Description:  The received DH public key can not be set in CSM key element.
   * Source:       External
   * Reason:       The received DH public key can not be set to the key derive function input key element
   *                CRYPTO_KE_CUSTOM_KEYEXCHANGE_PARTNER_PUB_KEY. This may be Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResDHPublicKeyCsmSetFailed                         = 0x79350000,
  /*!
   * Description:  The Csm input key for the key derive function can not be set to valid.
   * Source:       External
   * Reason:       The Csm input key for the key derive function can not be set to valid.
   *                This may be Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResKeyDeriveFuncInputKeySetValidFailed             = 0x79360000,
  /*!
   * Description:  The key derivation function call failed by Csm.
   * Source:       External
   * Reason:       The key derivation function failed in Csm.
   *                This may be due to a Csm/Crypto issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResKeyDeriveFuncStartFailed                        = 0x79370000,
  /*!
   * Description:  The encrypted private could not be decrypted.
   * Source:       External
   * Reason:       The encrypted private could not be decrypted.
   *                This may be due to a non matching private/public key pair or a
   *                Csm/Crypto configuration issue. */
  SccDetailedError_Iso_20_CertficateInstallationResKeyDeriveFuncFailed                             = 0x79380000,
  /*!
   * Description:  The private key could not be copied from the key derive function for validation.
   * Source:       External
   * Reason:       The private key can not be copied from the key derivation function key element
   *                CRYPTO_KE_KEYDERIVATION_PASSWORD to the validation function input key element
   *                CRYPTO_KE_SIGNATURE_KEY. This may be Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResPrepareKeyValidationPrivateKeyCsmSetFailed      = 0x79390000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The Csm input key for the key validation can not be set to valid.
   * Source:       External
   * Reason:       The Csm input key for the key validation function can not be set to valid.
   *                This may be Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResPrepareKeyValidationInputKeySetValidFailed      = 0x793A0000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The decrypted private key of the key derivation function can not be cleared.
   * Source:       External
   * Reason:       The Csm key element CRYPTO_KE_KEYDERIVATION_PASSWORD of the key derivation
   *                function can not be set to cleared. This may be Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResPrepareKeyValidationClearDecryptedPrivKeyFailed = 0x793B0000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The public key of the key derivation function can not be copied.
   * Source:       External
   * Reason:       The Csm key element CRYPTO_KE_CUSTOM_SCC_CONTRACT_PUBLIC_KEY of the key derivation
   *                function can not be copied to validation function key element
   *                CRYPTO_KE_CERTIFICATE_SUBJECT_PUBLIC_KEY.
   *                This may be Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResPrepareKeyValidationCopyPublicKeyFailed         = 0x793C0000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The innput key for the key pair validation can not be set to valid.
   * Source:       External
   * Reason:       The Csm input key for the key pair validation can not be set to valid.
   *                This may be Csm/Crypto issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResPrepareKeyValidationSetInputValidFailed         = 0x793D0000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The received MO Leaf(contract) certificate's private key can not be stored.
   * Source:       External
   * Reason:       The MO Leaf(contract) certificate's private key can not be stored in Csm.
   *                This may happen due to a Csm configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResMOLeafStorePrivateKeyFailed                     = 0x793E0000,
  /*!
   * Description:  The decrypted private could not be set in contract private key in Csm.
   * Source:       External
   * Reason:       The decrypted private could not be set to valid in the associated
   *                private key in Csm.
   *                This may be due to a Csm/Crypto configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResKeyDecryptedPrivKeySetValidFailed               = 0x793F0000,
  /*!
   * Description:  The decrypted private could not be overwritten in Csm.
   * Source:       External
   * Reason:       The decrypted private could not be overwritten in Csm.
   *                This may be due to a Csm/Crypto issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResKeyDeriveFuncOverwriteDecryptedPrivKeyFailed    = 0x79400000,
  /*!
   * Description:  The private key could not be overwritten in Csm.
   * Source:       External
   * Reason:       The decrypted private key could not be overwritten in Csm.
   *                This may be due to a Csm/Crypto issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResClearTmpPrivKeyClearValidationPrivKeyFailed     = 0x79410000,
  /*!
   * Description:  The private key could not be overwritten in Csm.
   * Source:       External
   * Reason:       The contract private could not be overwritten in Csm.
   *                This may be due to a Csm/Crypto issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResClearContractPrivKeyFailed                      = 0x79420000,
  /*!
   * Description:  The received Prov Sub-Ca1 certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The Prov Sub-Ca1 certificate can not be written to KeyM. This may happen
   *                due KeyM configuration issue or a format error of the received certificate.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResProvSubCa1KeyMAccessFailed                      = 0x79430000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The received Prov Sub-Ca1 certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The Prov Sub-Ca1 certificate can not be verified by KeyM. This may happen
   *                due KeyM configuration issue or a format error of the received certificate.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResProvSubCa1KeyMStartVerifyFailed                 = 0x79440000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The received Prov Sub-Ca1 certificate is invalid.
   * Source:       External
   * Reason:       The Prov Sub-Ca1 certificate can not be verified by a stored V2G root certificate.
   *                This may happen due to no matching root certificate, KeyM configuration issue
   *                or a format error of the received certificate. */
  SccDetailedError_Iso_20_CertficateInstallationResProvSubCa1Invalid                               = 0x79460000,
  /*!
   * Description:  The received Prov Sub-Ca2 certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The Prov Sub-Ca2 certificate can not be written to KeyM. This may happen
   *                due KeyM configuration issue or a format error of the received certificate.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResProvSubCa2KeyMAccessFailed = 0x79470000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The received Prov Sub-Ca2 certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The Prov Sub-Ca2 certificate verification can not be started by KeyM. This may happen
   *                due KeyM configuration issue or a format error of the received certificate.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResProvSubCa2KeyMStartVerifyFailed = 0x79480000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The received Prov Sub-Ca2 certificate is invalid.
   * Source:       External
   * Reason:       The Prov Sub_Ca2 certificate can not be verified by the received Prov Sub-Ca1 certificate.
   *                This may happen due to no matching chain of trust, KeyM configuration issue
   *                or a format error of the received certificate. */
  SccDetailedError_Iso_20_CertficateInstallationResProvSubCa2Invalid = 0x794A0000,
  /*!
   * Description:  The issuer of the received Prov Sub-Ca2 certificate can not be fetched from KeyM.
   * Source:       External
   * Reason:       KeyM rejects the call to KeyM_GetIssuerCertId.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResProvSubCa2CheckIssuerFailed = 0x794B0000,
  /*!
   * Description:  The received certificate provisioing chain is invalid.
   * Source:       External
   * Reason:       The following reasons may cause this issue:
   *                  - The received chain contains two sub certificates but the sub2 cert is
   *                      issued by a root certificate instead of sub1. */
  SccDetailedError_Iso_20_CertficateInstallationResProvChainInvalid = 0x794C0000,
  /*!
   * Description:  The received Prov Leaf(provisioning) certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The Prov Leaf(provisioning) certificate can not be written to KeyM. This may happen
   *                due KeyM configuration issue or a format error of the received certificate.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResProvLeafKeyMAccessFailed = 0x794D0000,
  /*!
   * Description:  The received Prov Leaf(provisioning) certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The Prov Leaf(provisioning) certificate verification can not be started by KeyM.
   *                This may happen due KeyM configuration issue or a format error of the
   *                received certificate.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResProvLeafKeyStartVerifyFailed = 0x794E0000,
  /*!
   * Description:  The received private and public key are no valid key pair.
   * Source:       External
   * Reason:       The received private and public key are no valid key pair. This may happen
   *                due to an invalid received contract, invalid DH public key or Csm
   *                configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResInvalidKeyPair = 0x794F0000,
  /*!
   * Description:  The received Prov Leaf(provisioning) certificate is invalid.
   * Source:       External
   * Reason:       The Prov Leaf(provisioning) certificate can not be verified up to a stored V2G root certificate.
   *                This may happen due to no matching chain of trust, KeyM configuration issue
   *                or a format error of the received certificate. */
  SccDetailedError_Iso_20_CertficateInstallationResProvLeafInvalid = 0x79510000,
  /*!
   * Description:  The public key has an invalid length.
   * Source:       External
   * Reason:       The received public key has an invalid length - too big. A SECC sent an invalid message.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResProvLeafPublicKeyLenInvalidTooBig = 0x79520000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The public key could not be accessed.
   * Source:       External
   * Reason:       The public key element can not be accessed by using KeyM to prepare XML signature.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResProvLeafPublicKeyAccessFailed = 0x79530000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The public key has an invalid length.
   * Source:       External
   * Reason:       The received public key has an invalid length - too short. A SECC sent an invalid message. */
  SccDetailedError_Iso_20_CertficateInstallationResProvLeafPublicKeyLenInvalidTooShort = 0x79540000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The signature pointer could not be set.
   * Source:       External
   * Reason:       An error occurred while setting up the signature pointer by using XmlSecurity. */
  SccDetailedError_Iso_20_CertficateInstallationResXmlSecuritySetSignaturePtr = 0x79550000,
  /*!
   * Description:  The encrypted private key has a invalid length.
   * Source:       External
   * Reason:       The encrypted private key length of the received certificate is invalid. */
  SccDetailedError_Iso_20_CertficateInstallationResPrivateKeyLenInvalid = 0x79560000,
  /*!
   * Description:  DH public key has invalid length.
   * Source:       External
   * Reason:       The received DH public key was set to a wrong length by an EVSE. */
  SccDetailedError_Iso_20_CertficateInstallationResDHPublicKeyLenInvalid = 0x79570000,
  /*!
   * Description:  The received contract certificate can not be handled due to unmatching configuration.
   * Source:       External
   * Reason:       The received contract consists of 2 sub certificates but the currently
   *                selected contract has no MO-SubCA 1 certificate configured. */
  SccDetailedError_Iso_20_CertficateInstallationResNoMoSubCa1Configured = 0x79580000,
  /*!
   * Description:  The received MO Sub-Ca1 certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The MO Sub-Ca1 certificate can not be written to KeyM. This may happen
   *                due KeyM configuration issue or a format error of the received certificate. */
  SccDetailedError_Iso_20_CertficateInstallationResMOSubCa1KeyMAccessFailed = 0x79590000,
  /*!
   * Description:  The received MO Sub-Ca1 certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The MO Sub-Ca1 certificate verification can not be started by KeyM. This may happen
   *                due KeyM configuration issue or a format error of the received certificate. */
  SccDetailedError_Iso_20_CertficateInstallationResMOSubCa1KeyMStartVerifyFailed = 0x795A0000,
  /*!
   * Description:  The public key has an invalid length.
   * Source:       External
   * Reason:       The received public key has an invalid length. A SECC sent an invalid message. */
  SccDetailedError_Iso_20_CertficateInstallationResProvLeafPublicKeyLenUnusedBitsInvalid = 0x795B0000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The received MO Sub-C12 certificate is invalid.
   * Source:       External
   * Reason:       The MO Sub-Ca1 certificate can not be verified by the received Sub-Ca1 certificate
   *                if the chain contains this certificate. Additionaly this may happen due to
   *                KeyM configuration issue or a format error of the received certificate. */
  SccDetailedError_Iso_20_CertficateInstallationResMOSubCa1Invalid = 0x795D0000,
  /*!
   * Description:  The received MO Sub-Ca2 certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The MO Sub-Ca2 certificate can not be written to KeyM. This may happen
   *                due KeyM configuration issue or a format error of the received certificate. */
  SccDetailedError_Iso_20_CertficateInstallationResMOSubCa2KeyMAccessFailed = 0x795E0000,
  /*!
   * Description:  The received MO Sub-Ca2 certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The MO Sub-Ca2 certificate verification can not be started by KeyM. This may happen
   *                due KeyM configuration issue or a format error of the received certificate. */
  SccDetailedError_Iso_20_CertficateInstallationResMOSubCa2KeyMStartVerifyFailed = 0x795F0000,
  /*!
   * Description:  The received MO Sub-Ca2 certificate is invalid.
   * Source:       External
   * Reason:       The MO Sub-Ca2 certificate can not be verified by the received Sub-Ca1 certificate
   *                if the chain contains this certificate. Additionaly this may happen due to
   *                KeyM configuration issue or a format error of the received certificate. */
  SccDetailedError_Iso_20_CertficateInstallationResMOSubCa2Invalid = 0x79610000,
  /*!
   * Description:  The received MO Leaf(contract) certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The MO Leaf(contract) certificate can not be written to KeyM. This may happen
   *                due KeyM configuration issue or a format error of the received certificate.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResMOLeafKeyMAccessFailed = 0x79620000,
  /*!
   * Description:  The received MO Leaf(contract) certificate can not be handled by KeyM.
   * Source:       External
   * Reason:       The MO Leaf(contract) certificate verification can not be started by KeyM.
   *                This may happen due KeyM configuration issue or a format error of the
   *                received certificate.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResMOLeafKeyMStartVerifyFailed = 0x79630000,
  /*!
   * Description:  The DH public key has an invalid compression format.
   * Source:       External
   * Reason:       The received DH public key has an invalid compression format. A SECC sent an invalid message. */
  SccDetailedError_Iso_20_CertficateInstallationResDHPublicKeyCompressionInvalid = 0x79640000,
  /*!
   * Description:  The received MO Leaf(contract) certificate is invalid.
   * Source:       External
   * Reason:       The MO Leaf(contract) certificate can not be verified by the Sub-Ca2 certificate.
   *                This may happen due to no matching chain of trust, KeyM configuration issue
   *                or a format error of the received certificate. */
  SccDetailedError_Iso_20_CertficateInstallationResMOLeafInvalid = 0x79650000,
  /*!
   * Description:  The message can not be handled due to invalid configuration of currently used contract.
   * Source:       External
   * Reason:       The received message can not be handled as no MO-SubCA 2 certificate
   *                is configured for the currently selected contract.
   *                Such a contract configuration shall only be used in restrictred and
   *                controlled environments without certificate installation. */
  SccDetailedError_Iso_20_CertficateInstallationResHelperNoMoSubCa2Configured = 0x79660000,
  /*!
   * Description:  The currently selected private key could not be cleared in Csm.
   * Source:       External
   * Reason:       Csm rejected the write request for the private key by Scc.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstUpdtResClearPrivKeyCsmFailed = 0x79670000,
  /*!
   * Description:  The currently selected contract chain could not be cleared in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for MO-SubCA 1 certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResHelperClearMoSubCa1Failed = 0x79680000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The currently selected contract chain could not be cleared in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for MO-SubCA 2 certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResHelperClearMoSubCa2Failed = 0x79690000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The currently selected contract chain could not be cleared in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for leaf certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResHelperClearMoLeafFailed = 0x796A0000,
  /*!
   * Description:  The decrypted private could not be overwritten in Csm.
   * Source:       External
   * Reason:       The decrypted private could not be overwritten in Csm.
   *                This may be due to a Csm/Crypto issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResHelperKeyDeriveFuncOverwriteDecryptedPrivKeyFailed = 0x796B0000,
  /*!
   * Description:  The private key could not be overwritten in Csm.
   * Source:       External
   * Reason:       The decrypted private key could not be overwritten in Csm.
   *                This may be due to a Csm/Crypto issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResHelperClearTmpPrivKeyClearValidationPrivKeyFailed = 0x796C0000,
  /*!
   * Description:  The public key used to verify the Xml signature could not be copied to
   *                Xml signature verify Csm job.
   * Source:       External
   * Reason:       Most probably it is an issue in Csm config of the key elements and the access rights.
   *               Make sure that both key elements have a matching configuration.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResHelperCopyPublicKeyFailed = 0x796D0000,
  /*!
   * Description:  The Encrypted private key received from EVSE is not supported.
   * Source:       External
   * Reason:       The Encrypted private key received from EVSE is not supported. This could be a config error. */
  SccDetailedError_Iso_20_CertficateInstallationResEncryptedKeyUnsupported = 0x796E0000,
  /*!
   * Description:  The Encrypted private key received from EVSE is currently not supported.
   * Source:       External
   * Reason:       The Encrypted private key received from EVSE is currently not supported. */
  SccDetailedError_Iso_20_CertficateInstallationResEncryptedKeyTPM = 0x796F0000,
  /*!
   * Description:  The current configuration does not match the received CPS chain.
   * Source:       External
   * Reason:       The received CPS chain has more certificates than configured in KeyM. */
  SccDetailedError_Iso_20_CertficateInstallationResCPSConfigMismatch = 0x79700000,
  /*!
   * Description:  Scc is not able to clear the temporary certificate slot used for
   *               validating the certificate provisioning service certificates in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for CPS-SubCA 1 certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResClearProvSubCa1Failed2 = 0x79710000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  Scc is not able to clear the temporary certificate slot used for
   *               validating the certificate provisioning service certificates in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for CPS-SubCA 2 certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResClearProvSubCa2Failed2 = 0x79720000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  Scc is not able to clear the temporary certificate slot used for
   *               validating the certificate provisioning service certificates in KeyM.
   * Source:       External
   * Reason:       KeyM rejected the write request for leaf certificate by Scc.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResClearProvLeafFailed2 = 0x79730000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  OEM cert curve and received ECDHCurve do not match.
   * Source:       External
   * Reason:       The received ECDHCurve was set to a wrong value by an EVSE. */
  SccDetailedError_Iso_20_CertficateInstallationResECDHCurveInvalidToOEM = 0x79740000,
  /*!
   * Description:  No CPS certificate available.
   * Source:       External
   * Reason:       The CPS certificate is not available. This issue may happen
   *               due to a configuration issue in KeyM. */
  SccDetailedError_Iso_20_CertficateInstallationResCPSCertNotAvailable = 0x79750000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  No CPS certificate available.
   * Source:       External
   * Reason:       The CPS certificate is not available. This issue may happen
   *               due to a configuration issue in KeyM. */
  SccDetailedError_Iso_20_CertficateInstallationResCPSCertNotAvailable2 = 0x79760000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  No CPS certificate available.
   * Source:       External
   * Reason:       The CPS certificate is not available. This issue may happen
   *               due to a configuration issue in KeyM. */
  SccDetailedError_Iso_20_CertficateInstallationResCPSCertNotAvailable3 = 0x79770000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  The SKI could not be accessed.
   * Source:       External
   * Reason:       The Subject Key identifier can not be accessed by using KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_Iso_20_CertficateInstallationResCertReadSki = 0x79780000,
  /*!
   * Description:  The IpBase conversion to Hex could not be done.
   * Source:       External
   * Reason:       The IpBase conversion to Hex could not be done. */
  SccDetailedError_Iso_20_CertficateInstallationResHexConvertError = 0x79790000,
  /*!
   * Description:  The AAD could not be set to Csm.
   * Source:       External
   * Reason:       The AAD cannot be written to Csm. This may happen
   *                due Csm configuration issue.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_CertficateInstallationResAadWriteFail = 0x797A0000,
  /*!
   * Description:  Scc was not able to read SubjectCommonName information from KeyM.
   * Source:       External
   * Reason:       KeyM returned error code.
   * Note:         May contain KeyM error. */
  SccDetailedError_KeyMUtils_ExtractPcidKeyMAccessFailed = 0x797B0000,
  /*!
   * Description:  The received Prov Sub-Ca1 certificate is invalid.
   * Source:       External
   * Reason:       The Prov Sub-Ca1 certificate can not be verified by a stored V2G root certificate.
   *                This may happen due to no matching root certificate, KeyM configuration issue
   *                or a format error of the received certificate. */
  SccDetailedError_Iso_20_CertficateInstallationResCcProvSubCa1Invalid = 0x797C0000,
  /*!
   * Description:  The received Prov Leaf(provisioning) certificate is invalid.
   * Source:       External
   * Reason:       The Prov Leaf(provisioning) certificate can not be verified up to a stored V2G root certificate.
   *                This may happen due to no matching chain of trust, KeyM configuration issue
   *                or a format error of the received certificate. */
  SccDetailedError_Iso_20_CertficateInstallationResCcProvLeafInvalid = 0x797D0000,
  /*!
   * Description:  The received MO Sub-Ca2 certificate is invalid.
   * Source:       External
   * Reason:       The MO Sub-Ca1 certificate can not be verified by the received Sub-Ca1 certificate
   *                if the chain contains this certificate. Additionaly this may happen due to
   *                KeyM configuration issue or a format error of the received certificate. */
  SccDetailedError_Iso_20_CertficateInstallationResCcMOSubCa1Invalid = 0x797E0000,
  /*!
   * Description:  The received MO Sub-Ca2 certificate is invalid.
   * Source:       External
   * Reason:       The MO Sub-Ca2 certificate can not be verified by the received Sub-Ca1 certificate
   *                if the chain contains this certificate. Additionaly this may happen due to
   *                KeyM configuration issue or a format error of the received certificate. */
  SccDetailedError_Iso_20_CertficateInstallationResCcMOSubCa2Invalid = 0x797F0000,
  /*!
   * Description:  The received MO Leaf(contract) certificate is invalid.
   * Source:       External
   * Reason:       The MO Leaf(contract) certificate can not be verified by the Sub-Ca2 certificate.
   *                This may happen due to no matching chain of trust, KeyM configuration issue
   *                or a format error of the received certificate. */
  SccDetailedError_Iso_20_CertficateInstallationResCcMOLeafInvalid = 0x79800000,
  /*!
   * Description:  The received CPS Sub-Ca1 certificate is based on a rejected elliptic curve type.
   * Source:       External
   * Reason:       The certificate uses a elliptic curve which is rejected by application. */
  SccDetailedError_Iso_20_CertificateInstallationResCPSSubCa1EllipticCurveRejected = 0x79810000,
  /*!
   * Description:  The received CPS Sub-Ca2 certificate is based on a rejected elliptic curve type.
   * Source:       External
   * Reason:       The certificate uses a elliptic curve which is rejected by application. */
  SccDetailedError_Iso_20_CertificateInstallationResCPSSubCa2EllipticCurveRejected = 0x79820000,
  /*!
   * Description:  The received CPS Leaf certificate is based on a rejected elliptic curve type.
   * Source:       External
   * Reason:       The certificate uses a elliptic curve which is rejected by application. */
  SccDetailedError_Iso_20_CertificateInstallationResCPSLeafEllipticCurveRejected = 0x79830000,
  /*!
   * Description:  The received MO Sub-Ca1 certificate is based on a rejected elliptic curve type.
   * Source:       External
   * Reason:       The contract certificate uses a elliptic curve which is rejected by application. */
  SccDetailedError_Iso_20_CertificateInstallationResMOSubCa1EllipticCurveRejected = 0x79840000,
  /*!
   * Description:  The received MO Sub-Ca2 certificate is based on a rejected elliptic curve type.
   * Source:       External
   * Reason:       The contract certificate uses a elliptic curve which is rejected by application. */
  SccDetailedError_Iso_20_CertificateInstallationResMOSubCa2EllipticCurveRejected = 0x79850000,
  /*!
   * Description:  The received MO Leaf (contract) certificate is based on a rejected elliptic curve type.
   * Source:       External
   * Reason:       The certificate uses a elliptic curve which is rejected by application. */
  SccDetailedError_Iso_20_CertificateInstallationResMOLeafEllipticCurveRejected = 0x79860000,
  /*!
   * Description:  The received ECDH curve is rejected.
   * Source:       External
   * Reason:       The received ECDH curve during CertificateInstallation is rejected by application. */
  SccDetailedError_Iso_20_CertificateInstallationResECDHCurveRejected = 0x79870000,
  /*!
   * Description:  The encrypted private key could not be decrypted for TPM.
   * Source:       External
   * Reason:       Application indicated an error that occurred during decryption of the
   *               encrypted private key. */
  SccDetailedError_Iso_20_CertficateInstallationResTPMProcessingFailed = 0x79880000,
  /*!
   * Description:  The public key could not be set in Csm for key pair validation.
   * Source:       External
   * Reason:       Csm reported an error that the key could not be set.
   * Note:         May contain Csm error.*/
    SccDetailedError_Iso_20_CertficateInstallationResTPMFailedToSetupPublicKey = 0x79890000,
  /*!
   * Description:  The public key could not be set to valid in Csm for key pair validation.
   * Source:       External
   * Reason:       Csm reported an error that the key could not be set to valid.
   * Note:         May contain Csm error.*/
    SccDetailedError_Iso_20_CertficateInstallationResTPMFailedToSetPublicKeyValid = 0x798A0000,

  /***************************************** Identification Details *******************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_IdentificationDetailsResMessageOutOfSequence = 0x79900000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_IdentificationDetailsResNegativeResponseCode = 0x79910000,


  /***************************************** Authorization ****************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_AuthorizationResMessageOutOfSequence = 0x79E00000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_AuthorizationResNegativeResponseCode = 0x79E10000,


  /***************************************** Charge Parameter Discvoery ***************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_ChargeParameterDiscoveryResMessageOutOfSequence = 0x7A440000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_ChargeParameterDiscoveryResNegativeResponseCode = 0x7A450000,
  /*!
   * Description:  The received message is missing a SAScheduleList.
   * Source:       External
   * Reason:       A message was sent by the SECC with no SASchedule. At least one schedule is
   *                needed. */
  SccDetailedError_Iso_20_ChargeParameterDiscoveryResMissingSaschedulelist = 0x7A460000,
  /*!
   * Description:  The received message's signature could not be verified.
   * Source:       Internal
   * Reason:       The contract sub cert1 is missing. Therefore, the signature could not be
   *                verified. */
  SccDetailedError_Iso_20_ChargeParameterDiscoveryResMissingContrsubcert1 = 0x7A470000,
  /*!
   * Description:  The received message's signature could not be verified.
   * Source:       Internal
   * Reason:       The contract certificate has an invalid public key length. Therefore, the
   *                signature could not be verified. */
  SccDetailedError_Iso_20_ChargeParameterDiscoveryResPublicKeyLenInvalid = 0x7A480000,
  /*!
   * Description:  The received message contains an invalid enerfy transfer mode.
   * Source:       Internal
   * Reason:       AC charging was selected but CPDResEnergyTransferMode contains an invalid element.
   *                 A SECC sent an unexpected message. */
  SccDetailedError_Iso_20_ChargeParameterDiscoveryResAcCpdresenergytransfermodeElemIdInvalid = 0x7A490000,
  /*!
   * Description:  The received message contains an invalid enerfy transfer mode.
   * Source:       Internal
   * Reason:       DC charging was selected but CPDResEnergyTransferMode contains an invalid element.
   *                 A SECC sent an unexpected message. */
  SccDetailedError_Iso_20_ChargeParameterDiscoveryResDcCpdresenergytransfermodeElemIdInvalid = 0x7A4A0000,
  /*!
   * Description:  The received message contains an invalid enerfy transfer mode.
   * Source:       Internal
   * Reason:       WPT charging was selected but CPDResEnergyTransferMode contains an invalid element.
   *                 A SECC sent an unexpected message. */
  SccDetailedError_Iso_20_ChargeParameterDiscoveryResWptCpdresenergytransfermodeElemIdInvalid = 0x7A4B0000,
  /*!
   * Description:  The received message contains an invalid enerfy transfer mode.
   * Source:       Internal
   * Reason:       BPT_AC charging was selected but CPDResEnergyTransferMode contains an invalid element.
   *                 A SECC sent an unexpected message. */
  SccDetailedError_Iso_20_ChargeParameterDiscoveryResBptAcCpdresenergytransfermodeElemIdInvalid = 0x7A4C0000,
  /*!
   * Description:  The received message contains an invalid enerfy transfer mode.
   * Source:       Internal
   * Reason:       BPT_DC charging was selected but CPDResEnergyTransferMode contains an invalid element.
   *                 A SECC sent an unexpected message. */
  SccDetailedError_Iso_20_ChargeParameterDiscoveryResBptDcCpdresenergytransfermodeElemIdInvalid = 0x7A4D0000,
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_WptChargeParameterDiscoveryResMessageOutOfSequence = 0x7A4E0000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_WptChargeParameterDiscoveryResNegativeResponseCode = 0x7A4F0000,


  /***************************************** Power Delivery ***************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_PowerDeliveryResMessageOutOfSequence = 0x7AA80000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_PowerDeliveryResNegativeResponseCode = 0x7AA90000,


  /***************************************** Metering Receipt *************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_MeteringReceiptResMessageOutOfSequence = 0x7B0C0000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_MeteringReceiptResNegativeResponseCode = 0x7B0D0000,


  /***************************************** Session Stop *****************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_SessionStopResMessageOutOfSequence = 0x7B700000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_SessionStopResNegativeResponseCode = 0x7B710000,
  /*!
   * Description:  Unable to write key element.
   * Source:       External
   * Reason:       Unable to write key element to Csm. This issue may happen due to a configuration issue in Csm.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_SessionStopReqResumeSessionWriteFailed = 0x7B720000,
  /*!
   * Description:  Unable to write key element.
   * Source:       External
   * Reason:       Unable to write key element to Csm. This issue may happen due to a configuration issue in Csm.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_SessionStopReqResumeSessionValidWriteFailed = 0x7B730000,


  /***************************************** Charging Status **************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_ChargingStatusResMessageOutOfSequence = 0x7BD40000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_ChargingStatusResNegativeResponseCode = 0x7BD50000,
  /*!
   * Description:  The response does not match the scheduled control mode.
   * Source:       External
   * Reason:       A response containing a scheduled control mode was expected. The CLResControlMode
   *                contains a wrong element. */
  SccDetailedError_Iso_20_ChargingStatusResScheduledClrescontrolmodeElemIdInvalid = 0x7BD60000,
  /*!
   * Description:  The response is missing the SAScheduleTupleId element.
   * Source:       External
   * Reason:       A SECC sent a response without a SAScheduleTupleId element. */
  SccDetailedError_Iso_20_ChargingStatusResScheduledMissingSascheduletupleid = 0x7BD70000,
  /*!
   * Description:  The response contains an invalid SAScheduleTupleId.
   * Source:       External
   * Reason:       The Id differs from the one sent in the PowerDelivery request. */
  SccDetailedError_Iso_20_ChargingStatusResScheduledUnexpectedSascheduletupleid = 0x7BD80000,
  /*!
   * Description:  The response does not match the dynamic control mode.
   * Source:       External
   * Reason:       A response containing a dynamic control mode was expected. The CSResControlMode
   *                element is missing. */
  SccDetailedError_Iso_20_ChargingStatusResDynamicMissingClrescontrolmodeElement = 0x7BD90000,
  /*!
   * Description:  The response does not match the dynamic control mode.
   * Source:       External
   * Reason:       A response containing a dynamic control mode was expected. The CLResControlMode
   *                contains a wrong element. */
  SccDetailedError_Iso_20_ChargingStatusResDynamicClrescontrolmodeElemIdInvalid = 0x7BDA0000,


  /***************************************** Cable Check ******************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_CableCheckResMessageOutOfSequence = 0x7C380000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_CableCheckResNegativeResponseCode = 0x7C390000,


  /***************************************** Pre Charge *******************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_PreChargeResMessageOutOfSequence = 0x7C9C0000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_PreChargeResNegativeResponseCode = 0x7C9D0000,


  /***************************************** Current Demand ***************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_CurrentDemandResMessageOutOfSequence = 0x7D000000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_CurrentDemandResNegativeResponseCode = 0x7D010000,
  /*!
   * Description:  The response contains an invalid CLResControlMode.
   * Source:       External
   * Reason:       A response containing a scheduled control mode was expected. The CLResControlMode
   *                contains a wrong element. */
  SccDetailedError_Iso_20_CurrentDemandResClrescontrolmodeElemIdInvalid = 0x7D020000,
  /*!
   * Description:  The response is missing the ScheduleTupleID element.
   * Source:       External
   * Reason:       A response containing a ScheduleTupleID element was expected. */
  SccDetailedError_Iso_20_CurrentDemandResMissingScheduletupleidElement = 0x7D030000,
  /*!
   * Description:  The response contains an invalid SAScheduleTupleId.
   * Source:       External
   * Reason:       The Id differs from the one sent in the PowerDelivery request. */
  SccDetailedError_Iso_20_CurrentDemandResUnexpectedSascheduletupleid = 0x7D040000,


  /***************************************** Welding Detection ************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_WeldingDetectionResMessageOutOfSequence = 0x7D640000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_WeldingDetectionResNegativeResponseCode   = 0x7D650000,


  /***************************************** Fine Postioning Setup ********************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_FinePositioningSetupResMessageOutOfSequence = 0x7DC80000,


  /***************************************** ACDP Vehicle Positioning *****************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_ACDP_VehiclePositioningResMessageOutOfSequence = 0x7DD00000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_ACDP_VehiclePositioningResNegativeResponseCode = 0x7DD10000,

  /***************************************** ACDP Connect *****************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_ACDP_ConnectResMessageOutOfSequence = 0x7DD80000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_ACDP_ConnectResNegativeResponseCode = 0x7DD90000,


  /***************************************** ACDP Disconnect **************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_ACDP_DisconnectResMessageOutOfSequence = 0x7DE00000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_ACDP_DisconnectResNegativeResponseCode = 0x7DE10000,

  /***************************************** ACDP SystemStatus **************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_ACDP_SystemStatusResMessageOutOfSequence = 0x7DE20000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_ACDP_SystemStatusResNegativeResponseCode = 0x7DE30000,

  /***************************************** Fine Postioning **************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_FinePositioningResMessageOutOfSequence = 0x7E2C0000,


  /***************************************** Pairing **********************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_PairingResMessageOutOfSequence = 0x7E900000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_PairingResNegativeResponseCode = 0x7E910000,


  /***************************************** Alignment Check **************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_AlignmentCheckResMessageOutOfSequence = 0x7EF40000,


  /***************************************** Power Demand *****************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_PowerDemandResMessageOutOfSequence = 0x7F580000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_PowerDemandResNegativeResponseCode = 0x7F590000,
  /*!
   * Description:  The response contains an invalid CLResControlMode.
   * Source:       External
   * Reason:       A response containing a scheduled control mode was expected. The CLResControlMode
   *                contains a wrong element. */
  SccDetailedError_Iso_20_PowerDemandResClrescontrolmodeElemIdInvalid = 0x7F5A0000,
  /*!
   * Description:  The response is missing the ScheduleTupleID element.
   * Source:       External
   * Reason:       A response containing a ScheduleTupleID element was expected. */
  SccDetailedError_Iso_20_PowerDemandResMissingScheduletupleidElement = 0x7F5B0000,
  /*!
   * Description:  The response contains an invalid SAScheduleTupleId.
   * Source:       External
   * Reason:       The Id differs from the one sent in the PowerDelivery request. */
  SccDetailedError_Iso_20_PowerDemandResUnexpectedSascheduletupleid = 0x7F5C0000,


  /***************************************** AC Bidirectional Control *****************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_AcBidirectionalControlResMessageOutOfSequence = 0x7FBC0000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_AcBidirectionalControlResNegativeResponseCode = 0x7FBD0000,
  /*!
   * Description:  The response contains an invalid CLResControlMode.
   * Source:       External
   * Reason:       A response containing a scheduled control mode was expected. The CLResControlMode
   *                contains a wrong element. */
  SccDetailedError_Iso_20_AcBidirectionalControlResClrescontrolmodeElemIdInvalid = 0x7FBE0000,
  /*!
   * Description:  The response is missing the ScheduleTupleID element.
   * Source:       External
   * Reason:       A response containing a ScheduleTupleID element was expected. */
  SccDetailedError_Iso_20_AcBidirectionalControlResMissingScheduletupleidElement = 0x7FBF0000,
  /*!
   * Description:  The response contains an invalid SAScheduleTupleId.
   * Source:       External
   * Reason:       The Id differs from the one sent in the PowerDelivery request. */
  SccDetailedError_Iso_20_AcBidirectionalControlResUnexpectedSascheduletupleid = 0x7FC00000,
  /* 0x7FC10000 etc used for SccDetailedError_Iso_20_MeteringConfirmationReqXmlsecurityInit */


  /***************************************** DC Bidirectional Control *****************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_DcBidirectionalControlResMessageOutOfSequence = 0x7FD00000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_DcBidirectionalControlResNegativeResponseCode = 0x7FD10000,
  /*!
   * Description:  The response contains an invalid CLResControlMode.
   * Source:       External
   * Reason:       A response containing a scheduled control mode was expected. The CLResControlMode
   *                contains a wrong element. */
  SccDetailedError_Iso_20_DcBidirectionalControlResClrescontrolmodeElemIdInvalid = 0x7FD20000,
  /*!
   * Description:  The response is missing the ScheduleTupleID element.
   * Source:       External
   * Reason:       A response containing a ScheduleTupleID element was expected. */
  SccDetailedError_Iso_20_DcBidirectionalControlResMissingScheduletupleidElement = 0x7FD30000,
  /*!
   * Description:  The response contains an invalid SAScheduleTupleId.
   * Source:       External
   * Reason:       The Id differs from the one sent in the PowerDelivery request. */
  SccDetailedError_Iso_20_DcBidirectionalControlResUnexpectedSascheduletupleid = 0x7FD40000,

  /***************************************** Authorization Setup ****************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_AuthorizationSetupResMessageOutOfSequence = 0x7FDA0000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_AuthorizationSetupResNegativeResponseCode = 0x7FDB0000,

  /***************************************** Charge Loop ************************************************/
  /***************** AC *****************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20AC_ChargeLoopResMessageOutOfSequence = 0x7FE00000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20AC_ChargeLoopResNegativeResponseCode = 0x7FE10000,
  /*!
   * Description:  A message containing an invalid data element id was received.
   * Source:       External
   * Reason:       Exi decoded an unexpected element id that is currently not supported by Scc. */
  SccDetailedError_Iso_20AC_ChargeParameterDiscoveryResUnsupportedEnergyModeElementId = 0x7FE20000,
  /*!
   * Description:  A message containing an invalid data element id was received.
   * Source:       External
   * Reason:       Exi decoded an unexpected element id that is currently not supported by Scc. */
  SccDetailedError_Iso_20AC_ChargeLoopResUnsupporteControlModedElementId = 0x7FE30000,
  /*!
   * Description:  Application provided an invalid control mode.
   * Source:       External
   * Reason:       The application provided an invalid control mode input that is not supported by Scc. */
  SccDetailedError_Iso_20AC_ChargeLoopReqInvalidControlMode = 0x7FE40000,

  /***************** WPT *****************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
 SccDetailedError_Iso_20WPT_ChargeLoopResMessageOutOfSequence = 0x7FE50000,

  /***************** DC *****************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20DC_ChargeLoopResMessageOutOfSequence = 0x7FEA0000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20DC_ChargeLoopResNegativeResponseCode = 0x7FEB0000,
  /*!
   * Description:  A message containing an invalid data element id was received.
   * Source:       External
   * Reason:       Exi decoded an unexpected element id that is currently not supported by Scc.
   */
  SccDetailedError_Iso_20DC_ChargeParameterDiscoveryResUnsupportedEnergyModeElementId = 0x7FEC0000,
  /*!
   * Description:  A message containing an invalid data element id was received.
   * Source:       External
   * Reason:       Exi decoded an unexpected element id that is currently not supported by Scc.
   */
  SccDetailedError_Iso_20DC_ChargeLoopResUnsupporteControlModedElementId = 0x7FED0000,
  /*!
   * Description:  Application provided an invalid control mode.
   * Source:       External
   * Reason:       The application provided an invalid control mode input that is not supported by Scc.
   */
  SccDetailedError_Iso_20DC_ChargeLoopReqInvalidControlMode = 0x7FEE0000,


  /***************************************** Schedule Exchange ******************************************/
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_ScheduleExchangeResMessageOutOfSequence = 0x7FF00000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_ScheduleExchangeResNegativeResponseCode = 0x7FF10000,
  /*!
   * Description:  A message containing no signature was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing no signature where a signature was expected.
   *                Something went wrong at the SECC. */
  SccDetailedError_Iso_20_ScheduleExchangeResNoSignature = 0x7FF20000,

  /***************************************** Metering Confirmation ******************************************/
  /*!
   * Description:  Application provided an invalid control mode.
   * Source:       External
   * Reason:       The application provided an invalid control mode input that is not supported by Scc. */
  SccDetailedError_Iso_20_MeteringConfirmationReqInvalidControlMode = 0x7FF30000,
  /*!
   * Description:  An unexpected message was received.
   * Source :      External
   * Reason :      An unexpected message was sent by the SECC. This indicates an out of sequence error.
   *                The SECC should stick to the specified message sequences. */
  SccDetailedError_Iso_20_MeteringConfirmationResMessageOutOfSequence = 0x7FF40000,
  /*!
   * Description:  A message containing a negative response code was received.
   * Source:       External
   * Reason:       A message was sent by the SECC containing a negative response code. Something
   *                went wrong at the SECC. */
  SccDetailedError_Iso_20_MeteringConfirmationResNegativeResponseCode = 0x7FC10000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The initialization of XmlSecurity failed.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_20_MeteringConfirmationReqXmlsecurityInit = 0x7FC20000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to setup the Xml Security workspace.
   *                Digest method was not accepted.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_20_MeteringConfirmationReqXmlSecuritySetDigestMethod = 0x7FC30000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Scc was unable to setup the Xml Security workspace.
   *                Signature method was not accepted.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_20_MeteringConfirmationReqXmlsecuritySetSignatureMethod = 0x7FC40000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The used Csm job could not be set in the XmlSecurity workspace. */
  SccDetailedError_Iso_20_MeteringConfirmationReqXmlsecuritySetExistreambuffer = 0x7FC50000,
  /*!
   * Description:  The XmlSecurity setup workspace could not be handled.
   * Source:       External
   * Reason:       An unsupported curve was used, therefore Scc is not able to setup XmlSecurity.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_20_MeteringConfirmationReqSetupXmlSecWs = 0x7FC60000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The private key of the chosen contract can not be copied in Csm.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_MeteringConfirmationReqCsmContrKeyElemCopyFailed = 0x7FC70000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The private key of the chosen contract was copied in Csm but could not be set to valid.
   * Note:         May contain Csm error. */
  SccDetailedError_Iso_20_MeteringConfirmationReqCsmContrKeySetValidFailed = 0x7FC80000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       The reference could not be added to the XmlSecurity workspace.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_20_MeteringConfirmationReqXmlsecurityAddReference = 0x7FC90000,
  /*!
   * Description:  The request could not be created.
   * Source:       External
   * Reason:       Signature generation by using XmlSecurity failed due to an XmlSecurity error.
   * Note:         May contain XmlSecurity error. */
  SccDetailedError_Iso_20_MeteringConfirmationReqXmlsecuritySignatureGeneration = 0x7FCA0000,

  /***************************************** Delete Contract ******************************************/
  /*!
   * Description:  Private key set to zero to delete private key has failed in Csm.
   * Source:       External
   * Reason:       Failed Csm key element set.
   * Note:         May contain Csm error. */
  SccDetailedError_DeleteContract_PrivKeyCsmDeleteFailed = 0x7FF50000,
  /*!
   * Description:  Delete ContrCert has failed in KeyM.
   * Source:       External
   * Reason:       Failed KeyM certificate delete.
   * Note:         May contain KeyM error. */
    SccDetailedError_DeleteContract_ContrCertDeleteFailed = 0x7FF60000,
  /*!
   * Description:  Delete MoSubCa1 has failed in KeyM.
   * Source:       External
   * Reason:       Failed KeyM certificate delete.
   * Note:         May contain KeyM error. */
    SccDetailedError_DeleteContract_MoSubCa1DeleteFailed = 0x7FF70000,
  /*!
   * Description:  Delete MoSubCa2 has failed in KeyM.
   * Source:       External
   * Reason:       Failed KeyM certificate delete.
   * Note:         May contain KeyM error. */
  SccDetailedError_DeleteContract_MoSubCa2DeleteFailed = 0x7FF80000,


  /***************************************** KeyM Utils ******************************************/
  /*!
   * Description:  Scc was not able to read certificate status information from KeyM.
   * Source:       External
   * Reason:       KeyM returned error code.
   * Note:         May contain KeyM error. */
  SccDetailedError_KeyMUtils_GetFirstAvailableCertInGroupKeyMAccessFailed = 0x60000000,
  /*!
   * Description:  Scc was not able to read certificate status information from KeyM.
   * Source:       External
   * Reason:       KeyM returned error code.
   * Note:         May contain KeyM error. */
  SccDetailedError_KeyMUtils_GetFirstAvailableCertInSubCa2ContrGroupKeyMAccessFailed = 0x60010000,
  /*!
   * Description:  Scc was not able to read certificate status information from KeyM.
   * Source:       External
   * Reason:       KeyM returned error code.
   * Note:         May contain KeyM error. */
  SccDetailedError_KeyMUtils_GetFirstAvailableCertInSubCa1ContrGroupKeyMAccessFailed = 0x60020000,
  /*!
   * Description:  Scc was not able to read certificate status information from KeyM.
   * Source:       External
   * Reason:       KeyM returned error code.
   * Note:         May contain KeyM error. */
  SccDetailedError_KeyMUtils_GetFirstAvailableCertInLeafContrGroupKeyMAccessFailed = 0x60030000,
  /*!
   * Description:  Scc was not able to read certificate status information from KeyM.
   * Source:       External
   * Reason:       KeyM returned error code.
   * Note:         May contain KeyM error. */
  SccDetailedError_KeyMUtils_GetFirstAvailableEMSPCertInGroupKeyMAccessFailed = 0x60040000,
  /*!
   * Description:  Scc was not able to detect an available Sub-Ca1 certificate in KeyM.
   * Source:       External
   * Reason:       The KeyM certificate status of a group certificate was invalid. */
  SccDetailedError_KeyMUtils_UpdateContractSubCa1InvalidCert = 0x60050000,
  /*!
   * Description:  Scc was not able to detect an available Sub-Ca2 certificate in KeyM.
   * Source:       External
   * Reason:       The KeyM certificate status of a group certificate was invalid. */
  SccDetailedError_KeyMUtils_UpdateContractSubCa2InvalidCert = 0x60060000,
  /*!
   * Description:  Scc was not able to detect an available leaf certificate in KeyM.
   * Source:       External
   * Reason:       The KeyM certificate status of a group certificate was invalid. */
  SccDetailedError_KeyMUtils_UpdateContractLeafInvalidCert = 0x60070000,
  /*!
   * Description:  Scc was not able to read certificate common name information from KeyM.
   * Source:       External
   * Reason:       KeyM returned error code.
   * Note:         May contain KeyM error. */
  SccDetailedError_KeyMUtils_IsProviderIdFoundKeyMAccessFailed = 0x60080000,
  /*!
   * Description:  Scc was not able to read certificate common name information from KeyM.
   * Source:       External
   * Reason:       KeyM returned error code.
   * Note:         May contain KeyM error. */
  SccDetailedError_KeyMUtils_ExtractEmaidListKeyMAccessFailed = 0x60090000,

  /************ Tls client authentication ***********/
  /*!
   * Description:  A KeyM error occurred while reading the issuer of the highest intermediate certificate of the
   *                vehicle certificate chain.
   * Source:       External
   * Reason:       KeyM access rejected with an error.
   * Note:         May contain a KeyM error. */
  SccDetailedError_KeyMUtils_ClientAuthVehicleChainIssuerKeyMAccessFailed = 0x60100000,

  /*!
   * Description:  A KeyM error occurred while reading the certificate status of
   *                vehicle leaf certificate.
   * Source:       External
   * Reason:       KeyM access rejected with error.
   * Note:         May contain KeyM error. */
  SccDetailedError_KeyMUtils_IsVehicleChainAvailableLeafStatusFailed = 0x60C00000,
  /*!
   * Description:  A KeyM error occurred while reading the certificate status of
   *                vehicle Sub-CA2 certificate.
   * Source:       External
   * Reason:       KeyM access rejected with error.
   * Note:         May contain KeyM error. */
  SccDetailedError_KeyMUtils_IsVehicleChainAvailableSubCa2StatusFailed = 0x60C10000,
  /*!
   * Description:  A KeyM error occurred while reading the certificate status of
   *                vehicle Sub-CA1 certificate.
   * Source:       External
   * Reason:       KeyM access rejected with error.
   * Note:         May contain KeyM error. */
  SccDetailedError_KeyMUtils_IsVehicleChainAvailableSubCa1StatusFailed = 0x60C20000,

  /*!
   * Description:  Application selected a vehicle chain index that is out of range.
   * Source:       External
   * Reason:       Application behavior is wrong. */
  SccDetailedError_Core_ISO20VehicleChainListHandleApplInvalidChainIdSelection = 0x60D00000, /* PRQA S 1711 */ /* MD_SCC_LongNames */
  /*!
   * Description:  Application selected a vehicle chain that is not compatible with
   *                signature algorithms supported by EVSE.
   * Source:       External
   * Reason:       Application behavior is wrong. */
  SccDetailedError_Core_ISO20VehicleChainListHandleApplInvalidChainSelection = 0x60D10000, /* PRQA S 1711 */ /* MD_SCC_LongNames */

  /*!
   * Description:  Buffer size is too small to write the vehicle cert chain and the root cert.
   * Source:       External
   * Reason:       Buffer chosen in Tls configuration too small. */
  SccDetailedError_Core_ISO20VehicleChainListHandlePushButtonModeListLengthInsufficient = 0x60D20000, /* PRQA S 1711 */ /* MD_SCC_LongNames */

  /*!
   * Description:  A KeyM error occurred while determining issuer of Sub1 certificate
   * Source:       External
   * Reason:       KeyM access rejected with error. */
  SccDetailedError_Core_ISO20VehicleChainListHandlePushButtonModeSubCa1IssuerNotAvailable = 0x60D30000, /* PRQA S 1711 */ /* MD_SCC_LongNames */

  /*!
   * Description:  A KeyM error occurred while determining issuer of Sub2 certificate
   * Source:       External
   * Reason:       KeyM access rejected with error. */
  SccDetailedError_Core_ISO20VehicleChainListHandlePushButtonModeSubCa2IssuerNotAvailable = 0x60D40000, /* PRQA S 1711 */ /* MD_SCC_LongNames */

  /*!
   * Description:  A KeyM error occurred while reading the basic constraints extension.
   * Source:       External
   * Reason:       KeyM access rejected with error. */
  SccDetailedError_KeyMUtils_BasicConstraintsExtensionNotAvailable = 0x60D50000,

  /*!
   * Description:  The basic constraints extension availability other than expected.
   * Source:       External
   * Reason:       Data of given certificate id other than expected. */
  SccDetailedError_KeyMUtils_BasicConstraintsExtensionAvailabilityOtherThanExpected = 0x60D60000,

  /*!
   * Description:  Key usage certificate extension availability other than expected.
   * Source:       External
   * Reason:       Data of given certificate id other than expected. */
  SccDetailedError_KeyMUtils_KeyUsageExtensionAvailabilityOtherThanExpected = 0x60D70000,

  /*!
   * Description:  A KeyM error occurred while reading the key usage extension.
   * Source:       External
   * Reason:       KeyM access rejected with error. */
  SccDetailedError_KeyMUtils_KeyUsageExtensionNotAvailable = 0x60D80000,

  /*!
   * Description:  Key usage certificate extension key usage flag state other than expected.
   * Source:       External
   * Reason:       Data of given certificate id other than expected. */
  SccDetailedError_KeyMUtils_KeyUsageExtensionhasKeyUsageInvalid = 0x60D90000,

  /*!
   * Description:  Key usage certificate extension critical flag state other than expected.
   * Source:       External
   * Reason:       Data of given certificate id other than expected. */
  SccDetailedError_KeyMUtils_KeyUsageExtensionCriticalFlagInvalid = 0x60DA0000,

  /*!
   * Description:  Key usage certificate extension digital signature flag state other than expected.
   * Source:       External
   * Reason:       Data of given certificate id other than expected. */
  SccDetailedError_KeyMUtils_KeyUsageExtensionDigitalSignatureFlagInvalid = 0x60DB0000,

  /*!
  * Description:  Key usage certificate extension non repudiation flag state other than expected.
  * Source:       External
  * Reason:       Data of given certificate id other than expected. */
  SccDetailedError_KeyMUtils_KeyUsageExtensionNonRepudiationFlagInvalid = 0x60DC0000,

  /*!
   * Description:  Key usage certificate extension key encipherment flag state other than expected.
   * Source:       External
   * Reason:       Data of given certificate id other than expected. */
  SccDetailedError_KeyMUtils_KeyUsageExtensionKeyEnciphermentFlagInvalid = 0x60DD0000,

  /*!
   * Description:  Key usage certificate extension data encipherment flag state other than expected.
   * Source:       External
   * Reason:       Data of given certificate id other than expected. */
  SccDetailedError_KeyMUtils_KeyUsageExtensionDataEnciphermentFlagInvalid = 0x60DE0000,

  /*!
   * Description:  Key usage certificate extension key agreement flag state other than expected.
   * Source:       External
   * Reason:       Data of given certificate id other than expected. */
  SccDetailedError_KeyMUtils_KeyUsageExtensionKeyAgreementFlagInvalid = 0x60DF0000,

  /*!
   * Description:  Key usage certificate extension key cert sign flag state other than expected.
   * Source:       External
   * Reason:       Data of given certificate id other than expected. */
  SccDetailedError_KeyMUtils_KeyUsageExtensionKeyCertSignFlagInvalid = 0x60E00000,

  /*!
   * Description:  Key usage certificate extension key cRL sign flag state other than expected.
   * Source:       External
   * Reason:       Data of given certificate id other than expected. */
  SccDetailedError_KeyMUtils_KeyUsageExtensionKeyCrlSignFlagInvalid = 0x60E10000,

  /*!
   * Description:  Key usage certificate extension encipher only flag state other than expected.
   * Source:       External
   * Reason:       Data of given certificate id other than expected. */
  SccDetailedError_KeyMUtils_KeyUsageExtensionEncipherOnlyFlagInvalid = 0x60E20000,

  /*!
   * Description:  Key usage certificate extension decipher only flag state other than expected.
   * Source:       External
   * Reason:       Data of given certificate id other than expected. */
  SccDetailedError_KeyMUtils_KeyUsageExtensionDecipherOnlyFlagInvalid = 0x60E30000,

  /*!
   * Description:  Basic constraints certificate extension critical flag state other than expected.
   * Source:       External
   * Reason:       Data of given certificate id other than expected. */
  SccDetailedError_KeyMUtils_BasicConstraintsExtensionCriticalFlagInvalid = 0x60E40000,

  /*!
   * Description:  Basic constraints certificate extension cA flag state other than expected.
   * Source:       External
   * Reason:       Data of given certificate id other than expected. */
  SccDetailedError_KeyMUtils_BasicConstraintsExtensionCaFlagInvalid = 0x60E50000,

  /*!
   * Description:  Basic constraints certificate extension path length flag state other than expected.
   * Source:       External
   * Reason:       Data of given certificate id other than expected. */
  SccDetailedError_KeyMUtils_BasicConstraintsExtensionPathLengthFlagInvalid = 0x60E60000,

  /*!
   * Description:  Basic constraints certificate extension path length parameter other than expected.
   * Source:       External
   * Reason:       Data of given certificate id other than expected. */
  SccDetailedError_KeyMUtils_BasicConstraintsExtensionPathLengthInvalid = 0x60E70000,

  /*!
   * Description:  The critical flag of an extension is not expected to be set.
   * Source:       External
   * Reason:       Data of given certificate id other than expected. Critical flag is set to true. */
  SccDetailedError_KeyMUtils_CertExtCriticalSetButShouldNot = 0x60E80000,
  /*!
   * Description:  The critical flag of an extension is expected to be set.
   * Source:       External
   * Reason:       Data of given certificate id other than expected. Critical flag is not set to true. */
  SccDetailedError_KeyMUtils_CertExtCriticalNotSetButShould = 0x60E90000,
  /*!
   * Description:  The critical flag of an extension is invalid.
   * Source:       External
   * Reason:       Data of given certificate id other than expected.
   * Note:         May contain KeyM error.*/
  SccDetailedError_KeyMUtils_CertExtCriticalInvalid = 0x60EA0000,
  /*!
   * Description:  The critical flag of an extension is expected to be set.
   * Source:       External
   * Reason:       Data of given certificate id other than expected. Critical flag is set not present in the certificate. */
  SccDetailedError_KeyMUtils_CertExtCriticalNotPresentButShould = 0x60F90000,

  /*!
   * Description:  The authority key identifier (AKI) extension is invalid.
   * Source:       External
   * Reason:       AKI extension may be missing in given certificate.
   * Note:         May contain KeyM error.*/
  SccDetailedError_KeyMUtils_CertExtAKIInvalid = 0x60EB0000,
  /*!
   * Description:  The authority key identifier (AKI) extension is present but should not.
   * Source:       External
   * Reason:       AKI extension is present in given certificate. */
  SccDetailedError_KeyMUtils_CertExtAKIPresentButShouldNot = 0x60EC0000,
  /*!
   * Description:  The authority key identifier (AKI) extension contains invalid data.
   * Source:       External
   * Reason:       AKI extension is present but usage of AuthorityCertIssuer and
   *               AuthorityCertSerialNumber is invalid. */
  SccDetailedError_KeyMUtils_CertExtAKIInvalidAuthorityParameter = 0x60ED0000,
  /*!
   * Description:  The authority key identifier (AKI) extension is not present but should.
   * Source:       External
   * Reason:       AKI extension is not present in given certificate. */
  SccDetailedError_KeyMUtils_CertExtAKINotPresentButShould = 0x60FA0000,

  /*!
   * Description:  The KeyIdentifier element of an Authority|SubjectKeyIdentifier (AKI|SKI) extension is not present.
   * Source:       External
   * Reason:       KeyIdentifier element is not present in given certificate but should. */
  SccDetailedError_KeyMUtils_CertExtAkiSkiKeyIdentifierMissing = 0x60EE0000,
  /*!
   * Description:  The KeyIdentifier element of Authority|SubjectKeyIdentifier (AKI|SKI) extension is present.
   * Source:       External
   * Reason:       KeyIdentifier element is present in given certificate but should not. */
  SccDetailedError_KeyMUtils_CertExtAkiSkiKeyIdentifierPresentButShouldNot = 0x60EF0000,
  /*!
   * Description:  The KeyIdentifier element length of Authority|SubjectKeyIdentifier (AKI|SKI) extension is invalid.
   * Source:       External
   * Reason:       KeyIdentifier element length is invalid in given certificate. */
  SccDetailedError_KeyMUtils_CertExtAkiSkiKeyIdentifierLengthInvalid = 0x60F00000,

  /*!
   * Description:  The subject key identifier (SKI) extension is invalid.
   * Source:       External
   * Reason:       SKI extension may be missing in given certificate.
   * Note:         May contain KeyM error.*/
  SccDetailedError_KeyMUtils_CertExtSKIInvalid = 0x60F10000,
  /*!
   * Description:  The subject key identifier (SKI) extension is present but should not.
   * Source:       External
   * Reason:       SKI extension is present in given certificate. */
  SccDetailedError_KeyMUtils_CertExtSKIPresentButShouldNot = 0x60F20000,
  /*!
   * Description:  The subject key identifier (SKI) extension is not present but should.
   * Source:       External
   * Reason:       SKI extension is not present in given certificate. */
  SccDetailedError_KeyMUtils_CertExtSKINotPresentButShould = 0x60FB0000,

  /*!
   * Description:  The ExtendedKeyUsage(EKU) extension is invalid.
   * Source:       External
   * Reason:       EKU extension may be missing in given certificate.
   * Note:         May contain KeyM error.*/
  SccDetailedError_KeyMUtils_CertExtExtendedKeyUsageInvalid = 0x60F30000,
  /*!
   * Description:  The ExtendedKeyUsage(EKU) extension is present but should not.
   * Source:       External
   * Reason:       EKU extension is present in given certificate. */
  SccDetailedError_KeyMUtils_CertExtExtendedKeyUsagePresentButShouldNot = 0x60F40000,
  /*!
   * Description:  The KeyPurpose element of ExtendedKeyUsage(EKU) extension is not accessible.
   * Source:       External
   * Reason:       KeyPurpose element can not be fetched from KeyM.
   * Note:         May contain KeyM error. */
  SccDetailedError_KeyMUtils_CertExtExtendedKeyUsageKeyPurposeNotAccessible = 0x60F50000,
  /*!
   * Description:  The KeyPurpose element of ExtendedKeyUsage(EKU) extension does not contain the ServerAuth information.
   * Source:       External
   * Reason:       KeyPurpose element should contain ServerAuthentication but does not. */
  SccDetailedError_KeyMUtils_CertExtExtendedKeyUsageKeyPurposeNoServerAuth = 0x60F60000,
  /*!
   * Description:  The ExtendedKeyUsage(EKU) extension is not present but should.
   * Source:       External
   * Reason:       EKU extension is not present in given certificate. */
  SccDetailedError_KeyMUtils_CertExtExtendedKeyUsageNotPresentButShould = 0x60F70000,

  /*!
   * Description:  In case method2 is used to calcute the keyIdentifier the first four bits must be 0100.
   * Source:       External
   * Reason:       First four bits do not match 0100. */
  SccDetailedError_KeyMUtils_CertExtAkiSkiMethod2InvalidStaticBits = 0x60F80000,


  /************ Buffer Pool ***********/
  /*!
   * Description:  The buffer pool is full. A buffer could not be requested.
   * Source:       Internal
   * Reason:       Error case not handled in Impl. */
  SccDetailedError_BuffPool_RequestError = 0x62000000,
  /*!
   * Description:  Buffer fetched for SDP Plc is too small.
   * Source:       Internal
   * Reason:       Configured buffer is too small. */
  SccDetailedError_BuffPool_SdpPlcBufferTooSmall = 0x62010000,
  /*!
   * Description:  Buffer fetched for SDP Wireless is too small.
   * Source:       Internal
   * Reason:       Configured buffer is too small. */
  SccDetailedError_BuffPool_SdpWirelessBufferTooSmall = 0x62020000,
  /*!
   * Description:  A buffer could not be fetched.
   * Source:       Internal
   * Reason:       PoolId invalid. */
  SccDetailedError_BuffPool_GetErrorDecodePrepare = 0x62030000,
  /*!
   * Description:  A buffer could not be fetched.
   * Source:       Internal
   * Reason:       PoolId invalid. */
  SccDetailedError_BuffPool_GetErrorProcCertInstall = 0x62040000,
  /*!
   * Description:  The buffer pool is not busy. But a release was requested.
   * Source:       Internal
   * Reason:       Release requested where not required. */
  SccDetailedError_BuffPool_ReleaseError = 0x62050000

  /**************************************************/

} Scc_DetailedErrorEnumType;


#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
typedef struct {
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) MethodNamePtr; /**< Pointer pointing to string value to be used */
  uint8 MethodNameLen;                                    /**< Length of the string to use */
  uint8 MethodSize;                                       /**< Size of the method value */
  P2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) CsmJobPtr;/**< CsmJod to use */
}Scc_XmlSecDigestConfigStructType;

typedef struct {
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) MethodNamePtr; /**< Pointer pointing to string value to be used */
  uint8 MethodNameLen;                                    /**< Length of the string to use */
  uint8 MethodSize;                                       /**< Size of the method value */
  P2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) CsmJobPtr;/**< CsmJod to use */
}Scc_XmlSecSignatureConfigStructType;

typedef struct {
  Scc_XmlSecDigestConfigStructType DigestCfg;                 /**< Configuration data related to digest */
  Scc_XmlSecSignatureConfigStructType SignatureCfg;           /**< Configuration data related to signature */
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) SignatureBufferPtr;  /**< Pointer where to store the generated signature */
  uint16 SignatureBufferPtrLen;                               /**< Size of the signature buffer */
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) ExiStreamBufferPtr;  /**< Pointer to the exi stream buffer that is going to be used */
  uint16 ExiStreamBufferPtrLen;                               /**< Size of the exi stream buffer */
  Scc_DetailedErrorEnumType DetailedErrorInit;                /**< Error code to use in case XmlSecurity_SigGenWS_Init fails */
  Scc_DetailedErrorEnumType DetailedErrorSetDigest;           /**< Error code to use in case XmlSecurity_SigGenWS_SetDigestMethod fails */
  Scc_DetailedErrorEnumType DetailedErrorSetSignatureMethod;  /**< Error code to use in case XmlSecurity_SigGenWS_SetSignatureMethod fails */
  Scc_DetailedErrorEnumType DetailedErrorSetExiBuffer;        /**< Error code to use in case XmlSecurity_SigGenWS_SetExiStreamBuffer fails */
}Scc_XmlSecSigGenConfigStructType;
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#endif /* SCC_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_Types.h
 *********************************************************************************************************************/

