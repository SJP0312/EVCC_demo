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
 *              File: Scc_DIN70121_TimerCfg.c
 *   Generation Time: 2025-09-23 11:18:24
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#define SCC_DIN70121_TIMERCFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
 #include "Scc_DIN70121_TimerCfg.h"
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
 *  Scc_DIN70121_TimerCfg_Get_SequencePerformanceTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_DIN70121_TimerCfg_Get_SequencePerformanceTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigDIN/SccTimerConfigDINParam/SequencePerformanceTimeout */
  retVal = 11800u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_TimerCfg_Get_CommunicationSetupTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_DIN70121_TimerCfg_Get_CommunicationSetupTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigDIN/SccTimerConfigDINParam/CommunicationSetupTimeout */
  retVal = 4000u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_TimerCfg_Get_ReadyToChargeTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_DIN70121_TimerCfg_Get_ReadyToChargeTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigDIN/SccTimerConfigDINParam/ReadyToChargeTimeout */
  retVal = 30000u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_TimerCfg_Get_ContractAuthenticationMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_DIN70121_TimerCfg_Get_ContractAuthenticationMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigDIN/SccTimerConfigDINParam/ContractAuthenticationMessageTimeout */
  retVal = 400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_TimerCfg_Get_CableCheckMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_DIN70121_TimerCfg_Get_CableCheckMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigDIN/SccTimerConfigDINParam/CableCheckMessageTimeout */
  retVal = 400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_TimerCfg_Get_ChargeParameterDiscoveryMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_DIN70121_TimerCfg_Get_ChargeParameterDiscoveryMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigDIN/SccTimerConfigDINParam/ChargeParameterDiscoveryMessageTimeout */
  retVal = 400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_TimerCfg_Get_CurrentDemandMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_DIN70121_TimerCfg_Get_CurrentDemandMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigDIN/SccTimerConfigDINParam/CurrentDemandMessageTimeout */
  retVal = (uint16)Appl_SccDynCP_DIN70121_TimerCfg_CurrentDemandMessageTimeout(); /* PRQA S 4424 */ /* MD_SCC_GENERIC_CFG_PARAMETER */
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_TimerCfg_Get_ServicePaymentSelectionMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_DIN70121_TimerCfg_Get_ServicePaymentSelectionMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigDIN/SccTimerConfigDINParam/ServicePaymentSelectionMessageTimeout */
  retVal = 400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_TimerCfg_Get_PowerDeliveryMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_DIN70121_TimerCfg_Get_PowerDeliveryMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigDIN/SccTimerConfigDINParam/PowerDeliveryMessageTimeout */
  retVal = 400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_TimerCfg_Get_PreChargeMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_DIN70121_TimerCfg_Get_PreChargeMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigDIN/SccTimerConfigDINParam/PreChargeMessageTimeout */
  retVal = 400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_TimerCfg_Get_ServiceDiscoveryMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_DIN70121_TimerCfg_Get_ServiceDiscoveryMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigDIN/SccTimerConfigDINParam/ServiceDiscoveryMessageTimeout */
  retVal = 400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_TimerCfg_Get_SessionSetupMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_DIN70121_TimerCfg_Get_SessionSetupMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigDIN/SccTimerConfigDINParam/SessionSetupMessageTimeout */
  retVal = 400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_TimerCfg_Get_SessionStopMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_DIN70121_TimerCfg_Get_SessionStopMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigDIN/SccTimerConfigDINParam/SessionStopMessageTimeout */
  retVal = 400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_TimerCfg_Get_WeldingDetectionMessageTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_DIN70121_TimerCfg_Get_WeldingDetectionMessageTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigDIN/SccTimerConfigDINParam/WeldingDetectionMessageTimeout */
  retVal = 400u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}


#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Scc_DIN70121_TimerCfg.c
 *********************************************************************************************************************/

