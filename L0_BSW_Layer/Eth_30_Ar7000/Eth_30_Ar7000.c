/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Eth_30_Ar7000.c
 *        \brief  Ethernet driver QCA 7005 main source file
 *
 *      \details  Vector static code implementation for the Ethernet driver QCA 7005 module.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file Eth_30_Ar7000.h.
 *********************************************************************************************************************/

#define ETH_30_AR7000_SOURCE

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Eth_30_Ar7000.h"
#include "Eth_30_Ar7000_Priv.h"
#include "Eth_30_Ar7000_AthEth.h"
#include "EthIf_Cbk.h"
#if ((defined ETH_30_AR7000_ENABLE_MAC_WRITE_ACCESS) && (STD_ON == ETH_30_AR7000_ENABLE_MAC_WRITE_ACCESS))
#include "NvM.h"
#endif
/* ETH_30_AR7000_ENABLE_MAC_WRITE_ACCESS */
#include "IpBase.h"
#include "EthTrcv_30_Ar7000.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* vendor specific version information is BCD coded */
#if (  (ETH_30_AR7000_SW_MAJOR_VERSION != (0x09U)) \
    || (ETH_30_AR7000_SW_MINOR_VERSION != (0x00U)) \
    || (ETH_30_AR7000_SW_PATCH_VERSION != (0x02U)) )
  #error "Vendor specific version numbers of Eth_30_Ar7000.c and Eth.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define ETH_30_AR7000_SPI_INV_LINK                                       0xFFU

#define ETH_30_AR7000_MAX_INTR_REQ_POLLING_MODE                             2U

/* ETH_30_AR7000 VLAN TPID according to IEEE802.1Q */
#define ETH_30_AR7000_VLAN_TPID                                        0x8100U
#define ETH_30_AR7000_VLAN_TAG_LENGTH                                       4U


#if !defined (ETH_30_AR7000_LOCAL)
# define ETH_30_AR7000_LOCAL static
#endif

#if !defined (ETH_30_AR7000_LOCAL_INLINE)
# define ETH_30_AR7000_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define ETH_30_AR7000_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */

ETH_30_AR7000_LOCAL VAR(Eth_ModeType, ETH_30_AR7000_VAR_NOINIT)                      Eth_30_Ar7000_CtrlMode[ETH_30_AR7000_MAX_CTRLS_TOTAL];
ETH_30_AR7000_LOCAL VAR(Eth_30_Ar7000_CpuModeType, ETH_30_AR7000_VAR_NOINIT)         Eth_30_Ar7000_CpuMode;
ETH_30_AR7000_LOCAL VAR(uint8, ETH_30_AR7000_VAR_NOINIT)                             Eth_30_Ar7000_RetryCnt;

ETH_30_AR7000_LOCAL VAR(uint8, ETH_30_AR7000_VAR_NOINIT)                             Eth_30_Ar7000_RingBufNextPos;
ETH_30_AR7000_LOCAL VAR(uint8, ETH_30_AR7000_VAR_NOINIT)                             Eth_30_Ar7000_RingBufCurProcFlow;

#if ((STD_OFF == ETH_30_AR7000_ENABLE_TX_INTERRUPT) && (STD_OFF == ETH_30_AR7000_ENABLE_RX_INTERRUPT))
ETH_30_AR7000_LOCAL VAR(uint8, ETH_30_AR7000_VAR_NOINIT)                             Eth_30_Ar7000_IntrCauseReqPending;
#endif /* ETH_30_AR7000_ENABLE_TX_INTERRUPT && ETH_30_AR7000_ENABLE_RX_INTERRUPT */

#if ((STD_ON == ETH_30_AR7000_ENABLE_TX_INTERRUPT) && (STD_ON == ETH_30_AR7000_ENABLE_RX_INTERRUPT))
ETH_30_AR7000_LOCAL VAR(boolean, ETH_30_AR7000_VAR_NOINIT)                           Eth_30_Ar7000_InterruptEnableRetry[ETH_30_AR7000_MAX_CTRLS_TOTAL];
#endif /* ETH_30_AR7000_ENABLE_TX_INTERRUPT && ETH_30_AR7000_ENABLE_RX_INTERRUPT */

#if ( STD_ON == ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT )
ETH_30_AR7000_LOCAL VAR(uint8, ETH_30_AR7000_VAR_NOINIT)                             Eth_30_Ar7000_ReadSignatureAttempts;
ETH_30_AR7000_LOCAL VAR(boolean, ETH_30_AR7000_VAR_NOINIT)                           Eth_30_Ar7000_RxDropCnt;
#endif /* ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT */

#if (STD_ON == ETH_30_AR7000_ENABLE_UPDATE_PHYS_ADDR_FILTER)
ETH_30_AR7000_LOCAL VAR(uint8, ETH_30_AR7000_VAR_NOINIT)                             Eth_30_Ar7000_PromiscousModeCnt[ETH_30_AR7000_MAX_CTRLS_TOTAL];
#endif /* ETH_30_AR7000_ENABLE_UPDATE_PHYS_ADDR_FILTER */

#define ETH_30_AR7000_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define ETH_30_AR7000_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
ETH_30_AR7000_LOCAL VAR(Eth_StateType, ETH_30_AR7000_VAR_ZERO_INIT)                  Eth_30_Ar7000_ModuleInitialized = ETH_STATE_UNINIT;
#endif /* ETH_30_AR7000_DEV_ERROR_DETECT */

#define ETH_30_AR7000_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define ETH_30_AR7000_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define ETH_30_AR7000_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define ETH_30_AR7000_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */

ETH_30_AR7000_LOCAL VAR(uint32, ETH_30_AR7000_VAR_NOINIT) Eth_30_Ar7000_CycleCnt;


#define ETH_30_AR7000_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define ETH_30_AR7000_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */

ETH_30_AR7000_LOCAL P2VAR(Eth_30_Ar7000_RegAccessSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT) Eth_30_Ar7000_FreeRegFlowAnchor;
ETH_30_AR7000_LOCAL P2VAR(Eth_30_Ar7000_BufAccessSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT) Eth_30_Ar7000_FreeBufFlowAnchor;

#define ETH_30_AR7000_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define ETH_30_AR7000_START_SEC_CODE
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VGetPacket
 *********************************************************************************************************************/
/*! \brief      Triggers a packet transaction from QCA7005 to host.
 *  \details    -
 *  \param[in]  LocalCtrlIdx                  Identifier of the Ethernet controller
 *  \pre        -
 *  \context    TASK|ISR2
 *  \reentrant  TRUE
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VGetPacket(
    uint8 LocalCtrlIdx);

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VSendNextSpiSeq
 *********************************************************************************************************************/
/*! \brief      Controls the flow of SPI bus protocol.
 *  \details    -
 *  \param[in]  LocalCtrlIdx                            Identifier of the Ethernet controller
 *  \return     ETH_30_AR7000_SEND_NEXT_SPI_SEQ_OK      Everything is OK. Wait until reception
 *  \return     ETH_30_AR7000_SEND_NEXT_SPI_SEQ_END     Everything is OK. Nothing to do anymore
 *  \return     ETH_30_AR7000_SEND_NEXT_SPI_SEQ_BUSY    Everything is OK. Nothing to do anymore
 *  \return     ETH_30_AR7000_SEND_NEXT_SPI_SEQ_NOT_OK  SPI transfer could not be triggered
 *  \pre        -
 *  \context    TASK|ISR2
 *  \reentrant  TRUE
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(Eth_30_Ar7000_SendNextSpiSeq_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_VSendNextSpiSeq(
    uint8 LocalCtrlIdx);

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VPushFlowToSLL
 *********************************************************************************************************************/
/*! \brief      Pushes the given flow element back to the free element pool.
 *  \details    -
 *  \param[in]  LocalCtrlIdx                  Identifier of the Ethernet controller
 *  \param[in]  Element                       flow object
 *  \pre        This function has to be called within an active critical section (interrupts are locked)
 *  \context    TASK|ISR2
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VPushFlowToSLL (
          uint8                                                          LocalCtrlIdx,
    P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA) Element );

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VPopFlowFromSLL
 *********************************************************************************************************************/
/*! \brief      Reserves a free buffer flow element.
 *  \details    -
 *  \param[in]  LocalCtrlIdx                  Identifier of the Ethernet controller
 *  \param[in]  FlowType                      Type of flow
 *  \param[out] Element                       Pointer to flow object
 *  \return     E_OK     - free flow object found
 *  \return     E_NOT_OK - no free flow object available
 *  \pre        This function has to be called within an active critical section (interrupts are locked)
 *  \context    TASK|ISR2
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(Std_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_VPopFlowFromSLL (
          uint8                                                           LocalCtrlIdx,
          uint8                                                           FlowType,
    P2VAR(Eth_30_Ar7000_BaseSpiFlow*, AUTOMATIC, ETH_30_AR7000_APPL_DATA) Element );

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VPopLinkedFlowsFromSLL
 *********************************************************************************************************************/
/*! \brief      Reserves two buffer flow elements.
 *  \details    Takes two buffer flows and reserves it. Method grants that either two or no flow is reserved.
 *  \param[in]  LocalCtrlIdx                  Identifier of the Ethernet controller
 *  \param[in]  FirstElement                  Type of flow
 *  \param[out] LinkedElement                 Pointer to flow object
 *  \return     E_OK     - two free buffer flow elements reserved and linked together
 *  \return     E_NOT_OK - no free buffers flow elements available
 *  \pre        This function has to be called within an active critical section (interrupts are locked)
 *  \context    TASK|ISR2
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(Std_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_VPopLinkedFlowsFromSLL(
          uint8                                                                LocalCtrlIdx,
    P2VAR(Eth_30_Ar7000_BufAccessSpiFlow*, AUTOMATIC, ETH_30_AR7000_APPL_DATA) FirstElement,
    P2VAR(Eth_30_Ar7000_BufAccessSpiFlow*, AUTOMATIC, ETH_30_AR7000_APPL_DATA) LinkedElement);

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VAddToRingBuffer
 *********************************************************************************************************************/
/*! \brief      Adds a flow to the ring buffer waiting for transmission.
 *  \details    -
 *  \param[in]  LocalCtrlIdx                  Identifier of the Ethernet controller
 *  \param[out] Flow                          Pointer to flow object
 *  \pre        This function has to be called within an active critical section (interrupts are locked)
 *  \context    TASK|ISR2
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VAddToRingBuffer(
          uint8                                                          LocalCtrlIdx,
    P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA) Flow );

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VIncProcPointer
 *********************************************************************************************************************/
/*! \brief      Sets current processing element.
 *  \details    -
 *  \param[in]  LocalCtrlIdx                  Identifier of the Ethernet controller
 *  \pre        This function has to be called within an active critical section (interrupts are locked)
 *  \context    TASK|ISR2
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VIncProcPointer(
    uint8 LocalCtrlIdx);

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VInterruptCauseNotification
 *********************************************************************************************************************/
/*! \brief      Callback after ETH_SPI_REG_INTR_CAUSE register of QCA7005 is read.
 *  \details    -
 *  \param[in]  GlobalCtrlIdx                 Identifier of the Ethernet controller
 *  \param[in]  FlowId                        Id of flow causing the notification
 *  \pre        -
 *  \context    ISR2
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VInterruptCauseNotification(
    uint8 GlobalCtrlIdx,
    uint8 FlowId);

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VWriteSpiConfirmation
 *********************************************************************************************************************/
/*! \brief      Pushes allocated flow element to free elements pool.
 *  \details    -
 *  \param[in]  GlobalCtrlIdx                 Identifier of the Ethernet controller
 *  \param[in]  FlowId                        Identifier of flow element
 *  \pre        -
 *  \context    TASK|ISR2
 *  \reentrant  TRUE for different flow id's
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VWriteSpiConfirmation(
    uint8 GlobalCtrlIdx,
    uint8 FlowId);

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VOnCpuRunning
 *********************************************************************************************************************/
/*! \brief      Further initialization after QCA7005-CPU is running.
 *  \details    -
 *  \param[in]  GlobalCtrlIdx                 Identifier of the Ethernet controller
 *  \param[in]  FlowId                        Identifier of flow element
 *  \pre        CPU of QCA7005 is running
 *  \context    TASK|ISR2
 *  \reentrant  TRUE for different flow id's
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VOnCpuRunning(
    uint8 GlobalCtrlIdx,
    uint8 FlowId);

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VReceive
 *********************************************************************************************************************/
/*! \brief      Requests a Ethernet-Frame from the QCA7005
 *  \details    -
 *  \param[in]  GlobalCtrlIdx                 Identifier of the Ethernet controller
 *  \param[in]  FlowId                        Identifier of flow element
 *  \pre        -
 *  \context    TASK|ISR2
 *  \reentrant  TRUE for different flow id's
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VReceive(
    uint8 GlobalCtrlIdx,
    uint8 FlowId);

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VCheckSpiHeader
 *********************************************************************************************************************/
/*! \brief      Verifies QCA7005 SPI-Header
 *  \details    -
 *  \param[in]  GlobalCtrlIdx                 Identifier of the Ethernet controller
 *  \param[in]  FlowId                        Identifier of flow element
 *  \pre        -
 *  \context    TASK|ISR2
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VCheckSpiHeader(
    uint8 GlobalCtrlIdx,
    uint8 FlowId);

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VTxConfirmation
 *********************************************************************************************************************/
/*! \brief      Informs upper layer about tx confirmation
 *  \details    This function is used instead of the Eth_30_Ar7000_TxConfirmation due to the interrupt driver
 *              communication to the QCA7005 chip.
 *  \param[in]  GlobalCtrlIdx                 Identifier of the Ethernet controller
 *  \param[in]  FlowId                        Identifier of flow element
 *  \pre        -
 *  \context    TASK|ISR2
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VTxConfirmation(
    uint8 GlobalCtrlIdx,
    uint8 FlowId);

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VFilterMacAddr
 *********************************************************************************************************************/
/*! \brief      Filters incoming frames according to the destination MAC address
 *  \details    -
 *  \param[in]  LocalCtrlIdx                  Identifier of the Ethernet controller
 *  \param[in]  DestMacAddr                   Destination MAC address filter
 *  \return     E_OK                          MAC address is valid
 *  \return     E_NOT_OK                      MAC address is not valid
 *  \pre        Must be called with an active ISR lock section (ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0) to protect
 *              the variable Eth_30_Ar7000_PromiscousModeCnt.
 *  \context    TASK|ISR2
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(Std_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_VFilterMacAddr(
            uint8                                  LocalCtrlIdx,
    P2CONST(uint8, AUTOMATIC, ETH_30_AR7000_CONST) DestMacAddr);

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VIsBroadcast
 *********************************************************************************************************************/
/*! \brief      Checks whether the MAC address is the broadcast address
 *  \details    -
 *  \param[in]  PhysAddrPtr                   MAC address that shall be checked
 *  \return     TRUE                          MAC address is broadcast address
 *  \return     FALSE                         MAC address isn't broadcast address
 *  \pre        -
 *  \context    TASK|ISR2
 *  \reentrant  TRUE
 */
ETH_30_AR7000_LOCAL FUNC(boolean, ETH_30_AR7000_CODE) Eth_30_Ar7000_VIsBroadcast(
    P2CONST(uint8, AUTOMATIC, ETH_30_AR7000_APPL_DATA) PhysAddrPtr);

#if ( STD_ON == ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT )
/**********************************************************************************************************************
 *  Eth_30_Ar7000_VOutOfSyncDetect
 *********************************************************************************************************************/
/*! \brief      Reads QCA7005-SPI signature register
 *  \details    -
 *  \param[in]  GlobalCtrlIdx                 Identifier of the Ethernet controller
 *  \param[in]  FlowId                        Identifier of flow element
 *  \pre        CPU of QCA7005 is running
 *  \context    TASK|ISR2
 *  \reentrant  FALSE
 *  \config     ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VOutOfSyncDetect(
    uint8 GlobalCtrlIdx,
    uint8 FlowId);
#endif /* ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT */

#if (STD_ON == ETH_30_AR7000_ENABLE_SPI_BUF_ERR_DETECT)
/**********************************************************************************************************************
 *  Eth_30_Ar7000_VSpiStatus
 *********************************************************************************************************************/
/*! \brief      Reads QCA7005-SPI status register
 *  \details    -
 *  \param[in]  GlobalCtrlIdx                 Identifier of the Ethernet controller
 *  \param[in]  FlowId                        Identifier of flow element
 *  \pre        CPU of QCA7005 is running
 *  \context    TASK|ISR2
 *  \reentrant  TRUE for different flow id's
 *  \config     ETH_30_AR7000_ENABLE_SPI_BUF_ERR_DETECT
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VSpiStatus(
    uint8 GlobalCtrlIdx,
    uint8 FlowId);
#endif /* ETH_30_AR7000_ENABLE_SPI_BUF_ERR_DETECT */

/* States of state machine */
/**********************************************************************************************************************
 *  Eth_30_Ar7000_VSMStateNA
 *********************************************************************************************************************/
/*! \brief      State NA of state machine, transition to RegData1
 *  \details    -
 *  \param[in]  LocalCtrlIdx                  Identifier of the Ethernet controller
 *  \return     ETH_SEND_NEXT_SPI_SEQ_OK      Everything is OK. Wait until reception
 *  \return     ETH_SEND_NEXT_SPI_SEQ_END     Everything is OK. Nothing to do anymore
 *  \return     ETH_SEND_NEXT_SPI_SEQ_NOT_OK  SPI transfer could not be triggered
 *  \pre        -
 *  \context    TASK|ISR2
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(Eth_30_Ar7000_SendNextSpiSeq_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_VSMStateNA(
    uint8 LocalCtrlIdx);

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VSMStateRegData1
 *********************************************************************************************************************/
/*! \brief      State RegData1 of state machine.
 *  \details    Send/Receive register 1
 *  \param[in]  LocalCtrlIdx                  Identifier of the Ethernet controller
 *  \return     ETH_SEND_NEXT_SPI_SEQ_OK      Everything is OK. Wait until reception
 *  \return     ETH_SEND_NEXT_SPI_SEQ_END     Everything is OK. Nothing to do anymore
 *  \return     ETH_SEND_NEXT_SPI_SEQ_NOT_OK  SPI transfer could not be triggered
 *  \pre        -
 *  \context    TASK|ISR2
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(Eth_30_Ar7000_SendNextSpiSeq_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_VSMStateRegData1(
    uint8 LocalCtrlIdx);

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VSMStateRegData2
 *********************************************************************************************************************/
/*! \brief      State RegData2 of state machine.
 *  \details    Send/Receive register 2
 *  \param[in]  LocalCtrlIdx                  Identifier of the Ethernet controller
 *  \return     ETH_SEND_NEXT_SPI_SEQ_OK      Everything is OK. Wait until reception
 *  \return     ETH_SEND_NEXT_SPI_SEQ_END     Everything is OK. Nothing to do anymore
 *  \return     ETH_SEND_NEXT_SPI_SEQ_NOT_OK  SPI transfer could not be triggered
 *  \pre        -
 *  \context    TASK|ISR2
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(Eth_30_Ar7000_SendNextSpiSeq_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_VSMStateRegData2(
    uint8 LocalCtrlIdx);

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VSMStateData
 *********************************************************************************************************************/
/*! \brief      State Data of state machine.
 *  \details    Send/Receive data
 *  \param[in]  LocalCtrlIdx                  Identifier of the Ethernet controller
 *  \return     ETH_SEND_NEXT_SPI_SEQ_OK      Everything is OK. Wait until reception
 *  \return     ETH_SEND_NEXT_SPI_SEQ_END     Everything is OK. Nothing to do anymore
 *  \return     ETH_SEND_NEXT_SPI_SEQ_NOT_OK  SPI transfer could not be triggered
 *  \pre        -
 *  \context    TASK|ISR2
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(Eth_30_Ar7000_SendNextSpiSeq_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_VSMStateData(
    uint8 LocalCtrlIdx);

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VSMStateEnd
 *********************************************************************************************************************/
