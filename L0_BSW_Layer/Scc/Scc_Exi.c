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
/*!        \file  Scc_Exi.c
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

#define SCC_EXI_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
 /* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Exi.h"
#include "Scc.h"
#include "Scc_Cfg.h"
#include "Scc_Lcfg.h"
#include "Scc_Priv.h"
#include "Scc_ExiRx_Common.h"
#include "Scc_Core_InterfaceCfg.h"
#include "Scc_TimerGeneral_TimerCfg.h"
#include "Scc_Core_Channel.h"

#if ( SCC_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */
#include "EthIf.h"
#include "Exi.h"
#include "TcpIp.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

/**********************************************************************************************************************
 *  LOCAL / GLOBAL DATA
 *********************************************************************************************************************/

/* 8bit variables */
#define SCC_START_SEC_VAR_NO_INIT_8
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 ))                                                             /* PRQA S 3332 */ /* MD_Scc_3332 */
VAR(uint8, SCC_VAR_NOINIT) Scc_Exi_SAScheduleTupleID;
#endif /* SCC_SCHEMA_ISO */

#if ( defined SCC_ENABLE_ISO15118_20_PNC_CHARGING ) && ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/* Flag to check if ExiTempBuf is currently used or not. This is used since it is possible that ScheduleExchangeRes and
 * MeteringConfirmationReq are processed at the same time and since both xmlSignature verification and generation jobs
 * use the same Scc internal buffers, it should not run into issues */
SCC_LOCAL VAR(boolean, SCC_VAR_NOINIT) Scc_ExiTempBufInUse;
#endif

#define SCC_STOP_SEC_VAR_NO_INIT_8
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* 16bit variables */
#define SCC_START_SEC_VAR_NO_INIT_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
VAR(uint16, SCC_VAR_NOINIT) Scc_Exi_TempBufPos;
#endif /* SCC_ENABLE_PNC_CHARGING */

#define SCC_STOP_SEC_VAR_NO_INIT_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* other variables */
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
VAR(XmlSecurity_SigGenWorkspaceType, SCC_VAR_NOINIT) Scc_Exi_XmlSecSigGenWs;
VAR(XmlSecurity_SigVerWorkspaceType, SCC_VAR_NOINIT) Scc_Exi_XmlSecSigVerWs;
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if (( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 ))                                                             /* PRQA S 3332 */ /* MD_Scc_3332 */
VAR(Scc_ISO_PaymentOptionType, SCC_VAR_NOINIT)   Scc_Exi_PaymentOption;
VAR(Scc_ISO_ChargingSessionType, SCC_VAR_NOINIT) Scc_Exi_ChargingSession;
#endif /* SCC_SCHEMA_ISO */

VAR(Scc_ExiTx_Xyz_PrepareMessageFctType, SCC_VAR_NOINIT) Scc_ExiTx_Xyz_PrepareMessageFctPtr;

SCC_LOCAL VAR(Scc_SendDataStateType, SCC_VAR_NOINIT)  Scc_SendDataState;

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0))
VAR(Scc_Exi_TempBufType, SCC_VAR_NOINIT)   Scc_Exi_TempBufUnion;                                                        /* PRQA S 0759, 0613 */ /* MD_MSR_Union, MD_SCC_BigStructure */
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_SCHEMA_ISO_20 */

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
 *  Scc_Exi_WriteHeader
 *********************************************************************************************************************/
/*! \brief          Write the header that is not yet sent
 *  \details        -
 *  \param[in]      PayloadType           payload type to be sent
 *  \param[in]      PBufPtr               pointer to tx data
 *  \param[in]      Exi_EncWsPtr          Pointer to the encode workspace
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(uint8, SCC_CODE) Scc_Exi_WriteHeader(uint16 PayloadType,
  P2VAR(Scc_PbufType, AUTOMATIC, SCC_APPL_DATA) PBufPtr,
  P2CONST(Exi_EncodeWorkspaceType, AUTOMATIC, SCC_APPL_DATA) Exi_EncWsPtr);

/**********************************************************************************************************************
 *  Scc_Exi_EncodeExiStream
 *********************************************************************************************************************/
/*! \brief          Encode the message into Exi
 *  \details        -
 *  \param[in]      PBufPtr               Pointer to tx data
 *  \param[in]      TxMsgWSPtr            Pointer to the Tx message workspace
 *  \return         Scc_ReturnType_OK     Exi encode was successful
 *  \return         Scc_ReturnType_NotOK  Exi encode was not successful
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_Exi_EncodeExiStream(
  P2VAR(Scc_PbufType, AUTOMATIC, SCC_APPL_DATA) PBufPtr,
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr,
  boolean        firstPart);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_Exi_Init
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */

