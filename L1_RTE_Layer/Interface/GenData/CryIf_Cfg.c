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
 *            Module: CryIf
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CryIf_Cfg.c
 *   Generation Time: 2025-09-11 13:39:30
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#define CRYIF_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "CryIf_Cfg.h"
#include "CryIf.h"
#include "CryIf_Private.h"
#include "Crypto_30_LibCv.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (CRYIF_LOCAL)
# define CRYIF_LOCAL static
#endif

#if !defined (CRYIF_LOCAL_INLINE)
# define CRYIF_LOCAL_INLINE LOCAL_INLINE
#endif




/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/






/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CryIf_Channel
**********************************************************************************************************************/
/** 
  \var    CryIf_Channel
  \brief  Contains parameters of /MICROSAR/CryIf/CryIfChannel.
  \details
  Element               Description
  DriverObjectRef       Contains values of DefinitionRef: /MICROSAR/CryIf/CryIfChannel/CryIfDriverObjectRef.
  CryptoFunctionsIdx    the index of the 1:1 relation pointing to CryIf_CryptoFunctions
  Id                    Contains values of DefinitionRef: /MICROSAR/CryIf/CryIfChannel/CryIfChannelId.
*/ 
#define CRYIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CryIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CryIf_ChannelType, CRYIF_CONST) CryIf_Channel[9] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DriverObjectRef                                                                    CryptoFunctionsIdx  Id        Referable Keys */
  { /*     0 */ CryptoConf_CryptoDriverObject_Crypto_30_LibCv                                    ,                 0u, 0u },  /* [/ActiveEcuC/CryIf/CryIfChannel, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueueECDSAVerify:CsmChannelRef] */
  { /*     1 */ CryptoConf_CryptoDriverObject_Crypto_30_LibCv_General                            ,                 0u, 1u },  /* [/ActiveEcuC/CryIf/CryIfChannel_Crypto_Lib_SCC, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue:CsmChannelRef, /ActiveEcuC/Csm/CsmQueues/CsmQueue_Hkdf_Sha256:CsmChannelRef, /ActiveEcuC/Csm/CsmQueues/CsmQueue_SCC_1_LibCv:CsmChannelRef, /ActiveEcuC/Csm/CsmQueues/Scc_KeyM_Queue:CsmChannelRef] */
  { /*     2 */ CryptoConf_CryptoDriverObject_CryptoDriverObject_Tls_Conn0                       ,                 0u, 2u },  /* [/ActiveEcuC/CryIf/CryIfChannel_Tls_Conn0, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Conn0:CsmChannelRef] */
  { /*     3 */ CryptoConf_CryptoDriverObject_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished,                 0u, 3u },  /* [/ActiveEcuC/CryIf/CryIfChannel_Tls_Conn0_HS_HashSha256_Finished, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Conn0_HS_HashSha256_Finished:CsmChannelRef] */
  { /*     4 */ CryptoConf_CryptoDriverObject_CryptoDriverObject_Tls_Conn1                       ,                 0u, 4u },  /* [/ActiveEcuC/CryIf/CryIfChannel_Tls_Conn1, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Conn1:CsmChannelRef] */
  { /*     5 */ CryptoConf_CryptoDriverObject_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished,                 0u, 5u },  /* [/ActiveEcuC/CryIf/CryIfChannel_Tls_Conn1_HS_HashSha256_Finished, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Conn1_HS_HashSha256_Finished:CsmChannelRef] */
  { /*     6 */ CryptoConf_CryptoDriverObject_CryptoDriverObject_Tls_Conn1_HS_HashSha384         ,                 0u, 6u },  /* [/ActiveEcuC/CryIf/CryIfChannel_Tls_Conn1_HS_HashSha384, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Conn1_HS_HashSha384:CsmChannelRef] */
  { /*     7 */ CryptoConf_CryptoDriverObject_CryptoDriverObject_Tls_Global_HashSha1             ,                 0u, 7u },  /* [/ActiveEcuC/CryIf/CryIfChannel_Tls_Global_HashSha1, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Global_HashSha1:CsmChannelRef] */
  { /*     8 */ CryptoConf_CryptoDriverObject_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384           ,                 0u, 8u }   /* [/ActiveEcuC/CryIf/CryIfChannel_Tls_Hkdf_Sha384, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_Hkdf_Sha384:CsmChannelRef] */
};
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CryIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CryIf_CryptoFunctions
**********************************************************************************************************************/
/** 
  \var    CryIf_CryptoFunctions
  \details
  Element                          Description
  SupportsKeyElementCopyPartial
  CancelJob                    
  CertificateParse             
  CertificateVerify            
  KeyCopy                      
  KeyDerive                    
  KeyElementCopy               
  KeyElementCopyPartial        
  KeyElementGet                
  KeyElementIdsGet             
  KeyElementSet                
  KeyExchangeCalcPubVal        
  KeyExchangeCalcSecret        
  KeyGenerate                  
  KeyGetStatus                 
  KeySetInvalid                
  KeyValidSet                  
  ProcessJob                   
  RandomSeed                   
*/ 
#define CRYIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CryIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CryIf_CryptoFunctionsType, CRYIF_CONST) CryIf_CryptoFunctions[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    SupportsKeyElementCopyPartial  CancelJob                  CertificateParse                  CertificateVerify                  KeyCopy                  KeyDerive                  KeyElementCopy                  KeyElementCopyPartial                  KeyElementGet                  KeyElementIdsGet                  KeyElementSet                  KeyExchangeCalcPubVal                  KeyExchangeCalcSecret                  KeyGenerate                  KeyGetStatus             KeySetInvalid             KeyValidSet                  ProcessJob                  RandomSeed                        Referable Keys */
  { /*     0 */                          TRUE, Crypto_30_LibCv_CancelJob, Crypto_30_LibCv_CertificateParse, Crypto_30_LibCv_CertificateVerify, Crypto_30_LibCv_KeyCopy, Crypto_30_LibCv_KeyDerive, Crypto_30_LibCv_KeyElementCopy, Crypto_30_LibCv_KeyElementCopyPartial, Crypto_30_LibCv_KeyElementGet, Crypto_30_LibCv_KeyElementIdsGet, Crypto_30_LibCv_KeyElementSet, Crypto_30_LibCv_KeyExchangeCalcPubVal, Crypto_30_LibCv_KeyExchangeCalcSecret, Crypto_30_LibCv_KeyGenerate, CryIf_KeyGetStatus_Stub, CryIf_KeySetInvalid_Stub, Crypto_30_LibCv_KeyValidSet, Crypto_30_LibCv_ProcessJob, Crypto_30_LibCv_RandomSeed }   /* [/ActiveEcuC/Crypto] */
};
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CryIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CryIf_Key
**********************************************************************************************************************/
/** 
  \var    CryIf_Key
  \brief  Contains parameters of /MICROSAR/CryIf/CryIfKey.
  \details
  Element               Description
  Ref                   Contains values of DefinitionRef: /MICROSAR/CryIf/CryIfKey/CryIfKeyRef.
  CryptoFunctionsIdx    the index of the 1:1 relation pointing to CryIf_CryptoFunctions
*/ 
#define CRYIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CryIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CryIf_KeyType, CRYIF_CONST) CryIf_Key[119] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Ref                                                                              CryptoFunctionsIdx        Referable Keys */
  { /*     0 */ CryptoConf_CryptoKey_CryptoKey_DefaultRandomSource                             ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_DefaultRandomSource, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_DefaultRandomSource:CsmKeyRef] */
  { /*     1 */ CryptoConf_CryptoKey_CryptoKey_Hkdf_Sha256                                     ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Hkdf_Sha256, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Hkdf_Sha256:CsmKeyRef] */
  { /*     2 */ CryptoConf_CryptoKey_CryptoKey_Hkdf_Sha384                                     ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Hkdf_Sha384, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Hkdf_Sha384:CsmKeyRef] */
  { /*     3 */ CryptoConf_CryptoKey_CryptoKey_HmacSha256Generate_1                            ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_HmacSha256Generate_1, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_HmacSha256Generate_1:CsmKeyRef] */
  { /*     4 */ CryptoConf_CryptoKey_CryptoKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey         ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey:CsmKeyRef] */
  { /*     5 */ CryptoConf_CryptoKey_CryptoKey_Leaf_Server_A_EccSecp521r1Sha512_PubKey         ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Leaf_Server_A_EccSecp521r1Sha512_PubKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Leaf_Server_A_EccSecp521r1Sha512_PubKey:CsmKeyRef] */
  { /*     6 */ CryptoConf_CryptoKey_CryptoKey_RandomGenerator                                 ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_RandomGenerator, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_RandomGenerator:CsmKeyRef] */
  { /*     7 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey:CsmKeyRef] */
  { /*     8 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey             ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey:CsmKeyRef] */
  { /*     9 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey             ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey:CsmKeyRef] */
  { /*    10 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey:CsmKeyRef] */
  { /*    11 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey             ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey:CsmKeyRef] */
  { /*    12 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey             ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey:CsmKeyRef] */
  { /*    13 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey           ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey:CsmKeyRef] */
  { /*    14 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey            ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey:CsmKeyRef] */
  { /*    15 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PrivateKey           ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PrivateKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PrivateKey:CsmKeyRef] */
  { /*    16 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey            ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey:CsmKeyRef] */
  { /*    17 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey          ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey:CsmKeyRef] */
  { /*    18 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey          ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey:CsmKeyRef] */
  { /*    19 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey          ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey:CsmKeyRef] */
  { /*    20 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey        ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey:CsmKeyRef] */
  { /*    21 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey         ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey:CsmKeyRef] */
  { /*    22 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PrivateKey        ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PrivateKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PrivateKey:CsmKeyRef] */
  { /*    23 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey         ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey:CsmKeyRef] */
  { /*    24 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey       ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey:CsmKeyRef] */
  { /*    25 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey       ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey:CsmKeyRef] */
  { /*    26 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey       ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey:CsmKeyRef] */
  { /*    27 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_V2GRoot_X_PublicKey                   ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_V2GRoot_X_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_V2GRoot_X_PublicKey:CsmKeyRef] */
  { /*    28 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_V2GRoot_Y_PublicKey                   ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_V2GRoot_Y_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_V2GRoot_Y_PublicKey:CsmKeyRef] */
  { /*    29 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey        ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey:CsmKeyRef] */
  { /*    30 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey         ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey:CsmKeyRef] */
  { /*    31 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey       ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey:CsmKeyRef] */
  { /*    32 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey       ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey:CsmKeyRef] */
  { /*    33 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey:CsmKeyRef] */
  { /*    34 */ CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey   ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey:CsmKeyRef] */
  { /*    35 */ CryptoConf_CryptoKey_CryptoKey_Scc_KDF                                         ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_KDF, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_KDF:CsmKeyRef] */
  { /*    36 */ CryptoConf_CryptoKey_CryptoKey_Scc_KDF_1                                       ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_KDF_1, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_KDF_1:CsmKeyRef] */
  { /*    37 */ CryptoConf_CryptoKey_CryptoKey_Scc_MOContract_X_PrivateKey                     ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_MOContract_X_PrivateKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Csm_Scc_MOContract_X_PrivateKey:CsmKeyRef] */
  { /*    38 */ CryptoConf_CryptoKey_CryptoKey_Scc_MOContract_X_PublicKey                      ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_MOContract_X_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Csm_Scc_MOContract_X_PublicKey:CsmKeyRef] */
  { /*    39 */ CryptoConf_CryptoKey_CryptoKey_Scc_MORoot_X_PublicKey                          ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_MORoot_X_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_MORoot_X_PublicKey:CsmKeyRef] */
  { /*    40 */ CryptoConf_CryptoKey_CryptoKey_Scc_MOSubCa1_X_PublicKey                        ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_MOSubCa1_X_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Csm_Scc_MOSubCa1_X_PublicKey:CsmKeyRef] */
  { /*    41 */ CryptoConf_CryptoKey_CryptoKey_Scc_MOSubCa2_X_PublicKey                        ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_MOSubCa2_X_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Csm_Scc_MOSubCa2_X_PublicKey:CsmKeyRef] */
  { /*    42 */ CryptoConf_CryptoKey_CryptoKey_Scc_OEMProvRoot                                 ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_OEMProvRoot, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Csm_Scc_OEMProvRoot_PublicKey:CsmKeyRef] */
  { /*    43 */ CryptoConf_CryptoKey_CryptoKey_Scc_OEMProvSubCa1                               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_OEMProvSubCa1, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Csm_Scc_OEMProvSubCa1_PublicKey:CsmKeyRef] */
  { /*    44 */ CryptoConf_CryptoKey_CryptoKey_Scc_OEMProvSubCa2                               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_OEMProvSubCa2, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Csm_Scc_OEMProvSubCa2_PublicKEy:CsmKeyRef] */
  { /*    45 */ CryptoConf_CryptoKey_CryptoKey_Scc_OEMProv_X_PrivateKey                        ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_OEMProv_X_PrivateKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Csm_Scc_OEMProv_X_PrivateKey:CsmKeyRef] */
  { /*    46 */ CryptoConf_CryptoKey_CryptoKey_Scc_OEMProv_X_PublicKey                         ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_OEMProv_X_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Csm_Scc_OEMProv_X_PublicKey:CsmKeyRef] */
  { /*    47 */ CryptoConf_CryptoKey_CryptoKey_Scc_ProvLeaf_X_PublicKey                        ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ProvLeaf_X_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Csm_Scc_ProvLeaf_X_PublicKey:CsmKeyRef] */
  { /*    48 */ CryptoConf_CryptoKey_CryptoKey_Scc_ProvSubCa1_X_PublicKey                      ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ProvSubCa1_X_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Csm_Scc_ProvSubCa1_X_PublicKey:CsmKeyRef] */
  { /*    49 */ CryptoConf_CryptoKey_CryptoKey_Scc_ProvSubCa2_X_PublicKey                      ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_ProvSubCa2_X_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Csm_Scc_ProvSubCa2_X_PublicKey:CsmKeyRef] */
    /* Index    Ref                                                                              CryptoFunctionsIdx        Referable Keys */
  { /*    50 */ CryptoConf_CryptoKey_CryptoKey_Scc_SHA512                                      ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_SHA512, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_SHA512:CsmKeyRef] */
  { /*    51 */ CryptoConf_CryptoKey_CryptoKey_Scc_V2GRoot_X_PublicKey                         ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_V2GRoot_X_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Csm_Scc_V2GRoot_X_PublicKey:CsmKeyRef] */
  { /*    52 */ CryptoConf_CryptoKey_CryptoKey_Scc_V2GRoot_Y_PublicKey                         ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Scc_V2GRoot_Y_PublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_V2GRoot_Y_PublicKey:CsmKeyRef] */
  { /*    53 */ CryptoConf_CryptoKey_CryptoKey_TlsConn0_HS_DhKeyExchange                       ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_TlsConn0_HS_DhKeyExchange, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_TlsConn0_HS_DhKeyExchange:CsmKeyRef] */
  { /*    54 */ CryptoConf_CryptoKey_CryptoKey_TlsConn0_HS_DhSignatureGenerate                 ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_TlsConn0_HS_DhSignatureGenerate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_TlsConn0_HS_DhSignatureGenerate:CsmKeyRef] */
  { /*    55 */ CryptoConf_CryptoKey_CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1             ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_TlsConn1_HS_DhKeyExchange_Secp521r1, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_TlsConn1_HS_DhKeyExchange_Secp521r1:CsmKeyRef] */
  { /*    56 */ CryptoConf_CryptoKey_CryptoKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1       ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1:CsmKeyRef] */
  { /*    57 */ CryptoConf_CryptoKey_CryptoKey_Tls_ChaCha20_Decrypt                            ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_ChaCha20_Decrypt, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_ChaCha20_Decrypt:CsmKeyRef] */
  { /*    58 */ CryptoConf_CryptoKey_CryptoKey_Tls_ChaCha20_Encrypt                            ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_ChaCha20_Encrypt, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_ChaCha20_Encrypt:CsmKeyRef] */
  { /*    59 */ CryptoConf_CryptoKey_CryptoKey_Tls_ChaCha20_PassiveDecrypt                     ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_ChaCha20_PassiveDecrypt, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_ChaCha20_PassiveDecrypt:CsmKeyRef] */
  { /*    60 */ CryptoConf_CryptoKey_CryptoKey_Tls_ChaCha20_PassiveEncrypt                     ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_ChaCha20_PassiveEncrypt, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_ChaCha20_PassiveEncrypt:CsmKeyRef] */
  { /*    61 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt                     ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn0_Aes128Cbc_Decrypt, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_Aes128Cbc_Decrypt:CsmKeyRef] */
  { /*    62 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt                     ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn0_Aes128Cbc_Encrypt, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_Aes128Cbc_Encrypt:CsmKeyRef] */
  { /*    63 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_CertVerify_PubKey                     ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn0_CertVerify_PubKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_CertVerify_PubKey:CsmKeyRef, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_CertVerify_Server_Leaf_PubKey:CsmKeyRef] */
  { /*    64 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_HMacShaX_Generate                     ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn0_HMacShaX_Generate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_HMacShaX_Generate:CsmKeyRef] */
  { /*    65 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_HMacShaX_Verify                       ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn0_HMacShaX_Verify, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_HMacShaX_Verify:CsmKeyRef] */
  { /*    66 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_HS_DhKeyExchange                      ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn0_HS_DhKeyExchange, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_HS_DhKeyExchange:CsmKeyRef] */
  { /*    67 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_HS_HashSha256_Finished                ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn0_HS_HashSha256_Finished, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_HashSha256_Finished:CsmKeyRef] */
  { /*    68 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_HS_HashSha256_ToClientFinished        ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn0_HS_HashSha256_ToClientFinished, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_HS_HashSha256_ToClientFinished:CsmKeyRef] */
  { /*    69 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_HS_HashSha256_ToServerFinished        ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn0_HS_HashSha256_ToServerFinished, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_HS_HashSha256_ToServerFinished:CsmKeyRef] */
  { /*    70 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_HS_RandomNumber                       ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn0_HS_RandomNumber, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_HS_RandomNumber:CsmKeyRef] */
  { /*    71 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_MasterSecret                          ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn0_MasterSecret, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_MasterSecret:CsmKeyRef] */
  { /*    72 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_PreMasterSecretInfo                   ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn0_PreMasterSecretInfo, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_PreMasterSecretInfo:CsmKeyRef] */
  { /*    73 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate           ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn0_PrfCalculationValuesPrivate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_PrfCalculationValuesPrivate:CsmKeyRef] */
  { /*    74 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_PrfCalculationValuesPublic            ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn0_PrfCalculationValuesPublic, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_PrfCalculationValuesPublic:CsmKeyRef] */
  { /*    75 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_Prf_ResultPrivate                     ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn0_Prf_ResultPrivate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_Prf_ResultPrivate:CsmKeyRef] */
  { /*    76 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_Prf_ResultPublic                      ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn0_Prf_ResultPublic, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_Prf_ResultPublic:CsmKeyRef] */
  { /*    77 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_Prf_Secret                            ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn0_Prf_Secret, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_Prf_Secret:CsmKeyRef, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_Prf_Secret_32:CsmKeyRef, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_Prf_Secret_48:CsmKeyRef] */
  { /*    78 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_TmpBuffer                             ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn0_TmpBuffer, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_TmpBuffer:CsmKeyRef] */
  { /*    79 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_Aes256GcmDecrypt                      ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn1_Aes256GcmDecrypt, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_Aes256GcmDecrypt_1:CsmKeyRef] */
  { /*    80 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_Aes256GcmEncrypt                      ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn1_Aes256GcmEncrypt, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_Aes256GcmEncrypt_1:CsmKeyRef] */
  { /*    81 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn1_Aes256GcmPassiveDecrypt, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_Aes256GcmPassiveDecrypt:CsmKeyRef] */
  { /*    82 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn1_Aes256GcmPassiveEncrypt, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_Aes256GcmPassiveEncrypt:CsmKeyRef] */
  { /*    83 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_HS_HashSha256_Finished                ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn1_HS_HashSha256_Finished, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_HS_HashSha256_Finished:CsmKeyRef] */
  { /*    84 */ CryptoConf_CryptoKey_Tls_Conn1_HS_HashSha384_Finished                          ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn1_HS_HashSha384_Finished, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_HS_HashSha384_Finished:CsmKeyRef] */
  { /*    85 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_MasterSecret                          ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn1_MasterSecret, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_MasterSecret:CsmKeyRef] */
  { /*    86 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate           ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn1_PrfCalculationValuesPrivate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_PrfCalculationValuesPrivate:CsmKeyRef] */
  { /*    87 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_PrfCalculationValuesPublic            ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn1_PrfCalculationValuesPublic, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_PrfCalculationValuesPublic:CsmKeyRef] */
  { /*    88 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_Prf_ResultPrivate                     ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn1_Prf_ResultPrivate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_Prf_ResultPrivate:CsmKeyRef] */
  { /*    89 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_Prf_ResultPublic                      ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn1_Prf_ResultPublic, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_Prf_ResultPublic:CsmKeyRef] */
  { /*    90 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_Prf_Secret_Secp521                    ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn1_Prf_Secret_Secp521, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_Prf_Secret:CsmKeyRef] */
  { /*    91 */ CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_TmpBuffer                             ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Conn1_TmpBuffer, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_TmpBuffer:CsmKeyRef] */
  { /*    92 */ CryptoConf_CryptoKey_CryptoKey_Tls_Global_HashSha1                             ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Global_HashSha1, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Global_HashSha1:CsmKeyRef] */
  { /*    93 */ CryptoConf_CryptoKey_CryptoKey_Tls_HMacSha384Generate                          ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_HMacSha384Generate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_HMacSha384Generate_1:CsmKeyRef] */
  { /*    94 */ CryptoConf_CryptoKey_CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret                ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Hkdf_ClientAdHsTrafficSecret, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_ClientAdHsTrafficSecret:CsmKeyRef] */
  { /*    95 */ CryptoConf_CryptoKey_CryptoKey_Tls_Hkdf_DerivedSecret                          ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Hkdf_DerivedSecret, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_DerivedSecret:CsmKeyRef] */
  { /*    96 */ CryptoConf_CryptoKey_CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret                ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Hkdf_ServerAdHsTrafficSecret, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_ServerAdHsTrafficSecret:CsmKeyRef] */
  { /*    97 */ CryptoConf_CryptoKey_CryptoKey_Tls_Hkdf_Sha256ExpandIn                         ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Hkdf_Sha256ExpandIn, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_Sha256ExpandIn:CsmKeyRef] */
  { /*    98 */ CryptoConf_CryptoKey_CryptoKey_Tls_Hkdf_Sha256ExpandOut                        ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Hkdf_Sha256ExpandOut, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_Sha256ExpandOut:CsmKeyRef] */
  { /*    99 */ CryptoConf_CryptoKey_CryptoKey_Tls_Hkdf_Sha384ExpandIn                         ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Hkdf_Sha384ExpandIn, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_Sha384ExpandIn:CsmKeyRef] */
    /* Index    Ref                                                                              CryptoFunctionsIdx        Referable Keys */
  { /*   100 */ CryptoConf_CryptoKey_CryptoKey_Tls_Hkdf_Sha384ExpandOut                        ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Hkdf_Sha384ExpandOut, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_Sha384ExpandOut:CsmKeyRef] */
  { /*   101 */ CryptoConf_CryptoKey_CryptoKey_Tls_Hkdf_TmpBuffer                              ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Hkdf_TmpBuffer, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_TmpBuffer:CsmKeyRef] */
  { /*   102 */ CryptoConf_CryptoKey_CryptoKey_Tls_RootA_EccSecp256r1Sha256_PubKey             ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_Root_A_EccSecp256r1Sha256_PubKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Root_A_EccSecp256r1Sha256_PubKey:CsmKeyRef] */
  { /*   103 */ CryptoConf_CryptoKey_CryptoKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey          ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey:CsmKeyRef] */
  { /*   104 */ CryptoConf_CryptoKey_CryptoKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey          ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey:CsmKeyRef] */
  { /*   105 */ CryptoConf_CryptoKey_CryptoKey_V2G_Root_1_PubKey                               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_V2G_Root_1_PubKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_V2G_Root_1_PubKey:CsmKeyRef] */
  { /*   106 */ CryptoConf_CryptoKey_CryptoKey_V2G_Root_2_PubKey                               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_V2G_Root_2_PubKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_V2G_Root_2_PubKey:CsmKeyRef] */
  { /*   107 */ CryptoConf_CryptoKey_CryptoKey_V2G_Root_3_PubKey                               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_V2G_Root_3_PubKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_V2G_Root_3_PubKey:CsmKeyRef] */
  { /*   108 */ CryptoConf_CryptoKey_CryptoKey_V2G_Root_4_PubKey                               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_V2G_Root_4_PubKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_V2G_Root_4_PubKey:CsmKeyRef] */
  { /*   109 */ CryptoConf_CryptoKey_CryptoKey_V2G_Root_5_PubKey                               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_V2G_Root_5_PubKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_V2G_Root_5_PubKey:CsmKeyRef] */
  { /*   110 */ CryptoConf_CryptoKey_CryptoKey_V2G_Root_6_PubKey                               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_V2G_Root_6_PubKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_V2G_Root_6_PubKey:CsmKeyRef] */
  { /*   111 */ CryptoConf_CryptoKey_CryptoKey_V2G_Root_7_PubKey                               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_V2G_Root_7_PubKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_V2G_Root_7_PubKey:CsmKeyRef] */
  { /*   112 */ CryptoConf_CryptoKey_CryptoKey_V2G_Root_8_PubKey                               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_V2G_Root_8_PubKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_V2G_Root_8_PubKey:CsmKeyRef] */
  { /*   113 */ CryptoConf_CryptoKey_CryptoKey_V2G_Root_9_PubKey                               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_V2G_Root_9_PubKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_V2G_Root_9_PubKey:CsmKeyRef] */
  { /*   114 */ CryptoConf_CryptoKey_CryptoKey_V2G_Root_10_PubKey                              ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_V2G_Root_10_PubKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_V2G_Root_10_PubKey:CsmKeyRef] */
  { /*   115 */ CryptoConf_CryptoKey_Crypto_SccContractPrivKey                                 ,                 0u },  /* [/ActiveEcuC/CryIf/CryIf_SccContractPrivKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_HS_DhSignatureGenerate:CsmKeyRef, /ActiveEcuC/Csm/CsmKeys/Csm_SccContractPrivKey:CsmKeyRef] */
  { /*   116 */ CryptoConf_CryptoKey_Crypto_SccPublicKey                                       ,                 0u },  /* [/ActiveEcuC/CryIf/CryIf_SccPublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Csm_SccPublicKey:CsmKeyRef] */
  { /*   117 */ CryptoConf_CryptoKey_CryptoKey_Scc_ResumeSessionInfo                           ,                 0u },  /* [/ActiveEcuC/CryIf/CryIf_Scc_ResumeSessionInfo, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Csm_Scc_ResumeSessionInfo:CsmKeyRef] */
  { /*   118 */ CryptoConf_CryptoKey_Crypto_TlsSha1Key                                         ,                 0u }   /* [/ActiveEcuC/CryIf/CryIf_TlsSha1Key, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Csm_TlsSha1Key:CsmKeyRef] */
};
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CryIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  END OF FILE: CryIf_Cfg.c
 *********************************************************************************************************************/
