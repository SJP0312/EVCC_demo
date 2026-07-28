/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: TcpIp
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: TcpIp_Lcfg.c
 *   Generation Time: 2025-09-11 13:39:34
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/


/* PRQA S 0828 EOF */ /* MD_MSR_1.1_828 */
/* PRQA S 1257 EOF */ /* MD_CSL_Rule10.3_OldValidLib */

/*lint -e552 */

#define TCPIP_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TcpIp_Lcfg.h"
#include "TcpIp_Cfg.h"
#include "TcpIp.h"
#include "Det.h"
#include "KeyM_Cfg.h"
#include "_Appl_Rand.h" 
#include "Appl_Tls_KeyM.h" 
#include "Scc_Cbk.h" 


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if defined (STATIC)
#else
# define STATIC static
#endif

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
#define TCPIP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

TCPIP_P2C(TcpIp_ConfigType) TcpIp_ConfigDataPtr = NULL_PTR;

#define TCPIP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 0612 OBJECT_SIZE */ /* MD_TcpIp_0612_BufferSize */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  TcpIp_ApplicationIds
**********************************************************************************************************************/
/** 
  \var    TcpIp_ApplicationIds
  \brief  Ids of the applications used for TcpIp
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_OsApplicationType, TCPIP_CONST) TcpIp_ApplicationIds[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ApplicationIds           */
  /*     0 */ TCPIP_SINGLECORE_APPLID 
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_CsmJobId
**********************************************************************************************************************/
/** 
  \var    TcpIp_CsmJobId
  \brief  Configured CSM Job IDs
*/ 
#define TCPIP_START_SEC_CONST_32
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_CsmJobIdType, TCPIP_CONST) TcpIp_CsmJobId[19] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CsmJobId                                                             Referable Keys */
  /*     0 */ CsmConf_CsmJob_CsmJob_TlsConn1_HS_DhSignatureGenerate_Secp521r1 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn1_HS_DhSignatureGenerate_Secp521r1] */
  /*     1 */ CsmConf_CsmJob_CsmJob_Tls_Conn1_HashSha384                      ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha384] */
  /*     2 */ CsmConf_CsmJob_CsmJob_Tls_Hkdf_Sha384                           ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha384] */
  /*     3 */ CsmConf_CsmJob_CsmJob_Tls_Hkdf_Sha384Expand                     ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha384Expand] */
  /*     4 */ CsmConf_CsmJob_CsmJob_TlsConn1_HS_DhSignatureGenerate_Secp521r1 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn1_HS_DhSignatureGenerate_Secp521r1] */
  /*     5 */ CsmConf_CsmJob_CsmJob_Tls_Conn1_HashSha256_Finished             ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha256_Finished] */
  /*     6 */ CsmConf_CsmJob_CsmJob_Tls_Hkdf_Sha256                           ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha256] */
  /*     7 */ CsmConf_CsmJob_CsmJob_Tls_Hkdf_Sha256Expand                     ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha256Expand] */
  /*     8 */ CsmConf_CsmJob_CsmJob_Tls_Conn0_HS_DhSignatureGenerate          ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_DhSignatureGenerate] */
  /*     9 */ CsmConf_CsmJob_CsmJob_Tls_Conn0_HMacSha256_Verify               ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha256_Verify] */
  /*    10 */ CsmConf_CsmJob_CsmJob_Tls_Conn0_HMacSha256_Generate             ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha256_Generate] */
  /*    11 */ CsmConf_CsmJob_CsmJob_Tls_Conn0_Aes128Cbc_Decrypt               ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Aes128Cbc_Decrypt] */
  /*    12 */ CsmConf_CsmJob_CsmJob_Tls_Conn0_Aes128Cbc_Encrypt               ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Aes128Cbc_Encrypt] */
  /*    13 */ CsmConf_CsmJob_CsmJob_HmacSha256Generate_1                      ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_HmacSha256Generate_1] */
  /*    14 */ CsmConf_CsmJob_CsmJob_Tls_Conn1_ChaCha20_Decrypt                ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_ChaCha20_Decrypt] */
  /*    15 */ CsmConf_CsmJob_CsmJob_Tls_Conn1_ChaCha20_Encrypt                ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_ChaCha20_Encrypt] */
  /*    16 */ CsmConf_CsmJob_CsmJob_Tls_HmacSha384Generate_1                  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_HmacSha384Generate_1] */
  /*    17 */ CsmConf_CsmJob_CsmJob_Tls_Conn1_Aes256Gcm_Decrypt_1             ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Aes256Gcm_Decrypt_1] */
  /*    18 */ CsmConf_CsmJob_CsmJob_Tls_Conn1_Aes256Gcm_Encrypt_1                /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Aes256Gcm_Encrypt_1] */
};
#define TCPIP_STOP_SEC_CONST_32
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_CsmKeyId
**********************************************************************************************************************/
/** 
  \var    TcpIp_CsmKeyId
  \brief  Configured CSM Key IDs
*/ 
#define TCPIP_START_SEC_CONST_32
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_CsmKeyIdType, TCPIP_CONST) TcpIp_CsmKeyId[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CsmKeyId                                                       Referable Keys */
  /*     0 */ CsmConf_CsmKey_CsmKey_Tls_Conn1_MasterSecret              ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_MasterSecret] */
  /*     1 */ CsmConf_CsmKey_CsmKey_TlsConn1_HS_DhKeyExchange_Secp521r1 ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_TlsConn1_HS_DhKeyExchange_Secp521r1] */
  /*     2 */ CsmConf_CsmKey_CsmKey_Tls_Hkdf_DerivedSecret              ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_DerivedSecret] */
  /*     3 */ CsmConf_CsmKey_CsmKey_Hkdf_Sha384                         ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Hkdf_Sha384] */
  /*     4 */ CsmConf_CsmKey_CsmKey_Tls_Hkdf_ServerAdHsTrafficSecret    ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_ServerAdHsTrafficSecret] */
  /*     5 */ CsmConf_CsmKey_CsmKey_Tls_Hkdf_ClientAdHsTrafficSecret    ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_ClientAdHsTrafficSecret] */
  /*     6 */ CsmConf_CsmKey_CsmKey_Tls_Hkdf_TmpBuffer                  ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_TmpBuffer] */
  /*     7 */ CsmConf_CsmKey_CsmKey_Tls_Hkdf_Sha384ExpandIn             ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_Sha384ExpandIn] */
  /*     8 */ CsmConf_CsmKey_CsmKey_Tls_Hkdf_Sha384ExpandOut            ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_Sha384ExpandOut] */
  /*     9 */ CsmConf_CsmKey_CsmKey_Tls_Conn1_MasterSecret              ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_MasterSecret] */
  /*    10 */ CsmConf_CsmKey_CsmKey_TlsConn1_HS_DhKeyExchange_Secp521r1 ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_TlsConn1_HS_DhKeyExchange_Secp521r1] */
  /*    11 */ CsmConf_CsmKey_CsmKey_Tls_Hkdf_DerivedSecret              ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_DerivedSecret] */
  /*    12 */ CsmConf_CsmKey_CsmKey_Hkdf_Sha256                         ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Hkdf_Sha256] */
  /*    13 */ CsmConf_CsmKey_CsmKey_Tls_Hkdf_ServerAdHsTrafficSecret    ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_ServerAdHsTrafficSecret] */
  /*    14 */ CsmConf_CsmKey_CsmKey_Tls_Hkdf_ClientAdHsTrafficSecret    ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_ClientAdHsTrafficSecret] */
  /*    15 */ CsmConf_CsmKey_CsmKey_Tls_Hkdf_TmpBuffer                  ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_TmpBuffer] */
  /*    16 */ CsmConf_CsmKey_CsmKey_Tls_Hkdf_Sha256ExpandIn             ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_Sha256ExpandIn] */
  /*    17 */ CsmConf_CsmKey_CsmKey_Tls_Hkdf_Sha256ExpandOut            ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_Sha256ExpandOut] */
  /*    18 */ CsmConf_CsmKey_CsmKey_Tls_Conn0_MasterSecret              ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_MasterSecret] */
  /*    19 */ CsmConf_CsmKey_CsmKey_Tls_Conn0_HS_DhKeyExchange          ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_HS_DhKeyExchange] */
  /*    20 */ CsmConf_CsmKey_CsmKey_Tls_ChaCha20_PassiveDecrypt         ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_ChaCha20_PassiveDecrypt] */
  /*    21 */ CsmConf_CsmKey_CsmKey_Tls_ChaCha20_PassiveEncrypt         ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_ChaCha20_PassiveEncrypt] */
  /*    22 */ CsmConf_CsmKey_CsmKey_Tls_Conn1_Aes256GcmPassiveDecrypt   ,  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_Aes256GcmPassiveDecrypt] */
  /*    23 */ CsmConf_CsmKey_CsmKey_Tls_Conn1_Aes256GcmPassiveEncrypt      /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_Aes256GcmPassiveEncrypt] */
};
#define TCPIP_STOP_SEC_CONST_32
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_DuplicateAddrDetectionFctPtr
**********************************************************************************************************************/
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_DuplicateAddrDetectionCbkType, TCPIP_CONST) TcpIp_DuplicateAddrDetectionFctPtr = NULL_PTR;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_EthIfCtrl
**********************************************************************************************************************/
/** 
  \var    TcpIp_EthIfCtrl
  \brief  Array mapping from EthIfCtrlIdx to IpCtrlIdx
  \details
  Element        Description
  IpV6CtrlIdx    the index of the 0:1 relation pointing to TcpIp_IpV6Ctrl
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_EthIfCtrlType, TCPIP_CONST) TcpIp_EthIfCtrl[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpV6CtrlIdx */
  { /*     0 */          0u }
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_IcmpV6Config
**********************************************************************************************************************/
/** 
  \var    TcpIp_IcmpV6Config
  \details
  Element           Description
  EchoRequestApi    Enable Echo Request API - Value of configuration parameter TcpIpIcmpV6EchoRequestApiEnabled [BOOLEAN]
  HopLimit          Hop Limit - Value of configuration parameter TcpIpIcmpV6HopLimit
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_IcmpV6ConfigType, TCPIP_CONST) TcpIp_IcmpV6Config[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    EchoRequestApi  HopLimit */
  { /*     0 */          FALSE,      64u }
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_IcmpV6MsgHandlerCbkFctPtr
**********************************************************************************************************************/
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_IcmpMultiPartMsgHandlerCbkType, TCPIP_CONST) TcpIp_IcmpV6MsgHandlerCbkFctPtr = NULL_PTR;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_IpV6Ctrl
**********************************************************************************************************************/
/** 
  \var    TcpIp_IpV6Ctrl
  \details
  Element                               Description
  DefaultLinkMtu                        Default Mtu Size - Value of configuration parameter TcpIpIpV6DefaultMtuSize
  MaskedBits                            contains bitcoded the boolean data of TcpIp_AllowLinkMtuReconfigurationOfIpV6Ctrl, TcpIp_DiscardUnknownExtHdrPacketOfIpV6Ctrl, TcpIp_EnableDynHopLimitOfIpV6Ctrl, TcpIp_EnablePathMtuOfIpV6Ctrl, TcpIp_HwChecksumIcmpOfIpV6Ctrl, TcpIp_HwChecksumIpDestinationOptionsOfIpV6Ctrl, TcpIp_HwChecksumIpHopByHopOptionsOfIpV6Ctrl, TcpIp_HwChecksumIpRoutingOfIpV6Ctrl, TcpIp_HwChecksumTcpOfIpV6Ctrl, TcpIp_HwChecksumUdpOfIpV6Ctrl
  PathMtuTimeout                        Path Mtu Timeout - Value of configuration parameter TcpIpIpV6PathMtuTimeout [SECONDS]
  DefaultHopLimit                       Default Hop Limit - Value of configuration parameter TcpIpIpV6DefaultHopLimit
  DefaultTrafficClassFlowLabelNbo       -
  DhcpMode                              -
  DhcpUserOptionEndIdx                  the end index of the 0:n relation pointing to TcpIp_DhcpUserOption
  DhcpUserOptionStartIdx                the start index of the 0:n relation pointing to TcpIp_DhcpUserOption
  EthIfCtrlIdx                          -
  FramePrioDefault                      IP Frame Prio Default - Value of configuration parameter TcpIpIpFramePrioDefault
  InterfaceIdentifierEndIdx             the end index of the 1:n relation pointing to TcpIp_InterfaceIdentifier
  InterfaceIdentifierStartIdx           the start index of the 1:n relation pointing to TcpIp_InterfaceIdentifier
  IpV6DefaultRouterListEntryEndIdx      the end index of the 1:n relation pointing to TcpIp_IpV6DefaultRouterListEntry
  IpV6DefaultRouterListEntryStartIdx    the start index of the 1:n relation pointing to TcpIp_IpV6DefaultRouterListEntry
  IpV6DestinationCacheEntryEndIdx       the end index of the 1:n relation pointing to TcpIp_IpV6DestinationCacheEntry
  IpV6DestinationCacheEntryStartIdx     the start index of the 1:n relation pointing to TcpIp_IpV6DestinationCacheEntry
  IpV6EthBufDataEndIdx                  the end index of the 1:n relation pointing to TcpIp_IpV6EthBufData
  IpV6EthBufDataStartIdx                the start index of the 1:n relation pointing to TcpIp_IpV6EthBufData
  IpV6MulticastAddrEndIdx               the end index of the 0:n relation pointing to TcpIp_IpV6MulticastAddr
  IpV6MulticastAddrStartIdx             the start index of the 0:n relation pointing to TcpIp_IpV6MulticastAddr
  IpV6NeighborCacheEntryEndIdx          the end index of the 1:n relation pointing to TcpIp_IpV6NeighborCacheEntry
  IpV6NeighborCacheEntryStartIdx        the start index of the 1:n relation pointing to TcpIp_IpV6NeighborCacheEntry
  IpV6PrefixListEntryEndIdx             the end index of the 1:n relation pointing to TcpIp_IpV6PrefixListEntry
  IpV6PrefixListEntryStartIdx           the start index of the 1:n relation pointing to TcpIp_IpV6PrefixListEntry
  IpV6SourceAddressEndIdx               the end index of the 1:n relation pointing to TcpIp_IpV6SourceAddress
  IpV6SourceAddressStartIdx             the start index of the 1:n relation pointing to TcpIp_IpV6SourceAddress
  LocalAddrV6BcIdx                      the index of the 0:1 relation pointing to TcpIp_LocalAddrV6
  NdpConfigIdx                          the index of the 1:1 relation pointing to TcpIp_NdpConfig
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_IpV6CtrlType, TCPIP_CONST) TcpIp_IpV6Ctrl[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DefaultLinkMtu  MaskedBits  PathMtuTimeout  DefaultHopLimit  DefaultTrafficClassFlowLabelNbo  DhcpMode                   DhcpUserOptionEndIdx                     DhcpUserOptionStartIdx                     EthIfCtrlIdx                               FramePrioDefault  InterfaceIdentifierEndIdx  InterfaceIdentifierStartIdx  IpV6DefaultRouterListEntryEndIdx  IpV6DefaultRouterListEntryStartIdx  IpV6DestinationCacheEntryEndIdx  IpV6DestinationCacheEntryStartIdx  IpV6EthBufDataEndIdx  IpV6EthBufDataStartIdx  IpV6MulticastAddrEndIdx                     IpV6MulticastAddrStartIdx                     IpV6NeighborCacheEntryEndIdx  IpV6NeighborCacheEntryStartIdx  IpV6PrefixListEntryEndIdx  IpV6PrefixListEntryStartIdx  IpV6SourceAddressEndIdx  IpV6SourceAddressStartIdx  LocalAddrV6BcIdx  NdpConfigIdx        Referable Keys */
  { /*     0 */          1500u,    0x0080u,           600u,             64u,                           0x00u, IPV6_DHCPV6_MODE_DISABLED, TCPIP_NO_DHCPUSEROPTIONENDIDXOFIPV6CTRL, TCPIP_NO_DHCPUSEROPTIONSTARTIDXOFIPV6CTRL, EthIfConf_EthIfController_EthIfController,               0u,                       64u,                          0u,                               2u,                                 0u,                              5u,                                0u,                   2u,                     0u, TCPIP_NO_IPV6MULTICASTADDRENDIDXOFIPV6CTRL, TCPIP_NO_IPV6MULTICASTADDRSTARTIDXOFIPV6CTRL,                           5u,                             0u,                        5u,                          0u,                      1u,                        0u,               1u,           0u }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpCtrl] */
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_IpV6General
**********************************************************************************************************************/
/** 
  \var    TcpIp_IpV6General
  \details
  Element                         Description
  ExtDestAddrValidationEnabled    IPv6 Extended Dest Addr Validation Enabled - Value of configuration parameter TcpIpIpV6ExtendedDestAddrValidationEnabled [BOOLEAN]
  IpV6CtrlDefaultIdx              the index of the 0:1 relation pointing to TcpIp_IpV6Ctrl
  IpV6SocketDynIcmpIdx            the index of the 1:1 relation pointing to TcpIp_IpV6SocketDyn
  IpV6SocketDynNdpIdx             the index of the 1:1 relation pointing to TcpIp_IpV6SocketDyn
  IpV6SocketDynTcpRstIdx          the index of the 0:1 relation pointing to TcpIp_IpV6SocketDyn
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_IpV6GeneralType, TCPIP_CONST) TcpIp_IpV6General[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ExtDestAddrValidationEnabled  IpV6CtrlDefaultIdx                        IpV6SocketDynIcmpIdx  IpV6SocketDynNdpIdx  IpV6SocketDynTcpRstIdx */
  { /*     0 */                        FALSE, TCPIP_NO_IPV6CTRLDEFAULTIDXOFIPV6GENERAL,                   5u,                  6u,                     4u }
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_IpV6SourceAddress
**********************************************************************************************************************/
/** 
  \var    TcpIp_IpV6SourceAddress
  \brief  Structure containing all statically configured IP address information.
  \details
  Element                 Description
  PrefixIsOnLink          Indicates whether all addresses using the same prefix as this address shall be handled as on-link.
  AddressAssignVariant    Ip address configuration source.
  DefaultAddrV6Idx        the index of the 0:1 relation pointing to TcpIp_DefaultAddrV6
  LocalAddrV6Idx          the index of the 1:1 relation pointing to TcpIp_LocalAddrV6
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_IpV6SourceAddressType, TCPIP_CONST) TcpIp_IpV6SourceAddress[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PrefixIsOnLink  AddressAssignVariant               DefaultAddrV6Idx                              LocalAddrV6Idx        Referable Keys */
  { /*     0 */          FALSE, TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL, TCPIP_NO_DEFAULTADDRV6IDXOFIPV6SOURCEADDRESS,             0u }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpV6LocalAddr_TcpIpCtrl_LinkLocal, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpCtrl/TcpIpIpVXCtrl/TcpIpIpV6Ctrl] */
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_LocalAddrV6
**********************************************************************************************************************/
/** 
  \var    TcpIp_LocalAddrV6
  \brief  -
  \details
  Element                     Description
  AddressAssignmentTrigger    Assignment trigger of the address
  IpV6CtrlIdx                 the index of the 1:1 relation pointing to TcpIp_IpV6Ctrl
  IpV6MulticastAddrIdx        the index of the 0:1 relation pointing to TcpIp_IpV6MulticastAddr
  IpV6SourceAddressIdx        the index of the 0:1 relation pointing to TcpIp_IpV6SourceAddress
  StaticDefaultRouterIdx      the index of the 0:1 relation pointing to TcpIp_StaticDefaultRouter
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_LocalAddrV6Type, TCPIP_CONST) TcpIp_LocalAddrV6[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    AddressAssignmentTrigger  IpV6CtrlIdx  IpV6MulticastAddrIdx                        IpV6SourceAddressIdx                        StaticDefaultRouterIdx                              Referable Keys */
  { /*     0 */ TCPIP_AUTOMATIC         ,          0u, TCPIP_NO_IPV6MULTICASTADDRIDXOFLOCALADDRV6,                                         0u, TCPIP_NO_STATICDEFAULTROUTERIDXOFLOCALADDRV6 },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpV6LocalAddr_TcpIpCtrl_LinkLocal, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpCtrl/TcpIpIpVXCtrl/TcpIpIpV6Ctrl] */
  { /*     1 */ TCPIP_AUTOMATIC         ,          0u, TCPIP_NO_IPV6MULTICASTADDRIDXOFLOCALADDRV6, TCPIP_NO_IPV6SOURCEADDRESSIDXOFLOCALADDRV6, TCPIP_NO_STATICDEFAULTROUTERIDXOFLOCALADDRV6 }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpV6LocalAddr_TcpIpCtrl_AsAn, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpCtrl/TcpIpIpVXCtrl/TcpIpIpV6Ctrl] */
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_NdpConfig
**********************************************************************************************************************/
/** 
  \var    TcpIp_NdpConfig
  \details
  Element                    Description
  MaskedBits                 contains bitcoded the boolean data of TcpIp_DropRedirectOfNdpConfig, TcpIp_DropRouterAdvertisementOfNdpConfig, TcpIp_DynamicReachableTimeOfNdpConfig, TcpIp_DynamicRetransTimerOfNdpConfig, TcpIp_EnableNdpInvNaOfNdpConfig, TcpIp_EnableNdpInvNaNcUpdateOfNdpConfig, TcpIp_EnableNdpInvNsOfNdpConfig, TcpIp_EnableNudOfNdpConfig, TcpIp_EnableOptimisticDadOfNdpConfig, TcpIp_EnableRfc6106DnsslOptOfNdpConfig, TcpIp_EnableRfc6106RdnssOptOfNdpConfig, TcpIp_EnableSlaacDelayOfNdpConfig, TcpIp_RandomReachableTimeOfNdpConfig, TcpIp_RndRtrSolicitationDelayOfNdpConfig
  MaxRtrSolicitationDelay    Max Rtr Solicitation Delay - Value of configuration parameter TcpIpNdpMaxRtrSolicitationDelay [MILLISECONDS]
  MaxSlaacDelay              Max address configuration delay - Value of configuration parameter TcpIpNdpSlaacMaxDelay [MILLISECONDS]
  NudFirstProbeDelay         Delay First Probe Time - Value of configuration parameter TcpIpNdpDelayFirstProbeTime [MILLISECONDS]
  ReachableTime              Default Reachable Time - Value of configuration parameter TcpIpNdpDefaultReachableTime [MILLISECONDS]
  RtrSolicitationInterval    Rtr Solicitation Interval - Value of configuration parameter TcpIpNdpRtrSolicitationInterval [MILLISECONDS]
  SlaacMinLifetime           Minimum Address Lifetime - Value of configuration parameter TcpIpNdpSlaacMinLifetime [SECONDS]
  DadTransmits               DAD Number Of Transmissions - Value of configuration parameter TcpIpNdpSlaacDadNumberOfTransmissions
  MaxRandomFactor            Max Random Factor - Value of configuration parameter TcpIpNdpMaxRandomFactor
  MaxRtrSolicitations        Max Rtr Solicitations - Value of configuration parameter TcpIpNdpMaxRtrSolicitations
  MinRandomFactor            Min Random Factor - Value of configuration parameter TcpIpNdpMinRandomFactor
  MulticastSolicits          Num Multicast Solicitations - Value of configuration parameter TcpIpNdpNumMulticastSolicitations
  RetransTimer               Default Retrans Timer - Value of configuration parameter TcpIpNdpDefaultRetransTimer [MILLISECONDS]
  UnicastSolicits            Num Unicast Solicitations - Value of configuration parameter TcpIpNdpNumUnicastSolicitations
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_NdpConfigType, TCPIP_CONST) TcpIp_NdpConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MaskedBits  MaxRtrSolicitationDelay  MaxSlaacDelay  NudFirstProbeDelay  ReachableTime  RtrSolicitationInterval  SlaacMinLifetime  DadTransmits  MaxRandomFactor  MaxRtrSolicitations  MinRandomFactor  MulticastSolicits  RetransTimer  UnicastSolicits        Referable Keys */
  { /*     0 */    0x0D43u,                   1000u,         1000u,              5000u,        30000u,                   4000u,            7200u,           1u,             15u,                  3u,              5u,                3u,         250u,              3u }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpIpConfig/TcpIpIpV6Config/TcpIpNdpConfig] */
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_RandomNumberFctPtr
**********************************************************************************************************************/
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_GetRandomNumberType, TCPIP_CONST) TcpIp_RandomNumberFctPtr = Appl_Crypto_GetRandNo;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_SocketOwnerConfig
**********************************************************************************************************************/
/** 
  \var    TcpIp_SocketOwnerConfig
  \brief  -
  \details
  Element                            Description
  CopyTxDataDynFuncPtr               [User]_CopyTxDataDyn Callback Function. (only required if socket owner uses indirect data provision in Tcp/UdpTransmit.)
  CopyTxDataFuncPtr                  [User]_CopyTxData Callback Function. (only required if socket owner uses indirect data provision in Tcp/UdpTransmit.)
  DhcpEventFuncPtr                   Callout triggered on reception and transmission of client DHCP messages.
  LocalIpAddrAssignmentChgFuncPtr    -
  RxIndicationFuncPtr                [User]_RxIndication Callback Function. (required for socket owner that receives packets.)
  TcpAcceptedFuncPtr                 [User]_TcpAccepted Callback Function. (only required if socket passively accepts TCP connections.)
  TcpConnectedFuncPtr                [User]_TcpConnected Callback Function. (only required if socket owner actively opens TCP connections.)
  TcpIpEventFuncPtr                  [User]_TcpIpEvent Callback Function. (required for every socket owner)
  TlsCertRequestFuncPtr              [User]_TlsCertRequest Callback Function.
  TlsChangeableCipherFuncPtr         [User]_TlsChangeableCipher Callback Function.
  TlsSessionTicketUpdateFuncPtr      [User]_TlsSessionTicketUpdate Callback Function.
  TlsValidationResultFuncPtr         [User]_TlsValidationResult Callback Function.
  TxConfirmationFuncPtr              [User]_TxConfirmation Callback Function. (optional for every socket owner)
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_SocketOwnerConfigType, TCPIP_CONST) TcpIp_SocketOwnerConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CopyTxDataDynFuncPtr  CopyTxDataFuncPtr  DhcpEventFuncPtr  LocalIpAddrAssignmentChgFuncPtr     RxIndicationFuncPtr      TcpAcceptedFuncPtr  TcpConnectedFuncPtr      TcpIpEventFuncPtr    TlsCertRequestFuncPtr                    TlsChangeableCipherFuncPtr    TlsSessionTicketUpdateFuncPtr  TlsValidationResultFuncPtr  TxConfirmationFuncPtr */
  { /*     0 */ Scc_Cbk_CopyTxData  , NULL_PTR         , NULL_PTR        , Scc_Cbk_IP_AddressAssignmentChange, Scc_Cbk_TL_RxIndication, NULL_PTR          , Scc_Cbk_TL_TCPConnected, Scc_Cbk_TL_TCPEvent, Scc_Cbk_TLS_ClientAuthenticationRequest, Scc_Cbk_TLS_ChangeableCipher, NULL_PTR                     , Scc_Cbk_TLS_CertChain     , NULL_PTR              }
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TcpConfig
**********************************************************************************************************************/
/** 
  \var    TcpIp_TcpConfig
  \details
  Element                    Description
  KeepAliveTime              Keep Alive Time - Value of configuration parameter TcpIpTcpKeepAliveTime [MAIN_FUNCTION_CYCLES]
  FinWait2Timeout            FIN Wait 2 Timeout - Value of configuration parameter TcpIpTcpFinWait2Timeout [MAIN_FUNCTION_CYCLES]
  PortMax                    Tcp Dynamic Port Max - Value of configuration parameter TcpIpTcpPortMax
  PortMin                    Tcp Dynamic Port Min - Value of configuration parameter TcpIpTcpPortMin
  RxMss                      maximum payload size of received TCP segments.
  TxMss                      maximum payload size of transmitted TCP segments.
  UserTimeoutDefCycles       User Timeout Def - Value of configuration parameter TcpIpTcpUserTimeoutDef [MAIN_FUNCTION_CYCLES]
  NoRstInvSocket             No RST on Invalid Socket - Value of configuration parameter TcpIpTcpNoRstInvSocket [BOOLEAN]
  KeepAliveInterval          Keep Alive Interval - Value of configuration parameter TcpIpTcpKeepAliveInterval [MAIN_FUNCTION_CYCLES]
  KeepAliveProbesMax         Keep Alive Probes Max - Value of configuration parameter TcpIpTcpKeepAliveProbesMax
  Msl                        Maximum Segment Lifetime (MSL) - Value of configuration parameter TcpIpTcpMsl [MAIN_FUNCTION_CYCLES]
  NagleTimeout               Nagle Timeout - Value of configuration parameter TcpIpTcpNagleTimeout [MAIN_FUNCTION_CYCLES]
  RetransTimeout             Retransmission Timeout - Value of configuration parameter TcpIpTcpRetransmissionTimeout [MAIN_FUNCTION_CYCLES]
  RetransTimeoutMax          Retransmission Timeout Max - Value of configuration parameter TcpIpTcpRetransmissionTimeoutMax [MAIN_FUNCTION_CYCLES]
  TcpOooQSizePerSocketAvg    Avg Num Out Of Order Segments per Socket - Value of configuration parameter TcpIpTcpAvgNumOooSegsPerSocket
  TcpOooQSizePerSocketMax    Max Num Out Of Order Segments per Socket - Value of configuration parameter TcpIpTcpMaxNumOooSegsPerSocket
  TcpRetryQSize              Average Tx Retry Queue Size - Value of configuration parameter TcpIpTcpTxRetryQueueSize
  TimeToLiveDefault          Time-To-Live (TTL) - Value of configuration parameter TcpIpTcpTtl
  UserTimeoutMaxCycles       User Timeout Max - Value of configuration parameter TcpIpTcpUserTimeoutMax [MAIN_FUNCTION_CYCLES]
  UserTimeoutMinCycles       User Timeout Min - Value of configuration parameter TcpIpTcpUserTimeoutMin [MAIN_FUNCTION_CYCLES]
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_TcpConfigType, TCPIP_CONST) TcpIp_TcpConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    KeepAliveTime  FinWait2Timeout  PortMax  PortMin  RxMss  TxMss  UserTimeoutDefCycles  NoRstInvSocket  KeepAliveInterval  KeepAliveProbesMax  Msl  NagleTimeout  RetransTimeout  RetransTimeoutMax  TcpOooQSizePerSocketAvg  TcpOooQSizePerSocketMax  TcpRetryQSize  TimeToLiveDefault  UserTimeoutMaxCycles                      UserTimeoutMinCycles                     */
  { /*     0 */       720000u,          12000u,  65535u,  49152u, 1460u, 1460u,                2000u,          FALSE,                0u,                 0u, 25u,           0u,            10u,              100u,                      5u,                      5u,           10u,               64u, TCPIP_NO_USERTIMEOUTMAXCYCLESOFTCPCONFIG, TCPIP_NO_USERTIMEOUTMINCYCLESOFTCPCONFIG }
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TcpRstHandling
**********************************************************************************************************************/
/** 
  \var    TcpIp_TcpRstHandling
  \details
  Element                     Description
  RstTxQueueBufferEndIdx      the end index of the 1:n relation pointing to TcpIp_RstTxQueueBuffer
  RstTxQueueBufferStartIdx    the start index of the 1:n relation pointing to TcpIp_RstTxQueueBuffer
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_TcpRstHandlingType, TCPIP_CONST) TcpIp_TcpRstHandling[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RstTxQueueBufferEndIdx  RstTxQueueBufferStartIdx */
  { /*     0 */                     8u,                       0u }
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TcpRxBufferDesc
**********************************************************************************************************************/
/** 
  \var    TcpIp_TcpRxBufferDesc
  \brief  TCP RX buffer descriptors
  \details
  Element                Description
  TcpRxBufferEndIdx      the end index of the 1:n relation pointing to TcpIp_TcpRxBuffer
  TcpRxBufferStartIdx    the start index of the 1:n relation pointing to TcpIp_TcpRxBuffer
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_TcpRxBufferDescType, TCPIP_CONST) TcpIp_TcpRxBufferDesc[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TcpRxBufferEndIdx  TcpRxBufferStartIdx */
  { /*     0 */             7600u,                  0u },
  { /*     1 */            17600u,               7600u },
  { /*     2 */            28850u,              17600u }
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TcpTxBufferDesc
**********************************************************************************************************************/
/** 
  \var    TcpIp_TcpTxBufferDesc
  \brief  TCP TX buffer descriptors
  \details
  Element                Description
  TcpTxBufferEndIdx      the end index of the 1:n relation pointing to TcpIp_TcpTxBuffer
  TcpTxBufferStartIdx    the start index of the 1:n relation pointing to TcpIp_TcpTxBuffer
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_TcpTxBufferDescType, TCPIP_CONST) TcpIp_TcpTxBufferDesc[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TcpTxBufferEndIdx  TcpTxBufferStartIdx */
  { /*     0 */             8380u,                  0u },
  { /*     1 */            16827u,               8380u },
  { /*     2 */            26827u,              16827u }
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsBufferMgmt
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsBufferMgmt
  \details
  Element                    Description
  TlsBufferRxAdHsEndIdx      the end index of the 1:n relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxAdHsLength      the number of relations pointing to TcpIp_TlsBufferRx
  TlsBufferRxAdHsStartIdx    the start index of the 1:n relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxAlEndIdx        the end index of the 1:n relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxAlStartIdx      the start index of the 1:n relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxCcsEndIdx       the end index of the 1:n relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxCcsStartIdx     the start index of the 1:n relation pointing to TcpIp_TlsBufferRx
  TlsBufferTxAdHsEndIdx      the end index of the 1:n relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxAdHsLength      the number of relations pointing to TcpIp_TlsBufferTx
  TlsBufferTxAdHsStartIdx    the start index of the 1:n relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxAlEndIdx        the end index of the 1:n relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxAlStartIdx      the start index of the 1:n relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxCcsEndIdx       the end index of the 1:n relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxCcsStartIdx     the start index of the 1:n relation pointing to TcpIp_TlsBufferTx
  RxBufStructMgtIdx          the index of the 1:1 relation pointing to TcpIp_RxBufStructMgt
  RxBufStructSegEndIdx       the end index of the 1:n relation pointing to TcpIp_RxBufStructSeg
  RxBufStructSegStartIdx     the start index of the 1:n relation pointing to TcpIp_RxBufStructSeg
  TlsBufferRxAlLength        the number of relations pointing to TcpIp_TlsBufferRx
  TlsBufferRxCcsLength       the number of relations pointing to TcpIp_TlsBufferRx
  TlsBufferTxAlLength        the number of relations pointing to TcpIp_TlsBufferTx
  TlsBufferTxCcsLength       the number of relations pointing to TcpIp_TlsBufferTx
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_TlsBufferMgmtType, TCPIP_CONST) TcpIp_TlsBufferMgmt[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TlsBufferRxAdHsEndIdx  TlsBufferRxAdHsLength  TlsBufferRxAdHsStartIdx  TlsBufferRxAlEndIdx  TlsBufferRxAlStartIdx  TlsBufferRxCcsEndIdx  TlsBufferRxCcsStartIdx  TlsBufferTxAdHsEndIdx  TlsBufferTxAdHsLength  TlsBufferTxAdHsStartIdx  TlsBufferTxAlEndIdx  TlsBufferTxAlStartIdx  TlsBufferTxCcsEndIdx  TlsBufferTxCcsStartIdx  RxBufStructMgtIdx  RxBufStructSegEndIdx  RxBufStructSegStartIdx  TlsBufferRxAlLength  TlsBufferRxCcsLength  TlsBufferTxAlLength  TlsBufferTxCcsLength        Referable Keys */
  { /*     0 */                 7729u,                 7729u,                      0u,               7859u,                 7729u,                7861u,                  7859u,                 8448u,                 8448u,                      0u,               8451u,                 8448u,                8452u,                  8451u,                0u,                   2u,                     0u,                130u,                   2u,                  3u,                   1u }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsCertId
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsCertId
  \brief  Used TLS certificate IDs of root certificates. Used for trusted ca indication extension.
*/ 
#define TCPIP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_TlsCertIdType, TCPIP_CONST) TcpIp_TlsCertId[13] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TlsCertId                                                      Referable Keys */
  /*     0 */  KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_10,  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*     1 */    KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2GRoot_0,  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*     2 */   KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_9,  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*     3 */   KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_5,  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*     4 */   KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_8,  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*     5 */   KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_1,  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*     6 */   KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_4,  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*     7 */   KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_7,  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*     8 */   KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_3,  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*     9 */   KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_6,  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*    10 */   KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_2,  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*    11 */    KeyMConf_KeyMCertificate_SccCertificate_ISO20_V2GRoot_1,  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*    12 */    KeyMConf_KeyMCertificate_SccCertificate_ISO20_V2GRoot_0   /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
};
#define TCPIP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsCipherDefinition
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsCipherDefinition
  \details
  Element              Description
  CipherSuiteId    
  CipherSuiteUsePsk
  TlsVersion       
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_TlsCipherDefinitionType, TCPIP_CONST) TcpIp_TlsCipherDefinition[16] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CipherSuiteId  CipherSuiteUsePsk  TlsVersion                 Referable Keys */
  { /*     0 */           44u,              TRUE, TCPIP_TLSVERSION_12 },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TLS_PSK_WITH_NULL_SHA] */
  { /*     1 */          140u,              TRUE, TCPIP_TLSVERSION_12 },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TLS_PSK_WITH_AES_128_CBC_SHA] */
  { /*     2 */          168u,              TRUE, TCPIP_TLSVERSION_12 },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TLS_PSK_WITH_AES_128_GCM_SHA256] */
  { /*     3 */          174u,              TRUE, TCPIP_TLSVERSION_12 },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TLS_PSK_WITH_AES_128_CBC_SHA256] */
  { /*     4 */          176u,              TRUE, TCPIP_TLSVERSION_12 },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TLS_PSK_WITH_NULL_SHA256] */
  { /*     5 */         4865u,             FALSE, TCPIP_TLSVERSION_13 },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TLS_AES_128_GCM_SHA256] */
  { /*     6 */         4866u,             FALSE, TCPIP_TLSVERSION_13 },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TLS_AES_256_GCM_SHA384] */
  { /*     7 */         4867u,             FALSE, TCPIP_TLSVERSION_13 },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TLS_CHACHA20_POLY1305_SHA256] */
  { /*     8 */        49153u,             FALSE, TCPIP_TLSVERSION_12 },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TLS_ECDH_ECDSA_WITH_NULL_SHA] */
  { /*     9 */        49156u,             FALSE, TCPIP_TLSVERSION_12 },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA] */
  { /*    10 */        49158u,             FALSE, TCPIP_TLSVERSION_12 },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TLS_ECDHE_ECDSA_WITH_NULL_SHA] */
  { /*    11 */        49161u,             FALSE, TCPIP_TLSVERSION_12 },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA] */
  { /*    12 */        49187u,             FALSE, TCPIP_TLSVERSION_12 },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256] */
  { /*    13 */        49189u,             FALSE, TCPIP_TLSVERSION_12 },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256] */
  { /*    14 */        49195u,             FALSE, TCPIP_TLSVERSION_12 },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256] */
  { /*    15 */        49197u,             FALSE, TCPIP_TLSVERSION_12 }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA256] */
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsCipherWorker
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsCipherWorker
  \details
  Element                            Description
  CipherEncryptKeyLength         
  CipherMacKeyLength             
  CsmJobIdCipherDecryptIdx           the index of the 0:1 relation pointing to TcpIp_CsmJobId
  CsmJobIdCipherEncryptIdx           the index of the 0:1 relation pointing to TcpIp_CsmJobId
  CsmJobIdHmacGenerateIdx            the index of the 0:1 relation pointing to TcpIp_CsmJobId
  CsmJobIdHmacVerifyIdx              the index of the 0:1 relation pointing to TcpIp_CsmJobId
  CsmKeyIdCipherPassiveDecryptIdx    the index of the 0:1 relation pointing to TcpIp_CsmKeyId
  CsmKeyIdCipherPassiveEncryptIdx    the index of the 0:1 relation pointing to TcpIp_CsmKeyId
  TlsCipherDefinitionIdx             the index of the 1:1 relation pointing to TcpIp_TlsCipherDefinition
  TlsHandshakeIndEndIdx              the end index of the 1:n relation pointing to TcpIp_TlsHandshakeInd
  TlsHandshakeIndStartIdx            the start index of the 1:n relation pointing to TcpIp_TlsHandshakeInd
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_TlsCipherWorkerType, TCPIP_CONST) TcpIp_TlsCipherWorker[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CipherEncryptKeyLength  CipherMacKeyLength  CsmJobIdCipherDecryptIdx  CsmJobIdCipherEncryptIdx  CsmJobIdHmacGenerateIdx  CsmJobIdHmacVerifyIdx                            CsmKeyIdCipherPassiveDecryptIdx                            CsmKeyIdCipherPassiveEncryptIdx                            TlsCipherDefinitionIdx  TlsHandshakeIndEndIdx  TlsHandshakeIndStartIdx        Referable Keys */
  { /*     0 */                    16u,                32u,                      11u,                      12u,                     10u,                                              9u, TCPIP_NO_CSMKEYIDCIPHERPASSIVEDECRYPTIDXOFTLSCIPHERWORKER, TCPIP_NO_CSMKEYIDCIPHERPASSIVEENCRYPTIDXOFTLSCIPHERWORKER,                    12u,                    1u,                      0u },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  { /*     1 */                     0u,                32u,                      14u,                      15u,                     13u, TCPIP_NO_CSMJOBIDHMACVERIFYIDXOFTLSCIPHERWORKER,                                                       20u,                                                       21u,                     7u,                    2u,                      1u },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_CHACHA20_POLY1305_SHA256_Secp521r1, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  { /*     2 */                     0u,                48u,                      17u,                      18u,                     16u, TCPIP_NO_CSMJOBIDHMACVERIFYIDXOFTLSCIPHERWORKER,                                                       22u,                                                       23u,                     6u,                    3u,                      2u }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_WITH_AES_256_GCM_SHA384_Secp521r1] */
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsCipherWorkerInd
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsCipherWorkerInd
  \brief  the indexes of the 1:1 sorted relation pointing to TcpIp_TlsCipherWorker
