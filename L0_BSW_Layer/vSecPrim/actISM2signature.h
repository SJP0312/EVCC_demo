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
/*!        \file  actISM2signature.h
 *         \unit  act_SM2
 *        \brief  Interface for SM2 signature implementation.
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
#ifndef ACTISM2SIGNATURE_H
# define ACTISM2SIGNATURE_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "actISM2.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
extern "C"
{
# endif

/**********************************************************************************************************************
 *  actSM2InitSign()
 *********************************************************************************************************************/
/*! \brief         This function initializes the SM2 workspace.
 *  \details       -
 *  \param[in,out] workSpace    (in) workspace for SM2
 *                              (out) initialized workspace
 *  \param[in]     wsSize       length of workspace in bytes
 *  \param[in]     domain       domain parameter
 *  \param[in]     domainExt    domain parameter extensions (Montgomery constants etc.)
 *  \param[in]     speedUpExt   (optional) pre-computations
 *  \return        actEXCEPTION_DOMAIN       domain decoding error
 *                 actEXCEPTION_DOMAIN_EXT   domain_ext decoding error
 *                 actEXCEPTION_SPEEDUP_EXT  speedup_ext decoding error
 *                 actEXCEPTION_MEMORY       wsSize is too small
 *                 actOK                     else
 *  \pre           all provided pointers must be valid
 *                 domain, domain_ext and speedup_ext have to be valid ASN1 structures for EC domain parameters.
 *                 The addresses of domain, domain_ext and speedup_ext have to be valid until returning from
 *                 actSM2Sign(), because the pointers to the data stored in domain, domain_ext and speedup_ext
 *                 are stored in the workspace. These pointers are used as long as the workspace is used.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSM2InitSign(
  VSECPRIM_P2VAR_PARA(actSM2STRUCT) workSpace,
  const actLengthType wsSize,
  VSECPRIM_P2ROMCONST_PARA(actU8) domain,
  VSECPRIM_P2ROMCONST_PARA(actU8) domainExt,
  VSECPRIM_P2ROMCONST_PARA(actU8) speedUpExt);

/**********************************************************************************************************************
 *  actSM2AddUserInfo()
 *********************************************************************************************************************/
/*! \brief         This function adds the userInfo to the SM2 signature.
 *  \details       Uses either:
 *                 1. the pre-calculated user info (ZA), OR
 *                 2. calculates the user info from user ID (if there is one) and public key.
 *  \param[in,out] workSpace    (in) workspace for SM2
 *                              (out) workspace for SM2, where the userInfo has been added
 * \param[in]      userInfo     pointer to user info (if pre-calculated)
 * \param[in]      id           pointer to user ID
 * \param[in]      idLength     length of user ID in BITS
 * \param[in]      publicKeyX   pointer to x coordinate of the public key
 * \param[in]      publicKeyY   pointer to y coordinate of the public key
 * \param[in]      watchdog     Pointer to watchdog trigger function
 * \pre            all provided pointers must be valid (if used)
 *                 workSpace has been initialized by actSM2InitSign() or actSM2InitVerify()
 *                 publicKeyX, publicKeyY and userInfo must be able to store at least 32 bytes, if they are used.
 * \context        TASK
 * \reentrant      FALSE
 * \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSM2AddUserInfo(VSECPRIM_P2VAR_PARA(actSM2STRUCT) workSpace,
  VSECPRIM_P2CONST_PARA(actU8) userInfo,
  VSECPRIM_P2CONST_PARA(actU8) id,
  const actLengthType idLength,
  VSECPRIM_P2CONST_PARA(actU8) publicKeyX,
  VSECPRIM_P2CONST_PARA(actU8) publicKeyY,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSM2UpdateMessage()
 *********************************************************************************************************************/
/*! \brief         Update the message representative using SM3 hashing. Can be called an arbitrary number of times.
 *  \details       -
 *  \param[in,out] workSpace    (in) workspace for SM2
 *                              (out) workspace for SM2, where the message has been added
 * \param[in]      message      pointer to (partial) message
 * \param[in]      msgLength    length of the (partial) message
 * \param[in]      watchdog     pointer to watchdog trigger function
 *  \return        actEXCEPTION_LENGTH       total input length larger than 2^64 - 1 bit
 *                 actOK                     else
 *  \pre           all provided pointers must be valid
 *                 actSM2AddUserInfo has been called before
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSM2UpdateMessage(VSECPRIM_P2VAR_PARA(actSM2STRUCT) workSpace,
  VSECPRIM_P2CONST_PARA(actU8) message,
  const actLengthType msgLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSM2Sign()
 *********************************************************************************************************************/
