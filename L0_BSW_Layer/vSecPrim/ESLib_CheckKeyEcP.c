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
/*!        \file  ESLib_CheckKeyEcP.c
 *        \brief  Validity of Keys implementation
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

#define ESLIB_ECCHECK_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "ESLib.h"
#include "ESLib_t.h"
#include "ESLib_Helper.h"

/* actCLib includes */
#include "actECPoint.h"
#include "actECCheckKey.h"
#include "actIECCheckKey.h"

#if (VSECPRIM_ECDSA_GENERIC_ENABLED == STD_ON)

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  esl_initKeyCheckEcP_prim()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
 /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
VSECPRIM_FUNC(eslt_ErrorCode) esl_initKeyCheckEcP_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcPKeyCheck) workspace,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomainExt) domainExt)
{
  eslt_ErrorCode retVal;

  if ((workspace == NULL_PTR) || (domain == NULL_PTR) || (domainExt == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeader(&workspace->header, ESL_SIZEOF_WS_ECP_KEY_CHECK)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
  {
    /* retVal already set */
  }
  else
  {
    /* Init actCLib EC check Keys */
    actRETURNCODE actRetVal = actECinitCheckKeyValidity(domain, domainExt, &(workspace->workspaceKeyCheck.baseData), workspace->header.size); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
    if (actRetVal != actOK)
    {
      if (actRetVal == actEXCEPTION_SPEEDUP_EXT)
      {
        retVal = ESL_ERC_ECC_SPEEDUPEXT_INVALID;
      }
      else if (actRetVal == actEXCEPTION_MEMORY)
      {
        retVal = ESL_ERC_WS_TOO_SMALL;
      }
      else if (actRetVal == actEXCEPTION_DOMAIN)
      {
        retVal = ESL_ERC_ECC_DOMAIN_INVALID;
      }
      else /* actRetVal ==  actEXCEPTION_DOMAIN_EXT */
      {
        retVal = ESL_ERC_ECC_DOMAINEXT_INVALID;
      }
    }
    else
    {
      retVal = ESL_ERC_NO_ERROR;
      /* set workSpace state */
      workspace->header.status = (ESL_WST_ALGO_ECP_KEYCHECK | ESL_WST_M_RUNNING | ESL_WST_M_CRITICAL); /* SBSW_VSECPRIM_WRITE_POINTER */

    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  esl_publicKeyCheckEcP_prim()
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
VSECPRIM_FUNC(eslt_ErrorCode) esl_publicKeyCheckEcP_prim(VSECPRIM_P2CONST_PARA(eslt_WorkSpaceEcPKeyCheck) workspace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey_x, const eslt_Length publicKeyLength_x,
  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey_y, const eslt_Length publicKeyLength_y)
{
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  if ((workspace == NULL_PTR) || (publicKey_x == NULL_PTR) || (publicKey_y == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workspace->header, ESL_SIZEOF_WS_ECP_KEY_CHECK, ESL_WST_ALGO_ECP_KEYCHECK)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
  {
    /* retVal already set */
  }
  else if ((publicKeyLength_x != workspace->workspaceKeyCheck.baseData.Curve.p_field.m_byte_length) || (publicKeyLength_y != workspace->workspaceKeyCheck.baseData.Curve.p_field.m_byte_length))
  {
    retVal = ESL_ERC_INPUT_INVALID;
  }
  else
  {
     actRetVal = actECCheckValidityOfPublicKey(&workspace->workspaceKeyCheck, publicKey_x, publicKeyLength_x, publicKey_y, publicKeyLength_y, workspace->header.watchdog);  /* SBSW_VSECPRIM_CALL_FUNCTION */

     if (actRetVal == actOK)
     {
       retVal = ESL_ERC_NO_ERROR;
     }
     else
     {
       retVal = ESL_ERC_KEY_INVALID;
     }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  esl_privateKeyCheckEcP_prim()
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
VSECPRIM_FUNC(eslt_ErrorCode) esl_privateKeyCheckEcP_prim(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceEcPKeyCheck) workspace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) privateKey,
  const eslt_Length privateKeyLength)
{
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  if ((workspace == NULL_PTR) || (privateKey == NULL_PTR) || (privateKeyLength == 0u))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workspace->header, ESL_SIZEOF_WS_ECP_KEY_CHECK, ESL_WST_ALGO_ECP_KEYCHECK)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
  {
    /* retVal already set */
  }
  else if (privateKeyLength != workspace->workspaceKeyCheck.baseData.Curve.n_field.m_byte_length)
  {
    retVal = ESL_ERC_INPUT_INVALID;
  }
  else
  {
    actRetVal = actECCheckValidityOfPrivateKey(&workspace->workspaceKeyCheck.baseData.Curve, privateKey, workspace->workspaceKeyCheck.baseData.Curve.n_field.m_byte_length); /* SBSW_VSECPRIM_CALL_FUNCTION */
    if (actRetVal == actOK)
    {
      retVal = ESL_ERC_NO_ERROR;
    }
    else
    {
      retVal = ESL_ERC_KEY_INVALID;
    }
  }
  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* (VSECPRIM_ECDSA_GENERIC_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  END OF FILE: ESLib_CheckKeyEcP.c
 *********************************************************************************************************************/