*/ 
#define TCPIP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_TlsCipherWorkerIndType, TCPIP_CONST) TcpIp_TlsCipherWorkerInd[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TlsCipherWorkerInd      Referable Keys */
  /*     0 */                  0u,  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*     1 */                  1u   /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
};
#define TCPIP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsConfig
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsConfig
  \details
  Element                          Description
  NssKeyLogPort                    Port used for NSS Key Log Frame
  MaskedBits                       contains bitcoded the boolean data of TcpIp_TlsClearBufferAfterHandshakeOfTlsConfig, TcpIp_TlsRejectEarlyDataExtensionInTicketOfTlsConfig, TcpIp_TlsUseKeyUpdateCalloutOfTlsConfig
  MaxAcceptanceTicketTime          Tls Session Resumption Max Acceptance Ticket Time - Value of configuration parameter TcpIpTlsMaxAcceptanceTicketTime [SECONDS]
  MaxPskIdentityLen                The maximum receivable PSK identity length the ECU can handle in a NewSessionTicket.
  MaxTicketLifetime                Tls Session Resumption Max Ticket Lifetime - Value of configuration parameter TcpIpTlsMaxTicketLifetime [SECONDS]
  MinRemainingTicketLifetime       Tls Session Resumption Min Remaining Ticket Lifetime - Value of configuration parameter TcpIpTlsMinRemainingTicketLifetime [SECONDS]
  MinTicketLifetime                Tls Session Resumption Min Ticket Lifetime - Value of configuration parameter TcpIpTlsMinTicketLifetime [SECONDS]
  KeyMServiceCertificateFunc       TLS service certificate function
  KeyMSetCertificateInGroupFunc    TLS set certificate in group function
  KeyMVerifyGroupFunc              TLS verify certificate group function
  TlsUserErrorCalloutFunction      TLS User Error Callout function
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_TlsConfigType, TCPIP_CONST) TcpIp_TlsConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    NssKeyLogPort           MaskedBits  MaxAcceptanceTicketTime                      MaxPskIdentityLen  MaxTicketLifetime                      MinRemainingTicketLifetime                      MinTicketLifetime                      KeyMServiceCertificateFunc  KeyMSetCertificateInGroupFunc  KeyMVerifyGroupFunc  TlsUserErrorCalloutFunction                     */
  { /*     0 */ 0xD431u /*  54321  */ ,      0x00u, TCPIP_NO_MAXACCEPTANCETICKETTIMEOFTLSCONFIG,                0u, TCPIP_NO_MAXTICKETLIFETIMEOFTLSCONFIG, TCPIP_NO_MINREMAININGTICKETLIFETIMEOFTLSCONFIG, TCPIP_NO_MINTICKETLIFETIMEOFTLSCONFIG, KeyM_ServiceCertificate   , KeyM_SetCertificateInGroup   , KeyM_VerifyGroup   , TcpIpTlsUserErrorCalloutFunction_TcpIpTlsConfig }
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsConnection
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsConnection
  \details
  Element                                              Description
  MaskedBits                                           contains bitcoded the boolean data of TcpIp_IncludeRootCertificateOfTlsConnection, TcpIp_MiddleboxCompatibilityModeOfTlsConnection, TcpIp_TlsSupportVersion12OfTlsConnection, TcpIp_TlsSupportVersion13OfTlsConnection, TcpIp_TlsUseChangeableCipherCallbackOfTlsConnection, TcpIp_TlsUseClientAuthenticationRequestOfTlsConnection, TcpIp_TlsUseExtensionCertificateStatusRequestOfTlsConnection, TcpIp_TlsUseExtensionRecordSizeLimitOfTlsConnection, TcpIp_TlsUseExtensionTrustedCaIndicationOfTlsConnection
  Port                                                 Port used for this TLS connection
  TlsSumLocalCertMaxLength                             Overall size of all referenced KeyM local certificates.
  TlsTemporarySignatureBufferEndIdx                    the end index of the 1:n relation pointing to TcpIp_TlsTemporarySignatureBuffer
  TlsTemporarySignatureBufferStartIdx                  the start index of the 1:n relation pointing to TcpIp_TlsTemporarySignatureBuffer
  CsmKeyIdResumptionMasterSecretIdx                    the index of the 0:1 relation pointing to TcpIp_CsmKeyId
  LocalAddrIdx                                         the index of the 0:1 relation pointing to TcpIp_LocalAddr
  Tls13PskIdentityIndEndIdx                            the end index of the 0:n relation pointing to TcpIp_Tls13PskIdentityInd
  Tls13PskIdentityIndStartIdx                          the start index of the 0:n relation pointing to TcpIp_Tls13PskIdentityInd
  TlsBufferMgmtIdx                                     the index of the 1:1 relation pointing to TcpIp_TlsBufferMgmt
  TlsCertIdIssuerEndIdx                                the end index of the 0:n relation pointing to TcpIp_TlsCertId
  TlsCertIdIssuerStartIdx                              the start index of the 0:n relation pointing to TcpIp_TlsCertId
  TlsCertValidationStatusDynEndIdx                     the end index of the 0:n relation pointing to TcpIp_TlsCertValidationStatusDyn
  TlsCertValidationStatusDynStartIdx                   the start index of the 0:n relation pointing to TcpIp_TlsCertValidationStatusDyn
  TlsCipherWorkerIndEndIdx                             the end index of the 1:n relation pointing to TcpIp_TlsCipherWorkerInd
  TlsCipherWorkerIndStartIdx                           the start index of the 1:n relation pointing to TcpIp_TlsCipherWorkerInd
  TlsCipherWorkingSetMgmtIdx                           the index of the 0:1 relation pointing to TcpIp_TlsCipherWorkingSetMgmt
  TlsClientAuthenticationMgmtIdx                       the index of the 0:1 relation pointing to TcpIp_TlsClientAuthenticationMgmt
  TlsClientBufferMgmtIdx                               the index of the 0:1 relation pointing to TcpIp_TlsClientBufferMgmt
  TlsClientConnectionIdx                               the index of the 0:1 relation pointing to TcpIp_TlsClientConnection
  TlsClientOcspBufferMgmtEndIdx                        the end index of the 0:n relation pointing to TcpIp_TlsClientOcspBufferMgmt
  TlsClientOcspBufferMgmtStartIdx                      the start index of the 0:n relation pointing to TcpIp_TlsClientOcspBufferMgmt
  TlsClientRandomAccessBufferEndIdx                    the end index of the 0:n relation pointing to TcpIp_TlsClientRandomAccessBuffer
  TlsClientRandomAccessBufferStartIdx                  the start index of the 0:n relation pointing to TcpIp_TlsClientRandomAccessBuffer
  TlsClientSessionIdAccessBufferEndIdx                 the end index of the 0:n relation pointing to TcpIp_TlsClientSessionIdAccessBuffer
  TlsClientSessionIdAccessBufferStartIdx               the start index of the 0:n relation pointing to TcpIp_TlsClientSessionIdAccessBuffer
  TlsConfiguredHandshakeForServerConnectionEndIdx      the end index of the 0:n relation pointing to TcpIp_TlsConfiguredHandshakeForServerConnection
  TlsConfiguredHandshakeForServerConnectionStartIdx    the start index of the 0:n relation pointing to TcpIp_TlsConfiguredHandshakeForServerConnection
  TlsLocalKeyMCertInfoEndIdx                           the end index of the 0:n relation pointing to TcpIp_TlsLocalKeyMCertInfo
  TlsLocalKeyMCertInfoStartIdx                         the start index of the 0:n relation pointing to TcpIp_TlsLocalKeyMCertInfo
  TlsMaxSizeDistinguishedNames                         Maximum size of distinguished names for TLS 1.3 extension certificate_authorities.
  TlsPskIdentityDefaultIdx                             the index of the 0:1 relation pointing to TcpIp_TlsPskIdentity
  TlsPskIdentityIndEndIdx                              the end index of the 0:n relation pointing to TcpIp_TlsPskIdentityInd
  TlsPskIdentityIndStartIdx                            the start index of the 0:n relation pointing to TcpIp_TlsPskIdentityInd
  TlsRemoteKeyMCertInfoEndIdx                          the end index of the 0:n relation pointing to TcpIp_TlsRemoteKeyMCertInfo
  TlsRemoteKeyMCertInfoStartIdx                        the start index of the 0:n relation pointing to TcpIp_TlsRemoteKeyMCertInfo
  TlsResumedConnectionIdx                              the index of the 0:1 relation pointing to TcpIp_TlsResumedConnection
  TlsServerBufferMgmtIdx                               the index of the 0:1 relation pointing to TcpIp_TlsServerBufferMgmt
  TlsServerConnectionIdx                               the index of the 0:1 relation pointing to TcpIp_TlsServerConnection
  TlsServerNameIndicationEndIdx                        the end index of the 0:n relation pointing to TcpIp_TlsServerNameIndication
  TlsServerNameIndicationLength                        the number of relations pointing to TcpIp_TlsServerNameIndication
  TlsServerNameIndicationStartIdx                      the start index of the 0:n relation pointing to TcpIp_TlsServerNameIndication
  TlsSigAlgServerCertReqMsgBufferEndIdx                the end index of the 1:n relation pointing to TcpIp_TlsSigAlgServerCertReqMsgBuffer
  TlsSigAlgServerCertReqMsgBufferStartIdx              the start index of the 1:n relation pointing to TcpIp_TlsSigAlgServerCertReqMsgBuffer
  TlsTemporaryClientAuthEdCurveBufferEndIdx            the end index of the 0:n relation pointing to TcpIp_TlsTemporaryClientAuthEdCurveBuffer
  TlsTemporaryClientAuthEdCurveBufferLength            the number of relations pointing to TcpIp_TlsTemporaryClientAuthEdCurveBuffer
  TlsTemporaryClientAuthEdCurveBufferStartIdx          the start index of the 0:n relation pointing to TcpIp_TlsTemporaryClientAuthEdCurveBuffer
  TlsTemporaryFinishedBufferEndIdx                     the end index of the 1:n relation pointing to TcpIp_TlsTemporaryFinishedBuffer
  TlsTemporaryFinishedBufferStartIdx                   the start index of the 1:n relation pointing to TcpIp_TlsTemporaryFinishedBuffer
  TlsTemporaryHashBufferEndIdx                         the end index of the 1:n relation pointing to TcpIp_TlsTemporaryHashBuffer
  TlsTemporaryHashBufferStartIdx                       the start index of the 1:n relation pointing to TcpIp_TlsTemporaryHashBuffer
  TlsTemporaryHkdfHashBufferEndIdx                     the end index of the 1:n relation pointing to TcpIp_TlsTemporaryHkdfHashBuffer
  TlsTemporaryHkdfHashBufferStartIdx                   the start index of the 1:n relation pointing to TcpIp_TlsTemporaryHkdfHashBuffer
  TlsTemporaryHmacBufferEndIdx                         the end index of the 1:n relation pointing to TcpIp_TlsTemporaryHmacBuffer
  TlsTemporaryHmacBufferStartIdx                       the start index of the 1:n relation pointing to TcpIp_TlsTemporaryHmacBuffer
  TlsUserErrorBufferEndIdx                             the end index of the 0:n relation pointing to TcpIp_TlsUserErrorBuffer
  TlsUserErrorBufferStartIdx                           the start index of the 0:n relation pointing to TcpIp_TlsUserErrorBuffer
  Mode                                                 Specifies if the TLS connection is a server or a client
  TimeCalloutFunc                                      TLS get time callout function
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_TlsConnectionType, TCPIP_CONST) TcpIp_TlsConnection[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MaskedBits  Port            TlsSumLocalCertMaxLength  TlsTemporarySignatureBufferEndIdx  TlsTemporarySignatureBufferStartIdx  CsmKeyIdResumptionMasterSecretIdx                          LocalAddrIdx                          Tls13PskIdentityIndEndIdx                          Tls13PskIdentityIndStartIdx                          TlsBufferMgmtIdx  TlsCertIdIssuerEndIdx  TlsCertIdIssuerStartIdx  TlsCertValidationStatusDynEndIdx  TlsCertValidationStatusDynStartIdx  TlsCipherWorkerIndEndIdx  TlsCipherWorkerIndStartIdx  TlsCipherWorkingSetMgmtIdx  TlsClientAuthenticationMgmtIdx  TlsClientBufferMgmtIdx  TlsClientConnectionIdx  TlsClientOcspBufferMgmtEndIdx  TlsClientOcspBufferMgmtStartIdx  TlsClientRandomAccessBufferEndIdx  TlsClientRandomAccessBufferStartIdx  TlsClientSessionIdAccessBufferEndIdx  TlsClientSessionIdAccessBufferStartIdx  TlsConfiguredHandshakeForServerConnectionEndIdx                          TlsConfiguredHandshakeForServerConnectionStartIdx                          TlsLocalKeyMCertInfoEndIdx  TlsLocalKeyMCertInfoStartIdx  TlsMaxSizeDistinguishedNames  TlsPskIdentityDefaultIdx                          TlsPskIdentityIndEndIdx                          TlsPskIdentityIndStartIdx                          TlsRemoteKeyMCertInfoEndIdx  TlsRemoteKeyMCertInfoStartIdx  TlsResumedConnectionIdx                          TlsServerBufferMgmtIdx                          TlsServerConnectionIdx                          TlsServerNameIndicationEndIdx                          TlsServerNameIndicationLength  TlsServerNameIndicationStartIdx                          TlsSigAlgServerCertReqMsgBufferEndIdx  TlsSigAlgServerCertReqMsgBufferStartIdx  TlsTemporaryClientAuthEdCurveBufferEndIdx                          TlsTemporaryClientAuthEdCurveBufferLength  TlsTemporaryClientAuthEdCurveBufferStartIdx                          TlsTemporaryFinishedBufferEndIdx  TlsTemporaryFinishedBufferStartIdx  TlsTemporaryHashBufferEndIdx  TlsTemporaryHashBufferStartIdx  TlsTemporaryHkdfHashBufferEndIdx  TlsTemporaryHkdfHashBufferStartIdx  TlsTemporaryHmacBufferEndIdx  TlsTemporaryHmacBufferStartIdx  TlsUserErrorBufferEndIdx  TlsUserErrorBufferStartIdx  Mode              TimeCalloutFunc        Referable Keys */
  { /*     0 */    0x0078u, TCPIP_PORT_ANY,                    1600u,                              333u,                                  0u, TCPIP_NO_CSMKEYIDRESUMPTIONMASTERSECRETIDXOFTLSCONNECTION, TCPIP_NO_LOCALADDRIDXOFTLSCONNECTION, TCPIP_NO_TLS13PSKIDENTITYINDENDIDXOFTLSCONNECTION, TCPIP_NO_TLS13PSKIDENTITYINDSTARTIDXOFTLSCONNECTION,               0u,                   13u,                      0u,                               6u,                                 0u,                       2u,                         0u,                         0u,                             0u,                     0u,                     0u,                            5u,                              0u,                               32u,                                  0u,                                  32u,                                     0u, TCPIP_NO_TLSCONFIGUREDHANDSHAKEFORSERVERCONNECTIONENDIDXOFTLSCONNECTION, TCPIP_NO_TLSCONFIGUREDHANDSHAKEFORSERVERCONNECTIONSTARTIDXOFTLSCONNECTION,                         1u,                           0u,                           0u, TCPIP_NO_TLSPSKIDENTITYDEFAULTIDXOFTLSCONNECTION, TCPIP_NO_TLSPSKIDENTITYINDENDIDXOFTLSCONNECTION, TCPIP_NO_TLSPSKIDENTITYINDSTARTIDXOFTLSCONNECTION,                          1u,                            0u, TCPIP_NO_TLSRESUMEDCONNECTIONIDXOFTLSCONNECTION, TCPIP_NO_TLSSERVERBUFFERMGMTIDXOFTLSCONNECTION, TCPIP_NO_TLSSERVERCONNECTIONIDXOFTLSCONNECTION, TCPIP_NO_TLSSERVERNAMEINDICATIONENDIDXOFTLSCONNECTION,                            0u, TCPIP_NO_TLSSERVERNAMEINDICATIONSTARTIDXOFTLSCONNECTION,                                   10u,                                      0u, TCPIP_NO_TLSTEMPORARYCLIENTAUTHEDCURVEBUFFERENDIDXOFTLSCONNECTION,                                        0u, TCPIP_NO_TLSTEMPORARYCLIENTAUTHEDCURVEBUFFERSTARTIDXOFTLSCONNECTION,                              32u,                                 0u,                          64u,                             0u,                              64u,                                 0u,                         100u,                             0u,                      10u,                         0u, TCPIP_TLS_CLIENT, NULL_PTR        }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsCsmJob
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsCsmJob
  \brief  List of all CSM jobs. CSM job Id as entry point.
  \details
  Element               Description
  CsmReferencedKeyId    Csm key ID of the referenced key in this job.
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_TlsCsmJobType, TCPIP_CONST) TcpIp_TlsCsmJob[90] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CsmReferencedKeyId        Comment */
  { /*     0 */ 3                  },  /* [CsmConf_CsmJob_CsmJob_HmacSha256Generate_1: 0] */
  { /*     1 */ 106                },  /* [CsmConf_CsmJob_CsmJob_SccECDSASignatureGenerate: 1] */
  { /*     2 */ 107                },  /* [CsmConf_CsmJob_CsmJob_SccECDSASignatureVerify: 2] */
  { /*     3 */ 107                },  /* [CsmConf_CsmJob_CsmJob_SccSha256: 3] */
  { /*     4 */ 38                 },  /* [CsmConf_CsmJob_CsmJob_SccSha512: 4] */
  { /*     5 */ 7                  },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_CPOLeaf_ECDSA_Verify: 5] */
  { /*     6 */ 8                  },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_CPOSubCA1_ECDSA_Verify: 6] */
  { /*     7 */ 9                  },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_CPOSubCA2_ECDSA_Verify: 7] */
  { /*     8 */ 10                 },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_CPSLeaf_ECDSA_Verify: 8] */
  { /*     9 */ 11                 },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_CPSSubCA1_ECDSA_Verify: 9] */
  { /*    10 */ 12                 },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_CPSSubCA2_ECDSA_Verify: 10] */
  { /*    11 */ 14                 },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_EMSPLeaf_0_ECDSA_Verify: 11] */
  { /*    12 */ 16                 },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_EMSPLeaf_1_ECDSA_Verify: 12] */
  { /*    13 */ 17                 },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_EMSPSubCa1_1_ECDSA_Verify: 13] */
  { /*    14 */ 18                 },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_EMSPSubCa2_0_ECDSA_Verify: 14] */
  { /*    15 */ 19                 },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_EMSPSubCa2_1_ECDSA_Verify: 15] */
  { /*    16 */ 21                 },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_OEMProvLeaf_0_ECDSA_Verify: 16] */
  { /*    17 */ 23                 },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_OEMProvLeaf_1_ECDSA_Verify: 17] */
  { /*    18 */ 24                 },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_OEMProvSubCa1_1_ECDSA_Verify: 18] */
  { /*    19 */ 25                 },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_OEMProvSubCa2_0_ECDSA_Verify: 19] */
  { /*    20 */ 26                 },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_OEMProvSubCa2_1_ECDSA_Verify: 20] */
  { /*    21 */ 27                 },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_V2GRoot_0_Verify: 21] */
  { /*    22 */ 27                 },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_V2GRoot_1_Verify: 22] */
  { /*    23 */ 30                 },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_VehicleLeaf_ECDSA_Verify: 23] */
  { /*    24 */ 31                 },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_VehicleSubCA1_ECDSA_Verify: 24] */
  { /*    25 */ 32                 },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_VehicleSubCA2_ECDSA_Verify: 25] */
  { /*    26 */ 33                 },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_secp521r1_SignatureGenerate: 26] */
  { /*    27 */ 34                 },  /* [CsmConf_CsmJob_CsmJob_Scc_ISO20_secp521r1_SignatureVerify: 27] */
  { /*    28 */ 35                 },  /* [CsmConf_CsmJob_CsmJob_Scc_KDF: 28] */
  { /*    29 */ 36                 },  /* [CsmConf_CsmJob_CsmJob_Scc_KDF_ISO15118_20: 29] */
  { /*    30 */ 109                },  /* [CsmConf_CsmJob_CsmJob_Scc_MOCOntract_X_Verify: 30] */
  { /*    31 */ 37                 },  /* [CsmConf_CsmJob_CsmJob_Scc_MORoot_X_Verify: 31] */
  { /*    32 */ 110                },  /* [CsmConf_CsmJob_CsmJob_Scc_MOSubCa1_X_Verify: 32] */
  { /*    33 */ 111                },  /* [CsmConf_CsmJob_CsmJob_Scc_MOSubCa2_X_Verify: 33] */
  { /*    34 */ 112                },  /* [CsmConf_CsmJob_CsmJob_Scc_OEMProvRoot: 34] */
  { /*    35 */ 113                },  /* [CsmConf_CsmJob_CsmJob_Scc_OEMProvSubCa1: 35] */
  { /*    36 */ 114                },  /* [CsmConf_CsmJob_CsmJob_Scc_OEMProvSubCa2: 36] */
  { /*    37 */ 116                },  /* [CsmConf_CsmJob_CsmJob_Scc_OEMProv_X_Verify: 37] */
  { /*    38 */ 117                },  /* [CsmConf_CsmJob_CsmJob_Scc_ProvLeaf_X_Verify: 38] */
  { /*    39 */ 118                },  /* [CsmConf_CsmJob_CsmJob_Scc_ProvSubCa1_X_Verify: 39] */
  { /*    40 */ 119                },  /* [CsmConf_CsmJob_CsmJob_Scc_ProvSubCa2_X_Verify: 40] */
  { /*    41 */ 121                },  /* [CsmConf_CsmJob_CsmJob_Scc_V2GRoot_X_Verify: 41] */
  { /*    42 */ 39                 },  /* [CsmConf_CsmJob_CsmJob_Scc_V2GRoot_Y_Verify: 42] */
  { /*    43 */ 96                 },  /* [CsmConf_CsmJob_CsmJob_SigVerify_Cert_V2G_Root_1: 43] */
  { /*    44 */ 97                 },  /* [CsmConf_CsmJob_CsmJob_SigVerify_Cert_V2G_Root_2: 44] */
  { /*    45 */ 98                 },  /* [CsmConf_CsmJob_CsmJob_SigVerify_Cert_V2G_Root_3: 45] */
  { /*    46 */ 99                 },  /* [CsmConf_CsmJob_CsmJob_SigVerify_Cert_V2G_Root_4: 46] */
  { /*    47 */ 100                },  /* [CsmConf_CsmJob_CsmJob_SigVerify_Cert_V2G_Root_5: 47] */
  { /*    48 */ 101                },  /* [CsmConf_CsmJob_CsmJob_SigVerify_Cert_V2G_Root_6: 48] */
  { /*    49 */ 102                },  /* [CsmConf_CsmJob_CsmJob_SigVerify_Cert_V2G_Root_7: 49] */
    /* Index    CsmReferencedKeyId        Comment */
  { /*    50 */ 103                },  /* [CsmConf_CsmJob_CsmJob_SigVerify_Cert_V2G_Root_8: 50] */
  { /*    51 */ 104                },  /* [CsmConf_CsmJob_CsmJob_SigVerify_Cert_V2G_Root_9: 51] */
  { /*    52 */ 105                },  /* [CsmConf_CsmJob_CsmJob_SigVerify_Cert_V2G_Root_10: 52] */
  { /*    53 */ 41                 },  /* [CsmConf_CsmJob_CsmJob_TlsConn0_HS_DhSignatureGenerate: 53] */
  { /*    54 */ 4                  },  /* [CsmConf_CsmJob_CsmJob_TlsConn0_HS_DhSignatureVerify: 54] */
  { /*    55 */ 43                 },  /* [CsmConf_CsmJob_CsmJob_TlsConn1_HS_DhSignatureGenerate_Secp521r1: 55] */
  { /*    56 */ 7                  },  /* [CsmConf_CsmJob_CsmJob_TlsConn1_HS_DhSignatureVerify_Secp521r1: 56] */
  { /*    57 */ 4                  },  /* [CsmConf_CsmJob_CsmJob_Tls_CertVerify_Leaf_Server_A_EccNistP256R1Sha256: 57] */
  { /*    58 */ 48                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn0_Aes128Cbc_Decrypt: 58] */
  { /*    59 */ 49                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn0_Aes128Cbc_Encrypt: 59] */
  { /*    60 */ 50                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn0_CertVerify_EccNistP256R1Sha1: 60] */
  { /*    61 */ 50                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn0_CertVerify_EccNistP256R1Sha256: 61] */
  { /*    62 */ 52                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn0_HMacSha1_Generate: 62] */
  { /*    63 */ 53                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn0_HMacSha1_Verify: 63] */
  { /*    64 */ 52                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn0_HMacSha256_Generate: 64] */
  { /*    65 */ 53                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn0_HMacSha256_Verify: 65] */
  { /*    66 */ 55                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn0_HS_DhSignatureGenerate: 66] */
  { /*    67 */ 51                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn0_HS_DhSignatureVerify: 67] */
  { /*    68 */ 58                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn0_HS_RandomNumber: 68] */
  { /*    69 */ 59                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn0_HashSha256_Finished: 69] */
  { /*    70 */ 67                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn0_Prf_HMacGenerate_Private: 70] */
  { /*    71 */ 68                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn0_Prf_HMacGenerate_Public: 71] */
  { /*    72 */ 70                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn1_Aes256Gcm_Decrypt_1: 72] */
  { /*    73 */ 71                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn1_Aes256Gcm_Encrypt_1: 73] */
  { /*    74 */ 44                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn1_ChaCha20_Decrypt: 74] */
  { /*    75 */ 45                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn1_ChaCha20_Encrypt: 75] */
  { /*    76 */ 74                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn1_HashSha256_Finished: 76] */
  { /*    77 */ 75                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn1_HashSha384: 77] */
  { /*    78 */ 75                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn1_HashSha384_Finished: 78] */
  { /*    79 */ 81                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn1_Prf_HMacGenerate_Private: 79] */
  { /*    80 */ 81                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Conn1_Prf_HMacGenerate_Public: 80] */
  { /*    81 */ 83                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Global_HashSha1: 81] */
  { /*    82 */ 1                  },  /* [CsmConf_CsmJob_CsmJob_Tls_Hkdf_Sha256: 82] */
  { /*    83 */ 88                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Hkdf_Sha256Expand: 83] */
  { /*    84 */ 2                  },  /* [CsmConf_CsmJob_CsmJob_Tls_Hkdf_Sha384: 84] */
  { /*    85 */ 90                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Hkdf_Sha384Expand: 85] */
  { /*    86 */ 84                 },  /* [CsmConf_CsmJob_CsmJob_Tls_HmacSha384Generate_1: 86] */
  { /*    87 */ 93                 },  /* [CsmConf_CsmJob_CsmJob_Tls_Root_A_EccNistP256R1Sha256: 87] */
  { /*    88 */ 94                 },  /* [CsmConf_CsmJob_CsmJob_Tls_SubCa1_A_EccNistP256R1Sha256: 88] */
  { /*    89 */ 95                 }   /* [CsmConf_CsmJob_CsmJob_Tls_SubCa2_A_EccNistP256R1Sha256: 89] */
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsHandshake
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsHandshake
  \details
  Element                                    Description
  HsCommonKeyElementId                   
  PrfValueActiveKeyElementId             
  PrfValueOutputKeyElementId             
  PrfValuePassiveKeyElementId            
  AdditionalInfoKeyElementId             
  CsmJobIdHkdfCalculationIdx                 the index of the 0:1 relation pointing to TcpIp_CsmJobId
  CsmJobIdHkdfExpandIdx                      the index of the 0:1 relation pointing to TcpIp_CsmJobId
  CsmJobIdHkdfHashMessagesJobIdIdx           the index of the 0:1 relation pointing to TcpIp_CsmJobId
  CsmJobIdKeyExchangeSignatureGenerateIdx    the index of the 0:1 relation pointing to TcpIp_CsmJobId
  CsmKeyIdHkdfClientAdHsTrafficSecretIdx     the index of the 0:1 relation pointing to TcpIp_CsmKeyId
  CsmKeyIdHkdfDerivedSecretIdx               the index of the 0:1 relation pointing to TcpIp_CsmKeyId
  CsmKeyIdHkdfServerAdHsTrafficSecretIdx     the index of the 0:1 relation pointing to TcpIp_CsmKeyId
  CsmKeyIdHkdfSharedSecretIdx                the index of the 0:1 relation pointing to TcpIp_CsmKeyId
  CsmKeyIdKeyExchangeIdx                     the index of the 0:1 relation pointing to TcpIp_CsmKeyId
  CsmKeyIdMasterSecretIdx                    the index of the 0:1 relation pointing to TcpIp_CsmKeyId
  CsmKeyIdTemporaryHkdfExpandInKeyIdx        the index of the 0:1 relation pointing to TcpIp_CsmKeyId
  CsmKeyIdTemporaryHkdfExpandOutKeyIdx       the index of the 0:1 relation pointing to TcpIp_CsmKeyId
  CsmKeyIdTemporaryHkdfKeyIdx                the index of the 0:1 relation pointing to TcpIp_CsmKeyId
  HashVerifyJobId                        
  HsTemporaryBufferKeyId                 
  PrfMacCalculationPrivateKeyId          
  PrfMacCalculationPublicKeyId           
  PrfMacGeneratePrivateJobId             
  PrfMacGeneratePublicJobId              
  PrfResultPrivateKeyId                  
  PrfResultPublicKeyId                   
  SignatureAlgorithmId                       Signature Algorithm defined in RFC8422 or RFC5246
  EllipticCurveId                            Curve ID named in RFC8422
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_TlsHandshakeType, TCPIP_CONST) TcpIp_TlsHandshake[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    HsCommonKeyElementId  PrfValueActiveKeyElementId  PrfValueOutputKeyElementId  PrfValuePassiveKeyElementId  AdditionalInfoKeyElementId  CsmJobIdHkdfCalculationIdx                         CsmJobIdHkdfExpandIdx                         CsmJobIdHkdfHashMessagesJobIdIdx                         CsmJobIdKeyExchangeSignatureGenerateIdx  CsmKeyIdHkdfClientAdHsTrafficSecretIdx                         CsmKeyIdHkdfDerivedSecretIdx                         CsmKeyIdHkdfServerAdHsTrafficSecretIdx                         CsmKeyIdHkdfSharedSecretIdx                         CsmKeyIdKeyExchangeIdx  CsmKeyIdMasterSecretIdx  CsmKeyIdTemporaryHkdfExpandInKeyIdx                         CsmKeyIdTemporaryHkdfExpandOutKeyIdx                         CsmKeyIdTemporaryHkdfKeyIdx                         HashVerifyJobId                                      HsTemporaryBufferKeyId                     PrfMacCalculationPrivateKeyId                                PrfMacCalculationPublicKeyId                                PrfMacGeneratePrivateJobId                                PrfMacGeneratePublicJobId                                PrfResultPrivateKeyId                              PrfResultPublicKeyId                              SignatureAlgorithmId                      EllipticCurveId                 Referable Keys */
  { /*     0 */                3080u,                      3082u,                      3081u,                       3083u,                       131u,                                                2u,                                           3u,                                                      1u,                                      0u,                                                            5u,                                                  2u,                                                            4u,                                                 3u,                     1u,                      0u,                                                         7u,                                                          8u,                                                 6u, CsmConf_CsmJob_CsmJob_Tls_Conn1_HashSha384_Finished, CsmConf_CsmKey_CsmKey_Tls_Conn1_TmpBuffer, CsmConf_CsmKey_CsmKey_Tls_Conn1_PrfCalculationValuesPrivate, CsmConf_CsmKey_CsmKey_Tls_Conn1_PrfCalculationValuesPublic, CsmConf_CsmJob_CsmJob_Tls_Conn1_Prf_HMacGenerate_Private, CsmConf_CsmJob_CsmJob_Tls_Conn1_Prf_HMacGenerate_Public, CsmConf_CsmKey_CsmKey_Tls_Conn1_Prf_ResultPrivate, CsmConf_CsmKey_CsmKey_Tls_Conn1_Prf_ResultPublic, TCPIP_SIG_ALGO_ID_ECDSA_SECP521R1_SHA512, TCPIP_CURVE_ID_SECP521R1 },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_WITH_AES_256_GCM_SHA384_Secp521r1] */
  { /*     1 */                3080u,                      3082u,                      3081u,                       3083u,                       131u,                                                6u,                                           7u,                                                      5u,                                      0u,                                                            5u,                                                  2u,                                                            4u,                                                12u,                     1u,                      0u,                                                        16u,                                                         17u,                                                 6u, CsmConf_CsmJob_CsmJob_Tls_Conn1_HashSha256_Finished, CsmConf_CsmKey_CsmKey_Tls_Conn1_TmpBuffer, CsmConf_CsmKey_CsmKey_Tls_Conn1_PrfCalculationValuesPrivate, CsmConf_CsmKey_CsmKey_Tls_Conn1_PrfCalculationValuesPublic, CsmConf_CsmJob_CsmJob_Tls_Conn1_Prf_HMacGenerate_Private, CsmConf_CsmJob_CsmJob_Tls_Conn1_Prf_HMacGenerate_Public, CsmConf_CsmKey_CsmKey_Tls_Conn1_Prf_ResultPrivate, CsmConf_CsmKey_CsmKey_Tls_Conn1_Prf_ResultPublic, TCPIP_SIG_ALGO_ID_ECDSA_SECP521R1_SHA512, TCPIP_CURVE_ID_SECP521R1 },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_CHACHA20_POLY1305_SHA256_Secp521r1] */
  { /*     2 */                3080u,                      3082u,                      3081u,                       3083u,                         0u, TCPIP_NO_CSMJOBIDHKDFCALCULATIONIDXOFTLSHANDSHAKE, TCPIP_NO_CSMJOBIDHKDFEXPANDIDXOFTLSHANDSHAKE, TCPIP_NO_CSMJOBIDHKDFHASHMESSAGESJOBIDIDXOFTLSHANDSHAKE,                                      8u, TCPIP_NO_CSMKEYIDHKDFCLIENTADHSTRAFFICSECRETIDXOFTLSHANDSHAKE, TCPIP_NO_CSMKEYIDHKDFDERIVEDSECRETIDXOFTLSHANDSHAKE, TCPIP_NO_CSMKEYIDHKDFSERVERADHSTRAFFICSECRETIDXOFTLSHANDSHAKE, TCPIP_NO_CSMKEYIDHKDFSHAREDSECRETIDXOFTLSHANDSHAKE,                    19u,                     18u, TCPIP_NO_CSMKEYIDTEMPORARYHKDFEXPANDINKEYIDXOFTLSHANDSHAKE, TCPIP_NO_CSMKEYIDTEMPORARYHKDFEXPANDOUTKEYIDXOFTLSHANDSHAKE, TCPIP_NO_CSMKEYIDTEMPORARYHKDFKEYIDXOFTLSHANDSHAKE, CsmConf_CsmJob_CsmJob_Tls_Conn0_HashSha256_Finished, CsmConf_CsmKey_CsmKey_Tls_Conn0_TmpBuffer, CsmConf_CsmKey_CsmKey_Tls_Conn0_PrfCalculationValuesPrivate, CsmConf_CsmKey_CsmKey_Tls_Conn0_PrfCalculationValuesPublic, CsmConf_CsmJob_CsmJob_Tls_Conn0_Prf_HMacGenerate_Private, CsmConf_CsmJob_CsmJob_Tls_Conn0_Prf_HMacGenerate_Public, CsmConf_CsmKey_CsmKey_Tls_Conn0_Prf_ResultPrivate, CsmConf_CsmKey_CsmKey_Tls_Conn0_Prf_ResultPublic, TCPIP_SIG_ALGO_ID_ECDSA_SECP256R1_SHA256, TCPIP_CURVE_ID_SECP256R1 }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256] */
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsHandshakeInd
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsHandshakeInd
  \brief  the indexes of the 1:1 sorted relation pointing to TcpIp_TlsHandshake
