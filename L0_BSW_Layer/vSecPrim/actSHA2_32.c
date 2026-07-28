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
/*!        \file  actSHA2_32.c
 *        \brief  Core SHA-224 and SHA-256 implementation.
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

#define ACTSHA2_32_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "actISHA2_32.h"
#include "actUtilities.h"
#include "actWatchdog.h"
#include "actConfig.h"

#if (VSECPRIM_ACTSHA2_32_ENABLED == STD_ON)

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
# define actSHA256_WORD_SIZE                                          (4u)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/* The SHA2_32 functions */
# define S0(x)                                                        (actRotr((x), 2u)^actRotr((x), 13u)^actRotr((x), 22u))
# define S1(x)                                                        (actRotr((x), 6u)^actRotr((x), 11u)^actRotr((x), 25u))
# define s0(x)                                                        (actRotr((x), 7u)^actRotr((x), 18u)^((x)>>3u))
# define s1(x)                                                        (actRotr((x), 17u)^actRotr((x), 19u)^((x)>>10u))

/* basic macros */
# define blk0(i)                                                      (W[(i)])
# define blk2(i)                                                      (W[(i)&15u]+=s1(W[((i)-2u)&15u])+W[((i)-7u)&15u]+s0(W[((i)-15u)&15u]))

# define Ch(x, y, z)                                                  ((z)^((x)&((y)^(z))))
# define Maj(x, y, z)                                                 (((x)&(y))|((z)&((x)|(y))))

# define a(i)                                                         (T[(0u-(i))&7u])
# define b(i)                                                         (T[(1u-(i))&7u])
# define c(i)                                                         (T[(2u-(i))&7u])
# define d(i)                                                         (T[(3u-(i))&7u])
# define e(i)                                                         (T[(4u-(i))&7u])
# define f(i)                                                         (T[(5u-(i))&7u])
# define g(i)                                                         (T[(6u-(i))&7u])
# define h(i)                                                         (T[(7u-(i))&7u])

# define Ra0(i, j)                                                    (h(i) += S1(e(i)) + Ch(e(i), f(i), g(i)) + ACT_ROM_R_DWD(actSHA2_32_K[(i) + (j)]) + blk0(i))
# define Ra2(i, j)                                                    blk2(i); \
                                                                      (h(i) = (h(i) + S1(e(i)) + Ch(e(i), f(i), g(i)) + ACT_ROM_R_DWD(actSHA2_32_K[(i) + (j)]) + W[(i)&15u])&0xFFFFFFFFu)
# define Rb(i)                                                        (d(i) += h(i))
# define Rc(i)                                                        (h(i) += S0(a(i)) + Maj(a(i), b(i), c(i)))

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

# define VSECPRIM_START_SEC_CONST_UNSPECIFIED
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VSECPRIM_ROM(VSECPRIM_LOCAL, actU32) actSHA2_32_K[64] = { /* PRQA S 3218 */ /* MD_VSECPRIM_8.7 */
  0x428a2f98U, 0x71374491U, 0xb5c0fbcfU, 0xe9b5dba5U, 0x3956c25bU, 0x59f111f1U, 0x923f82a4U, 0xab1c5ed5U,
  0xd807aa98U, 0x12835b01U, 0x243185beU, 0x550c7dc3U, 0x72be5d74U, 0x80deb1feU, 0x9bdc06a7U, 0xc19bf174U,
  0xe49b69c1U, 0xefbe4786U, 0x0fc19dc6U, 0x240ca1ccU, 0x2de92c6fU, 0x4a7484aaU, 0x5cb0a9dcU, 0x76f988daU,
  0x983e5152U, 0xa831c66dU, 0xb00327c8U, 0xbf597fc7U, 0xc6e00bf3U, 0xd5a79147U, 0x06ca6351U, 0x14292967U,
  0x27b70a85U, 0x2e1b2138U, 0x4d2c6dfcU, 0x53380d13U, 0x650a7354U, 0x766a0abbU, 0x81c2c92eU, 0x92722c85U,
  0xa2bfe8a1U, 0xa81a664bU, 0xc24b8b70U, 0xc76c51a3U, 0xd192e819U, 0xd6990624U, 0xf40e3585U, 0x106aa070U,
  0x19a4c116U, 0x1e376c08U, 0x2748774cU, 0x34b0bcb5U, 0x391c0cb3U, 0x4ed8aa4aU, 0x5b9cca4fU, 0x682e6ff3U,
  0x748f82eeU, 0x78a5636fU, 0x84c87814U, 0x8cc70208U, 0x90befffaU, 0xa4506cebU, 0xbef9a3f7U, 0xc67178f2U
};

