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
/*!        \file  Scc_OppCharge_StateM.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to SPEC OppCharge_ISO-15118-2_Extension_v1.03
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_OPPCHARGE_STATEM_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
 /*lint -e546 */ /* Suppress the 'Suspicious use of &' warning because the '&' is required by MISRA per Id 1502. */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_OppCharge_StateM.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON && (defined(SCC_SCHEMA_OPP_CHARGE) && SCC_SCHEMA_OPP_CHARGE != 0u) )

#include "Scc_StateM_ParamsCfg.h"
#include "Scc_OppCharge_TimerCfg.h"

#include "Scc.h"
#include "Scc_StateM_InterfaceCfg.h"
#include "Scc_StateM_Vector.h"
#include "Scc_Priv.h"

#if ( SCC_DEV_ERROR_DETECT == STD_ON )
# include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* Structure to keep track of received data from an EVSE.
 * It gets updated in the registered callouts of the core.
 */
typedef struct
{
  Scc_StateM_EVSEProcessingType           EVSEProcessing;     /**< Received processing information of the EVSE */
  Scc_BitType DC_Extended : 1;                                /**< Received energy transfer mode that is supported by EVSE */
  Exi_DIN_isolationLevelType              IsolationStatus;
  Scc_StateM_EVSENotificationType         EVSENotification;
}Scc_OppCharge_RxEVSEStructType;

/* Structure to keep track of what the application/state machine wants to send.
 * This information is fetched by the core by calling the registered callouts. */
typedef struct
{
  Scc_StateM_EnergyTransferModeType  EnergyTransferMode; /**< Chosen energy transfer mode of the application */
  Scc_StateM_ChargeStatusType        ChargeStatus;       /**< Charge status that is set by the state machine */
}Scc_OppCharge_TxEVSEStructType;

/* Contains all state machine relevent information which may need to be persisted over multiple main function cycles
 */
typedef struct
{
  Scc_StateMachineGenericStructType StateMachine;                 /**< The state machine to execute */
  Scc_StateM_ControlPilotStateType  LastControlPilotState;        /**< Last control pilot state. Is only updated if a change on CP is detected */
  Scc_OppCharge_RxEVSEStructType RxEVSE;                           /**< Information that was received by an EVSE */
  Scc_OppCharge_TxEVSEStructType TxEVSE;                           /**< Information that is going to be send to an EVSE */
}Scc_OppCharge_StateMLocalStructType;

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/* other variables */
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

SCC_LOCAL VAR(Scc_OppCharge_StateMLocalStructType, SCC_VAR_NOINIT) Scc_OppCharge_StateMLocal;

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  Scc_OppCharge_StateM<StateMachineState>_Prepare
 *********************************************************************************************************************/
/*! \brief          Prepares all parameters needed to transmit the associated request message
 *  \details        Set all parameters, the message trigger and the cyclic message trigger.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_OPP_CHARGE
 *********************************************************************************************************************/
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMSessionSetup_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMServiceDiscovery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMPaymentServiceSelection_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMAuthorization_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMChargeParameterDiscovery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMCableCheck_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMPreCharge_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMCurrentDemand_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMSessionStop_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_OppCharge_StateM<StateMachineState>_Wait
 *********************************************************************************************************************/
/*! \brief          Wait for reception of the associated response message.
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_OPP_CHARGE
 *********************************************************************************************************************/
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMSessionSetup_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMServiceDiscovery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMPaymentServiceSelection_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMAuthorization_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMChargeParameterDiscovery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMCableCheck_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMPreCharge_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMCurrentDemand_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMSessionStop_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_OppCharge_StateM<StateMachineState>_Process
 *********************************************************************************************************************/
/*! \brief          Processes the received response message
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_OPP_CHARGE
 *********************************************************************************************************************/
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMSessionSetup_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMServiceDiscovery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMPaymentServiceSelection_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMAuthorization_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMChargeParameterDiscovery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMCableCheck_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMPreCharge_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMCurrentDemand_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_OppCharge_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMSessionStop_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);



/**********************************************************************************************************************
 *  Scc_OppCharge_StateMGlobalParamCheck
 *********************************************************************************************************************/
/*! \brief          Global parameter check during OppCharge based communication
 *  \details        -
 *  \param[out]     ErrorInformation              Contains the information which was set by the function if return value is failed
 *  \return         Scc_StateMachineState_Done    No error was detected
 *  \return         Scc_StateMachineState_Failed  An error was detected
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_OPP_CHARGE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMGlobalParamCheck(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMGlobalTimerCheck
 *********************************************************************************************************************/
