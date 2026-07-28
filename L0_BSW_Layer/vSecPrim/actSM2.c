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
/*!        \file  actSM2.c
 *         \unit  act_SM2
 *        \brief  Core SM2 implementation.
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

#define ACTSM2_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "actISM2.h"
#include "actSM2.h"
#include "actSM3.h"
#include "actECPoint.h"
#include "actECTools.h"

#if (VSECPRIM_ACTSM2_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  actSM2sp()
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
 *
 */
 /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
VSECPRIM_FUNC(actRETURNCODE) actSM2sp(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) e,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) d,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) s,
  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actECPOINT Prec, Q;
  VSECPRIM_P2CONST_PARA(actBNRING) n_field = &(wksp->baseData.Curve.n_field);
  actLengthType n_length = n_field->m_length;
  actLengthType p_length = wksp->baseData.Curve.p_field.m_length;
  VSECPRIM_P2CONST_PARA(actBNDIGIT) RR = n_field->RR;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) d_inv = wksp->baseData.Curve.t[actEC_BIGNUM_TMP - 1u]; /* PRQA S 3494 */ /* MD_VSECPRIM_CONST_BOOL_OPERAND */ /*lint !e506 */
  VSECPRIM_P2VAR_PARA(actBNDIGIT) t0 = wksp->baseData.Curve.t[0u];
  VSECPRIM_P2VAR_PARA(actBNDIGIT) t1 = wksp->baseData.Curve.t[1u];
  VSECPRIM_P2VAR_PARA(actBNDIGIT) k;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) d1;

  actRETURNCODE retVal = actOK, rng_callback_error; /* rng_error is an error code of the actPRNG_GET callback function */
  actBoolean found = FALSE;

  k = wksp->dataPair.privKeys.ephKey;
  Q.x = wksp->multG.kG.xcoord;
  Q.y = wksp->multG.kG.ycoord;
  Q.z = wksp->multG.kG.zcoord;
  Prec.x = wksp->curvePoint.precomputedPoint.xcoord;
  Prec.y = wksp->curvePoint.precomputedPoint.ycoord;
  d1 = Q.y;

  while (found == FALSE)
  {
    /* A3: pick a random number k in [1, n - 1] */
    rng_callback_error = actBNModRandomize(k, n_field, wksp->baseData.Curve.t, watchdog);
    if (rng_callback_error!= actOK)
    {
      found = TRUE;

      /* actBNModRandomize returns actEXCEPTION_UNKNOWN and actEXCEPTION_RANDOM besides actOK.
       * Map the two different error codes to a common one to simplify the return values of this function. */
      retVal = actEXCEPTION_RANDOM;
    }

    if (retVal == actOK)
    {
      /* A4: compute Q = [k]G */
      actECPMultG(k, &Prec, &Q, &wksp->baseData.Curve, watchdog);

      /* compute x-coordinate x1 */
      if (actECPToAffineFromMont(&Q, &(wksp->baseData.Curve), FALSE, watchdog) != actOK)
      {
        found = TRUE;
        retVal =  actEXCEPTION_UNKNOWN;
      }

      if (retVal == actOK)
      {
        /* store unreduced e to messageDigest since the value in e could be modified by actBNReduce.
         * The same applies to n_field->m */
        actBNDIGIT messageDigest[actECC_MAX_N_DIGIT_LEN + 1u] = {0u};
        actBNDIGIT n_modulus[actECC_MAX_N_DIGIT_LEN] = {0u};
        actBoolean isZero = FALSE;
        actRETURNCODE compareResult = actCOMPARE_EQUAL;

        actBNCopy(messageDigest, e, actBNGetDigitLength(actHASH_SIZE_SM3));
        actBNCopy(n_modulus, n_field->m, n_length);

        /* A5: calculate r = (e + x1) mod n */
        actBNCopy(t1, Q.x, p_length); /* t1 = x1 */
        actBNReduceSimple(n_field->m, n_length, t1, p_length, t0); /* t1 %= n */
        actBNSetZero(t0, n_length); /* set t0 to zero, as it has been used as a temporary variable in actBNReduceSimple() */

        /* Caution: the result of the reduction is stored in t0, as 1 extra digit is needed during reduction.
         * Unfortunately, r cannot provide this extra digit (without enlarging the workspace).
         * As messageDigest and n_modulus are not needed after this reduction, there is no need to change
         * them back to their value before reduction */
        retVal = actBNReduce(messageDigest, actECC_MAX_N_DIGIT_LEN, n_modulus, n_field->m_length, t0, watchdog); /* t0 = e mod n */
        actBNCopy(r, t0, n_length);

        if (retVal == actOK)
        {
          /* check if preconditions for actBNModAdd are fulfilled:
           * 1. buffers must be of size n: used buffers are bigger here, however r is of size n
           * 2. r + t1 < 2n: here we know r = e mod n so r < n and t1 = x1 mod n, so t1 < n, therefore r + t1 < 2n
           * -> preconditions are fulfilled */
          actBNModAdd(r, t1, r, n_field, watchdog); /* r = (e + x1) mod n */

          (void)actBNAdd(r, k, t0, n_length); /* -> t0 = r + k */

          /* return to step A3 if r = 0 or r + k = n */
          isZero = actBNIsZero(r, n_length);
          compareResult = actBNCompare(t0, n_field->m, n_length, TRUE);
          if ((isZero == FALSE) && (compareResult != actCOMPARE_EQUAL))
          {
            /* A6: calculate s = ((1 + d)^(-1) * (k - r * d)) mod n */
            /* compute first factor: ((1 + d)^(-1)) */
            actBNSetOne(t1, n_length);

            /*
             * check if preconditions for actBNModAdd are fulfilled:
             * 1. buffers must be of size n: used buffers are bigger here, however d is of size n
             * 2. d + t1 < 2n: here we know t1 = 1 < n, and
             *    as d is valid d is in the interval (0, n) (this is checked in actSM2Sign()) so d < n -> d + t1 = d + 1 < 2n
             * -> preconditions are fulfilled
             */
            actBNModAdd(d, t1, t1, n_field, watchdog); /* t1 = (t1 + d) mod n = (1 + d) mod n */
            actBNMontMul(t1, RR, d1, n_field, watchdog); /* transform d1 to Montgomery Representation by multiplication with Montgomery Constant RR */
            /* d_inv = (1 + d)^(-1) */
            actBNFieldInversion(d1, d_inv, n_field, wksp->baseData.Curve.t, watchdog);

            /* compute second factor: (k - r * d) */
            /* t0 = r * d * (R^(-1)) mod n */
            actBNMontMul(r, d, t0, n_field, watchdog);
            /* t1 = r * d mod n */
            actBNMontMul(t0, RR, t1, n_field, watchdog);
            /* t0 = k - r * d mod n */
            actBNModSub(k, t1, t0, n_field, watchdog);
            /* t1 = (k - r*d)*R mod n */
            actBNMontMul(t0, RR, t1, n_field, watchdog);

            /* compute product of both factors */
            /* t1 = (1+d)^(-1)*R * (k - r*d)*R mod n */
            actBNMontMul(d_inv, t0, t1, n_field, watchdog);
            /* t0 = (1 + d)^(-1) * (k - r * d) mod n */
            actBNMontMul(t1, RR, t0, n_field, watchdog);
            /* s = t1 */
            actBNCopy(s, t1, n_length);

            /* if s = 0 then go to step A3 */
            if (actBNIsZero(s, n_length) == FALSE)
            {
              found = TRUE;
            }
          }
          else
          {
            /* r = 0 or r + k = n; generate a new ephemeral key 'k'
             * found = FALSE; is already set */
          }
        }
        else
        {
          /* reducing the message modulus order n failed; abort signature generation */
          found = TRUE;
        }
      }
    }
  }
  return retVal;
}

