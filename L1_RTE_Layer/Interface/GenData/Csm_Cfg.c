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
 *            Module: Csm
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Csm_Cfg.c
 *   Generation Time: 2025-09-11 13:39:30
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#define CSM_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Csm_Cfg.h"
#include "CryIf.h"
#include "SchM_Csm.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (CSM_LOCAL)
# define CSM_LOCAL static
#endif

#if !defined (CSM_LOCAL_INLINE)
# define CSM_LOCAL_INLINE LOCAL_INLINE
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
  Csm_BswCallbacks
**********************************************************************************************************************/
/** 
  \var    Csm_BswCallbacks
  \details
  Element           Description
  CallbackFunc43
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_BswCallbacksType, CSM_CONST) Csm_BswCallbacks[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CallbackFunc43                            Referable Keys */
  { /*     0 */ KeyM_CallbackNotificationSignature },  /* [/ActiveEcuC/Csm/CsmCallbacks/CsmCallback_KeyM_SigVerify] */
  { /*     1 */ Scc_Cbk_Csm_ApplNotification_Csm43 }   /* [/ActiveEcuC/Csm/CsmCallbacks/CsmCallback] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_InOutJobRedirectionTable
**********************************************************************************************************************/
/** 
  \var    Csm_InOutJobRedirectionTable
  \brief  Contains parameters of /MICROSAR/Csm/CsmInOutRedirections/CsmInOutRedirection.
  \details
  Element                        Description
  InputKeyId                 
  OutputKeyId                
  SecondaryInputKeyId        
  SecondaryOutputKeyId       
  TertiaryInputKeyId         
  OutputKeyElementId             Contains values of DefinitionRef: /MICROSAR/Csm/CsmInOutRedirections/CsmInOutRedirection/CsmOutputKeyElementId.
  SecondaryOutputKeyElementId    Contains values of DefinitionRef: /MICROSAR/Csm/CsmInOutRedirections/CsmInOutRedirection/CsmSecondaryOutputKeyElementId.
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_InOutJobRedirectionTableType, CSM_CONST) Csm_InOutJobRedirectionTable[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    InputKeyId                                                   OutputKeyId                                                  SecondaryInputKeyId  SecondaryOutputKeyId  TertiaryInputKeyId  OutputKeyElementId  SecondaryOutputKeyElementId        Referable Keys */
  { /*     0 */ CsmConf_CsmKey_CsmKey_Tls_Conn1_PrfCalculationValuesPrivate, CsmConf_CsmKey_CsmKey_Tls_Conn1_PrfCalculationValuesPrivate, CSM_INVALID_KEYID  , CSM_INVALID_KEYID   , CSM_INVALID_KEYID ,              3081u,                          0u },  /* [/ActiveEcuC/Csm/CsmInOutRedirections/CsmInOutRedirection_PrfPrivate_TlsConn1, /ActiveEcuC/Csm/CsmInOutRedirections, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Prf_HMacGenerate_Private:CsmInOutRedirectionRef] */
  { /*     1 */ CsmConf_CsmKey_CsmKey_Tls_Conn1_PrfCalculationValuesPublic , CsmConf_CsmKey_CsmKey_Tls_Conn1_PrfCalculationValuesPublic , CSM_INVALID_KEYID  , CSM_INVALID_KEYID   , CSM_INVALID_KEYID ,              3081u,                          0u },  /* [/ActiveEcuC/Csm/CsmInOutRedirections/CsmInOutRedirection_PrfPublic_TlsConn1, /ActiveEcuC/Csm/CsmInOutRedirections, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Prf_HMacGenerate_Public:CsmInOutRedirectionRef] */
  { /*     2 */ CsmConf_CsmKey_CsmKey_Tls_Conn0_PrfCalculationValuesPrivate, CsmConf_CsmKey_CsmKey_Tls_Conn0_PrfCalculationValuesPrivate, CSM_INVALID_KEYID  , CSM_INVALID_KEYID   , CSM_INVALID_KEYID ,              3081u,                          0u },  /* [/ActiveEcuC/Csm/CsmInOutRedirections/CsmInOutRedirection_Tls_PrfPrivate, /ActiveEcuC/Csm/CsmInOutRedirections, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Prf_HMacGenerate_Private:CsmInOutRedirectionRef] */
  { /*     3 */ CsmConf_CsmKey_CsmKey_Tls_Conn0_PrfCalculationValuesPublic , CsmConf_CsmKey_CsmKey_Tls_Conn0_PrfCalculationValuesPublic , CSM_INVALID_KEYID  , CSM_INVALID_KEYID   , CSM_INVALID_KEYID ,              3081u,                          0u }   /* [/ActiveEcuC/Csm/CsmInOutRedirections/CsmInOutRedirection_Tls_PrfPublic, /ActiveEcuC/Csm/CsmInOutRedirections, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Prf_HMacGenerate_Public:CsmInOutRedirectionRef] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_InOutRedirectionMap
**********************************************************************************************************************/
/** 
  \var    Csm_InOutRedirectionMap
  \brief  Maps Jobs to Redirections
  \details
  Element                        Description
  InOutJobRedirectionTableIdx    the index of the 1:1 relation pointing to Csm_InOutJobRedirectionTable
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_InOutRedirectionMapType, CSM_CONST) Csm_InOutRedirectionMap[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    InOutJobRedirectionTableIdx        Referable Keys */
  { /*     0 */                          2u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Prf_HMacGenerate_Private] */
  { /*     1 */                          3u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Prf_HMacGenerate_Public] */
  { /*     2 */                          0u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Prf_HMacGenerate_Private] */
  { /*     3 */                          1u }   /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Prf_HMacGenerate_Public] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobPrimitiveInfo
**********************************************************************************************************************/
/** 
  \var    Csm_JobPrimitiveInfo
  \brief  const uint32 callbackId; const Crypto_PrimitiveInfoType* primitiveInfo; const uint32 cryIfKeyId; const Crypto_ProcessingType processingType;
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_JobPrimitiveInfoType, CSM_CONST) Csm_JobPrimitiveInfo[87] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     JobPrimitiveInfo                                                                                                                         Referable Keys */
  /*     0 */ {0u, &Csm_PrimitiveInfo[23], CryIfConf_CryIfKey_CryIfKey_HmacSha256Generate_1, CRYPTO_PROCESSING_SYNC}                              ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_HmacSha256Generate_1] */
  /*     1 */ {0u, &Csm_PrimitiveInfo[0], CryIfConf_CryIfKey_CryIf_SccContractPrivKey, CRYPTO_PROCESSING_ASYNC}                                   ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SccECDSASignatureGenerate] */
  /*     2 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIf_SccPublicKey, CRYPTO_PROCESSING_ASYNC}                                         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SccECDSASignatureVerify] */
  /*     3 */ {0u, &Csm_PrimitiveInfo[2], CryIfConf_CryIfKey_CryIf_SccPublicKey, CRYPTO_PROCESSING_SYNC}                                          ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SccSha256] */
  /*     4 */ {0u, &Csm_PrimitiveInfo[17], CryIfConf_CryIfKey_CryIfKey_Scc_SHA512, CRYPTO_PROCESSING_SYNC}                                        ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SccSha512] */
  /*     5 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey, CRYPTO_PROCESSING_SYNC}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOLeaf_ECDSA_Verify] */
  /*     6 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey, CRYPTO_PROCESSING_SYNC}               ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOSubCA1_ECDSA_Verify] */
  /*     7 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey, CRYPTO_PROCESSING_SYNC}               ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOSubCA2_ECDSA_Verify] */
  /*     8 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey, CRYPTO_PROCESSING_SYNC}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSLeaf_ECDSA_Verify] */
  /*     9 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey, CRYPTO_PROCESSING_SYNC}               ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSSubCA1_ECDSA_Verify] */
  /*    10 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey, CRYPTO_PROCESSING_SYNC}               ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSSubCA2_ECDSA_Verify] */
  /*    11 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey, CRYPTO_PROCESSING_SYNC}              ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPLeaf_0_ECDSA_Verify] */
  /*    12 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey, CRYPTO_PROCESSING_SYNC}              ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPLeaf_1_ECDSA_Verify] */
  /*    13 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey, CRYPTO_PROCESSING_SYNC}            ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa1_1_ECDSA_Verify] */
  /*    14 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey, CRYPTO_PROCESSING_SYNC}            ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa2_0_ECDSA_Verify] */
  /*    15 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey, CRYPTO_PROCESSING_SYNC}            ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa2_1_ECDSA_Verify] */
  /*    16 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey, CRYPTO_PROCESSING_SYNC}           ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvLeaf_0_ECDSA_Verify] */
  /*    17 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey, CRYPTO_PROCESSING_SYNC}           ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvLeaf_1_ECDSA_Verify] */
  /*    18 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey, CRYPTO_PROCESSING_SYNC}         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa1_1_ECDSA_Verify] */
  /*    19 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey, CRYPTO_PROCESSING_SYNC}         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa2_0_ECDSA_Verify] */
  /*    20 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey, CRYPTO_PROCESSING_SYNC}         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa2_1_ECDSA_Verify] */
  /*    21 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_V2GRoot_X_PublicKey, CRYPTO_PROCESSING_SYNC}                     ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_V2GRoot_0_Verify, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_V2GRoot_1_Verify] */
  /*    22 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey, CRYPTO_PROCESSING_SYNC}           ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleLeaf_ECDSA_Verify] */
  /*    23 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey, CRYPTO_PROCESSING_SYNC}         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleSubCA1_ECDSA_Verify] */
  /*    24 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey, CRYPTO_PROCESSING_SYNC}         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleSubCA2_ECDSA_Verify] */
  /*    25 */ {0u, &Csm_PrimitiveInfo[19], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey, CRYPTO_PROCESSING_ASYNC} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_secp521r1_SignatureGenerate] */
  /*    26 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey, CRYPTO_PROCESSING_ASYNC}    ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_secp521r1_SignatureVerify] */
  /*    27 */ {0u, &Csm_PrimitiveInfo[25], CryIfConf_CryIfKey_CryIfKey_Scc_KDF, CRYPTO_PROCESSING_ASYNC}                                          ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_KDF] */
  /*    28 */ {0u, &Csm_PrimitiveInfo[26], CryIfConf_CryIfKey_CryIfKey_Scc_KDF_1, CRYPTO_PROCESSING_SYNC}                                         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_KDF_ISO15118_20] */
  /*    29 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_Scc_MOContract_X_PublicKey, CRYPTO_PROCESSING_SYNC}                         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOCOntract_X_Verify] */
  /*    30 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_Scc_MORoot_X_PublicKey, CRYPTO_PROCESSING_SYNC}                             ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MORoot_X_Verify] */
  /*    31 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_Scc_MOSubCa1_X_PublicKey, CRYPTO_PROCESSING_SYNC}                           ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOSubCa1_X_Verify] */
  /*    32 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_Scc_MOSubCa2_X_PublicKey, CRYPTO_PROCESSING_SYNC}                           ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOSubCa2_X_Verify] */
  /*    33 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_Scc_OEMProvRoot, CRYPTO_PROCESSING_SYNC}                                    ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvRoot] */
  /*    34 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_Scc_OEMProvSubCa1, CRYPTO_PROCESSING_SYNC}                                  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvSubCa1] */
  /*    35 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_Scc_OEMProvSubCa2, CRYPTO_PROCESSING_SYNC}                                  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvSubCa2] */
  /*    36 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_Scc_OEMProv_X_PublicKey, CRYPTO_PROCESSING_SYNC}                            ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProv_X_Verify] */
  /*    37 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_Scc_ProvLeaf_X_PublicKey, CRYPTO_PROCESSING_SYNC}                           ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvLeaf_X_Verify] */
  /*    38 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_Scc_ProvSubCa1_X_PublicKey, CRYPTO_PROCESSING_SYNC}                         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvSubCa1_X_Verify] */
  /*    39 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_Scc_ProvSubCa2_X_PublicKey, CRYPTO_PROCESSING_SYNC}                         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvSubCa2_X_Verify] */
  /*    40 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_Scc_V2GRoot_X_PublicKey, CRYPTO_PROCESSING_SYNC}                            ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_V2GRoot_X_Verify] */
  /*    41 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_Scc_V2GRoot_Y_PublicKey, CRYPTO_PROCESSING_SYNC}                            ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_V2GRoot_Y_Verify] */
  /*    42 */ {1u, &Csm_PrimitiveInfo[16], CryIfConf_CryIfKey_CryIfKey_V2G_Root_1_PubKey, CRYPTO_PROCESSING_ASYNC}                                ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_1] */
  /*    43 */ {1u, &Csm_PrimitiveInfo[16], CryIfConf_CryIfKey_CryIfKey_V2G_Root_2_PubKey, CRYPTO_PROCESSING_ASYNC}                                ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_2] */
  /*    44 */ {1u, &Csm_PrimitiveInfo[16], CryIfConf_CryIfKey_CryIfKey_V2G_Root_3_PubKey, CRYPTO_PROCESSING_ASYNC}                                ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_3] */
  /*    45 */ {1u, &Csm_PrimitiveInfo[16], CryIfConf_CryIfKey_CryIfKey_V2G_Root_4_PubKey, CRYPTO_PROCESSING_ASYNC}                                ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_4] */
  /*    46 */ {1u, &Csm_PrimitiveInfo[16], CryIfConf_CryIfKey_CryIfKey_V2G_Root_5_PubKey, CRYPTO_PROCESSING_ASYNC}                                ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_5] */
  /*    47 */ {1u, &Csm_PrimitiveInfo[16], CryIfConf_CryIfKey_CryIfKey_V2G_Root_6_PubKey, CRYPTO_PROCESSING_ASYNC}                                ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_6] */
  /*    48 */ {1u, &Csm_PrimitiveInfo[16], CryIfConf_CryIfKey_CryIfKey_V2G_Root_7_PubKey, CRYPTO_PROCESSING_ASYNC}                                ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_7] */
  /*    49 */ {1u, &Csm_PrimitiveInfo[16], CryIfConf_CryIfKey_CryIfKey_V2G_Root_8_PubKey, CRYPTO_PROCESSING_ASYNC}                                ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_8] */
  /* Index     JobPrimitiveInfo                                                                                                                         Referable Keys */
  /*    50 */ {1u, &Csm_PrimitiveInfo[16], CryIfConf_CryIfKey_CryIfKey_V2G_Root_9_PubKey, CRYPTO_PROCESSING_ASYNC}                                ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_9] */
  /*    51 */ {1u, &Csm_PrimitiveInfo[16], CryIfConf_CryIfKey_CryIfKey_V2G_Root_10_PubKey, CRYPTO_PROCESSING_ASYNC}                               ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_10] */
  /*    52 */ {0u, &Csm_PrimitiveInfo[18], CryIfConf_CryIfKey_CryIfKey_TlsConn0_HS_DhSignatureGenerate, CRYPTO_PROCESSING_SYNC}                   ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn0_HS_DhSignatureGenerate] */
  /*    53 */ {0u, &Csm_PrimitiveInfo[34], CryIfConf_CryIfKey_CryIfKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey, CRYPTO_PROCESSING_SYNC}           ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn0_HS_DhSignatureVerify] */
  /*    54 */ {0u, &Csm_PrimitiveInfo[19], CryIfConf_CryIfKey_CryIfKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1, CRYPTO_PROCESSING_SYNC}         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn1_HS_DhSignatureGenerate_Secp521r1] */
  /*    55 */ {0u, &Csm_PrimitiveInfo[35], CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey, CRYPTO_PROCESSING_SYNC}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn1_HS_DhSignatureVerify_Secp521r1] */
  /*    56 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey, CRYPTO_PROCESSING_SYNC}            ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_CertVerify_Leaf_Server_A_EccNistP256R1Sha256] */
  /*    57 */ {0u, &Csm_PrimitiveInfo[3], CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_Aes128Cbc_Decrypt, CRYPTO_PROCESSING_SYNC}                        ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Aes128Cbc_Decrypt] */
  /*    58 */ {0u, &Csm_PrimitiveInfo[4], CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_Aes128Cbc_Encrypt, CRYPTO_PROCESSING_SYNC}                        ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Aes128Cbc_Encrypt] */
  /*    59 */ {0u, &Csm_PrimitiveInfo[5], CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_CertVerify_PubKey, CRYPTO_PROCESSING_SYNC}                        ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_CertVerify_EccNistP256R1Sha1] */
  /*    60 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_CertVerify_PubKey, CRYPTO_PROCESSING_SYNC}                        ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_CertVerify_EccNistP256R1Sha256] */
  /*    61 */ {0u, &Csm_PrimitiveInfo[7], CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_HMacShaX_Generate, CRYPTO_PROCESSING_SYNC}                        ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha1_Generate] */
  /*    62 */ {0u, &Csm_PrimitiveInfo[8], CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_HMacShaX_Verify, CRYPTO_PROCESSING_SYNC}                          ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha1_Verify] */
  /*    63 */ {0u, &Csm_PrimitiveInfo[9], CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_HMacShaX_Generate, CRYPTO_PROCESSING_SYNC}                        ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha256_Generate] */
  /*    64 */ {0u, &Csm_PrimitiveInfo[10], CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_HMacShaX_Verify, CRYPTO_PROCESSING_SYNC}                         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha256_Verify] */
  /*    65 */ {0u, &Csm_PrimitiveInfo[18], CryIfConf_CryIfKey_CryIf_SccContractPrivKey, CRYPTO_PROCESSING_SYNC}                                   ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_DhSignatureGenerate] */
  /*    66 */ {0u, &Csm_PrimitiveInfo[34], CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_CertVerify_PubKey, CRYPTO_PROCESSING_SYNC}                       ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_DhSignatureVerify] */
  /*    67 */ {0u, &Csm_PrimitiveInfo[11], CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_HS_RandomNumber, CRYPTO_PROCESSING_SYNC}                         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_RandomNumber] */
  /*    68 */ {0u, &Csm_PrimitiveInfo[2], CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_HS_HashSha256_Finished, CRYPTO_PROCESSING_SYNC}                   ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HashSha256_Finished] */
  /*    69 */ {0u, &Csm_PrimitiveInfo[9], CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_Prf_Secret, CRYPTO_PROCESSING_SYNC}                               ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Prf_HMacGenerate_Private, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Prf_HMacGenerate_Public] */
  /*    70 */ {0u, &Csm_PrimitiveInfo[28], CryIfConf_CryIfKey_CryIfKey_Tls_Conn1_Aes256GcmDecrypt, CRYPTO_PROCESSING_SYNC}                        ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Aes256Gcm_Decrypt_1] */
  /*    71 */ {0u, &Csm_PrimitiveInfo[29], CryIfConf_CryIfKey_CryIfKey_Tls_Conn1_Aes256GcmEncrypt, CRYPTO_PROCESSING_SYNC}                        ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Aes256Gcm_Encrypt_1] */
  /*    72 */ {0u, &Csm_PrimitiveInfo[30], CryIfConf_CryIfKey_CryIfKey_Tls_ChaCha20_Decrypt, CRYPTO_PROCESSING_SYNC}                              ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_ChaCha20_Decrypt] */
  /*    73 */ {0u, &Csm_PrimitiveInfo[31], CryIfConf_CryIfKey_CryIfKey_Tls_ChaCha20_Encrypt, CRYPTO_PROCESSING_SYNC}                              ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_ChaCha20_Encrypt] */
  /*    74 */ {0u, &Csm_PrimitiveInfo[2], CryIfConf_CryIfKey_CryIfKey_Tls_Conn1_HS_HashSha256_Finished, CRYPTO_PROCESSING_SYNC}                   ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha256_Finished] */
  /*    75 */ {0u, &Csm_PrimitiveInfo[32], CryIfConf_CryIfKey_CryIfKey_Tls_Conn1_HS_HashSha384_Finished, CRYPTO_PROCESSING_SYNC}                  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha384] */
  /*    76 */ {0u, &Csm_PrimitiveInfo[2], CryIfConf_CryIfKey_CryIfKey_Tls_Conn1_HS_HashSha384_Finished, CRYPTO_PROCESSING_SYNC}                   ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha384_Finished] */
  /*    77 */ {0u, &Csm_PrimitiveInfo[9], CryIfConf_CryIfKey_CryIfKey_Tls_Conn1_Prf_Secret_Secp521, CRYPTO_PROCESSING_SYNC}                       ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Prf_HMacGenerate_Private, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Prf_HMacGenerate_Public] */
  /*    78 */ {0u, &Csm_PrimitiveInfo[6], CryIfConf_CryIfKey_CryIfKey_Tls_Global_HashSha1, CRYPTO_PROCESSING_SYNC}                                ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Global_HashSha1] */
  /*    79 */ {0u, &Csm_PrimitiveInfo[20], CryIfConf_CryIfKey_CryIfKey_Hkdf_Sha256, CRYPTO_PROCESSING_SYNC}                                       ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha256] */
  /*    80 */ {0u, &Csm_PrimitiveInfo[21], CryIfConf_CryIfKey_CryIfKey_Tls_Hkdf_Sha256ExpandIn, CRYPTO_PROCESSING_SYNC}                           ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha256Expand] */
  /*    81 */ {0u, &Csm_PrimitiveInfo[22], CryIfConf_CryIfKey_CryIfKey_Hkdf_Sha384, CRYPTO_PROCESSING_SYNC}                                       ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha384] */
  /*    82 */ {0u, &Csm_PrimitiveInfo[33], CryIfConf_CryIfKey_CryIfKey_Tls_Hkdf_Sha384ExpandIn, CRYPTO_PROCESSING_SYNC}                           ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha384Expand] */
  /*    83 */ {0u, &Csm_PrimitiveInfo[24], CryIfConf_CryIfKey_CryIfKey_Tls_HMacSha384Generate, CRYPTO_PROCESSING_SYNC}                            ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_HmacSha384Generate_1] */
  /*    84 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_Tls_Root_A_EccSecp256r1Sha256_PubKey, CRYPTO_PROCESSING_SYNC}               ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Root_A_EccNistP256R1Sha256] */
  /*    85 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey, CRYPTO_PROCESSING_SYNC}             ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_SubCa1_A_EccNistP256R1Sha256] */
  /*    86 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey, CRYPTO_PROCESSING_SYNC}                /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_SubCa2_A_EccNistP256R1Sha256] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobTable
**********************************************************************************************************************/
/** 
  \var    Csm_JobTable
  \brief  Contains parameters of /MICROSAR/Csm/CsmJobs/CsmJob.
  \details
  Element                    Description
  BswCallbacksIdx            the index of the 0:1 relation pointing to Csm_BswCallbacks
  CsmKeyIdIdx                the index of the 1:1 relation pointing to Csm_Key
  InOutRedirectionMapIdx     the index of the 0:1 relation pointing to Csm_InOutRedirectionMap
  JobPartitionIdx        
  JobPrimitiveInfoIdx        the index of the 1:1 relation pointing to Csm_JobPrimitiveInfo
  MaskedBits                 contains bitcoded the boolean data of Csm_AsynchronousOfJobTable, Csm_PrimitiveCallbackUpdateNotificationOfJobTable
  Priority                   Contains values of DefinitionRef: /MICROSAR/Csm/CsmJobs/CsmJob/CsmJobPriority.
  QueueInfoIdx               the index of the 1:1 relation pointing to Csm_QueueInfo
  RteCallbackPartitionIdx
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_JobTableType, CSM_CONST) Csm_JobTable[90] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    BswCallbacksIdx                   CsmKeyIdIdx  InOutRedirectionMapIdx                   JobPartitionIdx                   JobPrimitiveInfoIdx  MaskedBits  Priority  QueueInfoIdx  RteCallbackPartitionIdx                         Referable Keys */
  { /*     0 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          3u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                  0u,      0x00u,       0u,           0u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_HmacSha256Generate_1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_CHACHA20_POLY1305_SHA256_Secp521r1:TcpIpTlsCipherCsmMacGenerateJobRef] */
  { /*     1 */                               1u,        106u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                  1u,      0x03u,       0u,           0u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SccECDSASignatureGenerate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_2Config/SccISO2CsmConfig:SccECDSAGenSignJobId] */
  { /*     2 */                               1u,        107u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                  2u,      0x03u,       0u,           0u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SccECDSASignatureVerify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_2Config/SccISO2CsmConfig:SccECDSAVerifyJobId] */
  { /*     3 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,        107u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                  3u,      0x00u,       0u,           0u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SccSha256, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_2Config/SccISO2CsmConfig:SccSHA256JobId] */
  { /*     4 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         38u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                  4u,      0x00u,       0u,           0u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SccSha512, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_20Config/SccISO20CsmConfig/SccCommonCsmConfig:SccSHA512JobId] */
  { /*     5 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          7u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                  5u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOLeaf_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  { /*     6 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          8u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                  6u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOSubCA1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  { /*     7 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          9u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                  7u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOSubCA2_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  { /*     8 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         10u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                  8u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSLeaf_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  { /*     9 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         11u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                  9u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSSubCA1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    10 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         12u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 10u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSSubCA2_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    11 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         14u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 11u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPLeaf_0_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    12 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         16u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 12u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPLeaf_1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs] */
  { /*    13 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         17u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 13u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa1_1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    14 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         18u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 14u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa2_0_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    15 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         19u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 15u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa2_1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs] */
  { /*    16 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         21u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 16u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvLeaf_0_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_OEMProvCertificate_0:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    17 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         23u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 17u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvLeaf_1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs] */
  { /*    18 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         24u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 18u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa1_1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_OEMProvSubCA1_0:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    19 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         25u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 19u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa2_0_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_OEMProvSubCA2_0:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    20 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         26u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 20u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa2_1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs] */
  { /*    21 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         27u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 21u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_V2GRoot_0_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_0:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    22 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         27u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 21u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_V2GRoot_1_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_1:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    23 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         30u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 22u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleLeaf_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_VehicleCert_0:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    24 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         31u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 23u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleSubCA1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_VehicleSubCA1_0:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    25 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         32u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 24u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleSubCA2_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_VehicleSubCA2_0:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    26 */                               1u,         33u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 25u,      0x03u,       0u,           0u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_secp521r1_SignatureGenerate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_20Config/SccISO20CsmConfig/SccSecp521r1Config:SccSignatureGenerationJobId] */
  { /*    27 */                               1u,         34u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 26u,      0x03u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_secp521r1_SignatureVerify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_20Config/SccISO20CsmConfig/SccSecp521r1Config:SccSignatureVerifyJobId] */
  { /*    28 */                               1u,         35u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 27u,      0x02u,       0u,           0u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_KDF, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_2Config/SccISO2CsmConfig:SccKeyDeriveFuncJobId] */
  { /*    29 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         36u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 28u,      0x00u,       0u,           4u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_KDF_ISO15118_20, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_20Config/SccISO20CsmConfig/SccSecp521r1Config:SccKeyDeriveFuncJobId] */
  { /*    30 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,        109u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 29u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOCOntract_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    31 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         37u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 30u,      0x00u,       0u,           0u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MORoot_X_Verify, /ActiveEcuC/Csm/CsmJobs] */
  { /*    32 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,        110u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 31u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOSubCa1_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA1_0:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    33 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,        111u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 32u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOSubCa2_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA2_0:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    34 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,        112u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 33u,      0x00u,       0u,           0u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvRoot, /ActiveEcuC/Csm/CsmJobs] */
  { /*    35 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,        113u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 34u,      0x00u,       0u,           0u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvSubCa1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_OEMProvSubCa1:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    36 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,        114u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 35u,      0x00u,       0u,           0u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvSubCa2, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_OEMProvSubCa2:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    37 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,        116u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 36u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProv_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_OEMProvCertificate_0:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    38 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,        117u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 37u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvLeaf_X_Verify, /ActiveEcuC/Csm/CsmJobs] */
  { /*    39 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,        118u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 38u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvSubCa1_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSLeaf_Tmp:KeyMCertCsmSignatureVerifyJobRef, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA1_Tmp:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    40 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,        119u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 39u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvSubCa2_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA2_Tmp:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    41 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,        121u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 40u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_V2GRoot_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2GRoot_0:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    42 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         39u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 41u,      0x00u,       0u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_V2GRoot_Y_Verify, /ActiveEcuC/Csm/CsmJobs] */
  { /*    43 */                               0u,         96u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 42u,      0x02u,       0u,           1u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_1:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    44 */                               0u,         97u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 43u,      0x02u,       0u,           1u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_2, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_2:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    45 */                               0u,         98u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 44u,      0x02u,       0u,           1u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_3, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_3:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    46 */                               0u,         99u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 45u,      0x02u,       0u,           1u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_4, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_4:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    47 */                               0u,        100u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 46u,      0x02u,       0u,           1u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_5, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_5:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    48 */                               0u,        101u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 47u,      0x02u,       0u,           1u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_6, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_6:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    49 */                               0u,        102u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 48u,      0x02u,       0u,           1u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_7, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_7:KeyMCertCsmSignatureVerifyJobRef] */
    /* Index    BswCallbacksIdx                   CsmKeyIdIdx  InOutRedirectionMapIdx                   JobPartitionIdx                   JobPrimitiveInfoIdx  MaskedBits  Priority  QueueInfoIdx  RteCallbackPartitionIdx                         Referable Keys */
  { /*    50 */                               0u,        103u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 49u,      0x02u,       0u,           1u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_8, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_8:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    51 */                               0u,        104u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 50u,      0x02u,       0u,           1u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_9, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_9:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    52 */                               0u,        105u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 51u,      0x02u,       0u,           1u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_10, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_10:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    53 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         41u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 52u,      0x00u,       1u,           5u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn0_HS_DhSignatureGenerate, /ActiveEcuC/Csm/CsmJobs] */
  { /*    54 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          4u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 53u,      0x00u,       1u,           5u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn0_HS_DhSignatureVerify, /ActiveEcuC/Csm/CsmJobs] */
  { /*    55 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         43u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 54u,      0x00u,       1u,           7u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn1_HS_DhSignatureGenerate_Secp521r1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1:TcpIpTlsCsmKeyExchangeSignatureGenerateJobRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1:TcpIpTlsCsmKeyExchangeSignatureGenerateJobRef] */
  { /*    56 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          7u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 55u,      0x00u,       1u,          11u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn1_HS_DhSignatureVerify_Secp521r1, /ActiveEcuC/Csm/CsmJobs] */
  { /*    57 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          4u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 56u,      0x00u,       0u,           5u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_CertVerify_Leaf_Server_A_EccNistP256R1Sha256, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOLeaf_Tmp:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    58 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         48u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 57u,      0x00u,       0u,           5u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Aes128Cbc_Decrypt, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256:TcpIpTlsCipherCsmDecryptJobRef] */
  { /*    59 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         49u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 58u,      0x00u,       0u,           5u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Aes128Cbc_Encrypt, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256:TcpIpTlsCipherCsmEncryptJobRef] */
  { /*    60 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         50u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 59u,      0x00u,       0u,           5u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_CertVerify_EccNistP256R1Sha1, /ActiveEcuC/Csm/CsmJobs] */
  { /*    61 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         50u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 60u,      0x00u,       0u,           5u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_CertVerify_EccNistP256R1Sha256, /ActiveEcuC/Csm/CsmJobs] */
  { /*    62 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         52u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 61u,      0x00u,       0u,           5u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha1_Generate, /ActiveEcuC/Csm/CsmJobs] */
  { /*    63 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         53u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 62u,      0x00u,       0u,           5u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha1_Verify, /ActiveEcuC/Csm/CsmJobs] */
  { /*    64 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         52u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 63u,      0x00u,       0u,           5u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha256_Generate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256:TcpIpTlsCipherCsmMacGenerateJobRef] */
  { /*    65 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         53u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 64u,      0x00u,       0u,           5u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha256_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256:TcpIpTlsCipherCsmMacVerifyJobRef] */
  { /*    66 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         55u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 65u,      0x00u,       0u,           5u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_DhSignatureGenerate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1:TcpIpTlsCsmKeyExchangeSignatureGenerateJobRef] */
  { /*    67 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         51u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 66u,      0x01u,       0u,           5u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_DhSignatureVerify, /ActiveEcuC/Csm/CsmJobs] */
  { /*    68 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         58u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 67u,      0x00u,       0u,           5u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_RandomNumber, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig:TcpIpTlsCsmRandomGenerateJobRef] */
  { /*    69 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         59u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 68u,      0x00u,       0u,           6u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HashSha256_Finished, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1:TcpIpTlsCsmHashVerifyJobRef] */
  { /*    70 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         67u,                                      0u, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 69u,      0x00u,       0u,           5u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Prf_HMacGenerate_Private, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1:TcpIpTlsCsmPrfMacJobRef] */
  { /*    71 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         68u,                                      1u, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 69u,      0x00u,       0u,           5u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Prf_HMacGenerate_Public, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1:TcpIpTlsCsmPrfMacGeneratePublicJobRef] */
  { /*    72 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         70u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 70u,      0x00u,       0u,           7u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Aes256Gcm_Decrypt_1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_WITH_AES_256_GCM_SHA384_Secp521r1:TcpIpTlsCipherCsmDecryptJobRef] */
  { /*    73 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         71u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 71u,      0x00u,       0u,           7u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Aes256Gcm_Encrypt_1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_WITH_AES_256_GCM_SHA384_Secp521r1:TcpIpTlsCipherCsmEncryptJobRef] */
  { /*    74 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         44u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 72u,      0x00u,       0u,           7u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_ChaCha20_Decrypt, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_CHACHA20_POLY1305_SHA256_Secp521r1:TcpIpTlsCipherCsmDecryptJobRef] */
  { /*    75 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         45u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 73u,      0x00u,       0u,           7u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_ChaCha20_Encrypt, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_CHACHA20_POLY1305_SHA256_Secp521r1:TcpIpTlsCipherCsmEncryptJobRef] */
  { /*    76 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         74u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 74u,      0x00u,       0u,           8u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha256_Finished, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1:TcpIpTlsCsmHashVerifyJobRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfHashMessagesJobRef] */
  { /*    77 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         75u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 75u,      0x00u,       0u,           9u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha384, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfHashMessagesJobRef] */
  { /*    78 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         75u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 76u,      0x00u,       0u,           8u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha384_Finished, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1:TcpIpTlsCsmHashVerifyJobRef] */
  { /*    79 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         81u,                                      2u, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 77u,      0x00u,       0u,           7u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Prf_HMacGenerate_Private, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1:TcpIpTlsCsmPrfMacJobRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1:TcpIpTlsCsmPrfMacJobRef] */
  { /*    80 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         81u,                                      3u, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 77u,      0x00u,       0u,           7u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Prf_HMacGenerate_Public, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1:TcpIpTlsCsmPrfMacGeneratePublicJobRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1:TcpIpTlsCsmPrfMacGeneratePublicJobRef] */
  { /*    81 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         83u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 78u,      0x00u,       0u,          10u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Global_HashSha1, /ActiveEcuC/Csm/CsmJobs] */
  { /*    82 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          1u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 79u,      0x00u,       0u,           2u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha256, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfJobRef] */
  { /*    83 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         88u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 80u,      0x00u,       0u,           2u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha256Expand, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfExpandJobRef] */
  { /*    84 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          2u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 81u,      0x00u,       0u,           3u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha384, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfJobRef] */
  { /*    85 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         90u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 82u,      0x00u,       0u,           9u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha384Expand, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfExpandJobRef] */
  { /*    86 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         84u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 83u,      0x00u,       0u,           0u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_HmacSha384Generate_1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_WITH_AES_256_GCM_SHA384_Secp521r1:TcpIpTlsCipherCsmMacGenerateJobRef] */
  { /*    87 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         93u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 84u,      0x00u,       0u,           5u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Root_A_EccNistP256R1Sha256, /ActiveEcuC/Csm/CsmJobs] */
  { /*    88 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         94u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 85u,      0x00u,       0u,           5u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_SubCa1_A_EccNistP256R1Sha256, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA1_Tmp:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    89 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         95u, CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE, CSM_NO_JOBPARTITIONIDXOFJOBTABLE,                 86u,      0x00u,       0u,           5u, CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE }   /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_SubCa2_A_EccNistP256R1Sha256, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA2_Tmp:KeyMCertCsmSignatureVerifyJobRef] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Key
**********************************************************************************************************************/
/** 
  \var    Csm_Key
  \brief  Contains parameters of /AUTOSAR/EcucDefs/Csm/CsmKeys/CsmKey.
  \details
  Element       Description
  CryIfKeyId    Contains values of DefinitionRef: /MICROSAR/Csm/CsmKeys/CsmKey/CsmKeyRef.
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_KeyType, CSM_CONST) Csm_Key[123] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CryIfKeyId                                                                          Referable Keys */
  { /*     0 */ CryIfConf_CryIfKey_CryIfKey_DefaultRandomSource                              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_DefaultRandomSource, /ActiveEcuC/Csm/CsmKeys] */
  { /*     1 */ CryIfConf_CryIfKey_CryIfKey_Hkdf_Sha256                                      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Hkdf_Sha256, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha256:CsmJobKeyRef] */
  { /*     2 */ CryIfConf_CryIfKey_CryIfKey_Hkdf_Sha384                                      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Hkdf_Sha384, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha384:CsmJobKeyRef] */
  { /*     3 */ CryIfConf_CryIfKey_CryIfKey_HmacSha256Generate_1                             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_HmacSha256Generate_1, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_HmacSha256Generate_1:CsmJobKeyRef] */
  { /*     4 */ CryIfConf_CryIfKey_CryIfKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn0_HS_DhSignatureVerify:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_CertVerify_Leaf_Server_A_EccNistP256R1Sha256:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOLeaf_Tmp:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*     5 */ CryIfConf_CryIfKey_CryIfKey_Leaf_Server_A_EccSecp521r1Sha512_PubKey          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Leaf_Server_A_EccSecp521r1Sha512_PubKey, /ActiveEcuC/Csm/CsmKeys] */
  { /*     6 */ CryIfConf_CryIfKey_CryIfKey_RandomGenerator                                  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_RandomGenerator, /ActiveEcuC/Csm/CsmKeys] */
  { /*     7 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOLeaf_ECDSA_Verify:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn1_HS_DhSignatureVerify_Secp521r1:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*     8 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOSubCA1_ECDSA_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*     9 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOSubCA2_ECDSA_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    10 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSLeaf_ECDSA_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    11 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSSubCA1_ECDSA_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    12 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSSubCA2_ECDSA_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    13 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey            },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/KeyM/SccCryptoKey_ISO20_ContractCertificate_0_ECDSA:KeyMCryptoKeyCsmKeyTargetRef] */
  { /*    14 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPLeaf_0_ECDSA_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    15 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PrivateKey            },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PrivateKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/KeyM/SccCryptoKey_ISO20_ContractCertificate_1_ECDSA:KeyMCryptoKeyCsmKeyTargetRef] */
  { /*    16 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPLeaf_1_ECDSA_Verify:CsmJobKeyRef] */
  { /*    17 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey           },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa1_1_ECDSA_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    18 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey           },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa2_0_ECDSA_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    19 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey           },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa2_1_ECDSA_Verify:CsmJobKeyRef] */
  { /*    20 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey         },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/KeyM/SccCryptoKey_ISO20_OEMProvCertificate_0:KeyMCryptoKeyCsmKeyTargetRef] */
  { /*    21 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvLeaf_0_ECDSA_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO20_OEMProvCertificate_0:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    22 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PrivateKey         },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PrivateKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/KeyM/SccCryptoKey_ISO20_OEMProvCertificate_1:KeyMCryptoKeyCsmKeyTargetRef] */
  { /*    23 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvLeaf_1_ECDSA_Verify:CsmJobKeyRef] */
  { /*    24 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey        },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa1_1_ECDSA_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO20_OEMProvSubCA1_0:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    25 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey        },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa2_0_ECDSA_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO20_OEMProvSubCA2_0:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    26 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey        },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa2_1_ECDSA_Verify:CsmJobKeyRef] */
  { /*    27 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_V2GRoot_X_PublicKey                    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_V2GRoot_X_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_V2GRoot_0_Verify:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_V2GRoot_1_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_0:KeyMCertCsmSignatureVerifyKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_1:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    28 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_V2GRoot_Y_PublicKey                    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_V2GRoot_Y_PublicKey, /ActiveEcuC/Csm/CsmKeys] */
  { /*    29 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey         },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/KeyM/SccCryptoKey_ISO20_VehicleCertificate_0:KeyMCryptoKeyCsmKeyTargetRef] */
  { /*    30 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleLeaf_ECDSA_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO20_VehicleCert_0:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    31 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey        },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleSubCA1_ECDSA_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO20_VehicleSubCA1_0:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    32 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey        },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleSubCA2_ECDSA_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO20_VehicleSubCA2_0:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    33 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_secp521r1_SignatureGenerate:CsmJobKeyRef] */
  { /*    34 */ CryIfConf_CryIfKey_CryIfKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_secp521r1_SignatureVerify:CsmJobKeyRef] */
  { /*    35 */ CryIfConf_CryIfKey_CryIfKey_Scc_KDF                                          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_KDF, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_KDF:CsmJobKeyRef] */
  { /*    36 */ CryIfConf_CryIfKey_CryIfKey_Scc_KDF_1                                        },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_KDF_1, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_KDF_ISO15118_20:CsmJobKeyRef] */
  { /*    37 */ CryIfConf_CryIfKey_CryIfKey_Scc_MORoot_X_PublicKey                           },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_MORoot_X_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MORoot_X_Verify:CsmJobKeyRef] */
  { /*    38 */ CryIfConf_CryIfKey_CryIfKey_Scc_SHA512                                       },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_SHA512, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_SccSha512:CsmJobKeyRef] */
  { /*    39 */ CryIfConf_CryIfKey_CryIfKey_Scc_V2GRoot_Y_PublicKey                          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_V2GRoot_Y_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_V2GRoot_Y_Verify:CsmJobKeyRef] */
  { /*    40 */ CryIfConf_CryIfKey_CryIfKey_TlsConn0_HS_DhKeyExchange                        },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_TlsConn0_HS_DhKeyExchange, /ActiveEcuC/Csm/CsmKeys] */
  { /*    41 */ CryIfConf_CryIfKey_CryIfKey_TlsConn0_HS_DhSignatureGenerate                  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_TlsConn0_HS_DhSignatureGenerate, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn0_HS_DhSignatureGenerate:CsmJobKeyRef] */
  { /*    42 */ CryIfConf_CryIfKey_CryIfKey_TlsConn1_HS_DhKeyExchange_Secp521r1              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_TlsConn1_HS_DhKeyExchange_Secp521r1, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1:TcpIpTlsCsmKeyExchangeKeyRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1:TcpIpTlsCsmKeyExchangeKeyRef] */
  { /*    43 */ CryIfConf_CryIfKey_CryIfKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1        },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn1_HS_DhSignatureGenerate_Secp521r1:CsmJobKeyRef] */
  { /*    44 */ CryIfConf_CryIfKey_CryIfKey_Tls_ChaCha20_Decrypt                             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_ChaCha20_Decrypt, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_ChaCha20_Decrypt:CsmJobKeyRef, /ActiveEcuC/Csm/CsmPrimitives_Tls_ChaCha20_Decrypt/CsmAEADDecrypt/CsmPrimitives_Tls_ChaCha20_Decrypt:CsmAEADDecryptKeyRef] */
  { /*    45 */ CryIfConf_CryIfKey_CryIfKey_Tls_ChaCha20_Encrypt                             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_ChaCha20_Encrypt, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_ChaCha20_Encrypt:CsmJobKeyRef, /ActiveEcuC/Csm/CsmPrimitives_Tls_ChaCha20_Encrypt/CsmAEADEncrypt/CsmPrimitives_Tls_ChaCha20_Encrypt:CsmAEADEncryptKeyRef] */
  { /*    46 */ CryIfConf_CryIfKey_CryIfKey_Tls_ChaCha20_PassiveDecrypt                      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_ChaCha20_PassiveDecrypt, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_CHACHA20_POLY1305_SHA256_Secp521r1:TcpIpTlsCipherCsmPassiveDecryptKeyRef] */
  { /*    47 */ CryIfConf_CryIfKey_CryIfKey_Tls_ChaCha20_PassiveEncrypt                      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_ChaCha20_PassiveEncrypt, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_CHACHA20_POLY1305_SHA256_Secp521r1:TcpIpTlsCipherCsmPassiveEncryptKeyRef] */
  { /*    48 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_Aes128Cbc_Decrypt                      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_Aes128Cbc_Decrypt, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Aes128Cbc_Decrypt:CsmJobKeyRef] */
  { /*    49 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_Aes128Cbc_Encrypt                      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_Aes128Cbc_Encrypt, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Aes128Cbc_Encrypt:CsmJobKeyRef] */
    /* Index    CryIfKeyId                                                                          Referable Keys */
  { /*    50 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_CertVerify_PubKey                      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_CertVerify_PubKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_CertVerify_EccNistP256R1Sha1:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_CertVerify_EccNistP256R1Sha256:CsmJobKeyRef] */
  { /*    51 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_CertVerify_PubKey                      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_CertVerify_Server_Leaf_PubKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_DhSignatureVerify:CsmJobKeyRef] */
  { /*    52 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_HMacShaX_Generate                      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_HMacShaX_Generate, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha1_Generate:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha256_Generate:CsmJobKeyRef] */
  { /*    53 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_HMacShaX_Verify                        },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_HMacShaX_Verify, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha1_Verify:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha256_Verify:CsmJobKeyRef] */
  { /*    54 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_HS_DhKeyExchange                       },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_HS_DhKeyExchange, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1:TcpIpTlsCsmKeyExchangeKeyRef] */
  { /*    55 */ CryIfConf_CryIfKey_CryIf_SccContractPrivKey                                  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_HS_DhSignatureGenerate, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_DhSignatureGenerate:CsmJobKeyRef] */
  { /*    56 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_HS_HashSha256_ToClientFinished         },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_HS_HashSha256_ToClientFinished, /ActiveEcuC/Csm/CsmKeys] */
  { /*    57 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_HS_HashSha256_ToServerFinished         },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_HS_HashSha256_ToServerFinished, /ActiveEcuC/Csm/CsmKeys] */
  { /*    58 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_HS_RandomNumber                        },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_HS_RandomNumber, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_RandomNumber:CsmJobKeyRef] */
  { /*    59 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_HS_HashSha256_Finished                 },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_HashSha256_Finished, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HashSha256_Finished:CsmJobKeyRef] */
  { /*    60 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_MasterSecret                           },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_MasterSecret, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1:TcpIpTlsCsmMasterSecretKeyRef] */
  { /*    61 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_PreMasterSecretInfo                    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_PreMasterSecretInfo, /ActiveEcuC/Csm/CsmKeys] */
  { /*    62 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_PrfCalculationValuesPrivate            },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_PrfCalculationValuesPrivate, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmInOutRedirections/CsmInOutRedirection_Tls_PrfPrivate:CsmInputKeyRef, /ActiveEcuC/Csm/CsmInOutRedirections/CsmInOutRedirection_Tls_PrfPrivate:CsmOutputKeyRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1:TcpIpTlsCsmPrfMacKeyRef] */
  { /*    63 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_PrfCalculationValuesPublic             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_PrfCalculationValuesPublic, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmInOutRedirections/CsmInOutRedirection_Tls_PrfPublic:CsmInputKeyRef, /ActiveEcuC/Csm/CsmInOutRedirections/CsmInOutRedirection_Tls_PrfPublic:CsmOutputKeyRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1:TcpIpTlsCsmPrfMacCalcValuesPublicKeyRef] */
  { /*    64 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_Prf_ResultPrivate                      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_Prf_ResultPrivate, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1:TcpIpTlsCsmPrfResultPrivateKeyRef] */
  { /*    65 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_Prf_ResultPublic                       },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_Prf_ResultPublic, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1:TcpIpTlsCsmPrfResultPublicKeyRef] */
  { /*    66 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_Prf_Secret                             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_Prf_Secret, /ActiveEcuC/Csm/CsmKeys] */
  { /*    67 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_Prf_Secret                             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_Prf_Secret_32, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Prf_HMacGenerate_Private:CsmJobKeyRef] */
  { /*    68 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_Prf_Secret                             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_Prf_Secret_48, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Prf_HMacGenerate_Public:CsmJobKeyRef] */
  { /*    69 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn0_TmpBuffer                              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn0_TmpBuffer, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1:TcpIpTlsHsTemporaryBufferKeyRef] */
  { /*    70 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn1_Aes256GcmDecrypt                       },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_Aes256GcmDecrypt_1, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Aes256Gcm_Decrypt_1:CsmJobKeyRef, /ActiveEcuC/Csm/CsmPrimitives_Tls_Aes256Gcm_Decrypt/CsmAEADDecrypt/CsmPrimitives_Tls_Aes256Gcm_Decrypt:CsmAEADDecryptKeyRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_WITH_AES_256_GCM_SHA384_Secp521r1:TcpIpTlsCipherCsmDecryptKeyRef] */
  { /*    71 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn1_Aes256GcmEncrypt                       },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_Aes256GcmEncrypt_1, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Aes256Gcm_Encrypt_1:CsmJobKeyRef, /ActiveEcuC/Csm/CsmPrimitives_Tls_Aes256Gcm_Encrypt/CsmAEADEncrypt/CsmPrimitives_Tls_Aes256Gcm_Encrypt:CsmAEADEncryptKeyRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_WITH_AES_256_GCM_SHA384_Secp521r1:TcpIpTlsCipherCsmEncryptKeyRef] */
  { /*    72 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn1_Aes256GcmPassiveDecrypt                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_Aes256GcmPassiveDecrypt, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_WITH_AES_256_GCM_SHA384_Secp521r1:TcpIpTlsCipherCsmPassiveDecryptKeyRef] */
  { /*    73 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn1_Aes256GcmPassiveEncrypt                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_Aes256GcmPassiveEncrypt, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_WITH_AES_256_GCM_SHA384_Secp521r1:TcpIpTlsCipherCsmPassiveEncryptKeyRef] */
  { /*    74 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn1_HS_HashSha256_Finished                 },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_HS_HashSha256_Finished, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha256_Finished:CsmJobKeyRef] */
  { /*    75 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn1_HS_HashSha384_Finished                 },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_HS_HashSha384_Finished, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha384:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha384_Finished:CsmJobKeyRef] */
  { /*    76 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn1_MasterSecret                           },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_MasterSecret, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1:TcpIpTlsCsmMasterSecretKeyRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1:TcpIpTlsCsmMasterSecretKeyRef] */
  { /*    77 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn1_PrfCalculationValuesPrivate            },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_PrfCalculationValuesPrivate, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmInOutRedirections/CsmInOutRedirection_PrfPrivate_TlsConn1:CsmInputKeyRef, /ActiveEcuC/Csm/CsmInOutRedirections/CsmInOutRedirection_PrfPrivate_TlsConn1:CsmOutputKeyRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1:TcpIpTlsCsmPrfMacKeyRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1:TcpIpTlsCsmPrfMacKeyRef] */
  { /*    78 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn1_PrfCalculationValuesPublic             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_PrfCalculationValuesPublic, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmInOutRedirections/CsmInOutRedirection_PrfPublic_TlsConn1:CsmInputKeyRef, /ActiveEcuC/Csm/CsmInOutRedirections/CsmInOutRedirection_PrfPublic_TlsConn1:CsmOutputKeyRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1:TcpIpTlsCsmPrfMacCalcValuesPublicKeyRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1:TcpIpTlsCsmPrfMacCalcValuesPublicKeyRef] */
  { /*    79 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn1_Prf_ResultPrivate                      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_Prf_ResultPrivate, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1:TcpIpTlsCsmPrfResultPrivateKeyRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1:TcpIpTlsCsmPrfResultPrivateKeyRef] */
  { /*    80 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn1_Prf_ResultPublic                       },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_Prf_ResultPublic, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1:TcpIpTlsCsmPrfResultPublicKeyRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1:TcpIpTlsCsmPrfResultPublicKeyRef] */
  { /*    81 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn1_Prf_Secret_Secp521                     },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_Prf_Secret, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Prf_HMacGenerate_Private:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Prf_HMacGenerate_Public:CsmJobKeyRef] */
  { /*    82 */ CryIfConf_CryIfKey_CryIfKey_Tls_Conn1_TmpBuffer                              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Conn1_TmpBuffer, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1:TcpIpTlsHsTemporaryBufferKeyRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1:TcpIpTlsHsTemporaryBufferKeyRef] */
  { /*    83 */ CryIfConf_CryIfKey_CryIfKey_Tls_Global_HashSha1                              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Global_HashSha1, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Global_HashSha1:CsmJobKeyRef] */
  { /*    84 */ CryIfConf_CryIfKey_CryIfKey_Tls_HMacSha384Generate                           },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_HMacSha384Generate_1, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_HmacSha384Generate_1:CsmJobKeyRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_WITH_AES_256_GCM_SHA384_Secp521r1:TcpIpTlsCipherCsmMacGenerateKeyRef] */
  { /*    85 */ CryIfConf_CryIfKey_CryIfKey_Tls_Hkdf_ClientAdHsTrafficSecret                 },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_ClientAdHsTrafficSecret, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfClientAdHsTrafficSecretKeyRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfClientAdHsTrafficSecretKeyRef] */
  { /*    86 */ CryIfConf_CryIfKey_CryIfKey_Tls_Hkdf_DerivedSecret                           },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_DerivedSecret, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfDerivedSecretKeyRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfDerivedSecretKeyRef] */
  { /*    87 */ CryIfConf_CryIfKey_CryIfKey_Tls_Hkdf_ServerAdHsTrafficSecret                 },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_ServerAdHsTrafficSecret, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfServerAdHsTrafficSecretKeyRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfServerAdHsTrafficSecretKeyRef] */
  { /*    88 */ CryIfConf_CryIfKey_CryIfKey_Tls_Hkdf_Sha256ExpandIn                          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_Sha256ExpandIn, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha256Expand:CsmJobKeyRef] */
  { /*    89 */ CryIfConf_CryIfKey_CryIfKey_Tls_Hkdf_Sha256ExpandOut                         },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_Sha256ExpandOut, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfTemporaryExpandOutKeyRef] */
  { /*    90 */ CryIfConf_CryIfKey_CryIfKey_Tls_Hkdf_Sha384ExpandIn                          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_Sha384ExpandIn, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha384Expand:CsmJobKeyRef] */
  { /*    91 */ CryIfConf_CryIfKey_CryIfKey_Tls_Hkdf_Sha384ExpandOut                         },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_Sha384ExpandOut, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfTemporaryExpandOutKeyRef] */
  { /*    92 */ CryIfConf_CryIfKey_CryIfKey_Tls_Hkdf_TmpBuffer                               },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Hkdf_TmpBuffer, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfTemporaryKeyRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfTemporaryKeyRef] */
  { /*    93 */ CryIfConf_CryIfKey_CryIfKey_Tls_Root_A_EccSecp256r1Sha256_PubKey             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_Root_A_EccSecp256r1Sha256_PubKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Root_A_EccNistP256R1Sha256:CsmJobKeyRef] */
  { /*    94 */ CryIfConf_CryIfKey_CryIfKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey           },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_SubCa1_A_EccNistP256R1Sha256:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA1_Tmp:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    95 */ CryIfConf_CryIfKey_CryIfKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey           },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_SubCa2_A_EccNistP256R1Sha256:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA2_Tmp:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    96 */ CryIfConf_CryIfKey_CryIfKey_V2G_Root_1_PubKey                                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_V2G_Root_1_PubKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_1:CsmJobKeyRef, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_1:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    97 */ CryIfConf_CryIfKey_CryIfKey_V2G_Root_2_PubKey                                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_V2G_Root_2_PubKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_2:CsmJobKeyRef, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_2:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    98 */ CryIfConf_CryIfKey_CryIfKey_V2G_Root_3_PubKey                                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_V2G_Root_3_PubKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_3:CsmJobKeyRef, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_3:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    99 */ CryIfConf_CryIfKey_CryIfKey_V2G_Root_4_PubKey                                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_V2G_Root_4_PubKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_4:CsmJobKeyRef, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_4:KeyMCertCsmSignatureVerifyKeyRef] */
    /* Index    CryIfKeyId                                                                          Referable Keys */
  { /*   100 */ CryIfConf_CryIfKey_CryIfKey_V2G_Root_5_PubKey                                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_V2G_Root_5_PubKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_5:CsmJobKeyRef, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_5:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*   101 */ CryIfConf_CryIfKey_CryIfKey_V2G_Root_6_PubKey                                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_V2G_Root_6_PubKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_6:CsmJobKeyRef, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_6:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*   102 */ CryIfConf_CryIfKey_CryIfKey_V2G_Root_7_PubKey                                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_V2G_Root_7_PubKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_7:CsmJobKeyRef, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_7:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*   103 */ CryIfConf_CryIfKey_CryIfKey_V2G_Root_8_PubKey                                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_V2G_Root_8_PubKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_8:CsmJobKeyRef, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_8:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*   104 */ CryIfConf_CryIfKey_CryIfKey_V2G_Root_9_PubKey                                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_V2G_Root_9_PubKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_9:CsmJobKeyRef, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_9:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*   105 */ CryIfConf_CryIfKey_CryIfKey_V2G_Root_10_PubKey                               },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_V2G_Root_10_PubKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_10:CsmJobKeyRef, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_10:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*   106 */ CryIfConf_CryIfKey_CryIf_SccContractPrivKey                                  },  /* [/ActiveEcuC/Csm/CsmKeys/Csm_SccContractPrivKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_SccECDSASignatureGenerate:CsmJobKeyRef] */
  { /*   107 */ CryIfConf_CryIfKey_CryIf_SccPublicKey                                        },  /* [/ActiveEcuC/Csm/CsmKeys/Csm_SccPublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_SccECDSASignatureVerify:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SccSha256:CsmJobKeyRef] */
  { /*   108 */ CryIfConf_CryIfKey_CryIfKey_Scc_MOContract_X_PrivateKey                      },  /* [/ActiveEcuC/Csm/CsmKeys/Csm_Scc_MOContract_X_PrivateKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/KeyM/SccCryptoKey_ISO2_ContractCertificate_0:KeyMCryptoKeyCsmKeyTargetRef] */
  { /*   109 */ CryIfConf_CryIfKey_CryIfKey_Scc_MOContract_X_PublicKey                       },  /* [/ActiveEcuC/Csm/CsmKeys/Csm_Scc_MOContract_X_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOCOntract_X_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*   110 */ CryIfConf_CryIfKey_CryIfKey_Scc_MOSubCa1_X_PublicKey                         },  /* [/ActiveEcuC/Csm/CsmKeys/Csm_Scc_MOSubCa1_X_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOSubCa1_X_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA1_0:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*   111 */ CryIfConf_CryIfKey_CryIfKey_Scc_MOSubCa2_X_PublicKey                         },  /* [/ActiveEcuC/Csm/CsmKeys/Csm_Scc_MOSubCa2_X_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOSubCa2_X_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA2_0:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*   112 */ CryIfConf_CryIfKey_CryIfKey_Scc_OEMProvRoot                                  },  /* [/ActiveEcuC/Csm/CsmKeys/Csm_Scc_OEMProvRoot_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvRoot:CsmJobKeyRef] */
  { /*   113 */ CryIfConf_CryIfKey_CryIfKey_Scc_OEMProvSubCa1                                },  /* [/ActiveEcuC/Csm/CsmKeys/Csm_Scc_OEMProvSubCa1_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvSubCa1:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO2_OEMProvSubCa1:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*   114 */ CryIfConf_CryIfKey_CryIfKey_Scc_OEMProvSubCa2                                },  /* [/ActiveEcuC/Csm/CsmKeys/Csm_Scc_OEMProvSubCa2_PublicKEy, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvSubCa2:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO2_OEMProvSubCa2:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*   115 */ CryIfConf_CryIfKey_CryIfKey_Scc_OEMProv_X_PrivateKey                         },  /* [/ActiveEcuC/Csm/CsmKeys/Csm_Scc_OEMProv_X_PrivateKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/KeyM/SccCryptoKey_ISO2_OEMProvCertificate_0:KeyMCryptoKeyCsmKeyTargetRef] */
  { /*   116 */ CryIfConf_CryIfKey_CryIfKey_Scc_OEMProv_X_PublicKey                          },  /* [/ActiveEcuC/Csm/CsmKeys/Csm_Scc_OEMProv_X_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProv_X_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_OEMProvCertificate_0:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*   117 */ CryIfConf_CryIfKey_CryIfKey_Scc_ProvLeaf_X_PublicKey                         },  /* [/ActiveEcuC/Csm/CsmKeys/Csm_Scc_ProvLeaf_X_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvLeaf_X_Verify:CsmJobKeyRef] */
  { /*   118 */ CryIfConf_CryIfKey_CryIfKey_Scc_ProvSubCa1_X_PublicKey                       },  /* [/ActiveEcuC/Csm/CsmKeys/Csm_Scc_ProvSubCa1_X_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvSubCa1_X_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSLeaf_Tmp:KeyMCertCsmSignatureVerifyKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA1_Tmp:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*   119 */ CryIfConf_CryIfKey_CryIfKey_Scc_ProvSubCa2_X_PublicKey                       },  /* [/ActiveEcuC/Csm/CsmKeys/Csm_Scc_ProvSubCa2_X_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvSubCa2_X_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA2_Tmp:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*   120 */ CryIfConf_CryIfKey_CryIf_Scc_ResumeSessionInfo                               },  /* [/ActiveEcuC/Csm/CsmKeys/Csm_Scc_ResumeSessionInfo, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Scc/SccGeneral/SccGeneralCsmConfig:SccSessionKeyId] */
  { /*   121 */ CryIfConf_CryIfKey_CryIfKey_Scc_V2GRoot_X_PublicKey                          },  /* [/ActiveEcuC/Csm/CsmKeys/Csm_Scc_V2GRoot_X_PublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_V2GRoot_X_Verify:CsmJobKeyRef, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2GRoot_0:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*   122 */ CryIfConf_CryIfKey_CryIf_TlsSha1Key                                          }   /* [/ActiveEcuC/Csm/CsmKeys/Csm_TlsSha1Key, /ActiveEcuC/Csm/CsmKeys] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    Csm_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element         Description
  PartitionSNV
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_PartitionIdentifiersType, CSM_CONST) Csm_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV         */
  { /*     0 */ CSM_SINGLE_PARTITION }
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_PrimitiveInfo
**********************************************************************************************************************/
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo[36] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     PrimitiveInfo                                                                                                                               Referable Keys */
  /*     0 */ {CRYPTO_SIGNATUREGENERATE, {CRYPTO_ALGOFAM_ECCNIST, CRYPTO_ALGOFAM_SHA2_256, 32u, CRYPTO_ALGOMODE_CUSTOM_P256R1}}                      ,  /* [/ActiveEcuC/Csm/CsmPrimitiveEcdsaGen/CsmSignatureGenerate/CsmPrimitiveEcdsaGen] */
  /*     1 */ {CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_ECCNIST, CRYPTO_ALGOFAM_SHA2_256, 32u, CRYPTO_ALGOMODE_CUSTOM_P256R1}}                        ,  /* [/ActiveEcuC/Csm/CsmPrimitiveEcdsaVer/CsmSignatureVerify/CsmPrimitiveEcdsaVer, /ActiveEcuC/Csm/CsmPrimitives_Tls_CertVerify_EccNistP256R1Sha256/CsmSignatureVerify/CsmPrimitives_Tls_CertVerify_EccNistP256R1Sha256, /ActiveEcuC/Csm/CsmPrimitive_Scc_V2GRoot_X_EcdsaVerify/CsmSignatureVerify/CsmPrimitive_Scc_V2GRoot_X_EcdsaVerify] */
  /*     2 */ {CRYPTO_HASH, {CRYPTO_ALGOFAM_SHA2_256, CRYPTO_ALGOFAM_NOT_SET, 0u, CRYPTO_ALGOMODE_NOT_SET}}                                          ,  /* [/ActiveEcuC/Csm/CsmPrimitiveHash/CsmHash/CsmPrimitiveHash, /ActiveEcuC/Csm/CsmPrimitives_Tls_HashSha256/CsmHash/CsmPrimitives_Tls_HashSha256] */
  /*     3 */ {CRYPTO_DECRYPT, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, 16u, CRYPTO_ALGOMODE_CBC}}                                               ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Tls_Aes128Cbc_Decrypt/CsmDecrypt/CsmPrimitives_Tls_Aes128Cbc_Decrypt] */
  /*     4 */ {CRYPTO_ENCRYPT, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, 16u, CRYPTO_ALGOMODE_CBC}}                                               ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Tls_Aes128Cbc_Encrypt/CsmEncrypt/CsmPrimitives_Tls_Aes128Cbc_Encrypt] */
  /*     5 */ {CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_ECCNIST, CRYPTO_ALGOFAM_SHA1, 32u, CRYPTO_ALGOMODE_CUSTOM_P256R1}}                            ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Tls_CertVerify_EccNistP256R1Sha1/CsmSignatureVerify/CsmPrimitives_Tls_CertVerify_EccNistP256R1Sha1] */
  /*     6 */ {CRYPTO_HASH, {CRYPTO_ALGOFAM_SHA1, CRYPTO_ALGOFAM_NOT_SET, 0u, CRYPTO_ALGOMODE_NOT_SET}}                                              ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Tls_HashSha1/CsmHash/CsmPrimitives_Tls_HashSha1] */
  /*     7 */ {CRYPTO_MACGENERATE, {CRYPTO_ALGOFAM_SHA1, CRYPTO_ALGOFAM_NOT_SET, 16u, CRYPTO_ALGOMODE_HMAC}}                                         ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Tls_HMac_Sha1_Generate/CsmMacGenerate/CsmPrimitives_Tls_HMac_Sha1_Generate] */
  /*     8 */ {CRYPTO_MACVERIFY, {CRYPTO_ALGOFAM_SHA1, CRYPTO_ALGOFAM_NOT_SET, 16u, CRYPTO_ALGOMODE_HMAC}}                                           ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Tls_HMac_Sha1_Verify/CsmMacVerify/CsmPrimitives_Tls_HMac_Sha1_Verify] */
  /*     9 */ {CRYPTO_MACGENERATE, {CRYPTO_ALGOFAM_SHA2_256, CRYPTO_ALGOFAM_NOT_SET, 16u, CRYPTO_ALGOMODE_HMAC}}                                     ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Tls_HMac_Sha256_Generate/CsmMacGenerate/CsmPrimitives_Tls_HMac_Sha256_Generate] */
  /*    10 */ {CRYPTO_MACVERIFY, {CRYPTO_ALGOFAM_SHA2_256, CRYPTO_ALGOFAM_NOT_SET, 16u, CRYPTO_ALGOMODE_HMAC}}                                       ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Tls_HMac_Sha256_Verify/CsmMacVerify/CsmPrimitives_Tls_HMac_Sha256_Verify] */
  /*    11 */ {CRYPTO_RANDOMGENERATE, {CRYPTO_ALGOFAM_RNG, CRYPTO_ALGOFAM_NOT_SET, 0u, CRYPTO_ALGOMODE_NOT_SET}}                                     ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Tls_RandomNumber/CsmRandomGenerate/CsmPrimitives_Tls_RandomNumber] */
  /*    12 */ {CRYPTO_KEYEXCHANGECALCSECRET, {CRYPTO_ALGOFAM_ECCNIST, CRYPTO_ALGOFAM_NOT_SET, 0u, CRYPTO_ALGOMODE_CUSTOM_P256R1}}                    ,  /* [/ActiveEcuC/Csm/CsmPrimitivesExchangeCalcSecret/CsmJobKeyExchangeCalcSecret/CsmPrimitivesExchangeCalcSecret] */
  /*    13 */ {CRYPTO_SIGNATUREGENERATE, {CRYPTO_ALGOFAM_ECDSA, CRYPTO_ALGOFAM_NOT_SET, 32u, CRYPTO_ALGOMODE_NOT_SET}}                               ,  /* [/ActiveEcuC/Csm/CsmCertUpdSig/CsmSignatureGenerate/CsmCertUpdSig] */
  /*    14 */ {CRYPTO_DECRYPT, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, 16u, CRYPTO_ALGOMODE_NOT_SET}}                                           ,  /* [/ActiveEcuC/Csm/CsmDecAES128/CsmDecrypt/CsmDecAES128] */
  /*    15 */ {CRYPTO_KEYEXCHANGECALCSECRET, {CRYPTO_ALGOFAM_ECDH, CRYPTO_ALGOFAM_NOT_SET, 0u, CRYPTO_ALGOMODE_NOT_SET}}                             ,  /* [/ActiveEcuC/Csm/CsmECDHEx/CsmJobKeyExchangeCalcSecret/CsmECDHEx] */
  /*    16 */ {CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_CUSTOM_ECCSEC, CRYPTO_ALGOFAM_SHA2_256, 64u, CRYPTO_ALGOMODE_CUSTOM_P256R1}}                  ,  /* [/ActiveEcuC/Csm/CsmECDSAVerify/CsmSignatureVerify/CsmECDSAVerify] */
  /*    17 */ {CRYPTO_HASH, {CRYPTO_ALGOFAM_SHA2_512, CRYPTO_ALGOFAM_NOT_SET, 0u, CRYPTO_ALGOMODE_NOT_SET}}                                          ,  /* [/ActiveEcuC/Csm/CsmPrimitiveHash_SHA512/CsmHash512/CsmPrimitiveHash_SHA512, /ActiveEcuC/Csm/CsmPrimitives_Tls_HashSha512/CsmHash/CsmPrimitives_Tls_HashSha512] */
  /*    18 */ {CRYPTO_SIGNATUREGENERATE, {CRYPTO_ALGOFAM_CUSTOM_ECCSEC, CRYPTO_ALGOFAM_SHA2_256, 32u, CRYPTO_ALGOMODE_CUSTOM_P256R1}}                ,  /* [/ActiveEcuC/Csm/CsmPrimitivesTls_HsDhSignatureGenerate/CsmSignatureGenerate/CsmPrimitivesTls_HsDhSignatureGenerate, /ActiveEcuC/Csm/CsmPrimitives_Tls_Hs_DhSignatureGenerate/CsmSignatureGenerate_Tls_Hs_DhSignatureGenerate/CsmPrimitives_Tls_Hs_DhSignatureGenerate] */
  /*    19 */ {CRYPTO_SIGNATUREGENERATE, {CRYPTO_ALGOFAM_ECCSEC, CRYPTO_ALGOFAM_SHA2_512, 66u, CRYPTO_ALGOMODE_CUSTOM_P521R1}}                       ,  /* [/ActiveEcuC/Csm/CsmPrimitivesTls_HsDhSignatureGenerate_Secp521/CsmSignatureGenerate/CsmPrimitivesTls_HsDhSignatureGenerate_Secp521, /ActiveEcuC/Csm/CsmPrimitives_Scc_secp521r1_Generate/CsmSignatureGenerate/CsmPrimitives_Scc_secp521r1_Generate, /ActiveEcuC/Csm/CsmPrimitives_Scc_secp521r1_Generate_Async/CsmSignatureGenerate/CsmPrimitives_Scc_secp521r1_Generate_Async] */
  /*    20 */ {CRYPTO_KEYDERIVE, {139u, CRYPTO_ALGOFAM_SHA2_256, 0u, CRYPTO_ALGOMODE_HMAC} /*  Family = Crypto_30_LibCv_HKDF  */ }                   ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Hkdf_Sha256/CsmJobKeyDerive/CsmPrimitives_Hkdf_Sha256] */
  /*    21 */ {CRYPTO_KEYDERIVE, {197u, CRYPTO_ALGOFAM_SHA2_256, 0u, CRYPTO_ALGOMODE_HMAC} /*  Family = Crypto_30_LibCv_HKDF_Expand  */ }            ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Hkdf_Sha256Expand/CsmJobKeyDerive/CsmPrimitives_Hkdf_Sha256Expand] */
  /*    22 */ {CRYPTO_KEYDERIVE, {139u, CRYPTO_ALGOFAM_SHA2_384, 0u, CRYPTO_ALGOMODE_HMAC} /*  Family = Crypto_30_LibCv_HKDF  */ }                   ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Hkdf_Sha384/CsmJobKeyDerive/CsmPrimitives_Hkdf_Sha384] */
  /*    23 */ {CRYPTO_MACGENERATE, {CRYPTO_ALGOFAM_SHA2_256, CRYPTO_ALGOFAM_NOT_SET, 32u, CRYPTO_ALGOMODE_HMAC}}                                     ,  /* [/ActiveEcuC/Csm/CsmPrimitives_HmacSha256Generate/CsmMacGenerate/CsmPrimitives_HmacSha256Generate] */
  /*    24 */ {CRYPTO_MACGENERATE, {CRYPTO_ALGOFAM_SHA2_384, CRYPTO_ALGOFAM_NOT_SET, 16u, CRYPTO_ALGOMODE_HMAC}}                                     ,  /* [/ActiveEcuC/Csm/CsmPrimitives_HmacSha384Generate/CsmMacGenerate/CsmPrimitives_HmacSha384Generate] */
  /*    25 */ {CRYPTO_KEYDERIVE, {CRYPTO_ALGOFAM_CUSTOM_ISO15118, CRYPTO_ALGOFAM_NOT_SET, 0u, CRYPTO_ALGOMODE_NOT_SET}}                              ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Scc_KDF/CsmJobKeyDerive/CsmPrimitives_Scc_KDF] */
  /*    26 */ {CRYPTO_KEYDERIVE, {193u, CRYPTO_ALGOFAM_NOT_SET, 0u, CRYPTO_ALGOMODE_NOT_SET} /*  Family = Crypto_30_LibCv_ISO15118_20  */ }          ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Scc_KDF_ISO15118_20/CsmJobKeyDerive/CsmPrimitives_Scc_KDF_ISO15118_20] */
  /*    27 */ {CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_ECCSEC, CRYPTO_ALGOFAM_SHA2_512, 66u, CRYPTO_ALGOMODE_CUSTOM_P521R1}}                         ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Scc_secp521r1_Verify/CsmSignatureVerify/CsmPrimitives_Scc_secp521r1_Verify, /ActiveEcuC/Csm/CsmPrimitives_Scc_secp521r1_Verify_Async/CsmSignatureVerify/CsmPrimitives_Scc_secp521r1_Verify_Async, /ActiveEcuC/Csm/CsmPrimitives_Tls_CertVerify_EccNistP521R1Sha512/CsmSignatureVerify/CsmPrimitives_Tls_CertVerify_EccNistP521R1Sha512] */
  /*    28 */ {CRYPTO_AEADDECRYPT, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, 32u, CRYPTO_ALGOMODE_GCM}}                                           ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Tls_Aes256Gcm_Decrypt/CsmAEADDecrypt/CsmPrimitives_Tls_Aes256Gcm_Decrypt] */
  /*    29 */ {CRYPTO_AEADENCRYPT, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, 32u, CRYPTO_ALGOMODE_GCM}}                                           ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Tls_Aes256Gcm_Encrypt/CsmAEADEncrypt/CsmPrimitives_Tls_Aes256Gcm_Encrypt] */
  /*    30 */ {CRYPTO_AEADDECRYPT, {CRYPTO_ALGOFAM_CHACHA, 137u, 16u, CRYPTO_ALGOMODE_20ROUNDS} /*  SecondaryFamily = Crypto_30_LibCv_POLY1305  */ } ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Tls_ChaCha20_Decrypt/CsmAEADDecrypt/CsmPrimitives_Tls_ChaCha20_Decrypt] */
  /*    31 */ {CRYPTO_AEADENCRYPT, {CRYPTO_ALGOFAM_CHACHA, 137u, 16u, CRYPTO_ALGOMODE_20ROUNDS} /*  SecondaryFamily = Crypto_30_LibCv_POLY1305  */ } ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Tls_ChaCha20_Encrypt/CsmAEADEncrypt/CsmPrimitives_Tls_ChaCha20_Encrypt] */
  /*    32 */ {CRYPTO_HASH, {CRYPTO_ALGOFAM_SHA2_384, CRYPTO_ALGOFAM_NOT_SET, 0u, CRYPTO_ALGOMODE_NOT_SET}}                                          ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Tls_HashSha384/CsmHash/CsmPrimitives_Tls_HashSha384] */
  /*    33 */ {CRYPTO_KEYDERIVE, {197u, CRYPTO_ALGOFAM_SHA2_384, 0u, CRYPTO_ALGOMODE_HMAC} /*  Family = Crypto_30_LibCv_HKDF_Expand  */ }            ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Tls_HashSha384Expand/CsmJobKeyDerive/CsmPrimitives_Tls_HashSha384Expand] */
  /*    34 */ {CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_CUSTOM_ECCSEC, CRYPTO_ALGOFAM_SHA2_256, 32u, CRYPTO_ALGOMODE_CUSTOM_P256R1}}                  ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Tls_Hs_DhSignatureVerify/CsmSignatureVerify/CsmPrimitives_Tls_Hs_DhSignatureVerify] */
  /*    35 */ {CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_ECCSEC, CRYPTO_ALGOFAM_SHA2_512, 64u, CRYPTO_ALGOMODE_CUSTOM_P521R1}}                            /* [/ActiveEcuC/Csm/CsmPrimitives_Tls_Hs_DhSignatureVerify_Secp521/CsmSignatureVerify/CsmPrimitives_Tls_Hs_DhSignatureVerify_Secp521] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_QueueInfo
**********************************************************************************************************************/
/** 
  \var    Csm_QueueInfo
  \brief  Contains parameters of /AUTOSAR/EcucDefs/Csm/CsmQueues/CsmQueue.
  \details
  Element                 Description
  ChannelId               Contains values of DefinitionRef: /MICROSAR/Csm/CsmQueues/CsmQueue/CsmChannelRef.
  JobObjSynchronousIdx    the index of the 0:1 relation pointing to Csm_Job
  JobPoolEndIdx           the end index of the 0:n relation pointing to one of Csm_Job
  JobPoolPartitionIdx 
  JobPoolStartIdx         the start index of the 0:n relation pointing to one of Csm_Job
  MaskedBits              contains bitcoded the boolean data of Csm_JobSharingOfQueueInfo, Csm_TriggerAsynchJobsInCallbackOfQueueInfo
  QueueEndIdx             the end index of the 1:n relation pointing to Csm_Queue
  QueueStartIdx           the start index of the 1:n relation pointing to Csm_Queue
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_QueueInfoType, CSM_CONST) Csm_QueueInfo[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ChannelId                                                             JobObjSynchronousIdx  JobPoolEndIdx  JobPoolPartitionIdx                              JobPoolStartIdx  MaskedBits  QueueEndIdx  QueueStartIdx        Referable Keys */
  { /*     0 */ CryIfConf_CryIfChannel_CryIfChannel_Crypto_Lib_SCC                  ,                   0u,            3u,                  0u  /* CSM_SINGLE_PARTITION */,              1u,      0x02u,          2u,            0u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_HmacSha256Generate_1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SccECDSASignatureGenerate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SccECDSASignatureVerify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SccSha256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SccSha512:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_secp521r1_SignatureGenerate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_KDF:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MORoot_X_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvRoot:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvSubCa1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvSubCa2:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_HmacSha384Generate_1:CsmJobQueueRef] */
  { /*     1 */ CryIfConf_CryIfChannel_CryIfChannel                                 ,                   5u,            7u,                  0u  /* CSM_SINGLE_PARTITION */,              5u,      0x02u,          6u,            4u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueueECDSAVerify, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_10:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_2:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_3:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_4:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_5:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_6:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_7:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_8:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_9:CsmJobQueueRef] */
  { /*     2 */ CryIfConf_CryIfChannel_CryIfChannel_Crypto_Lib_SCC                  ,                   7u,            8u,                  0u  /* CSM_SINGLE_PARTITION */,              7u,      0x02u,          7u,            6u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Hkdf_Sha256, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha256Expand:CsmJobQueueRef] */
  { /*     3 */ CryIfConf_CryIfChannel_CryIfChannel_Tls_Hkdf_Sha384                 ,                   8u,            9u,                  0u  /* CSM_SINGLE_PARTITION */,              8u,      0x02u,          8u,            7u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Hkdf_Sha384, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha384:CsmJobQueueRef] */
  { /*     4 */ CryIfConf_CryIfChannel_CryIfChannel_Crypto_Lib_SCC                  ,                   9u,           10u,                  0u  /* CSM_SINGLE_PARTITION */,              9u,      0x02u,          9u,            8u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_SCC_1_LibCv, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_KDF_ISO15118_20:CsmJobQueueRef] */
  { /*     5 */ CryIfConf_CryIfChannel_CryIfChannel_Tls_Conn0                       ,                   3u,            4u,                  0u  /* CSM_SINGLE_PARTITION */,              3u,      0x02u,          3u,            2u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Conn0, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Aes128Cbc_Decrypt:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Aes128Cbc_Encrypt:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_CertVerify_EccNistP256R1Sha1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_CertVerify_EccNistP256R1Sha256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha1_Generate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha1_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha256_Generate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha256_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_RandomNumber:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Prf_HMacGenerate_Private:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Prf_HMacGenerate_Public:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn0_HS_DhSignatureGenerate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn0_HS_DhSignatureVerify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_CertVerify_Leaf_Server_A_EccNistP256R1Sha256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_DhSignatureGenerate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_DhSignatureVerify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Root_A_EccNistP256R1Sha256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_SubCa1_A_EccNistP256R1Sha256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_SubCa2_A_EccNistP256R1Sha256:CsmJobQueueRef] */
  { /*     6 */ CryIfConf_CryIfChannel_CryIfChannel_Tls_Conn0_HS_HashSha256_Finished,                  10u,           11u,                  0u  /* CSM_SINGLE_PARTITION */,             10u,      0x02u,         10u,            9u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Conn0_HS_HashSha256_Finished, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HashSha256_Finished:CsmJobQueueRef] */
  { /*     7 */ CryIfConf_CryIfChannel_CryIfChannel_Tls_Conn1                       ,                  11u,           12u,                  0u  /* CSM_SINGLE_PARTITION */,             11u,      0x02u,         11u,           10u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Conn1, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn1_HS_DhSignatureGenerate_Secp521r1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Aes256Gcm_Decrypt_1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Aes256Gcm_Encrypt_1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_ChaCha20_Decrypt:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_ChaCha20_Encrypt:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Prf_HMacGenerate_Private:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Prf_HMacGenerate_Public:CsmJobQueueRef] */
  { /*     8 */ CryIfConf_CryIfChannel_CryIfChannel_Tls_Conn1_HS_HashSha256_Finished,                  12u,           13u,                  0u  /* CSM_SINGLE_PARTITION */,             12u,      0x02u,         12u,           11u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Conn1_HS_HashSha256_Finished, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha256_Finished:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha384_Finished:CsmJobQueueRef] */
  { /*     9 */ CryIfConf_CryIfChannel_CryIfChannel_Tls_Conn1_HS_HashSha384         ,                  13u,           14u,                  0u  /* CSM_SINGLE_PARTITION */,             13u,      0x02u,         13u,           12u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Conn1_HS_HashSha384, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha384:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha384Expand:CsmJobQueueRef] */
  { /*    10 */ CryIfConf_CryIfChannel_CryIfChannel_Tls_Global_HashSha1             ,                   4u,            5u,                  0u  /* CSM_SINGLE_PARTITION */,              4u,      0x03u,          4u,            3u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Global_HashSha1, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Global_HashSha1:CsmJobQueueRef] */
  { /*    11 */ CryIfConf_CryIfChannel_CryIfChannel_Crypto_Lib_SCC                  ,                  14u,           17u,                  0u  /* CSM_SINGLE_PARTITION */,             15u,      0x02u,         15u,           13u }   /* [/ActiveEcuC/Csm/CsmQueues/Scc_KeyM_Queue, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOLeaf_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOSubCA1_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOSubCA2_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSLeaf_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSSubCA1_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSSubCA2_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPLeaf_0_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPLeaf_1_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa1_1_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa2_0_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa2_1_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvLeaf_0_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvLeaf_1_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa1_1_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa2_0_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa2_1_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_V2GRoot_0_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_V2GRoot_1_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleLeaf_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleSubCA1_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleSubCA2_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_secp521r1_SignatureVerify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOCOntract_X_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOSubCa1_X_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOSubCa2_X_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProv_X_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvLeaf_X_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvSubCa1_X_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvSubCa2_X_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_V2GRoot_X_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_V2GRoot_Y_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn1_HS_DhSignatureVerify_Secp521r1:CsmJobQueueRef] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_InOutRedirection
**********************************************************************************************************************/
/** 
  \var    Csm_InOutRedirection
  \brief  Buffer for storing In-Out Redirection used for Jobs.
*/ 
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_InOutRedirectionUType, CSM_VAR_NOINIT) Csm_InOutRedirection;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Prf_HMacGenerate_Private] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Prf_HMacGenerate_Public] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Prf_HMacGenerate_Private] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Prf_HMacGenerate_Public] */

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Job
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_JobType, CSM_VAR_NOINIT) Csm_Job[17];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [CsmQueue_SyncObj] */
  /*     1 */  /* [CsmQueue_AsyncPool] */
  /*     2 */  /* [CsmQueue_AsyncPool] */
  /*     3 */  /* [CsmQueue_Tls_Conn0_AsyncPool, CsmQueue_Tls_Conn0_SyncObj] */
  /*     4 */  /* [CsmQueue_Tls_Global_HashSha1_AsyncPool, CsmQueue_Tls_Global_HashSha1_SyncObj] */
  /*     5 */  /* [CsmQueueECDSAVerify_AsyncPool, CsmQueueECDSAVerify_SyncObj] */
  /*     6 */  /* [CsmQueueECDSAVerify_AsyncPool] */
  /*     7 */  /* [CsmQueue_Hkdf_Sha256_AsyncPool, CsmQueue_Hkdf_Sha256_SyncObj] */
  /*     8 */  /* [CsmQueue_Hkdf_Sha384_AsyncPool, CsmQueue_Hkdf_Sha384_SyncObj] */
  /*     9 */  /* [CsmQueue_SCC_1_LibCv_AsyncPool, CsmQueue_SCC_1_LibCv_SyncObj] */
  /*    10 */  /* [CsmQueue_Tls_Conn0_HS_HashSha256_Finished_AsyncPool, CsmQueue_Tls_Conn0_HS_HashSha256_Finished_SyncObj] */
  /*    11 */  /* [CsmQueue_Tls_Conn1_AsyncPool, CsmQueue_Tls_Conn1_SyncObj] */
  /*    12 */  /* [CsmQueue_Tls_Conn1_HS_HashSha256_Finished_AsyncPool, CsmQueue_Tls_Conn1_HS_HashSha256_Finished_SyncObj] */
  /*    13 */  /* [CsmQueue_Tls_Conn1_HS_HashSha384_AsyncPool, CsmQueue_Tls_Conn1_HS_HashSha384_SyncObj] */
  /*    14 */  /* [Scc_KeyM_Queue_SyncObj] */
  /*    15 */  /* [Scc_KeyM_Queue_AsyncPool] */
  /*    16 */  /* [Scc_KeyM_Queue_AsyncPool] */

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobState
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_JobStateType, CSM_VAR_NOINIT) Csm_JobState[90];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_HmacSha256Generate_1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_CHACHA20_POLY1305_SHA256_Secp521r1:TcpIpTlsCipherCsmMacGenerateJobRef] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SccECDSASignatureGenerate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_2Config/SccISO2CsmConfig:SccECDSAGenSignJobId] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SccECDSASignatureVerify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_2Config/SccISO2CsmConfig:SccECDSAVerifyJobId] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SccSha256, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_2Config/SccISO2CsmConfig:SccSHA256JobId] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SccSha512, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_20Config/SccISO20CsmConfig/SccCommonCsmConfig:SccSHA512JobId] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOLeaf_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOSubCA1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  /*     7 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOSubCA2_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  /*     8 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSLeaf_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  /*     9 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSSubCA1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  /*    10 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSSubCA2_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  /*    11 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPLeaf_0_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  /*    12 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPLeaf_1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs] */
  /*    13 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa1_1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  /*    14 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa2_0_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  /*    15 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa2_1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs] */
  /*    16 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvLeaf_0_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_OEMProvCertificate_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    17 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvLeaf_1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs] */
  /*    18 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa1_1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_OEMProvSubCA1_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    19 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa2_0_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_OEMProvSubCA2_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    20 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa2_1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs] */
  /*    21 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_V2GRoot_0_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    22 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_V2GRoot_1_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_1:KeyMCertCsmSignatureVerifyJobRef] */
  /*    23 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleLeaf_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_VehicleCert_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    24 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleSubCA1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_VehicleSubCA1_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    25 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleSubCA2_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_VehicleSubCA2_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    26 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_secp521r1_SignatureGenerate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_20Config/SccISO20CsmConfig/SccSecp521r1Config:SccSignatureGenerationJobId] */
  /*    27 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_secp521r1_SignatureVerify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_20Config/SccISO20CsmConfig/SccSecp521r1Config:SccSignatureVerifyJobId] */
  /*    28 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_KDF, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_2Config/SccISO2CsmConfig:SccKeyDeriveFuncJobId] */
  /*    29 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_KDF_ISO15118_20, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_20Config/SccISO20CsmConfig/SccSecp521r1Config:SccKeyDeriveFuncJobId] */
  /*    30 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOCOntract_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    31 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MORoot_X_Verify, /ActiveEcuC/Csm/CsmJobs] */
  /*    32 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOSubCa1_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA1_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    33 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOSubCa2_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA2_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    34 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvRoot, /ActiveEcuC/Csm/CsmJobs] */
  /*    35 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvSubCa1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_OEMProvSubCa1:KeyMCertCsmSignatureVerifyJobRef] */
  /*    36 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvSubCa2, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_OEMProvSubCa2:KeyMCertCsmSignatureVerifyJobRef] */
  /*    37 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProv_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_OEMProvCertificate_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    38 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvLeaf_X_Verify, /ActiveEcuC/Csm/CsmJobs] */
  /*    39 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvSubCa1_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSLeaf_Tmp:KeyMCertCsmSignatureVerifyJobRef, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA1_Tmp:KeyMCertCsmSignatureVerifyJobRef] */
  /*    40 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvSubCa2_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA2_Tmp:KeyMCertCsmSignatureVerifyJobRef] */
  /*    41 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_V2GRoot_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2GRoot_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    42 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_V2GRoot_Y_Verify, /ActiveEcuC/Csm/CsmJobs] */
  /*    43 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_1:KeyMCertCsmSignatureVerifyJobRef] */
  /*    44 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_2, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_2:KeyMCertCsmSignatureVerifyJobRef] */
  /*    45 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_3, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_3:KeyMCertCsmSignatureVerifyJobRef] */
  /*    46 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_4, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_4:KeyMCertCsmSignatureVerifyJobRef] */
  /*    47 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_5, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_5:KeyMCertCsmSignatureVerifyJobRef] */
  /*    48 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_6, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_6:KeyMCertCsmSignatureVerifyJobRef] */
  /*    49 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_7, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_7:KeyMCertCsmSignatureVerifyJobRef] */
  /* Index        Referable Keys */
  /*    50 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_8, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_8:KeyMCertCsmSignatureVerifyJobRef] */
  /*    51 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_9, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_9:KeyMCertCsmSignatureVerifyJobRef] */
  /*    52 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_10, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_10:KeyMCertCsmSignatureVerifyJobRef] */
  /*    53 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn0_HS_DhSignatureGenerate, /ActiveEcuC/Csm/CsmJobs] */
  /*    54 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn0_HS_DhSignatureVerify, /ActiveEcuC/Csm/CsmJobs] */
  /*    55 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn1_HS_DhSignatureGenerate_Secp521r1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1:TcpIpTlsCsmKeyExchangeSignatureGenerateJobRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1:TcpIpTlsCsmKeyExchangeSignatureGenerateJobRef] */
  /*    56 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn1_HS_DhSignatureVerify_Secp521r1, /ActiveEcuC/Csm/CsmJobs] */
  /*    57 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_CertVerify_Leaf_Server_A_EccNistP256R1Sha256, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOLeaf_Tmp:KeyMCertCsmSignatureVerifyJobRef] */
  /*    58 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Aes128Cbc_Decrypt, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256:TcpIpTlsCipherCsmDecryptJobRef] */
  /*    59 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Aes128Cbc_Encrypt, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256:TcpIpTlsCipherCsmEncryptJobRef] */
  /*    60 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_CertVerify_EccNistP256R1Sha1, /ActiveEcuC/Csm/CsmJobs] */
  /*    61 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_CertVerify_EccNistP256R1Sha256, /ActiveEcuC/Csm/CsmJobs] */
  /*    62 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha1_Generate, /ActiveEcuC/Csm/CsmJobs] */
  /*    63 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha1_Verify, /ActiveEcuC/Csm/CsmJobs] */
  /*    64 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha256_Generate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256:TcpIpTlsCipherCsmMacGenerateJobRef] */
  /*    65 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha256_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256:TcpIpTlsCipherCsmMacVerifyJobRef] */
  /*    66 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_DhSignatureGenerate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1:TcpIpTlsCsmKeyExchangeSignatureGenerateJobRef] */
  /*    67 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_DhSignatureVerify, /ActiveEcuC/Csm/CsmJobs] */
  /*    68 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_RandomNumber, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig:TcpIpTlsCsmRandomGenerateJobRef] */
  /*    69 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HashSha256_Finished, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1:TcpIpTlsCsmHashVerifyJobRef] */
  /*    70 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Prf_HMacGenerate_Private, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1:TcpIpTlsCsmPrfMacJobRef] */
  /*    71 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Prf_HMacGenerate_Public, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1:TcpIpTlsCsmPrfMacGeneratePublicJobRef] */
  /*    72 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Aes256Gcm_Decrypt_1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_WITH_AES_256_GCM_SHA384_Secp521r1:TcpIpTlsCipherCsmDecryptJobRef] */
  /*    73 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Aes256Gcm_Encrypt_1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_WITH_AES_256_GCM_SHA384_Secp521r1:TcpIpTlsCipherCsmEncryptJobRef] */
  /*    74 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_ChaCha20_Decrypt, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_CHACHA20_POLY1305_SHA256_Secp521r1:TcpIpTlsCipherCsmDecryptJobRef] */
  /*    75 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_ChaCha20_Encrypt, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_CHACHA20_POLY1305_SHA256_Secp521r1:TcpIpTlsCipherCsmEncryptJobRef] */
  /*    76 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha256_Finished, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1:TcpIpTlsCsmHashVerifyJobRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfHashMessagesJobRef] */
  /*    77 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha384, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfHashMessagesJobRef] */
  /*    78 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha384_Finished, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1:TcpIpTlsCsmHashVerifyJobRef] */
  /*    79 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Prf_HMacGenerate_Private, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1:TcpIpTlsCsmPrfMacJobRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1:TcpIpTlsCsmPrfMacJobRef] */
  /*    80 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Prf_HMacGenerate_Public, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1:TcpIpTlsCsmPrfMacGeneratePublicJobRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1:TcpIpTlsCsmPrfMacGeneratePublicJobRef] */
  /*    81 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Global_HashSha1, /ActiveEcuC/Csm/CsmJobs] */
  /*    82 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha256, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfJobRef] */
  /*    83 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha256Expand, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfExpandJobRef] */
  /*    84 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha384, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfJobRef] */
  /*    85 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha384Expand, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfExpandJobRef] */
  /*    86 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_HmacSha384Generate_1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_WITH_AES_256_GCM_SHA384_Secp521r1:TcpIpTlsCipherCsmMacGenerateJobRef] */
  /*    87 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Root_A_EccNistP256R1Sha256, /ActiveEcuC/Csm/CsmJobs] */
  /*    88 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_SubCa1_A_EccNistP256R1Sha256, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA1_Tmp:KeyMCertCsmSignatureVerifyJobRef] */
  /*    89 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_SubCa2_A_EccNistP256R1Sha256, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA2_Tmp:KeyMCertCsmSignatureVerifyJobRef] */

#define CSM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobToObjMap
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_SizeOfJobType, CSM_VAR_NOINIT) Csm_JobToObjMap[90];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_HmacSha256Generate_1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_CHACHA20_POLY1305_SHA256_Secp521r1:TcpIpTlsCipherCsmMacGenerateJobRef] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SccECDSASignatureGenerate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_2Config/SccISO2CsmConfig:SccECDSAGenSignJobId] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SccECDSASignatureVerify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_2Config/SccISO2CsmConfig:SccECDSAVerifyJobId] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SccSha256, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_2Config/SccISO2CsmConfig:SccSHA256JobId] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SccSha512, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_20Config/SccISO20CsmConfig/SccCommonCsmConfig:SccSHA512JobId] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOLeaf_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOSubCA1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  /*     7 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOSubCA2_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  /*     8 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSLeaf_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  /*     9 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSSubCA1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  /*    10 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSSubCA2_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  /*    11 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPLeaf_0_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  /*    12 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPLeaf_1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs] */
  /*    13 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa1_1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  /*    14 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa2_0_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA:KeyMCertCsmSignatureVerifyJobRef] */
  /*    15 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa2_1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs] */
  /*    16 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvLeaf_0_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_OEMProvCertificate_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    17 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvLeaf_1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs] */
  /*    18 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa1_1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_OEMProvSubCA1_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    19 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa2_0_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_OEMProvSubCA2_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    20 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa2_1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs] */
  /*    21 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_V2GRoot_0_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    22 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_V2GRoot_1_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_1:KeyMCertCsmSignatureVerifyJobRef] */
  /*    23 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleLeaf_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_VehicleCert_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    24 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleSubCA1_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_VehicleSubCA1_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    25 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleSubCA2_ECDSA_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO20_VehicleSubCA2_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    26 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_secp521r1_SignatureGenerate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_20Config/SccISO20CsmConfig/SccSecp521r1Config:SccSignatureGenerationJobId] */
  /*    27 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_secp521r1_SignatureVerify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_20Config/SccISO20CsmConfig/SccSecp521r1Config:SccSignatureVerifyJobId] */
  /*    28 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_KDF, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_2Config/SccISO2CsmConfig:SccKeyDeriveFuncJobId] */
  /*    29 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_KDF_ISO15118_20, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Scc/SccCertConfig/SccISO15118_20Config/SccISO20CsmConfig/SccSecp521r1Config:SccKeyDeriveFuncJobId] */
  /*    30 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOCOntract_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    31 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MORoot_X_Verify, /ActiveEcuC/Csm/CsmJobs] */
  /*    32 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOSubCa1_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA1_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    33 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOSubCa2_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA2_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    34 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvRoot, /ActiveEcuC/Csm/CsmJobs] */
  /*    35 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvSubCa1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_OEMProvSubCa1:KeyMCertCsmSignatureVerifyJobRef] */
  /*    36 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvSubCa2, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_OEMProvSubCa2:KeyMCertCsmSignatureVerifyJobRef] */
  /*    37 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProv_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_OEMProvCertificate_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    38 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvLeaf_X_Verify, /ActiveEcuC/Csm/CsmJobs] */
  /*    39 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvSubCa1_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSLeaf_Tmp:KeyMCertCsmSignatureVerifyJobRef, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA1_Tmp:KeyMCertCsmSignatureVerifyJobRef] */
  /*    40 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvSubCa2_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA2_Tmp:KeyMCertCsmSignatureVerifyJobRef] */
  /*    41 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_V2GRoot_X_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2GRoot_0:KeyMCertCsmSignatureVerifyJobRef] */
  /*    42 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_V2GRoot_Y_Verify, /ActiveEcuC/Csm/CsmJobs] */
  /*    43 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_1:KeyMCertCsmSignatureVerifyJobRef] */
  /*    44 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_2, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_2:KeyMCertCsmSignatureVerifyJobRef] */
  /*    45 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_3, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_3:KeyMCertCsmSignatureVerifyJobRef] */
  /*    46 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_4, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_4:KeyMCertCsmSignatureVerifyJobRef] */
  /*    47 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_5, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_5:KeyMCertCsmSignatureVerifyJobRef] */
  /*    48 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_6, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_6:KeyMCertCsmSignatureVerifyJobRef] */
  /*    49 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_7, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_7:KeyMCertCsmSignatureVerifyJobRef] */
  /* Index        Referable Keys */
  /*    50 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_8, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_8:KeyMCertCsmSignatureVerifyJobRef] */
  /*    51 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_9, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_9:KeyMCertCsmSignatureVerifyJobRef] */
  /*    52 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_10, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2G_Root_10:KeyMCertCsmSignatureVerifyJobRef] */
  /*    53 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn0_HS_DhSignatureGenerate, /ActiveEcuC/Csm/CsmJobs] */
  /*    54 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn0_HS_DhSignatureVerify, /ActiveEcuC/Csm/CsmJobs] */
  /*    55 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn1_HS_DhSignatureGenerate_Secp521r1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1:TcpIpTlsCsmKeyExchangeSignatureGenerateJobRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1:TcpIpTlsCsmKeyExchangeSignatureGenerateJobRef] */
  /*    56 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn1_HS_DhSignatureVerify_Secp521r1, /ActiveEcuC/Csm/CsmJobs] */
  /*    57 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_CertVerify_Leaf_Server_A_EccNistP256R1Sha256, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOLeaf_Tmp:KeyMCertCsmSignatureVerifyJobRef] */
  /*    58 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Aes128Cbc_Decrypt, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256:TcpIpTlsCipherCsmDecryptJobRef] */
  /*    59 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Aes128Cbc_Encrypt, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256:TcpIpTlsCipherCsmEncryptJobRef] */
  /*    60 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_CertVerify_EccNistP256R1Sha1, /ActiveEcuC/Csm/CsmJobs] */
  /*    61 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_CertVerify_EccNistP256R1Sha256, /ActiveEcuC/Csm/CsmJobs] */
  /*    62 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha1_Generate, /ActiveEcuC/Csm/CsmJobs] */
  /*    63 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha1_Verify, /ActiveEcuC/Csm/CsmJobs] */
  /*    64 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha256_Generate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256:TcpIpTlsCipherCsmMacGenerateJobRef] */
  /*    65 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha256_Verify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256:TcpIpTlsCipherCsmMacVerifyJobRef] */
  /*    66 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_DhSignatureGenerate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1:TcpIpTlsCsmKeyExchangeSignatureGenerateJobRef] */
  /*    67 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_DhSignatureVerify, /ActiveEcuC/Csm/CsmJobs] */
  /*    68 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_RandomNumber, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig:TcpIpTlsCsmRandomGenerateJobRef] */
  /*    69 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HashSha256_Finished, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1:TcpIpTlsCsmHashVerifyJobRef] */
  /*    70 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Prf_HMacGenerate_Private, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1:TcpIpTlsCsmPrfMacJobRef] */
  /*    71 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Prf_HMacGenerate_Public, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TlsHs1_ECDHE_ECDSA_Curve_Secp256r1:TcpIpTlsCsmPrfMacGeneratePublicJobRef] */
  /*    72 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Aes256Gcm_Decrypt_1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_WITH_AES_256_GCM_SHA384_Secp521r1:TcpIpTlsCipherCsmDecryptJobRef] */
  /*    73 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Aes256Gcm_Encrypt_1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_WITH_AES_256_GCM_SHA384_Secp521r1:TcpIpTlsCipherCsmEncryptJobRef] */
  /*    74 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_ChaCha20_Decrypt, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_CHACHA20_POLY1305_SHA256_Secp521r1:TcpIpTlsCipherCsmDecryptJobRef] */
  /*    75 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_ChaCha20_Encrypt, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_CHACHA20_POLY1305_SHA256_Secp521r1:TcpIpTlsCipherCsmEncryptJobRef] */
  /*    76 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha256_Finished, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1:TcpIpTlsCsmHashVerifyJobRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfHashMessagesJobRef] */
  /*    77 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha384, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfHashMessagesJobRef] */
  /*    78 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha384_Finished, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1:TcpIpTlsCsmHashVerifyJobRef] */
  /*    79 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Prf_HMacGenerate_Private, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1:TcpIpTlsCsmPrfMacJobRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1:TcpIpTlsCsmPrfMacJobRef] */
  /*    80 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Prf_HMacGenerate_Public, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1:TcpIpTlsCsmPrfMacGeneratePublicJobRef, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1:TcpIpTlsCsmPrfMacGeneratePublicJobRef] */
  /*    81 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Global_HashSha1, /ActiveEcuC/Csm/CsmJobs] */
  /*    82 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha256, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfJobRef] */
  /*    83 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha256Expand, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_CHACHA20_SHA256_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfExpandJobRef] */
  /*    84 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha384, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfJobRef] */
  /*    85 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha384Expand, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/TcpIpTlsHandshake_Tls13_AES_256_SHA384_Secp521r1/TcpIpTls13Config:TcpIpTlsCsmHkdfExpandJobRef] */
  /*    86 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_HmacSha384Generate_1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/TcpIp/TcpIpConfig/TcpIpTlsConfig/TcpIpTlsCiphersuites/C_TlsCw1_TLS_WITH_AES_256_GCM_SHA384_Secp521r1:TcpIpTlsCipherCsmMacGenerateJobRef] */
  /*    87 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Root_A_EccNistP256R1Sha256, /ActiveEcuC/Csm/CsmJobs] */
  /*    88 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_SubCa1_A_EccNistP256R1Sha256, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA1_Tmp:KeyMCertCsmSignatureVerifyJobRef] */
  /*    89 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_SubCa2_A_EccNistP256R1Sha256, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA2_Tmp:KeyMCertCsmSignatureVerifyJobRef] */

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_PartitionDataInitialized
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_PartitionDataInitializedType, CSM_VAR_ZERO_INIT) Csm_PartitionDataInitialized = 0u;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CSM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Queue
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_QueueUType, CSM_VAR_NOINIT) Csm_Queue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Conn0] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Global_HashSha1] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueueECDSAVerify] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueueECDSAVerify] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Hkdf_Sha256] */
  /*     7 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Hkdf_Sha384] */
  /*     8 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_SCC_1_LibCv] */
  /*     9 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Conn0_HS_HashSha256_Finished] */
  /*    10 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Conn1] */
  /*    11 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Conn1_HS_HashSha256_Finished] */
  /*    12 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Conn1_HS_HashSha384] */
  /*    13 */  /* [/ActiveEcuC/Csm/CsmQueues/Scc_KeyM_Queue] */
  /*    14 */  /* [/ActiveEcuC/Csm/CsmQueues/Scc_KeyM_Queue] */

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_QueueState
**********************************************************************************************************************/
/** 
  \var    Csm_QueueState
  \brief  Stores state of the asynchronous job queue.
  \details
  Element         Description
  Lock        
  QueueIdx        the index of the 1:1 relation pointing to Csm_Queue
  Retriggering
*/ 
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_QueueStateType, CSM_VAR_NOINIT) Csm_QueueState[12];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_HmacSha256Generate_1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SccECDSASignatureGenerate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SccECDSASignatureVerify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SccSha256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SccSha512:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_secp521r1_SignatureGenerate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_KDF:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MORoot_X_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvRoot:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvSubCa1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProvSubCa2:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_HmacSha384Generate_1:CsmJobQueueRef] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueueECDSAVerify, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_10:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_2:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_3:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_4:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_5:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_6:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_7:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_8:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigVerify_Cert_V2G_Root_9:CsmJobQueueRef] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Hkdf_Sha256, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha256Expand:CsmJobQueueRef] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Hkdf_Sha384, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha384:CsmJobQueueRef] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_SCC_1_LibCv, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_KDF_ISO15118_20:CsmJobQueueRef] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Conn0, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Aes128Cbc_Decrypt:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Aes128Cbc_Encrypt:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_CertVerify_EccNistP256R1Sha1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_CertVerify_EccNistP256R1Sha256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha1_Generate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha1_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha256_Generate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HMacSha256_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_RandomNumber:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Prf_HMacGenerate_Private:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_Prf_HMacGenerate_Public:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn0_HS_DhSignatureGenerate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn0_HS_DhSignatureVerify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_CertVerify_Leaf_Server_A_EccNistP256R1Sha256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_DhSignatureGenerate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HS_DhSignatureVerify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Root_A_EccNistP256R1Sha256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_SubCa1_A_EccNistP256R1Sha256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_SubCa2_A_EccNistP256R1Sha256:CsmJobQueueRef] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Conn0_HS_HashSha256_Finished, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn0_HashSha256_Finished:CsmJobQueueRef] */
  /*     7 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Conn1, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn1_HS_DhSignatureGenerate_Secp521r1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Aes256Gcm_Decrypt_1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Aes256Gcm_Encrypt_1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_ChaCha20_Decrypt:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_ChaCha20_Encrypt:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Prf_HMacGenerate_Private:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_Prf_HMacGenerate_Public:CsmJobQueueRef] */
  /*     8 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Conn1_HS_HashSha256_Finished, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha256_Finished:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha384_Finished:CsmJobQueueRef] */
  /*     9 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Conn1_HS_HashSha384, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Conn1_HashSha384:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Hkdf_Sha384Expand:CsmJobQueueRef] */
  /*    10 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Tls_Global_HashSha1, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Tls_Global_HashSha1:CsmJobQueueRef] */
  /*    11 */  /* [/ActiveEcuC/Csm/CsmQueues/Scc_KeyM_Queue, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOLeaf_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOSubCA1_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPOSubCA2_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSLeaf_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSSubCA1_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_CPSSubCA2_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPLeaf_0_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPLeaf_1_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa1_1_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa2_0_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_EMSPSubCa2_1_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvLeaf_0_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvLeaf_1_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa1_1_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa2_0_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_OEMProvSubCa2_1_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_V2GRoot_0_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_V2GRoot_1_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleLeaf_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleSubCA1_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_VehicleSubCA2_ECDSA_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ISO20_secp521r1_SignatureVerify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOCOntract_X_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOSubCa1_X_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_MOSubCa2_X_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_OEMProv_X_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvLeaf_X_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvSubCa1_X_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_ProvSubCa2_X_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_V2GRoot_X_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Scc_V2GRoot_Y_Verify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_TlsConn1_HS_DhSignatureVerify_Secp521r1:CsmJobQueueRef] */

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#define CSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Csm_InitMemory
 **********************************************************************************************************************/
FUNC(void, CSM_CODE) Csm_InitMemory(void)
{
  Csm_InitMemory_Local(Csm_PartitionIndexOfCSLForCSM_SINGLE_PARTITION); /*lint !e522 */
}

/***********************************************************************************************************************
 *  Csm_MainFunction
 **********************************************************************************************************************/
FUNC(void, CSM_CODE) Csm_MainFunction(void)
{
  Csm_MainFunction_Local(Csm_PartitionIndexOfCSLForCSM_SINGLE_PARTITION); /*lint !e522 */
}

#define CSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define CSM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
/***********************************************************************************************************************
 *  Function Group 
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Function Group MainFunctionGroup
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Function Group InitMemoryGroup
 **********************************************************************************************************************/

#define CSM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
 *  END OF FILE: Csm_Cfg.c
 *********************************************************************************************************************/