/*! \brief          Global timer check during OppCharge based communication
 *  \details        -
 *  \param[in]      CurrentState                  The current state of the state machine
 *  \param[out]     ErrorInformation              Contains the information which was set by the function if return value is failed
 *  \return         Scc_StateMachineState_Done    No error was detected
 *  \return         Scc_StateMachineState_Failed  An error was detected
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_OPP_CHARGE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMGlobalTimerCheck(
  Scc_StateM_StateType CurrentState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMErrorHandling
 *********************************************************************************************************************/
/*! \brief          Global error handling during OppCharge based communication
 *  \details        -
 *  \param[out]     NextState                     The next state to execute if return value indicates success
 *  \param[in]      ErrorReason                   Information why the error handling is triggered
 *  \return         Scc_StateMachineState_Done    Error handling was successfull
 *  \return         Scc_StateMachineState_Failed  Error handling failed
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_OPP_CHARGE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMErrorHandling(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  Scc_StateM_StateMachineErrorType ErrorReason);



/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMGlobalParamCheck
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMGlobalParamCheck(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  Scc_StateM_ControlPilotStateType controlPilotState = Scc_ControlPilotState_None;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Get the current CP state */
  Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);

  /* #20 Check if the CP changed */
  if (controlPilotState != Scc_OppCharge_StateMLocal.LastControlPilotState)
  {
    /* #30 Update the function-local control pilot status */
    Scc_OppCharge_StateMLocal.LastControlPilotState = controlPilotState;

    /* This is okay since the pantograph may disconnect the physical connection
     * but has not reached its home position yet. Therefore this should not be
     * considered as an error. */
    /* #40 Check if plug out (state A,E,F) is allowed */
    if ( (controlPilotState == Scc_ControlPilotState_State_A_E_F)
      && (Scc_SMS_CableCheck < Scc_OppCharge_StateMLocal.StateMachine.CurrentState)
      && (Scc_SMS_SessionStop > Scc_OppCharge_StateMLocal.StateMachine.CurrentState) )
    {
      /* #50 Plug out while in active charging session, propagate invalid CP state */
      /* Error shutdown */
      *ErrorInformation = Scc_SMER_InvalidControlPilotState;
      retVal = Scc_StateMachineState_Failed;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMGlobalTimerCheck
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMGlobalTimerCheck(
  Scc_StateM_StateType CurrentState, /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(CurrentState);                                                                              /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* 8.7.1 Restriction: ReadyToCharge and CommunicationSetup timer are not used */
  /* OppCharge does not specify the chapter "EVCC timing and error handling for cable check timeout"
   * Therefore the cable check timer is not checked. */

  /* #10 [V2G2-438]: Monitor V2G_EVCC_Msg_Timer  */
  if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_SequencePerformance) == TRUE)
  {
    /* #20 Propagate error information that the timer has expired */
    *ErrorInformation = Scc_SMER_Timer_SequencePerformanceTimer;
  }
  /* #30 [V2G2-706]: Monitor V2G_EVCC_PreCharge_Timer */
  else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_PreCharge) == TRUE)
  {
    /* #40 Propagate error information that the timer has expired */
    *ErrorInformation = Scc_SMER_Timer_PreChargeTimer;
  }
  /* #50 No timer expired */
  else
  {
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMErrorHandling
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMErrorHandling(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  Scc_StateM_StateMachineErrorType ErrorReason)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Report the error reason to the application */
  Scc_StateM_InterfaceCfg_Set_StateMachineError(ErrorReason);

  /* Based on state set state machine to SessionStop */
  if ( (Scc_SMS_SessionSetup < Scc_OppCharge_StateMLocal.StateMachine.CurrentState)
    && (Scc_SMS_SessionStop > Scc_OppCharge_StateMLocal.StateMachine.CurrentState) )
  {
    *NextState = Scc_SMS_SessionStop;
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}


/**********************************************************************************************************************/
/* Session Setup                                                                                                      */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_OppCharge_StateMSessionSetup_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMSessionSetup_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-485] Trigger the SessionSetup request */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_SessionSetup, FALSE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMSessionSetup_Wait
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
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMSessionSetup_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G2-449] Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_SessionSetup_OK)
  {
    /* #20 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G2-486] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_SessionSetup_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
  }
  /* #50 Otherwise */
  else
  {
    /* #60 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMSessionSetup_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMSessionSetup_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-487]: Trigger a ServiceDiscoveryReq message */
  *NextState = Scc_SMS_ServiceDiscovery;

  return Scc_StateMachineState_Done;
}


/**********************************************************************************************************************/
/* Service Discovery                                                                                                  */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_OppCharge_StateMServiceDiscovery_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMServiceDiscovery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-487] Trigger the ServiceDiscovery request */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_ServiceDiscovery, FALSE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMServiceDiscovery_Wait
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
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMServiceDiscovery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_ServiceDiscovery_OK)
  {
    /* #20 Proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G2-488] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_ServiceDiscovery_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
  }
  /* #50 Otherwise */
  else
  {
    /* #60 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMServiceDiscovery_Process
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
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMServiceDiscovery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  uint8 EnergyTransferModeFlags = 0;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G2-490] Set the new state to PaymentServiceSelection */
  *NextState = Scc_SMS_PaymentServiceSelection;

  /* #20 [V2G2-OC-272_1]: Check received energy transfer modes */
  if ((Scc_OppCharge_StateMLocal.RxEVSE.DC_Extended == SCC_STATEM_ENERGY_TRANSFER_MODE_ENABLED))
  {
    /* #30 Store mode for communication session */
    EnergyTransferModeFlags = (uint8)Scc_EnergyTransferMode_DC_Extended;
  }
  /* #40 Otherwise */
  else
  {
    /* #50 Propagate invalid energy transfer mode error */
    *ErrorInformation = Scc_SMER_ServiceDiscovery_InvalidEnergyTransferMode;
    retVal = Scc_StateMachineState_Failed;
  }

  /* #60 Propagate the supported energy transfer modes to the application */
  Scc_StateM_InterfaceCfg_Set_EnergyTransferModeFlags(EnergyTransferModeFlags);

  return retVal;
}


/**********************************************************************************************************************/
/* Service Payment Selection                                                                                          */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_OppCharge_StateMPaymentServiceSelection_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMPaymentServiceSelection_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-490], [V2G2-493] trigger the PaymentServiceSelection request */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_PaymentServiceSelection, FALSE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMPaymentServiceSelection_Wait
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
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMPaymentServiceSelection_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_PaymentServiceSelection_OK)
  {
    /* #20 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G2-492] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_PaymentServiceSelection_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
  }
  /* #50 Otherwise */
  else
  {
    /* #60 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMPaymentServiceSelection_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMPaymentServiceSelection_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-509] Otherwise set the new state Authorization */
  *NextState = Scc_SMS_Authorization;

  return Scc_StateMachineState_Done;
}


/**********************************************************************************************************************/
/* Contract Authentication                                                                                            */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_OppCharge_StateMAuthorization_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMAuthorization_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-509],[V2G2-503] Trigger the Authorization request and set cyclic message trigger to false */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_Authorization, FALSE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMAuthorization_Wait
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
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMAuthorization_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_Authorization_OK)
  {
    /* #20 [V2G2-OC-213_1] Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_Authorization_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
  }
  /* #50 Otherwise */
  else
  {
    /* #60 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMAuthorization_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMAuthorization_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation )                                  /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-505], [V2G2-OC-213_1] Set the new state to ChargeParameterDiscovery */
  *NextState = Scc_SMS_ChargeParameterDiscovery;

  return Scc_StateMachineState_Done;
}


/**********************************************************************************************************************/
/* Charge Parameter Discovery                                                                                         */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_OppCharge_StateMChargeParameterDiscovery_Prepare
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMChargeParameterDiscovery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Get the current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);
  /* #20 Check if the application is not ready to continue */
  if (chargingControl != Scc_ChargingControl_NegotiateChargingParameters)
  {
    /* #30 Return Pending */
    retVal = Scc_StateMachineState_Pending;
  }
  /* #40 Otherwise */
  else
  {
    /* #50 Get the selected EnergyTransferMode from application */
    Scc_OppCharge_StateMLocal.TxEVSE.EnergyTransferMode = Scc_EnergyTransferMode_None;
    Scc_StateM_InterfaceCfg_Get_EnergyTransferMode(&Scc_OppCharge_StateMLocal.TxEVSE.EnergyTransferMode);

    /* #60 [V2G2-OC-217_1]: Only Dc_extended is allowed. Validate user input */
    if (Scc_OppCharge_StateMLocal.TxEVSE.EnergyTransferMode != Scc_EnergyTransferMode_DC_Extended)
    {
      /* #70 Invalid energry transfer mode set by application detected. */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
    /* #80 If SCC_DEV_ERROR_REPORT is enabled, report error */
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_OPPCHARGE_STATEM_CHRGPARAM_CBK, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
    }
    /* #90 Otherwise */
    else
    {
      /* #100 Trigger the ChargeParameterDiscovery request and set cyclic message trigger to false since looping is not possible */
      Scc_StateM_SetMsgTrig(Scc_MsgTrig_ChargeParameterDiscovery, FALSE);
      retVal = Scc_StateMachineState_Done;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMChargeParameterDiscovery_Wait
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
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMChargeParameterDiscovery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_ChargeParameterDiscovery_OK)
  {
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;

    /* #20 [V2G2-OC-220_1] Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G2-506] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_ChargeParameterDiscovery_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
  }
  /* #50 Otherwise */
  else
  {
    /* #60 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMChargeParameterDiscovery_Process
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMChargeParameterDiscovery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Check if EVSENotification is set to StopCharging */
  if (Scc_OppCharge_StateMLocal.RxEVSE.EVSENotification == Scc_EVSENotification_StopCharging)
  {
    /* #20 [V2G2-OC-679_1] Proceed with SessionStop */
    *NextState = Scc_SMS_SessionStop;
  }
  /* #30 Otherwise */
  else
  {
    /* #40 [V2G2-599], [V2G2-OC-220_1] Proceed with cable check */
    *NextState = Scc_SMS_CableCheck;
  }

  return Scc_StateMachineState_Done;
}


/**********************************************************************************************************************/
/* Cable Check                                                                                                        */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_OppCharge_StateMCableCheck_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMCableCheck_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-599],[V2G2-617] Trigger the Cable Check request and set cyclic message trigger to true */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_CableCheck, TRUE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMCableCheck_Wait
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
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMCableCheck_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;


  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_CableCheck_OK)
  {
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;
    /* #20 Check if EVSEProcessing is set to Ongoing */
    if (Scc_OppCharge_StateMLocal.RxEVSE.EVSEProcessing == Scc_EVSEProcessing_Ongoing)
    {
      /* #30 Start delay timer to delay the next cable check request based on configured delay time */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_CableCheckNextReqDelay());
    }

    retVal = Scc_StateMachineState_Done;
  }
  /* #40 [V2G2-524] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_CableCheck_Failed)
  {
    /* #50 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
  }
  else
  {
    /* #60 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMCableCheck_Process
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMCableCheck_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Check if EVSEProcessing is set to Finished */
  if (Scc_OppCharge_StateMLocal.RxEVSE.EVSEProcessing == Scc_EVSEProcessing_Finished)
  {
    /* #20 Check if during OppCharge if Isolation status was received as fault */
    if (Scc_OppCharge_StateMLocal.RxEVSE.IsolationStatus == EXI_DIN_ISOLATION_LEVEL_TYPE_FAULT)
    {
      /* #30 Set the new state */
      /* [V2G2-OC-524_1] */
      *NextState = Scc_SMS_SessionStop;
    }
    else if (Scc_OppCharge_StateMLocal.RxEVSE.EVSENotification == Scc_EVSENotification_StopCharging)
    {
      /* [V2G2-OC-679_1]:
      * If the parameter EVSENotification in EVSEStatus is equal to StopCharging,
      * the EVCC shall stop charging immediately. */
      *NextState = Scc_SMS_SessionStop;
    }
    else
    {
      /* #40 [V2G2-525] Set the new state to PreCharge */
      *NextState = Scc_SMS_PreCharge;
    }

    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

    retVal = Scc_StateMachineState_Done;
  }
  /* #50 [V2G2-617] Resend the CableCheckReq message if EVSEProcessing is equal to Ongoing */
  else /* EVSEProcessing_Ongoing */
  {
    *NextState = Scc_SMS_CableCheck;

    /* #60 Check if delay timer is disabled */
    if  (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #70 The next request can be send */
      retVal = Scc_StateMachineState_Done;
    }
    /* #80 Check if delay timer has expired */
    else if ((Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE))
    {
      /* #90 The next request can be send */
      retVal = Scc_StateMachineState_Done;
    }
    /* #100 Otherwise */
    else
    {
      /* #110 Wait until the delay timer has expired */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  return retVal;
}

/**********************************************************************************************************************/
/* Pre Charge                                                                                                         */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_OppCharge_StateMPreCharge_Prepare
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMPreCharge_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-525]: Trigger the pre charge request */
  /* #20 Set the cyclic trigger  and set cyclic message trigger to true */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_PreCharge, TRUE);

  /* #30 [V2G2-704]: Start the pre charge timeout only once */
  /* Start the pre charge timer only for the first time a PreCharge message
    * is sent in the communication session. Consecutive pre charge messages issued
    * due to an unmatching output voltage at EVSE should not restart the timer. */
  if (Scc_StateMachineTimer_IsStarted(Scc_StateMachineTimer_PreCharge) == FALSE)
  {
    /* #40 Start pre charge timer based on configured timeout value */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_PreCharge, Scc_StateM_ParamCfg_Get_PreChargeTimeout());
  }

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMPreCharge_Wait
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
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMPreCharge_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;


  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_PreCharge_OK)
  {
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;
    /* #20 Start delay timer to delay the next pre charge request based on configured delay time */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_PreChargeNextReqDelay());

    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G2-526] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_PreCharge_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
  }
  /* #50 Otherwise */
  else
  {
    /* #60 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMPreCharge_Process
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
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMPreCharge_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Get the current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* #20 Check if EVSENotification is set to StopCharging */
  if (Scc_OppCharge_StateMLocal.RxEVSE.EVSENotification == Scc_EVSENotification_StopCharging)
  {
    /* #30 Stop the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* #40 Stop the V2G_EVCC_PreCharge_Timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_PreCharge);

    /* #50 [V2G2-OC-679_1] Proceed with SessionStop */
    *NextState = Scc_SMS_SessionStop;
  }
  /* #60 Otherwise check if the application wants to stop the PreCharge sequence */
  else if (chargingControl == Scc_ChargingControl_PreChargeCompleted)
  {
    /* [V2G2-711] */
    /* #70 Stop the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* #80 Stop the V2G_EVCC_PreCharge_Timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_PreCharge);

    /* #90 [V2G2-528] Proceed with power delivery */
    *NextState = Scc_SMS_PowerDelivery;

    retVal = Scc_StateMachineState_Done;
  }
  /* #100 Otherwise */
  else
  {
    /* #110 [V2G2-618] Continue with PreCharge */
    *NextState = Scc_SMS_PreCharge;

    /* #120 Check if delay timer is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #130 The next request can be send */
      retVal = Scc_StateMachineState_Done;
    }
    /* #140 Check if delay timer has expired */
    else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #150 The next request can be send */
      retVal = Scc_StateMachineState_Done;
    }
    /* #160 Otherwise */
    else
    {
      /* #170 Wait until the delay timer has expired */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  return retVal;
}


