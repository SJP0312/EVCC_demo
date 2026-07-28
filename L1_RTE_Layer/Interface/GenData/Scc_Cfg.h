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
 *            Module: Scc
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Scc_Cfg.h
 *   Generation Time: 2025-08-28 10:22:04
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#if !defined(SCC_CFG_H)
#define SCC_CFG_H

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Std_Types.h"

#include "EthIf_Cfg.h"
#include "TcpIp_Cfg.h"

/**********************************************************************************************************************
 *  SCC ECUC GLOBAL CONFIGURATION CONTAINER NAME
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GENERAL DEFINES
 *********************************************************************************************************************/
#ifndef SCC_USE_DUMMY_STATEMENT
#define SCC_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SCC_DUMMY_STATEMENT
#define SCC_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SCC_DUMMY_STATEMENT_CONST
#define SCC_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SCC_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define SCC_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef SCC_ATOMIC_VARIABLE_ACCESS
#define SCC_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef SCC_PROCESSOR_TC377T
#define SCC_PROCESSOR_TC377T
#endif
#ifndef SCC_COMP_DIAB
#define SCC_COMP_DIAB
#endif
#ifndef SCC_GEN_GENERATOR_MSR
#define SCC_GEN_GENERATOR_MSR
#endif
#ifndef SCC_CPUTYPE_BITORDER_LSB2MSB
#define SCC_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef SCC_CONFIGURATION_VARIANT_PRECOMPILE
#define SCC_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef SCC_CONFIGURATION_VARIANT_LINKTIME
#define SCC_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef SCC_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define SCC_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef SCC_CONFIGURATION_VARIANT
#define SCC_CONFIGURATION_VARIANT SCC_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef SCC_POSTBUILD_VARIANT_SUPPORT
#define SCC_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define SCC_NUM_STATES_IN_PROCESS_TRANSMIT                 4u

/**********************************************************************************************************************
 *  CONFIGURATION VARIANT
 *********************************************************************************************************************/
#define SCC_CONFIG_VARIANT                   SCC_CONFIGURATION_VARIANT




/**********************************************************************************************************************
 *  DEFINES
 *********************************************************************************************************************/

/* General Defines */
#define SCC_VERSION_INFO_API                          STD_OFF /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccVersionInfoApi */
#define SCC_DEV_ERROR_DETECT                          STD_OFF /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccDevErrorDetect */
#define SCC_DEV_ERROR_REPORT                          STD_OFF /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccDevErrorDetect */
#define SCC_IDSM_REPORT                               STD_OFF /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccEnableSecurityEventReporting */
#define SCC_IPADDR_SELECTION                          STD_ON /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccConnectionConfig/SccIPv6Address2Ref */

/* V2G Defines */                                     
#define SCC_V2G_PROT_VER                              1u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccV2GProtocolVersion */

#define SCC_EVSE_COMP_SEND_GEN_CHALLENGE_EVERY_TIME   STD_OFF
/* Connection Defines */                              
#define SCC_TCP_RX_BUF_LEN                            11250u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccConnectionConfig/SccTcpSocketRxBufLen */
#define SCC_TCP_TX_BUF_LEN                            10000u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccConnectionConfig/SccTcpSocketTxBufLen */
#define SCC_TLS_CONNECTION_ID                         0u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccConnectionConfig/SccTlsConnectionToUse -> TcpIpConf_TcpIpTlsConnection_TlsConnectionConfig_Scc */
#define SCC_TLS_CERT_CNT                              6u
#define SCC_TLS_CERT_MAXSUBJECTDCLEN                  63u
#define SCC_EXI_RX_STREAM_PBUF_ELEMENTS               2u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccConnectionConfig/SccV2GTPMaxTcpRxSegments */
                                                    
