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
/*!       \file  actEdDSA.c
 *        \brief Ed25519 and Ed448 core implementation.
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

#define ACTEDDSA_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "actUtilities.h"
#include "actExternRandom.h"
#include "actConfig.h"
#include "actWatchdog.h"
#include "actEd25519core.h"
#include "actEd448core.h"
#include "actEdDSA.h"

#if ((VSECPRIM_ACTED25519_ENABLED == STD_ON) || (VSECPRIM_ACTED448_ENABLED == STD_ON))
 /**********************************************************************************************************************
  *  LOCAL CONSTANT MACROS
  *********************************************************************************************************************/
# define actEDWARDS25519_DOM2_LENGTH                                  (32u)

 /**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

# define VSECPRIM_START_SEC_CONST_UNSPECIFIED
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if (VSECPRIM_ACTED25519_ENABLED == STD_ON)
VSECPRIM_ROM(VSECPRIM_LOCAL, actU8) actEd25519_dom2[] = { "SigEd25519 no Ed25519 collisions" }; /* PRQA S 3218 */ /* MD_VSECPRIM_8.7 */
# endif

# define VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  act25519_dom2()
 **********************************************************************************************************************/
/*! \brief      DOM2 Parser
 *  \details    This function handles and processes the DOM2 tag.
 *  \param[in,out]  ws  In: Pointer to the workspace. Out: Workspace with processed message information.
 *  \param[in]  watchdog  Pointer to watchdog function.
 *  \context    TASK
 *  \reentrant  TRUE
 *  \pre        -
 *********************************************************************************************************************/
# if (VSECPRIM_ACTED25519_ENABLED == STD_ON)
VSECPRIM_LOCAL_FUNC(void) act25519_dom2(
  VSECPRIM_P2VAR_PARA(actEdDSASTRUCT) ws,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));
# endif

/**********************************************************************************************************************
 *  actEdDSAImportMessage()
 **********************************************************************************************************************/
