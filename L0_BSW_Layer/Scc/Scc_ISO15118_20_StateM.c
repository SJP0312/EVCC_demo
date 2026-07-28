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
/*!        \file  Scc_ISO15118_20_StateM.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to ISO 15118-20.
 *                This unit takes care of dispatching all available schema specific messages/states.
 *                It also takes care of managing the common workspace that may be shared across
 *                different schema specific units.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_ISO15118_2_STATEM_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
/*lint -e546 */ /* Suppress the 'Suspicious use of &' warning because the '&' is required by MISRA per Id 1502. */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON && (defined(SCC_SCHEMA_ISO_20) && SCC_SCHEMA_ISO_20 != 0u) )

#include "Scc_ISO15118_20_StateM.h"
#include "Scc_ISO15118_20_StateMReneg.h"
#include "Scc_ISO15118_20_StateMMeter.h"
#include "Scc_ISO15118_20_StateMSysS.h"
#include "Scc_StateM_ParamsCfg.h"
#include "Scc_StateM_InterfaceCfg.h"
#include "Scc_ISO15118_20_TimerCfg.h"

#include "Scc.h"
#include "Scc_Priv.h"
#include "Scc_StateMachineTimer.h"
#include "Scc_StateM_Vector.h"

#include "Scc_ISO15118_20CM_StateM.h"
#include "Scc_ISO15118_20AC_StateM.h"
#include "Scc_ISO15118_20DC_StateM.h"
#include "Scc_ISO15118_20WPT_StateM.h"
#include "Scc_ISO15118_20ACDP_StateM.h"

#include "Scc_SAP_Exi.h"
#include "IpBase.h"

#if ( SCC_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

#define SCC_ISO15118_20_STATEM_GEN_CHALLENGE_MAX_LEN      16u

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/* other variables */
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

SCC_LOCAL VAR(Scc_ISO15118_20_StateMWsStructType, SCC_VAR_NOINIT) Scc_ISO15118_20_StateMWs;

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMGlobalParamCheck
 *********************************************************************************************************************/
/*! \brief          Global parameter check
 *  \details        -
 *  \param[out]     ErrorInformation  Pointer to error information to set. The error information is valid if
 *                                    Scc_StateMachineState_Failed is returned
 *  \return         Scc_StateMachineState_Done    No error detected
 *  \return         Scc_StateMachineState_Failed  An error was detected.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMGlobalParamCheck(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMGlobalTimerCheck
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
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMGlobalTimerCheck(
  Scc_StateM_StateType CurrentState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMErrorHandling
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
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMErrorHandling(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  Scc_StateM_StateMachineErrorType ErrorReason);


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMGlobalParamCheck
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMGlobalParamCheck(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  Scc_StateM_ControlPilotStateType controlPilotState = Scc_ControlPilotState_None;

  /* ----- Implementation ------------------------------------------------------------ */
#if ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
  /* #10 Check if NumTaxCostsExceeded */
  if (TRUE == Scc_ISO15118_20_StateMWs.RxEVSE.NumTaxCostsExceeded)
  {
    /* #20 Report Error shutdown */
    *ErrorInformation = Scc_SMER_NumOfTaxCostsExceeded;
    retVal = Scc_StateMachineState_Failed;
  }
#endif /* SCC_ENABLE_METERING_RECEIPT */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
  /* #30 Check if NumSupportedProvidersExceeded */
  if (TRUE == Scc_ISO15118_20_StateMWs.RxEVSE.NumSupportedProvidersExceeded)
  {
    /* #40 Report Error shutdown */
    *ErrorInformation = Scc_SMER_NumOfSupportedProvidersExceeded;
    retVal = Scc_StateMachineState_Failed;
  }
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

  /* #50 Check for unexpected messages */
  if (SccDetailedError_General_MainRxMessageUnexpectedMessage == Scc_StateM_GetDetailedErrorChannel(SCC_CHANNEL_DEFAULT))
  {
    /* #60 Propagate error information that an unexpected message was received */
    *ErrorInformation = Scc_SMER_UnexpectedMessage;
    retVal = Scc_StateMachineState_Failed;
    /* #70 Clear error code */
    Scc_StateM_SetDetailedErrorChannel(SccDetailedError_No_Error, SCC_CHANNEL_DEFAULT);
  }

  /* #80 Get the current state of the cable */
  Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);
  /* #90 Check if the control pilot changed */
  if (controlPilotState != Scc_ISO15118_20_StateMWs.LastControlPilotState)
  {
    /* update the function-local control pilot status */
    Scc_ISO15118_20_StateMWs.LastControlPilotState = controlPilotState;

    /* #100 [V2G2-737] check for error state (A = not connected, E = no Grid connecte, F = EVSE not available) or CP is turned off */
    /* #110 [V2G20-4028] Check if CP state is invalid */
    if (controlPilotState == Scc_ControlPilotState_State_A_E_F)
    {
      /* plug out while in active charging session */
      /* #120 Report Error shutdown */
      *ErrorInformation = Scc_SMER_InvalidControlPilotState;
      retVal = Scc_StateMachineState_Failed;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMGlobalTimerCheck
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
 *
 *
 *
 *
 *
 */
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMGlobalTimerCheck(
  Scc_StateM_StateType CurrentState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G20-436], [V2G20-438] Monitor V2G_EVCC_Msg_Timer */
  if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_SequencePerformance) == TRUE)
  {
    /* #20 Propagate error information that the timer has expired */
    *ErrorInformation = Scc_SMER_Timer_SequencePerformanceTimer;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #30 [V2G20-2298], [V2G20-448] Monitor V2G_EVCC_CommuncationSetup_Timer */
  else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_ISO15118_20_CommunicationSetup) == TRUE)
  {
    /* #40 Propagate error information that the timer has expired */
    *ErrorInformation = Scc_SMER_Timer_CommunicationSetupTimer;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #50 [V2G20-700]: Monitor V2G_EVCC_DC_CableCheck_Timer */
  else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_CableCheck) == TRUE)
  {
    /* #60 [V2G20-1398] Propagate error information that the timer has expired */
    *ErrorInformation = Scc_SMER_Timer_CableCheckTimer;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #70 [V2G20-704]: Monitor V2G_EVCC_DC_PreCharge_Timer */
  else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_PreCharge) == TRUE)
  {
    /* #80 Propagate error information that the timer has expired */
    *ErrorInformation = Scc_SMER_Timer_PreChargeTimer;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #90 [V2G20-1964], [V2G20-1651], [V2G20-5080]: Monitor MaxDelay Timer */
  else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_NotificationMaxDelayServiceReneg) == TRUE)
  {
    /* #100 Propagate error information that the timer has expired */
    *ErrorInformation = Scc_SMER_Timer_NotificationMaxDelayServiceRenegotiationTimer;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #110 [V2G20-2101] Monitor V2G_EVCC_Ongoing_Timer */
  else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_Ongoing) == TRUE)
  {
    switch (CurrentState)
    {
      /* #120 Check if in state Authorization */
    case Scc_SMS_Authorization:
      *ErrorInformation = Scc_SMER_Timer_AuthorizationOngoingTimer;
      break;
      /* #130 Check if in state ScheduleExchange */
    case Scc_SMS_ScheduleExchange:
      *ErrorInformation = Scc_SMER_Timer_ScheduleExchangeOngoingTimer;
      break;
#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
      /* #140 Check if in state CableCheck */
    case Scc_SMS_CableCheck:
      *ErrorInformation = Scc_SMER_Timer_CableCheckOngoingTimer;
      break;

      /* #150 Check if in state PreCharge */
    case Scc_SMS_PreCharge:
      *ErrorInformation = Scc_SMER_Timer_PreChargeOngoingTimer;
      break;
#endif

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
      /* #160 Check if in state CertificateInstallation */
    case Scc_SMS_CertificateInstallation:
      *ErrorInformation = Scc_SMER_Timer_CertificateInstallationOngoingTimer;
      break;
#endif /* defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
      /* #170 Check if in state FinePositioning */
    case Scc_SMS_FinePositioning:
      *ErrorInformation = Scc_SMER_Timer_FinePositioningOngoingTimer;
      break;
      /* #180 Check if in state Pairing */
    case Scc_SMS_Pairing:
      *ErrorInformation = Scc_SMER_Timer_PairingOngoingTimer;
      break;
      /* #190 Check if in state AlignmentCheck */
    case Scc_SMS_AlignmentCheck:
      *ErrorInformation = Scc_SMER_Timer_AlignmentCheckOngoingTimer;
      break;
#endif /* SCC_SCHEMA_ISO_20WPT */

# if ( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 )
      /* #200 Check if in state VehiclePositioning */
    case Scc_SMS_ACDP_VehiclePositioning:
      *ErrorInformation = Scc_SMER_Timer_VehiclePositioningOngoingTimer;
      break;
      /* #210 Check if in state Connect */
    case Scc_SMS_ACDP_Connect:
      *ErrorInformation = Scc_SMER_Timer_ConnectOngoingTimer;
      break;
      /* #220 Check if in state Disconnect */
    case Scc_SMS_ACDP_Disconnect:
      *ErrorInformation = Scc_SMER_Timer_DisconnectOngoingTimer;
      break;
#endif /* defined SCC_SCHEMA_ISO_20ACDP */

    default:
#if (SCC_DEV_ERROR_REPORT == STD_ON)
      /* This should never happen otherwise there is an issue in ISO state machine */
      /* Otherwise report an error */
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_20_STATEM_TIMER_CHECK, SCC_DET_INV_STATE);
#endif
      break;
    }

    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #230 Otherwise no timer error occurred */
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMErrorHandling
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
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20_StateMErrorHandling(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,                                                      /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
  Scc_StateM_StateMachineErrorType ErrorReason)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(*NextState);                                                                                /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  /* #10 Check if ACDP is not the selected schema */
  if (Scc_SAP_ExiRx_GetChosenSchema() != Scc_SAPSchemaIDs_ISO15118_20ACDP)
  {
#endif /* SCC_SCHEMA_ISO_20ACDP */
    /* #20 report the error to the application */
    Scc_StateM_InterfaceCfg_Set_StateMachineError(ErrorReason);

    /* Reset SessionID */
    (void)Scc_ResetSessionID(TRUE);
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  }
  /* #30 Otherwise */
  else
  {
    /* #40 report the error to the application */
    Scc_StateM_InterfaceCfg_Set_StateMachineError(ErrorReason);

    /* reset timers that could be started in StateM so that it doesn't expire after current state is left */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_CableCheck);
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_PreCharge);
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ISO15118_20_CommunicationSetup);

    /* [V2G20-4026] */
    /* #50 If current state is SessionSetup */
    if (Scc_ISO15118_20_StateMWs.StateMachineMainChannel.CurrentState <= Scc_SMS_SessionSetup)
    {
      /* #60 [V2G20-4030] Close the communication */
      /* Reset SessionID */
      (void)Scc_ResetSessionID(TRUE);
    }
    /* #70 Otherwise if state is before ACDP_Connect
     *     OR if state is ACDP_Disconnect */
    else if ( (Scc_ISO15118_20_StateMWs.StateMachineMainChannel.CurrentState < Scc_SMS_ACDP_Connect)
           || (Scc_ISO15118_20_StateMWs.StateMachineMainChannel.CurrentState == Scc_SMS_ACDP_Disconnect) )
    {
      /* #80 Check if msg timeout occurred (Table 80, ISO 15118-20) */
      if (Scc_StateM_GetDetailedErrorChannel(SCC_CHANNEL_DEFAULT) == SccDetailedError_GeneralTimeout)
      {
        /* #90 [V2G20-1966] / Table 80 - Close the communication */
        /* Reset SessionID */
        (void)Scc_ResetSessionID(TRUE);
      }
      /* #100 Otherwise */
      else
      {
        /* [V2G20-4031] to [V2G20-4038], [V2G20-4079], [V2G20-4044] */
        *NextState = Scc_SMS_SessionStop;
        retVal = Scc_StateMachineState_Done;
      }
    }
    /* #110 Otherwise */
    else
    {
      /* #120 Check if state is ChargeLoop */
      if (Scc_ISO15118_20_StateMWs.StateMachineMainChannel.CurrentState == Scc_SMS_ChargeLoop)
      {
        /* #130 Return Done so that the state remains in ChargeLoop and Application can change the
         *       ChargingControl to StopCharging after ramping down the current to go to PowerDeliveryReq(Stop) */
        retVal = Scc_StateMachineState_Done;
      }
      /* #140 Otherwise check if state is lesser than SessionStop */
      else if (Scc_ISO15118_20_StateMWs.StateMachineMainChannel.CurrentState < Scc_SMS_SessionStop)
      {
        /* #150 [V2G20-4039] to [V2G20-4043] Send ACDP_DisconnectReq */
        *NextState = Scc_SMS_ACDP_Disconnect;
        retVal = Scc_StateMachineState_Done;
      }
      /* #160 Otherwise */
      else
      {
        /* retVal is already set to Failed and communication will be shutdown */
        /* #170 Close the communication */
        /* Reset SessionID */
        (void)Scc_ResetSessionID(TRUE);
      }
    }
  }
