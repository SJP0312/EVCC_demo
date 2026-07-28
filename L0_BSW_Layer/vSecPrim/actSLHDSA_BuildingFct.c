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
/*!       \file  actSLHDSA_BuildingFct.c
 *        \unit  act_SLHDSABuildingFct
 *       \brief  SLH-DSA building functions
 *
 *      \details This file is part of the embedded systems library cvActLib.
 *               Implements the building functions for version:
 *                - 128S
 *               of section 4.1, 10.1 and 10.2 in NIST FIPS-205 (draft) from august 2023:
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

#define ACTSLHDSABUILDINGFCT_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "actSLHDSA_BuildingFct.h"
#include "actISHA2_32.h"
#include "actIHashMACSHA256.h"

#include "actSLHDSA_Utilities.h"
#include "actSLHDSA_Types.h"
#include "actUtilities.h"

#if (VSECPRIM_SLHDSA_SHA256_128_S_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */
# define VSECPRIM_WRAPPER_SHA256
#endif

#if (VSECPRIM_ACTSLHDSA_BUILDINGFCT_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

typedef actWorkSpaceUnionHashFunctions_SLHDSA actWorkSpaceUnionHashFunctions; /*lint !e452 */
# include "actHashFctWrappers_Implementation.h" /* PRQA S 5087 */ /* MD_VSECPRIM_19.1 */

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if defined ACT_PLATFORM_UINT64_AVAILABLE

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actSLHDSAGenerateMaskMGF1()
 *********************************************************************************************************************/
