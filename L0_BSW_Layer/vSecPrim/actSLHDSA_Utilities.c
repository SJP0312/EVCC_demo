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
/*!       \file  actSLHDSA_Utilities.c
 *         \unit  act_SLHDSAUtilities
 *       \brief  SLHDSA utilities
 *
 *      \details This file is part of the embedded systems library cvActLib.
 *               Implements helper functions for the signature scheme SLH-DSA, see
 *               NIST FIPS-205 (draft) from august 2023: nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.205.ipd.pdf
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

#define ACTSLHDSA_UTILITIES_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "actSLHDSA_Types.h"
#include "actSLHDSA_Utilities.h"
#include "actUtilities.h"

#if (VSECPRIM_ACTSLHDSA_UTILITIES_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if defined ACT_PLATFORM_UINT64_AVAILABLE

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actBEU8toBEU4()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_FUNC(void) actBEU8toBEU4(VSECPRIM_P2VAR_PARA(actU8) dest,
                                       actU8 destLength,
                                       VSECPRIM_P2CONST_PARA(actU8) src)
{
  actU8 idxSrc = 0u;

  for (actU8 idxDest = 0u; idxDest < destLength; idxDest++)
  {
    /* check if idxDest is even */
    if ((idxDest & 1u) == 0u)
    {
      dest[idxDest] = (src[idxSrc] & 0xF0u) >> 4u;
    }
    else
    {
      dest[idxDest] =  src[idxSrc] & 0x0Fu;
      idxSrc ++;
    }
  }
}

/**********************************************************************************************************************
 *  actBEU8ToBase2PowerB()
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
 */
VSECPRIM_FUNC(void) actBEU8ToBase2PowerB(VSECPRIM_P2VAR_PARA(actU16) dest,
                                                actU8 destLength,
                                                VSECPRIM_P2CONST_PARA(actU8) src,
                                                actU8 log2base)
{
  actU8 srcIdx = 0u;
  actU8 bits = 0u;
  actU32 total = 0u; /* Number of relevant bits in total is always less than 24 - actU32 data type is necessary */

  /* Get log2baseMask = 11...11.= 2^log2base -1u for efficient modulo reduction */
  actU16 log2baseMask = (actU16)(0xFFFFu >> (16u - log2base));

  /* Loop over the variables of dest */
  for (actU8 destIdx = 0u; destIdx < destLength; destIdx++)
  {
    /* 1) Copy enough bytes from "src" to a buffer "total" (enough means at least log2base bits)
          Variable "bits" is the amount of bits in the variable "total" that are relevant (need to by copy in "dest")
          NOTE: - Since log2base is less than 16, we never use the while-loop of algo 3 in FIPS 205 more than twice
                  in a row. To avoid the use of a while-loop, we use if-conditions. */
    if (bits < log2base)
    {
      total = (total << 8u) + src[srcIdx];
      srcIdx++;
      bits = (actU8)(bits + 8u);
      if (bits < log2base)
      {
        total = (total << 8u) + src[srcIdx];
        srcIdx++;
        bits = (actU8)(bits + 8u);
      }
    }
    /* At this point, "bits" < log2base + 8 */

    /* 2) Copy the next relevant log2base bits from "total" to the next variable of "dest".
          Keep the rest in buffer "total" for the next loop. */
    bits = (actU8)(bits - log2base);
    dest[destIdx] = (actU16)(total >> bits) & log2baseMask;
    /* At this point, "bits" < 8 */
  }
}

/**********************************************************************************************************************
 *  actVarLenBEtoU64()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_INLINE_FUNC(actU64) actVarLenBEtoU64(VSECPRIM_P2CONST_PARA(actU8) src, actU8 length)
{
  VSECPRIM_REGISTER actU64 u64 = 0u;

  for (actU8 idx = 0u; idx < length; idx++)
  {
    actU8 shift = (actU8)(8u * (length - 1u - idx));
    u64 |= ((actU64)actLOW_BYTE(src[idx])) << shift;
  }

  return u64;
}

/**********************************************************************************************************************
 *  actVarLenBEtoU16()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_INLINE_FUNC(actU16) actVarLenBEtoU16(VSECPRIM_P2CONST_PARA(actU8) src, actU8 length)
{
  VSECPRIM_REGISTER actU16 u16 = 0u;
  if (length == 1u)
  {
    u16 = src[0];
  }
  else if (length == 2u)
  {
    u16 = (actU16)(((actU16)actLOW_BYTE(src[0]) << 8u) | (actU16)actLOW_BYTE(src[1]));
  }
  else /* length == 0 */
  {
    /* according to pre, length is 0, therefore return value is not relevant */
  }

  return u16;
}

