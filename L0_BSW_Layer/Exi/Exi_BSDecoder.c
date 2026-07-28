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
/**        \file  Exi_BSDecoder.c
 *        \brief  Efficient XML Interchange basic decoder source file
 *
 *      \details  Vector static code implementation for the Efficient XML Interchange sub-component basic decoder.
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
/* PRQA S 2755 EOF */ /* MD_Exi_DataFlowAnalysisTimeout */

#define EXI_BS_DECODER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "vstdlib.h"
#include "Exi.h"
#include "Exi_BSDecoder.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

#if !defined (EXI_LOCAL)
# define EXI_LOCAL static
#endif /* !defined (EXI_LOCAL) */

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/
typedef enum
{
  EXI_BSDSD_GENERIC_ELEMENT = 0,
  EXI_BSDSD_STRING_VALUE    = 1,
  EXI_BSDSD_NOT_SET         = 2
} Exi_BSDecoder_SchemaDeviationType;

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Exi_VBSDecodeTruncateRemainder
 *********************************************************************************************************************/
/*! \brief         Compare actual length with respected buffer length.
 *  \details       Check if actual length exceeds respected buffer length and truncate remaining bytes if permitted.
 *                 Otherwise throw an error.
 *  \param[in]     DecWsPtr             EXI bitstream decoding workspace
 *  \param[in]     ActualLen            Length information that is read from EXI stream
 *  \param[in]     ProvidedLen          Length that is available in buffer
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
EXI_LOCAL FUNC(void, EXI_CODE) Exi_VBSDecodeTruncateRemainder(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  uint32 ActualLen,
  uint32 ProvidedLen);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_VBSDecodeInitWorkspace()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, EXI_CODE) Exi_VBSDecodeInitWorkspace(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
  P2CONST(IpBase_PbufType, AUTOMATIC, EXI_APPL_VAR) PBufPtr,
#else
  P2CONST(uint8, AUTOMATIC, EXI_APPL_VAR) BufPtr,
  uint32 BufLen,
#endif
  uint32 ByteOffset)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Std_ReturnType retVal;

  /* #10 Check plausibility of input parameters */
#if ( EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON )
  retVal = E_NOT_OK;
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
#endif /* (EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize the workspace */
    DecWsPtr->StartOffset = ByteOffset;
    DecWsPtr->TotalStreamLength = 0;
#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
    DecWsPtr->PBufIdx = 0;
    DecWsPtr->PBufPtr = PBufPtr;
    DecWsPtr->PBufProcessedElementBytes = 0;
    /* Check if offset position is in current PBuf segment */
    if (ByteOffset >= (uint32)PBufPtr->len)
    {
      /* Get the PBuf segment where the offset is inside */
      while (ByteOffset >= (uint32)PBufPtr[DecWsPtr->PBufIdx].len)
      {
        DecWsPtr->PBufProcessedElementBytes += PBufPtr[DecWsPtr->PBufIdx].len;
        ByteOffset -= PBufPtr[DecWsPtr->PBufIdx].len;                                                                   /* PRQA S 1338 */ /* MD_Exi_FunctionParameter */
        DecWsPtr->PBufIdx++;
      }
    }
    DecWsPtr->BytePos = (uint16)ByteOffset;
#else
    DecWsPtr->BufPtr = BufPtr;
    DecWsPtr->BufLen = BufLen;
    DecWsPtr->BytePos = (uint32)ByteOffset;
#endif
    DecWsPtr->BitPos = 0;

    DecWsPtr->EERequired = Exi_BT_True;
    DecWsPtr->StatusCode = EXI_E_OK;

    DecWsPtr->DeviationWs.ComplexGenericElementsCount = 0;
    DecWsPtr->DeviationWs.ElementIndexRequired = Exi_BT_False;
    DecWsPtr->DeviationWs.ElementContentEERequired = Exi_BT_False;
    DecWsPtr->DeviationWs.IsAttribute = Exi_BT_False;
    DecWsPtr->DeviationWs.DeviationOccur = Exi_BT_False;
    retVal = E_OK;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
}

/**********************************************************************************************************************
 *  Exi_VBSReadHeader()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, EXI_CODE) Exi_VBSReadHeader(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_BitBufType bitBuf = 0;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Read and check EXI header (8 bits) */
  if (   (Exi_VBSReadBits(DecWsPtr, &bitBuf, EXI_BITS_IN_BYTE) != EXI_BITS_IN_BYTE)
      || ((uint8)bitBuf != EXI_HEADER_BYTE))
  {
    /* buffer to small or header byte value does not match */
    Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_INV_HEADER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
  }
}

/**********************************************************************************************************************
 *  Exi_VBSReadBits()
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
 */
/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(uint8, EXI_CODE) Exi_VBSReadBits(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(Exi_BitBufType, AUTOMATIC, EXI_APPL_VAR) BitBufPtr,
  uint8 BitCount)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  uint8 bitsRemain; /* number of bits that have to be read until BitCount is reached */
  uint8 bitsAvail;  /* number of available bits in current byte */
  P2CONST(uint8, AUTOMATIC, EXI_APPL_VAR) bufPtr;
  uint8 localResult;

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
    bufPtr = DecWsPtr->PBufPtr[DecWsPtr->PBufIdx].payload;
#else
    bufPtr = DecWsPtr->BufPtr;
#endif

    /* #20 Loop until all bits are read or an error is detected */
    while ((bitsRemain > 0u) && (DecWsPtr->StatusCode == EXI_E_OK))
    {
#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
      /* #30 PUBF is used: If end of buffer segment has been reached */
      if (DecWsPtr->BytePos >= DecWsPtr->PBufPtr[DecWsPtr->PBufIdx].len)
      {
        /* end of current PBuf segment reached */
#if (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON)
        /* Check if data outside the current segment was read */
        if (DecWsPtr->BytePos != DecWsPtr->PBufPtr[DecWsPtr->PBufIdx].len)
        {
          (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, (uint8)EXI_API_ID_V_INTERNAL_FUNCTION, EXI_E_INVALID_PBBUF_POS);
        }
        else if (DecWsPtr->BitPos != 0u)
        {
          (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, (uint8)EXI_API_ID_V_INTERNAL_FUNCTION, EXI_E_INVALID_PBBUF_POS);
        }
        else
        {
          /* No det error, nothing to do */
        }
#endif /* EXI_INTERNAL_DEV_ERROR_REPORT */

        /* #40 Mark current segment as processed */
        DecWsPtr->PBufProcessedElementBytes += DecWsPtr->PBufPtr[DecWsPtr->PBufIdx].len;
        /* #50 If more PBuf segments are available */
        if (DecWsPtr->PBufProcessedElementBytes < DecWsPtr->PBufPtr[DecWsPtr->PBufIdx].totLen)
        {
          /* #60 Switch from current PBuf segment to next segement */
          DecWsPtr->PBufIdx++;
          bufPtr = DecWsPtr->PBufPtr[DecWsPtr->PBufIdx].payload;
          /* #70 Set the byte pos to the beginning of the new PBuf segment */
          DecWsPtr->BytePos = 0u;
        }
        /* #80 End of PBuf segments reached */
        else
        {
          /* #90 End reading, there are still remaining bits */
          break;
        }
      }
#else
      /* #100 Linear buffer is used: If end of buffer has been reached */
      if (DecWsPtr->BytePos >= DecWsPtr->BufLen)
      {
        /* #110 End reading, there are still remaining bits */
        break;
      }
#endif

      /* #120 If read start position is at the beginning of current byte */
      if (DecWsPtr->BitPos == 0u)
      {
        /* #130 If more than 8 bits have to be read */
        if (bitsRemain > EXI_BITS_IN_BYTE)
        {
          /* #140 Read complete byte */
          *BitBufPtr <<= EXI_BITS_IN_BYTE;
          *BitBufPtr |= bufPtr[DecWsPtr->BytePos];

          bitsRemain -= EXI_BITS_IN_BYTE;

          /* #150 Continue with next byte */
          DecWsPtr->BytePos++;
        }
        /* #160 8 bits or less have to be read, all bits to read are in current byte */
        else
        {
          /* #170 Read remaining bits only */
          *BitBufPtr <<= bitsRemain;

          /* #180 If 8 bits shall be read */
          if (bitsRemain == EXI_BITS_IN_BYTE)
          {
            /* #190 Read 8 bits from the buffer */
            *BitBufPtr |= bufPtr[DecWsPtr->BytePos];
            /* #200 Complete byte read, increment byte position */
            DecWsPtr->BytePos++;
          }
          /* #210 Less than 8 bits shall be read */
          else
          {
            /* #220 Read remaining bits from buffer */
            localResult = bufPtr[DecWsPtr->BytePos] >> ((uint8)(EXI_BITS_IN_BYTE)-bitsRemain);
            *BitBufPtr |= (Exi_BitBufType)localResult;
            /* #230 Unread bits are left in current byte, only advance BitPos */
            DecWsPtr->BitPos = bitsRemain;
          }

          /* #240 Finished, there are no remaining bits left */
          bitsRemain = 0;
        }
      }
      /* #250 Read start position is somewhere in the current byte */
      else
      {
        /* #260 If not all remaining bits are in current byte */
        if ((DecWsPtr->BitPos + bitsRemain) > EXI_BITS_IN_BYTE)
        {
          /* #270 Read all available bits in current byte */
          bitsAvail = (uint8)(EXI_BITS_IN_BYTE - DecWsPtr->BitPos);

          *BitBufPtr <<= bitsAvail;
          *BitBufPtr |= (uint8)(bufPtr[DecWsPtr->BytePos] & (0xFFu >> DecWsPtr->BitPos));

          /* #280 All bits in current byte have been read, continue reading at beginning of next byte */
          DecWsPtr->BitPos = 0;
          DecWsPtr->BytePos++;

          bitsRemain -= bitsAvail;
        }
        /* #290 All remaining bits are in current byte */
        else
        {
          /* #300 Read all remaining bits */
          *BitBufPtr <<= bitsRemain;

          /* #310 If remaining bits end at current byte end */
          if ((DecWsPtr->BitPos + bitsRemain) == EXI_BITS_IN_BYTE)
          {
            /* #320 Read remaining bits */
            *BitBufPtr |= (uint8)(bufPtr[DecWsPtr->BytePos] & (0xFFu >> DecWsPtr->BitPos));
            /* #330 All bits of current byte have been read */
            DecWsPtr->BytePos++;
            DecWsPtr->BitPos = 0;
          }
          /* #340 Remaining bits end somewhere in the current byte */
          else
          {
            /* #350 Read only remaining bits */
            localResult = (bufPtr[DecWsPtr->BytePos] >> (uint8)(EXI_BITS_IN_BYTE - bitsRemain - DecWsPtr->BitPos));
            localResult &= (uint8)((1u << bitsRemain) - 1u);
            *BitBufPtr |= (Exi_BitBufType)localResult;
            /* #360 Unread bits are left in current byte, only advance BitPos */
            DecWsPtr->BitPos += bitsRemain;
          }

          /* #370 Finished, there are no remaining bits left */
          bitsRemain = 0;
        }
      }
    }

    /* #380 If not all bits could be read */
    if(bitsRemain != 0u)
    {
      /* #390 Set error end of stream (EOS) reached */
      Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_EOS, EXI_BS_SSC_NO_DET_CALL, 0, 0);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */

  return (uint8)(BitCount - bitsRemain);                                                                                /* PRQA S 0291 */ /* MD_Exi_21.1_0291 */
}


