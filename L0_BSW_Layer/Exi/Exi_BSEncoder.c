/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Exi_BSEncoder.c
 *        \brief  Efficient XML Interchange basic encoder source file
 *
 *      \details  Vector static code implementation for the Efficient XML Interchange sub-component basic encoder.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file Exi.h.
 *********************************************************************************************************************/

/* PRQA S 0857 EOF */ /* MD_Exi_1.1_0857 */ /* [L] Number of macro definitions exceeds 1024 - program is non-conforming. */

#define EXI_BS_ENCODER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Exi.h"
#include "Exi_BSEncoder.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_VBSEncodeInitWorkspace()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6060 1 */ /* MD_MSR_STPTH, MD_MSR_STPAR */
FUNC(Std_ReturnType, EXI_CODE) Exi_VBSEncodeInitWorkspace(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
  P2VAR(IpBase_PbufType, AUTOMATIC, EXI_APPL_VAR) PBufPtr,
#else
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR) BufPtr,
  uint32 BufLen,
#endif
  uint32 ByteOffset
#if (EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON)
 ,uint32 StartWriteAtStreamPos
 ,Exi_BooleanType CalculateStreamLength
#endif
  )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Std_ReturnType retVal;

  /* #10 Check plausibility of input parameters */
#if ( EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON )
  retVal = E_NOT_OK;
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
#endif /* (EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize the workspace */
    EncWsPtr->StartOffset = ByteOffset;
    EncWsPtr->TotalStreamLength = 0;
#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
    EncWsPtr->PBufIdx = 0;
    EncWsPtr->PBufPtr = PBufPtr;
    EncWsPtr->PBufProcessedElementBytes = 0;
    /* Check if offset position is in current PBuf segment */
    if (ByteOffset >= (uint32)PBufPtr->len)
    {
      /* Get the PBuf segment where the offset is inside */
      while (ByteOffset >= (uint32)PBufPtr[EncWsPtr->PBufIdx].len)
      {
        EncWsPtr->PBufProcessedElementBytes += PBufPtr[EncWsPtr->PBufIdx].len;
        ByteOffset -= PBufPtr[EncWsPtr->PBufIdx].len;                                                                   /* PRQA S 1338 */ /* MD_Exi_FunctionParameter */
        EncWsPtr->PBufIdx++;
      }
    }
#else
    EncWsPtr->BufPtr = BufPtr;
    EncWsPtr->BufLen = BufLen;
#endif

    EncWsPtr->BytePos = ByteOffset;
    EncWsPtr->BitPos = 0;

    EncWsPtr->EERequired = Exi_BT_True;
    EncWsPtr->StatusCode = EXI_E_OK;

#if (EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON)
    if (StartWriteAtStreamPos == 0u)
    {
      EncWsPtr->WritingToBufferIsActive = Exi_BT_True;
      EncWsPtr->StartWriteAtBytePos = 0;
    }
    else
    {
      EncWsPtr->WritingToBufferIsActive = Exi_BT_False;
      EncWsPtr->StartWriteAtBytePos = StartWriteAtStreamPos;
    }
    EncWsPtr->OverallStreamBytePos = 0;
    EncWsPtr->CurrentStreamSegmentLen = 0;
    EncWsPtr->StreamComplete = Exi_BT_False;
    EncWsPtr->CalculateStreamLength = CalculateStreamLength;
#endif
    retVal = E_OK;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_ENCODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
}


/**********************************************************************************************************************
 *  Exi_VBSWriteHeader()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EXI_CODE) Exi_VBSWriteHeader(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr)
{
  /* #10 Write EXI header (8 bits) */
  (void)Exi_VBSWriteBits(EncWsPtr, (Exi_BitBufType)EXI_HEADER_BYTE, EXI_BITS_IN_BYTE);
}


/**********************************************************************************************************************
 *  Exi_VBSWriteBits()
 **********************************************************************************************************************/
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
/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(uint8, EXI_CODE) Exi_VBSWriteBits(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  Exi_BitBufType BitBuf,
  uint8 BitCount)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  uint8 bitsAvail;
  uint8 bitsRemain;
  uint8 mask;
  P2VAR(uint8, AUTOMATIC, EXI_APPL_DATA) bufPtr;

#if ((EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON) || (EXI_ENABLE_PBUF_SUPPORT == STD_OFF))
  uint32 buffTotalLen;
#endif

  /* #10 Check plausibility of input parameters */
#if ( EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (BitCount > (sizeof(Exi_BitBufType) * 8u))
  {
    errorId = EXI_E_INV_PARAM;
    bitsRemain = BitCount;
  }
  else
#endif /* (EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    bitsRemain = BitCount;

#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
    bufPtr = EncWsPtr->PBufPtr[EncWsPtr->PBufIdx].payload;
#if ((EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON) || (EXI_ENABLE_PBUF_SUPPORT == STD_OFF))
    buffTotalLen = EncWsPtr->PBufPtr[EncWsPtr->PBufIdx].totLen;
