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
 *            Module: Crypto_30_LibCv
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Crypto_30_LibCv_Cfg.h
 *   Generation Time: 2025-08-26 17:17:05
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/


#if !defined (CRYPTO_30_LIBCV_CFG_H)
#define CRYPTO_30_LIBCV_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
// #include "Os.h"
#include "NvM.h"
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0759 EOF */ /* MD_CSL_18.4 */
#include "Csm_Types.h"
#include "vSecPrim.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef CRYPTO_30_LIBCV_USE_DUMMY_STATEMENT
#define CRYPTO_30_LIBCV_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYPTO_30_LIBCV_DUMMY_STATEMENT
#define CRYPTO_30_LIBCV_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYPTO_30_LIBCV_DUMMY_STATEMENT_CONST
#define CRYPTO_30_LIBCV_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYPTO_30_LIBCV_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CRYPTO_30_LIBCV_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CRYPTO_30_LIBCV_ATOMIC_VARIABLE_ACCESS
#define CRYPTO_30_LIBCV_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CRYPTO_30_LIBCV_PROCESSOR_TC377T
#define CRYPTO_30_LIBCV_PROCESSOR_TC377T
#endif
#ifndef CRYPTO_30_LIBCV_COMP_DIAB
#define CRYPTO_30_LIBCV_COMP_DIAB
#endif
#ifndef CRYPTO_30_LIBCV_GEN_GENERATOR_MSR
#define CRYPTO_30_LIBCV_GEN_GENERATOR_MSR
#endif
#ifndef CRYPTO_30_LIBCV_CPUTYPE_BITORDER_LSB2MSB
#define CRYPTO_30_LIBCV_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CRYPTO_30_LIBCV_CONFIGURATION_VARIANT_PRECOMPILE
#define CRYPTO_30_LIBCV_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CRYPTO_30_LIBCV_CONFIGURATION_VARIANT_LINKTIME
#define CRYPTO_30_LIBCV_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CRYPTO_30_LIBCV_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CRYPTO_30_LIBCV_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CRYPTO_30_LIBCV_CONFIGURATION_VARIANT
#define CRYPTO_30_LIBCV_CONFIGURATION_VARIANT CRYPTO_30_LIBCV_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CRYPTO_30_LIBCV_POSTBUILD_VARIANT_SUPPORT
#define CRYPTO_30_LIBCV_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define CRYPTO_30_LIBCV_SINGLE_PARTITION                                                            0u
#define Crypto_30_LibCv_MainApplicationId                                                           CRYPTO_30_LIBCV_SINGLE_PARTITION
#define Crypto_30_LibCv_MainPartitionIdx                                                            Crypto_30_LibCv_PartitionIndexOfCSLForCRYPTO_30_LIBCV_SINGLE_PARTITION
#define CRYPTO_30_LIBCV_WATCHDOGTRIGGERFUNCTIONOFGENERAL                                            STD_OFF
#define CRYPTO_30_LIBCV_KEYVALIDITYSETCALLOUTFCTNAMEOFCONFIGURABLECALLOUTS                          STD_OFF
#define CRYPTO_30_LIBCV_KEYVALUECHANGEDCALLOUTFCTNAMEOFCONFIGURABLECALLOUTS                         STD_OFF
#define Crypto_30_LibCv_GetNvWriteBlockFctNameOfNvStorage()                                         NvM_WriteBlock
#define Crypto_30_LibCv_GetNvmEnableSetRamBlockStatusOfGeneral()                                    FALSE
#define CRYPTO_30_LIBCV_NVM_ENABLE_SET_RAM_BLOCK_STATUS                                             STD_OFF
#define Crypto_30_LibCv_GetEnableAes192OfCipherPrimitives()                                         FALSE
#define CRYPTO_30_LIBCV_ENABLE_AES192                                                               STD_OFF
#define Crypto_30_LibCv_GetEnableAes256OfCipherPrimitives()                                         TRUE
#define CRYPTO_30_LIBCV_ENABLE_AES256                                                               STD_ON
#define Crypto_30_LibCv_GetAlignKeyStorageOfGeneral()                                               FALSE
#define CRYPTO_30_LIBCV_ALIGN_KEY_STORAGE                                                           STD_OFF
#define Crypto_30_LibCv_GetCmacAesRoundkeyReuseOfMacPrimitives()                                    FALSE
#define CRYPTO_30_LIBCV_CMAC_AES_ROUNDKEY_REUSE                                                     STD_OFF
#define Crypto_30_LibCv_GetEnableKeyLockingOfGeneral()                                              TRUE
#define CRYPTO_30_LIBCV_ENABLE_KEY_LOCKING                                                          STD_ON
#define Crypto_30_LibCv_GetKeyElementDeleteOfGeneral()                                              FALSE
#define CRYPTO_30_LIBCV_KEY_ELEMENT_DELETE                                                          STD_OFF
#define Crypto_30_LibCv_GetMultiPartitionRuntimeChecksOfGeneral()                                   FALSE
#define CRYPTO_30_LIBCV_MULTI_PARTITION_RUNTIME_CHECKS                                              STD_OFF
#define Crypto_30_LibCv_GetRedirectionOfGeneral()                                                   TRUE
#define CRYPTO_30_LIBCV_REDIRECTION                                                                 STD_ON
#define CRYPTO_30_LIBCV_SHE_DEBUG_CMD                                                               STD_OFF
#define CRYPTO_30_LIBCV_SHE_ENABLE_COUNTER                                                          STD_OFF
#define CRYPTO_30_LIBCV_SHE_ENABLE_FID                                                              STD_OFF
#define Crypto_30_LibCv_GetNumberOfLongTermPrimitiveWorkspaceOfGeneral()                            0u
#define CRYPTO_30_LIBCV_NUMBER_OF_LONG_TERM_PRIMITIVE_WORKSPACE                                     0u
#define Crypto_30_LibCv_GetKeyGenerateMaxLengthOfGeneral()                                          32u
#define CRYPTO_30_LIBCV_KEY_GENERATE_MAX_LENGTH                                                     32u
#define Crypto_30_LibCv_GetDefaultRandomMaxRetriesOfGeneral()                                       10u
#define CRYPTO_30_LIBCV_DEFAULT_RANDOM_MAX_RETRIES                                                  10u
#define Crypto_30_LibCv_GetNvManagementDataPerKeyOfNvStorage()                                      4u
#define CRYPTO_30_LIBCV_NV_MANAGEMENT_DATA_PER_KEY                                                  4u
#define CRYPTO_30_LIBCV_NUMBER_OF_DRIVER_OBJECTS                                                    9u
#define CRYPTO_30_LIBCV_NUMBER_OF_PARTITIONS                                                        0u
#define CRYPTO_30_LIBCV_NO_DEFAULT_RANDOM_KEY                                                       0xffu
/* Module version information */
#define CRYPTO_30_LIBCV_CFG_MAJOR_VERSION                                                           14u
#define CRYPTO_30_LIBCV_CFG_MINOR_VERSION                                                           3u
#define CRYPTO_30_LIBCV_CFG_PATCH_VERSION                                                           0u
#define CRYPTO_30_LIBCV_GENERATOR_MAJOR_VERSION                                                     14u
#define CRYPTO_30_LIBCV_GENERATOR_MINOR_VERSION                                                     3u
#define CRYPTO_30_LIBCV_GENERATOR_PATCH_VERSION                                                     0u

/* Defines for general parameters of type boolean, integer and enumeration */
#define CRYPTO_30_LIBCV_VERSION_INFO_API                                                            STD_OFF 
#define CRYPTO_30_LIBCV_USE_VSTD_LIB                                                                STD_ON 
#define CRYPTO_30_LIBCV_STRICT_LENGTH_CHECK_FOR_KEY_ELEMENT_GET                                     STD_ON 
#define CRYPTO_30_LIBCV_SHE_KEY_UPDATE                                                              STD_OFF 

/* Symbolic Name Define Block */
#define CryptoConf_CryptoDriverObject_CryptoDriverObject_Tls_Conn0                                  0u 
#define CryptoConf_CryptoDriverObject_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished           1u 
#define CryptoConf_CryptoDriverObject_CryptoDriverObject_Tls_Conn1                                  2u 
#define CryptoConf_CryptoDriverObject_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished           3u 
#define CryptoConf_CryptoDriverObject_CryptoDriverObject_Tls_Conn1_HS_HashSha384                    4u 
#define CryptoConf_CryptoDriverObject_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384                      5u 
#define CryptoConf_CryptoDriverObject_CryptoDriverObject_Tls_Global_HashSha1                        6u 
#define CryptoConf_CryptoDriverObject_Crypto_30_LibCv                                               7u 
#define CryptoConf_CryptoDriverObject_Crypto_30_LibCv_General                                       8u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Scc_ResumeSession                              1u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_EccNistP256R1Sha256                        1u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_EccNistP521R1Sha512                        1u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_Gcm256_Key                                 1u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_HMacShaX                                   1u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_HashShaX                                   1u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_HashShaX_Sha384                            1u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_KeyEx_SharedSecret                         1u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_PrfSecret                                  1u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_PrfSecret_Secp521                          1u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_PubKey                                     1u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_Xcrypt_Key                                 1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Aead_ChaCha_Key                                 1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Cipher_Key                                      1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Cipher_Key_She                                  1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Cipher_Key_She_Ram                              1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Hash_Result                                     1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Ke_Target_Key                                   1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Password                          1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_SharedValue                         1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyGenerate_Key                                 1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Mac_Key                                         1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Mac_Key_She                                     1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Mac_Key_She384                                  1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Mac_Key_She_Ram                                 1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_EcDsa_SECp160r1_private               1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_EcDsa_SECp160r1_public                1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_EcDsa_SECp256r1_private               1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_EcDsa_SECp256r1_public                1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_EcDsa_SECp384r1_private               1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_EcDsa_SECp384r1_public                1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_EcDsa_SECp512r1_private               1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_EcDsa_SECp512r1_public                1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_EcDsa_SECp521r1_private               1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_EcDsa_SECp521r1_public                1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_EdDsa_Ed25519_private                 1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_EdDsa_Ed25519_public                  1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_EdDsa_Ed448_private                   1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_EdDsa_Ed448_public                    1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_Key                                   1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_SlhDsa_SHA2_128s_public               1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_Sm2Verify_P256Sm2_public              1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_Sm2_P256Sm2_private                   1u 
#define CryptoConf_CryptoKeyElement_SccPublicKey                                                    1u 
#define CryptoConf_CryptoKeyElement_SccPublicKey_ISO20_secp521r1                                    1u 
#define CryptoConf_CryptoKeyElement_Scc_Signature_Key_ISO20                                         1u 
#define CryptoConf_CryptoKeyElement_Scc_Signature_Key_ISO20_Temp                                    1u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Scc_SessionHash                                2u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Mac_Proof                                       2u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_RandomNumber_Seed                          3u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_vSecPrim_RandomNumber_Seed                     3u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Seed                                     3u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128            3u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES256            3u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_HASH_SHA2_512     3u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_RandomNumber_Algorithm                     4u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_vSecPrim_RandomNumber_Algorithm                4u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Algorithm                                4u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Algorithm_Fips186_Sha1                   4u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128       4u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128_DF    4u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES256       4u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES256Df     4u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_HASH_SHA2_512 4u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_Gcm256_IV                                  5u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_Xcrypt_IV                                  5u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Aead_ChaCha_Nonce                               5u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Cipher_IV                                       5u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Cipher_Proof                                    6u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Cipher_2NDKey                                   7u 
#define CryptoConf_CryptoKeyElement_SccPrivateKeyDecrypted                                          7u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Base                                8u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_KeyEx_PrivKey                              9u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_PrivKey                             9u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_KeyEx_OwnPubKey                            10u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_OwnPubKey                           10u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_OwnPubKey_Secp521                   10u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_KeyEx_Algorithm                            12u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Algorithm_ANSIP256R1                12u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Algorithm_NISTP224R1_BD             12u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Algorithm_P256R1_BD                 12u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Algorithm_SECP256R1                 12u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Algorithm_SECP384R1                 12u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Algorithm_SECP521R1                 12u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Algorithm_Spake2Plus_Suite8         12u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Algorithm_Spake2Plus_Suite8_1       12u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Algorithm_X25519                    12u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Algorithm_X448                      12u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Salt                              13u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Iterations_HKDF                   14u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Iterations_PBKDF2                 14u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_ASM_NISTFIPS1864        15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA256        15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384        15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_Option1_SHA256     15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_Option1_SHA512     15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_ISO15118                15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_ISO15118_20             15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_KDF_X963_SHA256         15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_KDF_X963_SHA512         15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_NIST80056A              15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_PBKDF2_HMAC_SHA1        15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_PBKDF2_HMAC_SHA256      15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_SYM_NIST800108          15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_Spake2Plus_P256R1       15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerive_Algorithm                             15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyGenerate_Seed                                16u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyGenerate_Algorithm                           17u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyGenerate_Algorithm_Ansi_Nist_Sec_P256R1      17u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519                   17u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyGenerate_Algorithm_Nist_Sec_P384R1           17u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyGenerate_Algorithm_Nist_Sec_P521R1           17u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyGenerate_Algorithm_Sm2P256v1                 17u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyGenerate_Algorithm_Symmetric_Generic         17u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Label                             130u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_AdditionalInfo                                  131u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_AdditionalInfo                    131u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Rsa_Modulus                                     160u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_Rsa_Modulus                           160u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Rsa_Pub_Exponent                                161u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_Rsa_Pub_Exponent                      161u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Rsa_Priv_Exponent                               162u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_Rsa_Priv_Exponent                     162u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Rsa_Salt                                        163u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_Rsa_Salt                              163u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Rsa_SaltLength                                  164u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_Rsa_SaltLength                        164u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_PartnerPubKey                       3003u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_PartnerPubKey_2                     3004u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Intermediate                        3005u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_NumEcu                              3006u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_EcuId                               3007u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_SCC_Contract_PubKey                             3013u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_SCC_IV_And_Encrypted_PrivKey                    3014u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_PrivateString                            3015u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_AdditinalInput                           3016u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_AdditionalInput                          3016u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Nonce                                    3017u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Reseed_Counter                           3018u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_She_Counter                                     3019u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_She_UId                                         3021u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Rsa_PrimeP                                      3051u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_Rsa_PrimeP                            3051u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Rsa_PrimeQ                                      3052u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_Rsa_PrimeQ                            3052u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Rsa_ExponentDp                                  3053u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_Rsa_ExponentDp                        3053u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Rsa_ExponentDq                                  3054u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_Rsa_ExponentDq                        3054u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Rsa_InverseQi                                   3055u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_Rsa_InverseQi                         3055u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_She_BootProtection                              3056u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_She_DebuggerProtection                          3057u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Label                                           3058u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_SCC_Contract_AAD                                3060u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_EdDsa_Context                                   3061u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_HkdfTmpBuffer                              3080u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_MasterSecret                               3080u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_PrfInputValue                              3080u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_PrfResultPrivate                           3080u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_PrfResultPublic                            3080u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_TmpBuffer                                  3080u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_PrfOutputValuePrivate                      3081u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_PrfOutputValuePublic                       3081u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_PrfValueActivePrivate                      3082u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_PrfValueActivePublic                       3082u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_PrfValuePassivePrivate                     3083u 
#define CryptoConf_CryptoKeyElement_CryptoKeyElement_Tls_PrfValuePassivePublic                      3083u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_W0                                              3084u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_W1                                              3085u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_L                                               3086u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Verification                                    3087u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Verification_Result                             3088u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_Sm2_ID                                3092u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_Sm2Generate_P256Sm2_public            3093u 
#define CryptoConf_CryptoKey_Crypto_SccContractPrivKey                                              0u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey                          1u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PrivateKey                        2u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_V2GRoot_Y_PublicKey                                3u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey                         4u 
#define CryptoConf_CryptoKey_Crypto_TlsSha1Key                                                      5u 
#define CryptoConf_CryptoKey_Crypto_SccPublicKey                                                    6u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey                      7u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey                    8u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt                                  9u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_CertVerify_PubKey                                  10u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_V2GRoot_X_PublicKey                                11u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_HMacShaX_Generate                                  12u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PrivateKey                     13u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_HMacShaX_Verify                                    14u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_HS_HashSha256_ToClientFinished                     15u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_HS_HashSha256_ToServerFinished                     16u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey                     17u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_HS_RandomNumber                                    18u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey                    19u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_MasterSecret                                       20u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_PreMasterSecretInfo                                21u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey                    22u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_Prf_ResultPrivate                                  23u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey                      24u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_Prf_ResultPublic                                   25u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_Prf_Secret                                         26u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey                     27u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate                        28u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_PrfCalculationValuesPublic                         29u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey             30u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_TmpBuffer                                          31u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Global_HashSha1                                          32u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey                    33u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt                                  34u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey                          35u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey                    36u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey                      37u 
#define CryptoConf_CryptoKey_CryptoKey_TlsConn0_HS_DhKeyExchange                                    38u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey                         39u 
#define CryptoConf_CryptoKey_CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1                          40u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey                41u 
#define CryptoConf_CryptoKey_CryptoKey_TlsConn0_HS_DhSignatureGenerate                              42u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_MasterSecret                                       43u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_Prf_ResultPrivate                                  44u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey                       45u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_Prf_ResultPublic                                   46u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Hkdf_Sha384ExpandIn                                      47u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Hkdf_Sha384ExpandOut                                     48u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_Prf_Secret_Secp521                                 49u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate                        50u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_PrfCalculationValuesPublic                         51u 
#define CryptoConf_CryptoKey_CryptoKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey                      52u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_TmpBuffer                                          53u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey                       54u 
#define CryptoConf_CryptoKey_CryptoKey_Leaf_Server_A_EccSecp521r1Sha512_PubKey                      55u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey                            56u 
#define CryptoConf_CryptoKey_CryptoKey_RandomGenerator                                              57u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_RootA_EccSecp256r1Sha256_PubKey                          58u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey                          59u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_HS_HashSha256_Finished                             60u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey                       61u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey                          62u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey                       63u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey                       64u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey                        65u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_KDF                                                      66u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_KDF_1                                                    67u 
#define CryptoConf_CryptoKey_CryptoKey_DefaultRandomSource                                          68u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_MOContract_X_PrivateKey                                  69u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_OEMProv_X_PrivateKey                                     70u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_HS_HashSha256_Finished                             71u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_MOSubCa2_X_PublicKey                                     72u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_MOSubCa1_X_PublicKey                                     73u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_MOContract_X_PublicKey                                   74u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_OEMProv_X_PublicKey                                      75u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_OEMProvSubCa2                                            76u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_OEMProvSubCa1                                            77u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_OEMProvRoot                                              78u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret                             79u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Hkdf_DerivedSecret                                       80u 
#define CryptoConf_CryptoKey_CryptoKey_Hkdf_Sha256                                                  81u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret                             82u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_MORoot_X_PublicKey                                       83u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ProvLeaf_X_PublicKey                                     84u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ProvSubCa1_X_PublicKey                                   85u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ProvSubCa2_X_PublicKey                                   86u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ResumeSessionInfo                                        87u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Hkdf_TmpBuffer                                           88u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_SHA512                                                   89u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_V2GRoot_X_PublicKey                                      90u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_V2GRoot_Y_PublicKey                                      91u 
#define CryptoConf_CryptoKey_CryptoKey_V2G_Root_1_PubKey                                            92u 
#define CryptoConf_CryptoKey_CryptoKey_V2G_Root_2_PubKey                                            93u 
#define CryptoConf_CryptoKey_CryptoKey_Hkdf_Sha384                                                  94u 
#define CryptoConf_CryptoKey_CryptoKey_V2G_Root_3_PubKey                                            95u 
#define CryptoConf_CryptoKey_CryptoKey_V2G_Root_4_PubKey                                            96u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_Aes256GcmEncrypt                                   97u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_HMacSha384Generate                                       98u 
#define CryptoConf_CryptoKey_CryptoKey_V2G_Root_5_PubKey                                            99u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Hkdf_Sha256ExpandIn                                      100u 
#define CryptoConf_CryptoKey_CryptoKey_V2G_Root_6_PubKey                                            101u 
#define CryptoConf_CryptoKey_CryptoKey_V2G_Root_7_PubKey                                            102u 
#define CryptoConf_CryptoKey_CryptoKey_V2G_Root_8_PubKey                                            103u 
#define CryptoConf_CryptoKey_CryptoKey_V2G_Root_9_PubKey                                            104u 
#define CryptoConf_CryptoKey_CryptoKey_HmacSha256Generate_1                                         105u 
#define CryptoConf_CryptoKey_CryptoKey_V2G_Root_10_PubKey                                           106u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_Aes256GcmDecrypt                                   107u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt                            108u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn0_HS_DhKeyExchange                                   109u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Hkdf_Sha256ExpandOut                                     110u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt                            111u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_ChaCha20_Decrypt                                         112u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_ChaCha20_PassiveDecrypt                                  113u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_ChaCha20_Encrypt                                         114u 
#define CryptoConf_CryptoKey_CryptoKey_Tls_ChaCha20_PassiveEncrypt                                  115u 
#define CryptoConf_CryptoKey_Tls_Conn1_HS_HashSha384_Finished                                       116u 
#define CryptoConf_CryptoKey_CryptoKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1                    117u 
#define CryptoConf_CryptoKey_CryptoKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey                            118u 
#define CryptoConf_CryptoNvBlock_CryptoNvBlock                                                      0u 

#define CRYPTO_30_LIBCV_NV_PROCESSING_DEFERRED                                                      0x00u 
#define CRYPTO_30_LIBCV_NV_PROCESSING_IMMEDIATE                                                     0x01u 
#define CRYPTO_30_LIBCV_NV_CONSISTENCY_LEVEL_DETECT                                                 0x00u 
#define CRYPTO_30_LIBCV_NV_CONSISTENCY_LEVEL_NONE                                                   0x01u 

#define CRYPTO_30_LIBCV_RAM_KEY_EXPORT                                                              STD_OFF

#define CRYPTO_30_LIBCVPERSIST_SIZE                                                                 797
#ifndef CRYPTO_30_LIBCV_DEV_ERROR_DETECT
#define CRYPTO_30_LIBCV_DEV_ERROR_DETECT STD_OFF
#endif
#ifndef CRYPTO_30_LIBCV_DEV_ERROR_REPORT
#define CRYPTO_30_LIBCV_DEV_ERROR_REPORT STD_OFF
#endif

/* The following defines keep the max size of the used key elements. */

/* The following defines give an overview which services are used. */
#define CRYPTO_30_LIBCV_SERVICE_AEADDECRYPT                                                         STD_ON
#define CRYPTO_30_LIBCV_SERVICE_AEADENCRYPT                                                         STD_ON
#define CRYPTO_30_LIBCV_SERVICE_CERTIFICATE_PARSE                                                   STD_OFF
#define CRYPTO_30_LIBCV_SERVICE_CERTIFICATE_VERIFY                                                  STD_OFF
#define CRYPTO_30_LIBCV_SERVICE_DECRYPT                                                             STD_ON
#define CRYPTO_30_LIBCV_SERVICE_ENCRYPT                                                             STD_ON
#define CRYPTO_30_LIBCV_SERVICE_HASH                                                                STD_ON
#define CRYPTO_30_LIBCV_SERVICE_KEY_DERIVE                                                          STD_ON
#define CRYPTO_30_LIBCV_SERVICE_KEY_EXCHANGE_CALC_PUBVAL                                            STD_OFF
#define CRYPTO_30_LIBCV_SERVICE_KEY_EXCHANGE_CALC_SECRET                                            STD_ON
#define CRYPTO_30_LIBCV_SERVICE_KEY_GENERATE                                                        STD_ON
#define CRYPTO_30_LIBCV_SERVICE_KEY_SET_VALID                                                       STD_OFF
#define CRYPTO_30_LIBCV_SERVICE_MAC_GENERATE                                                        STD_ON
#define CRYPTO_30_LIBCV_SERVICE_MAC_VERIFY                                                          STD_ON
#define CRYPTO_30_LIBCV_SERVICE_RANDOM                                                              STD_ON
#define CRYPTO_30_LIBCV_SERVICE_RANDOM_SEED                                                         STD_OFF
#define CRYPTO_30_LIBCV_SERVICE_SIGNATURE_GENERATE                                                  STD_ON
#define CRYPTO_30_LIBCV_SERVICE_SIGNATURE_VERIFY                                                    STD_ON
#define CRYPTO_30_LIBCV_SERVICE_KEYSETINVALID                                                       STD_OFF
/* The following defines are used for key access rights. */
#define CRYPTO_30_LIBCV_RA_ALLOWED                                                                  0x00u
#define CRYPTO_30_LIBCV_RA_ENCRYPTED                                                                0x01u
#define CRYPTO_30_LIBCV_RA_INTERNAL_COPY                                                            0x02u
#define CRYPTO_30_LIBCV_RA_DENIED                                                                   0x03u
#define CRYPTO_30_LIBCV_WA_ALLOWED                                                                  0x00u
#define CRYPTO_30_LIBCV_WA_ENCRYPTED                                                                0x01u
#define CRYPTO_30_LIBCV_WA_INTERNAL_COPY                                                            0x02u
#define CRYPTO_30_LIBCV_WA_DENIED                                                                   0x03u

/* The following defines represent the configuration of CryptoKeyDeriveAlgorithm. */
#define CRYPTO_30_LIBCV_KEY_DERIVE_ALGORITHM                                                        STD_ON
#define CRYPTO_30_LIBCV_KDF_ALGO_ASYM_NIST_FIPS_186_4_ERB_ENABLED                                   STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_SYM_NIST_800_108_CNT_MODE_SHA256_ENABLED                           STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_ISO_15118_CERTIFICATE_HANDLING_ENABLED                             STD_ON
#define CRYPTO_30_LIBCV_KDF_ALGO_NIST_800_56_A_ONE_PASS_C1E1S_SINGLE_STEP_KDF_SHA256_ENABLED        STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_X963_SHA256_ENABLED                                                STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_PBKDF2_HMAC_SHA1_ENABLED                                           STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_PBKDF2_HMAC_SHA256_ENABLED                                         STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_X963_SHA512_ENABLED                                                STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_HKDF_HMAC_SHA256_ENABLED                                           STD_ON
#define CRYPTO_30_LIBCV_KDF_ALGO_SPAKE2_PLUS_P256R1_ENABLED                                         STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_HKDF_OPTION1_SHA256_ENABLED                                        STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_HKDF_HMAC_SHA384_ENABLED                                           STD_ON
#define CRYPTO_30_LIBCV_KDF_ALGO_HKDF_OPTION1_SHA512_ENABLED                                        STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_ISO_15118_20_CERTIFICATE_HANDLING_ENABLED                          STD_ON
#define CRYPTO_30_LIBCV_KDF_ALGO_HKDF_EXPAND_HMAC_SHA256_ENABLED                                    STD_ON
#define CRYPTO_30_LIBCV_KDF_ALGO_HKDF_EXPAND_HMAC_SHA384_ENABLED                                    STD_ON

/* The following defines represent the configuration of CryptoKeyExchangeAlgorithm. */
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_ALGORITHM                                                      STD_ON
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_ALGORITHM_X25519_ENABLED                                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_ALGORITHM_ANSIP256R1_ENABLED                                   STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_ALGORITHM_SECP256R1_ENABLED                                    STD_ON
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_ALGORITHM_SECP384R1_ENABLED                                    STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_ALGORITHM_SPAKE2_PLUS_CIPHERSUITE_8_ENABLED                    STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_ALGORITHM_NISTP224R1_BD_ENABLED                                STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_ALGORITHM_SECP521R1_ENABLED                                    STD_ON
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_ALGORITHM_X448_ENABLED                                         STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_ALGORITHM_P256R1_BD_ENABLED                                    STD_OFF

/* The following defines represent the configuration of CryptoKeyGenerateAlgorithm. */
#define CRYPTO_30_LIBCV_KEY_GENERATE_ALGORITHM                                                      STD_ON
#define CRYPTO_30_LIBCV_KEY_GENERATE_ALGORITHM_SYMMETRIC_GENERIC_ENABLED                            STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ALGORITHM_ANSI_NIST_SEC_P256R1_ENABLED                         STD_ON
#define CRYPTO_30_LIBCV_KEY_GENERATE_ALGORITHM_NIST_SEC_P384R1_ENABLED                              STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ALGORITHM_ED25519_ENABLED                                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ALGORITHM_NIST_SEC_P521R1_ENABLED                              STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ALGORITHM_SM2P256V1_ENABLED                                    STD_OFF

#define CRYPTO_30_LIBCV_VSEC_PRIM_ESLT_LENGTH_32                                                    STD_ON

/* The following defines describes the used primitives. They are set together in the following way:
 * (Service | Family | Mode | Second Family) without prefixed CRYPTO_ALOGFAM and CRYPTO_ALGOMODE.
 * So, a configured encryption service with AES in CBC Mode without secondary family results in 
 * CRYPTO_30_LIBCV_ENCRYPT_AES_ECB_NOT_SET.
 */
#define CRYPTO_30_LIBCV_AEADDECRYPT_AES                                                             STD_ON
#define CRYPTO_30_LIBCV_AEADDECRYPT_AES_CUSTOM_CCM_NOT_SET                                          STD_OFF
#define CRYPTO_30_LIBCV_AEADDECRYPT_AES_GCM_NOT_SET                                                 STD_ON
#define CRYPTO_30_LIBCV_AEADDECRYPT_CHACHA                                                          STD_ON
#define CRYPTO_30_LIBCV_AEADDECRYPT_CHACHA_20ROUNDS_CUSTOM_POLY_1305                                STD_ON
#define CRYPTO_30_LIBCV_AEADDECRYPT_CHACHA_20ROUNDS_POLY1305                                        STD_ON
#define CRYPTO_30_LIBCV_AEADDECRYPT_SECFAM_CUSTOM_POLY_1305                                         STD_ON
#define CRYPTO_30_LIBCV_AEADDECRYPT_SECFAM_NOT_SET                                                  STD_ON
#define CRYPTO_30_LIBCV_AEADDECRYPT_SECFAM_POLY1305                                                 STD_ON
#define CRYPTO_30_LIBCV_AEADENCRYPT_AES                                                             STD_ON
#define CRYPTO_30_LIBCV_AEADENCRYPT_AES_CUSTOM_CCM_NOT_SET                                          STD_OFF
#define CRYPTO_30_LIBCV_AEADENCRYPT_AES_GCM_NOT_SET                                                 STD_ON
#define CRYPTO_30_LIBCV_AEADENCRYPT_CHACHA                                                          STD_ON
#define CRYPTO_30_LIBCV_AEADENCRYPT_CHACHA_20ROUNDS_CUSTOM_POLY_1305                                STD_ON
#define CRYPTO_30_LIBCV_AEADENCRYPT_CHACHA_20ROUNDS_POLY1305                                        STD_ON
#define CRYPTO_30_LIBCV_AEADENCRYPT_SECFAM_CUSTOM_POLY_1305                                         STD_ON
#define CRYPTO_30_LIBCV_AEADENCRYPT_SECFAM_NOT_SET                                                  STD_ON
#define CRYPTO_30_LIBCV_AEADENCRYPT_SECFAM_POLY1305                                                 STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES                                                                 STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_CBC_CUSTOM_PADDING_PKCS7                                        STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_CBC_NOT_SET                                                     STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_CBC_PADDING_ONEWITHZEROS                                        STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_CBC_PADDING_PKCS7                                               STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_CTR_CUSTOM_PADDING_PKCS7                                        STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_CTR_NOT_SET                                                     STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_CTR_PADDING_ONEWITHZEROS                                        STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_CTR_PADDING_PKCS7                                               STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_ECB_CUSTOM_PADDING_PKCS7                                        STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_ECB_NOT_SET                                                     STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_ECB_PADDING_ONEWITHZEROS                                        STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_ECB_PADDING_PKCS7                                               STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_RSA                                                                 STD_OFF
#define CRYPTO_30_LIBCV_DECRYPT_RSA_CUSTOM_RSAES_OAEP_CRT_SHA1                                      STD_OFF
#define CRYPTO_30_LIBCV_DECRYPT_RSA_CUSTOM_RSAES_OAEP_CRT_SHA2_256                                  STD_OFF
#define CRYPTO_30_LIBCV_DECRYPT_RSA_RSAES_OAEP_SHA1                                                 STD_OFF
#define CRYPTO_30_LIBCV_DECRYPT_RSA_RSAES_OAEP_SHA2_256                                             STD_OFF
#define CRYPTO_30_LIBCV_DECRYPT_RSA_RSAES_PKCS1_v1_5_NOT_SET                                        STD_OFF
#define CRYPTO_30_LIBCV_DECRYPT_SECFAM_CUSTOM_PADDING_PKCS7                                         STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_SECFAM_NOT_SET                                                      STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_SECFAM_PADDING_ONEWITHZEROS                                         STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_SECFAM_PADDING_PKCS7                                                STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_SECFAM_SHA1                                                         STD_OFF
#define CRYPTO_30_LIBCV_DECRYPT_SECFAM_SHA2_256                                                     STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_AES                                                                 STD_ON
#define CRYPTO_30_LIBCV_ENCRYPT_AES_CBC_CUSTOM_PADDING_PKCS7                                        STD_ON
#define CRYPTO_30_LIBCV_ENCRYPT_AES_CBC_NOT_SET                                                     STD_ON
#define CRYPTO_30_LIBCV_ENCRYPT_AES_CBC_PADDING_ONEWITHZEROS                                        STD_ON
#define CRYPTO_30_LIBCV_ENCRYPT_AES_CBC_PADDING_PKCS7                                               STD_ON
#define CRYPTO_30_LIBCV_ENCRYPT_AES_CTR_CUSTOM_PADDING_PKCS7                                        STD_ON
#define CRYPTO_30_LIBCV_ENCRYPT_AES_CTR_NOT_SET                                                     STD_ON
#define CRYPTO_30_LIBCV_ENCRYPT_AES_CTR_PADDING_ONEWITHZEROS                                        STD_ON
#define CRYPTO_30_LIBCV_ENCRYPT_AES_CTR_PADDING_PKCS7                                               STD_ON
#define CRYPTO_30_LIBCV_ENCRYPT_AES_ECB_CUSTOM_PADDING_PKCS7                                        STD_ON
#define CRYPTO_30_LIBCV_ENCRYPT_AES_ECB_NOT_SET                                                     STD_ON
#define CRYPTO_30_LIBCV_ENCRYPT_AES_ECB_PADDING_ONEWITHZEROS                                        STD_ON
#define CRYPTO_30_LIBCV_ENCRYPT_AES_ECB_PADDING_PKCS7                                               STD_ON
#define CRYPTO_30_LIBCV_ENCRYPT_RSA                                                                 STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_RSA_RSAES_OAEP_SHA1                                                 STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_RSA_RSAES_OAEP_SHA2_256                                             STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_RSA_RSAES_PKCS1_v1_5_NOT_SET                                        STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_SECFAM_CUSTOM_PADDING_PKCS7                                         STD_ON
#define CRYPTO_30_LIBCV_ENCRYPT_SECFAM_NOT_SET                                                      STD_ON
#define CRYPTO_30_LIBCV_ENCRYPT_SECFAM_PADDING_ONEWITHZEROS                                         STD_ON
#define CRYPTO_30_LIBCV_ENCRYPT_SECFAM_PADDING_PKCS7                                                STD_ON
#define CRYPTO_30_LIBCV_ENCRYPT_SECFAM_SHA1                                                         STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_SECFAM_SHA2_256                                                     STD_OFF
#define CRYPTO_30_LIBCV_HASH_CUSTOM_MD5                                                             STD_OFF
#define CRYPTO_30_LIBCV_HASH_CUSTOM_MD5_NOT_SET_NOT_SET                                             STD_OFF
#define CRYPTO_30_LIBCV_HASH_RIPEMD160                                                              STD_OFF
#define CRYPTO_30_LIBCV_HASH_RIPEMD160_NOT_SET_NOT_SET                                              STD_OFF
#define CRYPTO_30_LIBCV_HASH_SECFAM_NOT_SET                                                         STD_ON
#define CRYPTO_30_LIBCV_HASH_SHA1                                                                   STD_ON
#define CRYPTO_30_LIBCV_HASH_SHA1_NOT_SET_NOT_SET                                                   STD_ON
#define CRYPTO_30_LIBCV_HASH_SHA2_256                                                               STD_ON
#define CRYPTO_30_LIBCV_HASH_SHA2_256_NOT_SET_NOT_SET                                               STD_ON
#define CRYPTO_30_LIBCV_HASH_SHA2_384                                                               STD_ON
#define CRYPTO_30_LIBCV_HASH_SHA2_384_NOT_SET_NOT_SET                                               STD_ON
#define CRYPTO_30_LIBCV_HASH_SHA2_512                                                               STD_ON
#define CRYPTO_30_LIBCV_HASH_SHA2_512_NOT_SET_NOT_SET                                               STD_ON
#define CRYPTO_30_LIBCV_HASH_SHA3_224                                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHA3_224_NOT_SET_NOT_SET                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHA3_256                                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHA3_256_NOT_SET_NOT_SET                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHA3_384                                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHA3_384_NOT_SET_NOT_SET                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHA3_512                                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHA3_512_NOT_SET_NOT_SET                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHAKE128                                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHAKE128_NOT_SET_NOT_SET                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHAKE256                                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHAKE256_NOT_SET_NOT_SET                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SM3                                                                    STD_OFF
#define CRYPTO_30_LIBCV_HASH_SM3_NOT_SET_NOT_SET                                                    STD_OFF
#define CRYPTO_30_LIBCV_KEYSETINVALID_NOT_SET                                                       STD_OFF
#define CRYPTO_30_LIBCV_KEYSETINVALID_NOT_SET_NOT_SET_NOT_SET                                       STD_OFF
#define CRYPTO_30_LIBCV_KEYSETINVALID_SECFAM_NOT_SET                                                STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM                                                           STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM_FIPS186                                                   STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM_FIPS186_NOT_SET_SHA2_256                                  STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM_HKDF                                                      STD_ON
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM_HKDF_HMAC_SHA2_256                                        STD_ON
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM_HKDF_HMAC_SHA2_384                                        STD_ON
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM_HKDF_NOT_SET_SHA2_256                                     STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM_ISO15118                                                  STD_ON
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM_ISO15118_NOT_SET_NOT_SET                                  STD_ON
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM_NOT_SET_NOT_SET                                           STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM_SPAKE2_PLUS                                               STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM_SPAKE2_PLUS_CUSTOM_P256R1_NOT_SET                         STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_DH                                                               STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_DH_CUSTOM_P256R1_SHA2_256                                        STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_FIPS186                                                          STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_FIPS186_NOT_SET_SHA2_256                                         STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_HKDF                                                             STD_ON
#define CRYPTO_30_LIBCV_KEY_DERIVE_HKDF_HMAC_SHA2_256                                               STD_ON
#define CRYPTO_30_LIBCV_KEY_DERIVE_HKDF_HMAC_SHA2_384                                               STD_ON
#define CRYPTO_30_LIBCV_KEY_DERIVE_HKDF_NOT_SET_SHA2_256                                            STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_HKDF_NOT_SET_SHA2_512                                            STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_KDFX963                                                          STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_KDFX963_NOT_SET_SHA2_256                                         STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_KDFX963_NOT_SET_SHA2_512                                         STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_NOT_SET                                                          STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_NOT_SET_CTR_SHA2_256                                             STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_PBKDF2                                                           STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_PBKDF2_HMAC_SHA1                                                 STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_PBKDF2_HMAC_SHA2_256                                             STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_SECFAM_NOT_SET                                                   STD_ON
#define CRYPTO_30_LIBCV_KEY_DERIVE_SECFAM_SHA1                                                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_SECFAM_SHA2_256                                                  STD_ON
#define CRYPTO_30_LIBCV_KEY_DERIVE_SECFAM_SHA2_384                                                  STD_ON
#define CRYPTO_30_LIBCV_KEY_DERIVE_SECFAM_SHA2_512                                                  STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_ECCANSI                                     STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_ECCANSI_CUSTOM_P256R1_NOT_SET               STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_ECCSEC                                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_ECCSEC_CUSTOM_P256R1_NOT_SET                STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_ECCSEC_CUSTOM_P384R1_NOT_SET                STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_ECCSEC_CUSTOM_P521R1_NOT_SET                STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_SPAKE2_PLUS                                 STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_SPAKE2_PLUS_CUSTOM_MODE_1_CUSTOM_CIPHER_SUITE_8 STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_SPAKE2_PLUS_NOT_SET_CUSTOM_CIPHER_SUITE_8   STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_X25519                                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_X25519_NOT_SET_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCANSI                                            STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCANSI_CUSTOM_P256R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCNIST                                            STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCNIST_CUSTOM_P224R1_CUSTOM_BD                    STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCNIST_CUSTOM_P256R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCNIST_CUSTOM_P384R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCNIST_CUSTOM_P521R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCSEC                                             STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCSEC_CUSTOM_P224R1_CUSTOM_BD                     STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCSEC_CUSTOM_P256R1_NOT_SET                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCSEC_CUSTOM_P384R1_NOT_SET                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCSEC_CUSTOM_P521R1_NOT_SET                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ED25519                                            STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ED25519_NOT_SET_NOT_SET                            STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_SECFAM_CUSTOM_BD                                   STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_SECFAM_CUSTOM_CIPHER_SUITE_8                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_SECFAM_NOT_SET                                     STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_X25519                                             STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_X25519_NOT_SET_NOT_SET                             STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_ECCANSI                                     STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_ECCANSI_CUSTOM_P256R1_NOT_SET               STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_ECCSEC                                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_ECCSEC_CUSTOM_P256R1_NOT_SET                STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_ECCSEC_CUSTOM_P384R1_NOT_SET                STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_ECCSEC_CUSTOM_P521R1_NOT_SET                STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_SPAKE2_PLUS                                 STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_SPAKE2_PLUS_CUSTOM_MODE_1_CUSTOM_CIPHER_SUITE_8 STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_SPAKE2_PLUS_NOT_SET_CUSTOM_CIPHER_SUITE_8   STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_X25519                                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_X25519_NOT_SET_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCANSI                                            STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCANSI_CUSTOM_P256R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCNIST                                            STD_ON
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCNIST_CUSTOM_P224R1_CUSTOM_BD                    STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCNIST_CUSTOM_P256R1_NOT_SET                      STD_ON
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCNIST_CUSTOM_P384R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCNIST_CUSTOM_P521R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCSEC                                             STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCSEC_CUSTOM_P224R1_CUSTOM_BD                     STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCSEC_CUSTOM_P256R1_NOT_SET                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCSEC_CUSTOM_P384R1_NOT_SET                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCSEC_CUSTOM_P521R1_NOT_SET                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_SECFAM_CUSTOM_BD                                   STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_SECFAM_CUSTOM_CIPHER_SUITE_8                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_SECFAM_NOT_SET                                     STD_ON
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_X25519                                             STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_X25519_NOT_SET_NOT_SET                             STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_CUSTOM_ECCANSI                                                 STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_CUSTOM_ECCANSI_CUSTOM_P256R1_NOT_SET                           STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_CUSTOM_ECCSEC                                                  STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_CUSTOM_ECCSEC_CUSTOM_P256R1_NOT_SET                            STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_CUSTOM_ECCSEC_CUSTOM_P384R1_NOT_SET                            STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ECCANSI                                                        STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ECCANSI_CUSTOM_P256R1_NOT_SET                                  STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ECCNIST                                                        STD_ON
#define CRYPTO_30_LIBCV_KEY_GENERATE_ECCNIST_CUSTOM_P256R1_NOT_SET                                  STD_ON
#define CRYPTO_30_LIBCV_KEY_GENERATE_ECCNIST_CUSTOM_P384R1_NOT_SET                                  STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ECCSEC                                                         STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ECCSEC_CUSTOM_P256R1_NOT_SET                                   STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ECCSEC_CUSTOM_P384R1_NOT_SET                                   STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ED25519                                                        STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ED25519_NOT_SET_NOT_SET                                        STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_NOT_SET                                                        STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_NOT_SET_NOT_SET_NOT_SET                                        STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_SECFAM_NOT_SET                                                 STD_ON
#define CRYPTO_30_LIBCV_KEY_GENERATE_SM2                                                            STD_OFF
#define CRYPTO_30_LIBCV_KEY_SET_VALID_NOT_SET                                                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_SET_VALID_NOT_SET_NOT_SET_NOT_SET                                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_SET_VALID_SECFAM_NOT_SET                                                STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_AES                                                            STD_ON
#define CRYPTO_30_LIBCV_MAC_GENERATE_AES_CMAC_CUSTOM_CMD_GET_ID                                     STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_AES_CMAC_NOT_SET                                               STD_ON
#define CRYPTO_30_LIBCV_MAC_GENERATE_AES_GMAC_NOT_SET                                               STD_ON
#define CRYPTO_30_LIBCV_MAC_GENERATE_RIPEMD160                                                      STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_RIPEMD160_HMAC_NOT_SET                                         STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_SECFAM_CUSTOM_CMD_GET_ID                                       STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_SECFAM_NOT_SET                                                 STD_ON
#define CRYPTO_30_LIBCV_MAC_GENERATE_SHA1                                                           STD_ON
#define CRYPTO_30_LIBCV_MAC_GENERATE_SHA1_HMAC_NOT_SET                                              STD_ON
#define CRYPTO_30_LIBCV_MAC_GENERATE_SHA2_256                                                       STD_ON
#define CRYPTO_30_LIBCV_MAC_GENERATE_SHA2_256_HMAC_NOT_SET                                          STD_ON
#define CRYPTO_30_LIBCV_MAC_GENERATE_SHA2_384                                                       STD_ON
#define CRYPTO_30_LIBCV_MAC_GENERATE_SHA2_384_HMAC_NOT_SET                                          STD_ON
#define CRYPTO_30_LIBCV_MAC_GENERATE_SHA2_512                                                       STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_SHA2_512_HMAC_NOT_SET                                          STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_SIPHASH                                                        STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_SIPHASH_SIPHASH_2_4_NOT_SET                                    STD_OFF
#define CRYPTO_30_LIBCV_MAC_VERIFY_AES                                                              STD_ON
#define CRYPTO_30_LIBCV_MAC_VERIFY_AES_CMAC_NOT_SET                                                 STD_ON
#define CRYPTO_30_LIBCV_MAC_VERIFY_AES_GMAC_NOT_SET                                                 STD_ON
#define CRYPTO_30_LIBCV_MAC_VERIFY_RIPEMD160                                                        STD_OFF
#define CRYPTO_30_LIBCV_MAC_VERIFY_RIPEMD160_HMAC_NOT_SET                                           STD_OFF
#define CRYPTO_30_LIBCV_MAC_VERIFY_SECFAM_NOT_SET                                                   STD_ON
#define CRYPTO_30_LIBCV_MAC_VERIFY_SHA1                                                             STD_ON
#define CRYPTO_30_LIBCV_MAC_VERIFY_SHA1_HMAC_NOT_SET                                                STD_ON
#define CRYPTO_30_LIBCV_MAC_VERIFY_SHA2_256                                                         STD_ON
#define CRYPTO_30_LIBCV_MAC_VERIFY_SHA2_256_HMAC_NOT_SET                                            STD_ON
#define CRYPTO_30_LIBCV_MAC_VERIFY_SHA2_384                                                         STD_ON
#define CRYPTO_30_LIBCV_MAC_VERIFY_SHA2_384_HMAC_NOT_SET                                            STD_ON
#define CRYPTO_30_LIBCV_MAC_VERIFY_SHA2_512                                                         STD_OFF
#define CRYPTO_30_LIBCV_MAC_VERIFY_SHA2_512_HMAC_NOT_SET                                            STD_OFF
#define CRYPTO_30_LIBCV_MAC_VERIFY_SIPHASH                                                          STD_OFF
#define CRYPTO_30_LIBCV_MAC_VERIFY_SIPHASH_SIPHASH_2_4_NOT_SET                                      STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_CUSTOM_DRBG                                                          STD_ON
#define CRYPTO_30_LIBCV_RANDOM_CUSTOM_DRBG_CUSTOM_USE_DF_AES                                        STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_CUSTOM_DRBG_NOT_SET_AES                                              STD_ON
#define CRYPTO_30_LIBCV_RANDOM_CUSTOM_DRBG_NOT_SET_SHA2_512                                         STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_CUSTOM_FIPS186                                                       STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_CUSTOM_FIPS186_NOT_SET_NOT_SET                                       STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_CUSTOM_FIPS186_NOT_SET_SHA1                                          STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_DRBG                                                                 STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_DRBG_CUSTOM_USE_DF_AES                                               STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_DRBG_NOT_SET_AES                                                     STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_DRBG_NOT_SET_SHA2_512                                                STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_FIPS186                                                              STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_FIPS186_NOT_SET_NOT_SET                                              STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_FIPS186_NOT_SET_SHA1                                                 STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_RNG                                                                  STD_ON
#define CRYPTO_30_LIBCV_RANDOM_RNG_CUSTOM_USE_DF_AES                                                STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_RNG_NOT_SET_AES                                                      STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_RNG_NOT_SET_NOT_SET                                                  STD_ON
#define CRYPTO_30_LIBCV_RANDOM_RNG_NOT_SET_SHA1                                                     STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SECFAM_AES                                                           STD_ON
#define CRYPTO_30_LIBCV_RANDOM_SECFAM_NOT_SET                                                       STD_ON
#define CRYPTO_30_LIBCV_RANDOM_SECFAM_SHA1                                                          STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SECFAM_SHA2_512                                                      STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_CUSTOM_DRBG                                                     STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_CUSTOM_DRBG_CUSTOM_USE_DF_AES                                   STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_CUSTOM_DRBG_NOT_SET_AES                                         STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_CUSTOM_DRBG_NOT_SET_SHA2_512                                    STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_CUSTOM_FIPS186                                                  STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_CUSTOM_FIPS186_NOT_SET_NOT_SET                                  STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_CUSTOM_FIPS186_NOT_SET_SHA1                                     STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_DRBG                                                            STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_DRBG_CUSTOM_USE_DF_AES                                          STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_DRBG_NOT_SET_AES                                                STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_DRBG_NOT_SET_SHA2_512                                           STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_FIPS186                                                         STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_FIPS186_NOT_SET_NOT_SET                                         STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_FIPS186_NOT_SET_SHA1                                            STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_RNG                                                             STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_RNG_CUSTOM_USE_DF_AES                                           STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_RNG_NOT_SET_AES                                                 STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_RNG_NOT_SET_NOT_SET                                             STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_RNG_NOT_SET_SHA1                                                STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_SECFAM_AES                                                      STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_SECFAM_NOT_SET                                                  STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_SECFAM_SHA1                                                     STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_SECFAM_SHA2_512                                                 STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCANSI                                           STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCANSI_CUSTOM_P256R1_NOT_SET                     STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA1                        STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA2_256                    STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA2_384                    STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA2_512                    STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC                                            STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P160R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P256R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA1                         STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA2_256                     STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA2_384                     STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA2_512                     STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P384R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA1                         STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA2_256                     STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA2_384                     STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA2_512                     STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCANSI                                                  STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCANSI_CUSTOM_P256R1_NOT_SET                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCANSI_CUSTOM_P256R1_SHA1                               STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCANSI_CUSTOM_P256R1_SHA2_256                           STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCANSI_CUSTOM_P256R1_SHA2_384                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCANSI_CUSTOM_P256R1_SHA2_512                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST                                                  STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P256R1_NOT_SET                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P256R1_SHA1                               STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P256R1_SHA2_256                           STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P256R1_SHA2_384                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P256R1_SHA2_512                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P384R1_NOT_SET                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P384R1_SHA1                               STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P384R1_SHA2_256                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P384R1_SHA2_384                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P384R1_SHA2_512                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P521R1_SHA2_512                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC                                                   STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P160R1_NOT_SET                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P256R1_NOT_SET                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P256R1_SHA1                                STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P256R1_SHA2_256                            STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P256R1_SHA2_384                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P256R1_SHA2_512                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P384R1_NOT_SET                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P384R1_SHA1                                STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P384R1_SHA2_256                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P384R1_SHA2_384                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P384R1_SHA2_512                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P521R1_SHA2_512                            STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ED25519                                                  STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ED25519_NOT_SET_NOT_SET                                  STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ED25519_NOT_SET_SHA2_512                                 STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_RSA                                                      STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_RSA_CUSTOM_RSASSA_PKCS1_v1_5_CRT_SHA1                    STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_RSA_CUSTOM_RSASSA_PKCS1_v1_5_CRT_SHA2_256                STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_RSA_RSASSA_PKCS1_v1_5_SHA1                               STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_RSA_RSASSA_PKCS1_v1_5_SHA2_256                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_RSA_RSASSA_PSS_SHA1                                      STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_RSA_RSASSA_PSS_SHA2_256                                  STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_RSA_RSASSA_PSS_SHA2_384                                  STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_SECFAM_NOT_SET                                           STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_SECFAM_SHA1                                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_SECFAM_SHA2_256                                          STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_SECFAM_SHA2_384                                          STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_SECFAM_SHA2_512                                          STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_SM2                                                      STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCANSI                                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCANSI_CUSTOM_P256R1_NOT_SET                       STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA1                          STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA2_256                      STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA2_384                      STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA2_512                      STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC                                              STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P160R1_NOT_SET                        STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P256R1_NOT_SET                        STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA1                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA2_256                       STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA2_384                       STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA2_512                       STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P384R1_NOT_SET                        STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA1                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA2_256                       STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA2_384                       STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA2_512                       STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCANSI                                                    STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCANSI_CUSTOM_P256R1_NOT_SET                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCANSI_CUSTOM_P256R1_SHA1                                 STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCANSI_CUSTOM_P256R1_SHA2_256                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCANSI_CUSTOM_P256R1_SHA2_384                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCANSI_CUSTOM_P256R1_SHA2_512                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST                                                    STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P256R1_NOT_SET                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P256R1_SHA1                                 STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P256R1_SHA2_256                             STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P256R1_SHA2_384                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P256R1_SHA2_512                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P384R1_NOT_SET                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P384R1_SHA1                                 STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P384R1_SHA2_256                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P384R1_SHA2_384                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P384R1_SHA2_512                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P521R1_SHA2_512                             STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC                                                     STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P160R1_NOT_SET                               STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P256R1_NOT_SET                               STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P256R1_SHA1                                  STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P256R1_SHA2_256                              STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P256R1_SHA2_384                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P256R1_SHA2_512                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P384R1_NOT_SET                               STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P384R1_SHA1                                  STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P384R1_SHA2_256                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P384R1_SHA2_384                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P384R1_SHA2_512                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P521R1_SHA2_512                              STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ED25519                                                    STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ED25519_NOT_SET_NOT_SET                                    STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ED25519_NOT_SET_SHA2_512                                   STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_RSA                                                        STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_RSA_RSASSA_PKCS1_v1_5_SHA1                                 STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_RSA_RSASSA_PKCS1_v1_5_SHA2_256                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_RSA_RSASSA_PSS_SHA1                                        STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_RSA_RSASSA_PSS_SHA2_256                                    STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_RSA_RSASSA_PSS_SHA2_384                                    STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_SECFAM_NOT_SET                                             STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_SECFAM_SHA1                                                STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_SECFAM_SHA2_256                                            STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_SECFAM_SHA2_384                                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_SECFAM_SHA2_512                                            STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_SM2                                                        STD_OFF

#define CRYPTO_30_LIBCV_DEFAULT_RANDOM_SOURCE                                                       STD_ON
#define CRYPTO_30_LIBCV_RANDOM_SOURCE_DRBG_AES                                                      STD_ON
#define CRYPTO_30_LIBCV_RANDOM_SOURCE_DRBG_HASH                                                     STD_OFF


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_LibCvPCDataSwitches  Crypto_30_LibCv Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CRYPTO_30_LIBCV_AEADCHACHAPOLY1305DECRYPT                                                   STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFAEADCHACHAPOLY1305DECRYPT                                        STD_ON
#define CRYPTO_30_LIBCV_AEADCHACHAPOLY1305ENCRYPT                                                   STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFAEADCHACHAPOLY1305ENCRYPT                                        STD_ON
#define CRYPTO_30_LIBCV_AESCCMDECRYPT                                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_AesCcmDecrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFAESCCMDECRYPT                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_AesCcmDecrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_AESCCMENCRYPT                                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_AesCcmEncrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFAESCCMENCRYPT                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_AesCcmEncrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_AESDECRYPT                                                                  STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFAESDECRYPT                                                       STD_ON
#define CRYPTO_30_LIBCV_AESENCRYPT                                                                  STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFAESENCRYPT                                                       STD_ON
#define CRYPTO_30_LIBCV_AESGCMDECRYPT                                                               STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFAESGCMDECRYPT                                                    STD_ON
#define CRYPTO_30_LIBCV_AESGCMENCRYPT                                                               STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFAESGCMENCRYPT                                                    STD_ON
#define CRYPTO_30_LIBCV_BUFFERLENGTH                                                                STD_ON
#define CRYPTO_30_LIBCV_CMACAESGENERATE                                                             STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFCMACAESGENERATE                                                  STD_ON
#define CRYPTO_30_LIBCV_CMACAESVERIFY                                                               STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFCMACAESVERIFY                                                    STD_ON
#define CRYPTO_30_LIBCV_DRBGAES                                                                     STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFDRBGAES                                                          STD_ON
#define CRYPTO_30_LIBCV_DRBGHASHSHA512                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_DRBGHashSha512' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFDRBGHASHSHA512                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_DRBGHashSha512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_DISPATCH_QUEUEPRIMITIVEINFOIDX                                              STD_ON
#define CRYPTO_30_LIBCV_DRIVEROBJECTSTATE                                                           STD_ON
#define CRYPTO_30_LIBCV_ECP160GENERATE                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP160Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFECP160GENERATE                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP160Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_ECP160VERIFY                                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP160Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFECP160VERIFY                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP160Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_ECP256GENERATE                                                              STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFECP256GENERATE                                                   STD_ON
#define CRYPTO_30_LIBCV_ECP256VERIFY                                                                STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFECP256VERIFY                                                     STD_ON
#define CRYPTO_30_LIBCV_ECP384GENERATE                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP384Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFECP384GENERATE                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP384Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_ECP384VERIFY                                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP384Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFECP384VERIFY                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP384Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_ECP521GENERATE                                                              STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFECP521GENERATE                                                   STD_ON
#define CRYPTO_30_LIBCV_ECP521VERIFY                                                                STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFECP521VERIFY                                                     STD_ON
#define CRYPTO_30_LIBCV_ECPKEYCHECK                                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcPKeyCheck' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFECPKEYCHECK                                                      STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcPKeyCheck.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_ED25519GENERATE                                                             STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFED25519GENERATE                                                  STD_ON
#define CRYPTO_30_LIBCV_ED25519VERIFY                                                               STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFED25519VERIFY                                                    STD_ON
#define CRYPTO_30_LIBCV_ED448GENERATE                                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_Ed448Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFED448GENERATE                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_Ed448Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_ED448VERIFY                                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_Ed448Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFED448VERIFY                                                      STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_Ed448Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_EDKEYCHECK                                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EdKeyCheck' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFEDKEYCHECK                                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EdKeyCheck.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_EXPECTEDCOMPATIBILITYVERSION                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_LIBCV_FAMILYTOHASHMAPPING                                                         STD_ON
#define CRYPTO_30_LIBCV_FINALMAGICNUMBER                                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_LIBCV_FIPS186                                                                     STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFFIPS186                                                          STD_ON
#define CRYPTO_30_LIBCV_GENERATORCOMPATIBILITYVERSION                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_LIBCV_GMACAESGENERATE                                                             STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFGMACAESGENERATE                                                  STD_ON
#define CRYPTO_30_LIBCV_GMACAESVERIFY                                                               STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFGMACAESVERIFY                                                    STD_ON
#define CRYPTO_30_LIBCV_HASH                                                                        STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFHASH                                                             STD_ON
#define CRYPTO_30_LIBCV_HMACRIPEMD160GENERATE                                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacRipeMd160Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFHMACRIPEMD160GENERATE                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacRipeMd160Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_HMACRIPEMD160VERIFY                                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacRipeMd160Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFHMACRIPEMD160VERIFY                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacRipeMd160Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_HMACSHA1GENERATE                                                            STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFHMACSHA1GENERATE                                                 STD_ON
#define CRYPTO_30_LIBCV_HMACSHA1VERIFY                                                              STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFHMACSHA1VERIFY                                                   STD_ON
#define CRYPTO_30_LIBCV_HMACSHA256GENERATE                                                          STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFHMACSHA256GENERATE                                               STD_ON
#define CRYPTO_30_LIBCV_HMACSHA256VERIFY                                                            STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFHMACSHA256VERIFY                                                 STD_ON
#define CRYPTO_30_LIBCV_HMACSHA384GENERATE                                                          STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFHMACSHA384GENERATE                                               STD_ON
#define CRYPTO_30_LIBCV_HMACSHA384VERIFY                                                            STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFHMACSHA384VERIFY                                                 STD_ON
#define CRYPTO_30_LIBCV_HMACSHA512GENERATE                                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacSha512Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFHMACSHA512GENERATE                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacSha512Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_HMACSHA512VERIFY                                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacSha512Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFHMACSHA512VERIFY                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacSha512Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_INITDATAHASHCODE                                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_LIBCV_INITVALUE                                                                   STD_ON
#define CRYPTO_30_LIBCV_KEY                                                                         STD_ON
#define CRYPTO_30_LIBCV_KEYELEMENTSENDIDXOFKEY                                                      STD_ON
#define CRYPTO_30_LIBCV_KEYELEMENTSSTARTIDXOFKEY                                                    STD_ON
#define CRYPTO_30_LIBCV_NVBLOCKIDXOFKEY                                                             STD_ON
#define CRYPTO_30_LIBCV_NVBLOCKUSEDOFKEY                                                            STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFEXPANDHMACSHA256                                               STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVEHKDFEXPANDHMACSHA256                                    STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFEXPANDHMACSHA384                                               STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVEHKDFEXPANDHMACSHA384                                    STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFHMACSHA256                                                     STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVEHKDFHMACSHA256                                          STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFHMACSHA384                                                     STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVEHKDFHMACSHA384                                          STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFHASHOPTION1SHA256                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveHKDFHashOption1SHA256' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVEHKDFHASHOPTION1SHA256                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveHKDFHashOption1SHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFHASHOPTION1SHA512                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveHKDFHashOption1SHA512' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVEHKDFHASHOPTION1SHA512                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveHKDFHashOption1SHA512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYDERIVEISO15118                                                           STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVEISO15118                                                STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEISO15118_20                                                        STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVEISO15118_20                                             STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEKDF2HMACSHA1                                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveKDF2HMACSHA1' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVEKDF2HMACSHA1                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveKDF2HMACSHA1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYDERIVEKDF2HMACSHA256                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveKDF2HMACSHA256' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVEKDF2HMACSHA256                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveKDF2HMACSHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYDERIVENIST800108CNT                                                      STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNist800108Cnt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVENIST800108CNT                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNist800108Cnt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYDERIVENIST80056AONEPASS                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNist80056AOnePass' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVENIST80056AONEPASS                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNist80056AOnePass.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYDERIVENISTFIPS186ERB                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNistFips186Erb' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVENISTFIPS186ERB                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNistFips186Erb.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYDERIVESPAKE2P                                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveSpake2P' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVESPAKE2P                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveSpake2P.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYDERIVEX963SHA256                                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveX963SHA256' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVEX963SHA256                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveX963SHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYDERIVEX963SHA512                                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveX963SHA512' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVEX963SHA512                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveX963SHA512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYELEMENTINFO                                                              STD_ON
#define CRYPTO_30_LIBCV_IDOFKEYELEMENTINFO                                                          STD_ON
#define CRYPTO_30_LIBCV_INITVALUEENDIDXOFKEYELEMENTINFO                                             STD_ON
#define CRYPTO_30_LIBCV_INITVALUESTARTIDXOFKEYELEMENTINFO                                           STD_ON
#define CRYPTO_30_LIBCV_INITVALUEUSEDOFKEYELEMENTINFO                                               STD_ON
#define CRYPTO_30_LIBCV_LENGTHOFKEYELEMENTINFO                                                      STD_ON
#define CRYPTO_30_LIBCV_MASKEDBITSOFKEYELEMENTINFO                                                  STD_ON
#define CRYPTO_30_LIBCV_ONCEOFKEYELEMENTINFO                                                        STD_ON
#define CRYPTO_30_LIBCV_PARTIALOFKEYELEMENTINFO                                                     STD_ON
#define CRYPTO_30_LIBCV_PERSISTOFKEYELEMENTINFO                                                     STD_ON
#define CRYPTO_30_LIBCV_READOFKEYELEMENTINFO                                                        STD_ON
#define CRYPTO_30_LIBCV_WRITEOFKEYELEMENTINFO                                                       STD_ON
#define CRYPTO_30_LIBCV_KEYELEMENTS                                                                 STD_ON
#define CRYPTO_30_LIBCV_IDOFKEYELEMENTS                                                             STD_ON
#define CRYPTO_30_LIBCV_KEYELEMENTINFOIDXOFKEYELEMENTS                                              STD_ON
#define CRYPTO_30_LIBCV_KEYSTORAGEENDIDXOFKEYELEMENTS                                               STD_ON
#define CRYPTO_30_LIBCV_KEYSTORAGEEXTENSIONIDXOFKEYELEMENTS                                         STD_ON
#define CRYPTO_30_LIBCV_KEYSTORAGESTARTIDXOFKEYELEMENTS                                             STD_ON
#define CRYPTO_30_LIBCV_KEYSTORAGEVALIDIDXOFKEYELEMENTS                                             STD_ON
#define CRYPTO_30_LIBCV_KEYSTORAGEWRITTENLENGTHENDIDXOFKEYELEMENTS                                  STD_ON
#define CRYPTO_30_LIBCV_KEYSTORAGEWRITTENLENGTHSTARTIDXOFKEYELEMENTS                                STD_ON
#define CRYPTO_30_LIBCV_KEYGENED25519                                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenEd25519' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYGENED25519                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenEd25519.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYGENP256R1                                                                STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYGENP256R1                                                     STD_ON
#define CRYPTO_30_LIBCV_KEYGENP384R1                                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenP384R1' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYGENP384R1                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenP384R1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYGENP521R1                                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenP521R1' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYGENP521R1                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenP521R1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYGENSM2P256V1                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenSm2P256V1' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYGENSM2P256V1                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenSm2P256V1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYGENSYMGENERIC                                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenSymGeneric' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYGENSYMGENERIC                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenSymGeneric.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYLOCK                                                                     STD_ON
#define CRYPTO_30_LIBCV_KEYNVSTATUS                                                                 STD_ON
#define CRYPTO_30_LIBCV_KEYP224R1BDPUBVAL                                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP224R1BDPubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYP224R1BDPUBVAL                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP224R1BDPubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYP224R1BDSECRET                                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP224R1BDSecret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYP224R1BDSECRET                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP224R1BDSecret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYP256R1BDPUBVAL                                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1BDPubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYP256R1BDPUBVAL                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1BDPubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYP256R1BDSECRET                                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1BDSecret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYP256R1BDSECRET                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1BDSecret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYP256R1PUBVAL                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1PubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYP256R1PUBVAL                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYP256R1SECRET                                                             STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYP256R1SECRET                                                  STD_ON
#define CRYPTO_30_LIBCV_KEYP384R1PUBVAL                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP384R1PubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYP384R1PUBVAL                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP384R1PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYP384R1SECRET                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP384R1Secret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYP384R1SECRET                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP384R1Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYP521R1PUBVAL                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP521R1PubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYP521R1PUBVAL                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP521R1PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYP521R1SECRET                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP521R1Secret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYP521R1SECRET                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP521R1Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYSEEDDRBGAES                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySeedDRBGAES' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYSEEDDRBGAES                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySeedDRBGAES.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYSEEDDRBGHASHSHA512                                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySeedDRBGHashSha512' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYSEEDDRBGHASHSHA512                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySeedDRBGHashSha512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYSEEDFIPS186                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySeedFips186' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYSEEDFIPS186                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySeedFips186.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYSETINVALIDJOB                                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySetInvalidJob' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYSETINVALIDJOB                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySetInvalidJob.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYSETVALIDJOB                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySetValidJob' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYSETVALIDJOB                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySetValidJob.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYSPAKE2PPUBVAL                                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySpake2PPubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYSPAKE2PPUBVAL                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySpake2PPubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYSPAKE2PSECRET                                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySpake2PSecret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYSPAKE2PSECRET                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySpake2PSecret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYSTORAGE                                                                  STD_ON
#define CRYPTO_30_LIBCV_KEYX25519PUBVAL                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyX25519PubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYX25519PUBVAL                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyX25519PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYX25519SECRET                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyX25519Secret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYX25519SECRET                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyX25519Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYX448PUBVAL                                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyX448PubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYX448PUBVAL                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyX448PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYX448SECRET                                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyX448Secret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYX448SECRET                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyX448Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_LASTJOB                                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_LastJob' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define CRYPTO_30_LIBCV_FAMILYOFLASTJOB                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Family' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define CRYPTO_30_LIBCV_KEYIDOFLASTJOB                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_LastJob.KeyId' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define CRYPTO_30_LIBCV_MODEOFLASTJOB                                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Mode' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define CRYPTO_30_LIBCV_LOCK                                                                        STD_ON
#define CRYPTO_30_LIBCV_LONGTERMWS                                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_LongTermWs' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_LONGTERMWSLOCK                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_LongTermWsLock' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_MD5                                                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_MD5' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFMD5                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_MD5.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_MAINFUNCTIONPERIODOFGENERAL                                                 STD_ON
#define CRYPTO_30_LIBCV_NVBLOCK                                                                     STD_ON
#define CRYPTO_30_LIBCV_CONSISTENCYLEVELOFNVBLOCK                                                   STD_ON
#define CRYPTO_30_LIBCV_CRCOFNVBLOCK                                                                STD_ON
#define CRYPTO_30_LIBCV_DESCRIPTOROFNVBLOCK                                                         STD_ON
#define CRYPTO_30_LIBCV_IDOFNVBLOCK                                                                 STD_ON
#define CRYPTO_30_LIBCV_KEYSTORAGEENDIDXOFNVBLOCK                                                   STD_ON
#define CRYPTO_30_LIBCV_KEYSTORAGESTARTIDXOFNVBLOCK                                                 STD_ON
#define CRYPTO_30_LIBCV_LENGTHOFNVBLOCK                                                             STD_ON
#define CRYPTO_30_LIBCV_PROCESSINGOFNVBLOCK                                                         STD_ON
#define CRYPTO_30_LIBCV_OBJECTINFO                                                                  STD_ON
#define CRYPTO_30_LIBCV_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO                                    STD_ON
#define CRYPTO_30_LIBCV_AEADCHACHAPOLY1305DECRYPTUSEDOFOBJECTINFO                                   STD_ON
#define CRYPTO_30_LIBCV_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO                                    STD_ON
#define CRYPTO_30_LIBCV_AEADCHACHAPOLY1305ENCRYPTUSEDOFOBJECTINFO                                   STD_ON
#define CRYPTO_30_LIBCV_AESCCMDECRYPTIDXOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmDecryptIdx' Reason: 'the optional indirection is deactivated because AesCcmDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_AESCCMDECRYPTUSEDOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmDecryptUsed' Reason: 'the optional indirection is deactivated because AesCcmDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_AESCCMENCRYPTIDXOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmEncryptIdx' Reason: 'the optional indirection is deactivated because AesCcmEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_AESCCMENCRYPTUSEDOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmEncryptUsed' Reason: 'the optional indirection is deactivated because AesCcmEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_AESDECRYPTIDXOFOBJECTINFO                                                   STD_ON
#define CRYPTO_30_LIBCV_AESDECRYPTUSEDOFOBJECTINFO                                                  STD_ON
#define CRYPTO_30_LIBCV_AESENCRYPTIDXOFOBJECTINFO                                                   STD_ON
#define CRYPTO_30_LIBCV_AESENCRYPTUSEDOFOBJECTINFO                                                  STD_ON
#define CRYPTO_30_LIBCV_AESGCMDECRYPTIDXOFOBJECTINFO                                                STD_ON
#define CRYPTO_30_LIBCV_AESGCMDECRYPTUSEDOFOBJECTINFO                                               STD_ON
#define CRYPTO_30_LIBCV_AESGCMENCRYPTIDXOFOBJECTINFO                                                STD_ON
#define CRYPTO_30_LIBCV_AESGCMENCRYPTUSEDOFOBJECTINFO                                               STD_ON
#define CRYPTO_30_LIBCV_APPLICATIONIDOFOBJECTINFO                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.ApplicationId' Reason: 'Deactivated for use case Single Partition' */
#define CRYPTO_30_LIBCV_CMACAESGENERATEIDXOFOBJECTINFO                                              STD_ON
#define CRYPTO_30_LIBCV_CMACAESGENERATEUSEDOFOBJECTINFO                                             STD_ON
#define CRYPTO_30_LIBCV_CMACAESVERIFYIDXOFOBJECTINFO                                                STD_ON
#define CRYPTO_30_LIBCV_CMACAESVERIFYUSEDOFOBJECTINFO                                               STD_ON
#define CRYPTO_30_LIBCV_DRBGAESIDXOFOBJECTINFO                                                      STD_ON
#define CRYPTO_30_LIBCV_DRBGAESUSEDOFOBJECTINFO                                                     STD_ON
#define CRYPTO_30_LIBCV_DRBGHASHSHA512IDXOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.DRBGHashSha512Idx' Reason: 'the optional indirection is deactivated because DRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_DRBGHASHSHA512USEDOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.DRBGHashSha512Used' Reason: 'the optional indirection is deactivated because DRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP160GENERATEIDXOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160GenerateIdx' Reason: 'the optional indirection is deactivated because EcP160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP160GENERATEUSEDOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160GenerateUsed' Reason: 'the optional indirection is deactivated because EcP160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP160VERIFYIDXOFOBJECTINFO                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160VerifyIdx' Reason: 'the optional indirection is deactivated because EcP160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP160VERIFYUSEDOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160VerifyUsed' Reason: 'the optional indirection is deactivated because EcP160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP256GENERATEIDXOFOBJECTINFO                                               STD_ON
#define CRYPTO_30_LIBCV_ECP256GENERATEUSEDOFOBJECTINFO                                              STD_ON
#define CRYPTO_30_LIBCV_ECP256VERIFYIDXOFOBJECTINFO                                                 STD_ON
#define CRYPTO_30_LIBCV_ECP256VERIFYUSEDOFOBJECTINFO                                                STD_ON
#define CRYPTO_30_LIBCV_ECP384GENERATEIDXOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384GenerateIdx' Reason: 'the optional indirection is deactivated because EcP384GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP384GENERATEUSEDOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384GenerateUsed' Reason: 'the optional indirection is deactivated because EcP384GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP384VERIFYIDXOFOBJECTINFO                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384VerifyIdx' Reason: 'the optional indirection is deactivated because EcP384VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP384VERIFYUSEDOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384VerifyUsed' Reason: 'the optional indirection is deactivated because EcP384VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP521GENERATEIDXOFOBJECTINFO                                               STD_ON
#define CRYPTO_30_LIBCV_ECP521GENERATEUSEDOFOBJECTINFO                                              STD_ON
#define CRYPTO_30_LIBCV_ECP521VERIFYIDXOFOBJECTINFO                                                 STD_ON
#define CRYPTO_30_LIBCV_ECP521VERIFYUSEDOFOBJECTINFO                                                STD_ON
#define CRYPTO_30_LIBCV_ECPKEYCHECKIDXOFOBJECTINFO                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcPKeyCheckIdx' Reason: 'the optional indirection is deactivated because EcPKeyCheckUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECPKEYCHECKUSEDOFOBJECTINFO                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcPKeyCheckUsed' Reason: 'the optional indirection is deactivated because EcPKeyCheckUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ED25519GENERATEIDXOFOBJECTINFO                                              STD_ON
#define CRYPTO_30_LIBCV_ED25519GENERATEUSEDOFOBJECTINFO                                             STD_ON
#define CRYPTO_30_LIBCV_ED25519VERIFYIDXOFOBJECTINFO                                                STD_ON
#define CRYPTO_30_LIBCV_ED25519VERIFYUSEDOFOBJECTINFO                                               STD_ON
#define CRYPTO_30_LIBCV_ED448GENERATEIDXOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Ed448GenerateIdx' Reason: 'the optional indirection is deactivated because Ed448GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ED448GENERATEUSEDOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Ed448GenerateUsed' Reason: 'the optional indirection is deactivated because Ed448GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ED448VERIFYIDXOFOBJECTINFO                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Ed448VerifyIdx' Reason: 'the optional indirection is deactivated because Ed448VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ED448VERIFYUSEDOFOBJECTINFO                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Ed448VerifyUsed' Reason: 'the optional indirection is deactivated because Ed448VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_EDKEYCHECKIDXOFOBJECTINFO                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EdKeyCheckIdx' Reason: 'the optional indirection is deactivated because EdKeyCheckUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_EDKEYCHECKUSEDOFOBJECTINFO                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EdKeyCheckUsed' Reason: 'the optional indirection is deactivated because EdKeyCheckUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_FIPS186IDXOFOBJECTINFO                                                      STD_ON
#define CRYPTO_30_LIBCV_FIPS186USEDOFOBJECTINFO                                                     STD_ON
#define CRYPTO_30_LIBCV_GMACAESGENERATEIDXOFOBJECTINFO                                              STD_ON
#define CRYPTO_30_LIBCV_GMACAESGENERATEUSEDOFOBJECTINFO                                             STD_ON
#define CRYPTO_30_LIBCV_GMACAESVERIFYIDXOFOBJECTINFO                                                STD_ON
#define CRYPTO_30_LIBCV_GMACAESVERIFYUSEDOFOBJECTINFO                                               STD_ON
#define CRYPTO_30_LIBCV_HASHIDXOFOBJECTINFO                                                         STD_ON
#define CRYPTO_30_LIBCV_HASHUSEDOFOBJECTINFO                                                        STD_ON
#define CRYPTO_30_LIBCV_HMACRIPEMD160GENERATEIDXOFOBJECTINFO                                        STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160GenerateIdx' Reason: 'the optional indirection is deactivated because HmacRipeMd160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACRIPEMD160GENERATEUSEDOFOBJECTINFO                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160GenerateUsed' Reason: 'the optional indirection is deactivated because HmacRipeMd160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACRIPEMD160VERIFYIDXOFOBJECTINFO                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160VerifyIdx' Reason: 'the optional indirection is deactivated because HmacRipeMd160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACRIPEMD160VERIFYUSEDOFOBJECTINFO                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160VerifyUsed' Reason: 'the optional indirection is deactivated because HmacRipeMd160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACSHA1GENERATEIDXOFOBJECTINFO                                             STD_ON
#define CRYPTO_30_LIBCV_HMACSHA1GENERATEUSEDOFOBJECTINFO                                            STD_ON
#define CRYPTO_30_LIBCV_HMACSHA1VERIFYIDXOFOBJECTINFO                                               STD_ON
#define CRYPTO_30_LIBCV_HMACSHA1VERIFYUSEDOFOBJECTINFO                                              STD_ON
#define CRYPTO_30_LIBCV_HMACSHA256GENERATEIDXOFOBJECTINFO                                           STD_ON
#define CRYPTO_30_LIBCV_HMACSHA256GENERATEUSEDOFOBJECTINFO                                          STD_ON
#define CRYPTO_30_LIBCV_HMACSHA256VERIFYIDXOFOBJECTINFO                                             STD_ON
#define CRYPTO_30_LIBCV_HMACSHA256VERIFYUSEDOFOBJECTINFO                                            STD_ON
#define CRYPTO_30_LIBCV_HMACSHA384GENERATEIDXOFOBJECTINFO                                           STD_ON
#define CRYPTO_30_LIBCV_HMACSHA384GENERATEUSEDOFOBJECTINFO                                          STD_ON
#define CRYPTO_30_LIBCV_HMACSHA384VERIFYIDXOFOBJECTINFO                                             STD_ON
#define CRYPTO_30_LIBCV_HMACSHA384VERIFYUSEDOFOBJECTINFO                                            STD_ON
#define CRYPTO_30_LIBCV_HMACSHA512GENERATEIDXOFOBJECTINFO                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha512GenerateIdx' Reason: 'the optional indirection is deactivated because HmacSha512GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACSHA512GENERATEUSEDOFOBJECTINFO                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha512GenerateUsed' Reason: 'the optional indirection is deactivated because HmacSha512GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACSHA512VERIFYIDXOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha512VerifyIdx' Reason: 'the optional indirection is deactivated because HmacSha512VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACSHA512VERIFYUSEDOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha512VerifyUsed' Reason: 'the optional indirection is deactivated because HmacSha512VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFEXPANDHMACSHA256IDXOFOBJECTINFO                                STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFEXPANDHMACSHA256USEDOFOBJECTINFO                               STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFEXPANDHMACSHA384IDXOFOBJECTINFO                                STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFEXPANDHMACSHA384USEDOFOBJECTINFO                               STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFHMACSHA256IDXOFOBJECTINFO                                      STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFHMACSHA256USEDOFOBJECTINFO                                     STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFHMACSHA384IDXOFOBJECTINFO                                      STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFHMACSHA384USEDOFOBJECTINFO                                     STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFHASHOPTION1SHA256IDXOFOBJECTINFO                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHashOption1SHA256Idx' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHashOption1SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFHASHOPTION1SHA256USEDOFOBJECTINFO                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHashOption1SHA256Used' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHashOption1SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFHASHOPTION1SHA512IDXOFOBJECTINFO                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHashOption1SHA512Idx' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHashOption1SHA512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFHASHOPTION1SHA512USEDOFOBJECTINFO                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHashOption1SHA512Used' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHashOption1SHA512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEISO15118IDXOFOBJECTINFO                                            STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEISO15118USEDOFOBJECTINFO                                           STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEISO15118_20IDXOFOBJECTINFO                                         STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEISO15118_20USEDOFOBJECTINFO                                        STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEKDF2HMACSHA1IDXOFOBJECTINFO                                        STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA1Idx' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEKDF2HMACSHA1USEDOFOBJECTINFO                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA1Used' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEKDF2HMACSHA256IDXOFOBJECTINFO                                      STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA256Idx' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEKDF2HMACSHA256USEDOFOBJECTINFO                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA256Used' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVENIST800108CNTIDXOFOBJECTINFO                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist800108CntIdx' Reason: 'the optional indirection is deactivated because KeyDeriveNist800108CntUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVENIST800108CNTUSEDOFOBJECTINFO                                      STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist800108CntUsed' Reason: 'the optional indirection is deactivated because KeyDeriveNist800108CntUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVENIST80056AONEPASSIDXOFOBJECTINFO                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist80056AOnePassIdx' Reason: 'the optional indirection is deactivated because KeyDeriveNist80056AOnePassUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVENIST80056AONEPASSUSEDOFOBJECTINFO                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist80056AOnePassUsed' Reason: 'the optional indirection is deactivated because KeyDeriveNist80056AOnePassUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVENISTFIPS186ERBIDXOFOBJECTINFO                                      STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNistFips186ErbIdx' Reason: 'the optional indirection is deactivated because KeyDeriveNistFips186ErbUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVENISTFIPS186ERBUSEDOFOBJECTINFO                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNistFips186ErbUsed' Reason: 'the optional indirection is deactivated because KeyDeriveNistFips186ErbUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVESPAKE2PIDXOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveSpake2PIdx' Reason: 'the optional indirection is deactivated because KeyDeriveSpake2PUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVESPAKE2PUSEDOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveSpake2PUsed' Reason: 'the optional indirection is deactivated because KeyDeriveSpake2PUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEX963SHA256IDXOFOBJECTINFO                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA256Idx' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEX963SHA256USEDOFOBJECTINFO                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA256Used' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEX963SHA512IDXOFOBJECTINFO                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA512Idx' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEX963SHA512USEDOFOBJECTINFO                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA512Used' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYGENED25519IDXOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenEd25519Idx' Reason: 'the optional indirection is deactivated because KeyGenEd25519UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYGENED25519USEDOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenEd25519Used' Reason: 'the optional indirection is deactivated because KeyGenEd25519UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYGENP256R1IDXOFOBJECTINFO                                                 STD_ON
#define CRYPTO_30_LIBCV_KEYGENP256R1USEDOFOBJECTINFO                                                STD_ON
#define CRYPTO_30_LIBCV_KEYGENP384R1IDXOFOBJECTINFO                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP384R1Idx' Reason: 'the optional indirection is deactivated because KeyGenP384R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYGENP384R1USEDOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP384R1Used' Reason: 'the optional indirection is deactivated because KeyGenP384R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYGENP521R1IDXOFOBJECTINFO                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP521R1Idx' Reason: 'the optional indirection is deactivated because KeyGenP521R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYGENP521R1USEDOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP521R1Used' Reason: 'the optional indirection is deactivated because KeyGenP521R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYGENSM2P256V1IDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenSm2P256V1Idx' Reason: 'the optional indirection is deactivated because KeyGenSm2P256V1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYGENSM2P256V1USEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenSm2P256V1Used' Reason: 'the optional indirection is deactivated because KeyGenSm2P256V1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYGENSYMGENERICIDXOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenSymGenericIdx' Reason: 'the optional indirection is deactivated because KeyGenSymGenericUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYGENSYMGENERICUSEDOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenSymGenericUsed' Reason: 'the optional indirection is deactivated because KeyGenSymGenericUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP224R1BDPUBVALIDXOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDPubValIdx' Reason: 'the optional indirection is deactivated because KeyP224R1BDPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP224R1BDPUBVALUSEDOFOBJECTINFO                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDPubValUsed' Reason: 'the optional indirection is deactivated because KeyP224R1BDPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP224R1BDSECRETIDXOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDSecretIdx' Reason: 'the optional indirection is deactivated because KeyP224R1BDSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP224R1BDSECRETUSEDOFOBJECTINFO                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDSecretUsed' Reason: 'the optional indirection is deactivated because KeyP224R1BDSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP256R1BDPUBVALIDXOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1BDPubValIdx' Reason: 'the optional indirection is deactivated because KeyP256R1BDPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP256R1BDPUBVALUSEDOFOBJECTINFO                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1BDPubValUsed' Reason: 'the optional indirection is deactivated because KeyP256R1BDPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP256R1BDSECRETIDXOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1BDSecretIdx' Reason: 'the optional indirection is deactivated because KeyP256R1BDSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP256R1BDSECRETUSEDOFOBJECTINFO                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1BDSecretUsed' Reason: 'the optional indirection is deactivated because KeyP256R1BDSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP256R1PUBVALIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1PubValIdx' Reason: 'the optional indirection is deactivated because KeyP256R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP256R1PUBVALUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1PubValUsed' Reason: 'the optional indirection is deactivated because KeyP256R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP256R1SECRETIDXOFOBJECTINFO                                              STD_ON
#define CRYPTO_30_LIBCV_KEYP256R1SECRETUSEDOFOBJECTINFO                                             STD_ON
#define CRYPTO_30_LIBCV_KEYP384R1PUBVALIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1PubValIdx' Reason: 'the optional indirection is deactivated because KeyP384R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP384R1PUBVALUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1PubValUsed' Reason: 'the optional indirection is deactivated because KeyP384R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP384R1SECRETIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1SecretIdx' Reason: 'the optional indirection is deactivated because KeyP384R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP384R1SECRETUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1SecretUsed' Reason: 'the optional indirection is deactivated because KeyP384R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP521R1PUBVALIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1PubValIdx' Reason: 'the optional indirection is deactivated because KeyP521R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP521R1PUBVALUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1PubValUsed' Reason: 'the optional indirection is deactivated because KeyP521R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP521R1SECRETIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1SecretIdx' Reason: 'the optional indirection is deactivated because KeyP521R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP521R1SECRETUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1SecretUsed' Reason: 'the optional indirection is deactivated because KeyP521R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSEEDDRBGAESIDXOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGAESIdx' Reason: 'the optional indirection is deactivated because KeySeedDRBGAESUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSEEDDRBGAESUSEDOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGAESUsed' Reason: 'the optional indirection is deactivated because KeySeedDRBGAESUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSEEDDRBGHASHSHA512IDXOFOBJECTINFO                                        STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGHashSha512Idx' Reason: 'the optional indirection is deactivated because KeySeedDRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSEEDDRBGHASHSHA512USEDOFOBJECTINFO                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGHashSha512Used' Reason: 'the optional indirection is deactivated because KeySeedDRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSEEDFIPS186IDXOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedFips186Idx' Reason: 'the optional indirection is deactivated because KeySeedFips186UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSEEDFIPS186USEDOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedFips186Used' Reason: 'the optional indirection is deactivated because KeySeedFips186UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSETINVALIDJOBIDXOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySetInvalidJobIdx' Reason: 'the optional indirection is deactivated because KeySetInvalidJobUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSETINVALIDJOBUSEDOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySetInvalidJobUsed' Reason: 'the optional indirection is deactivated because KeySetInvalidJobUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSETVALIDJOBIDXOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySetValidJobIdx' Reason: 'the optional indirection is deactivated because KeySetValidJobUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSETVALIDJOBUSEDOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySetValidJobUsed' Reason: 'the optional indirection is deactivated because KeySetValidJobUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSPAKE2PPUBVALIDXOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PPubValIdx' Reason: 'the optional indirection is deactivated because KeySpake2PPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSPAKE2PPUBVALUSEDOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PPubValUsed' Reason: 'the optional indirection is deactivated because KeySpake2PPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSPAKE2PSECRETIDXOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PSecretIdx' Reason: 'the optional indirection is deactivated because KeySpake2PSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSPAKE2PSECRETUSEDOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PSecretUsed' Reason: 'the optional indirection is deactivated because KeySpake2PSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYX25519PUBVALIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519PubValIdx' Reason: 'the optional indirection is deactivated because KeyX25519PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYX25519PUBVALUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519PubValUsed' Reason: 'the optional indirection is deactivated because KeyX25519PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYX25519SECRETIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519SecretIdx' Reason: 'the optional indirection is deactivated because KeyX25519SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYX25519SECRETUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519SecretUsed' Reason: 'the optional indirection is deactivated because KeyX25519SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYX448PUBVALIDXOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX448PubValIdx' Reason: 'the optional indirection is deactivated because KeyX448PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYX448PUBVALUSEDOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX448PubValUsed' Reason: 'the optional indirection is deactivated because KeyX448PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYX448SECRETIDXOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX448SecretIdx' Reason: 'the optional indirection is deactivated because KeyX448SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYX448SECRETUSEDOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX448SecretUsed' Reason: 'the optional indirection is deactivated because KeyX448SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_MD5IDXOFOBJECTINFO                                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.MD5Idx' Reason: 'the optional indirection is deactivated because MD5UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_MD5USEDOFOBJECTINFO                                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.MD5Used' Reason: 'the optional indirection is deactivated because MD5UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_PARTITIONIDXOFOBJECTINFO                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.PartitionIdx' Reason: 'Deactivated for use case Single Partition' */
#define CRYPTO_30_LIBCV_QUEUEIDXOFOBJECTINFO                                                        STD_ON
#define CRYPTO_30_LIBCV_RANDOMSEEDBUFFERENDIDXOFOBJECTINFO                                          STD_ON
#define CRYPTO_30_LIBCV_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO                                        STD_ON
#define CRYPTO_30_LIBCV_RANDOMSEEDBUFFERUSEDOFOBJECTINFO                                            STD_ON
#define CRYPTO_30_LIBCV_RSAOAEPCRTSHA1DECRYPTIDXOFOBJECTINFO                                        STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha1DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPCRTSHA1DECRYPTUSEDOFOBJECTINFO                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha1DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPCRTSHA256DECRYPTIDXOFOBJECTINFO                                      STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha256DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPCRTSHA256DECRYPTUSEDOFOBJECTINFO                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha256DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA1DECRYPTIDXOFOBJECTINFO                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA1DECRYPTUSEDOFOBJECTINFO                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA1ENCRYPTIDXOFOBJECTINFO                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1EncryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA1ENCRYPTUSEDOFOBJECTINFO                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1EncryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA256DECRYPTIDXOFOBJECTINFO                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA256DECRYPTUSEDOFOBJECTINFO                                        STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA256ENCRYPTIDXOFOBJECTINFO                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256EncryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha256EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA256ENCRYPTUSEDOFOBJECTINFO                                        STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256EncryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha256EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPKCS1CRTGENERATEIDXOFOBJECTINFO                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1CrtGenerateIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1CrtGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPKCS1CRTGENERATEUSEDOFOBJECTINFO                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1CrtGenerateUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1CrtGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPKCS1DECRYPTIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1DecryptIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPKCS1DECRYPTUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1DecryptUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPKCS1ENCRYPTIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1EncryptIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPKCS1ENCRYPTUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1EncryptUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPKCS1GENERATEIDXOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1GenerateIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPKCS1GENERATEUSEDOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1GenerateUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPKCS1VERIFYIDXOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1VerifyIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPKCS1VERIFYUSEDOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1VerifyUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPSSGENERATEIDXOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssGenerateIdx' Reason: 'the optional indirection is deactivated because RsaPssGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPSSGENERATEUSEDOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssGenerateUsed' Reason: 'the optional indirection is deactivated because RsaPssGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPSSVERIFYIDXOFOBJECTINFO                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssVerifyIdx' Reason: 'the optional indirection is deactivated because RsaPssVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPSSVERIFYUSEDOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssVerifyUsed' Reason: 'the optional indirection is deactivated because RsaPssVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SHECMDGETIDIDXOFOBJECTINFO                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SheCmdGetIdIdx' Reason: 'the optional indirection is deactivated because SheCmdGetIdUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SHECMDGETIDUSEDOFOBJECTINFO                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SheCmdGetIdUsed' Reason: 'the optional indirection is deactivated because SheCmdGetIdUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SIPHASHGENERATEIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashGenerateIdx' Reason: 'the optional indirection is deactivated because SipHashGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SIPHASHGENERATEUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashGenerateUsed' Reason: 'the optional indirection is deactivated because SipHashGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SIPHASHVERIFYIDXOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashVerifyIdx' Reason: 'the optional indirection is deactivated because SipHashVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SIPHASHVERIFYUSEDOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashVerifyUsed' Reason: 'the optional indirection is deactivated because SipHashVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SLHDSAVERIFYIDXOFOBJECTINFO                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SlhDsaVerifyIdx' Reason: 'the optional indirection is deactivated because SlhDsaVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SLHDSAVERIFYUSEDOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SlhDsaVerifyUsed' Reason: 'the optional indirection is deactivated because SlhDsaVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SM2GENERATEIDXOFOBJECTINFO                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm2GenerateIdx' Reason: 'the optional indirection is deactivated because Sm2GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SM2GENERATEUSEDOFOBJECTINFO                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm2GenerateUsed' Reason: 'the optional indirection is deactivated because Sm2GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SM2VERIFYIDXOFOBJECTINFO                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm2VerifyIdx' Reason: 'the optional indirection is deactivated because Sm2VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SM2VERIFYUSEDOFOBJECTINFO                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm2VerifyUsed' Reason: 'the optional indirection is deactivated because Sm2VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SM4DECRYPTIDXOFOBJECTINFO                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm4DecryptIdx' Reason: 'the optional indirection is deactivated because Sm4DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SM4DECRYPTUSEDOFOBJECTINFO                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm4DecryptUsed' Reason: 'the optional indirection is deactivated because Sm4DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SM4ENCRYPTIDXOFOBJECTINFO                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm4EncryptIdx' Reason: 'the optional indirection is deactivated because Sm4EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SM4ENCRYPTUSEDOFOBJECTINFO                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm4EncryptUsed' Reason: 'the optional indirection is deactivated because Sm4EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_WORKSPACEADDROFOBJECTINFO                                                   STD_ON
#define CRYPTO_30_LIBCV_WORKSPACELENGTHOFOBJECTINFO                                                 STD_ON
#define CRYPTO_30_LIBCV_OBJECTINFOIND                                                               STD_ON
#define CRYPTO_30_LIBCV_PARTITIONIDENTIFIERS                                                        STD_ON
#define CRYPTO_30_LIBCV_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                  STD_ON
#define CRYPTO_30_LIBCV_PARTITIONSNVOFPARTITIONIDENTIFIERS                                          STD_ON
#define CRYPTO_30_LIBCV_PARTITIONINFO                                                               STD_ON
#define CRYPTO_30_LIBCV_AESOFPARTITIONINFO                                                          STD_ON
#define CRYPTO_30_LIBCV_DEFAULTRANDOMKEYOFPARTITIONINFO                                             STD_ON
#define CRYPTO_30_LIBCV_HASHOFPARTITIONINFO                                                         STD_ON
#define CRYPTO_30_LIBCV_MASKEDBITSOFPARTITIONINFO                                                   STD_ON
#define CRYPTO_30_LIBCV_PARTITIONINITIALIZED                                                        STD_ON
#define CRYPTO_30_LIBCV_PRIMITIVEFCT                                                                STD_ON
#define CRYPTO_30_LIBCV_DISPATCHOFPRIMITIVEFCT                                                      STD_ON
#define CRYPTO_30_LIBCV_OBJECTINFOINDENDIDXOFPRIMITIVEFCT                                           STD_ON
#define CRYPTO_30_LIBCV_OBJECTINFOINDSTARTIDXOFPRIMITIVEFCT                                         STD_ON
#define CRYPTO_30_LIBCV_OBJECTINFOINDUSEDOFPRIMITIVEFCT                                             STD_ON
#define CRYPTO_30_LIBCV_PRIMITIVEINFO                                                               STD_ON
#define CRYPTO_30_LIBCV_COMBINEDOFPRIMITIVEINFO                                                     STD_ON
#define CRYPTO_30_LIBCV_CONTEXTOFPRIMITIVEINFO                                                      STD_ON
#define CRYPTO_30_LIBCV_DEFAULTRANDOMSOURCEOFPRIMITIVEINFO                                          STD_ON
#define CRYPTO_30_LIBCV_MASKEDBITSOFPRIMITIVEINFO                                                   STD_ON
#define CRYPTO_30_LIBCV_PRIMITIVEFCTIDXOFPRIMITIVEINFO                                              STD_ON
#define CRYPTO_30_LIBCV_PRIMITIVESERVICEINFO                                                        STD_ON
#define CRYPTO_30_LIBCV_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO                                   STD_ON
#define CRYPTO_30_LIBCV_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO                                 STD_ON
#define CRYPTO_30_LIBCV_PRIMITIVEINFOUSEDOFPRIMITIVESERVICEINFO                                     STD_ON
#define CRYPTO_30_LIBCV_PROCESSJOB_TRIGGER_WRITE                                                    STD_ON
#define CRYPTO_30_LIBCV_QUEUE                                                                       STD_ON
#define CRYPTO_30_LIBCV_RANDOMSEEDBUFFER                                                            STD_ON
#define CRYPTO_30_LIBCV_RANDOMSOURCEGENERATECOUNT                                                   STD_ON
#define CRYPTO_30_LIBCV_REDIRECT_BUFFER                                                             STD_ON
#define CRYPTO_30_LIBCV_RSAOAEPCRTSHA1DECRYPT                                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepCrtSha1Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAOAEPCRTSHA1DECRYPT                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepCrtSha1Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAOAEPCRTSHA256DECRYPT                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepCrtSha256Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAOAEPCRTSHA256DECRYPT                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepCrtSha256Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA1DECRYPT                                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha1Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAOAEPSHA1DECRYPT                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha1Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA1ENCRYPT                                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha1Encrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAOAEPSHA1ENCRYPT                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha1Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA256DECRYPT                                                        STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha256Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAOAEPSHA256DECRYPT                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha256Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA256ENCRYPT                                                        STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha256Encrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAOAEPSHA256ENCRYPT                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha256Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAPKCS1CRTGENERATE                                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1CrtGenerate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAPKCS1CRTGENERATE                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1CrtGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAPKCS1DECRYPT                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAPKCS1DECRYPT                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAPKCS1ENCRYPT                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Encrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAPKCS1ENCRYPT                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAPKCS1GENERATE                                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAPKCS1GENERATE                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAPKCS1VERIFY                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAPKCS1VERIFY                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAPSSGENERATE                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPssGenerate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAPSSGENERATE                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPssGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAPSSVERIFY                                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPssVerify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAPSSVERIFY                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPssVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_SAVEANDRESTOREWORKSPACE                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SaveAndRestoreWorkspace' Reason: 'Disable Feature if no Context primitive is used' */
#define CRYPTO_30_LIBCV_LENGTHOFSAVEANDRESTOREWORKSPACE                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SaveAndRestoreWorkspace.Length' Reason: 'Disable Feature if no Context primitive is used' */
#define CRYPTO_30_LIBCV_SHECMDGETID                                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SheCmdGetId' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFSHECMDGETID                                                      STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SheCmdGetId.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_SHEKEYS                                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SheKeys' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_SIPHASHGENERATE                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SipHashGenerate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFSIPHASHGENERATE                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SipHashGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_SIPHASHVERIFY                                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SipHashVerify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFSIPHASHVERIFY                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SipHashVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_SIZEOFAEADCHACHAPOLY1305DECRYPT                                             STD_ON
#define CRYPTO_30_LIBCV_SIZEOFAEADCHACHAPOLY1305ENCRYPT                                             STD_ON
#define CRYPTO_30_LIBCV_SIZEOFAESDECRYPT                                                            STD_ON
#define CRYPTO_30_LIBCV_SIZEOFAESENCRYPT                                                            STD_ON
#define CRYPTO_30_LIBCV_SIZEOFAESGCMDECRYPT                                                         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFAESGCMENCRYPT                                                         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFBUFFERLENGTH                                                          STD_ON
#define CRYPTO_30_LIBCV_SIZEOFCMACAESGENERATE                                                       STD_ON
#define CRYPTO_30_LIBCV_SIZEOFCMACAESVERIFY                                                         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFDRBGAES                                                               STD_ON
#define CRYPTO_30_LIBCV_SIZEOFDISPATCH_QUEUEPRIMITIVEINFOIDX                                        STD_ON
#define CRYPTO_30_LIBCV_SIZEOFDRIVEROBJECTSTATE                                                     STD_ON
#define CRYPTO_30_LIBCV_SIZEOFECP256GENERATE                                                        STD_ON
#define CRYPTO_30_LIBCV_SIZEOFECP256VERIFY                                                          STD_ON
#define CRYPTO_30_LIBCV_SIZEOFECP521GENERATE                                                        STD_ON
#define CRYPTO_30_LIBCV_SIZEOFECP521VERIFY                                                          STD_ON
#define CRYPTO_30_LIBCV_SIZEOFED25519GENERATE                                                       STD_ON
#define CRYPTO_30_LIBCV_SIZEOFED25519VERIFY                                                         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFFAMILYTOHASHMAPPING                                                   STD_ON
#define CRYPTO_30_LIBCV_SIZEOFFIPS186                                                               STD_ON
#define CRYPTO_30_LIBCV_SIZEOFGMACAESGENERATE                                                       STD_ON
#define CRYPTO_30_LIBCV_SIZEOFGMACAESVERIFY                                                         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFHASH                                                                  STD_ON
#define CRYPTO_30_LIBCV_SIZEOFHMACSHA1GENERATE                                                      STD_ON
#define CRYPTO_30_LIBCV_SIZEOFHMACSHA1VERIFY                                                        STD_ON
#define CRYPTO_30_LIBCV_SIZEOFHMACSHA256GENERATE                                                    STD_ON
#define CRYPTO_30_LIBCV_SIZEOFHMACSHA256VERIFY                                                      STD_ON
#define CRYPTO_30_LIBCV_SIZEOFHMACSHA384GENERATE                                                    STD_ON
#define CRYPTO_30_LIBCV_SIZEOFHMACSHA384VERIFY                                                      STD_ON
#define CRYPTO_30_LIBCV_SIZEOFINITVALUE                                                             STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEY                                                                   STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYDERIVEHKDFEXPANDHMACSHA256                                         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYDERIVEHKDFEXPANDHMACSHA384                                         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYDERIVEHKDFHMACSHA256                                               STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYDERIVEHKDFHMACSHA384                                               STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYDERIVEISO15118                                                     STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYDERIVEISO15118_20                                                  STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYELEMENTINFO                                                        STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYELEMENTS                                                           STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYGENP256R1                                                          STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYLOCK                                                               STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYNVSTATUS                                                           STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYP256R1SECRET                                                       STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYSTORAGE                                                            STD_ON
#define CRYPTO_30_LIBCV_SIZEOFLOCK                                                                  STD_ON
#define CRYPTO_30_LIBCV_SIZEOFNVBLOCK                                                               STD_ON
#define CRYPTO_30_LIBCV_SIZEOFOBJECTINFO                                                            STD_ON
#define CRYPTO_30_LIBCV_SIZEOFOBJECTINFOIND                                                         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFPARTITIONIDENTIFIERS                                                  STD_ON
#define CRYPTO_30_LIBCV_SIZEOFPARTITIONINFO                                                         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFPRIMITIVEFCT                                                          STD_ON
#define CRYPTO_30_LIBCV_SIZEOFPRIMITIVEINFO                                                         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFPRIMITIVESERVICEINFO                                                  STD_ON
#define CRYPTO_30_LIBCV_SIZEOFPROCESSJOB_TRIGGER_WRITE                                              STD_ON
#define CRYPTO_30_LIBCV_SIZEOFQUEUE                                                                 STD_ON
#define CRYPTO_30_LIBCV_SIZEOFRANDOMSEEDBUFFER                                                      STD_ON
#define CRYPTO_30_LIBCV_SIZEOFREDIRECT_BUFFER                                                       STD_ON
#define CRYPTO_30_LIBCV_SIZEOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN0                            STD_ON
#define CRYPTO_30_LIBCV_SIZEOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN0_HS_HASHSHA256_FINISHED     STD_ON
#define CRYPTO_30_LIBCV_SIZEOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1                            STD_ON
#define CRYPTO_30_LIBCV_SIZEOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HS_HASHSHA256_FINISHED     STD_ON
#define CRYPTO_30_LIBCV_SIZEOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HS_HASHSHA384              STD_ON
#define CRYPTO_30_LIBCV_SIZEOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HKDF_SHA384                STD_ON
#define CRYPTO_30_LIBCV_SIZEOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_GLOBAL_HASHSHA1                  STD_ON
#define CRYPTO_30_LIBCV_SIZEOFSTRUCTUNIONWS_CRYPTO_30_LIBCV                                         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFSTRUCTUNIONWS_CRYPTO_30_LIBCV_GENERAL                                 STD_ON
#define CRYPTO_30_LIBCV_SIZEOFWRITTENLENGTH                                                         STD_ON
#define CRYPTO_30_LIBCV_SLHDSAVERIFY                                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SlhDsaVerify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFSLHDSAVERIFY                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SlhDsaVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_SM2GENERATE                                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_Sm2Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFSM2GENERATE                                                      STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_Sm2Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_SM2VERIFY                                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_Sm2Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFSM2VERIFY                                                        STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_Sm2Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_SM4DECRYPT                                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_Sm4Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFSM4DECRYPT                                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_Sm4Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_SM4ENCRYPT                                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_Sm4Encrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFSM4ENCRYPT                                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_Sm4Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_STRICTLENGTHCHECKFORKEYELEMENTGETOFGENERAL                                  STD_ON
#define CRYPTO_30_LIBCV_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN0                                  STD_ON
#define CRYPTO_30_LIBCV_DATAOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN0                            STD_ON
#define CRYPTO_30_LIBCV_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN0_HS_HASHSHA256_FINISHED           STD_ON
#define CRYPTO_30_LIBCV_DATAOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN0_HS_HASHSHA256_FINISHED     STD_ON
#define CRYPTO_30_LIBCV_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1                                  STD_ON
#define CRYPTO_30_LIBCV_DATAOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1                            STD_ON
#define CRYPTO_30_LIBCV_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HS_HASHSHA256_FINISHED           STD_ON
#define CRYPTO_30_LIBCV_DATAOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HS_HASHSHA256_FINISHED     STD_ON
#define CRYPTO_30_LIBCV_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HS_HASHSHA384                    STD_ON
#define CRYPTO_30_LIBCV_DATAOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HS_HASHSHA384              STD_ON
#define CRYPTO_30_LIBCV_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HKDF_SHA384                      STD_ON
#define CRYPTO_30_LIBCV_DATAOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HKDF_SHA384                STD_ON
#define CRYPTO_30_LIBCV_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_GLOBAL_HASHSHA1                        STD_ON
#define CRYPTO_30_LIBCV_DATAOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_GLOBAL_HASHSHA1                  STD_ON
#define CRYPTO_30_LIBCV_STRUCTUNIONWS_CRYPTO_30_LIBCV                                               STD_ON
#define CRYPTO_30_LIBCV_DATAOFSTRUCTUNIONWS_CRYPTO_30_LIBCV                                         STD_ON
#define CRYPTO_30_LIBCV_STRUCTUNIONWS_CRYPTO_30_LIBCV_GENERAL                                       STD_ON
#define CRYPTO_30_LIBCV_DATAOFSTRUCTUNIONWS_CRYPTO_30_LIBCV_GENERAL                                 STD_ON
#define CRYPTO_30_LIBCV_USEVSTDLIBOFGENERAL                                                         STD_ON
#define CRYPTO_30_LIBCV_VERSIONINFOAPIOFGENERAL                                                     STD_ON
#define CRYPTO_30_LIBCV_WRITTENLENGTH                                                               STD_ON
#define CRYPTO_30_LIBCV_PCCONFIG                                                                    STD_ON
#define CRYPTO_30_LIBCV_FINALMAGICNUMBEROFPCCONFIG                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_LIBCV_INITDATAHASHCODEOFPCCONFIG                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_LIBCV_PCPARTITIONCONFIGOFPCCONFIG                                                 STD_ON
#define CRYPTO_30_LIBCV_PARTITIONIDENTIFIERSOFPCCONFIG                                              STD_ON
#define CRYPTO_30_LIBCV_SIZEOFPARTITIONIDENTIFIERSOFPCCONFIG                                        STD_ON
#define CRYPTO_30_LIBCV_PCPARTITIONCONFIG                                                           STD_ON
#define CRYPTO_30_LIBCV_AEADCHACHAPOLY1305DECRYPTOFPCPARTITIONCONFIG                                STD_ON
#define CRYPTO_30_LIBCV_AEADCHACHAPOLY1305ENCRYPTOFPCPARTITIONCONFIG                                STD_ON
#define CRYPTO_30_LIBCV_AESDECRYPTOFPCPARTITIONCONFIG                                               STD_ON
#define CRYPTO_30_LIBCV_AESENCRYPTOFPCPARTITIONCONFIG                                               STD_ON
#define CRYPTO_30_LIBCV_AESGCMDECRYPTOFPCPARTITIONCONFIG                                            STD_ON
#define CRYPTO_30_LIBCV_AESGCMENCRYPTOFPCPARTITIONCONFIG                                            STD_ON
#define CRYPTO_30_LIBCV_BUFFERLENGTHOFPCPARTITIONCONFIG                                             STD_ON
#define CRYPTO_30_LIBCV_CMACAESGENERATEOFPCPARTITIONCONFIG                                          STD_ON
#define CRYPTO_30_LIBCV_CMACAESVERIFYOFPCPARTITIONCONFIG                                            STD_ON
#define CRYPTO_30_LIBCV_DRBGAESOFPCPARTITIONCONFIG                                                  STD_ON
#define CRYPTO_30_LIBCV_DISPATCH_QUEUEPRIMITIVEINFOIDXOFPCPARTITIONCONFIG                           STD_ON
#define CRYPTO_30_LIBCV_DRIVEROBJECTSTATEOFPCPARTITIONCONFIG                                        STD_ON
#define CRYPTO_30_LIBCV_ECP256GENERATEOFPCPARTITIONCONFIG                                           STD_ON
#define CRYPTO_30_LIBCV_ECP256VERIFYOFPCPARTITIONCONFIG                                             STD_ON
#define CRYPTO_30_LIBCV_ECP521GENERATEOFPCPARTITIONCONFIG                                           STD_ON
#define CRYPTO_30_LIBCV_ECP521VERIFYOFPCPARTITIONCONFIG                                             STD_ON
#define CRYPTO_30_LIBCV_ED25519GENERATEOFPCPARTITIONCONFIG                                          STD_ON
#define CRYPTO_30_LIBCV_ED25519VERIFYOFPCPARTITIONCONFIG                                            STD_ON
#define CRYPTO_30_LIBCV_EXPECTEDCOMPATIBILITYVERSIONOFPCPARTITIONCONFIG                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PCPartitionConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_LIBCV_FAMILYTOHASHMAPPINGOFPCPARTITIONCONFIG                                      STD_ON
#define CRYPTO_30_LIBCV_FIPS186OFPCPARTITIONCONFIG                                                  STD_ON
#define CRYPTO_30_LIBCV_GENERATORCOMPATIBILITYVERSIONOFPCPARTITIONCONFIG                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PCPartitionConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_LIBCV_GMACAESGENERATEOFPCPARTITIONCONFIG                                          STD_ON
#define CRYPTO_30_LIBCV_GMACAESVERIFYOFPCPARTITIONCONFIG                                            STD_ON
#define CRYPTO_30_LIBCV_HASHOFPCPARTITIONCONFIG                                                     STD_ON
#define CRYPTO_30_LIBCV_HMACSHA1GENERATEOFPCPARTITIONCONFIG                                         STD_ON
#define CRYPTO_30_LIBCV_HMACSHA1VERIFYOFPCPARTITIONCONFIG                                           STD_ON
#define CRYPTO_30_LIBCV_HMACSHA256GENERATEOFPCPARTITIONCONFIG                                       STD_ON
#define CRYPTO_30_LIBCV_HMACSHA256VERIFYOFPCPARTITIONCONFIG                                         STD_ON
#define CRYPTO_30_LIBCV_HMACSHA384GENERATEOFPCPARTITIONCONFIG                                       STD_ON
#define CRYPTO_30_LIBCV_HMACSHA384VERIFYOFPCPARTITIONCONFIG                                         STD_ON
#define CRYPTO_30_LIBCV_INITVALUEOFPCPARTITIONCONFIG                                                STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFEXPANDHMACSHA256OFPCPARTITIONCONFIG                            STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFEXPANDHMACSHA384OFPCPARTITIONCONFIG                            STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFHMACSHA256OFPCPARTITIONCONFIG                                  STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFHMACSHA384OFPCPARTITIONCONFIG                                  STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEISO15118OFPCPARTITIONCONFIG                                        STD_ON
#define CRYPTO_30_LIBCV_KEYDERIVEISO15118_20OFPCPARTITIONCONFIG                                     STD_ON
#define CRYPTO_30_LIBCV_KEYELEMENTINFOOFPCPARTITIONCONFIG                                           STD_ON
#define CRYPTO_30_LIBCV_KEYELEMENTSOFPCPARTITIONCONFIG                                              STD_ON
#define CRYPTO_30_LIBCV_KEYGENP256R1OFPCPARTITIONCONFIG                                             STD_ON
#define CRYPTO_30_LIBCV_KEYLOCKOFPCPARTITIONCONFIG                                                  STD_ON
#define CRYPTO_30_LIBCV_KEYNVSTATUSOFPCPARTITIONCONFIG                                              STD_ON
#define CRYPTO_30_LIBCV_KEYOFPCPARTITIONCONFIG                                                      STD_ON
#define CRYPTO_30_LIBCV_KEYP256R1SECRETOFPCPARTITIONCONFIG                                          STD_ON
#define CRYPTO_30_LIBCV_KEYSTORAGEOFPCPARTITIONCONFIG                                               STD_ON
#define CRYPTO_30_LIBCV_LOCKOFPCPARTITIONCONFIG                                                     STD_ON
#define CRYPTO_30_LIBCV_MAINFUNCTIONPERIODOFGENERALOFPCPARTITIONCONFIG                              STD_ON
#define CRYPTO_30_LIBCV_NVBLOCKOFPCPARTITIONCONFIG                                                  STD_ON
#define CRYPTO_30_LIBCV_OBJECTINFOINDOFPCPARTITIONCONFIG                                            STD_ON
#define CRYPTO_30_LIBCV_OBJECTINFOOFPCPARTITIONCONFIG                                               STD_ON
#define CRYPTO_30_LIBCV_PARTITIONINFOOFPCPARTITIONCONFIG                                            STD_ON
#define CRYPTO_30_LIBCV_PARTITIONINITIALIZEDOFPCPARTITIONCONFIG                                     STD_ON
#define CRYPTO_30_LIBCV_PRIMITIVEFCTOFPCPARTITIONCONFIG                                             STD_ON
#define CRYPTO_30_LIBCV_PRIMITIVEINFOOFPCPARTITIONCONFIG                                            STD_ON
#define CRYPTO_30_LIBCV_PRIMITIVESERVICEINFOOFPCPARTITIONCONFIG                                     STD_ON
#define CRYPTO_30_LIBCV_PROCESSJOB_TRIGGER_WRITEOFPCPARTITIONCONFIG                                 STD_ON
#define CRYPTO_30_LIBCV_QUEUEOFPCPARTITIONCONFIG                                                    STD_ON
#define CRYPTO_30_LIBCV_RANDOMSEEDBUFFEROFPCPARTITIONCONFIG                                         STD_ON
#define CRYPTO_30_LIBCV_RANDOMSOURCEGENERATECOUNTOFPCPARTITIONCONFIG                                STD_ON
#define CRYPTO_30_LIBCV_REDIRECT_BUFFEROFPCPARTITIONCONFIG                                          STD_ON
#define CRYPTO_30_LIBCV_SIZEOFAEADCHACHAPOLY1305DECRYPTOFPCPARTITIONCONFIG                          STD_ON
#define CRYPTO_30_LIBCV_SIZEOFAEADCHACHAPOLY1305ENCRYPTOFPCPARTITIONCONFIG                          STD_ON
#define CRYPTO_30_LIBCV_SIZEOFAESDECRYPTOFPCPARTITIONCONFIG                                         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFAESENCRYPTOFPCPARTITIONCONFIG                                         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFAESGCMDECRYPTOFPCPARTITIONCONFIG                                      STD_ON
#define CRYPTO_30_LIBCV_SIZEOFAESGCMENCRYPTOFPCPARTITIONCONFIG                                      STD_ON
#define CRYPTO_30_LIBCV_SIZEOFBUFFERLENGTHOFPCPARTITIONCONFIG                                       STD_ON
#define CRYPTO_30_LIBCV_SIZEOFCMACAESGENERATEOFPCPARTITIONCONFIG                                    STD_ON
#define CRYPTO_30_LIBCV_SIZEOFCMACAESVERIFYOFPCPARTITIONCONFIG                                      STD_ON
#define CRYPTO_30_LIBCV_SIZEOFDRBGAESOFPCPARTITIONCONFIG                                            STD_ON
#define CRYPTO_30_LIBCV_SIZEOFDISPATCH_QUEUEPRIMITIVEINFOIDXOFPCPARTITIONCONFIG                     STD_ON
#define CRYPTO_30_LIBCV_SIZEOFDRIVEROBJECTSTATEOFPCPARTITIONCONFIG                                  STD_ON
#define CRYPTO_30_LIBCV_SIZEOFECP256GENERATEOFPCPARTITIONCONFIG                                     STD_ON
#define CRYPTO_30_LIBCV_SIZEOFECP256VERIFYOFPCPARTITIONCONFIG                                       STD_ON
#define CRYPTO_30_LIBCV_SIZEOFECP521GENERATEOFPCPARTITIONCONFIG                                     STD_ON
#define CRYPTO_30_LIBCV_SIZEOFECP521VERIFYOFPCPARTITIONCONFIG                                       STD_ON
#define CRYPTO_30_LIBCV_SIZEOFED25519GENERATEOFPCPARTITIONCONFIG                                    STD_ON
#define CRYPTO_30_LIBCV_SIZEOFED25519VERIFYOFPCPARTITIONCONFIG                                      STD_ON
#define CRYPTO_30_LIBCV_SIZEOFFAMILYTOHASHMAPPINGOFPCPARTITIONCONFIG                                STD_ON
#define CRYPTO_30_LIBCV_SIZEOFFIPS186OFPCPARTITIONCONFIG                                            STD_ON
#define CRYPTO_30_LIBCV_SIZEOFGMACAESGENERATEOFPCPARTITIONCONFIG                                    STD_ON
#define CRYPTO_30_LIBCV_SIZEOFGMACAESVERIFYOFPCPARTITIONCONFIG                                      STD_ON
#define CRYPTO_30_LIBCV_SIZEOFHASHOFPCPARTITIONCONFIG                                               STD_ON
#define CRYPTO_30_LIBCV_SIZEOFHMACSHA1GENERATEOFPCPARTITIONCONFIG                                   STD_ON
#define CRYPTO_30_LIBCV_SIZEOFHMACSHA1VERIFYOFPCPARTITIONCONFIG                                     STD_ON
#define CRYPTO_30_LIBCV_SIZEOFHMACSHA256GENERATEOFPCPARTITIONCONFIG                                 STD_ON
#define CRYPTO_30_LIBCV_SIZEOFHMACSHA256VERIFYOFPCPARTITIONCONFIG                                   STD_ON
#define CRYPTO_30_LIBCV_SIZEOFHMACSHA384GENERATEOFPCPARTITIONCONFIG                                 STD_ON
#define CRYPTO_30_LIBCV_SIZEOFHMACSHA384VERIFYOFPCPARTITIONCONFIG                                   STD_ON
#define CRYPTO_30_LIBCV_SIZEOFINITVALUEOFPCPARTITIONCONFIG                                          STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYDERIVEHKDFEXPANDHMACSHA256OFPCPARTITIONCONFIG                      STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYDERIVEHKDFEXPANDHMACSHA384OFPCPARTITIONCONFIG                      STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYDERIVEHKDFHMACSHA256OFPCPARTITIONCONFIG                            STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYDERIVEHKDFHMACSHA384OFPCPARTITIONCONFIG                            STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYDERIVEISO15118OFPCPARTITIONCONFIG                                  STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYDERIVEISO15118_20OFPCPARTITIONCONFIG                               STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYELEMENTINFOOFPCPARTITIONCONFIG                                     STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYELEMENTSOFPCPARTITIONCONFIG                                        STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYGENP256R1OFPCPARTITIONCONFIG                                       STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYLOCKOFPCPARTITIONCONFIG                                            STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYNVSTATUSOFPCPARTITIONCONFIG                                        STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYOFPCPARTITIONCONFIG                                                STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYP256R1SECRETOFPCPARTITIONCONFIG                                    STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYSTORAGEOFPCPARTITIONCONFIG                                         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFLOCKOFPCPARTITIONCONFIG                                               STD_ON
#define CRYPTO_30_LIBCV_SIZEOFNVBLOCKOFPCPARTITIONCONFIG                                            STD_ON
#define CRYPTO_30_LIBCV_SIZEOFOBJECTINFOINDOFPCPARTITIONCONFIG                                      STD_ON
#define CRYPTO_30_LIBCV_SIZEOFOBJECTINFOOFPCPARTITIONCONFIG                                         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFPARTITIONINFOOFPCPARTITIONCONFIG                                      STD_ON
#define CRYPTO_30_LIBCV_SIZEOFPRIMITIVEFCTOFPCPARTITIONCONFIG                                       STD_ON
#define CRYPTO_30_LIBCV_SIZEOFPRIMITIVEINFOOFPCPARTITIONCONFIG                                      STD_ON
#define CRYPTO_30_LIBCV_SIZEOFPRIMITIVESERVICEINFOOFPCPARTITIONCONFIG                               STD_ON
#define CRYPTO_30_LIBCV_SIZEOFPROCESSJOB_TRIGGER_WRITEOFPCPARTITIONCONFIG                           STD_ON
#define CRYPTO_30_LIBCV_SIZEOFQUEUEOFPCPARTITIONCONFIG                                              STD_ON
#define CRYPTO_30_LIBCV_SIZEOFRANDOMSEEDBUFFEROFPCPARTITIONCONFIG                                   STD_ON
#define CRYPTO_30_LIBCV_SIZEOFREDIRECT_BUFFEROFPCPARTITIONCONFIG                                    STD_ON
#define CRYPTO_30_LIBCV_SIZEOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN0OFPCPARTITIONCONFIG         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN0_HS_HASHSHA256_FINISHEDOFPCPARTITIONCONFIG STD_ON
#define CRYPTO_30_LIBCV_SIZEOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1OFPCPARTITIONCONFIG         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HS_HASHSHA256_FINISHEDOFPCPARTITIONCONFIG STD_ON
#define CRYPTO_30_LIBCV_SIZEOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HS_HASHSHA384OFPCPARTITIONCONFIG STD_ON
#define CRYPTO_30_LIBCV_SIZEOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HKDF_SHA384OFPCPARTITIONCONFIG STD_ON
#define CRYPTO_30_LIBCV_SIZEOFSTRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_GLOBAL_HASHSHA1OFPCPARTITIONCONFIG STD_ON
#define CRYPTO_30_LIBCV_SIZEOFSTRUCTUNIONWS_CRYPTO_30_LIBCVOFPCPARTITIONCONFIG                      STD_ON
#define CRYPTO_30_LIBCV_SIZEOFSTRUCTUNIONWS_CRYPTO_30_LIBCV_GENERALOFPCPARTITIONCONFIG              STD_ON
#define CRYPTO_30_LIBCV_SIZEOFWRITTENLENGTHOFPCPARTITIONCONFIG                                      STD_ON
#define CRYPTO_30_LIBCV_STRICTLENGTHCHECKFORKEYELEMENTGETOFGENERALOFPCPARTITIONCONFIG               STD_ON
#define CRYPTO_30_LIBCV_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN0OFPCPARTITIONCONFIG               STD_ON
#define CRYPTO_30_LIBCV_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN0_HS_HASHSHA256_FINISHEDOFPCPARTITIONCONFIG STD_ON
#define CRYPTO_30_LIBCV_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1OFPCPARTITIONCONFIG               STD_ON
#define CRYPTO_30_LIBCV_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HS_HASHSHA256_FINISHEDOFPCPARTITIONCONFIG STD_ON
#define CRYPTO_30_LIBCV_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HS_HASHSHA384OFPCPARTITIONCONFIG STD_ON
#define CRYPTO_30_LIBCV_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HKDF_SHA384OFPCPARTITIONCONFIG   STD_ON
#define CRYPTO_30_LIBCV_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_GLOBAL_HASHSHA1OFPCPARTITIONCONFIG     STD_ON
#define CRYPTO_30_LIBCV_STRUCTUNIONWS_CRYPTO_30_LIBCVOFPCPARTITIONCONFIG                            STD_ON
#define CRYPTO_30_LIBCV_STRUCTUNIONWS_CRYPTO_30_LIBCV_GENERALOFPCPARTITIONCONFIG                    STD_ON
#define CRYPTO_30_LIBCV_USEVSTDLIBOFGENERALOFPCPARTITIONCONFIG                                      STD_ON
#define CRYPTO_30_LIBCV_VERSIONINFOAPIOFGENERALOFPCPARTITIONCONFIG                                  STD_ON
#define CRYPTO_30_LIBCV_WRITTENLENGTHOFPCPARTITIONCONFIG                                            STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCMinNumericValueDefines  Crypto_30_LibCv Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define CRYPTO_30_LIBCV_MIN_BUFFERLENGTH                                                            0u
#define CRYPTO_30_LIBCV_MIN_DRIVEROBJECTSTATE                                                       0u
#define CRYPTO_30_LIBCV_MIN_KEYLOCK                                                                 0u
#define CRYPTO_30_LIBCV_MIN_KEYNVSTATUS                                                             0u
#define CRYPTO_30_LIBCV_MIN_KEYSTORAGE                                                              0u
#define CRYPTO_30_LIBCV_MIN_KEYIDOFLASTJOB                                                          0u
#define CRYPTO_30_LIBCV_MIN_LOCK                                                                    0u
#define CRYPTO_30_LIBCV_MIN_LONGTERMWSLOCK                                                          0u
#define CRYPTO_30_LIBCV_MIN_PARTITIONINITIALIZED                                                    0u
#define CRYPTO_30_LIBCV_MIN_RANDOMSEEDBUFFER                                                        0u
#define CRYPTO_30_LIBCV_MIN_RANDOMSOURCEGENERATECOUNT                                               0u
#define CRYPTO_30_LIBCV_MIN_LENGTHOFSAVEANDRESTOREWORKSPACE                                         0u
#define CRYPTO_30_LIBCV_MIN_WRITTENLENGTH                                                           0u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCMaxNumericValueDefines  Crypto_30_LibCv Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define CRYPTO_30_LIBCV_MAX_BUFFERLENGTH                                                            4294967295u
#define CRYPTO_30_LIBCV_MAX_DRIVEROBJECTSTATE                                                       255u
#define CRYPTO_30_LIBCV_MAX_KEYLOCK                                                                 255u
#define CRYPTO_30_LIBCV_MAX_KEYNVSTATUS                                                             255u
#define CRYPTO_30_LIBCV_MAX_KEYSTORAGE                                                              255u
#define CRYPTO_30_LIBCV_MAX_KEYIDOFLASTJOB                                                          4294967295u
#define CRYPTO_30_LIBCV_MAX_LOCK                                                                    4294967295u
#define CRYPTO_30_LIBCV_MAX_LONGTERMWSLOCK                                                          4294967295u
#define CRYPTO_30_LIBCV_MAX_PARTITIONINITIALIZED                                                    255u
#define CRYPTO_30_LIBCV_MAX_RANDOMSEEDBUFFER                                                        255u
#define CRYPTO_30_LIBCV_MAX_RANDOMSOURCEGENERATECOUNT                                               65535u
#define CRYPTO_30_LIBCV_MAX_LENGTHOFSAVEANDRESTOREWORKSPACE                                         4294967295u
#define CRYPTO_30_LIBCV_MAX_WRITTENLENGTH                                                           4294967295u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCNoReferenceDefines  Crypto_30_LibCv No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CRYPTO_30_LIBCV_NO_INITVALUE                                                                255u
#define CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY                                                          255u
#define CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO                                          255u
#define CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO                                        255u
#define CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO                                 255u
#define CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO                                 255u
#define CRYPTO_30_LIBCV_NO_AESCCMDECRYPTIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_AESCCMENCRYPTIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_AESDECRYPTIDXOFOBJECTINFO                                                255u
#define CRYPTO_30_LIBCV_NO_AESENCRYPTIDXOFOBJECTINFO                                                255u
#define CRYPTO_30_LIBCV_NO_AESGCMDECRYPTIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_AESGCMENCRYPTIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_CMACAESGENERATEIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_CMACAESVERIFYIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_DRBGAESIDXOFOBJECTINFO                                                   255u
#define CRYPTO_30_LIBCV_NO_DRBGHASHSHA512IDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_ECP160GENERATEIDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_ECP160VERIFYIDXOFOBJECTINFO                                              255u
#define CRYPTO_30_LIBCV_NO_ECP256GENERATEIDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_ECP256VERIFYIDXOFOBJECTINFO                                              255u
#define CRYPTO_30_LIBCV_NO_ECP384GENERATEIDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_ECP384VERIFYIDXOFOBJECTINFO                                              255u
#define CRYPTO_30_LIBCV_NO_ECP521GENERATEIDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_ECP521VERIFYIDXOFOBJECTINFO                                              255u
#define CRYPTO_30_LIBCV_NO_ECPKEYCHECKIDXOFOBJECTINFO                                               255u
#define CRYPTO_30_LIBCV_NO_ED25519GENERATEIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_ED25519VERIFYIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_ED448GENERATEIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_ED448VERIFYIDXOFOBJECTINFO                                               255u
#define CRYPTO_30_LIBCV_NO_EDKEYCHECKIDXOFOBJECTINFO                                                255u
#define CRYPTO_30_LIBCV_NO_FIPS186IDXOFOBJECTINFO                                                   255u
#define CRYPTO_30_LIBCV_NO_GMACAESGENERATEIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_GMACAESVERIFYIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_HASHIDXOFOBJECTINFO                                                      255u
#define CRYPTO_30_LIBCV_NO_HMACRIPEMD160GENERATEIDXOFOBJECTINFO                                     255u
#define CRYPTO_30_LIBCV_NO_HMACRIPEMD160VERIFYIDXOFOBJECTINFO                                       255u
#define CRYPTO_30_LIBCV_NO_HMACSHA1GENERATEIDXOFOBJECTINFO                                          255u
#define CRYPTO_30_LIBCV_NO_HMACSHA1VERIFYIDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_HMACSHA256GENERATEIDXOFOBJECTINFO                                        255u
#define CRYPTO_30_LIBCV_NO_HMACSHA256VERIFYIDXOFOBJECTINFO                                          255u
#define CRYPTO_30_LIBCV_NO_HMACSHA384GENERATEIDXOFOBJECTINFO                                        255u
#define CRYPTO_30_LIBCV_NO_HMACSHA384VERIFYIDXOFOBJECTINFO                                          255u
#define CRYPTO_30_LIBCV_NO_HMACSHA512GENERATEIDXOFOBJECTINFO                                        255u
#define CRYPTO_30_LIBCV_NO_HMACSHA512VERIFYIDXOFOBJECTINFO                                          255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFEXPANDHMACSHA256IDXOFOBJECTINFO                             255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFEXPANDHMACSHA384IDXOFOBJECTINFO                             255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHMACSHA256IDXOFOBJECTINFO                                   255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHMACSHA384IDXOFOBJECTINFO                                   255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHASHOPTION1SHA256IDXOFOBJECTINFO                            255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHASHOPTION1SHA512IDXOFOBJECTINFO                            255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVEISO15118IDXOFOBJECTINFO                                         255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVEISO15118_20IDXOFOBJECTINFO                                      255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVEKDF2HMACSHA1IDXOFOBJECTINFO                                     255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVEKDF2HMACSHA256IDXOFOBJECTINFO                                   255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVENIST800108CNTIDXOFOBJECTINFO                                    255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVENIST80056AONEPASSIDXOFOBJECTINFO                                255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVENISTFIPS186ERBIDXOFOBJECTINFO                                   255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVESPAKE2PIDXOFOBJECTINFO                                          255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVEX963SHA256IDXOFOBJECTINFO                                       255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVEX963SHA512IDXOFOBJECTINFO                                       255u
#define CRYPTO_30_LIBCV_NO_KEYGENED25519IDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_KEYGENP256R1IDXOFOBJECTINFO                                              255u
#define CRYPTO_30_LIBCV_NO_KEYGENP384R1IDXOFOBJECTINFO                                              255u
#define CRYPTO_30_LIBCV_NO_KEYGENP521R1IDXOFOBJECTINFO                                              255u
#define CRYPTO_30_LIBCV_NO_KEYGENSM2P256V1IDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_KEYGENSYMGENERICIDXOFOBJECTINFO                                          255u
#define CRYPTO_30_LIBCV_NO_KEYP224R1BDPUBVALIDXOFOBJECTINFO                                         255u
#define CRYPTO_30_LIBCV_NO_KEYP224R1BDSECRETIDXOFOBJECTINFO                                         255u
#define CRYPTO_30_LIBCV_NO_KEYP256R1BDPUBVALIDXOFOBJECTINFO                                         255u
#define CRYPTO_30_LIBCV_NO_KEYP256R1BDSECRETIDXOFOBJECTINFO                                         255u
#define CRYPTO_30_LIBCV_NO_KEYP256R1PUBVALIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_KEYP256R1SECRETIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_KEYP384R1PUBVALIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_KEYP384R1SECRETIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_KEYP521R1PUBVALIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_KEYP521R1SECRETIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_KEYSEEDDRBGAESIDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_KEYSEEDDRBGHASHSHA512IDXOFOBJECTINFO                                     255u
#define CRYPTO_30_LIBCV_NO_KEYSEEDFIPS186IDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_KEYSETINVALIDJOBIDXOFOBJECTINFO                                          255u
#define CRYPTO_30_LIBCV_NO_KEYSETVALIDJOBIDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_KEYSPAKE2PPUBVALIDXOFOBJECTINFO                                          255u
#define CRYPTO_30_LIBCV_NO_KEYSPAKE2PSECRETIDXOFOBJECTINFO                                          255u
#define CRYPTO_30_LIBCV_NO_KEYX25519PUBVALIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_KEYX25519SECRETIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_KEYX448PUBVALIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_KEYX448SECRETIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_MD5IDXOFOBJECTINFO                                                       255u
#define CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERENDIDXOFOBJECTINFO                                       255u
#define CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO                                     255u
#define CRYPTO_30_LIBCV_NO_RSAOAEPCRTSHA1DECRYPTIDXOFOBJECTINFO                                     255u
#define CRYPTO_30_LIBCV_NO_RSAOAEPCRTSHA256DECRYPTIDXOFOBJECTINFO                                   255u
#define CRYPTO_30_LIBCV_NO_RSAOAEPSHA1DECRYPTIDXOFOBJECTINFO                                        255u
#define CRYPTO_30_LIBCV_NO_RSAOAEPSHA1ENCRYPTIDXOFOBJECTINFO                                        255u
#define CRYPTO_30_LIBCV_NO_RSAOAEPSHA256DECRYPTIDXOFOBJECTINFO                                      255u
#define CRYPTO_30_LIBCV_NO_RSAOAEPSHA256ENCRYPTIDXOFOBJECTINFO                                      255u
#define CRYPTO_30_LIBCV_NO_RSAPKCS1CRTGENERATEIDXOFOBJECTINFO                                       255u
#define CRYPTO_30_LIBCV_NO_RSAPKCS1DECRYPTIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_RSAPKCS1ENCRYPTIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_RSAPKCS1GENERATEIDXOFOBJECTINFO                                          255u
#define CRYPTO_30_LIBCV_NO_RSAPKCS1VERIFYIDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_RSAPSSGENERATEIDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_RSAPSSVERIFYIDXOFOBJECTINFO                                              255u
#define CRYPTO_30_LIBCV_NO_SHECMDGETIDIDXOFOBJECTINFO                                               255u
#define CRYPTO_30_LIBCV_NO_SIPHASHGENERATEIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_SIPHASHVERIFYIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_SLHDSAVERIFYIDXOFOBJECTINFO                                              255u
#define CRYPTO_30_LIBCV_NO_SM2GENERATEIDXOFOBJECTINFO                                               255u
#define CRYPTO_30_LIBCV_NO_SM2VERIFYIDXOFOBJECTINFO                                                 255u
#define CRYPTO_30_LIBCV_NO_SM4DECRYPTIDXOFOBJECTINFO                                                255u
#define CRYPTO_30_LIBCV_NO_SM4ENCRYPTIDXOFOBJECTINFO                                                255u
#define CRYPTO_30_LIBCV_NO_OBJECTINFOINDENDIDXOFPRIMITIVEFCT                                        255u
#define CRYPTO_30_LIBCV_NO_OBJECTINFOINDSTARTIDXOFPRIMITIVEFCT                                      255u
#define CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO                                255u
#define CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO                              255u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCMaskedBitDefines  Crypto_30_LibCv Masked Bit Defines (PRE_COMPILE)
  \brief  These defines are masks to extract packed boolean data.
  \{
*/ 
#define CRYPTO_30_LIBCV_ONCEOFKEYELEMENTINFO_MASK                                                   0x04u
#define CRYPTO_30_LIBCV_PARTIALOFKEYELEMENTINFO_MASK                                                0x02u
#define CRYPTO_30_LIBCV_PERSISTOFKEYELEMENTINFO_MASK                                                0x01u
#define CRYPTO_30_LIBCV_AESOFPARTITIONINFO_MASK                                                     0x02u
#define CRYPTO_30_LIBCV_HASHOFPARTITIONINFO_MASK                                                    0x01u
#define CRYPTO_30_LIBCV_CONTEXTOFPRIMITIVEINFO_MASK                                                 0x02u
#define CRYPTO_30_LIBCV_DEFAULTRANDOMSOURCEOFPRIMITIVEINFO_MASK                                     0x01u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCIsReducedToDefineDefines  Crypto_30_LibCv Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFAEADCHACHAPOLY1305DECRYPT                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFAEADCHACHAPOLY1305ENCRYPT                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFAESCCMDECRYPT                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFAESCCMENCRYPT                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFAESDECRYPT                                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFAESENCRYPT                                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFAESGCMDECRYPT                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFAESGCMENCRYPT                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFCMACAESGENERATE                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFCMACAESVERIFY                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFDRBGAES                                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFDRBGHASHSHA512                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFECP160GENERATE                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFECP160VERIFY                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFECP256GENERATE                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFECP256VERIFY                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFECP384GENERATE                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFECP384VERIFY                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFECP521GENERATE                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFECP521VERIFY                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFECPKEYCHECK                                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFED25519GENERATE                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFED25519VERIFY                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFED448GENERATE                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFED448VERIFY                                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFEDKEYCHECK                                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_FAMILYTOHASHMAPPING                                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFFIPS186                                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFGMACAESGENERATE                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFGMACAESVERIFY                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFHASH                                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFHMACRIPEMD160GENERATE                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFHMACRIPEMD160VERIFY                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFHMACSHA1GENERATE                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFHMACSHA1VERIFY                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFHMACSHA256GENERATE                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFHMACSHA256VERIFY                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFHMACSHA384GENERATE                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFHMACSHA384VERIFY                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFHMACSHA512GENERATE                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFHMACSHA512VERIFY                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_INITVALUE                                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYELEMENTSENDIDXOFKEY                                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYELEMENTSSTARTIDXOFKEY                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_NVBLOCKIDXOFKEY                                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_NVBLOCKUSEDOFKEY                                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVEHKDFEXPANDHMACSHA256                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVEHKDFEXPANDHMACSHA384                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVEHKDFHMACSHA256                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVEHKDFHMACSHA384                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVEHKDFHASHOPTION1SHA256                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVEHKDFHASHOPTION1SHA512                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVEISO15118                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVEISO15118_20                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVEKDF2HMACSHA1                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVEKDF2HMACSHA256                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVENIST800108CNT                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVENIST80056AONEPASS                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVENISTFIPS186ERB                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVESPAKE2P                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVEX963SHA256                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVEX963SHA512                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_IDOFKEYELEMENTINFO                                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_INITVALUEENDIDXOFKEYELEMENTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_INITVALUESTARTIDXOFKEYELEMENTINFO                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_INITVALUEUSEDOFKEYELEMENTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_LENGTHOFKEYELEMENTINFO                                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_MASKEDBITSOFKEYELEMENTINFO                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ONCEOFKEYELEMENTINFO                                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PARTIALOFKEYELEMENTINFO                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PERSISTOFKEYELEMENTINFO                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_READOFKEYELEMENTINFO                                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WRITEOFKEYELEMENTINFO                                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_IDOFKEYELEMENTS                                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYELEMENTINFOIDXOFKEYELEMENTS                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSTORAGEENDIDXOFKEYELEMENTS                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSTORAGEEXTENSIONIDXOFKEYELEMENTS                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSTORAGESTARTIDXOFKEYELEMENTS                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSTORAGEVALIDIDXOFKEYELEMENTS                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSTORAGEWRITTENLENGTHENDIDXOFKEYELEMENTS                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSTORAGEWRITTENLENGTHSTARTIDXOFKEYELEMENTS                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYGENED25519                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYGENP256R1                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYGENP384R1                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYGENP521R1                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYGENSM2P256V1                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYGENSYMGENERIC                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYP224R1BDPUBVAL                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYP224R1BDSECRET                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYP256R1BDPUBVAL                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYP256R1BDSECRET                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYP256R1PUBVAL                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYP256R1SECRET                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYP384R1PUBVAL                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYP384R1SECRET                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYP521R1PUBVAL                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYP521R1SECRET                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYSEEDDRBGAES                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYSEEDDRBGHASHSHA512                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYSEEDFIPS186                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYSETINVALIDJOB                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYSETVALIDJOB                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYSPAKE2PPUBVAL                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYSPAKE2PSECRET                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYX25519PUBVAL                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYX25519SECRET                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYX448PUBVAL                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYX448SECRET                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFMD5                                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_CONSISTENCYLEVELOFNVBLOCK                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_CRCOFNVBLOCK                                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_DESCRIPTOROFNVBLOCK                                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_IDOFNVBLOCK                                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSTORAGEENDIDXOFNVBLOCK                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSTORAGESTARTIDXOFNVBLOCK                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_LENGTHOFNVBLOCK                                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PROCESSINGOFNVBLOCK                                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AEADCHACHAPOLY1305DECRYPTUSEDOFOBJECTINFO                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AEADCHACHAPOLY1305ENCRYPTUSEDOFOBJECTINFO                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESCCMDECRYPTIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESCCMDECRYPTUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESCCMENCRYPTIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESCCMENCRYPTUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESDECRYPTIDXOFOBJECTINFO                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESDECRYPTUSEDOFOBJECTINFO                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESENCRYPTIDXOFOBJECTINFO                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESENCRYPTUSEDOFOBJECTINFO                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESGCMDECRYPTIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESGCMDECRYPTUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESGCMENCRYPTIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESGCMENCRYPTUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_APPLICATIONIDOFOBJECTINFO                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_CMACAESGENERATEIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_CMACAESGENERATEUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_CMACAESVERIFYIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_CMACAESVERIFYUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_DRBGAESIDXOFOBJECTINFO                                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_DRBGAESUSEDOFOBJECTINFO                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_DRBGHASHSHA512IDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_DRBGHASHSHA512USEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP160GENERATEIDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP160GENERATEUSEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP160VERIFYIDXOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP160VERIFYUSEDOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP256GENERATEIDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP256GENERATEUSEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP256VERIFYIDXOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP256VERIFYUSEDOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP384GENERATEIDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP384GENERATEUSEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP384VERIFYIDXOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP384VERIFYUSEDOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP521GENERATEIDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP521GENERATEUSEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP521VERIFYIDXOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP521VERIFYUSEDOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECPKEYCHECKIDXOFOBJECTINFO                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECPKEYCHECKUSEDOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ED25519GENERATEIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ED25519GENERATEUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ED25519VERIFYIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ED25519VERIFYUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ED448GENERATEIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ED448GENERATEUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ED448VERIFYIDXOFOBJECTINFO                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ED448VERIFYUSEDOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_EDKEYCHECKIDXOFOBJECTINFO                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_EDKEYCHECKUSEDOFOBJECTINFO                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_FIPS186IDXOFOBJECTINFO                                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_FIPS186USEDOFOBJECTINFO                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_GMACAESGENERATEIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_GMACAESGENERATEUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_GMACAESVERIFYIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_GMACAESVERIFYUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HASHIDXOFOBJECTINFO                                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HASHUSEDOFOBJECTINFO                                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACRIPEMD160GENERATEIDXOFOBJECTINFO                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACRIPEMD160GENERATEUSEDOFOBJECTINFO                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACRIPEMD160VERIFYIDXOFOBJECTINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACRIPEMD160VERIFYUSEDOFOBJECTINFO                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA1GENERATEIDXOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA1GENERATEUSEDOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA1VERIFYIDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA1VERIFYUSEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA256GENERATEIDXOFOBJECTINFO                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA256GENERATEUSEDOFOBJECTINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA256VERIFYIDXOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA256VERIFYUSEDOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA384GENERATEIDXOFOBJECTINFO                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA384GENERATEUSEDOFOBJECTINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA384VERIFYIDXOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA384VERIFYUSEDOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA512GENERATEIDXOFOBJECTINFO                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA512GENERATEUSEDOFOBJECTINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA512VERIFYIDXOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA512VERIFYUSEDOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEHKDFEXPANDHMACSHA256IDXOFOBJECTINFO                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEHKDFEXPANDHMACSHA256USEDOFOBJECTINFO                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEHKDFEXPANDHMACSHA384IDXOFOBJECTINFO                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEHKDFEXPANDHMACSHA384USEDOFOBJECTINFO                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEHKDFHMACSHA256IDXOFOBJECTINFO                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEHKDFHMACSHA256USEDOFOBJECTINFO                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEHKDFHMACSHA384IDXOFOBJECTINFO                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEHKDFHMACSHA384USEDOFOBJECTINFO                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEHKDFHASHOPTION1SHA256IDXOFOBJECTINFO                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEHKDFHASHOPTION1SHA256USEDOFOBJECTINFO                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEHKDFHASHOPTION1SHA512IDXOFOBJECTINFO                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEHKDFHASHOPTION1SHA512USEDOFOBJECTINFO                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEISO15118IDXOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEISO15118USEDOFOBJECTINFO                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEISO15118_20IDXOFOBJECTINFO                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEISO15118_20USEDOFOBJECTINFO                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEKDF2HMACSHA1IDXOFOBJECTINFO                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEKDF2HMACSHA1USEDOFOBJECTINFO                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEKDF2HMACSHA256IDXOFOBJECTINFO                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEKDF2HMACSHA256USEDOFOBJECTINFO                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVENIST800108CNTIDXOFOBJECTINFO                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVENIST800108CNTUSEDOFOBJECTINFO                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVENIST80056AONEPASSIDXOFOBJECTINFO                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVENIST80056AONEPASSUSEDOFOBJECTINFO                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVENISTFIPS186ERBIDXOFOBJECTINFO                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVENISTFIPS186ERBUSEDOFOBJECTINFO                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVESPAKE2PIDXOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVESPAKE2PUSEDOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEX963SHA256IDXOFOBJECTINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEX963SHA256USEDOFOBJECTINFO                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEX963SHA512IDXOFOBJECTINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEX963SHA512USEDOFOBJECTINFO                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYGENED25519IDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYGENED25519USEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYGENP256R1IDXOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYGENP256R1USEDOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYGENP384R1IDXOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYGENP384R1USEDOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYGENP521R1IDXOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYGENP521R1USEDOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYGENSM2P256V1IDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYGENSM2P256V1USEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYGENSYMGENERICIDXOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYGENSYMGENERICUSEDOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP224R1BDPUBVALIDXOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP224R1BDPUBVALUSEDOFOBJECTINFO                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP224R1BDSECRETIDXOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP224R1BDSECRETUSEDOFOBJECTINFO                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP256R1BDPUBVALIDXOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP256R1BDPUBVALUSEDOFOBJECTINFO                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP256R1BDSECRETIDXOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP256R1BDSECRETUSEDOFOBJECTINFO                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP256R1PUBVALIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP256R1PUBVALUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP256R1SECRETIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP256R1SECRETUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP384R1PUBVALIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP384R1PUBVALUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP384R1SECRETIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP384R1SECRETUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP521R1PUBVALIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP521R1PUBVALUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP521R1SECRETIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP521R1SECRETUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSEEDDRBGAESIDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSEEDDRBGAESUSEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSEEDDRBGHASHSHA512IDXOFOBJECTINFO                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSEEDDRBGHASHSHA512USEDOFOBJECTINFO                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSEEDFIPS186IDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSEEDFIPS186USEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSETINVALIDJOBIDXOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSETINVALIDJOBUSEDOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSETVALIDJOBIDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSETVALIDJOBUSEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSPAKE2PPUBVALIDXOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSPAKE2PPUBVALUSEDOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSPAKE2PSECRETIDXOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSPAKE2PSECRETUSEDOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYX25519PUBVALIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYX25519PUBVALUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYX25519SECRETIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYX25519SECRETUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYX448PUBVALIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYX448PUBVALUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYX448SECRETIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYX448SECRETUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_MD5IDXOFOBJECTINFO                                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_MD5USEDOFOBJECTINFO                                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PARTITIONIDXOFOBJECTINFO                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_QUEUEIDXOFOBJECTINFO                                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RANDOMSEEDBUFFERENDIDXOFOBJECTINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RANDOMSEEDBUFFERUSEDOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPCRTSHA1DECRYPTIDXOFOBJECTINFO                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPCRTSHA1DECRYPTUSEDOFOBJECTINFO                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPCRTSHA256DECRYPTIDXOFOBJECTINFO                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPCRTSHA256DECRYPTUSEDOFOBJECTINFO                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPSHA1DECRYPTIDXOFOBJECTINFO                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPSHA1DECRYPTUSEDOFOBJECTINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPSHA1ENCRYPTIDXOFOBJECTINFO                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPSHA1ENCRYPTUSEDOFOBJECTINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPSHA256DECRYPTIDXOFOBJECTINFO                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPSHA256DECRYPTUSEDOFOBJECTINFO                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPSHA256ENCRYPTIDXOFOBJECTINFO                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPSHA256ENCRYPTUSEDOFOBJECTINFO                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPKCS1CRTGENERATEIDXOFOBJECTINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPKCS1CRTGENERATEUSEDOFOBJECTINFO                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPKCS1DECRYPTIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPKCS1DECRYPTUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPKCS1ENCRYPTIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPKCS1ENCRYPTUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPKCS1GENERATEIDXOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPKCS1GENERATEUSEDOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPKCS1VERIFYIDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPKCS1VERIFYUSEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPSSGENERATEIDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPSSGENERATEUSEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPSSVERIFYIDXOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPSSVERIFYUSEDOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SHECMDGETIDIDXOFOBJECTINFO                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SHECMDGETIDUSEDOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SIPHASHGENERATEIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SIPHASHGENERATEUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SIPHASHVERIFYIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SIPHASHVERIFYUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SLHDSAVERIFYIDXOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SLHDSAVERIFYUSEDOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SM2GENERATEIDXOFOBJECTINFO                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SM2GENERATEUSEDOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SM2VERIFYIDXOFOBJECTINFO                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SM2VERIFYUSEDOFOBJECTINFO                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SM4DECRYPTIDXOFOBJECTINFO                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SM4DECRYPTUSEDOFOBJECTINFO                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SM4ENCRYPTIDXOFOBJECTINFO                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SM4ENCRYPTUSEDOFOBJECTINFO                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEADDROFOBJECTINFO                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACELENGTHOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_OBJECTINFOIND                                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PARTITIONSNVOFPARTITIONIDENTIFIERS                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESOFPARTITIONINFO                                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_DEFAULTRANDOMKEYOFPARTITIONINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HASHOFPARTITIONINFO                                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_MASKEDBITSOFPARTITIONINFO                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_DISPATCHOFPRIMITIVEFCT                                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_OBJECTINFOINDENDIDXOFPRIMITIVEFCT                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_OBJECTINFOINDSTARTIDXOFPRIMITIVEFCT                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_OBJECTINFOINDUSEDOFPRIMITIVEFCT                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_COMBINEDOFPRIMITIVEINFO                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_CONTEXTOFPRIMITIVEINFO                                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_DEFAULTRANDOMSOURCEOFPRIMITIVEINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_MASKEDBITSOFPRIMITIVEINFO                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PRIMITIVEFCTIDXOFPRIMITIVEINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PRIMITIVEINFOUSEDOFPRIMITIVESERVICEINFO                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAOAEPCRTSHA1DECRYPT                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAOAEPCRTSHA256DECRYPT                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAOAEPSHA1DECRYPT                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAOAEPSHA1ENCRYPT                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAOAEPSHA256DECRYPT                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAOAEPSHA256ENCRYPT                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAPKCS1CRTGENERATE                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAPKCS1DECRYPT                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAPKCS1ENCRYPT                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAPKCS1GENERATE                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAPKCS1VERIFY                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAPSSGENERATE                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAPSSVERIFY                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFSHECMDGETID                                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFSIPHASHGENERATE                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFSIPHASHVERIFY                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFSLHDSAVERIFY                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFSM2GENERATE                                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFSM2VERIFY                                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFSM4DECRYPT                                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFSM4ENCRYPT                                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_INITDATAHASHCODEOFPCCONFIG                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PCPARTITIONCONFIGOFPCCONFIG                                           STD_ON
#define CRYPTO_30_LIBCV_ISDEF_PARTITIONIDENTIFIERSOFPCCONFIG                                        STD_ON
#define CRYPTO_30_LIBCV_ISDEF_AEADCHACHAPOLY1305DECRYPTOFPCPARTITIONCONFIG                          STD_ON
#define CRYPTO_30_LIBCV_ISDEF_AEADCHACHAPOLY1305ENCRYPTOFPCPARTITIONCONFIG                          STD_ON
#define CRYPTO_30_LIBCV_ISDEF_AESDECRYPTOFPCPARTITIONCONFIG                                         STD_ON
#define CRYPTO_30_LIBCV_ISDEF_AESENCRYPTOFPCPARTITIONCONFIG                                         STD_ON
#define CRYPTO_30_LIBCV_ISDEF_AESGCMDECRYPTOFPCPARTITIONCONFIG                                      STD_ON
#define CRYPTO_30_LIBCV_ISDEF_AESGCMENCRYPTOFPCPARTITIONCONFIG                                      STD_ON
#define CRYPTO_30_LIBCV_ISDEF_BUFFERLENGTHOFPCPARTITIONCONFIG                                       STD_ON
#define CRYPTO_30_LIBCV_ISDEF_CMACAESGENERATEOFPCPARTITIONCONFIG                                    STD_ON
#define CRYPTO_30_LIBCV_ISDEF_CMACAESVERIFYOFPCPARTITIONCONFIG                                      STD_ON
#define CRYPTO_30_LIBCV_ISDEF_DRBGAESOFPCPARTITIONCONFIG                                            STD_ON
#define CRYPTO_30_LIBCV_ISDEF_DISPATCH_QUEUEPRIMITIVEINFOIDXOFPCPARTITIONCONFIG                     STD_ON
#define CRYPTO_30_LIBCV_ISDEF_DRIVEROBJECTSTATEOFPCPARTITIONCONFIG                                  STD_ON
#define CRYPTO_30_LIBCV_ISDEF_ECP256GENERATEOFPCPARTITIONCONFIG                                     STD_ON
#define CRYPTO_30_LIBCV_ISDEF_ECP256VERIFYOFPCPARTITIONCONFIG                                       STD_ON
#define CRYPTO_30_LIBCV_ISDEF_ECP521GENERATEOFPCPARTITIONCONFIG                                     STD_ON
#define CRYPTO_30_LIBCV_ISDEF_ECP521VERIFYOFPCPARTITIONCONFIG                                       STD_ON
#define CRYPTO_30_LIBCV_ISDEF_ED25519GENERATEOFPCPARTITIONCONFIG                                    STD_ON
#define CRYPTO_30_LIBCV_ISDEF_ED25519VERIFYOFPCPARTITIONCONFIG                                      STD_ON
#define CRYPTO_30_LIBCV_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCPARTITIONCONFIG                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_FAMILYTOHASHMAPPINGOFPCPARTITIONCONFIG                                STD_ON
#define CRYPTO_30_LIBCV_ISDEF_FIPS186OFPCPARTITIONCONFIG                                            STD_ON
#define CRYPTO_30_LIBCV_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCPARTITIONCONFIG                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_GMACAESGENERATEOFPCPARTITIONCONFIG                                    STD_ON
#define CRYPTO_30_LIBCV_ISDEF_GMACAESVERIFYOFPCPARTITIONCONFIG                                      STD_ON
#define CRYPTO_30_LIBCV_ISDEF_HASHOFPCPARTITIONCONFIG                                               STD_ON
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA1GENERATEOFPCPARTITIONCONFIG                                   STD_ON
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA1VERIFYOFPCPARTITIONCONFIG                                     STD_ON
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA256GENERATEOFPCPARTITIONCONFIG                                 STD_ON
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA256VERIFYOFPCPARTITIONCONFIG                                   STD_ON
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA384GENERATEOFPCPARTITIONCONFIG                                 STD_ON
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA384VERIFYOFPCPARTITIONCONFIG                                   STD_ON
#define CRYPTO_30_LIBCV_ISDEF_INITVALUEOFPCPARTITIONCONFIG                                          STD_ON
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEHKDFEXPANDHMACSHA256OFPCPARTITIONCONFIG                      STD_ON
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEHKDFEXPANDHMACSHA384OFPCPARTITIONCONFIG                      STD_ON
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEHKDFHMACSHA256OFPCPARTITIONCONFIG                            STD_ON
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEHKDFHMACSHA384OFPCPARTITIONCONFIG                            STD_ON
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEISO15118OFPCPARTITIONCONFIG                                  STD_ON
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEISO15118_20OFPCPARTITIONCONFIG                               STD_ON
#define CRYPTO_30_LIBCV_ISDEF_KEYELEMENTINFOOFPCPARTITIONCONFIG                                     STD_ON
#define CRYPTO_30_LIBCV_ISDEF_KEYELEMENTSOFPCPARTITIONCONFIG                                        STD_ON
#define CRYPTO_30_LIBCV_ISDEF_KEYGENP256R1OFPCPARTITIONCONFIG                                       STD_ON
#define CRYPTO_30_LIBCV_ISDEF_KEYLOCKOFPCPARTITIONCONFIG                                            STD_ON
#define CRYPTO_30_LIBCV_ISDEF_KEYNVSTATUSOFPCPARTITIONCONFIG                                        STD_ON
#define CRYPTO_30_LIBCV_ISDEF_KEYOFPCPARTITIONCONFIG                                                STD_ON
#define CRYPTO_30_LIBCV_ISDEF_KEYP256R1SECRETOFPCPARTITIONCONFIG                                    STD_ON
#define CRYPTO_30_LIBCV_ISDEF_KEYSTORAGEOFPCPARTITIONCONFIG                                         STD_ON
#define CRYPTO_30_LIBCV_ISDEF_LOCKOFPCPARTITIONCONFIG                                               STD_ON
#define CRYPTO_30_LIBCV_ISDEF_NVBLOCKOFPCPARTITIONCONFIG                                            STD_ON
#define CRYPTO_30_LIBCV_ISDEF_OBJECTINFOINDOFPCPARTITIONCONFIG                                      STD_ON
#define CRYPTO_30_LIBCV_ISDEF_OBJECTINFOOFPCPARTITIONCONFIG                                         STD_ON
#define CRYPTO_30_LIBCV_ISDEF_PARTITIONINFOOFPCPARTITIONCONFIG                                      STD_ON
#define CRYPTO_30_LIBCV_ISDEF_PARTITIONINITIALIZEDOFPCPARTITIONCONFIG                               STD_ON
#define CRYPTO_30_LIBCV_ISDEF_PRIMITIVEFCTOFPCPARTITIONCONFIG                                       STD_ON
#define CRYPTO_30_LIBCV_ISDEF_PRIMITIVEINFOOFPCPARTITIONCONFIG                                      STD_ON
#define CRYPTO_30_LIBCV_ISDEF_PRIMITIVESERVICEINFOOFPCPARTITIONCONFIG                               STD_ON
#define CRYPTO_30_LIBCV_ISDEF_PROCESSJOB_TRIGGER_WRITEOFPCPARTITIONCONFIG                           STD_ON
#define CRYPTO_30_LIBCV_ISDEF_QUEUEOFPCPARTITIONCONFIG                                              STD_ON
#define CRYPTO_30_LIBCV_ISDEF_RANDOMSEEDBUFFEROFPCPARTITIONCONFIG                                   STD_ON
#define CRYPTO_30_LIBCV_ISDEF_RANDOMSOURCEGENERATECOUNTOFPCPARTITIONCONFIG                          STD_ON
#define CRYPTO_30_LIBCV_ISDEF_REDIRECT_BUFFEROFPCPARTITIONCONFIG                                    STD_ON
#define CRYPTO_30_LIBCV_ISDEF_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN0OFPCPARTITIONCONFIG         STD_ON
#define CRYPTO_30_LIBCV_ISDEF_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN0_HS_HASHSHA256_FINISHEDOFPCPARTITIONCONFIG STD_ON
#define CRYPTO_30_LIBCV_ISDEF_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1OFPCPARTITIONCONFIG         STD_ON
#define CRYPTO_30_LIBCV_ISDEF_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HS_HASHSHA256_FINISHEDOFPCPARTITIONCONFIG STD_ON
#define CRYPTO_30_LIBCV_ISDEF_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HS_HASHSHA384OFPCPARTITIONCONFIG STD_ON
#define CRYPTO_30_LIBCV_ISDEF_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HKDF_SHA384OFPCPARTITIONCONFIG STD_ON
#define CRYPTO_30_LIBCV_ISDEF_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_GLOBAL_HASHSHA1OFPCPARTITIONCONFIG STD_ON
#define CRYPTO_30_LIBCV_ISDEF_STRUCTUNIONWS_CRYPTO_30_LIBCVOFPCPARTITIONCONFIG                      STD_ON
#define CRYPTO_30_LIBCV_ISDEF_STRUCTUNIONWS_CRYPTO_30_LIBCV_GENERALOFPCPARTITIONCONFIG              STD_ON
#define CRYPTO_30_LIBCV_ISDEF_WRITTENLENGTHOFPCPARTITIONCONFIG                                      STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCEqualsAlwaysToDefines  Crypto_30_LibCv Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFAEADCHACHAPOLY1305DECRYPT                                    
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFAEADCHACHAPOLY1305ENCRYPT                                    
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFAESCCMDECRYPT                                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFAESCCMENCRYPT                                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFAESDECRYPT                                                   
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFAESENCRYPT                                                   
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFAESGCMDECRYPT                                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFAESGCMENCRYPT                                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFCMACAESGENERATE                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFCMACAESVERIFY                                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFDRBGAES                                                      
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFDRBGHASHSHA512                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFECP160GENERATE                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFECP160VERIFY                                                 
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFECP256GENERATE                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFECP256VERIFY                                                 
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFECP384GENERATE                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFECP384VERIFY                                                 
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFECP521GENERATE                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFECP521VERIFY                                                 
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFECPKEYCHECK                                                  
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFED25519GENERATE                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFED25519VERIFY                                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFED448GENERATE                                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFED448VERIFY                                                  
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFEDKEYCHECK                                                   
#define CRYPTO_30_LIBCV_EQ2_FAMILYTOHASHMAPPING                                                     
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFFIPS186                                                      
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFGMACAESGENERATE                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFGMACAESVERIFY                                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFHASH                                                         
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFHMACRIPEMD160GENERATE                                        
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFHMACRIPEMD160VERIFY                                          
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFHMACSHA1GENERATE                                             
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFHMACSHA1VERIFY                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFHMACSHA256GENERATE                                           
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFHMACSHA256VERIFY                                             
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFHMACSHA384GENERATE                                           
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFHMACSHA384VERIFY                                             
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFHMACSHA512GENERATE                                           
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFHMACSHA512VERIFY                                             
#define CRYPTO_30_LIBCV_EQ2_INITVALUE                                                               
#define CRYPTO_30_LIBCV_EQ2_KEYELEMENTSENDIDXOFKEY                                                  
#define CRYPTO_30_LIBCV_EQ2_KEYELEMENTSSTARTIDXOFKEY                                                
#define CRYPTO_30_LIBCV_EQ2_NVBLOCKIDXOFKEY                                                         
#define CRYPTO_30_LIBCV_EQ2_NVBLOCKUSEDOFKEY                                                        
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVEHKDFEXPANDHMACSHA256                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVEHKDFEXPANDHMACSHA384                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVEHKDFHMACSHA256                                      
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVEHKDFHMACSHA384                                      
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVEHKDFHASHOPTION1SHA256                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVEHKDFHASHOPTION1SHA512                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVEISO15118                                            
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVEISO15118_20                                         
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVEKDF2HMACSHA1                                        
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVEKDF2HMACSHA256                                      
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVENIST800108CNT                                       
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVENIST80056AONEPASS                                   
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVENISTFIPS186ERB                                      
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVESPAKE2P                                             
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVEX963SHA256                                          
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVEX963SHA512                                          
#define CRYPTO_30_LIBCV_EQ2_IDOFKEYELEMENTINFO                                                      
#define CRYPTO_30_LIBCV_EQ2_INITVALUEENDIDXOFKEYELEMENTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_INITVALUESTARTIDXOFKEYELEMENTINFO                                       
#define CRYPTO_30_LIBCV_EQ2_INITVALUEUSEDOFKEYELEMENTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_LENGTHOFKEYELEMENTINFO                                                  
#define CRYPTO_30_LIBCV_EQ2_MASKEDBITSOFKEYELEMENTINFO                                              
#define CRYPTO_30_LIBCV_EQ2_ONCEOFKEYELEMENTINFO                                                    
#define CRYPTO_30_LIBCV_EQ2_PARTIALOFKEYELEMENTINFO                                                 
#define CRYPTO_30_LIBCV_EQ2_PERSISTOFKEYELEMENTINFO                                                 
#define CRYPTO_30_LIBCV_EQ2_READOFKEYELEMENTINFO                                                    
#define CRYPTO_30_LIBCV_EQ2_WRITEOFKEYELEMENTINFO                                                   
#define CRYPTO_30_LIBCV_EQ2_IDOFKEYELEMENTS                                                         
#define CRYPTO_30_LIBCV_EQ2_KEYELEMENTINFOIDXOFKEYELEMENTS                                          
#define CRYPTO_30_LIBCV_EQ2_KEYSTORAGEENDIDXOFKEYELEMENTS                                           
#define CRYPTO_30_LIBCV_EQ2_KEYSTORAGEEXTENSIONIDXOFKEYELEMENTS                                     
#define CRYPTO_30_LIBCV_EQ2_KEYSTORAGESTARTIDXOFKEYELEMENTS                                         
#define CRYPTO_30_LIBCV_EQ2_KEYSTORAGEVALIDIDXOFKEYELEMENTS                                         
#define CRYPTO_30_LIBCV_EQ2_KEYSTORAGEWRITTENLENGTHENDIDXOFKEYELEMENTS                              
#define CRYPTO_30_LIBCV_EQ2_KEYSTORAGEWRITTENLENGTHSTARTIDXOFKEYELEMENTS                            
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYGENED25519                                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYGENP256R1                                                 
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYGENP384R1                                                 
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYGENP521R1                                                 
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYGENSM2P256V1                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYGENSYMGENERIC                                             
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYP224R1BDPUBVAL                                            
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYP224R1BDSECRET                                            
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYP256R1BDPUBVAL                                            
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYP256R1BDSECRET                                            
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYP256R1PUBVAL                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYP256R1SECRET                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYP384R1PUBVAL                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYP384R1SECRET                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYP521R1PUBVAL                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYP521R1SECRET                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYSEEDDRBGAES                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYSEEDDRBGHASHSHA512                                        
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYSEEDFIPS186                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYSETINVALIDJOB                                             
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYSETVALIDJOB                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYSPAKE2PPUBVAL                                             
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYSPAKE2PSECRET                                             
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYX25519PUBVAL                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYX25519SECRET                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYX448PUBVAL                                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYX448SECRET                                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFMD5                                                          
#define CRYPTO_30_LIBCV_EQ2_CONSISTENCYLEVELOFNVBLOCK                                               
#define CRYPTO_30_LIBCV_EQ2_CRCOFNVBLOCK                                                            
#define CRYPTO_30_LIBCV_EQ2_DESCRIPTOROFNVBLOCK                                                     
#define CRYPTO_30_LIBCV_EQ2_IDOFNVBLOCK                                                             
#define CRYPTO_30_LIBCV_EQ2_KEYSTORAGEENDIDXOFNVBLOCK                                               
#define CRYPTO_30_LIBCV_EQ2_KEYSTORAGESTARTIDXOFNVBLOCK                                             
#define CRYPTO_30_LIBCV_EQ2_LENGTHOFNVBLOCK                                                         
#define CRYPTO_30_LIBCV_EQ2_PROCESSINGOFNVBLOCK                                                     
#define CRYPTO_30_LIBCV_EQ2_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO                                
#define CRYPTO_30_LIBCV_EQ2_AEADCHACHAPOLY1305DECRYPTUSEDOFOBJECTINFO                               
#define CRYPTO_30_LIBCV_EQ2_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO                                
#define CRYPTO_30_LIBCV_EQ2_AEADCHACHAPOLY1305ENCRYPTUSEDOFOBJECTINFO                               
#define CRYPTO_30_LIBCV_EQ2_AESCCMDECRYPTIDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_AESCCMDECRYPTUSEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_AESCCMENCRYPTIDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_AESCCMENCRYPTUSEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_AESDECRYPTIDXOFOBJECTINFO                                               
#define CRYPTO_30_LIBCV_EQ2_AESDECRYPTUSEDOFOBJECTINFO                                              
#define CRYPTO_30_LIBCV_EQ2_AESENCRYPTIDXOFOBJECTINFO                                               
#define CRYPTO_30_LIBCV_EQ2_AESENCRYPTUSEDOFOBJECTINFO                                              
#define CRYPTO_30_LIBCV_EQ2_AESGCMDECRYPTIDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_AESGCMDECRYPTUSEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_AESGCMENCRYPTIDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_AESGCMENCRYPTUSEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_APPLICATIONIDOFOBJECTINFO                                               
#define CRYPTO_30_LIBCV_EQ2_CMACAESGENERATEIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_CMACAESGENERATEUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_CMACAESVERIFYIDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_CMACAESVERIFYUSEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_DRBGAESIDXOFOBJECTINFO                                                  
#define CRYPTO_30_LIBCV_EQ2_DRBGAESUSEDOFOBJECTINFO                                                 
#define CRYPTO_30_LIBCV_EQ2_DRBGHASHSHA512IDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_DRBGHASHSHA512USEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_ECP160GENERATEIDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_ECP160GENERATEUSEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_ECP160VERIFYIDXOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_ECP160VERIFYUSEDOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_ECP256GENERATEIDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_ECP256GENERATEUSEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_ECP256VERIFYIDXOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_ECP256VERIFYUSEDOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_ECP384GENERATEIDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_ECP384GENERATEUSEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_ECP384VERIFYIDXOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_ECP384VERIFYUSEDOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_ECP521GENERATEIDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_ECP521GENERATEUSEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_ECP521VERIFYIDXOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_ECP521VERIFYUSEDOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_ECPKEYCHECKIDXOFOBJECTINFO                                              
#define CRYPTO_30_LIBCV_EQ2_ECPKEYCHECKUSEDOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_ED25519GENERATEIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_ED25519GENERATEUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_ED25519VERIFYIDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_ED25519VERIFYUSEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_ED448GENERATEIDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_ED448GENERATEUSEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_ED448VERIFYIDXOFOBJECTINFO                                              
#define CRYPTO_30_LIBCV_EQ2_ED448VERIFYUSEDOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_EDKEYCHECKIDXOFOBJECTINFO                                               
#define CRYPTO_30_LIBCV_EQ2_EDKEYCHECKUSEDOFOBJECTINFO                                              
#define CRYPTO_30_LIBCV_EQ2_FIPS186IDXOFOBJECTINFO                                                  
#define CRYPTO_30_LIBCV_EQ2_FIPS186USEDOFOBJECTINFO                                                 
#define CRYPTO_30_LIBCV_EQ2_GMACAESGENERATEIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_GMACAESGENERATEUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_GMACAESVERIFYIDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_GMACAESVERIFYUSEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_HASHIDXOFOBJECTINFO                                                     
#define CRYPTO_30_LIBCV_EQ2_HASHUSEDOFOBJECTINFO                                                    
#define CRYPTO_30_LIBCV_EQ2_HMACRIPEMD160GENERATEIDXOFOBJECTINFO                                    
#define CRYPTO_30_LIBCV_EQ2_HMACRIPEMD160GENERATEUSEDOFOBJECTINFO                                   
#define CRYPTO_30_LIBCV_EQ2_HMACRIPEMD160VERIFYIDXOFOBJECTINFO                                      
#define CRYPTO_30_LIBCV_EQ2_HMACRIPEMD160VERIFYUSEDOFOBJECTINFO                                     
#define CRYPTO_30_LIBCV_EQ2_HMACSHA1GENERATEIDXOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_HMACSHA1GENERATEUSEDOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_HMACSHA1VERIFYIDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_HMACSHA1VERIFYUSEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_HMACSHA256GENERATEIDXOFOBJECTINFO                                       
#define CRYPTO_30_LIBCV_EQ2_HMACSHA256GENERATEUSEDOFOBJECTINFO                                      
#define CRYPTO_30_LIBCV_EQ2_HMACSHA256VERIFYIDXOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_HMACSHA256VERIFYUSEDOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_HMACSHA384GENERATEIDXOFOBJECTINFO                                       
#define CRYPTO_30_LIBCV_EQ2_HMACSHA384GENERATEUSEDOFOBJECTINFO                                      
#define CRYPTO_30_LIBCV_EQ2_HMACSHA384VERIFYIDXOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_HMACSHA384VERIFYUSEDOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_HMACSHA512GENERATEIDXOFOBJECTINFO                                       
#define CRYPTO_30_LIBCV_EQ2_HMACSHA512GENERATEUSEDOFOBJECTINFO                                      
#define CRYPTO_30_LIBCV_EQ2_HMACSHA512VERIFYIDXOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_HMACSHA512VERIFYUSEDOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEHKDFEXPANDHMACSHA256IDXOFOBJECTINFO                            
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEHKDFEXPANDHMACSHA256USEDOFOBJECTINFO                           
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEHKDFEXPANDHMACSHA384IDXOFOBJECTINFO                            
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEHKDFEXPANDHMACSHA384USEDOFOBJECTINFO                           
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEHKDFHMACSHA256IDXOFOBJECTINFO                                  
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEHKDFHMACSHA256USEDOFOBJECTINFO                                 
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEHKDFHMACSHA384IDXOFOBJECTINFO                                  
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEHKDFHMACSHA384USEDOFOBJECTINFO                                 
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEHKDFHASHOPTION1SHA256IDXOFOBJECTINFO                           
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEHKDFHASHOPTION1SHA256USEDOFOBJECTINFO                          
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEHKDFHASHOPTION1SHA512IDXOFOBJECTINFO                           
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEHKDFHASHOPTION1SHA512USEDOFOBJECTINFO                          
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEISO15118IDXOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEISO15118USEDOFOBJECTINFO                                       
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEISO15118_20IDXOFOBJECTINFO                                     
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEISO15118_20USEDOFOBJECTINFO                                    
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEKDF2HMACSHA1IDXOFOBJECTINFO                                    
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEKDF2HMACSHA1USEDOFOBJECTINFO                                   
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEKDF2HMACSHA256IDXOFOBJECTINFO                                  
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEKDF2HMACSHA256USEDOFOBJECTINFO                                 
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVENIST800108CNTIDXOFOBJECTINFO                                   
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVENIST800108CNTUSEDOFOBJECTINFO                                  
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVENIST80056AONEPASSIDXOFOBJECTINFO                               
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVENIST80056AONEPASSUSEDOFOBJECTINFO                              
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVENISTFIPS186ERBIDXOFOBJECTINFO                                  
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVENISTFIPS186ERBUSEDOFOBJECTINFO                                 
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVESPAKE2PIDXOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVESPAKE2PUSEDOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEX963SHA256IDXOFOBJECTINFO                                      
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEX963SHA256USEDOFOBJECTINFO                                     
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEX963SHA512IDXOFOBJECTINFO                                      
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEX963SHA512USEDOFOBJECTINFO                                     
#define CRYPTO_30_LIBCV_EQ2_KEYGENED25519IDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_KEYGENED25519USEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_KEYGENP256R1IDXOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_KEYGENP256R1USEDOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_KEYGENP384R1IDXOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_KEYGENP384R1USEDOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_KEYGENP521R1IDXOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_KEYGENP521R1USEDOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_KEYGENSM2P256V1IDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYGENSM2P256V1USEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYGENSYMGENERICIDXOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYGENSYMGENERICUSEDOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_KEYP224R1BDPUBVALIDXOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_KEYP224R1BDPUBVALUSEDOFOBJECTINFO                                       
#define CRYPTO_30_LIBCV_EQ2_KEYP224R1BDSECRETIDXOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_KEYP224R1BDSECRETUSEDOFOBJECTINFO                                       
#define CRYPTO_30_LIBCV_EQ2_KEYP256R1BDPUBVALIDXOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_KEYP256R1BDPUBVALUSEDOFOBJECTINFO                                       
#define CRYPTO_30_LIBCV_EQ2_KEYP256R1BDSECRETIDXOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_KEYP256R1BDSECRETUSEDOFOBJECTINFO                                       
#define CRYPTO_30_LIBCV_EQ2_KEYP256R1PUBVALIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYP256R1PUBVALUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYP256R1SECRETIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYP256R1SECRETUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYP384R1PUBVALIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYP384R1PUBVALUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYP384R1SECRETIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYP384R1SECRETUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYP521R1PUBVALIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYP521R1PUBVALUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYP521R1SECRETIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYP521R1SECRETUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYSEEDDRBGAESIDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_KEYSEEDDRBGAESUSEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYSEEDDRBGHASHSHA512IDXOFOBJECTINFO                                    
#define CRYPTO_30_LIBCV_EQ2_KEYSEEDDRBGHASHSHA512USEDOFOBJECTINFO                                   
#define CRYPTO_30_LIBCV_EQ2_KEYSEEDFIPS186IDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_KEYSEEDFIPS186USEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYSETINVALIDJOBIDXOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYSETINVALIDJOBUSEDOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_KEYSETVALIDJOBIDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_KEYSETVALIDJOBUSEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYSPAKE2PPUBVALIDXOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYSPAKE2PPUBVALUSEDOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_KEYSPAKE2PSECRETIDXOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYSPAKE2PSECRETUSEDOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_KEYX25519PUBVALIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYX25519PUBVALUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYX25519SECRETIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYX25519SECRETUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYX448PUBVALIDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_KEYX448PUBVALUSEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_KEYX448SECRETIDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_KEYX448SECRETUSEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_MD5IDXOFOBJECTINFO                                                      
#define CRYPTO_30_LIBCV_EQ2_MD5USEDOFOBJECTINFO                                                     
#define CRYPTO_30_LIBCV_EQ2_PARTITIONIDXOFOBJECTINFO                                                
#define CRYPTO_30_LIBCV_EQ2_QUEUEIDXOFOBJECTINFO                                                    
#define CRYPTO_30_LIBCV_EQ2_RANDOMSEEDBUFFERENDIDXOFOBJECTINFO                                      
#define CRYPTO_30_LIBCV_EQ2_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO                                    
#define CRYPTO_30_LIBCV_EQ2_RANDOMSEEDBUFFERUSEDOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPCRTSHA1DECRYPTIDXOFOBJECTINFO                                    
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPCRTSHA1DECRYPTUSEDOFOBJECTINFO                                   
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPCRTSHA256DECRYPTIDXOFOBJECTINFO                                  
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPCRTSHA256DECRYPTUSEDOFOBJECTINFO                                 
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPSHA1DECRYPTIDXOFOBJECTINFO                                       
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPSHA1DECRYPTUSEDOFOBJECTINFO                                      
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPSHA1ENCRYPTIDXOFOBJECTINFO                                       
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPSHA1ENCRYPTUSEDOFOBJECTINFO                                      
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPSHA256DECRYPTIDXOFOBJECTINFO                                     
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPSHA256DECRYPTUSEDOFOBJECTINFO                                    
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPSHA256ENCRYPTIDXOFOBJECTINFO                                     
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPSHA256ENCRYPTUSEDOFOBJECTINFO                                    
#define CRYPTO_30_LIBCV_EQ2_RSAPKCS1CRTGENERATEIDXOFOBJECTINFO                                      
#define CRYPTO_30_LIBCV_EQ2_RSAPKCS1CRTGENERATEUSEDOFOBJECTINFO                                     
#define CRYPTO_30_LIBCV_EQ2_RSAPKCS1DECRYPTIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_RSAPKCS1DECRYPTUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_RSAPKCS1ENCRYPTIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_RSAPKCS1ENCRYPTUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_RSAPKCS1GENERATEIDXOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_RSAPKCS1GENERATEUSEDOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_RSAPKCS1VERIFYIDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_RSAPKCS1VERIFYUSEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_RSAPSSGENERATEIDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_RSAPSSGENERATEUSEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_RSAPSSVERIFYIDXOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_RSAPSSVERIFYUSEDOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_SHECMDGETIDIDXOFOBJECTINFO                                              
#define CRYPTO_30_LIBCV_EQ2_SHECMDGETIDUSEDOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_SIPHASHGENERATEIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_SIPHASHGENERATEUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_SIPHASHVERIFYIDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_SIPHASHVERIFYUSEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_SLHDSAVERIFYIDXOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_SLHDSAVERIFYUSEDOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_SM2GENERATEIDXOFOBJECTINFO                                              
#define CRYPTO_30_LIBCV_EQ2_SM2GENERATEUSEDOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_SM2VERIFYIDXOFOBJECTINFO                                                
#define CRYPTO_30_LIBCV_EQ2_SM2VERIFYUSEDOFOBJECTINFO                                               
#define CRYPTO_30_LIBCV_EQ2_SM4DECRYPTIDXOFOBJECTINFO                                               
#define CRYPTO_30_LIBCV_EQ2_SM4DECRYPTUSEDOFOBJECTINFO                                              
#define CRYPTO_30_LIBCV_EQ2_SM4ENCRYPTIDXOFOBJECTINFO                                               
#define CRYPTO_30_LIBCV_EQ2_SM4ENCRYPTUSEDOFOBJECTINFO                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEADDROFOBJECTINFO                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACELENGTHOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_OBJECTINFOIND                                                           
#define CRYPTO_30_LIBCV_EQ2_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                              
#define CRYPTO_30_LIBCV_EQ2_PARTITIONSNVOFPARTITIONIDENTIFIERS                                      
#define CRYPTO_30_LIBCV_EQ2_AESOFPARTITIONINFO                                                      
#define CRYPTO_30_LIBCV_EQ2_DEFAULTRANDOMKEYOFPARTITIONINFO                                         
#define CRYPTO_30_LIBCV_EQ2_HASHOFPARTITIONINFO                                                     
#define CRYPTO_30_LIBCV_EQ2_MASKEDBITSOFPARTITIONINFO                                               
#define CRYPTO_30_LIBCV_EQ2_DISPATCHOFPRIMITIVEFCT                                                  
#define CRYPTO_30_LIBCV_EQ2_OBJECTINFOINDENDIDXOFPRIMITIVEFCT                                       
#define CRYPTO_30_LIBCV_EQ2_OBJECTINFOINDSTARTIDXOFPRIMITIVEFCT                                     
#define CRYPTO_30_LIBCV_EQ2_OBJECTINFOINDUSEDOFPRIMITIVEFCT                                         
#define CRYPTO_30_LIBCV_EQ2_COMBINEDOFPRIMITIVEINFO                                                 
#define CRYPTO_30_LIBCV_EQ2_CONTEXTOFPRIMITIVEINFO                                                  
#define CRYPTO_30_LIBCV_EQ2_DEFAULTRANDOMSOURCEOFPRIMITIVEINFO                                      
#define CRYPTO_30_LIBCV_EQ2_MASKEDBITSOFPRIMITIVEINFO                                               
#define CRYPTO_30_LIBCV_EQ2_PRIMITIVEFCTIDXOFPRIMITIVEINFO                                          
#define CRYPTO_30_LIBCV_EQ2_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO                               
#define CRYPTO_30_LIBCV_EQ2_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO                             
#define CRYPTO_30_LIBCV_EQ2_PRIMITIVEINFOUSEDOFPRIMITIVESERVICEINFO                                 
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAOAEPCRTSHA1DECRYPT                                        
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAOAEPCRTSHA256DECRYPT                                      
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAOAEPSHA1DECRYPT                                           
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAOAEPSHA1ENCRYPT                                           
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAOAEPSHA256DECRYPT                                         
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAOAEPSHA256ENCRYPT                                         
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAPKCS1CRTGENERATE                                          
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAPKCS1DECRYPT                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAPKCS1ENCRYPT                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAPKCS1GENERATE                                             
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAPKCS1VERIFY                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAPSSGENERATE                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAPSSVERIFY                                                 
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFSHECMDGETID                                                  
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFSIPHASHGENERATE                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFSIPHASHVERIFY                                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFSLHDSAVERIFY                                                 
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFSM2GENERATE                                                  
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFSM2VERIFY                                                    
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFSM4DECRYPT                                                   
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFSM4ENCRYPT                                                   
#define CRYPTO_30_LIBCV_EQ2_FINALMAGICNUMBEROFPCCONFIG                                              
#define CRYPTO_30_LIBCV_EQ2_INITDATAHASHCODEOFPCCONFIG                                              
#define CRYPTO_30_LIBCV_EQ2_PCPARTITIONCONFIGOFPCCONFIG                                             Crypto_30_LibCv_PCPartitionConfig
#define CRYPTO_30_LIBCV_EQ2_PARTITIONIDENTIFIERSOFPCCONFIG                                          Crypto_30_LibCv_PartitionIdentifiers
#define CRYPTO_30_LIBCV_EQ2_AEADCHACHAPOLY1305DECRYPTOFPCPARTITIONCONFIG                            Crypto_30_LibCv_AEADChaChaPoly1305Decrypt
#define CRYPTO_30_LIBCV_EQ2_AEADCHACHAPOLY1305ENCRYPTOFPCPARTITIONCONFIG                            Crypto_30_LibCv_AEADChaChaPoly1305Encrypt
#define CRYPTO_30_LIBCV_EQ2_AESDECRYPTOFPCPARTITIONCONFIG                                           Crypto_30_LibCv_AesDecrypt
#define CRYPTO_30_LIBCV_EQ2_AESENCRYPTOFPCPARTITIONCONFIG                                           Crypto_30_LibCv_AesEncrypt
#define CRYPTO_30_LIBCV_EQ2_AESGCMDECRYPTOFPCPARTITIONCONFIG                                        Crypto_30_LibCv_AesGcmDecrypt
#define CRYPTO_30_LIBCV_EQ2_AESGCMENCRYPTOFPCPARTITIONCONFIG                                        Crypto_30_LibCv_AesGcmEncrypt
#define CRYPTO_30_LIBCV_EQ2_BUFFERLENGTHOFPCPARTITIONCONFIG                                         Crypto_30_LibCv_BufferLength
#define CRYPTO_30_LIBCV_EQ2_CMACAESGENERATEOFPCPARTITIONCONFIG                                      Crypto_30_LibCv_CmacAesGenerate
#define CRYPTO_30_LIBCV_EQ2_CMACAESVERIFYOFPCPARTITIONCONFIG                                        Crypto_30_LibCv_CmacAesVerify
#define CRYPTO_30_LIBCV_EQ2_DRBGAESOFPCPARTITIONCONFIG                                              Crypto_30_LibCv_DRBGAES
#define CRYPTO_30_LIBCV_EQ2_DISPATCH_QUEUEPRIMITIVEINFOIDXOFPCPARTITIONCONFIG                       Crypto_30_LibCv_Dispatch_QueuePrimitiveInfoIdx
#define CRYPTO_30_LIBCV_EQ2_DRIVEROBJECTSTATEOFPCPARTITIONCONFIG                                    Crypto_30_LibCv_DriverObjectState
#define CRYPTO_30_LIBCV_EQ2_ECP256GENERATEOFPCPARTITIONCONFIG                                       Crypto_30_LibCv_EcP256Generate
#define CRYPTO_30_LIBCV_EQ2_ECP256VERIFYOFPCPARTITIONCONFIG                                         Crypto_30_LibCv_EcP256Verify
#define CRYPTO_30_LIBCV_EQ2_ECP521GENERATEOFPCPARTITIONCONFIG                                       Crypto_30_LibCv_EcP521Generate
#define CRYPTO_30_LIBCV_EQ2_ECP521VERIFYOFPCPARTITIONCONFIG                                         Crypto_30_LibCv_EcP521Verify
#define CRYPTO_30_LIBCV_EQ2_ED25519GENERATEOFPCPARTITIONCONFIG                                      Crypto_30_LibCv_Ed25519Generate
#define CRYPTO_30_LIBCV_EQ2_ED25519VERIFYOFPCPARTITIONCONFIG                                        Crypto_30_LibCv_Ed25519Verify
#define CRYPTO_30_LIBCV_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCPARTITIONCONFIG                         
#define CRYPTO_30_LIBCV_EQ2_FAMILYTOHASHMAPPINGOFPCPARTITIONCONFIG                                  Crypto_30_LibCv_FamilyToHashMapping
#define CRYPTO_30_LIBCV_EQ2_FIPS186OFPCPARTITIONCONFIG                                              Crypto_30_LibCv_Fips186
#define CRYPTO_30_LIBCV_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCPARTITIONCONFIG                        
#define CRYPTO_30_LIBCV_EQ2_GMACAESGENERATEOFPCPARTITIONCONFIG                                      Crypto_30_LibCv_GmacAesGenerate
#define CRYPTO_30_LIBCV_EQ2_GMACAESVERIFYOFPCPARTITIONCONFIG                                        Crypto_30_LibCv_GmacAesVerify
#define CRYPTO_30_LIBCV_EQ2_HASHOFPCPARTITIONCONFIG                                                 Crypto_30_LibCv_Hash
#define CRYPTO_30_LIBCV_EQ2_HMACSHA1GENERATEOFPCPARTITIONCONFIG                                     Crypto_30_LibCv_HmacSha1Generate
#define CRYPTO_30_LIBCV_EQ2_HMACSHA1VERIFYOFPCPARTITIONCONFIG                                       Crypto_30_LibCv_HmacSha1Verify
#define CRYPTO_30_LIBCV_EQ2_HMACSHA256GENERATEOFPCPARTITIONCONFIG                                   Crypto_30_LibCv_HmacSha256Generate
#define CRYPTO_30_LIBCV_EQ2_HMACSHA256VERIFYOFPCPARTITIONCONFIG                                     Crypto_30_LibCv_HmacSha256Verify
#define CRYPTO_30_LIBCV_EQ2_HMACSHA384GENERATEOFPCPARTITIONCONFIG                                   Crypto_30_LibCv_HmacSha384Generate
#define CRYPTO_30_LIBCV_EQ2_HMACSHA384VERIFYOFPCPARTITIONCONFIG                                     Crypto_30_LibCv_HmacSha384Verify
#define CRYPTO_30_LIBCV_EQ2_INITVALUEOFPCPARTITIONCONFIG                                            Crypto_30_LibCv_InitValue
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEHKDFEXPANDHMACSHA256OFPCPARTITIONCONFIG                        Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEHKDFEXPANDHMACSHA384OFPCPARTITIONCONFIG                        Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEHKDFHMACSHA256OFPCPARTITIONCONFIG                              Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEHKDFHMACSHA384OFPCPARTITIONCONFIG                              Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEISO15118OFPCPARTITIONCONFIG                                    Crypto_30_LibCv_KeyDeriveISO15118
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEISO15118_20OFPCPARTITIONCONFIG                                 Crypto_30_LibCv_KeyDeriveISO15118_20
#define CRYPTO_30_LIBCV_EQ2_KEYELEMENTINFOOFPCPARTITIONCONFIG                                       Crypto_30_LibCv_KeyElementInfo
#define CRYPTO_30_LIBCV_EQ2_KEYELEMENTSOFPCPARTITIONCONFIG                                          Crypto_30_LibCv_KeyElements
#define CRYPTO_30_LIBCV_EQ2_KEYGENP256R1OFPCPARTITIONCONFIG                                         Crypto_30_LibCv_KeyGenP256R1
#define CRYPTO_30_LIBCV_EQ2_KEYLOCKOFPCPARTITIONCONFIG                                              Crypto_30_LibCv_KeyLock.raw
#define CRYPTO_30_LIBCV_EQ2_KEYNVSTATUSOFPCPARTITIONCONFIG                                          Crypto_30_LibCv_KeyNvStatus.raw
#define CRYPTO_30_LIBCV_EQ2_KEYOFPCPARTITIONCONFIG                                                  Crypto_30_LibCv_Key
#define CRYPTO_30_LIBCV_EQ2_KEYP256R1SECRETOFPCPARTITIONCONFIG                                      Crypto_30_LibCv_KeyP256R1Secret
#define CRYPTO_30_LIBCV_EQ2_KEYSTORAGEOFPCPARTITIONCONFIG                                           Crypto_30_LibCv_KeyStorage
#define CRYPTO_30_LIBCV_EQ2_LOCKOFPCPARTITIONCONFIG                                                 Crypto_30_LibCv_Lock
#define CRYPTO_30_LIBCV_EQ2_NVBLOCKOFPCPARTITIONCONFIG                                              Crypto_30_LibCv_NvBlock
#define CRYPTO_30_LIBCV_EQ2_OBJECTINFOINDOFPCPARTITIONCONFIG                                        Crypto_30_LibCv_ObjectInfoInd
#define CRYPTO_30_LIBCV_EQ2_OBJECTINFOOFPCPARTITIONCONFIG                                           Crypto_30_LibCv_ObjectInfo
#define CRYPTO_30_LIBCV_EQ2_PARTITIONINFOOFPCPARTITIONCONFIG                                        Crypto_30_LibCv_PartitionInfo
#define CRYPTO_30_LIBCV_EQ2_PARTITIONINITIALIZEDOFPCPARTITIONCONFIG                                 (&(Crypto_30_LibCv_PartitionInitialized))
#define CRYPTO_30_LIBCV_EQ2_PRIMITIVEFCTOFPCPARTITIONCONFIG                                         Crypto_30_LibCv_PrimitiveFct
#define CRYPTO_30_LIBCV_EQ2_PRIMITIVEINFOOFPCPARTITIONCONFIG                                        Crypto_30_LibCv_PrimitiveInfo
#define CRYPTO_30_LIBCV_EQ2_PRIMITIVESERVICEINFOOFPCPARTITIONCONFIG                                 Crypto_30_LibCv_PrimitiveServiceInfo
#define CRYPTO_30_LIBCV_EQ2_PROCESSJOB_TRIGGER_WRITEOFPCPARTITIONCONFIG                             Crypto_30_LibCv_ProcessJob_Trigger_Write
#define CRYPTO_30_LIBCV_EQ2_QUEUEOFPCPARTITIONCONFIG                                                Crypto_30_LibCv_Queue.raw
#define CRYPTO_30_LIBCV_EQ2_RANDOMSEEDBUFFEROFPCPARTITIONCONFIG                                     Crypto_30_LibCv_RandomSeedBuffer.raw
#define CRYPTO_30_LIBCV_EQ2_RANDOMSOURCEGENERATECOUNTOFPCPARTITIONCONFIG                            (&(Crypto_30_LibCv_RandomSourceGenerateCount))
#define CRYPTO_30_LIBCV_EQ2_REDIRECT_BUFFEROFPCPARTITIONCONFIG                                      Crypto_30_LibCv_Redirect_Buffer
#define CRYPTO_30_LIBCV_EQ2_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN0OFPCPARTITIONCONFIG           Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0
#define CRYPTO_30_LIBCV_EQ2_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN0_HS_HASHSHA256_FINISHEDOFPCPARTITIONCONFIG Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished
#define CRYPTO_30_LIBCV_EQ2_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1OFPCPARTITIONCONFIG           Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1
#define CRYPTO_30_LIBCV_EQ2_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HS_HASHSHA256_FINISHEDOFPCPARTITIONCONFIG Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished
#define CRYPTO_30_LIBCV_EQ2_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HS_HASHSHA384OFPCPARTITIONCONFIG Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384
#define CRYPTO_30_LIBCV_EQ2_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_CONN1_HKDF_SHA384OFPCPARTITIONCONFIG Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384
#define CRYPTO_30_LIBCV_EQ2_STRUCTUNIONWS_CRYPTODRIVEROBJECT_TLS_GLOBAL_HASHSHA1OFPCPARTITIONCONFIG Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1
#define CRYPTO_30_LIBCV_EQ2_STRUCTUNIONWS_CRYPTO_30_LIBCVOFPCPARTITIONCONFIG                        Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv
#define CRYPTO_30_LIBCV_EQ2_STRUCTUNIONWS_CRYPTO_30_LIBCV_GENERALOFPCPARTITIONCONFIG                Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General
#define CRYPTO_30_LIBCV_EQ2_WRITTENLENGTHOFPCPARTITIONCONFIG                                        Crypto_30_LibCv_WrittenLength
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCSymbolicInitializationPointers  Crypto_30_LibCv Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Crypto_30_LibCv_Config_Ptr                                                                  NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Crypto_30_LibCv' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCInitializationSymbols  Crypto_30_LibCv Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Crypto_30_LibCv_Config                                                                      NULL_PTR  /**< symbolic identifier which could be used to initialize 'Crypto_30_LibCv */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCGeneral  Crypto_30_LibCv General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CRYPTO_30_LIBCV_CHECK_INIT_POINTER                                                          STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CRYPTO_30_LIBCV_FINAL_MAGIC_NUMBER                                                          0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Crypto_30_LibCv */
#define CRYPTO_30_LIBCV_INDIVIDUAL_POSTBUILD                                                        STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Crypto_30_LibCv' is not configured to be postbuild capable. */
#define CRYPTO_30_LIBCV_INIT_DATA                                                                   CRYPTO_30_LIBCV_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CRYPTO_30_LIBCV_INIT_DATA_HASH_CODE                                                         2027971617  /**< the precompile constant to validate the initialization structure at initialization time of Crypto_30_LibCv with a hashcode. The seed value is '0xFF1Eu' */
#define CRYPTO_30_LIBCV_USE_ECUM_BSW_ERROR_HOOK                                                     STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CRYPTO_30_LIBCV_USE_INIT_POINTER                                                            STD_OFF  /**< STD_ON if the init pointer Crypto_30_LibCv shall be used. */
#define Crypto_30_LibCv_PartitionIndexOfCSLForCRYPTO_30_LIBCV_SINGLE_PARTITION                      0u  /**< internal partition index of the ComStackLib for the partition CRYPTO_30_LIBCV_SINGLE_PARTITION */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_LibCvPBDataSwitches  Crypto_30_LibCv Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CRYPTO_30_LIBCV_PBCONFIG                                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CRYPTO_30_LIBCV_LTCONFIGIDXOFPBCONFIG                                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CRYPTO_30_LIBCV_PBPARTITIONCONFIGOFPBCONFIG                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PBConfig.PBPartitionConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CRYPTO_30_LIBCV_PCCONFIGIDXOFPBCONFIG                                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CRYPTO_30_LIBCV_PBPARTITIONCONFIG                                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PBPartitionConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPBIsReducedToDefineDefines  Crypto_30_LibCv Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CRYPTO_30_LIBCV_ISDEF_LTCONFIGIDXOFPBCONFIG                                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PBPARTITIONCONFIGOFPBCONFIG                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PCCONFIGIDXOFPBCONFIG                                                 STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPBEqualsAlwaysToDefines  Crypto_30_LibCv Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CRYPTO_30_LIBCV_EQ2_LTCONFIGIDXOFPBCONFIG                                                   
#define CRYPTO_30_LIBCV_EQ2_PBPARTITIONCONFIGOFPBCONFIG                                             
#define CRYPTO_30_LIBCV_EQ2_PCCONFIGIDXOFPBCONFIG                                                   
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
  \defgroup  Crypto_30_LibCvPCGetRootDataMacros  Crypto_30_LibCv Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Crypto_30_LibCv_GetFinalMagicNumberOfPCConfig()                                               /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_LibCv_GetInitDataHashCodeOfPCConfig()                                               /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_LibCv_GetExpectedCompatibilityVersionOfPCPartitionConfig(partitionIndex)            /**< Deactivateable: 'Crypto_30_LibCv_PCPartitionConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_LibCv_GetGeneratorCompatibilityVersionOfPCPartitionConfig(partitionIndex)           /**< Deactivateable: 'Crypto_30_LibCv_PCPartitionConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCGetConstantDuplicatedRootDataMacros  Crypto_30_LibCv Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Crypto_30_LibCv_GetPCPartitionConfigOfPCConfig()                                              /**< PartitionConfig is empty */
#define Crypto_30_LibCv_GetPartitionIdentifiersOfPCConfig()                                         Crypto_30_LibCv_PartitionIdentifiers  /**< the pointer to Crypto_30_LibCv_PartitionIdentifiers */
#define Crypto_30_LibCv_GetSizeOfPartitionIdentifiersOfPCConfig()                                   1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_PartitionIdentifiers */
#define Crypto_30_LibCv_GetAEADChaChaPoly1305DecryptOfPCPartitionConfig()                           Crypto_30_LibCv_AEADChaChaPoly1305Decrypt  /**< the pointer to Crypto_30_LibCv_AEADChaChaPoly1305Decrypt */
#define Crypto_30_LibCv_GetAEADChaChaPoly1305EncryptOfPCPartitionConfig()                           Crypto_30_LibCv_AEADChaChaPoly1305Encrypt  /**< the pointer to Crypto_30_LibCv_AEADChaChaPoly1305Encrypt */
#define Crypto_30_LibCv_GetAesDecryptOfPCPartitionConfig()                                          Crypto_30_LibCv_AesDecrypt  /**< the pointer to Crypto_30_LibCv_AesDecrypt */
#define Crypto_30_LibCv_GetAesEncryptOfPCPartitionConfig()                                          Crypto_30_LibCv_AesEncrypt  /**< the pointer to Crypto_30_LibCv_AesEncrypt */
#define Crypto_30_LibCv_GetAesGcmDecryptOfPCPartitionConfig()                                       Crypto_30_LibCv_AesGcmDecrypt  /**< the pointer to Crypto_30_LibCv_AesGcmDecrypt */
#define Crypto_30_LibCv_GetAesGcmEncryptOfPCPartitionConfig()                                       Crypto_30_LibCv_AesGcmEncrypt  /**< the pointer to Crypto_30_LibCv_AesGcmEncrypt */
#define Crypto_30_LibCv_GetBufferLengthOfPCPartitionConfig()                                        Crypto_30_LibCv_BufferLength  /**< the pointer to Crypto_30_LibCv_BufferLength */
#define Crypto_30_LibCv_GetCmacAesGenerateOfPCPartitionConfig()                                     Crypto_30_LibCv_CmacAesGenerate  /**< the pointer to Crypto_30_LibCv_CmacAesGenerate */
#define Crypto_30_LibCv_GetCmacAesVerifyOfPCPartitionConfig()                                       Crypto_30_LibCv_CmacAesVerify  /**< the pointer to Crypto_30_LibCv_CmacAesVerify */
#define Crypto_30_LibCv_GetDRBGAESOfPCPartitionConfig()                                             Crypto_30_LibCv_DRBGAES  /**< the pointer to Crypto_30_LibCv_DRBGAES */
#define Crypto_30_LibCv_GetDispatch_QueuePrimitiveInfoIdxOfPCPartitionConfig()                      Crypto_30_LibCv_Dispatch_QueuePrimitiveInfoIdx  /**< the pointer to Crypto_30_LibCv_Dispatch_QueuePrimitiveInfoIdx */
#define Crypto_30_LibCv_GetDriverObjectStateOfPCPartitionConfig()                                   Crypto_30_LibCv_DriverObjectState  /**< the pointer to Crypto_30_LibCv_DriverObjectState */
#define Crypto_30_LibCv_GetEcP256GenerateOfPCPartitionConfig()                                      Crypto_30_LibCv_EcP256Generate  /**< the pointer to Crypto_30_LibCv_EcP256Generate */
#define Crypto_30_LibCv_GetEcP256VerifyOfPCPartitionConfig()                                        Crypto_30_LibCv_EcP256Verify  /**< the pointer to Crypto_30_LibCv_EcP256Verify */
#define Crypto_30_LibCv_GetEcP521GenerateOfPCPartitionConfig()                                      Crypto_30_LibCv_EcP521Generate  /**< the pointer to Crypto_30_LibCv_EcP521Generate */
#define Crypto_30_LibCv_GetEcP521VerifyOfPCPartitionConfig()                                        Crypto_30_LibCv_EcP521Verify  /**< the pointer to Crypto_30_LibCv_EcP521Verify */
#define Crypto_30_LibCv_GetEd25519GenerateOfPCPartitionConfig()                                     Crypto_30_LibCv_Ed25519Generate  /**< the pointer to Crypto_30_LibCv_Ed25519Generate */
#define Crypto_30_LibCv_GetEd25519VerifyOfPCPartitionConfig()                                       Crypto_30_LibCv_Ed25519Verify  /**< the pointer to Crypto_30_LibCv_Ed25519Verify */
#define Crypto_30_LibCv_GetFamilyToHashMappingOfPCPartitionConfig()                                 Crypto_30_LibCv_FamilyToHashMapping  /**< the pointer to Crypto_30_LibCv_FamilyToHashMapping */
#define Crypto_30_LibCv_GetFips186OfPCPartitionConfig()                                             Crypto_30_LibCv_Fips186  /**< the pointer to Crypto_30_LibCv_Fips186 */
#define Crypto_30_LibCv_GetGmacAesGenerateOfPCPartitionConfig()                                     Crypto_30_LibCv_GmacAesGenerate  /**< the pointer to Crypto_30_LibCv_GmacAesGenerate */
#define Crypto_30_LibCv_GetGmacAesVerifyOfPCPartitionConfig()                                       Crypto_30_LibCv_GmacAesVerify  /**< the pointer to Crypto_30_LibCv_GmacAesVerify */
#define Crypto_30_LibCv_GetHashOfPCPartitionConfig()                                                Crypto_30_LibCv_Hash  /**< the pointer to Crypto_30_LibCv_Hash */
#define Crypto_30_LibCv_GetHmacSha1GenerateOfPCPartitionConfig()                                    Crypto_30_LibCv_HmacSha1Generate  /**< the pointer to Crypto_30_LibCv_HmacSha1Generate */
#define Crypto_30_LibCv_GetHmacSha1VerifyOfPCPartitionConfig()                                      Crypto_30_LibCv_HmacSha1Verify  /**< the pointer to Crypto_30_LibCv_HmacSha1Verify */
#define Crypto_30_LibCv_GetHmacSha256GenerateOfPCPartitionConfig()                                  Crypto_30_LibCv_HmacSha256Generate  /**< the pointer to Crypto_30_LibCv_HmacSha256Generate */
#define Crypto_30_LibCv_GetHmacSha256VerifyOfPCPartitionConfig()                                    Crypto_30_LibCv_HmacSha256Verify  /**< the pointer to Crypto_30_LibCv_HmacSha256Verify */
#define Crypto_30_LibCv_GetHmacSha384GenerateOfPCPartitionConfig()                                  Crypto_30_LibCv_HmacSha384Generate  /**< the pointer to Crypto_30_LibCv_HmacSha384Generate */
#define Crypto_30_LibCv_GetHmacSha384VerifyOfPCPartitionConfig()                                    Crypto_30_LibCv_HmacSha384Verify  /**< the pointer to Crypto_30_LibCv_HmacSha384Verify */
#define Crypto_30_LibCv_GetInitValueOfPCPartitionConfig()                                           Crypto_30_LibCv_InitValue  /**< the pointer to Crypto_30_LibCv_InitValue */
#define Crypto_30_LibCv_GetKeyDeriveHKDFExpandHMACSHA256OfPCPartitionConfig()                       Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256  /**< the pointer to Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256 */
#define Crypto_30_LibCv_GetKeyDeriveHKDFExpandHMACSHA384OfPCPartitionConfig()                       Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384  /**< the pointer to Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384 */
#define Crypto_30_LibCv_GetKeyDeriveHKDFHMACSHA256OfPCPartitionConfig()                             Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256  /**< the pointer to Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256 */
#define Crypto_30_LibCv_GetKeyDeriveHKDFHMACSHA384OfPCPartitionConfig()                             Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384  /**< the pointer to Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384 */
#define Crypto_30_LibCv_GetKeyDeriveISO15118OfPCPartitionConfig()                                   Crypto_30_LibCv_KeyDeriveISO15118  /**< the pointer to Crypto_30_LibCv_KeyDeriveISO15118 */
#define Crypto_30_LibCv_GetKeyDeriveISO15118_20OfPCPartitionConfig()                                Crypto_30_LibCv_KeyDeriveISO15118_20  /**< the pointer to Crypto_30_LibCv_KeyDeriveISO15118_20 */
#define Crypto_30_LibCv_GetKeyElementInfoOfPCPartitionConfig()                                      Crypto_30_LibCv_KeyElementInfo  /**< the pointer to Crypto_30_LibCv_KeyElementInfo */
#define Crypto_30_LibCv_GetKeyElementsOfPCPartitionConfig()                                         Crypto_30_LibCv_KeyElements  /**< the pointer to Crypto_30_LibCv_KeyElements */
#define Crypto_30_LibCv_GetKeyGenP256R1OfPCPartitionConfig()                                        Crypto_30_LibCv_KeyGenP256R1  /**< the pointer to Crypto_30_LibCv_KeyGenP256R1 */
#define Crypto_30_LibCv_GetKeyLockOfPCPartitionConfig()                                             Crypto_30_LibCv_KeyLock.raw  /**< the pointer to Crypto_30_LibCv_KeyLock */
#define Crypto_30_LibCv_GetKeyNvStatusOfPCPartitionConfig()                                         Crypto_30_LibCv_KeyNvStatus.raw  /**< the pointer to Crypto_30_LibCv_KeyNvStatus */
#define Crypto_30_LibCv_GetKeyOfPCPartitionConfig()                                                 Crypto_30_LibCv_Key  /**< the pointer to Crypto_30_LibCv_Key */
#define Crypto_30_LibCv_GetKeyP256R1SecretOfPCPartitionConfig()                                     Crypto_30_LibCv_KeyP256R1Secret  /**< the pointer to Crypto_30_LibCv_KeyP256R1Secret */
#define Crypto_30_LibCv_GetKeyStorageOfPCPartitionConfig()                                          Crypto_30_LibCv_KeyStorage  /**< the pointer to Crypto_30_LibCv_KeyStorage */
#define Crypto_30_LibCv_GetLockOfPCPartitionConfig()                                                Crypto_30_LibCv_Lock  /**< the pointer to Crypto_30_LibCv_Lock */
#define Crypto_30_LibCv_GetMainFunctionPeriodOfGeneralOfPCPartitionConfig(partitionIndex)           1u
#define Crypto_30_LibCv_GetNvBlockOfPCPartitionConfig()                                             Crypto_30_LibCv_NvBlock  /**< the pointer to Crypto_30_LibCv_NvBlock */
#define Crypto_30_LibCv_GetObjectInfoIndOfPCPartitionConfig()                                       Crypto_30_LibCv_ObjectInfoInd  /**< the pointer to Crypto_30_LibCv_ObjectInfoInd */
#define Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()                                          Crypto_30_LibCv_ObjectInfo  /**< the pointer to Crypto_30_LibCv_ObjectInfo */
#define Crypto_30_LibCv_GetPartitionInfoOfPCPartitionConfig()                                       Crypto_30_LibCv_PartitionInfo  /**< the pointer to Crypto_30_LibCv_PartitionInfo */
#define Crypto_30_LibCv_GetPartitionInitializedOfPCPartitionConfig(partitionIndex)                  (&(Crypto_30_LibCv_PartitionInitialized))  /**< the pointer to Crypto_30_LibCv_PartitionInitialized */
#define Crypto_30_LibCv_GetPrimitiveFctOfPCPartitionConfig()                                        Crypto_30_LibCv_PrimitiveFct  /**< the pointer to Crypto_30_LibCv_PrimitiveFct */
#define Crypto_30_LibCv_GetPrimitiveInfoOfPCPartitionConfig()                                       Crypto_30_LibCv_PrimitiveInfo  /**< the pointer to Crypto_30_LibCv_PrimitiveInfo */
#define Crypto_30_LibCv_GetPrimitiveServiceInfoOfPCPartitionConfig()                                Crypto_30_LibCv_PrimitiveServiceInfo  /**< the pointer to Crypto_30_LibCv_PrimitiveServiceInfo */
#define Crypto_30_LibCv_GetProcessJob_Trigger_WriteOfPCPartitionConfig()                            Crypto_30_LibCv_ProcessJob_Trigger_Write  /**< the pointer to Crypto_30_LibCv_ProcessJob_Trigger_Write */
#define Crypto_30_LibCv_GetQueueOfPCPartitionConfig()                                               Crypto_30_LibCv_Queue.raw  /**< the pointer to Crypto_30_LibCv_Queue */
#define Crypto_30_LibCv_GetRandomSeedBufferOfPCPartitionConfig()                                    Crypto_30_LibCv_RandomSeedBuffer.raw  /**< the pointer to Crypto_30_LibCv_RandomSeedBuffer */
#define Crypto_30_LibCv_GetRandomSourceGenerateCountOfPCPartitionConfig(partitionIndex)             (&(Crypto_30_LibCv_RandomSourceGenerateCount))  /**< the pointer to Crypto_30_LibCv_RandomSourceGenerateCount */
#define Crypto_30_LibCv_GetRedirect_BufferOfPCPartitionConfig()                                     Crypto_30_LibCv_Redirect_Buffer  /**< the pointer to Crypto_30_LibCv_Redirect_Buffer */
#define Crypto_30_LibCv_GetSizeOfAEADChaChaPoly1305DecryptOfPCPartitionConfig()                     1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_AEADChaChaPoly1305Decrypt */
#define Crypto_30_LibCv_GetSizeOfAEADChaChaPoly1305EncryptOfPCPartitionConfig()                     1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_AEADChaChaPoly1305Encrypt */
#define Crypto_30_LibCv_GetSizeOfAesDecryptOfPCPartitionConfig()                                    3u  /**< the number of accomplishable value elements in Crypto_30_LibCv_AesDecrypt */
#define Crypto_30_LibCv_GetSizeOfAesEncryptOfPCPartitionConfig()                                    3u  /**< the number of accomplishable value elements in Crypto_30_LibCv_AesEncrypt */
#define Crypto_30_LibCv_GetSizeOfAesGcmDecryptOfPCPartitionConfig()                                 1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_AesGcmDecrypt */
#define Crypto_30_LibCv_GetSizeOfAesGcmEncryptOfPCPartitionConfig()                                 1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_AesGcmEncrypt */
#define Crypto_30_LibCv_GetSizeOfCmacAesGenerateOfPCPartitionConfig()                               2u  /**< the number of accomplishable value elements in Crypto_30_LibCv_CmacAesGenerate */
#define Crypto_30_LibCv_GetSizeOfCmacAesVerifyOfPCPartitionConfig()                                 2u  /**< the number of accomplishable value elements in Crypto_30_LibCv_CmacAesVerify */
#define Crypto_30_LibCv_GetSizeOfDRBGAESOfPCPartitionConfig()                                       2u  /**< the number of accomplishable value elements in Crypto_30_LibCv_DRBGAES */
#define Crypto_30_LibCv_GetSizeOfEcP256GenerateOfPCPartitionConfig()                                4u  /**< the number of accomplishable value elements in Crypto_30_LibCv_EcP256Generate */
#define Crypto_30_LibCv_GetSizeOfEcP256VerifyOfPCPartitionConfig()                                  4u  /**< the number of accomplishable value elements in Crypto_30_LibCv_EcP256Verify */
#define Crypto_30_LibCv_GetSizeOfEcP521GenerateOfPCPartitionConfig()                                4u  /**< the number of accomplishable value elements in Crypto_30_LibCv_EcP521Generate */
#define Crypto_30_LibCv_GetSizeOfEcP521VerifyOfPCPartitionConfig()                                  4u  /**< the number of accomplishable value elements in Crypto_30_LibCv_EcP521Verify */
#define Crypto_30_LibCv_GetSizeOfEd25519GenerateOfPCPartitionConfig()                               1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_Ed25519Generate */
#define Crypto_30_LibCv_GetSizeOfEd25519VerifyOfPCPartitionConfig()                                 1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_Ed25519Verify */
#define Crypto_30_LibCv_GetSizeOfFamilyToHashMappingOfPCPartitionConfig()                           8u  /**< the number of accomplishable value elements in Crypto_30_LibCv_FamilyToHashMapping */
#define Crypto_30_LibCv_GetSizeOfFips186OfPCPartitionConfig()                                       2u  /**< the number of accomplishable value elements in Crypto_30_LibCv_Fips186 */
#define Crypto_30_LibCv_GetSizeOfGmacAesGenerateOfPCPartitionConfig()                               2u  /**< the number of accomplishable value elements in Crypto_30_LibCv_GmacAesGenerate */
#define Crypto_30_LibCv_GetSizeOfGmacAesVerifyOfPCPartitionConfig()                                 2u  /**< the number of accomplishable value elements in Crypto_30_LibCv_GmacAesVerify */
#define Crypto_30_LibCv_GetSizeOfHashOfPCPartitionConfig()                                          8u  /**< the number of accomplishable value elements in Crypto_30_LibCv_Hash */
#define Crypto_30_LibCv_GetSizeOfHmacSha1GenerateOfPCPartitionConfig()                              3u  /**< the number of accomplishable value elements in Crypto_30_LibCv_HmacSha1Generate */
#define Crypto_30_LibCv_GetSizeOfHmacSha1VerifyOfPCPartitionConfig()                                3u  /**< the number of accomplishable value elements in Crypto_30_LibCv_HmacSha1Verify */
#define Crypto_30_LibCv_GetSizeOfHmacSha256GenerateOfPCPartitionConfig()                            4u  /**< the number of accomplishable value elements in Crypto_30_LibCv_HmacSha256Generate */
#define Crypto_30_LibCv_GetSizeOfHmacSha256VerifyOfPCPartitionConfig()                              4u  /**< the number of accomplishable value elements in Crypto_30_LibCv_HmacSha256Verify */
#define Crypto_30_LibCv_GetSizeOfHmacSha384GenerateOfPCPartitionConfig()                            2u  /**< the number of accomplishable value elements in Crypto_30_LibCv_HmacSha384Generate */
#define Crypto_30_LibCv_GetSizeOfHmacSha384VerifyOfPCPartitionConfig()                              1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_HmacSha384Verify */
#define Crypto_30_LibCv_GetSizeOfInitValueOfPCPartitionConfig()                                     15u  /**< the number of accomplishable value elements in Crypto_30_LibCv_InitValue */
#define Crypto_30_LibCv_GetSizeOfKeyDeriveHKDFExpandHMACSHA256OfPCPartitionConfig()                 1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256 */
#define Crypto_30_LibCv_GetSizeOfKeyDeriveHKDFExpandHMACSHA384OfPCPartitionConfig()                 1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384 */
#define Crypto_30_LibCv_GetSizeOfKeyDeriveHKDFHMACSHA256OfPCPartitionConfig()                       2u  /**< the number of accomplishable value elements in Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256 */
#define Crypto_30_LibCv_GetSizeOfKeyDeriveHKDFHMACSHA384OfPCPartitionConfig()                       1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384 */
#define Crypto_30_LibCv_GetSizeOfKeyDeriveISO15118OfPCPartitionConfig()                             3u  /**< the number of accomplishable value elements in Crypto_30_LibCv_KeyDeriveISO15118 */
#define Crypto_30_LibCv_GetSizeOfKeyDeriveISO15118_20OfPCPartitionConfig()                          1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_KeyDeriveISO15118_20 */
#define Crypto_30_LibCv_GetSizeOfKeyElementInfoOfPCPartitionConfig()                                69u  /**< the number of accomplishable value elements in Crypto_30_LibCv_KeyElementInfo */
#define Crypto_30_LibCv_GetSizeOfKeyElementsOfPCPartitionConfig()                                   194u  /**< the number of accomplishable value elements in Crypto_30_LibCv_KeyElements */
#define Crypto_30_LibCv_GetSizeOfKeyGenP256R1OfPCPartitionConfig()                                  1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_KeyGenP256R1 */
#define Crypto_30_LibCv_GetSizeOfKeyOfPCPartitionConfig()                                           119u  /**< the number of accomplishable value elements in Crypto_30_LibCv_Key */
#define Crypto_30_LibCv_GetSizeOfKeyP256R1SecretOfPCPartitionConfig()                               1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_KeyP256R1Secret */
#define Crypto_30_LibCv_GetSizeOfKeyStorageOfPCPartitionConfig()                                    12815u  /**< the number of accomplishable value elements in Crypto_30_LibCv_KeyStorage */
#define Crypto_30_LibCv_GetSizeOfNvBlockOfPCPartitionConfig()                                       1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_NvBlock */
#define Crypto_30_LibCv_GetSizeOfObjectInfoIndOfPCPartitionConfig()                                 83u  /**< the number of accomplishable value elements in Crypto_30_LibCv_ObjectInfoInd */
#define Crypto_30_LibCv_GetSizeOfObjectInfoOfPCPartitionConfig()                                    9u  /**< the number of accomplishable value elements in Crypto_30_LibCv_ObjectInfo */
#define Crypto_30_LibCv_GetSizeOfPartitionInfoOfPCPartitionConfig()                                 1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_PartitionInfo */
#define Crypto_30_LibCv_GetSizeOfPrimitiveFctOfPCPartitionConfig()                                  36u  /**< the number of accomplishable value elements in Crypto_30_LibCv_PrimitiveFct */
#define Crypto_30_LibCv_GetSizeOfPrimitiveInfoOfPCPartitionConfig()                                 72u  /**< the number of accomplishable value elements in Crypto_30_LibCv_PrimitiveInfo */
#define Crypto_30_LibCv_GetSizeOfPrimitiveServiceInfoOfPCPartitionConfig()                          21u  /**< the number of accomplishable value elements in Crypto_30_LibCv_PrimitiveServiceInfo */
#define Crypto_30_LibCv_GetSizeOfQueueOfPCPartitionConfig()                                         9u  /**< the number of accomplishable value elements in Crypto_30_LibCv_Queue */
#define Crypto_30_LibCv_GetSizeOfRandomSeedBufferOfPCPartitionConfig()                              42u  /**< the number of accomplishable value elements in Crypto_30_LibCv_RandomSeedBuffer */
#define Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn0OfPCPartitionConfig()    1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0 */
#define Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_FinishedOfPCPartitionConfig() 1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished */
#define Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1OfPCPartitionConfig()    1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1 */
#define Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_FinishedOfPCPartitionConfig() 1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished */
#define Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384OfPCPartitionConfig() 1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384 */
#define Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384OfPCPartitionConfig() 1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384 */
#define Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1OfPCPartitionConfig() 1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1 */
#define Crypto_30_LibCv_GetSizeOfStructUnionWS_Crypto_30_LibCvOfPCPartitionConfig()                 1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv */
#define Crypto_30_LibCv_GetSizeOfStructUnionWS_Crypto_30_LibCv_GeneralOfPCPartitionConfig()         1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General */
#define Crypto_30_LibCv_IsStrictLengthCheckForKeyElementGetOfGeneralOfPCPartitionConfig(partitionIndex) (((TRUE)) != FALSE)
#define Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Conn0OfPCPartitionConfig()          Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0  /**< the pointer to Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0 */
#define Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_FinishedOfPCPartitionConfig() Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished  /**< the pointer to Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished */
#define Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Conn1OfPCPartitionConfig()          Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1  /**< the pointer to Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1 */
#define Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_FinishedOfPCPartitionConfig() Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished  /**< the pointer to Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished */
#define Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384OfPCPartitionConfig() Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384  /**< the pointer to Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384 */
#define Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384OfPCPartitionConfig() Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384  /**< the pointer to Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384 */
#define Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1OfPCPartitionConfig() Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1  /**< the pointer to Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1 */
#define Crypto_30_LibCv_GetStructUnionWS_Crypto_30_LibCvOfPCPartitionConfig()                       Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv  /**< the pointer to Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv */
#define Crypto_30_LibCv_GetStructUnionWS_Crypto_30_LibCv_GeneralOfPCPartitionConfig()               Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General  /**< the pointer to Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General */
#define Crypto_30_LibCv_IsUseVStdLibOfGeneralOfPCPartitionConfig(partitionIndex)                    (((TRUE)) != FALSE)
#define Crypto_30_LibCv_IsVersionInfoApiOfGeneralOfPCPartitionConfig(partitionIndex)                (((FALSE)) != FALSE)
#define Crypto_30_LibCv_GetWrittenLengthOfPCPartitionConfig()                                       Crypto_30_LibCv_WrittenLength  /**< the pointer to Crypto_30_LibCv_WrittenLength */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCGetDuplicatedRootDataMacros  Crypto_30_LibCv Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define Crypto_30_LibCv_GetSizeOfBufferLengthOfPCPartitionConfig()                                  Crypto_30_LibCv_GetSizeOfObjectInfoOfPCPartitionConfig()  /**< the number of accomplishable value elements in Crypto_30_LibCv_BufferLength */
#define Crypto_30_LibCv_GetSizeOfDispatch_QueuePrimitiveInfoIdxOfPCPartitionConfig()                Crypto_30_LibCv_GetSizeOfObjectInfoOfPCPartitionConfig()  /**< the number of accomplishable value elements in Crypto_30_LibCv_Dispatch_QueuePrimitiveInfoIdx */
#define Crypto_30_LibCv_GetSizeOfDriverObjectStateOfPCPartitionConfig()                             Crypto_30_LibCv_GetSizeOfObjectInfoOfPCPartitionConfig()  /**< the number of accomplishable value elements in Crypto_30_LibCv_DriverObjectState */
#define Crypto_30_LibCv_GetSizeOfKeyLockOfPCPartitionConfig()                                       Crypto_30_LibCv_GetSizeOfKeyOfPCPartitionConfig()  /**< the number of accomplishable value elements in Crypto_30_LibCv_KeyLock */
#define Crypto_30_LibCv_GetSizeOfKeyNvStatusOfPCPartitionConfig()                                   Crypto_30_LibCv_GetSizeOfKeyOfPCPartitionConfig()  /**< the number of accomplishable value elements in Crypto_30_LibCv_KeyNvStatus */
#define Crypto_30_LibCv_GetSizeOfLockOfPCPartitionConfig()                                          Crypto_30_LibCv_GetSizeOfObjectInfoOfPCPartitionConfig()  /**< the number of accomplishable value elements in Crypto_30_LibCv_Lock */
#define Crypto_30_LibCv_GetSizeOfProcessJob_Trigger_WriteOfPCPartitionConfig()                      Crypto_30_LibCv_GetSizeOfObjectInfoOfPCPartitionConfig()  /**< the number of accomplishable value elements in Crypto_30_LibCv_ProcessJob_Trigger_Write */
#define Crypto_30_LibCv_GetSizeOfRedirect_BufferOfPCPartitionConfig()                               Crypto_30_LibCv_GetSizeOfObjectInfoOfPCPartitionConfig()  /**< the number of accomplishable value elements in Crypto_30_LibCv_Redirect_Buffer */
#define Crypto_30_LibCv_GetSizeOfWrittenLengthOfPCPartitionConfig()                                 Crypto_30_LibCv_GetSizeOfObjectInfoOfPCPartitionConfig()  /**< the number of accomplishable value elements in Crypto_30_LibCv_WrittenLength */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCGetDataMacros  Crypto_30_LibCv Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Crypto_30_LibCv_GetWorkspaceOfAEADChaChaPoly1305Decrypt(Index)                              (Crypto_30_LibCv_GetAEADChaChaPoly1305DecryptOfPCPartitionConfig()[(Index)].WorkspaceOfAEADChaChaPoly1305Decrypt)
#define Crypto_30_LibCv_GetWorkspaceOfAEADChaChaPoly1305Encrypt(Index)                              (Crypto_30_LibCv_GetAEADChaChaPoly1305EncryptOfPCPartitionConfig()[(Index)].WorkspaceOfAEADChaChaPoly1305Encrypt)
#define Crypto_30_LibCv_GetWorkspaceOfAesCcmDecrypt(Index)                                            /**< Deactivateable: 'Crypto_30_LibCv_AesCcmDecrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfAesCcmEncrypt(Index)                                            /**< Deactivateable: 'Crypto_30_LibCv_AesCcmEncrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfAesDecrypt(Index)                                             (Crypto_30_LibCv_GetAesDecryptOfPCPartitionConfig()[(Index)].WorkspaceOfAesDecrypt)
#define Crypto_30_LibCv_GetWorkspaceOfAesEncrypt(Index)                                             (Crypto_30_LibCv_GetAesEncryptOfPCPartitionConfig()[(Index)].WorkspaceOfAesEncrypt)
#define Crypto_30_LibCv_GetWorkspaceOfAesGcmDecrypt(Index)                                          (Crypto_30_LibCv_GetAesGcmDecryptOfPCPartitionConfig()[(Index)].WorkspaceOfAesGcmDecrypt)
#define Crypto_30_LibCv_GetWorkspaceOfAesGcmEncrypt(Index)                                          (Crypto_30_LibCv_GetAesGcmEncryptOfPCPartitionConfig()[(Index)].WorkspaceOfAesGcmEncrypt)
#define Crypto_30_LibCv_GetBufferLength(Index)                                                      (Crypto_30_LibCv_GetBufferLengthOfPCPartitionConfig()[(Index)])
#define Crypto_30_LibCv_GetWorkspaceOfCmacAesGenerate(Index)                                        (Crypto_30_LibCv_GetCmacAesGenerateOfPCPartitionConfig()[(Index)].WorkspaceOfCmacAesGenerate)
#define Crypto_30_LibCv_GetWorkspaceOfCmacAesVerify(Index)                                          (Crypto_30_LibCv_GetCmacAesVerifyOfPCPartitionConfig()[(Index)].WorkspaceOfCmacAesVerify)
#define Crypto_30_LibCv_GetWorkspaceOfDRBGAES(Index)                                                (Crypto_30_LibCv_GetDRBGAESOfPCPartitionConfig()[(Index)].WorkspaceOfDRBGAES)
#define Crypto_30_LibCv_GetWorkspaceOfDRBGHashSha512(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_DRBGHashSha512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetDispatch_QueuePrimitiveInfoIdx(Index)                                    (Crypto_30_LibCv_GetDispatch_QueuePrimitiveInfoIdxOfPCPartitionConfig()[(Index)])
#define Crypto_30_LibCv_GetDriverObjectState(Index)                                                 (Crypto_30_LibCv_GetDriverObjectStateOfPCPartitionConfig()[(Index)])
#define Crypto_30_LibCv_GetWorkspaceOfEcP160Generate(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_EcP160Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfEcP160Verify(Index)                                             /**< Deactivateable: 'Crypto_30_LibCv_EcP160Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfEcP256Generate(Index)                                         (Crypto_30_LibCv_GetEcP256GenerateOfPCPartitionConfig()[(Index)].WorkspaceOfEcP256Generate)
#define Crypto_30_LibCv_GetWorkspaceOfEcP256Verify(Index)                                           (Crypto_30_LibCv_GetEcP256VerifyOfPCPartitionConfig()[(Index)].WorkspaceOfEcP256Verify)
#define Crypto_30_LibCv_GetWorkspaceOfEcP384Generate(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_EcP384Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfEcP384Verify(Index)                                             /**< Deactivateable: 'Crypto_30_LibCv_EcP384Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfEcP521Generate(Index)                                         (Crypto_30_LibCv_GetEcP521GenerateOfPCPartitionConfig()[(Index)].WorkspaceOfEcP521Generate)
#define Crypto_30_LibCv_GetWorkspaceOfEcP521Verify(Index)                                           (Crypto_30_LibCv_GetEcP521VerifyOfPCPartitionConfig()[(Index)].WorkspaceOfEcP521Verify)
#define Crypto_30_LibCv_GetWorkspaceOfEcPKeyCheck(Index)                                              /**< Deactivateable: 'Crypto_30_LibCv_EcPKeyCheck.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfEd25519Generate(Index)                                        (Crypto_30_LibCv_GetEd25519GenerateOfPCPartitionConfig()[(Index)].WorkspaceOfEd25519Generate)
#define Crypto_30_LibCv_GetWorkspaceOfEd25519Verify(Index)                                          (Crypto_30_LibCv_GetEd25519VerifyOfPCPartitionConfig()[(Index)].WorkspaceOfEd25519Verify)
#define Crypto_30_LibCv_GetWorkspaceOfEd448Generate(Index)                                            /**< Deactivateable: 'Crypto_30_LibCv_Ed448Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfEd448Verify(Index)                                              /**< Deactivateable: 'Crypto_30_LibCv_Ed448Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfEdKeyCheck(Index)                                               /**< Deactivateable: 'Crypto_30_LibCv_EdKeyCheck.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetFamilyToHashMapping(Index)                                               (Crypto_30_LibCv_GetFamilyToHashMappingOfPCPartitionConfig()[(Index)])
#define Crypto_30_LibCv_GetWorkspaceOfFips186(Index)                                                (Crypto_30_LibCv_GetFips186OfPCPartitionConfig()[(Index)].WorkspaceOfFips186)
#define Crypto_30_LibCv_GetWorkspaceOfGmacAesGenerate(Index)                                        (Crypto_30_LibCv_GetGmacAesGenerateOfPCPartitionConfig()[(Index)].WorkspaceOfGmacAesGenerate)
#define Crypto_30_LibCv_GetWorkspaceOfGmacAesVerify(Index)                                          (Crypto_30_LibCv_GetGmacAesVerifyOfPCPartitionConfig()[(Index)].WorkspaceOfGmacAesVerify)
#define Crypto_30_LibCv_GetWorkspaceOfHash(Index)                                                   (Crypto_30_LibCv_GetHashOfPCPartitionConfig()[(Index)].WorkspaceOfHash)
#define Crypto_30_LibCv_GetWorkspaceOfHmacRipeMd160Generate(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_HmacRipeMd160Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfHmacRipeMd160Verify(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_HmacRipeMd160Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfHmacSha1Generate(Index)                                       (Crypto_30_LibCv_GetHmacSha1GenerateOfPCPartitionConfig()[(Index)].WorkspaceOfHmacSha1Generate)
#define Crypto_30_LibCv_GetWorkspaceOfHmacSha1Verify(Index)                                         (Crypto_30_LibCv_GetHmacSha1VerifyOfPCPartitionConfig()[(Index)].WorkspaceOfHmacSha1Verify)
#define Crypto_30_LibCv_GetWorkspaceOfHmacSha256Generate(Index)                                     (Crypto_30_LibCv_GetHmacSha256GenerateOfPCPartitionConfig()[(Index)].WorkspaceOfHmacSha256Generate)
#define Crypto_30_LibCv_GetWorkspaceOfHmacSha256Verify(Index)                                       (Crypto_30_LibCv_GetHmacSha256VerifyOfPCPartitionConfig()[(Index)].WorkspaceOfHmacSha256Verify)
#define Crypto_30_LibCv_GetWorkspaceOfHmacSha384Generate(Index)                                     (Crypto_30_LibCv_GetHmacSha384GenerateOfPCPartitionConfig()[(Index)].WorkspaceOfHmacSha384Generate)
#define Crypto_30_LibCv_GetWorkspaceOfHmacSha384Verify(Index)                                       (Crypto_30_LibCv_GetHmacSha384VerifyOfPCPartitionConfig()[(Index)].WorkspaceOfHmacSha384Verify)
#define Crypto_30_LibCv_GetWorkspaceOfHmacSha512Generate(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_HmacSha512Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfHmacSha512Verify(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_HmacSha512Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetInitValue(Index)                                                         (Crypto_30_LibCv_GetInitValueOfPCPartitionConfig()[(Index)])
#define Crypto_30_LibCv_GetKeyElementsEndIdxOfKey(Index)                                            (Crypto_30_LibCv_GetKeyOfPCPartitionConfig()[(Index)].KeyElementsEndIdxOfKey)
#define Crypto_30_LibCv_GetKeyElementsStartIdxOfKey(Index)                                          (Crypto_30_LibCv_GetKeyOfPCPartitionConfig()[(Index)].KeyElementsStartIdxOfKey)
#define Crypto_30_LibCv_GetNvBlockIdxOfKey(Index)                                                   (Crypto_30_LibCv_GetKeyOfPCPartitionConfig()[(Index)].NvBlockIdxOfKey)
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveHKDFExpandHMACSHA256(Index)                          (Crypto_30_LibCv_GetKeyDeriveHKDFExpandHMACSHA256OfPCPartitionConfig()[(Index)].WorkspaceOfKeyDeriveHKDFExpandHMACSHA256)
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveHKDFExpandHMACSHA384(Index)                          (Crypto_30_LibCv_GetKeyDeriveHKDFExpandHMACSHA384OfPCPartitionConfig()[(Index)].WorkspaceOfKeyDeriveHKDFExpandHMACSHA384)
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveHKDFHMACSHA256(Index)                                (Crypto_30_LibCv_GetKeyDeriveHKDFHMACSHA256OfPCPartitionConfig()[(Index)].WorkspaceOfKeyDeriveHKDFHMACSHA256)
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveHKDFHMACSHA384(Index)                                (Crypto_30_LibCv_GetKeyDeriveHKDFHMACSHA384OfPCPartitionConfig()[(Index)].WorkspaceOfKeyDeriveHKDFHMACSHA384)
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveHKDFHashOption1SHA256(Index)                           /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveHKDFHashOption1SHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveHKDFHashOption1SHA512(Index)                           /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveHKDFHashOption1SHA512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveISO15118(Index)                                      (Crypto_30_LibCv_GetKeyDeriveISO15118OfPCPartitionConfig()[(Index)].WorkspaceOfKeyDeriveISO15118)
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveISO15118_20(Index)                                   (Crypto_30_LibCv_GetKeyDeriveISO15118_20OfPCPartitionConfig()[(Index)].WorkspaceOfKeyDeriveISO15118_20)
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveKDF2HMACSHA1(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveKDF2HMACSHA1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveKDF2HMACSHA256(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveKDF2HMACSHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveNist800108Cnt(Index)                                   /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNist800108Cnt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveNist80056AOnePass(Index)                               /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNist80056AOnePass.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveNistFips186Erb(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNistFips186Erb.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveSpake2P(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveSpake2P.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveX963SHA256(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveX963SHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveX963SHA512(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveX963SHA512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetIdOfKeyElementInfo(Index)                                                (Crypto_30_LibCv_GetKeyElementInfoOfPCPartitionConfig()[(Index)].IdOfKeyElementInfo)
#define Crypto_30_LibCv_GetInitValueEndIdxOfKeyElementInfo(Index)                                   (Crypto_30_LibCv_GetKeyElementInfoOfPCPartitionConfig()[(Index)].InitValueEndIdxOfKeyElementInfo)
#define Crypto_30_LibCv_GetInitValueStartIdxOfKeyElementInfo(Index)                                 (Crypto_30_LibCv_GetKeyElementInfoOfPCPartitionConfig()[(Index)].InitValueStartIdxOfKeyElementInfo)
#define Crypto_30_LibCv_GetLengthOfKeyElementInfo(Index)                                            (Crypto_30_LibCv_GetKeyElementInfoOfPCPartitionConfig()[(Index)].LengthOfKeyElementInfo)
#define Crypto_30_LibCv_GetMaskedBitsOfKeyElementInfo(Index)                                        (Crypto_30_LibCv_GetKeyElementInfoOfPCPartitionConfig()[(Index)].MaskedBitsOfKeyElementInfo)
#define Crypto_30_LibCv_GetReadOfKeyElementInfo(Index)                                              (Crypto_30_LibCv_GetKeyElementInfoOfPCPartitionConfig()[(Index)].ReadOfKeyElementInfo)
#define Crypto_30_LibCv_GetWriteOfKeyElementInfo(Index)                                             (Crypto_30_LibCv_GetKeyElementInfoOfPCPartitionConfig()[(Index)].WriteOfKeyElementInfo)
#define Crypto_30_LibCv_GetIdOfKeyElements(Index)                                                   (Crypto_30_LibCv_GetKeyElementsOfPCPartitionConfig()[(Index)].IdOfKeyElements)
#define Crypto_30_LibCv_GetKeyElementInfoIdxOfKeyElements(Index)                                    (Crypto_30_LibCv_GetKeyElementsOfPCPartitionConfig()[(Index)].KeyElementInfoIdxOfKeyElements)
#define Crypto_30_LibCv_GetKeyStorageEndIdxOfKeyElements(Index)                                     (Crypto_30_LibCv_GetKeyElementsOfPCPartitionConfig()[(Index)].KeyStorageEndIdxOfKeyElements)
#define Crypto_30_LibCv_GetKeyStorageStartIdxOfKeyElements(Index)                                   (Crypto_30_LibCv_GetKeyElementsOfPCPartitionConfig()[(Index)].KeyStorageStartIdxOfKeyElements)
#define Crypto_30_LibCv_GetWorkspaceOfKeyGenEd25519(Index)                                            /**< Deactivateable: 'Crypto_30_LibCv_KeyGenEd25519.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyGenP256R1(Index)                                           (Crypto_30_LibCv_GetKeyGenP256R1OfPCPartitionConfig()[(Index)].WorkspaceOfKeyGenP256R1)
#define Crypto_30_LibCv_GetWorkspaceOfKeyGenP384R1(Index)                                             /**< Deactivateable: 'Crypto_30_LibCv_KeyGenP384R1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyGenP521R1(Index)                                             /**< Deactivateable: 'Crypto_30_LibCv_KeyGenP521R1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyGenSm2P256V1(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyGenSm2P256V1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyGenSymGeneric(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_KeyGenSymGeneric.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetKeyLock(Index)                                                           (Crypto_30_LibCv_GetKeyLockOfPCPartitionConfig()[(Index)])
#define Crypto_30_LibCv_GetKeyNvStatus(Index)                                                       (Crypto_30_LibCv_GetKeyNvStatusOfPCPartitionConfig()[(Index)])
#define Crypto_30_LibCv_GetWorkspaceOfKeyP224R1BDPubVal(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_KeyP224R1BDPubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyP224R1BDSecret(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_KeyP224R1BDSecret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyP256R1BDPubVal(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1BDPubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyP256R1BDSecret(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1BDSecret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyP256R1PubVal(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyP256R1Secret(Index)                                        (Crypto_30_LibCv_GetKeyP256R1SecretOfPCPartitionConfig()[(Index)].WorkspaceOfKeyP256R1Secret)
#define Crypto_30_LibCv_GetWorkspaceOfKeyP384R1PubVal(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP384R1PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyP384R1Secret(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP384R1Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyP521R1PubVal(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP521R1PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyP521R1Secret(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP521R1Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeySeedDRBGAES(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_KeySeedDRBGAES.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeySeedDRBGHashSha512(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_KeySeedDRBGHashSha512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeySeedFips186(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_KeySeedFips186.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeySetInvalidJob(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_KeySetInvalidJob.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeySetValidJob(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_KeySetValidJob.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeySpake2PPubVal(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_KeySpake2PPubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeySpake2PSecret(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_KeySpake2PSecret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetKeyStorage(Index)                                                        (Crypto_30_LibCv_GetKeyStorageOfPCPartitionConfig()[(Index)])
#define Crypto_30_LibCv_GetWorkspaceOfKeyX25519PubVal(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyX25519PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyX25519Secret(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyX25519Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyX448PubVal(Index)                                            /**< Deactivateable: 'Crypto_30_LibCv_KeyX448PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyX448Secret(Index)                                            /**< Deactivateable: 'Crypto_30_LibCv_KeyX448Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetFamilyOfLastJob(Index)                                                     /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Family' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_GetKeyIdOfLastJob(Index)                                                      /**< Deactivateable: 'Crypto_30_LibCv_LastJob.KeyId' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_GetModeOfLastJob(Index)                                                       /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Mode' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_GetLock(Index)                                                              (Crypto_30_LibCv_GetLockOfPCPartitionConfig()[(Index)])
#define Crypto_30_LibCv_GetLongTermWs(Index)                                                          /**< Deactivateable: 'Crypto_30_LibCv_LongTermWs' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetLongTermWsLock(Index)                                                      /**< Deactivateable: 'Crypto_30_LibCv_LongTermWsLock' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfMD5(Index)                                                      /**< Deactivateable: 'Crypto_30_LibCv_MD5.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetConsistencyLevelOfNvBlock(Index)                                         (Crypto_30_LibCv_GetNvBlockOfPCPartitionConfig()[(Index)].ConsistencyLevelOfNvBlock)
#define Crypto_30_LibCv_GetCrcOfNvBlock(Index)                                                      (Crypto_30_LibCv_GetNvBlockOfPCPartitionConfig()[(Index)].CrcOfNvBlock)
#define Crypto_30_LibCv_GetDescriptorOfNvBlock(Index)                                               (Crypto_30_LibCv_GetNvBlockOfPCPartitionConfig()[(Index)].DescriptorOfNvBlock)
#define Crypto_30_LibCv_GetIdOfNvBlock(Index)                                                       (Crypto_30_LibCv_GetNvBlockOfPCPartitionConfig()[(Index)].IdOfNvBlock)
#define Crypto_30_LibCv_GetKeyStorageEndIdxOfNvBlock(Index)                                         (Crypto_30_LibCv_GetNvBlockOfPCPartitionConfig()[(Index)].KeyStorageEndIdxOfNvBlock)
#define Crypto_30_LibCv_GetKeyStorageStartIdxOfNvBlock(Index)                                       (Crypto_30_LibCv_GetNvBlockOfPCPartitionConfig()[(Index)].KeyStorageStartIdxOfNvBlock)
#define Crypto_30_LibCv_GetLengthOfNvBlock(Index)                                                   (Crypto_30_LibCv_GetNvBlockOfPCPartitionConfig()[(Index)].LengthOfNvBlock)
#define Crypto_30_LibCv_GetProcessingOfNvBlock(Index)                                               (Crypto_30_LibCv_GetNvBlockOfPCPartitionConfig()[(Index)].ProcessingOfNvBlock)
#define Crypto_30_LibCv_GetAEADChaChaPoly1305DecryptIdxOfObjectInfo(Index)                          (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].AEADChaChaPoly1305DecryptIdxOfObjectInfo)
#define Crypto_30_LibCv_GetAEADChaChaPoly1305EncryptIdxOfObjectInfo(Index)                          (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].AEADChaChaPoly1305EncryptIdxOfObjectInfo)
#define Crypto_30_LibCv_GetAesCcmDecryptIdxOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmDecryptIdx' Reason: 'the optional indirection is deactivated because AesCcmDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsAesCcmDecryptUsedOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmDecryptUsed' Reason: 'the optional indirection is deactivated because AesCcmDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetAesCcmEncryptIdxOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmEncryptIdx' Reason: 'the optional indirection is deactivated because AesCcmEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsAesCcmEncryptUsedOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmEncryptUsed' Reason: 'the optional indirection is deactivated because AesCcmEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetAesDecryptIdxOfObjectInfo(Index)                                         (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].AesDecryptIdxOfObjectInfo)
#define Crypto_30_LibCv_GetAesEncryptIdxOfObjectInfo(Index)                                         (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].AesEncryptIdxOfObjectInfo)
#define Crypto_30_LibCv_GetAesGcmDecryptIdxOfObjectInfo(Index)                                      (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].AesGcmDecryptIdxOfObjectInfo)
#define Crypto_30_LibCv_GetAesGcmEncryptIdxOfObjectInfo(Index)                                      (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].AesGcmEncryptIdxOfObjectInfo)
#define Crypto_30_LibCv_GetApplicationIdOfObjectInfo(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.ApplicationId' Reason: 'Deactivated for use case Single Partition' */
#define Crypto_30_LibCv_GetCmacAesGenerateIdxOfObjectInfo(Index)                                    (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].CmacAesGenerateIdxOfObjectInfo)
#define Crypto_30_LibCv_GetCmacAesVerifyIdxOfObjectInfo(Index)                                      (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].CmacAesVerifyIdxOfObjectInfo)
#define Crypto_30_LibCv_GetDRBGAESIdxOfObjectInfo(Index)                                            (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].DRBGAESIdxOfObjectInfo)
#define Crypto_30_LibCv_GetDRBGHashSha512IdxOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.DRBGHashSha512Idx' Reason: 'the optional indirection is deactivated because DRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsDRBGHashSha512UsedOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.DRBGHashSha512Used' Reason: 'the optional indirection is deactivated because DRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetEcP160GenerateIdxOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160GenerateIdx' Reason: 'the optional indirection is deactivated because EcP160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsEcP160GenerateUsedOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160GenerateUsed' Reason: 'the optional indirection is deactivated because EcP160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetEcP160VerifyIdxOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160VerifyIdx' Reason: 'the optional indirection is deactivated because EcP160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsEcP160VerifyUsedOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160VerifyUsed' Reason: 'the optional indirection is deactivated because EcP160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetEcP256GenerateIdxOfObjectInfo(Index)                                     (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].EcP256GenerateIdxOfObjectInfo)
#define Crypto_30_LibCv_GetEcP256VerifyIdxOfObjectInfo(Index)                                       (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].EcP256VerifyIdxOfObjectInfo)
#define Crypto_30_LibCv_GetEcP384GenerateIdxOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384GenerateIdx' Reason: 'the optional indirection is deactivated because EcP384GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsEcP384GenerateUsedOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384GenerateUsed' Reason: 'the optional indirection is deactivated because EcP384GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetEcP384VerifyIdxOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384VerifyIdx' Reason: 'the optional indirection is deactivated because EcP384VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsEcP384VerifyUsedOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384VerifyUsed' Reason: 'the optional indirection is deactivated because EcP384VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetEcP521GenerateIdxOfObjectInfo(Index)                                     (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].EcP521GenerateIdxOfObjectInfo)
#define Crypto_30_LibCv_GetEcP521VerifyIdxOfObjectInfo(Index)                                       (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].EcP521VerifyIdxOfObjectInfo)
#define Crypto_30_LibCv_GetEcPKeyCheckIdxOfObjectInfo(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcPKeyCheckIdx' Reason: 'the optional indirection is deactivated because EcPKeyCheckUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsEcPKeyCheckUsedOfObjectInfo(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcPKeyCheckUsed' Reason: 'the optional indirection is deactivated because EcPKeyCheckUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetEd25519GenerateIdxOfObjectInfo(Index)                                    (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].Ed25519GenerateIdxOfObjectInfo)
#define Crypto_30_LibCv_GetEd25519VerifyIdxOfObjectInfo(Index)                                      (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].Ed25519VerifyIdxOfObjectInfo)
#define Crypto_30_LibCv_GetEd448GenerateIdxOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Ed448GenerateIdx' Reason: 'the optional indirection is deactivated because Ed448GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsEd448GenerateUsedOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Ed448GenerateUsed' Reason: 'the optional indirection is deactivated because Ed448GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetEd448VerifyIdxOfObjectInfo(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Ed448VerifyIdx' Reason: 'the optional indirection is deactivated because Ed448VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsEd448VerifyUsedOfObjectInfo(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Ed448VerifyUsed' Reason: 'the optional indirection is deactivated because Ed448VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetEdKeyCheckIdxOfObjectInfo(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EdKeyCheckIdx' Reason: 'the optional indirection is deactivated because EdKeyCheckUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsEdKeyCheckUsedOfObjectInfo(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EdKeyCheckUsed' Reason: 'the optional indirection is deactivated because EdKeyCheckUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetFips186IdxOfObjectInfo(Index)                                            (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].Fips186IdxOfObjectInfo)
#define Crypto_30_LibCv_GetGmacAesGenerateIdxOfObjectInfo(Index)                                    (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].GmacAesGenerateIdxOfObjectInfo)
#define Crypto_30_LibCv_GetGmacAesVerifyIdxOfObjectInfo(Index)                                      (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].GmacAesVerifyIdxOfObjectInfo)
#define Crypto_30_LibCv_GetHashIdxOfObjectInfo(Index)                                               (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].HashIdxOfObjectInfo)
#define Crypto_30_LibCv_GetHmacRipeMd160GenerateIdxOfObjectInfo(Index)                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160GenerateIdx' Reason: 'the optional indirection is deactivated because HmacRipeMd160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsHmacRipeMd160GenerateUsedOfObjectInfo(Index)                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160GenerateUsed' Reason: 'the optional indirection is deactivated because HmacRipeMd160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetHmacRipeMd160VerifyIdxOfObjectInfo(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160VerifyIdx' Reason: 'the optional indirection is deactivated because HmacRipeMd160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsHmacRipeMd160VerifyUsedOfObjectInfo(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160VerifyUsed' Reason: 'the optional indirection is deactivated because HmacRipeMd160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetHmacSha1GenerateIdxOfObjectInfo(Index)                                   (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].HmacSha1GenerateIdxOfObjectInfo)
#define Crypto_30_LibCv_GetHmacSha1VerifyIdxOfObjectInfo(Index)                                     (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].HmacSha1VerifyIdxOfObjectInfo)
#define Crypto_30_LibCv_GetHmacSha256GenerateIdxOfObjectInfo(Index)                                 (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].HmacSha256GenerateIdxOfObjectInfo)
#define Crypto_30_LibCv_GetHmacSha256VerifyIdxOfObjectInfo(Index)                                   (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].HmacSha256VerifyIdxOfObjectInfo)
#define Crypto_30_LibCv_GetHmacSha384GenerateIdxOfObjectInfo(Index)                                 (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].HmacSha384GenerateIdxOfObjectInfo)
#define Crypto_30_LibCv_GetHmacSha384VerifyIdxOfObjectInfo(Index)                                   (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].HmacSha384VerifyIdxOfObjectInfo)
#define Crypto_30_LibCv_GetHmacSha512GenerateIdxOfObjectInfo(Index)                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha512GenerateIdx' Reason: 'the optional indirection is deactivated because HmacSha512GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsHmacSha512GenerateUsedOfObjectInfo(Index)                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha512GenerateUsed' Reason: 'the optional indirection is deactivated because HmacSha512GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetHmacSha512VerifyIdxOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha512VerifyIdx' Reason: 'the optional indirection is deactivated because HmacSha512VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsHmacSha512VerifyUsedOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha512VerifyUsed' Reason: 'the optional indirection is deactivated because HmacSha512VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveHKDFExpandHMACSHA256IdxOfObjectInfo(Index)                      (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].KeyDeriveHKDFExpandHMACSHA256IdxOfObjectInfo)
#define Crypto_30_LibCv_GetKeyDeriveHKDFExpandHMACSHA384IdxOfObjectInfo(Index)                      (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].KeyDeriveHKDFExpandHMACSHA384IdxOfObjectInfo)
#define Crypto_30_LibCv_GetKeyDeriveHKDFHMACSHA256IdxOfObjectInfo(Index)                            (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].KeyDeriveHKDFHMACSHA256IdxOfObjectInfo)
#define Crypto_30_LibCv_GetKeyDeriveHKDFHMACSHA384IdxOfObjectInfo(Index)                            (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].KeyDeriveHKDFHMACSHA384IdxOfObjectInfo)
#define Crypto_30_LibCv_GetKeyDeriveHKDFHashOption1SHA256IdxOfObjectInfo(Index)                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHashOption1SHA256Idx' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHashOption1SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveHKDFHashOption1SHA256UsedOfObjectInfo(Index)                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHashOption1SHA256Used' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHashOption1SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveHKDFHashOption1SHA512IdxOfObjectInfo(Index)                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHashOption1SHA512Idx' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHashOption1SHA512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveHKDFHashOption1SHA512UsedOfObjectInfo(Index)                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHashOption1SHA512Used' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHashOption1SHA512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveISO15118IdxOfObjectInfo(Index)                                  (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].KeyDeriveISO15118IdxOfObjectInfo)
#define Crypto_30_LibCv_GetKeyDeriveISO15118_20IdxOfObjectInfo(Index)                               (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].KeyDeriveISO15118_20IdxOfObjectInfo)
#define Crypto_30_LibCv_GetKeyDeriveKDF2HMACSHA1IdxOfObjectInfo(Index)                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA1Idx' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveKDF2HMACSHA1UsedOfObjectInfo(Index)                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA1Used' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveKDF2HMACSHA256IdxOfObjectInfo(Index)                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA256Idx' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveKDF2HMACSHA256UsedOfObjectInfo(Index)                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA256Used' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveNist800108CntIdxOfObjectInfo(Index)                               /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist800108CntIdx' Reason: 'the optional indirection is deactivated because KeyDeriveNist800108CntUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveNist800108CntUsedOfObjectInfo(Index)                               /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist800108CntUsed' Reason: 'the optional indirection is deactivated because KeyDeriveNist800108CntUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveNist80056AOnePassIdxOfObjectInfo(Index)                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist80056AOnePassIdx' Reason: 'the optional indirection is deactivated because KeyDeriveNist80056AOnePassUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveNist80056AOnePassUsedOfObjectInfo(Index)                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist80056AOnePassUsed' Reason: 'the optional indirection is deactivated because KeyDeriveNist80056AOnePassUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveNistFips186ErbIdxOfObjectInfo(Index)                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNistFips186ErbIdx' Reason: 'the optional indirection is deactivated because KeyDeriveNistFips186ErbUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveNistFips186ErbUsedOfObjectInfo(Index)                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNistFips186ErbUsed' Reason: 'the optional indirection is deactivated because KeyDeriveNistFips186ErbUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveSpake2PIdxOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveSpake2PIdx' Reason: 'the optional indirection is deactivated because KeyDeriveSpake2PUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveSpake2PUsedOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveSpake2PUsed' Reason: 'the optional indirection is deactivated because KeyDeriveSpake2PUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveX963SHA256IdxOfObjectInfo(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA256Idx' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveX963SHA256UsedOfObjectInfo(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA256Used' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveX963SHA512IdxOfObjectInfo(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA512Idx' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveX963SHA512UsedOfObjectInfo(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA512Used' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyGenEd25519IdxOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenEd25519Idx' Reason: 'the optional indirection is deactivated because KeyGenEd25519UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyGenEd25519UsedOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenEd25519Used' Reason: 'the optional indirection is deactivated because KeyGenEd25519UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyGenP256R1IdxOfObjectInfo(Index)                                       (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].KeyGenP256R1IdxOfObjectInfo)
#define Crypto_30_LibCv_GetKeyGenP384R1IdxOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP384R1Idx' Reason: 'the optional indirection is deactivated because KeyGenP384R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyGenP384R1UsedOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP384R1Used' Reason: 'the optional indirection is deactivated because KeyGenP384R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyGenP521R1IdxOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP521R1Idx' Reason: 'the optional indirection is deactivated because KeyGenP521R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyGenP521R1UsedOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP521R1Used' Reason: 'the optional indirection is deactivated because KeyGenP521R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyGenSm2P256V1IdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenSm2P256V1Idx' Reason: 'the optional indirection is deactivated because KeyGenSm2P256V1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyGenSm2P256V1UsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenSm2P256V1Used' Reason: 'the optional indirection is deactivated because KeyGenSm2P256V1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyGenSymGenericIdxOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenSymGenericIdx' Reason: 'the optional indirection is deactivated because KeyGenSymGenericUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyGenSymGenericUsedOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenSymGenericUsed' Reason: 'the optional indirection is deactivated because KeyGenSymGenericUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyP224R1BDPubValIdxOfObjectInfo(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDPubValIdx' Reason: 'the optional indirection is deactivated because KeyP224R1BDPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyP224R1BDPubValUsedOfObjectInfo(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDPubValUsed' Reason: 'the optional indirection is deactivated because KeyP224R1BDPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyP224R1BDSecretIdxOfObjectInfo(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDSecretIdx' Reason: 'the optional indirection is deactivated because KeyP224R1BDSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyP224R1BDSecretUsedOfObjectInfo(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDSecretUsed' Reason: 'the optional indirection is deactivated because KeyP224R1BDSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyP256R1BDPubValIdxOfObjectInfo(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1BDPubValIdx' Reason: 'the optional indirection is deactivated because KeyP256R1BDPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyP256R1BDPubValUsedOfObjectInfo(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1BDPubValUsed' Reason: 'the optional indirection is deactivated because KeyP256R1BDPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyP256R1BDSecretIdxOfObjectInfo(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1BDSecretIdx' Reason: 'the optional indirection is deactivated because KeyP256R1BDSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyP256R1BDSecretUsedOfObjectInfo(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1BDSecretUsed' Reason: 'the optional indirection is deactivated because KeyP256R1BDSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyP256R1PubValIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1PubValIdx' Reason: 'the optional indirection is deactivated because KeyP256R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyP256R1PubValUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1PubValUsed' Reason: 'the optional indirection is deactivated because KeyP256R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyP256R1SecretIdxOfObjectInfo(Index)                                    (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].KeyP256R1SecretIdxOfObjectInfo)
#define Crypto_30_LibCv_GetKeyP384R1PubValIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1PubValIdx' Reason: 'the optional indirection is deactivated because KeyP384R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyP384R1PubValUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1PubValUsed' Reason: 'the optional indirection is deactivated because KeyP384R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyP384R1SecretIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1SecretIdx' Reason: 'the optional indirection is deactivated because KeyP384R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyP384R1SecretUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1SecretUsed' Reason: 'the optional indirection is deactivated because KeyP384R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyP521R1PubValIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1PubValIdx' Reason: 'the optional indirection is deactivated because KeyP521R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyP521R1PubValUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1PubValUsed' Reason: 'the optional indirection is deactivated because KeyP521R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyP521R1SecretIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1SecretIdx' Reason: 'the optional indirection is deactivated because KeyP521R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyP521R1SecretUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1SecretUsed' Reason: 'the optional indirection is deactivated because KeyP521R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeySeedDRBGAESIdxOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGAESIdx' Reason: 'the optional indirection is deactivated because KeySeedDRBGAESUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeySeedDRBGAESUsedOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGAESUsed' Reason: 'the optional indirection is deactivated because KeySeedDRBGAESUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeySeedDRBGHashSha512IdxOfObjectInfo(Index)                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGHashSha512Idx' Reason: 'the optional indirection is deactivated because KeySeedDRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeySeedDRBGHashSha512UsedOfObjectInfo(Index)                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGHashSha512Used' Reason: 'the optional indirection is deactivated because KeySeedDRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeySeedFips186IdxOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedFips186Idx' Reason: 'the optional indirection is deactivated because KeySeedFips186UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeySeedFips186UsedOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedFips186Used' Reason: 'the optional indirection is deactivated because KeySeedFips186UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeySetInvalidJobIdxOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySetInvalidJobIdx' Reason: 'the optional indirection is deactivated because KeySetInvalidJobUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeySetInvalidJobUsedOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySetInvalidJobUsed' Reason: 'the optional indirection is deactivated because KeySetInvalidJobUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeySetValidJobIdxOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySetValidJobIdx' Reason: 'the optional indirection is deactivated because KeySetValidJobUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeySetValidJobUsedOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySetValidJobUsed' Reason: 'the optional indirection is deactivated because KeySetValidJobUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeySpake2PPubValIdxOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PPubValIdx' Reason: 'the optional indirection is deactivated because KeySpake2PPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeySpake2PPubValUsedOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PPubValUsed' Reason: 'the optional indirection is deactivated because KeySpake2PPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeySpake2PSecretIdxOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PSecretIdx' Reason: 'the optional indirection is deactivated because KeySpake2PSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeySpake2PSecretUsedOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PSecretUsed' Reason: 'the optional indirection is deactivated because KeySpake2PSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyX25519PubValIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519PubValIdx' Reason: 'the optional indirection is deactivated because KeyX25519PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyX25519PubValUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519PubValUsed' Reason: 'the optional indirection is deactivated because KeyX25519PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyX25519SecretIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519SecretIdx' Reason: 'the optional indirection is deactivated because KeyX25519SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyX25519SecretUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519SecretUsed' Reason: 'the optional indirection is deactivated because KeyX25519SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyX448PubValIdxOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX448PubValIdx' Reason: 'the optional indirection is deactivated because KeyX448PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyX448PubValUsedOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX448PubValUsed' Reason: 'the optional indirection is deactivated because KeyX448PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyX448SecretIdxOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX448SecretIdx' Reason: 'the optional indirection is deactivated because KeyX448SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyX448SecretUsedOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX448SecretUsed' Reason: 'the optional indirection is deactivated because KeyX448SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetMD5IdxOfObjectInfo(Index)                                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.MD5Idx' Reason: 'the optional indirection is deactivated because MD5UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsMD5UsedOfObjectInfo(Index)                                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.MD5Used' Reason: 'the optional indirection is deactivated because MD5UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetPartitionIdxOfObjectInfo(Index)                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.PartitionIdx' Reason: 'Deactivated for use case Single Partition' */
#define Crypto_30_LibCv_GetQueueIdxOfObjectInfo(Index)                                              (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].QueueIdxOfObjectInfo)
#define Crypto_30_LibCv_GetRandomSeedBufferEndIdxOfObjectInfo(Index)                                (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].RandomSeedBufferEndIdxOfObjectInfo)
#define Crypto_30_LibCv_GetRandomSeedBufferStartIdxOfObjectInfo(Index)                              (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].RandomSeedBufferStartIdxOfObjectInfo)
#define Crypto_30_LibCv_GetRsaOaepCrtSha1DecryptIdxOfObjectInfo(Index)                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha1DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaOaepCrtSha1DecryptUsedOfObjectInfo(Index)                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha1DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaOaepCrtSha256DecryptIdxOfObjectInfo(Index)                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha256DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaOaepCrtSha256DecryptUsedOfObjectInfo(Index)                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha256DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaOaepSha1DecryptIdxOfObjectInfo(Index)                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaOaepSha1DecryptUsedOfObjectInfo(Index)                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaOaepSha1EncryptIdxOfObjectInfo(Index)                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1EncryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaOaepSha1EncryptUsedOfObjectInfo(Index)                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1EncryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaOaepSha256DecryptIdxOfObjectInfo(Index)                                 /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaOaepSha256DecryptUsedOfObjectInfo(Index)                                 /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaOaepSha256EncryptIdxOfObjectInfo(Index)                                 /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256EncryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha256EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaOaepSha256EncryptUsedOfObjectInfo(Index)                                 /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256EncryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha256EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaPkcs1CrtGenerateIdxOfObjectInfo(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1CrtGenerateIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1CrtGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaPkcs1CrtGenerateUsedOfObjectInfo(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1CrtGenerateUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1CrtGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaPkcs1DecryptIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1DecryptIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaPkcs1DecryptUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1DecryptUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaPkcs1EncryptIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1EncryptIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaPkcs1EncryptUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1EncryptUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaPkcs1GenerateIdxOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1GenerateIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaPkcs1GenerateUsedOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1GenerateUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaPkcs1VerifyIdxOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1VerifyIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaPkcs1VerifyUsedOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1VerifyUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaPssGenerateIdxOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssGenerateIdx' Reason: 'the optional indirection is deactivated because RsaPssGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaPssGenerateUsedOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssGenerateUsed' Reason: 'the optional indirection is deactivated because RsaPssGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaPssVerifyIdxOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssVerifyIdx' Reason: 'the optional indirection is deactivated because RsaPssVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaPssVerifyUsedOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssVerifyUsed' Reason: 'the optional indirection is deactivated because RsaPssVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetSheCmdGetIdIdxOfObjectInfo(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SheCmdGetIdIdx' Reason: 'the optional indirection is deactivated because SheCmdGetIdUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsSheCmdGetIdUsedOfObjectInfo(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SheCmdGetIdUsed' Reason: 'the optional indirection is deactivated because SheCmdGetIdUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetSipHashGenerateIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashGenerateIdx' Reason: 'the optional indirection is deactivated because SipHashGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsSipHashGenerateUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashGenerateUsed' Reason: 'the optional indirection is deactivated because SipHashGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetSipHashVerifyIdxOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashVerifyIdx' Reason: 'the optional indirection is deactivated because SipHashVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsSipHashVerifyUsedOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashVerifyUsed' Reason: 'the optional indirection is deactivated because SipHashVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetSlhDsaVerifyIdxOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SlhDsaVerifyIdx' Reason: 'the optional indirection is deactivated because SlhDsaVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsSlhDsaVerifyUsedOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SlhDsaVerifyUsed' Reason: 'the optional indirection is deactivated because SlhDsaVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetSm2GenerateIdxOfObjectInfo(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm2GenerateIdx' Reason: 'the optional indirection is deactivated because Sm2GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsSm2GenerateUsedOfObjectInfo(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm2GenerateUsed' Reason: 'the optional indirection is deactivated because Sm2GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetSm2VerifyIdxOfObjectInfo(Index)                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm2VerifyIdx' Reason: 'the optional indirection is deactivated because Sm2VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsSm2VerifyUsedOfObjectInfo(Index)                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm2VerifyUsed' Reason: 'the optional indirection is deactivated because Sm2VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetSm4DecryptIdxOfObjectInfo(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm4DecryptIdx' Reason: 'the optional indirection is deactivated because Sm4DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsSm4DecryptUsedOfObjectInfo(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm4DecryptUsed' Reason: 'the optional indirection is deactivated because Sm4DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetSm4EncryptIdxOfObjectInfo(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm4EncryptIdx' Reason: 'the optional indirection is deactivated because Sm4EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsSm4EncryptUsedOfObjectInfo(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm4EncryptUsed' Reason: 'the optional indirection is deactivated because Sm4EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetWorkspaceAddrOfObjectInfo(Index)                                         (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].WorkspaceAddrOfObjectInfo)
#define Crypto_30_LibCv_GetWorkspaceLengthOfObjectInfo(Index)                                       (Crypto_30_LibCv_GetObjectInfoOfPCPartitionConfig()[(Index)].WorkspaceLengthOfObjectInfo)
#define Crypto_30_LibCv_GetObjectInfoInd(Index)                                                     (Crypto_30_LibCv_GetObjectInfoIndOfPCPartitionConfig()[(Index)])
#define Crypto_30_LibCv_GetPCPartitionConfigIdxOfPartitionIdentifiers(Index)                        (Crypto_30_LibCv_GetPartitionIdentifiersOfPCConfig()[(Index)].PCPartitionConfigIdxOfPartitionIdentifiers)
#define Crypto_30_LibCv_GetPartitionSNVOfPartitionIdentifiers(Index)                                (Crypto_30_LibCv_GetPartitionIdentifiersOfPCConfig()[(Index)].PartitionSNVOfPartitionIdentifiers)
#define Crypto_30_LibCv_GetDefaultRandomKeyOfPartitionInfo(Index)                                   (Crypto_30_LibCv_GetPartitionInfoOfPCPartitionConfig()[(Index)].DefaultRandomKeyOfPartitionInfo)
#define Crypto_30_LibCv_GetMaskedBitsOfPartitionInfo(Index)                                         (Crypto_30_LibCv_GetPartitionInfoOfPCPartitionConfig()[(Index)].MaskedBitsOfPartitionInfo)
#define Crypto_30_LibCv_GetPartitionInitialized(partitionIndex)                                     ((*(Crypto_30_LibCv_GetPartitionInitializedOfPCPartitionConfig(partitionIndex))))
#define Crypto_30_LibCv_GetDispatchOfPrimitiveFct(Index)                                            (Crypto_30_LibCv_GetPrimitiveFctOfPCPartitionConfig()[(Index)].DispatchOfPrimitiveFct)
#define Crypto_30_LibCv_GetObjectInfoIndEndIdxOfPrimitiveFct(Index)                                 (Crypto_30_LibCv_GetPrimitiveFctOfPCPartitionConfig()[(Index)].ObjectInfoIndEndIdxOfPrimitiveFct)
#define Crypto_30_LibCv_GetObjectInfoIndStartIdxOfPrimitiveFct(Index)                               (Crypto_30_LibCv_GetPrimitiveFctOfPCPartitionConfig()[(Index)].ObjectInfoIndStartIdxOfPrimitiveFct)
#define Crypto_30_LibCv_GetCombinedOfPrimitiveInfo(Index)                                           (Crypto_30_LibCv_GetPrimitiveInfoOfPCPartitionConfig()[(Index)].CombinedOfPrimitiveInfo)
#define Crypto_30_LibCv_GetMaskedBitsOfPrimitiveInfo(Index)                                         (Crypto_30_LibCv_GetPrimitiveInfoOfPCPartitionConfig()[(Index)].MaskedBitsOfPrimitiveInfo)
#define Crypto_30_LibCv_GetPrimitiveFctIdxOfPrimitiveInfo(Index)                                    (Crypto_30_LibCv_GetPrimitiveInfoOfPCPartitionConfig()[(Index)].PrimitiveFctIdxOfPrimitiveInfo)
#define Crypto_30_LibCv_GetPrimitiveInfoEndIdxOfPrimitiveServiceInfo(Index)                         (Crypto_30_LibCv_GetPrimitiveServiceInfoOfPCPartitionConfig()[(Index)].PrimitiveInfoEndIdxOfPrimitiveServiceInfo)
#define Crypto_30_LibCv_GetPrimitiveInfoStartIdxOfPrimitiveServiceInfo(Index)                       (Crypto_30_LibCv_GetPrimitiveServiceInfoOfPCPartitionConfig()[(Index)].PrimitiveInfoStartIdxOfPrimitiveServiceInfo)
#define Crypto_30_LibCv_IsProcessJob_Trigger_Write(Index)                                           ((Crypto_30_LibCv_GetProcessJob_Trigger_WriteOfPCPartitionConfig()[(Index)]) != FALSE)
#define Crypto_30_LibCv_GetQueue(Index)                                                             (Crypto_30_LibCv_GetQueueOfPCPartitionConfig()[(Index)])
#define Crypto_30_LibCv_GetRandomSeedBuffer(Index)                                                  (Crypto_30_LibCv_GetRandomSeedBufferOfPCPartitionConfig()[(Index)])
#define Crypto_30_LibCv_GetRandomSourceGenerateCount(partitionIndex)                                ((*(Crypto_30_LibCv_GetRandomSourceGenerateCountOfPCPartitionConfig(partitionIndex))))
#define Crypto_30_LibCv_GetRedirect_Buffer(Index)                                                   (Crypto_30_LibCv_GetRedirect_BufferOfPCPartitionConfig()[(Index)])
#define Crypto_30_LibCv_GetWorkspaceOfRsaOaepCrtSha1Decrypt(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepCrtSha1Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaOaepCrtSha256Decrypt(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepCrtSha256Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaOaepSha1Decrypt(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha1Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaOaepSha1Encrypt(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha1Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaOaepSha256Decrypt(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha256Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaOaepSha256Encrypt(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha256Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaPkcs1CrtGenerate(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1CrtGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaPkcs1Decrypt(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaPkcs1Encrypt(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaPkcs1Generate(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaPkcs1Verify(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaPssGenerate(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_RsaPssGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaPssVerify(Index)                                             /**< Deactivateable: 'Crypto_30_LibCv_RsaPssVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetLengthOfSaveAndRestoreWorkspace(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_SaveAndRestoreWorkspace.Length' Reason: 'Disable Feature if no Context primitive is used' */
#define Crypto_30_LibCv_GetWorkspaceOfSheCmdGetId(Index)                                              /**< Deactivateable: 'Crypto_30_LibCv_SheCmdGetId.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfSipHashGenerate(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_SipHashGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfSipHashVerify(Index)                                            /**< Deactivateable: 'Crypto_30_LibCv_SipHashVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfSlhDsaVerify(Index)                                             /**< Deactivateable: 'Crypto_30_LibCv_SlhDsaVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfSm2Generate(Index)                                              /**< Deactivateable: 'Crypto_30_LibCv_Sm2Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfSm2Verify(Index)                                                /**< Deactivateable: 'Crypto_30_LibCv_Sm2Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfSm4Decrypt(Index)                                               /**< Deactivateable: 'Crypto_30_LibCv_Sm4Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfSm4Encrypt(Index)                                               /**< Deactivateable: 'Crypto_30_LibCv_Sm4Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0(Index)                  (Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Conn0OfPCPartitionConfig()[(Index)].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0)
#define Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished(Index) (Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_FinishedOfPCPartitionConfig()[(Index)].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished)
#define Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1(Index)                  (Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Conn1OfPCPartitionConfig()[(Index)].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1)
#define Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished(Index) (Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_FinishedOfPCPartitionConfig()[(Index)].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished)
#define Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384(Index)    (Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384OfPCPartitionConfig()[(Index)].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384)
#define Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384(Index)      (Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384OfPCPartitionConfig()[(Index)].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384)
#define Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1(Index)        (Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1OfPCPartitionConfig()[(Index)].DataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1)
#define Crypto_30_LibCv_GetDataOfStructUnionWS_Crypto_30_LibCv(Index)                               (Crypto_30_LibCv_GetStructUnionWS_Crypto_30_LibCvOfPCPartitionConfig()[(Index)].DataOfStructUnionWS_Crypto_30_LibCv)
#define Crypto_30_LibCv_GetDataOfStructUnionWS_Crypto_30_LibCv_General(Index)                       (Crypto_30_LibCv_GetStructUnionWS_Crypto_30_LibCv_GeneralOfPCPartitionConfig()[(Index)].DataOfStructUnionWS_Crypto_30_LibCv_General)
#define Crypto_30_LibCv_GetWrittenLength(Index)                                                     (Crypto_30_LibCv_GetWrittenLengthOfPCPartitionConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCGetBitDataMacros  Crypto_30_LibCv Get Bit Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read bitcoded data elements.
  \{
*/ 
#define Crypto_30_LibCv_IsOnceOfKeyElementInfo(Index)                                               (CRYPTO_30_LIBCV_ONCEOFKEYELEMENTINFO_MASK == (Crypto_30_LibCv_GetMaskedBitsOfKeyElementInfo(Index) & CRYPTO_30_LIBCV_ONCEOFKEYELEMENTINFO_MASK))
#define Crypto_30_LibCv_IsPartialOfKeyElementInfo(Index)                                            (CRYPTO_30_LIBCV_PARTIALOFKEYELEMENTINFO_MASK == (Crypto_30_LibCv_GetMaskedBitsOfKeyElementInfo(Index) & CRYPTO_30_LIBCV_PARTIALOFKEYELEMENTINFO_MASK))
#define Crypto_30_LibCv_IsPersistOfKeyElementInfo(Index)                                            (CRYPTO_30_LIBCV_PERSISTOFKEYELEMENTINFO_MASK == (Crypto_30_LibCv_GetMaskedBitsOfKeyElementInfo(Index) & CRYPTO_30_LIBCV_PERSISTOFKEYELEMENTINFO_MASK))
#define Crypto_30_LibCv_IsAesOfPartitionInfo(Index)                                                 (CRYPTO_30_LIBCV_AESOFPARTITIONINFO_MASK == (Crypto_30_LibCv_GetMaskedBitsOfPartitionInfo(Index) & CRYPTO_30_LIBCV_AESOFPARTITIONINFO_MASK))  /**< Holds the information if the primitive is AES */
#define Crypto_30_LibCv_IsHashOfPartitionInfo(Index)                                                (CRYPTO_30_LIBCV_HASHOFPARTITIONINFO_MASK == (Crypto_30_LibCv_GetMaskedBitsOfPartitionInfo(Index) & CRYPTO_30_LIBCV_HASHOFPARTITIONINFO_MASK))  /**< Holds the information if the primitive is Hash */
#define Crypto_30_LibCv_IsContextOfPrimitiveInfo(Index)                                             (CRYPTO_30_LIBCV_CONTEXTOFPRIMITIVEINFO_MASK == (Crypto_30_LibCv_GetMaskedBitsOfPrimitiveInfo(Index) & CRYPTO_30_LIBCV_CONTEXTOFPRIMITIVEINFO_MASK))
#define Crypto_30_LibCv_IsDefaultRandomSourceOfPrimitiveInfo(Index)                                 (CRYPTO_30_LIBCV_DEFAULTRANDOMSOURCEOFPRIMITIVEINFO_MASK == (Crypto_30_LibCv_GetMaskedBitsOfPrimitiveInfo(Index) & CRYPTO_30_LIBCV_DEFAULTRANDOMSOURCEOFPRIMITIVEINFO_MASK))
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCGetDeduplicatedDataMacros  Crypto_30_LibCv Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Crypto_30_LibCv_GetExpectedCompatibilityVersion(partitionIndex)                               /**< Deactivateable: 'Crypto_30_LibCv_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_LibCv_GetFinalMagicNumber()                                                         /**< Deactivateable: 'Crypto_30_LibCv_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_LibCv_GetGeneratorCompatibilityVersion(partitionIndex)                              /**< Deactivateable: 'Crypto_30_LibCv_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_LibCv_GetInitDataHashCode()                                                         /**< Deactivateable: 'Crypto_30_LibCv_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_LibCv_IsNvBlockUsedOfKey(Index)                                                   (((boolean)(Crypto_30_LibCv_GetNvBlockIdxOfKey(Index) != CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_NvBlock */
#define Crypto_30_LibCv_IsInitValueUsedOfKeyElementInfo(Index)                                      (((boolean)(Crypto_30_LibCv_GetInitValueStartIdxOfKeyElementInfo(Index) != CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Crypto_30_LibCv_InitValue */
#define Crypto_30_LibCv_GetKeyStorageExtensionIdxOfKeyElements(Index)                               ((Crypto_30_LibCv_KeyStorageExtensionIdxOfKeyElementsType)((Crypto_30_LibCv_GetKeyStorageStartIdxOfKeyElements(Index) - 1u)))  /**< the index of the 1:1 relation pointing to Crypto_30_LibCv_KeyStorage */
#define Crypto_30_LibCv_GetKeyStorageValidIdxOfKeyElements(Index)                                   ((Crypto_30_LibCv_KeyStorageValidIdxOfKeyElementsType)((Crypto_30_LibCv_GetKeyStorageStartIdxOfKeyElements(Index) - 2u)))  /**< the index of the 1:1 relation pointing to Crypto_30_LibCv_KeyStorage */
#define Crypto_30_LibCv_GetKeyStorageWrittenLengthEndIdxOfKeyElements(Index)                        ((Crypto_30_LibCv_KeyStorageWrittenLengthEndIdxOfKeyElementsType)((Crypto_30_LibCv_GetKeyStorageStartIdxOfKeyElements(Index) - 2u)))  /**< the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage */
#define Crypto_30_LibCv_GetKeyStorageWrittenLengthStartIdxOfKeyElements(Index)                      ((Crypto_30_LibCv_KeyStorageWrittenLengthStartIdxOfKeyElementsType)((Crypto_30_LibCv_GetKeyStorageStartIdxOfKeyElements(Index) - 4u)))  /**< the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage */
#define Crypto_30_LibCv_GetMainFunctionPeriodOfGeneral(partitionIndex)                              Crypto_30_LibCv_GetMainFunctionPeriodOfGeneralOfPCPartitionConfig(partitionIndex)
#define Crypto_30_LibCv_IsAEADChaChaPoly1305DecryptUsedOfObjectInfo(Index)                          (((boolean)(Crypto_30_LibCv_GetAEADChaChaPoly1305DecryptIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_AEADChaChaPoly1305Decrypt */
#define Crypto_30_LibCv_IsAEADChaChaPoly1305EncryptUsedOfObjectInfo(Index)                          (((boolean)(Crypto_30_LibCv_GetAEADChaChaPoly1305EncryptIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_AEADChaChaPoly1305Encrypt */
#define Crypto_30_LibCv_IsAesDecryptUsedOfObjectInfo(Index)                                         (((boolean)(Crypto_30_LibCv_GetAesDecryptIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_AESDECRYPTIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_AesDecrypt */
#define Crypto_30_LibCv_IsAesEncryptUsedOfObjectInfo(Index)                                         (((boolean)(Crypto_30_LibCv_GetAesEncryptIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_AESENCRYPTIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_AesEncrypt */
#define Crypto_30_LibCv_IsAesGcmDecryptUsedOfObjectInfo(Index)                                      (((boolean)(Crypto_30_LibCv_GetAesGcmDecryptIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_AESGCMDECRYPTIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_AesGcmDecrypt */
#define Crypto_30_LibCv_IsAesGcmEncryptUsedOfObjectInfo(Index)                                      (((boolean)(Crypto_30_LibCv_GetAesGcmEncryptIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_AESGCMENCRYPTIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_AesGcmEncrypt */
#define Crypto_30_LibCv_IsCmacAesGenerateUsedOfObjectInfo(Index)                                    (((boolean)(Crypto_30_LibCv_GetCmacAesGenerateIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_CMACAESGENERATEIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_CmacAesGenerate */
#define Crypto_30_LibCv_IsCmacAesVerifyUsedOfObjectInfo(Index)                                      (((boolean)(Crypto_30_LibCv_GetCmacAesVerifyIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_CMACAESVERIFYIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_CmacAesVerify */
#define Crypto_30_LibCv_IsDRBGAESUsedOfObjectInfo(Index)                                            (((boolean)(Crypto_30_LibCv_GetDRBGAESIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_DRBGAESIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_DRBGAES */
#define Crypto_30_LibCv_IsEcP256GenerateUsedOfObjectInfo(Index)                                     (((boolean)(Crypto_30_LibCv_GetEcP256GenerateIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_ECP256GENERATEIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_EcP256Generate */
#define Crypto_30_LibCv_IsEcP256VerifyUsedOfObjectInfo(Index)                                       (((boolean)(Crypto_30_LibCv_GetEcP256VerifyIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_ECP256VERIFYIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_EcP256Verify */
#define Crypto_30_LibCv_IsEcP521GenerateUsedOfObjectInfo(Index)                                     (((boolean)(Crypto_30_LibCv_GetEcP521GenerateIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_ECP521GENERATEIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_EcP521Generate */
#define Crypto_30_LibCv_IsEcP521VerifyUsedOfObjectInfo(Index)                                       (((boolean)(Crypto_30_LibCv_GetEcP521VerifyIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_ECP521VERIFYIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_EcP521Verify */
#define Crypto_30_LibCv_IsEd25519GenerateUsedOfObjectInfo(Index)                                    (((boolean)(Crypto_30_LibCv_GetEd25519GenerateIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_ED25519GENERATEIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_Ed25519Generate */
#define Crypto_30_LibCv_IsEd25519VerifyUsedOfObjectInfo(Index)                                      (((boolean)(Crypto_30_LibCv_GetEd25519VerifyIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_ED25519VERIFYIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_Ed25519Verify */
#define Crypto_30_LibCv_IsFips186UsedOfObjectInfo(Index)                                            (((boolean)(Crypto_30_LibCv_GetFips186IdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_FIPS186IDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_Fips186 */
#define Crypto_30_LibCv_IsGmacAesGenerateUsedOfObjectInfo(Index)                                    (((boolean)(Crypto_30_LibCv_GetGmacAesGenerateIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_GMACAESGENERATEIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_GmacAesGenerate */
#define Crypto_30_LibCv_IsGmacAesVerifyUsedOfObjectInfo(Index)                                      (((boolean)(Crypto_30_LibCv_GetGmacAesVerifyIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_GMACAESVERIFYIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_GmacAesVerify */
#define Crypto_30_LibCv_IsHashUsedOfObjectInfo(Index)                                               (((boolean)(Crypto_30_LibCv_GetHashIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_HASHIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_Hash */
#define Crypto_30_LibCv_IsHmacSha1GenerateUsedOfObjectInfo(Index)                                   (((boolean)(Crypto_30_LibCv_GetHmacSha1GenerateIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_HMACSHA1GENERATEIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_HmacSha1Generate */
#define Crypto_30_LibCv_IsHmacSha1VerifyUsedOfObjectInfo(Index)                                     (((boolean)(Crypto_30_LibCv_GetHmacSha1VerifyIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_HMACSHA1VERIFYIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_HmacSha1Verify */
#define Crypto_30_LibCv_IsHmacSha256GenerateUsedOfObjectInfo(Index)                                 (((boolean)(Crypto_30_LibCv_GetHmacSha256GenerateIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_HMACSHA256GENERATEIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_HmacSha256Generate */
#define Crypto_30_LibCv_IsHmacSha256VerifyUsedOfObjectInfo(Index)                                   (((boolean)(Crypto_30_LibCv_GetHmacSha256VerifyIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_HMACSHA256VERIFYIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_HmacSha256Verify */
#define Crypto_30_LibCv_IsHmacSha384GenerateUsedOfObjectInfo(Index)                                 (((boolean)(Crypto_30_LibCv_GetHmacSha384GenerateIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_HMACSHA384GENERATEIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_HmacSha384Generate */
#define Crypto_30_LibCv_IsHmacSha384VerifyUsedOfObjectInfo(Index)                                   (((boolean)(Crypto_30_LibCv_GetHmacSha384VerifyIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_HMACSHA384VERIFYIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_HmacSha384Verify */
#define Crypto_30_LibCv_IsKeyDeriveHKDFExpandHMACSHA256UsedOfObjectInfo(Index)                      (((boolean)(Crypto_30_LibCv_GetKeyDeriveHKDFExpandHMACSHA256IdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFEXPANDHMACSHA256IDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256 */
#define Crypto_30_LibCv_IsKeyDeriveHKDFExpandHMACSHA384UsedOfObjectInfo(Index)                      (((boolean)(Crypto_30_LibCv_GetKeyDeriveHKDFExpandHMACSHA384IdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFEXPANDHMACSHA384IDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384 */
#define Crypto_30_LibCv_IsKeyDeriveHKDFHMACSHA256UsedOfObjectInfo(Index)                            (((boolean)(Crypto_30_LibCv_GetKeyDeriveHKDFHMACSHA256IdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHMACSHA256IDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256 */
#define Crypto_30_LibCv_IsKeyDeriveHKDFHMACSHA384UsedOfObjectInfo(Index)                            (((boolean)(Crypto_30_LibCv_GetKeyDeriveHKDFHMACSHA384IdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHMACSHA384IDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384 */
#define Crypto_30_LibCv_IsKeyDeriveISO15118UsedOfObjectInfo(Index)                                  (((boolean)(Crypto_30_LibCv_GetKeyDeriveISO15118IdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_KEYDERIVEISO15118IDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_KeyDeriveISO15118 */
#define Crypto_30_LibCv_IsKeyDeriveISO15118_20UsedOfObjectInfo(Index)                               (((boolean)(Crypto_30_LibCv_GetKeyDeriveISO15118_20IdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_KEYDERIVEISO15118_20IDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_KeyDeriveISO15118_20 */
#define Crypto_30_LibCv_IsKeyGenP256R1UsedOfObjectInfo(Index)                                       (((boolean)(Crypto_30_LibCv_GetKeyGenP256R1IdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_KEYGENP256R1IDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_KeyGenP256R1 */
#define Crypto_30_LibCv_IsKeyP256R1SecretUsedOfObjectInfo(Index)                                    (((boolean)(Crypto_30_LibCv_GetKeyP256R1SecretIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_KEYP256R1SECRETIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_KeyP256R1Secret */
#define Crypto_30_LibCv_IsRandomSeedBufferUsedOfObjectInfo(Index)                                   (((boolean)(Crypto_30_LibCv_GetRandomSeedBufferStartIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Crypto_30_LibCv_RandomSeedBuffer */
#define Crypto_30_LibCv_IsObjectInfoIndUsedOfPrimitiveFct(Index)                                    (((boolean)(Crypto_30_LibCv_GetObjectInfoIndStartIdxOfPrimitiveFct(Index) != CRYPTO_30_LIBCV_NO_OBJECTINFOINDSTARTIDXOFPRIMITIVEFCT)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Crypto_30_LibCv_ObjectInfoInd */
#define Crypto_30_LibCv_IsPrimitiveInfoUsedOfPrimitiveServiceInfo(Index)                            (((boolean)(Crypto_30_LibCv_GetPrimitiveInfoStartIdxOfPrimitiveServiceInfo(Index) != CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Crypto_30_LibCv_PrimitiveInfo */
#define Crypto_30_LibCv_GetSizeOfAEADChaChaPoly1305Decrypt()                                        Crypto_30_LibCv_GetSizeOfAEADChaChaPoly1305DecryptOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfAEADChaChaPoly1305Encrypt()                                        Crypto_30_LibCv_GetSizeOfAEADChaChaPoly1305EncryptOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfAesDecrypt()                                                       Crypto_30_LibCv_GetSizeOfAesDecryptOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfAesEncrypt()                                                       Crypto_30_LibCv_GetSizeOfAesEncryptOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfAesGcmDecrypt()                                                    Crypto_30_LibCv_GetSizeOfAesGcmDecryptOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfAesGcmEncrypt()                                                    Crypto_30_LibCv_GetSizeOfAesGcmEncryptOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfBufferLength()                                                     Crypto_30_LibCv_GetSizeOfBufferLengthOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfCmacAesGenerate()                                                  Crypto_30_LibCv_GetSizeOfCmacAesGenerateOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfCmacAesVerify()                                                    Crypto_30_LibCv_GetSizeOfCmacAesVerifyOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfDRBGAES()                                                          Crypto_30_LibCv_GetSizeOfDRBGAESOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfDispatch_QueuePrimitiveInfoIdx()                                   Crypto_30_LibCv_GetSizeOfDispatch_QueuePrimitiveInfoIdxOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfDriverObjectState()                                                Crypto_30_LibCv_GetSizeOfDriverObjectStateOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfEcP256Generate()                                                   Crypto_30_LibCv_GetSizeOfEcP256GenerateOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfEcP256Verify()                                                     Crypto_30_LibCv_GetSizeOfEcP256VerifyOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfEcP521Generate()                                                   Crypto_30_LibCv_GetSizeOfEcP521GenerateOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfEcP521Verify()                                                     Crypto_30_LibCv_GetSizeOfEcP521VerifyOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfEd25519Generate()                                                  Crypto_30_LibCv_GetSizeOfEd25519GenerateOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfEd25519Verify()                                                    Crypto_30_LibCv_GetSizeOfEd25519VerifyOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfFamilyToHashMapping()                                              Crypto_30_LibCv_GetSizeOfFamilyToHashMappingOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfFips186()                                                          Crypto_30_LibCv_GetSizeOfFips186OfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfGmacAesGenerate()                                                  Crypto_30_LibCv_GetSizeOfGmacAesGenerateOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfGmacAesVerify()                                                    Crypto_30_LibCv_GetSizeOfGmacAesVerifyOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfHash()                                                             Crypto_30_LibCv_GetSizeOfHashOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfHmacSha1Generate()                                                 Crypto_30_LibCv_GetSizeOfHmacSha1GenerateOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfHmacSha1Verify()                                                   Crypto_30_LibCv_GetSizeOfHmacSha1VerifyOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfHmacSha256Generate()                                               Crypto_30_LibCv_GetSizeOfHmacSha256GenerateOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfHmacSha256Verify()                                                 Crypto_30_LibCv_GetSizeOfHmacSha256VerifyOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfHmacSha384Generate()                                               Crypto_30_LibCv_GetSizeOfHmacSha384GenerateOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfHmacSha384Verify()                                                 Crypto_30_LibCv_GetSizeOfHmacSha384VerifyOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfInitValue()                                                        Crypto_30_LibCv_GetSizeOfInitValueOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfKey()                                                              Crypto_30_LibCv_GetSizeOfKeyOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfKeyDeriveHKDFExpandHMACSHA256()                                    Crypto_30_LibCv_GetSizeOfKeyDeriveHKDFExpandHMACSHA256OfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfKeyDeriveHKDFExpandHMACSHA384()                                    Crypto_30_LibCv_GetSizeOfKeyDeriveHKDFExpandHMACSHA384OfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfKeyDeriveHKDFHMACSHA256()                                          Crypto_30_LibCv_GetSizeOfKeyDeriveHKDFHMACSHA256OfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfKeyDeriveHKDFHMACSHA384()                                          Crypto_30_LibCv_GetSizeOfKeyDeriveHKDFHMACSHA384OfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfKeyDeriveISO15118()                                                Crypto_30_LibCv_GetSizeOfKeyDeriveISO15118OfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfKeyDeriveISO15118_20()                                             Crypto_30_LibCv_GetSizeOfKeyDeriveISO15118_20OfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfKeyElementInfo()                                                   Crypto_30_LibCv_GetSizeOfKeyElementInfoOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfKeyElements()                                                      Crypto_30_LibCv_GetSizeOfKeyElementsOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfKeyGenP256R1()                                                     Crypto_30_LibCv_GetSizeOfKeyGenP256R1OfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfKeyLock()                                                          Crypto_30_LibCv_GetSizeOfKeyLockOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfKeyNvStatus()                                                      Crypto_30_LibCv_GetSizeOfKeyNvStatusOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfKeyP256R1Secret()                                                  Crypto_30_LibCv_GetSizeOfKeyP256R1SecretOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfKeyStorage()                                                       Crypto_30_LibCv_GetSizeOfKeyStorageOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfLock()                                                             Crypto_30_LibCv_GetSizeOfLockOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfNvBlock()                                                          Crypto_30_LibCv_GetSizeOfNvBlockOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfObjectInfo()                                                       Crypto_30_LibCv_GetSizeOfObjectInfoOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfObjectInfoInd()                                                    Crypto_30_LibCv_GetSizeOfObjectInfoIndOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfPartitionIdentifiers()                                             Crypto_30_LibCv_GetSizeOfPartitionIdentifiersOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfPartitionInfo()                                                    Crypto_30_LibCv_GetSizeOfPartitionInfoOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfPrimitiveFct()                                                     Crypto_30_LibCv_GetSizeOfPrimitiveFctOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfPrimitiveInfo()                                                    Crypto_30_LibCv_GetSizeOfPrimitiveInfoOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfPrimitiveServiceInfo()                                             Crypto_30_LibCv_GetSizeOfPrimitiveServiceInfoOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfProcessJob_Trigger_Write()                                         Crypto_30_LibCv_GetSizeOfProcessJob_Trigger_WriteOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfQueue()                                                            Crypto_30_LibCv_GetSizeOfQueueOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfRandomSeedBuffer()                                                 Crypto_30_LibCv_GetSizeOfRandomSeedBufferOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfRedirect_Buffer()                                                  Crypto_30_LibCv_GetSizeOfRedirect_BufferOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn0()                       Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn0OfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished() Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_FinishedOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1()                       Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1OfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished() Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_FinishedOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384()         Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384OfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384()           Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384OfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1()             Crypto_30_LibCv_GetSizeOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1OfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfStructUnionWS_Crypto_30_LibCv()                                    Crypto_30_LibCv_GetSizeOfStructUnionWS_Crypto_30_LibCvOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfStructUnionWS_Crypto_30_LibCv_General()                            Crypto_30_LibCv_GetSizeOfStructUnionWS_Crypto_30_LibCv_GeneralOfPCPartitionConfig()
#define Crypto_30_LibCv_GetSizeOfWrittenLength()                                                    Crypto_30_LibCv_GetSizeOfWrittenLengthOfPCPartitionConfig()
#define Crypto_30_LibCv_IsStrictLengthCheckForKeyElementGetOfGeneral(partitionIndex)                Crypto_30_LibCv_IsStrictLengthCheckForKeyElementGetOfGeneralOfPCPartitionConfig(partitionIndex)
#define Crypto_30_LibCv_IsUseVStdLibOfGeneral(partitionIndex)                                       Crypto_30_LibCv_IsUseVStdLibOfGeneralOfPCPartitionConfig(partitionIndex)
#define Crypto_30_LibCv_IsVersionInfoApiOfGeneral(partitionIndex)                                   Crypto_30_LibCv_IsVersionInfoApiOfGeneralOfPCPartitionConfig(partitionIndex)
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCSetDataMacros  Crypto_30_LibCv Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Crypto_30_LibCv_SetBufferLength(Index, Value)                                               Crypto_30_LibCv_GetBufferLengthOfPCPartitionConfig()[(Index)] = (Value)
#define Crypto_30_LibCv_SetDispatch_QueuePrimitiveInfoIdx(Index, Value)                             Crypto_30_LibCv_GetDispatch_QueuePrimitiveInfoIdxOfPCPartitionConfig()[(Index)] = (Value)
#define Crypto_30_LibCv_SetDriverObjectState(Index, Value)                                          Crypto_30_LibCv_GetDriverObjectStateOfPCPartitionConfig()[(Index)] = (Value)
#define Crypto_30_LibCv_SetKeyLock(Index, Value)                                                    Crypto_30_LibCv_GetKeyLockOfPCPartitionConfig()[(Index)] = (Value)
#define Crypto_30_LibCv_SetKeyNvStatus(Index, Value)                                                Crypto_30_LibCv_GetKeyNvStatusOfPCPartitionConfig()[(Index)] = (Value)
#define Crypto_30_LibCv_SetKeyStorage(Index, Value)                                                 Crypto_30_LibCv_GetKeyStorageOfPCPartitionConfig()[(Index)] = (Value)
#define Crypto_30_LibCv_SetFamilyOfLastJob(Index, Value)                                              /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Family' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_SetKeyIdOfLastJob(Index, Value)                                               /**< Deactivateable: 'Crypto_30_LibCv_LastJob.KeyId' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_SetModeOfLastJob(Index, Value)                                                /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Mode' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_SetLock(Index, Value)                                                       Crypto_30_LibCv_GetLockOfPCPartitionConfig()[(Index)] = (Value)
#define Crypto_30_LibCv_SetLongTermWs(Index, Value)                                                   /**< Deactivateable: 'Crypto_30_LibCv_LongTermWs' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_SetLongTermWsLock(Index, Value)                                               /**< Deactivateable: 'Crypto_30_LibCv_LongTermWsLock' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_SetPartitionInitialized(Value, partitionIndex)                              (*(Crypto_30_LibCv_GetPartitionInitializedOfPCPartitionConfig(partitionIndex))) = (Value)
#define Crypto_30_LibCv_SetProcessJob_Trigger_Write(Index, Value)                                   Crypto_30_LibCv_GetProcessJob_Trigger_WriteOfPCPartitionConfig()[(Index)] = (Value)
#define Crypto_30_LibCv_SetQueue(Index, Value)                                                      Crypto_30_LibCv_GetQueueOfPCPartitionConfig()[(Index)] = (Value)
#define Crypto_30_LibCv_SetRandomSeedBuffer(Index, Value)                                           Crypto_30_LibCv_GetRandomSeedBufferOfPCPartitionConfig()[(Index)] = (Value)
#define Crypto_30_LibCv_SetRandomSourceGenerateCount(Value, partitionIndex)                         (*(Crypto_30_LibCv_GetRandomSourceGenerateCountOfPCPartitionConfig(partitionIndex))) = (Value)
#define Crypto_30_LibCv_SetRedirect_Buffer(Index, Value)                                            Crypto_30_LibCv_GetRedirect_BufferOfPCPartitionConfig()[(Index)] = (Value)
#define Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(Index, Value)                              /**< Deactivateable: 'Crypto_30_LibCv_SaveAndRestoreWorkspace.Length' Reason: 'Disable Feature if no Context primitive is used' */
#define Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0(Index, Value)           Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Conn0OfPCPartitionConfig()[(Index)].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0 = (Value)
#define Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished(Index, Value) Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_FinishedOfPCPartitionConfig()[(Index)].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished = (Value)
#define Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1(Index, Value)           Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Conn1OfPCPartitionConfig()[(Index)].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1 = (Value)
#define Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished(Index, Value) Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_FinishedOfPCPartitionConfig()[(Index)].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished = (Value)
#define Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384(Index, Value) Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384OfPCPartitionConfig()[(Index)].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384 = (Value)
#define Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384(Index, Value) Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384OfPCPartitionConfig()[(Index)].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384 = (Value)
#define Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1(Index, Value) Crypto_30_LibCv_GetStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1OfPCPartitionConfig()[(Index)].DataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1 = (Value)
#define Crypto_30_LibCv_SetDataOfStructUnionWS_Crypto_30_LibCv(Index, Value)                        Crypto_30_LibCv_GetStructUnionWS_Crypto_30_LibCvOfPCPartitionConfig()[(Index)].DataOfStructUnionWS_Crypto_30_LibCv = (Value)
#define Crypto_30_LibCv_SetDataOfStructUnionWS_Crypto_30_LibCv_General(Index, Value)                Crypto_30_LibCv_GetStructUnionWS_Crypto_30_LibCv_GeneralOfPCPartitionConfig()[(Index)].DataOfStructUnionWS_Crypto_30_LibCv_General = (Value)
#define Crypto_30_LibCv_SetWrittenLength(Index, Value)                                              Crypto_30_LibCv_GetWrittenLengthOfPCPartitionConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCGetAddressOfDataMacros  Crypto_30_LibCv Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define Crypto_30_LibCv_GetAddrInitValue(Index)                                                     (&Crypto_30_LibCv_GetInitValue(Index))
#define Crypto_30_LibCv_GetAddrKeyStorage(Index)                                                    (&Crypto_30_LibCv_GetKeyStorage(Index))
#define Crypto_30_LibCv_GetAddrDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0(Index)              (&Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0(Index))
#define Crypto_30_LibCv_GetAddrDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished(Index) (&Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished(Index))
#define Crypto_30_LibCv_GetAddrDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1(Index)              (&Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1(Index))
#define Crypto_30_LibCv_GetAddrDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished(Index) (&Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished(Index))
#define Crypto_30_LibCv_GetAddrDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384(Index) (&Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384(Index))
#define Crypto_30_LibCv_GetAddrDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384(Index)  (&Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384(Index))
#define Crypto_30_LibCv_GetAddrDataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1(Index)    (&Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1(Index))
#define Crypto_30_LibCv_GetAddrDataOfStructUnionWS_Crypto_30_LibCv(Index)                           (&Crypto_30_LibCv_GetDataOfStructUnionWS_Crypto_30_LibCv(Index))
#define Crypto_30_LibCv_GetAddrDataOfStructUnionWS_Crypto_30_LibCv_General(Index)                   (&Crypto_30_LibCv_GetDataOfStructUnionWS_Crypto_30_LibCv_General(Index))
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCHasMacros  Crypto_30_LibCv Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Crypto_30_LibCv_HasAEADChaChaPoly1305Decrypt()                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfAEADChaChaPoly1305Decrypt()                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasAEADChaChaPoly1305Encrypt()                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfAEADChaChaPoly1305Encrypt()                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesCcmDecrypt()                                                            /**< Deactivateable: 'Crypto_30_LibCv_AesCcmDecrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfAesCcmDecrypt()                                                 /**< Deactivateable: 'Crypto_30_LibCv_AesCcmDecrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasAesCcmEncrypt()                                                            /**< Deactivateable: 'Crypto_30_LibCv_AesCcmEncrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfAesCcmEncrypt()                                                 /**< Deactivateable: 'Crypto_30_LibCv_AesCcmEncrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasAesDecrypt()                                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfAesDecrypt()                                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesEncrypt()                                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfAesEncrypt()                                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesGcmDecrypt()                                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfAesGcmDecrypt()                                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesGcmEncrypt()                                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfAesGcmEncrypt()                                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasBufferLength()                                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasCmacAesGenerate()                                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfCmacAesGenerate()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasCmacAesVerify()                                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfCmacAesVerify()                                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasDRBGAES()                                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfDRBGAES()                                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasDRBGHashSha512()                                                           /**< Deactivateable: 'Crypto_30_LibCv_DRBGHashSha512' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfDRBGHashSha512()                                                /**< Deactivateable: 'Crypto_30_LibCv_DRBGHashSha512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasDispatch_QueuePrimitiveInfoIdx()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasDriverObjectState()                                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasEcP160Generate()                                                           /**< Deactivateable: 'Crypto_30_LibCv_EcP160Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfEcP160Generate()                                                /**< Deactivateable: 'Crypto_30_LibCv_EcP160Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasEcP160Verify()                                                             /**< Deactivateable: 'Crypto_30_LibCv_EcP160Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfEcP160Verify()                                                  /**< Deactivateable: 'Crypto_30_LibCv_EcP160Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasEcP256Generate()                                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfEcP256Generate()                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasEcP256Verify()                                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfEcP256Verify()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasEcP384Generate()                                                           /**< Deactivateable: 'Crypto_30_LibCv_EcP384Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfEcP384Generate()                                                /**< Deactivateable: 'Crypto_30_LibCv_EcP384Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasEcP384Verify()                                                             /**< Deactivateable: 'Crypto_30_LibCv_EcP384Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfEcP384Verify()                                                  /**< Deactivateable: 'Crypto_30_LibCv_EcP384Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasEcP521Generate()                                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfEcP521Generate()                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasEcP521Verify()                                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfEcP521Verify()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasEcPKeyCheck()                                                              /**< Deactivateable: 'Crypto_30_LibCv_EcPKeyCheck' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfEcPKeyCheck()                                                   /**< Deactivateable: 'Crypto_30_LibCv_EcPKeyCheck.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasEd25519Generate()                                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfEd25519Generate()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasEd25519Verify()                                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfEd25519Verify()                                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasEd448Generate()                                                            /**< Deactivateable: 'Crypto_30_LibCv_Ed448Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfEd448Generate()                                                 /**< Deactivateable: 'Crypto_30_LibCv_Ed448Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasEd448Verify()                                                              /**< Deactivateable: 'Crypto_30_LibCv_Ed448Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfEd448Verify()                                                   /**< Deactivateable: 'Crypto_30_LibCv_Ed448Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasEdKeyCheck()                                                               /**< Deactivateable: 'Crypto_30_LibCv_EdKeyCheck' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfEdKeyCheck()                                                    /**< Deactivateable: 'Crypto_30_LibCv_EdKeyCheck.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasExpectedCompatibilityVersion(partitionIndex)                               /**< Deactivateable: 'Crypto_30_LibCv_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_LibCv_HasFamilyToHashMapping()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasFinalMagicNumber()                                                         /**< Deactivateable: 'Crypto_30_LibCv_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_LibCv_HasFips186()                                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfFips186()                                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasGeneratorCompatibilityVersion(partitionIndex)                              /**< Deactivateable: 'Crypto_30_LibCv_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_LibCv_HasGmacAesGenerate()                                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfGmacAesGenerate()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasGmacAesVerify()                                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfGmacAesVerify()                                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasHash()                                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfHash()                                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacRipeMd160Generate()                                                    /**< Deactivateable: 'Crypto_30_LibCv_HmacRipeMd160Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfHmacRipeMd160Generate()                                         /**< Deactivateable: 'Crypto_30_LibCv_HmacRipeMd160Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasHmacRipeMd160Verify()                                                      /**< Deactivateable: 'Crypto_30_LibCv_HmacRipeMd160Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfHmacRipeMd160Verify()                                           /**< Deactivateable: 'Crypto_30_LibCv_HmacRipeMd160Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasHmacSha1Generate()                                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfHmacSha1Generate()                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha1Verify()                                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfHmacSha1Verify()                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha256Generate()                                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfHmacSha256Generate()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha256Verify()                                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfHmacSha256Verify()                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha384Generate()                                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfHmacSha384Generate()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha384Verify()                                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfHmacSha384Verify()                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha512Generate()                                                       /**< Deactivateable: 'Crypto_30_LibCv_HmacSha512Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfHmacSha512Generate()                                            /**< Deactivateable: 'Crypto_30_LibCv_HmacSha512Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasHmacSha512Verify()                                                         /**< Deactivateable: 'Crypto_30_LibCv_HmacSha512Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfHmacSha512Verify()                                              /**< Deactivateable: 'Crypto_30_LibCv_HmacSha512Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasInitDataHashCode()                                                         /**< Deactivateable: 'Crypto_30_LibCv_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_LibCv_HasInitValue()                                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasKey()                                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyElementsEndIdxOfKey()                                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyElementsStartIdxOfKey()                                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasNvBlockIdxOfKey()                                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasNvBlockUsedOfKey()                                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveHKDFExpandHMACSHA256()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveHKDFExpandHMACSHA256()                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveHKDFExpandHMACSHA384()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveHKDFExpandHMACSHA384()                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveHKDFHMACSHA256()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveHKDFHMACSHA256()                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveHKDFHMACSHA384()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveHKDFHMACSHA384()                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveHKDFHashOption1SHA256()                                           /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveHKDFHashOption1SHA256' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveHKDFHashOption1SHA256()                                /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveHKDFHashOption1SHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyDeriveHKDFHashOption1SHA512()                                           /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveHKDFHashOption1SHA512' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveHKDFHashOption1SHA512()                                /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveHKDFHashOption1SHA512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyDeriveISO15118()                                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveISO15118()                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveISO15118_20()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveISO15118_20()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveKDF2HMACSHA1()                                                    /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveKDF2HMACSHA1' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveKDF2HMACSHA1()                                         /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveKDF2HMACSHA1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyDeriveKDF2HMACSHA256()                                                  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveKDF2HMACSHA256' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveKDF2HMACSHA256()                                       /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveKDF2HMACSHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyDeriveNist800108Cnt()                                                   /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNist800108Cnt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveNist800108Cnt()                                        /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNist800108Cnt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyDeriveNist80056AOnePass()                                               /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNist80056AOnePass' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveNist80056AOnePass()                                    /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNist80056AOnePass.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyDeriveNistFips186Erb()                                                  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNistFips186Erb' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveNistFips186Erb()                                       /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNistFips186Erb.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyDeriveSpake2P()                                                         /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveSpake2P' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveSpake2P()                                              /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveSpake2P.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyDeriveX963SHA256()                                                      /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveX963SHA256' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveX963SHA256()                                           /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveX963SHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyDeriveX963SHA512()                                                      /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveX963SHA512' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveX963SHA512()                                           /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveX963SHA512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyElementInfo()                                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasIdOfKeyElementInfo()                                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasInitValueEndIdxOfKeyElementInfo()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasInitValueStartIdxOfKeyElementInfo()                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasInitValueUsedOfKeyElementInfo()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasLengthOfKeyElementInfo()                                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasMaskedBitsOfKeyElementInfo()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasOnceOfKeyElementInfo()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasPartialOfKeyElementInfo()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasPersistOfKeyElementInfo()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasReadOfKeyElementInfo()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasWriteOfKeyElementInfo()                                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyElements()                                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasIdOfKeyElements()                                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyElementInfoIdxOfKeyElements()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyStorageEndIdxOfKeyElements()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyStorageExtensionIdxOfKeyElements()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyStorageStartIdxOfKeyElements()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyStorageValidIdxOfKeyElements()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyStorageWrittenLengthEndIdxOfKeyElements()                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyStorageWrittenLengthStartIdxOfKeyElements()                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyGenEd25519()                                                            /**< Deactivateable: 'Crypto_30_LibCv_KeyGenEd25519' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyGenEd25519()                                                 /**< Deactivateable: 'Crypto_30_LibCv_KeyGenEd25519.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyGenP256R1()                                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfKeyGenP256R1()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyGenP384R1()                                                             /**< Deactivateable: 'Crypto_30_LibCv_KeyGenP384R1' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyGenP384R1()                                                  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenP384R1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyGenP521R1()                                                             /**< Deactivateable: 'Crypto_30_LibCv_KeyGenP521R1' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyGenP521R1()                                                  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenP521R1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyGenSm2P256V1()                                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyGenSm2P256V1' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyGenSm2P256V1()                                               /**< Deactivateable: 'Crypto_30_LibCv_KeyGenSm2P256V1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyGenSymGeneric()                                                         /**< Deactivateable: 'Crypto_30_LibCv_KeyGenSymGeneric' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyGenSymGeneric()                                              /**< Deactivateable: 'Crypto_30_LibCv_KeyGenSymGeneric.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyLock()                                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyNvStatus()                                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyP224R1BDPubVal()                                                        /**< Deactivateable: 'Crypto_30_LibCv_KeyP224R1BDPubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyP224R1BDPubVal()                                             /**< Deactivateable: 'Crypto_30_LibCv_KeyP224R1BDPubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyP224R1BDSecret()                                                        /**< Deactivateable: 'Crypto_30_LibCv_KeyP224R1BDSecret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyP224R1BDSecret()                                             /**< Deactivateable: 'Crypto_30_LibCv_KeyP224R1BDSecret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyP256R1BDPubVal()                                                        /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1BDPubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyP256R1BDPubVal()                                             /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1BDPubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyP256R1BDSecret()                                                        /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1BDSecret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyP256R1BDSecret()                                             /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1BDSecret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyP256R1PubVal()                                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1PubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyP256R1PubVal()                                               /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyP256R1Secret()                                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfKeyP256R1Secret()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyP384R1PubVal()                                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP384R1PubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyP384R1PubVal()                                               /**< Deactivateable: 'Crypto_30_LibCv_KeyP384R1PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyP384R1Secret()                                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP384R1Secret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyP384R1Secret()                                               /**< Deactivateable: 'Crypto_30_LibCv_KeyP384R1Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyP521R1PubVal()                                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP521R1PubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyP521R1PubVal()                                               /**< Deactivateable: 'Crypto_30_LibCv_KeyP521R1PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyP521R1Secret()                                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP521R1Secret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyP521R1Secret()                                               /**< Deactivateable: 'Crypto_30_LibCv_KeyP521R1Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeySeedDRBGAES()                                                           /**< Deactivateable: 'Crypto_30_LibCv_KeySeedDRBGAES' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeySeedDRBGAES()                                                /**< Deactivateable: 'Crypto_30_LibCv_KeySeedDRBGAES.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeySeedDRBGHashSha512()                                                    /**< Deactivateable: 'Crypto_30_LibCv_KeySeedDRBGHashSha512' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeySeedDRBGHashSha512()                                         /**< Deactivateable: 'Crypto_30_LibCv_KeySeedDRBGHashSha512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeySeedFips186()                                                           /**< Deactivateable: 'Crypto_30_LibCv_KeySeedFips186' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeySeedFips186()                                                /**< Deactivateable: 'Crypto_30_LibCv_KeySeedFips186.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeySetInvalidJob()                                                         /**< Deactivateable: 'Crypto_30_LibCv_KeySetInvalidJob' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeySetInvalidJob()                                              /**< Deactivateable: 'Crypto_30_LibCv_KeySetInvalidJob.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeySetValidJob()                                                           /**< Deactivateable: 'Crypto_30_LibCv_KeySetValidJob' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeySetValidJob()                                                /**< Deactivateable: 'Crypto_30_LibCv_KeySetValidJob.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeySpake2PPubVal()                                                         /**< Deactivateable: 'Crypto_30_LibCv_KeySpake2PPubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeySpake2PPubVal()                                              /**< Deactivateable: 'Crypto_30_LibCv_KeySpake2PPubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeySpake2PSecret()                                                         /**< Deactivateable: 'Crypto_30_LibCv_KeySpake2PSecret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeySpake2PSecret()                                              /**< Deactivateable: 'Crypto_30_LibCv_KeySpake2PSecret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyStorage()                                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyX25519PubVal()                                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyX25519PubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyX25519PubVal()                                               /**< Deactivateable: 'Crypto_30_LibCv_KeyX25519PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyX25519Secret()                                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyX25519Secret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyX25519Secret()                                               /**< Deactivateable: 'Crypto_30_LibCv_KeyX25519Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyX448PubVal()                                                            /**< Deactivateable: 'Crypto_30_LibCv_KeyX448PubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyX448PubVal()                                                 /**< Deactivateable: 'Crypto_30_LibCv_KeyX448PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyX448Secret()                                                            /**< Deactivateable: 'Crypto_30_LibCv_KeyX448Secret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyX448Secret()                                                 /**< Deactivateable: 'Crypto_30_LibCv_KeyX448Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasLastJob()                                                                  /**< Deactivateable: 'Crypto_30_LibCv_LastJob' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_HasFamilyOfLastJob()                                                          /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Family' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_HasKeyIdOfLastJob()                                                           /**< Deactivateable: 'Crypto_30_LibCv_LastJob.KeyId' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_HasModeOfLastJob()                                                            /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Mode' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_HasLock()                                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasLongTermWs()                                                               /**< Deactivateable: 'Crypto_30_LibCv_LongTermWs' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasLongTermWsLock()                                                           /**< Deactivateable: 'Crypto_30_LibCv_LongTermWsLock' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasMD5()                                                                      /**< Deactivateable: 'Crypto_30_LibCv_MD5' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfMD5()                                                           /**< Deactivateable: 'Crypto_30_LibCv_MD5.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasMainFunctionPeriodOfGeneral(partitionIndex)                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasNvBlock()                                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasConsistencyLevelOfNvBlock()                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasCrcOfNvBlock()                                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasDescriptorOfNvBlock()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasIdOfNvBlock()                                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyStorageEndIdxOfNvBlock()                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyStorageStartIdxOfNvBlock()                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasLengthOfNvBlock()                                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasProcessingOfNvBlock()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasObjectInfo()                                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasAEADChaChaPoly1305DecryptIdxOfObjectInfo()                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasAEADChaChaPoly1305DecryptUsedOfObjectInfo()                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasAEADChaChaPoly1305EncryptIdxOfObjectInfo()                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasAEADChaChaPoly1305EncryptUsedOfObjectInfo()                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesCcmDecryptIdxOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmDecryptIdx' Reason: 'the optional indirection is deactivated because AesCcmDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasAesCcmDecryptUsedOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmDecryptUsed' Reason: 'the optional indirection is deactivated because AesCcmDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasAesCcmEncryptIdxOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmEncryptIdx' Reason: 'the optional indirection is deactivated because AesCcmEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasAesCcmEncryptUsedOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmEncryptUsed' Reason: 'the optional indirection is deactivated because AesCcmEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasAesDecryptIdxOfObjectInfo()                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesDecryptUsedOfObjectInfo()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesEncryptIdxOfObjectInfo()                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesEncryptUsedOfObjectInfo()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesGcmDecryptIdxOfObjectInfo()                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesGcmDecryptUsedOfObjectInfo()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesGcmEncryptIdxOfObjectInfo()                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesGcmEncryptUsedOfObjectInfo()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasApplicationIdOfObjectInfo()                                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.ApplicationId' Reason: 'Deactivated for use case Single Partition' */
#define Crypto_30_LibCv_HasCmacAesGenerateIdxOfObjectInfo()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasCmacAesGenerateUsedOfObjectInfo()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasCmacAesVerifyIdxOfObjectInfo()                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasCmacAesVerifyUsedOfObjectInfo()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasDRBGAESIdxOfObjectInfo()                                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasDRBGAESUsedOfObjectInfo()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasDRBGHashSha512IdxOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.DRBGHashSha512Idx' Reason: 'the optional indirection is deactivated because DRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasDRBGHashSha512UsedOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.DRBGHashSha512Used' Reason: 'the optional indirection is deactivated because DRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP160GenerateIdxOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160GenerateIdx' Reason: 'the optional indirection is deactivated because EcP160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP160GenerateUsedOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160GenerateUsed' Reason: 'the optional indirection is deactivated because EcP160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP160VerifyIdxOfObjectInfo()                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160VerifyIdx' Reason: 'the optional indirection is deactivated because EcP160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP160VerifyUsedOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160VerifyUsed' Reason: 'the optional indirection is deactivated because EcP160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP256GenerateIdxOfObjectInfo()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasEcP256GenerateUsedOfObjectInfo()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasEcP256VerifyIdxOfObjectInfo()                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasEcP256VerifyUsedOfObjectInfo()                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasEcP384GenerateIdxOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384GenerateIdx' Reason: 'the optional indirection is deactivated because EcP384GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP384GenerateUsedOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384GenerateUsed' Reason: 'the optional indirection is deactivated because EcP384GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP384VerifyIdxOfObjectInfo()                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384VerifyIdx' Reason: 'the optional indirection is deactivated because EcP384VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP384VerifyUsedOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384VerifyUsed' Reason: 'the optional indirection is deactivated because EcP384VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP521GenerateIdxOfObjectInfo()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasEcP521GenerateUsedOfObjectInfo()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasEcP521VerifyIdxOfObjectInfo()                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasEcP521VerifyUsedOfObjectInfo()                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasEcPKeyCheckIdxOfObjectInfo()                                               /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcPKeyCheckIdx' Reason: 'the optional indirection is deactivated because EcPKeyCheckUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcPKeyCheckUsedOfObjectInfo()                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcPKeyCheckUsed' Reason: 'the optional indirection is deactivated because EcPKeyCheckUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEd25519GenerateIdxOfObjectInfo()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasEd25519GenerateUsedOfObjectInfo()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasEd25519VerifyIdxOfObjectInfo()                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasEd25519VerifyUsedOfObjectInfo()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasEd448GenerateIdxOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Ed448GenerateIdx' Reason: 'the optional indirection is deactivated because Ed448GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEd448GenerateUsedOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Ed448GenerateUsed' Reason: 'the optional indirection is deactivated because Ed448GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEd448VerifyIdxOfObjectInfo()                                               /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Ed448VerifyIdx' Reason: 'the optional indirection is deactivated because Ed448VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEd448VerifyUsedOfObjectInfo()                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Ed448VerifyUsed' Reason: 'the optional indirection is deactivated because Ed448VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEdKeyCheckIdxOfObjectInfo()                                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EdKeyCheckIdx' Reason: 'the optional indirection is deactivated because EdKeyCheckUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEdKeyCheckUsedOfObjectInfo()                                               /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EdKeyCheckUsed' Reason: 'the optional indirection is deactivated because EdKeyCheckUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasFips186IdxOfObjectInfo()                                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasFips186UsedOfObjectInfo()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasGmacAesGenerateIdxOfObjectInfo()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasGmacAesGenerateUsedOfObjectInfo()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasGmacAesVerifyIdxOfObjectInfo()                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasGmacAesVerifyUsedOfObjectInfo()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasHashIdxOfObjectInfo()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasHashUsedOfObjectInfo()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacRipeMd160GenerateIdxOfObjectInfo()                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160GenerateIdx' Reason: 'the optional indirection is deactivated because HmacRipeMd160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacRipeMd160GenerateUsedOfObjectInfo()                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160GenerateUsed' Reason: 'the optional indirection is deactivated because HmacRipeMd160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacRipeMd160VerifyIdxOfObjectInfo()                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160VerifyIdx' Reason: 'the optional indirection is deactivated because HmacRipeMd160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacRipeMd160VerifyUsedOfObjectInfo()                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160VerifyUsed' Reason: 'the optional indirection is deactivated because HmacRipeMd160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacSha1GenerateIdxOfObjectInfo()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha1GenerateUsedOfObjectInfo()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha1VerifyIdxOfObjectInfo()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha1VerifyUsedOfObjectInfo()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha256GenerateIdxOfObjectInfo()                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha256GenerateUsedOfObjectInfo()                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha256VerifyIdxOfObjectInfo()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha256VerifyUsedOfObjectInfo()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha384GenerateIdxOfObjectInfo()                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha384GenerateUsedOfObjectInfo()                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha384VerifyIdxOfObjectInfo()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha384VerifyUsedOfObjectInfo()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha512GenerateIdxOfObjectInfo()                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha512GenerateIdx' Reason: 'the optional indirection is deactivated because HmacSha512GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacSha512GenerateUsedOfObjectInfo()                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha512GenerateUsed' Reason: 'the optional indirection is deactivated because HmacSha512GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacSha512VerifyIdxOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha512VerifyIdx' Reason: 'the optional indirection is deactivated because HmacSha512VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacSha512VerifyUsedOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha512VerifyUsed' Reason: 'the optional indirection is deactivated because HmacSha512VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveHKDFExpandHMACSHA256IdxOfObjectInfo()                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveHKDFExpandHMACSHA256UsedOfObjectInfo()                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveHKDFExpandHMACSHA384IdxOfObjectInfo()                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveHKDFExpandHMACSHA384UsedOfObjectInfo()                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveHKDFHMACSHA256IdxOfObjectInfo()                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveHKDFHMACSHA256UsedOfObjectInfo()                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveHKDFHMACSHA384IdxOfObjectInfo()                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveHKDFHMACSHA384UsedOfObjectInfo()                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveHKDFHashOption1SHA256IdxOfObjectInfo()                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHashOption1SHA256Idx' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHashOption1SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveHKDFHashOption1SHA256UsedOfObjectInfo()                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHashOption1SHA256Used' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHashOption1SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveHKDFHashOption1SHA512IdxOfObjectInfo()                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHashOption1SHA512Idx' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHashOption1SHA512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveHKDFHashOption1SHA512UsedOfObjectInfo()                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHashOption1SHA512Used' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHashOption1SHA512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveISO15118IdxOfObjectInfo()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveISO15118UsedOfObjectInfo()                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveISO15118_20IdxOfObjectInfo()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveISO15118_20UsedOfObjectInfo()                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveKDF2HMACSHA1IdxOfObjectInfo()                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA1Idx' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveKDF2HMACSHA1UsedOfObjectInfo()                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA1Used' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveKDF2HMACSHA256IdxOfObjectInfo()                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA256Idx' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveKDF2HMACSHA256UsedOfObjectInfo()                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA256Used' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveNist800108CntIdxOfObjectInfo()                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist800108CntIdx' Reason: 'the optional indirection is deactivated because KeyDeriveNist800108CntUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveNist800108CntUsedOfObjectInfo()                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist800108CntUsed' Reason: 'the optional indirection is deactivated because KeyDeriveNist800108CntUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveNist80056AOnePassIdxOfObjectInfo()                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist80056AOnePassIdx' Reason: 'the optional indirection is deactivated because KeyDeriveNist80056AOnePassUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveNist80056AOnePassUsedOfObjectInfo()                               /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist80056AOnePassUsed' Reason: 'the optional indirection is deactivated because KeyDeriveNist80056AOnePassUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveNistFips186ErbIdxOfObjectInfo()                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNistFips186ErbIdx' Reason: 'the optional indirection is deactivated because KeyDeriveNistFips186ErbUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveNistFips186ErbUsedOfObjectInfo()                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNistFips186ErbUsed' Reason: 'the optional indirection is deactivated because KeyDeriveNistFips186ErbUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveSpake2PIdxOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveSpake2PIdx' Reason: 'the optional indirection is deactivated because KeyDeriveSpake2PUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveSpake2PUsedOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveSpake2PUsed' Reason: 'the optional indirection is deactivated because KeyDeriveSpake2PUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveX963SHA256IdxOfObjectInfo()                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA256Idx' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveX963SHA256UsedOfObjectInfo()                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA256Used' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveX963SHA512IdxOfObjectInfo()                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA512Idx' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveX963SHA512UsedOfObjectInfo()                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA512Used' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyGenEd25519IdxOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenEd25519Idx' Reason: 'the optional indirection is deactivated because KeyGenEd25519UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyGenEd25519UsedOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenEd25519Used' Reason: 'the optional indirection is deactivated because KeyGenEd25519UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyGenP256R1IdxOfObjectInfo()                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyGenP256R1UsedOfObjectInfo()                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyGenP384R1IdxOfObjectInfo()                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP384R1Idx' Reason: 'the optional indirection is deactivated because KeyGenP384R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyGenP384R1UsedOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP384R1Used' Reason: 'the optional indirection is deactivated because KeyGenP384R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyGenP521R1IdxOfObjectInfo()                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP521R1Idx' Reason: 'the optional indirection is deactivated because KeyGenP521R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyGenP521R1UsedOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP521R1Used' Reason: 'the optional indirection is deactivated because KeyGenP521R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyGenSm2P256V1IdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenSm2P256V1Idx' Reason: 'the optional indirection is deactivated because KeyGenSm2P256V1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyGenSm2P256V1UsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenSm2P256V1Used' Reason: 'the optional indirection is deactivated because KeyGenSm2P256V1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyGenSymGenericIdxOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenSymGenericIdx' Reason: 'the optional indirection is deactivated because KeyGenSymGenericUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyGenSymGenericUsedOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenSymGenericUsed' Reason: 'the optional indirection is deactivated because KeyGenSymGenericUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP224R1BDPubValIdxOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDPubValIdx' Reason: 'the optional indirection is deactivated because KeyP224R1BDPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP224R1BDPubValUsedOfObjectInfo()                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDPubValUsed' Reason: 'the optional indirection is deactivated because KeyP224R1BDPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP224R1BDSecretIdxOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDSecretIdx' Reason: 'the optional indirection is deactivated because KeyP224R1BDSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP224R1BDSecretUsedOfObjectInfo()                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDSecretUsed' Reason: 'the optional indirection is deactivated because KeyP224R1BDSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP256R1BDPubValIdxOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1BDPubValIdx' Reason: 'the optional indirection is deactivated because KeyP256R1BDPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP256R1BDPubValUsedOfObjectInfo()                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1BDPubValUsed' Reason: 'the optional indirection is deactivated because KeyP256R1BDPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP256R1BDSecretIdxOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1BDSecretIdx' Reason: 'the optional indirection is deactivated because KeyP256R1BDSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP256R1BDSecretUsedOfObjectInfo()                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1BDSecretUsed' Reason: 'the optional indirection is deactivated because KeyP256R1BDSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP256R1PubValIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1PubValIdx' Reason: 'the optional indirection is deactivated because KeyP256R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP256R1PubValUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1PubValUsed' Reason: 'the optional indirection is deactivated because KeyP256R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP256R1SecretIdxOfObjectInfo()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyP256R1SecretUsedOfObjectInfo()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyP384R1PubValIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1PubValIdx' Reason: 'the optional indirection is deactivated because KeyP384R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP384R1PubValUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1PubValUsed' Reason: 'the optional indirection is deactivated because KeyP384R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP384R1SecretIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1SecretIdx' Reason: 'the optional indirection is deactivated because KeyP384R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP384R1SecretUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1SecretUsed' Reason: 'the optional indirection is deactivated because KeyP384R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP521R1PubValIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1PubValIdx' Reason: 'the optional indirection is deactivated because KeyP521R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP521R1PubValUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1PubValUsed' Reason: 'the optional indirection is deactivated because KeyP521R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP521R1SecretIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1SecretIdx' Reason: 'the optional indirection is deactivated because KeyP521R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP521R1SecretUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1SecretUsed' Reason: 'the optional indirection is deactivated because KeyP521R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySeedDRBGAESIdxOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGAESIdx' Reason: 'the optional indirection is deactivated because KeySeedDRBGAESUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySeedDRBGAESUsedOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGAESUsed' Reason: 'the optional indirection is deactivated because KeySeedDRBGAESUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySeedDRBGHashSha512IdxOfObjectInfo()                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGHashSha512Idx' Reason: 'the optional indirection is deactivated because KeySeedDRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySeedDRBGHashSha512UsedOfObjectInfo()                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGHashSha512Used' Reason: 'the optional indirection is deactivated because KeySeedDRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySeedFips186IdxOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedFips186Idx' Reason: 'the optional indirection is deactivated because KeySeedFips186UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySeedFips186UsedOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedFips186Used' Reason: 'the optional indirection is deactivated because KeySeedFips186UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySetInvalidJobIdxOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySetInvalidJobIdx' Reason: 'the optional indirection is deactivated because KeySetInvalidJobUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySetInvalidJobUsedOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySetInvalidJobUsed' Reason: 'the optional indirection is deactivated because KeySetInvalidJobUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySetValidJobIdxOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySetValidJobIdx' Reason: 'the optional indirection is deactivated because KeySetValidJobUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySetValidJobUsedOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySetValidJobUsed' Reason: 'the optional indirection is deactivated because KeySetValidJobUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySpake2PPubValIdxOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PPubValIdx' Reason: 'the optional indirection is deactivated because KeySpake2PPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySpake2PPubValUsedOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PPubValUsed' Reason: 'the optional indirection is deactivated because KeySpake2PPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySpake2PSecretIdxOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PSecretIdx' Reason: 'the optional indirection is deactivated because KeySpake2PSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySpake2PSecretUsedOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PSecretUsed' Reason: 'the optional indirection is deactivated because KeySpake2PSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyX25519PubValIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519PubValIdx' Reason: 'the optional indirection is deactivated because KeyX25519PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyX25519PubValUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519PubValUsed' Reason: 'the optional indirection is deactivated because KeyX25519PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyX25519SecretIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519SecretIdx' Reason: 'the optional indirection is deactivated because KeyX25519SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyX25519SecretUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519SecretUsed' Reason: 'the optional indirection is deactivated because KeyX25519SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyX448PubValIdxOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX448PubValIdx' Reason: 'the optional indirection is deactivated because KeyX448PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyX448PubValUsedOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX448PubValUsed' Reason: 'the optional indirection is deactivated because KeyX448PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyX448SecretIdxOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX448SecretIdx' Reason: 'the optional indirection is deactivated because KeyX448SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyX448SecretUsedOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX448SecretUsed' Reason: 'the optional indirection is deactivated because KeyX448SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasMD5IdxOfObjectInfo()                                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.MD5Idx' Reason: 'the optional indirection is deactivated because MD5UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasMD5UsedOfObjectInfo()                                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.MD5Used' Reason: 'the optional indirection is deactivated because MD5UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasPartitionIdxOfObjectInfo()                                                 /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.PartitionIdx' Reason: 'Deactivated for use case Single Partition' */
#define Crypto_30_LibCv_HasQueueIdxOfObjectInfo()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasRandomSeedBufferEndIdxOfObjectInfo()                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasRandomSeedBufferStartIdxOfObjectInfo()                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasRandomSeedBufferUsedOfObjectInfo()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasRsaOaepCrtSha1DecryptIdxOfObjectInfo()                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha1DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepCrtSha1DecryptUsedOfObjectInfo()                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha1DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepCrtSha256DecryptIdxOfObjectInfo()                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha256DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepCrtSha256DecryptUsedOfObjectInfo()                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha256DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepSha1DecryptIdxOfObjectInfo()                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepSha1DecryptUsedOfObjectInfo()                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepSha1EncryptIdxOfObjectInfo()                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1EncryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepSha1EncryptUsedOfObjectInfo()                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1EncryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepSha256DecryptIdxOfObjectInfo()                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepSha256DecryptUsedOfObjectInfo()                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepSha256EncryptIdxOfObjectInfo()                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256EncryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha256EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepSha256EncryptUsedOfObjectInfo()                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256EncryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha256EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPkcs1CrtGenerateIdxOfObjectInfo()                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1CrtGenerateIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1CrtGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPkcs1CrtGenerateUsedOfObjectInfo()                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1CrtGenerateUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1CrtGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPkcs1DecryptIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1DecryptIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPkcs1DecryptUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1DecryptUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPkcs1EncryptIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1EncryptIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPkcs1EncryptUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1EncryptUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPkcs1GenerateIdxOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1GenerateIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPkcs1GenerateUsedOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1GenerateUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPkcs1VerifyIdxOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1VerifyIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPkcs1VerifyUsedOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1VerifyUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPssGenerateIdxOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssGenerateIdx' Reason: 'the optional indirection is deactivated because RsaPssGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPssGenerateUsedOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssGenerateUsed' Reason: 'the optional indirection is deactivated because RsaPssGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPssVerifyIdxOfObjectInfo()                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssVerifyIdx' Reason: 'the optional indirection is deactivated because RsaPssVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPssVerifyUsedOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssVerifyUsed' Reason: 'the optional indirection is deactivated because RsaPssVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSheCmdGetIdIdxOfObjectInfo()                                               /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SheCmdGetIdIdx' Reason: 'the optional indirection is deactivated because SheCmdGetIdUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSheCmdGetIdUsedOfObjectInfo()                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SheCmdGetIdUsed' Reason: 'the optional indirection is deactivated because SheCmdGetIdUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSipHashGenerateIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashGenerateIdx' Reason: 'the optional indirection is deactivated because SipHashGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSipHashGenerateUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashGenerateUsed' Reason: 'the optional indirection is deactivated because SipHashGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSipHashVerifyIdxOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashVerifyIdx' Reason: 'the optional indirection is deactivated because SipHashVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSipHashVerifyUsedOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashVerifyUsed' Reason: 'the optional indirection is deactivated because SipHashVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSlhDsaVerifyIdxOfObjectInfo()                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SlhDsaVerifyIdx' Reason: 'the optional indirection is deactivated because SlhDsaVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSlhDsaVerifyUsedOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SlhDsaVerifyUsed' Reason: 'the optional indirection is deactivated because SlhDsaVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSm2GenerateIdxOfObjectInfo()                                               /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm2GenerateIdx' Reason: 'the optional indirection is deactivated because Sm2GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSm2GenerateUsedOfObjectInfo()                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm2GenerateUsed' Reason: 'the optional indirection is deactivated because Sm2GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSm2VerifyIdxOfObjectInfo()                                                 /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm2VerifyIdx' Reason: 'the optional indirection is deactivated because Sm2VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSm2VerifyUsedOfObjectInfo()                                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm2VerifyUsed' Reason: 'the optional indirection is deactivated because Sm2VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSm4DecryptIdxOfObjectInfo()                                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm4DecryptIdx' Reason: 'the optional indirection is deactivated because Sm4DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSm4DecryptUsedOfObjectInfo()                                               /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm4DecryptUsed' Reason: 'the optional indirection is deactivated because Sm4DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSm4EncryptIdxOfObjectInfo()                                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm4EncryptIdx' Reason: 'the optional indirection is deactivated because Sm4EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSm4EncryptUsedOfObjectInfo()                                               /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Sm4EncryptUsed' Reason: 'the optional indirection is deactivated because Sm4EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasWorkspaceAddrOfObjectInfo()                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceLengthOfObjectInfo()                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasObjectInfoInd()                                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasPartitionIdentifiers()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasPCPartitionConfigIdxOfPartitionIdentifiers()                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasPartitionSNVOfPartitionIdentifiers()                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasPartitionInfo()                                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesOfPartitionInfo()                                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasDefaultRandomKeyOfPartitionInfo()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasHashOfPartitionInfo()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasMaskedBitsOfPartitionInfo()                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasPartitionInitialized(partitionIndex)                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasPrimitiveFct()                                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasDispatchOfPrimitiveFct()                                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasObjectInfoIndEndIdxOfPrimitiveFct()                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasObjectInfoIndStartIdxOfPrimitiveFct()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasObjectInfoIndUsedOfPrimitiveFct()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasPrimitiveInfo()                                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasCombinedOfPrimitiveInfo()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasContextOfPrimitiveInfo()                                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasDefaultRandomSourceOfPrimitiveInfo()                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasMaskedBitsOfPrimitiveInfo()                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasPrimitiveFctIdxOfPrimitiveInfo()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasPrimitiveServiceInfo()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasPrimitiveInfoEndIdxOfPrimitiveServiceInfo()                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasPrimitiveInfoStartIdxOfPrimitiveServiceInfo()                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasPrimitiveInfoUsedOfPrimitiveServiceInfo()                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasProcessJob_Trigger_Write()                                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasQueue()                                                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasRandomSeedBuffer()                                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasRandomSourceGenerateCount(partitionIndex)                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasRedirect_Buffer()                                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasRsaOaepCrtSha1Decrypt()                                                    /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepCrtSha1Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaOaepCrtSha1Decrypt()                                         /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepCrtSha1Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaOaepCrtSha256Decrypt()                                                  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepCrtSha256Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaOaepCrtSha256Decrypt()                                       /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepCrtSha256Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaOaepSha1Decrypt()                                                       /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha1Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaOaepSha1Decrypt()                                            /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha1Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaOaepSha1Encrypt()                                                       /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha1Encrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaOaepSha1Encrypt()                                            /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha1Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaOaepSha256Decrypt()                                                     /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha256Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaOaepSha256Decrypt()                                          /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha256Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaOaepSha256Encrypt()                                                     /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha256Encrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaOaepSha256Encrypt()                                          /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha256Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaPkcs1CrtGenerate()                                                      /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1CrtGenerate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaPkcs1CrtGenerate()                                           /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1CrtGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaPkcs1Decrypt()                                                          /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaPkcs1Decrypt()                                               /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaPkcs1Encrypt()                                                          /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Encrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaPkcs1Encrypt()                                               /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaPkcs1Generate()                                                         /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaPkcs1Generate()                                              /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaPkcs1Verify()                                                           /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaPkcs1Verify()                                                /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaPssGenerate()                                                           /**< Deactivateable: 'Crypto_30_LibCv_RsaPssGenerate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaPssGenerate()                                                /**< Deactivateable: 'Crypto_30_LibCv_RsaPssGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaPssVerify()                                                             /**< Deactivateable: 'Crypto_30_LibCv_RsaPssVerify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaPssVerify()                                                  /**< Deactivateable: 'Crypto_30_LibCv_RsaPssVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasSaveAndRestoreWorkspace()                                                  /**< Deactivateable: 'Crypto_30_LibCv_SaveAndRestoreWorkspace' Reason: 'Disable Feature if no Context primitive is used' */
#define Crypto_30_LibCv_HasLengthOfSaveAndRestoreWorkspace()                                          /**< Deactivateable: 'Crypto_30_LibCv_SaveAndRestoreWorkspace.Length' Reason: 'Disable Feature if no Context primitive is used' */
#define Crypto_30_LibCv_HasSheCmdGetId()                                                              /**< Deactivateable: 'Crypto_30_LibCv_SheCmdGetId' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfSheCmdGetId()                                                   /**< Deactivateable: 'Crypto_30_LibCv_SheCmdGetId.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasSheKeys()                                                                  /**< Deactivateable: 'Crypto_30_LibCv_SheKeys' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasSipHashGenerate()                                                          /**< Deactivateable: 'Crypto_30_LibCv_SipHashGenerate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfSipHashGenerate()                                               /**< Deactivateable: 'Crypto_30_LibCv_SipHashGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasSipHashVerify()                                                            /**< Deactivateable: 'Crypto_30_LibCv_SipHashVerify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfSipHashVerify()                                                 /**< Deactivateable: 'Crypto_30_LibCv_SipHashVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasSizeOfAEADChaChaPoly1305Decrypt()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfAEADChaChaPoly1305Encrypt()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfAesDecrypt()                                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfAesEncrypt()                                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfAesGcmDecrypt()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfAesGcmEncrypt()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfBufferLength()                                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfCmacAesGenerate()                                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfCmacAesVerify()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfDRBGAES()                                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfDispatch_QueuePrimitiveInfoIdx()                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfDriverObjectState()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfEcP256Generate()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfEcP256Verify()                                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfEcP521Generate()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfEcP521Verify()                                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfEd25519Generate()                                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfEd25519Verify()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfFamilyToHashMapping()                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfFips186()                                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfGmacAesGenerate()                                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfGmacAesVerify()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfHash()                                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfHmacSha1Generate()                                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfHmacSha1Verify()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfHmacSha256Generate()                                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfHmacSha256Verify()                                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfHmacSha384Generate()                                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfHmacSha384Verify()                                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfInitValue()                                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKey()                                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyDeriveHKDFExpandHMACSHA256()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyDeriveHKDFExpandHMACSHA384()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyDeriveHKDFHMACSHA256()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyDeriveHKDFHMACSHA384()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyDeriveISO15118()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyDeriveISO15118_20()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyElementInfo()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyElements()                                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyGenP256R1()                                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyLock()                                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyNvStatus()                                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyP256R1Secret()                                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyStorage()                                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfLock()                                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfNvBlock()                                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfObjectInfo()                                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfObjectInfoInd()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfPartitionIdentifiers()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfPartitionInfo()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfPrimitiveFct()                                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfPrimitiveInfo()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfPrimitiveServiceInfo()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfProcessJob_Trigger_Write()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfQueue()                                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfRandomSeedBuffer()                                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfRedirect_Buffer()                                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn0()                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished() (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1()                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished() (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384()         (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384()           (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1()             (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfStructUnionWS_Crypto_30_LibCv()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfStructUnionWS_Crypto_30_LibCv_General()                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfWrittenLength()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSlhDsaVerify()                                                             /**< Deactivateable: 'Crypto_30_LibCv_SlhDsaVerify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfSlhDsaVerify()                                                  /**< Deactivateable: 'Crypto_30_LibCv_SlhDsaVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasSm2Generate()                                                              /**< Deactivateable: 'Crypto_30_LibCv_Sm2Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfSm2Generate()                                                   /**< Deactivateable: 'Crypto_30_LibCv_Sm2Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasSm2Verify()                                                                /**< Deactivateable: 'Crypto_30_LibCv_Sm2Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfSm2Verify()                                                     /**< Deactivateable: 'Crypto_30_LibCv_Sm2Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasSm4Decrypt()                                                               /**< Deactivateable: 'Crypto_30_LibCv_Sm4Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfSm4Decrypt()                                                    /**< Deactivateable: 'Crypto_30_LibCv_Sm4Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasSm4Encrypt()                                                               /**< Deactivateable: 'Crypto_30_LibCv_Sm4Encrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfSm4Encrypt()                                                    /**< Deactivateable: 'Crypto_30_LibCv_Sm4Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasStrictLengthCheckForKeyElementGetOfGeneral(partitionIndex)               (TRUE != FALSE)
#define Crypto_30_LibCv_HasStructUnionWS_CryptoDriverObject_Tls_Conn0()                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0()                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished()      (TRUE != FALSE)
#define Crypto_30_LibCv_HasDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished() (TRUE != FALSE)
#define Crypto_30_LibCv_HasStructUnionWS_CryptoDriverObject_Tls_Conn1()                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1()                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished()      (TRUE != FALSE)
#define Crypto_30_LibCv_HasDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished() (TRUE != FALSE)
#define Crypto_30_LibCv_HasStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384()               (TRUE != FALSE)
#define Crypto_30_LibCv_HasDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384()         (TRUE != FALSE)
#define Crypto_30_LibCv_HasStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384()                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384()           (TRUE != FALSE)
#define Crypto_30_LibCv_HasStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1()                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasDataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1()             (TRUE != FALSE)
#define Crypto_30_LibCv_HasStructUnionWS_Crypto_30_LibCv()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasDataOfStructUnionWS_Crypto_30_LibCv()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasStructUnionWS_Crypto_30_LibCv_General()                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasDataOfStructUnionWS_Crypto_30_LibCv_General()                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasUseVStdLibOfGeneral(partitionIndex)                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasVersionInfoApiOfGeneral(partitionIndex)                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasWrittenLength()                                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasPCConfig()                                                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasFinalMagicNumberOfPCConfig()                                               /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_LibCv_HasInitDataHashCodeOfPCConfig()                                               /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_LibCv_HasPCPartitionConfigOfPCConfig()                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasPartitionIdentifiersOfPCConfig()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfPartitionIdentifiersOfPCConfig()                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasPCPartitionConfig()                                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasAEADChaChaPoly1305DecryptOfPCPartitionConfig()                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasAEADChaChaPoly1305EncryptOfPCPartitionConfig()                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesDecryptOfPCPartitionConfig()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesEncryptOfPCPartitionConfig()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesGcmDecryptOfPCPartitionConfig()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesGcmEncryptOfPCPartitionConfig()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasBufferLengthOfPCPartitionConfig()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasCmacAesGenerateOfPCPartitionConfig()                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasCmacAesVerifyOfPCPartitionConfig()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasDRBGAESOfPCPartitionConfig()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasDispatch_QueuePrimitiveInfoIdxOfPCPartitionConfig()                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasDriverObjectStateOfPCPartitionConfig()                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasEcP256GenerateOfPCPartitionConfig()                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasEcP256VerifyOfPCPartitionConfig()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasEcP521GenerateOfPCPartitionConfig()                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasEcP521VerifyOfPCPartitionConfig()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasEd25519GenerateOfPCPartitionConfig()                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasEd25519VerifyOfPCPartitionConfig()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasExpectedCompatibilityVersionOfPCPartitionConfig(partitionIndex)            /**< Deactivateable: 'Crypto_30_LibCv_PCPartitionConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_LibCv_HasFamilyToHashMappingOfPCPartitionConfig()                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasFips186OfPCPartitionConfig()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasGeneratorCompatibilityVersionOfPCPartitionConfig(partitionIndex)           /**< Deactivateable: 'Crypto_30_LibCv_PCPartitionConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_LibCv_HasGmacAesGenerateOfPCPartitionConfig()                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasGmacAesVerifyOfPCPartitionConfig()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasHashOfPCPartitionConfig()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha1GenerateOfPCPartitionConfig()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha1VerifyOfPCPartitionConfig()                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha256GenerateOfPCPartitionConfig()                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha256VerifyOfPCPartitionConfig()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha384GenerateOfPCPartitionConfig()                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacSha384VerifyOfPCPartitionConfig()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasInitValueOfPCPartitionConfig()                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveHKDFExpandHMACSHA256OfPCPartitionConfig()                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveHKDFExpandHMACSHA384OfPCPartitionConfig()                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveHKDFHMACSHA256OfPCPartitionConfig()                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveHKDFHMACSHA384OfPCPartitionConfig()                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveISO15118OfPCPartitionConfig()                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyDeriveISO15118_20OfPCPartitionConfig()                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyElementInfoOfPCPartitionConfig()                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyElementsOfPCPartitionConfig()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyGenP256R1OfPCPartitionConfig()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyLockOfPCPartitionConfig()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyNvStatusOfPCPartitionConfig()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyOfPCPartitionConfig()                                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyP256R1SecretOfPCPartitionConfig()                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyStorageOfPCPartitionConfig()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasLockOfPCPartitionConfig()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasMainFunctionPeriodOfGeneralOfPCPartitionConfig(partitionIndex)           (TRUE != FALSE)
#define Crypto_30_LibCv_HasNvBlockOfPCPartitionConfig()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasObjectInfoIndOfPCPartitionConfig()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasObjectInfoOfPCPartitionConfig()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasPartitionInfoOfPCPartitionConfig()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasPartitionInitializedOfPCPartitionConfig(partitionIndex)                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasPrimitiveFctOfPCPartitionConfig()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasPrimitiveInfoOfPCPartitionConfig()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasPrimitiveServiceInfoOfPCPartitionConfig()                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasProcessJob_Trigger_WriteOfPCPartitionConfig()                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasQueueOfPCPartitionConfig()                                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasRandomSeedBufferOfPCPartitionConfig()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasRandomSourceGenerateCountOfPCPartitionConfig(partitionIndex)             (TRUE != FALSE)
#define Crypto_30_LibCv_HasRedirect_BufferOfPCPartitionConfig()                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfAEADChaChaPoly1305DecryptOfPCPartitionConfig()                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfAEADChaChaPoly1305EncryptOfPCPartitionConfig()                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfAesDecryptOfPCPartitionConfig()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfAesEncryptOfPCPartitionConfig()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfAesGcmDecryptOfPCPartitionConfig()                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfAesGcmEncryptOfPCPartitionConfig()                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfBufferLengthOfPCPartitionConfig()                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfCmacAesGenerateOfPCPartitionConfig()                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfCmacAesVerifyOfPCPartitionConfig()                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfDRBGAESOfPCPartitionConfig()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfDispatch_QueuePrimitiveInfoIdxOfPCPartitionConfig()                (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfDriverObjectStateOfPCPartitionConfig()                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfEcP256GenerateOfPCPartitionConfig()                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfEcP256VerifyOfPCPartitionConfig()                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfEcP521GenerateOfPCPartitionConfig()                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfEcP521VerifyOfPCPartitionConfig()                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfEd25519GenerateOfPCPartitionConfig()                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfEd25519VerifyOfPCPartitionConfig()                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfFamilyToHashMappingOfPCPartitionConfig()                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfFips186OfPCPartitionConfig()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfGmacAesGenerateOfPCPartitionConfig()                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfGmacAesVerifyOfPCPartitionConfig()                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfHashOfPCPartitionConfig()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfHmacSha1GenerateOfPCPartitionConfig()                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfHmacSha1VerifyOfPCPartitionConfig()                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfHmacSha256GenerateOfPCPartitionConfig()                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfHmacSha256VerifyOfPCPartitionConfig()                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfHmacSha384GenerateOfPCPartitionConfig()                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfHmacSha384VerifyOfPCPartitionConfig()                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfInitValueOfPCPartitionConfig()                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyDeriveHKDFExpandHMACSHA256OfPCPartitionConfig()                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyDeriveHKDFExpandHMACSHA384OfPCPartitionConfig()                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyDeriveHKDFHMACSHA256OfPCPartitionConfig()                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyDeriveHKDFHMACSHA384OfPCPartitionConfig()                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyDeriveISO15118OfPCPartitionConfig()                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyDeriveISO15118_20OfPCPartitionConfig()                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyElementInfoOfPCPartitionConfig()                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyElementsOfPCPartitionConfig()                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyGenP256R1OfPCPartitionConfig()                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyLockOfPCPartitionConfig()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyNvStatusOfPCPartitionConfig()                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyOfPCPartitionConfig()                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyP256R1SecretOfPCPartitionConfig()                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyStorageOfPCPartitionConfig()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfLockOfPCPartitionConfig()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfNvBlockOfPCPartitionConfig()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfObjectInfoIndOfPCPartitionConfig()                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfObjectInfoOfPCPartitionConfig()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfPartitionInfoOfPCPartitionConfig()                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfPrimitiveFctOfPCPartitionConfig()                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfPrimitiveInfoOfPCPartitionConfig()                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfPrimitiveServiceInfoOfPCPartitionConfig()                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfProcessJob_Trigger_WriteOfPCPartitionConfig()                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfQueueOfPCPartitionConfig()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfRandomSeedBufferOfPCPartitionConfig()                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfRedirect_BufferOfPCPartitionConfig()                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn0OfPCPartitionConfig()    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_FinishedOfPCPartitionConfig() (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1OfPCPartitionConfig()    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_FinishedOfPCPartitionConfig() (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384OfPCPartitionConfig() (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384OfPCPartitionConfig() (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1OfPCPartitionConfig() (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfStructUnionWS_Crypto_30_LibCvOfPCPartitionConfig()                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfStructUnionWS_Crypto_30_LibCv_GeneralOfPCPartitionConfig()         (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfWrittenLengthOfPCPartitionConfig()                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasStrictLengthCheckForKeyElementGetOfGeneralOfPCPartitionConfig(partitionIndex) (TRUE != FALSE)
#define Crypto_30_LibCv_HasStructUnionWS_CryptoDriverObject_Tls_Conn0OfPCPartitionConfig()          (TRUE != FALSE)
#define Crypto_30_LibCv_HasStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_FinishedOfPCPartitionConfig() (TRUE != FALSE)
#define Crypto_30_LibCv_HasStructUnionWS_CryptoDriverObject_Tls_Conn1OfPCPartitionConfig()          (TRUE != FALSE)
#define Crypto_30_LibCv_HasStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_FinishedOfPCPartitionConfig() (TRUE != FALSE)
#define Crypto_30_LibCv_HasStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384OfPCPartitionConfig() (TRUE != FALSE)
#define Crypto_30_LibCv_HasStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384OfPCPartitionConfig() (TRUE != FALSE)
#define Crypto_30_LibCv_HasStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1OfPCPartitionConfig() (TRUE != FALSE)
#define Crypto_30_LibCv_HasStructUnionWS_Crypto_30_LibCvOfPCPartitionConfig()                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasStructUnionWS_Crypto_30_LibCv_GeneralOfPCPartitionConfig()               (TRUE != FALSE)
#define Crypto_30_LibCv_HasUseVStdLibOfGeneralOfPCPartitionConfig(partitionIndex)                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasVersionInfoApiOfGeneralOfPCPartitionConfig(partitionIndex)               (TRUE != FALSE)
#define Crypto_30_LibCv_HasWrittenLengthOfPCPartitionConfig()                                       (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCIncrementDataMacros  Crypto_30_LibCv Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Crypto_30_LibCv_IncBufferLength(Index)                                                      Crypto_30_LibCv_GetBufferLength(Index)++
#define Crypto_30_LibCv_IncDispatch_QueuePrimitiveInfoIdx(Index)                                    Crypto_30_LibCv_GetDispatch_QueuePrimitiveInfoIdx(Index)++
#define Crypto_30_LibCv_IncDriverObjectState(Index)                                                 Crypto_30_LibCv_GetDriverObjectState(Index)++
#define Crypto_30_LibCv_IncKeyLock(Index)                                                           Crypto_30_LibCv_GetKeyLock(Index)++
#define Crypto_30_LibCv_IncKeyNvStatus(Index)                                                       Crypto_30_LibCv_GetKeyNvStatus(Index)++
#define Crypto_30_LibCv_IncKeyStorage(Index)                                                        Crypto_30_LibCv_GetKeyStorage(Index)++
#define Crypto_30_LibCv_IncFamilyOfLastJob(Index)                                                     /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Family' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_IncKeyIdOfLastJob(Index)                                                      /**< Deactivateable: 'Crypto_30_LibCv_LastJob.KeyId' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_IncModeOfLastJob(Index)                                                       /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Mode' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_IncLock(Index)                                                              Crypto_30_LibCv_GetLock(Index)++
#define Crypto_30_LibCv_IncLongTermWs(Index)                                                          /**< Deactivateable: 'Crypto_30_LibCv_LongTermWs' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_IncLongTermWsLock(Index)                                                      /**< Deactivateable: 'Crypto_30_LibCv_LongTermWsLock' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_IncPartitionInitialized(partitionIndex)                                     Crypto_30_LibCv_GetPartitionInitialized(partitionIndex)++
#define Crypto_30_LibCv_IncQueue(Index)                                                             Crypto_30_LibCv_GetQueue(Index)++
#define Crypto_30_LibCv_IncRandomSeedBuffer(Index)                                                  Crypto_30_LibCv_GetRandomSeedBuffer(Index)++
#define Crypto_30_LibCv_IncRandomSourceGenerateCount(partitionIndex)                                Crypto_30_LibCv_GetRandomSourceGenerateCount(partitionIndex)++
#define Crypto_30_LibCv_IncRedirect_Buffer(Index)                                                   Crypto_30_LibCv_GetRedirect_Buffer(Index)++
#define Crypto_30_LibCv_IncLengthOfSaveAndRestoreWorkspace(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_SaveAndRestoreWorkspace.Length' Reason: 'Disable Feature if no Context primitive is used' */
#define Crypto_30_LibCv_IncDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0(Index)                  Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0(Index)++
#define Crypto_30_LibCv_IncDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished(Index) Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished(Index)++
#define Crypto_30_LibCv_IncDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1(Index)                  Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1(Index)++
#define Crypto_30_LibCv_IncDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished(Index) Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished(Index)++
#define Crypto_30_LibCv_IncDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384(Index)    Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384(Index)++
#define Crypto_30_LibCv_IncDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384(Index)      Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384(Index)++
#define Crypto_30_LibCv_IncDataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1(Index)        Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1(Index)++
#define Crypto_30_LibCv_IncDataOfStructUnionWS_Crypto_30_LibCv(Index)                               Crypto_30_LibCv_GetDataOfStructUnionWS_Crypto_30_LibCv(Index)++
#define Crypto_30_LibCv_IncDataOfStructUnionWS_Crypto_30_LibCv_General(Index)                       Crypto_30_LibCv_GetDataOfStructUnionWS_Crypto_30_LibCv_General(Index)++
#define Crypto_30_LibCv_IncWrittenLength(Index)                                                     Crypto_30_LibCv_GetWrittenLength(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCDecrementDataMacros  Crypto_30_LibCv Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Crypto_30_LibCv_DecBufferLength(Index)                                                      Crypto_30_LibCv_GetBufferLength(Index)--
#define Crypto_30_LibCv_DecDispatch_QueuePrimitiveInfoIdx(Index)                                    Crypto_30_LibCv_GetDispatch_QueuePrimitiveInfoIdx(Index)--
#define Crypto_30_LibCv_DecDriverObjectState(Index)                                                 Crypto_30_LibCv_GetDriverObjectState(Index)--
#define Crypto_30_LibCv_DecKeyLock(Index)                                                           Crypto_30_LibCv_GetKeyLock(Index)--
#define Crypto_30_LibCv_DecKeyNvStatus(Index)                                                       Crypto_30_LibCv_GetKeyNvStatus(Index)--
#define Crypto_30_LibCv_DecKeyStorage(Index)                                                        Crypto_30_LibCv_GetKeyStorage(Index)--
#define Crypto_30_LibCv_DecFamilyOfLastJob(Index)                                                     /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Family' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_DecKeyIdOfLastJob(Index)                                                      /**< Deactivateable: 'Crypto_30_LibCv_LastJob.KeyId' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_DecModeOfLastJob(Index)                                                       /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Mode' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_DecLock(Index)                                                              Crypto_30_LibCv_GetLock(Index)--
#define Crypto_30_LibCv_DecLongTermWs(Index)                                                          /**< Deactivateable: 'Crypto_30_LibCv_LongTermWs' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_DecLongTermWsLock(Index)                                                      /**< Deactivateable: 'Crypto_30_LibCv_LongTermWsLock' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_DecPartitionInitialized(partitionIndex)                                     Crypto_30_LibCv_GetPartitionInitialized(partitionIndex)--
#define Crypto_30_LibCv_DecQueue(Index)                                                             Crypto_30_LibCv_GetQueue(Index)--
#define Crypto_30_LibCv_DecRandomSeedBuffer(Index)                                                  Crypto_30_LibCv_GetRandomSeedBuffer(Index)--
#define Crypto_30_LibCv_DecRandomSourceGenerateCount(partitionIndex)                                Crypto_30_LibCv_GetRandomSourceGenerateCount(partitionIndex)--
#define Crypto_30_LibCv_DecRedirect_Buffer(Index)                                                   Crypto_30_LibCv_GetRedirect_Buffer(Index)--
#define Crypto_30_LibCv_DecLengthOfSaveAndRestoreWorkspace(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_SaveAndRestoreWorkspace.Length' Reason: 'Disable Feature if no Context primitive is used' */
#define Crypto_30_LibCv_DecDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0(Index)                  Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0(Index)--
#define Crypto_30_LibCv_DecDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished(Index) Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished(Index)--
#define Crypto_30_LibCv_DecDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1(Index)                  Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1(Index)--
#define Crypto_30_LibCv_DecDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished(Index) Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished(Index)--
#define Crypto_30_LibCv_DecDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384(Index)    Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384(Index)--
#define Crypto_30_LibCv_DecDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384(Index)      Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384(Index)--
#define Crypto_30_LibCv_DecDataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1(Index)        Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1(Index)--
#define Crypto_30_LibCv_DecDataOfStructUnionWS_Crypto_30_LibCv(Index)                               Crypto_30_LibCv_GetDataOfStructUnionWS_Crypto_30_LibCv(Index)--
#define Crypto_30_LibCv_DecDataOfStructUnionWS_Crypto_30_LibCv_General(Index)                       Crypto_30_LibCv_GetDataOfStructUnionWS_Crypto_30_LibCv_General(Index)--
#define Crypto_30_LibCv_DecWrittenLength(Index)                                                     Crypto_30_LibCv_GetWrittenLength(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCAddDataMacros  Crypto_30_LibCv Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define Crypto_30_LibCv_AddBufferLength(Index, Value)                                               Crypto_30_LibCv_SetBufferLength(Index, (Crypto_30_LibCv_GetBufferLength(Index) + Value))
#define Crypto_30_LibCv_AddDispatch_QueuePrimitiveInfoIdx(Index, Value)                             Crypto_30_LibCv_SetDispatch_QueuePrimitiveInfoIdx(Index, (Crypto_30_LibCv_GetDispatch_QueuePrimitiveInfoIdx(Index) + Value))
#define Crypto_30_LibCv_AddDriverObjectState(Index, Value)                                          Crypto_30_LibCv_SetDriverObjectState(Index, (Crypto_30_LibCv_GetDriverObjectState(Index) + Value))
#define Crypto_30_LibCv_AddKeyLock(Index, Value)                                                    Crypto_30_LibCv_SetKeyLock(Index, (Crypto_30_LibCv_GetKeyLock(Index) + Value))
#define Crypto_30_LibCv_AddKeyNvStatus(Index, Value)                                                Crypto_30_LibCv_SetKeyNvStatus(Index, (Crypto_30_LibCv_GetKeyNvStatus(Index) + Value))
#define Crypto_30_LibCv_AddKeyStorage(Index, Value)                                                 Crypto_30_LibCv_SetKeyStorage(Index, (Crypto_30_LibCv_GetKeyStorage(Index) + Value))
#define Crypto_30_LibCv_AddFamilyOfLastJob(Index, Value)                                              /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Family' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_AddKeyIdOfLastJob(Index, Value)                                               /**< Deactivateable: 'Crypto_30_LibCv_LastJob.KeyId' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_AddModeOfLastJob(Index, Value)                                                /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Mode' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_AddLock(Index, Value)                                                       Crypto_30_LibCv_SetLock(Index, (Crypto_30_LibCv_GetLock(Index) + Value))
#define Crypto_30_LibCv_AddLongTermWs(Index, Value)                                                   /**< Deactivateable: 'Crypto_30_LibCv_LongTermWs' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_AddLongTermWsLock(Index, Value)                                               /**< Deactivateable: 'Crypto_30_LibCv_LongTermWsLock' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_AddPartitionInitialized(Value, partitionIndex)                              Crypto_30_LibCv_SetPartitionInitialized((Crypto_30_LibCv_GetPartitionInitialized(partitionIndex) + Value), partitionIndex)
#define Crypto_30_LibCv_AddQueue(Index, Value)                                                      Crypto_30_LibCv_SetQueue(Index, (Crypto_30_LibCv_GetQueue(Index) + Value))
#define Crypto_30_LibCv_AddRandomSeedBuffer(Index, Value)                                           Crypto_30_LibCv_SetRandomSeedBuffer(Index, (Crypto_30_LibCv_GetRandomSeedBuffer(Index) + Value))
#define Crypto_30_LibCv_AddRandomSourceGenerateCount(Value, partitionIndex)                         Crypto_30_LibCv_SetRandomSourceGenerateCount((Crypto_30_LibCv_GetRandomSourceGenerateCount(partitionIndex) + Value), partitionIndex)
#define Crypto_30_LibCv_AddRedirect_Buffer(Index, Value)                                            Crypto_30_LibCv_SetRedirect_Buffer(Index, (Crypto_30_LibCv_GetRedirect_Buffer(Index) + Value))
#define Crypto_30_LibCv_AddLengthOfSaveAndRestoreWorkspace(Index, Value)                              /**< Deactivateable: 'Crypto_30_LibCv_SaveAndRestoreWorkspace.Length' Reason: 'Disable Feature if no Context primitive is used' */
#define Crypto_30_LibCv_AddDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0(Index, Value)           Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0(Index, (Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0(Index) + Value))
#define Crypto_30_LibCv_AddDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished(Index, Value) Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished(Index, (Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished(Index) + Value))
#define Crypto_30_LibCv_AddDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1(Index, Value)           Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1(Index, (Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1(Index) + Value))
#define Crypto_30_LibCv_AddDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished(Index, Value) Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished(Index, (Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished(Index) + Value))
#define Crypto_30_LibCv_AddDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384(Index, Value) Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384(Index, (Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384(Index) + Value))
#define Crypto_30_LibCv_AddDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384(Index, Value) Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384(Index, (Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384(Index) + Value))
#define Crypto_30_LibCv_AddDataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1(Index, Value) Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1(Index, (Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1(Index) + Value))
#define Crypto_30_LibCv_AddDataOfStructUnionWS_Crypto_30_LibCv(Index, Value)                        Crypto_30_LibCv_SetDataOfStructUnionWS_Crypto_30_LibCv(Index, (Crypto_30_LibCv_GetDataOfStructUnionWS_Crypto_30_LibCv(Index) + Value))
#define Crypto_30_LibCv_AddDataOfStructUnionWS_Crypto_30_LibCv_General(Index, Value)                Crypto_30_LibCv_SetDataOfStructUnionWS_Crypto_30_LibCv_General(Index, (Crypto_30_LibCv_GetDataOfStructUnionWS_Crypto_30_LibCv_General(Index) + Value))
#define Crypto_30_LibCv_AddWrittenLength(Index, Value)                                              Crypto_30_LibCv_SetWrittenLength(Index, (Crypto_30_LibCv_GetWrittenLength(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCSubstractDataMacros  Crypto_30_LibCv Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define Crypto_30_LibCv_SubBufferLength(Index, Value)                                               Crypto_30_LibCv_SetBufferLength(Index, (Crypto_30_LibCv_GetBufferLength(Index) - Value))
#define Crypto_30_LibCv_SubDispatch_QueuePrimitiveInfoIdx(Index, Value)                             Crypto_30_LibCv_SetDispatch_QueuePrimitiveInfoIdx(Index, (Crypto_30_LibCv_GetDispatch_QueuePrimitiveInfoIdx(Index) - Value))
#define Crypto_30_LibCv_SubDriverObjectState(Index, Value)                                          Crypto_30_LibCv_SetDriverObjectState(Index, (Crypto_30_LibCv_GetDriverObjectState(Index) - Value))
#define Crypto_30_LibCv_SubKeyLock(Index, Value)                                                    Crypto_30_LibCv_SetKeyLock(Index, (Crypto_30_LibCv_GetKeyLock(Index) - Value))
#define Crypto_30_LibCv_SubKeyNvStatus(Index, Value)                                                Crypto_30_LibCv_SetKeyNvStatus(Index, (Crypto_30_LibCv_GetKeyNvStatus(Index) - Value))
#define Crypto_30_LibCv_SubKeyStorage(Index, Value)                                                 Crypto_30_LibCv_SetKeyStorage(Index, (Crypto_30_LibCv_GetKeyStorage(Index) - Value))
#define Crypto_30_LibCv_SubFamilyOfLastJob(Index, Value)                                              /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Family' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_SubKeyIdOfLastJob(Index, Value)                                               /**< Deactivateable: 'Crypto_30_LibCv_LastJob.KeyId' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_SubModeOfLastJob(Index, Value)                                                /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Mode' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_SubLock(Index, Value)                                                       Crypto_30_LibCv_SetLock(Index, (Crypto_30_LibCv_GetLock(Index) - Value))
#define Crypto_30_LibCv_SubLongTermWs(Index, Value)                                                   /**< Deactivateable: 'Crypto_30_LibCv_LongTermWs' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_SubLongTermWsLock(Index, Value)                                               /**< Deactivateable: 'Crypto_30_LibCv_LongTermWsLock' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_SubPartitionInitialized(Value, partitionIndex)                              Crypto_30_LibCv_SetPartitionInitialized((Crypto_30_LibCv_GetPartitionInitialized(partitionIndex) - Value), partitionIndex)
#define Crypto_30_LibCv_SubQueue(Index, Value)                                                      Crypto_30_LibCv_SetQueue(Index, (Crypto_30_LibCv_GetQueue(Index) - Value))
#define Crypto_30_LibCv_SubRandomSeedBuffer(Index, Value)                                           Crypto_30_LibCv_SetRandomSeedBuffer(Index, (Crypto_30_LibCv_GetRandomSeedBuffer(Index) - Value))
#define Crypto_30_LibCv_SubRandomSourceGenerateCount(Value, partitionIndex)                         Crypto_30_LibCv_SetRandomSourceGenerateCount((Crypto_30_LibCv_GetRandomSourceGenerateCount(partitionIndex) - Value), partitionIndex)
#define Crypto_30_LibCv_SubRedirect_Buffer(Index, Value)                                            Crypto_30_LibCv_SetRedirect_Buffer(Index, (Crypto_30_LibCv_GetRedirect_Buffer(Index) - Value))
#define Crypto_30_LibCv_SubLengthOfSaveAndRestoreWorkspace(Index, Value)                              /**< Deactivateable: 'Crypto_30_LibCv_SaveAndRestoreWorkspace.Length' Reason: 'Disable Feature if no Context primitive is used' */
#define Crypto_30_LibCv_SubDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0(Index, Value)           Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0(Index, (Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0(Index) - Value))
#define Crypto_30_LibCv_SubDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished(Index, Value) Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished(Index, (Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished(Index) - Value))
#define Crypto_30_LibCv_SubDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1(Index, Value)           Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1(Index, (Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1(Index) - Value))
#define Crypto_30_LibCv_SubDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished(Index, Value) Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished(Index, (Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished(Index) - Value))
#define Crypto_30_LibCv_SubDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384(Index, Value) Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384(Index, (Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384(Index) - Value))
#define Crypto_30_LibCv_SubDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384(Index, Value) Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384(Index, (Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384(Index) - Value))
#define Crypto_30_LibCv_SubDataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1(Index, Value) Crypto_30_LibCv_SetDataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1(Index, (Crypto_30_LibCv_GetDataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1(Index) - Value))
#define Crypto_30_LibCv_SubDataOfStructUnionWS_Crypto_30_LibCv(Index, Value)                        Crypto_30_LibCv_SetDataOfStructUnionWS_Crypto_30_LibCv(Index, (Crypto_30_LibCv_GetDataOfStructUnionWS_Crypto_30_LibCv(Index) - Value))
#define Crypto_30_LibCv_SubDataOfStructUnionWS_Crypto_30_LibCv_General(Index, Value)                Crypto_30_LibCv_SetDataOfStructUnionWS_Crypto_30_LibCv_General(Index, (Crypto_30_LibCv_GetDataOfStructUnionWS_Crypto_30_LibCv_General(Index) - Value))
#define Crypto_30_LibCv_SubWrittenLength(Index, Value)                                              Crypto_30_LibCv_SetWrittenLength(Index, (Crypto_30_LibCv_GetWrittenLength(Index) - Value))
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
/** 
  \defgroup  Crypto_30_LibCvPBGetRootDataMacros  Crypto_30_LibCv Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Crypto_30_LibCv_GetLTConfigIdxOfPBConfig()                                                    /**< Deactivateable: 'Crypto_30_LibCv_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_LibCv_GetPBPartitionConfigOfPBConfig()                                              /**< Deactivateable: 'Crypto_30_LibCv_PBConfig.PBPartitionConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_LibCv_GetPCConfigIdxOfPBConfig()                                                    /**< Deactivateable: 'Crypto_30_LibCv_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPBHasMacros  Crypto_30_LibCv Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Crypto_30_LibCv_HasPBConfig()                                                                 /**< Deactivateable: 'Crypto_30_LibCv_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_LibCv_HasLTConfigIdxOfPBConfig(partitionIndex)                                      /**< Deactivateable: 'Crypto_30_LibCv_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_LibCv_HasPBPartitionConfigOfPBConfig()                                              /**< Deactivateable: 'Crypto_30_LibCv_PBConfig.PBPartitionConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_LibCv_HasPCConfigIdxOfPBConfig(partitionIndex)                                      /**< Deactivateable: 'Crypto_30_LibCv_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_LibCv_HasPBPartitionConfig()                                                        /**< Deactivateable: 'Crypto_30_LibCv_PBPartitionConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


#define CRYPTO_30_LIBCV_INITMEMORY                     STD_ON 
#define CRYPTO_30_LIBCV_NVBLOCK_READFROM_CRYPTONVBLOCK STD_ON 
#define CRYPTO_30_LIBCV_NVBLOCK_WRITETO_CRYPTONVBLOCK  STD_ON 
#define CRYPTO_30_LIBCV_NVBLOCK_INIT_CRYPTONVBLOCK     STD_ON 
#define CRYPTO_30_LIBCV_NVBLOCK_CALLBACK_CRYPTONVBLOCK STD_ON 


/* PRQA S 3453 LOCKMACROS_3453 */  /* MD_CSL_3453 */
#define Crypto_30_LibCv_FreeLock(lockIdx) Crypto_30_LibCv_SetLock((lockIdx), 0xFFFFFFFFu)
#define Crypto_30_LibCv_IsLockFree(lockIdx) (Crypto_30_LibCv_GetLock((lockIdx))) == 0xFFFFFFFFu
#define Crypto_30_LibCv_IsLockOccupiedByJob(lockIdx, jobId) (Crypto_30_LibCv_GetLock((lockIdx))) == (jobId)
/* PRQA L:LOCKMACROS_3453 */


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/** Elliptic Curve workspace buffer type */
typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  eslt_WorkSpaceEcP wsEcP;
  vSecPrimType_WorkSpaceHash wsPreHash;
} Crypto_30_LibCv_WorkSpaceEcP;

/** AES workspace union type */
typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  eslt_WorkSpaceAES128 wsAES128;
  eslt_WorkSpaceAES256 wsAES256;
} Crypto_30_LibCv_WorkSpaceAESSubType;

/** AES workspace struct type */
typedef struct
{
  uint8 mode;
  Crypto_30_LibCv_WorkSpaceAESSubType wsAES;
} Crypto_30_LibCv_WorkSpaceAES;

/** CMAC AES workspace struct type */
typedef struct
{
  uint8 mode;
  eslt_WorkSpaceCMACAES wsCMACAES;
} Crypto_30_LibCv_WorkSpaceCMACAES;

/** KDF ISO15118 workspace buffer type */
typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  eslt_WorkSpaceEcP wsEcP;
  eslt_WorkSpaceSHA256 wsSHA256;
  eslt_WorkSpaceAES128 wsAes;
} Crypto_30_LibCv_WorkSpaceISO15118;

/** KDF ISO15118-20 workspace buffer type */
typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  eslt_WorkSpaceEcP wsEcP;
  eslt_WorkSpaceHKDFHASH wsHkdfSHA512;
  eslt_WorkSpaceGCM wsAesGcm;
  eslt_WorkSpaceEdDH wsEdDH;
} Crypto_30_LibCv_WorkSpaceISO15118_20;

/** RSA PSS workspace struct type */
typedef struct
{
  uint32 saltLength;
  eslt_WorkSpaceRSAPSSver wsRsa;
} Crypto_30_LibCv_WorkSpaceRsaPssVer;

/** RSA Decrypt struct type */
typedef struct
{
  uint8 decryptionMode;
  eslt_WorkSpaceRSAdec wsRsa;
} Crypto_30_LibCv_WorkSpaceRsaDecrypt;


typedef uint8 Crypto_30_LibCv_WorkSpaceKeySetValidity; /* No Workspace Required */

typedef uint8 Crypto_30_LibCv_WorkSpaceKeyGenerateSymmetric;  /* No Workspace Required */

typedef P2FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE, Crypto_30_LibCv_DispatchFctPtrType)(uint32 objectId, P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,  Crypto_OperationModeType mode);

typedef P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) Crypto_30_LibCv_SaveAndRestoreWorkspaceAddressType;

typedef P2VAR(Crypto_JobType, TYPEDEF, CRYPTO_30_LIBCV_APPL_VAR) Crypto_30_LibCv_JobPtrType;


typedef struct
{
  uint32 firstOutputLength;
  uint32 firstOutputLengthWritten;
  uint32 secondaryOutputLength;
  uint32 secondaryOutputLengthWritten;
  Crypto_JobPrimitiveInputOutputType jobPrimitiveInputOutput_Restore;
} Crypto_30_LibCv_Redirect_Type;

typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  Crypto_30_LibCv_WorkSpaceAES AesEncrypt;
  Crypto_30_LibCv_WorkSpaceAES AesDecrypt;
  vSecPrimType_WorkSpaceHash Hash;
  eslt_WorkSpaceHMACSHA256 HmacSha256Generate;
  eslt_WorkSpaceHMACSHA256 HmacSha256Verify;
  eslt_WorkSpaceHMACSHA1 HmacSha1Generate;
  eslt_WorkSpaceHMACSHA1 HmacSha1Verify;
  eslt_WorkSpaceFIPS186 Fips186;
  Crypto_30_LibCv_WorkSpaceEcP EcP256Generate;
  Crypto_30_LibCv_WorkSpaceEcP EcP256Verify;
  Crypto_30_LibCv_WorkSpaceEcP EcP521Generate;
  Crypto_30_LibCv_WorkSpaceEcP EcP521Verify;
} Crypto_30_LibCv_UnionWS_CryptoDriverObject_Tls_Conn0_Type;

typedef struct sCrypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn0_Type
{
#if (CRYPTO_30_LIBCV_SAVEANDRESTOREWORKSPACE == STD_ON)
  uint8 settings[8];
#endif
  Crypto_30_LibCv_UnionWS_CryptoDriverObject_Tls_Conn0_Type primWS;
} Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn0_Type;

typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  vSecPrimType_WorkSpaceHash Hash;
} Crypto_30_LibCv_UnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished_Type;

typedef struct sCrypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished_Type
{
#if (CRYPTO_30_LIBCV_SAVEANDRESTOREWORKSPACE == STD_ON)
  uint8 settings[8];
#endif
  Crypto_30_LibCv_UnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished_Type primWS;
} Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished_Type;

typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  Crypto_30_LibCv_WorkSpaceAES AesEncrypt;
  Crypto_30_LibCv_WorkSpaceAES AesDecrypt;
  eslt_WorkSpaceGCM AesGcmEncrypt;
  eslt_WorkSpaceGCM AesGcmDecrypt;
  eslt_WorkSpaceChaChaPoly AEADChaChaPoly1305Encrypt;
  eslt_WorkSpaceChaChaPoly AEADChaChaPoly1305Decrypt;
  vSecPrimType_WorkSpaceHash Hash;
  Crypto_30_LibCv_WorkSpaceCMACAES CmacAesGenerate;
  Crypto_30_LibCv_WorkSpaceCMACAES CmacAesVerify;
  eslt_WorkSpaceGMAC GmacAesGenerate;
  eslt_WorkSpaceGMAC GmacAesVerify;
  eslt_WorkSpaceHMACSHA384 HmacSha384Generate;
  eslt_WorkSpaceHMACSHA384 HmacSha384Verify;
  eslt_WorkSpaceHMACSHA256 HmacSha256Generate;
  eslt_WorkSpaceHMACSHA256 HmacSha256Verify;
  eslt_WorkSpaceHMACSHA1 HmacSha1Generate;
  eslt_WorkSpaceHMACSHA1 HmacSha1Verify;
  eslt_WorkSpaceFIPS186 Fips186;
  eslt_WorkSpaceCTRDRBG DRBGAES;
  eslt_WorkSpaceEd25519 Ed25519Generate;
  eslt_WorkSpaceEd25519 Ed25519Verify;
  Crypto_30_LibCv_WorkSpaceEcP EcP256Generate;
  Crypto_30_LibCv_WorkSpaceEcP EcP256Verify;
  Crypto_30_LibCv_WorkSpaceEcP EcP521Generate;
  Crypto_30_LibCv_WorkSpaceEcP EcP521Verify;
  Crypto_30_LibCv_WorkSpaceISO15118 KeyDeriveISO15118;
} Crypto_30_LibCv_UnionWS_CryptoDriverObject_Tls_Conn1_Type;

typedef struct sCrypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn1_Type
{
#if (CRYPTO_30_LIBCV_SAVEANDRESTOREWORKSPACE == STD_ON)
  uint8 settings[8];
#endif
  Crypto_30_LibCv_UnionWS_CryptoDriverObject_Tls_Conn1_Type primWS;
} Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn1_Type;

typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  vSecPrimType_WorkSpaceHash Hash;
} Crypto_30_LibCv_UnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished_Type;

typedef struct sCrypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished_Type
{
#if (CRYPTO_30_LIBCV_SAVEANDRESTOREWORKSPACE == STD_ON)
  uint8 settings[8];
#endif
  Crypto_30_LibCv_UnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished_Type primWS;
} Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished_Type;

typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  vSecPrimType_WorkSpaceHash Hash;
  eslt_WorkSpaceHKDFHMAC KeyDeriveHKDFExpandHMACSHA384;
} Crypto_30_LibCv_UnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384_Type;

typedef struct sCrypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn1_HS_HashSha384_Type
{
#if (CRYPTO_30_LIBCV_SAVEANDRESTOREWORKSPACE == STD_ON)
  uint8 settings[8];
#endif
  Crypto_30_LibCv_UnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384_Type primWS;
} Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn1_HS_HashSha384_Type;

typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  eslt_WorkSpaceHKDFHMAC KeyDeriveHKDFHMACSHA256;
  eslt_WorkSpaceHKDFHMAC KeyDeriveHKDFHMACSHA384;
} Crypto_30_LibCv_UnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384_Type;

typedef struct sCrypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384_Type
{
#if (CRYPTO_30_LIBCV_SAVEANDRESTOREWORKSPACE == STD_ON)
  uint8 settings[8];
#endif
  Crypto_30_LibCv_UnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384_Type primWS;
} Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384_Type;

typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  vSecPrimType_WorkSpaceHash Hash;
} Crypto_30_LibCv_UnionWS_CryptoDriverObject_Tls_Global_HashSha1_Type;

typedef struct sCrypto_30_LibCv_WS_CryptoDriverObject_Tls_Global_HashSha1_Type
{
#if (CRYPTO_30_LIBCV_SAVEANDRESTOREWORKSPACE == STD_ON)
  uint8 settings[8];
#endif
  Crypto_30_LibCv_UnionWS_CryptoDriverObject_Tls_Global_HashSha1_Type primWS;
} Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Global_HashSha1_Type;

typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  Crypto_30_LibCv_WorkSpaceAES AesEncrypt;
  Crypto_30_LibCv_WorkSpaceAES AesDecrypt;
  vSecPrimType_WorkSpaceHash Hash;
  eslt_WorkSpaceHMACSHA256 HmacSha256Generate;
  eslt_WorkSpaceHMACSHA256 HmacSha256Verify;
  eslt_WorkSpaceHMACSHA1 HmacSha1Generate;
  eslt_WorkSpaceHMACSHA1 HmacSha1Verify;
  eslt_WorkSpaceCTRDRBG DRBGAES;
  Crypto_30_LibCv_WorkSpaceEcP EcP256Generate;
  Crypto_30_LibCv_WorkSpaceEcP EcP256Verify;
  Crypto_30_LibCv_WorkSpaceEcP EcP521Generate;
  Crypto_30_LibCv_WorkSpaceEcP EcP521Verify;
  eslt_WorkSpaceEcP KeyP256R1Secret;
  Crypto_30_LibCv_WorkSpaceISO15118 KeyDeriveISO15118;
} Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Type;

typedef struct sCrypto_30_LibCv_WS_Crypto_30_LibCv_Type
{
#if (CRYPTO_30_LIBCV_SAVEANDRESTOREWORKSPACE == STD_ON)
  uint8 settings[8];
#endif
  Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Type primWS;
} Crypto_30_LibCv_WS_Crypto_30_LibCv_Type;

typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  vSecPrimType_WorkSpaceHash Hash;
  Crypto_30_LibCv_WorkSpaceCMACAES CmacAesGenerate;
  Crypto_30_LibCv_WorkSpaceCMACAES CmacAesVerify;
  eslt_WorkSpaceGMAC GmacAesGenerate;
  eslt_WorkSpaceGMAC GmacAesVerify;
  eslt_WorkSpaceHMACSHA384 HmacSha384Generate;
  eslt_WorkSpaceHMACSHA256 HmacSha256Generate;
  eslt_WorkSpaceHMACSHA256 HmacSha256Verify;
  Crypto_30_LibCv_WorkSpaceEcP EcP256Generate;
  Crypto_30_LibCv_WorkSpaceEcP EcP256Verify;
  Crypto_30_LibCv_WorkSpaceEcP EcP521Generate;
  Crypto_30_LibCv_WorkSpaceEcP EcP521Verify;
  eslt_WorkSpaceHKDFHMAC KeyDeriveHKDFHMACSHA256;
  eslt_WorkSpaceHKDFHMAC KeyDeriveHKDFExpandHMACSHA256;
  Crypto_30_LibCv_WorkSpaceISO15118 KeyDeriveISO15118;
  Crypto_30_LibCv_WorkSpaceISO15118_20 KeyDeriveISO15118_20;
  eslt_WorkSpaceEcP KeyGenP256R1;
} Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_General_Type;

typedef struct sCrypto_30_LibCv_WS_Crypto_30_LibCv_General_Type
{
#if (CRYPTO_30_LIBCV_SAVEANDRESTOREWORKSPACE == STD_ON)
  uint8 settings[8];
#endif
  Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_General_Type primWS;
} Crypto_30_LibCv_WS_Crypto_30_LibCv_General_Type;

typedef P2VAR(Crypto_30_LibCv_WorkSpaceAES, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Crypto_30_LibCv_WorkSpaceAES_PtrType;
typedef P2VAR(vSecPrimType_WorkSpaceHash, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_vSecPrimType_WorkSpaceHash_PtrType;
typedef P2VAR(eslt_WorkSpaceHMACSHA256, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_eslt_WorkSpaceHMACSHA256_PtrType;
typedef P2VAR(eslt_WorkSpaceHMACSHA1, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_eslt_WorkSpaceHMACSHA1_PtrType;
typedef P2VAR(eslt_WorkSpaceFIPS186, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_eslt_WorkSpaceFIPS186_PtrType;
typedef P2VAR(Crypto_30_LibCv_WorkSpaceEcP, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Crypto_30_LibCv_WorkSpaceEcP_PtrType;
typedef P2VAR(eslt_WorkSpaceGCM, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_eslt_WorkSpaceGCM_PtrType;
typedef P2VAR(eslt_WorkSpaceChaChaPoly, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_eslt_WorkSpaceChaChaPoly_PtrType;
typedef P2VAR(Crypto_30_LibCv_WorkSpaceCMACAES, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Crypto_30_LibCv_WorkSpaceCMACAES_PtrType;
typedef P2VAR(eslt_WorkSpaceGMAC, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_eslt_WorkSpaceGMAC_PtrType;
typedef P2VAR(eslt_WorkSpaceHMACSHA384, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_eslt_WorkSpaceHMACSHA384_PtrType;
typedef P2VAR(eslt_WorkSpaceCTRDRBG, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_eslt_WorkSpaceCTRDRBG_PtrType;
typedef P2VAR(eslt_WorkSpaceEd25519, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_eslt_WorkSpaceEd25519_PtrType;
typedef P2VAR(Crypto_30_LibCv_WorkSpaceISO15118, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Crypto_30_LibCv_WorkSpaceISO15118_PtrType;
typedef P2VAR(eslt_WorkSpaceHKDFHMAC, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_eslt_WorkSpaceHKDFHMAC_PtrType;
typedef P2VAR(eslt_WorkSpaceEcP, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_eslt_WorkSpaceEcP_PtrType;
typedef P2VAR(Crypto_30_LibCv_WorkSpaceISO15118_20, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Crypto_30_LibCv_WorkSpaceISO15118_20_PtrType;


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_LibCvPCIterableTypes  Crypto_30_LibCv Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Crypto_30_LibCv_AEADChaChaPoly1305Decrypt */
typedef uint8_least Crypto_30_LibCv_AEADChaChaPoly1305DecryptIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_AEADChaChaPoly1305Encrypt */
typedef uint8_least Crypto_30_LibCv_AEADChaChaPoly1305EncryptIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_AesDecrypt */
typedef uint8_least Crypto_30_LibCv_AesDecryptIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_AesEncrypt */
typedef uint8_least Crypto_30_LibCv_AesEncryptIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_AesGcmDecrypt */
typedef uint8_least Crypto_30_LibCv_AesGcmDecryptIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_AesGcmEncrypt */
typedef uint8_least Crypto_30_LibCv_AesGcmEncryptIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_CmacAesGenerate */
typedef uint8_least Crypto_30_LibCv_CmacAesGenerateIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_CmacAesVerify */
typedef uint8_least Crypto_30_LibCv_CmacAesVerifyIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_DRBGAES */
typedef uint8_least Crypto_30_LibCv_DRBGAESIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_EcP256Generate */
typedef uint8_least Crypto_30_LibCv_EcP256GenerateIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_EcP256Verify */
typedef uint8_least Crypto_30_LibCv_EcP256VerifyIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_EcP521Generate */
typedef uint8_least Crypto_30_LibCv_EcP521GenerateIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_EcP521Verify */
typedef uint8_least Crypto_30_LibCv_EcP521VerifyIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_Ed25519Generate */
typedef uint8_least Crypto_30_LibCv_Ed25519GenerateIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_Ed25519Verify */
typedef uint8_least Crypto_30_LibCv_Ed25519VerifyIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_FamilyToHashMapping */
typedef uint8_least Crypto_30_LibCv_FamilyToHashMappingIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_Fips186 */
typedef uint8_least Crypto_30_LibCv_Fips186IterType;

/**   \brief  type used to iterate Crypto_30_LibCv_GmacAesGenerate */
typedef uint8_least Crypto_30_LibCv_GmacAesGenerateIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_GmacAesVerify */
typedef uint8_least Crypto_30_LibCv_GmacAesVerifyIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_Hash */
typedef uint8_least Crypto_30_LibCv_HashIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_HmacSha1Generate */
typedef uint8_least Crypto_30_LibCv_HmacSha1GenerateIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_HmacSha1Verify */
typedef uint8_least Crypto_30_LibCv_HmacSha1VerifyIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_HmacSha256Generate */
typedef uint8_least Crypto_30_LibCv_HmacSha256GenerateIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_HmacSha256Verify */
typedef uint8_least Crypto_30_LibCv_HmacSha256VerifyIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_HmacSha384Generate */
typedef uint8_least Crypto_30_LibCv_HmacSha384GenerateIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_HmacSha384Verify */
typedef uint8_least Crypto_30_LibCv_HmacSha384VerifyIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_InitValue */
typedef uint8_least Crypto_30_LibCv_InitValueIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_Key */
typedef uint8_least Crypto_30_LibCv_KeyIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256 */
typedef uint8_least Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256IterType;

/**   \brief  type used to iterate Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384 */
typedef uint8_least Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384IterType;

/**   \brief  type used to iterate Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256 */
typedef uint8_least Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256IterType;

/**   \brief  type used to iterate Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384 */
typedef uint8_least Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384IterType;

/**   \brief  type used to iterate Crypto_30_LibCv_KeyDeriveISO15118 */
typedef uint8_least Crypto_30_LibCv_KeyDeriveISO15118IterType;

/**   \brief  type used to iterate Crypto_30_LibCv_KeyDeriveISO15118_20 */
typedef uint8_least Crypto_30_LibCv_KeyDeriveISO15118_20IterType;

/**   \brief  type used to iterate Crypto_30_LibCv_KeyElementInfo */
typedef uint8_least Crypto_30_LibCv_KeyElementInfoIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_KeyElements */
typedef uint8_least Crypto_30_LibCv_KeyElementsIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_KeyGenP256R1 */
typedef uint8_least Crypto_30_LibCv_KeyGenP256R1IterType;

/**   \brief  type used to iterate Crypto_30_LibCv_KeyP256R1Secret */
typedef uint8_least Crypto_30_LibCv_KeyP256R1SecretIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_KeyStorage */
typedef uint16_least Crypto_30_LibCv_KeyStorageIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_NvBlock */
typedef uint8_least Crypto_30_LibCv_NvBlockIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_ObjectInfo */
typedef uint8_least Crypto_30_LibCv_ObjectInfoIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_ObjectInfoInd */
typedef uint8_least Crypto_30_LibCv_ObjectInfoIndIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_PartitionIdentifiers */
typedef uint8_least Crypto_30_LibCv_PartitionIdentifiersIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_PartitionInfo */
typedef uint8_least Crypto_30_LibCv_PartitionInfoIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_PrimitiveFct */
typedef uint8_least Crypto_30_LibCv_PrimitiveFctIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_PrimitiveInfo */
typedef uint8_least Crypto_30_LibCv_PrimitiveInfoIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_PrimitiveServiceInfo */
typedef uint8_least Crypto_30_LibCv_PrimitiveServiceInfoIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_Queue */
typedef uint8_least Crypto_30_LibCv_QueueIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_RandomSeedBuffer */
typedef uint8_least Crypto_30_LibCv_RandomSeedBufferIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0 */
typedef uint8_least Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0IterType;

/**   \brief  type used to iterate Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished */
typedef uint8_least Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_FinishedIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1 */
typedef uint8_least Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1IterType;

/**   \brief  type used to iterate Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished */
typedef uint8_least Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_FinishedIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384 */
typedef uint8_least Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384IterType;

/**   \brief  type used to iterate Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384 */
typedef uint8_least Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384IterType;

/**   \brief  type used to iterate Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1 */
typedef uint8_least Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1IterType;

/**   \brief  type used to iterate Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv */
typedef uint8_least Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCvIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General */
typedef uint8_least Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_GeneralIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_PCPartitionConfig */
typedef uint8_least Crypto_30_LibCv_PCPartitionConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCIterableTypesWithSizeRelations  Crypto_30_LibCv Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate Crypto_30_LibCv_BufferLength */
typedef Crypto_30_LibCv_ObjectInfoIterType Crypto_30_LibCv_BufferLengthIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_Dispatch_QueuePrimitiveInfoIdx */
typedef Crypto_30_LibCv_ObjectInfoIterType Crypto_30_LibCv_Dispatch_QueuePrimitiveInfoIdxIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_DriverObjectState */
typedef Crypto_30_LibCv_ObjectInfoIterType Crypto_30_LibCv_DriverObjectStateIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_KeyLock */
typedef Crypto_30_LibCv_KeyIterType Crypto_30_LibCv_KeyLockIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_KeyNvStatus */
typedef Crypto_30_LibCv_KeyIterType Crypto_30_LibCv_KeyNvStatusIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_Lock */
typedef Crypto_30_LibCv_ObjectInfoIterType Crypto_30_LibCv_LockIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_ProcessJob_Trigger_Write */
typedef Crypto_30_LibCv_ObjectInfoIterType Crypto_30_LibCv_ProcessJob_Trigger_WriteIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_Redirect_Buffer */
typedef Crypto_30_LibCv_ObjectInfoIterType Crypto_30_LibCv_Redirect_BufferIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_WrittenLength */
typedef Crypto_30_LibCv_ObjectInfoIterType Crypto_30_LibCv_WrittenLengthIterType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCValueTypes  Crypto_30_LibCv Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Crypto_30_LibCv_BufferLength */
typedef uint32 Crypto_30_LibCv_BufferLengthType;

/**   \brief  value based type definition for Crypto_30_LibCv_DriverObjectState */
typedef uint8 Crypto_30_LibCv_DriverObjectStateType;

/**   \brief  value based type definition for Crypto_30_LibCv_FamilyToHashMapping */
typedef uint8 Crypto_30_LibCv_FamilyToHashMappingType;

/**   \brief  value based type definition for Crypto_30_LibCv_InitValue */
typedef uint8 Crypto_30_LibCv_InitValueType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyElementsEndIdxOfKey */
typedef uint8 Crypto_30_LibCv_KeyElementsEndIdxOfKeyType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyElementsStartIdxOfKey */
typedef uint8 Crypto_30_LibCv_KeyElementsStartIdxOfKeyType;

/**   \brief  value based type definition for Crypto_30_LibCv_NvBlockIdxOfKey */
typedef uint8 Crypto_30_LibCv_NvBlockIdxOfKeyType;

/**   \brief  value based type definition for Crypto_30_LibCv_NvBlockUsedOfKey */
typedef boolean Crypto_30_LibCv_NvBlockUsedOfKeyType;

/**   \brief  value based type definition for Crypto_30_LibCv_IdOfKeyElementInfo */
typedef uint16 Crypto_30_LibCv_IdOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_InitValueEndIdxOfKeyElementInfo */
typedef uint8 Crypto_30_LibCv_InitValueEndIdxOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_InitValueStartIdxOfKeyElementInfo */
typedef uint8 Crypto_30_LibCv_InitValueStartIdxOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_InitValueUsedOfKeyElementInfo */
typedef boolean Crypto_30_LibCv_InitValueUsedOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_LengthOfKeyElementInfo */
typedef uint8 Crypto_30_LibCv_LengthOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_MaskedBitsOfKeyElementInfo */
typedef uint8 Crypto_30_LibCv_MaskedBitsOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_OnceOfKeyElementInfo */
typedef boolean Crypto_30_LibCv_OnceOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_PartialOfKeyElementInfo */
typedef boolean Crypto_30_LibCv_PartialOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_PersistOfKeyElementInfo */
typedef boolean Crypto_30_LibCv_PersistOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_ReadOfKeyElementInfo */
typedef uint8 Crypto_30_LibCv_ReadOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_WriteOfKeyElementInfo */
typedef uint8 Crypto_30_LibCv_WriteOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_IdOfKeyElements */
typedef uint16 Crypto_30_LibCv_IdOfKeyElementsType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyElementInfoIdxOfKeyElements */
typedef uint8 Crypto_30_LibCv_KeyElementInfoIdxOfKeyElementsType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyStorageEndIdxOfKeyElements */
typedef uint16 Crypto_30_LibCv_KeyStorageEndIdxOfKeyElementsType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyStorageExtensionIdxOfKeyElements */
typedef uint16 Crypto_30_LibCv_KeyStorageExtensionIdxOfKeyElementsType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyStorageStartIdxOfKeyElements */
typedef uint16 Crypto_30_LibCv_KeyStorageStartIdxOfKeyElementsType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyStorageValidIdxOfKeyElements */
typedef uint16 Crypto_30_LibCv_KeyStorageValidIdxOfKeyElementsType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyStorageWrittenLengthEndIdxOfKeyElements */
typedef uint16 Crypto_30_LibCv_KeyStorageWrittenLengthEndIdxOfKeyElementsType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyStorageWrittenLengthStartIdxOfKeyElements */
typedef uint16 Crypto_30_LibCv_KeyStorageWrittenLengthStartIdxOfKeyElementsType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyLock */
typedef uint8 Crypto_30_LibCv_KeyLockType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyNvStatus */
typedef uint8 Crypto_30_LibCv_KeyNvStatusType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyStorage */
typedef uint8 Crypto_30_LibCv_KeyStorageType;

/**   \brief  value based type definition for Crypto_30_LibCv_Lock */
typedef uint32 Crypto_30_LibCv_LockType;

/**   \brief  value based type definition for Crypto_30_LibCv_MainFunctionPeriodOfGeneral */
typedef uint8 Crypto_30_LibCv_MainFunctionPeriodOfGeneralType;

/**   \brief  value based type definition for Crypto_30_LibCv_ConsistencyLevelOfNvBlock */
typedef uint8 Crypto_30_LibCv_ConsistencyLevelOfNvBlockType;

/**   \brief  value based type definition for Crypto_30_LibCv_CrcOfNvBlock */
typedef uint32 Crypto_30_LibCv_CrcOfNvBlockType;

/**   \brief  value based type definition for Crypto_30_LibCv_DescriptorOfNvBlock */
typedef uint16 Crypto_30_LibCv_DescriptorOfNvBlockType;

/**   \brief  value based type definition for Crypto_30_LibCv_IdOfNvBlock */
typedef uint8 Crypto_30_LibCv_IdOfNvBlockType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyStorageEndIdxOfNvBlock */
typedef uint16 Crypto_30_LibCv_KeyStorageEndIdxOfNvBlockType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyStorageStartIdxOfNvBlock */
typedef uint16 Crypto_30_LibCv_KeyStorageStartIdxOfNvBlockType;

/**   \brief  value based type definition for Crypto_30_LibCv_LengthOfNvBlock */
typedef uint16 Crypto_30_LibCv_LengthOfNvBlockType;

/**   \brief  value based type definition for Crypto_30_LibCv_ProcessingOfNvBlock */
typedef uint8 Crypto_30_LibCv_ProcessingOfNvBlockType;

/**   \brief  value based type definition for Crypto_30_LibCv_AEADChaChaPoly1305DecryptIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_AEADChaChaPoly1305DecryptIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_AEADChaChaPoly1305DecryptUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_AEADChaChaPoly1305DecryptUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_AEADChaChaPoly1305EncryptIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_AEADChaChaPoly1305EncryptIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_AEADChaChaPoly1305EncryptUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_AEADChaChaPoly1305EncryptUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_AesDecryptIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_AesDecryptIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_AesDecryptUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_AesDecryptUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_AesEncryptIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_AesEncryptIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_AesEncryptUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_AesEncryptUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_AesGcmDecryptIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_AesGcmDecryptIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_AesGcmDecryptUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_AesGcmDecryptUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_AesGcmEncryptIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_AesGcmEncryptIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_AesGcmEncryptUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_AesGcmEncryptUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_CmacAesGenerateIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_CmacAesGenerateIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_CmacAesGenerateUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_CmacAesGenerateUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_CmacAesVerifyIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_CmacAesVerifyIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_CmacAesVerifyUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_CmacAesVerifyUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_DRBGAESIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_DRBGAESIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_DRBGAESUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_DRBGAESUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_EcP256GenerateIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_EcP256GenerateIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_EcP256GenerateUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_EcP256GenerateUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_EcP256VerifyIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_EcP256VerifyIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_EcP256VerifyUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_EcP256VerifyUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_EcP521GenerateIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_EcP521GenerateIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_EcP521GenerateUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_EcP521GenerateUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_EcP521VerifyIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_EcP521VerifyIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_EcP521VerifyUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_EcP521VerifyUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_Ed25519GenerateIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_Ed25519GenerateIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_Ed25519GenerateUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_Ed25519GenerateUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_Ed25519VerifyIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_Ed25519VerifyIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_Ed25519VerifyUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_Ed25519VerifyUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_Fips186IdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_Fips186IdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_Fips186UsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_Fips186UsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_GmacAesGenerateIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_GmacAesGenerateIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_GmacAesGenerateUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_GmacAesGenerateUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_GmacAesVerifyIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_GmacAesVerifyIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_GmacAesVerifyUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_GmacAesVerifyUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_HashIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_HashIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_HashUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_HashUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_HmacSha1GenerateIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_HmacSha1GenerateIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_HmacSha1GenerateUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_HmacSha1GenerateUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_HmacSha1VerifyIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_HmacSha1VerifyIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_HmacSha1VerifyUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_HmacSha1VerifyUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_HmacSha256GenerateIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_HmacSha256GenerateIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_HmacSha256GenerateUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_HmacSha256GenerateUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_HmacSha256VerifyIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_HmacSha256VerifyIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_HmacSha256VerifyUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_HmacSha256VerifyUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_HmacSha384GenerateIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_HmacSha384GenerateIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_HmacSha384GenerateUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_HmacSha384GenerateUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_HmacSha384VerifyIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_HmacSha384VerifyIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_HmacSha384VerifyUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_HmacSha384VerifyUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256IdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256IdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256UsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256UsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384IdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384IdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384UsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384UsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256IdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256IdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256UsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256UsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384IdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384IdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384UsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384UsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyDeriveISO15118IdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_KeyDeriveISO15118IdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyDeriveISO15118UsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_KeyDeriveISO15118UsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyDeriveISO15118_20IdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_KeyDeriveISO15118_20IdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyDeriveISO15118_20UsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_KeyDeriveISO15118_20UsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyGenP256R1IdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_KeyGenP256R1IdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyGenP256R1UsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_KeyGenP256R1UsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyP256R1SecretIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_KeyP256R1SecretIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyP256R1SecretUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_KeyP256R1SecretUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_QueueIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_QueueIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_RandomSeedBufferEndIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_RandomSeedBufferEndIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_RandomSeedBufferStartIdxOfObjectInfo */
typedef uint8 Crypto_30_LibCv_RandomSeedBufferStartIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_RandomSeedBufferUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_RandomSeedBufferUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_WorkspaceLengthOfObjectInfo */
typedef uint32 Crypto_30_LibCv_WorkspaceLengthOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_ObjectInfoInd */
typedef uint8 Crypto_30_LibCv_ObjectInfoIndType;

/**   \brief  value based type definition for Crypto_30_LibCv_PCPartitionConfigIdxOfPartitionIdentifiers */
typedef uint8 Crypto_30_LibCv_PCPartitionConfigIdxOfPartitionIdentifiersType;

/**   \brief  value based type definition for Crypto_30_LibCv_PartitionSNVOfPartitionIdentifiers */
typedef uint32 Crypto_30_LibCv_PartitionSNVOfPartitionIdentifiersType;

/**   \brief  value based type definition for Crypto_30_LibCv_AesOfPartitionInfo */
typedef boolean Crypto_30_LibCv_AesOfPartitionInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_DefaultRandomKeyOfPartitionInfo */
typedef uint32 Crypto_30_LibCv_DefaultRandomKeyOfPartitionInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_HashOfPartitionInfo */
typedef boolean Crypto_30_LibCv_HashOfPartitionInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_MaskedBitsOfPartitionInfo */
typedef uint8 Crypto_30_LibCv_MaskedBitsOfPartitionInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_PartitionInitialized */
typedef uint8 Crypto_30_LibCv_PartitionInitializedType;

/**   \brief  value based type definition for Crypto_30_LibCv_ObjectInfoIndEndIdxOfPrimitiveFct */
typedef uint8 Crypto_30_LibCv_ObjectInfoIndEndIdxOfPrimitiveFctType;

/**   \brief  value based type definition for Crypto_30_LibCv_ObjectInfoIndStartIdxOfPrimitiveFct */
typedef uint8 Crypto_30_LibCv_ObjectInfoIndStartIdxOfPrimitiveFctType;

/**   \brief  value based type definition for Crypto_30_LibCv_ObjectInfoIndUsedOfPrimitiveFct */
typedef boolean Crypto_30_LibCv_ObjectInfoIndUsedOfPrimitiveFctType;

/**   \brief  value based type definition for Crypto_30_LibCv_CombinedOfPrimitiveInfo */
typedef uint32 Crypto_30_LibCv_CombinedOfPrimitiveInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_ContextOfPrimitiveInfo */
typedef boolean Crypto_30_LibCv_ContextOfPrimitiveInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_DefaultRandomSourceOfPrimitiveInfo */
typedef boolean Crypto_30_LibCv_DefaultRandomSourceOfPrimitiveInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_MaskedBitsOfPrimitiveInfo */
typedef uint8 Crypto_30_LibCv_MaskedBitsOfPrimitiveInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_PrimitiveFctIdxOfPrimitiveInfo */
typedef uint8 Crypto_30_LibCv_PrimitiveFctIdxOfPrimitiveInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_PrimitiveInfoEndIdxOfPrimitiveServiceInfo */
typedef uint8 Crypto_30_LibCv_PrimitiveInfoEndIdxOfPrimitiveServiceInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_PrimitiveInfoStartIdxOfPrimitiveServiceInfo */
typedef uint8 Crypto_30_LibCv_PrimitiveInfoStartIdxOfPrimitiveServiceInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_PrimitiveInfoUsedOfPrimitiveServiceInfo */
typedef boolean Crypto_30_LibCv_PrimitiveInfoUsedOfPrimitiveServiceInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_ProcessJob_Trigger_Write */
typedef boolean Crypto_30_LibCv_ProcessJob_Trigger_WriteType;

/**   \brief  value based type definition for Crypto_30_LibCv_RandomSeedBuffer */
typedef uint8 Crypto_30_LibCv_RandomSeedBufferType;

/**   \brief  value based type definition for Crypto_30_LibCv_RandomSourceGenerateCount */
typedef uint16 Crypto_30_LibCv_RandomSourceGenerateCountType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfAEADChaChaPoly1305Decrypt */
typedef uint8 Crypto_30_LibCv_SizeOfAEADChaChaPoly1305DecryptType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfAEADChaChaPoly1305Encrypt */
typedef uint8 Crypto_30_LibCv_SizeOfAEADChaChaPoly1305EncryptType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfAesDecrypt */
typedef uint8 Crypto_30_LibCv_SizeOfAesDecryptType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfAesEncrypt */
typedef uint8 Crypto_30_LibCv_SizeOfAesEncryptType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfAesGcmDecrypt */
typedef uint8 Crypto_30_LibCv_SizeOfAesGcmDecryptType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfAesGcmEncrypt */
typedef uint8 Crypto_30_LibCv_SizeOfAesGcmEncryptType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfBufferLength */
typedef uint8 Crypto_30_LibCv_SizeOfBufferLengthType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfCmacAesGenerate */
typedef uint8 Crypto_30_LibCv_SizeOfCmacAesGenerateType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfCmacAesVerify */
typedef uint8 Crypto_30_LibCv_SizeOfCmacAesVerifyType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfDRBGAES */
typedef uint8 Crypto_30_LibCv_SizeOfDRBGAESType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfDispatch_QueuePrimitiveInfoIdx */
typedef uint8 Crypto_30_LibCv_SizeOfDispatch_QueuePrimitiveInfoIdxType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfDriverObjectState */
typedef uint8 Crypto_30_LibCv_SizeOfDriverObjectStateType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfEcP256Generate */
typedef uint8 Crypto_30_LibCv_SizeOfEcP256GenerateType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfEcP256Verify */
typedef uint8 Crypto_30_LibCv_SizeOfEcP256VerifyType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfEcP521Generate */
typedef uint8 Crypto_30_LibCv_SizeOfEcP521GenerateType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfEcP521Verify */
typedef uint8 Crypto_30_LibCv_SizeOfEcP521VerifyType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfEd25519Generate */
typedef uint8 Crypto_30_LibCv_SizeOfEd25519GenerateType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfEd25519Verify */
typedef uint8 Crypto_30_LibCv_SizeOfEd25519VerifyType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfFamilyToHashMapping */
typedef uint8 Crypto_30_LibCv_SizeOfFamilyToHashMappingType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfFips186 */
typedef uint8 Crypto_30_LibCv_SizeOfFips186Type;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfGmacAesGenerate */
typedef uint8 Crypto_30_LibCv_SizeOfGmacAesGenerateType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfGmacAesVerify */
typedef uint8 Crypto_30_LibCv_SizeOfGmacAesVerifyType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfHash */
typedef uint8 Crypto_30_LibCv_SizeOfHashType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfHmacSha1Generate */
typedef uint8 Crypto_30_LibCv_SizeOfHmacSha1GenerateType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfHmacSha1Verify */
typedef uint8 Crypto_30_LibCv_SizeOfHmacSha1VerifyType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfHmacSha256Generate */
typedef uint8 Crypto_30_LibCv_SizeOfHmacSha256GenerateType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfHmacSha256Verify */
typedef uint8 Crypto_30_LibCv_SizeOfHmacSha256VerifyType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfHmacSha384Generate */
typedef uint8 Crypto_30_LibCv_SizeOfHmacSha384GenerateType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfHmacSha384Verify */
typedef uint8 Crypto_30_LibCv_SizeOfHmacSha384VerifyType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfInitValue */
typedef uint8 Crypto_30_LibCv_SizeOfInitValueType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfKey */
typedef uint8 Crypto_30_LibCv_SizeOfKeyType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfKeyDeriveHKDFExpandHMACSHA256 */
typedef uint8 Crypto_30_LibCv_SizeOfKeyDeriveHKDFExpandHMACSHA256Type;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfKeyDeriveHKDFExpandHMACSHA384 */
typedef uint8 Crypto_30_LibCv_SizeOfKeyDeriveHKDFExpandHMACSHA384Type;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfKeyDeriveHKDFHMACSHA256 */
typedef uint8 Crypto_30_LibCv_SizeOfKeyDeriveHKDFHMACSHA256Type;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfKeyDeriveHKDFHMACSHA384 */
typedef uint8 Crypto_30_LibCv_SizeOfKeyDeriveHKDFHMACSHA384Type;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfKeyDeriveISO15118 */
typedef uint8 Crypto_30_LibCv_SizeOfKeyDeriveISO15118Type;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfKeyDeriveISO15118_20 */
typedef uint8 Crypto_30_LibCv_SizeOfKeyDeriveISO15118_20Type;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfKeyElementInfo */
typedef uint8 Crypto_30_LibCv_SizeOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfKeyElements */
typedef uint8 Crypto_30_LibCv_SizeOfKeyElementsType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfKeyGenP256R1 */
typedef uint8 Crypto_30_LibCv_SizeOfKeyGenP256R1Type;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfKeyLock */
typedef uint8 Crypto_30_LibCv_SizeOfKeyLockType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfKeyNvStatus */
typedef uint8 Crypto_30_LibCv_SizeOfKeyNvStatusType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfKeyP256R1Secret */
typedef uint8 Crypto_30_LibCv_SizeOfKeyP256R1SecretType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfKeyStorage */
typedef uint16 Crypto_30_LibCv_SizeOfKeyStorageType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfLock */
typedef uint8 Crypto_30_LibCv_SizeOfLockType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfNvBlock */
typedef uint8 Crypto_30_LibCv_SizeOfNvBlockType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfObjectInfo */
typedef uint8 Crypto_30_LibCv_SizeOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfObjectInfoInd */
typedef uint8 Crypto_30_LibCv_SizeOfObjectInfoIndType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfPartitionIdentifiers */
typedef uint8 Crypto_30_LibCv_SizeOfPartitionIdentifiersType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfPartitionInfo */
typedef uint8 Crypto_30_LibCv_SizeOfPartitionInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfPrimitiveFct */
typedef uint8 Crypto_30_LibCv_SizeOfPrimitiveFctType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfPrimitiveInfo */
typedef uint8 Crypto_30_LibCv_SizeOfPrimitiveInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfPrimitiveServiceInfo */
typedef uint8 Crypto_30_LibCv_SizeOfPrimitiveServiceInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfProcessJob_Trigger_Write */
typedef uint8 Crypto_30_LibCv_SizeOfProcessJob_Trigger_WriteType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfQueue */
typedef uint8 Crypto_30_LibCv_SizeOfQueueType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfRandomSeedBuffer */
typedef uint8 Crypto_30_LibCv_SizeOfRandomSeedBufferType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfRedirect_Buffer */
typedef uint8 Crypto_30_LibCv_SizeOfRedirect_BufferType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfStructUnionWS_CryptoDriverObject_Tls_Conn0 */
typedef uint8 Crypto_30_LibCv_SizeOfStructUnionWS_CryptoDriverObject_Tls_Conn0Type;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished */
typedef uint8 Crypto_30_LibCv_SizeOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_FinishedType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1 */
typedef uint8 Crypto_30_LibCv_SizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1Type;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished */
typedef uint8 Crypto_30_LibCv_SizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_FinishedType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384 */
typedef uint8 Crypto_30_LibCv_SizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384Type;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384 */
typedef uint8 Crypto_30_LibCv_SizeOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384Type;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1 */
typedef uint8 Crypto_30_LibCv_SizeOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1Type;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfStructUnionWS_Crypto_30_LibCv */
typedef uint8 Crypto_30_LibCv_SizeOfStructUnionWS_Crypto_30_LibCvType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfStructUnionWS_Crypto_30_LibCv_General */
typedef uint8 Crypto_30_LibCv_SizeOfStructUnionWS_Crypto_30_LibCv_GeneralType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfWrittenLength */
typedef uint8 Crypto_30_LibCv_SizeOfWrittenLengthType;

/**   \brief  value based type definition for Crypto_30_LibCv_StrictLengthCheckForKeyElementGetOfGeneral */
typedef boolean Crypto_30_LibCv_StrictLengthCheckForKeyElementGetOfGeneralType;

/**   \brief  value based type definition for Crypto_30_LibCv_UseVStdLibOfGeneral */
typedef boolean Crypto_30_LibCv_UseVStdLibOfGeneralType;

/**   \brief  value based type definition for Crypto_30_LibCv_VersionInfoApiOfGeneral */
typedef boolean Crypto_30_LibCv_VersionInfoApiOfGeneralType;

/**   \brief  value based type definition for Crypto_30_LibCv_WrittenLength */
typedef uint32 Crypto_30_LibCv_WrittenLengthType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_LibCvPCStructTypes  Crypto_30_LibCv Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Crypto_30_LibCv_AEADChaChaPoly1305Decrypt */
typedef struct sCrypto_30_LibCv_AEADChaChaPoly1305DecryptType
{
  Crypto_30_LibCv_eslt_WorkSpaceChaChaPoly_PtrType WorkspaceOfAEADChaChaPoly1305Decrypt;
} Crypto_30_LibCv_AEADChaChaPoly1305DecryptType;

/**   \brief  type used in Crypto_30_LibCv_AEADChaChaPoly1305Encrypt */
typedef struct sCrypto_30_LibCv_AEADChaChaPoly1305EncryptType
{
  Crypto_30_LibCv_eslt_WorkSpaceChaChaPoly_PtrType WorkspaceOfAEADChaChaPoly1305Encrypt;
} Crypto_30_LibCv_AEADChaChaPoly1305EncryptType;

/**   \brief  type used in Crypto_30_LibCv_AesDecrypt */
typedef struct sCrypto_30_LibCv_AesDecryptType
{
  Crypto_30_LibCv_Crypto_30_LibCv_WorkSpaceAES_PtrType WorkspaceOfAesDecrypt;
} Crypto_30_LibCv_AesDecryptType;

/**   \brief  type used in Crypto_30_LibCv_AesEncrypt */
typedef struct sCrypto_30_LibCv_AesEncryptType
{
  Crypto_30_LibCv_Crypto_30_LibCv_WorkSpaceAES_PtrType WorkspaceOfAesEncrypt;
} Crypto_30_LibCv_AesEncryptType;

/**   \brief  type used in Crypto_30_LibCv_AesGcmDecrypt */
typedef struct sCrypto_30_LibCv_AesGcmDecryptType
{
  Crypto_30_LibCv_eslt_WorkSpaceGCM_PtrType WorkspaceOfAesGcmDecrypt;
} Crypto_30_LibCv_AesGcmDecryptType;

/**   \brief  type used in Crypto_30_LibCv_AesGcmEncrypt */
typedef struct sCrypto_30_LibCv_AesGcmEncryptType
{
  Crypto_30_LibCv_eslt_WorkSpaceGCM_PtrType WorkspaceOfAesGcmEncrypt;
} Crypto_30_LibCv_AesGcmEncryptType;

/**   \brief  type used in Crypto_30_LibCv_CmacAesGenerate */
typedef struct sCrypto_30_LibCv_CmacAesGenerateType
{
  Crypto_30_LibCv_Crypto_30_LibCv_WorkSpaceCMACAES_PtrType WorkspaceOfCmacAesGenerate;
} Crypto_30_LibCv_CmacAesGenerateType;

/**   \brief  type used in Crypto_30_LibCv_CmacAesVerify */
typedef struct sCrypto_30_LibCv_CmacAesVerifyType
{
  Crypto_30_LibCv_Crypto_30_LibCv_WorkSpaceCMACAES_PtrType WorkspaceOfCmacAesVerify;
} Crypto_30_LibCv_CmacAesVerifyType;

/**   \brief  type used in Crypto_30_LibCv_DRBGAES */
typedef struct sCrypto_30_LibCv_DRBGAESType
{
  Crypto_30_LibCv_eslt_WorkSpaceCTRDRBG_PtrType WorkspaceOfDRBGAES;
} Crypto_30_LibCv_DRBGAESType;

/**   \brief  type used in Crypto_30_LibCv_EcP256Generate */
typedef struct sCrypto_30_LibCv_EcP256GenerateType
{
  Crypto_30_LibCv_Crypto_30_LibCv_WorkSpaceEcP_PtrType WorkspaceOfEcP256Generate;
} Crypto_30_LibCv_EcP256GenerateType;

/**   \brief  type used in Crypto_30_LibCv_EcP256Verify */
typedef struct sCrypto_30_LibCv_EcP256VerifyType
{
  Crypto_30_LibCv_Crypto_30_LibCv_WorkSpaceEcP_PtrType WorkspaceOfEcP256Verify;
} Crypto_30_LibCv_EcP256VerifyType;

/**   \brief  type used in Crypto_30_LibCv_EcP521Generate */
typedef struct sCrypto_30_LibCv_EcP521GenerateType
{
  Crypto_30_LibCv_Crypto_30_LibCv_WorkSpaceEcP_PtrType WorkspaceOfEcP521Generate;
} Crypto_30_LibCv_EcP521GenerateType;

/**   \brief  type used in Crypto_30_LibCv_EcP521Verify */
typedef struct sCrypto_30_LibCv_EcP521VerifyType
{
  Crypto_30_LibCv_Crypto_30_LibCv_WorkSpaceEcP_PtrType WorkspaceOfEcP521Verify;
} Crypto_30_LibCv_EcP521VerifyType;

/**   \brief  type used in Crypto_30_LibCv_Ed25519Generate */
typedef struct sCrypto_30_LibCv_Ed25519GenerateType
{
  Crypto_30_LibCv_eslt_WorkSpaceEd25519_PtrType WorkspaceOfEd25519Generate;
} Crypto_30_LibCv_Ed25519GenerateType;

/**   \brief  type used in Crypto_30_LibCv_Ed25519Verify */
typedef struct sCrypto_30_LibCv_Ed25519VerifyType
{
  Crypto_30_LibCv_eslt_WorkSpaceEd25519_PtrType WorkspaceOfEd25519Verify;
} Crypto_30_LibCv_Ed25519VerifyType;

/**   \brief  type used in Crypto_30_LibCv_Fips186 */
typedef struct sCrypto_30_LibCv_Fips186Type
{
  Crypto_30_LibCv_eslt_WorkSpaceFIPS186_PtrType WorkspaceOfFips186;
} Crypto_30_LibCv_Fips186Type;

/**   \brief  type used in Crypto_30_LibCv_GmacAesGenerate */
typedef struct sCrypto_30_LibCv_GmacAesGenerateType
{
  Crypto_30_LibCv_eslt_WorkSpaceGMAC_PtrType WorkspaceOfGmacAesGenerate;
} Crypto_30_LibCv_GmacAesGenerateType;

/**   \brief  type used in Crypto_30_LibCv_GmacAesVerify */
typedef struct sCrypto_30_LibCv_GmacAesVerifyType
{
  Crypto_30_LibCv_eslt_WorkSpaceGMAC_PtrType WorkspaceOfGmacAesVerify;
} Crypto_30_LibCv_GmacAesVerifyType;

/**   \brief  type used in Crypto_30_LibCv_Hash */
typedef struct sCrypto_30_LibCv_HashType
{
  Crypto_30_LibCv_vSecPrimType_WorkSpaceHash_PtrType WorkspaceOfHash;
} Crypto_30_LibCv_HashType;

/**   \brief  type used in Crypto_30_LibCv_HmacSha1Generate */
typedef struct sCrypto_30_LibCv_HmacSha1GenerateType
{
  Crypto_30_LibCv_eslt_WorkSpaceHMACSHA1_PtrType WorkspaceOfHmacSha1Generate;
} Crypto_30_LibCv_HmacSha1GenerateType;

/**   \brief  type used in Crypto_30_LibCv_HmacSha1Verify */
typedef struct sCrypto_30_LibCv_HmacSha1VerifyType
{
  Crypto_30_LibCv_eslt_WorkSpaceHMACSHA1_PtrType WorkspaceOfHmacSha1Verify;
} Crypto_30_LibCv_HmacSha1VerifyType;

/**   \brief  type used in Crypto_30_LibCv_HmacSha256Generate */
typedef struct sCrypto_30_LibCv_HmacSha256GenerateType
{
  Crypto_30_LibCv_eslt_WorkSpaceHMACSHA256_PtrType WorkspaceOfHmacSha256Generate;
} Crypto_30_LibCv_HmacSha256GenerateType;

/**   \brief  type used in Crypto_30_LibCv_HmacSha256Verify */
typedef struct sCrypto_30_LibCv_HmacSha256VerifyType
{
  Crypto_30_LibCv_eslt_WorkSpaceHMACSHA256_PtrType WorkspaceOfHmacSha256Verify;
} Crypto_30_LibCv_HmacSha256VerifyType;

/**   \brief  type used in Crypto_30_LibCv_HmacSha384Generate */
typedef struct sCrypto_30_LibCv_HmacSha384GenerateType
{
  Crypto_30_LibCv_eslt_WorkSpaceHMACSHA384_PtrType WorkspaceOfHmacSha384Generate;
} Crypto_30_LibCv_HmacSha384GenerateType;

/**   \brief  type used in Crypto_30_LibCv_HmacSha384Verify */
typedef struct sCrypto_30_LibCv_HmacSha384VerifyType
{
  Crypto_30_LibCv_eslt_WorkSpaceHMACSHA384_PtrType WorkspaceOfHmacSha384Verify;
} Crypto_30_LibCv_HmacSha384VerifyType;

/**   \brief  type used in Crypto_30_LibCv_Key */
typedef struct sCrypto_30_LibCv_KeyType
{
  Crypto_30_LibCv_KeyElementsEndIdxOfKeyType KeyElementsEndIdxOfKey;  /**< the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyElements */
  Crypto_30_LibCv_KeyElementsStartIdxOfKeyType KeyElementsStartIdxOfKey;  /**< the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyElements */
  Crypto_30_LibCv_NvBlockIdxOfKeyType NvBlockIdxOfKey;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_NvBlock */
} Crypto_30_LibCv_KeyType;

/**   \brief  type used in Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256 */
typedef struct sCrypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256Type
{
  Crypto_30_LibCv_eslt_WorkSpaceHKDFHMAC_PtrType WorkspaceOfKeyDeriveHKDFExpandHMACSHA256;
} Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256Type;

/**   \brief  type used in Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384 */
typedef struct sCrypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384Type
{
  Crypto_30_LibCv_eslt_WorkSpaceHKDFHMAC_PtrType WorkspaceOfKeyDeriveHKDFExpandHMACSHA384;
} Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384Type;

/**   \brief  type used in Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256 */
typedef struct sCrypto_30_LibCv_KeyDeriveHKDFHMACSHA256Type
{
  Crypto_30_LibCv_eslt_WorkSpaceHKDFHMAC_PtrType WorkspaceOfKeyDeriveHKDFHMACSHA256;
} Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256Type;

/**   \brief  type used in Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384 */
typedef struct sCrypto_30_LibCv_KeyDeriveHKDFHMACSHA384Type
{
  Crypto_30_LibCv_eslt_WorkSpaceHKDFHMAC_PtrType WorkspaceOfKeyDeriveHKDFHMACSHA384;
} Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384Type;

/**   \brief  type used in Crypto_30_LibCv_KeyDeriveISO15118 */
typedef struct sCrypto_30_LibCv_KeyDeriveISO15118Type
{
  Crypto_30_LibCv_Crypto_30_LibCv_WorkSpaceISO15118_PtrType WorkspaceOfKeyDeriveISO15118;
} Crypto_30_LibCv_KeyDeriveISO15118Type;

/**   \brief  type used in Crypto_30_LibCv_KeyDeriveISO15118_20 */
typedef struct sCrypto_30_LibCv_KeyDeriveISO15118_20Type
{
  Crypto_30_LibCv_Crypto_30_LibCv_WorkSpaceISO15118_20_PtrType WorkspaceOfKeyDeriveISO15118_20;
} Crypto_30_LibCv_KeyDeriveISO15118_20Type;

/**   \brief  type used in Crypto_30_LibCv_KeyElementInfo */
typedef struct sCrypto_30_LibCv_KeyElementInfoType
{
  Crypto_30_LibCv_IdOfKeyElementInfoType IdOfKeyElementInfo;
  Crypto_30_LibCv_InitValueEndIdxOfKeyElementInfoType InitValueEndIdxOfKeyElementInfo;  /**< the end index of the 0:n relation pointing to Crypto_30_LibCv_InitValue */
  Crypto_30_LibCv_InitValueStartIdxOfKeyElementInfoType InitValueStartIdxOfKeyElementInfo;  /**< the start index of the 0:n relation pointing to Crypto_30_LibCv_InitValue */
  Crypto_30_LibCv_LengthOfKeyElementInfoType LengthOfKeyElementInfo;
  Crypto_30_LibCv_MaskedBitsOfKeyElementInfoType MaskedBitsOfKeyElementInfo;  /**< contains bitcoded the boolean data of Crypto_30_LibCv_OnceOfKeyElementInfo, Crypto_30_LibCv_PartialOfKeyElementInfo, Crypto_30_LibCv_PersistOfKeyElementInfo */
  Crypto_30_LibCv_ReadOfKeyElementInfoType ReadOfKeyElementInfo;
  Crypto_30_LibCv_WriteOfKeyElementInfoType WriteOfKeyElementInfo;
} Crypto_30_LibCv_KeyElementInfoType;

/**   \brief  type used in Crypto_30_LibCv_KeyElements */
typedef struct sCrypto_30_LibCv_KeyElementsType
{
  Crypto_30_LibCv_IdOfKeyElementsType IdOfKeyElements;
  Crypto_30_LibCv_KeyStorageEndIdxOfKeyElementsType KeyStorageEndIdxOfKeyElements;  /**< the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage */
  Crypto_30_LibCv_KeyStorageStartIdxOfKeyElementsType KeyStorageStartIdxOfKeyElements;  /**< the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage */
  Crypto_30_LibCv_KeyElementInfoIdxOfKeyElementsType KeyElementInfoIdxOfKeyElements;  /**< the index of the 1:1 relation pointing to Crypto_30_LibCv_KeyElementInfo */
} Crypto_30_LibCv_KeyElementsType;

/**   \brief  type used in Crypto_30_LibCv_KeyGenP256R1 */
typedef struct sCrypto_30_LibCv_KeyGenP256R1Type
{
  Crypto_30_LibCv_eslt_WorkSpaceEcP_PtrType WorkspaceOfKeyGenP256R1;
} Crypto_30_LibCv_KeyGenP256R1Type;

/**   \brief  type used in Crypto_30_LibCv_KeyP256R1Secret */
typedef struct sCrypto_30_LibCv_KeyP256R1SecretType
{
  Crypto_30_LibCv_eslt_WorkSpaceEcP_PtrType WorkspaceOfKeyP256R1Secret;
} Crypto_30_LibCv_KeyP256R1SecretType;

/**   \brief  type used in Crypto_30_LibCv_NvBlock */
typedef struct sCrypto_30_LibCv_NvBlockType
{
  Crypto_30_LibCv_CrcOfNvBlockType CrcOfNvBlock;  /**< Calculated CRC over layout of the block */
  Crypto_30_LibCv_DescriptorOfNvBlockType DescriptorOfNvBlock;  /**< Contains values of DefinitionRef: /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock/CryptoNvBlockDescriptor. */
  Crypto_30_LibCv_KeyStorageEndIdxOfNvBlockType KeyStorageEndIdxOfNvBlock;  /**< the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage */
  Crypto_30_LibCv_KeyStorageStartIdxOfNvBlockType KeyStorageStartIdxOfNvBlock;  /**< the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage */
  Crypto_30_LibCv_LengthOfNvBlockType LengthOfNvBlock;  /**< Contains values of DefinitionRef: /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock/CryptoNvBlockLength. */
  Crypto_30_LibCv_ConsistencyLevelOfNvBlockType ConsistencyLevelOfNvBlock;  /**< Contains values of DefinitionRef: /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock/CryptoNvBlockConsistencyLevel. */
  Crypto_30_LibCv_IdOfNvBlockType IdOfNvBlock;  /**< Contains values of DefinitionRef: /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock/CryptoNvBlockId. */
  Crypto_30_LibCv_ProcessingOfNvBlockType ProcessingOfNvBlock;  /**< Contains values of DefinitionRef: /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock/CryptoNvBlockProcessing. */
} Crypto_30_LibCv_NvBlockType;

/**   \brief  type used in Crypto_30_LibCv_ObjectInfo */
typedef struct sCrypto_30_LibCv_ObjectInfoType
{
  Crypto_30_LibCv_WorkspaceLengthOfObjectInfoType WorkspaceLengthOfObjectInfo;  /**< Holds the length of the workspace. */
  Crypto_30_LibCv_AEADChaChaPoly1305DecryptIdxOfObjectInfoType AEADChaChaPoly1305DecryptIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_AEADChaChaPoly1305Decrypt */
  Crypto_30_LibCv_AEADChaChaPoly1305EncryptIdxOfObjectInfoType AEADChaChaPoly1305EncryptIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_AEADChaChaPoly1305Encrypt */
  Crypto_30_LibCv_AesDecryptIdxOfObjectInfoType AesDecryptIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_AesDecrypt */
  Crypto_30_LibCv_AesEncryptIdxOfObjectInfoType AesEncryptIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_AesEncrypt */
  Crypto_30_LibCv_AesGcmDecryptIdxOfObjectInfoType AesGcmDecryptIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_AesGcmDecrypt */
  Crypto_30_LibCv_AesGcmEncryptIdxOfObjectInfoType AesGcmEncryptIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_AesGcmEncrypt */
  Crypto_30_LibCv_CmacAesGenerateIdxOfObjectInfoType CmacAesGenerateIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_CmacAesGenerate */
  Crypto_30_LibCv_CmacAesVerifyIdxOfObjectInfoType CmacAesVerifyIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_CmacAesVerify */
  Crypto_30_LibCv_DRBGAESIdxOfObjectInfoType DRBGAESIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_DRBGAES */
  Crypto_30_LibCv_EcP256GenerateIdxOfObjectInfoType EcP256GenerateIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_EcP256Generate */
  Crypto_30_LibCv_EcP256VerifyIdxOfObjectInfoType EcP256VerifyIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_EcP256Verify */
  Crypto_30_LibCv_EcP521GenerateIdxOfObjectInfoType EcP521GenerateIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_EcP521Generate */
  Crypto_30_LibCv_EcP521VerifyIdxOfObjectInfoType EcP521VerifyIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_EcP521Verify */
  Crypto_30_LibCv_Ed25519GenerateIdxOfObjectInfoType Ed25519GenerateIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_Ed25519Generate */
  Crypto_30_LibCv_Ed25519VerifyIdxOfObjectInfoType Ed25519VerifyIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_Ed25519Verify */
  Crypto_30_LibCv_Fips186IdxOfObjectInfoType Fips186IdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_Fips186 */
  Crypto_30_LibCv_GmacAesGenerateIdxOfObjectInfoType GmacAesGenerateIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_GmacAesGenerate */
  Crypto_30_LibCv_GmacAesVerifyIdxOfObjectInfoType GmacAesVerifyIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_GmacAesVerify */
  Crypto_30_LibCv_HashIdxOfObjectInfoType HashIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_Hash */
  Crypto_30_LibCv_HmacSha1GenerateIdxOfObjectInfoType HmacSha1GenerateIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_HmacSha1Generate */
  Crypto_30_LibCv_HmacSha1VerifyIdxOfObjectInfoType HmacSha1VerifyIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_HmacSha1Verify */
  Crypto_30_LibCv_HmacSha256GenerateIdxOfObjectInfoType HmacSha256GenerateIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_HmacSha256Generate */
  Crypto_30_LibCv_HmacSha256VerifyIdxOfObjectInfoType HmacSha256VerifyIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_HmacSha256Verify */
  Crypto_30_LibCv_HmacSha384GenerateIdxOfObjectInfoType HmacSha384GenerateIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_HmacSha384Generate */
  Crypto_30_LibCv_HmacSha384VerifyIdxOfObjectInfoType HmacSha384VerifyIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_HmacSha384Verify */
  Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256IdxOfObjectInfoType KeyDeriveHKDFExpandHMACSHA256IdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256 */
  Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384IdxOfObjectInfoType KeyDeriveHKDFExpandHMACSHA384IdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384 */
  Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256IdxOfObjectInfoType KeyDeriveHKDFHMACSHA256IdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256 */
  Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384IdxOfObjectInfoType KeyDeriveHKDFHMACSHA384IdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384 */
  Crypto_30_LibCv_KeyDeriveISO15118IdxOfObjectInfoType KeyDeriveISO15118IdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyDeriveISO15118 */
  Crypto_30_LibCv_KeyDeriveISO15118_20IdxOfObjectInfoType KeyDeriveISO15118_20IdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyDeriveISO15118_20 */
  Crypto_30_LibCv_KeyGenP256R1IdxOfObjectInfoType KeyGenP256R1IdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyGenP256R1 */
  Crypto_30_LibCv_KeyP256R1SecretIdxOfObjectInfoType KeyP256R1SecretIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyP256R1Secret */
  Crypto_30_LibCv_QueueIdxOfObjectInfoType QueueIdxOfObjectInfo;  /**< the index of the 1:1 relation pointing to Crypto_30_LibCv_Queue */
  Crypto_30_LibCv_RandomSeedBufferEndIdxOfObjectInfoType RandomSeedBufferEndIdxOfObjectInfo;  /**< the end index of the 0:n relation pointing to Crypto_30_LibCv_RandomSeedBuffer */
  Crypto_30_LibCv_RandomSeedBufferStartIdxOfObjectInfoType RandomSeedBufferStartIdxOfObjectInfo;  /**< the start index of the 0:n relation pointing to Crypto_30_LibCv_RandomSeedBuffer */
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT)  WorkspaceAddrOfObjectInfo;  /**< Holds the address of the workspace. */
} Crypto_30_LibCv_ObjectInfoType;

/**   \brief  type used in Crypto_30_LibCv_PartitionIdentifiers */
typedef struct sCrypto_30_LibCv_PartitionIdentifiersType
{
  Crypto_30_LibCv_PartitionSNVOfPartitionIdentifiersType PartitionSNVOfPartitionIdentifiers;
  Crypto_30_LibCv_PCPartitionConfigIdxOfPartitionIdentifiersType PCPartitionConfigIdxOfPartitionIdentifiers;  /**< the index of the 1:1 relation pointing to Crypto_30_LibCv_PCPartitionConfig */
} Crypto_30_LibCv_PartitionIdentifiersType;

/**   \brief  type used in Crypto_30_LibCv_PartitionInfo */
typedef struct sCrypto_30_LibCv_PartitionInfoType
{
  Crypto_30_LibCv_DefaultRandomKeyOfPartitionInfoType DefaultRandomKeyOfPartitionInfo;  /**< Holds default random key ref */
  Crypto_30_LibCv_MaskedBitsOfPartitionInfoType MaskedBitsOfPartitionInfo;  /**< contains bitcoded the boolean data of Crypto_30_LibCv_AesOfPartitionInfo, Crypto_30_LibCv_HashOfPartitionInfo */
} Crypto_30_LibCv_PartitionInfoType;

/**   \brief  type used in Crypto_30_LibCv_PrimitiveFct */
typedef struct sCrypto_30_LibCv_PrimitiveFctType
{
  Crypto_30_LibCv_ObjectInfoIndEndIdxOfPrimitiveFctType ObjectInfoIndEndIdxOfPrimitiveFct;  /**< the end index of the 0:n relation pointing to Crypto_30_LibCv_ObjectInfoInd */
  Crypto_30_LibCv_ObjectInfoIndStartIdxOfPrimitiveFctType ObjectInfoIndStartIdxOfPrimitiveFct;  /**< the start index of the 0:n relation pointing to Crypto_30_LibCv_ObjectInfoInd */
  Crypto_30_LibCv_DispatchFctPtrType DispatchOfPrimitiveFct;
} Crypto_30_LibCv_PrimitiveFctType;

/**   \brief  type used in Crypto_30_LibCv_PrimitiveInfo */
typedef struct sCrypto_30_LibCv_PrimitiveInfoType
{
  Crypto_30_LibCv_CombinedOfPrimitiveInfoType CombinedOfPrimitiveInfo;
  Crypto_30_LibCv_MaskedBitsOfPrimitiveInfoType MaskedBitsOfPrimitiveInfo;  /**< contains bitcoded the boolean data of Crypto_30_LibCv_ContextOfPrimitiveInfo, Crypto_30_LibCv_DefaultRandomSourceOfPrimitiveInfo */
  Crypto_30_LibCv_PrimitiveFctIdxOfPrimitiveInfoType PrimitiveFctIdxOfPrimitiveInfo;  /**< the index of the 1:1 relation pointing to Crypto_30_LibCv_PrimitiveFct */
} Crypto_30_LibCv_PrimitiveInfoType;

/**   \brief  type used in Crypto_30_LibCv_PrimitiveServiceInfo */
typedef struct sCrypto_30_LibCv_PrimitiveServiceInfoType
{
  Crypto_30_LibCv_PrimitiveInfoEndIdxOfPrimitiveServiceInfoType PrimitiveInfoEndIdxOfPrimitiveServiceInfo;  /**< the end index of the 0:n relation pointing to Crypto_30_LibCv_PrimitiveInfo */
  Crypto_30_LibCv_PrimitiveInfoStartIdxOfPrimitiveServiceInfoType PrimitiveInfoStartIdxOfPrimitiveServiceInfo;  /**< the start index of the 0:n relation pointing to Crypto_30_LibCv_PrimitiveInfo */
} Crypto_30_LibCv_PrimitiveServiceInfoType;

/**   \brief  type used in Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0 */
typedef struct sCrypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0Type
{
  Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn0_Type DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0;  /**< Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0. */
} Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0Type;

/**   \brief  type used in Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished */
typedef struct sCrypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_FinishedType
{
  Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished_Type DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished;  /**< Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished. */
} Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_FinishedType;

/**   \brief  type used in Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1 */
typedef struct sCrypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1Type
{
  Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn1_Type DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1;  /**< Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1. */
} Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1Type;

/**   \brief  type used in Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished */
typedef struct sCrypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_FinishedType
{
  Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished_Type DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished;  /**< Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished. */
} Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_FinishedType;

/**   \brief  type used in Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384 */
typedef struct sCrypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384Type
{
  Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn1_HS_HashSha384_Type DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384;  /**< Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha384. */
} Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384Type;

/**   \brief  type used in Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384 */
typedef struct sCrypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384Type
{
  Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384_Type DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384;  /**< Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_Hkdf_Sha384. */
} Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384Type;

/**   \brief  type used in Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1 */
typedef struct sCrypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1Type
{
  Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Global_HashSha1_Type DataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1;  /**< Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Global_HashSha1. */
} Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1Type;

/**   \brief  type used in Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv */
typedef struct sCrypto_30_LibCv_StructUnionWS_Crypto_30_LibCvType
{
  Crypto_30_LibCv_WS_Crypto_30_LibCv_Type DataOfStructUnionWS_Crypto_30_LibCv;  /**< Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv. */
} Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCvType;

/**   \brief  type used in Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General */
typedef struct sCrypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_GeneralType
{
  Crypto_30_LibCv_WS_Crypto_30_LibCv_General_Type DataOfStructUnionWS_Crypto_30_LibCv_General;  /**< Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General. */
} Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_GeneralType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCSymbolicStructTypes  Crypto_30_LibCv Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to Crypto_30_LibCv_KeyLock in the partition context  */
typedef struct Crypto_30_LibCv_KeyLockStructSTag
{
  Crypto_30_LibCv_KeyLockType Crypto_SccContractPrivKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PrivateKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_V2GRoot_Y_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyLockType Crypto_TlsSha1Key;
  Crypto_30_LibCv_KeyLockType Crypto_SccPublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn0_CertVerify_PubKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_V2GRoot_X_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn0_HMacShaX_Generate;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PrivateKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn0_HMacShaX_Verify;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn0_HS_HashSha256_ToClientFinished;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn0_HS_HashSha256_ToServerFinished;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn0_HS_RandomNumber;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn0_MasterSecret;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn0_PreMasterSecretInfo;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn0_Prf_ResultPrivate;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn0_Prf_ResultPublic;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn0_Prf_Secret;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn0_PrfCalculationValuesPublic;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn0_TmpBuffer;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Global_HashSha1;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_TlsConn0_HS_DhKeyExchange;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_TlsConn0_HS_DhSignatureGenerate;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn1_MasterSecret;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn1_Prf_ResultPrivate;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn1_Prf_ResultPublic;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Hkdf_Sha384ExpandIn;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Hkdf_Sha384ExpandOut;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn1_Prf_Secret_Secp521;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn1_PrfCalculationValuesPublic;
  Crypto_30_LibCv_KeyLockType CryptoKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn1_TmpBuffer;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Leaf_Server_A_EccSecp521r1Sha512_PubKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_RandomGenerator;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_RootA_EccSecp256r1Sha256_PubKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn1_HS_HashSha256_Finished;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_KDF;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_KDF_1;
  Crypto_30_LibCv_KeyLockType CryptoKey_DefaultRandomSource;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_MOContract_X_PrivateKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_OEMProv_X_PrivateKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn0_HS_HashSha256_Finished;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_MOSubCa2_X_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_MOSubCa1_X_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_MOContract_X_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_OEMProv_X_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_OEMProvSubCa2;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_OEMProvSubCa1;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_OEMProvRoot;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Hkdf_DerivedSecret;
  Crypto_30_LibCv_KeyLockType CryptoKey_Hkdf_Sha256;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_MORoot_X_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ProvLeaf_X_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ProvSubCa1_X_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ProvSubCa2_X_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ResumeSessionInfo;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Hkdf_TmpBuffer;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_SHA512;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_V2GRoot_X_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_V2GRoot_Y_PublicKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_V2G_Root_1_PubKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_V2G_Root_2_PubKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Hkdf_Sha384;
  Crypto_30_LibCv_KeyLockType CryptoKey_V2G_Root_3_PubKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_V2G_Root_4_PubKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn1_Aes256GcmEncrypt;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_HMacSha384Generate;
  Crypto_30_LibCv_KeyLockType CryptoKey_V2G_Root_5_PubKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Hkdf_Sha256ExpandIn;
  Crypto_30_LibCv_KeyLockType CryptoKey_V2G_Root_6_PubKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_V2G_Root_7_PubKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_V2G_Root_8_PubKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_V2G_Root_9_PubKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_HmacSha256Generate_1;
  Crypto_30_LibCv_KeyLockType CryptoKey_V2G_Root_10_PubKey;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn1_Aes256GcmDecrypt;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn0_HS_DhKeyExchange;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Hkdf_Sha256ExpandOut;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_ChaCha20_Decrypt;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_ChaCha20_PassiveDecrypt;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_ChaCha20_Encrypt;
  Crypto_30_LibCv_KeyLockType CryptoKey_Tls_ChaCha20_PassiveEncrypt;
  Crypto_30_LibCv_KeyLockType Tls_Conn1_HS_HashSha384_Finished;
  Crypto_30_LibCv_KeyLockType CryptoKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1;
  Crypto_30_LibCv_KeyLockType CryptoKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey;
} Crypto_30_LibCv_KeyLockStructSType;

/**   \brief  type to be used as symbolic data element access to Crypto_30_LibCv_KeyNvStatus in the partition context  */
typedef struct Crypto_30_LibCv_KeyNvStatusStructSTag
{
  Crypto_30_LibCv_KeyNvStatusType Crypto_SccContractPrivKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PrivateKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_V2GRoot_Y_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType Crypto_TlsSha1Key;
  Crypto_30_LibCv_KeyNvStatusType Crypto_SccPublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn0_CertVerify_PubKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_V2GRoot_X_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn0_HMacShaX_Generate;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PrivateKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn0_HMacShaX_Verify;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn0_HS_HashSha256_ToClientFinished;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn0_HS_HashSha256_ToServerFinished;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn0_HS_RandomNumber;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn0_MasterSecret;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn0_PreMasterSecretInfo;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn0_Prf_ResultPrivate;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn0_Prf_ResultPublic;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn0_Prf_Secret;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn0_PrfCalculationValuesPublic;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn0_TmpBuffer;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Global_HashSha1;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_TlsConn0_HS_DhKeyExchange;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_TlsConn0_HS_DhSignatureGenerate;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn1_MasterSecret;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn1_Prf_ResultPrivate;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn1_Prf_ResultPublic;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Hkdf_Sha384ExpandIn;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Hkdf_Sha384ExpandOut;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn1_Prf_Secret_Secp521;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn1_PrfCalculationValuesPublic;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn1_TmpBuffer;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Leaf_Server_A_EccSecp521r1Sha512_PubKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_RandomGenerator;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_RootA_EccSecp256r1Sha256_PubKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn1_HS_HashSha256_Finished;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_KDF;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_KDF_1;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_DefaultRandomSource;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_MOContract_X_PrivateKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_OEMProv_X_PrivateKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn0_HS_HashSha256_Finished;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_MOSubCa2_X_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_MOSubCa1_X_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_MOContract_X_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_OEMProv_X_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_OEMProvSubCa2;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_OEMProvSubCa1;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_OEMProvRoot;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Hkdf_DerivedSecret;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Hkdf_Sha256;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_MORoot_X_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ProvLeaf_X_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ProvSubCa1_X_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ProvSubCa2_X_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ResumeSessionInfo;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Hkdf_TmpBuffer;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_SHA512;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_V2GRoot_X_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_V2GRoot_Y_PublicKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_V2G_Root_1_PubKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_V2G_Root_2_PubKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Hkdf_Sha384;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_V2G_Root_3_PubKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_V2G_Root_4_PubKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn1_Aes256GcmEncrypt;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_HMacSha384Generate;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_V2G_Root_5_PubKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Hkdf_Sha256ExpandIn;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_V2G_Root_6_PubKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_V2G_Root_7_PubKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_V2G_Root_8_PubKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_V2G_Root_9_PubKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_HmacSha256Generate_1;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_V2G_Root_10_PubKey;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn1_Aes256GcmDecrypt;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn0_HS_DhKeyExchange;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Hkdf_Sha256ExpandOut;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_ChaCha20_Decrypt;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_ChaCha20_PassiveDecrypt;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_ChaCha20_Encrypt;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Tls_ChaCha20_PassiveEncrypt;
  Crypto_30_LibCv_KeyNvStatusType Tls_Conn1_HS_HashSha384_Finished;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1;
  Crypto_30_LibCv_KeyNvStatusType CryptoKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey;
} Crypto_30_LibCv_KeyNvStatusStructSType;

/**   \brief  type to be used as symbolic data element access to Crypto_30_LibCv_Queue in the partition context  */
typedef struct Crypto_30_LibCv_QueueStructSTag
{
  Crypto_30_LibCv_JobPtrType CryptoDriverObject_Tls_Conn0;
  Crypto_30_LibCv_JobPtrType CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished;
  Crypto_30_LibCv_JobPtrType CryptoDriverObject_Tls_Conn1;
  Crypto_30_LibCv_JobPtrType CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished;
  Crypto_30_LibCv_JobPtrType CryptoDriverObject_Tls_Conn1_HS_HashSha384;
  Crypto_30_LibCv_JobPtrType CryptoDriverObject_Tls_Conn1_Hkdf_Sha384;
  Crypto_30_LibCv_JobPtrType CryptoDriverObject_Tls_Global_HashSha1;
  Crypto_30_LibCv_JobPtrType Crypto_30_LibCv;
  Crypto_30_LibCv_JobPtrType Crypto_30_LibCv_General;
} Crypto_30_LibCv_QueueStructSType;

/**   \brief  type to be used as symbolic data element access to Crypto_30_LibCv_RandomSeedBuffer in the partition context  */
typedef struct Crypto_30_LibCv_RandomSeedBufferStructSTag
{
  Crypto_30_LibCv_RandomSeedBufferType CryptoDriverObject_Tls_Conn0[21];
  Crypto_30_LibCv_RandomSeedBufferType CryptoDriverObject_Tls_Conn1[21];
} Crypto_30_LibCv_RandomSeedBufferStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCUnionIndexAndSymbolTypes  Crypto_30_LibCv Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access Crypto_30_LibCv_KeyLock in an index and symbol based style. */
typedef union Crypto_30_LibCv_KeyLockUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_LibCv_KeyLockType raw[119];
  Crypto_30_LibCv_KeyLockStructSType str;
} Crypto_30_LibCv_KeyLockUType;

/**   \brief  type to access Crypto_30_LibCv_KeyNvStatus in an index and symbol based style. */
typedef union Crypto_30_LibCv_KeyNvStatusUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_LibCv_KeyNvStatusType raw[119];
  Crypto_30_LibCv_KeyNvStatusStructSType str;
} Crypto_30_LibCv_KeyNvStatusUType;

/**   \brief  type to access Crypto_30_LibCv_Queue in an index and symbol based style. */
typedef union Crypto_30_LibCv_QueueUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_LibCv_JobPtrType raw[9];
  Crypto_30_LibCv_QueueStructSType str;
} Crypto_30_LibCv_QueueUType;

/**   \brief  type to access Crypto_30_LibCv_RandomSeedBuffer in an index and symbol based style. */
typedef union Crypto_30_LibCv_RandomSeedBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_LibCv_RandomSeedBufferType raw[42];
  Crypto_30_LibCv_RandomSeedBufferStructSType str;
} Crypto_30_LibCv_RandomSeedBufferUType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCRootPointerTypes  Crypto_30_LibCv Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Crypto_30_LibCv_AEADChaChaPoly1305Decrypt */
typedef P2CONST(Crypto_30_LibCv_AEADChaChaPoly1305DecryptType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AEADChaChaPoly1305DecryptPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_AEADChaChaPoly1305Encrypt */
typedef P2CONST(Crypto_30_LibCv_AEADChaChaPoly1305EncryptType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AEADChaChaPoly1305EncryptPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_AesDecrypt */
typedef P2CONST(Crypto_30_LibCv_AesDecryptType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AesDecryptPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_AesEncrypt */
typedef P2CONST(Crypto_30_LibCv_AesEncryptType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AesEncryptPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_AesGcmDecrypt */
typedef P2CONST(Crypto_30_LibCv_AesGcmDecryptType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AesGcmDecryptPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_AesGcmEncrypt */
typedef P2CONST(Crypto_30_LibCv_AesGcmEncryptType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AesGcmEncryptPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_BufferLength */
typedef P2VAR(Crypto_30_LibCv_BufferLengthType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_BufferLengthPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_CmacAesGenerate */
typedef P2CONST(Crypto_30_LibCv_CmacAesGenerateType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_CmacAesGeneratePtrType;

/**   \brief  type used to point to Crypto_30_LibCv_CmacAesVerify */
typedef P2CONST(Crypto_30_LibCv_CmacAesVerifyType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_CmacAesVerifyPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_DRBGAES */
typedef P2CONST(Crypto_30_LibCv_DRBGAESType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_DRBGAESPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_Dispatch_QueuePrimitiveInfoIdx */
typedef P2VAR(Crypto_30_LibCv_SizeOfPrimitiveInfoType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Dispatch_QueuePrimitiveInfoIdxPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_DriverObjectState */
typedef P2VAR(Crypto_30_LibCv_DriverObjectStateType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_DriverObjectStatePtrType;

/**   \brief  type used to point to Crypto_30_LibCv_EcP256Generate */
typedef P2CONST(Crypto_30_LibCv_EcP256GenerateType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_EcP256GeneratePtrType;

/**   \brief  type used to point to Crypto_30_LibCv_EcP256Verify */
typedef P2CONST(Crypto_30_LibCv_EcP256VerifyType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_EcP256VerifyPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_EcP521Generate */
typedef P2CONST(Crypto_30_LibCv_EcP521GenerateType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_EcP521GeneratePtrType;

/**   \brief  type used to point to Crypto_30_LibCv_EcP521Verify */
typedef P2CONST(Crypto_30_LibCv_EcP521VerifyType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_EcP521VerifyPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_Ed25519Generate */
typedef P2CONST(Crypto_30_LibCv_Ed25519GenerateType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Ed25519GeneratePtrType;

/**   \brief  type used to point to Crypto_30_LibCv_Ed25519Verify */
typedef P2CONST(Crypto_30_LibCv_Ed25519VerifyType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Ed25519VerifyPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_FamilyToHashMapping */
typedef P2CONST(Crypto_30_LibCv_FamilyToHashMappingType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_FamilyToHashMappingPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_Fips186 */
typedef P2CONST(Crypto_30_LibCv_Fips186Type, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Fips186PtrType;

/**   \brief  type used to point to Crypto_30_LibCv_GmacAesGenerate */
typedef P2CONST(Crypto_30_LibCv_GmacAesGenerateType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_GmacAesGeneratePtrType;

/**   \brief  type used to point to Crypto_30_LibCv_GmacAesVerify */
typedef P2CONST(Crypto_30_LibCv_GmacAesVerifyType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_GmacAesVerifyPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_Hash */
typedef P2CONST(Crypto_30_LibCv_HashType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_HashPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_HmacSha1Generate */
typedef P2CONST(Crypto_30_LibCv_HmacSha1GenerateType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_HmacSha1GeneratePtrType;

/**   \brief  type used to point to Crypto_30_LibCv_HmacSha1Verify */
typedef P2CONST(Crypto_30_LibCv_HmacSha1VerifyType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_HmacSha1VerifyPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_HmacSha256Generate */
typedef P2CONST(Crypto_30_LibCv_HmacSha256GenerateType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_HmacSha256GeneratePtrType;

/**   \brief  type used to point to Crypto_30_LibCv_HmacSha256Verify */
typedef P2CONST(Crypto_30_LibCv_HmacSha256VerifyType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_HmacSha256VerifyPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_HmacSha384Generate */
typedef P2CONST(Crypto_30_LibCv_HmacSha384GenerateType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_HmacSha384GeneratePtrType;

/**   \brief  type used to point to Crypto_30_LibCv_HmacSha384Verify */
typedef P2CONST(Crypto_30_LibCv_HmacSha384VerifyType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_HmacSha384VerifyPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_InitValue */
typedef P2CONST(Crypto_30_LibCv_InitValueType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_InitValuePtrType;

/**   \brief  type used to point to Crypto_30_LibCv_Key */
typedef P2CONST(Crypto_30_LibCv_KeyType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256 */
typedef P2CONST(Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256Type, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256PtrType;

/**   \brief  type used to point to Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384 */
typedef P2CONST(Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384Type, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384PtrType;

/**   \brief  type used to point to Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256 */
typedef P2CONST(Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256Type, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256PtrType;

/**   \brief  type used to point to Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384 */
typedef P2CONST(Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384Type, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384PtrType;

/**   \brief  type used to point to Crypto_30_LibCv_KeyDeriveISO15118 */
typedef P2CONST(Crypto_30_LibCv_KeyDeriveISO15118Type, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyDeriveISO15118PtrType;

/**   \brief  type used to point to Crypto_30_LibCv_KeyDeriveISO15118_20 */
typedef P2CONST(Crypto_30_LibCv_KeyDeriveISO15118_20Type, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyDeriveISO15118_20PtrType;

/**   \brief  type used to point to Crypto_30_LibCv_KeyElementInfo */
typedef P2CONST(Crypto_30_LibCv_KeyElementInfoType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyElementInfoPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_KeyElements */
typedef P2CONST(Crypto_30_LibCv_KeyElementsType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyElementsPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_KeyGenP256R1 */
typedef P2CONST(Crypto_30_LibCv_KeyGenP256R1Type, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyGenP256R1PtrType;

/**   \brief  type used to point to Crypto_30_LibCv_KeyLock */
typedef P2VAR(Crypto_30_LibCv_KeyLockType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_KeyLockPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_KeyNvStatus */
typedef P2VAR(Crypto_30_LibCv_KeyNvStatusType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_KeyNvStatusPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_KeyP256R1Secret */
typedef P2CONST(Crypto_30_LibCv_KeyP256R1SecretType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyP256R1SecretPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_KeyStorage */
typedef P2VAR(Crypto_30_LibCv_KeyStorageType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_KeyStoragePtrType;

/**   \brief  type used to point to Crypto_30_LibCv_Lock */
typedef P2VAR(Crypto_30_LibCv_LockType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_LockPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_NvBlock */
typedef P2CONST(Crypto_30_LibCv_NvBlockType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_NvBlockPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_ObjectInfo */
typedef P2CONST(Crypto_30_LibCv_ObjectInfoType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_ObjectInfoPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_ObjectInfoInd */
typedef P2CONST(Crypto_30_LibCv_ObjectInfoIndType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_ObjectInfoIndPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_PartitionIdentifiers */
typedef P2CONST(Crypto_30_LibCv_PartitionIdentifiersType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PartitionIdentifiersPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_PartitionInfo */
typedef P2CONST(Crypto_30_LibCv_PartitionInfoType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PartitionInfoPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_PartitionInitialized */
typedef P2VAR(Crypto_30_LibCv_PartitionInitializedType, TYPEDEF, CRYPTO_30_LIBCV_VAR_ZERO_INIT) Crypto_30_LibCv_PartitionInitializedPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_PrimitiveFct */
typedef P2CONST(Crypto_30_LibCv_PrimitiveFctType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveFctPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_PrimitiveInfo */
typedef P2CONST(Crypto_30_LibCv_PrimitiveInfoType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveInfoPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_PrimitiveServiceInfo */
typedef P2CONST(Crypto_30_LibCv_PrimitiveServiceInfoType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveServiceInfoPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_ProcessJob_Trigger_Write */
typedef P2VAR(Crypto_30_LibCv_ProcessJob_Trigger_WriteType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_ProcessJob_Trigger_WritePtrType;

/**   \brief  type used to point to Crypto_30_LibCv_Queue */
typedef P2VAR(Crypto_30_LibCv_JobPtrType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_QueuePtrType;

/**   \brief  type used to point to Crypto_30_LibCv_RandomSeedBuffer */
typedef P2VAR(Crypto_30_LibCv_RandomSeedBufferType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_RandomSeedBufferPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_RandomSourceGenerateCount */
typedef P2VAR(Crypto_30_LibCv_RandomSourceGenerateCountType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_RandomSourceGenerateCountPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_Redirect_Buffer */
typedef P2VAR(Crypto_30_LibCv_Redirect_Type, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Redirect_BufferPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0 */
typedef P2VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0Type, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0PtrType;

/**   \brief  type used to point to Crypto_30_LibCv_DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0 */
typedef P2VAR(Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn0_Type, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0PtrType;

/**   \brief  type used to point to Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished */
typedef P2VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_FinishedType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_FinishedPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished */
typedef P2VAR(Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished_Type, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_FinishedPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1 */
typedef P2VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1Type, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1PtrType;

/**   \brief  type used to point to Crypto_30_LibCv_DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1 */
typedef P2VAR(Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn1_Type, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1PtrType;

/**   \brief  type used to point to Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished */
typedef P2VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_FinishedType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_FinishedPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished */
typedef P2VAR(Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished_Type, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_FinishedPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384 */
typedef P2VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384Type, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384PtrType;

/**   \brief  type used to point to Crypto_30_LibCv_DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384 */
typedef P2VAR(Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn1_HS_HashSha384_Type, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384PtrType;

/**   \brief  type used to point to Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384 */
typedef P2VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384Type, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384PtrType;

/**   \brief  type used to point to Crypto_30_LibCv_DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384 */
typedef P2VAR(Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384_Type, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384PtrType;

/**   \brief  type used to point to Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1 */
typedef P2VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1Type, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1PtrType;

/**   \brief  type used to point to Crypto_30_LibCv_DataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1 */
typedef P2VAR(Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Global_HashSha1_Type, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_DataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1PtrType;

/**   \brief  type used to point to Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv */
typedef P2VAR(Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCvType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCvPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_DataOfStructUnionWS_Crypto_30_LibCv */
typedef P2VAR(Crypto_30_LibCv_WS_Crypto_30_LibCv_Type, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_DataOfStructUnionWS_Crypto_30_LibCvPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General */
typedef P2VAR(Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_GeneralType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_GeneralPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_DataOfStructUnionWS_Crypto_30_LibCv_General */
typedef P2VAR(Crypto_30_LibCv_WS_Crypto_30_LibCv_General_Type, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_DataOfStructUnionWS_Crypto_30_LibCv_GeneralPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_WrittenLength */
typedef P2VAR(Crypto_30_LibCv_WrittenLengthType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_WrittenLengthPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCPartitionRootPointer  Crypto_30_LibCv Partition Root Pointer (PRE_COMPILE)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/**   \brief  type used in Crypto_30_LibCv_PCPartitionConfig */
typedef struct sCrypto_30_LibCv_PCPartitionConfigType
{
  uint8 Crypto_30_LibCv_PCPartitionConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Crypto_30_LibCv_PCPartitionConfigType;

/**   \brief  type used to point to Crypto_30_LibCv_PCPartitionConfig */
typedef P2CONST(Crypto_30_LibCv_PCPartitionConfigType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PCPartitionConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCRootValueTypes  Crypto_30_LibCv Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Crypto_30_LibCv_PCConfig */
typedef struct sCrypto_30_LibCv_PCConfigType
{
  uint8 Crypto_30_LibCv_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Crypto_30_LibCv_PCConfigType;

typedef Crypto_30_LibCv_PCConfigType Crypto_30_LibCv_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_LibCvPBIterableTypes  Crypto_30_LibCv Iterable Types (POST_BUILD)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPBValueTypes  Crypto_30_LibCv Value Types (POST_BUILD)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_LibCvPBPartitionRootPointer  Crypto_30_LibCv Partition Root Pointer (POST_BUILD)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPBRootValueTypes  Crypto_30_LibCv Root Value Types (POST_BUILD)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  Crypto_30_LibCv_AEADChaChaPoly1305Decrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_AEADChaChaPoly1305Decrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_AEADChaChaPoly1305DecryptType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AEADChaChaPoly1305Decrypt[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_AEADChaChaPoly1305Encrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_AEADChaChaPoly1305Encrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_AEADChaChaPoly1305EncryptType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AEADChaChaPoly1305Encrypt[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_AesDecrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_AesDecrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_AesDecryptType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AesDecrypt[3];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_AesEncrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_AesEncrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_AesEncryptType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AesEncrypt[3];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_AesGcmDecrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_AesGcmDecrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_AesGcmDecryptType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AesGcmDecrypt[1];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_AesGcmEncrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_AesGcmEncrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_AesGcmEncryptType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AesGcmEncrypt[1];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_CmacAesGenerate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_CmacAesGenerate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_CmacAesGenerateType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_CmacAesGenerate[2];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_CmacAesVerify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_CmacAesVerify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_CmacAesVerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_CmacAesVerify[2];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_DRBGAES
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_DRBGAES
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_DRBGAESType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_DRBGAES[2];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_EcP256Generate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_EcP256Generate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_EcP256GenerateType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_EcP256Generate[4];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_EcP256Verify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_EcP256Verify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_EcP256VerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_EcP256Verify[4];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_EcP521Generate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_EcP521Generate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_EcP521GenerateType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_EcP521Generate[4];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_EcP521Verify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_EcP521Verify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_EcP521VerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_EcP521Verify[4];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Ed25519Generate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Ed25519Generate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_Ed25519GenerateType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Ed25519Generate[1];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Ed25519Verify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Ed25519Verify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_Ed25519VerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Ed25519Verify[1];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_FamilyToHashMapping
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_FamilyToHashMappingType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_FamilyToHashMapping[8];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Fips186
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Fips186
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_Fips186Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Fips186[2];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_GmacAesGenerate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_GmacAesGenerate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_GmacAesGenerateType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_GmacAesGenerate[2];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_GmacAesVerify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_GmacAesVerify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_GmacAesVerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_GmacAesVerify[2];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Hash
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Hash
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_HashType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Hash[8];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_HmacSha1Generate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_HmacSha1Generate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_HmacSha1GenerateType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_HmacSha1Generate[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_HmacSha1Verify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_HmacSha1Verify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_HmacSha1VerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_HmacSha1Verify[3];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_HmacSha256Generate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_HmacSha256Generate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_HmacSha256GenerateType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_HmacSha256Generate[4];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_HmacSha256Verify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_HmacSha256Verify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_HmacSha256VerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_HmacSha256Verify[4];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_HmacSha384Generate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_HmacSha384Generate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_HmacSha384GenerateType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_HmacSha384Generate[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_HmacSha384Verify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_HmacSha384Verify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_HmacSha384VerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_HmacSha384Verify[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_InitValue
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_InitValueType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_InitValue[15];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Key
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Key
  \details
  Element                Description
  KeyElementsEndIdx      the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyElements
  KeyElementsStartIdx    the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyElements
  NvBlockIdx             the index of the 0:1 relation pointing to Crypto_30_LibCv_NvBlock
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_KeyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Key[119];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyDeriveISO15118
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyDeriveISO15118
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_KeyDeriveISO15118Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyDeriveISO15118[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyDeriveISO15118_20
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyDeriveISO15118_20
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_KeyDeriveISO15118_20Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyDeriveISO15118_20[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyElementInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyElementInfo
  \details
  Element              Description
  Id               
  InitValueEndIdx      the end index of the 0:n relation pointing to Crypto_30_LibCv_InitValue
  InitValueStartIdx    the start index of the 0:n relation pointing to Crypto_30_LibCv_InitValue
  Length           
  MaskedBits           contains bitcoded the boolean data of Crypto_30_LibCv_OnceOfKeyElementInfo, Crypto_30_LibCv_PartialOfKeyElementInfo, Crypto_30_LibCv_PersistOfKeyElementInfo
  Read             
  Write            
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_KeyElementInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyElementInfo[69];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyElements
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyElements
  \details
  Element               Description
  Id                
  KeyStorageEndIdx      the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageStartIdx    the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  KeyElementInfoIdx     the index of the 1:1 relation pointing to Crypto_30_LibCv_KeyElementInfo
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_KeyElementsType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyElements[194];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyGenP256R1
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyGenP256R1
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_KeyGenP256R1Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyGenP256R1[1];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyP256R1Secret
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyP256R1Secret
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_KeyP256R1SecretType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyP256R1Secret[1];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_NvBlock
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_NvBlock
  \brief  Contains parameters of /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock.
  \details
  Element               Description
  Crc                   Calculated CRC over layout of the block
  Descriptor            Contains values of DefinitionRef: /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock/CryptoNvBlockDescriptor.
  KeyStorageEndIdx      the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageStartIdx    the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  Length                Contains values of DefinitionRef: /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock/CryptoNvBlockLength.
  ConsistencyLevel      Contains values of DefinitionRef: /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock/CryptoNvBlockConsistencyLevel.
  Id                    Contains values of DefinitionRef: /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock/CryptoNvBlockId.
  Processing            Contains values of DefinitionRef: /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock/CryptoNvBlockProcessing.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_NvBlockType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_NvBlock[1];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_ObjectInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_ObjectInfo
  \details
  Element                             Description
  WorkspaceLength                     Holds the length of the workspace.
  AEADChaChaPoly1305DecryptIdx        the index of the 0:1 relation pointing to Crypto_30_LibCv_AEADChaChaPoly1305Decrypt
  AEADChaChaPoly1305EncryptIdx        the index of the 0:1 relation pointing to Crypto_30_LibCv_AEADChaChaPoly1305Encrypt
  AesDecryptIdx                       the index of the 0:1 relation pointing to Crypto_30_LibCv_AesDecrypt
  AesEncryptIdx                       the index of the 0:1 relation pointing to Crypto_30_LibCv_AesEncrypt
  AesGcmDecryptIdx                    the index of the 0:1 relation pointing to Crypto_30_LibCv_AesGcmDecrypt
  AesGcmEncryptIdx                    the index of the 0:1 relation pointing to Crypto_30_LibCv_AesGcmEncrypt
  CmacAesGenerateIdx                  the index of the 0:1 relation pointing to Crypto_30_LibCv_CmacAesGenerate
  CmacAesVerifyIdx                    the index of the 0:1 relation pointing to Crypto_30_LibCv_CmacAesVerify
  DRBGAESIdx                          the index of the 0:1 relation pointing to Crypto_30_LibCv_DRBGAES
  EcP256GenerateIdx                   the index of the 0:1 relation pointing to Crypto_30_LibCv_EcP256Generate
  EcP256VerifyIdx                     the index of the 0:1 relation pointing to Crypto_30_LibCv_EcP256Verify
  EcP521GenerateIdx                   the index of the 0:1 relation pointing to Crypto_30_LibCv_EcP521Generate
  EcP521VerifyIdx                     the index of the 0:1 relation pointing to Crypto_30_LibCv_EcP521Verify
  Ed25519GenerateIdx                  the index of the 0:1 relation pointing to Crypto_30_LibCv_Ed25519Generate
  Ed25519VerifyIdx                    the index of the 0:1 relation pointing to Crypto_30_LibCv_Ed25519Verify
  Fips186Idx                          the index of the 0:1 relation pointing to Crypto_30_LibCv_Fips186
  GmacAesGenerateIdx                  the index of the 0:1 relation pointing to Crypto_30_LibCv_GmacAesGenerate
  GmacAesVerifyIdx                    the index of the 0:1 relation pointing to Crypto_30_LibCv_GmacAesVerify
  HashIdx                             the index of the 0:1 relation pointing to Crypto_30_LibCv_Hash
  HmacSha1GenerateIdx                 the index of the 0:1 relation pointing to Crypto_30_LibCv_HmacSha1Generate
  HmacSha1VerifyIdx                   the index of the 0:1 relation pointing to Crypto_30_LibCv_HmacSha1Verify
  HmacSha256GenerateIdx               the index of the 0:1 relation pointing to Crypto_30_LibCv_HmacSha256Generate
  HmacSha256VerifyIdx                 the index of the 0:1 relation pointing to Crypto_30_LibCv_HmacSha256Verify
  HmacSha384GenerateIdx               the index of the 0:1 relation pointing to Crypto_30_LibCv_HmacSha384Generate
  HmacSha384VerifyIdx                 the index of the 0:1 relation pointing to Crypto_30_LibCv_HmacSha384Verify
  KeyDeriveHKDFExpandHMACSHA256Idx    the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256
  KeyDeriveHKDFExpandHMACSHA384Idx    the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384
  KeyDeriveHKDFHMACSHA256Idx          the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256
  KeyDeriveHKDFHMACSHA384Idx          the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384
  KeyDeriveISO15118Idx                the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyDeriveISO15118
  KeyDeriveISO15118_20Idx             the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyDeriveISO15118_20
  KeyGenP256R1Idx                     the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyGenP256R1
  KeyP256R1SecretIdx                  the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyP256R1Secret
  QueueIdx                            the index of the 1:1 relation pointing to Crypto_30_LibCv_Queue
  RandomSeedBufferEndIdx              the end index of the 0:n relation pointing to Crypto_30_LibCv_RandomSeedBuffer
  RandomSeedBufferStartIdx            the start index of the 0:n relation pointing to Crypto_30_LibCv_RandomSeedBuffer
  WorkspaceAddr                       Holds the address of the workspace.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_ObjectInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_ObjectInfo[9];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_ObjectInfoInd
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_ObjectInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Crypto_30_LibCv_ObjectInfo
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_ObjectInfoIndType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_ObjectInfoInd[83];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to Crypto_30_LibCv_PCPartitionConfig
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_PartitionIdentifiersType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PartitionIdentifiers[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PartitionInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PartitionInfo
  \details
  Element             Description
  DefaultRandomKey    Holds default random key ref
  MaskedBits          contains bitcoded the boolean data of Crypto_30_LibCv_AesOfPartitionInfo, Crypto_30_LibCv_HashOfPartitionInfo
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_PartitionInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PartitionInfo[1];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PrimitiveFct
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PrimitiveFct
  \details
  Element                  Description
  ObjectInfoIndEndIdx      the end index of the 0:n relation pointing to Crypto_30_LibCv_ObjectInfoInd
  ObjectInfoIndStartIdx    the start index of the 0:n relation pointing to Crypto_30_LibCv_ObjectInfoInd
  Dispatch             
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_PrimitiveFctType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveFct[36];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PrimitiveInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PrimitiveInfo
  \details
  Element            Description
  Combined       
  MaskedBits         contains bitcoded the boolean data of Crypto_30_LibCv_ContextOfPrimitiveInfo, Crypto_30_LibCv_DefaultRandomSourceOfPrimitiveInfo
  PrimitiveFctIdx    the index of the 1:1 relation pointing to Crypto_30_LibCv_PrimitiveFct
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_PrimitiveInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveInfo[72];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PrimitiveServiceInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PrimitiveServiceInfo
  \details
  Element                  Description
  PrimitiveInfoEndIdx      the end index of the 0:n relation pointing to Crypto_30_LibCv_PrimitiveInfo
  PrimitiveInfoStartIdx    the start index of the 0:n relation pointing to Crypto_30_LibCv_PrimitiveInfo
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_PrimitiveServiceInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveServiceInfo[21];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_BufferLength
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_BufferLength
  \brief  Buffer which holds the current seed of the Fips186 algorithm to restore the needed workspace.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_BufferLengthType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_BufferLength[9];
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Dispatch_QueuePrimitiveInfoIdx
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_SizeOfPrimitiveInfoType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Dispatch_QueuePrimitiveInfoIdx[9];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_DriverObjectState
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_DriverObjectState
  \brief  State of the current workspace usage.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_DriverObjectStateType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_DriverObjectState[9];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyLock
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyLock
  \brief  Stores locking counter of each key
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_KeyLockUType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_KeyLock;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyNvStatus
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyNvStatus
  \brief  Stores the key status of each key regarding synchronization with non-volatile memory
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_KeyNvStatusUType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_KeyNvStatus;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyStorage
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_KeyStorageType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_KeyStorage[12815];
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Lock
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Lock
  \brief  Id of job that currently occupies the workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_LockType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Lock[9];
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PartitionInitialized
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PartitionInitialized
  \brief  Tracks which partition has already been initialized
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_PartitionInitializedType, CRYPTO_30_LIBCV_VAR_ZERO_INIT) Crypto_30_LibCv_PartitionInitialized;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_ProcessJob_Trigger_Write
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_ProcessJob_Trigger_WriteType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_ProcessJob_Trigger_Write[9];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Queue
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Queue
  \brief  Acts as job queue for all driver objects.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_QueueUType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Queue;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_RandomSeedBuffer
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_RandomSeedBufferUType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_RandomSeedBuffer;  /* PRQA S 0777, 0759 */  /* MD_MSR_Rule5.1, MD_CSL_Union */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_RandomSourceGenerateCount
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_RandomSourceGenerateCount
  \brief  Used to check if the RNG calculation was valid
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_RandomSourceGenerateCountType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_RandomSourceGenerateCount;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Redirect_Buffer
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_Redirect_Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Redirect_Buffer[9];
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0
  \brief  Struct which holds the Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0.
  \details
  Element    Description
  Data       Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished
  \brief  Struct which holds the Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished.
  \details
  Element    Description
  Data       Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_FinishedType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1
  \brief  Struct which holds the Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1.
  \details
  Element    Description
  Data       Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished
  \brief  Struct which holds the Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished.
  \details
  Element    Description
  Data       Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_FinishedType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384
  \brief  Struct which holds the Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha384.
  \details
  Element    Description
  Data       Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha384.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384
  \brief  Struct which holds the Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_Hkdf_Sha384.
  \details
  Element    Description
  Data       Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_Hkdf_Sha384.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1
  \brief  Struct which holds the Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Global_HashSha1.
  \details
  Element    Description
  Data       Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Global_HashSha1.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv
  \brief  Struct which holds the Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv.
  \details
  Element    Description
  Data       Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCvType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General
  \brief  Struct which holds the Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General.
  \details
  Element    Description
  Data       Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_GeneralType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_WrittenLength
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_WrittenLength
  \brief  Holds the length which needs to be written in a next step for some algorithms.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_WrittenLengthType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_WrittenLength[9];
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
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

 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


#define CRYPTO_30_LIBCV_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/***********************************************************************************************************************
 *  MainFunctionGroup
 **********************************************************************************************************************/
/*!
 * \fn          Crypto_30_LibCv_MainFunction
 * \brief       Partition specific main function
 * \details     Calls MainFunctionHandler with dedicated partition.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  InitMemoryFunctionGroup
 **********************************************************************************************************************/
/*!
 * \fn          Crypto_30_LibCv_InitMemory
 * \brief       Partition specific InitMemory function
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Use this function in case these variables are not initialized by the startup code.
 **********************************************************************************************************************/
extern FUNC(void, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_InitMemory(void);

/***********************************************************************************************************************
 *  ReadFromBlock
 **********************************************************************************************************************/
/*!
 * \fn          Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock
 * \brief       Block specific callback routine which is called by NvM in order to let the Crypto driver copy data from
 *              NvM RAM mirror to Crypto RAM block. 
 * \param[in]   NvMBuffer   RAM mirror where Ram block data can be read from.
 * \return      E_OK      Data was copied from buffer.
 * \return      E_NOT_OK  Data was not copied.
 * \pre         -
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock(P2CONST(void, AUTOMATIC, CRYPTO_30_LIBCV_APPL_DATA) NvMBuffer);

/***********************************************************************************************************************
 *  WriteToBlock
 **********************************************************************************************************************/
/*!
 * \fn          Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock
 * \brief       Block specific callback routine which is called by NvM in order to let the Crypto driver copy data from
 *              RAM block to NvM RAM mirror.
 * \param[out]  NvMBuffer  RAM mirror where Ram block data shall be written to.
 * \return      E_OK      Data was copied to buffer.
 * \return      E_NOT_OK  No data was copied.
 * \pre         -
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock(P2VAR(void, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) NvMBuffer);

/***********************************************************************************************************************
 *  InitBlock
 **********************************************************************************************************************/
/*!
 * \fn          Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock
 * \brief       Block specific callback routine which is called by NvM in order to let the Crypto driver copy default
 *              data to a RAM block.
 * \return      E_OK      Data initialized.
 * \return      E_NOT_OK  Any error occured.
 * \pre         -
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock(void);

/***********************************************************************************************************************
 *  CallbackBlock
 **********************************************************************************************************************/
/*!
 * \fn          Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock
 * \brief       Block specific callback routine which is called by NvM in order to notify the Crypto driver that an
 *              asynchronous single block request has been finished.
 * \param[in]   uint8                  The service identifier of the completed request.
 * \param[in]   NvM_RequestResultType  Result of the single block job.
 * \return      E_OK      Callback function has been processed successfully.
 * \return      E_NOT_OK  Callback function has not been processed successfully.
 * \pre         -
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock(uint8 ServiceId, NvM_RequestResultType JobResult);
#define CRYPTO_30_LIBCV_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */




#if !defined (CRYPTO_30_LIBCV_NOUNIT_CSLUNIT)
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/

#endif



#endif /* CRYPTO_30_LIBCV_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_LibCv_Cfg.h
 *********************************************************************************************************************/