FUNC(void, SCC_CODE) Scc_Exi_Init(void)
{
  /* ----- Implementation ----------------------------------------------- */
#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
  /* #10 reset the position of the Scc_Exi_TempBuf */
  Scc_Exi_TempBufPos = 0;
#endif /* SCC_ENABLE_PNC_CHARGING */

#if ( defined SCC_ENABLE_ISO15118_20_PNC_CHARGING ) && ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
  /* #20 Clear flag that ExiTempBuf is used */
  Scc_ExiTempBufInUse = FALSE;
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

  Scc_SendDataState = Scc_SendDataState_Done;

  return;
}


#if ( defined SCC_ENABLE_ISO15118_20_PNC_CHARGING ) && ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_Exi_IsExiTempBufInUse
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_STATIC_CODE) Scc_Exi_IsExiTempBufInUse(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return Scc_ExiTempBufInUse */
  return Scc_ExiTempBufInUse;
}

/**********************************************************************************************************************
 *  Scc_Exi_SetExiTempBufInUse
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_STATIC_CODE) Scc_Exi_SetExiTempBufInUse(boolean ExiTempBufInUse)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set ExiTempBufInUse */
  Scc_ExiTempBufInUse = ExiTempBufInUse;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_Exi_Get_SendDataState
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_SendDataStateType, SCC_CODE) Scc_Exi_Get_SendDataState(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the SendDataState */
  return Scc_SendDataState;
}

/**********************************************************************************************************************
 *  Scc_Exi_Set_SendDataState
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Exi_Set_SendDataState(Scc_SendDataStateType SendDataState)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the SendDataState */
  Scc_SendDataState = SendDataState;
}

/**********************************************************************************************************************
 *  Scc_Exi_EncodeReq
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
 */