#endif
#else
    bufPtr = EncWsPtr->BufPtr;
#if ((EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON) || (EXI_ENABLE_PBUF_SUPPORT == STD_OFF))
    buffTotalLen = EncWsPtr->BufLen;
#endif
#endif

    /* #20 Loop until all bits are read or an error is detected */
    while ( (bitsRemain > 0u) && (EncWsPtr->StatusCode == EXI_E_OK) )
    {
#if (EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON)
      /* #30 TX streaming is used: If the current byte shall be written */
      /* Note: OverallStreamBytePos is only incremented in case bytes are not written */
      if (   (EncWsPtr->StartWriteAtBytePos == EncWsPtr->OverallStreamBytePos)
#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
          && ( (EncWsPtr->PBufProcessedElementBytes + EncWsPtr->BytePos) < buffTotalLen)
#else
          && ( EncWsPtr->BytePos < buffTotalLen)
#endif
         )
      {
        /* Byte is in writable range */
        /* #40 If writing to out buffer is diabled, writing to the buffer has just been started */
        if (EncWsPtr->WritingToBufferIsActive == Exi_BT_False)
        {
          /* #50 Enable writing */
          EncWsPtr->WritingToBufferIsActive = Exi_BT_True;
        }
#endif
#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
        /* #60 PUBF is used: If end of buffer segment has been reached */
        if (EncWsPtr->BytePos >= EncWsPtr->PBufPtr[EncWsPtr->PBufIdx].len)
        {
          /* end of current PBuf segment reached */
#if (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON)
          /* Check if data outside the current segment was read */
          if (EncWsPtr->BytePos != EncWsPtr->PBufPtr[EncWsPtr->PBufIdx].len)
          {
            (void)Det_ReportError(EXI_MODULE_ID, EXI_ENCODER_INSTANCE_ID, (uint8)EXI_API_ID_V_INTERNAL_FUNCTION, EXI_E_INVALID_PBBUF_POS);
          }
          else if (EncWsPtr->BitPos != 0u)
          {
            (void)Det_ReportError(EXI_MODULE_ID, EXI_ENCODER_INSTANCE_ID, (uint8)EXI_API_ID_V_INTERNAL_FUNCTION, EXI_E_INVALID_PBBUF_POS);
          }
          else
          {
            /* No det error, nothing to do */
          }
#endif

          /* #70 Mark current segment as processed */
          EncWsPtr->PBufProcessedElementBytes += EncWsPtr->PBufPtr[EncWsPtr->PBufIdx].len;
          /* #80 If more PBuf segments are available */
          if (EncWsPtr->PBufProcessedElementBytes < EncWsPtr->PBufPtr[EncWsPtr->PBufIdx].totLen)
          {
            /* #90 Switch from current PBuf segment to next segement */
            EncWsPtr->PBufIdx++;
            bufPtr = EncWsPtr->PBufPtr[EncWsPtr->PBufIdx].payload;
            /* #100 Set the byte pos to the beginning of the new PBuf segment */
            EncWsPtr->BytePos = 0u;
          }
          /* #110 End of PBuf segments reached */
          else
          {
            /* #120 End writing, there are still remaining bits */
            break;
          }
        }
#else
#if (EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_OFF)
        /* #130 Linear buffer is used: If end of buffer has been reached */
        if (EncWsPtr->BytePos >= buffTotalLen)
        {
          /* #140 End writing, there are still remaining bits */
          break;
        }
#endif
#endif
        /* #150 If write start position is at the beginning of current byte */
        if (EncWsPtr->BitPos == 0u)
        {
          /* #160 If more than 8 bits shall be written */
          if (bitsRemain > EXI_BITS_IN_BYTE)
          {
            /* #170 Write complete byte */
            bitsRemain -= EXI_BITS_IN_BYTE;
            bufPtr[EncWsPtr->BytePos] = (uint8)(BitBuf >> bitsRemain);

            /* #180 Continue with next byte */
            EncWsPtr->BytePos++;
          }
          /* #190 8 bits or less have to be read, all bits to write are in current byte */
          else
          {
            /* #200 Write remaining bits only */

            /* #210 If 8 bits shall be written */
            if (bitsRemain == EXI_BITS_IN_BYTE)
            {
              /* #220 Write 8 bits to the buffer */
              bufPtr[EncWsPtr->BytePos] = (uint8)(BitBuf);
              /* #230 Complete byte read, increment byte position */
              EncWsPtr->BytePos++;
            }
            /* #240 Less than 8 bits shall be written */
            else
            {
              /* #250 Read remaining bits from buffer */
              bufPtr[EncWsPtr->BytePos] = (uint8)(BitBuf << (EXI_BITS_IN_BYTE - bitsRemain));
              /* #260 There are free bits in current stream byte left, only advance BitPos */
              EncWsPtr->BitPos = bitsRemain;
            }

            /* #270 Finished, there are no remaining bits left */
            bitsRemain = 0;
          }
        }
        /* #280 Write start position is somewhere in the current byte */
        else
        {
          /* #290 Get avilable bits in current byte and create mask */
          bitsAvail = (uint8)(EXI_BITS_IN_BYTE - EncWsPtr->BitPos);
          mask = (uint8)(0xFFu >> EncWsPtr->BitPos);

          /* #300 If more bits are remaining than available in current byte */
          if (bitsRemain > bitsAvail)
          {
            /* #310 Write all available bits of current byte to the stream */
            bitsRemain -= bitsAvail;
            bufPtr[EncWsPtr->BytePos] = (uint8)((bufPtr[EncWsPtr->BytePos] & (uint8)(~mask)) | (uint8)((BitBuf >> bitsRemain) & mask));

            /* #320 All bits in current byte have been written, continue reading at beginning of next byte */
            EncWsPtr->BitPos = 0;
            EncWsPtr->BytePos++;
          }
          /* #330 Remaining bits count is less or equal to available bits count */
          else
          {
            /* #340 If remaining bits count is equal to available bits */
            if (bitsRemain == bitsAvail)
            {
              /* #350 Write all available bits of current byte to the stream */
              bufPtr[EncWsPtr->BytePos] = (uint8)((bufPtr[EncWsPtr->BytePos] & (uint8)(~mask)) | (uint8)((BitBuf) & mask));

              /* #360 All bits in current byte have been written, continue reading at beginning of next byte */
              EncWsPtr->BytePos++;
              EncWsPtr->BitPos = 0;
            }
            /* #370 Remaining bits count is less that avialalble bits count */
            else
            {
              /* #380 Wirte all remaining bits to the stream */
              bufPtr[EncWsPtr->BytePos] = (uint8)((bufPtr[EncWsPtr->BytePos] & (uint8)(~mask)) | (uint8)((BitBuf << (bitsAvail - bitsRemain)) & mask));
              /* #390 There are free bits in current stream byte left, only advance BitPos */
              EncWsPtr->BitPos += bitsRemain;
            }

            /* #400 Finished, there are no remaining bits left */
            bitsRemain = 0;
          }
        }
#if (EXI_ENABLE_SIMPLE_TX_STREAMING_SUPPORT == STD_ON)
      }
      /* #410 TX streaming is used: The current byte shall not be written, just calculate byte and bit positions */
      else
      {
        /* #420 If the stream segment was finished with last byte (writing is active) */
        if (EncWsPtr->WritingToBufferIsActive == Exi_BT_True)
        {
          /* #430 Add the written Length to the streaming parameters */
#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
          EncWsPtr->CurrentStreamSegmentLen = (EncWsPtr->PBufProcessedElementBytes + EncWsPtr->BytePos) - EncWsPtr->StartOffset;
          EncWsPtr->OverallStreamBytePos += EncWsPtr->CurrentStreamSegmentLen;
#else
          EncWsPtr->CurrentStreamSegmentLen = EncWsPtr->BytePos - EncWsPtr->StartOffset;
          EncWsPtr->OverallStreamBytePos += EncWsPtr->CurrentStreamSegmentLen;
#endif
          /* #440 Set streaming state info parameters (disable writing) */
          EncWsPtr->WritingToBufferIsActive = Exi_BT_False;
          EncWsPtr->StreamComplete = Exi_BT_False;

          /* #450 If the stream length shall not be calculated */
          if (EncWsPtr->CalculateStreamLength == Exi_BT_False)
          {
            /* #460 Skip writing further bits, set status code 'End Of Stream' */
            Exi_VBSEncodeSetStatusCode(EncWsPtr, EXI_E_EOS, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          }
        }
        /* #470 If writing starts at the beginning of the byte and no error did occur */
        if ( (EncWsPtr->BitPos == 0u) && (EncWsPtr->StatusCode == EXI_E_OK) )
        {
          /* #480 If more than 8 bits are remaining */
          if (bitsRemain > EXI_BITS_IN_BYTE)
          {
            /* #490 Reduce remaining bits by 8 and continue with next byte */
            bitsRemain -= EXI_BITS_IN_BYTE;
            EncWsPtr->OverallStreamBytePos++;
          }
          /* #500 8 bits or les are remaining */
          else
          {
            /* #510 If 8 bits are remaining */
            if (bitsRemain == EXI_BITS_IN_BYTE)
            {
              /* #520 Just increment the byte position */
              EncWsPtr->OverallStreamBytePos++;
            }
            /* #530 Less than 8 bits are remaining */
            else
            {
              /* #540 Just increment the bit position */
              EncWsPtr->BitPos = bitsRemain;
            }

            /* #550 Finished, all bits have been calculated */
            bitsRemain = 0;
          }
        }
        /* #560 Writing starts somwhere in the current byte, if no error did occur */
        else if (EncWsPtr->StatusCode == EXI_E_OK)
        {
          /* #570 Get avilable bits in current byte */
          bitsAvail = (uint8)(EXI_BITS_IN_BYTE - EncWsPtr->BitPos);

          /* #580 If more bits are remaining than available in current byte */
          if (bitsRemain > bitsAvail)
          {
            /* #590 Reduce remaining bits by available bit count and continue with next byte */
            bitsRemain -= bitsAvail;
            EncWsPtr->BitPos = 0;
            EncWsPtr->OverallStreamBytePos++;
          }
          /* #600 Remaining bits count is less or equal to available bits count */
          else
          {
            /* #610 If remaining bits count is equal to available bits */
            if (bitsRemain == bitsAvail)
            {
              /* #620 Move to next byte */
              EncWsPtr->OverallStreamBytePos++;
              EncWsPtr->BitPos = 0;
            }
            /* #630 Remaining bits count is less that avialalble bits count */
            else
            {
              /* #640 Just increment bit position */
              EncWsPtr->BitPos += bitsRemain;
            }

            /* #650 Finished, there are no remaining bits left */
            bitsRemain = 0;
          }
        }
        else /* Required by MISRA */
        {
          /* Nothing to do, error is already set */
        }
      }
#endif
    }

    if (bitsRemain != 0u)
    {
      Exi_VBSEncodeSetStatusCode(EncWsPtr, EXI_E_EOS, EXI_BS_SSC_NO_DET_CALL, 0, 0);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_ENCODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */

  return (uint8)(BitCount - bitsRemain);                                                                                /* PRQA S 0291 */ /* MD_Exi_21.1_0291 */
}

/* === 7.1.1 BINARY === */

/* UInt + Bytes... (see 7.1.6) */

/**********************************************************************************************************************
 *  Exi_VBSEncodeBytes()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, EXI_CODE) Exi_VBSEncodeBytes(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  P2CONST(uint8, AUTOMATIC, EXI_APPL_DATA) DataPtr,
  uint16 DataLen)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  uint16 idx;

  /* #10 Check plausibility of input parameters */
#if ( EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DataPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
#endif /* (EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* Byte arrays are encoded by writing their length to the stream followed by all byte values */

    /* #20 Encode array length to the stream */
    Exi_VBSEncodeUInt(EncWsPtr, DataLen);
    /* #30 Loop over all array elements */
    for (idx = 0; idx < DataLen; idx++)
    {
      /* #40 Write 8 bits to the stream, if failed */
      if (Exi_VBSWriteBits(EncWsPtr, DataPtr[idx], EXI_BITS_IN_BYTE) != EXI_BITS_IN_BYTE)
      {
        /* #50 End loop error was already set to status code in Exi_VBSWriteBits */
        break;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_ENCODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}

/* === 7.1.2 BOOLEAN === */

/**********************************************************************************************************************
 *  Exi_VBSEncodeBool()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, EXI_CODE) Exi_VBSEncodeBool(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  boolean Value)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_BitBufType boolTmp;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* Booleans are encoded by writing a single bit to the stream */
  /* #10 Convert bool to Exi_BitBufType  */
  if (Value == ((boolean)TRUE))
  {
    boolTmp = 1u;
  }
  else
  {
    boolTmp = 0u;
  }

  /* #20 Write 1 bit to the stream */
  (void)Exi_VBSWriteBits(EncWsPtr, boolTmp, 1);

}

/* === 7.1.3 DECIMAL === */

/* The Decimal datatype representation is a Boolean sign (see 7.1.2 Boolean) followed by two Unsigned Integers (see 7.1.6 Unsigned Integer). */

/* === 7.1.4 FLOAT === */

/* Int + Int (see 7.1.5) */

/* === 7.1.5 INTEGER === */

/* Boolean (see 7.1.2) + UInt (see 7.1.6) */

/**********************************************************************************************************************
 *  Exi_VBSEncodeInt()
 **********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_VBSEncodeInt(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  sint32 Value)
{
  sint32 localResult;
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* This API is used to encode Int16 and Int32 (Note to encode Int8 the API Exi_VBSEncodeUIntN is used with an offset.
   * Int16/32 values are represented by a sign bit and a positive value. Since the value '-0' is not used this value
   * does represent '-1'. So all negative values do have an offset of 1.
   * The value +5 is represented by:
   * - sign bit: FALSE; value 5
   * The value -5 is represented by:
   * - sign bit: TRUE; value 4
   */
  /* #10 If value is negative */
  if (Value < 0)
  {
    /* #20 Write sign bit */
    Exi_VBSEncodeBool(EncWsPtr, TRUE);
    /* #30 Write positive value with an offset of -1 */
    localResult = ((Value + 1) * -1);
    Exi_VBSEncodeUInt(EncWsPtr, (uint32)localResult);
  }
  /* #40 Value is positive */
  else
  {
    /* #50 Write sign bit */
    Exi_VBSEncodeBool(EncWsPtr, FALSE);
    /* #60 Write positive value */
    Exi_VBSEncodeUInt(EncWsPtr, (uint32)(Value));
  }
}