#define SCC_SCHEMA_OPP_CHARGE                         0u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccSchemaPriorityOppCharge */
#define SCC_SCHEMA_DIN                                3u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccSchemaPriorityDin */
#define SCC_SCHEMA_ISO                                2u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccSchemaPriorityIsoFdis */
#define SCC_SCHEMA_ISO_20                             1u /* Aggregation of the -20 schema specific configurations */  
#define SCC_SCHEMA_ISO_20AC                           0u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccSchemaPriorityIso20AC */
#define SCC_SCHEMA_ISO_20DC                           1u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccSchemaPriorityIso20DC */
#define SCC_SCHEMA_ISO_20WPT                          0u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccSchemaPriorityIso20WPT */
#define SCC_SCHEMA_ISO_20ACDP                         0u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccSchemaPriorityIso20ACDP */

                                           
#define SCC_ACTIVE_SCHEMA_CNT                         3u /* The number of actives schemata shown above */ 

/* The below define is the maximum length of all available PrivEnv identifier */
#define SCC_PRIVENV_IDMAXLEN                          3u
#define SCC_PRIVENV_NUMOFIDS                          0u

#define SCC_CHARGING_AC                               STD_OFF /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccEnableAcCharging */
#define SCC_CHARGING_DC                               STD_ON /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccEnableDcCharging */
#define SCC_CHARGING_BPT                              STD_ON /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccEnableBptCharging */

                                                      
#define SCC_ENABLE_TLS                                STD_ON /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccConnectionConfig/SccEnableTls */
#define SCC_ENABLE_TLS_ISO20_CLIENTAUTH               STD_ON /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccConnectionConfig/SccEnableISO20TlsClientAuth */
#define SCC_ENABLE_TLS_RESUMPTION                     STD_OFF /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccConnectionConfig/SccEnableTlsResumption */
#define SCC_ENABLE_PNC_CHARGING                       STD_ON /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccEnablePncCharging */
#define SCC_ENABLE_ISO15118_20_PNC_CHARGING           STD_OFF /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccEnableISO20PncCharging */
#define SCC_ENABLE_CERTIFICATE_UPDATE                 STD_ON /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccPncConfig/SccEnableCertificateUpdate */
#define SCC_ENABLE_CERTIFICATE_INSTALLATION           STD_ON /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccPncConfig/SccEnableCertificateInstallation */
#define SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION    STD_OFF /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccPncConfig/SccEnableISO20CertificateInstallation */
#define SCC_ENABLE_ONGOING_CALLBACKS                  STD_ON /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccEnableOngoingCallbacks */
#define SCC_ENABLE_CPS_CHECK                          STD_OFF /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccPncConfig/SccCertCpsCheckEnabled */
#define SCC_ENABLE_STATE_MACHINE                      STD_ON /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccEnableStateMachine */
#define SCC_ENABLE_STATEM_APPL_CONTROLLED_FLOW        STD_OFF /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccApplicationControlledFlow */
#define SCC_ENABLE_SLAC_HANDLING                      STD_ON /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccEnableSlacHandling */
#define SCC_ENABLE_SLAC_CHANGEABLE_NMK_FOR_LEAVE      STD_OFF /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccSlacConfig/SccEnableSlacChangeableNmkForLeave */
#define SCC_ENABLE_ISO15118_2_SERVICE_HPC1            STD_OFF /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccEnableISO15118_2_HPC1 */
#define SCC_RAMSHARING_CPS_CPO_ENABLED                STD_ON /* DefinitionRef: /MICROSAR/Scc/SccCertConfig/SccCertConfigEnableTlsCertsRAMSharing */
#define SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION   STD_OFF /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccPncConfig/SccEnableCertExtensionValidation */
#define SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES     STD_OFF /* DefinitionRef: /MICROSAR/Scc/SccCertConfig/SccISO15118_20Config/SccSupportED448Certificates */
#define SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES   STD_ON /* DefinitionRef: /MICROSAR/Scc/SccCertConfig/SccISO15118_20Config/SccSupportSECP521R1Certificates */

