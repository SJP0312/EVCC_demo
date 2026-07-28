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
/*!        \file  actKDFX963.c
 *        \brief  KDFX963 key derivation function according to ANSI X9.63 using SHA-1 as underlying hash function.
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

#define ACTKDFX963_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "actIKDFX963.h"
#include "actUtilities.h"

#if (VSECPRIM_ACTKDFX963_ENABLED == STD_ON)

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  actKDFX963Derive
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actKDFX963Derive(
  VSECPRIM_P2VAR_PARA(actKDFX963STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) passwd, actLengthType passwd_length,
  VSECPRIM_P2CONST_PARA(actU8) salt, actLengthType salt_length,
  VSECPRIM_P2VAR_PARA(actU8) key, actLengthType key_length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE retVal;
  VSECPRIM_P2VAR_PARA(actSHASTRUCT) sha = &info->actwsHash;
  VSECPRIM_P2VAR_PARA(actU8) keyPtr = key;
  actU8 counter[4];
  actLengthType l, r, i;

# if (vSecPrim_GetSizeOfEsltLengthOfGeneral() == VSECPRIM_SIZE_UINT32) /* COV_VSECPRIM_NO_SAFE_CONFIG TX */
  if (((key_length + (actHASH_SIZE_SHA - 1u)) < key_length))
  {
    retVal = actEXCEPTION_INPUT_LENGTH;
  }
  else
# endif
  {
    l = (key_length + actHASH_SIZE_SHA - 1u) / actHASH_SIZE_SHA;
    r = key_length - ((l - 1u) * actHASH_SIZE_SHA);
    /* derive key */
    /* Since key_length + actHASH_SIZE_SHA - 1u < uint32max < 2^32 it follows that
     * l < (2^32)/actHASH_SIZE_SHA = (2^32)/20 < uint32max.
     * Thus, l + 1u is a valid addition without overflow. */
    for (i = 1u; i < (l + 1u); ++i) /* FETA_VSECPRIM_UPPER_BOUNDARY_CHECKED_BY_CALLEE_PARAMETER */
    {
      /* hash (passwd|counter|salt) */
      (void)actSHAInit(sha); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
      (void)actSHAUpdate(sha, passwd, passwd_length, watchdog); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
      actU32toBE(counter, (actU32)i); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
      (void)actSHAUpdate(sha, counter, sizeof(counter), watchdog); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
      (void)actSHAUpdate(sha, salt, salt_length, watchdog); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */

      /* test: is last block? */
      if (i != l)
      {
        (void)actSHAFinalize(sha, &keyPtr[actHASH_SIZE_SHA * (i - 1u)], watchdog); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
      }
      else
      {
        (void)actSHAFinalize(sha, info->hashBuf, watchdog); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
        actMemCpyByteArray(&keyPtr[actHASH_SIZE_SHA * (i - 1u)], info->hashBuf, r); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
      }
    }

    retVal = actOK;
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTKDFX963_ENABLED == STD_ON) */
