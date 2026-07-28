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
/*!        \file  Scc_DIN70121_ExiRx.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to the specifications ISO/IEC 15118-2,
 *                DIN SPEC 70121 and customer specific schemas.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_DIN70121_EXIRX_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
/* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */
/*lint -e546 */ /* Suppress the 'Suspicious use of &' warning because the '&' is required by MISRA per Id 1502. */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Scc_Cfg.h"

#if ( defined SCC_SCHEMA_DIN ) && ( SCC_SCHEMA_DIN != 0 )

#include "Scc.h"
#include "Scc_Priv.h"
#include "Scc_DIN70121_Exi.h"
#include "Scc_DIN70121_InterfaceCfg.h"
#include "Scc_ExiRx_Common.h"
#include "Scc_Core_InterfaceCfg.h"
#include "Scc_Core_Channel.h"

/* Foreign modules */
#include "Exi.h"
#include "IpBase.h"
#if (SCC_IDSM_REPORT == STD_ON)
# include "IdsM.h"
#endif

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

#define SCC_DIN70121_V2GTP_HDR_PAYLOAD_TYPE_LEN (1u)

/**********************************************************************************************************************
 *  LOCAL / GLOBAL DATA
 *********************************************************************************************************************/

/* 16bit variables */
#define SCC_START_SEC_VAR_NO_INIT_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint16, SCC_VAR_NOINIT) Scc_DIN70121_ExiRx_ServiceID;

