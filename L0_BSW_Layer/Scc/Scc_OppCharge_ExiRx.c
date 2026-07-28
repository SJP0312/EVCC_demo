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
/*!        \file  Scc_OppCharge_ExiRx.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to the specification of OppCharge.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_OPPCHARGE_EXIRX_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
/* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */
/*lint -e546 */ /* Suppress the 'Suspicious use of &' warning because the '&' is required by MISRA per Id 1502. */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Scc_Cfg.h"

#if ( defined SCC_SCHEMA_OPP_CHARGE ) && ( SCC_SCHEMA_OPP_CHARGE != 0 )

/* Common inculdes */
#include "Scc.h"
#include "Scc_Priv.h"
#include "Scc_ExiRx_Common.h"
#include "Scc_Core_InterfaceCfg.h"
#include "Scc_Core_Channel.h"

/* OppCharge specific includes */
#include "Scc_OppCharge_Exi.h"
#include "Scc_OppCharge_InterfaceCfg.h"

/* Foreign modules */
#include "Exi.h"
#include "IpBase.h"
#if (SCC_IDSM_REPORT == STD_ON)
# include "IdsM.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

#define SCC_OPPCHARGE_V2GTP_HDR_PAYLOAD_TYPE_LEN (1u)

/**********************************************************************************************************************
 *  LOCAL / GLOBAL DATA
 *********************************************************************************************************************/

/* 16bit variables */
#define SCC_START_SEC_CONST_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

SCC_LOCAL CONST(uint16, SCC_CONST) Scc_OppCharge_ExiRx_SupportedPayloadTypes[SCC_OPPCHARGE_V2GTP_HDR_PAYLOAD_TYPE_LEN] = {/* PRQA S 3218 */ /* MD_Scc_3218 */
  (uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_EXI
};

#define SCC_STOP_SEC_CONST_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_<OppCharge-Response>
 *********************************************************************************************************************/
/*! \brief         Get all parameters of OppCharge response message
 *  \details        Validates parameter and reports them to the application.
 *  \pre            -
 *  \param[in]      MsgPtr                Pointer to the Received message
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_OPP_CHARGE
 *********************************************************************************************************************/
/* Common */
/* see pattern Scc_OppCharge_ExiRx_<OppCharge-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_SessionSetupRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_OppCharge_ExiRx_<OppCharge-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_ServiceDiscoveryRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_OppCharge_ExiRx_<OppCharge-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_ServicePaymentSelectionRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_OppCharge_ExiRx_<OppCharge-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_ContractAuthenticationRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_OppCharge_ExiRx_<OppCharge-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_ChargeParameterDiscoveryRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_OppCharge_ExiRx_<OppCharge-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_PowerDeliveryRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_OppCharge_ExiRx_<OppCharge-Response> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_SessionStopRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);

/* DC */
/* see pattern Scc_OppCharge_ExiRx_<OppCharge-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_CableCheckRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_OppCharge_ExiRx_<OppCharge-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_PreChargeRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_OppCharge_ExiRx_<OppCharge-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_CurrentDemandRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);


/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_ReadEVSEStatusDC
 *********************************************************************************************************************/
/*! \brief          reports the EVSEStatus to the application.
 *  \details        reports EVSEIsolationStatus, EVSEStatusCode, EVSENotification and NotificationMaxDelay to the application.
 *  \param[in]      EVSEStatusPtr             Pointer to the EVSEstatus
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_OPP_CHARGE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_ReadEVSEStatusDC(
  P2CONST(Exi_DIN_DC_EVSEStatusType, AUTOMATIC, SCC_VAR_NOINIT) EVSEStatusPtr);

/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_CheckSessionId
 *********************************************************************************************************************/
/*! \brief          Checks the session id of the passed message
 *  \details        -
 *  \param[in]      MsgPtr               Pointer to a response message
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_OPP_CHARGE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_OppCharge_ExiRx_CheckSessionId(
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) MsgPtr);

/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_DecodeMessagePrepare
 *********************************************************************************************************************/
/*! \brief          Prepares the decoding of an EXI stream
 *  \details        -
 *  \param[in]      V2GTpHeaderPtr        Pointer to a v2gtp header
 *  \param[in]      RxMsgWSPtr            Pointer to the Rx message workspace
 *  \return         E_OK                  Exi decode preparation was successful
 *  \return         E_NOT_OK              Exi decode preparation was not successful
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_OPP_CHARGE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_OppCharge_ExiRx_DecodeMessagePrepare(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);

/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_DecodeMessage
 *********************************************************************************************************************/
/*! \brief          Decodes EXI streams
 *  \details        -
 *  \param[in]      V2GTpHeaderPtr          Pointer to a v2gtp header
 *  \param[in]      RxMsgWSPtr              Pointer to the Rx message workspace
 *  \return         Scc_ReturnType_OK       Exi decode was successful
 *  \return         Scc_ReturnType_NotOK    Exi decode was not successful
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_OPP_CHARGE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_OppCharge_ExiRx_DecodeMessage(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_SetupRxConfig
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_OppCharge_ExiRx_SetupRxConfig(
  P2VAR(Scc_RxConfigStructType, AUTOMATIC, SCC_APPL_DATA) RxConfigPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Setup the passed Rx configuration structure */
  RxConfigPtr->DecodePrepareFct = &Scc_OppCharge_ExiRx_DecodeMessagePrepare;
  RxConfigPtr->DecodeFct = &Scc_OppCharge_ExiRx_DecodeMessage;
  RxConfigPtr->SupportedPayloadTypeList = &Scc_OppCharge_ExiRx_SupportedPayloadTypes[0];
  RxConfigPtr->SupportedPayloadTypeListLen = SCC_OPPCHARGE_V2GTP_HDR_PAYLOAD_TYPE_LEN;
  RxConfigPtr->PropagteMessage = TRUE;
}



