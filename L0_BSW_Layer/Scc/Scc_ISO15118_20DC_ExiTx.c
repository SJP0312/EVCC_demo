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
/*!        \file  Scc_ISO15118_20DC_ExiTx.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to the specifications ISO/IEC 15118-20 DC schema
 *                specific parts.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_ISO15118_20DC_EXITX_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
#include "Scc_ISO15118_20DC_Exi.h"
#include "Scc_ISO15118_20CM_Exi.h"
#include "Scc_ISO15118_20_Exi.h"
#include "Scc_ISO15118_20_TimerCfg.h"
#include "Scc_ISO15118_20_InterfaceCfg.h"
#include "Scc_Priv.h"

#if ( SCC_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */

#include "IpBase.h"
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
 *  Scc_ISO15118_20DC_ExiTx_<ISO15118-20-Request>
 *********************************************************************************************************************/
/*! \brief          Set all parameters for ISO15118-20 request message
 *  \details        Set all parameters for the body element of the request message.
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[out]     RootElementIdPtr        Pointer to the root element that needs to be set by the specialized message type.
 *  \return         Scc_ReturnType_OK       Header was created and written.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
 /* See pattern Scc_ISO15118_20DC_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiTx_DC_ChargeParameterDiscoveryReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
/* See pattern Scc_ISO15118_20DC_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiTx_DC_CableCheckReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
/* See pattern Scc_ISO15118_20DC_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiTx_DC_PreChargeReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
/* See pattern Scc_ISO15118_20DC_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiTx_DC_ChargeLoopReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
/* See pattern Scc_ISO15118_20DC_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiTx_DC_WeldingDetectionReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_ExiTx_DC_ChargeLoopReqHandleControlMode
 *********************************************************************************************************************/
/*! \brief          Creates and sets the control mode related parameters of a charge loop message.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  MsgPtr                  Pointer to the message that needs to be modified.
 *  \return         Scc_ReturnType_OK       Control mode was created.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiTx_DC_ChargeLoopReqHandleControlMode(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_20_DC_10_DC_ChargeLoopReqType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_ExiTx_PrepareMessageCreateMessage
 *********************************************************************************************************************/
