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
/*!        \file  ESLib_SLHDSA.c
 *        \unit   es_SLHDSA
 *        \brief  SLH-DSA verification implementation, see NIST FIPS-205 (draft) from august 2023:
 *                nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.205.ipd.pdf
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

#define ESLIB_SLHDSA_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "ESLib.h"
#include "ESLib_t.h"
#include "ESLib_Helper.h"

/* actCLib includes */
#include "actSLHDSA.h"
#include "actSLHDSA_BuildingFct.h"

#if (VSECPRIM_SLHDSA_SHA256_128_S_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

/* Check that 64 bit type is supported by platform. */
# ifndef ACT_PLATFORM_UINT64_AVAILABLE
#  error ACT_PLATFORM_UINT64_AVAILABLE must be defined
# endif

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if defined ACT_PLATFORM_UINT64_AVAILABLE

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  esl_checkSizeSLHDSA()
 *********************************************************************************************************************/
/*! \brief          This function checks the size of input array parameters.
 *  \details        This function checks the size of the
 *                  - public key
 *                  - signature
 *                  on esl-level, depending on the version.
 *  \param[in]      dataName      Flag for the length to check. There is the choice between
 *                                - ESL_SLHDSA_FLAG_SIGNATURE
 *                                - ESL_SLHDSA_FLAG_PUBLIC_KEY
 *  \param[in]      version       Flag for the version. Currently, only ESL_SLHDSA_VERSION_128S is supported.
 *  \param[in]      length        Length corresponding to dataName.
 *  \return         - ESL_ERC_ERROR      if the length does not corresponds to the expected length.
 *                  - ESL_ERC_NO_ERROR   if the length corresponds to the expected length.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_checkSizeSLHDSA(
  const eslt_Byte dataName,
  const eslt_SLHDSA_Version version,
  const eslt_Length length);

/**********************************************************************************************************************
 *  esl_initParametersSLHDSA()
 *********************************************************************************************************************/
/*! \brief          This function sets the main parameters in the workspace.
 *  \details        -
 *  \param[in,out]  workSpace      (in)  Pointer to the workspace.
 *                                 (out) Pointer to the workspace with initialized main parameters.
 *  \pre            Pointer must be valid.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(void) esl_initParametersSLHDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceVerifySLHDSA) workSpace);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  esl_checkSizeSLHDSA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_checkSizeSLHDSA(
  const eslt_Byte dataName,
  const eslt_SLHDSA_Version version,
  const eslt_Length length)
{
  eslt_ErrorCode retVal = ESL_ERC_ERROR;
  eslt_Length expectedLength = 0u;

  switch (dataName)
  {
  case ESL_SLHDSA_FLAG_SIGNATURE:
#  if (ESL_SLHDSA_MULTIPLE_VERSION_ENABLED == STD_ON)
    if (version == ESL_SLHDSA_VERSION_128S)
#  endif
    {
      expectedLength = ESL_SLHDSA_SIGNATURE_LENGTH_128S;
    }
    break;
  case ESL_SLHDSA_FLAG_PUBLIC_KEY:
#  if (ESL_SLHDSA_MULTIPLE_VERSION_ENABLED == STD_ON)
    if (version == ESL_SLHDSA_VERSION_128S)
#  endif
    {
      expectedLength = ESL_SLHDSA_PK_LENGTH_128S;
    }
    break;
  default:
    /* Never happens */
    break;
  }

  if (length == expectedLength)
  {
    retVal = ESL_ERC_NO_ERROR;
  }

  VSECPRIM_DUMMY_STATEMENT_CONST(version);

  return retVal;
}

