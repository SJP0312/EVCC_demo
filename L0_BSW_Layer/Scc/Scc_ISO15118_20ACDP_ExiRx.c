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
/*!        \file  Scc_ISO15118_20ACDP_ExiRx.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to the specifications ISO/IEC 15118-20.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_ISO15118_20ACDP_EXIRX_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
#include "Scc_ISO15118_20ACDP_Exi.h"
#include "Scc_ISO15118_20_Exi.h"
#include "Scc_Core_Channel.h"
#include "Scc_ExiRx_Common.h"
#include "Scc_Priv.h"
#include "Scc_ISO15118_20_InterfaceCfg.h"

#if (SCC_IDSM_REPORT == STD_ON)
# include "IdsM.h"
#endif

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
 *  LOCAL / GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_ExiRx_<ISO15118-20-Response>
 *********************************************************************************************************************/
/*! \brief          Get all parameters of ISO-20 response message
 *  \details        Validates parameter and reports them to the application.
 *  \param[in]      RxMsgWSPtr          Pointer to the Rx message workspace
 *  \return         OK                  Processing data successful
 *  \return         NotOK               Processing data not successful
 *  \return         Pending             More time required to process data. Try again later
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
/* see pattern Scc_ISO15118_20ACDP_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_ExiRx_ACDP_VehiclePositioningRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
/* see pattern Scc_ISO15118_20ACDP_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_ExiRx_ACDP_ConnectRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
/* see pattern Scc_ISO15118_20ACDP_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_ExiRx_ACDP_DisconnectRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
#if ( (defined SCC_ENABLE_ACDP_SYSTEM_STATUS) && (SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON) )
/* see pattern Scc_ISO15118_20ACDP_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_ExiRx_ACDP_SystemStatusRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
#endif /* SCC_ENABLE_ACDP_SYSTEM_STATUS */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_ExiRx_DecodeMessagePrepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20ACDP_ExiRx_DecodeMessagePrepare(
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Start exi decoding */
  return Scc_ExiRx_Common_DecodeMessagePrepare(EXI_SCHEMA_SET_ISO_20_ACDP_10_TYPE, NULL_PTR, RxMsgWSPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_ExiRx_DecodeMessage
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20ACDP_ExiRx_DecodeMessage(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Handle an incoming response message */
  switch (Scc_Core_Channel_Get_MsgTrig())
  {
    /* handle an incoming ACDP VehiclePositioning response message */
  case Scc_MsgTrig_ACDP_VehiclePositioning:
    /* try to process the message and check if it was successful */
    if (E_OK == Scc_ISO15118_20ACDP_ExiRx_ACDP_VehiclePositioningRes(RxMsgWSPtr))
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_ACDP_VehiclePositioning_OK);
      retVal = Scc_ReturnType_OK;
    }
    break;
    /* handle an incoming ACDP connect response message */
  case Scc_MsgTrig_ACDP_Connect:
    /* try to process the message and check if it was successful */
    if (E_OK == Scc_ISO15118_20ACDP_ExiRx_ACDP_ConnectRes(RxMsgWSPtr))
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_ACDP_Connect_OK);
      retVal = Scc_ReturnType_OK;
    }
    break;
    /* handle an incoming ACDP disconnect response message */
  case Scc_MsgTrig_ACDP_Disconnect:
    /* try to process the message and check if it was successful */
    if (E_OK == Scc_ISO15118_20ACDP_ExiRx_ACDP_DisconnectRes(RxMsgWSPtr))
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_ACDP_Disconnect_OK);
      retVal = Scc_ReturnType_OK;
    }
    break;
#if ( (defined SCC_ENABLE_ACDP_SYSTEM_STATUS) && (SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON) )
  case Scc_MsgTrig_ACDP_SystemStatus:
    /* try to process the message and check if it was successful */
    if (E_OK == Scc_ISO15118_20ACDP_ExiRx_ACDP_SystemStatusRes(RxMsgWSPtr))
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_ACDP_SystemStatus_OK);
      retVal = Scc_ReturnType_OK;
    }
    break;
