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
/*!       \file  actSLHDSA_FORS.c
 *         \unit act_SLHDSAFors
 *       \brief  SLH-DSA FORS algorithms for version:
 *                 - 128S
 *
 *      \details This file is part of the embedded systems library cvActLib.
 *               Implements the SLH-DSA FORS functions for version:
 *                - 128S
 *               of section 8.4 in NIST FIPS-205 (draft) from august 2023:
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

#define ACTSLHDSA_FORS_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "actSLHDSA_FORS.h"
#include "actSLHDSA_BuildingFct.h"

#include "actSLHDSA_Types.h"
#include "actSLHDSA_Utilities.h"
#include "actUtilities.h"

#if (VSECPRIM_ACTSLHDSA_FORS_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if defined ACT_PLATFORM_UINT64_AVAILABLE

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actSLHDSAForsPublicKeyFromSig()
 *********************************************************************************************************************/
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
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
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
VSECPRIM_FUNC(void) actSLHDSAForsPublicKeyFromSig(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2VAR_PARA(actU8) forsPublicKey,
  VSECPRIM_P2CONST_PARA(actU8) forsSignature,
  VSECPRIM_P2CONST_PARA(actU8) messageDigest,
  VSECPRIM_P2VAR_PARA(actU8) adrs,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actU16 indices[actSLHDSA_FORS_NUMBER_TREES_MAX] = {0u}; /* array to store the converted message digest segments */
  actU8 forsPkAdrs[actSLHDSA_ADRS32_LENGTH] = {0u}; /* FORS tree roots compression address */

  VSECPRIM_P2CONST_PARA(actU8) currentForsTree = NULL_PTR;
  VSECPRIM_P2CONST_PARA(actU8) currentForsTreeSecretKey = NULL_PTR;
  VSECPRIM_P2CONST_PARA(actU8) currentForsTreeAuthPath = NULL_PTR;

  /* Create new address for the FORS roots hashing process.
   * This is done in FIPS 205 at the end of algorithm 16, but can be done at the beginning since the relevant
   * informations (layer address and tree address) are not changed. */
  actMemCpyByteArray(forsPkAdrs, adrs, actSLHDSA_ADRS32_LENGTH);
  actSetTypeAndClear(forsPkAdrs, actSLHDSA_ADRS_TYPE_FORS_ROOTS);
  actCopyKeyPairAdrs(forsPkAdrs, adrs);

  /* Initialize the hash computation of the roots of the FORS trees */
  actSLHDSAInitHashT(ws, forsPkAdrs, watchdog);

  /* Convert message into t base representation, the result is a 16-bits array of length forsNbrTrees,
   * where each entry corresponds to the position of a leaf node in its tree.
   * These integers are used to determine the position in the Merkle Tree of the hash of the secret values
   * from the signature.
   *  Example: We have three trees, resulting array indices = [2,0,7].
   *           The positions of the hash of the secrets are:
   *            - first tree: second leaf
   *            - second tree: zeroth leaf
   *            - third tree: seventh leaf */
  actBEU8ToBase2PowerB(indices,
                       ws->parameters.forsNbrTrees,
                       messageDigest,
                       ws->parameters.forsTreeHeight);

  /* iterate over all trees to compute the roots of the k Merkle Trees */
  for(actU8 i = 0u; i < ws->parameters.forsNbrTrees; i++)
  {
    actU8 node[actSLHDSA_MAIN_PARAMETER_MAX] = {0u};
    actU8 root[actSLHDSA_MAIN_PARAMETER_MAX] = {0u}; /* stores the computed root node for each tree */

    /* jump to current tree in signature */
    currentForsTree = &forsSignature[ws->parameters.getForsTreeSigAtIdx * i];

     /* get leaf of current tree - which is part of the private key */
    currentForsTreeSecretKey = &currentForsTree[ws->parameters.getForsTreeSK];

    /* extract the corresponding authentication path for the leaf from signature */
    currentForsTreeAuthPath = &currentForsTree[ws->parameters.getForsTreeAuthPath];

    /* start at leaf level of tree */
    actSetTreeHeight(adrs, 0u);

    /* calculate the leaf index of the private key
     * example: We have three trees, resulting array indices = [2,0,7], k = 3 and a = 3 (tree height=3).
     *          For i = 0 we get 0 * 2^3 + indices[i] =  0 + 2 =  2
     *          For i = 1 we get 1 * 2^3 + indices[i] =  8 + 0 =  8
     *          For i = 2 we get 2 * 2^3 + indices[i] = 16 + 7 = 23 */
    actSetTreeIndex(adrs, (((actU32)(i) * (actU32)(ws->parameters.forsNbrLeafs)) + (actU32) indices[i]));

    /* hash current leaf node (hash secret value) */
    actSLHDSAHash(ws, node, adrs, currentForsTreeSecretKey, ws->parameters.mainParameter, watchdog);

    /* use the hash of secret values along with corresponding authentication path
     * from signature to compute Merkle Tree roots */
    actComputeRootInMerkleTreeWithAuthPath(ws, root,
    ws->parameters.forsTreeHeight, node, indices[i], currentForsTreeAuthPath, adrs, watchdog);

    /* Update the hash computation of the roots of the FORS trees */
    actSLHDSAUpdateHashT(ws, root, watchdog);
  }
  /* Finalize the hash computation of the roots of the FORS trees */
  actSLHDSAFinalizeHashT(ws, forsPublicKey, watchdog);
}

# endif /* defined ACT_PLATFORM_UINT64_AVAILABLE */

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VSECPRIM_ACTSLHDSA_FORS_ENABLED == STD_ON */

/**********************************************************************************************************************
 *  END OF FILE: actSLHDSA_FORS.c
 *********************************************************************************************************************/
