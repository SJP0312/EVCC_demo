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
/*!        \file  Scc_DIN70121_ExiTx.c
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

#define SCC_DIN70121_EXITX_SOURCE

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
#include "Scc_DIN70121_TimerCfg.h"
#include "Scc_Core_Channel.h"
#include "Scc_BufferPool.h"

#include "Scc_Core_InterfaceCfg.h"

/* Forgein modules */
#include "TcpIp.h"
#include "Exi.h"

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

/**********************************************************************************************************************
 *  LOCAL / GLOBAL DATA
 *********************************************************************************************************************/

/* Other variables */
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
/* PRQA S 3473 MACROS_FUNCTION_LIKE */ /* MD_MSR_FctLikeMacro */

/* PRQA L:MACROS_FUNCTION_LIKE */
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_<DIN-Request>
 *********************************************************************************************************************/
/*! \brief          Set all parameters for DIN request message
 *  \details        Set all parameters for the body element of the request message.
 *  \param[in,out]  ExiAllocWsPtr      Pointer to the allocation workspace that shall be used.
 *  \param[out]     MsgBodyPtr         Pointer to the base message that should be enhanced by the specialized message type.
 *  \return         TRUE               Message was created.
 *  \return         FALSE              Message was not created, error occurred.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/

/* Common */
/* See pattern Scc_DIN70121_ExiTx_<DIN-Request> */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_SessionSetupReq(P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr);
/* See pattern Scc_DIN70121_ExiTx_<DIN-Request> */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_ServiceDiscoveryReq(P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr);
/* See pattern Scc_DIN70121_ExiTx_<DIN-Request> */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_ServicePaymentSelectionReq(P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr);
/* See pattern Scc_DIN70121_ExiTx_<DIN-Request> */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_ContractAuthenticationReq(P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr);
/* See pattern Scc_DIN70121_ExiTx_<DIN-Request> */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_ChargeParameterDiscoveryReq(P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr);
/* See pattern Scc_DIN70121_ExiTx_<DIN-Request> */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_PowerDeliveryReq(P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr);
/* See pattern Scc_DIN70121_ExiTx_<DIN-Request> */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_SessionStopReq(P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr);

/* DC */
/* See pattern Scc_DIN70121_ExiTx_<DIN-Request> */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_CableCheckReq(P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr);
/* See pattern Scc_DIN70121_ExiTx_<DIN-Request> */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_PreChargeReq(P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr);
/* See pattern Scc_DIN70121_ExiTx_<DIN-Request> */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_CurrentDemandReq(P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr);
/* See pattern Scc_DIN70121_ExiTx_<DIN-Request> */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_WeldingDetectionReq(P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr);


/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_CreateMessage
 *********************************************************************************************************************/
/*! \brief          Creates the header and the abstract body of a V2G message.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr      Pointer to the allocation workspace that shall be used.
 *  \param[out]     DinMsgPtr          Pointer to the base message that should be created.
 *  \return         TRUE               Message was created.
 *  \return         FALSE              Message was not created, error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_CreateMessage(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_V2G_MessageType*, AUTOMATIC, SCC_APPL_DATA) DinMsgPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_CreateHeader
 *********************************************************************************************************************/
/*! \brief          Creates the header of a DIN V2G message.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr      Pointer to the allocation workspace that shall be used.
 *  \param[out]     DinHeaderPtr       Pointer to the header that should be created.
 *  \return         TRUE               Message was created.
 *  \return         FALSE              Message was not created, error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_CreateHeader(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_MessageHeaderType*, AUTOMATIC, SCC_APPL_DATA) DinHeaderPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_CreateAbstractBody
 *********************************************************************************************************************/
/*! \brief          Creates the abstract body of a DIN V2G message.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr      Pointer to the allocation workspace that shall be used.
 *  \param[out]     DinBodyPtr         Pointer to the base message that should be created.
 *  \return         TRUE               Body was created.
 *  \return         FALSE              Body was not created, error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_CreateAbstractBody(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_BodyType*, AUTOMATIC, SCC_APPL_DATA) DinBodyPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_CreateBody
 *********************************************************************************************************************/
/*! \brief          Creates the message specific body of a DIN V2G message.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr      Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  DinBodyPtr         Pointer to the base message that should be created.
 *  \return         TRUE               Body was created.
 *  \return         FALSE              Body was not created, error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_CreateBody(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) DinBodyPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_CreatePhysicalValueType
 *********************************************************************************************************************/
/*! \brief          Creates a DIN physical value type based on a Scc physical value type.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr             Pointer to the allocation workspace that shall be used.
 *  \param[in]      ValuePtr                  Pointer to the value that should be assigned.
 *  \param[in]      Unit                      The unit that shall be used.
 *  \param[out]     DINPhysicalValueTypePtr   Pointer to the DIN physical value that should be created.
 *  \return         TRUE                      Physical value type was created.
 *  \return         FALSE                     Physical value type was not created, error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_CreatePhysicalValueType(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) ValuePtr,
  Exi_DIN_unitSymbolType Unit,
  P2VAR(Exi_DIN_PhysicalValueType*, AUTOMATIC, SCC_VAR_NOINIT) DINPhysicalValueTypePtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_WriteEVStatusDC
 *********************************************************************************************************************/