/*! \brief         Simplified implementation of mask generation function (MGF1) for SLH-DSA
 *  \details       Simplified MGF1 implementation as described in appendix B.2.1 of PKCS#1 2.2.
 *                 Based on selected hash function, this function generates a pseudorandom output string of
 *                 arbitrary length depending on an input string (seed) of variable length
 *  \param[in,out] ws              (in)  Pointer to SLH DSA workspace, containing the corresponding hash workspace
 *                                 (out) Pointer to SLH DSA workspace, containing the corresponding hash workspace
 *  \param[in,out] tempHash        (in)  Temporary buffer for intermediate hash
 *                                 (out) intermediate hash value
 *  \param[in]     seedLength      Length input seed
 *  \param[in]     seed            Input seed from which mask is generated
 *  \param[in,out] mask            (in)  Output buffer for generated mask
 *                                 (out) generated  mask
 *  \param[in]     watchdog        Pointer to the watchdog trigger function
 *  \pre           - ws, tempHash, seed and mask have to be valid pointers
 *                 - buffer referenced by tempHash has to be at least ws->parameters.hashSize.
 *                 - buffer referenced by mask has to be at least of length ws->parameters.digestLength.
 *  \context       TASK
 *  \reentrant     TRUE, for different workspaces
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(void) actSLHDSAGenerateMaskMGF1(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2VAR_PARA(actU8) tempHash,
  actLengthType seedLength,
  VSECPRIM_P2CONST_PARA(actU8) seed,
  VSECPRIM_P2VAR_PARA(actU8) mask,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actSLHDSAGenerateMaskMGF1()
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
VSECPRIM_LOCAL_FUNC(void) actSLHDSAGenerateMaskMGF1(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2VAR_PARA(actU8) tempHash,
  actLengthType seedLength,
  VSECPRIM_P2CONST_PARA(actU8) seed,
  VSECPRIM_P2VAR_PARA(actU8) mask,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actU32 counter;
  actU8 octetCounter[4u];
  actLengthType digestNumber;
  actLengthType remainingLength;
  actLengthType offset;
  actLengthType passLength;
  actLengthType i;

  /* B.2.1, Step 3: Initialize counter value */
  counter = 0u;
  offset = 0u;
  digestNumber = (actLengthType)(((actLengthType)ws->parameters.digestLength + (actLengthType)ws->parameters.hashSize - (actLengthType)1u) / (actLengthType)ws->parameters.hashSize);
  remainingLength = ws->parameters.digestLength;

  /* B.2.1, Step 3: Generate requested length */
  /* Upper boundary for digestNumber is calculated from maskLength and hashDigitSize
     The upper boundary of mask length is specified as UINT32_MAX
     The upper boundary of hashDigitSize is the length of the output of the chosen hash function
     Note: the function actHashInit, actHashUpdate and actHashFinalize are voided since the algo ID is checked before. */
  for (i = 0u; i < digestNumber; i++) /* FETA_VSECPRIM_BOUNDARY_CHECK_BY_CALLER_PARAMETER */
  {
    /* Initialize hash calculation */
    (void) actHashInit(&(ws->wsHash), ws->parameters.hashID); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
    /* B.2.1, Step 3b: Hash given seed value */
    (void) actHashUpdate(&(ws->wsHash), seed, seedLength, ws->parameters.hashID, watchdog); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
    /* B.2.1, Step 3a: Convert counter value to big-endian octet string */
    actU32toBE(octetCounter, counter); /* SBSW_VSECPRIM_FCT_CALL_LOCAL_BUFFER */
    /* B.2.1, Step 3b: Hash octet string of counter */
    (void) actHashUpdate(&(ws->wsHash), octetCounter, sizeof(octetCounter),  ws->parameters.hashID, watchdog); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
    /* Finalize hash calculation */
    (void) actHashFinalize(&(ws->wsHash), tempHash,  ws->parameters.hashID, watchdog); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
    /* B.2.1, Step 4: Limit length in this pass, when end of buffer is reached */
    passLength = ws->parameters.hashSize;
    if (passLength > remainingLength)
    {
      passLength = remainingLength;
    }

    /* B.2.1, Steps 3-4: Concatenate (truncated) hash to output */
    actMemCpyByteArray(&mask[offset], tempHash, passLength); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_FIXED_SUBADDRESS */

    /* B.2.1, Step 3: Update counter */
    counter++;
    offset = (actLengthType)(offset + passLength);
    remainingLength = (actLengthType)(remainingLength - passLength);
  }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actSLHDSAinitHashMessage()
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
VSECPRIM_FUNC(void) actSLHDSAinitHashMessage(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2CONST_PARA(actU8) randomizer,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  (void)actHashInit(&(ws->wsHash), ws->parameters.hashID);
  (void)actHashUpdate(&(ws->wsHash), randomizer, ws->parameters.mainParameter, ws->parameters.hashID, watchdog);
  (void)actHashUpdate(&(ws->wsHash), ws->pkSeed, ws->parameters.mainParameter, ws->parameters.hashID, watchdog);
  (void)actHashUpdate(&(ws->wsHash), ws->pkRoot, ws->parameters.mainParameter, ws->parameters.hashID, watchdog);
}
/**********************************************************************************************************************
 *  actSLHDSAupdateHashMessage()
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
 */
VSECPRIM_FUNC(void) actSLHDSAupdateHashMessage(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2CONST_PARA(actU8) message,
  actLengthType messageLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  (void)actHashUpdate(&(ws->wsHash), message, messageLength, ws->parameters.hashID, watchdog);
}

/**********************************************************************************************************************
 *  actSLHDSAfinalizeHashMessage()
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
 */
VSECPRIM_FUNC(void) actSLHDSAfinalizeHashMessage(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2CONST_PARA(actU8) randomizer,
  VSECPRIM_P2VAR_PARA(actU8) digest,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
#  if (actSLHDSA_SHAKE_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XX */
  /* Case SHAKE */
  if (ws->parameters.hashID == actHA_SHAKE_256)
  {
    /* Compute digest */
    (void)actXOFFinalize(&(ws->wsHash), digest, ws->parameters.hashID,
                                          actBytesToBits(ws->parameters.digestLength), watchdog);
  }
  /* Case SHA2 */
  else
#  endif
  {
    actU8 seed[actSLHDSA_SEED_LENGTH_MAX] = {0u};
    actU8 tempDigest[actSLHDSA_HASH_SIZE_MAX] = {0u};

    /* Seed length = (Randomizer length + pk seed length + hash size) where length of randomizer and pk seed
       is mainParameter */
    actU16 seedLength = (actU16)((actU16)((actU16)2u * ws->parameters.mainParameter) + (actU16)ws->parameters.hashSize);

    /* Finalize SHA2 computation */
    (void)actHashFinalize(&(ws->wsHash), tempDigest, ws->parameters.hashID, watchdog);

    /* seed = (randomizer || pkSeed || hash) */
    actMemCpyByteArray(seed, randomizer, ws->parameters.mainParameter);
    actMemCpyByteArray(&seed[ws->parameters.mainParameter], ws->pkSeed, ws->parameters.mainParameter);
    actMemCpyByteArray(&seed[2u*(ws->parameters.mainParameter)], tempDigest, ws->parameters.hashSize);

    /* Compute digest. The hash workspace in ws can be reused since the precedent hash process was finished */
    actSLHDSAGenerateMaskMGF1(ws, tempDigest, seedLength, seed, digest, watchdog);

  }
}

