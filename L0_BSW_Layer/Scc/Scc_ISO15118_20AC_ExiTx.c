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
/*!        \file  Scc_ISO15118_20AC_ExiTx.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to the specifications ISO/IEC 15118-20 AC schema
 *                specific parts.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_ISO15118_20AC_EXITX_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( defined SCC_SCHEMA_ISO_20AC ) && ( SCC_SCHEMA_ISO_20AC != 0 )
#include "Scc_ISO15118_20AC_Exi.h"
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
#include "Exi.h"

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
 *  Scc_ISO15118_20AC_ExiTx_<ISO15118-20-Request>
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
/* See pattern Scc_ISO15118_20AC_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20AC_ExiTx_ChargeParameterDiscoveryReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
/* See pattern Scc_ISO15118_20AC_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20AC_ExiTx_ChargeLoopReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20AC_ExiTx_ChargeLoopReqHandleControlMode
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20AC_ExiTx_ChargeLoopReqHandleControlMode(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_20_AC_10_AC_ChargeLoopReqType, AUTOMATIC, SCC_VAR_NOINIT) MsgPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20AC_ExiTx_PrepareMessageCreateMessage
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20AC_ExiTx_PrepareMessageCreateMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20AC_ExiTx_SAPSetEntry
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
FUNC(void, SCC_CODE) Scc_ISO15118_20AC_ExiTx_SAPSetEntry(
  P2VAR(Exi_SAP_AppProtocolType, AUTOMATIC, SCC_APPL_DATA) AppProtocolPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* [V2G20-1039]  */
  /* #10 Copy the namespace string */
  /* PRQA S 0310,3305,0315 3 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy */
  IpBase_Copy(
    (P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&AppProtocolPtr->ProtocolNamespace->Buffer[0],
    (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))SCC_ISO15118_20AC_EXI_SAP_PROTOCOL_NAMESPACE,
    SCC_ISO15118_20AC_EXI_SAP_PROTOCOL_NAMESPACE_LEN);
  /* #20 Set namespace length */
  AppProtocolPtr->ProtocolNamespace->Length = SCC_ISO15118_20AC_EXI_SAP_PROTOCOL_NAMESPACE_LEN;
  /* #30 Set VersionNumberMajor */
  AppProtocolPtr->VersionNumberMajor = SCC_ISO15118_20AC_EXI_SAP_VERSION_NUMBER_MAJOR;
  /* #40 Set VersionNumberMinor */
  AppProtocolPtr->VersionNumberMinor = SCC_ISO15118_20AC_EXI_SAP_VERSION_NUMBER_MINOR;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20AC_ExiTx_PrepareMessage
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
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20AC_ExiTx_PrepareMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if this is the initial step */
  if (TxMsgWSPtr->Step == SCC_MSGPROC_STEP_INIT)
  {
    Scc_PoolBuffType poolBuffType = SCC_POOL_BUFF_LARGE;
    uint8 bufferPoolId = 0;
    P2VAR(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                      Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());

    TxMsgWSPtr->BufIdx = 0;
    TxMsgWSPtr->RootElementId = 0;
    TxMsgWSPtr->payloadType = SCC_V2GTP_HDR_PAYLOAD_TYPE_AC;

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
    retVal = Scc_ISO15118_20AC_ExiTx_PrepareMessageCreateMessage(TxMsgWSPtr);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_PrepareMessageCreateMessage
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20AC_ExiTx_PrepareMessageCreateMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */

    /* #10 Create request message and set MessageTimeout based on message trigger */
  switch (Scc_Core_Channel_Get_MsgTrig())
  {
  case Scc_MsgTrig_ChargeParameterDiscovery:
    retVal = Scc_ISO15118_20AC_ExiTx_ChargeParameterDiscoveryReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
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
      /* If renegotiation channel is enabled, renegotiation channel */
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

  case Scc_MsgTrig_ChargeLoop:
    retVal = Scc_ISO15118_20AC_ExiTx_ChargeLoopReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
    if (retVal == Scc_ReturnType_OK)
    {
      /* Set timeout values */
      /* [V2G20-434],[V2G20-436] Setup V2G_EVCC_Msg_Timeout */
      Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_ChargeLoopMessageTimeout();
      /* [V2G20-1846] If renegotiation channel is enabled in configuration, then enable the channel to transmit messages */
#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
      Scc_Core_Channel_EnableChannel(SCC_CHANNEL_RENEGOTIATION);
#endif
      /* [V2G20-1084] If metering channel is enabled in configuration, then enable the channel to transmit messages */
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
      Scc_Core_Channel_EnableChannel(SCC_CHANNEL_METERING);
#endif
    }
    break;

  default:
    /* Report a V2G error of the current trigger */
    Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Iso_20_EncodeACMessageInvalidMsgTrigger);
    break;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20AC_ExiTx_ChargeParameterDiscoveryReq
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20AC_ExiTx_ChargeParameterDiscoveryReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryReqType, AUTOMATIC, SCC_VAR_NOINIT))                           /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    /* [V2G20-1258] */
    /* #30 Fill the EXI structure with parameter values */
    *RootElementIdPtr = EXI_ISO_20_AC_10_AC_CHARGE_PARAMETER_DISCOVERY_REQ_TYPE;

    /* #40 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #50 Check if header was written successfully */
    if (retVal == Scc_ReturnType_OK)
    {
      retVal = Scc_ReturnType_NotOK;

      /* #60 Setup energy transfer mode based on selected energy transfer service */
      switch (Scc_ISO15118_20CM_ExiTx_Get_SelectedEnergyTransferServiceID())
      {
        /* #70 If AC is selected: Fetch AC_CPDReqEnergyTransferMode from application */
        case Scc_ISO15118_20_SID_AC:
        {
          /* Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType */
          msgPtr->AC_CPDReqEnergyTransferModeElementId = EXI_ISO_20_AC_10_AC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE;
          msgPtr->AC_CPDReqEnergyTransferMode
            = (P2VAR(Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType, AUTOMATIC, SCC_VAR_NOINIT))                      /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType), Exi_BT_True);
          if (msgPtr->AC_CPDReqEnergyTransferMode != NULL_PTR)
          {
            Scc_ISO15118_20AC_InterfaceCfg_ExiTx_Get_AC_CPDReqEnergyTransferMode(msgPtr->AC_CPDReqEnergyTransferMode);
            retVal = Scc_ReturnType_OK;
          }
          break;
        }
