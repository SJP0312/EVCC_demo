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
/*!        \file  Scc_StateMachineGeneric.c
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

#define SCC_STATEMACHINEGENERIC_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_StateMachineGeneric.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON )

#include "Scc.h"
#include "Scc_StateM_InterfaceCfg.h"
#include "Scc_StateMachineTimer.h"

/* Foreign modules */
#if ( SCC_DEV_ERROR_DETECT == STD_ON )
# include "Det.h"
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

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ( SCC_ENABLE_STATEM_APPL_CONTROLLED_FLOW == STD_ON )
/**********************************************************************************************************************
 Scc_StateMachineGeneric_HandleWaitForApplication()
 **********************************************************************************************************************/
/*! \brief          Handles the transition to the wait for application sub state.
 *  \details        -
 *  \param[in,out]  StateMachineConfig       Pointer to the state machine to handle
 *  \pre            -
 *  \config         SCC_ENABLE_STATEM_APPL_CONTROLLED_FLOW
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_HandleWaitForApplication(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineConfig);
#endif /* SCC_ENABLE_STATEM_APPL_CONTROLLED_FLOW */

/**********************************************************************************************************************
 Scc_StateMachineGeneric_HandleStateTransistion()
 **********************************************************************************************************************/
/*! \brief          Handles a state transition for the passed state machine.
 *  \details        -
 *  \param[in,out]  StateMachineConfig       Pointer to the state machine to handle
 *  \param[in]      NextState                The next state to transition to
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_HandleStateTransistion(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineConfig,
  Scc_StateM_StateType NextState);

/**********************************************************************************************************************
 Scc_StateMachineGeneric_StepGlobalTimerCheck()
 **********************************************************************************************************************/
/*! \brief          Handles the execution of the global timer check.
 *  \details        If the passed state machine has configured a global timer check callout then this callout is
 *                  triggered. The state machine then can perform the associated timer checks. If the callout indicates
 *                  an erroneous timer the state machine is set to error handling state.
 *  \param[in,out]  StateMachineConfig       Pointer to the state machine to handle
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_StepGlobalTimerCheck(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineConfig);

/**********************************************************************************************************************
 Scc_StateMachineGeneric_StepGlobalParamCheck()
 **********************************************************************************************************************/
/*! \brief          Handles the execution of the global parameter check.
 *  \details        If the passed state machine has configured a global parameter check callout then this callout is
 *                  triggered. The state machine then can perform the associated parameter checks. If the callout
 *                  indicates an erroneous parameter the state machine is set to error handling state.
 *  \param[in,out]  StateMachineConfig       Pointer to the state machine to handle
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_StepGlobalParamCheck(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineConfig);

/**********************************************************************************************************************
 Scc_StateMachineGeneric_StepPrepare()
 **********************************************************************************************************************/
/*! \brief          Handles the prepare step of a generic state.
 *  \details        If the current state of the passed state machine has configured the optional prepare step callout
 *                  then this callout is going to be called.
 *  \param[in,out]  StateMachineConfig       Pointer to the state machine to handle
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_StepPrepare(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineConfig);

/**********************************************************************************************************************
 Scc_StateMachineGeneric_StepWait()
 **********************************************************************************************************************/
/*! \brief          Handles the wait step of a generic state.
 *  \details        If the current state of the passed state machine has configured the optional wait step callout
 *                  then this callout is going to be called.
 *  \param[in,out]  StateMachineConfig       Pointer to the state machine to handle
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_StepWait(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineConfig);

/**********************************************************************************************************************
 Scc_StateMachineGeneric_StepProcess()
 **********************************************************************************************************************/
/*! \brief          Handles the process step of a generic state.
 *  \details        If the current state of the passed state machine has configured the optional process step callout
 *                  then this callout is going to be called.
 *  \param[in,out]  StateMachineConfig       Pointer to the state machine to handle
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_StepProcess(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineConfig);

/**********************************************************************************************************************
 Scc_StateMachineGeneric_StepErrorHandling()
 **********************************************************************************************************************/