/*! \brief      State End of state machine.
 *  \details    Unset used flag, notify user, increase proc pointer
 *  \param[in]  LocalCtrlIdx                  Identifier of the Ethernet controller
 *  \pre        A critical section must be active, due to this function will release one more critical section
 *              as it does activate.
 *  \context    TASK|ISR2
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VSMStateEnd(
    uint8 LocalCtrlIdx);

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VSendNextSpiSeq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
ETH_30_AR7000_LOCAL FUNC(Eth_30_Ar7000_SendNextSpiSeq_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_VSendNextSpiSeq(
    uint8 LocalCtrlIdx)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Eth_30_Ar7000_SendNextSpiSeq_ReturnType retVal = ETH_30_AR7000_SEND_NEXT_SPI_SEQ_END; /* Return value of this function */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();

  /* #10 verify pending elements
   *     if no new elements found
   *       return immediately
   */
  if ( Eth_30_Ar7000_RingBufCurProcFlow != Eth_30_Ar7000_RingBufNextPos )
  {

    /* #20 Control the flow of the SPI bus protocol (like a state machine manager) */
    /* The state transitions are placed within each state */
    if ( ETH_30_AR7000_SPI_FLOW_STATE_NA == Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->state )
    {
      retVal = Eth_30_Ar7000_VSMStateNA(LocalCtrlIdx);
    }
    else if ( ETH_30_AR7000_SPI_FLOW_STATE_REGDATA1 == Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->state )
    {
      retVal = Eth_30_Ar7000_VSMStateRegData1(LocalCtrlIdx);
    }
    else if ( ETH_30_AR7000_SPI_FLOW_STATE_REGDATA2 == Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->state )
    {
      retVal = Eth_30_Ar7000_VSMStateRegData2(LocalCtrlIdx);
    }
    else if ( ETH_30_AR7000_SPI_FLOW_STATE_DATA == Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->state )
    {
      retVal = Eth_30_Ar7000_VSMStateData(LocalCtrlIdx);
    }
    else
    {
      /* nothing to do */
    }

    if ( ETH_30_AR7000_SPI_FLOW_STATE_END == Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->state )
    {
      /* Call Eth_30_Ar7000_VSMStateEnd with an active critical section. The critical section will be closed inside the function */
      Eth_30_Ar7000_VSMStateEnd(LocalCtrlIdx);                                                                          /* PRQA S 1520 */ /* MD_Eth_30_Ar7000_RecursiveCalls */
    }
    else
    {
      ETH_30_AR7000_END_CRITICAL_SECTION_0();
    }
  }
  else
  {
    ETH_30_AR7000_END_CRITICAL_SECTION_0();
  }
  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VPushFlowToSLL
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VPushFlowToSLL(
          uint8                                                          LocalCtrlIdx,
    P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA) Element )
{
  /* --------------------------------- Dummy statement for unused variables ---------------------------------------- */
  ETH_30_AR7000_DUMMY_STATEMENT(LocalCtrlIdx);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Push the used spi flow control element back to the free elements pool
   *     Reset flags and state
   *     Update free elements list
   */
  Element->flags = 0;
  Element->state = ETH_30_AR7000_SPI_FLOW_STATE_NA;

  if (ETH_30_AR7000_SPI_FLOW_TYPE_REG == Element->type )
  {
    Element->nextFlow = (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA))Eth_30_Ar7000_FreeRegFlowAnchor; /* PRQA S 0310 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
    Eth_30_Ar7000_FreeRegFlowAnchor = (P2VAR(Eth_30_Ar7000_RegAccessSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT))Element; /* PRQA S 0310, 2916 */ /* MD_Eth_30_Ar7000_SpiFLowCast, MD_Eth_30_Ar7000_SpiFLowPointerLifeTime */
  }
  else
  {
    /* delete the link between to to elements (in addition to the FreeRegFlowAnchor) */
    /* PRQA S 0310 1 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
    P2VAR(Eth_30_Ar7000_BufAccessSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT) BufFlow = (P2VAR(Eth_30_Ar7000_BufAccessSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT))Element;
    BufFlow->linkedFlowId = ETH_30_AR7000_SPI_INV_LINK;

    Element->nextFlow = (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA))Eth_30_Ar7000_FreeBufFlowAnchor; /* PRQA S 0310 */ /* MD_Eth_30_Ar7000_SpiFLowCast */

    Eth_30_Ar7000_FreeBufFlowAnchor = BufFlow;                                                                          /* PRQA S 2916 */ /* MD_Eth_30_Ar7000_SpiFLowPointerLifeTime */
  }
}

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VPopFlowFromSLL
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
ETH_30_AR7000_LOCAL FUNC(Std_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_VPopFlowFromSLL(
          uint8                                                           LocalCtrlIdx,
          uint8                                                           FlowType,
    P2VAR(Eth_30_Ar7000_BaseSpiFlow*, AUTOMATIC, ETH_30_AR7000_APPL_DATA) Element)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* Return value of this function */

  /* --------------------------------- Dummy statement for unused variables ---------------------------------------- */
  ETH_30_AR7000_DUMMY_STATEMENT(LocalCtrlIdx);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Pop a free spi flow control element from the free elements pool
   *     if register access type is requested
   *       verify that a free element can be supplied from the FreeRegFlowAnchor list
   *       pop element from list
   *       update list
   *     else
   *       verify that a free element can be supplied from the FreeBufFlowAnchor list
   *       pop element from list
   *       update list
   */
  if ( ETH_30_AR7000_SPI_FLOW_TYPE_REG == FlowType )
  {

    if ( (Eth_30_Ar7000_RegAccessSpiFlow*)NULL_PTR != Eth_30_Ar7000_FreeRegFlowAnchor )
    {
      /* PRQA S 0310 2 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
      *Element = (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA))Eth_30_Ar7000_FreeRegFlowAnchor;
      Eth_30_Ar7000_FreeRegFlowAnchor = (P2VAR(Eth_30_Ar7000_RegAccessSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT))Eth_30_Ar7000_FreeRegFlowAnchor->base.nextFlow;
      (*Element)->flowTransmissionFailed = FALSE;

      retVal = E_OK;
    }
    else
    {
      /* no free flows */
    }

  }
  else
  {
    if ( (Eth_30_Ar7000_BufAccessSpiFlow*)NULL_PTR != Eth_30_Ar7000_FreeBufFlowAnchor )
    {
      /* PRQA S 0310 2 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
      *Element = (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA))Eth_30_Ar7000_FreeBufFlowAnchor;
      Eth_30_Ar7000_FreeBufFlowAnchor = (P2VAR(Eth_30_Ar7000_BufAccessSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT))Eth_30_Ar7000_FreeBufFlowAnchor->base.nextFlow;
      (*Element)->flowTransmissionFailed = FALSE;

      retVal = E_OK;
    }
    else
    {
      /* no free flows */
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VPopLinkedFlowsFromSLL
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
 */
ETH_30_AR7000_LOCAL FUNC(Std_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_VPopLinkedFlowsFromSLL(
          uint8                                                                LocalCtrlIdx,
    P2VAR(Eth_30_Ar7000_BufAccessSpiFlow*, AUTOMATIC, ETH_30_AR7000_APPL_DATA) FirstElement,
    P2VAR(Eth_30_Ar7000_BufAccessSpiFlow*, AUTOMATIC, ETH_30_AR7000_APPL_DATA) LinkedElement)
{

  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* Return value of this function */
  Std_ReturnType resVal; /* Result value of called functions */

  /* -------------------------------------------- Implementation --------------------------------------------------- */
  /* #10 Get first spi flow control element */
  /* Get flow to read length information */
  /* PRQA S 0310 2 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
  resVal = Eth_30_Ar7000_VPopFlowFromSLL(LocalCtrlIdx, ETH_30_AR7000_SPI_FLOW_TYPE_BUF,
      (P2VAR(Eth_30_Ar7000_BaseSpiFlow*, AUTOMATIC, ETH_30_AR7000_APPL_DATA))FirstElement);

  /* #20 If first element was successful requested
   *       Get second spi flow control element
   *       If second element was successful requested
   *         Link both (1st & 2nd) together
   *       else
   *         Push first element back to the free elements pool
   */
  if ( E_OK == resVal)
  {
    /* Get flow to read payload information */
    /* PRQA S 0310 2 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
    resVal = Eth_30_Ar7000_VPopFlowFromSLL(LocalCtrlIdx, ETH_30_AR7000_SPI_FLOW_TYPE_BUF,
        (P2VAR(Eth_30_Ar7000_BaseSpiFlow*, AUTOMATIC, ETH_30_AR7000_APPL_DATA))LinkedElement);
    if (E_OK == resVal)
    {
      /* link header and payload flows together */
      (*FirstElement)->linkedFlowId = (*LinkedElement)->base.id;

      retVal = E_OK;
    }
    else
    {
      /* There is no free flow structure available - try to increase number of flows */

      /* push last flow back to SSL */
      /* PRQA S 0310 1 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
      Eth_30_Ar7000_VPushFlowToSLL(LocalCtrlIdx, (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA))*FirstElement);
    }
  }
  else
  {
    /* There is no free flow structure available - try to increase number of flows */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VAddToRingBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VAddToRingBuffer(
          uint8                                                          LocalCtrlIdx,
    P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA) Flow)
{
  /* --------------------------------- Dummy statement for unused variables ---------------------------------------- */
  ETH_30_AR7000_DUMMY_STATEMENT(LocalCtrlIdx);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Add spi flow control element to ring buffer */
  Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufNextPos] = (Eth_30_Ar7000_BaseSpiFlow*)Flow;

  /* #20 set ringer buffer index to next position */
  if ( ETH_30_AR7000_MAX_FLOWS_TOTAL > Eth_30_Ar7000_RingBufNextPos)
  {
    Eth_30_Ar7000_RingBufNextPos++;
  }
  else
  {
    Eth_30_Ar7000_RingBufNextPos = 0;
  }
}

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VIncProcPointer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VIncProcPointer(
    uint8 LocalCtrlIdx)
{
  /* --------------------------------- Dummy statement for unused variables ---------------------------------------- */
  ETH_30_AR7000_DUMMY_STATEMENT(LocalCtrlIdx);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 set current processing ring buffer index */
  if ( ETH_30_AR7000_MAX_FLOWS_TOTAL > Eth_30_Ar7000_RingBufCurProcFlow )
  {
    Eth_30_Ar7000_RingBufCurProcFlow++;
  }
  else
  {
    Eth_30_Ar7000_RingBufCurProcFlow = 0;
  }
}

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VInterruptCauseNotification
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
 */
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VInterruptCauseNotification(
    uint8 GlobalCtrlIdx,
    uint8 FlowId)
{
  /* Callback after ETH_SPI_REG_INTR_CAUSE register of QCA7005 is read */
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Eth_30_Ar7000_SpiReqIntrCauseFlagsType interruptCauseFlags = 0;
  Eth_30_Ar7000_ReturnType resVal; /* Result value of called functions */
  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
#if ((STD_OFF == ETH_30_AR7000_ENABLE_TX_INTERRUPT) && (STD_OFF == ETH_30_AR7000_ENABLE_RX_INTERRUPT))
  if (Eth_30_Ar7000_IntrCauseReqPending > 0U)
  {
    Eth_30_Ar7000_IntrCauseReqPending--;
  }
#endif /* ETH_30_AR7000_ENABLE_TX_INTERRUPT && ETH_30_AR7000_ENABLE_RX_INTERRUPT */

  /* #10 Read SPI result */
  resVal = Eth_30_Ar7000_GetReadSpiResult(GlobalCtrlIdx, FlowId, &interruptCauseFlags);

  /* #20 If the QCA7005 cpu is ON
   *       If 'read SPI result' is OK
   *         verify that a package is available before try to get the package from the QCA7005
   *         If RX/TX_INTERRUPTS are enabled
   *           Enable QCA7005 PACKET_AVAILABLE interrupt
   */
  if ( Eth_30_Ar7000_CpuMode == ETH_30_AR7000_CPU_ON )
  {
    if ( ETH_30_AR7000_RT_OK == resVal )
    {
      if ( ( interruptCauseFlags & ETH_30_AR7000_SPI_INTR_PACKET_AVAILABLE ) == ETH_30_AR7000_SPI_INTR_PACKET_AVAILABLE)
      {
        Eth_30_Ar7000_VGetPacket(localCtrlIdx);
      }
#if ((STD_ON == ETH_30_AR7000_ENABLE_TX_INTERRUPT) && (STD_ON == ETH_30_AR7000_ENABLE_RX_INTERRUPT))
      else
      {
        ETH_30_AR7000_BEGIN_CRITICAL_SECTION_1();
        /* Enable interrupts */
        if ( E_NOT_OK == Eth_30_Ar7000_WriteSpi(GlobalCtrlIdx, ETH_30_AR7000_SPI_REG_INTR_ENABLE, ETH_30_AR7000_SPI_INTEN_ENABLE) )
        {
          Eth_30_Ar7000_InterruptEnableRetry[localCtrlIdx] = TRUE;
        }
        else
        {
          Eth_30_Ar7000_InterruptEnableRetry[localCtrlIdx] = FALSE;
        }
        ETH_30_AR7000_END_CRITICAL_SECTION_1();
      }
#endif /* ETH_30_AR7000_ENABLE_TX_INTERRUPT && ETH_30_AR7000_ENABLE_RX_INTERRUPT */

    }
  }
}

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VGetPacket
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
 *
 *
 *
 *
 */
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VGetPacket(
    uint8 LocalCtrlIdx)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2VAR(Eth_30_Ar7000_BufAccessSpiFlow, AUTOMATIC, AUTOMATIC) spiLengthFlow = NULL_PTR;
  P2VAR(Eth_30_Ar7000_BufAccessSpiFlow, AUTOMATIC, AUTOMATIC) spiPayloadFlow = NULL_PTR;
  Std_ReturnType resVal; /* Result value of called functions */
  uint8 bufferIdx = 0;
  boolean isBufReserved = FALSE;
#if ( STD_ON == ETH_30_AR7000_ENABLE_DET_ON_SPI_BUS_ERROR )
  uint8 globalCtrlIdx = Eth_30_Ar7000_TransformToGlobalCtrlIdx(LocalCtrlIdx);                                           /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */
#endif /* ETH_30_AR7000_ENABLE_DET_ON_SPI_BUS_ERROR */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();

  /* #10 Get two linked spi flow control elements */
  resVal = Eth_30_Ar7000_VPopLinkedFlowsFromSLL(LocalCtrlIdx, &spiLengthFlow, &spiPayloadFlow);

  /* #20 Try to get a free RX buffer
   *     Mark the buffer as busy (if we found a free buffer)
   */
  if (E_OK == resVal)
  {
    /* get read buffer */
    while( ETH_30_AR7000_RX_BUF_TOTAL > bufferIdx )
    {
      if( (uint8)0 == Eth_30_Ar7000_RxBufferBusyTable[bufferIdx] )
      {
        break;
      }
      bufferIdx++;
    }

    if( ETH_30_AR7000_RX_BUF_TOTAL > bufferIdx )
    {
      Eth_30_Ar7000_RxBufferBusyTable[bufferIdx] = 1;
      /* Buffer is reserved, go on... */
      isBufReserved = TRUE;
    }
  }

  ETH_30_AR7000_END_CRITICAL_SECTION_0();

  /* #30 If we have a free RX buffer
   *       Prepare spi flow control elements for packet transaction from QCA7005 to host
   *       Add the two spi flow control elements to the ring buffer
   *     Else if don't have a free RX buffer
   *       Push the two allocated spi flow control elements back to the free elements pool
   */
  if (TRUE == isBufReserved)
  {
    /* Link buffer index to flows */
    spiLengthFlow->bufIdx = bufferIdx;
    spiPayloadFlow->bufIdx = bufferIdx;
    /* Command words */
    spiLengthFlow->base.cmdWord_1[0]   = ETH_30_AR7000_SPI_CMD_WORD_I_FLAG_MASK;
    spiLengthFlow->base.cmdWord_1[0]  |= ETH_30_AR7000_SPI_CMD_WORD_R_FLAG_MASK;
    spiLengthFlow->base.cmdWord_1[0]  |= (uint8)(( ETH_30_AR7000_SPI_REG_RDBUF_BYTE_AVA & ETH_30_AR7000_SPI_CMD_WORD_ADDR_HIGH_MASK ) >> 8);
    spiLengthFlow->base.cmdWord_1[1]   = (uint8)( ETH_30_AR7000_SPI_REG_RDBUF_BYTE_AVA & ETH_30_AR7000_SPI_CMD_WORD_ADDR_LOW_MASK );
    spiPayloadFlow->base.cmdWord_1[0]  = spiLengthFlow->base.cmdWord_1[0];
    spiPayloadFlow->base.cmdWord_1[1]  = spiLengthFlow->base.cmdWord_1[1];

    spiLengthFlow->cmdWord_2[0]   = ETH_30_AR7000_SPI_CMD_WORD_I_FLAG_MASK;
    spiLengthFlow->cmdWord_2[0]  &= (uint8)(~(uint32)ETH_30_AR7000_SPI_CMD_WORD_R_FLAG_MASK);
    spiLengthFlow->cmdWord_2[0]  |= (uint8)(( ETH_30_AR7000_SPI_REG_BFR_SIZE & ETH_30_AR7000_SPI_CMD_WORD_ADDR_HIGH_MASK ) >> 8);
    spiLengthFlow->cmdWord_2[1]   = (uint8)( ETH_30_AR7000_SPI_REG_BFR_SIZE & ETH_30_AR7000_SPI_CMD_WORD_ADDR_LOW_MASK  );
    spiPayloadFlow->cmdWord_2[0]  = spiLengthFlow->cmdWord_2[0];
    spiPayloadFlow->cmdWord_2[1]  = spiLengthFlow->cmdWord_2[1];

    spiLengthFlow->regData_2[0] = 0;
    spiLengthFlow->regData_2[1] = ETH_30_AR7000_SPI_HWGEN_LENGTH & (uint8)0xFF;
    spiLengthFlow->dataSize     = ETH_30_AR7000_SPI_HWGEN_LENGTH;

    spiLengthFlow->cmdWord_3[0]  = ETH_30_AR7000_SPI_CMD_WORD_R_FLAG_MASK;
    spiPayloadFlow->cmdWord_3[0] = ETH_30_AR7000_SPI_CMD_WORD_R_FLAG_MASK;

    /* Callback */
    spiLengthFlow->base.EndNotification  = Eth_30_Ar7000_VCheckSpiHeader;
    spiPayloadFlow->base.EndNotification = Eth_30_Ar7000_VReceive;

    /* flags */
    spiLengthFlow->base.flags  |= ETH_30_AR7000_SPI_FLOW_FLAG_READ_MASK;
    spiPayloadFlow->base.flags  = spiLengthFlow->base.flags;

    /* Add to buffer */
    ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();
    /* PRQA S 0310 2 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
    Eth_30_Ar7000_VAddToRingBuffer(LocalCtrlIdx, (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA))spiLengthFlow);
    Eth_30_Ar7000_VAddToRingBuffer(LocalCtrlIdx, (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA))spiPayloadFlow);
    ETH_30_AR7000_END_CRITICAL_SECTION_0();
  }
  else if (E_OK == resVal)
  {
    ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();
    /* push the elements back to the free elements pool */
    /* PRQA S 0310 2 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
    Eth_30_Ar7000_VPushFlowToSLL(LocalCtrlIdx, (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA)) spiLengthFlow);
    Eth_30_Ar7000_VPushFlowToSLL(LocalCtrlIdx, (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA)) spiPayloadFlow);
    ETH_30_AR7000_END_CRITICAL_SECTION_0();
  }
  else
  {
    /* don't care */
  }

  /* #40 Trigger processing of SPI working queue */
  /* #50 If state execution return NOT_OK AND ETH_30_AR7000_ENABLE_DET_ON_SPI_BUS_ERROR is enabled
   *       Throw fatal SPI error
   */
  if ( ETH_30_AR7000_SEND_NEXT_SPI_SEQ_NOT_OK == Eth_30_Ar7000_VSendNextSpiSeq(LocalCtrlIdx) )
  {
#if ( STD_ON == ETH_30_AR7000_ENABLE_DET_ON_SPI_BUS_ERROR )
    /* Fatal Spi error */
    (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, globalCtrlIdx, ETH_30_AR7000_API_ID_GET_PACKET, ETH_30_AR7000_E_SPI_PROT_ERROR);
#endif /* ETH_30_AR7000_ENABLE_DET_ON_SPI_BUS_ERROR */
  }
}

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VWriteSpiConfirmation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VWriteSpiConfirmation(
    uint8 GlobalCtrlIdx,
    uint8 FlowId)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Push spi flow control element back to free elements pool */
  /* Push flow always back to SSL directly since there is no callback to the user */
  ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();
  Eth_30_Ar7000_VPushFlowToSLL(localCtrlIdx, (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA))&Eth_30_Ar7000_RegFlows[FlowId]); /* PRQA S 0310 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
  ETH_30_AR7000_END_CRITICAL_SECTION_0();
}

#if (STD_ON == ETH_30_AR7000_ENABLE_SPI_BUF_ERR_DETECT)
/**********************************************************************************************************************
 *  Eth_30_Ar7000_VSpiStatus
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VSpiStatus(
    uint8 GlobalCtrlIdx,
    uint8 FlowId)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint16 spiStatusFlags = 0;
  Eth_30_Ar7000_ReturnType resVal; /* Result value of called functions */
  Eth_30_Ar7000_SpiBufferErrorType errorType = 0;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Read QCA7005 status register value
   *     If Read SPI is OK
   *       Verify error type
   */
  resVal = Eth_30_Ar7000_GetReadSpiResult(GlobalCtrlIdx, FlowId, &spiStatusFlags);

  if ( ETH_30_AR7000_RT_OK == resVal )
  {
    if (0U != (spiStatusFlags & (ETH_30_AR7000_SPI_REG_STATUS_RDBUF_ERR | ETH_30_AR7000_SPI_REG_STATUS_WRBUF_ERR)))
    {
      if (0U != (spiStatusFlags & ETH_30_AR7000_SPI_REG_STATUS_RDBUF_ERR))
      {
        errorType |= ETH_30_AR7000_READ_BUFFER_ERROR;
      }
      if (0U != (spiStatusFlags & ETH_30_AR7000_SPI_REG_STATUS_WRBUF_ERR))
      {
        errorType |= ETH_30_AR7000_WRITE_BUFFER_ERROR;
      }
      (void)ETH_30_AR7000_SPI_BUF_ERR_CBK(GlobalCtrlIdx, errorType);
    }
  }
}
#endif /* ETH_30_AR7000_ENABLE_SPI_BUF_ERR_DETECT */

#if ( STD_ON == ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT )
/**********************************************************************************************************************
 *  Eth_30_Ar7000_VOutOfSyncDetect
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VOutOfSyncDetect(
    uint8 GlobalCtrlIdx,
    uint8 FlowId)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint16 signatureRegisterValue = 0;
  Eth_30_Ar7000_ReturnType resVal; /* Result value of called functions */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Read QCA7005 spi signature register value
   *     If Read SPI is OK
   *       verify that signature pattern is correct before update the readSignatureAttempts counter
   */
  resVal = Eth_30_Ar7000_GetReadSpiResult(GlobalCtrlIdx, FlowId, &signatureRegisterValue);

  if ( ETH_30_AR7000_RT_OK == resVal )
  {
    if ( (signatureRegisterValue == ETH_30_AR7000_SPI_SIGNATURE_PATTERN) )
    {
      ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();
      Eth_30_Ar7000_ReadSignatureAttempts = ETH_30_AR7000_RECOV_ATTEMPTS_AFTER_OSD;
      ETH_30_AR7000_END_CRITICAL_SECTION_0();
    }
  }
}
#endif /* STD_ON == ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT */

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VOnCpuRunning
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
 *
 */
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VOnCpuRunning(
    uint8 GlobalCtrlIdx,
    uint8 FlowId)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Eth_30_Ar7000_SpiReqIntrCauseFlagsType intrruptCauseFlags = 0;
  Eth_30_Ar7000_ReturnType resVal; /* Result value of called functions */
  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Read QCA7005 interrupt cause register value */
  resVal = Eth_30_Ar7000_GetReadSpiResult(GlobalCtrlIdx, FlowId, &intrruptCauseFlags);

  /* #20 If SPI read is OK */
  if ( ETH_30_AR7000_RT_OK == resVal )
  {
    /* #30 If ETH_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD is enabled
     *        If QCA7005 CPU_ON interrupt is detected
     *      else
     *        If QCA7005 cpu mode is off && QCA7005 signals packet available
     */
#if (ETH_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON)
    if ( ( intrruptCauseFlags & ETH_30_AR7000_SPI_INTR_CPU_ON ) == ETH_30_AR7000_SPI_INTR_CPU_ON)
#else
    if (   (ETH_30_AR7000_CPU_OFF == Eth_30_Ar7000_CpuMode)
        && ( ( intrruptCauseFlags & ETH_30_AR7000_SPI_INTR_PACKET_AVAILABLE ) == ETH_30_AR7000_SPI_INTR_PACKET_AVAILABLE) )
#endif
    {
      /* #40 Verify incoming spi data */
      if ( ( 0U == (intrruptCauseFlags & ETH_30_AR7000_SPI_INTR_RDBUF_ERROR )) &&
           ( 0U == (intrruptCauseFlags & ETH_30_AR7000_SPI_INTR_WRBUF_ERROR ))
         )
      {
        /* #50 Enable QCA7005 multiple cs transfer
         *        Enable QCA7005 'packet available' interrupt self-clearing (ACT_CTRL[0]=0)
         */
        (void)Eth_30_Ar7000_WriteSpi(GlobalCtrlIdx, ETH_30_AR7000_SPI_REG_ACT_CTRL, ETH_30_AR7000_SPI_REG_ACT_CTRL_MULTI_CS_EN);

        /* #60 If ETH_30_AR7000_ENABLE_TX_INTERRUPT & ETH_30_AR7000_ENABLE_RX_INTERRUPT are enabled
         *          Enable QCA7005 packet available interrupt
         */
#if ((STD_ON == ETH_30_AR7000_ENABLE_TX_INTERRUPT) && (STD_ON == ETH_30_AR7000_ENABLE_RX_INTERRUPT))
        ETH_30_AR7000_BEGIN_CRITICAL_SECTION_1();
        if ( E_NOT_OK == Eth_30_Ar7000_WriteSpi(GlobalCtrlIdx, ETH_30_AR7000_SPI_REG_INTR_ENABLE, ETH_30_AR7000_SPI_INTEN_ENABLE) )
        {
          Eth_30_Ar7000_InterruptEnableRetry[localCtrlIdx] = TRUE;
        }
        else
        {
          Eth_30_Ar7000_InterruptEnableRetry[localCtrlIdx] = FALSE;
        }
        ETH_30_AR7000_END_CRITICAL_SECTION_1();
#endif /* ETH_30_AR7000_ENABLE_TX_INTERRUPT && ETH_30_AR7000_ENABLE_RX_INTERRUPT */

        /* ESCAN00100760: Watermark value shall be configurable */
        /* #70 Set QCA7005 read buffer watermark */
        /* interrupts before prefetching a whole Ethernet packet are not desired */
        (void)Eth_30_Ar7000_WriteSpi(GlobalCtrlIdx, ETH_30_AR7000_SPI_REG_RDBUF_WATERMARK, ETH_30_AR7000_SPI_REG_RDBUF_WATERMARK_VALUE);

        /* #80 Set cpu mode indication to ON */
        Eth_30_Ar7000_CpuMode = ETH_30_AR7000_CPU_ON;
      }
    }


    /* #90 If QCA7005 signals packet available
     *        get package
     */
    if ( ( intrruptCauseFlags & ETH_30_AR7000_SPI_INTR_PACKET_AVAILABLE ) == ETH_30_AR7000_SPI_INTR_PACKET_AVAILABLE)
    {
      Eth_30_Ar7000_VGetPacket(localCtrlIdx);
    }

    /* #100 If QCA7005 signals pending interrupts
     *        Clear all interrupts except the packet available interrupt
     */
    if ( 0U != intrruptCauseFlags )
    {
      /* Clear Interrupt */
      (void)Eth_30_Ar7000_WriteSpi(GlobalCtrlIdx, ETH_30_AR7000_SPI_REG_INTR_CAUSE, intrruptCauseFlags & (uint16)(~(uint32)ETH_30_AR7000_SPI_INTR_PACKET_AVAILABLE));
    }
  }
}

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VReceive
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
 *
 *
 *
 */
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VReceive(
    uint8 GlobalCtrlIdx,
    uint8 FlowId)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2VAR(Eth_30_Ar7000_BufAccessSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT) flow = &Eth_30_Ar7000_BufFlows[FlowId];
  volatile Eth_30_Ar7000_AlignedFrameCacheType rxBufDataPtr;                                                            /* PRQA S 0759 */ /* MD_Eth_30_Ar7000_UnionForBufferAccess */
  uint32 bufOffs;
  uint16 frameType;
  uint16 frameLen;
  uint16 curOffset = 0;
  uint16 regData_1_short;
  Std_ReturnType resVal; /* Result value of called functions */
  uint8 bufferIdx;
  boolean isBroadcast;
  boolean isNewPacketAvailable = FALSE;
  boolean errorDetected = TRUE;
  uint16        mmType;
  P2VAR(uint8, AUTOMATIC, ETH_30_AR7000_APPL_DATA) physAddrPtr;
  P2VAR(uint8, AUTOMATIC, ETH_30_AR7000_APPL_DATA) dataU8Ptr;
  uint16 lenByte;
  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */

  /* --------------------------------------------- Implementation -------------------------------------------------- */

  /* #10 Find correct rx buffer start position */
  /* Get buffer index */
  bufferIdx = flow->bufIdx;

  /* Get buffer pointer */
  bufOffs = (uint32)bufferIdx * Eth_30_Ar7000_RxRing2BufMap_0[ETH_30_AR7000_RING_IDX].SegmentSize;

  /* Access associated buffer */
  rxBufDataPtr.U8 = &Eth_30_Ar7000_RxRing2BufMap_0[ETH_30_AR7000_RING_IDX].BufPtr.U8[bufOffs];

  /* #20 Verify that SPI flow control element data size is large enough */
  if ((curOffset + ETH_30_AR7000_SPI_HEADER_LENGTH) < flow->dataSize)
  {
    /* #30 Verify received SPI packet 'start of frame' indication */
    if ( (rxBufDataPtr.U16[ETH_30_AR7000_RX_SPI_SOF_OFFSET_U16 + 0U] == ETH_30_AR7000_SPI_SOF_U16) &&
         (rxBufDataPtr.U16[ETH_30_AR7000_RX_SPI_SOF_OFFSET_U16 + 1U] == ETH_30_AR7000_SPI_SOF_U16))
    {
      curOffset += ETH_30_AR7000_RX_SPI_LEN_OFFSET_U8;

      /* #40 Read SPI packet length (equal the Ethernet frame length) */
      /* Little endianess */
      frameLen = rxBufDataPtr.U8[curOffset];
      frameLen |= (uint16)(((uint32)rxBufDataPtr.U8[curOffset + 1U]) << 8U);

      curOffset += ETH_30_AR7000_SPI_FRAME_LENGTH + ETH_30_AR7000_SPI_RSV_FIELD_LENGTH;

      curOffset += frameLen;

      /* #50 Verify Ethernet frame size */
      if ( ((curOffset - ETH_30_AR7000_ALIGN_PADDING) < Eth_30_Ar7000_RxRing2BufMap_0[ETH_30_AR7000_RING_IDX].SegmentSize ) &&
           ((curOffset - ETH_30_AR7000_ALIGN_PADDING) < flow->dataSize) )
      {
        /* #60 Verify received SPI packet 'end of frame' indication */
        if ((rxBufDataPtr.U8[curOffset] == ETH_30_AR7000_SPI_EOF_BYTE) &&
            (rxBufDataPtr.U8[curOffset + 1U] == ETH_30_AR7000_SPI_EOF_BYTE))
        {
          /* #70 SPI packet is valid
           *         If ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT is enabled
           *           reset drop counter
           */
          ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();
#if ( STD_ON == ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT )
          Eth_30_Ar7000_RxDropCnt = ETH_30_AR7000_RECOV_ATTEMPTS_AFTER_OSD;
#endif /* ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT */

          /* #80 Verify that received Ethernet frame is for us */
          resVal = Eth_30_Ar7000_VFilterMacAddr(
            localCtrlIdx,
            (P2CONST(uint8, AUTOMATIC, ETH_30_AR7000_CONST))&rxBufDataPtr.U8[ETH_30_AR7000_RX_DST_OFFSET_U8]);

          ETH_30_AR7000_END_CRITICAL_SECTION_0();

          /* #90 If Ethernet frame is for us or is Multicast
           *           Extract frame type
           *           Get broadcast status
           *           Inform upper layer (EthIf or Transceiver) about frame arrival
           *         Set rx-error indicator to false
           */
          if ( E_OK == resVal )
          {
            /* Extract frame type */
            frameType = IPBASE_SWAP16(rxBufDataPtr.U16[(ETH_30_AR7000_RX_TYPE_OFFSET_U16)]);

            isBroadcast = Eth_30_Ar7000_VIsBroadcast((P2CONST(uint8, AUTOMATIC, ETH_30_AR7000_CONST))&rxBufDataPtr.U8[ETH_30_AR7000_RX_DST_OFFSET_U8]);

            physAddrPtr = &rxBufDataPtr.U8[ETH_30_AR7000_RX_SRC_OFFSET_U8];
            dataU8Ptr = &rxBufDataPtr.U8[ETH_30_AR7000_RX_DATA_OFFSET_U8];
            lenByte = (uint16)(frameLen - ETH_30_AR7000_HDR_LEN_BYTE);

            /* #100 Read position of MME type (Memory will always be allocated due to Ethernet minimum frame size) */
            mmType = (uint16)dataU8Ptr[ETH_30_AR7000_MME_TYPE_POS + 0U];
            mmType |= (uint16)(((uint16)dataU8Ptr[ETH_30_AR7000_MME_TYPE_POS + 1U]) << 8U);

            /* #110 Check if the frame is an MME frame and if yes, if the MME type is in the vendor specific range */
            if (   (frameType == ETH_30_AR7000_MME_ETHERNET_FRAME_TYPE)
                && (mmType > ETH_30_AR7000_MME_VENDOR_SPECIFIC_RANGE) )
            {
              /* #120 Yes, forward the frame to the AR7000 Trcv directly */
              EthTrcv_30_Ar7000_MME_RxIndication(GlobalCtrlIdx, frameType, isBroadcast, physAddrPtr, dataU8Ptr, lenByte);
            }
            else
            {
              /* #130 No, forward the frame to the EthIf, it will decide if it shall be forwared to the TcpIp or Slac module */
              EthIf_RxIndication(GlobalCtrlIdx, frameType, isBroadcast, physAddrPtr, &rxBufDataPtr.Native[ETH_30_AR7000_RX_DATA_OFFSET_U32], lenByte);
            }
          }

          errorDetected = FALSE;
        }
      }
    }
  }


  /* #140 If a rx-error was detected
   *       If ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT is enabled
   *         Update rx frame drop counter
   *     else
   *       Check for new package
   */
  if (TRUE == errorDetected)
  {
#if ( STD_ON == ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT )
    ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();
    if (0U < Eth_30_Ar7000_RxDropCnt)
    {
      Eth_30_Ar7000_RxDropCnt--;
    }
    ETH_30_AR7000_END_CRITICAL_SECTION_0();
#endif /* ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT */
  }
  else
  {
    /* check for new package */
    regData_1_short  = flow->base.regData_1[1U];
    regData_1_short |= (((uint16)(flow->base.regData_1[0])) << 8U);
    if ((regData_1_short > flow->dataSize) && (((uint16)(regData_1_short - flow->dataSize)) > ETH_30_AR7000_MIN_FRAME_SIZE))
    {
      isNewPacketAvailable = TRUE;
    }
  }

  /* #150 Free/Unlock the used rx buffer
   *     Push the spi flow control element back to the free elements pool
   */
  ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();

  Eth_30_Ar7000_RxBufferBusyTable[Eth_30_Ar7000_BufFlows[FlowId].bufIdx] = 0U;

  Eth_30_Ar7000_VPushFlowToSLL(localCtrlIdx, (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT))flow); /* PRQA S 0310 */ /* MD_Eth_30_Ar7000_SpiFLowCast */

  ETH_30_AR7000_END_CRITICAL_SECTION_0();

  /* #160 If new packet is available
   *       Try to receive it
   *     Else if TX/RX_INTERRUPT is enabled and no rx-error was detected
   *       Enable QCA7005 packet available interrupt
   */
  if (TRUE == isNewPacketAvailable)
  {
    /* run outside of critical section (Eth_30_Ar7000_VGetPacket is secured internally) */
    Eth_30_Ar7000_VGetPacket(localCtrlIdx);
  }
