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
 *              File: Scc_TimerGeneral_TimerCfg.h
 *   Generation Time: 2025-08-26 17:17:05
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

 
#if !defined(SCC_TIMERGENERAL_TIMERCFG_H)
#define SCC_TIMERGENERAL_TIMERCFG_H


/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Scc_Types.h"
#include "Scc_Lcfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define Scc_TimerGeneral_TimerCfg_ConfigType_IPAddressWaitTimeout  SCC_CFG_TYPE_STATIC 
#define Scc_TimerGeneral_TimerCfg_ConfigType_TransportLayerTimeout SCC_CFG_TYPE_STATIC 
#define Scc_TimerGeneral_TimerCfg_ConfigType_OnHoldTimeout         SCC_CFG_TYPE_STATIC 



#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Timeout values
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_TimerGeneral_TimerCfg_Get_IPAddressWaitTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_TimerGeneral_TimerCfg_Get_IPAddressWaitTimeout(void);

/**********************************************************************************************************************
 *  Scc_TimerGeneral_TimerCfg_Get_TransportLayerTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_TimerGeneral_TimerCfg_Get_TransportLayerTimeout(void);

/**********************************************************************************************************************
 *  Scc_TimerGeneral_TimerCfg_Get_OnHoldTimeout 
 *********************************************************************************************************************/
/*! \brief          Returns the configured timer timeout value in main function cycles
 *  \details        -
 *  \return         The configured timer timeout value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint16, SCC_CODE) Scc_TimerGeneral_TimerCfg_Get_OnHoldTimeout(void);



/**********************************************************************************************************************
 * Other values
 *********************************************************************************************************************/

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* SCC_TIMERGENERAL_TIMERCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Scc_TimerGeneral_TimerCfg.h
 *********************************************************************************************************************/