/*! \brief          Creates the EXI request message to be transmitted.
 *  \details        -
 *  \param[in]      TxMsgWSPtr                  Pointer to the Tx message workspace.
 *  \return         Scc_ReturnType_OK           Exi preparation was successful.
 *  \return         Scc_ReturnType_NotOK        Exi preparation was not successful or timeout happened.
 *  \return         Scc_ReturnType_Pending      Message handling is pending, try again later.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20DC_ExiTx_PrepareMessageCreateMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_ExiTx_SAPSetEntry
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
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_ExiTx_SAPSetEntry(
  P2VAR(Exi_SAP_AppProtocolType, AUTOMATIC, SCC_APPL_DATA) AppProtocolPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* [V2G20-2132]  */
  /* #10 Copy the namespace string */
  /* PRQA S 0310,3305,0315 3 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy */
  IpBase_Copy(
    (P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&AppProtocolPtr->ProtocolNamespace->Buffer[0],
    (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))SCC_ISO15118_20DC_EXI_SAP_PROTOCOL_NAMESPACE,
    SCC_ISO15118_20DC_EXI_SAP_PROTOCOL_NAMESPACE_LEN);
  /* #20 Set namespace length */
  AppProtocolPtr->ProtocolNamespace->Length = SCC_ISO15118_20DC_EXI_SAP_PROTOCOL_NAMESPACE_LEN;
  /* #30 Set VersionNumberMajor */
  AppProtocolPtr->VersionNumberMajor = SCC_ISO15118_20DC_EXI_SAP_VERSION_NUMBER_MAJOR;
  /* #40 Set VersionNumberMinor */
  AppProtocolPtr->VersionNumberMinor = SCC_ISO15118_20DC_EXI_SAP_VERSION_NUMBER_MINOR;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_ExiTx_PrepareMessage
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
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20DC_ExiTx_PrepareMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  Scc_PoolBuffType poolBuffType = SCC_POOL_BUFF_LARGE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if this is the initial step */
  if (TxMsgWSPtr->Step == SCC_MSGPROC_STEP_INIT)
  {
    uint8 bufferPoolId = 0;
    P2VAR(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                      Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());

    TxMsgWSPtr->BufIdx = 0;
    TxMsgWSPtr->RootElementId = 0;
    TxMsgWSPtr->payloadType = SCC_V2GTP_HDR_PAYLOAD_TYPE_DC;

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
    retVal = Scc_ISO15118_20DC_ExiTx_PrepareMessageCreateMessage(TxMsgWSPtr);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_ExiTx_PrepareMessageCreateMessage
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20DC_ExiTx_PrepareMessageCreateMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* #10 create request message and set MessageTimeout based on message trigger */
  switch (Scc_Core_Channel_Get_MsgTrig())
  {
    case Scc_MsgTrig_ChargeParameterDiscovery:
      retVal = Scc_ISO15118_20DC_ExiTx_DC_ChargeParameterDiscoveryReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
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
            /* [V2G20-434], [V2G20-436]: Setup V2G_EVCC_Msg_Timeout */
            Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_ChargeParameterDiscoveryMessageTimeout();
            break;
          }
          /* If renegotiation channel is enabled, Renegotiation channel */
#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
          case SCC_CHANNEL_RENEGOTIATION:
          {
            /* Set timeout */
            /* [V2G20-434], [V2G20-436]: Setup V2G_EVCC_Msg_Timeout */
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

    case Scc_MsgTrig_CableCheck:
      retVal = Scc_ISO15118_20DC_ExiTx_DC_CableCheckReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
      if (retVal == Scc_ReturnType_OK)
      {
        /* [V2G20-434], [V2G20-436]: Setup V2G_EVCC_Msg_Timeout */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_CableCheckMessageTimeout();
      }
      break;

    case Scc_MsgTrig_PreCharge:
      retVal =  Scc_ISO15118_20DC_ExiTx_DC_PreChargeReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
      if (retVal == Scc_ReturnType_OK)
      {
        /* [V2G20-434], [V2G20-436]: Setup V2G_EVCC_Msg_Timeout */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_PreChargeMessageTimeout();
      }
      break;

    case Scc_MsgTrig_ChargeLoop:
      retVal = Scc_ISO15118_20DC_ExiTx_DC_ChargeLoopReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
      if (retVal == Scc_ReturnType_OK)
      {
        /* [V2G20-434], [V2G20-436]: Setup V2G_EVCC_Msg_Timeout */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_ChargeLoopMessageTimeout();
        /* [V2G20-1846] If Renegotiation channel is enabled in configuration, then enable the channel to transmit messages */
#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
        Scc_Core_Channel_EnableChannel(SCC_CHANNEL_RENEGOTIATION);
#endif
    /* [V2G20-1084] If Metering channel is enabled in configuration, then enable the channel to transmit messages */
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
        Scc_Core_Channel_EnableChannel(SCC_CHANNEL_METERING);
#endif
      }
      break;

    case Scc_MsgTrig_WeldingDetection:
      retVal = Scc_ISO15118_20DC_ExiTx_DC_WeldingDetectionReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
      if (retVal == Scc_ReturnType_OK)
      {
        /* [V2G20-434], [V2G20-436]: Setup V2G_EVCC_Msg_Timeout */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_WeldingDetectionMessageTimeout();
      }
      break;

    default:
      /* Report a V2G error of the current trigger */
      Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Iso_20_EncodeDCMessageInvalidMsgTrigger);
      retVal = Scc_ReturnType_NotOK;
      break;
  }

  return retVal;
}
/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_ExiTx_DC_ChargeParameterDiscoveryReq
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
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiTx_DC_ChargeParameterDiscoveryReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_DC_10_DC_ChargeParameterDiscoveryReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_DC_10_DC_ChargeParameterDiscoveryReqType, AUTOMATIC, SCC_VAR_NOINIT))                           /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_DC_10_DC_ChargeParameterDiscoveryReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    *RootElementIdPtr = EXI_ISO_20_DC_10_DC_CHARGE_PARAMETER_DISCOVERY_REQ_TYPE;

    /* #30 [V2G20-1268] Fill the EXI structure with parameter values */
    /* #40 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #50 Check if the header was written */
    if (retVal == Scc_ReturnType_OK)
    {
      retVal = Scc_ReturnType_NotOK;

      /* #60 Setup energy transfer mode based on selected energy transfer service */
      switch (Scc_ISO15118_20CM_ExiTx_Get_SelectedEnergyTransferServiceID())
      {
        /* #70 If DC is selected: [V2G20-1348] Fetch DC_CPDReqEnergyTransferModeType from application */
        case Scc_ISO15118_20_SID_DC:
#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
        case Scc_ISO15118_20_SID_DC_ACDP:
#endif /* SCC_SCHEMA_ISO_20ACDP */
        {
          /* Exi_ISO_20_DC_10_DC_CPDReqEnergyTransferModeType */
          msgPtr->DC_CPDReqEnergyTransferModeElementId = EXI_ISO_20_DC_10_DC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE;
          msgPtr->DC_CPDReqEnergyTransferMode
            = (P2VAR(Exi_ISO_20_DC_10_DC_CPDReqEnergyTransferModeType, AUTOMATIC, SCC_VAR_NOINIT))                      /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_DC_10_DC_CPDReqEnergyTransferModeType), Exi_BT_True);
          if (msgPtr->DC_CPDReqEnergyTransferMode != NULL_PTR)
          {
            Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_DC_CPDReqEnergyTransferMode(
              (P2VAR(Exi_ISO_20_DC_10_DC_CPDReqEnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA))msgPtr->DC_CPDReqEnergyTransferMode);
            retVal = Scc_ReturnType_OK;
          }
          break;
        }
