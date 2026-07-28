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
/*!        \file  actSLHDSA_Types.h
 *        \brief  SLH-DSA Types
 *
 *      \details This file is part of the embedded systems library cvActLib.
 *               Define symbolic constants and data types for the act level of SLH-DSA, see
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

#ifndef ACTSLHDSATYPES_H
# define ACTSLHDSATYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "actPlatformTypes.h"
# include "actConfig.h"
# include "actITypes.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * SLH-DSA versions
 *********************************************************************************************************************/

# define actSLHDSA_VERSION_128S                                       (0x00u)
# define actSLHDSA_VERSION_128F                                       (0x01u)
# define actSLHDSA_VERSION_192S                                       (0x02u)
# define actSLHDSA_VERSION_192F                                       (0x03u)
# define actSLHDSA_VERSION_256S                                       (0x04u)
# define actSLHDSA_VERSION_256F                                       (0x05u)

/**********************************************************************************************************************
 * HASH PARAMETERS
 *********************************************************************************************************************/

# define actSLHDSA_HASH_ID_SHA2_256                                   actHA_SHA2_256
# define actSLHDSA_HASH_ID_SHA2_512                                   actHA_SHA2_512
# define actSLHDSA_HASH_ID_SHAKE_256                                  actHA_SHAKE_256

# define actSLHDSA_HASH_SIZE_SHA2_256                                 actHASH_SIZE_SHA256
# define actSLHDSA_HASH_SIZE_SHA2_512                                 actHASH_SIZE_SHA512

/**********************************************************************************************************************
 * SLH-DSA Address Parameters
 *********************************************************************************************************************/

/* Address types (same name as in FIPS-205) */
# define actSLHDSA_ADRS_TYPE_WOTS_HASH                                (0u)
# define actSLHDSA_ADRS_TYPE_WOTS_PK                                  (1u)
# define actSLHDSA_ADRS_TYPE_TREE                                     (2u)
# define actSLHDSA_ADRS_TYPE_FORS_TREE                                (3u)
# define actSLHDSA_ADRS_TYPE_FORS_ROOTS                               (4u)
# define actSLHDSA_ADRS_TYPE_WOTSP_PRF                                (5u)
# define actSLHDSA_ADRS_TYPE_FORS_PRF                                 (6u)

 /* Address general:
 [    ADRS_LAYER |                                     ADRS_TREE ||     ADRS_TYPE |                      Dependent from ADRS_TYPE ]
 [_______________|_______________|_______________|_______________||_______________|_______________|_______________|_______________]
    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15   16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31
 */
# define actSLHDSA_ADRS_WORD_LENGTH                                   (4u)
# define actSLHDSA_ADRS32_LENGTH                                      (32u)     /* An address (denoted adrs) has 32 bytes splitted in 8 words of 4 bytes */
# define actSLHDSA_ADRS32_LAYER_LSB                                   (3u)
# define actSLHDSA_ADRS32_TREE_MSB                                    (4u)
# define actSLHDSA_ADRS32_TYPE_LSB                                    (19u)
# define actSLHDSA_ADRS32_KEY_PAIR_ADRS_MSB                           (20u)
# define actSLHDSA_ADRS32_KEY_PAIR_ADRS_LSB                           (23u)
# define actSLHDSA_ADRS32_CHAIN_ADRS_LSB                              (27u)
# define actSLHDSA_ADRS32_HASH_ADRS_LSB                               (31u)
# define actSLHDSA_ADRS32_TREE_HEIGHT_LSB                             (27u)
# define actSLHDSA_ADRS32_TREE_INDEX_MSB                              (28u)

/* Compressed address for SHA2-256 (see end of section 4.2 in FIPS 205):
 [    ADRS_LAYER |                                     ADRS_TREE ||     ADRS_TYPE |                      Dependent from ADRS_TYPE ]
            [____]               [_______________|_______________]           [____|_______________|_______________|_______________]
                0                   1   2   3   4   5   6   7   8                9  10  11  12  13  14  15  16  17  18  19  20  21
ADRS_LAYER is 1 byte long
ADRS_TREE  is 8 bytes long
ADRS_TYPE  is 1 byte long
 */