#endif /* SCC_SCHEMA_ISO_20ACDP */


  return retVal;
}

/**********************************************************************************************************************/
/* State Machine Specific Function                                                                                    */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMSetupStateFunctions
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_20_StateMSetupStateFunctions(
  Scc_StateM_StateType StateToSetup,
  P2VAR(Scc_StateMachineGenericStateStructType, AUTOMATIC, SCC_APPL_DATA) CommonStatePtr)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Setup the internal state machine function pointers based on the passed state */
  switch (StateToSetup)
  {
    case Scc_SMS_SessionSetup:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20CM_StateMSessionSetup_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20CM_StateMSessionSetup_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20CM_StateMSessionSetup_Process;
      break;

#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
    case Scc_SMS_FinePositioningSetup:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20WPT_StateMWPT_FinePositioningSetup_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20WPT_StateMWPT_FinePositioningSetup_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20WPT_StateMWPT_FinePositioningSetup_Process;
      break;

    case Scc_SMS_FinePositioning:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20WPT_StateMWPT_FinePositioning_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20WPT_StateMWPT_FinePositioning_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20WPT_StateMWPT_FinePositioning_Process;
      break;

    case Scc_SMS_Pairing:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20WPT_StateMWPT_Pairing_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20WPT_StateMWPT_Pairing_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20WPT_StateMWPT_Pairing_Process;
      break;
#endif /* SCC_SCHEMA_ISO_20WPT */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
    case Scc_SMS_ReadContrCertChain:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20CM_StateMReadContrCertChain_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20CM_StateMReadContrCertChain_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20CM_StateMReadContrCertChain_Process;
      break;
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

    case Scc_SMS_AuthorizationSetup:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20CM_StateMAuthorizationSetup_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20CM_StateMAuthorizationSetup_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20CM_StateMAuthorizationSetup_Process;
      break;

    case Scc_SMS_Authorization:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20CM_StateMAuthorization_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20CM_StateMAuthorization_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20CM_StateMAuthorization_Process;
      break;

#if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
    case Scc_SMS_ReadRootCertificate:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20CM_StateMReadRootCertificate_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20CM_StateMReadRootCertificate_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20CM_StateMReadRootCertificate_Process;
      break;

    case Scc_SMS_ReadOEMProvCert:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20CM_StateMReadOemProvCert_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20CM_StateMReadOemProvCert_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20CM_StateMReadOemProvCert_Process;
      break;

    case Scc_SMS_CertificateInstallation:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20CM_StateMCertificateInstallation_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20CM_StateMCertificateInstallation_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20CM_StateMCertificateInstallation_Process;
      break;
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

    case Scc_SMS_ServiceDiscovery:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20CM_StateMServiceDiscovery_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20CM_StateMServiceDiscovery_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20CM_StateMServiceDiscovery_Process;
      break;

    case Scc_SMS_ServiceDetail:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20CM_StateMServiceDetail_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20CM_StateMServiceDetail_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20CM_StateMServiceDetail_Process;
      break;

    case Scc_SMS_PaymentServiceSelection:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20CM_StateMServiceSelection_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20CM_StateMServiceSelection_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20CM_StateMServiceSelection_Process;
      break;

    case Scc_SMS_ChargeParameterDiscovery:
    {
      switch (Scc_ISO15118_20_StateM_GetSelectedServiceId())
      {
#if (defined SCC_SCHEMA_ISO_20AC) && (SCC_SCHEMA_ISO_20AC != 0)
        case Scc_ISO15118_20_SID_AC:
# if ( defined SCC_CHARGING_BPT ) && ( SCC_CHARGING_BPT != 0 )
        case Scc_ISO15118_20_SID_AC_BPT:
# endif /* SCC_CHARGING_BPT */
        {
          CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20AC_StateMAC_ChargeParameterDiscovery_Prepare;
          CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20AC_StateMAC_ChargeParameterDiscovery_Wait;
          CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20AC_StateMAC_ChargeParameterDiscovery_Process;
          break;
        }
#endif /* SCC_SCHEMA_ISO_20AC */
#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
        case Scc_ISO15118_20_SID_DC:
# if ( defined SCC_CHARGING_BPT ) && ( SCC_CHARGING_BPT != 0 )
        case Scc_ISO15118_20_SID_DC_BPT:
# endif /* SCC_CHARGING_BPT */
# if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
        case Scc_ISO15118_20_SID_DC_ACDP:
#  if (defined(SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON))
        case Scc_ISO15118_20_SID_DC_ACDP_BPT:
#  endif /* SCC_CHARGING_BPT */
# endif /* SCC_SCHEMA_ISO_20ACDP */
        {
          CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20DC_StateMDC_ChargeParameterDiscovery_Prepare;
          CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20DC_StateMDC_ChargeParameterDiscovery_Wait;
          CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20DC_StateMDC_ChargeParameterDiscovery_Process;
          break;
        }
#endif /* SCC_SCHEMA_ISO_20DC */
#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
        case Scc_ISO15118_20_SID_WPT:
        {
          CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20WPT_StateMWPT_ChargeParameterDiscovery_Prepare;
          CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20WPT_StateMWPT_ChargeParameterDiscovery_Wait;
          CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20WPT_StateMWPT_ChargeParameterDiscovery_Process;
          break;
        }
#endif /* SCC_SCHEMA_ISO_20WPT */

        default:
          CommonStatePtr->PrepareFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
          CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
          CommonStatePtr->ProcessResponseFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
          /* Something went wrong in setup of states */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
          (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_20_STATEM_SETUP, SCC_DET_INV_STATE);
#endif
          break;
      }
    }
    break;

    case Scc_SMS_ScheduleExchange:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20CM_StateMScheduleExchange_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20CM_StateMScheduleExchange_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20CM_StateMScheduleExchange_Process;
      break;

#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
    case Scc_SMS_AlignmentCheck:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20WPT_StateMWPT_AlignmentCheck_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20WPT_StateMWPT_AlignmentCheck_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20WPT_StateMWPT_AlignmentCheck_Process;
      break;
#endif /* SCC_SCHEMA_ISO_20WPT */

#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
    case Scc_SMS_CableCheck:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20DC_StateMDC_CableCheck_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20DC_StateMDC_CableCheck_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20DC_StateMDC_CableCheck_Process;
      break;

    case Scc_SMS_PreCharge:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20DC_StateMDC_PreCharge_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20DC_StateMDC_PreCharge_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20DC_StateMDC_PreCharge_Process;
      break;
#endif

    case Scc_SMS_PowerDelivery:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20CM_StateMPowerDelivery_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20CM_StateMPowerDelivery_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20CM_StateMPowerDelivery_Process;
      break;

#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
    case Scc_SMS_WeldingDetection:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20DC_StateMDC_WeldingDetection_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20DC_StateMDC_WeldingDetection_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20DC_StateMDC_WeldingDetection_Process;
      break;
#endif

    case Scc_SMS_ChargeLoop:
    {
      switch (Scc_ISO15118_20_StateM_GetSelectedServiceId())
      {
#if ( defined SCC_SCHEMA_ISO_20AC ) && ( SCC_SCHEMA_ISO_20AC != 0 )
        case Scc_ISO15118_20_SID_AC:
# if ( defined SCC_CHARGING_BPT ) && ( SCC_CHARGING_BPT != 0 )
        case Scc_ISO15118_20_SID_AC_BPT:
# endif /* SCC_CHARGING_BPT */
        {
          /* [V2G20-1437] */
          CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20AC_StateMAC_ChargeLoop_Prepare;
          CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20AC_StateMAC_ChargeLoop_Wait;
          CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20AC_StateMAC_ChargeLoop_Process;
          break;
        }
#endif /* SCC_SCHEMA_ISO_20AC */
#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
        case Scc_ISO15118_20_SID_DC:
# if ( defined SCC_CHARGING_BPT ) && ( SCC_CHARGING_BPT != 0 )
        case Scc_ISO15118_20_SID_DC_BPT:
# endif /* SCC_CHARGING_BPT */
# if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
        case Scc_ISO15118_20_SID_DC_ACDP:
#  if (defined(SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON))
        case Scc_ISO15118_20_SID_DC_ACDP_BPT:
#  endif /* SCC_CHARGING_BPT */
# endif /* SCC_SCHEMA_ISO_20ACDP */
        {
          /* [V2G20-1438] */
          CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20DC_StateMDC_ChargeLoop_Prepare;
          CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20DC_StateMDC_ChargeLoop_Wait;
          CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20DC_StateMDC_ChargeLoop_Process;
          break;
        }
#endif /* SCC_SCHEMA_ISO_20DC */
# if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0u )
        case Scc_ISO15118_20_SID_WPT:
        {
          /* [V2G20-5037] */
          CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20WPT_StateMWPT_ChargeLoop_Prepare;
          CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20WPT_StateMWPT_ChargeLoop_Wait;
          CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20WPT_StateMWPT_ChargeLoop_Process;
          break;
        }
# endif /* SCC_SCHEMA_ISO_20WPT */
        default:
          CommonStatePtr->PrepareFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
          CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
          CommonStatePtr->ProcessResponseFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
          /* Something went wrong in setup of states */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
          (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_20_STATEM_SETUP, SCC_DET_INV_STATE);
#endif
          break;
      }
    }
    break;

    case Scc_SMS_RestoreOldSessionInformation:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20CM_RestoreOldSessionInformation_Prepare;
      CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20CM_RestoreOldSessionInformation_Process;
      break;

#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
    case Scc_SMS_ACDP_VehiclePositioning:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20ACDP_StateMACDP_VehiclePositioning_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20ACDP_StateMACDP_VehiclePositioning_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20ACDP_StateMACDP_VehiclePositioning_Process;
      break;

    case Scc_SMS_ACDP_Connect:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20ACDP_StateMACDP_Connect_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20ACDP_StateMACDP_Connect_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20ACDP_StateMACDP_Connect_Process;
      break;

    case Scc_SMS_ACDP_Disconnect:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20ACDP_StateMACDP_Disconnect_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20ACDP_StateMACDP_Disconnect_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20ACDP_StateMACDP_Disconnect_Process;
      break;
#endif /* SCC_SCHEMA_ISO_20ACDP */

    case Scc_SMS_SessionStop:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_20CM_StateMSessionStop_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_20CM_StateMSessionStop_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_20CM_StateMSessionStop_Process;
      break;

    default:
      CommonStatePtr->PrepareFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      CommonStatePtr->ProcessResponseFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      /* Something went wrong in setup of states */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_20_STATEM_SETUP, SCC_DET_INV_STATE);