#if (defined SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON)
        /* #80 [V2G20-1458],[V2G20-2650] If BPT enabled: If DC_BPT is selected: Fetch BPT_DC_CPDReqEnergyTransferModeType from application */
        case Scc_ISO15118_20_SID_DC_BPT:
#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
        case Scc_ISO15118_20_SID_DC_ACDP_BPT:
#endif /* SCC_SCHEMA_ISO_20ACDP */
        {
          /* Exi_ISO_20_DC_10_BPT_DC_CPDReqEnergyTransferModeType */
          msgPtr->DC_CPDReqEnergyTransferModeElementId = EXI_ISO_20_DC_10_BPT_DC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE;
          msgPtr->DC_CPDReqEnergyTransferMode
            = (P2VAR(Exi_ISO_20_DC_10_DC_CPDReqEnergyTransferModeType, AUTOMATIC, SCC_VAR_NOINIT))                      /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_DC_10_BPT_DC_CPDReqEnergyTransferModeType), Exi_BT_True);
          if (msgPtr->DC_CPDReqEnergyTransferMode != NULL_PTR)
          {
            Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_BPT_DC_CPDReqEnergyTransferMode(
              (P2VAR(Exi_ISO_20_DC_10_BPT_DC_CPDReqEnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA))msgPtr->DC_CPDReqEnergyTransferMode); /* PRQA S 0310  */ /* MD_Scc_0310_0314_0316_3305 */
            retVal = Scc_ReturnType_OK;
          }
          break;
        }
