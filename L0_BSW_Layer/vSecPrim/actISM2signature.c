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
/*!        \file  actISM2signature.c
 *         \unit  act_SM2
 *        \brief  SM2 signature implementation.
 *      \details Currently the actClib version is used.
 *               This file is part of the embedded systems library actCLib
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

#define ACTISM2SIGNATURE_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "actISM2signature.h"
#include "actSM2.h"
#include "actECLengthInfo.h"
#include "actECPoint.h"
#include "actECTools.h"
#include "actSM3.h"

#if (VSECPRIM_ACTISM2SIGNATURE_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
/**********************************************************************************************************************
 *  actSM2Init()
 *********************************************************************************************************************/
/*! \brief       This function initializes the SM2 workspace.
 *  \details     -
 *  \param[in,out] workSpace    (in) workspace
 *                              (out) initialized workspace
 *  \param[in]     wsSize       length of workspace in bytes
 *  \param[in]     domain       domain parameter
 *  \param[in]     domainExt    domain parameter extensions (Montgomery constants etc.)
 *  \param[in]     speedUpExt   (optional) pre-computations
 *  \param[in]     algo_flag    actEC_ALGO_FLAG_SP or actEC_ALGO_FLAG_VP
 *  \return        actEXCEPTION_DOMAIN       domain decoding error
 *                 actEXCEPTION_DOMAIN_EXT   domain_ext decoding error
 *                 actEXCEPTION_SPEEDUP_EXT  speedup_ext decoding error
 *                 actEXCEPTION_MEMORY       wksp_len too small
 *                 actOK                     else
 *  \pre         all provided pointers must be valid
 *               domain, domain_ext and speedup_ext have to be valid ASN1 structures for ECC domain parameters.
 *               The addresses of domain, domain_ext and speedup_ext have to be valid until returning from
 *               actSM2Sign(), because the pointers to the data stored in domain, domain_ext and speedup_ext
 *               are stored in the workspace. These pointers are used as long as the workspace is used.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actSM2Init(
  VSECPRIM_P2VAR_PARA(actSM2STRUCT) workSpace,
  actLengthType wsSize,
  VSECPRIM_P2ROMCONST_PARA(actU8) domain,
  VSECPRIM_P2ROMCONST_PARA(actU8) domainExt,
  VSECPRIM_P2ROMCONST_PARA(actU8) speedUpExt,
  actU16 algo_flag);

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  actSM2Init()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actSM2Init(
  VSECPRIM_P2VAR_PARA(actSM2STRUCT) workSpace,
  actLengthType wsSize,
  VSECPRIM_P2ROMCONST_PARA(actU8) domain,
  VSECPRIM_P2ROMCONST_PARA(actU8) domainExt,
  VSECPRIM_P2ROMCONST_PARA(actU8) speedUpExt,
  actU16 algo_flag)
{
  actRETURNCODE result;
  result = actECInit(domain, domainExt, speedUpExt, algo_flag, &workSpace->eccWorkspace.baseData, wsSize);
  if (result == actOK)
  {
    /* verify, that bit-length(order) >= bit-length(SM3 digest) */
    if (actBNGetBitLength(workSpace->eccWorkspace.baseData.Curve.n_field.m, workSpace->eccWorkspace.baseData.Curve.n_field.m_length) < actBytesToBits(actSM3_HASH_WORDS * actSM3_WORD_SIZE))
    {
      /* curve not valid for SM2 */
      result = actEXCEPTION_DOMAIN;
    }
  }
  return result;
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  actSM2InitSign()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actSM2InitSign(
  VSECPRIM_P2VAR_PARA(actSM2STRUCT) workSpace,
  const actLengthType wsSize,
  VSECPRIM_P2ROMCONST_PARA(actU8) domain,
  VSECPRIM_P2ROMCONST_PARA(actU8) domainExt,
  VSECPRIM_P2ROMCONST_PARA(actU8) speedUpExt)
{
  return actSM2Init(workSpace, wsSize, domain, domainExt, speedUpExt, actEC_ALGO_FLAG_SP);
}