#if ((STD_ON == ETH_30_AR7000_ENABLE_TX_INTERRUPT) && (STD_ON == ETH_30_AR7000_ENABLE_RX_INTERRUPT))
  else if (FALSE == errorDetected)
  {
    ETH_30_AR7000_BEGIN_CRITICAL_SECTION_1();
    /* Enable interrupts */
    if ( E_NOT_OK == Eth_30_Ar7000_WriteSpi(GlobalCtrlIdx, ETH_30_AR7000_SPI_REG_INTR_ENABLE, ETH_30_AR7000_SPI_INTEN_ENABLE) )
    {
      Eth_30_Ar7000_InterruptEnableRetry[localCtrlIdx] = TRUE;
    }
    else
    {
      Eth_30_Ar7000_InterruptEnableRetry[localCtrlIdx] = FALSE;
    }
    ETH_30_AR7000_END_CRITICAL_SECTION_1();
  }
#endif /* ETH_30_AR7000_ENABLE_TX_INTERRUPT && ETH_30_AR7000_ENABLE_RX_INTERRUPT */
  else
  {
    /* nothing to do */
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STMCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VCheckSpiHeader
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
 *
 *
 *
 *
 *
 *
 */
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VCheckSpiHeader(
    uint8 GlobalCtrlIdx,
    uint8 FlowId)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2VAR(Eth_30_Ar7000_BufAccessSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT) spiLengthFlow = &Eth_30_Ar7000_BufFlows[FlowId];
  P2VAR(Eth_30_Ar7000_BufAccessSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT) spiPayloadFlow = &Eth_30_Ar7000_BufFlows[spiLengthFlow->linkedFlowId];
  volatile Eth_30_Ar7000_AlignedFrameCacheType rxBufDataPtr;                                                            /* PRQA S 0759 */ /* MD_Eth_30_Ar7000_UnionForBufferAccess */
  uint32 bufOffs;
  uint32 hwGenLen;
  uint8 bufferIdx;
  boolean errorDetected = FALSE;
  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */

  /* --------------------------------------------- Implementation -------------------------------------------------- */

  /* #10 Find correct rx buffer start position */
  /* Get buffer index */
  bufferIdx = Eth_30_Ar7000_BufFlows[FlowId].bufIdx;

  /* Get buffer pointer */
  bufOffs = bufferIdx * ((uint32)Eth_30_Ar7000_RxRing2BufMap_0[ETH_30_AR7000_RING_IDX].SegmentSize);

  /* Access associated buffer */
  rxBufDataPtr.U8 = &Eth_30_Ar7000_RxRing2BufMap_0[ETH_30_AR7000_RING_IDX].BufPtr.U8[bufOffs];

  /* #20 Verify that we have a correct spiLengthFlow flow control element */
  if (spiLengthFlow->dataSize == ETH_30_AR7000_SPI_HWGEN_LENGTH)
  {
    /* #30 Read QCA7005 HW-generated SPI packet length (big endian) */
    hwGenLen  = (uint32)(((uint32)rxBufDataPtr.U8[ETH_30_AR7000_RX_SPI_HWLEN_OFFSET_U8 + 0U]) << 24U);
    hwGenLen |= (uint32)(((uint32)rxBufDataPtr.U8[ETH_30_AR7000_RX_SPI_HWLEN_OFFSET_U8 + 1U]) << 16U);
    hwGenLen |= (uint32)(((uint32)rxBufDataPtr.U8[ETH_30_AR7000_RX_SPI_HWLEN_OFFSET_U8 + 2U]) <<  8U);
    hwGenLen |= (uint32)((uint32)rxBufDataPtr.U8[ETH_30_AR7000_RX_SPI_HWLEN_OFFSET_U8 + 3U]);

    /* #40 Verify that a correct sized Ethernet frame can be retreived by SpiPayloadFlow, else throw an error */
    if ((hwGenLen < Eth_30_Ar7000_RxRing2BufMap_0[ETH_30_AR7000_RING_IDX].SegmentSize) &&
        (hwGenLen >= ETH_30_AR7000_MIN_FRAME_SIZE))
    {
      spiPayloadFlow->regData_2[0U] = (uint8)(hwGenLen >> 8U);
      spiPayloadFlow->regData_2[1U] = (uint8)(hwGenLen & 0xFFU);
      spiPayloadFlow->dataSize      = (uint16)hwGenLen;
    }
    else
    {
      errorDetected = TRUE;
    }
  }

  ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();
  /* #50 Push the SpiLength flow control element back to free element pool */
  Eth_30_Ar7000_VPushFlowToSLL(localCtrlIdx, (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT))spiLengthFlow); /* PRQA S 0310 */ /* MD_Eth_30_Ar7000_SpiFLowCast */

  /* #60 If a error occurred
   *       Select the linked SpiPayload flow element
   *       Free the Rx-Buffer of the SpiPayload flow element
   *       Push the SpiPayload flow control element back to the free element pool
   *       If ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT is enabled
   *         Update RxDropCounter
   */
  if (TRUE == errorDetected)
  {
    /* error */

    /* jump over next flow in ring buffer, because the flow is linked to this one */
    Eth_30_Ar7000_VIncProcPointer(localCtrlIdx);
    /* Unlock buffer */
    Eth_30_Ar7000_RxBufferBusyTable[spiPayloadFlow->bufIdx] = 0U;
    /* Push back to SLL */
    Eth_30_Ar7000_VPushFlowToSLL(localCtrlIdx, (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT))spiPayloadFlow); /* PRQA S 0310 */ /* MD_Eth_30_Ar7000_SpiFLowCast */

#if ( STD_ON == ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT )
    if (0U < Eth_30_Ar7000_RxDropCnt)
    {
      Eth_30_Ar7000_RxDropCnt--;
    }
#endif /* ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT */

  }

  ETH_30_AR7000_END_CRITICAL_SECTION_0();

  /* #70 Trigger processing of SPI working queue */
  /* #80 If state execution return NOT_OK AND ETH_30_AR7000_ENABLE_DET_ON_SPI_BUS_ERROR is enabled
   *       Throw fatal SPI error
   */
  if ( ETH_30_AR7000_SEND_NEXT_SPI_SEQ_NOT_OK == Eth_30_Ar7000_VSendNextSpiSeq(localCtrlIdx) )
  {
#if ( STD_ON == ETH_30_AR7000_ENABLE_DET_ON_SPI_BUS_ERROR )
    /* Fatal Spi error */
    (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_GET_PACKET, ETH_30_AR7000_E_SPI_PROT_ERROR);
#endif /* ETH_30_AR7000_ENABLE_DET_ON_SPI_BUS_ERROR */
  }
}

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VTxConfirmation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VTxConfirmation(
  uint8 GlobalCtrlIdx,
    uint8 FlowId )
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Inform upper layer (EthIf) about Tx completion through callback */
  if ( TRUE == Eth_30_Ar7000_BufFlows[FlowId].txConfirmation )
  {
    EthIf_TxConfirmation(GlobalCtrlIdx, Eth_30_Ar7000_BufFlows[FlowId].bufIdx);
  }

  /* #20 Free used Tx-Buffer */
  Eth_30_Ar7000_TxBufferBusyTable[Eth_30_Ar7000_BufFlows[FlowId].bufIdx] = 0;


  /* #30 Push used SPI flow control element back to free elements pool */
  ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();
  Eth_30_Ar7000_VPushFlowToSLL(localCtrlIdx, (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA))&Eth_30_Ar7000_BufFlows[FlowId]); /* PRQA S 0310 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
  ETH_30_AR7000_END_CRITICAL_SECTION_0();
}

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VFilterMacAddr
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
 */
