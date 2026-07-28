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
/*!        \file  actSLHDSA_Utilities.h
 *        \brief  SLH-DSA utilities
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

#ifndef ACTSLHDSA_UTILITIES_H
# define ACTSLHDSA_UTILITIES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "actITypes.h"
# include "actConfig.h"
# include "actSLHDSA_Types.h"

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
 *  actBEU8toBEU4()
 *********************************************************************************************************************/
/*! \brief       Convert big endian byte array to big endian byte array in base 2^4.
 *  \details     Convert big endian byte array to big endian byte array in base 2^4 (used for base_2^b in algo 6
 *               and algo 7).
 *  \param[in,out]    dest       (in)  Pointer to byte-array.
 *                               (out) Pointer to byte-array with a 2^4 base representation of src.
 *  \param[in]        destLength Length of byte-array dest.
 *  \param[in]        src        Pointer to byte-array.
 *  \pre         - Pointers must be valid.
 *               - srcLength must be at least ceil(destLength*log2base / 8).
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actBEU8toBEU4(VSECPRIM_P2VAR_PARA(actU8) dest,
                                           actU8 destLength,
                                           VSECPRIM_P2CONST_PARA(actU8) src);

/**********************************************************************************************************************
 *  actBEU8ToBase2PowerB()
 *********************************************************************************************************************/
/*! \brief       Transform the left bits of a byte array in an array of base 2^log2base.
 *  \details     Transform the (destLength * log2base) left bits of the byte array src in an actU16-array dest of
 *               base 2^log2base.
 *               Steps: 1) Copy enough bytes from "src" to a buffer "total" (enough means at least log2base bits).
 *                      2) Copy the next relevant log2base bits from "total" to the next variable of "dest".
 *               NOTE: In general, we do not compute the 2^log2base representation of src, since the amount of
 *                     bits in src may exceed (destLength * log2base) bits.
 *  \param[in,out]    dest       (in)  Pointer to actU16-array.
 *                               (out) Pointer to actU16-array with a 2^log2base base representation of src.
 *  \param[in]        destLength Length of actU16-array dest.
 *  \param[in]        src        Pointer to byte-array.
 *  \param[in]        log2base   Logarithm in base 2 of the base, corresponds to the amount of bits.
 *  \pre         - Pointers must be valid.
 *               - srcLength must be at least ceil(destLength*log2base / 8).
 *               - log2base <= 16 (in SLHDSA, log2base is always <=14 ).
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actBEU8ToBase2PowerB(VSECPRIM_P2VAR_PARA(actU16) dest,
                                                actU8 destLength,
                                                VSECPRIM_P2CONST_PARA(actU8) src,
                                                actU8 log2base);

/**********************************************************************************************************************
 *  actVarLenBEtoU64()
 *********************************************************************************************************************/
/*! \brief       Copy u8 big endian array with variable length into u64 value
 *  \details     This function copies u8 array in big endian format with variable length into u64 value.
 *  \param[in]   src      Pointer to u8 array
 *  \param[in]   length   Length u8 array src
 *  \return      u64 value
 *  \pre         Pointers must be valid.
 *               length must be an integer such that 0 <= length <= 8.
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_INLINE_FUNC(actU64) actVarLenBEtoU64(VSECPRIM_P2CONST_PARA(actU8) src, actU8 length);

/**********************************************************************************************************************
 *  actVarLenBEtoU16()
 *********************************************************************************************************************/
/*! \brief       Copy u8 big endian array with variable length into u16 value
 *  \details     This function copies u8 array in big endian format with variable length into u16 value.
 *  \param[in]   src      Pointer to u8 array
 *  \param[in]   length   Length u8 array src
 *  \return      u16 value
 *  \pre         Pointers must be valid.
 *               length must be an integer such that 0 <= length <= 2.
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_INLINE_FUNC(actU16) actVarLenBEtoU16(VSECPRIM_P2CONST_PARA(actU8) src, actU8 length);

/**********************************************************************************************************************
 *  actCompressAdrs()
 *********************************************************************************************************************/
/*! \brief       Copy an address to a compressed address.
 *  \details     Copy the data of adrs in a compressed adrs (see end of section 4.2 in FIPS 205).
 *                #           adrs index:    0  1  2  3| 4  5  6  7| 8  9 10 11| 12 13 14 15|| 16 17 18 19| 20...31
 *                #                 adrs = [___________|____________________________________||____________|___...__]
 *                #       adrsCompressed =          [__]           [___________|____________]         [___|___...__]
 *                # adrsCompressed index:             0|             1  2  3  4|  5  6  7  8||           9| 10...21
 *  \param[in,out]    adrsCompressed  (in)  Pointer to a 22-byte array address.
 *                                    (out) Pointer to a 22-byte array address where data from adrs is copied.
 *  \param[in]        adrs            Pointer to a 32-byte array address.
 *  \pre         - Pointers must be valid.
 *               - adrsCompressed must have length 22
 *               - adrs must have length 32
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actCompressAdrs(VSECPRIM_P2VAR_PARA(actU8) adrsCompressed,
                                    VSECPRIM_P2CONST_PARA(actU8) adrs);

/**********************************************************************************************************************
 *  actSetLayerAdrs()
 *********************************************************************************************************************/
