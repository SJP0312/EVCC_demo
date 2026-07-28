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
/*!        \file  Scc_ISO15118_20_StateMSysS.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to ISO 15118-20.
 *                This unit takes care of dispatching all available schema specific messages/states for SystemStatus channel.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_ISO15118_20_STATEMSYSS_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
/*lint -e546 */ /* Suppress the 'Suspicious use of &' warning because the '&' is required by MISRA per Id 1502. */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( (defined SCC_ENABLE_STATE_MACHINE) && (SCC_ENABLE_STATE_MACHINE == STD_ON) \
   && (defined SCC_ENABLE_ACDP_SYSTEM_STATUS) && (SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON) )

#include "Scc_ISO15118_20_StateMSysS.h"
#include "Scc_StateM_InterfaceCfg.h"
#include "Scc_StateM_ParamsCfg.h"
#include "Scc.h"
#include "Scc_ISO15118_20_StateM.h"
#include "Scc_StateM_Vector.h"
#include "Scc_SAP_Exi.h"

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

SCC_LOCAL VAR(Scc_ISO15118_20_StateMSystemStatusChannelStructType, SCC_VAR_NOINIT) Scc_ISO15118_20_StateMSysSWs;

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Functions to enable usage of system status state machine
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMSysS_<StateMachineState>_Prepare
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
 *  \config         SCC_ENABLE_ACDP_SYSTEM_STATUS
 *********************************************************************************************************************/
/* see pattern Scc_ISO15118_20_StateMSysS_<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMSysS_Initialized_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20_StateMSysS_<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMSysS_SystemStatus_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMSysS_<StateMachineState>_Wait
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
 *  \config         SCC_ENABLE_ACDP_SYSTEM_STATUS
 *********************************************************************************************************************/
/* see pattern Scc_ISO15118_20_StateMSysS_<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMSysS_SystemStatus_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMSysS_<StateMachineState>_Process
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
 *  \config         SCC_ENABLE_ACDP_SYSTEM_STATUS
 *********************************************************************************************************************/
/* see pattern Scc_ISO15118_20_StateMSysS_<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMSysS_Initialized_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20_StateMSysS_<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMSysS_SystemStatus_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMSysS_SetupStateFunctions
 *********************************************************************************************************************/
/*! \brief          Global function to set up StateM functions
 *  \details        -
 *  \param[in]      StateToSetup      The current state of the state machine
 *  \param[out]     CommonStatePtr    Pointer to state machine function pointers
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_ACDP_SYSTEM_STATUS
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_20_StateMSysS_SetupStateFunctions(
  Scc_StateM_StateType StateToSetup,
  P2VAR(Scc_StateMachineGenericStateStructType, AUTOMATIC, SCC_APPL_DATA) CommonStatePtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMSysSErrorHandling
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
 *  \config         SCC_ENABLE_ACDP_SYSTEM_STATUS
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMSysSErrorHandling(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  Scc_StateM_StateMachineErrorType ErrorReason);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMSysSGlobalParamCheck
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
 *  \config         SCC_ENABLE_ACDP_SYSTEM_STATUS
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMSysSGlobalParamCheck(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMSysSGlobalParamCheck
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMSysSGlobalParamCheck(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if an unexpected message was received on active channel */
  if (Scc_StateM_GetDetailedErrorChannel(SCC_CHANNEL_SYSTEM_STATUS) == SccDetailedError_General_MainRxMessageUnexpectedMessage)
  {
    /* #20 Propagate error information that an unexpected message was received */
    *ErrorInformation = Scc_SMER_UnexpectedMessage;
    retVal = Scc_StateMachineState_Failed;
    /* #30 Clear error code */
    Scc_StateM_SetDetailedErrorChannel(SccDetailedError_No_Error, SCC_CHANNEL_SYSTEM_STATUS);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMSysSErrorHandling
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMSysSErrorHandling(
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
 *  Scc_ISO15118_20_StateMSysS_SetupStateFunctions
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_20_StateMSysS_SetupStateFunctions(
  Scc_StateM_StateType StateToSetup,
  P2VAR(Scc_StateMachineGenericStateStructType, AUTOMATIC, SCC_APPL_DATA) CommonStatePtr)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Setup the internal state machine function pointers based on the passed state */
  switch (StateToSetup)
  {
  case Scc_SMS_Initialized:
    CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20_StateMSysS_Initialized_Prepare;
    CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
    CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20_StateMSysS_Initialized_Process;
    break;
  case Scc_SMS_ACDP_SystemStatus:
    CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20_StateMSysS_SystemStatus_Prepare;
    CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20_StateMSysS_SystemStatus_Wait;
    CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20_StateMSysS_SystemStatus_Process;
    break;

  default:
    CommonStatePtr->PrepareFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
    CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
    CommonStatePtr->ProcessResponseFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
    /* Something went wrong in setup of states */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_20_STATEM_SYSTEM_STATUS_SETUP, SCC_DET_INV_STATE);
#endif
    break;
  }
}

