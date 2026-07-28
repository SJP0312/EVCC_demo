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
/*!        \file  actSLHDSA_WOTS.h
 *        \brief  SLH-DSA WOTS algorithms for version:
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

#ifndef ACTSLHDSA_WOTS_H
# define ACTSLHDSA_WOTS_H

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
 *  actSLHDSAWotsPublicKeyFromSig()
 *********************************************************************************************************************/
/*! \brief          The function actSLHDSAWotsPublicKeyFromSig computes the WOTS+ public key given a
 *                   WOTS+ signature.
 *  \details        We only obtain the correct WOTS+ public key if the WOTS+ signature (part of XMSS signature)
 *                  is a signature of the message digest given in signedMessage.
 *                  The implementation corresponds to algorithm 7 in FIPS205.
 *                  Steps:
 *                  - Get a representation in base 16 of the signed message.
 *                  - Compute checksum
 *                  - Get a representation in base 16 of the checksum and copy it at the end of the representation
 *                    of the signed message.
 *                  - Compute the roots of the WOTS+ chains.
 *                  - Hash the roots to get the WOTS+ public key.
 *  \param[in,out]  ws             (in)  Pointer to workspace.
 *                                 (out) Pointer to workspace.
 *  \param[in,out]  wotsPkFromSig  (in)  Pointer to buffer for the WOTS+ public key.
 *                                 (out) Pointer to WOTS+ public key generated from a WOTS+ signature.
 *  \param[in]      wotsSignature  Pointer to the WOTS+ signature.
 *  \param[in]      signedMessage  Message digest.
 *  \param[in,out]  adrs           (in)  pointer to an ADRS with 32 bytes of type WOTS_HASH.
 *                                 (out) pointer to an ADRS with new chain address.
 *  \param[in]      watchdog       Pointer to the watchdog trigger function
 *  \pre            - Provided pointers must be valid.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSLHDSAWotsPublicKeyFromSig(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws,
  VSECPRIM_P2VAR_PARA(actU8) wotsPkFromSig,
  VSECPRIM_P2CONST_PARA(actU8) wotsSignature,
  VSECPRIM_P2CONST_PARA(actU8) signedMessage,
  VSECPRIM_P2VAR_PARA(actU8) adrs,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# endif /* defined ACT_PLATFORM_UINT64_AVAILABLE */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
} /* extern "C" */
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* ACTSLHDSA_WOTS_H */

/**********************************************************************************************************************
 *  END OF FILE: actSLHDSA_WOTS.h
 *********************************************************************************************************************/
