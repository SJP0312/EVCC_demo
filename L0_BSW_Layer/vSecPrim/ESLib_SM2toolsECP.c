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
/*!        \file  ESLib_SM2toolsECP.c
 *         \unit  es_SM2
 *        \brief  Tools for SM2 signature implementation based on ECP.
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

#define ESLIB_SM2TOOLSECP_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "ESLib.h"
#include "ESLib_types.h"
#include "ESLib_Helper.h"

/* actCLib includes */
#include "actIECKey.h"
#include "actISM2.h"

#define VSECPRIM_START_SEC_CODE
#include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VSECPRIM_SM2_KEY_GENERATION_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  esl_initGenerateKeyPairSM2_ECP()
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
VSECPRIM_FUNC(eslt_ErrorCode) esl_initGenerateKeyPairSM2_ECP (VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSM2) workSpace,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomainExt) domainExt,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccSpeedUpExt) speedUpExt)
{
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

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
    actRetVal = actECInitGenerateKeyPair(domain, domainExt, speedUpExt, &workSpace->wsSM2.eccWorkspace, workSpace->header.size);

    if (actRetVal != actOK)
    {
      if (actRetVal == actEXCEPTION_MEMORY)
      {
        retVal = ESL_ERC_WS_TOO_SMALL;
      }
      else if (actRetVal == actEXCEPTION_DOMAIN)
      {
        retVal = ESL_ERC_ECC_DOMAIN_INVALID;
      }
      else if (actRetVal == actEXCEPTION_DOMAIN_EXT)
      {
        retVal = ESL_ERC_ECC_DOMAINEXT_INVALID;
      }
      else /* actRetVal == actEXCEPTION_SPEEDUP_EXT */
      {
        retVal = ESL_ERC_ECC_SPEEDUPEXT_INVALID;
      }
    }
    else
    {
      eslt_Length orderSize = (eslt_Length) workSpace->wsSM2.eccWorkspace.baseData.Curve.n_field.m_byte_length;

      if (orderSize < ESL_SIZEOF_SM2_KEY_MIN)
      {
        retVal = ESL_ERC_ECC_DOMAIN_INVALID;
      }
      else
      {
        /* retVal has already been set in esl_CheckWorkSpaceHeader() */

        /* Set workSpace state */
        esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_SM2); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
      }
    }
  }
  return retVal;
}

/***********************************************************************************************************************
 *  esl_generateKeyPairSM2_ECP()
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
 */
 /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyPairSM2_ECP(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSM2) workSpace,
  VSECPRIM_P2VAR_PARA(eslt_Byte) privateKey,
  VSECPRIM_P2VAR_PARA(eslt_Length) privateKeyLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) publicKeyX,
  VSECPRIM_P2VAR_PARA(eslt_Length) publicKeyXLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) publicKeyY,
  VSECPRIM_P2VAR_PARA(eslt_Length) publicKeyYLength)
{
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  if ((workSpace == NULL_PTR) || (privateKey == NULL_PTR) || (publicKeyX == NULL_PTR) || (publicKeyY == NULL_PTR) ||
      (privateKeyLength == NULL_PTR) || (publicKeyXLength == NULL_PTR) || (publicKeyYLength == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_SM2, ESL_WST_ALGO_SM2)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
  {
    /* retVal was already set */
  }
  else
  {
    eslt_Length expectedPrivateKeySize = (eslt_Length) workSpace->wsSM2.eccWorkspace.baseData.Curve.n_field.m_byte_length;
    eslt_Length expectedPublicKeySize = (eslt_Length) workSpace->wsSM2.eccWorkspace.baseData.Curve.p_field.m_byte_length;

    if ((*privateKeyLength < expectedPrivateKeySize) || (*publicKeyXLength < expectedPublicKeySize) || (*publicKeyYLength < expectedPublicKeySize))
    {
      retVal = ESL_ERC_INPUT_INVALID;
    }
    else
    {
      /* call actCLib ECP key generation */
      actRetVal = actECGenerateKeyPair(TRUE, privateKey, publicKeyX, publicKeyY, &workSpace->wsSM2.eccWorkspace, workSpace->header.watchdog);
      if (actRetVal != actOK)
      {
        if (actRetVal == actEXCEPTION_PRIVKEY)
        {
           retVal = ESL_ERC_ECC_PRIVKEY_INVALID;
        }
        else if (actRetVal == actEXCEPTION_RANDOM)
        {
          retVal = ESL_ERC_RNG_FAILED;
        }
        else /* (actRetVal == actEXCEPTION_UNKNOWN) */
        {
          retVal = ESL_ERC_ECC_INTERNAL_ERROR;
        }
      }
      else
      {
        /* retVal = ESL_ERC_NO_ERROR was already set in esl_CheckWorkSpaceHeaderAndState. */
        *publicKeyXLength = expectedPublicKeySize; /* SBSW_VSECPRIM_WRITE_POINTER */
        *publicKeyYLength = expectedPublicKeySize; /* SBSW_VSECPRIM_WRITE_POINTER */
        *privateKeyLength = expectedPrivateKeySize; /* SBSW_VSECPRIM_WRITE_POINTER */
      }
    }

    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsSM2); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  }
  return retVal;
}
#endif /* (VSECPRIM_SM2_KEY_GENERATION_ENABLED == STD_ON) */

