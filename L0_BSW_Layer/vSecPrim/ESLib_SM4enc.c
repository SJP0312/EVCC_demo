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
/*!        \file  ESLib_SM4enc.c
 *         \unit  es_SM4
 *        \brief  SM4 cipher encryption implementation.
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

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "ESLib.h"
#include "ESLib_types.h"
#include "ESLib_Helper.h"

/* actCLib includes */
#include "actISM4.h"
#include "actUtilities.h"

#if (VSECPRIM_SM4_ENABLED == STD_ON)  /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  esl_initEncryptSM4()
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
 /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptSM4(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSM4) workSpace,
  const eslt_Length keySize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) key,
  const eslt_BlockMode blockMode,
  const eslt_Length initVectorSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) initVector)
{
  eslt_ErrorCode retVal = ESL_ERC_ERROR;

  /* validate parameters */
  if ((workSpace == NULL_PTR) || (key == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_SIZEOF_WS_SM4)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    /* retVal was already set */
  }
  /* Check Length */
  else if (keySize != ESL_SIZEOF_SM4_KEY)
  {
    retVal = ESL_ERC_INVALID_LENGTH;
  }
  /* evaluate block mode */
  else if ((blockMode != ESL_BM_ECB) && (blockMode != ESL_BM_CBC))
  {
    retVal = ESL_ERC_MODE_INVALID;
  }
  /* In the CBC mode, if a pointer to an initVector is given, the length must be set on ESL_SIZEOF_SM4_BLOCK */
  else if ((blockMode == ESL_BM_CBC) && (initVector != NULL_PTR) && (initVectorSize != ESL_SIZEOF_SM4_BLOCK))
  {
    retVal = ESL_ERC_INVALID_LENGTH;
  }
  else
  {
    eslt_Byte mode = (blockMode == ESL_BM_ECB) ? actSM4_ECB : actSM4_CBC;
    workSpace->wsSM4.cryptMode = ESL_SM4_ENCRYPT;

    /* initialize actCLib SM4 */
    actSM4InitEncryptDecrypt(&(workSpace->wsSM4), key, initVector, mode, workSpace->header.watchdog);

    /* set workSpace state */
    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_SM4); /* SBSW_VSECPRIM_CALL_FUNCTION */
    /* retVal already set to ESL_ERC_NO_ERROR by esl_CheckWorkSpaceHeader */
  }
  return retVal;
}

