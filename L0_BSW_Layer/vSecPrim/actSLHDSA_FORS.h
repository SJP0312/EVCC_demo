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
/*!       \file  actSLHDSA_FORS.h
 *       \brief  SLHDSA FORS
 *
 *      \details This file is part of the embedded systems library cvActLib.
 *               Function headers for SLH-DSA FORS functions for version:
 *                - 128S of section 8.4 in FIPS-205:
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

#ifndef ACTSLHDSA_FORS_H
# define ACTSLHDSA_FORS_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "actITypes.h"
# include "actConfig.h"
# include "actSLHDSA_Types.h"

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
 *  actSLHDSAForsPublicKeyFromSig()
 *********************************************************************************************************************/
/*! \brief         Computation of a candidate FORS public key from a FORS signature and a
 *                 corresponding message digest.
 *  \details       Algorithm 16 from nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.205.ipd.pdf
 *                 steps:
 *                 - convert message into base t representation (where t = 2^a) by calling actBEU8ToBase2PowerB.
 *                   ka bits of the message digest are split into k a-bit strings, each of which is interpreted
 *                   as an integer between 0 and t - 1.
 *                   The integers are used to determine the positions in the Merkle trees of the hashed secret values
 *                   from the signature.
 *                 - iterate over the k trees to compute each root:
 *                   - go to each tree by jumping to the correct index of forsSignature (forsSignature consists of
 *                     n bytes private key values and a * n bytes of authentication path) to extract its secret value
 *                     and the corresponding authentication path.
 *                   - compute the hash of the secret values.
 *                   - compute the root of each tree by calling actComputeRootInMerkleTreeWithAuthPath()
 *                 - hash all roots together. This hash forms the FORS public key.
 *                 Example: calling actBEU8ToBase2PowerB gives us indices = [2,0,7]
 *                 o: leaf node    a: part of authentication path   x: secret value
 *                 leaf indices:    0    1 2   3 4  5  6    7   8  9 10 11 12 13 14 15    16 17 18  19 20  21 22 23
 *                                  o    o x   a o  o  o    o   x  a o  o   o  o  o  o    o   o  o   o  o   o  a  x
 *                                  |    | |   | |  |  |    |   |  | |  |   |  |  |  |    |   |  |   |  |   |  |  |
 *                                  o'  o' x'  a o' o' o'  o'  x'  a o' o'  o' o' o' o'   o'  o' o'  o' o'  o' a  x'
 *                                   \  /   \  / \  /  \  /     \  / \  /   \  /  \  /     \  /  \  /    \  /  \  /
 *                                    \/     \/   \/    \/       \/   \/     \/    \/       \/    \/      \/    \/
 *                                    a      --   --    --       --    a     --    --       --    --      a    --
 *                                     \    /     \    /         \   /       \   /          \    /        \    /
 *                                      \  /       \  /           \ /         \ /            \  /          \  /
 *                                       --         a             --          a               a             --
 *                                        \       /                \         /                 \           /
 *                                         \     /                  \       /                   \         /
 *                                          \   /                    \     /                     \       /
 *                                           \ /                      \   /                       \     /
 *                                          root[0]                   root[1]                      root[2]
 *                 The roots are hashed together and form the FORS public key.
 *  \param[in,out]  ws                (in)  Pointer to workspace.
 *                                    (out) Pointer to workspace.
 *  \param[in,out]    forsPublicKey   (in)  buffer to candidate FORS public key
 *                                    (out) computed candidate FORS public key
 *  \param[in]        forsSignature   Pointer to a FORS signature, which is part of SLHDSA signature
 *  \param[in]        messageDigest   pointer to message digest
 *  \param[in,out]    adrs            (in) Pointer to used address
 *                                    (out) Pointer to address, where treeIndex, treeHeight have been changed
 *  \param[in]        watchdog        Pointer to the watchdog trigger function
 *  \pre         Pointers must be valid.
 *  \context     TASK
 *  \reentrant   TRUE, for different workspaces
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSLHDSAForsPublicKeyFromSig(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2VAR_PARA(actU8) forsPublicKey,
  VSECPRIM_P2CONST_PARA(actU8) forsSignature,
  VSECPRIM_P2CONST_PARA(actU8) messageDigest,
  VSECPRIM_P2VAR_PARA(actU8) adrs,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# endif /* defined ACT_PLATFORM_UINT64_AVAILABLE */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
} /* extern "C" */
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* ACTSLHDSA_FORS_H */

/**********************************************************************************************************************
 *  END OF FILE: actSLHDSA_FORS.h
 *********************************************************************************************************************/