#define SCC_ENABLE_ISO15118_20_TPM_SUPPORT            STD_OFF /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccPncConfig/SccEnableTPMSupport */

     
#define SCC_PRIV_KEY_LEN                              32u /* DefinitionRef: /MICROSAR/Scc/SccCertConfig/SccISO15118_2Config/SccCertPrivKeyLen */
#define SCC_PUB_KEY_LEN                               65u /* DefinitionRef: /MICROSAR/Scc/SccCertConfig/SccISO15118_2Config/SccCertPubKeyLen */
#define SCC_IV_LEN                                    16u /* DefinitionRef: /MICROSAR/Scc/SccCertConfig/SccISO15118_2Config/SccCertIvLen */
#define SCC_PROV_CERT_ID_MAX_LEN                      18u /* DefinitionRef: /MICROSAR/Scc/SccCertConfig/SccISO15118_2Config/SccProvCertIdMaxLen */
#define SCC_ISO15118_2_ROOT_CERT_CNT                  1u
#define SCC_ISO15118_2_CPS_CERT_CNT                   1u /* DefinitionRef: /MICROSAR/Scc/SccCertConfig/SccISO15118_2Config/SccISO2CPSProvCertConfig */
#define SCC_ISO15118_2_CONTRACT_CERT_CNT              1u
#define SCC_ISO15118_2_CONTRACT_MAX_SUBS_CNT          2u
#define SCC_ISO15118_2_OEM_PROV_CERT_CNT              1u
#define SCC_MAX_SUPPORTED_PROVIDERS                   128u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccPncConfig/SccMaxSupportedProviders */
#define SCC_ISO15118_20_MAX_TAX_COSTS                 10u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccPncConfig/SccMaxTaxCosts */
#define SCC_ISO15118_20_ROOT_CERT_CNT                 2u /* DefinitionRef: /MICROSAR/Scc/SccCertConfig/SccISO15118_20Config/SccISO20V2GRootCertConfig */
#define SCC_ISO15118_20_VEHICLE_CERT_CNT              1u /* DefinitionRef: /MICROSAR/Scc/SccCertConfig/SccISO15118_20Config/SccISO20VehicleCertConfig */
#define SCC_ISO15118_20_OEMPROV_CERT_CNT              1u /* DefinitionRef: /MICROSAR/Scc/SccCertConfig/SccISO15118_20Config/SccISO20OEMProvCertConfig */
#define SCC_ISO15118_20_CONTRACT_CERT_CNT             1u /* DefinitionRef: /MICROSAR/Scc/SccCertConfig/SccISO15118_20Config/SccISO20EMSPCertConfig */
#define SCC_ISO15118_20_CONTRACT_MAX_SUBS_CNT         2u
#define SCC_ISO15118_20_CPS_CERT_CNT                  1u /* DefinitionRef: /MICROSAR/Scc/SccCertConfig/SccISO15118_20Config/SccISO20CPSProvCertConfig */
#define SCC_CONTRAT_MAX_SUBS_CNT                      2u
#define SCC_MAX_ROOT_CERT_CNT                         2u /* max(SCC_ISO15118_2_ROOT_CERT_CNT, SCC_ISO15118_20_ROOT_CERT_CNT) */
#define SCC_CPS_MAXSUBJECTDCLEN                       63u
#define SCC_SKI_MAXLEN                                10u
#define SCC_PCID_MAXLEN                               256u



#define SCC_NUM_OF_POOL_BUFF                          1u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccBufferConfig/SccPoolBuffer */
#define SCC_EXI_TEMP_BUF_LEN                          3000u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccBufferConfig/SccExiTempBufLen */
#define SCC_ENABLE_INTERNAL_CHARGING_PROFILE_BUFFER   STD_OFF /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccBufferConfig/SccEnableInternalChargingProfileBuffer */

#define SCC_IPV6_ADDRESS1                             TcpIpConf_TcpIpLocalAddr_TcpIpV6LocalAddr_TcpIpCtrl_LinkLocal /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccConnectionConfig/SccIPv6Address1Ref */
#define SCC_IPV6_ADDRESS2                             TcpIpConf_TcpIpLocalAddr_TcpIpV6LocalAddr_TcpIpCtrl_AsAn /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccConnectionConfig/SccIPv6Address2Ref */


#define SCC_CSM_SESSION_KEY_ID                        CsmConf_CsmKey_Csm_Scc_ResumeSessionInfo /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccGeneralCsmConfig/SccSessionKeyId */
#define SCC_CRYPTO_KEY_ELEM_SESSION_RESUME            1u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccGeneralCsmConfig/SccSessionKeyElementIdResume */
#define SCC_CRYPTO_KEY_ELEM_SESSION_HASH              2u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccGeneralCsmConfig/SccSessionKeyElementIdSessionHash */