/*! \brief          Handles the error handling of the passed generic state machine.
 *  \details        If the passed state machine has configured the optional error handling callout
 *                  then this callout is going to be called.
 *  \param[in,out]  StateMachineConfig       Pointer to the state machine to handle
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_StepErrorHandling(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineConfig);

#if ( SCC_ENABLE_STATEM_APPL_CONTROLLED_FLOW == STD_ON )
/**********************************************************************************************************************
 Scc_StateMachineGeneric_StepWaitForApplication()
 **********************************************************************************************************************/
 /*! \brief         Handles the wait for application sub state.
 *  \details        The execution of the next state is continued as soon as the application signalizes that it
 *                  is ready to continue state machine execution.
 *  \param[in,out]  StateMachineConfig       Pointer to the state machine to handle
 *  \pre            -
 *  \config         SCC_ENABLE_STATEM_APPL_CONTROLLED_FLOW
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_StepWaitForApplication(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineConfig);
#endif /* SCC_ENABLE_STATEM_APPL_CONTROLLED_FLOW */


/**********************************************************************************************************************
 Scc_StateMachineGeneric_ProcessState()
 **********************************************************************************************************************/
/*! \brief          Processes the current state of the passed state machine.
 *  \details        -
 *  \param[in,out]  StateMachineToExecute   Pointer to the state machine to handle
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_ProcessState(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineToExecute);

/**********************************************************************************************************************
 Scc_StateMachineGeneric_PropagateState()
 **********************************************************************************************************************/
/*! \brief          Propagtes the status based on the state of the passed state machine.
 *  \details        -
 *  \param[in,out]  StateMachineToExecute   Pointer to the state machine to handle
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_PropagateState(
  P2CONST(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineToExecute);



/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

#if ( SCC_ENABLE_STATEM_APPL_CONTROLLED_FLOW == STD_ON )
/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_HandleWaitForApplication
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_HandleWaitForApplication(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineConfig)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  boolean flowControl = TRUE;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Get the flow control from the application */
  Scc_StateM_InterfaceCfg_Get_FlowControl(&flowControl);
  /* #20 Check if the state machine has to wait */
  if (TRUE != flowControl)
  {
    /* #30 Set the msg state to wait for application */
    StateMachineConfig->CurrentSubState = Scc_StateMachineGeneric_WaitForApplication;
    Scc_StateM_InterfaceCfg_Set_StateMachineMessageState(Scc_SMMS_WaitingForApplication);
  }
}
#endif /* SCC_ENABLE_STATEM_APPL_CONTROLLED_FLOW */

/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_HandleStateTransistion
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_HandleStateTransistion(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineConfig,
  Scc_StateM_StateType NextState)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Assign the next state to the passed state machine structure */
  StateMachineConfig->NextState = NextState;
  StateMachineConfig->CurrentSubState = Scc_StateMachineGeneric_Prepare;
  /* #20 Propagte the preparing request state transition */
  Scc_StateM_InterfaceCfg_Set_StateMachineMessageState(Scc_SMMS_PreparingRequest);
  /* #30 If FlowControl enabled, check for wait for application */
#if ( SCC_ENABLE_STATEM_APPL_CONTROLLED_FLOW == STD_ON )
  Scc_StateMachineGeneric_HandleWaitForApplication(StateMachineConfig);
#endif /* SCC_ENABLE_STATEM_APPL_CONTROLLED_FLOW */
}

/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_StepGlobalTimerCheck
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_StepGlobalTimerCheck(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineConfig)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType stateRetVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if optional timeout function pointer is available */
  if (StateMachineConfig->GlobalTimeoutFunctionPtr != SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED)
  {
    /* #20 Yes: call the configured timeout function */
    stateRetVal = StateMachineConfig->GlobalTimeoutFunctionPtr(StateMachineConfig->CurrentState, &StateMachineConfig->LatestErrorInformation);
  }

  /* #30 If an error occurred trigger error handling */
  if (stateRetVal == Scc_StateMachineState_Failed)
  {
    /* An error occurred -> Continue with error handling */
    StateMachineConfig->CurrentSubState = Scc_StateMachineGeneric_Error;
  }
}