ETH_30_AR7000_LOCAL FUNC(Std_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_VFilterMacAddr(
            uint8                                  LocalCtrlIdx,
    P2CONST(uint8, AUTOMATIC, ETH_30_AR7000_CONST) DestMacAddr )
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2CONST(uint8, AUTOMATIC, ETH_30_AR7000_CONST) ownMacAddrPtr;
  Std_ReturnType retVal = E_NOT_OK;

#if (STD_OFF == ETH_30_AR7000_ENABLE_UPDATE_PHYS_ADDR_FILTER)
  /* --------------------------------- Dummy statement for unused variables ---------------------------------------- */
  ETH_30_AR7000_DUMMY_STATEMENT(LocalCtrlIdx);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* ETH_30_AR7000_ENABLE_UPDATE_PHYS_ADDR_FILTER */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Check if promiscous mode is allowed */
#if (STD_ON == ETH_30_AR7000_ENABLE_UPDATE_PHYS_ADDR_FILTER)
  if( Eth_30_Ar7000_PromiscousModeCnt[LocalCtrlIdx] > 0U )
  {
    /* #20 accept every frame in promiscous mode */
    retVal = E_OK;
  }
  else
#endif /* ETH_30_AR7000_ENABLE_UPDATE_PHYS_ADDR_FILTER */
  /* #30 (Else) check for own address */
  {
    /* #40 Get own physical address from configuration or from customer call back */
    ownMacAddrPtr = Eth_30_Ar7000_VCfgGetPhysSrcAddr();

    /* #50 Check for multicast / broadcast */
    /* LSB is individual/group bit and must be set. */
    if ((DestMacAddr[0U] & 0x01U) == 0x01U)
    {
      retVal = E_OK;
    }
    /* #60 Else check for unicast */
    else if (   ( DestMacAddr[0U] == ownMacAddrPtr[0] )
             && ( DestMacAddr[1U] == ownMacAddrPtr[1] )
             && ( DestMacAddr[2U] == ownMacAddrPtr[2] )
             && ( DestMacAddr[3U] == ownMacAddrPtr[3] )
             && ( DestMacAddr[4U] == ownMacAddrPtr[4] )
             && ( DestMacAddr[5U] == ownMacAddrPtr[5] ) )
    {
      retVal = E_OK;
    }
    /* #70 Else unicast to another node */
    else
    {
      /* Unicast to another node */
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VIsBroadcast
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
ETH_30_AR7000_LOCAL FUNC(boolean, ETH_30_AR7000_CODE) Eth_30_Ar7000_VIsBroadcast(
    P2CONST(uint8, AUTOMATIC, ETH_30_AR7000_APPL_DATA) PhysAddrPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8_least addrIdx;
  boolean isBroadcast = TRUE;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Verify that all MAC address bytes are 0xFF and return true, else return false. */
  for (addrIdx = 0U; addrIdx < ETH_PHYS_ADDR_LEN_BYTE; addrIdx++)
  {
    if (0xFFU != PhysAddrPtr[addrIdx])
    {
      isBroadcast = FALSE;
      break;
    }
  }

  return isBroadcast;
}

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VSMStateNA
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
 */
ETH_30_AR7000_LOCAL FUNC(Eth_30_Ar7000_SendNextSpiSeq_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_VSMStateNA(
    uint8 LocalCtrlIdx)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Eth_30_Ar7000_SendNextSpiSeq_ReturnType retVal = ETH_30_AR7000_SEND_NEXT_SPI_SEQ_END; /* Return value of this function */
  Eth_30_Ar7000_SpiSeqResultType spiResVal; /* Result value of SPI sequence result function */
  Std_ReturnType resVal; /* Result value of called functions */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  ETH_30_AR7000_DUMMY_STATEMENT(LocalCtrlIdx);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
  /* #10 Verify previous queued sequence was transmitted */
  spiResVal = ETH_30_AR7000_SPI_GETSEQUENCERESULT(ETH_30_AR7000_SPI_REF_SEQ_REG);

  /* #20 If transmission was OK or CANCELLED */
  if ( (ETH_30_AR7000_SPI_SEQ_OK == spiResVal) || (ETH_30_AR7000_SPI_SEQ_CANCELLED == spiResVal))
  {
    /* #30 Setup the SPI external buffers for the current processed SPI flow control element */
    if ( ETH_30_AR7000_SPI_FLOW_TYPE_BUF == Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->type )
    {
      /* The QCA7005 Buffer access is divided into individual steps. But the first step must be a read access and
       * is common for both: read from or write to the QCA7005 buffer.
       */
      /* PRQA S 0310, 3305 2 */ /* MD_Eth_30_Ar7000_CastToSpiDataType, MD_Eth_30_Ar7000_CastToSpiDataType */
      resVal = ETH_30_AR7000_SPI_SETUP_EB_CHL_CMD_1(Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]);
      resVal |= ETH_30_AR7000_SPI_SETUP_EB_CHL_REG_1_RX(Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]);
    }
    else
    {
      /* The QCA7005 internal register access is only one step.
       * Depending on read or write the REG_1_[TX|RX] must be set
       */
      if ( ( Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->flags & ETH_30_AR7000_SPI_FLOW_FLAG_READ_MASK ) == 0U )
      {
        /* PRQA S 0310, 3305 2 */ /* MD_Eth_30_Ar7000_CastToSpiDataType, MD_Eth_30_Ar7000_CastToSpiDataType */
        resVal  = ETH_30_AR7000_SPI_SETUP_EB_CHL_CMD_1(Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]);
        resVal |= ETH_30_AR7000_SPI_SETUP_EB_CHL_REG_1_TX(Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]);
      }
      else
      {
        /* PRQA S 0310, 3305 2 */ /* MD_Eth_30_Ar7000_CastToSpiDataType, MD_Eth_30_Ar7000_CastToSpiDataType */
        resVal  = ETH_30_AR7000_SPI_SETUP_EB_CHL_CMD_1(Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]);
        resVal |= ETH_30_AR7000_SPI_SETUP_EB_CHL_REG_1_RX(Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]);
      }
    }

    if (resVal == E_OK)
    {
      /* #40 If ETH_30_AR7000_SPI_ASYNC_MODE_ENABLED is enabled
       *       Queue the CMD1|REG_DATA1 pair for async. transmission to the QCA7005 slave
       */
#if ( STD_OFF == ETH_30_AR7000_SPI_ASYNC_MODE_ENABLED )
      resVal = ETH_30_AR7000_SPI_SYNCTRANSMIT(ETH_30_AR7000_SPI_REF_SEQ_REG);
#else
      resVal = ETH_30_AR7000_SPI_ASYNCTRANSMIT(ETH_30_AR7000_SPI_REF_SEQ_REG);
#endif /* ETH_30_AR7000_SPI_ASYNC_MODE_ENABLED */
    }

    if (resVal == E_OK)
    {
      /* #50 Set used flag for current processed SPI flow control element */
      Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->flags |= ETH_30_AR7000_SPI_FLOW_FLAG_USED_MASK;

      /* #60 Set transition to REGDATA1 */
      /*--------------------------------------------*/
      /* TRANSITION TO REGDATA1                     */
      /*--------------------------------------------*/
      Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->state = ETH_30_AR7000_SPI_FLOW_STATE_REGDATA1;

      retVal = ETH_30_AR7000_SEND_NEXT_SPI_SEQ_OK;
    }
    else
    {
      /* do nothing, retry in next call */
    }
  }
  else if ( ETH_30_AR7000_SPI_SEQ_FAILED == spiResVal )
  {
    /* Failed */
    Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->state = ETH_30_AR7000_SPI_FLOW_STATE_END;
    Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->flowTransmissionFailed = TRUE;

    retVal = ETH_30_AR7000_SEND_NEXT_SPI_SEQ_NOT_OK;
  }
  else
  {
    /* nothing to do */
  }

  return retVal;

}
/**********************************************************************************************************************
 *  Eth_30_Ar7000_VSMStateRegData1
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
 *
 *
 *
 */
ETH_30_AR7000_LOCAL FUNC(Eth_30_Ar7000_SendNextSpiSeq_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_VSMStateRegData1(
    uint8 LocalCtrlIdx)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2VAR(Eth_30_Ar7000_BufAccessSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA) bufFlow;                                    /* PRQA S 3678 */ /* MD_Eth_30_Ar7000_BufFlow_NotConst */
  uint16 regData_1_short;
  Eth_30_Ar7000_SendNextSpiSeq_ReturnType retVal = ETH_30_AR7000_SEND_NEXT_SPI_SEQ_END; /* Return value of this function */
  Eth_30_Ar7000_SpiSeqResultType spiResVal; /* Result value of SPI sequence result function */
  Std_ReturnType resVal; /* Result value of called functions */

  /* --------------------------------- Dummy statement for unused variables ---------------------------------------- */
  ETH_30_AR7000_DUMMY_STATEMENT(LocalCtrlIdx);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Verify NA_State queued sequence was transmitted */
  spiResVal = ETH_30_AR7000_SPI_GETSEQUENCERESULT(ETH_30_AR7000_SPI_REF_SEQ_REG);

  /* #20 If transmission was OK or CANCELLED */
  if ( (ETH_30_AR7000_SPI_SEQ_OK == spiResVal) || (ETH_30_AR7000_SPI_SEQ_CANCELLED == spiResVal))
  {
    /* #30 If the transmission is of type 'buffer access' */
    if ( ETH_30_AR7000_SPI_FLOW_TYPE_BUF == Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->type )
    {
      /* #40 Read result of CMD1 which is in case of:
       *        writing: available write buffer empty space
       *        reading: the total number of data bytes within the read buffer
       */
      /* PRQA S 0310 1 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
      bufFlow = (P2VAR(Eth_30_Ar7000_BufAccessSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA))Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow];

      regData_1_short  = Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->regData_1[1U];
      regData_1_short |= (((uint16)(Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->regData_1[0U])) << 8U);

      /* #50 If we want to write to the QCA7005 data transmission buffer */
      if ( ( Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->flags & ETH_30_AR7000_SPI_FLOW_FLAG_READ_MASK ) == 0U )
      {
        /* #60 Verify we not exceed the transmission retry counter */
        /*--------------------------------------------*/
        /* TRANSITION TO END                          */
        /*--------------------------------------------*/
        if ( Eth_30_Ar7000_RetryCnt >= ETH_30_AR7000_MAX_RETRY_CNT_TX )
        {
          /* Set back */
          Eth_30_Ar7000_RetryCnt = 0U;
          /* release resources */
          Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->state = ETH_30_AR7000_SPI_FLOW_STATE_END;
          Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->flowTransmissionFailed = TRUE;

          retVal =  ETH_30_AR7000_SEND_NEXT_SPI_SEQ_NOT_OK;

          /* Fatal SPI error */
#if ( ETH_30_AR7000_DEM_ERROR_DETECT == STD_ON )
          ETH_30_AR7000_DEM_REPORT_ERROR_STATUS_ETH_30_AR7000_E_ACCESS(CtrlIdx);
#endif /* ETH_30_AR7000_DEM_ERROR_DETECT */
        }
        /* #70 If the QCA7005 have not enough available write buffer empty space
         *          Update retry counter
         *          Read the QCA7005 available write buffer empty space again (queued by NA_State) AND
         *          Verify the space again
         *        else
         *          We have enough space to write to the QCA7005 write buffer
         */
        else if ( regData_1_short < bufFlow->dataSize )
        {
          /*--------------------------------------------*/
          /* TRANSITION TO NA                           */
          /*--------------------------------------------*/
          Eth_30_Ar7000_RetryCnt++;
          Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->state = ETH_30_AR7000_SPI_FLOW_STATE_NA;
          Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->flags &= (uint8)(~(uint32)ETH_30_AR7000_SPI_FLOW_FLAG_USED_MASK);

          retVal = ETH_30_AR7000_SEND_NEXT_SPI_SEQ_END;
        }
        else
        {
          /*--------------------------------------------*/
          /* TRANSITION TO REGDATA2 ALLOWED             */
          /*--------------------------------------------*/
          Eth_30_Ar7000_RetryCnt = 0U;
          retVal = ETH_30_AR7000_SEND_NEXT_SPI_SEQ_OK;
        }
      }
      /* #80 Else-If we want to read the QCA7005 received data buffer */
      else if ( ( Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->flags & ETH_30_AR7000_SPI_FLOW_FLAG_READ_MASK ) != 0U )
      {
        /* #90 Verify that the QCA7005 has stored enough data to read this buffer element */
        if ( bufFlow->dataSize > regData_1_short)
        {
          /* ... not enough data available */
          if (bufFlow->linkedFlowId != ETH_30_AR7000_SPI_INV_LINK)
          {
            /* HW generated length was not taken from the QCA7000's FIFO.
             * Discard both flows and try again later */
            /*--------------------------------------------*/
            /* TRANSITION TO END                          */
            /*--------------------------------------------*/
            Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->state = ETH_30_AR7000_SPI_FLOW_STATE_END;
            Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->flowTransmissionFailed = TRUE;
            Eth_30_Ar7000_BufFlows[bufFlow->linkedFlowId].base.state = ETH_30_AR7000_SPI_FLOW_STATE_END;
            Eth_30_Ar7000_BufFlows[bufFlow->linkedFlowId].base.flowTransmissionFailed = TRUE;
          }
          else
          {
            /* HW generated length was already taken from the QCA7000's FIFO. Try to get the packet later on.
             * Do not discard the flow because of data inconsistency */
            /*--------------------------------------------*/
            /* TRANSITION TO NA                           */
            /*--------------------------------------------*/
            Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->state = ETH_30_AR7000_SPI_FLOW_STATE_NA;
            Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->flags &= (uint8)(~(uint32)ETH_30_AR7000_SPI_FLOW_FLAG_USED_MASK);
          }
          retVal = ETH_30_AR7000_SEND_NEXT_SPI_SEQ_END;
        }
        else
        {
          /*--------------------------------------------*/
          /* TRANSITION TO REGDATA2 ALLOWED             */
          /*--------------------------------------------*/
          retVal = ETH_30_AR7000_SEND_NEXT_SPI_SEQ_OK;
        }
      }
      else
      {
        /* Unreachable path, however an 'else' path is required due to MISRA */
      }

      /* #100 If the QCA7005 provide enough space for writing to OR provide enough data for reading from AND
       *       the ETH_30_AR7000_SPI_ASYNC_MODE_ENABLED is enabled
       *         Queue the CMD2|REG_DATA2 pair for async. transmission to the QCA7005 slave
       */
      if ( ETH_30_AR7000_SEND_NEXT_SPI_SEQ_OK == retVal )
      {
        /* PRQA S 0310, 3305 2 */ /* MD_Eth_30_Ar7000_CastToSpiDataType, MD_Eth_30_Ar7000_CastToSpiDataType */
        resVal  = ETH_30_AR7000_SPI_SETUP_EB_CHL_CMD_2(bufFlow);
        resVal |= ETH_30_AR7000_SPI_SETUP_EB_CHL_REG_2(bufFlow);

        if (resVal == E_OK)
        {
#if ( (defined ETH_30_AR7000_SPI_ASYNC_MODE_ENABLED) &&  (STD_OFF == ETH_30_AR7000_SPI_ASYNC_MODE_ENABLED) )
          resVal = ETH_30_AR7000_SPI_SYNCTRANSMIT(ETH_30_AR7000_SPI_REF_SEQ_REG);
#else
          resVal = ETH_30_AR7000_SPI_ASYNCTRANSMIT(ETH_30_AR7000_SPI_REF_SEQ_REG);
#endif /* ETH_30_AR7000_SPI_ASYNC_MODE_ENABLED */
        }

        if (resVal == E_OK)
        {
          /*--------------------------------------------*/
          /* TRANSITION TO REGDATA2                     */
          /*--------------------------------------------*/
          Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->state = ETH_30_AR7000_SPI_FLOW_STATE_REGDATA2;
        }
        else
        {
          /* do nothing, retry in next call */
        }
      }
    }
    /* #110 Else
     *        The transmission was a QCA7005 internal register access (no further data for transmission) */
    else
    {
      /*--------------------------------------------*/
      /* TRANSITION TO END                          */
      /*--------------------------------------------*/
      /* flow state */
      Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->state = ETH_30_AR7000_SPI_FLOW_STATE_END;

      retVal = ETH_30_AR7000_SEND_NEXT_SPI_SEQ_OK;
    }
  }
  else if ( ETH_30_AR7000_SPI_SEQ_FAILED == spiResVal )
  {
    /* Previous transmission failed */
    Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->state = ETH_30_AR7000_SPI_FLOW_STATE_END;
    Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->flowTransmissionFailed = TRUE;

    retVal = ETH_30_AR7000_SEND_NEXT_SPI_SEQ_NOT_OK;
  }
  else
  {
    /* Sequence still pending - nothing to do */
  }

  return retVal;
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VSMStateRegData2
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
ETH_30_AR7000_LOCAL FUNC(Eth_30_Ar7000_SendNextSpiSeq_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_VSMStateRegData2(
    uint8 LocalCtrlIdx)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2VAR(Eth_30_Ar7000_BufAccessSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA) bufFlow;                                    /* PRQA S 3678 */ /* MD_Eth_30_Ar7000_BufFlow_NotConst */
  volatile Eth_30_Ar7000_AlignedFrameCacheType bufDataPtr;                                                              /* PRQA S 0759 */ /* MD_Eth_30_Ar7000_UnionForBufferAccess */
  uint32 bufOffs;
  uint16 bufferIdx;
#if ( ETH_30_AR7000_ENABLE_SPI_PADDING == STD_ON )
  Eth_30_Ar7000_SpiDataType oddByte;
#endif /* ETH_30_AR7000_ENABLE_SPI_PADDING */
  Eth_30_Ar7000_SendNextSpiSeq_ReturnType retVal = ETH_30_AR7000_SEND_NEXT_SPI_SEQ_END; /* Return value of this function */
  Eth_30_Ar7000_SpiSeqResultType spiResVal; /* Result value of SPI sequence result function */
  Std_ReturnType resVal; /* Result value of called functions */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* PRQA S 0310 1 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
  bufFlow = (P2VAR(Eth_30_Ar7000_BufAccessSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA))Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow];

  /* #10 Verify RegData1_State queued sequence was transmitted */
  spiResVal = ETH_30_AR7000_SPI_GETSEQUENCERESULT(ETH_30_AR7000_SPI_REF_SEQ_REG);
  if ( (ETH_30_AR7000_SPI_SEQ_OK == spiResVal) || (ETH_30_AR7000_SPI_SEQ_CANCELLED == spiResVal) )
  {
    spiResVal = ETH_30_AR7000_SPI_GETSEQUENCERESULT(ETH_30_AR7000_SPI_REF_SEQ_DATA);
  }
#if ( ETH_30_AR7000_ENABLE_SPI_PADDING == STD_ON )
  if ( (ETH_30_AR7000_SPI_SEQ_OK == spiResVal) || (ETH_30_AR7000_SPI_SEQ_CANCELLED == spiResVal) )
  {
    /* For the following code the compiler may indicate multiple warnings, please see MD_Eth_30_Ar7000_SpiDataType at
     * the end of the file, for justifications of this warnings.
     */
    /* PRQA S 3356, 3357, 3358, 3359, 3201 4 */ /* MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType */
    if ( (0U != (bufFlow->dataSize % 2U)) && ( 1U != sizeof(Eth_30_Ar7000_SpiDataType)) ) /*lint !e506 */
    {
      spiResVal = ETH_30_AR7000_SPI_GETSEQUENCERESULT(ETH_30_AR7000_SPI_REF_SEQ_PAD);
    }
  }
#endif /* ETH_30_AR7000_ENABLE_SPI_PADDING */

  /* #20 If transmission was OK or CANCELLED */
  if ( (ETH_30_AR7000_SPI_SEQ_OK == spiResVal) || (ETH_30_AR7000_SPI_SEQ_CANCELLED == spiResVal) )
  {
    /* PRQA S 0310, 3305 1 */ /* MD_Eth_30_Ar7000_CastToSpiDataType, MD_Eth_30_Ar7000_CastToSpiDataType */
    resVal = ETH_30_AR7000_SPI_SETUP_EB_CHL_CMD_3(bufFlow);
    if ( 0U != ( Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->flags & ETH_30_AR7000_SPI_FLOW_FLAG_READ_MASK ) )
    {
      /* Setup host SPI buffer for reading from QCA7005 */
      bufferIdx = bufFlow->bufIdx;

      /* Get buffer pointer */
      bufOffs = bufferIdx * ((uint32)Eth_30_Ar7000_RxRing2BufMap_0[ETH_30_AR7000_RING_IDX].SegmentSize);

      /* Access associated buffer */
      bufDataPtr.U8 = &Eth_30_Ar7000_RxRing2BufMap_0[ETH_30_AR7000_RING_IDX].BufPtr.U8[bufOffs + ETH_30_AR7000_ALIGN_PADDING];

      /* PRQA S 0310, 3305 1 */ /* MD_Eth_30_Ar7000_CastToSpiDataType, MD_Eth_30_Ar7000_CastToSpiDataType */
      resVal |= ETH_30_AR7000_SPI_SETUP_EB_CHL_DATA_RX(Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow], bufDataPtr.U8);
    }
    else
    {
      /* Setup host SPI buffer for writing to QCA7005 */
      bufOffs = Eth_30_Ar7000_TxBufferStart[bufFlow->bufIdx];

      bufDataPtr.U8 = &Eth_30_Ar7000_Ctrl2TxBufferMap[LocalCtrlIdx].U8[bufOffs];

      /* PRQA S 0310, 3305 1 */ /* MD_Eth_30_Ar7000_CastToSpiDataType, MD_Eth_30_Ar7000_CastToSpiDataType */
      resVal |= ETH_30_AR7000_SPI_SETUP_EB_CHL_DATA_TX(Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow], bufDataPtr.U8);

#if ( ETH_30_AR7000_ENABLE_SPI_PADDING == STD_ON )
      /* For the following code the compiler may indicate multiple warnings, please see MD_Eth_30_Ar7000_SpiDataType at
       * the end of the file, for justifications of this warnings.
       */
      /* PRQA S 3356, 3357, 3358, 3359, 3201 6 */ /* MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType */
      if ( (0U != (bufFlow->dataSize % 2U)) && ( 1U != sizeof(Eth_30_Ar7000_SpiDataType)) ) /*lint !e506 */
      {
        oddByte = (Eth_30_Ar7000_SpiDataType)(bufDataPtr.U8[bufFlow->dataSize - 1U]);

        resVal |= ETH_30_AR7000_SPI_WRITEIB(ETH_30_AR7000_SPI_REF_CHL_PAD, (P2CONST(Eth_30_Ar7000_SpiDataType, AUTOMATIC, ETH_30_AR7000_SPI_CONST))&oddByte);
      }
#endif /* ETH_30_AR7000_ENABLE_SPI_PADDING */
    }

    /* #30 If the ETH_30_AR7000_SPI_ASYNC_MODE_ENABLED is enabled
     *        Queue the CMD3|DATA pair for async. transmission to the QCA7005 slave
     */
    if (resVal == E_OK)
    {
#if ( STD_OFF == ETH_30_AR7000_SPI_ASYNC_MODE_ENABLED )
      resVal = ETH_30_AR7000_SPI_SYNCTRANSMIT(ETH_30_AR7000_SPI_REF_SEQ_DATA);
#if ( ETH_30_AR7000_ENABLE_SPI_PADDING == STD_ON )
      /* For the following code the compiler may indicate multiple warnings, please see MD_Eth_30_Ar7000_SpiDataType at
       * the end of the file, for justifications of this warnings.
       */
      /* PRQA S 3356, 3357, 3358, 3359, 3201 4 */ /* MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType */
      if ( (resVal == E_OK) && (0U != (bufFlow->dataSize % 2U)) && ( 1U != sizeof(Eth_30_Ar7000_SpiDataType)) ) /*lint !e506 */
      {
        resVal = ETH_30_AR7000_SPI_SYNCTRANSMIT(ETH_30_AR7000_SPI_REF_SEQ_PAD);
      }
#endif /* ETH_30_AR7000_ENABLE_SPI_PADDING */
#else
      resVal = ETH_30_AR7000_SPI_ASYNCTRANSMIT(ETH_30_AR7000_SPI_REF_SEQ_DATA);
#if ( ETH_30_AR7000_ENABLE_SPI_PADDING == STD_ON )
      /* For the following code the compiler may indicate multiple warnings, please see MD_Eth_30_Ar7000_SpiDataType at
       * the end of the file, for justifications of this warnings.
       */
      /* PRQA S 3356, 3357, 3358, 3359, 3201 4 */ /* MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType */
      if ( (resVal == E_OK) && (0U != (bufFlow->dataSize % 2U)) && ( 1U != sizeof(Eth_30_Ar7000_SpiDataType)) ) /*lint !e506 */
      {
        resVal = ETH_30_AR7000_SPI_ASYNCTRANSMIT(ETH_30_AR7000_SPI_REF_SEQ_PAD);
      }
#endif /* ETH_30_AR7000_ENABLE_SPI_PADDING */
#endif /* ETH_30_AR7000_SPI_ASYNC_MODE_ENABLED */
    }

    if (resVal == E_OK)
    {
      /* #40 Setup host SPI external buffers */
      /*--------------------------------------------*/
      /* TRANSITION TO DATA                         */
      /*--------------------------------------------*/
      Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->state = ETH_30_AR7000_SPI_FLOW_STATE_DATA;
    }

  }
  else if ( ETH_30_AR7000_SPI_SEQ_FAILED == spiResVal )
  {
    /* Previous transmission failed */
    Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->state = ETH_30_AR7000_SPI_FLOW_STATE_END;
    Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->flowTransmissionFailed = TRUE;

    retVal = ETH_30_AR7000_SEND_NEXT_SPI_SEQ_NOT_OK;
  }
  else
  {
    /* Sequence still pending - nothing to do */
  }

  return retVal;
} /* PRQA S 6010, 6030 */ /* MD_MSR_STPTH, MD_MSR_STCYC */
/**********************************************************************************************************************
 *  Eth_30_Ar7000_VSMStateData
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
ETH_30_AR7000_LOCAL FUNC(Eth_30_Ar7000_SendNextSpiSeq_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_VSMStateData(
    uint8 LocalCtrlIdx)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
#if ( ETH_30_AR7000_ENABLE_SPI_PADDING == STD_ON )
  /* PRQA S 0310 1 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
  P2VAR(Eth_30_Ar7000_BufAccessSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA) bufFlow = (P2VAR(Eth_30_Ar7000_BufAccessSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA))Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]; /* PRQA S 3678 */ /* MD_Eth_30_Ar7000_BufFlow_NotConst */
  uint32 bufferIdx;
  uint32 bufOffs;
  Eth_30_Ar7000_SpiDataType oddByte;