/**********************************************************************************************************************
 *  actSLHDSAHash()
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
 */
VSECPRIM_FUNC(void) actSLHDSAHash(
  VSECPRIM_P2CONST_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2VAR_PARA(actU8) hashDigestTrunc,
  VSECPRIM_P2CONST_PARA(actU8) adrs,
  VSECPRIM_P2CONST_PARA(actU8) data,
  actU16 dataLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /*** local variables ***/
  /* We cannot use the hash workspace from ws, since it is already used by another
   * hashing process in WOTS+ and FORS */
  actWorkSpaceUnionHashFunctions_SLHDSA wsHashLocal = {0u}; /* PRQA S 0759 */ /* MD_MSR_Union */
  actU8 hashDigest[actSLHDSA_HASH_SIZE_MAX] = {0u};
  const actU8 padding[actSLHDSA_HASH_PADDING_LENGTH_MAX] = {0u};
  actU8 adrsToHash[actSLHDSA_ADRS32_LENGTH] = {0u};

  /* Set variables for the case SHA2-256 */
  actU8 adrsLength = actSLHDSA_ADRS22_LENGTH;
  actU8 paddingLength = (actU8)((actU8)64u - (ws->parameters.mainParameter));
  actU8 hashID = ws->parameters.hashID;

  /*** Prepare variables ***/
  /* Set address and address length */
#  if (actSLHDSA_SHAKE_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XX */
  if ((hashID) == actHA_SHAKE_256)
  {
    adrsLength = actSLHDSA_ADRS32_LENGTH;
    actMemCpyByteArray(adrsToHash, adrs, adrsLength);
  }
  else
#  endif
  {
    actCompressAdrs(adrsToHash, adrs);
    /* adrsLength already set: adrsLength = actSLHDSA_ADRS22_LENGTH */
  }

#  if (actSLHDSA_SHA2_512_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XX */
  /* Set hash identifier:
     There is a special case for F (dataLength == mainParameter) and SHA2-512.
     In this case, we use SHA2-256, see section 10.3 in FIPS 205. */
  if (((hashID) == actHA_SHA2_512) && (dataLength == (ws->parameters.mainParameter)))
  {
    hashID = actHA_SHA2_256;
  }
  else
#  endif
  {
    /* hashID already set: hashID = ws->hashID */
  }

#  if ((actSLHDSA_SHAKE_ENABLED == STD_ON) || (actSLHDSA_SHA2_512_ENABLED == STD_ON))  /* COV_VSECPRIM_NO_SAFE_CONFIG XX xx xx */
  /* Set padding length (see section 10.2 and 10.3 in FIPS205):
     SHAKE: No padding, paddingLength = 0u
     SHA2-256: paddingLength = 64u - mainParameter
     SHA2-512: paddingLength = 128u - mainParameter */
  if (hashID == actHA_SHAKE_256)
  {
    paddingLength = 0u;
  }
  else if (hashID == actHA_SHA2_512)
  {
    paddingLength = 128u - (ws->parameters.mainParameter);
  }
  else /* (hashID == actHA_SHA2_256) */
#  endif
  {
    /* paddingLength already set: paddingLength = 64u - (ws->parameters.mainParameter) */
  }

  /*** Hash the byte array: [ pkSeed || padding || adrsCompressed || data ] ***/
  (void)actHashInit(&(wsHashLocal), hashID);

  (void)actHashUpdate(&(wsHashLocal), ws->pkSeed, ws->parameters.mainParameter, hashID, watchdog);
  (void)actHashUpdate(&(wsHashLocal), padding, paddingLength, hashID, watchdog);
  (void)actHashUpdate(&(wsHashLocal), adrsToHash, adrsLength, hashID, watchdog);
  (void)actHashUpdate(&(wsHashLocal), data, dataLength, hashID, watchdog);

#  if (actSLHDSA_SHAKE_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XX */
  /* Different finalize for SHAKE and SHA2 since SHAKE needs an output length parameter and SHA has a fix
     output length. */
  if (ws->parameters.hashID == actHA_SHAKE_256)
  {
    (void)actXOFFinalize(&(wsHashLocal), hashDigest, hashID,
                                    actBytesToBits(ws->parameters.mainParameter), watchdog);
  }
  else /* case SHA */
#  endif
  {
    (void)actHashFinalize(&(wsHashLocal), hashDigest, hashID, watchdog);
  }

  /*** Truncate the hash digest to "mainParameter" bytes. In case of SHAKE, we simply copy the hashDigest ***/
  actMemCpyByteArray(hashDigestTrunc, hashDigest, ws->parameters.mainParameter);
}