# define actSLHDSA_ADRS22_LENGTH                                      (22u)
# define actSLHDSA_ADRS22_LAYER_LSB                                   (0u)
# define actSLHDSA_ADRS22_TREE_MSB                                    (1u)
# define actSLHDSA_ADRS22_TYPE_LSB                                    (9u)

/**********************************************************************************************************************
 * WOTS+ general parameters
 *********************************************************************************************************************/

# define actSLHDSA_WINTERNITZ_PARAMETER                               (16u)
# define actSLHDSA_WINTERNITZ_PARAMETER_LOG2                          (4u)
# define actSLHDSA_CSUM_BYTE_LENGTH                                   (2u) /* Three 4 bits values fit into 2 bytes */

# define actSLHDSA_FLAG_LEFT                                          (0u)
# define actSLHDSA_FLAG_RIGHT                                         (1u)

/**********************************************************************************************************************
 * SLH-DSA SHA256_128S
 *********************************************************************************************************************/

/*************** SLH-DSA Main Parameters for version 128S ***************/
/* Length are given in bytes */
# define actSLHDSA_MAIN_PARAMETER_128S                                (16u)         /* Main parameter n in FIPS205 */
# define actSLHDSA_FORS_NUMBER_TREES_128S                             (14u)         /* Variable k in FIPS205: Amount of trees in FORS */
# define actSLHDSA_FORS_HEIGHT_128S                                   (12u)         /* Variable a in FIPS205: Bit length of a message block used in one FORS tree */
# define actSLHDSA_HT_NUMBER_LAYER_128S                               (7u)          /* Variable d in FIPS205: Number of layers in the hyper tree */
# define actSLHDSA_XMSS_HEIGHT_128S                                   (9u)          /* Variable h_prime in FIPS205: Height of an XMSS tree */
# define actSLHDSA_DIGEST_LENGTH_128S                                 (30u)         /* Variable m in FIPS205: Length of the digest */

# define actSLHDSA_PK_LENGTH_128S                                     (2u * actSLHDSA_MAIN_PARAMETER_128S)        /* Length of the SLH-DSA public key */
# define actSLHDSA_SK_LENGTH_128S                                     (4u * actSLHDSA_MAIN_PARAMETER_128S)        /* Length of the SLH-DSA secret key */
# define actSLHDSA_SIGNATURE_LENGTH_128S                              (7856u)       /* Length of the SLH-DSA signature: RANDOMIZER_LENGTH + FORS_SIGNATURE_LENGTH + HT_SIGNATURE_LENGTH */

# define actSLHDSA_SHA256_PADDING_LENGTH_128S                         (64u - actSLHDSA_MAIN_PARAMETER_128S)

/**********************************************************************************************************************
 * MAX VALUES FOR LOCAL ARRAY DEFINITION (currently only for version 128S and SHA256)
 *********************************************************************************************************************/

 /* These defines MUST be adapted when multiple versions are supported */
# define actSLHDSA_MAIN_PARAMETER_MAX                                 actSLHDSA_MAIN_PARAMETER_128S
# define actSLHDSA_FORS_NUMBER_TREES_MAX                              actSLHDSA_FORS_NUMBER_TREES_128S
# define actSLHDSA_FORS_HEIGHT_MAX                                    actSLHDSA_FORS_HEIGHT_128S
# define actSLHDSA_DIGEST_LENGTH_MAX                                  actSLHDSA_DIGEST_LENGTH_128S
# define actSLHDSA_XMSS_HEIGHT_MAX                                    actSLHDSA_XMSS_HEIGHT_128S

# define actSLHDSA_HASH_SIZE_MAX                                      actSLHDSA_HASH_SIZE_SHA2_256
# define actSLHDSA_HASH_PADDING_LENGTH_MAX                            actSLHDSA_SHA256_PADDING_LENGTH_128S

