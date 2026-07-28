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
/*!        \file  Scc_DIN70121_StateM.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to DIN SPEC 70121
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_DIN70121_STATEM_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
/*lint -e546 */ /* Suppress the 'Suspicious use of &' warning because the '&' is required by MISRA per Id 1502. */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_DIN70121_StateM.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON && (defined(SCC_SCHEMA_DIN) && SCC_SCHEMA_DIN != 0u) )

#include "Scc_StateM_ParamsCfg.h"
#include "Scc_DIN70121_TimerCfg.h"

#include "Scc.h"
#include "Scc_StateM_InterfaceCfg.h"
#include "Scc_StateM_Vector.h"
#include "Scc_StateMachineTimer.h"

#if ( SCC_DEV_ERROR_DETECT == STD_ON )
# include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */


/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/* other variables */
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

SCC_LOCAL VAR(Scc_DIN70121_StateMLocalStructType, SCC_VAR_NOINIT) Scc_DIN70121_StateMLocal;

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  Scc_DIN70121_StateM<StateMachineState>_Prepare
 *********************************************************************************************************************/
/*! \brief          Prepares all parameters needed to transmit the associated request message
 *  \details        Set all parameters, the message trigger and the cyclic message trigger.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
 /* see pattern Scc_DIN70121_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMSessionSetup_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMServiceDiscovery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMPaymentServiceSelection_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMAuthorization_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMChargeParameterDiscovery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMCableCheck_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMPreCharge_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMCurrentDemand_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMWeldingDetection_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMSessionStop_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_DIN70121_StateM<StateMachineState>_Wait
 *********************************************************************************************************************/
/*! \brief          Wait for reception of the associated response message.
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
 /* see pattern Scc_DIN70121_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMSessionSetup_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMServiceDiscovery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMPaymentServiceSelection_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMAuthorization_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMChargeParameterDiscovery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMCableCheck_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMPreCharge_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMCurrentDemand_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMWeldingDetection_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMSessionStop_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_DIN70121_StateM<StateMachineState>_Process
 *********************************************************************************************************************/
/*! \brief          Processes the received response message
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMSessionSetup_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMServiceDiscovery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMPaymentServiceSelection_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMAuthorization_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMChargeParameterDiscovery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMCableCheck_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMPreCharge_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMCurrentDemand_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMWeldingDetection_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_DIN70121_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMSessionStop_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);



/**********************************************************************************************************************
 *  Scc_DIN70121_StateMGlobalParamCheck
 *********************************************************************************************************************/
/*! \brief          Global parameter check during DIN70121 based communication
 *  \details        -
 *  \param[out]     ErrorInformation              Contains the information which was set by the function if return value is failed
 *  \return         Scc_StateMachineState_Done    No error was detected
 *  \return         Scc_StateMachineState_Failed  An error was detected
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMGlobalParamCheck(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMGlobalTimerCheck
 *********************************************************************************************************************/
/*! \brief          Global timer check during DIN70121 based communication
 *  \details        -
 *  \param[in]      CurrentState                  The current state of the state machine
 *  \param[out]     ErrorInformation              Contains the information which was set by the function if return value is failed
 *  \return         Scc_StateMachineState_Done    No error was detected
 *  \return         Scc_StateMachineState_Failed  An error was detected
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMGlobalTimerCheck(
  Scc_StateM_StateType CurrentState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMErrorHandling
 *********************************************************************************************************************/