#if (defined SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON)
      /* #80 [V2G20-1456],[V2G20-2652] If BPT enabled: If AC_BPT is selected: Fetch BPT_AC_CPDReqEnergyTransferMode from application */
        case Scc_ISO15118_20_SID_AC_BPT:
        {
          /* Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType */
          msgPtr->AC_CPDReqEnergyTransferModeElementId = EXI_ISO_20_AC_10_BPT_AC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE;
          msgPtr->AC_CPDReqEnergyTransferMode
            = (P2VAR(Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType, AUTOMATIC, SCC_VAR_NOINIT))                      /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType), Exi_BT_True);
          if (msgPtr->AC_CPDReqEnergyTransferMode != NULL_PTR)
          {
            Scc_ISO15118_20AC_InterfaceCfg_ExiTx_Get_BPT_AC_CPDReqEnergyTransferMode( /* PRQA S 0310 1 */ /* MD_Scc_0310_0314_0316_3305 */
              (P2VAR(Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA))msgPtr->AC_CPDReqEnergyTransferMode);
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
 *  Scc_ISO15118_20AC_ExiTx_ChargeLoopReq
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20AC_ExiTx_ChargeLoopReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_AC_10_AC_ChargeLoopReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_AC_10_AC_ChargeLoopReqType, AUTOMATIC, SCC_VAR_NOINIT))                                         /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_AC_10_AC_ChargeLoopReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    *RootElementIdPtr = EXI_ISO_20_AC_10_AC_CHARGE_LOOP_REQ_TYPE;
    /* #30 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #40 Check if header was written successfully */
    if (retVal == Scc_ReturnType_OK)
    {
      retVal = Scc_ReturnType_NotOK;

      /* DisplayParameters */
      msgPtr->DisplayParameters
        = (P2VAR(Exi_ISO_20_CT_10_DisplayParametersType, AUTOMATIC, SCC_VAR_NOINIT))                                    /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_DisplayParametersType), Exi_BT_True);

      if (msgPtr->DisplayParameters != NULL_PTR)
      {
        boolean flag = FALSE;

        /* #50 Fetch DisplayParameters from application */
        Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_DisplayParameters(msgPtr->DisplayParameters, &flag);
        msgPtr->DisplayParametersFlag = SCC_BOOLEAN_TO_BITTYPE(flag);

        /* #60 Fetch MeterInfoRequested from application */
        msgPtr->MeterInfoRequested = FALSE;
        Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_MeterInfoRequested(&msgPtr->MeterInfoRequested);

        /* #70 Create the control mode parameter */
        retVal = Scc_ISO15118_20AC_ExiTx_ChargeLoopReqHandleControlMode(ExiAllocWsPtr, msgPtr);
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20AC_ExiTx_ChargeLoopReqHandleControlMode
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20AC_ExiTx_ChargeLoopReqHandleControlMode(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_20_AC_10_AC_ChargeLoopReqType, AUTOMATIC, SCC_VAR_NOINIT) MsgPtr)
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
        /* #50 [V2G20-1214] If AC charging: Fetch Dynamic_AC_CLReqControlMode from application */
        case Scc_ISO15118_20_SID_AC:
        {
          /* Dynamic_AC_CLReqControlMode */
          MsgPtr->CLReqControlModeElementId = EXI_ISO_20_AC_10_DYNAMIC_AC_CLREQ_CONTROL_MODE_TYPE;
          MsgPtr->CLReqControlMode
            = (P2VAR(Exi_ISO_20_CT_10_CLReqControlModeType, AUTOMATIC, SCC_VAR_NOINIT))                                 /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_AC_10_Dynamic_AC_CLReqControlModeType), Exi_BT_True);
          if (MsgPtr->CLReqControlMode != NULL_PTR)
          {
            /* Fetch Dynamic_AC_CLReqControlMode from application */
            Scc_ISO15118_20AC_InterfaceCfg_ExiTx_Get_Dynamic_AC_CLReqControlMode(
              (P2VAR(Exi_ISO_20_AC_10_Dynamic_AC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA))MsgPtr->CLReqControlMode); /* PRQA S 0316 */ /* MD_Scc_Exi_Generic */
            retVal = Scc_ReturnType_OK;
          }
          break;
        }