#endif /* ETH_30_AR7000_ENABLE_SPI_PADDING */
  Eth_30_Ar7000_SendNextSpiSeq_ReturnType retVal = ETH_30_AR7000_SEND_NEXT_SPI_SEQ_END; /* Return value of this function */
  Eth_30_Ar7000_SpiSeqResultType spiResVal; /* Result value of SPI sequence result function */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  ETH_30_AR7000_DUMMY_STATEMENT(LocalCtrlIdx);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
  /* #10 Verify RegData2_State queued sequence was transmitted */
  spiResVal = ETH_30_AR7000_SPI_GETSEQUENCERESULT(ETH_30_AR7000_SPI_REF_SEQ_DATA);
#if ( ETH_30_AR7000_ENABLE_SPI_PADDING == STD_ON )
  if ( (ETH_30_AR7000_SPI_SEQ_OK == spiResVal) || (ETH_30_AR7000_SPI_SEQ_CANCELLED == spiResVal) )
  {
    /* For the following code the compiler may indicate multiple warnings, please see MD_Eth_30_Ar7000_SpiDataType at
     * the end of the file, for justifications of this warnings.
     */
    /* PRQA S 3356, 3357, 3358, 3359, 3201 4 */ /* MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType */
    if ( (0U != (bufFlow->dataSize % 2U)) && ( 1U != sizeof(Eth_30_Ar7000_SpiDataType)) ) /*lint !e506 */
    {
      spiResVal = ETH_30_AR7000_SPI_GETSEQUENCERESULT(ETH_30_AR7000_SPI_REF_SEQ_PAD);
    }
  }
#endif /* ETH_30_AR7000_ENABLE_SPI_PADDING */

  /* #20 If transmission was OK or CANCELLED
   *       Transition to State_END with valid EndNotification callback
   *     Else-If transmission FAILED
   *       Transition to State_END without valid EndNotification callback
   */
  if ( (ETH_30_AR7000_SPI_SEQ_OK == spiResVal) || (ETH_30_AR7000_SPI_SEQ_CANCELLED == spiResVal) )
  {
#if ( ETH_30_AR7000_ENABLE_SPI_PADDING == STD_ON )
    /* For the following code the compiler may indicate multiple warnings, please see MD_Eth_30_Ar7000_SpiDataType at
     * the end of the file, for justifications of this warnings.
     */
    /* PRQA S 3356, 3357, 3358, 3359, 3201 10 */ /* MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType, MD_Eth_30_Ar7000_SpiDataType */
    if ( (0U != (bufFlow->dataSize % 2U)) && ( 1U != sizeof(Eth_30_Ar7000_SpiDataType)) ) /*lint !e506 */
    {
      /* Get buffer index */
      bufferIdx = bufFlow->bufIdx;
      /* Get buffer pointer */
      bufOffs = bufferIdx * ((uint32)Eth_30_Ar7000_RxRing2BufMap_0[ETH_30_AR7000_RING_IDX].SegmentSize);
      /* get last byte of the buffer */
      if (E_OK == ETH_30_AR7000_SPI_READIB(ETH_30_AR7000_SPI_REF_CHL_PAD, &oddByte))
      {
        /* Write oddByte to the end of the buffer */
        /* PRQA S 0310 1 */ /* MD_Eth_30_Ar7000_BufferCast */
        ((P2VAR(uint8, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT))Eth_30_Ar7000_RxBuffer_0_0)[(bufOffs + ETH_30_AR7000_ALIGN_PADDING) + (((uint32)bufFlow->dataSize) - 1U)] = (uint8)oddByte;
      }
      else
      {
        /* Error getting last byte, set as 0 instead */
        /* PRQA S 0310 1 */ /* MD_Eth_30_Ar7000_BufferCast */
        ((P2VAR(uint8, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT))Eth_30_Ar7000_RxBuffer_0_0)[(bufOffs + ETH_30_AR7000_ALIGN_PADDING) + (((uint32)bufFlow->dataSize) - 1U)] = 0U;
      }
    }
#endif /* ETH_30_AR7000_ENABLE_SPI_PADDING */

    Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->state = ETH_30_AR7000_SPI_FLOW_STATE_END;
    retVal = ETH_30_AR7000_SEND_NEXT_SPI_SEQ_OK;
  }
  else if ( ETH_30_AR7000_SPI_SEQ_FAILED == spiResVal)
  {
    /* previous transmission failed */
    Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->flowTransmissionFailed = TRUE;
    Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->state = ETH_30_AR7000_SPI_FLOW_STATE_END;

    retVal = ETH_30_AR7000_SEND_NEXT_SPI_SEQ_NOT_OK;
  }
  else
  {
    /* nothing to do - Sequence still pending */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VSMStateEnd
 *********************************************************************************************************************/
/*!
 *
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
 *
 *
 *
 *
 */
ETH_30_AR7000_LOCAL FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_VSMStateEnd(
    uint8 LocalCtrlIdx)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA) tempFlow;
  boolean hasLink = FALSE;
  uint8 globalCtrlIdx = Eth_30_Ar7000_TransformToGlobalCtrlIdx(LocalCtrlIdx);                                           /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */

  /* --------------------------------------------- Implementation -------------------------------------------------- */

  /* #10 Clear 'used' flag for current processed SPI flow control element */
  Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]->flags &= (uint8)(~(uint32)ETH_30_AR7000_SPI_FLOW_FLAG_USED_MASK);

  tempFlow = Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow];

  /* #20 Select next processing element in case of a data-transmission this is the linked buffer flow element */
  Eth_30_Ar7000_VIncProcPointer(LocalCtrlIdx);

  /* #30 Verify link state for current processed SPI flow control element */
  /* PRQA S 0310 2 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
  if ( (ETH_30_AR7000_SPI_FLOW_TYPE_BUF == tempFlow->type) &&
           (((P2VAR(Eth_30_Ar7000_BufAccessSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT))tempFlow)->linkedFlowId != ETH_30_AR7000_SPI_INV_LINK))
  {
    hasLink = TRUE;
  }

  /* End critical section here, it was started in Eth_30_Ar7000_VSendNextSpiSeq */
  ETH_30_AR7000_END_CRITICAL_SECTION_0();

  if ( FALSE == hasLink )
  {

    /* look for new SPI flow recursively */
    (void)Eth_30_Ar7000_VSendNextSpiSeq(LocalCtrlIdx);                                                                  /* PRQA S 1520 */ /* MD_Eth_30_Ar7000_RecursiveCalls */
  }

  /* #40 Call current processed SPI flow control element EndNotification callback if available and no error occured
   *     If no valid EndNotification is available
   *       Release Tx- or Rx-Buffer if current processed SPI flow control element was a type of QCA7005 buffer access
   *       Push current processed SPI flow control element back to the free elements pool. Flows with EndNotification
   *       will be freed in context of the end notification call back. However a flow may be abort in error cases.
   *       In this case the EndNotification will be cleared. There for flows without an EndNotification set needs to
   *       be cleared in any case.
   *       If the current processed SPI flow control element has a valid link
   *         Push the linked element to the free elements pool
   *         Select next processing element
   */
  if (   (tempFlow->flowTransmissionFailed == FALSE)
      && ((Eth_30_Ar7000_EndNotificationFctType)0 != tempFlow->EndNotification) )
  {
    tempFlow->EndNotification(globalCtrlIdx, tempFlow->id);
  }
  else
  {
    ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();

    /* Buffer flow */
    if (ETH_30_AR7000_SPI_FLOW_TYPE_BUF == tempFlow->type)
    {
      uint8 bufferIdx = ((P2VAR(Eth_30_Ar7000_BufAccessSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT))tempFlow)->bufIdx; /* PRQA S 0310 */ /* MD_Eth_30_Ar7000_SpiFLowCast */

      /* Release TX buffer */
      if ((tempFlow->flags & ETH_30_AR7000_SPI_FLOW_FLAG_READ_MASK) != ETH_30_AR7000_SPI_FLOW_FLAG_READ_MASK)
      {
        /* Check if index is valid */
        if (bufferIdx < ETH_30_AR7000_TX_BUF_TOTAL)
        {
          Eth_30_Ar7000_TxBufferBusyTable[bufferIdx] = 0U;
        }
        else
        {
          /* The index is out of range, it cannot be released, just ignore it and continue with the flow release. */
        }
      }
      /* Release RX buffer */
      else if ((tempFlow->flags & ETH_30_AR7000_SPI_FLOW_FLAG_READ_MASK) == ETH_30_AR7000_SPI_FLOW_FLAG_READ_MASK)
      {
        /* Check if index is valid */
        if (bufferIdx < ETH_30_AR7000_TX_BUF_TOTAL)
        {
          Eth_30_Ar7000_RxBufferBusyTable[bufferIdx] = 0U;
        }
        else
        {
          /* The index is out of range, it cannot be released, just ignore it and continue with the flow release. */
        }
      }
      else
      {
        /* not possible */
      }
    }

    if ((ETH_30_AR7000_SPI_FLOW_TYPE_REG == tempFlow->type) && ((ETH_30_AR7000_SPI_FLOW_FLAG_READ_MASK & tempFlow->flags) != 0U))
    {
      /* Register read flow, without end notificateion set or with error occured.
       * In both cases the user has to call Eth_30_Ar7000_GetReadSpiResult, this call will release this flow.
       */
      if ((Eth_30_Ar7000_EndNotificationFctType)0 != tempFlow->EndNotification)
      {
        /* Do not call the EndNotification call back within an active interrupt locking section */
        ETH_30_AR7000_END_CRITICAL_SECTION_0();
        /* (tempFlow->flowTransmissionFailed == TRUE) due to previous check. Call EndNotification to
         * inform user about the failed sequence */
        tempFlow->EndNotification(globalCtrlIdx, tempFlow->id);
        ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();
      }
      else
      {
        /* Nothing to do. No EndNotification was set, user has to poll Eth_30_Ar7000_GetReadSpiResult to get the result. */
      }
    }
    else
    {
      /* Push flow back to SLL */
      Eth_30_Ar7000_VPushFlowToSLL(LocalCtrlIdx, tempFlow);
    }

    if (TRUE == hasLink)
    {
      /* linked flow without end notification - flows were discarded, jump over subsequent flow */
      /* Push flow back to SLL */
      Eth_30_Ar7000_VPushFlowToSLL(LocalCtrlIdx, Eth_30_Ar7000_RingBuffer[Eth_30_Ar7000_RingBufCurProcFlow]);

      /* jump over next flow */
      Eth_30_Ar7000_VIncProcPointer(LocalCtrlIdx);

      /* End critical section befor calling Eth_30_Ar7000_VSendNextSpiSeq */
      ETH_30_AR7000_END_CRITICAL_SECTION_0();

      /* look for new SPI flow recursively */
      (void)Eth_30_Ar7000_VSendNextSpiSeq(LocalCtrlIdx);                                                                /* PRQA S 1520 */ /* MD_Eth_30_Ar7000_RecursiveCalls */
    }
    else
    {
      ETH_30_AR7000_END_CRITICAL_SECTION_0();
    }
  }
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF  */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Eth_30_Ar7000_InitMemory
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_InitMemory( void )
{
#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  /* #10 If DET is enabled set module initialized to UNINIT */
  Eth_30_Ar7000_ModuleInitialized = ETH_STATE_UNINIT;
#endif /* ETH_30_AR7000_DEV_ERROR_DETECT */
}

/**********************************************************************************************************************
 *  Eth_30_Ar7000_Init
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_Init(
    P2CONST(Eth_30_Ar7000_ConfigType, AUTOMATIC, ETH_30_AR7000_CONST) CfgPtr)
{
  ETH_30_AR7000_DUMMY_STATEMENT(CfgPtr);                                                                                /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  Eth_30_Ar7000_CycleCnt = 0U;

  /* #10 Initialize controller specific data for all QCA7005 transceivers */
#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  Eth_30_Ar7000_ModuleInitialized = ETH_STATE_INIT;
#endif /* ETH_30_AR7000_DEV_ERROR_DETECT */
  {
    uint8_least localCtrlIdx;
    for (localCtrlIdx = 0; localCtrlIdx < ETH_30_AR7000_MAX_CTRLS_TOTAL; localCtrlIdx++)
    {
      Eth_30_Ar7000_CtrlMode[localCtrlIdx] = ETH_MODE_DOWN;
#if ((STD_ON == ETH_30_AR7000_ENABLE_TX_INTERRUPT) && (STD_ON == ETH_30_AR7000_ENABLE_RX_INTERRUPT))
      Eth_30_Ar7000_InterruptEnableRetry[localCtrlIdx] = FALSE;
#endif /* ETH_30_AR7000_ENABLE_TX_INTERRUPT && ETH_30_AR7000_ENABLE_RX_INTERRUPT */

      /* #20 Set MAC address from configured default address */
      /* Init physical address if necessary, do this during init so that the application is able to change
       * the address in before requesting the communication.
       */
#if ((defined ETH_30_AR7000_ENABLE_MAC_WRITE_ACCESS) && (STD_ON == ETH_30_AR7000_ENABLE_MAC_WRITE_ACCESS))
      /* Physical address is initialized during NvM_ReadAll */
#else
      /* Manually write configured default address to local RAM */
      {
        uint8_least ByteIdx;
        for (ByteIdx = 0U; ByteIdx < ETH_PHYS_ADDR_LEN_BYTE; ByteIdx++)
        {
          Eth_30_Ar7000_PhysSrcAddrs[localCtrlIdx][ByteIdx] = Eth_30_Ar7000_PhysSrcAddrsRom[localCtrlIdx][ByteIdx];
        }
      }
#endif
    }
  }

  /* #30 Initialize QCA7005 CPU mode */
  Eth_30_Ar7000_CpuMode = ETH_30_AR7000_CPU_OFF;

}

