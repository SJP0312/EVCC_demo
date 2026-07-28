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
/*!        \file  actX448core.c
 *        \brief  Core X448 implementation.
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

#define ACTX448CORE_SOURCE
#define BITS_448                                                      448u

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "actX448core.h"
#include "actWatchdog.h"
#include "actUtilities.h"
#include "actBigNum.h"

#if (VSECPRIM_ACTX448CORE_ENABLED == STD_ON)

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

# define VSECPRIM_START_SEC_CONST_UNSPECIFIED
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* a24 = (A - 2) / 4, A = 156326 ('A' is the Montgomery curve constant used in Curve448 evaluation)
 * a24 = 39081 = 0x98A9
 */

VSECPRIM_ROM(VSECPRIM_LOCAL, actBNDIGIT) a24_448[BNDIGITS_456] = /* PRQA S 3218 */ /* MD_VSECPRIM_8.7 */
{
  DIGITs(0x000098A9U), DIGITs(0x00000000U), DIGITs(0x00000000U), DIGITs(0x00000000U),     /*lint !e572 */
  DIGITs(0x00000000U), DIGITs(0x00000000U), DIGITs(0x00000000U), DIGITs(0x00000000U),     /*lint !e572 */
  DIGITs(0x00000000U), DIGITs(0x00000000U), DIGITs(0x00000000U), DIGITs(0x00000000U),     /*lint !e572 */
  DIGITs(0x00000000U), DIGITs(0x00000000U), 0x00u                                           /*lint !e572 */
};

# define VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  actX448_cswap()
 **********************************************************************************************************************/
/*! \brief      Conditional swap function
 *  \details    This function implements the conditional swap function defined in RFC 7748 Chapter 5.
 *  \param[in]  swap  input for mask
 *  \param[in,out]  a  pointer to a
 *  \param[in,out]  b  pointer to b
 *  \context    TASK
 *  \reentrant  TRUE
 *  \pre        a, b must be valid pointers
 *              a, b must be of size BNDIGITS_456
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(void) actX448_cswap(
  actU32 swap,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) b);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actX448_cswap()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_LOCAL_FUNC(void) actX448_cswap(
  actU32 swap,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) b)
{
  actBNDIGIT mask = (actBNDIGIT)(0u - swap); /* PRQA S 2986 */ /* MD_VSECPRIM_REDUNDANT_OP */
  actBNDIGIT digit;
  actU8 d;

  for (d = 0; d < BNDIGITS_456; d++)
  {
    digit = mask & (a[d] ^ b[d]);
    a[d] ^= digit; /* SBSW_VSECPRIM_WRITE_ARRAY */
    b[d] ^= digit; /* SBSW_VSECPRIM_WRITE_ARRAY */
  }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actX448_initCore()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(void) actX448_initCore(VSECPRIM_P2VAR_PARA(actEdDHSTRUCT) ws) /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
{
  /* Initialize core */
  act448_initCore((VSECPRIM_P2VAR_PARA(actEdwardsCurveWs)) &ws->coreWS); /* SBSW_VSECPRIM_CALL_FUNCTION */
}

