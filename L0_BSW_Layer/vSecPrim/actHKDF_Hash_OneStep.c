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
/*!        \file  actHKDF_Hash_OneStep.c
 *        \brief  One step HKDF key derivation function according to NIST SP800-56C1 using SHA256 or SHA512.
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

#define ACTHKDF_HASH_ONESTEP_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "actIHKDF_Hash_OneStep.h"
#include "actUtilities.h"
#include "actConfig.h"

#if (VSECPRIM_ACTHKDFHASHONESTEP_ENABLED == STD_ON)

/***********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
# define COUNTER_BUFFER_LENGTH                                        (4u)

# if (VSECPRIM_HKDF_SHA2_256_ONESTEP_ENABLED == STD_ON)
#  define VSECPRIM_WRAPPER_SHA256
# endif
# if (VSECPRIM_HKDF_SHA2_512_ONESTEP_ENABLED == STD_ON)
#  define VSECPRIM_WRAPPER_SHA512
# endif

typedef actWorkSpaceUnionHashFunctions_HKDF actWorkSpaceUnionHashFunctions;
# include "actHashFctWrappers_Implementation.h" /* PRQA S 5087 */ /* MD_VSECPRIM_19.1 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  actHKDF_Hash_OneStepDerive()
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
VSECPRIM_FUNC(actRETURNCODE) actHKDF_Hash_OneStepDerive(
  VSECPRIM_P2VAR_PARA(actHKDFHASHSTRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) secret,
  actLengthType secretLength,
  VSECPRIM_P2CONST_PARA(actU8) addInput,
  actLengthType addInputLength,
  VSECPRIM_P2VAR_PARA(actU8) derivedKey,
  const actLengthType derivedKeyLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /* ----- Local Variables ------------------------------------------------ */
  actRETURNCODE retVal;
  actLengthType numberOfBlocks, remainingBytes, currentBlock;
  actU8 counterBuffer[COUNTER_BUFFER_LENGTH];
  actU32 counter = 1u;
  actU8 hashSize = info->hashSize;
  actU8 hashId = info->hashID;

  /* ----- Implementation ------------------------------------------------- */
 /* Initialize counter as a 4-byte array, starting from 1 */
  actU32toBE(counterBuffer, counter); /* SBSW_VSECPRIM_FCT_CALL_LOCAL_BUFFER_FIXED_SIZE */

  /* Check whether derivedKeyLength is too high to be processed. */
  if ((derivedKeyLength + hashSize - 1u) < derivedKeyLength)
  {
    retVal = actEXCEPTION_LENGTH;
  }
  else
  {
    /* Determine the necessary number of blocks */
    numberOfBlocks = (derivedKeyLength + hashSize - 1u) / hashSize;
    remainingBytes = derivedKeyLength % hashSize;

    /* Size of numberOfBlocks depends on derivedKeyLength. From the specification, derivedKeyLength can be larger than
     * UINT32_MAX therefore only a check for overflow is sufficient
     * Since derivedKeyLength + hashSize - 1u < uint32max < 2^32 it follows that
     * numberOfBlocks < (2^32)/hashSize <= (2^32)/32 = (2^32)/(2^5) = 2^27 < uint32max,
     * where hashSize is either 32 or 64.
     * Thus, numberOfBlocks + 1u is a valid addition without overflow. */
    for (currentBlock = 1u; currentBlock < (numberOfBlocks + 1u); currentBlock++) /*lint !e644 */ /* FETA_VSECPRIM_UPPER_BOUNDARY_CHECKED_BY_CALLEE_PARAMETER */
    {
      /* Calculate block K(i) as K(i) = HASH([counter || secret || addInput]) */
      (void)actHashInit(&info->actwsSha, hashId); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */

      /* actHashUpdate returns actEXCEPTION_LENGTH, if its parameter 'length' > 2^64 bit;
       * counter length = 32 bit, secretLength < 2^35 bit, addInputLength < 2^35 bit -> sum < 2^36 + 32 bit < 2^64 bit */
      (void)actHashUpdate(&info->actwsSha, counterBuffer, COUNTER_BUFFER_LENGTH, hashId, watchdog);  /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
      (void)actHashUpdate(&info->actwsSha, secret, secretLength, hashId, watchdog);  /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */

      if (addInputLength > 0u)
      {
         /* If addInputLength > 0u, then addInput != NULL_PTR, as this was checked in esl_deriveKeyHKDF_Hash_OneStep */
        (void)actHashUpdate(&info->actwsSha, addInput, addInputLength, hashId, watchdog);  /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
      }

      /* not last block or complete last block required? */
      if ((currentBlock != numberOfBlocks) || (0u == remainingBytes))
      {
        /* complete (last) block; actHashFinalize always returns actOK */
        (void)actHashFinalize(&info->actwsSha, &derivedKey[hashSize * (currentBlock - 1u)], hashId, watchdog);  /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
      }
      else
      {
        /* partial last block; actHashFinalize always returns actOK */
        (void)actHashFinalize(&info->actwsSha, info->blockT, hashId, watchdog);  /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
        actMemCpyByteArray(&derivedKey[hashSize * (currentBlock - 1u)], info->blockT, remainingBytes);  /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_FIXED_SUBADDRESS */
      }

      /* increment counter */
      counter++;
      actU32toBE(counterBuffer, counter); /* SBSW_VSECPRIM_FCT_CALL_LOCAL_BUFFER_FIXED_SIZE */
    }

    retVal = actOK;
  }

  return retVal;

}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTHKDFHASHONESTEP_ENABLED == STD_ON) */
