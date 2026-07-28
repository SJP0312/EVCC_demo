/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Slac
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Slac_Lcfg.c
 *   Generation Time: 2025-09-11 13:39:31
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/


#define SLAC_LCFG_SOURCE

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
#include "Slac_LCfg.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/
#define SLAC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Slac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/* This is a variable because the EthIf_Transmit() API does not accept a pointer to a CONST address */
VAR(Eth_PhysAddrType, SLAC_VAR_NOINIT) Slac_PlcChipPhysAddress;

#define SLAC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Slac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */


#define SLAC_START_SEC_CONST_8
#include "Slac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/* NID and NMK for default NMK: 'HomePlugAV' */
CONST(uint8, SLAC_CONST) Slac_DefaultNid[SLAC_MME_NID_LEN] =
{
  0xB0u, 0xF2u, 0xE6u, 0x95u, 0x66u, 0x6Bu, 0x03u
};
CONST(uint8, SLAC_CONST) Slac_DefaultNmk[SLAC_MME_NMK_LEN] =
{
  0x50u, 0xD3u, 0xE4u, 0x93u, 0x3Fu, 0x85u, 0x5Bu, 0x70u, 0x40u, 0x78u, 0x4Du, 0xF8u, 0x15u, 0xAAu, 0x8Du, 0xB7u
};

#define SLAC_STOP_SEC_CONST_8
#include "Slac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  END OF FILE: Slac_LCfg.c
 **********************************************************************************************************************/