/**********************************************************************************************************************
 *  Exi_VBSEncodeInt64()
 **********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_VBSEncodeInt64(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  Exi_SInt64 Value)
{
#if defined (Exi_SInt64_Available)
  Exi_SInt64 localResult;
#endif
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* Int64 values are represented by a sign bit and a positive value. Since the value '-0' is not used this value
   * does represent '-1'. So all negative values do have an offset of 1.
   * The value +5 is represented by:
   * - sign bit: FALSE; value 5
   * The value -5 is represented by:
   * - sign bit: TRUE; value 4
   */
#if defined (Exi_SInt64_Available)
  /* #10 Sint64 is available: If value is positive */
  if (Value < 0)
#else
  /* #20 Sint64 is not available: If HiWord is positive */
  if (Value.HiWord < 0)
#endif
  {
    /* #30 Write sign bit */
    Exi_VBSEncodeBool(EncWsPtr, TRUE);
    /* #40 Write positive value with an offset of -1 */
#if defined (Exi_SInt64_Available)
    localResult = ((Value + 1) * -1);
    Exi_VBSEncodeUInt64(EncWsPtr, (Exi_UInt64)localResult);
#else
    {
      Exi_UInt64 TempValue;
      sint32 localResult;
      localResult = (Value.HiWord * -1) - 1;
      TempValue.HiWord = (uint32)localResult; /*(uint32)(~Value.HiWord) leads to MISRA warning */
      TempValue.LoWord = ~Value.LoWord;
      Exi_VBSEncodeUInt64(EncWsPtr, TempValue);
    }
#endif
  }
  /* #50 Value is negative */
  else
  {
    /* #60 Write sign bit */
    Exi_VBSEncodeBool(EncWsPtr, FALSE);
    /* #70 Write positive value */
#if defined (Exi_SInt64_Available)
    Exi_VBSEncodeUInt64(EncWsPtr, (Exi_UInt64)(Value));
#else
    {
      Exi_UInt64 TempValue;
      TempValue.HiWord = (uint32)(Value.HiWord);
      TempValue.LoWord = Value.LoWord;
      Exi_VBSEncodeUInt64(EncWsPtr, TempValue);
    }
#endif
  }
}


