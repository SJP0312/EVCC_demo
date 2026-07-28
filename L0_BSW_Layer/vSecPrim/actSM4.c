/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 1999 - 2016 cv cryptovision GmbH.                                                All rights reserved.
 *
 *  For modifications by Vector Informatik GmbH:
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is protected under intellectual property laws and proprietary to cv cryptovision GmbH
 *                and/or Vector Informatik GmbH.
 *                No right or license is granted save as expressly set out in the applicable license conditions.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  actSM4.c
 *         \unit  act_SM4
 *        \brief  Core SM4 implementation.
 *
 *      \details This file is part of the embedded systems library actLib
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

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "actISM4.h"
#include "actSM4.h"
#include "actUtilities.h"
#include "actWatchdog.h"
#include "actConfig.h"

#if (VSECPRIM_ACTSM4_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

/**********************************************************************************************************************
 * LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
/****************************************************************************
 * Look up tables
 ***************************************************************************/

/* byte-wide S-box (source: www.gmbz.org.cn/main/postDetail.html?id=20180404044052) */
# define VSECPRIM_START_SEC_CONST_8BIT
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VSECPRIM_ROM(VSECPRIM_LOCAL, actU8) sbox[256u] = {  /* PRQA S 3218 */ /* MD_VSECPRIM_8.7 */
  0xD6u, 0x90u, 0xE9u, 0xFEu, 0xCCu, 0xE1u, 0x3Du, 0xB7u, 0x16u, 0xB6u, 0x14u, 0xC2u, 0x28u, 0xFBu, 0x2Cu, 0x05u,
  0x2Bu, 0x67u, 0x9Au, 0x76u, 0x2Au, 0xBEu, 0x04u, 0xC3u, 0xAAu, 0x44u, 0x13u, 0x26u, 0x49u, 0x86u, 0x06u, 0x99u,
  0x9Cu, 0x42u, 0x50u, 0xF4u, 0x91u, 0xEFu, 0x98u, 0x7Au, 0x33u, 0x54u, 0x0Bu, 0x43u, 0xEDu, 0xCFu, 0xACu, 0x62u,
  0xE4u, 0xB3u, 0x1Cu, 0xA9u, 0xC9u, 0x08u, 0xE8u, 0x95u, 0x80u, 0xDFu, 0x94u, 0xFAu, 0x75u, 0x8Fu, 0x3Fu, 0xA6u,
  0x47u, 0x07u, 0xA7u, 0xFCu, 0xF3u, 0x73u, 0x17u, 0xBAu, 0x83u, 0x59u, 0x3Cu, 0x19u, 0xE6u, 0x85u, 0x4Fu, 0xA8u,
  0x68u, 0x6Bu, 0x81u, 0xB2u, 0x71u, 0x64u, 0xDAu, 0x8Bu, 0xF8u, 0xEBu, 0x0Fu, 0x4Bu, 0x70u, 0x56u, 0x9Du, 0x35u,
  0x1Eu, 0x24u, 0x0Eu, 0x5Eu, 0x63u, 0x58u, 0xD1u, 0xA2u, 0x25u, 0x22u, 0x7Cu, 0x3Bu, 0x01u, 0x21u, 0x78u, 0x87u,
  0xD4u, 0x00u, 0x46u, 0x57u, 0x9Fu, 0xD3u, 0x27u, 0x52u, 0x4Cu, 0x36u, 0x02u, 0xE7u, 0xA0u, 0xC4u, 0xC8u, 0x9Eu,
  0xEAu, 0xBFu, 0x8Au, 0xD2u, 0x40u, 0xC7u, 0x38u, 0xB5u, 0xA3u, 0xF7u, 0xF2u, 0xCEu, 0xF9u, 0x61u, 0x15u, 0xA1u,
  0xE0u, 0xAEu, 0x5Du, 0xA4u, 0x9Bu, 0x34u, 0x1Au, 0x55u, 0xADu, 0x93u, 0x32u, 0x30u, 0xF5u, 0x8Cu, 0xB1u, 0xE3u,
  0x1Du, 0xF6u, 0xE2u, 0x2Eu, 0x82u, 0x66u, 0xCAu, 0x60u, 0xC0u, 0x29u, 0x23u, 0xABu, 0x0Du, 0x53u, 0x4Eu, 0x6Fu,
  0xD5u, 0xDBu, 0x37u, 0x45u, 0xDEu, 0xFDu, 0x8Eu, 0x2Fu, 0x03u, 0xFFu, 0x6Au, 0x72u, 0x6Du, 0x6Cu, 0x5Bu, 0x51u,
  0x8Du, 0x1Bu, 0xAFu, 0x92u, 0xBBu, 0xDDu, 0xBCu, 0x7Fu, 0x11u, 0xD9u, 0x5Cu, 0x41u, 0x1Fu, 0x10u, 0x5Au, 0xD8u,
  0x0Au, 0xC1u, 0x31u, 0x88u, 0xA5u, 0xCDu, 0x7Bu, 0xBDu, 0x2Du, 0x74u, 0xD0u, 0x12u, 0xB8u, 0xE5u, 0xB4u, 0xB0u,
  0x89u, 0x69u, 0x97u, 0x4Au, 0x0Cu, 0x96u, 0x77u, 0x7Eu, 0x65u, 0xB9u, 0xF1u, 0x09u, 0xC5u, 0x6Eu, 0xC6u, 0x84u,
  0x18u, 0xF0u, 0x7Du, 0xECu, 0x3Au, 0xDCu, 0x4Du, 0x20u, 0x79u, 0xEEu, 0x5Fu, 0x3Eu, 0xD7u, 0xCBu, 0x39u, 0x48u
};

