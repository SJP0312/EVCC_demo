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
/*!        \file  actSM3.c
 *        \brief  Core SM3 implementation.
 *
 *      \details This file is part of the embedded systems library actLib
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
#define ACTSM3_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "actISM3.h"
#include "actSM3.h"
#include "actUtilities.h"
#include "actWatchdog.h"
#include "actConfig.h"

#if (VSECPRIM_ACTSM3_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

/* PRQA S 3218 EOF */ /* MD_VSECPRIM_8.7 */

/***********************************************************************************************************************
 *  LOCAL CONSTANTS
 **********************************************************************************************************************/
# define VSECPRIM_START_SEC_CONST_32BIT
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VSECPRIM_ROM(VSECPRIM_LOCAL, actU32) actSM3_T_j[] =
{
  /* 0 <= j <= 15:  0x79CC4519 <<< j */
  0x79CC4519U, 0xF3988A32U, 0xE7311465U, 0xCE6228CBU,
  0x9CC45197U, 0x3988A32FU, 0x7311465EU, 0xE6228CBCU,
  0xCC451979U, 0x988A32F3U, 0x311465E7U, 0x6228CBCEU,
  0xC451979CU, 0x88A32F39U, 0x11465E73U, 0x228CBCE6U,

  /* 16 <= j <= 63   0x7A879D8A <<< j */
  0x9D8A7A87U, 0x3B14F50FU, 0x7629EA1EU, 0xEC53D43CU,
  0xD8A7A879U, 0xB14F50F3U, 0x629EA1E7U, 0xC53D43CEU,
  0x8A7A879DU, 0x14F50F3BU, 0x29EA1E76U, 0x53D43CECU,
  0xA7A879D8U, 0x4F50F3B1U, 0x9EA1E762U, 0x3D43CEC5U,
  0x7A879D8AU, 0xF50F3B14U, 0xEA1E7629U, 0xD43CEC53U,
  0xA879D8A7U, 0x50F3B14FU, 0xA1E7629EU, 0x43CEC53DU,
  0x879D8A7AU, 0x0F3B14F5U, 0x1E7629EAU, 0x3CEC53D4U,
  0x79D8A7A8U, 0xF3B14F50U, 0xE7629EA1U, 0xCEC53D43U,
  0x9D8A7A87U, 0x3B14F50FU, 0x7629EA1EU, 0xEC53D43CU,
  0xD8A7A879U, 0xB14F50F3U, 0x629EA1E7U, 0xC53D43CEU,
  0x8A7A879DU, 0x14F50F3BU, 0x29EA1E76U, 0x53D43CECU,
  0xA7A879D8U, 0x4F50F3B1U, 0x9EA1E762U, 0x3D43CEC5U
};

# define VSECPRIM_STOP_SEC_CONST_32BIT
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/* combinatorial functions, round 00...15 */
# define actSM3_FF00(X, Y, Z)                                         ((X) ^ (Y) ^ (Z))
# define actSM3_GG00(X, Y, Z)                                         ((X) ^ (Y) ^ (Z))

/* combinatorial functions, round 16...63 */
/* actSM3_FF16(X, Y, Z)   (((X) & (Y)) | ( (X) & (Z))  | ((Y) & (Z))) */
# define actSM3_FF16(X, Y, Z)                                         (((X) & (Y)) | (((X) | (Y)) & (Z)))                 /* minor optimization */
# define actSM3_GG16(X, Y, Z)                                         (((X) & (Y)) | (~(X) & (Z)))

/* permutation functions */
# define actSM3_P0(X)                                                 ((X) ^ (actRotl ((X),  9u)) ^ (actRotl ((X), 17u)))   /* used in compression */
# define actSM3_P1(X)                                                 ((X) ^ (actRotl ((X), 15u)) ^ (actRotl ((X), 23u)))   /* used in expansion */

/* expansion MACRO
 * expand Wj from Wj-16, Wj-9, Wj-3, Wj-13 and Wj-6
 * Wj-16 is the same word as Wj
 * (it's no longer used and overwritten!) */
