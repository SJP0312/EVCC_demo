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
/*!        \file  Scc_ISO15118_20WPT_ExiTx.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to the specifications ISO/IEC 15118-20 WPT schema
 *                specific parts.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_ISO15118_20WPT_EXITX_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
#include "Scc_ISO15118_20_Exi.h"
#include "Scc_ISO15118_20WPT_Exi.h"
#include "Scc_ISO15118_20_InterfaceCfg.h"
#include "Scc_ISO15118_20_TimerCfg.h"
#include "Scc_Priv.h"
#include "Scc_Core_Channel.h"
#include "Scc_BufferPool.h"

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
 *  Scc_ISO15118_20WPT_ExiTx_<ISO15118-20-Request>
 *********************************************************************************************************************/
/*! \brief          Set all parameters for ISO15118-20 request message
 *  \details        Set all parameters for the body element of the request message.
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[out]     RootElementIdPtr        Pointer to the root element that needs to be set by the specialized message type.
 *  \return         Scc_ReturnType_OK       Message was created and written.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
/* See pattern Scc_ISO15118_20WPT_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiTx_WPT_FinePositioningSetupReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
/* See pattern Scc_ISO15118_20WPT_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiTx_WPT_FinePositioningReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
/* See pattern Scc_ISO15118_20WPT_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiTx_WPT_PairingReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
/* See pattern Scc_ISO15118_20WPT_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiTx_WPT_ChargeParameterDiscoveryReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
/* See pattern Scc_ISO15118_20WPT_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiTx_WPT_AlignmentCheckReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
/* See pattern Scc_ISO15118_20WPT_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiTx_WPT_ChargeLoopReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);


/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_ExiTx_PrepareMessageCreateMessage
 *********************************************************************************************************************/