/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_CheckSessionId
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_OppCharge_ExiRx_CheckSessionId(
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_VAR_NOINIT) exiRx_MsgPtr =
    (P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_VAR_NOINIT)) MsgPtr;                                               /* PRQA S 0310,3305 */ /* MD_Scc_0310_0314_0316_3305 */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the SessionID starting from ServiceDiscovery */
  if (Scc_MsgTrig_SessionSetup < Scc_Core_Channel_Get_MsgTrig())
  {
    /* [V2G2-486] and figure OC_2 specifiy StopCom without SessionStop after SessionSetupRes with ResponseCode Failed */
    if (Scc_MsgStatus != Scc_MsgStatus_SessionSetup_Failed)
    {
      /* #20 Compare the length of the stored and received SessionID */
      if (exiRx_MsgPtr->Header->SessionID->Length == Scc_SessionIDNvm[0])
      {
        /* #30 Compare SessionID value */
        if (IPBASE_CMP_EQUAL != IpBase_StrCmpLen(
                                  &exiRx_MsgPtr->Header->SessionID->Buffer[0],
                                  &Scc_SessionIDNvm[1], Scc_SessionIDNvm[0]))
        {
          /* #40 Unequal: [V2G2-OC-722] - Ignore message */
        }
        else
        {
          /* #50 Equal: SessionId matches */
          retVal = E_OK;
        }
      }
      /* #60 Length is unequal */
      else
      {
        /* #70 [V2G2-OC-722] - Ignore message */
      }
    }
    /* Invalid msg trigger */
    else
    {
      /* report the error */
      Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_OppCharge_CheckSessionIdSessionSetupFailed);
    }
  }
  else
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_DecodeMessagePrepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_OppCharge_ExiRx_DecodeMessagePrepare(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  SCC_DUMMY_STATEMENT_CONST(V2GTpHeaderPtr);                                                                            /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Start exi decoding */
  return Scc_ExiRx_Common_DecodeMessagePrepare(EXI_SCHEMA_SET_DIN_TYPE, &Scc_OppCharge_ExiRx_CheckSessionId, RxMsgWSPtr);
}