#endif /* SCC_ENABLE_ACDP_SYSTEM_STATUS */
  default:
    /* Not implemented yet - Dummy */
    break;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_ExiRx_ACDP_VehiclePositioningRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_ExiRx_ACDP_VehiclePositioningRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_ACDP_10_ACDP_VEHICLE_POSITIONING_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_ACDP_VehiclePositioningResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #20 Otherwise */
  else
  {
    P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                      Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
    /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-2543], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-735] Check if the response is negative */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20_ACDP_VehiclePositioningResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
    /* #50 [V2G20-734] Otherwise */
    else
    {
      /* #60 [V2G20-4005] Report the parameter from the response to the application. */
      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

      /* EVSEPositioningSupport */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiRx_Set_EVSEPositioningSupport(msgPtr->EVSEPositioningSupport);

      /* EVRelativeXDeviation */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiRx_Set_EVRelativeXDeviation(msgPtr->EVRelativeXDeviation);

      /* EVRelativeYDeviation */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiRx_Set_EVRelativeYDeviation(msgPtr->EVRelativeYDeviation);

      /* ContactWindowXc */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiRx_Set_ContactWindowXc(msgPtr->ContactWindowXc);

      /* ContactWindowYc */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiRx_Set_ContactWindowYc(msgPtr->ContactWindowYc);

      /* EVInChargePosition */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiRx_Set_EVInChargePosition(msgPtr->EVInChargePosition);

      /* EVSEProcessing */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEProcessing(msgPtr->EVSEProcessing);

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_ExiRx_ACDP_ConnectRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_ExiRx_ACDP_ConnectRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if (RxMsgWSPtr->RootElementId != EXI_ISO_20_ACDP_10_ACDP_CONNECT_RES_TYPE)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_ACDP_ConnectResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #20 Otherwise */
  else
  {
    P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                      Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
    /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_20_ACDP_10_ACDP_ConnectResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_ACDP_10_ACDP_ConnectResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-2543], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-735] Check if the response is negative. */
    else if (msgPtr->ResponseCode >= EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED)
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20_ACDP_ConnectResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
    /* #50 [V2G20-734] Otherwise */
    else
    {
      /* #60 [V2G20-4007] Report the parameter from the response to the application. */
      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

      /* EVSEElectricalChargingDeviceStatus */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiRx_Set_EVSEElectricalChargingDeviceStatus(msgPtr->EVSEElectricalChargingDeviceStatus);

      /* EVSEMechanicalChargingDeviceStatus */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiRx_Set_EVSEMechanicalChargingDeviceStatus(msgPtr->EVSEMechanicalChargingDeviceStatus);

      /* EVSEProcessing */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEProcessing(msgPtr->EVSEProcessing);

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_ExiRx_ACDP_DisconnectRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_ExiRx_ACDP_DisconnectRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
/* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_ACDP_10_ACDP_DISCONNECT_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_ACDP_DisconnectResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #20 Otherwise */
  else
  {
    P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                      Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
    /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_20_ACDP_10_ACDP_ConnectResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_ACDP_10_ACDP_ConnectResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-2543], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-735] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20_ACDP_DisconnectResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
    /* #50 [V2G20-734] Otherwise */
    else
    {
      /* #60 [V2G20-4009] Report the parameter from the response to the application. */
      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

      /* EVSEElectricalChargingDeviceStatus */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiRx_Set_EVSEElectricalChargingDeviceStatus(msgPtr->EVSEElectricalChargingDeviceStatus);

      /* EVSEMechanicalChargingDeviceStatus */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiRx_Set_EVSEMechanicalChargingDeviceStatus(msgPtr->EVSEMechanicalChargingDeviceStatus);

      /* EVSEProcessing */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEProcessing(msgPtr->EVSEProcessing);

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

#if ( (defined SCC_ENABLE_ACDP_SYSTEM_STATUS) && (SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON) )
/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_ExiRx_ACDP_SystemStatusRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_ExiRx_ACDP_SystemStatusRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_ACDP_10_ACDP_SYSTEM_STATUS_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_ACDP_SystemStatusResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #20 Otherwise */
  else
  {
    P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                      Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
    /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_20_ACDP_10_ACDP_SystemStatusResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_ACDP_10_ACDP_SystemStatusResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-2543], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-4015] Check if the response is negative. */
    else if (msgPtr->ResponseCode >= EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED)
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20_ACDP_SystemStatusResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
    /* #50 [V2G20-734], [V2G20-4014] Otherwise */
    else
    {
      /* #60 [V2G20-4012] Report the parameter from the response to the application. */
      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

      /* EVSEMechanicalChargingDeviceStatus  */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiRx_Set_EVSEMechanicalChargingDeviceStatus(msgPtr->EVSEMechanicalChargingDeviceStatus);

      /* EVSEReadyToCharge */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiRx_Set_EVSEReadyToCharge(msgPtr->EVSEReadyToCharge);

      /* EVSEIsolationStatus */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiRx_Set_EVSEIsolationStatus(msgPtr->EVSEIsolationStatus);

      /* EVSEDisabled */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiRx_Set_EVSEDisabled(msgPtr->EVSEDisabled);

      /* EVSEUtilityInterruptEvent */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiRx_Set_EVSEUtilityInterruptEvent(msgPtr->EVSEUtilityInterruptEvent);

      /* EVSEEmergencyShutdown */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiRx_Set_EVSEEmergencyShutdown(msgPtr->EVSEEmergencyShutdown);

      /* EVSEMalfunction */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiRx_Set_EVSEMalfunction(msgPtr->EVSEMalfunction);

      /* EVInChargePosition */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiRx_Set_EVInChargePosition(msgPtr->EVInChargePosition);

      /* EVAssociationStatus */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiRx_Set_EVAssociationStatus(msgPtr->EVAssociationStatus);

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_ACDP_SYSTEM_STATUS */

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SCHEMA_ISO_20ACDP */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20ACDP_ExiRx.c
 *********************************************************************************************************************/