/**********************************************************************************************************************
 *  Eth_30_Ar7000_ControllerInit
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
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_ControllerInit(
    uint8 GlobalCtrlIdx,
    uint8 CfgIdx)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Eth_30_Ar7000_DetErrorType errorId = ETH_30_AR7000_E_NO_ERROR;
  uint8 u8Idx = 0;
  Std_ReturnType retVal; /* Return value of this function: Do not initialize here to prevent compiler warnings */
  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  retVal = E_NOT_OK; /* Return value of this function */
  if (Eth_30_Ar7000_ModuleInitialized == ETH_STATE_UNINIT)
  {
    errorId = ETH_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (localCtrlIdx >= ETH_30_AR7000_MAX_CTRLS_TOTAL)
  {
    errorId = ETH_30_AR7000_E_INV_CTRL_IDX;
  }
  else if (CfgIdx >= ETH_30_AR7000_MAX_CFGS_TOTAL)
  {
    errorId = ETH_30_AR7000_E_INV_CONFIG;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* trigger start of runtime measurement */
    Eth_30_Ar7000_Rtm_Start(ControllerInit);

    /* #20 set controller mode to DOWN */
#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
    Eth_30_Ar7000_ModuleInitialized = ETH_STATE_ACTIVE;
#endif /* ETH_30_AR7000_DEV_ERROR_DETECT */
    Eth_30_Ar7000_CtrlMode[localCtrlIdx] = ETH_MODE_DOWN;
#if ((STD_ON == ETH_30_AR7000_ENABLE_TX_INTERRUPT) && (STD_ON == ETH_30_AR7000_ENABLE_RX_INTERRUPT))
    Eth_30_Ar7000_InterruptEnableRetry[localCtrlIdx] = FALSE;
#endif /* ETH_30_AR7000_ENABLE_TX_INTERRUPT && ETH_30_AR7000_ENABLE_RX_INTERRUPT */

    /* #30 Initialize SPI flow control element pool for QCA7005 register access
     *     Set pool base address
     *     Iterate over all elements
     *       Set flow control element type
     *       Set unique ID
     *       Clear all flags
     *       Set initial state
     *       link/concatenate each element
     */
    Eth_30_Ar7000_FreeRegFlowAnchor = &Eth_30_Ar7000_RegFlows[0U];
    while ( ETH_30_AR7000_MAX_REG_FLOWS > u8Idx )
    {
      Eth_30_Ar7000_RegFlows[u8Idx].base.type = ETH_30_AR7000_SPI_FLOW_TYPE_REG;
      Eth_30_Ar7000_RegFlows[u8Idx].base.id = u8Idx;
      Eth_30_Ar7000_RegFlows[u8Idx].base.flags = 0U;
      Eth_30_Ar7000_RegFlows[u8Idx].base.state = ETH_30_AR7000_SPI_FLOW_STATE_NA;
      if ( (ETH_30_AR7000_MAX_REG_FLOWS - 1U) > u8Idx )
      {
        Eth_30_Ar7000_RegFlows[u8Idx].base.nextFlow = (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT)) &Eth_30_Ar7000_RegFlows[u8Idx + 1U]; /* PRQA S 0310 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
      }
      else
      {
        Eth_30_Ar7000_RegFlows[u8Idx].base.nextFlow = (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT)) NULL_PTR;
      }
      u8Idx++;
    }

    /* #40 Initialize SPI flow control element pool for QCA7005 data transmission
     *     Set pool base address
     *     Iterate over all elements
     *       Set flow control element type
     *       Set unique ID
     *       Clear all flags
     *       Set initial state
     *       Initialize callback functions to zero
     *       Disable txConfirmation
     *       link/concatenate each element
     */
    u8Idx = 0U;
    Eth_30_Ar7000_FreeBufFlowAnchor = &Eth_30_Ar7000_BufFlows[0U];
    while ( ETH_30_AR7000_MAX_BUF_FLOWS > u8Idx )
    {
      Eth_30_Ar7000_BufFlows[u8Idx].base.type = ETH_30_AR7000_SPI_FLOW_TYPE_BUF;
      Eth_30_Ar7000_BufFlows[u8Idx].base.id = u8Idx;
      Eth_30_Ar7000_BufFlows[u8Idx].base.flags = 0U;
      Eth_30_Ar7000_BufFlows[u8Idx].base.state = ETH_30_AR7000_SPI_FLOW_STATE_NA;
      Eth_30_Ar7000_BufFlows[u8Idx].base.EndNotification = (Eth_30_Ar7000_EndNotificationFctType)0;
      Eth_30_Ar7000_BufFlows[u8Idx].base.flowTransmissionFailed = FALSE;
      Eth_30_Ar7000_BufFlows[u8Idx].txConfirmation = FALSE;


      if ( (ETH_30_AR7000_MAX_BUF_FLOWS - 1U) > u8Idx )
      {
        Eth_30_Ar7000_BufFlows[u8Idx].base.nextFlow = (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT)) &Eth_30_Ar7000_BufFlows[u8Idx + 1U]; /* PRQA S 0310 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
      }
      else
      {
        Eth_30_Ar7000_BufFlows[u8Idx].base.nextFlow = (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT)) NULL_PTR;
      }

      u8Idx++;
    }

    /* #50 Initialize all counter and buffer positions */
    /* Init ring buffer */
    Eth_30_Ar7000_RingBufNextPos = 0U;
    Eth_30_Ar7000_RingBufCurProcFlow = 0U;

    /* init retry counter */
    Eth_30_Ar7000_RetryCnt = 0U;

#if ( STD_ON == ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT )
    Eth_30_Ar7000_ReadSignatureAttempts = ETH_30_AR7000_RECOV_ATTEMPTS_AFTER_OSD;
    Eth_30_Ar7000_RxDropCnt = ETH_30_AR7000_RECOV_ATTEMPTS_AFTER_OSD;
#endif /* ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT */


    /* #60 Initialize buffer busy tables */
    u8Idx = ETH_30_AR7000_TX_BUF_TOTAL;
    while( 0U != u8Idx )
    {
      u8Idx--;
      Eth_30_Ar7000_TxBufferBusyTable[u8Idx] = (uint8)0U;
    }
    u8Idx = ETH_30_AR7000_RX_BUF_TOTAL;
    while( 0U != u8Idx )
    {
      u8Idx--;
      Eth_30_Ar7000_RxBufferBusyTable[u8Idx] = (uint8)0U;
    }

    /* #70 Clear interrupt cause pending counter (if ETH_30_AR7000_ENABLE_TX_INTERRUPT disabled)
     *     Clear promiscous mode counter (if ETH_30_AR7000_ENABLE_UPDATE_PHYS_ADDR_FILTER enabled)
     */
#if ((STD_OFF == ETH_30_AR7000_ENABLE_TX_INTERRUPT) && (STD_OFF == ETH_30_AR7000_ENABLE_RX_INTERRUPT))
    Eth_30_Ar7000_IntrCauseReqPending = 0U;
#endif /* ETH_30_AR7000_ENABLE_TX_INTERRUPT && ETH_30_AR7000_ENABLE_RX_INTERRUPT */

#if (STD_ON == ETH_30_AR7000_ENABLE_UPDATE_PHYS_ADDR_FILTER)
    Eth_30_Ar7000_PromiscousModeCnt[localCtrlIdx] = 0U;
#endif /* ETH_30_AR7000_ENABLE_UPDATE_PHYS_ADDR_FILTER */

    /* Set return value */
    retVal = E_OK;

    /* trigger stop of runtime measurement */
    Eth_30_Ar7000_Rtm_Stop(ControllerInit);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETH_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETH_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_CONTROLLER_INIT, errorId);
  }
#else
  ETH_30_AR7000_DUMMY_STATEMENT(errorId);                                                                               /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
  ETH_30_AR7000_DUMMY_STATEMENT(CfgIdx);                                                                                /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
#endif
  return retVal;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Eth_30_Ar7000_SetControllerMode
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_SetControllerMode(
    uint8        GlobalCtrlIdx,
    Eth_ModeType CtrlMode)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Eth_30_Ar7000_DetErrorType errorId = ETH_30_AR7000_E_NO_ERROR;
  Std_ReturnType retVal; /* Return value of this function: Do not initialize here to prevent compiler warnings */

  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  retVal = E_NOT_OK;
  if (Eth_30_Ar7000_ModuleInitialized < ETH_STATE_ACTIVE)
  {
    errorId = ETH_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (localCtrlIdx >= ETH_30_AR7000_MAX_CTRLS_TOTAL)
  {
    errorId = ETH_30_AR7000_E_INV_CTRL_IDX;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Set the current controller mode */
    if ( ETH_MODE_ACTIVE == CtrlMode )
    {
      Eth_30_Ar7000_CtrlMode[localCtrlIdx] = ETH_MODE_ACTIVE;
    }
    else
    {
      Eth_30_Ar7000_CtrlMode[localCtrlIdx] = ETH_MODE_DOWN;
    }
    retVal = E_OK;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETH_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETH_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_SET_CONTROLLER_MODE, errorId);
  }
#else
  ETH_30_AR7000_DUMMY_STATEMENT(errorId);                                                                               /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
}

/**********************************************************************************************************************
 *  Eth_30_Ar7000_GetControllerMode
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_GetControllerMode(
          uint8                                             GlobalCtrlIdx,
    P2VAR(Eth_ModeType, AUTOMATIC, ETH_30_AR7000_APPL_DATA) CtrlModePtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Eth_30_Ar7000_DetErrorType errorId = ETH_30_AR7000_E_NO_ERROR; /* Error ID used for DET check error codes */
  Std_ReturnType retVal; /* Return value of this function: Do not initialize here to prevent compiler warnings */

  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  retVal = E_NOT_OK;
  if (Eth_30_Ar7000_ModuleInitialized < ETH_STATE_ACTIVE)
  {
    errorId = ETH_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (localCtrlIdx >= ETH_30_AR7000_MAX_CTRLS_TOTAL)
  {
    errorId = ETH_30_AR7000_E_INV_CTRL_IDX;
  }
  else if (NULL_PTR == CtrlModePtr)
  {
    errorId = ETH_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Provide current controller mode */
    *CtrlModePtr = Eth_30_Ar7000_CtrlMode[localCtrlIdx];

    retVal = E_OK;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETH_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETH_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_GET_CONTROLLER_MODE, errorId);
  }
#else
  ETH_30_AR7000_DUMMY_STATEMENT(errorId);                                                                               /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
}

/**********************************************************************************************************************
 *  Eth_30_Ar7000_GetPhysAddr
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_GetPhysAddr(
          uint8                                      GlobalCtrlIdx,
    P2VAR(uint8, AUTOMATIC, ETH_30_AR7000_APPL_DATA) PhysAddrPtr)

{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2CONST(uint8, AUTOMATIC, ETH_30_AR7000_CONST) ownMacAddrPtr;
  Eth_30_Ar7000_DetErrorType errorId = ETH_30_AR7000_E_NO_ERROR; /* Error ID used for DET check error codes */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */
  if (Eth_30_Ar7000_ModuleInitialized < ETH_STATE_INIT)
  {
    errorId = ETH_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (localCtrlIdx >= ETH_30_AR7000_MAX_CTRLS_TOTAL)
  {
    errorId = ETH_30_AR7000_E_INV_CTRL_IDX;
  }
  else if (NULL_PTR == PhysAddrPtr)
  {
    errorId = ETH_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Get own physical address from configuration or from customer call back */
    ownMacAddrPtr = Eth_30_Ar7000_VCfgGetPhysSrcAddr();
    PhysAddrPtr[0u] = ownMacAddrPtr[0];
    PhysAddrPtr[1u] = ownMacAddrPtr[1];
    PhysAddrPtr[2u] = ownMacAddrPtr[2];
    PhysAddrPtr[3u] = ownMacAddrPtr[3];
    PhysAddrPtr[4u] = ownMacAddrPtr[4];
    PhysAddrPtr[5u] = ownMacAddrPtr[5];
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETH_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETH_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_GET_PHYS_ADDR, errorId);
  }
#else
  ETH_30_AR7000_DUMMY_STATEMENT(errorId);                                                                               /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
  ETH_30_AR7000_DUMMY_STATEMENT(GlobalCtrlIdx);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
#endif
}

/**********************************************************************************************************************
 *  Eth_30_Ar7000_SetPhysAddr
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC (void, ETH_30_AR7000_CODE) Eth_30_Ar7000_SetPhysAddr(
            uint8                                      GlobalCtrlIdx,
    P2CONST(uint8, AUTOMATIC, ETH_30_AR7000_APPL_DATA) PhysAddrPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2VAR(uint8, AUTOMATIC, ETH_30_AR7000_APPL_DATA) ownMacAddrPtr;
  Eth_30_Ar7000_DetErrorType errorId = ETH_30_AR7000_E_NO_ERROR; /* Error ID used for DET check error codes */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */
  if (Eth_30_Ar7000_ModuleInitialized < ETH_STATE_INIT)
  {
    errorId = ETH_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (localCtrlIdx >= ETH_30_AR7000_MAX_CTRLS_TOTAL)
  {
    errorId = ETH_30_AR7000_E_INV_CTRL_IDX;
  }
  else if (NULL_PTR == PhysAddrPtr)
  {
    errorId = ETH_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Get own physical address pointer from configuration or from customer call back */
    ownMacAddrPtr = Eth_30_Ar7000_VCfgGetPhysSrcAddr();
    /* #30 Update MAC address */
    ownMacAddrPtr[0] = PhysAddrPtr[0];
    ownMacAddrPtr[1] = PhysAddrPtr[1];
    ownMacAddrPtr[2] = PhysAddrPtr[2];
    ownMacAddrPtr[3] = PhysAddrPtr[3];
    ownMacAddrPtr[4] = PhysAddrPtr[4];
    ownMacAddrPtr[5] = PhysAddrPtr[5];

    /* #40 If ETH_30_AR7000_ENABLE_MAC_WRITE_ACCESS is enabled write MAC address to non volatile memory area  */
#if ((defined ETH_30_AR7000_ENABLE_MAC_WRITE_ACCESS) && (STD_ON == ETH_30_AR7000_ENABLE_MAC_WRITE_ACCESS))
    {
      Std_ReturnType RetVal;
      uint8 Status = NVM_REQ_PENDING;
      RetVal = NvM_GetErrorStatus((NvM_BlockIdType)ETH_30_AR7000_CTRL_MAC_ADDR_BLOCK_ID, &Status);

      if((E_OK == RetVal) && (Status != NVM_REQ_PENDING))
      {
        /* set block Status to true */
        (void)NvM_SetRamBlockStatus((NvM_BlockIdType)ETH_30_AR7000_CTRL_MAC_ADDR_BLOCK_ID, TRUE);
      }
    }
#endif /* ETH_30_AR7000_ENABLE_MAC_WRITE_ACCESS */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETH_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETH_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_SET_PHYS_ADDR, errorId);
  }
#else
  ETH_30_AR7000_DUMMY_STATEMENT(errorId);                                                                               /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
  ETH_30_AR7000_DUMMY_STATEMENT(GlobalCtrlIdx);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
#endif
}

#if ((defined ETH_30_AR7000_ENABLE_UPDATE_PHYS_ADDR_FILTER) && (STD_ON == ETH_30_AR7000_ENABLE_UPDATE_PHYS_ADDR_FILTER))
/**********************************************************************************************************************
 *  Eth_30_Ar7000_UpdatePhysAddrFilter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC (Std_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_UpdatePhysAddrFilter(
            uint8                                                    GlobalCtrlIdx,
    P2CONST(uint8,               AUTOMATIC, ETH_30_AR7000_APPL_DATA) PhysAddrPtr,
            Eth_FilterActionType                                     Action)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Eth_30_Ar7000_DetErrorType errorId = ETH_30_AR7000_E_NO_ERROR; /* Error ID used for DET check error codes */
  Std_ReturnType retVal = E_NOT_OK; /* Return value of this function */
  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  if (Eth_30_Ar7000_ModuleInitialized < ETH_STATE_ACTIVE)
  {
    errorId = ETH_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (localCtrlIdx >= ETH_30_AR7000_MAX_CTRLS_TOTAL)
  {
    errorId = ETH_30_AR7000_E_INV_CTRL_IDX;
  }
  else if (NULL_PTR == PhysAddrPtr)
  {
    errorId = ETH_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();

    /* #20 If any address is passed Set/Unset promiscous mode depending on the 'Action' passed as parameter */
    if (   (Action == ETH_ADD_TO_FILTER)
        && (Eth_30_Ar7000_PromiscousModeCnt[localCtrlIdx] < 0xFFU) )
    {
        Eth_30_Ar7000_PromiscousModeCnt[localCtrlIdx]++;
        retVal = E_OK;
    }
    else if (   (Action == ETH_REMOVE_FROM_FILTER)
             && (Eth_30_Ar7000_PromiscousModeCnt[localCtrlIdx] > 0x00U) )
    {
        Eth_30_Ar7000_PromiscousModeCnt[localCtrlIdx]--;
        retVal = E_OK;
    }
    else
    {
      /* Invalid action, 'retVal = E_NOT_OK' is already set */
    }

    ETH_30_AR7000_END_CRITICAL_SECTION_0();
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETH_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETH_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_UPDATE_PHYS_ADDR_FILTER, errorId);
  }
#else
  ETH_30_AR7000_DUMMY_STATEMENT(errorId);                                                                               /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
  ETH_30_AR7000_DUMMY_STATEMENT(PhysAddrPtr);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif /* ETH_30_AR7000_ENABLE_UPDATE_PHYS_ADDR_FILTER */

/**********************************************************************************************************************
 *  Eth_30_Ar7000_WriteSpi
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
FUNC(Eth_30_Ar7000_SpiAccessReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_WriteSpi(
    uint8 GlobalCtrlIdx,
    uint16 RegAddr,
    uint16 RegVal)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2VAR(Eth_30_Ar7000_RegAccessSpiFlow, AUTOMATIC, AUTOMATIC) flow = (P2VAR(Eth_30_Ar7000_RegAccessSpiFlow, AUTOMATIC, AUTOMATIC))NULL_PTR;
  Eth_30_Ar7000_DetErrorType errorId = ETH_30_AR7000_E_NO_ERROR; /* Error ID used for DET check error codes */
  Eth_30_Ar7000_SpiAccessReturnType retVal; /* Return value of this function: Do not initialize here to prevent compiler warnings */
  Std_ReturnType resVal; /* Result value of called functions */
  boolean firstFlowInQueue = FALSE;

  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  retVal = ETH_30_AR7000_SPI_ACCESS_NOT_OK;
  if (Eth_30_Ar7000_ModuleInitialized < ETH_STATE_ACTIVE)
  {
    errorId = ETH_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (localCtrlIdx >= ETH_30_AR7000_MAX_CTRLS_TOTAL)
  {
    errorId = ETH_30_AR7000_E_INV_CTRL_IDX;
  }
  else if (RegAddr > ETH_30_AR7000_SPI_REG_ACT_CTRL)
  {
    errorId = ETH_30_AR7000_E_INV_PARAM;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Request free SPI flow control element from element pool */
    ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();
    resVal = Eth_30_Ar7000_VPopFlowFromSLL(localCtrlIdx, ETH_30_AR7000_SPI_FLOW_TYPE_REG, (P2VAR(Eth_30_Ar7000_BaseSpiFlow*, AUTOMATIC, ETH_30_AR7000_APPL_DATA)) &flow); /* PRQA S 0310 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
    ETH_30_AR7000_END_CRITICAL_SECTION_0();

    /* #30 Verify that we get a valid element */
    /* #40 Prepare the element for a QCA7005 internal register write
     *     Push the element to the working queue
     */
    if ( E_OK == resVal )
    {
      /* fill flow */
      /* Command word */
      flow->base.cmdWord_1[0]  = ETH_30_AR7000_SPI_CMD_WORD_I_FLAG_MASK;
      flow->base.cmdWord_1[0] &= (uint8)(~(uint32)ETH_30_AR7000_SPI_CMD_WORD_R_FLAG_MASK);
      flow->base.cmdWord_1[0] |= (uint8)(( RegAddr & ETH_30_AR7000_SPI_CMD_WORD_ADDR_HIGH_MASK ) >> 8U);
      flow->base.cmdWord_1[1]  = (uint8)( RegAddr  & ETH_30_AR7000_SPI_CMD_WORD_ADDR_LOW_MASK );

      flow->base.regData_1[0] = (uint8)(( RegVal & 0xFF00U ) >> 8U);
      flow->base.regData_1[1] = (uint8)(RegVal & 0x00FFU);

      /* Callback */
      flow->base.EndNotification = Eth_30_Ar7000_VWriteSpiConfirmation;

      /* flags */
      flow->base.flags &= (uint8)(~(uint32)ETH_30_AR7000_SPI_FLOW_FLAG_READ_MASK);

      /* Check if this is this flow will be processed during the following Eth_30_Ar7000_VSendNextSpiSeq() call */
      if ( Eth_30_Ar7000_RingBufCurProcFlow == Eth_30_Ar7000_RingBufNextPos )
      {
        firstFlowInQueue = TRUE;
      }

      /* Add to buffer */
      ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();
      Eth_30_Ar7000_VAddToRingBuffer(localCtrlIdx, (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA))flow); /* PRQA S 0310 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
      ETH_30_AR7000_END_CRITICAL_SECTION_0();
    }

    /* #50 Trigger processing of SPI working queue */
    /* #60 If state execution return NOT_OK AND ETH_30_AR7000_ENABLE_DET_ON_SPI_BUS_ERROR is enabled
     *       Throw fatal SPI error
     */
    if ( ETH_30_AR7000_SEND_NEXT_SPI_SEQ_NOT_OK == Eth_30_Ar7000_VSendNextSpiSeq(localCtrlIdx) )
    {
      /* Fatal Spi error */
#if ( STD_ON == ETH_30_AR7000_ENABLE_DET_ON_SPI_BUS_ERROR )
      (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_WRITE_SPI, ETH_30_AR7000_E_SPI_PROT_ERROR);
#endif /* ETH_30_AR7000_ENABLE_DET_ON_SPI_BUS_ERROR */
      if (   (resVal == E_OK)
          && (firstFlowInQueue == TRUE) )
      {
        /* If sequence has been scheduled but error during other sequence processing did occur */
        resVal = (Std_ReturnType)ETH_30_AR7000_SPI_ACCESS_ERROR_BUT_SEQ_SCHEDULED;
      }
      else if (resVal == E_OK)
      {
        /* Error during processing of this sequence */
        resVal = E_NOT_OK;
      }
      else
      {
        /* resVal already set from previous Eth_30_Ar7000_VPopFlowFromSLL() call */
      }
    }

    /* Set return value */
    retVal = resVal;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETH_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETH_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_WRITE_SPI, errorId);
  }