/**********************************************************************************************************************
 *  esl_initParametersSLHDSA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_LOCAL_FUNC(void) esl_initParametersSLHDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceVerifySLHDSA) workSpace)
{
  switch (workSpace->wsSLHDSA.parameters.version)
  {
  case ESL_SLHDSA_VERSION_128S:
    workSpace->wsSLHDSA.parameters.mainParameter = ESL_SLHDSA_MAIN_PARAMETER_128S;
    workSpace->wsSLHDSA.parameters.forsTreeHeight = ESL_SLHDSA_FORS_HEIGHT_128S;
    workSpace->wsSLHDSA.parameters.forsNbrTrees = ESL_SLHDSA_FORS_NUMBER_TREES_128S;
    workSpace->wsSLHDSA.parameters.hyperTreeNbrLayers = ESL_SLHDSA_HT_NUMBER_LAYER_128S;
    workSpace->wsSLHDSA.parameters.xmssTreeHeight = ESL_SLHDSA_XMSS_HEIGHT_128S;
    workSpace->wsSLHDSA.parameters.digestLength = ESL_SLHDSA_DIGEST_LENGTH_128S;
    break;
  default:
    /* Never happens */
    break;
  }

  switch (workSpace->wsSLHDSA.parameters.hashID)
  {
  case ESL_SLHDSA_HASH_ID_SHA2_256:
    workSpace->wsSLHDSA.parameters.hashSize = ESL_SLHDSA_HASH_SIZE_SHA2_256;
    break;
  default:
    /* Never happens */
    break;
  }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  esl_initVerifySLHDSA()
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
VSECPRIM_FUNC(eslt_ErrorCode) esl_initVerifySLHDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceVerifySLHDSA) workSpace,
  const eslt_SLHDSA_Version version,
  const eslt_SLHDSA_HashAlgorithm hashID)
{
  eslt_ErrorCode retVal = ESL_ERC_PARAMETER_INVALID;

  if (workSpace == NULL_PTR)
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* Check workspace header validity */
  else if ((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_SIZEOF_WS_SLHDSA)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    /* retVal already set */
  }
  else if ((version != ESL_SLHDSA_VERSION_128S) || (hashID != ESL_SLHDSA_HASH_ID_SHA2_256))
  {
    retVal = ESL_ERC_INPUT_INVALID;
  }

  else
  {
    /* Set workspace */
    workSpace->wsSLHDSA.parameters.version = version;
    workSpace->wsSLHDSA.parameters.hashID = hashID;
    esl_initParametersSLHDSA(workSpace);

    retVal = ESL_ERC_NO_ERROR;
    /* set workSpace state */
    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_SLHDSA); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  esl_verifySLHDSA()
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
VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySLHDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceVerifySLHDSA) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) message,
  const eslt_Length messageSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey,
  const eslt_Length publicKeySize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) signature,
  const eslt_Length signatureSize)
{
  /* Variables */
  eslt_ErrorCode retVal = ESL_ERC_ERROR;  /* PRQA S 2982 */ /* MD_VSECPRIM_2.2 */

  /* Validate pointers */
  if ((workSpace == NULL_PTR) || (message == NULL_PTR) || (signature == NULL_PTR) || (publicKey == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* Check workspace and states - retVal is being assigned */
  else if (ESL_ERC_NO_ERROR != (retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_SLHDSA, ESL_WST_ALGO_SLHDSA))) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_P2CONST_PARAM */
  {
    /* intentionally left empty, because retVal has already been set */
  }
  else if ((messageSize == 0u)
            || (esl_checkSizeSLHDSA(ESL_SLHDSA_FLAG_SIGNATURE, workSpace->wsSLHDSA.parameters.version, signatureSize) == ESL_ERC_ERROR)
            || (esl_checkSizeSLHDSA(ESL_SLHDSA_FLAG_PUBLIC_KEY, workSpace->wsSLHDSA.parameters.version, publicKeySize) == ESL_ERC_ERROR))
  {
    retVal = ESL_ERC_INVALID_LENGTH;
  }
  else
  {
    /* Variables for else path */
    actRETURNCODE actRetVal = actEXCEPTION_UNKNOWN;  /* PRQA S 2982 */ /* MD_VSECPRIM_2.2 */
    eslt_Byte digest[ESL_SLHDSA_DIGEST_LENGTH_MAX];
    actMemset(digest, 0u, ESL_SLHDSA_DIGEST_LENGTH_MAX);

    retVal = ESL_ERC_NO_ERROR;

    Esl_MemCpyByteArray(workSpace->wsSLHDSA.pkSeed, publicKey,
                                                        workSpace->wsSLHDSA.parameters.mainParameter);
    Esl_MemCpyByteArray(workSpace->wsSLHDSA.pkRoot, &publicKey[workSpace->wsSLHDSA.parameters.mainParameter],
                                                        workSpace->wsSLHDSA.parameters.mainParameter);

    /* initialize the digest computation */
    actSLHDSAinitHashMessage(&(workSpace->wsSLHDSA), &(signature[0u]), workSpace->header.watchdog);

    actSLHDSAupdateHashMessage(&(workSpace->wsSLHDSA), message, messageSize, workSpace->header.watchdog);

    /* Get the digest from the message, the randomizer and the public key */
    actSLHDSAfinalizeHashMessage(&(workSpace->wsSLHDSA), &signature[0u], digest, workSpace->header.watchdog);

    /* Verify the digest */
    actRetVal = actSLHDSAVerify(&(workSpace->wsSLHDSA), signature, digest, workSpace->header.watchdog);

    switch (actRetVal)
    {
      case actOK:
        /* retVal already set */
        break;
      case actVERIFICATION_FAILED:
        retVal = ESL_ERC_SIGNATURE_INVALID;
        break;
      default:
        retVal = ESL_ERC_ERROR;
        break;
    }

    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsSLHDSA); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
  }
  return retVal;
}

# endif /* defined ACT_PLATFORM_UINT64_AVAILABLE */

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_SLHDSA_SHA256_128_S_ENABLED == STD_ON) */
/**********************************************************************************************************************
 *  END OF FILE: ESLib_SLHDSA.c
 *********************************************************************************************************************/