#define SCC_STOP_SEC_VAR_NO_INIT_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SCC_START_SEC_CONST_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* [V2G-DC-171] */
SCC_LOCAL CONST(uint16, SCC_CONST) Scc_DIN70121_ExiRx_SupportedPayloadTypes[SCC_DIN70121_V2GTP_HDR_PAYLOAD_TYPE_LEN] = {/* PRQA S 3218 */ /* MD_Scc_3218 */
  (uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_EXI
};

#define SCC_STOP_SEC_CONST_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* other variables */
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_<DIN-Response>
 *********************************************************************************************************************/
/*! \brief         Get all parameters of DIN response message
 *  \details        Validates parameter and reports them to the application.
 *  \pre            -
 *  \param[in]      MsgPtr                Pointer to the Received message
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
/* Common */
/* see pattern Scc_DIN70121_ExiRx_<DIN-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_SessionSetupRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_DIN70121_ExiRx_<DIN-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_ServiceDiscoveryRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_DIN70121_ExiRx_<DIN-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_ServicePaymentSelectionRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_DIN70121_ExiRx_<DIN-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_ContractAuthenticationRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_DIN70121_ExiRx_<DIN-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_ChargeParameterDiscoveryRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_DIN70121_ExiRx_<DIN-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_PowerDeliveryRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_DIN70121_ExiRx_<DIN-Response> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_SessionStopRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);

/* DC */
/* see pattern Scc_DIN70121_ExiRx_<DIN-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_CableCheckRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_DIN70121_ExiRx_<DIN-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_PreChargeRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_DIN70121_ExiRx_<DIN-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_CurrentDemandRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_DIN70121_ExiRx_<DIN-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_WeldingDetectionRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_ReadEVSEStatusDC
 *********************************************************************************************************************/
/*! \brief          reports the EVSEStatus to the application.
 *  \details        reports EVSEIsolationStatus, EVSEStatusCode, EVSENotification and NotificationMaxDelay to the application.
 *  \param[in]      EVSEStatusPtr             Pointer to the EVSEstatus
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_ReadEVSEStatusDC(P2CONST(Exi_DIN_DC_EVSEStatusType, AUTOMATIC, SCC_VAR_NOINIT) EVSEStatusPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_CheckSessionId
 *********************************************************************************************************************/
/*! \brief          Checks the session id of the passed message
 *  \details        -
 *  \param[in]      MsgPtr               Pointer to a response message
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_DIN70121_ExiRx_CheckSessionId(
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) MsgPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_DecodeMessagePrepare
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
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_DIN70121_ExiRx_DecodeMessagePrepare(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_DecodeMessage
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
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_DIN70121_ExiRx_DecodeMessage(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_SetupRxConfig
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_DIN70121_ExiRx_SetupRxConfig(
  P2VAR(Scc_RxConfigStructType, AUTOMATIC, SCC_APPL_DATA) RxConfigPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Setup the passed Rx configuration structure */
  RxConfigPtr->DecodePrepareFct = &Scc_DIN70121_ExiRx_DecodeMessagePrepare;
  RxConfigPtr->DecodeFct = &Scc_DIN70121_ExiRx_DecodeMessage;
  RxConfigPtr->SupportedPayloadTypeList = &Scc_DIN70121_ExiRx_SupportedPayloadTypes[0];
  RxConfigPtr->SupportedPayloadTypeListLen = SCC_DIN70121_V2GTP_HDR_PAYLOAD_TYPE_LEN;
  RxConfigPtr->PropagteMessage = TRUE;
}


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_CheckSessionId
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_DIN70121_ExiRx_CheckSessionId(
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
  P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_VAR_NOINIT) exiRx_MsgPtr =
    (P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_VAR_NOINIT)) MsgPtr;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 check the SessionID starting from ServiceDiscovery */
  if (Scc_MsgTrig_SessionSetup < Scc_Core_Channel_Get_MsgTrig())
  {
    /* #20 check the SessionID starting from ServiceDiscovery and stop with SessionStop */
    /* V2G-DC-649 requires SessionStop after SessionSetupRes with ResponseCode Failed.
     * SessionID is not set in this condition */
    if (Scc_MsgStatus != Scc_MsgStatus_SessionSetup_Failed)
    {
      /* compare the length of the stored and received SessionID */
      if (exiRx_MsgPtr->Header->SessionID->Length == Scc_SessionIDNvm[0])
      {
        /* if the length is the same, check if the content is the same, too */
        if (IPBASE_CMP_EQUAL != IpBase_StrCmpLen(&exiRx_MsgPtr->Header->SessionID->Buffer[0],
          &Scc_SessionIDNvm[1], Scc_SessionIDNvm[0]))
        {
          /* SessionID is not equal, report the error */
          Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Din_CheckSessionIdSessionIdInvalid);
        }
        else
        {
          retVal = E_OK;
        }
      }
      /* length is not the same */
      else
      {

        /* report the error */
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Din_CheckSessionIdSessionIdLenInvalid);
      }
    }
    else
    {
      /* return Ok */
      retVal = E_OK;
    }
    /* the Notification is currently ignored */
  }
  else
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_DecodeMessagePrepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_DIN70121_ExiRx_DecodeMessagePrepare(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  SCC_DUMMY_STATEMENT_CONST(V2GTpHeaderPtr);                                                                            /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Start exi decoding */
  return Scc_ExiRx_Common_DecodeMessagePrepare(EXI_SCHEMA_SET_DIN_TYPE, &Scc_DIN70121_ExiRx_CheckSessionId, RxMsgWSPtr);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_DecodeMessage
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030,6050 1 */ /* MD_MSR_STCYC,MD_MSR_STCAL */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_DIN70121_ExiRx_DecodeMessage(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                    Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
  /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
  P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_VAR_NOINIT) exiRx_MsgPtr =
    (P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_VAR_NOINIT)) buffPoolWsPtr->MsgPtr;

  /* ----- Implementation ----------------------------------------------- */
#if (defined(SCC_EVSE_COMP_ALLOW_BIGGER_PAYLOAD) && (SCC_EVSE_COMP_ALLOW_BIGGER_PAYLOAD == STD_ON))
  /* Do not perform the length check as too big payload information in header should be ignored */
  SCC_DUMMY_STATEMENT_CONST(V2GTpHeaderPtr);                                                                            /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#else
  if (RxMsgWSPtr->Exi_DecWs.DecWs.TotalStreamLength != V2GTpHeaderPtr->PayloadLength)
  {
    /* The payload length is wrong the message is going to be ignored */
    /* [V2G-DC-172] */
    retVal = Scc_ReturnType_InvalidPayloadLen;
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Din_DecodeMessageInvalidPayloadLen);

