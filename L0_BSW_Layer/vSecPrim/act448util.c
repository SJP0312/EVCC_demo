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
/*!       \file  act448util.c
 *       \brief  Curve448 utilities
 *
 *      \details This file is part of the embedded systems library cvActLib.
 *               Implements the following RFCs:
 *               https:/ /tools.ietf.org/html/draft-irtf-cfrg-eddsa-08
 *               https:/ /tools.ietf.org/html/rfc7748
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

#define ACT448UTIL_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "act448util.h"
#include "actWatchdog.h"
#include "actUtilities.h"

#if (VSECPRIM_ACT448UTIL_ENABLED == STD_ON)

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

# if (actBN_BITS_PER_DIGIT == 8u) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */
#  define ACT_448_DIGIT_INDEX                                         (4u)
# elif (actBN_BITS_PER_DIGIT == 16u)
#  define ACT_448_DIGIT_INDEX                                         (2u)
# else /* (actBN_BITS_PER_DIGIT == 32u) */
#  define ACT_448_DIGIT_INDEX                                         (1u)
# endif
# define LS_BIT_TO_MS_BIT_CST                                         (7u)
# define MS_BIT_TO_LS_BIT_CST                                         (7u)
# define MOST_SIGNIFICANT_BIT_OF_BYTE                                 (0x80u)

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

# define VSECPRIM_START_SEC_CONST_UNSPECIFIED
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* prime:
 * p = 2^448 - 2^224 - 1
 *   = 726838724295606890549323807888004534353641360687318060281490199180612328166730772686396383698676545930088884461843637361053498018365439
 * (448 bit long)
 */
VSECPRIM_ROM(VSECPRIM_LOCAL, actBNDIGIT) edwards448Prime[BNDIGITS_456] = /* PRQA S 3218 */ /* MD_VSECPRIM_8.7 */
{
  DIGITs(0xFFFFFFFFU), DIGITs(0xFFFFFFFFU), DIGITs(0xFFFFFFFFU), DIGITs(0xFFFFFFFFU),
  DIGITs(0xFFFFFFFFU), DIGITs(0xFFFFFFFFU), DIGITs(0xFFFFFFFFU), DIGITs(0xFFFFFFFEU),
  DIGITs(0xFFFFFFFFU), DIGITs(0xFFFFFFFFU), DIGITs(0xFFFFFFFFU), DIGITs(0xFFFFFFFFU),
  DIGITs(0xFFFFFFFFU), DIGITs(0xFFFFFFFFU), 0x00u
};

/* curve constant (Edwards):
 * d = -39081 % p
 *   = 726838724295606890549323807888004534353641360687318060281490199180612328166730772686396383698676545930088884461843637361053498018326358
 * (448 bit long)
 */
VSECPRIM_ROM(VSECPRIM_LOCAL, actBNDIGIT) edwards448CurveConst[BNDIGITS_456] = /* PRQA S 3218 */ /* MD_VSECPRIM_8.7 */
{
   DIGITs(0xFFFF6756U), DIGITs(0xFFFFFFFFU), DIGITs(0xFFFFFFFFU), DIGITs(0xFFFFFFFFU),
   DIGITs(0xFFFFFFFFU), DIGITs(0xFFFFFFFFU), DIGITs(0xFFFFFFFFU), DIGITs(0xFFFFFFFEU),
   DIGITs(0xFFFFFFFFU), DIGITs(0xFFFFFFFFU), DIGITs(0xFFFFFFFFU), DIGITs(0xFFFFFFFFU),
   DIGITs(0xFFFFFFFFU), DIGITs(0xFFFFFFFFU), 0x00u
};

/* group order:
 * q = 2^446 - 0x8335dc163bb124b65129c96fde933d8d723a70aadc873d6d54a7bb0d
 *   = 181709681073901722637330951972001133588410340171829515070372549795146003961539585716195755291692375963310293709091662304773755859649779
 *   = 0x3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7CCA23E9C44EDB49AED63690216CC2728DC58F552378C292AB5844F3
 * (446 bit long)
 */
VSECPRIM_ROM(VSECPRIM_LOCAL, actBNDIGIT) edwards448GroupOrder[BNDIGITS_456] = /* PRQA S 3218 */ /* MD_VSECPRIM_8.7 */
{
   DIGITs(0xab5844f3U), DIGITs(0x2378c292U), DIGITs(0x8dc58f55U), DIGITs(0x216cc272U),
   DIGITs(0xaed63690U), DIGITs(0xc44edb49U), DIGITs(0x7cca23e9U), DIGITs(0xffffffffU),
   DIGITs(0xffffffffU), DIGITs(0xffffffffU), DIGITs(0xffffffffU), DIGITs(0xffffffffU),
   DIGITs(0xffffffffU), DIGITs(0x3fffffffU), 0x00u
};

/* base point in Edwards coordinates
 * bX = 224580040295924300187604334099896036246789641632564134246125461686950415467406032909029192869357953282578032075146446173674602635247710 (447 bit long)
 * bY = 298819210078481492676017930443930673437544040154080242095928241372331506189835876003536878655418784733982303233503462500531545062832660 (447 bit long)
 */
VSECPRIM_ROM(VSECPRIM_LOCAL, actHomogeneousPointEd448) edwards448BasePoint = /* PRQA S 3218 */ /* MD_VSECPRIM_8.7 */
{
  /* X */
   {
     DIGITs(0xC70CC05EU), DIGITs(0x2626A82BU), DIGITs(0x8B00938EU), DIGITs(0x433B80E1U),
     DIGITs(0x2AB66511U), DIGITs(0x12AE1AF7U), DIGITs(0xA3D3A464U), DIGITs(0xEA6DE324U),
     DIGITs(0x470F1767U), DIGITs(0x9E146570U), DIGITs(0x22BF36DAU), DIGITs(0x221D15A6U),
     DIGITs(0x6BED0DEDU), DIGITs(0x4F1970C6U), 0x00u
   },
  /* Y */
   {
     DIGITs(0xF230FA14U), DIGITs(0x9808795BU), DIGITs(0x4ED7C8ADU), DIGITs(0xFDBD132CU),
     DIGITs(0xE67C39C4U), DIGITs(0x3AD3FF1CU), DIGITs(0x05A0C2D7U), DIGITs(0x87789C1EU),
     DIGITs(0x6CA39840U), DIGITs(0x4BEA7373U), DIGITs(0x56C9C762U), DIGITs(0x88762037U),
     DIGITs(0x6EB6BC24U), DIGITs(0x693F4671U), 0x00u
   },
  /* Z = 1 */
   {
     DIGITs(0x00000001U), DIGITs(0x00000000U), DIGITs(0x00000000U), DIGITs(0x00000000U), /*lint !e572 */
     DIGITs(0x00000000U), DIGITs(0x00000000U), DIGITs(0x00000000U), DIGITs(0x00000000U), /*lint !e572 */
     DIGITs(0x00000000U), DIGITs(0x00000000U), DIGITs(0x00000000U), DIGITs(0x00000000U), /*lint !e572 */
     DIGITs(0x00000000U), DIGITs(0x00000000U), 0x00u /*lint !e572 */
    }
};