/*! \brief          Creates and assigns values for an EVStatus element.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr             Pointer to the allocation workspace that shall be used.
 *  \param[out]     EVStatusPtr               Pointer to the EV Status that should be created.
 *  \return         TRUE                      EVStatus type was created.
 *  \return         FALSE                     EVStatus type was not created, error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_WriteEVStatusDC(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_DC_EVStatusType*, AUTOMATIC, SCC_VAR_NOINIT) EVStatusPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_WriteDCEVChargeParameterType
 *********************************************************************************************************************/
/*! \brief          Creates and assigns values for an DC_EVChargeParameterType element.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr             Pointer to the allocation workspace that shall be used.
 *  \param[out]     DcEvChargeParamTypePtr    Pointer to the DC_EVChargeParameterType element that should be created.
 *  \return         TRUE                      DC_EVChargeParameterType type was created.
 *  \return         FALSE                     DC_EVChargeParameterType type was not created, error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_WriteDCEVChargeParameterType(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_DC_EVChargeParameterType*, AUTOMATIC, SCC_VAR_NOINIT) DcEvChargeParamTypePtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_PrepareMessage
 *********************************************************************************************************************/
/*! \brief          Prepares the EXI request message to be transmitted
 *  \details        -
 *  \param[in,out]  TxMsgWSPtr                  Pointer to the Tx message workspace
 *  \return         Scc_ReturnType_OK           Exi preparation was successful
 *  \return         Scc_ReturnType_NotOK        Exi preparation was not successful or timeout happened
 *  \return         Scc_ReturnType_Pending      Message handling is pending, try again later
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_DIN70121_ExiTx_PrepareMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_SetupTxConfig
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_DIN70121_ExiTx_SetupTxConfig(
  P2VAR(Scc_ExiTx_Xyz_PrepareMessageFctType, AUTOMATIC, SCC_APPL_DATA) TxPrepMessagePtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Setup the passed prepare message function pointer */
  *TxPrepMessagePtr = &Scc_DIN70121_ExiTx_PrepareMessage;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_SAPSetEntry
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_DIN70121_ExiTx_SAPSetEntry(
  P2VAR(Exi_SAP_AppProtocolType, AUTOMATIC, SCC_APPL_DATA) AppProtocolPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* [V2G-DC-229] */
  /* #10 Copy the namespace string */
  /* PRQA S 0310,3305,0315 3 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy */
  IpBase_Copy(
    (P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&AppProtocolPtr->ProtocolNamespace->Buffer[0],
    (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))SCC_DIN70121_EXI_SAP_PROTOCOL_NAMESPACE,
    SCC_DIN70121_EXI_SAP_PROTOCOL_NAMESPACE_LEN);
  /* #20 Set namespace length */
  AppProtocolPtr->ProtocolNamespace->Length = SCC_DIN70121_EXI_SAP_PROTOCOL_NAMESPACE_LEN;
  /* #30 Set VersionNumberMajor */
  AppProtocolPtr->VersionNumberMajor = SCC_DIN70121_EXI_SAP_VERSION_NUMBER_MAJOR;
  /* #40 Set VersionNumberMinor */
  AppProtocolPtr->VersionNumberMinor = SCC_DIN70121_EXI_SAP_VERSION_NUMBER_MINOR;
}


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_PrepareMessage
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_DIN70121_ExiTx_PrepareMessage(P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  P2VAR(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) dinMsgPtr = NULL_PTR;
  uint8 bufferPoolId = 0;
  P2VAR(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                    Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get MsgPtr and MsgPtrSize */
  if (Scc_BufferPoolRequestGetBuffer(SCC_POOL_BUFF_LARGE, &buffPoolWsPtr->MsgPtr, &buffPoolWsPtr->MsgPtrSize, &bufferPoolId) != E_OK)
  {
    /* Do nothing. Error already reported */
  }
  else
  {
    /* #20 Store the bufferPoolId */
    Scc_Core_Channel_Set_BufferPoolId(bufferPoolId);
    /* #30 Check if EXI alloc workspace can be initialized */
    if (Exi_InitMemAllocWorkspace(&TxMsgWSPtr->Exi_AllocWs, buffPoolWsPtr->MsgPtr, 0u, buffPoolWsPtr->MsgPtrSize) == EXI_E_OK)
    {
      /* #40 Check if TX message can be created */
      if (Scc_DIN70121_ExiTx_CreateMessage(&TxMsgWSPtr->Exi_AllocWs, &dinMsgPtr) == TRUE)
      {
        /* #50 Yes: Set the V2G_Message type as root element */
        TxMsgWSPtr->RootElementId = EXI_DIN_V2G_MESSAGE_TYPE;
        TxMsgWSPtr->payloadType = SCC_V2GTP_HDR_PAYLOAD_TYPE_EXI;
        retVal = Scc_ReturnType_OK;
      }
      else
      {
        /* #60 No: Report error */
        Scc_ReportError(Scc_StackError_Unspecified, SccDetailedError_Din_EncodeMessageFailed);
        retVal = Scc_ReturnType_NotOK;
      }
    }
    else
    {
      /* Do nothing */
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_SessionSetupReq
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
 */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_SessionSetupReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean messageCreated = FALSE;
  P2VAR(Exi_DIN_SessionSetupReqType, AUTOMATIC, SCC_APPL_DATA) bodyPtr
    = (P2VAR(Exi_DIN_SessionSetupReqType, AUTOMATIC, SCC_VAR_NOINIT))                                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_SessionSetupReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_DIN_SESSION_SETUP_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_DIN_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                          /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

    /* #30 Create the EVCCID */
    bodyPtr->EVCCID
      = (P2VAR(Exi_DIN_evccIDType, AUTOMATIC, SCC_APPL_DATA))                                                           /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_evccIDType), Exi_BT_True);
    /* #40 Check if EVCCID was created */
    if (bodyPtr->EVCCID != NULL_PTR)
    {
      /* #50 Get MAC address from EthIf */
      (void)TcpIp_GetPhysAddr(Scc_LocalAddrId, &bodyPtr->EVCCID->Buffer[0]);
      bodyPtr->EVCCID->Length = 6;
      messageCreated = TRUE;
    }
  }

  return messageCreated;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_ServiceDiscoveryReq
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_ServiceDiscoveryReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  CONSTP2VAR(Exi_DIN_ServiceDiscoveryReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_DIN_ServiceDiscoveryReqType, AUTOMATIC, SCC_VAR_NOINIT))                                               /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_ServiceDiscoveryReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_DIN_SERVICE_DISCOVERY_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_DIN_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                          /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

    /* ServiceScope */
    bodyPtr->ServiceScopeFlag = 0u;

    /* ServiceCategory */
    {
      boolean flag = FALSE;
      Scc_DIN70121_InterfaceCfg_ExiTx_Get_ServiceCategory(&bodyPtr->ServiceCategory, &flag);
      bodyPtr->ServiceCategoryFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                                      /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
    }
  }

  return bodyPtr != NULL_PTR;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_ServicePaymentSelectionReq
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
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_ServicePaymentSelectionReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean messageCreated = FALSE;
  CONSTP2VAR(Exi_DIN_ServicePaymentSelectionReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_DIN_ServicePaymentSelectionReqType, AUTOMATIC, SCC_VAR_NOINIT))                                        /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_ServicePaymentSelectionReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_DIN_SERVICE_PAYMENT_SELECTION_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_DIN_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                          /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

    /* [V2G-DC-252]: Only ExternalPayment shall be used */
    bodyPtr->SelectedPaymentOption = EXI_DIN_PAYMENT_OPTION_TYPE_EXTERNAL_PAYMENT;

    /* #30 Create a SelectedServiceList */
    bodyPtr->SelectedServiceList
      = (P2VAR(Exi_DIN_SelectedServiceListType, AUTOMATIC, SCC_APPL_DATA))                                              /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_SelectedServiceListType), Exi_BT_True);
    /* #40 Check if the list was created */
    if (bodyPtr->SelectedServiceList != NULL_PTR)
    {
      /* #50 Create a SelectedService */
      bodyPtr->SelectedServiceList->SelectedService
        = (P2VAR(Exi_DIN_SelectedServiceType, AUTOMATIC, SCC_APPL_DATA))                                                /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_SelectedServiceType), Exi_BT_True);
      /* #60 Check if the selected service was created */
      if (bodyPtr->SelectedServiceList->SelectedService != NULL_PTR)
      {
        /* #70 Set the SelectedService */
        bodyPtr->SelectedServiceList->SelectedService->ServiceID = Scc_DIN70121_ExiRx_ServiceID;
        bodyPtr->SelectedServiceList->SelectedService->ParameterSetIDFlag = 0;
        bodyPtr->SelectedServiceList->SelectedService->NextSelectedServicePtr = NULL_PTR;

        messageCreated = TRUE;
      }
    }
  }

  return messageCreated;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_ContractAuthenticationReq
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_ContractAuthenticationReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  CONSTP2VAR(Exi_DIN_ContractAuthenticationReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_DIN_ContractAuthenticationReqType, AUTOMATIC, SCC_VAR_NOINIT))                                         /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_ContractAuthenticationReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_DIN_CONTRACT_AUTHENTICATION_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_DIN_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                          /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

    /* GenChallenge */
    bodyPtr->IdFlag = 0u;
    bodyPtr->GenChallengeFlag = 0u;
  }

  return bodyPtr != NULL_PTR;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_ChargeParameterDiscoveryReq
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_ChargeParameterDiscoveryReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean messageCreated = FALSE;
  CONSTP2VAR(Exi_DIN_ChargeParameterDiscoveryReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_DIN_ChargeParameterDiscoveryReqType, AUTOMATIC, SCC_VAR_NOINIT))                                       /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_ChargeParameterDiscoveryReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_DIN_CHARGE_PARAMETER_DISCOVERY_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_DIN_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                          /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

    /* EVRequestedEnergyTransferType */
    Scc_DIN70121_InterfaceCfg_ExiTx_Get_RequestedEnergyTransferMode(&bodyPtr->EVRequestedEnergyTransferType);

    /* EVChargeParameter -> Exi_DIN_DC_EVChargeParameterType */ /* PRQA S 0310,0316 1 */ /* MD_Scc_0310_0314_0316_3305 */
    messageCreated = Scc_DIN70121_ExiTx_WriteDCEVChargeParameterType(ExiAllocWsPtr, (P2VAR(Exi_DIN_DC_EVChargeParameterType*, AUTOMATIC, SCC_VAR_NOINIT))&bodyPtr->EVChargeParameter);

    /* EVChargeParameterElementId */
    bodyPtr->EVChargeParameterElementId = EXI_DIN_DC_EVCHARGE_PARAMETER_TYPE;
  }

  return messageCreated;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_PowerDeliveryReq
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_PowerDeliveryReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean messageCreated = FALSE;
  CONSTP2VAR(Exi_DIN_PowerDeliveryReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_DIN_PowerDeliveryReqType, AUTOMATIC, SCC_VAR_NOINIT))                                                  /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_PowerDeliveryReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    boolean flag = FALSE;

    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_DIN_POWER_DELIVERY_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_DIN_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                          /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

    /* ReadyToChargeState */
    Scc_DIN70121_InterfaceCfg_ExiTx_Get_ReadyToChargeState(&bodyPtr->ReadyToChargeState);

    /* ChargingProfile */
    Scc_DIN70121_InterfaceCfg_ExiTx_Get_ChargingProfilePtr(&bodyPtr->ChargingProfile, &flag);
    bodyPtr->ChargingProfileFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                                        /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */

    /* Check if the EVPowerDeliveryParameter shall be send */
    Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVPowerDeliveryParameterFlag(&flag);
    if (flag == TRUE)
    {
      /* Get the pointer to the Exi_DIN_DC_EVPowerDeliveryParameterType */
      bodyPtr->EVPowerDeliveryParameter
        = (P2VAR(Exi_DIN_EVPowerDeliveryParameterType, AUTOMATIC, SCC_APPL_DATA))                                       /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_DC_EVPowerDeliveryParameterType), Exi_BT_True);

      if (bodyPtr->EVPowerDeliveryParameter != NULL_PTR)
      {
        CONSTP2VAR(Exi_DIN_DC_EVPowerDeliveryParameterType, AUTOMATIC, SCC_APPL_DATA) dc_EVPowerDeliveryParameter
          = (P2VAR(Exi_DIN_DC_EVPowerDeliveryParameterType, AUTOMATIC, SCC_APPL_DATA))bodyPtr->EVPowerDeliveryParameter; /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */

        /* DC_EVPowerDeliveryParameter */
        bodyPtr->EVPowerDeliveryParameterElementId = EXI_DIN_DC_EVPOWER_DELIVERY_PARAMETER_TYPE;
        bodyPtr->EVPowerDeliveryParameterFlag = 1;

        /* DC_EVPowerDeliveryParameter -> DC_EVStatus */
        messageCreated = Scc_DIN70121_ExiTx_WriteEVStatusDC(ExiAllocWsPtr, &dc_EVPowerDeliveryParameter->DC_EVStatus);

        /* DC_EVPowerDeliveryParameter -> BulkChargingComplete */
        Scc_DIN70121_InterfaceCfg_ExiTx_Get_BulkChargingComplete(&dc_EVPowerDeliveryParameter->BulkChargingComplete, &flag);
        dc_EVPowerDeliveryParameter->BulkChargingCompleteFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                           /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */

        /* DC_EVPowerDeliveryParameter -> ChargingComplete */
        Scc_DIN70121_InterfaceCfg_ExiTx_Get_ChargingComplete(&dc_EVPowerDeliveryParameter->ChargingComplete);
      }
    }
    else
    {
      bodyPtr->EVPowerDeliveryParameterFlag = 0u;
      messageCreated = TRUE;
    }
  }

  return messageCreated;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_SessionStopReq
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_SessionStopReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,                                             /* PRQA S 3206, 3673 */ /* MD_SCC_CORE_GENERIC_INTERFACE */
  P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  SCC_DUMMY_STATEMENT_CONST(ExiAllocWsPtr);                                                                             /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Fill the EXI structure with parameter values */
  MsgBodyPtr->BodyElementElementId = EXI_DIN_SESSION_STOP_REQ_TYPE;
  MsgBodyPtr->BodyElement = (P2VAR(Exi_DIN_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) NULL_PTR;

  return TRUE;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_CableCheckReq
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_CableCheckReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean messageCreated = FALSE;
  CONSTP2VAR(Exi_DIN_CableCheckReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_DIN_CableCheckReqType, AUTOMATIC, SCC_VAR_NOINIT))                                                     /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_CableCheckReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_DIN_CABLE_CHECK_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_DIN_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                          /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

    /* DC_EVStatus */
    messageCreated = Scc_DIN70121_ExiTx_WriteEVStatusDC(ExiAllocWsPtr, &bodyPtr->DC_EVStatus);
  }

  return messageCreated;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_PreChargeReq
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_PreChargeReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean messageCreated = FALSE;
  CONSTP2VAR(Exi_DIN_PreChargeReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_DIN_PreChargeReqType, AUTOMATIC, SCC_VAR_NOINIT))                                                      /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_PreChargeReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_DIN_PRE_CHARGE_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_DIN_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                          /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

    /* DC_EVStatus */
    messageCreated = Scc_DIN70121_ExiTx_WriteEVStatusDC(ExiAllocWsPtr, &bodyPtr->DC_EVStatus);
    /* EVTargetVoltage */
    if (messageCreated == TRUE)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVTargetVoltage(&scc_PhysicalValueTmp);
      messageCreated = Scc_DIN70121_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_DIN_UNIT_SYMBOL_TYPE_V, &bodyPtr->EVTargetVoltage);
    }
    /* EVTargetCurrent */
    if (messageCreated == TRUE)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVTargetCurrent(&scc_PhysicalValueTmp);
      messageCreated = Scc_DIN70121_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_DIN_UNIT_SYMBOL_TYPE_A, &bodyPtr->EVTargetCurrent);
    }
  }

  return messageCreated;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_CurrentDemandReq
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010 1 */ /* MD_MSR_STPTH */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_CurrentDemandReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean messageCreated = FALSE;
  CONSTP2VAR(Exi_DIN_CurrentDemandReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_DIN_CurrentDemandReqType, AUTOMATIC, SCC_VAR_NOINIT))                                                  /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_CurrentDemandReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_DIN_CURRENT_DEMAND_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_DIN_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                          /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

    /* DC_EVStatus */
    messageCreated = Scc_DIN70121_ExiTx_WriteEVStatusDC(ExiAllocWsPtr, &bodyPtr->DC_EVStatus);
    /* EVTargetCurrent */
    if (messageCreated == TRUE)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVTargetCurrent(&scc_PhysicalValueTmp);
      messageCreated = Scc_DIN70121_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_DIN_UNIT_SYMBOL_TYPE_A, &bodyPtr->EVTargetCurrent);
    }
    /* EVMaximumVoltageLimit */
    if (messageCreated == TRUE)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      boolean flag = FALSE;
      Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVMaximumVoltageLimit(&scc_PhysicalValueTmp, &flag);
      messageCreated = Scc_DIN70121_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_DIN_UNIT_SYMBOL_TYPE_V, &bodyPtr->EVMaximumVoltageLimit);
      bodyPtr->EVMaximumVoltageLimitFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                                /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
    }
    /* EVMaximumCurrentLimit */
    if (messageCreated == TRUE)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      boolean flag = FALSE;
      Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVMaximumCurrentLimit(&scc_PhysicalValueTmp, &flag);
      messageCreated = Scc_DIN70121_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_DIN_UNIT_SYMBOL_TYPE_A, &bodyPtr->EVMaximumCurrentLimit);
      bodyPtr->EVMaximumCurrentLimitFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                                /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
    }
    /* EVMaximumPowerLimit */
    if (messageCreated == TRUE)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      boolean flag = FALSE;
      Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVMaximumPowerLimit(&scc_PhysicalValueTmp, &flag);
      messageCreated = Scc_DIN70121_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_DIN_UNIT_SYMBOL_TYPE_W, &bodyPtr->EVMaximumPowerLimit);
      bodyPtr->EVMaximumPowerLimitFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                                  /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
    }
    /* BulkChargingComplete */
    if (messageCreated == TRUE)
    {
      boolean flag = FALSE;
      Scc_DIN70121_InterfaceCfg_ExiTx_Get_BulkChargingComplete(&bodyPtr->BulkChargingComplete, &flag);
      bodyPtr->BulkChargingCompleteFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                                 /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */

    }
    /* ChargingComplete */
    Scc_DIN70121_InterfaceCfg_ExiTx_Get_ChargingComplete(&bodyPtr->ChargingComplete);
    /* RemainingTimeToFullSoC */
    if (messageCreated == TRUE)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      boolean flag = FALSE;
      Scc_DIN70121_InterfaceCfg_ExiTx_Get_RemainingTimeToFullSoC(&scc_PhysicalValueTmp, &flag);
      messageCreated = Scc_DIN70121_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_DIN_UNIT_SYMBOL_TYPE_S, &bodyPtr->RemainingTimeToFullSoC);
      bodyPtr->RemainingTimeToFullSoCFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                               /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
    }
    /* RemainingTimeToBulkSoC */
    if (messageCreated == TRUE)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      boolean flag = FALSE;
      Scc_DIN70121_InterfaceCfg_ExiTx_Get_RemainingTimeToBulkSoC(&scc_PhysicalValueTmp, &flag);
      messageCreated = Scc_DIN70121_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_DIN_UNIT_SYMBOL_TYPE_S, &bodyPtr->RemainingTimeToBulkSoC);
      bodyPtr->RemainingTimeToBulkSoCFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                               /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
    }
    /* EVTargetVoltage */
    if (messageCreated == TRUE)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVTargetVoltage(&scc_PhysicalValueTmp);
      messageCreated = Scc_DIN70121_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_DIN_UNIT_SYMBOL_TYPE_V, &bodyPtr->EVTargetVoltage);
    }
  }

  return messageCreated;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_WeldingDetectionReq
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_WeldingDetectionReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean messageCreated = FALSE;
  CONSTP2VAR(Exi_DIN_WeldingDetectionReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_DIN_WeldingDetectionReqType, AUTOMATIC, SCC_VAR_NOINIT))                                               /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_WeldingDetectionReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_DIN_WELDING_DETECTION_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_DIN_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                          /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

    /* DC_EVStatus */
    messageCreated = Scc_DIN70121_ExiTx_WriteEVStatusDC(ExiAllocWsPtr, &bodyPtr->DC_EVStatus);
  }

  return messageCreated;
}