/**********************************************************************************************************************
 *  Exi_VBSDecodeSkipBits()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(uint32, EXI_CODE) Exi_VBSDecodeSkipBits(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  uint32 BitCount)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  uint32 newBitPos;
  uint32 oldBitPos;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Get current bit position in the EXI stream */
  oldBitPos = Exi_VBSDecodeGetWorkspaceBitPos(DecWsPtr);
  /* #20 Calculate and set new bit position in the EXI stream */
  newBitPos = Exi_VBSDecodeSetWorkspaceBitPos(DecWsPtr, oldBitPos + BitCount);

  /* #30 Return number of skipped bits */
  return (newBitPos - oldBitPos);
}
/* === 7.1.1 BINARY === */

/* UInt + Bytes... (see 7.1.6) */

/**********************************************************************************************************************
 *  Exi_VBSDecodeBytes()
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
/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_VBSDecodeBytes(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR) BufPtr,
  P2VAR(uint16, AUTOMATIC, EXI_APPL_VAR) BufLenPtr,
  Exi_BooleanType MaxLengthRestricted)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BitBufType bitBuf = 0;
  Exi_BitBufType numBytes = 0;
  uint16 copyByteLen;
  uint16 i;

  /* #10 Check plausibility of input parameters */
#if ( EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (BufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (BufLenPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
#endif /* (EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode the size of the byte array */
    Exi_VBSDecodeUInt(DecWsPtr, &numBytes);

    /* #30 If an error did occur */
    if (DecWsPtr->StatusCode != EXI_E_OK)
    {
      /* #40 If error integer overflow was set */
      if (DecWsPtr->StatusCode == EXI_E_INT_OVERFLOW)
      {
        /* #50 Abort decoding, length of byte array unknown. */
        DecWsPtr->StatusCode = EXI_E_NOT_OK;
      }
    }
    /* #60 Size has been successfully decoded */
    else
    {
      /* #70 Check if byte array is bigger than the available buffer */
      if (numBytes > (*BufLenPtr))
      {
        /* #80 Check if the maximum length is restricted */
        if (MaxLengthRestricted == Exi_BT_True)
        {
          /* #90 Throw an overflow error */
          copyByteLen = 0;
          Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_ARR_OVERFLOW, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
        else
        {
          /* #100 Limit the size to decode to the size of the available buffer */
          copyByteLen = (*BufLenPtr);
        }
      }
      /* #110 Byte array does fit into the buffer */
      else
      {
        /* #120 decode the complete size of the array */
        copyByteLen = (uint16)numBytes;
      }

      /* #130 Read all bytes from stream */
      for(i = 0; i < copyByteLen; i++)
      {
        Exi_VBSDecodeUIntN(DecWsPtr, &bitBuf, EXI_BITS_IN_BYTE);
        BufPtr[i] = (uint8)bitBuf;
      }

      Exi_VBSDecodeTruncateRemainder(DecWsPtr, numBytes, copyByteLen);

      /* #140 Null-terminate array if possible */
      if (numBytes < (*BufLenPtr))
      {
        BufPtr[numBytes] = 0;
      }

      *BufLenPtr = copyByteLen;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}

/* === 7.1.2 BOOLEAN === */

/**********************************************************************************************************************
 *  Exi_VBSDecodeBool()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, EXI_CODE) Exi_VBSDecodeBool(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(boolean, AUTOMATIC, EXI_APPL_VAR) ValuePtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  uint32 bitBuf = 0;

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
    /* #20 Read boolean value */
    if (Exi_VBSReadBits(DecWsPtr, &bitBuf, 1) == 1u)
    {
      /* #30 Convert boolean value */
      if ((bitBuf & 0x1u) != 0u)
      {
        *ValuePtr = TRUE;
      }
      else
      {
        *ValuePtr = FALSE;
      }
    }
    else
    {
      Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_INT_OVERFLOW, EXI_BS_SSC_NO_DET_CALL, 0, 0);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}

/* === 7.1.3 DECIMAL === */

/* The Decimal datatype representation is a Boolean sign (see 7.1.2 Boolean) followed by two Unsigned Integers (see 7.1.6 Unsigned Integer). */

/* === 7.1.4 FLOAT === */

/* Int + Int (see 7.1.5) */

/* === 7.1.5 INTEGER === */

/* Boolean (see 7.1.2) + UInt (see 7.1.6) */


/**********************************************************************************************************************
 *  Exi_VBSDecodeInt8()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, EXI_CODE) Exi_VBSDecodeInt8(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(sint8, AUTOMATIC, EXI_APPL_VAR) ValuePtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BitBufType thisValue = 0;
  uint32 localResult;

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
    /* Int8 values are represented as a 8-bit unsigned integer value with offset 128 */
    /* #20 Read 8 bits from EXI stream */
    Exi_VBSDecodeUIntN(DecWsPtr, &thisValue, 8);
    /* #30 Subtract 128 from the read value to remove the offset */
    localResult = thisValue;
    localResult -= (uint32)128;
    *ValuePtr = (sint8)localResult; /* changed from (sint8)(thisValue - 128) for QAC9 */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}

/**********************************************************************************************************************
 *  Exi_VBSDecodeInt16()
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
 */