/*! \brief       Set in ADRS the layer address.
 *  \details     Construction of the first 16 bytes of an ADRS:
 *                       [    ADRS_LAYER |                                     ADRS_TREE |
 *               index:  [ 00  01  02  03| 04  05  06  07  08  09  10  11  12  13  14  15|
 *                                     /\
 *                                Byte to set
 *               The layer address is max d, which is max 22 (section 10 in FIPS 205). Hence, we set only one byte.
 *  \param[in,out]    adrs       (in)  Pointer to ADRS.
 *                               (out) Pointer to ADRS with new layer address.
 *  \param[in]        layerAdrs  Integer which gives the layer address in a Merkle-tree.
 *  \pre         - Pointer must be valid.
 *               - adrs must have length 32.
 *               - 0 <= layerAdrs < 2^8.
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_INLINE_FUNC(void) actSetLayerAdrs(VSECPRIM_P2VAR_PARA(actU8) adrs,
                                           actU8 layerAdrs);

/**********************************************************************************************************************
 *  actSetTreeAdrs()
 *********************************************************************************************************************/
/*! \brief       Set in ADRS the tree address.
 *  \details     Construction of the first 16 bytes of an ADRS:
 *                       [    ADRS_LAYER |                                     ADRS_TREE |
 *               index:  [ 00  01  02  03| 04  05  06  07  08  09  10  11  12  13  14  15|
 *                                                         /\  /\  /\  /\  /\  /\  /\  /\
 *                                                                 Bytes to set
 *               The tree index is max (h - h_prime) bits = 64 bits = 8 bytes. (section 10 in FIPS 205).
 *               Hence, we use an actU64 data type.
 *  \param[in,out]    adrs       (in)  Pointer to ADRS.
 *                               (out) Pointer to ADRS with new tree address.
 *  \param[in]        treeAdrs   Integer which gives the tree address.
 *  \pre         - Pointer must be valid.
 *               - adrs must have length 32.
 *               - 0 <= layerAdrs < 2^64.
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_INLINE_FUNC(void) actSetTreeAdrs(VSECPRIM_P2VAR_PARA(actU8) adrs,
                                          actU64 treeAdrs);

/**********************************************************************************************************************
 *  actSetTypeAndClear()
 *********************************************************************************************************************/
/*! \brief       Set in a 32-byte ADRS the address type and set the 12 last bytes to zero.
 *  \details     Construction of ADRS (without 16 first bytes):
 *                       | ADRS_TYPE = ? |                                   Set to zero ]
 *               index:  | 16  17  18  19| 20  21  22  23| 24  25  26  27| 28  29  30  31]
 *                                     /\
 *                                 Byte to set
 *               The address type is max 6. Hence, we set only one byte.
 *  \param[in,out]    adrs       (in)  Pointer to ADRS.
 *                               (out) Pointer to ADRS with new type and bytes at index 20 to 31 set to zero.
 *  \param[in]        type       Integer which gives the type of the address.
 *  \pre         - Pointer must be valid.
 *               - adrs must have length 32.
 *               - 0 <= layerAdrs < 2^8.
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_INLINE_FUNC(void) actSetTypeAndClear(VSECPRIM_P2VAR_PARA(actU8) adrs,
                                              actU8 type);

/**********************************************************************************************************************
 *  actSetHashAdrs()
 *********************************************************************************************************************/
/*! \brief       Set the hash address.
 *  \details     Set in ADRS of type WOTS_HASH in the word HASH_ADRS the hashing position (hashAdrs) in a WOTS chain.
 *               Construction of a WOTS_HASH ADRS (without 16 first bytes):
 *                       | ADRS_TYPE = 0 | KEY_PAIR_ADRS |    CHAIN_ADRS |     HASH_ADRS ]
 *               index:  | 16  17  18  19| 20  21  22  23| 24  25  26  27| 28  29  30  31]
 *                                                                                     /\
 *                                                                                 Byte to set
 *               A chain in FIPS 205 has a length of 16. Hence, we set only one byte.
 *  \param[in,out]    adrs       (in)  Pointer to ADRS.
 *                               (out) Pointer to ADRS with new hash address.
 *  \param[in]        hashAdrs   Integer which gives the new hash address.
 *  \pre         - Pointer must be valid.
 *               - adrs must have length 32.
 *               - 0 <= hashAdrs < 2^8.
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_INLINE_FUNC(void) actSetHashAdrs(VSECPRIM_P2VAR_PARA(actU8) adrs,
                                          actU8 hashAdrs);

/**********************************************************************************************************************
 *  actSetChainAdrs()
 *********************************************************************************************************************/
