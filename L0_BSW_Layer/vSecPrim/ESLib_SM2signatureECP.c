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
/*!        \file  ESLib_SM2signatureECP.c
 *         \unit  es_SM2
 *        \brief  SM2 signature implementation based on ECP.
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

#define ESLIB_SM2SIGNATUREECP_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "ESLib.h"
#include "ESLib_types.h"
#include "ESLib_Helper.h"

/* actCLib includes */
#include "actISM2signature.h"

#if (VSECPRIM_SM2_SIGNATURE_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  esl_initSignSM2_ECP()
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
 */
 /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignSM2_ECP(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSM2) workSpace,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomainExt) domainExt,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccSpeedUpExt) speedUpExt)
{
  eslt_ErrorCode retVal;
  actRETURNCODE result;

  /* validate parameters */
  if ((workSpace == NULL_PTR) || (domain == NULL_PTR) || (domainExt == NULL_PTR) || (speedUpExt == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_SIZEOF_WS_SM2)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
  {
    /* retVal was already set */
  }
  else
  {
    /* initialize actCLib SM2 signature */
    workSpace->wsSM2.phase  = ESL_SM2_PHASE_USERINFO;
    workSpace->wsSM2.domain = domain;
    result = actSM2InitSign(&workSpace->wsSM2, workSpace->header.size, domain, domainExt, speedUpExt);
    if (result != actOK)
    {
      if (result == actEXCEPTION_MEMORY)
      {
        retVal = ESL_ERC_WS_TOO_SMALL;
      }
      else if (result == actEXCEPTION_DOMAIN)
      {
        retVal = ESL_ERC_ECC_DOMAIN_INVALID;
      }
      else if (result == actEXCEPTION_DOMAIN_EXT)
      {
        retVal = ESL_ERC_ECC_DOMAINEXT_INVALID;
      }
      else if (result == actEXCEPTION_SPEEDUP_EXT)
      {
        retVal = ESL_ERC_ECC_SPEEDUPEXT_INVALID;
      }
      else /* if (actEXCEPTION_INPUT_LENGTH == result) */
      {
        retVal = ESL_ERC_INPUT_INVALID;
      }
    }
    else
    {
      /* set workSpace state */
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_SM2);
      retVal = ESL_ERC_NO_ERROR;
    }
  }
  return retVal;
}

/***********************************************************************************************************************
 *  esl_addUserInfoSM2_ECP()
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
 */
 /* PRQA S 6030, 6080 1 */ /* MD_MSR_STMIF, MD_MSR_STCYC */
VSECPRIM_FUNC(eslt_ErrorCode) esl_addUserInfoSM2_ECP(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSM2) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) userInfo,
  const eslt_Length userInfoLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) id,
  const eslt_Length idLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyX,
  const eslt_Length publicKeyXLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyY,
  const eslt_Length publicKeyYLength)
{
  eslt_ErrorCode retVal;

  /* if the userInfo is not given, then it must be calculated from the public key coordinates */
  if ((workSpace == NULL_PTR) || ((userInfo == NULL_PTR) && ((publicKeyX == NULL_PTR) || (publicKeyY == NULL_PTR))))
  {
      retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_SM2, ESL_WST_ALGO_SM2)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
  {
    /* retVal has already been set */
  }
  else if ((userInfo == NULL_PTR) && (userInfoLength > 0u))
  {
    retVal = ESL_ERC_INVALID_LENGTH;
  }
  else if ((userInfo != NULL_PTR) && (userInfoLength < ESL_SIZEOF_SM3_DIGEST))
  {
    retVal = ESL_ERC_INVALID_LENGTH;
  }
  else if ((userInfo == NULL_PTR) && ((id == NULL_PTR) && (idLength > 0u)))
  {
    retVal = ESL_ERC_INVALID_LENGTH;
  }
  else if ((userInfo == NULL_PTR) && (id != NULL_PTR) && ((idLength > ESL_SIZEOF_SM2_MAXID) || ((idLength % 8u) != 0u)))
  {
    retVal = ESL_ERC_INVALID_LENGTH;
  }
  else
  {
    eslt_Length expectedPublicKeySize = (eslt_Length) workSpace->wsSM2.eccWorkspace.baseData.Curve.p_field.m_byte_length;

    VSECPRIM_P2VAR_PARA(actSM2STRUCT) sm2 = &workSpace->wsSM2;
    if ((sm2->phase & ESL_SM2_PHASE) != ESL_SM2_PHASE_USERINFO)
    {
      retVal = ESL_ERC_WS_STATE_INVALID;
    }
    else if ((userInfo == NULL_PTR) && ((publicKeyXLength < expectedPublicKeySize) || (publicKeyYLength < expectedPublicKeySize)))
    {
      retVal = ESL_ERC_INVALID_LENGTH;
    }
    else
    {
      if (id == NULL_PTR)
      {
        actSM2AddUserInfo(sm2, userInfo, id, 0u, publicKeyX, publicKeyY, workSpace->header.watchdog);
      }
      else
      {
        actSM2AddUserInfo(sm2, userInfo, id, idLength, publicKeyX, publicKeyY, workSpace->header.watchdog);
      }

      /* retVal has already been set */

      /* update phase */
      sm2->phase = ESL_SM2_PHASE_MESSAGE;
    }
  }
  return retVal;
}

