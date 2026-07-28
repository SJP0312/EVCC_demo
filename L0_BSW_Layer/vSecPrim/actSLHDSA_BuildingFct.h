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
/*!        \file  actSLHDSA_BuildingFct.h
 *        \brief  SLH-DSA building functions for version:
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

#ifndef ACTSLHDSA_BUILDINGFCT_H
# define ACTSLHDSA_BUILDINGFCT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "actITypes.h"
# include "actConfig.h"
# include "actSLHDSA_Utilities.h"

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
 *  actSLHDSAinitHashMessage()
 *********************************************************************************************************************/
/*! \brief          Start of building function H_msg in section 10.1, 10.2 and 10.3 of FIPS 205.
 *  \details        This function is part of the initialisation and update process.
 *                  - initialises workspace
 *                  - updates the hash with:
 *                         - randomizer
 *                         - pkSeed
 *                         - pkRoot
 *  \param[in,out]  ws              (in)  Pointer to workspace
 *                                  (out) Initialized workspace
 *  \param[in]      randomizer      Generated during signature generation
 *  \param[in]      watchdog        Pointer to the watchdog trigger function
 *  \pre            - Provided pointers must be valid.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSLHDSAinitHashMessage(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2CONST_PARA(actU8) randomizer,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSLHDSAupdateHashMessage()
 *********************************************************************************************************************/
/*! \brief          Update of building function H_msg in section 10.1, 10.2 and 10.3 of FIPS 205.
 *  \details        This function is part of the update process:
 *                  - updates the hash with:
 *                         - message
 *                  This function can be called arbitrarily often between an initialize and finalize of the
 *                  hash algorithm.
 *                  Uses any data already in the structure and leaves any partial data block there.
 *  \param[in,out]  ws              (in)  Pointer to workspace
 *                                  (out) Actualized workspace
 *  \param[in]      message         Pointer to message
 *  \param[in]      messageLength   Length of the message
 *  \param[in]      watchdog        Pointer to the watchdog trigger function
 *  \pre            - Provided pointers must be valid.
 *                  - actSLHDSAinitHashMessage() has been called before calling this function.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSLHDSAupdateHashMessage(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2CONST_PARA(actU8) message,
  actLengthType messageLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSLHDSAfinalizeHashMessage()
 *********************************************************************************************************************/
/*! \brief          Finalize building function H_msg in section 10.1, 10.2 and 10.3 of FIPS 205.
 *  \details        This function is part of the finalize process:
 *                  - SHAKE case:
 *                    - SHAKE is an XOF function, only proceed the finalize step with correct length output.
 *                  - SHA2 case:
 *                    - finalizes the hash of (randomizer||pkSeed||pkRoot|| message)
 *                    - SHA2 has no extendable length output. The mask function MGF1 with seed
 *                         (randomizer || pkSeed || hash)
 *                      is used.
 *  \param[in,out]  ws              (in)  Pointer to workspace
 *                                  (out) Finalized workspace
 *  \param[in]      randomizer      Pointer to randomizer
 *  \param[in,out]  digest          Buffer for the mask to be generated
 *  \param[in]      watchdog        Pointer to the watchdog trigger function
 *  \pre            - Provided pointers must be valid.
 *                  - actSLHDSAinitHashMessage() has been called before calling this function.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSLHDSAfinalizeHashMessage(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2CONST_PARA(actU8) randomizer,
  VSECPRIM_P2VAR_PARA(actU8) digest,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSLHDSAHash()
 *********************************************************************************************************************/
/*! \brief       Implementation of building functions F, H, T_ell and PRF in section 10.2 of FIPS 205 for version 128S.
 *  \details     This function can be used for the computation of:
 *                # nodes in WOTS+ chains.
 *                  In this case, it corresponds to the function F and the variable data is another hash digest.
 *                # nodes in FORS Merkle trees or XMSS Merkle trees.
 *                  In this case, it corresponds to the function H and the variable data is the concatenation of two
 *                  hash digest.
 *                # small "public keys" for WOTS+ and FORS.
 *                  In this case, it corresponds to the function T_ell and the variable data is
 *                   - the concatenation of the end of the WOTS+ chains (ell = len) or
 *                   - the concatenation of the root of FORS trees (ell = k).
 *                # the secret key in FORS and the secret key of each WOTS+ chain.
 *                  In this case, it corresponds to the function PRF and the variable data is the secret seed.
 *               The function actSLHDSAHash() corresponds to:
 *                - F or PRF      if dataLength =actSLHDSA_actSLHDSA_MAIN_PARAMETER_128S
 *                - H             if dataLength =actSLHDSA_MAIN_PARAMETER_128S * 2
 *                - T_ell         if dataLength = actSLHDSA_MAIN_PARAMETER_128S * ell
 *               and always hashes the byte array
 *                - [ pkSeed || (64 - actSLHDSA_MAIN_PARAMETER_128S) zeros || adrsCompressed || data ].
 *               NOTE: ell can take the value k or len, which are respectively 14 and 35 for version 128S.
 *  \param[in]        ws               Pointer to workspace with parameters for SLH-DSA and a pointer
 *  \param[in,out]    hashDigestTrunc  (in)  Pointer to byte array.
 *                                     (out) Pointer to byte array with the first actSLHDSA_MAIN_PARAMETER_128S bytes of
 *                                           the hash digest.
 *  \param[in]        adrs             Pointer to standard ADRS.
 *  \param[in]        data             Pointer to data to hash (see "details" for a description of data).
 *  \param[in]        dataLength       Length of data.
 *  \param[in]        watchdog         pointer to the watchdog function
 *  \pre         - Pointers must be valid.
 *               - adrs must have length 32.
 *  \context     TASK
 *  \reentrant   TRUE, for different workspaces
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSLHDSAHash(
  VSECPRIM_P2CONST_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2VAR_PARA(actU8) hashDigestTrunc,
  VSECPRIM_P2CONST_PARA(actU8) adrs,
  VSECPRIM_P2CONST_PARA(actU8) data,
  actU16 dataLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSLHDSAInitHashT()
 *********************************************************************************************************************/