/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_StepGlobalParamCheck
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_StepGlobalParamCheck(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineConfig)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType stateRetVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if optional parameter check function pointer is available */
  if (StateMachineConfig->GlobalCheckFunctionPtr != SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED)
  {
    /* #20 Yes: call the configured paramter check function */
    stateRetVal = StateMachineConfig->GlobalCheckFunctionPtr(&StateMachineConfig->LatestErrorInformation);
  }

  /* #30 If an error occurred trigger error handling */
  if (stateRetVal == Scc_StateMachineState_Failed)
  {
    /* An error occurred -> Continue with error handling */
    StateMachineConfig->CurrentSubState = Scc_StateMachineGeneric_Error;
  }
}

/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_StepPrepare
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_StepPrepare(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineConfig)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType stateRetVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if optional prepare function pointer is available */
  if (StateMachineConfig->CurrentStateConfig.PrepareFunctionPtr != SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED)
  {
    /* #20 Yes: call the configured prepare function */
    stateRetVal = StateMachineConfig->CurrentStateConfig.PrepareFunctionPtr(&StateMachineConfig->LatestErrorInformation);
  }

  /* #30 Handle state transition */
  switch (stateRetVal)
  {
    case Scc_StateMachineState_Done:
      if (StateMachineConfig->SequencePerformanceTimerId != Scc_StateMachineTimer_NumOfTimers)
      {
        /* [V2G2-439] */
        Scc_StateMachineTimer_Stop(StateMachineConfig->SequencePerformanceTimerId);
      }
      StateMachineConfig->CurrentSubState = Scc_StateMachineGeneric_Wait;
      Scc_StateM_InterfaceCfg_Set_StateMachineMessageState(Scc_SMMS_WaitingForResponse);
      break;
    case Scc_StateMachineState_Failed:
      StateMachineConfig->CurrentSubState = Scc_StateMachineGeneric_Error;
      break;
    default:
      /* Other return values are treated as pending */
      /* Wait until operation is finished */
      break;
  }
}

/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_StepWait
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_StepWait(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineConfig)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType stateRetVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if optional wait function pointer is available */
  if (StateMachineConfig->CurrentStateConfig.WaitFunctionPtr != SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED)
  {
    /* #20 Yes: call the configured prepare function */
    stateRetVal = StateMachineConfig->CurrentStateConfig.WaitFunctionPtr(&StateMachineConfig->LatestErrorInformation);
  }

  /* #30 Handle state transition */
  switch (stateRetVal)
  {
    case Scc_StateMachineState_Done:
      StateMachineConfig->CurrentSubState = Scc_StateMachineGeneric_Process;
      Scc_StateM_InterfaceCfg_Set_StateMachineMessageState(Scc_SMMS_ProcessingResponse);
      break;
    case Scc_StateMachineState_Failed:
      StateMachineConfig->CurrentSubState = Scc_StateMachineGeneric_Error;
      break;
    default:
      /* Other return values are treated as pending */
      /* Wait until operation is finished */
      break;
  }
}

/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_StepErrorHandling
 *********************************************************************************************************************/
