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
/*!       \file  actSLHDSA.c
 *        \unit  act_SLHDSASchemes
 *       \brief  SLH-DSA verify algorithm of the message digest for version:
 *                 - 128S
 *
 *      \details This file is part of the embedded systems library cvActLib.
 *               Implements the SLH-DSA verify algorithm of the message digest for version:
 *                - 128S
 *               in NIST FIPS-205 (draft) from august 2023:
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

#define ACTSLHDSA_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "actSLHDSA.h"
#include "actSLHDSA_HyperTree.h"
#include "actSLHDSA_FORS.h"
#include "actSLHDSA_Utilities.h"
#include "actSLHDSA_Types.h"

#if (VSECPRIM_ACTSLHDSA_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if defined ACT_PLATFORM_UINT64_AVAILABLE

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actSLHDSAVerify()
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
 */
VSECPRIM_FUNC(actRETURNCODE) actSLHDSAVerify(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2CONST_PARA(actU8) slhdsaSignature,
  VSECPRIM_P2CONST_PARA(actU8) digest,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actU8 maxNumberOfBitsInt16 = 16u;
  actU8 maxNumberOfBitsInt64 = 64u;
  actU64 maskU64 = 0xFFFFFFFFFFFFFFFFu;
  actU16 maskU16 = 0xFFFFu;
  actU64 treeIdx = 0u;
  actU16 leafIdx = 0u;

  /* Define local buffers for adrs and the FORS public key */
  actU8 adrs[actSLHDSA_ADRS32_LENGTH] = {0u};
  actU8 forsPublicKey[actSLHDSA_MAIN_PARAMETER_MAX] = {0u};

  /* Init workspace, compute parameters from main parameters */
  actInitWorkSpaceSLHDSA(ws);

  /* Extract message digest and indices from digest:
   * digest = [messageDigest || treeIdx || leafIdx]
   * Note: - treeIdxLength is computed in actInitWorkSpaceSLHDSA() and it corresponds to
   *         ceil((h - h_prime)/8). (see line 11 in algorithm 19 FIPS205).
   *         This is maximal 8 (version 256F), thus actVarLenBEtoU64() can be used.
   *       - leafIdxLength is computed in actInitWorkSpaceSLHDSA() and it corresponds to
   *         ceil(h_prime/8). (see line 12 in algorithm 19 FIPS205).
   *         This is maximal 2 (version 128S and 192S), thus actVarLenBEtoU16() can be used. */
  treeIdx = actVarLenBEtoU64(&(digest[ws->parameters.getTreeIdx]), ws->parameters.treeIdxLength);
  leafIdx = actVarLenBEtoU16(&(digest[ws->parameters.getLeafIdx]), ws->parameters.leafIdxLength);

  /* Reducing a mod 2^k is equivalent to (a &= 111...111) where the right value consists of k 1s.
   * To get 111...111 with k ones in a data type of max t bits (k <= t), shift the max value of the data type
   * to the right by (t - k) bits.
   * For example, computation of (a mod 2^10):
   * - max actU16 value: max = 1111 1111 1111 1111
   * - Shift max by 16 - 10 = 6 bits: cst = max >> (16 - 10) = 11 1111 1111
   * - Compute a & cst = a & 11 1111 1111 = a mod 2^10 */

  treeIdx = treeIdx & (actU64)((maskU64 >> (maxNumberOfBitsInt64 - ws->parameters.treeIdxLengthInBits)));
  leafIdx = leafIdx & (actU16)((maskU16 >> (maxNumberOfBitsInt16 - ws->parameters.leafIdxLengthInBits)));

  /* Set address words */
  actSetTreeAdrs(adrs, treeIdx);
  actSetTypeAndClear(adrs, actSLHDSA_ADRS_TYPE_FORS_TREE);
  actSetKeyPairAdrs(adrs, leafIdx);

  /* Compute FORS public key from the message digest and the FORS signature */
  actSLHDSAForsPublicKeyFromSig(ws, forsPublicKey, &slhdsaSignature[ws->parameters.getForsSignature],
                            digest, adrs, watchdog);

  /* Verify the FORS public key */
  return actSLHDSAHyperTreeVerify(ws, forsPublicKey, &slhdsaSignature[ws->parameters.getHyperTreeSignature],
                                                                                   &treeIdx, &leafIdx, watchdog);
}

# endif /* defined ACT_PLATFORM_UINT64_AVAILABLE */

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VSECPRIM_ACTSLHDSA_ENABLED == STD_ON */

/**********************************************************************************************************************
 *  END OF FILE: actSLHDSA.c
 *********************************************************************************************************************/
