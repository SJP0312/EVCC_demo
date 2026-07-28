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
/*!        \file  ESLib_EdDH.c
 *        \brief  EdDH implementation.
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

#define ESLIB_EDDH_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "ESLib_Config.h"
#include "ESLib.h"

/* actCLib includes */
#include "actIXEdDH.h"

#if (VSECPRIM_EDDH_ENABLED == STD_ON)

# include "ESLib_Helper.h"
# include "ESLib_EdDSA_Helper.h"

# ifndef ESL_SUPPORT_CURVE25519
#  error "Curve25519 Support must be enabled"
# endif

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  esl_initEdDH()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_initEdDH(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEdDH) workSpace,
  eslt_Size16 curve)
{
  eslt_ErrorCode retVal, validCurve = ESL_ERC_ERROR;

  switch (curve)
  {
# if (VSECPRIM_ECDH_25519_ENABLED == STD_ON)
  case ESL_CURVE25519:
    validCurve = ESL_ERC_NO_ERROR;
    break;
# endif /* (VSECPRIM_ECDH_25519_ENABLED == STD_ON) */
# if (VSECPRIM_EDDH_448_ENABLED == STD_ON)
  case ESL_CURVE448:
    validCurve = ESL_ERC_NO_ERROR;
    break;
# endif /* (VSECPRIM_EDDH_448_ENABLED == STD_ON) */
  default:
    /* validity of curve has been check before */
    break;
  }

  if (workSpace == NULL_PTR)
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_SIZEOF_WS_EDDH)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    /* retVal already set */
  }
  else if (validCurve == ESL_ERC_ERROR)
  {
    retVal = ESL_ERC_CURVE_NOT_SUPPORTED;
  }
  else
  {
    VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEdDH) wsPtr = (VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEdDH)) workSpace;

    /* Initialize actCLib X25519 or X448 via actEdDHInit, respectively */
    wsPtr->wsEdDHBuffer.curveId = curve; /* SBSW_VSECPRIM_WRITE_POINTER */
    (void)actEdDHInit(&wsPtr->wsEdDHBuffer); /* SBSW_VSECPRIM_CALL_FUNCTION */

    /* Provide backward compatible pointer */
    workSpace->wsX25519 = (VSECPRIM_P2VAR_PARA(eslt_Byte))&(workSpace->wsEdDHBuffer); /* PRQA S 0310 */ /* MD_VSECPRIM_11.4 */ /* SBSW_VSECPRIM_WRITE_POINTER */

    /* Set workSpace state */
    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_EDDH); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  esl_generateEphemeralKeyPairEdDH()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
 /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