/* Constant for square root:
 * (p + 1) / 4
 * = 181709681073901722637330951972001133588410340171829515070372549795153082041682693171599095924669136482522221115460909340263374504591360
 * = 0x3fffffffffffffffffffffffffffffffffffffffffffffffffffffffc0000000000000000000000000000000000000000000000000000000
 * (446 bit long)
 */
VSECPRIM_ROM(VSECPRIM_LOCAL, actBNDIGIT) edwards448SquareRootConstant[BNDIGITS_456] = /* PRQA S 3218 */ /* MD_VSECPRIM_8.7 */
{
  DIGITs(0x00000000U), DIGITs(0x00000000U), DIGITs(0x00000000U), DIGITs(0x00000000U), /*lint !e572 */
  DIGITs(0x00000000U), DIGITs(0x00000000U), DIGITs(0xc0000000U), DIGITs(0xffffffffU), /*lint !e572 */
  DIGITs(0xffffffffU), DIGITs(0xffffffffU), DIGITs(0xffffffffU), DIGITs(0xffffffffU),
  DIGITs(0xffffffffU), DIGITs(0x3fffffffU), 0x00u
};

/* m in Barrett reduction mod q:
 * m = 12486994201263968925526388919172665222994392570659884603436627838502436525599741561595256720318532645199348130880001343719115547893759685562115303
 *   = 0x400000000000000000000000000000000000000000000000000000008335DC163BB124B65129C96FDE933D8D723A70AADC873D6D54A7BB0E0D00AA4E7
 *   = floor(2^928 / q)
 * (483 bit long)
 */

VSECPRIM_ROM(VSECPRIM_LOCAL, actBNDIGIT) mqBarrett[BNDIGITS_512] = /* PRQA S 3218 */ /* MD_VSECPRIM_8.7 */
{
DIGITs(0xd00aa4e7U), DIGITs(0x4a7bb0e0U), DIGITs(0xc873d6d5U), DIGITs(0x23a70aadU),
DIGITs(0xe933d8d7U), DIGITs(0x129c96fdU), DIGITs(0xbb124b65U), DIGITs(0x335dc163U),
DIGITs(0x00000008U), DIGITs(0x00000000U), DIGITs(0x00000000U), DIGITs(0x00000000U), /*lint !e572 */
DIGITs(0x00000000U), DIGITs(0x00000000U), DIGITs(0x00000000U), DIGITs(0x00000004U)  /*lint !e572 */
};

# define VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
  act448_reduce()
 **********************************************************************************************************************/
/*! \brief      Barrett reduction
 *  \details    This function performs the operation r = a mod n using Barrett's reduction method.
 *              When called from act448_reduceP(), k = 896.
 *              When called from act448_reduceQ(), k = 928.
 *  \param[in,out]  r  In: Pointer to buffer; Out: Result of operation.
 *  \param[in]      a  Pointer to dividend.
 *  \param[in]      q  Pointer to constant expression q = ((a * m) / 2^k)
 *  \param[in]      n  Pointer to divisor.
 *  \pre          Pointers must be valid.
 *                The buffer referenced by r must provide at least BNDIGITS_456 many actBNDIGITS.
 *                The buffer referenced by a must provide at least BNDIGITS_456 many actBNDIGITs.
 *                The buffer referenced by q must provide at least BNDIGITS_456 many actBNDIGITs.
 *                The buffer referenced by n must provide at least BNDIGITS_456 many actBNDIGITs.
 *  \context    TASK
 *  \reentrant  TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(void) act448_reduce(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) q,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) n);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  act448_reduce()
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
 */