#else
  ETH_30_AR7000_DUMMY_STATEMENT(errorId);                                                                               /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Eth_30_Ar7000_ReadSpi
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
FUNC(Eth_30_Ar7000_SpiAccessReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_ReadSpi(
          uint8                                                                    GlobalCtrlIdx,
    P2VAR(uint8,                               AUTOMATIC, ETH_30_AR7000_APPL_DATA) FlowId,
          Eth_30_Ar7000_EndNotificationFctType                                     EndNotification,
          uint16                                                                   RegAddr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2VAR(Eth_30_Ar7000_RegAccessSpiFlow, AUTOMATIC, AUTOMATIC) flow = (P2VAR(Eth_30_Ar7000_RegAccessSpiFlow, AUTOMATIC, AUTOMATIC))NULL_PTR;
  Eth_30_Ar7000_DetErrorType errorId = ETH_30_AR7000_E_NO_ERROR; /* Error ID used for DET check error codes */
  Eth_30_Ar7000_SpiAccessReturnType retVal; /* Return value of this function: Do not initialize here to prevent compiler warnings */
  Std_ReturnType resVal; /* Result value of called functions */
  boolean firstFlowInQueue = FALSE;
  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  retVal = ETH_30_AR7000_SPI_ACCESS_NOT_OK;
  if (Eth_30_Ar7000_ModuleInitialized < ETH_STATE_ACTIVE)
  {
    errorId = ETH_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (localCtrlIdx >= ETH_30_AR7000_MAX_CTRLS_TOTAL)
  {
    errorId = ETH_30_AR7000_E_INV_CTRL_IDX;
  }
  /* EndNotification is allowed to be NULL_PTR */
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Request free SPI flow control element from element pool */
    ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();
    resVal = Eth_30_Ar7000_VPopFlowFromSLL(localCtrlIdx, ETH_30_AR7000_SPI_FLOW_TYPE_REG, (P2VAR(Eth_30_Ar7000_BaseSpiFlow*, AUTOMATIC, ETH_30_AR7000_APPL_DATA)) &flow); /* PRQA S 0310 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
    ETH_30_AR7000_END_CRITICAL_SECTION_0();

    /* #30 Verify that we get a valid element */
    /* #40 Prepare the element for a QCA7005 internal register read
     *     Push the element to the working queue
     */
    if ( E_OK == resVal )
    {
      /* fill flow */
      /* Command word */
      flow->base.cmdWord_1[0]  = ETH_30_AR7000_SPI_CMD_WORD_I_FLAG_MASK ;
      flow->base.cmdWord_1[0] |= ETH_30_AR7000_SPI_CMD_WORD_R_FLAG_MASK ;
      flow->base.cmdWord_1[0] |= (uint8)(( RegAddr & ETH_30_AR7000_SPI_CMD_WORD_ADDR_HIGH_MASK ) >> 8);
      flow->base.cmdWord_1[1]  = (uint8)( RegAddr  & ETH_30_AR7000_SPI_CMD_WORD_ADDR_LOW_MASK );

      /* Callback */
      flow->base.EndNotification = EndNotification;

      /* flags */
      flow->base.flags |= ETH_30_AR7000_SPI_FLOW_FLAG_READ_MASK;

      /* fill flow id */
      *FlowId = flow->base.id;

      ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();
      /* Check if this is this flow will be processed during the following Eth_30_Ar7000_VSendNextSpiSeq() call */
      if ( Eth_30_Ar7000_RingBufCurProcFlow == Eth_30_Ar7000_RingBufNextPos )
      {
        firstFlowInQueue = TRUE;
      }

      /* Add to buffer */
      Eth_30_Ar7000_VAddToRingBuffer(localCtrlIdx, (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA))flow); /* PRQA S 0310 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
      ETH_30_AR7000_END_CRITICAL_SECTION_0();
    }

    /* #50 Trigger processing of SPI working queue */
    /* #60 If state execution return NOT_OK AND ETH_30_AR7000_ENABLE_DET_ON_SPI_BUS_ERROR is enabled
     *       Throw fatal SPI error
     */
    if ( ETH_30_AR7000_SEND_NEXT_SPI_SEQ_NOT_OK == Eth_30_Ar7000_VSendNextSpiSeq(localCtrlIdx) )
    {
      /* Fatal Spi error */
#if ( STD_ON == ETH_30_AR7000_ENABLE_DET_ON_SPI_BUS_ERROR )
      (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_READ_SPI, ETH_30_AR7000_E_SPI_PROT_ERROR);
#endif /* ETH_30_AR7000_ENABLE_DET_ON_SPI_BUS_ERROR */
      if (   (resVal == E_OK)
          && (firstFlowInQueue == TRUE) )
      {
        /* If sequence has been scheduled but error during other sequence processing did occur */
        resVal = (Std_ReturnType)ETH_30_AR7000_SPI_ACCESS_ERROR_BUT_SEQ_SCHEDULED;
      }
      else if (resVal == E_OK)
      {
        /* Error during processing of this sequence */
        resVal = E_NOT_OK;
      }
      else
      {
        /* resVal already set from previous Eth_30_Ar7000_VPopFlowFromSLL() call */
      }
    }

    /* Set return value */
    retVal = resVal;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETH_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETH_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_READ_SPI, errorId);
  }
#else
  ETH_30_AR7000_DUMMY_STATEMENT(errorId);                                                                               /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Eth_30_Ar7000_GetReadSpiResult
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Eth_30_Ar7000_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_GetReadSpiResult(
          uint8                                       GlobalCtrlIdx,
          uint8                                       FlowId,
    P2VAR(uint16, AUTOMATIC, ETH_30_AR7000_APPL_DATA) RegValPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Eth_30_Ar7000_DetErrorType errorId = ETH_30_AR7000_E_NO_ERROR; /* Error ID used for DET check error codes */
  Eth_30_Ar7000_ReturnType retVal = ETH_30_AR7000_RT_NOT_OK; /* Return value of this function */
  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  if (Eth_30_Ar7000_ModuleInitialized < ETH_STATE_ACTIVE)
  {
    errorId = ETH_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (localCtrlIdx >= ETH_30_AR7000_MAX_CTRLS_TOTAL)
  {
    errorId = ETH_30_AR7000_E_INV_CTRL_IDX;
  }
  else if (RegValPtr == NULL_PTR)
  {
    errorId = ETH_30_AR7000_E_INV_POINTER;
  }
  else if (FlowId >= ETH_30_AR7000_MAX_REG_FLOWS)
  {
    errorId = ETH_30_AR7000_E_INV_PARAM;
  }
  else
#else
  if (FlowId >= ETH_30_AR7000_MAX_REG_FLOWS)
  {
    /* return value is already set to Not OK */
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Verify that SPI flow control element is already processed */
    /* #30 Read the requested register value */
    /* #40 Push the used SPI flow control element back to free elements pool (look at VSMStateEnd) */
    ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();
    if ( (Eth_30_Ar7000_RegFlows[FlowId].base.flags & ETH_30_AR7000_SPI_FLOW_FLAG_USED_MASK) != ETH_30_AR7000_SPI_FLOW_FLAG_USED_MASK )
    {
      if (Eth_30_Ar7000_RegFlows[FlowId].base.flowTransmissionFailed == FALSE)
      {
        /* reception occured */
        *RegValPtr  = Eth_30_Ar7000_RegFlows[FlowId].base.regData_1[1];
        *RegValPtr |= (uint16)((uint16)((uint16)Eth_30_Ar7000_RegFlows[FlowId].base.regData_1[0]) << 8);

        retVal = ETH_30_AR7000_RT_OK;
      }
      else
      {
        /* ETH_30_AR7000_RT_NOT_OK already set, just release flow */
      }

      /* Push flow back to SLL */
      /* PRQA S 0310 1 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
      Eth_30_Ar7000_VPushFlowToSLL(localCtrlIdx, (P2VAR(Eth_30_Ar7000_BaseSpiFlow, ETH_30_AR7000_VAR_NOINIT, ETH_30_AR7000_VAR_NOINIT))&Eth_30_Ar7000_RegFlows[FlowId]);
    }
    else
    {
      retVal = ETH_30_AR7000_RT_PENDING;
    }
    ETH_30_AR7000_END_CRITICAL_SECTION_0();
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETH_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETH_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_GET_READ_SPI_RESULT, errorId);
  }
#else
  ETH_30_AR7000_DUMMY_STATEMENT(errorId);                                                                               /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Eth_30_Ar7000_GetCounterState
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3673 4 */ /* MD_MSR_Rule8.13 */
FUNC(Std_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_GetCounterState(
          uint8                                       GlobalCtrlIdx,
          uint16                                      CtrOffs,
    P2VAR(uint32, AUTOMATIC, ETH_30_AR7000_APPL_DATA) CtrValPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Eth_30_Ar7000_DetErrorType errorId = ETH_30_AR7000_E_NO_ERROR; /* Error ID used for DET check error codes */
  Std_ReturnType retVal = E_NOT_OK; /* Return value of this function */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */
  if (Eth_30_Ar7000_ModuleInitialized < ETH_STATE_ACTIVE)
  {
    errorId = ETH_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (localCtrlIdx >= ETH_30_AR7000_MAX_CTRLS_TOTAL)
  {
    errorId = ETH_30_AR7000_E_INV_CTRL_IDX;
  }
  else if (CtrValPtr == NULL_PTR)
  {
    errorId = ETH_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* AUTOSAR conformance */
    /* QCA7005 does not provide any counters, return E_NOT_OK */
    ETH_30_AR7000_DUMMY_STATEMENT(CtrOffs);                                                                             /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
    ETH_30_AR7000_DUMMY_STATEMENT(CtrValPtr);                                                                           /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETH_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETH_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_GET_COUNTER_STATE, errorId);
  }
#else
  ETH_30_AR7000_DUMMY_STATEMENT(errorId);                                                                               /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
  ETH_30_AR7000_DUMMY_STATEMENT(GlobalCtrlIdx);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;

}

/**********************************************************************************************************************
 *  Eth_30_Ar7000_ProvideTxBuffer
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
 */
FUNC(BufReq_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_ProvideTxBuffer(
          uint8                                              GlobalCtrlIdx,
    P2VAR(uint8,        AUTOMATIC, ETH_30_AR7000_APPL_DATA)  BufIdxPtr,
    P2VAR(Eth_DataType, AUTOMATIC, ETH_30_AR7000_APPL_DATA) *BufPtrPtr,
    P2VAR(uint16,       AUTOMATIC, ETH_30_AR7000_APPL_DATA)  LenBytePtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Eth_30_Ar7000_DetErrorType errorId = ETH_30_AR7000_E_NO_ERROR; /* Error ID used for DET check error codes */
  BufReq_ReturnType retVal; /* Return value of this function: Do not initialize here to prevent compiler warnings */
  uint8 txBufferBusyIdx;
  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  retVal = BUFREQ_E_NOT_OK;
  if (Eth_30_Ar7000_ModuleInitialized < ETH_STATE_ACTIVE)
  {
    errorId = ETH_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (localCtrlIdx >= ETH_30_AR7000_MAX_CTRLS_TOTAL)
  {
    errorId = ETH_30_AR7000_E_INV_CTRL_IDX;
  }
  else if (Eth_30_Ar7000_CtrlMode[localCtrlIdx] < ETH_MODE_ACTIVE)
  {
    errorId = ETH_30_AR7000_E_INV_MODE;
  }
  else if (BufIdxPtr == NULL_PTR)
  {
    errorId = ETH_30_AR7000_E_INV_POINTER;
  }
  else if (BufPtrPtr == NULL_PTR)
  {
    errorId = ETH_30_AR7000_E_INV_POINTER;
  }
  else if (LenBytePtr == NULL_PTR)
  {
    errorId = ETH_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();

    /* #20 Verify that requested buffer size and Ethernet header not exceed 1514 byte */
    if (ETH_30_AR7000_TX_MAX_BUF_SIZE < (*LenBytePtr + ETH_30_AR7000_HDR_LEN_BYTE))
    {
      retVal = BUFREQ_E_OVFL;
    }
    else
    {
      txBufferBusyIdx = 0;
      /* #30 Iterate over all transmit buffers
       *      Find a free buffer which can handle the requested buffer size + ethernet frame header size
       */
      while(txBufferBusyIdx < ETH_30_AR7000_TX_BUF_TOTAL)
      {
        if(   ((uint8)ETH_30_AR7000_BUFFER_NOT_BUSY == Eth_30_Ar7000_TxBufferBusyTable[txBufferBusyIdx])
           && ((*LenBytePtr + ETH_30_AR7000_HDR_LEN_BYTE) <= Eth_30_Ar7000_TxBufferLen[txBufferBusyIdx]))
        {
          break;
        }
        txBufferBusyIdx++;
      }

      /* #40 If a free transmit buffer is available
       *        Provide the uint32 aligned buffer, the buffer size and the buffer index to the caller (EthIf)
       *        Lock the used buffer
       */
      if(txBufferBusyIdx < ETH_30_AR7000_TX_BUF_TOTAL)
      {
        uint32 BufIdxU32 =
        Eth_30_Ar7000_TxBufferStart[txBufferBusyIdx] + ETH_30_AR7000_FRAME_AND_SPI_HEADER_OVERHEAD_LEN;
        /* Divide by 4, Configuration tool ensures that it is 4 byte divisable */
        BufIdxU32 = BufIdxU32 / sizeof(Eth_DataType);

        Eth_30_Ar7000_TxBufferBusyTable[txBufferBusyIdx] = (uint8)ETH_30_AR7000_BUFFER_BUSY;
        *BufIdxPtr = txBufferBusyIdx;
        *LenBytePtr = (uint16)(Eth_30_Ar7000_TxBufferLen[txBufferBusyIdx] - ETH_30_AR7000_HDR_LEN_BYTE);
        *BufPtrPtr = &(Eth_30_Ar7000_Ctrl2TxBufferMap[localCtrlIdx].Native[BufIdxU32]);

        retVal = BUFREQ_OK;
      }
      else
      {
        /* all buffers are busy */
        retVal = BUFREQ_E_BUSY;
      }
    }

    ETH_30_AR7000_END_CRITICAL_SECTION_0();
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETH_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETH_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_PROVIDE_TX_BUFFER, errorId);
  }
#else
  ETH_30_AR7000_DUMMY_STATEMENT(errorId);                                                                               /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Eth_30_Ar7000_Transmit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_Transmit(
            uint8                                         GlobalCtrlIdx,
            uint8                                         BufIdx,
            Eth_FrameType                                 FrameType,
            boolean                                       TxConfirmation,
            uint16                                        LenByte,
    P2CONST(uint8,        AUTOMATIC, ETH_30_AR7000_CONST) PhysAddrPtr)
{

  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8 srcAddr[ETH_PHYS_ADDR_LEN_BYTE];

  /* #10 Plausibility check of input parameters not required, all internally called functions will check them */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #20 Get source MAC-Address */
  /* CtrlIdx is checked by all called API's, no DET check is required */
  Eth_30_Ar7000_GetPhysAddr(GlobalCtrlIdx, &srcAddr[0]);

  /* #30 Invoke the transmission */
  return Eth_30_Ar7000_VTransmit(
                                  GlobalCtrlIdx,
                                  BufIdx,
                                  FrameType,
                                  TxConfirmation,
                                  LenByte,
                                  PhysAddrPtr,
                                  &srcAddr[0]);
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

/**********************************************************************************************************************
 *  Eth_30_Ar7000_VTransmit
 *********************************************************************************************************************/
/*!
 *
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
 *
 *
 */
FUNC(Std_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_VTransmit(
            uint8                                         GlobalCtrlIdx,
            uint8                                         BufIdx,
            Eth_FrameType                                 FrameType,
            boolean                                       TxConfirmation,
            uint16                                        LenByte,
    P2CONST(uint8,        AUTOMATIC, ETH_30_AR7000_CONST) DestMacAddrPtr,
    P2CONST(uint8,        AUTOMATIC, ETH_30_AR7000_CONST) SrcMacAddrPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2VAR(Eth_30_Ar7000_BufAccessSpiFlow, AUTOMATIC, AUTOMATIC) flow = NULL_PTR;
  volatile Eth_30_Ar7000_AlignedFrameCacheType bufferPtr;                                                               /* PRQA S 0759, 3203 */ /* MD_Eth_30_Ar7000_UnionForBufferAccess, MD_Eth_30_Ar7000_BufferPtrNotAccessed */
  uint32 bufferIdx;
  uint16 ethTotalLength;
  uint16 spiTotalLength;
  uint16_least u8Idx;
  uint16 localLenByte = LenByte;
  Eth_30_Ar7000_DetErrorType errorId = ETH_30_AR7000_E_NO_ERROR; /* Error ID used for DET check error codes */
  Std_ReturnType retVal = E_NOT_OK; /* Return value of this function */
  Std_ReturnType resVal; /* Result value of called functions */

  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  if (Eth_30_Ar7000_ModuleInitialized < ETH_STATE_ACTIVE)
  {
    errorId = ETH_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (localCtrlIdx >= ETH_30_AR7000_MAX_CTRLS_TOTAL)
  {
    errorId = ETH_30_AR7000_E_INV_CTRL_IDX;
  }
  else if (Eth_30_Ar7000_CtrlMode[localCtrlIdx] < ETH_MODE_ACTIVE)
  {
    errorId = ETH_30_AR7000_E_INV_MODE;
  }
  else if (BufIdx >= ETH_30_AR7000_TX_BUF_TOTAL)
  {
    errorId = ETH_30_AR7000_E_INV_PARAM;
  }
  else if (localLenByte > (Eth_30_Ar7000_TxBufferLen[BufIdx] - ETH_30_AR7000_HDR_LEN_BYTE))
  {
    errorId = ETH_30_AR7000_E_INV_PARAM;
  }
  else if (DestMacAddrPtr == NULL_PTR)
  {
    errorId = ETH_30_AR7000_E_INV_POINTER;
  }
  else if (SrcMacAddrPtr == NULL_PTR)
  {
    errorId = ETH_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();
    /* #20 Verify that we have a valid transmit buffer */
    if((uint8)ETH_30_AR7000_BUFFER_BUSY == Eth_30_Ar7000_TxBufferBusyTable[BufIdx])
    {
      /* #30 Verify the user needs:
       *       + release the buffer (localLenByte == 0) or
       *       + send a 'real' package (localLenByte != 0)
       */
      if ( (uint16)0 == localLenByte)
      {
        Eth_30_Ar7000_TxBufferBusyTable[BufIdx] = (uint8)ETH_30_AR7000_BUFFER_NOT_BUSY;

        retVal = E_OK;
      }
      else
      {
        /* #40 Setup the transmit buffer */
        /* set buffer index and pointer */
        bufferIdx = (uint32)Eth_30_Ar7000_TxBufferStart[BufIdx];
        bufferPtr.U8 = &Eth_30_Ar7000_Ctrl2TxBufferMap[localCtrlIdx].U8[bufferIdx];

        /* #50 Prepare the Ethernet-Frame payload size to be at least 47 byte */
        /* Each buffer has at least a payload data section of 46 bytes (ensured by configuration tool) */
        if ( ETH_30_AR7000_MIN_PAYLOAD > localLenByte)
        {
          for (u8Idx = localLenByte; u8Idx < ETH_30_AR7000_MIN_PAYLOAD; u8Idx++)
          {
            if ((ETH_30_AR7000_VLAN_TPID == FrameType) && (ETH_30_AR7000_VLAN_TAG_LENGTH > u8Idx))
            {
              /* 4 further bytes are used for VLAN tag */
            }
            else
            {
              bufferPtr.U8[ETH_30_AR7000_TX_DATA_OFFSET_U8 + u8Idx] = 0x00U;
            }
          }
          localLenByte = ETH_30_AR7000_MIN_PAYLOAD;
        }

        /* #60 Prepare the SPI message
         * +---------------------------+------------
         * |       Overall Length      | Multiple SPI Frame Header
         * +---------------------------+------------
         * |       Start of Frame      |
         * +---------------------------+
         * |         SPI Length        | SPI Frame Header
         * +---------------------------+
         * |          Reserved         |
         * +---------------------------+------------
         * |        MAC DestAddr       |
         * +---------------------------+
         * |        MAC SrcAddr        | Ethernet Header
         * +---------------------------+
         * | Eth_FrameType (IEEE802.3) |
         * +---------------------------+------------
         * |          Payload          | Upperlayer Data
         * +---------------------------+------------
         * |        End of Frame       | SPI Footer
         * +---------------------------+------------
         */
        /* Length */
        ethTotalLength = localLenByte + ETH_30_AR7000_HDR_LEN_BYTE;
        spiTotalLength = ethTotalLength + ETH_30_AR7000_SPI_OVERALL_FRAME_OVERHEAD;

        /* SPI start of frame */
        bufferPtr.U16[ETH_30_AR7000_TX_SPI_SOF_OFFSET_U16 + 0U] = 0xAAAAU;
        bufferPtr.U16[ETH_30_AR7000_TX_SPI_SOF_OFFSET_U16 + 1U] = 0xAAAAU;

        /* SPI length */
        bufferPtr.U8[ETH_30_AR7000_TX_SPI_LEN_OFFSET_U8 +  0U] = (uint8)(ethTotalLength & 0xFFU);
        bufferPtr.U8[ETH_30_AR7000_TX_SPI_LEN_OFFSET_U8 + 1U] = (uint8)(ethTotalLength >> 8U);

        /* 2 Bytes reserved */
        bufferPtr.U16[ETH_30_AR7000_TX_SPI_RSVD_OFFSET_U16] = 0x0000U;

        /* Assemble Ethernet Header */
        /* Physical destination address */
        bufferPtr.U8[ETH_30_AR7000_TX_DST_OFFSET_U8 + 0U] = DestMacAddrPtr[0U];
        bufferPtr.U8[ETH_30_AR7000_TX_DST_OFFSET_U8 + 1U] = DestMacAddrPtr[1U];
        bufferPtr.U8[ETH_30_AR7000_TX_DST_OFFSET_U8 + 2U] = DestMacAddrPtr[2U];
        bufferPtr.U8[ETH_30_AR7000_TX_DST_OFFSET_U8 + 3U] = DestMacAddrPtr[3U];
        bufferPtr.U8[ETH_30_AR7000_TX_DST_OFFSET_U8 + 4U] = DestMacAddrPtr[4U];
        bufferPtr.U8[ETH_30_AR7000_TX_DST_OFFSET_U8 + 5U] = DestMacAddrPtr[5U];

        /* Physical source address */
        bufferPtr.U8[ETH_30_AR7000_TX_SRC_OFFSET_U8 + 0U] = SrcMacAddrPtr[0U];
        bufferPtr.U8[ETH_30_AR7000_TX_SRC_OFFSET_U8 + 1U] = SrcMacAddrPtr[1U];
        bufferPtr.U8[ETH_30_AR7000_TX_SRC_OFFSET_U8 + 2U] = SrcMacAddrPtr[2U];
        bufferPtr.U8[ETH_30_AR7000_TX_SRC_OFFSET_U8 + 3U] = SrcMacAddrPtr[3U];
        bufferPtr.U8[ETH_30_AR7000_TX_SRC_OFFSET_U8 + 4U] = SrcMacAddrPtr[4U];
        bufferPtr.U8[ETH_30_AR7000_TX_SRC_OFFSET_U8 + 5U] = SrcMacAddrPtr[5U];

        /* Frame type */
        bufferPtr.U16[ETH_30_AR7000_TX_TYPE_OFFSET_U16] = IPBASE_HTON16(FrameType);

        /* Spi footer */
        bufferPtr.U8[ETH_30_AR7000_SPI_HEADER_LENGTH + ethTotalLength] = 0x55U;
        bufferPtr.U8[ETH_30_AR7000_SPI_HEADER_LENGTH + ethTotalLength + 1U] = 0x55U;

        /* #70 Setup a new SPI flow control element and push it to the working queue */
        resVal = Eth_30_Ar7000_VPopFlowFromSLL(localCtrlIdx, ETH_30_AR7000_SPI_FLOW_TYPE_BUF, (P2VAR(Eth_30_Ar7000_BaseSpiFlow*, AUTOMATIC, ETH_30_AR7000_APPL_DATA))&flow); /* PRQA S 0310 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
        if ( E_OK == resVal )
        {
          /* TX Confirmation */
          flow->txConfirmation = TxConfirmation;

          /* Command words */
          flow->base.cmdWord_1[0U]  = ETH_30_AR7000_SPI_CMD_WORD_I_FLAG_MASK;
          flow->base.cmdWord_1[0U] |= ETH_30_AR7000_SPI_CMD_WORD_R_FLAG_MASK;
          flow->base.cmdWord_1[0U] |= (uint8)(( ETH_30_AR7000_SPI_REG_WRBUF_SPC_AVA & ETH_30_AR7000_SPI_CMD_WORD_ADDR_HIGH_MASK ) >> 8U);
          flow->base.cmdWord_1[1U]  = ( ETH_30_AR7000_SPI_REG_WRBUF_SPC_AVA & ETH_30_AR7000_SPI_CMD_WORD_ADDR_LOW_MASK  );

          flow->cmdWord_2[0U]  = ETH_30_AR7000_SPI_CMD_WORD_I_FLAG_MASK;
          flow->cmdWord_2[0U] &= (uint8)(~(uint32)ETH_30_AR7000_SPI_CMD_WORD_R_FLAG_MASK);
          flow->cmdWord_2[0U] |= (uint8)(( ETH_30_AR7000_SPI_REG_BFR_SIZE & ETH_30_AR7000_SPI_CMD_WORD_ADDR_HIGH_MASK ) >> 8U);
          flow->cmdWord_2[1U]  = ( ETH_30_AR7000_SPI_REG_BFR_SIZE & ETH_30_AR7000_SPI_CMD_WORD_ADDR_LOW_MASK  );

          flow->cmdWord_3[0U]  = 0U;
          /* ignore address in command word 3 */

          /* flow */
          flow->regData_2[0U] = (uint8)((( spiTotalLength ) & 0xFF00U ) >> 8U);
          flow->regData_2[1U] = (uint8)(spiTotalLength   & 0x00FFU);
          flow->bufIdx = BufIdx;
          flow->dataSize = spiTotalLength;

          /* Notification */
          flow->base.EndNotification = Eth_30_Ar7000_VTxConfirmation;

          /* flags */
          flow->base.flags &= (uint8)(~(uint32)ETH_30_AR7000_SPI_FLOW_FLAG_READ_MASK);

          Eth_30_Ar7000_VAddToRingBuffer(localCtrlIdx, (P2VAR(Eth_30_Ar7000_BaseSpiFlow, AUTOMATIC, ETH_30_AR7000_APPL_DATA))flow); /* PRQA S 0310 */ /* MD_Eth_30_Ar7000_SpiFLowCast */
        }

        /* Set return value */
        retVal = resVal;
      }
    }

    ETH_30_AR7000_END_CRITICAL_SECTION_0();

    /* #80 Trigger processing of SPI working queue */
    /* #90 If state execution return NOT_OK AND ETH_30_AR7000_ENABLE_DET_ON_SPI_BUS_ERROR is enabled
     *       Throw fatal SPI error
     */
    if ( ETH_30_AR7000_SEND_NEXT_SPI_SEQ_NOT_OK == Eth_30_Ar7000_VSendNextSpiSeq(localCtrlIdx) )
    {
#if ( STD_ON == ETH_30_AR7000_ENABLE_DET_ON_SPI_BUS_ERROR )
      /* Fatal Spi error */
      (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_TRANSMIT, ETH_30_AR7000_E_SPI_PROT_ERROR);
#endif /* ETH_30_AR7000_ENABLE_DET_ON_SPI_BUS_ERROR */
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETH_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETH_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_TRANSMIT, errorId);
  }
#else
  ETH_30_AR7000_DUMMY_STATEMENT(errorId);                                                                               /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
} /* PRQA S 6030, 6060, 6080 */ /* MD_MSR_STCYC, MD_MSR_STPAR, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Eth_30_Ar7000_Receive
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, ETH_30_AR7000_CODE_ISR) Eth_30_Ar7000_Receive(
          uint8                                                GlobalCtrlIdx,
    P2VAR(Eth_RxStatusType, AUTOMATIC, ETH_30_AR7000_APPL_VAR) RxStatusPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Eth_30_Ar7000_DetErrorType errorId = ETH_30_AR7000_E_NO_ERROR; /* Error ID used for DET check error codes */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */
  if (Eth_30_Ar7000_ModuleInitialized < ETH_STATE_ACTIVE)
  {
    errorId = ETH_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (localCtrlIdx >= ETH_30_AR7000_MAX_CTRLS_TOTAL)
  {
    errorId = ETH_30_AR7000_E_INV_CTRL_IDX;
  }
  else if (Eth_30_Ar7000_CtrlMode[localCtrlIdx] < ETH_MODE_ACTIVE)
  {
    errorId = ETH_30_AR7000_E_INV_MODE;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 If driver mode == polling
     *       Manually trigger a asynchronous read if a a package is available
     */
#if ((STD_OFF == ETH_30_AR7000_ENABLE_TX_INTERRUPT) && (STD_OFF == ETH_30_AR7000_ENABLE_RX_INTERRUPT))
    /* check that last request is already served. Avoids that ring buffer overruns when Eth_30_Ar7000_Receive is triggered faster
     * than SPI */
    if (ETH_30_AR7000_MAX_INTR_REQ_POLLING_MODE > Eth_30_Ar7000_IntrCauseReqPending)
    {
      uint8 flowId;
      /* Read interrupt cause register */
      (void)Eth_30_Ar7000_ReadSpi(GlobalCtrlIdx, &flowId, Eth_30_Ar7000_VInterruptCauseNotification, ETH_30_AR7000_SPI_REG_INTR_CAUSE);
      Eth_30_Ar7000_IntrCauseReqPending++;
    }
#endif /* ETH_30_AR7000_ENABLE_TX_INTERRUPT && ETH_30_AR7000_ENABLE_RX_INTERRUPT */

    /* always return not_received to indicate that the EthIf must not call this function a second time */
    *RxStatusPtr = ETH_NOT_RECEIVED;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETH_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETH_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_RECEIVE, errorId);
  }
#else
  ETH_30_AR7000_DUMMY_STATEMENT(errorId);                                                                               /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
  ETH_30_AR7000_DUMMY_STATEMENT(GlobalCtrlIdx);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
#endif
}

/**********************************************************************************************************************
 *  Eth_30_Ar7000_TxConfirmation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, ETH_30_AR7000_CODE_ISR) Eth_30_Ar7000_TxConfirmation(
    uint8 GlobalCtrlIdx)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Eth_30_Ar7000_DetErrorType errorId = ETH_30_AR7000_E_NO_ERROR; /* Error ID used for DET check error codes */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */
  if (Eth_30_Ar7000_ModuleInitialized < ETH_STATE_ACTIVE)
  {
    errorId = ETH_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (localCtrlIdx >= ETH_30_AR7000_MAX_CTRLS_TOTAL)
  {
    errorId = ETH_30_AR7000_E_INV_CTRL_IDX;
  }
  else if (Eth_30_Ar7000_CtrlMode[localCtrlIdx] < ETH_MODE_ACTIVE)
  {
    errorId = ETH_30_AR7000_E_INV_MODE;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* nothing to do here - the user may decide to disable/not trigger the EthIf_MainfunctionTx function */
    /* The TX Confirmation runs in context of the SPI notification. In case the SPI driver runs in polling mode, the
     * TX confirmation does not run in interrupt context either.
     */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETH_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETH_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_TX_CONFIRMATION, errorId);
  }
#else
  ETH_30_AR7000_DUMMY_STATEMENT(errorId);                                                                               /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
  ETH_30_AR7000_DUMMY_STATEMENT(GlobalCtrlIdx);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
#endif
}

#if (ETH_30_AR7000_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  Eth_30_Ar7000_GetVersionInfo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_GetVersionInfo(
    P2VAR(Std_VersionInfoType, ETH_30_AR7000_APPL_DATA, ETH_30_AR7000_APPL_DATA)  VersionInfoPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Eth_30_Ar7000_DetErrorType errorId = ETH_30_AR7000_E_NO_ERROR; /* Error ID used for DET check error codes */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  if (VersionInfoPtr == NULL_PTR)
  {
    errorId = ETH_30_AR7000_E_INV_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Write component data to versioninfo */
    VersionInfoPtr->vendorID = ETH_30_AR7000_VENDOR_ID;
    VersionInfoPtr->moduleID = ETH_30_AR7000_MODULE_ID;
    VersionInfoPtr->sw_major_version = ETH_30_AR7000_SW_MAJOR_VERSION;
    VersionInfoPtr->sw_minor_version = ETH_30_AR7000_SW_MINOR_VERSION;
    VersionInfoPtr->sw_patch_version = ETH_30_AR7000_SW_PATCH_VERSION;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETH_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETH_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, Eth_30_Ar7000_TransformToGlobalCtrlIdx(0U), ETH_30_AR7000_API_ID_GET_VERSION_INFO, errorId); /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */
  }
#else
  ETH_30_AR7000_DUMMY_STATEMENT(errorId);                                                                               /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
#endif
}
#endif /* ETH_30_AR7000_VERSION_INFO_API */

/**********************************************************************************************************************
 *  Eth_30_Ar7000_SpiFlowHdlr
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC (void, ETH_30_AR7000_CODE_ISR) Eth_30_Ar7000_SpiFlowHdlr(
    uint8 GlobalCtrlIdx)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Eth_30_Ar7000_DetErrorType errorId = ETH_30_AR7000_E_NO_ERROR; /* Error ID used for DET check error codes */

  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  if (Eth_30_Ar7000_ModuleInitialized < ETH_STATE_ACTIVE)
  {
    errorId = ETH_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (localCtrlIdx >= ETH_30_AR7000_MAX_CTRLS_TOTAL)
  {
    errorId = ETH_30_AR7000_E_INV_CTRL_IDX;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Trigger processing of SPI working queue */
    /* #30 If state execution return NOT_OK AND ETH_30_AR7000_ENABLE_DET_ON_SPI_BUS_ERROR is enabled
     *       Throw fatal SPI error
     */
    if ( ETH_30_AR7000_SEND_NEXT_SPI_SEQ_NOT_OK == Eth_30_Ar7000_VSendNextSpiSeq(localCtrlIdx) )
    {
#if ( STD_ON == ETH_30_AR7000_ENABLE_DET_ON_SPI_BUS_ERROR )
      (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_SPI_FLOW_HDLR, ETH_30_AR7000_E_SPI_PROT_ERROR);
#endif
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETH_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETH_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_SPI_FLOW_HDLR, errorId);
  }
#else
  ETH_30_AR7000_DUMMY_STATEMENT(errorId);                                                                               /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
#endif
}

#if ((STD_ON == ETH_30_AR7000_ENABLE_TX_INTERRUPT) && (STD_ON == ETH_30_AR7000_ENABLE_RX_INTERRUPT))
/**********************************************************************************************************************
 *  Eth_30_Ar7000_Ar7000IrqHdlr
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
 */
FUNC (void, ETH_30_AR7000_CODE_ISR) Eth_30_Ar7000_Ar7000IrqHdlr(
    uint8 GlobalCtrlIdx)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Eth_30_Ar7000_DetErrorType errorId = ETH_30_AR7000_E_NO_ERROR;
  uint8 flowId;

  uint8 localCtrlIdx = Eth_30_Ar7000_TransformToLocalCtrlIdx(GlobalCtrlIdx);                                            /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */

  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  /* #10 Check plausibility of input parameters */
#if ( ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON )
  if (Eth_30_Ar7000_ModuleInitialized == ETH_STATE_UNINIT)
  {
    errorId = ETH_30_AR7000_E_NOT_INITIALIZED;
  }
  else if (localCtrlIdx >= ETH_30_AR7000_MAX_CTRLS_TOTAL)
  {
    errorId = ETH_30_AR7000_E_INV_CTRL_IDX;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Verify that QCA7005 is ACTIVE
     *       Handle QCA7005 'packet available' interrupt:
     *         + Disable all interrupts on the QCA7005 slave
     *         + Perform a buffer read operation,
     *           invoked by VInterruptCauseNotification during read of the interrupt cause register
     *         + Clear 'packet available' interrupt is done by QCA7005 itself
     *         + Enable 'package available' interrupt (not part of this Routine)
     */
    if (Eth_30_Ar7000_CtrlMode[localCtrlIdx] == ETH_MODE_ACTIVE)
    {

      ETH_30_AR7000_BEGIN_CRITICAL_SECTION_1();

      /* Disable interrupts, do not retry here in case of errors. Interrupt register will be read cyclically */
      Eth_30_Ar7000_InterruptEnableRetry[localCtrlIdx] = FALSE;
      (void)Eth_30_Ar7000_WriteSpi(GlobalCtrlIdx, ETH_30_AR7000_SPI_REG_INTR_ENABLE, ETH_30_AR7000_SPI_INTEN_DISABLE);

      /* Read interrupt cause register */
      (void)Eth_30_Ar7000_ReadSpi(GlobalCtrlIdx, &flowId, Eth_30_Ar7000_VInterruptCauseNotification, ETH_30_AR7000_SPI_REG_INTR_CAUSE);

      ETH_30_AR7000_END_CRITICAL_SECTION_1();
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
#if ( ETH_30_AR7000_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETH_30_AR7000_E_NO_ERROR)
  {
    (void)Det_ReportError(ETH_30_AR7000_MODULE_ID, GlobalCtrlIdx, ETH_30_AR7000_API_ID_AR7000_IRQ_HDLR, errorId);
  }
#else
  ETH_30_AR7000_DUMMY_STATEMENT(errorId);                                                                               /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt, MD_MSR_DummyStmt */ /*lint !e438 */
#endif
}
#endif /* ETH_30_AR7000_ENABLE_TX_INTERRUPT && ETH_30_AR7000_ENABLE_RX_INTERRUPT */

/**********************************************************************************************************************
 *  Eth_30_Ar7000_MainFunction
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
 FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_MainFunction( void )
{
   /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8 flowId;
#if ( STD_ON == ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT )
  uint8 flowId_Signature;
#endif /* ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT */
  uint8 globalCtrlIdx = Eth_30_Ar7000_TransformToGlobalCtrlIdx(0U);                                                     /* PRQA S 2985 */ /* MD_Eth_30_Ar7000_CtrlTransform */

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Verify that QCA7005 is ACTIVE
   *       Poll QCA7005 IRQ cause register every ETH_30_AR7000_IRQ_POLL_TICKS
   *       Update MainFunction call counter
   *       Perform Out-Of-Sync detection if enabled
   *       Perform QCA7005 buffer error detection if enabled
   */
  /* Use local controller index, multiple controller instances are not supported */
  if (ETH_MODE_ACTIVE == Eth_30_Ar7000_CtrlMode[0U])
  {
    if ( (Eth_30_Ar7000_CycleCnt % ETH_30_AR7000_IRQ_POLL_TICKS) == 0U)
    {
      /* Check for interrupts */
      (void)Eth_30_Ar7000_ReadSpi(globalCtrlIdx, &flowId, Eth_30_Ar7000_VOnCpuRunning, ETH_30_AR7000_SPI_REG_INTR_CAUSE);
    }

    /* Out of sync detection (if OUT_OF_SYNC_DETECT enabled) */
#if ( STD_ON == ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT )
    if( (Eth_30_Ar7000_CycleCnt % ETH_30_AR7000_OUT_OF_SYNC_POLL_TICKS) == 0U)
    {
      ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();
      if (0u == Eth_30_Ar7000_ReadSignatureAttempts)
      {
        ETH_30_AR7000_END_CRITICAL_SECTION_0();
        (void)ETH_30_AR7000_RST_CBK_AFTER_OSD(globalCtrlIdx, ETH_30_AR7000_OSD_HARD_RESET_NECESSARY);
      }
      else
      {
        /* ESCAN00101424: Decremet before reading the register, because read may be done faster than the call returns */
        Eth_30_Ar7000_ReadSignatureAttempts--;
        ETH_30_AR7000_END_CRITICAL_SECTION_0();
        (void)Eth_30_Ar7000_ReadSpi(globalCtrlIdx, &flowId_Signature, Eth_30_Ar7000_VOutOfSyncDetect, ETH_30_AR7000_SPI_REG_SIGNATURE);
      }
    }
#endif /* ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT */

    Eth_30_Ar7000_CycleCnt++;

#if (STD_ON == ETH_30_AR7000_ENABLE_SPI_BUF_ERR_DETECT)
    /* The frequency is the same than used to poll the INTR Cause register,
     * however the offset is modified by factor *3/2 so that the two registers are read alternately.
     */
    if ( (Eth_30_Ar7000_CycleCnt % ((ETH_30_AR7000_IRQ_POLL_TICKS*3U)/2U)) == 0U)
    {
      (void)Eth_30_Ar7000_ReadSpi(globalCtrlIdx, &flowId, Eth_30_Ar7000_VSpiStatus, ETH_30_AR7000_SPI_REG_STATUS);
    }
#endif /* ETH_30_AR7000_ENABLE_SPI_BUF_ERR_DETECT */

#if ((STD_ON == ETH_30_AR7000_ENABLE_TX_INTERRUPT) && (STD_ON == ETH_30_AR7000_ENABLE_RX_INTERRUPT))
    ETH_30_AR7000_BEGIN_CRITICAL_SECTION_1();
    if ( Eth_30_Ar7000_InterruptEnableRetry[0U] == TRUE )
    {
      /* Enable interrupts */
      if ( E_NOT_OK == Eth_30_Ar7000_WriteSpi(globalCtrlIdx, ETH_30_AR7000_SPI_REG_INTR_ENABLE, ETH_30_AR7000_SPI_INTEN_ENABLE) )
      {
        Eth_30_Ar7000_InterruptEnableRetry[0U] = TRUE;
      }
      else
      {
        Eth_30_Ar7000_InterruptEnableRetry[0U] = FALSE;
      }
    }
    ETH_30_AR7000_END_CRITICAL_SECTION_1();
#endif /* ETH_30_AR7000_ENABLE_TX_INTERRUPT && ETH_30_AR7000_ENABLE_RX_INTERRUPT */

  /* Out of sync detection (if OUT_OF_SYNC_DETECT enabled) */
#if ( STD_ON == ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT )
    ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0();
    if (0U == Eth_30_Ar7000_RxDropCnt)
    {
      Eth_30_Ar7000_RxDropCnt = ETH_30_AR7000_RECOV_ATTEMPTS_AFTER_OSD;
      ETH_30_AR7000_END_CRITICAL_SECTION_0();

# if ( ETH_30_AR7000_DEM_ERROR_DETECT == STD_ON )
      ETH_30_AR7000_DEM_REPORT_ERROR_STATUS_ETH_30_AR7000_E_ACCESS(0U);
# endif /* ETH_30_AR7000_DEM_ERROR_DETECT */

      (void)ETH_30_AR7000_RST_CBK_AFTER_OSD(globalCtrlIdx, ETH_30_AR7000_OSD_SPI_RESET_NECESSARY);
    }
    else
    {
      ETH_30_AR7000_END_CRITICAL_SECTION_0();
    }
#endif /* ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT */
  }
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

#define ETH_30_AR7000_STOP_SEC_CODE
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* module specific MISRA deviations:
 MD_Eth_30_Ar7000_UnionForBufferAccess:
      Reason:     A union is used to access the uint32 Eth_DataType as uint8 byte array without casting all the time.
                  This results in a better code readability.
      Risk:       Buffer may be accessed out of bound in case the calculation is wrong.
      Prevention: Covered by code review.
 MD_Eth_30_Ar7000_BufferPtrNotAccessed:
      Reason:     The variable bufferPtr is volatile, because it is only written in this API. It is used for easier
                  write access of the transmit buffer. The transmit buffer will be identified by
                  "flow->bufIdx = BufIdx" during the real transmission.
      Risk:       There is no risk.
      Prevention: Covered by code review.
 MD_Eth_30_Ar7000_BufferCast:
      Reason:     Due to alignment and optimization reasons the Eth_DataType is of type uint32. However the buffer
                  needs to be accessed bytewise. Therefor a cast to uint8* is required to access the correct buffer
                  position.
      Risk:       Buffer may be accessed out of bound in case the calculation is wrong.
      Prevention: Covered by code review.
 MD_Eth_30_Ar7000_CastToSpiDataType:
      Reason:     For transmission of data elements on the SPI line it is required to cast the to the SPI data
                  type. This data type may be more or less strict than the data elements that shall be set. The
                  length will always be corrected by the customer template file Eth_30_Ar7000_Spi.h.
      Risk:       Customer may calculate the wrong size of an element.
      Prevention: Covered by code review at Vector and customer.
 MD_Eth_30_Ar7000_CastBeforeShift:
      Reason:     The value of the variable shall be shifted out side its data type boundaries, therefore it is
                  required to cast it to a wider data type first.
      Risk:       No risk.
      Prevention: Not required.
 MD_Eth_30_Ar7000_BufFlow_NotConst:
      Reason:     This variable is not of type P2CONST, because it is used within the SPI abstraction macros.
                  Since this macros are used in multiple positions, they have to be used always the same way.
                  Therefore this variable must not be CONST.
      Risk:       No risk.
      Prevention: Not required.
 MD_Eth_30_Ar7000_SpiFLowCast:
      Reason:     Casting is used to support C-style inheritance. A pointer to a Eth_30_Ar7000_RegAccessSpiFlow or
                  Eth_30_Ar7000_BufAccessSpiFlow object is always a pointer to a Eth_30_Ar7000_BaseSpiFlow object, too.
                  This is necessary to administrate buffer and register structures in a single
                  ring buffer array.
      Risk:       This is a design consideration and has no risk since the type of structure is
                  checked before the cast is done
      Prevention: Covered by code review.
 MD_Eth_30_Ar7000_SpiFLowPointerLifeTime:
      Reason:     The SPI flows are global variables, which are provided to this API within the parameter 'Element'.
                  This global elements do have the same lifetime as the global variable they are stored to.
      Risk:       Wrong/local pointers may be provided to this API, which may lead to later invalid memory accesses.
      Prevention: Covered by code review.
 MD_Eth_30_Ar7000_CtrlTransform:
      Reason:     The macros Eth_30_Ar7000_TransformToGlobalCtrlIdx and Eth_30_Ar7000_TransformToLocalCtrlIdx are
                  used to convert the global controller index to a local controller index and the other way around.
                  The occurrence of this deviation depends on configuration. The offset may be zero in case the
                  controller is the first one in the configuration.
      Risk:       There is no risk.
      Prevention: Is not required.
 MD_Eth_30_Ar7000_SpiDataType:
      Reason:     The size of the Spi_DataType is configured using a none AUTOSAR configuration parameter. Therefore
                  it is not possible to perform this sizeof() check in the configuration. Since sizeof() cannot be
                  used within pre-processor checks, this check has to be performed during run time. Therefore there
                  are configurations that will issue that the following condition is always TRUE or always FALSE.
                  In case of 'always FALSE' the compiler or tool may issue that the code within the 'if' condition
                  is unreachable. There for this warnings may be active for multiple compilers.
                  Note: This warning will only be active in the is the SPI legacy mode. Qualcomm recommends to use
                  the burst mode instead. The legacy mode shall not be used anymore.
      Risk:       There is no risk.
      Prevention: Covered by code review.
 MD_Eth_30_Ar7000_RecursiveCalls:
      Reason:     The APIs Eth_30_Ar7000_VSendNextSpiSeq and Eth_30_Ar7000_VSMStateEnd are calling each other
                  recursively in specific states. As soon as one SPI sequence is processed completely, the next
                  sequence is started. Productive systems shall always use asynchronous SPI sequence transmission.
                  Therefore the state machine ensures that the depth of the recursive calls is at maximum 1. For
                  synchronous SPI handling during the first development steps it may happen that the recursive call
                  depth is higher.
      Risk:       Possible stack overflows that should be detected by the operating system.
      Prevention: Covered by code review.
*/

/**********************************************************************************************************************
 *  END OF FILE: Eth_30_Ar7000.c
 *********************************************************************************************************************/