/* PRQA S 6010,6030 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC */
FUNC(Scc_ReturnType, SCC_CODE) Scc_Exi_EncodeReq(
    P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) BufPtr,
    P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) BufLengthPtr,
    P2VAR(Scc_PbufType, AUTOMATIC, SCC_APPL_DATA) PBufPtr,
    P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  uint16         payloadType = TxMsgWSPtr->payloadType;
  uint16         lengthRemaining = *BufLengthPtr;
  uint16         lengthSent = 0;
  boolean        firstPart = FALSE;
  P2VAR(uint8, AUTOMATIC, SCC_VAR_NOINIT) currentBufPtr = BufPtr;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Check if data transmission is already done */
  if (Scc_SendDataState == Scc_SendDataState_Done)
  {
    /* Nothing to do as everything was already written */
    /* This state is called if a wrap around in the TcpIp/Tls occurred and
     * the message to transmit is excatly the size of the rest of the buffer before
     * the wrap around occurs. TcpIp then can not detect that Scc is already finished
     * and is going to call CopyTxData callback once more with the rest of the available
     * buffer. But Scc is already done at this point in time.
     * E.g.
     * Tls Buffer: +=free, -=used
     * |+++++++++++++++++++++++++++++++------------++++++++|
     *
     * Tls buffer has 42 bytes left at the end of the buffer and more data at the beginning of the buffer
     * Scc requested a size of 1440 bytes in transmit call which is bigger than the free space at the end of the buffer
     * CopyTxData is going to be called with 42 bytes
     * Scc message size is excatly 42 bytes
     * Scc sets buffer length to 42 and returns ok <--- Here Tls can not detect that Scc is already done
     * Tls then calls CopyTxData again with 1398 bytes (rest of the requested buffer)
     * Scc returns 0 as it is already done
     */
    retVal = Scc_ReturnType_OK;
    *BufLengthPtr = 0;
  }
  /* #20 Otherwise */
  else
  {
    /* #30 Check if the state is Init */
    if (Scc_SendDataState == Scc_SendDataState_Init)
    {
      TxMsgWSPtr->Exi_EncWs.InputData.RootElementId = TxMsgWSPtr->RootElementId;
      TxMsgWSPtr->Exi_EncWs.EncWs.StartWriteAtBytePos = 0;
      TxMsgWSPtr->Exi_EncWs.EncWs.CurrentStreamSegmentLen = 0;
      firstPart = TRUE;
      /* #40 Encode, Finalize and copy the message */
      if (Scc_ReturnType_OK == Scc_Exi_EncodeExiStream(PBufPtr, TxMsgWSPtr, firstPart))
      {
        /* #50 Go to state WriteV2GHeader */
        Scc_SendDataState = Scc_SendDataState_WriteV2GHeader;
        TxMsgWSPtr->Step = SCC_MSGPROC_STEP_INIT;
      }
    }

    /* #60 Check if the state is WriteV2GHeader */
    if (Scc_SendDataState == Scc_SendDataState_WriteV2GHeader)
    {
      /* #70 write V2GTP header to PBuf */
      lengthSent = Scc_Exi_WriteHeader(payloadType, PBufPtr, &TxMsgWSPtr->Exi_EncWs);
      lengthRemaining = lengthRemaining - lengthSent;
      retVal = Scc_ReturnType_OK;

      /* #80 Check if the complete header was sent */
      if ((Scc_Core_Channel_Get_TxDataSent()) == SCC_V2GTP_HDR_LEN)
      {
        /* In case this is a subsequent call then part of header was sent in earlier call.
         * Hence exactly 8 bytes cannot be sent in this call. Hence reset Exi lengths */
         /* In case this is the first call and exactly 8 bytes were available then lengthRemaining would be 0. Hence reset Exi lengths */
         /* #90 In case this is a subsequent call or if exactly 8 bytes were available then reset EXI lengths */
        if ((lengthSent != SCC_V2GTP_HDR_LEN) || (lengthRemaining == 0u))
        {
          /* #100 Reset Exi data since payload was not copied */
          TxMsgWSPtr->Exi_EncWs.EncWs.StartWriteAtBytePos = 0;
          TxMsgWSPtr->Exi_EncWs.EncWs.CurrentStreamSegmentLen = 0;
        }
        /* set the length of the tx data */
        Scc_Core_Channel_Increment_TxDataSent(TxMsgWSPtr->Exi_EncWs.EncWs.CurrentStreamSegmentLen);
        lengthRemaining = lengthRemaining - (uint16)TxMsgWSPtr->Exi_EncWs.EncWs.CurrentStreamSegmentLen;
        lengthSent = lengthSent + (uint16)TxMsgWSPtr->Exi_EncWs.EncWs.CurrentStreamSegmentLen;

        /* #110 Check if all EXI data was written */
        if (TxMsgWSPtr->Exi_EncWs.EncWs.StreamComplete == Exi_BT_True)
        {
          /* #120 Set state to done */
          Scc_SendDataState = Scc_SendDataState_Done;
        }
        /* #130 Otherwise set state to WritePayload */
        else
        {
          Scc_SendDataState = Scc_SendDataState_WritePayload;
        }
      }
    }

    /* #140 Check if the state is WritePayload and if buffer is available to be written and if this is not the first part */
    if (Scc_SendDataState == Scc_SendDataState_WritePayload)
    {
      /* #150 Check if buffer is available */
      if (lengthRemaining != 0u)
      {
        currentBufPtr = &currentBufPtr[lengthSent];

        /* Update the PBuf to point to the remaining available buffer */
        PBufPtr->payload = currentBufPtr;
        PBufPtr->len = lengthRemaining;
        PBufPtr->totLen = lengthRemaining;

        /* #160 Encode rest of the EXI stream */
        retVal = Scc_Exi_EncodeExiStream(PBufPtr, TxMsgWSPtr, FALSE);
        /* #170 set the length of the tx data */
        Scc_Core_Channel_Increment_TxDataSent(TxMsgWSPtr->Exi_EncWs.EncWs.CurrentStreamSegmentLen);
        lengthSent = (uint16)TxMsgWSPtr->Exi_EncWs.EncWs.CurrentStreamSegmentLen + lengthSent;
      }
    }

    /* #180 copy the streaming status from the EXI workspace */
    if (TxMsgWSPtr->Exi_EncWs.EncWs.StreamComplete == Exi_BT_True)
    {
      Scc_TxStreamingActive = FALSE;
      Scc_SendDataState = Scc_SendDataState_Done;
    }
    else
    {
      Scc_TxStreamingActive = TRUE;
    }

    /* #190 Check if encoding was successful */
    if (retVal == Scc_ReturnType_OK)
    {
      *BufLengthPtr = lengthSent;
      /* payload changed in Scc_SendDataState_WritePayload. Hence update here */
      PBufPtr->payload = BufPtr;
      PBufPtr->totLen = *BufLengthPtr;
      PBufPtr->len = *BufLengthPtr;

      /* #200 Provide sent data to application */
      {
        /* create and set the tx buffer pointer */
        Scc_TxRxBufferPointerType V2GRequest;
        V2GRequest.PbufPtr = PBufPtr;
        V2GRequest.FirstPart = firstPart;
        V2GRequest.StreamComplete = SCC_EXIBOOLEAN_TO_BOOLEAN(TxMsgWSPtr->Exi_EncWs.EncWs.StreamComplete);
        /* provide the buffer to the application */
        Scc_Core_InterfaceCfg_Set_V2GRequest(&V2GRequest);
      }
    }
  }
  return retVal;
}


