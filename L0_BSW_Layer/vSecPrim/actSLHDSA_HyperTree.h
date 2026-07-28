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
/*!        \file  actSLHDSA_HyperTree.h
 *        \brief  SLH-DSA HyperTree algorithms for version:
 *                - 128S
 *
 *      \details This file is part of the embedded systems library cvActLib.
 *               Implements the HyperTree function headers for version:
 *                - 128S of section 7.2 in FIPS-205:
 *               nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.205.ipd.pdf
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

#ifndef ACTSLHDSA_HYPERTREE_H
# define ACTSLHDSA_HYPERTREE_H

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
 *  actSLHDSAHyperTreeVerify()
 *********************************************************************************************************************/
/*! \brief          The function actSLHDSAHyperTreeVerify() verifies a hypertree signature.
 *  \details        The algorithm follows algorithm 12 in FIPS205 from
 *                  nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.205.ipd.pdf
 *                  Steps:
 *                  - create address to navigate through hypertree
 *                  - set tree address
 *                  - extract initial XMSS signature from the given hypertree signature
 *                  - compute initial XMSS publick key
 *                  - Iterate through hypertree layers: for each subsequent layer in the hypertree:
 *                    - update leaf index and tree index for the current layer
 *                    - set the layer address
 *                    - extract the XMSS signature for the current layer
 *                    - compute the XMSS public key from the current layer, using the previously computed node
 *                  - compare computed key with hypertree public key (pkRoot)
 *                    - if equal: verification is successful
 *                    - if not equal: verification failed
 *  \param[in,out]  ws                   (in)  Pointer to workspace.
 *                                       (out) Pointer to workspace.
 *                                       to the public key.
 *  \param[in]      forsPublicKey        Pointer to FORS public key, which is verified.
 *  \param[in]      hyperTreeSignature   Pointer to hypertree signature.
 *  \param[in,out]  treeIdx              (in)  Pointer to the index of the leaf within the hypertree structure.
 *                                             It has a maximum of 64 bits.
 *                                       (out) Pointer to the last tree index.
 *  \param[in,out]  leafIdx              (in)  Pointer to the index of a leaf node within an individual XMSS tree.
 *                                             It has a maximum of 9 bits.
 *                                       (out) Pointer to the last leaf index.
 *  \param[in]      watchdog             Pointer to the watchdog trigger function
 *  \return         actOK                     verification successful
 *                  actVERIFICATION_FAILED    else
 *  \pre            Provided pointers must be valid.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSLHDSAHyperTreeVerify(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2CONST_PARA(actU8) forsPublicKey,
  VSECPRIM_P2CONST_PARA(actU8) hyperTreeSignature,
  VSECPRIM_P2VAR_PARA(actU64) treeIdx,
  VSECPRIM_P2VAR_PARA(actU16) leafIdx,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# endif /* defined ACT_PLATFORM_UINT64_AVAILABLE */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
} /* extern "C" */
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* ACTSLHDSA_HYPERTREE_H */

/**********************************************************************************************************************
 *  END OF FILE: actSLHDSA_HyperTree.h
 *********************************************************************************************************************/