VSECPRIM_LOCAL_FUNC(void) act448_reduce(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) q,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) n)
{
  actU32 d;
  actBNDDIGIT tempBuffer;

  /* (2)   r = q * n = ((a * m) / 2^k) * n
   *
   *    we just calculate the BNDIGITS_456 LSdigits:
   *    the MSdigits will NOT influence the final result
   *      (which is just BNDIGITS_456 "long")
   *
   */
  actBNSetZero(r, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
  for (d = 0u; d < BNDIGITS_456; d++)
  {
    actU32 j;
    actBNDDIGIT digit;

    digit = n[d];
    tempBuffer = 0u;
    for (j = 0u; j < ((actU32)BNDIGITS_456 - d); j++) /* FETA_VSECPRIM_UPPER_BOUNDARY_CHECKED_BY_CALLEE */
    {
      tempBuffer += ((actBNDDIGIT)q[j]) * digit;
      tempBuffer += r[d + j];
      r[d + j] = actBNLoWord(tempBuffer); /* SBSW_VSECPRIM_WRITE_ARRAY_NO_CHECK */
      tempBuffer = actBNHiWord(tempBuffer);
    }
  }

  /* (3)   r = a - r = a - (((a * m) / 2^k) * n)
   *
   *  We just calculate the BNDIGITS_456 LSdigits:
   *    the MSdigits will turn to ZERO anyway since result has to be smaller than 2*modulus
   *    where modulus is prime p (448 bits) or order q (446 bits).
   */
  actBNSub(a, r, r, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */

  /* (4)   r -= n    (while still too large)
   *
   *    ONE subtraction should be enough:
   *    * just in case we'll repeat this...
   */
  while (actCOMPARE_EQUAL <= actBNCompare(r, n, BNDIGITS_456, FALSE)) /* SBSW_VSECPRIM_CALL_FUNCTION */ /* FETA_VSECPRIM_BARRETT_REDUCTION */
  {
    actBNSub(r, n, r, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  act448_initCore()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(void) act448_initCore(VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) ws)
{
  VSECPRIM_P2VAR_PARA(actBNRING) ring;

  /* Initialize core variables */
  actBNCopy(ws->prime, edwards448Prime, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNCopy(ws->order, edwards448GroupOrder, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNCopy(ws->precomputedBarrettConstant, mqBarrett, BNDIGITS_512);  /* SBSW_VSECPRIM_CALL_FUNCTION */

  /* Set p-ring */
  ring = &(ws->pRing);
  ring->m = ws->prime; /* SBSW_VSECPRIM_WRITE_POINTER */
  ring->m_length = BNDIGITS_456; /* SBSW_VSECPRIM_WRITE_POINTER */

  /* Set q-ring */
  ring = &(ws->qRing);
  ring->m = ws->order; /* SBSW_VSECPRIM_WRITE_POINTER */
  ring->m_length = BNDIGITS_456; /* SBSW_VSECPRIM_WRITE_POINTER */
}

/**********************************************************************************************************************
 *  act448_reduceP()
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
 */
VSECPRIM_FUNC(void) act448_reduceP(
  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) ws,  /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a)
{
  VSECPRIM_P2VAR_PARA(actBNDIGIT) q = ws->auxVar.tempQ;

 /************************************
  * Barrett with k = 896
  *************************************/

  /*
   * - Step (1) of Barrett reduction: Set m = ((2^896)/prime448), 449 bit long
   * - m = 0x
   *          1  0000 0000  0000 0000  0000 0000
   *  0000 0000  0000 0000  0000 0000  0000 0001
   *  0000 0000  0000 0000  0000 0000  0000 0000
   *  0000 0000  0000 0000  0000 0002
   *    = (little endian)
   * {0000 0002, 0000 0000, 0000 0000, 0000 0000
   *  0000 0000, 0000 0000, 0000 0000, 0000 0001
   *  0000 0000, 0000 0000, 0000 0000, 0000 0000
   *  0000 0000, 0000 0000, 0000 0001}
   * - Compute q = (a*m/(2^896))
   *
   * Description of the code below for actBN_BITS_PER_DIGIT = 32u (throughout the whole comment):
   *   Set T = 2^32.
   *   m = 2 + T^7 + T^14
   *   a = sum_{i = 0}^28 a_i T^i    (For the example, length_a = 29. Code depends on the length of a > 28)
   *   ma = 2 * T^0 * a0 + ____ + 2 * T^7 * a7 + ____ + 2 * T^14 * a14 + ______ + 2 * T^28 * a28
   *                            +     T 7 * a0 + ____ +     T^14 * a7  + ______ +     T^28 * a21 + T^29 * a22 + ____ + T^35 * a28
   *                                                  +     T^14 * a0  + ______ +     T^28 * a14 + T^29 * a15 + ____ + T^35 * a22 + ____ + T^42 * a28
   *       -------- Right shift by 896: 896/32 = 28 digits are deleted --------##########################################################################
   *   Only the digits underlined by ### are kept.
   *
   * Do not forget to compute the carry after each addition!
   *
   * We get 6 loops - Case actBN_BITS_PER_DIGIT = 32u:
   *   loop (1) from digit 0                 to digit 6
   *   loop (2) from digit 7                 to digit 13
   *   loop (3) from digit 14                to digit 27
   *   --> Up to this point, we only compute the carry, since the digits themselves will be discarded
   *       in the right shift later
   *   --> From now on, we also store the value of each digit itself (and compute the carry).
   *   loop (4) from digit 28                to digit BNDIGITS_912 - 1 (= 28, if actBN_BITS_PER_DIGIT = 32u)
   *   loop (5) from digit BNDIGITS_912      to digit BNDIGITS_912 + 6
   *   loop (6) from digit BNDIGITS_912 + 7  to digit BNDIGITS_912 + 13
   *
   * Hint for loop (4): If you only considered the multiplied digits and the necessary additions,
   * loop (4) would be a part of loop (3) and in total, only 5 loops were necessary.
   * However, the digit with index 28 is the first digit which is not deleted by the right shift. Thus, this digit is handled in a
   * separate for loop, where not only the carry is computed but also the value of the digit itself.
   *
   * Hint: d > offset1 > offset2, each offet is one for - loop behind the other(or behind d)
   */

  actBNDDIGIT tempBuffer = 0u;
  actU8 d;
  actU8 offset1 = 0u;
  actU8 offset2 = 0u;
  actU8 offsetQ = 0u;

  /* Loop 1: For loop 1 to loop 3, only compute the carry */
  for (d = 0u; d < (ACT_448_DIGIT_INDEX * 7u); d++)
  {
    tempBuffer += ((actBNDDIGIT)a[d]) * 2u; /* PRQA S 2841 */ /* MD_VSECPRIM_INVALID_PTR_ACT448UTIL_ACCESSWITHD */
    tempBuffer = actBNHiWord(tempBuffer);
  }

  /* Loop 2 */
  for (d = (ACT_448_DIGIT_INDEX * 7u); d < (ACT_448_DIGIT_INDEX * 14u); d++)
  {
    tempBuffer += ((actBNDDIGIT)a[d]) * 2u; /* PRQA S 2841 */ /* MD_VSECPRIM_INVALID_PTR_ACT448UTIL_ACCESSWITHD */
    tempBuffer += ((actBNDDIGIT)a[offset1]); /* PRQA S 2841 */ /* MD_VSECPRIM_INVALID_PTR_ACT448UTIL_ACCESSWITHOFFSET1 */
    tempBuffer = actBNHiWord(tempBuffer);
    offset1++;
  }

  /* Loop 3 */
  for (d = (ACT_448_DIGIT_INDEX * 14u); d < (ACT_448_DIGIT_INDEX * 28u); d++)
  {
    tempBuffer += ((actBNDDIGIT)a[d]) * 2u; /* PRQA S 2841 */ /* MD_VSECPRIM_INVALID_PTR_ACT448UTIL_ACCESSWITHD */
    tempBuffer += ((actBNDDIGIT)a[offset1]); /* PRQA S 2841 */ /* MD_VSECPRIM_INVALID_PTR_ACT448UTIL_ACCESSWITHOFFSET1 */
    tempBuffer += ((actBNDDIGIT)a[offset2]); /* PRQA S 2841 */ /* MD_VSECPRIM_INVALID_PTR_ACT448UTIL_ACCESSWITHOFFSET2 */
    tempBuffer = actBNHiWord(tempBuffer);
    offset1++;
    offset2++;
  }

  /* Loop 4: from this point, also save the result of the operations */
  for (d = (ACT_448_DIGIT_INDEX * 28u); d < BNDIGITS_912; d++)
  {
    tempBuffer += ((actBNDDIGIT)a[d]) * 2u; /* PRQA S 2841 */ /* MD_VSECPRIM_INVALID_PTR_ACT448UTIL_ACCESSWITHD */
    tempBuffer += ((actBNDDIGIT)a[offset1]); /* PRQA S 2841 */ /* MD_VSECPRIM_INVALID_PTR_ACT448UTIL_ACCESSWITHOFFSET1 */
    tempBuffer += ((actBNDDIGIT)a[offset2]); /* PRQA S 2841 */ /* MD_VSECPRIM_INVALID_PTR_ACT448UTIL_ACCESSWITHOFFSET2 */
    q[offsetQ] = actBNLoWord(tempBuffer); /* SBSW_VSECPRIM_WRITE_ARRAY */ /* PRQA S 2841 */ /* MD_VSECPRIM_INVALID_PTR_ACT448UTIL_ACCESSWITHQ */
    tempBuffer = actBNHiWord(tempBuffer);
    offset1++;
    offset2++;
    offsetQ++;
  }

  /* Loop 5 */
  for (d = BNDIGITS_912; d < (BNDIGITS_912 + (ACT_448_DIGIT_INDEX * 7u)); d++)
  {
    tempBuffer += ((actBNDDIGIT)a[offset1]); /* PRQA S 2841 */ /* MD_VSECPRIM_INVALID_PTR_ACT448UTIL_ACCESSWITHOFFSET1 */
    tempBuffer += ((actBNDDIGIT)a[offset2]); /* PRQA S 2841 */ /* MD_VSECPRIM_INVALID_PTR_ACT448UTIL_ACCESSWITHOFFSET2 */
    q[offsetQ] = actBNLoWord(tempBuffer); /* SBSW_VSECPRIM_WRITE_ARRAY */ /* PRQA S 2841 */ /* MD_VSECPRIM_INVALID_PTR_ACT448UTIL_ACCESSWITHQ */
    tempBuffer = actBNHiWord(tempBuffer);
    offset1++;
    offset2++;
    offsetQ++;
  }

  /* Loop 6 */
  for (d = (BNDIGITS_912 + (ACT_448_DIGIT_INDEX * 7u)); d < (BNDIGITS_912 + (ACT_448_DIGIT_INDEX * 14u)); d++)
  {
    tempBuffer += ((actBNDDIGIT)a[offset2]); /* PRQA S 2841 */ /* MD_VSECPRIM_INVALID_PTR_ACT448UTIL_ACCESSWITHOFFSET2 */
    q[offsetQ] = actBNLoWord(tempBuffer); /* SBSW_VSECPRIM_WRITE_ARRAY */ /* PRQA S 2841 */ /* MD_VSECPRIM_INVALID_PTR_ACT448UTIL_ACCESSWITHQ */
    tempBuffer = actBNHiWord(tempBuffer);
    offset2++;
    offsetQ++;
  }

  /* Remark: We do not need to save the last tempBuffer (i.e., the carry) in the last array position of q
   * since at this point, q is already completely filled, because
   * we know that a < p^2 < (2^448)^2 = 2^896 (this is a prerequisite for Barrett).
   * Hence, a can be represented in 896 bit. We currently provide 2*456 = 912 bit to represent a.
   * Thus, the most significant bits of the most significant digit are always 0, and therefore
   * the last carries will always be 0 and can be discarded.
   */

  /* Call act448_reduce() to perform step 2 - 4 of Barrett reduction */
  act448_reduce(r, a, ws->auxVar.tempQ, ws->prime); /* SBSW_VSECPRIM_CALL_FUNCTION */

}

/**********************************************************************************************************************
 *  act448_reduceQ()
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
 *
 *
 *
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(void) act448_reduceQ(
  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) ws, /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a)
{
  actBNDIGIT q[BNDIGITS_912 + BNDIGITS_512];
  actBNSetZero(q, BNDIGITS_912 + BNDIGITS_512); /* SBSW_VSECPRIM_CALL_FUNCTION */

  /* (1)   q = (a * m)
   * a: 912 bit, m: 483 bit --> a * m: 1395 bit
   * 1395 bits are 44  digits, if actBN_BITS_PER_DIGITS == 32
   *               88  digits, if actBN_BITS_PER_DIGITS == 16
   *               175 digits, if actBN_BITS_PER_DIGITS == 8.
   * The output buffer q is  45  digits long, if actBN_BITS_PER_DIGITS == 32
   *                         89  digits long, if actBN_BITS_PER_DIGITS == 16
   *                         178 digits long, if actBN_BITS_PER_DIGITS == 8.
   */
  actBNMult(a, BNDIGITS_912, ws->precomputedBarrettConstant, BNDIGITS_512, q, NULL_PTR); /* SBSW_VSECPRIM_CALL_FUNCTION */

/* (2) Implicit division by 2^928
 * After the cutoff/division by 2^928, the remaining buffer q is a buffer of length
 * ((digit length of buffer q) - BNDIGITS_928) digits with value length ((digit length of a * m) - BNDIGITS_928),
 *              i.e.,
 *   16 digits with value length 15 digits, if actBN_BITS_PER_DIGITS == 32
 *   31 digits with value length 30 digits, if actBN_BITS_PER_DIGITS == 16
 *   62 digits with value length 59 digits, if actBN_BITS_PER_DIGITS == 8.
 */
/* (3) Call act448_reduce() to perform step 2 - 4 of Barrett reduction */
  act448_reduce(r, a, &q[BNDIGITS_928], ws->order); /* SBSW_VSECPRIM_CALL_FUNCTION */
}

/**********************************************************************************************************************
 *  act448_addModP()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(void) act448_addModP(
  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) ws, /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b)
{
  /* r = (a + b) mod p */
  actBNModAdd(a, b, r, &(ws->pRing), NULL_PTR); /* SBSW_VSECPRIM_CALL_FUNCTION */
}

/**********************************************************************************************************************
 *  act448_subModP()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(void) act448_subModP(
  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) ws, /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b)
{
  /* r = (a - b) mod p */
  actBNModSub(a, b, r, &(ws->pRing), NULL_PTR); /* SBSW_VSECPRIM_CALL_FUNCTION */
}

/**********************************************************************************************************************
 *  act448_mulModP()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(void) act448_mulModP(
  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) ws,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b)
{
  /* c = (a * b) */
  /* bitLength(a) <= 456, bitLength(b) <= 456  ==> bitLength(a*b) <= 912 */
  actBNMult(a, BNDIGITS_456, b, BNDIGITS_456, ws->auxVar.temp1, NULL_PTR); /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* r = c mod p */
  act448_reduceP(ws, r, ws->auxVar.temp1); /* SBSW_VSECPRIM_CALL_FUNCTION */
}

/**********************************************************************************************************************
 *  act448_powModP()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(void) act448_powModP(
  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) ws,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actU8 dig;

  actBNSetOne(r, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */

  /* Iterate over the digits of "b" */
  for (dig = 0u; dig < BNDIGITS_456; dig++)
  {
    actBNDIGIT digit = b[dig];
    actU8 bit;

    /* Iterate over the bits of "digit" */
    for (bit = 0u; bit < actBN_BITS_PER_DIGIT; bit++)
    {
      /* Multiply */
      if (actBNGetBitOfDigit(digit, bit))
      {
        act448_mulModP(ws, r, a, r);  /* multiply */ /* SBSW_VSECPRIM_CALL_FUNCTION */
      }
      act448_mulModP(ws, a, a, a);  /* square */ /* SBSW_VSECPRIM_CALL_FUNCTION */

      ifWDisL2(0u == (bit % 2u), watchdog); /* every 2..4 multiplications */ /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_POINTER_CALL_WATCHDOG */
    }
  }
}

