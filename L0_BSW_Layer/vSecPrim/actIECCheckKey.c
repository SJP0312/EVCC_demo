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
/*!        \file  actIECCheckKey.c
 *        \brief  Key Check implementation for EcP
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

#define ACTIECCHECKKEY_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "actIECCheckKey.h"
#include "actECCheckKey.h"

#if (VSECPRIM_ACTIECCHECKKEY_ENABLED == STD_ON)

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  actECinitCheckKey()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actECinitCheckKeyValidity(
  VSECPRIM_P2ROMCONST_PARA(actU8) domain,
  VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext,
  VSECPRIM_P2VAR_PARA(actECPBasicStruct) wksp,
  actLengthType wksp_len)
{
  return actECinitCheckKey(domain, domain_ext, wksp, wksp_len); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
}

/**********************************************************************************************************************
 *  actECCheckValidityOfPublicKey()
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
 /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
VSECPRIM_FUNC(actRETURNCODE) actECCheckValidityOfPublicKey(VSECPRIM_P2CONST_PARA(act_WorkSpaceEcPKeyCheck) workspace,
  VSECPRIM_P2CONST_PARA(actU8) publicKey_x, const actLengthType publicKeyLength_x,
  VSECPRIM_P2CONST_PARA(actU8) publicKey_y, const actLengthType publicKeyLength_y,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE retVal;
  actBNDIGIT publicKeyBN_x[actECC_MAX_P_DIGIT_LEN];
  actBNDIGIT publicKeyBN_y[actECC_MAX_P_DIGIT_LEN];

  /* set public key in workspace */
  actBNSetOctetString(publicKeyBN_x, (actLengthType)(actBNGetDigitLengthFromBit((actLengthType)actBytesToBits((actLengthType)publicKeyLength_x))), publicKey_x, publicKeyLength_x); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetOctetString(publicKeyBN_y, (actLengthType)(actBNGetDigitLengthFromBit((actLengthType)actBytesToBits((actLengthType)publicKeyLength_y))), publicKey_y, publicKeyLength_y); /* SBSW_VSECPRIM_CALL_FUNCTION */

  /* range check: assert that the public key coordinates are in (0, p) */
  if (actBNCompare(publicKeyBN_x, workspace->baseData.Curve.p_field.m, workspace->baseData.Curve.p_field.m_length, FALSE) >= actCOMPARE_EQUAL) /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    retVal = actEXCEPTION_PUBKEY;
  }
  else if (actBNCompare(publicKeyBN_y, workspace->baseData.Curve.p_field.m, workspace->baseData.Curve.p_field.m_length, FALSE) >= actCOMPARE_EQUAL) /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    retVal = actEXCEPTION_PUBKEY;
  }
  else if (actBNIsZero(publicKeyBN_x, (actLengthType)actBNGetDigitLengthFromBit((actLengthType)actBytesToBits((actLengthType)publicKeyLength_x))) == TRUE) /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    retVal = actEXCEPTION_PUBKEY;
  }
  else if (actBNIsZero(publicKeyBN_y, (actLengthType)actBNGetDigitLengthFromBit((actLengthType)actBytesToBits((actLengthType)publicKeyLength_y))) == TRUE) /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    retVal = actEXCEPTION_PUBKEY;
  }
  else
  {
    /* the given coordinates are within range */
    actECPOINT point;
    actRETURNCODE actECPointIsOnCurve_Result;

    /* prepare data for checkKeyOnCurve */
    point.x = publicKeyBN_x; /* SBSW_VSECPRIM_WRITE_POINTER */
    point.y = publicKeyBN_y; /* SBSW_VSECPRIM_WRITE_POINTER */
    point.is_affine = TRUE;
    point.is_infinity = FALSE;

    /* Call actCLib EC checkKeyOnCurve */
    actECPointIsOnCurve_Result = actECCheckPublicKey(&point, &workspace->baseData.Curve, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

    if (actECPointIsOnCurve_Result == actOK)
    {
      retVal = actOK;
    }
    else
    {
      retVal = actEXCEPTION_PUBKEY;
    }
  }
  return retVal;
}
/**********************************************************************************************************************
 *  actECCheckValidityOfPrivateKey()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actECCheckValidityOfPrivateKey(
  VSECPRIM_P2CONST_PARA(actECCURVE) curveInformation,
  VSECPRIM_P2CONST_PARA(actU8) privateKeyInBytes,
  const actLengthType givenPrivateKeyLength)
{
  return actECCheckPrivateKey(curveInformation, privateKeyInBytes, givenPrivateKeyLength); /* SBSW_VSECPRIM_CALL_FUNCTION */
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTIECCHECKKEY_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  END OF FILE: actIECCheckKey.c
 *********************************************************************************************************************/