/**********************************************************************************************************************/
/* Power Delivery                                                                                                     */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_OppCharge_StateMPowerDelivery_Prepare
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMPowerDelivery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Get the current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* #20 Check if the charging control indicates that charging shall be started */
  if (chargingControl == Scc_ChargingControl_StartPowerDelivery)
  {
    /* #30 [V2G2-OC-222_1] Trigger a power delivery request with ReadyToChargeState set to TRUE */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_PowerDelivery, FALSE);

    Scc_OppCharge_StateMLocal.TxEVSE.ChargeStatus = Scc_ChargeStatus_Starting;

    retVal = Scc_StateMachineState_Done;
  }
  /* #40 [V2G2-513] Check if the charging control indicates that charging shall be stopped or paused */
  else if (chargingControl == Scc_ChargingControl_StopCharging)
  {
    /* #50 [V2G2-OC-222_1] Trigger the PowerDelivery request with ReadyToChargeState set to FALSE */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_PowerDelivery, FALSE);

    Scc_OppCharge_StateMLocal.TxEVSE.ChargeStatus = Scc_ChargeStatus_Stopping;

    retVal = Scc_StateMachineState_Done;
  }
  /* #60 Otherwise */
  else
  {
    /* #70 Wait until application becomes ready */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMPowerDelivery_Wait
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMPowerDelivery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_PowerDelivery_OK)
  {
    retVal = Scc_StateMachineState_Done;
  }
  /* #20 [V2G2-799] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_PowerDelivery_Failed)
  {
    /* #30 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
  }
  /* #40 Otherwise */
  else
  {
    /* #50 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMPowerDelivery_Process
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMPowerDelivery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Check if EVSENotification is set to StopCharging */
  if (Scc_OppCharge_StateMLocal.RxEVSE.EVSENotification == Scc_EVSENotification_StopCharging)
  {
    /* #20 [V2G2-OC-679_1] Proceed with SessionStop */
    *NextState = Scc_SMS_SessionStop;
  }
  /* #30 Otherwise check if charging shall be started */
  else if (Scc_OppCharge_StateMLocal.TxEVSE.ChargeStatus == Scc_ChargeStatus_Starting)
  {
    /* #40 [V2G2-530]: Proceed with current demand */
    *NextState = Scc_SMS_CurrentDemand;
    retVal = Scc_StateMachineState_Done;
  }
  /* #50 [V2G2-520], [V2G2-619]: Check how charging shall be proceeded */
  else /* Scc_ChargeStatus_Stopping */
  {
    Scc_StateM_ControlPilotStateType controlPilotState = Scc_ControlPilotState_None;

    /* #60 Get the current CP state from application */
    Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);

    /* #70 Check if current CP state does not equal state "B" (the power switch is still closed) */
    if (controlPilotState != Scc_ControlPilotState_State_B)
    {
      /* #80 Wait until application releases CP state */
      retVal = Scc_StateMachineState_Pending;
    }
    /* #90 Otherwise */
    else
    {
      /* #100 Proceed with session stop */
      *NextState = Scc_SMS_SessionStop;

      retVal = Scc_StateMachineState_Done;
    }
  }

  return retVal;
}