/**********************************************************************************************************************
 *  actX448_eval()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actX448_eval(
  VSECPRIM_P2VAR_PARA(actEdDHSTRUCT) ws, /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE retVal = actOK;

  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) coreWSptr = (VSECPRIM_P2VAR_PARA(actEdwardsCurveWs)) &ws->coreWS;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) x_1 = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) ws->basePointBuf.bnDigit_x_1);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) x_2 = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) coreWSptr->auxVar.tempA);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) z_2 = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) coreWSptr->auxVar.tempB);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) x_3 = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) coreWSptr->auxVar.tempC);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) z_3 = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) coreWSptr->auxVar.tempD);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) A   = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) coreWSptr->auxVar.tempE);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) B   = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) coreWSptr->auxVar.tempF);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) C   = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) coreWSptr->auxVar.tempG);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) D   = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) coreWSptr->auxVar.tempH);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) AA = A;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) BB = B;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) CB = C;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) DA = D;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) E = x_3;

  actU32 k_t;
  actU32 swap;
  actU16 i;

  /* x_1 is not set to 0 because we already saved uCoord in the union */
  actBNSetZero(x_2, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(z_2, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(x_3, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(z_3, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(A, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(B, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(C, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(D, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */

  /* Initialize */
  /* x_1 = u, no masking for X448 */
  actBNLoadLE(x_1, ws->basePointBuf.uCoord, actX448_KEY_SIZE); /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* x_2 = 1 */
  actBNSetOne(x_2, BNDIGITS_456); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* z_2 = 0 */
  actBNSetZero(z_2, BNDIGITS_456); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /*  x_2 = 0 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* x_3 = u, z_3 = 1 */
  actMemCpyWordArray(x_3, x_1, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actMemCpyWordArray(z_3, x_2, BNDIGITS_456); /* SBSW_VSECPRIM_CALL_FUNCTION */

  swap = 0u;
  for (i = 448u; i > 0u; i--)
  {
    k_t = ((actU32)ws->privateKey[(i-1u) / 8u] >> ((i-1u) & 0x07u)) & 0x01u;

    /* conditional swap */
    swap ^= k_t;
    actX448_cswap(swap, x_2, x_3); /* SBSW_VSECPRIM_CALL_FUNCTION */
    actX448_cswap(swap, z_2, z_3); /* SBSW_VSECPRIM_CALL_FUNCTION */
    swap = k_t;

    /* algorithm from https:/ /tools.ietf.org/html/rfc7748
     * has been re-ordered to save memory!
     *
     *  1. calculate A,  B,  C  and D
     *  2. calculate DA, CB, BB and AA
     *  3. calculate E
     *  4. calculate x_2, z_2, x_3, z_3
     */

    act448_addModP(coreWSptr, A, x_2, z_2);  /*  A   = x2 + z_2 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_subModP(coreWSptr, B, x_2, z_2);  /*  B   = x2 - z_2 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_addModP(coreWSptr, C, x_3, z_3);  /*  C   = x3 + z_3 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_subModP(coreWSptr, D, x_3, z_3);  /*  D   = x3 - z_3 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_mulModP(coreWSptr, DA, D, A);     /*  DA  =  D * A */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_mulModP(coreWSptr, CB, C, B);     /*  CB  =  C * B */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_mulModP(coreWSptr, BB, B, B);     /*  BB  =  B * B */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_mulModP(coreWSptr, AA, A, A);     /*  AA  =  A * A */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_subModP(coreWSptr, E, AA, BB);    /*  E   = AA - BB */ /* SBSW_VSECPRIM_CALL_FUNCTION */

    act448_mulModP(coreWSptr, x_2, AA, BB);  /*  x_2 = AA * BB */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    /* 5 multiplications + 5 additions */
    actL2trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */

    actMemCpyWordArray(BB, a24_448, BNDIGITS_456); /* BB  =           a24 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_mulModP(coreWSptr, z_2, BB, E);     /* z_2 =           a24 * E */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_addModP(coreWSptr, z_2, AA, z_2);   /* z_2 =      AA + a24 * E */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_mulModP(coreWSptr, z_2, E, z_2);    /* z_2 = E * (AA + a24 * E) */ /* SBSW_VSECPRIM_CALL_FUNCTION */

    act448_addModP(coreWSptr, x_3, DA, CB);    /* x_3 =  DA + CB */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_mulModP(coreWSptr, x_3, x_3, x_3);  /* x_3 = (DA + CB) ^2 */ /* SBSW_VSECPRIM_CALL_FUNCTION */

    act448_subModP(coreWSptr, z_3, DA, CB);    /* z_3 =        DA - CB */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_mulModP(coreWSptr, z_3, z_3, z_3);  /* z_3 =       (DA - CB) ^2 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_mulModP(coreWSptr, z_3, z_3, x_1);  /* z_3 = x_1 * (DA - CB) ^2 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    /* 5 multiplications + 3 additions */
    actL2trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
  }

  /* conditional swap */
  actX448_cswap(swap, x_2, x_3); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actX448_cswap(swap, z_2, z_3); /* SBSW_VSECPRIM_CALL_FUNCTION */

  /* return x_2 * z_2^-1 */
  retVal = act448_invModP(coreWSptr, z_3, z_2, watchdog); /* z_3 =      z_2^-1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  if (retVal == actOK)
  {
    act448_mulModP(coreWSptr, x_2, x_2, z_3);      /* x_2 = x2 * z_2^-1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_BNStoreLE(ws->basePointBuf.uCoord, x_2); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }

  actBNSetZero(coreWSptr->auxVar.tempA, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(coreWSptr->auxVar.tempB, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(coreWSptr->auxVar.tempC, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(coreWSptr->auxVar.tempD, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(coreWSptr->auxVar.tempE, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(coreWSptr->auxVar.tempF, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(coreWSptr->auxVar.tempG, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(coreWSptr->auxVar.tempH, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTX448CORE_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  END OF FILE: actX448core.c
 *********************************************************************************************************************/