FUNC(void, EXI_CODE) Exi_VBSDecodeInt16(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(sint16, AUTOMATIC, EXI_APPL_VAR) ValuePtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BitBufType thisValue;
  boolean negative = FALSE;

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
    /* Int16 values are represented by a sign bit and a positive value. Since the value '-0' is not used this value
     * does represent '-1'. So all negative values do have an offset of 1.
     * The value +5 is represented by:
     * - sign bit: FALSE; value 5
     * The value -5 is represented by:
     * - sign bit: TRUE; value 4
     */
    /* #20 Read the sign bit from the stream */
    Exi_VBSDecodeBool(DecWsPtr, &negative);
    /* #30 Read the value from the stream */
    Exi_VBSDecodeUInt(DecWsPtr, &thisValue);

    /* #40 If previouse decoding was successfull */
    if (DecWsPtr->StatusCode == EXI_E_OK)
    {
      /* #50 If value is negative */
      if (negative == (boolean)TRUE)
      {
        /* #60 If value is smaller than sint16 negative maximum */
        if (thisValue < EXI_SINT16_MAX_NEG_NUM)
        {
          /* #70 Cast value to negative value and subtract 1 */
          *ValuePtr = (sint16)((-(sint16)thisValue) - 1);
        }
        /* #80 Value is bigger than or equal to negative maximum */
        else
        {
          /* #90 Set the minimum possible value */
          *ValuePtr = (-(sint16)EXI_SINT16_MAX_POS_NUM) - 1; /* (sint16)EXI_SINT16_MAX_NEG_NUM leads to MISRA warning */
          /* #100 Set overflow error code */
          Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_INT_OVERFLOW, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
      /* #110 Value is positive */
      else
      {
        /* #120 If value is smaller than or equal to sint16 positive maximum */
        if (thisValue <= EXI_SINT16_MAX_POS_NUM)
        {
          /* #130 Set positive value */
          *ValuePtr = (sint16)thisValue;
        }
        /* #140 Value is bigger than positive maximum */
        else
        {
          /* #150 Set the maximum possible value */
          *ValuePtr = (sint16)EXI_SINT16_MAX_POS_NUM;
          /* #160 Set overflow error code */
          Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_INT_OVERFLOW, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}

/**********************************************************************************************************************
 *  Exi_VBSDecodeInt32()
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
 */
FUNC(void, EXI_CODE) Exi_VBSDecodeInt32(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(sint32, AUTOMATIC, EXI_APPL_VAR) ValuePtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BitBufType thisValue;
  boolean negative = FALSE;

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
    /* Int32 values are represented by a sign bit and a positive value. Since the value '-0' is not used this value
     * does represent '-1'. So all negative values do have an offset of 1.
     * The value +5 is represented by:
     * - sign bit: FALSE; value 5
     * The value -5 is represented by:
     * - sign bit: TRUE; value 4
     */
    /* #20 Read the sign bit from the stream */
    Exi_VBSDecodeBool(DecWsPtr, &negative);
    /* #30 Read the value from the stream */
    Exi_VBSDecodeUInt(DecWsPtr, &thisValue);

    /* #40 If previouse decoding was successfull */
    if (DecWsPtr->StatusCode == EXI_E_OK)
    {
      /* #50 If value is negative */
      if (negative == (boolean)TRUE)
      {
        /* #60 If value is smaller than sint32 negative maximum */
        if (thisValue < EXI_SINT32_MAX_NEG_NUM)
        {
          /* #70 Cast value to negative value and subtract 1 */
          *ValuePtr = (-(sint32)thisValue) - 1;
        }
        /* #80 Value is bigger than or equal to negative maximum */
        else
        {
          /* #90 Set the minimum possible value */
          *ValuePtr = (-(sint32)EXI_SINT32_MAX_POS_NUM) - 1; /* (sint32)EXI_SINT32_MAX_NEG_NUM leads to MISRA warning */
          /* #100 Set overflow error code */
          Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_INT_OVERFLOW, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
      /* #110 Value is positive */
      else
      {
        /* #120 If value is smaller than or equal to sint32 positive maximum */
        if (thisValue <= EXI_SINT32_MAX_POS_NUM)
        {
          /* #130 Set positive value */
          *ValuePtr = (sint32)thisValue;
        }
        /* #140 Value is bigger than positive maximum */
        else
        {
          /* #150 Set the maximum possible value */
          *ValuePtr = (sint32)EXI_SINT32_MAX_POS_NUM;
          /* #160 Set overflow error code */
          Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_INT_OVERFLOW, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}

/**********************************************************************************************************************
 *  Exi_VBSDecodeInt64()
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
 */
FUNC(void, EXI_CODE) Exi_VBSDecodeInt64(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(Exi_SInt64, AUTOMATIC, EXI_APPL_VAR) ValuePtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_UInt64 thisValue;
  boolean negative = FALSE;

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
    /* Int32 values are represented by a sign bit and a positive value. Since the value '-0' is not used this value
     * does represent '-1'. So all negative values do have an offset of 1.
     * The value +5 is represented by:
     * - sign bit: FALSE; value 5
     * The value -5 is represented by:
     * - sign bit: TRUE; value 4
     */
    /* #20 Read the sign bit from the stream */
    Exi_VBSDecodeBool(DecWsPtr, &negative);
    /* #30 Read the value from the stream */
    Exi_VBSDecodeUInt64(DecWsPtr, &thisValue);

    /* #40 If previouse decoding was successfull */
    if (DecWsPtr->StatusCode == EXI_E_OK)
    {
      /* #50 If value is negative */
      if (negative == (boolean)TRUE)
      {
#if defined(Exi_SInt64_Available)
        /* #60 If SInt64 datatype is available in this platform */
        {
          /* #70 If value is smaller than sint64 negative maximum */
          if (thisValue < EXI_SINT64_MAX_NEG_NUM)
          {
            /* #80 Cast value to negative value and subtract 1 */
            *ValuePtr = (-(Exi_SInt64)thisValue) - 1;
          }
          /* #90 Value is bigger than or equal to negative maximum */
          else
          {
            /* #100 Set the minimum possible value */
            *ValuePtr = (-(Exi_SInt64)EXI_SINT64_MAX_POS_NUM) - 1; /* (Exi_SInt64)EXI_SINT64_MAX_NEG_NUM leads to MISRA warning */
            /* #110 Set overflow error code */
            Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_INT_OVERFLOW, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          }
        }
#else
        /* #120 If SInt64 datatype is not available in this platform */
        {
          /* #130 If the high word is smaller than sint32 negative maximum */
          if (thisValue.HiWord < EXI_SINT32_MAX_NEG_NUM)
          {
            /* #140 Invert value and set to high-low word structure */
            (*ValuePtr).HiWord = (-(sint32)thisValue.HiWord) - 1;
            (*ValuePtr).LoWord = ~(thisValue.LoWord);
          }
          /* #150 high word is bigger than or equal to negative maximum */
          else
          {
            /* #160 Set the minimum possible value */
            (*ValuePtr).HiWord = (-(sint32)EXI_SINT32_MAX_POS_NUM) - 1;
            (*ValuePtr).LoWord = 0;
            /* #170 Set overflow error code */
            Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_INT_OVERFLOW, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          }
        }
#endif
      }
      /* #180 Value is positive */
      else
      {
#if defined(Exi_SInt64_Available)
        /* #190 If SInt64 datatype is available in this platform */
        {
          /* #200 If value is smaller than or equal to sint64 positive maximum */
          if (thisValue <= EXI_SINT64_MAX_POS_NUM )
          {
            /* #210 Set positive value */
            *ValuePtr = (Exi_SInt64)thisValue;
          }
          /* #220 Value is bigger than positive maximum */
          else
          {
            /* #230 Set the maximum possible value */
            *ValuePtr = (Exi_SInt64)EXI_SINT64_MAX_POS_NUM;
            /* #240 Set overflow error code */
            Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_INT_OVERFLOW, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          }
        }
#else
        /* #250 If SInt64 datatype is not available in this platform */
        {
          /* #260 If the high word is smaller than or equal to sint64 positive maximum */
          if (thisValue.HiWord <= EXI_SINT32_MAX_POS_NUM)
          {
            /* #270 Set value to high-low word structure */
            (*ValuePtr).HiWord = (sint32)thisValue.HiWord;
            (*ValuePtr).LoWord = thisValue.LoWord;
          }
          else
          {
            /* #280 Set the maximum possible value */
            (*ValuePtr).HiWord = (sint32)EXI_SINT32_MAX_POS_NUM;
            (*ValuePtr).LoWord = EXI_UINT32_MAX_NUM;
            /* #290 Set overflow error code */
            Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_INT_OVERFLOW, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          }
        }
#endif
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}

/**********************************************************************************************************************
 *  Exi_VBSDecodeBigInt()
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
 */
/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_VBSDecodeBigInt(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(Exi_BigIntType, AUTOMATIC, EXI_APPL_VAR) ValuePtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  uint32 bitBuf = 0x80u; /* Set most significant bit for byte values, to enter the while loop */
  uint16 valueSize;
  uint8 currentBitPosition = 0u;
  uint8 bitShift;

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
     * The most significant bit of each value byte does contain the information if there are more bytes to read. So
     * each byte does only contain 7 value bits. The 7 least significant bits are encoded to the first byte.
     * The value +128 does require two bytes to encode it
     * First byte:  0b10000000 -> value: 0 but one more byte to read
     * Second byte: 0b00000001 -> value: 1 no more byte to read
     */
    valueSize = sizeof(ValuePtr->Value);
    /* #20 Read sign bit */
    Exi_VBSDecodeBool(DecWsPtr, &ValuePtr->IsNegative);
    ValuePtr->Length = 1u;
    /* #30 Loop as long as most significant bit is set */
    while ((bitBuf & 0x80u) == 0x80u)
    {
      bitBuf = 0u;
      /* #40 Calculate numbers of bits that have to be shifted to the left */
      bitShift = (uint8)(currentBitPosition % 8u);
      /* #50 Read 8 bits from the stream, if successfull */
      if (Exi_VBSReadBits(DecWsPtr, &bitBuf, EXI_BITS_IN_BYTE) == EXI_BITS_IN_BYTE)
      {
        /* #60 Shift and store value in current value byte */
        ValuePtr->Value[valueSize - ValuePtr->Length] |= (uint8)((bitBuf & 0x7Fu) << bitShift);
        /* if bitShift is greater than 1 it is not possible to write 7 Bit into the current byte */
        /* #70 Check if any shift operation was performed */
        if(bitShift > 0u)
        {
          /* #80 Yes, check if the value position could be incremented */
          if(ValuePtr->Length < valueSize)
          {
            /* #90 Yes, check if this is the last decoded byte and if the additional bits for the next value byte are zero */
            if (   ((bitBuf & 0x80u) == 0x00u) /* ESCAN00113014 */
                && (((bitBuf & 0x7Fu) >> (8u - bitShift)) == 0u))
            {
              /* #100 Yes, incrementing the length is not required, no additional significant value bits are present. Loop will be quit. */
            }
            else
            {
              /* #110 No, increment the value length */
              ValuePtr->Length++;
              /* #120 Check if more significant bits shall be written. */
              if (bitShift != 1u) /* ESCAN00068523 */
              {
                /* Yes, write the remaining bits to next byte. */
                ValuePtr->Value[valueSize - ValuePtr->Length] |= (uint8)((bitBuf & 0x7Fu) >> (8u - bitShift));
              }
            }
          }
          /* #130 Value byte postion cannot be incremented */
          else
          {
            /* #140 Check if this was the last byte to read */
            if ((bitBuf & 0x80u) == 0x00u)
            {
              /* #150 Yes, Loop will be quit. Do not increment length. */
            }
            else
            {
              /* #160 No, more bytes are available */
              /* #170 Maximum configured length exceeded, write error status if not already done */
              Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_INT_OVERFLOW, EXI_BS_SSC_NO_DET_CALL, 0, 0);
            }
          }
        }
        /* #180 Zero bits have been shiftet */
        else
        {
          /* #190 All bits are stored in current byte, nothing to do */
        }
        /* #200 Increment current bit positon by read value bits */
        currentBitPosition += EXI_BITS_IN_BYTE - 1u;
      }
      /* #210 8 bits could not be read from the stream */
      else
      {
        /* #220 reached the end of the stream, error status already written in Exi_VBSReadBits */
      }
      /* #230 If an error code has been set */
      if (DecWsPtr->StatusCode != EXI_E_OK)
      {
        /* #240 Stop the loop */
        break;
      }
    }

    /* #250 If the value is negative and no error did occur */
    if ((ValuePtr->IsNegative == (boolean)TRUE) && (DecWsPtr->StatusCode == EXI_E_OK))
    {
      /* #260 Add 1 to the value */
      /* Reason: Values are always shown positive in 'ValuePtr->Value'. Due to the different
       *         range of positive and negative values, 1 is added (-128 to -1 and 0 to 127)
       */
      uint16 idx = 0;
      Exi_BooleanType endLoop = Exi_BT_False;
      /* #270 Loop over the value size */
      while ((idx < valueSize) && (endLoop == Exi_BT_False)) /* ESCAN00110286 */
      {
        /* #280 If the current byte value is smaller than 0xFF */
        if (0xFFu != ValuePtr->Value[valueSize - 1u - idx])
        {
          /* #290 Increment the value by one */
          ValuePtr->Value[valueSize - 1u - idx]++;
          /* #300 End the loop */
          endLoop = Exi_BT_True;
        }
        /* #310 Current byte is 0xFF, overflow into next byte */
        else
        {
          /* #320 Set current byte to 0 */
          ValuePtr->Value[valueSize - 1u - idx] = 0x00u;
          /* #330 If this is most significant byte */
          if (idx == (ValuePtr->Length - 1u))
          {
            /* #340 Yes, check if the length can still be incrementes */
            if (ValuePtr->Length < EXI_MAX_NUM_BYTES_BIGINT) /* ESCAN00110286 */
            {
              /* #350 Yes, increment length, add 1 in the next iteration */
              ValuePtr->Length++;
            }
            else
            {
              /* #360 No, Maximum configured length exceeded, write error status if not already done */
              Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_INT_OVERFLOW, EXI_BS_SSC_NO_DET_CALL, 0, 0);
            }
          }
        }
        idx++;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}


/**********************************************************************************************************************
 *  Exi_VBSDecodeUInt()
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
 */
FUNC(void, EXI_CODE) Exi_VBSDecodeUInt(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(Exi_BitBufType, AUTOMATIC, EXI_APPL_VAR) ValuePtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  uint32 bitBuf = 0;
  uint8 currentBitPosition = 0;

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
    /* The most significant bit of each value byte does contain the information if there are more bytes to read. So
     * each byte does only contain 7 value bits. The 7 least significant bits are encoded to the first byte.
     * The value 128 does require two bytes to encode it
     * First byte:  0b10000000 -> value: 0 but one more byte to read
     * Second byte: 0b00000001 -> value: 1 no more byte to read
     * The maximum value size is 32 bit, so there will be read 5 bytes maximum. The last byte has only 4 valuable bits.
     */
    *ValuePtr = 0;

    /* #20 loop as long as most significant bit is set */
    do
    {
      /* #30 Read 8 bits from the stream, if successfull */
      if (Exi_VBSReadBits(DecWsPtr, &bitBuf, EXI_BITS_IN_BYTE) == EXI_BITS_IN_BYTE)
      {
        /* #40 If bits are set outside of the 32 bit range or an additional byte has been encoded */
        if ((currentBitPosition == 28u) && ((bitBuf & 0xF0u) != 0u))
        {
          /* #50 More than 32 bits have been encoded, set maximum possible value */
          *ValuePtr = EXI_UINT32_MAX_NUM;
          /* #60 Set over flow status code */
          Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_INT_OVERFLOW, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
        /* #70 All set bits are inside the allowed range */
        else
        {
          /* #80 Store read bists to the provided buffer */
          *ValuePtr |= (bitBuf & 0x7Fu) << currentBitPosition;
        }

        /* #90 Increment bit position */
        currentBitPosition += 7u;
      }
      /* #100 8 bits could not be read from the stream */
      else
      {
        /* #110 reached the end of the stream, error status already written in Exi_VBSReadBits */
      }
      /* #120 If an error code has been set */
      if (DecWsPtr->StatusCode != EXI_E_OK)
      {
        /* #130 Stop the loop */
        break;
      }
    } while ((bitBuf & 0x80u) == 0x80u);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}


/**********************************************************************************************************************
 *  Exi_VBSDecodeUInt8()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, EXI_CODE) Exi_VBSDecodeUInt8(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR) ValuePtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BitBufType bitBuf = 0;

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
    /* UInt8 values are represented as a 8-bit unsigned integer value */
    /* #20 Read 8 bit value from stream */
    Exi_VBSDecodeUIntN(DecWsPtr, &bitBuf, 8);
    *ValuePtr = (uint8)bitBuf;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}

/**********************************************************************************************************************
 *  Exi_VBSDecodeUInt16()
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
FUNC(void, EXI_CODE) Exi_VBSDecodeUInt16(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(uint16, AUTOMATIC, EXI_APPL_VAR) ValuePtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BitBufType bitBuf = 0;

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
    /* #20 Read value from stream */
    Exi_VBSDecodeUInt(DecWsPtr, &bitBuf);
    /* #30 If value is inside 16 bit range */
    if (bitBuf <= EXI_UINT16_MAX_NUM)
    {
      /* #40 Set value to the out buffer */
      *ValuePtr = (uint16)bitBuf;
    }
    /* #50 value is out of range */
    else
    {
      /* #60 Set maximum possible value */
      *ValuePtr = EXI_UINT16_MAX_NUM;
      /* #70 Set over flow status code */
      Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_INT_OVERFLOW, EXI_BS_SSC_NO_DET_CALL, 0, 0);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}

/**********************************************************************************************************************
 *  Exi_VBSDecodeUInt32()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, EXI_CODE) Exi_VBSDecodeUInt32(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(uint32, AUTOMATIC, EXI_APPL_VAR) ValuePtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

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
    /* #20 Read value from stream, all required check to read an uint32 are inside the called API */
    Exi_VBSDecodeUInt(DecWsPtr, (Exi_BitBufType*)ValuePtr);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}

/**********************************************************************************************************************
 *  Exi_VBSDecodeUInt64()
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
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_VBSDecodeUInt64(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(Exi_UInt64, AUTOMATIC, EXI_APPL_VAR) ValuePtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  uint32 bitBuf = 0;
  uint8 currentBitPosition;

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
    /* The most significant bit of each value byte does contain the information if there are more bytes to read. So
     * each byte does only contain 7 value bits. The 7 least significant bits are encoded to the first byte.
     * The value 128 does require two bytes to encode it
     * First byte:  0b10000000 -> value: 0 but one more byte to read
     * Second byte: 0b00000001 -> value: 1 no more byte to read
     * The maximum value size is 64 bit, so there will be read 10 bytes maximum. The last byte has only 1 valuable bit.
     */
    currentBitPosition = 0;
#if defined(Exi_UInt64_Available)
    /* #20 If UInt64 datatype is available in this platform */
    {
      *ValuePtr = 0;

      /* #30 loop as long as most significant bit is set */
      do
      {
        /* #40 Read 8 bits from the stream, if successfull */
        if (Exi_VBSReadBits(DecWsPtr, &bitBuf, EXI_BITS_IN_BYTE) == EXI_BITS_IN_BYTE)
        {
          /* #50 If bits are set outside of the 64 bit range or an additional byte has been encoded */
          if ((currentBitPosition == 63u) && ((bitBuf & 0xFEu) != 0u))
          {
            /* #60 More than 64 bits have been encoded, set maximum possible value */
            *ValuePtr = EXI_UINT64_MAX_NUM;
            /* #70 Set over flow status code */
            Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_INT_OVERFLOW, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          }
          /* #80 All set bits are inside the allowed range */
          else
          {
            /* #90 Store read bists to the provided buffer */
            *ValuePtr |= (((Exi_UInt64)bitBuf & 0x7Fu)) << currentBitPosition;
          }

          /* #100 Increment bit position */
          currentBitPosition += 7u;
        }
        /* #110 8 bits could not be read from the stream */
        else
        {
          /* #120 reached the end of the stream, error status already written in Exi_VBSReadBits */
        }
        /* #130 If an error code has been set */
        if (DecWsPtr->StatusCode != EXI_E_OK)
        {
          /* #140 Stop the loop */
          break;
        }
      } while ((bitBuf & 0x80u) == 0x80u);
    }
#else
    /* #150 If UInt64 datatype is not available in this platform */
    {
      (*ValuePtr).HiWord = 0;
      (*ValuePtr).LoWord = 0;

      /* #160 loop as long as most significant bit is set */
      do
      {
        /* #170 Read 8 bits from the stream, if successfull */
        if (Exi_VBSReadBits(DecWsPtr, &bitBuf, EXI_BITS_IN_BYTE) == EXI_BITS_IN_BYTE)
        {
          /* #180 If bits are set outside of the 64 bit range or an additional byte has been encoded */
          if ((currentBitPosition == 63u) && ((bitBuf & 0xFEu) != 0u))
          {
            /* #190 More than 64 bits have been encoded, set maximum possible value */
            (*ValuePtr).HiWord = EXI_UINT32_MAX_NUM;
            (*ValuePtr).LoWord = EXI_UINT32_MAX_NUM;
            /* #200 Set over flow status code */
            Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_INT_OVERFLOW, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          }
          /* #210 All set bits are inside the allowed range */
          /* #220 If inside low word */
          else if (currentBitPosition < 28u)
          {
            /* #230 Write read bits to low word */
            (*ValuePtr).LoWord |= (uint32)((bitBuf & 0x7Fu) << currentBitPosition);
          }
          /* #240 If at low-high word boundary */
          else if (currentBitPosition == 28u)
          {
            /* #250 Write 4 least significant bits to the low words most significant bits */
            (*ValuePtr).LoWord |= (uint32)((bitBuf & 0x0Fu) << currentBitPosition);
            /* #260 Write 4 most significant bits to the high words least significant bits */
            (*ValuePtr).HiWord |= (uint32)((bitBuf & 0x70u) >> 4u);
          }
          /* #270 Inside high word */
          else
          {
            /* #280 Write read bits into high word */
            (*ValuePtr).HiWord |= (uint32)((bitBuf & 0x7Fu) << (currentBitPosition - 32u));
          }
          /* #290 Increment bit position */
          currentBitPosition += 7u;
        }
        /* #300 8 bits could not be read from the stream */
        else
        {
          /* #310 reached the end of the stream, error status already written in Exi_VBSReadBits */
        }
        /* #320 If an error code has been set */
        if (DecWsPtr->StatusCode != EXI_E_OK)
        {
          /* #330 Stop the loop */
          break;
        }
      } while ((bitBuf & 0x80u) == 0x80u);
    }
#endif
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
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
 *  Exi_VBSDecodeUIntN()
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
FUNC(void, EXI_CODE) Exi_VBSDecodeUIntN(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(Exi_BitBufType, AUTOMATIC, EXI_APPL_VAR) BitBufPtr,
  uint8 BitCount)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
#if ( EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (BitBufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (BitCount > (sizeof(Exi_BitBufType) * 8u))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
#endif /* (EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Read N bits from the stream, if failed */
    if ((Exi_VBSReadBits(DecWsPtr, BitBufPtr, BitCount) == 0u)
      && (DecWsPtr->StatusCode != EXI_E_OK))
    {
      /* #30 Error occured, provoke error detection of higher layers by setting the maximum possible return value.
       *     In that case EventCode check will end in a schema deviation or will detect an invalid event.
       *     StatusCode has already been set.
       */
      *BitBufPtr = 0xFFFFFFFFu;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}

/* === 7.1.10 STRING === */

/**********************************************************************************************************************
 *  Exi_VBSDecodeStringOnly()
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
 */
/* PRQA S 6010 1 */ /* MD_MSR_STPTH */
FUNC(void, EXI_CODE) Exi_VBSDecodeStringOnly(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR) StrBufPtr,
  P2VAR(uint16, AUTOMATIC, EXI_APPL_VAR) StrBufLenPtr,
  uint16 StrLen,
  Exi_BooleanType MaxLengthRestricted)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BitBufType bitBuf = 0;
  uint16 copyStrLen;
  uint16 idx;

  /* #10 Check plausibility of input parameters */
#if ( EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (StrBufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (StrBufLenPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
#endif /* (EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Check if the given string is bigger than the provided buffer */
    if (StrLen > (*StrBufLenPtr))
    {
      /* #30 Check if the maximum length is restricted */
      if (MaxLengthRestricted == Exi_BT_True)
      {
        copyStrLen = 0;
        /* #40 Throw an overflow error */
        Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_ARR_OVERFLOW, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
      /* #50 Otherwise */
      else
      {
        /* #60 Set the copy length to the buffer size */
        copyStrLen = (*StrBufLenPtr);
      }
    }
    /* #70 Otherwise */
    else
    {
      /* #80 Complete string fits into the buffer, set copy length to string length */
      copyStrLen = StrLen;
    }

    /* #90 Loop over all characters of the string */
    for (idx = 0; idx < copyStrLen; idx++)
    {
      /* #100 Read and store each character of the string */
      Exi_VBSDecodeUIntN(DecWsPtr, &bitBuf, EXI_BITS_IN_BYTE);
      StrBufPtr[idx] = (uint8)bitBuf;
    }

    Exi_VBSDecodeTruncateRemainder(DecWsPtr, StrLen, copyStrLen);

    /* #110 If string is smaller than buffer */
    if (StrLen < (*StrBufLenPtr))
    {
      /* #120 Optionally add null-termination to the string, so that e.g. IpBase_StrCpyMaxLen() can be used */
      StrBufPtr[StrLen] = 0;                                                                                            /* PRQA S 2842 */ /* MD_Exi_BufferLengthChecked */
    }

    /* #130 Set string length to the out buffer length pointer */
    *StrBufLenPtr = copyStrLen;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}

/**********************************************************************************************************************
 *  Exi_VBSDecodeString()
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
FUNC(void, EXI_CODE) Exi_VBSDecodeString(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR) StrBufPtr,
  P2VAR(uint16, AUTOMATIC, EXI_APPL_VAR) StrBufLenPtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BitBufType bitBuf = 0;

  /* #10 Check plausibility of input parameters */
#if ( EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (StrBufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (StrBufLenPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
#endif /* (EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Read string length from the stream */
    Exi_VBSDecodeUInt(DecWsPtr, &bitBuf);
    /* #30 If successfull */
    if (DecWsPtr->StatusCode == EXI_E_OK)
    {
      /* #40 Read string bytes */
      Exi_VBSDecodeStringOnly(DecWsPtr, StrBufPtr, StrBufLenPtr, (uint16)bitBuf, Exi_BT_False);
    }
    /* #50 Failed */
    else
    {
      /* #60 If Status code was set to OVERFLOW */
      if (DecWsPtr->StatusCode == EXI_E_INT_OVERFLOW)
      {
        /* #70 String length could not be read, skip of unread bytes is not possible */
        DecWsPtr->StatusCode = EXI_E_NOT_OK;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}

/**********************************************************************************************************************
 *  Exi_VBSDecodeStringValue()
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
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_VBSDecodeStringValue(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR) StrBufPtr,
  P2VAR(uint16, AUTOMATIC, EXI_APPL_VAR) StrBufLenPtr,
  Exi_BooleanType MaxLengthRestricted)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BitBufType bitBuf = 0;

  /* #10 Check plausibility of input parameters */
#if ( EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (StrBufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (StrBufLenPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
#endif /* (EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Read string information element from stream */
    /* String information element has the following values:
     * - 0: String is contained in the local string table
     * - 1: String is contained in the global string table
     * - >1: String is contained in the stream length is 'information - 2'
     * This decoder does not support any string tables, only direct encoding is supported.
     */
    Exi_VBSDecodeUInt(DecWsPtr, &bitBuf);

    /* #30 If successfull */
    if (DecWsPtr->StatusCode == EXI_E_OK)
    {
      /* #40 If string is stored in local string table */
      if (bitBuf == 0u)
      {
        /* #50 Not supported set error to status code */
        DecWsPtr->StatusCode = EXI_E_STRING_TABLE_LOCAL_HIT;
      }
      /* #60 If string is stored in global string table */
      else if (bitBuf == 1u)
      {
        /* #70 Not supported set error to status code */
        DecWsPtr->StatusCode = EXI_E_STRING_TABLE_GLOBAL_HIT;
      }
      /* #80 String is stored in the stream */
      else
      {
        /* #90 Subtract 2 from string to get the string length */
        bitBuf -= 2u;
        /* #100 Read string from stream */
        Exi_VBSDecodeStringOnly(DecWsPtr, StrBufPtr, StrBufLenPtr, (uint16)bitBuf, MaxLengthRestricted);
      }
    }
    /* #110 Failed */
    else
    {
      /* #120 If Status code was set to OVERFLOW */
      if (EXI_E_INT_OVERFLOW == DecWsPtr->StatusCode)
      {
        /* #130 String length could not be read, skip of unread bytes is not possible */
        DecWsPtr->StatusCode = EXI_E_NOT_OK;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}

/**********************************************************************************************************************
 *  Exi_VBSDecodeQName()
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
 */
FUNC(void, EXI_CODE) Exi_VBSDecodeQName(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(uint8, AUTOMATIC, EXI_APPL_VAR) StrBufPtr,
  P2VAR(uint16, AUTOMATIC, EXI_APPL_VAR) StrBufLenPtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BitBufType bitBuf = 0;

  /* #10 Check plausibility of input parameters */
#if ( EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (StrBufPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (StrBufLenPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
#endif /* (EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Read string information from stream */
    Exi_VBSDecodeUInt(DecWsPtr, &bitBuf);

    /* #30 If successfull */
    if (DecWsPtr->StatusCode == EXI_E_OK)
    {
      /* #40 If string is stored in local string table */
      if (bitBuf == 0u)
      {

        /* #50 Not supported set error to status code */
        DecWsPtr->StatusCode = EXI_E_STRING_TABLE_LOCAL_HIT;
      }
      /* #60 String is stored in the stream */
      else
      {
        /* #70 Subtract 1 from string to get the string length */
        bitBuf -= 1u;
        /* #80 Read string from stream */
        Exi_VBSDecodeStringOnly(DecWsPtr, StrBufPtr, StrBufLenPtr, (uint16)bitBuf, Exi_BT_False);
      }
    }
    /* #90 Failed */
    else
    {
      /* #100 If Status code was set to OVERFLOW */
      if (DecWsPtr->StatusCode == EXI_E_INT_OVERFLOW)
      {
        /* #110 String length could not be read, skip of unread bytes is not possible */
        DecWsPtr->StatusCode = EXI_E_NOT_OK;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */
}

/* === 7.1.11 LIST === */


/**********************************************************************************************************************
 *  Exi_VBSDecodeCheckSchemaDeviation()
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
/* PRQA S 6060 1 */ /* MD_MSR_STPAR */
FUNC(void, EXI_CODE) Exi_VBSDecodeCheckSchemaDeviation(
  P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(Exi_BitBufType, AUTOMATIC, EXI_APPL_VAR) ExiEventCodePtr,
  Exi_BitBufType SchemaDeviationEventCode,
  uint8 EventCodeBitSize,
  Exi_BooleanType StartElement,
  Exi_BooleanType OptionalElement,
  Exi_BooleanType SubstitutionElement,
  Exi_BooleanType AttributesAllowed,
  Exi_BooleanType OptionalElementatEE,
  uint8 KnownAttributesNum,
  uint16 SchemaSetId,
  uint16 ElementIdentifier)
{
  /* #10 Check if this event code is a schema deviation */
  if (*ExiEventCodePtr == SchemaDeviationEventCode)
  {
    /* #20 Decode schema deviation */
    Exi_VBSDecodeSchemaDeviation(
      DecWsPtr,
      ExiEventCodePtr,
      SchemaDeviationEventCode,
      EventCodeBitSize,
      StartElement,
      OptionalElement,
      SubstitutionElement,
      AttributesAllowed,
      OptionalElementatEE,
      KnownAttributesNum,
      SchemaSetId);

    /* 30 set DeviationOccur */
    if (DecWsPtr->DecWs.DeviationWs.DeviationOccur == Exi_BT_False)
    {
      DecWsPtr->DecWs.DeviationWs.DeviationOccur = Exi_BT_True;
    }

    /* #30 The in-out pointer ExiEventCodePtr will be set to the next none deviation elements event code */
  }
  /* #40 No schema deviation */
  else
  {
    /* #50 Normal element deconding in calling function possible */
  }
#if defined(EXI_TEST_SCHEMA_DEVIATION_CALLOUT)
  EXI_TEST_SCHEMA_DEVIATION_CALLOUT(
    ExiEventCodePtr,
    (uint32)SchemaDeviationEventCode,
    SchemaSetId,
    ElementIdentifier);
#else
  EXI_DUMMY_STATEMENT_CONST(ElementIdentifier);                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif
}

/**********************************************************************************************************************
 *  Exi_VBSDecodeSchemaDeviation()
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
 */
/* PRQA S 6010, 6030, 6060, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_VBSDecodeSchemaDeviation(
  P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  P2VAR(Exi_BitBufType, AUTOMATIC, EXI_APPL_VAR) ExiEventCodePtr,
  Exi_BitBufType SchemaDeviationEventCode,
  uint8 EventCodeBitSize,
  Exi_BooleanType StartElement,
  Exi_BooleanType OptionalElement,
  Exi_BooleanType SubstitutionOrMultiOccurenceBufferElement,
  Exi_BooleanType AttributesAllowed,
  Exi_BooleanType OptionalElementatEE,
  uint8 KnownAttributesNum,
  uint16 SchemaSetId)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_BSDecoder_SchemaDeviationType readElement = EXI_BSDSD_NOT_SET;                                                    /* PRQA S 2981 */ /* MD_Exi_RedundantInitialization */
  uint8 dummyString = 0;
  uint16 dummyStringLen = 0;
  Exi_BooleanType thisAttributesAllowed = AttributesAllowed;
  uint8 maxPossibleEventCode = 1;


  /*
            This is a use case for element with complete grammar:
            "Color" and "sku" are examples for schema-informed attributes
            After a schema informed attribute event code is detected, this use case is providing the maximum possible
            event codes to be expected(AttributesAllowed = Exi_BT_True , AfterAttribute = Exi_BT_True).

                Terminals                                     Event code

                AT("color")[schema-typed value] Use_color     0     -> Use case: May differ according to StartElement,
                AT("sku")[schema-typed value] Use_sku 1       1        OptionalElement, AttributesAllowed, AfterAttribute.
                                                                    -> If use case changes, next event codes are also expected to change(reducing possible terminals/expected event codes)
                ---------------------------------------------------------------------
                EE                                            2.0   -> supported
                AT(xsi:type) Use_color 0                      2.1
                AT(xsi:nil) Use_color 0                       2.2
                AT(*) Use_color 0                             2.3
                AT("color")[untyped value] Use_color1         2.4.0 -> supported
                AT("sku")[untyped value] Use_sku1             2.4.1 -> supported
                AT(*)[untyped value] Use_color 0              2.4.2
                SE(*) Use_sku 1_copied                        2.5   -> supported
                CH[untyped value] Use_sku 1_copied            2.6   -> supported

  */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  EXI_DUMMY_STATEMENT_CONST(KnownAttributesNum);                                                                        /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  /* #10 Loop as long event code is set to schema deviation or an error does occur */
  while ((*ExiEventCodePtr == SchemaDeviationEventCode) && (DecWsPtr->DecWs.StatusCode == EXI_E_OK))
  {
    /* handle schema daviations */
    *ExiEventCodePtr = 0;
    /* #20 Get the element type that shall be decoded and shall be skipped(start element tag (SE) or character information (CH)) */
    if (StartElement == Exi_BT_True)
    {
      /* #30 attributes are allowed */
      if (thisAttributesAllowed == Exi_BT_True)
      {
        /* #40 Max event code calculation */
        maxPossibleEventCode = maxPossibleEventCode + 2u;
        if (OptionalElement == Exi_BT_False)
        {
          maxPossibleEventCode = maxPossibleEventCode + 1u;
        }
        if (KnownAttributesNum == 0u)
        {
          maxPossibleEventCode = maxPossibleEventCode + 2u;
        }

        /* #50 Disallow attributes for further loops */
        thisAttributesAllowed = Exi_BT_False;
        /* #60 Read event code */
        /* Schema deviation could be EE, AT(xsi:type), AT(xsi:nil), AT(*), AT(QName), AT(*)[untyped value] SE(*) or CH[untyped value] */
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, ExiEventCodePtr, Exi_VBSDecodeCalculateBitSize(maxPossibleEventCode));
        /* Only SE(*) and CH[untyped value] accepted/skipped */
        /* #70 If this is a start element tag (SE) */
        switch (*ExiEventCodePtr)
        {
        case 2:
          /* #80 read start position choice/optional element start position obligatory after optional attribute event code */
          readElement = EXI_BSDSD_GENERIC_ELEMENT;
          break;
        case 3:
          /* #90 read start position choice/optional element after attribute or start position obligatory after optional attribute event code */
          if (OptionalElement == Exi_BT_True)
          {
            readElement = EXI_BSDSD_STRING_VALUE;
          }
          else
          {
            readElement = EXI_BSDSD_GENERIC_ELEMENT;
          }
          break;
        case 4:
          /* #100 read start position optional element */
          if (KnownAttributesNum == 0u)
          {
            readElement = EXI_BSDSD_GENERIC_ELEMENT;
          }
          else
          {
            readElement = EXI_BSDSD_STRING_VALUE;
          }
          break;
        case 5:
          /* #110 read start position */
          if (   (OptionalElement == Exi_BT_True) 
		      && (    (SubstitutionOrMultiOccurenceBufferElement == Exi_BT_True) 
			       || (OptionalElementatEE == Exi_BT_True) ) )
          {
            readElement = EXI_BSDSD_STRING_VALUE;
          }
          else
          {
            readElement = EXI_BSDSD_GENERIC_ELEMENT;
          }
          break;
        case 6:
          /* #120 String value element has to be skipped */
          readElement = EXI_BSDSD_STRING_VALUE;
          break;
        default:
          /* #130 Unsupported element, if no error has been set */
          if (DecWsPtr->DecWs.StatusCode == EXI_E_OK)
          {
            DecWsPtr->DecWs.StatusCode = EXI_E_INV_EVENT_CODE;
          }
          else /* should not be hit, required by MISRA */
          {
            /* nothing to do, error already set */
          }
          break;
        }
      }
      /* #140 Attributes are not allowed */
      else
      {
        /* #150 Read element with MinOccurs = 0 event code(can be EE(0,0) or EE(0), SE(*) or CH[untyped value])*/
        if (OptionalElement == Exi_BT_True)
        {
          /* #160 Read maxOccur = 0 element event code */
          if (OptionalElementatEE == Exi_BT_True)
          {
            /* #170 Read EE of  optional element event code */
            Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, ExiEventCodePtr, 1);
          }
          else if (SubstitutionOrMultiOccurenceBufferElement == Exi_BT_True)
          {
            /* #180 Read substitution element event code */
            Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, ExiEventCodePtr, 1);
          }
          else
          {
            /* #190 Read optional element event code */
            Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, ExiEventCodePtr, 2);
          }
        }
        /* #200 Element is mandatory */
        else
        {
          /* #210 Read mandatory element event code */
          Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, ExiEventCodePtr, 2);
        }

        /* #220 Switch event Code: SE(*) and CH[untyped value] accepted/skipped */
        switch (*ExiEventCodePtr)
        {
        case 0:
          /* #230 Generic element has to be skipped */
          readElement = EXI_BSDSD_GENERIC_ELEMENT;
          break;
        case 1:
          /* #240 Skip elements */
          if (   (OptionalElement == Exi_BT_False) 
              || (   (OptionalElement == Exi_BT_True) 
                  && (OptionalElementatEE == Exi_BT_False)
                  && (SubstitutionOrMultiOccurenceBufferElement == Exi_BT_False) ) )
          {
            /* #250 Generic element has to be skipped */
            readElement = EXI_BSDSD_GENERIC_ELEMENT;
          }
          else
          {
            /* #260 String value element has to be skipped */
            readElement = EXI_BSDSD_STRING_VALUE;
          }
          break;
        case 2:
          /* #270 String value element has to be skipped */
          readElement = EXI_BSDSD_STRING_VALUE;
          break;
        default:
          /* #280 Unsupported element, if no error has been set */
          if (DecWsPtr->DecWs.StatusCode == EXI_E_OK)
          {
            DecWsPtr->DecWs.StatusCode = EXI_E_INV_EVENT_CODE;
          }
          else /* should not be hit, required by MISRA */
          {
            /* nothing to do, error already set */
          }
          break;
        }
      }
    }
    /* #290 End element (EE) is expected */
    else
    {
      /* #300 Read event code(can be SE(*) or CH[untyped value])*/
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, ExiEventCodePtr, 1);
      /* #310 Switch event Code */
      switch (*ExiEventCodePtr)
      {
      case 0:
        /* #320 Generic element has to be skipped(SE) */
        readElement = EXI_BSDSD_GENERIC_ELEMENT;
        break;
      case 1:
        /* #330 String value element has to be skipped(CH) */
        readElement = EXI_BSDSD_STRING_VALUE;
        break;
      default:
        /* #340 Unsupported element, if no error has been set */
        if (DecWsPtr->DecWs.StatusCode == EXI_E_OK)
        {
          /* #350 Set status code to error */
          DecWsPtr->DecWs.StatusCode = EXI_E_INV_EVENT_CODE;
        }
        else /* should not be hit, required by MISRA */
        {
          /* nothing to do, error already set */
        }
        break;
      }
    }
    /* #360 If element type could be retrieved */
    if (DecWsPtr->DecWs.StatusCode == EXI_E_OK)
    {
      /* #370 Switch element type */
      switch (readElement)
      {
      case EXI_BSDSD_GENERIC_ELEMENT:
        /* #380 Generic element decode */
        (void)Exi_VBSDecodeGenericElement(DecWsPtr, SchemaSetId, Exi_BT_False);
        break;
      case EXI_BSDSD_STRING_VALUE:
        /* #390 String value decode */
        Exi_VBSDecodeStringValue(&DecWsPtr->DecWs, &dummyString, &dummyStringLen, Exi_BT_False);
        break;
      default: /* EXI_BSDSD_NOT_SET */
        /* #400 Error type has not been set */
          /* #410 Set status code to error */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        break;
      }
    }
    /* #420 If element could be skipped */
    if (DecWsPtr->DecWs.StatusCode == EXI_E_OK)
    {
      /* #430 Read event code for next loop */
      *ExiEventCodePtr = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, ExiEventCodePtr, EventCodeBitSize);
    }
  }
}

/**********************************************************************************************************************
 *  Exi_VBSDecodeGenericElement()
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
 */
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(void*, EXI_CODE) Exi_VBSDecodeGenericElement(
  P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  uint16 SchemaSetId,
  Exi_BooleanType SkipElement)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  uint8 dummyString = 0;
  uint16 dummyStringLen = 0;
  Exi_BitBufType exiEventCode = 0;
  Exi_GenericElementType* genElementPtr = NULL_PTR;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 If element shall be skipped */
  if(SkipElement == Exi_BT_False)
  {
    /* #20 Get and initialize generic element from storage buffer */
    genElementPtr = (Exi_GenericElementType*) Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(*genElementPtr), Exi_BT_True); /* PRQA S 0316 */ /*  MD_Exi_PointerConversion */
    if (genElementPtr != NULL_PTR)
    {
      genElementPtr->ContentType = EXI_SCHEMA_UNKNOWN_ELEMENT_TYPE;
      genElementPtr->QNameType = EXI_SCHEMA_UNKNOWN_ELEMENT_TYPE;
    }
  }

  /* #30 If schema set ID is known */
  if(SchemaSetId < EXI_UNKNOWN_SCHEMA_SET_TYPE)
  {
    /* #40 Read URI event code */
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, Exi_VBSDecodeCalculateBitSize(Exi_UriPartitionSize[SchemaSetId]));
    /* #50 If URI is not included */
    if(exiEventCode == 0u)
    {
      /* #60 If no error did occur */
      if(DecWsPtr->DecWs.StatusCode == EXI_E_OK)
      {
        /* #70 Decode uri name */
        Exi_VBSDecodeString(&DecWsPtr->DecWs, &dummyString, &dummyStringLen);
        /* #80 Decode local name */
        /* #90 Not supported, set status code to error */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #100 URI is included */
    else
    {
      /* URI hit, URI index is EXI Event -1 */
      /* uint8 uriIndex = (uint8)(exiEventCode - 1); */
      /* #110 Decode local name */
      /* #120 If element skipped is allowed */
      if(SkipElement == Exi_BT_True)
      {
        /* #130 Decode with a dummy buffer of length 0 to skip the complete string */
        Exi_VBSDecodeQName(&DecWsPtr->DecWs, &dummyString, &dummyStringLen);
      }
      /* #140 Element will not be skipped */
      else
      {
        /* #150 Allocate buffer and decode QName element */
        Exi_GenericStringType* QNamePtr;
        QNamePtr = (Exi_GenericStringType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(*QNamePtr), Exi_BT_True); /* PRQA S 0316 */ /*  MD_Exi_PointerConversion */
        /* #160 If buffer allocation was successful */
        if (QNamePtr != NULL_PTR)
        {
          Exi_VBSDecodeQName(&DecWsPtr->DecWs, &QNamePtr->Buffer[0], &QNamePtr->Length);
          /* #170 If successful */
          if ((DecWsPtr->DecWs.StatusCode == EXI_E_OK) && (genElementPtr != NULL_PTR))
          {
            /* #180 Set generic element type */
            genElementPtr->QNameType = EXI_SCHEMA_GENERIC_STRING_TYPE;
            genElementPtr->GenericQName = QNamePtr;                                                                     /* PRQA S 0315 */  /* MD_Exi_ImplicitPointerConversion */
          }
        }
        /* #190 Otherwise */
        else
        {
          /* #200 Set return value to NULL, StatusCode is already set to error */
          genElementPtr = NULL_PTR;
        }
      }
      /* #210 If string was located in the local string table */
      if (EXI_E_STRING_TABLE_LOCAL_HIT == DecWsPtr->DecWs.StatusCode)
      {
        /* Dervive type from URI and local name information and decode */
        /* uriIndex = uriIndex; */ /* avoid compiler warning */
        /* #220 Stringtables are currently not supported, set status code to error */
        /* not supported */
        DecWsPtr->DecWs.StatusCode = EXI_E_INV_EVENT_CODE;
      }
      /* #230 If string was locaed in the stream and no error did occur */
      else if (DecWsPtr->DecWs.StatusCode == EXI_E_OK)
      {
        /* #240 Read generic element content from the stream */
        Exi_VBSDecodeGenericElementContent(DecWsPtr, SchemaSetId, SkipElement, genElementPtr);
      }
      else /* Else is required by MISRA */
      {
        /* error already detected in an earlier step -> nothing to do */
      }
    }
  }
  /* #250 Schema set is unknown */
  else
  {
    /* #260 Set status code to error */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_NOT_OK, EXI_BS_SSC_NO_DET_CALL, 0, 0);
  }

  return (void*)genElementPtr;                                                                                          /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
}

/**********************************************************************************************************************
 *  Exi_VBSDecodeGenericElementContent()
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
 */
/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_VBSDecodeGenericElementContent(
  P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  uint16 SchemaSetId,
  Exi_BooleanType SkipContent,
  Exi_GenericElementType* GenericElementPtr)
{

  uint8 dummyString = 0;
  uint16 dummyStringLen = 0;
  Exi_BitBufType exiEventCode = 0;
  Exi_BooleanType continueProcessingStream = Exi_BT_True;

  /* Simple Deviations Content:
  *                EE                      0
  *                SE(*)  ElementContent   1.0
  *                CH  ElementContent      1.1
  */

  /* Complex Deviations Content: ChildContentItems(n.m) :
   *               SE(*) ElementContent    n.m
   *               CH ElementContent       n.(m + 1)
   *               ER ElementContent       n.(m + 2)
   *               CM ElementContent       n.(m + 3).0
   *               PI ElementContent       n.(m + 3).1
   */

   /* check if complex element has more than one element, if yes read end prefix bits and exit */
  if ((DecWsPtr->DecWs.DeviationWs.ComplexGenericElementsCount > 1u) && (DecWsPtr->DecWs.DeviationWs.ElementIndexRequired == Exi_BT_True))
  {
    /* Read n, m bits  */
    /* #10 Decode element position in complex type */
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, Exi_VBSDecodeCalculateBitSize((uint8)(DecWsPtr->DecWs.DeviationWs.ComplexGenericElementsCount)));
    DecWsPtr->DecWs.DeviationWs.ElementIndexRequired = Exi_BT_False;

    /* #20 If EE event code of complex deviation */
    if (exiEventCode == (DecWsPtr->DecWs.DeviationWs.ComplexGenericElementsCount - 1u))
    {
      /* #30 Element finished */
      /* Re-Initialize Deviation workspace parameters */
      DecWsPtr->DecWs.DeviationWs.ComplexGenericElementsCount = 0;
      continueProcessingStream = Exi_BT_False;
    }
  }

  /* If attributes, read string value and exit */
  else if (DecWsPtr->DecWs.DeviationWs.IsAttribute == Exi_BT_True)
  {
    /* #40 Allocate buffer for element */
    Exi_GenericStringType* attributeStringPtr;
    attributeStringPtr = (Exi_GenericStringType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(*attributeStringPtr), Exi_BT_True); /* PRQA S 0316 */ /*  MD_Exi_PointerConversion */

    DecWsPtr->DecWs.DeviationWs.IsAttribute = Exi_BT_False;
    /* #50 If successfull */
    if (attributeStringPtr != NULL_PTR)
    {
      /* #60 Decode string */
      attributeStringPtr->Length = sizeof(attributeStringPtr->Buffer);
      Exi_VBSDecodeStringValue(&DecWsPtr->DecWs, &attributeStringPtr->Buffer[0], &attributeStringPtr->Length, Exi_BT_False);
      /* #70 If successfull */
      if ( (DecWsPtr->DecWs.StatusCode == EXI_E_OK) && (GenericElementPtr != NULL_PTR) )
      {
        /* #80 Set element information */
        GenericElementPtr->ContentType = EXI_SCHEMA_GENERIC_STRING_TYPE;
        GenericElementPtr->GenericContent = attributeStringPtr;                                                         /* PRQA S 0315, 2916 */  /* MD_Exi_ImplicitPointerConversion, MD_Exi_PointerLifeTime */
      }
    }

    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    if (DecWsPtr->DecWs.StatusCode == EXI_E_OK)
    {
      /* #90 Read generic element content from the stream */
      Exi_VBSDecodeGenericElementContent(DecWsPtr, SchemaSetId, SkipContent, GenericElementPtr);                        /* PRQA S 3670 */  /* MD_Exi_16.2 */
    }
    else /* Else is required by MISRA */
    {
      /* error already detected in an earlier step -> nothing to do */
    }
    continueProcessingStream = Exi_BT_False;
  }

  else
  {
    /* Read 1 bit */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);

    /* If end element, exit */
    /* ElementContent  EE 0 */
    if ((exiEventCode == 0u) && (DecWsPtr->DecWs.DeviationWs.ElementContentEERequired == Exi_BT_True))
    {
      /* #100 Element finished, nothing to do */
      DecWsPtr->DecWs.DeviationWs.ElementContentEERequired = Exi_BT_False;
      continueProcessingStream = Exi_BT_False;
    }
  }

  if (continueProcessingStream == Exi_BT_True)
  {
    /* ElementContent : ChildContentItems 1.0 */
    if (exiEventCode >= 1u)
    {
      /* #110 Decode the second bit (0: SE(*); 1: CH[untyped value]) */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* #120 If SE(*) event code */
      if (exiEventCode == 0u)
      {
        /* #130 Decode generic element start */
        /* #140 If element shall be decoded */
        if ((SkipContent == Exi_BT_False) && (GenericElementPtr != NULL_PTR))
        {
          /* #150 Set content type and decode generic element, call will return the decoded element */
          GenericElementPtr->ContentType = EXI_SCHEMA_GENERIC_ELEMENT_TYPE;
          GenericElementPtr->GenericContent = Exi_VBSDecodeGenericElement(DecWsPtr, SchemaSetId, SkipContent);
        }
        /* #160 Element shall be skipped */
        else
        {
          /* #170 Decode generic element, call will return NULL_PTR */
          (void)Exi_VBSDecodeGenericElement(DecWsPtr, SchemaSetId, SkipContent);
        }

        /* #180 If no error did occur, decode the generic element content */
        if (DecWsPtr->DecWs.StatusCode == EXI_E_OK)
        {
          Exi_GenericElementType* nextElementPtr = (Exi_GenericElementType*)NULL_PTR;
          /* #190 If element shall be decoded */
          if (SkipContent == Exi_BT_False)
          {
            /* #200 Get the buffer that will be allocated in Exi_VBSDecodeGenericElementContent and pre initialize it for later evaluation */
            /* do not increment StorageOffset here because this element will be allocated again in
            Exi_VBSDecodeGenericElement if required. Then nextElementPtr == GenericElementPtr */
            nextElementPtr = (Exi_GenericElementType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(*nextElementPtr), Exi_BT_False); /* PRQA S 0316 */ /*  MD_Exi_PointerConversion */
            /* #210 If buffer could be allocated */
            if (nextElementPtr != NULL_PTR)
            {
              nextElementPtr->ContentType = EXI_SCHEMA_UNKNOWN_ELEMENT_TYPE;
              nextElementPtr->QNameType = EXI_SCHEMA_UNKNOWN_ELEMENT_TYPE;
              /* #220 Decode the generic element content */
              DecWsPtr->DecWs.DeviationWs.ComplexGenericElementsCount += 1u;
              DecWsPtr->DecWs.DeviationWs.ElementIndexRequired = Exi_BT_True;
              Exi_VBSDecodeGenericElementContent(DecWsPtr, SchemaSetId, SkipContent, nextElementPtr);                   /* PRQA S 3670 */  /* MD_Exi_16.2 */
              /* #230 If an element has been decoded */
              if (    (    (nextElementPtr->ContentType != EXI_SCHEMA_UNKNOWN_ELEMENT_TYPE) 
                        || (nextElementPtr->QNameType != EXI_SCHEMA_UNKNOWN_ELEMENT_TYPE) ) 
                   && (GenericElementPtr != NULL_PTR) )
              {
                /* #240 Assign the decoded element to the output buffer */
                ((Exi_GenericElementType*)GenericElementPtr->GenericContent)->NextGenericElement = nextElementPtr;      /* PRQA S 0316 */ /*  MD_Exi_PointerConversion */
              }
            }
          }
          /* #250 Element shall be skipped */
          else
          {
            /* #260 Skip the generic element content */
            Exi_VBSDecodeGenericElementContent(DecWsPtr, SchemaSetId, SkipContent, nextElementPtr);                     /* PRQA S 3670 */  /* MD_Exi_16.2 */
          }
        }
      }
      /* #270 CH[untyped value] event code */
      else
      {
        /* #280 If element shall be skipped */
        if (SkipContent == Exi_BT_True)
        {
          /* #290 Skip Character information content, use dummy string with length 0 */
          Exi_VBSDecodeStringValue(&DecWsPtr->DecWs, &dummyString, &dummyStringLen, Exi_BT_False);
        }
        /* #300 Element shall not be skipped */
        else
        {
          /* #310 Allocate buffer for element */
          Exi_GenericStringType* contentStringPtr;
          contentStringPtr = (Exi_GenericStringType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(*contentStringPtr), Exi_BT_True); /* PRQA S 0316 */ /*  MD_Exi_PointerConversion */
          /* #320 If successfull */
          if (contentStringPtr != NULL_PTR)
          {
            /* #330 Decode string */
            contentStringPtr->Length = sizeof(contentStringPtr->Buffer);
            Exi_VBSDecodeStringValue(&DecWsPtr->DecWs, &contentStringPtr->Buffer[0], &contentStringPtr->Length, Exi_BT_False);
            /* #340 If successfull */
            if ( (DecWsPtr->DecWs.StatusCode == EXI_E_OK) && (GenericElementPtr != NULL_PTR) )
            {
              /* #350 Set element information */
              GenericElementPtr->ContentType = EXI_SCHEMA_GENERIC_STRING_TYPE;
              GenericElementPtr->GenericContent = contentStringPtr;                                                     /* PRQA S 0315, 2916 */  /* MD_Exi_ImplicitPointerConversion, MD_Exi_PointerLifeTime */
            }
          }
        }

        /* #360 If successfull */
        if (DecWsPtr->DecWs.StatusCode == EXI_E_OK)
        {
          /* #370 Decode element content */

          DecWsPtr->DecWs.DeviationWs.ElementContentEERequired = Exi_BT_True;
          Exi_VBSDecodeGenericElementContent(DecWsPtr, SchemaSetId, SkipContent, GenericElementPtr);                    /* PRQA S 3670 */  /*  MD_Exi_16.2 */
        }
        /* #380 Previous processing did fail */
        else
        {
          /* #390 If error status is not EXI_E_BUFFER_SIZE */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_BUFFER_SIZE)
          {
            /* #400 Set status code to invalid event code */
            DecWsPtr->DecWs.StatusCode = EXI_E_INV_EVENT_CODE;
          }
        }
      }
    }


    /* check StartTagContent(EE or AT) */
    else
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);


      /* AT(*) StartTagContent 0.1 */
      if ((exiEventCode == 1u) && (DecWsPtr->DecWs.DeviationWs.IsAttribute == Exi_BT_False))
      {
        DecWsPtr->DecWs.DeviationWs.IsAttribute = Exi_BT_True;
        (void)Exi_VBSDecodeGenericElement(DecWsPtr, SchemaSetId, SkipContent);
      }
      /*  StartTagContent  EE 0.0  */
      else if (exiEventCode == 0u)
      {
        /* EE: exit */
      }
      else
      {
        /* MISRA REQUIREMENT */
      }
    }
    /* #410 Further information in second bit */
  }
}