/**********************************************************************************************************************
 *  Exi_VBSEncodeBigInt()
 **********************************************************************************************************************/
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
/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_VBSEncodeBigInt(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  P2CONST(Exi_BigIntType, AUTOMATIC, EXI_APPL_DATA) ValuePtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  uint16 index;
  uint16 valueLength;
  uint16 valueStartPos;
  uint8 byte;
  uint8 currentBitPosition = 0;
  uint8 bitCount;
  uint8 bitShift;
  boolean decrement;

  /* #10 Check plausibility of input parameters */
#if ( EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (ValuePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
#endif /* (EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* BigInt values are represented by a sign bit and a positive value. Since the value '-0' is not used this value
     * does represent '-1'. So all negative values do have an offset of 1.
     * The value +5 is represented by:
     * - sign bit: FALSE; value 5
     * The value -5 is represented by:
     * - sign bit: TRUE; value 4
     *
     * The most significant bit in the stream of each value byte does contain the information if there are more
     * bytes to read. So each byte does only contain 7 value bits. The 7 least significant bits are encoded to the
     * first byte.
     * The value +128 does require two bytes to encode it
     * First byte:  0b10000000 -> value: 0 but one more byte to read
     * Second byte: 0b00000001 -> value: 1 no more byte to read
     *
     * BigInt values are written from highest (LSB) array index to lowest (MSB) array index.
     */

    /* #20 Write sign bit */
    Exi_VBSEncodeBool(EncWsPtr, ValuePtr->IsNegative);
    /* Get encoding information */
    decrement = ValuePtr->IsNegative;
    index = (uint16)(sizeof(ValuePtr->Value) - 1u);
    valueLength = ValuePtr->Length;
    valueStartPos = (uint16)(sizeof(ValuePtr->Value) - valueLength);
    bitCount = (uint8)ValuePtr->Length * 8u;
    /* #30 If value is negative and more than one byte in size */
    if((ValuePtr->IsNegative == (boolean)TRUE) && (valueLength > 1u))
    {
      /* If the most significant byte equals 0x01 and all other bytes equal 0x00 valueLength need to be decremented.
       * Taking the offset of -1 into account the BigInt will be reduced by one byte in size.
       */

      /* #40 If most significant byte is 1 */
      if(ValuePtr->Value[sizeof(ValuePtr->Value) - valueLength] == 0x01u)
      {
        uint16 tmpIdx;
        Exi_BooleanType allZeros = Exi_BT_True;
        /* #50 Loop over all value bytes and check if they are set to 0 */
        for (tmpIdx = ((uint16)(sizeof(ValuePtr->Value)) - valueLength) + 1u; tmpIdx <= (index); tmpIdx++)
        {
          if (ValuePtr->Value[tmpIdx] != 0x00u)
          {
            allZeros = Exi_BT_False;
            break;
          }
        }
        /* #60 If all value bytes are zero */
        if(allZeros == Exi_BT_True)
        {
          /* #70 Decrement value length by one */
          valueLength--;
        }
      }
    }
    /* #80 Loop as long as more bytes have to be written */
    do
    {
      /* #90 Calculate numbers of bits that have to be shifted to the right */
      bitShift = (uint8)(currentBitPosition % 8u);
      /* #100 Get first part of the byte to be written */
      byte = (uint8)(ValuePtr->Value[index] >> bitShift);
      /* #110 If zero bit shifts are required */
      if(bitShift == 0u)
      {
        /* #120 Mask the value with 0x7F to get the bits to write */
        byte &= 0x7Fu; /* mask 7 least significant bits _1111111 */
      }
      /* #130 If more than one shift is required and current position is within the value length */
      else if((bitShift > 1u) && (valueLength > (sizeof(ValuePtr->Value) - index)))
      {
        /* #140 Decrement value index and get the second part of the byte to be written */
        index--;
        byte |= (uint8)((uint8)(ValuePtr->Value[index] << (8u - bitShift)) & (uint8)0x7F); /* mask 7 least significant bits _1111111 */
      }
      /* #150 If one shift is required and current position is within the value length */
      else if((bitShift == 1u) && (valueLength > (sizeof(ValuePtr->Value) - index))) /* ESCAN00068523 */
      {
        /* #160 7 value bytes are in the buffer, masking is not required */
        index--;
      }
      /* #170 Highest bit in most significant byte is set */
      else /* (valueLength == (sizeof(ValuePtr->Value) - index)) */
      {
        /* #180 This is the last bit to write, it has already been shifted to the correct position */
      }

      /* #190 If value has to be decremented (negative values only; decrement flag is TRUE) */
      if(decrement == (boolean)TRUE)
      {
        /* #200 If current byte value is bigger than zero */
        if(byte != 0x00u)
        {
          /* #210 Drecrement byte to write and set decrement flag to FALSE */
          decrement = FALSE;
          byte--;
        }
        /* #220 Current byte value is zero */
        else
        {
          /* #230 Set byte to write maximum value */
          byte = 0x7Fu;
        }
      }

      /* #240 Increment current bit position */
      currentBitPosition += 7u;
      /* #250 If current position is within the value length or highest bit in most significant byte is set */
      if (currentBitPosition < bitCount)
      {
        uint8 tmpValueToCheck = 0u;
        uint8 tmpBitShift;
        /* #260 Check if there are remaining bytes which are not zero. */
        if (index > 0u)
        {
          uint16 tmpIdx;
          for (tmpIdx = valueStartPos; tmpIdx < index; tmpIdx++)
          {
            if (tmpIdx < EXI_MAX_NUM_BYTES_BIGINT)
            {
              tmpValueToCheck |= ValuePtr->Value[tmpIdx];
              /* As soon as the value is not zero, stop the loop. Setting 0x80 bit is required anyway */
              if (tmpValueToCheck != 0x00u)
              {
                break;
              }
            }
          }
        }
        /*# 250 Calculate the bitshift of the next while loop. */
        tmpBitShift = (uint8)(currentBitPosition % 8u);
        /* #270 Check if there are remaining bits in current byte which are not zero. */
        tmpValueToCheck |= (uint8)(ValuePtr->Value[index] >> tmpBitShift);

        /* #280 Check if an additional byte is required in the stream. */
        if (tmpValueToCheck != 0u)
        {
          /* #290 Set the 0x80 bit to indicate that more value bytes are written */
          byte |= (uint8)0x80; /* Set most significant bit (more bytes indication bit) */
        }
      }

      /* #300 Write the current byte into the stream, if failed */
      if (Exi_VBSWriteBits(EncWsPtr, byte, EXI_BITS_IN_BYTE) != EXI_BITS_IN_BYTE)
      {
        /* #310 End the loop, error is already set to the status code */
        break;
      }
    } while ((byte & 0x80u) == 0x80u);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_ENCODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}