*/ 
#define TCPIP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_TlsHandshakeIndType, TCPIP_CONST) TcpIp_TlsHandshakeInd[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TlsHandshakeInd      Referable Keys */
  /*     0 */               2u,  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256] */
  /*     1 */               1u,  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_CHACHA20_POLY1305_SHA256_Secp521r1] */
  /*     2 */               0u   /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_WITH_AES_256_GCM_SHA384_Secp521r1] */
};
#define TCPIP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsKeyMCertificate
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsKeyMCertificate
  \brief  List of all KeyM certificates. KeyMCertificateElementId as entry point.
  \details
  Element                     Description
  PubKeyAlgorithmElementId
  PubKeyCurveElementId    
  CsmCertSignVerifyJobId      Csm signature verify job ID from this KeyM certificate.
  CsmCertSignVerifyKeyId      Csm signature verify key ID from this KeyM certificate.
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_TlsKeyMCertificateType, TCPIP_CONST) TcpIp_TlsKeyMCertificate[40] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PubKeyAlgorithmElementId  PubKeyCurveElementId  CsmCertSignVerifyJobId  CsmCertSignVerifyKeyId        Comment */
  { /*     0 */                      19u,                  20u,                    57u,                     4u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPOLeaf_Tmp: 0] */
  { /*     1 */                      19u,                  20u,                    88u,                    94u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPOSubCA1_Tmp: 1] */
  { /*     2 */                      19u,                  20u,                    89u,                    95u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPOSubCA2_Tmp: 2] */
  { /*     3 */                      19u,                  20u,                    39u,                   118u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPSLeaf_Tmp: 3] */
  { /*     4 */                      19u,                  20u,                    39u,                   118u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPSSubCA1_Tmp: 4] */
  { /*     5 */                      19u,                  20u,                    40u,                   119u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPSSubCA2_Tmp: 5] */
  { /*     6 */                   65535u,               65535u,                    35u,                   113u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO2_OEMProvSubCa1: 6] */
  { /*     7 */                   65535u,               65535u,                    36u,                   114u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO2_OEMProvSubCa2: 7] */
  { /*     8 */                     160u,                 165u,                     5u,                     7u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA: 8] */
  { /*     9 */                     160u,                 165u,                     6u,                     8u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA: 9] */
  { /*    10 */                     160u,                 165u,                     7u,                     9u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA: 10] */
  { /*    11 */                     160u,                 165u,                     8u,                    10u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA: 11] */
  { /*    12 */                     160u,                 165u,                     9u,                    11u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA: 12] */
  { /*    13 */                     160u,                 165u,                    10u,                    12u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA: 13] */
  { /*    14 */                     160u,                 165u,                    11u,                    14u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO20_EMSPContract_0_ECDSA: 14] */
  { /*    15 */                     160u,                 165u,                    13u,                    17u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA: 15] */
  { /*    16 */                     160u,                 165u,                    14u,                    18u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA: 16] */
  { /*    17 */                     160u,                 165u,                    16u,                    21u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO20_OEMProvCertificate_0: 17] */
  { /*    18 */                     160u,                 165u,                    18u,                    24u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO20_OEMProvSubCA1_0: 18] */
  { /*    19 */                     160u,                 165u,                    19u,                    25u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO20_OEMProvSubCA2_0: 19] */
  { /*    20 */                     160u,                 165u,                    21u,                    27u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO20_V2GRoot_0: 20] */
  { /*    21 */                     160u,                 165u,                    22u,                    27u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO20_V2GRoot_1: 21] */
  { /*    22 */                     160u,                 165u,                    23u,                    30u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO20_VehicleCert_0: 22] */
  { /*    23 */                     160u,                 165u,                    24u,                    31u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO20_VehicleSubCA1_0: 23] */
  { /*    24 */                     160u,                 165u,                    25u,                    32u },  /* [KeyMConf_KeyMCertificate_SccCertificate_ISO20_VehicleSubCA2_0: 24] */
  { /*    25 */                      19u,                  20u,                    30u,                   109u },  /* [KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_ContractCertificate_0: 25] */
  { /*    26 */                      19u,                  20u,                    32u,                   110u },  /* [KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_MOSubCA1_0: 26] */
  { /*    27 */                      19u,                  20u,                    33u,                   111u },  /* [KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_MOSubCA2_0: 27] */
  { /*    28 */                      19u,                  20u,                    37u,                   116u },  /* [KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_OEMProvCertificate_0: 28] */
  { /*    29 */                      19u,                  20u,                    41u,                   121u },  /* [KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2GRoot_0: 29] */
  { /*    30 */                      19u,                  20u,                    43u,                    96u },  /* [KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_1: 30] */
  { /*    31 */                      19u,                  20u,                    44u,                    97u },  /* [KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_2: 31] */
  { /*    32 */                      19u,                  20u,                    45u,                    98u },  /* [KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_3: 32] */
  { /*    33 */                      19u,                  20u,                    46u,                    99u },  /* [KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_4: 33] */
  { /*    34 */                      19u,                  20u,                    47u,                   100u },  /* [KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_5: 34] */
  { /*    35 */                      19u,                  20u,                    48u,                   101u },  /* [KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_6: 35] */
  { /*    36 */                      19u,                  20u,                    49u,                   102u },  /* [KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_7: 36] */
  { /*    37 */                      19u,                  20u,                    50u,                   103u },  /* [KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_8: 37] */
  { /*    38 */                      19u,                  20u,                    51u,                   104u },  /* [KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_9: 38] */
  { /*    39 */                      19u,                  20u,                    52u,                   105u }   /* [KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_10: 39] */
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsLocalKeyMCertInfo
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsLocalKeyMCertInfo
  \brief  Tls KeyM Local Certificate Chain Info
  \details
  Element       Description
  LeafCertId    Leaf certificate KeyMCertId
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_TlsLocalKeyMCertInfoType, TCPIP_CONST) TcpIp_TlsLocalKeyMCertInfo[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LeafCertId                                                         Referable Keys */
  { /*     0 */ KeyMConf_KeyMCertificate_SccCertificate_ISO20_VehicleCert_0 }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsRemoteKeyMCertInfo
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsRemoteKeyMCertInfo
  \brief  Tls KeyM Remote Certificate Chain Info
  \details
  Element        Description
  CertGroupId    Leaf certificate KeyMCertId
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_TlsRemoteKeyMCertInfoType, TCPIP_CONST) TcpIp_TlsRemoteKeyMCertInfo[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CertGroupId                                                            Referable Keys */
  { /*     0 */ KeyMConf_KeyMCertificateGroup_SccCertificateGroup_TlsConnection }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TxReqElemList
**********************************************************************************************************************/
/** 
  \var    TcpIp_TxReqElemList
  \brief  UDP TX request list configuration
  \details
  Element              Description
  TxReqElemEndIdx      the end index of the 1:n relation pointing to TcpIp_TxReqElem
  TxReqElemLength      the number of relations pointing to TcpIp_TxReqElem
  TxReqElemStartIdx    the start index of the 1:n relation pointing to TcpIp_TxReqElem
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_TxReqElemListType, TCPIP_CONST) TcpIp_TxReqElemList[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxReqElemEndIdx  TxReqElemLength  TxReqElemStartIdx */
  { /*     0 */              1u,              1u,                0u }
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_UdpConfig
**********************************************************************************************************************/
/** 
  \var    TcpIp_UdpConfig
  \details
  Element    Description
  PortMax    Udp Dynamic Port Max - Value of configuration parameter TcpIpUdpPortMax
  PortMin    Udp Dynamic Port Min - Value of configuration parameter TcpIpUdpPortMin
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_UdpConfigType, TCPIP_CONST) TcpIp_UdpConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PortMax  PortMin */
  { /*     0 */  65535u,  49152u }
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_EthIfCtrlDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_EthIfCtrlDyn
  \brief  -
  \details
  Element    Description
  State      State of the controller
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_EthIfCtrlDynType, TCPIP_VAR_NO_INIT) TcpIp_EthIfCtrlDyn[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_IcmpV6TxMsgBuffer
**********************************************************************************************************************/
/** 
  \var    TcpIp_IcmpV6TxMsgBuffer
  \brief  -
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_IcmpV6TxMsgBufferType, TCPIP_VAR_NO_INIT) TcpIp_IcmpV6TxMsgBuffer[1280];  /* PRQA S 1514, 1533, 0612, 0613 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_BigStructure, MD_CSL_BigStructure */
#define TCPIP_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_InterfaceIdentifier
**********************************************************************************************************************/
/** 
  \var    TcpIp_InterfaceIdentifier
  \brief  -
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_InterfaceIdentifierUType, TCPIP_VAR_NO_INIT) TcpIp_InterfaceIdentifier;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpCtrl/TcpIpIpVXCtrl/TcpIpIpV6Ctrl] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpCtrl/TcpIpIpVXCtrl/TcpIpIpV6Ctrl] */
  /*    63 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpCtrl/TcpIpIpVXCtrl/TcpIpIpV6Ctrl] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_IpV6CtrlDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_IpV6CtrlDyn
  \brief  -
  \details
  Element                                  Description
  BaseReachableTimeMs                      Time a neighbor is considered to be reachable.
  LinkLocalDadDelayMs                      Holds the delay for the link local address for DAD algorithm.
  ReachableTimeMs                          Time a neighbor is considered to be reachable.
  RetransTimerMs                           Interval between retransmissions.
  DefaultLinkMtu                           -
  CtrlPreviousState                        -
  CtrlState                                -
  CurHopLimit                              Hop Limit for outgoing packets, may be changed by received RAs.
  IpV6DefaultRouterListEntryValidEndIdx    the index of the 1:1 relation pointing to TcpIp_IpV6DefaultRouterListEntry
  IpV6DestinationCacheEntryValidEndIdx     the index of the 1:1 relation pointing to TcpIp_IpV6DestinationCacheEntry
  IpV6NeighborCacheEntryValidEndIdx        the index of the 1:1 relation pointing to TcpIp_IpV6NeighborCacheEntry
  IpV6PrefixListEntryValidEndIdx           the index of the 1:1 relation pointing to TcpIp_IpV6PrefixListEntry
  Ndp_RouterSolicitationTxCount            -
  PreOnHoldCtrlState                       -
  LastBcAddrPtr                            -
  Ndp_PendingDadNa                         -
  Ndp_RouterSolicitationNextTxTime         -
  NextRouterProbeIdx                       -
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_IpV6CtrlDynUType, TCPIP_VAR_NO_INIT) TcpIp_IpV6CtrlDyn;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpCtrl] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_IpV6DefaultRouterListEntry
**********************************************************************************************************************/
/** 
  \var    TcpIp_IpV6DefaultRouterListEntry
  \brief  -
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_IpV6DefaultRouterListEntryUType, TCPIP_VAR_NO_INIT) TcpIp_IpV6DefaultRouterListEntry;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpCtrl/TcpIpIpVXCtrl/TcpIpIpV6Ctrl] */
  /*     1 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpCtrl/TcpIpIpVXCtrl/TcpIpIpV6Ctrl] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_IpV6DestinationCacheEntry
**********************************************************************************************************************/
/** 
  \var    TcpIp_IpV6DestinationCacheEntry
  \brief  -
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_IpV6DestinationCacheEntryUType, TCPIP_VAR_NO_INIT) TcpIp_IpV6DestinationCacheEntry;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpCtrl/TcpIpIpVXCtrl/TcpIpIpV6Ctrl] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpCtrl/TcpIpIpVXCtrl/TcpIpIpV6Ctrl] */
  /*     4 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpCtrl/TcpIpIpVXCtrl/TcpIpIpV6Ctrl] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_IpV6EthBufData
**********************************************************************************************************************/
/** 
  \var    TcpIp_IpV6EthBufData
  \brief  -
  \details
  Element             Description
  IpV6SocketDynIdx    the index of the 0:1 relation pointing to TcpIp_IpV6SocketDyn
  UlTxReqTabIdx       Store which socket index belongs to the BufIdx of CtrlIdx.
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_IpV6EthBufDataUType, TCPIP_VAR_NO_INIT) TcpIp_IpV6EthBufData;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig] */
  /*     1 */  /* [/ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_IpV6NeighborCacheEntry
**********************************************************************************************************************/
/** 
  \var    TcpIp_IpV6NeighborCacheEntry
  \brief  -
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_IpV6NeighborCacheEntryUType, TCPIP_VAR_NO_INIT) TcpIp_IpV6NeighborCacheEntry;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpCtrl/TcpIpIpVXCtrl/TcpIpIpV6Ctrl] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpCtrl/TcpIpIpVXCtrl/TcpIpIpV6Ctrl] */
  /*     4 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpCtrl/TcpIpIpVXCtrl/TcpIpIpV6Ctrl] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_IpV6PrefixListEntry
**********************************************************************************************************************/
/** 
  \var    TcpIp_IpV6PrefixListEntry
  \brief  -
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_IpV6PrefixListEntryUType, TCPIP_VAR_NO_INIT) TcpIp_IpV6PrefixListEntry;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpCtrl/TcpIpIpVXCtrl/TcpIpIpV6Ctrl] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpCtrl/TcpIpIpVXCtrl/TcpIpIpV6Ctrl] */
  /*     4 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpCtrl/TcpIpIpVXCtrl/TcpIpIpV6Ctrl] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_IpV6SocketDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_IpV6SocketDyn
  \brief  -
  \details
  Element                             Description
  IpV6HdrVersionTcFlNbo               -
  EthIfFramePrio                      -
  Flags                               -
  HopLimit                            -
  IpV6DestinationCacheEntryHintIdx    the index of the 0:1 relation pointing to TcpIp_IpV6DestinationCacheEntry
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_IpV6SocketDynType, TCPIP_VAR_NO_INIT) TcpIp_IpV6SocketDyn[7];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [UDP] */
  /*     1 */  /* [TCP] */
  /*   ... */  /* [TCP] */
  /*     3 */  /* [TCP] */
  /*     4 */  /* [TCP-RST] */
  /*     5 */  /* [ICMPv6] */
  /*     6 */  /* [NDP] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_IpV6SourceAddressTableEntry
**********************************************************************************************************************/
/** 
  \var    TcpIp_IpV6SourceAddressTableEntry
  \brief  -
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(IpV6_SourceAddressTableEntryType, TCPIP_VAR_NO_INIT) TcpIp_IpV6SourceAddressTableEntry[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpV6LocalAddr_TcpIpCtrl_LinkLocal, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpCtrl/TcpIpIpVXCtrl/TcpIpIpV6Ctrl] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_LocalAddr
**********************************************************************************************************************/
/** 
  \var    TcpIp_LocalAddr
  \details
  Element            Description
  AssignmentState    -
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_LocalAddrUType, TCPIP_VAR_NO_INIT) TcpIp_LocalAddr;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpV6LocalAddr_TcpIpCtrl_LinkLocal] */
  /*     1 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpV6LocalAddr_TcpIpCtrl_AsAn] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_RstTxQueueBuffer
**********************************************************************************************************************/
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_RstTxQueueBufferUType, TCPIP_VAR_NO_INIT) TcpIp_RstTxQueueBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [SINGLECORE_APPLICATION] */
  /*   ... */  /* [SINGLECORE_APPLICATION] */
  /*     7 */  /* [SINGLECORE_APPLICATION] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_RxBufStructMgt
**********************************************************************************************************************/
/** 
  \var    TcpIp_RxBufStructMgt
  \brief  Rx buffer struct management
  \details
  Element              Description
  RxBufStructSegIdx    the index of the 1:1 relation pointing to TcpIp_RxBufStructSeg
  RxBufStructSegLvl    Level of used TcpIp_TlsRxBufStructSegs
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_RxBufStructMgtUType, TCPIP_VAR_NO_INIT) TcpIp_RxBufStructMgt;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_RxBufStructSeg
**********************************************************************************************************************/
/** 
  \var    TcpIp_RxBufStructSeg
  \brief  Rx buffer struct segment to store data segment
  \details
  Element    Description
  Len        Length of the segment
  DataPtr    the pointer to segment data
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_RxBufStructSegUType, TCPIP_VAR_NO_INIT) TcpIp_RxBufStructSeg;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*     1 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_SocketDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_SocketDyn
  \brief  Generic (TCP/UDP) socket variables
  \details
  Element                 Description
  ListenActiveConnStat    Current state of the socket
  LocalAddrBindIdx        the index of the 0:1 relation pointing to TcpIp_LocalAddr
  SocketOwnerConfigIdx    the index of the 0:1 relation pointing to TcpIp_SocketOwnerConfig
  TxBufRequested          TX buffer request semaphore
  TxIpAddrIdx             Index of local IPxV address that is used for transmission
  LocSock                 IP address and port of the local host
  RemSock                 IP address and port of the remote host
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_SocketDynUType, TCPIP_VAR_NO_INIT) TcpIp_SocketDyn;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [UDP] */
  /*     1 */  /* [TCP] */
  /*   ... */  /* [TCP] */
  /*     3 */  /* [TCP] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_SocketTcpDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_SocketTcpDyn
  \brief  TCP socket specific variables
  \details
  Element                              Description
  DupAckNumber                         SEQ-Number of the current duplicated ACKs.
  FinWait2Timeout                      -
  IdleTimeoutShort                     -
  Iss                                  -
  Msl                                  Current Msl of the socket
  MslTimeout                           Remaining time of MSL
  RcvNxt                               -
  RetransmitTimeout                    -
  RetransmitTimeoutDefault             Used to store the configured timeout value or the timeout value set by the ChangeParameter API
  RtoReloadValue                       -
  SndNxt                               -
  SndNxtAfterFin                       TX sequence number that follows the FIN.
  SndUna                               -
  SndWl1                               -
  SndWl2                               -
  TxNextSendSeqNo                      -
  TxReqSeqNo                           Sequence number of first pending TX request.
  MaxNumListenSockets                  -
  PathMtuNewSize                       -
  RcvWnd                               -
  SndWnd                               -
  TxMaxSegLenByte                      -
  TxMssAgreed                          Maximum segment size agreed during connection setup
  DupAckCount                          Count of the current duplicated ACKs
  EventIndicationPending               Variable contains the pending events that have to be forwarded to the socket user
  PathMtuChanged                       -
  RetryQFillNum                        -
  RstReceived                          -
  SendLastHsAck                        Flag to indicate if the next ACK is the last of the handshake
  SockIsServer                         -
  SockState                            -
  SockStateNext                        -
  SocketTcpDynMasterListenSocketIdx    the index of the 0:1 relation pointing to TcpIp_SocketTcpDyn
  TcpRetryQElementFirstIdx             the index of the 0:1 relation pointing to TcpIp_TcpRetryQElement
  TcpRetryQElementLastIdx              the index of the 0:1 relation pointing to TcpIp_TcpRetryQElement
  TcpRxBufferDescIdx                   the index of the 0:1 relation pointing to TcpIp_TcpRxBufferDesc
  TcpTxBufferDescIdx                   the index of the 0:1 relation pointing to TcpIp_TcpTxBufferDesc
  TlsConnectionIdx                     the index of the 0:1 relation pointing to TcpIp_TlsConnection
  TxFlags                              -
  TxOneTimeOpts                        -
  TxOneTimeOptsLen                     -
  TxOptLen                             -
  TxReqFullyQueued                     all unqueued data from this request is used within the next segment
  UseTls                               -
  RequestedRxBufferSize                -
  RequestedTxBufferSize                -
  RxBufferIndPos                       -
  RxBufferRemIndLen                    -
  TxLenByteTx                          -
  TxReqDataBufStartIdx                 byte position inside the TxBuffer
  TxReqDataLenByte                     length of data to be transmitted
  TxReqQueuedLen                       length of data that could already be queued for transmission
  TxTotNotQueuedLen                    -
*/ 
#define TCPIP_START_SEC_SOCKETTCPDYN_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(TcpIp_SocketTcpDynType, TCPIP_VAR_NO_INIT) TcpIp_SocketTcpDyn[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_SOCKETTCPDYN_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_SocketTcpNagleDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_SocketTcpNagleDyn
  \brief  Manages the state of nagle's algorithm
  \details
  Element    Description
  Enabled    -
  Timeout    -
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_SocketTcpNagleDynType, TCPIP_VAR_NO_INIT) TcpIp_SocketTcpNagleDyn[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_SocketTcpOooDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_SocketTcpOooDyn
  \brief  Manages the state of TCP segments that arrive out of order
  \details
  Element                   Description
  TcpOooQElementFirstIdx    the index of the 0:1 relation pointing to TcpIp_TcpOooQElement
  TcpOooQFillNum            -
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_SocketTcpOooDynType, TCPIP_VAR_NO_INIT) TcpIp_SocketTcpOooDyn[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_SocketUdpDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_SocketUdpDyn
  \brief  UDP socket specific variables
  \details
  Element                  Description
  TxReqElemListIdx         the index of the 0:1 relation pointing to TcpIp_TxReqElemList
  TxRetrQueueMaxNum        Maximum number of TX retry queue elements for the socket.
  UdpChecksum              Indicate of the checksum is active for this socket
  IpTxRequestDescriptor    TX request descriptor required for the IP layer
  TxReqIpBufPtr            Pointer to the provided TX buffer of the IP layer
  TxRetrQueue              TX retry queue
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_SocketUdpDynType, TCPIP_VAR_NO_INIT) TcpIp_SocketUdpDyn[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TcpOooQElement
**********************************************************************************************************************/
#define TCPIP_START_SEC_TCPOOOQELEMENT_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_Tcp_RxPreBufEleType, TCPIP_VAR_NO_INIT) TcpIp_TcpOooQElement[15];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_TCPOOOQELEMENT_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TcpRetryQElement
**********************************************************************************************************************/
#define TCPIP_START_SEC_TCPRETRYQELEMENT_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_Tcp_TxRetrQueueType, TCPIP_VAR_NO_INIT) TcpIp_TcpRetryQElement[30];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_TCPRETRYQELEMENT_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TcpRstHandlingDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_TcpRstHandlingDyn
  \details
  Element                       Description
  ApplicationIdsApplIdIdx       the index of the 0:1 relation pointing to TcpIp_ApplicationIds
  RstTxQueueBufferFillMaxIdx    the index of the 0:1 relation pointing to TcpIp_RstTxQueueBuffer
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TcpRstHandlingDynType, TCPIP_VAR_NO_INIT) TcpIp_TcpRstHandlingDyn[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TcpRxBuffer
**********************************************************************************************************************/
/** 
  \var    TcpIp_TcpRxBuffer
  \brief  TCP TX buffers
*/ 
#define TCPIP_START_SEC_TCPRXBUFFER_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TcpRxBufferUType, TCPIP_VAR_NO_INIT) TcpIp_TcpRxBuffer;  /* PRQA S 0759, 1514, 1533, 0612, 0613 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_BigStructure, MD_CSL_BigStructure */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTcpConfig/TcpIpTcpSocketBuffer_Secp256] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTcpConfig/TcpIpTcpSocketBuffer_Secp256] */
  /*  7599 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTcpConfig/TcpIpTcpSocketBuffer_Secp256] */
  /*  7600 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTcpConfig/TcpIpTcpSocketBuffer_Secp521] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTcpConfig/TcpIpTcpSocketBuffer_Secp521] */
  /* 17599 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTcpConfig/TcpIpTcpSocketBuffer_Secp521] */
  /* 17600 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTcpConfig/TcpIpTcpSocketBuffer_Scc] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTcpConfig/TcpIpTcpSocketBuffer_Scc] */
  /* 28849 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTcpConfig/TcpIpTcpSocketBuffer_Scc] */

#define TCPIP_STOP_SEC_TCPRXBUFFER_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TcpRxBufferDescDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_TcpRxBufferDescDyn
  \details
  Element                Description
  TcpRxBufferWriteIdx    the index of the 1:1 relation pointing to TcpIp_TcpRxBuffer
  SocketTcpDynIdx        the index of the 0:1 relation pointing to TcpIp_SocketTcpDyn
  FillLevel          
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TcpRxBufferDescDynType, TCPIP_VAR_NO_INIT) TcpIp_TcpRxBufferDescDyn[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TcpTxBuffer
**********************************************************************************************************************/
/** 
  \var    TcpIp_TcpTxBuffer
  \brief  TCP TX buffers
*/ 
#define TCPIP_START_SEC_TCPTXBUFFER_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TcpTxBufferUType, TCPIP_VAR_NO_INIT) TcpIp_TcpTxBuffer;  /* PRQA S 0759, 1514, 1533, 0612, 0613 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_BigStructure, MD_CSL_BigStructure */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTcpConfig/TcpIpTcpSocketBuffer_Secp256] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTcpConfig/TcpIpTcpSocketBuffer_Secp256] */
  /*  8379 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTcpConfig/TcpIpTcpSocketBuffer_Secp256] */
  /*  8380 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTcpConfig/TcpIpTcpSocketBuffer_Secp521] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTcpConfig/TcpIpTcpSocketBuffer_Secp521] */
  /* 16826 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTcpConfig/TcpIpTcpSocketBuffer_Secp521] */
  /* 16827 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTcpConfig/TcpIpTcpSocketBuffer_Scc] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTcpConfig/TcpIpTcpSocketBuffer_Scc] */
  /* 26826 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTcpConfig/TcpIpTcpSocketBuffer_Scc] */

#define TCPIP_STOP_SEC_TCPTXBUFFER_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TcpTxBufferDescDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_TcpTxBufferDescDyn
  \details
  Element                Description
  TcpTxBufferWriteIdx    the index of the 1:1 relation pointing to TcpIp_TcpTxBuffer
  SocketTcpDynIdx        the index of the 0:1 relation pointing to TcpIp_SocketTcpDyn
  FillLevel          
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TcpTxBufferDescDynType, TCPIP_VAR_NO_INIT) TcpIp_TcpTxBufferDescDyn[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsBufferMgmtDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsBufferMgmtDyn
  \details
  Element                                                     Description
  RemainingHsPlaintextLenInRxBuf                              The length of the received HS plaintext data in the TLS Rx buffer after the HS is completed. This data has to be removed from the buffer after parsing.
  RlTxContentTypeLen                                          Length of the TX Content Type without MAC or Padding
  RlTxCopiedLen                                               Copied length of requested data
  RlTxFragmentLen                                             Fragment length of the Transmit
  RxUpperlayerReleasedDataLen                                 Indicate how many bytes are released by the upper layer since the last Mainfunction
  RlRxCopiedLen                                               Copied len of received data
  TlsBufferRxAdHsCurrHsMsgEndIdx                              the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxAdHsReadIdx                                      the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxAdHsWriteIdx                                     the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxAlReadIdx                                        the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxAlWriteIdx                                       the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxCcsReadIdx                                       the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxCcsWriteIdx                                      the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxHbReadIdx                                        the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxHbWriteIdx                                       the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxRlFrameStartIdx                                  the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxUlRxIndIdx                                       the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferTxAdHsReadIdx                                      the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxAdHsWriteIdx                                     the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxAlReadIdx                                        the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxAlWriteIdx                                       the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxByteOverwrittenByInnerPlainTextContentTypeIdx    the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxCcsReadIdx                                       the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxCcsWriteIdx                                      the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxHbReadIdx                                        the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxHbWriteIdx                                       the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxRlSendIdx                                        the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  RlTxContentType                                             Content type of the Frame which should be transmitted
  RlTxInnerPlaintextContentType                               Content type of the Frame which should be transmitted
  RlTxValueOfByteOverwrittenByInnerPlainTextContentType       The value of the byte temporarily overwritten to add the inner plaintext content type to the buffer
  TxInnerContentTypeAdded                                     Flag which indicates if the inner content type (TLS 1.3) was added.
  AdRxFillLevel                                               Fill level of the TLS Application data RX buffer
  AdTxFillLevel                                               Fill level of the TLS Application data TX buffer
  AdUlRxIndLevel                                              Position of Ul Rx Indication
  RxDataSplit                                                 Struct to store the Rx Data Split offset
  TxDataSplit                                                 Struct to store the Tx Data Split offset
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsBufferMgmtDynUType, TCPIP_VAR_NO_INIT) TcpIp_TlsBufferMgmtDyn;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsBufferRx
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsBufferRx
  \brief  Rx Buffer for TLS
