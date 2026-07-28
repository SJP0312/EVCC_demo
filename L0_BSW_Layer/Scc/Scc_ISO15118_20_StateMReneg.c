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
/*!        \file  Scc_ISO15118_20_StateMReneg.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to ISO 15118-20.
 *                This unit takes care of dispatching all available schema specific messages/states for reneg channel.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_ISO15118_20_STATEMRENEG_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
/*lint -e546 */ /* Suppress the 'Suspicious use of &' warning because the '&' is required by MISRA per Id 1502. */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON && (defined(SCC_ENABLE_RENEGOTIATION_CHANNEL) && SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON) )

#include "Scc_ISO15118_20_StateMReneg.h"
#include "Scc_ISO15118_20_StateM.h"
#include "Scc_StateM_ParamsCfg.h"
#include "Scc_StateM_InterfaceCfg.h"

#include "Scc.h"
#include "Scc_StateM_Vector.h"

#if ( SCC_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
 /* other variables */
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

SCC_LOCAL VAR(Scc_ISO15118_20_StateMRenegotiationChannelStructType, SCC_VAR_NOINIT) Scc_ISO15118_20_StateMRenegWs;

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Functions to enable usage of renegotiation state machine
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_<StateMachineState>_Prepare
 *********************************************************************************************************************/
/*! \brief          Prepares all parameters needed to transmit the associated request message
 *  \details        Set all parameters, the message trigger and the cyclic message trigger.
 *  \param[out]     ErrorInformation    Error information if the return value is set to failed.
 *  \return         Scc_StateMachineState_Failed    Preparation failed, error information is stored in parameter ErrorInformation
 *  \return         Scc_StateMachineState_Pending   Preparation is ongoing call again
 *  \return         Scc_StateMachineState_Done      Preparation succeeded
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_RENEGOTIATION_CHANNEL
 *********************************************************************************************************************/
/* see pattern Scc_ISO15118_20_StateM_<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_Initialized_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20_StateM_<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_ChargeParameterDiscovery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20_StateM_<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_ScheduleExchange_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20_StateM_<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_PowerDelivery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_<StateMachineState>_Wait
 *********************************************************************************************************************/
/*! \brief          Wait for reception of the associated response message.
 *  \details        -
 *  \param[out]     ErrorInformation    Error information if the return value is set to failed.
 *  \return         Scc_StateMachineState_Failed    Waiting failed, error information is stored in parameter ErrorInformation
 *  \return         Scc_StateMachineState_Pending   Waiting is ongoing call again
 *  \return         Scc_StateMachineState_Done      Waiting finished
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_RENEGOTIATION_CHANNEL
 *********************************************************************************************************************/
/* see pattern Scc_ISO15118_20_StateM_<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_Initialized_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20_StateM_<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_ChargeParameterDiscovery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20_StateM_<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_ScheduleExchange_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20_StateM_<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_PowerDelivery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_<StateMachineState>_Process
 *********************************************************************************************************************/
/*! \brief          Processes the received response message
 *  \details        -
 *  \param[out]     NextState           Next state that shall be executed if the return value is set to done.
 *  \param[out]     ErrorInformation    Error information if the return value is set to failed.
 *  \return         Scc_StateMachineState_Failed    Processing failed, error information is stored in parameter ErrorInformation
 *  \return         Scc_StateMachineState_Pending   Processing is ongoing call again
 *  \return         Scc_StateMachineState_Done      Processing done, next state is in parameter NextState
 *  \return         Scc_StateMachineState_Finished  Processing finished nothing left to do
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_RENEGOTIATION_CHANNEL
 *********************************************************************************************************************/
/* see pattern Scc_ISO15118_20_StateM_<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_Initialized_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20_StateM_<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_ChargeParameterDiscovery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20_StateM_<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_ScheduleExchange_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20_StateM_<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_PowerDelivery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_SetupStateFunctions
 *********************************************************************************************************************/
/*! \brief          Global function to set up StateM functions
 *  \details        -
 *  \param[in]      StateToSetup      The current state of the state machine
 *  \param[out]     CommonStatePtr    Pointer to state machine function pointers
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_RENEGOTIATION_CHANNEL
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_SetupStateFunctions(
  Scc_StateM_StateType StateToSetup,
  P2VAR(Scc_StateMachineGenericStateStructType, AUTOMATIC, SCC_APPL_DATA) CommonStatePtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMRenegGlobalTimerCheck
 *********************************************************************************************************************/