/**********************************************************************************************************************
 *  Exi_VBSDecodeCalculateBitSize()
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
FUNC(uint8, EXI_CODE) Exi_VBSDecodeCalculateBitSize(uint8 MaxValue)
{
  uint8 requiredBitSize = 1;
  uint8 idx;
  /* #10 Calculate the required bit size for the exi event */
  /* #20 Loop over all bits and calculate the size for highest bit set */
  for (idx = 0u; idx < 8u; idx++)
  {
    /* #30 If least significant bit is set */
    if ((MaxValue & 0x01u) == 0x01u)
    {
      /* #40 Set bit size by current bit index */
      requiredBitSize = (uint8)(idx + 1u);
    }
    /* #50 Shift MaxValue to next bit for next loop */
    MaxValue = (uint8)(MaxValue >> 1);                                                                                  /* PRQA S 1338 */ /* MD_Exi_FunctionParameter */
  }
  /* #60 Return bit size */
  return requiredBitSize;
}

/**********************************************************************************************************************
 *  Exi_VBSDecodeCheckAndAllocateBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void*, EXI_CODE) Exi_VBSDecodeCheckAndAllocateBuffer(
  P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  uint32 ElementSize,
  Exi_BooleanType IncrementStorageBuffer)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  P2VAR(void, AUTOMATIC, EXI_APPL_DATA) outPtr = NULL_PTR;

  /* --------------------------------------------- Implementation -------------------------------------------------- */

  /* #10 Try to allocate buffer for the given element size */
  outPtr = Exi_AllocateElementFromBufferWs(&DecWsPtr->OutputData.MemAllocWs, ElementSize, IncrementStorageBuffer);

  /* #20 Check if allocation is successful */
  if (outPtr != NULL_PTR)
  {
    /* Do nothing, allocation successful */
  }
  /* #30 Otherwise */
  else
  {
    /* #40 Set status code to error EXI_E_BUFFER_SIZE */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_BUFFER_SIZE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
  }
  /* #50 Return allocated address or NULL_PTR on error */
  return outPtr;
}