/*! \brief          Global error handling during DIN70121 based communication
 *  \details        -
 *  \param[out]     NextState                     The next state to execute if return value indicates success
 *  \param[in]      ErrorReason                   Information why the error handling is triggered
 *  \return         Scc_StateMachineState_Done    Error handling was successfull
 *  \return         Scc_StateMachineState_Failed  Error handling failed
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMErrorHandling(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  Scc_StateM_StateMachineErrorType ErrorReason);



/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMGlobalParamCheck
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */ /* PRQA S 6010 1 */ /* MD_MSR_STPTH */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMGlobalParamCheck(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  Scc_StateM_ControlPilotStateType controlPilotState = Scc_ControlPilotState_None;
  Scc_DetailedErrorEnumType detailedError;

  /* ----- Implementation ------------------------------------------------------------ */
  detailedError = Scc_StateM_GetDetailedErrorChannel(SCC_CHANNEL_DEFAULT);
  /* #10 Check for unexpected messages */
  if (detailedError == SccDetailedError_General_MainRxMessageUnexpectedMessage)
  {
    /* #20 Propagate error information that an unexpected message was received */
    *ErrorInformation = Scc_SMER_UnexpectedMessage;
    retVal = Scc_StateMachineState_Failed;
    /* #30 Clear error code */
    Scc_StateM_SetDetailedErrorChannel(SccDetailedError_No_Error, SCC_CHANNEL_DEFAULT);
  }

  /* #40 Get the current CP state */
  Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);

  /* #50 Check if the CP changed */
  if (controlPilotState != Scc_DIN70121_StateMLocal.LastControlPilotState)
  {
    /* #60 Update the function-local control pilot status */
    Scc_DIN70121_StateMLocal.LastControlPilotState = controlPilotState;

    /* #70 [V2G-DC-655]: Check for error state (A = not connected, E = no Grid connected, F = EVSE not available) or CP is turned off */
    if (controlPilotState == Scc_ControlPilotState_State_A_E_F)
    {
      /* #80 Plug out while in active charging session, propagate invalid CP state */
      /* Error shutdown */
      *ErrorInformation = Scc_SMER_InvalidControlPilotState;
      retVal = Scc_StateMachineState_Failed;
    }
  }

  /* #90 Check if PWM monitoring is enabled */
  if (Scc_DIN70121_StateMLocal.EnablePWMDutyCycleMonitoring == TRUE)
  {
    Scc_StateM_PWMStateType pwmState = Scc_PWMState_ChargingNotAllowed;

    /* #100 [V2G-DC-656]: Check if PWM state is valid */
    Scc_StateM_InterfaceCfg_Get_PWMState(&pwmState);
    if (pwmState != Scc_PWMState_HLCOnly)
    {
      /* #110 No: Propagate invalid CP state */
      *ErrorInformation = Scc_SMER_InvalidControlPilotState;
      retVal = Scc_StateMachineState_Failed;
    }
  }

  /* #120 [V2G-DC-648], [V2G-DC-673]: Check for user interaction based shutdown request */
  if (controlPilotState != Scc_ControlPilotState_State_A_E_F)
  {
    Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

    /* #130 Get charging control information from application and check if it wants to stop */
    Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);
    if (chargingControl == Scc_ChargingControl_StopCharging)
    {
      /* #140 Yes: Store shutdown request as shutdown sequence is handled in each sub state.
       * Depending on the state different behaviour is necessary. */
      Scc_DIN70121_StateMLocal.UserInteraction.ShutdownRequested = TRUE;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMGlobalTimerCheck
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMGlobalTimerCheck(
  Scc_StateM_StateType CurrentState, /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(CurrentState);                                                                              /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G-DC-361]: Monitor V2G_EVCC_Msg_Timer  */
  if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_SequencePerformance) == TRUE)
  {
    /* #20 Propagate error information that the timer has expired */
    *ErrorInformation = Scc_SMER_Timer_SequencePerformanceTimer;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #30 [V2G-DC-371]: Monitor V2G_EVCC_CommuncationSetup_Timer */
  else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_DIN70121_CommunicationSetup) == TRUE)
  {
    /* #40 Propagate error information that the timer has expired */
    *ErrorInformation = Scc_SMER_Timer_CommunicationSetupTimer;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #50 [V2G-DC-375]: Monitor V2G_EVCC_ReadyToCharge_Timer */
  else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_ReadyToCharge) == TRUE)
  {
    /* #60 Propagate error information that the timer has expired */
    *ErrorInformation = Scc_SMER_Timer_ReadyToChargeTimer;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #70 [V2G-DC-380]: Monitor V2G_EVCC_CableCheck_Timer */
  else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_CableCheck) == TRUE)
  {
    /* #80 Propagate error information that the timer has expired */
    *ErrorInformation = Scc_SMER_Timer_CableCheckTimer;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #90 [V2G-DC-385]: Monitor V2G_EVCC_PreCharge_Timer */
  else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_PreCharge) == TRUE)
  {
    /* #100 Propagate error information that the timer has expired */
    *ErrorInformation = Scc_SMER_Timer_PreChargeTimer;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #110 No timer expired */
  else
  {
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMErrorHandling
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMErrorHandling(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  Scc_StateM_StateMachineErrorType ErrorReason)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Report the error reason to the application */
  Scc_StateM_InterfaceCfg_Set_StateMachineError(ErrorReason);

  /* Evaluate the passed error reason */
  /* #20 Reason is invalid control pilot state */
  if (ErrorReason == Scc_SMER_InvalidControlPilotState)
  {
    /* #30 Yes: reset the current session id and abort with error shutdown */
    /* Reset SessionID */
    (void)Scc_ResetSessionID(TRUE);
    retVal = Scc_StateMachineState_Failed;
  }
  /* #40 Reason is [V2G-DC-651], the received response cannot be processed */
  if (Scc_StateM_RxCore.StackError[SCC_CHANNEL_DEFAULT] == Scc_StackError_InvalidRxParameter)
  {
    /* #50 Yes: Abort with error shutdown */
    retVal = Scc_StateMachineState_Failed;
  }
  /* #60 Reason is [V2G-DC-402], unexpected response */
  else if (Scc_StateM_RxCore.StackError[SCC_CHANNEL_DEFAULT] == Scc_StackError_InvalidRxMessage)
  {
    /* #70 Yes: Abort with error shutdown */
    retVal = Scc_StateMachineState_Failed;
  }
  /* #80 Reason is [V2G-DC-649] or [V2G-DC-652], a negative response code */
  else if (Scc_StateM_RxCore.StackError[SCC_CHANNEL_DEFAULT] == Scc_StackError_NegativeResponseCode)
  {
    switch (Scc_DIN70121_StateMLocal.ErrorMode)
    {
      /* #90 [V2G-DC-653]: Negative response before charge parameter discovery */
      case Scc_DinErrorBeforeChargeParameterDiscovery:
      {
        /* #100 Decide whether it is a non-critical shutdown [V2G-DC-649] or a critical [V2G-DC-652] based on the PWM state */
        Scc_StateM_PWMStateType pwmState = Scc_PWMState_ChargingNotAllowed;
        /* Detect if CP oscillator is turned off */
        Scc_StateM_InterfaceCfg_Get_PWMState(&pwmState);
        if (pwmState != Scc_PWMState_ChargingNotAllowed)
        {
          /* #110 [V2G-DC-649]: CP Oscillator still active, continue with session stop (non-critical) */
          *NextState = Scc_SMS_SessionStop;
        }
        else
        {
          /* #120 [V2G-DC-652]: CP Oscillator turned off, abort with error shutdown (critical) */
          retVal = Scc_StateMachineState_Failed;
        }
        break;
      }
      /* #130 [V2G-DC-653]: Negative response after charge parameter discovery */
      case Scc_DinErrorAfterChargeParameterDiscovery:
      {
        /* #140 Abort with error shutdown */
        retVal = Scc_StateMachineState_Failed;
        break;
      }

      default:
      {
        /* This should never happen */
        retVal = Scc_StateMachineState_Failed;
        break;
      }
    }
  }
  /* #150 All other errors are considered as critical */
  else
  {
    /* #160 Abort with error shutdown */
    retVal = Scc_StateMachineState_Failed;
  }

  /* #170 Check if retVal was set to failed */
  if (retVal == Scc_StateMachineState_Failed)
  {
    /* #180 Yes: reset the current session id */
    (void)Scc_ResetSessionID(TRUE);
  }

  return retVal;
}


/**********************************************************************************************************************/
/* Session Setup                                                                                                      */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_DIN70121_StateMSessionSetup_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMSessionSetup_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_StateM_ControlPilotStateType controlPilotState = Scc_ControlPilotState_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Get the current CP status from the application */
  Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);

  /* #20 [V2G-DC-738]: Check CP state */
  if (controlPilotState != Scc_ControlPilotState_State_B)
  {
    /* #30 CP state is not "B", wait until it is set to "B" */
    retVal = Scc_StateMachineState_Pending;
  }
  else
  {
    /* #40 [V2G-DC-405]: Trigger the SessionSetup request */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_SessionSetup, FALSE);

    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMSessionSetup_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMSessionSetup_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G-DC-405], [V2G-DC-740]: Wait for session setup response */
  /* #20 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_SessionSetup_OK)
  {
    /* #30 [V2G-DC-372]: Stop the CommunicationSetup timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_DIN70121_CommunicationSetup);
    /* #40 [V2G-DC-740]: Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #50 Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_SessionSetup_Failed)
  {
    /* #60 [V2G-DC-372]: Stop the CommunicationSetup timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_DIN70121_CommunicationSetup);
    /* #70 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #80 Otherwise */
  else
  {
    /* #90 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMSessionSetup_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMSessionSetup_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G-DC-407]: Trigger a ServiceDiscoveryReq message */
  *NextState = Scc_SMS_ServiceDiscovery;

  /* #20 [V2G-DC-648]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.ShutdownRequested == TRUE)
  {
    /* #30 Set next state to SessionStop */
    *NextState = Scc_SMS_SessionStop;
  }

  return Scc_StateMachineState_Done;
}


