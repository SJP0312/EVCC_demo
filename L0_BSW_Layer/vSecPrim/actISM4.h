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
/*!        \file  actISM4.h
 *        \brief  Interface for SM4 implementation.
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

#ifndef ACTISM4_H
# define ACTISM4_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "actITypes.h"

# ifdef __cplusplus /* COV_VSECPRIM_CPLUSPLUS XF */
    extern "C" {
# endif

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  actSM4InitEncryptDecrypt()
 *********************************************************************************************************************/
/*! \brief          Call actSM4Init()
 *  \details        -
 *  \param[in,out]  info      (in)  Pointer to SM4 context structure.
 *                            (out) Initialized SM4 context structure.
 *  \param[in]      key       Pointer to the cipher key.
 *  \param[in]      iv        Pointer to the initialization vector. A null pointer is valid.
 *  \param[in]      mode      Flag for the block mode. It must be actSM4_CBC or actSM4_ECB.
 *  \param[in]      watchdog  Pointer to the watchdog trigger function.
 *  \pre            - Provided pointers must be valid.
 *                  - Parameter mode must be actSM4_CBC or actSM4_ECB.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSM4InitEncryptDecrypt(
  VSECPRIM_P2VAR_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) key,
  VSECPRIM_P2CONST_PARA(actU8) iv,
  actU8 mode,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSM4EncryptDecrypt()
 *********************************************************************************************************************/
/*! \brief          SM4 encryption/decryption of data.
 *  \details        This function handles the input data together with the data already saved in the info buffer in
 *                  order to correctly call actSM4EncryptDecryptMultipleBlocks().
 *                  Since actSM4EncryptDecryptMultipleBlocks() only processes a fixed amount of blocks, this function
 *                  evaluates the provided data and copies the rest into the info buffer for the next
 *                  actSM4EncryptDecrypt() call or the actSM4FinalizeEncryptDecrypt() call.
 *                  Steps:
 *                  - If (info->bufferUsed + inLength) <= actSM4_BLOCK_SIZE, the in data is concatenated to
 *                    info buffer data. No data is encrypted/decrypted and the output length is set to 0.
 *                  - Else:
 *                    - The nbr of blocks to process during this function call is computed together with the length
 *                      of the rest to copy into info buffer.
 *                    - If the output buffer is to small, return an error
 *                    - Else:
 *                      - Fill up the info buffer and process the block info buffer
 *                      - Proceed the other blocks
 *                      - Copy the rest to info buffer (1 to 16 bytes)
 *                      - Set the output length
 *  \param[in,out]  info        (in)  Pointer to SM4 context structure.
 *                              (out) SM4 context structure with actual buffer and prevBlock.
 *  \param[in]      in          Pointer to the data to encrypt/decrypt.
 *  \param[in]      inLength    Length in bytes of the data to encrypt/decrypt.
 *  \param[in,out]  outBuffer   (in)  Pointer to the output buffer.
 *                              (out) Pointer to the encrypted/decrypted data.
 *  \param[in,out]  outLength   (in)  Pointer to the length of the provided output buffer.
 *                              (out) Pointer to the length of the encrypted/decrypted data.
 *  \param[in]      watchdog    Pointer to the watchdog trigger function.
 *  \return         - actEXCEPTION_OUTPUT_BUFFER if the output buffer is too small
 *                  - actOK, else.
 *  \pre            - Provided pointers must be valid.
 *                  - outLength >= ((inLength + bufferUsed - 1u) / actSM4_BLOCK_SIZE) * actSM4_BLOCK_SIZE
 *                    where bufferUsed is a parameter of the info struct and / is the integer division.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSM4EncryptDecrypt(
  VSECPRIM_P2VAR_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) in,
  actLengthType inLength,
  VSECPRIM_P2VAR_PARA(actU8) outBuffer,
  VSECPRIM_P2VAR_PARA(actLengthType) outLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSM4FinalizeEncryptDecrypt()
 *********************************************************************************************************************/
/*! \brief          Finalize the SM4 encryption/decryption.
 *  \details        This function finalizes the SM4 encryption/decryption algorithm. SM4 does not support padding,
 *                  the complete length of the input data must be a multiple of actSM4_BLOCK_SIZE.
 *                  Steps:
 *                  - Check that exact actSM4_BLOCK_SIZE bytes are used in the info buffer.
 *                  - Encrypt/Decrypt the last block.
 *  \param[in,out]  info      (in)  Pointer to SM4 context structure which contains in buffer the last block to
 *                                  encrypt/decrypt.
 *                            (out) Pointer to SM4 context structure.
 *  \param[in,out]  outBuffer (in)  Pointer to the output buffer.
 *                            (out) Pointer to the last encrypted/decrypted block.
 *  \param[in]      watchdog  Pointer to the watchdog trigger function.
 *  \return         - actEXCEPTION_INPUT_LENGTH, if the total length of the input data in the precedent calls of
 *                    actSM4EncryptDecrypt() is 0 or not a multiple of actSM4_BLOCK_SIZE.
 *                  - actOK, else.
 *  \pre            - Provided pointers must be valid.
 *                  - outBuffer must provide at least actSM4_BLOCK_SIZE bytes.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSM4FinalizeEncryptDecrypt(
  VSECPRIM_P2VAR_PARA(actSM4STRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) outBuffer,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSM4InitEncryptDecryptBlock()
 *********************************************************************************************************************/
/*! \brief          Initialize the encryption/decryption of one block.
 *  \details        This function calls the actSM4KeySetup() function.
 *  \param[in,out]  info      (in)  Pointer to SM4 context structure.
 *                            (out) Pointer to SM4 context structure with initialized rounds key.
 *  \param[in]      key       Pointer to the cipher key.
 *  \param[in]      watchdog  Pointer to the watchdog trigger function.
 *  \pre            - Provided pointers must be valid.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSM4InitEncryptDecryptBlock(
  VSECPRIM_P2VAR_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) key,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSM4EncryptDecryptBlock()
 *********************************************************************************************************************/
/*! \brief          SM4 encryption/decryption of one block.
 *  \details        -
 *  \param[in]      info      Pointer to SM4 context structure.
 *  \param[in]      inBlock   Pointer to the input block.
 *  \param[in,out]  outBlock  (in)  Pointer to the output buffer.
 *                            (out) Pointer the encrypted/decrypted block.
 *  \param[in]      watchdog  Pointer to the watchdog trigger function.
 *  \pre            - Provided pointers must be valid.
 *                  - outBlock must provide at least actSM4_BLOCK_SIZE bytes.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSM4EncryptDecryptBlock(
  VSECPRIM_P2CONST_PARA(actSM4STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) inBlock,
  VSECPRIM_P2VAR_PARA(actU8) outBlock,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus  /* COV_VSECPRIM_CPLUSPLUS XF */
    }  /*  extern "C"  */
# endif

#endif /* ACTISM4_H */

/**********************************************************************************************************************
 *  END OF FILE: actISM4.h
 *********************************************************************************************************************/
