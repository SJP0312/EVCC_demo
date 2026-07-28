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
/*!        \file  actSM3.h
 *        \brief  Interface to core SM3 implementation.
 *
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

#ifndef ACTSM3_H
# define ACTSM3_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "actISM3.h"
# include "actITypes.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
# define actSM3_WORD_SIZE                                             4u
# define actSM3_HASH_WORDS                                            actHASH_SIZE_SM3 / actSM3_WORD_SIZE

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
extern "C"
{
# endif

/***********************************************************************************************************************
 * actSM3_Transform()
 **********************************************************************************************************************/
/*! \brief         Transform a single input block. The parameter names were taken from the standard:
 *                 datatracker.ietf.org/doc/html/draft-oscca-cfrg-sm3-02
 *  \details       -
 *  \param[in]     Bi  pointer to i-th block of input data
 *  \param[in,out] Vi  (in) buffer for the transformed input data
 *                     (out) output value of i-th block
 *  \param[in]      watchdog    pointer to watchdog trigger function
 *  \pre           Pointers must be valid
 *                 Vi must be at least of length 8 - so at least 8 * 4 bytes = 32 bytes.
 *  \context       TASK
 *  \reentrant     TRUE, for different workspaces
 *  \synchronous   TRUE
 **********************************************************************************************************************/
extern VSECPRIM_FUNC(void) actSM3_Transform(
  VSECPRIM_P2CONST_PARA(actU8) Bi,
  VSECPRIM_P2VAR_PARA(actU32) Vi,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
} /* extern "C" */
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /*  ACTSM3_H  */

/***********************************************************************************************************************
 *  END OF FILE: actSM3.h
 **********************************************************************************************************************/
