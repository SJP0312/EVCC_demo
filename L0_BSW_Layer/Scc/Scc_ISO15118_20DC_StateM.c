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
/*!        \file  Scc_ISO15118_20DC_StateM.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to ISO 15118-20 DC schema.
 *                Also the Scc core callouts related to DC schema are implemented by this unit.
 *                The received information is then being propagated to the common workspace for -20.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_ISO15118_20DC_STATEM_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON && (defined(SCC_SCHEMA_ISO_20DC) && SCC_SCHEMA_ISO_20DC != 0u) )
#include "Scc_ISO15118_20DC_StateM.h"
#include "Scc_ISO15118_20_StateM.h"
#include "Scc_ISO15118_20_StateMReneg.h"
#include "Scc_ISO15118_20_TimerCfg.h"
#include "Scc_StateM_Vector.h"
#include "Scc_StateM_InterfaceCfg.h"
#include "Scc_ISO15118_20_StateMMeter.h"
#include "Scc_SAP_Exi.h"
#include "Scc_Priv.h"

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

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************/
/* Charge Parameter Discovery                                                                                         */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_StateMDC_ChargeParameterDiscovery_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_StateMDC_ChargeParameterDiscovery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G20-1590] Trigger the ChargeParameterDiscovery request */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_ChargeParameterDiscovery, FALSE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_StateMDC_ChargeParameterDiscovery_Wait
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_StateMDC_ChargeParameterDiscovery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G20-2659], Wait for the ChargeParameterDiscoveryRes */
  /* #20 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatus();
  /* #30 [V2G20-734] Check if a valid response was received */
  if (msgStatus == Scc_MsgStatus_ChargeParameterDiscovery_OK)
  {
    /* #40 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #50 [V2G20-735] Check if invalid response was received */
  else if (msgStatus == Scc_MsgStatus_ChargeParameterDiscovery_Failed)
  {
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
    Scc_DetailedErrorEnumType detailedError = Scc_StateM_GetDetailedErrorChannel(SCC_CHANNEL_DEFAULT);

    /* #60 Check if the selected schema is ACDP
     *     AND Check if msg timeout did not occur (Table 80, ISO 15118-20) */
    if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
      && (detailedError != SccDetailedError_GeneralTimeout) )
    {
      /* Reset error so that the ErrorHandling function is not entered till a new error is reported */
      Scc_ResetError();

      /* #70 [V2G20-4026] Indicate received response and proceed with message processing */
      retVal = Scc_StateMachineState_Done;
    }
    else
#endif /* SCC_SCHEMA_ISO_20ACDP */
    {
      /* #80 Propagate stack error */
      *ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  /* #90 Otherwise */
  else
  {
    /* #100 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_StateMDC_ChargeParameterDiscovery_Process
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_StateMDC_ChargeParameterDiscovery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  Scc_MsgStatusType msgStatus = Scc_StateM_GetMsgStatus();
#endif /* SCC_SCHEMA_ISO_20ACDP */

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  /* #20 Check if a failed response was received in ACDP schema */
  if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
    && (Scc_MsgStatus_ChargeParameterDiscovery_Failed == msgStatus) )
  {
    /* #30 [V2G20-4038] Continue with SessionStop */
    *NextState = Scc_SMS_SessionStop;
  }
  else
#endif /* SCC_SCHEMA_ISO_20ACDP */
  /* #40 [V2G20-2644] Check if charging needs to be stopped */
  if (chargingControl == Scc_ChargingControl_StopCharging)
  {
    *NextState = Scc_SMS_SessionStop;
  }
  /* #50 Otherwise */
  else
  {
    /* #60 [V2G20-2659] Trigger a ScheduleExchangeReq message */
    *NextState = Scc_SMS_ScheduleExchange;
  }

  return retVal;
}

/**********************************************************************************************************************/
/* DC Cable Check                                                                                                     */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_StateMDC_CableCheck_Prepare
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_StateMDC_CableCheck_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_StateM_ControlPilotStateType controlPilotState = Scc_ControlPilotState_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Fetch current control pilot state from application */
  Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);

  /* #20 [V2G20-912], [V2G20-4022] Check if the EV is ready for charging */
  if (controlPilotState == Scc_ControlPilotState_State_C_D)
  {
    /* #30 [V2G20-1431] Set CableCheckReq as cyclic message to true */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_CableCheck, TRUE);
    /* [V2G20-700] Start the cable check timer only for the first time a CableCheckReq message
     * is sent in the communication session. Consecutive cable check messages issued
     * due to an "Ongoing" responses should not restart the timer. */
    /* #40 Check if CableCheck timer is not started */
    if (Scc_StateMachineTimer_IsStarted(Scc_StateMachineTimer_CableCheck) == FALSE)
    {
      /* #50 Start the CableCheck timer */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_CableCheck, Scc_StateM_ParamCfg_Get_CableCheckTimeout());
    }

    retVal = Scc_StateMachineState_Done;
  }
  /* #60 Otherwise */
  else
  {
    /* #70 Waiting for EV to become ready */
    retVal = Scc_StateMachineState_Pending;
  }


  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_StateMDC_CableCheck_Wait
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_StateMDC_CableCheck_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Wait for the CableCheckRes */
  /* #20 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatus();
  /* #30 [V2G20-734] Check if a valid response was received */
  if (msgStatus == Scc_MsgStatus_CableCheck_OK)
  {
     /* #40 [V2G20-1431] Check if EVSEProcessing is set to Ongoing */
    if (Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT) == Scc_EVSEProcessing_Ongoing)
    {
      /* #50 Check if ongoing timer is disabled */
      if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_Ongoing) == TRUE)
      {
        uint16 tempTimerValue;
        tempTimerValue = Scc_StateM_ParamCfg_Get_CableCheckOngoingTimeout();
        /* #60 [V2G20-710] Start the timer */
        Scc_StateMachineTimer_Start(Scc_StateMachineTimer_Ongoing, tempTimerValue);
      }
    }
    /* #70 Otherwise stop the timer */
    else
    {
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    }
    /* #80 Start delay timer to delay the next cable check request based on configured delay time */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_CableCheckNextReqDelay());

    /* #90 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #100 [V2G20-735] Check if invalid response was received */
  else if (msgStatus == Scc_MsgStatus_CableCheck_Failed)
  {
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
    /* #110 Check if the selected schema is ACDP */
    if (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
    {
      /* Reset error so that the ErrorHandling function is not entered till a new error is reported */
      Scc_ResetError();

      /* #120 [V2G20-4026] Indicate received response and proceed with message processing */
      retVal = Scc_StateMachineState_Done;
    }
    else
#endif /* SCC_SCHEMA_ISO_20ACDP */
    {
      /* #130 Propagate stack error */
      *ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  /* #140 Otherwise */
  else
  {
    /* #150 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_StateMDC_CableCheck_Process
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_StateMDC_CableCheck_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  Scc_MsgStatusType msgStatus = Scc_StateM_GetMsgStatus();
#endif /* SCC_SCHEMA_ISO_20ACDP */

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  /* #20 Check if a failed response was received in ACDP schema */
  if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
    && ( (msgStatus == Scc_MsgStatus_CableCheck_Failed)
      || (chargingControl == Scc_ChargingControl_StopCharging) ) )
  {
    /* reset the cycle timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* Stop the V2G_EVCC_CableCheckTimer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_CableCheck);
    /* #30 [V2G20-4040] Continue with Disconnect */
    *NextState = Scc_SMS_ACDP_Disconnect;
  }
  else
#endif /* SCC_SCHEMA_ISO_20ACDP */
  /* #40 [V2G20-2644] Check if charging needs to be stopped */
  if (chargingControl == Scc_ChargingControl_StopCharging)
  {
    /* reset the cycle timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* Stop the V2G_EVCC_CableCheckTimer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_CableCheck);
    *NextState = Scc_SMS_SessionStop;
  }
  /* #50 Otherwise */
  else
  {
    /* #60 Check if the EVSE signals that CableCheck has finished */
    if (Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT) == Scc_EVSEProcessing_Finished)
    {
      /* #70 Reset cycle timer and delay timer if processing is finished */
      /* reset the cycle timer */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
      /* reset the delay timer */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
      /* [V2G20-1399] Stop the V2G_EVCC_CableCheckTimer */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_CableCheck);
      /* #80 [V2G20-1432] Trigger a PreChargeReq message */
      *NextState = Scc_SMS_PreCharge;
      retVal = Scc_StateMachineState_Done;
    }
    /* #90 Otherwise if the EVSE signals that CableCheck is Ongoing */
    else /* EVSEProcessing_Ongoing */
    {
      /* #100 [V2G20-1431] Trigger another CableCheckReq */
      *NextState = Scc_SMS_CableCheck;

      /* #110 Check if the delay counter is disabled */
      if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
      {
        /* #120 The next request can be sent now */
        retVal = Scc_StateMachineState_Done;
      }
      /* #130 Check if the delay counter is expired */
      else if ((Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE))
      {
        /* #140 The next request can be sent now */
        retVal = Scc_StateMachineState_Done;
      }
      else
      {
        /* #150 Otherwise the next request shall be delayed further */
        retVal = Scc_StateMachineState_Pending;
      }
    }
  }

  return retVal;
}


/**********************************************************************************************************************/
/* DC PreCharge                                                                                                       */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_StateMDC_PreCharge_Prepare
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_StateMDC_PreCharge_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_StartPreCharge;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Get the current charging control command */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* #20 Check if the application is ready to continue */
  if (  (chargingControl == Scc_ChargingControl_StartPreCharge)
     || (chargingControl == Scc_ChargingControl_PreChargeCompleted))
  {
    /* #30 [V2G20-1432],[V2G20-1433],[V2G20-1434] Set PreChargeReq as cyclic message to true */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_PreCharge, TRUE);

    /* [V2G20-704] */
    /* Start the pre charge timer only for the first time a PreCharge message
     * is sent in the communication session. Consecutive pre charge messages issued
     * due to an unmatching output voltage at EVSE should not restart the timer. */
    /* #40 Check if the PreCharge timer is not started */
    if (Scc_StateMachineTimer_IsStarted(Scc_StateMachineTimer_PreCharge) == FALSE)
    {
      /* #50 Start the PreCharge timer */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_PreCharge, Scc_StateM_ParamCfg_Get_ISO_20_PreChargeTimeout());
    }
    retVal = Scc_StateMachineState_Done;
  }
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_StateMDC_PreCharge_Wait
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_StateMDC_PreCharge_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Wait for the PreChargeRes */
  /* #20 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatus();
  /* #30 [V2G20-734] Check if a valid response was received */
  if (msgStatus == Scc_MsgStatus_PreCharge_OK)
  {
    /* #40 Start delay timer to delay the next pre charge request based on configured delay time */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_PreChargeNextReqDelay());

    /* #50 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #60 [V2G20-735] Check if invalid response was received */
  else if (msgStatus == Scc_MsgStatus_PreCharge_Failed)
  {
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
    /* #70 Check if the selected schema is ACDP */
    if (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
    {
      /* Reset error so that the ErrorHandling function is not entered till a new error is reported */
      Scc_ResetError();

      /* #80 [V2G20-4026] Indicate received response and proceed with message processing */
      retVal = Scc_StateMachineState_Done;
    }
    else
#endif /* SCC_SCHEMA_ISO_20ACDP */
    {
      /* #90 Propagate stack error */
      *ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
    }
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
 *  Scc_ISO15118_20DC_StateMDC_PreCharge_Process
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_StateMDC_PreCharge_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  Scc_MsgStatusType msgStatus = Scc_StateM_GetMsgStatus();
#endif /* SCC_SCHEMA_ISO_20ACDP */

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  /* #20 Check if a failed response was received in ACDP schema */
  if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
    && ( (msgStatus == Scc_MsgStatus_PreCharge_Failed)
      || (chargingControl == Scc_ChargingControl_StopCharging) ) )
  {
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* reset the pre charge time */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_PreCharge);
    /* #30 [V2G20-4041] Continue with Disconnect */
    *NextState = Scc_SMS_ACDP_Disconnect;
  }
  else
