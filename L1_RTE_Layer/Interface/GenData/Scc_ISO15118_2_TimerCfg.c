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
 *              File: Scc_ISO15118_2_TimerCfg.c
 *   Generation Time: 2025-09-11 13:39:31
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#define SCC_ISO15118_2_TIMERCFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
 #include "Scc_ISO15118_2_TimerCfg.h"
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
 * Timer
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_SequencePerformanceTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_SequencePerformanceTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigISO/SccTimerConfigISOParam/SequencePerformanceTimeout */
  retVal = 8000u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_CommunicationSetupTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_CommunicationSetupTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigISO/SccTimerConfigISOParam/CommunicationSetupTimeout */
  retVal = 4000u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_AuthorizationMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_AuthorizationMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigISO/SccTimerConfigISOParam/AuthorizationMessageTimeout */
  retVal = 400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_CableCheckMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_CableCheckMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigISO/SccTimerConfigISOParam/CableCheckMessageTimeout */
  retVal = 1000u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_CertificateInstallationMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_CertificateInstallationMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigISO/SccTimerConfigISOParam/CertificateInstallationMessageTimeout */
  retVal = 1000u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_CertificateUpdateMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_CertificateUpdateMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigISO/SccTimerConfigISOParam/CertificateUpdateMessageTimeout */
  retVal = 1000u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_ChargeParameterDiscoveryMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_ChargeParameterDiscoveryMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigISO/SccTimerConfigISOParam/ChargeParameterDiscoveryMessageTimeout */
  retVal = 400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_ChargingStatusMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_ChargingStatusMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigISO/SccTimerConfigISOParam/ChargingStatusMessageTimeout */
  retVal = 400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_CurrentDemandMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_CurrentDemandMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigISO/SccTimerConfigISOParam/CurrentDemandMessageTimeout */
  retVal = (uint16)Appl_SccDynCP_ISO15118_2_TimerCfg_CurrentDemandMessageTimeout(); /* PRQA S 4424 */ /* MD_SCC_GENERIC_CFG_PARAMETER */
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_MeteringReceiptMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_MeteringReceiptMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigISO/SccTimerConfigISOParam/MeteringReceiptMessageTimeout */
  retVal = 400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_PaymentDetailsMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_PaymentDetailsMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigISO/SccTimerConfigISOParam/PaymentDetailsMessageTimeout */
  retVal = 1000u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_PaymentServiceSelectionMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_PaymentServiceSelectionMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigISO/SccTimerConfigISOParam/PaymentServiceSelectionMessageTimeout */
  retVal = 400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_PowerDeliveryMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_PowerDeliveryMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigISO/SccTimerConfigISOParam/PowerDeliveryMessageTimeout */
  retVal = 1000u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_PreChargeMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_PreChargeMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigISO/SccTimerConfigISOParam/PreChargeMessageTimeout */
  retVal = 400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_ServiceDetailMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_ServiceDetailMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigISO/SccTimerConfigISOParam/ServiceDetailMessageTimeout */
  retVal = 1000u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_ServiceDiscoveryMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_ServiceDiscoveryMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigISO/SccTimerConfigISOParam/ServiceDiscoveryMessageTimeout */
  retVal = 400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_SessionSetupMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_SessionSetupMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigISO/SccTimerConfigISOParam/SessionSetupMessageTimeout */
  retVal = 400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_SessionStopMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_SessionStopMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigISO/SccTimerConfigISOParam/SessionStopMessageTimeout */
  retVal = 400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_TimerCfg_Get_WeldingDetectionMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_ISO15118_2_TimerCfg_Get_WeldingDetectionMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigISO/SccTimerConfigISOParam/WeldingDetectionMessageTimeout */
  retVal = 400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}



#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_2_TimerCfg.c
 *********************************************************************************************************************/