/**********************************************************************************************************************
 *  actSLHDSAInitHashT()
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
VSECPRIM_FUNC(void) actSLHDSAInitHashT(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2CONST_PARA(actU8) adrs,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /*** local variables ***/
  const actU8 padding[actSLHDSA_HASH_PADDING_LENGTH_MAX] = {0u};
  actU8 adrsToHash[actSLHDSA_ADRS32_LENGTH] = {0u};
  actU8 adrsLength = actSLHDSA_ADRS22_LENGTH;
  actU8 paddingLength = (actU8)((actU8)64u - (ws->parameters.mainParameter));

  /*** Prepare variables ***/
  /* Set address and address length */
#  if (actSLHDSA_SHAKE_ENABLED == STD_ON)  /* COV_VSECPRIM_NO_SAFE_CONFIG XX */
  if ((ws->parameters.hashID) == actHA_SHAKE_256)
  {
    adrsLength = actSLHDSA_ADRS32_LENGTH;
    actMemCpyByteArray(adrsToHash, adrs, adrsLength);
  }
  else
#  endif
  {
    actCompressAdrs(adrsToHash, adrs);
    /* adrsLength already set: adrsLength = actSLHDSA_ADRS22_LENGTH */
  }

#  if ((actSLHDSA_SHAKE_ENABLED == STD_ON) || (actSLHDSA_SHA2_512_ENABLED == STD_ON))  /* COV_VSECPRIM_NO_SAFE_CONFIG XX xx xx */
  /* Set padding length (see section 10.2 and 10.3 in FIPS205):
     SHAKE: No padding, paddingLength = 0u
     SHA2-256: paddingLength = 64u - mainParameter
     SHA2-512: paddingLength = 128u - mainParameter */
  if (ws->parameters.hashID == actHA_SHAKE_256)
  {
    paddingLength = 0u;
  }
  else if (ws->parameters.hashID == actHA_SHA2_512)
  {
    paddingLength = 128u - (ws->parameters.mainParameter);
  }
  else /* (ws->parameters.hashID == actHA_SHA2_256) */
#  endif
  {
    /* paddingLength already set: paddingLength = 64u - (ws->parameters.mainParameters->mainParameter) */
  }

  /*** Start to hash: [ pkSeed || padding || adrs] ***/
  (void)actHashInit(&(ws->wsHash), ws->parameters.hashID);

  (void)actHashUpdate(&(ws->wsHash), ws->pkSeed, ws->parameters.mainParameter, ws->parameters.hashID, watchdog);
  (void)actHashUpdate(&(ws->wsHash), padding, paddingLength, ws->parameters.hashID, watchdog);
  (void)actHashUpdate(&(ws->wsHash), adrsToHash, adrsLength, ws->parameters.hashID, watchdog);
}