/**********************************************************************************************************************
 *  actCompressAdrs()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(void) actCompressAdrs(VSECPRIM_P2VAR_PARA(actU8) adrsCompressed,
                                    VSECPRIM_P2CONST_PARA(actU8) adrs)
{
  /* Copy layer address */
  adrsCompressed[actSLHDSA_ADRS22_LAYER_LSB] = adrs[actSLHDSA_ADRS32_LAYER_LSB];
  /* Copy tree address */
  actMemCpyByteArray(&adrsCompressed[actSLHDSA_ADRS22_TREE_MSB], &adrs[actSLHDSA_ADRS32_TREE_MSB + actSLHDSA_ADRS_WORD_LENGTH], (actSLHDSA_ADRS_WORD_LENGTH * (2u)));
  /* Copy address type */
  adrsCompressed[actSLHDSA_ADRS22_TYPE_LSB] = adrs[actSLHDSA_ADRS32_TYPE_LSB];
  /* Copy rest of the address */
  actMemCpyByteArray(&adrsCompressed[actSLHDSA_ADRS22_TYPE_LSB + 1u], &adrs[actSLHDSA_ADRS32_TYPE_LSB + 1u], (actSLHDSA_ADRS_WORD_LENGTH * (3u)));
}

/**********************************************************************************************************************
 *  actSetLayerAdrs()
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
 */
VSECPRIM_INLINE_FUNC(void) actSetLayerAdrs(VSECPRIM_P2VAR_PARA(actU8) adrs,
                                           actU8 layerAdrs)
{
  adrs[actSLHDSA_ADRS32_LAYER_LSB] = layerAdrs;
}

/**********************************************************************************************************************
 *  actSetTreeAdrs()
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
 */
VSECPRIM_INLINE_FUNC(void) actSetTreeAdrs(VSECPRIM_P2VAR_PARA(actU8) adrs,
                                          actU64 treeAdrs)
{
  actU64toBE(&adrs[actSLHDSA_ADRS32_TREE_MSB + actSLHDSA_ADRS_WORD_LENGTH], treeAdrs);
}

/**********************************************************************************************************************
 *  actSetTypeAndClear()
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
VSECPRIM_INLINE_FUNC(void) actSetTypeAndClear(VSECPRIM_P2VAR_PARA(actU8) adrs,
                                              actU8 type)
{
  /* Set address type */
  adrs[actSLHDSA_ADRS32_TYPE_LSB] = type;

  /* Set 12 last bytes to zero */
  actMemClear(&adrs[actSLHDSA_ADRS32_TYPE_LSB + 1u], (actSLHDSA_ADRS_WORD_LENGTH * (3u)));
}

/**********************************************************************************************************************
 *  actSetHashAdrs()
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
VSECPRIM_INLINE_FUNC(void) actSetHashAdrs(VSECPRIM_P2VAR_PARA(actU8) adrs,
                                          actU8 hashAdrs)
{
  adrs[actSLHDSA_ADRS32_HASH_ADRS_LSB] = hashAdrs;
}

/**********************************************************************************************************************
 *  actSetChainAdrs()
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
 */
VSECPRIM_INLINE_FUNC(void) actSetChainAdrs(VSECPRIM_P2VAR_PARA(actU8) adrs,
                                           actU8 chainAdrs)
{
  adrs[actSLHDSA_ADRS32_CHAIN_ADRS_LSB] = chainAdrs;
}

/**********************************************************************************************************************
 *  actSetKeyPairAdrs()
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
 */
VSECPRIM_INLINE_FUNC(void) actSetKeyPairAdrs(VSECPRIM_P2VAR_PARA(actU8) adrs,
                                             actU16 keyPairAdrs)
{
  actU16toBE(&adrs[actSLHDSA_ADRS32_KEY_PAIR_ADRS_MSB + 2u], keyPairAdrs);
}