# define actSM3_EXPAND(W, j)                                          actSM3_P1(W[(j - 16u) % 16u] ^ W[(j - 9u) % 16u] ^ actRotl(W[(j - 3u) % 16u], 15u)) ^ actRotl(W[(j - 13u) % 16u], 7u) ^ W[(j - 6u) % 16u]

/* rename working variables */
# define actSM3_A                                                     (T[0u])
# define actSM3_B                                                     (T[1u])
# define actSM3_C                                                     (T[2u])
# define actSM3_D                                                     (T[3u])
# define actSM3_E                                                     (T[4u])
# define actSM3_F                                                     (T[5u])
# define actSM3_G                                                     (T[6u])
# define actSM3_H                                                     (T[7u])

/* access "expanded" input data */
# define actSM3_W(j)                                                  (W[(j) % 16u])
# define actSM3_Wtic(j)                                               (W[(j) % 16u] ^ W[((j) + 4u) % 16u])

/* compression MACRO */
/* instead of shifting and reducing the constant value ACTSM3_T_j in each iteration,
 * the shifted and reduced values are precomputed and stored in the ACTSM3_T_j-Array
 */
# define actSM3_COMPRESS(T, W, j, FF, GG)                             do {                                                                       \
                                                                      actU32 actSM3_A12 = actRotl(actSM3_A, 12u);                               \
                                                                      actU32 actSM3_SS1 = actRotl(actSM3_A12 + actSM3_E + actSM3_T_j[(j)], 7u); \
                                                                      actU32 actSM3_SS2 = actSM3_SS1 ^ actSM3_A12;                              \
                                                                      actU32 actSM3_TT1 = FF + actSM3_D + actSM3_SS2 + actSM3_Wtic(j);          \
                                                                      actU32 actSM3_TT2 = GG + actSM3_H + actSM3_SS1 + actSM3_W(j);             \
                                                                      actSM3_D = actSM3_C;                                                      \
                                                                      actSM3_C = actRotl(actSM3_B,  9u);                                        \
                                                                      actSM3_B = actSM3_A;                                                      \
                                                                      actSM3_A = actSM3_TT1;                                                    \
                                                                      actSM3_H = actSM3_G;                                                      \
                                                                      actSM3_G = actRotl(actSM3_F, 19u);                                        \
                                                                      actSM3_F = actSM3_E;                                                      \
                                                                      actSM3_E = actSM3_P0(actSM3_TT2);                                         \
                                                                      } while (0u)

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if (actSM3_SPEED_UP < 1u) /* COV_VSECPRIM_NO_SAFE_CONFIG XX */

/**********************************************************************************************************************
 *  expand()
 *********************************************************************************************************************/
/*! \brief          Calls the macro to expand the given input data.
 *  \details        -
 *  \param[in]      W  data block that is to expanded
 *  \param[in,out]  j  the index of the data block to be expanded, ranges from j = 16 to 67.
 *  \return         Returns the expanded data block
 *  \pre            All pointers must be valid.
 *                  W must be at least of length 16u - so at least 16 * 4 bytes = 64 bytes.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(actU32) actSM3_expand(
  VSECPRIM_P2CONST_PARA(actU32) W,
  const actU8 j);

/**********************************************************************************************************************
 *  compress()
 *********************************************************************************************************************/
/*! \brief          Calls the macro to compress the given input data.
 *  \details        -
 *  \param[in,out]  T    (in) buffer to store the compressed data
 *                       (out) compressed data
 *  \param[in]      W   data block that has to be compressed
 *  \param[in,out]  j   index of block to be processed (ranges from 0 to 63)
 *  \param[in,out]  FF  either FF00 or FF16, depending on the value of j
 *  \param[in,out]  GG  either GG00 or GG16, depending on the value of j
 *  \pre            All pointers must be valid.
 *                  T must be at least of length 8u - so at least 8 * 4 bytes = 32 bytes.
 *                  W must be at least of length 16u - so at least 16 * 4 bytes = 64 bytes.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(void) actSM3_compress(
  VSECPRIM_P2VAR_PARA(actU32) T,
  VSECPRIM_P2CONST_PARA(actU32) W,
  actU8 j,
  actU32 FF,
  actU32 GG);

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/* implement expansion and compression as functions */
/***********************************************************************************************************************
 *  expand()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_LOCAL_FUNC(actU32) actSM3_expand(
  VSECPRIM_P2CONST_PARA(actU32) W,
  const actU8 j)
{
  return actSM3_EXPAND(W, j);
}

/***********************************************************************************************************************
 *  compress()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_LOCAL_FUNC(void) actSM3_compress(
  VSECPRIM_P2VAR_PARA(actU32) T,
  VSECPRIM_P2CONST_PARA(actU32) W,
  actU8 j,
  actU32 FF,
  actU32 GG)
{
  actSM3_COMPRESS(T, W, j, FF, GG);
}
# else
/* implement expansion and compression as macros */

