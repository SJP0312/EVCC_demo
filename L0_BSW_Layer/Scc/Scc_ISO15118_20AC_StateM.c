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
/*!        \file  Scc_ISO15118_20AC_StateM.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to ISO 15118-20 AC schema.
 *                Also the Scc core callouts related to AC schema are implemented by this unit.
 *                The received information is then being propagated to the common workspace for -20.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_ISO15118_20AC_STATEM_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON && (defined(SCC_SCHEMA_ISO_20AC) && SCC_SCHEMA_ISO_20AC != 0u) )

#include "Scc_ISO15118_20AC_StateM.h"
#include "Scc_ISO15118_20_StateM.h"
#include "Scc_ISO15118_20_StateMReneg.h"
#include "Scc_ISO15118_20_TimerCfg.h"
#include "Scc_StateM_Vector.h"
#include "Scc_StateM_InterfaceCfg.h"
#include "Scc_StateM_ParamsCfg.h"
#include "Scc_ISO15118_20_StateMMeter.h"

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
 *  Scc_ISO15118_20AC_StateMAC_ChargeParameterDiscovery_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20AC_StateMAC_ChargeParameterDiscovery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;
  Scc_StateM_PWMStateType pwmState = Scc_PWMState_ChargingNotAllowed;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(*ErrorInformation);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* get the current status of the cable */
  Scc_StateM_InterfaceCfg_Get_PWMState(&pwmState);
  /* #10 [V2G20-930] Check if the duty cycle is not 5% or nominal */
  if (Scc_PWMState_ChargingNotAllowed == pwmState)
  {
    /* wait */
  }
  else
  {
    /* #20 [V2G20-1590] Trigger the ChargeParameterDiscovery request */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_ChargeParameterDiscovery, FALSE);

    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20AC_StateMAC_ChargeParameterDiscovery_Wait
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20AC_StateMAC_ChargeParameterDiscovery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G20-2659] Wait for the ChargeParameterDiscoveryRes */
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
 *  Scc_ISO15118_20AC_StateMAC_ChargeParameterDiscovery_Process
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20AC_StateMAC_ChargeParameterDiscovery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(*ErrorInformation);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Fetch the current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* #20 [V2G20-2644] Check if charging needs to be stopped */
  if (chargingControl == Scc_ChargingControl_StopCharging)
  {
    *NextState = Scc_SMS_SessionStop;
  }
  /* #30 Otherwise */
  else
  {
    /* #40 [V2G20-2659] Trigger a ScheduleExchangeReq message */
    *NextState = Scc_SMS_ScheduleExchange;
  }

  return retVal;
}


