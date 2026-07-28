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
/*!        \file  actEd448core.c
 *        \brief  Core Ed448 implementation.
 *
 *      \details This file is part of the embedded systems library cvActLib
 *               Reference: https:/ /tools.ietf.org/html/draft-irtf-cfrg-eddsa-08
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

#define ACTED448CORE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "actEd448core.h"
#include "actWatchdog.h"
#include "actUtilities.h"
#include "actISHAKE.h"
#include "act448util.h"

#if (VSECPRIM_ACTED448CORE_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CONST_UNSPECIFIED
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
# define actEDWARDS448_DOM4_LENGTH                                    (8u)

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
VSECPRIM_ROM(VSECPRIM_LOCAL, actU8) actEd448_dom4[] = { "SigEd448" }; /* PRQA S 3218 */ /* MD_VSECPRIM_8.7 */

# define VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  act448_hashPM()
 *********************************************************************************************************************/
/*! \brief       Hash the prefix and message
 *  \details     This function performs step 2 of the Ed448 signature algorithm.
 *               www.rfc-editor.org/rfc/rfc8032
 *  \param[in,out]  ws  Pointer to the work-space structure.
 *  \param[out]  hash  Pointer to the output buffer for the hash value
 *  \param[in]   watchdog  Pointer to watchdog trigger function.
 *  \return      actOK  -  actOK is always returned.
 *  \pre         The buffer referenced by hash must provide at least 114 bytes
 *               ws, hash must be valid pointers
 *               ws must be initialized
 *  \context     TASK
 *  \reentrant   TRUE, for different workspaces
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(actRETURNCODE) act448_hashPM(
  VSECPRIM_P2VAR_PARA(actEdDSASTRUCT) ws,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  act448_hashRAM()
 *********************************************************************************************************************/
/*! \brief       Hash R, A and the message
 *  \details     This function performs step 4 of the Ed448 signature algorithm
 *               www.rfc-editor.org/rfc/rfc8032 (section 5.2.6)
 *               or step 2 of the Ed448 verification algorithm
 *               www.rfc-editor.org/rfc/rfc8032 section 5.2.7)
 *  \param[in,out]  ws  Pointer to the work-space structure.
 *  \param[in]   R  Pointer to the R value.
 *  \param[out]  hash  Pointer to the output buffer for the hash value.
 *  \param[in]   watchdog  Pointer to watchdog trigger function.
 *  \return      actOK  -  actOK is always returned.
 *  \pre         The buffer referenced by hash must provide at least 114 bytes
 *               ws, hash must be valid pointers
 *               ws must be initialized
 *  \context     TASK
 *  \reentrant   TRUE, for different workspaces
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(actRETURNCODE) act448_hashRAM(
  VSECPRIM_P2VAR_PARA(actEdDSASTRUCT) ws,
  VSECPRIM_P2CONST_PARA(actU8) R,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actEd448_initCore()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(void) actEd448_initCore(VSECPRIM_P2VAR_PARA(actEdDSASTRUCT) ws) /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
{
  /* Init core */
  act448_initCore((VSECPRIM_P2VAR_PARA(actEdwardsCurveWs))&ws->coreWS); /* SBSW_VSECPRIM_CALL_FUNCTION */
}

