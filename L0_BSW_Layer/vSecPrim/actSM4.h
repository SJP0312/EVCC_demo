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
/*!        \file  actSM4.h
 *        \brief  Interface to core SM4 implementation.
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

#ifndef ACTSM4_H
# define ACTSM4_H

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
extern "C"
{
# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actSM4Init()
 *********************************************************************************************************************/
/*! \brief          This function initializes an SM4 encryption/decryption process.
 *  \details        - Mode and bufferUsed are set in the info struct.
 *                  - In the CBC mode, the initialization vector is set in the info struct.
 *                  - The cipher key is expanded to the round keys via the key expansion algorithm in section 7.3
 *                    of the SM4 documentation:
 *                     www.gmbz.org.cn/upload/2018-04-04/1522788048733065051.pdf
 *  \param[in,out]  info      (in)  Pointer to SM4 context structure.
 *                            (out) Initialized SM4 context structure.
 *  \param[in]      key       Pointer to the cipher key.
 *  \param[in]      iv        Pointer to the initialization vector. A null pointer is valid.
 *                            If iv is a null pointer in CBC mode, the buffer prevBlock in the info struct
 *                            is overwritten with 0s.
 *  \param[in]      mode      Flag for the block mode.
 *  \param[in]      watchdog  Pointer to the watchdog trigger function.
 *  \pre            - Provided pointers must be valid.
 *                  - Parameter mode must be actSM4_CBC or actSM4_ECB.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSM4Init(
  VSECPRIM_P2VAR_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) key,
  VSECPRIM_P2CONST_PARA(actU8) iv,
  actU8 mode,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSM4KeySetup()
 *********************************************************************************************************************/
/*! \brief          Round keys generation.
 *  \details        This function expands the cipher key to the round keys via the key expansion algorithm described
 *                  in section 7.3 of the SM4 documentation:
 *                    www.gmbz.org.cn/upload/2018-04-04/1522788048733065051.pdf
 *  \param[in,out]  info      (in)  Pointer to SM4 context structure.
 *                            (out) SM4 context structure with initialized round keys.
 *  \param[in]      key       Pointer to the cipher key.
 *  \param[in]      watchdog  Pointer to the watchdog trigger function.
 *  \pre            - Provided pointers must be valid.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSM4KeySetup(
  VSECPRIM_P2VAR_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) key,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSM4EncryptBlockCore()
 *********************************************************************************************************************/
/*! \brief          SM4 encryption of one block
 *  \details        This function encrypts one block according to the SM4 encryption algorithm described in
 *                  section 7.1 of
 *                      www.gmbz.org.cn/upload/2018-04-04/1522788048733065051.pdf
 *                  To improve the efficiency of the encryption, look up tables may be used and loops may be
 *                  unrolled via configuration.
 *  \param[in]      info      Pointer to SM4 context structure.
 *  \param[in]      inBlock   Pointer to the block to encrypt.
 *  \param[in,out]  outBlock  (in)  Pointer to buffer to store the encrypted block.
 *                            (out) Pointer to the encrypted block.
 *  \param[in]      watchdog  Pointer to the watchdog trigger function.
 *  \pre            - Provided pointers must be valid.
 *                  - inBlock and outBlock must provide at least actSM4_BLOCK_SIZE bytes.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSM4EncryptBlockCore(
  VSECPRIM_P2CONST_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) inBlock,
  VSECPRIM_P2VAR_PARA(actU8) outBlock,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSM4DecryptBlockCore()
 *********************************************************************************************************************/
/*! \brief          SM4 decryption of one block
 *  \details        This function decrypts one block according to the SM4 encryption algorithm described in
 *                  section 7.2 of
 *                      www.gmbz.org.cn/upload/2018-04-04/1522788048733065051.pdf
 *                  To improve the efficiency of the decryption, look up tables may be used and loops may be
 *                  unrolled via configuration.
 *  \param[in]      info      Pointer to SM4 context structure.
 *  \param[in]      inBlock   Pointer to the block to decrypt.
 *  \param[in,out]  outBlock  (in)  Pointer to buffer to store the decrypted block.
 *                            (out) Pointer to the decrypted block.
 *  \param[in]      watchdog  Pointer to the watchdog trigger function.
 *  \pre            - Provided pointers must be valid.
 *                  - inBlock and outBlock must provide at least actSM4_BLOCK_SIZE bytes.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSM4DecryptBlockCore(
  VSECPRIM_P2CONST_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) inBlock,
  VSECPRIM_P2VAR_PARA(actU8) outBlock,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSM4EncryptDecryptECB()
 *********************************************************************************************************************/
