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
/*!        \file  actSLHDSA_XMSS.h
 *        \brief  SLH-DSA XMSS algorithms for version:
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

#ifndef ACTSLHDSA_XMSS_H
# define ACTSLHDSA_XMSS_H

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
 *  actSLHDSAXmssPublicKeyFromSig()
 *********************************************************************************************************************/
/*! \brief          This function computes an XMSS public key from a message and its signature.
 *  \details        We follow algorithm 10 in FIPS205.
 *                  Steps:
 *                  - Set the adrs for WOTS hashing.
 *                  - Get the WOTS signature and the authentication path of the XMSS Merkle tree
 *                    from the XMSS signature.
 *                  - Compute the WOTS public key from the message and the WOTS signature.
 *                    This is the leaf of the XMSS Merkle tree.
 *                  - Set adrs for an XMSS Merkle tree root computation.
 *                  - Compute the root of the XMSS Merkle tree.
 *  \param[in,out]  ws             (in)  Pointer to workspace.
 *                                 (out) Pointer to workspace.
 *  \param[in,out]  xmssPkFromSig  (in)  Pointer to buffer for the XMSS public key.
 *                                 (out) Pointer to XMSS public key generated from an XMSS signature.
 *  \param[in]      treeIndex      Index of the leaf for authentication in the XMSS Merkle tree
 *  \param[in]      xmssSignature  Pointer to the XMSS signature.
 *  \param[in]      signedMessage  Signed message, can be an XMSS or a FORS root.
 *  \param[in,out]  adrs           (in)  Pointer to an address with 32 bytes.
 *                                 (out) Pointer to an address of type actSLHDSA_ADRS_TYPE_TREE.
 *  \param[in]      watchdog       Pointer to the watchdog trigger function
 *  \pre            - Provided pointers must be valid.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSLHDSAXmssPublicKeyFromSig(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2VAR_PARA(actU8) xmssPkFromSig,
  actU16 treeIndex,
  VSECPRIM_P2CONST_PARA(actU8) xmssSignature,
  VSECPRIM_P2CONST_PARA(actU8) signedMessage,
  VSECPRIM_P2VAR_PARA(actU8) adrs,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# endif /* defined ACT_PLATFORM_UINT64_AVAILABLE */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
} /* extern "C" */
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* ACTSLHDSA_XMSS_H */

/**********************************************************************************************************************
 *  END OF FILE: actSLHDSA_XMSS.h
 *********************************************************************************************************************/