#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_V2GTPHEADER_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
#endif /* SCC_EVSE_COMP_ALLOW_BIGGER_PAYLOAD */
  {
    /* #10 Handle an incoming response message */
    switch (Scc_Core_Channel_Get_MsgTrig())
    {
      /* handle an incoming session setup response message */
    case Scc_MsgTrig_SessionSetup:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_DIN70121_ExiRx_SessionSetupRes(exiRx_MsgPtr))
      {
        Scc_State = Scc_State_Connected;
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_SessionSetup_OK);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming service discovery response message */
    case Scc_MsgTrig_ServiceDiscovery:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_DIN70121_ExiRx_ServiceDiscoveryRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_ServiceDiscovery_OK);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming service payment selection response message */
    case Scc_MsgTrig_PaymentServiceSelection:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_DIN70121_ExiRx_ServicePaymentSelectionRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_PaymentServiceSelection_OK);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming contract authentication response message */
    case Scc_MsgTrig_Authorization:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_DIN70121_ExiRx_ContractAuthenticationRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_Authorization_OK);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming charge parameter discovery response message */
    case Scc_MsgTrig_ChargeParameterDiscovery:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_DIN70121_ExiRx_ChargeParameterDiscoveryRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_ChargeParameterDiscovery_OK);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming power delivery response message */
    case Scc_MsgTrig_PowerDelivery:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_DIN70121_ExiRx_PowerDeliveryRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_PowerDelivery_OK);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming session stop response message */
    case Scc_MsgTrig_SessionStop:
    {
      /* try to process the message and check if it was successful */
      Scc_ReturnType funcRetVal = Scc_DIN70121_ExiRx_SessionStopRes(exiRx_MsgPtr);
      /* Check if ok, report the status */
      if (funcRetVal == Scc_ReturnType_OK)
      {
        Scc_State = Scc_State_Disconnected;
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_SessionStop_OK);
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
      if ((Std_ReturnType)E_OK == Scc_DIN70121_ExiRx_CableCheckRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_CableCheck_OK);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming pre charge response message */
    case Scc_MsgTrig_PreCharge:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_DIN70121_ExiRx_PreChargeRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_PreCharge_OK);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming current demand response message */
    case Scc_MsgTrig_CurrentDemand:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_DIN70121_ExiRx_CurrentDemandRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_CurrentDemand_OK);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming welding detection response message */
    case Scc_MsgTrig_WeldingDetection:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_DIN70121_ExiRx_WeldingDetectionRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_WeldingDetection_OK);
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
 *  Scc_DIN70121_ExiRx_SessionSetupRes
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_SessionSetupRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 check if the message is not the one that was expected */
  if ( EXI_DIN_SESSION_SETUP_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Din_SessionSetupResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }

  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_DIN_SessionSetupResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_DIN_SessionSetupResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;


    /* SessionID */
    /* get the new length of the SessionID */
    Scc_SessionIDNvm[0] = (uint8)MsgPtr->Header->SessionID->Length;
    /* copy the SessionID */ /* PRQA S 0310,3305,0315 2 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy */
    IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &Scc_SessionIDNvm[1],
      (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &MsgPtr->Header->SessionID->Buffer[0], Scc_SessionIDNvm[0]);

    /* SessionID */
    Scc_DIN70121_InterfaceCfg_ExiRx_Set_SessionID(MsgPtr->Header->SessionID);


    /* #20 check if the response is negative */
    if ( EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Din_SessionSetupResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application */

      /* EVSEID */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEID(BodyPtr->EVSEID);

      /* DateTimeNow */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_DateTimeNow(BodyPtr->DateTimeNow, BodyPtr->DateTimeNowFlag);

      /* ResponseCode */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(EXI_DIN_RESPONSE_CODE_TYPE_OK_NEW_SESSION_ESTABLISHED);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_ServiceDiscoveryRes
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_ServiceDiscoveryRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8_least Counter;
  boolean     ExternalPaymentFound = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_DIN_SERVICE_DISCOVERY_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Din_ServiceDiscoveryResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_DIN_ServiceDiscoveryResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_DIN_ServiceDiscoveryResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;

    /* #20 Check if the response is negative. */
    if ( EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Din_ServiceDiscoveryResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */

      /* PaymentOptionList */
      for ( Counter = 0; Counter < BodyPtr->PaymentOptions->PaymentOptionCount; Counter++ )
      {
        /* check if this PaymentOption element contains ExternalPayment */
        if ( EXI_DIN_PAYMENT_OPTION_TYPE_EXTERNAL_PAYMENT == BodyPtr->PaymentOptions->PaymentOption[Counter] )
        {
          /* set the flag */
          ExternalPaymentFound = TRUE;
        }
      }
      /* check if ExternalPayment was not found */
      if ( TRUE != ExternalPaymentFound )
      {
        /* report the error */
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Din_ServiceDiscoveryResMissingExternalPayment);
      }
      else
      {

        /* ChargeService */
        Scc_DIN70121_InterfaceCfg_ExiRx_Set_ChargeService(BodyPtr->ChargeService);

        /* save the ServiceID */
        Scc_DIN70121_ExiRx_ServiceID = BodyPtr->ChargeService->ServiceTag->ServiceID;

        /* ResponseCode */
        Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);

        retVal = E_OK;
      }
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_ServicePaymentSelectionRes
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_ServicePaymentSelectionRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_DIN_SERVICE_PAYMENT_SELECTION_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Din_ServicePaymentSelectionResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_DIN_ServicePaymentSelectionResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_DIN_ServicePaymentSelectionResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;

    /* #20 Check if the response is negative. */
    if ( EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Din_ServicePaymentSelectionResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */

      /* ResponseCode */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_ContractAuthenticationRes
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_ContractAuthenticationRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_DIN_CONTRACT_AUTHENTICATION_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Din_ContractAuthenticationResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_DIN_ContractAuthenticationResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_DIN_ContractAuthenticationResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;

    /* #20 Check if the response is negative. */
    if ( EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Din_ContractAuthenticationResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */

      /* EVSEProcessing */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEProcessing(BodyPtr->EVSEProcessing);

      /* ResponseCode */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_ChargeParameterDiscoveryRes
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S  6050,6080 1 */ /* MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_ChargeParameterDiscoveryRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Scc_PhysicalValueType scc_PhysicalValueTmp;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_DIN_CHARGE_PARAMETER_DISCOVERY_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Din_ChargeParameterDiscoveryResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_DIN_ChargeParameterDiscoveryResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_DIN_ChargeParameterDiscoveryResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;

    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_DIN_DC_EVSEChargeParameterType, AUTOMATIC, SCC_VAR_NOINIT) DC_EVSEChargeParameterPtr =
      (P2CONST(Exi_DIN_DC_EVSEChargeParameterType, AUTOMATIC, SCC_APPL_DATA))BodyPtr->EVSEChargeParameter;

    /* check if the EVSEChargeParameter has the correct type */
    if ( EXI_DIN_DC_EVSECHARGE_PARAMETER_TYPE != BodyPtr->EVSEChargeParameterElementId )
    {
      Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Din_ChargeParameterDiscoveryResDcEvsechargeParameterElemIdInvalid);
    }
    else
    {
      /* #20 Check if the response is negative. */
      if ( EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
      {
        /* report the negative response code as stack error */
        Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Din_ChargeParameterDiscoveryResNegativeResponseCode);
        /* provide the response code to the application */
        Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
      }
      else
      {
        /* #30 Report the parameter from the response to the application. */
        /* EVSEProcessing */
        Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEProcessing(BodyPtr->EVSEProcessing);

        /* only update the values when EVSEProcessing is set to Finished */
        if ( EXI_DIN_EVSEPROCESSING_TYPE_FINISHED == BodyPtr->EVSEProcessing )
        {
          /* provide the SAScheduleList to the application */
          Scc_DIN70121_InterfaceCfg_ExiRx_Set_SAScheduleList(BodyPtr->SASchedules);                                     /* PRQA S 0317 */ /* MD_Scc_Exi_Generic */
        }

      #if ( SCC_ENABLE_ONGOING_CALLBACKS ) && ( SCC_ENABLE_ONGOING_CALLBACKS == STD_ON )
      #else
        /* only update the values when EVSEProcessing is set to Finished */
        if ( EXI_DIN_EVSEPROCESSING_TYPE_FINISHED == BodyPtr->EVSEProcessing )
      #endif
        {
          /* DC_EVSEChargeParameter -> DC_EVSEStatus */
          Scc_DIN70121_ExiRx_ReadEVSEStatusDC(DC_EVSEChargeParameterPtr->DC_EVSEStatus);

          /* DC_EVSEChargeParameter -> EVSEMaximumCurrentLimit */
          Scc_Conv_DIN2Scc_PhysicalValue(DC_EVSEChargeParameterPtr->EVSEMaximumCurrentLimit, &scc_PhysicalValueTmp);
          Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMaximumCurrentLimit(&scc_PhysicalValueTmp, 1);

          /* DC_EVSEChargeParameter -> EVSEMaximumPowerLimit */
          Scc_Conv_DIN2Scc_PhysicalValue(DC_EVSEChargeParameterPtr->EVSEMaximumPowerLimit, &scc_PhysicalValueTmp);
          Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMaximumPowerLimit(&scc_PhysicalValueTmp, DC_EVSEChargeParameterPtr->EVSEMaximumPowerLimitFlag);

          /* DC_EVSEChargeParameter -> EVSEMaximumVoltageLimit */
          Scc_Conv_DIN2Scc_PhysicalValue(DC_EVSEChargeParameterPtr->EVSEMaximumVoltageLimit, &scc_PhysicalValueTmp);
          Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMaximumVoltageLimit(&scc_PhysicalValueTmp, 1);


          /* DC_EVSEChargeParameter -> EVSEMinimumCurrentLimit */
          Scc_Conv_DIN2Scc_PhysicalValue(DC_EVSEChargeParameterPtr->EVSEMinimumCurrentLimit, &scc_PhysicalValueTmp);
          Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMinimumCurrentLimit(&scc_PhysicalValueTmp);

          /* DC_EVSEChargeParameter -> EVSEMinimumVoltageLimit */
          Scc_Conv_DIN2Scc_PhysicalValue(DC_EVSEChargeParameterPtr->EVSEMinimumVoltageLimit, &scc_PhysicalValueTmp);
          Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMinimumVoltageLimit(&scc_PhysicalValueTmp);

          /* DC_EVSEChargeParameter -> EVSECurrentRegulationTolerance */
          Scc_Conv_DIN2Scc_PhysicalValue(DC_EVSEChargeParameterPtr->EVSECurrentRegulationTolerance, &scc_PhysicalValueTmp);
          Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSECurrentRegulationTolerance(&scc_PhysicalValueTmp, DC_EVSEChargeParameterPtr->EVSECurrentRegulationToleranceFlag);

          /* DC_EVSEChargeParameter -> EVSEPeakCurrentRipple */
          Scc_Conv_DIN2Scc_PhysicalValue(DC_EVSEChargeParameterPtr->EVSEPeakCurrentRipple, &scc_PhysicalValueTmp);
          Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPeakCurrentRipple(&scc_PhysicalValueTmp);

          /* DC_EVSEChargeParameter -> EVSEEnergyToBeDelivered */
          Scc_Conv_DIN2Scc_PhysicalValue(DC_EVSEChargeParameterPtr->EVSEEnergyToBeDelivered, &scc_PhysicalValueTmp);
          Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEEnergyToBeDelivered(&scc_PhysicalValueTmp, DC_EVSEChargeParameterPtr->EVSEEnergyToBeDeliveredFlag);
        }

        retVal = E_OK;

        /* #40 only further verify the message when EVSEProcessing is set to Finished */
        if ( EXI_DIN_EVSEPROCESSING_TYPE_FINISHED == BodyPtr->EVSEProcessing )
        {
          /* check if the parameter was sent by the EVSE */
          if ( 0u == DC_EVSEChargeParameterPtr->EVSEMaximumPowerLimitFlag )
          {
#if ( defined SCC_EVSE_COMP_IGNORE_MAXIMUM_POWER_LIMIT ) && ( SCC_EVSE_COMP_IGNORE_MAXIMUM_POWER_LIMIT == STD_ON )      /* PRQA S 3332 */ /* MD_Scc_3332 */
#else
            Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Din_ChargeParameterDiscoveryResMissingEvsemaximumpowerlimitParameter);
            retVal = E_NOT_OK;
#endif /* SCC_EVSE_COMP_IGNORE_MAXIMUM_POWER_LIMIT */
          }
        }

        if ( retVal == E_OK )                                                                                           /* PRQA S 2991,2995 */ /* MD_Scc_2742_2880_2991_2995 */
        {
          /* ResponseCode */
          Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
        }
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_PowerDeliveryRes
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_PowerDeliveryRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_DIN_POWER_DELIVERY_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Din_PowerDeliveryResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_DIN_PowerDeliveryResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_DIN_PowerDeliveryResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;


    /* #20 Check if the response is negative. */
    if ( EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Din_PowerDeliveryResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */

      /* check if the EVSEStatus contains an DC_EVSEStatus */
      if ( EXI_DIN_DC_EVSESTATUS_TYPE != BodyPtr->EVSEStatusElementId )
      {
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Din_PowerDeliveryResDcEvsestatusElemIdInvalid);
      }
      else
      {
        /* DC_EVSEStatus */
        Scc_DIN70121_ExiRx_ReadEVSEStatusDC((P2VAR(Exi_DIN_DC_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA))BodyPtr->EVSEStatus); /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */

        /* ResponseCode */
        Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);

        retVal = E_OK;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_SessionStopRes
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_SessionStopRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
  P2CONST(Exi_DIN_SessionStopResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
    (P2CONST(Exi_DIN_SessionStopResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_DIN_SESSION_STOP_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Din_SessionStopResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* #20 Check if the response is negative. */
    if ( EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Din_SessionStopResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */
      /* ResponseCode */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);

      retVal = Scc_ReturnType_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_CableCheckRes
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_CableCheckRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_DIN_CABLE_CHECK_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Din_CableCheckResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_DIN_CableCheckResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_DIN_CableCheckResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;


    /* #20 Check if the response is negative. */
    if ( EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Din_CableCheckResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */

      /* EVSEProcessing */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEProcessing(BodyPtr->EVSEProcessing);

    #if ( SCC_ENABLE_ONGOING_CALLBACKS ) && ( SCC_ENABLE_ONGOING_CALLBACKS == STD_ON )
    #else
      /* only update the values when EVSEProcessing is set to Finished */
      if ( EXI_DIN_EVSEPROCESSING_TYPE_FINISHED == BodyPtr->EVSEProcessing )
    #endif
      {
        /* DC_EVSEStatus */
        Scc_DIN70121_ExiRx_ReadEVSEStatusDC((P2VAR(Exi_DIN_DC_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA))BodyPtr->DC_EVSEStatus);
      }

      /* ResponseCode */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_PreChargeRes
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_PreChargeRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Scc_PhysicalValueType scc_PhysicalValueTmp;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_DIN_PRE_CHARGE_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Din_PrechargeResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_DIN_PreChargeResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_DIN_PreChargeResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;


    /* #20 Check if the response is negative. */
    if ( EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Din_PrechargeResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */

      /* DC_EVSEStatus */
      Scc_DIN70121_ExiRx_ReadEVSEStatusDC((P2VAR(Exi_DIN_DC_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA))BodyPtr->DC_EVSEStatus);

      /* EVSEPresentVoltage */
      Scc_Conv_DIN2Scc_PhysicalValue(BodyPtr->EVSEPresentVoltage, &scc_PhysicalValueTmp);
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPresentVoltage(&scc_PhysicalValueTmp);

      /* ResponseCode */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_CurrentDemandRes
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_CurrentDemandRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Scc_PhysicalValueType scc_PhysicalValueTmp;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_DIN_CURRENT_DEMAND_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Din_CurrentDemandResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_DIN_CurrentDemandResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_DIN_CurrentDemandResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;


    /* #20 Check if the response is negative. */
    if ( EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Din_CurrentDemandResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */

      /* DC_EVSEStatus */
      Scc_DIN70121_ExiRx_ReadEVSEStatusDC((P2VAR(Exi_DIN_DC_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA))BodyPtr->DC_EVSEStatus);

      /* EVSEPresentVoltage */
      Scc_Conv_DIN2Scc_PhysicalValue(BodyPtr->EVSEPresentVoltage, &scc_PhysicalValueTmp);
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPresentVoltage(&scc_PhysicalValueTmp);

      /* EVSEPresentCurrent */
      Scc_Conv_DIN2Scc_PhysicalValue(BodyPtr->EVSEPresentCurrent, &scc_PhysicalValueTmp);
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPresentCurrent(&scc_PhysicalValueTmp);

      /* EVSECurrentLimitAchieved */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSECurrentLimitAchieved(BodyPtr->EVSECurrentLimitAchieved);

      /* EVSEVoltageLimitAchieved */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEVoltageLimitAchieved(BodyPtr->EVSEVoltageLimitAchieved);

      /* EVSEPowerLimitAchieved */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPowerLimitAchieved(BodyPtr->EVSEPowerLimitAchieved);

      /* EVSEMaximumVoltageLimit */
      Scc_Conv_DIN2Scc_PhysicalValue(BodyPtr->EVSEMaximumVoltageLimit, &scc_PhysicalValueTmp);
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMaximumVoltageLimit(&scc_PhysicalValueTmp, BodyPtr->EVSEMaximumVoltageLimitFlag);

      /* EVSEMaximumCurrentLimit */
      Scc_Conv_DIN2Scc_PhysicalValue(BodyPtr->EVSEMaximumCurrentLimit, &scc_PhysicalValueTmp);
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMaximumCurrentLimit(&scc_PhysicalValueTmp, BodyPtr->EVSEMaximumCurrentLimitFlag);

      /* EVSEMaximumPowerLimit */
      Scc_Conv_DIN2Scc_PhysicalValue(BodyPtr->EVSEMaximumPowerLimit, &scc_PhysicalValueTmp);
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMaximumPowerLimit(&scc_PhysicalValueTmp, BodyPtr->EVSEMaximumPowerLimitFlag);

      /* ResponseCode */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_WeldingDetectionRes
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_WeldingDetectionRes(P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Scc_PhysicalValueType scc_PhysicalValueTmp;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_DIN_WELDING_DETECTION_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Din_WeldingDetectionResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_DIN_WeldingDetectionResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_DIN_WeldingDetectionResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;


    /* #20 Check if the response is negative. */
    if ( EXI_DIN_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Din_WeldingDetectionResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */

      /* DC_EVSEStatus */
      Scc_DIN70121_ExiRx_ReadEVSEStatusDC((P2VAR(Exi_DIN_DC_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA))BodyPtr->DC_EVSEStatus);

      /* EVSEPresentVoltage */
      Scc_Conv_DIN2Scc_PhysicalValue(BodyPtr->EVSEPresentVoltage, &scc_PhysicalValueTmp);
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPresentVoltage(&scc_PhysicalValueTmp);

      /* ResponseCode */
      Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiRx_ReadEVSEStatusDC
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_DIN70121_ExiRx_ReadEVSEStatusDC(P2CONST(Exi_DIN_DC_EVSEStatusType, AUTOMATIC, SCC_VAR_NOINIT) EVSEStatusPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Report the parameter from the response to the application. */
  /* EVSEIsolationStatus */
  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEIsolationStatus(EVSEStatusPtr->EVSEIsolationStatus, EVSEStatusPtr->EVSEIsolationStatusFlag);
  /* EVSEStatusCode */
  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEStatusCode(EVSEStatusPtr->EVSEStatusCode);
  /* NotificationMaxDelay */
  Scc_DIN70121_InterfaceCfg_ExiRx_Set_NotificationMaxDelay(EVSEStatusPtr->NotificationMaxDelay);
  /* EVSENotification */
  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSENotification(EVSEStatusPtr->EVSENotification);
}

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/
/* PRQA L:NEST_STRUCTS */
/* PRQA L:RETURN_PATHS */

#endif /* SCC_SCHEMA_DIN */

/*lint +e546 */ /* Enable the 'Suspicious use of &' reporting again. */

/**********************************************************************************************************************
 *  END OF FILE: Scc_DIN70121_ExiRx.c
 *********************************************************************************************************************/
