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
/*!        \file  Scc_ISO15118_20_StateMMeter.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to ISO 15118-20.
 *                This unit takes care of dispatching all available schema specific messages/states for Metering channel.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_ISO15118_20_STATEMMETER_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
/*lint -e546 */ /* Suppress the 'Suspicious use of &' warning because the '&' is required by MISRA per Id 1502. */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON && (defined(SCC_ENABLE_METERING_RECEIPT) && SCC_ENABLE_METERING_RECEIPT == STD_ON) )

#include "Scc_ISO15118_20_StateMMeter.h"
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

SCC_LOCAL VAR(Scc_ISO15118_20_StateMMeteringChannelStructType, SCC_VAR_NOINIT) Scc_ISO15118_20_StateMMeterWs;

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Functions to enable usage of metering state machine
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeter_<StateMachineState>_Prepare
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
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *********************************************************************************************************************/
/* see pattern Scc_ISO15118_20_StateMMeter_<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMMeter_Initialized_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20_StateMMeter_<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMMeter_MeteringConfirmation_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeter_<StateMachineState>_Wait
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
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *********************************************************************************************************************/
/* see pattern Scc_ISO15118_20_StateMMeter_<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMMeter_MeteringConfirmation_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeter_<StateMachineState>_Process
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
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *********************************************************************************************************************/
/* see pattern Scc_ISO15118_20_StateMMeter_<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMMeter_Initialized_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20_StateMMeter_<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMMeter_MeteringConfirmation_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeter_SetupStateFunctions
 *********************************************************************************************************************/
/*! \brief          Global function to set up StateM functions
 *  \details        -
 *  \param[in]      StateToSetup      The current state of the state machine
 *  \param[out]     CommonStatePtr    Pointer to state machine function pointers
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_20_StateMMeter_SetupStateFunctions(
  Scc_StateM_StateType StateToSetup,
  P2VAR(Scc_StateMachineGenericStateStructType, AUTOMATIC, SCC_APPL_DATA) CommonStatePtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeterGlobalTimerCheck
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
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMMeterGlobalTimerCheck(
  Scc_StateM_StateType CurrentState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeterErrorHandling
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
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMMeterErrorHandling(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  Scc_StateM_StateMachineErrorType ErrorReason);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeterGlobalParamCheck
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
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMMeterGlobalParamCheck(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeterGlobalTimerCheck
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMMeterGlobalTimerCheck(
  Scc_StateM_StateType CurrentState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(CurrentState);                                                                              /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G20-1621] Monitor NotificationMaxDelay */
  if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_NotificationMaxDelayMeter) == TRUE)
  {
    /* #20 Propagate error information that the timer has expired */
    *ErrorInformation = Scc_SMER_Timer_NotificationMaxDelayMeterTimer;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #30 Otherwise no timer error occurred */
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeterGlobalParamCheck
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMMeterGlobalParamCheck(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if an unexpected message was received on active channel */
  if (SccDetailedError_General_MainRxMessageUnexpectedMessage == Scc_StateM_GetDetailedErrorChannel(SCC_CHANNEL_METERING))
  {
    /* #20 Propagate error information that an unexpected message was received */
    *ErrorInformation = Scc_SMER_UnexpectedMessage;
    retVal = Scc_StateMachineState_Failed;
    /* #30 Clear error code */
    Scc_StateM_SetDetailedErrorChannel(SccDetailedError_No_Error, SCC_CHANNEL_METERING);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeterErrorHandling
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMMeterErrorHandling(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,                                                      /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
  Scc_StateM_StateMachineErrorType ErrorReason)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(*NextState);                                                                                /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 report the error to the application */
  Scc_StateM_InterfaceCfg_Set_StateMachineError(ErrorReason);

  return retVal;
}

/**********************************************************************************************************************/
/* State Machine Specific Function                                                                                    */
/**********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeter_SetupStateFunctions
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_20_StateMMeter_SetupStateFunctions(
  Scc_StateM_StateType StateToSetup,
  P2VAR(Scc_StateMachineGenericStateStructType, AUTOMATIC, SCC_APPL_DATA) CommonStatePtr)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Setup the internal state machine function pointers based on the passed state */
  switch (StateToSetup)
  {
  case Scc_SMS_Initialized:
    CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20_StateMMeter_Initialized_Prepare;
    CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
    CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20_StateMMeter_Initialized_Process;
    break;
  case Scc_SMS_MeteringReceipt:
    CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20_StateMMeter_MeteringConfirmation_Prepare;
    CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20_StateMMeter_MeteringConfirmation_Wait;
    CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20_StateMMeter_MeteringConfirmation_Process;
    break;

  default:
    CommonStatePtr->PrepareFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
    CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
    CommonStatePtr->ProcessResponseFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
    /* Something went wrong in setup of states */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_20_STATEM_METER_SETUP, SCC_DET_INV_STATE);
#endif
    break;
  }
}

