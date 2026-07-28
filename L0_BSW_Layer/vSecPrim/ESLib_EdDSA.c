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
/*!        \file  ESLib_EdDSA.c
 *        \brief  EdDSA implementation.
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

#define ESLIB_EDDSA_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "ESLib_Config.h"
#include "ESLib.h"
#include "ESLib_Helper.h"
#include "ESLib_EdDSA_Helper.h"

/* actCLib includes */
#include "actIEdDSA.h"

#if (VSECPRIM_ECDSA_25519_ENABLED == STD_ON)

# ifndef ESL_SUPPORT_CURVE25519
#  error "Curve25519 Support must be enabled"
# endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  esl_validateKeyLengthEdDSA()
 **********************************************************************************************************************/
/*! \brief         Validate key length pointer.
 *  \details       This function validates the public key length pointer.
 *  \param[in]     secretKeyLength  Reference to the secret key length.
 *  \param[in]     publicKeyLength  Reference to the public key length.
 *  \return        ESL_ERC_NO_ERROR  Operation successful
 *                 ESL_ERC_PARAMETER_INVALID  Input parameter is NULL
 *                 ESL_ERC_WS_STATE_INVALID  Work space state invalid
 *  \pre           Workspace needs to be initialized.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_validateKeyLengthEdDSA(
  eslt_LengthConstRef secretKeyLength,
  eslt_LengthConstRef publicKeyLength);

/**********************************************************************************************************************
 *  esl_initEdDSA()
 **********************************************************************************************************************/