*/ 
#define TCPIP_START_SEC_TLSBUFFERRX_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsBufferRxUType, TCPIP_VAR_NO_INIT) TcpIp_TlsBufferRx;  /* PRQA S 0759, 1514, 1533, 0612, 0613 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_BigStructure, MD_CSL_BigStructure */
  /* Index        Referable Keys */
  /*     0 */  /* [TlsConnectionConfig_Scc_ADHS_RX_BUFFERSIZE] */
  /*   ... */  /* [TlsConnectionConfig_Scc_ADHS_RX_BUFFERSIZE] */
  /*  7728 */  /* [TlsConnectionConfig_Scc_ADHS_RX_BUFFERSIZE] */
  /*  7729 */  /* [TlsConnectionConfig_Scc_AL_RX_BUFFERSIZE] */
  /*   ... */  /* [TlsConnectionConfig_Scc_AL_RX_BUFFERSIZE] */
  /*  7858 */  /* [TlsConnectionConfig_Scc_AL_RX_BUFFERSIZE] */
  /*  7859 */  /* [TlsConnectionConfig_Scc_CCS_RX_BUFFERSIZE] */
  /*  7860 */  /* [TlsConnectionConfig_Scc_CCS_RX_BUFFERSIZE] */

#define TCPIP_STOP_SEC_TLSBUFFERRX_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsBufferTx
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsBufferTx
  \brief  Tx Buffer for TLS