# define VSECPRIM_STOP_SEC_CONST_8BIT
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define VSECPRIM_START_SEC_CONST_32BIT
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if (actSM4_SPEED_UP >= 1u) /* COV_VSECPRIM_NO_SAFE_CONFIG XX */
/* 32bit wide S-box: */
/* pre-calculated    L (tau (b)) */
VSECPRIM_ROM(VSECPRIM_LOCAL, actU32) L_sbox[256u] = {  /* PRQA S 3218 */ /* MD_VSECPRIM_8.7 */
  0xD55B5B8Eu, 0x924242D0u, 0xEAA7A74Du, 0xFDFBFB06u, 0xCF3333FCu, 0xE2878765u, 0x3DF4F4C9u, 0xB5DEDE6Bu,
  0x1658584Eu, 0xB4DADA6Eu, 0x14505044u, 0xC10B0BCAu, 0x28A0A088u, 0xF8EFEF17u, 0x2CB0B09Cu, 0x05141411u,
  0x2BACAC87u, 0x669D9DFBu, 0x986A6AF2u, 0x77D9D9AEu, 0x2AA8A882u, 0xBCFAFA46u, 0x04101014u, 0xC00F0FCFu,
  0xA8AAAA02u, 0x45111154u, 0x134C4C5Fu, 0x269898BEu, 0x4825256Du, 0x841A1A9Eu, 0x0618181Eu, 0x9B6666FDu,
  0x9E7272ECu, 0x4309094Au, 0x51414110u, 0xF7D3D324u, 0x934646D5u, 0xECBFBF53u, 0x9A6262F8u, 0x7BE9E992u,
  0x33CCCCFFu, 0x55515104u, 0x0B2C2C27u, 0x420D0D4Fu, 0xEEB7B759u, 0xCC3F3FF3u, 0xAEB2B21Cu, 0x638989EAu,
  0xE7939374u, 0xB1CECE7Fu, 0x1C70706Cu, 0xABA6A60Du, 0xCA2727EDu, 0x08202028u, 0xEBA3A348u, 0x975656C1u,
  0x82020280u, 0xDC7F7FA3u, 0x965252C4u, 0xF9EBEB12u, 0x74D5D5A1u, 0x8D3E3EB3u, 0x3FFCFCC3u, 0xA49A9A3Eu,
  0x461D1D5Bu, 0x071C1C1Bu, 0xA59E9E3Bu, 0xFFF3F30Cu, 0xF0CFCF3Fu, 0x72CDCDBFu, 0x175C5C4Bu, 0xB8EAEA52u,
  0x810E0E8Fu, 0x5865653Du, 0x3CF0F0CCu, 0x1964647Du, 0xE59B9B7Eu, 0x87161691u, 0x4E3D3D73u, 0xAAA2A208u,
  0x69A1A1C8u, 0x6AADADC7u, 0x83060685u, 0xB0CACA7Au, 0x70C5C5B5u, 0x659191F4u, 0xD96B6BB2u, 0x892E2EA7u,
  0xFBE3E318u, 0xE8AFAF47u, 0x0F3C3C33u, 0x4A2D2D67u, 0x71C1C1B0u, 0x5759590Eu, 0x9F7676E9u, 0x35D4D4E1u,
  0x1E787866u, 0x249090B4u, 0x0E383836u, 0x5F797926u, 0x628D8DEFu, 0x59616138u, 0xD2474795u, 0xA08A8A2Au,
  0x259494B1u, 0x228888AAu, 0x7DF1F18Cu, 0x3BECECD7u, 0x01040405u, 0x218484A5u, 0x79E1E198u, 0x851E1E9Bu,
  0xD7535384u, 0x00000000u, 0x4719195Eu, 0x565D5D0Bu, 0x9D7E7EE3u, 0xD04F4F9Fu, 0x279C9CBBu, 0x5349491Au,
  0x4D31317Cu, 0x36D8D8EEu, 0x0208080Au, 0xE49F9F7Bu, 0xA2828220u, 0xC71313D4u, 0xCB2323E8u, 0x9C7A7AE6u,
  0xE9ABAB42u, 0xBDFEFE43u, 0x882A2AA2u, 0xD14B4B9Au, 0x41010140u, 0xC41F1FDBu, 0x38E0E0D8u, 0xB7D6D661u,
  0xA18E8E2Fu, 0xF4DFDF2Bu, 0xF1CBCB3Au, 0xCD3B3BF6u, 0xFAE7E71Du, 0x608585E5u, 0x15545441u, 0xA3868625u,
  0xE3838360u, 0xACBABA16u, 0x5C757529u, 0xA6929234u, 0x996E6EF7u, 0x34D0D0E4u, 0x1A686872u, 0x54555501u,
  0xAFB6B619u, 0x914E4EDFu, 0x32C8C8FAu, 0x30C0C0F0u, 0xF6D7D721u, 0x8E3232BCu, 0xB3C6C675u, 0xE08F8F6Fu,
  0x1D747469u, 0xF5DBDB2Eu, 0xE18B8B6Au, 0x2EB8B896u, 0x800A0A8Au, 0x679999FEu, 0xC92B2BE2u, 0x618181E0u,
  0xC30303C0u, 0x29A4A48Du, 0x238C8CAFu, 0xA9AEAE07u, 0x0D343439u, 0x524D4D1Fu, 0x4F393976u, 0x6EBDBDD3u,
  0xD6575781u, 0xD86F6FB7u, 0x37DCDCEBu, 0x44151551u, 0xDD7B7BA6u, 0xFEF7F709u, 0x8C3A3AB6u, 0x2FBCBC93u,
  0x030C0C0Fu, 0xFCFFFF03u, 0x6BA9A9C2u, 0x73C9C9BAu, 0x6CB5B5D9u, 0x6DB1B1DCu, 0x5A6D6D37u, 0x50454515u,
  0x8F3636B9u, 0x1B6C6C77u, 0xADBEBE13u, 0x904A4ADAu, 0xB9EEEE57u, 0xDE7777A9u, 0xBEF2F24Cu, 0x7EFDFD83u,
  0x11444455u, 0xDA6767BDu, 0x5D71712Cu, 0x40050545u, 0x1F7C7C63u, 0x10404050u, 0x5B696932u, 0xDB6363B8u,
  0x0A282822u, 0xC20707C5u, 0x31C4C4F5u, 0x8A2222A8u, 0xA7969631u, 0xCE3737F9u, 0x7AEDED97u, 0xBFF6F649u,
  0x2DB4B499u, 0x75D1D1A4u, 0xD3434390u, 0x1248485Au, 0xBAE2E258u, 0xE6979771u, 0xB6D2D264u, 0xB2C2C270u,
  0x8B2626ADu, 0x68A5A5CDu, 0x955E5ECBu, 0x4B292962u, 0x0C30303Cu, 0x945A5ACEu, 0x76DDDDABu, 0x7FF9F986u,
  0x649595F1u, 0xBBE6E65Du, 0xF2C7C735u, 0x0924242Du, 0xC61717D1u, 0x6FB9B9D6u, 0xC51B1BDEu, 0x86121294u,
  0x18606078u, 0xF3C3C330u, 0x7CF5F589u, 0xEFB3B35Cu, 0x3AE8E8D2u, 0xDF7373ACu, 0x4C353579u, 0x208080A0u,
  0x78E5E59Du, 0xEDBBBB56u, 0x5E7D7D23u, 0x3EF8F8C6u, 0xD45F5F8Bu, 0xC82F2FE7u, 0x39E4E4DDu, 0x49212168u
};
# endif