/*! \brief         Initialize EdDSA.
 *  \details       This function initializes the Ed25519 curve.
 *  \param[in,out] workSpace     Pointer to initialized workspace buffer
 *  \param[in]     curve         Curve identifier
 *  \param[in]     instance      Instance identifier
 *  \param[in]     context       Context buffer pointer
 *  \param[in]     contextLength Context buffer length
 *  \return        ESL_ERC_NO_ERROR            Operation successful
 *                 ESL_ERC_PARAMETER_INVALID   Input parameter is NULL
 *                 ESL_ERC_WS_STATE_INVALID    Work space state invalid
 *                 ESL_ERC_CURVE_NOT_SUPPORTED Requested curve is not supported
 *  \pre           Workspace needs to be initialized.
 *  \context       TASK
 *  \reentrant     TRUE, for different workspaces
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace,
  const eslt_Size16 curve,
  const eslt_Byte instance,
  VSECPRIM_P2CONST_PARA(eslt_Byte) context,
  const eslt_Length contextLength);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  esl_validateKeyLengthEdDSA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_validateKeyLengthEdDSA(eslt_LengthConstRef secretKeyLength, eslt_LengthConstRef publicKeyLength)
{
  /* Check validity of secretKeyLength pointer */
  eslt_ErrorCode retVal = esl_checkLengthRef(secretKeyLength, ESL_SIZEOF_Ed25519_SECRET_KEY); /* SBSW_VSECPRIM_CALL_FUNCTION */

  if (retVal == ESL_ERC_NO_ERROR)
  {
    /* Check validity of publicKeyLength pointer */
    retVal = esl_checkLengthRef(publicKeyLength, ESL_SIZEOF_Ed25519_PUBLIC_KEY); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  esl_initEdDSA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace,
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
  else if ((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_SIZEOF_WS_Ed25519)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    /* retVal already set */
  }
  /* Check if curve is supported */
  else if (curve != ESL_CURVE25519)
  {
    retVal = ESL_ERC_CURVE_NOT_SUPPORTED;
  }
  else
  {
    (void)actEdDSAInit(&workSpace->wsEdDSABuffer, instance, context, contextLength, curve); /* SBSW_VSECPRIM_CALL_FUNCTION */

    /* Provide backward compatible pointer */
    workSpace->wsEd25519 = (VSECPRIM_P2VAR_PARA(eslt_Byte))&(workSpace->wsEdDSABuffer); /* PRQA S 0310 */ /* MD_VSECPRIM_11.4 */ /* SBSW_VSECPRIM_WRITE_POINTER */

    /* Set workSpace state */
    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_Ed25519); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  esl_initSignEdDSA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace,
  eslt_Size16 curve,
  const eslt_Byte instance,
  VSECPRIM_P2CONST_PARA(eslt_Byte) context,
  const eslt_Length contextLength)
{
  /* Check instance context validity */
  /* Check if curve is supported */
  eslt_ErrorCode retVal = esl_checkInstanceContext(instance, context, contextLength, curve); /* SBSW_VSECPRIM_CALL_FUNCTION */

  if (retVal == ESL_ERC_NO_ERROR)
  {
    /* Initialize EdDSA */
    retVal = esl_initEdDSA(workSpace, curve, instance, context, contextLength); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  esl_signEdDSA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_signEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace, /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  VSECPRIM_P2CONST_PARA(eslt_Byte) input,
  eslt_Length inputLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) secretKey,
  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey,
  VSECPRIM_P2VAR_PARA(eslt_Byte) signature,
  VSECPRIM_P2VAR_PARA(eslt_Length) signatureLength)
{
  eslt_ErrorCode retVal;

  /* Validate pointers */
  if ((NULL_PTR == workSpace) || ((NULL_PTR == input) && (inputLength != 0u)) || (NULL_PTR == secretKey) || (NULL_PTR == signature) || (NULL_PTR == signatureLength))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if (ESL_ERC_NO_ERROR != esl_checkLengthRef(signatureLength, ESL_SIZEOF_Ed25519_SIGNATURE)) /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    retVal = ESL_ERC_BUFFER_TOO_SMALL;
  }
  /* Check workspace and states - retVal is being assigned */
  else if (ESL_ERC_NO_ERROR != (retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_Ed25519, ESL_WST_ALGO_Ed25519))) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_P2CONST_PARAM */
  {
    /* intentionally left empty, because retVal has already been set */
  }
  else
  {
    /* Sign given input */
    switch (actEdDSASign(&workSpace->wsEdDSABuffer, input, inputLength, secretKey, publicKey, signature, workSpace->header.watchdog)) /* SBSW_VSECPRIM_CALL_FUNCTION */
    {
    case actOK:
      *signatureLength = ESL_SIZEOF_Ed25519_SIGNATURE; /* SBSW_VSECPRIM_WRITE_POINTER */
      break;

    case actEXCEPTION_LENGTH:
      /* SHA512 failure */
      retVal = ESL_ERC_TOTAL_LENGTH_OVERFLOW;
      break;

    default:
      /* Corresponds to case actEXCEPTION_UNKNOWN, i.e., attempted to invert 0.
       * Used to avoid an unreachable default branch */
      retVal = ESL_ERC_ERROR;
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  esl_initVerifyEdDSA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_initVerifyEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace,
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
    retVal = esl_initEdDSA(workSpace, curve, instance, context, contextLength); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  esl_verifyEdDSA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace, /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  VSECPRIM_P2CONST_PARA(eslt_Byte) input,
  eslt_Length inputLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey,
  VSECPRIM_P2CONST_PARA(eslt_Byte) signature,
  eslt_Length signatureLength)
{
  eslt_ErrorCode retVal;

  /* Validate provided pointers */
  if ((NULL_PTR == workSpace) || ((NULL_PTR == input) && (inputLength != 0u)) || (NULL_PTR == publicKey) || (NULL_PTR == signature))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* Check length */
  else if (signatureLength < ESL_SIZEOF_Ed25519_SIGNATURE)
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* Check workspace state and validity */
  else if (ESL_ERC_NO_ERROR != (retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_Ed25519, ESL_WST_ALGO_Ed25519))) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_P2CONST_PARAM */
  {
    /* retVal was already set */
  }
  else
  {
    /* Perform EdDSA verification */
    switch(actEdDSAVerify(&workSpace->wsEdDSABuffer, input, inputLength, publicKey, signature, workSpace->header.watchdog)) /* SBSW_VSECPRIM_CALL_FUNCTION */
    {
      case actOK:
      {
        /* retVal is already OK */
        break;
      }
      case actEXCEPTION_LENGTH:
      {
        /* SHA-512 length overflow or hashing failed */
        retVal = ESL_ERC_TOTAL_LENGTH_OVERFLOW;
        break;
      }
      default:
      {
        retVal = ESL_ERC_SIGNATURE_INVALID;
        break;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  esl_updateEdDSA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_updateEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) input,
  eslt_Length inputLength) /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
{
  eslt_ErrorCode retVal;
  if ((workSpace == NULL_PTR) || (input == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_Ed25519, ESL_WST_ALGO_Ed25519)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_P2CONST_PARAM */
  {
    /* retVal was already set */
  }
  else
  {
    /* Update EdDSA calculation */
    switch(actEdDSAUpdate(&workSpace->wsEdDSABuffer, input, inputLength, workSpace->header.watchdog)) /* SBSW_VSECPRIM_CALL_FUNCTION */
    {
      case actOK:
      {
        /* nothing to do */
        break;
      }
      case actEXCEPTION_ALGOID:
      {
        /* stored instance != prehash */
        retVal = ESL_ERC_INPUT_INVALID;
        break;
      }
      case actEXCEPTION_LENGTH:
      {
        /* SHA-512 length overflow */
        retVal = ESL_ERC_TOTAL_LENGTH_OVERFLOW;
        break;
      }
      default:
      {
        retVal = ESL_ERC_WS_STATE_INVALID;
        break;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  esl_initGenerateKeyPairEdDSA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_initGenerateKeyPairEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace, /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  eslt_Size16 curve)
{
  /* Initialize EdDSA */
  return esl_initEdDSA(workSpace, curve, ESL_INSTANCE_Ed25519, NULL_PTR, 0); /* SBSW_VSECPRIM_CALL_FUNCTION */
}

/**********************************************************************************************************************
 *  esl_generateKeyPairEdDSA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyPairEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace, /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  VSECPRIM_P2VAR_PARA(eslt_Byte) secretKey,
  VSECPRIM_P2VAR_PARA(eslt_Length) secretKeyLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) publicKey,
  VSECPRIM_P2VAR_PARA(eslt_Length) publicKeyLength)
{
  eslt_ErrorCode retVal;

  /* Validate pointers */
  if ((workSpace == NULL_PTR) || (secretKey == NULL_PTR) || (secretKeyLength == NULL_PTR) || (publicKey == NULL_PTR) || (publicKeyLength == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* Validate key length - retVal variable is being assigned */
  else if (ESL_ERC_NO_ERROR != (retVal = esl_validateKeyLengthEdDSA(secretKeyLength, publicKeyLength))) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    /* retVal was already set */
  }
  /* Validate workSpace - retVal variable is being assigned */
  else if (ESL_ERC_NO_ERROR != (retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_Ed25519, ESL_WST_ALGO_Ed25519))) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_P2CONST_PARAM */
  {
    /* retVal was already set */
  }
  else
  {
    /* Generate key pair */
    if (actEd25519GenKeyPair(&workSpace->wsEdDSABuffer, secretKey, publicKey, workSpace->header.watchdog) == actOK) /* SBSW_VSECPRIM_CALL_FUNCTION */
    {
      *secretKeyLength = ESL_SIZEOF_Ed25519_SECRET_KEY; /* SBSW_VSECPRIM_WRITE_POINTER */
      *publicKeyLength = ESL_SIZEOF_Ed25519_PUBLIC_KEY; /* SBSW_VSECPRIM_WRITE_POINTER */
    }
    else
    {
      retVal = ESL_ERC_RNG_FAILED;
    }
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ECDSA_25519_ENABLED == STD_ON) */
/**********************************************************************************************************************
 *  END OF FILE: ESLib_EdDSA.c
 *********************************************************************************************************************/
