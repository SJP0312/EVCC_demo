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
/*!        \file  actEdCheckKey.c
 *        \brief  Implementation file for actEdCheckKey.h
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

#define ACTEDCHECKKEY_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "actEdCheckKey.h"
#include "actUtilities.h"
#include "act448util.h"
#include "act25519util.h"

#if (VSECPRIM_ACTEDCHECKKEY_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# if (VSECPRIM_ECDSA_25519_ENABLED == STD_ON)
/**********************************************************************************************************************
  actEd25519CheckPublicKey()
 **********************************************************************************************************************/
/*! \brief       Checks if the public key for Ed25519 is valid by checking its range and if it is on the curve.
 *  \details     This function takes the public key and decodes it. During the decoding a range check is done.
 *               While the y-coordinate is recovered directly from the given key, the x-coordinate is recovered from
 *               the curve equation: x^2 = (y^2 - 1) / (d y^2 - 1) (mod p). If it is not possible to recover the
 *               x-coordinate, the given public key is not on the curve and therefore invalid.
 *  \param[in,out]  workspace          pointer to workspace
 *  \param[in]      publicKey          pointer to public key
 *  \param[in]      watchdog           pointer to watchdog trigger function
 *  \return         actEXCEPTION_UNKNOWN       Error during decoding - the public key is invalid
 *                  actOK                      else
 *  \pre            pointers must be valid
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actEd25519CheckPublicKey(
  VSECPRIM_P2VAR_PARA(actEdwardsKeyCheck) workspace,
  VSECPRIM_P2CONST_PARA(actU8) publicKey,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));
# endif

# if (VSECPRIM_EDDSA_448_ENABLED == STD_ON)
/**********************************************************************************************************************
  actEd448CheckPublicKey()
 **********************************************************************************************************************/
/*! \brief       Checks if the public key for Ed448 is valid  by checking its range and if it is on the curve.
 *  \details     This function takes the public key and decodes it. During the decoding a range check is done.
 *               While the y-coordinate is recovered directly from the given key, the x-coordinate is recovered from
 *               the curve equation: x^2 = (y^2 - 1) / (d y^2 + 1) (mod p). If it is not possible to recover the
 *               x-coordinate, the given public key is not on the curve and therefore invalid.
 *  \param[in,out]  workspace          pointer to workspace
 *  \param[in]      publicKey          pointer to public key
 *  \param[in]      watchdog           pointer to watchdog trigger function
 *  \return         actEXCEPTION_UNKNOWN       Error during decoding - the public key is invalid
 *                  actOK                      else
 *  \pre            pointers must be valid
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actEd448CheckPublicKey(
  VSECPRIM_P2VAR_PARA(actEdwardsKeyCheck) workspace,
  VSECPRIM_P2CONST_PARA(actU8) publicKey,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));
# endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

# if (VSECPRIM_ECDSA_25519_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  actEd25519CheckPublicKey()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actEd25519CheckPublicKey(
  VSECPRIM_P2VAR_PARA(actEdwardsKeyCheck) workspace,
  VSECPRIM_P2CONST_PARA(actU8) publicKey,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /* the function recovers the y-coordinate and from that, computes a x-coordinate that lies on the curve.
   * so, if the public key is valid, coordinates on the curves will be returned */
  actRETURNCODE retVal = act25519_decodePoint(&workspace->curveInformation, &workspace->point25519, publicKey, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

  return retVal;
}
# endif