/**********************************************************************************************************************
 *  act448_invModP()
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
 */
VSECPRIM_FUNC(actRETURNCODE) act448_invModP(
  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) ws,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE retVal = actOK;

  if (actBNIsZero(a, BNDIGITS_456) == TRUE) /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    retVal = actEXCEPTION_UNKNOWN;
  }
  else
  {
    /* Copy data into local buffer */
    actBNCopy(ws->auxVar.tempE, a, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
    actBNCopy(ws->auxVar.tempF, ws->prime, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
    /* Calculate exponent b = p - 2 */
    ws->auxVar.tempF[0] = (actBNDIGIT)(ws->auxVar.tempF[0] - (actBNDIGIT) 2u); /* SBSW_VSECPRIM_WRITE_ARRAY */

    /* r = (a ^ b) mod p */
    act448_powModP(ws, r, ws->auxVar.tempE, ws->auxVar.tempF, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }
  return retVal;
}

/**********************************************************************************************************************
 *  act448_sqrtModP()
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
VSECPRIM_FUNC(actBoolean) act448_sqrtModP(
  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) ws,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actBoolean retVal = FALSE;
  actBNCopy(ws->auxVar.tempG, a, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNCopy(ws->auxVar.tempH, edwards448SquareRootConstant, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */

  /* candidate: r = a ^ ((p + 1) / 4) mod p */
  act448_powModP(ws, ws->auxVar.tempE, ws->auxVar.tempG, ws->auxVar.tempH, watchdog); /* tempE = candidate */ /* SBSW_VSECPRIM_CALL_FUNCTION */

  /* square; if identical -> sqrt found */
  act448_mulModP(ws, ws->auxVar.tempF, ws->auxVar.tempE, ws->auxVar.tempE); /* square */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  if (actBNCompare(ws->auxVar.tempF, a, BNDIGITS_456, FALSE) == actCOMPARE_EQUAL) /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    /* found! */
    actBNCopy(r, ws->auxVar.tempE, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */

    actL2trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
    retVal = TRUE;
  }

  actL2trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
  return retVal;
}

/**********************************************************************************************************************
 * act448_addModQ()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(void) act448_addModQ(
  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) ws, /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b)
{
  /* Big number modular addition */
  actBNModAdd(a, b, r, &(ws->qRing), NULL_PTR); /* SBSW_VSECPRIM_CALL_FUNCTION */
}