#endif /* SCC_CHARGING_BPT */
        default:
          /* Nothing to do - Tx part already takes care of ensuring valid energy transfer service */
          retVal = Scc_ReturnType_NotOK;
          break;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_ExiTx_DC_CableCheckReq
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiTx_DC_CableCheckReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_DC_10_DC_CableCheckReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_DC_10_DC_CableCheckReqType, AUTOMATIC, SCC_VAR_NOINIT))                                         /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_DC_10_DC_CableCheckReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    /* ----- Implementation ----------------------------------------------- */
    /* [V2G20-1279] */
    /* #30 Fill the EXI structure with parameter values */
    *RootElementIdPtr = EXI_ISO_20_DC_10_DC_CABLE_CHECK_REQ_TYPE;

    /* #40 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_ExiTx_DC_PreChargeReq
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiTx_DC_PreChargeReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_DC_10_DC_PreChargeReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_DC_10_DC_PreChargeReqType, AUTOMATIC, SCC_VAR_NOINIT))                                          /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_DC_10_DC_PreChargeReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };

    /* [V2G20-1281] */
    /* #30 Fill the EXI structure with parameter values */
    *RootElementIdPtr = EXI_ISO_20_DC_10_DC_PRE_CHARGE_REQ_TYPE;

    /* #40 Write header. */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #50 Check if header was written. */
    if (retVal == Scc_ReturnType_OK)
    {
      /* #60 Fetch EVProcessing from application. */
      Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVProcessing(&msgPtr->EVProcessing);

      /* #70 EVPresentVoltage */
      /* #80 Fetch EVPresentVoltage from application. */
      Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_EVPresentVoltage(&scc_PhysicalValueTmp);
      retVal = Scc_ISO15118_20_ExiTx_CreateRationaleNumberType(ExiAllocWsPtr, &scc_PhysicalValueTmp, &msgPtr->EVPresentVoltage);
      /* #90 EVTargetVoltage */
      if (retVal == Scc_ReturnType_OK)
      {
        /* #100 Fetch EVTargetVoltage from application. */
        Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVTargetVoltage(&scc_PhysicalValueTmp);
        retVal = Scc_ISO15118_20_ExiTx_CreateRationaleNumberType(ExiAllocWsPtr, &scc_PhysicalValueTmp, &msgPtr->EVTargetVoltage);
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_ExiTx_DC_ChargeLoopReq
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
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiTx_DC_ChargeLoopReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_DC_10_DC_ChargeLoopReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_DC_10_DC_ChargeLoopReqType, AUTOMATIC, SCC_VAR_NOINIT))                                         /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_DC_10_DC_ChargeLoopReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    /* #30 [V2G20-1283] Fill the EXI structure with parameter values */
    *RootElementIdPtr = EXI_ISO_20_DC_10_DC_CHARGE_LOOP_REQ_TYPE;

    /* #40 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #50 Check if header was written */
    if (retVal == Scc_ReturnType_OK)
    {
      retVal = Scc_ReturnType_NotOK;

      /* DisplayParameters */
      msgPtr->DisplayParameters
        = (P2VAR(Exi_ISO_20_CT_10_DisplayParametersType, AUTOMATIC, SCC_VAR_NOINIT))                                    /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_DisplayParametersType), Exi_BT_True);
      /* #60 Check if DisplayParameters was created */
      if (msgPtr->DisplayParameters != NULL_PTR)
      {
        /* #70 Fetch DisplayParameters from application */
        {
          boolean flag = FALSE;
          Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_DisplayParameters(msgPtr->DisplayParameters, &flag);
          msgPtr->DisplayParametersFlag = SCC_BOOLEAN_TO_BITTYPE(flag);
        }

        /* #80 Fetch MeterInfoRequested from application */
        msgPtr->MeterInfoRequested = FALSE;
        Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_MeterInfoRequested(&msgPtr->MeterInfoRequested);

        /* EVPresentVoltage */
        /* #90 Fetch EVPresentVoltage from application */
        {
          Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
          Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_EVPresentVoltage(&scc_PhysicalValueTmp);
          retVal = Scc_ISO15118_20_ExiTx_CreateRationaleNumberType(ExiAllocWsPtr, &scc_PhysicalValueTmp, &msgPtr->EVPresentVoltage);
        }

        /* #100 Check if EVPresentVoltage was created */
        if (retVal == Scc_ReturnType_OK)
        {
          /* #110 Handle the control mode parameter */
          retVal = Scc_ISO15118_20DC_ExiTx_DC_ChargeLoopReqHandleControlMode(ExiAllocWsPtr, msgPtr);
        }
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_ExiTx_DC_ChargeLoopReqHandleControlMode
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
 /* PRQA S 6030 1 */ /* MD_MSR_STCYC */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiTx_DC_ChargeLoopReqHandleControlMode(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_20_DC_10_DC_ChargeLoopReqType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  Scc_ISO15118_20_ControlModeType controlMode = SCC_ISO15118_20_CONTROL_MODE_TYPE_SCHEDULED;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Fetch current control mode from application */
  Scc_ISO15118_20_InterfaceCfg_ExiTx_Get_ControlMode(&controlMode);
  /* #20 Based on user control mode */
  switch (controlMode)
  {
    /* #30 [V2G20-1460] Dynamic control mode selected */
    case SCC_ISO15118_20_CONTROL_MODE_TYPE_DYNAMIC:
    {
      /* #40 Based on selected energy transfer service */
      switch (Scc_ISO15118_20CM_ExiTx_Get_SelectedEnergyTransferServiceID())
      {
        /* #50 [V2G20-1214],[V2G20-1762] If DC charging: Fetch Dynamic_DC_CLReqControlMode from application */
        case Scc_ISO15118_20_SID_DC:
#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
        case Scc_ISO15118_20_SID_DC_ACDP:
#endif /* SCC_SCHEMA_ISO_20ACDP */
        {
          /* Dynamic_DC_CLReqControlMode */
          MsgPtr->CLReqControlModeElementId = EXI_ISO_20_DC_10_DYNAMIC_DC_CLREQ_CONTROL_MODE_TYPE;
          MsgPtr->CLReqControlMode
            = (P2VAR(Exi_ISO_20_CT_10_CLReqControlModeType, AUTOMATIC, SCC_VAR_NOINIT))                                 /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_DC_10_Dynamic_DC_CLReqControlModeType), Exi_BT_True);
          if (MsgPtr->CLReqControlMode != NULL_PTR)
          {
            Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_Dynamic_DC_CLReqControlMode(
              (P2VAR(Exi_ISO_20_DC_10_Dynamic_DC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA))MsgPtr->CLReqControlMode); /* PRQA S 0316 */ /* MD_Scc_Exi_Generic */
            retVal = Scc_ReturnType_OK;
          }
          break;
        }
#if (defined SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON)
        /* #60 [V2G20-1214],[V2G20-1772],[V2G20-2650] If BPT enabled: If DC_BPT charging: Fetch BPT_Dynamic_DC_CLReqControlMode from application */
        case Scc_ISO15118_20_SID_DC_BPT:
#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
        case Scc_ISO15118_20_SID_DC_ACDP_BPT:
#endif /* SCC_SCHEMA_ISO_20ACDP */
        {
          /* BPT_Dynamic_DC_CLReqControlMode */
          MsgPtr->CLReqControlModeElementId = EXI_ISO_20_DC_10_BPT_DYNAMIC_DC_CLREQ_CONTROL_MODE_TYPE;
          MsgPtr->CLReqControlMode
            = (P2VAR(Exi_ISO_20_CT_10_CLReqControlModeType, AUTOMATIC, SCC_VAR_NOINIT))                                 /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLReqControlModeType), Exi_BT_True);
          if (MsgPtr->CLReqControlMode != NULL_PTR)
          {
            Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_BPT_Dynamic_DC_CLReqControlMode(
              (P2VAR(Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA))MsgPtr->CLReqControlMode); /* PRQA S 0316 */ /* MD_Scc_Exi_Generic */
            retVal = Scc_ReturnType_OK;
          }
          break;
        }
#endif /* SCC_CHARGING_BPT */
        default:
          /* Nothing to do - Tx part already takes care of ensuring valid energy transfer service */
          retVal = Scc_ReturnType_NotOK;
          break;
      }
      break;
    }

    /* #70 [V2G20-1460] Scheduled control mode selected */
    case SCC_ISO15118_20_CONTROL_MODE_TYPE_SCHEDULED:
    {
      /* #80 Based on selected energy transfer service */
      switch (Scc_ISO15118_20CM_ExiTx_Get_SelectedEnergyTransferServiceID())
      {
        /* #90 [V2G20-1215],[V2G20-1760] If DC charging: Fetch Scheduled_DC_CLReqControlMode from application */
        case Scc_ISO15118_20_SID_DC:
#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
        case Scc_ISO15118_20_SID_DC_ACDP:
#endif /* SCC_SCHEMA_ISO_20ACDP */
        {
          /* Scheduled_DC_CLReqControlMode */
          MsgPtr->CLReqControlModeElementId = EXI_ISO_20_DC_10_SCHEDULED_DC_CLREQ_CONTROL_MODE_TYPE;
          MsgPtr->CLReqControlMode
            = (P2VAR(Exi_ISO_20_CT_10_CLReqControlModeType, AUTOMATIC, SCC_VAR_NOINIT))                                 /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_DC_10_Scheduled_DC_CLReqControlModeType), Exi_BT_True);
          if (MsgPtr->CLReqControlMode != NULL_PTR)
          {
            Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_Scheduled_DC_CLReqControlMode(
              (P2VAR(Exi_ISO_20_DC_10_Scheduled_DC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA))MsgPtr->CLReqControlMode); /* PRQA S 0316 */ /* MD_Scc_Exi_Generic */
            retVal = Scc_ReturnType_OK;
          }
          break;
        }