/*!
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
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_StepProcess(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineConfig)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType stateRetVal;
  Scc_StateM_StateType nextState = StateMachineConfig->CurrentState;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if mandatory process function is configured */
  if (StateMachineConfig->CurrentStateConfig.ProcessResponseFunctionPtr == SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED)
  {
    /* #20 No: Report Det error */
    stateRetVal = Scc_StateMachineState_Failed;
#if(SCC_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_STATEMGENERIC_PROCESS, SCC_DET_STATEMGENERIC_INVALIDPROCESSFCT);
#endif
  }
  else
  {
    /* #30 Otherwise call configured process function */
    stateRetVal = StateMachineConfig->CurrentStateConfig.ProcessResponseFunctionPtr(&nextState, &StateMachineConfig->LatestErrorInformation);
  }

  /* #40 Evaluate state processing */
  switch (stateRetVal)
  {
    /* #50 State was handled successfully: Transistion to next state */
    case Scc_StateMachineState_Done:
      Scc_StateMachineGeneric_HandleStateTransistion(StateMachineConfig, nextState);
      break;

    /* #60 State machine finished: Transistion to finished state */
    case Scc_StateMachineState_Finished:
      StateMachineConfig->CurrentSubState = Scc_StateMachineGeneric_Finish;
      break;

    /* #70 State handling failed: Transistion to error state */
    case Scc_StateMachineState_Failed:
      StateMachineConfig->CurrentSubState = Scc_StateMachineGeneric_Error;
      break;

    /* #80 Otherwise: State is pending */
    default:
      /* Other return values are treated as pending */
      /* Wait until operation is finished */
      break;
  }
}

/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_StepErrorHandling
 *********************************************************************************************************************/
/*!
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
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_StepErrorHandling(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineConfig)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType stateRetVal;
  Scc_StateM_StateType nextState = StateMachineConfig->CurrentState;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if optional error handling function pointer is available */
  if (StateMachineConfig->GlobalErrorFunctionPtr != SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED)
  {
    /* #20 Yes: call the configured error handling function */
    stateRetVal = StateMachineConfig->GlobalErrorFunctionPtr(&nextState, StateMachineConfig->LatestErrorInformation);
  }
  else
  {
    /* #30 No: Error handling can not be done therefore consider it as failed */
    stateRetVal = Scc_StateMachineState_Failed;
  }

  /* #40 Handle state transition */
  switch (stateRetVal)
  {
    /* #50 Error handling was done successfully: Recover from error state */
    case Scc_StateMachineState_Done:
      Scc_StateMachineGeneric_HandleStateTransistion(StateMachineConfig, nextState);
      break;
    /* #60 Error handling failed: Abort processing of state machine */
    case Scc_StateMachineState_Failed:
      /* State machine is aborted */
      StateMachineConfig->CurrentSubState = Scc_StateMachineGeneric_Abort;
      break;
    /* #70 Otherwise: Error handling is pending */
    default:
      /* Other return values are treated as pending */
      /* Wait until operation is finished */
      break;
  }
}

#if ( SCC_ENABLE_STATEM_APPL_CONTROLLED_FLOW == STD_ON )
/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_StepWaitForApplication
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_StepWaitForApplication(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineConfig)
{
  /* ----- Implementation ------------------------------------------------------------ */
  if (StateMachineConfig->CurrentSubState == Scc_StateMachineGeneric_WaitForApplication)
  {
    boolean flowControl = TRUE;

    /* #10 Get the flow control from the application */
    Scc_StateM_InterfaceCfg_Get_FlowControl(&flowControl);
    /* #20 Check if the flow control indicates proceeding with processing */
    if (flowControl == TRUE)
    {
      /* #30 Proceed with preparation */
      StateMachineConfig->CurrentSubState = Scc_StateMachineGeneric_Prepare;
      /* #40 Propagate preparing transition to application */
      Scc_StateM_InterfaceCfg_Set_StateMachineMessageState(Scc_SMMS_PreparingRequest);
    }
  }
}
#endif /* SCC_ENABLE_STATEM_APPL_CONTROLLED_FLOW */

/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_ProcessState
 *********************************************************************************************************************/
/*!
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
SCC_LOCAL FUNC(void, SCC_CODE)  Scc_StateMachineGeneric_ProcessState(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineToExecute)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 If FlowControl enabled, handle application flow control */
#if ( SCC_ENABLE_STATEM_APPL_CONTROLLED_FLOW == STD_ON )
  if (StateMachineToExecute->CurrentSubState == Scc_StateMachineGeneric_WaitForApplication)
  {
    Scc_StateMachineGeneric_StepWaitForApplication(StateMachineToExecute);
  }