/**********************************************************************************************************************/
/* Initialization                                                                                                     */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeter_Initialized_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMMeter_Initialized_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;
  boolean startMetering = FALSE;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  Scc_StateM_InterfaceCfg_Get_StartMetering(&startMetering);
  /* #10 Check if the application wants to start metering */
  if (startMetering == TRUE)
  {
    /* #20 Set Trigger to None to wait for the application */
    Scc_StateM_SetMsgTrigParallelChannel(Scc_MsgTrig_None, FALSE, SCC_CHANNEL_METERING);
    Scc_ISO15118_20_StateMMeter_SetMeteringReqSent(TRUE);

    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeter_Initialized_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMMeter_Initialized_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 [V2G20-1084] Continue with MeteringConfirmation */
  *NextState = Scc_SMS_MeteringReceipt;

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************/
/* Metering Confirmation                                                                                              */
/**********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeter_MeteringConfirmation_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMMeter_MeteringConfirmation_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(*ErrorInformation);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G20-1084] Trigger the MeteringConfirmation request */
  Scc_StateM_SetMsgTrigParallelChannel(Scc_MsgTrig_MeteringReceipt, FALSE, SCC_CHANNEL_METERING);
  /* #20 Stop timer since metering request is triggered by StateM */
  Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_NotificationMaxDelayMeter);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeter_MeteringConfirmation_Wait
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMMeter_MeteringConfirmation_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatusParallelChannel(SCC_CHANNEL_METERING);
  /* #20 [V2G20-734] Check if a valid response was received */
  if (msgStatus == Scc_MsgStatus_MeteringReceipt_OK)
  {
    /* #30 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #40 [V2G20-735] Check if invalid response was received */
  else if (msgStatus == Scc_MsgStatus_MeteringReceipt_Failed)
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
 *  Scc_ISO15118_20_StateMMeter_MeteringConfirmation_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMMeter_MeteringConfirmation_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,                                                      /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  SCC_DUMMY_STATEMENT_CONST(NextState);                                                                                 /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G20-1085] Note 2, Set retVal to finished since communication in this channel needs to be stopped */
  Scc_ISO15118_20_StateMMeter_SetChannelStarted(FALSE);
  retVal = Scc_StateMachineState_Finished;

  return retVal;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeter_Init
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateMMeter_Init(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Initialize Metering data */
  Scc_ISO15118_20_StateMMeter_SetChannelStarted(FALSE);
  Scc_ISO15118_20_StateMMeterWs.IsMeteringReqSent = FALSE;

  /* #20 Stop timer */
  Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_NotificationMaxDelayMeter);

  /* #30 Initialize Metering state machine */
  Scc_StateMachineGeneric_Init(&Scc_ISO15118_20_StateMMeterWs.StateMachineMeterChannel, &Scc_ISO15118_20_StateMMeter_SetupStateFunctions,
    &Scc_ISO15118_20_StateMMeterGlobalTimerCheck, &Scc_ISO15118_20_StateMMeterGlobalParamCheck, &Scc_ISO15118_20_StateMMeterErrorHandling);
  Scc_StateMachineGeneric_SetSequencePerformanceTimerId(&Scc_ISO15118_20_StateMMeterWs.StateMachineMeterChannel, Scc_StateMachineTimer_NumOfTimers);
  Scc_StateMachineGeneric_SetChannelNumber(&Scc_ISO15118_20_StateMMeterWs.StateMachineMeterChannel, SCC_CHANNEL_METERING);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeter_Execute
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateMMeter_Execute(void)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Execute the ISO 15118-20 state machine for Meter */
  retVal = Scc_StateMachineGeneric_Execute(&Scc_ISO15118_20_StateMMeterWs.StateMachineMeterChannel);

  /* #20 If StateM is aborted or finished then reset it so that in case another round of metering is required, the StateM can react to it */
  if ((retVal == Scc_StateMachine_Finished)
    || (retVal == Scc_StateMachine_Aborted))
  {
    /* #30 Initialize to restart the StateM */
    Scc_ISO15118_20_StateMMeter_Init();
  }
}

/**********************************************************************************************************************/
/* Common Workspace Management Functions                                                                              */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeter_SetChannelStarted
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateMMeter_SetChannelStarted(boolean Started)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the channel was started */
  if (Started == TRUE)
  {
    /* #20 Reset flag that MeteringReq was not yet sent */
    Scc_ISO15118_20_StateMMeter_SetMeteringReqSent(FALSE);
  }
  /* #30 Store value into workspace */
  Scc_ISO15118_20_StateMMeterWs.ChannelStarted = Started;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeter_IsChannelStarted
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateMMeter_IsChannelStarted(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Return if the parallel channel was already started */
  return Scc_ISO15118_20_StateMMeterWs.ChannelStarted;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeter_SetMeteringReqSent()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateMMeter_SetMeteringReqSent(boolean MeteringSent)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Store if metering is sent or not. */
  Scc_ISO15118_20_StateMMeterWs.IsMeteringReqSent = MeteringSent;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeter_IsMeteringReqSent()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateMMeter_IsMeteringReqSent(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return if metering is sent or not. */
  return Scc_ISO15118_20_StateMMeterWs.IsMeteringReqSent;
}

/**********************************************************************************************************************/
/* State Machine Callouts                                                                                             */
/**********************************************************************************************************************/

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE && SCC_ENABLE_METERING_RECEIPT */

/*lint +e546 */ /* Enable the 'Suspicious use of &' reporting again. */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20_StateMMeter.c
 *********************************************************************************************************************/