/*! \brief       Initialization of building function T_ell in section 10.1, 10.2 and 10.3 of FIPS 205.
 *  \details     This function is used for the computation of small "public keys" for WOTS+ and FORS.
 *               Steps:
 *               - Prepare variables
 *               - Initialize the underlying hash function
 *               - Call actHashUpdate with [ pkSeed || padding || adrs ]
 *  \param[in,out]    ws               Pointer to workspace with parameters for SLH-DSA and a pointer
 *  \param[in]        adrs             Pointer to standard ADRS.
 *  \param[in]        watchdog         pointer to the watchdog function
 *  \pre         - Pointers must be valid.
 *               - adrs must have length 32.
 *  \context     TASK
 *  \reentrant   TRUE, for different workspaces
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSLHDSAInitHashT(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2CONST_PARA(actU8) adrs,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSLHDSAUpdateHashT()
 *********************************************************************************************************************/
/*! \brief       Update of building function T_ell in section 10.1, 10.2 and 10.3 of FIPS 205.
 *  \details     This function is used for the computation of small "public keys" for WOTS+ and FORS.
 *               Steps:
 *               - Call actHashUpdate with [ root ]
 *  \param[in,out]    ws               Pointer to workspace with parameters for SLH-DSA and a pointer
 *  \param[in]        root             Pointer the root of one tree in FORS or one chain in WOTS+.
 *  \param[in]        watchdog         pointer to the watchdog function
 *  \pre         - Pointers must be valid.
 *  \context     TASK
 *  \reentrant   TRUE, for different workspaces
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSLHDSAUpdateHashT(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2CONST_PARA(actU8) root,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSLHDSAFinalizeHashT()
 *********************************************************************************************************************/
/*! \brief       Finalize building function T_ell in section 10.1, 10.2 and 10.3 of FIPS 205.
 *  \details     This function is used for the computation of small "public keys" for WOTS+ and FORS.
 *               Steps:
 *               - Call actHashFinalize if the hash function is set to SHA2
 *                      actXOFFinalize if the hash function is set to SHAKE
 *               - Truncate the hash
 *  \param[in,out]  ws                 (in)  Pointer to workspace.
 *                                     (out) Pointer to workspace.
 *  \param[in,out]    hashDigestTrunc  (in)  Pointer for the output buffer.
 *                                     (out) Pointer to the truncated digest.
 *  \param[in]        watchdog         pointer to the watchdog function
 *  \pre         - Pointers must be valid.
 *  \context     TASK
 *  \reentrant   TRUE, for different workspaces
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSLHDSAFinalizeHashT(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2VAR_PARA(actU8) hashDigestTrunc,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actComputeRootInMerkleTreeWithAuthPath()
 *********************************************************************************************************************/
/*! \brief       This function computes the root of a Merkle tree given a leaf and an authentication path.
 *  \details     The root is written in the variable node at the end of the operation.
 *               Steps:
 *               - Set the tree height in the address
 *               - Check if we have a left or a right node
 *               - Set the new tree index
 *               - Depending on the node position:
 *                  - left node  --> hash  [          node || authPath[idx] ]
 *                  - right node --> hash  [ authPath[idx] || node          ]
 *               - At the end of the for-loop, the value of root is saved in node.
 *               NOTE: This function can be used in an XMSS and a FORS Merkle tree during verification since we
 *                     need an authentication path.
 *  \param[in]        ws               Pointer to workspace with parameters for SLH-DSA and a pointer
 *  \param[in,out]    node             (in)  Pointer to byte array.
 *                                     (out) Pointer to byte array with the first actSLHDSA_MAIN_PARAMETER_128S bytes of
 *                                           the hash digest.
 *  \param[in,out]    adrs             (in)  Pointer to adrs.
 *                                     (out) Pointer to adrs with new tree height and tree address.
 *  \param[in]        treeHeight       Height of the Merkle tree.
 *  \param[in]        leaf             Pointer to the leaf.
 *  \param[in]        leafIndex        Index of the leaf in the tree. This is NOT the tree index in algorithm 16
 *                                     but the variable indices[i].
 *  \param[in]        authPath         pointer to the authentication path associated to the leaf index
 *                                     from the signature.
 *  \param[in]        watchdog         pointer to the watchdog function
 *  \pre         - Pointers must be valid.
 *               - adrs must have length 32.
 *  \context     TASK
 *  \reentrant   TRUE, for different workspaces
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_INLINE_FUNC(void) actComputeRootInMerkleTreeWithAuthPath(
  VSECPRIM_P2CONST_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2VAR_PARA(actU8) node,
  actU8 treeHeight,
  VSECPRIM_P2CONST_PARA(actU8) leaf,
  actU32 leafIndex,
  VSECPRIM_P2CONST_PARA(actU8) authPath,
  VSECPRIM_P2VAR_PARA(actU8) adrs,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# endif /* defined ACT_PLATFORM_UINT64_AVAILABLE */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
} /* extern "C" */
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* ACTSLHDSA_BUILDINGFCT_H */

/**********************************************************************************************************************
 *  END OF FILE: actSLHDSA_BuildingFct.h
 *********************************************************************************************************************/