# define VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
  actSHA2_32_Transform()
 **********************************************************************************************************************/
/*! \brief      SHA2 transformation.
 *  \details    This function hashes one 64 byte block of data.
 *  \param[in]      in  Pointer to 64 byte input data.
 *  \param[in,out]  H   Current hash state.
 *  \param[in]      watchdog  Pointer to watchdog function.
 *  \context    TASK
 *  \reentrant  TRUE
 *  \pre        Input data must be 64 byte, H must be at least 256 byte
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(void) actSHA2_32_Transform(
  VSECPRIM_P2CONST_PARA(actU8) in,
  VSECPRIM_P2VAR_PARA(actU32) H,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
  actSHA2_32_Update()
 **********************************************************************************************************************/
/*! \brief      This function is the generic SHA2 update implementation.
 *  \details    This function hashes the given data and can be called arbitrarily often between an initialize and
 *              finalize of the SHA-2 algorithm. Uses any data already in the actSHA256STRUCT structure and leaves
 *              any partial data block there.
 *  \param[in,out]  info  In: Pointer to hash context structure. Out: Actualized hash context structure.
 *  \param[in]  dataIN  Pointer to data to be hashed.
 *  \param[in]  length  Length of data in bytes.
 *  \param[in]  watchdog  Pointer to watchdog trigger function
 *  \context    TASK
 *  \reentrant  TRUE
 *  \return     actEXCEPTION_LENGTH   total input more than 2^64 - 1 bit
 *              actOK                 else
 *  \pre        actSHAxxxInit() has been called before calling this function. dataIN != NULL is a valid pointer
                length >= 0
                info must be a valid pointer.
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actSHA2_32_Update(
  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN,
  actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
  actSHA2_32_Finalize()
 **********************************************************************************************************************/