/*! \brief          Global timer check
 *  \details        -
 *  \param[in]      CurrentState      The current state of the state machine
 *  \param[out]     ErrorInformation  Pointer to error information to set. The error information is valid if
 *                                    Scc_StateMachineState_Failed is returned
 *  \return         Scc_StateMachineState_Done    No error detected
 *  \return         Scc_StateMachineState_Failed  A timer being monitored has expired
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_RENEGOTIATION_CHANNEL
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMRenegGlobalTimerCheck(
  Scc_StateM_StateType CurrentState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMRenegErrorHandling
 *********************************************************************************************************************/
/*! \brief          Global error handling
 *  \details        -
 *  \param[out]     NextState         The desired next state if Scc_StateMachineState_Done is returned
 *  \param[in]      ErrorReason       The error that caused the error handling to take place
 *  \return         Scc_StateMachineState_Done    Recoved from error condition passed
 *  \return         Scc_StateMachineState_Failed  No posibility to recover. Error handling failed
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_RENEGOTIATION_CHANNEL
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMRenegErrorHandling(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  Scc_StateM_StateMachineErrorType ErrorReason);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMRenegGlobalParamCheck
 *********************************************************************************************************************/
/*! \brief          Global parameter check
 *  \details        -
 *  \param[out]     ErrorInformation              The error that was found. Valid if return value indicates failed.
 *  \return         Scc_StateMachineState_Done    No error found
 *  \return         Scc_StateMachineState_Failed  Error found. Error information is set in ErrorInformation param.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_RENEGOTIATION_CHANNEL
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMRenegGlobalParamCheck(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_SetChannelStarted
 *********************************************************************************************************************/
/*! \brief          Store the passed information in workspace
 *  \details        -
 *  \param[in]      Started TRUE if channel was started. Otherwise FALSE.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_RENEGOTIATION_CHANNEL
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ISO15118_20_StateMReneg_SetChannelStarted(boolean Started);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMRenegGlobalTimerCheck
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMRenegGlobalTimerCheck(
  Scc_StateM_StateType CurrentState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;                                                 /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* [V2G20-1042] */
  /* #10 [V2G20-436], [V2G20-438] Monitor V2G_EVCC_Msg_Timer */
  if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_SequencePerformanceRenegotiation) == TRUE)
  {
    /* #20 Propagate error information that the timer has expired */
    *ErrorInformation = Scc_SMER_Timer_SequencePerformanceTimer;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #30 [V2G20-1052] Monitor NotificationMaxDelay */
  else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_NotificationMaxDelayRenegotiation) == TRUE)
  {
    /* #40 Propagate error information that the timer has expired */
    *ErrorInformation = Scc_SMER_Timer_NotificationMaxDelayRenegotiationTimer;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #50 [V2G20-2101] Monitor V2G_EVCC_Ongoing_Timer */
  else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_OngoingRenegotiation) == TRUE)
  {
    switch (CurrentState)
    {
      /* #60 Check if in state ScheduleExchange */
    case Scc_SMS_ScheduleExchange:
      *ErrorInformation = Scc_SMER_Timer_ScheduleExchangeOngoingTimer;
      break;

    default:
#if (SCC_DEV_ERROR_REPORT == STD_ON)
      /* This should never happen otherwise there is an issue in ISO state machine */
      /* Otherwise report an error */
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_20_STATEM_RENEG_TIMER_CHECK, SCC_DET_INV_STATE);
#endif
      break;
    }

    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #70 Otherwise no timer error occurred */
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMRenegGlobalParamCheck
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMRenegGlobalParamCheck(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if an unexpected message was received on active channel */
  if (TRUE == Scc_ISO15118_20_StateMReneg_IsChannelStarted())
  {
    if (SccDetailedError_General_MainRxMessageUnexpectedMessage == Scc_StateM_GetDetailedErrorChannel(SCC_CHANNEL_RENEGOTIATION))
    {
      /* #20 Propagate error information that an unexpected message was received */
      *ErrorInformation = Scc_SMER_UnexpectedMessage;
      retVal = Scc_StateMachineState_Failed;
      /* #30 Clear error code */
      Scc_StateM_SetDetailedErrorChannel(SccDetailedError_No_Error, SCC_CHANNEL_RENEGOTIATION);
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMRenegErrorHandling
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMRenegErrorHandling(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,                                                      /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
  Scc_StateM_StateMachineErrorType ErrorReason)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(NextState);                                                                                 /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 report the error to the application */
  Scc_StateM_InterfaceCfg_Set_StateMachineError(ErrorReason);
  Scc_ISO15118_20_StateMReneg_SetChannelStarted(FALSE);

  return retVal;
}

/**********************************************************************************************************************/
/* State Machine Specific Function                                                                                    */
/**********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_SetupStateFunctions
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_SetupStateFunctions(
  Scc_StateM_StateType StateToSetup,
  P2VAR(Scc_StateMachineGenericStateStructType, AUTOMATIC, SCC_APPL_DATA) CommonStatePtr)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Setup the internal state machine function pointers based on the passed state */
  switch (StateToSetup)
  {
  case Scc_SMS_Initialized:
    CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20_StateMReneg_Initialized_Prepare;
    CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20_StateMReneg_Initialized_Wait;
    CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20_StateMReneg_Initialized_Process;
    break;
  case Scc_SMS_ChargeParameterDiscovery:
    CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20_StateMReneg_ChargeParameterDiscovery_Prepare;
    CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20_StateMReneg_ChargeParameterDiscovery_Wait;
    CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20_StateMReneg_ChargeParameterDiscovery_Process;
    break;

  case Scc_SMS_ScheduleExchange:
    CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20_StateMReneg_ScheduleExchange_Prepare;
    CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20_StateMReneg_ScheduleExchange_Wait;
    CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20_StateMReneg_ScheduleExchange_Process;
    break;

  case Scc_SMS_PowerDelivery:
    CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20_StateMReneg_PowerDelivery_Prepare;
    CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20_StateMReneg_PowerDelivery_Wait;
    CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20_StateMReneg_PowerDelivery_Process;
    break;

  default:
    CommonStatePtr->PrepareFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
    CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
    CommonStatePtr->ProcessResponseFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
    /* Something went wrong in setup of states */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_20_STATEM_RENEG_SETUP, SCC_DET_INV_STATE);
#endif
    break;
  }
}

