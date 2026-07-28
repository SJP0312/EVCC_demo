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
 *            Module: EthTrcv_Ar7000
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EthTrcv_30_Ar7000_Lcfg.c
 *   Generation Time: 2025-09-11 13:39:31
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/


#define ETHTRCV_30_AR7000_LCFG_SOURCE

/* START of Checksum exclude for - EthTrcv_LinktimeCRC */

/* PRQA S 0810 ETHTRCV_30_Ar7000_INCL_NESTING */ /* MD_EthTrcv_30_Ar7000_IncludeNesting */
/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "EthTrcv_30_Ar7000_Lcfg.h"

/* PRQA L:ETHTRCV_30_Ar7000_INCL_NESTING */ /* MD_EthTrcv_30_Ar7000_IncludeNesting */
/**********************************************************************************************************************
 *  RAM VARIABLES
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  ROM VARIABLES
 *********************************************************************************************************************/
/* START of Checksum include for - EthTrcv_LinktimeCRC */


#define ETHTRCV_30_AR7000_START_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

CONST(uint8, ETHTRCV_30_AR7000_CONST) EthTrcv_30_Ar7000_HwSubIndex[1] =
{
  ETHTRCV_DONT_CARE
};

CONST(uint8, ETHTRCV_30_AR7000_CONST) EthTrcv_30_Ar7000_HwIndex[1] =
{
  (uint8)EthConf_EthCtrlConfig_EthCtrlConfig
};

CONST(uint8, ETHTRCV_30_AR7000_CONST) EthTrcv_30_Ar7000_Speed[1] =
{
  ETHTRCV_BAUD_RATE_100MBIT
};

CONST(uint8, ETHTRCV_30_AR7000_CONST) EthTrcv_30_Ar7000_MiiMode[1] =
{
  ETHTRCV_DONT_CARE
};

CONST(boolean, ETHTRCV_30_AR7000_CONST) EthTrcv_30_Ar7000_AutoNegotiation[1] =
{
  TRUE
};

#define ETHTRCV_30_AR7000_STOP_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#define ETHTRCV_30_AR7000_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

CONST(EthTrcv_30_Ar7000_ConfigType, ETHTRCV_30_AR7000_CONST) EthTrcv_30_Ar7000_Config = 0U;

#define ETHTRCV_30_AR7000_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */


#define ETHTRCV_30_AR7000_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/**********************************************************************************************************************
 *  DYNAMIC FUNCTIONS
 *********************************************************************************************************************/
#define ETHTRCV_30_AR7000_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/**********************************************************************************************************************
 *  VARIANT DEPENDEND
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ROM VARIABLES
 *********************************************************************************************************************/
#define ETHTRCV_30_AR7000_START_SEC_CONST_UNSPECIFIED_NVM
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#define ETHTRCV_30_AR7000_STOP_SEC_CONST_UNSPECIFIED_NVM
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */
#define ETHTRCV_30_AR7000_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */


#define ETHTRCV_30_AR7000_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#define ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_UNSPECIFIED_NVM
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */
/**********************************************************************************************************************
 *  RAM VARIABLES
 *********************************************************************************************************************/

#define ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_UNSPECIFIED_NVM
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */


/* END of Checksum include for - EthTrcv_LinktimeCRC */


/* END of Checksum exclude for - EthTrcv_LinktimeCRC */

/**********************************************************************************************************************
 *  MISRA DEVIATIONS
 *********************************************************************************************************************/
 
/* module specific MISRA deviations:
 MD_EthTrcv_30_Ar7000_IncludeNesting:
      Reason:     In some constellation it may happen that the nesting of includes exceeds the given limit.
                  This module cannot influence the includes of other modules.
      Risk:       There is no risk. If nessting level is to high the compiler complains.
      Prevention: No prevention necessary.
*/

/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Ar7000_Lcfg.c
 *********************************************************************************************************************/

