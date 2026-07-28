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
 *            Module: Eth_Ar7000
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Eth_30_Ar7000_Lcfg.c
 *   Generation Time: 2025-09-11 13:39:31
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
   LOCAL MISRA JUSTIFICATION
**********************************************************************************************************************/
/* PRQA S 777 EOF */ /* MD_MSR_Rule5.1  */

#define ETH_30_AR7000_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Eth_30_Ar7000_Lcfg.h"


/**********************************************************************************************************************
 *  PRIVATE MACROS
 *********************************************************************************************************************/
#ifndef STATIC
#define STATIC static
#endif /* STATIC */

/**********************************************************************************************************************
 *  RAM VARIABLES
 *********************************************************************************************************************/
#define ETH_30_AR7000_START_SEC_VAR_NOINIT_BUFFER
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* PRQA S 0612 L1 */ /* MD_Eth_30_Ar7000_0612 */
VAR(Eth_DataType, ETH_30_AR7000_VAR_NOINIT) Eth_30_Ar7000_RxBuffer_0_0[768];

VAR(Eth_DataType, ETH_30_AR7000_VAR_NOINIT) Eth_30_Ar7000_TxBuffer_0[768];

/* PRQA L:L1 */ /* MD_Eth_30_Ar7000_0612 */
#define ETH_30_AR7000_STOP_SEC_VAR_NOINIT_BUFFER
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define ETH_30_AR7000_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint8, ETH_30_AR7000_VAR_NOINIT) Eth_30_Ar7000_TxBufferBusyTable[2];
VAR(uint8, ETH_30_AR7000_VAR_NOINIT) Eth_30_Ar7000_UlTxConfState[2];

#define ETH_30_AR7000_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define ETH_30_AR7000_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Eth_PhysAddrType, ETH_30_AR7000_VAR_NOINIT) Eth_30_Ar7000_PhysSrcAddrs[ETH_30_AR7000_MAX_CTRLS_TOTAL];

#define ETH_30_AR7000_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define ETH_30_AR7000_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint8, ETH_30_AR7000_VAR_NOINIT) Eth_30_Ar7000_RxBufferBusyTable[2];

#define ETH_30_AR7000_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define ETH_30_AR7000_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

P2VAR(Eth_30_Ar7000_BaseSpiFlow, ETH_30_AR7000_VAR_NOINIT, ETH_30_AR7000_VAR_NOINIT) Eth_30_Ar7000_RingBuffer[17];
VAR(Eth_30_Ar7000_RegAccessSpiFlow, ETH_30_AR7000_VAR_NOINIT) Eth_30_Ar7000_RegFlows[10];
VAR(Eth_30_Ar7000_BufAccessSpiFlow, ETH_30_AR7000_VAR_NOINIT) Eth_30_Ar7000_BufFlows[6];

#define ETH_30_AR7000_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  ROM VARIABLES
 *********************************************************************************************************************/
#define ETH_30_AR7000_START_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(uint8, ETH_30_AR7000_CONST) Eth_30_Ar7000_RxQueueCntTotal[1] = 
{
  1u
};

CONST(uint8, ETH_30_AR7000_CONST) Eth_30_Ar7000_TxQueueCntTotal[1] = 
{
  1u
};



#define ETH_30_AR7000_STOP_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define ETH_30_AR7000_START_SEC_CONST_16BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
CONST(uint16, ETH_30_AR7000_CONST) Eth_30_Ar7000_TxBufferLen[2] =
{
  1518u, 
  1518u
};
#define ETH_30_AR7000_STOP_SEC_CONST_16BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define ETH_30_AR7000_START_SEC_CONST_32BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
CONST(uint32, ETH_30_AR7000_CONST) Eth_30_Ar7000_TxBufferStart[2] =
{
  2u, 
  1538u
};

#define ETH_30_AR7000_STOP_SEC_CONST_32BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
 
 
#define ETH_30_AR7000_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(Eth_30_Ar7000_RegBaseAddrType, ETH_30_AR7000_CONST)    Eth_30_Ar7000_RegBaseAddr[1] =
{
  0x00000000u
};


CONST(Eth_30_Ar7000_ConfigType, ETH_30_AR7000_CONST) Eth_30_Ar7000_Config = 0U;
CONST(Eth_PhysAddrType, ETH_30_AR7000_CONST) Eth_30_Ar7000_PhysSrcAddrsRom[ETH_30_AR7000_MAX_CTRLS_TOTAL] =
{
  {0x02U, 0x00U, 0x00U, 0x00U, 0x00U, 0x01U}
};

CONST(Eth_30_Ar7000_AlignedFrameCacheType, ETH_30_AR7000_CONST) Eth_30_Ar7000_Ctrl2TxBufferMap[1] = 
{
  {
    Eth_30_Ar7000_TxBuffer_0
  }
};

CONST(Eth_30_Ar7000_RxRing2BufMapType, ETH_30_AR7000_CONST) Eth_30_Ar7000_RxRing2BufMap_0[1] = {
  {
    {
      Eth_30_Ar7000_RxBuffer_0_0 /*  Buffer Pointers  */ 
    }, 
    1536u /*  Segment Size  */ , 
    1522u /*  Maximum Frame Size  */ , 
    1536u /*  Last Segment Size  */ , 
    2u /*  Segment Number  */ , 
    0u /*  Extended Segment Number  */ 
  }
};



#define ETH_30_AR7000_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */







/* module specific MISRA deviations:
 MD_Eth_30_Ar7000_0612:
      Reason:     Ethernet buffers may be larger than 32767 bytes in a total.
      Risk:       There is no risk. If memory is too small the linker complains.
      Prevention: No prevention necessary.
 MD_Eth_30_Ar7000_0750:
      Reason:     Ethernet buffer is accessed by an union. This allows accessing U8, U16 and U32 fields without casts
                  (and misra warnings of type 0310)
      Risk:       Depending on the buffer, an unaligned memory exception may occur on certain platforms.
      Prevention: The configuration tool ensures that all buffers are 4 bytes aligned. Reviewers check that access
                  to U16 fields always 2 bytes aligned and to U32 fields always 4 bytes aligned.
*/

/**********************************************************************************************************************
 *  END OF FILE: Eth_30_Ar7000_Lcfg.c
 *********************************************************************************************************************/
 