/**********************************************************************************************************************
 *  OCSP config
 *********************************************************************************************************************/
#define SCC_ENABLE_OCSP                               STD_OFF /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccConnectionConfig */


/**********************************************************************************************************************
 *  PRECOMPILE CONFIG
 *********************************************************************************************************************/

#define SCC_MAIN_FUNCTION_PERIOD_MS             5u

#define SCC_NUM_OF_DYN_CONFIG_PARAMS            1u

/**********************************************************************************************************************
 *  NVM BLOCK DEFINES
 *********************************************************************************************************************/
#define SCC_SESSION_ID_NVM_BLOCK_LEN            9u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccNvmConfig/SccSessionIdNvmBlockExpLen */
#define SCC_SESSION_ID_NVM_BLOCK                NvMConf_NvMBlockDescriptor_SccSessionIdNvmBlock /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccNvmConfig/SccSessionIdNvmBlock */

#define SCC_DIAG_PARAMETERS_NVM_BLOCK_LEN       2u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccNvmConfig/SccDiagParametersNvmBlock */
#define SCC_DIAG_PARAMETERS_NVM_BLOCK           NvMConf_NvMBlockDescriptor_SccDynConfigParamsNvmBlock /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccNvmConfig/SccDiagParametersNvmBlock */

/**********************************************************************************************************************
 *  Payload types
 *********************************************************************************************************************/
#define SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_PLC_REQ           0x9000u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccV2GTpHdrPayloadTypeSdpReqPlc */
#define SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_PLC_RES           0x9001u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccV2GTpHdrPayloadTypeSdpResPlc */

#define SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_WIRELESS_REQ      0x9002u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccV2GTpHdrPayloadTypeSdpReqWireless */
#define SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_WIRELESS_RES      0x9003u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccV2GTpHdrPayloadTypeSdpResWireless */

#define SCC_V2GTP_HDR_PAYLOAD_TYPE_SAP                   0x8001u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccV2GTpHdrPayloadTypeSap */
#define SCC_V2GTP_HDR_PAYLOAD_TYPE_EXI                   0x8001u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccV2GTpHdrPayloadTypeExi */

#define SCC_V2GTP_HDR_PAYLOAD_TYPE_CM                    0x8002u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccV2GTpHdrPayloadTypeCommonMessages */
#define SCC_V2GTP_HDR_PAYLOAD_TYPE_AC                    0x8003u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccV2GTpHdrPayloadTypeAcMessages */
#define SCC_V2GTP_HDR_PAYLOAD_TYPE_DC                    0x8004u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccV2GTpHdrPayloadTypeDcMessages */
#define SCC_V2GTP_HDR_PAYLOAD_TYPE_WPT                   0x8006u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccV2GTpHdrPayloadTypeWptMessages */
#define SCC_V2GTP_HDR_PAYLOAD_TYPE_ACDP                  0x8005u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccV2GTpHdrPayloadTypeAcdpMessages */

#define SCC_V2GTP_HDR_PAYLOAD_TYPE_RENEGOTIATION         0x8101u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccParallelChannels/SccV2GTpHdrPayloadTypeRenegotiation */
#define SCC_V2GTP_HDR_PAYLOAD_TYPE_ACDP_SYSTEM_STATUS    0x8103u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccParallelChannels/SccV2GTpHdrPayloadTypeAcdp */
#define SCC_V2GTP_HDR_PAYLOAD_TYPE_METERING_RECEIPT      0x8102u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccParallelChannels/SccV2GTpHdrPayloadTypeMetering */

#define SCC_ENABLE_RENEGOTIATION_CHANNEL                 STD_OFF /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccParallelChannels/SccEnableRenegotiationChannel */
#define SCC_ENABLE_ACDP_SYSTEM_STATUS                    STD_OFF /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccParallelChannels/SccEnableAcdpSystemStatusChannel */
#define SCC_ENABLE_METERING_RECEIPT                      STD_OFF /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccParallelChannels/SccEnableMeteringChannel */

