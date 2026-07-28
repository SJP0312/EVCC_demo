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
/*!        \file  Scc_ISO15118_20WPT_ExiRx.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to ISO15118-20 SPEC for WPT schema specific parts.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_ISO15118_20WPT_EXIRX_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
 /*lint -e546 */ /* Suppress the 'Suspicious use of &' warning because the '&' is required by MISRA per Id 1502. */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
#include "Scc_ISO15118_20WPT_Exi.h"
#include "Scc_Core_Channel.h"
#include "Scc_ExiRx_Common.h"
#include "Scc_Priv.h"
#include "Scc_Core_InterfaceCfg.h"
#include "Scc_ISO15118_20_InterfaceCfg.h"
#include "Scc_ISO15118_20_Exi.h"

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
 *  Scc_ISO15118_20WPT_ExiRx_<ISO15118-20-Response>
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
/* see pattern Scc_ISO15118_20WPT_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiRx_WPT_FinePositioningSetupRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
/* see pattern Scc_ISO15118_20WPT_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiRx_WPT_FinePositioningRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
/* see pattern Scc_ISO15118_20WPT_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiRx_WPT_PairingRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
/* see pattern Scc_ISO15118_20WPT_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiRx_WPT_ChargeParameterDiscoveryRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
/* see pattern Scc_ISO15118_20WPT_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiRx_WPT_AlignmentCheckRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
/* see pattern Scc_ISO15118_20WPT_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiRx_WPT_ChargeLoopRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_ExiRx_DecodeMessagePrepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20WPT_ExiRx_DecodeMessagePrepare(
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Start exi decoding */
  return Scc_ExiRx_Common_DecodeMessagePrepare(EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, NULL_PTR, RxMsgWSPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_ExiRx_DecodeMessage
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
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20WPT_ExiRx_DecodeMessage(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Handle an incoming response message */
  switch (Scc_Core_Channel_Get_MsgTrig())
  {
    /* #20 Handle an incoming FinePositioningSetup response message */
  case Scc_MsgTrig_FinePositioningSetup:
  {
    /* try to process the message and check if it was successful */
    Scc_ReturnType funcRetVal = Scc_ISO15118_20WPT_ExiRx_WPT_FinePositioningSetupRes(RxMsgWSPtr);
    if (funcRetVal == Scc_ReturnType_OK)
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_FinePositioningSetup_OK);
      Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
      retVal = Scc_ReturnType_OK;
    }
    /* If pending then set status to failed but retVal to ok to send SessionStopReq */
    else if (funcRetVal == Scc_ReturnType_Pending)
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_FinePositioningSetup_Failed);
      Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
      retVal = Scc_ReturnType_OK;
    }
    /* Otherwise set error */
    else
    {
      /* retVal is already set to not ok */
    }
  }
    break;

    /* #30 Handle an incoming FinePositioning response message */
  case Scc_MsgTrig_FinePositioning:
  {
    /* try to process the message and check if it was successful */
    Scc_ReturnType funcRetVal = Scc_ISO15118_20WPT_ExiRx_WPT_FinePositioningRes(RxMsgWSPtr);
    if (funcRetVal == Scc_ReturnType_OK)
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_FinePositioning_OK);
      Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
      retVal = Scc_ReturnType_OK;
    }
    /* If pending then set status to failed but retVal to ok to send SessionStopReq */
    else if (funcRetVal == Scc_ReturnType_Pending)
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_FinePositioning_Failed);
      Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
      retVal = Scc_ReturnType_OK;
    }
    /* Otherwise set error */
    else
    {
      /* retVal is already set to not ok */
    }
  }
    break;

    /* #40 Handle an incoming Pairing response message */
  case Scc_MsgTrig_Pairing:
  {
    /* try to process the message and check if it was successful */
    Scc_ReturnType funcRetVal = Scc_ISO15118_20WPT_ExiRx_WPT_PairingRes(RxMsgWSPtr);
    if (funcRetVal == Scc_ReturnType_OK)
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_Pairing_OK);
      Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
      retVal = Scc_ReturnType_OK;
    }
    else if (funcRetVal == Scc_ReturnType_Pending)
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_Pairing_Failed);
      Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
      retVal = Scc_ReturnType_OK;
    }
    else
    {
      /* retVal already set to Scc_ReturnType_NotOK */
    }
  }
    break;

    /* #50 Handle an incoming ChargeParameterDiscovery response message */
  case Scc_MsgTrig_ChargeParameterDiscovery:
  {
    /* try to process the message and check if it was successful */
    if (Scc_ISO15118_20WPT_ExiRx_WPT_ChargeParameterDiscoveryRes(RxMsgWSPtr) == E_OK)
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_ChargeParameterDiscovery_OK);
      retVal = Scc_ReturnType_OK;
    }
    /* Otherwise set error */
    else
    {
      /* retVal is already set to not ok */
    }
  }
    break;

    /* #60 Handle an incoming AlignmentCheck response message */
  case Scc_MsgTrig_AlignmentCheck:
  {
    /* try to process the message and check if it was successful */
    Scc_ReturnType funcRetVal = Scc_ISO15118_20WPT_ExiRx_WPT_AlignmentCheckRes(RxMsgWSPtr);
    if (funcRetVal == Scc_ReturnType_OK)
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_AlignmentCheck_OK);
      Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
      retVal = Scc_ReturnType_OK;
    }
    /* If pending then set status to failed but retVal to ok to send SessionStopReq */
    else if (funcRetVal == Scc_ReturnType_Pending)
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_AlignmentCheck_Failed);
      Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
      retVal = Scc_ReturnType_OK;
    }
    /* Otherwise set error */
    else
    {
      /* retVal is already set to not ok */
    }
  }
    break;

    /* #70 Handle an incoming ChargeLoop response message */
  case Scc_MsgTrig_ChargeLoop:
  {
    /* try to process the message and check if it was successful */
    Scc_ReturnType funcRetVal = Scc_ISO15118_20WPT_ExiRx_WPT_ChargeLoopRes(RxMsgWSPtr);
    if (funcRetVal == Scc_ReturnType_OK)
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_ChargeLoop_OK);
      Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
      retVal = Scc_ReturnType_OK;
    }
    /* If pending then set status to failed but retVal to ok to send SessionStopReq */
    else if (funcRetVal == Scc_ReturnType_Pending)
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_ChargeLoop_Failed);
      Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
      retVal = Scc_ReturnType_OK;
    }
    /* Otherwise set error */
    else
    {
      /* retVal is already set to not ok */
    }
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
 *  Scc_ISO15118_20WPT_ExiRx_WPT_FinePositioningSetupRes
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
   */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiRx_WPT_FinePositioningSetupRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)                                                  /* PRQA S 3673 */ /* MD_SCC_CORE_GENERIC_INTERFACE */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_SETUP_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_FinePositioningSetupResMessageOutOfSequence);
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
    P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-2543], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-5067] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = Scc_ReturnType_Pending;
    }
    /* #50 [V2G20-734], [V2G20-2201] Otherwise */
    else
    {
      /* #60 [2G20-5010] Report the parameter from the response to the application. */

      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

      /* PrimaryDeviceFinePositioningMethodList */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_PrimaryDeviceFinePositioningMethodList(msgPtr->PrimaryDeviceFinePositioningMethodList);

      /* PrimaryDevicePairingMethodList */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_PrimaryDevicePairingMethodList(msgPtr->PrimaryDevicePairingMethodList);

      /* PrimaryDeviceAlignmentCheckMethodList */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_PrimaryDeviceAlignmentCheckMethodList(msgPtr->PrimaryDeviceAlignmentCheckMethodList);

      /* NaturalOffset */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_NaturalOffsetRx(msgPtr->NaturalOffset);

      /* VendorSpecificDataContainer */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_VendorSpecificDataContainerRx(msgPtr->VendorSpecificDataContainer, msgPtr->VendorSpecificDataContainerFlag);

      /* LF_SystemSetupData */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_LF_SystemSetupDataRx(msgPtr->LF_SystemSetupData, msgPtr->LF_SystemSetupDataFlag);

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = Scc_ReturnType_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_ExiRx_WPT_FinePositioningRes
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
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiRx_WPT_FinePositioningRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)                                                  /* PRQA S 3673 */ /* MD_SCC_CORE_GENERIC_INTERFACE */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_FinePositioningResMessageOutOfSequence);
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
    P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-2543], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-5067] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = Scc_ReturnType_Pending;
    }
    /* #50 [V2G20-734], [V2G20-2201] Otherwise */
    else
    {
      /* #60 [V2G20-5013] Report the parameter from the response to the application. */

      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

      /* EVSEProcessing */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEProcessing(msgPtr->EVSEProcessing);

      /* VendorSpecificDataContainer */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_VendorSpecificDataContainerRx(msgPtr->VendorSpecificDataContainer, msgPtr->VendorSpecificDataContainerFlag);

      /* WPT_LF_DataPackageList */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_WPT_LF_DataPackageListRx(msgPtr->WPT_LF_DataPackageList, msgPtr->WPT_LF_DataPackageListFlag);

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = Scc_ReturnType_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_ExiRx_WPT_PairingRes
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
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiRx_WPT_PairingRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)                                                  /* PRQA S 3673 */ /* MD_SCC_CORE_GENERIC_INTERFACE */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_WPT_10_WPT_PAIRING_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    /* #20 Report Error */
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_PairingResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #30 Otherwise */
  else
  {
    P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                      Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
    /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_20_WPT_10_WPT_PairingResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_WPT_10_WPT_PairingResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #40 [V2G20-2543], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing - retVal already set to E_NOT_OK and Scc_ReportError is invoked by Scc_ISO15118_20_ExiRx_CheckSessionId */
    }
    /* #50 [V2G20-5067] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* #60 Report the response code to the application. */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      /* #70 Set retVal to pending to enforce MsgStatus to be set to Scc_MsgStatus_Pairing_Failed */
      retVal = Scc_ReturnType_Pending;
    }
    /* #80 [V2G20-734], [V2G20-2201] Otherwise */
    else
    {
      /* #90 [V2G20-5101] Report the parameter values from the response to the application. */

      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

      /* EVSEProcessing */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEProcessing(msgPtr->EVSEProcessing);

      /* ObservedIDCode */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_ObservedIDCodeRx(msgPtr->ObservedIDCode, msgPtr->ObservedIDCodeFlag);

      /* AlternativeSECCList */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_AlternativeSECCList(msgPtr->AlternativeSECCList, msgPtr->AlternativeSECCListFlag);

      /* VendorSpecificDataContainer */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_VendorSpecificDataContainerRx(msgPtr->VendorSpecificDataContainer, msgPtr->VendorSpecificDataContainerFlag);

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = Scc_ReturnType_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_ExiRx_WPT_ChargeParameterDiscoveryRes
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
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiRx_WPT_ChargeParameterDiscoveryRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)                                                  /* PRQA S 3673 */ /* MD_SCC_CORE_GENERIC_INTERFACE */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_WPT_10_WPT_CHARGE_PARAMETER_DISCOVERY_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_WptChargeParameterDiscoveryResMessageOutOfSequence);
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
    P2CONST(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-2543], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-735] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20_WptChargeParameterDiscoveryResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
    /* #50 [V2G20-734], [V2G20-2201] Otherwise */
    else
    {
      /* #60 [V2G20-5127] Report the parameter from the response to the application. */

      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

      /* PDMaxCoilCurrent */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_PDMaxCoilCurrent(msgPtr->PDMaxCoilCurrent);

      /* PDMinCoilCurrent */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_PDMinCoilCurrent(msgPtr->PDMinCoilCurrent);

      /* SDMaxOutputPower */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_SDMaxOutputPower(msgPtr->SDMaxOutputPower);

      /* SDMinOutputPower */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_SDMinOutputPower(msgPtr->SDMinOutputPower);

      /* SDMaxGroundClearanceSupport */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_SDMaxGroundClearanceSupport(msgPtr->SDMaxGroundClearanceSupport);

      /* SDMinGroundClearanceSupport */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_SDMinGroundClearanceSupport(msgPtr->SDMinGroundClearanceSupport);

      /* SDManufacturerSpecificDataContainer */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_VendorSpecificDataContainerRx(msgPtr->SDManufacturerSpecificDataContainer, msgPtr->SDManufacturerSpecificDataContainerFlag);

      /* PDInputPowerClass */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_PDInputPowerClass(msgPtr->PDInputPowerClass);

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_ExiRx_WPT_AlignmentCheckRes
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
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiRx_WPT_AlignmentCheckRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)                                                  /* PRQA S 3673 */ /* MD_SCC_CORE_GENERIC_INTERFACE */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_AlignmentCheckResMessageOutOfSequence);
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
    P2CONST(Exi_ISO_20_WPT_10_WPT_AlignmentCheckResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_WPT_10_WPT_AlignmentCheckResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-2541], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-5067] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = Scc_ReturnType_Pending;
    }
    /* #50 [V2G20-734], [V2G20-2201] Otherwise */
    else
    {
      /* #60 [V2G20-5014] Report the parameter from the response to the application. */

      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

      /* EVSEProcessing */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEProcessing(msgPtr->EVSEProcessing);

      /* PowerTransmitted */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_PowerTransmitted(msgPtr->PowerTransmitted, msgPtr->PowerTransmittedFlag);

      /* SupplyDeviceCurrent */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_SupplyDeviceCurrent(msgPtr->SupplyDeviceCurrent, msgPtr->SupplyDeviceCurrentFlag);

      /* VendorSpecificDataContainer */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_VendorSpecificDataContainerRx(msgPtr->VendorSpecificDataContainer, msgPtr->VendorSpecificDataContainerFlag);

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = Scc_ReturnType_OK;
    }
  }

  return retVal;
}



