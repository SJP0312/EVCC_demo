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
/*!        \file  Scc_Core_Channel.c
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
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/
#define SCC_CORE_CHANNEL_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
/*lint -e546 */ /* Suppress the 'Suspicious use of &' warning because the '&' is required by MISRA per Id 1502. */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Core_Channel.h"
#include "Scc_Priv.h"
#include "Scc_Core_InterfaceCfg.h"
#if ( SCC_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL_INLINE)
# define SCC_LOCAL_INLINE LOCAL_INLINE
#endif

#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL / GLOBAL DATA
 *********************************************************************************************************************/

 /* 8bit variables - no init */
#define SCC_START_SEC_VAR_NO_INIT_8
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

SCC_LOCAL VAR(uint8, SCC_VAR_NOINIT)  Scc_CurrentChannel;
SCC_LOCAL VAR(uint8, SCC_VAR_NOINIT)  Scc_CurrentReceptionChannel;

#define SCC_STOP_SEC_VAR_NO_INIT_8
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* other variables */
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

SCC_LOCAL VAR(Scc_CoreChannelStructType, SCC_VAR_NOINIT)  Scc_CoreChannels[SCC_CHANNEL_MAX];

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_Core_Channel_IsChannelEnabled
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_Core_Channel_IsChannelEnabled(Scc_CoreChannelType ChannelType)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isChannelEnabled = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if it is deafult channel */
  if (ChannelType == SCC_CHANNEL_DEFAULT)
  {
    /* #20 Return true since default channel is always enabled */
    isChannelEnabled = TRUE;
  }
  /* #30 Otherwise return if the channel is enabled or not */
  else
  {
    if (ChannelType < SCC_CHANNEL_MAX)
    {
      isChannelEnabled = Scc_CoreChannels[ChannelType].IsChannelEnabled;                                                /* PRQA S 2841 */ /* MD_SCC_CORE_CHANNEL_MAX */ /*lint !e676 */
    }
    else
    {
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_CHANNEL_ENABLED, SCC_DET_INV_PARAM);
#endif
    }
  }

  return isChannelEnabled;
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_IsMessageTrigValid
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
FUNC(boolean, SCC_CODE) Scc_Core_Channel_IsMessageTrigValid(Scc_CoreChannelType ChannelType, Scc_MsgTrigType MsgTrigger)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean IsMessageTrigValid = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if it is deafult channel */
  if (ChannelType == SCC_CHANNEL_DEFAULT)
  {
    /* #20 Return true since all messages are valid for default channel */
    /* All messages are valid for default channel */
    IsMessageTrigValid = TRUE;
  }
  else
  {
#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
    /* #30 Otherwise check if channel is renegotiation */
    if (ChannelType == SCC_CHANNEL_RENEGOTIATION)
    {
      /* #40 Check if message trigger is valid for this channel */
      if ( (MsgTrigger == Scc_MsgTrig_None)
        || (MsgTrigger == Scc_MsgTrig_ChargeParameterDiscovery)
        || (MsgTrigger == Scc_MsgTrig_ScheduleExchange)
        || (MsgTrigger == Scc_MsgTrig_PowerDelivery) )
      {
        IsMessageTrigValid = TRUE;
      }
    }
#endif /* SCC_ENABLE_RENEGOTIATION_CHANNEL */
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
    /* #50 Otherwise check if channel is metering */
    if (ChannelType == SCC_CHANNEL_METERING)
    {
      /* #60 Check if message trigger is valid for this channel */
      if ( (MsgTrigger == Scc_MsgTrig_None)
        || (MsgTrigger == Scc_MsgTrig_MeteringReceipt) )
      {
        IsMessageTrigValid = TRUE;
      }
    }
#endif /* SCC_ENABLE_METERING_RECEIPT */
#if ( defined SCC_ENABLE_ACDP_SYSTEM_STATUS ) && ( SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON )
    /* #70 Otherwise check if channel is SystemStatus */
    if (ChannelType == SCC_CHANNEL_SYSTEM_STATUS)
    {
      /* #80 Check if message trigger is valid for this channel */
      if ( (MsgTrigger == Scc_MsgTrig_None)
        || (MsgTrigger == Scc_MsgTrig_ACDP_SystemStatus))
      {
        IsMessageTrigValid = TRUE;
      }
    }
#endif /* SCC_ENABLE_ACDP_SYSTEM_STATUS */

#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_OFF ) \
   && ( defined SCC_ENABLE_METERING_RECEIPT) && (SCC_ENABLE_METERING_RECEIPT == STD_OFF ) \
   && ( defined SCC_ENABLE_ACDP_SYSTEM_STATUS) && (SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_OFF )
    SCC_DUMMY_STATEMENT_CONST(MsgTrigger);                                                                              /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif
  }

  return IsMessageTrigValid;
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_EnableChannel
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Core_Channel_EnableChannel(Scc_CoreChannelType ChannelType)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Enable the channel */
  Scc_CoreChannels[ChannelType].IsChannelEnabled = TRUE;
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_DisableAllChannels
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Core_Channel_DisableAllChannels(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least index;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate for number of channels */
  for (index = 0; index < (uint8_least)SCC_CHANNEL_MAX; index++)                                                        /* PRQA S 1880 */ /* MD_SCC_CORE_CHANNEL_ENUM */
  {
    /* #20 Disable the channel */
    Scc_CoreChannels[index].IsChannelEnabled = FALSE;
  }
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_Init
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Core_Channel_Init(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least index;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate for number of channels */
  for (index = 0; index < (uint8_least)SCC_CHANNEL_MAX; index++)                                                        /* PRQA S 1880 */ /* MD_SCC_CORE_CHANNEL_ENUM */
  {
    /* #20 Initialize data for each channel */
    Scc_CoreChannels[index].IsChannelEnabled = FALSE;
    Scc_CoreChannels[index].MsgTrig          = Scc_MsgTrig_None;
    Scc_CoreChannels[index].CyclicMsgTrig    = FALSE;
    Scc_CoreChannels[index].MsgState         = Scc_MsgState_WaitForNextRequest;
    Scc_CoreChannels[index].TxDataSent       = 0;
    Scc_CoreChannels[index].TimeoutRetval    = E_OK;
    Scc_CoreChannels[index].BufferPoolWS.BufferPoolId = SCC_INVALID_BUFFER_POOL_ID;
    Scc_CoreChannels[index].BufferPoolWS.MsgPtr = NULL_PTR;
    Scc_CoreChannels[index].BufferPoolWS.MsgPtrSize = 0;

#if ( ((defined SCC_SCHEMA_ISO) && (SCC_SCHEMA_ISO != 0)) \
   || ((defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0)) )
    Scc_CoreChannels[index].TxMsgWS.Step = SCC_MSGPROC_STEP_INIT;
#endif /* SCC_SCHEMA_ISO || SCC_SCHEMA_ISO_20 */
  }

  /* #30 Set TimeoutHandlingFct for different channels */
  Scc_CoreChannels[(uint8)SCC_CHANNEL_DEFAULT].TimeoutHandlingFct       = &Scc_TimeoutHandling;
#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
  Scc_CoreChannels[(uint8)SCC_CHANNEL_RENEGOTIATION].TimeoutHandlingFct = &Scc_TimeoutHandlingReneg;
#endif
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
  Scc_CoreChannels[(uint8)SCC_CHANNEL_METERING].TimeoutHandlingFct = &Scc_TimeoutHandlingMetering;
#endif
#if ( defined SCC_ENABLE_ACDP_SYSTEM_STATUS ) && ( SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON )
  Scc_CoreChannels[(uint8)SCC_CHANNEL_SYSTEM_STATUS].TimeoutHandlingFct = &Scc_TimeoutHandlingSystemStatus;
#endif
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_Get_CyclicMsgTrig
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_Core_Channel_Get_CyclicMsgTrig(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the CyclicMsgTrig for the current channel */
  return Scc_CoreChannels[Scc_CurrentChannel].CyclicMsgTrig;
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_Set_CyclicMsgTrig
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Core_Channel_Set_CyclicMsgTrig(boolean CyclicMsgTrig)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the CyclicMsgTrig for the current channel */
  Scc_CoreChannels[Scc_CurrentChannel].CyclicMsgTrig = CyclicMsgTrig;
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_Get_TxDataSent
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(uint32, SCC_CODE) Scc_Core_Channel_Get_TxDataSent(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the CyclicMsgTrig for the current channel */
  return Scc_CoreChannels[Scc_CurrentChannel].TxDataSent;
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_Set_TxDataSent
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Core_Channel_Set_TxDataSent(uint32 TxDataSent)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the TxDataSent for the current channel */
  Scc_CoreChannels[Scc_CurrentChannel].TxDataSent = TxDataSent;
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_Increment_TxDataSent
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Core_Channel_Increment_TxDataSent(uint32 TxDataSent)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the TxDataSent for the current channel */
  Scc_CoreChannels[Scc_CurrentChannel].TxDataSent += TxDataSent;
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_Get_MsgState
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_MsgStateType, SCC_CODE) Scc_Core_Channel_Get_MsgState(Scc_CoreChannelType ChannelType)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the MsgState for the current channel */
  return Scc_CoreChannels[ChannelType].MsgState;
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_Set_MsgState
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Core_Channel_Set_MsgState(Scc_MsgStateType MsgState)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the MsgState for the current channel */
  Scc_CoreChannels[Scc_CurrentChannel].MsgState = MsgState;
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_Get_TimeoutRetval
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, SCC_CODE) Scc_Core_Channel_Get_TimeoutRetval(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the TimeoutRetval for the current channel */
  return Scc_CoreChannels[Scc_CurrentChannel].TimeoutRetval;
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_Get_MsgTrig
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_MsgTrigType, SCC_CODE) Scc_Core_Channel_Get_MsgTrig(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the MsgTrig for the current channel */
  return Scc_CoreChannels[Scc_CurrentChannel].MsgTrig;
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_Set_MsgTrig
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Core_Channel_Set_MsgTrig(Scc_MsgTrigType MsgTrig)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the MsgTrig for the current channel */
  Scc_CoreChannels[Scc_CurrentChannel].MsgTrig = MsgTrig;
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_Get_CurrentChannel
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Scc_CoreChannelType, SCC_CODE) Scc_Core_Channel_Get_CurrentChannel(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_CoreChannelType currentChannel = SCC_CHANNEL_DEFAULT;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the current channel is valid */
  if (Scc_CurrentChannel < (uint8)SCC_CHANNEL_MAX)
  {
    /* #20 Copy the current channel */
    currentChannel = (Scc_CoreChannelType)Scc_CurrentChannel;                                                           /* PRQA S 4342 */ /* MD_SCC_CORE_CHANNEL_ENUM */
  }

  /* #30 Return the current channel */
  return currentChannel;
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_Get_RxMsgWSPtr
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA), SCC_CODE) Scc_Core_Channel_Get_RxMsgWSPtr(Scc_CoreChannelType ChannelType)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the received message workspace for the current channel */
  return &Scc_CoreChannels[ChannelType].RxMsgWS;
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_Get_TxMsgWSPtr
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA), SCC_CODE) Scc_Core_Channel_Get_TxMsgWSPtr(Scc_CoreChannelType ChannelType)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the transmit message workspace for the current channel */
  return &Scc_CoreChannels[ChannelType].TxMsgWS;
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_Set_CurrentChannel
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Core_Channel_Set_CurrentChannel(uint8 CurrentChannel)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the current channel */
  Scc_CurrentChannel = CurrentChannel;
  Scc_Core_InterfaceCfg_Set_CurrentChannel((Scc_CoreChannelType)Scc_CurrentChannel);                                    /* PRQA S 4342 */ /* MD_SCC_CORE_CHANNEL_ENUM */
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_Get_BufferPoolId
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(uint8, SCC_CODE) Scc_Core_Channel_Get_BufferPoolId(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the BufferPoolId for the current channel */
  return Scc_CoreChannels[Scc_CurrentChannel].BufferPoolWS.BufferPoolId;
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_Set_BufferPoolId
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Core_Channel_Set_BufferPoolId(uint8 BufferPoolId)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the BufferPoolId for the current channel */
  Scc_CoreChannels[Scc_CurrentChannel].BufferPoolWS.BufferPoolId = BufferPoolId;
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_Get_BufferPoolWSPtr
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(P2VAR(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA), SCC_CODE) Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_CoreChannelType ChannelType)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the buffer pool workspace for the current channel */
  return &Scc_CoreChannels[ChannelType].BufferPoolWS;
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_ActualizeReceptionChannel
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Core_Channel_ActualizeReceptionChannel(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the current channel */
  Scc_CurrentChannel = Scc_CurrentReceptionChannel;
  Scc_Core_InterfaceCfg_Set_CurrentChannel((Scc_CoreChannelType)Scc_CurrentChannel);                                    /* PRQA S 4342 */ /* MD_SCC_CORE_CHANNEL_ENUM */
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_TimeoutHandling
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Core_Channel_TimeoutHandling(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if TimeoutHandlingFct is valid */
  if (Scc_CoreChannels[Scc_CurrentChannel].TimeoutHandlingFct != NULL_PTR)
  {
    /* #20 Call TimeoutHandlingFct for the current channel */
    Scc_CoreChannels[Scc_CurrentChannel].TimeoutRetval = Scc_CoreChannels[Scc_CurrentChannel].TimeoutHandlingFct();
  }
  else
  {
    Scc_CoreChannels[Scc_CurrentChannel].TimeoutRetval = E_NOT_OK;
  }
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_IsReceivedMessageExpected
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_Core_Channel_IsReceivedMessageExpected(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean expectedMessage = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the current channel was awaiting a response */
  if (Scc_CurrentChannel < (uint8)SCC_CHANNEL_MAX)
  {
    if (   (Scc_CoreChannels[Scc_CurrentChannel].MsgState == Scc_MsgState_WaitingForV2GTpHeader)
        && (Scc_CoreChannels[Scc_CurrentChannel].TimeoutRetval == E_OK))
    {
      /* #20 Inform the application the channel number */
      Scc_Core_InterfaceCfg_Set_CurrentChannel((Scc_CoreChannelType)Scc_CurrentChannel);                                /* PRQA S 4342 */ /* MD_SCC_CORE_CHANNEL_ENUM */
      expectedMessage = TRUE;
    }
  }

  return expectedMessage;
}

/**********************************************************************************************************************
 *  Scc_Core_Channel_SetRxChannelByPayloadType
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
FUNC(void, SCC_CODE) Scc_Core_Channel_SetRxChannelByPayloadType(uint16 PayloadType)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_CoreChannelType currentChannel = SCC_CHANNEL_DEFAULT;

  /* ----- Implementation ----------------------------------------------- */
  switch (PayloadType)
  {
    /* #10 Check if payload type is SDP or EXI */
    case SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_PLC_RES:
#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
    case SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_WIRELESS_RES:
#endif /* SCC_WIRELESS_SDP */
    case SCC_V2GTP_HDR_PAYLOAD_TYPE_EXI:
#if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )
    case SCC_V2GTP_HDR_PAYLOAD_TYPE_CM:
#endif
#if ( defined SCC_SCHEMA_ISO_20AC ) && ( SCC_SCHEMA_ISO_20AC != 0 )
    case SCC_V2GTP_HDR_PAYLOAD_TYPE_AC:
#endif
#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
    case SCC_V2GTP_HDR_PAYLOAD_TYPE_DC:
#endif
      currentChannel = SCC_CHANNEL_DEFAULT;
      break;

#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
    /* #20 Check if payload type is renegotiation */
    case SCC_V2GTP_HDR_PAYLOAD_TYPE_RENEGOTIATION:
      currentChannel = SCC_CHANNEL_RENEGOTIATION;
      break;
#endif

#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
      /* #30 Check if payload type is metering */
    case SCC_V2GTP_HDR_PAYLOAD_TYPE_METERING_RECEIPT:
      currentChannel = SCC_CHANNEL_METERING;
      break;
#endif /* SCC_ENABLE_METERING_RECEIPT */

#if ( defined SCC_ENABLE_ACDP_SYSTEM_STATUS ) && ( SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON )
      /* #40 Check if payload type is SystemStatus */
    case SCC_V2GTP_HDR_PAYLOAD_TYPE_ACDP_SYSTEM_STATUS:
      currentChannel = SCC_CHANNEL_SYSTEM_STATUS;
      break;
#endif /* SCC_ENABLE_ACDP_SYSTEM_STATUS */

    /* #50 Otherwise: Unknown payload type is always considered as default channel */
    default:
      currentChannel = SCC_CHANNEL_DEFAULT;
      break;
  }

  /* #60 Setup current channel */
  Scc_CurrentChannel = (uint8)currentChannel;
  Scc_CurrentReceptionChannel = (uint8)currentChannel;
  /* #70 Propagate current channel to application */
  Scc_Core_InterfaceCfg_Set_CurrentChannel((Scc_CoreChannelType)currentChannel);
}

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*lint +e546 */ /* Enable the 'Suspicious use of &' reporting again. */

/**********************************************************************************************************************
 *  END OF FILE: Scc_Core_Channel.c
 *********************************************************************************************************************/