/**********************************************************************************************************************/
/* Initialization                                                                                                     */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_Initialized_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_Initialized_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Set Trigger to None to wait for the application */
  Scc_StateM_SetMsgTrigParallelChannel(Scc_MsgTrig_None, FALSE, SCC_CHANNEL_RENEGOTIATION);

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_Initialized_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_Initialized_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;
  boolean startRenegotiation = FALSE;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Fetch start of renegation from application */
  Scc_StateM_InterfaceCfg_Get_StartRenegotiation(&startRenegotiation);

  /* #20 [V2G20-1954], [V2G20-1845] Check if EVSE or EV has triggered the Schedule renegotiation */
  if ( (Scc_ISO15118_20_StateMReneg_IsScheduleRenegRequested() == TRUE)
    || (startRenegotiation == TRUE) )
  {
    /* [V2G20-1049] Reset flag so that after PowerDelivery no messages are sent out */
    Scc_ISO15118_20_StateMReneg_SetRequestScheduleReneg(FALSE);

    /* #30 Continue with processing */
    Scc_ISO15118_20_StateMReneg_SetChannelStarted(TRUE);
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_Initialized_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_Initialized_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 [V2G20-1046],[V2G20-1846] Continue with ChargeParameterDiscovery */
  *NextState = Scc_SMS_ChargeParameterDiscovery;

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************/
/* Charge Parameter Discovery                                                                                      */
/**********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_ChargeParameterDiscovery_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_ChargeParameterDiscovery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G20-1046],[V2G20-1846] Trigger the ChargeParameterDiscovery request */
  Scc_StateM_SetMsgTrigParallelChannel(Scc_MsgTrig_ChargeParameterDiscovery, FALSE, SCC_CHANNEL_RENEGOTIATION);

  /* #20 [V2G20-1052] Stop timer */
  Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_NotificationMaxDelayRenegotiation);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_ChargeParameterDiscovery_Wait
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_ChargeParameterDiscovery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatusParallelChannel(SCC_CHANNEL_RENEGOTIATION);
  /* #20 [V2G20-734] Check if a valid response was received */
  if (msgStatus == Scc_MsgStatus_ChargeParameterDiscovery_OK)
  {
    /* #30 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #40 [V2G20-735] Check if invalid response was received */
  else if (msgStatus == Scc_MsgStatus_ChargeParameterDiscovery_Failed)
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
 *  Scc_ISO15118_20_StateMReneg_ChargeParameterDiscovery_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_ChargeParameterDiscovery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G20-1048] Trigger a ScheduleExchangeReq message */
  *NextState = Scc_SMS_ScheduleExchange;

  return retVal;
}


