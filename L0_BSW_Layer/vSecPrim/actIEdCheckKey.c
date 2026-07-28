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
/*!        \file  actIEdCheckKey.c
 *        \brief  Implementation file for actIEdCheckKey.h
 *
 *      \details This file is part of the embedded systems library cvActLib
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

#define ACTIEDCHECKKEY_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "actIEdCheckKey.h"
#include "actEdCheckKey.h"
#include "actUtilities.h"

#if (VSECPRIM_ACTIEDCHECKKEY_ENABLED == STD_ON)

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  actEdinitCheckKey()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(void) actEdinitCheckKey(
  VSECPRIM_P2VAR_PARA(actEdwardsKeyCheck) workspace)
{
  actEdKeyCheck_initCore(workspace); /* SBSW_VSECPRIM_CALL_FUNCTION */
}

/**********************************************************************************************************************
 *  actEdCheckValidityOfPublicKey()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actEdCheckValidityOfPublicKey(
VSECPRIM_P2VAR_PARA(actEdwardsKeyCheck) workspace,
VSECPRIM_P2CONST_PARA(actU8) publicKey,
const actLengthType publicKeyLength,
VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE retVal = actEXCEPTION_UNKNOWN;
  actLengthType expectedPublicKeyLength = 0u;

   /* differentiate between the Edwardscurves */
   if (workspace->curveId == actEDWARDSCURVE25519)
   {
     expectedPublicKeyLength = actEd25519_KEY_SIZE;
   }
   else /* (workspace->curveId == actEDWARDSCURVE448) */
   {
     expectedPublicKeyLength = actEd448_KEY_SIZE;
   }

   /* check if the key length is correct  */
   if (publicKeyLength != expectedPublicKeyLength)
   {
     retVal = actEXCEPTION_INPUT_LENGTH;
   }
   else
   {
       retVal = actEdCheckPublicKey(workspace, publicKey, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
   }
   return retVal;
}

/**********************************************************************************************************************
 *  actEdCheckValidityOfPrivateKey()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actEdCheckValidityOfPrivateKey(
VSECPRIM_P2CONST_PARA(actEdwardsKeyCheck) workspace,
VSECPRIM_P2CONST_PARA(actU8) privateKey,
const actLengthType privateKeyLength)
{
  return actEdCheckPrivateKey(workspace, privateKey, privateKeyLength); /* SBSW_VSECPRIM_CALL_FUNCTION */
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTIEDCHECKKEY_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  END OF FILE: actIEdCheckKey.c
 *********************************************************************************************************************/
