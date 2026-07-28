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
/*!        \file  actSM2.h
 *         \unit  act_SM2
 *        \brief  Interface to core SM2 implementation.
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

#ifndef ACTSM2_H
# define ACTSM2_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

# include "actISM2.h"
# include "actECPoint.h"

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
extern "C"
{
# endif

/**********************************************************************************************************************
 *  actSM2sp()
 *********************************************************************************************************************/
/*! \brief          This function implements the SM2 signature protocol arithmetic.
 *  \details        -
 *  \param[in]      e     the hashed message to be signed (length in BNDIGITS: n_length)
 *  \param[in]      d     the private key (length in BNDIGITS: n_length)
 *  \param[in,out]  r     (in) buffer for the signatureR (length in BNDIGITS: n_length)
 *                        (out) computed signatureR
 *  \param[in,out]  s     (in) buffer for the signatureS (length in BNDIGITS: n_length)
 *                        (out) computed signatureS
 *  \param[in,out]  wksp  (in) workspace for SM2
 *                        (out) workspace for SM2
 *  \param[in]      watchdog    pointer to watchdog trigger function
 *  \return         actEXCEPTION_UNKNOWN  internal error (e.g. point not on the curve)
 *                  actEXCEPTION_LENGTH   reduction failed
 *                  actEXCEPTION_RANDOM   random generator/generating the ephemeral key failed
 *                  actOK                 else
 *  \pre            All provided pointers must be valid
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSM2sp(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) e,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) d,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) s,
  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSM2vp()
 *********************************************************************************************************************/
/*! \brief       This function implements the SM2 verification protocol arithmetic.
 *  \details     -
 *  \param[in]      e       the signed hash value (length in BNDIGITS: n_length)
 *  \param[in]      r       pointer to signatureR (length in BNDIGITS: n_length)
 *  \param[in]      s       pointer to signatureS (length in BNDIGITS: n_length)
 *  \param[in]      Q       affine public key ( Q = [d]G, where d is the private key)
 *  \param[in,out]  wksp   (in) workspace for SM2
 *                         (out) workspace for SM2
 *  \param[in]      watchdog    pointer to watchdog trigger function
 *  \return        actVERIFICATION_FAILED signature (r,s) is invalid
 *                 actEXCEPTION_PUBKEY    public key is invalid
 *                 actEXCEPTION_UNKNOWN   internal error (e.g. point not on curve)
 *                 actOK                  otherwise
 *  \pre           All provided pointers must be valid
 *                 Q is in affine representation (X, Y, 1)
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSM2vp(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) e,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) s,
  VSECPRIM_P2CONST_PARA(actECPOINT) Q,
  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
} /* extern "C" */
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /*  ACTSM2_H  */

/***********************************************************************************************************************
 *  END OF FILE: actSM2.h
 **********************************************************************************************************************/