/*! \brief       Set the chain address.
 *  \details     Set in ADRS of type WOTS_HASH in the word CHAIN_ADRS the index of the chain in WOTS+.
 *               Construction of a WOTS_HASH ADRS (without 16 first bytes):
 *                       | ADRS_TYPE = 0 | KEY_PAIR_ADRS |    CHAIN_ADRS |     HASH_ADRS ]
 *               index:  | 16  17  18  19| 20  21  22  23| 24  25  26  27| 28  29  30  31]
 *                                                                     /\
 *                                                                 Byte to set
 *               There are (2*MAIN_PARAMETER + 3) chains, we never use an index greater than 67.
 *                Hence, we set only one byte.
 *  \param[in,out]    adrs       (in)  Pointer to ADRS.
 *                               (out) Pointer to ADRS with new chain address.
 *  \param[in]        chainAdrs  Integer which gives the new chain address.
 *  \pre         - Pointer must be valid.
 *               - adrs must have length 32.
 *               - 0 <= chainAdrs < 2^8.
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_INLINE_FUNC(void) actSetChainAdrs(VSECPRIM_P2VAR_PARA(actU8) adrs,
                                           actU8 chainAdrs);

/**********************************************************************************************************************
 *  actSetKeyPairAdrs()
 *********************************************************************************************************************/
/*! \brief       Set the key pair address.
 *  \details     Set in ADRS with a KEY_PAIR_ADRS word the key pair address.
 *               Every address has a KEY_PAIR_ADRS word excepted for type == 2 (TREE).
 *               Construction of an ADRS of type != 2 (without 16 first bytes):
 *                       | ADRS_TYPE != 2| KEY_PAIR_ADRS |                             ? ]
 *               index:  | 16  17  18  19| 20  21  22  23| 24  25  26  27| 28  29  30  31]
 *                                                 /\  /\
 *                                              Bytes to set
 *               The key pair address is the leaf of the hyper tree and is max 2^9 (2^h_prime).
 *               Hence, we use an actU16 data type.
 *  \param[in,out]    adrs         (in)  Pointer to ADRS.
 *                                 (out) Pointer to ADRS with new key pair address.
 *  \param[in]        keyPairAdrs  Integer which gives the new key pair address.
 *  \pre         - Pointer must be valid.
 *               - adrs must have length 32.
 *               - 0 <= keyPairAdrs < 2^16.
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_INLINE_FUNC(void) actSetKeyPairAdrs(VSECPRIM_P2VAR_PARA(actU8) adrs,
                                             actU16 keyPairAdrs);

/**********************************************************************************************************************
 *  actCopyKeyPairAdrs()
 *********************************************************************************************************************/
/*! \brief       Copy the key pair address from an ADRS to another.
 *  \details     Replace the following operation in FIPS 205:
 *                  adrs1.setKeyPairAddress(adrs2.getKeyPairAddress())
 *               Construction of an ADRS of type != 2 (without 16 first bytes):
 *                       | ADRS_TYPE != 2| KEY_PAIR_ADRS |                             ? ]
 *               index:  | 16  17  18  19| 20  21  22  23| 24  25  26  27| 28  29  30  31]
 *                                                 /\  /\
 *                                             Bytes to copy
 *               The key pair address is the leaf of the hyper tree and is max 2^9 (2^h_prime).
 *               Hence, we copy 2 bytes.
 *  \param[in,out]    adrsDest     (in)  Pointer to ADRS.
 *                                 (out) Pointer to ADRS with new key pair address.
 *  \param[in]        adrsSrc      (in)  Pointer to ADRS containing key pair address to copy.
 *  \pre         - Pointers must be valid.
 *               - adrsDest and adrsSrc must have length 32.
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_INLINE_FUNC(void) actCopyKeyPairAdrs(VSECPRIM_P2VAR_PARA(actU8) adrsDest,
                                              VSECPRIM_P2CONST_PARA(actU8) adrsSrc);

/**********************************************************************************************************************
 *  actSetTreeIndex()
 *********************************************************************************************************************/
