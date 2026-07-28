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
/*!        \file  Scc_ISO15118_20WPT_StateM.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to ISO 15118-20 WPT schema.
 *                Also the Scc core callouts related to WPT schema are implemented by this unit.
 *                The received information is then being propagated to the common workspace for -20.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_ISO15118_20WPT_STATEM_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON && (defined(SCC_SCHEMA_ISO_20WPT) && SCC_SCHEMA_ISO_20WPT != 0u) )
#include "Scc.h"
#include "Scc_ISO15118_20WPT_StateM.h"
#include "Scc_ISO15118_20_StateM.h"
#include "Scc_ISO15118_20_StateMReneg.h"
#include "Scc_StateM_InterfaceCfg.h"
#include "Scc_StateM_Vector.h"
#include "Scc_ISO15118_20_StateMMeter.h"
#include "Scc_ISO15118_20_TimerCfg.h"
#include "Scc_StateM_ParamsCfg.h"

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

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************/
/* Fine Positioning Setup                                                                                             */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_StateMWPT_FinePositioningSetup_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_FinePositioningSetup_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);
  /* #10 [V2G20-5024], [V2G20-5042] Trigger the FinePositioningSetup request */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_FinePositioningSetup, TRUE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_StateMWPT_FinePositioningSetup_Wait
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_FinePositioningSetup_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_MsgStatusType msgStatus = Scc_MsgStatus_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);
  /* #10 Wait for the FinePositioningSetupRes */
  /* #20 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatus();

  /* #30 Check if a valid response was received */
  if (msgStatus == Scc_MsgStatus_FinePositioningSetup_OK)
  {
    /* #40 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
    /* #50 Start delay timer to delay the next FinePositioningSetup request based on configured delay time */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_FinePositioningSetupNextReqDelay());
  }
  /* #60 Check if invalid response was received */
  else if (msgStatus == Scc_MsgStatus_FinePositioningSetup_Failed)
  {
    Exi_ISO_20_CT_10_responseCodeType responseCode = Scc_ISO15118_20_StateM_GetResponseCode(SCC_CHANNEL_DEFAULT);

    /* #70 [V2G20-5067] Check if response code was failed */
    if (responseCode >= EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED)
    {
      /* #80 Indicate received response and proceed with message processing */
      retVal = Scc_StateMachineState_Done;
    }
    /* #90 Otherwise */
    else
    {
      /* #100 Propagate stack error */
      *ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
    }
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
 *  Scc_ISO15118_20WPT_StateMWPT_FinePositioningSetup_Process
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_FinePositioningSetup_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);
  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);
  /* #20 Check if Failed response was received or if Application wants to terminate communication */
  if ( (Scc_StateM_GetMsgStatus() == Scc_MsgStatus_FinePositioningSetup_Failed)
    || (chargingControl == Scc_ChargingControl_StopCharging) )
  {
    /* [V2G20-5067], [V2G20-2644] Trigger a SessionStopReq */
    *NextState = Scc_SMS_SessionStop;
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 Check if a warning response code was received */
  else if (TRUE == Scc_ISO15118_20_StateM_IsResponseCodeWarning())
  {
    Exi_ISO_20_CT_10_responseCodeType responseCode = Scc_ISO15118_20_StateM_GetResponseCode(SCC_CHANNEL_DEFAULT);

    /* #40 Check if a WARNING_WPT response code was received */
    if (responseCode == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_WPT)
    {
      /* #50 Check if Application wants to restart FinePositioningSetup */
      if (chargingControl == Scc_ChargingControl_StartFinePositioningSetup)
      {
        /* #60 ISO-20 User Group Issue 152: Trigger a FinePositioningSetupReq */
        *NextState = Scc_SMS_FinePositioningSetup;
        /* reset the delay timer */
        Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
        retVal = Scc_StateMachineState_Done;
      }
      /* #70 Otherwise */
      else
      {
        /* #80 Application needs more time to process */
        retVal = Scc_StateMachineState_Pending;
      }
    }
    else
    {
      /* Report Det error */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_20WPT_STATEM_FINE_POS_SETUP, SCC_DET_INV_PARAM);
#endif
      *ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  /* #90 Otherwise check if application wants to move to FinePositioning */
  else if (chargingControl == Scc_ChargingControl_StartFinePositioning)
  {
    /* #100 [V2G20-5024] Trigger a FinePositioningReq */
    *NextState = Scc_SMS_FinePositioning;
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    retVal = Scc_StateMachineState_Done;
  }
  /* #110 Otherwise check if application wants to continue with FinePositioningSetup */
  else if (chargingControl == Scc_ChargingControl_StartFinePositioningSetup)
  {
    /* #120 [V2G20-5024] Trigger a FinePositioningSetup */
    *NextState = Scc_SMS_FinePositioningSetup;

    /* #130 Check if the delay counter is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #140 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    /* #150 Check if the delay counter is expired */
    else if ((Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE))
    {
      /* #160 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    else
    {
      /* #170 Otherwise the next request shall be delayed further */
      retVal = Scc_StateMachineState_Pending;
    }
  }
  else
  {
    /* #180 Otherwise the next request shall be delayed further */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}


/**********************************************************************************************************************/
/* Fine Positioning                                                                                                   */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_StateMWPT_FinePositioning_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_FinePositioning_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);
  /* #10 Trigger a FinePositioningReq */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_FinePositioning, TRUE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_StateMWPT_FinePositioning_Wait
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_FinePositioning_Wait(
   P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                  /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_MsgStatusType msgStatus = Scc_MsgStatus_None;
  Exi_ISO_20_CT_10_responseCodeType responseCode = Scc_ISO15118_20_StateM_GetResponseCode(SCC_CHANNEL_DEFAULT);

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);
  /* #10 Wait for the FinePositioningRes */
  /* #20 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatus();

  /* #30 Check if a valid response was received */
  if (msgStatus == Scc_MsgStatus_FinePositioning_OK)
  {
    /* #40 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
    /* #50 Start delay timer to delay the next FinePositioning request based on configured delay time */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_FinePositioningNextReqDelay());

    /* #60 Check if EVSEProcessing is set to Ongoing */
    if (Scc_EVSEProcessing_Ongoing == Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT))
    {
      /* #70 [V2G20-710] Check if ongoing timer is not yet started */
      if (TRUE == Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_Ongoing))
      {
        /* #80 [V2G20-710] Start the timer */
        Scc_StateMachineTimer_Start(Scc_StateMachineTimer_Ongoing, Scc_StateM_ParamCfg_Get_FinePositioningOngoingTimeout());
      }
    }
    /* #90 Otherwise stop the timer */
    else
    {
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    }
  }
  /* #100 Check if invalid response was received */
  else if (msgStatus == Scc_MsgStatus_FinePositioning_Failed)
  {
    /* #110 [V2G20-5067] Check if response code was failed */
    if (responseCode >= EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED)
    {
      /* #120 Indicate received response and proceed with message processing */
      retVal = Scc_StateMachineState_Done;
    }
    /* #130 Otherwise */
    else
    {
      /* #140 Propagate stack error */
      *ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
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
 *  Scc_ISO15118_20WPT_StateMWPT_FinePositioning_Process
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_FinePositioning_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* #20 Check if Failed response was received or if Application wants to terminate communication */
  if ( (Scc_StateM_GetMsgStatus() == Scc_MsgStatus_FinePositioning_Failed)
    || (chargingControl == Scc_ChargingControl_StopCharging) )
  {
    /* #30 [V2G20-5067], [V2G20-5055], [V2G20-2644] Trigger a SessionStopReq */
    *NextState = Scc_SMS_SessionStop;
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

    retVal = Scc_StateMachineState_Done;
  }
  /* #40 Check if a warning response code was received */
  else if (TRUE == Scc_ISO15118_20_StateM_IsResponseCodeWarning())
  {
    Exi_ISO_20_CT_10_responseCodeType responseCode = Scc_ISO15118_20_StateM_GetResponseCode(SCC_CHANNEL_DEFAULT);

    /* [V2G20-5055] Check if EVSEProcessing is Finished and ResponseCode is warning */
    if ( (Scc_EVSEProcessing_Finished == Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT))
      && (responseCode == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_WPT) )
    {
      /* #50 Otherwise check if Application wants to restart FinePositioningSetup */
      if (chargingControl == Scc_ChargingControl_StartFinePositioningSetup)
      {
        /* #60 [V2G20-5055] Trigger a FinePositioningSetupReq */
        *NextState = Scc_SMS_FinePositioningSetup;
        /* reset the delay timer */
        Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

        retVal = Scc_StateMachineState_Done;
      }
      /* #70 Otherwise */
      else
      {
        /* #80 Application needs more time to process */
        retVal = Scc_StateMachineState_Pending;
      }
    }
    else
    {
      /* Report Det error */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_20WPT_STATEM_FINE_POS, SCC_DET_INV_PARAM);
#endif
      *ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  /* #90 Check if EVSEProcessing is set to Ongoing */
  else if (Scc_EVSEProcessing_Ongoing == Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT))
  {
    /* [V2G20-5025], [V2G20-5026] Trigger FinePositioningReq */
    *NextState = Scc_SMS_FinePositioning;

    /* #100 Check if the delay counter is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #110 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    /* #120 Check if the delay counter is expired */
    else if ((Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE))
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
  else
  {
    /* [V2G20-5029] Trigger PairingReq */
    *NextState = Scc_SMS_Pairing;
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************/
/* Pairing                                                                                                            */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_StateMWPT_Pairing_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_Pairing_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);
  /* #10 Trigger a PairingReq */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_Pairing, TRUE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_StateMWPT_Pairing_Wait
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_Pairing_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_MsgStatusType msgStatus = Scc_MsgStatus_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);
  /* #10 Wait for the PairingRes */
  /* #20 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatus();

  /* #30 Check if a valid response was received */
  if (msgStatus == Scc_MsgStatus_Pairing_OK)
  {
    /* #40 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_PairingNextReqDelay());

    /* #50 Check if EVSEProcessing is set to Ongoing */
    if (Scc_EVSEProcessing_Ongoing == Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT))
    {
      /* #60 [V2G20-710] Check if ongoing timer is not yet started */
      if (TRUE == Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_Ongoing))
      {
        /* #70 [V2G20-710] Start the timer */
        Scc_StateMachineTimer_Start(Scc_StateMachineTimer_Ongoing, Scc_StateM_ParamCfg_Get_PairingOngoingTimeout());
      }
    }
    /* #80 Otherwise stop the timer */
    else
    {
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    }
  }
  /* #90 [V2G20-5067] Check if invalid response was received */
  else if (msgStatus == Scc_MsgStatus_Pairing_Failed)
  {
    /* #100 Check if the error is caused by a PairingRes with ResponseCode Failed  */
    if (Scc_ISO15118_20_StateM_GetResponseCode(SCC_CHANNEL_DEFAULT) >= EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED)
    {
      /* #110 Handle the error in state process, proceed with message processing */
      retVal = Scc_StateMachineState_Done;
    }
    /* #120 Otherwise error results e.g. from V2G_EVCC_Msg_Timeout */
    else
    {
      /* #130 [V2G20-1966] Stop communication */
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
 *  Scc_ISO15118_20WPT_StateMWPT_Pairing_Process
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_Pairing_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* #20 Check if an error occurred or Application wants to terminate communication */
  if (   (Scc_StateM_GetMsgStatus() == Scc_MsgStatus_Pairing_Failed)
      || (chargingControl == Scc_ChargingControl_StopCharging))
  {
    /* #30 [V2G20-5067] [V2G20-5054], [V2G20-2644] Trigger a SessionStopReq */
    *NextState = Scc_SMS_SessionStop;
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

    retVal = Scc_StateMachineState_Done;
  }
  /* #40 Check if a warning response code was received */
  else if (TRUE == Scc_ISO15118_20_StateM_IsResponseCodeWarning())
  {
    Exi_ISO_20_CT_10_responseCodeType responseCode = Scc_ISO15118_20_StateM_GetResponseCode(SCC_CHANNEL_DEFAULT);

    /* #50 [V2G20-5054] Check if EVSEProcessing is Finished and ResponseCode is warning */
    if ((Scc_EVSEProcessing_Finished == Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT))
      && (responseCode == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_WPT))
    {
      /* #60 Otherwise check if Application wants to restart FinePositioningSetup */
      if (chargingControl == Scc_ChargingControl_StartFinePositioningSetup)
      {
        /* #70 [V2G20-5054] Trigger a FinePositioningSetupReq, SessionStopReq is triggered in branch above */
        *NextState = Scc_SMS_FinePositioningSetup;
        /* reset the delay timer */
        Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

        retVal = Scc_StateMachineState_Done;
      }
      /* #80 Otherwise */
      else
      {
        /* #90 Application needs more time to process */
        retVal = Scc_StateMachineState_Pending;
      }
    }
    else
    {
      /* Report Det error */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_20WPT_STATEM_PAIRING, SCC_DET_INV_PARAM);
#endif
      *ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  /* #100 Check if EVSEProcessing is set to Ongoing */
  else if (Scc_EVSEProcessing_Ongoing == Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT))
  {
    Exi_ISO_20_CT_10_processingType EVProcessing;
    Scc_ISO15118_20_StateM_Get_EVProcessing(&EVProcessing);

    if (EVProcessing == EXI_ISO_20_CT_10_PROCESSING_TYPE_FINISHED)
    {
      /* [V2G20-5032] */
      *NextState = Scc_SMS_AuthorizationSetup;
      retVal = Scc_StateMachineState_Done;
    }
    else
    {
      /* [V2G20-5030], [V2G20-5031] Trigger PairingReq with EVProcessing = Ongoing or EVProcessing = Finished */
      *NextState = Scc_SMS_Pairing;

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
  else
  {
    /* [V2G20-5034] Trigger AuthorizationSetupReq */
    *NextState = Scc_SMS_AuthorizationSetup;
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************/
/* Charge Parameter Discovery                                                                                         */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_StateMWPT_ChargeParameterDiscovery_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_ChargeParameterDiscovery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);
  /* #10 Trigger a ChargeParameterDiscoveryReq */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_ChargeParameterDiscovery, FALSE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_StateMWPT_ChargeParameterDiscovery_Wait
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_ChargeParameterDiscovery_Wait(
   P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                  /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_MsgStatusType msgStatus = Scc_MsgStatus_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);
  /* #10 Wait for the ChargeParameterDiscoveryRes */
  /* #20 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatus();

  /* #30 Check if a valid response was received */
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
 *  Scc_ISO15118_20WPT_StateMWPT_ChargeParameterDiscovery_Process
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_ChargeParameterDiscovery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch the current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* #20 [V2G20-2644], [V2G20-5062] Check if charging needs to be stopped */
  if (chargingControl == Scc_ChargingControl_StopCharging)
  {
    *NextState = Scc_SMS_SessionStop;
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 Otherwise check if a warning response code was received */
  else if (TRUE == Scc_ISO15118_20_StateM_IsResponseCodeWarning())
  {
    Exi_ISO_20_CT_10_responseCodeType responseCode = Scc_ISO15118_20_StateM_GetResponseCode(SCC_CHANNEL_DEFAULT);

    /* [V2G20-5062] Check if ResponseCode is warning wpt */
    if (responseCode == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_WPT)
    {
      /* #40 Otherwise check if Application wants to restart FinePositioningSetup */
      if (chargingControl == Scc_ChargingControl_StartFinePositioningSetup)
      {
        /* #50 [V2G20-5062] Trigger a FinePositioningSetupReq */
        *NextState = Scc_SMS_FinePositioningSetup;
        retVal = Scc_StateMachineState_Done;
      }
      /* #60 Otherwise */
      else
      {
        /* #70 Application needs more time to process */
        retVal = Scc_StateMachineState_Pending;
      }
    }
    else
    {
      *ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  else
  {
    /* #80 [V2G20-2659] Trigger a ScheduleExchangeReq message */
    *NextState = Scc_SMS_ScheduleExchange;
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************/
/* Alignment Check                                                                                                    */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_StateMWPT_AlignmentCheck_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_AlignmentCheck_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);
  /* #10 Trigger an AlignmentCheckReq */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_AlignmentCheck, TRUE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_StateMWPT_AlignmentCheck_Wait
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_AlignmentCheck_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_MsgStatusType msgStatus = Scc_MsgStatus_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);
  /* #10 Wait for the AlignmentCheckRes */
  /* #20 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatus();

  /* #30 Check if a valid response was received */
  if (msgStatus == Scc_MsgStatus_AlignmentCheck_OK)
  {
    /* #40 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
    /* #50 Start delay timer to delay the next AlignmentCheck request based on configured delay time */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_AlignmentCheckNextReqDelay());

    /* #60 Check if EVSEProcessing is set to Ongoing */
    if (Scc_EVSEProcessing_Ongoing == Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT))
    {
      /* #70 [V2G20-710] Check if ongoing timer is not yet started */
      if (TRUE == Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_Ongoing))
      {
        /* #80 [V2G20-710] Start the timer */
        Scc_StateMachineTimer_Start(Scc_StateMachineTimer_Ongoing, Scc_StateM_ParamCfg_Get_AlignmentCheckOngoingTimeout());
      }
    }
    /* #90 Otherwise stop the timer */
    else
    {
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    }
  }
  /* #100 [V2G20-5067] Check if an invalid response was received */
  else if (msgStatus == Scc_MsgStatus_AlignmentCheck_Failed)
  {
    /* #110 Check if the error is caused by an AlignmentCheckRes with ResponseCode Failed  */
    if (Scc_ISO15118_20_StateM_GetResponseCode(SCC_CHANNEL_DEFAULT) >= EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED)
    {
      /* #120 [V2G20-5067] Continue with process state to transmit a SessionStopReq */
      retVal = Scc_StateMachineState_Done;
    }
    /* #130 Otherwise error results e.g. from V2G_EVCC_Msg_Timeout */
    else
    {
      /* #140 [V2G20-1966] Stop communication */
      *ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
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
 *  Scc_ISO15118_20WPT_StateMWPT_AlignmentCheck_Process
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_AlignmentCheck_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
  Scc_StateM_ChargeStatusType chargeStatus = Scc_ChargeStatus_Preparing;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* #20 Fetch current charge status from 20CM StateM */
  chargeStatus = Scc_ISO15118_20_StateM_GetChargeStatus();

  /* #30 Check if an error occurred or Application wants to terminate communication [V2G20-2644]  */
  if (   (Scc_StateM_GetMsgStatus() == Scc_MsgStatus_AlignmentCheck_Failed)
      || (     ( chargingControl == Scc_ChargingControl_StopCharging)
            && ( chargeStatus < Scc_ChargeStatus_Starting) ) )
  {
    /* #40 [V2G20-5067], [V2G20-5057], [V2G20-2644] Trigger a SessionStopReq */
    *NextState = Scc_SMS_SessionStop;
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

    retVal = Scc_StateMachineState_Done;
  }
  /* #50 Check if a warning response code was received */
  else if (TRUE == Scc_ISO15118_20_StateM_IsResponseCodeWarning())
  {
    Exi_ISO_20_CT_10_responseCodeType responseCode = Scc_ISO15118_20_StateM_GetResponseCode(SCC_CHANNEL_DEFAULT);

    /* [V2G20-5057] Check if EVSEProcessing is Finished and ResponseCode is warning */
    if (   (Scc_EVSEProcessing_Finished == Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT))
        && (responseCode == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_WPT))
    {
      /* #60 Check if Application wants to restart FinePositioningSetup */
      if (chargingControl == Scc_ChargingControl_StartFinePositioningSetup)
      {
        /* #70 [V2G20-5057] Trigger a FinePositioningSetupReq */
        *NextState = Scc_SMS_FinePositioningSetup;
        /* reset the delay timer */
        Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

        retVal = Scc_StateMachineState_Done;
      }
      /* #80 Otherwise */
      else
      {
        /* #90 Application needs more time to process */
        retVal = Scc_StateMachineState_Pending;
      }
    }
    else
    {
      /* Report Det error */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_20WPT_STATEM_ALIGNMENT_CHECK, SCC_DET_INV_PARAM);
#endif
      * ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  /* #100 Check if EVSEProcessing is set to Ongoing */
  else if (Scc_EVSEProcessing_Ongoing == Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT))
  {
    Exi_ISO_20_CT_10_processingType EVProcessing = EXI_ISO_20_CT_10_PROCESSING_TYPE_ONGOING_WAITING_FOR_CUSTOMER_INTERACTION;
    Scc_ISO15118_20_StateM_Get_EVProcessing(&EVProcessing);

    /* #110 [V2G20-5036] Check if EVSEProcessing was set to 'Finished' in previously sent AlignmentCheckReq message  */
    if (EVProcessing == EXI_ISO_20_CT_10_PROCESSING_TYPE_FINISHED)
    {
      /* #120 [V2G20-5036] Continue with PowerDelivery */
      *NextState = Scc_SMS_PowerDelivery;
      retVal = Scc_StateMachineState_Done;
    }
    else
    {
      /* #130 [V2G20-5035] Loop AlignmentCheck */
      *NextState = Scc_SMS_AlignmentCheck;

      /* #140 Check if the delay counter is disabled */
      if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
      {
        /* #150 The next request can be sent now */
        retVal = Scc_StateMachineState_Done;
      }
      /* #160 Check if the delay counter is expired */
      else if ((Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE))
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
  }
  else
  {
    /* [V2G20-5036] Trigger PowerDeliveryReq */
    *NextState = Scc_SMS_PowerDelivery;
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************/
/* State Machine Callouts                                                                                             */
/**********************************************************************************************************************/
/***************************************************************************************
 * PairingReq, AlignmentCheckReq
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_StateM_Get_EVProcessing()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20WPT_StateM_Get_EVProcessing(
  P2VAR(Exi_ISO_20_CT_10_processingType, AUTOMATIC, SCC_APPL_DATA) EVProcessingPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Exi_ISO_20_CT_10_processingType evProcessing = EXI_ISO_20_CT_10_PROCESSING_TYPE_ONGOING_WAITING_FOR_CUSTOMER_INTERACTION;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the EVProcessing value from application */
  Scc_StateM_InterfaceCfg_Get_EVProcessing(&evProcessing);
  /* #20 Copy EVProcessing */
  *EVProcessingPtr = evProcessing;
  Scc_ISO15118_20_StateM_Set_EVProcessing(evProcessing);
}

/**********************************************************************************************************************/
/* ChargeLoop                                                                                                         */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_StateMWPT_ChargeLoop_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_ChargeLoop_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G20-5037],[V2G20-5039] Set ChargeLoop request and set ChargeLoopReq as cyclic message to true */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_ChargeLoop, TRUE);

  /* #20 [V2G20-1846], [V2G20-1661] Set ChargeLoopSent */
  Scc_ISO15118_20_StateM_SetChargeLoopSent();

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_StateMWPT_ChargeLoop_Wait
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_ChargeLoop_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_MsgStatusType msgStatus = Scc_MsgStatus_None;

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
    Exi_ISO_20_CT_10_responseCodeType responseCode = Scc_ISO15118_20_StateM_GetResponseCode(SCC_CHANNEL_DEFAULT);

    /* #60 [V2G20-5067] Check if response code was failed */
    if (responseCode >= EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED)
    {
      /* #70 Indicate received response and proceed with message processing */
      retVal = Scc_StateMachineState_Done;
    }
    /* #80 Otherwise */
    else
    {
      /* #90 Propagate stack error */
      *ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  /* #100 Otherwise wait for the response to be received */
  else
  {
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_StateMWPT_ChargeLoop_Process
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
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6030,6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_ChargeLoop_Process(
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

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Check if Failed response was received */
  if (Scc_StateM_GetMsgStatus() == Scc_MsgStatus_ChargeLoop_Failed)
  {
    /* #20 [V2G20-5067] Trigger a SessionStopReq */
    *NextState = Scc_SMS_SessionStop;
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

    retVal = Scc_StateMachineState_Done;
  }
  /* #30 Otherwise: MsgStatus OK */
  else
  {
    /* #40 Get current response code */
    Exi_ISO_20_CT_10_responseCodeType responseCode = Scc_ISO15118_20_StateM_GetResponseCode(SCC_CHANNEL_DEFAULT);
    /* #50 Fetch current charging control from application */
    Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);
    IsPauseEnabled = Scc_ISO15118_20_StateM_ActivatePause();

    /* #60 Check if response Code equals Warning_WPT */
    if (responseCode == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_WPT)
    {
      /* #70 [V2G20-5058] Check if ChargingControl equals StopCharging */
      if (chargingControl == Scc_ChargingControl_StopCharging)
      {
        /* #80 Trigger a SessionStopReq */
        *NextState = Scc_SMS_SessionStop;
        /* reset the delay timer */
        Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

        retVal = Scc_StateMachineState_Done;
      }
      /* #90 Otherwise: check if ChargingControl equals WPT_Pairing */
      else if (chargingControl == Scc_ChargingControl_WptPairing)
      {
        /* #100 [V2G20-5058] Trigger PairingReq */
        *NextState = Scc_SMS_Pairing;
        /* reset the delay timer */
        Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

        retVal = Scc_StateMachineState_Done;
      }
      /* #110 Otherwise: ChargingControl can not be resolved to a specific value */
      else
      {
        /* #120 [V2G20-5058] Trigger AlignmentCheck */
        *NextState = Scc_SMS_AlignmentCheck;
        /* reset the delay timer */
        Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

        retVal = Scc_StateMachineState_Done;
      }
    }
    /* #130 Otherwise: ResponseCode == OK */
    else
    {
      boolean serviceRenegotiationSupported = Scc_ISO15118_20_StateM_GetServiceRenegotiationSupported();
      boolean isEVSERequestingServiceReneg = Scc_ISO15118_20_StateM_IsEVSERequestingServiceReneg();
#if (defined(SCC_ENABLE_RENEGOTIATION_CHANNEL) && SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON)
      boolean IsRenegChannelStarted = Scc_ISO15118_20_StateMReneg_IsChannelStarted();
#endif /* SCC_ENABLE_RENEGOTIATION_CHANNEL */

      /* #140 [V2G20-5082],[V2G20-5129] Check if charging needs to be stopped or has to go to standby */
      /* #150 [V2G-5080] Ask the application also if chargingControl is ServiceRenegotion and ScheduleRenegotiation is not ongoing */
      if ( ( (chargingControl == Scc_ChargingControl_StopCharging)
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
        /* #160 [V2G20-434] Start the sequence performance timeout since previously the timer was started with ChargeLoop value */
        Scc_StateMachineTimer_Start(Scc_StateMachineTimer_SequencePerformance, Scc_ISO15118_20_TimerCfg_Get_SequencePerformanceTimeout());

        /* #170 Continue with PowerDeliveryReq */
        *NextState = Scc_SMS_PowerDelivery;
        retVal = Scc_StateMachineState_Done;
      }
      /* #180 [V2G20-1850] Check if EVSENotification set to Pause and NotificationMaxDelay set to 60s and ScheduleRenegotiation is not ongoing */
      else if ( (IsPauseEnabled == TRUE)
#if (defined(SCC_ENABLE_RENEGOTIATION_CHANNEL) && SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON)
             && (IsRenegChannelStarted == FALSE)
#endif /* SCC_ENABLE_RENEGOTIATION_CHANNEL */
              )
      {
        /* reset the delay timer */
        Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
        /* #190 Continue with PowerDeliveryReq */
        *NextState = Scc_SMS_PowerDelivery;
        retVal = Scc_StateMachineState_Done;
      }
      /* #200 Otherwise */
      else
      {
        /* #210 [V2G20-5039] Continue with next ChargeLoopReq */
        *NextState = Scc_SMS_ChargeLoop;

        /* #220 Check if the delay counter is disabled */
        if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
        {
          /* #230 The next request can be sent now */
          retVal = Scc_StateMachineState_Done;
        }
        /* #240 Check if the delay counter is expired */
        else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
        {
          /* #250 The next request can be sent now */
          retVal = Scc_StateMachineState_Done;
        }
        else
        {
          /* #260 Otherwise the next request shall be delayed further */
          retVal = Scc_StateMachineState_Pending;
        }
      }

      /* #270 [V2G20-1845] If renegotiation channel is enabled, Check if EVSE requested a ScheduleReneg */
#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
      if ( (Scc_ISO15118_20_StateM_IsEVSERequestingScheduleReneg() == TRUE)
        && (retVal == Scc_StateMachineState_Done))
      {
        /* #280 Set flag that ScheduleReneg is requested */
        Scc_ISO15118_20_StateMReneg_SetRequestScheduleReneg(TRUE);
      }
#endif

      /* #290 [V2G20-1084], [V2G20-2704] If metering channel is enabled, Check if EVSE requested a MeteringConfirmation */
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
      paymentOption = Scc_ISO15118_20_StateM_GetChosenAuthorizationService();
      if ( (Scc_ISO15118_20_StateM_IsEVSERequestingMeteringConfirmation() == TRUE)
        && (retVal == Scc_StateMachineState_Done)
        && (paymentOption == Scc_PaymentOption_PnC))
      {
        /* #300 Check if channel is already activated */
        if (Scc_ISO15118_20_StateMMeter_IsChannelStarted() == FALSE)
        {
          /* #310 Set flag that Metering is requested */
          Scc_ISO15118_20_StateMMeter_SetChannelStarted(TRUE);
        }
        /* Otherwise */
        else
        {
          /* #320 Check if MeteringConfirmationReq was not yet sent */
          if (Scc_ISO15118_20_StateMMeter_IsMeteringReqSent() == FALSE)
          {
            /* #330 [V2G20-2105] Propagate stack error */
            /* In case the channel was already activated but the MeteringConfirmationReq was not yet sent then propogate error */
            *ErrorInformation = Scc_SMER_ChargeLoop_InvalidMeteringRequested;
            retVal = Scc_StateMachineState_Failed;
          }
        }
      }
#endif
    }
  }
  return retVal;
}

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE && SCC_SCHEMA_ISO_20WPT */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20WPT_StateM.c
 *********************************************************************************************************************/
