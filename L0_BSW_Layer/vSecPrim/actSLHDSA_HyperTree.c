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
/*!       \file  actSLHDSA_HyperTree.c
 *        \unit  act_SLHDSAHyperTree
 *       \brief  SLH-DSA HyperTree algorithms for version:
 *                 - 128S
 *
 *      \details This file is part of the embedded systems library cvActLib.
 *               Implements the HyperTree functions for version:
 *                - 128S
 *               of section 7.2 in NIST FIPS-205 (draft) from august 2023:
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

#define ACTSLHDSA_HYPERTREE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "actSLHDSA_HyperTree.h"
#include "actSLHDSA_XMSS.h"

#include "actSLHDSA_Utilities.h"
#include "actSLHDSA_Types.h"
#include "actUtilities.h"

#if (VSECPRIM_ACTSLHDSA_HYPERTREE_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if defined ACT_PLATFORM_UINT64_AVAILABLE

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actSLHDSAHyperTreeVerify()
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
 */
VSECPRIM_FUNC(actRETURNCODE) actSLHDSAHyperTreeVerify(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2CONST_PARA(actU8) forsPublicKey,
  VSECPRIM_P2CONST_PARA(actU8) hyperTreeSignature,
  VSECPRIM_P2VAR_PARA(actU64) treeIdx,
  VSECPRIM_P2VAR_PARA(actU16) leafIdx,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /* set variables */
  actRETURNCODE retVal = actVERIFICATION_FAILED;

  VSECPRIM_P2CONST_PARA(actU8) tempXMSSSignature = NULL_PTR;
  actU16 totalAmoutLeafNodes = (actU16)(((actU16) (1u)) << (ws->parameters.xmssTreeHeight)); /* = 2^9, actU16 is enough */

  actU8 xmssPublicKey[actSLHDSA_MAIN_PARAMETER_MAX] = {0u};
  actU8 adrs[actSLHDSA_ADRS32_LENGTH] = {0u}; /* is used to navigate through the hypertree structure */

  actSetTreeAdrs(adrs, *treeIdx);
  tempXMSSSignature = &hyperTreeSignature[ws->parameters.getXmssSigAtIdx * 0u]; /* get the first XMSS signature */
  actSLHDSAXmssPublicKeyFromSig(ws, xmssPublicKey, *leafIdx, tempXMSSSignature, forsPublicKey, adrs, watchdog);

  /* go from the lowest layer to upper HT-layers */
  for(uint8 j = 1u; j < (ws->parameters.hyperTreeNbrLayers); j++)
  {
    /* leafIdx = treeIdx mod 2^xmssHeight = treeIdx mod totalAmoutLeafNodes */
    *leafIdx = (actU16)((actU16) *treeIdx & ((totalAmoutLeafNodes - (actU16) 1u)));

    /* remove least significant xmssHeight bits from treeIdx */
    *treeIdx = (*treeIdx >> ws->parameters.xmssTreeHeight);
    actSetLayerAdrs(adrs, j);
    actSetTreeAdrs(adrs, *treeIdx);
    tempXMSSSignature = &hyperTreeSignature[ws->parameters.getXmssSigAtIdx * j]; /* gives signature no. j + 1 */
    actSLHDSAXmssPublicKeyFromSig(ws, xmssPublicKey, *leafIdx,
                                      tempXMSSSignature, xmssPublicKey, adrs, watchdog);
  }

  /* The XMSS public key for the last layer has been computed.
   * Verification is successful, if this node is equal to pkRoot */

  if (actMemcmp(xmssPublicKey, ws->pkRoot, ws->parameters.mainParameter) == TRUE)
  {
    retVal = actOK;
  }

  return retVal;
}

# endif /* defined ACT_PLATFORM_UINT64_AVAILABLE */

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VSECPRIM_ACTSLHDSA_HYPERTREE_ENABLED == STD_ON */

/**********************************************************************************************************************
 *  END OF FILE: actSLHDSA_HyperTree.c
 *********************************************************************************************************************/
