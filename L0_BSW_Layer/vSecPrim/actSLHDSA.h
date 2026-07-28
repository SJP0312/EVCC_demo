/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  actSLHDSA.h
 *        \brief  SLH-DSA verify algorithm of the message digest for version:
 *                 - 128S
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

#ifndef ACTSLHDSA_H
# define ACTSLHDSA_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "actSLHDSA_Types.h"
# include "actITypes.h"
# include "actConfig.h"

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
extern "C"
{
# endif

# if defined ACT_PLATFORM_UINT64_AVAILABLE

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actSLHDSAVerify()
 *********************************************************************************************************************/
/*! \brief          This algorithm verifies the SLH-DSA signature given the digest of the message.
 *  \details        It follows algorithm 19 in FIPS205, except for lines 1, 2, 3, 5 and 9 which are handled
 *                  on higher level.
 *                  Steps:
 *                  - Declare and set variables
 *                  - Extract message digest, tree index and leaf index from the digest
 *                  - Set the address
 *                  - Compute FORS public key from the message digest and the FORS signature
 *                  - Verify the FORS public key
 *  \param[in,out]  ws               (in)  Pointer to workspace.
 *                                   (out) Pointer to workspace.
 *  \param[in]      slhdsaSignature  Pointer to the SLH-DSA signature.
 *  \param[in]      digest           Pointer to the digest.
 *  \param[in]      watchdog         Pointer to the watchdog trigger function.
 *  \return         actOK                    Verification of the digest successful
 *                  actVERIFICATION_FAILED   Verification failed
 *  \pre            Provided pointers must be valid.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSLHDSAVerify(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2CONST_PARA(actU8) slhdsaSignature,
  VSECPRIM_P2CONST_PARA(actU8) digest,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# endif /* defined ACT_PLATFORM_UINT64_AVAILABLE */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
} /* extern "C" */
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* ACTSLHDSA_H */

/**********************************************************************************************************************
 *  END OF FILE: actSLHDSA.h
 *********************************************************************************************************************/