/**********************************************************************************************************************/
/* AC Charge Loop                                                                                                     */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20AC_StateMAC_ChargeLoop_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20AC_StateMAC_ChargeLoop_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Set ChargeLoopReq as cyclic message to true */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_ChargeLoop, TRUE);

  /* #20 [V2G20-1846], [V2G20-1661] Set ChargeLoopSent */
  Scc_ISO15118_20_StateM_SetChargeLoopSent();

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20AC_StateMAC_ChargeLoop_Wait
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20AC_StateMAC_ChargeLoop_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatus();
  /* #20 [V2G20-734],[V2G20-1440],[V2G20-1443],[V2G20-2193] Check if valid response was received */
  if ( (msgStatus == Scc_MsgStatus_ChargeLoop_OK)
    && (TRUE == Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT]) )
  {
    /* #30 Start delay timer to delay the next charge loop request based on configured delay time */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_ChargeLoopNextReqDelay());

    /* #40 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;
  }
  /* #50 [V2G20-735] Check if an invalid response was received */
  else if (msgStatus == Scc_MsgStatus_ChargeLoop_Failed)
  {
    /* #60 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #70 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20AC_StateMAC_ChargeLoop_Process
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
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20AC_StateMAC_ChargeLoop_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{

  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;                                               /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
  boolean isPauseEnabled;
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
  Scc_StateM_PaymentOptionType paymentOption = Scc_PaymentOption_None;
#endif
  boolean serviceRenegotiationSupported = Scc_ISO15118_20_StateM_GetServiceRenegotiationSupported();
  boolean isEVSERequestingServiceReneg = Scc_ISO15118_20_StateM_IsEVSERequestingServiceReneg();
#if (defined(SCC_ENABLE_RENEGOTIATION_CHANNEL) && SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON)
  boolean IsRenegChannelStarted = Scc_ISO15118_20_StateMReneg_IsChannelStarted();
#endif /* SCC_ENABLE_RENEGOTIATION_CHANNEL */

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(*ErrorInformation);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);
  isPauseEnabled = Scc_ISO15118_20_StateM_ActivatePause();

  /* #10 [V2G20-1443],[V2G20-2193],[V2G20-1969] Check if charging needs to be stopped or has to go to standby */
  /* #20 [V2G-1964] Ask the application also if chargingControl is ServiceRenegotion and ScheduleRenegotiation is not ongoing */
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
    /* #30 [V2G20-434] Start the sequence performance timeout since previously the timer was started with ChargeLoop value */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_SequencePerformance, Scc_ISO15118_20_TimerCfg_Get_SequencePerformanceTimeout());

    /* #40 Continue with PowerDeliveryReq */
    *NextState = Scc_SMS_PowerDelivery;
    retVal = Scc_StateMachineState_Done;
  }
  /* #50 [V2G20-1850] Check if EVSENotification set to Pause and NotificationMaxDelay set to 60s and ScheduleRenegotiation is not ongoing */
  else if ( (isPauseEnabled == TRUE)
#if (defined(SCC_ENABLE_RENEGOTIATION_CHANNEL) && SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON)
         && (IsRenegChannelStarted == FALSE)
#endif /* SCC_ENABLE_RENEGOTIATION_CHANNEL */
          )
  {
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    *NextState = Scc_SMS_PowerDelivery;
    retVal = Scc_StateMachineState_Done;
  }
  /* #60 Otherwise */
  else
  {
    /* #70 [V2G20-1440] Continue with next ChargeLoopReq */
    *NextState = Scc_SMS_ChargeLoop;

    /* #80 Check if the delay counter is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #90 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    /* #100 Check if the delay counter is expired */
    else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #110 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    else
    {
      /* #120 Otherwise the next request shall be delayed further */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  /* #130 [V2G20-1845] If renegotiation channel is enabled, Check if EVSE requested a ScheduleReneg */
#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
  if ( (Scc_ISO15118_20_StateM_IsEVSERequestingScheduleReneg() == TRUE)
    && (retVal == Scc_StateMachineState_Done) )
  {
    /* #140 Set flag that ScheduleReneg is requested */
    Scc_ISO15118_20_StateMReneg_SetRequestScheduleReneg(TRUE);
  }
#endif

  /* #150 [V2G20-1084], [V2G20-2704] If metering channel is enabled, Check if EVSE requested a MeteringConfirmation */
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
  paymentOption = Scc_ISO15118_20_StateM_GetChosenAuthorizationService();
  if ( (Scc_ISO15118_20_StateM_IsEVSERequestingMeteringConfirmation() == TRUE)
    && (retVal == Scc_StateMachineState_Done)
    && (paymentOption == Scc_PaymentOption_PnC) )
  {
    /* #160 Check if channel is already activated */
    if (Scc_ISO15118_20_StateMMeter_IsChannelStarted() == FALSE)
    {
      /* #170 Set flag that Metering is requested */
      Scc_ISO15118_20_StateMMeter_SetChannelStarted(TRUE);
    }
    /* Otherwise */
    else
    {
      /* #180 Check if MeteringConfirmationReq was not yet sent */
      if (Scc_ISO15118_20_StateMMeter_IsMeteringReqSent() == FALSE)
      {
        /* #190 [V2G20-2105] Propagate stack error */
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
/* State Machine Callouts                                                                                             */
/**********************************************************************************************************************/

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE && SCC_SCHEMA_ISO_20AC */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20AC_StateM.c
 *********************************************************************************************************************/