/**********************************************************************************************************************
 * act448_mulModQ()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_FUNC(void) act448_mulModQ(
  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) ws, /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b)
{
  /* r = (a * b) mod q */
  /* Big number multiplication c = a * b */
  /* bitLength(a) <= 456, bitLength(b) <= 456  ==> bitLength(a*b) <= 912 */
  actBNMult(a, BNDIGITS_456, b, BNDIGITS_456, ws->auxVar.temp1, NULL_PTR); /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* Perform Barrett reduction for r = c mod q */
  act448_reduceQ(ws, r, ws->auxVar.temp1); /* SBSW_VSECPRIM_CALL_FUNCTION */
}

/**********************************************************************************************************************
 * act448_encodePoint()
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
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) act448_encodePoint(
  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) ws,
  VSECPRIM_P2VAR_PARA(actU8) buffer,
  VSECPRIM_P2CONST_PARA(actHomogeneousPointEd448) point,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE retVal = actOK;
  /* Transform point projective -> affine coordinates
   * tempA will be fully initialized before usage in act448_invModP */
  retVal = act448_invModP(ws, ws->auxVar.tempA, point->Z, watchdog); /* A = 1 / Z */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  if (retVal == actOK)
  {
    act448_mulModP(ws, ws->auxVar.tempB, point->X, ws->auxVar.tempA); /* X / Z = X * A */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_mulModP(ws, ws->auxVar.tempC, point->Y, ws->auxVar.tempA); /* Y / Z = Y * A */ /* SBSW_VSECPRIM_CALL_FUNCTION */

    /* MSBit (y) = lsBit (x) */
    /* MSbit (y) will be ZERO, because p = 2^448 - 2^224 - 1. In fact, even MSbyte (y) = 0. */
    /* Remark for next line:
     *  - tempB[0] is the least significant DIGIT of x
     *  - Shift by 7 and actU8 cast -> get '*000 0000' where '*' is the least significant bit of x
     *  - Store the produced byte in the most significant DIGIT of y, i.e., tempC[BNDIGITS_456 - 1u]
     *  - In every config, the least significant byte of the most significant DIGIT of y corresponds to the
     *    byte 57 of y in little endian representation.
     */
    ws->auxVar.tempC[BNDIGITS_456 - 1u] = (actBNDIGIT)(ws->auxVar.tempC[BNDIGITS_456 - 1u] | (actBNDIGIT)((ws->auxVar.tempB[0] << LS_BIT_TO_MS_BIT_CST) & ((actBNDIGIT)MOST_SIGNIFICANT_BIT_OF_BYTE))); /* SBSW_VSECPRIM_WRITE_ARRAY */
    /* Store as little endian byte array */
    act448_BNStoreLE(buffer, ws->auxVar.tempC); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }

  actL2trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */

  return retVal;
}