/**********************************************************************************************************************
 *  actEd448_sign()
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
VSECPRIM_FUNC(actRETURNCODE) actEd448_sign(
  VSECPRIM_P2VAR_PARA(actEdDSASTRUCT) ws,
  VSECPRIM_P2VAR_PARA(actU8) signature,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE actRetVal = actOK;

  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) coreWSptr = &ws->coreWS;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a = coreWSptr->auxVar.tempA;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) k = coreWSptr->auxVar.tempB;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) s = coreWSptr->auxVar.tempC;
  VSECPRIM_P2VAR_PARA(actHomogeneousPointEd448) rB = &(ws->shakeWs.point_rB);
  VSECPRIM_P2VAR_PARA(actU8) hash = ((VSECPRIM_P2VAR_PARA(actU8))(coreWSptr->auxVar.tempA)); /* need  114 bytes - temA || tempB   is  116 bytes */

  actBNDIGIT r[BNDIGITS_456];

  /* First part of signature R: */
  /* 1. + 2. Hash the prefix and the message to derive r */
  (void)act448_hashPM(ws, hash, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* interpret hash in little endian representation */
  act448_BNLoadLE(coreWSptr->auxVar.temp1, hash, actEDWARDS_MAX_HASH_DIGEST_SIZE); /* SBSW_VSECPRIM_CALL_FUNCTION */
  act448_reduceQ(coreWSptr, r, coreWSptr->auxVar.temp1); /* r = hash mod Q */ /* SBSW_VSECPRIM_CALL_FUNCTION */

  /* 3. Encode rB into the first half of the signature buffer as R */
  act448_mulBasePoint(coreWSptr, rB, r, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actRetVal = act448_encodePoint(coreWSptr, signature, rB, watchdog);  /* R */ /* SBSW_VSECPRIM_CALL_FUNCTION */

  if (actRetVal == actOK)
  {
    /* Second part of signature S: */
    /* 4. Hash R, A, and the message to get k */
    (void)act448_hashRAM(ws, signature, ws->hashBuf.hashValue, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
    /* Interpret hash in little endian representation in temp1: */
    act448_BNLoadLE(coreWSptr->auxVar.temp1, ws->hashBuf.hashValue, actED448_SHAKE_DIGEST_LENGTH); /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_reduceQ(coreWSptr, k, coreWSptr->auxVar.temp1); /* k = hash mod Q */ /* SBSW_VSECPRIM_CALL_FUNCTION */

    /* Compute s = (r + k * a) mod q */
    act448_BNLoadLE(a, ws->privateKey, actEd448_KEY_SIZE); /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_mulModQ(coreWSptr, s, k, a); /* s =     (k * a) mod q */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_addModQ(coreWSptr, s, r, s); /* s = (r + k * a) mod q */ /* SBSW_VSECPRIM_CALL_FUNCTION */

    act448_BNStoreLE(&signature[actEd448_SIGNATURE_SIZE / 2u], s); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }

  actL2trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */

  /* Clean up */
  actBNSetZero(coreWSptr->auxVar.tempA, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(coreWSptr->auxVar.tempB, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(coreWSptr->auxVar.tempC, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(coreWSptr->auxVar.temp1, BNDIGITS_912_MULTIPLICATION); /* SBSW_VSECPRIM_CALL_FUNCTION */

  return actRetVal;
}

/**********************************************************************************************************************
 *  actEd448_verify()
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
VSECPRIM_FUNC(actRETURNCODE) actEd448_verify(
  VSECPRIM_P2VAR_PARA(actEdDSASTRUCT) ws,
  VSECPRIM_P2CONST_PARA(actU8) signature,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) coreWSptr = &ws->coreWS;
  /* Even if sB/A abnd s/k are taken from union, they are not used concurrently!
   * For better readability and comparability to algorithm specification, additional variables pointing to same address are used. */
  VSECPRIM_P2VAR_PARA(actHomogeneousPointEd448) A = &(ws->shakeWs.point_A);
  VSECPRIM_P2VAR_PARA(actHomogeneousPointEd448) sB = &(ws->shakeWs.point_sB);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) s = ws->hashBuf.bnDigit_s;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) k = ws->hashBuf.bnDigit_k;
  actHomogeneousPointEd448 R;
  actRETURNCODE result = actVERIFICATION_FAILED;

  /* Reconstruct the k value from the signing step */
  (void)act448_hashRAM(ws, signature, ws->hashBuf.hashValue, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

  /* Decode the public key */
  result = act448_decodePoint(coreWSptr, A, ws->pubKeyBuf.publicKey, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

  /* Decode the R component of the signature */
  result |= act448_decodePoint(coreWSptr, &R, signature, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

  if (result == actOK)
  {
    /* Calculate R + k * A */
    act448_BNLoadLE(coreWSptr->auxVar.temp1, ws->hashBuf.hashValue, actED448_SHAKE_DIGEST_LENGTH); /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_reduceQ(coreWSptr, k, coreWSptr->auxVar.temp1); /* k = hash mod Q */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_mulAddPoint(coreWSptr, &R, A, k, watchdog); /* R = R + k * A */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    /* Calculate s * B */
    act448_BNLoadLE(s, &signature[actEd448_SIGNATURE_SIZE / 2u], actEd448_SIGNATURE_SIZE / 2u); /* SBSW_VSECPRIM_CALL_FUNCTION */
    /* Check if s < group order */
    if (actBNCompare(s, coreWSptr->order, BNDIGITS_456, FALSE) == actCOMPARE_SMALLER) /* SBSW_VSECPRIM_CALL_FUNCTION */
    {
      act448_mulBasePoint(coreWSptr, sB, s, watchdog); /* sB = s * B */ /* SBSW_VSECPRIM_CALL_FUNCTION */
      /* Compare s * B and R + k * A for equality */
      if (act448_comparePoints(coreWSptr, sB, &R, watchdog) == actOK) /* SBSW_VSECPRIM_CALL_FUNCTION */
      {
        result = actOK;
      }
      else
      {
        result = actVERIFICATION_FAILED;
      }
    }
    else
    {
      result = actVERIFICATION_FAILED;
    }
  }

  /* clean up and exit */
  actL3trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
  actBNSetZero(coreWSptr->auxVar.tempA, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(coreWSptr->auxVar.tempB, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(coreWSptr->auxVar.tempC, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(coreWSptr->auxVar.tempD, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */
  actBNSetZero(coreWSptr->auxVar.temp1, BNDIGITS_912_MULTIPLICATION); /* SBSW_VSECPRIM_CALL_FUNCTION */

  return result;
}

/**********************************************************************************************************************
 *  actEd448_importKeyPair()
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
VSECPRIM_FUNC(actRETURNCODE) actEd448_importKeyPair(
  VSECPRIM_P2VAR_PARA(actEdDSASTRUCT) ws,
  VSECPRIM_P2CONST_PARA(actU8) secretKey,
  VSECPRIM_P2CONST_PARA(actU8) publicKey,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  VSECPRIM_P2VAR_PARA(actEdwardsCurveWs) coreWSptr = &ws->coreWS;
  VSECPRIM_P2VAR_PARA(actHomogeneousPointEd448) A = &(ws->shakeWs.point_A);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a = (ws->pubKeyBuf.bnDigit_a);
  actRETURNCODE actRetVal = actOK;

  if (NULL_PTR != secretKey)
  {
    /* Hash the secret key to get the private scalar 'a' and the message prefix.
     * Hash the 57-byte private key using SHAKE256(x, 114), storing the
     *  digest in a 114-octet large buffer.  Only the lower 57
     *  bytes are used for generating the public key. */
    (void)actSHAKEInit(&(ws->shakeWs.shake), actED448_SHAKESTRENGTH); /* SBSW_VSECPRIM_CALL_FUNCTION */
    (void)actSHAKEUpdate(&(ws->shakeWs.shake), secretKey, actEd448_KEY_SIZE, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
    (void)actSHAKEGetXOFDigest(&(ws->shakeWs.shake), ws->privateKey, actBytesToBits((actLengthType)actED448_SHAKE_DIGEST_LENGTH), watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

    /* Prune the buffer: The two least significant bits of the first
     *  octet are cleared, all eight bits the last octet are cleared, and
     *  the highest bit of the second to last octet is set.
     */
    ws->privateKey[0] &= 0xFCu; /* FC = 1111 1100 */ /* SBSW_VSECPRIM_WRITE_ARRAY */
    ws->privateKey[55] |= 0x80u; /* 80 = 1000 0000 */ /* SBSW_VSECPRIM_WRITE_ARRAY */
    ws->privateKey[56] = 0x0u; /* SBSW_VSECPRIM_WRITE_ARRAY */
  }

  if (NULL_PTR != publicKey)
  {
    /* Copy public key */
    actMemCpyByteArray(ws->pubKeyBuf.publicKey, publicKey, actEd448_KEY_SIZE); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  }
  else
  {
    /*  Calculate public key from private key
     *  to conserve (re-use) memory:
     *  - A is overlayed onto the SHAKE work-space
     *  - a is overlayed onto the public key
     */

    /* Compute  (a * BP) and encode the point (-> public key) */
    act448_BNLoadLE(a, ws->privateKey, actEd448_KEY_SIZE); /* SBSW_VSECPRIM_CALL_FUNCTION */
    act448_mulBasePoint(coreWSptr, A, a, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
    actRetVal = act448_encodePoint(coreWSptr, ws->pubKeyBuf.publicKey, A, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

    /* Clean up workspace */
    actBNSetZero(coreWSptr->auxVar.tempA, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */
    actBNSetZero(coreWSptr->auxVar.tempB, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */
    actBNSetZero(coreWSptr->auxVar.tempC, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */
    actBNSetZero(coreWSptr->auxVar.tempD, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }

  return actRetVal;
}

/**********************************************************************************************************************
 *  act448_dom4()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_LOCAL_FUNC(void) act448_dom4(
  VSECPRIM_P2VAR_PARA(actEdDSASTRUCT) ws,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{

  actU8 dom4StringMiddlePart[actEDWARDS448_DOM4MIDDLEPART_LENGTH] = { actEDWARDS448PURE_PHFLAG, actEDWARDS448_DEFAULTCONTEXTLEN };
  if (ws->instance == actEd448PH)
  {
    dom4StringMiddlePart[actEDWARDS448_DOM4MIDDLEPART_PHFLAGIDX] = actEDWARDS448PH_PHFLAG; /* SBSW_VSECPRIM_WRITE_ARRAY */
  }
  if (ws->ctxLen != 0u)
  {
    dom4StringMiddlePart[actEDWARDS448_DOM4MIDDLEPART_CTXLENGTHIDX] = (actU8)(ws->ctxLen & 0xFFu); /* SBSW_VSECPRIM_WRITE_ARRAY */
  }

  (void)actSHAKEUpdate(&(ws->shakeWs.shake), actEd448_dom4, actEDWARDS448_DOM4_LENGTH, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
  (void)actSHAKEUpdate(&(ws->shakeWs.shake), dom4StringMiddlePart, actEDWARDS448_DOM4MIDDLEPART_LENGTH, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

  if ((ws->context != NULL_PTR) && (ws->ctxLen != 0u))
  {
    (void)actSHAKEUpdate(&(ws->shakeWs.shake), ws->context, ws->ctxLen, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }

}

/**********************************************************************************************************************
 *  act448_hashPM()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_LOCAL_FUNC(actRETURNCODE) act448_hashPM(
  VSECPRIM_P2VAR_PARA(actEdDSASTRUCT) ws,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /* Init SHAKE256 */
  (void)actSHAKEInit(&(ws->shakeWs.shake), actED448_SHAKESTRENGTH); /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* Process DOM4 tag */
  act448_dom4(ws, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

  /* Hash the prefix and message */
  /* Let prefix denote the second half of the hash digest, h[57],...,h[113].*/
  (void)actSHAKEUpdate(&(ws->shakeWs.shake), &ws->privateKey[actEd448_SIGNATURE_SIZE / 2u], actEd448_SIGNATURE_SIZE / 2u, watchdog); /* prefix */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  (void)actSHAKEUpdate(&(ws->shakeWs.shake), ws->message, ws->msgLen, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
  (void)actSHAKEGetXOFDigest(&(ws->shakeWs.shake), hash, actBytesToBits((actLengthType)(actED448_SHAKE_DIGEST_LENGTH)), watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

  return actOK;
}

/**********************************************************************************************************************
 *  act448_hashRAM()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_LOCAL_FUNC(actRETURNCODE) act448_hashRAM(
  VSECPRIM_P2VAR_PARA(actEdDSASTRUCT) ws,
  VSECPRIM_P2CONST_PARA(actU8) R,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /* Hash R, A and the Message */
  (void)actSHAKEInit(&(ws->shakeWs.shake), actED448_SHAKESTRENGTH); /* SBSW_VSECPRIM_CALL_FUNCTION */
  act448_dom4(ws, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

  (void)actSHAKEUpdate(&(ws->shakeWs.shake), R, actEd448_KEY_SIZE, watchdog); /* R */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  (void)actSHAKEUpdate(&(ws->shakeWs.shake), ws->pubKeyBuf.publicKey, actEd448_KEY_SIZE, watchdog); /* A */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  (void)actSHAKEUpdate(&(ws->shakeWs.shake), ws->message, ws->msgLen, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
  (void)actSHAKEGetXOFDigest(&(ws->shakeWs.shake), hash, actBytesToBits((actLengthType)actED448_SHAKE_DIGEST_LENGTH), watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

  return actOK;
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTED448CORE_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  END OF FILE: actEd448core.c
 *********************************************************************************************************************/
