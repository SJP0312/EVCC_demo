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
 *              File: Scc_StateM_ParamsCfg.c
 *   Generation Time: 2025-08-26 17:17:05
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#define SCC_STATEM_PARAMSCFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
 #include "Scc_StateM_ParamsCfg.h"
 #include "Scc.h"
 /* The following includes are based on configuration parameter /MICROSAR/Scc/SccConfigMapping/SccCbkIncludeHeader */
/* User defined header files that shall include the prototypes for the external parameters */
#include "_ApplScc_CbkStubs.h"


/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/
/* PRQA S 3673 EOF */ /* MD_Scc_VariantDependent */

#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Timeout values
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_AuthorizationOngoingTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_AuthorizationOngoingTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/AuthorizationOngoingTimeout */
  retVal = 12000u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ChargeParameterDiscoveryOngoingTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ChargeParameterDiscoveryOngoingTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/ChargeParameterDiscoveryOngoingTimeout */
  retVal = 12000u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ScheduleExchangeOngoingTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ScheduleExchangeOngoingTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/ScheduleExchangeOngoingTimeout */
  retVal = 12000u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_CableCheckOngoingTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_CableCheckOngoingTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/CableCheckOngoingTimeout */
  retVal = 12000u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_CableCheckTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_CableCheckTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/CableCheckTimeout */
  retVal = 8000u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_PreChargeTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_PreChargeTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/PreChargeTimeout */
  retVal = 3000u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ISO_20_PreChargeTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ISO_20_PreChargeTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/ISO_20_PreChargeTimeout */
  retVal = 1400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_CertificateInstallationOngoingTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_CertificateInstallationOngoingTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/CertificateInstallationOngoingTimeout */
  retVal = 12000u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}



/**********************************************************************************************************************
 * Delay values
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ReconnectDelay 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the delay value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ReconnectDelay(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/ReconnectDelay */
  retVal = 60u;
  
  /* Return the delay value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_AuthorizationNextReqDelay 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the delay value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_AuthorizationNextReqDelay(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/AuthorizationNextReqDelay */
  retVal = 100u;
  
  /* Return the delay value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ChargeParameterDiscoveryNextReqDelay 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the delay value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ChargeParameterDiscoveryNextReqDelay(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/ChargeParameterDiscoveryNextReqDelay */
  retVal = 100u;
  
  /* Return the delay value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_CableCheckNextReqDelay 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the delay value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_CableCheckNextReqDelay(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/CableCheckNextReqDelay */
  retVal = 40u;
  
  /* Return the delay value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ChargeLoopNextReqDelay 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the delay value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ChargeLoopNextReqDelay(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/ChargeLoopNextReqDelay */
  retVal = 40u;
  
  /* Return the delay value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_PreChargeNextReqDelay 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the delay value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_PreChargeNextReqDelay(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/PreChargeNextReqDelay */
  retVal = 40u;
  
  /* Return the delay value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ScheduleExchangeNextReqDelay 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the delay value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ScheduleExchangeNextReqDelay(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/ScheduleExchangeNextReqDelay */
  retVal = 40u;
  
  /* Return the delay value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_PowerDeliveryNextReqDelay 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the delay value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_PowerDeliveryNextReqDelay(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/PowerDeliveryNextReqDelay */
  retVal = 40u;
  
  /* Return the delay value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ServiceDetailNextReqDelay 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the delay value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ServiceDetailNextReqDelay(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/ServiceDetailNextReqDelay */
  retVal = 40u;
  
  /* Return the delay value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_CurrentDemandNextReqDelay 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the delay value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_CurrentDemandNextReqDelay(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/CurrentDemandNextReqDelay */
  retVal = 20u;
  
  /* Return the delay value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_WeldingDetectionNextReqDelay 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the delay value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_WeldingDetectionNextReqDelay(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/WeldingDetectionNextReqDelay */
  retVal = 40u;
  
  /* Return the delay value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ChargingStatusNextReqDelay 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the delay value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ChargingStatusNextReqDelay(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/ChargingStatusNextReqDelay */
  retVal = 200u;
  
  /* Return the delay value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_CertificateInstallationNextReqDelay 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the delay value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_CertificateInstallationNextReqDelay(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/CertificateInstallationNextReqDelay */
  retVal = 100u;
  
  /* Return the delay value of the related parameter */
  return retVal;
}



