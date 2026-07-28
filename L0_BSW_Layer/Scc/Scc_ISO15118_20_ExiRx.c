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
/*!        \file  Scc_ISO15118_20_ExiRx.c
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

#define SCC_ISO15118_20_EXIRX_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
/*lint -e546 */ /* Suppress the 'Suspicious use of &' warning because the '&' is required by MISRA per Id 1502. */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )
#include "Scc_ISO15118_20_Exi.h"
#include "Scc_ISO15118_20CM_Exi.h"
#include "Scc_Priv.h"
#include "Scc_ExiRx_Common.h"
#include "Scc.h"
#include "Scc_Core_Channel.h"

#if ( SCC_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */

#if (SCC_IDSM_REPORT == STD_ON)
# include "IdsM.h"
#endif
#include "IpBase.h"

#if (defined SCC_SCHEMA_ISO_20AC) && (SCC_SCHEMA_ISO_20AC != 0)
# include "Scc_ISO15118_20AC_Exi.h"
#endif

#if (defined SCC_SCHEMA_ISO_20DC) && (SCC_SCHEMA_ISO_20DC != 0)
# include "Scc_ISO15118_20DC_Exi.h"
#endif

#if (defined SCC_SCHEMA_ISO_20WPT) && (SCC_SCHEMA_ISO_20WPT != 0)
# include "Scc_ISO15118_20WPT_Exi.h"
#endif