#define SCC_NUM_OF_RES_PER_MAIN_FUNCTION                 1u /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccV2GConfig/SccParallelChannels/SccProcessMaxNumResponse */


/**********************************************************************************************************************
 *  CSM Abstraction Layer
 *********************************************************************************************************************/
 #define SCC_CSM_SIGNATUREGENERATE              Csm_SignatureGenerate /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccCsmAbstractionConfig/SccCsmSignatureGenerate */
 #define SCC_CSM_SIGNATUREVERIFY                Csm_SignatureVerify /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccCsmAbstractionConfig/SccCsmSignatureVerify */
 #define SCC_CSM_KEYELEMENTSET                  Csm_KeyElementSet /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccCsmAbstractionConfig/SccCsmKeyElementSet */
 #define SCC_CSM_KEYSETVALID                    Csm_KeySetValid /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccCsmAbstractionConfig/SccCsmKeySetValid */
 #define SCC_CSM_CANCELJOB                      Csm_CancelJob /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccCsmAbstractionConfig/SccCsmCancelJob */
 #define SCC_CSM_KEYELEMENTCOPY                 Csm_KeyElementCopy /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccCsmAbstractionConfig/SccCsmKeyElementCopy */
 #define SCC_CSM_KEYDERIVEFUNC                  Csm_JobKeyDerive /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccCsmAbstractionConfig/SccCsmJobKeyDeriveFunc */
 #define SCC_CSM_KEYELEMENTGET                  Csm_KeyElementGet /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccCsmAbstractionConfig/SccCsmKeyElementGet */
 #define SCC_CSM_HASH                           Csm_Hash /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccCsmAbstractionConfig/SccCsmHash */
 
/**********************************************************************************************************************
 *  KEYM Abstraction Layer
 *********************************************************************************************************************/
 #define SCC_KEYM_CERTELEMENTGET                KeyM_CertElementGet /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccKeyMAbstractionConfig/SccKeyMCertElementGet */
 #define SCC_KEYM_CERTGETSTATUS                 KeyM_CertGetStatus /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccKeyMAbstractionConfig/SccKeyMCertGetStatus */
 #define SCC_KEYM_GETCERTIFICATE                KeyM_GetCertificate /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccKeyMAbstractionConfig/SccKeyMGetCertificate */
 #define SCC_KEYM_SETCERTIFICATE                KeyM_SetCertificate /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccKeyMAbstractionConfig/SccKeyMSetCertifcate */
 #define SCC_KEYM_SETCERTIFICATEINGROUP         KeyM_SetCertificateInGroup /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccKeyMAbstractionConfig/SccKeyMSetCertificateInGroup */
 #define SCC_KEYM_VERIFYCERTIFICATE             KeyM_VerifyCertificate /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccKeyMAbstractionConfig/SccKeyMVerifyCertifcate */
 #define SCC_KEYM_VERIFYGROUP                   KeyM_VerifyGroup /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccKeyMAbstractionConfig/SccKeyMVerifyGroup */
 #define SCC_KEYM_GETISSUERCERTID               KeyM_GetIssuerCertId /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccKeyMAbstractionConfig/SccKeyMGetIssuerCertId */
 #define SCC_KEYM_CERTDELETE                    KeyM_CertDelete /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccKeyMAbstractionConfig/SccKeyMCertDelete */
 #define SCC_KEYM_CERTSTRUCTUREGET              KeyM_CertStructureGet /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccKeyMAbstractionConfig/SccKeyMCertStructureGet */
 #define SCC_KEYM_GETCERTBASICCONSTRAINTS       KeyM_GetCertBasicConstraints /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccKeyMAbstractionConfig/SccKeyMGetCertBasicConstraints */
 #define SCC_KEYM_CERTKEYUSAGE                  KeyM_GetCertKeyUsage /* DefinitionRef: /MICROSAR/Scc/SccGeneral/SccAbstractionConfig/SccKeyMAbstractionConfig/SccKeyMGetCertKeyUsage */

#endif /* SCC_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Scc_Cfg.h
 *********************************************************************************************************************/

