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
/*!        \file  Scc_ISO15118_20DC_ExiRx.c
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

#define SCC_ISO15118_20DC_EXIRX_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
#include "Scc_ISO15118_20DC_Exi.h"
#include "Scc_ISO15118_20_Exi.h"
#include "Scc_Core_Channel.h"
#include "Scc_ExiRx_Common.h"
#include "Scc_Priv.h"
#include "Scc_ISO15118_20_InterfaceCfg.h"

#if ( SCC_DEV_ERROR_DETECT == STD_ON )
# include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */

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
 *  Scc_ISO15118_20DC_ExiRx_<ISO15118-20-Response>
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
/* see pattern Scc_ISO15118_20DC_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiRx_DC_ChargeParameterDiscoveryRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
/* see pattern Scc_ISO15118_20DC_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiRx_DC_CableCheckRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
/* see pattern Scc_ISO15118_20DC_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiRx_DC_PreChargeRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
/* see pattern Scc_ISO15118_20DC_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiRx_DC_ChargeLoopRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
/* see pattern Scc_ISO15118_20DC_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiRx_DC_WeldingDetectionRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_ExiRx_DecodeMessagePrepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20DC_ExiRx_DecodeMessagePrepare(
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Start exi decoding */
  return Scc_ExiRx_Common_DecodeMessagePrepare(EXI_SCHEMA_SET_ISO_20_DC_10_TYPE, NULL_PTR, RxMsgWSPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_ExiRx_DecodeMessage
 *********************************************************************************************************************/
 /*!
  *
  * Internal comment removed.
 *
 *
  */
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20DC_ExiRx_DecodeMessage(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Handle an incoming response message */
  switch (Scc_Core_Channel_Get_MsgTrig())
  {
    /* handle an incoming charge parameter discovery response message */
  case Scc_MsgTrig_ChargeParameterDiscovery:
    /* try to process the message and check if it was successful */
    if ((Std_ReturnType)E_OK == Scc_ISO15118_20DC_ExiRx_DC_ChargeParameterDiscoveryRes(RxMsgWSPtr))
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_ChargeParameterDiscovery_OK);
      retVal = Scc_ReturnType_OK;
    }
    break;
    /* handle an incoming charge loop response message */
  case Scc_MsgTrig_CableCheck:
    /* try to process the message and check if it was successful */
    if ((Std_ReturnType)E_OK == Scc_ISO15118_20DC_ExiRx_DC_CableCheckRes(RxMsgWSPtr))
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_CableCheck_OK);
      retVal = Scc_ReturnType_OK;
    }
    break;

    /* handle an incoming charge loop response message */
  case Scc_MsgTrig_ChargeLoop:
    /* try to process the message and check if it was successful */
    if ((Std_ReturnType)E_OK == Scc_ISO15118_20DC_ExiRx_DC_ChargeLoopRes(RxMsgWSPtr))
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_ChargeLoop_OK);
      retVal = Scc_ReturnType_OK;
    }
    break;

  case Scc_MsgTrig_PreCharge:
    /* try to process the message and check if it was successful */
    if ((Std_ReturnType)E_OK == Scc_ISO15118_20DC_ExiRx_DC_PreChargeRes(RxMsgWSPtr))
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_PreCharge_OK);
      retVal = Scc_ReturnType_OK;
    }
    break;

    /* handle an incoming charge loop response message */
  case Scc_MsgTrig_WeldingDetection:
    /* try to process the message and check if it was successful */
    if ((Std_ReturnType)E_OK == Scc_ISO15118_20DC_ExiRx_DC_WeldingDetectionRes(RxMsgWSPtr))
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_WeldingDetection_OK);
      retVal = Scc_ReturnType_OK;
    }
    break;

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
 *  Scc_ISO15118_20DC_ExiRx_DC_ChargeParameterDiscoveryRes
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
   */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiRx_DC_ChargeParameterDiscoveryRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)                                                  /* PRQA S 3673 */ /* MD_SCC_CORE_GENERIC_INTERFACE */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_DC_10_DC_CHARGE_PARAMETER_DISCOVERY_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_ChargeParameterDiscoveryResMessageOutOfSequence);
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
    P2CONST(Exi_ISO_20_DC_10_DC_ChargeParameterDiscoveryResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_DC_10_DC_ChargeParameterDiscoveryResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-2543], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-735] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20_ChargeParameterDiscoveryResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
    /* #50 [V2G20-734], [V2G20-2201] Otherwise */
    else
    {
      /* #60 [V2G20-1207] Report the parameter from the response to the application. */

      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

      /* #70 Propagate energy transfer mode element based on received element */
      retVal = E_OK;
      switch (msgPtr->DC_CPDResEnergyTransferModeElementId)
      {
        /* #80 [V2G20-1349] If DC mode: Propagate DC_CPDResEnergyTransferModeType */
        case EXI_ISO_20_DC_10_DC_CPDRES_ENERGY_TRANSFER_MODE_TYPE:
          Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_CPDResEnergyTransferMode(msgPtr->DC_CPDResEnergyTransferMode);
          break;
#if (defined SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON)
        /* #90 [V2G20-1459],[V2G20-2650] If BPT enabled: If DC_BPT mode: Propagate BPT_DC_CPDResEnergyTransferModeType */
        case EXI_ISO_20_DC_10_BPT_DC_CPDRES_ENERGY_TRANSFER_MODE_TYPE:
          Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_BPT_DC_CPDResEnergyTransferMode(
            (P2CONST(Exi_ISO_20_DC_10_BPT_DC_CPDResEnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA))msgPtr->DC_CPDResEnergyTransferMode); /* PRQA S 0310 */ /* MD_Scc_0310_0314_0316_3305 */
          break;
#endif /* SCC_CHARGING_BPT */

        /* #100 Otherwise */
        default:
          /* #110 Propagate error for unsupported element id */
          Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20DC_ChargeParameterDiscoveryResUnsupportedEnergyModeElementId);
          retVal = E_NOT_OK;
          break;
      }

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_ExiRx_DC_CableCheckRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiRx_DC_CableCheckRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
/* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_DC_10_DC_CABLE_CHECK_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_CableCheckResMessageOutOfSequence);
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
    P2CONST(Exi_ISO_20_DC_10_DC_CableCheckResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_DC_10_DC_CableCheckResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-2543], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-735] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20_CableCheckResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
    /* #50 [V2G20-734], [V2G20-2201] Otherwise */
    else
    {
      /* #60 [2G20-1280] Report the parameter from the response to the application. */

      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

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
 *  Scc_ISO15118_20DC_ExiRx_DC_PreChargeRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiRx_DC_PreChargeRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Scc_PhysicalValueType scc_PhysicalValueTmp;

  /* ----- Implementation ----------------------------------------------- */
/* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_DC_10_DC_PRE_CHARGE_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_PreChargeResMessageOutOfSequence);
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
    P2CONST(Exi_ISO_20_DC_10_DC_PreChargeResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_DC_10_DC_PreChargeResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-2543], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-735] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20_PreChargeResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
    /* #50 [V2G20-734], [V2G20-2201] Otherwise */
    else
    {
      /* #60 [V2G20-1282] Report the parameter from the response to the application. */

      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

      /* PresentVoltage */
      Scc_Conv_ISO20ToScc_PhysicalValue(msgPtr->EVSEPresentVoltage, &scc_PhysicalValueTmp);
      Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEPresentVoltage(&scc_PhysicalValueTmp);

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_ExiRx_DC_ChargeLoopRes
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
/* PRQA S 6050,6080 1 */ /* MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiRx_DC_ChargeLoopRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Scc_PhysicalValueType scc_PhysicalValueTmp;

  /* ----- Implementation ----------------------------------------------- */
/* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_DC_10_DC_CHARGE_LOOP_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20DC_ChargeLoopResMessageOutOfSequence);
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
    P2CONST(Exi_ISO_20_DC_10_DC_ChargeLoopResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_DC_10_DC_ChargeLoopResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-2543], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-735] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20DC_ChargeLoopResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
    /* #50 [V2G20-734], [V2G20-2201] Otherwise */
    else
    {
      /* #60 [V2G20-1284] Report the parameter from the response to the application. */
      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

      /* EVSEStatus */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEStatus(msgPtr->EVSEStatus, msgPtr->EVSEStatusFlag);

      /* MeterInfo */
      Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_MeterInfo(msgPtr->MeterInfo, msgPtr->MeterInfoFlag);

      /* Receipt */
      Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_Receipt(msgPtr->Receipt, msgPtr->ReceiptFlag);

      /* EVSEPresentCurrent */
      Scc_Conv_ISO20ToScc_PhysicalValue(msgPtr->EVSEPresentCurrent, &scc_PhysicalValueTmp);
      Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEPresentCurrent(&scc_PhysicalValueTmp);

      /* EVSEPresentVoltage */
      Scc_Conv_ISO20ToScc_PhysicalValue(msgPtr->EVSEPresentVoltage, &scc_PhysicalValueTmp);
      Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEPresentVoltage(&scc_PhysicalValueTmp);

      /* EVSEPowerLimitAchieved */
      Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEPowerLimitAchieved(msgPtr->EVSEPowerLimitAchieved);

      /* EVSECurrentLimitAchieved */
      Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSECurrentLimitAchieved(msgPtr->EVSECurrentLimitAchieved);

      /* EVSEVoltageLimitAchieved */
      Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEVoltageLimitAchieved(msgPtr->EVSEVoltageLimitAchieved);

      /* #70 Propagate control mode element based on received element */
      retVal = E_OK;
      switch (msgPtr->CLResControlModeElementId)
      {
        /* #80 If DC scheduled mode: Propagte Scheduled_DC_CLResControlMode */
        case EXI_ISO_20_DC_10_SCHEDULED_DC_CLRES_CONTROL_MODE_TYPE:
          Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_Scheduled_DC_CLResControlMode(
            (P2CONST(Exi_ISO_20_DC_10_Scheduled_DC_CLResControlModeType, AUTOMATIC, SCC_APPL_DATA))msgPtr->CLResControlMode); /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          break;
#if (defined SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON)
        /* #90 [V2G20-1771],[V2G20-2650] If BPT enabled: If DC_BPT scheduled mode: Propagte BPT_Scheduled_DC_CLResControlMode */
        case EXI_ISO_20_DC_10_BPT_SCHEDULED_DC_CLRES_CONTROL_MODE_TYPE:
          Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_BPT_Scheduled_DC_CLResControlMode(
            (P2CONST(Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLResControlModeType, AUTOMATIC, SCC_APPL_DATA))msgPtr->CLResControlMode); /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          break;
#endif /* SCC_CHARGING_BPT */
        /* #100 [V2G20-1763] If DC dynamic mode: Propagte Dynamic_DC_CLResControlMode */
        case EXI_ISO_20_DC_10_DYNAMIC_DC_CLRES_CONTROL_MODE_TYPE:
          Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_Dynamic_DC_CLResControlMode(
            (P2CONST(Exi_ISO_20_DC_10_Dynamic_DC_CLResControlModeType, AUTOMATIC, SCC_APPL_DATA))msgPtr->CLResControlMode); /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          break;
#if (defined SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON)
        /* #110  [V2G20-1773],[V2G20-2650] If BPT enabled: If DC_BPT dynamic mode: Propagte BPT_Dynamic_DC_CLResControlMode */
        case EXI_ISO_20_DC_10_BPT_DYNAMIC_DC_CLRES_CONTROL_MODE_TYPE:
          Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_BPT_Dynamic_DC_CLResControlMode(
            (P2CONST(Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLResControlModeType, AUTOMATIC, SCC_APPL_DATA))msgPtr->CLResControlMode); /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          break;
#endif /* SCC_CHARGING_BPT */
        /* #120 Otherwise */
        default:
          /* #130 Propagate error for unsupported element id */
          Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20DC_ChargeLoopResUnsupporteControlModedElementId);
          retVal = E_NOT_OK;
          break;
      }

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_ExiRx_DC_WeldingDetectionRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiRx_DC_WeldingDetectionRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Scc_PhysicalValueType scc_PhysicalValueTmp;

  /* ----- Implementation ----------------------------------------------- */
/* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_DC_10_DC_WELDING_DETECTION_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_WeldingDetectionResMessageOutOfSequence);
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
    P2CONST(Exi_ISO_20_DC_10_DC_WeldingDetectionResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_DC_10_DC_WeldingDetectionResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-2543], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-735] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20_WeldingDetectionResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
    /* #50 [V2G20-734], [V2G20-2201] Otherwise */
    else
    {
      /* #60 [V2G20-1286] Report the parameter from the response to the application. */
      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

      /* EVSEPresentVoltage */
      Scc_Conv_ISO20ToScc_PhysicalValue(msgPtr->EVSEPresentVoltage, &scc_PhysicalValueTmp);
      Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEPresentVoltage(&scc_PhysicalValueTmp);

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}
#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SCHEMA_ISO_20DC */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20DC_ExiRx.c
 *********************************************************************************************************************/