/**********************************************************************************************************************/
/* Current Demand                                                                                                     */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_OppCharge_StateMCurrentDemand_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMCurrentDemand_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-530],[V2G2-531] Trigger the CurrentDemand request and set cyclic message trigger to true */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_CurrentDemand, TRUE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMCurrentDemand_Wait
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMCurrentDemand_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_CurrentDemand_OK)
  {
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;
    /* #20 Start delay timer to delay the next current demand request based on configured delay time */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_CurrentDemandNextReqDelay());
    /* #30 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #40 [V2G2-532] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_CurrentDemand_Failed)
  {
    /* #50 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
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
 *  Scc_OppCharge_StateMCurrentDemand_Process
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMCurrentDemand_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Get the current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* #20 Check if the charging shall be stopped */
  if (Scc_OppCharge_StateMLocal.RxEVSE.EVSENotification == Scc_EVSENotification_StopCharging)
  {
    /* #30 [V2G2-OC-679_1]: Change state to SessionStop */
    *NextState = Scc_SMS_SessionStop;

    /* #40 Stop the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

    retVal = Scc_StateMachineState_Done;
  }
  else if (chargingControl == Scc_ChargingControl_StopCharging)
  {
    /* #50 Stop the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

    /* #60 [V2G2-527]: Proceed with power delivery */
    *NextState = Scc_SMS_PowerDelivery;

    retVal = Scc_StateMachineState_Done;
  }
  /* #70 Otherwise */
  else
  {
    /* #80 [V2G2-531]: Continue with CurrentDemand */
    *NextState = Scc_SMS_CurrentDemand;

    /* #90 Check if delay timer is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #100 The next request can be send */
      retVal = Scc_StateMachineState_Done;
    }
    /* #110 Check if delay timer has expired */
    else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #120 The next request can be send */
      retVal = Scc_StateMachineState_Done;
    }
    else
    {
      /* #130 Wait until the delay timer has expired */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  return retVal;
}


