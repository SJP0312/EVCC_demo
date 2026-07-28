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
 *              File: Eth_30_Ar7000_Lcfg.h
 *   Generation Time: 2025-09-11 13:39:31
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/


#if !defined(ETH_30_AR7000_LCFG_H)
#define ETH_30_AR7000_LCFG_H

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Eth_30_Ar7000_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define ETH_30_AR7000_UINT16_MAX_SIZE 65535U

#define ETH_30_AR7000_ISR_NO_OS_SUPPORT   0U
#define ETH_30_AR7000_ISR_CATEGORY_1      1U
#define ETH_30_AR7000_ISR_CATEGORY_2      2U



/**********************************************************************************************************************
 *  RTM MEASUREMENT POINT MACROS
 *********************************************************************************************************************/
/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define Eth_30_Ar7000_Rtm_Start(Type)

/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define Eth_30_Ar7000_Rtm_Stop(Type)

/**********************************************************************************************************************
 *  LOCAL <-> GLOBAL CONTROLLER INDEX TRANSFORMATION
 *********************************************************************************************************************/
/* PRQA S 3453 2 */ /* MD_MSR_FctLikeMacro */
#define Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx) \
              (uint8)((GlobalCtrlIdx) - ETH_30_AR7000_CTRL_IDX_OFFSET)

/* PRQA S 3453 2 */ /* MD_MSR_FctLikeMacro */
#define Eth_30_Ar7000_TransformToGlobalCtrlIdx(LocalCtrlIdx)   \
              (uint8)((LocalCtrlIdx) + ETH_30_AR7000_CTRL_IDX_OFFSET)


/**********************************************************************************************************************
 *  PHYSICAL SOURCE ADDRESS ACCESS MACROS
 *********************************************************************************************************************/
#define Eth_30_Ar7000_VPhysSrcAddr_0 (Eth_30_Ar7000_PhysSrcAddrs[0])
#define Eth_30_Ar7000_VPhysSrcAddrRomDefault_0 (Eth_30_Ar7000_PhysSrcAddrsRom[0])

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* PRQA S 0750 7 */ /* MD_Eth_30_Ar7000_0750 */
typedef union
{
  P2VAR(Eth_DataType, ETH_30_AR7000_VAR_NOINIT, ETH_30_AR7000_VAR_NOINIT) Native;
  P2VAR(uint32      , ETH_30_AR7000_VAR_NOINIT, ETH_30_AR7000_VAR_NOINIT) U32;
  P2VAR(uint16      , ETH_30_AR7000_VAR_NOINIT, ETH_30_AR7000_VAR_NOINIT) U16;
  P2VAR(uint8       , ETH_30_AR7000_VAR_NOINIT, ETH_30_AR7000_VAR_NOINIT) U8;
} Eth_30_Ar7000_AlignedFrameCacheType;

typedef struct
{
  Eth_30_Ar7000_AlignedFrameCacheType BufPtr;
  uint16                    SegmentSize;
  uint16                    MaximumFrameSize;
  uint16                    LastSegmentSize;
  uint16                    SegmentNumber;
  uint16                    ExtSegmentNumber;
} Eth_30_Ar7000_RxRing2BufMapType;

typedef uint32 Eth_30_Ar7000_RegBaseAddrType;


#if ((defined ETH_30_AR7000_ENABLE_MAC_WRITE_ACCESS) && (STD_ON == ETH_30_AR7000_ENABLE_MAC_WRITE_ACCESS))
typedef struct
{
   boolean          EthIsMacAddrWriteAccess;
   NvM_BlockIdType  EthNvMBlockDesc;
} Eth_30_Ar7000_CtrlMacAddrBlockIdType;
#endif /* ETH_30_AR7000_ENABLE_MAC_WRITE_ACCESS */

  

/* Flow structures */
typedef uint8 Eth_30_Ar7000_SendNextSpiSeq_ReturnType;

typedef struct Eth_30_Ar7000_BaseSpiFlowStruct
{
    uint8 type;
    uint8 id;
    uint8 flags;
    uint8 state;
    P2VAR(struct Eth_30_Ar7000_BaseSpiFlowStruct, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT) nextFlow;
    Eth_30_Ar7000_EndNotificationFctType EndNotification;
    uint8 cmdWord_1[2];
    uint8 regData_1[2];
    boolean flowTransmissionFailed;
#if ( defined ETH_30_AR7000_SM_TRACE )
    uint32 debugUid;
#endif
} Eth_30_Ar7000_BaseSpiFlow;

typedef struct
{
    Eth_30_Ar7000_BaseSpiFlow base;
} Eth_30_Ar7000_RegAccessSpiFlow;

