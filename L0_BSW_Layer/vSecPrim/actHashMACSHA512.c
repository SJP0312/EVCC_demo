/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is protected under intellectual property laws and proprietary to cv cryptovision GmbH
 *                and/or Vector Informatik GmbH.
 *                No right or license is granted save as expressly set out in the applicable license conditions.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  actHashMACSHA512.c
 *        \brief  Hash MAC SHA-512 implementation.
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

#define ACTHASHMACSHA512_SOURCE

#include "actIHashMACSHA512.h"
#include "actUtilities.h"

#if (VSECPRIM_ACTHASHMACSHA512_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

/****************************************************************************
 ** Global Functions
 ***************************************************************************/
# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  actHashMACSHA512Init()
 *********************************************************************************************************************/
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
VSECPRIM_FUNC(actRETURNCODE) actHashMACSHA512Init(
  VSECPRIM_P2VAR_PARA(actHASHMACSHA512STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /* ----- Local Variables ------------------------------------------------ */
  VSECPRIM_P2VAR_PARA(actSHA512STRUCT) sha512 = &info->sha512;
  VSECPRIM_P2VAR_PARA(actU8) tmp_block = info->sha512.buffer;
  actRETURNCODE retVal = actOK;
  actLengthType i;

  /* ----- Implementation ------------------------------------------------- */
  /* check if there is a valid key and if so store key */
  if (key_length < 1u)
  {
    retVal = actEXCEPTION_LENGTH;
  }
  /* check key length - if the key length is smaller than the block size, the key can be used directly - otherwise the key is hashed */
  else if (key_length <= actHASH_BLOCK_SIZE_SHA512)
  {
    /* copy key to key_buf */
    actMemCpyByteArray(info->key_buf, key, key_length); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
    info->key_length = key_length;
  }
  else
  {
    /* hash the key - use SHA-512(key) */
    (void)actSHA512Init(sha512);
    (void)actSHA512Update(sha512, key, key_length, watchdog);
    (void)actSHA512Finalize(sha512, info->key_buf, watchdog);
    info->key_length = actHASH_SIZE_SHA512; /* the hashed key is always of size 64 byte = 512 bit */
  }

  if (retVal == actOK)
  {
    /* expand key with zeros */
    actMemCpyByteArray(tmp_block, info->key_buf, (info->key_length)); /* copies key into tmp_block */ /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
    actMemClear(&tmp_block[info->key_length], (actLengthType)(actHASH_BLOCK_SIZE_SHA512 - info->key_length)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* sets everything 0 from index info->key_length = 64 until end */
    /* the expanded key is XORed with ipad = 0011 0110 */
    for (i = 0u; i < actHASH_BLOCK_SIZE_SHA512; ++i)
    {
      tmp_block[i] ^= (actU8)(0x36u); /* 0x36 (hex) = 0011 0110 (binary) <- the inner pad consists of the repetition of this bit pattern -
                                         tmp_block consists of 128 entries, therefore it is of length 1024 */
    }
    /* the result is the first input block to the hash function */
    (void)actSHA512Init(sha512);
    (void)actSHA512Update(sha512, tmp_block, actHASH_BLOCK_SIZE_SHA512, watchdog);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  actHashMACSHA512Update()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actHashMACSHA512Update(
   VSECPRIM_P2VAR_PARA(actHASHMACSHA512STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   return actSHA512Update(&info->sha512, dataIN, length, watchdog);
}

/**********************************************************************************************************************
 *  actHashMACFinalize()
 *********************************************************************************************************************/
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
 */
VSECPRIM_FUNC(void) actHashMACSHA512Finalize(
   VSECPRIM_P2VAR_PARA(actHASHMACSHA512STRUCT) info, VSECPRIM_P2VAR_PARA(actU8) hash,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   VSECPRIM_P2VAR_PARA(actSHA512STRUCT) sha512 = &info->sha512;
   VSECPRIM_P2VAR_PARA(actU8) tmp_block = info->sha512.buffer;
   actLengthType i;

   /* function call to finalize Sha512(Expanded Key XOR ipad || message) */
   (void)actSHA512Finalize(sha512, hash, watchdog);

   /* expand key */
   actMemCpyByteArray(tmp_block, info->key_buf, (info->key_length)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
   actMemClear(&tmp_block[info->key_length], (actLengthType)(actHASH_BLOCK_SIZE_SHA512 - info->key_length)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
   /* the expanded key gets XORed with the following opad bit pattern : 0101 1100 */
   for (i=0u; i < actHASH_BLOCK_SIZE_SHA512; ++i)
   {
      tmp_block[i] ^= (actU8)(0x5cu); /* 0x5c (hex) = 0101 1100 (binary) <- outer pad */
   }

   /* finalizing HMAC: Hash(Expanded Key XOR opad || Hash(Expanded Key XOR ipad || message)) */
   (void)actSHA512Init(sha512);
   (void)actSHA512Update(sha512, tmp_block, actHASH_BLOCK_SIZE_SHA512, watchdog);
   (void)actSHA512Update(sha512, hash, actHASH_SIZE_SHA512, watchdog);
   (void)actSHA512Finalize(sha512, hash, watchdog);

}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTHASHMACSHA512_ENABLED == STD_ON) */