/**********************************************************************************************************************/
/* Session Stop                                                                                                       */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_OppCharge_StateMSessionStop_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMSessionStop_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Trigger the session stop request with Cyclic trigger */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_SessionStop, TRUE);
  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateMSessionStop_Wait
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMSessionStop_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_SessionStop_OK)
  {
    /* #20 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G2-507] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_SessionStop_Failed)
  {
    /* #40 Start delay timer to delay the next cable check request based on configured delay time */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_SessionStopNextReqDelay());

    /* #50 [V2G2-OC-507_1], [V2G2-OC-507_2] Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
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
 *  Scc_OppCharge_StateMSessionStop_Process
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_OppCharge_StateMSessionStop_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,                                                      /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_SessionStop_OK)
  {
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

    /* #20 Reset the SessionID */
    (void)Scc_ResetSessionID(TRUE);

    /* #30 [V2G2-508] Set return as finished. Common part has to take care of shutting down the connection */
    retVal = Scc_StateMachineState_Finished;
  }
  /* #40 [V2G2-507] Check if invalid response was received */
  else /* Scc_MsgStatus_SessionStop_Failed */
  {
    /* #50 [V2G2-OC-507_1] Stay in state SessionStop to send SessionStopReq */
    *NextState = Scc_SMS_SessionStop;

    /* #60 Check if delay timer is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* Reset error so that the ErrorHandling function is not entered till a new error is reported */
      Scc_ResetError();

      /* #70 The next request can be send */
      retVal = Scc_StateMachineState_Done;
    }
    /* #80 Check if delay timer has expired */
    else if ((Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE))
    {
      /* Reset error so that the ErrorHandling function is not entered till a new error is reported */
      Scc_ResetError();

      /* #90 The next request can be send */
      retVal = Scc_StateMachineState_Done;
    }
    /* #100 Otherwise */
    else
    {
      /* #110 Wait until the delay timer has expired */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  return retVal;
}