/*! \brief      This function finalizes the SHA algorithm and delivers the hash value.
 *  \details    This function applies padding and processes the leftovers of the input data to generate the message
 *              digest.
 *  \param[in,out]  info  In: Pointer to hash context structure. Out: Finalized hash context structure.
 *  \param[out]  hash  Buffer where the hash value shall be stored.
 *  \param[in]  watchdog  Pointer to watchdog trigger function.
 *  \context    TASK
 *  \reentrant  TRUE
 *  \return     actOK  Operation successful.
 *  \pre        actSHAxxxInit() has been called before calling this function.
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actSHA2_32_Finalize(
  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actSHA2_32_Transform()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_LOCAL_FUNC(void) actSHA2_32_Transform(
  VSECPRIM_P2CONST_PARA(actU8) in,
  VSECPRIM_P2VAR_PARA(actU32) H,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actU32 W[16];
  actU32 T[8];
  actU32 i, j;

  /* Copy state to working vars */
  for (i = 0u; i < 8u; ++i)
  {
    T[i] = H[i]; /* SBSW_VSECPRIM_WRITE_ARRAY */
  }

  /* Copy 64 byte block input data to workspace in big endian format */
  actCpyBEtoU32(W, in, actHASH_BLOCK_SIZE_SHA256); /* SBSW_VSECPRIM_CALL_FUNCTION */

  actL2trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */

  /* Perform SHA2 Rounds */
  for (j = 0u; j < 64u; j += 16u) /*lint -e{661, 662} */ /* FETA_VSECPRIM_UPPER_BOUNDARY_CHECKED_BY_CALLEE */
  {
# if (actSHA256_SPEED_UP > 0) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */
    /* rounds unrolled */
    if (j == 0u) {
      /* PRQA S 2910 8 */ /* MD_VSECPRIM_WRAPAROUND */
      Ra0(0u, j); Rb(0u); Rc(0u); Ra0(1u, j); Rb(1u); Rc(1u);
      Ra0(2u, j); Rb(2u); Rc(2u); Ra0(3u, j); Rb(3u); Rc(3u);
      Ra0(4u, j); Rb(4u); Rc(4u); Ra0(5u, j); Rb(5u); Rc(5u);
      Ra0(6u, j); Rb(6u); Rc(6u); Ra0(7u, j); Rb(7u); Rc(7u);
      Ra0(8u, j); Rb(8u); Rc(8u); Ra0(9u, j); Rb(9u); Rc(9u);
      Ra0(10u, j); Rb(10u); Rc(10u); Ra0(11u, j); Rb(11u); Rc(11u);
      Ra0(12u, j); Rb(12u); Rc(12u); Ra0(13u, j); Rb(13u); Rc(13u);
      Ra0(14u, j); Rb(14u); Rc(14u); Ra0(15u, j); Rb(15u); Rc(15u);
      actL3trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
    }
    else
    {
      /* PRQA S 2910, 2985, 2986 8 */ /* MD_VSECPRIM_WRAPAROUND */ /* MD_VSECPRIM_REDUNDANT_OP */
      Ra2(0u, j); Rb(0u); Rc(0u); Ra2(1u, j); Rb(1u); Rc(1u);
      Ra2(2u, j); Rb(2u); Rc(2u); Ra2(3u, j); Rb(3u); Rc(3u);
      Ra2(4u, j); Rb(4u); Rc(4u); Ra2(5u, j); Rb(5u); Rc(5u);
      Ra2(6u, j); Rb(6u); Rc(6u); Ra2(7u, j); Rb(7u); Rc(7u);
      Ra2(8u, j); Rb(8u); Rc(8u); Ra2(9u, j); Rb(9u); Rc(9u);
      Ra2(10u, j); Rb(10u); Rc(10u); Ra2(11u, j); Rb(11u); Rc(11u);
      Ra2(12u, j); Rb(12u); Rc(12u); Ra2(13u, j); Rb(13u); Rc(13u);
      Ra2(14u, j); Rb(14u); Rc(14u); Ra2(15u, j); Rb(15u); Rc(15u);
      actL3trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
    }
# else
    if (j == 0u) {
      for (i = 0u; i < 16u; ++i)
      {
        Ra0(i, j); /* PRQA S 2985, 3226 */ /* MD_VSECPRIM_REDUNDANT_OP, MD_VSECPRIM_ASSIGNMENT_RESULT_IN_OP */ /* SBSW_VSECPRIM_WRITE_ARRAY */ /* SBSW_VSECPRIM_WRITE_ARRAY */
        Rb(i);                                                                                                /* SBSW_VSECPRIM_WRITE_ARRAY */
        Rc(i);    /* PRQA S 2986 */ /* MD_VSECPRIM_REDUNDANT_OP */                                            /* SBSW_VSECPRIM_WRITE_ARRAY */

        actL3trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
      }
    }
    else
    {
      for (i = 0u; i < 16u; ++i)
      {
        Ra2(i, j); /* PRQA S 2985, 3226 */ /* MD_VSECPRIM_REDUNDANT_OP, MD_VSECPRIM_ASSIGNMENT_RESULT_IN_OP */ /* SBSW_VSECPRIM_WRITE_ARRAY */ /* SBSW_VSECPRIM_WRITE_ARRAY */
        Rb(i);                                                                                                /* SBSW_VSECPRIM_WRITE_ARRAY */
        Rc(i);    /* PRQA S 2986 */ /* MD_VSECPRIM_REDUNDANT_OP */                                            /* SBSW_VSECPRIM_WRITE_ARRAY */

        actL3trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
      }
    }
# endif
    actL2trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
  }

  actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */  /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */

  /* Update the HASH state with current results */
  for (i = 0u; i < 8u; ++i)
  {
    H[i] += T[i]; /* SBSW_VSECPRIM_WRITE_ARRAY */
  }
}