#if (defined SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON)
        /* #100 [V2G20-1215],[V2G20-1770],[V2G20-2650] If BPT enabled: If DC_BPT charging: Fetch BPT_Scheduled_DC_CLReqControlMode from application */
        case Scc_ISO15118_20_SID_DC_BPT:
#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
        case Scc_ISO15118_20_SID_DC_ACDP_BPT:
#endif /* SCC_SCHEMA_ISO_20ACDP */
        {
          /* BPT_Scheduled_DC_CLReqControlMode */
          MsgPtr->CLReqControlModeElementId = EXI_ISO_20_DC_10_BPT_SCHEDULED_DC_CLREQ_CONTROL_MODE_TYPE;
          MsgPtr->CLReqControlMode
            = (P2VAR(Exi_ISO_20_CT_10_CLReqControlModeType, AUTOMATIC, SCC_VAR_NOINIT))                                 /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLReqControlModeType), Exi_BT_True);
          if (MsgPtr->CLReqControlMode != NULL_PTR)
          {
            Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_BPT_Scheduled_DC_CLReqControlMode(
              (P2VAR(Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA))MsgPtr->CLReqControlMode); /* PRQA S 0316 */ /* MD_Scc_Exi_Generic */
            retVal = Scc_ReturnType_OK;
          }
          break;
        }