/*! \brief          Creates the EXI request message to be transmitted.
 *  \details        -
 *  \param[in]      TxMsgWSPtr                  Pointer to the Tx message workspace.
 *  \return         Scc_ReturnType_OK           Exi preparation was successful.
 *  \return         Scc_ReturnType_NotOK        Exi preparation was not successful or timeout happened.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20WPT_ExiTx_PrepareMessageCreateMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_ExiTx_SAPSetEntry
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
FUNC(void, SCC_CODE) Scc_ISO15118_20WPT_ExiTx_SAPSetEntry(
  P2VAR(Exi_SAP_AppProtocolType, AUTOMATIC, SCC_APPL_DATA) AppProtocolPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* [V2G20-2132]  */
  /* #10 Copy the namespace string */
  /* PRQA S 0310,3305,0315 3 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy */
  IpBase_Copy(
    (P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&AppProtocolPtr->ProtocolNamespace->Buffer[0],
    (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))SCC_ISO15118_20WPT_EXI_SAP_PROTOCOL_NAMESPACE,
    SCC_ISO15118_20WPT_EXI_SAP_PROTOCOL_NAMESPACE_LEN);
  /* #20 Set namespace length */
  AppProtocolPtr->ProtocolNamespace->Length = SCC_ISO15118_20WPT_EXI_SAP_PROTOCOL_NAMESPACE_LEN;
  /* #30 Set VersionNumberMajor */
  AppProtocolPtr->VersionNumberMajor = SCC_ISO15118_20WPT_EXI_SAP_VERSION_NUMBER_MAJOR;
  /* #40 Set VersionNumberMinor */
  AppProtocolPtr->VersionNumberMinor = SCC_ISO15118_20WPT_EXI_SAP_VERSION_NUMBER_MINOR;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_ExiTx_PrepareMessage
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
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20WPT_ExiTx_PrepareMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  Scc_PoolBuffType poolBuffType = SCC_POOL_BUFF_LARGE;
  P2VAR(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                    Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if this is the initial step */
  if (TxMsgWSPtr->Step == SCC_MSGPROC_STEP_INIT)
  {
    uint8 bufferPoolId = 0;

    TxMsgWSPtr->BufIdx = 0;
    TxMsgWSPtr->RootElementId = 0;
    TxMsgWSPtr->payloadType = SCC_V2GTP_HDR_PAYLOAD_TYPE_WPT;

#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
    /* #20 Check if the message is ChargeLoop */
    if (Scc_Core_Channel_Get_MsgTrig() == Scc_MsgTrig_ChargeLoop)
    {
      /* #30 Change buffer type to Small */
      poolBuffType = SCC_POOL_BUFF_SMALL;
    }
#endif /* SCC_ENABLE_RENEGOTIATION_CHANNEL */

    /* #40 Get MsgPtr and MsgPtrSize */
    if (Scc_BufferPoolRequestGetBuffer(poolBuffType, &buffPoolWsPtr->MsgPtr, &buffPoolWsPtr->MsgPtrSize, &bufferPoolId) != E_OK)
    {
      /* Do nothing. Error already reported */
    }
    else
    {
      /* #50 Store the bufferPoolId */
      Scc_Core_Channel_Set_BufferPoolId(bufferPoolId);
      /* #60 Check if EXI alloc workspace can be initialized */
      if (Exi_InitMemAllocWorkspace(&TxMsgWSPtr->Exi_AllocWs, buffPoolWsPtr->MsgPtr, 0u, buffPoolWsPtr->MsgPtrSize) == EXI_E_OK)
      {
        /* #70 Continue */
        retVal = Scc_ReturnType_OK;
      }
      else
      {
        /* Do nothing */
      }
    }
  }
  else
  {
    retVal = Scc_ReturnType_OK;
  }

  if (retVal == Scc_ReturnType_OK)
  {
    retVal = Scc_ISO15118_20WPT_ExiTx_PrepareMessageCreateMessage(TxMsgWSPtr);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
 /**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_ExiTx_PrepareMessageCreateMessage
 *********************************************************************************************************************/
 /*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20WPT_ExiTx_PrepareMessageCreateMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* #10 Create request message and set MessageTimeout */
  switch (Scc_Core_Channel_Get_MsgTrig())
  {
    case Scc_MsgTrig_FinePositioningSetup:
    {
      retVal = Scc_ISO15118_20WPT_ExiTx_WPT_FinePositioningSetupReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
      if (retVal == Scc_ReturnType_OK)
      {
        /* [V2G20-5069]: Setup V2G_EVCC_Msg_Timeout */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_FinePositioningSetupMessageTimeout();
      }
      break;
    }
    case Scc_MsgTrig_FinePositioning:
    {
      retVal = Scc_ISO15118_20WPT_ExiTx_WPT_FinePositioningReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
      if (retVal == Scc_ReturnType_OK)
      {
        /* [V2G20-5069]: Setup V2G_EVCC_Msg_Timeout */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_FinePositioningMessageTimeout();
      }
      break;
    }
    case Scc_MsgTrig_Pairing:
    {
      retVal = Scc_ISO15118_20WPT_ExiTx_WPT_PairingReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
      if (retVal == Scc_ReturnType_OK)
      {
        /* [V2G20-5069]: Setup V2G_EVCC_Msg_Timeout */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_PairingMessageTimeout();
      }
      break;
    }
    case Scc_MsgTrig_ChargeParameterDiscovery:
    {
      retVal = Scc_ISO15118_20WPT_ExiTx_WPT_ChargeParameterDiscoveryReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
      if (retVal == Scc_ReturnType_OK)
      {
        /* Set the timeout based on currently active channel */
        const Scc_CoreChannelType currentChannel = Scc_Core_Channel_Get_CurrentChannel();
        switch (currentChannel)
        {
          /*  Default channel */
          case SCC_CHANNEL_DEFAULT:
          {
            /* Set timeout */
            /* [V2G20-434],[V2G20-436] Setup V2G_EVCC_Msg_Timeout */
            Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_ChargeParameterDiscoveryMessageTimeout();
            break;
          }
          /* If renegotiation channel is enabled, Renegotiation channel */
#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
          case SCC_CHANNEL_RENEGOTIATION:
          {
            /* Set timeout */
            /* [V2G20-434],[V2G20-436] Setup V2G_EVCC_Msg_Timeout */
            Scc_TimeoutCnt[SCC_CHANNEL_RENEGOTIATION] = (uint16)Scc_ISO15118_20_TimerCfg_Get_ChargeParameterDiscoveryMessageTimeout();
            /* [V2G20-1045] */
            TxMsgWSPtr->payloadType = SCC_V2GTP_HDR_PAYLOAD_TYPE_RENEGOTIATION;
            break;
          }
#endif /* SCC_ENABLE_RENEGOTIATION_CHANNEL */
          /* Otherwise: Error, unsupported channel */
          default:
            retVal = Scc_ReturnType_NotOK;
            break;
        }
      }
      break;
    }

    case Scc_MsgTrig_AlignmentCheck:
    {
      retVal = Scc_ISO15118_20WPT_ExiTx_WPT_AlignmentCheckReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
      if (retVal == Scc_ReturnType_OK)
      {
        /* [V2G20-5069]: Setup V2G_EVCC_Msg_Timeout */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_AlignmentCheckMessageTimeout();
      }
      break;
    }
    case Scc_MsgTrig_ChargeLoop:
    {
      retVal = Scc_ISO15118_20WPT_ExiTx_WPT_ChargeLoopReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);

      if (retVal == Scc_ReturnType_OK)
      {
        /* [V2G20-5069]: Setup V2G_EVCC_Msg_Timeout */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_ChargeLoopMessageTimeout();
        /* [V2G20-1846] If Renegotiation channel is enabled in configuration, then enable the channel to transmit messages */
#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
        Scc_Core_Channel_EnableChannel(SCC_CHANNEL_RENEGOTIATION);
#endif
      }
      break;
    }

    default:
      /* Report a V2G error of the current trigger */
      Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Iso_20_EncodeWPTMessageInvalidMsgTrigger);
      retVal = Scc_ReturnType_NotOK;
      break;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_ExiTx_WPT_FinePositioningSetupReq
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
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiTx_WPT_FinePositioningSetupReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)