#endif
      break;
  }
}


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Init
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
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Init(void)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  uint8_least serviceIdx;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Initialize general data. */
  Scc_ISO15118_20CM_StateM_Init();

  /* #20 Initialize state machine */
  Scc_StateMachineGeneric_Init(&Scc_ISO15118_20_StateMWs.StateMachineMainChannel, &Scc_ISO15118_20_StateMSetupStateFunctions,
    &Scc_ISO15118_20_StateMGlobalTimerCheck, &Scc_ISO15118_20_StateMGlobalParamCheck, &Scc_ISO15118_20_StateMErrorHandling);
  Scc_StateMachineGeneric_SetChannelNumber(&Scc_ISO15118_20_StateMWs.StateMachineMainChannel, SCC_CHANNEL_DEFAULT);

  /* #30 Start handling the session setup */
  Scc_StateMachineGeneric_ForceState(&Scc_ISO15118_20_StateMWs.StateMachineMainChannel, Scc_SMS_SessionSetup);

  /* #40 Clear all local variables */
  for (serviceIdx = 0; serviceIdx < (uint8_least)SCC_ISO15118_20_STATEM_NUMOFAUTHSERV; serviceIdx++)
  {
    Scc_ISO15118_20_StateMWs.RxEVSE.AvailableAuthorizationServices[serviceIdx] = Scc_PaymentOption_None;
  }

  /* #50 Reset Pause variable */
  Scc_ISO15118_20_StateMWs.IsPaused = FALSE;

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
  Scc_ISO15118_20_StateMWs.RxEVSE.NumSupportedProvidersExceeded = FALSE;
  Scc_ISO15118_20_StateMWs.RxEVSE.SupportedProviders.NumOfSupportedProviders = 0;
  Scc_ISO15118_20_StateMWs.TxEVSE.CoreContractCertChainIndexInUse = 0xFF;
  Scc_ISO15118_20_StateMWs.TxEVSE.OemProvCertId = 0;
  Scc_ISO15118_20_StateMWs.TxEVSE.PrioEmaid.EMAID = &Scc_ISO15118_20_StateMWs.TxEVSE.EmaidList[0];
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

  Scc_ISO15118_20_StateM_ResetLocalVariables();
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_ResetLocalVariables
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
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_ResetLocalVariables(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Reset EVSENotification variables */
  Scc_ISO15118_20_StateMWs.RxEVSE.EvseNotification[SCC_CHANNEL_DEFAULT] = EXI_ISO_20_CT_10_EVSE_NOTIFICATION_TYPE_PAUSE;

  /* #20 Clear EvseNotificationFlag */
  Scc_ISO15118_20_StateMWs.RxEVSE.EvseNotificationFlag[SCC_CHANNEL_DEFAULT] = 0;

  /* #30 Clear NotificationMaxDelay */
  Scc_ISO15118_20_StateMWs.RxEVSE.NotificationMaxDelay = 0;

  /* #40 Clear Control Mode */
  Scc_ISO15118_20_StateMWs.TxEVSE.SelectedControlMode = SCC_ISO15118_20_CONTROL_MODE_TYPE_SCHEDULED;

  /* #50 Reset service negotiation variables */
  Scc_ISO15118_20_StateM_ClearEngeryTransferServices();
  Scc_ISO15118_20_StateM_ClearVASList();
  Scc_ISO15118_20_StateMWs.TxEVSE.TempData.CurrentServiceId = Scc_ISO15118_20_SID_ServiceNotSet;
  Scc_ISO15118_20_StateMWs.TxEVSE.SelectedServiceId = Scc_ISO15118_20_SID_ServiceNotSet;

#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
  /* #60 Initialize Reneg data. */
  Scc_ISO15118_20_StateMReneg_Init();
#endif /* SCC_ENABLE_RENEGOTIATION_CHANNEL */
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
  /* #70 Initialize metering data. */
  Scc_ISO15118_20_StateMMeter_Init();
#endif /* SCC_ENABLE_METERING_RECEIPT */
#if ( defined SCC_ENABLE_ACDP_SYSTEM_STATUS ) && ( SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON)
  /* #80 Initialize SystemStatus data. */
  Scc_ISO15118_20_StateMSysS_Init();
#endif /* SCC_ENABLE_ACDP_SYSTEM_STATUS */


#if ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
  Scc_ISO15118_20_StateMWs.RxEVSE.MeterInfo.MeterID = &Scc_ISO15118_20_StateMWs.RxEVSE.MeterID;
  Scc_ISO15118_20_StateMWs.RxEVSE.MeterInfo.MeterSignature = &Scc_ISO15118_20_StateMWs.RxEVSE.MeterSignature;

  Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.AdditionalServicesCosts = &Scc_ISO15118_20_StateMWs.RxEVSE.ReceiptAdditionalServicesCosts;
  Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.AdditionalServicesCosts->Amount = &Scc_ISO15118_20_StateMWs.RxEVSE.AdditionalServicesCostsAmount;
  Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.AdditionalServicesCosts->CostPerUnit = &Scc_ISO15118_20_StateMWs.RxEVSE.AdditionalServicesCostsCostPerUnit;

  Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.EnergyCosts = &Scc_ISO15118_20_StateMWs.RxEVSE.ReceiptEnergyCosts;
  Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.EnergyCosts->Amount = &Scc_ISO15118_20_StateMWs.RxEVSE.EnergyCostsAmount;
  Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.EnergyCosts->CostPerUnit = &Scc_ISO15118_20_StateMWs.RxEVSE.EnergyCostsCostPerUnit;

  Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.OccupancyCosts = &Scc_ISO15118_20_StateMWs.RxEVSE.ReceiptOccupancyCosts;
  Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.OccupancyCosts->Amount = &Scc_ISO15118_20_StateMWs.RxEVSE.OccupancyCostsAmount;
  Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.OccupancyCosts->CostPerUnit = &Scc_ISO15118_20_StateMWs.RxEVSE.OccupancyCostsCostPerUnit;

  Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.OverstayCosts = &Scc_ISO15118_20_StateMWs.RxEVSE.ReceiptOverstayCosts;
  Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.OverstayCosts->Amount = &Scc_ISO15118_20_StateMWs.RxEVSE.OverstayCostsAmount;
  Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.OverstayCosts->CostPerUnit = &Scc_ISO15118_20_StateMWs.RxEVSE.OverstayCostsCostPerUnit;

  Scc_ISO15118_20_StateMWs.RxEVSE.ReceiptFlag = (Exi_BitType)Exi_BT_False;
  Scc_ISO15118_20_StateMWs.RxEVSE.NumTaxCostsExceeded = FALSE;
#endif /* SCC_ENABLE_METERING_RECEIPT */

  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServiceDetailDone = FALSE;
  Scc_ISO15118_20_StateMWs.RxEVSE.ServiceDetailsWaitForReTransmission = FALSE;
#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
  Scc_ISO15118_20_StateMWs.TxEVSE.EVProcessing = EXI_ISO_20_CT_10_PROCESSING_TYPE_ONGOING;
#endif /* SCC_SCHEMA_ISO_20WPT */

  Scc_ISO15118_20_StateMWs.TxEVSE.ChargeStatus = Scc_ChargeStatus_Preparing;
  Scc_ISO15118_20_StateMWs.RxEVSE.IsChargeLoopSent = FALSE;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Execute
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
FUNC(Scc_StateMachineReturnType, SCC_CODE) Scc_ISO15118_20_StateM_Execute(void)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G20-1846] If renegotiation channel is enabled, then check if ChargeLoopReq was sent */
#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
  if (Scc_ISO15118_20_StateM_IsChargeLoopSent() == TRUE)
  {
    Scc_ISO15118_20_StateMReneg_Execute();
  }
#endif /* SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON */
  /* #20 If metering channel is enabled, then check if metering receipt needs to be sent */
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
  if (Scc_ISO15118_20_StateMMeter_IsChannelStarted() == TRUE)
  {
    /* #30 Excute metering channel state machine */
    Scc_ISO15118_20_StateMMeter_Execute();
  }
#endif /* SCC_ENABLE_METERING_RECEIPT == STD_ON */
  /* If SystemStatus channel is enabled, check if a SystemStatusReq needs to be sent */
#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
# if ( defined SCC_ENABLE_ACDP_SYSTEM_STATUS ) && ( SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON )
  if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
    && (Scc_StateM_TxCore.MsgTrig[SCC_CHANNEL_DEFAULT] >= Scc_MsgTrig_SessionSetup) )
  {
    Scc_ISO15118_20_StateMSysS_Execute();
  }
# endif /* SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON */
#endif /* SCC_SCHEMA_ISO_20ACDP != 0 */

  /* #40 Execute the ISO 15118-20 state machine after all multiplexed channels */
  retVal = Scc_StateMachineGeneric_Execute(&Scc_ISO15118_20_StateMWs.StateMachineMainChannel);

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_MsgRxIndication
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
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_MsgRxIndication(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  switch (Scc_StateM_TxCore.MsgCurrentChannel)
  {
    case (uint8)SCC_CHANNEL_DEFAULT:
    {
      /* #10 Check if the received mesasge is ChargeLoopRes */
      if (Scc_StateM_TxCore.MsgTrig[SCC_CHANNEL_DEFAULT] == Scc_MsgTrig_ChargeLoop)
      {
        /* #20 [V2G20-1440], [V2G20-1499], [V2G20-1501] Start the sequence performance timeout for ChargeLoop */
        Scc_StateMachineTimer_Start(Scc_StateMachineTimer_SequencePerformance, Scc_ISO15118_20_TimerCfg_Get_ChargeLoopSequencePerformanceTimeout());
      }
      /* #30 Otherwise */
      else
      {
        /* #40 [V2G20-434] Start the sequence performance timeout */
        Scc_StateMachineTimer_Start(Scc_StateMachineTimer_SequencePerformance, Scc_ISO15118_20_TimerCfg_Get_SequencePerformanceTimeout());
      }

      break;
    }
#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
    case (uint8)SCC_CHANNEL_RENEGOTIATION:
    {/* start the sequence performance timeout */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_SequencePerformanceRenegotiation, Scc_ISO15118_20_TimerCfg_Get_SequencePerformanceTimeout());
      break;
    }
#endif
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
    case (uint8)SCC_CHANNEL_METERING:
    {
      /* Do nothing. Since only 1 Req-Res pair is possible in Metering channel, there's no need for a sequence performance timer */
      break;
    }
#endif
#if ( defined SCC_ENABLE_ACDP_SYSTEM_STATUS ) && ( SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON )
    case (uint8)SCC_CHANNEL_SYSTEM_STATUS:
    {
      /* Do nothing. Since only 1 Req-Res pair is possible in SystemStatus channel, there's no need for a sequence performance timer */
      break;
    }
#endif
    default:
      /* this is an invalid state */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_STATEM_SET_MSG_STATUS, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
      break;
  }
}