/* === 7.1.6 UNSIGNED INTEGER === */

/**********************************************************************************************************************
 *  Exi_VBSEncodeUInt()
 **********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_VBSEncodeUInt(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  Exi_BitBufType Value)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  uint8 byte;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* This API is used to encode UInt16 and UInt32 (Note to encode UInt8 the API Exi_VBSEncodeUIntN is used.
   * The most significant bit of each value byte does contain the information if there are more bytes. So
   * each byte does only contain 7 value bits. The 7 least significant bits are encoded to the first byte.
   * The value 128 does require two bytes to encode it
   * First byte:  0b10000000 -> value: 0 but one more byte to read
   * Second byte: 0b00000001 -> value: 1 no more byte to read
   * The maximum value size is 32 bit, so there will be written 5 bytes maximum. The last byte has only 4 valuable bits.
   */
  /* #10 Loop as long as more bytes have to be written */
  do
  {
    /* #20 Mask value to use 7 bits only */
    byte = (uint8)(Value & 0x7Fu); /* mask 7 least significant bits _1111111 */

    /* #30 If further iterations are required (value is bigger or equal to 128) */
    if (Value >= 128u)
    {
      /* #40 Set 'more bytes' bit */
      byte |= (uint8)0x80; /* Set most significant bit (more bytes indication bit) */
      /* #50 Shift value 7 bits to the left to prepare for next cycle */
      Value >>= 7u;                                                                                                     /* PRQA S 1338 */ /* MD_Exi_FunctionParameter */
    }
    /* #60 Write the current 8 bits to the stream, if failed */
    if (Exi_VBSWriteBits(EncWsPtr, byte, EXI_BITS_IN_BYTE) != EXI_BITS_IN_BYTE)
    {
      /* #70 End the loop, status code is already set to error by Exi_VBSWriteBits */
      break;
    }
  } while ((byte & 0x80u) == 0x80u);
}

