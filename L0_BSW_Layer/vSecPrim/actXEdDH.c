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
/*!        \file  actXEdDH.c
 *        \brief  Core X25519 and X448 implementation.
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

#define ACTXEDDH_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "actUtilities.h"
#include "actExternRandom.h"
#include "actConfig.h"
#include "actWatchdog.h"
#include "actIXEdDH.h"
#include "actX25519core.h"
#include "actX448core.h"

#if ((VSECPRIM_ACTX25519_ENABLED == STD_ON) || (VSECPRIM_ACTX448_ENABLED == STD_ON))

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

# define x25519_initCore(ws)                                          actX25519_initCore (ws)
# define x448_initCore(ws)                                            actX448_initCore (ws)
# define x25519_exchangeKeys(ws, wd)                                  actX25519_eval ((ws), (wd))
# define x448_exchangeKeys(ws, wd)                                    actX448_eval ((ws), (wd))

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  actEdDHInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actEdDHInit(VSECPRIM_P2VAR_PARA(actEdDHSTRUCT) ws)
{
  /* Call init function */
  switch (ws->curveId)
  {
# if (VSECPRIM_ACTX25519_ENABLED == STD_ON)
    case actEDWARDSCURVE25519:
      x25519_initCore(ws); /* SBSW_VSECPRIM_CALL_FUNCTION */
      break;
# endif /* (VSECPRIM_ACTX25519_ENABLED == STD_ON) */
# if (VSECPRIM_ACTX448_ENABLED == STD_ON)
    case actEDWARDSCURVE448:
      x448_initCore(ws); /* SBSW_VSECPRIM_CALL_FUNCTION */
      break;
# endif /* (VSECPRIM_ACTX448_ENABLED == STD_ON) */
    default: /* COV_VSECPRIM_MISRA_ADDITIONAL_STATEMENT */
      /* empty default: validity of curve was checked before */
      break;
  }

  return actOK;
}

/**********************************************************************************************************************
 *  actEdDHGenKeyPair()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actEdDHGenKeyPair(
  VSECPRIM_P2VAR_PARA(actEdDHSTRUCT) ws,
  VSECPRIM_P2VAR_PARA(actU8) publicKey,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE retVal = actEXCEPTION_UNKNOWN;
  actLengthType keySize = 0;
  actU8 uCoordinateBasePoint = 0u;

  switch (ws->curveId)
  {
# if (VSECPRIM_ACTX25519_ENABLED == STD_ON)
  case actEDWARDSCURVE25519:
  {
    keySize = actX25519_KEY_SIZE;
    uCoordinateBasePoint = 9u; /* base point = 9 for curve25519 */
    break;
  }
# endif /* (VSECPRIM_ACTX25519_ENABLED == STD_ON) */
# if (VSECPRIM_ACTX448_ENABLED == STD_ON)
  case actEDWARDSCURVE448:
  {
    keySize = actX448_KEY_SIZE;
    uCoordinateBasePoint = 5u; /* base point = 5 for curve448 */
    break;
  }
