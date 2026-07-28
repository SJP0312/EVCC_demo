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
/*!        \file  actISM2.h
 *         \unit  act_SM2
 *        \brief  Interface for SM2 implementation.
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

#ifndef ACTISM2_H
# define ACTISM2_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "actITypes.h"
# include "actSM3.h"
# include "actECPoint.h"

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
extern "C" {
# endif

/**********************************************************************************************************************
 *  actISM2CalculateZA()
 *********************************************************************************************************************/
/*! \brief          Calculate the SM2 user info ZA from user id, curve parameters and public key.
 *  \details        -
 *  \param[in,out]  sm2                   (in) algorithm context buffer
 *                                        (out) algorithm context buffer
 *  \param[in]      id                    pointer to the user id; may be NULL
 *  \param[in]      idLength              length of the user id in bits
 *  \param[in]      publicKeyX            pointer to x-coordinate of public key
 *  \param[in]      publicKeyY            pointer to y-coordinate of public key
 *  \param[in,out]  za                    (in)  pointer buffer to store the user info
 *                                        (out) pointer to buffer storing the user info
 *  \param[in]      watchdog              Pointer to watchdog trigger function
 *  \pre            All provided pointers must be valid (except for id)
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actISM2CalculateZA(VSECPRIM_P2VAR_PARA(actSM2STRUCT) sm2,
  VSECPRIM_P2CONST_PARA(actU8) id,
  const actLengthType idLength,
  VSECPRIM_P2CONST_PARA(actU8) publicKeyX,
  VSECPRIM_P2CONST_PARA(actU8) publicKeyY,
  VSECPRIM_P2VAR_PARA(actU8) za,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
    }  /*  extern "C"  */
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* ACTISM2_H */

/***********************************************************************************************************************
 *  END OF FILE: actISM2.h
 **********************************************************************************************************************/