/**********************************************************************************************************************
 *  Scc_Exi_InitDecodingWorkspace
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, SCC_CODE) Scc_Exi_InitDecodingWorkspace(P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                    Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());

  /* ----- Implementation ----------------------------------------------- */
  /* #10 initialize the decoding workspace */
  if ( (Std_ReturnType)E_OK != Exi_InitDecodeWorkspace(&RxMsgWSPtr->Exi_DecWs,
    (P2VAR(IpBase_PbufType, AUTOMATIC, SCC_APPL_DATA))&Scc_ExiStreamRxPBuf[0], (P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA))& buffPoolWsPtr->MsgPtr[0],
    buffPoolWsPtr->MsgPtrSize, SCC_V2GTP_HDR_LEN) )
  {
    /* report the error to the application */
    Scc_ReportError(Scc_StackError_Exi, SccDetailedError_Common_ExiInitDecodingWsExiInitFailed);
  }
  else
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_Exi_WriteHeader
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */ /* PRQA S 3673 2 */ /* MD_Scc_QAC_Mistaken */
SCC_LOCAL FUNC(uint8, SCC_CODE) Scc_Exi_WriteHeader(uint16 PayloadType,
    P2VAR(Scc_PbufType, AUTOMATIC, SCC_APPL_DATA) PBufPtr,
    P2CONST(Exi_EncodeWorkspaceType, AUTOMATIC, SCC_APPL_DATA) Exi_EncWsPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8       Buf[SCC_V2GTP_HDR_LEN];
  uint32      txDataSentEarlier;
  uint32      txDataSentNow;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 set the V2GTP header (8 byte) with version info (2 byte), payload type (2 byte) and payload length (2 byte). */

  /* set the version info (2 byte) */
  Buf[Scc_V2GTPOffsets_Version]         = (uint8)SCC_V2G_PROT_VER;
  Buf[Scc_V2GTPOffsets_InverseVersion]  = (uint8)((~SCC_V2G_PROT_VER) & 0xFFu);
  /* set the payload type (2 byte) */
  Buf[Scc_V2GTPOffsets_PayloadType]     = (uint8)(( PayloadType & 0xFF00u ) >> 8u );
  Buf[Scc_V2GTPOffsets_PayloadType+1u]   = (uint8) ( PayloadType & 0x00FFu );
  /* set the payload length (4 byte) */
  Buf[Scc_V2GTPOffsets_PayloadLength]   =
    (uint8)(( Exi_EncWsPtr->EncWs.TotalStreamLength & 0xFF000000u ) >> 24u );
  Buf[Scc_V2GTPOffsets_PayloadLength+1u] =
    (uint8)(( Exi_EncWsPtr->EncWs.TotalStreamLength & 0x00FF0000u ) >> 16u );
  Buf[Scc_V2GTPOffsets_PayloadLength+2u] =
    (uint8)(( Exi_EncWsPtr->EncWs.TotalStreamLength & 0x0000FF00u ) >> 8u );
  Buf[Scc_V2GTPOffsets_PayloadLength+3u] =
    (uint8) ( Exi_EncWsPtr->EncWs.TotalStreamLength & 0x000000FFu );

  txDataSentEarlier = Scc_Core_Channel_Get_TxDataSent();
  /* #20 copy the V2GTP header to the PBuf */
  if (txDataSentEarlier < SCC_V2GTP_HDR_LEN )
  {
    if ( (Std_ReturnType)E_OK != IpBase_CopyString2PbufAt(( P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) )&Buf[txDataSentEarlier],/* PRQA S 0310,3305 */ /* MD_Scc_0310_0314_0316_3305 */
      (uint16)( SCC_V2GTP_HDR_LEN - txDataSentEarlier),
      ( P2VAR(IpBase_PbufType, AUTOMATIC, SCC_APPL_DATA) )PBufPtr, 0) )
    {
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      ( void )Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_EXI_WRITE_HEADER, SCC_DET_IP_BASE);
#endif /* SCC_DEV_ERROR_REPORT */
    }
  }
  else
  {
#if(SCC_DEV_ERROR_REPORT == STD_ON)
    ( void )Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_EXI_WRITE_HEADER, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
  }

  /* #30 Calculate length sent in this cycle */
  txDataSentNow = SCC_V2GTP_HDR_LEN - txDataSentEarlier;
  /* #40 Check and limit the length sent based on PBuf legth */
  if (PBufPtr->totLen < txDataSentNow)
  {
    txDataSentNow = PBufPtr->totLen;
  }

  Scc_Core_Channel_Increment_TxDataSent(txDataSentNow);

  return (uint8) txDataSentNow;
}