/***********************************************************************************************************************
 *  esl_updateMessageSM2_ECP()
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
VSECPRIM_FUNC(eslt_ErrorCode) esl_updateMessageSM2_ECP(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSM2) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) message,
  const eslt_Length messageLength)
{
  eslt_ErrorCode retVal;
  actRETURNCODE result;
  /* validate parameters */
  if ((workSpace == NULL_PTR) || (message == NULL_PTR))
  {
    retVal =  ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_SM2, ESL_WST_ALGO_SM2)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
  {
    /* retVal has already been set */
  }
  else
  {
    VSECPRIM_P2VAR_PARA(actSM2STRUCT) sm2 = &workSpace->wsSM2;

    /* verify that current phase IS "MESSAGE" */
    if ((sm2->phase & ESL_SM2_PHASE) != ESL_SM2_PHASE_MESSAGE)
    {
      retVal =  ESL_ERC_WS_STATE_INVALID;
    }
    else
    {
      /* update message hash */
      result = actSM2UpdateMessage(sm2, message, messageLength, workSpace->header.watchdog);
      if (result != actOK)
      {
        retVal =  ESL_ERC_TOTAL_LENGTH_OVERFLOW;
      }
    }
  }
  return retVal;
}

/***********************************************************************************************************************
 *  esl_signSM2_ECP()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
 /* PRQA S 6030, 6080 1 */ /* MD_MSR_STMIF, MD_MSR_STCYC */
VSECPRIM_FUNC(eslt_ErrorCode) esl_signSM2_ECP(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSM2) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) privateKey,
  const eslt_Length privateKeyLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) signatureR,
  VSECPRIM_P2VAR_PARA(eslt_Length) signatureRLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) signatureS,
  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSLength)
{
  eslt_ErrorCode retVal;
  actRETURNCODE result;

  if ((workSpace == NULL_PTR) || (privateKey == NULL_PTR) || (signatureR == NULL_PTR) || (signatureS == NULL_PTR) || (signatureSLength == NULL_PTR) || (signatureRLength == NULL_PTR))
  {
      retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_SM2, ESL_WST_ALGO_SM2)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
  {
    /* retVal was already set */
  }
  else
  {
    eslt_Length expectedSize = (eslt_Length) workSpace->wsSM2.eccWorkspace.baseData.Curve.n_field.m_byte_length;

    /* verify that current phase IS "MESSAGE" */
    if (ESL_SM2_PHASE_MESSAGE != (((&workSpace->wsSM2))->phase & ESL_SM2_PHASE))
    {
      retVal = ESL_ERC_WS_STATE_INVALID;
    }
    else if((privateKeyLength < expectedSize))
    {
      retVal = ESL_ERC_INVALID_LENGTH;
    }
    else if((*signatureRLength < expectedSize) || (*signatureSLength < expectedSize))
    {
      retVal = ESL_ERC_BUFFER_TOO_SMALL;
    }
    else
    {
      result = actSM2Sign(&workSpace->wsSM2, privateKey, signatureR, signatureS, workSpace->header.watchdog);
      if (result != actOK)
      {
        if (result == actEXCEPTION_PRIVKEY)
        {
          retVal = ESL_ERC_ECC_PRIVKEY_INVALID;
        }
        else if (result == actEXCEPTION_UNKNOWN)
        {
          retVal = ESL_ERC_ECC_INTERNAL_ERROR;
        }
        else if (result == actEXCEPTION_LENGTH)
        {
          retVal = ESL_ERC_INVALID_LENGTH;
        }
        else if (result == actEXCEPTION_RANDOM)
        {
          retVal = ESL_ERC_RNG_FAILED;
        }
        else
        {
          /* Default case to map all remaining error codes. */
          retVal = ESL_ERC_ERROR;
        }
      }
      else
      {
        /* retVal has already been set */
        *signatureRLength = expectedSize; /* SBSW_VSECPRIM_WRITE_POINTER */
        *signatureSLength = expectedSize; /* SBSW_VSECPRIM_WRITE_POINTER */
      }
    }
    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsSM2); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  }
  return retVal;
}