{/* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupReqType, AUTOMATIC, SCC_VAR_NOINIT))                             /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    /* [V2G20-5128] */
    /* #30 Fill the EXI structure with parameter values */
    *RootElementIdPtr = EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_SETUP_REQ_TYPE;
    /* #40 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #50 Check if header was written successfully */
    if (retVal == Scc_ReturnType_OK)
    {
      retVal = Scc_ReturnType_NotOK;
      /* #60 Allocate message elements */
      /* EVDeviceFinePositioningMethodList */
      msgPtr->EVDeviceFinePositioningMethodList
        = (P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningMethodListType, AUTOMATIC, SCC_VAR_NOINIT))                       /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_FinePositioningMethodListType), Exi_BT_True);
      /* EVDevicePairingMethodList */
      msgPtr->EVDevicePairingMethodList
        = (P2VAR(Exi_ISO_20_WPT_10_WPT_PairingMethodListType, AUTOMATIC, SCC_VAR_NOINIT))                               /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_PairingMethodListType), Exi_BT_True);
      /* EVDeviceAlignmentCheckMethodList */
      msgPtr->EVDeviceAlignmentCheckMethodList
        = (P2VAR(Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodListType, AUTOMATIC, SCC_VAR_NOINIT))                        /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodListType), Exi_BT_True);
      /* VendorSpecificDataContainer */
      msgPtr->VendorSpecificDataContainer
        = (P2VAR(Exi_ISO_20_WPT_10_WPT_DataContainerType, AUTOMATIC, SCC_VAR_NOINIT))                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_DataContainerType), Exi_BT_True);
      /* LF_SystemSetupData */
      msgPtr->LF_SystemSetupData
        = (P2VAR(Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataType, AUTOMATIC, SCC_VAR_NOINIT))                              /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataType), Exi_BT_True);

      /* #70 Check if message elements were allocated */
      if ((msgPtr->EVDeviceFinePositioningMethodList != NULL_PTR)
        && (msgPtr->EVDevicePairingMethodList != NULL_PTR)
        && (msgPtr->EVDeviceAlignmentCheckMethodList != NULL_PTR)
        && (msgPtr->VendorSpecificDataContainer != NULL_PTR)
        && (msgPtr->LF_SystemSetupData != NULL_PTR))
      {
        /*
         * [V2G20-5001], [V2G20-5002], [V2G20-5003] need to be taken care by application.
         * The Scc doesn't restrict the application with these requirements.
         * It is the choice of the application to follow the requirements or not.
         */
        /* #80 Fetch EVProcessing from application */
        Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVProcessing(&msgPtr->EVProcessing);
        /* #90 Fetch EVDeviceFinePositioningMethodList from application */
        Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_EVDeviceFinePositioningMethodList(msgPtr->EVDeviceFinePositioningMethodList);
        /* #100 Fetch EVDevicePairingMethodList from application */
        Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_EVDevicePairingMethodList(msgPtr->EVDevicePairingMethodList);
        /* #110 Fetch EVDeviceAlignmentCheckMethodList from application */
        Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_EVDeviceAlignmentCheckMethodList(msgPtr->EVDeviceAlignmentCheckMethodList);
        /* #120 Fetch NaturalOffset from application */
        Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_NaturalOffset(&msgPtr->NaturalOffset);
        /* #130 Fetch VendorSpecificDataContainer from application */
        {
          boolean flag = FALSE;
          Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_VendorSpecificDataContainer(msgPtr->VendorSpecificDataContainer, &flag);
          msgPtr->VendorSpecificDataContainerFlag = SCC_BOOLEAN_TO_BITTYPE(flag);
        }
        /* #140 Fetch LF_SystemSetupData from application */
        {
          boolean flag = FALSE;
          Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_LF_SystemSetupData(msgPtr->LF_SystemSetupData, &flag);
          msgPtr->LF_SystemSetupDataFlag = SCC_BOOLEAN_TO_BITTYPE(flag);
        }

        retVal = Scc_ReturnType_OK;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_ExiTx_WPT_FinePositioningReq
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiTx_WPT_FinePositioningReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)