/***********************************************************************************************************************
 *  actSM2vp()
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
 /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
VSECPRIM_FUNC(actRETURNCODE) actSM2vp(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) e,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) s,
  VSECPRIM_P2CONST_PARA(actECPOINT) Q,
  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE retVal = actOK;
  actECPOINT G, QG, point;
  VSECPRIM_P2CONST_PARA(actBNRING) n_field = &(wksp->baseData.Curve.n_field);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) t0 = wksp->baseData.Curve.t[0u];
  VSECPRIM_P2VAR_PARA(actBNDIGIT) t1 = wksp->baseData.Curve.t[1u];
  VSECPRIM_P2VAR_PARA(actBNDIGIT) R  = wksp->baseData.Curve.t[actEC_BIGNUM_TMP - 1u]; /* PRQA S 3494 */ /* MD_VSECPRIM_CONST_BOOL_OPERAND */ /*lint !e506 */
  actLengthType p_length = wksp->baseData.Curve.p_field.m_length;
  actLengthType p_bytes  = wksp->baseData.Curve.p_field.m_byte_length;
  actLengthType n_length = wksp->baseData.Curve.n_field.m_length;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) t = wksp->dataPair.u12.u1;

  G.x = wksp->curvePoint.basePoint.xcoord;
  G.y = wksp->curvePoint.basePoint.ycoord;
  QG.x = wksp->multG.QG.xcoord;
  QG.y = wksp->multG.QG.ycoord;
  QG.z = wksp->multG.QG.zcoord;
  point.x = wksp->Q.xcoord;
  point.y = wksp->Q.ycoord;
  point.z = wksp->Q.zcoord;

  /*  Step B5: calculate t = (r' + s') mod n, verification failed if t = 0 */
  /* check if preconditions for actBNModAdd are fulfilled:
   * 1. buffers must be of size n: used buffers are bigger here, however r, s are of size n
   * 2. r + s < 2n: r and s are in the interval: [1, n - 1], therefore r + s < 2n
   *    These ranges are checked in function actSM2Verify, before actSM2vp is called. */
  actBNModAdd(r, s, t, n_field, watchdog);
  if(actBNIsZero(t, n_length))
  {
   retVal = actVERIFICATION_FAILED;
  }

  if(retVal == actOK)
  {
    /* initialize base-point coordinates Gx, Gy, Gz */
    actBNSetOctetStringROM(G.x, p_length, wksp->baseData.Curve.G_R, p_bytes);
    actBNSetOctetStringROM(G.y, p_length, &wksp->baseData.Curve.G_R[p_bytes], p_bytes);
    G.is_affine = TRUE;
    G.is_infinity = FALSE;
    actECPToMont(Q, &wksp->baseData.Curve, watchdog);  /* convert Q to Montgomery Representation */

    /* check if Q is on curve before continuing */
    if (actECPointIsOnCurve(Q, &(wksp->baseData.Curve), watchdog) != actOK)
    {
      retVal = actEXCEPTION_PUBKEY;
    }

    if(retVal == actOK)
    {
      /* B6: Compute point(x1, x2) = [s]G + [t]PA */
      actECPSimMult(&G, Q, s, t, &QG, &point, &wksp->baseData.Curve, watchdog);

      /* Compute x-coordinate x1 of point */
      if (actECPToAffineFromMont(&point, &wksp->baseData.Curve, FALSE, watchdog) != actOK)
      {
        retVal = actEXCEPTION_UNKNOWN;
      }

      if (retVal == actOK)
      {
        /* store unreduced e to messageDigest since the value in e could be modified by actBNReduce the same applies to n_field->m */
        actBNDIGIT messageDigest[actECC_MAX_N_DIGIT_LEN + 1u] = {0u};
        actBNDIGIT n_modulus[actECC_MAX_N_DIGIT_LEN] = {0u};

        actBNCopy(messageDigest, e, actBNGetDigitLength(actHASH_SIZE_SM3));
        actBNCopy(n_modulus, n_field->m, n_length);

        /* Step B7: compute R = (e + x1) mod n */
        actBNCopy(t1, point.x, p_length); /* t1  = x1 */
        actBNReduceSimple(n_field->m, n_length, t1, p_length, t0); /* t1 %= n */
        actBNSetZero(t0, n_length);

        /* caution: the result of the reduction is stored in t0, as 1 extra digit is needed during reduction.
         * Unfortunately, R cannot provide this extra digit (without enlarging the workspace)
         * As messageDigest and n_modulus are not needed after this reduction, there is no need to change
         * them back to their value before reduction */
        retVal = actBNReduce(messageDigest, actECC_MAX_N_DIGIT_LEN, n_modulus, n_field->m_length, t0, watchdog);

        if (retVal == actOK)
        {
          actBNCopy(R, t0, n_length);
          actBNSetZero(t0, n_length);

          /* check if preconditions for actBNModAdd are fulfilled:
           * 1. buffers must be of size n: buffers are bigger here
           * 2. R + t1 < 2n: t1 = t1 mod n, so t1 < n and R = e mod n, so R < n and R + t1 < 2n */
          actBNModAdd(R,  t1,  R,  n_field, watchdog); /* R = (e + x1) mod n */

          /* compare R and r' (MUST be equal) */
          if (actBNCompare (R, r, n_length, TRUE) != actCOMPARE_EQUAL)
          {
            retVal = actVERIFICATION_FAILED;
          }
        }
      }
    }
  }
  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTSM2_ENABLED == STD_ON) */
/***********************************************************************************************************************
 *  END OF FILE: actSM2.c
 **********************************************************************************************************************/