# endif /* (VSECPRIM_ACTX448_ENABLED == STD_ON) */
  default:
    /* empty default: validity of curve was checked before, retVal has already been set */
    break;
  }

  retVal = actGetExternRandom(ws->privateKey, keySize); /* SBSW_VSECPRIM_CALL_FUNCTION */

  /* Generate random ephemeral private key */
  if (retVal != actOK)
  {
    /* Clear memory */
    actMemset(ws->privateKey, 0u, keySize); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    retVal = actEXCEPTION_PRIVKEY;
  }
  else
  {
    switch (ws->curveId)
    {
# if (VSECPRIM_ACTX25519_ENABLED == STD_ON)
    case actEDWARDSCURVE25519:
    {
      ws->privateKey[0] &= 0xF8u; /* SBSW_VSECPRIM_WRITE_ARRAY */
      ws->privateKey[31] &= 0x7Fu; /* SBSW_VSECPRIM_WRITE_ARRAY */
      ws->privateKey[31] |= 0x40u; /* SBSW_VSECPRIM_WRITE_ARRAY */
      break;
    }
# endif /* (VSECPRIM_ACTX25519_ENABLED == STD_ON) */
# if (VSECPRIM_ACTX448_ENABLED == STD_ON)
    case actEDWARDSCURVE448:
    {
      ws->privateKey[0] &= 0xFCu; /* SBSW_VSECPRIM_WRITE_ARRAY */
      ws->privateKey[55] |= 0x80u; /* SBSW_VSECPRIM_WRITE_ARRAY */
      break;
    }
# endif /* (VSECPRIM_ACTX448_ENABLED == STD_ON) */
    default:
      /* value has already been set */
      break;
    }

    /* Evaluate curve equation using base point and ephemeral private key
     * Thus, set up the base point first.
     *
     * The base point will be stored in ws->basePointBuf.uCoord. This union has a second member, bnDigit_x_1.
     * For curve448, bnDigit_x_1 is a longer array than uCoord, and needs to be initialized with all zeros, too.
     * In particular, its most significant digits must be cleared.
     * Hence, we initialize bnDigit_x_1, thereby implicitly also initializing uCoord.
     * Then we only update the first byte of uCoord, so that uCoord correctly stores the u-coordinate
     * of the base point of the curve. */
    actBNSetZero(ws->basePointBuf.bnDigit_x_1, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */
    ws->basePointBuf.uCoord[0] = uCoordinateBasePoint; /* SBSW_VSECPRIM_WRITE_ARRAY */

    switch (ws->curveId)
    {
# if (VSECPRIM_ACTX25519_ENABLED == STD_ON)
    case actEDWARDSCURVE25519:
      retVal = x25519_exchangeKeys(ws, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
      break;
# endif /* (VSECPRIM_ACTX25519_ENABLED == STD_ON) */
# if (VSECPRIM_ACTX448_ENABLED == STD_ON)
    case actEDWARDSCURVE448:
      retVal = x448_exchangeKeys(ws, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
      break;
# endif /* (VSECPRIM_ACTX448_ENABLED == STD_ON) */
    default:
      /* empty default: validity of curve was checked before */
      break;
    }

    if (retVal == actOK)
    {
      actMemCpyByteArray(publicKey, ws->basePointBuf.uCoord, keySize); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  actEdDHImportPrivateKey()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(void) actEdDHImportPrivateKey(
  VSECPRIM_P2VAR_PARA(actEdDHSTRUCT) ws,
  VSECPRIM_P2CONST_PARA(actU8) privateKey,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)) /* PRQA S 3206 */ /* MD_VSECPRIM_WATCHDOG */
{
  actLengthType keySize = 0;

  switch (ws->curveId)
  {
# if (VSECPRIM_ACTX25519_ENABLED == STD_ON)
  case actEDWARDSCURVE25519:
  {
    keySize = actX25519_KEY_SIZE;
    break;
  }
# endif /* (VSECPRIM_ACTX25519_ENABLED == STD_ON) */
# if (VSECPRIM_ACTX448_ENABLED == STD_ON)
  case actEDWARDSCURVE448:
  {
    keySize = actX448_KEY_SIZE;
    break;
  }
# endif /* (VSECPRIM_ACTX448_ENABLED == STD_ON) */
  default: /* COV_VSECPRIM_MISRA_ADDITIONAL_STATEMENT */
    /* empty default: validity of curve was checked before and returnvalue has been set already */
    break;
  }

  /* Import privateKey */
  actMemCpyByteArray(ws->privateKey, privateKey, keySize); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */

  switch (ws->curveId)
  {
# if (VSECPRIM_ACTX25519_ENABLED == STD_ON)
  case actEDWARDSCURVE25519:
  {
    ws->privateKey[0] &= 0xF8u; /* SBSW_VSECPRIM_WRITE_ARRAY */
    ws->privateKey[31] &= 0x7Fu; /* SBSW_VSECPRIM_WRITE_ARRAY */
    ws->privateKey[31] |= 0x40u; /* SBSW_VSECPRIM_WRITE_ARRAY */
    break;
  }
# endif /* (VSECPRIM_ACTX25519_ENABLED == STD_ON) */
# if (VSECPRIM_ACTX448_ENABLED == STD_ON)
  case actEDWARDSCURVE448:
  {
    ws->privateKey[0] &= 0xFCu; /* SBSW_VSECPRIM_WRITE_ARRAY */
    ws->privateKey[55] |= 0x80u; /* SBSW_VSECPRIM_WRITE_ARRAY */
    break;
  }
# endif /* (VSECPRIM_ACTX448_ENABLED == STD_ON) */
  default: /* COV_VSECPRIM_MISRA_ADDITIONAL_STATEMENT */
    /* empty default: validity of curve was checked before, value has already been set */
    break;
  }
  actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
}

/**********************************************************************************************************************
 *  actEdDHGenSecret()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actEdDHGenSecret(
  VSECPRIM_P2VAR_PARA(actEdDHSTRUCT) ws,
  VSECPRIM_P2CONST_PARA(actU8) publicKey,
  VSECPRIM_P2VAR_PARA(actU8) sharedSecret,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE retVal = actOK;
  actLengthType keySize = 0;

  switch (ws->curveId)
  {
# if (VSECPRIM_ACTX25519_ENABLED == STD_ON)
  case actEDWARDSCURVE25519:
    keySize = actX25519_KEY_SIZE;
    break;
# endif /* (VSECPRIM_ACTX25519_ENABLED == STD_ON) */
# if (VSECPRIM_ACTX448_ENABLED == STD_ON)
  case actEDWARDSCURVE448:
    keySize = actX448_KEY_SIZE;
    break;
# endif /* (VSECPRIM_ACTX448_ENABLED == STD_ON) */
  default: /* COV_VSECPRIM_MISRA_ADDITIONAL_STATEMENT */
    /* empty default: validity of curve was checked before, value has already been set */
    break;
  }

  /* Initialize second union member bnDigit_x_1 with zero, as this cannot be done, once
   * union member uCoord is written.
   * (bnDigit_x_1 is up to 3 bytes longer than uCoord - these bytes would otherwise not get initialized.) */
  actBNSetZero(ws->basePointBuf.bnDigit_x_1, actEDWARDS_MAX_BNDIGITS); /* SBSW_VSECPRIM_CALL_FUNCTION */
  /* Generate shared secret */
  actMemCpyByteArray(ws->basePointBuf.uCoord, publicKey, keySize); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */

  switch (ws->curveId)
  {
# if (VSECPRIM_ACTX25519_ENABLED == STD_ON)
    case actEDWARDSCURVE25519:
      retVal = x25519_exchangeKeys(ws, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
      break;
# endif /* (VSECPRIM_ACTX25519_ENABLED == STD_ON) */
# if (VSECPRIM_ACTX448_ENABLED == STD_ON)
    case actEDWARDSCURVE448:
      retVal = x448_exchangeKeys(ws, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
      break;
# endif /* (VSECPRIM_ACTX448_ENABLED == STD_ON) */
    default: /* COV_VSECPRIM_MISRA_ADDITIONAL_STATEMENT */
      /* empty default: validity of curve was checked before */
      break;
  }
  if (retVal == actOK)
  {
    actMemCpyByteArray(sharedSecret, ws->basePointBuf.uCoord, keySize); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* ((VSECPRIM_ACTX25519_ENABLED == STD_ON) || (VSECPRIM_ACTX448_ENABLED == STD_ON)) */

/**********************************************************************************************************************
 *  END OF FILE: actXEdDH.c
 *********************************************************************************************************************/