/**********************************************************************************************************************
 *  act448_decodePoint()
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
 *
 *
 *
 *
 *
 *
 *
 */
 /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
VSECPRIM_FUNC(actRETURNCODE) act448_decodePoint(
  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) ws,
  VSECPRIM_P2VAR_PARA(actHomogeneousPointEd448) point,
  VSECPRIM_P2CONST_PARA(actU8) buffer,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actU8 x_0;
  actU8 d;
  actBNDIGIT xNOTzero = 0u;
  actRETURNCODE retVal = actOK;

  /* 10. Load from LE byte array */
  act448_BNLoadLE(point->Y, buffer, BNBYTES_456); /* SBSW_VSECPRIM_CALL_FUNCTION */

  /* Extract information for the recovery of the x-coordinate */
  /* 11. x_0 = lsBit (x) = MSBit (y) */
  /* Remark for next line:
   *  - In every config, the least significant byte of the most significant DIGIT of y corresponds to the
   *    byte 57 of y in little endian representation
   *  - (Y[BNDIGITS_456 - 1u] >> 7u) shifts the critical bit to the right
   */
  x_0 = (actU8)(point->Y[BNDIGITS_456 - 1u] >> MS_BIT_TO_LS_BIT_CST); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
  /* 12. y = clear MSBit (y) */
  point->Y[BNDIGITS_456 - 1u] = 0x00u; /* SBSW_VSECPRIM_WRITE_ARRAY */
  /* Check if y < p */
  if (actBNCompare(point->Y, ws->prime, BNDIGITS_456, FALSE) == actCOMPARE_SMALLER) /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    /* 13. z = 1 */
    actBNSetOne(point->Z, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */

    /* 20. Evaluate curve equation to get x^2 */
    /* 21. x^2 = (u/v) = (y^2 -1) / (d * y^2 - 1) (mod p) */
    act448_mulModP(ws, ws->auxVar.tempD, point->Y, point->Y); /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_subModP(ws, ws->auxVar.tempA, ws->auxVar.tempD, point->Z); /* tempA = u = y^2 -1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    actBNCopy(ws->auxVar.tempC, edwards448CurveConst, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_mulModP(ws, ws->auxVar.tempB, ws->auxVar.tempD, ws->auxVar.tempC); /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_subModP(ws, ws->auxVar.tempB, ws->auxVar.tempB, point->Z); /* tempB = v = d * y^2 - 1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    actL2trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */

    /* Compute u/v, since x-coordinate is either sqrt(u/v) or -sqrt(u/v) */
    /* 22. compute u/v (mod p) */
    retVal = act448_invModP(ws, ws->auxVar.tempC, ws->auxVar.tempB, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
    if (retVal == actOK)
    {
      act448_mulModP(ws, ws->auxVar.tempD, ws->auxVar.tempA, ws->auxVar.tempC);  /* tempD = (u/v) = x^2 */ /* SBSW_VSECPRIM_CALL_FUNCTION */

      /* 30. Compute the correct x-coordinate */
      /* 31. If no square root, decoding fails */
      if (FALSE == act448_sqrtModP(ws, point->X, ws->auxVar.tempD, watchdog)) /* p.x = x */ /* SBSW_VSECPRIM_CALL_FUNCTION */
      {
        retVal = actEXCEPTION_UNKNOWN; /* NO square-root found */
      }
      else
      {
        for (d = 0u; d < BNDIGITS_456; ++d)
        {
          xNOTzero |= point->X[d];
        }

        /* 32. If x == 0 and x_0 == 1, decoding fails */
        if ((xNOTzero == 0x0u) && (x_0 == 0x1u))
        {
          retVal = actEXCEPTION_UNKNOWN; /* NOT a valid point */
        }
        else
        {
          /* 33. If x_0 != x mod 2 (wrong square root), set x = (0 - x) (mod p) (other candidate) */
          if (x_0 != (point->X[0] & 1u))
          {
            actBNSetZero(ws->auxVar.tempB, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
            act448_subModP(ws, point->X, ws->auxVar.tempB, point->X); /* SBSW_VSECPRIM_CALL_FUNCTION */
          }
        }
      }
    }
  }
  else
  {
    retVal = actEXCEPTION_UNKNOWN;
  }

  actL2trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
  return retVal;
}
/**********************************************************************************************************************
 *  act448_addPoint()
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
 *
 *
 */
VSECPRIM_FUNC(void) act448_addPoint(
  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) ws,
  VSECPRIM_P2VAR_PARA(actHomogeneousPointEd448) r, /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  VSECPRIM_P2CONST_PARA(actHomogeneousPointEd448) p,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{

  /* #10 A = r.Z * p.Z */
  act448_mulModP(ws, ws->auxVar.tempA, r->Z, p->Z); /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* #20 B = A^2 */
  act448_mulModP(ws, ws->auxVar.tempB, ws->auxVar.tempA, ws->auxVar.tempA); /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* #30 C = r.X * p.X */
  act448_mulModP(ws, ws->auxVar.tempC, r->X, p->X); /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* #40 D = r.Y * p.Y */
  act448_mulModP(ws, ws->auxVar.tempD, r->Y, p->Y); /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* #50 E = d*C*D */
  act448_mulModP(ws, ws->auxVar.tempH, ws->auxVar.tempC, ws->auxVar.tempD); /* H = C*D */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  act448_mulModP(ws, ws->auxVar.tempE, edwards448CurveConst, ws->auxVar.tempH); /* E = d*H */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* #60 F = B-E */
  act448_subModP(ws, ws->auxVar.tempF, ws->auxVar.tempB, ws->auxVar.tempE); /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* #70 G = B+E */
  act448_addModP(ws, ws->auxVar.tempG, ws->auxVar.tempB, ws->auxVar.tempE); /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* #80 H = (r.X+r.Y)*(p.X+p.Y) */
  act448_addModP(ws, ws->auxVar.tempB, r->X, r->Y); /* B = (r.X + r.Y) */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  act448_addModP(ws, ws->auxVar.tempE, p->X, p->Y); /* E = (p.X + p.Y) */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  act448_mulModP(ws, ws->auxVar.tempH, ws->auxVar.tempB, ws->auxVar.tempE); /* H = B*E */ /* SBSW_VSECPRIM_CALL_FUNCTION */

  actL2trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */

  /* #90 r.X = A*F*(H-C-D) */
  act448_subModP(ws, ws->auxVar.tempB, ws->auxVar.tempH, ws->auxVar.tempC); /* B = H-C */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  act448_subModP(ws, ws->auxVar.tempB, ws->auxVar.tempB, ws->auxVar.tempD); /* B = B-D */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  act448_mulModP(ws, ws->auxVar.tempB, ws->auxVar.tempF, ws->auxVar.tempB); /* B = F*B */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  act448_mulModP(ws, r->X, ws->auxVar.tempA, ws->auxVar.tempB); /* X3 = A*B */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* #100 r.Y = A*G*(D-C) */
  act448_subModP(ws, ws->auxVar.tempB, ws->auxVar.tempD, ws->auxVar.tempC); /* B = D-C */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  act448_mulModP(ws, ws->auxVar.tempB, ws->auxVar.tempG, ws->auxVar.tempB); /* B = G*B */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  act448_mulModP(ws, r->Y, ws->auxVar.tempA, ws->auxVar.tempB); /* Y3 = A*B */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* #110 r.Z = F*G */
  act448_mulModP(ws, r->Z, ws->auxVar.tempF, ws->auxVar.tempG); /* Y3 = F*G */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  actL2trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
}

/**********************************************************************************************************************
 *  act448_doublePoint()
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
 *
 */
VSECPRIM_FUNC(void) act448_doublePoint(
  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) ws,
  VSECPRIM_P2VAR_PARA(actHomogeneousPointEd448) r, /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /* #10  A  = r.X + r.Y */
  act448_addModP(ws, ws->auxVar.tempA, r->X, r->Y); /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* #20  B  = A^2 */
  act448_mulModP(ws, ws->auxVar.tempB, ws->auxVar.tempA, ws->auxVar.tempA); /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* #30  C  = (r.X)^2 */
  act448_mulModP(ws, ws->auxVar.tempC, r->X, r->X); /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* #40  D  = (r.Y)^2 */
  act448_mulModP(ws, ws->auxVar.tempD, r->Y, r->Y); /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* #50  E  = C+D */
  act448_addModP(ws, ws->auxVar.tempE, ws->auxVar.tempC, ws->auxVar.tempD); /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* #60  H  = (r.Z)^2 */
  act448_mulModP(ws, ws->auxVar.tempH, r->Z, r->Z); /* SBSW_VSECPRIM_CALL_FUNCTION */

  actL2trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */

  /* #70  G  = E-2*H */
  act448_addModP(ws, ws->auxVar.tempA, ws->auxVar.tempH, ws->auxVar.tempH); /* A = 2*H */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  act448_subModP(ws, ws->auxVar.tempG, ws->auxVar.tempE, ws->auxVar.tempA); /* G = E-A */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* #80  r.X = (B-E)*G */
  act448_subModP(ws, ws->auxVar.tempA, ws->auxVar.tempB, ws->auxVar.tempE); /* A = B-E */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  act448_mulModP(ws, r->X, ws->auxVar.tempA, ws->auxVar.tempG); /* r.X = A*G */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* #90  r.Y = E*(C-D) */
  act448_subModP(ws, ws->auxVar.tempA, ws->auxVar.tempC, ws->auxVar.tempD); /* A = C-D */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  act448_mulModP(ws, r->Y, ws->auxVar.tempE, ws->auxVar.tempA); /* r.X = A*G */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* #100 r.Z = E*G */
  act448_mulModP(ws, r->Z, ws->auxVar.tempE, ws->auxVar.tempG); /* r.X = A*G */ /* SBSW_VSECPRIM_CALL_FUNCTION */

  actL2trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
}

