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
/*!        \file  Scc_StateMachineTimer.c
 *        \brief  Smart Charging Communication Source Code File
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

#define SCC_STATEMACHINETIMER_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_StateMachineTimer.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON )

# if ( SCC_DEV_ERROR_DETECT == STD_ON )
#  include "Det.h"
# endif /* SCC_DEV_ERROR_DETECT */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

#define SCC_STATEMACHINETIMER_EXPIRED   (0u)

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

SCC_LOCAL VAR(Scc_StateMachineTimerStructType, SCC_VAR_NOINIT) Scc_StateMachineTimers[Scc_StateMachineTimer_NumOfTimers];

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_StateMachineTimer_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateMachineTimer_Init(void)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  uint8_least timerIdx;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Disable all timers and set their timer value to 0 */
  for (timerIdx = 0; timerIdx < (uint8)Scc_StateMachineTimer_NumOfTimers; timerIdx++)
  {
    Scc_StateMachineTimers[timerIdx].TimerValue = 0u;
    Scc_StateMachineTimers[timerIdx].State = Scc_StateMachineTimer_Disabled;
  }
}

/**********************************************************************************************************************
 *  Scc_StateMachineTimer_ProcessTimers
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateMachineTimer_ProcessTimers(void)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  uint8_least timerIdx;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 For each timer */
  for (timerIdx = 0; timerIdx < (uint8)Scc_StateMachineTimer_NumOfTimers; timerIdx++)
  {
    /* #20 Decrement the timer if it is enabled and not yet expired */
    if (    (Scc_StateMachineTimers[timerIdx].State == Scc_StateMachineTimer_Enabled)
         && (Scc_StateMachineTimers[timerIdx].TimerValue != SCC_STATEMACHINETIMER_EXPIRED))
    {
      Scc_StateMachineTimers[timerIdx].TimerValue--;
    }
  }
}

/**********************************************************************************************************************
 *  Scc_StateMachineTimer_Start
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateMachineTimer_Start(Scc_StateMachineTimerEnumType Timer, Scc_StateMachineTimer_TimeValueType StartValue)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Assign the passed value to the timer */
  Scc_StateMachineTimers[Timer].TimerValue = StartValue;

  /* #20 Check if passed value is equal to 0u */
  if (StartValue == SCC_STATEMACHINETIMER_EXPIRED)
  {
    /* #30 Disable the timer */
    Scc_StateMachineTimers[Timer].State = Scc_StateMachineTimer_Disabled;
  }
  /* #40 Otherwise */
  else
  {
    /* #50 Enable the timer */
    Scc_StateMachineTimers[Timer].State = Scc_StateMachineTimer_Enabled;
  }
}

/**********************************************************************************************************************
 *  Scc_StateMachineTimer_Stop
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateMachineTimer_Stop(Scc_StateMachineTimerEnumType Timer)
{
  /* #10 Stope the passed timer */
  Scc_StateMachineTimers[Timer].State = Scc_StateMachineTimer_Disabled;
}

/**********************************************************************************************************************
 *  Scc_StateMachineTimer_HasExpired
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimerEnumType Timer)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  boolean timerExpired = FALSE;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if the timer is enabled and expired */
  if (    (Scc_StateMachineTimers[Timer].State == Scc_StateMachineTimer_Enabled)
      &&  (Scc_StateMachineTimers[Timer].TimerValue == SCC_STATEMACHINETIMER_EXPIRED))
  {
    /* #20 Disable the timer and indicate expired state */
    timerExpired = TRUE;
    Scc_StateMachineTimers[Timer].State = Scc_StateMachineTimer_Disabled;
  }

  return timerExpired;
}

/**********************************************************************************************************************
 *  Scc_StateMachineTimer_IsStarted
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_StateMachineTimer_IsStarted(Scc_StateMachineTimerEnumType Timer)
{
  /* #10 Check if the timer is enabled and therefore started */
  return Scc_StateMachineTimers[Timer].State == Scc_StateMachineTimer_Enabled;
}

/**********************************************************************************************************************
 *  Scc_StateMachineTimer_IsDisabled
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimerEnumType Timer)
{
  /* #10 Check if the timer is disabled */
  return Scc_StateMachineTimers[Timer].State == Scc_StateMachineTimer_Disabled;
}

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* SCC_ENABLE_STATE_MACHINE */

/**********************************************************************************************************************
 *  END OF FILE: Scc_StateMachineTimer.c
 *********************************************************************************************************************/
