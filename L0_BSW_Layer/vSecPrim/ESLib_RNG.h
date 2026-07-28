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
/*!        \file  ESLib_RNG.h
 *        \brief  Random number generator header.
 *
 *      \details Currently the actClib version is used.
 *               This file is part of the embedded systems library cvActLib/ES
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

#ifndef ESLIB_RNG_H
# define ESLIB_RNG_H

# include "ESLib_t.h"
# include "ESLib_ERC.h"

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
extern "C"
{
# endif

/*****************************************************************************
 * Random number generator defines and functions
 *****************************************************************************/

# define ESL_MAXSIZEOF_WS_RNG                                         ESL_MAXSIZEOF_WS_FIPS186

  typedef struct
  {
    eslt_WorkSpaceHeader header;
    eslt_Byte wsRNG[ESL_MAXSIZEOF_WS_RNG];
  } eslt_WorkSpaceRNG;

# define ESL_SIZEOF_RNG_STATE                                         ESL_SIZEOF_RNGFIPS186_STATE

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*****************************************************************************
 * Random number generator functions (according to FIPS186-2)
 *****************************************************************************/

/**********************************************************************************************************************
 * esl_getBytesRNG
 *********************************************************************************************************************/
/*!
 * \brief          Get random byte
 * \details        Function shall generate the given number of random bytes and store these bytes in the passed array.
 *                 This can be achieved by e.g. using a TRNG or PRNG of an available cryptographic hardware
 *                 accelerator or using one of the provided software PRNG implementations, e.g. the DRBG algorithm.
 * \param[in]      targetLength    the number of bytes that shall be generated
 * \param[in,out]  target          (in) pointer to output buffer with at least targetLength bytes.
 *                                 (out) pointer to generated random bytes
 * \return         ESL_ERC_PARAMETER_INVALID input parameter is NULL
 *                 ESL_ERC_NO_ERROR          else
 * \pre            -
 * \context        TASK
 * \reentrant      TRUE
 * \synchronous    TRUE
 *********************************************************************************************************************/
extern VSECPRIM_FUNC(eslt_ErrorCode) esl_getBytesRNG(
  const eslt_Length targetLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) target);

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
}                               /* extern "C" */
# endif

#endif /* ESLIB_RNG_H */

/**********************************************************************************************************************
 *  END OF FILE: ESLib_RNG.h
 *********************************************************************************************************************/