/**********************************************************************************************************************/
/* Service Discovery                                                                                                  */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_DIN70121_StateMServiceDiscovery_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMServiceDiscovery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G-DC-648]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.ShutdownRequested == TRUE)
  {
    /* #20 Yes: Go to wait state since NextState can be changed to SessionStop only in Process */
    Scc_DIN70121_StateMLocal.UserInteraction.MoveToProcess = TRUE;
  }
  /* #30 Otherwise */
  else
  {
    /* #40 [V2G-DC-407]: Trigger the ServiceDiscovery request */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_ServiceDiscovery, FALSE);
  }

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMServiceDiscovery_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMServiceDiscovery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G-DC-648]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.MoveToProcess == TRUE)
  {
    /* #20 Yes: Go to Process state since NextState can be changed to SessionStop only in Process */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G-DC-407], [V2G-DC-741]:  Wait for service discovery response */
  /* #40 Otherwise check if valid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_ServiceDiscovery_OK)
  {
    /* #50 [V2G-DC-741]: Proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #60 Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_ServiceDiscovery_Failed)
  {
    /* #70 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #80 Otherwise */
  else
  {
    /* #90 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMServiceDiscovery_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMServiceDiscovery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  uint8 EnergyTransferModeFlags = 0;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G-DC-648]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.ShutdownRequested == TRUE)
  {
    /* #20 Proceed with session stop */
    *NextState = Scc_SMS_SessionStop;
  }
  /* #30 Otherwise */
  else
  {
    /* #40 [V2G-DC-409]: Proceed with payment service selection */
    *NextState = Scc_SMS_PaymentServiceSelection;

    /* #50 [V2G-DC-632]: Check received energy transfer modes */
    /* #60 Is mode DC_extended */
    if (Scc_DIN70121_StateMLocal.RxEVSE.EnergyTransferMode.DC_Core == SCC_STATEM_ENERGY_TRANSFER_MODE_ENABLED)
    {
      /* #70 Store mode for communication session */
      EnergyTransferModeFlags = (uint8)Scc_EnergyTransferMode_DC_Core;
    }
    /* #80 Is mode DC_core */
    else if ((Scc_DIN70121_StateMLocal.RxEVSE.EnergyTransferMode.DC_Extended == SCC_STATEM_ENERGY_TRANSFER_MODE_ENABLED))
    {
      /* #90 Store mode for communication session */
      EnergyTransferModeFlags = (uint8)Scc_EnergyTransferMode_DC_Extended;
    }
    /* #100 Otherwise */
    else
    {
      /* #110 Propagate invalid energy transfer mode error */
      *ErrorInformation = Scc_SMER_ServiceDiscovery_InvalidEnergyTransferMode;
      retVal = Scc_StateMachineState_Failed;
    }

    /* #120 Propagate the supported energy transfer modes to the application */
    Scc_StateM_InterfaceCfg_Set_EnergyTransferModeFlags(EnergyTransferModeFlags);
  }

  return retVal;
}


/**********************************************************************************************************************/
/* Service Payment Selection                                                                                          */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_DIN70121_StateMPaymentServiceSelection_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMPaymentServiceSelection_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G-DC-648]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.ShutdownRequested == TRUE)
  {
    /* #20 Yes: Go to wait state since NextState can be changed to SessionStop only in Process */
    Scc_DIN70121_StateMLocal.UserInteraction.MoveToProcess = TRUE;
  }
  /* #30 Otherwise */
  else
  {
    /* #40 [V2G-DC-409]: Trigger the PaymentServiceSelection request  */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_PaymentServiceSelection, FALSE);
  }

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMPaymentServiceSelection_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMPaymentServiceSelection_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G-DC-648]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.MoveToProcess == TRUE)
  {
    /* #20 Yes: Go to Process state since NextState can be changed to SessionStop only in Process */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G-DC-409], [V2G-DC-742]: Wait for payment service selection response */
  /* #40 Otherwise check if valid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_PaymentServiceSelection_OK)
  {
    /* #50 [V2G-DC-742]: Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #60 Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_PaymentServiceSelection_Failed)
  {
    /* #70 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #80 Otherwise */
  else
  {
    /* #90 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMPaymentServiceSelection_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMPaymentServiceSelection_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G-DC-648]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.ShutdownRequested == TRUE)
  {
    /* #20 Set next state to SessionStop */
    *NextState = Scc_SMS_SessionStop;
  }
  else
  {
    /* #30 [V2G-DC-414]: Proceed with contract authentication */
    *NextState = Scc_SMS_Authorization;
  }

  return Scc_StateMachineState_Done;
}


/**********************************************************************************************************************/
/* Contract Authentication                                                                                            */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_DIN70121_StateMAuthorization_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMAuthorization_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G-DC-648]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.ShutdownRequested == TRUE)
  {
    /* #20 Yes: Go to wait state since NextState can be changed to SessionStop only in Process */
    Scc_DIN70121_StateMLocal.UserInteraction.MoveToProcess = TRUE;
  }
  /* #30 Otherwise */
  else
  {
    /* #40 [V2G-DC-414]: Trigger the contract authentication request */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_Authorization, TRUE);
  }

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMAuthorization_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMAuthorization_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G-DC-648]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.MoveToProcess == TRUE)
  {
    /* #20 Yes: Go to Process state since NextState can be changed to SessionStop only in Process */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G-DC-414], [V2G-DC-743]: Wait for contract authentication response */
  /* #40 Otherwise check if valid response was received */
  else if (    (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_Authorization_OK)
      &&  (Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] == TRUE))
  {
    /* #50 [V2G-DC-740]: Indicate received response and proceed with message processing */
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;
    /* #60 Check if EVSEProcessing is set to Ongoing */
    if (Scc_DIN70121_StateMLocal.RxEVSE.EVSEProcessing == Scc_EVSEProcessing_Ongoing)
    {
      /* #70 Start delay timer to delay the next contract authorization request based on configured delay time */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_AuthorizationNextReqDelay());
    }

    retVal = Scc_StateMachineState_Done;
  }
  /* #80 Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_Authorization_Failed)
  {
    /* #90 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #100 Otherwise */
  else
  {
    /* #110 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMAuthorization_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMAuthorization_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation )                                  /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G-DC-648]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.ShutdownRequested == TRUE)
  {
    /* #20 Set next state to SessionStop */
    *NextState = Scc_SMS_SessionStop;
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G-DC-490]: Check if EVSEProcessing is set to Finished */
  else if (Scc_DIN70121_StateMLocal.RxEVSE.EVSEProcessing == Scc_EVSEProcessing_Finished)
  {
    /* #40 Stop delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* #50 [V2G-DC-490]: Proceed with charge parameter discovery */
    *NextState = Scc_SMS_ChargeParameterDiscovery;
    retVal = Scc_StateMachineState_Done;
  }
  /* #60 [V2G-DC-492]: Resend the ContractAuthenticationReq message if EVSEProcessing is equal to Ongoing */
  else /* Scc_EVSEProcessing_Ongoing */
  {
    *NextState = Scc_SMS_Authorization;

    /* #70 Check if delay timer is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #80 The next request can be send */
      retVal = Scc_StateMachineState_Done;
    }
    /* #90 Check if delay timer has expired */
    else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #100 The next request can be send now */
      retVal = Scc_StateMachineState_Done;
    }
    /* #110 Otherwise */
    else
    {
      /* #120 Wait until the delay timer has expired */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  return retVal;
}