#  define actSM3_expand(W, j)                                         actSM3_EXPAND((W), (j))
#  define actSM3_compress(T, W, j, FF, GG)                            actSM3_COMPRESS((T), (W), (j), (FF), (GG))
# endif

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  actSM3_Transform()
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
/* PRQA S 6010, 6030 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC */
VSECPRIM_FUNC(void) actSM3_Transform(
  VSECPRIM_P2CONST_PARA(actU8) Bi,
  VSECPRIM_P2VAR_PARA(actU32) Vi,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actU32 W[16u];
  actU32 T[8u];

  /* import data block */
  actCpyBEtoU32(W, Bi, actHASH_BLOCK_SIZE_SM3);

  /* copy hash value to working variables */
  actMemCpy32Bit(T, Vi, actSM3_HASH_WORDS);

  actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */

# if (actSM3_SPEED_UP < 2u) /* COV_VSECPRIM_NO_SAFE_CONFIG XX */
  {
    /* perform hashing */
    /* interleave compression with expansion */
    actU8 j;

    for (j = 0u; j < 16u; j++)
    {
      actSM3_compress(T, W, j, actSM3_FF00(actSM3_A, actSM3_B, actSM3_C), actSM3_GG00(actSM3_E, actSM3_F, actSM3_G));
      W[j % 16u] = actSM3_expand(W, (actU8)(j + 16u));
      actL3trigger(watchdog); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
    }

    for (j = 16u; j < 52u; j++)
    {
      actSM3_compress(T, W, j, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));

      /* expansion from j = 16 to 67 */
      W[j % 16u] = actSM3_expand(W, (actU8) (j + 16u));
      actL3trigger(watchdog); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
    }

    for (j = 52u; j < actHASH_BLOCK_SIZE_SM3; j++)
    {
      actSM3_compress(T, W, j, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));
      /* further expansion NOT needed */
      actL3trigger(watchdog); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
    }
    actL2trigger(watchdog); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
  }