/**********************************************************************************************************************
 *  Scc_Exi_EncodeExiStream
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_Exi_EncodeExiStream(
    P2VAR(Scc_PbufType, AUTOMATIC, SCC_APPL_DATA) PBufPtr,
    P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr,
    boolean        firstPart)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  uint16 OutBufOfs;
  Exi_ReturnType  exiRetVal;
  P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                    Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if this is the first part */
  if (firstPart == TRUE)
  {
    /* #20 Check if the buffer is big enough to store the (first part of the) EXI stream. */
    if (PBufPtr->totLen > SCC_V2GTP_HDR_LEN)
    {
      /* #30 Start writing the EXI stream after V2GTP header */
      OutBufOfs = SCC_V2GTP_HDR_LEN;
    }
    /* #40 Otherwise set buffer offset to buffer length - 1 */
    else
    {
      /* EXI stream cannot be encoded, initialize the EXI workspace to only calculate the stream length to put it into the V2GTP header */
      /* Buffer is not big enough to trigger an Exi write. The written Exi data will be overwritten by V2G header later on */
      /* Exi init required at least 8 bytes of header buffer and 1 byte of Exi buffer. */
      /* Underflow condition evaluated in Scc_Cbk_CopyTxData already. */
      OutBufOfs = (uint16)(PBufPtr->totLen - 1u);
    }
  }
  /* #50 Otherwise set buffer offset to 0 */
  else
  {
    /* Set OutBufOfs to 0 since Exi encode is always done from offset 0 in case of subsequent message encoding. */
    OutBufOfs = 0;
  }

  /* #60 initialize the exi encode workspace */
  if ((Std_ReturnType)E_OK != Exi_InitEncodeWorkspace(&TxMsgWSPtr->Exi_EncWs,                                           /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
    (P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA))& buffPoolWsPtr->MsgPtr[0],
    (P2VAR(IpBase_PbufType, AUTOMATIC, SCC_APPL_DATA))PBufPtr, OutBufOfs,
    TxMsgWSPtr->Exi_EncWs.EncWs.StartWriteAtBytePos + TxMsgWSPtr->Exi_EncWs.EncWs.CurrentStreamSegmentLen, firstPart))
  {
    /* report the error to the application */
    Scc_ReportError(Scc_StackError_Exi, SccDetailedError_Common_ExiInitEncodingWsExiInitFailed);
  }
  else
  {
    /* #70 encode the message and check if the encoding failed */
    exiRetVal = Exi_Encode(&TxMsgWSPtr->Exi_EncWs);
    if ((EXI_E_OK != exiRetVal) && (EXI_E_EOS != exiRetVal))
    {
      /* report the error */
      Scc_ReportError(Scc_StackError_Exi, SccDetailedError_Common_ExiEncodeStreamExiEncodeFailed);
    }
    /* #80 finalize the exi stream */
    else if (EXI_E_OK != Exi_FinalizeExiStream(&TxMsgWSPtr->Exi_EncWs))
    {
      /* report the error to the application */
      Scc_ReportError(Scc_StackError_Exi, SccDetailedError_Common_ExiEncodeStreamExiFinalizedFailed);
    }
    else
    {
      retVal = Scc_ReturnType_OK;
    }
  }

  return retVal;
}


#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/
/* PRQA L:NEST_STRUCTS */
/* PRQA L:RETURN_PATHS */

/**********************************************************************************************************************
 *  END OF FILE: Scc_Exi.c
 *********************************************************************************************************************/