/**********************************************************************************************************************
 *  actSHA2_32_Update()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actSHA2_32_Update(
  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN,
  actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  VSECPRIM_P2VAR_PARA(actU32) Hptr = info->H;
  VSECPRIM_P2VAR_PARA(actU8) bufferPtr = info->buffer;
  actLengthType diff = 0u;
  actRETURNCODE retVal = actOK;
  actLengthType lastBlockEnd;
  actLengthType bcount;
  actBoolean finished = FALSE;

  actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */  /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */

  /* Update byte count */
  if ((info->low_count + (actU32)length) < info->low_count)
  {
    info->hi_count++; /* SBSW_VSECPRIM_WRITE_POINTER */
    if ((info->hi_count) == ((actU32)1u << 29)) /* add carry */
    {
      retVal = actEXCEPTION_LENGTH; /* overflow: 2^64 bit input */
    }
  }

  if (retVal == actOK)
  {
    info->low_count += (actU32)length; /* SBSW_VSECPRIM_WRITE_POINTER */

    /* Left overs of the last update */
    if (info->buffer_used > 0u)
    {
      diff = (actLengthType)actMin(length, (actHASH_BLOCK_SIZE_SHA256 - info->buffer_used));
      actMemCpyByteArray(&bufferPtr[info->buffer_used], dataIN, diff); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
      info->buffer_used += (actU16)(diff & 0xFFu); /* SBSW_VSECPRIM_WRITE_POINTER */
      if (info->buffer_used < actHASH_BLOCK_SIZE_SHA256)
      {
        retVal = actOK; /* Operation is finished */
        finished = TRUE;
      }
      else
      {
        actSHA2_32_Transform(bufferPtr, Hptr, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
      }
    }

    if (finished == FALSE)
    {
      /* Complete blocks */
      lastBlockEnd = (actLengthType)((length - diff) / actHASH_BLOCK_SIZE_SHA256);
      lastBlockEnd = (lastBlockEnd*actHASH_BLOCK_SIZE_SHA256) + diff;

      for (bcount = diff; bcount < lastBlockEnd; bcount += actHASH_BLOCK_SIZE_SHA256) /* FETA_VSECPRIM_UPPER_BOUNDARY_CHECKED_BY_CALLEE_PARAMETER */
      {
        actSHA2_32_Transform(&dataIN[bcount], Hptr, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
      }

      /* Copy left overs into buffer */
      info->buffer_used = (actLengthType)(length - lastBlockEnd); /* actHASH_BLOCK_SIZE_SHA256 (64) fits in actU16 */ /* SBSW_VSECPRIM_WRITE_POINTER */
      actMemCpyByteArray(bufferPtr, &dataIN[lastBlockEnd], info->buffer_used); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */

      actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */  /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
    }
  }

  return retVal;
}

/***********************************************************************************************************************
 *  actSHA2_32_Finalize
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actSHA2_32_Finalize(
  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) info, /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  VSECPRIM_P2VAR_PARA(actU8) tempBuffer = (VSECPRIM_P2VAR_PARA(actU8))info->buffer;
  VSECPRIM_P2VAR_PARA(actU32) digest = (VSECPRIM_P2VAR_PARA(actU32))info->H;
  actU32 low_bitcount = info->low_count << 3;
  actU32 hi_bitcount = (info->hi_count << 3) | (info->low_count >> 29);
  actLengthType len = info->low_count & 0x3Fu;
  actLengthType pad_len = (actLengthType)(actHASH_BLOCK_SIZE_SHA256 - (2u * actSHA256_WORD_SIZE));

  actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */  /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */

  /* Pad byte '0x80' */
  tempBuffer[len] = 0x80u; /* SBSW_VSECPRIM_WRITE_ARRAY_NO_CHECK */
  len = len + 1u;

  /* Pad zeros */
  actMemset(&tempBuffer[len], 0u, (actLengthType)(actHASH_BLOCK_SIZE_SHA256 - len)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  if (len > pad_len)
  {
    actSHA2_32_Transform((VSECPRIM_P2CONST_PARA(actU8))tempBuffer, digest, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
    actMemset(tempBuffer, 0u, (actLengthType)pad_len); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  }

  /* Pad 64-bit input count to last 8 bytes in big endian format */
  actU32toBE(&tempBuffer[pad_len],                      hi_bitcount); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actU32toBE(&tempBuffer[pad_len+actSHA256_WORD_SIZE], low_bitcount); /* SBSW_VSECPRIM_CALL_FUNCTION */

  /* Transform last block */
  actSHA2_32_Transform((VSECPRIM_P2CONST_PARA(actU8))tempBuffer, digest, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

  /* Convert little endian SHA-256-Digest to big endian byte order */
  actCpyU32toBE(hash, digest, (actU32)info->result_length / actSHA256_WORD_SIZE); /* SBSW_VSECPRIM_CALL_FUNCTION */

  /* Wipe buffer */
  actMemset((VSECPRIM_P2VAR_PARA(actU8))&info->buffer[0], 0u, actHASH_BLOCK_SIZE_SHA256); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */

  actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */  /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */

  return actOK;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actSHA224Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actSHA224Init(VSECPRIM_P2VAR_PARA(actSHA224STRUCT) info)
{
  /* Initialize message digest */
  info->H[0] = 0xc1059ed8U; /* SBSW_VSECPRIM_WRITE_ARRAY */
  info->H[1] = 0x367cd507U; /* SBSW_VSECPRIM_WRITE_ARRAY */
  info->H[2] = 0x3070dd17U; /* SBSW_VSECPRIM_WRITE_ARRAY */
  info->H[3] = 0xf70e5939U; /* SBSW_VSECPRIM_WRITE_ARRAY */
  info->H[4] = 0xffc00b31U; /* SBSW_VSECPRIM_WRITE_ARRAY */
  info->H[5] = 0x68581511U; /* SBSW_VSECPRIM_WRITE_ARRAY */
  info->H[6] = 0x64f98fa7U; /* SBSW_VSECPRIM_WRITE_ARRAY */
  info->H[7] = 0xbefa4fa4U; /* SBSW_VSECPRIM_WRITE_ARRAY */

  /* Initialize count variables */
  info->low_count = 0u; /* SBSW_VSECPRIM_WRITE_POINTER */
  info->hi_count = 0u; /* SBSW_VSECPRIM_WRITE_POINTER */
  info->buffer_used = 0u; /* SBSW_VSECPRIM_WRITE_POINTER */
  info->result_length = actHASH_SIZE_SHA224; /* SBSW_VSECPRIM_WRITE_POINTER */

  return actOK;
}

/***********************************************************************************************************************
 *  actSHA224Update
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actSHA224Update(
  VSECPRIM_P2VAR_PARA(actSHA224STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN,
  actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  return actSHA2_32_Update((VSECPRIM_P2VAR_PARA(actSHA256STRUCT))info, dataIN, length, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
}

/***********************************************************************************************************************
 *  actSHA224Finalize
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actSHA224Finalize(
  VSECPRIM_P2VAR_PARA(actSHA224STRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  return actSHA2_32_Finalize((VSECPRIM_P2VAR_PARA(actSHA256STRUCT)) info, hash, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
}

/**********************************************************************************************************************
 *  actSHA256Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actSHA256Init(VSECPRIM_P2VAR_PARA(actSHA256STRUCT) info)
{
  /* initialize message digest */
  info->H[0] = 0x6a09e667U; /* SBSW_VSECPRIM_WRITE_ARRAY */
  info->H[1] = 0xbb67ae85U; /* SBSW_VSECPRIM_WRITE_ARRAY */
  info->H[2] = 0x3c6ef372U; /* SBSW_VSECPRIM_WRITE_ARRAY */
  info->H[3] = 0xa54ff53aU; /* SBSW_VSECPRIM_WRITE_ARRAY */
  info->H[4] = 0x510e527fU; /* SBSW_VSECPRIM_WRITE_ARRAY */
  info->H[5] = 0x9b05688cU; /* SBSW_VSECPRIM_WRITE_ARRAY */
  info->H[6] = 0x1f83d9abU; /* SBSW_VSECPRIM_WRITE_ARRAY */
  info->H[7] = 0x5be0cd19U; /* SBSW_VSECPRIM_WRITE_ARRAY */

  /* initialize count variables */
  info->low_count = 0u; /* SBSW_VSECPRIM_WRITE_POINTER */
  info->hi_count = 0u; /* SBSW_VSECPRIM_WRITE_POINTER */
  info->buffer_used = 0u; /* SBSW_VSECPRIM_WRITE_POINTER */
  info->result_length = actHASH_SIZE_SHA256; /* SBSW_VSECPRIM_WRITE_POINTER */

  return actOK;
}

/***********************************************************************************************************************
 *  actSHA256Update
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actSHA256Update(
  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN,
  actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  return actSHA2_32_Update((VSECPRIM_P2VAR_PARA(actSHA256STRUCT)) info, dataIN, length, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
}

/***********************************************************************************************************************
 *  actSHA256Finalize
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actSHA256Finalize(
  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  return actSHA2_32_Finalize((VSECPRIM_P2VAR_PARA(actSHA256STRUCT)) info, hash, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTSHA2_32_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  END OF FILE: actSHA2_32.c
 *********************************************************************************************************************/
