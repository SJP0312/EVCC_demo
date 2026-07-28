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
 *            Module: KeyM
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: KeyM_Cfg.h
 *   Generation Time: 2025-09-11 13:39:33
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/


#if !defined (KEYM_CFG_H)
#define KEYM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "NvM.h"
#include "KeyM_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef KEYM_USE_DUMMY_STATEMENT
#define KEYM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef KEYM_DUMMY_STATEMENT
#define KEYM_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef KEYM_DUMMY_STATEMENT_CONST
#define KEYM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef KEYM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define KEYM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef KEYM_ATOMIC_VARIABLE_ACCESS
#define KEYM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef KEYM_PROCESSOR_TC377T
#define KEYM_PROCESSOR_TC377T
#endif
#ifndef KEYM_COMP_DIAB
#define KEYM_COMP_DIAB
#endif
#ifndef KEYM_GEN_GENERATOR_MSR
#define KEYM_GEN_GENERATOR_MSR
#endif
#ifndef KEYM_CPUTYPE_BITORDER_LSB2MSB
#define KEYM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef KEYM_CONFIGURATION_VARIANT_PRECOMPILE
#define KEYM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef KEYM_CONFIGURATION_VARIANT_LINKTIME
#define KEYM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef KEYM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define KEYM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef KEYM_CONFIGURATION_VARIANT
#define KEYM_CONFIGURATION_VARIANT KEYM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef KEYM_POSTBUILD_VARIANT_SUPPORT
#define KEYM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define KEYM_ALGORITHM_RSA_ENABLED                                                                  STD_OFF
#define KEYM_ALGORITHM_ECDSA_ENABLED                                                                STD_ON
#define KEYM_ALGORITHM_EDDSA_ENABLED                                                                STD_OFF
#define KEYM_CERTIFICATEEXTENSION_MAX_LENGTH                                                        100u
#define KEYM_CERTIFICATEISSUERNAME_MAX_LENGTH                                                       256u
#define KEYM_CERTIFICATEISSUERUNIQUEIDENTIFIER_MAX_LENGTH                                           0u
#define KEYM_CERTIFICATESERIALNUMBER_MAX_LENGTH                                                     20u
#define KEYM_CERTIFICATESIGNATURE_MAX_LENGTH                                                        140u
#define KEYM_CERTIFICATESIGNATUREALGORITHM_MAX_LENGTH                                               10u
#define KEYM_CERTIFICATESIGNATUREALGORITHMID_MAX_LENGTH                                             10u
#define KEYM_CERTIFICATESUBJECTNAME_MAX_LENGTH                                                      256u
#define KEYM_CERTIFICATESUBJECTPUBLICKEYINFO_PUBLICKEYALGORITHM_MAX_LENGTH                          10u
#define KEYM_CERTIFICATESUBJECTPUBLICKEYINFO_SUBJECTPUBLICKEY_MAX_LENGTH                            139u
#define KEYM_CERTIFICATESUBJECTUNIQUEIDENTIFIER_MAX_LENGTH                                          0u
#define KEYM_CERTIFICATEVALIDITYPERIODNOTAFTER_MAX_LENGTH                                           17u
#define KEYM_CERTIFICATEVALIDITYPERIODNOTBEFORE_MAX_LENGTH                                          17u
#define KEYM_CERTIFICATEVERSIONNUMBER_MAX_LENGTH                                                    1u
#define KEYM_CERTIFICATESUBJECTAUTHORIZATION_MAX_LENGTH                                             0u
#define KEYM_REVOKEDCERTIFICATES_MAX_LENGTH                                                         0u
#define KEYM_CERTIFICATEREVOCATIONLIST_MAX_LENGTH                                                   0u
#define KEYM_CERTIFICATEATTRIBUTEHOLDER_MAX_LENGTH                                                  0u
#define KEYM_CERTIFICATEATTRIBUTE_MAX_LENGTH                                                        0u
#define KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH                                                         139u
#define KEYM_CERTIFICATE_SIGNATURE_MAX_LENGTH                                                       140u
#define KEYM_OPTIONAL_CERTIFICATE_ELEMENT_ENABLED                                                   STD_ON
#define KEYM_HAS_ITERATION_CERTIFICATE_ELEMENT_ENABLED                                              STD_ON
#define KEYM_ROM_CERTIFICATES                                                                       STD_ON
#define KEYM_CERT_PERSIST_INVALID_CERT_ENABLED                                                      STD_OFF
/* Microsar Define Block for Boolean and Integers */
#define KEYM_CERTIFICATE_CHAIN_MAX_DEPTH                                                            4u 
#define KEYM_CERTIFICATE_MANAGER_ENABLED                                                            STD_ON 
#define KEYM_CRYPTO_KEY_PREPARE_FUNCTION_ENABLED                                                    STD_OFF 
#define KEYM_CRYPTO_KEY_START_FINALIZE_FUNCTION_ENABLED                                             STD_OFF 
#define KEYM_CRYPTO_KEY_VERIFY_ASYNC_MODE                                                           STD_OFF 
#define KEYM_CRYPTO_KEY_VERIFY_FUNCTION_ENABLED                                                     STD_OFF 
#define KEYM_KEY_CERT_NAME_MAX_LENGTH                                                               41u 
#define KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED                                                   STD_ON 
#define KEYM_VERSION_INFO_API                                                                       STD_OFF 
#define KEYM_PARSE_MAX_NESTING_LEVEL                                                                20u 
#define KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED                                                    STD_OFF 
#define KEYM_CERTIFICATE_EXTENSION_VALIDATION_ENABLED                                               STD_OFF 
#define KEYM_OCSPRESPONSE_VALIDITY_PERIOD                                                           1209600u 
#define KEYM_OCSPMAX_LENGTH_OF_DISTINGUISHED_NAME                                                   1000u 
#define KEYM_OCSPMAX_LENGTH_OF_CERT_ID_HASH                                                         64u 
#define KEYM_OCSPFORMAT                                                                             STD_OFF 
#define KEYM_CREMAX_NUMBER_OF_ENTRIES                                                               1u 
#define KEYM_CREMAX_LENGTH_OF_ISSUER_NAME                                                           64u 
#define KEYM_CREMAX_LENGTH_OF_SERIAL_NUMBER                                                         32u 
#define KEYM_CRE                                                                                    STD_OFF 
#define KEYM_REMOTE_OCSPENABLED                                                                     STD_OFF 
#define KEYM_REMOTE_CREENABLED                                                                      STD_OFF 
#define KEYM_PUBLISHED_INFORMATION                                                                  STD_OFF 

/* Symbolic Name Define Block */
#define KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPOLeaf_Tmp                                    0u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPOSubCA1_Tmp                                  1u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPOSubCA2_Tmp                                  2u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPSLeaf_Tmp                                    3u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPSSubCA1_Tmp                                  4u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPSSubCA2_Tmp                                  5u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO2_OEMProvSubCa1                                  6u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO2_OEMProvSubCa2                                  7u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA                             8u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA                           9u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA                           10u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA                             11u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA                           12u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA                           13u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO20_EMSPContract_0_ECDSA                          14u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA                            15u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA                            16u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO20_OEMProvCertificate_0                          17u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO20_OEMProvSubCA1_0                               18u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO20_OEMProvSubCA2_0                               19u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO20_V2GRoot_0                                     20u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO20_V2GRoot_1                                     21u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO20_VehicleCert_0                                 22u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO20_VehicleSubCA1_0                               23u 
#define KeyMConf_KeyMCertificate_SccCertificate_ISO20_VehicleSubCA2_0                               24u 
#define KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_ContractCertificate_0                         25u 
#define KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_MOSubCA1_0                                    26u 
#define KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_MOSubCA2_0                                    27u 
#define KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_OEMProvCertificate_0                          28u 
#define KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2GRoot_0                                     29u 
#define KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_1                                    30u 
#define KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_2                                    31u 
#define KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_3                                    32u 
#define KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_4                                    33u 
#define KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_5                                    34u 
#define KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_6                                    35u 
#define KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_7                                    36u 
#define KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_8                                    37u 
#define KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_9                                    38u 
#define KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2G_Root_10                                   39u 
#define KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO2_CPSLeaf_Tmp                          0u 
#define KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO2_CPSSubCA1_Tmp                        1u 
#define KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO2_CPSSubCA2_Tmp                        2u 
#define KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO2_MOSubCA1_0                           3u 
#define KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO2_MO_Chain                             4u 
#define KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO2_OEMProvCertificate_0                 5u 
#define KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO2_Scc_OEMProvSubCa1                    6u 
#define KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO20_CPSLeaf_Tmp                         7u 
#define KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO20_CPSSubCA1_Tmp                       8u 
#define KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO20_CPSSubCA2_Tmp                       9u 
#define KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO20_EMSPContract_0                      10u 
#define KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO20_EMSPSubCA1_0                        11u 
#define KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO20_EMSPSubCA2_0                        12u 
#define KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO20_OEMProvSubCA1_1                     13u 
#define KeyMConf_KeyMCertificateGroup_SccCertificateGroup_Scc_Certificate_ContractCertificate_0     14u 
#define KeyMConf_KeyMCertificateGroup_SccCertificateGroup_TlsConnection                             15u 

#define KEYM_AC                                                                                     0x00u 
#define KEYM_CRL                                                                                    0x01u 
#define KEYM_CVC                                                                                    0x02u 
#define KEYM_X509                                                                                   0x03u 
#define KEYM_STORAGE_IN_CSM                                                                         0x00u 
#define KEYM_STORAGE_IN_NVM                                                                         0x01u 
#define KEYM_STORAGE_IN_RAM                                                                         0x02u 
#define KEYM_STORAGE_IN_ROM                                                                         0x03u 
#define KEYM_STORAGE_REMOTE                                                                         0x04u 
#define KEYM_ECDSA                                                                                  0x00u 
#define KEYM_EDDSA                                                                                  0x01u 
#define KEYM_RSA                                                                                    0x02u 
#define KEYM_NONE                                                                                   0x00u 
#define KEYM_PARSE_AND_TRUST                                                                        0x01u 
#define KEYM_PARSE_AND_VERIFY                                                                       0x02u 
#define KEYM_DYNAMIC_MANDATORY_ISSUER                                                               0x00u 
#define KEYM_DYNAMIC_OPTIONAL_ISSUER                                                                0x01u 
#define KEYM_DYNAMIC_SELFSIGNED_OR_MANDATORY_ISSUER                                                 0x02u 
#define KEYM_PRESET_ISSUER                                                                          0x03u 
#define KEYM_CERT                                                                                   0x00u 
#define KEYM_PUBKEY                                                                                 0x01u 

#define KEYM_NVM_WRITE_BLOCK_FCT_NAME                                                               NvM_WriteBlock
#define KEYM_DEFERRED                                                                               0u
#define KEYM_IMMEDIATE                                                                              1u
#define KEYM_CERTIFICATE_NVMBLOCK                                                                   STD_ON
#define KEYM_NUMBER_OF_CERTIFICATES                                                                 40u
#define KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO                                                    0x80u
#define KEYM_CERTIFICATE_VALIDITY_PERIOD                                                            0x81u
#define KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ECC_CURVE                               0x82u
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_Version                                                     0u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_Version                                                   0u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_Version                                                   0u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_Version                                                     0u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_Version                                                   0u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_Version                                                   0u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_Version                                          0u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_Version                                                     0u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_Version                                                     0u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_Version                                           0u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_Version                                                      0u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_Version                                                                         0u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_Version                                                                          0u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_Version                                                                          0u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_Version                                                                          0u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_Version                                                                          0u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_Version                                                                          0u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_Version                                                                          0u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_Version                                                                          0u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_Version                                                                          0u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_Version                                                                          0u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_SerialNumber                                                1u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_SerialNumber                                              1u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_SerialNumber                                              1u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_SerialNumber                                                1u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_SerialNumber                                              1u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_SerialNumber                                              1u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_Scc_OEMProvSubCa1_CertificateSerialNumber                                    1u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_Scc_OEMProvSubCa2_CertificateSerialNumber                                    1u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_SerialNumber                                     1u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_SerialNumber                                                1u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_SerialNumber                                                1u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_SerialNumber                                      1u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_SerialNumber                                                 1u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_SerialNumber                                                                    1u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_SerialNumber                                                                     1u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_SerialNumber                                                                     1u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_SerialNumber                                                                     1u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_SerialNumber                                                                     1u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_SerialNumber                                                                     1u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_SerialNumber                                                                     1u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_SerialNumber                                                                     1u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_SerialNumber                                                                     1u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_SerialNumber                                                                     1u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_SignatureAlgorithmId                                        2u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_SignatureAlgorithmId                                      2u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_SignatureAlgorithmId                                      2u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_SignatureAlgorithmId                                        2u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_SignatureAlgorithmId                                      2u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_SignatureAlgorithmId                                      2u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_SignatureAlgorithmId                             2u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_SignatureAlgorithmId                                        2u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_SignatureAlgorithmId                                        2u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_SignatureAlgorithmId                              2u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_SignatureAlgorithmId                                         2u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_SignatureAlgorithmId                                                            2u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_SignatureAlgorithmId                                                             2u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_SignatureAlgorithmId                                                             2u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_SignatureAlgorithmId                                                             2u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_SignatureAlgorithmId                                                             2u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_SignatureAlgorithmId                                                             2u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_SignatureAlgorithmId                                                             2u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_SignatureAlgorithmId                                                             2u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_SignatureAlgorithmId                                                             2u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_SignatureAlgorithmId                                                             2u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_IssuerCommonNameUTF8                                        3u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_IssuerCommonNameUTF8                                      3u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_IssuerCommonNameUTF8                                      3u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_IssuerCommonNameUTF8                                        3u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_IssuerCommonNameUTF8                                      3u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_IssuerCommonNameUTF8                                      3u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_IssuerCommonNameUTF8                             3u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_IssuerCommonNameUTF8                                        3u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_IssuerCommonNameUTF8                                        3u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_IssuerCommonNameUTF8                              3u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_IssuerCommonNameUTF8                                         3u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_IssuerCommonName                                                                3u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_IssuerCommonName                                                                 3u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_IssuerCommonName                                                                 3u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_IssuerCommonName                                                                 3u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_IssuerCommonName                                                                 3u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_IssuerCommonName                                                                 3u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_IssuerCommonName                                                                 3u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_IssuerCommonName                                                                 3u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_IssuerCommonName                                                                 3u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_IssuerCommonName                                                                 3u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_IssuerCommonNamePrintableString                             4u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_IssuerCommonNamePrintableString                           4u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_IssuerCommonNamePrintableString                           4u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_IssuerCommonNamePrintableString                             4u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_IssuerCommonNamePrintableString                           4u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_IssuerCommonNamePrintableString                           4u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_IssuerCommonNamePrintableString                  4u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_IssuerCommonNamePrintableString                             4u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_IssuerCommonNamePrintableString                             4u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_IssuerCommonNamePrintableString                   4u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_IssuerCommonNamePrintableString                              4u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_IssuerCommonName_001                                                            4u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_IssuerCommonName_001                                                             4u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_IssuerCommonName_001                                                             4u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_IssuerCommonName_001                                                             4u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_IssuerCommonName_001                                                             4u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_IssuerCommonName_001                                                             4u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_IssuerCommonName_001                                                             4u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_IssuerCommonName_001                                                             4u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_IssuerCommonName_001                                                             4u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_IssuerCommonName_001                                                             4u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_Version                                              5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_Version                                            5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_Version                                            5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_Version                                              5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_Version                                            5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_Version                                            5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_Version                                           5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_Version                                             5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_Version                                             5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_Version                                           5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_Version                                                5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_Version                                                5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_Version                                                      5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_Version                                                      5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_Version                                                  5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_Version                                                5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_Version                                                5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_IssuerOrganizationNameUTF8                                  5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_IssuerOrganizationNameUTF8                                5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_IssuerOrganizationNameUTF8                                5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_IssuerOrganizationNameUTF8                                  5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_IssuerOrganizationNameUTF8                                5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_IssuerOrganizationNameUTF8                                5u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_IssuerOrganizationNameUTF8                       5u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_IssuerOrganizationNameUTF8                                  5u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_IssuerOrganizationNameUTF8                                  5u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_IssuerOrganizationNameUTF8                        5u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_IssuerOrganizationNameUTF8                                   5u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_IssuerOrganizationName                                                          5u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_IssuerOrganizationName                                                           5u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_IssuerOrganizationName                                                           5u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_IssuerOrganizationName                                                           5u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_IssuerOrganizationName                                                           5u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_IssuerOrganizationName                                                           5u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_IssuerOrganizationName                                                           5u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_IssuerOrganizationName                                                           5u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_IssuerOrganizationName                                                           5u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_IssuerOrganizationName                                                           5u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_IssuerOrganizationNamePrintableString                       6u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_IssuerOrganizationNamePrintableString                     6u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_IssuerOrganizationNamePrintableString                     6u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_IssuerOrganizationNamePrintableString                       6u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_IssuerOrganizationNamePrintableString                     6u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_IssuerOrganizationNamePrintableString                     6u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_IssuerOrganizationNamePrintableString            6u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_IssuerOrganizationNamePrintableString                       6u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_IssuerOrganizationNamePrintableString                       6u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_IssuerOrganizationNamePrintableString             6u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_IssuerOrganizationNamePrintableString                        6u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_IssuerOrganizationName_001                                                      6u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_IssuerOrganizationName_001                                                       6u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_IssuerOrganizationName_001                                                       6u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_IssuerOrganizationName_001                                                       6u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_IssuerOrganizationName_001                                                       6u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_IssuerOrganizationName_001                                                       6u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_IssuerOrganizationName_001                                                       6u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_IssuerOrganizationName_001                                                       6u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_IssuerOrganizationName_001                                                       6u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_IssuerOrganizationName_001                                                       6u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_IssuerCountryName                                           7u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_IssuerCountryName                                         7u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_IssuerCountryName                                         7u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_IssuerCountryName                                           7u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_IssuerCountryName                                         7u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_IssuerCountryName                                         7u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_IssuerCountryName                                7u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_IssuerCountryName                                           7u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_IssuerCountryName                                           7u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_IssuerCountryName                                 7u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_IssuerCountryName                                            7u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_IssuerCountryName                                                               7u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_IssuerCountryName                                                                7u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_IssuerCountryName                                                                7u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_IssuerCountryName                                                                7u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_IssuerCountryName                                                                7u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_IssuerCountryName                                                                7u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_IssuerCountryName                                                                7u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_IssuerCountryName                                                                7u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_IssuerCountryName                                                                7u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_IssuerCountryName                                                                7u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_IssueDomainComponent                                        8u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_IssueDomainComponent                                      8u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_IssueDomainComponent                                      8u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_IssueDomainComponent                                        8u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_IssueDomainComponent                                      8u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_IssueDomainComponent                                      8u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_IssueDomainComponent                             8u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_IssueDomainComponent                                        8u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_IssueDomainComponent                                        8u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_IssueDomainComponent                              8u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_IssueDomainComponent                                         8u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_IssuerOrganizationalUnitName                                                    8u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_IssuerOrganizationalUnitName                                                     8u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_IssuerOrganizationalUnitName                                                     8u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_IssuerOrganizationalUnitName                                                     8u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_IssuerOrganizationalUnitName                                                     8u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_IssuerOrganizationalUnitName                                                     8u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_IssuerOrganizationalUnitName                                                     8u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_IssuerOrganizationalUnitName                                                     8u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_IssuerOrganizationalUnitName                                                     8u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_IssuerOrganizationalUnitName                                                     8u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_IssuerOrganizationalUnitNameUTF8                            9u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_IssuerOrganizationalUnitNameUTF8                          9u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_IssuerOrganizationalUnitNameUTF8                          9u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_IssuerOrganizationalUnitNameUTF8                            9u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_IssuerOrganizationalUnitNameUTF8                          9u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_IssuerOrganizationalUnitNameUTF8                          9u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_IssuerOrganizationalUnitNameUTF8                 9u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_IssuerOrganizationalUnitNameUTF8                            9u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_IssuerOrganizationalUnitNameUTF8                            9u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_IssuerOrganizationalUnitNameUTF8                  9u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_IssuerOrganizationalUnitNameUTF8                             9u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_ValidityNotBefore                                                               9u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_ValidityNotBefore                                                                9u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_ValidityNotBefore                                                                9u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_ValidityNotBefore                                                                9u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_ValidityNotBefore                                                                9u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_ValidityNotBefore                                                                9u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_ValidityNotBefore                                                                9u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_ValidityNotBefore                                                                9u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_ValidityNotBefore                                                                9u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_ValidityNotBefore                                                                9u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SerialNumber                                         10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SerialNumber                                       10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SerialNumber                                       10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SerialNumber                                         10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_SerialNumber                                       10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_SerialNumber                                       10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SerialNumber                                      10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_SerialNumber                                        10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SerialNumber                                        10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SerialNumber                                      10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_SerialNumber                                           10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_SerialNumber                                           10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_SerialNumber                                                 10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_SerialNumber                                                 10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_SerialNumber                                             10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_SerialNumber                                           10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_SerialNumber                                           10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_IssuerOrganizationalUnitNamePrintableString                 10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_IssuerOrganizationalUnitNamePrintableString               10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_IssuerOrganizationalUnitNamePrintableString               10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_IssuerOrganizationalUnitNamePrintableString                 10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_IssuerOrganizationalUnitNamePrintableString               10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_IssuerOrganizationalUnitNamePrintableString               10u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_IssuerOrganizationalUnitNamePrintableString      10u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_IssuerOrganizationalUnitNamePrintableString                 10u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_IssuerOrganizationalUnitNamePrintableString                 10u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_IssuerOrganizationalUnitNamePrintableString       10u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_IssuerOrganizationalUnitNamePrintableString                  10u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ValidityNotBefore                                           11u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ValidityNotBefore                                         11u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ValidityNotBefore                                         11u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ValidityNotBefore                                           11u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ValidityNotBefore                                         11u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ValidityNotBefore                                         11u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ValidityNotBefore                                11u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ValidityNotBefore                                           11u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ValidityNotBefore                                           11u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ValidityNotBefore                                 11u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ValidityNotBefore                                            11u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_ValidityNotAfter                                                                11u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_ValidityNotAfter                                                                 11u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_ValidityNotAfter                                                                 11u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_ValidityNotAfter                                                                 11u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_ValidityNotAfter                                                                 11u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_ValidityNotAfter                                                                 11u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_ValidityNotAfter                                                                 11u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_ValidityNotAfter                                                                 11u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_ValidityNotAfter                                                                 11u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_ValidityNotAfter                                                                 11u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ValidityNotAfter                                            12u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ValidityNotAfter                                          12u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ValidityNotAfter                                          12u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ValidityNotAfter                                            12u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ValidityNotAfter                                          12u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ValidityNotAfter                                          12u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ValidityNotAfter                                 12u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ValidityNotAfter                                            12u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ValidityNotAfter                                            12u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ValidityNotAfter                                  12u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ValidityNotAfter                                             12u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_SubjectCommonNameUTF8                                       13u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_SubjectCommonNameUTF8                                     13u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_SubjectCommonNameUTF8                                     13u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_SubjectCommonNameUTF8                                       13u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_SubjectCommonNameUTF8                                     13u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_SubjectCommonNameUTF8                                     13u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_SubjectCommonNameUTF8                            13u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_SubjectCommonNameUTF8                                       13u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_SubjectCommonNameUTF8                                       13u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_SubjectCommonNameUTF8                             13u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_SubjectCommonNameUTF8                                        13u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_SubjectCommonName                                                               13u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_SubjectCommonName                                                                13u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_SubjectCommonName                                                                13u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_SubjectCommonName                                                                13u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_SubjectCommonName                                                                13u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_SubjectCommonName                                                                13u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_SubjectCommonName                                                                13u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_SubjectCommonName                                                                13u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_SubjectCommonName                                                                13u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_SubjectCommonName                                                                13u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_SubjectCommonNamePrintableString                            14u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_SubjectCommonNamePrintableString                          14u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_SubjectCommonNamePrintableString                          14u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_SubjectCommonNamePrintableString                            14u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_SubjectCommonNamePrintableString                          14u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_SubjectCommonNamePrintableString                          14u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_SubjectCommonNamePrintableString                 14u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_SubjectCommonNamePrintableString                            14u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_SubjectCommonNamePrintableString                            14u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_SubjectCommonNamePrintableString                  14u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_SubjectCommonNamePrintableString                             14u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_SubjectCommonName_001                                                           14u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_SubjectCommonName_001                                                            14u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_SubjectCommonName_001                                                            14u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_SubjectCommonName_001                                                            14u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_SubjectCommonName_001                                                            14u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_SubjectCommonName_001                                                            14u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_SubjectCommonName_001                                                            14u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_SubjectCommonName_001                                                            14u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_SubjectCommonName_001                                                            14u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_SubjectCommonName_001                                                            14u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SignatureAlgorithmId                                 15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SignatureAlgorithmId                               15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SignatureAlgorithmId                               15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SignatureAlgorithmId                                 15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_SignatureAlgorithmId                               15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_SignatureAlgorithmId                               15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SignatureAlgorithmId                              15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_SignatureAlgorithmId                                15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SignatureAlgorithmId                                15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SignatureAlgorithmId                              15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_SignatureAlgorithmId                                   15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_SignatureAlgorithmId                                   15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_SignatureAlgorithmId                                         15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_SignatureAlgorithmId                                         15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_SignatureAlgorithmId                                     15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_SignatureAlgorithmId                                   15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_SignatureAlgorithmId                                   15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_SubjectOrgNameUTF8                                          15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_SubjectOrgNameUTF8                                        15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_SubjectOrgNameUTF8                                        15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_SubjectOrgNameUTF8                                          15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_SubjectOrgNameUTF8                                        15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_SubjectOrgNameUTF8                                        15u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_SubjectOrgNameUTF8                               15u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_SubjectOrgNameUTF8                                          15u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_SubjectOrgNameUTF8                                          15u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_SubjectOrgNameUTF8                                15u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_SubjectOrgNameUTF8                                           15u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_SubjectOrgName                                                                  15u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_SubjectOrgName                                                                   15u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_SubjectOrgName                                                                   15u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_SubjectOrgName                                                                   15u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_SubjectOrgName                                                                   15u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_SubjectOrgName                                                                   15u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_SubjectOrgName                                                                   15u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_SubjectOrgName                                                                   15u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_SubjectOrgName                                                                   15u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_SubjectOrgName                                                                   15u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_SubjectOrgNamePrintableString                               16u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_SubjectOrgNamePrintableString                             16u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_SubjectOrgNamePrintableString                             16u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_SubjectOrgNamePrintableString                               16u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_SubjectOrgNamePrintableString                             16u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_SubjectOrgNamePrintableString                             16u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_SubjectOrgNamePrintableString                    16u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_SubjectOrgNamePrintableString                               16u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_SubjectOrgNamePrintableString                               16u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_SubjectOrgNamePrintableString                     16u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_SubjectOrgNamePrintableString                                16u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_SubjectOrgName_001                                                              16u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_SubjectOrgName_001                                                               16u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_SubjectOrgName_001                                                               16u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_SubjectOrgName_001                                                               16u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_SubjectOrgName_001                                                               16u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_SubjectOrgName_001                                                               16u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_SubjectOrgName_001                                                               16u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_SubjectOrgName_001                                                               16u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_SubjectOrgName_001                                                               16u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_SubjectOrgName_001                                                               16u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_SubjectCountryName                                          17u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_SubjectCountryName                                        17u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_SubjectCountryName                                        17u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_SubjectCountryName                                          17u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_SubjectCountryName                                        17u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_SubjectCountryName                                        17u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_SubjectCountryName                               17u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_SubjectCountryName                                          17u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_SubjectCountryName                                          17u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_SubjectCountryName                                17u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_SubjectCountryName                                           17u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_SubjectCountryName                                                              17u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_SubjectCountryName                                                               17u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_SubjectCountryName                                                               17u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_SubjectCountryName                                                               17u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_SubjectCountryName                                                               17u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_SubjectCountryName                                                               17u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_SubjectCountryName                                                               17u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_SubjectCountryName                                                               17u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_SubjectCountryName                                                               17u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_SubjectCountryName                                                               17u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_SubjectDomainComponent                                      18u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_SubjectDomainComponent                                    18u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_SubjectDomainComponent                                    18u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_SubjectDomainComponent                                      18u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_SubjectDomainComponent                                    18u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_SubjectDomainComponent                                    18u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_SubjectDomainComponent                           18u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_SubjectDomainComponent                                      18u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_SubjectDomainComponent                                      18u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_SubjectDomainComponent                            18u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_SubjectDomainComponent                                       18u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_SubjecDomainComponent                                                           18u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_SubjecDomainComponent                                                            18u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_SubjecDomainComponent                                                            18u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_SubjecDomainComponent                                                            18u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_SubjecDomainComponent                                                            18u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_SubjecDomainComponent                                                            18u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_SubjecDomainComponent                                                            18u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_SubjecDomainComponent                                                            18u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_SubjecDomainComponent                                                            18u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_SubjecDomainComponent                                                            18u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_SubjectPublicKeyAlgorithm                                   19u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_SubjectPublicKeyAlgorithm                                 19u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_SubjectPublicKeyAlgorithm                                 19u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_SubjectPublicKeyAlgorithm                                   19u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_SubjectPublicKeyAlgorithm                                 19u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_SubjectPublicKeyAlgorithm                                 19u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_SubjectPublicKeyAlgorithm                        19u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_SubjectPublicKeyAlgorithm                                   19u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_SubjectPublicKeyAlgorithm                                   19u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_SubjectPublicKeyAlgorithm                         19u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_SubjectPublicKeyAlgorithm                                    19u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_SubjectPublicKeyAlgorithm                                                       19u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_SubjectPublicKeyAlgorithm                                                        19u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_SubjectPublicKeyAlgorithm                                                        19u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_SubjectPublicKeyAlgorithm                                                        19u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_SubjectPublicKeyAlgorithm                                                        19u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_SubjectPublicKeyAlgorithm                                                        19u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_SubjectPublicKeyAlgorithm                                                        19u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_SubjectPublicKeyAlgorithm                                                        19u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_SubjectPublicKeyAlgorithm                                                        19u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_SubjectPublicKeyAlgorithm                                                        19u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_IssuerCountryNameOID                                 20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_IssuerCountryNameOID                               20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_IssuerCountryNameOID                               20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_IssuerCountryNameOID                                 20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_IssuerCountryNameOID                               20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_IssuerCountryNameOID                               20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_IssuerCountryNameOID                              20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_IssuerCountryNameOID                                20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_IssuerCountryNameOID                                20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_IssuerCountryNameOID                              20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_IssuerCountryNameOID                                   20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_IssuerCountryNameOID                                   20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerCountryNameOID                                         20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerCountryNameOID                                         20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_IssuerCountryNameOID                                     20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_IssuerCountryNameOID                                   20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_IssuerCountryNameOID                                   20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_SubjectPublicKeyCurve                                       20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_SubjectPublicKeyCurve                                     20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_SubjectPublicKeyCurve                                     20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_SubjectPublicKeyCurve                                       20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_SubjectPublicKeyCurve                                     20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_SubjectPublicKeyCurve                                     20u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_SubjectPublicKeyCurve                            20u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_SubjectPublicKeyCurve                                       20u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_SubjectPublicKeyCurve                                       20u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_SubjectPublicKeyCurve                             20u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_SubjectPublicKeyCurve                                        20u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_SubjectPublicKeyCurve                                                           20u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_SubjectPublicKeyCurve                                                            20u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_SubjectPublicKeyCurve                                                            20u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_SubjectPublicKeyCurve                                                            20u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_SubjectPublicKeyCurve                                                            20u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_SubjectPublicKeyCurve                                                            20u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_SubjectPublicKeyCurve                                                            20u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_SubjectPublicKeyCurve                                                            20u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_SubjectPublicKeyCurve                                                            20u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_SubjectPublicKeyCurve                                                            20u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_SubjectPublicKeyBitString                                   21u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_SubjectPublicKeyBitString                                 21u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_SubjectPublicKeyBitString                                 21u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_SubjectPublicKeyBitString                                   21u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_SubjectPublicKeyBitString                                 21u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_SubjectPublicKeyBitString                                 21u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_SubjectPublicKeyBitString                        21u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_SubjectPublicKeyBitString                                   21u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_SubjectPublicKeyBitString                                   21u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_SubjectPublicKeyBitString                         21u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_SubjectPublicKeyBitString                                    21u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_SubjectPublicKeyBitString                                                       21u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_SubjectPublicKeyBitString                                                        21u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_SubjectPublicKeyBitString                                                        21u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_SubjectPublicKeyBitString                                                        21u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_SubjectPublicKeyBitString                                                        21u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_SubjectPublicKeyBitString                                                        21u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_SubjectPublicKeyBitString                                                        21u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_SubjectPublicKeyBitString                                                        21u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_SubjectPublicKeyBitString                                                        21u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_SubjectPublicKeyBitString                                                        21u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionKeyUsage                                           22u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionKeyUsage                                         22u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionKeyUsage                                         22u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionKeyUsage                                           22u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionKeyUsage                                         22u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionKeyUsage                                         22u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ExtensionKeyUsage                                22u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ExtensionKeyUsage                                           22u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ExtensionKeyUsage                                           22u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ExtensionKeyUsage                                 22u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ExtensionKeyUsage                                            22u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_ExtensionKeyUsage                                                               22u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_ExtensionKeyUsage                                                                22u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_ExtensionKeyUsage                                                                22u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_ExtensionKeyUsage                                                                22u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_ExtensionKeyUsage                                                                22u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_ExtensionKeyUsage                                                                22u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_ExtensionKeyUsage                                                                22u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_ExtensionKeyUsage                                                                22u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_ExtensionKeyUsage                                                                22u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_ExtensionKeyUsage                                                                22u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionBasicConstraints                                   23u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionBasicConstraints                                 23u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionBasicConstraints                                 23u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionBasicConstraints                                   23u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionBasicConstraints                                 23u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionBasicConstraints                                 23u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ExtensionBasicConstraints                        23u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ExtensionBasicConstraints                                   23u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ExtensionBasicConstraints                                   23u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ExtensionBasicConstraints                         23u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ExtensionBasicConstraints                                    23u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_ExtensionBasicConstraints                                                       23u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_ExtensionBasicConstraints                                                        23u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_ExtensionBasicConstraints                                                        23u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_ExtensionBasicConstraints                                                        23u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_ExtensionBasicConstraints                                                        23u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_ExtensionBasicConstraints                                                        23u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_ExtensionBasicConstraints                                                        23u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_ExtensionBasicConstraints                                                        23u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_ExtensionBasicConstraints                                                        23u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_ExtensionBasicConstraints                                                        23u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionExtendedKeyUsageOID                                24u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionExtendedKeyUsageOID                              24u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionExtendedKeyUsageOID                              24u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionExtendedKeyUsageOID                                24u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionExtendedKeyUsageOID                              24u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionExtendedKeyUsageOID                              24u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ExtensionExtendedKeyUsageOID                     24u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ExtensionExtendedKeyUsageOID                                24u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ExtensionExtendedKeyUsageOID                                24u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ExtensionExtendedKeyUsageOID                      24u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ExtensionExtendedKeyUsageOID                                 24u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_ExtensionExtKeyUsage                                                            24u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_ExtensionExtKeyUsage                                                             24u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_ExtensionExtKeyUsage                                                             24u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_ExtensionExtKeyUsage                                                             24u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_ExtensionExtKeyUsage                                                             24u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_ExtensionExtKeyUsage                                                             24u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_ExtensionExtKeyUsage                                                             24u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_ExtensionExtKeyUsage                                                             24u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_ExtensionExtKeyUsage                                                             24u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_ExtensionExtKeyUsage                                                             24u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_IssuerCountryName                                    25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_IssuerCountryName                                  25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_IssuerCountryName                                  25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_IssuerCountryName                                    25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_IssuerCountryName                                  25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_IssuerCountryName                                  25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_IssuerCountryName                                 25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_IssuerCountryName                                   25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_IssuerCountryName                                   25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_IssuerCountryName                                 25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_IssuerCountryName                                      25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_IssuerCountryName                                      25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerCountryName                                            25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerCountryName                                            25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_IssuerCountryName                                        25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_IssuerCountryName                                      25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_IssuerCountryName                                      25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionExtendedKeyUsageCritical                           25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionExtendedKeyUsageCritical                         25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionExtendedKeyUsageCritical                         25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionExtendedKeyUsageCritical                           25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionExtendedKeyUsageCritical                         25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionExtendedKeyUsageCritical                         25u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ExtensionExtendedKeyUsageCritical                25u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ExtensionExtendedKeyUsageCritical                           25u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ExtensionExtendedKeyUsageCritical                           25u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ExtensionExtendedKeyUsageCritical                 25u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ExtensionExtendedKeyUsageCritical                            25u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_ExtensionServerAuth                                                             25u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_ExtensionServerAuth                                                              25u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_ExtensionServerAuth                                                              25u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_ExtensionServerAuth                                                              25u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_ExtensionServerAuth                                                              25u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_ExtensionServerAuth                                                              25u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_ExtensionServerAuth                                                              25u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_ExtensionServerAuth                                                              25u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_ExtensionServerAuth                                                              25u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_ExtensionServerAuth                                                              25u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionExtendedKeyUsageKeyPurposeId                       26u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionExtendedKeyUsageKeyPurposeId                     26u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionExtendedKeyUsageKeyPurposeId                     26u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionExtendedKeyUsageKeyPurposeId                       26u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionExtendedKeyUsageKeyPurposeId                     26u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionExtendedKeyUsageKeyPurposeId                     26u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ExtensionExtendedKeyUsageKeyPurposeId            26u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ExtensionExtendedKeyUsageKeyPurposeId                       26u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ExtensionExtendedKeyUsageKeyPurposeId                       26u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ExtensionExtendedKeyUsageKeyPurposeId             26u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ExtensionExtendedKeyUsageKeyPurposeId                        26u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_ExtensionClientAuth                                                             26u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_ExtensionClientAuth                                                              26u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_ExtensionClientAuth                                                              26u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_ExtensionClientAuth                                                              26u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_ExtensionClientAuth                                                              26u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_ExtensionClientAuth                                                              26u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_ExtensionClientAuth                                                              26u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_ExtensionClientAuth                                                              26u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_ExtensionClientAuth                                                              26u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_ExtensionClientAuth                                                              26u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionAuthorityKeyIdentifierOID                          27u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionAuthorityKeyIdentifierOID                        27u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionAuthorityKeyIdentifierOID                        27u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionAuthorityKeyIdentifierOID                          27u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionAuthorityKeyIdentifierOID                        27u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionAuthorityKeyIdentifierOID                        27u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ExtensionAuthorityKeyIdentifierOID               27u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ExtensionAuthorityKeyIdentifierOID                          27u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ExtensionAuthorityKeyIdentifierOID                          27u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ExtensionAuthorityKeyIdentifierOID                27u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ExtensionAuthorityKeyIdentifierOID                           27u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_ExtensionAuthorityKeyIdentifier                                                 27u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_ExtensionAuthorityKeyIdentifier                                                  27u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_ExtensionAuthorityKeyIdentifier                                                  27u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_ExtensionAuthorityKeyIdentifier                                                  27u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_ExtensionAuthorityKeyIdentifier                                                  27u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_ExtensionAuthorityKeyIdentifier                                                  27u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_ExtensionAuthorityKeyIdentifier                                                  27u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_ExtensionAuthorityKeyIdentifier                                                  27u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_ExtensionAuthorityKeyIdentifier                                                  27u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_ExtensionAuthorityKeyIdentifier                                                  27u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionAuthorityKeyIdentifierCritical                     28u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionAuthorityKeyIdentifierCritical                   28u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionAuthorityKeyIdentifierCritical                   28u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionAuthorityKeyIdentifierCritical                     28u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionAuthorityKeyIdentifierCritical                   28u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionAuthorityKeyIdentifierCritical                   28u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ExtensionAuthorityKeyIdentifierCritical          28u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ExtensionAuthorityKeyIdentifierCritical                     28u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ExtensionAuthorityKeyIdentifierCritical                     28u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ExtensionAuthorityKeyIdentifierCritical           28u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ExtensionAuthorityKeyIdentifierCritical                      28u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_ExtensionSubjectKeyIdentifier                                                   28u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_ExtensionSubjectKeyIdentifier                                                    28u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_ExtensionSubjectKeyIdentifier                                                    28u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_ExtensionSubjectKeyIdentifier                                                    28u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_ExtensionSubjectKeyIdentifier                                                    28u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_ExtensionSubjectKeyIdentifier                                                    28u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_ExtensionSubjectKeyIdentifier                                                    28u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_ExtensionSubjectKeyIdentifier                                                    28u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_ExtensionSubjectKeyIdentifier                                                    28u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_ExtensionSubjectKeyIdentifier                                                    28u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionAuthorityKeyIdentifier                             29u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionAuthorityKeyIdentifier                           29u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionAuthorityKeyIdentifier                           29u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionAuthorityKeyIdentifier                             29u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionAuthorityKeyIdentifier                           29u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionAuthorityKeyIdentifier                           29u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ExtensionAuthorityKeyIdentifier                  29u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ExtensionAuthorityKeyIdentifier                             29u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ExtensionAuthorityKeyIdentifier                             29u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ExtensionAuthorityKeyIdentifier                   29u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ExtensionAuthorityKeyIdentifier                              29u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_ExtensionAuthorityInfoAccess                                                    29u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_ExtensionAuthorityInfoAccess                                                     29u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_ExtensionAuthorityInfoAccess                                                     29u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_ExtensionAuthorityInfoAccess                                                     29u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_ExtensionAuthorityInfoAccess                                                     29u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_ExtensionAuthorityInfoAccess                                                     29u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_ExtensionAuthorityInfoAccess                                                     29u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_ExtensionAuthorityInfoAccess                                                     29u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_ExtensionAuthorityInfoAccess                                                     29u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_ExtensionAuthorityInfoAccess                                                     29u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_IssuerOrganizationNameOID                            30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_IssuerOrganizationNameOID                          30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_IssuerOrganizationNameOID                          30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_IssuerOrganizationNameOID                            30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_IssuerOrganizationNameOID                          30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_IssuerOrganizationNameOID                          30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_IssuerOrganizationNameOID                         30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_IssuerOrganizationNameOID                           30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_IssuerOrganizationNameOID                           30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_IssuerOrganizationNameOID                         30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_IssuerOrganizationNameOID                              30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_IssuerOrganizationNameOID                              30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerOrganizationNameOID                                    30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerOrganizationNameOID                                    30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_IssuerOrganizationNameOID                                30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_IssuerOrganizationNameOID                              30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_IssuerOrganizationNameOID                              30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionAuthorityKeyIdentifierCertIssuerOid                30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionAuthorityKeyIdentifierCertIssuerOid              30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionAuthorityKeyIdentifierCertIssuerOid              30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionAuthorityKeyIdentifierCertIssuerOid                30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionAuthorityKeyIdentifierCertIssuerOid              30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionAuthorityKeyIdentifierCertIssuerOid              30u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ExtensionAuthorityKeyIdentifierCertIssuerOid     30u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ExtensionAuthorityKeyIdentifierCertIssuerOid                30u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ExtensionAuthorityKeyIdentifierCertIssuerOid                30u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ExtensionAuthorityKeyIdentifierCertIssuerOid      30u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ExtensionAuthorityKeyIdentifierCertIssuerOid                 30u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_ExtensionOcsp                                                                   30u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_ExtensionOcsp                                                                    30u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_ExtensionOcsp                                                                    30u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_ExtensionOcsp                                                                    30u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_ExtensionOcsp                                                                    30u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_ExtensionOcsp                                                                    30u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_ExtensionOcsp                                                                    30u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_ExtensionOcsp                                                                    30u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_ExtensionOcsp                                                                    30u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_ExtensionOcsp                                                                    30u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber             31u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber           31u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber           31u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber             31u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber           31u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber           31u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ExtensionAuthorityKeyIdentifierCertSerialNumber  31u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ExtensionAuthorityKeyIdentifierCertSerialNumber             31u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ExtensionAuthorityKeyIdentifierCertSerialNumber             31u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ExtensionAuthorityKeyIdentifierCertSerialNumber   31u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ExtensionAuthorityKeyIdentifierCertSerialNumber              31u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_CertificateSignatureAlgorithm                                                   31u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_CertificateSignatureAlgorithm                                                    31u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_CertificateSignatureAlgorithm                                                    31u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_CertificateSignatureAlgorithm                                                    31u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_CertificateSignatureAlgorithm                                                    31u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_CertificateSignatureAlgorithm                                                    31u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_CertificateSignatureAlgorithm                                                    31u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_CertificateSignatureAlgorithm                                                    31u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_CertificateSignatureAlgorithm                                                    31u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_CertificateSignatureAlgorithm                                                    31u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber2            32u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber2          32u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber2          32u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber2            32u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber2          32u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber2          32u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ExtensionAuthorityKeyIdentifierCertSerialNumber2 32u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ExtensionAuthorityKeyIdentifierCertSerialNumber2            32u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ExtensionAuthorityKeyIdentifierCertSerialNumber2            32u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ExtensionAuthorityKeyIdentifierCertSerialNumber2  32u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ExtensionAuthorityKeyIdentifierCertSerialNumber2             32u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_10_SignatureInteger                                                                32u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_1_SignatureInteger                                                                 32u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_2_SignatureInteger                                                                 32u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_3_SignatureInteger                                                                 32u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_4_SignatureInteger                                                                 32u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_5_SignatureInteger                                                                 32u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_6_SignatureInteger                                                                 32u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_7_SignatureInteger                                                                 32u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_8_SignatureInteger                                                                 32u 
#define KeyMConf_KeyMCertificateElement_V2G_Root_9_SignatureInteger                                                                 32u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionSubjectKeyIdentifierOID                            33u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionSubjectKeyIdentifierOID                          33u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionSubjectKeyIdentifierOID                          33u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionSubjectKeyIdentifierOID                            33u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionSubjectKeyIdentifierOID                          33u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionSubjectKeyIdentifierOID                          33u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ExtensionSubjectKeyIdentifierOID                 33u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ExtensionSubjectKeyIdentifierOID                            33u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ExtensionSubjectKeyIdentifierOID                            33u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ExtensionSubjectKeyIdentifierOID                  33u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ExtensionSubjectKeyIdentifierOID                             33u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionSubjectKeyIdentifierCritical                       34u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionSubjectKeyIdentifierCritical                     34u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionSubjectKeyIdentifierCritical                     34u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionSubjectKeyIdentifierCritical                       34u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionSubjectKeyIdentifierCritical                     34u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionSubjectKeyIdentifierCritical                     34u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ExtensionSubjectKeyIdentifierCritical            34u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ExtensionSubjectKeyIdentifierCritical                       34u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ExtensionSubjectKeyIdentifierCritical                       34u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ExtensionSubjectKeyIdentifierCritical             34u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ExtensionSubjectKeyIdentifierCritical                        34u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_IssuerOrganizationNameUTF8                           35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_IssuerOrganizationNameUTF8                         35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_IssuerOrganizationNameUTF8                         35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_IssuerOrganizationNameUTF8                           35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_IssuerOrganizationNameUTF8                         35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_IssuerOrganizationNameUTF8                         35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_IssuerOrganizationNameUTF8                        35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_IssuerOrganizationNameUTF8                          35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_IssuerOrganizationNameUTF8                          35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_IssuerOrganizationNameUTF8                        35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_IssuerOrganizationNameUTF8                             35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_IssuerOrganizationNameUTF8                             35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerOrganizationNameUTF8                                   35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerOrganizationNameUTF8                                   35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_IssuerOrganizationNameUTF8                               35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_IssuerOrganizationNameUTF8                             35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_IssuerOrganizationNameUTF8                             35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionSubjectKeyIdentifier                               35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionSubjectKeyIdentifier                             35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionSubjectKeyIdentifier                             35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionSubjectKeyIdentifier                               35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionSubjectKeyIdentifier                             35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionSubjectKeyIdentifier                             35u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ExtensionSubjectKeyIdentifier                    35u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ExtensionSubjectKeyIdentifier                               35u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ExtensionSubjectKeyIdentifier                               35u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ExtensionSubjectKeyIdentifier                     35u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ExtensionSubjectKeyIdentifier                                35u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionCRLDistributionPointsOID                           36u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionCRLDistributionPointsOID                         36u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionCRLDistributionPointsOID                         36u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionCRLDistributionPointsOID                           36u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionCRLDistributionPointsOID                         36u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionCRLDistributionPointsOID                         36u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ExtensionCRLDistributionPointsOID                36u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ExtensionCRLDistributionPointsOID                           36u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ExtensionCRLDistributionPointsOID                           36u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ExtensionCRLDistributionPointsOID                 36u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ExtensionCRLDistributionPointsOID                            36u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionCRLDistributionPointsCritical                      37u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionCRLDistributionPointsCritical                    37u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionCRLDistributionPointsCritical                    37u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionCRLDistributionPointsCritical                      37u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionCRLDistributionPointsCritical                    37u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionCRLDistributionPointsCritical                    37u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ExtensionCRLDistributionPointsCritical           37u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ExtensionCRLDistributionPointsCritical                      37u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ExtensionCRLDistributionPointsCritical                      37u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ExtensionCRLDistributionPointsCritical            37u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ExtensionCRLDistributionPointsCritical                       37u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionAuthorityInfoAccessOID                             38u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionAuthorityInfoAccessOID                           38u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionAuthorityInfoAccessOID                           38u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionAuthorityInfoAccessOID                             38u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionAuthorityInfoAccessOID                           38u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionAuthorityInfoAccessOID                           38u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ExtensionAuthorityInfoAccessOID                  38u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ExtensionAuthorityInfoAccessOID                             38u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ExtensionAuthorityInfoAccessOID                             38u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ExtensionAuthorityInfoAccessOID                   38u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ExtensionAuthorityInfoAccessOID                              38u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionAuthorityInfoAccessCritical                        39u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionAuthorityInfoAccessCritical                      39u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionAuthorityInfoAccessCritical                      39u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionAuthorityInfoAccessCritical                        39u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionAuthorityInfoAccessCritical                      39u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionAuthorityInfoAccessCritical                      39u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ExtensionAuthorityInfoAccessCritical             39u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ExtensionAuthorityInfoAccessCritical                        39u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ExtensionAuthorityInfoAccessCritical                        39u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ExtensionAuthorityInfoAccessCritical              39u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ExtensionAuthorityInfoAccessCritical                         39u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_IssuerOrganizationNamePrintableString                40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_IssuerOrganizationNamePrintableString              40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_IssuerOrganizationNamePrintableString              40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_IssuerOrganizationNamePrintableString                40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_IssuerOrganizationNamePrintableString              40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_IssuerOrganizationNamePrintableString              40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_IssuerOrganizationNamePrintableString             40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_IssuerOrganizationNamePrintableString               40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_IssuerOrganizationNamePrintableString               40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_IssuerOrganizationNamePrintableString             40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_IssuerOrganizationNamePrintableString                  40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_IssuerOrganizationNamePrintableString                  40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerOrganizationNamePrintableString                        40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerOrganizationNamePrintableString                        40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_IssuerOrganizationNamePrintableString                    40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_IssuerOrganizationNamePrintableString                  40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_IssuerOrganizationNamePrintableString                  40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionAuthorityInfoAccessMethodOID                       40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionAuthorityInfoAccessMethodOID                     40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionAuthorityInfoAccessMethodOID                     40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionAuthorityInfoAccessMethodOID                       40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionAuthorityInfoAccessMethodOID                     40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionAuthorityInfoAccessMethodOID                     40u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ExtensionAuthorityInfoAccessMethodOID            40u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ExtensionAuthorityInfoAccessMethodOID                       40u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ExtensionAuthorityInfoAccessMethodOID                       40u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ExtensionAuthorityInfoAccessMethodOID             40u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ExtensionAuthorityInfoAccessMethodOID                        40u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionAuthorityInfoAccessMethodLocation                  41u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionAuthorityInfoAccessMethodLocation                41u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionAuthorityInfoAccessMethodLocation                41u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionAuthorityInfoAccessMethodLocation                  41u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionAuthorityInfoAccessMethodLocation                41u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionAuthorityInfoAccessMethodLocation                41u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ExtensionAuthorityInfoAccessMethodLocation       41u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_ExtensionAuthorityInfoAccessMethodLocation                  41u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_ExtensionAuthorityInfoAccessMethodLocation                  41u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_ExtensionAuthorityInfoAccessMethodLocation        41u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_ExtensionAuthorityInfoAccessMethodLocation                   41u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_CertificateSignatureAlgorithm                               42u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_CertificateSignatureAlgorithm                             42u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_CertificateSignatureAlgorithm                             42u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_CertificateSignatureAlgorithm                               42u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_CertificateSignatureAlgorithm                             42u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_CertificateSignatureAlgorithm                             42u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_CertificateSignatureAlgorithm                    42u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_CertificateSignatureAlgorithm                               42u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_CertificateSignatureAlgorithm                               42u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_CertificateSignatureAlgorithm                     42u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_CertificateSignatureAlgorithm                                42u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_SignatureInteger                                            43u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_SignatureInteger                                          43u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_SignatureInteger                                          43u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_SignatureInteger                                            43u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA1_Tmp_SignatureInteger                                          43u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSSubCA2_Tmp_SignatureInteger                                          43u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_SignatureInteger                                 43u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA1_0_SignatureInteger                                            43u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_SignatureInteger                                            43u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_OEMProvCertificate_0_SignatureInteger                                  43u 
#define KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_SignatureInteger                                             43u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_IssuerOrganizationalUnitNameOID                      45u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_IssuerOrganizationalUnitNameOID                    45u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_IssuerOrganizationalUnitNameOID                    45u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_IssuerOrganizationalUnitNameOID                      45u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_IssuerOrganizationalUnitNameOID                    45u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_IssuerOrganizationalUnitNameOID                    45u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_IssuerOrganizationalUnitNameOID                   45u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_IssuerOrganizationalUnitNameOID                     45u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_IssuerOrganizationalUnitNameOID                     45u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_IssuerOrganizationalUnitNameOID                   45u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_IssuerOrganizationalUnitNameOID                        45u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_IssuerOrganizationalUnitNameOID                        45u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerOrganizationalUnitNameOID                              45u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerOrganizationalUnitNameOID                              45u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_IssuerOrganizationalUnitNameOID                          45u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_IssuerOrganizationalUnitNameOID                        45u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_IssuerOrganizationalUnitNameOID                        45u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_IssuerOrganizationalUnitNameUTF8                     50u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_IssuerOrganizationalUnitNameUTF8                   50u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_IssuerOrganizationalUnitNameUTF8                   50u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_IssuerOrganizationalUnitNameUTF8                     50u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_IssuerOrganizationalUnitNameUTF8                   50u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_IssuerOrganizationalUnitNameUTF8                   50u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_IssuerOrganizationalUnitNameUTF8                  50u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_IssuerOrganizationalUnitNameUTF8                    50u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_IssuerOrganizationalUnitNameUTF8                    50u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_IssuerOrganizationalUnitNameUTF8                  50u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_IssuerOrganizationalUnitNameUTF8                       50u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_IssuerOrganizationalUnitNameUTF8                       50u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerOrganizationalUnitNameUTF8                             50u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerOrganizationalUnitNameUTF8                             50u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_IssuerOrganizationalUnitNameUTF8                         50u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_IssuerOrganizationalUnitNameUTF8                       50u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_IssuerOrganizationalUnitNameUTF8                       50u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_IssuerOrganizationalUnitNamePrintableString          55u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_IssuerOrganizationalUnitNamePrintableString        55u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_IssuerOrganizationalUnitNamePrintableString        55u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_IssuerOrganizationalUnitNamePrintableString          55u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_IssuerOrganizationalUnitNamePrintableString        55u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_IssuerOrganizationalUnitNamePrintableString        55u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_IssuerOrganizationalUnitNamePrintableString       55u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_IssuerOrganizationalUnitNamePrintableString         55u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_IssuerOrganizationalUnitNamePrintableString         55u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_IssuerOrganizationalUnitNamePrintableString       55u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_IssuerOrganizationalUnitNamePrintableString            55u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_IssuerOrganizationalUnitNamePrintableString            55u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerOrganizationalUnitNamePrintableString                  55u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerOrganizationalUnitNamePrintableString                  55u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_IssuerOrganizationalUnitNamePrintableString              55u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_IssuerOrganizationalUnitNamePrintableString            55u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_IssuerOrganizationalUnitNamePrintableString            55u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_IssuerCommonNameOID                                  60u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_IssuerCommonNameOID                                60u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_IssuerCommonNameOID                                60u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_IssuerCommonNameOID                                  60u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_IssuerCommonNameOID                                60u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_IssuerCommonNameOID                                60u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_IssuerCommonNameOID                               60u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_IssuerCommonNameOID                                 60u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_IssuerCommonNameOID                                 60u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_IssuerCommonNameOID                               60u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_IssuerCommonNameOID                                    60u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_IssuerCommonNameOID                                    60u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerCommonNameOID                                          60u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerCommonNameOID                                          60u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_IssuerCommonNameOID                                      60u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_IssuerCommonNameOID                                    60u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_IssuerCommonNameOID                                    60u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_IssuerCommonNameUTF8                                 65u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_IssuerCommonNameUTF8                               65u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_IssuerCommonNameUTF8                               65u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_IssuerCommonNameUTF8                                 65u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_IssuerCommonNameUTF8                               65u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_IssuerCommonNameUTF8                               65u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_IssuerCommonNameUTF8                              65u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_IssuerCommonNameUTF8                                65u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_IssuerCommonNameUTF8                                65u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_IssuerCommonNameUTF8                              65u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_IssuerCommonNameUTF8                                   65u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_IssuerCommonNameUTF8                                   65u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerCommonNameUTF8                                         65u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerCommonNameUTF8                                         65u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_IssuerCommonNameUTF8                                     65u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_IssuerCommonNameUTF8                                   65u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_IssuerCommonNameUTF8                                   65u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_IssuerCommonNamePrintableString                      70u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_IssuerCommonNamePrintableString                    70u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_IssuerCommonNamePrintableString                    70u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_IssuerCommonNamePrintableString                      70u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_IssuerCommonNamePrintableString                    70u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_IssuerCommonNamePrintableString                    70u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_IssuerCommonNamePrintableString                   70u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_IssuerCommonNamePrintableString                     70u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_IssuerCommonNamePrintableString                     70u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_IssuerCommonNamePrintableString                   70u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_IssuerCommonNamePrintableString                        70u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_IssuerCommonNamePrintableString                        70u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerCommonNamePrintableString                              70u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerCommonNamePrintableString                              70u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_IssuerCommonNamePrintableString                          70u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_IssuerCommonNamePrintableString                        70u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_IssuerCommonNamePrintableString                        70u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_IssuerDomainComponentOID                             75u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_IssuerDomainComponentOID                           75u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_IssuerDomainComponentOID                           75u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_IssuerDomainComponentOID                             75u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_IssuerDomainComponentOID                           75u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_IssuerDomainComponentOID                           75u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_IssuerDomainComponentOID                          75u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_IssuerDomainComponentOID                            75u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_IssuerDomainComponentOID                            75u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_IssuerDomainComponentOID                          75u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_IssuerDomainComponentOID                               75u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_IssuerDomainComponentOID                               75u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerDomainComponentOID                                     75u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerDomainComponentOID                                     75u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_IssuerDomainComponentOID                                 75u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_IssuerDomainComponentOID                               75u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_IssuerDomainComponentOID                               75u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_IssuerDomainComponent                                80u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_IssuerDomainComponent                              80u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_IssuerDomainComponent                              80u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_IssuerDomainComponent                                80u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_IssuerDomainComponent                              80u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_IssuerDomainComponent                              80u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_IssuerDomainComponent                             80u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_IssuerDomainComponent                               80u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_IssuerDomainComponent                               80u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_IssuerDomainComponent                             80u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_IssuerDomainComponent                                  80u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_IssuerDomainComponent                                  80u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerDomainComponent                                        80u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerDomainComponent                                        80u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_IssuerDomainComponent                                    80u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_IssuerDomainComponent                                  80u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_IssuerDomainComponent                                  80u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ValidityNotBefore                                    85u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ValidityNotBefore                                  85u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ValidityNotBefore                                  85u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ValidityNotBefore                                    85u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ValidityNotBefore                                  85u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ValidityNotBefore                                  85u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ValidityNotBefore                                 85u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ValidityNotBefore                                   85u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ValidityNotBefore                                   85u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ValidityNotBefore                                 85u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ValidityNotBefore                                      85u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ValidityNotBefore                                      85u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_ValidityNotBefore                                            85u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_ValidityNotBefore                                            85u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ValidityNotBefore                                        85u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ValidityNotBefore                                      85u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ValidityNotBefore                                      85u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ValidityNotAfter                                     90u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ValidityNotAfter                                   90u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ValidityNotAfter                                   90u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ValidityNotAfter                                     90u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ValidityNotAfter                                   90u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ValidityNotAfter                                   90u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ValidityNotAfter                                  90u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ValidityNotAfter                                    90u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ValidityNotAfter                                    90u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ValidityNotAfter                                  90u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ValidityNotAfter                                       90u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ValidityNotAfter                                       90u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_ValidityNotAfter                                             90u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_ValidityNotAfter                                             90u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ValidityNotAfter                                         90u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ValidityNotAfter                                       90u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ValidityNotAfter                                       90u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SubjectCountryNameOID                                95u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SubjectCountryNameOID                              95u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SubjectCountryNameOID                              95u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SubjectCountryNameOID                                95u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_SubjectCountryNameOID                              95u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_SubjectCountryNameOID                              95u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectCountryNameOID                             95u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_SubjectCountryNameOID                               95u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SubjectCountryNameOID                               95u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SubjectCountryNameOID                             95u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_SubjectCountryNameOID                                  95u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_SubjectCountryNameOID                                  95u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_SubjectCountryNameOID                                        95u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_SubjectCountryNameOID                                        95u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_SubjectCountryNameOID                                    95u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_SubjectCountryNameOID                                  95u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_SubjectCountryNameOID                                  95u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SubjectCountryName                                   100u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SubjectCountryName                                 100u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SubjectCountryName                                 100u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SubjectCountryName                                   100u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_SubjectCountryName                                 100u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_SubjectCountryName                                 100u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectCountryName                                100u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_SubjectCountryName                                  100u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SubjectCountryName                                  100u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SubjectCountryName                                100u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_SubjectCountryName                                     100u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_SubjectCountryName                                     100u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_SubjectCountryName                                           100u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_SubjectCountryName                                           100u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_SubjectCountryName                                       100u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_SubjectCountryName                                     100u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_SubjectCountryName                                     100u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SubjectOrganizationNameOID                           105u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SubjectOrganizationNameOID                         105u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SubjectOrganizationNameOID                         105u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SubjectOrganizationNameOID                           105u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_SubjectOrganizationNameOID                         105u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_SubjectOrganizationNameOID                         105u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectOrganizationNameOID                        105u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_SubjectOrganizationNameOID                          105u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SubjectOrganizationNameOID                          105u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SubjectOrganizationNameOID                        105u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_SubjectOrganizationNameOID                             105u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_SubjectOrganizationNameOID                             105u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_SubjectOrganizationNameOID                                   105u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_SubjectOrganizationNameOID                                   105u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_SubjectOrganizationNameOID                               105u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_SubjectOrganizationNameOID                             105u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_SubjectOrganizationNameOID                             105u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SubjectOrganizationNameUTF8                          110u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SubjectOrganizationNameUTF8                        110u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SubjectOrganizationNameUTF8                        110u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SubjectOrganizationNameUTF8                          110u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_SubjectOrganizationNameUTF8                        110u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_SubjectOrganizationNameUTF8                        110u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectOrganizationNameUTF8                       110u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_SubjectOrganizationNameUTF8                         110u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SubjectOrganizationNameUTF8                         110u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SubjectOrganizationNameUTF8                       110u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_SubjectOrganizationNameUTF8                            110u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_SubjectOrganizationNameUTF8                            110u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_SubjectOrganizationNameUTF8                                  110u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_SubjectOrganizationNameUTF8                                  110u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_SubjectOrganizationNameUTF8                              110u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_SubjectOrganizationNameUTF8                            110u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_SubjectOrganizationNameUTF8                            110u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SubjectOrganizationNamePrintableString               115u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SubjectOrganizationNamePrintableString             115u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SubjectOrganizationNamePrintableString             115u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SubjectOrganizationNamePrintableString               115u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_SubjectOrganizationNamePrintableString             115u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_SubjectOrganizationNamePrintableString             115u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectOrganizationNamePrintableString            115u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_SubjectOrganizationNamePrintableString              115u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SubjectOrganizationNamePrintableString              115u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SubjectOrganizationNamePrintableString            115u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_SubjectOrganizationNamePrintableString                 115u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_SubjectOrganizationNamePrintableString                 115u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_SubjectOrganizationNamePrintableString                       115u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_SubjectOrganizationNamePrintableString                       115u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_SubjectOrganizationNamePrintableString                   115u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_SubjectOrganizationNamePrintableString                 115u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_SubjectOrganizationNamePrintableString                 115u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SubjectOrganizationalUnitNameOID                     120u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SubjectOrganizationalUnitNameOID                   120u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SubjectOrganizationalUnitNameOID                   120u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SubjectOrganizationalUnitNameOID                     120u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_SubjectOrganizationalUnitNameOID                   120u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_SubjectOrganizationalUnitNameOID                   120u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectOrganizationalUnitNameOID                  120u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_SubjectOrganizationalUnitNameOID                    120u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SubjectOrganizationalUnitNameOID                    120u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SubjectOrganizationalUnitNameOID                  120u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_SubjectOrganizationalUnitNameOID                       120u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_SubjectOrganizationalUnitNameOID                       120u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_SubjectOrganizationalUnitNameOID                             120u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_SubjectOrganizationalUnitNameOID                             120u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_SubjectOrganizationalUnitNameOID                         120u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_SubjectOrganizationalUnitNameOID                       120u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_SubjectOrganizationalUnitNameOID                       120u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SubjectOrganizationalUnitNameUTF8                    125u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SubjectOrganizationalUnitNameUTF8                  125u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SubjectOrganizationalUnitNameUTF8                  125u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SubjectOrganizationalUnitNameUTF8                    125u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_SubjectOrganizationalUnitNameUTF8                  125u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_SubjectOrganizationalUnitNameUTF8                  125u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectOrganizationalUnitNameUTF8                 125u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_SubjectOrganizationalUnitNameUTF8                   125u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SubjectOrganizationalUnitNameUTF8                   125u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SubjectOrganizationalUnitNameUTF8                 125u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_SubjectOrganizationalUnitNameUTF8                      125u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_SubjectOrganizationalUnitNameUTF8                      125u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_SubjectOrganizationalUnitNameUTF8                            125u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_SubjectOrganizationalUnitNameUTF8                            125u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_SubjectOrganizationalUnitNameUTF8                        125u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_SubjectOrganizationalUnitNameUTF8                      125u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_SubjectOrganizationalUnitNameUTF8                      125u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SubjectOrganizationalUnitNamePrintableString         130u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SubjectOrganizationalUnitNamePrintableString       130u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SubjectOrganizationalUnitNamePrintableString       130u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SubjectOrganizationalUnitNamePrintableString         130u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_SubjectOrganizationalUnitNamePrintableString       130u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_SubjectOrganizationalUnitNamePrintableString       130u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectOrganizationalUnitNamePrintableString      130u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_SubjectOrganizationalUnitNamePrintableString        130u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SubjectOrganizationalUnitNamePrintableString        130u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SubjectOrganizationalUnitNamePrintableString      130u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_SubjectOrganizationalUnitNamePrintableString           130u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_SubjectOrganizationalUnitNamePrintableString           130u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_SubjectOrganizationalUnitNamePrintableString                 130u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_SubjectOrganizationalUnitNamePrintableString                 130u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_SubjectOrganizationalUnitNamePrintableString             130u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_SubjectOrganizationalUnitNamePrintableString           130u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_SubjectOrganizationalUnitNamePrintableString           130u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SubjectCommonNameOID                                 135u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SubjectCommonNameOID                               135u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SubjectCommonNameOID                               135u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SubjectCommonNameOID                                 135u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_SubjectCommonNameOID                               135u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_SubjectCommonNameOID                               135u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectCommonNameOID                              135u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_SubjectCommonNameOID                                135u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SubjectCommonNameOID                                135u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SubjectCommonNameOID                              135u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_SubjectCommonNameOID                                   135u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_SubjectCommonNameOID                                   135u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_SubjectCommonNameOID                                         135u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_SubjectCommonNameOID                                         135u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_SubjectCommonNameOID                                     135u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_SubjectCommonNameOID                                   135u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_SubjectCommonNameOID                                   135u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SubjectCommonNameUTF8                                140u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SubjectCommonNameUTF8                              140u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SubjectCommonNameUTF8                              140u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SubjectCommonNameUTF8                                140u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_SubjectCommonNameUTF8                              140u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_SubjectCommonNameUTF8                              140u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectCommonNameUTF8                             140u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_SubjectCommonNameUTF8                               140u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SubjectCommonNameUTF8                               140u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SubjectCommonNameUTF8                             140u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_SubjectCommonNameUTF8                                  140u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_SubjectCommonNameUTF8                                  140u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_SubjectCommonNameUTF8                                        140u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_SubjectCommonNameUTF8                                        140u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_SubjectCommonNameUTF8                                    140u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_SubjectCommonNameUTF8                                  140u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_SubjectCommonNameUTF8                                  140u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SubjectCommonNamePrintableString                     145u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SubjectCommonNamePrintableString                   145u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SubjectCommonNamePrintableString                   145u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SubjectCommonNamePrintableString                     145u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_SubjectCommonNamePrintableString                   145u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_SubjectCommonNamePrintableString                   145u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectCommonNamePrintableString                  145u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_SubjectCommonNamePrintableString                    145u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SubjectCommonNamePrintableString                    145u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SubjectCommonNamePrintableString                  145u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_SubjectCommonNamePrintableString                       145u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_SubjectCommonNamePrintableString                       145u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_SubjectCommonNamePrintableString                             145u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_SubjectCommonNamePrintableString                             145u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_SubjectCommonNamePrintableString                         145u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_SubjectCommonNamePrintableString                       145u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_SubjectCommonNamePrintableString                       145u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SubjectDomainComponentOID                            150u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SubjectDomainComponentOID                          150u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SubjectDomainComponentOID                          150u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SubjectDomainComponentOID                            150u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_SubjectDomainComponentOID                          150u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_SubjectDomainComponentOID                          150u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectDomainComponentOID                         150u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_SubjectDomainComponentOID                           150u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SubjectDomainComponentOID                           150u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SubjectDomainComponentOID                         150u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_SubjectDomainComponentOID                              150u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_SubjectDomainComponentOID                              150u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_SubjectDomainComponentOID                                    150u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_SubjectDomainComponentOID                                    150u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_SubjectDomainComponentOID                                150u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_SubjectDomainComponentOID                              150u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_SubjectDomainComponentOID                              150u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SubjectDomainComponent                               155u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SubjectDomainComponent                             155u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SubjectDomainComponent                             155u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SubjectDomainComponent                               155u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_SubjectDomainComponent                             155u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_SubjectDomainComponent                             155u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectDomainComponent                            155u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_SubjectDomainComponent                              155u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SubjectDomainComponent                              155u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SubjectDomainComponent                            155u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_SubjectDomainComponent                                 155u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_SubjectDomainComponent                                 155u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_SubjectDomainComponent                                       155u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_SubjectDomainComponent                                       155u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_SubjectDomainComponent                                   155u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_SubjectDomainComponent                                 155u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_SubjectDomainComponent                                 155u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SubjectPublicKeyInfoAlgorithm                        160u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SubjectPublicKeyInfoAlgorithm                      160u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SubjectPublicKeyInfoAlgorithm                      160u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SubjectPublicKeyInfoAlgorithm                        160u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_SubjectPublicKeyInfoAlgorithm                      160u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_SubjectPublicKeyInfoAlgorithm                      160u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectPublicKeyInfoAlgorithm                     160u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_SubjectPublicKeyInfoAlgorithm                       160u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SubjectPublicKeyInfoAlgorithm                       160u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SubjectPublicKeyInfoAlgorithm                     160u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_SubjectPublicKeyInfoAlgorithm                          160u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_SubjectPublicKeyInfoAlgorithm                          160u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_SubjectPublicKeyInfoAlgorithm                                160u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_SubjectPublicKeyInfoAlgorithm                                160u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_SubjectPublicKeyInfoAlgorithm                            160u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_SubjectPublicKeyInfoAlgorithm                          160u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_SubjectPublicKeyInfoAlgorithm                          160u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SubjectPublicKeyInfoCurve                            165u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SubjectPublicKeyInfoCurve                          165u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SubjectPublicKeyInfoCurve                          165u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SubjectPublicKeyInfoCurve                            165u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_SubjectPublicKeyInfoCurve                          165u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_SubjectPublicKeyInfoCurve                          165u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectPublicKeyInfoCurve                         165u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_SubjectPublicKeyInfoCurve                           165u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SubjectPublicKeyInfoCurve                           165u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SubjectPublicKeyInfoCurve                         165u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_SubjectPublicKeyInfoCurve                              165u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_SubjectPublicKeyInfoCurve                              165u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_SubjectPublicKeyInfoCurve                                    165u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_SubjectPublicKeyInfoCurve                                    165u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_SubjectPublicKeyInfoCurve                                165u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_SubjectPublicKeyInfoCurve                              165u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_SubjectPublicKeyInfoCurve                              165u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SubjectPublicKeyBitString                            170u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SubjectPublicKeyBitString                          170u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SubjectPublicKeyBitString                          170u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SubjectPublicKeyBitString                            170u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_SubjectPublicKeyBitString                          170u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_SubjectPublicKeyBitString                          170u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectPublicKeyBitString                         170u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_SubjectPublicKeyBitString                           170u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SubjectPublicKeyBitString                           170u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SubjectPublicKeyBitString                         170u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_SubjectPublicKeyBitString                              170u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_SubjectPublicKeyBitString                              170u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_SubjectPublicKeyBitString                                    170u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_SubjectPublicKeyBitString                                    170u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_SubjectPublicKeyBitString                                170u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_SubjectPublicKeyBitString                              170u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_SubjectPublicKeyBitString                              170u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierOID                   175u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierOID                 175u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierOID                 175u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierOID                   175u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierOID                 175u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierOID                 175u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionAuthorityKeyIdentifierOID                175u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionAuthorityKeyIdentifierOID                  175u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionAuthorityKeyIdentifierOID                  175u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionAuthorityKeyIdentifierOID                175u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionAuthorityKeyIdentifierOID                     175u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionAuthorityKeyIdentifierOID                     175u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_ExtensionSubjectKeyIdentifierOID                             175u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_ExtensionSubjectKeyIdentifierOID                             175u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionAuthorityKeyIdentifierOID                       175u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionAuthorityKeyIdentifierOID                     175u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionAuthorityKeyIdentifierOID                     175u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCritical              180u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCritical            180u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCritical            180u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCritical              180u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCritical            180u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCritical            180u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionAuthorityKeyIdentifierCritical           180u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionAuthorityKeyIdentifierCritical             180u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionAuthorityKeyIdentifierCritical             180u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionAuthorityKeyIdentifierCritical           180u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionAuthorityKeyIdentifierCritical                180u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionAuthorityKeyIdentifierCritical                180u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_ExtensionSubjectKeyIdentifierCritical                        180u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_ExtensionSubjectKeyIdentifierCritical                        180u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionAuthorityKeyIdentifierCritical                  180u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionAuthorityKeyIdentifierCritical                180u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionAuthorityKeyIdentifierCritical                180u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifier                      185u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifier                    185u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifier                    185u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifier                      185u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifier                    185u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifier                    185u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionAuthorityKeyIdentifier                   185u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionAuthorityKeyIdentifier                     185u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionAuthorityKeyIdentifier                     185u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionAuthorityKeyIdentifier                   185u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionAuthorityKeyIdentifier                        185u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionAuthorityKeyIdentifier                        185u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_ExtensionSubjectKeyIdentifier                                185u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_ExtensionSubjectKeyIdentifier                                185u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionAuthorityKeyIdentifier                          185u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionAuthorityKeyIdentifier                        185u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionAuthorityKeyIdentifier                        185u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertIssuerOid         190u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertIssuerOid       190u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertIssuerOid       190u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertIssuerOid         190u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertIssuerOid       190u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertIssuerOid       190u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionAuthorityKeyIdentifierCertIssuerOid      190u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionAuthorityKeyIdentifierCertIssuerOid        190u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionAuthorityKeyIdentifierCertIssuerOid        190u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionAuthorityKeyIdentifierCertIssuerOid      190u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionAuthorityKeyIdentifierCertIssuerOid           190u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionAuthorityKeyIdentifierCertIssuerOid           190u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_ExtensionKeyUsageOID                                         190u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_ExtensionKeyUsageOID                                         190u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionAuthorityKeyIdentifierCertIssuerOid             190u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionAuthorityKeyIdentifierCertIssuerOid           190u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionAuthorityKeyIdentifierCertIssuerOid           190u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber      195u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber    195u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber    195u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber      195u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber    195u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber    195u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber   195u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber     195u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber     195u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionAuthorityKeyIdentifierCertSerialNumber   195u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionAuthorityKeyIdentifierCertSerialNumber        195u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionAuthorityKeyIdentifierCertSerialNumber        195u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_ExtensionKeyUsageCritical                                    195u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_ExtensionKeyUsageCritical                                    195u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionAuthorityKeyIdentifierCertSerialNumber          195u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionAuthorityKeyIdentifierCertSerialNumber        195u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionAuthorityKeyIdentifierCertSerialNumber        195u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber2     200u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber2   200u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber2   200u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber2     200u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber2   200u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber2   200u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber2  200u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber2    200u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber2    200u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionAuthorityKeyIdentifierCertSerialNumber2  200u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionAuthorityKeyIdentifierCertSerialNumber2       200u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionAuthorityKeyIdentifierCertSerialNumber2       200u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_ExtensionKeyUsage                                            200u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_ExtensionKeyUsage                                            200u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionAuthorityKeyIdentifierCertSerialNumber2         200u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionAuthorityKeyIdentifierCertSerialNumber2       200u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionAuthorityKeyIdentifierCertSerialNumber2       200u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionSubjectKeyIdentifierOID                     205u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionSubjectKeyIdentifierOID                   205u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionSubjectKeyIdentifierOID                   205u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionSubjectKeyIdentifierOID                     205u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionSubjectKeyIdentifierOID                   205u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionSubjectKeyIdentifierOID                   205u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionSubjectKeyIdentifierOID                  205u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionSubjectKeyIdentifierOID                    205u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionSubjectKeyIdentifierOID                    205u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionSubjectKeyIdentifierOID                  205u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionSubjectKeyIdentifierOID                       205u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionSubjectKeyIdentifierOID                       205u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_ExtensionBasicConstraintsOID                                 205u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_ExtensionBasicConstraintsOID                                 205u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionSubjectKeyIdentifierOID                         205u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionSubjectKeyIdentifierOID                       205u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionSubjectKeyIdentifierOID                       205u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionSubjectKeyIdentifierCritical                210u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionSubjectKeyIdentifierCritical              210u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionSubjectKeyIdentifierCritical              210u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionSubjectKeyIdentifierCritical                210u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionSubjectKeyIdentifierCritical              210u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionSubjectKeyIdentifierCritical              210u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionSubjectKeyIdentifierCritical             210u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionSubjectKeyIdentifierCritical               210u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionSubjectKeyIdentifierCritical               210u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionSubjectKeyIdentifierCritical             210u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionSubjectKeyIdentifierCritical                  210u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionSubjectKeyIdentifierCritical                  210u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_ExtensionBasicConstraintsCritical                            210u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_ExtensionBasicConstraintsCritical                            210u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionSubjectKeyIdentifierCritical                    210u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionSubjectKeyIdentifierCritical                  210u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionSubjectKeyIdentifierCritical                  210u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionSubjectKeyIdentifier                        215u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionSubjectKeyIdentifier                      215u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionSubjectKeyIdentifier                      215u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionSubjectKeyIdentifier                        215u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionSubjectKeyIdentifier                      215u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionSubjectKeyIdentifier                      215u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionSubjectKeyIdentifier                     215u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionSubjectKeyIdentifier                       215u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionSubjectKeyIdentifier                       215u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionSubjectKeyIdentifier                     215u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionSubjectKeyIdentifier                          215u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionSubjectKeyIdentifier                          215u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_ExtensionBasicConstraintsCA                                  215u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_ExtensionBasicConstraintsCA                                  215u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionSubjectKeyIdentifier                            215u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionSubjectKeyIdentifier                          215u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionSubjectKeyIdentifier                          215u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionKeyUsageOID                                 220u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionKeyUsageOID                               220u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionKeyUsageOID                               220u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionKeyUsageOID                                 220u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionKeyUsageOID                               220u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionKeyUsageOID                               220u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionKeyUsageOID                              220u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionKeyUsageOID                                220u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionKeyUsageOID                                220u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionKeyUsageOID                              220u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionKeyUsageOID                                   220u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionKeyUsageOID                                   220u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_CertificateSignatureAlgorithm                                220u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_CertificateSignatureAlgorithm                                220u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionKeyUsageOID                                     220u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionKeyUsageOID                                   220u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionKeyUsageOID                                   220u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionKeyUsageCritical                            225u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionKeyUsageCritical                          225u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionKeyUsageCritical                          225u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionKeyUsageCritical                            225u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionKeyUsageCritical                          225u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionKeyUsageCritical                          225u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionKeyUsageCritical                         225u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionKeyUsageCritical                           225u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionKeyUsageCritical                           225u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionKeyUsageCritical                         225u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionKeyUsageCritical                              225u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionKeyUsageCritical                              225u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_SignatureInteger                                             225u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_SignatureInteger                                             225u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionKeyUsageCritical                                225u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionKeyUsageCritical                              225u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionKeyUsageCritical                              225u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionKeyUsage                                    230u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionKeyUsage                                  230u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionKeyUsage                                  230u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionKeyUsage                                    230u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionKeyUsage                                  230u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionKeyUsage                                  230u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionKeyUsage                                 230u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionKeyUsage                                   230u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionKeyUsage                                   230u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionKeyUsage                                 230u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionKeyUsage                                      230u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionKeyUsage                                      230u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionKeyUsage                                        230u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionKeyUsage                                      230u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionKeyUsage                                      230u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionExtendedKeyUsageOID                         235u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionExtendedKeyUsageOID                       235u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionExtendedKeyUsageOID                       235u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionExtendedKeyUsageOID                         235u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionExtendedKeyUsageOID                       235u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionExtendedKeyUsageOID                       235u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionExtendedKeyUsageOID                      235u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionExtendedKeyUsageOID                        235u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionExtendedKeyUsageOID                        235u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionCertificatePoliciesOID                   235u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionCertificatePoliciesOID                        235u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionCertificatePoliciesOID                        235u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionExtendedKeyUsageOID                             235u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionCertificatePoliciesOID                        235u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionCertificatePoliciesOID                        235u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionExtendedKeyUsageCritical                    240u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionExtendedKeyUsageCritical                  240u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionExtendedKeyUsageCritical                  240u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionExtendedKeyUsageCritical                    240u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionExtendedKeyUsageCritical                  240u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionExtendedKeyUsageCritical                  240u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionExtendedKeyUsageCritical                 240u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionExtendedKeyUsageCritical                   240u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionExtendedKeyUsageCritical                   240u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionCertificatePoliciesCritical              240u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionCertificatePoliciesCritical                   240u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionCertificatePoliciesCritical                   240u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionExtendedKeyUsageCritical                        240u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionCertificatePoliciesCritical                   240u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionCertificatePoliciesCritical                   240u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionExtendedKeyUsageKeyPurposeId                245u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionExtendedKeyUsageKeyPurposeId              245u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionExtendedKeyUsageKeyPurposeId              245u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionExtendedKeyUsageKeyPurposeId                245u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionExtendedKeyUsageKeyPurposeId              245u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionExtendedKeyUsageKeyPurposeId              245u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionExtendedKeyUsageKeyPurposeId             245u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionExtendedKeyUsageKeyPurposeId               245u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionExtendedKeyUsageKeyPurposeId               245u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionBasicConstraintsOID                      245u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionBasicConstraintsOID                           245u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionBasicConstraintsOID                           245u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionExtendedKeyUsageKeyPurposeId                    245u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionBasicConstraintsOID                           245u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionBasicConstraintsOID                           245u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionCertificatePoliciesOID                      250u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionCertificatePoliciesOID                    250u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionCertificatePoliciesOID                    250u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionBasicConstraintsOID                         250u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionBasicConstraintsOID                       250u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionBasicConstraintsOID                       250u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionBasicConstraintsOID                      250u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionBasicConstraintsOID                        250u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionBasicConstraintsOID                        250u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionBasicConstraintsCritical                 250u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionBasicConstraintsCritical                      250u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionBasicConstraintsCritical                      250u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionCertificatePoliciesOID                          250u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionBasicConstraintsCritical                      250u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionBasicConstraintsCritical                      250u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionCertificatePoliciesCritical                 255u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionCertificatePoliciesCritical               255u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionCertificatePoliciesCritical               255u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionBasicConstraintsCritical                    255u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionBasicConstraintsCritical                  255u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionBasicConstraintsCritical                  255u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionBasicConstraintsCritical                 255u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionBasicConstraintsCritical                   255u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionBasicConstraintsCritical                   255u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionBasicConstraintsCA                       255u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionBasicConstraintsCA                            255u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionBasicConstraintsCA                            255u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionCertificatePoliciesCritical                     255u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionBasicConstraintsCA                            255u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionBasicConstraintsCA                            255u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionBasicConstraintsOID                         260u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionBasicConstraintsOID                       260u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionBasicConstraintsOID                       260u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionBasicConstraintsCA                          260u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionBasicConstraintsCA                        260u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionBasicConstraintsCA                        260u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionBasicConstraintsCA                       260u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionBasicConstraintsCA                         260u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionBasicConstraintsCA                         260u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionCRLDistributionPointsOID                 260u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionBasicConstraintsPathLen                       260u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionBasicConstraintsPathLen                       260u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionBasicConstraintsOID                             260u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionBasicConstraintsPathLen                       260u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionBasicConstraintsPathLen                       260u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionBasicConstraintsCritical                    265u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionBasicConstraintsCritical                  265u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionBasicConstraintsCritical                  265u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionCertificatePoliciesOID                      265u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionBasicConstraintsPathLen                   265u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionBasicConstraintsPathLen                   265u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionCertificatePoliciesOID                   265u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionBasicConstraintsPathLen                    265u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionBasicConstraintsPathLen                    265u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionCRLDistributionPointsCritical            265u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionCRLDistributionPointsOID                      265u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionCRLDistributionPointsOID                      265u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionBasicConstraintsCritical                        265u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionCRLDistributionPointsOID                      265u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionCRLDistributionPointsOID                      265u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionBasicConstraintsCA                          270u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionBasicConstraintsCA                        270u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionBasicConstraintsCA                        270u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionCertificatePoliciesCritical                 270u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionCertificatePoliciesOID                    270u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionCertificatePoliciesOID                    270u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionCertificatePoliciesCritical              270u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionCertificatePoliciesOID                     270u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionCertificatePoliciesOID                     270u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionAuthorityInfoAccessOID                   270u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionCRLDistributionPointsCritical                 270u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionCRLDistributionPointsCritical                 270u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionBasicConstraintsCA                              270u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionCRLDistributionPointsCritical                 270u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionCRLDistributionPointsCritical                 270u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionBasicConstraintsPathLen                     275u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionBasicConstraintsPathLen                   275u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionBasicConstraintsPathLen                   275u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionCRLDistributionPointsOID                    275u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionCertificatePoliciesCritical               275u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionCertificatePoliciesCritical               275u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionCRLDistributionPointsOID                 275u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionCertificatePoliciesCritical                275u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionCertificatePoliciesCritical                275u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionAuthorityInfoAccessCritical              275u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionAuthorityInfoAccessOID                        275u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionAuthorityInfoAccessOID                        275u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionCRLDistributionPointsOID                        275u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionAuthorityInfoAccessOID                        275u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionAuthorityInfoAccessOID                        275u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionAuthorityInfoAccessOID                      280u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionAuthorityInfoAccessOID                    280u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionAuthorityInfoAccessOID                    280u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionCRLDistributionPointsCritical               280u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionCRLDistributionPointsOID                  280u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionCRLDistributionPointsOID                  280u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionCRLDistributionPointsCritical            280u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionCRLDistributionPointsOID                   280u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionCRLDistributionPointsOID                   280u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionAuthorityInfoAccessMethodOID             280u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionAuthorityInfoAccessCritical                   280u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionAuthorityInfoAccessCritical                   280u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionCRLDistributionPointsCritical                   280u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionAuthorityInfoAccessCritical                   280u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionAuthorityInfoAccessCritical                   280u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionAuthorityInfoAccessCritical                 285u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionAuthorityInfoAccessCritical               285u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionAuthorityInfoAccessCritical               285u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionAuthorityInfoAccessOID                      285u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionCRLDistributionPointsCritical             285u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionCRLDistributionPointsCritical             285u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionAuthorityInfoAccessOID                   285u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionCRLDistributionPointsCritical              285u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionCRLDistributionPointsCritical              285u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionAuthorityInfoAccessMethodLocation        285u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionAuthorityInfoAccessMethodOID                  285u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionAuthorityInfoAccessMethodOID                  285u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionAuthorityInfoAccessOID                          285u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionAuthorityInfoAccessMethodOID                  285u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionAuthorityInfoAccessMethodOID                  285u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionAuthorityInfoAccessMethodOID                290u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionAuthorityInfoAccessMethodOID              290u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionAuthorityInfoAccessMethodOID              290u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionAuthorityInfoAccessCritical                 290u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionAuthorityInfoAccessOID                    290u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionAuthorityInfoAccessOID                    290u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionAuthorityInfoAccessCritical              290u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionAuthorityInfoAccessOID                     290u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionAuthorityInfoAccessOID                     290u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionSubjectInfoAccessOID                     290u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_ExtensionAuthorityInfoAccessMethodLocation             290u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_ExtensionAuthorityInfoAccessMethodLocation             290u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionAuthorityInfoAccessCritical                     290u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_ExtensionAuthorityInfoAccessMethodLocation             290u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_ExtensionAuthorityInfoAccessMethodLocation             290u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionAuthorityInfoAccessMethodLocation           295u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionAuthorityInfoAccessMethodLocation         295u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionAuthorityInfoAccessMethodLocation         295u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionAuthorityInfoAccessMethodOID                295u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionAuthorityInfoAccessCritical               295u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionAuthorityInfoAccessCritical               295u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionAuthorityInfoAccessMethodOID             295u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionAuthorityInfoAccessCritical                295u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionAuthorityInfoAccessCritical                295u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionSubjectInfoAccessCritical                295u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_CertificateSignatureAlgorithm                          295u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_CertificateSignatureAlgorithm                          295u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionAuthorityInfoAccessMethodOID                    295u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_CertificateSignatureAlgorithm                          295u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_CertificateSignatureAlgorithm                          295u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_CertificateSignatureAlgorithm                        300u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_CertificateSignatureAlgorithm                      300u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_CertificateSignatureAlgorithm                      300u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionAuthorityInfoAccessMethodLocation           300u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionAuthorityInfoAccessMethodOID              300u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionAuthorityInfoAccessMethodOID              300u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionAuthorityInfoAccessMethodLocation        300u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionAuthorityInfoAccessMethodOID               300u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionAuthorityInfoAccessMethodOID               300u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_ExtensionSubjectInfoAccess                        300u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA1_0_SignatureInteger                                       300u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvSubCA2_0_SignatureInteger                                       300u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_ExtensionAuthorityInfoAccessMethodLocation               300u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA1_0_SignatureInteger                                       300u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleSubCA2_0_SignatureInteger                                       300u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SignatureInteger                                     305u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SignatureInteger                                   305u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SignatureInteger                                   305u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_CertificateSignatureAlgorithm                        305u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionAuthorityInfoAccessMethodLocation         305u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionAuthorityInfoAccessMethodLocation         305u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionSubjectInfoAccessOID                     305u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionAuthorityInfoAccessMethodLocation          305u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionAuthorityInfoAccessMethodLocation          305u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_CertificateSignatureAlgorithm                     305u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_CertificateSignatureAlgorithm                            305u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SignatureInteger                                     310u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_CertificateSignatureAlgorithm                      310u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_CertificateSignatureAlgorithm                      310u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionSubjectInfoAccessCritical                310u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_CertificateSignatureAlgorithm                       310u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_CertificateSignatureAlgorithm                       310u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SignatureInteger                                  310u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_VehicleCert_0_SignatureInteger                                         310u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_SignatureInteger                                   315u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_SignatureInteger                                   315u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionSubjectInfoAccess                        315u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_SignatureInteger                                    315u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SignatureInteger                                    315u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_CertificateSignatureAlgorithm                     320u 
#define KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SignatureInteger                                  325u 

#define KEYM_MAX_CERTIFICATE_MAX_LENGTH                                                             1600u
#define KEYM_MAX_NUM_CSR_EXTENSIONS                                                                 1u
#define KEYM_MAX_NUM_CERT_ELEMENTS                                                                  65u
#define KEYM_CSM_SYNC_SIGNATURE_VERIFY                                                              STD_ON
#define KEYM_CSM_ASYNC_SIGNATURE_VERIFY                                                             STD_ON
#define KEYM_OCSP_CERT_ID_CHECK_ENABLED                                                             STD_OFF
#define KEYM_MAX_NUM_EXTENSIONS                                                                     29u
#define KEYM_MAX_NUM_SUBJECT_NAME_COMPONENTS                                                        13u
#define KEYM_REMOTE_DISPATCHING_ENABLED                                                             STD_OFF
#define KEYM_REMOTE_REDIRECTION_ENABLED                                                             STD_OFF
#ifndef KEYM_DEV_ERROR_DETECT
#define KEYM_DEV_ERROR_DETECT STD_ON
#endif
#ifndef KEYM_DEV_ERROR_REPORT
#define KEYM_DEV_ERROR_REPORT STD_ON
#endif


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  KeyMPCDataSwitches  KeyM Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define KEYM_BASICCONSTRAINTSSTORAGE                                                                STD_OFF  /**< Deactivateable: 'KeyM_BasicConstraintsStorage' Reason: 'KeyM not configured for certificate extension validation.' */
#define KEYM_CREINFO                                                                                STD_OFF  /**< Deactivateable: 'KeyM_CREInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define KEYM_CRESTORAGEIDENDIDXOFCREINFO                                                            STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageIdEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGEIDLENGTHOFCREINFO                                                            STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageIdLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGEIDSTARTIDXOFCREINFO                                                          STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageIdStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGEISSUERENDIDXOFCREINFO                                                        STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageIssuerEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGEISSUERLENGTHOFCREINFO                                                        STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageIssuerLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGEISSUERSTARTIDXOFCREINFO                                                      STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageIssuerStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGEISSUERWRITTENLENGTHENDIDXOFCREINFO                                           STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageIssuerWrittenLengthEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGEISSUERWRITTENLENGTHLENGTHOFCREINFO                                           STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageIssuerWrittenLengthLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGEISSUERWRITTENLENGTHSTARTIDXOFCREINFO                                         STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageIssuerWrittenLengthStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGESERIALNUMBERENDIDXOFCREINFO                                                  STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageSerialNumberEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGESERIALNUMBERLENGTHOFCREINFO                                                  STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageSerialNumberLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGESERIALNUMBERSTARTIDXOFCREINFO                                                STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageSerialNumberStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGESERIALNUMBERWRITTENLENGTHENDIDXOFCREINFO                                     STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageSerialNumberWrittenLengthEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGESERIALNUMBERWRITTENLENGTHLENGTHOFCREINFO                                     STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageSerialNumberWrittenLengthLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGESERIALNUMBERWRITTENLENGTHSTARTIDXOFCREINFO                                   STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageSerialNumberWrittenLengthStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGE                                                                             STD_OFF  /**< Deactivateable: 'KeyM_CREStorage' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTELEMENTPATH                                                                        STD_ON
#define KEYM_CERTHASHSTORAGE                                                                        STD_OFF  /**< Deactivateable: 'KeyM_CertHashStorage' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTINFODATA                                                                           STD_OFF  /**< Deactivateable: 'KeyM_CertInfoData' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTPUBKEYHASHSTORAGE                                                                  STD_OFF  /**< Deactivateable: 'KeyM_CertPubKeyHashStorage' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTSTORAGE                                                                            STD_ON
#define KEYM_CERT_CERTINFO                                                                          STD_ON
#define KEYM_CERT_LEAFCERTSTOVERIFY                                                                 STD_ON
#define KEYM_CERT_LOCK                                                                              STD_ON
#define KEYM_CERT_STORAGETYPE                                                                       STD_ON
#define KEYM_CERT_VERIFYCHAIN                                                                       STD_ON
#define KEYM_CERTIFICATE                                                                            STD_ON
#define KEYM_CERTALGORITHMFAMILYOFCERTIFICATE                                                       STD_ON
#define KEYM_CERTALLOWFLEXIBLEELEMENTORDEROFCERTIFICATE                                             STD_ON
#define KEYM_CERTALLOWUNCONFIGUREDELEMENTSOFCERTIFICATE                                             STD_ON
#define KEYM_CERTATTRIBUTEHOLDERCERTREFIDXOFCERTIFICATE                                             STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertAttributeHolderCertRefIdx' Reason: 'the optional indirection is deactivated because CertificateUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTCSMHASHJOBREFOFCERTIFICATE                                                         STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertCsmHashJobRef' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmHashJobRef not configured.' */
#define KEYM_CERTCSMHASHJOBREFVALIDOFCERTIFICATE                                                    STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertCsmHashJobRefValid' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmHashJobRef not configured.' */
#define KEYM_CERTCSMSIGNATUREGENERATEJOBREFOFCERTIFICATE                                            STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertCsmSignatureGenerateJobRef' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmSignatureGenerateJobRef not configured.' */
#define KEYM_CERTCSMSIGNATUREGENERATEJOBREFVALIDOFCERTIFICATE                                       STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertCsmSignatureGenerateJobRefValid' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmSignatureGenerateJobRef not configured.' */
#define KEYM_CERTCSMSIGNATUREVERIFYJOBREFOFCERTIFICATE                                              STD_ON
#define KEYM_CERTCSMSIGNATUREVERIFYKEYREFOFCERTIFICATE                                              STD_ON
#define KEYM_CERTCSMSIGNATUREVERIFYKEYREFVALIDOFCERTIFICATE                                         STD_ON
#define KEYM_CERTFORMATTYPEOFCERTIFICATE                                                            STD_ON
#define KEYM_CERTHASHSTORAGEENDIDXOFCERTIFICATE                                                     STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertHashStorageEndIdx' Reason: 'the optional indirection is deactivated because CertHashStorageUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTHASHSTORAGELENGTHOFCERTIFICATE                                                     STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertHashStorageLength' Reason: 'the optional indirection is deactivated because CertHashStorageUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTHASHSTORAGESTARTIDXOFCERTIFICATE                                                   STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertHashStorageStartIdx' Reason: 'the optional indirection is deactivated because CertHashStorageUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTHASHSTORAGEUSEDOFCERTIFICATE                                                       STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertHashStorageUsed' Reason: 'the optional indirection is deactivated because CertHashStorageUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTHASHTYPEOFCERTIFICATE                                                              STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertHashType' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertHashType not configured.' */
#define KEYM_CERTHASHTYPEVALIDOFCERTIFICATE                                                         STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertHashTypeValid' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertHashType not configured.' */
#define KEYM_CERTINFODATAIDXOFCERTIFICATE                                                           STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertInfoDataIdx' Reason: 'the optional indirection is deactivated because CertInfoDataUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTINFODATAUSEDOFCERTIFICATE                                                          STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertInfoDataUsed' Reason: 'the optional indirection is deactivated because CertInfoDataUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTPERSISTINVALIDCERTOFCERTIFICATE                                                    STD_ON
#define KEYM_CERTPUBKEYHASHSTORAGEENDIDXOFCERTIFICATE                                               STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertPubKeyHashStorageEndIdx' Reason: 'the optional indirection is deactivated because CertPubKeyHashStorageUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTPUBKEYHASHSTORAGELENGTHOFCERTIFICATE                                               STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertPubKeyHashStorageLength' Reason: 'the optional indirection is deactivated because CertPubKeyHashStorageUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTPUBKEYHASHSTORAGESTARTIDXOFCERTIFICATE                                             STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertPubKeyHashStorageStartIdx' Reason: 'the optional indirection is deactivated because CertPubKeyHashStorageUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTPUBKEYHASHSTORAGEUSEDOFCERTIFICATE                                                 STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertPubKeyHashStorageUsed' Reason: 'the optional indirection is deactivated because CertPubKeyHashStorageUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTSTARTUPHANDLINGOFCERTIFICATE                                                       STD_ON
#define KEYM_CERTSTORAGEENDIDXOFCERTIFICATE                                                         STD_ON
#define KEYM_CERTSTORAGELENGTHOFCERTIFICATE                                                         STD_ON
#define KEYM_CERTSTORAGESTARTIDXOFCERTIFICATE                                                       STD_ON
#define KEYM_CERTSTORAGESTATUSENDIDXOFCERTIFICATE                                                   STD_ON
#define KEYM_CERTSTORAGESTATUSLENGTHOFCERTIFICATE                                                   STD_ON
#define KEYM_CERTSTORAGESTATUSSTARTIDXOFCERTIFICATE                                                 STD_ON
#define KEYM_CERTSTORAGEUSEDOFCERTIFICATE                                                           STD_ON
#define KEYM_CERTSTORAGEWRITTENLENGTHENDIDXOFCERTIFICATE                                            STD_ON
#define KEYM_CERTSTORAGEWRITTENLENGTHLENGTHOFCERTIFICATE                                            STD_ON
#define KEYM_CERTSTORAGEWRITTENLENGTHSTARTIDXOFCERTIFICATE                                          STD_ON
#define KEYM_CERTSTORAGEWRITTENLENGTHUSEDOFCERTIFICATE                                              STD_ON
#define KEYM_CERTTIMEBASEREFOFCERTIFICATE                                                           STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertTimebaseRef' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertTimebaseRef not configured.' */
#define KEYM_CERTTIMEBASEREFVALIDOFCERTIFICATE                                                      STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertTimebaseRefValid' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertTimebaseRef not configured.' */
#define KEYM_CERTUPPERHIERARCHICALCERTREFIDXOFCERTIFICATE                                           STD_ON
#define KEYM_CERTUPPERHIERARCHICALTYPEOFCERTIFICATE                                                 STD_ON
#define KEYM_CERTIFICATEELEMENTENDIDXOFCERTIFICATE                                                  STD_ON
#define KEYM_CERTIFICATEELEMENTLENGTHOFCERTIFICATE                                                  STD_ON
#define KEYM_CERTIFICATEELEMENTSTARTIDXOFCERTIFICATE                                                STD_ON
#define KEYM_CERTIFICATEELEMENTUSEDOFCERTIFICATE                                                    STD_ON
#define KEYM_CERTIFICATEGETCURRENTTIMECALLOUTIDXOFCERTIFICATE                                       STD_ON
#define KEYM_CERTIFICATEGETCURRENTTIMECALLOUTUSEDOFCERTIFICATE                                      STD_ON
#define KEYM_CERTIFICATEGROUPIDXOFCERTIFICATE                                                       STD_ON
#define KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE                                                      STD_ON
#define KEYM_CERTIFICATEINITVALUEINFOIDXOFCERTIFICATE                                               STD_ON
#define KEYM_CERTIFICATEINITVALUEINFOUSEDOFCERTIFICATE                                              STD_ON
#define KEYM_CERTIFICATENAMEENDIDXOFCERTIFICATE                                                     STD_ON
#define KEYM_CERTIFICATENAMELENGTHOFCERTIFICATE                                                     STD_ON
#define KEYM_CERTIFICATENAMESTARTIDXOFCERTIFICATE                                                   STD_ON
#define KEYM_CERTIFICATESETKEYCALLOUTIDXOFCERTIFICATE                                               STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateSetKeyCalloutIdx' Reason: 'the optional indirection is deactivated because CertificateSetKeyCalloutUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATESETKEYCALLOUTUSEDOFCERTIFICATE                                              STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateSetKeyCalloutUsed' Reason: 'the optional indirection is deactivated because CertificateSetKeyCalloutUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE                                                       STD_ON
#define KEYM_CERTIFICATEUSEDOFCERTIFICATE                                                           STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateUsed' Reason: 'the optional indirection is deactivated because CertificateUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHIDIDXOFCERTIFICATE                            STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateVerifyCallbackNotificationWithIdIdx' Reason: 'the optional indirection is deactivated because CertificateVerifyCallbackNotificationWithIdUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHIDUSEDOFCERTIFICATE                           STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateVerifyCallbackNotificationWithIdUsed' Reason: 'the optional indirection is deactivated because CertificateVerifyCallbackNotificationWithIdUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHOUTIDIDXOFCERTIFICATE                         STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateVerifyCallbackNotificationWithoutIdIdx' Reason: 'the optional indirection is deactivated because CertificateVerifyCallbackNotificationWithoutIdUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHOUTIDUSEDOFCERTIFICATE                        STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateVerifyCallbackNotificationWithoutIdUsed' Reason: 'the optional indirection is deactivated because CertificateVerifyCallbackNotificationWithoutIdUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CSMKEYTARGETREFOFCERTIFICATE                                                           STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CsmKeyTargetRef' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateCsmKeyTargetRef not configured.' */
#define KEYM_CSMKEYTARGETREFVALIDOFCERTIFICATE                                                      STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CsmKeyTargetRefValid' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateCsmKeyTargetRef not configured.' */
#define KEYM_KEYMCERTCSMHASHJOBREFASYNCOFCERTIFICATE                                                STD_ON
#define KEYM_KEYMCERTCSMSIGNATUREGENERATEJOBREFASYNCOFCERTIFICATE                                   STD_ON
#define KEYM_KEYMCERTCSMSIGNATUREVERIFYJOBREFASYNCOFCERTIFICATE                                     STD_ON
#define KEYM_MASKEDBITSOFCERTIFICATE                                                                STD_ON
#define KEYM_MAXLENGTHOFCERTIFICATE                                                                 STD_ON
#define KEYM_NVMBLOCKIDXOFCERTIFICATE                                                               STD_ON
#define KEYM_NVMBLOCKUSEDOFCERTIFICATE                                                              STD_ON
#define KEYM_OCSPIDXOFCERTIFICATE                                                                   STD_OFF  /**< Deactivateable: 'KeyM_Certificate.OCSPIdx' Reason: 'the optional indirection is deactivated because OCSPUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_OCSPUSEDOFCERTIFICATE                                                                  STD_OFF  /**< Deactivateable: 'KeyM_Certificate.OCSPUsed' Reason: 'the optional indirection is deactivated because OCSPUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_REMOTECERTIFICATEIDOFCERTIFICATE                                                       STD_ON
#define KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONIDXOFCERTIFICATE                                 STD_OFF  /**< Deactivateable: 'KeyM_Certificate.ServiceCertificateCallbackNotificationIdx' Reason: 'the optional indirection is deactivated because ServiceCertificateCallbackNotificationUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONUSEDOFCERTIFICATE                                STD_OFF  /**< Deactivateable: 'KeyM_Certificate.ServiceCertificateCallbackNotificationUsed' Reason: 'the optional indirection is deactivated because ServiceCertificateCallbackNotificationUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_SERVICECERTIFICATERTECALLBACKNOTIFICATION2211IDXOFCERTIFICATE                          STD_OFF  /**< Deactivateable: 'KeyM_Certificate.ServiceCertificateRteCallbackNotification2211Idx' Reason: 'the optional indirection is deactivated because ServiceCertificateRteCallbackNotification2211UsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_SERVICECERTIFICATERTECALLBACKNOTIFICATION2211USEDOFCERTIFICATE                         STD_OFF  /**< Deactivateable: 'KeyM_Certificate.ServiceCertificateRteCallbackNotification2211Used' Reason: 'the optional indirection is deactivated because ServiceCertificateRteCallbackNotification2211UsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_SERVICECERTIFICATERTECALLBACKNOTIFICATION440IDXOFCERTIFICATE                           STD_OFF  /**< Deactivateable: 'KeyM_Certificate.ServiceCertificateRteCallbackNotification440Idx' Reason: 'the optional indirection is deactivated because ServiceCertificateRteCallbackNotification440UsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_SERVICECERTIFICATERTECALLBACKNOTIFICATION440USEDOFCERTIFICATE                          STD_OFF  /**< Deactivateable: 'KeyM_Certificate.ServiceCertificateRteCallbackNotification440Used' Reason: 'the optional indirection is deactivated because ServiceCertificateRteCallbackNotification440UsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_SLOTREFIDXOFCERTIFICATE                                                                STD_ON
#define KEYM_STORAGEOFCERTIFICATE                                                                   STD_ON
#define KEYM_CERTIFICATECHAINMAXDEPTHOFGENERAL                                                      STD_ON
#define KEYM_CERTIFICATEELEMENT                                                                     STD_ON
#define KEYM_CERTELEMENTPATHENDIDXOFCERTIFICATEELEMENT                                              STD_ON
#define KEYM_CERTELEMENTPATHLENGTHOFCERTIFICATEELEMENT                                              STD_ON
#define KEYM_CERTELEMENTPATHSTARTIDXOFCERTIFICATEELEMENT                                            STD_ON
#define KEYM_CERTELEMENTPATHUSEDOFCERTIFICATEELEMENT                                                STD_ON
#define KEYM_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT                           STD_OFF  /**< Deactivateable: 'KeyM_CertificateElement.CertificateElementVerificationCalloutIdx' Reason: 'the optional indirection is deactivated because CertificateElementVerificationCalloutUsedOfCertificateElement is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEELEMENTVERIFICATIONCALLOUTUSEDOFCERTIFICATEELEMENT                          STD_OFF  /**< Deactivateable: 'KeyM_CertificateElement.CertificateElementVerificationCalloutUsed' Reason: 'the optional indirection is deactivated because CertificateElementVerificationCalloutUsedOfCertificateElement is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT                                                   STD_ON
#define KEYM_ELEMENTOIDLENGTHOFCERTIFICATEELEMENT                                                   STD_ON
#define KEYM_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT                                                 STD_ON
#define KEYM_ELEMENTOIDUSEDOFCERTIFICATEELEMENT                                                     STD_ON
#define KEYM_HASITERATIONOFCERTIFICATEELEMENT                                                       STD_ON
#define KEYM_IDOFCERTIFICATEELEMENT                                                                 STD_ON
#define KEYM_MASKEDBITSOFCERTIFICATEELEMENT                                                         STD_ON
#define KEYM_MAXLENGTHOFCERTIFICATEELEMENT                                                          STD_ON
#define KEYM_OBJECTTYPEOFCERTIFICATEELEMENT                                                         STD_ON
#define KEYM_OFSTRUCTUREOFCERTIFICATEELEMENT                                                        STD_ON
#define KEYM_OPTIONALOFCERTIFICATEELEMENT                                                           STD_ON
#define KEYM_CERTIFICATEELEMENTVERIFICATIONCALLOUT                                                  STD_OFF  /**< Deactivateable: 'KeyM_CertificateElementVerificationCallout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEEXTENSIONVALIDATIONENABLEDOFGENERAL                                         STD_ON
#define KEYM_CERTIFICATEGETCURRENTTIMECALLOUT                                                       STD_ON
#define KEYM_CERTIFICATEGROUP                                                                       STD_ON
#define KEYM_CERTIFICATEGROUPVERIFYCALLBACKNOTIFICATIONIDXOFCERTIFICATEGROUP                        STD_ON
#define KEYM_CERTIFICATEGROUPVERIFYCALLBACKNOTIFICATIONUSEDOFCERTIFICATEGROUP                       STD_ON
#define KEYM_CERTIFICATEREMOTEGROUPIDOFCERTIFICATEGROUP                                             STD_ON
#define KEYM_ELEMENTOIDPRIMARYENDIDXOFCERTIFICATEGROUP                                              STD_ON
#define KEYM_ELEMENTOIDPRIMARYLENGTHOFCERTIFICATEGROUP                                              STD_ON
#define KEYM_ELEMENTOIDPRIMARYSTARTIDXOFCERTIFICATEGROUP                                            STD_ON
#define KEYM_ELEMENTOIDPRIMARYUSEDOFCERTIFICATEGROUP                                                STD_ON
#define KEYM_ELEMENTOIDSECONDARYENDIDXOFCERTIFICATEGROUP                                            STD_ON
#define KEYM_ELEMENTOIDSECONDARYLENGTHOFCERTIFICATEGROUP                                            STD_ON
#define KEYM_ELEMENTOIDSECONDARYSTARTIDXOFCERTIFICATEGROUP                                          STD_ON
#define KEYM_ELEMENTOIDSECONDARYUSEDOFCERTIFICATEGROUP                                              STD_ON
#define KEYM_GROUPINDCERTENDIDXOFCERTIFICATEGROUP                                                   STD_ON
#define KEYM_GROUPINDCERTLENGTHOFCERTIFICATEGROUP                                                   STD_ON
#define KEYM_GROUPINDCERTSTARTIDXOFCERTIFICATEGROUP                                                 STD_ON
#define KEYM_GROUPINDISSUERENDIDXOFCERTIFICATEGROUP                                                 STD_ON
#define KEYM_GROUPINDISSUERLENGTHOFCERTIFICATEGROUP                                                 STD_ON
#define KEYM_GROUPINDISSUERSTARTIDXOFCERTIFICATEGROUP                                               STD_ON
#define KEYM_CERTIFICATEGROUPEXT                                                                    STD_ON
#define KEYM_CERTIFICATEGROUPENDIDXOFCERTIFICATEGROUPEXT                                            STD_ON
#define KEYM_CERTIFICATEGROUPLENGTHOFCERTIFICATEGROUPEXT                                            STD_ON
#define KEYM_CERTIFICATEGROUPSTARTIDXOFCERTIFICATEGROUPEXT                                          STD_ON
#define KEYM_CERTIFICATEGROUPVERIFYCALLBACKNOTIFICATION                                             STD_ON
#define KEYM_CERTIFICATEINITCALLOUT                                                                 STD_ON
#define KEYM_CERTIFICATEINITVALUE                                                                   STD_ON
#define KEYM_CERTIFICATEINITVALUEINFO                                                               STD_ON
#define KEYM_CERTIFICATEINITCALLOUTIDXOFCERTIFICATEINITVALUEINFO                                    STD_ON
#define KEYM_CERTIFICATEINITCALLOUTUSEDOFCERTIFICATEINITVALUEINFO                                   STD_ON
#define KEYM_CERTIFICATEINITVALUEENDIDXOFCERTIFICATEINITVALUEINFO                                   STD_ON
#define KEYM_CERTIFICATEINITVALUELENGTHOFCERTIFICATEINITVALUEINFO                                   STD_ON
#define KEYM_CERTIFICATEINITVALUESTARTIDXOFCERTIFICATEINITVALUEINFO                                 STD_ON
#define KEYM_CERTIFICATEINITVALUEUSEDOFCERTIFICATEINITVALUEINFO                                     STD_ON
#define KEYM_CERTIFICATEMANAGERENABLEDOFGENERAL                                                     STD_ON
#define KEYM_CERTIFICATENAME                                                                        STD_ON
#define KEYM_CERTIFICATESETKEYCALLOUT                                                               STD_OFF  /**< Deactivateable: 'KeyM_CertificateSetKeyCallout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATESIGNINGREQUESTENABLEDOFGENERAL                                              STD_ON
#define KEYM_CERTIFICATESLOT                                                                        STD_ON
#define KEYM_IDOFCERTIFICATESLOT                                                                    STD_ON
#define KEYM_MAXLENGTHOFCERTIFICATESLOT                                                             STD_ON
#define KEYM_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHID                                            STD_OFF  /**< Deactivateable: 'KeyM_CertificateVerifyCallbackNotificationWithId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHOUTID                                         STD_OFF  /**< Deactivateable: 'KeyM_CertificateVerifyCallbackNotificationWithoutId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_COMMONCERTDATA                                                                         STD_ON
#define KEYM_CRYPTOKEYPREPAREFUNCTIONENABLEDOFGENERAL                                               STD_ON
#define KEYM_CRYPTOKEYSTARTFINALIZEFUNCTIONENABLEDOFGENERAL                                         STD_ON
#define KEYM_CRYPTOKEYVERIFYASYNCMODEOFGENERAL                                                      STD_ON
#define KEYM_CRYPTOKEYVERIFYFUNCTIONENABLEDOFGENERAL                                                STD_ON
#define KEYM_CSMREMOTEINFOJOBREFOFGENERAL                                                           STD_OFF  /**< Deactivateable: 'KeyM_CsmRemoteInfoJobRefOfGeneral' Reason: 'Reference is not configured!' */
#define KEYM_CSMREMOTEINFOKEYREFOFGENERAL                                                           STD_OFF  /**< Deactivateable: 'KeyM_CsmRemoteInfoKeyRefOfGeneral' Reason: 'Reference is not configured!' */
#define KEYM_ELEMENTOID                                                                             STD_ON
#define KEYM_ELEMENTSTORAGEREF                                                                      STD_ON
#define KEYM_EXPECTEDCOMPATIBILITYVERSION                                                           STD_OFF  /**< Deactivateable: 'KeyM_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define KEYM_FINALMAGICNUMBER                                                                       STD_OFF  /**< Deactivateable: 'KeyM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define KEYM_GENERAL                                                                                STD_ON
#define KEYM_KEYMCSMREMOTEINFOJOBREFASYNCOFGENERAL                                                  STD_ON
#define KEYM_GENERATORCOMPATIBILITYVERSION                                                          STD_OFF  /**< Deactivateable: 'KeyM_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define KEYM_GROUPIND                                                                               STD_ON
#define KEYM_CERTIFICATEIDXOFGROUPIND                                                               STD_ON
#define KEYM_INITDATAHASHCODE                                                                       STD_OFF  /**< Deactivateable: 'KeyM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define KEYM_KEYCERTNAMEMAXLENGTHOFGENERAL                                                          STD_ON
#define KEYM_KEYUSAGESTORAGE                                                                        STD_OFF  /**< Deactivateable: 'KeyM_KeyUsageStorage' Reason: 'KeyM not configured for certificate extension validation.' */
#define KEYM_MAINFUNCTIONPERIODOFGENERAL                                                            STD_ON
#define KEYM_MAXLENGTHOFISSUERNAMEOFCRE                                                             STD_OFF  /**< Deactivateable: 'KeyM_MaxLengthOfIssuerNameOfCRE' Reason: 'Parameter is not configured!' */
#define KEYM_MAXLENGTHOFSERIALNUMBEROFCRE                                                           STD_OFF  /**< Deactivateable: 'KeyM_MaxLengthOfSerialNumberOfCRE' Reason: 'Parameter is not configured!' */
#define KEYM_MAXNUMBEROFENTRIESOFCRE                                                                STD_OFF  /**< Deactivateable: 'KeyM_MaxNumberOfEntriesOfCRE' Reason: 'Parameter is not configured!' */
#define KEYM_NVBLOCK_STATE                                                                          STD_ON
#define KEYM_NVMBLOCK                                                                               STD_ON
#define KEYM_CERTNVBLOCKPROCESSINGOFNVMBLOCK                                                        STD_ON
#define KEYM_DESCRIPTORREFOFNVMBLOCK                                                                STD_ON
#define KEYM_LENGTHOFNVMBLOCK                                                                       STD_ON
#define KEYM_OCSP                                                                                   STD_OFF  /**< Deactivateable: 'KeyM_OCSP' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define KEYM_CREPERSISTANCEENABLEDOFOCSP                                                            STD_OFF  /**< Deactivateable: 'KeyM_OCSP.CREPersistanceEnabled' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIDCHECKENABLEDOFOCSP                                                               STD_OFF  /**< Deactivateable: 'KeyM_OCSP.CertIdCheckEnabled' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEGROUPEXTUSEDOFOCSP                                                          STD_OFF  /**< Deactivateable: 'KeyM_OCSP.CertificateGroupExtUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEIDXOFOCSP                                                                   STD_OFF  /**< Deactivateable: 'KeyM_OCSP.CertificateIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_DELEGATEDRESPONDERREFIDXOFOCSP                                                         STD_OFF  /**< Deactivateable: 'KeyM_OCSP.DelegatedResponderRefIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_KEYMOCSPRESPONDERPUBKEYHASHCSMJOBREFASYNCOFOCSP                                        STD_OFF  /**< Deactivateable: 'KeyM_OCSP.KeyMOCSPResponderPubKeyHashCsmJobRefAsync' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_KEYMOCSPRESPONSECERTIDHASHCSMJOBREFASYNCOFOCSP                                         STD_OFF  /**< Deactivateable: 'KeyM_OCSP.KeyMOCSPResponseCertIdHashCsmJobRefAsync' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_RESPONDERPUBKEYHASHCSMJOBREFOFOCSP                                                     STD_OFF  /**< Deactivateable: 'KeyM_OCSP.ResponderPubKeyHashCsmJobRef' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMOCSP/KeyMOCSPResponderPubKeyHashCsmJobRef not configured.' */
#define KEYM_RESPONDERPUBKEYHASHCSMJOBREFVALIDOFOCSP                                                STD_OFF  /**< Deactivateable: 'KeyM_OCSP.ResponderPubKeyHashCsmJobRefValid' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMOCSP/KeyMOCSPResponderPubKeyHashCsmJobRef not configured.' */
#define KEYM_RESPONSECERTIDHASHCSMJOBREFOFOCSP                                                      STD_OFF  /**< Deactivateable: 'KeyM_OCSP.ResponseCertIdHashCsmJobRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_OCSPMAXLENGTHOFCERTIDHASHOFOCSPFORMAT                                                  STD_OFF  /**< Deactivateable: 'KeyM_OCSPMaxLengthOfCertIdHashOfOCSPFormat' Reason: 'Parameter is not configured!' */
#define KEYM_OCSPMAXLENGTHOFDISTINGUISHEDNAMEOFOCSPFORMAT                                           STD_OFF  /**< Deactivateable: 'KeyM_OCSPMaxLengthOfDistinguishedNameOfOCSPFormat' Reason: 'Parameter is not configured!' */
#define KEYM_OCSPRESPONSEVALIDITYPERIODOFGENERAL                                                    STD_OFF  /**< Deactivateable: 'KeyM_OCSPResponseValidityPeriodOfGeneral' Reason: 'Parameter is not configured!' */
#define KEYM_PARSEMAXNESTINGLEVELOFGENERAL                                                          STD_ON
#define KEYM_REMOTECREENABLEDOFPUBLISHEDINFORMATION                                                 STD_OFF  /**< Deactivateable: 'KeyM_RemoteCREEnabledOfPublishedInformation' Reason: 'Parameter is not configured!' */
#define KEYM_REMOTEOCSPENABLEDOFPUBLISHEDINFORMATION                                                STD_OFF  /**< Deactivateable: 'KeyM_RemoteOCSPEnabledOfPublishedInformation' Reason: 'Parameter is not configured!' */
#define KEYM_SERVICECERTIFICATECALLBACKNOTIFICATION                                                 STD_OFF  /**< Deactivateable: 'KeyM_ServiceCertificateCallbackNotification' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_SERVICECERTIFICATEFUNCTIONENABLEDOFGENERAL                                             STD_ON
#define KEYM_SERVICECERTIFICATERTECALLBACKNOTIFICATION2211                                          STD_OFF  /**< Deactivateable: 'KeyM_ServiceCertificateRteCallbackNotification2211' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_SERVICECERTIFICATERTECALLBACKNOTIFICATION440                                           STD_OFF  /**< Deactivateable: 'KeyM_ServiceCertificateRteCallbackNotification440' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_SIZEOFCERTELEMENTPATH                                                                  STD_ON
#define KEYM_SIZEOFCERTSTORAGE                                                                      STD_ON
#define KEYM_SIZEOFCERT_CERTINFO                                                                    STD_ON
#define KEYM_SIZEOFCERT_LEAFCERTSTOVERIFY                                                           STD_ON
#define KEYM_SIZEOFCERT_LOCK                                                                        STD_ON
#define KEYM_SIZEOFCERT_STORAGETYPE                                                                 STD_ON
#define KEYM_SIZEOFCERT_VERIFYCHAIN                                                                 STD_ON
#define KEYM_SIZEOFCERTIFICATE                                                                      STD_ON
#define KEYM_SIZEOFCERTIFICATEELEMENT                                                               STD_ON
#define KEYM_SIZEOFCERTIFICATEGETCURRENTTIMECALLOUT                                                 STD_ON
#define KEYM_SIZEOFCERTIFICATEGROUP                                                                 STD_ON
#define KEYM_SIZEOFCERTIFICATEGROUPEXT                                                              STD_ON
#define KEYM_SIZEOFCERTIFICATEGROUPVERIFYCALLBACKNOTIFICATION                                       STD_ON
#define KEYM_SIZEOFCERTIFICATEINITCALLOUT                                                           STD_ON
#define KEYM_SIZEOFCERTIFICATEINITVALUE                                                             STD_ON
#define KEYM_SIZEOFCERTIFICATEINITVALUEINFO                                                         STD_ON
#define KEYM_SIZEOFCERTIFICATENAME                                                                  STD_ON
#define KEYM_SIZEOFCERTIFICATESLOT                                                                  STD_ON
#define KEYM_SIZEOFCOMMONCERTDATA                                                                   STD_ON
#define KEYM_SIZEOFELEMENTOID                                                                       STD_ON
#define KEYM_SIZEOFELEMENTSTORAGEREF                                                                STD_ON
#define KEYM_SIZEOFGENERAL                                                                          STD_ON
#define KEYM_SIZEOFGROUPIND                                                                         STD_ON
#define KEYM_SIZEOFNVBLOCK_STATE                                                                    STD_ON
#define KEYM_SIZEOFNVMBLOCK                                                                         STD_ON
#define KEYM_SIZEOFSLOTOWNER                                                                        STD_ON
#define KEYM_SLOTOWNER                                                                              STD_ON
#define KEYM_VERSIONINFOAPIOFGENERAL                                                                STD_ON
#define KEYM_PCCONFIG                                                                               STD_ON
#define KEYM_CERTELEMENTPATHOFPCCONFIG                                                              STD_ON
#define KEYM_CERTSTORAGEOFPCCONFIG                                                                  STD_ON
#define KEYM_CERT_CERTINFOOFPCCONFIG                                                                STD_ON
#define KEYM_CERT_LEAFCERTSTOVERIFYOFPCCONFIG                                                       STD_ON
#define KEYM_CERT_LOCKOFPCCONFIG                                                                    STD_ON
#define KEYM_CERT_STORAGETYPEOFPCCONFIG                                                             STD_ON
#define KEYM_CERT_VERIFYCHAINOFPCCONFIG                                                             STD_ON
#define KEYM_CERTIFICATECHAINMAXDEPTHOFGENERALOFPCCONFIG                                            STD_ON
#define KEYM_CERTIFICATEELEMENTOFPCCONFIG                                                           STD_ON
#define KEYM_CERTIFICATEEXTENSIONVALIDATIONENABLEDOFGENERALOFPCCONFIG                               STD_ON
#define KEYM_CERTIFICATEGETCURRENTTIMECALLOUTOFPCCONFIG                                             STD_ON
#define KEYM_CERTIFICATEGROUPEXTOFPCCONFIG                                                          STD_ON
#define KEYM_CERTIFICATEGROUPOFPCCONFIG                                                             STD_ON
#define KEYM_CERTIFICATEGROUPVERIFYCALLBACKNOTIFICATIONOFPCCONFIG                                   STD_ON
#define KEYM_CERTIFICATEINITCALLOUTOFPCCONFIG                                                       STD_ON
#define KEYM_CERTIFICATEINITVALUEINFOOFPCCONFIG                                                     STD_ON
#define KEYM_CERTIFICATEINITVALUEOFPCCONFIG                                                         STD_ON
#define KEYM_CERTIFICATEMANAGERENABLEDOFGENERALOFPCCONFIG                                           STD_ON
#define KEYM_CERTIFICATENAMEOFPCCONFIG                                                              STD_ON
#define KEYM_CERTIFICATEOFPCCONFIG                                                                  STD_ON
#define KEYM_CERTIFICATESIGNINGREQUESTENABLEDOFGENERALOFPCCONFIG                                    STD_ON
#define KEYM_CERTIFICATESLOTOFPCCONFIG                                                              STD_ON
#define KEYM_COMMONCERTDATAOFPCCONFIG                                                               STD_ON
#define KEYM_CRYPTOKEYPREPAREFUNCTIONENABLEDOFGENERALOFPCCONFIG                                     STD_ON
#define KEYM_CRYPTOKEYSTARTFINALIZEFUNCTIONENABLEDOFGENERALOFPCCONFIG                               STD_ON
#define KEYM_CRYPTOKEYVERIFYASYNCMODEOFGENERALOFPCCONFIG                                            STD_ON
#define KEYM_CRYPTOKEYVERIFYFUNCTIONENABLEDOFGENERALOFPCCONFIG                                      STD_ON
#define KEYM_CSMREMOTEINFOJOBREFOFGENERALOFPCCONFIG                                                 STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.CsmRemoteInfoJobRefOfGeneral' Reason: 'Reference is not configured!' */
#define KEYM_CSMREMOTEINFOKEYREFOFGENERALOFPCCONFIG                                                 STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.CsmRemoteInfoKeyRefOfGeneral' Reason: 'Reference is not configured!' */
#define KEYM_ELEMENTOIDOFPCCONFIG                                                                   STD_ON
#define KEYM_ELEMENTSTORAGEREFOFPCCONFIG                                                            STD_ON
#define KEYM_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                                 STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define KEYM_FINALMAGICNUMBEROFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define KEYM_GENERALOFPCCONFIG                                                                      STD_ON
#define KEYM_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                                STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define KEYM_GROUPINDOFPCCONFIG                                                                     STD_ON
#define KEYM_INITDATAHASHCODEOFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define KEYM_KEYCERTNAMEMAXLENGTHOFGENERALOFPCCONFIG                                                STD_ON
#define KEYM_MAINFUNCTIONPERIODOFGENERALOFPCCONFIG                                                  STD_ON
#define KEYM_MAXLENGTHOFISSUERNAMEOFCREOFPCCONFIG                                                   STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.MaxLengthOfIssuerNameOfCRE' Reason: 'Parameter is not configured!' */
#define KEYM_MAXLENGTHOFSERIALNUMBEROFCREOFPCCONFIG                                                 STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.MaxLengthOfSerialNumberOfCRE' Reason: 'Parameter is not configured!' */
#define KEYM_MAXNUMBEROFENTRIESOFCREOFPCCONFIG                                                      STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.MaxNumberOfEntriesOfCRE' Reason: 'Parameter is not configured!' */
#define KEYM_NVBLOCK_STATEOFPCCONFIG                                                                STD_ON
#define KEYM_NVMBLOCKOFPCCONFIG                                                                     STD_ON
#define KEYM_OCSPMAXLENGTHOFCERTIDHASHOFOCSPFORMATOFPCCONFIG                                        STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.OCSPMaxLengthOfCertIdHashOfOCSPFormat' Reason: 'Parameter is not configured!' */
#define KEYM_OCSPMAXLENGTHOFDISTINGUISHEDNAMEOFOCSPFORMATOFPCCONFIG                                 STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.OCSPMaxLengthOfDistinguishedNameOfOCSPFormat' Reason: 'Parameter is not configured!' */
#define KEYM_OCSPRESPONSEVALIDITYPERIODOFGENERALOFPCCONFIG                                          STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.OCSPResponseValidityPeriodOfGeneral' Reason: 'Parameter is not configured!' */
#define KEYM_PARSEMAXNESTINGLEVELOFGENERALOFPCCONFIG                                                STD_ON
#define KEYM_REMOTECREENABLEDOFPUBLISHEDINFORMATIONOFPCCONFIG                                       STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.RemoteCREEnabledOfPublishedInformation' Reason: 'Parameter is not configured!' */
#define KEYM_REMOTEOCSPENABLEDOFPUBLISHEDINFORMATIONOFPCCONFIG                                      STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.RemoteOCSPEnabledOfPublishedInformation' Reason: 'Parameter is not configured!' */
#define KEYM_SERVICECERTIFICATEFUNCTIONENABLEDOFGENERALOFPCCONFIG                                   STD_ON
#define KEYM_SIZEOFCERTELEMENTPATHOFPCCONFIG                                                        STD_ON
#define KEYM_SIZEOFCERTSTORAGEOFPCCONFIG                                                            STD_ON
#define KEYM_SIZEOFCERT_CERTINFOOFPCCONFIG                                                          STD_ON
#define KEYM_SIZEOFCERT_LEAFCERTSTOVERIFYOFPCCONFIG                                                 STD_ON
#define KEYM_SIZEOFCERT_LOCKOFPCCONFIG                                                              STD_ON
#define KEYM_SIZEOFCERT_STORAGETYPEOFPCCONFIG                                                       STD_ON
#define KEYM_SIZEOFCERT_VERIFYCHAINOFPCCONFIG                                                       STD_ON
#define KEYM_SIZEOFCERTIFICATEELEMENTOFPCCONFIG                                                     STD_ON
#define KEYM_SIZEOFCERTIFICATEGETCURRENTTIMECALLOUTOFPCCONFIG                                       STD_ON
#define KEYM_SIZEOFCERTIFICATEGROUPEXTOFPCCONFIG                                                    STD_ON
#define KEYM_SIZEOFCERTIFICATEGROUPOFPCCONFIG                                                       STD_ON
#define KEYM_SIZEOFCERTIFICATEGROUPVERIFYCALLBACKNOTIFICATIONOFPCCONFIG                             STD_ON
#define KEYM_SIZEOFCERTIFICATEINITCALLOUTOFPCCONFIG                                                 STD_ON
#define KEYM_SIZEOFCERTIFICATEINITVALUEINFOOFPCCONFIG                                               STD_ON
#define KEYM_SIZEOFCERTIFICATEINITVALUEOFPCCONFIG                                                   STD_ON
#define KEYM_SIZEOFCERTIFICATENAMEOFPCCONFIG                                                        STD_ON
#define KEYM_SIZEOFCERTIFICATEOFPCCONFIG                                                            STD_ON
#define KEYM_SIZEOFCERTIFICATESLOTOFPCCONFIG                                                        STD_ON
#define KEYM_SIZEOFCOMMONCERTDATAOFPCCONFIG                                                         STD_ON
#define KEYM_SIZEOFELEMENTOIDOFPCCONFIG                                                             STD_ON
#define KEYM_SIZEOFELEMENTSTORAGEREFOFPCCONFIG                                                      STD_ON
#define KEYM_SIZEOFGENERALOFPCCONFIG                                                                STD_ON
#define KEYM_SIZEOFGROUPINDOFPCCONFIG                                                               STD_ON
#define KEYM_SIZEOFNVBLOCK_STATEOFPCCONFIG                                                          STD_ON
#define KEYM_SIZEOFNVMBLOCKOFPCCONFIG                                                               STD_ON
#define KEYM_SIZEOFSLOTOWNEROFPCCONFIG                                                              STD_ON
#define KEYM_SLOTOWNEROFPCCONFIG                                                                    STD_ON
#define KEYM_VERSIONINFOAPIOFGENERALOFPCCONFIG                                                      STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCMinNumericValueDefines  KeyM Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define KEYM_MIN_CERTSTORAGE                                                                        0u
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCMaxNumericValueDefines  KeyM Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define KEYM_MAX_CERTSTORAGE                                                                        255u
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCNoReferenceDefines  KeyM No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define KEYM_NO_CERTSTORAGEENDIDXOFCERTIFICATE                                                      65535u
#define KEYM_NO_CERTSTORAGESTARTIDXOFCERTIFICATE                                                    65535u
#define KEYM_NO_CERTSTORAGEWRITTENLENGTHENDIDXOFCERTIFICATE                                         65535u
#define KEYM_NO_CERTSTORAGEWRITTENLENGTHSTARTIDXOFCERTIFICATE                                       65535u
#define KEYM_NO_CERTIFICATEELEMENTENDIDXOFCERTIFICATE                                               65535u
#define KEYM_NO_CERTIFICATEELEMENTSTARTIDXOFCERTIFICATE                                             65535u
#define KEYM_NO_CERTIFICATEGETCURRENTTIMECALLOUTIDXOFCERTIFICATE                                    255u
#define KEYM_NO_CERTIFICATEGROUPIDXOFCERTIFICATE                                                    255u
#define KEYM_NO_CERTIFICATEINITVALUEINFOIDXOFCERTIFICATE                                            255u
#define KEYM_NO_NVMBLOCKIDXOFCERTIFICATE                                                            255u
#define KEYM_NO_SLOTREFIDXOFCERTIFICATE                                                             255u
#define KEYM_NO_CERTELEMENTPATHENDIDXOFCERTIFICATEELEMENT                                           65535u
#define KEYM_NO_CERTELEMENTPATHSTARTIDXOFCERTIFICATEELEMENT                                         65535u
#define KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT                                                255u
#define KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT                                              255u
#define KEYM_NO_CERTIFICATEGROUPVERIFYCALLBACKNOTIFICATIONIDXOFCERTIFICATEGROUP                     255u
#define KEYM_NO_ELEMENTOIDPRIMARYENDIDXOFCERTIFICATEGROUP                                           255u
#define KEYM_NO_ELEMENTOIDPRIMARYSTARTIDXOFCERTIFICATEGROUP                                         255u
#define KEYM_NO_ELEMENTOIDSECONDARYENDIDXOFCERTIFICATEGROUP                                         255u
#define KEYM_NO_ELEMENTOIDSECONDARYSTARTIDXOFCERTIFICATEGROUP                                       255u
#define KEYM_NO_CERTIFICATEINITVALUE                                                                255u
#define KEYM_NO_CERTIFICATEINITCALLOUTIDXOFCERTIFICATEINITVALUEINFO                                 255u
#define KEYM_NO_CERTIFICATEINITVALUEENDIDXOFCERTIFICATEINITVALUEINFO                                65535u
#define KEYM_NO_CERTIFICATEINITVALUESTARTIDXOFCERTIFICATEINITVALUEINFO                              65535u
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCMaskedBitDefines  KeyM Masked Bit Defines (PRE_COMPILE)
  \brief  These defines are masks to extract packed boolean data.
  \{
*/ 
#define KEYM_CERTALLOWFLEXIBLEELEMENTORDEROFCERTIFICATE_MASK                                        0x40u
#define KEYM_CERTALLOWUNCONFIGUREDELEMENTSOFCERTIFICATE_MASK                                        0x20u
#define KEYM_CERTCSMSIGNATUREVERIFYKEYREFVALIDOFCERTIFICATE_MASK                                    0x10u
#define KEYM_CERTPERSISTINVALIDCERTOFCERTIFICATE_MASK                                               0x08u
#define KEYM_KEYMCERTCSMHASHJOBREFASYNCOFCERTIFICATE_MASK                                           0x04u
#define KEYM_KEYMCERTCSMSIGNATUREGENERATEJOBREFASYNCOFCERTIFICATE_MASK                              0x02u
#define KEYM_KEYMCERTCSMSIGNATUREVERIFYJOBREFASYNCOFCERTIFICATE_MASK                                0x01u
#define KEYM_HASITERATIONOFCERTIFICATEELEMENT_MASK                                                  0x02u
#define KEYM_OPTIONALOFCERTIFICATEELEMENT_MASK                                                      0x01u
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCIsReducedToDefineDefines  KeyM Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define KEYM_ISDEF_CERTELEMENTPATH                                                                  STD_OFF
#define KEYM_ISDEF_CERTALGORITHMFAMILYOFCERTIFICATE                                                 STD_OFF
#define KEYM_ISDEF_CERTALLOWFLEXIBLEELEMENTORDEROFCERTIFICATE                                       STD_OFF
#define KEYM_ISDEF_CERTALLOWUNCONFIGUREDELEMENTSOFCERTIFICATE                                       STD_OFF
#define KEYM_ISDEF_CERTCSMSIGNATUREVERIFYJOBREFOFCERTIFICATE                                        STD_OFF
#define KEYM_ISDEF_CERTCSMSIGNATUREVERIFYKEYREFOFCERTIFICATE                                        STD_OFF
#define KEYM_ISDEF_CERTCSMSIGNATUREVERIFYKEYREFVALIDOFCERTIFICATE                                   STD_OFF
#define KEYM_ISDEF_CERTFORMATTYPEOFCERTIFICATE                                                      STD_OFF
#define KEYM_ISDEF_CERTPERSISTINVALIDCERTOFCERTIFICATE                                              STD_OFF
#define KEYM_ISDEF_CERTSTARTUPHANDLINGOFCERTIFICATE                                                 STD_OFF
#define KEYM_ISDEF_CERTSTORAGEENDIDXOFCERTIFICATE                                                   STD_OFF
#define KEYM_ISDEF_CERTSTORAGELENGTHOFCERTIFICATE                                                   STD_OFF
#define KEYM_ISDEF_CERTSTORAGESTARTIDXOFCERTIFICATE                                                 STD_OFF
#define KEYM_ISDEF_CERTSTORAGESTATUSENDIDXOFCERTIFICATE                                             STD_OFF
#define KEYM_ISDEF_CERTSTORAGESTATUSLENGTHOFCERTIFICATE                                             STD_OFF
#define KEYM_ISDEF_CERTSTORAGESTATUSSTARTIDXOFCERTIFICATE                                           STD_OFF
#define KEYM_ISDEF_CERTSTORAGEUSEDOFCERTIFICATE                                                     STD_OFF
#define KEYM_ISDEF_CERTSTORAGEWRITTENLENGTHENDIDXOFCERTIFICATE                                      STD_OFF
#define KEYM_ISDEF_CERTSTORAGEWRITTENLENGTHLENGTHOFCERTIFICATE                                      STD_OFF
#define KEYM_ISDEF_CERTSTORAGEWRITTENLENGTHSTARTIDXOFCERTIFICATE                                    STD_OFF
#define KEYM_ISDEF_CERTSTORAGEWRITTENLENGTHUSEDOFCERTIFICATE                                        STD_OFF
#define KEYM_ISDEF_CERTUPPERHIERARCHICALCERTREFIDXOFCERTIFICATE                                     STD_OFF
#define KEYM_ISDEF_CERTUPPERHIERARCHICALTYPEOFCERTIFICATE                                           STD_OFF
#define KEYM_ISDEF_CERTIFICATEELEMENTENDIDXOFCERTIFICATE                                            STD_OFF
#define KEYM_ISDEF_CERTIFICATEELEMENTLENGTHOFCERTIFICATE                                            STD_OFF
#define KEYM_ISDEF_CERTIFICATEELEMENTSTARTIDXOFCERTIFICATE                                          STD_OFF
#define KEYM_ISDEF_CERTIFICATEELEMENTUSEDOFCERTIFICATE                                              STD_OFF
#define KEYM_ISDEF_CERTIFICATEGETCURRENTTIMECALLOUTIDXOFCERTIFICATE                                 STD_OFF
#define KEYM_ISDEF_CERTIFICATEGETCURRENTTIMECALLOUTUSEDOFCERTIFICATE                                STD_OFF
#define KEYM_ISDEF_CERTIFICATEGROUPIDXOFCERTIFICATE                                                 STD_OFF
#define KEYM_ISDEF_CERTIFICATEGROUPUSEDOFCERTIFICATE                                                STD_OFF
#define KEYM_ISDEF_CERTIFICATEINITVALUEINFOIDXOFCERTIFICATE                                         STD_OFF
#define KEYM_ISDEF_CERTIFICATEINITVALUEINFOUSEDOFCERTIFICATE                                        STD_OFF
#define KEYM_ISDEF_CERTIFICATENAMEENDIDXOFCERTIFICATE                                               STD_OFF
#define KEYM_ISDEF_CERTIFICATENAMELENGTHOFCERTIFICATE                                               STD_OFF
#define KEYM_ISDEF_CERTIFICATENAMESTARTIDXOFCERTIFICATE                                             STD_OFF
#define KEYM_ISDEF_CERTIFICATESLOTUSEDOFCERTIFICATE                                                 STD_OFF
#define KEYM_ISDEF_KEYMCERTCSMHASHJOBREFASYNCOFCERTIFICATE                                          STD_OFF
#define KEYM_ISDEF_KEYMCERTCSMSIGNATUREGENERATEJOBREFASYNCOFCERTIFICATE                             STD_OFF
#define KEYM_ISDEF_KEYMCERTCSMSIGNATUREVERIFYJOBREFASYNCOFCERTIFICATE                               STD_OFF
#define KEYM_ISDEF_MASKEDBITSOFCERTIFICATE                                                          STD_OFF
#define KEYM_ISDEF_MAXLENGTHOFCERTIFICATE                                                           STD_OFF
#define KEYM_ISDEF_NVMBLOCKIDXOFCERTIFICATE                                                         STD_OFF
#define KEYM_ISDEF_NVMBLOCKUSEDOFCERTIFICATE                                                        STD_OFF
#define KEYM_ISDEF_REMOTECERTIFICATEIDOFCERTIFICATE                                                 STD_OFF
#define KEYM_ISDEF_SLOTREFIDXOFCERTIFICATE                                                          STD_OFF
#define KEYM_ISDEF_STORAGEOFCERTIFICATE                                                             STD_OFF
#define KEYM_ISDEF_CERTELEMENTPATHENDIDXOFCERTIFICATEELEMENT                                        STD_OFF
#define KEYM_ISDEF_CERTELEMENTPATHLENGTHOFCERTIFICATEELEMENT                                        STD_OFF
#define KEYM_ISDEF_CERTELEMENTPATHSTARTIDXOFCERTIFICATEELEMENT                                      STD_OFF
#define KEYM_ISDEF_CERTELEMENTPATHUSEDOFCERTIFICATEELEMENT                                          STD_OFF
#define KEYM_ISDEF_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT                                             STD_OFF
#define KEYM_ISDEF_ELEMENTOIDLENGTHOFCERTIFICATEELEMENT                                             STD_OFF
#define KEYM_ISDEF_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT                                           STD_OFF
#define KEYM_ISDEF_ELEMENTOIDUSEDOFCERTIFICATEELEMENT                                               STD_OFF
#define KEYM_ISDEF_HASITERATIONOFCERTIFICATEELEMENT                                                 STD_OFF
#define KEYM_ISDEF_IDOFCERTIFICATEELEMENT                                                           STD_OFF
#define KEYM_ISDEF_MASKEDBITSOFCERTIFICATEELEMENT                                                   STD_OFF
#define KEYM_ISDEF_MAXLENGTHOFCERTIFICATEELEMENT                                                    STD_OFF
#define KEYM_ISDEF_OBJECTTYPEOFCERTIFICATEELEMENT                                                   STD_OFF
#define KEYM_ISDEF_OFSTRUCTUREOFCERTIFICATEELEMENT                                                  STD_OFF
#define KEYM_ISDEF_OPTIONALOFCERTIFICATEELEMENT                                                     STD_OFF
#define KEYM_ISDEF_CERTIFICATEGETCURRENTTIMECALLOUT                                                 STD_OFF
#define KEYM_ISDEF_CERTIFICATEGROUPVERIFYCALLBACKNOTIFICATIONIDXOFCERTIFICATEGROUP                  STD_OFF
#define KEYM_ISDEF_CERTIFICATEGROUPVERIFYCALLBACKNOTIFICATIONUSEDOFCERTIFICATEGROUP                 STD_OFF
#define KEYM_ISDEF_CERTIFICATEREMOTEGROUPIDOFCERTIFICATEGROUP                                       STD_OFF
#define KEYM_ISDEF_ELEMENTOIDPRIMARYENDIDXOFCERTIFICATEGROUP                                        STD_OFF
#define KEYM_ISDEF_ELEMENTOIDPRIMARYLENGTHOFCERTIFICATEGROUP                                        STD_OFF
#define KEYM_ISDEF_ELEMENTOIDPRIMARYSTARTIDXOFCERTIFICATEGROUP                                      STD_OFF
#define KEYM_ISDEF_ELEMENTOIDPRIMARYUSEDOFCERTIFICATEGROUP                                          STD_OFF
#define KEYM_ISDEF_ELEMENTOIDSECONDARYENDIDXOFCERTIFICATEGROUP                                      STD_OFF
#define KEYM_ISDEF_ELEMENTOIDSECONDARYLENGTHOFCERTIFICATEGROUP                                      STD_OFF
#define KEYM_ISDEF_ELEMENTOIDSECONDARYSTARTIDXOFCERTIFICATEGROUP                                    STD_OFF
#define KEYM_ISDEF_ELEMENTOIDSECONDARYUSEDOFCERTIFICATEGROUP                                        STD_OFF
#define KEYM_ISDEF_GROUPINDCERTENDIDXOFCERTIFICATEGROUP                                             STD_OFF
#define KEYM_ISDEF_GROUPINDCERTLENGTHOFCERTIFICATEGROUP                                             STD_OFF
#define KEYM_ISDEF_GROUPINDCERTSTARTIDXOFCERTIFICATEGROUP                                           STD_OFF
#define KEYM_ISDEF_GROUPINDISSUERENDIDXOFCERTIFICATEGROUP                                           STD_OFF
#define KEYM_ISDEF_GROUPINDISSUERLENGTHOFCERTIFICATEGROUP                                           STD_OFF
#define KEYM_ISDEF_GROUPINDISSUERSTARTIDXOFCERTIFICATEGROUP                                         STD_OFF
#define KEYM_ISDEF_CERTIFICATEGROUPENDIDXOFCERTIFICATEGROUPEXT                                      STD_OFF
#define KEYM_ISDEF_CERTIFICATEGROUPLENGTHOFCERTIFICATEGROUPEXT                                      STD_OFF
#define KEYM_ISDEF_CERTIFICATEGROUPSTARTIDXOFCERTIFICATEGROUPEXT                                    STD_OFF
#define KEYM_ISDEF_CERTIFICATEGROUPVERIFYCALLBACKNOTIFICATION                                       STD_OFF
#define KEYM_ISDEF_CERTIFICATEINITCALLOUT                                                           STD_OFF
#define KEYM_ISDEF_CERTIFICATEINITVALUE                                                             STD_OFF
#define KEYM_ISDEF_CERTIFICATEINITCALLOUTIDXOFCERTIFICATEINITVALUEINFO                              STD_OFF
#define KEYM_ISDEF_CERTIFICATEINITCALLOUTUSEDOFCERTIFICATEINITVALUEINFO                             STD_OFF
#define KEYM_ISDEF_CERTIFICATEINITVALUEENDIDXOFCERTIFICATEINITVALUEINFO                             STD_OFF
#define KEYM_ISDEF_CERTIFICATEINITVALUELENGTHOFCERTIFICATEINITVALUEINFO                             STD_OFF
#define KEYM_ISDEF_CERTIFICATEINITVALUESTARTIDXOFCERTIFICATEINITVALUEINFO                           STD_OFF
#define KEYM_ISDEF_CERTIFICATEINITVALUEUSEDOFCERTIFICATEINITVALUEINFO                               STD_OFF
#define KEYM_ISDEF_CERTIFICATENAME                                                                  STD_OFF
#define KEYM_ISDEF_IDOFCERTIFICATESLOT                                                              STD_OFF
#define KEYM_ISDEF_MAXLENGTHOFCERTIFICATESLOT                                                       STD_OFF
#define KEYM_ISDEF_ELEMENTOID                                                                       STD_OFF
#define KEYM_ISDEF_KEYMCSMREMOTEINFOJOBREFASYNCOFGENERAL                                            STD_OFF
#define KEYM_ISDEF_CERTIFICATEIDXOFGROUPIND                                                         STD_OFF
#define KEYM_ISDEF_CERTNVBLOCKPROCESSINGOFNVMBLOCK                                                  STD_OFF
#define KEYM_ISDEF_DESCRIPTORREFOFNVMBLOCK                                                          STD_OFF
#define KEYM_ISDEF_LENGTHOFNVMBLOCK                                                                 STD_OFF
#define KEYM_ISDEF_CERTELEMENTPATHOFPCCONFIG                                                        STD_ON
#define KEYM_ISDEF_CERTSTORAGEOFPCCONFIG                                                            STD_ON
#define KEYM_ISDEF_CERT_CERTINFOOFPCCONFIG                                                          STD_ON
#define KEYM_ISDEF_CERT_LEAFCERTSTOVERIFYOFPCCONFIG                                                 STD_ON
#define KEYM_ISDEF_CERT_LOCKOFPCCONFIG                                                              STD_ON
#define KEYM_ISDEF_CERT_STORAGETYPEOFPCCONFIG                                                       STD_ON
#define KEYM_ISDEF_CERT_VERIFYCHAINOFPCCONFIG                                                       STD_ON
#define KEYM_ISDEF_CERTIFICATEELEMENTOFPCCONFIG                                                     STD_ON
#define KEYM_ISDEF_CERTIFICATEGETCURRENTTIMECALLOUTOFPCCONFIG                                       STD_ON
#define KEYM_ISDEF_CERTIFICATEGROUPEXTOFPCCONFIG                                                    STD_ON
#define KEYM_ISDEF_CERTIFICATEGROUPOFPCCONFIG                                                       STD_ON
#define KEYM_ISDEF_CERTIFICATEGROUPVERIFYCALLBACKNOTIFICATIONOFPCCONFIG                             STD_ON
#define KEYM_ISDEF_CERTIFICATEINITCALLOUTOFPCCONFIG                                                 STD_ON
#define KEYM_ISDEF_CERTIFICATEINITVALUEINFOOFPCCONFIG                                               STD_ON
#define KEYM_ISDEF_CERTIFICATEINITVALUEOFPCCONFIG                                                   STD_ON
#define KEYM_ISDEF_CERTIFICATENAMEOFPCCONFIG                                                        STD_ON
#define KEYM_ISDEF_CERTIFICATEOFPCCONFIG                                                            STD_ON
#define KEYM_ISDEF_CERTIFICATESLOTOFPCCONFIG                                                        STD_ON
#define KEYM_ISDEF_COMMONCERTDATAOFPCCONFIG                                                         STD_ON
#define KEYM_ISDEF_ELEMENTOIDOFPCCONFIG                                                             STD_ON
#define KEYM_ISDEF_ELEMENTSTORAGEREFOFPCCONFIG                                                      STD_ON
#define KEYM_ISDEF_GENERALOFPCCONFIG                                                                STD_ON
#define KEYM_ISDEF_GROUPINDOFPCCONFIG                                                               STD_ON
#define KEYM_ISDEF_NVBLOCK_STATEOFPCCONFIG                                                          STD_ON
#define KEYM_ISDEF_NVMBLOCKOFPCCONFIG                                                               STD_ON
#define KEYM_ISDEF_SLOTOWNEROFPCCONFIG                                                              STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCEqualsAlwaysToDefines  KeyM Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define KEYM_EQ2_CERTELEMENTPATH                                                                    
#define KEYM_EQ2_CERTALGORITHMFAMILYOFCERTIFICATE                                                   
#define KEYM_EQ2_CERTALLOWFLEXIBLEELEMENTORDEROFCERTIFICATE                                         
#define KEYM_EQ2_CERTALLOWUNCONFIGUREDELEMENTSOFCERTIFICATE                                         
#define KEYM_EQ2_CERTCSMSIGNATUREVERIFYJOBREFOFCERTIFICATE                                          
#define KEYM_EQ2_CERTCSMSIGNATUREVERIFYKEYREFOFCERTIFICATE                                          
#define KEYM_EQ2_CERTCSMSIGNATUREVERIFYKEYREFVALIDOFCERTIFICATE                                     
#define KEYM_EQ2_CERTFORMATTYPEOFCERTIFICATE                                                        
#define KEYM_EQ2_CERTPERSISTINVALIDCERTOFCERTIFICATE                                                
#define KEYM_EQ2_CERTSTARTUPHANDLINGOFCERTIFICATE                                                   
#define KEYM_EQ2_CERTSTORAGEENDIDXOFCERTIFICATE                                                     
#define KEYM_EQ2_CERTSTORAGELENGTHOFCERTIFICATE                                                     
#define KEYM_EQ2_CERTSTORAGESTARTIDXOFCERTIFICATE                                                   
#define KEYM_EQ2_CERTSTORAGESTATUSENDIDXOFCERTIFICATE                                               
#define KEYM_EQ2_CERTSTORAGESTATUSLENGTHOFCERTIFICATE                                               
#define KEYM_EQ2_CERTSTORAGESTATUSSTARTIDXOFCERTIFICATE                                             
#define KEYM_EQ2_CERTSTORAGEUSEDOFCERTIFICATE                                                       
#define KEYM_EQ2_CERTSTORAGEWRITTENLENGTHENDIDXOFCERTIFICATE                                        
#define KEYM_EQ2_CERTSTORAGEWRITTENLENGTHLENGTHOFCERTIFICATE                                        
#define KEYM_EQ2_CERTSTORAGEWRITTENLENGTHSTARTIDXOFCERTIFICATE                                      
#define KEYM_EQ2_CERTSTORAGEWRITTENLENGTHUSEDOFCERTIFICATE                                          
#define KEYM_EQ2_CERTUPPERHIERARCHICALCERTREFIDXOFCERTIFICATE                                       
#define KEYM_EQ2_CERTUPPERHIERARCHICALTYPEOFCERTIFICATE                                             
#define KEYM_EQ2_CERTIFICATEELEMENTENDIDXOFCERTIFICATE                                              
#define KEYM_EQ2_CERTIFICATEELEMENTLENGTHOFCERTIFICATE                                              
#define KEYM_EQ2_CERTIFICATEELEMENTSTARTIDXOFCERTIFICATE                                            
#define KEYM_EQ2_CERTIFICATEELEMENTUSEDOFCERTIFICATE                                                
#define KEYM_EQ2_CERTIFICATEGETCURRENTTIMECALLOUTIDXOFCERTIFICATE                                   
#define KEYM_EQ2_CERTIFICATEGETCURRENTTIMECALLOUTUSEDOFCERTIFICATE                                  
#define KEYM_EQ2_CERTIFICATEGROUPIDXOFCERTIFICATE                                                   
#define KEYM_EQ2_CERTIFICATEGROUPUSEDOFCERTIFICATE                                                  
#define KEYM_EQ2_CERTIFICATEINITVALUEINFOIDXOFCERTIFICATE                                           
#define KEYM_EQ2_CERTIFICATEINITVALUEINFOUSEDOFCERTIFICATE                                          
#define KEYM_EQ2_CERTIFICATENAMEENDIDXOFCERTIFICATE                                                 
#define KEYM_EQ2_CERTIFICATENAMELENGTHOFCERTIFICATE                                                 
#define KEYM_EQ2_CERTIFICATENAMESTARTIDXOFCERTIFICATE                                               
#define KEYM_EQ2_CERTIFICATESLOTUSEDOFCERTIFICATE                                                   
#define KEYM_EQ2_KEYMCERTCSMHASHJOBREFASYNCOFCERTIFICATE                                            
#define KEYM_EQ2_KEYMCERTCSMSIGNATUREGENERATEJOBREFASYNCOFCERTIFICATE                               
#define KEYM_EQ2_KEYMCERTCSMSIGNATUREVERIFYJOBREFASYNCOFCERTIFICATE                                 
#define KEYM_EQ2_MASKEDBITSOFCERTIFICATE                                                            
#define KEYM_EQ2_MAXLENGTHOFCERTIFICATE                                                             
#define KEYM_EQ2_NVMBLOCKIDXOFCERTIFICATE                                                           
#define KEYM_EQ2_NVMBLOCKUSEDOFCERTIFICATE                                                          
#define KEYM_EQ2_REMOTECERTIFICATEIDOFCERTIFICATE                                                   
#define KEYM_EQ2_SLOTREFIDXOFCERTIFICATE                                                            
#define KEYM_EQ2_STORAGEOFCERTIFICATE                                                               
#define KEYM_EQ2_CERTELEMENTPATHENDIDXOFCERTIFICATEELEMENT                                          
#define KEYM_EQ2_CERTELEMENTPATHLENGTHOFCERTIFICATEELEMENT                                          
#define KEYM_EQ2_CERTELEMENTPATHSTARTIDXOFCERTIFICATEELEMENT                                        
#define KEYM_EQ2_CERTELEMENTPATHUSEDOFCERTIFICATEELEMENT                                            
#define KEYM_EQ2_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT                                               
#define KEYM_EQ2_ELEMENTOIDLENGTHOFCERTIFICATEELEMENT                                               
#define KEYM_EQ2_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT                                             
#define KEYM_EQ2_ELEMENTOIDUSEDOFCERTIFICATEELEMENT                                                 
#define KEYM_EQ2_HASITERATIONOFCERTIFICATEELEMENT                                                   
#define KEYM_EQ2_IDOFCERTIFICATEELEMENT                                                             
#define KEYM_EQ2_MASKEDBITSOFCERTIFICATEELEMENT                                                     
#define KEYM_EQ2_MAXLENGTHOFCERTIFICATEELEMENT                                                      
#define KEYM_EQ2_OBJECTTYPEOFCERTIFICATEELEMENT                                                     
#define KEYM_EQ2_OFSTRUCTUREOFCERTIFICATEELEMENT                                                    
#define KEYM_EQ2_OPTIONALOFCERTIFICATEELEMENT                                                       
#define KEYM_EQ2_CERTIFICATEGETCURRENTTIMECALLOUT                                                   
#define KEYM_EQ2_CERTIFICATEGROUPVERIFYCALLBACKNOTIFICATIONIDXOFCERTIFICATEGROUP                    
#define KEYM_EQ2_CERTIFICATEGROUPVERIFYCALLBACKNOTIFICATIONUSEDOFCERTIFICATEGROUP                   
#define KEYM_EQ2_CERTIFICATEREMOTEGROUPIDOFCERTIFICATEGROUP                                         
#define KEYM_EQ2_ELEMENTOIDPRIMARYENDIDXOFCERTIFICATEGROUP                                          
#define KEYM_EQ2_ELEMENTOIDPRIMARYLENGTHOFCERTIFICATEGROUP                                          
#define KEYM_EQ2_ELEMENTOIDPRIMARYSTARTIDXOFCERTIFICATEGROUP                                        
#define KEYM_EQ2_ELEMENTOIDPRIMARYUSEDOFCERTIFICATEGROUP                                            
#define KEYM_EQ2_ELEMENTOIDSECONDARYENDIDXOFCERTIFICATEGROUP                                        
#define KEYM_EQ2_ELEMENTOIDSECONDARYLENGTHOFCERTIFICATEGROUP                                        
#define KEYM_EQ2_ELEMENTOIDSECONDARYSTARTIDXOFCERTIFICATEGROUP                                      
#define KEYM_EQ2_ELEMENTOIDSECONDARYUSEDOFCERTIFICATEGROUP                                          
#define KEYM_EQ2_GROUPINDCERTENDIDXOFCERTIFICATEGROUP                                               
#define KEYM_EQ2_GROUPINDCERTLENGTHOFCERTIFICATEGROUP                                               
#define KEYM_EQ2_GROUPINDCERTSTARTIDXOFCERTIFICATEGROUP                                             
#define KEYM_EQ2_GROUPINDISSUERENDIDXOFCERTIFICATEGROUP                                             
#define KEYM_EQ2_GROUPINDISSUERLENGTHOFCERTIFICATEGROUP                                             
#define KEYM_EQ2_GROUPINDISSUERSTARTIDXOFCERTIFICATEGROUP                                           
#define KEYM_EQ2_CERTIFICATEGROUPENDIDXOFCERTIFICATEGROUPEXT                                        
#define KEYM_EQ2_CERTIFICATEGROUPLENGTHOFCERTIFICATEGROUPEXT                                        
#define KEYM_EQ2_CERTIFICATEGROUPSTARTIDXOFCERTIFICATEGROUPEXT                                      
#define KEYM_EQ2_CERTIFICATEGROUPVERIFYCALLBACKNOTIFICATION                                         
#define KEYM_EQ2_CERTIFICATEINITCALLOUT                                                             
#define KEYM_EQ2_CERTIFICATEINITVALUE                                                               
#define KEYM_EQ2_CERTIFICATEINITCALLOUTIDXOFCERTIFICATEINITVALUEINFO                                
#define KEYM_EQ2_CERTIFICATEINITCALLOUTUSEDOFCERTIFICATEINITVALUEINFO                               
#define KEYM_EQ2_CERTIFICATEINITVALUEENDIDXOFCERTIFICATEINITVALUEINFO                               
#define KEYM_EQ2_CERTIFICATEINITVALUELENGTHOFCERTIFICATEINITVALUEINFO                               
#define KEYM_EQ2_CERTIFICATEINITVALUESTARTIDXOFCERTIFICATEINITVALUEINFO                             
#define KEYM_EQ2_CERTIFICATEINITVALUEUSEDOFCERTIFICATEINITVALUEINFO                                 
#define KEYM_EQ2_CERTIFICATENAME                                                                    
#define KEYM_EQ2_IDOFCERTIFICATESLOT                                                                
#define KEYM_EQ2_MAXLENGTHOFCERTIFICATESLOT                                                         
#define KEYM_EQ2_ELEMENTOID                                                                         
#define KEYM_EQ2_KEYMCSMREMOTEINFOJOBREFASYNCOFGENERAL                                              
#define KEYM_EQ2_CERTIFICATEIDXOFGROUPIND                                                           
#define KEYM_EQ2_CERTNVBLOCKPROCESSINGOFNVMBLOCK                                                    
#define KEYM_EQ2_DESCRIPTORREFOFNVMBLOCK                                                            
#define KEYM_EQ2_LENGTHOFNVMBLOCK                                                                   
#define KEYM_EQ2_CERTELEMENTPATHOFPCCONFIG                                                          KeyM_CertElementPath
#define KEYM_EQ2_CERTSTORAGEOFPCCONFIG                                                              KeyM_CertStorage.raw
#define KEYM_EQ2_CERT_CERTINFOOFPCCONFIG                                                            KeyM_Cert_CertInfo
#define KEYM_EQ2_CERT_LEAFCERTSTOVERIFYOFPCCONFIG                                                   KeyM_Cert_LeafCertsToVerify
#define KEYM_EQ2_CERT_LOCKOFPCCONFIG                                                                KeyM_Cert_Lock
#define KEYM_EQ2_CERT_STORAGETYPEOFPCCONFIG                                                         KeyM_Cert_StorageType
#define KEYM_EQ2_CERT_VERIFYCHAINOFPCCONFIG                                                         KeyM_Cert_VerifyChain
#define KEYM_EQ2_CERTIFICATEELEMENTOFPCCONFIG                                                       KeyM_CertificateElement
#define KEYM_EQ2_CERTIFICATEGETCURRENTTIMECALLOUTOFPCCONFIG                                         KeyM_CertificateGetCurrentTimeCallout
#define KEYM_EQ2_CERTIFICATEGROUPEXTOFPCCONFIG                                                      KeyM_CertificateGroupExt
#define KEYM_EQ2_CERTIFICATEGROUPOFPCCONFIG                                                         KeyM_CertificateGroup
#define KEYM_EQ2_CERTIFICATEGROUPVERIFYCALLBACKNOTIFICATIONOFPCCONFIG                               KeyM_CertificateGroupVerifyCallbackNotification
#define KEYM_EQ2_CERTIFICATEINITCALLOUTOFPCCONFIG                                                   KeyM_CertificateInitCallout
#define KEYM_EQ2_CERTIFICATEINITVALUEINFOOFPCCONFIG                                                 KeyM_CertificateInitValueInfo
#define KEYM_EQ2_CERTIFICATEINITVALUEOFPCCONFIG                                                     KeyM_CertificateInitValue
#define KEYM_EQ2_CERTIFICATENAMEOFPCCONFIG                                                          KeyM_CertificateName
#define KEYM_EQ2_CERTIFICATEOFPCCONFIG                                                              KeyM_Certificate
#define KEYM_EQ2_CERTIFICATESLOTOFPCCONFIG                                                          KeyM_CertificateSlot
#define KEYM_EQ2_COMMONCERTDATAOFPCCONFIG                                                           KeyM_CommonCertData.raw
#define KEYM_EQ2_ELEMENTOIDOFPCCONFIG                                                               KeyM_ElementOid
#define KEYM_EQ2_ELEMENTSTORAGEREFOFPCCONFIG                                                        KeyM_ElementStorageRef
#define KEYM_EQ2_GENERALOFPCCONFIG                                                                  KeyM_General
#define KEYM_EQ2_GROUPINDOFPCCONFIG                                                                 KeyM_GroupInd
#define KEYM_EQ2_NVBLOCK_STATEOFPCCONFIG                                                            KeyM_NvBlock_State.raw
#define KEYM_EQ2_NVMBLOCKOFPCCONFIG                                                                 KeyM_NvmBlock
#define KEYM_EQ2_SLOTOWNEROFPCCONFIG                                                                KeyM_SlotOwner
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCSymbolicInitializationPointers  KeyM Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define KeyM_Config_Ptr                                                                             NULL_PTR  /**< symbolic identifier which shall be used to initialize 'KeyM' */
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCInitializationSymbols  KeyM Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define KeyM_Config                                                                                 NULL_PTR  /**< symbolic identifier which could be used to initialize 'KeyM */
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCGeneral  KeyM General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define KEYM_CHECK_INIT_POINTER                                                                     STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define KEYM_FINAL_MAGIC_NUMBER                                                                     0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of KeyM */
#define KEYM_INDIVIDUAL_POSTBUILD                                                                   STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'KeyM' is not configured to be postbuild capable. */
#define KEYM_INIT_DATA                                                                              KEYM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define KEYM_INIT_DATA_HASH_CODE                                                                    -492589632  /**< the precompile constant to validate the initialization structure at initialization time of KeyM with a hashcode. The seed value is '0xFF1Eu' */
#define KEYM_USE_ECUM_BSW_ERROR_HOOK                                                                STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define KEYM_USE_INIT_POINTER                                                                       STD_OFF  /**< STD_ON if the init pointer KeyM shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  KeyMPBDataSwitches  KeyM Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define KEYM_PBCONFIG                                                                               STD_OFF  /**< Deactivateable: 'KeyM_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define KEYM_LTCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< Deactivateable: 'KeyM_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define KEYM_PCCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< Deactivateable: 'KeyM_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  KeyMPCGetConstantDuplicatedRootDataMacros  KeyM Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define KeyM_GetCertElementPathOfPCConfig()                                                         KeyM_CertElementPath  /**< the pointer to KeyM_CertElementPath */
#define KeyM_GetCertStorageOfPCConfig()                                                             KeyM_CertStorage.raw  /**< the pointer to KeyM_CertStorage */
#define KeyM_GetCert_CertInfoOfPCConfig()                                                           KeyM_Cert_CertInfo  /**< the pointer to KeyM_Cert_CertInfo */
#define KeyM_GetCert_LeafCertsToVerifyOfPCConfig()                                                  KeyM_Cert_LeafCertsToVerify  /**< the pointer to KeyM_Cert_LeafCertsToVerify */
#define KeyM_GetCert_LockOfPCConfig()                                                               KeyM_Cert_Lock  /**< the pointer to KeyM_Cert_Lock */
#define KeyM_GetCert_StorageTypeOfPCConfig()                                                        KeyM_Cert_StorageType  /**< the pointer to KeyM_Cert_StorageType */
#define KeyM_GetCert_VerifyChainOfPCConfig()                                                        KeyM_Cert_VerifyChain  /**< the pointer to KeyM_Cert_VerifyChain */
#define KeyM_GetCertificateChainMaxDepthOfGeneralOfPCConfig()                                       4u
#define KeyM_GetCertificateElementOfPCConfig()                                                      KeyM_CertificateElement  /**< the pointer to KeyM_CertificateElement */
#define KeyM_IsCertificateExtensionValidationEnabledOfGeneralOfPCConfig()                           (((FALSE)) != FALSE)
#define KeyM_GetCertificateGetCurrentTimeCalloutOfPCConfig()                                        KeyM_CertificateGetCurrentTimeCallout  /**< the pointer to KeyM_CertificateGetCurrentTimeCallout */
#define KeyM_GetCertificateGroupExtOfPCConfig()                                                     KeyM_CertificateGroupExt  /**< the pointer to KeyM_CertificateGroupExt */
#define KeyM_GetCertificateGroupOfPCConfig()                                                        KeyM_CertificateGroup  /**< the pointer to KeyM_CertificateGroup */
#define KeyM_GetCertificateGroupVerifyCallbackNotificationOfPCConfig()                              KeyM_CertificateGroupVerifyCallbackNotification  /**< the pointer to KeyM_CertificateGroupVerifyCallbackNotification */
#define KeyM_GetCertificateInitCalloutOfPCConfig()                                                  KeyM_CertificateInitCallout  /**< the pointer to KeyM_CertificateInitCallout */
#define KeyM_GetCertificateInitValueInfoOfPCConfig()                                                KeyM_CertificateInitValueInfo  /**< the pointer to KeyM_CertificateInitValueInfo */
#define KeyM_GetCertificateInitValueOfPCConfig()                                                    KeyM_CertificateInitValue  /**< the pointer to KeyM_CertificateInitValue */
#define KeyM_IsCertificateManagerEnabledOfGeneralOfPCConfig()                                       (((TRUE)) != FALSE)
#define KeyM_GetCertificateNameOfPCConfig()                                                         KeyM_CertificateName  /**< the pointer to KeyM_CertificateName */
#define KeyM_GetCertificateOfPCConfig()                                                             KeyM_Certificate  /**< the pointer to KeyM_Certificate */
#define KeyM_IsCertificateSigningRequestEnabledOfGeneralOfPCConfig()                                (((FALSE)) != FALSE)
#define KeyM_GetCertificateSlotOfPCConfig()                                                         KeyM_CertificateSlot  /**< the pointer to KeyM_CertificateSlot */
#define KeyM_GetCommonCertDataOfPCConfig()                                                          KeyM_CommonCertData.raw  /**< the pointer to KeyM_CommonCertData */
#define KeyM_IsCryptoKeyPrepareFunctionEnabledOfGeneralOfPCConfig()                                 (((FALSE)) != FALSE)
#define KeyM_IsCryptoKeyStartFinalizeFunctionEnabledOfGeneralOfPCConfig()                           (((FALSE)) != FALSE)
#define KeyM_IsCryptoKeyVerifyAsyncModeOfGeneralOfPCConfig()                                        (((FALSE)) != FALSE)
#define KeyM_IsCryptoKeyVerifyFunctionEnabledOfGeneralOfPCConfig()                                  (((FALSE)) != FALSE)
#define KeyM_GetElementOidOfPCConfig()                                                              KeyM_ElementOid  /**< the pointer to KeyM_ElementOid */
#define KeyM_GetElementStorageRefOfPCConfig()                                                       KeyM_ElementStorageRef  /**< the pointer to KeyM_ElementStorageRef */
#define KeyM_GetGeneralOfPCConfig()                                                                 KeyM_General  /**< the pointer to KeyM_General */
#define KeyM_GetGroupIndOfPCConfig()                                                                KeyM_GroupInd  /**< the pointer to KeyM_GroupInd */
#define KeyM_GetKeyCertNameMaxLengthOfGeneralOfPCConfig()                                           41u
#define KeyM_GetMainFunctionPeriodOfGeneralOfPCConfig()                                             1u
#define KeyM_GetNvBlock_StateOfPCConfig()                                                           KeyM_NvBlock_State.raw  /**< the pointer to KeyM_NvBlock_State */
#define KeyM_GetNvmBlockOfPCConfig()                                                                KeyM_NvmBlock  /**< the pointer to KeyM_NvmBlock */
#define KeyM_GetParseMaxNestingLevelOfGeneralOfPCConfig()                                           20u
#define KeyM_IsServiceCertificateFunctionEnabledOfGeneralOfPCConfig()                               (((TRUE)) != FALSE)
#define KeyM_GetSizeOfCertElementPathOfPCConfig()                                                   1733u  /**< the number of accomplishable value elements in KeyM_CertElementPath */
#define KeyM_GetSizeOfCertStorageOfPCConfig()                                                       11347u  /**< the number of accomplishable value elements in KeyM_CertStorage */
#define KeyM_GetSizeOfCertificateElementOfPCConfig()                                                1812u  /**< the number of accomplishable value elements in KeyM_CertificateElement */
#define KeyM_GetSizeOfCertificateGetCurrentTimeCalloutOfPCConfig()                                  1u  /**< the number of accomplishable value elements in KeyM_CertificateGetCurrentTimeCallout */
#define KeyM_GetSizeOfCertificateGroupExtOfPCConfig()                                               16u  /**< the number of accomplishable value elements in KeyM_CertificateGroupExt */
#define KeyM_GetSizeOfCertificateGroupOfPCConfig()                                                  17u  /**< the number of accomplishable value elements in KeyM_CertificateGroup */
#define KeyM_GetSizeOfCertificateGroupVerifyCallbackNotificationOfPCConfig()                        2u  /**< the number of accomplishable value elements in KeyM_CertificateGroupVerifyCallbackNotification */
#define KeyM_GetSizeOfCertificateInitCalloutOfPCConfig()                                            18u  /**< the number of accomplishable value elements in KeyM_CertificateInitCallout */
#define KeyM_GetSizeOfCertificateInitValueInfoOfPCConfig()                                          26u  /**< the number of accomplishable value elements in KeyM_CertificateInitValueInfo */
#define KeyM_GetSizeOfCertificateInitValueOfPCConfig()                                              5811u  /**< the number of accomplishable value elements in KeyM_CertificateInitValue */
#define KeyM_GetSizeOfCertificateNameOfPCConfig()                                                   1107u  /**< the number of accomplishable value elements in KeyM_CertificateName */
#define KeyM_GetSizeOfCertificateOfPCConfig()                                                       40u  /**< the number of accomplishable value elements in KeyM_Certificate */
#define KeyM_GetSizeOfCertificateSlotOfPCConfig()                                                   4u  /**< the number of accomplishable value elements in KeyM_CertificateSlot */
#define KeyM_GetSizeOfCommonCertDataOfPCConfig()                                                    40u  /**< the number of accomplishable value elements in KeyM_CommonCertData */
#define KeyM_GetSizeOfElementOidOfPCConfig()                                                        111u  /**< the number of accomplishable value elements in KeyM_ElementOid */
#define KeyM_GetSizeOfGeneralOfPCConfig()                                                           1u  /**< the number of accomplishable value elements in KeyM_General */
#define KeyM_GetSizeOfGroupIndOfPCConfig()                                                          48u  /**< the number of accomplishable value elements in KeyM_GroupInd */
#define KeyM_GetSizeOfNvmBlockOfPCConfig()                                                          6u  /**< the number of accomplishable value elements in KeyM_NvmBlock */
#define KeyM_GetSlotOwnerOfPCConfig()                                                               KeyM_SlotOwner  /**< the pointer to KeyM_SlotOwner */
#define KeyM_IsVersionInfoApiOfGeneralOfPCConfig()                                                  (((FALSE)) != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCGetDuplicatedRootDataMacros  KeyM Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define KeyM_GetSizeOfCert_CertInfoOfPCConfig()                                                     KeyM_GetSizeOfCertificateOfPCConfig()  /**< the number of accomplishable value elements in KeyM_Cert_CertInfo */
#define KeyM_GetSizeOfCert_LeafCertsToVerifyOfPCConfig()                                            KeyM_GetSizeOfCertificateOfPCConfig()  /**< the number of accomplishable value elements in KeyM_Cert_LeafCertsToVerify */
#define KeyM_GetSizeOfCert_LockOfPCConfig()                                                         KeyM_GetSizeOfCertificateOfPCConfig()  /**< the number of accomplishable value elements in KeyM_Cert_Lock */
#define KeyM_GetSizeOfCert_StorageTypeOfPCConfig()                                                  KeyM_GetSizeOfCertificateOfPCConfig()  /**< the number of accomplishable value elements in KeyM_Cert_StorageType */
#define KeyM_GetSizeOfCert_VerifyChainOfPCConfig()                                                  KeyM_GetSizeOfCertificateOfPCConfig()  /**< the number of accomplishable value elements in KeyM_Cert_VerifyChain */
#define KeyM_GetSizeOfElementStorageRefOfPCConfig()                                                 KeyM_GetSizeOfCertificateElementOfPCConfig()  /**< the number of accomplishable value elements in KeyM_ElementStorageRef */
#define KeyM_GetSizeOfNvBlock_StateOfPCConfig()                                                     KeyM_GetSizeOfNvmBlockOfPCConfig()  /**< the number of accomplishable value elements in KeyM_NvBlock_State */
#define KeyM_GetSizeOfSlotOwnerOfPCConfig()                                                         KeyM_GetSizeOfCertificateSlotOfPCConfig()  /**< the number of accomplishable value elements in KeyM_SlotOwner */
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


#define KEYM_NVBLOCK_READFROM_SCC_CERTIFICATE_ISO2_CONTRACTCERTIFICATE_0 STD_ON 
#define KEYM_NVBLOCK_WRITETO_SCC_CERTIFICATE_ISO2_CONTRACTCERTIFICATE_0  STD_ON 
#define KEYM_NVBLOCK_INIT_SCC_CERTIFICATE_ISO2_CONTRACTCERTIFICATE_0     STD_ON 
#define KEYM_NVBLOCK_CALLBACK_SCC_CERTIFICATE_ISO2_CONTRACTCERTIFICATE_0 STD_ON 
#define KEYM_NVBLOCK_READFROM_SCC_CERTIFICATE_ISO2_MOSUBCA1_0            STD_ON 
#define KEYM_NVBLOCK_WRITETO_SCC_CERTIFICATE_ISO2_MOSUBCA1_0             STD_ON 
#define KEYM_NVBLOCK_INIT_SCC_CERTIFICATE_ISO2_MOSUBCA1_0                STD_ON 
#define KEYM_NVBLOCK_CALLBACK_SCC_CERTIFICATE_ISO2_MOSUBCA1_0            STD_ON 
#define KEYM_NVBLOCK_READFROM_SCC_CERTIFICATE_ISO2_MOSUBCA2_0            STD_ON 
#define KEYM_NVBLOCK_WRITETO_SCC_CERTIFICATE_ISO2_MOSUBCA2_0             STD_ON 
#define KEYM_NVBLOCK_INIT_SCC_CERTIFICATE_ISO2_MOSUBCA2_0                STD_ON 
#define KEYM_NVBLOCK_CALLBACK_SCC_CERTIFICATE_ISO2_MOSUBCA2_0            STD_ON 
#define KEYM_NVBLOCK_READFROM_SCCCERTIFICATE_ISO20_EMSPCONTRACT_0_ECDSA  STD_ON 
#define KEYM_NVBLOCK_WRITETO_SCCCERTIFICATE_ISO20_EMSPCONTRACT_0_ECDSA   STD_ON 
#define KEYM_NVBLOCK_INIT_SCCCERTIFICATE_ISO20_EMSPCONTRACT_0_ECDSA      STD_ON 
#define KEYM_NVBLOCK_CALLBACK_SCCCERTIFICATE_ISO20_EMSPCONTRACT_0_ECDSA  STD_ON 
#define KEYM_NVBLOCK_READFROM_SCCCERTIFICATE_ISO20_EMSPSUBCA1_0_ECDSA    STD_ON 
#define KEYM_NVBLOCK_WRITETO_SCCCERTIFICATE_ISO20_EMSPSUBCA1_0_ECDSA     STD_ON 
#define KEYM_NVBLOCK_INIT_SCCCERTIFICATE_ISO20_EMSPSUBCA1_0_ECDSA        STD_ON 
#define KEYM_NVBLOCK_CALLBACK_SCCCERTIFICATE_ISO20_EMSPSUBCA1_0_ECDSA    STD_ON 
#define KEYM_NVBLOCK_READFROM_SCCCERTIFICATE_ISO20_EMSPSUBCA2_0_ECDSA    STD_ON 
#define KEYM_NVBLOCK_WRITETO_SCCCERTIFICATE_ISO20_EMSPSUBCA2_0_ECDSA     STD_ON 
#define KEYM_NVBLOCK_INIT_SCCCERTIFICATE_ISO20_EMSPSUBCA2_0_ECDSA        STD_ON 
#define KEYM_NVBLOCK_CALLBACK_SCCCERTIFICATE_ISO20_EMSPSUBCA2_0_ECDSA    STD_ON 




/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/* Enum literals for KeyM_CertificateStructureType */
# define KEYM_CERTIFICATE_ATTRIBUTE                                                                 0x00u
# define KEYM_CERTIFICATE_ATTRIBUTE_HOLDER                                                          0x01u
# define KEYM_CERTIFICATE_EXTENSION                                                                 0x02u
# define KEYM_CERTIFICATE_ISSUER_NAME                                                               0x03u
# define KEYM_CERTIFICATE_ISSUER_UNIQUE_IDENTIFIER                                                  0x04u
# define KEYM_CERTIFICATE_REVOCATION_LIST                                                           0x05u
# define KEYM_CERTIFICATE_SERIAL_NUMBER                                                             0x06u
# define KEYM_CERTIFICATE_SIGNATURE                                                                 0x07u
# define KEYM_CERTIFICATE_SIGNATURE_ALGORITHM                                                       0x08u
# define KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID                                                    0x09u
# define KEYM_CERTIFICATE_SUBJECT_NAME                                                              0x0Au
# define KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM                              0x0Bu
# define KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY                                0x0Cu
# define KEYM_CERTIFICATE_SUBJECT_UNIQUE_IDENTIFIER                                                 0x0Du
# define KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER                                                 0x0Eu
# define KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE                                                0x0Fu
# define KEYM_CERTIFICATE_VERSION_NUMBER                                                            0x10u
# define KEYM_CERTIFICATE_SUBJECT_AUTHORIZATION                                                     0x11u
# define KEYM_REVOKED_CERTIFICATES                                                                  0x12u

/* Structure Types */
typedef struct
{
  uint16 offset;
  uint16 length;
} KeyM_Ans1_Element_Ref_Type;

/* Certificate Group Verify Callback Notification Typedef */
typedef P2FUNC(Std_ReturnType, KEYM_APPL_CODE, KeyM_CertificateGroupVerifyCallbackNotificationFctPtrType)(KeyM_CertificateGroupIdType GroupId, KeyM_CertificateGroupStatusType Result);

/* BSW Certificate Verify Callback Notification Typedef / AUTOSAR R22-11+ Rte Certificate Verify Callback Notification Typedef */
typedef P2FUNC(Std_ReturnType, KEYM_APPL_CODE, KeyM_CertificateVerifyCallbackNotificationWithIdFctPtrType)(KeyM_CertificateIdType CertId, KeyM_CertificateStatusType Result);

/* Service Certificate Callback Notification Typedef */
typedef P2FUNC(void, KEYM_APPL_CODE, KeyM_ServiceCertificateCallbackNotificationFctPtrType)(KeyM_CertificateIdType CertId, KeyM_CertificateStatusType Result, uint16 ResultDataLength, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResultDataPtr);

/* Certificate Element Verification Callout Typedef */
typedef P2FUNC(Std_ReturnType, KEYM_APPL_CODE, KeyM_CertificateElementVerificationCalloutFctPtrType)(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertElementData, uint32 CertElementDataLength);

/* Certificate Set Key Callout Typedef */
typedef P2FUNC(Std_ReturnType, KEYM_APPL_CODE, KeyM_CertificateSetKeyCalloutFctPtrType)(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint32 csmKeyId, P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertElementData, uint32 CertElementDataLength);

/* Certificate Init Callout Typedef */
typedef P2FUNC(void, KEYM_APPL_CODE, KeyM_CertificateInitCalloutFctPtrType)(KeyM_CertificateIdType CertId, P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_VAR) CertificateDataPtr);

/* Certificate Get Current Time Callout Typedef */
typedef P2FUNC(Std_ReturnType, KEYM_APPL_CODE, KeyM_CertificateGetCurrentTimeCalloutFctPtrType)(KeyM_CertificateIdType CertId, P2VAR(uint64, AUTOMATIC, KEYM_APPL_VAR) timeStamp);

/* Rte Certificate Callback Notification Typedef according to AUTOSAR 4.4.0 */
typedef P2FUNC(Std_ReturnType, KEYM_RTE_CODE, KeyM_ServiceCertificateRteCallbackNotification440FctPtrType)(KeyM_CertificateStatusType Result, uint16 ResultDataLength, P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) ResultDataPtr);

/* Rte Certificate Callback Notification Typedef according to AUTOSAR R22-11 */
typedef P2FUNC(Std_ReturnType, KEYM_RTE_CODE, KeyM_ServiceCertificateRteCallbackNotification2211FctPtrType)(KeyM_CertificateStatusType Result, uint16 ResultDataLength, P2CONST(void, AUTOMATIC, KEYM_APPL_DATA) ResultDataPtr);

/* AUTOSAR R21-11 and below Rte Certificate Verify Callback Notification Typedef */
typedef P2FUNC(Std_ReturnType, KEYM_RTE_CODE, KeyM_CertificateVerifyCallbackNotificationWithoutIdFctPtrType)(KeyM_CertificateStatusType Result);



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  KeyMPCIterableTypes  KeyM Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate KeyM_CertElementPath */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertElementPath() } \endspec */ 
typedef uint16_least KeyM_CertElementPathIterType;

/**   \brief  type used to iterate KeyM_CertStorage */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertStorage() } \endspec */ 
typedef uint32_least KeyM_CertStorageIterType;

/**   \brief  type used to iterate KeyM_Certificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificate() } \endspec */ 
typedef uint8_least KeyM_CertificateIterType;

/**   \brief  type used to iterate KeyM_CertificateElement */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateElement() } \endspec */ 
typedef uint16_least KeyM_CertificateElementIterType;

/**   \brief  type used to iterate KeyM_CertificateGetCurrentTimeCallout */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateGetCurrentTimeCallout() } \endspec */ 
typedef uint8_least KeyM_CertificateGetCurrentTimeCalloutIterType;

/**   \brief  type used to iterate KeyM_CertificateGroup */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateGroup() } \endspec */ 
typedef uint8_least KeyM_CertificateGroupIterType;

/**   \brief  type used to iterate KeyM_CertificateGroupExt */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateGroupExt() } \endspec */ 
typedef uint8_least KeyM_CertificateGroupExtIterType;

/**   \brief  type used to iterate KeyM_CertificateGroupVerifyCallbackNotification */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateGroupVerifyCallbackNotification() } \endspec */ 
typedef uint8_least KeyM_CertificateGroupVerifyCallbackNotificationIterType;

/**   \brief  type used to iterate KeyM_CertificateInitCallout */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateInitCallout() } \endspec */ 
typedef uint8_least KeyM_CertificateInitCalloutIterType;

/**   \brief  type used to iterate KeyM_CertificateInitValue */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateInitValue() } \endspec */ 
typedef uint16_least KeyM_CertificateInitValueIterType;

/**   \brief  type used to iterate KeyM_CertificateInitValueInfo */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateInitValueInfo() } \endspec */ 
typedef uint8_least KeyM_CertificateInitValueInfoIterType;

/**   \brief  type used to iterate KeyM_CertificateName */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateName() } \endspec */ 
typedef uint16_least KeyM_CertificateNameIterType;

/**   \brief  type used to iterate KeyM_CertificateSlot */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateSlot() } \endspec */ 
typedef uint8_least KeyM_CertificateSlotIterType;

/**   \brief  type used to iterate KeyM_CommonCertData */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCommonCertData() } \endspec */ 
typedef uint8_least KeyM_CommonCertDataIterType;

/**   \brief  type used to iterate KeyM_ElementOid */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfElementOid() } \endspec */ 
typedef uint8_least KeyM_ElementOidIterType;

/**   \brief  type used to iterate KeyM_General */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfGeneral() } \endspec */ 
typedef uint8_least KeyM_GeneralIterType;

/**   \brief  type used to iterate KeyM_GroupInd */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfGroupInd() } \endspec */ 
typedef uint8_least KeyM_GroupIndIterType;

/**   \brief  type used to iterate KeyM_NvmBlock */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfNvmBlock() } \endspec */ 
typedef uint8_least KeyM_NvmBlockIterType;

/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCIterableTypesWithSizeRelations  KeyM Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate KeyM_Cert_CertInfo */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCert_CertInfo() } \endspec */ 
typedef KeyM_CertificateIterType KeyM_Cert_CertInfoIterType;

/**   \brief  type used to iterate KeyM_Cert_LeafCertsToVerify */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCert_LeafCertsToVerify() } \endspec */ 
typedef KeyM_CertificateIterType KeyM_Cert_LeafCertsToVerifyIterType;

/**   \brief  type used to iterate KeyM_Cert_Lock */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCert_Lock() } \endspec */ 
typedef KeyM_CertificateIterType KeyM_Cert_LockIterType;

/**   \brief  type used to iterate KeyM_Cert_StorageType */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCert_StorageType() } \endspec */ 
typedef KeyM_CertificateIterType KeyM_Cert_StorageTypeIterType;

/**   \brief  type used to iterate KeyM_Cert_VerifyChain */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCert_VerifyChain() } \endspec */ 
typedef KeyM_CertificateIterType KeyM_Cert_VerifyChainIterType;

/**   \brief  type used to iterate KeyM_ElementStorageRef */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfElementStorageRef() } \endspec */ 
typedef KeyM_CertificateElementIterType KeyM_ElementStorageRefIterType;

/**   \brief  type used to iterate KeyM_NvBlock_State */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfNvBlock_State() } \endspec */ 
typedef KeyM_NvmBlockIterType KeyM_NvBlock_StateIterType;

/**   \brief  type used to iterate KeyM_SlotOwner */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfSlotOwner() } \endspec */ 
typedef KeyM_CertificateSlotIterType KeyM_SlotOwnerIterType;

/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCValueTypes  KeyM Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for KeyM_CertElementPath */
typedef uint8 KeyM_CertElementPathType;

/**   \brief  value based type definition for KeyM_CertStorage */
typedef uint8 KeyM_CertStorageType;

/**   \brief  value based type definition for KeyM_Cert_Lock */
typedef boolean KeyM_Cert_LockType;

/**   \brief  value based type definition for KeyM_CertAlgorithmFamilyOfCertificate */
typedef uint8 KeyM_CertAlgorithmFamilyOfCertificateType;

/**   \brief  value based type definition for KeyM_CertAllowFlexibleElementOrderOfCertificate */
typedef boolean KeyM_CertAllowFlexibleElementOrderOfCertificateType;

/**   \brief  value based type definition for KeyM_CertAllowUnconfiguredElementsOfCertificate */
typedef boolean KeyM_CertAllowUnconfiguredElementsOfCertificateType;

/**   \brief  value based type definition for KeyM_CertCsmSignatureVerifyJobRefOfCertificate */
typedef uint32 KeyM_CertCsmSignatureVerifyJobRefOfCertificateType;

/**   \brief  value based type definition for KeyM_CertCsmSignatureVerifyKeyRefOfCertificate */
typedef uint32 KeyM_CertCsmSignatureVerifyKeyRefOfCertificateType;

/**   \brief  value based type definition for KeyM_CertCsmSignatureVerifyKeyRefValidOfCertificate */
typedef boolean KeyM_CertCsmSignatureVerifyKeyRefValidOfCertificateType;

/**   \brief  value based type definition for KeyM_CertFormatTypeOfCertificate */
typedef uint8 KeyM_CertFormatTypeOfCertificateType;

/**   \brief  value based type definition for KeyM_CertPersistInvalidCertOfCertificate */
typedef boolean KeyM_CertPersistInvalidCertOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStartUpHandlingOfCertificate */
typedef uint8 KeyM_CertStartUpHandlingOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageEndIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertStorage() } \endspec */ 
typedef uint16 KeyM_CertStorageEndIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageLengthOfCertificate */
typedef uint16 KeyM_CertStorageLengthOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageStartIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertStorage() } \endspec */ 
typedef uint16 KeyM_CertStorageStartIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageStatusEndIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertStorage() } \endspec */ 
typedef uint16 KeyM_CertStorageStatusEndIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageStatusLengthOfCertificate */
typedef uint8 KeyM_CertStorageStatusLengthOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageStatusStartIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertStorage() } \endspec */ 
typedef uint16 KeyM_CertStorageStatusStartIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageUsedOfCertificate */
typedef boolean KeyM_CertStorageUsedOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageWrittenLengthEndIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertStorage() } \endspec */ 
typedef uint16 KeyM_CertStorageWrittenLengthEndIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageWrittenLengthLengthOfCertificate */
typedef uint8 KeyM_CertStorageWrittenLengthLengthOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageWrittenLengthStartIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertStorage() } \endspec */ 
typedef uint16 KeyM_CertStorageWrittenLengthStartIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageWrittenLengthUsedOfCertificate */
typedef boolean KeyM_CertStorageWrittenLengthUsedOfCertificateType;

/**   \brief  value based type definition for KeyM_CertUpperHierarchicalCertRefIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificate() } \endspec */ 
typedef uint8 KeyM_CertUpperHierarchicalCertRefIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertUpperHierarchicalTypeOfCertificate */
typedef uint8 KeyM_CertUpperHierarchicalTypeOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateElementEndIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateElement() } \endspec */ 
typedef uint16 KeyM_CertificateElementEndIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateElementLengthOfCertificate */
typedef uint8 KeyM_CertificateElementLengthOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateElementStartIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateElement() } \endspec */ 
typedef uint16 KeyM_CertificateElementStartIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateElementUsedOfCertificate */
typedef boolean KeyM_CertificateElementUsedOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateGetCurrentTimeCalloutIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateGetCurrentTimeCallout() } \endspec */ 
typedef uint8 KeyM_CertificateGetCurrentTimeCalloutIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateGetCurrentTimeCalloutUsedOfCertificate */
typedef boolean KeyM_CertificateGetCurrentTimeCalloutUsedOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateGroupIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateGroup() } \endspec */ 
typedef uint8 KeyM_CertificateGroupIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateGroupUsedOfCertificate */
typedef boolean KeyM_CertificateGroupUsedOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateInitValueInfoIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateInitValueInfo() } \endspec */ 
typedef uint8 KeyM_CertificateInitValueInfoIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateInitValueInfoUsedOfCertificate */
typedef boolean KeyM_CertificateInitValueInfoUsedOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateNameEndIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateName() } \endspec */ 
typedef uint16 KeyM_CertificateNameEndIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateNameLengthOfCertificate */
typedef uint8 KeyM_CertificateNameLengthOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateNameStartIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateName() } \endspec */ 
typedef uint16 KeyM_CertificateNameStartIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateSlotUsedOfCertificate */
typedef boolean KeyM_CertificateSlotUsedOfCertificateType;

/**   \brief  value based type definition for KeyM_KeyMCertCsmHashJobRefAsyncOfCertificate */
typedef boolean KeyM_KeyMCertCsmHashJobRefAsyncOfCertificateType;

/**   \brief  value based type definition for KeyM_KeyMCertCsmSignatureGenerateJobRefAsyncOfCertificate */
typedef boolean KeyM_KeyMCertCsmSignatureGenerateJobRefAsyncOfCertificateType;

/**   \brief  value based type definition for KeyM_KeyMCertCsmSignatureVerifyJobRefAsyncOfCertificate */
typedef boolean KeyM_KeyMCertCsmSignatureVerifyJobRefAsyncOfCertificateType;

/**   \brief  value based type definition for KeyM_MaskedBitsOfCertificate */
typedef uint8 KeyM_MaskedBitsOfCertificateType;

/**   \brief  value based type definition for KeyM_MaxLengthOfCertificate */
typedef uint16 KeyM_MaxLengthOfCertificateType;

/**   \brief  value based type definition for KeyM_NvmBlockIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfNvmBlock() } \endspec */ 
typedef uint8 KeyM_NvmBlockIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_NvmBlockUsedOfCertificate */
typedef boolean KeyM_NvmBlockUsedOfCertificateType;

/**   \brief  value based type definition for KeyM_RemoteCertificateIdOfCertificate */
typedef uint8 KeyM_RemoteCertificateIdOfCertificateType;

/**   \brief  value based type definition for KeyM_SlotRefIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateSlot() } \endspec */ 
typedef uint8 KeyM_SlotRefIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_StorageOfCertificate */
typedef uint8 KeyM_StorageOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateChainMaxDepthOfGeneral */
typedef uint8 KeyM_CertificateChainMaxDepthOfGeneralType;

/**   \brief  value based type definition for KeyM_CertElementPathEndIdxOfCertificateElement */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertElementPath() } \endspec */ 
typedef uint16 KeyM_CertElementPathEndIdxOfCertificateElementType;

/**   \brief  value based type definition for KeyM_CertElementPathLengthOfCertificateElement */
typedef uint8 KeyM_CertElementPathLengthOfCertificateElementType;

/**   \brief  value based type definition for KeyM_CertElementPathStartIdxOfCertificateElement */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertElementPath() } \endspec */ 
typedef uint16 KeyM_CertElementPathStartIdxOfCertificateElementType;

/**   \brief  value based type definition for KeyM_CertElementPathUsedOfCertificateElement */
typedef boolean KeyM_CertElementPathUsedOfCertificateElementType;

/**   \brief  value based type definition for KeyM_ElementOidEndIdxOfCertificateElement */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfElementOid() } \endspec */ 
typedef uint8 KeyM_ElementOidEndIdxOfCertificateElementType;

/**   \brief  value based type definition for KeyM_ElementOidLengthOfCertificateElement */
typedef uint8 KeyM_ElementOidLengthOfCertificateElementType;

/**   \brief  value based type definition for KeyM_ElementOidStartIdxOfCertificateElement */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfElementOid() } \endspec */ 
typedef uint8 KeyM_ElementOidStartIdxOfCertificateElementType;

/**   \brief  value based type definition for KeyM_ElementOidUsedOfCertificateElement */
typedef boolean KeyM_ElementOidUsedOfCertificateElementType;

/**   \brief  value based type definition for KeyM_HasIterationOfCertificateElement */
typedef boolean KeyM_HasIterationOfCertificateElementType;

/**   \brief  value based type definition for KeyM_IdOfCertificateElement */
typedef uint16 KeyM_IdOfCertificateElementType;

/**   \brief  value based type definition for KeyM_MaskedBitsOfCertificateElement */
typedef uint8 KeyM_MaskedBitsOfCertificateElementType;

/**   \brief  value based type definition for KeyM_MaxLengthOfCertificateElement */
typedef uint16 KeyM_MaxLengthOfCertificateElementType;

/**   \brief  value based type definition for KeyM_ObjectTypeOfCertificateElement */
typedef uint8 KeyM_ObjectTypeOfCertificateElementType;

/**   \brief  value based type definition for KeyM_OptionalOfCertificateElement */
typedef boolean KeyM_OptionalOfCertificateElementType;

/**   \brief  value based type definition for KeyM_CertificateExtensionValidationEnabledOfGeneral */
typedef boolean KeyM_CertificateExtensionValidationEnabledOfGeneralType;

/**   \brief  value based type definition for KeyM_CertificateGroupVerifyCallbackNotificationIdxOfCertificateGroup */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateGroupVerifyCallbackNotification() } \endspec */ 
typedef uint8 KeyM_CertificateGroupVerifyCallbackNotificationIdxOfCertificateGroupType;

/**   \brief  value based type definition for KeyM_CertificateGroupVerifyCallbackNotificationUsedOfCertificateGroup */
typedef boolean KeyM_CertificateGroupVerifyCallbackNotificationUsedOfCertificateGroupType;

/**   \brief  value based type definition for KeyM_CertificateRemoteGroupIdOfCertificateGroup */
typedef uint8 KeyM_CertificateRemoteGroupIdOfCertificateGroupType;

/**   \brief  value based type definition for KeyM_ElementOidPrimaryEndIdxOfCertificateGroup */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfElementOid() } \endspec */ 
typedef uint8 KeyM_ElementOidPrimaryEndIdxOfCertificateGroupType;

/**   \brief  value based type definition for KeyM_ElementOidPrimaryLengthOfCertificateGroup */
typedef uint8 KeyM_ElementOidPrimaryLengthOfCertificateGroupType;

/**   \brief  value based type definition for KeyM_ElementOidPrimaryStartIdxOfCertificateGroup */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfElementOid() } \endspec */ 
typedef uint8 KeyM_ElementOidPrimaryStartIdxOfCertificateGroupType;

/**   \brief  value based type definition for KeyM_ElementOidPrimaryUsedOfCertificateGroup */
typedef boolean KeyM_ElementOidPrimaryUsedOfCertificateGroupType;

/**   \brief  value based type definition for KeyM_ElementOidSecondaryEndIdxOfCertificateGroup */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfElementOid() } \endspec */ 
typedef uint8 KeyM_ElementOidSecondaryEndIdxOfCertificateGroupType;

/**   \brief  value based type definition for KeyM_ElementOidSecondaryLengthOfCertificateGroup */
typedef uint8 KeyM_ElementOidSecondaryLengthOfCertificateGroupType;

/**   \brief  value based type definition for KeyM_ElementOidSecondaryStartIdxOfCertificateGroup */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfElementOid() } \endspec */ 
typedef uint8 KeyM_ElementOidSecondaryStartIdxOfCertificateGroupType;

/**   \brief  value based type definition for KeyM_ElementOidSecondaryUsedOfCertificateGroup */
typedef boolean KeyM_ElementOidSecondaryUsedOfCertificateGroupType;

/**   \brief  value based type definition for KeyM_GroupIndCertEndIdxOfCertificateGroup */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfGroupInd() } \endspec */ 
typedef uint8 KeyM_GroupIndCertEndIdxOfCertificateGroupType;

/**   \brief  value based type definition for KeyM_GroupIndCertLengthOfCertificateGroup */
typedef uint8 KeyM_GroupIndCertLengthOfCertificateGroupType;

/**   \brief  value based type definition for KeyM_GroupIndCertStartIdxOfCertificateGroup */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfGroupInd() } \endspec */ 
typedef uint8 KeyM_GroupIndCertStartIdxOfCertificateGroupType;

/**   \brief  value based type definition for KeyM_GroupIndIssuerEndIdxOfCertificateGroup */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfGroupInd() } \endspec */ 
typedef uint8 KeyM_GroupIndIssuerEndIdxOfCertificateGroupType;

/**   \brief  value based type definition for KeyM_GroupIndIssuerLengthOfCertificateGroup */
typedef uint8 KeyM_GroupIndIssuerLengthOfCertificateGroupType;

/**   \brief  value based type definition for KeyM_GroupIndIssuerStartIdxOfCertificateGroup */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfGroupInd() } \endspec */ 
typedef uint8 KeyM_GroupIndIssuerStartIdxOfCertificateGroupType;

/**   \brief  value based type definition for KeyM_CertificateGroupEndIdxOfCertificateGroupExt */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateGroup() } \endspec */ 
typedef uint8 KeyM_CertificateGroupEndIdxOfCertificateGroupExtType;

/**   \brief  value based type definition for KeyM_CertificateGroupLengthOfCertificateGroupExt */
typedef uint8 KeyM_CertificateGroupLengthOfCertificateGroupExtType;

/**   \brief  value based type definition for KeyM_CertificateGroupStartIdxOfCertificateGroupExt */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateGroup() } \endspec */ 
typedef uint8 KeyM_CertificateGroupStartIdxOfCertificateGroupExtType;

/**   \brief  value based type definition for KeyM_CertificateInitValue */
typedef uint8 KeyM_CertificateInitValueType;

/**   \brief  value based type definition for KeyM_CertificateInitCalloutIdxOfCertificateInitValueInfo */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateInitCallout() } \endspec */ 
typedef uint8 KeyM_CertificateInitCalloutIdxOfCertificateInitValueInfoType;

/**   \brief  value based type definition for KeyM_CertificateInitCalloutUsedOfCertificateInitValueInfo */
typedef boolean KeyM_CertificateInitCalloutUsedOfCertificateInitValueInfoType;

/**   \brief  value based type definition for KeyM_CertificateInitValueEndIdxOfCertificateInitValueInfo */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateInitValue() } \endspec */ 
typedef uint16 KeyM_CertificateInitValueEndIdxOfCertificateInitValueInfoType;

/**   \brief  value based type definition for KeyM_CertificateInitValueLengthOfCertificateInitValueInfo */
typedef uint16 KeyM_CertificateInitValueLengthOfCertificateInitValueInfoType;

/**   \brief  value based type definition for KeyM_CertificateInitValueStartIdxOfCertificateInitValueInfo */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateInitValue() } \endspec */ 
typedef uint16 KeyM_CertificateInitValueStartIdxOfCertificateInitValueInfoType;

/**   \brief  value based type definition for KeyM_CertificateInitValueUsedOfCertificateInitValueInfo */
typedef boolean KeyM_CertificateInitValueUsedOfCertificateInitValueInfoType;

/**   \brief  value based type definition for KeyM_CertificateManagerEnabledOfGeneral */
typedef boolean KeyM_CertificateManagerEnabledOfGeneralType;

/**   \brief  value based type definition for KeyM_CertificateName */
typedef uint8 KeyM_CertificateNameType;

/**   \brief  value based type definition for KeyM_CertificateSigningRequestEnabledOfGeneral */
typedef boolean KeyM_CertificateSigningRequestEnabledOfGeneralType;

/**   \brief  value based type definition for KeyM_IdOfCertificateSlot */
typedef uint8 KeyM_IdOfCertificateSlotType;

/**   \brief  value based type definition for KeyM_MaxLengthOfCertificateSlot */
typedef uint16 KeyM_MaxLengthOfCertificateSlotType;

/**   \brief  value based type definition for KeyM_CryptoKeyPrepareFunctionEnabledOfGeneral */
typedef boolean KeyM_CryptoKeyPrepareFunctionEnabledOfGeneralType;

/**   \brief  value based type definition for KeyM_CryptoKeyStartFinalizeFunctionEnabledOfGeneral */
typedef boolean KeyM_CryptoKeyStartFinalizeFunctionEnabledOfGeneralType;

/**   \brief  value based type definition for KeyM_CryptoKeyVerifyAsyncModeOfGeneral */
typedef boolean KeyM_CryptoKeyVerifyAsyncModeOfGeneralType;

/**   \brief  value based type definition for KeyM_CryptoKeyVerifyFunctionEnabledOfGeneral */
typedef boolean KeyM_CryptoKeyVerifyFunctionEnabledOfGeneralType;

/**   \brief  value based type definition for KeyM_ElementOid */
typedef uint8 KeyM_ElementOidType;

/**   \brief  value based type definition for KeyM_KeyMCsmRemoteInfoJobRefAsyncOfGeneral */
typedef boolean KeyM_KeyMCsmRemoteInfoJobRefAsyncOfGeneralType;

/**   \brief  value based type definition for KeyM_CertificateIdxOfGroupInd */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificate() } \endspec */ 
typedef uint8 KeyM_CertificateIdxOfGroupIndType;

/**   \brief  value based type definition for KeyM_KeyCertNameMaxLengthOfGeneral */
typedef uint8 KeyM_KeyCertNameMaxLengthOfGeneralType;

/**   \brief  value based type definition for KeyM_MainFunctionPeriodOfGeneral */
typedef uint8 KeyM_MainFunctionPeriodOfGeneralType;

/**   \brief  value based type definition for KeyM_CertNvBlockProcessingOfNvmBlock */
typedef uint8 KeyM_CertNvBlockProcessingOfNvmBlockType;

/**   \brief  value based type definition for KeyM_DescriptorRefOfNvmBlock */
typedef uint16 KeyM_DescriptorRefOfNvmBlockType;

/**   \brief  value based type definition for KeyM_LengthOfNvmBlock */
typedef uint16 KeyM_LengthOfNvmBlockType;

/**   \brief  value based type definition for KeyM_ParseMaxNestingLevelOfGeneral */
typedef uint8 KeyM_ParseMaxNestingLevelOfGeneralType;

/**   \brief  value based type definition for KeyM_ServiceCertificateFunctionEnabledOfGeneral */
typedef boolean KeyM_ServiceCertificateFunctionEnabledOfGeneralType;

/**   \brief  value based type definition for KeyM_SizeOfCertElementPath */
typedef uint16 KeyM_SizeOfCertElementPathType;

/**   \brief  value based type definition for KeyM_SizeOfCertStorage */
typedef uint16 KeyM_SizeOfCertStorageType;

/**   \brief  value based type definition for KeyM_SizeOfCert_CertInfo */
typedef uint8 KeyM_SizeOfCert_CertInfoType;

/**   \brief  value based type definition for KeyM_SizeOfCert_LeafCertsToVerify */
typedef uint8 KeyM_SizeOfCert_LeafCertsToVerifyType;

/**   \brief  value based type definition for KeyM_SizeOfCert_Lock */
typedef uint8 KeyM_SizeOfCert_LockType;

/**   \brief  value based type definition for KeyM_SizeOfCert_StorageType */
typedef uint8 KeyM_SizeOfCert_StorageTypeType;

/**   \brief  value based type definition for KeyM_SizeOfCert_VerifyChain */
typedef uint8 KeyM_SizeOfCert_VerifyChainType;

/**   \brief  value based type definition for KeyM_SizeOfCertificate */
typedef uint8 KeyM_SizeOfCertificateType;

/**   \brief  value based type definition for KeyM_SizeOfCertificateElement */
typedef uint16 KeyM_SizeOfCertificateElementType;

/**   \brief  value based type definition for KeyM_SizeOfCertificateGetCurrentTimeCallout */
typedef uint8 KeyM_SizeOfCertificateGetCurrentTimeCalloutType;

/**   \brief  value based type definition for KeyM_SizeOfCertificateGroup */
typedef uint8 KeyM_SizeOfCertificateGroupType;

/**   \brief  value based type definition for KeyM_SizeOfCertificateGroupExt */
typedef uint8 KeyM_SizeOfCertificateGroupExtType;

/**   \brief  value based type definition for KeyM_SizeOfCertificateGroupVerifyCallbackNotification */
typedef uint8 KeyM_SizeOfCertificateGroupVerifyCallbackNotificationType;

/**   \brief  value based type definition for KeyM_SizeOfCertificateInitCallout */
typedef uint8 KeyM_SizeOfCertificateInitCalloutType;

/**   \brief  value based type definition for KeyM_SizeOfCertificateInitValue */
typedef uint16 KeyM_SizeOfCertificateInitValueType;

/**   \brief  value based type definition for KeyM_SizeOfCertificateInitValueInfo */
typedef uint8 KeyM_SizeOfCertificateInitValueInfoType;

/**   \brief  value based type definition for KeyM_SizeOfCertificateName */
typedef uint16 KeyM_SizeOfCertificateNameType;

/**   \brief  value based type definition for KeyM_SizeOfCertificateSlot */
typedef uint8 KeyM_SizeOfCertificateSlotType;

/**   \brief  value based type definition for KeyM_SizeOfCommonCertData */
typedef uint8 KeyM_SizeOfCommonCertDataType;

/**   \brief  value based type definition for KeyM_SizeOfElementOid */
typedef uint8 KeyM_SizeOfElementOidType;

/**   \brief  value based type definition for KeyM_SizeOfElementStorageRef */
typedef uint16 KeyM_SizeOfElementStorageRefType;

/**   \brief  value based type definition for KeyM_SizeOfGeneral */
typedef uint8 KeyM_SizeOfGeneralType;

/**   \brief  value based type definition for KeyM_SizeOfGroupInd */
typedef uint8 KeyM_SizeOfGroupIndType;

/**   \brief  value based type definition for KeyM_SizeOfNvBlock_State */
typedef uint8 KeyM_SizeOfNvBlock_StateType;

/**   \brief  value based type definition for KeyM_SizeOfNvmBlock */
typedef uint8 KeyM_SizeOfNvmBlockType;

/**   \brief  value based type definition for KeyM_SizeOfSlotOwner */
typedef uint8 KeyM_SizeOfSlotOwnerType;

/**   \brief  value based type definition for KeyM_VersionInfoApiOfGeneral */
typedef boolean KeyM_VersionInfoApiOfGeneralType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  KeyMPCStructTypes  KeyM Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in KeyM_Certificate */
/*! 
 * \spec strong type invariant () { 
 *   (!(self.CertStorageLengthOfCertificate != 0u) || (self.CertStorageEndIdxOfCertificate < KeyM_GetSizeOfCertStorage())) &&
 *   (!(self.CertStorageLengthOfCertificate != 0u) || (self.CertStorageStartIdxOfCertificate < KeyM_GetSizeOfCertStorage())) &&
 *   (self.CertStorageStatusStartIdxOfCertificate < KeyM_GetSizeOfCertStorage()) &&
 *   (!(self.CertStorageWrittenLengthLengthOfCertificate != 0u) || (self.CertStorageWrittenLengthEndIdxOfCertificate < KeyM_GetSizeOfCertStorage())) &&
 *   (!(self.CertStorageWrittenLengthLengthOfCertificate != 0u) || (self.CertStorageWrittenLengthStartIdxOfCertificate < KeyM_GetSizeOfCertStorage())) &&
 *   (!(self.CertificateElementLengthOfCertificate != 0u) || (self.CertificateElementEndIdxOfCertificate < KeyM_GetSizeOfCertificateElement())) &&
 *   (!(self.CertificateElementLengthOfCertificate != 0u) || (self.CertificateElementStartIdxOfCertificate < KeyM_GetSizeOfCertificateElement())) &&
 *   (self.CertificateNameEndIdxOfCertificate < KeyM_GetSizeOfCertificateName()) &&
 *   (self.CertificateNameStartIdxOfCertificate < KeyM_GetSizeOfCertificateName()) &&
 *   (self.CertUpperHierarchicalCertRefIdxOfCertificate < KeyM_GetSizeOfCertificate()) &&
 *   (!(self.CertificateGetCurrentTimeCalloutIdxOfCertificate != KEYM_NO_CERTIFICATEGETCURRENTTIMECALLOUTIDXOFCERTIFICATE) || (self.CertificateGetCurrentTimeCalloutIdxOfCertificate < KeyM_GetSizeOfCertificateGetCurrentTimeCallout())) &&
 *   (!(self.CertificateGroupIdxOfCertificate != KEYM_NO_CERTIFICATEGROUPIDXOFCERTIFICATE) || (self.CertificateGroupIdxOfCertificate < KeyM_GetSizeOfCertificateGroup())) &&
 *   (!(self.CertificateInitValueInfoIdxOfCertificate != KEYM_NO_CERTIFICATEINITVALUEINFOIDXOFCERTIFICATE) || (self.CertificateInitValueInfoIdxOfCertificate < KeyM_GetSizeOfCertificateInitValueInfo())) &&
 *   (!(self.NvmBlockIdxOfCertificate != KEYM_NO_NVMBLOCKIDXOFCERTIFICATE) || (self.NvmBlockIdxOfCertificate < KeyM_GetSizeOfNvmBlock())) &&
 *   (!(self.SlotRefIdxOfCertificate != KEYM_NO_SLOTREFIDXOFCERTIFICATE) || (self.SlotRefIdxOfCertificate < KeyM_GetSizeOfCertificateSlot()))
 * }
 * \endspec 
 */ 
typedef struct sKeyM_CertificateType
{
  KeyM_CertCsmSignatureVerifyJobRefOfCertificateType CertCsmSignatureVerifyJobRefOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmSignatureVerifyJobRef. */
  KeyM_CertCsmSignatureVerifyKeyRefOfCertificateType CertCsmSignatureVerifyKeyRefOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmSignatureVerifyKeyRef. */
  KeyM_CertStorageEndIdxOfCertificateType CertStorageEndIdxOfCertificate;  /**< the end index of the 0:n relation pointing to KeyM_CertStorage */
  KeyM_CertStorageStartIdxOfCertificateType CertStorageStartIdxOfCertificate;  /**< the start index of the 0:n relation pointing to KeyM_CertStorage */
  KeyM_CertStorageStatusStartIdxOfCertificateType CertStorageStatusStartIdxOfCertificate;  /**< the start index of the 1:n relation pointing to KeyM_CertStorage */
  KeyM_CertStorageWrittenLengthEndIdxOfCertificateType CertStorageWrittenLengthEndIdxOfCertificate;  /**< the end index of the 0:n relation pointing to KeyM_CertStorage */
  KeyM_CertStorageWrittenLengthStartIdxOfCertificateType CertStorageWrittenLengthStartIdxOfCertificate;  /**< the start index of the 0:n relation pointing to KeyM_CertStorage */
  KeyM_CertificateElementEndIdxOfCertificateType CertificateElementEndIdxOfCertificate;  /**< the end index of the 0:n relation pointing to KeyM_CertificateElement */
  KeyM_CertificateElementStartIdxOfCertificateType CertificateElementStartIdxOfCertificate;  /**< the start index of the 0:n relation pointing to KeyM_CertificateElement */
  KeyM_CertificateNameEndIdxOfCertificateType CertificateNameEndIdxOfCertificate;  /**< the end index of the 1:n relation pointing to KeyM_CertificateName */
  KeyM_CertificateNameStartIdxOfCertificateType CertificateNameStartIdxOfCertificate;  /**< the start index of the 1:n relation pointing to KeyM_CertificateName */
  KeyM_MaxLengthOfCertificateType MaxLengthOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateMaxLength. */
  KeyM_CertAlgorithmFamilyOfCertificateType CertAlgorithmFamilyOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertAlgorithmFamily. */
  KeyM_CertFormatTypeOfCertificateType CertFormatTypeOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertFormatType. */
  KeyM_CertStartUpHandlingOfCertificateType CertStartUpHandlingOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertStartUpHandling. */
  KeyM_CertUpperHierarchicalCertRefIdxOfCertificateType CertUpperHierarchicalCertRefIdxOfCertificate;  /**< the index of the 1:1 relation pointing to KeyM_Certificate */
  KeyM_CertUpperHierarchicalTypeOfCertificateType CertUpperHierarchicalTypeOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertUpperHierarchicalType. */
  KeyM_CertificateGetCurrentTimeCalloutIdxOfCertificateType CertificateGetCurrentTimeCalloutIdxOfCertificate;  /**< the index of the 0:1 relation pointing to KeyM_CertificateGetCurrentTimeCallout */
  KeyM_CertificateGroupIdxOfCertificateType CertificateGroupIdxOfCertificate;  /**< the index of the 0:1 relation pointing to KeyM_CertificateGroup */
  KeyM_CertificateInitValueInfoIdxOfCertificateType CertificateInitValueInfoIdxOfCertificate;  /**< the index of the 0:1 relation pointing to KeyM_CertificateInitValueInfo */
  KeyM_MaskedBitsOfCertificateType MaskedBitsOfCertificate;  /**< contains bitcoded the boolean data of KeyM_CertAllowFlexibleElementOrderOfCertificate, KeyM_CertAllowUnconfiguredElementsOfCertificate, KeyM_CertCsmSignatureVerifyKeyRefValidOfCertificate, KeyM_CertPersistInvalidCertOfCertificate, KeyM_KeyMCertCsmHashJobRefAsyncOfCertificate, KeyM_KeyMCertCsmSignatureGenerateJobRefAsyncOfCertificate, KeyM_KeyMCertCsmSignatureVerifyJobRefAsyncOfCertificate */
  KeyM_NvmBlockIdxOfCertificateType NvmBlockIdxOfCertificate;  /**< the index of the 0:1 relation pointing to KeyM_NvmBlock */
  KeyM_SlotRefIdxOfCertificateType SlotRefIdxOfCertificate;  /**< the index of the 0:1 relation pointing to KeyM_CertificateSlot */
  KeyM_StorageOfCertificateType StorageOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateStorage. */
} KeyM_CertificateType;

/**   \brief  type used in KeyM_CertificateElement */
/*! 
 * \spec strong type invariant () { 
 *   (!(self.CertElementPathLengthOfCertificateElement != 0u) || (self.CertElementPathEndIdxOfCertificateElement < KeyM_GetSizeOfCertElementPath())) &&
 *   (!(self.CertElementPathLengthOfCertificateElement != 0u) || (self.CertElementPathStartIdxOfCertificateElement < KeyM_GetSizeOfCertElementPath())) &&
 *   (!(self.ElementOidLengthOfCertificateElement != 0u) || (self.ElementOidEndIdxOfCertificateElement < KeyM_GetSizeOfElementOid())) &&
 *   (!(self.ElementOidLengthOfCertificateElement != 0u) || (self.ElementOidStartIdxOfCertificateElement < KeyM_GetSizeOfElementOid()))
 * }
 * \endspec 
 */ 
typedef struct sKeyM_CertificateElementType
{
  KeyM_CertElementPathEndIdxOfCertificateElementType CertElementPathEndIdxOfCertificateElement;  /**< the end index of the 0:n relation pointing to KeyM_CertElementPath */
  KeyM_CertElementPathStartIdxOfCertificateElementType CertElementPathStartIdxOfCertificateElement;  /**< the start index of the 0:n relation pointing to KeyM_CertElementPath */
  KeyM_IdOfCertificateElementType IdOfCertificateElement;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId. */
  KeyM_MaxLengthOfCertificateElementType MaxLengthOfCertificateElement;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementMaxLength. */
  KeyM_ElementOidEndIdxOfCertificateElementType ElementOidEndIdxOfCertificateElement;  /**< the end index of the 0:n relation pointing to KeyM_ElementOid */
  KeyM_ElementOidStartIdxOfCertificateElementType ElementOidStartIdxOfCertificateElement;  /**< the start index of the 0:n relation pointing to KeyM_ElementOid */
  KeyM_MaskedBitsOfCertificateElementType MaskedBitsOfCertificateElement;  /**< contains bitcoded the boolean data of KeyM_HasIterationOfCertificateElement, KeyM_OptionalOfCertificateElement */
  KeyM_ObjectTypeOfCertificateElementType ObjectTypeOfCertificateElement;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementObjectType. */
  KeyM_CertificateStructureType OfStructureOfCertificateElement;
} KeyM_CertificateElementType;

/**   \brief  type used in KeyM_CertificateGroup */
/*! 
 * \spec strong type invariant () { 
 *   (!(self.CertificateGroupVerifyCallbackNotificationIdxOfCertificateGroup != KEYM_NO_CERTIFICATEGROUPVERIFYCALLBACKNOTIFICATIONIDXOFCERTIFICATEGROUP) || (self.CertificateGroupVerifyCallbackNotificationIdxOfCertificateGroup < KeyM_GetSizeOfCertificateGroupVerifyCallbackNotification())) &&
 *   (!(self.ElementOidPrimaryLengthOfCertificateGroup != 0u) || (self.ElementOidPrimaryEndIdxOfCertificateGroup < KeyM_GetSizeOfElementOid())) &&
 *   (!(self.ElementOidPrimaryLengthOfCertificateGroup != 0u) || (self.ElementOidPrimaryStartIdxOfCertificateGroup < KeyM_GetSizeOfElementOid())) &&
 *   (!(self.ElementOidSecondaryLengthOfCertificateGroup != 0u) || (self.ElementOidSecondaryEndIdxOfCertificateGroup < KeyM_GetSizeOfElementOid())) &&
 *   (!(self.ElementOidSecondaryLengthOfCertificateGroup != 0u) || (self.ElementOidSecondaryStartIdxOfCertificateGroup < KeyM_GetSizeOfElementOid())) &&
 *   (self.GroupIndCertEndIdxOfCertificateGroup < KeyM_GetSizeOfGroupInd()) &&
 *   (self.GroupIndCertStartIdxOfCertificateGroup < KeyM_GetSizeOfGroupInd()) &&
 *   (self.GroupIndIssuerEndIdxOfCertificateGroup < KeyM_GetSizeOfGroupInd()) &&
 *   (self.GroupIndIssuerStartIdxOfCertificateGroup < KeyM_GetSizeOfGroupInd())
 * }
 * \endspec 
 */ 
typedef struct sKeyM_CertificateGroupType
{
  KeyM_CertificateGroupVerifyCallbackNotificationIdxOfCertificateGroupType CertificateGroupVerifyCallbackNotificationIdxOfCertificateGroup;  /**< the index of the 0:1 relation pointing to KeyM_CertificateGroupVerifyCallbackNotification */
  KeyM_CertificateRemoteGroupIdOfCertificateGroupType CertificateRemoteGroupIdOfCertificateGroup;  /**< Remote id of the group. */
  KeyM_ElementOidPrimaryEndIdxOfCertificateGroupType ElementOidPrimaryEndIdxOfCertificateGroup;  /**< the end index of the 0:n relation pointing to KeyM_ElementOid */
  KeyM_ElementOidPrimaryStartIdxOfCertificateGroupType ElementOidPrimaryStartIdxOfCertificateGroup;  /**< the start index of the 0:n relation pointing to KeyM_ElementOid */
  KeyM_ElementOidSecondaryEndIdxOfCertificateGroupType ElementOidSecondaryEndIdxOfCertificateGroup;  /**< the end index of the 0:n relation pointing to KeyM_ElementOid */
  KeyM_ElementOidSecondaryStartIdxOfCertificateGroupType ElementOidSecondaryStartIdxOfCertificateGroup;  /**< the start index of the 0:n relation pointing to KeyM_ElementOid */
  KeyM_GroupIndCertEndIdxOfCertificateGroupType GroupIndCertEndIdxOfCertificateGroup;  /**< the end index of the 1:n relation pointing to KeyM_GroupInd */
  KeyM_GroupIndCertStartIdxOfCertificateGroupType GroupIndCertStartIdxOfCertificateGroup;  /**< the start index of the 1:n relation pointing to KeyM_GroupInd */
  KeyM_GroupIndIssuerEndIdxOfCertificateGroupType GroupIndIssuerEndIdxOfCertificateGroup;  /**< the end index of the 1:n relation pointing to KeyM_GroupInd */
  KeyM_GroupIndIssuerStartIdxOfCertificateGroupType GroupIndIssuerStartIdxOfCertificateGroup;  /**< the start index of the 1:n relation pointing to KeyM_GroupInd */
} KeyM_CertificateGroupType;

/**   \brief  type used in KeyM_CertificateGroupExt */
/*! 
 * \spec strong type invariant () { 
 *   (self.CertificateGroupEndIdxOfCertificateGroupExt < KeyM_GetSizeOfCertificateGroup())
 * }
 * \endspec 
 */ 
typedef struct sKeyM_CertificateGroupExtType
{
  KeyM_CertificateGroupEndIdxOfCertificateGroupExtType CertificateGroupEndIdxOfCertificateGroupExt;  /**< the end index of the 1:n relation pointing to KeyM_CertificateGroup */
  KeyM_CertificateGroupLengthOfCertificateGroupExtType CertificateGroupLengthOfCertificateGroupExt;  /**< the number of relations pointing to KeyM_CertificateGroup */
} KeyM_CertificateGroupExtType;

/**   \brief  type used in KeyM_CertificateInitValueInfo */
/*! 
 * \spec strong type invariant () { 
 *   (!(self.CertificateInitValueLengthOfCertificateInitValueInfo != 0u) || (self.CertificateInitValueEndIdxOfCertificateInitValueInfo < KeyM_GetSizeOfCertificateInitValue())) &&
 *   (!(self.CertificateInitValueLengthOfCertificateInitValueInfo != 0u) || (self.CertificateInitValueStartIdxOfCertificateInitValueInfo < KeyM_GetSizeOfCertificateInitValue())) &&
 *   (!(self.CertificateInitCalloutIdxOfCertificateInitValueInfo != KEYM_NO_CERTIFICATEINITCALLOUTIDXOFCERTIFICATEINITVALUEINFO) || (self.CertificateInitCalloutIdxOfCertificateInitValueInfo < KeyM_GetSizeOfCertificateInitCallout()))
 * }
 * \endspec 
 */ 
typedef struct sKeyM_CertificateInitValueInfoType
{
  KeyM_CertificateInitValueEndIdxOfCertificateInitValueInfoType CertificateInitValueEndIdxOfCertificateInitValueInfo;  /**< the end index of the 0:n relation pointing to KeyM_CertificateInitValue */
  KeyM_CertificateInitValueStartIdxOfCertificateInitValueInfoType CertificateInitValueStartIdxOfCertificateInitValueInfo;  /**< the start index of the 0:n relation pointing to KeyM_CertificateInitValue */
  KeyM_CertificateInitCalloutIdxOfCertificateInitValueInfoType CertificateInitCalloutIdxOfCertificateInitValueInfo;  /**< the index of the 0:1 relation pointing to KeyM_CertificateInitCallout */
} KeyM_CertificateInitValueInfoType;

/**   \brief  type used in KeyM_CertificateSlot */
typedef struct sKeyM_CertificateSlotType
{
  KeyM_MaxLengthOfCertificateSlotType MaxLengthOfCertificateSlot;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificateSlot/KeyMCertificateSlotMaxLength. */
  KeyM_IdOfCertificateSlotType IdOfCertificateSlot;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificateSlot/KeyMCertificateSlotId. */
} KeyM_CertificateSlotType;

/**   \brief  type used in KeyM_General */
typedef struct sKeyM_GeneralType
{
  KeyM_KeyMCsmRemoteInfoJobRefAsyncOfGeneralType KeyMCsmRemoteInfoJobRefAsyncOfGeneral;
} KeyM_GeneralType;

/**   \brief  type used in KeyM_GroupInd */
/*! 
 * \spec strong type invariant () { 
 *   (self.CertificateIdxOfGroupInd < KeyM_GetSizeOfCertificate())
 * }
 * \endspec 
 */ 
typedef struct sKeyM_GroupIndType
{
  KeyM_CertificateIdxOfGroupIndType CertificateIdxOfGroupInd;  /**< the index of the 1:1 relation pointing to KeyM_Certificate */
} KeyM_GroupIndType;

/**   \brief  type used in KeyM_NvmBlock */
typedef struct sKeyM_NvmBlockType
{
  KeyM_DescriptorRefOfNvmBlockType DescriptorRefOfNvmBlock;
  KeyM_LengthOfNvmBlockType LengthOfNvmBlock;
  KeyM_CertNvBlockProcessingOfNvmBlockType CertNvBlockProcessingOfNvmBlock;
} KeyM_NvmBlockType;

/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCSymbolicStructTypes  KeyM Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to KeyM_CertStorage */
typedef struct KeyM_CertStorageStructSTag
{
  KeyM_CertStorageType SccRAMGroup_CPOLeafRAMSharing__WrittenLength__[2];
  KeyM_CertStorageType SccRAMGroup_CPOLeafRAMSharing__Status__[2];
  KeyM_CertStorageType SccRAMGroup_CPOLeafRAMSharing__Data__[1600];
  KeyM_CertStorageType SccRAMGroup_CPOSubCA1RAMSharing__WrittenLength__[2];
  KeyM_CertStorageType SccRAMGroup_CPOSubCA1RAMSharing__Status__[2];
  KeyM_CertStorageType SccRAMGroup_CPOSubCA1RAMSharing__Data__[1600];
  KeyM_CertStorageType SccRAMGroup_CPOSubCA2RAMSharing__WrittenLength__[2];
  KeyM_CertStorageType SccRAMGroup_CPOSubCA2RAMSharing__Status__[2];
  KeyM_CertStorageType SccRAMGroup_CPOSubCA2RAMSharing__Data__[1600];
  KeyM_CertStorageType SccCertificate_ISO2_OEMProvSubCa1__WrittenLength__[2];
  KeyM_CertStorageType SccCertificate_ISO2_OEMProvSubCa1__Status__[2];
  KeyM_CertStorageType SccCertificate_ISO2_OEMProvSubCa1__Data__[800];
  KeyM_CertStorageType SccCertificate_ISO2_OEMProvSubCa2__WrittenLength__[2];
  KeyM_CertStorageType SccCertificate_ISO2_OEMProvSubCa2__Status__[2];
  KeyM_CertStorageType SccCertificate_ISO2_OEMProvSubCa2__Data__[800];
  KeyM_CertStorageType SccCertificate_ISO20_EMSPContract_0_ECDSA__WrittenLength__[2];
  KeyM_CertStorageType SccCertificate_ISO20_EMSPContract_0_ECDSA__Status__[2];
  KeyM_CertStorageType SccCertificate_ISO20_EMSPContract_0_ECDSA__Data__[1600];
  KeyM_CertStorageType SccCertificate_ISO20_EMSPSubCA1_0_ECDSA__WrittenLength__[2];
  KeyM_CertStorageType SccCertificate_ISO20_EMSPSubCA1_0_ECDSA__Status__[2];
  KeyM_CertStorageType SccCertificate_ISO20_EMSPSubCA1_0_ECDSA__Data__[1600];
  KeyM_CertStorageType SccCertificate_ISO20_EMSPSubCA2_0_ECDSA__WrittenLength__[2];
  KeyM_CertStorageType SccCertificate_ISO20_EMSPSubCA2_0_ECDSA__Status__[2];
  KeyM_CertStorageType SccCertificate_ISO20_EMSPSubCA2_0_ECDSA__Data__[1600];
  KeyM_CertStorageType SccCertificate_ISO20_OEMProvCertificate_0__WrittenLength__[2];
  KeyM_CertStorageType SccCertificate_ISO20_OEMProvCertificate_0__Status__[2];
  KeyM_CertStorageType SccCertificate_ISO20_OEMProvCertificate_0__Data__;
  KeyM_CertStorageType SccCertificate_ISO20_OEMProvSubCA1_0__WrittenLength__[2];
  KeyM_CertStorageType SccCertificate_ISO20_OEMProvSubCA1_0__Status__[2];
  KeyM_CertStorageType SccCertificate_ISO20_OEMProvSubCA1_0__Data__;
  KeyM_CertStorageType SccCertificate_ISO20_OEMProvSubCA2_0__WrittenLength__[2];
  KeyM_CertStorageType SccCertificate_ISO20_OEMProvSubCA2_0__Status__[2];
  KeyM_CertStorageType SccCertificate_ISO20_OEMProvSubCA2_0__Data__;
  KeyM_CertStorageType SccCertificate_ISO20_V2GRoot_0__WrittenLength__[2];
  KeyM_CertStorageType SccCertificate_ISO20_V2GRoot_0__Status__[2];
  KeyM_CertStorageType SccCertificate_ISO20_V2GRoot_0__Data__;
  KeyM_CertStorageType SccCertificate_ISO20_V2GRoot_1__WrittenLength__[2];
  KeyM_CertStorageType SccCertificate_ISO20_V2GRoot_1__Status__[2];
  KeyM_CertStorageType SccCertificate_ISO20_V2GRoot_1__Data__;
  KeyM_CertStorageType SccCertificate_ISO20_VehicleCert_0__WrittenLength__[2];
  KeyM_CertStorageType SccCertificate_ISO20_VehicleCert_0__Status__[2];
  KeyM_CertStorageType SccCertificate_ISO20_VehicleCert_0__Data__;
  KeyM_CertStorageType SccCertificate_ISO20_VehicleSubCA1_0__WrittenLength__[2];
  KeyM_CertStorageType SccCertificate_ISO20_VehicleSubCA1_0__Status__[2];
  KeyM_CertStorageType SccCertificate_ISO20_VehicleSubCA1_0__Data__;
  KeyM_CertStorageType SccCertificate_ISO20_VehicleSubCA2_0__WrittenLength__[2];
  KeyM_CertStorageType SccCertificate_ISO20_VehicleSubCA2_0__Status__[2];
  KeyM_CertStorageType SccCertificate_ISO20_VehicleSubCA2_0__Data__;
  KeyM_CertStorageType Scc_Certificate_ISO2_ContractCertificate_0__WrittenLength__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_ContractCertificate_0__Status__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_ContractCertificate_0__Data__;
  KeyM_CertStorageType Scc_Certificate_ISO2_MOSubCA1_0__WrittenLength__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_MOSubCA1_0__Status__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_MOSubCA1_0__Data__;
  KeyM_CertStorageType Scc_Certificate_ISO2_MOSubCA2_0__WrittenLength__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_MOSubCA2_0__Status__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_MOSubCA2_0__Data__;
  KeyM_CertStorageType Scc_Certificate_ISO2_OEMProvCertificate_0__WrittenLength__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_OEMProvCertificate_0__Status__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_OEMProvCertificate_0__Data__;
  KeyM_CertStorageType Scc_Certificate_ISO2_V2GRoot_0__WrittenLength__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2GRoot_0__Status__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2GRoot_0__Data__;
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_1__WrittenLength__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_1__Status__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_1__Data__;
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_2__WrittenLength__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_2__Status__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_2__Data__;
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_3__WrittenLength__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_3__Status__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_3__Data__;
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_4__WrittenLength__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_4__Status__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_4__Data__;
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_5__WrittenLength__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_5__Status__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_5__Data__;
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_6__WrittenLength__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_6__Status__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_6__Data__;
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_7__WrittenLength__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_7__Status__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_7__Data__;
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_8__WrittenLength__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_8__Status__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_8__Data__;
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_9__WrittenLength__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_9__Status__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_9__Data__;
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_10__WrittenLength__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_10__Status__[2];
  KeyM_CertStorageType Scc_Certificate_ISO2_V2G_Root_10__Data__;
} KeyM_CertStorageStructSType;

/**   \brief  type to be used as symbolic data element access to KeyM_CommonCertData */
typedef struct KeyM_CommonCertDataStructSTag
{
  KeyM_ConstCertDataType SccCertificate_ISO2_CPOLeaf_Tmp;
  KeyM_ConstCertDataType SccCertificate_ISO2_CPOSubCA1_Tmp;
  KeyM_ConstCertDataType SccCertificate_ISO2_CPOSubCA2_Tmp;
  KeyM_ConstCertDataType SccCertificate_ISO2_CPSLeaf_Tmp;
  KeyM_ConstCertDataType SccCertificate_ISO2_CPSSubCA1_Tmp;
  KeyM_ConstCertDataType SccCertificate_ISO2_CPSSubCA2_Tmp;
  KeyM_ConstCertDataType SccCertificate_ISO2_OEMProvSubCa1;
  KeyM_ConstCertDataType SccCertificate_ISO2_OEMProvSubCa2;
  KeyM_ConstCertDataType SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA;
  KeyM_ConstCertDataType SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA;
  KeyM_ConstCertDataType SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA;
  KeyM_ConstCertDataType SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA;
  KeyM_ConstCertDataType SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA;
  KeyM_ConstCertDataType SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA;
  KeyM_ConstCertDataType SccCertificate_ISO20_EMSPContract_0_ECDSA;
  KeyM_ConstCertDataType SccCertificate_ISO20_EMSPSubCA1_0_ECDSA;
  KeyM_ConstCertDataType SccCertificate_ISO20_EMSPSubCA2_0_ECDSA;
  KeyM_ConstCertDataType SccCertificate_ISO20_OEMProvCertificate_0;
  KeyM_ConstCertDataType SccCertificate_ISO20_OEMProvSubCA1_0;
  KeyM_ConstCertDataType SccCertificate_ISO20_OEMProvSubCA2_0;
  KeyM_ConstCertDataType SccCertificate_ISO20_V2GRoot_0;
  KeyM_ConstCertDataType SccCertificate_ISO20_V2GRoot_1;
  KeyM_ConstCertDataType SccCertificate_ISO20_VehicleCert_0;
  KeyM_ConstCertDataType SccCertificate_ISO20_VehicleSubCA1_0;
  KeyM_ConstCertDataType SccCertificate_ISO20_VehicleSubCA2_0;
  KeyM_ConstCertDataType Scc_Certificate_ISO2_ContractCertificate_0;
  KeyM_ConstCertDataType Scc_Certificate_ISO2_MOSubCA1_0;
  KeyM_ConstCertDataType Scc_Certificate_ISO2_MOSubCA2_0;
  KeyM_ConstCertDataType Scc_Certificate_ISO2_OEMProvCertificate_0;
  KeyM_ConstCertDataType Scc_Certificate_ISO2_V2GRoot_0;
  KeyM_ConstCertDataType Scc_Certificate_ISO2_V2G_Root_1;
  KeyM_ConstCertDataType Scc_Certificate_ISO2_V2G_Root_2;
  KeyM_ConstCertDataType Scc_Certificate_ISO2_V2G_Root_3;
  KeyM_ConstCertDataType Scc_Certificate_ISO2_V2G_Root_4;
  KeyM_ConstCertDataType Scc_Certificate_ISO2_V2G_Root_5;
  KeyM_ConstCertDataType Scc_Certificate_ISO2_V2G_Root_6;
  KeyM_ConstCertDataType Scc_Certificate_ISO2_V2G_Root_7;
  KeyM_ConstCertDataType Scc_Certificate_ISO2_V2G_Root_8;
  KeyM_ConstCertDataType Scc_Certificate_ISO2_V2G_Root_9;
  KeyM_ConstCertDataType Scc_Certificate_ISO2_V2G_Root_10;
} KeyM_CommonCertDataStructSType;

/**   \brief  type to be used as symbolic data element access to KeyM_NvBlock_State */
typedef struct KeyM_NvBlock_StateStructSTag
{
  tKeyMCertNvBlockStateType Scc_Certificate_ISO2_ContractCertificate_0;
  tKeyMCertNvBlockStateType Scc_Certificate_ISO2_MOSubCA1_0;
  tKeyMCertNvBlockStateType Scc_Certificate_ISO2_MOSubCA2_0;
  tKeyMCertNvBlockStateType SccCertificate_ISO20_EMSPContract_0_ECDSA;
  tKeyMCertNvBlockStateType SccCertificate_ISO20_EMSPSubCA1_0_ECDSA;
  tKeyMCertNvBlockStateType SccCertificate_ISO20_EMSPSubCA2_0_ECDSA;
} KeyM_NvBlock_StateStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCUnionIndexAndSymbolTypes  KeyM Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access KeyM_CertStorage in an index and symbol based style. */
typedef union KeyM_CertStorageUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  KeyM_CertStorageType raw[11347];
  KeyM_CertStorageStructSType str;
} KeyM_CertStorageUType;

/**   \brief  type to access KeyM_CommonCertData in an index and symbol based style. */
typedef union KeyM_CommonCertDataUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  KeyM_ConstCertDataType raw[40];
  KeyM_CommonCertDataStructSType str;
} KeyM_CommonCertDataUType;

/**   \brief  type to access KeyM_NvBlock_State in an index and symbol based style. */
typedef union KeyM_NvBlock_StateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  tKeyMCertNvBlockStateType raw[6];
  KeyM_NvBlock_StateStructSType str;
} KeyM_NvBlock_StateUType;

/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCRootPointerTypes  KeyM Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to KeyM_CertElementPath */
typedef P2CONST(KeyM_CertElementPathType, TYPEDEF, KEYM_CONST) KeyM_CertElementPathPtrType;

/**   \brief  type used to point to KeyM_CertStorage */
typedef P2VAR(KeyM_CertStorageType, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_CertStoragePtrType;

/**   \brief  type used to point to KeyM_Cert_CertInfo */
typedef P2VAR(tKeyMCertInfoType, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_Cert_CertInfoPtrType;

/**   \brief  type used to point to KeyM_Cert_LeafCertsToVerify */
typedef P2VAR(KeyM_CertificateIdType, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_Cert_LeafCertsToVerifyPtrType;

/**   \brief  type used to point to KeyM_Cert_Lock */
typedef P2VAR(KeyM_Cert_LockType, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_Cert_LockPtrType;

/**   \brief  type used to point to KeyM_Cert_StorageType */
typedef P2VAR(tKeyMCertStorageType, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_Cert_StorageTypePtrType;

/**   \brief  type used to point to KeyM_Cert_VerifyChain */
typedef P2VAR(KeyM_CertificateIdType, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_Cert_VerifyChainPtrType;

/**   \brief  type used to point to KeyM_Certificate */
typedef P2CONST(KeyM_CertificateType, TYPEDEF, KEYM_CONST) KeyM_CertificatePtrType;

/**   \brief  type used to point to KeyM_CertificateElement */
typedef P2CONST(KeyM_CertificateElementType, TYPEDEF, KEYM_CONST) KeyM_CertificateElementPtrType;

/**   \brief  type used to point to KeyM_CertificateGetCurrentTimeCallout */
typedef P2CONST(KeyM_CertificateGetCurrentTimeCalloutFctPtrType, TYPEDEF, KEYM_CONST) KeyM_CertificateGetCurrentTimeCalloutPtrType;

/**   \brief  type used to point to KeyM_CertificateGroup */
typedef P2CONST(KeyM_CertificateGroupType, TYPEDEF, KEYM_CONST) KeyM_CertificateGroupPtrType;

/**   \brief  type used to point to KeyM_CertificateGroupExt */
typedef P2CONST(KeyM_CertificateGroupExtType, TYPEDEF, KEYM_CONST) KeyM_CertificateGroupExtPtrType;

/**   \brief  type used to point to KeyM_CertificateGroupVerifyCallbackNotification */
typedef P2CONST(KeyM_CertificateGroupVerifyCallbackNotificationFctPtrType, TYPEDEF, KEYM_CONST) KeyM_CertificateGroupVerifyCallbackNotificationPtrType;

/**   \brief  type used to point to KeyM_CertificateInitCallout */
typedef P2CONST(KeyM_CertificateInitCalloutFctPtrType, TYPEDEF, KEYM_CONST) KeyM_CertificateInitCalloutPtrType;

/**   \brief  type used to point to KeyM_CertificateInitValue */
typedef P2CONST(KeyM_CertificateInitValueType, TYPEDEF, KEYM_CONST) KeyM_CertificateInitValuePtrType;

/**   \brief  type used to point to KeyM_CertificateInitValueInfo */
typedef P2CONST(KeyM_CertificateInitValueInfoType, TYPEDEF, KEYM_CONST) KeyM_CertificateInitValueInfoPtrType;

/**   \brief  type used to point to KeyM_CertificateName */
typedef P2CONST(KeyM_CertificateNameType, TYPEDEF, KEYM_CONST) KeyM_CertificateNamePtrType;

/**   \brief  type used to point to KeyM_CertificateSlot */
typedef P2CONST(KeyM_CertificateSlotType, TYPEDEF, KEYM_CONST) KeyM_CertificateSlotPtrType;

/**   \brief  type used to point to KeyM_CommonCertData */
typedef P2VAR(KeyM_ConstCertDataType, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_CommonCertDataPtrType;

/**   \brief  type used to point to KeyM_ElementOid */
typedef P2CONST(KeyM_ElementOidType, TYPEDEF, KEYM_CONST) KeyM_ElementOidPtrType;

/**   \brief  type used to point to KeyM_ElementStorageRef */
typedef P2VAR(KeyM_Ans1_Element_Ref_Type, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_ElementStorageRefPtrType;

/**   \brief  type used to point to KeyM_General */
typedef P2CONST(KeyM_GeneralType, TYPEDEF, KEYM_CONST) KeyM_GeneralPtrType;

/**   \brief  type used to point to KeyM_GroupInd */
typedef P2CONST(KeyM_GroupIndType, TYPEDEF, KEYM_CONST) KeyM_GroupIndPtrType;

/**   \brief  type used to point to KeyM_NvBlock_State */
typedef P2VAR(tKeyMCertNvBlockStateType, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_NvBlock_StatePtrType;

/**   \brief  type used to point to KeyM_NvmBlock */
typedef P2CONST(KeyM_NvmBlockType, TYPEDEF, KEYM_CONST) KeyM_NvmBlockPtrType;

/**   \brief  type used to point to KeyM_SlotOwner */
typedef P2VAR(KeyM_CertificateIdType, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_SlotOwnerPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCRootValueTypes  KeyM Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in KeyM_PCConfig */
typedef struct sKeyM_PCConfigType
{
  uint8 KeyM_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} KeyM_PCConfigType;

typedef KeyM_PCConfigType KeyM_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  KeyM_CertElementPath
**********************************************************************************************************************/
#define KEYM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(KeyM_CertElementPathType, KEYM_CONST) KeyM_CertElementPath[1733];
#define KEYM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_Certificate
**********************************************************************************************************************/
/** 
  \var    KeyM_Certificate
  \brief  Contains parameters of /MICROSAR/KeyM/KeyMCertificate.
  \details
  Element                                Description
  CertCsmSignatureVerifyJobRef           Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmSignatureVerifyJobRef.
  CertCsmSignatureVerifyKeyRef           Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmSignatureVerifyKeyRef.
  CertStorageEndIdx                      the end index of the 0:n relation pointing to KeyM_CertStorage
  CertStorageStartIdx                    the start index of the 0:n relation pointing to KeyM_CertStorage
  CertStorageStatusStartIdx              the start index of the 1:n relation pointing to KeyM_CertStorage
  CertStorageWrittenLengthEndIdx         the end index of the 0:n relation pointing to KeyM_CertStorage
  CertStorageWrittenLengthStartIdx       the start index of the 0:n relation pointing to KeyM_CertStorage
  CertificateElementEndIdx               the end index of the 0:n relation pointing to KeyM_CertificateElement
  CertificateElementStartIdx             the start index of the 0:n relation pointing to KeyM_CertificateElement
  CertificateNameEndIdx                  the end index of the 1:n relation pointing to KeyM_CertificateName
  CertificateNameStartIdx                the start index of the 1:n relation pointing to KeyM_CertificateName
  MaxLength                              Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateMaxLength.
  CertAlgorithmFamily                    Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertAlgorithmFamily.
  CertFormatType                         Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertFormatType.
  CertStartUpHandling                    Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertStartUpHandling.
  CertUpperHierarchicalCertRefIdx        the index of the 1:1 relation pointing to KeyM_Certificate
  CertUpperHierarchicalType              Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertUpperHierarchicalType.
  CertificateGetCurrentTimeCalloutIdx    the index of the 0:1 relation pointing to KeyM_CertificateGetCurrentTimeCallout
  CertificateGroupIdx                    the index of the 0:1 relation pointing to KeyM_CertificateGroup
  CertificateInitValueInfoIdx            the index of the 0:1 relation pointing to KeyM_CertificateInitValueInfo
  MaskedBits                             contains bitcoded the boolean data of KeyM_CertAllowFlexibleElementOrderOfCertificate, KeyM_CertAllowUnconfiguredElementsOfCertificate, KeyM_CertCsmSignatureVerifyKeyRefValidOfCertificate, KeyM_CertPersistInvalidCertOfCertificate, KeyM_KeyMCertCsmHashJobRefAsyncOfCertificate, KeyM_KeyMCertCsmSignatureGenerateJobRefAsyncOfCertificate, KeyM_KeyMCertCsmSignatureVerifyJobRefAsyncOfCertificate
  NvmBlockIdx                            the index of the 0:1 relation pointing to KeyM_NvmBlock
  SlotRefIdx                             the index of the 0:1 relation pointing to KeyM_CertificateSlot
  Storage                                Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateStorage.
*/ 
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(KeyM_CertificateType, KEYM_CONST) KeyM_Certificate[40];
#define KEYM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CertificateElement
**********************************************************************************************************************/
/** 
  \var    KeyM_CertificateElement
  \brief  Contains parameters of /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement.
  \details
  Element                    Description
  CertElementPathEndIdx      the end index of the 0:n relation pointing to KeyM_CertElementPath
  CertElementPathStartIdx    the start index of the 0:n relation pointing to KeyM_CertElementPath
  Id                         Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId.
  MaxLength                  Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementMaxLength.
  ElementOidEndIdx           the end index of the 0:n relation pointing to KeyM_ElementOid
  ElementOidStartIdx         the start index of the 0:n relation pointing to KeyM_ElementOid
  MaskedBits                 contains bitcoded the boolean data of KeyM_HasIterationOfCertificateElement, KeyM_OptionalOfCertificateElement
  ObjectType                 Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementObjectType.
  OfStructure            
*/ 
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(KeyM_CertificateElementType, KEYM_CONST) KeyM_CertificateElement[1812];
#define KEYM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CertificateGetCurrentTimeCallout
**********************************************************************************************************************/
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(KeyM_CertificateGetCurrentTimeCalloutFctPtrType, KEYM_CONST) KeyM_CertificateGetCurrentTimeCallout[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define KEYM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CertificateGroup
**********************************************************************************************************************/
/** 
  \var    KeyM_CertificateGroup
  \details
  Element                                          Description
  CertificateGroupVerifyCallbackNotificationIdx    the index of the 0:1 relation pointing to KeyM_CertificateGroupVerifyCallbackNotification
  CertificateRemoteGroupId                         Remote id of the group.
  ElementOidPrimaryEndIdx                          the end index of the 0:n relation pointing to KeyM_ElementOid
  ElementOidPrimaryStartIdx                        the start index of the 0:n relation pointing to KeyM_ElementOid
  ElementOidSecondaryEndIdx                        the end index of the 0:n relation pointing to KeyM_ElementOid
  ElementOidSecondaryStartIdx                      the start index of the 0:n relation pointing to KeyM_ElementOid
  GroupIndCertEndIdx                               the end index of the 1:n relation pointing to KeyM_GroupInd
  GroupIndCertStartIdx                             the start index of the 1:n relation pointing to KeyM_GroupInd
  GroupIndIssuerEndIdx                             the end index of the 1:n relation pointing to KeyM_GroupInd
  GroupIndIssuerStartIdx                           the start index of the 1:n relation pointing to KeyM_GroupInd
*/ 
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(KeyM_CertificateGroupType, KEYM_CONST) KeyM_CertificateGroup[17];
#define KEYM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CertificateGroupExt
**********************************************************************************************************************/
/** 
  \var    KeyM_CertificateGroupExt
  \details
  Element                   Description
  CertificateGroupEndIdx    the end index of the 1:n relation pointing to KeyM_CertificateGroup
  CertificateGroupLength    the number of relations pointing to KeyM_CertificateGroup
*/ 
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(KeyM_CertificateGroupExtType, KEYM_CONST) KeyM_CertificateGroupExt[16];
#define KEYM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CertificateGroupVerifyCallbackNotification
**********************************************************************************************************************/
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(KeyM_CertificateGroupVerifyCallbackNotificationFctPtrType, KEYM_CONST) KeyM_CertificateGroupVerifyCallbackNotification[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define KEYM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CertificateInitCallout
**********************************************************************************************************************/
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(KeyM_CertificateInitCalloutFctPtrType, KEYM_CONST) KeyM_CertificateInitCallout[18];
#define KEYM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CertificateInitValue
**********************************************************************************************************************/
#define KEYM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(KeyM_CertificateInitValueType, KEYM_CONST) KeyM_CertificateInitValue[5811];
#define KEYM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CertificateInitValueInfo
**********************************************************************************************************************/
/** 
  \var    KeyM_CertificateInitValueInfo
  \details
  Element                         Description
  CertificateInitValueEndIdx      the end index of the 0:n relation pointing to KeyM_CertificateInitValue
  CertificateInitValueStartIdx    the start index of the 0:n relation pointing to KeyM_CertificateInitValue
  CertificateInitCalloutIdx       the index of the 0:1 relation pointing to KeyM_CertificateInitCallout
*/ 
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(KeyM_CertificateInitValueInfoType, KEYM_CONST) KeyM_CertificateInitValueInfo[26];
#define KEYM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CertificateName
**********************************************************************************************************************/
#define KEYM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(KeyM_CertificateNameType, KEYM_CONST) KeyM_CertificateName[1107];
#define KEYM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CertificateSlot
**********************************************************************************************************************/
/** 
  \var    KeyM_CertificateSlot
  \brief  Contains parameters of /MICROSAR/KeyM/KeyMCertificateSlot.
  \details
  Element      Description
  MaxLength    Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificateSlot/KeyMCertificateSlotMaxLength.
  Id           Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificateSlot/KeyMCertificateSlotId.
*/ 
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(KeyM_CertificateSlotType, KEYM_CONST) KeyM_CertificateSlot[4];
#define KEYM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_ElementOid
**********************************************************************************************************************/
#define KEYM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(KeyM_ElementOidType, KEYM_CONST) KeyM_ElementOid[111];
#define KEYM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_General
**********************************************************************************************************************/
/** 
  \var    KeyM_General
  \brief  Contains parameters of /MICROSAR/KeyM/KeyMGeneral.
  \details
  Element                         Description
  KeyMCsmRemoteInfoJobRefAsync
*/ 
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(KeyM_GeneralType, KEYM_CONST) KeyM_General[1];
#define KEYM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_GroupInd
**********************************************************************************************************************/
/** 
  \var    KeyM_GroupInd
  \details
  Element           Description
  CertificateIdx    the index of the 1:1 relation pointing to KeyM_Certificate
*/ 
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(KeyM_GroupIndType, KEYM_CONST) KeyM_GroupInd[48];
#define KEYM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_NvmBlock
**********************************************************************************************************************/
/** 
  \var    KeyM_NvmBlock
  \brief  NvM Block Info
  \details
  Element                  Description
  DescriptorRef        
  Length               
  CertNvBlockProcessing
*/ 
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(KeyM_NvmBlockType, KEYM_CONST) KeyM_NvmBlock[6];
#define KEYM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CertStorage
**********************************************************************************************************************/
#define KEYM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(KeyM_CertStorageUType, KEYM_VAR_NO_INIT) KeyM_CertStorage;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define KEYM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_Cert_CertInfo
**********************************************************************************************************************/
/** 
  \var    KeyM_Cert_CertInfo
  \brief  Certificate data for signature verification, service request information and verification result
*/ 
#define KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(tKeyMCertInfoType, KEYM_VAR_NO_INIT) KeyM_Cert_CertInfo[40];
#define KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_Cert_LeafCertsToVerify
**********************************************************************************************************************/
/** 
  \var    KeyM_Cert_LeafCertsToVerify
  \brief  Buffer that contains certificate IDs of leaf certificates that shall be verified
*/ 
#define KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(KeyM_CertificateIdType, KEYM_VAR_NO_INIT) KeyM_Cert_LeafCertsToVerify[40];
#define KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_Cert_Lock
**********************************************************************************************************************/
/** 
  \var    KeyM_Cert_Lock
  \brief  Certificate Lock
*/ 
#define KEYM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(KeyM_Cert_LockType, KEYM_VAR_NO_INIT) KeyM_Cert_Lock[40];
#define KEYM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_Cert_StorageType
**********************************************************************************************************************/
/** 
  \var    KeyM_Cert_StorageType
  \brief  Storage type of certificate
*/ 
#define KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(tKeyMCertStorageType, KEYM_VAR_NO_INIT) KeyM_Cert_StorageType[40];
#define KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_Cert_VerifyChain
**********************************************************************************************************************/
/** 
  \var    KeyM_Cert_VerifyChain
  \brief  Buffer for certificates to be verified
*/ 
#define KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(KeyM_CertificateIdType, KEYM_VAR_NO_INIT) KeyM_Cert_VerifyChain[40];
#define KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CommonCertData
**********************************************************************************************************************/
#define KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(KeyM_CommonCertDataUType, KEYM_VAR_NO_INIT) KeyM_CommonCertData;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_ElementStorageRef
**********************************************************************************************************************/
#define KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(KeyM_Ans1_Element_Ref_Type, KEYM_VAR_NO_INIT) KeyM_ElementStorageRef[1812];
#define KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_NvBlock_State
**********************************************************************************************************************/
/** 
  \var    KeyM_NvBlock_State
  \brief  NvM Block State
*/ 
#define KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(KeyM_NvBlock_StateUType, KEYM_VAR_NO_INIT) KeyM_NvBlock_State;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_SlotOwner
**********************************************************************************************************************/
/** 
  \var    KeyM_SlotOwner
  \brief  Stores which certificate owns the shared RAM slot.
*/ 
#define KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(KeyM_CertificateIdType, KEYM_VAR_NO_INIT) KeyM_SlotOwner[4];
#define KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCGetDataInlineFunctionPrototypes  Get Data Inline Function Prototypes
  \brief  These inline functions can be used to read CONST and VAR data.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertElementPathType, KEYM_CODE) KeyM_GetCertElementPath(KeyM_CertElementPathIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageType, KEYM_CODE) KeyM_GetCertStorage(KeyM_CertStorageIterType Index);
KEYM_LOCAL_INLINE FUNC(tKeyMCertInfoType, KEYM_CODE) KeyM_GetCert_CertInfo(KeyM_Cert_CertInfoIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateIdType, KEYM_CODE) KeyM_GetCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_Cert_LockType, KEYM_CODE) KeyM_IsCert_Lock(KeyM_Cert_LockIterType Index);
KEYM_LOCAL_INLINE FUNC(tKeyMCertStorageType, KEYM_CODE) KeyM_GetCert_StorageType(KeyM_Cert_StorageTypeIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateIdType, KEYM_CODE) KeyM_GetCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertAlgorithmFamilyOfCertificateType, KEYM_CODE) KeyM_GetCertAlgorithmFamilyOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertCsmSignatureVerifyJobRefOfCertificateType, KEYM_CODE) KeyM_GetCertCsmSignatureVerifyJobRefOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertCsmSignatureVerifyKeyRefOfCertificateType, KEYM_CODE) KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertFormatTypeOfCertificateType, KEYM_CODE) KeyM_GetCertFormatTypeOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStartUpHandlingOfCertificateType, KEYM_CODE) KeyM_GetCertStartUpHandlingOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageEndIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageStartIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageStatusStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageStatusStartIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageWrittenLengthEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageWrittenLengthEndIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageWrittenLengthStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageWrittenLengthStartIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertUpperHierarchicalCertRefIdxOfCertificateType, KEYM_CODE) KeyM_GetCertUpperHierarchicalCertRefIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertUpperHierarchicalTypeOfCertificateType, KEYM_CODE) KeyM_GetCertUpperHierarchicalTypeOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateElementEndIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateElementStartIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGetCurrentTimeCalloutIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateGetCurrentTimeCalloutIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGroupIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateGroupIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueInfoIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateInitValueInfoIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateNameEndIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateNameStartIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_MaskedBitsOfCertificateType, KEYM_CODE) KeyM_GetMaskedBitsOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_MaxLengthOfCertificateType, KEYM_CODE) KeyM_GetMaxLengthOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_NvmBlockIdxOfCertificateType, KEYM_CODE) KeyM_GetNvmBlockIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_SlotRefIdxOfCertificateType, KEYM_CODE) KeyM_GetSlotRefIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_StorageOfCertificateType, KEYM_CODE) KeyM_GetStorageOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertElementPathEndIdxOfCertificateElementType, KEYM_CODE) KeyM_GetCertElementPathEndIdxOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertElementPathStartIdxOfCertificateElementType, KEYM_CODE) KeyM_GetCertElementPathStartIdxOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidEndIdxOfCertificateElementType, KEYM_CODE) KeyM_GetElementOidEndIdxOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidStartIdxOfCertificateElementType, KEYM_CODE) KeyM_GetElementOidStartIdxOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_IdOfCertificateElementType, KEYM_CODE) KeyM_GetIdOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_MaskedBitsOfCertificateElementType, KEYM_CODE) KeyM_GetMaskedBitsOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_MaxLengthOfCertificateElementType, KEYM_CODE) KeyM_GetMaxLengthOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ObjectTypeOfCertificateElementType, KEYM_CODE) KeyM_GetObjectTypeOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateStructureType, KEYM_CODE) KeyM_GetOfStructureOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGetCurrentTimeCalloutFctPtrType, KEYM_CODE) KeyM_GetCertificateGetCurrentTimeCallout(KeyM_CertificateGetCurrentTimeCalloutIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGroupVerifyCallbackNotificationIdxOfCertificateGroupType, KEYM_CODE) KeyM_GetCertificateGroupVerifyCallbackNotificationIdxOfCertificateGroup(KeyM_CertificateGroupIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateRemoteGroupIdOfCertificateGroupType, KEYM_CODE) KeyM_GetCertificateRemoteGroupIdOfCertificateGroup(KeyM_CertificateGroupIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidPrimaryEndIdxOfCertificateGroupType, KEYM_CODE) KeyM_GetElementOidPrimaryEndIdxOfCertificateGroup(KeyM_CertificateGroupIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidPrimaryStartIdxOfCertificateGroupType, KEYM_CODE) KeyM_GetElementOidPrimaryStartIdxOfCertificateGroup(KeyM_CertificateGroupIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidSecondaryEndIdxOfCertificateGroupType, KEYM_CODE) KeyM_GetElementOidSecondaryEndIdxOfCertificateGroup(KeyM_CertificateGroupIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidSecondaryStartIdxOfCertificateGroupType, KEYM_CODE) KeyM_GetElementOidSecondaryStartIdxOfCertificateGroup(KeyM_CertificateGroupIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_GroupIndCertEndIdxOfCertificateGroupType, KEYM_CODE) KeyM_GetGroupIndCertEndIdxOfCertificateGroup(KeyM_CertificateGroupIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_GroupIndCertStartIdxOfCertificateGroupType, KEYM_CODE) KeyM_GetGroupIndCertStartIdxOfCertificateGroup(KeyM_CertificateGroupIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_GroupIndIssuerEndIdxOfCertificateGroupType, KEYM_CODE) KeyM_GetGroupIndIssuerEndIdxOfCertificateGroup(KeyM_CertificateGroupIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_GroupIndIssuerStartIdxOfCertificateGroupType, KEYM_CODE) KeyM_GetGroupIndIssuerStartIdxOfCertificateGroup(KeyM_CertificateGroupIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGroupEndIdxOfCertificateGroupExtType, KEYM_CODE) KeyM_GetCertificateGroupEndIdxOfCertificateGroupExt(KeyM_CertificateGroupExtIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGroupLengthOfCertificateGroupExtType, KEYM_CODE) KeyM_GetCertificateGroupLengthOfCertificateGroupExt(KeyM_CertificateGroupExtIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGroupVerifyCallbackNotificationFctPtrType, KEYM_CODE) KeyM_GetCertificateGroupVerifyCallbackNotification(KeyM_CertificateGroupVerifyCallbackNotificationIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitCalloutFctPtrType, KEYM_CODE) KeyM_GetCertificateInitCallout(KeyM_CertificateInitCalloutIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueType, KEYM_CODE) KeyM_GetCertificateInitValue(KeyM_CertificateInitValueIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitCalloutIdxOfCertificateInitValueInfoType, KEYM_CODE) KeyM_GetCertificateInitCalloutIdxOfCertificateInitValueInfo(KeyM_CertificateInitValueInfoIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueEndIdxOfCertificateInitValueInfoType, KEYM_CODE) KeyM_GetCertificateInitValueEndIdxOfCertificateInitValueInfo(KeyM_CertificateInitValueInfoIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueStartIdxOfCertificateInitValueInfoType, KEYM_CODE) KeyM_GetCertificateInitValueStartIdxOfCertificateInitValueInfo(KeyM_CertificateInitValueInfoIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameType, KEYM_CODE) KeyM_GetCertificateName(KeyM_CertificateNameIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_IdOfCertificateSlotType, KEYM_CODE) KeyM_GetIdOfCertificateSlot(KeyM_CertificateSlotIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_MaxLengthOfCertificateSlotType, KEYM_CODE) KeyM_GetMaxLengthOfCertificateSlot(KeyM_CertificateSlotIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ConstCertDataType, KEYM_CODE) KeyM_GetCommonCertData(KeyM_CommonCertDataIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidType, KEYM_CODE) KeyM_GetElementOid(KeyM_ElementOidIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_Ans1_Element_Ref_Type, KEYM_CODE) KeyM_GetElementStorageRef(KeyM_ElementStorageRefIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_KeyMCsmRemoteInfoJobRefAsyncOfGeneralType, KEYM_CODE) KeyM_IsKeyMCsmRemoteInfoJobRefAsyncOfGeneral(KeyM_GeneralIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateIdxOfGroupIndType, KEYM_CODE) KeyM_GetCertificateIdxOfGroupInd(KeyM_GroupIndIterType Index);
KEYM_LOCAL_INLINE FUNC(tKeyMCertNvBlockStateType, KEYM_CODE) KeyM_GetNvBlock_State(KeyM_NvBlock_StateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertNvBlockProcessingOfNvmBlockType, KEYM_CODE) KeyM_GetCertNvBlockProcessingOfNvmBlock(KeyM_NvmBlockIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_DescriptorRefOfNvmBlockType, KEYM_CODE) KeyM_GetDescriptorRefOfNvmBlock(KeyM_NvmBlockIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_LengthOfNvmBlockType, KEYM_CODE) KeyM_GetLengthOfNvmBlock(KeyM_NvmBlockIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateIdType, KEYM_CODE) KeyM_GetSlotOwner(KeyM_SlotOwnerIterType Index);
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCGetBitDataInlineFunctionPrototypes  Get Bit Data Inline Function Prototypes
  \brief  These inline functions can be used to read bitcoded data elements.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCertAllowFlexibleElementOrderOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCertAllowUnconfiguredElementsOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCertCsmSignatureVerifyKeyRefValidOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCertPersistInvalidCertOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsKeyMCertCsmHashJobRefAsyncOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsKeyMCertCsmSignatureGenerateJobRefAsyncOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsKeyMCertCsmSignatureVerifyJobRefAsyncOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsHasIterationOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsOptionalOfCertificateElement(KeyM_CertificateElementIterType Index);
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCGetDeduplicatedInlineFunctionPrototypes  Get Deduplicated Inline Function Prototypes
  \brief  These inline functions  can be used to read deduplicated data elements.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageLengthOfCertificateType, KEYM_CODE) KeyM_GetCertStorageLengthOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageStatusEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageStatusEndIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageStatusLengthOfCertificateType, KEYM_CODE) KeyM_GetCertStorageStatusLengthOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageUsedOfCertificateType, KEYM_CODE) KeyM_IsCertStorageUsedOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageWrittenLengthLengthOfCertificateType, KEYM_CODE) KeyM_GetCertStorageWrittenLengthLengthOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageWrittenLengthUsedOfCertificateType, KEYM_CODE) KeyM_IsCertStorageWrittenLengthUsedOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementLengthOfCertificateType, KEYM_CODE) KeyM_GetCertificateElementLengthOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementUsedOfCertificateType, KEYM_CODE) KeyM_IsCertificateElementUsedOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGetCurrentTimeCalloutUsedOfCertificateType, KEYM_CODE) KeyM_IsCertificateGetCurrentTimeCalloutUsedOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGroupUsedOfCertificateType, KEYM_CODE) KeyM_IsCertificateGroupUsedOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueInfoUsedOfCertificateType, KEYM_CODE) KeyM_IsCertificateInitValueInfoUsedOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameLengthOfCertificateType, KEYM_CODE) KeyM_GetCertificateNameLengthOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateSlotUsedOfCertificateType, KEYM_CODE) KeyM_IsCertificateSlotUsedOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_NvmBlockUsedOfCertificateType, KEYM_CODE) KeyM_IsNvmBlockUsedOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_RemoteCertificateIdOfCertificateType, KEYM_CODE) KeyM_GetRemoteCertificateIdOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateChainMaxDepthOfGeneralType, KEYM_CODE) KeyM_GetCertificateChainMaxDepthOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_CertElementPathLengthOfCertificateElementType, KEYM_CODE) KeyM_GetCertElementPathLengthOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertElementPathUsedOfCertificateElementType, KEYM_CODE) KeyM_IsCertElementPathUsedOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidLengthOfCertificateElementType, KEYM_CODE) KeyM_GetElementOidLengthOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidUsedOfCertificateElementType, KEYM_CODE) KeyM_IsElementOidUsedOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateExtensionValidationEnabledOfGeneralType, KEYM_CODE) KeyM_IsCertificateExtensionValidationEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGroupVerifyCallbackNotificationUsedOfCertificateGroupType, KEYM_CODE) KeyM_IsCertificateGroupVerifyCallbackNotificationUsedOfCertificateGroup(KeyM_CertificateGroupIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidPrimaryLengthOfCertificateGroupType, KEYM_CODE) KeyM_GetElementOidPrimaryLengthOfCertificateGroup(KeyM_CertificateGroupIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidPrimaryUsedOfCertificateGroupType, KEYM_CODE) KeyM_IsElementOidPrimaryUsedOfCertificateGroup(KeyM_CertificateGroupIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidSecondaryLengthOfCertificateGroupType, KEYM_CODE) KeyM_GetElementOidSecondaryLengthOfCertificateGroup(KeyM_CertificateGroupIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidSecondaryUsedOfCertificateGroupType, KEYM_CODE) KeyM_IsElementOidSecondaryUsedOfCertificateGroup(KeyM_CertificateGroupIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_GroupIndCertLengthOfCertificateGroupType, KEYM_CODE) KeyM_GetGroupIndCertLengthOfCertificateGroup(KeyM_CertificateGroupIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_GroupIndIssuerLengthOfCertificateGroupType, KEYM_CODE) KeyM_GetGroupIndIssuerLengthOfCertificateGroup(KeyM_CertificateGroupIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGroupStartIdxOfCertificateGroupExtType, KEYM_CODE) KeyM_GetCertificateGroupStartIdxOfCertificateGroupExt(KeyM_CertificateGroupExtIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitCalloutUsedOfCertificateInitValueInfoType, KEYM_CODE) KeyM_IsCertificateInitCalloutUsedOfCertificateInitValueInfo(KeyM_CertificateInitValueInfoIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueLengthOfCertificateInitValueInfoType, KEYM_CODE) KeyM_GetCertificateInitValueLengthOfCertificateInitValueInfo(KeyM_CertificateInitValueInfoIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueUsedOfCertificateInitValueInfoType, KEYM_CODE) KeyM_IsCertificateInitValueUsedOfCertificateInitValueInfo(KeyM_CertificateInitValueInfoIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateManagerEnabledOfGeneralType, KEYM_CODE) KeyM_IsCertificateManagerEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateSigningRequestEnabledOfGeneralType, KEYM_CODE) KeyM_IsCertificateSigningRequestEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_CryptoKeyPrepareFunctionEnabledOfGeneralType, KEYM_CODE) KeyM_IsCryptoKeyPrepareFunctionEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_CryptoKeyStartFinalizeFunctionEnabledOfGeneralType, KEYM_CODE) KeyM_IsCryptoKeyStartFinalizeFunctionEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_CryptoKeyVerifyAsyncModeOfGeneralType, KEYM_CODE) KeyM_IsCryptoKeyVerifyAsyncModeOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_CryptoKeyVerifyFunctionEnabledOfGeneralType, KEYM_CODE) KeyM_IsCryptoKeyVerifyFunctionEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_KeyCertNameMaxLengthOfGeneralType, KEYM_CODE) KeyM_GetKeyCertNameMaxLengthOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_MainFunctionPeriodOfGeneralType, KEYM_CODE) KeyM_GetMainFunctionPeriodOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_ParseMaxNestingLevelOfGeneralType, KEYM_CODE) KeyM_GetParseMaxNestingLevelOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_ServiceCertificateFunctionEnabledOfGeneralType, KEYM_CODE) KeyM_IsServiceCertificateFunctionEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertElementPathType, KEYM_CODE) KeyM_GetSizeOfCertElementPath(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertStorageType, KEYM_CODE) KeyM_GetSizeOfCertStorage(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_CertInfoType, KEYM_CODE) KeyM_GetSizeOfCert_CertInfo(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_LeafCertsToVerifyType, KEYM_CODE) KeyM_GetSizeOfCert_LeafCertsToVerify(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_LockType, KEYM_CODE) KeyM_GetSizeOfCert_Lock(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_StorageTypeType, KEYM_CODE) KeyM_GetSizeOfCert_StorageType(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_VerifyChainType, KEYM_CODE) KeyM_GetSizeOfCert_VerifyChain(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateType, KEYM_CODE) KeyM_GetSizeOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateElementType, KEYM_CODE) KeyM_GetSizeOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateGetCurrentTimeCalloutType, KEYM_CODE) KeyM_GetSizeOfCertificateGetCurrentTimeCallout(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateGroupType, KEYM_CODE) KeyM_GetSizeOfCertificateGroup(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateGroupExtType, KEYM_CODE) KeyM_GetSizeOfCertificateGroupExt(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateGroupVerifyCallbackNotificationType, KEYM_CODE) KeyM_GetSizeOfCertificateGroupVerifyCallbackNotification(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateInitCalloutType, KEYM_CODE) KeyM_GetSizeOfCertificateInitCallout(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateInitValueType, KEYM_CODE) KeyM_GetSizeOfCertificateInitValue(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateInitValueInfoType, KEYM_CODE) KeyM_GetSizeOfCertificateInitValueInfo(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateNameType, KEYM_CODE) KeyM_GetSizeOfCertificateName(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateSlotType, KEYM_CODE) KeyM_GetSizeOfCertificateSlot(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCommonCertDataType, KEYM_CODE) KeyM_GetSizeOfCommonCertData(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfElementOidType, KEYM_CODE) KeyM_GetSizeOfElementOid(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfElementStorageRefType, KEYM_CODE) KeyM_GetSizeOfElementStorageRef(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfGeneralType, KEYM_CODE) KeyM_GetSizeOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfGroupIndType, KEYM_CODE) KeyM_GetSizeOfGroupInd(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfNvBlock_StateType, KEYM_CODE) KeyM_GetSizeOfNvBlock_State(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfNvmBlockType, KEYM_CODE) KeyM_GetSizeOfNvmBlock(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfSlotOwnerType, KEYM_CODE) KeyM_GetSizeOfSlotOwner(void);
KEYM_LOCAL_INLINE FUNC(KeyM_VersionInfoApiOfGeneralType, KEYM_CODE) KeyM_IsVersionInfoApiOfGeneral(void);
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCSetDataInlineFunctionPrototypes  Set Data Inline Function Prototypes
  \brief  These inline functions can be used to write data.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCertStorage(KeyM_CertStorageIterType Index, KeyM_CertStorageType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCert_CertInfo(KeyM_Cert_CertInfoIterType Index, tKeyMCertInfoType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index, KeyM_CertificateIdType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCert_Lock(KeyM_Cert_LockIterType Index, KeyM_Cert_LockType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCert_StorageType(KeyM_Cert_StorageTypeIterType Index, tKeyMCertStorageType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index, KeyM_CertificateIdType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCommonCertData(KeyM_CommonCertDataIterType Index, KeyM_ConstCertDataType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetElementStorageRef(KeyM_ElementStorageRefIterType Index, KeyM_Ans1_Element_Ref_Type Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetNvBlock_State(KeyM_NvBlock_StateIterType Index, tKeyMCertNvBlockStateType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetSlotOwner(KeyM_SlotOwnerIterType Index, KeyM_CertificateIdType Value);
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCGetAddressOfDataInlineFunctionPrototypes  Get Address Of Data Inline Function Prototypes
  \brief  These inline functions can be used to get the data by the address operator.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertElementPathPtrType, KEYM_CODE) KeyM_GetAddrCertElementPath(KeyM_CertElementPathIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStoragePtrType, KEYM_CODE) KeyM_GetAddrCertStorage(KeyM_CertStorageIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_Cert_CertInfoPtrType, KEYM_CODE) KeyM_GetAddrCert_CertInfo(KeyM_Cert_CertInfoIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_Cert_LockPtrType, KEYM_CODE) KeyM_GetAddrCert_Lock(KeyM_Cert_LockIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_Cert_StorageTypePtrType, KEYM_CODE) KeyM_GetAddrCert_StorageType(KeyM_Cert_StorageTypeIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValuePtrType, KEYM_CODE) KeyM_GetAddrCertificateInitValue(KeyM_CertificateInitValueIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNamePtrType, KEYM_CODE) KeyM_GetAddrCertificateName(KeyM_CertificateNameIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CommonCertDataPtrType, KEYM_CODE) KeyM_GetAddrCommonCertData(KeyM_CommonCertDataIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidPtrType, KEYM_CODE) KeyM_GetAddrElementOid(KeyM_ElementOidIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementStorageRefPtrType, KEYM_CODE) KeyM_GetAddrElementStorageRef(KeyM_ElementStorageRefIterType Index);
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCHasInlineFunctionPrototypes  Has Inline Function Prototypes
  \brief  These inline functions can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertElementPath(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorage(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_CertInfo(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_LeafCertsToVerify(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_Lock(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_StorageType(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_VerifyChain(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertAlgorithmFamilyOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertAllowFlexibleElementOrderOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertAllowUnconfiguredElementsOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertCsmSignatureVerifyJobRefOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertCsmSignatureVerifyKeyRefOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertCsmSignatureVerifyKeyRefValidOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertFormatTypeOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertPersistInvalidCertOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStartUpHandlingOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageEndIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageLengthOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageStartIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageStatusEndIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageStatusLengthOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageStatusStartIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageUsedOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageWrittenLengthEndIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageWrittenLengthLengthOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageWrittenLengthStartIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageWrittenLengthUsedOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertUpperHierarchicalCertRefIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertUpperHierarchicalTypeOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementEndIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementLengthOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementStartIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementUsedOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCalloutIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCalloutUsedOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupUsedOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueInfoIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueInfoUsedOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateNameEndIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateNameLengthOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateNameStartIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateSlotUsedOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyMCertCsmHashJobRefAsyncOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyMCertCsmSignatureGenerateJobRefAsyncOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyMCertCsmSignatureVerifyJobRefAsyncOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMaskedBitsOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMaxLengthOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasNvmBlockIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasNvmBlockUsedOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasRemoteCertificateIdOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSlotRefIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasStorageOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateChainMaxDepthOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertElementPathEndIdxOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertElementPathLengthOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertElementPathStartIdxOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertElementPathUsedOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidEndIdxOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidLengthOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidStartIdxOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidUsedOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasHasIterationOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasIdOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMaskedBitsOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMaxLengthOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasObjectTypeOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasOfStructureOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasOptionalOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateExtensionValidationEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCallout(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroup(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupVerifyCallbackNotificationIdxOfCertificateGroup(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupVerifyCallbackNotificationUsedOfCertificateGroup(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateRemoteGroupIdOfCertificateGroup(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidPrimaryEndIdxOfCertificateGroup(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidPrimaryLengthOfCertificateGroup(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidPrimaryStartIdxOfCertificateGroup(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidPrimaryUsedOfCertificateGroup(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidSecondaryEndIdxOfCertificateGroup(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidSecondaryLengthOfCertificateGroup(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidSecondaryStartIdxOfCertificateGroup(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidSecondaryUsedOfCertificateGroup(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGroupIndCertEndIdxOfCertificateGroup(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGroupIndCertLengthOfCertificateGroup(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGroupIndCertStartIdxOfCertificateGroup(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGroupIndIssuerEndIdxOfCertificateGroup(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGroupIndIssuerLengthOfCertificateGroup(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGroupIndIssuerStartIdxOfCertificateGroup(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupExt(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupEndIdxOfCertificateGroupExt(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupLengthOfCertificateGroupExt(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupStartIdxOfCertificateGroupExt(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupVerifyCallbackNotification(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitCallout(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValue(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueInfo(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitCalloutIdxOfCertificateInitValueInfo(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitCalloutUsedOfCertificateInitValueInfo(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueEndIdxOfCertificateInitValueInfo(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueLengthOfCertificateInitValueInfo(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueStartIdxOfCertificateInitValueInfo(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueUsedOfCertificateInitValueInfo(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateManagerEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateName(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateSigningRequestEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateSlot(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasIdOfCertificateSlot(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMaxLengthOfCertificateSlot(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCommonCertData(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyPrepareFunctionEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyStartFinalizeFunctionEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyVerifyAsyncModeOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyVerifyFunctionEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOid(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementStorageRef(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyMCsmRemoteInfoJobRefAsyncOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGroupInd(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateIdxOfGroupInd(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyCertNameMaxLengthOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMainFunctionPeriodOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasNvBlock_State(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasNvmBlock(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertNvBlockProcessingOfNvmBlock(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasDescriptorRefOfNvmBlock(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasLengthOfNvmBlock(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasParseMaxNestingLevelOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasServiceCertificateFunctionEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertElementPath(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertStorage(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_CertInfo(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_LeafCertsToVerify(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_Lock(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_StorageType(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_VerifyChain(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGetCurrentTimeCallout(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGroup(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGroupExt(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGroupVerifyCallbackNotification(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateInitCallout(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateInitValue(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateInitValueInfo(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateName(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateSlot(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCommonCertData(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfElementOid(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfElementStorageRef(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfGroupInd(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfNvBlock_State(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfNvmBlock(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfSlotOwner(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSlotOwner(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasVersionInfoApiOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertElementPathOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_CertInfoOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_LeafCertsToVerifyOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_LockOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_StorageTypeOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_VerifyChainOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateChainMaxDepthOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateExtensionValidationEnabledOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCalloutOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupExtOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupVerifyCallbackNotificationOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitCalloutOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueInfoOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateManagerEnabledOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateNameOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateSigningRequestEnabledOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateSlotOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCommonCertDataOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyPrepareFunctionEnabledOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyStartFinalizeFunctionEnabledOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyVerifyAsyncModeOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyVerifyFunctionEnabledOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementStorageRefOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGroupIndOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyCertNameMaxLengthOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMainFunctionPeriodOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasNvBlock_StateOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasNvmBlockOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasParseMaxNestingLevelOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasServiceCertificateFunctionEnabledOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertElementPathOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertStorageOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_CertInfoOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_LeafCertsToVerifyOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_LockOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_StorageTypeOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_VerifyChainOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateElementOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGetCurrentTimeCalloutOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGroupExtOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGroupOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGroupVerifyCallbackNotificationOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateInitCalloutOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateInitValueInfoOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateInitValueOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateNameOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateSlotOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCommonCertDataOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfElementOidOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfElementStorageRefOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfGroupIndOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfNvBlock_StateOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfNvmBlockOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfSlotOwnerOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSlotOwnerOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasVersionInfoApiOfGeneralOfPCConfig(void);
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCIncrementInlineFunctionPrototypes  Increment Inline Function Prototypes
  \brief  These inline functions can be used to increment VAR data with numerical nature.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_IncCertStorage(KeyM_CertStorageIterType Index);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_IncCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_IncCert_StorageType(KeyM_Cert_StorageTypeIterType Index);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_IncCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_IncNvBlock_State(KeyM_NvBlock_StateIterType Index);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_IncSlotOwner(KeyM_SlotOwnerIterType Index);
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCDecrementInlineFunctionPrototypes  Decrement Inline Function Prototypes
  \brief  These inline functions can be used to decrement VAR data with numerical nature.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_DecCertStorage(KeyM_CertStorageIterType Index);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_DecCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_DecCert_StorageType(KeyM_Cert_StorageTypeIterType Index);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_DecCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_DecNvBlock_State(KeyM_NvBlock_StateIterType Index);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_DecSlotOwner(KeyM_SlotOwnerIterType Index);
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCAddInlineFunctionPrototypes  Add Inline Function Prototypes
  \brief  These inline functions can be used to add VAR data with numerical nature.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_AddCertStorage(KeyM_CertStorageIterType Index, KeyM_CertStorageType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_AddCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index, KeyM_CertificateIdType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_AddCert_StorageType(KeyM_Cert_StorageTypeIterType Index, tKeyMCertStorageType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_AddCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index, KeyM_CertificateIdType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_AddNvBlock_State(KeyM_NvBlock_StateIterType Index, tKeyMCertNvBlockStateType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_AddSlotOwner(KeyM_SlotOwnerIterType Index, KeyM_CertificateIdType Value);
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCSubstractInlineFunctionPrototypes  Substract Inline Function Prototypes
  \brief  These inline functions can be used to substract VAR data with numerical nature.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SubCertStorage(KeyM_CertStorageIterType Index, KeyM_CertStorageType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SubCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index, KeyM_CertificateIdType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SubCert_StorageType(KeyM_Cert_StorageTypeIterType Index, tKeyMCertStorageType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SubCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index, KeyM_CertificateIdType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SubNvBlock_State(KeyM_NvBlock_StateIterType Index, tKeyMCertNvBlockStateType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SubSlotOwner(KeyM_SlotOwnerIterType Index, KeyM_CertificateIdType Value);
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
 *  ReadFromBlock
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_NvBlock_ReadFrom_Scc_Certificate_ISO2_ContractCertificate_0
 * \fn          KeyM_NvBlock_ReadFrom_Scc_Certificate_ISO2_MOSubCA1_0
 * \fn          KeyM_NvBlock_ReadFrom_Scc_Certificate_ISO2_MOSubCA2_0
 * \fn          KeyM_NvBlock_ReadFrom_SccCertificate_ISO20_EMSPContract_0_ECDSA
 * \fn          KeyM_NvBlock_ReadFrom_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA
 * \fn          KeyM_NvBlock_ReadFrom_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA
 * \brief       Block specific callback routine which is called by NvM in order to let the KeyM copy data from NvM RAM
 *              mirror to KeyM RAM block. 
 * \param[in]   NvMBuffer   RAM mirror where Ram block data can be read from.
 * \return      E_OK      Data was copied from buffer.
 * \return      E_NOT_OK  Data was not copied.
 * \pre         -
 * \reentrant   FALSE
 * \synchronous TRUE
 */
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_ReadFrom_Scc_Certificate_ISO2_ContractCertificate_0(P2CONST(void, AUTOMATIC, KEYM_APPL_DATA) NvMBuffer);
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_ReadFrom_Scc_Certificate_ISO2_MOSubCA1_0(P2CONST(void, AUTOMATIC, KEYM_APPL_DATA) NvMBuffer);
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_ReadFrom_Scc_Certificate_ISO2_MOSubCA2_0(P2CONST(void, AUTOMATIC, KEYM_APPL_DATA) NvMBuffer);
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_ReadFrom_SccCertificate_ISO20_EMSPContract_0_ECDSA(P2CONST(void, AUTOMATIC, KEYM_APPL_DATA) NvMBuffer);
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_ReadFrom_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA(P2CONST(void, AUTOMATIC, KEYM_APPL_DATA) NvMBuffer);
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_ReadFrom_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA(P2CONST(void, AUTOMATIC, KEYM_APPL_DATA) NvMBuffer);

/**********************************************************************************************************************
 *  WriteToBlock
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_NvBlock_WriteTo_Scc_Certificate_ISO2_ContractCertificate_0
 * \fn          KeyM_NvBlock_WriteTo_Scc_Certificate_ISO2_MOSubCA1_0
 * \fn          KeyM_NvBlock_WriteTo_Scc_Certificate_ISO2_MOSubCA2_0
 * \fn          KeyM_NvBlock_WriteTo_SccCertificate_ISO20_EMSPContract_0_ECDSA
 * \fn          KeyM_NvBlock_WriteTo_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA
 * \fn          KeyM_NvBlock_WriteTo_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA
 * \brief       Block specific callback routine which is called by NvM in order to let the KeyM copy data from RAM block
 *              to NvM RAM mirror.
 * \param[out]  NvMBuffer  RAM mirror where Ram block data shall be written to.
 * \return      E_OK      Data was copied to buffer.
 * \return      E_NOT_OK  No data was copied.
 * \pre         -
 * \reentrant   FALSE
 * \synchronous TRUE
 */
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_WriteTo_Scc_Certificate_ISO2_ContractCertificate_0(P2VAR(void, AUTOMATIC, KEYM_APPL_VAR) NvMBuffer);
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_WriteTo_Scc_Certificate_ISO2_MOSubCA1_0(P2VAR(void, AUTOMATIC, KEYM_APPL_VAR) NvMBuffer);
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_WriteTo_Scc_Certificate_ISO2_MOSubCA2_0(P2VAR(void, AUTOMATIC, KEYM_APPL_VAR) NvMBuffer);
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_WriteTo_SccCertificate_ISO20_EMSPContract_0_ECDSA(P2VAR(void, AUTOMATIC, KEYM_APPL_VAR) NvMBuffer);
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_WriteTo_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA(P2VAR(void, AUTOMATIC, KEYM_APPL_VAR) NvMBuffer);
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_WriteTo_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA(P2VAR(void, AUTOMATIC, KEYM_APPL_VAR) NvMBuffer);

/**********************************************************************************************************************
 *  InitBlock
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_NvBlock_Init_Scc_Certificate_ISO2_ContractCertificate_0
 * \fn          KeyM_NvBlock_Init_Scc_Certificate_ISO2_MOSubCA1_0
 * \fn          KeyM_NvBlock_Init_Scc_Certificate_ISO2_MOSubCA2_0
 * \fn          KeyM_NvBlock_Init_SccCertificate_ISO20_EMSPContract_0_ECDSA
 * \fn          KeyM_NvBlock_Init_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA
 * \fn          KeyM_NvBlock_Init_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA
 * \brief       Block specific callback routine which is called by NvM in order to let the KeyM copy default data to a
 *              RAM block.
 * \return      E_OK      Data initialized.
 * \return      E_NOT_OK  Any error occurred.
 * \pre         -
 * \reentrant   FALSE
 * \synchronous TRUE
 */
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Init_Scc_Certificate_ISO2_ContractCertificate_0(void);
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Init_Scc_Certificate_ISO2_MOSubCA1_0(void);
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Init_Scc_Certificate_ISO2_MOSubCA2_0(void);
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Init_SccCertificate_ISO20_EMSPContract_0_ECDSA(void);
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Init_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA(void);
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Init_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA(void);

/**********************************************************************************************************************
 *  CallbackBlock
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_NvBlock_Callback_Scc_Certificate_ISO2_ContractCertificate_0
 * \fn          KeyM_NvBlock_Callback_Scc_Certificate_ISO2_MOSubCA1_0
 * \fn          KeyM_NvBlock_Callback_Scc_Certificate_ISO2_MOSubCA2_0
 * \fn          KeyM_NvBlock_Callback_SccCertificate_ISO20_EMSPContract_0_ECDSA
 * \fn          KeyM_NvBlock_Callback_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA
 * \fn          KeyM_NvBlock_Callback_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA
 * \brief       Block specific callback routine which is called by NvM in order to notify the KeyM that an asynchronous
 *              single block request has been finished.
 * \param[in]   uint8                  The service identifier of the completed request.
 * \param[in]   NvM_RequestResultType  Result of the single block job.
 * \return      E_OK      Callback function has been processed successfully.
 * \return      E_NOT_OK  Callback function has not been processed successfully.
 * \pre         -
 * \reentrant   FALSE
 * \synchronous TRUE
 */
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Callback_Scc_Certificate_ISO2_ContractCertificate_0(uint8 ServiceId, NvM_RequestResultType JobResult);
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Callback_Scc_Certificate_ISO2_MOSubCA1_0(uint8 ServiceId, NvM_RequestResultType JobResult);
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Callback_Scc_Certificate_ISO2_MOSubCA2_0(uint8 ServiceId, NvM_RequestResultType JobResult);
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Callback_SccCertificate_ISO20_EMSPContract_0_ECDSA(uint8 ServiceId, NvM_RequestResultType JobResult);
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Callback_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA(uint8 ServiceId, NvM_RequestResultType JobResult);
extern FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Callback_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA(uint8 ServiceId, NvM_RequestResultType JobResult);
#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



# define KEYM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * KeyM_Cert_IsBusy()
 *********************************************************************************************************************/
/*! \brief         Check if KeyM Cert submodule is busy.
 *  \details       -
 *  \return        TRUE            KeyM is busy with a task.
 *                 FALSE           KeyM is in idle state.
 *  \pre           The KeyM is initialized in advance.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(boolean, KEYM_CODE) KeyM_Cert_IsBusy(void);

# define KEYM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define KEYM_START_SEC_APPL_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Certificate Group Verify Callback Notification Prototypes
 *********************************************************************************************************************/
/*!
 * \fn          Scc_Cbk_KeyM_GroupUpdateStatus
 * \fn          Scc_Cbk_KeyM_OEMProvGroupVerifyResult
 * \brief       Indicate result of the certificate group verification operation.
 * \details     Notifies the application that a certificate group verification has been finished. The function name is
 *              configurable by KeyMCertificateGroupVerifyCallbackNotificationFunc.
 * \param[in]   GroupId  Holds the certificate group identifier.
 * \param[in]   Result   Contains information about the result of the operation.
 * \return      E_OK      Operation successful
 * \return      E_NOT_OK  Operation failed
 * \pre         -
 * \reentrant   TRUE
 * \synchronous TRUE
 */
extern FUNC(Std_ReturnType, KEYM_APPL_CODE) Scc_Cbk_KeyM_GroupUpdateStatus(KeyM_CertificateGroupIdType GroupId, KeyM_CertificateGroupStatusType Result );
extern FUNC(Std_ReturnType, KEYM_APPL_CODE) Scc_Cbk_KeyM_OEMProvGroupVerifyResult(KeyM_CertificateGroupIdType GroupId, KeyM_CertificateGroupStatusType Result );

/**********************************************************************************************************************
 *  Certificate Get Current Time Callout Prototypes
 *********************************************************************************************************************/
/*!
 * \fn          Appl_KeyMCertificateGetCurrentTimeCalloutFunc
 * \brief       Provide current time
 * \details     Provide current time to verify certificate time stamp.
 * \param[in]   CertId     Certificate identifier.
 * \param[out]  timeStamp  Current time in Unix time format.
 * \return      E_OK                             Operation successful
 * \return      E_NOT_OK                         Operation failed
 * \return      KEYM_E_NO_PERIOD_VALIDITY_CHECK  Skip time stamp validation
 * \pre         -
 * \reentrant   TRUE
 * \synchronous TRUE
 */
extern FUNC(Std_ReturnType, KEYM_APPL_CODE) Appl_KeyMCertificateGetCurrentTimeCalloutFunc( KeyM_CertificateIdType CertId,  P2VAR(uint64, AUTOMATIC, KEYM_APPL_VAR) timeStamp);

/**********************************************************************************************************************
 *  Certificate Init Callout Prototypes
 *********************************************************************************************************************/
/*!
 * \fn          Appl_ISO20_EMSPContract_0_InitCalloutFunc
 * \fn          Appl_ISO20_EMSPSubCA1_0_InitCalloutFunc
 * \fn          Appl_ISO20_EMSPSubCA2_0_InitCalloutFunc
 * \fn          Appl_KeyMCertificateCertInit_ISO2_ContractCertificate_0
 * \fn          Appl_KeyMCertificateCertInit_ISO2_MOSubCA1_0
 * \fn          Appl_KeyMCertificateCertInit_ISO2_MOSubCA2_0
 * \fn          Appl_KeyMCertificateCertInit_ISO2_OEMProvCertificate_0
 * \fn          Appl_KeyMCertificateCertInit_V2G_Root_0
 * \fn          Appl_KeyMCertificateCertInit_V2G_Root_1
 * \fn          Appl_KeyMCertificateCertInit_V2G_Root_2
 * \fn          Appl_KeyMCertificateCertInit_V2G_Root_3
 * \fn          Appl_KeyMCertificateCertInit_V2G_Root_4
 * \fn          Appl_KeyMCertificateCertInit_V2G_Root_5
 * \fn          Appl_KeyMCertificateCertInit_V2G_Root_6
 * \fn          Appl_KeyMCertificateCertInit_V2G_Root_7
 * \fn          Appl_KeyMCertificateCertInit_V2G_Root_8
 * \fn          Appl_KeyMCertificateCertInit_V2G_Root_9
 * \fn          Appl_KeyMCertificateCertInit_V2G_Root_10
 * \brief       Provide the certificate data during initialization
 * \param[in]   CertId              Certificate identifier.
 * \param[in,out]CertificateDataPtr  Provides a pointer to a certificate data structure. The buffer located by the
 *                                   pointer in the structure shall be provided by the caller of this function. The
 *                                   length information indicates the maximum length of the buffer when the function is
 *                                   called. When the function returns, the length information indicates the actual
 *                                   length of the certificate data in the buffer.
 * \pre         -
 * \reentrant   TRUE
 * \synchronous TRUE
 */
extern FUNC(void, KEYM_APPL_CODE) Appl_ISO20_EMSPContract_0_InitCalloutFunc( KeyM_CertificateIdType CertId,  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);
extern FUNC(void, KEYM_APPL_CODE) Appl_ISO20_EMSPSubCA1_0_InitCalloutFunc( KeyM_CertificateIdType CertId,  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);
extern FUNC(void, KEYM_APPL_CODE) Appl_ISO20_EMSPSubCA2_0_InitCalloutFunc( KeyM_CertificateIdType CertId,  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);
extern FUNC(void, KEYM_APPL_CODE) Appl_KeyMCertificateCertInit_ISO2_ContractCertificate_0( KeyM_CertificateIdType CertId,  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);
extern FUNC(void, KEYM_APPL_CODE) Appl_KeyMCertificateCertInit_ISO2_MOSubCA1_0( KeyM_CertificateIdType CertId,  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);
extern FUNC(void, KEYM_APPL_CODE) Appl_KeyMCertificateCertInit_ISO2_MOSubCA2_0( KeyM_CertificateIdType CertId,  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);
extern FUNC(void, KEYM_APPL_CODE) Appl_KeyMCertificateCertInit_ISO2_OEMProvCertificate_0( KeyM_CertificateIdType CertId,  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);
extern FUNC(void, KEYM_APPL_CODE) Appl_KeyMCertificateCertInit_V2G_Root_0( KeyM_CertificateIdType CertId,  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);
extern FUNC(void, KEYM_APPL_CODE) Appl_KeyMCertificateCertInit_V2G_Root_1( KeyM_CertificateIdType CertId,  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);
extern FUNC(void, KEYM_APPL_CODE) Appl_KeyMCertificateCertInit_V2G_Root_2( KeyM_CertificateIdType CertId,  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);
extern FUNC(void, KEYM_APPL_CODE) Appl_KeyMCertificateCertInit_V2G_Root_3( KeyM_CertificateIdType CertId,  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);
extern FUNC(void, KEYM_APPL_CODE) Appl_KeyMCertificateCertInit_V2G_Root_4( KeyM_CertificateIdType CertId,  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);
extern FUNC(void, KEYM_APPL_CODE) Appl_KeyMCertificateCertInit_V2G_Root_5( KeyM_CertificateIdType CertId,  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);
extern FUNC(void, KEYM_APPL_CODE) Appl_KeyMCertificateCertInit_V2G_Root_6( KeyM_CertificateIdType CertId,  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);
extern FUNC(void, KEYM_APPL_CODE) Appl_KeyMCertificateCertInit_V2G_Root_7( KeyM_CertificateIdType CertId,  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);
extern FUNC(void, KEYM_APPL_CODE) Appl_KeyMCertificateCertInit_V2G_Root_8( KeyM_CertificateIdType CertId,  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);
extern FUNC(void, KEYM_APPL_CODE) Appl_KeyMCertificateCertInit_V2G_Root_9( KeyM_CertificateIdType CertId,  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);
extern FUNC(void, KEYM_APPL_CODE) Appl_KeyMCertificateCertInit_V2G_Root_10( KeyM_CertificateIdType CertId,  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);

# define KEYM_STOP_SEC_APPL_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* PRQA S 2995, 2996 InlineFunctions_2995_2996 */ /* MD_KEYM_2.2, MD_KEYM_2.2 */


#if !defined (KEYM_NOUNIT_CSLUNIT)
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/
#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCGetDataInlineFunctions  KeyM Get Data Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to read CONST and VAR data.
  \{
*/ 
/*! \spec requires Index < KeyM_GetSizeOfCertElementPath(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertElementPathType, KEYM_CODE) KeyM_GetCertElementPath(KeyM_CertElementPathIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertElementPathType) (KeyM_GetCertElementPathOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCertStorage(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageType, KEYM_CODE) KeyM_GetCertStorage(KeyM_CertStorageIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageType) (KeyM_GetCertStorageOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCert_CertInfo(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(tKeyMCertInfoType, KEYM_CODE) KeyM_GetCert_CertInfo(KeyM_Cert_CertInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_GetCert_CertInfoOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCert_LeafCertsToVerify(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateIdType, KEYM_CODE) KeyM_GetCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateIdType) (KeyM_GetCert_LeafCertsToVerifyOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCert_Lock(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_Cert_LockType, KEYM_CODE) KeyM_IsCert_Lock(KeyM_Cert_LockIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_Cert_LockType) ((KeyM_GetCert_LockOfPCConfig()[(Index)]) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCert_StorageType(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(tKeyMCertStorageType, KEYM_CODE) KeyM_GetCert_StorageType(KeyM_Cert_StorageTypeIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (tKeyMCertStorageType) (KeyM_GetCert_StorageTypeOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCert_VerifyChain(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateIdType, KEYM_CODE) KeyM_GetCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateIdType) (KeyM_GetCert_VerifyChainOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertAlgorithmFamilyOfCertificateType, KEYM_CODE) KeyM_GetCertAlgorithmFamilyOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertAlgorithmFamilyOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertAlgorithmFamilyOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertCsmSignatureVerifyJobRefOfCertificateType, KEYM_CODE) KeyM_GetCertCsmSignatureVerifyJobRefOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertCsmSignatureVerifyJobRefOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertCsmSignatureVerifyJobRefOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertCsmSignatureVerifyKeyRefOfCertificateType, KEYM_CODE) KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertCsmSignatureVerifyKeyRefOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertCsmSignatureVerifyKeyRefOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertFormatTypeOfCertificateType, KEYM_CODE) KeyM_GetCertFormatTypeOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertFormatTypeOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertFormatTypeOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStartUpHandlingOfCertificateType, KEYM_CODE) KeyM_GetCertStartUpHandlingOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStartUpHandlingOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertStartUpHandlingOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageEndIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageEndIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertStorageEndIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageStartIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageStartIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertStorageStartIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageStatusStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageStatusStartIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageStatusStartIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertStorageStatusStartIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageWrittenLengthEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageWrittenLengthEndIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageWrittenLengthEndIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertStorageWrittenLengthEndIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageWrittenLengthStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageWrittenLengthStartIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageWrittenLengthStartIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertStorageWrittenLengthStartIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertUpperHierarchicalCertRefIdxOfCertificateType, KEYM_CODE) KeyM_GetCertUpperHierarchicalCertRefIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertUpperHierarchicalCertRefIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertUpperHierarchicalCertRefIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertUpperHierarchicalTypeOfCertificateType, KEYM_CODE) KeyM_GetCertUpperHierarchicalTypeOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertUpperHierarchicalTypeOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertUpperHierarchicalTypeOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateElementEndIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateElementEndIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertificateElementEndIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateElementStartIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateElementStartIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertificateElementStartIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGetCurrentTimeCalloutIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateGetCurrentTimeCalloutIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateGetCurrentTimeCalloutIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertificateGetCurrentTimeCalloutIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGroupIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateGroupIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateGroupIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertificateGroupIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueInfoIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateInitValueInfoIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateInitValueInfoIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertificateInitValueInfoIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateNameEndIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateNameEndIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertificateNameEndIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateNameStartIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateNameStartIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertificateNameStartIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_MaskedBitsOfCertificateType, KEYM_CODE) KeyM_GetMaskedBitsOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_MaskedBitsOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].MaskedBitsOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_MaxLengthOfCertificateType, KEYM_CODE) KeyM_GetMaxLengthOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_MaxLengthOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].MaxLengthOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_NvmBlockIdxOfCertificateType, KEYM_CODE) KeyM_GetNvmBlockIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_NvmBlockIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].NvmBlockIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_SlotRefIdxOfCertificateType, KEYM_CODE) KeyM_GetSlotRefIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_SlotRefIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].SlotRefIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_StorageOfCertificateType, KEYM_CODE) KeyM_GetStorageOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_StorageOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].StorageOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertElementPathEndIdxOfCertificateElementType, KEYM_CODE) KeyM_GetCertElementPathEndIdxOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertElementPathEndIdxOfCertificateElementType) (KeyM_GetCertificateElementOfPCConfig()[(Index)].CertElementPathEndIdxOfCertificateElement);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertElementPathStartIdxOfCertificateElementType, KEYM_CODE) KeyM_GetCertElementPathStartIdxOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertElementPathStartIdxOfCertificateElementType) (KeyM_GetCertificateElementOfPCConfig()[(Index)].CertElementPathStartIdxOfCertificateElement);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidEndIdxOfCertificateElementType, KEYM_CODE) KeyM_GetElementOidEndIdxOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ElementOidEndIdxOfCertificateElementType) (KeyM_GetCertificateElementOfPCConfig()[(Index)].ElementOidEndIdxOfCertificateElement);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidStartIdxOfCertificateElementType, KEYM_CODE) KeyM_GetElementOidStartIdxOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ElementOidStartIdxOfCertificateElementType) (KeyM_GetCertificateElementOfPCConfig()[(Index)].ElementOidStartIdxOfCertificateElement);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_IdOfCertificateElementType, KEYM_CODE) KeyM_GetIdOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_IdOfCertificateElementType) (KeyM_GetCertificateElementOfPCConfig()[(Index)].IdOfCertificateElement);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_MaskedBitsOfCertificateElementType, KEYM_CODE) KeyM_GetMaskedBitsOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_MaskedBitsOfCertificateElementType) (KeyM_GetCertificateElementOfPCConfig()[(Index)].MaskedBitsOfCertificateElement);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_MaxLengthOfCertificateElementType, KEYM_CODE) KeyM_GetMaxLengthOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_MaxLengthOfCertificateElementType) (KeyM_GetCertificateElementOfPCConfig()[(Index)].MaxLengthOfCertificateElement);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ObjectTypeOfCertificateElementType, KEYM_CODE) KeyM_GetObjectTypeOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ObjectTypeOfCertificateElementType) (KeyM_GetCertificateElementOfPCConfig()[(Index)].ObjectTypeOfCertificateElement);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateStructureType, KEYM_CODE) KeyM_GetOfStructureOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateStructureType) (KeyM_GetCertificateElementOfPCConfig()[(Index)].OfStructureOfCertificateElement);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGetCurrentTimeCallout(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGetCurrentTimeCalloutFctPtrType, KEYM_CODE) KeyM_GetCertificateGetCurrentTimeCallout(KeyM_CertificateGetCurrentTimeCalloutIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateGetCurrentTimeCalloutFctPtrType) (KeyM_GetCertificateGetCurrentTimeCalloutOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroup(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGroupVerifyCallbackNotificationIdxOfCertificateGroupType, KEYM_CODE) KeyM_GetCertificateGroupVerifyCallbackNotificationIdxOfCertificateGroup(KeyM_CertificateGroupIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateGroupVerifyCallbackNotificationIdxOfCertificateGroupType) (KeyM_GetCertificateGroupOfPCConfig()[(Index)].CertificateGroupVerifyCallbackNotificationIdxOfCertificateGroup);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroup(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateRemoteGroupIdOfCertificateGroupType, KEYM_CODE) KeyM_GetCertificateRemoteGroupIdOfCertificateGroup(KeyM_CertificateGroupIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateRemoteGroupIdOfCertificateGroupType) (KeyM_GetCertificateGroupOfPCConfig()[(Index)].CertificateRemoteGroupIdOfCertificateGroup);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroup(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidPrimaryEndIdxOfCertificateGroupType, KEYM_CODE) KeyM_GetElementOidPrimaryEndIdxOfCertificateGroup(KeyM_CertificateGroupIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ElementOidPrimaryEndIdxOfCertificateGroupType) (KeyM_GetCertificateGroupOfPCConfig()[(Index)].ElementOidPrimaryEndIdxOfCertificateGroup);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroup(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidPrimaryStartIdxOfCertificateGroupType, KEYM_CODE) KeyM_GetElementOidPrimaryStartIdxOfCertificateGroup(KeyM_CertificateGroupIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ElementOidPrimaryStartIdxOfCertificateGroupType) (KeyM_GetCertificateGroupOfPCConfig()[(Index)].ElementOidPrimaryStartIdxOfCertificateGroup);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroup(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidSecondaryEndIdxOfCertificateGroupType, KEYM_CODE) KeyM_GetElementOidSecondaryEndIdxOfCertificateGroup(KeyM_CertificateGroupIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ElementOidSecondaryEndIdxOfCertificateGroupType) (KeyM_GetCertificateGroupOfPCConfig()[(Index)].ElementOidSecondaryEndIdxOfCertificateGroup);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroup(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidSecondaryStartIdxOfCertificateGroupType, KEYM_CODE) KeyM_GetElementOidSecondaryStartIdxOfCertificateGroup(KeyM_CertificateGroupIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ElementOidSecondaryStartIdxOfCertificateGroupType) (KeyM_GetCertificateGroupOfPCConfig()[(Index)].ElementOidSecondaryStartIdxOfCertificateGroup);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroup(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_GroupIndCertEndIdxOfCertificateGroupType, KEYM_CODE) KeyM_GetGroupIndCertEndIdxOfCertificateGroup(KeyM_CertificateGroupIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_GroupIndCertEndIdxOfCertificateGroupType) (KeyM_GetCertificateGroupOfPCConfig()[(Index)].GroupIndCertEndIdxOfCertificateGroup);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroup(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_GroupIndCertStartIdxOfCertificateGroupType, KEYM_CODE) KeyM_GetGroupIndCertStartIdxOfCertificateGroup(KeyM_CertificateGroupIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_GroupIndCertStartIdxOfCertificateGroupType) (KeyM_GetCertificateGroupOfPCConfig()[(Index)].GroupIndCertStartIdxOfCertificateGroup);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroup(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_GroupIndIssuerEndIdxOfCertificateGroupType, KEYM_CODE) KeyM_GetGroupIndIssuerEndIdxOfCertificateGroup(KeyM_CertificateGroupIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_GroupIndIssuerEndIdxOfCertificateGroupType) (KeyM_GetCertificateGroupOfPCConfig()[(Index)].GroupIndIssuerEndIdxOfCertificateGroup);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroup(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_GroupIndIssuerStartIdxOfCertificateGroupType, KEYM_CODE) KeyM_GetGroupIndIssuerStartIdxOfCertificateGroup(KeyM_CertificateGroupIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_GroupIndIssuerStartIdxOfCertificateGroupType) (KeyM_GetCertificateGroupOfPCConfig()[(Index)].GroupIndIssuerStartIdxOfCertificateGroup);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroupExt(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGroupEndIdxOfCertificateGroupExtType, KEYM_CODE) KeyM_GetCertificateGroupEndIdxOfCertificateGroupExt(KeyM_CertificateGroupExtIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateGroupEndIdxOfCertificateGroupExtType) (KeyM_GetCertificateGroupExtOfPCConfig()[(Index)].CertificateGroupEndIdxOfCertificateGroupExt);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroupExt(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGroupLengthOfCertificateGroupExtType, KEYM_CODE) KeyM_GetCertificateGroupLengthOfCertificateGroupExt(KeyM_CertificateGroupExtIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateGroupLengthOfCertificateGroupExtType) (KeyM_GetCertificateGroupExtOfPCConfig()[(Index)].CertificateGroupLengthOfCertificateGroupExt);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroupVerifyCallbackNotification(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGroupVerifyCallbackNotificationFctPtrType, KEYM_CODE) KeyM_GetCertificateGroupVerifyCallbackNotification(KeyM_CertificateGroupVerifyCallbackNotificationIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateGroupVerifyCallbackNotificationFctPtrType) (KeyM_GetCertificateGroupVerifyCallbackNotificationOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateInitCallout(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitCalloutFctPtrType, KEYM_CODE) KeyM_GetCertificateInitCallout(KeyM_CertificateInitCalloutIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateInitCalloutFctPtrType) (KeyM_GetCertificateInitCalloutOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateInitValue(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueType, KEYM_CODE) KeyM_GetCertificateInitValue(KeyM_CertificateInitValueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateInitValueType) (KeyM_GetCertificateInitValueOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateInitValueInfo(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitCalloutIdxOfCertificateInitValueInfoType, KEYM_CODE) KeyM_GetCertificateInitCalloutIdxOfCertificateInitValueInfo(KeyM_CertificateInitValueInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateInitCalloutIdxOfCertificateInitValueInfoType) (KeyM_GetCertificateInitValueInfoOfPCConfig()[(Index)].CertificateInitCalloutIdxOfCertificateInitValueInfo);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateInitValueInfo(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueEndIdxOfCertificateInitValueInfoType, KEYM_CODE) KeyM_GetCertificateInitValueEndIdxOfCertificateInitValueInfo(KeyM_CertificateInitValueInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateInitValueEndIdxOfCertificateInitValueInfoType) (KeyM_GetCertificateInitValueInfoOfPCConfig()[(Index)].CertificateInitValueEndIdxOfCertificateInitValueInfo);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateInitValueInfo(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueStartIdxOfCertificateInitValueInfoType, KEYM_CODE) KeyM_GetCertificateInitValueStartIdxOfCertificateInitValueInfo(KeyM_CertificateInitValueInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateInitValueStartIdxOfCertificateInitValueInfoType) (KeyM_GetCertificateInitValueInfoOfPCConfig()[(Index)].CertificateInitValueStartIdxOfCertificateInitValueInfo);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateName(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameType, KEYM_CODE) KeyM_GetCertificateName(KeyM_CertificateNameIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateNameType) (KeyM_GetCertificateNameOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateSlot(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_IdOfCertificateSlotType, KEYM_CODE) KeyM_GetIdOfCertificateSlot(KeyM_CertificateSlotIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_IdOfCertificateSlotType) (KeyM_GetCertificateSlotOfPCConfig()[(Index)].IdOfCertificateSlot);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateSlot(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_MaxLengthOfCertificateSlotType, KEYM_CODE) KeyM_GetMaxLengthOfCertificateSlot(KeyM_CertificateSlotIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_MaxLengthOfCertificateSlotType) (KeyM_GetCertificateSlotOfPCConfig()[(Index)].MaxLengthOfCertificateSlot);
}
/*! \spec requires Index < KeyM_GetSizeOfCommonCertData(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ConstCertDataType, KEYM_CODE) KeyM_GetCommonCertData(KeyM_CommonCertDataIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_GetCommonCertDataOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfElementOid(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidType, KEYM_CODE) KeyM_GetElementOid(KeyM_ElementOidIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ElementOidType) (KeyM_GetElementOidOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfElementStorageRef(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_Ans1_Element_Ref_Type, KEYM_CODE) KeyM_GetElementStorageRef(KeyM_ElementStorageRefIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_GetElementStorageRefOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfGeneral(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_KeyMCsmRemoteInfoJobRefAsyncOfGeneralType, KEYM_CODE) KeyM_IsKeyMCsmRemoteInfoJobRefAsyncOfGeneral(KeyM_GeneralIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_KeyMCsmRemoteInfoJobRefAsyncOfGeneralType) ((KeyM_GetGeneralOfPCConfig()[(Index)].KeyMCsmRemoteInfoJobRefAsyncOfGeneral) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfGroupInd(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateIdxOfGroupIndType, KEYM_CODE) KeyM_GetCertificateIdxOfGroupInd(KeyM_GroupIndIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateIdxOfGroupIndType) (KeyM_GetGroupIndOfPCConfig()[(Index)].CertificateIdxOfGroupInd);
}
/*! \spec requires Index < KeyM_GetSizeOfNvBlock_State(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(tKeyMCertNvBlockStateType, KEYM_CODE) KeyM_GetNvBlock_State(KeyM_NvBlock_StateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (tKeyMCertNvBlockStateType) (KeyM_GetNvBlock_StateOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfNvmBlock(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertNvBlockProcessingOfNvmBlockType, KEYM_CODE) KeyM_GetCertNvBlockProcessingOfNvmBlock(KeyM_NvmBlockIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertNvBlockProcessingOfNvmBlockType) (KeyM_GetNvmBlockOfPCConfig()[(Index)].CertNvBlockProcessingOfNvmBlock);
}
/*! \spec requires Index < KeyM_GetSizeOfNvmBlock(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_DescriptorRefOfNvmBlockType, KEYM_CODE) KeyM_GetDescriptorRefOfNvmBlock(KeyM_NvmBlockIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_DescriptorRefOfNvmBlockType) (KeyM_GetNvmBlockOfPCConfig()[(Index)].DescriptorRefOfNvmBlock);
}
/*! \spec requires Index < KeyM_GetSizeOfNvmBlock(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_LengthOfNvmBlockType, KEYM_CODE) KeyM_GetLengthOfNvmBlock(KeyM_NvmBlockIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_LengthOfNvmBlockType) (KeyM_GetNvmBlockOfPCConfig()[(Index)].LengthOfNvmBlock);
}
/*! \spec requires Index < KeyM_GetSizeOfSlotOwner(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateIdType, KEYM_CODE) KeyM_GetSlotOwner(KeyM_SlotOwnerIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateIdType) (KeyM_GetSlotOwnerOfPCConfig()[(Index)]);
}
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCGetBitDataInlineFunctions  KeyM Get Bit Data Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to read bitcoded data elements.
  \{
*/ 
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCertAllowFlexibleElementOrderOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_CERTALLOWFLEXIBLEELEMENTORDEROFCERTIFICATE_MASK == (KeyM_GetMaskedBitsOfCertificate(Index) & KEYM_CERTALLOWFLEXIBLEELEMENTORDEROFCERTIFICATE_MASK));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCertAllowUnconfiguredElementsOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_CERTALLOWUNCONFIGUREDELEMENTSOFCERTIFICATE_MASK == (KeyM_GetMaskedBitsOfCertificate(Index) & KEYM_CERTALLOWUNCONFIGUREDELEMENTSOFCERTIFICATE_MASK));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCertCsmSignatureVerifyKeyRefValidOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_CERTCSMSIGNATUREVERIFYKEYREFVALIDOFCERTIFICATE_MASK == (KeyM_GetMaskedBitsOfCertificate(Index) & KEYM_CERTCSMSIGNATUREVERIFYKEYREFVALIDOFCERTIFICATE_MASK));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCertPersistInvalidCertOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_CERTPERSISTINVALIDCERTOFCERTIFICATE_MASK == (KeyM_GetMaskedBitsOfCertificate(Index) & KEYM_CERTPERSISTINVALIDCERTOFCERTIFICATE_MASK));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsKeyMCertCsmHashJobRefAsyncOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_KEYMCERTCSMHASHJOBREFASYNCOFCERTIFICATE_MASK == (KeyM_GetMaskedBitsOfCertificate(Index) & KEYM_KEYMCERTCSMHASHJOBREFASYNCOFCERTIFICATE_MASK));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsKeyMCertCsmSignatureGenerateJobRefAsyncOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_KEYMCERTCSMSIGNATUREGENERATEJOBREFASYNCOFCERTIFICATE_MASK == (KeyM_GetMaskedBitsOfCertificate(Index) & KEYM_KEYMCERTCSMSIGNATUREGENERATEJOBREFASYNCOFCERTIFICATE_MASK));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsKeyMCertCsmSignatureVerifyJobRefAsyncOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_KEYMCERTCSMSIGNATUREVERIFYJOBREFASYNCOFCERTIFICATE_MASK == (KeyM_GetMaskedBitsOfCertificate(Index) & KEYM_KEYMCERTCSMSIGNATUREVERIFYJOBREFASYNCOFCERTIFICATE_MASK));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsHasIterationOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_HASITERATIONOFCERTIFICATEELEMENT_MASK == (KeyM_GetMaskedBitsOfCertificateElement(Index) & KEYM_HASITERATIONOFCERTIFICATEELEMENT_MASK));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsOptionalOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_OPTIONALOFCERTIFICATEELEMENT_MASK == (KeyM_GetMaskedBitsOfCertificateElement(Index) & KEYM_OPTIONALOFCERTIFICATEELEMENT_MASK));
}
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCGetDeduplicatedInlineFunctions  KeyM Get Deduplicated Inline Functions (PRE_COMPILE)
  \brief  These inline functions  can be used to read deduplicated data elements.
  \{
*/ 
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageLengthOfCertificateType, KEYM_CODE) KeyM_GetCertStorageLengthOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageLengthOfCertificateType) ((KeyM_CertStorageLengthOfCertificateType)((KeyM_GetCertStorageEndIdxOfCertificate(Index) - KeyM_GetCertStorageStartIdxOfCertificate(Index))));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageStatusEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageStatusEndIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageStatusEndIdxOfCertificateType) ((KeyM_CertStorageStatusEndIdxOfCertificateType)((KeyM_GetCertStorageStatusStartIdxOfCertificate(Index) + 2u)));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageStatusLengthOfCertificateType, KEYM_CODE) KeyM_GetCertStorageStatusLengthOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageStatusLengthOfCertificateType) ((KeyM_CertStorageStatusLengthOfCertificateType)((KeyM_GetCertificateGetCurrentTimeCalloutIdxOfCertificate(Index) + 2u)));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageUsedOfCertificateType, KEYM_CODE) KeyM_IsCertStorageUsedOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageUsedOfCertificateType) (((boolean)(KeyM_GetCertStorageLengthOfCertificate(Index) != 0u)) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageWrittenLengthLengthOfCertificateType, KEYM_CODE) KeyM_GetCertStorageWrittenLengthLengthOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageWrittenLengthLengthOfCertificateType) ((KeyM_CertStorageWrittenLengthLengthOfCertificateType)((KeyM_GetCertStorageWrittenLengthEndIdxOfCertificate(Index) - KeyM_GetCertStorageWrittenLengthStartIdxOfCertificate(Index))));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageWrittenLengthUsedOfCertificateType, KEYM_CODE) KeyM_IsCertStorageWrittenLengthUsedOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageWrittenLengthUsedOfCertificateType) (((boolean)(KeyM_GetCertStorageWrittenLengthLengthOfCertificate(Index) != 0u)) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementLengthOfCertificateType, KEYM_CODE) KeyM_GetCertificateElementLengthOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateElementLengthOfCertificateType) ((KeyM_CertificateElementLengthOfCertificateType)((KeyM_GetCertificateElementEndIdxOfCertificate(Index) - KeyM_GetCertificateElementStartIdxOfCertificate(Index))));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementUsedOfCertificateType, KEYM_CODE) KeyM_IsCertificateElementUsedOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateElementUsedOfCertificateType) (((boolean)(KeyM_GetCertificateElementLengthOfCertificate(Index) != 0u)) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGetCurrentTimeCalloutUsedOfCertificateType, KEYM_CODE) KeyM_IsCertificateGetCurrentTimeCalloutUsedOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateGetCurrentTimeCalloutUsedOfCertificateType) (((boolean)(KeyM_GetCertificateGetCurrentTimeCalloutIdxOfCertificate(Index) != KEYM_NO_CERTIFICATEGETCURRENTTIMECALLOUTIDXOFCERTIFICATE)) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGroupUsedOfCertificateType, KEYM_CODE) KeyM_IsCertificateGroupUsedOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateGroupUsedOfCertificateType) (((boolean)(KeyM_GetCertificateGroupIdxOfCertificate(Index) != KEYM_NO_CERTIFICATEGROUPIDXOFCERTIFICATE)) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueInfoUsedOfCertificateType, KEYM_CODE) KeyM_IsCertificateInitValueInfoUsedOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateInitValueInfoUsedOfCertificateType) (((boolean)(KeyM_GetCertificateInitValueInfoIdxOfCertificate(Index) != KEYM_NO_CERTIFICATEINITVALUEINFOIDXOFCERTIFICATE)) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameLengthOfCertificateType, KEYM_CODE) KeyM_GetCertificateNameLengthOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateNameLengthOfCertificateType) ((KeyM_CertificateNameLengthOfCertificateType)((KeyM_GetCertificateNameEndIdxOfCertificate(Index) - KeyM_GetCertificateNameStartIdxOfCertificate(Index))));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateSlotUsedOfCertificateType, KEYM_CODE) KeyM_IsCertificateSlotUsedOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateSlotUsedOfCertificateType) (((boolean)(KeyM_GetSlotRefIdxOfCertificate(Index) != KEYM_NO_SLOTREFIDXOFCERTIFICATE)) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_NvmBlockUsedOfCertificateType, KEYM_CODE) KeyM_IsNvmBlockUsedOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_NvmBlockUsedOfCertificateType) (((boolean)(KeyM_GetNvmBlockIdxOfCertificate(Index) != KEYM_NO_NVMBLOCKIDXOFCERTIFICATE)) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_RemoteCertificateIdOfCertificateType, KEYM_CODE) KeyM_GetRemoteCertificateIdOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_RemoteCertificateIdOfCertificateType) KeyM_GetCertificateGetCurrentTimeCalloutIdxOfCertificate(Index);
}
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateChainMaxDepthOfGeneralType, KEYM_CODE) KeyM_GetCertificateChainMaxDepthOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CertificateChainMaxDepthOfGeneralType) KeyM_GetCertificateChainMaxDepthOfGeneralOfPCConfig();
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertElementPathLengthOfCertificateElementType, KEYM_CODE) KeyM_GetCertElementPathLengthOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertElementPathLengthOfCertificateElementType) ((KeyM_CertElementPathLengthOfCertificateElementType)((KeyM_GetCertElementPathEndIdxOfCertificateElement(Index) - KeyM_GetCertElementPathStartIdxOfCertificateElement(Index))));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertElementPathUsedOfCertificateElementType, KEYM_CODE) KeyM_IsCertElementPathUsedOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertElementPathUsedOfCertificateElementType) (((boolean)(KeyM_GetCertElementPathLengthOfCertificateElement(Index) != 0u)) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidLengthOfCertificateElementType, KEYM_CODE) KeyM_GetElementOidLengthOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ElementOidLengthOfCertificateElementType) ((KeyM_ElementOidLengthOfCertificateElementType)((KeyM_GetElementOidEndIdxOfCertificateElement(Index) - KeyM_GetElementOidStartIdxOfCertificateElement(Index))));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidUsedOfCertificateElementType, KEYM_CODE) KeyM_IsElementOidUsedOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ElementOidUsedOfCertificateElementType) (((boolean)(KeyM_GetElementOidLengthOfCertificateElement(Index) != 0u)) != FALSE);
}
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateExtensionValidationEnabledOfGeneralType, KEYM_CODE) KeyM_IsCertificateExtensionValidationEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CertificateExtensionValidationEnabledOfGeneralType) KeyM_IsCertificateExtensionValidationEnabledOfGeneralOfPCConfig();
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroup(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGroupVerifyCallbackNotificationUsedOfCertificateGroupType, KEYM_CODE) KeyM_IsCertificateGroupVerifyCallbackNotificationUsedOfCertificateGroup(KeyM_CertificateGroupIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateGroupVerifyCallbackNotificationUsedOfCertificateGroupType) (((boolean)(KeyM_GetCertificateGroupVerifyCallbackNotificationIdxOfCertificateGroup(Index) != KEYM_NO_CERTIFICATEGROUPVERIFYCALLBACKNOTIFICATIONIDXOFCERTIFICATEGROUP)) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroup(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidPrimaryLengthOfCertificateGroupType, KEYM_CODE) KeyM_GetElementOidPrimaryLengthOfCertificateGroup(KeyM_CertificateGroupIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ElementOidPrimaryLengthOfCertificateGroupType) ((KeyM_ElementOidPrimaryLengthOfCertificateGroupType)((KeyM_GetElementOidPrimaryEndIdxOfCertificateGroup(Index) - KeyM_GetElementOidPrimaryStartIdxOfCertificateGroup(Index))));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroup(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidPrimaryUsedOfCertificateGroupType, KEYM_CODE) KeyM_IsElementOidPrimaryUsedOfCertificateGroup(KeyM_CertificateGroupIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ElementOidPrimaryUsedOfCertificateGroupType) (((boolean)(KeyM_GetElementOidPrimaryLengthOfCertificateGroup(Index) != 0u)) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroup(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidSecondaryLengthOfCertificateGroupType, KEYM_CODE) KeyM_GetElementOidSecondaryLengthOfCertificateGroup(KeyM_CertificateGroupIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ElementOidSecondaryLengthOfCertificateGroupType) ((KeyM_ElementOidSecondaryLengthOfCertificateGroupType)((KeyM_GetElementOidSecondaryEndIdxOfCertificateGroup(Index) - KeyM_GetElementOidSecondaryStartIdxOfCertificateGroup(Index))));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroup(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidSecondaryUsedOfCertificateGroupType, KEYM_CODE) KeyM_IsElementOidSecondaryUsedOfCertificateGroup(KeyM_CertificateGroupIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ElementOidSecondaryUsedOfCertificateGroupType) (((boolean)(KeyM_GetElementOidSecondaryLengthOfCertificateGroup(Index) != 0u)) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroup(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_GroupIndCertLengthOfCertificateGroupType, KEYM_CODE) KeyM_GetGroupIndCertLengthOfCertificateGroup(KeyM_CertificateGroupIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_GroupIndCertLengthOfCertificateGroupType) ((KeyM_GroupIndCertLengthOfCertificateGroupType)((KeyM_GetGroupIndCertEndIdxOfCertificateGroup(Index) - KeyM_GetGroupIndCertStartIdxOfCertificateGroup(Index))));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroup(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_GroupIndIssuerLengthOfCertificateGroupType, KEYM_CODE) KeyM_GetGroupIndIssuerLengthOfCertificateGroup(KeyM_CertificateGroupIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_GroupIndIssuerLengthOfCertificateGroupType) ((KeyM_GroupIndIssuerLengthOfCertificateGroupType)((KeyM_GetGroupIndIssuerEndIdxOfCertificateGroup(Index) - KeyM_GetGroupIndIssuerStartIdxOfCertificateGroup(Index))));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGroupExt(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGroupStartIdxOfCertificateGroupExtType, KEYM_CODE) KeyM_GetCertificateGroupStartIdxOfCertificateGroupExt(KeyM_CertificateGroupExtIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateGroupStartIdxOfCertificateGroupExtType) ((KeyM_CertificateGroupStartIdxOfCertificateGroupExtType)((Index)));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateInitValueInfo(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitCalloutUsedOfCertificateInitValueInfoType, KEYM_CODE) KeyM_IsCertificateInitCalloutUsedOfCertificateInitValueInfo(KeyM_CertificateInitValueInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateInitCalloutUsedOfCertificateInitValueInfoType) (((boolean)(KeyM_GetCertificateInitCalloutIdxOfCertificateInitValueInfo(Index) != KEYM_NO_CERTIFICATEINITCALLOUTIDXOFCERTIFICATEINITVALUEINFO)) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateInitValueInfo(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueLengthOfCertificateInitValueInfoType, KEYM_CODE) KeyM_GetCertificateInitValueLengthOfCertificateInitValueInfo(KeyM_CertificateInitValueInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateInitValueLengthOfCertificateInitValueInfoType) ((KeyM_CertificateInitValueLengthOfCertificateInitValueInfoType)((KeyM_GetCertificateInitValueEndIdxOfCertificateInitValueInfo(Index) - KeyM_GetCertificateInitValueStartIdxOfCertificateInitValueInfo(Index))));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateInitValueInfo(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueUsedOfCertificateInitValueInfoType, KEYM_CODE) KeyM_IsCertificateInitValueUsedOfCertificateInitValueInfo(KeyM_CertificateInitValueInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateInitValueUsedOfCertificateInitValueInfoType) (((boolean)(KeyM_GetCertificateInitValueLengthOfCertificateInitValueInfo(Index) != 0u)) != FALSE);
}
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateManagerEnabledOfGeneralType, KEYM_CODE) KeyM_IsCertificateManagerEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CertificateManagerEnabledOfGeneralType) KeyM_IsCertificateManagerEnabledOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateSigningRequestEnabledOfGeneralType, KEYM_CODE) KeyM_IsCertificateSigningRequestEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CertificateSigningRequestEnabledOfGeneralType) KeyM_IsCertificateSigningRequestEnabledOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_CryptoKeyPrepareFunctionEnabledOfGeneralType, KEYM_CODE) KeyM_IsCryptoKeyPrepareFunctionEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CryptoKeyPrepareFunctionEnabledOfGeneralType) KeyM_IsCryptoKeyPrepareFunctionEnabledOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_CryptoKeyStartFinalizeFunctionEnabledOfGeneralType, KEYM_CODE) KeyM_IsCryptoKeyStartFinalizeFunctionEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CryptoKeyStartFinalizeFunctionEnabledOfGeneralType) KeyM_IsCryptoKeyStartFinalizeFunctionEnabledOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_CryptoKeyVerifyAsyncModeOfGeneralType, KEYM_CODE) KeyM_IsCryptoKeyVerifyAsyncModeOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CryptoKeyVerifyAsyncModeOfGeneralType) KeyM_IsCryptoKeyVerifyAsyncModeOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_CryptoKeyVerifyFunctionEnabledOfGeneralType, KEYM_CODE) KeyM_IsCryptoKeyVerifyFunctionEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CryptoKeyVerifyFunctionEnabledOfGeneralType) KeyM_IsCryptoKeyVerifyFunctionEnabledOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_KeyCertNameMaxLengthOfGeneralType, KEYM_CODE) KeyM_GetKeyCertNameMaxLengthOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_KeyCertNameMaxLengthOfGeneralType) KeyM_GetKeyCertNameMaxLengthOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_MainFunctionPeriodOfGeneralType, KEYM_CODE) KeyM_GetMainFunctionPeriodOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_MainFunctionPeriodOfGeneralType) KeyM_GetMainFunctionPeriodOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_ParseMaxNestingLevelOfGeneralType, KEYM_CODE) KeyM_GetParseMaxNestingLevelOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_ParseMaxNestingLevelOfGeneralType) KeyM_GetParseMaxNestingLevelOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_ServiceCertificateFunctionEnabledOfGeneralType, KEYM_CODE) KeyM_IsServiceCertificateFunctionEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_ServiceCertificateFunctionEnabledOfGeneralType) KeyM_IsServiceCertificateFunctionEnabledOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertElementPathType, KEYM_CODE) KeyM_GetSizeOfCertElementPath(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertElementPathType) KeyM_GetSizeOfCertElementPathOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertStorageType, KEYM_CODE) KeyM_GetSizeOfCertStorage(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertStorageType) KeyM_GetSizeOfCertStorageOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_CertInfoType, KEYM_CODE) KeyM_GetSizeOfCert_CertInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCert_CertInfoType) KeyM_GetSizeOfCert_CertInfoOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_LeafCertsToVerifyType, KEYM_CODE) KeyM_GetSizeOfCert_LeafCertsToVerify(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCert_LeafCertsToVerifyType) KeyM_GetSizeOfCert_LeafCertsToVerifyOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_LockType, KEYM_CODE) KeyM_GetSizeOfCert_Lock(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCert_LockType) KeyM_GetSizeOfCert_LockOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_StorageTypeType, KEYM_CODE) KeyM_GetSizeOfCert_StorageType(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCert_StorageTypeType) KeyM_GetSizeOfCert_StorageTypeOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_VerifyChainType, KEYM_CODE) KeyM_GetSizeOfCert_VerifyChain(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCert_VerifyChainType) KeyM_GetSizeOfCert_VerifyChainOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateType, KEYM_CODE) KeyM_GetSizeOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateType) KeyM_GetSizeOfCertificateOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateElementType, KEYM_CODE) KeyM_GetSizeOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateElementType) KeyM_GetSizeOfCertificateElementOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateGetCurrentTimeCalloutType, KEYM_CODE) KeyM_GetSizeOfCertificateGetCurrentTimeCallout(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateGetCurrentTimeCalloutType) KeyM_GetSizeOfCertificateGetCurrentTimeCalloutOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateGroupType, KEYM_CODE) KeyM_GetSizeOfCertificateGroup(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateGroupType) KeyM_GetSizeOfCertificateGroupOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateGroupExtType, KEYM_CODE) KeyM_GetSizeOfCertificateGroupExt(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateGroupExtType) KeyM_GetSizeOfCertificateGroupExtOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateGroupVerifyCallbackNotificationType, KEYM_CODE) KeyM_GetSizeOfCertificateGroupVerifyCallbackNotification(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateGroupVerifyCallbackNotificationType) KeyM_GetSizeOfCertificateGroupVerifyCallbackNotificationOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateInitCalloutType, KEYM_CODE) KeyM_GetSizeOfCertificateInitCallout(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateInitCalloutType) KeyM_GetSizeOfCertificateInitCalloutOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateInitValueType, KEYM_CODE) KeyM_GetSizeOfCertificateInitValue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateInitValueType) KeyM_GetSizeOfCertificateInitValueOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateInitValueInfoType, KEYM_CODE) KeyM_GetSizeOfCertificateInitValueInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateInitValueInfoType) KeyM_GetSizeOfCertificateInitValueInfoOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateNameType, KEYM_CODE) KeyM_GetSizeOfCertificateName(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateNameType) KeyM_GetSizeOfCertificateNameOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateSlotType, KEYM_CODE) KeyM_GetSizeOfCertificateSlot(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateSlotType) KeyM_GetSizeOfCertificateSlotOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCommonCertDataType, KEYM_CODE) KeyM_GetSizeOfCommonCertData(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCommonCertDataType) KeyM_GetSizeOfCommonCertDataOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfElementOidType, KEYM_CODE) KeyM_GetSizeOfElementOid(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfElementOidType) KeyM_GetSizeOfElementOidOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfElementStorageRefType, KEYM_CODE) KeyM_GetSizeOfElementStorageRef(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfElementStorageRefType) KeyM_GetSizeOfElementStorageRefOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfGeneralType, KEYM_CODE) KeyM_GetSizeOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfGeneralType) KeyM_GetSizeOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfGroupIndType, KEYM_CODE) KeyM_GetSizeOfGroupInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfGroupIndType) KeyM_GetSizeOfGroupIndOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfNvBlock_StateType, KEYM_CODE) KeyM_GetSizeOfNvBlock_State(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfNvBlock_StateType) KeyM_GetSizeOfNvBlock_StateOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfNvmBlockType, KEYM_CODE) KeyM_GetSizeOfNvmBlock(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfNvmBlockType) KeyM_GetSizeOfNvmBlockOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfSlotOwnerType, KEYM_CODE) KeyM_GetSizeOfSlotOwner(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfSlotOwnerType) KeyM_GetSizeOfSlotOwnerOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_VersionInfoApiOfGeneralType, KEYM_CODE) KeyM_IsVersionInfoApiOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_VersionInfoApiOfGeneralType) KeyM_IsVersionInfoApiOfGeneralOfPCConfig();
}
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCSetDataInlineFunctions  KeyM Set Data Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to write data.
  \{
*/ 
/*! \spec requires Index < KeyM_GetSizeOfCertStorage(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCertStorage(KeyM_CertStorageIterType Index, KeyM_CertStorageType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCertStorageOfPCConfig()[(Index)] = (Value);
}
/*! \spec requires Index < KeyM_GetSizeOfCert_CertInfo(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCert_CertInfo(KeyM_Cert_CertInfoIterType Index, tKeyMCertInfoType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_CertInfoOfPCConfig()[(Index)] = (Value);
}
/*! \spec requires Index < KeyM_GetSizeOfCert_LeafCertsToVerify(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index, KeyM_CertificateIdType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_LeafCertsToVerifyOfPCConfig()[(Index)] = (Value);
}
/*! \spec requires Index < KeyM_GetSizeOfCert_Lock(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCert_Lock(KeyM_Cert_LockIterType Index, KeyM_Cert_LockType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_LockOfPCConfig()[(Index)] = (Value);
}
/*! \spec requires Index < KeyM_GetSizeOfCert_StorageType(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCert_StorageType(KeyM_Cert_StorageTypeIterType Index, tKeyMCertStorageType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_StorageTypeOfPCConfig()[(Index)] = (Value);
}
/*! \spec requires Index < KeyM_GetSizeOfCert_VerifyChain(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index, KeyM_CertificateIdType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_VerifyChainOfPCConfig()[(Index)] = (Value);
}
/*! \spec requires Index < KeyM_GetSizeOfCommonCertData(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCommonCertData(KeyM_CommonCertDataIterType Index, KeyM_ConstCertDataType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCommonCertDataOfPCConfig()[(Index)] = (Value);
}
/*! \spec requires Index < KeyM_GetSizeOfElementStorageRef(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetElementStorageRef(KeyM_ElementStorageRefIterType Index, KeyM_Ans1_Element_Ref_Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetElementStorageRefOfPCConfig()[(Index)] = (Value);
}
/*! \spec requires Index < KeyM_GetSizeOfNvBlock_State(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetNvBlock_State(KeyM_NvBlock_StateIterType Index, tKeyMCertNvBlockStateType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetNvBlock_StateOfPCConfig()[(Index)] = (Value);
}
/*! \spec requires Index < KeyM_GetSizeOfSlotOwner(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetSlotOwner(KeyM_SlotOwnerIterType Index, KeyM_CertificateIdType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetSlotOwnerOfPCConfig()[(Index)] = (Value);
}
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCGetAddressOfDataInlineFunctions  KeyM Get Address Of Data Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to get the data by the address operator.
  \{
*/ 
/*! \spec requires Index < KeyM_GetSizeOfCertElementPath(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertElementPathPtrType, KEYM_CODE) KeyM_GetAddrCertElementPath(KeyM_CertElementPathIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CertElementPathPtrType) (&(KeyM_GetCertElementPathOfPCConfig()[(Index)]));
}
/*! \spec requires Index < KeyM_GetSizeOfCertStorage(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStoragePtrType, KEYM_CODE) KeyM_GetAddrCertStorage(KeyM_CertStorageIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CertStoragePtrType) (&(KeyM_GetCertStorageOfPCConfig()[(Index)]));
}
/*! \spec requires Index < KeyM_GetSizeOfCert_CertInfo(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_Cert_CertInfoPtrType, KEYM_CODE) KeyM_GetAddrCert_CertInfo(KeyM_Cert_CertInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (&(KeyM_GetCert_CertInfoOfPCConfig()[(Index)]));
}
/*! \spec requires Index < KeyM_GetSizeOfCert_Lock(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_Cert_LockPtrType, KEYM_CODE) KeyM_GetAddrCert_Lock(KeyM_Cert_LockIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_Cert_LockPtrType) (&(KeyM_GetCert_LockOfPCConfig()[(Index)]));
}
/*! \spec requires Index < KeyM_GetSizeOfCert_StorageType(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_Cert_StorageTypePtrType, KEYM_CODE) KeyM_GetAddrCert_StorageType(KeyM_Cert_StorageTypeIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_Cert_StorageTypePtrType) (&(KeyM_GetCert_StorageTypeOfPCConfig()[(Index)]));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateInitValue(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValuePtrType, KEYM_CODE) KeyM_GetAddrCertificateInitValue(KeyM_CertificateInitValueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CertificateInitValuePtrType) (&(KeyM_GetCertificateInitValueOfPCConfig()[(Index)]));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateName(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNamePtrType, KEYM_CODE) KeyM_GetAddrCertificateName(KeyM_CertificateNameIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CertificateNamePtrType) (&(KeyM_GetCertificateNameOfPCConfig()[(Index)]));
}
/*! \spec requires Index < KeyM_GetSizeOfCommonCertData(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CommonCertDataPtrType, KEYM_CODE) KeyM_GetAddrCommonCertData(KeyM_CommonCertDataIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (&(KeyM_GetCommonCertDataOfPCConfig()[(Index)]));
}
/*! \spec requires Index < KeyM_GetSizeOfElementOid(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidPtrType, KEYM_CODE) KeyM_GetAddrElementOid(KeyM_ElementOidIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_ElementOidPtrType) (&(KeyM_GetElementOidOfPCConfig()[(Index)]));
}
/*! \spec requires Index < KeyM_GetSizeOfElementStorageRef(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementStorageRefPtrType, KEYM_CODE) KeyM_GetAddrElementStorageRef(KeyM_ElementStorageRefIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (&(KeyM_GetElementStorageRefOfPCConfig()[(Index)]));
}
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCHasInlineFunctions  KeyM Has Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertElementPath(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorage(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_CertInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_LeafCertsToVerify(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_Lock(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_StorageType(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_VerifyChain(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertAlgorithmFamilyOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertAllowFlexibleElementOrderOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertAllowUnconfiguredElementsOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertCsmSignatureVerifyJobRefOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertCsmSignatureVerifyKeyRefOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertCsmSignatureVerifyKeyRefValidOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertFormatTypeOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertPersistInvalidCertOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStartUpHandlingOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageEndIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageLengthOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageStartIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageStatusEndIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageStatusLengthOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageStatusStartIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageUsedOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageWrittenLengthEndIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageWrittenLengthLengthOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageWrittenLengthStartIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageWrittenLengthUsedOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertUpperHierarchicalCertRefIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertUpperHierarchicalTypeOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementEndIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementLengthOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementStartIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementUsedOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCalloutIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCalloutUsedOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupUsedOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueInfoIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueInfoUsedOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateNameEndIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateNameLengthOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateNameStartIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateSlotUsedOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyMCertCsmHashJobRefAsyncOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyMCertCsmSignatureGenerateJobRefAsyncOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyMCertCsmSignatureVerifyJobRefAsyncOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMaskedBitsOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMaxLengthOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasNvmBlockIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasNvmBlockUsedOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasRemoteCertificateIdOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSlotRefIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasStorageOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateChainMaxDepthOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertElementPathEndIdxOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertElementPathLengthOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertElementPathStartIdxOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertElementPathUsedOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidEndIdxOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidLengthOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidStartIdxOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidUsedOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasHasIterationOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasIdOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMaskedBitsOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMaxLengthOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasObjectTypeOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasOfStructureOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasOptionalOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateExtensionValidationEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCallout(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroup(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupVerifyCallbackNotificationIdxOfCertificateGroup(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupVerifyCallbackNotificationUsedOfCertificateGroup(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateRemoteGroupIdOfCertificateGroup(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidPrimaryEndIdxOfCertificateGroup(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidPrimaryLengthOfCertificateGroup(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidPrimaryStartIdxOfCertificateGroup(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidPrimaryUsedOfCertificateGroup(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidSecondaryEndIdxOfCertificateGroup(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidSecondaryLengthOfCertificateGroup(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidSecondaryStartIdxOfCertificateGroup(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidSecondaryUsedOfCertificateGroup(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGroupIndCertEndIdxOfCertificateGroup(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGroupIndCertLengthOfCertificateGroup(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGroupIndCertStartIdxOfCertificateGroup(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGroupIndIssuerEndIdxOfCertificateGroup(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGroupIndIssuerLengthOfCertificateGroup(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGroupIndIssuerStartIdxOfCertificateGroup(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupExt(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupEndIdxOfCertificateGroupExt(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupLengthOfCertificateGroupExt(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupStartIdxOfCertificateGroupExt(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupVerifyCallbackNotification(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitCallout(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitCalloutIdxOfCertificateInitValueInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitCalloutUsedOfCertificateInitValueInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueEndIdxOfCertificateInitValueInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueLengthOfCertificateInitValueInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueStartIdxOfCertificateInitValueInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueUsedOfCertificateInitValueInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateManagerEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateName(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateSigningRequestEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateSlot(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasIdOfCertificateSlot(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMaxLengthOfCertificateSlot(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCommonCertData(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyPrepareFunctionEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyStartFinalizeFunctionEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyVerifyAsyncModeOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyVerifyFunctionEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOid(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementStorageRef(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyMCsmRemoteInfoJobRefAsyncOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGroupInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateIdxOfGroupInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyCertNameMaxLengthOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMainFunctionPeriodOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasNvBlock_State(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasNvmBlock(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertNvBlockProcessingOfNvmBlock(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasDescriptorRefOfNvmBlock(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasLengthOfNvmBlock(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasParseMaxNestingLevelOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasServiceCertificateFunctionEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertElementPath(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertStorage(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_CertInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_LeafCertsToVerify(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_Lock(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_StorageType(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_VerifyChain(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGetCurrentTimeCallout(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGroup(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGroupExt(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGroupVerifyCallbackNotification(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateInitCallout(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateInitValue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateInitValueInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateName(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateSlot(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCommonCertData(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfElementOid(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfElementStorageRef(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfGroupInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfNvBlock_State(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfNvmBlock(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfSlotOwner(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSlotOwner(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasVersionInfoApiOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertElementPathOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_CertInfoOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_LeafCertsToVerifyOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_LockOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_StorageTypeOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_VerifyChainOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateChainMaxDepthOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateExtensionValidationEnabledOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCalloutOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupExtOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGroupVerifyCallbackNotificationOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitCalloutOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueInfoOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateManagerEnabledOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateNameOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateSigningRequestEnabledOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateSlotOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCommonCertDataOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyPrepareFunctionEnabledOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyStartFinalizeFunctionEnabledOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyVerifyAsyncModeOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyVerifyFunctionEnabledOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementStorageRefOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGroupIndOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyCertNameMaxLengthOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMainFunctionPeriodOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasNvBlock_StateOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasNvmBlockOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasParseMaxNestingLevelOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasServiceCertificateFunctionEnabledOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertElementPathOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertStorageOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_CertInfoOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_LeafCertsToVerifyOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_LockOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_StorageTypeOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_VerifyChainOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateElementOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGetCurrentTimeCalloutOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGroupExtOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGroupOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGroupVerifyCallbackNotificationOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateInitCalloutOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateInitValueInfoOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateInitValueOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateNameOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateSlotOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCommonCertDataOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfElementOidOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfElementStorageRefOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfGroupIndOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfNvBlock_StateOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfNvmBlockOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfSlotOwnerOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSlotOwnerOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasVersionInfoApiOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCIncrementInlineFunctions  KeyM Increment Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to increment VAR data with numerical nature.
  \{
*/ 
/*! \spec requires Index < KeyM_GetSizeOfCertStorage(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_IncCertStorage(KeyM_CertStorageIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCertStorageOfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
/*! \spec requires Index < KeyM_GetSizeOfCert_LeafCertsToVerify(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_IncCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_LeafCertsToVerifyOfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
/*! \spec requires Index < KeyM_GetSizeOfCert_StorageType(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_IncCert_StorageType(KeyM_Cert_StorageTypeIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_StorageTypeOfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
/*! \spec requires Index < KeyM_GetSizeOfCert_VerifyChain(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_IncCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_VerifyChainOfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
/*! \spec requires Index < KeyM_GetSizeOfNvBlock_State(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_IncNvBlock_State(KeyM_NvBlock_StateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetNvBlock_StateOfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
/*! \spec requires Index < KeyM_GetSizeOfSlotOwner(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_IncSlotOwner(KeyM_SlotOwnerIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetSlotOwnerOfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCDecrementInlineFunctions  KeyM Decrement Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to decrement VAR data with numerical nature.
  \{
*/ 
/*! \spec requires Index < KeyM_GetSizeOfCertStorage(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_DecCertStorage(KeyM_CertStorageIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCertStorageOfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
/*! \spec requires Index < KeyM_GetSizeOfCert_LeafCertsToVerify(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_DecCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_LeafCertsToVerifyOfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
/*! \spec requires Index < KeyM_GetSizeOfCert_StorageType(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_DecCert_StorageType(KeyM_Cert_StorageTypeIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_StorageTypeOfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
/*! \spec requires Index < KeyM_GetSizeOfCert_VerifyChain(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_DecCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_VerifyChainOfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
/*! \spec requires Index < KeyM_GetSizeOfNvBlock_State(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_DecNvBlock_State(KeyM_NvBlock_StateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetNvBlock_StateOfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
/*! \spec requires Index < KeyM_GetSizeOfSlotOwner(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_DecSlotOwner(KeyM_SlotOwnerIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetSlotOwnerOfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCAddInlineFunctions  KeyM Add Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to add VAR data with numerical nature.
  \{
*/ 
/*! \spec requires Index < KeyM_GetSizeOfCertStorage(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_AddCertStorage(KeyM_CertStorageIterType Index, KeyM_CertStorageType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_SetCertStorage(Index, (KeyM_GetCertStorageOfPCConfig()[(Index)] + Value));
}
/*! \spec requires Index < KeyM_GetSizeOfCert_LeafCertsToVerify(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_AddCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index, KeyM_CertificateIdType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_SetCert_LeafCertsToVerify(Index, (KeyM_GetCert_LeafCertsToVerifyOfPCConfig()[(Index)] + Value));
}
/*! \spec requires Index < KeyM_GetSizeOfCert_StorageType(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_AddCert_StorageType(KeyM_Cert_StorageTypeIterType Index, tKeyMCertStorageType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_SetCert_StorageType(Index, (KeyM_GetCert_StorageTypeOfPCConfig()[(Index)] + Value));
}
/*! \spec requires Index < KeyM_GetSizeOfCert_VerifyChain(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_AddCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index, KeyM_CertificateIdType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_SetCert_VerifyChain(Index, (KeyM_GetCert_VerifyChainOfPCConfig()[(Index)] + Value));
}
/*! \spec requires Index < KeyM_GetSizeOfNvBlock_State(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_AddNvBlock_State(KeyM_NvBlock_StateIterType Index, tKeyMCertNvBlockStateType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_SetNvBlock_State(Index, (KeyM_GetNvBlock_StateOfPCConfig()[(Index)] + Value));
}
/*! \spec requires Index < KeyM_GetSizeOfSlotOwner(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_AddSlotOwner(KeyM_SlotOwnerIterType Index, KeyM_CertificateIdType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_SetSlotOwner(Index, (KeyM_GetSlotOwnerOfPCConfig()[(Index)] + Value));
}
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCSubstractInlineFunctions  KeyM Substract Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to substract VAR data with numerical nature.
  \{
*/ 
/*! \spec requires Index < KeyM_GetSizeOfCertStorage(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SubCertStorage(KeyM_CertStorageIterType Index, KeyM_CertStorageType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_SetCertStorage(Index, (KeyM_GetCertStorageOfPCConfig()[(Index)] - Value));
}
/*! \spec requires Index < KeyM_GetSizeOfCert_LeafCertsToVerify(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SubCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index, KeyM_CertificateIdType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_SetCert_LeafCertsToVerify(Index, (KeyM_GetCert_LeafCertsToVerifyOfPCConfig()[(Index)] - Value));
}
/*! \spec requires Index < KeyM_GetSizeOfCert_StorageType(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SubCert_StorageType(KeyM_Cert_StorageTypeIterType Index, tKeyMCertStorageType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_SetCert_StorageType(Index, (KeyM_GetCert_StorageTypeOfPCConfig()[(Index)] - Value));
}
/*! \spec requires Index < KeyM_GetSizeOfCert_VerifyChain(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SubCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index, KeyM_CertificateIdType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_SetCert_VerifyChain(Index, (KeyM_GetCert_VerifyChainOfPCConfig()[(Index)] - Value));
}
/*! \spec requires Index < KeyM_GetSizeOfNvBlock_State(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SubNvBlock_State(KeyM_NvBlock_StateIterType Index, tKeyMCertNvBlockStateType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_SetNvBlock_State(Index, (KeyM_GetNvBlock_StateOfPCConfig()[(Index)] - Value));
}
/*! \spec requires Index < KeyM_GetSizeOfSlotOwner(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SubSlotOwner(KeyM_SlotOwnerIterType Index, KeyM_CertificateIdType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_SetSlotOwner(Index, (KeyM_GetSlotOwnerOfPCConfig()[(Index)] - Value));
}
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


#endif

/* PRQA L:InlineFunctions_2995_2996 */


#endif /* KEYM_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: KeyM_Cfg.h
 *********************************************************************************************************************/