/**********************************************************************************************************************/
/* State Machine Specific Functions                                                                                   */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_OppCharge_StateMSetupStateFunctions
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_OppCharge_StateMSetupStateFunctions(
  Scc_StateM_StateType StateToSetup,
  P2VAR(Scc_StateMachineGenericStateStructType, AUTOMATIC, SCC_APPL_DATA) CommonStatePtr)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Setup the internal state machine function pointers based on the passed state */
  switch (StateToSetup)
  {
    case Scc_SMS_SessionSetup:
      CommonStatePtr->PrepareFunctionPtr = &Scc_OppCharge_StateMSessionSetup_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_OppCharge_StateMSessionSetup_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_OppCharge_StateMSessionSetup_Process;
      break;

    case Scc_SMS_ServiceDiscovery:
      CommonStatePtr->PrepareFunctionPtr = &Scc_OppCharge_StateMServiceDiscovery_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_OppCharge_StateMServiceDiscovery_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_OppCharge_StateMServiceDiscovery_Process;
      break;

    case Scc_SMS_PaymentServiceSelection:
      CommonStatePtr->PrepareFunctionPtr = &Scc_OppCharge_StateMPaymentServiceSelection_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_OppCharge_StateMPaymentServiceSelection_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_OppCharge_StateMPaymentServiceSelection_Process;
      break;

    case Scc_SMS_Authorization:
      CommonStatePtr->PrepareFunctionPtr = &Scc_OppCharge_StateMAuthorization_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_OppCharge_StateMAuthorization_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_OppCharge_StateMAuthorization_Process;
      break;

    case Scc_SMS_ChargeParameterDiscovery:
      CommonStatePtr->PrepareFunctionPtr = &Scc_OppCharge_StateMChargeParameterDiscovery_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_OppCharge_StateMChargeParameterDiscovery_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_OppCharge_StateMChargeParameterDiscovery_Process;
      break;

    case Scc_SMS_PowerDelivery:
      CommonStatePtr->PrepareFunctionPtr = &Scc_OppCharge_StateMPowerDelivery_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_OppCharge_StateMPowerDelivery_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_OppCharge_StateMPowerDelivery_Process;
      break;

    case Scc_SMS_CableCheck:
      CommonStatePtr->PrepareFunctionPtr = &Scc_OppCharge_StateMCableCheck_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_OppCharge_StateMCableCheck_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_OppCharge_StateMCableCheck_Process;
      break;

    case Scc_SMS_PreCharge:
      CommonStatePtr->PrepareFunctionPtr = &Scc_OppCharge_StateMPreCharge_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_OppCharge_StateMPreCharge_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_OppCharge_StateMPreCharge_Process;
      break;

    case Scc_SMS_CurrentDemand:
      CommonStatePtr->PrepareFunctionPtr = &Scc_OppCharge_StateMCurrentDemand_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_OppCharge_StateMCurrentDemand_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_OppCharge_StateMCurrentDemand_Process;
      break;

    case Scc_SMS_SessionStop:
      CommonStatePtr->PrepareFunctionPtr = &Scc_OppCharge_StateMSessionStop_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_OppCharge_StateMSessionStop_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_OppCharge_StateMSessionStop_Process;
      break;

    default:
      CommonStatePtr->PrepareFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      CommonStatePtr->ProcessResponseFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      /* Something went wrong in setup of states */
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_OPPCHARGE_STATEM_SETUP, SCC_DET_INV_PARAM);
#endif
      break;
  }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_OppCharge_StateM_Init
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_OppCharge_StateM_Init(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Initialize general data. */
  Scc_OppCharge_StateMLocal.LastControlPilotState = Scc_ControlPilotState_None;
  Scc_OppCharge_StateMLocal.RxEVSE.DC_Extended = SCC_STATEM_ENERGY_TRANSFER_MODE_DISABLED;
  Scc_OppCharge_StateMLocal.RxEVSE.EVSENotification = Scc_EVSENotification_None;
  Scc_OppCharge_StateMLocal.RxEVSE.EVSEProcessing = Scc_EVSEProcessing_Ongoing;
  Scc_OppCharge_StateMLocal.RxEVSE.IsolationStatus = EXI_DIN_ISOLATION_LEVEL_TYPE_INVALID;
  Scc_OppCharge_StateMLocal.TxEVSE.ChargeStatus = Scc_ChargeStatus_Preparing;
  Scc_OppCharge_StateMLocal.TxEVSE.EnergyTransferMode = Scc_EnergyTransferMode_None;

  /* #20 Initialize state machine */
  Scc_StateMachineGeneric_Init(&Scc_OppCharge_StateMLocal.StateMachine, &Scc_OppCharge_StateMSetupStateFunctions,
    &Scc_OppCharge_StateMGlobalTimerCheck, &Scc_OppCharge_StateMGlobalParamCheck, &Scc_OppCharge_StateMErrorHandling);
  Scc_StateMachineGeneric_SetChannelNumber(&Scc_OppCharge_StateMLocal.StateMachine, SCC_CHANNEL_DEFAULT);

  /* #30 Start handling the session setup */
  Scc_StateMachineGeneric_ForceState(&Scc_OppCharge_StateMLocal.StateMachine, Scc_SMS_SessionSetup);
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateM_Execute
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateMachineReturnType, SCC_CODE) Scc_OppCharge_StateM_Execute(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Execute the OppCharge state machine */
  return Scc_StateMachineGeneric_Execute(&Scc_OppCharge_StateMLocal.StateMachine);
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateM_MsgRxIndication
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_OppCharge_StateM_MsgRxIndication(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Table 103_1: Start the sequence performance timeout */
  switch (Scc_OppCharge_StateMLocal.StateMachine.CurrentState)
  {
  case Scc_SMS_CableCheck:
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_SequencePerformance, Scc_OppCharge_TimerCfg_Get_SequencePerformanceTimeoutCableCheck());
    break;

  case Scc_SMS_ChargeParameterDiscovery:
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_SequencePerformance, Scc_OppCharge_TimerCfg_Get_SequencePerformanceTimeoutChargeParameterDiscovery());
    break;

  case Scc_SMS_PreCharge:
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_SequencePerformance, Scc_OppCharge_TimerCfg_Get_SequencePerformanceTimeoutPreCharge());
    break;

  case Scc_SMS_PowerDelivery:
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_SequencePerformance, Scc_OppCharge_TimerCfg_Get_SequencePerformanceTimeoutPowerDelivery());
    break;

  default:
    /* For all other messages the sequence performance timer is not used */
    break;
  }
}