/**********************************************************************************************************************
 *  Exi_VBSDecodeGetWorkspaceBitPos()
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
FUNC(uint32, EXI_CODE) Exi_VBSDecodeGetWorkspaceBitPos(
  P2CONST(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_DATA) DecWsPtr)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  uint32 bytePosition;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Set position in current buffer (segment) */
  bytePosition = DecWsPtr->BytePos;

#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
  /* #20 If feature PBUF support is enabled */
  {
    /* #30 If not in first segment */
    if (DecWsPtr->PBufIdx != 0u)
    {
      uint8 TmpPBufIdx;

      /* #40 Add length of all previouse PBuf segments */
      for (TmpPBufIdx = 0; TmpPBufIdx < DecWsPtr->PBufIdx; TmpPBufIdx++)
      {
        bytePosition += DecWsPtr->PBufPtr[TmpPBufIdx].len;
      }
    }
  }
#endif

  /* #50 Calculate current bit position from the byte position and return the result */
  return ((uint32)(bytePosition << 3)) + DecWsPtr->BitPos;
}

/**********************************************************************************************************************
 *  Exi_VBSDecodeSetWorkspaceBitPos()
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
 */
FUNC(uint32, EXI_CODE) Exi_VBSDecodeSetWorkspaceBitPos(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  uint32 BitPos)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  uint32 maxBitPos;

  /* --------------------------------------------- Implementation -------------------------------------------------- */

