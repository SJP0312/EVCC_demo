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
/*!        \file  ESLib_EdwardsDSA.c
 *        \brief  EdwardsDSA implementation.
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

#define ESLIB_EDWARDSDSA_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "ESLib_Config.h"
#include "ESLib.h"
#include "ESLib_Helper.h"
#include "ESLib_EdDSA_Helper.h"

/* actCLib includes */
#include "actIEdDSA.h"

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
 *  esl_initEdwardsDSA()
 **********************************************************************************************************************/
/*! \brief         Initialize EdwardsDSA.
 *  \details       This function initializes the Ed25519 or Ed448 curve.
 *  \param[in,out] workSpace  Pointer to initialized workspace buffer
 *  \param[in]      curve identifier -  underlying curve; supports
 *                                     - ESL_CURVE25519
 *                                     - ESL_CURVE448
 *  \param[in]      instance  EdDSA instance to use; one of
 *                            - ESL_INSTANCE_Ed25519
 *                            - ESL_INSTANCE_Ed25519CTX
 *                            - ESL_INSTANCE_Ed25519PH
 *                            - ESL_INSTANCE_Ed448
 *                            - ESL_INSTANCE_Ed448PH
 *  \param[in]     context       Context buffer pointer
 *  \param[in]     contextLength Context buffer length
 *  \return        ESL_ERC_NO_ERROR               Operation successful
 *                 ESL_ERC_PARAMETER_INVALID      Input parameter is NULL
 *                 ESL_ERC_CURVE_NOT_SUPPORTED    Requested curve is not supported
 *                 ESL_ERC_WS_TOO_SMALL           work space too small
 *  \pre           Workspace needs to be initialized.
 *  \context       TASK
 *  \reentrant     TRUE, for different workspaces
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initEdwardsDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEdDSA) workSpace,
  const eslt_Size16 curve,
  const eslt_Byte instance,
  VSECPRIM_P2CONST_PARA(eslt_Byte) context,
  const eslt_Length contextLength);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  esl_initEdwardsDSA()
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
VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initEdwardsDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEdDSA) workSpace,
  const eslt_Size16 curve,
  const eslt_Byte instance,
  VSECPRIM_P2CONST_PARA(eslt_Byte) context,
  const eslt_Length contextLength)
{
  /* Check workspace header validity */
  eslt_ErrorCode retVal;

  if (workSpace == NULL_PTR)
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_SIZEOF_WS_EDDSA)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    /* retVal already set */
  }
  else
  {
    /* Initialize actCLib Ed25519 respectively Ed448 */
    (void)actEdDSAInit(&workSpace->wsEdDSABuffer, instance, context, contextLength, curve); /* SBSW_VSECPRIM_CALL_FUNCTION */

    /* Set workSpace state */
    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_EDWARDS_DSA); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  esl_initSignEdwardsDSA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignEdwardsDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEdDSA) workSpace,
  eslt_Size16 curve,
  const eslt_Byte instance,
  VSECPRIM_P2CONST_PARA(eslt_Byte) context,
  const eslt_Length contextLength)
{
  /* Check instance context validity */
  eslt_ErrorCode retVal = esl_checkInstanceContext(instance, context, contextLength, curve); /* SBSW_VSECPRIM_CALL_FUNCTION */

  if (retVal == ESL_ERC_NO_ERROR)
  {
    /* Initialize EdwardsDSA */
    retVal = esl_initEdwardsDSA(workSpace, curve, instance, context, contextLength); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  esl_signEdwardsDSA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_signEdwardsDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEdDSA) workSpace, /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  VSECPRIM_P2CONST_PARA(eslt_Byte) input,
  const eslt_Length inputLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) secretKey,
  const eslt_Length secretKeyLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey,
  const eslt_Length publicKeyLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) signature,
  VSECPRIM_P2VAR_PARA(eslt_Length) signatureLength)
{
  eslt_ErrorCode retVal;

  /* Validate pointers */
  if ((NULL_PTR == workSpace) || ((NULL_PTR == input) && (inputLength != 0u)) || (NULL_PTR == secretKey) || (NULL_PTR == signature) || (NULL_PTR == signatureLength))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if (ESL_ERC_NO_ERROR != (retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_EDDSA, ESL_WST_ALGO_EDWARDS_DSA))) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_P2CONST_PARAM */
  {
    /* intentionally left empty, because retVal has already been set */
  }
  else
  {
    eslt_Size16 curve = workSpace->wsEdDSABuffer.curveId;
    eslt_Length expectedSignatureLength = 0;
    eslt_Length expectedSecretKeyLength = 0;
    eslt_Length expectedPublicKeyLength = 0;
    /* differentiate between Ed25519 and Ed448 */
    switch (curve)
    {
# if (VSECPRIM_ECDSA_25519_ENABLED == STD_ON)
    case ESL_CURVE25519:
      expectedSecretKeyLength = ESL_SIZEOF_Ed25519_SECRET_KEY;
      expectedPublicKeyLength = ESL_SIZEOF_Ed25519_PUBLIC_KEY;
      expectedSignatureLength = ESL_SIZEOF_Ed25519_SIGNATURE;
      break;
# endif /* (VSECPRIM_ECDH_25519_ENABLED == STD_ON) */
# if (VSECPRIM_EDDSA_448_ENABLED == STD_ON)
    case ESL_CURVE448:
      expectedSecretKeyLength = ESL_SIZEOF_Ed448_SECRET_KEY;
      expectedPublicKeyLength = ESL_SIZEOF_Ed448_PUBLIC_KEY;
      expectedSignatureLength = ESL_SIZEOF_Ed448_SIGNATURE;
      break;
# endif /* (VSECPRIM_EDDH_448_ENABLED == STD_ON) */
    default: /* COV_VSECPRIM_MISRA_ADDITIONAL_STATEMENT */
      /* empty default: validity of curve was checked before */
      break;
    }
    retVal = esl_checkKeyLength(secretKeyLength, expectedSecretKeyLength);
    if (publicKey != NULL_PTR)
    {
      /* publicKeyLength = 0 is valid, when the public key is a null pointer. In this case it is generated from the secret key. */
      retVal |= esl_checkKeyLength(publicKeyLength, expectedPublicKeyLength);
    }
    if (retVal != ESL_ERC_NO_ERROR)
    {
      /* retVal is already set: ESL_ERC_INVALID_LENGTH */
    }
    else
    {
      retVal = esl_checkLengthRef(signatureLength, expectedSignatureLength); /* SBSW_VSECPRIM_CALL_FUNCTION */
    }

    if (retVal != ESL_ERC_NO_ERROR)
    {
      /* retVal has been assigned */
    }
    else
    {
      /* Sign given input */
      switch (actEdDSASign(&workSpace->wsEdDSABuffer, input, inputLength, secretKey, publicKey, signature, workSpace->header.watchdog)) /* SBSW_VSECPRIM_CALL_FUNCTION */
      {
      case actOK:
        *signatureLength = expectedSignatureLength; /* SBSW_VSECPRIM_WRITE_POINTER */
        break;
      case actEXCEPTION_LENGTH:
        /* SHA512 or SHAKE failure */
        retVal = ESL_ERC_TOTAL_LENGTH_OVERFLOW;
        break;
      default:
        /* Corresponds to case actEXCEPTION_UNKNOWN, i.e., attempted to invert 0.
         * Used to avoid an unreachable default branch */
        retVal = ESL_ERC_ERROR;
        break;
      }
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  esl_initVerifyEdwardsDSA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_initVerifyEdwardsDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEdDSA) workSpace,
  eslt_Size16 curve,
  const eslt_Byte instance,
  VSECPRIM_P2CONST_PARA(eslt_Byte) context,
  const eslt_Length contextLength)
{
  /* Check instance context validity */
  eslt_ErrorCode retVal = esl_checkInstanceContext(instance, context, contextLength, curve); /* SBSW_VSECPRIM_CALL_FUNCTION */

  if (retVal == ESL_ERC_NO_ERROR)
  {
    /* Initialize EdDSA */
    retVal = esl_initEdwardsDSA(workSpace, curve, instance, context, contextLength); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  esl_verifyEdwardsDSA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyEdwardsDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEdDSA) workSpace, /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  VSECPRIM_P2CONST_PARA(eslt_Byte) input,
  const eslt_Length inputLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey,
  const eslt_Length publicKeyLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) signature,
  const eslt_Length signatureLength)
{
  eslt_ErrorCode retVal;

  /* Validate provided pointers */
  if ((NULL_PTR == workSpace) || ((NULL_PTR == input) && (inputLength != 0u)) || (NULL_PTR == publicKey) || (NULL_PTR == signature))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* Check workspace state and validity */
  else if (ESL_ERC_NO_ERROR != (retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_Ed25519, ESL_WST_ALGO_EDWARDS_DSA))) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_P2CONST_PARAM */
  {
    /* retVal was already set */
  }
  else
  {
    eslt_Length expectedSignatureLength = 0;
    eslt_Length expectedPublicKeyLength = 0;
    /* differentiate between Ed25519 and Ed448 */
    switch (workSpace->wsEdDSABuffer.curveId)
    {
# if (VSECPRIM_ECDSA_25519_ENABLED == STD_ON)
    case ESL_CURVE25519:
      expectedSignatureLength = ESL_SIZEOF_Ed25519_SIGNATURE;
      expectedPublicKeyLength = ESL_SIZEOF_Ed25519_PUBLIC_KEY;
      break;
# endif /* (VSECPRIM_ECDH_25519_ENABLED == STD_ON) */
# if (VSECPRIM_EDDSA_448_ENABLED == STD_ON)
    case ESL_CURVE448:
      expectedSignatureLength = ESL_SIZEOF_Ed448_SIGNATURE;
      expectedPublicKeyLength = ESL_SIZEOF_Ed448_PUBLIC_KEY;
      break;
# endif /* (VSECPRIM_EDDH_448_ENABLED == STD_ON) */
    default: /* COV_VSECPRIM_MISRA_ADDITIONAL_STATEMENT */
      /* empty default: validity of curve was checked before */
      break;
    }
    retVal = esl_checkKeyLength(publicKeyLength, expectedPublicKeyLength);
    retVal |= esl_checkKeyLength(signatureLength, expectedSignatureLength);
    /* In case of an error, the return value retVal = ESL_ERC_INVALID_LENGTH is set here. */

    if (retVal == ESL_ERC_NO_ERROR)
    {
      /* Perform EdDSA verification */
      switch (actEdDSAVerify(&workSpace->wsEdDSABuffer, input, inputLength, publicKey, signature, workSpace->header.watchdog)) /* SBSW_VSECPRIM_CALL_FUNCTION */
      {
      case actOK:
        /* retVal is already OK */
        break;
      case actEXCEPTION_LENGTH:
        /* SHA-512 length overflow or SHAKE failed */
        retVal = ESL_ERC_TOTAL_LENGTH_OVERFLOW;
        break;
      default:
        retVal = ESL_ERC_SIGNATURE_INVALID;
        break;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  esl_updateEdwardsDSA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_updateEdwardsDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEdDSA) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) input,
  const eslt_Length inputLength) /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
{
  eslt_ErrorCode retVal;
  if ((workSpace == NULL_PTR) || (input == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_EDDSA, ESL_WST_ALGO_EDWARDS_DSA)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_P2CONST_PARAM */
  {
    /* retVal was already set */
  }
  else
  {
    switch (actEdDSAUpdate(&workSpace->wsEdDSABuffer, input, inputLength, workSpace->header.watchdog)) /* SBSW_VSECPRIM_CALL_FUNCTION */
    {
      case actOK:
        /* nothing to do */
        break;
      case actEXCEPTION_ALGOID:
        /* stored instance != prehash */
        retVal = ESL_ERC_INPUT_INVALID;
        break;
      case actEXCEPTION_LENGTH:
        /* SHA-512 length overflow or SHAKE failed. */
        retVal = ESL_ERC_TOTAL_LENGTH_OVERFLOW;
        break;
      default:
        /* corresponds to case actEXCEPTION_MODE, i.e., SHAKE update failed
         * used to avoid an unreachable default branch */
        retVal = ESL_ERC_STATE_INVALID;
        break;
    }
  }
  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_EDDSA_ENABLED == STD_ON) */
/**********************************************************************************************************************
 *  END OF FILE: ESLib_EdwardsDSA.c
 *********************************************************************************************************************/