/*! \brief      Handles the provided message.
 *  \details    This function is used to cover different instance variants of the EdDSA for Ed25519 and Ed448.
 *              Actually only supports the pre-hash variant.
 *  \param[in,out]  ws        In: Pointer to the workspace.
 *                            Out: Workspace with processed message information.
 *  \param[in]      message   Pointer to the actual message.
 *  \param[in]      msgLen    Length of the provided message.
 *  \param[in]      watchdog  Pointer to watchdog function.
 *  \return     actOK                - Operation successful.
 *              actEXCEPTION_LENGTH  - Pre-hashing failure.
 *  \context    TASK
 *  \reentrant  TRUE
 *  \pre        ws must be a valid pointer.
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actEdDSAImportMessage(
  VSECPRIM_P2VAR_PARA(actEdDSASTRUCT) ws,
  VSECPRIM_P2CONST_PARA(actU8) message,
  const actLengthType msgLen,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

# if (VSECPRIM_ACTED25519_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  act25519_dom2()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_LOCAL_FUNC(void) act25519_dom2(
  VSECPRIM_P2VAR_PARA(actEdDSASTRUCT) ws,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  if (ws->instance != actEd25519PURE)
  {
    /* Process DOM2 tag */
    VSECPRIM_P2VAR_PARA(actSHA512STRUCT) sha512WsPtr = &(ws->shaWs.sha512);
    actU8 ph_len[2] = {0u, 0u};

    if (ws->instance == actEd25519PH)
    {
      ph_len[0] = 1u; /* SBSW_VSECPRIM_WRITE_ARRAY */
    }

    if (ws->context != NULL_PTR)
    {
      ph_len[1] = (actU8)(ws->ctxLen & 0xFFu); /* SBSW_VSECPRIM_WRITE_ARRAY */
    }

    (void)actSHA512Update(sha512WsPtr, actEd25519_dom2, actEDWARDS25519_DOM2_LENGTH, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
    (void)actSHA512Update(sha512WsPtr, ph_len, 2, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

    if ((ws->context != NULL_PTR) && (ws->ctxLen != 0u))
    {
      (void)actSHA512Update(sha512WsPtr, ws->context, ws->ctxLen, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
    }
  }
}

# endif /* (VSECPRIM_ACTED25519_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  actEdDSAImportMessage()
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
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actEdDSAImportMessage(
  VSECPRIM_P2VAR_PARA(actEdDSASTRUCT) ws,
  VSECPRIM_P2CONST_PARA(actU8) message,
  const actLengthType msgLen,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE retVal = actOK;

  switch (ws->curveId)
  {
# if (VSECPRIM_ACTED25519_ENABLED == STD_ON)
  case actEDWARDSCURVE25519:
    /* Check if context is ph instance */
    if (ws->instance == actEd25519PH)
    {
      /* Prehash provided message */
      if (actOK != (actSHA512Update(&(ws->shaWs.sha512), message, msgLen, watchdog))) /* SBSW_VSECPRIM_CALL_FUNCTION */
      {
        retVal = actEXCEPTION_LENGTH;
      }
      else
      {
        /* actSHA512Finalize always returns actOK */
        (void)actSHA512Finalize(&(ws->shaWs.sha512), ws->hashBuf.hashValue, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

        /* Store message information */
        ws->message = ws->hashBuf.hashValue; /* SBSW_VSECPRIM_WRITE_POINTER */
        ws->msgLen = actHASH_SIZE_SHA512; /* SBSW_VSECPRIM_WRITE_POINTER */
      }
    }
    else
    {
      /* Store plain message information */
      ws->message = message; /* SBSW_VSECPRIM_WRITE_POINTER */
      ws->msgLen = msgLen; /* SBSW_VSECPRIM_WRITE_POINTER */
    }
    break;
# endif /* (VSECPRIM_ACTED25519_ENABLED == STD_ON) */
# if (VSECPRIM_ACTED448_ENABLED == STD_ON)
  case actEDWARDSCURVE448:
    /* Check if context is ph instance */
    if (ws->instance == actEd448PH)
    {
      if( actOK != (actSHAKEUpdate(&(ws->shakeWs.shake), message, msgLen, watchdog))) /* SBSW_VSECPRIM_CALL_FUNCTION */
      {
        retVal = actEXCEPTION_LENGTH;
      }
      else
      {
        /* Ed448ph is the same as Ed448 but with PH being SHAKE256(x, 64)
         * actSHAKEGetXOFDigest always returns actOK, if the requested digest length is a multiple of 8. */
        (void)actSHAKEGetXOFDigest(&(ws->shakeWs.shake), ws->hashBuf.hashValue, actBytesToBits((actLengthType)actED448PH_DIGESTLENGTH), watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

        /* Store message information */
        ws->message = ws->hashBuf.hashValue; /* SBSW_VSECPRIM_WRITE_POINTER */
        /* SHAKE256(x, 64) returns a digest of length 64 */
        ws->msgLen = actED448PH_DIGESTLENGTH; /* SBSW_VSECPRIM_WRITE_POINTER */
      }
    }
    else
    {
      /* Store plain message information */
      ws->message = message; /* SBSW_VSECPRIM_WRITE_POINTER */
      ws->msgLen = msgLen; /* SBSW_VSECPRIM_WRITE_POINTER */
    }
    break;
# endif /* (VSECPRIM_ACTED448_ENABLED == STD_ON) */
    /* curve is neither Ed25519 nor Ed448 */
  default: /* COV_VSECPRIM_MISRA_ADDITIONAL_STATEMENT */
    /* empty default: validity of curve was checked before */
    break;
  }

   return retVal;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
# if (VSECPRIM_ACTED25519_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  act25519_hashPM()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) act25519_hashPM(
  VSECPRIM_P2VAR_PARA(actEdDSASTRUCT) ws,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  VSECPRIM_P2VAR_PARA(actSHA512STRUCT) sha512WsPtr = &(ws->shaWs.sha512);

  /* Init SHA-512 */
  (void)actSHA512Init(sha512WsPtr); /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* Process DOM2 tag */
  act25519_dom2(ws, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

  /* Hash the private key and message */
  (void)actSHA512Update(sha512WsPtr, &ws->privateKey[32], 32, watchdog); /* prefix */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  (void)actSHA512Update(sha512WsPtr, ws->message, ws->msgLen, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
  (void)actSHA512Finalize(sha512WsPtr, hash, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

  return actOK;
}

/**********************************************************************************************************************
 *  act25519_hashRAM()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) act25519_hashRAM(
  VSECPRIM_P2VAR_PARA(actEdDSASTRUCT) ws,
  VSECPRIM_P2CONST_PARA(actU8) R,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  VSECPRIM_P2VAR_PARA(actSHA512STRUCT) sha512WsPtr = &(ws->shaWs.sha512);
  /* Hash R, A and the Message */
  (void)actSHA512Init(sha512WsPtr); /* SBSW_VSECPRIM_CALL_FUNCTION */
  act25519_dom2(ws, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

  (void)actSHA512Update(sha512WsPtr, R, 32, watchdog); /* R */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  (void)actSHA512Update(sha512WsPtr, ws->pubKeyBuf.publicKey, 32, watchdog); /* A */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  (void)actSHA512Update(sha512WsPtr, ws->message, ws->msgLen, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
  (void)actSHA512Finalize(sha512WsPtr, hash, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

  return actOK;
}
# endif /* (VSECPRIM_ACTED25519_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  actEdDSAInit()
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
VSECPRIM_FUNC(actRETURNCODE) actEdDSAInit(
  VSECPRIM_P2VAR_PARA(actEdDSASTRUCT) ws,
  const actU8 instance,
  VSECPRIM_P2CONST_PARA(actU8) context,
  const actLengthType ctxLen,
  const actU16 curve) /* is actually a eslt_Size16-type */
{
  ws->instance = instance; /* SBSW_VSECPRIM_WRITE_POINTER */
  ws->curveId = curve; /* SBSW_VSECPRIM_WRITE_POINTER */
  /* differentiate between curves */
  switch (curve)
  {
# if (VSECPRIM_ACTED25519_ENABLED == STD_ON)
  case actEDWARDSCURVE25519:
    /* Initialize SHA-512 when instance is pre-hash */
    if (instance == actEd25519PH)
    {
      (void)actSHA512Init(&(ws->shaWs.sha512)); /* no need to check for error - returns actOK anyway */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    }
    /* Initialize EdwardsDSA core */
    actEd25519_initCore(ws); /* SBSW_VSECPRIM_CALL_FUNCTION */
    ws->context = context; /* SBSW_VSECPRIM_WRITE_POINTER */
    ws->ctxLen = ctxLen; /* SBSW_VSECPRIM_WRITE_POINTER */
    break;
# endif /* (VSECPRIM_ACTED25519_ENABLED == STD_ON) */
# if (VSECPRIM_ACTED448_ENABLED == STD_ON)
  case actEDWARDSCURVE448:
    /* Initialize SHAKE256, when instance is pre-hash */
    if (instance == actEd448PH)
    {
      /* no need to check for error - returns actOK anyway for provided strength of 256 */
      (void)actSHAKEInit(&(ws->shakeWs.shake), actED448_SHAKESTRENGTH);  /* SBSW_VSECPRIM_CALL_FUNCTION */
    }
    /* Initialize EdwardsDSA core */
    actEd448_initCore(ws); /* SBSW_VSECPRIM_CALL_FUNCTION */
    ws->context = context; /* SBSW_VSECPRIM_WRITE_POINTER */
    ws->ctxLen = ctxLen; /* SBSW_VSECPRIM_WRITE_POINTER */
    break;
# endif /* (VSECPRIM_ACTED448_ENABLED == STD_ON) */
  default: /* COV_VSECPRIM_MISRA_ADDITIONAL_STATEMENT */
    /* empty default: validity of curve was checked before */
    break;
  }
  return actOK;
}

/**********************************************************************************************************************
 *  actEdDSAUpdate()
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
VSECPRIM_FUNC(actRETURNCODE) actEdDSAUpdate(
  VSECPRIM_P2VAR_PARA(actEdDSASTRUCT) ws,
  VSECPRIM_P2CONST_PARA(actU8) message,
  const actLengthType msgLen,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /* Returning an error code in the default case is not necessary,
   * as the default case is not reachable from the esl-level. */
  actRETURNCODE retVal = actOK;

  /* differentiate between Ed25519 and Ed448 */
  switch (ws->curveId)
  {
# if (VSECPRIM_ACTED25519_ENABLED == STD_ON)
  case actEDWARDSCURVE25519:
    if (ws->instance != actEd25519PH)
    {
      retVal = actEXCEPTION_ALGOID;
    }
    else
    {
      /* Update SHA-512 */
      retVal = actSHA512Update(&(ws->shaWs.sha512), message, msgLen, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
    }
    break;
# endif /* (VSECPRIM_ACTED25519_ENABLED == STD_ON) */
# if (VSECPRIM_ACTED448_ENABLED == STD_ON)
  case actEDWARDSCURVE448:
    if (ws->instance != actEd448PH)
    {
      retVal = actEXCEPTION_ALGOID;
    }
    else
    {
      /* Update SHAKE256 */
      retVal = actSHAKEUpdate(&(ws->shakeWs.shake), message, msgLen, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
    }
    break;
# endif /* (VSECPRIM_ACTED448_ENABLED == STD_ON) */
  default: /* COV_VSECPRIM_MISRA_ADDITIONAL_STATEMENT */
    /* empty default: validity of curve was checked before */
    break;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  actEdDSASign()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actEdDSASign(
  VSECPRIM_P2VAR_PARA(actEdDSASTRUCT) ws,
  VSECPRIM_P2CONST_PARA(actU8) message,
  const actLengthType msgLen,
  VSECPRIM_P2CONST_PARA(actU8) secretKey,
  VSECPRIM_P2CONST_PARA(actU8) publicKey,
  VSECPRIM_P2VAR_PARA(actU8) signature,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /* Handle instance variants */
  /* import message for curve Ed25519 or Ed448 respectively */
  actRETURNCODE retVal = actEdDSAImportMessage(ws, message, msgLen, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

  if (retVal == actOK)
  {
    switch (ws->curveId)
    {
# if (VSECPRIM_ACTED25519_ENABLED == STD_ON)
    case actEDWARDSCURVE25519:
      /* Import key pairs from actEd25519core */
      retVal = actEd25519_importKeyPair(ws, secretKey, publicKey, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

      if (retVal == actOK)
      {
        /* Sign provided message */
        retVal = actEd25519_sign(ws, signature, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
      }
      break;
# endif /* (VSECPRIM_ACTED25519_ENABLED == STD_ON) */
# if (VSECPRIM_ACTED448_ENABLED == STD_ON)
    case actEDWARDSCURVE448:
      /* Import key pairs from actEd448core */
      retVal = actEd448_importKeyPair(ws, secretKey, publicKey, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

      if (retVal == actOK)
      {
        /* Sign provided message */
        retVal = actEd448_sign(ws, signature, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
      }
      break;
# endif /* (VSECPRIM_ACTED448_ENABLED == STD_ON) */
    default: /* COV_VSECPRIM_MISRA_ADDITIONAL_STATEMENT */
      /* empty default: validity of curve was checked before */
      break;
    }

    /* Clear local memory */
    actMemset(ws->privateKey, 0u, sizeof(ws->privateKey)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    actMemset(ws->pubKeyBuf.publicKey, 0u, sizeof(ws->pubKeyBuf.publicKey)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */

    actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */  /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  actEdDSAVerify()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actEdDSAVerify(
  VSECPRIM_P2VAR_PARA(actEdDSASTRUCT) ws,
  VSECPRIM_P2CONST_PARA(actU8) message,
  const actLengthType msgLen,
  VSECPRIM_P2CONST_PARA(actU8) publicKey,
  VSECPRIM_P2CONST_PARA(actU8) signature,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /* import message for both Ed25519 and Ed448 respectively */
  /* Handle instance variants */
  actRETURNCODE retVal = actEdDSAImportMessage(ws, message, msgLen, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

  if (retVal == actOK)
  {
    switch (ws->curveId)
    {
# if (VSECPRIM_ACTED25519_ENABLED == STD_ON)
    case actEDWARDSCURVE25519:
      /* Import the key pair */
      retVal = actEd25519_importKeyPair(ws, NULL_PTR, publicKey, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

      if (retVal == actOK)
      {
        /* Verify provided signature over given message */
        retVal = actEd25519_verify(ws, signature, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
      }
      break;
# endif /* (VSECPRIM_ACTED25519_ENABLED == STD_ON) */
# if (VSECPRIM_ACTED448_ENABLED == STD_ON)
    case actEDWARDSCURVE448:
      /* Import the key pair */
      retVal = actEd448_importKeyPair(ws, NULL_PTR, publicKey, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

      if (retVal == actOK)
      {
        /* Verify provided signature over given message */
        retVal = actEd448_verify(ws, signature, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
      }
      break;
# endif /* (VSECPRIM_ACTED448_ENABLED == STD_ON) */
    default: /* COV_VSECPRIM_MISRA_ADDITIONAL_STATEMENT */
      /* empty default: validity of curve was checked before */
      break;
    }

    /* Clear local memory */
    actMemset(ws->pubKeyBuf.publicKey, 0u, sizeof(ws->pubKeyBuf.publicKey)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    /*  ws->privateKey: no need to clear - holds the signature (re-) calculated */
    actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */  /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
  }

  return retVal;
}

# if (VSECPRIM_ACTED25519_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  actEd25519GenKeyPair()
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
VSECPRIM_FUNC(actRETURNCODE) actEd25519GenKeyPair(
  VSECPRIM_P2VAR_PARA(actEdDSASTRUCT) ws,
  VSECPRIM_P2VAR_PARA(actU8) secretKey,
  VSECPRIM_P2VAR_PARA(actU8) publicKey,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /* Generate secretKey randomly */
  actRETURNCODE retVal = actGetExternRandom(secretKey, actEd25519_KEY_SIZE); /* SBSW_VSECPRIM_CALL_FUNCTION */

  if (retVal != actOK)
  {
    /* Failed to get random bytes */
    actMemset(secretKey, 0u, actEd25519_KEY_SIZE); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    retVal = actEXCEPTION_PRIVKEY;
  }
  else
  {
    /* Generate key pair from random private key */
    retVal = actEd25519_importKeyPair(ws, secretKey, NULL_PTR, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

    if (retVal == actOK)
    {
      /* Copy public key from workspace to user buffer */
      actMemCpyByteArray(publicKey, ws->pubKeyBuf.publicKey, actEd25519_KEY_SIZE); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    }

    /* Clear workspace */
    actMemset(ws->privateKey, 0u, sizeof(ws->privateKey)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    actMemset(ws->pubKeyBuf.publicKey, 0u, sizeof(ws->pubKeyBuf.publicKey)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */

    actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */  /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
  }

  return retVal;
}
# endif /* (VSECPRIM_ACTED25519_ENABLED == STD_ON) */

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* ((VSECPRIM_ACTED25519_ENABLED == STD_ON) || (VSECPRIM_ACTED448_ENABLED == STD_ON)) */

/**********************************************************************************************************************
 *  END OF FILE: actEdDSA.c
 *********************************************************************************************************************/