/**********************************************************************************************************************
 *  actCopyKeyPairAdrs()
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
 */
VSECPRIM_INLINE_FUNC(void) actCopyKeyPairAdrs(VSECPRIM_P2VAR_PARA(actU8) adrsDest,
                                              VSECPRIM_P2CONST_PARA(actU8) adrsSrc)
{
  adrsDest[actSLHDSA_ADRS32_KEY_PAIR_ADRS_LSB - 1u] = adrsSrc[actSLHDSA_ADRS32_KEY_PAIR_ADRS_LSB - 1u];
  adrsDest[actSLHDSA_ADRS32_KEY_PAIR_ADRS_LSB] = adrsSrc[actSLHDSA_ADRS32_KEY_PAIR_ADRS_LSB];
}

/**********************************************************************************************************************
 *  actSetTreeIndex()
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
 */
VSECPRIM_INLINE_FUNC(void) actSetTreeIndex(VSECPRIM_P2VAR_PARA(actU8) adrs,
                                           actU32 treeIndex)
{
  actU32toBE(&adrs[actSLHDSA_ADRS32_TREE_INDEX_MSB], treeIndex);
}

/**********************************************************************************************************************
 *  actGetTreeIndex()
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
 */
VSECPRIM_INLINE_FUNC(actU32) actGetTreeIndex(VSECPRIM_P2CONST_PARA(actU8) adrs)
{
  return actBEtoU32(&adrs[actSLHDSA_ADRS32_TREE_INDEX_MSB]);
}

/**********************************************************************************************************************
 *  actSetTreeHeight()
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
 */
VSECPRIM_INLINE_FUNC(void) actSetTreeHeight(VSECPRIM_P2VAR_PARA(actU8) adrs,
                                            actU8 treeHeight)
{
  adrs[actSLHDSA_ADRS32_TREE_HEIGHT_LSB] = treeHeight;
}

/**********************************************************************************************************************
 *  actInitWorkSpaceSLHDSA()
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
 */