# define actSLHDSA_PK_LENGTH_MAX                                      (2u * actSLHDSA_MAIN_PARAMETER_MAX)
# define actSLHDSA_RANDOMIZER_LENGTH_MAX                              actSLHDSA_MAIN_PARAMETER_MAX
# define actSLHDSA_WOTS_LEN_MAX                                       ((2u * actSLHDSA_MAIN_PARAMETER_MAX) + 3u)
# define actSLHDSA_SEED_LENGTH_MAX                                    (2u * actSLHDSA_MAIN_PARAMETER_MAX) + actSLHDSA_HASH_SIZE_MAX
# define actSLHDSA_H_INPUT_LENGTH_MAX                                 (2u * actSLHDSA_MAIN_PARAMETER_MAX)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

# define BITS_TO_BYTES(x)                                             (((x) + 7u) >> 3u)

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/**********************************************************************************************************************
 * STRUCTURE AND UNION WORKSPACE
 *********************************************************************************************************************/

/* Struct for computed parameters */
typedef struct
{
  /**** actU16 types ***/
  /* XMSS */
  actU16 getWotsSig;
  actU16 getXmssAuthPath;

  /* Hypertree */
  actU16 getXmssSigAtIdx;

  /* FORS */
  actU16 forsNbrLeafs;
  actU16 getForsTreeAuthPath;
  actU16 getForsTreeSK;
  actU16 getForsTreeSigAtIdx;

  /* WOTS */
  actU16 wotsRootsLength;

  /* Scheme */
  actU16 getTreeIdx;
  actU16 getLeafIdx;
  actU16 getHyperTreeSignature;

  /**** actU8 types ***/
  /* Version parameters */
  actU8 version;
  actU8 mainParameter;      /* n  in NIST FIPS205 */
  actU8 xmssTreeHeight;     /* h' in NIST FIPS205 */
  actU8 forsTreeHeight;     /* a  in NIST FIPS205 */
  actU8 hyperTreeNbrLayers; /* d  in NIST FIPS205 */
  actU8 forsNbrTrees;       /* k  in NIST FIPS205 */
  actU8 digestLength;       /* m  in NIST FIPS205 */

  /* Hash parameters */
  actU8 hashID;
  actU8 hashSize;

  /* Building Fcts */
  actU8 hInputLength;

  /* WOTS */
  actU8 getNodeAtIdx;
  actU8 wotsLengthMessageDigest;
  actU8 wotsLengthCheckSum;
  actU8 wotsLength;

  /* Scheme */
  actU8 treeIdxLength;
  actU8 leafIdxLength;
  actU8 treeIdxLengthInBits;
  actU8 leafIdxLengthInBits;
  actU8 getForsSignature;

  actU8 getPKSeed;
  actU8 getPKRoot;
} actParametersSLHDSA;

/* Building functions */
/* Union for hash workspaces. Currently, only SHA2-256 is supported.
   Extension possible with SHA2-512 and SHAKE256. */
typedef union
{/* PRQA S 0750 */ /* MD_MSR_Union */
  actSHA256STRUCT SHA256ws;
# if(actSLHDSA_SHAKE_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */
  actSHA512STRUCT SHA512ws;
# endif
# if(actSLHDSA_SHA2_512_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */
  actKECCAKcSTRUCT SHAKEws;
# endif
} actWorkSpaceUnionHashFunctions_SLHDSA;

/* Struct for SLHDSA on act level */
typedef struct
{
  actParametersSLHDSA parameters;
  actU8 pkSeed[actSLHDSA_MAIN_PARAMETER_MAX];
  actU8 pkRoot[actSLHDSA_MAIN_PARAMETER_MAX];
  actWorkSpaceUnionHashFunctions_SLHDSA wsHash;
} actWorkSpaceVerifySLHDSA;

#endif /* ACTSLHDSATYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: actSLHDSA_Types.h
 *********************************************************************************************************************/