{/* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningReqType, AUTOMATIC, SCC_VAR_NOINIT))                                  /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_FinePositioningReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    /* [V2G20-5128] */
    /* #30 Fill the EXI structure with parameter values */
    *RootElementIdPtr = EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_REQ_TYPE;
    /* #40 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #50 Check if header was written successfully */
    if (retVal == Scc_ReturnType_OK)
    {
      retVal = Scc_ReturnType_NotOK;
      /* #60 Allocate message elements */
      /* VendorSpecificDataContainer */
      msgPtr->VendorSpecificDataContainer
        = (P2VAR(Exi_ISO_20_WPT_10_WPT_DataContainerType, AUTOMATIC, SCC_VAR_NOINIT))                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_DataContainerType), Exi_BT_True);
      /* WPT_LF_DataPackageList */
      msgPtr->WPT_LF_DataPackageList
        = (P2VAR(Exi_ISO_20_WPT_10_WPT_LF_DataPackageListType, AUTOMATIC, SCC_VAR_NOINIT))                              /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_LF_DataPackageListType), Exi_BT_True);

      /* #70 Check if message elements were allocated */
      if (   (msgPtr->VendorSpecificDataContainer != NULL_PTR)
          && (msgPtr->WPT_LF_DataPackageList != NULL_PTR))
      {
        /* #80 Fetch EVProcessing from application */
        Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVProcessing(&msgPtr->EVProcessing);
        /* #90 Fetch EVResultCode from application */
        /*
         * [V2G20-5051], [V2G20-5052] need to be taken care by application.
         * The Scc doesn't restrict the application with these requirements.
         * It is the choice of the application to follow the requirements or not
         */
        Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_EVResultCode(&msgPtr->EVResultCode);
        /* #100 Fetch VendorSpecificDataContainer from application */
        {
          boolean flag = FALSE;
          Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_VendorSpecificDataContainer(msgPtr->VendorSpecificDataContainer, &flag);
          msgPtr->VendorSpecificDataContainerFlag = SCC_BOOLEAN_TO_BITTYPE(flag);
        }
        /* #110 Fetch LF_SystemSetupData from application */
        {
          boolean flag = FALSE;
          Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_WPT_LF_DataPackageList(msgPtr->WPT_LF_DataPackageList, &flag);
          msgPtr->WPT_LF_DataPackageListFlag = SCC_BOOLEAN_TO_BITTYPE(flag);
        }

        retVal = Scc_ReturnType_OK;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_ExiTx_WPT_PairingReq
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiTx_WPT_PairingReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)