#endif /* SCC_CHARGING_BPT */
        default:
          /* Nothing to do - Tx part already takes care of ensuring valid energy transfer service */
          retVal = Scc_ReturnType_NotOK;
          break;
      }
      break;
    }

    /* #110 Otherwise */
    default:
      /* #120 Propagate error to indicate invalid user input */
      Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Iso_20DC_ChargeLoopReqInvalidControlMode);
      retVal = Scc_ReturnType_NotOK;
      break;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_ExiTx_DC_WeldingDetectionReq
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20DC_ExiTx_DC_WeldingDetectionReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_DC_10_DC_WeldingDetectionReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_DC_10_DC_WeldingDetectionReqType, AUTOMATIC, SCC_VAR_NOINIT))                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_DC_10_DC_WeldingDetectionReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    /* [V2G20-1285] */
    /* #30 Fill the EXI structure with parameter values */
    *RootElementIdPtr = EXI_ISO_20_DC_10_DC_WELDING_DETECTION_REQ_TYPE;

    /* #40 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #50 Check if header was written */
    if (retVal == Scc_ReturnType_OK)
    {
      /* #60 Fetch EVProcessing from application */
      Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVProcessing(&msgPtr->EVProcessing);
    }
  }

  return retVal;
}
#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SCHEMA_ISO_20DC */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20DC_ExiTx.c
 *********************************************************************************************************************/