/**********************************************************************************************************************
 *  LOCAL HELPER FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_CreateMessage
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_CreateMessage(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_V2G_MessageType*, AUTOMATIC, SCC_APPL_DATA) DinMsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean messageCreated = FALSE;
  CONSTP2VAR(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) dinMsgPtr
    = (P2VAR(Exi_DIN_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA))                                                        /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_V2G_MessageType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message was created */
  if (dinMsgPtr != NULL_PTR)
  {
    /* #20 Initialize the header of the V2G messages */
    if (Scc_DIN70121_ExiTx_CreateHeader(ExiAllocWsPtr, &dinMsgPtr->Header) == TRUE)
    {
      /* #30 Initialize the body of the V2G messages */
      if (Scc_DIN70121_ExiTx_CreateAbstractBody(ExiAllocWsPtr, &dinMsgPtr->Body) == TRUE)
      {
        if (Scc_DIN70121_ExiTx_CreateBody(ExiAllocWsPtr, dinMsgPtr->Body) == TRUE)
        {
          messageCreated = TRUE;
          *DinMsgPtr = dinMsgPtr;
        }
      }
    }
  }

  return messageCreated;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_CreateAbstractBody
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_CreateAbstractBody(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_BodyType*, AUTOMATIC, SCC_APPL_DATA) DinBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* Allocate buffer for BodyType element */
  P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) bodyPtr
    = (P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA))                                                               /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_BodyType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #20 Set the common body parameters */
    bodyPtr->BodyElementFlag = 1;

    *DinBodyPtr = bodyPtr;
  }

  return bodyPtr != NULL_PTR;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_CreateBody
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_CreateBody(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_BodyType, AUTOMATIC, SCC_APPL_DATA) DinBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean msgCreated = FALSE;

  /* #10 Create request message and set MessageTimeout based on current message trigger */
  switch (Scc_Core_Channel_Get_MsgTrig())
  {
    /* Check if a session setup request shall be sent */
    case Scc_MsgTrig_SessionSetup:
      msgCreated = Scc_DIN70121_ExiTx_SessionSetupReq(ExiAllocWsPtr, DinBodyPtr);
      if (msgCreated == TRUE)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = Scc_DIN70121_TimerCfg_Get_SessionSetupMessageTimeout();
      }
      break;

      /* Check if a service discovery request shall be sent */
    case Scc_MsgTrig_ServiceDiscovery:
      msgCreated = Scc_DIN70121_ExiTx_ServiceDiscoveryReq(ExiAllocWsPtr, DinBodyPtr);
      if (msgCreated == TRUE)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = Scc_DIN70121_TimerCfg_Get_ServiceDiscoveryMessageTimeout();
      }
      break;

      /* Check if a service payment selection request shall be sent */
    case Scc_MsgTrig_PaymentServiceSelection:
      msgCreated = Scc_DIN70121_ExiTx_ServicePaymentSelectionReq(ExiAllocWsPtr, DinBodyPtr);
      if (msgCreated == TRUE)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = Scc_DIN70121_TimerCfg_Get_ServicePaymentSelectionMessageTimeout();
      }
      break;

      /* Check if a contract authentication request shall be sent */
    case Scc_MsgTrig_Authorization:
      msgCreated = Scc_DIN70121_ExiTx_ContractAuthenticationReq(ExiAllocWsPtr, DinBodyPtr);
      if (msgCreated == TRUE)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = Scc_DIN70121_TimerCfg_Get_ContractAuthenticationMessageTimeout();
      }
      break;

      /* Check if a charge parameter discovery request shall be sent */
    case Scc_MsgTrig_ChargeParameterDiscovery:
      msgCreated = Scc_DIN70121_ExiTx_ChargeParameterDiscoveryReq(ExiAllocWsPtr, DinBodyPtr);
      if (msgCreated == TRUE)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = Scc_DIN70121_TimerCfg_Get_ChargeParameterDiscoveryMessageTimeout();
      }
      break;

      /* Check if a power delivery request shall be sent */
    case Scc_MsgTrig_PowerDelivery:
      msgCreated = Scc_DIN70121_ExiTx_PowerDeliveryReq(ExiAllocWsPtr, DinBodyPtr);
      if (msgCreated == TRUE)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = Scc_DIN70121_TimerCfg_Get_PowerDeliveryMessageTimeout();
      }
      break;

      /* Check if a session stop request shall be sent */
    case Scc_MsgTrig_SessionStop:
      msgCreated = Scc_DIN70121_ExiTx_SessionStopReq(ExiAllocWsPtr, DinBodyPtr);
      if (msgCreated == TRUE)                                                                                           /* PRQA S 2991,2995 */ /* MD_SCC_CORE_GENERIC_INTERFACE */
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = Scc_DIN70121_TimerCfg_Get_SessionStopMessageTimeout();
      }
      break;

      /* Check if a cable check request shall be sent */
    case Scc_MsgTrig_CableCheck:
      msgCreated = Scc_DIN70121_ExiTx_CableCheckReq(ExiAllocWsPtr, DinBodyPtr);
      if (msgCreated == TRUE)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = Scc_DIN70121_TimerCfg_Get_CableCheckMessageTimeout();
      }
      break;

      /* Check if a pre charge request shall be sent */
    case Scc_MsgTrig_PreCharge:
      msgCreated = Scc_DIN70121_ExiTx_PreChargeReq(ExiAllocWsPtr, DinBodyPtr);
      if (msgCreated == TRUE)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = Scc_DIN70121_TimerCfg_Get_PreChargeMessageTimeout();
      }
      break;

      /* Check if a current demand request shall be sent */
    case Scc_MsgTrig_CurrentDemand:
      msgCreated = Scc_DIN70121_ExiTx_CurrentDemandReq(ExiAllocWsPtr, DinBodyPtr);
      if (msgCreated == TRUE)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = Scc_DIN70121_TimerCfg_Get_CurrentDemandMessageTimeout();
      }
      break;

      /* Check if a welding detection request shall be sent */
    case Scc_MsgTrig_WeldingDetection:
      msgCreated = Scc_DIN70121_ExiTx_WeldingDetectionReq(ExiAllocWsPtr, DinBodyPtr);
      if (msgCreated == TRUE)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = Scc_DIN70121_TimerCfg_Get_WeldingDetectionMessageTimeout();
      }
      break;

    default:
      /* Report a V2G error of the current trigger */
      Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Din_EncodeMessageInvalidMsgTrigger);
      break;
  }

  return msgCreated;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_CreateHeader
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
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_CreateHeader(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_MessageHeaderType*, AUTOMATIC, SCC_APPL_DATA) DinHeaderPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean headerCreated = FALSE;
  /* Allocate buffer for MessageHeaderType element */
  P2VAR(Exi_DIN_MessageHeaderType, AUTOMATIC, SCC_APPL_DATA) headerPtr
    = (P2VAR(Exi_DIN_MessageHeaderType, AUTOMATIC, SCC_APPL_DATA))                                                      /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_MessageHeaderType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the header element was created */
  if (headerPtr != NULL_PTR)
  {
    /* #20 Set the buffer of the V2G message header */
    headerPtr->NotificationFlag = 0;
    headerPtr->SignatureFlag = 0;

    /* #30 Allocate buffer for sessionIdType */
    headerPtr->SessionID
      = (P2VAR(Exi_DIN_sessionIDType, AUTOMATIC, SCC_APPL_DATA))                                                        /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_sessionIDType), Exi_BT_True);

    /* #40 Check if sessionId was allocated */
    if (headerPtr->SessionID != NULL_PTR)
    {
      /* #50 Init SessionId */
      headerPtr->SessionID->Length = Scc_SessionIDNvm[0];
      /* #60 Copy the SessionID to the buffer */
      IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &headerPtr->SessionID->Buffer[0],
        (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &Scc_SessionIDNvm[1], (uint32)Scc_SessionIDNvm[0]);    /* PRQA S 0310,3305,0315 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy */

      *DinHeaderPtr = headerPtr;
      headerCreated = TRUE;
    }
  }

  return headerCreated;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_WriteEVStatusDC
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
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_WriteEVStatusDC(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_DC_EVStatusType*, AUTOMATIC, SCC_VAR_NOINIT) EVStatusPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  *EVStatusPtr
    = (P2VAR(Exi_DIN_DC_EVStatusType, AUTOMATIC, SCC_VAR_NOINIT))                                                       /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_DC_EVStatusType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if status element was created */
  if (*EVStatusPtr != NULL_PTR)
  {
    CONSTP2VAR(Exi_DIN_DC_EVStatusType, AUTOMATIC, SCC_VAR_NOINIT) evStatusPtr = *EVStatusPtr;
    boolean flag = FALSE;

    /* #20 Set EVReady based on interface API */
    Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVReady(&evStatusPtr->EVReady);

    /* #30 Set EVCabinConditioning based on interface API */
    Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVCabinConditioning(&evStatusPtr->EVCabinConditioning, &flag);
    evStatusPtr->EVCabinConditioningFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                                /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */

    /* #40 Set EVRESSConditioning based on interface API */
    Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVRESSConditioning(&evStatusPtr->EVRESSConditioning, &flag);
    evStatusPtr->EVRESSConditioningFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                                 /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */

    /* #50 Set EVErrorCode based on interface API */
    Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVErrorCode(&evStatusPtr->EVErrorCode);

    /* #60 Set EVRESSSOC based on interface API */
    Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVRESSSOC(&evStatusPtr->EVRESSSOC);
  }

  return *EVStatusPtr != NULL_PTR;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_WriteDCEVChargeParameterType
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_WriteDCEVChargeParameterType(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_DIN_DC_EVChargeParameterType*, AUTOMATIC, SCC_VAR_NOINIT) DcEvChargeParamTypePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean typeCreated = FALSE;
  *DcEvChargeParamTypePtr
    = (P2VAR(Exi_DIN_DC_EVChargeParameterType, AUTOMATIC, SCC_VAR_NOINIT))                                              /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_DC_EVChargeParameterType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if charge parameter type element was created */
  if (*DcEvChargeParamTypePtr != NULL_PTR)
  {
    P2VAR(Exi_DIN_DC_EVChargeParameterType, AUTOMATIC, SCC_VAR_NOINIT) dcChargeParamTypePtr = *DcEvChargeParamTypePtr;

    /* #20 Fill Exi structure for DIN_DC_EVChargeParameterType based on interface APIs */
    /* Setup DC_EVStatus */
    typeCreated = Scc_DIN70121_ExiTx_WriteEVStatusDC(ExiAllocWsPtr, &dcChargeParamTypePtr->DC_EVStatus);
    /* EVMaximumCurrentLimit */
    if (typeCreated == TRUE)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      boolean flag = FALSE;

      Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVMaximumCurrentLimit(&scc_PhysicalValueTmp, &flag);
      typeCreated = Scc_DIN70121_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_DIN_UNIT_SYMBOL_TYPE_A, &dcChargeParamTypePtr->EVMaximumCurrentLimit);
      /* Parameter is not optional for this message, check if it was set */
      if (flag != TRUE)
      {
        Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Din_ChargeParameterDiscoveryReqMissingEvmaximumcurrentlimit);
        typeCreated = FALSE;
      }
    }
    /* EVMaximumPowerLimit */
    if (typeCreated == TRUE)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      boolean flag = FALSE;

      Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVMaximumPowerLimit(&scc_PhysicalValueTmp, &flag);
      typeCreated = Scc_DIN70121_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_DIN_UNIT_SYMBOL_TYPE_W, &dcChargeParamTypePtr->EVMaximumPowerLimit);
      dcChargeParamTypePtr->EVMaximumPowerLimitFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                     /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
    }
    /* EVMaximumVoltageLimit */
    if (typeCreated == TRUE)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      boolean flag = FALSE;

      Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVMaximumVoltageLimit(&scc_PhysicalValueTmp, &flag);
      typeCreated = Scc_DIN70121_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_DIN_UNIT_SYMBOL_TYPE_V, &dcChargeParamTypePtr->EVMaximumVoltageLimit);
      /* Parameter is not optional for this message, check if it was set */
      if (flag != TRUE)
      {
        Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Din_ChargeParameterDiscoveryReqMissingEvmaximumvoltagelimit);
        typeCreated = FALSE;
      }
    }
    /* EVEnergyCapacity */
    if (typeCreated == TRUE)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      boolean flag = FALSE;

      Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVEnergyCapacity(&scc_PhysicalValueTmp, &flag);
      typeCreated = Scc_DIN70121_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_DIN_UNIT_SYMBOL_TYPE_WH, &dcChargeParamTypePtr->EVEnergyCapacity);
      dcChargeParamTypePtr->EVEnergyCapacityFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                        /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
    }
    /* EVEnergyRequest */
    if (typeCreated == TRUE)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      boolean flag = FALSE;

      Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVEnergyRequest(&scc_PhysicalValueTmp, &flag);
      typeCreated = Scc_DIN70121_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_DIN_UNIT_SYMBOL_TYPE_WH, &dcChargeParamTypePtr->EVEnergyRequest);
      dcChargeParamTypePtr->EVEnergyRequestFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                         /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
    }
    /* FullSOC */
    {
      boolean flag = FALSE;
      Scc_DIN70121_InterfaceCfg_ExiTx_Get_FullSOC(&dcChargeParamTypePtr->FullSOC, &flag);
      dcChargeParamTypePtr->FullSOCFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                                 /* PRQA S 2995, 2996, 2997, 2998 */ /* MD_Scc_VariantDependent */
    }
    /* BulkSOC */
    {
      boolean flag = FALSE;
      Scc_DIN70121_InterfaceCfg_ExiTx_Get_BulkSOC(&dcChargeParamTypePtr->BulkSOC, &flag);
      dcChargeParamTypePtr->BulkSOCFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                                 /* PRQA S 2995, 2996, 2997, 2998 */ /* MD_Scc_VariantDependent */
    }
    /* Set DC EV Charge Parameter Type for V2G message */
    *DcEvChargeParamTypePtr = dcChargeParamTypePtr;
  }


  return typeCreated;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_ExiTx_CreatePhysicalValueType
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_DIN70121_ExiTx_CreatePhysicalValueType(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) ValuePtr,
  Exi_DIN_unitSymbolType Unit,
  P2VAR(Exi_DIN_PhysicalValueType*, AUTOMATIC, SCC_VAR_NOINIT) DINPhysicalValueTypePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  CONSTP2VAR(Exi_DIN_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) physicalValueTypePtr
    = (P2VAR(Exi_DIN_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT))                                                     /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_DIN_PhysicalValueType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if physical value type element was created */
  if (physicalValueTypePtr != NULL_PTR)
  {
    /* #20 Setup physical value type */
    Scc_Conv_Scc2DIN_PhysicalValue(ValuePtr, physicalValueTypePtr);
    physicalValueTypePtr->UnitFlag = 1;
    physicalValueTypePtr->Unit = Unit;

    *DINPhysicalValueTypePtr = physicalValueTypePtr;
  }

  return physicalValueTypePtr != NULL_PTR;
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
 *  END OF FILE: Scc_DIN70121_ExiTx.c
 *********************************************************************************************************************/
