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
/*!        \file  Scc_ISO15118_20ACDP_ExiTx.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to the specifications ISO/IEC 15118-20 ACDP schema
 *                specific parts.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_ISO15118_20ACDP_EXITX_SOURCE

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
#include "Scc_ISO15118_20_TimerCfg.h"
#include "Scc_Priv.h"
#include "Scc_ISO15118_20_InterfaceCfg.h"

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
 *  Scc_ISO15118_20ACDP_ExiTx_<ISO15118-20-Request>
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
/* see pattern Scc_ISO15118_20ACDP_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_ExiTx_ACDP_VehiclePositioningReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
/* see pattern Scc_ISO15118_20ACDP_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_ExiTx_ACDP_ConnectReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
/* see pattern Scc_ISO15118_20ACDP_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_ExiTx_ACDP_DisconnectReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
#if ( (defined SCC_ENABLE_ACDP_SYSTEM_STATUS) && (SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON) )
/* see pattern Scc_ISO15118_20ACDP_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_ExiTx_ACDP_SystemStatusReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
#endif /* SCC_ENABLE_ACDP_SYSTEM_STATUS */

/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_ExiTx_PrepareMessageCreateMessage
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20ACDP_ExiTx_PrepareMessageCreateMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_ExiTx_SAPSetEntry
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
FUNC(void, SCC_CODE) Scc_ISO15118_20ACDP_ExiTx_SAPSetEntry(
  P2VAR(Exi_SAP_AppProtocolType, AUTOMATIC, SCC_APPL_DATA) AppProtocolPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* [V2G20-2132]  */
  /* #10 Copy the namespace string */
  /* PRQA S 0310,3305,0315 3 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy */
  IpBase_Copy(
    (P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&AppProtocolPtr->ProtocolNamespace->Buffer[0],
    (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))SCC_ISO15118_20ACDP_EXI_SAP_PROTOCOL_NAMESPACE,
    SCC_ISO15118_20ACDP_EXI_SAP_PROTOCOL_NAMESPACE_LEN);
  /* #20 Set namespace length */
  AppProtocolPtr->ProtocolNamespace->Length = SCC_ISO15118_20ACDP_EXI_SAP_PROTOCOL_NAMESPACE_LEN;
  /* #30 Set VersionNumberMajor */
  AppProtocolPtr->VersionNumberMajor = SCC_ISO15118_20ACDP_EXI_SAP_VERSION_NUMBER_MAJOR;
  /* #40 Set VersionNumberMinor */
  AppProtocolPtr->VersionNumberMinor = SCC_ISO15118_20ACDP_EXI_SAP_VERSION_NUMBER_MINOR;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_ExiTx_PrepareMessage
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
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20ACDP_ExiTx_PrepareMessage(
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
    TxMsgWSPtr->payloadType = SCC_V2GTP_HDR_PAYLOAD_TYPE_ACDP;

#if ( (defined SCC_ENABLE_ACDP_SYSTEM_STATUS) && (SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON) )
    /* #20 Check if the message is transmitted on SystemStatus channel */
    if (Scc_Core_Channel_Get_CurrentChannel() == SCC_CHANNEL_SYSTEM_STATUS)
    {
      /* #30 Change buffer type to Small */
      poolBuffType = SCC_POOL_BUFF_SMALL;
    }
#endif /* SCC_ENABLE_ACDP_SYSTEM_STATUS */

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
    retVal = Scc_ISO15118_20ACDP_ExiTx_PrepareMessageCreateMessage(TxMsgWSPtr);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_ExiTx_PrepareMessageCreateMessage
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20ACDP_ExiTx_PrepareMessageCreateMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 create request message and set MessageTimeout */
  switch (Scc_Core_Channel_Get_MsgTrig())
  {
  case Scc_MsgTrig_ACDP_VehiclePositioning:
    retVal = Scc_ISO15118_20ACDP_ExiTx_ACDP_VehiclePositioningReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
    if (retVal == Scc_ReturnType_OK)
    {
      /* [V2G20-4020]: Setup V2G_EVCC_Msg_Timeout */
      Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_VehiclePositioningMessageTimeout();
    }
    break;
  case Scc_MsgTrig_ACDP_Connect:
    retVal = Scc_ISO15118_20ACDP_ExiTx_ACDP_ConnectReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
    if (retVal == Scc_ReturnType_OK)
    {
      /* [V2G20-4020]: Setup V2G_EVCC_Msg_Timeout */
      Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_ConnectMessageTimeout();
    }
    break;
  case Scc_MsgTrig_ACDP_Disconnect:
    retVal = Scc_ISO15118_20ACDP_ExiTx_ACDP_DisconnectReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
    if (retVal == Scc_ReturnType_OK)
    {
      /* [V2G20-4020]: Setup V2G_EVCC_Msg_Timeout */
      Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_DisconnectMessageTimeout();
    }
    break;
#if ( (defined SCC_ENABLE_ACDP_SYSTEM_STATUS) && (SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON) )
  case Scc_MsgTrig_ACDP_SystemStatus:
    /* #20 Check if the message is received on the right channel */
    if (Scc_Core_Channel_Get_CurrentChannel() == SCC_CHANNEL_SYSTEM_STATUS)
    {
      retVal = Scc_ISO15118_20ACDP_ExiTx_ACDP_SystemStatusReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
      if (retVal == Scc_ReturnType_OK)
      {
        /* [V2G20-4020]: Setup V2G_EVCC_Msg_Timeout */
        Scc_TimeoutCnt[SCC_CHANNEL_SYSTEM_STATUS] = (uint16)Scc_ISO15118_20_TimerCfg_Get_SystemStatusMessageTimeout();

        /* ISO 15118 - 20, Table 14 / chapter 8.3.4.7.3, Note 2 */
        TxMsgWSPtr->payloadType = SCC_V2GTP_HDR_PAYLOAD_TYPE_ACDP_SYSTEM_STATUS;
      }
    }
    /* #30 Otherwise */
    else
    {
      /* retVal set to Scc_ReturnType_NotOK already */
    }
    break;
#endif /* SCC_ENABLE_ACDP_SYSTEM_STATUS */

  default:
    /* retVal already set to Scc_ReturnType_NotOK */
    break;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_ExiTx_ACDP_VehiclePositioningReq
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_ExiTx_ACDP_VehiclePositioningReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningReqType, AUTOMATIC, SCC_VAR_NOINIT))                             /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
    Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    /* [V2G20-4004] */
    /* #30 Fill the EXI structure with parameter values */
    *RootElementIdPtr = EXI_ISO_20_ACDP_10_ACDP_VEHICLE_POSITIONING_REQ_TYPE;

    /* #40 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #50 Check if header was written successfully */
    if (retVal == Scc_ReturnType_OK)
    {
      /* #60 Fetch EVMobilityStatus from application */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiTx_Get_EVMobilityStatus(&msgPtr->EVMobilityStatus);

      /* #70 Fetch EVPositioningSupport from application */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiTx_Get_EVPositioningSupport(&msgPtr->EVPositioningSupport);
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_ExiTx_ACDP_ConnectReq
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_ExiTx_ACDP_ConnectReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_ACDP_10_ACDP_ConnectReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_ACDP_10_ACDP_ConnectReqType, AUTOMATIC, SCC_VAR_NOINIT))                                        /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
    Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_ACDP_10_ACDP_ConnectReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    /* [V2G20-4006] */
    /* #30 Fill the EXI structure with parameter values */
    *RootElementIdPtr = EXI_ISO_20_ACDP_10_ACDP_CONNECT_REQ_TYPE;

    /* #40 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #50 Check if header was written successfully */
    if (retVal == Scc_ReturnType_OK)
    {
      /* #60 Fetch EVElectricalChargingDeviceStatus from application */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiTx_Get_EVElectricalChargingDeviceStatus(&msgPtr->EVElectricalChargingDeviceStatus);
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_ExiTx_ACDP_DisconnectReq
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_ExiTx_ACDP_DisconnectReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_ACDP_10_ACDP_ConnectReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_ACDP_10_ACDP_ConnectReqType, AUTOMATIC, SCC_VAR_NOINIT))                                        /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
    Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_ACDP_10_ACDP_ConnectReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    /* [V2G20-4008] */
    /* #30 Fill the EXI structure with parameter values */
    *RootElementIdPtr = EXI_ISO_20_ACDP_10_ACDP_DISCONNECT_REQ_TYPE;

    /* #40 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #50 Check if header was written successfully */
    if (retVal == Scc_ReturnType_OK)
    {
      /* #60 Fetch EVElectricalChargingDeviceStatus from application */
      Scc_ISO15118_20ACDP_InterfaceCfg_ExiTx_Get_EVElectricalChargingDeviceStatus(&msgPtr->EVElectricalChargingDeviceStatus);
    }
  }

  return retVal;
}

