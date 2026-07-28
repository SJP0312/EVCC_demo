/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  _EthTrcv_30_Ar7000_Cbk.h
 *        \brief  Ethernet transceiver driver QCA 7005 call back template header file
 *
 *      \details  Vector static code header file template for the Ethernet transceiver driver QCA 7005 module. 
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

#ifndef _ETHTRCV_30_AR7000_TRCV_CBK_H
#define _ETHTRCV_30_AR7000_TRCV_CBK_H


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "EthTrcv_30_Ar7000.h"
#include "EthTrcv_30_Ar7000_Trcv.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define ETHTRCV_30_AR7000_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#if (ETHTRCV_30_AR7000_ENABLE_HASH_NID_EXAMPLE_FUNCTION == STD_ON)
/***********************************************************************************************************************
 *  Appl_TrcvHashNID
 **********************************************************************************************************************/
/*!
 * \brief       Calculates the NID from a given NMK using SHA256 hashes.
 * \details     -
 * \param[in]     NmkPtr          Pointer to the buffer storing the input NMK
 * \param[in,out] HashedNid       Pointer to the buffer where the resulting NID shall be copied to
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      ETHTRCV_30_AR7000_ENABLE_HASH_NID_EXAMPLE_FUNCTION
 */
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) Appl_TrcvHashNID(
              P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) NmkPtr,
              P2VAR(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) HashedNid);
#endif /* ETHTRCV_30_AR7000_ENABLE_HASH_NID_EXAMPLE_FUNCTION */

#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_SM_HOOK_ROUTINE )
/***********************************************************************************************************************
 *  Appl_TrcvHookRoutine
 **********************************************************************************************************************/
/*!
 * \brief       All MMEs get forwarded to this hook routine to implement own sate machines.
 * \details     -
 * \param[in]   DataPtr         DataPointer to the MME beginning with the MMV field.
 * \param[in]   LenByte         Length of MME message.
 * \pre         -
 * \context     ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \config      ETHTRCV_30_AR7000_ENABLE_SM_HOOK_ROUTINE
 */
FUNC(void, ETHTRCV_30_AR7000_CODE) Appl_TrcvHookRoutine(
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) DataPtr,
          uint16                                                           LenByte);
#endif /* ETHTRCV_30_AR7000_ENABLE_SM_HOOK_ROUTINE */


#define ETHTRCV_30_AR7000_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#endif  /* _ETHTRCV_30_AR7000_TRCV_CBK_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Ar7000_Cbk.h
 *********************************************************************************************************************/
