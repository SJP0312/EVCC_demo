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
/*!        \file  actISM3.c
 *        \brief  SM3 hash implementation.
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

#define ACTISM3_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "actISM3.h"
#include "actSM3.h"
#include "actUtilities.h"
#include "actWatchdog.h"
#include "actConfig.h"

#if (VSECPRIM_ACTISM3_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  actSM3Init()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_FUNC(void) actSM3Init(VSECPRIM_P2VAR_PARA(actSM3STRUCT) sm3)
{
  /* initialize message digest */
  sm3->H[0] = 0x7380166FU;
  sm3->H[1] = 0x4914B2B9U;
  sm3->H[2] = 0x172442D7U;
  sm3->H[3] = 0xDA8A0600U;
  sm3->H[4] = 0xA96F30BCU;
  sm3->H[5] = 0x163138AAU;
  sm3->H[6] = 0xE38DEE4DU;
  sm3->H[7] = 0xB0FB0E4EU;

  /* initialize working variables */
  sm3->low_count = 0x00u;
  sm3->hi_count = 0x00u;
  sm3->buffer_used = 0x00u;

}

/***********************************************************************************************************************
 *  actSM3Update()
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
 */
VSECPRIM_FUNC(actRETURNCODE) actSM3Update(
  VSECPRIM_P2VAR_PARA(actSM3STRUCT) sm3,
  VSECPRIM_P2CONST_PARA(actU8) input,
  actLengthType inputSize,
  VSECPRIM_P2FUNC( VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE retVal = actOK;
  actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */

  /* update byte count */
  if ((sm3->low_count + inputSize) < sm3->low_count)
  {
    /* overflow from low counter
     * note: hi_count is in bytes, therefore check if it exceeds 2^29 bytes (not 2^32 bits) */
    if ((sm3->hi_count + 1u) == ((actU32)1u << 29u))
    {
      /* overflow: > 2^64 bit input */
      retVal =  actEXCEPTION_LENGTH;
    }
    else
    {
      sm3->hi_count++;
      /* retVal is already set to actOK */
    }
  }

  if (retVal == actOK)
  {
    actU32 diff = 0x00u;
    actBoolean finished = FALSE;
    sm3->low_count += inputSize;

    /* any buffered data? */
    if (sm3->buffer_used > 0u)
    {
      /* copy the amount of data that fits in the block into the buffer: either whole data or only part of the data */
      diff = actMin(inputSize, actHASH_BLOCK_SIZE_SM3 - sm3->buffer_used);
      actMemCpyByteArray(&sm3->buffer[sm3->buffer_used], input, diff);
      sm3->buffer_used += diff;

      /* check if the block is not full */
      if(sm3->buffer_used < actHASH_BLOCK_SIZE_SM3)
      {
        /* block NOT yet filled up */
        retVal = actOK;
        finished = TRUE;
      }
      else
      {
        actSM3_Transform(sm3->buffer, sm3->H, watchdog);
      }
    }

    if(finished == FALSE)
    {
      actLengthType lastBlockEnd;
      actLengthType bcount;

      lastBlockEnd = (actLengthType)((inputSize - diff) / actHASH_BLOCK_SIZE_SM3);
      lastBlockEnd = (lastBlockEnd * actHASH_BLOCK_SIZE_SM3) + diff;

      for (bcount = diff; bcount < lastBlockEnd; bcount += actHASH_BLOCK_SIZE_SM3) /* FETA_VSECPRIM_UPPER_BOUNDARY_CHECKED_BY_CALLEE_PARAMETER */
      {
        actSM3_Transform(&input[bcount], sm3->H, watchdog);
      }

      /* copy left overs into buffer */
      sm3->buffer_used = (actLengthType)(inputSize - lastBlockEnd); /* SBSW_VSECPRIM_WRITE_POINTER */
      actMemCpyByteArray(sm3->buffer, &input[lastBlockEnd], (actLengthType)(sm3->buffer_used)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */

      actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
    }
  }
  return retVal;
}

/***********************************************************************************************************************
 *  actSM3Finalize()
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
VSECPRIM_FUNC(void) actSM3Finalize(
  VSECPRIM_P2VAR_PARA(actSM3STRUCT) sm3,
  VSECPRIM_P2VAR_PARA(actU8) digest,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actU8 padLength = actHASH_BLOCK_SIZE_SM3 - (2u * actSM3_WORD_SIZE);

  actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */

  /* append 1 at the end of the message: pad byte '0x80' */
  sm3->buffer[sm3->buffer_used] = 0x80u; /* = (1000 0000)_2 */
  sm3->buffer_used++;

  /* check if the buffer_used is smaller than the block size to avoid "using" data that is not part of the buffer
   * In the case the buffer_used is equal to actHASH_BLOCK_SIZE_SM3, there is no need to pad the block with zeros
   * as it is already full */
  if (sm3->buffer_used < actHASH_BLOCK_SIZE_SM3)
  {
    /* pad zeros */
    actMemClear(&sm3->buffer[sm3->buffer_used], actHASH_BLOCK_SIZE_SM3 - sm3->buffer_used);
  }

  if (sm3->buffer_used > padLength)
  {
    /* bit-count DOESN'T fit */
    actSM3_Transform(sm3->buffer, sm3->H, watchdog);

    /* set the buffer to zero */
    actMemClear(sm3->buffer, padLength);
  }

  /* convert byte-count to bit-count and write to block */
  actU32toBE(&sm3->buffer[padLength], (sm3->hi_count  << 3u) | (sm3->low_count >> 29u));
  actU32toBE(&sm3->buffer[padLength + actSM3_WORD_SIZE], sm3->low_count << 3u);

  /* transform last block */
  actSM3_Transform(sm3->buffer, sm3->H, watchdog);

  /* wipe buffer */
  actMemClear(sm3->buffer, actHASH_BLOCK_SIZE_SM3);

  /* store digest in BIG endian byte order */
  actCpyU32toBE(digest, sm3->H, actHASH_SIZE_SM3/actSM3_WORD_SIZE);

  actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTISM3_ENABLED == STD_ON) */
/***********************************************************************************************************************
 *  END OF FILE: actISM3.c
 **********************************************************************************************************************/