/**********************************************************************************************************************/
/* Charge Parameter Discovery                                                                                         */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_DIN70121_StateMChargeParameterDiscovery_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMChargeParameterDiscovery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Get the current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* #20 [V2G-DC-648]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.ShutdownRequested == TRUE)
  {
    /* #30 Yes: Go to wait state since NextState can be changed to SessionStop only in Process */
    Scc_DIN70121_StateMLocal.UserInteraction.MoveToProcess = TRUE;
    retVal = Scc_StateMachineState_Done;
  }
  /* #40 Check if the charging control is unequal to NegotiateChargingParameters */
  else if (chargingControl != Scc_ChargingControl_NegotiateChargingParameters)
  {
    /* #50 Wait for the application to become ready */
    /* pending */
  }
  /* #60 Otherwise */
  else
  {
    /* #70 Get the selected EnergyTransferMode from application */
    Scc_DIN70121_StateMLocal.TxEVSE.EnergyTransferMode = Scc_EnergyTransferMode_None;
    Scc_StateM_InterfaceCfg_Get_EnergyTransferMode(&Scc_DIN70121_StateMLocal.TxEVSE.EnergyTransferMode);

    /* #80 [V2G-DC-625]: Only Dc_core and Dc_extended are allowed. Validate user input */
    if (   (Scc_DIN70121_StateMLocal.TxEVSE.EnergyTransferMode != Scc_EnergyTransferMode_DC_Core)
        && (Scc_DIN70121_StateMLocal.TxEVSE.EnergyTransferMode != Scc_EnergyTransferMode_DC_Extended))
    {
      /* #90 Invalid energry transfer mode set by application detected. */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      /* #100 If SCC_DEV_ERROR_REPORT is enabled, report error */
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_DIN70121_STATEM_CHRGPARAM_CBK, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
    }
    /* #110 Otherwise */
    else
    {
      /* #120 [V2G-DC-653]: Update error handling mode as it is different after charge parameter discovery request was send */
      Scc_DIN70121_StateMLocal.ErrorMode = Scc_DinErrorAfterChargeParameterDiscovery;
      /* #130 Trigger the ChargeParameterDiscovery request and set cyclic message trigger to true */
      Scc_StateM_SetMsgTrig(Scc_MsgTrig_ChargeParameterDiscovery, TRUE);
      retVal = Scc_StateMachineState_Done;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMChargeParameterDiscovery_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMChargeParameterDiscovery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G-DC-648]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.MoveToProcess == TRUE)
  {
    /* #20 Yes: Go to Process state since NextState can be changed to SessionStop only in Process */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G-DC-744]:  Wait for charge parameter discovery response */
  /* #40 Otherwise check if valid response was received */
  else if ( (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_ChargeParameterDiscovery_OK)
         && (Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] == TRUE) )
  {
    /* #50 [V2G-DC-744]: Indicate received response and proceed with message processing */
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;

    /* #60 Check if EVSEProcessing is set to Ongoing */
    if (Scc_DIN70121_StateMLocal.RxEVSE.EVSEProcessing == Scc_EVSEProcessing_Ongoing)
    {
      /* #70 Start delay timer to delay the next charge parameter discovery request based on configured delay time */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_ChargeParameterDiscoveryNextReqDelay());
    }

    /* #80 [V2G-DC-656]: Enable PWM monitoring after a charge parameter discovery response was received */
    Scc_DIN70121_StateMLocal.EnablePWMDutyCycleMonitoring = TRUE;

    retVal = Scc_StateMachineState_Done;
  }
  /* #90 Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_ChargeParameterDiscovery_Failed)
  {
    /* #100 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #110 Otherwise */
  else
  {
    /* #120 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMChargeParameterDiscovery_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMChargeParameterDiscovery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G-DC-648]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.ShutdownRequested == TRUE)
  {
    /* #20 Set next state to SessionStop */
    *NextState = Scc_SMS_SessionStop;
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G-DC-415]: Check if EVSEProcessing is set to Finished */
  else if (Scc_DIN70121_StateMLocal.RxEVSE.EVSEProcessing == Scc_EVSEProcessing_Finished)
  {
    /* #40 Stop the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

    /* #50 [V2G-DC-415]: Proceed with cable check */
    *NextState = Scc_SMS_CableCheck;
    retVal = Scc_StateMachineState_Done;
  }
  /* #60 [V2G-DC-493]: Resend the ChargeParameterDiscoveryReq message if EVSEProcessing is equal to Ongoing */
  else /* EVSEProcessing_Ongoing */
  {
    /* #70 Continue with charge parameter discovery */
    *NextState = Scc_SMS_ChargeParameterDiscovery;

    /* #80 Check if delay timer is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #90 The next request can be send */
      retVal = Scc_StateMachineState_Done;
    }
    /* #100 Check if delay timer has expired */
    else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #110 The next request can be send */
      retVal = Scc_StateMachineState_Done;
    }
    /* #120 Otherwise */
    else
    {
      /* #130 Wait until the delay timer has expired */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  return retVal;
}


