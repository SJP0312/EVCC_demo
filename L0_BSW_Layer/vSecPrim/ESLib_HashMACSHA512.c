/***********************************************************************************************************************
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
/*!        \file  ESLib_HashMACSHA512.c
 *        \brief  Hash MAC SHA-512 implementation.
 *
 *      \details Currently the actClib version is used.
 *               This file is part of the embedded systems library cvActLib/ES
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

#define ESLIB_HASHMACSHA512_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "ESLib.h"
#include "ESLib_Helper.h"

/* actCLib includes */
#include "actIHashMACSHA512.h"

#if (VSECPRIM_HMAC_SHA2_512_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/****************************************************************************
 * esl_initHashMACSHA512
 ***************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_initHashMACSHA512(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA512) workSpace, const eslt_Length keyLength, VSECPRIM_P2CONST_PARA(eslt_Byte) key)
{
  eslt_ErrorCode retVal;

  /* Any NULLs ? */
  if ((workSpace == NULL_PTR) || (key == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* Check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA512)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */
  {
    /* retVal already set */
  }
  /* Check keyLength */
  else if (keyLength == 0u)
  {
    retVal = ESL_ERC_HMAC_KEY_LENGTH_OUT_OF_RANGE;
  }
  else
  {
    /* init actCLib HMAC-SHA-512; it is safe to void actHashMACSHA512Init, since actHashMACSHA512Init only returns
     * actEXCEPTION_LENGTH, if keyLength < 1, and this was checked before */
    (void)actHashMACSHA512Init(&workSpace->wsHMACSHA512, key, keyLength, workSpace->header.watchdog);

    /* Set workSpace state */
    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_HMACSHA512);

  }

  return retVal;
}

/****************************************************************************
 * esl_updateHashMACSHA512
 ***************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_updateHashMACSHA512(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA512) workSpace, const eslt_Length inputLength, VSECPRIM_P2CONST_PARA(eslt_Byte) input)
{
  eslt_ErrorCode retVal;

  /* Any NULLs ? */
  if ((workSpace == NULL_PTR) || (input == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* Check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA512, ESL_WST_ALGO_HMACSHA512)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */
  {
    /* retVal already set */
  }
  else
  {
    /* update actCLib HMAC-SHA-512 */
    if (actEXCEPTION_LENGTH == actHashMACSHA512Update(&workSpace->wsHMACSHA512, input, inputLength, workSpace->header.watchdog))
    {
      retVal = ESL_ERC_TOTAL_LENGTH_OVERFLOW;
    }
  }

  return retVal;
}

/****************************************************************************
 * esl_finalizeHashMACSHA512
 ***************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashMACSHA512(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA512) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageHashMAC, VSECPRIM_P2VAR_PARA(eslt_Length) messageHashMACLength)
{
  eslt_ErrorCode retVal;

  /* Any NULLs ? */
  if ((workSpace == NULL_PTR) || (messageHashMAC == NULL_PTR) || (messageHashMACLength == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if (*messageHashMACLength < ESL_SIZEOF_SHA512_DIGEST)
  {
    retVal = ESL_ERC_INPUT_INVALID;
  }
  /* Check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA512, ESL_WST_ALGO_HMACSHA512)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */
  {
    /* retVal already set */
  }
  else
  {
    /* finalize actCLib HMAC-SHA-512 */
    actHashMACSHA512Finalize(&workSpace->wsHMACSHA512, messageHashMAC, workSpace->header.watchdog);

    *messageHashMACLength = ESL_SIZEOF_SHA512_DIGEST;

    /* Reset and clear workspace */
    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsHMACSHA512); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
  }

  return retVal;
}

/****************************************************************************
 * esl_verifyHashMACSHA512
 ***************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyHashMACSHA512(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA512) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) messageHashMAC, const eslt_Length messageHashMACLength)
{
  eslt_Byte tmpMAC[ESL_SIZEOF_SHA512_DIGEST];
  eslt_ErrorCode retVal;
  eslt_Length messageLength = messageHashMACLength;

  actMemClear(tmpMAC, ESL_SIZEOF_SHA512_DIGEST); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */

  /* Any NULLs ? messageHashMACLength has to be of size 64 */
  if ((workSpace == NULL_PTR) || (messageHashMAC == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if (messageHashMACLength != ESL_SIZEOF_SHA512_DIGEST)
  {
    retVal = ESL_ERC_INPUT_INVALID;
  }
  /* Check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA512, ESL_WST_ALGO_HMACSHA512)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */
  {
    /* retVal already set */
  }
  else
  {
    /* Verify MAC; it is safe to void esl_finalizeHashMACSHA512, since all relevant error conditions for
     * esl_finalizeHashMACSHA512 were checked before */
    (void)esl_finalizeHashMACSHA512(workSpace, tmpMAC, &messageLength);

    if (actMemcmp(tmpMAC, messageHashMAC, ESL_SIZEOF_SHA512_DIGEST) != TRUE) /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
    {
      retVal = ESL_ERC_HMAC_INCORRECT_MAC;
    }

  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_HMAC_SHA2_512_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  END OF FILE: ESLib_HashMACSHA512.c
 *********************************************************************************************************************/
