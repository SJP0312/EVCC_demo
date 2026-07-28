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
/*!        \file  Scc_ISO15118_20ACDP_StateM.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to ISO 15118-20 ACDP schema.
 *                Also the Scc core callouts related to ACDP schema are implemented by this unit.
 *                The received information is then being propagated to the common workspace for -20.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_ISO15118_20ACDP_STATEM_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( (SCC_ENABLE_STATE_MACHINE == STD_ON) && ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u)) )
#include "Scc_ISO15118_20ACDP_StateM.h"
#include "Scc_ISO15118_20_StateM.h"
#include "Scc_StateM_InterfaceCfg.h"
#include "Scc_StateM_Vector.h"
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
/* ACDP VehiclePositioning                                                                                            */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_StateMACDP_VehiclePositioning_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_StateMACDP_VehiclePositioning_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G20-4046], [V2G20-4047] Trigger the ACDP_Disconnect message */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_ACDP_VehiclePositioning, TRUE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_StateMACDP_VehiclePositioning_Wait
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_StateMACDP_VehiclePositioning_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_MsgStatusType msgStatus = Scc_StateM_GetMsgStatus();

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(*ErrorInformation);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Wait for the ACDP_DisconnectRes */
  /* #20 [V2G20-734] Check if a valid response was received */
  if (msgStatus == Scc_MsgStatus_ACDP_VehiclePositioning_OK)
  {
    /* #30 Start the delay timers */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_VehiclePositioningNextReqDelay());

    /* #40 Check if EVSEProcessing is set to Ongoing */
    if (Scc_EVSEProcessing_Ongoing == Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT))
    {
      /* #50 [V2G20-710] Check if ongoing timer is not yet started */
      if (TRUE == Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_Ongoing))
      {
        /* #60 [V2G20-710] Start the timer */
        Scc_StateMachineTimer_Start(Scc_StateMachineTimer_Ongoing, Scc_StateM_ParamCfg_Get_VehiclePositioningOngoingTimeout());
      }
    }
    /* #70 Otherwise stop the timer */
    else
    {
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    }

    /* #80 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #90 [V2G20-4031] Check if invalid response was received */
  else if (msgStatus == Scc_MsgStatus_ACDP_VehiclePositioning_Failed)
  {
    /* #100 Check if msg timeout occurred (Table 80, ISO 15118-20) */
    if (Scc_StateM_GetDetailedErrorChannel(SCC_CHANNEL_DEFAULT) == SccDetailedError_GeneralTimeout)
    {
      /* #110 Indicate error to enforce SDP-Restart */
      retVal = Scc_StateMachineState_Failed;
    }
    /* #120 Otherwise */
    else
    {
      /* #130 Handle as exception on app level */
      /* Reset error so that the ErrorHandling function is not entered till a new error is reported */
      Scc_ResetError();

      /* #140 Indicate received response and proceed with message processing */
      retVal = Scc_StateMachineState_Done;
    }
  }
  /* #150 Otherwise */
  else
  {
    /* #160 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_StateMACDP_VehiclePositioning_Process
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_StateMACDP_VehiclePositioning_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  Scc_MsgStatusType msgStatus = Scc_StateM_GetMsgStatus();
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);
  /* #20 Check if a failed response is received */
  if ( (msgStatus == Scc_MsgStatus_ACDP_VehiclePositioning_Failed)
    || (chargingControl == Scc_ChargingControl_StopCharging) )
  {
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* reset the cycle timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    /* #30 [V2G20-4031] Continue with SessionStopReq */
    *NextState = Scc_SMS_SessionStop;
  }
  /* #40 Otherwise check if EVSEProcessing is set to Finished */
  else if (Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT) == Scc_EVSEProcessing_Finished)
  {
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* reset the cycle timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    /* #50 [V2G20-4049] Continue with AuthorizationSetupReq */
    *NextState = Scc_SMS_AuthorizationSetup;
  }
  /* #60 Otherwise */
  else
  {
    /* #70 [V2G20-4047] Continue with next ACDP_VehiclePositioningReq */
    *NextState = Scc_SMS_ACDP_VehiclePositioning;

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

  return retVal;
}