/**********************************************************************************************************************
 * Other values
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_AcceptUnsecureConnection 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configured numeric value
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_AcceptUnsecureConnection(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/AcceptUnsecureConnection */
  retVal = 1u;
  
  /* Return the configured numeric value */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_AcceptFreeCertificateServicesOnly 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configured numeric value
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_AcceptFreeCertificateServicesOnly(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/AcceptFreeCertificateServicesOnly */
  retVal = 0u;
  
  /* Return the configured numeric value */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ReconnectRetries 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configured numeric value
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ReconnectRetries(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/ReconnectRetries */
  retVal = 9u;
  
  /* Return the configured numeric value */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_RequestInternetDetails 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configured numeric value
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_RequestInternetDetails(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/RequestInternetDetails */
  retVal = 1u;
  
  /* Return the configured numeric value */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_TLConnectedWaitTime 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configured numeric value
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_TLConnectedWaitTime(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/TLConnectedWaitTime */
  retVal = 0u;
  
  /* Return the configured numeric value */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_PaymentPrioritization 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configured numeric value
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_PaymentPrioritization(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/PaymentPrioritization */
  retVal = 2u;
  
  /* Return the configured numeric value */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ContractCertificateChainIndexInUse 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configured numeric value
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ContractCertificateChainIndexInUse(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/ContractCertificateChainIndexInUse */
  retVal = 0u;
  
  /* Return the configured numeric value */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_CertificateExpireThreshold 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configured numeric value
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_CertificateExpireThreshold(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/CertificateExpireThreshold */
  retVal = 7u;
  
  /* Return the configured numeric value */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_RequestCertificateDetails 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configured numeric value
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_RequestCertificateDetails(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/RequestCertificateDetails */
  retVal = 1u;
  
  /* Return the configured numeric value */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_RequestCertificateInstallation 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configured numeric value
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_RequestCertificateInstallation(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/RequestCertificateInstallation */
  retVal = 1u;
  
  /* Return the configured numeric value */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_RequestCertificateUpdate 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configured numeric value
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_RequestCertificateUpdate(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/RequestCertificateUpdate */
  retVal = 1u;
  
  /* Return the configured numeric value */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_SLACAmpMapMode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configured numeric value
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_SLACAmpMapMode(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/SLACAmpMapMode */
  retVal = 0u;
  
  /* Return the configured numeric value */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_IsTlsInSdpPossible 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configured numeric value
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_IsTlsInSdpPossible(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/IsTlsInSdpPossible */
  retVal = 1u;
  
  /* Return the configured numeric value */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Get_ServiceRenegotiation 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Enter exclusive area 3
 * - Fetch dynamic configuration data
 * - Leave exclusive area 3
 * - Return the configured numeric value
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_StateM_ParamCfg_Get_ServiceRenegotiation(void)
{
  uint16 retVal;
  
  /* Enter exclusive area 3 */
  SCC_ENTER_EXCLUSIVE_AREA_3();
  /* Fetch dynamic configuration data */
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/ServiceRenegotiation */
  retVal = Scc_DynConfigParamsNvm[Scc_DynConfigParam_StateM_ParamCfg_ServiceRenegotiation];
  /* Leave exclusive area 3 */
  SCC_LEAVE_EXCLUSIVE_AREA_3();
  
  /* Return the configured numeric value */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_ParamCfg_Set_ServiceRenegotiation 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Enter exclusive area 3
 * - Modify dynamic configuration data
 * - Leave exclusive area 3
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_ParamCfg_Set_ServiceRenegotiation(uint16 ValueToSet)
{
  /* Enter exclusive area 3 */
  SCC_ENTER_EXCLUSIVE_AREA_3();
  /* Modify dynamic configuration data */
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/ServiceRenegotiation */
  Scc_DynConfigParamsNvm[Scc_DynConfigParam_StateM_ParamCfg_ServiceRenegotiation] = ValueToSet;
  /* Leave exclusive area 3 */
  SCC_LEAVE_EXCLUSIVE_AREA_3();
}



#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Scc_StateM_ParamsCfg.c
 *********************************************************************************************************************/