/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_ExiRx_WPT_ChargeLoopRes
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
 */

SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiRx_WPT_ChargeLoopRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)                                                  /* PRQA S 3673 */ /* MD_SCC_CORE_GENERIC_INTERFACE */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  Scc_PhysicalValueType scc_PhysicalValueTmp;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_WPT_10_WPT_CHARGE_LOOP_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20WPT_ChargeLoopResMessageOutOfSequence);
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
    P2CONST(Exi_ISO_20_WPT_10_WPT_ChargeLoopResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_WPT_10_WPT_ChargeLoopResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-2543], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-735] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = Scc_ReturnType_Pending;
    }
    /* #50 [V2G20-734], [V2G20-2201] Otherwise */
    else
    {
      /* #60 [V2G20-5028] Report the parameter from the response to the application. */
      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

      /* EVSEStatus */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEStatus(msgPtr->EVSEStatus, msgPtr->EVSEStatusFlag);

      /* MeterInfo */
      Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_MeterInfo(msgPtr->MeterInfo, msgPtr->MeterInfoFlag);

      /* Receipt */
      Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_Receipt(msgPtr->Receipt, msgPtr->ReceiptFlag);

      /* EVPCPowerRequest */
      Scc_Conv_ISO20ToScc_PhysicalValue(msgPtr->EVPCPowerRequest, &scc_PhysicalValueTmp);
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_EVPCPowerRequestTx(&scc_PhysicalValueTmp);

      /* SDPowerInput */
      Scc_Conv_ISO20ToScc_PhysicalValue(msgPtr->SDPowerInput, &scc_PhysicalValueTmp);
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_SDPowerInput(&scc_PhysicalValueTmp, msgPtr->SDPowerInputFlag);

      /* SPCMaxOutputPowerLimit */
      Scc_Conv_ISO20ToScc_PhysicalValue(msgPtr->SPCMaxOutputPowerLimit, &scc_PhysicalValueTmp);
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_SPCMaxOutputPowerLimit(&scc_PhysicalValueTmp);

      /* SPCMinOutputPowerLimit */
      Scc_Conv_ISO20ToScc_PhysicalValue(msgPtr->SPCMinOutputPowerLimit, &scc_PhysicalValueTmp);
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_SPCMinOutputPowerLimit(&scc_PhysicalValueTmp);

      /* SPCChargeDiagnostics */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_SPCChargeDiagnostics(&msgPtr->SPCChargeDiagnostics);

      /* SPCOperatingFrequency */
      Scc_Conv_ISO20ToScc_PhysicalValue(msgPtr->SPCOperatingFrequency, &scc_PhysicalValueTmp);
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_SPCOperatingFrequencyTx(&scc_PhysicalValueTmp, msgPtr->SPCOperatingFrequencyFlag);

      /* SPCPowerControlParameter */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_SPCPowerControlParameter(msgPtr->SPCPowerControlParameter, msgPtr->SPCPowerControlParameterFlag);

      /* ManufacturerSpecificDataContainer */
      Scc_ISO15118_20WPT_InterfaceCfg_ExiRx_Set_ManufacturerSpecificDataContainerTx(msgPtr->ManufacturerSpecificDataContainer, msgPtr->ManufacturerSpecificDataContainerFlag);

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = Scc_ReturnType_OK;
    }
  }

  return retVal;
}
#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SCHEMA_ISO_20WPT */

/*lint +e546 */ /* Enable the 'Suspicious use of &' reporting again. */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20WPT_ExiRx.c
 *********************************************************************************************************************/