/**********************************************************************************************************************
 *  act448_mulPoint()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_FUNC(void) act448_mulPoint(
  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) ws,
  VSECPRIM_P2VAR_PARA(actHomogeneousPointEd448) r,
  VSECPRIM_P2VAR_PARA(actHomogeneousPointEd448) p,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) s,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /* initialize the result to the neutral element of the group: r = (0, 1, 1) (see 5.2.4 in rfc8032) */
  actBNSetZero(r->X, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetOne(r->Y, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetOne(r->Z, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
  act448_mulAddPoint(ws, r, p, s, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
}

/**********************************************************************************************************************
 *  act448_mulAddPoint()
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
VSECPRIM_FUNC(void) act448_mulAddPoint(
  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) ws,
  VSECPRIM_P2VAR_PARA(actHomogeneousPointEd448) r,
  VSECPRIM_P2VAR_PARA(actHomogeneousPointEd448) p,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) s,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actU8 dig;

  /* Iterate over the digits of "s" */
  for (dig = 0u; dig < BNDIGITS_456; dig++)
  {
    actU8 bit;
    actBNDIGIT digit = s[dig];

    /* Iterate over the bits of "digit" */
    for (bit = 0; bit < actBN_BITS_PER_DIGIT; bit++)
    {
      if (actBNGetBitOfDigit(digit, bit))
      {
        act448_addPoint(ws, r, p, watchdog);  /* add */ /* SBSW_VSECPRIM_CALL_FUNCTION */
      }
      act448_doublePoint(ws, p, watchdog);  /* double */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    }
  }
}

/**********************************************************************************************************************
 *  act448_mulBasePoint()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_FUNC(void) act448_mulBasePoint(
  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) ws,
  VSECPRIM_P2VAR_PARA(actHomogeneousPointEd448) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) s,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actHomogeneousPointEd448 p;

  /* Multiply base point */
  actBNCopy(p.X, edwards448BasePoint.X, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNCopy(p.Y, edwards448BasePoint.Y, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNCopy(p.Z, edwards448BasePoint.Z, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
  act448_mulPoint(ws, r, &p, s, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
}

/**********************************************************************************************************************
 *  act448_comparePoints()
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
VSECPRIM_FUNC(actRETURNCODE) act448_comparePoints(
  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) ws,
  VSECPRIM_P2CONST_PARA(actHomogeneousPointEd448) p,
  VSECPRIM_P2CONST_PARA(actHomogeneousPointEd448) q,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE result = actEXCEPTION_UNKNOWN;

  /* Compare x and y coordinates */
  act448_mulModP(ws, ws->auxVar.tempA, p->X, q->Z); /* SBSW_VSECPRIM_CALL_FUNCTION */
  act448_mulModP(ws, ws->auxVar.tempB, q->X, p->Z); /* SBSW_VSECPRIM_CALL_FUNCTION */

  if (actCOMPARE_EQUAL == actBNCompare(ws->auxVar.tempA, ws->auxVar.tempB, BNDIGITS_456, FALSE)) /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    act448_mulModP(ws, ws->auxVar.tempA, p->Y, q->Z); /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_mulModP(ws, ws->auxVar.tempB, q->Y, p->Z); /* SBSW_VSECPRIM_CALL_FUNCTION */

    if (actCOMPARE_EQUAL == actBNCompare(ws->auxVar.tempA, ws->auxVar.tempB, BNDIGITS_456, FALSE)) /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    {
      result = actOK;
    }
  }

  actL2trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
  return result;
}

/**********************************************************************************************************************
 *  act448_BNStoreLE()
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
 *
 *
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(void) act448_BNStoreLE(
  VSECPRIM_P2VAR_PARA(actU8) bytes,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) bigNum)
{
  actU32 b;
  VSECPRIM_P2VAR_PARA(actU8) bytesPtr = bytes;
  /* #10 Case actBN_BYTES_PER_DIGIT == 4: */
# if (actBN_BYTES_PER_DIGIT == 4u)
  /* #11 Stop after 14 loops (56 bytes stored) */
  for (b = BNDIGITS_456; b > 1u; b--)
  {
    actBNDIGIT tmp = bigNum[(BNDIGITS_456 - b)];

    bytesPtr[0] = (actU8)(tmp); /* SBSW_VSECPRIM_WRITE_ARRAY */
    bytesPtr[1] = (actU8)(tmp >> 8u); /* SBSW_VSECPRIM_WRITE_ARRAY */
    bytesPtr[2] = (actU8)(tmp >> 16u); /* SBSW_VSECPRIM_WRITE_ARRAY */
    bytesPtr[3] = (actU8)(tmp >> 24u); /* SBSW_VSECPRIM_WRITE_ARRAY */
    bytesPtr = &bytesPtr[4u];
  }
  /* By now, bytesPtr points to the last byte of input parameter 'bytes'. */
  /* #12 Copy the last byte independently */
  bytesPtr[0] = (actU8)bigNum[BNDIGITS_456 - 1u]; /* SBSW_VSECPRIM_WRITE_ARRAY */
  /* #20 Case actBN_BYTES_PER_DIGIT == 2: */
# elif (actBN_BYTES_PER_DIGIT == 2u) /* COV_VSECPRIM_NO_SAFE_CONFIG TX */
  /* #21 Stop after 28 loops (56 bytes stored) */
  for (b = BNDIGITS_456; b > 1u; b--)
  {
    actBNDIGIT tmp = bigNum[(BNDIGITS_456 - b)];

    bytesPtr[0] = (actU8)(tmp); /* SBSW_VSECPRIM_WRITE_ARRAY */
    bytesPtr[1] = (actU8)(tmp >> 8u); /* SBSW_VSECPRIM_WRITE_ARRAY */
    bytesPtr = &bytesPtr[2u];
  }
  /* By now, bytesPtr points to the last byte of input parameter 'bytes'. */
  /* #22 Copy the last byte independently */
  bytesPtr[0] = (actU8)bigNum[BNDIGITS_456 - 1u]; /* SBSW_VSECPRIM_WRITE_ARRAY */
  /* #30 Case actBN_BYTES_PER_DIGIT == 1: */
# elif (actBN_BYTES_PER_DIGIT == 1)
  /* #31 57 loops */
  for (b = BNDIGITS_456; b > 0u; b--)
  {
    actBNDIGIT tmp = bigNum[(BNDIGITS_456 - b)];
    bytesPtr[(bnLength - b)] = (actU8)(tmp); /* SBSW_VSECPRIM_WRITE_ARRAY */
  }
# else
#  error actBN_BYTES_PER_DIGIT value not supported
# endif
}

/**********************************************************************************************************************
 *  act448_BNLoadLE()
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
 */
VSECPRIM_FUNC(void) act448_BNLoadLE(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) bigNum,
  VSECPRIM_P2CONST_PARA(actU8) bytes,
  const actU32 byteLength)
{
  /* local variables */
  actBNDIGIT tmp = 0u;
  actLengthType k, b, offset = 0u;
  actLengthType bnLength = (byteLength + actBN_BYTES_PER_DIGIT - 1u) / (actBN_BYTES_PER_DIGIT);
  actLengthType rest = byteLength % actBN_BYTES_PER_DIGIT;
  actLengthType quotient = byteLength / actBN_BYTES_PER_DIGIT;

  /* 10. Load the last bytes in the last digit */
  for (k = 0u; k < rest; k++) /* FETA_VSECPRIM_UPPER_BOUNDARY_CHECKED_BY_CALLEE */
  {
    tmp = (actBNDIGIT)(tmp + (actBNDIGIT)(((actBNDIGIT)bytes[byteLength - (rest - k)]) << (8u * k))); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
  }

  bigNum[bnLength - 1u] = tmp; /* SBSW_VSECPRIM_WRITE_ARRAY_NO_CHECK */

  for (b = quotient; b > 0u; b--)
  {
# if (4u == actBN_BYTES_PER_DIGIT)
    /* 20. Case actBN_BYTES_PER_DIGIT == 4: Create 1 digit with 4 bytes */
    tmp = ((actBNDIGIT)(bytes[offset]));
    tmp += ((actBNDIGIT)(bytes[offset + 1u])) << 8u;
    tmp += ((actBNDIGIT)(bytes[offset + 2u])) << 16u;
    tmp += ((actBNDIGIT)(bytes[offset + 3u])) << 24u;
    offset += 4u;
# elif (2u == actBN_BYTES_PER_DIGIT) /* COV_VSECPRIM_NO_SAFE_CONFIG TX */
    /* 30. Case actBN_BYTES_PER_DIGIT == 2: Create 1 digit with 2 bytes */
    tmp = ((actBNDIGIT)(bytes[offset]));
    tmp = (actBNDIGIT)(tmp + (actBNDIGIT)(((actBNDIGIT)(bytes[offset + 1u])) << 8u));
    offset += 2u;
# elif (1u == actBN_BYTES_PER_DIGIT)
    /* 40. Case actBN_BYTES_PER_DIGIT == 1: Create 1 digit with 1 bytes */
    tmp = ((actBNDIGIT)(bytes[offset]));
    offset++;
# else
#  error actBN_BYTES_PER_DIGIT value not supported
# endif
    /* 50. Load computed digit in BigNum */
    bigNum[quotient - b] = tmp; /* SBSW_VSECPRIM_WRITE_ARRAY */
  }
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACT448UTIL_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  END OF FILE: act448util.c
 *********************************************************************************************************************/
