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
/*!        \file  ESLib_HKDF_Hash_OneStep.c
 *        \brief  HKDF SHA256 and SHA512 one step key derivation function according to NIST SP800-56C.
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

#define ESLIB_HKDFHASHONESTEP_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "ESLib.h"
#include "ESLib_Helper.h"

/* actCLib includes */
#include "actIHKDF_Hash_OneStep.h"

#if ((VSECPRIM_HKDF_SHA2_256_ONESTEP_ENABLED == STD_ON) || (VSECPRIM_HKDF_SHA2_512_ONESTEP_ENABLED == STD_ON))

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  esl_initHKDF_Hash_OneStep_dispatchHashId
 **********************************************************************************************************************/
/*! \brief         Stores hashID and corresponding hash digest size in workspace, if hashID is valid.
 *  \details       -
 *  \param[in,out] workSpace  (in)  HKDF hash work space
 *                            (out) HKDF hash work space
 *  \param[in]     hashID     flag which indicates which hash function shall be used; checked for validity here
 *  \return        ESL_ERC_NO_ERROR           Operation successful
 *                 ESL_ERC_INPUT_INVALID      hashID != ESL_HA_SHA2_256 and hashID != ESL_HA_SHA2_512
 *  \pre           workSpace is initialized by esl_initWorkSpaceHeader(..)
 *  \context       TASK
 *  \reentrant     TRUE, for different workspaces.
 *  \synchronous   TRUE
 **********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initHKDF_Hash_OneStep_dispatchHashId(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHKDFHASH) workSpace,
  eslt_HashAlgorithm hashID);

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  esl_initHKDF_Hash_OneStep_dispatchHashId
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initHKDF_Hash_OneStep_dispatchHashId(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHKDFHASH) workSpace,
  eslt_HashAlgorithm hashID)
{
  eslt_ErrorCode retVal = ESL_ERC_INPUT_INVALID;

  switch (hashID)
  {
# if (VSECPRIM_HKDF_SHA2_256_ONESTEP_ENABLED == STD_ON)
    case ESL_HA_SHA2_256:
      workSpace->wsHKDF.hashID = hashID; /* SBSW_VSECPRIM_WRITE_POINTER */
      workSpace->wsHKDF.hashSize = actHASH_SIZE_SHA256; /* SBSW_VSECPRIM_WRITE_POINTER */
      retVal = ESL_ERC_NO_ERROR;
      break;
# endif
# if (VSECPRIM_HKDF_SHA2_512_ONESTEP_ENABLED == STD_ON)
    case ESL_HA_SHA2_512:
      workSpace->wsHKDF.hashID = hashID; /* SBSW_VSECPRIM_WRITE_POINTER */
      workSpace->wsHKDF.hashSize = actHASH_SIZE_SHA512; /* SBSW_VSECPRIM_WRITE_POINTER */
      retVal = ESL_ERC_NO_ERROR;
      break;
# endif
    default:
      /* nothing to do; retVal is already set. */
      break;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/***********************************************************************************************************************
 *  esl_initHKDF_Hash_OneStep()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_initHKDF_Hash_OneStep(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHKDFHASH) workSpace,
  eslt_HashAlgorithm hashID)
{
  eslt_ErrorCode retVal;
  /* validate parameters */
  if (workSpace == NULL_PTR)
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_HKDF_HASH)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    /* retVal was already set */
  }
  else if ((retVal = esl_initHKDF_Hash_OneStep_dispatchHashId(workSpace, hashID)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    /* retVal already set */
  }
  else
  {
    /* set workSpace state */
    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_HKDF_HASH_ONESTEP); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }
  return retVal;
}

/***********************************************************************************************************************
 *  esl_deriveKeyHKDF_Hash_OneStep
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_deriveKeyHKDF_Hash_OneStep(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHKDFHASH) workSpace,
  const eslt_Length secretLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) secret,
  const eslt_Length infoLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) info,
  const eslt_Length keyLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) key)
{
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  /* validate parameters */
  if ((workSpace == NULL_PTR) || (secret == NULL_PTR) || ((info == NULL_PTR) && (infoLength > 0u)) || (key == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* check length */
  else if ((secretLength == 0u) || (keyLength == 0u))
  {
    retVal = ESL_ERC_INPUT_INVALID;
  }
  /* check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HKDF_HASH, ESL_WST_ALGO_HKDF_HASH_ONESTEP)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_P2CONST_PARAM */
  {
    /* retVal was already set */
  }
  else
  {
    actRetVal = actHKDF_Hash_OneStepDerive(&workSpace->wsHKDF, secret, secretLength, info, infoLength, key, keyLength, workSpace->header.watchdog); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */

    if (actRetVal == actEXCEPTION_LENGTH)
    {
      retVal = ESL_ERC_INVALID_LENGTH;
    }
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VSECPRIM_HKDF_HMAC_SHA256_ENABLED == STD_ON */

/**********************************************************************************************************************
 *  END OF FILE: ESLib_HKDF_Hash_OneStep.c
 *********************************************************************************************************************/