/**********************************************************************************************************************
 *  Exi_VBSEncodeUInt64()
 **********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_VBSEncodeUInt64(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  Exi_UInt64 Value)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  uint8 byte;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* The most significant bit of each value byte does contain the information if there are more bytes to read. So
   * each byte does only contain 7 value bits. The 7 least significant bits are encoded to the first byte.
   * The value 128 does require two bytes to encode it
   * First byte:  0b10000000 -> value: 0 but one more byte to read
   * Second byte: 0b00000001 -> value: 1 no more byte to read
   * The maximum value size is 64 bit, so there will be written 10 bytes maximum. The last byte has only 1 valuable bit.
   */
  /* #10 Loop as long as more bytes have to be written */
  do
  {
#if defined (Exi_UInt64_Available)
    /* #20 If UInt64 datatype is available in this platform */
    {
      /* #30 Mask value to use 7 bits only */
      byte = (uint8)(Value & 0x7Fu); /* mask 7 least significant bits _1111111 */

      /* #40 If further iterations are required (value is bigger or equal to 128) */
      if (Value >= 128u)
      {
        /* #50 Set 'more bytes' bit */
        byte |= (uint8)0x80; /* Set most significant bit (more bytes indication bit) */
        /* #60 Shift value 7 bits to the left to prepare for next cycle */
        Value >>= 7u;                                                                                                   /* PRQA S 1338 */ /* MD_Exi_FunctionParameter */
      }
    }
#else
    /* #70 If UInt64 datatype is not available in this platform */
    {
      /* #80 Mask low word to use 7 bits only */
      byte = (uint8)(Value.LoWord & 0x7Fu); /* mask 7 least significant bits _1111111 */

      /* #90 If further iterations are required (HiWord unequal 0 or LoWord bigger 128) */
      if ((Value.HiWord != 0u) || (Value.LoWord >= 128u))
      {
        /* #100 Set 'more bytes' bit */
        byte |= (uint8)0x80; /* Set most significant bit (more bytes indication bit) */
        /* #110 Build new LoWord to prepare for next cycle */
        Value.LoWord = ((Value.HiWord << 25u) | (Value.LoWord >> 7u));
        /* #120 Shift HiWord 7 bits to the left */
        Value.HiWord >>= 7u;
      }
    }
#endif

    /* #130 Write the current 8 bits to the stream, if failed */
    if(Exi_VBSWriteBits(EncWsPtr, byte, EXI_BITS_IN_BYTE) != EXI_BITS_IN_BYTE)
    {
      /* #140 End the loop, status code is already set to error by Exi_VBSWriteBits */
      break;
    }
  } while ((byte & 0x80u) == 0x80u);
}


