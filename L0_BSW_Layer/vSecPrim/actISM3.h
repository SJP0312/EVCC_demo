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
/*!        \file  actISM3.h
 *        \brief  Interface for SM3 implementation.
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

#ifndef ACTISM3_H
# define ACTISM3_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "actITypes.h"

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
    extern "C" {
# endif

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  actSM3Init()
 *********************************************************************************************************************/
/*! \brief          This function sets the variables in the workspace for SM3.
 *  \details        -
 *  \param[in,out]  sm3  (in) pointer to SM3 context structure
 *                       (out) pointer to SM3 initialized context structure
 *  \pre            workSpace is initialized by esl_initWorkSpaceHeader(..)
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSM3Init(VSECPRIM_P2VAR_PARA(actSM3STRUCT) sm3);

/**********************************************************************************************************************
 *  actSM3Update()
 *********************************************************************************************************************/
/*! \brief          Hash the input data given.
 *  \details        Can be called arbitrarily often between initialization and finalization of the SM3 hash algorithm.
 *                  Includes data buffered in actSM3STRUCT and stores any partial input block there.
 *  \param[in,out]  sm3      (in)  pointer to SM3 context structure
 *                           (out) updated SM3 context structure
 *  \param[in]     input     pointer to the input data
 *  \param[in]      inputSize length of the given input data in bytes
 *  \param[in]      watchdog  pointer to watchdog reset function
 *  \return         actEXCEPTION_LENGTH   total input length larger than 2^64 - 1 bit
 *                  actOK                 otherwise
 *  \pre            workSpace is initialized by actSM3Init(..)
 *                  All pointers must be valid. Total length of input cannot be greater than 2^64
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSM3Update(
  VSECPRIM_P2VAR_PARA(actSM3STRUCT) sm3,
  VSECPRIM_P2CONST_PARA(actU8) input,
  actLengthType  inputSize,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSHAFinalize()
 *********************************************************************************************************************/
/*! \brief          Finalizes the SM3 hash algorithm and returns the hash value.
 *  \details        -
 *  \param[in,out]  sm3      (in)  pointer to SM3 context structure
 *                           (out) updated SM3 context structure
 *  \param[in,out]  digest   (in)  byte array to store the hash value
 *                           (out) the final hash value
 *  \param[in]      watchdog  pointer to watchdog reset function
 *  \pre            actSM3Init() has been called once before calling this function
 *                  The buffer digest needs to provide at least actHASH_SIZE_SM3 many bytes.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSM3Finalize(
  VSECPRIM_P2VAR_PARA(actSM3STRUCT) sm3,
  VSECPRIM_P2VAR_PARA(actU8) digest,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
    }   /*  extern "C"  */
# endif

#endif /*  ACTISM3_H   */

/***********************************************************************************************************************
 *  END OF FILE: actISM3.h
 **********************************************************************************************************************/