VSECPRIM_ROM(VSECPRIM_LOCAL, actU32) fk[4u] = {  /* PRQA S 3218 */ /* MD_VSECPRIM_8.7 */
  0xA3B1BAC6u, 0x56AA3350u, 0x677D9197u, 0xB27022DCu
};

VSECPRIM_ROM(VSECPRIM_LOCAL, actU32) ck[32u] = {  /* PRQA S 3218 */ /* MD_VSECPRIM_8.7 */
  0x00070E15u, 0x1C232A31u, 0x383F464Du, 0x545B6269u,
  0x70777E85u, 0x8C939AA1u, 0xA8AFB6BDu, 0xC4CBD2D9u,
  0xE0E7EEF5u, 0xFC030A11u, 0x181F262Du, 0x343B4249u,
  0x50575E65u, 0x6C737A81u, 0x888F969Du, 0xA4ABB2B9u,
  0xC0C7CED5u, 0xDCE3EAF1u, 0xF8FF060Du, 0x141B2229u,
  0x30373E45u, 0x4C535A61u, 0x686F767Du, 0x848B9299u,
  0xA0A7AEB5u, 0xBCC3CAD1u, 0xD8DFE6EDu, 0xF4FB0209u,
  0x10171E25u, 0x2C333A41u, 0x484F565Du, 0x646B7279u
};

