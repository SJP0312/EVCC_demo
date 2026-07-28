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
/*!        \file  actECCheckKey.c
 *        \brief  Key Check for EcP implementation
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

#define ACTECCHECKKEY_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "actECCheckKey.h"
#include "actECTools.h"
#include "actECPoint.h"
#include "actUtilities.h"

#if (VSECPRIM_ACTECCHECKKEY_ENABLED == STD_ON)

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
VSECPRIM_FUNC(actRETURNCODE) actECinitCheckKey(
  VSECPRIM_P2ROMCONST_PARA(actU8) domain,
  VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext,
  VSECPRIM_P2VAR_PARA(actECPBasicStruct) wksp,
  actLengthType wksp_len)
{
  return actECInit(domain, domain_ext, (VSECPRIM_P2CONST_PARA(actU8)) NULL_PTR, actEC_ALGO_FLAG_CHECKKEYS, (wksp), wksp_len); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
}

/**********************************************************************************************************************
 *  actECCheckPublicKey()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actECCheckPublicKey(
  VSECPRIM_P2VAR_PARA(actECPOINT) point, /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  VSECPRIM_P2CONST_PARA(actECCURVE) curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE actECPointIsOnCurve_Result;

  actECPToMont(point, curve, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actECPointIsOnCurve_Result = actECPointIsOnCurve(point, curve, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

  return actECPointIsOnCurve_Result;
}

/**********************************************************************************************************************
 *  actECCheckPrivateKey()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actECCheckPrivateKey(
  VSECPRIM_P2CONST_PARA(actECCURVE) curveInformation,
  VSECPRIM_P2CONST_PARA(actU8) privateKeyInBytes,
  const actLengthType givenPrivateKeyLength)
{
  actRETURNCODE retVal = actOK;
  VSECPRIM_P2CONST_PARA(actBNDIGIT) order;
  actBNDIGIT privateKey[actECC_MAX_N_DIGIT_LEN];
  actLengthType order_length, privateKeyLengthInBnDigit;
  actRETURNCODE resultCompareInput;
  actBoolean privateKeyIsZero;

  /* transform privateKey to bigNum */
  privateKeyLengthInBnDigit = actBNGetDigitLengthFromBit(actBytesToBits(givenPrivateKeyLength));
  actBNSetOctetString(privateKey, privateKeyLengthInBnDigit, privateKeyInBytes, givenPrivateKeyLength); /* SBSW_VSECPRIM_CALL_FUNCTION */
  order = curveInformation->n_field.m;
  order_length = curveInformation->n_field.m_length;
  /* Check if the private key is in the range (0...n). */
  resultCompareInput = actBNCompare(privateKey, order, order_length, FALSE); /* SBSW_VSECPRIM_CALL_FUNCTION */
  privateKeyIsZero = (actBNIsZero(privateKey, actBNGetDigitLength(givenPrivateKeyLength))); /* SBSW_VSECPRIM_CALL_FUNCTION */
  if ((privateKeyIsZero == FALSE) && (resultCompareInput == actCOMPARE_SMALLER))
  {
    retVal = actOK;
  }
  else
  {
    retVal = actEXCEPTION_PRIVKEY;
  }
  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTECCHECKKEY_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  END OF FILE: actECCheckKey.c
 *********************************************************************************************************************/