/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_DecodeMessage
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
/* PRQA S 6030,6050 1 */ /* MD_MSR_STCYC,MD_MSR_STCAL */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_OppCharge_ExiRx_DecodeMessage(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                    Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
  P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_VAR_NOINIT) exiRx_MsgPtr =
    (P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_VAR_NOINIT)) buffPoolWsPtr->MsgPtr;                                /* PRQA S 0310,3305 */ /* MD_Scc_0310_0314_0316_3305 */

  /* ----- Implementation ----------------------------------------------- */
#if (defined(SCC_EVSE_COMP_ALLOW_BIGGER_PAYLOAD) && (SCC_EVSE_COMP_ALLOW_BIGGER_PAYLOAD == STD_ON))
  /* Do not perform the length check as too big payload information in header should be ignored */
  SCC_DUMMY_STATEMENT_CONST(V2GTpHeaderPtr);                                                                            /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#else
  /* #10 Check if message payload length matches EXI stream size */
  if (RxMsgWSPtr->Exi_DecWs.DecWs.TotalStreamLength != V2GTpHeaderPtr->PayloadLength)
  {
    /* #20 Unequal: The payload length is wrong the message is going to be ignored */
    /* [V2G-DC-172] */
    retVal = Scc_ReturnType_InvalidPayloadLen;
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_OppCharge_DecodeMessageInvalidPayloadLen);

#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_V2GTPHEADER_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #30 Otherwise */
  else
