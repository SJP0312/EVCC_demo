/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Scc_StateMachineTimer.h
 *        \brief  Smart Charging Communication Header File
 *
 *      \details  Implements Vehicle 2 Grid communication according to the specifications ISO/IEC 15118-2,
 *                DIN SPEC 70121 and customer specific schemas.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/
#if !defined (SCC_STATEMACHINETIMER_H)
# define SCC_STATEMACHINETIMER_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON )

#include "Scc_Lcfg.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef uint16 Scc_StateMachineTimer_TimeValueType;

typedef enum
{
  Scc_StateMachineTimer_Disabled,
  Scc_StateMachineTimer_Enabled
}Scc_StateMachineTimer_StateEnumType;

typedef struct
{
  Scc_StateMachineTimer_TimeValueType TimerValue;
  Scc_StateMachineTimer_StateEnumType State;
}Scc_StateMachineTimerStructType;

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_StateMachineTimer_Init
 *********************************************************************************************************************/
/*! \brief          Initializes the timer module.
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateMachineTimer_Init(void);

/**********************************************************************************************************************
 *  Scc_StateMachineTimer_ProcessTimers
 *********************************************************************************************************************/
/*! \brief          Processes all known timers.
 *  \details        The context while calling this function defines the time related to each count value.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateMachineTimer_ProcessTimers(void);

/**********************************************************************************************************************
 *  Scc_StateMachineTimer_Start
 *********************************************************************************************************************/
/*! \brief          Starts the passed timer with the given value.
 *  \details        If the passed StartValue is equal to 0 the timer will be disabled as the value can not
 *                  be further decremented.
 *  \pre            -
 *  \param[in]      Timer        The timer to start
 *  \param[in]      StartValue   The counting value in Scc_StateMachineTimer_ProcessTimers cycles
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
 FUNC(void, SCC_CODE) Scc_StateMachineTimer_Start(Scc_StateMachineTimerEnumType Timer, Scc_StateMachineTimer_TimeValueType StartValue);

 /**********************************************************************************************************************
 *  Scc_StateMachineTimer_Stop
 *********************************************************************************************************************/
 /*! \brief         Stops the passed timer
 *  \details        -
 *  \pre            -
 *  \param[in]      Timer        The timer to stop
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
 FUNC(void, SCC_CODE) Scc_StateMachineTimer_Stop(Scc_StateMachineTimerEnumType Timer);

/**********************************************************************************************************************
 *  Scc_StateMachineTimer_HasExpired
 *********************************************************************************************************************/
/*! \brief          Checks if the passed timer has expired
 *  \details        If TRUE is returned, an expired timer is indicated and the passed timer is then being disabled.
 *                  Therefore, if this function is called multiple times only the first call returns TRUE if the
 *                  timer is expired all other consecutive calls are going to return FALSE.
 *  \pre            -
 *  \param[in]      Timer        The timer to check
 *  \return         TRUE - timer has expired
 *  \return         FALSE - timer has not expired yet
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimerEnumType Timer);

/**********************************************************************************************************************
 *  Scc_StateMachineTimer_IsStarted
 *********************************************************************************************************************/
/*! \brief          Checks if the passed timer was started.
 *  \details        -
 *  \pre            -
 *  \param[in]      Timer        The timer to check
 *  \return         TRUE - timer was started
 *  \return         FALSE - timer was not started
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_StateMachineTimer_IsStarted(Scc_StateMachineTimerEnumType Timer);

/**********************************************************************************************************************
 *  Scc_StateMachineTimer_IsDisabled
 *********************************************************************************************************************/
/*! \brief          Checks if the passed timer is disabled/stopped.
 *  \details        -
 *  \pre            -
 *  \param[in]      Timer        The timer to check
 *  \return         TRUE - timer is disabled
 *  \return         FALSE - timer is active
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimerEnumType Timer);

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE */

#endif /* SCC_STATEMACHINETIMER_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_StateMachineTimer.h
 *********************************************************************************************************************/
