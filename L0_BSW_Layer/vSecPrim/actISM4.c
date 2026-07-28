/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 1999 - 2016 cv cryptovision GmbH.                                                All rights reserved.
 *
 *  For modifications by Vector Informatik GmbH:
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is protected under intellectual property laws and proprietary to cv cryptovision GmbH
 *                and/or Vector Informatik GmbH.
 *                No right or license is granted save as expressly set out in the applicable license conditions.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  actISM4.c
 *         \unit  act_SM4
 *        \brief  SM4 encryption and decryption implementation.
 *
 *      \details Currently the actClib version is used.
 *               This file is part of the embedded systems library actCLib
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to module's header file.
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "actISM4.h"
#include "actSM4.h"
#include "actUtilities.h"
#include "actWatchdog.h"
#include "actConfig.h"

#if (VSECPRIM_ACTISM4_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actSM4InitEncryptDecrypt()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(void) actSM4InitEncryptDecrypt(
  VSECPRIM_P2VAR_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) key,
  VSECPRIM_P2CONST_PARA(actU8) iv,
  actU8 mode,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actSM4Init(info, key, iv, mode, watchdog);
}

/**********************************************************************************************************************
 *  actSM4EncryptDecrypt()
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
 *
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actSM4EncryptDecrypt(
  VSECPRIM_P2VAR_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) in,
  actLengthType inLength,
  VSECPRIM_P2VAR_PARA(actU8) outBuffer,
  VSECPRIM_P2VAR_PARA(actLengthType) outLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE retVal = actEXCEPTION_UNKNOWN;

  /*  Remark: info->bufferUsed corresponds to the number of used bytes in info->buffer and is max actSM4_BLOCK_SIZE.
   *          Hence, there is no underflow in the next check. */
  if (inLength <= (actSM4_BLOCK_SIZE - info->bufferUsed))
  {
    /* Case inLength + info->bufferUsed <= actSM4_BLOCK_SIZE:
     * The in data is concatenate to info->buffer and the buffer data will be processed in the next call of
     * - actSM4EncryptDecrypt or
     * - actSM4EncryptDecryptBlock
     */
    actMemCpyByteArray(&(info->buffer[info->bufferUsed]), in, inLength);
    info->bufferUsed += inLength;

    *outLength = 0u;
    retVal = actOK;
  }
  else
  {
    /* Case inLength + info->bufferUsed > actSM4_BLOCK_SIZE:
     * Remark: As long as data is provided, blocks should be processed such that 1 to 16 bytes remain in the info->buffer.
     *         To get the correct number of blocks to proceed, a trick is used: The nbr of bytes to process is reduced
     *         by 1 (no issue, since the case nbrOfBytes == 0 is handled in the if-case) and the nbr of blocks to proceed
     *         is the quotient in the euclidean division by actSM4_BLOCK_SIZE. */
    actLengthType nbrOfBytes = info->bufferUsed + inLength;
    actLengthType nbrOutputBlocks = (nbrOfBytes - 1u) / actSM4_BLOCK_SIZE;
    actLengthType nbrOfBytesOutput = actSM4_BLOCK_SIZE * nbrOutputBlocks;

    if (nbrOfBytesOutput > *outLength)
    {
      /* Output buffer is too small */
      retVal = actEXCEPTION_OUTPUT_BUFFER;
    }
    else
    {
      /* (actSM4_BLOCK_SIZE - info->bufferUsed) bytes are concatenate to info->buffer and are en/decrypted
       * Remark: We are in the case inLength + info->bufferUsed > actSM4_BLOCK_SIZE.
       *         Hence, inLength > actSM4_BLOCK_SIZE - info->bufferUsed = diff
       *         and only bytes from the array in are copied in info->buffer. */
      actLengthType diff = actSM4_BLOCK_SIZE - info->bufferUsed;
      actLengthType inIdx = diff;
      actMemCpyByteArray(&(info->buffer[info->bufferUsed]), in, diff);
      actSM4EncryptDecryptMultipleBlocks(info, info->buffer, outBuffer, 1u, watchdog);

      /* Proceed the next complete blocks */
      actSM4EncryptDecryptMultipleBlocks(info, &(in[inIdx]), &outBuffer[actSM4_BLOCK_SIZE], (nbrOutputBlocks - 1u), watchdog);

      /* Copy the last 1 to actSM4_BLOCK_SIZE bytes into info->buffer */
      inIdx += (nbrOutputBlocks - 1u) * actSM4_BLOCK_SIZE;
      actMemCpyByteArray(info->buffer, &(in[inIdx]), nbrOfBytes - nbrOfBytesOutput);

      /* Save the buffer used length */
      info->bufferUsed = nbrOfBytes - nbrOfBytesOutput;
      *outLength = nbrOfBytesOutput;
      retVal = actOK;
    }
  }

  actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */  /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
  return retVal;
}

/**********************************************************************************************************************
 *  actSM4FinalizeEncryptDecrypt()
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
VSECPRIM_FUNC(actRETURNCODE) actSM4FinalizeEncryptDecrypt(
  VSECPRIM_P2VAR_PARA(actSM4STRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) outBuffer,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE retVal = actEXCEPTION_INPUT_LENGTH;

  /* The finalize step process the last block saved in info->buffer.
   * Since no padding is supported, info->buffer must be completely filled. */
  if (info->bufferUsed != actSM4_BLOCK_SIZE)
  {
    /* retVal already set */
  }
  else
  {
    actSM4EncryptDecryptMultipleBlocks(info, info->buffer, outBuffer, 1u, watchdog);
    retVal = actOK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  actSM4InitEncryptDecryptBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(void) actSM4InitEncryptDecryptBlock(
  VSECPRIM_P2VAR_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) key,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actSM4KeySetup(info, key, watchdog);
}

/**********************************************************************************************************************
 *  actSM4EncryptDecryptBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(void) actSM4EncryptDecryptBlock(
  VSECPRIM_P2CONST_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) inBlock,
  VSECPRIM_P2VAR_PARA(actU8) outBlock,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  if (info->cryptMode == actSM4_ENCRYPT)
  {
    actSM4EncryptBlockCore(info, inBlock, outBlock, watchdog);
  }
  else
  {
    actSM4DecryptBlockCore(info, inBlock, outBlock, watchdog);
  }
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTISM4_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  END OF FILE: actISM4.c
 *********************************************************************************************************************/
