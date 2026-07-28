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
 *              File: EthTrcv_30_Ar7000_Lcfg.h
 *   Generation Time: 2025-09-11 13:39:31
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/


#if !defined(ETHTRCV_30_AR7000_LCFG_H)
#define ETHTRCV_30_AR7000_LCFG_H

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "EthTrcv_GeneralTypes.h"
#include "EthTrcv_30_Ar7000_Types.h"
#include "EthTrcv_30_Ar7000_HwCfg.h"


/**********************************************************************************************************************
 *  VARIANT DEPENDENT GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  DATA TYPES
 *********************************************************************************************************************/
 

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define ETHTRCV_30_Ar7000_DONT_CARE  (0xFFU)

/**********************************************************************************************************************
 *  RTM MEASUREMENT POINT MACROS
 *********************************************************************************************************************/

#define EthTrcv_30_Ar7000_Rtm_Start(Type)

#define EthTrcv_30_Ar7000_Rtm_Stop(Type)

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


#define ETHTRCV_30_AR7000_START_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

extern CONST(uint8,   ETHTRCV_30_AR7000_CONST) EthTrcv_30_Ar7000_HwSubIndex[1];
extern CONST(uint8,   ETHTRCV_30_AR7000_CONST) EthTrcv_30_Ar7000_HwIndex[1];
extern CONST(uint8,   ETHTRCV_30_AR7000_CONST) EthTrcv_30_Ar7000_Speed[1];
extern CONST(boolean, ETHTRCV_30_AR7000_CONST) EthTrcv_30_Ar7000_AutoNegotiation[1];

#define ETHTRCV_30_AR7000_STOP_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#define ETHTRCV_30_AR7000_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

extern CONST(EthTrcv_30_Ar7000_ConfigType, ETHTRCV_30_AR7000_CONST) EthTrcv_30_Ar7000_Config;

extern CONST(uint8, ETHTRCV_30_AR7000_CONST) EthTrcv_30_Ar7000_MiiMode[1];

#define ETHTRCV_30_AR7000_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#define ETHTRCV_30_AR7000_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/**********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define ETHTRCV_30_AR7000_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */


/**********************************************************************************************************************
 *  VARIANT DEPENDENT GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  ROM VARIABLES
 *********************************************************************************************************************/
#define ETHTRCV_30_AR7000_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */



#define ETHTRCV_30_AR7000_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/**********************************************************************************************************************
 *  RAM VARIABLES
 *********************************************************************************************************************/
#define ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */


#define ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */


#endif /* ETHTRCV_30_AR7000_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Ar7000_Lcfg.h
 *********************************************************************************************************************/
 
