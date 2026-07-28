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
/*!        \file  ESLib_EdDSA_Helper.c
 *        \brief  ES Library internal helper functions for EdDSA and EdDH for Edwards448 and Edwards25519
 *
 *      \details  Contains declarations of function declarations, which are internally used for EdwardsDSA and EdDH
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

#define ESLIB_EDDSA_HELPER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "ESLib_Config.h"
#include "ESLib.h"

/* actCLib includes */
#include "actIXEdDH.h"

#if (VSECPRIM_ED_HELPER_ENABLED == STD_ON)

# include "ESLib_Helper.h"
# include "ESLib_EdDSA_Helper.h"

# ifndef ESL_SUPPORT_CURVE25519
#  error "Curve25519 Support must be enabled"
# endif

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  esl_checkKeyLength()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_checkKeyLength(const eslt_Length keyLength,
  const eslt_Length expectedLength)
{
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;

  if (keyLength == expectedLength)
  {
    /* retVal has already been set */
  }
  else
  {
    retVal = ESL_ERC_INVALID_LENGTH;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  esl_validateCommonSecretLength()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_validateCommonSecretLength(eslt_Size16 curve,
  VSECPRIM_P2CONST_PARA(eslt_Length) sharedSecretLength)
{
  eslt_ErrorCode retVal = ESL_ERC_ERROR;

  /* Call common check length references function for sharedSecretLength */
# if (VSECPRIM_ECDH_25519_ENABLED == STD_ON)
  if(curve == ESL_CURVE25519)
  {
    retVal = esl_checkLengthRef(sharedSecretLength, ESL_SIZEOF_X25519_SHARED_SECRET); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }
# endif /* (VSECPRIM_ECDH_25519_ENABLED == STD_ON) */
# if (VSECPRIM_EDDH_448_ENABLED == STD_ON)
  if (curve == ESL_CURVE448)
  {
    retVal = esl_checkLengthRef(sharedSecretLength, ESL_SIZEOF_X448_SHARED_SECRET); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }
# endif /* (VSECPRIM_EDDH_448_ENABLED == STD_ON) */
  VSECPRIM_DUMMY_STATEMENT_CONST(curve); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  VSECPRIM_DUMMY_STATEMENT(sharedSecretLength); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  return retVal;
}

/**********************************************************************************************************************
 *  esl_checkInstanceContext()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_checkInstanceContext(
  const eslt_Byte instance,
  VSECPRIM_P2CONST_PARA(eslt_Byte) context,
  const eslt_Length contextLength,
  const eslt_Size16 curve)
{
  eslt_ErrorCode retVal = ESL_ERC_CURVE_NOT_SUPPORTED;

  /* differentiate between Ed25519 and Ed448 */
# if (VSECPRIM_ECDSA_25519_ENABLED == STD_ON)
  if (curve == ESL_CURVE25519)
  {
    if ((instance != ESL_INSTANCE_Ed25519)
      && (instance != ESL_INSTANCE_Ed25519CTX)
      && (instance != ESL_INSTANCE_Ed25519PH))
    {
      retVal = ESL_ERC_INSTANCE_NOT_SUPPORTED;
    }
    /* validate context */
    else if ((instance != ESL_INSTANCE_Ed25519) && (context != NULL_PTR) && (contextLength > ESL_EDWARDS_CONTEXT_LENGTH))
    {
      retVal = ESL_ERC_PARAMETER_INVALID;
    }
    else
    {
      retVal = ESL_ERC_NO_ERROR;
    }
  }
# endif /* (VSECPRIM_ECDSA_25519_ENABLED == STD_ON) */
# if (VSECPRIM_EDDSA_448_ENABLED == STD_ON)
  if (curve == ESL_CURVE448)
  {
    if ((instance != ESL_INSTANCE_Ed448)
      && (instance != ESL_INSTANCE_Ed448PH))
    {
      retVal = ESL_ERC_INSTANCE_NOT_SUPPORTED;
    }
    /* validate context */
    /* RFC8032: Value of context is set by signer and verifier (maximum of 255 octets; the default is empty string) */
    else if ((context != NULL_PTR) && (contextLength > ESL_EDWARDS_CONTEXT_LENGTH))
    {
      retVal = ESL_ERC_PARAMETER_INVALID;
    }
    else
    {
      retVal = ESL_ERC_NO_ERROR;
    }
  }
# endif /* (VSECPRIM_EDDSA_448_ENABLED == STD_ON) */
  VSECPRIM_DUMMY_STATEMENT_CONST(curve); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  VSECPRIM_DUMMY_STATEMENT_CONST(instance); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  VSECPRIM_DUMMY_STATEMENT(context); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  VSECPRIM_DUMMY_STATEMENT_CONST(contextLength); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ED_HELPER_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  END OF FILE: ESLib_EdDSA_Helper.c
 *********************************************************************************************************************/