/***********************************************************************************************************************
 *  esl_initVerifySM2_ECP()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
 /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
VSECPRIM_FUNC(eslt_ErrorCode) esl_initVerifySM2_ECP (
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSM2) workSpace,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomainExt) domainExt)
{
  actRETURNCODE result;
  eslt_ErrorCode retVal;
  /* validate parameters */
  if ((workSpace == NULL_PTR) || (domain == NULL_PTR) || (domainExt == NULL_PTR))
  {
      retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_SIZEOF_WS_SM2)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
  {
    /* retVal was already set */
  }
  else
  {
    /* initialize actCLib SM2 verification */
    (&workSpace->wsSM2)->phase  = ESL_SM2_PHASE_USERINFO;
    (&workSpace->wsSM2)->domain = domain;

    result = actSM2InitVerify(&workSpace->wsSM2, workSpace->header.size, domain, domainExt);
    if (actOK != result)
    {
      if (result == actEXCEPTION_MEMORY)
      {
        retVal = ESL_ERC_WS_TOO_SMALL;
      }
      else if (result == actEXCEPTION_DOMAIN)
      {
        retVal = ESL_ERC_ECC_DOMAIN_INVALID;
      }
      else /* (actEXCEPTION_DOMAIN_EXT == result) */
      {
        retVal = ESL_ERC_ECC_DOMAINEXT_INVALID;
      }
    }
    else
    {
      retVal = ESL_ERC_NO_ERROR;
      /* set workSpace state */
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_SM2);
    }
  }
  return retVal;
}

/***********************************************************************************************************************
 *  esl_verifySM2_ECP()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
 /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySM2_ECP(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSM2) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyX,
  const eslt_Length publicKeyXLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyY,
  const eslt_Length publicKeyYLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) signatureR,
  const eslt_Length signatureRLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) signatureS,
  const eslt_Length signatureSLength)
{
  eslt_ErrorCode retVal;
  actRETURNCODE result;

  if ((workSpace == NULL_PTR) || (publicKeyX == NULL_PTR) || (publicKeyY == NULL_PTR) || (signatureR == NULL_PTR) || (signatureS == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_SM2, ESL_WST_ALGO_SM2)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
  {
    /* retVal was already set */
  }
  else
  {
    eslt_Length expectedPublicKeySize = (eslt_Length) workSpace->wsSM2.eccWorkspace.baseData.Curve.p_field.m_byte_length;
    eslt_Length expectedSignatureSize = (eslt_Length) workSpace->wsSM2.eccWorkspace.baseData.Curve.n_field.m_byte_length;

    /* verify that current phase IS "MESSAGE" */
    if ((((&workSpace->wsSM2))->phase & ESL_SM2_PHASE) != ESL_SM2_PHASE_MESSAGE)
    {
      retVal = ESL_ERC_WS_STATE_INVALID;
    }
    else if((publicKeyXLength < expectedPublicKeySize) || (publicKeyYLength < expectedPublicKeySize) || (signatureRLength < expectedSignatureSize) || (signatureSLength < expectedSignatureSize))
    {
      retVal = ESL_ERC_INVALID_LENGTH;
    }
    else
    {
      /* call actCLib SM2 signature */
      result = actSM2Verify(&workSpace->wsSM2, publicKeyX, publicKeyY, signatureR, signatureS, workSpace->header.watchdog);
      if (result != actOK)
      {
        if (result == actEXCEPTION_PUBKEY)
        {
          retVal = ESL_ERC_ECC_PUBKEY_INVALID;
        }
        else if (result == actEXCEPTION_UNKNOWN)
        {
          retVal = ESL_ERC_ECC_INTERNAL_ERROR;
        }
        else if (result == actVERIFICATION_FAILED)
        {
          retVal = ESL_ERC_ECC_SIGNATURE_INVALID;
        }
        else
        {
          /* Default case to map all remaining error codes. */
          retVal = ESL_ERC_ERROR;
        }
      }
      else
      {
        retVal = ESL_ERC_NO_ERROR;
      }
    }
    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsSM2); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  }
  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_SM2_SIGNATURE_ENABLED == STD_ON) */

/***********************************************************************************************************************
 *  END OF FILE: ESLib_SM2signatureECP.c
 **********************************************************************************************************************/