#endif /* SCC_SCHEMA_ISO_20ACDP */
  /* #40 [V2G20-2644] Check if charging needs to be stopped */
  if (chargingControl == Scc_ChargingControl_StopCharging)
  {
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* reset the pre charge time */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_PreCharge);
    *NextState = Scc_SMS_SessionStop;
  }
  /* #50 Check if the application wants to stop the PreCharge sequence */
  else if ( (Scc_ISO15118_20_StateM_GetResponseCode(SCC_CHANNEL_DEFAULT) == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_OK )
         && (chargingControl== Scc_ChargingControl_PreChargeCompleted) )
  {
    /* #60 Reset delay timer if processing is finished */
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* reset the pre charge time */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_PreCharge);

    /* #70 [V2G20-1435] Trigger a PowerDeliveryReq message */
    *NextState = Scc_SMS_PowerDelivery;
    retVal = Scc_StateMachineState_Done;
  }
 /* #80 Otherwise */
  else
  {
    /* #90 [V2G20-1433],[V2G20-1434] Trigger another PreChargeReq message */
    *NextState = Scc_SMS_PreCharge;

    /* #100 Check if the delay counter is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #110 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    /* #120 Check if the delay counter is expired */
    else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #130 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    else
    {
      /* #140 Otherwise the next request shall be delayed further */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  return retVal;
}

/**********************************************************************************************************************/
/* DC Charge Loop                                                                                                     */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_StateMDC_ChargeLoop_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_StateMDC_ChargeLoop_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G20-1438],[V2G20-1441] Set ChargeLoop request and set ChargeLoopReq as cyclic message to true */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_ChargeLoop, TRUE);

  /* #20 [V2G20-1846], [V2G20-1661] Set ChargeLoopSent */
  Scc_ISO15118_20_StateM_SetChargeLoopSent();

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_StateMDC_ChargeLoop_Wait
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_StateMDC_ChargeLoop_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatus();
  /* #20 [V2G20-734] Check if valid response was received */
  if (msgStatus == Scc_MsgStatus_ChargeLoop_OK)
  {
    /* #30 Start delay timer to delay the next charge loop request based on configured delay time */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_ChargeLoopNextReqDelay());

    /* #40 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #50 [V2G20-735] Check if an invalid response was received */
  else if (msgStatus == Scc_MsgStatus_ChargeLoop_Failed)
  {
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
    /* #60 Check if the selected schema is ACDP */
    if (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
    {
      /* Reset error so that the ErrorHandling function is not entered till a new error is reported */
      Scc_ResetError();

      /* #70 [V2G20-4026] Indicate received response and proceed with message processing */
      retVal = Scc_StateMachineState_Done;
    }
    else
#endif /* SCC_SCHEMA_ISO_20ACDP */
    {
      /* #80 Propagate stack error */
      *ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  else
  {
    /* #90 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_StateMDC_ChargeLoop_Process
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
 *
 *
 */
/* PRQA S 6050, 6030, 6080 1 */ /* MD_MSR_STCAL, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_StateMDC_ChargeLoop_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{

  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;                                               /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
  boolean IsPauseEnabled;
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
  Scc_StateM_PaymentOptionType paymentOption = Scc_PaymentOption_None;
#endif
  boolean serviceRenegotiationSupported = Scc_ISO15118_20_StateM_GetServiceRenegotiationSupported();
  boolean isEVSERequestingServiceReneg = Scc_ISO15118_20_StateM_IsEVSERequestingServiceReneg();
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  Scc_MsgStatusType msgStatus = Scc_StateM_GetMsgStatus();
#endif /* SCC_SCHEMA_ISO_20ACDP */
#if (defined(SCC_ENABLE_RENEGOTIATION_CHANNEL) && SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON)
  boolean IsRenegChannelStarted = Scc_ISO15118_20_StateMReneg_IsChannelStarted();
#endif /* SCC_ENABLE_RENEGOTIATION_CHANNEL */

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);
  IsPauseEnabled = Scc_ISO15118_20_StateM_ActivatePause();

#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  /* #20 Check if a failed response was received in ACDP schema */
  if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
    && (msgStatus == Scc_MsgStatus_ChargeLoop_Failed) )
  {
    Scc_DetailedErrorEnumType detailedError = Scc_StateM_GetDetailedErrorChannel(SCC_CHANNEL_DEFAULT);

    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    if ( (Scc_ISO15118_20_StateM_GetResponseCode(SCC_CHANNEL_DEFAULT) >= EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED)
      || (detailedError == SccDetailedError_GeneralTimeout) )
    {
      /* #30 [V2G20-4043] Continue with Disconnect */
      *NextState = Scc_SMS_ACDP_Disconnect;
    }
    else
    {
      /* #40 [V2G20-434] Start the sequence performance timeout since previously the timer was started with ChargeLoop value */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_SequencePerformance, Scc_ISO15118_20_TimerCfg_Get_SequencePerformanceTimeout());

      /* Table 80: Send PowerDeliveryReq in case of error in ACDP ChargeLoop in ISO15118-20 */
      /* #50 Continue with PowerDeliveryReq */
      *NextState = Scc_SMS_PowerDelivery;
    }
    retVal = Scc_StateMachineState_Done;
  }
  else
#endif /* SCC_SCHEMA_ISO_20ACDP */
  /* #60 [V2G20-1444],[V2G20-2195] Check if charging needs to be stopped or has to go to standby */
  /* #70 [V2G-1651] Ask the application also if chargingControl is ServiceRenegotion and ScheduleRenegotiation is not ongoing */
  if  ( ( (chargingControl == Scc_ChargingControl_StopCharging)
       || (chargingControl == Scc_ChargingControl_Standby)
       || ( (chargingControl == Scc_ChargingControl_ServiceRenegotiation)
         && (serviceRenegotiationSupported == TRUE)
         && (isEVSERequestingServiceReneg == TRUE) ) )
#if (defined(SCC_ENABLE_RENEGOTIATION_CHANNEL) && SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON)
     && (IsRenegChannelStarted == FALSE)
#endif /* SCC_ENABLE_RENEGOTIATION_CHANNEL */
      )
  {
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* #80 [V2G20-434] Start the sequence performance timeout since previously the timer was started with ChargeLoop value */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_SequencePerformance, Scc_ISO15118_20_TimerCfg_Get_SequencePerformanceTimeout());

    /* Table 80: Send PowerDeliveryReq in case of error in ACDP ChargeLoop */
    /* #90 Continue with PowerDeliveryReq */
    *NextState = Scc_SMS_PowerDelivery;
    retVal = Scc_StateMachineState_Done;
  }
  /* #100 [V2G20-1850] Check if EVSENotification set to Pause and NotificationMaxDelay set to 60s and ScheduleRenegotiation is not ongoing */
  else if ( (IsPauseEnabled == TRUE)
#if (defined(SCC_ENABLE_RENEGOTIATION_CHANNEL) && SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON)
         && (IsRenegChannelStarted == FALSE)
#endif /* SCC_ENABLE_RENEGOTIATION_CHANNEL */
          )
  {
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* #110 Continue with PowerDeliveryReq */
    *NextState = Scc_SMS_PowerDelivery;
    retVal = Scc_StateMachineState_Done;
  }
  /* #120 Otherwise */
  else
  {
    /* #130 [V2G20-1441] Continue with next ChargeLoopReq */
    *NextState = Scc_SMS_ChargeLoop;

    /* #140 Check if the delay counter is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #150 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    /* #160 Check if the delay counter is expired */
    else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #170 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    else
    {
      /* #180 Otherwise the next request shall be delayed further */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  /* #190 [V2G20-1845] If renegotiation channel is enabled, Check if EVSE requested a ScheduleReneg */
#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
  if ( (Scc_ISO15118_20_StateM_IsEVSERequestingScheduleReneg() == TRUE)
    && (retVal == Scc_StateMachineState_Done) )
  {
    /* #200 Set flag that ScheduleReneg is requested */
    Scc_ISO15118_20_StateMReneg_SetRequestScheduleReneg(TRUE);
  }
#endif

  /* #210 [V2G20-1084], [V2G20-2704] If metering channel is enabled, Check if EVSE requested a MeteringConfirmation */
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
  paymentOption = Scc_ISO15118_20_StateM_GetChosenAuthorizationService();
  if ( (Scc_ISO15118_20_StateM_IsEVSERequestingMeteringConfirmation() == TRUE)
    && (retVal == Scc_StateMachineState_Done)
    && (paymentOption == Scc_PaymentOption_PnC) )
  {
    /* #220 Check if channel is already activated */
    if (Scc_ISO15118_20_StateMMeter_IsChannelStarted() == FALSE)
    {
      /* #230 Set flag that Metering is requested */
      Scc_ISO15118_20_StateMMeter_SetChannelStarted(TRUE);
    }
    /* Otherwise */
    else
    {
      /* #240 Check if MeteringConfirmationReq was not yet sent */
      if (Scc_ISO15118_20_StateMMeter_IsMeteringReqSent() == FALSE)
      {
        /* #250 [V2G20-2105] Propagate stack error */
        /* In case the channel was already activated but the MeteringConfirmationReq was not yet sent then propogate error */
        *ErrorInformation = Scc_SMER_ChargeLoop_InvalidMeteringRequested;
        retVal = Scc_StateMachineState_Failed;
      }
    }
  }
#endif

  return retVal;
}

/**********************************************************************************************************************/
/* WeldingDetection                                                                                                   */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_StateMDC_WeldingDetection_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_StateMDC_WeldingDetection_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10  [V2G20-1448],[V2G20-1573] Set WeldingDetection request and set WeldingDetection as cyclic message to true */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_WeldingDetection, TRUE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_StateMDC_WeldingDetection_Wait
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_StateMDC_WeldingDetection_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Wait for the WeldingDetection */
  /* #20 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatus();
  /* #30 [V2G20-734] Check if a valid response was received */
  if (msgStatus == Scc_MsgStatus_WeldingDetection_OK)
  {
    /* #40 Start delay timer to delay the next welding detection request based on configured delay time */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_WeldingDetectionNextReqDelay());

    /* #50 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #60 [V2G20-735] Check if invalid response was received */
  else if (msgStatus == Scc_MsgStatus_WeldingDetection_Failed)
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
 *  Scc_ISO15118_20DC_StateMDC_WeldingDetection_Process
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_StateMDC_WeldingDetection_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* #20 [V2G20-1462] Check if charging needs to be stopped */
  if (chargingControl == Scc_ChargingControl_StopCharging)
  {
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    *NextState = Scc_SMS_SessionStop;
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G20-1573] Trigger a WeldingDetectionReq message */
  else if (Scc_ISO15118_20_StateM_GetResponseCode(SCC_CHANNEL_DEFAULT) == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_OK)
  {
    *NextState = Scc_SMS_WeldingDetection;

    /* #40 Check if the delay counter is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #50 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    /* #60 Check if the delay counter is expired */
    else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #70 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    else
    {
      /* #80 Otherwise the next request shall be delayed further */
      retVal = Scc_StateMachineState_Pending;
    }
  }
  else
  {
    /* Do nothing */
  }

  return retVal;
}
/**********************************************************************************************************************/
/* State Machine Callouts                                                                                             */
/**********************************************************************************************************************/

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE && SCC_SCHEMA_ISO_20DC */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20DC_StateM.c
 *********************************************************************************************************************/