/**********************************************************************************************************************/
/* ACDP Connect                                                                                                    */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_StateMACDP_Connect_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_StateMACDP_Connect_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G20-4050], [V2G20-4051] Trigger the ACDP_Connect message */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_ACDP_Connect, TRUE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_StateMACDP_Connect_Wait
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_StateMACDP_Connect_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_MsgStatusType msgStatus = Scc_StateM_GetMsgStatus();

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(*ErrorInformation);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Wait for the ACDP_ConnectRes */
  /* #20 [V2G20-734] Check if a valid response was received */
  if (msgStatus == Scc_MsgStatus_ACDP_Connect_OK)
  {
    /* #30 Start the delay timers */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_ConnectNextReqDelay());

    /* #40 Check if EVSEProcessing is set to Ongoing */
    if (Scc_EVSEProcessing_Ongoing == Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT))
    {
      /* #50 [V2G20-710] Check if ongoing timer is not yet started */
      if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_Ongoing) == TRUE)
      {
        /* #60 [V2G20-710] Start the timer */
        Scc_StateMachineTimer_Start(Scc_StateMachineTimer_Ongoing, Scc_StateM_ParamCfg_Get_ConnectOngoingTimeout());
      }
    }
    /* #70 Otherwise stop the timer */
    else
    {
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    }

    /* #80 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #90 [V2G20-4039] Check if invalid response was received */
  else if (msgStatus == Scc_MsgStatus_ACDP_Connect_Failed)
  {
    /* Reset error so that the ErrorHandling function is not entered till a new error is reported */
    Scc_ResetError();

    /* #100 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
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
 *  Scc_ISO15118_20ACDP_StateMACDP_ACDP_Connect_Process
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_StateMACDP_Connect_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  Scc_MsgStatusType msgStatus = Scc_StateM_GetMsgStatus();
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);
  /* #20 Check if a failed response was received
   *     OR [V2G20-4027] Check if Application wants to shutdown communication */
  if ( (msgStatus == Scc_MsgStatus_ACDP_Connect_Failed)
    || (chargingControl == Scc_ChargingControl_StopCharging) )
  {
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* reset the cycle timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    /* #30 [V2G20-4039] Continue with ACDP_Disconnect */
    *NextState = Scc_SMS_ACDP_Disconnect;
  }
  else if (Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT) == Scc_EVSEProcessing_Finished)
  {
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* reset the cycle timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    /* #40 [V2G20-4052] Continue with CableCheck */
    *NextState = Scc_SMS_CableCheck;
  }
  /* #50 Otherwise */
  else
  {
    /* #60 [V2G20-4051] Continue with next ConnectReq */
    *NextState = Scc_SMS_ACDP_Connect;

    /* #70 Check if the delay counter is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #80 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    /* #90 Check if the delay counter is expired */
    else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #100 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    else
    {
      /* #110 Otherwise the next request shall be delayed further */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  return retVal;
}

/**********************************************************************************************************************/
/* ACDP Disconnect                                                                                                    */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_StateMACDP_Disconnect_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_StateMACDP_Disconnect_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G20-4053], [V2G20-4054] Trigger the ACDP_Disconnect message */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_ACDP_Disconnect, TRUE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_StateMACDP_Disconnect_Wait
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_StateMACDP_Disconnect_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_MsgStatusType msgStatus = Scc_StateM_GetMsgStatus();

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(*ErrorInformation);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Wait for the ACDP_DisconnectRes */
  /* #20 [V2G20-734] Check if a valid response was received */
  if (msgStatus == Scc_MsgStatus_ACDP_Disconnect_OK)
  {
    /* #30 Start the delay timers */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_DisconnectNextReqDelay());

    /* #40 Check if EVSEProcessing is set to Ongoing */
    if (Scc_EVSEProcessing_Ongoing == Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT))
    {
      /* #50 [V2G20-710] Check if ongoing timer is not yet started */
      if (TRUE == Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_Ongoing))
      {
        /* #60 [V2G20-710] Start the timer */
        Scc_StateMachineTimer_Start(Scc_StateMachineTimer_Ongoing, Scc_StateM_ParamCfg_Get_DisconnectOngoingTimeout());
      }
    }
    /* #70 Otherwise stop the timer */
    else
    {
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    }

    /* #80 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #90 [V2G20-4044] Check if invalid response was received */
  else if (msgStatus == Scc_MsgStatus_ACDP_Disconnect_Failed)
  {
    /* Reset error so that the ErrorHandling function is not entered till a new error is reported */
    Scc_ResetError();

    /* #100 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
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
 *  Scc_ISO15118_20ACDP_StateMACDP_ACDP_Disconnect_Process
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_StateMACDP_Disconnect_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  Scc_MsgStatusType msgStatus = Scc_StateM_GetMsgStatus();

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Check if a failed response or Finished EVSEProcessing was received */
  if ( (Scc_EVSEProcessing_Finished == Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT))
    || (Scc_MsgStatus_ACDP_Disconnect_Failed == msgStatus) )
  {
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* reset the cycle timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    /* #20 [V2G20-4044], [V2G20-4055] Continue with SessionStop */
    *NextState = Scc_SMS_SessionStop;
  }
  /* #30 Otherwise */
  else
  {
    /* #40 [V2G20-4054] Continue with next DisconnectReq */
    *NextState = Scc_SMS_ACDP_Disconnect;

    /* #50 Check if the delay counter is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #60 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    /* #70 Check if the delay counter is expired */
    else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #80 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    else
    {
      /* #90 Otherwise the next request shall be delayed further */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  return retVal;
}

/**********************************************************************************************************************/
/* State Machine Callouts                                                                                             */
/**********************************************************************************************************************/

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE && SCC_SCHEMA_ISO_20ACDP */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20ACDP_StateM.c
 *********************************************************************************************************************/