/**********************************************************************************************************************/
/* Cable Check                                                                                                        */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_DIN70121_StateMCableCheck_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMCableCheck_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_StateM_ControlPilotStateType controlPilotState = Scc_ControlPilotState_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Get the current CP state from application */
  Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);

  /* #20 [V2G-DC-648]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.ShutdownRequested == TRUE)
  {
    /* #30 Yes: Go to wait state since NextState can be changed to SessionStop only in Process */
    Scc_DIN70121_StateMLocal.UserInteraction.MoveToProcess = TRUE;
    retVal = Scc_StateMachineState_Done;
  }
  /* #40 [V2G-DC-501]: Otherwise check if current CP state is set to C or D */
  else if (controlPilotState != Scc_ControlPilotState_State_C_D)
  {
    /* #50 No: Wait until CP state is set by application */
    retVal = Scc_StateMachineState_Pending;
  }
  /* #60 Otherwise */
  else
  {
    /* #70 [V2G-DC-415]: Trigger the cable check request and set cyclic message trigger to true */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_CableCheck, TRUE);

    /* #80 [V2G-DC-377]: Start the cable check timeout only once */
    /* Start the cable check timer only for the first time a CableCheckReq message
     * is sent in the communication session. Consecutive cable check messages issued
     * due to an "Ongoing" responses should not restart the timer. */
    if (Scc_StateMachineTimer_IsStarted(Scc_StateMachineTimer_CableCheck) == FALSE)
    {
      /* #90 Start cable check timer based on configured timeout value */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_CableCheck, Scc_StateM_ParamCfg_Get_CableCheckTimeout());
    }

    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMCableCheck_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMCableCheck_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;


  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G-DC-648]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.MoveToProcess == TRUE)
  {
    /* #20 Yes: Go to Process state since NextState can be changed to SessionStop only in Process */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G-DC-415], [V2G-DC-745]: Wait for cable check response */
  /* #40 Otherwise check if valid response was received */
  else if (   (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_CableCheck_OK)
      && (Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] == TRUE))
  {
    /* #50 [V2G-DC-745]: Indicate received response and proceed with message processing */
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;
    /* #60 Check if EVSEProcessing is set to Ongoing */
    if (Scc_DIN70121_StateMLocal.RxEVSE.EVSEProcessing == Scc_EVSEProcessing_Ongoing)
    {
      /* #70 Start delay timer to delay the next cable check request based on configured delay time */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_CableCheckNextReqDelay());
    }

    retVal = Scc_StateMachineState_Done;
  }
  /* #80 Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_CableCheck_Failed)
  {
    /* #90 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #100 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMCableCheck_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMCableCheck_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G-DC-648]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.ShutdownRequested == TRUE)
  {
    /* #20 Stop the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* Stop the V2G_EVCC_CableCheckTimer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_CableCheck);
    /* #30 Set next state to SessionStop */
    *NextState = Scc_SMS_SessionStop;
    retVal = Scc_StateMachineState_Done;
  }
  /* #40 [V2G-DC-417]: Check if EVSEProcessing is set to Finished */
  else if (Scc_DIN70121_StateMLocal.RxEVSE.EVSEProcessing == Scc_EVSEProcessing_Finished)
  {
    /* #50 Stop the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* #60 [V2G-DC-381]: Stop the V2G_EVCC_CableCheckTimer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_CableCheck);

    /* [V2G-DC-417], [V2G-DC-CharIN-061], [V2G-DC-CharIN-064] */
    /* #70 [V2G-DC-417]: Proceed with pre charge */
    *NextState = Scc_SMS_PreCharge;

    retVal = Scc_StateMachineState_Done;
  }
  /* #80 [V2G-DC-418]: Resend the CableCheckReq message if EVSEProcessing is equal to Ongoing */
  /* [V2G-DC-CharIN-058] */
  else /* EVSEProcessing_Ongoing */
  {
    *NextState = Scc_SMS_CableCheck;

    /* #90 Check if delay timer is disabled */
    if  (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #100 The next request can be send */
      retVal = Scc_StateMachineState_Done;
    }
    /* #110 Check if delay timer has expired */
    else if ((Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE))
    {
      /* #120 The next request can be send */
      retVal = Scc_StateMachineState_Done;
    }
    /* #130 Otherwise */
    else
    {
      /* #140 Wait until the delay timer has expired */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  return retVal;
}


/**********************************************************************************************************************/
/* Pre Charge                                                                                                         */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_DIN70121_StateMPreCharge_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMPreCharge_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G-DC-648]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.ShutdownRequested == TRUE)
  {
    /* #20 Yes: Go to wait state since NextState can be changed to SessionStop only in Process */
    Scc_DIN70121_StateMLocal.UserInteraction.MoveToProcess = TRUE;
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 Otherwise */
  else
  {
    Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_StartPreCharge;

    /* #40 Get the current charging control command */
    Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

    /* #50 Check if the application is ready to continue */
    if (   (chargingControl == Scc_ChargingControl_StartPreCharge)
        || (chargingControl == Scc_ChargingControl_PreChargeCompleted))
    {
      /* #60 [V2G-DC-417]: Trigger the pre charge request */
      /* #70 Set the cyclic trigger  and set cyclic message trigger to true */
      Scc_StateM_SetMsgTrig(Scc_MsgTrig_PreCharge, TRUE);

      /* #80 [V2G-DC-382]: Start the pre charge timeout only once */
      /* Start the pre charge timer only for the first time a PreCharge message
       * is sent in the communication session. Consecutive pre charge messages issued
       * due to an unmatching output voltage at EVSE should not restart the timer. */
      if (Scc_StateMachineTimer_IsStarted(Scc_StateMachineTimer_PreCharge) == FALSE)
      {
        /* #90 Start pre charge timer based on configured timeout value */
        Scc_StateMachineTimer_Start(Scc_StateMachineTimer_PreCharge, Scc_StateM_ParamCfg_Get_PreChargeTimeout());
      }
      retVal = Scc_StateMachineState_Done;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMPreCharge_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMPreCharge_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;


  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G-DC-648]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.MoveToProcess == TRUE)
  {
    /* #20 Yes: Go to Process state since NextState can be changed to SessionStop only in Process */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G-DC-417], [V2G-DC-746]: Otherwise wait for pre charge response */
  else if (   (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_PreCharge_OK)
      && (Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] == TRUE))
  {
    /* #40 [V2G-DC-746]: Indicate received response and proceed with message processing */
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;
    /* #50 Start delay timer to delay the next pre charge request based on configured delay time */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_PreChargeNextReqDelay());

    retVal = Scc_StateMachineState_Done;
  }
  /* #60 Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_PreCharge_Failed)
  {
    /* #70 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #80 Otherwise */
  else
  {
    /* #90 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMPreCharge_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMPreCharge_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Get the current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* #20 [V2G-DC-648]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.ShutdownRequested == TRUE)
  {
    /* #30 Stop the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* Stop the V2G_EVCC_PreCharge_Timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_PreCharge);
    /* #40 Set next state to SessionStop */
    *NextState = Scc_SMS_SessionStop;
    retVal = Scc_StateMachineState_Done;
  }
  /* #50 [V2G-DC-421]: Check if application has detected an sufficiently adjusted EVSE output voltage */
  else if (chargingControl == Scc_ChargingControl_PreChargeCompleted)
  {
    /* #60 Stop the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* #70 [V2G-DC-386]: Stop the V2G_EVCC_PreCharge_Timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_PreCharge);

    /* #80 [V2G-DC-421]: Proceed with power delivery */
    *NextState = Scc_SMS_PowerDelivery;

    retVal = Scc_StateMachineState_Done;
  }
  /* #90 [V2G-DC-422]: EVSE output voltage is not sufficiently adjusted */
  else
  {
    /* #100 Continue with PreCharge */
    *NextState = Scc_SMS_PreCharge;

    /* #110 Check if delay timer is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #120 The next request can be send */
      retVal = Scc_StateMachineState_Done;
    }
    /* #130 Check if delay timer has expired */
    else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #140 The next request can be send */
      retVal = Scc_StateMachineState_Done;
    }
    /* #150 Otherwise */
    else
    {
      /* #160 Wait until the delay timer has expired */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  return retVal;
}