VSECPRIM_FUNC(eslt_ErrorCode) esl_generateEphemeralKeyPairEdDH(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEdDH) workSpace, /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  VSECPRIM_P2VAR_PARA(eslt_Byte) publicKey,
  VSECPRIM_P2VAR_PARA(eslt_Length) publicKeyLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) privateKey,
  VSECPRIM_P2VAR_PARA(eslt_Length) privateKeyLength)
{
  eslt_ErrorCode retVal;

  if ((workSpace == NULL_PTR) || (publicKey == NULL_PTR) || (publicKeyLength == NULL_PTR) || (privateKey == NULL_PTR) || (privateKeyLength == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_EDDH, ESL_WST_ALGO_EDDH)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_P2CONST_PARAM */
  {
    /* retVal was already set */
  }
  else
  {
    eslt_Size16 curve = workSpace->wsEdDHBuffer.curveId;
    eslt_Byte expectedPrivateKeySize = 0;
    eslt_Byte expectedPublicKeySize = 0;
    switch (curve)
    {
# if (VSECPRIM_ECDH_25519_ENABLED == STD_ON)
    case ESL_CURVE25519:
      expectedPublicKeySize = ESL_SIZEOF_X25519_PUBLIC_KEY;
      expectedPrivateKeySize = ESL_SIZEOF_X25519_PRIVATE_KEY;
      break;
# endif /* (VSECPRIM_ECDH_25519_ENABLED == STD_ON) */
# if (VSECPRIM_EDDH_448_ENABLED == STD_ON)
    case ESL_CURVE448:
      expectedPublicKeySize = ESL_SIZEOF_X448_PUBLIC_KEY;
      expectedPrivateKeySize = ESL_SIZEOF_X448_PRIVATE_KEY;
      break;
# endif /* (VSECPRIM_EDDH_448_ENABLED == STD_ON) */
    default: /* COV_VSECPRIM_MISRA_ADDITIONAL_STATEMENT */
      /* validity of curve has been check before */
      break;
    }
    if (ESL_ERC_NO_ERROR != (retVal = esl_checkLengthRef(publicKeyLength, expectedPublicKeySize))) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    {
      /* retVal already set */
    }
    else if (ESL_ERC_NO_ERROR != (retVal = esl_checkLengthRef(privateKeyLength, expectedPrivateKeySize))) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    {
      /* retVal already set */
    }
    else
    {
      /* Key pair generation */
      switch (actEdDHGenKeyPair(&workSpace->wsEdDHBuffer, publicKey, workSpace->header.watchdog)) /* SBSW_VSECPRIM_CALL_FUNCTION */
      {
      case actOK:
        *publicKeyLength = expectedPublicKeySize; /* SBSW_VSECPRIM_WRITE_POINTER */
         /* set private key and private key length */
        *privateKeyLength = expectedPrivateKeySize; /* SBSW_VSECPRIM_WRITE_POINTER */
        actMemCpyByteArray(privateKey, workSpace->wsEdDHBuffer.privateKey, (actU32)(expectedPrivateKeySize)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* MD_MSR_VStdLibCopy */ /* SBSW_VSECPRIM_FCT_CALL_P2CONST_PARAM */
        break;
      case actEXCEPTION_PRIVKEY:
        retVal = ESL_ERC_RNG_FAILED;
        break;
      default:
        retVal = ESL_ERC_UNRECOVERABLE_ERROR;
        break;
      }
    }
  }

  return retVal;
}
/**********************************************************************************************************************
 * esl_importStaticPrivateKeyEdDH()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_importStaticPrivateKeyEdDH(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEdDH) workSpace, /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  VSECPRIM_P2CONST_PARA(eslt_Byte) privateKey,
  const eslt_Length privateKeyLength)
{
  eslt_ErrorCode retVal;

  if ((workSpace == NULL_PTR) || (privateKey == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_EDDH, ESL_WST_ALGO_EDDH)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_P2CONST_PARAM */
  {
    /* retVal was already set */
  }
  else
  {
    eslt_Size16 curve = workSpace->wsEdDHBuffer.curveId;
    eslt_Byte expectedKeySize = 0;
    switch (curve)
    {

# if (VSECPRIM_ECDH_25519_ENABLED == STD_ON)
    case ESL_CURVE25519:
      expectedKeySize = ESL_SIZEOF_X25519_PRIVATE_KEY;
      break;
# endif /* (VSECPRIM_ECDH_25519_ENABLED == STD_ON) */
# if (VSECPRIM_EDDH_448_ENABLED == STD_ON)
    case ESL_CURVE448:
      expectedKeySize = ESL_SIZEOF_X448_PRIVATE_KEY;
      break;
# endif /* (VSECPRIM_EDDH_448_ENABLED == STD_ON) */
    default: /* COV_VSECPRIM_MISRA_ADDITIONAL_STATEMENT */
      /* validity of curve has been check before */
      break;
    }

    if ((ESL_ERC_NO_ERROR != (retVal = esl_checkKeyLength(privateKeyLength, expectedKeySize)))) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */
    {
      /* retVal already set */
    }
    else
    {
      /* Import private key */
      actEdDHImportPrivateKey(&workSpace->wsEdDHBuffer, privateKey, workSpace->header.watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 * esl_generateSharedSecretEdDH()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
 /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
VSECPRIM_FUNC(eslt_ErrorCode) esl_generateSharedSecretEdDH(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEdDH) workSpace, /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey, /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  const eslt_Length publicKeyLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) sharedSecret,
  VSECPRIM_P2VAR_PARA(eslt_Length) sharedSecretLength)
{
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;
  actRETURNCODE actRetVal = actOK;

  if ((workSpace == NULL_PTR) || (publicKey == NULL_PTR) || (sharedSecret == NULL_PTR) || (sharedSecretLength == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_EDDH, ESL_WST_ALGO_EDDH)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_P2CONST_PARAM */
  {
    /* retVal was already set */
  }
  else
  {
    eslt_Size16 curve = workSpace->wsEdDHBuffer.curveId;
    eslt_Byte expectedKeySize = 0;
    switch (curve)
    {
# if (VSECPRIM_ECDH_25519_ENABLED == STD_ON)
    case ESL_CURVE25519:
      expectedKeySize = ESL_SIZEOF_X25519_PUBLIC_KEY;
      break;
# endif /* (VSECPRIM_ECDH_25519_ENABLED == STD_ON) */
# if (VSECPRIM_EDDH_448_ENABLED == STD_ON)
    case ESL_CURVE448:
      expectedKeySize = ESL_SIZEOF_X448_PUBLIC_KEY;
      break;
# endif /* (VSECPRIM_EDDH_448_ENABLED == STD_ON) */
    default: /* COV_VSECPRIM_MISRA_ADDITIONAL_STATEMENT */
      /* validity of curve has been check before */
      break;
    }

    if (ESL_ERC_NO_ERROR != (retVal = esl_checkKeyLength(publicKeyLength, expectedKeySize))) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */
    {
      /* retVal already set */
    }
    else if (ESL_ERC_NO_ERROR != (retVal = esl_validateCommonSecretLength(workSpace->wsEdDHBuffer.curveId, sharedSecretLength))) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    {
      /* retVal already set */
    }
    else
    {
      /* Generate shared secret */
      actRetVal = actEdDHGenSecret(&workSpace->wsEdDHBuffer, publicKey, sharedSecret, workSpace->header.watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
      if (actRetVal == actOK)
      {
        switch (curve)
        {
# if (VSECPRIM_ECDH_25519_ENABLED == STD_ON)
        case ESL_CURVE25519:
          *sharedSecretLength = ESL_SIZEOF_X25519_SHARED_SECRET; /* SBSW_VSECPRIM_WRITE_POINTER */
          break;
# endif /* (VSECPRIM_ECDH_25519_ENABLED == STD_ON) */
# if (VSECPRIM_EDDH_448_ENABLED == STD_ON)
        case ESL_CURVE448:
          *sharedSecretLength = ESL_SIZEOF_X448_SHARED_SECRET; /* SBSW_VSECPRIM_WRITE_POINTER */
          break;
# endif /* (VSECPRIM_EDDH_448_ENABLED == STD_ON) */
        default: /* COV_VSECPRIM_MISRA_ADDITIONAL_STATEMENT */
          /* validity of curve has been check before */
          break;
        }
      }
      else
      {
        retVal = ESL_ERC_UNRECOVERABLE_ERROR;
      }
    }
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_EDDH_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  END OF FILE: ESLib_EdDH.c
 *********************************************************************************************************************/