/**********************************************************************************************************************/
/* State Machine Callouts                                                                                             */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_OppCharge_StateM_Set_EVSEProcessing
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_OppCharge_StateM_Set_EVSEProcessing(
  Exi_DIN_EVSEProcessingType EVSEProcessing)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set EVSEProcessing for OppCharge */
  switch (EVSEProcessing)
  {
    case EXI_DIN_EVSEPROCESSING_TYPE_ONGOING:
      Scc_OppCharge_StateMLocal.RxEVSE.EVSEProcessing = Scc_EVSEProcessing_Ongoing;
      break;

    default: /* case EXI_DIN_EVSEPROCESSING_TYPE_FINISHED: */
      Scc_OppCharge_StateMLocal.RxEVSE.EVSEProcessing = Scc_EVSEProcessing_Finished;
      break;
  }
}


/**********************************************************************************************************************
 *  Scc_OppCharge_StateM_Set_ChargeService
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_OppCharge_StateM_Set_ChargeService(
  P2CONST(Exi_DIN_ServiceChargeType, AUTOMATIC, SCC_VAR_NOINIT) ChargeService)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Handle the passed ChargeService information of a received service discovery response */
  /* #20 Reset energy transfer mode */
  Scc_OppCharge_StateMLocal.RxEVSE.DC_Extended = SCC_STATEM_ENERGY_TRANSFER_MODE_DISABLED;

  /* #30 Evaluate energy transfer mode of passed charge service */
  switch (ChargeService->EnergyTransferType)
  {
    case EXI_DIN_EVSESUPPORTED_ENERGY_TRANSFER_TYPE_DC_EXTENDED:
      Scc_OppCharge_StateMLocal.RxEVSE.DC_Extended = SCC_STATEM_ENERGY_TRANSFER_MODE_ENABLED;
      break;

    default:
      /* invalid EnergyTransferType */
      break;
  }
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateM_Set_EVSEIsolationStatus()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_OppCharge_StateM_Set_EVSEIsolationStatus(Exi_DIN_isolationLevelType IsolationLevel, Exi_BitType Flag)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if flag is set and store the received data */
  if (Flag == 1u)
  {
    Scc_OppCharge_StateMLocal.RxEVSE.IsolationStatus = IsolationLevel;
  }
  /* #20 Otherwise set value to invalid */
  else
  {
    Scc_OppCharge_StateMLocal.RxEVSE.IsolationStatus = EXI_DIN_ISOLATION_LEVEL_TYPE_INVALID;
  }
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateM_Set_EVSENotification()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_OppCharge_StateM_Set_EVSENotification(Exi_DIN_EVSENotificationType EVSENotification)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set EVSENotification for OppCharge */
  switch (EVSENotification)
  {
  case EXI_DIN_EVSENOTIFICATION_TYPE_STOP_CHARGING:
    Scc_OppCharge_StateMLocal.RxEVSE.EVSENotification = Scc_EVSENotification_StopCharging;
    break;

  default:
    Scc_OppCharge_StateMLocal.RxEVSE.EVSENotification = Scc_EVSENotification_None;
    break;
  }
}

/**********************************************************************************************************************
 *  Scc_OppCharge_StateM_Get_ReadyToChargeState
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_OppCharge_StateM_Get_ReadyToChargeState(
  P2VAR(boolean, AUTOMATIC, SCC_VAR_NOINIT) ReadyToChargeState)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 [V2G2-OC-222_1] Propagate the ReadyToChargeState information based on state machine */
  switch (Scc_OppCharge_StateMLocal.TxEVSE.ChargeStatus)
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
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_OPPCHARGE_STATEM_READYTOCHRG_CBK, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
      break;
  }
}

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE && SCC_SCHEMA_OPP_CHARGE */

/*lint +e546 */ /* Enable the 'Suspicious use of &' reporting again. */

/**********************************************************************************************************************
 *  END OF FILE: Scc_OppCharge_StateM.c
 *********************************************************************************************************************/