/**********************************************************************************************************************/
/* Power Delivery                                                                                                     */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_DIN70121_StateMPowerDelivery_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMPowerDelivery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Get the current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* #20 [V2G-DC-648]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.ShutdownRequested == TRUE)
  {
    /* #30 [V2G-DC-673]: Check if a power delivery with ReadyToChargeState equal to TRUE was sent */
    if (Scc_DIN70121_StateMLocal.UserInteraction.PowerDeliveryWithReadyToChargeSent == TRUE)
    {
      /* #40 Trigger the power delivery request with ReadyToChargeState set to FALSE */
      Scc_StateM_SetMsgTrig(Scc_MsgTrig_PowerDelivery, FALSE);

      Scc_DIN70121_StateMLocal.TxEVSE.ChargeStatus = Scc_ChargeStatus_Stopping;
    }
    /* #50 Otherwise */
    else
    {
      /* #60 [V2G-DC-648]: Go to session stop */
    }

    retVal = Scc_StateMachineState_Done;
  }
  /* #70 Check if the charging control indicates that charging shall be started */
  else if (chargingControl == Scc_ChargingControl_StartPowerDelivery)
  {
    /* #80 [V2G-DC-421]: Trigger a power delivery request with ReadyToChargeState set to TRUE */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_PowerDelivery, FALSE);

    Scc_DIN70121_StateMLocal.TxEVSE.ChargeStatus = Scc_ChargeStatus_Starting;
    Scc_DIN70121_StateMLocal.UserInteraction.PowerDeliveryWithReadyToChargeSent = TRUE;

    retVal = Scc_StateMachineState_Done;
  }
  /* #90 Check if the charging control indicates that welding detection shall be started */
  else if (chargingControl == Scc_ChargingControl_StartWeldingDetection)
  {
    /* #100 [V2G-DC-427]: Trigger the PowerDelivery request with ReadyToChargeState set to FALSE */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_PowerDelivery, FALSE);
    Scc_DIN70121_StateMLocal.TxEVSE.ChargeStatus = Scc_ChargeStatus_Stopping;

    retVal = Scc_StateMachineState_Done;
  }
  /* #110 Check if the charging control indicates that charging shall be stopped or paused */
  else if (chargingControl == Scc_ChargingControl_StopCharging)
  {
    /* #120 [V2G-DC-420], [V2G-DC-428]: Trigger the PowerDelivery request with ReadyToChargeState set to FALSE */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_PowerDelivery, FALSE);

    Scc_DIN70121_StateMLocal.TxEVSE.ChargeStatus = Scc_ChargeStatus_Stopping;

    retVal = Scc_StateMachineState_Done;
  }
  /* #130 Otherwise */
  else
  {
    /* #140 Wait until application becomes ready */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMPowerDelivery_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMPowerDelivery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G-DC-648]: Check if user wants to shutdown and ReadyToChargeState equals FALSE */
  if (   (Scc_DIN70121_StateMLocal.UserInteraction.ShutdownRequested == TRUE)
      && (Scc_DIN70121_StateMLocal.UserInteraction.PowerDeliveryWithReadyToChargeSent == FALSE))
  {
    /* #20 Do not sent a power delivery request message -> go to session stop */
    /* #30 Stop the ready to charge timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ReadyToCharge);

    retVal = Scc_StateMachineState_Done;
  }
  /* #40 [V2G-DC-747]: Wait for power delivery response */
  /* #50 Check if valid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_PowerDelivery_OK)
  {
    /* #60 [V2G-DC-747]: Indicate received response and proceed with message processing */
    /* #70 [V2G-DC-376]: Stop the V2G_EVCC_ReadyToCharge_Timer */
    /* Timer is started in common part as it is started at the beginning
     * of the charging session and not the communication session. */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ReadyToCharge);

    retVal = Scc_StateMachineState_Done;
  }
  /* #80 Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_PowerDelivery_Failed)
  {
    /* #90 [V2G-DC-376]: Stop V2G_EVCC_ReadyToCharge_Timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ReadyToCharge);

    /* #100 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #110 Otherwise */
  else
  {
    /* #120 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMPowerDelivery_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMPowerDelivery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G-DC-648]: Check if user wants to shutdown and ReadyToChargeState equals FALSE */
  if (   (Scc_DIN70121_StateMLocal.UserInteraction.ShutdownRequested == TRUE)
      && (Scc_DIN70121_StateMLocal.UserInteraction.PowerDeliveryWithReadyToChargeSent == FALSE))
  {
    /* #20 Do not sent a power delivery request message -> go to session stop */
    *NextState = Scc_SMS_SessionStop;
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G-DC-424]: Check if charging shall be started */
  else if (Scc_DIN70121_StateMLocal.TxEVSE.ChargeStatus == Scc_ChargeStatus_Starting)
  {
    /* #40 [V2G-DC-424]: Proceed with current demand */
    *NextState = Scc_SMS_CurrentDemand;
    retVal = Scc_StateMachineState_Done;
  }
  /* #50 [V2G-DC-427], [V2G-DC-428], [V2G-DC-502]: Check how charging shall be proceeded */
  else /* Scc_ChargeStatus_Stopping */
  {
    Scc_StateM_ControlPilotStateType controlPilotState = Scc_ControlPilotState_None;

    /* #60 Get the current CP state from application */
    Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);

    /* #70 [V2G-DC-502]: Check if current CP state does not equal state "B" (the power switch is still closed) */
    if (controlPilotState != Scc_ControlPilotState_State_B)
    {
      /* #80 Wait until application releases CP state */
      retVal = Scc_StateMachineState_Pending;
    }
    /* #90 Otherwise */
    else
    {
      Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
      /* #100 Get the current charging control from application */
      Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

      /* #110 [V2G-DC-427]: Check if application wants to perform welding detection */
      if (chargingControl == Scc_ChargingControl_StartWeldingDetection)
      {
        /* #120 Proceed with welding detection */
        *NextState = Scc_SMS_WeldingDetection;
      }
      /* #130 [V2G-DC-428]: Otherwise */
      else
      {
        /* #140 Proceed with session stop */
        *NextState = Scc_SMS_SessionStop;
      }

      retVal = Scc_StateMachineState_Done;
    }
  }

  return retVal;
}


/**********************************************************************************************************************/
/* Current Demand                                                                                                     */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_DIN70121_StateMCurrentDemand_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMCurrentDemand_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G-DC-424]: Trigger the current demand request and set cyclic message trigger to true */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_CurrentDemand, TRUE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMCurrentDemand_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMCurrentDemand_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G-DC-424], [V2G-DC-748]: Wait for contract authentication response  */
  if (   (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_CurrentDemand_OK)
      && (Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] == TRUE))
  {
    /* #20 [V2G-DC-748]: Indicate received response and proceed with message processing */
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;
    /* #30 Start delay timer to delay the next current demand request based on configured delay time */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_CurrentDemandNextReqDelay());

    retVal = Scc_StateMachineState_Done;
  }
  /* #40 Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_CurrentDemand_Failed)
  {
    /* #50 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #60 Otherwise */
  else
  {
    /* #70 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMCurrentDemand_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMCurrentDemand_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Get the current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* #20 [V2G-DC-420]: Check if charging control indicates that charging shall be stopped */
  if (   (chargingControl == Scc_ChargingControl_StartWeldingDetection)
      || (chargingControl == Scc_ChargingControl_StopCharging))
  {
    /* #30 Stop the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

    /* #40 [V2G-DC-420]: Proceed with power delivery */
    *NextState = Scc_SMS_PowerDelivery;

    retVal = Scc_StateMachineState_Done;
  }
  /* #50 Otherwise */
  else
  {
    /* #60 [V2G-DC-425]: Continue with CurrentDemand */
    *NextState = Scc_SMS_CurrentDemand;

    /* #70 Check if delay timer is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #80 The next request can be send */
      retVal = Scc_StateMachineState_Done;
    }
    /* #90 Check if delay timer has expired */
    else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #100 The next request can be send */
      retVal = Scc_StateMachineState_Done;
    }
    else
    {
      /* #110 Wait until the delay timer has expired */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  /* #120 [V2G-DC-673]: Check if user wants to shutdown */
  if (Scc_DIN70121_StateMLocal.UserInteraction.ShutdownRequested == TRUE)
  {
    /* #130 Set next state to power delivery */
    *NextState = Scc_SMS_PowerDelivery;
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}


/**********************************************************************************************************************/
/* Welding Detection                                                                                                  */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_DIN70121_StateMWeldingDetection_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMWeldingDetection_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G-DC-427]: Trigger the welding detection request and set cyclic message trigger to true */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_WeldingDetection,TRUE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMWeldingDetection_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMWeldingDetection_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G-DC-749]: Wait for welding detection response */
  /* #20 Check if valid response was received */
  if (   (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_WeldingDetection_OK)
      && (Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] == TRUE))
  {
    /* #30 [V2G-DC-749]: Indicate received response and proceed with message processing */
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;
    /* #40 Start delay timer to delay the next welding detection request based on configured delay time */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_WeldingDetectionNextReqDelay());

    retVal = Scc_StateMachineState_Done;
  }
  /* #50 Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_WeldingDetection_Failed)
  {
    /* #60 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #70 Otherwise */
  else
  {
    /* #80 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMWeldingDetection_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMWeldingDetection_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Get the current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* #20 [V2G-DC-430]: Check if the current charging control indicates that welding detection has finished on EV side */
  if (chargingControl == Scc_ChargingControl_StopCharging)
  {
    /* #30 Stop delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

    /* #40 [V2G-DC-430]: Proceed with session stop */
    /* set the new state */
    *NextState = Scc_SMS_SessionStop;
    retVal = Scc_StateMachineState_Done;
  }
  /* #50 Otherwise [V2G-DC-431]: Welding detection is not finished on EV side */
  else
  {
    /* #60 Continue with WeldingDetection */
    *NextState = Scc_SMS_WeldingDetection;

    /* #70 Check if delay timer is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #80 The next request can be send */
      retVal = Scc_StateMachineState_Done;
    }
    /* #90 Check if delay timer has expired */
    else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #100 The next request can be send */
      retVal = Scc_StateMachineState_Done;
    }
    /* #110 Otherwise */
    else
    {
      /* #120 Wait until the delay timer has expired */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  return retVal;
}


