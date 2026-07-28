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
/**        \file  _EthTrcv_30_Ar7000_Cbk.c
 *        \brief  Ethernet transceiver driver QCA 7005 call back template source file
 *
 *      \details  Vector static code implementation template for the Ethernet transceiver driver QCA 7005 module.
 *                This file is a template file and shall be changed according to the customer needs.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file EthTrcv_30_Ar7000.h.
 *********************************************************************************************************************/

#define ETHTRCV_30_AR7000_CBK_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "_EthTrcv_30_Ar7000_Cbk.h"
#include "EthTrcv_30_Ar7000_Prot.h"
#include "EthTrcv_30_Ar7000_Trcv.h"

#if (ETHTRCV_30_AR7000_ENABLE_HASH_NID_EXAMPLE_FUNCTION == STD_ON)
#include "Crypto.h"
#endif /* ETHTRCV_30_AR7000_ENABLE_HASH_NID_EXAMPLE_FUNCTION */


/**********************************************************************************************************************
 * Local defines
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/
#define ETHTRCV_30_AR7000_START_SEC_CODE
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#if (ETHTRCV_30_AR7000_ENABLE_HASH_NID_EXAMPLE_FUNCTION == STD_ON)
/***********************************************************************************************************************
 *  Appl_TrcvHashNID
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) Appl_TrcvHashNID(                                                          /* PRQA S 6030, 6080 */ /* MD_MSR_STMCYC, MD_MSR_STMIF */
              P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) NmkPtr,
              P2VAR(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) HashedNid)
{
  Std_ReturnType retVal = E_NOT_OK; /* Return value of this function */
  Std_ReturnType resVal; /* Result value of called functions */
  eslt_WorkSpaceSHA256 workSpaceSha256;
  uint8 hashCount;

  /* #10 Hash the NMK */
  if ( ESL_ERC_NO_ERROR != esl_initWorkSpaceHeader(&workSpaceSha256.header, ESL_MAXSIZEOF_WS_SHA256, NULL_PTR) )
  {
    /* E_NOT_OK */
  }
  else if( ESL_ERC_NO_ERROR != esl_initSHA256(&workSpaceSha256) )
  {
    /* E_NOT_OK */
  }
  else if( ESL_ERC_NO_ERROR != esl_updateSHA256(&workSpaceSha256, ETHTRCV_30_AR7000_NMK_SIZE_BYTE, NmkPtr) )
  {
    /* E_NOT_OK */
  }
  else if( ESL_ERC_NO_ERROR != esl_finalizeSHA256(&workSpaceSha256, HashedNid) )
  {
    /* E_NOT_OK */
  }
  else
  {
    /* #20 Hash the newly formed hash value another 4 times */
    resVal = E_OK;
    for (hashCount = 0u; hashCount < 4u; hashCount++)
    {
      if( ESL_ERC_NO_ERROR != esl_initSHA256(&workSpaceSha256) )
      {
        resVal = E_NOT_OK;
      }
      else if( ESL_ERC_NO_ERROR != esl_updateSHA256(&workSpaceSha256, 32, HashedNid) ) /* SHA256 HashedNid has a size of 32 bytes */
      {
        resVal = E_NOT_OK;
      }
      else if(ESL_ERC_NO_ERROR != esl_finalizeSHA256(&workSpaceSha256, HashedNid))
      {
        resVal = E_NOT_OK;
      }
      else
      {
        /* E_OK */
      }

      if (resVal == E_NOT_OK)
      {
        break;
      }
    }
    if (resVal == E_OK)
    {
      /* #30 Shift last nibble of seventh byte (index 6) to the LS nibble in NID */
      HashedNid[ETHTRCV_30_AR7000_NID_SIZE_BYTE - 1u] = (uint8)(HashedNid[ETHTRCV_30_AR7000_NID_SIZE_BYTE - 1u] >> 4u);
      retVal = E_OK;
    }

    /* #40 This is your NID (the first seven byte) */
  }

  return retVal;
} 
#endif /* ETHTRCV_30_AR7000_ENABLE_HASH_NID_EXAMPLE_FUNCTION */

#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_SM_HOOK_ROUTINE )
/***********************************************************************************************************************
 *  Appl_TrcvHookRoutine
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
 /* PRQA S 3206 4 */ /* MD_EthTrcv_30_Ar7000_3206 */
FUNC(void, ETHTRCV_30_AR7000_CODE) Appl_TrcvHookRoutine(
    P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) DataPtr,
            uint16                                                           LenByte)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint16 MmType;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  ETHTRCV_30_AR7000_DUMMY_STATEMENT(LenByte);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  /* #10 Parse MAC Management Message Type from received ethernet frames and call the specific handle routines. */
  /* PRQA S 0310 2 */ /* MD_EthTrcv_30_Ar7000_0310 */
  MmType  =           (uint16)DataPtr[ETHTRCV_30_AR7000_MME_MMTYPE];
  MmType |= (uint16)(((uint16)DataPtr[ETHTRCV_30_AR7000_MME_MMTYPE + 1u]) << 8u);

  /* - Add your implementation */
  /* - For MMTypes and other useful protocol defines see EthTrcv_30_Ar7000_Trcv.h */
  /* - For available transceiver APIs see technical reference */
  switch (MmType)
  {
  case ETHTRCV_30_AR7000_MME_VS_MODULE_OPERATION | ETHTRCV_30_AR7000_MME_CNF:
    break;
  default:
    /* Ignore irrelevant MME frames, they may be handled by the EthTrcv_30_Ar7000 already */
    break;
  }


}
#endif /* ETHTRCV_30_AR7000_ENABLE_SM_HOOK_ROUTINE */

#define ETHTRCV_30_AR7000_STOP_SEC_CODE
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Ar7000_Cbk.c
 *********************************************************************************************************************/