# define VSECPRIM_STOP_SEC_CONST_32BIT
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
# if (actSM4_SPEED_UP < 1u)  /* COV_VSECPRIM_NO_SAFE_CONFIG XX */
#  define actSM4_L(B)                                                 ((actU32) (B) ^ actRotl((B), 2u) ^ actRotl((B), 10u) ^ actRotl((B), 18u) ^ actRotl((B), 24u))
# else
#  define actSM4_L_tau(A)                                             (((actU32) ACT_ROM_R_DWD (L_sbox[actGetU8fromU32 ((A), 0u)]))       ^   \
                                                                      (actRotl((actU32) ACT_ROM_R_DWD (L_sbox[actGetU8fromU32 ((A), 1u)]),  8u)) ^   \
                                                                      (actRotl((actU32) ACT_ROM_R_DWD (L_sbox[actGetU8fromU32 ((A), 2u)]), 16u)) ^   \
                                                                      (actRotl((actU32) ACT_ROM_R_DWD (L_sbox[actGetU8fromU32 ((A), 3u)]), 24u)))
# endif

/* L' NOT optimized: */
/* used for key expansion only; would need extra S-box table (1 KByte) */
# define actSM4_Lt(B)                                                 ((actU32) (B) ^ actRotl ((B), 13u) ^ actRotl ((B), 23u))

# define actSM4_tau(A)                                                (((actU32) ACT_ROM_R_BYT(sbox [actGetU8fromU32 ((A), 0u)]))        |     \
                                                                      ((actU32) ACT_ROM_R_BYT(sbox [actGetU8fromU32 ((A), 1u)]) <<  8u) |     \
                                                                      ((actU32) ACT_ROM_R_BYT(sbox [actGetU8fromU32 ((A), 2u)]) << 16u) |     \
                                                                      ((actU32) ACT_ROM_R_BYT(sbox [actGetU8fromU32 ((A), 3u)]) << 24u))

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actSM4Init()
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
VSECPRIM_FUNC(void) actSM4Init(
  VSECPRIM_P2VAR_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) key,
  VSECPRIM_P2CONST_PARA(actU8) iv,
  actU8 mode,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /* initialization mode, buffers, etc. */
  info->blockMode = mode;
  info->bufferUsed = 0u;
  switch (mode)
  {
  case actSM4_CBC:
    if (iv == NULL_PTR)
    {
      actMemClear(info->prevBlock, actSM4_BLOCK_SIZE);
    }
    else
    {
      actMemCpyByteArray(info->prevBlock, iv, actSM4_BLOCK_SIZE);
    }
    break;
  default: /* ECB mode: No initialization vector needed */
    break;
  }

  /* key setup */
  actSM4KeySetup(info, key, watchdog);
}

/**********************************************************************************************************************
 *  actSM4KeySetup()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_FUNC(void) actSM4KeySetup(
  VSECPRIM_P2VAR_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) key,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actU32 K[4u];

  /* load user key */
  actCpyBEtoU32(K, key, actSM4_KEY_SIZE);

  /* XOR with family key */
  actXOR32(K, fk, actSM4_KEY_WORDS);

  /* generate 32 round keys */
  for(actLengthType i = 0u; i < 32u; i++)
  {
    /* three separate steps, to prevent compiler from expanding tau (S-box) macro multiple times */
    actU32 tmp   = K[(i + 1u) % 4u] ^ K[(i + 2u) % 4u] ^ K[(i + 3u) % 4u] ^ ck[i];
    tmp          = actSM4_tau (tmp);   /* tmp = tau (K [i], ck [i]) */  /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    K[i % 4u]   ^= actSM4_Lt  (tmp);   /* K [i +4] = K [i] ^ T' (K [i]) = K [i] ^ L' (tau (K [i], ck [i])) */

    info->rk[i] = K[i % 4u];    /* rk [i] = K [i +4] */
  }

  actL1trigger(watchdog);  /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */  /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
}