/* === 7.1.7 QNAME === */

/* String (see 7.1.10) */

/* === 7.1.8 DATE TIME === */

/* Year           Int */
/* MonthDay       UInt(9) */
/* Time           UInt(17) */
/* FractionalSecs UInt */
/* TimeZone       UInt(11) */
/* presence       Boolean */

/* === 7.1.9 N-BIT UNSIGNED INTEGER === */

/**********************************************************************************************************************
 *  Exi_VBSEncodeUIntN()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, EXI_CODE) Exi_VBSEncodeUIntN(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  Exi_BitBufType BitBuf,
  uint8 BitCount)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
#if ( EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (BitCount > (sizeof(Exi_BitBufType) * 8u))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
#endif /* (EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Write bits to the stream */
    (void)Exi_VBSWriteBits(EncWsPtr, BitBuf, BitCount);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_ENCODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}

/* === 7.1.10 STRING === */

/**********************************************************************************************************************
 *  Exi_VBSEncodeStringOnly()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, EXI_CODE) Exi_VBSEncodeStringOnly(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  P2CONST(uint8, AUTOMATIC, EXI_APPL_VAR) StrBufPtr,
  uint16 StrBufLen)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  uint16 idx;

  /* #10 Check plausibility of input parameters */
#if ( EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (StrBufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
#endif /* (EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Loop over all string bytes */
    for (idx = 0; idx < StrBufLen; idx++)
    {
      /* #30 Wirte string byte to the stream */
      Exi_VBSEncodeUIntN(EncWsPtr, (Exi_BitBufType)StrBufPtr[idx], EXI_BITS_IN_BYTE);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_ENCODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}