/**********************************************************************************************************************/
/* ScheduleExchange                                                                                                   */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_ScheduleExchange_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_ScheduleExchange_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 [V2G20-1048] Trigger the ScheduleExchange request as cyclic message */
  Scc_StateM_SetMsgTrigParallelChannel(Scc_MsgTrig_ScheduleExchange, TRUE, SCC_CHANNEL_RENEGOTIATION);

  retVal = Scc_StateMachineState_Done;

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_ScheduleExchange_Wait
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_ScheduleExchange_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatusParallelChannel(SCC_CHANNEL_RENEGOTIATION);

  /* #20 [V2G20-734] Check if a valid response was received */
  if ( (msgStatus == Scc_MsgStatus_ScheduleExchange_OK)
    && (TRUE == Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_RENEGOTIATION]) )
  {
    /* #30 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_RENEGOTIATION] = FALSE;

    /* #40 Check if EVSEProcessing is set to Ongoing */
    if (Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_RENEGOTIATION) == Scc_EVSEProcessing_Ongoing)
    {
      /* #50 Start delay timer to delay the next schedule exchange request based on configured delay time */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelayRenegotiation, Scc_StateM_ParamCfg_Get_ScheduleExchangeNextReqDelay());

      /* #60 [V2G20-710] Check if ongoing timer is not yet started */
      if (TRUE == Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_OngoingRenegotiation))
      {
        /* #70 [V2G20-710] Start the timer */
        Scc_StateMachineTimer_Start(Scc_StateMachineTimer_OngoingRenegotiation, Scc_StateM_ParamCfg_Get_ScheduleExchangeOngoingTimeout());
      }
    }
    /* #80 Otherwise stop the timer */
    else
    {
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_OngoingRenegotiation);
    }
  }
  /* #90 [V2G20-735] Check if invalid response was received */
  else if (msgStatus == Scc_MsgStatus_ScheduleExchange_Failed)
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
 *  Scc_ISO15118_20_StateMReneg_ScheduleExchange_Process
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_ScheduleExchange_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G20-2316] Check if EVSEProcessing is set to ongoing */
  if (Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_RENEGOTIATION) == Scc_EVSEProcessing_Ongoing)
  {
    /* #20 [V2G20-2714] Trigger a ScheduleExchange message */
    /* [V2G20-UG-014-1] the ScheduleExchange message shall be repeated unaltered */
    *NextState = Scc_SMS_ScheduleExchange;

    /* #30 Check if delay timer is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelayRenegotiation) == TRUE)
    {
      /* #40 The next request can be send */
      retVal = Scc_StateMachineState_Done;
    }
    /* #50 Check if delay timer has expired */
    else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelayRenegotiation) == TRUE)
    {
      /* #60 The next request can be send now */
      retVal = Scc_StateMachineState_Done;
    }
    /* #70 Otherwise */
    else
    {
      /* #80 Wait until the delay timer has expired */
      retVal = Scc_StateMachineState_Pending;
    }
  }
  /* #90 Otherwise */
  else
  {
    /* #100 Stop delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelayRenegotiation);

    /* #110 [V2G20-2713],[V2G20-2317] Trigger a PowerDelivery message */
    *NextState = Scc_SMS_PowerDelivery;
  }

  return retVal;
}