/**********************************************************************************************************************/
/* Common Workspace Management Functions                                                                              */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetCertificateInstallationPossible
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetCertificateInstallationPossible(
  boolean ServiceAvailable)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Store the certificate installation service availability information */
  Scc_ISO15118_20_StateMWs.RxEVSE.CertificateInstallationAvailable = ServiceAvailable;

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
  Scc_StateM_InterfaceCfg_Set_CertificateInstallationService(ServiceAvailable);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsCertificateInstallationPossible
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsCertificateInstallationPossible(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Return the availabilty of the service */
  return Scc_ISO15118_20_StateMWs.RxEVSE.CertificateInstallationAvailable;
}

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetSupportedProviders
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
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetSupportedProviders(
  P2CONST(Exi_ISO_20_CM_10_SupportedProvidersListType, AUTOMATIC, SCC_APPL_DATA) SupportedProvidersPtr)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  uint8_least index = 0;
  P2CONST(Exi_ISO_20_CT_10_nameType, AUTOMATIC, SCC_APPL_DATA) providerIdPtr = NULL_PTR;
  boolean endOfListReached = FALSE;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if the pointers are valid */
  if ( (SupportedProvidersPtr != NULL_PTR)
    && (SupportedProvidersPtr->ProviderID != NULL_PTR) )
  {
    providerIdPtr = SupportedProvidersPtr->ProviderID;
    /* #20 Iterate for maximum supported providers */
    for (index = 0; (index < (uint8_least)SCC_MAX_SUPPORTED_PROVIDERS) && (providerIdPtr != NULL_PTR); index++)
    {
      /* #30 Store the ProviderId */
      if (providerIdPtr->Length <= SCC_PROVIDER_ID_BUFF_LEN)
      {
        /* PRQA S 0315 3 */ /* MD_MSR_VStdLibCopy */
        IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&Scc_ISO15118_20_StateMWs.RxEVSE.SupportedProviders.ProviderId[index].Buffer[0],
          (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&providerIdPtr->Buffer[0],
          providerIdPtr->Length);
        /* uint16 length is copied in uint8 since the length can be max 80. Hence should fit in uint8 */
        Scc_ISO15118_20_StateMWs.RxEVSE.SupportedProviders.ProviderId[index].Length = (uint8)providerIdPtr->Length;
      }
      else
      {
        Scc_ISO15118_20_StateMWs.RxEVSE.SupportedProviders.ProviderId[index].Length = 0u;
      }

      /* #40 Check if end of list is reached */
      providerIdPtr = providerIdPtr->NextProviderIDPtr;
      if (providerIdPtr == NULL_PTR)
      {
        /* #50 Break the loop */
        endOfListReached = TRUE;
      }
    }
  }
  Scc_ISO15118_20_StateMWs.RxEVSE.SupportedProviders.NumOfSupportedProviders = (uint8)index;

  /* #60 report the ProviderIdList to the application */
  Scc_StateM_InterfaceCfg_Set_ProviderIdList(&Scc_ISO15118_20_StateMWs.RxEVSE.SupportedProviders);

  /* #70 Check if any providerId could not be stored */
  if (endOfListReached == FALSE)
  {
    /* Set flag to report error */
    Scc_ISO15118_20_StateMWs.RxEVSE.NumSupportedProvidersExceeded = TRUE;
  }
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetContractCertificateChainUsed
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetContractCertificateChainUsed(uint8 Index, boolean Value)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Set the ContractCertificateChainUsed */
  Scc_ISO15118_20_StateMWs.TxEVSE.ContractCertificateChainUsed[Index] = Value;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsContractCertificateChainUsed
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsContractCertificateChainUsed(uint8 Index)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Get the ContractCertificateChainUsed */
  return Scc_ISO15118_20_StateMWs.TxEVSE.ContractCertificateChainUsed[Index];
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON)
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetProvCertUsed
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetProvCertUsed(uint8 Index, boolean Value)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Set the ProvCertUsed */
  Scc_ISO15118_20_StateMWs.TxEVSE.ProvCertUsed[Index] = Value;
}
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsProvCertUsed
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsProvCertUsed(uint8 Index)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Get the ProvCertUsed */
  return Scc_ISO15118_20_StateMWs.TxEVSE.ProvCertUsed[Index];
}
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetRemainingContrCertChains
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetRemainingContrCertChains(uint8 RemainingContrCertChains)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Set the RemainingContrCertChains */
  Scc_ISO15118_20_StateMWs.TxEVSE.RemainingContrCertChains = RemainingContrCertChains;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetRemainingContrCertChains
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(uint8, SCC_CODE) Scc_ISO15118_20_StateM_GetRemainingContrCertChains(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Get the RemainingContrCertChains */
  return Scc_ISO15118_20_StateMWs.TxEVSE.RemainingContrCertChains;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetMoveToAuthorization
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetMoveToAuthorization(boolean MoveToAuthorization)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Set the MoveToAuthorization */
  Scc_ISO15118_20_StateMWs.TxEVSE.MoveToAuthorization = MoveToAuthorization;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsMoveToAuthorization
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsMoveToAuthorization(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Get the MoveToAuthorization */
  return Scc_ISO15118_20_StateMWs.TxEVSE.MoveToAuthorization;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetCertInstallSentAfterAuthorization
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetCertInstallSentAfterAuthorization(boolean CertInstallSentAfterAuthorization)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Set the CertInstallSentAfterAuthorization */
  Scc_ISO15118_20_StateMWs.TxEVSE.CertInstallSentAfterAuthorization = CertInstallSentAfterAuthorization;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsCertInstallSentAfterAuthorization
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsCertInstallSentAfterAuthorization(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Get the CertInstallSentAfterAuthorization */
  return Scc_ISO15118_20_StateMWs.TxEVSE.CertInstallSentAfterAuthorization;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetCurrentContrCertChainId
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_CertArrayIdType, SCC_CODE) Scc_ISO15118_20_StateM_GetCurrentContrCertChainId(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Get the CurrentContrCertChainId */
  return Scc_ISO15118_20_StateMWs.TxEVSE.CurrentContrCertChainId;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetCurrentContrCertChainId
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetCurrentContrCertChainId(Scc_CertArrayIdType CurrentContrCertChainId)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Set the CurrentContrCertChainId */
  Scc_ISO15118_20_StateMWs.TxEVSE.CurrentContrCertChainId = CurrentContrCertChainId;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetOemProvCertId
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_CertArrayIdType, SCC_CODE) Scc_ISO15118_20_StateM_GetOemProvCertId(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Get the OemProvCertId */
  return Scc_ISO15118_20_StateMWs.TxEVSE.OemProvCertId;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetOemProvCertId
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetOemProvCertId(Scc_CertArrayIdType OemProvCertId)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Set the OemProvCertId */
  Scc_ISO15118_20_StateMWs.TxEVSE.OemProvCertId = OemProvCertId;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsPaymentOptionChanged
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsPaymentOptionChanged(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Get the PaymentOptionChanged */
  return Scc_ISO15118_20_StateMWs.TxEVSE.PaymentOptionChanged;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetPaymentOptionChanged
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetPaymentOptionChanged(boolean PaymentOptionChanged)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Set the PaymentOptionChanged */
  Scc_ISO15118_20_StateMWs.TxEVSE.PaymentOptionChanged = PaymentOptionChanged;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_AreCertDetailsPropogated
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_AreCertDetailsPropogated(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Get the CertDetailsPropogated */
  return Scc_ISO15118_20_StateMWs.TxEVSE.CertDetailsPropogated;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetCertDetailsPropogated
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetCertDetailsPropogated(boolean CertDetailsPropogated)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Set the CertDetailsPropogated */
  Scc_ISO15118_20_StateMWs.TxEVSE.CertDetailsPropogated = CertDetailsPropogated;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetSupportedProvidersListPtr
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(P2VAR(Scc_ISO15118_20_SupportedProvidersType, AUTOMATIC, SCC_APPL_DATA), SCC_CODE) Scc_ISO15118_20_StateM_GetSupportedProvidersListPtr(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 returns the pointer to SupportedProvidersList */
  return &Scc_ISO15118_20_StateMWs.RxEVSE.SupportedProviders;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_AddAuthorizationService
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_AddAuthorizationService(
  Scc_StateM_PaymentOptionType AuthorizationService)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  uint8_least serviceIdx;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 For each available authorization service */
  for (serviceIdx = 0; serviceIdx < (uint8_least)SCC_ISO15118_20_STATEM_NUMOFAUTHSERV; serviceIdx++)
  {
    /* #20 Check if the current service slot is free */
    if (Scc_ISO15118_20_StateMWs.RxEVSE.AvailableAuthorizationServices[serviceIdx] == Scc_PaymentOption_None)
    {
      /* #30 Add authorization method to slot and leave */
      Scc_ISO15118_20_StateMWs.RxEVSE.AvailableAuthorizationServices[serviceIdx] = AuthorizationService;
      break;
    }
  }
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsAuthorizationServiceEIMPossible
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsAuthorizationServicePossible(
  Scc_StateM_PaymentOptionType AuthorizationService)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  uint8_least serviceIdx;
  boolean retVal = FALSE;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 For each available authorization service */
  for (serviceIdx = 0; serviceIdx < (uint8_least)SCC_ISO15118_20_STATEM_NUMOFAUTHSERV; serviceIdx++)
  {
    /* #20 Check if the passed service is available */
    if (Scc_ISO15118_20_StateMWs.RxEVSE.AvailableAuthorizationServices[serviceIdx] == AuthorizationService)
    {
      /* #30 Indicate success */
      retVal = TRUE;
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetChosenAuthorizationService
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetChosenAuthorizationService(
  Scc_StateM_PaymentOptionType ChosenService)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Store the chosen authorization service for later usage */
  Scc_ISO15118_20_StateMWs.TxEVSE.SelectedPaymentOption = ChosenService;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetChosenAuthorizationService
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateM_PaymentOptionType, SCC_CODE) Scc_ISO15118_20_StateM_GetChosenAuthorizationService(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return the chosen payment option */
  return Scc_ISO15118_20_StateMWs.TxEVSE.SelectedPaymentOption;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetEVSEProcessing
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateM_EVSEProcessingType, SCC_CODE) Scc_ISO15118_20_StateM_GetEVSEProcessing(
  Scc_CoreChannelType ChannelType)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return the stored EVSE processing information */
  return Scc_ISO15118_20_StateMWs.RxEVSE.EVSEProcessing[ChannelType];
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetResponseCode
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Exi_ISO_20_CT_10_responseCodeType, SCC_CODE) Scc_ISO15118_20_StateM_GetResponseCode(
  Scc_CoreChannelType ChannelType)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return the stored ResponseCode */
  return Scc_ISO15118_20_StateMWs.RxEVSE.ResponseCode[ChannelType];
}

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetCoreContractCertChainIndexInUse
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetCoreContractCertChainIndexInUse(uint8 Index)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Set the CoreContractCertChainIndexInUse */
  Scc_ISO15118_20_StateMWs.TxEVSE.CoreContractCertChainIndexInUse = Index;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetCoreContractCertChainIndexInUse
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(uint8, SCC_CODE) Scc_ISO15118_20_StateM_GetCoreContractCertChainIndexInUse(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Return the CoreContractCertChainIndexInUse */
  return Scc_ISO15118_20_StateMWs.TxEVSE.CoreContractCertChainIndexInUse;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetEmaidListPtr
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(P2VAR(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, SCC_APPL_DATA), SCC_CODE) Scc_ISO15118_20_StateM_GetEmaidListPtr(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Return the EmaidList */
  return &Scc_ISO15118_20_StateMWs.TxEVSE.EmaidList[0];
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetPrioEmaidPtr
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(P2VAR(Exi_ISO_20_CM_10_EMAIDListType, AUTOMATIC, SCC_APPL_DATA), SCC_CODE) Scc_ISO15118_20_StateM_GetPrioEmaidPtr(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Return the PrioEmaidList */
  return &Scc_ISO15118_20_StateMWs.TxEVSE.PrioEmaid;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsResponseCodeWarning
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsResponseCodeWarning(void)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  boolean retVal = FALSE;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the stored ResponseCode contains a warning message */
  if (   (Scc_ISO15118_20_StateMWs.RxEVSE.ResponseCode[SCC_CHANNEL_DEFAULT] == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_AUTHORIZATION_SELECTION_INVALID)
      || (Scc_ISO15118_20_StateMWs.RxEVSE.ResponseCode[SCC_CHANNEL_DEFAULT] == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_NO_CERTIFICATE_AVAILABLE)
      || (Scc_ISO15118_20_StateMWs.RxEVSE.ResponseCode[SCC_CHANNEL_DEFAULT] == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_CERTIFICATE_EXPIRED)
      || (Scc_ISO15118_20_StateMWs.RxEVSE.ResponseCode[SCC_CHANNEL_DEFAULT] == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_CERTIFICATE_NOT_YET_VALID)
      || (Scc_ISO15118_20_StateMWs.RxEVSE.ResponseCode[SCC_CHANNEL_DEFAULT] == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_CERTIFICATE_REVOKED)
      || (Scc_ISO15118_20_StateMWs.RxEVSE.ResponseCode[SCC_CHANNEL_DEFAULT] == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_CERTIFICATE_VALIDATION_ERROR)
      || (Scc_ISO15118_20_StateMWs.RxEVSE.ResponseCode[SCC_CHANNEL_DEFAULT] == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_CHALLENGE_INVALID)
      || (Scc_ISO15118_20_StateMWs.RxEVSE.ResponseCode[SCC_CHANNEL_DEFAULT] == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_EIMAUTHORIZATION_FAILURE)
      || (Scc_ISO15118_20_StateMWs.RxEVSE.ResponseCode[SCC_CHANNEL_DEFAULT] == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_EVPOWER_PROFILE_VIOLATION)
      || (Scc_ISO15118_20_StateMWs.RxEVSE.ResponseCode[SCC_CHANNEL_DEFAULT] == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_E_MSPUNKNOWN)
      || (Scc_ISO15118_20_StateMWs.RxEVSE.ResponseCode[SCC_CHANNEL_DEFAULT] == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_GENERAL_PN_CAUTHORIZATION_ERROR)
      || (Scc_ISO15118_20_StateMWs.RxEVSE.ResponseCode[SCC_CHANNEL_DEFAULT] == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_NO_CONTRACT_MATCHING_PCIDFOUND)
      || (Scc_ISO15118_20_StateMWs.RxEVSE.ResponseCode[SCC_CHANNEL_DEFAULT] == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_POWER_TOLERANCE_NOT_CONFIRMED)
      || (Scc_ISO15118_20_StateMWs.RxEVSE.ResponseCode[SCC_CHANNEL_DEFAULT] == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_SCHEDULE_RENEGOTIATION_FAILED)
      || (Scc_ISO15118_20_StateMWs.RxEVSE.ResponseCode[SCC_CHANNEL_DEFAULT] == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_STANDBY_NOT_ALLOWED)
      || (Scc_ISO15118_20_StateMWs.RxEVSE.ResponseCode[SCC_CHANNEL_DEFAULT] == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_WPT) )
  {
    retVal = TRUE;
  }

  return retVal;
}


/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetServiceRenegotiationSupported
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
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetServiceRenegotiationSupported(
  boolean ServiceRenegotiationSupported)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  uint16 storedServiceReneg = Scc_StateM_ParamCfg_Get_ServiceRenegotiation();

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if ServiceRenegotiation was not already set in Nvm */
  if ((storedServiceReneg != (uint16)FALSE) && (storedServiceReneg != (uint16)TRUE))                                    /* PRQA S 4304 */ /* MD_MSR_AutosarBoolean */
  {
    /* #20 Set the information about the ServiceRenegotiation support of the EVSE */
    Scc_ISO15118_20_StateMWs.RxEVSE.ServiceRenegotiationSupported = ServiceRenegotiationSupported;
    /* #30 Store to NvM */
    Scc_StateM_ParamCfg_Set_ServiceRenegotiation((uint16)ServiceRenegotiationSupported);                                /* PRQA S 4304 */ /* MD_MSR_AutosarBoolean */
  }
  /* #40 Otherwise */
  else
  {
    /* #50 Store the information about the ServiceRenegotiation support from NvM */
    Scc_ISO15118_20_StateMWs.RxEVSE.ServiceRenegotiationSupported = (boolean)storedServiceReneg;                        /* PRQA S 4340 */ /* MD_SCC_Uint16ToBool */
  }
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetServiceRenegotiationSupported
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_GetServiceRenegotiationSupported(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the information about the ServiceRenegotiation support of the EVSE */
  return Scc_ISO15118_20_StateMWs.RxEVSE.ServiceRenegotiationSupported;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_ClearEngeryTransferServices
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
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_ClearEngeryTransferServices(void)
{
  /* ----- Implementation ----------------------------------------------- */

  /* #10 Clear the AC availability */
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.AC.ServiceID = Scc_ISO15118_20_SID_ServiceNotSet;
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.AC.FreeService = FALSE;
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.AC.ServiceStatus = Scc_ISO15118_20_SST_NotOffered;

  /* #20 Clear the DC availability */
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC.ServiceID = Scc_ISO15118_20_SID_ServiceNotSet;
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC.FreeService = FALSE;
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC.ServiceStatus = Scc_ISO15118_20_SST_NotOffered;

  /* #30 Clear the WPT availability */
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.WPT.ServiceID = Scc_ISO15118_20_SID_ServiceNotSet;
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.WPT.FreeService = FALSE;
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.WPT.ServiceStatus = Scc_ISO15118_20_SST_NotOffered;

  /* #40 Clear the DC_ACDP availability */
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_ACDP.ServiceID = Scc_ISO15118_20_SID_ServiceNotSet;
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_ACDP.FreeService = FALSE;
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_ACDP.ServiceStatus = Scc_ISO15118_20_SST_NotOffered;

  /* #50 Clear the AC_BPT availability */
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.AC_BPT.ServiceID = Scc_ISO15118_20_SID_ServiceNotSet;
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.AC_BPT.FreeService = FALSE;
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.AC_BPT.ServiceStatus = Scc_ISO15118_20_SST_NotOffered;

  /* #60 Clear the DC_BPT availability */
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_BPT.ServiceID = Scc_ISO15118_20_SID_ServiceNotSet;
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_BPT.FreeService = FALSE;
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_BPT.ServiceStatus = Scc_ISO15118_20_SST_NotOffered;

  /* #70 Clear the DC_ACDP_BPT availability */
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_ACDP_BPT.ServiceID = Scc_ISO15118_20_SID_ServiceNotSet;
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_ACDP_BPT.FreeService = FALSE;
  Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_ACDP_BPT.ServiceStatus = Scc_ISO15118_20_SST_NotOffered;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetEngeryTransferService
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
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_SetEngeryTransferService(
  P2CONST(Exi_ISO_20_CM_10_ServiceType, AUTOMATIC, SCC_APPL_DATA) EnergyTransferServicePtr)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  boolean retVal = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if provided energy transfer service is known */
  switch ((Scc_ISO15118_20_ServiceIDType)EnergyTransferServicePtr->ServiceID)                                           /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */
  {
    case Scc_ISO15118_20_SID_AC:
      /* #20 Yes: Enable the AC availability */
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.AC.ServiceID = (Scc_ISO15118_20_ServiceIDType)EnergyTransferServicePtr->ServiceID; /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.AC.FreeService = EnergyTransferServicePtr->FreeService;
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.AC.ServiceStatus = Scc_ISO15118_20_SST_ServiceReceived;
      retVal = TRUE;
      break;
    case Scc_ISO15118_20_SID_DC:
      /* #30 Yes: Enable the DC availability */
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC.ServiceID = (Scc_ISO15118_20_ServiceIDType)EnergyTransferServicePtr->ServiceID; /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC.FreeService = EnergyTransferServicePtr->FreeService;
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC.ServiceStatus = Scc_ISO15118_20_SST_ServiceReceived;
      retVal = TRUE;
      break;
    case Scc_ISO15118_20_SID_WPT:
      /* #40 Yes: Enable the WPT availability */
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.WPT.ServiceID = (Scc_ISO15118_20_ServiceIDType)EnergyTransferServicePtr->ServiceID; /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.WPT.FreeService = EnergyTransferServicePtr->FreeService;
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.WPT.ServiceStatus = Scc_ISO15118_20_SST_ServiceReceived;
      retVal = TRUE;
      break;
    case Scc_ISO15118_20_SID_DC_ACDP:
      /* #50 Yes: Enable the DC_ACDP availability */
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_ACDP.ServiceID = (Scc_ISO15118_20_ServiceIDType)EnergyTransferServicePtr->ServiceID; /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_ACDP.FreeService = EnergyTransferServicePtr->FreeService;
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_ACDP.ServiceStatus = Scc_ISO15118_20_SST_ServiceReceived;
      retVal = TRUE;
      break;
    case Scc_ISO15118_20_SID_AC_BPT:
      /* #60 Yes: Enable the AC_BPT availability */
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.AC_BPT.ServiceID = (Scc_ISO15118_20_ServiceIDType)EnergyTransferServicePtr->ServiceID; /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.AC_BPT.FreeService = EnergyTransferServicePtr->FreeService;
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.AC_BPT.ServiceStatus = Scc_ISO15118_20_SST_ServiceReceived;
      retVal = TRUE;
      break;
    case Scc_ISO15118_20_SID_DC_BPT:
      /* #70 Yes: Enable the DC_BPT availability */
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_BPT.ServiceID = (Scc_ISO15118_20_ServiceIDType)EnergyTransferServicePtr->ServiceID; /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_BPT.FreeService = EnergyTransferServicePtr->FreeService;
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_BPT.ServiceStatus = Scc_ISO15118_20_SST_ServiceReceived;
      retVal = TRUE;
      break;
    case Scc_ISO15118_20_SID_DC_ACDP_BPT:
      /* #80 Yes: Enable the DC_ACDP_BPT availability */
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_ACDP_BPT.ServiceID = (Scc_ISO15118_20_ServiceIDType)EnergyTransferServicePtr->ServiceID; /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_ACDP_BPT.FreeService = EnergyTransferServicePtr->FreeService;
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_ACDP_BPT.ServiceStatus = Scc_ISO15118_20_SST_ServiceReceived;
      retVal = TRUE;
      break;
    default:
      /* #90 No: Just return FALSE (already set) */
      break;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetEngeryTransferServiceState
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetEngeryTransferServiceState(
  Scc_ISO15118_20_ServiceIDType ServiceId,
  Scc_ISO15118_20_ServiceStateType ServiceState)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if provided energy transfer service is known and set new state */
  switch (ServiceId)
  {
    case Scc_ISO15118_20_SID_AC:
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.AC.ServiceStatus = ServiceState;
      break;
    case Scc_ISO15118_20_SID_DC:
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC.ServiceStatus = ServiceState;
      break;
    case Scc_ISO15118_20_SID_WPT:
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.WPT.ServiceStatus = ServiceState;
      break;
    case Scc_ISO15118_20_SID_DC_ACDP:
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_ACDP.ServiceStatus = ServiceState;
      break;
    case Scc_ISO15118_20_SID_AC_BPT:
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.AC_BPT.ServiceStatus = ServiceState;
      break;
    case Scc_ISO15118_20_SID_DC_BPT:
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_BPT.ServiceStatus = ServiceState;
      break;
    case Scc_ISO15118_20_SID_DC_ACDP_BPT:
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_ACDP_BPT.ServiceStatus = ServiceState;
      break;
    default:
      /* This state has been checked before in parent APIs, so this case should never happen */
      break;
  }
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsEngeryTransferPossible
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsEngeryTransferPossible(void)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  boolean retVal = FALSE;
  Scc_SAPSchemaIDType chosenSchema;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the selected schema */
  chosenSchema = Scc_SAP_ExiRx_GetChosenSchema();

  /* #20 Check if charging is possible with the selected schema and received energy transfer modes */
  switch (chosenSchema)
  {
#if ( defined SCC_SCHEMA_ISO_20AC ) && ( SCC_SCHEMA_ISO_20AC != 0 )
    case Scc_SAPSchemaIDs_ISO15118_20AC:
      if (Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.AC.ServiceStatus == Scc_ISO15118_20_SST_ServiceReceived)
      {
        retVal = TRUE;
      }
      else if (Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.AC_BPT.ServiceStatus == Scc_ISO15118_20_SST_ServiceReceived)
      {
        retVal = TRUE;
      }
      else
      {
        /* Not possible, retVal is already set to FALSE */
      }
      break;
#endif /* SCC_SCHEMA_ISO_20AC */
#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
    case Scc_SAPSchemaIDs_ISO15118_20DC:
      if (Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC.ServiceStatus == Scc_ISO15118_20_SST_ServiceReceived)
      {
        retVal = TRUE;
      }
      else if (Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_BPT.ServiceStatus == Scc_ISO15118_20_SST_ServiceReceived)
      {
        retVal = TRUE;
      }
      else
      {
        /* Not possible, retVal is already set to FALSE */
      }
      break;
#endif /* SCC_SCHEMA_ISO_20DC */
#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
    case Scc_SAPSchemaIDs_ISO15118_20WPT:
      if (Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.WPT.ServiceStatus == Scc_ISO15118_20_SST_ServiceReceived)
      {
        retVal = TRUE;
      }
      else
      {
        /* Not possible, retVal is already set to FALSE */
      }
      break;
#endif /* SCC_SCHEMA_ISO_20WPT */
#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
    case Scc_SAPSchemaIDs_ISO15118_20ACDP:
      if (Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_ACDP.ServiceStatus == Scc_ISO15118_20_SST_ServiceReceived)
      {
        retVal = TRUE;
      }
# if (defined(SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON))
      else if (Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServices.DC_ACDP_BPT.ServiceStatus == Scc_ISO15118_20_SST_ServiceReceived)
      {
        retVal = TRUE;
      }
# endif /* SCC_CHARGING_BPT */
      else
      {
        /* Not possible, retVal is already set to FALSE */
      }
      break;
#endif /* SCC_SCHEMA_ISO_20ACDP */
    default:
      /* Not possible, retVal is already set to FALSE */
      break;
  }

  return retVal;
}


/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_ClearVASList
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_ClearVASList(void)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  uint8_least idx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Clear all list entries */
  for (idx = 0u; idx < (uint8_least)SCC_ISO15118_20_STATEM_NUM_OF_VAS_SERVICES; idx++)
  {
    /* #20 Clear the AC availability */
    Scc_ISO15118_20_StateMWs.RxEVSE.VASList.Service[idx].ServiceID = Scc_ISO15118_20_SID_ServiceNotSet;
    Scc_ISO15118_20_StateMWs.RxEVSE.VASList.Service[idx].FreeService = FALSE;
    Scc_ISO15118_20_StateMWs.RxEVSE.VASList.Service[idx].ServiceStatus = Scc_ISO15118_20_SST_NotOffered;
  }
  /* #30 Set list length to 0 */
  Scc_ISO15118_20_StateMWs.RxEVSE.VASList.ListLength = 0u;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetVASListEntry
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
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_SetVASListEntry(
  P2CONST(Exi_ISO_20_CM_10_ServiceType, AUTOMATIC, SCC_APPL_DATA) VASPtr)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  boolean retVal = FALSE;
  uint8_least idx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each list entry */
  for (idx = 0u; idx < (uint8_least)Scc_ISO15118_20_StateMWs.RxEVSE.VASList.ListLength; idx++)
  {
    /* #20 Check if the passed service is already known */
    P2CONST(Scc_ISO15118_20_ServiceInfoType, AUTOMATIC, SCC_APPL_DATA) knownVASPtr = &(Scc_ISO15118_20_StateMWs.RxEVSE.VASList.Service[idx]);
    if (knownVASPtr->ServiceID == (Scc_ISO15118_20_ServiceIDType)VASPtr->ServiceID)                                     /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */
    {
      /* #30 Yes: The service is already in the list */
      /* Stop the search */
      break;
    }
  }

  /* #40 Check if the passed VAS has not been found in the list */
  if (idx == (uint8_least)Scc_ISO15118_20_StateMWs.RxEVSE.VASList.ListLength)
  {
    /* #50 Check if there are free entries in the VAS list */
    if (idx < (uint8_least)SCC_ISO15118_20_STATEM_NUM_OF_VAS_SERVICES)
    {
      /* #60 Add the entry to the VAS list */
      Scc_ISO15118_20_StateMWs.RxEVSE.VASList.Service[idx].ServiceID = (Scc_ISO15118_20_ServiceIDType)VASPtr->ServiceID; /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */
      Scc_ISO15118_20_StateMWs.RxEVSE.VASList.Service[idx].FreeService = VASPtr->FreeService;
      Scc_ISO15118_20_StateMWs.RxEVSE.VASList.Service[idx].ServiceStatus = Scc_ISO15118_20_SST_ServiceReceived;
      Scc_ISO15118_20_StateMWs.RxEVSE.VASList.ListLength++;
      retVal = TRUE;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_HandleNextVAService
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
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Scc_StateMachineStatesReturnType, SCC_CODE) Scc_ISO15118_20_StateM_HandleNextVAService(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;                                                 /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Scc_ISO15118_20_ServiceIDType serviceToRequest = Scc_ISO15118_20_SID_ServiceNotSet;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the next EnergyTransferService from the application */
  Scc_StateM_InterfaceCfg_Get_ServiceDetailVAService(&serviceToRequest);

  /* #20 Check if the application is pending */
  if (serviceToRequest == Scc_ISO15118_20_SID_ServiceNotSet)
  {
    /* #30 Return pending and try again later */
    retVal = Scc_StateMachineState_Pending;
  }
  /* #40 Check if the application does not request further details */
  else if (serviceToRequest == Scc_ISO15118_20_SID_StopRequestingMoreServices)
  {
    /* #50 Store the service ID and continue */
    Scc_ISO15118_20_StateM_SetServiceIdTx(serviceToRequest);
    Scc_ISO15118_20_StateM_SetServiceIdRx(serviceToRequest);
    retVal = Scc_StateMachineState_Finished;
  }
  /* #60 Check if the application requests a general service */
  else if (serviceToRequest > Scc_ISO15118_20_SID_LastPossibleEnergyTransferServices)
  {
    uint8_least idx;
    boolean isKnownService = FALSE;

    /* #70 Check if this is a supported value added service that was received from EVSE */
    for (idx = 0u; idx < (uint8_least)Scc_ISO15118_20_StateMWs.RxEVSE.VASList.ListLength; idx++)
    {
      /* #80 Check if this service is supported */
      P2CONST(Scc_ISO15118_20_ServiceInfoType, AUTOMATIC, SCC_APPL_DATA) knownVASPtr = &(Scc_ISO15118_20_StateMWs.RxEVSE.VASList.Service[idx]);
      if (knownVASPtr->ServiceID == serviceToRequest)
      {
        /* #90 Yes: The service is already in the list */
        isKnownService = TRUE;
        break;
      }
    }
    /* #100 Check if this service ID is supported */
    if (isKnownService == TRUE)
    {
      /* #110 Store the service ID and continue */
      Scc_ISO15118_20_StateM_SetServiceIdTx(serviceToRequest);
      Scc_ISO15118_20_StateM_SetServiceIdRx(Scc_ISO15118_20_SID_ServiceNotSet);
      retVal = Scc_StateMachineState_Done;
    }
    /* #120 Otherwise */
    else
    {
      /* #130 Indicate error as the selected ServiceId is not supported by EVSE */
      *ErrorInformation = Scc_SMER_ServiceDetail_UnknownServiceIdFromApplication;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  /* #140 Otherwise */
  else
  {
    /* #150 Provided Service ID is out of the valid range */
      *ErrorInformation = Scc_SMER_ServiceDetail_InvalidServiceIdFromApplication;
    retVal = Scc_StateMachineState_Failed;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetVAServiceState
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetVAServiceState(
  Scc_ISO15118_20_ServiceIDType ServiceId,
  Scc_ISO15118_20_ServiceStateType ServiceState)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least idx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each VAS service in the list */
  for (idx = 0u; idx < (uint8_least)Scc_ISO15118_20_StateMWs.RxEVSE.VASList.ListLength; idx++)
  {
    /* #20 Check if the passed ServiceId is already known */
    P2CONST(Scc_ISO15118_20_ServiceInfoType, AUTOMATIC, SCC_APPL_DATA) knownVASPtr = &(Scc_ISO15118_20_StateMWs.RxEVSE.VASList.Service[idx]);
    if (knownVASPtr->ServiceID == ServiceId)
    {
      /* #30 Yes: Update the serivce status according to the passed ServiceState */
      Scc_ISO15118_20_StateMWs.RxEVSE.VASList.Service[idx].ServiceStatus = ServiceState;
      break;
    }
  }
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetServiceIdTx
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetServiceIdTx(
  Scc_ISO15118_20_ServiceIDType CurrentServiceId)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set value into workspace */
  Scc_ISO15118_20_StateMWs.TxEVSE.TempData.CurrentServiceId = CurrentServiceId;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetServiceIdTx
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_ISO15118_20_ServiceIDType, SCC_CODE) Scc_ISO15118_20_StateM_GetServiceIdTx(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return value from workspace */
  return Scc_ISO15118_20_StateMWs.TxEVSE.TempData.CurrentServiceId;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetServiceIdRx
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetServiceIdRx(
  Scc_ISO15118_20_ServiceIDType CurrentServiceId)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set value into workspace */
  Scc_ISO15118_20_StateMWs.RxEVSE.TempData.CurrentServiceId = CurrentServiceId;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetServiceIdRx
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_ISO15118_20_ServiceIDType, SCC_CODE) Scc_ISO15118_20_StateM_GetServiceIdRx(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return value from workspace */
  return Scc_ISO15118_20_StateMWs.RxEVSE.TempData.CurrentServiceId;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_HandleNextEnergyTransferService
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
FUNC(Scc_StateMachineStatesReturnType, SCC_CODE) Scc_ISO15118_20_StateM_HandleNextEnergyTransferService(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;                                                 /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Scc_ISO15118_20_ServiceIDType energyServiceToRequest = Scc_ISO15118_20_SID_ServiceNotSet;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the next EnergyTransferService from the application */
  Scc_StateM_InterfaceCfg_Get_ServiceDetailEnergyService(&energyServiceToRequest);

  /* #20  Check if the application is pending */
  if (energyServiceToRequest == Scc_ISO15118_20_SID_ServiceNotSet)
  {
    /* #30 Return pending and try again later */
    retVal = Scc_StateMachineState_Pending;
  }
  /* #40 Check if the application requests an energy transfer service */
  else if (energyServiceToRequest < Scc_ISO15118_20_SID_LastPossibleEnergyTransferServices)
  {
    /* #50 Store the service ID and continue */
    Scc_ISO15118_20_StateM_SetServiceIdTx(energyServiceToRequest);
    Scc_ISO15118_20_StateM_SetServiceIdRx(Scc_ISO15118_20_SID_ServiceNotSet);
    retVal = Scc_StateMachineState_Done;
  }
  /* #60 Check if the application does not request further details */
  else if (energyServiceToRequest == Scc_ISO15118_20_SID_StopRequestingMoreServices)
  {
    /* #70 Store the service ID and continue */
    Scc_ISO15118_20_StateM_SetServiceIdTx(energyServiceToRequest);
    Scc_ISO15118_20_StateM_SetServiceIdRx(energyServiceToRequest);
    Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServiceDetailDone = TRUE;
    retVal = Scc_StateMachineState_Finished;
  }
  /* #80 Otherwise */
  else
  {
    /* #90 Provided Service ID is out of the valid range */
    *ErrorInformation = Scc_SMER_ServiceDetail_InvalidServiceIdFromApplication;
    retVal = Scc_StateMachineState_Failed;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsEnergyTransferServiceDetailDone
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsEnergyTransferServiceDetailDone(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return value from workspace */
  return Scc_ISO15118_20_StateMWs.RxEVSE.EnergyTransferServiceDetailDone;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetServiceDetailsWaitForReTransmission
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetServiceDetailsWaitForReTransmission(boolean WaitForReTransmission)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set value in workspace */
  Scc_ISO15118_20_StateMWs.RxEVSE.ServiceDetailsWaitForReTransmission = WaitForReTransmission;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsServiceDetailsWaitForReTransmission
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsServiceDetailsWaitForReTransmission(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return value from workspace */
  return Scc_ISO15118_20_StateMWs.RxEVSE.ServiceDetailsWaitForReTransmission;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetSelectedServiceId
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetSelectedServiceId(
  Scc_ISO15118_20_ServiceIDType SelectedServiceId)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Store value into workspace */
  Scc_ISO15118_20_StateMWs.TxEVSE.SelectedServiceId = SelectedServiceId;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetSelectedServiceId
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_ISO15118_20_ServiceIDType, SCC_CODE) Scc_ISO15118_20_StateM_GetSelectedServiceId(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Returns the stored value from workspace */
  return Scc_ISO15118_20_StateMWs.TxEVSE.SelectedServiceId;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Fetch_ControlMode
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Fetch_ControlMode(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Fetch the ControlMode from application */
  Scc_StateM_InterfaceCfg_Get_ControlMode(&Scc_ISO15118_20_StateMWs.TxEVSE.SelectedControlMode);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Get_ControlMode
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Get_ControlMode(
  P2VAR(Scc_ISO15118_20_ControlModeType, AUTOMATIC, SCC_APPL_DATA) ControlModePtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return the ControlMode */
  *ControlModePtr = Scc_ISO15118_20_StateMWs.TxEVSE.SelectedControlMode;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetChargeStatus
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetChargeStatus(
  Scc_StateM_ChargeStatusType ChargeStatus)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set value into workspace */
  Scc_ISO15118_20_StateMWs.TxEVSE.ChargeStatus = ChargeStatus;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetChargeStatus
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateM_ChargeStatusType, SCC_CODE) Scc_ISO15118_20_StateM_GetChargeStatus(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return value from workspace */
  return Scc_ISO15118_20_StateMWs.TxEVSE.ChargeStatus;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetChargingSession
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetChargingSession(
  Exi_ISO_20_CM_10_chargingSessionType ChargingSession)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set value into workspace */
  Scc_ISO15118_20_StateMWs.TxEVSE.ChargingSession = ChargingSession;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetChargingSession
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Exi_ISO_20_CM_10_chargingSessionType, SCC_CODE) Scc_ISO15118_20_StateM_GetChargingSession(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return value from workspace */
  return Scc_ISO15118_20_StateMWs.TxEVSE.ChargingSession;
}

#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsEVSERequestingScheduleReneg
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsEVSERequestingScheduleReneg(void)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  boolean IsRenegotiationRequested = FALSE;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Return if renegotiation was requested or not */
  if (Scc_ISO15118_20_StateMWs.RxEVSE.EvseNotificationFlag[SCC_CHANNEL_DEFAULT] == 1u)
  {
    if (Scc_ISO15118_20_StateMWs.RxEVSE.EvseNotification[SCC_CHANNEL_DEFAULT] == EXI_ISO_20_CT_10_EVSE_NOTIFICATION_TYPE_SCHEDULE_RENEGOTIATION)
    {
      IsRenegotiationRequested = TRUE;
    }
  }

  return IsRenegotiationRequested;
}
#endif /* SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON */

#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsEVSERequestingMeteringConfirmation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsEVSERequestingMeteringConfirmation(void)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  boolean isMeteringRequested = FALSE;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G20-1083] Return if Metering was requested or not */
  if (Scc_ISO15118_20_StateMWs.RxEVSE.EvseNotificationFlag[SCC_CHANNEL_DEFAULT] == 1u)
  {
    if (Scc_ISO15118_20_StateMWs.RxEVSE.EvseNotification[SCC_CHANNEL_DEFAULT] == EXI_ISO_20_CT_10_EVSE_NOTIFICATION_TYPE_METERING_CONFIRMATION)
    {
      isMeteringRequested = TRUE;
    }
  }

  return isMeteringRequested;
}
#endif /* SCC_ENABLE_METERING_RECEIPT == STD_ON */

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsEVSERequestingServiceReneg
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsEVSERequestingServiceReneg(void)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  boolean isRenegotiationRequested = FALSE;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Return if renegotiation was requested or not */
  if (Scc_ISO15118_20_StateMWs.RxEVSE.EvseNotificationFlag[SCC_CHANNEL_DEFAULT] == 1u)
  {
    if (Scc_ISO15118_20_StateMWs.RxEVSE.EvseNotification[SCC_CHANNEL_DEFAULT] ==
                              EXI_ISO_20_CT_10_EVSE_NOTIFICATION_TYPE_SERVICE_RENEGOTIATION)
    {
      isRenegotiationRequested = TRUE;
    }
  }

  return isRenegotiationRequested;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetPauseActive
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetPauseActive(boolean PauseStatus)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set value in workspace */
  Scc_ISO15118_20_StateMWs.IsPaused = PauseStatus;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_isPauseActive
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsPauseActive(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return value from workspace */
  return Scc_ISO15118_20_StateMWs.IsPaused;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_ActivatePause
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
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_ActivatePause(void)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  boolean startPause = FALSE;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 IsPaused is already enabled */
  if (Scc_ISO15118_20_StateM_IsPauseActive() == TRUE)
  {
    startPause = TRUE;
  }
  /* #20 [V2G20-2121] Check if GoToPause  is true and PowerScheduleEntry  is 0W */
  else if ((Scc_ISO15118_20_StateMWs.RxEVSE.GoToPause == TRUE)
        && (Scc_ISO15118_20_StateMWs.RxEVSE.PowerScheduleEntryValue == 0))
  {
    /* #30 Set IsPaused to True in workspace */
    startPause = TRUE;
    Scc_ISO15118_20_StateMWs.IsPaused = TRUE;
  }
  /* #40 [V2G20-1850] Check if EVSENotification set to Pause and NotificationMaxDelay set to 60s */
  else if ((Scc_ISO15118_20_StateMWs.RxEVSE.EvseNotification[SCC_CHANNEL_DEFAULT] == EXI_ISO_20_CT_10_EVSE_NOTIFICATION_TYPE_PAUSE)
        && (Scc_ISO15118_20_StateMWs.RxEVSE.EvseNotificationFlag[SCC_CHANNEL_DEFAULT]== 1u)
        && (Scc_ISO15118_20_StateMWs.RxEVSE.NotificationMaxDelay == 60u))
  {
    /* #50 Set IsPaused to True in workspace */
    startPause = TRUE;
    Scc_ISO15118_20_StateMWs.IsPaused = TRUE;
  }
  /* #60 Otherwise */
  else
  {
    /* #70 Pausing mechanism is not triggered or has been resumed */
    Scc_ISO15118_20_StateMWs.IsPaused = FALSE;
  }
  return startPause;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Set_GoToPause
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Set_GoToPause(
  boolean GoToPause)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set value into workspace */
  Scc_ISO15118_20_StateMWs.RxEVSE.GoToPause = GoToPause;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Set_PowerScheduleEntryValue
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Set_PowerScheduleEntryValue(
  sint16 PowerScheduleEntryValue)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set value into workspace */
  Scc_ISO15118_20_StateMWs.RxEVSE.PowerScheduleEntryValue = PowerScheduleEntryValue;
}

/**********************************************************************************************************************/
/* State Machine Callouts                                                                                             */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Set_EVSEProcessing
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Set_EVSEProcessing(
  Exi_ISO_20_CT_10_processingType EVSEProcessing)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Store the EVSEProcessing information in workspace */
  switch (EVSEProcessing)
  {
    case EXI_ISO_20_CT_10_PROCESSING_TYPE_ONGOING :
    case EXI_ISO_20_CT_10_PROCESSING_TYPE_ONGOING_WAITING_FOR_CUSTOMER_INTERACTION:
      Scc_ISO15118_20_StateMWs.RxEVSE.EVSEProcessing[Scc_StateM_TxCore.MsgCurrentChannel] = Scc_EVSEProcessing_Ongoing;
      break;

    default: /* case EXI_ISO_EVSEPROCESSING_TYPE_FINISHED: */
      Scc_ISO15118_20_StateMWs.RxEVSE.EVSEProcessing[Scc_StateM_TxCore.MsgCurrentChannel] = Scc_EVSEProcessing_Finished;
      break;
  }
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Set_ResponseCode
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Set_ResponseCode(
  Exi_ISO_20_CT_10_responseCodeType ResponseCode)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Store the ResponseCode information in workspace */
  Scc_ISO15118_20_StateMWs.RxEVSE.ResponseCode[Scc_StateM_TxCore.MsgCurrentChannel] = ResponseCode;
}

/***************************************************************************************
 * PowerDeliveryRes/ChargeLoopRes
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Set_EVSEStatus
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
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Set_EVSEStatus(
  P2CONST(Exi_ISO_20_CT_10_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* ----- Implementation ----------------------------------------------- */
  if (DataPtr != NULL_PTR)
  {
    /* #10 Store the EvseNotification information in workspace */
    if (Scc_StateM_TxCore.MsgCurrentChannel < (uint8)SCC_CHANNEL_MAX)
    {
      Scc_ISO15118_20_StateMWs.RxEVSE.EvseNotification[Scc_StateM_TxCore.MsgCurrentChannel] = DataPtr->EVSENotification;
      Scc_ISO15118_20_StateMWs.RxEVSE.EvseNotificationFlag[Scc_StateM_TxCore.MsgCurrentChannel] = Flag;
    }
    Scc_ISO15118_20_StateMWs.RxEVSE.NotificationMaxDelay = DataPtr->NotificationMaxDelay;

#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
    /* #20 Check if Schedule renegotiation is requested by the EVSE */
    if ( (Flag == (Exi_BitType)Exi_BT_True)
      && (Scc_StateM_TxCore.MsgCurrentChannel == (uint8)SCC_CHANNEL_DEFAULT)
      && (DataPtr->EVSENotification == EXI_ISO_20_CT_10_EVSE_NOTIFICATION_TYPE_SCHEDULE_RENEGOTIATION))
    {
      Scc_StateMachineTimer_TimeValueType timeoutval;
      /* Convert from sec to function cycles */
      timeoutval = (DataPtr->NotificationMaxDelay * 1000u) / SCC_MAIN_FUNCTION_PERIOD_MS;

      /* #30 [V2G20-1052] Start the NotificationMaxDelay timer */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_NotificationMaxDelayRenegotiation, timeoutval);
    }
#endif /* SCC_ENABLE_RENEGOTIATION_CHANNEL */
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
    /* #40 Check if Metering receipt is requested by the EVSE */
    if ( (Flag == (Exi_BitType)Exi_BT_True)
      && (Scc_StateM_TxCore.MsgCurrentChannel == (uint8)SCC_CHANNEL_DEFAULT)
      && (DataPtr->EVSENotification == EXI_ISO_20_CT_10_EVSE_NOTIFICATION_TYPE_METERING_CONFIRMATION) )
    {
      Scc_StateMachineTimer_TimeValueType timeoutval;
      /* Convert from sec to function cycles */
      timeoutval = (DataPtr->NotificationMaxDelay * 1000u) / SCC_MAIN_FUNCTION_PERIOD_MS;

      /* #50 [V2G20-1621] Start the NotificationMaxDelay timer */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_NotificationMaxDelayMeter, timeoutval);
    }
#endif /* SCC_ENABLE_METERING_RECEIPT */
    /* #60 Check if ServiceRenegotiation is requested by the EVSE */
    if ( (Flag == (Exi_BitType)Exi_BT_True)
      && (Scc_StateM_TxCore.MsgCurrentChannel == (uint8)SCC_CHANNEL_DEFAULT)
      && (DataPtr->EVSENotification == EXI_ISO_20_CT_10_EVSE_NOTIFICATION_TYPE_SERVICE_RENEGOTIATION)
      && (Scc_ISO15118_20_StateM_GetServiceRenegotiationSupported() == TRUE) )
    {
      Scc_StateMachineTimer_TimeValueType timeoutval;
      /* Convert from sec to function cycles */
      timeoutval = (DataPtr->NotificationMaxDelay * 1000u) / SCC_MAIN_FUNCTION_PERIOD_MS;

      /* #70 [V2G20-1964], [V2G20-1651], [V2G20-5080] Start the NotificationMaxDelay timer */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_NotificationMaxDelayServiceReneg, timeoutval);
    }
  }
  else
  {
    Scc_ISO15118_20_StateMWs.RxEVSE.EvseNotificationFlag[Scc_StateM_TxCore.MsgCurrentChannel] = 0u;
  }
}

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetGenChallenge
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_GetGenChallenge(
  P2VAR(Exi_ISO_20_CM_10_genChallengeType*, AUTOMATIC, SCC_APPL_DATA) GenChallengePtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return the GenChallenge pointer */
  *GenChallengePtr = &Scc_ISO15118_20_StateMWs.RxEVSE.GenChallenge;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetGenChallenge
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetGenChallenge(
  P2VAR(Exi_ISO_20_CM_10_genChallengeType, AUTOMATIC, SCC_APPL_DATA) GenChallengePtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the GenChallenge length is valid */
  if (GenChallengePtr->Length <= SCC_ISO15118_20_STATEM_GEN_CHALLENGE_MAX_LEN)
  {
    /* #20 Store the GenChallenge */
    /* PRQA S 0315 2 */ /* MD_MSR_VStdLibCopy */
    IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&Scc_ISO15118_20_StateMWs.RxEVSE.GenChallenge.Buffer[0],
      (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&GenChallengePtr->Buffer[0],
      GenChallengePtr->Length);
    Scc_ISO15118_20_StateMWs.RxEVSE.GenChallenge.Length = GenChallengePtr->Length;
  }
  /* #30 Otherwise reset the length */
  else
  {
    GenChallengePtr->Length = 0;
  }
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/***************************************************************************************
 * ChargeLoopRes
 ***************************************************************************************/
#if ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Set_MeterInfo()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010 1 */ /* MD_MSR_STPTH */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Set_MeterInfo(
  P2CONST(Exi_ISO_20_CT_10_MeterInfoType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Store the MeterInfo. */
  if (Flag == (Exi_BitType)Exi_BT_True)
  {
    Scc_ISO15118_20_StateMWs.RxEVSE.MeterInfo.ChargedEnergyReadingWh = DataPtr->ChargedEnergyReadingWh;

    Scc_ISO15118_20_StateMWs.RxEVSE.MeterInfo.BPT_DischargedEnergyReadingWhFlag = DataPtr->BPT_DischargedEnergyReadingWhFlag;
    if (DataPtr->BPT_DischargedEnergyReadingWhFlag == (Exi_BitType)Exi_BT_True)
    {
      Scc_ISO15118_20_StateMWs.RxEVSE.MeterInfo.BPT_DischargedEnergyReadingWh = DataPtr->BPT_DischargedEnergyReadingWh;
    }

    Scc_ISO15118_20_StateMWs.RxEVSE.MeterInfo.BPT_InductiveEnergyReadingVARhFlag = DataPtr->BPT_InductiveEnergyReadingVARhFlag;
    if (DataPtr->BPT_InductiveEnergyReadingVARhFlag == (Exi_BitType)Exi_BT_True)
    {
      Scc_ISO15118_20_StateMWs.RxEVSE.MeterInfo.BPT_InductiveEnergyReadingVARh = DataPtr->BPT_InductiveEnergyReadingVARh;
    }

    Scc_ISO15118_20_StateMWs.RxEVSE.MeterInfo.CapacitiveEnergyReadingVARhFlag = DataPtr->CapacitiveEnergyReadingVARhFlag;
    if (DataPtr->CapacitiveEnergyReadingVARhFlag == (Exi_BitType)Exi_BT_True)
    {
      Scc_ISO15118_20_StateMWs.RxEVSE.MeterInfo.CapacitiveEnergyReadingVARh = DataPtr->CapacitiveEnergyReadingVARh;
    }

    Scc_ISO15118_20_StateMWs.RxEVSE.MeterInfo.MeterStatusFlag = DataPtr->MeterStatusFlag;
    if (DataPtr->MeterStatusFlag == (Exi_BitType)Exi_BT_True)
    {
      Scc_ISO15118_20_StateMWs.RxEVSE.MeterInfo.MeterStatus = DataPtr->MeterStatus;
    }

    Scc_ISO15118_20_StateMWs.RxEVSE.MeterInfo.MeterTimestampFlag = DataPtr->MeterTimestampFlag;
    if (DataPtr->MeterTimestampFlag == (Exi_BitType)Exi_BT_True)
    {
      Scc_ISO15118_20_StateMWs.RxEVSE.MeterInfo.MeterTimestamp = DataPtr->MeterTimestamp;
    }

    /* #20 Store the MeterId */
    if (DataPtr->MeterID->Length <= 32u)
    {
      /* PRQA S 0315 3 */ /* MD_MSR_VStdLibCopy */
      IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&Scc_ISO15118_20_StateMWs.RxEVSE.MeterID.Buffer[0],
        (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&DataPtr->MeterID->Buffer[0],
        DataPtr->MeterID->Length);
      Scc_ISO15118_20_StateMWs.RxEVSE.MeterID.Length = DataPtr->MeterID->Length;
    }
    else
    {
      Scc_ISO15118_20_StateMWs.RxEVSE.MeterID.Length = 0;
    }

    Scc_ISO15118_20_StateMWs.RxEVSE.MeterInfo.MeterSignatureFlag = DataPtr->MeterSignatureFlag;
    if (DataPtr->MeterSignatureFlag == (Exi_BitType)Exi_BT_True)
    {
      /* #30 Store the MeterSignature */
      if (DataPtr->MeterSignature->Length <= 64u)
      {
        /* PRQA S 0315 3 */ /* MD_MSR_VStdLibCopy */
        IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&Scc_ISO15118_20_StateMWs.RxEVSE.MeterSignature.Buffer[0],
          (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&DataPtr->MeterSignature->Buffer[0],
          DataPtr->MeterSignature->Length);
        Scc_ISO15118_20_StateMWs.RxEVSE.MeterSignature.Length = DataPtr->MeterSignature->Length;
      }
      else
      {
        Scc_ISO15118_20_StateMWs.RxEVSE.MeterSignature.Length = 0;
      }
    }
  }
}
#endif /* SCC_ENABLE_METERING_RECEIPT */

#if ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Set_Receipt()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Set_Receipt(
  P2CONST(Exi_ISO_20_CT_10_ReceiptType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Store the Receipt. */
  if ((Flag == (Exi_BitType)Exi_BT_True) && (DataPtr != NULL_PTR))
  {
    /* Set ReceiptFlag only if True since its possible that before MeteringConfirmation is sent out we receive another ChargeLoopRes without
     * EvseNotification set to Metering and hence the flag will be set to False which is not intended */
    Scc_ISO15118_20_StateMWs.RxEVSE.ReceiptFlag = Flag;
    Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.TimeAnchor = DataPtr->TimeAnchor;
    Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.AdditionalServicesCostsFlag = DataPtr->AdditionalServicesCostsFlag;
    if (DataPtr->AdditionalServicesCostsFlag == (Exi_BitType)Exi_BT_True)
    {
      Scc_ISO15118_20_StateMWs.RxEVSE.AdditionalServicesCostsAmount.Value = DataPtr->AdditionalServicesCosts->Amount->Value;
      Scc_ISO15118_20_StateMWs.RxEVSE.AdditionalServicesCostsAmount.Exponent = DataPtr->AdditionalServicesCosts->Amount->Exponent;
      Scc_ISO15118_20_StateMWs.RxEVSE.AdditionalServicesCostsCostPerUnit.Value = DataPtr->AdditionalServicesCosts->CostPerUnit->Value;
      Scc_ISO15118_20_StateMWs.RxEVSE.AdditionalServicesCostsCostPerUnit.Exponent = DataPtr->AdditionalServicesCosts->CostPerUnit->Exponent;
    }

    Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.EnergyCostsFlag = DataPtr->EnergyCostsFlag;
    if (DataPtr->EnergyCostsFlag == (Exi_BitType)Exi_BT_True)
    {
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyCostsAmount.Value = DataPtr->EnergyCosts->Amount->Value;
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyCostsAmount.Exponent = DataPtr->EnergyCosts->Amount->Exponent;
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyCostsCostPerUnit.Value = DataPtr->EnergyCosts->CostPerUnit->Value;
      Scc_ISO15118_20_StateMWs.RxEVSE.EnergyCostsCostPerUnit.Exponent = DataPtr->EnergyCosts->CostPerUnit->Exponent;
    }

    Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.OccupancyCostsFlag = DataPtr->OccupancyCostsFlag;
    if (DataPtr->OccupancyCostsFlag == (Exi_BitType)Exi_BT_True)
    {
      Scc_ISO15118_20_StateMWs.RxEVSE.OccupancyCostsAmount.Value = DataPtr->OccupancyCosts->Amount->Value;
      Scc_ISO15118_20_StateMWs.RxEVSE.OccupancyCostsAmount.Exponent = DataPtr->OccupancyCosts->Amount->Exponent;
      Scc_ISO15118_20_StateMWs.RxEVSE.OccupancyCostsCostPerUnit.Value = DataPtr->OccupancyCosts->CostPerUnit->Value;
      Scc_ISO15118_20_StateMWs.RxEVSE.OccupancyCostsCostPerUnit.Exponent = DataPtr->OccupancyCosts->CostPerUnit->Exponent;
    }

    Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.OverstayCostsFlag = DataPtr->OverstayCostsFlag;
    if (DataPtr->OverstayCostsFlag == (Exi_BitType)Exi_BT_True)
    {
      Scc_ISO15118_20_StateMWs.RxEVSE.OverstayCostsAmount.Value = DataPtr->OverstayCosts->Amount->Value;
      Scc_ISO15118_20_StateMWs.RxEVSE.OverstayCostsAmount.Exponent = DataPtr->OverstayCosts->Amount->Exponent;
      Scc_ISO15118_20_StateMWs.RxEVSE.OverstayCostsCostPerUnit.Value = DataPtr->OverstayCosts->CostPerUnit->Value;
      Scc_ISO15118_20_StateMWs.RxEVSE.OverstayCostsCostPerUnit.Exponent = DataPtr->OverstayCosts->CostPerUnit->Exponent;
    }

    Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.TaxCostsFlag = DataPtr->TaxCostsFlag;
    if ( (DataPtr->TaxCostsFlag == (Exi_BitType)Exi_BT_True)
      && (DataPtr->TaxCosts != NULL_PTR) )
    {
      boolean endOfListReached = FALSE;
      P2CONST(struct Exi_ISO_20_CT_10_DetailedTaxType, AUTOMATIC, SCC_APPL_DATA) nextTaxCostsPtr = DataPtr->TaxCosts;
      uint8_least index = 0;

      for (index = 0; (index < (uint8_least)SCC_ISO15118_20_MAX_TAX_COSTS) && (nextTaxCostsPtr != NULL_PTR); index++)
      {
        Scc_ISO15118_20_StateMWs.RxEVSE.TaxCostsAmount[index].Value = nextTaxCostsPtr->Amount->Value;
        Scc_ISO15118_20_StateMWs.RxEVSE.TaxCostsAmount[index].Exponent = nextTaxCostsPtr->Amount->Exponent;
        Scc_ISO15118_20_StateMWs.RxEVSE.TaxCostsTaxRuleID[index] = nextTaxCostsPtr->TaxRuleID;

        nextTaxCostsPtr = nextTaxCostsPtr->NextTaxCostsPtr;
        if (nextTaxCostsPtr == NULL_PTR)
        {
          endOfListReached = TRUE;
        }
      }
      Scc_ISO15118_20_StateMWs.RxEVSE.NumTaxCosts = (uint8)index;

      /* #20 Check if any TaxCosts could not be stored */
      if (endOfListReached == FALSE)
      {
        /* Since receipt should be sent only in default channel, check for it so that parallel channels do not stop communication in default channel */
        if (Scc_StateM_TxCore.MsgCurrentChannel == (uint8)SCC_CHANNEL_DEFAULT)
        {
          Scc_ISO15118_20_StateMWs.RxEVSE.NumTaxCostsExceeded = TRUE;
        }
      }
    }
  }
}
#endif /* SCC_ENABLE_METERING_RECEIPT */

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsChargeLoopSent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsChargeLoopSent(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Return if a ChargeLoop was transmitted or not */
  return Scc_ISO15118_20_StateMWs.RxEVSE.IsChargeLoopSent;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetChargeLoopSent
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetChargeLoopSent(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Store value into workspace */
  Scc_ISO15118_20_StateMWs.RxEVSE.IsChargeLoopSent = TRUE;
}

/***************************************************************************************
 * MeteringConfirmationReq
 ***************************************************************************************/
#if ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Get_MeterInfo()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Get_MeterInfo(
  P2VAR(Exi_ISO_20_CT_10_MeterInfoType*, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the MeterInfo. */
  *DataPtr = &Scc_ISO15118_20_StateMWs.RxEVSE.MeterInfo;
}
#endif /* SCC_ENABLE_METERING_RECEIPT */

#if ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Get_Receipt()
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
/* PRQA S 6010,6080 1 */ /* MD_MSR_STPTH,MD_MSR_STMIF */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Get_Receipt(
  P2VAR(Exi_ISO_20_CT_10_ReceiptType*, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  uint8_least index = 0;
  P2VAR(struct Exi_ISO_20_CT_10_DetailedTaxType, AUTOMATIC, SCC_APPL_DATA) nextTaxCostsPtr = NULL_PTR;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Store the Receipt. */
  *Flag = SCC_EXIBITTYPE_TO_BOOLEAN(Scc_ISO15118_20_StateMWs.RxEVSE.ReceiptFlag);
  *DataPtr = &Scc_ISO15118_20_StateMWs.RxEVSE.Receipt;

  /* #20 Check if recipt flag and tax costs flag is true */
  if ( (Scc_ISO15118_20_StateMWs.RxEVSE.ReceiptFlag == (Exi_BitType)Exi_BT_True)
    && (Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.TaxCostsFlag == (Exi_BitType)Exi_BT_True) )
  {
    /* #30 Check if atleast 1 tax costs was received */
    if (Scc_ISO15118_20_StateMWs.RxEVSE.NumTaxCosts > 0u)
    {
      Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.TaxCosts = &Scc_ISO15118_20_StateMWs.RxEVSE.TaxCostsNextTaxCosts[0];
      nextTaxCostsPtr = Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.TaxCosts;

      /* #40 Iterate for number of tax costs */
      for (index = 0; (index < (uint8_least)SCC_ISO15118_20_MAX_TAX_COSTS) && (index < (uint8_least)Scc_ISO15118_20_StateMWs.RxEVSE.NumTaxCosts); index++)
      {
        /* #50 Store the tax costs pointers */
        nextTaxCostsPtr->Amount = &Scc_ISO15118_20_StateMWs.RxEVSE.TaxCostsAmount[index];
        nextTaxCostsPtr->TaxRuleID = Scc_ISO15118_20_StateMWs.RxEVSE.TaxCostsTaxRuleID[index];
        if ( ((index + 1u) < (uint8_least)SCC_ISO15118_20_MAX_TAX_COSTS)
          && ((index + 1u) < (uint8_least)Scc_ISO15118_20_StateMWs.RxEVSE.NumTaxCosts) )
        {
          nextTaxCostsPtr->NextTaxCostsPtr = &Scc_ISO15118_20_StateMWs.RxEVSE.TaxCostsNextTaxCosts[index + 1u];
          nextTaxCostsPtr = nextTaxCostsPtr->NextTaxCostsPtr;
        }
      }
      /* #60 Set the last NextTaxCostsPtr to null to indicate end of list */
      nextTaxCostsPtr->NextTaxCostsPtr = NULL_PTR;
    }
    /* #70 Otherwise */
    else
    {
      /* #80 Set tax costs pointer to null */
      Scc_ISO15118_20_StateMWs.RxEVSE.Receipt.TaxCosts = NULL_PTR;
    }
  }

  /* Reset ReceiptFlag since MeteringConfirmationReq is sent and this Receipt is no longer required. This is done so that in case another
   * MeteringConfirmation is requested in ChargeLoopRes and Receipt is set to false then this will not be reflected in the ReceiptFlag */
  Scc_ISO15118_20_StateMWs.RxEVSE.ReceiptFlag = (Exi_BitType)Exi_BT_False;
}
#endif /* SCC_ENABLE_METERING_RECEIPT */

#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Set_EVProcessing
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Set_EVProcessing(Exi_ISO_20_CT_10_processingType EVProcessing)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set value in workspace */
  Scc_ISO15118_20_StateMWs.TxEVSE.EVProcessing = EVProcessing;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Get_EVProcessing
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Get_EVProcessing(P2VAR(Exi_ISO_20_CT_10_processingType, AUTOMATIC, SCC_APPL_DATA) EVProcessingPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get value from workspace */
  *EVProcessingPtr = Scc_ISO15118_20_StateMWs.TxEVSE.EVProcessing;
}
#endif /* SCC_SCHEMA_ISO_20WPT */

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE && SCC_SCHEMA_ISO_20 */

/*lint +e546 */ /* Enable the 'Suspicious use of &' reporting again. */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20_StateM.c
 *********************************************************************************************************************/