#if (VSECPRIM_SM2_SIGNATURE_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */
/***********************************************************************************************************************
 *  esl_calculateUserInfoSM2_ECP()
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
 */
 /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
VSECPRIM_FUNC(eslt_ErrorCode) esl_calculateUserInfoSM2_ECP(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSM2) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) id,
  const eslt_Length idLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyX,
  const eslt_Length publicKeyXLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyY,
  const eslt_Length publicKeyYLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) ZA,
  VSECPRIM_P2VAR_PARA(eslt_Length) ZALength)
{
  eslt_ErrorCode retVal;

  if ((workSpace == NULL_PTR) || (publicKeyX == NULL_PTR) || (publicKeyY == NULL_PTR) || (ZA == NULL_PTR) || (ZALength == NULL_PTR))
  {
    retVal =  ESL_ERC_PARAMETER_INVALID;
  }
  /* check workSpace state */
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_SM2, ESL_WST_ALGO_SM2)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
  {
    /* retVal was already set */
  }
  else if ((id == NULL_PTR) && (idLength > 0u))
  {
    retVal = ESL_ERC_INVALID_LENGTH;
  }
  else if ((id != NULL_PTR) && ((idLength > ESL_SIZEOF_SM2_MAXID) || ((idLength % 8u) != 0u)))
  {
    retVal = ESL_ERC_INVALID_LENGTH;
  }
  else
  {
    eslt_Length expectedPublicKeySize = (eslt_Length) workSpace->wsSM2.eccWorkspace.baseData.Curve.p_field.m_byte_length;

    if ((publicKeyXLength < expectedPublicKeySize) || (publicKeyYLength < expectedPublicKeySize) || (*ZALength < ESL_SIZEOF_SM3_DIGEST))
    {
      retVal =  ESL_ERC_INVALID_LENGTH;
    }
    else
    {
      if (id == NULL_PTR)
      {
        actISM2CalculateZA(&workSpace->wsSM2, id, 0u, publicKeyX, publicKeyY, ZA, workSpace->header.watchdog);
      }
      else
      {
        actISM2CalculateZA(&workSpace->wsSM2, id, idLength, publicKeyX, publicKeyY, ZA, workSpace->header.watchdog);
      }

      *ZALength = ESL_SIZEOF_SM3_DIGEST;
      /* retVal = ESL_ERC_NO_ERROR was already set in esl_CheckWorkSpaceHeaderAndState. */
    }

  }
  return retVal;
}
#endif /*(VSECPRIM_SM2_SIGNATURE_ENABLED == STD_ON) */

#define VSECPRIM_STOP_SEC_CODE
#include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  END OF FILE: ESLib_SM2toolsECP.c
 **********************************************************************************************************************/