typedef struct
{
    Eth_30_Ar7000_BaseSpiFlow base;
    uint8 cmdWord_2[2];
    uint8 regData_2[2];
    uint8 cmdWord_3[2];
#if ( defined ETH_30_AR7000_SM_TRACE )
    uint8 magicNr1;
#endif
    uint8 bufIdx;
#if ( defined ETH_30_AR7000_SM_TRACE )
    uint8 magicNr2;
#endif
    uint16 dataSize;
    boolean txConfirmation;
    uint8 linkedFlowId;
} Eth_30_Ar7000_BufAccessSpiFlow;


  
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define ETH_30_AR7000_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, ETH_30_AR7000_VAR_NOINIT)                                  Eth_30_Ar7000_TxBufferBusyTable[ETH_30_AR7000_TX_BUF_TOTAL];
extern VAR(uint8, ETH_30_AR7000_VAR_NOINIT)                                  Eth_30_Ar7000_UlTxConfState[ETH_30_AR7000_TX_BUF_TOTAL];

#define ETH_30_AR7000_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define ETH_30_AR7000_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Eth_PhysAddrType, ETH_30_AR7000_VAR_NOINIT)                       Eth_30_Ar7000_PhysSrcAddrs[ETH_30_AR7000_MAX_CTRLS_TOTAL];

#define ETH_30_AR7000_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
  
#define ETH_30_AR7000_START_SEC_VAR_NOINIT_BUFFER
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* PRQA S 0612 L1 */ /* MD_Eth_0612 */
extern VAR(Eth_DataType, ETH_30_AR7000_VAR_NOINIT)                           Eth_30_Ar7000_TxBuffer_0[768];
extern VAR(Eth_DataType, ETH_30_AR7000_VAR_NOINIT)                           Eth_30_Ar7000_RxBuffer_0_0[768];
/* PRQA L:L1 */ /* MD_Eth_0612 */
#define ETH_30_AR7000_STOP_SEC_VAR_NOINIT_BUFFER
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define ETH_30_AR7000_START_SEC_CONST_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint8, ETH_30_AR7000_CONST)                                     Eth_30_Ar7000_RxQueueCntTotal[1];
extern CONST(uint8, ETH_30_AR7000_CONST)                                     Eth_30_Ar7000_TxQueueCntTotal[1];


#define ETH_30_AR7000_STOP_SEC_CONST_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define ETH_30_AR7000_START_SEC_CONST_16BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern CONST(uint16, ETH_30_AR7000_CONST)                                    Eth_30_Ar7000_TxBufferLen[ETH_30_AR7000_TX_BUF_TOTAL];
#define ETH_30_AR7000_STOP_SEC_CONST_16BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define ETH_30_AR7000_START_SEC_CONST_32BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern CONST(uint32, ETH_30_AR7000_CONST)                                    Eth_30_Ar7000_TxBufferStart[2];
#define ETH_30_AR7000_STOP_SEC_CONST_32BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define ETH_30_AR7000_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(Eth_30_Ar7000_RegBaseAddrType, ETH_30_AR7000_CONST)                       Eth_30_Ar7000_RegBaseAddr[1];
extern CONST(Eth_30_Ar7000_ConfigType, ETH_30_AR7000_CONST)                            Eth_30_Ar7000_Config;
extern CONST(Eth_PhysAddrType, ETH_30_AR7000_CONST)                          Eth_30_Ar7000_PhysSrcAddrsRom[ETH_30_AR7000_MAX_CTRLS_TOTAL];
extern CONST(Eth_30_Ar7000_AlignedFrameCacheType, ETH_30_AR7000_CONST)                 Eth_30_Ar7000_Ctrl2TxBufferMap[1];
/* PRQA S 777 Eth_SignificantChars */ /* MD_Eth_SignificantChars */
extern CONST(Eth_30_Ar7000_RxRing2BufMapType, ETH_30_AR7000_CONST)                     Eth_30_Ar7000_RxRing2BufMap_0[1];
/* PRQA L:Eth_SignificantChars */

#define ETH_30_AR7000_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */



/**********************************************************************************************************************
 *  VARIANT DEPENDENT GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
#define ETH_30_AR7000_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern P2VAR(Eth_30_Ar7000_BaseSpiFlow, ETH_30_AR7000_VAR_NOINIT, ETH_30_AR7000_VAR_NOINIT)      Eth_30_Ar7000_RingBuffer[17];
extern VAR(Eth_30_Ar7000_RegAccessSpiFlow, ETH_30_AR7000_VAR_NOINIT)                   Eth_30_Ar7000_RegFlows[10];
extern VAR(Eth_30_Ar7000_BufAccessSpiFlow, ETH_30_AR7000_VAR_NOINIT)                   Eth_30_Ar7000_BufFlows[6];
#define ETH_30_AR7000_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
 
#define ETH_30_AR7000_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(uint8, ETH_30_AR7000_VAR_NOINIT)                                  Eth_30_Ar7000_RxBufferBusyTable[2];
#define ETH_30_AR7000_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* ETH_30_AR7000_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Eth_30_Ar7000_Lcfg.h
 *********************************************************************************************************************/

 