/***********************************************************************************************************************
 *  actSM2AddUserInfo()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(void) actSM2AddUserInfo(VSECPRIM_P2VAR_PARA(actSM2STRUCT) workSpace,
  VSECPRIM_P2CONST_PARA(actU8) userInfo,
  VSECPRIM_P2CONST_PARA(actU8) id,
  const actLengthType idLength,
  VSECPRIM_P2CONST_PARA(actU8) publicKeyX,
  VSECPRIM_P2CONST_PARA(actU8) publicKeyY,
  VSECPRIM_P2FUNC( VSECPRIM_NONE, void, watchdog)(void))
{
  VSECPRIM_P2VAR_PARA(actSM3STRUCT) sm3 = &workSpace->sm3;
  if (userInfo != NULL_PTR)
  {
    /* pre-calculated user info */
    /* initialize and update message hash */
    actSM3Init(sm3);
    (void)actSM3Update(sm3, userInfo, actHASH_SIZE_SM3, watchdog);
  }
  else
  {
    actU8 ZA[actHASH_SIZE_SM3];
    /* calculate user info from id, domain and public key */
    actISM2CalculateZA(workSpace, id, idLength, publicKeyX, publicKeyY, ZA, watchdog);

    actSM3Init(sm3);
    (void)actSM3Update(sm3, ZA, actHASH_SIZE_SM3, watchdog);
  }
}

/***********************************************************************************************************************
 *  actSM2UpdateMessage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actSM2UpdateMessage(
  VSECPRIM_P2VAR_PARA(actSM2STRUCT) workSpace,
  VSECPRIM_P2CONST_PARA(actU8) message,
  const actLengthType msgLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  return actSM3Update(&workSpace->sm3, message, msgLength, watchdog);
}

/***********************************************************************************************************************
 *  actSM2Sign()
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
VSECPRIM_FUNC(actRETURNCODE) actSM2Sign(
  VSECPRIM_P2VAR_PARA(actSM2STRUCT) workSpace,
  VSECPRIM_P2CONST_PARA(actU8) privateKey,
  VSECPRIM_P2VAR_PARA(actU8) signatureR,
  VSECPRIM_P2VAR_PARA(actU8) signatureS,
  VSECPRIM_P2FUNC( VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE retVal;
  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp = &workSpace->eccWorkspace;
  VSECPRIM_P2CONST_PARA(actECCURVE) curve = &workSpace->eccWorkspace.baseData.Curve;
  actLengthType n_length = curve->n_field.m_length;
  actLengthType n_bytes = curve->n_field.m_byte_length;
  actU8 messageDigest[actHASH_SIZE_SM3] = {0u};
  VSECPRIM_P2VAR_PARA(actBNDIGIT) e = wksp->msg.hashed_message;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) d = wksp->dataPair.privKeys.privKey;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r = wksp->signature_r;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) s = wksp->signature_s;

  /* initialization of d */
  actBNSetOctetString(d, n_length, privateKey, n_bytes);

  /* check if 0 < d < n before continue */
  if (actBNIsZero(d, n_length))
  {
     retVal =  actEXCEPTION_PRIVKEY;
  }
  /* d is the private key, thus make actBNCompare iterate over all entries. */
  else if (actBNCompare(d, curve->n_field.m, n_length, TRUE) >= actCOMPARE_EQUAL)
  {
    retVal = actEXCEPTION_PRIVKEY;
  }
  else
  {
    /* SM2 Steps A1 + A2: e = SM3(ZA || M) */
    actSM3Finalize(&workSpace->sm3, messageDigest, watchdog);

    /* initialization of e */
    actBNSetOctetString(e, n_length, messageDigest, actHASH_SIZE_SM3);

    /* call SM2 sp and calculate signature (r, s) */
    retVal = actSM2sp(e, d, r, s, wksp, watchdog);

    /* if ok, write (r, s) to output */
    if (retVal == actOK)
    {
      /* SM2 Steps A7: : Convert the type of data r,s to be bit strings */
      actBNOctetString(signatureR, n_bytes, r, n_length);
      actBNOctetString(signatureS, n_bytes, s, n_length);
    }
    /* wipe local d */
    actBNSetZero(d, n_length);
  }
  return retVal;
}