/*! \brief          Encryption/Decryption in ECB mode.
 *  \details        This function processes a fixed amount of blocks according to the ECB mode.
 *                  for all blocks in encrypt/decrypt case:
 *                  - encrypt/decrypt the block.
 *                  - concatenate the encrypted/decrypted block to the output buffer.
 *  \param[in]      info      Pointer to SM4 context structure.
 *  \param[in]      in        Pointer to the blocks to encrypt/decrypt.
 *  \param[in,out]  outBuffer (in)  Pointer to buffer to store the encrypted/decrypted blocks.
 *                            (out) Pointer to the encrypted/decrypted blocks.
 *  \param[in]      blocks    Number of blocks to process contained in input parameter 'in'.
 *  \param[in]      watchdog  Pointer to the watchdog trigger function.
 *  \pre            - Provided pointers must be valid.
 *                  - in and outBuffer must provide at least (actSM4_BLOCK_SIZE * blocks) bytes.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSM4EncryptDecryptECB(
  VSECPRIM_P2CONST_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) in,
  VSECPRIM_P2VAR_PARA(actU8) outBuffer,
  actLengthType blocks,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSM4EncryptDecryptCBC()
 *********************************************************************************************************************/
/*! \brief          Encryption/Decryption in CBC mode.
 *  \details        This function processes a fixed amount of blocks according to the CBC mode.
 *                  For all blocks in the encryption case:
 *                  - XOR the previous block with the block to encrypt (first previous block is the initialization
 *                    vector)
 *                  - Encrypt the resulted block
 *                  - The encrypted block is copied to the previous block buffer and concatenate to the output buffer
 *                  For all blocks in the decryption case:
 *                  - Decrypt the in block
 *                  - XOR the previous block with the decrypted block (first previous block is the initialization
 *                    vector)
 *                  - The result concatenate to the output buffer
 *                  - The in block is copied to the previous block buffer
 *  \param[in,out]  info      (in)  Pointer to SM4 context structure.
 *                            (out) SM4 context structure with actual buffer and prevBlock.
 *  \param[in]      in        Pointer to the blocks to encrypt/decrypt.
 *  \param[in,out]  outBuffer (in)  Pointer to buffer to store the encrypted/decrypted blocks.
 *                            (out) Pointer to the encrypted/decrypted blocks.
 *  \param[in]      blocks    Number of blocks to process contained in input parameter in.
 *  \param[in]      watchdog  Pointer to the watchdog trigger function.
 *  \pre            - Provided pointers must be valid.
 *                  - in and outBuffer must provide at least (actSM4_BLOCK_SIZE * blocks) bytes.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSM4EncryptDecryptCBC(
  VSECPRIM_P2VAR_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) in,
  VSECPRIM_P2VAR_PARA(actU8) outBuffer,
  actLengthType blocks,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSM4EncryptDecryptMultipleBlocks()
 *********************************************************************************************************************/
/*! \brief          Encrypt/Decrypt multiple block input.
 *  \details        This function calls the correct mode function, depending on the information
                    saved in info->blockMode.
 *  \param[in,out]  info      (in)  Pointer to SM4 context structure.
 *                            (out) SM4 context structure with actual buffer and prevBlock.
 *  \param[in]      in        Pointer to the blocks to encrypt/decrypt.
 *  \param[in,out]  outBuffer (in)  Pointer to buffer to store the encrypted/decrypted blocks.
 *                            (out) Pointer to the encrypted/decrypted blocks.
 *  \param[in]      blocks    Number of blocks to process contained in input parameter in.
 *  \param[in]      watchdog  Pointer to the watchdog trigger function.
 *  \pre            - Provided pointers must be valid.
 *                  - in and outBuffer must provide at least (actSM4_BLOCK_SIZE * blocks) bytes.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSM4EncryptDecryptMultipleBlocks(
  VSECPRIM_P2VAR_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) in,
  VSECPRIM_P2VAR_PARA(actU8) outBuffer,
  actLengthType blocks,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
} /* extern "C" */
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /*  ACTSM4_H  */

/**********************************************************************************************************************
 *  END OF FILE: actSM4.h
 *********************************************************************************************************************/