/**********************************************************************************************************************/
/* Session Stop                                                                                                       */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_DIN70121_StateMSessionStop_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMSessionStop_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G-DC-428], [V2G-DC-430]: Trigger the session stop request */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_SessionStop, FALSE);
  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMSessionStop_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMSessionStop_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G-DC-413]: Wait for session stop response */
  /* #20 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_SessionStop_OK)
  {
    /* #30 [V2G-DC-413]: Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #40 Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_SessionStop_Failed)
  {
    /* #50 [V2G-DC-658]: Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #60 Otherwise */
  else
  {
    /* #70 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateMSessionStop_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_DIN70121_StateMSessionStop_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,                                                      /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_StateM_ControlPilotStateType controlPilotState = Scc_ControlPilotState_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  SCC_DUMMY_STATEMENT_CONST(NextState);                                                                                 /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Get the current CP state from application */
  Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);

  /* #20 [V2G-DC-750]: Check if the current CP state is set to state "B" */
  if (controlPilotState != Scc_ControlPilotState_State_B)
  {
    /* #30 No: Power switch is still closed, wait until state B is reached */
    retVal = Scc_StateMachineState_Pending;
  }
  /* #40 Otherwise */
  else
  {
    /* #50 [V2G-DC-657]: Communication session is now stopped. Common part has to take care of shutting down the connection */
    retVal = Scc_StateMachineState_Finished;
  }

  return retVal;
}



/**********************************************************************************************************************/
/* State Machine Specific Functions                                                                                   */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_DIN70121_StateMSetupStateFunctions
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_DIN70121_StateMSetupStateFunctions(
  Scc_StateM_StateType StateToSetup,
  P2VAR(Scc_StateMachineGenericStateStructType, AUTOMATIC, SCC_APPL_DATA) CommonStatePtr)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Setup the internal state machine function pointers based on the passed state */
  switch (StateToSetup)
  {
    case Scc_SMS_SessionSetup:
      CommonStatePtr->PrepareFunctionPtr = &Scc_DIN70121_StateMSessionSetup_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_DIN70121_StateMSessionSetup_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_DIN70121_StateMSessionSetup_Process;
      break;

    case Scc_SMS_ServiceDiscovery:
      CommonStatePtr->PrepareFunctionPtr = &Scc_DIN70121_StateMServiceDiscovery_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_DIN70121_StateMServiceDiscovery_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_DIN70121_StateMServiceDiscovery_Process;
      break;

    case Scc_SMS_PaymentServiceSelection:
      CommonStatePtr->PrepareFunctionPtr = &Scc_DIN70121_StateMPaymentServiceSelection_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_DIN70121_StateMPaymentServiceSelection_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_DIN70121_StateMPaymentServiceSelection_Process;
      break;

    case Scc_SMS_Authorization:
      CommonStatePtr->PrepareFunctionPtr = &Scc_DIN70121_StateMAuthorization_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_DIN70121_StateMAuthorization_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_DIN70121_StateMAuthorization_Process;
      break;

    case Scc_SMS_ChargeParameterDiscovery:
      CommonStatePtr->PrepareFunctionPtr = &Scc_DIN70121_StateMChargeParameterDiscovery_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_DIN70121_StateMChargeParameterDiscovery_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_DIN70121_StateMChargeParameterDiscovery_Process;
      break;

    case Scc_SMS_PowerDelivery:
      CommonStatePtr->PrepareFunctionPtr = &Scc_DIN70121_StateMPowerDelivery_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_DIN70121_StateMPowerDelivery_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_DIN70121_StateMPowerDelivery_Process;
      break;

    case Scc_SMS_CableCheck:
      CommonStatePtr->PrepareFunctionPtr = &Scc_DIN70121_StateMCableCheck_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_DIN70121_StateMCableCheck_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_DIN70121_StateMCableCheck_Process;
      break;

    case Scc_SMS_PreCharge:
      CommonStatePtr->PrepareFunctionPtr = &Scc_DIN70121_StateMPreCharge_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_DIN70121_StateMPreCharge_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_DIN70121_StateMPreCharge_Process;
      break;

    case Scc_SMS_CurrentDemand:
      CommonStatePtr->PrepareFunctionPtr = &Scc_DIN70121_StateMCurrentDemand_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_DIN70121_StateMCurrentDemand_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_DIN70121_StateMCurrentDemand_Process;
      break;

    case Scc_SMS_WeldingDetection:
      CommonStatePtr->PrepareFunctionPtr = &Scc_DIN70121_StateMWeldingDetection_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_DIN70121_StateMWeldingDetection_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_DIN70121_StateMWeldingDetection_Process;
      break;

    case Scc_SMS_SessionStop:
      CommonStatePtr->PrepareFunctionPtr = &Scc_DIN70121_StateMSessionStop_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_DIN70121_StateMSessionStop_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_DIN70121_StateMSessionStop_Process;
      break;

    default:
      CommonStatePtr->PrepareFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      CommonStatePtr->ProcessResponseFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      /* Something went wrong in setup of states */
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_DIN70121_STATEM_SETUP, SCC_DET_INV_PARAM);
#endif
      break;
  }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_DIN70121_StateM_Init
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_DIN70121_StateM_Init(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Initialize general data. */
  Scc_DIN70121_StateMLocal.ErrorMode = Scc_DinErrorBeforeChargeParameterDiscovery;
  Scc_DIN70121_StateMLocal.UserInteraction.ShutdownRequested = FALSE;
  Scc_DIN70121_StateMLocal.UserInteraction.MoveToProcess = FALSE;
  Scc_DIN70121_StateMLocal.UserInteraction.PowerDeliveryWithReadyToChargeSent = FALSE;
  Scc_DIN70121_StateMLocal.EnablePWMDutyCycleMonitoring = FALSE;
  Scc_DIN70121_StateMLocal.LastControlPilotState = Scc_ControlPilotState_None;

  /* #20 Initialize state machine */
  Scc_StateMachineGeneric_Init(&Scc_DIN70121_StateMLocal.StateMachine, &Scc_DIN70121_StateMSetupStateFunctions,
    &Scc_DIN70121_StateMGlobalTimerCheck, &Scc_DIN70121_StateMGlobalParamCheck, &Scc_DIN70121_StateMErrorHandling);
  Scc_StateMachineGeneric_SetChannelNumber(&Scc_DIN70121_StateMLocal.StateMachine, SCC_CHANNEL_DEFAULT);

  /* #30 Start handling the session setup */
  Scc_StateMachineGeneric_ForceState(&Scc_DIN70121_StateMLocal.StateMachine, Scc_SMS_SessionSetup);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateM_Execute
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateMachineReturnType, SCC_CODE) Scc_DIN70121_StateM_Execute(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Execute the DIN 70121 state machine */
  return Scc_StateMachineGeneric_Execute(&Scc_DIN70121_StateMLocal.StateMachine);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateM_MsgRxIndication
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_DIN70121_StateM_MsgRxIndication(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G-DC-357] Start the sequence performance timeout */
  Scc_StateMachineTimer_Start(Scc_StateMachineTimer_SequencePerformance, Scc_DIN70121_TimerCfg_Get_SequencePerformanceTimeout());
}