#if (defined SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON)
        /* #60 [V2G20-1214],[V2G20-1768],[V2G20-2652] If BPT enabled: If AC_BPT charging: Fetch BPT_Dynamic_AC_CLReqControlMode from application */
        case Scc_ISO15118_20_SID_AC_BPT:
        {
          /* BPT_Dynamic_AC_CLReqControlMode */
          MsgPtr->CLReqControlModeElementId = EXI_ISO_20_AC_10_BPT_DYNAMIC_AC_CLREQ_CONTROL_MODE_TYPE;
          MsgPtr->CLReqControlMode
            = (P2VAR(Exi_ISO_20_CT_10_CLReqControlModeType, AUTOMATIC, SCC_VAR_NOINIT))                                 /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlModeType), Exi_BT_True);
          if (MsgPtr->CLReqControlMode != NULL_PTR)
          {
            /* Fetch BPT_Dynamic_AC_CLReqControlMode from application */
            Scc_ISO15118_20AC_InterfaceCfg_ExiTx_Get_BPT_Dynamic_AC_CLReqControlMode(
              (P2VAR(Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA))MsgPtr->CLReqControlMode); /* PRQA S 0316 */ /* MD_Scc_Exi_Generic */
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
        /* #90 [V2G20-1215] If AC charging: Fetch Scheduled_AC_CLReqControlMode from application */
        case Scc_ISO15118_20_SID_AC:
        {
          /* Scheduled_AC_CLReqControlMode */
          MsgPtr->CLReqControlModeElementId = EXI_ISO_20_AC_10_SCHEDULED_AC_CLREQ_CONTROL_MODE_TYPE;
          MsgPtr->CLReqControlMode
            = (P2VAR(Exi_ISO_20_CT_10_CLReqControlModeType, AUTOMATIC, SCC_VAR_NOINIT))                                 /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_AC_10_Scheduled_AC_CLReqControlModeType), Exi_BT_True);
          if (MsgPtr->CLReqControlMode != NULL_PTR)
          {
            /* Fetch Scheduled_AC_CLReqControlMode from application */
            Scc_ISO15118_20AC_InterfaceCfg_ExiTx_Get_Scheduled_AC_CLReqControlMode(
              (P2VAR(Exi_ISO_20_AC_10_Scheduled_AC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA))MsgPtr->CLReqControlMode); /* PRQA S 0316 */ /* MD_Scc_Exi_Generic */
            retVal = Scc_ReturnType_OK;
          }
          break;
        }
#if (defined SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON)
        /* #100 [V2G20-1215],[V2G20-1766],[V2G20-2652] If BPT enabled: If AC_BPT charging: Fetch BPT_Scheduled_AC_CLReqControlMode from application */
        case Scc_ISO15118_20_SID_AC_BPT:
        {
          /* BPT_Scheduled_AC_CLReqControlMode */
          MsgPtr->CLReqControlModeElementId = EXI_ISO_20_AC_10_BPT_SCHEDULED_AC_CLREQ_CONTROL_MODE_TYPE;
          MsgPtr->CLReqControlMode
            = (P2VAR(Exi_ISO_20_CT_10_CLReqControlModeType, AUTOMATIC, SCC_VAR_NOINIT))                                 /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlModeType), Exi_BT_True);
          if (MsgPtr->CLReqControlMode != NULL_PTR)
          {
            /* Fetch BPT_Scheduled_AC_CLReqControlMode from application */
            Scc_ISO15118_20AC_InterfaceCfg_ExiTx_Get_BPT_Scheduled_AC_CLReqControlMode(
              (P2VAR(Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA))MsgPtr->CLReqControlMode); /* PRQA S 0316 */ /* MD_Scc_Exi_Generic */
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
      Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Iso_20AC_ChargeLoopReqInvalidControlMode);
      retVal = Scc_ReturnType_NotOK;
      break;
  }

  return retVal;
}

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SCHEMA_ISO_20AC */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20AC_ExiTx.c
 *********************************************************************************************************************/