*/ 
#define TCPIP_START_SEC_TLSBUFFERTX_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsBufferTxUType, TCPIP_VAR_NO_INIT) TcpIp_TlsBufferTx;  /* PRQA S 0759, 1514, 1533, 0612, 0613 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_BigStructure, MD_CSL_BigStructure */
  /* Index        Referable Keys */
  /*     0 */  /* [TlsConnectionConfig_Scc_ADHS_TX_BUFFERSIZE] */
  /*   ... */  /* [TlsConnectionConfig_Scc_ADHS_TX_BUFFERSIZE] */
  /*  8447 */  /* [TlsConnectionConfig_Scc_ADHS_TX_BUFFERSIZE] */
  /*  8448 */  /* [TlsConnectionConfig_Scc_AL_TX_BUFFERSIZE] */
  /*   ... */  /* [TlsConnectionConfig_Scc_AL_TX_BUFFERSIZE] */
  /*  8450 */  /* [TlsConnectionConfig_Scc_AL_TX_BUFFERSIZE] */
  /*  8451 */  /* [TlsConnectionConfig_Scc_CCS_TX_BUFFERSIZE] */

#define TCPIP_STOP_SEC_TLSBUFFERTX_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsCertValidationStatusDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsCertValidationStatusDyn
  \brief  Struct to store KeyM Certificate Information
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsCertValidationStatusDynUType, TCPIP_VAR_NO_INIT) TcpIp_TlsCertValidationStatusDyn;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*     5 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsCipherWorkerDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsCipherWorkerDyn
  \details
  Element                  Description
  TlsHandshakeActiveIdx    the index of the 0:1 relation pointing to TcpIp_TlsHandshake
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsCipherWorkerDynType, TCPIP_VAR_NO_INIT) TcpIp_TlsCipherWorkerDyn[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*     1 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_CHACHA20_POLY1305_SHA256_Secp521r1, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*     2 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_WITH_AES_256_GCM_SHA384_Secp521r1] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsCipherWorkingSetMgmt
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsCipherWorkingSetMgmt
  \details
  Element                         Description
  CipherSuiteWorkingSet           Type to store the working set of cipher suites
  SignatureAlgorithmWorkingSet    Type to store the working set of signature algorithms
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsCipherWorkingSetMgmtUType, TCPIP_VAR_NO_INIT) TcpIp_TlsCipherWorkingSetMgmt;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsClientAuthenticationMgmt
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsClientAuthenticationMgmt
  \details
  Element           Description
  ClientCertInfo    Type to store the information of the client certificates that should be sent
  RequestInfo       Type to store the information of a certificate request message
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsClientAuthenticationMgmtUType, TCPIP_VAR_NO_INIT) TcpIp_TlsClientAuthenticationMgmt;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsClientBufferMgmt
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsClientBufferMgmt
  \details
  Element                                             Description
  ServerCertStatusOcspResponseLen                     Length of the received OCSP response
  ClientCertificateLen                                Length of the ClientCertificate message to be transmitted
  ClientCertificateVerifyLen                          Length of the ClientCertificateVerify message to be transmitted
  ClientFinishedLen                                   Length of the ClientFinished message to be transmitted
  ClientHelloLen                                      Length of the ClienHello message to be transmitted
  ClientKeyExchangeLen                                Length of the ClienKeyExchange message to be transmitted
  EncryptedExtensionsLen                              Length of the received EncryptedExtensions message
  ServerCertificateRequestLen                         Length of the received ServerCertificateRequest message
  ServerCertificateStatusLen                          Length of the received ServerCertificateStatus message
  ServerCertificateVerifyLen                          Length of the received ServerCertificateVerify message
  ServerCertificatesLen                               Length of the received ServerCertificates message
  ServerFinishedLen                                   Length of the received ServerFinished message
  ServerHelloDoneLen                                  Length of the received ServerHelloDone message
  ServerHelloLen                                      Length of the received ServerHello message
  ServerKeyExchangeLen                                Length of the received ServerKeyExchangeLen message
  ServerKeyExchangePskHintLen                         Length of the received Server KeyExchange PSK Hint
  TlsBufferRxEncryptedExtensionsIdx                   the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxServerCertStatusOcspResponseIdx          the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxServerCertificateRequestCertTypesIdx     the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxServerCertificateRequestIdx              the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxServerCertificateStatusIdx               the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxServerCertificateVerifyIdx               the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxServerCertificatesIdx                    the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxServerFinishedIdx                        the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxServerFinishedVerifyDataIdx              the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxServerHelloDoneIdx                       the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxServerHelloIdx                           the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxServerKeyExchangeIdx                     the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxServerKeyExchangeParamsIdx               the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxServerKeyExchangePskHintIdx              the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxServerKeyExchangePskParamIdx             the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxServerKeyExchangePubKeyIdx               the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxServerKeyExchangePubKeyLenIdx            the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxServerRandomIdx                          the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxServerSessionIdIdx                       the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxServerSignatureIdx                       the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferRxServerSignatureLenIdx                    the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
  TlsBufferTxClientCertVerifySignatureLenIdx          the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxClientCertificateIdx                     the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxClientCertificateVerifyIdx               the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxClientDoneIdx                            the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxClientExtensionsIdx                      the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxClientFinishedIdx                        the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxClientFinishedVerifyDataIdx              the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxClientHelloIdx                           the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxClientHelloPreSharedKeyExtBinderIdx      the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxClientKeyExchangeIdx                     the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxClientKeyExchangePubKeyIdx               the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxClientKeyExchangePubKeyLenIdx            the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxClientKeyShareExtensionIdx               the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxClientRandomIdx                          the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxClientSessionIdIdx                       the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  TlsBufferTxClientSignatureAlgorithmsExtensionIdx    the index of the 0:1 relation pointing to TcpIp_TlsBufferTx
  ServerHelloSessionIdLen                             Length of the received ServerHello SessionId
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsClientBufferMgmtUType, TCPIP_VAR_NO_INIT) TcpIp_TlsClientBufferMgmt;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsClientConnection
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsClientConnection
  \details
  Element                                     Description
  ResumptionBaseConnectionAge                 Age of a connection counting from the point the resumption master secret is calculated
  IdxForNextGroupToCalculatePubKey            Idx of the group for which a public key should be calculated in the next iteration
  ReceivedCipherSuiteId                       ID of the received cipher suite in the ServerHello for this TLS connection
  CalcClientCertVerifySignatureAsyncFlag      Flag to indicate the Async Ctx for CertificateVerify signature calculation
  CalcClientFinishedHashAsyncFlag             Flag to indicate the Async Ctx for ClientFinished hash generation
  CalcFinishedKeyAsyncFlag                    Flag to indicate the Async Ctx for FinishedKey calculation
  CalcServerFinishedHashAsyncFlag             Flag to indicate the Async Ctx for ServerFinished hash generation
  CalcServerFinishedVerifyDataAsyncFlag       Flag to indicate the Async Ctx for ServerFinishedVerifyData hash generation
  CertificateStatusOcspValidationAsyncFlag    Flag to indicate the Async Ctx for the Certificate Status OCSP response validation
  CertificateVerifyReadyToSend                Flag that marks the Client Change CertificateVerify message as transmittable
  ChangeCipherSpecReadyToSend                 Flag that marks the Client Change CipherSpec message as transmittable
  ClientCertificateReadyToSend                Flag that marks the Client Certificate message as transmittable
  ClientFinishedReadyToSend                   Flag that marks the Client Finished message as transmittable
  HelloReadyToSend                            Flag that marks the Client Hello message as transmittable
  HsVerifySignatureAsyncFlag                  Flag indicates signature verification async task is triggered
  KeyExchangeReadyToSend                      Flag that marks the Client Key exchange message as transmittable
  SccPushButtonMode                           Flag that indicates the push button mode from the SCC upper layer
  SendCertificateVerify                       Flag that marks that a CertificateVerify message should be sent
  VerifyCertVerifySignatureAsyncFlag          Flag to indicate the Async Ctx for CertificateVerify signature verification
  RootCertId                                  ID of the used root certificate for this TLS connection
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsClientConnectionUType, TCPIP_VAR_NO_INIT) TcpIp_TlsClientConnection;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsClientOcspBufferMgmt
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsClientOcspBufferMgmt
  \details
  Element                                   Description
  ServerCertStatusResponseLen               Length of the received OCSP response
  TlsBufferRxServerCertStatusResponseIdx    the index of the 0:1 relation pointing to TcpIp_TlsBufferRx
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsClientOcspBufferMgmtUType, TCPIP_VAR_NO_INIT) TcpIp_TlsClientOcspBufferMgmt;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*     4 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsClientRandomAccessBuffer
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsClientRandomAccessBuffer
  \brief  Temporary Buffer for support master secret API to access the client random
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsClientRandomAccessBufferUType, TCPIP_VAR_NO_INIT) TcpIp_TlsClientRandomAccessBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*    31 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsClientSessionIdAccessBuffer
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsClientSessionIdAccessBuffer
  \brief  Temporary Buffer for support master secret API to access the client session ID
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsClientSessionIdAccessBufferUType, TCPIP_VAR_NO_INIT) TcpIp_TlsClientSessionIdAccessBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*    31 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsConnectionDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsConnectionDyn
  \details
  Element                                               Description
  LastRlRxSequenceCounter                               Sequence Counter used for last encryption of RX message
  LastRlTxSequenceCounter                               Sequence Counter used for last encryption of TX message
  RlRxSequenceCounter                                   Sequence Counter for RX messages
  RlTxSequenceCounter                                   Sequence Counter for TX messages
  KeyBlockSize                                          Size for the Key Block which must be generated to calculate the master secret
  ReceivedBytesOfLastHsMsgPartiallyReceived             Received bytes of the last HS message if it was only partially received
  RemainingBytesOfLastHsMsgPartiallyReceived            Remaining bytes of the last HS message if it was only partially received
  ActiveMaxTxRlSize                                     Active maximum length in bytes of a transmitted TLS fragment
  RxRecordSizeLimit                                     Record Size Limit for RX messages (configured value)
  TxRecordSizeLimit                                     Record Size Limit for TX messages (value updated by received extension
  AdRxIndication                                        Flag which indicate application data reception
  Aes128CbcPaddingByte                                  Padding byte value for AES-128 CBC Operation
  AlRxIndication                                        Flag which indicate alert message reception
  BlockDecryptOperationsUntilKeysAreCalculated          Flag which indicates that decryption shall be blocked until the next keys are calculated
  CalcApplTrafficKeysAsyncFlag                          Flag which indicates the pending calculation in the asynchronous context for the TLS 1.3 application traffic keys
  CalcHsTrafficKeysAsyncFlag                            Flag which indicates the pending calculation in the asynchronous context for the TLS 1.3 handshake traffic keys
  CalcMasterSecretAsyncFlag                             Flag which indicates the pending calculation in the asynchronous context for the master secret generation
  CalcPskValueAsyncFlag                                 Flag which indicates the pending calculation in the asynchronous context for the TLS 1.3 session resumption PSK value
  CalcResumptionMasterSecretAsyncFlag                   Flag which indicates the pending calculation in the asynchronous context for the TLS 1.3 session resumption master secret key
  CcsReceivable                                         Flag which indicates that a change cipher spec message is receivable
  CcsReceived                                           Flag which indicated the reception of a CCS message
  CcsRxIndication                                       Flag which indicate change cipher spec message reception
  ClientSessionIdAccessBufferLen                        Length of the SessionId stored in Access Buffer for the Master Secret API
  DhPubKeyKeyExchangeAsyncFlag                          Flag which indicates the pending calculation in the asynchronous context for the DH public key generation of the Key Exchange message
  DhSharedSecretAsyncFlag                               Flag which indicates the pending calculation in the asynchronous context for the DH shared secret generation
  ExpectServerCertificateStatusMessage                  Specifies that the Client expect the ServerCertificateStatus message
  ExtensionRecordSizeLimitReceived                      Flag that indicated that the record size limit extension was received from the peer connection
  HelloRequestDuringHsRxIndicationFlag                  Flag which indicates HelloRequest reception (during TLS handshake)
  HsRxIndicationCnt                                     Counter to indicate Handshake Message reception
  HsStmTxTrigger                                        Flag which indicates to reenter the handshake statemachine when a transmit operation is required
  LastReceivedContentType                               Holds the information about the last received content type
  LastReceivedHsType                                    Holds the information about the last received Handshake type message
  MandatoryReceivedCertificateStatusRequestExtension    Specifies that the Client expect the mandatory extension for CertificateStatus request
  MsgPrecedingKeyChangeNotAlignWithBoundary             Flag which indicates that a message preceding a key change does not align with a RL boundary
  MsgPrecedingKeyChangePartiallyReceived                Flag which indicates that message which preceeds a key change was only received partially
  NssApplicationTrafficSecretReadyToSend                Flag to indicate if application secret can be send
  NssHandshakeTrafficSecretReadyToSend                  Flag to indicate if handshake secret can be send
  NssMasterSecretReadyToSend                            Flag to indicate if master secret can be send
  PskPremasterSecretAsyncFlag                           Flag which indicates the pending calculation in the asynchronous context for the PSK premaster secret generation
  ReceivedBytesOfLastHsHeaderPartiallyReceived          Received bytes of the last HS header if it was only partially received
  RlRxIndicationFlag                                    Flag which indicate Record Layer reception
  SessionResumptionUsingPsk                             Specifies if the handshake for this connection shall be performed with session resumption using a PSK
  SocketDynComIdx                                       the index of the 0:1 relation pointing to TcpIp_SocketDyn
  SocketDynListenIdx                                    the index of the 0:1 relation pointing to TcpIp_SocketDyn
  SocketOwnerConfigIdx                                  the index of the 0:1 relation pointing to TcpIp_SocketOwnerConfig
  Tls13PskIdentityActiveIdx                             the index of the 0:1 relation pointing to TcpIp_Tls13PskIdentity
  TlsCertValidationStatusDynCurrentIdx                  the index of the 0:1 relation pointing to TcpIp_TlsCertValidationStatusDyn
  TlsCertValidationStatusDynValidEndIdx                 the index of the 0:1 relation pointing to TcpIp_TlsCertValidationStatusDyn
  TlsCipherWorkerActiveIdx                              the index of the 0:1 relation pointing to TcpIp_TlsCipherWorker
  TlsClientOcspBufferMgmtCurrentIdx                     the index of the 0:1 relation pointing to TcpIp_TlsClientOcspBufferMgmt
  TlsClientOcspBufferMgmtValidEndIdx                    the index of the 0:1 relation pointing to TcpIp_TlsClientOcspBufferMgmt
  TlsPskIdentityActiveIdx                               the index of the 0:1 relation pointing to TcpIp_TlsPskIdentity
  TlsUserErrorBufferWriteIdx                            the index of the 0:1 relation pointing to TcpIp_TlsUserErrorBuffer
  TxAlertTrigger                                        Flag which triggers transmission of generic alert message
  TxCloseNotifyTrigger                                  Flag which triggers transmission of CloseNotify message
  VersionSpecificHsStmTrigger                           Flag which indicates to enter the TLS version specific handshake state machine
  ActiveCipherRx                                        Activates cipher for this connection (Rx)
  ActiveCipherTx                                        Activates cipher for this connection (Tx)
  ActiveMaxRxRlSize                                     Active maximum length in bytes of a received TLS fragment
  ActiveVersion                                         Active TLS version of the TLS connection
  CalcKeyMaterialState                                  Active state of the master secret calculation
  ConnectionState                                       Active state of the TLS connection
  DecryptAlgoType                                       Specifies the type of decryption used for current RL processing
  DhPubKeyKeyShareExtCurveAsyncTrigger                  Parameter which indicates the pending calculation in the asynchronous context for the DH public key generation of the Key Share extension for this particular curve
  EllipticCurveId                                       Elliptic curve ID negotiated for the TLS connection
  HandshakeState                                        Active handshake state of the TLS connection within the TLS handshake
  HsAsyncCtxState                                       State for pending asynchronous operation while handshake is in progress
  HsCertState                                           Processing state of the certificate chain used during TLS handshake
  HsLeafCertId                                          Leaf certificate ID used during TLS handshake
  LastHsMsgTypeOfLastReceivedHsRlFrame                  Handshake type of last handshake message in last received RL frame which contains (a) HS message(s)
  TlsCertValidationResult                               Overall certificate chain validation result for this TLS connection
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(TcpIp_TlsConnectionDynUType, TCPIP_VAR_NO_INIT) TcpIp_TlsConnectionDyn;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsHandshakeDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsHandshakeDyn
  \details
  Element              Description
  TlsHandshakeInUse    Flag which indicates the current TLS handshake reference as in use
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsHandshakeDynType, TCPIP_VAR_NO_INIT) TcpIp_TlsHandshakeDyn[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_WITH_AES_256_GCM_SHA384_Secp521r1] */
  /*     1 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_CHACHA20_POLY1305_SHA256_Secp521r1] */
  /*     2 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsListener
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsListener
  \details
  Element         Description
  Port            TCP port on which TLS connection can be established
  SocketDynIdx    the index of the 0:1 relation pointing to TcpIp_SocketDyn
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsListenerType, TCPIP_VAR_NO_INIT) TcpIp_TlsListener[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsSigAlgServerCertReqMsgBuffer
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsSigAlgServerCertReqMsgBuffer
  \brief  Buffer for signature algorithms of ServerCertReqMsg used for client authentication
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsSigAlgServerCertReqMsgBufferUType, TCPIP_VAR_NO_INIT) TcpIp_TlsSigAlgServerCertReqMsgBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*     9 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsTemporaryFinishedBuffer
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsTemporaryFinishedBuffer
  \brief  Temporary Buffer for HMAC operations
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsTemporaryFinishedBufferUType, TCPIP_VAR_NO_INIT) TcpIp_TlsTemporaryFinishedBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*    31 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsTemporaryHashBuffer
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsTemporaryHashBuffer
  \brief  Temporary Buffer for Hash operations
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsTemporaryHashBufferUType, TCPIP_VAR_NO_INIT) TcpIp_TlsTemporaryHashBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*    63 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsTemporaryHkdfHashBuffer
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsTemporaryHkdfHashBuffer
  \brief  Temporary Buffer for Hkdf Hash operations
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsTemporaryHkdfHashBufferUType, TCPIP_VAR_NO_INIT) TcpIp_TlsTemporaryHkdfHashBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*    63 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsTemporaryHmacBuffer
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsTemporaryHmacBuffer
  \brief  Temporary Buffer for HMAC operations
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsTemporaryHmacBufferUType, TCPIP_VAR_NO_INIT) TcpIp_TlsTemporaryHmacBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*    99 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsTemporarySignatureBuffer
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsTemporarySignatureBuffer
  \brief  Temporary Buffer for Signature operations
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsTemporarySignatureBufferUType, TCPIP_VAR_NO_INIT) TcpIp_TlsTemporarySignatureBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*   332 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TlsUserErrorBuffer
**********************************************************************************************************************/
/** 
  \var    TcpIp_TlsUserErrorBuffer
  \brief  Buffer to store TLS user errors
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TlsUserErrorBufferUType, TCPIP_VAR_NO_INIT) TcpIp_TlsUserErrorBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */
  /*     9 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TlsConnectionConfig_Scc] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TxReqElem
**********************************************************************************************************************/
/** 
  \var    TcpIp_TxReqElem
  \brief  UDP TX request list elements
  \details
  Element                 Description
  TxReqElemDataLenByte    -
  TxReqElemTransmitted    -
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TxReqElemUType, TCPIP_VAR_NO_INIT) TcpIp_TxReqElem;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpUdpConfig/TcpIpUdpTxReqList_Scc] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_TxReqElemListDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_TxReqElemListDyn
  \brief  UDP TX request list variables
  \details
  Element            Description
  FillNum            Number of elements currently stored in TX request ring buffer
  ReadPos            Read position of TX request ring buffer
  SocketUdpDynIdx    the index of the 0:1 relation pointing to TcpIp_SocketUdpDyn
  WritePos           Write position in TX request ring buffer
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_TxReqElemListDynType, TCPIP_VAR_NO_INIT) TcpIp_TxReqElemListDyn[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_UdpTxRetryQueueElementChain
**********************************************************************************************************************/
/** 
  \var    TcpIp_UdpTxRetryQueueElementChain
  \brief  UDP TX retry queue element chain
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_DListNodeType, TCPIP_VAR_NO_INIT) TcpIp_UdpTxRetryQueueElementChain[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_UdpTxRetryQueueElements
**********************************************************************************************************************/
/** 
  \var    TcpIp_UdpTxRetryQueueElements
  \brief  UDP TX retry queue elements
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_Udp_RetryQueueElementType, TCPIP_VAR_NO_INIT) TcpIp_UdpTxRetryQueueElements[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_UdpTxRetryQueuePoolDesc
**********************************************************************************************************************/
/** 
  \var    TcpIp_UdpTxRetryQueuePoolDesc
  \brief  UDP TX retry queue element pool
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_DListDescType, TCPIP_VAR_NO_INIT) TcpIp_UdpTxRetryQueuePoolDesc[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_PCConfig
**********************************************************************************************************************/
/** 
  \var    TcpIp_PCConfig
  \details
  Element                                      Description
  DefaultAddrV6                                the pointer to TcpIp_DefaultAddrV6
  DhcpUserOption                               the pointer to TcpIp_DhcpUserOption
  DhcpUserOptionBuffer                         the pointer to TcpIp_DhcpUserOptionBuffer
  DhcpUserOptionDyn                            the pointer to TcpIp_DhcpUserOptionDyn
  IpV6MulticastAddr                            the pointer to TcpIp_IpV6MulticastAddr
  IpV6MulticastAddrActive                      the pointer to TcpIp_IpV6MulticastAddrActive
  PhysAddrConfig                               the pointer to TcpIp_PhysAddrConfig
  PskIdentity                                  the pointer to TcpIp_PskIdentity
  PskIdentityHint                              the pointer to TcpIp_PskIdentityHint
  StaticDefaultRouter                          the pointer to TcpIp_StaticDefaultRouter
  TcpOooQElement                               the pointer to TcpIp_TcpOooQElement
  Tls13PskIdentity                             the pointer to TcpIp_Tls13PskIdentity
  Tls13PskIdentityBuffer                       the pointer to TcpIp_Tls13PskIdentityBuffer
  Tls13PskIdentityDyn                          the pointer to TcpIp_Tls13PskIdentityDyn
  Tls13PskIdentityInd                          the pointer to TcpIp_Tls13PskIdentityInd
  Tls13PskNonceBuffer                          the pointer to TcpIp_Tls13PskNonceBuffer
  TlsCertId                                    the pointer to TcpIp_TlsCertId
  TlsCertValidationStatusDyn                   the pointer to TcpIp_TlsCertValidationStatusDyn
  TlsCipherWorkerInd                           the pointer to TcpIp_TlsCipherWorkerInd
  TlsCipherWorkingSetMgmt                      the pointer to TcpIp_TlsCipherWorkingSetMgmt
  TlsClientAuthenticationMgmt                  the pointer to TcpIp_TlsClientAuthenticationMgmt
  TlsConnection                                the pointer to TcpIp_TlsConnection
  TlsCsmJob                                    the pointer to TcpIp_TlsCsmJob
  TlsKeyMCertificate                           the pointer to TcpIp_TlsKeyMCertificate
  TlsLocalKeyMCertInfo                         the pointer to TcpIp_TlsLocalKeyMCertInfo
  TlsPskIdentity                               the pointer to TcpIp_TlsPskIdentity
  TlsPskIdentityInd                            the pointer to TcpIp_TlsPskIdentityInd
  TlsRemoteKeyMCertInfo                        the pointer to TcpIp_TlsRemoteKeyMCertInfo
  TlsResumedConnection                         the pointer to TcpIp_TlsResumedConnection
  TlsServerNameIndication                      the pointer to TcpIp_TlsServerNameIndication
  TlsSigAlgServerCertReqMsgBuffer              the pointer to TcpIp_TlsSigAlgServerCertReqMsgBuffer
  TlsTemporaryClientAuthEdCurveBuffer          the pointer to TcpIp_TlsTemporaryClientAuthEdCurveBuffer
  TlsUserErrorBuffer                           the pointer to TcpIp_TlsUserErrorBuffer
  TxReqElem                                    the pointer to TcpIp_TxReqElem
  TxReqElemList                                the pointer to TcpIp_TxReqElemList
  TxReqElemListDyn                             the pointer to TcpIp_TxReqElemListDyn
  UdpTxRetryQueueElementChain                  the pointer to TcpIp_UdpTxRetryQueueElementChain
  UdpTxRetryQueueElements                      the pointer to TcpIp_UdpTxRetryQueueElements
  UdpTxRetryQueuePoolDesc                      the pointer to TcpIp_UdpTxRetryQueuePoolDesc
  SizeOfDefaultAddrV6                          the number of accomplishable value elements in TcpIp_DefaultAddrV6
  SizeOfDhcpUserOption                         the number of accomplishable value elements in TcpIp_DhcpUserOption
  SizeOfDhcpUserOptionBuffer                   the number of accomplishable value elements in TcpIp_DhcpUserOptionBuffer
  SizeOfIpV6MulticastAddr                      the number of accomplishable value elements in TcpIp_IpV6MulticastAddr
  SizeOfIpV6MulticastAddrActive                the number of accomplishable value elements in TcpIp_IpV6MulticastAddrActive
  SizeOfPhysAddrConfig                         the number of accomplishable value elements in TcpIp_PhysAddrConfig
  SizeOfPskIdentity                            the number of accomplishable value elements in TcpIp_PskIdentity
  SizeOfPskIdentityHint                        the number of accomplishable value elements in TcpIp_PskIdentityHint
  SizeOfStaticDefaultRouter                    the number of accomplishable value elements in TcpIp_StaticDefaultRouter
  SizeOfTcpOooQElement                         the number of accomplishable value elements in TcpIp_TcpOooQElement
  SizeOfTls13PskIdentity                       the number of accomplishable value elements in TcpIp_Tls13PskIdentity
  SizeOfTls13PskIdentityBuffer                 the number of accomplishable value elements in TcpIp_Tls13PskIdentityBuffer
  SizeOfTls13PskIdentityInd                    the number of accomplishable value elements in TcpIp_Tls13PskIdentityInd
  SizeOfTls13PskNonceBuffer                    the number of accomplishable value elements in TcpIp_Tls13PskNonceBuffer
  SizeOfTlsCertId                              the number of accomplishable value elements in TcpIp_TlsCertId
  SizeOfTlsCertValidationStatusDyn             the number of accomplishable value elements in TcpIp_TlsCertValidationStatusDyn
  SizeOfTlsCipherWorkerInd                     the number of accomplishable value elements in TcpIp_TlsCipherWorkerInd
  SizeOfTlsCipherWorkingSetMgmt                the number of accomplishable value elements in TcpIp_TlsCipherWorkingSetMgmt
  SizeOfTlsClientAuthenticationMgmt            the number of accomplishable value elements in TcpIp_TlsClientAuthenticationMgmt
  SizeOfTlsConnection                          the number of accomplishable value elements in TcpIp_TlsConnection
  SizeOfTlsCsmJob                              the number of accomplishable value elements in TcpIp_TlsCsmJob
  SizeOfTlsKeyMCertificate                     the number of accomplishable value elements in TcpIp_TlsKeyMCertificate
  SizeOfTlsLocalKeyMCertInfo                   the number of accomplishable value elements in TcpIp_TlsLocalKeyMCertInfo
  SizeOfTlsPskIdentity                         the number of accomplishable value elements in TcpIp_TlsPskIdentity
  SizeOfTlsPskIdentityInd                      the number of accomplishable value elements in TcpIp_TlsPskIdentityInd
  SizeOfTlsRemoteKeyMCertInfo                  the number of accomplishable value elements in TcpIp_TlsRemoteKeyMCertInfo
  SizeOfTlsResumedConnection                   the number of accomplishable value elements in TcpIp_TlsResumedConnection
  SizeOfTlsServerNameIndication                the number of accomplishable value elements in TcpIp_TlsServerNameIndication
  SizeOfTlsSigAlgServerCertReqMsgBuffer        the number of accomplishable value elements in TcpIp_TlsSigAlgServerCertReqMsgBuffer
  SizeOfTlsTemporaryClientAuthEdCurveBuffer    the number of accomplishable value elements in TcpIp_TlsTemporaryClientAuthEdCurveBuffer
  SizeOfTlsUserErrorBuffer                     the number of accomplishable value elements in TcpIp_TlsUserErrorBuffer
  SizeOfTxReqElem                              the number of accomplishable value elements in TcpIp_TxReqElem
  SizeOfTxReqElemList                          the number of accomplishable value elements in TcpIp_TxReqElemList
  SizeOfUdpTxRetryQueueElementChain            the number of accomplishable value elements in TcpIp_UdpTxRetryQueueElementChain
  SizeOfUdpTxRetryQueueElements                the number of accomplishable value elements in TcpIp_UdpTxRetryQueueElements
  SizeOfUdpTxRetryQueuePoolDesc                the number of accomplishable value elements in TcpIp_UdpTxRetryQueuePoolDesc
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_PCConfigsType, TCPIP_CONST) TcpIp_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config] */
      NULL_PTR                                   /**< the pointer to TcpIp_DefaultAddrV6 */
    , NULL_PTR                                   /**< the pointer to TcpIp_DhcpUserOption */
    , NULL_PTR                                   /**< the pointer to TcpIp_DhcpUserOptionBuffer */
    , NULL_PTR                                   /**< the pointer to TcpIp_DhcpUserOptionDyn */
    , NULL_PTR                                   /**< the pointer to TcpIp_IpV6MulticastAddr */
    , NULL_PTR                                   /**< the pointer to TcpIp_IpV6MulticastAddrActive */
    , NULL_PTR                                   /**< the pointer to TcpIp_PhysAddrConfig */
    , NULL_PTR                                   /**< the pointer to TcpIp_PskIdentity */
    , NULL_PTR                                   /**< the pointer to TcpIp_PskIdentityHint */
    , NULL_PTR                                   /**< the pointer to TcpIp_StaticDefaultRouter */
    , TcpIp_TcpOooQElement                       /**< the pointer to TcpIp_TcpOooQElement */
    , NULL_PTR                                   /**< the pointer to TcpIp_Tls13PskIdentity */
    , NULL_PTR                                   /**< the pointer to TcpIp_Tls13PskIdentityBuffer */
    , NULL_PTR                                   /**< the pointer to TcpIp_Tls13PskIdentityDyn */
    , NULL_PTR                                   /**< the pointer to TcpIp_Tls13PskIdentityInd */
    , NULL_PTR                                   /**< the pointer to TcpIp_Tls13PskNonceBuffer */
    , TcpIp_TlsCertId                            /**< the pointer to TcpIp_TlsCertId */
    , TcpIp_TlsCertValidationStatusDyn.raw       /**< the pointer to TcpIp_TlsCertValidationStatusDyn */
    , TcpIp_TlsCipherWorkerInd                   /**< the pointer to TcpIp_TlsCipherWorkerInd */
    , TcpIp_TlsCipherWorkingSetMgmt.raw          /**< the pointer to TcpIp_TlsCipherWorkingSetMgmt */
    , TcpIp_TlsClientAuthenticationMgmt.raw      /**< the pointer to TcpIp_TlsClientAuthenticationMgmt */
    , TcpIp_TlsConnection                        /**< the pointer to TcpIp_TlsConnection */
    , TcpIp_TlsCsmJob                            /**< the pointer to TcpIp_TlsCsmJob */
    , TcpIp_TlsKeyMCertificate                   /**< the pointer to TcpIp_TlsKeyMCertificate */
    , TcpIp_TlsLocalKeyMCertInfo                 /**< the pointer to TcpIp_TlsLocalKeyMCertInfo */
    , NULL_PTR                                   /**< the pointer to TcpIp_TlsPskIdentity */
    , NULL_PTR                                   /**< the pointer to TcpIp_TlsPskIdentityInd */
    , TcpIp_TlsRemoteKeyMCertInfo                /**< the pointer to TcpIp_TlsRemoteKeyMCertInfo */
    , NULL_PTR                                   /**< the pointer to TcpIp_TlsResumedConnection */
    , NULL_PTR                                   /**< the pointer to TcpIp_TlsServerNameIndication */
    , TcpIp_TlsSigAlgServerCertReqMsgBuffer.raw  /**< the pointer to TcpIp_TlsSigAlgServerCertReqMsgBuffer */
    , NULL_PTR                                   /**< the pointer to TcpIp_TlsTemporaryClientAuthEdCurveBuffer */
    , TcpIp_TlsUserErrorBuffer.raw               /**< the pointer to TcpIp_TlsUserErrorBuffer */
    , TcpIp_TxReqElem.raw                        /**< the pointer to TcpIp_TxReqElem */
    , TcpIp_TxReqElemList                        /**< the pointer to TcpIp_TxReqElemList */
    , TcpIp_TxReqElemListDyn                     /**< the pointer to TcpIp_TxReqElemListDyn */
    , TcpIp_UdpTxRetryQueueElementChain          /**< the pointer to TcpIp_UdpTxRetryQueueElementChain */
    , TcpIp_UdpTxRetryQueueElements              /**< the pointer to TcpIp_UdpTxRetryQueueElements */
    , TcpIp_UdpTxRetryQueuePoolDesc              /**< the pointer to TcpIp_UdpTxRetryQueuePoolDesc */
    , 0u                                         /**< the number of elements in TcpIp_DefaultAddrV6 */
    , 0u                                         /**< the number of elements in TcpIp_DhcpUserOption */
    , 0u                                         /**< the number of elements in TcpIp_DhcpUserOptionBuffer */
    , 0u                                         /**< the number of elements in TcpIp_IpV6MulticastAddr */
    , 0u                                         /**< the number of elements in TcpIp_IpV6MulticastAddrActive */
    , 0u                                         /**< the number of elements in TcpIp_PhysAddrConfig */
    , 0u                                         /**< the number of elements in TcpIp_PskIdentity */
    , 0u                                         /**< the number of elements in TcpIp_PskIdentityHint */
    , 0u                                         /**< the number of elements in TcpIp_StaticDefaultRouter */
    , 15u                                        /**< the number of elements in TcpIp_TcpOooQElement */
    , 0u                                         /**< the number of elements in TcpIp_Tls13PskIdentity */
    , 0u                                         /**< the number of elements in TcpIp_Tls13PskIdentityBuffer */
    , 0u                                         /**< the number of elements in TcpIp_Tls13PskIdentityInd */
    , 0u                                         /**< the number of elements in TcpIp_Tls13PskNonceBuffer */
    , 13u                                        /**< the number of elements in TcpIp_TlsCertId */
    , 6u                                         /**< the number of elements in TcpIp_TlsCertValidationStatusDyn */
    , 2u                                         /**< the number of elements in TcpIp_TlsCipherWorkerInd */
    , 1u                                         /**< the number of elements in TcpIp_TlsCipherWorkingSetMgmt */
    , 1u                                         /**< the number of elements in TcpIp_TlsClientAuthenticationMgmt */
    , 1u                                         /**< the number of elements in TcpIp_TlsConnection */
    , 90u                                        /**< the number of elements in TcpIp_TlsCsmJob */
    , 40u                                        /**< the number of elements in TcpIp_TlsKeyMCertificate */
    , 1u                                         /**< the number of elements in TcpIp_TlsLocalKeyMCertInfo */
    , 0u                                         /**< the number of elements in TcpIp_TlsPskIdentity */
    , 0u                                         /**< the number of elements in TcpIp_TlsPskIdentityInd */
    , 1u                                         /**< the number of elements in TcpIp_TlsRemoteKeyMCertInfo */
    , 0u                                         /**< the number of elements in TcpIp_TlsResumedConnection */
    , 0u                                         /**< the number of elements in TcpIp_TlsServerNameIndication */
    , 10u                                        /**< the number of elements in TcpIp_TlsSigAlgServerCertReqMsgBuffer */
    , 0u                                         /**< the number of elements in TcpIp_TlsTemporaryClientAuthEdCurveBuffer */
    , 10u                                        /**< the number of elements in TcpIp_TlsUserErrorBuffer */
    , 1u                                         /**< the number of elements in TcpIp_TxReqElem */
    , 1u                                         /**< the number of elements in TcpIp_TxReqElemList */
    , 1u                                         /**< the number of elements in TcpIp_UdpTxRetryQueueElementChain */
    , 1u                                         /**< the number of elements in TcpIp_UdpTxRetryQueueElements */
    , 1u                                         /**< the number of elements in TcpIp_UdpTxRetryQueuePoolDesc */
  }
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/* PRQA L:OBJECT_SIZE */