#endif /* SCC_ENABLE_STATEM_APPL_CONTROLLED_FLOW */

  /* #20 Report the current status to the application */
  Scc_StateMachineGeneric_PropagateState(StateMachineToExecute);

  /* #30 Execute the active generic state */
  /* #40 If current sub state is prepare, then handle the preparation function */
  if (StateMachineToExecute->CurrentSubState == Scc_StateMachineGeneric_Prepare)
  {
    Scc_StateMachineGeneric_StepPrepare(StateMachineToExecute);
  }

  /* #50 If current sub state is wait, then handle the wait function */
  if (StateMachineToExecute->CurrentSubState == Scc_StateMachineGeneric_Wait)
  {
    Scc_StateMachineGeneric_StepWait(StateMachineToExecute);
  }

  /* #60 If current sub state is process, then handle the process function */
  if (StateMachineToExecute->CurrentSubState == Scc_StateMachineGeneric_Process)
  {
    Scc_StateMachineGeneric_StepProcess(StateMachineToExecute);
  }

  /* #70 If current sub state is error, then handle the error handling function */
  if (StateMachineToExecute->CurrentSubState == Scc_StateMachineGeneric_Error)
  {
    Scc_StateMachineGeneric_StepErrorHandling(StateMachineToExecute);
  }
}