{/* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_WPT_10_WPT_PairingReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_WPT_10_WPT_PairingReqType, AUTOMATIC, SCC_VAR_NOINIT))                                          /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_PairingReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    /* [V2G20-5128] */
    /* #30 Fill the EXI structure with parameter values */
    *RootElementIdPtr = EXI_ISO_20_WPT_10_WPT_PAIRING_REQ_TYPE;
    /* #40 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #50 Check if header was written successfully */
    if (retVal == Scc_ReturnType_OK)
    {
      retVal = Scc_ReturnType_NotOK;
      /* #60 Allocate message elements */
      /* VendorSpecificDataContainer */
      msgPtr->VendorSpecificDataContainer
        = (P2VAR(Exi_ISO_20_WPT_10_WPT_DataContainerType, AUTOMATIC, SCC_VAR_NOINIT))                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_DataContainerType), Exi_BT_True);

      /* #70 Check if message elements were allocated */
      if (msgPtr->VendorSpecificDataContainer != NULL_PTR)
      {
        /* #80 Fetch EVProcessing from application and write to message */
        Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_EVProcessing(&msgPtr->EVProcessing);

        /* #90 Fetch EVResultCode from application and write to message */
        /*
         * [V2G20-5049], [V2G20-5050] need to be taken care by application.
         * The Scc doesn't restrict the application with these requirements.
         * It is the choice of the application to follow the requirements or not
         */
        Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_EVResultCode(&msgPtr->EVResultCode);

        /* #100 Fetch ObservedIDCode from application and write to message */
        {
          boolean flag = FALSE;
          Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_ObservedIDCode(&msgPtr->ObservedIDCode, &flag);
          msgPtr->ObservedIDCodeFlag = SCC_BOOLEAN_TO_BITTYPE(flag);
        }

        /* #110 Fetch VendorSpecificDataContainer from application and write to message */
        {
          boolean flag = FALSE;
          Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_VendorSpecificDataContainer(msgPtr->VendorSpecificDataContainer, &flag);
          msgPtr->VendorSpecificDataContainerFlag = SCC_BOOLEAN_TO_BITTYPE(flag);
        }

        retVal = Scc_ReturnType_OK;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_ExiTx_WPT_ChargeParameterDiscoveryReq
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
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiTx_WPT_ChargeParameterDiscoveryReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{/* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReqType, AUTOMATIC, SCC_VAR_NOINIT))                         /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    /* [V2G20-5128] */
    /* #30 Fill the EXI structure with parameter values */
    *RootElementIdPtr = EXI_ISO_20_WPT_10_WPT_CHARGE_PARAMETER_DISCOVERY_REQ_TYPE;
    /* #40 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #50 Check if header was written successfully */
    if (retVal == Scc_ReturnType_OK)
    {
      retVal = Scc_ReturnType_NotOK;
      /* #60 Allocate message elements */
      /* EVPCMaxReceivablePower */
      msgPtr->EVPCMaxReceivablePower
        = (P2VAR(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_VAR_NOINIT))                                       /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_RationalNumberType), Exi_BT_True);
      /* EVPCNaturalFrequency */
      msgPtr->EVPCNaturalFrequency
        = (P2VAR(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_VAR_NOINIT))                                       /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_RationalNumberType), Exi_BT_True);
      /* VendorSpecificDataContainer */
      msgPtr->VendorSpecificDataContainer
        = (P2VAR(Exi_ISO_20_WPT_10_WPT_DataContainerType, AUTOMATIC, SCC_VAR_NOINIT))                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_DataContainerType), Exi_BT_True);

      /* #70 Check if message elements were allocated */
      if (   (msgPtr->EVPCMaxReceivablePower != NULL_PTR)
          && (msgPtr->EVPCNaturalFrequency != NULL_PTR)
          && (msgPtr->VendorSpecificDataContainer != NULL_PTR))
      {
        /* #80 Fetch EVPCMaxReceivablePower from application */
        Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_EVPCMaxReceivablePower(msgPtr->EVPCMaxReceivablePower);
        /* #90 Fetch EVPCNaturalFrequency from application */
        Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_EVPCNaturalFrequency(msgPtr->EVPCNaturalFrequency);
        /* #100 Fetch SDMaxGroundClearence from application */
        Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_SDMaxGroundClearence(&msgPtr->SDMaxGroundClearence);
        /* #110 Fetch SDMinGroundClearence from application */
        Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_SDMinGroundClearence(&msgPtr->SDMinGroundClearence);
        /* #120 Fetch VendorSpecificDataContainer from application */
        {
          boolean flag = FALSE;
          Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_VendorSpecificDataContainer(msgPtr->VendorSpecificDataContainer, &flag);
          msgPtr->VendorSpecificDataContainerFlag = SCC_BOOLEAN_TO_BITTYPE(flag);
        }
        /* #130 Fetch EVPCDeviceLocalControl from application */
        Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_EVPCDeviceLocalControl(&msgPtr->EVPCDeviceLocalControl);

        retVal = Scc_ReturnType_OK;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_ExiTx_WPT_AlignmentCheckReq
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiTx_WPT_AlignmentCheckReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_WPT_10_WPT_AlignmentCheckReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_WPT_10_WPT_AlignmentCheckReqType, AUTOMATIC, SCC_VAR_NOINIT))                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_AlignmentCheckReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    /* [V2G20-5128] */
    /* #30 Fill the EXI structure with parameter values */
    *RootElementIdPtr = EXI_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_REQ_TYPE;
    /* #40 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #50 Check if header was written successfully */
    if (retVal == Scc_ReturnType_OK)
    {
      retVal = Scc_ReturnType_NotOK;
      /* #60 Allocate message elements */
      /* VendorSpecificDataContainer */
      msgPtr->VendorSpecificDataContainer
        = (P2VAR(Exi_ISO_20_WPT_10_WPT_DataContainerType, AUTOMATIC, SCC_VAR_NOINIT))                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_DataContainerType), Exi_BT_True);
      /* TargetCoilCurrent */
      msgPtr->TargetCoilCurrent
        = (P2VAR(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_VAR_NOINIT))                                       /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_RationalNumberType), Exi_BT_True);

      /* #70 Check if message elements were allocated */
      if (   (msgPtr->VendorSpecificDataContainer != NULL_PTR)
          && (msgPtr->TargetCoilCurrent != NULL_PTR))
      {
        /* #80 Fetch EVProcessing from application */
        Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_EVProcessing(&msgPtr->EVProcessing);
        /* #90 Fetch EVResultCode from application */
        /*
         * [V2G20-5047], [V2G20-5048] need to be taken care by application.
         * The Scc doesn't restrict the application with these requirements.
         * It is the choice of the application to follow the requirements or not
         */
        Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_EVResultCode(&msgPtr->EVResultCode);
        /* #100 Fetch VendorSpecificDataContainer from application */
        {
          boolean flag = FALSE;
          Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_VendorSpecificDataContainer(msgPtr->VendorSpecificDataContainer, &flag);
          msgPtr->VendorSpecificDataContainerFlag = SCC_BOOLEAN_TO_BITTYPE(flag);
        }
        /* #110 Fetch TargetCoilCurrent from application */
        {
          boolean flag = FALSE;
          Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_TargetCoilCurrent(msgPtr->TargetCoilCurrent, &flag);
          msgPtr->TargetCoilCurrentFlag = SCC_BOOLEAN_TO_BITTYPE(flag);
        }

        retVal = Scc_ReturnType_OK;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_ExiTx_WPT_ChargeLoopReq
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
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_ExiTx_WPT_ChargeLoopReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_WPT_10_WPT_ChargeLoopReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_WPT_10_WPT_ChargeLoopReqType, AUTOMATIC, SCC_VAR_NOINIT))                                       /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_ChargeLoopReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    /* [V2G20-5128] */
    /* #30 Fill the EXI structure with parameter values */
    *RootElementIdPtr = EXI_ISO_20_WPT_10_WPT_CHARGE_LOOP_REQ_TYPE;
    /* #40 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #50 Check if header was written successfully */
    if (retVal == Scc_ReturnType_OK)
    {
      retVal = Scc_ReturnType_NotOK;

      /* #60 Allocate message elements */
      /* DisplayParameters */
      msgPtr->DisplayParameters
        = (P2VAR(Exi_ISO_20_CT_10_DisplayParametersType, AUTOMATIC, SCC_VAR_NOINIT))                                    /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_DisplayParametersType), Exi_BT_True);
      /* EVPCPowerRequest */
      msgPtr->EVPCPowerRequest
        = (P2VAR(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_VAR_NOINIT))                                       /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_RationalNumberType), Exi_BT_True);
      /* EVPCPowerOutput */
      msgPtr->EVPCPowerOutput
        = (P2VAR(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_VAR_NOINIT))                                       /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_RationalNumberType), Exi_BT_True);
      /* EVPCOperatingFrequency */
      msgPtr->EVPCOperatingFrequency
        = (P2VAR(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_VAR_NOINIT))                                       /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_RationalNumberType), Exi_BT_True);
      /* EVPCPowerControlParameter */
      msgPtr->EVPCPowerControlParameter
        = (P2VAR(Exi_ISO_20_WPT_10_WPT_EVPCPowerControlParameterType, AUTOMATIC, SCC_VAR_NOINIT))                       /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_EVPCPowerControlParameterType), Exi_BT_True);
      /* ManufacturerSpecificDataContainer */
      msgPtr->ManufacturerSpecificDataContainer
        = (P2VAR(Exi_ISO_20_WPT_10_WPT_DataContainerType, AUTOMATIC, SCC_VAR_NOINIT))                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_DataContainerType), Exi_BT_True);

      /* #70 Check if message elements were allocated */
      if (   (msgPtr->DisplayParameters != NULL_PTR)
          && (msgPtr->EVPCPowerRequest != NULL_PTR)
          && (msgPtr->EVPCPowerOutput != NULL_PTR)
          && (msgPtr->EVPCOperatingFrequency != NULL_PTR)
          && (msgPtr->EVPCPowerControlParameter != NULL_PTR)
          && (msgPtr->ManufacturerSpecificDataContainer != NULL_PTR))
      {
        /* #80 Fetch DisplayParameters from application */
        {
          boolean flag = FALSE;
          Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_DisplayParameters(msgPtr->DisplayParameters, &flag);
          msgPtr->DisplayParametersFlag = SCC_BOOLEAN_TO_BITTYPE(flag);
        }
        /* [V2G20-1081] */
        /* #90 Fetch MeterInfoRequested from application */
        msgPtr->MeterInfoRequested = FALSE;
        Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_MeterInfoRequested(&msgPtr->MeterInfoRequested);
        /* #100 Fetch EVPCPowerRequest from application */
        {
          Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
          Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_EVPCPowerRequest(&scc_PhysicalValueTmp);
          Scc_Conv_Scc20ToISO_PhysicalValue(&scc_PhysicalValueTmp, msgPtr->EVPCPowerRequest);
        }
        /* #110 Fetch EVPCPowerOutput from application */
        {
          Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
          Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_EVPCPowerOutput(&scc_PhysicalValueTmp);
          Scc_Conv_Scc20ToISO_PhysicalValue(&scc_PhysicalValueTmp, msgPtr->EVPCPowerOutput);
        }
        /* #120 Fetch EVPCChargeDiagnostics from application */
        Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_EVPCChargeDiagnostics(&msgPtr->EVPCChargeDiagnostics);
        /* #130 Fetch EVPCOperatingFrequency from application */
        {
          Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
          boolean flag = FALSE;
          Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_EVPCOperatingFrequency(&scc_PhysicalValueTmp, &flag);
          Scc_Conv_Scc20ToISO_PhysicalValue(&scc_PhysicalValueTmp, msgPtr->EVPCOperatingFrequency);
          msgPtr->EVPCOperatingFrequencyFlag = SCC_BOOLEAN_TO_BITTYPE(flag);
        }
        /* EVPCPowerControlParameter */
        {
          boolean flag = FALSE;
          msgPtr->EVPCPowerControlParameter->EVPCCoilCurrentInformation
            = (P2VAR(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_VAR_NOINIT))                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_RationalNumberType), Exi_BT_True);
          msgPtr->EVPCPowerControlParameter->EVPCCoilCurrentRequest
            = (P2VAR(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_VAR_NOINIT))                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_RationalNumberType), Exi_BT_True);
          msgPtr->EVPCPowerControlParameter->EVPCCurrentOutputInformation
            = (P2VAR(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_VAR_NOINIT))                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_RationalNumberType), Exi_BT_True);
          msgPtr->EVPCPowerControlParameter->EVPCVoltageOutputInformation
            = (P2VAR(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_VAR_NOINIT))                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_RationalNumberType), Exi_BT_True);

          if (   (msgPtr->EVPCPowerControlParameter->EVPCCoilCurrentInformation != NULL_PTR)
              && (msgPtr->EVPCPowerControlParameter->EVPCCoilCurrentRequest != NULL_PTR)
              && (msgPtr->EVPCPowerControlParameter->EVPCCurrentOutputInformation != NULL_PTR)
              && (msgPtr->EVPCPowerControlParameter->EVPCVoltageOutputInformation != NULL_PTR))
          {
            /* #140 Fetch EVPCPowerControlParameter from application */
            Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_EVPCPowerControlParameter(msgPtr->EVPCPowerControlParameter, &flag);
            msgPtr->EVPCPowerControlParameterFlag = SCC_BOOLEAN_TO_BITTYPE(flag);
            retVal = Scc_ReturnType_OK;
          }
        }
        /* #150 Fetch ManufacturerSpecificDataContainer from application */
        {
          boolean flag = FALSE;
          Scc_ISO15118_20WPT_InterfaceCfg_ExiTx_Get_ManufacturerSpecificDataContainer(msgPtr->ManufacturerSpecificDataContainer, &flag);
          msgPtr->ManufacturerSpecificDataContainerFlag = SCC_BOOLEAN_TO_BITTYPE(flag);
        }
      }
    }
  }

  return retVal;
}

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SCHEMA_ISO_20WPT */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20WPT_ExiTx.c
 *********************************************************************************************************************/