#endif /* SCC_EVSE_COMP_ALLOW_BIGGER_PAYLOAD */
  {
    /* #40 Dispatch an incoming response message based on current message trigger */
    switch (Scc_Core_Channel_Get_MsgTrig())
    {
      /* handle an incoming session setup response message */
    case Scc_MsgTrig_SessionSetup:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_OppCharge_ExiRx_SessionSetupRes(exiRx_MsgPtr))
      {
        Scc_State = Scc_State_Connected;
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_SessionSetup_OK);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming service discovery response message */
    case Scc_MsgTrig_ServiceDiscovery:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_OppCharge_ExiRx_ServiceDiscoveryRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_ServiceDiscovery_OK);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming service payment selection response message */
    case Scc_MsgTrig_PaymentServiceSelection:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_OppCharge_ExiRx_ServicePaymentSelectionRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_PaymentServiceSelection_OK);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming contract authentication response message */
    case Scc_MsgTrig_Authorization:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_OppCharge_ExiRx_ContractAuthenticationRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_Authorization_OK);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming charge parameter discovery response message */
    case Scc_MsgTrig_ChargeParameterDiscovery:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_OppCharge_ExiRx_ChargeParameterDiscoveryRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_ChargeParameterDiscovery_OK);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming power delivery response message */
    case Scc_MsgTrig_PowerDelivery:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_OppCharge_ExiRx_PowerDeliveryRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_PowerDelivery_OK);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming session stop response message */
    case Scc_MsgTrig_SessionStop:
    {
      /* try to process the message and check if it was successful */
      Scc_ReturnType funcRetVal = Scc_OppCharge_ExiRx_SessionStopRes(exiRx_MsgPtr);
      /* Check if ok, report the status */
      if (funcRetVal == Scc_ReturnType_OK)
      {
        Scc_State = Scc_State_Disconnected;
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_SessionStop_OK);
        retVal = Scc_ReturnType_OK;
      }
      /* If pending then set status to failed but retVal to ok to send the next SessionStopReq */
      else if (funcRetVal == Scc_ReturnType_Pending)
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_SessionStop_Failed);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
        retVal = Scc_ReturnType_OK;
      }
      /* Otherwise set error */
      else
      {
        /* retVal is already set to not ok */
      }
      break;
    }

    /* handle an incoming cable check response message */
    case Scc_MsgTrig_CableCheck:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_OppCharge_ExiRx_CableCheckRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_CableCheck_OK);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming pre charge response message */
    case Scc_MsgTrig_PreCharge:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_OppCharge_ExiRx_PreChargeRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_PreCharge_OK);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming current demand response message */
    case Scc_MsgTrig_CurrentDemand:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_OppCharge_ExiRx_CurrentDemandRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_CurrentDemand_OK);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
        retVal = Scc_ReturnType_OK;
      }
      break;

    default:
      /* invalid state */
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_SessionSetupRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_SessionSetupRes(
  P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected */
  if ( EXI_DIN_SESSION_SETUP_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    /* #20 Report out of sequence error  */
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_OppCharge_SessionSetupResMessageOutOfSequence);

#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #30 Otherwise */
  else
  {
    P2CONST(Exi_DIN_SessionSetupResType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr =
      (P2CONST(Exi_DIN_SessionSetupResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;                       /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */

    /* SessionID */
    /* get the new length of the SessionID */
    Scc_SessionIDNvm[0] = (uint8)MsgPtr->Header->SessionID->Length;
    /* copy the SessionID */
    IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &Scc_SessionIDNvm[1],                            /* PRQA S 0310,3305,0315 1 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy */
      (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &MsgPtr->Header->SessionID->Buffer[0], Scc_SessionIDNvm[0]);

    /* #40 Popagate SessionID to interface API */
    Scc_OppCharge_InterfaceCfg_ExiRx_Set_SessionID(MsgPtr->Header->SessionID);


    /* #50 Check if the response is negative */
    if ( EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= bodyPtr->ResponseCode )
    {
      /* #60 Report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_OppCharge_SessionSetupResNegativeResponseCode);

      /* provide the response code to the application */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_ResponseCode(bodyPtr->ResponseCode);
    }
    /* #70 Otherwise */
    else
    {
      /* #80 Report the parameters from the response to interface API */
      /* EVSEID */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSEID(bodyPtr->EVSEID);
      /* DateTimeNow */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_DateTimeNow(bodyPtr->DateTimeNow, bodyPtr->DateTimeNowFlag);
      /* ResponseCode */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_ResponseCode(EXI_DIN_RESPONSE_CODE_TYPE_OK_NEW_SESSION_ESTABLISHED);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_ServiceDiscoveryRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_ServiceDiscoveryRes(
  P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_DIN_SERVICE_DISCOVERY_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    /* #20 Report out of sequence error  */
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_OppCharge_ServiceDiscoveryResMessageOutOfSequence);

#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #30 Otherwise */
  else
  {
    P2CONST(Exi_DIN_ServiceDiscoveryResType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr =
      (P2CONST(Exi_DIN_ServiceDiscoveryResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */

    /* #40 Check if the response is negative. */
    if ( EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= bodyPtr->ResponseCode )
    {
      /* #50 Report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_OppCharge_ServiceDiscoveryResNegativeResponseCode);

      /* provide the response code to the application */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_ResponseCode(bodyPtr->ResponseCode);
    }
    /* #60 Check if [V2G2-OC-283_1] is fullfilled - one payment option */
    else if (bodyPtr->PaymentOptions->PaymentOptionCount != 1u)
    {
      /* #70 No: Report error */
      Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_OppCharge_ServiceDiscoveryResPaymenOptionCountNotOne);
    }
    /* #80 Check if [V2G2-OC-283_1] is fullfilled - external payment */
    else if (bodyPtr->PaymentOptions->PaymentOption[0u] != EXI_DIN_PAYMENT_OPTION_TYPE_EXTERNAL_PAYMENT)
    {
      /* #90 No: Report error */
      Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_OppCharge_ServiceDiscoveryResMissingExternalPayment);
    }
    /* #100 Otherwise */
    else
    {
      /* #110 Report the parameters from the response to interface API */
      /* ChargeService */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_ChargeService(bodyPtr->ChargeService);
      /* ResponseCode */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_ResponseCode(bodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_ServicePaymentSelectionRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_ServicePaymentSelectionRes(
  P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_DIN_SERVICE_PAYMENT_SELECTION_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    /* #20 Report out of sequence error  */
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_OppCharge_ServicePaymentSelectionResMessageOutOfSequence);

#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #30 Otherwise */
  else
  {
    P2CONST(Exi_DIN_ServicePaymentSelectionResType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr =
      (P2CONST(Exi_DIN_ServicePaymentSelectionResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;            /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */

    /* #40 Check if the response is negative. */
    if ( EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= bodyPtr->ResponseCode )
    {
      /* #50 Report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_OppCharge_ServicePaymentSelectionResNegativeResponseCode);

      /* provide the response code to the application */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_ResponseCode(bodyPtr->ResponseCode);
    }
    /* #60 Otherwise */
    else
    {
      /* #70 Report the parameters from the response to interface API */
      /* ResponseCode */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_ResponseCode(bodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_ContractAuthenticationRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_ContractAuthenticationRes(
  P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_DIN_CONTRACT_AUTHENTICATION_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    /* #20 Report out of sequence error  */
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_OppCharge_ContractAuthenticationResMessageOutOfSequence);

#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #30 Otherwise */
  else
  {
    P2CONST(Exi_DIN_ContractAuthenticationResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_DIN_ContractAuthenticationResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;             /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */

    /* #40 Check if the response is negative. */
    if ( EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* #50 Report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_OppCharge_ContractAuthenticationResNegativeResponseCode);

      /* provide the response code to the application */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    /* #60 Otherwise */
    else
    {
      /* #70 Report the parameters from the response to interface API */
      /* EVSEProcessing */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSEProcessing(BodyPtr->EVSEProcessing);
      /* ResponseCode */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_ChargeParameterDiscoveryRes
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
 */
/* PRQA S  6050,6080 1 */ /* MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_ChargeParameterDiscoveryRes(
  P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_DIN_CHARGE_PARAMETER_DISCOVERY_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    /* #20 Report out of sequence error  */
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_OppCharge_ChargeParameterDiscoveryResMessageOutOfSequence);

#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #30 Otherwise */
  else
  {
    P2CONST(Exi_DIN_ChargeParameterDiscoveryResType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr =
      (P2CONST(Exi_DIN_ChargeParameterDiscoveryResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;           /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */


    /* #40 Check if the EVSEChargeParameter has the correct type */
    if ( EXI_DIN_DC_EVSECHARGE_PARAMETER_TYPE != bodyPtr->EVSEChargeParameterElementId )
    {
      /* #50 Report wrong type as stack error */
      Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_OppCharge_ChargeParameterDiscoveryResDcEvsechargeParameterElemIdInvalid);

    }
    /* #60 Otherwise */
    else
    {
      /* #70 Check if the response is negative. */
      if ( EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= bodyPtr->ResponseCode )
      {
        /* #80 Report the negative response code as stack error */
        Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_OppCharge_ChargeParameterDiscoveryResNegativeResponseCode);

        /* provide the response code to the application */
        Scc_OppCharge_InterfaceCfg_ExiRx_Set_ResponseCode(bodyPtr->ResponseCode);
      }
      /* #90 Otherwise */
      else
      {
        /* #100 Report the parameters from the response to interface API */
        Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
        P2CONST(Exi_DIN_DC_EVSEChargeParameterType, AUTOMATIC, SCC_VAR_NOINIT) dc_EVSEChargeParameterPtr =
          (P2CONST(Exi_DIN_DC_EVSEChargeParameterType, AUTOMATIC, SCC_APPL_DATA))bodyPtr->EVSEChargeParameter;          /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */

        /* [V2G2-OC-220_1] - EVSEProcessing and SAScheduleList are not used */

        /* DC_EVSEChargeParameter -> DC_EVSEStatus */
        Scc_OppCharge_ExiRx_ReadEVSEStatusDC(dc_EVSEChargeParameterPtr->DC_EVSEStatus);

        /* DC_EVSEChargeParameter -> EVSEMaximumCurrentLimit */
        Scc_Conv_DIN2Scc_PhysicalValue(dc_EVSEChargeParameterPtr->EVSEMaximumCurrentLimit, &scc_PhysicalValueTmp);
        Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSEMaximumCurrentLimit(&scc_PhysicalValueTmp, 1);

        /* DC_EVSEChargeParameter -> EVSEMaximumPowerLimit */
        Scc_Conv_DIN2Scc_PhysicalValue(dc_EVSEChargeParameterPtr->EVSEMaximumPowerLimit, &scc_PhysicalValueTmp);
        Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSEMaximumPowerLimit(&scc_PhysicalValueTmp, dc_EVSEChargeParameterPtr->EVSEMaximumPowerLimitFlag);

        /* DC_EVSEChargeParameter -> EVSEMaximumVoltageLimit */
        Scc_Conv_DIN2Scc_PhysicalValue(dc_EVSEChargeParameterPtr->EVSEMaximumVoltageLimit, &scc_PhysicalValueTmp);
        Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSEMaximumVoltageLimit(&scc_PhysicalValueTmp, 1);

        /* DC_EVSEChargeParameter -> EVSEMinimumCurrentLimit */
        Scc_Conv_DIN2Scc_PhysicalValue(dc_EVSEChargeParameterPtr->EVSEMinimumCurrentLimit, &scc_PhysicalValueTmp);
        Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSEMinimumCurrentLimit(&scc_PhysicalValueTmp);

        /* DC_EVSEChargeParameter -> EVSEMinimumVoltageLimit */
        Scc_Conv_DIN2Scc_PhysicalValue(dc_EVSEChargeParameterPtr->EVSEMinimumVoltageLimit, &scc_PhysicalValueTmp);
        Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSEMinimumVoltageLimit(&scc_PhysicalValueTmp);

        /* DC_EVSEChargeParameter -> EVSECurrentRegulationTolerance */
        Scc_Conv_DIN2Scc_PhysicalValue(dc_EVSEChargeParameterPtr->EVSECurrentRegulationTolerance, &scc_PhysicalValueTmp);
        Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSECurrentRegulationTolerance(&scc_PhysicalValueTmp, dc_EVSEChargeParameterPtr->EVSECurrentRegulationToleranceFlag);

        /* DC_EVSEChargeParameter -> EVSEPeakCurrentRipple */
        Scc_Conv_DIN2Scc_PhysicalValue(dc_EVSEChargeParameterPtr->EVSEPeakCurrentRipple, &scc_PhysicalValueTmp);
        Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSEPeakCurrentRipple(&scc_PhysicalValueTmp);

        /* DC_EVSEChargeParameter -> EVSEEnergyToBeDelivered */
        Scc_Conv_DIN2Scc_PhysicalValue(dc_EVSEChargeParameterPtr->EVSEEnergyToBeDelivered, &scc_PhysicalValueTmp);
        Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSEEnergyToBeDelivered(&scc_PhysicalValueTmp, dc_EVSEChargeParameterPtr->EVSEEnergyToBeDeliveredFlag);

        retVal = E_OK;

        /* check if the parameter was sent by the EVSE */
        if ( 0u == dc_EVSEChargeParameterPtr->EVSEMaximumPowerLimitFlag )
        {
          Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_OppCharge_ChargeParameterDiscoveryResMissingEvsemaximumpowerlimitParameter);

          retVal = E_NOT_OK;
        }

        if ( retVal == E_OK )
        {
          /* ResponseCode */
          Scc_OppCharge_InterfaceCfg_ExiRx_Set_ResponseCode(bodyPtr->ResponseCode);
        }
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_PowerDeliveryRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_PowerDeliveryRes(
  P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_DIN_POWER_DELIVERY_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    /* #20 Report out of sequence error  */
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_OppCharge_PowerDeliveryResMessageOutOfSequence);

#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #30 Otherwise */
  else
  {
    P2CONST(Exi_DIN_PowerDeliveryResType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr =
      (P2CONST(Exi_DIN_PowerDeliveryResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;                      /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */


    /* #40 Check if the response is negative. */
    if ( EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= bodyPtr->ResponseCode )
    {
      /* #50 Report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_OppCharge_PowerDeliveryResNegativeResponseCode);

      /* provide the response code to the application */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_ResponseCode(bodyPtr->ResponseCode);
    }
    /* #60 Check if EVSEStatus contains no DC_EVSEStatus */
    else if ( EXI_DIN_DC_EVSESTATUS_TYPE != bodyPtr->EVSEStatusElementId )
    {
      /* #70 Report the missing DC_EVSEStatus as stack error */
      Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_OppCharge_PowerDeliveryResDcEvsestatusElemIdInvalid);

    }
    /* #80 Otherwise */
    else
    {
      /* #90 Report the parameters from the response to interface API */
      /* DC_EVSEStatus */
      Scc_OppCharge_ExiRx_ReadEVSEStatusDC((P2VAR(Exi_DIN_DC_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA))bodyPtr->EVSEStatus); /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
      /* ResponseCode */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_ResponseCode(bodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_SessionStopRes
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_SessionStopRes(
  P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_DIN_SESSION_STOP_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    /* #20 Report out of sequence error  */
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_OppCharge_SessionStopResMessageOutOfSequence);

#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #30 Otherwise */
  else
  {
    P2CONST(Exi_DIN_SessionStopResType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr =
      (P2CONST(Exi_DIN_SessionStopResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;                        /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */

    /* #40 Check if the response is negative. */
    if (EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= bodyPtr->ResponseCode)
    {
      /* #50 Return pending to inform the calling function since failed response code is accepted in OppCharge */
      /* Pantograph may not be in upper home position yet */
      /* provide the response code to the application */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_ResponseCode(bodyPtr->ResponseCode);
      retVal = Scc_ReturnType_Pending;
    }
    /* #60 Otherwise */
    else
    {
      /* #70 Report the parameters from the response to interface API */
      /* ResponseCode */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_ResponseCode(bodyPtr->ResponseCode);

      retVal = Scc_ReturnType_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_CableCheckRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_CableCheckRes(
  P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_DIN_CABLE_CHECK_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    /* #20 Report out of sequence error  */
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_OppCharge_CableCheckResMessageOutOfSequence);

#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #30 Otherwise */
  else
  {
    P2CONST(Exi_DIN_CableCheckResType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr =
      (P2CONST(Exi_DIN_CableCheckResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;                         /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */


    /* #40 Check if the response is negative. */
    if ( EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= bodyPtr->ResponseCode )
    {
      /* #50 Report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_OppCharge_CableCheckResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_ResponseCode(bodyPtr->ResponseCode);
    }
    /* #60 Otherwise */
    else
    {
      /* #70 Report the parameters from the response to interface API */
      /* EVSEProcessing */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSEProcessing(bodyPtr->EVSEProcessing);

      /* DC_EVSEStatus */
      Scc_OppCharge_ExiRx_ReadEVSEStatusDC((P2VAR(Exi_DIN_DC_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA))bodyPtr->DC_EVSEStatus);

      /* ResponseCode */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_ResponseCode(bodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_PreChargeRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_PreChargeRes(
  P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_DIN_PRE_CHARGE_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    /* #20 Report out of sequence error  */
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_OppCharge_PrechargeResMessageOutOfSequence);

#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #30 Otherwise */
  else
  {
    P2CONST(Exi_DIN_PreChargeResType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr =
      (P2CONST(Exi_DIN_PreChargeResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;                          /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */


    /* #40 Check if the response is negative. */
    if ( EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= bodyPtr->ResponseCode )
    {
      /* #50 Report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_OppCharge_PrechargeResNegativeResponseCode);

      /* provide the response code to the application */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_ResponseCode(bodyPtr->ResponseCode);
    }
    /* #60 Otherwise */
    else
    {
      /* #70 Report the parameters from the response to interface API */
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };

      /* DC_EVSEStatus */
      Scc_OppCharge_ExiRx_ReadEVSEStatusDC((P2VAR(Exi_DIN_DC_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA))bodyPtr->DC_EVSEStatus);

      /* EVSEPresentVoltage */
      Scc_Conv_DIN2Scc_PhysicalValue(bodyPtr->EVSEPresentVoltage, &scc_PhysicalValueTmp);
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSEPresentVoltage(&scc_PhysicalValueTmp);

      /* ResponseCode */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_ResponseCode(bodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_CurrentDemandRes
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
 */ /* PRQA S 6050 1 */ /* MD_MSR_STCAL */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_CurrentDemandRes(
  P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_DIN_CURRENT_DEMAND_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    /* #20 Report out of sequence error  */
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_OppCharge_CurrentDemandResMessageOutOfSequence);

#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #30 Otherwise */
  else
  {
    P2CONST(Exi_DIN_CurrentDemandResType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr =
      (P2CONST(Exi_DIN_CurrentDemandResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;                      /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */


    /* #40 Check if the response is negative. */
    if ( EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= bodyPtr->ResponseCode )
    {
      /* #50 Report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_OppCharge_CurrentDemandResNegativeResponseCode);

      /* provide the response code to the application */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_ResponseCode(bodyPtr->ResponseCode);
    }
    /* #60 Otherwise */
    else
    {
      /* #70 Report the parameters from the response to interface API */
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };

      /* DC_EVSEStatus */
      Scc_OppCharge_ExiRx_ReadEVSEStatusDC((P2VAR(Exi_DIN_DC_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA))bodyPtr->DC_EVSEStatus);

      /* EVSEPresentVoltage */
      Scc_Conv_DIN2Scc_PhysicalValue(bodyPtr->EVSEPresentVoltage, &scc_PhysicalValueTmp);
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSEPresentVoltage(&scc_PhysicalValueTmp);

      /* EVSEPresentCurrent */
      Scc_Conv_DIN2Scc_PhysicalValue(bodyPtr->EVSEPresentCurrent, &scc_PhysicalValueTmp);
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSEPresentCurrent(&scc_PhysicalValueTmp);

      /* EVSECurrentLimitAchieved */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSECurrentLimitAchieved(bodyPtr->EVSECurrentLimitAchieved);

      /* EVSEVoltageLimitAchieved */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSEVoltageLimitAchieved(bodyPtr->EVSEVoltageLimitAchieved);

      /* EVSEPowerLimitAchieved */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSEPowerLimitAchieved(bodyPtr->EVSEPowerLimitAchieved);

      /* EVSEMaximumVoltageLimit */
      Scc_Conv_DIN2Scc_PhysicalValue(bodyPtr->EVSEMaximumVoltageLimit, &scc_PhysicalValueTmp);
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSEMaximumVoltageLimit(&scc_PhysicalValueTmp, bodyPtr->EVSEMaximumVoltageLimitFlag);

      /* EVSEMaximumCurrentLimit */
      Scc_Conv_DIN2Scc_PhysicalValue(bodyPtr->EVSEMaximumCurrentLimit, &scc_PhysicalValueTmp);
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSEMaximumCurrentLimit(&scc_PhysicalValueTmp, bodyPtr->EVSEMaximumCurrentLimitFlag);

      /* EVSEMaximumPowerLimit */
      Scc_Conv_DIN2Scc_PhysicalValue(bodyPtr->EVSEMaximumPowerLimit, &scc_PhysicalValueTmp);
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSEMaximumPowerLimit(&scc_PhysicalValueTmp, bodyPtr->EVSEMaximumPowerLimitFlag);

      /* ResponseCode */
      Scc_OppCharge_InterfaceCfg_ExiRx_Set_ResponseCode(bodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_OppCharge_ExiRx_ReadEVSEStatusDC
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_OppCharge_ExiRx_ReadEVSEStatusDC(P2CONST(Exi_DIN_DC_EVSEStatusType, AUTOMATIC, SCC_VAR_NOINIT) EVSEStatusPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Report the parameters from the response to interface API */
  /* EVSEIsolationStatus */
  Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSEIsolationStatus(EVSEStatusPtr->EVSEIsolationStatus, EVSEStatusPtr->EVSEIsolationStatusFlag);
  /* EVSEStatusCode */
  Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSEStatusCode(EVSEStatusPtr->EVSEStatusCode);
  /* NotificationMaxDelay */
  Scc_OppCharge_InterfaceCfg_ExiRx_Set_NotificationMaxDelay(EVSEStatusPtr->NotificationMaxDelay);
  /* EVSENotification */
  Scc_OppCharge_InterfaceCfg_ExiRx_Set_EVSENotification(EVSEStatusPtr->EVSENotification);
}

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SCHEMA_OPP_CHARGE */

/*lint +e546 */ /* Enable the 'Suspicious use of &' reporting again. */

/**********************************************************************************************************************
 *  END OF FILE: Scc_OppCharge_ExiRx.c
 *********************************************************************************************************************/
