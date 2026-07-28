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
/*!       \file  actSLHDSA_XMSS.c
 *        \unit  act_SLHDSAXmss
 *       \brief  SLH-DSA XMSS algorithms for version:
 *                 - 128S
 *
 *      \details This file is part of the embedded systems library cvActLib.
 *               Implements the XMSS algorithms for version:
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

#define ACTSLHDSA_XMSS_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "actSLHDSA_XMSS.h"
#include "actSLHDSA_WOTS.h"
#include "actSLHDSA_BuildingFct.h"

#include "actSLHDSA_Utilities.h"
#include "actSLHDSA_Types.h"
#include "actUtilities.h"

#if (VSECPRIM_ACTSLHDSA_XMSS_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if defined ACT_PLATFORM_UINT64_AVAILABLE

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actSLHDSAXmssPublicKeyFromSig()
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
VSECPRIM_FUNC(void) actSLHDSAXmssPublicKeyFromSig(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2VAR_PARA(actU8) xmssPkFromSig,
  actU16 treeIndex,
  VSECPRIM_P2CONST_PARA(actU8) xmssSignature,
  VSECPRIM_P2CONST_PARA(actU8) signedMessage,
  VSECPRIM_P2VAR_PARA(actU8) adrs,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actU8 leaf[actSLHDSA_MAIN_PARAMETER_MAX] = {0u};

  /* Get the WOTS signature and the authentication path of the XMSS Merkle tree from the XMSS signature */
  VSECPRIM_P2CONST_PARA(actU8) wotsSig = &xmssSignature[ws->parameters.getWotsSig];
  VSECPRIM_P2CONST_PARA(actU8) authPath = &xmssSignature[ws->parameters.getXmssAuthPath];

  /* Set the adrs for WOTS hashing */
  actSetTypeAndClear(adrs, actSLHDSA_ADRS_TYPE_WOTS_HASH);
  actSetKeyPairAdrs(adrs, treeIndex);

  /* Compute the WOTS public key from the message and the WOTS signature.
     This is the leaf of the XMSS Merkle tree. */
  actSLHDSAWotsPublicKeyFromSig(ws, leaf, wotsSig, signedMessage, adrs, watchdog);

  /* Set adrs for an XMSS Merkle tree root computation */
  actSetTypeAndClear(adrs, actSLHDSA_ADRS_TYPE_TREE);
  actSetTreeIndex(adrs, treeIndex);

  /* Compute the root of the XMSS Merkle tree */
  actComputeRootInMerkleTreeWithAuthPath(ws, xmssPkFromSig, ws->parameters.xmssTreeHeight,
                                                                    leaf, treeIndex, authPath, adrs, watchdog);
}

# endif /* defined ACT_PLATFORM_UINT64_AVAILABLE */

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VSECPRIM_ACTSLHDSA_XMSS_ENABLED == STD_ON */

/**********************************************************************************************************************
 *  END OF FILE: actSLHDSA_XMSS.c
 *********************************************************************************************************************/