/*! \brief          This function calculates the signature over a message.
 *  \details        -
 *  \param[in,out]  workSpace      (in) workspace for SM2
 *                                 (out) workspace for SM2
 *  \param[in]      privateKey     pointer to the private key
 *  \param[in,out]  signatureR     (in) buffer for the signatureR
 *                                 (out) computed signatureR
 *  \param[in,out]  signatureS     (in) buffer for the signatureS
 *                                 (out) computed signatureS
 *  \param[in]      watchdog       pointer to watchdog trigger function
 *  \return        actEXCEPTION_PRIVKEY  privateKey is not in the correct range: (d == 0 || d >= n)
 *                 actEXCEPTION_UNKNOWN  internal error (e.g. point not on curve)
 *                 actEXCEPTION_LENGTH   reduction failed
 *                 actEXCEPTION_RANDOM   random generator/generating the ephemeral key failed
 *                 actOK                 else
 *  \pre           all provided pointers must be valid.
 *                 signatureR and signatureS must be able to store at least 32 bytes.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSM2Sign(
  VSECPRIM_P2VAR_PARA(actSM2STRUCT) workSpace,
  VSECPRIM_P2CONST_PARA(actU8) privateKey,
  VSECPRIM_P2VAR_PARA(actU8) signatureR,
  VSECPRIM_P2VAR_PARA(actU8) signatureS,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSM2InitVerify()
 *********************************************************************************************************************/
/*! \brief         This function initializes the SM2 workspace.
 *  \details       -
 *  \param[in,out] workSpace    (in) workspace for SM2
 *                              (out) initialized workspace
 *  \param[in]     wsSize       length of workspace in bytes
 *  \param[in]     domain       domain parameter
 *  \param[in]     domainExt   domain parameter extensions (Montgomery constants etc.)
 *  \return        actEXCEPTION_DOMAIN       domain decoding error
 *                 actEXCEPTION_DOMAIN_EXT   domain_ext decoding error OR
 **                                          curve not usable for SM2 (bit-length (order) < bit-length (SM3 hash))
 *                 actEXCEPTION_MEMORY       wsSize is too small
 *                 actOK                     else
 *  \pre           all provided pointers must be valid
 *                 domain, domain_ext and speedup_ext have to be valid ASN1 structures for EC domain parameters.
 *                 The addresses of domain, domain_ext and speedup_ext have to be valid until returning from
 *                 actSM2Verify(), because the pointers to the data stored in domain, domain_ext and speedup_ext
 *                 are stored in the workspace. These pointers are used as long as the workspace is used.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSM2InitVerify(
  VSECPRIM_P2VAR_PARA(actSM2STRUCT) workSpace,
  const actLengthType wsSize,
  VSECPRIM_P2ROMCONST_PARA(actU8) domain,
  VSECPRIM_P2ROMCONST_PARA(actU8) domainExt);

/**********************************************************************************************************************
 *  actSM2Verify()
 *********************************************************************************************************************/
/*! \brief         This function verifies a signature over a message.
 *  \details       -
 *  \param[in,out] workSpace    (in) workspace for SM2
 *                              (out) updated workspace
 *  \param[in]     publicKeyX   pointer to x coordinate of the public key
 *  \param[in]     publicKeyY   pointer to y coordinate of the public key
 *  \param[in]     signatureR   pointer to signatureR
 *  \param[in]     signatureS   pointer to signatureS
 *  \param[in]      watchdog        pointer to watchdog trigger function
 *  \return        actEXCEPTION_PUBKEY     the public key is invalid
 *                 actVERIFICATION_FAILED  (r == 0 || s == 0 || r >= n || s >= n)
 *                                         OR the signature is invalid
 *                 actEXCEPTION_UNKNOWN    internal error (e.g. point not on curve)
 *                 actOK                   otherwise
 *  \pre           all provided pointers must be valid
 *                 workSpace has been initialized by actSM2InitVerify()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSM2Verify(
  VSECPRIM_P2VAR_PARA(actSM2STRUCT) workSpace,
  VSECPRIM_P2CONST_PARA(actU8) publicKeyX,
  VSECPRIM_P2CONST_PARA(actU8) publicKeyY,
  VSECPRIM_P2CONST_PARA(actU8) signatureR,
  VSECPRIM_P2CONST_PARA(actU8) signatureS,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
}                               /* extern "C" */
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* ACTISM2SIGNATURE_H */
/**********************************************************************************************************************
 *  END OF FILE: actISM2signature.h
 *********************************************************************************************************************/