/**********************************************************************************************************************
 *  actSM4EncryptBlockCore()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_FUNC(void) actSM4EncryptBlockCore(
  VSECPRIM_P2CONST_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) inBlock,
  VSECPRIM_P2VAR_PARA(actU8) outBlock,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actU32  X[4u];

  /* load block */
  actCpyBEtoU32 (X, inBlock, actSM4_BLOCK_SIZE);

# if (actSM4_SPEED_UP == 0u)  /* COV_VSECPRIM_NO_SAFE_CONFIG XX */
  {
    for (actLengthType i = 0u; i < 32u; i++)
    {
      actU32 tmp;

      /* three separate steps, to prevent compiler from expanding tau (S-box) macro multiple times */
      tmp        = X[(i + 1u) % 4u] ^ X[(i + 2u) % 4u] ^ X[(i + 3u) % 4u] ^ info->rk[i];
      tmp        = actSM4_tau (tmp);      /* tmp = actSM4_tau (X [i], rk [i]) */  /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
      X[i % 4u] ^= actSM4_L   (tmp);      /* X [i +4] = X [i] ^ T (X [i]) = X [i] ^ actSM4_L (actSM4_tau (X [i], rk [i])) */
    }
  }

# elif (actSM4_SPEED_UP == 1u)  /* COV_VSECPRIM_NO_SAFE_CONFIG XX */
  {
    for (actLengthType i = 0u; i < 32u; i++) {
      X[i % 4u] ^= actSM4_L_tau (X[(i + 1u) % 4u] ^ X[(i + 2u) % 4u] ^ X[(i + 3u) % 4u] ^ info->rk [i]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    }
  }

# elif (actSM4_SPEED_UP == 2u)  /* COV_VSECPRIM_NO_SAFE_CONFIG XX */
  {
    for (actLengthType i = 0u; i < 32u; i += 4u)
    {
      X[0u] ^= actSM4_L_tau (X[1u] ^ X[2] ^ X[3u] ^ info->rk[i + 0u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
      X[1u] ^= actSM4_L_tau (X[2u] ^ X[3] ^ X[0u] ^ info->rk[i + 1u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
      X[2u] ^= actSM4_L_tau (X[3u] ^ X[0] ^ X[1u] ^ info->rk[i + 2u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
      X[3u] ^= actSM4_L_tau (X[0u] ^ X[1] ^ X[2u] ^ info->rk[i + 3u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    }
  }

# elif (actSM4_SPEED_UP == 3)  /* COV_VSECPRIM_NO_SAFE_CONFIG XX */
  {
    X[0u] ^= actSM4_L_tau (X[1u] ^ X[2u] ^ X[3u] ^ info->rk[ 0u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[1u] ^= actSM4_L_tau (X[2u] ^ X[3u] ^ X[0u] ^ info->rk[ 1u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[2u] ^= actSM4_L_tau (X[3u] ^ X[0u] ^ X[1u] ^ info->rk[ 2u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[3u] ^= actSM4_L_tau (X[0u] ^ X[1u] ^ X[2u] ^ info->rk[ 3u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[0u] ^= actSM4_L_tau (X[1u] ^ X[2u] ^ X[3u] ^ info->rk[ 4u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[1u] ^= actSM4_L_tau (X[2u] ^ X[3u] ^ X[0u] ^ info->rk[ 5u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[2u] ^= actSM4_L_tau (X[3u] ^ X[0u] ^ X[1u] ^ info->rk[ 6u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[3u] ^= actSM4_L_tau (X[0u] ^ X[1u] ^ X[2u] ^ info->rk[ 7u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[0u] ^= actSM4_L_tau (X[1u] ^ X[2u] ^ X[3u] ^ info->rk[ 8u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[1u] ^= actSM4_L_tau (X[2u] ^ X[3u] ^ X[0u] ^ info->rk[ 9u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[2u] ^= actSM4_L_tau (X[3u] ^ X[0u] ^ X[1u] ^ info->rk[10u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[3u] ^= actSM4_L_tau (X[0u] ^ X[1u] ^ X[2u] ^ info->rk[11u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[0u] ^= actSM4_L_tau (X[1u] ^ X[2u] ^ X[3u] ^ info->rk[12u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[1u] ^= actSM4_L_tau (X[2u] ^ X[3u] ^ X[0u] ^ info->rk[13u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[2u] ^= actSM4_L_tau (X[3u] ^ X[0u] ^ X[1u] ^ info->rk[14u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[3u] ^= actSM4_L_tau (X[0u] ^ X[1u] ^ X[2u] ^ info->rk[15u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[0u] ^= actSM4_L_tau (X[1u] ^ X[2u] ^ X[3u] ^ info->rk[16u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[1u] ^= actSM4_L_tau (X[2u] ^ X[3u] ^ X[0u] ^ info->rk[17u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[2u] ^= actSM4_L_tau (X[3u] ^ X[0u] ^ X[1u] ^ info->rk[18u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[3u] ^= actSM4_L_tau (X[0u] ^ X[1u] ^ X[2u] ^ info->rk[19u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[0u] ^= actSM4_L_tau (X[1u] ^ X[2u] ^ X[3u] ^ info->rk[20u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[1u] ^= actSM4_L_tau (X[2u] ^ X[3u] ^ X[0u] ^ info->rk[21u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[2u] ^= actSM4_L_tau (X[3u] ^ X[0u] ^ X[1u] ^ info->rk[22u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[3u] ^= actSM4_L_tau (X[0u] ^ X[1u] ^ X[2u] ^ info->rk[23u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[0u] ^= actSM4_L_tau (X[1u] ^ X[2u] ^ X[3u] ^ info->rk[24u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[1u] ^= actSM4_L_tau (X[2u] ^ X[3u] ^ X[0u] ^ info->rk[25u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[2u] ^= actSM4_L_tau (X[3u] ^ X[0u] ^ X[1u] ^ info->rk[26u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[3u] ^= actSM4_L_tau (X[0u] ^ X[1u] ^ X[2u] ^ info->rk[27u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[0u] ^= actSM4_L_tau (X[1u] ^ X[2u] ^ X[3u] ^ info->rk[28u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[1u] ^= actSM4_L_tau (X[2u] ^ X[3u] ^ X[0u] ^ info->rk[29u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[2u] ^= actSM4_L_tau (X[3u] ^ X[0u] ^ X[1u] ^ info->rk[30u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[3u] ^= actSM4_L_tau (X[0u] ^ X[1u] ^ X[2u] ^ info->rk[31u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
  }
# endif

  /* store block in reverse order */
  actU32toBE(outBlock,       X[3u]);
  actU32toBE(&outBlock[4u],  X[2u]);
  actU32toBE(&outBlock[8u],  X[1u]);
  actU32toBE(&outBlock[12u], X[0u]);

  actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */  /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
}

/**********************************************************************************************************************
 *  actSM4DecryptBlockCore()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_FUNC(void) actSM4DecryptBlockCore(
  VSECPRIM_P2CONST_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) inBlock,
  VSECPRIM_P2VAR_PARA(actU8) outBlock,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actU32 X[4u];

  /* load block */
  actCpyBEtoU32(X, inBlock, actSM4_BLOCK_SIZE);

# if (actSM4_SPEED_UP == 0u)  /* COV_VSECPRIM_NO_SAFE_CONFIG XX */
  {
    for (actLengthType i = 0u; i < 32u; i++)
    {
      actU32 tmp;

      /* three separate steps, to prevent compiler from expanding tau (S-box) macro multiple times */
      tmp         = X[(i + 1u) % 4u] ^ X[(i + 2u) % 4u] ^ X[(i + 3u) % 4u] ^ info->rk[31u - i];
      tmp         = actSM4_tau (tmp);      /* tmp = tau (X [i], rk [i]) */  /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
      X [i % 4u] ^= actSM4_L   (tmp);      /* X [i +4] = X [i] ^ T (X [i]) = X [i] ^ L (tau (X [i], rk [i])) */
    }
  }

# elif (actSM4_SPEED_UP == 1u)  /* COV_VSECPRIM_NO_SAFE_CONFIG XX */
  {
    for (actLengthType i = 0u; i < 32u; i++)
    {
      X[i % 4u] ^= actSM4_L_tau (X[(i + 1u) % 4u] ^ X[(i + 2u) % 4u] ^ X[(i + 3u) % 4u] ^ info->rk[31u - i]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    }
  }

# elif (actSM4_SPEED_UP == 2u)  /* COV_VSECPRIM_NO_SAFE_CONFIG XX */
  {
    for (actLengthType i = 0u; i < 32u; i += 4u)
    {
      X[0u] ^= actSM4_L_tau (X[1u] ^ X[2u] ^ X[3u] ^ info->rk[31u - i]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
      X[1u] ^= actSM4_L_tau (X[2u] ^ X[3u] ^ X[0u] ^ info->rk[30u - i]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
      X[2u] ^= actSM4_L_tau (X[3u] ^ X[0u] ^ X[1u] ^ info->rk[29u - i]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
      X[3u] ^= actSM4_L_tau (X[0u] ^ X[1u] ^ X[2u] ^ info->rk[28u - i]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    }
  }

# elif (actSM4_SPEED_UP == 3u)  /* COV_VSECPRIM_NO_SAFE_CONFIG XX */
  {
    X[0u] ^= actSM4_L_tau (X[1u] ^ X[2u] ^ X[3u] ^ info->rk[31u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[1u] ^= actSM4_L_tau (X[2u] ^ X[3u] ^ X[0u] ^ info->rk[30u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[2u] ^= actSM4_L_tau (X[3u] ^ X[0u] ^ X[1u] ^ info->rk[29u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[3u] ^= actSM4_L_tau (X[0u] ^ X[1u] ^ X[2u] ^ info->rk[28u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[0u] ^= actSM4_L_tau (X[1u] ^ X[2u] ^ X[3u] ^ info->rk[27u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[1u] ^= actSM4_L_tau (X[2u] ^ X[3u] ^ X[0u] ^ info->rk[26u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[2u] ^= actSM4_L_tau (X[3u] ^ X[0u] ^ X[1u] ^ info->rk[25u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[3u] ^= actSM4_L_tau (X[0u] ^ X[1u] ^ X[2u] ^ info->rk[24u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[0u] ^= actSM4_L_tau (X[1u] ^ X[2u] ^ X[3u] ^ info->rk[23u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[1u] ^= actSM4_L_tau (X[2u] ^ X[3u] ^ X[0u] ^ info->rk[22u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[2u] ^= actSM4_L_tau (X[3u] ^ X[0u] ^ X[1u] ^ info->rk[21u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[3u] ^= actSM4_L_tau (X[0u] ^ X[1u] ^ X[2u] ^ info->rk[20u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[0u] ^= actSM4_L_tau (X[1u] ^ X[2u] ^ X[3u] ^ info->rk[19u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[1u] ^= actSM4_L_tau (X[2u] ^ X[3u] ^ X[0u] ^ info->rk[18u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[2u] ^= actSM4_L_tau (X[3u] ^ X[0u] ^ X[1u] ^ info->rk[17u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[3u] ^= actSM4_L_tau (X[0u] ^ X[1u] ^ X[2u] ^ info->rk[16u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[0u] ^= actSM4_L_tau (X[1u] ^ X[2u] ^ X[3u] ^ info->rk[15u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[1u] ^= actSM4_L_tau (X[2u] ^ X[3u] ^ X[0u] ^ info->rk[14u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[2u] ^= actSM4_L_tau (X[3u] ^ X[0u] ^ X[1u] ^ info->rk[13u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[3u] ^= actSM4_L_tau (X[0u] ^ X[1u] ^ X[2u] ^ info->rk[12u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[0u] ^= actSM4_L_tau (X[1u] ^ X[2u] ^ X[3u] ^ info->rk[11u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[1u] ^= actSM4_L_tau (X[2u] ^ X[3u] ^ X[0u] ^ info->rk[10u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[2u] ^= actSM4_L_tau (X[3u] ^ X[0u] ^ X[1u] ^ info->rk[ 9u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[3u] ^= actSM4_L_tau (X[0u] ^ X[1u] ^ X[2u] ^ info->rk[ 8u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[0u] ^= actSM4_L_tau (X[1u] ^ X[2u] ^ X[3u] ^ info->rk[ 7u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[1u] ^= actSM4_L_tau (X[2u] ^ X[3u] ^ X[0u] ^ info->rk[ 6u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[2u] ^= actSM4_L_tau (X[3u] ^ X[0u] ^ X[1u] ^ info->rk[ 5u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[3u] ^= actSM4_L_tau (X[0u] ^ X[1u] ^ X[2u] ^ info->rk[ 4u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[0u] ^= actSM4_L_tau (X[1u] ^ X[2u] ^ X[3u] ^ info->rk[ 3u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[1u] ^= actSM4_L_tau (X[2u] ^ X[3u] ^ X[0u] ^ info->rk[ 2u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[2u] ^= actSM4_L_tau (X[3u] ^ X[0u] ^ X[1u] ^ info->rk[ 1u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
    X[3u] ^= actSM4_L_tau (X[0u] ^ X[1u] ^ X[2u] ^ info->rk[ 0u]); /* PRQA S 2985 */ /* MD_VSECPRIM_REDUNDANT_OP */
  }
# endif

  /* store block in reverse order */
  actU32toBE(outBlock,       X[3u]);
  actU32toBE(&outBlock[4u],  X[2u]);
  actU32toBE(&outBlock[8u],  X[1u]);
  actU32toBE(&outBlock[12u], X[0u]);

  actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */  /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
}

/**********************************************************************************************************************
 *  actSM4EncryptDecryptECB()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(void) actSM4EncryptDecryptECB(
  VSECPRIM_P2CONST_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) in,
  VSECPRIM_P2VAR_PARA(actU8) outBuffer,
  actLengthType blocks,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actLengthType idx = 0u;
  if (info->cryptMode == actSM4_ENCRYPT)
  {
    for (actLengthType bcount = 0u; bcount < blocks; ++bcount)
    {
      /* outBlock = Encrypt(inBlock) */
      actSM4EncryptBlockCore(info, &(in[idx]), &(outBuffer[idx]), watchdog);

      idx += actSM4_BLOCK_SIZE;
    }
  }
  else /* info->cryptMode == actSM4_DECRYPT */
  {
    for (actLengthType bcount = 0u; bcount < blocks; ++bcount)
    {
      /* outBlock = Decrypt(inBlock) */
      actSM4DecryptBlockCore(info, &(in[idx]), &(outBuffer[idx]), watchdog);

      idx += actSM4_BLOCK_SIZE;
    }
  }
}

/**********************************************************************************************************************
 *  actSM4EncryptDecryptCBC()
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
VSECPRIM_FUNC(void) actSM4EncryptDecryptCBC(
  VSECPRIM_P2VAR_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) in,
  VSECPRIM_P2VAR_PARA(actU8) outBuffer,
  actLengthType blocks,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  VSECPRIM_P2VAR_PARA(actU8) prevBlock = info->prevBlock;

  if (info->cryptMode == actSM4_ENCRYPT)
  {
    for (actLengthType bcount = 0u; bcount < blocks; ++bcount)
    {
      /*
       * In encryption CBC mode, the block is first XORed with the iv or the previous block
       * and after encrypted.
       */
      for (actLengthType i = 0u; i < actSM4_BLOCK_SIZE; ++i)
      {
        outBuffer[i] = (actU8)(prevBlock[i] ^ in[i]);
      }
      /* outBlock = Encrypt(outBlock) */
      actSM4EncryptBlockCore(info, outBuffer, outBuffer, watchdog);
      /* prevBlock = outBlock */
      for (actLengthType i = 0u; i < actSM4_BLOCK_SIZE; ++i)
      {
        prevBlock[i] = outBuffer[i];
      }

      outBuffer = &outBuffer[actSM4_BLOCK_SIZE];  /* PRQA S 1338 */ /* MD_VSECPRIM_PTR_REDEFINITION_SM4 */
      in = &in[actSM4_BLOCK_SIZE];                /* PRQA S 1338 */ /* MD_VSECPRIM_PTR_REDEFINITION_SM4 */
    }
  }
  else /* info->cryptMode == actSM4_DECRYPT */
  {
    for (actLengthType bcount = 0u; bcount < blocks; ++bcount)
    {
      /* A buffer is needed since inplace encryption is supported:
       * The information in blocks prevBlock and in are needed after decryption. Hence, it is not possible
       * to use outBuffer in actSM4DecryptBlockCore() since the information in block in are overwritten in the
       * case where outBuffer and in are pointers to the same address. */
      actU8 buffer[actSM4_BLOCK_SIZE] = {0u};

      /* In decryption CBC mode, the block is first decrypted and after XORed with the previous block. */
      actMemCpyByteArray(buffer, in, actSM4_BLOCK_SIZE);

      actSM4DecryptBlockCore(info, buffer, buffer, watchdog);
      /* outBlock = prevBlock ^ outBlock */
      /* prevBlock = inBlock */
      for (actLengthType i = 0u; i < actSM4_BLOCK_SIZE; ++i)
      {
        buffer[i] = buffer[i] ^ prevBlock[i];
        prevBlock[i] = in[i];
        outBuffer[i] = buffer[i];
      }

      outBuffer = &outBuffer[actSM4_BLOCK_SIZE]; /* PRQA S 1338 */ /* MD_VSECPRIM_PTR_REDEFINITION_SM4 */
      in = &in[actSM4_BLOCK_SIZE];               /* PRQA S 1338 */ /* MD_VSECPRIM_PTR_REDEFINITION_SM4 */
    }
  }
}

/**********************************************************************************************************************
 *  actSM4EncryptDecryptMultipleBlocks()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(void) actSM4EncryptDecryptMultipleBlocks(
  VSECPRIM_P2VAR_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) in,
  VSECPRIM_P2VAR_PARA(actU8) outBuffer,
  actLengthType blocks,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  switch (info->blockMode)
  {
  case actSM4_CBC:
    actSM4EncryptDecryptCBC(info, in, outBuffer, blocks, watchdog);
    break;
  default: /* actSM4_ECB */
    actSM4EncryptDecryptECB(info, in, outBuffer, blocks, watchdog);
    break;
  }
}

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTSM4_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  END OF FILE: actSM4c.c
 *********************************************************************************************************************/