/**********************************************************************************************************************/
/* PowerDelivery                                                                                                      */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_PowerDelivery_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_PowerDelivery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;                                                 /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G20-2317] Trigger the PowerDelivery request */
  Scc_StateM_SetMsgTrigParallelChannel(Scc_MsgTrig_PowerDelivery, FALSE, SCC_CHANNEL_RENEGOTIATION);

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_PowerDelivery_Wait
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_PowerDelivery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatusParallelChannel(SCC_CHANNEL_RENEGOTIATION);
  /* #20 [V2G20-734],[V2G20-1049] Check if a valid response was received */
  if (msgStatus == Scc_MsgStatus_PowerDelivery_OK)
  {
    /* #30 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #40 [V2G20-735] Check if invalid response was received */
  else if (msgStatus == Scc_MsgStatus_PowerDelivery_Failed)
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
 *  Scc_ISO15118_20_StateMReneg_PowerDelivery_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMReneg_PowerDelivery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,                                                      /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;                                               /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  SCC_DUMMY_STATEMENT_CONST(NextState);                                                                                 /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G20-1049] Set retVal to finished since communication in this channel needs to be stopped */
  /* [V2G20-1050] Has to be implemented by application */
  Scc_ISO15118_20_StateMReneg_SetChannelStarted(FALSE);
  retVal = Scc_StateMachineState_Finished;

  return retVal;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_Init
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateMReneg_Init(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Initialize ScheduleReneg data */
  Scc_ISO15118_20_StateMRenegWs.RequestScheduleReneg = FALSE;
  Scc_ISO15118_20_StateMReneg_SetChannelStarted(FALSE);

  /* #20 Stop timer */
  Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_NotificationMaxDelayRenegotiation);

  /* #30 Initialize Renegotiation state machine */
  Scc_StateMachineGeneric_Init(&Scc_ISO15118_20_StateMRenegWs.StateMachineRenegChannel, &Scc_ISO15118_20_StateMReneg_SetupStateFunctions,
    &Scc_ISO15118_20_StateMRenegGlobalTimerCheck, &Scc_ISO15118_20_StateMRenegGlobalParamCheck, &Scc_ISO15118_20_StateMRenegErrorHandling);
  Scc_StateMachineGeneric_SetSequencePerformanceTimerId(&Scc_ISO15118_20_StateMRenegWs.StateMachineRenegChannel, Scc_StateMachineTimer_SequencePerformanceRenegotiation);
  Scc_StateMachineGeneric_SetChannelNumber(&Scc_ISO15118_20_StateMRenegWs.StateMachineRenegChannel, SCC_CHANNEL_RENEGOTIATION);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_Execute
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateMReneg_Execute(void)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Execute the ISO 15118-20 state machine for Reneg */
  retVal = Scc_StateMachineGeneric_Execute(&Scc_ISO15118_20_StateMRenegWs.StateMachineRenegChannel);

  /* #20 If StateM is aborted or finished then reset it so that in case another round of renegotiation is required, the StateM can react to it */
  if ( (retVal == Scc_StateMachine_Finished)
    || (retVal == Scc_StateMachine_Aborted) )
  {
    /* #30 Set NextState to Initialized to restart the StateM */
    Scc_StateMachineGeneric_Init(&Scc_ISO15118_20_StateMRenegWs.StateMachineRenegChannel, &Scc_ISO15118_20_StateMReneg_SetupStateFunctions,
      &Scc_ISO15118_20_StateMRenegGlobalTimerCheck, &Scc_ISO15118_20_StateMRenegGlobalParamCheck, &Scc_ISO15118_20_StateMRenegErrorHandling);
    Scc_StateMachineGeneric_SetSequencePerformanceTimerId(&Scc_ISO15118_20_StateMRenegWs.StateMachineRenegChannel, Scc_StateMachineTimer_SequencePerformanceRenegotiation);
    Scc_StateMachineGeneric_SetChannelNumber(&Scc_ISO15118_20_StateMRenegWs.StateMachineRenegChannel, SCC_CHANNEL_RENEGOTIATION);
  }
}

/**********************************************************************************************************************/
/* Common Workspace Management Functions                                                                              */
/**********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_SetRequestScheduleReneg
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateMReneg_SetRequestScheduleReneg(
  boolean Flag)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Store value into workspace */
  Scc_ISO15118_20_StateMRenegWs.RequestScheduleReneg = Flag;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_IsScheduleRenegRequested
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateMReneg_IsScheduleRenegRequested(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return if ScheduleRenegotiation should be done or not */
  return Scc_ISO15118_20_StateMRenegWs.RequestScheduleReneg;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_IsChannelStarted
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateMReneg_IsChannelStarted(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Return if the parallel channel was already started */
  return Scc_ISO15118_20_StateMRenegWs.ChannelStarted;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_SetChannelStarted
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ISO15118_20_StateMReneg_SetChannelStarted(boolean Started)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Store value into workspace */
  Scc_ISO15118_20_StateMRenegWs.ChannelStarted = Started;
}

/**********************************************************************************************************************/
/* State Machine Callouts                                                                                             */
/**********************************************************************************************************************/

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE && SCC_ENABLE_RENEGOTIATION_CHANNEL */

/*lint +e546 */ /* Enable the 'Suspicious use of &' reporting again. */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20_StateMReneg.c
 *********************************************************************************************************************/
