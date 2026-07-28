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
/*!       \file  actSLHDSA_WOTS.c
 *        \unit  act_SLHDSAWots
 *       \brief  SLH-DSA WOTS+ algorithms
 *
 *      \details This file is part of the embedded systems library cvActLib.
 *               Implements the WOTS+ algorithms for version:
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

#define ACTSLHDSA_WOTS_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "actSLHDSA_WOTS.h"
#include "actSLHDSA_BuildingFct.h"

#include "actSLHDSA_Utilities.h"
#include "actSLHDSA_Types.h"
#include "actUtilities.h"

#if (VSECPRIM_ACTSLHDSA_WOTS_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if defined ACT_PLATFORM_UINT64_AVAILABLE

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actSLHDSAChain()
 *********************************************************************************************************************/
/*! \brief          The function actSLHDSAChain computes a section of a WOTS+ chain.
 *  \details        -
 *  \param[in]      ws           Pointer to workspace with parameters for SLH-DSA and a pointer
 *  \param[in,out]  node         (in)  Pointer to start node.
 *                               (out) Pointer to output data, last computed digest of the chain section.
 *  \param[in]      startIndex   Position in the chain where to start.
 *  \param[in]      nbrOfSteps   Number of steps to proceed in the chain, length of the section.
 *  \param[in,out]  adrs         (in) pointer to an ADRS with 32 bytes of type WOTS_HASH.
 *                               (out) pointer to an ADRS with new hash address.
 *  \param[in]      watchdog     Pointer to the watchdog trigger function
 *  \pre            - Provided pointers must be valid.
 *                  - startIndex + nbrOfSteps < actSLHDSA_WINTERNITZ_PARAMETER = 16u, since the Winternitz parameter
 *                    is the length of a WOTS+ chain.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSLHDSAChain(
  VSECPRIM_P2CONST_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2VAR_PARA(actU8) node,
  actU8 startIndex,
  actU8 nbrOfSteps,
  VSECPRIM_P2VAR_PARA(actU8) adrs,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actSLHDSAChain()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(void) actSLHDSAChain(
  VSECPRIM_P2CONST_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2VAR_PARA(actU8) node,
  actU8 startIndex,
  actU8 nbrOfSteps,
  VSECPRIM_P2VAR_PARA(actU8) adrs,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /* Chain section */
  for (actU8 idx = startIndex; idx < (startIndex + nbrOfSteps); idx++)
  {
    actSetHashAdrs(adrs, idx);
    actSLHDSAHash(ws, node, adrs, node, ws->parameters.mainParameter, watchdog);
  }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actSLHDSAWotsPublicKeyFromSig()
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
VSECPRIM_FUNC(void) actSLHDSAWotsPublicKeyFromSig(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2VAR_PARA(actU8) wotsPkFromSig,
  VSECPRIM_P2CONST_PARA(actU8) wotsSignature,
  VSECPRIM_P2CONST_PARA(actU8) signedMessage,
  VSECPRIM_P2VAR_PARA(actU8) adrs,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /* Scope: adrs setting and Hash initialization */
  {
    actU8 wotsPkAdrs[actSLHDSA_ADRS32_LENGTH] = {0u};

    /* Create new address for the WOTS roots hashing process.
     * This is done in FIPS 205 at the end of algorithm 7, but can be done at the beginning since the relevant
     * informations (layer address and tree address) are not changed. */
    actMemCpyByteArray(wotsPkAdrs, adrs, actSLHDSA_ADRS32_LENGTH);
    actSetTypeAndClear(wotsPkAdrs, actSLHDSA_ADRS_TYPE_WOTS_PK);
    actCopyKeyPairAdrs(wotsPkAdrs, adrs);

    /* Initialize the hash computation of the roots of the WOTS+ chains */
    actSLHDSAInitHashT(ws, wotsPkAdrs, watchdog);
  }

  /* Scope: csum initialization and WOTS computation */
  {
    actU16 csum = 0u;
    actU8 signedDataBaseW[actSLHDSA_WOTS_LEN_MAX] = {0u};
    actU8 csumArray[actSLHDSA_CSUM_BYTE_LENGTH] = {0u};

    /*
     * Copy the signed message in base w into the len1 (wotsLengthMessageDigest) first bytes of signedDataBaseW.
     * Preconditions are fulfilled:
     *     - ceil((wotsLengthMessageDigest / 2) = 16 which is the length of signedMessage.
     */
    actBEU8toBEU4(signedDataBaseW, ws->parameters.wotsLengthMessageDigest, signedMessage);

    /* Compute checksum */
    for (actU8 idx = 0u; idx < ws->parameters.wotsLengthMessageDigest; idx++)
    {
      csum = (actU16)(csum + ((actU16)actSLHDSA_WINTERNITZ_PARAMETER) - ((actU16)1u) - ((actU16)signedDataBaseW[idx]));
    }

    /*
     * Encode csum to compensate the fact that the last bits of csum in the next call of actBEU8toBEU4()
     * are not handled.
     * lgw = 4, hence we only need to shift by 4 (see comment at the right of line 9 in algo 7).
     * Note: The maximum of csum at this point is (actSLHDSA_WINTERNITZ_PARAMETER - 1u) * wotsLengthMessageDigest = 480.
     *       A shift by 4 cannot produce an overflow since csum is of type actU16
     */
    csum = (actU16)(csum << 4u);

    /* Convert csum in a BE byte array */
    actU16toBE(csumArray, csum);

    /*
     * Copy the checksum in base w into the len2 (wotsLengthCheckSum) last bytes of signedDataBaseW.
     * Preconditions are fulfilled:
     *     - ceil((wotsLengthCheckSum / 2) = 2 which is the length of csumArray.
     */
    actBEU8toBEU4(&signedDataBaseW[ws->parameters.wotsLengthMessageDigest],
                                                      ws->parameters.wotsLengthCheckSum, csumArray);

    /* Compute the roots of all the chains */
    for (actU8 idx = 0u; idx < ws->parameters.wotsLength; idx++)
    {
      actU8 node[actSLHDSA_MAIN_PARAMETER_MAX] = {0u};
      actU8 nbrSteps = (actU8)(actSLHDSA_WINTERNITZ_PARAMETER - 1u - signedDataBaseW[idx]);

      actSetChainAdrs(adrs, idx);

      /* Get the WOTS+ signature of chain idx */
      actMemCpyByteArray(node, &wotsSignature[ws->parameters.getNodeAtIdx * idx], ws->parameters.mainParameter);

      /* Get the root of the WOTS+ chain idx */
      actSLHDSAChain(ws, node, signedDataBaseW[idx], nbrSteps, adrs, watchdog);

      /* Update the hash computation of the roots of the WOTS+ chains */
      actSLHDSAUpdateHashT(ws, node, watchdog);
    }
    /* Finalize the hash computation of the roots of the FORS trees */
    actSLHDSAFinalizeHashT(ws, wotsPkFromSig, watchdog);
  }
}

# endif /* defined ACT_PLATFORM_UINT64_AVAILABLE */

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VSECPRIM_ACTSLHDSA_WOTS_ENABLED == STD_ON */

/**********************************************************************************************************************
 *  END OF FILE: actSLHDSA_WOTS.c
 *********************************************************************************************************************/