# if (VSECPRIM_EDDSA_448_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  actEd448CheckPublicKey()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actEd448CheckPublicKey(
  VSECPRIM_P2VAR_PARA(actEdwardsKeyCheck) workspace,
  VSECPRIM_P2CONST_PARA(actU8) publicKey,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /* the function recovers the y-coordinate and from that, computes a x-coordinate that lies on the curve.
   * so, if the public key is valid, coordinates on the curves will be returned */
  actRETURNCODE retVal = act448_decodePoint(&workspace->curveInformation, &workspace->point448, publicKey, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */

  return retVal;
}
# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  actEdKeyCheck_initCore()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(void) actEdKeyCheck_initCore(VSECPRIM_P2VAR_PARA(actEdwardsKeyCheck) workspace) /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
{
  /* differentiate between curves */
# if (VSECPRIM_ECDSA_25519_ENABLED == STD_ON)
  if (workspace->curveId == actEDWARDSCURVE25519)
  {
    act25519_initCore((VSECPRIM_P2VAR_PARA(actEdwardsCurveWs))&workspace->curveInformation); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }
# endif

# if (VSECPRIM_EDDSA_448_ENABLED == STD_ON)
  if (workspace->curveId == actEDWARDSCURVE448)
  {
    act448_initCore((VSECPRIM_P2VAR_PARA(actEdwardsCurveWs))&workspace->curveInformation); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }
# endif
}

/**********************************************************************************************************************
 *  actEdCheckPublicKey()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actEdCheckPublicKey(
  VSECPRIM_P2VAR_PARA(actEdwardsKeyCheck) workspace,
  VSECPRIM_P2CONST_PARA(actU8) publicKey,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE retVal = actEXCEPTION_PUBKEY;
# if (VSECPRIM_ECDSA_25519_ENABLED == STD_ON)
  if (workspace->curveId == actEDWARDSCURVE25519)
  {
    retVal = actEd25519CheckPublicKey(workspace, publicKey, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }
# endif
# if (VSECPRIM_EDDSA_448_ENABLED == STD_ON)
  if (workspace->curveId == actEDWARDSCURVE448)
  {
    retVal = actEd448CheckPublicKey(workspace, publicKey, watchdog); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }
# endif
  return retVal;
}

/**********************************************************************************************************************
 *  actEdCheckPrivateKey()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actEdCheckPrivateKey(
  VSECPRIM_P2CONST_PARA(actEdwardsKeyCheck) workspace,
  VSECPRIM_P2CONST_PARA(actU8) privateKey,
  const actLengthType privateKeyLength)
{
  actRETURNCODE retVal = actEXCEPTION_UNKNOWN;
  actLengthType expectedPrivateKeyLength = 0u;
  actBNDIGIT privateKeyBNDigit[BNDIGITS_456];
  actBNSetZero(privateKeyBNDigit, BNDIGITS_456); /* SBSW_VSECPRIM_FCT_CALL_LOCAL_BUFFER_FIXED_SIZE */

  /* check if the given private key is zero */
# if (VSECPRIM_ECDSA_25519_ENABLED == STD_ON)
  if (workspace->curveId == actEDWARDSCURVE25519)
  {
    expectedPrivateKeyLength = actEd25519_KEY_SIZE;
    actBNLoadLE(privateKeyBNDigit, privateKey, expectedPrivateKeyLength); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }
# endif
# if (VSECPRIM_EDDSA_448_ENABLED == STD_ON)
  if (workspace->curveId == actEDWARDSCURVE448)
  {
    expectedPrivateKeyLength = actEd448_KEY_SIZE;
    act448_BNLoadLE(privateKeyBNDigit, privateKey, expectedPrivateKeyLength); /* SBSW_VSECPRIM_CALL_FUNCTION */
  }
# endif

  if (privateKeyLength != expectedPrivateKeyLength)
  {
    retVal = actEXCEPTION_INPUT_LENGTH;
  }
  else if (actBNIsZero(privateKeyBNDigit, (actLengthType)actBNGetDigitLengthFromBit(actBytesToBits((actLengthType)expectedPrivateKeyLength))) == TRUE) /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_FIXED_SIZE */
  {
    retVal = actEXCEPTION_PRIVKEY;
  }
  else
  {
    retVal = actOK;
  }
  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTEDCHECKKEY_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  END OF FILE: actEdCheckKey.c
 *********************************************************************************************************************/
