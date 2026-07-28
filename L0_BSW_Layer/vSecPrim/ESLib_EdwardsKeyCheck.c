/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  ESLib_EdwardsKeyCheck.c
 *        \brief  Key Check implementation for Edwardscurve Ed448 and Ed25519.
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

#define ESLIB_EDWARDSKEYCHECK_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "ESLib_Config.h"
#include "ESLib.h"
#include "ESLib_Helper.h"

/* actCLib includes */
#include "actIEdCheckKey.h"

#if (VSECPRIM_EDDSA_ENABLED == STD_ON)

# ifndef ESL_SUPPORT_CURVE25519
#  error "Curve25519 Support must be enabled"
# endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  esl_initKeyCheckEdwards()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_initKeyCheckEdwards(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEdKeyCheck) workspace,
  const eslt_Size16 curve)
{
  /* Check workspace header validity */
  eslt_ErrorCode retVal = ESL_ERC_ERROR;
  eslt_ErrorCode validCurve = ESL_ERC_CURVE_NOT_SUPPORTED;

  if (workspace == NULL_PTR)
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeader(&workspace->header, ESL_SIZEOF_WS_EDKEYCHECK)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    /* retVal already set */
  }
  else
  {
# if (VSECPRIM_ECDSA_25519_ENABLED == STD_ON)
    if (curve == ESL_CURVE25519)
    {
      validCurve = ESL_ERC_NO_ERROR;
    }
# endif
# if (VSECPRIM_EDDSA_448_ENABLED == STD_ON)
    if (curve == ESL_CURVE448)
    {
      validCurve = ESL_ERC_NO_ERROR;
    }
# endif

    if (validCurve == ESL_ERC_NO_ERROR)
    {
      /* Initialize actCLib Ed25519 respectively Ed448 */
      workspace->wsEdKeyCheck.curveId = curve; /* SBSW_VSECPRIM_WRITE_POINTER */
      actEdinitCheckKey(&workspace->wsEdKeyCheck); /* SBSW_VSECPRIM_CALL_FUNCTION */

      /* Set workSpace state */
      esl_SetWorkspaceStatus(&workspace->header, ESL_WST_ALGO_EDWARDS_KEYCHECK); /* SBSW_VSECPRIM_CALL_FUNCTION */
    }
    else
    {
      retVal = ESL_ERC_CURVE_NOT_SUPPORTED;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  esl_privateKeyCheckEdwards()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_privateKeyCheckEdwards(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceEdKeyCheck) workspace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) privateKey,
  const eslt_Length privateKeyLength)
{
  eslt_ErrorCode retVal = ESL_ERC_ERROR;
  actRETURNCODE actRetVal = actEXCEPTION_PRIVKEY;

  /* Check for any null pointers */
  if ((workspace == NULL_PTR) || (privateKey == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workspace->header, ESL_SIZEOF_WS_EDKEYCHECK, ESL_WST_ALGO_EDWARDS_KEYCHECK)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
  {
    /* retVal already set */
  }
  else
  {
    actRetVal = actEdCheckValidityOfPrivateKey(&workspace->wsEdKeyCheck, privateKey, privateKeyLength); /* SBSW_VSECPRIM_CALL_FUNCTION */
    if (actRetVal != actOK)
    {
      if (actRetVal == actEXCEPTION_INPUT_LENGTH)
      {
        retVal = ESL_ERC_INPUT_INVALID;
      }
      else /* (actRetVal == actEXCEPTION_PUBKEY) */
      {
        retVal = ESL_ERC_KEY_INVALID;
      }
    }
    else
    {
      retVal = ESL_ERC_NO_ERROR;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  esl_publicKeyCheckEdwards()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_publicKeyCheckEdwards(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEdKeyCheck) workspace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey,
  const eslt_Length publicKeyLength)
{
  eslt_ErrorCode retVal = ESL_ERC_ERROR;
  actRETURNCODE actRetVal = actEXCEPTION_PUBKEY;

  /* Check for any null pointers */
  if ((workspace == NULL_PTR) || (publicKey == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workspace->header, ESL_SIZEOF_WS_EDKEYCHECK, ESL_WST_ALGO_EDWARDS_KEYCHECK)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
  {
    /* retVal already set */
  }
  else
  {
    actRetVal = actEdCheckValidityOfPublicKey(&workspace->wsEdKeyCheck, publicKey, publicKeyLength, workspace->header.watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
    if (actRetVal != actOK)
    {
      if (actRetVal == actEXCEPTION_INPUT_LENGTH)
      {
        retVal = ESL_ERC_INPUT_INVALID;
      }
      else /* (actRetVal == actEXCEPTION_PUBKEY) or (actRetVal == actEXCEPTION_UNKNOWN) */
      {
        retVal = ESL_ERC_KEY_INVALID;
      }
    }
    else
    {
      retVal = ESL_ERC_NO_ERROR;
    }
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_EDDSA_ENABLED == STD_ON) */
/**********************************************************************************************************************
 *  END OF FILE: ESLib_EdwardsKeyCheck.c
 *********************************************************************************************************************/