/***********************************************************************************************************************
 *  actSM2InitVerify()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actSM2InitVerify(VSECPRIM_P2VAR_PARA(actSM2STRUCT) workSpace,
  const actLengthType wsSize,
  VSECPRIM_P2ROMCONST_PARA(actU8) domain,
  VSECPRIM_P2ROMCONST_PARA(actU8) domainExt)
{
  return actSM2Init(workSpace, wsSize, domain, domainExt, NULL_PTR, actEC_ALGO_FLAG_VP);
}

/***********************************************************************************************************************
 *  actSM2Verify()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actSM2Verify(
  VSECPRIM_P2VAR_PARA(actSM2STRUCT) workSpace,
  VSECPRIM_P2CONST_PARA(actU8) publicKeyX,
  VSECPRIM_P2CONST_PARA(actU8) publicKeyY,
  VSECPRIM_P2CONST_PARA(actU8) signatureR,
  VSECPRIM_P2CONST_PARA(actU8) signatureS,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE retVal = actOK;
  actECPOINT Q;
  VSECPRIM_P2CONST_PARA(actECCURVE) curve = &workSpace->eccWorkspace.baseData.Curve;
  actLengthType p_length = curve->p_field.m_length;
  actLengthType p_bytes = curve->p_field.m_byte_length;
  actLengthType n_length = curve->n_field.m_length;
  actLengthType n_bytes = curve->n_field.m_byte_length;
  actU8 messageDigest[actHASH_SIZE_SM3] = {0u};
  VSECPRIM_P2VAR_PARA(actBNDIGIT) e = workSpace->eccWorkspace.msg.hashed_message;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r = workSpace->eccWorkspace.signature_r;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) s = workSpace->eccWorkspace.signature_s;

  Q.x = workSpace->eccWorkspace.public_key_x;
  Q.y = workSpace->eccWorkspace.public_key_y;

  /* initialization of r, s */
  actBNSetOctetString(r, n_length, signatureR, n_bytes);
  actBNSetOctetString(s, n_length, signatureS, n_bytes);

  if (actBNIsZero(r, n_length))
  {
    retVal = actVERIFICATION_FAILED;
  }
  else if (actBNCompare(r, curve->n_field.m, n_length, FALSE) >= actCOMPARE_EQUAL) /* r is public information, thus, the runtime of actBNCompare can be shortened. */
  {
    retVal = actVERIFICATION_FAILED;
  }
  else if (actBNIsZero(s, n_length))
  {
    retVal = actVERIFICATION_FAILED;
  }
  else if (actBNCompare(s, curve->n_field.m, n_length, FALSE) >= actCOMPARE_EQUAL)  /* s is public information, thus, the runtime of actBNCompare can be shortened. */
  {
    retVal = actVERIFICATION_FAILED;
  }
  else
  {
    /* SM2 Steps B3, B4: e = SM3(ZA || M) */
    actSM3Finalize(&workSpace->sm3, messageDigest, watchdog);

    /* initialization of e */
    actBNSetOctetString(e, n_length, messageDigest, actHASH_SIZE_SM3);

    /* initialization of Q */
    actBNSetOctetString(Q.x, p_length, publicKeyX, p_bytes);
    actBNSetOctetString(Q.y, p_length, publicKeyY, p_bytes);
    Q.is_affine   = TRUE;
    Q.is_infinity = FALSE;
  }

  if (retVal == actOK)
  {
    retVal = actSM2vp(e, r, s, &Q, &workSpace->eccWorkspace, watchdog);
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTISM2SIGNATURE_ENABLED == STD_ON) */
/***********************************************************************************************************************
 *  END OF FILE: actISM2signature.c
 **********************************************************************************************************************/