/**********************************************************************************************************************
 *  esl_encryptSM4()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptSM4(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSM4) workSpace,
  const eslt_Length inputSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) input,
  VSECPRIM_P2VAR_PARA(eslt_Length) outputSize,
  VSECPRIM_P2VAR_PARA(eslt_Byte) output)
{
  eslt_ErrorCode retVal = ESL_ERC_ERROR;

  /* validate parameters */
  if ((workSpace == NULL_PTR) || (input == NULL_PTR) || (outputSize == NULL_PTR) || (output == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* check workSpace state */
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_SM4, ESL_WST_ALGO_SM4)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_P2CONST_PARAM */
  {
    /* retVal was already set */
  }
  else
  {
    /* update actCLib SM4 */
    actLengthType encryptionLength = (actLengthType) *outputSize;
    actRETURNCODE result = actSM4EncryptDecrypt(&(workSpace->wsSM4), input, (actLengthType) inputSize, output,
                                                                &encryptionLength, workSpace->header.watchdog);
    if (result == actOK)
    {
      *outputSize = (eslt_Length) encryptionLength;
      /* retVal already set to ESL_ERC_NO_ERROR by esl_CheckWorkSpaceHeaderAndState */
    }
    else if (result == actEXCEPTION_OUTPUT_BUFFER)
    {
      retVal = ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
    }
    else /* unexpected error */
    {
      retVal = ESL_ERC_ERROR;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  esl_finalizeEncryptSM4()
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
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeEncryptSM4(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSM4) workSpace,
  VSECPRIM_P2VAR_PARA(eslt_Length) outputSize,
  VSECPRIM_P2VAR_PARA(eslt_Byte) output)
{
  eslt_ErrorCode retVal = ESL_ERC_ERROR;

  /* validate parameters */
  if ((workSpace == NULL_PTR) || (output == NULL_PTR)|| (outputSize == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* check workSpace state */
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_SM4, ESL_WST_ALGO_SM4)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_P2CONST_PARAM */
  {
    /* retVal was already set */
  }
  else if (*outputSize < ESL_SIZEOF_SM4_BLOCK)
  {
    retVal = ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
  }
  else
  {
    actRETURNCODE result = actSM4FinalizeEncryptDecrypt(&(workSpace->wsSM4), output, workSpace->header.watchdog);
    if (result == actOK)
    {
      *outputSize = ESL_SIZEOF_SM4_BLOCK;
      /* reset and clear workspace */
      esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsSM4); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
      /* retVal already set to ESL_ERC_NO_ERROR by esl_CheckWorkSpaceHeaderAndState */
    }
    else if (result == actEXCEPTION_INPUT_LENGTH)
    {
      retVal = ESL_ERC_INPUT_INVALID;           /* the total input length is not zero mod ESL_SIZEOF_SM4_BLOCK */
    }
    else
    {
      /* unexpected error */
      retVal = ESL_ERC_ERROR;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  esl_initEncryptSM4Block()
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
VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptSM4Block(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSM4Block) workSpace,
  const eslt_Length keySize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) key)
{
  eslt_ErrorCode retVal = ESL_ERC_ERROR;

  /* validate parameters */
  if ((workSpace == NULL_PTR) || (key == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_SIZEOF_WS_SM4BLOCK)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    /* retVal was already set */
  }
  /* check length */
  else if (keySize != ESL_SIZEOF_SM4_KEY)
  {
    retVal = ESL_ERC_INVALID_LENGTH;
  }
  else
  {
    workSpace->wsSM4.cryptMode = actSM4_ENCRYPT;

    /* initialize actCLib SM4 */
    actSM4InitEncryptDecryptBlock(&(workSpace->wsSM4), key, workSpace->header.watchdog);

    /* set workSpace state */
    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_SM4); /* SBSW_VSECPRIM_CALL_FUNCTION */

    /* retVal already set to ESL_ERC_NO_ERROR by esl_CheckWorkSpaceHeader */
  }
  return retVal;
}

/**********************************************************************************************************************
 *  esl_encryptSM4Block()
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
VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptSM4Block(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSM4Block) workSpace,
  const eslt_Length inputBlockSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) inputBlock,
  VSECPRIM_P2VAR_PARA(eslt_Length) outputBlockSize,
  VSECPRIM_P2VAR_PARA(eslt_Byte) outputBlock)
{
  eslt_ErrorCode retVal = ESL_ERC_ERROR;

  /* validate parameters */
  if ((workSpace == NULL_PTR) || (inputBlock == NULL_PTR) || (outputBlock == NULL_PTR) || (outputBlockSize == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* check workSpace state */
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_SM4, ESL_WST_ALGO_SM4)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_P2CONST_PARAM */
  {
    /* retVal was already set */
  }
  /* check length */
  else if(inputBlockSize != ESL_SIZEOF_SM4_BLOCK)
  {
    retVal = ESL_ERC_INVALID_LENGTH;
  }
  /* Output buffer too small */
  else if (*outputBlockSize < ESL_SIZEOF_SM4_BLOCK)
  {
    retVal = ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
  }
  else
  {
    /* encrypt block */
    actSM4EncryptDecryptBlock(&(workSpace->wsSM4), inputBlock, outputBlock, workSpace->header.watchdog);
    *outputBlockSize = ESL_SIZEOF_SM4_BLOCK;
    /* reset and clear workspace */
    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsSM4); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    /* retVal already set to ESL_ERC_NO_ERROR by esl_CheckWorkSpaceHeaderAndState */
  }
  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_SM4_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  END OF FILE: ESLib_SM4enc.c
 *********************************************************************************************************************/