/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_PropagateState
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_StateMachineGeneric_PropagateState(
  P2CONST(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineToExecute)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the state shall be propagated */
  if (StateMachineToExecute->CurrentState != Scc_SMS_SchemaSpecificState)
  {
    /* ----- Local Variables ----------------------------------------------------------- */
    Scc_StateM_StateMachineStatusType statusToPropagate = Scc_StateMachineStatus_None;

    /* ----- Implementation ------------------------------------------------------------ */
    /* #20 Get the status to propagate based on the state of the passed state machine */
    switch (StateMachineToExecute->CurrentState)
    {
      case Scc_SMS_Initialized:
        statusToPropagate = Scc_StateMachineStatus_Initialized;
        break;
  #if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
      case Scc_SMS_SLAC:
        statusToPropagate = Scc_StateMachineStatus_SLAC;
        break;
  #endif /* SCC_ENABLE_SLAC_HANDLING */
      case Scc_SMS_WaitForIPAddress:
        statusToPropagate = Scc_StateMachineStatus_WaitForIP;
        break;
      case Scc_SMS_SECCDiscoveryProtocol:
        statusToPropagate = Scc_StateMachineStatus_SECCDiscoveryProtocol;
        break;
      case Scc_SMS_TLConnection:
        statusToPropagate = Scc_StateMachineStatus_TLConnection;
        break;
      case Scc_SMS_SupportedAppProtocol:
        statusToPropagate = Scc_StateMachineStatus_SupportedAppProtocol;
        break;
      case Scc_SMS_SessionSetup:
        statusToPropagate = Scc_StateMachineStatus_SessionSetup;
        break;
#if ( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 )
      case Scc_SMS_ACDP_VehiclePositioning:
        statusToPropagate = Scc_StateMachineStatus_ACDP_VehiclePositioning;
        break;
#endif /* SCC_SCHEMA_ISO_20ACDP */
#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
      case Scc_SMS_FinePositioningSetup:
        statusToPropagate = Scc_StateMachineStatus_FinePositioningSetup;
        break;
      case Scc_SMS_FinePositioning:
        statusToPropagate = Scc_StateMachineStatus_FinePositioning;
        break;
      case Scc_SMS_Pairing:
        statusToPropagate = Scc_StateMachineStatus_Pairing;
        break;
#endif /* SCC_SCHEMA_ISO_20WPT */
#if ( ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0u ))
      case Scc_SMS_AuthorizationSetup:
        statusToPropagate = Scc_StateMachineStatus_AuthorizationSetup;
        break;
#endif /* SCC_SCHEMA_ISO_20 */
#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
      case Scc_SMS_ReadContrCertChain:
        statusToPropagate = Scc_StateMachineStatus_ReadContrCertChain;
        break;
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
      case Scc_SMS_ReadOEMProvCert:
        statusToPropagate = Scc_StateMachineStatus_ReadOEMProvCert;
        break;
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */
      case Scc_SMS_ServiceDiscovery:
        statusToPropagate = Scc_StateMachineStatus_ServiceDiscovery;
        break;
#if (( defined SCC_ENABLE_PNC_CHARGING ) && ( SCC_ENABLE_PNC_CHARGING != 0u ))
      case Scc_SMS_ReadContractCertificate:
        statusToPropagate = Scc_StateMachineStatus_ReadContractCertificate;
        break;
      case Scc_SMS_ReadRootCertificate:
        statusToPropagate = Scc_StateMachineStatus_ReadRootCertificate;
        break;
#endif /* SCC_ENABLE_PNC_CHARGING */
#if (( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0u ))
      case Scc_SMS_DeterminePaymentOption:
        statusToPropagate = Scc_StateMachineStatus_DeterminePaymentOption;
        break;
      case Scc_SMS_VASList:
        statusToPropagate = Scc_StateMachineStatus_VASList;
        break;
#endif /* SCC_SCHEMA_ISO */
  #if ( (( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0u )) || (( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0u )))/* PRQA S 3332 */ /* MD_Scc_3332 */
      case Scc_SMS_ServiceDetail:
        statusToPropagate = Scc_StateMachineStatus_ServiceDetail;
        break;
  #endif /* SCC_SCHEMA_ISO || SCC_SCHEMA_ISO_20 */
      case Scc_SMS_PaymentServiceSelection:
        statusToPropagate = Scc_StateMachineStatus_PaymentServiceSelection;
        break;
  #if ( SCC_ENABLE_PNC_CHARGING == STD_ON ) \
   || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
      case Scc_SMS_CertificateInstallation:
        statusToPropagate = Scc_StateMachineStatus_CertificateInstallation;
        break;
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */
#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
      case Scc_SMS_CertificateUpdate:
        statusToPropagate = Scc_StateMachineStatus_CertificateUpdate;
        break;
      case Scc_SMS_PaymentDetails:
        statusToPropagate = Scc_StateMachineStatus_PaymentDetails;
        break;
  #endif /* SCC_ENABLE_PNC_CHARGING */

      case Scc_SMS_Authorization:
        statusToPropagate = Scc_StateMachineStatus_Authorization;
        break;
      case Scc_SMS_ChargeParameterDiscovery:
        statusToPropagate = Scc_StateMachineStatus_ChargeParameterDiscovery;
        break;
#if ( ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0u ))
      case Scc_SMS_ScheduleExchange:
        statusToPropagate = Scc_StateMachineStatus_ScheduleExchange;
        break;
#endif
#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
      case Scc_SMS_AlignmentCheck:
        statusToPropagate = Scc_StateMachineStatus_AlignmentCheck;
        break;
#endif /* SCC_SCHEMA_ISO_20WPT */
  #if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
      case Scc_SMS_CableCheck:
        statusToPropagate = Scc_StateMachineStatus_CableCheck;
        break;
      case Scc_SMS_PreCharge:
        statusToPropagate = Scc_StateMachineStatus_PreCharge;
        break;
  #endif /* SCC_CHARGING_DC */

      case Scc_SMS_PowerDelivery:
        statusToPropagate = Scc_StateMachineStatus_PowerDelivery;
        break;
#if ( ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0u ))
      case Scc_SMS_ChargeLoop:
        statusToPropagate = Scc_StateMachineStatus_ChargeLoop;
        break;
#endif /* SCC_SCHEMA_ISO_20 */
  #if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 ) \
   && ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
      case Scc_SMS_ChargingStatus:
        statusToPropagate = Scc_StateMachineStatus_ChargingStatus;
        break;
  #endif /* SCC_SCHEMA_ISO && SCC_CHARGING_AC */
  #if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
      case Scc_SMS_CurrentDemand:
        statusToPropagate = Scc_StateMachineStatus_CurrentDemand;
        break;
  #endif /* SCC_CHARGING_DC */
  #if ( SCC_ENABLE_PNC_CHARGING == STD_ON ) \
   || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
      case Scc_SMS_MeteringReceipt:
        statusToPropagate = Scc_StateMachineStatus_MeteringReceipt;
        break;
  #endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */
  #if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
      case Scc_SMS_WeldingDetection:
        statusToPropagate = Scc_StateMachineStatus_WeldingDetection;
        break;
  #endif /* SCC_CHARGING_DC */
  #if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
      case Scc_SMS_ACDP_Connect:
        statusToPropagate = Scc_StateMachineStatus_ACDP_Connect;
        break;
      case Scc_SMS_ACDP_Disconnect:
        statusToPropagate = Scc_StateMachineStatus_ACDP_Disconnect;
        break;
  #endif /* SCC_SCHEMA_ISO_20ACDP */
  #if (( defined SCC_ENABLE_ACDP_SYSTEM_STATUS ) && ( SCC_ENABLE_ACDP_SYSTEM_STATUS != 0 ))
      case Scc_SMS_ACDP_SystemStatus:
        statusToPropagate = Scc_StateMachineStatus_ACDP_SystemStatus;
        break;
  #endif /* SCC_ENABLE_ACDP_SYSTEM_STATUS */
      case Scc_SMS_SessionStop:
        statusToPropagate = Scc_StateMachineStatus_SessionStop;
        break;
      case Scc_SMS_StopCommunicationSession:
        statusToPropagate = Scc_StateMachineStatus_StopCommunicationSession;
        break;
      case Scc_SMS_AbortCommunicationSession:
        statusToPropagate = Scc_StateMachineStatus_AbortCommunicationSession;
        break;
  #if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
      case Scc_SMS_LeavePLCNetwork:
        statusToPropagate = Scc_StateMachineStatus_LeavePLCNetwork;
        break;
      case Scc_SMS_Error_LeavePLCNetwork:
        statusToPropagate = Scc_StateMachineStatus_Error_LeavePLCNetwork;
        break;
  #endif /* SCC_ENABLE_SLAC_HANDLING */
      case Scc_SMS_WaitingForRetry:
        statusToPropagate = Scc_StateMachineStatus_WaitingForRetry;
        break;
      case Scc_SMS_Stopped:
        statusToPropagate = Scc_StateMachineStatus_Finished;
        break;
#if ( ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0u ))
      case Scc_SMS_RestoreOldSessionInformation:
        statusToPropagate = Scc_StateMachineStatus_RestoreOldSessionInformation;
        break;
#endif
      case Scc_SMS_Error_WaitingForRetry:
        statusToPropagate = Scc_StateMachineStatus_Error_WaitingForRetry;
        break;
      case Scc_SMS_Error_Stopped:
        statusToPropagate = Scc_StateMachineStatus_Error_Stopped;
        break;

      default:
        /* IF DET is enabled: Report a DET error */
  #if(SCC_DEV_ERROR_REPORT == STD_ON)
        (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_DET_GENERIC_STATEM_PROPAGATE, 0xFF);
  #endif
        break;
    }

    /* #30 Propagate the current state to the application */
    Scc_StateM_InterfaceCfg_Set_StateMachineStatus(statusToPropagate);
  }
}



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateMachineGeneric_Init(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineToInitialize,
  Scc_StateMachineGeneric_SetupFunctionsFctType SetupFunctionPtr,
  Scc_StateMachineGeneric_TimeoutFctType GlobalTimeoutFunctionPtr,
  Scc_StateMachineGeneric_ParamCheckFctType  GlobalCheckFunctionPtr,
  Scc_StateMachineGeneric_ErrorFctType GlobalErrorFunctionPtr)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Initialize the state variables */
  StateMachineToInitialize->CurrentState = Scc_SMS_Uninitialized;
  StateMachineToInitialize->NextState = Scc_SMS_Initialized;
  StateMachineToInitialize->CurrentSubState = Scc_StateMachineGeneric_Prepare;

  /* #20 Initialize the passed function pointers */
  StateMachineToInitialize->SetupFunctionsPtr = SetupFunctionPtr;
  StateMachineToInitialize->GlobalCheckFunctionPtr = GlobalCheckFunctionPtr;
  StateMachineToInitialize->GlobalTimeoutFunctionPtr = GlobalTimeoutFunctionPtr;
  StateMachineToInitialize->GlobalErrorFunctionPtr = GlobalErrorFunctionPtr;

  /* #30 Initialize other values */
  StateMachineToInitialize->SequencePerformanceTimerId = Scc_StateMachineTimer_SequencePerformance;
  StateMachineToInitialize->ChannelNumber = SCC_CHANNEL_MAX;
}