#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
  /* #10 Check if buffer length is within data type boundaries */
  if ((uint32)DecWsPtr->PBufPtr[0].totLen <= (EXI_UINT32_MAX_NUM >> 3))
  {
    /* #20 Get the maximum possible bit position from the input buffer */
    maxBitPos = (uint32)(DecWsPtr->PBufPtr[0].totLen << 3);
  }
  /* #30 Otherwise */
  else
  {
    /* #40 Report buffer size error */
    maxBitPos = 0;
    Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_BUFFER_SIZE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
  }
#else
  /* #50 Check if buffer length is within data type boundaries */
  if ((uint32)DecWsPtr->BufLen <= (EXI_UINT32_MAX_NUM >> 3))
  {
    /* #60 Get the maximum possible bit position from the input buffer */
    maxBitPos = (uint32)(DecWsPtr->BufLen << 3);
  }
  /* #70 Otherwise */
  else
  {
    /* #80 Report buffer size error */
    maxBitPos = 0;
    Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_BUFFER_SIZE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
  }
#endif
  /* #90 Check if 'bit position to set' is smaller or equal than maximum possible bit position */
  if (BitPos <= maxBitPos)
  {
    /* #100 Set absolute byte and bit position */
    DecWsPtr->BytePos = (uint32)(BitPos >> 3);   /* (BitPos / BITS_IN_BYTE) */
    DecWsPtr->BitPos = (uint8)(BitPos & 0x07U); /* (BitPos % BITS_IN_BYTE) */

#if (EXI_ENABLE_PBUF_SUPPORT == STD_ON)
    /* #110 If feature PBUF support is enabled */
    {
      /* #120 Get the PBuf segment where the new position is inside */
      DecWsPtr->PBufIdx = 0;
      DecWsPtr->PBufProcessedElementBytes = 0;
      /* #130 If position is not in first segment */
      if (DecWsPtr->BytePos >= DecWsPtr->PBufPtr[0].len)
      {
        /* #140 Loop as long as the byte position is bigger than the current segment length */
        while (DecWsPtr->BytePos >= DecWsPtr->PBufPtr[DecWsPtr->PBufIdx].len)
        {
          /* #150 Mark the segment as already processed */
          DecWsPtr->PBufProcessedElementBytes += DecWsPtr->PBufPtr[DecWsPtr->PBufIdx].len;
          /* #160 If processed segments length is smaller than total length */
          if (DecWsPtr->PBufProcessedElementBytes < DecWsPtr->PBufPtr[0].totLen)
          {
            /* #170 Decrement byte position and increment PBUF index */
            DecWsPtr->BytePos -= DecWsPtr->PBufPtr[DecWsPtr->PBufIdx].len;
            DecWsPtr->PBufIdx++;
          }
          /* #180 Processed segments length is bigger or equal */
          else
          {
            /* #190 Mark the complete buffer as processed and set status code 'end of stream' reached, stop the loop */
            DecWsPtr->PBufProcessedElementBytes = DecWsPtr->PBufPtr[0].totLen;
            Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_EOS, EXI_BS_SSC_NO_DET_CALL, 0, 0);
            break;
          }
        }
      }
    }