/*! \brief       Set in an ADRS with a word TREE_INDEX the tree index.
 *  \details     Set in an address of type 2 (TREE), type 3 (FORS_TREE) or type 6 (FORS_PRF) the tree index.
 *               Construction of an ADRS of type 2, 3 or 6 (without 16 first bytes):
 *                       |     ADRS_TYPE |             ? |   TREE_HEIGHT |    TREE_INDEX ]
 *               index:  | 16  17  18  19| 20  21  22  23| 24  25  26  27| 28  29  30  31]
 *                                                                         /\  /\  /\  /\
 *                                                                          Bytes to set
 *               In FORS, the tree index is max (k-1)*2^a + 2^a - 1 which can be greater than 2^16 for some versions
 *               of SLH-DSA. Hence, we use a actU32 integer and set the complete word.
 *  \param[in,out]    adrs         (in)  Pointer to ADRS.
 *                                 (out) Pointer to ADRS with new tree index.
 *  \param[in]        treeIndex    Integer which gives the new tree index.
 *  \pre         - Pointer must be valid.
 *               - adrs must have length 32.
 *               - 0 <= keyPairAdrs < 2^32.
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_INLINE_FUNC(void) actSetTreeIndex(VSECPRIM_P2VAR_PARA(actU8) adrs,
                                           actU32 treeIndex);

/**********************************************************************************************************************
 *  actGetTreeIndex()
 *********************************************************************************************************************/
/*! \brief       Get from an ADRS with a word TREE_INDEX the tree index.
 *  \details     Get from an address of type 2 (TREE), type 3 (FORS_TREE) or type 6 (FORS_PRF) the tree index.
 *               Construction of an ADRS of type 2, 3 or 6 (without 16 first bytes):
 *                       |     ADRS_TYPE |             ? |   TREE_HEIGHT |    TREE_INDEX ]
 *               index:  | 16  17  18  19| 20  21  22  23| 24  25  26  27| 28  29  30  31]
 *                                                                         /\  /\  /\  /\
 *                                                                Bytes to transform in an integer and to get.
 *  \param[in]   adrs    Pointer to an adrs of type 2, 3 or 6.
 *  \return      - The value of tree index.
 *  \pre         - Pointer must be valid.
 *               - adrs must have length 32.
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_INLINE_FUNC(actU32) actGetTreeIndex(VSECPRIM_P2CONST_PARA(actU8) adrs);

/**********************************************************************************************************************
 *  actSetTreeHeight()
 *********************************************************************************************************************/
/*! \brief       Set in an ADRS with a word TREE_HEIGHT the tree height.
 *  \details     Set in an address of type 2 (TREE), type 3 (FORS_TREE) or type 6 (FORS_PRF) the tree height.
 *               Construction of an ADRS of type 2, 3 or 6 (without 16 first bytes):
 *                       |     ADRS_TYPE |             ? |   TREE_HEIGHT |    TREE_INDEX ]
 *               index:  | 16  17  18  19| 20  21  22  23| 24  25  26  27| 28  29  30  31]
 *                                                                     /\
 *                                                                 Byte to set
 *               The tree height is either the tree height in FORS, which is a, or the tree height in XMSS,
 *               which is h_prime.
 *               Since, the max for the tree height is 14, we only set one byte.
 *  \param[in,out]    adrs         (in)  Pointer to ADRS.
 *                                 (out) Pointer to ADRS with new tree height.
 *  \param[in]        treeHeight   Integer which gives the new tree height.
 *  \pre         - Pointer must be valid.
 *               - adrs must have length 32.
 *               - 0 <= treeHeight < 2^8.
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_INLINE_FUNC(void) actSetTreeHeight(VSECPRIM_P2VAR_PARA(actU8) adrs,
                                            actU8 treeHeight);

/**********************************************************************************************************************
 *  actInitWorkSpaceSLHDSA()
 *********************************************************************************************************************/
/*! \brief       Compute all the parameters needed during the SLH-DSA algorithm from the main parameters.
 *  \details     The main parameters are given in table 1, section 10, FIPS 205.
 *               If the parameter name:
 *               - contains "Length", it is a "length" in bytes. If the length is in bits, it is explicitly
 *                 written in the name.
 *               - starts with "get", it is an index for an array.
 *               - end with "AtIdx", we are in the context of a loop with a loop index and the parameter must be
 *                 multiplied with the loop index to get the right index in the target array.
 *  \param[in,out]    ws              (in)  Pointer to workspace.
 *                                    (out) Pointer to workspace with parameter set.
 *  \pre         - Pointer must be valid.
 *  \context     TASK
 *  \reentrant   TRUE, for different workspaces
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_INLINE_FUNC(void) actInitWorkSpaceSLHDSA(
  VSECPRIM_P2VAR_PARA(actWorkSpaceVerifySLHDSA) ws);

# endif /* defined ACT_PLATFORM_UINT64_AVAILABLE */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
} /* extern "C" */
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* ACTSLHDSAUTILITIES_H */

/**********************************************************************************************************************
 *  END OF FILE: actSLHDSA_Utilities.h
 *********************************************************************************************************************/