#define TCPIP_START_SEC_CODE
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_MainFunction(void)
{
  TcpIp_MultiPartitionMainFunction(TCPIP_SINGLECORE_APPLID);
}



/**********************************************************************************************************************
 *  USER FUNCTIONS
 *********************************************************************************************************************/
/* TcpIp_<Up>GetSocket ----------------------------------------------------- */
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_SccGetSocket(
    TcpIp_DomainType                                      Domain,
    TcpIp_ProtocolType                                    Protocol,
    P2VAR(TcpIp_SocketIdType, AUTOMATIC, TCPIP_APPL_DATA) SocketIdPtr)
{
    return TcpIp_GetSocketForUser(Domain, Protocol, SocketIdPtr, TcpIpConf_TcpIpSocketOwner_Scc);  /* SBSW_TCPIP_NonNullPtrParameter */
}
 

#define TCPIP_STOP_SEC_CODE
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA L:MACRO_LIMIT */

/* Justification for module-specific MISRA deviations:

  MD_TEST_Rule5.5_Wrapper: Identifier '%s' is also used as a macro name.
    Reason:     Redefinition allows execution of foreign code.
    Risk:       Code is more difficult to read and to debug.
    Prevention: Code is only present in test environment and not in productive builds.
  
  MD_CSL_Rule10.3_OldValidLib: The value of an expression shall not be assigned to an object with a narrower essential
                               type or of a different essential type category.
    Reason:     Other Autosar modules generates narrow datatypes for the symbolic name values.
    Risk:       None.
    Prevention: Other modules need to change their SNV generation
  
  MD_TCPIP_CERT-DCL40-C_0789: Identifier matches other identifier(s) (e.g. '%s') in first 63 characters.
    Reason:     The rule 0789 checks if all internal identifiers are different within the first 63 characters.
    Risk:       A compiler might not correctly pre-process the software what might result in incorrect code.
    Prevention: Each delivery is integrated and tested on the real target system. In addition, preprocessors and
                compilers used in current MICROSAR projects are not expected to suffer from this (historic) limitation. 
                Compiler selection and validation is done by ECU supplier. 
  
  MD_TCPIP_CERT-ARR30-C_2842: Apparent: Dereference of an invalid pointer value.
    Reason:     A function parameter is used to access an array element. The parameter is passed by an internal TcpIp 
                function that ensures that the parameter is in a valid range. This is ensured by SafeBSW measures.
                The parameter cannot be written by other BSW module or the application.
    Risk:       None.
    Prevention: Covered by code review.
      
*/
/**********************************************************************************************************************
 *  END OF FILE: TcpIp_Lcfg.c
 *********************************************************************************************************************/