#endif
  }
  /* #200 Otherwise */
  else
  {
    /* #210 Set the bit position to the end of the stream and throw an end of stream error */
    BitPos = maxBitPos;                                                                                                 /* PRQA S 1338 */ /* MD_Exi_FunctionParameter */
    Exi_VBSDecodeSetStatusCode(DecWsPtr, EXI_E_EOS, EXI_BS_SSC_NO_DET_CALL, 0, 0);
  }

  /* #220 Return the new bit position */
  return BitPos;
}

/**********************************************************************************************************************
 *  Exi_VBSDecodeSetStatusCode
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
FUNC(void, EXI_CODE) Exi_VBSDecodeSetStatusCode(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  Exi_ReturnType NewStatusCode,
  Exi_BSSetStatusCodeDetType CallInternal,
  uint16 ApiId,
  uint8 ErrorId)
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT != STD_ON )
  EXI_DUMMY_STATEMENT_CONST(ApiId);                                                                                     /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  EXI_DUMMY_STATEMENT_CONST(ErrorId);                                                                                   /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON) */

  /* #10 If DET error shall be set in any case */
  if (CallInternal == EXI_BS_SSC_CALL_DET_ALLWAYS)
  {
    /* #20 Set DET error using the provided API and ERROR ID */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
    (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, (uint8)ApiId, ErrorId);
#endif
  }
  /* #30 If status code is still OK */
  if (DecWsPtr->StatusCode == EXI_E_OK)
  {
    /* #40 If DET shall be set on status code changes */
    if (CallInternal == EXI_BS_SSC_CALL_DET_ON_CHANGE)
    {
      /* #50 Set DET error using the provided API and ERROR ID */
#if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
      (void)Det_ReportError(EXI_MODULE_ID, EXI_DECODER_INSTANCE_ID, (uint8)ApiId, ErrorId);
#endif
    }
    /* #60 Set new status code */
    DecWsPtr->StatusCode = NewStatusCode;
  }
}