# else
      /* perform hashing
       * interleave compression with expansion
       * all loops unrolled */

      actSM3_compress(T, W,  0u, actSM3_FF00(actSM3_A, actSM3_B, actSM3_C), actSM3_GG00(actSM3_E, actSM3_F, actSM3_G));    W[ 0u % 16u] = actSM3_expand(W,  0u + 16u);
      actSM3_compress(T, W,  1u, actSM3_FF00(actSM3_A, actSM3_B, actSM3_C), actSM3_GG00(actSM3_E, actSM3_F, actSM3_G));    W[ 1u % 16u] = actSM3_expand(W,  1u + 16u);
      actSM3_compress(T, W,  2u, actSM3_FF00(actSM3_A, actSM3_B, actSM3_C), actSM3_GG00(actSM3_E, actSM3_F, actSM3_G));    W[ 2u % 16u] = actSM3_expand(W,  2u + 16u);
      actSM3_compress(T, W,  3u, actSM3_FF00(actSM3_A, actSM3_B, actSM3_C), actSM3_GG00(actSM3_E, actSM3_F, actSM3_G));    W[ 3u % 16u] = actSM3_expand(W,  3u + 16u);
      actSM3_compress(T, W,  4u, actSM3_FF00(actSM3_A, actSM3_B, actSM3_C), actSM3_GG00(actSM3_E, actSM3_F, actSM3_G));    W[ 4u % 16u] = actSM3_expand(W,  4u + 16u);
      actSM3_compress(T, W,  5u, actSM3_FF00(actSM3_A, actSM3_B, actSM3_C), actSM3_GG00(actSM3_E, actSM3_F, actSM3_G));    W[ 5u % 16u] = actSM3_expand(W,  5u + 16u);
      actSM3_compress(T, W,  6u, actSM3_FF00(actSM3_A, actSM3_B, actSM3_C), actSM3_GG00(actSM3_E, actSM3_F, actSM3_G));    W[ 6u % 16u] = actSM3_expand(W,  6u + 16u);
      actSM3_compress(T, W,  7u, actSM3_FF00(actSM3_A, actSM3_B, actSM3_C), actSM3_GG00(actSM3_E, actSM3_F, actSM3_G));    W[ 7u % 16u] = actSM3_expand(W,  7u + 16u);
      actSM3_compress(T, W,  8u, actSM3_FF00(actSM3_A, actSM3_B, actSM3_C), actSM3_GG00(actSM3_E, actSM3_F, actSM3_G));    W[ 8u % 16u] = actSM3_expand(W,  8u + 16u);
      actSM3_compress(T, W,  9u, actSM3_FF00(actSM3_A, actSM3_B, actSM3_C), actSM3_GG00(actSM3_E, actSM3_F, actSM3_G));    W[ 9u % 16u] = actSM3_expand(W,  9u + 16u);
      actSM3_compress(T, W, 10u, actSM3_FF00(actSM3_A, actSM3_B, actSM3_C), actSM3_GG00(actSM3_E, actSM3_F, actSM3_G));    W[10u % 16u] = actSM3_expand(W, 10u + 16u);
      actSM3_compress(T, W, 11u, actSM3_FF00(actSM3_A, actSM3_B, actSM3_C), actSM3_GG00(actSM3_E, actSM3_F, actSM3_G));    W[11u % 16u] = actSM3_expand(W, 11u + 16u);
      actSM3_compress(T, W, 12u, actSM3_FF00(actSM3_A, actSM3_B, actSM3_C), actSM3_GG00(actSM3_E, actSM3_F, actSM3_G));    W[12u % 16u] = actSM3_expand(W, 12u + 16u);
      actSM3_compress(T, W, 13u, actSM3_FF00(actSM3_A, actSM3_B, actSM3_C), actSM3_GG00(actSM3_E, actSM3_F, actSM3_G));    W[13u % 16u] = actSM3_expand(W, 13u + 16u);
      actSM3_compress(T, W, 14u, actSM3_FF00(actSM3_A, actSM3_B, actSM3_C), actSM3_GG00(actSM3_E, actSM3_F, actSM3_G));    W[14u % 16u] = actSM3_expand(W, 14u + 16u);
      actSM3_compress(T, W, 15u, actSM3_FF00(actSM3_A, actSM3_B, actSM3_C), actSM3_GG00(actSM3_E, actSM3_F, actSM3_G));    W[15u % 16u] = actSM3_expand(W, 15u + 16u);
      actL3trigger(watchdog); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */

      actSM3_compress(T, W, 16u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[16u % 16u] = actSM3_expand(W, 16u + 16u);
      actSM3_compress(T, W, 17u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[17u % 16u] = actSM3_expand(W, 17u + 16u);
      actSM3_compress(T, W, 18u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[18u % 16u] = actSM3_expand(W, 18u + 16u);
      actSM3_compress(T, W, 19u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[19u % 16u] = actSM3_expand(W, 19u + 16u);
      actSM3_compress(T, W, 20u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[20u % 16u] = actSM3_expand(W, 20u + 16u);
      actSM3_compress(T, W, 21u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[21u % 16u] = actSM3_expand(W, 21u + 16u);
      actSM3_compress(T, W, 22u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[22u % 16u] = actSM3_expand(W, 22u + 16u);
      actSM3_compress(T, W, 23u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[23u % 16u] = actSM3_expand(W, 23u + 16u);
      actSM3_compress(T, W, 24u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[24u % 16u] = actSM3_expand(W, 24u + 16u);
      actSM3_compress(T, W, 25u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[25u % 16u] = actSM3_expand(W, 25u + 16u);
      actSM3_compress(T, W, 26u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[26u % 16u] = actSM3_expand(W, 26u + 16u);
      actSM3_compress(T, W, 27u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[27u % 16u] = actSM3_expand(W, 27u + 16u);
      actSM3_compress(T, W, 28u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[28u % 16u] = actSM3_expand(W, 28u + 16u);
      actSM3_compress(T, W, 29u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[29u % 16u] = actSM3_expand(W, 29u + 16u);
      actSM3_compress(T, W, 30u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[30u % 16u] = actSM3_expand(W, 30u + 16u);
      actSM3_compress(T, W, 31u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[31u % 16u] = actSM3_expand(W, 31u + 16u);
      actSM3_compress(T, W, 32u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[32u % 16u] = actSM3_expand(W, 32u + 16u);
      actSM3_compress(T, W, 33u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[33u % 16u] = actSM3_expand(W, 33u + 16u);
      actSM3_compress(T, W, 34u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[34u % 16u] = actSM3_expand(W, 34u + 16u);
      actSM3_compress(T, W, 35u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[35u % 16u] = actSM3_expand(W, 35u + 16u);
      actSM3_compress(T, W, 36u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[36u % 16u] = actSM3_expand(W, 36u + 16u);
      actSM3_compress(T, W, 37u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[37u % 16u] = actSM3_expand(W, 37u + 16u);
      actSM3_compress(T, W, 38u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[38u % 16u] = actSM3_expand(W, 38u + 16u);
      actSM3_compress(T, W, 39u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[39u % 16u] = actSM3_expand(W, 39u + 16u);
      actSM3_compress(T, W, 40u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[40u % 16u] = actSM3_expand(W, 40u + 16u);
      actSM3_compress(T, W, 41u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[41u % 16u] = actSM3_expand(W, 41u + 16u);
      actSM3_compress(T, W, 42u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[42u % 16u] = actSM3_expand(W, 42u + 16u);
      actSM3_compress(T, W, 43u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[43u % 16u] = actSM3_expand(W, 43u + 16u);
      actSM3_compress(T, W, 44u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[44u % 16u] = actSM3_expand(W, 44u + 16u);
      actSM3_compress(T, W, 45u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[45u % 16u] = actSM3_expand(W, 45u + 16u);
      actSM3_compress(T, W, 46u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[46u % 16u] = actSM3_expand(W, 46u + 16u);
      actSM3_compress(T, W, 47u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[47u % 16u] = actSM3_expand(W, 47u + 16u);
      actSM3_compress(T, W, 48u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[48u % 16u] = actSM3_expand(W, 48u + 16u);
      actSM3_compress(T, W, 49u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[49u % 16u] = actSM3_expand(W, 49u + 16u);
      actSM3_compress(T, W, 50u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[50u % 16u] = actSM3_expand(W, 50u + 16u);
      actSM3_compress(T, W, 51u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));    W[51u % 16u] = actSM3_expand(W, 51u + 16u);
      actL3trigger(watchdog); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */

      actSM3_compress(T, W, 52u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));
      actSM3_compress(T, W, 53u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));
      actSM3_compress(T, W, 54u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));
      actSM3_compress(T, W, 55u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));
      actSM3_compress(T, W, 56u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));
      actSM3_compress(T, W, 57u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));
      actSM3_compress(T, W, 58u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));
      actSM3_compress(T, W, 59u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));
      actSM3_compress(T, W, 60u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));
      actSM3_compress(T, W, 61u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));
      actSM3_compress(T, W, 62u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));
      actSM3_compress(T, W, 63u, actSM3_FF16(actSM3_A, actSM3_B, actSM3_C), actSM3_GG16(actSM3_E, actSM3_F, actSM3_G));
      actL3trigger(watchdog); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
# endif

  /* XOR working variables into hash value */
  actXOR32(Vi, T, actSM3_HASH_WORDS);

  actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTSM3_ENABLED == STD_ON) */

/***********************************************************************************************************************
 *  END OF FILE: actSM3.c
 **********************************************************************************************************************/