/**********************************************************************************************************************/
/* State Machine Callouts                                                                                             */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_DIN70121_StateM_Set_EVSEProcessing
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_DIN70121_StateM_Set_EVSEProcessing(
  Exi_DIN_EVSEProcessingType EVSEProcessing)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set EVSEProcessing for DIN */
  switch (EVSEProcessing)
  {
    case EXI_DIN_EVSEPROCESSING_TYPE_ONGOING:
      Scc_DIN70121_StateMLocal.RxEVSE.EVSEProcessing = Scc_EVSEProcessing_Ongoing;
      break;

    default: /* case EXI_DIN_EVSEPROCESSING_TYPE_FINISHED: */
      Scc_DIN70121_StateMLocal.RxEVSE.EVSEProcessing = Scc_EVSEProcessing_Finished;
      break;
  }
}


/**********************************************************************************************************************
 *  Scc_DIN70121_StateM_Set_ChargeService
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_DIN70121_StateM_Set_ChargeService(
  P2CONST(Exi_DIN_ServiceChargeType, AUTOMATIC, SCC_VAR_NOINIT) ChargeService)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Handle the passed ChargeService information of a received service discovery response */
  /* #20 Reset all energy transfer modes */
  Scc_DIN70121_StateMLocal.RxEVSE.EnergyTransferMode.DC_Core = SCC_STATEM_ENERGY_TRANSFER_MODE_DISABLED;
  Scc_DIN70121_StateMLocal.RxEVSE.EnergyTransferMode.DC_Extended = SCC_STATEM_ENERGY_TRANSFER_MODE_DISABLED;

  /* #30 Evaluate energy transfer mode of passed charge service */
  switch (ChargeService->EnergyTransferType)
  {
    case EXI_DIN_EVSESUPPORTED_ENERGY_TRANSFER_TYPE_DC_CORE:
      Scc_DIN70121_StateMLocal.RxEVSE.EnergyTransferMode.DC_Core = SCC_STATEM_ENERGY_TRANSFER_MODE_ENABLED;
      break;

    case EXI_DIN_EVSESUPPORTED_ENERGY_TRANSFER_TYPE_DC_EXTENDED:
      Scc_DIN70121_StateMLocal.RxEVSE.EnergyTransferMode.DC_Extended = SCC_STATEM_ENERGY_TRANSFER_MODE_ENABLED;
      break;

    default:
      /* invalid EnergyTransferType */
      /* Energy modes are evaluated in state machine context */
      break;
  }
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateM_Get_ServiceCategory
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_DIN70121_StateM_Get_ServiceCategory(
  P2VAR(Exi_DIN_serviceCategoryType, AUTOMATIC, SCC_VAR_NOINIT) ServiceCategory,
  P2VAR(boolean, AUTOMATIC, SCC_VAR_NOINIT) Flag)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 The optional element ServiceCategory is used */
  *Flag = TRUE;

  /* #20 [V2G-DC-557]: Set category to "EVcharging" */
  *ServiceCategory = EXI_DIN_SERVICE_CATEGORY_TYPE_EVCHARGING;
}


/**********************************************************************************************************************
 *  Scc_DIN70121_StateM_Get_RequestedEnergyTransferMode
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_DIN70121_StateM_Get_RequestedEnergyTransferMode(
  P2VAR(Exi_DIN_EVRequestedEnergyTransferType, AUTOMATIC, SCC_VAR_NOINIT) EnergyTransferMode)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Propagate the energy transfer mode information that was fetched from application in state machine context */
  switch (Scc_DIN70121_StateMLocal.TxEVSE.EnergyTransferMode)
  {
    case Scc_EnergyTransferMode_DC_Core:
      *EnergyTransferMode = EXI_DIN_EVREQUESTED_ENERGY_TRANSFER_TYPE_DC_CORE;
      break;

    case Scc_EnergyTransferMode_DC_Extended:
      *EnergyTransferMode = EXI_DIN_EVREQUESTED_ENERGY_TRANSFER_TYPE_DC_EXTENDED;
      break;

    default:
      /* Nothing to do here */
      /* Det error is already reported in state machine context while user input is validated */
      break;
  }
}

/**********************************************************************************************************************
 *  Scc_DIN70121_StateM_Get_ReadyToChargeState
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_DIN70121_StateM_Get_ReadyToChargeState(
  P2VAR(boolean, AUTOMATIC, SCC_VAR_NOINIT) ReadyToChargeState)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Propagate the ReadyToChargeState information based on state machine */
  switch (Scc_DIN70121_StateMLocal.TxEVSE.ChargeStatus)
  {
    case Scc_ChargeStatus_Starting:
      *ReadyToChargeState = TRUE;
      break;

    case Scc_ChargeStatus_Stopping:
      *ReadyToChargeState = FALSE;
      break;

    default:
      /* This should not happen, otherwise the state machine has an error */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_DIN70121_STATEM_READYTOCHRG_CBK, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
      break;
  }
}

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE && SCC_SCHEMA_DIN */

/*lint +e546 */ /* Enable the 'Suspicious use of &' reporting again. */

/**********************************************************************************************************************
 *  END OF FILE: Scc_DIN70121_StateM.c
 *********************************************************************************************************************/