#if (defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0)
# include "Scc_ISO15118_20ACDP_Exi.h"
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
#define SCC_START_SEC_CONST_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* [V2G20-2307] */
#if ( defined SCC_SCHEMA_ISO_20AC ) && ( SCC_SCHEMA_ISO_20AC != 0 )
SCC_LOCAL CONST(uint16, SCC_CONST) Scc_ISO15118_20_ExiRx_SupportedPayloadTypesAC[] = {                                  /* PRQA S 3218 */ /* MD_Scc_3218 */
  (uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_CM
  ,(uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_AC
#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
  ,(uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_RENEGOTIATION
#endif
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
  ,(uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_METERING_RECEIPT
#endif
};
#endif /* SCC_SCHEMA_ISO_20AC */

/* [V2G20-2307] */
#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
SCC_LOCAL CONST(uint16, SCC_CONST) Scc_ISO15118_20_ExiRx_SupportedPayloadTypesDC[] = {                                  /* PRQA S 3218 */ /* MD_Scc_3218 */
  (uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_CM
  ,(uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_DC
#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
  ,(uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_RENEGOTIATION
#endif
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
  ,(uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_METERING_RECEIPT
#endif
};
#endif /* SCC_SCHEMA_ISO_20DC */

#if ( ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 ) )
SCC_LOCAL CONST(uint16, SCC_CONST) Scc_ISO15118_20_ExiRx_SupportedPayloadTypesWPT[] = {                                 /* PRQA S 3218 */ /* MD_Scc_3218 */
  (uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_CM
  ,(uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_WPT
#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
  ,(uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_RENEGOTIATION
#endif
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
  ,(uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_METERING_RECEIPT
#endif
};
#endif /* SCC_SCHEMA_ISO_20WPT */

#if ( ( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ) )
SCC_LOCAL CONST(uint16, SCC_CONST) Scc_ISO15118_20_ExiRx_SupportedPayloadTypesACDP[] = {                                /* PRQA S 3218 */ /* MD_Scc_3218 */
  (uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_CM
  ,(uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_ACDP
  ,(uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_DC
#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
  ,(uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_RENEGOTIATION
#endif
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
  ,(uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_METERING_RECEIPT
#endif
#if ( defined SCC_ENABLE_ACDP_SYSTEM_STATUS ) && ( SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON )
  ,(uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_ACDP_SYSTEM_STATUS
#endif
};
#endif /* SCC_SCHEMA_ISO_20ACDP */

#define SCC_STOP_SEC_CONST_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_ISO15118_20_ExiRx_DecodeMessage
 *********************************************************************************************************************/
/*! \brief          Decodes EXI streams
 *  \details        -
 *  \param[in]      V2GTpHeaderPtr              Pointer to a v2gtp header
 *  \param[in]      RxMsgWSPtr                  Pointer to the Rx message workspace
 *  \return         Scc_ReturnType_OK           Exi decode was successful
 *  \return         Scc_ReturnType_NotOK        Exi decode was not successful or timeout happened
 *  \return         Scc_ReturnType_Pending      Message handling is pending, try again later
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20_ExiRx_DecodeMessage(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_ExiRx_SetupRxConfig
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
FUNC(void, SCC_CODE) Scc_ISO15118_20_ExiRx_SetupRxConfig(
  P2VAR(Scc_RxConfigStructType, AUTOMATIC, SCC_APPL_DATA) RxConfigPtr,
  Scc_SAPSchemaIDType SapSchemaID)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Setup the passed Rx configuration structure */
  RxConfigPtr->DecodePrepareFct = &Scc_ISO15118_20_ExiRx_DecodeMessagePrepare;
  RxConfigPtr->DecodeFct = &Scc_ISO15118_20_ExiRx_DecodeMessage;
  RxConfigPtr->PropagteMessage = TRUE;

  /* #20 If AC is enabled, Check if AC is chosen by the EVSE */
#if ( defined SCC_SCHEMA_ISO_20AC ) && ( SCC_SCHEMA_ISO_20AC != 0 )
  if (SapSchemaID == Scc_SAPSchemaIDs_ISO15118_20AC)
  {
    /* #30 Set AC supported payload types */
    RxConfigPtr->SupportedPayloadTypeList = &Scc_ISO15118_20_ExiRx_SupportedPayloadTypesAC[0];
    RxConfigPtr->SupportedPayloadTypeListLen = sizeof(Scc_ISO15118_20_ExiRx_SupportedPayloadTypesAC) / sizeof(Scc_ISO15118_20_ExiRx_SupportedPayloadTypesAC[0]);
  }
#endif /* SCC_SCHEMA_ISO_20AC */
  /* #40 If DC is enabled, Check if DC is chosen by the EVSE */
#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
  if (SapSchemaID == Scc_SAPSchemaIDs_ISO15118_20DC)
  {
    /* #50 Set DC supported payload types */
    RxConfigPtr->SupportedPayloadTypeList = &Scc_ISO15118_20_ExiRx_SupportedPayloadTypesDC[0];
    RxConfigPtr->SupportedPayloadTypeListLen = sizeof(Scc_ISO15118_20_ExiRx_SupportedPayloadTypesDC) / sizeof(Scc_ISO15118_20_ExiRx_SupportedPayloadTypesDC[0]);
  }
#endif /* SCC_SCHEMA_ISO_20DC */
  /* #60 If WPT is enabled, Check if WPT is chosen by the EVSE */
#if ( ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 ) )
  if (SapSchemaID == Scc_SAPSchemaIDs_ISO15118_20WPT)
  {
    /* #70 Set WPT supported payload types */
    RxConfigPtr->SupportedPayloadTypeList = &Scc_ISO15118_20_ExiRx_SupportedPayloadTypesWPT[0];
    RxConfigPtr->SupportedPayloadTypeListLen = sizeof(Scc_ISO15118_20_ExiRx_SupportedPayloadTypesWPT) / sizeof(Scc_ISO15118_20_ExiRx_SupportedPayloadTypesWPT[0]);
  }
#endif /* SCC_SCHEMA_ISO_20WPT */
  /* #80 If ACDP is enabled, Check if ACDP is choosen by the EVSE */
#if ( ( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ) )
  if (SapSchemaID == Scc_SAPSchemaIDs_ISO15118_20ACDP)
  {
    /* #90 Set ACDP supported payload types */
    RxConfigPtr->SupportedPayloadTypeList = &Scc_ISO15118_20_ExiRx_SupportedPayloadTypesACDP[0];
    RxConfigPtr->SupportedPayloadTypeListLen = sizeof(Scc_ISO15118_20_ExiRx_SupportedPayloadTypesACDP) / sizeof(Scc_ISO15118_20_ExiRx_SupportedPayloadTypesACDP[0]);
  }
#endif /* SCC_SCHEMA_ISO_20ACDP */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_ExiRx_CheckSessionId
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
FUNC(Std_ReturnType, SCC_CODE) Scc_ISO15118_20_ExiRx_CheckSessionId(
  P2CONST(Exi_ISO_20_CT_10_sessionIDType, AUTOMATIC, SCC_APPL_DATA) SessionIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 [V2G20-747] Check the SessionID starting from ServiceDiscovery */
  if (Scc_MsgTrig_SessionSetup < Scc_Core_Channel_Get_MsgTrig())
  {
    /* #20 Compare the length of the stored and received SessionID */
    if (SessionIdPtr->Length == Scc_SessionIDNvm[0])
    {
      /* #30 If the length is the same, check if the content is the same, too */
      if (IPBASE_CMP_EQUAL != IpBase_StrCmpLen(&SessionIdPtr->Buffer[0],
        &Scc_SessionIDNvm[1], Scc_SessionIDNvm[0]))
      {
        /* #40 SessionID is not equal, report the error */
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CheckSessionIdSessionIdInvalid);
      }
      /* #50 Otherwise return Ok */
      else
      {
        retVal = E_OK;
      }
    }
    /* #60 Otherwise length is not the same */
    else
    {
      /* #70 Report the error */
      Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CheckSessionIdSessionIdLenInvalid);
    }
  }
  /* #80 Otherwise return Ok */
  else
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_ExiRx_DecodeMessagePrepare
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
 */
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20_ExiRx_DecodeMessagePrepare(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Dispatch the decoding prepare based on the payload type of the header */
  switch (V2GTpHeaderPtr->PayloadType)
  {
  case SCC_V2GTP_HDR_PAYLOAD_TYPE_CM:
    /* #20 Dispatch to CM schema specific function */
    retVal = Scc_ISO15118_20CM_ExiRx_DecodeMessagePrepare(RxMsgWSPtr);
    break;

#if (defined(SCC_SCHEMA_ISO_20AC) && (SCC_SCHEMA_ISO_20AC != 0u))
    /* #30 If SCC_SCHEMA_ISO_20AC enabled: */
  case SCC_V2GTP_HDR_PAYLOAD_TYPE_AC:
    /* #40 Dispatch to AC schema specific function */
    retVal = Scc_ISO15118_20AC_ExiRx_DecodeMessagePrepare(RxMsgWSPtr);
    break;
#endif /* SCC_SCHEMA_ISO_20AC */

#if (defined(SCC_SCHEMA_ISO_20DC) && (SCC_SCHEMA_ISO_20DC != 0u))
    /* #50 If SCC_SCHEMA_ISO_20DC enabled: */
  case SCC_V2GTP_HDR_PAYLOAD_TYPE_DC:
    /* #60 Dispatch to DC schema specific function */
    retVal = Scc_ISO15118_20DC_ExiRx_DecodeMessagePrepare(RxMsgWSPtr);
    break;
#endif /* SCC_SCHEMA_ISO_20DC */

#if (defined(SCC_SCHEMA_ISO_20WPT) && (SCC_SCHEMA_ISO_20WPT != 0u))
    /* #70 If SCC_SCHEMA_ISO_20WPT enabled: */
  case SCC_V2GTP_HDR_PAYLOAD_TYPE_WPT:
    /* #80 Dispatch to WPT schema specific function */
    retVal = Scc_ISO15118_20WPT_ExiRx_DecodeMessagePrepare(RxMsgWSPtr);
    break;
#endif /* SCC_SCHEMA_ISO_20WPT */

#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
    /* #90 If SCC_SCHEMA_ISO_20ACDP enabled: */
  case SCC_V2GTP_HDR_PAYLOAD_TYPE_ACDP:
    /* #100 Dispatch to ACDP schema specific function */
    retVal = Scc_ISO15118_20ACDP_ExiRx_DecodeMessagePrepare(RxMsgWSPtr);
    break;
#endif /* SCC_SCHEMA_ISO_20ACDP */

#if (defined(SCC_ENABLE_RENEGOTIATION_CHANNEL) && (SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON))
    /* #110 If renegotiation channel is enabled: */
  case SCC_V2GTP_HDR_PAYLOAD_TYPE_RENEGOTIATION:
  {
    /* #120 Handle an incoming response message */
    switch (Scc_Core_Channel_Get_MsgTrig())
    {
      /* #130 Handle an incoming charge parameter discovery response message */
    case Scc_MsgTrig_ChargeParameterDiscovery:
    {
      Scc_ISO15118_20_ServiceIDType serviceId = Scc_ISO15118_20CM_ExiTx_Get_SelectedEnergyTransferServiceID();
      switch (serviceId)
      {
        /* #140 If SCC_SCHEMA_ISO_20AC or SCC_CHARGING_BPT enabled: */
#if (defined(SCC_SCHEMA_ISO_20AC) && (SCC_SCHEMA_ISO_20AC != 0u))
      case Scc_ISO15118_20_SID_AC:
# if (defined(SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON))
      case Scc_ISO15118_20_SID_AC_BPT:
# endif
        /* #150 Dispatch to AC schema specific function */
        retVal = Scc_ISO15118_20AC_ExiRx_DecodeMessagePrepare(RxMsgWSPtr);
        break;
#endif /* SCC_SCHEMA_ISO_20AC */
        /* #160 If SCC_SCHEMA_ISO_20DC or SCC_CHARGING_BPT enabled: */
#if (defined(SCC_SCHEMA_ISO_20DC) && (SCC_SCHEMA_ISO_20DC != 0u))
      case Scc_ISO15118_20_SID_DC:
# if (defined(SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON))
      case Scc_ISO15118_20_SID_DC_BPT:
# endif
#if ( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 )
        /* #170 If Scc_ISO15118_20_SID_DC_ACDP enabled: */
      case Scc_ISO15118_20_SID_DC_ACDP:
# if (defined(SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON))
      case Scc_ISO15118_20_SID_DC_ACDP_BPT:
# endif /* SCC_CHARGING_BPT */
#endif /* SCC_SCHEMA_ISO_20ACDP */
        /* #180 Dispatch to DC schema specific function */
        retVal = Scc_ISO15118_20DC_ExiRx_DecodeMessagePrepare(RxMsgWSPtr);
        break;
#endif /* SCC_SCHEMA_ISO_20DC */
#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
        /* #190 If Scc_ISO15118_20_SID_WPT enabled: */
      case Scc_ISO15118_20_SID_WPT:
        /* #200 Dispatch to WPT schema specific function */
        retVal = Scc_ISO15118_20WPT_ExiRx_DecodeMessagePrepare(RxMsgWSPtr);
        break;
#endif /* SCC_SCHEMA_ISO_20WPT */
      default:
        Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_DecodeMessagePrepareInvalidPayloadTypeChargeParam);
#if (SCC_IDSM_REPORT == STD_ON)
        IdsM_SetSecurityEvent(SCC_IDSMEVENT_V2GTPHEADER_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
        break;
      }
    }
    break;
    /* #210 Handle an incoming ScheduleExchange or PowerDelivery response message */
    case Scc_MsgTrig_ScheduleExchange:
    case Scc_MsgTrig_PowerDelivery:
      /* #220 Dispatch to CM schema specific function */
      retVal = Scc_ISO15118_20CM_ExiRx_DecodeMessagePrepare(RxMsgWSPtr);
      break;
    default:
      Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_DecodeMessagePrepareInvalidPayloadTypePowerDelivery);
#if (SCC_IDSM_REPORT == STD_ON)
      IdsM_SetSecurityEvent(SCC_IDSMEVENT_V2GTPHEADER_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
      break;
    }
  }
  break;
#endif /* SCC_ENABLE_RENEGOTIATION_CHANNEL */

#if (defined(SCC_ENABLE_METERING_RECEIPT) && (SCC_ENABLE_METERING_RECEIPT == STD_ON))
  /* #230 [V2G20-1085] If metering receipt is enabled: */
  case SCC_V2GTP_HDR_PAYLOAD_TYPE_METERING_RECEIPT:
  {
    /* #240 Handle an incoming response message */
    switch (Scc_Core_Channel_Get_MsgTrig())
    {
      /* #250 Handle an incoming MeteringReceipt response message */
    case Scc_MsgTrig_MeteringReceipt:
      /* #260 Dispatch to CM schema specific function */
      retVal = Scc_ISO15118_20CM_ExiRx_DecodeMessagePrepare(RxMsgWSPtr);
      break;
    default:
      Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_DecodeMessagePrepareInvalidPayloadTypeMeteringReceipt);
#if (SCC_IDSM_REPORT == STD_ON)
      IdsM_SetSecurityEvent(SCC_IDSMEVENT_V2GTPHEADER_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
      break;
    }
  }
  break;
#endif /* SCC_ENABLE_METERING_RECEIPT */

#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
# if (defined(SCC_ENABLE_ACDP_SYSTEM_STATUS) && (SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON))
  /* #270 If SystemStatus is enabled: */
  case SCC_V2GTP_HDR_PAYLOAD_TYPE_ACDP_SYSTEM_STATUS:
  {
    /* #280 Handle an incoming response message */
    switch (Scc_Core_Channel_Get_MsgTrig())
    {
      /* #290 Handle an incoming SystemStatus response message */
    case Scc_MsgTrig_ACDP_SystemStatus:
      /* #300 Dispatch to CM schema specific function */
      retVal = Scc_ISO15118_20ACDP_ExiRx_DecodeMessagePrepare(RxMsgWSPtr);
      break;
    default:
      Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_DecodeMessagePrepareInvalidPayloadTypeSystemStatus);
#  if (SCC_IDSM_REPORT == STD_ON)
      IdsM_SetSecurityEvent(SCC_IDSMEVENT_V2GTPHEADER_INVALID);
#  endif /* SCC_IDSM_REPORT == STD_ON */
      break;
    }
  }
  break;
# endif /* SCC_ENABLE_ACDP_SYSTEM_STATUS */
#endif /* SCC_SCHEMA_ISO_20ACDP */

  default:
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_DecodeMessagePrepareInvalidPayloadType);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_V2GTPHEADER_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
    break;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_ExiRx_DecodeMessage
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
 */
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20_ExiRx_DecodeMessage(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;


  /* ----- Implementation ----------------------------------------------- */
#if (defined(SCC_EVSE_COMP_ALLOW_BIGGER_PAYLOAD) && (SCC_EVSE_COMP_ALLOW_BIGGER_PAYLOAD == STD_ON))
  /* Do not perform the length check as too big payload information in header should be ignored */
#else
  /* The payload type is already checked during reception of the V2G message */
  /* #10 Check if the payload length is invalid */
  if (RxMsgWSPtr->Exi_DecWs.DecWs.TotalStreamLength != V2GTpHeaderPtr->PayloadLength)
  {
    /* The payload length is wrong the message is going to be ignored */
    /* [V2G20-094], [V2G20-800] */
    retVal = Scc_ReturnType_InvalidPayloadLen;
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_V2GTPHEADER_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #20 Otherwise */
  else
#endif /* SCC_EVSE_COMP_ALLOW_BIGGER_PAYLOAD */
  {
    /* #30 Dispatch the decoding based on the payload type of the header */
    switch (V2GTpHeaderPtr->PayloadType)
    {
      case SCC_V2GTP_HDR_PAYLOAD_TYPE_CM:
        /* #40 Dispatch to CM schema specific function */
        retVal = Scc_ISO15118_20CM_ExiRx_DecodeMessage(RxMsgWSPtr);
        break;

#if (defined(SCC_SCHEMA_ISO_20AC) && (SCC_SCHEMA_ISO_20AC != 0u))
      /* #50 If SCC_SCHEMA_ISO_20AC enabled: */
      case SCC_V2GTP_HDR_PAYLOAD_TYPE_AC:
        /* #60 Dispatch to AC schema specific function */
        retVal = Scc_ISO15118_20AC_ExiRx_DecodeMessage(RxMsgWSPtr);
        break;
#endif /* SCC_SCHEMA_ISO_20AC */

#if (defined(SCC_SCHEMA_ISO_20DC) && (SCC_SCHEMA_ISO_20DC != 0u))
        /* #70 If SCC_SCHEMA_ISO_20DC enabled: */
      case SCC_V2GTP_HDR_PAYLOAD_TYPE_DC:
        /* #80 Dispatch to DC schema specific function */
        retVal = Scc_ISO15118_20DC_ExiRx_DecodeMessage(RxMsgWSPtr);
        break;
#endif /* SCC_SCHEMA_ISO_20DC */

#if (defined(SCC_SCHEMA_ISO_20WPT) && (SCC_SCHEMA_ISO_20WPT != 0u))
        /* #90 If SCC_SCHEMA_ISO_20WPT enabled: */
      case SCC_V2GTP_HDR_PAYLOAD_TYPE_WPT:
        /* #100 Dispatch to WPT schema specific function */
        retVal = Scc_ISO15118_20WPT_ExiRx_DecodeMessage(RxMsgWSPtr);
        break;
#endif /* SCC_SCHEMA_ISO_20WPT */

#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
# if defined SCC_ENABLE_ACDP_SYSTEM_STATUS
      case SCC_V2GTP_HDR_PAYLOAD_TYPE_ACDP_SYSTEM_STATUS:
# endif /* SCC_ENABLE_ACDP_SYSTEM_STATUS */
        /* #110 If SCC_SCHEMA_ISO_20ACDP enabled: */
      case SCC_V2GTP_HDR_PAYLOAD_TYPE_ACDP:
        /* #120 Dispatch to ACDP schema specific function */
        retVal = Scc_ISO15118_20ACDP_ExiRx_DecodeMessage(RxMsgWSPtr);
        break;
#endif /* SCC_SCHEMA_ISO_20ACDP */

#if (defined(SCC_ENABLE_RENEGOTIATION_CHANNEL) && (SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON))
        /* #130 If Renegotiation channel enabled: */
      case SCC_V2GTP_HDR_PAYLOAD_TYPE_RENEGOTIATION:
      {
        /* #140 Handle an incoming response message */
        switch (Scc_Core_Channel_Get_MsgTrig())
        {
        /* #150 Handle an incoming charge parameter discovery response message */
        case Scc_MsgTrig_ChargeParameterDiscovery:
        {
          Scc_ISO15118_20_ServiceIDType serviceId = Scc_ISO15118_20CM_ExiTx_Get_SelectedEnergyTransferServiceID();
          switch (serviceId)
          {
#if (defined(SCC_SCHEMA_ISO_20AC) && (SCC_SCHEMA_ISO_20AC != 0u))
            /* #160 If SCC_SCHEMA_ISO_20AC enabled: */
          case Scc_ISO15118_20_SID_AC:
# if (defined(SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON))
          case Scc_ISO15118_20_SID_AC_BPT:
# endif
            /* #170 Dispatch to AC schema specific function */
            retVal = Scc_ISO15118_20AC_ExiRx_DecodeMessage(RxMsgWSPtr);
            break;
#endif /* SCC_SCHEMA_ISO_20AC */
#if (defined(SCC_SCHEMA_ISO_20DC) && (SCC_SCHEMA_ISO_20DC != 0u))
            /* #180 If SCC_SCHEMA_ISO_20DC enabled: */
          case Scc_ISO15118_20_SID_DC:
#if (defined(SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON))
          case Scc_ISO15118_20_SID_DC_BPT:
#endif
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0))
          case Scc_ISO15118_20_SID_DC_ACDP:
# if (defined(SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON))
          case Scc_ISO15118_20_SID_DC_ACDP_BPT:
# endif /* SCC_CHARGING_BPT */
#endif
            /* #190 Dispatch to DC schema specific function */
            retVal = Scc_ISO15118_20DC_ExiRx_DecodeMessage(RxMsgWSPtr);
            break;
#endif /* SCC_SCHEMA_ISO_20DC */
#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
            /* #200 If Scc_ISO15118_20_SID_WPT enabled */
          case Scc_ISO15118_20_SID_WPT:
            /* #210 Dispatch to WPT schema specific function */
            retVal = Scc_ISO15118_20WPT_ExiRx_DecodeMessage(RxMsgWSPtr);
            break;
#endif /* SCC_SCHEMA_ISO_20WPT */
          default:
            Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_DecodeMessageInvalidPayloadTypeChargeParam);
#if (SCC_IDSM_REPORT == STD_ON)
            IdsM_SetSecurityEvent(SCC_IDSMEVENT_V2GTPHEADER_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
            break;
          }
        }
        break;
        /* #220 Handle an incoming ScheduleExchange or PowerDelivery response message */
        case Scc_MsgTrig_ScheduleExchange:
        case Scc_MsgTrig_PowerDelivery:
          /* #230 Dispatch to CM schema specific function */
          retVal = Scc_ISO15118_20CM_ExiRx_DecodeMessage(RxMsgWSPtr);
          break;
        default:
          Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_DecodeMessageInvalidPayloadTypePowerDelivery);
#if (SCC_IDSM_REPORT == STD_ON)
          IdsM_SetSecurityEvent(SCC_IDSMEVENT_V2GTPHEADER_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
          break;
        }
      }
      break;
#endif /* SCC_ENABLE_RENEGOTIATION_CHANNEL */

#if (defined(SCC_ENABLE_METERING_RECEIPT) && (SCC_ENABLE_METERING_RECEIPT == STD_ON))
      /* #240 [V2G20-1085] If metering receipt enabled: */
      case SCC_V2GTP_HDR_PAYLOAD_TYPE_METERING_RECEIPT:
      {
        /* #250 Handle an incoming response message */
        switch (Scc_Core_Channel_Get_MsgTrig())
        {
        /* #260 Handle an incoming MeteringReceipt response message */
        case Scc_MsgTrig_MeteringReceipt:
          /* #270 Dispatch to CM schema specific function */
          retVal = Scc_ISO15118_20CM_ExiRx_DecodeMessage(RxMsgWSPtr);
          break;
        default:
          Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_DecodeMessageInvalidPayloadTypeMeteringReceipt);
#if (SCC_IDSM_REPORT == STD_ON)
          IdsM_SetSecurityEvent(SCC_IDSMEVENT_V2GTPHEADER_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
          break;
        }
      }
      break;
#endif /* SCC_ENABLE_METERING_RECEIPT */

      default:
        Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_DecodeMessageInvalidPayloadType);
#if (SCC_IDSM_REPORT == STD_ON)
        IdsM_SetSecurityEvent(SCC_IDSMEVENT_V2GTPHEADER_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
        break;
    }
  }

  return retVal;
}

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SCHEMA_ISO_20 */

/*lint +e546 */ /* Enable the 'Suspicious use of &' reporting again. */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20_ExiRx.c
 *********************************************************************************************************************/