/**********************************************************************************************************************
 *  actSLHDSAUpdateHashT()
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
VSECPRIM_FUNC(void) actSLHDSAUpdateHashT(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2CONST_PARA(actU8) root,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  (void)actHashUpdate(&(ws->wsHash), root, ws->parameters.mainParameter, ws->parameters.hashID, watchdog);
}

/**********************************************************************************************************************
 *  actSLHDSAFinalizeHashT()
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
VSECPRIM_FUNC(void) actSLHDSAFinalizeHashT(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2VAR_PARA(actU8) hashDigestTrunc,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actU8 hashDigest[actSLHDSA_HASH_SIZE_MAX] = {0u};

#  if (actSLHDSA_SHAKE_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XX */
  /* Different finalize for SHAKE and SHA2 since SHAKE needs an output length parameter and SHA has a fix
     output length. */
  if (ws->parameters.hashID == actHA_SHAKE_256)
  {
    (void)actXOFFinalize(&(ws->wsHash), hashDigest, ws->parameters.hashID,
                                    actBytesToBits(ws->parameters.mainParameter), watchdog);
  }
  else /* case SHA */
#  endif
  {
    (void)actHashFinalize(&(ws->wsHash), hashDigest, ws->parameters.hashID, watchdog);
  }

  /*** Truncate the hash digest to "mainParameter" bytes. In case of SHAKE, we simply copy the hashDigest ***/
  actMemCpyByteArray(hashDigestTrunc, hashDigest, ws->parameters.mainParameter);
}

/**********************************************************************************************************************
 *  actComputeRootInMerkleTreeWithAuthPath()
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
VSECPRIM_INLINE_FUNC(void) actComputeRootInMerkleTreeWithAuthPath(
  VSECPRIM_P2CONST_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2VAR_PARA(actU8) node,
  actU8 treeHeight,
  VSECPRIM_P2CONST_PARA(actU8) leaf,
  actU32 leafIndex,
  VSECPRIM_P2CONST_PARA(actU8) authPath,
  VSECPRIM_P2VAR_PARA(actU8) adrs,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actMemCpyByteArray(node, leaf, ws->parameters.mainParameter);

  for (actU8 idx = 0u; idx < treeHeight; idx++)
  {
    actU8 nodeConcatenation[actSLHDSA_H_INPUT_LENGTH_MAX] = {0u};
    VSECPRIM_P2CONST_PARA(actU8) nodeAuthPath = &authPath[ws->parameters.getNodeAtIdx * idx];

    /* Get the bit of leafIndex at position idx counting from the right.
        If it is 0, then we have a node at the left.
        If it is 1, then we have a node at the right. */
    actU8 nodePosition = (actU8)((leafIndex >> idx) & 1u);

    /* Get the current tree height */
    actSetTreeHeight(adrs, (actU8)(idx + (actU8)1u));

    /* Set the new tree index */
    actSetTreeIndex(adrs, actGetTreeIndex(adrs) >> 1u);
    if (nodePosition == actSLHDSA_FLAG_LEFT)
    {
      /* set nodeConcatenation = node || nodeAuthPath */
      actMemCpyByteArray(nodeConcatenation, node, ws->parameters.mainParameter);
      actMemCpyByteArray(&nodeConcatenation[ws->parameters.mainParameter], nodeAuthPath, ws->parameters.mainParameter);
    }
    else /* nodePosition == RIGHT */
    {
      /* set nodeConcatenation = nodeAuthPath || node */
      actMemCpyByteArray(nodeConcatenation, nodeAuthPath, ws->parameters.mainParameter);
      actMemCpyByteArray(&nodeConcatenation[ws->parameters.mainParameter], node, ws->parameters.mainParameter);
    }
    /* Compute newNode */
    actSLHDSAHash(ws, node, adrs, nodeConcatenation, ws->parameters.hInputLength, watchdog);
  }
}

# endif /* defined ACT_PLATFORM_UINT64_AVAILABLE */

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* ACTSLHDSA_BUILDINGFCT_ENABLED == STD_ON */

/**********************************************************************************************************************
 *  END OF FILE: actSLHDSA_BuildingFct.c
 *********************************************************************************************************************/