/**********************************************************************************************************************/
/* Initialization                                                                                                     */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMSysS_Initialized_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMSysS_Initialized_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Set Trigger to None to wait for the application */
  Scc_StateM_SetMsgTrigParallelChannel(Scc_MsgTrig_None, FALSE, SCC_CHANNEL_SYSTEM_STATUS);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMSysS_Initialized_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMSysS_Initialized_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Continue with SystemStatusReq */
  *NextState = Scc_SMS_ACDP_SystemStatus;

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************/
/* System Status                                                                                                      */
/**********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMSysS_SystemStatus_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMSysS_SystemStatus_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  boolean startSystemStatus = FALSE;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(*ErrorInformation);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  Scc_StateM_InterfaceCfg_Get_StartSystemStatus(&startSystemStatus);

  if (startSystemStatus == TRUE)
  {
    /* #10 [V2G20-4016] Trigger the SystemStatus request */
    Scc_StateM_SetMsgTrigParallelChannel(Scc_MsgTrig_ACDP_SystemStatus, FALSE, SCC_CHANNEL_SYSTEM_STATUS);

    retVal = Scc_StateMachineState_Done;
  }
  else
  {
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMSysS_SystemStatus_Wait
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMSysS_SystemStatus_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatusParallelChannel(SCC_CHANNEL_SYSTEM_STATUS);
  /* #20 [V2G20-734] Check if a valid response was received */
  if (msgStatus == Scc_MsgStatus_ACDP_SystemStatus_OK)
  {
    /* #30 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #40 [V2G20-735] Check if invalid response was received */
  else if (msgStatus == Scc_MsgStatus_ACDP_SystemStatus_Failed)
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
 *  Scc_ISO15118_20_StateMSysS_SystemStatus_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMSysS_SystemStatus_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,                                                      /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  SCC_DUMMY_STATEMENT_CONST(NextState);                                                                                 /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G20-1085] Note 2, Set retVal to finished since communication in this channel needs to be stopped */
  retVal = Scc_StateMachineState_Finished;

  return retVal;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMSysS_Init
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateMSysS_Init(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Initialize SystemStatus data */
  Scc_ISO15118_20_StateMSysSWs.ChannelStarted = FALSE;

  /* #20 Initialize SystemStatus state machine */
  Scc_StateMachineGeneric_Init(&Scc_ISO15118_20_StateMSysSWs.StateMachineSystemStatusChannel, &Scc_ISO15118_20_StateMSysS_SetupStateFunctions,
    SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED, &Scc_ISO15118_20_StateMSysSGlobalParamCheck, &Scc_ISO15118_20_StateMSysSErrorHandling);
  Scc_StateMachineGeneric_SetSequencePerformanceTimerId(&Scc_ISO15118_20_StateMSysSWs.StateMachineSystemStatusChannel, Scc_StateMachineTimer_NumOfTimers);
  Scc_StateMachineGeneric_SetChannelNumber(&Scc_ISO15118_20_StateMSysSWs.StateMachineSystemStatusChannel, SCC_CHANNEL_SYSTEM_STATUS);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMSysS_Execute
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateMSysS_Execute(void)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Execute the ISO 15118-20 state machine for SystemStatus */
  retVal = Scc_StateMachineGeneric_Execute(&Scc_ISO15118_20_StateMSysSWs.StateMachineSystemStatusChannel);

  /* #20 If StateM is aborted or finished then reset it so that in case another round of SystemStatus is required, the StateM can react to it */
  if (   (retVal == Scc_StateMachine_Finished)
      || (retVal == Scc_StateMachine_Aborted) )
  {
    /* #30 Initialize to restart the StateM */
    Scc_ISO15118_20_StateMSysS_Init();
  }
}

/**********************************************************************************************************************/
/* State Machine Callouts                                                                                             */
/**********************************************************************************************************************/

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE && SCC_ENABLE_ACDP_SYSTEM_STATUS */

/*lint +e546 */ /* Enable the 'Suspicious use of &' reporting again. */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20_StateMSysS.c
 *********************************************************************************************************************/