/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_SetSequencePerformanceTimerId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateMachineGeneric_SetSequencePerformanceTimerId(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineToInitialize,
  Scc_StateMachineTimerEnumType        SequencePerformanceTimerId)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Set value */
  StateMachineToInitialize->SequencePerformanceTimerId = SequencePerformanceTimerId;
}

/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_SetChannelNumber
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateMachineGeneric_SetChannelNumber(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineToInitialize,
  Scc_CoreChannelType                  ChannelNumber)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Set value */
  StateMachineToInitialize->ChannelNumber = ChannelNumber;
}

/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_ForceState
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateMachineGeneric_ForceState(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineToChange,
  Scc_StateM_StateType ForceState)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Force the next state */
  StateMachineToChange->NextState = ForceState;
}

/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_Execute
 *********************************************************************************************************************/
/*!
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
FUNC(Scc_StateMachineReturnType, SCC_CODE) Scc_StateMachineGeneric_Execute(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineToExecute)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineReturnType retVal = Scc_StateMachine_Pending;
  Scc_CoreChannelType channelNumber = StateMachineToExecute->ChannelNumber;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if channel number is valid */
  if (channelNumber < SCC_CHANNEL_MAX)
  {
    /* #20 Set the current channel number to the application */
    Scc_StateM_InterfaceCfg_Set_CurrentChannel(channelNumber);
  }

  /* #30 Check if a state transition occurred */
  if (StateMachineToExecute->NextState != StateMachineToExecute->CurrentState)
  {
    /* #40 Yes: Start preparation of new state */
    StateMachineToExecute->SetupFunctionsPtr(StateMachineToExecute->NextState, &StateMachineToExecute->CurrentStateConfig);
    StateMachineToExecute->CurrentState = StateMachineToExecute->NextState;
  }

  /* #50 Trigger global timer check */
  Scc_StateMachineGeneric_StepGlobalTimerCheck(StateMachineToExecute);

  /* #60 Trigger global parameter check */
  Scc_StateMachineGeneric_StepGlobalParamCheck(StateMachineToExecute);

  /* #70 Process current state */
  Scc_StateMachineGeneric_ProcessState(StateMachineToExecute);

  /* #80 Check if the state machine has finished its operation */
  if (StateMachineToExecute->CurrentSubState == Scc_StateMachineGeneric_Finish)
  {
    retVal = Scc_StateMachine_Finished;
  }
  /* #90 Check if the state machine has failed and should be aborted */
  else if (StateMachineToExecute->CurrentSubState == Scc_StateMachineGeneric_Abort)
  {
    retVal = Scc_StateMachine_Aborted;
  }
  /* #100 Otherwise the state machine can be continued */
  else
  {
    /* The state machine can be continued */
  }
  /* #110 Check if channel number is valid */
  if (channelNumber < SCC_CHANNEL_MAX)
  {
    /* #120 Propogate end of channel execution */
    Scc_StateM_InterfaceCfg_Set_FinishProcessingCurrentChannel(channelNumber);
  }

  return retVal;
}

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE */

/**********************************************************************************************************************
 *  END OF FILE: Scc_StateMachineGeneric.c
 *********************************************************************************************************************/
