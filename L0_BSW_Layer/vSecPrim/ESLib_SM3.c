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
/*!        \file  ESLib_SM3.c
 *        \brief  SM3 hash implementation taken from: tools.ietf.org/html/draft-oscca-cfrg-sm3-02
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

#define ESLIB_SM3_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "ESLib.h"
#include "ESLib_types.h"
#include "ESLib_Helper.h"

/* actCLib includes */
#include "actISM3.h"
#include "actUtilities.h"

#if (VSECPRIM_SM3_ENABLED == STD_ON)  /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  esl_initSM3()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_initSM3(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSM3) workSpace)
{
  eslt_ErrorCode retVal;

  if (workSpace == NULL_PTR)
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_SIZEOF_WS_SM3)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_P2CONST_PARAM */
  {
    /* retVal already set */
  }
  else
  {
    retVal = ESL_ERC_NO_ERROR;
    /* initialize actCLib SM3 */
    actSM3Init(&workSpace->wsSM3);

    /* set workSpace state */
    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_SM3);
  }

  return retVal;
}

/***********************************************************************************************************************
 *  esl_updateSM3()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSM3 (
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSM3) workSpace,
  const eslt_Length inputSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) input)
{
  eslt_ErrorCode retVal;

  if ((workSpace == NULL_PTR) || (input == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_SM3, ESL_WST_ALGO_SM3)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_P2CONST_PARAM */
  {
    /* retVal already set */
  }
  else
  {
    actRETURNCODE actRetVal = actSM3Update(&workSpace->wsSM3, input, inputSize, workSpace->header.watchdog);
    if (actRetVal == actEXCEPTION_LENGTH)
    {
      retVal = ESL_ERC_TOTAL_LENGTH_OVERFLOW;
    }
  }
  return retVal;
}

/***********************************************************************************************************************
 *  esl_finalizeSM3()
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
VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSM3(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSM3) workSpace,
  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest,
  VSECPRIM_P2VAR_PARA(eslt_Length) messageDigestLength)
{
  eslt_ErrorCode retVal;

  if ((workSpace == NULL_PTR) || (messageDigest == NULL_PTR) || (messageDigestLength == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_SM3, ESL_WST_ALGO_SM3)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_P2CONST_PARAM */
  {
    /* retVal already set */
  }
  else
  {
    if (*messageDigestLength >= ESL_SIZEOF_SM3_DIGEST)
    {
      /* the total hash value is computed and stored */
      /* finalize actCLib SM3 */
      actSM3Finalize(&workSpace->wsSM3, messageDigest, workSpace->header.watchdog);
      *messageDigestLength = ESL_SIZEOF_SM3_DIGEST;
    }
    else
    {
      /* total hash value is computed, however only partial hash value is stored in messageDigest */
      /* finalize actCLib SM3 */
      if(*messageDigestLength == 0u)
      {
        /* do nothing */
      }
      else
      {
        actSM3Finalize(&workSpace->wsSM3, workSpace->wsSM3.digest, workSpace->header.watchdog);
        Esl_MemCpyByteArray(messageDigest, workSpace->wsSM3.digest, *messageDigestLength);
      }
    }
    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsSM3); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  }
  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* (VSECPRIM_SM3_ENABLED == STD_ON) */
/***********************************************************************************************************************
 *  END OF FILE: ESLib_SM3.c
 **********************************************************************************************************************/