/**********************************************************************************************************************
 *  Exi_VBSDecodeCheckForFirstElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, EXI_CODE) Exi_VBSDecodeCheckForFirstElement(
  P2VAR(Exi_DecoderOutputDataType, AUTOMATIC, EXI_APPL_VAR) OutPutDataPtr,
  P2VAR(Exi_BooleanType, AUTOMATIC, EXI_APPL_VAR) isFirstElementPtr,
  Exi_RootElementIdType RootElementId)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
#if ( EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON )
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (RootElementId >= EXI_SCHEMA_UNKNOWN_ELEMENT_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
#endif /* (EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON) */
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If workspace root element ID is still set to unknown */
    if (OutPutDataPtr->RootElementId == EXI_SCHEMA_UNKNOWN_ELEMENT_TYPE)
    {
      /* #30 This is the first start tag in the stream, set ID as root element */
      *isFirstElementPtr = Exi_BT_True;
      OutPutDataPtr->RootElementId = RootElementId;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON )
  if (errorId != EXI_E_NO_ERROR)
  {
    (void)Det_ReportError(EXI_MODULE_ID, EXI_INSTANCE_ID, EXI_API_ID_V_INTERNAL_FUNCTION, errorId);
  }
#else
  EXI_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 3112, 3199 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* (EXI_INTERNAL_DEV_ERROR_DETECT == STD_ON) */
}


/**********************************************************************************************************************
 *  Exi_VBSDecodeCheckAndDecodeEE
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
 */
FUNC(Std_ReturnType, EXI_CODE) Exi_VBSDecodeCheckAndDecodeEE(
  P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  uint8 BitCount,
  Exi_BitBufType SchemaDeviationEventCode,
  uint16 SchemaSetId,
  uint16 ElementIdentifier)
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_BitBufType exiEventCode;
  Std_ReturnType retVal = E_NOT_OK;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 If end element (EE) flag is set */
  if (DecWsPtr->DecWs.EERequired == Exi_BT_True)
  {
    /* #20 Read EE event code from stream */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, BitCount);
    /* #30 Check if a schema deviation did occur */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, SchemaDeviationEventCode, BitCount, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, SchemaSetId, ElementIdentifier);

    /* #40 If event code is valid */
    if (exiEventCode < SchemaDeviationEventCode)
    {
      /* #50 EE event code is valid */
      retVal = E_OK;
    }
    /* #60 Event code is invalid */
    else
    {
      /* #70 Set status code to error. retVal already set to E_NOT_OK */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
    }
  }
  /* #80 End element flag is not set */
  else
  {
    /* #90 EE already decoded in subfunction call, reset EE flag to TRUE */
    DecWsPtr->DecWs.EERequired = Exi_BT_True;
    retVal = E_OK;
  }
  return retVal;
}

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_VBSDecodeTruncateRemainder
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
EXI_LOCAL FUNC(void, EXI_CODE) Exi_VBSDecodeTruncateRemainder(
  P2VAR(Exi_BSDecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr,
  uint32 ActualLen,
  uint32 ProvidedLen)
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Check if error is present */
  if (DecWsPtr->StatusCode != EXI_E_OK)
  {
    /* Do nothing */
  }
  /* #20 Otherwise check if actual length is bigger than the provided buffer */
  else if (ActualLen > ProvidedLen)
  {
    uint32 tmpBitsToSkip = ((ActualLen - ProvidedLen) * EXI_BITS_IN_BYTE);
    /* #30 Check if excessing bytes can be skipped */
    if (tmpBitsToSkip == Exi_VBSDecodeSkipBits(DecWsPtr, tmpBitsToSkip))
    {
      /* Skipping successful, do nothing further */
    }
    /* #40 Otherwise */
    else
    {
      /* #50 End of Stream reached, error already thrown by Exi_VBSDecodeSkipBits(...) */
    }
  }
  /* #60 Otherwise */
  else
  {
    /* Do nothing */
  }
}


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Exi_BSDecoder.c
 **********************************************************************************************************************/
