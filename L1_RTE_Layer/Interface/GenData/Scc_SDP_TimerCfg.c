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
 *              File: Scc_SDP_TimerCfg.c
 *   Generation Time: 2025-08-26 17:17:05
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#define SCC_SDP_TIMERCFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Scc_SDP_TimerCfg.h"
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
 *  Scc_SDP_TimerCfg_Get_SECCDiscoveryProtocolTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configuration value of the related parameter
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_SDP_TimerCfg_Get_SECCDiscoveryProtocolTimeout(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigSECCDiscoveryProtocol/SccTimerConfigSDPParam/SECCDiscoveryProtocolTimeout */
  retVal = 50u;
  
  /* Return the configuration value of the related parameter */
  return retVal;
}


/**********************************************************************************************************************
 * Other values
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_SDP_TimerCfg_Get_SECCDiscoveryProtocolRetries 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configured numeric value
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_SDP_TimerCfg_Get_SECCDiscoveryProtocolRetries(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigSECCDiscoveryProtocol/SccTimerConfigSDPParam/SECCDiscoveryProtocolRetries */
  retVal = 49u;
  
  /* Return the configured numeric value */
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_SDP_TimerCfg_Get_SECCDiscoveryProtocolTlsRetries 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Return the configured numeric value
 * \endinternal
 */
FUNC(uint16, SCC_CODE) Scc_SDP_TimerCfg_Get_SECCDiscoveryProtocolTlsRetries(void)
{
  uint16 retVal;
  
  /* The following assignment is based on configuration parameter: /MICROSAR/Scc/SccConfigMapping/SccTimerConfig/SccTimerConfigSECCDiscoveryProtocol/SccTimerConfigSDPParam/SECCDiscoveryProtocolTlsRetries */
  retVal = 25u;
  
  /* Return the configured numeric value */
  return retVal;
}



#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Scc_SDP_TimerCfg.c
 *********************************************************************************************************************/