VSECPRIM_INLINE_FUNC(void) actInitWorkSpaceSLHDSA(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws)
{

  /*******************************
   * General parameters
   *******************************/
  /* Only use this macro when a WOTS signature, an XMSS authentication path or a FORS tree
   * authentication path is given */
  ws->parameters.getNodeAtIdx = ws->parameters.mainParameter;

  /*******************************
   * Parameters for Merkle Trees
   *******************************/
  ws->parameters.hInputLength = (actU8)(2u * ws->parameters.mainParameter); /* H input length [Left Node || Right Node] */

  /*******************************
   * Parameters for WOTS
   *******************************/
  /* See line 663 in FIPS 205 */
  ws->parameters.wotsLengthCheckSum = 3u;
  /* See line 663 in FIPS 205 */
  ws->parameters.wotsLengthMessageDigest = (actU8)(2u * ws->parameters.mainParameter);
  /* WOTS length = message length (base w) + csum length */
  ws->parameters.wotsLength = (actU8)((ws->parameters.wotsLengthMessageDigest) + (ws->parameters.wotsLengthCheckSum));
  /* Nbr chains (wotsLength) * mainParameter */
  ws->parameters.wotsRootsLength = (actU16)((actU16)ws->parameters.wotsLength * (actU16)ws->parameters.mainParameter);

  /*******************************
   * Parameters for XMSS
   *******************************/
  /* XMSS signature = [WOTS SIG || XMSS PATH], where length of WOTS signature = length of WOTS roots  */
  ws->parameters.getWotsSig = 0u;                             /* Caution: Use only if a XMSS signature is given! */
  ws->parameters.getXmssAuthPath = (ws->parameters.wotsRootsLength);  /* Caution: Use only if a XMSS signature is given! */

  /*******************************
   * Parameters for Hyper Tree
   *******************************/
  /* HT signature = [XMSS SIG || ... || XMSS SIG] and
   * XMSS signature = [WOTS SIG || XMSS PATH] where XMSS path = (mainParameter * xmssTreeHeight) */
  ws->parameters.getXmssSigAtIdx = (actU16)(ws->parameters.wotsRootsLength + (actU16)((actU16)ws->parameters.mainParameter * (actU16)ws->parameters.xmssTreeHeight)); /* Caution: Use only if an HT signature is given! */

  /*******************************
   * Parameters for FORS
   *******************************/
  /* Nbr of leafs in one FORS tree = 2^forsTreeHeight */
  ws->parameters.forsNbrLeafs = (actU16)(((actU16) 1u) << ws->parameters.forsTreeHeight);
  /* FORS one tree signature = [SK || AUTH PATH] */
  ws->parameters.getForsTreeSK = 0u;                    /* Caution: Use only if a FORS One Tree signature is given! */
  ws->parameters.getForsTreeAuthPath = ws->parameters.mainParameter;   /* Caution: Use only if a FORS One Tree signature is given! */
  /* Length of FORS one tree signature: Length of FORS SK + Length of AUTH PATH */
  ws->parameters.getForsTreeSigAtIdx = (actU16)((actU16)ws->parameters.mainParameter + ((actU16)ws->parameters.mainParameter * (actU16)ws->parameters.forsTreeHeight)); /* Caution: Use only if a FORS signature is given! */

  /*******************************
   * Parameters for Verification
   *******************************/
  /* Length of tree index in bits: Nbr of leafs in Hypertree - Nbr of bits needed for the first XMSS tree (leaf idx).
   * See line 11 or 14 in algorithm 19 in FIPS 205. */
  ws->parameters.treeIdxLengthInBits = (actU8)((ws->parameters.hyperTreeNbrLayers * ws->parameters.xmssTreeHeight) - ws->parameters.xmssTreeHeight);
  /* Length of message digest in bytes corresponds to the index of the treeIdx in the digest since
   *  digest = [messageDigest || treeIdx || leafIdx]
   * See line 10 and 11 in algorithm 19 in FIPS 205 */
  ws->parameters.getTreeIdx = (actU16)(BITS_TO_BYTES((actU16)((actU16)ws->parameters.forsNbrTrees * (actU16)ws->parameters.forsTreeHeight)));
  /* Nbr of bytes we use to extract treeIdx.
   * See line 11 in algorithm 19 in FIPS 205 */
  ws->parameters.treeIdxLength = (actU8)(BITS_TO_BYTES(ws->parameters.treeIdxLengthInBits));
  /* Length of leaf index in bits: Nbr of bits needed for the first XMSS tree.
   * See line 12 or 15 in algorithm 19 in FIPS 205 */
  ws->parameters.leafIdxLengthInBits = ws->parameters.xmssTreeHeight;
  /* Length of message digest and tree idx in bytes corresponds to the index of the leafIdx in the digest since
   * digest = [messageDigest || treeIdx || leafIdx]
   * See line 12 in algorithm 19 in FIPS 205 */
  ws->parameters.getLeafIdx = (actU16)((ws->parameters.getTreeIdx) + (ws->parameters.treeIdxLength));
  /* Nbr of bytes we use to extract leafIdx.
   * See line 12 in algorithm 19 in FIPS 205 */
  ws->parameters.leafIdxLength = (actU8)(BITS_TO_BYTES(ws->parameters.leafIdxLengthInBits));
  /* SLH-DSA Signature = [Randomizer || FORS sig || HT sig] where length of Randomizer is mainParameter */
  ws->parameters.getForsSignature = ws->parameters.mainParameter;
  /* SLH-DSA signature = [Randomizer || FORS sig || HT sig] where length of
   * - Randomizer is mainParameter
   * - FORS sig is length of FORS one tree signature times nbr of FORS trees */
  ws->parameters.getHyperTreeSignature = (actU16)(ws->parameters.mainParameter + ((ws->parameters.getForsTreeSigAtIdx) * ws->parameters.forsNbrTrees));
  ws->parameters.getPKSeed = 0u;        /* PK = [PK Seed || PK root] */
  ws->parameters.getPKRoot = ws->parameters.mainParameter; /* PK = [PK Seed || PK root] */
}

# endif /* defined ACT_PLATFORM_UINT64_AVAILABLE */

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VSECPRIM_ACTSLHDSA_UTILITIES_ENABLED == STD_ON */

/**********************************************************************************************************************
 *  END OF FILE: actSLHDSA_Utilities.c
 *********************************************************************************************************************/