#if ( (defined SCC_ENABLE_ACDP_SYSTEM_STATUS) && (SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON) )
/**********************************************************************************************************************
 *  Scc_ISO15118_20ACDP_ExiTx_ACDP_SystemStatusReq
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20ACDP_ExiTx_ACDP_SystemStatusReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_ACDP_10_ACDP_SystemStatusReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_ACDP_10_ACDP_SystemStatusReqType, AUTOMATIC, SCC_VAR_NOINIT))                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
    Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_ACDP_10_ACDP_SystemStatusReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    /* [V2G20-4010] */
    /* #30 Fill the EXI structure with parameter values */
    *RootElementIdPtr = EXI_ISO_20_ACDP_10_ACDP_SYSTEM_STATUS_REQ_TYPE;

    /* #40 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #50 Check if header was written successfully */
    if (retVal == Scc_ReturnType_OK)
    {
      retVal = Scc_ReturnType_NotOK;

      /* PRQA S 0310,3305 1 */ /* MD_Scc_0310_0314_0316_3305 */
      msgPtr->EVTechnicalStatus
        = (P2VAR(Exi_ISO_20_ACDP_10_EVTechnicalStatusType, AUTOMATIC, SCC_VAR_NOINIT))                                  /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_ACDP_10_EVTechnicalStatusType), Exi_BT_True);
      if (msgPtr->EVTechnicalStatus != NULL_PTR)
      {
        /* #60 Fetch EVTechnicalStatus from application */
        Scc_ISO15118_20ACDP_InterfaceCfg_ExiTx_Get_EVTechnicalStatus(msgPtr->EVTechnicalStatus);
        retVal = Scc_ReturnType_OK;
      }
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_ACDP_SYSTEM_STATUS */

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SCHEMA_ISO_20ACDP */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20ACDP_ExiTx.c
 *********************************************************************************************************************/