/**********************************************************************************************************************
 *  Exi_VBSEncodeString()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, EXI_CODE) Exi_VBSEncodeString(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  P2CONST(uint8, AUTOMATIC, EXI_APPL_VAR) StrBufPtr,
  uint16 StrBufLen)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
#if ( EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (StrBufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
#endif /* (EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Write string length to the stream */
    Exi_VBSEncodeUInt(EncWsPtr, (Exi_BitBufType)StrBufLen);
    /* #30 Write string to the stream */
    Exi_VBSEncodeStringOnly(EncWsPtr, StrBufPtr, StrBufLen);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_ENCODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}

/**********************************************************************************************************************
 *  Exi_VBSEncodeStringValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, EXI_CODE) Exi_VBSEncodeStringValue(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  P2CONST(uint8, AUTOMATIC, EXI_APPL_VAR) StrBufPtr,
  uint16 StrBufLen)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
#if ( EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (StrBufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
#endif /* (EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Write string information element to the stream */
    /* String information element has the following values:
     * - 0: String is contained in the local string table
     * - 1: String is contained in the global string table
     * - >1: String is contained in the stream length is 'information - 2'
     * This encoder does not support any string tables, just increment length by 2 to get the information element.
     */
    Exi_VBSEncodeUInt(EncWsPtr, ((Exi_BitBufType)StrBufLen) + 2u);
    /* #30 Write string to the stream */
    Exi_VBSEncodeStringOnly(EncWsPtr, StrBufPtr, StrBufLen);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_ENCODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}

/* === 7.1.11 LIST === */

/**********************************************************************************************************************
 *  Exi_VBSEncodeGetWorkspaceBitPos()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(uint32, EXI_CODE) Exi_VBSEncodeGetWorkspaceBitPos(
  P2CONST(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  uint32 bytePosition;

  /* #10 Set position in current buffer (segment) */
  bytePosition = EncWsPtr->BytePos;

#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
  /* #20 If feature PBUF support is enabled */
  {
    /* #30 If not in first segment */
    if (EncWsPtr->PBufIdx != 0u)
    {
      uint8 TmpPBufIdx;

      /* #40 Add length of all previouse PBuf segments */
      for (TmpPBufIdx = 0; TmpPBufIdx < EncWsPtr->PBufIdx; TmpPBufIdx++)
      {
        bytePosition += EncWsPtr->PBufPtr[TmpPBufIdx].len;
      }
    }
  }
#endif

  /* #50 Calculate current bit position from the byte position and return the result */
  return ((uint32)(bytePosition << 3)) + EncWsPtr->BitPos;
}

/**********************************************************************************************************************
 *  Exi_VBSEncodeSetStatusCode
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
FUNC(void, EXI_CODE) Exi_VBSEncodeSetStatusCode(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  Exi_ReturnType NewStatusCode,
  Exi_BSSetStatusCodeDetType CallInternal,
  uint16 ApiId,
  uint8 ErrorId)
{
#if ( EXI_INTERNAL_DEV_ERROR_REPORT != STD_ON )
  EXI_DUMMY_STATEMENT_CONST(ApiId);                                                                                     /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  EXI_DUMMY_STATEMENT_CONST(ErrorId);                                                                                   /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */

  /* #10 If DET error shall be set in any case */
  if (CallInternal == EXI_BS_SSC_CALL_DET_ALLWAYS)
  {
    /* #20 Set DET error using the provided API and ERROR ID */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
    (void)Det_ReportError(EXI_MODULE_ID, EXI_ENCODER_INSTANCE_ID, (uint8)ApiId, ErrorId);
#endif
  }
  /* #30 If status code is still OK */
  if (EncWsPtr->StatusCode == EXI_E_OK)
  {
    /* #40 If DET shall be set on status code changes */
    if (CallInternal == EXI_BS_SSC_CALL_DET_ON_CHANGE)
    {
      /* #50 Set DET error using the provided API and ERROR ID */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
      (void)Det_ReportError(EXI_MODULE_ID, EXI_ENCODER_INSTANCE_ID, (uint8)ApiId, ErrorId);
#endif

    }
    /* #60 Set new status code */
    EncWsPtr->StatusCode = NewStatusCode;
  }
}

/**********************************************************************************************************************
 *  Exi_VBSEncodeCheckAndEncodeEE
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, EXI_CODE) Exi_VBSEncodeCheckAndEncodeEE(
  P2VAR(Exi_BSEncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr,
  Exi_BitBufType BitBuf,
  uint8 BitCount)
{
  /* #10 If end element (EE) flag is set */
  if (EncWsPtr->EERequired == Exi_BT_True)
  {
    /* #20 Write EE event code to the stream */
    Exi_VBSEncodeUIntN(EncWsPtr, BitBuf, BitCount);
  }
  /* #30 End element flag is not set */
  else
  {
    /* #40 EE already encoded in subfunction call, reset EE flag to TRUE */
    EncWsPtr->EERequired = Exi_BT_True;
  }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Exi_BSEncoder.c
 **********************************************************************************************************************/
