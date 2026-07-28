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
/**        \file  Eth_30_Ar7000.h
 *        \brief  Ethernet driver QCA 7005 main header file
 *
 *      \details  Vector static code main header file for the Ethernet driver QCA 7005 module.
 *
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2011-05-27  haw     -             Creation
 *  02.00.00  2012-02-14  haw     ESCAN00056807 Adapted implementation to QCA7000 behavior.
 *                                              PL14 board is not supported anymore!
 *                                ESCAN00056209 Compiler error: When a little endian machine is used a compiler error
 *                                              occurs due to a missing bracket
 *                                ESCAN00056208 V850 MCAL does not allow a common SPI Sequence End Notification for
 *                                              more than one SPI sequence
 *  02.00.01  2012-04-02  haw     ESCAN00058083 Switching controller mode from active to down and back to active
 *                                              leads to a loss of communication
 *                                ESCAN00058085 RX Frames get partly lost on high traffic situations
 *                                ESCAN00058138 Eth_ProvideTxBuffers provides only buffer sizes for payloads
 *                                              of 1498 bytes instead of 1500 bytes. Wrong frame padding.
 *  02.00.02  2012-04-10  haw     ESCAN00058191 Compiler error: Compiler errors with DiabData compiler due to
 *                                              implicit casts
 *  02.00.03  2012-04-10  haw     ESCAN00058199 DET error ETH_E_SPI_PROT_ERROR may occur by mistake
 *                                ESCAN00058613 Transceiver freezes on an MPC platform when receiving frames
 *                                              with odd payload lengths
 *  02.01.00  2012-05-30  haw     ESCAN00059190 Enable error detection for Out-Of-Sync situations and add
 *                                              runtime error handling
 *  02.02.00  2012-07-02  haw     ESCAN00059680 Runtime exception on TriCore platforms due to unaligned memory access
 *                                ESCAN00059512 AR4-125: Remove support for v_cfg.h in Cfg5 systems
 *                                ESCAN00056451 Use ETH_USE_DUMMY_STATEMENT define instead of V_USE_DUMMY_STATEMENT
 *                                ESCAN00060217 MISRA-C:2004 compliance
 *                                ESCAN00059812 Introduce Eth_GetSourceAddressLatch API
 *                                ESCAN00060908 Parse VLAN Tags within received Ethernet headers
 *                                ESCAN00059812 Introduce Eth_GetSourceAddressLatch API
 *                                ESCAN00056351 Remove Macro support for Version Info API
 *  02.02.01  2012-10-12  haw     ESCAN00062123 ASR4 Enhancement
 *                                ESCAN00062246 AR4-220: Remove STATIC
 *                                ESCAN00062852 Redesigned usage of exclusive areas to avoid race conditions
 *                                ESCAN00062855 Interrupt generation of AR700 partly stops when receiving a burst of
 *                                              frames at a time
 *  02.03.00  2012-11-26  haw     ESCAN00063261 Introduce Eth_GetDestinationAddressLatch API
 *                                ESCAN00063621 Received packets may be discarded since they are assumed to be
 *                                              corrupt by mistake
 *  02.04.00  2013-02-08  haw     ESCAN00064386 Introduce application callback function for the controller's
 *                                              MAC address
 *                                ESCAN00065445 Reading a SPI register via Eth_ReadSpi without using a confirmation
 *                                              does not work
 *                                ESCAN00065437 Parsing error of received corrupt Ethernet frames when SPI interface
 *                                              is not ready
 *  02.04.01  2013-03-12  haw     ESCAN00065786 Nested exclusive areas avoid usage of OS resources instead of
 *                                              disabling all interrupts
 *                                ESCAN00065437 Resubmitted: Parsing error of received corrupt Ethernet frames
 *                                              when SPI interface is not ready
 *  02.05.00  2013-04-22  haw     ESCAN00066726 Metrowerks Compiler: Wrong memory access when assembling Ethernet
 *                                              header. Issue with excessive cast
 *                                ESCAN00066797 Handler for external edge-triggered interrupt line is not an ISR but a
 *                                              notification function for ICU module
 *  02.05.01  2013-04-23  haw     ESCAN00066726 Resubmitted: Metrowerks Compiler: Wrong memory access when assembling
 *                                              Ethernet header. Issue with excessive cast
 *                                ESCAN00065786 Resubmitted: Nested exclusive areas avoid usage of OS resources instead
 *                                              of disabling all interrupts
 *  02.06.00  2013-05-03  haw     ESCAN00067100 Change SPI interface to avoid unaligned Ethernet payload addresses
 *                                ESCAN00067101 Reworked critical sections: Added critical section into SPI state
 *                                              machine
 *  02.07.00  2013-11-19  haw     ESCAN00072048 Extend Out-of-Sync detection to detect faulty operating SPI drivers
 *  02.07.01  2013-11-29  haw     ESCAN00072368 Potential race condition due to wrong critical section handling
 *  02.08.00  2013-12-10  haw     ESCAN00072551 Unaligned access trap on RH850, when Ethernet buffers are mapped to
 *                                              a 2 byte offset for proper payload alignment
 *                                ESCAN00072749 Polling mode not working
 *  02.08.01  2014-02-03  haw     ESCAN00072551 Unaligned access trap on RH850, when Ethernet buffers are mapped to
 *                                              a 2 byte offset for proper payload alignment
 *  03.00.00  2014-08-04  haw     ESCAN00077581 Breaking Change ASR4 Release 8/ Java7
 *                                ESCAN00072174 RH850: Unaligned memory access exception in function Eth_Transmit
 *                                              and Eth_VCheckSpiHeader.
 *                                ESCAN00056430 VAR_INIT / VAR_ZERO_INIT Memory Mapping sections
 *  03.01.00  2014-10-29  haw     ESCAN00079180 Implement callback routine for read and write buffer errors, that
 *                                              are reported by the QCA
 *  03.02.00  2015-03-25  vismha  ESCAN00082050 AR4-535: RTM Runtime Measurement Points
 *  04.00.00  2015-07-15  vismha  ESCAN00083988 Introduce API infixing
 *            2015-07-23  vismha  ESCAN00084165 Introduce Transmission API that allows to define the source MAC
 *                                              address of the Ethernet frame
 *            2015-07-24  vismha  ESCAN00084203 Separate polling frequency of IRQ and signature register
 *            2015-07-29  vismha  ESCAN00084270 Support packet filtering by Eth_UpdatePhysAddressFilter API
 *  04.00.01  2015-11-30  vismha  ESCAN00086876 Controller index is not handled correct internally
 *                                ESCAN00085949 Ethernet Frames with odd length aren't received
 *  05.00.00  2016-03-24  vissop  ESCAN00089088 Fix: Move Eth_PhysAddrType to Eth_GeneralTypes.h (Update to R14)
 *            2016-03-29  vissop  ESCAN00088699 Fix: External FW download: CPU_ON is never set by QCA
 *            2016-03-29  vissop  ESCAN00085016 Fix: Inconsistent access to the SPI working queue (re-add IsProcLocked)
 *  05.00.01  2016-05-31  vismha  ESCAN00090231 Default MemMap.h lacks section ETH_30_AR7000_VAR_NOINIT_BUFFER
 *  06.00.00  2016-08-09  vissop  ESCAN00091387 Add: MSR4 R16: Buffer segmentation
 *            2016-08-09  vissop  ESCAN00084531 Fix: Set ModuleID to 88 as specified by AUTOSAR (previously 430)
 *            2016-08-10  vissop  ESCAN00085413 Fix: Use configured default MAC address if NvM is not used to store it
 *            2016-08-10  vissop  ESCAN00087238 Fix: Remove compiler warnings
 *            2016-08-10  vissop  ESCAN00091181 Fix: Add source file defines to Eth_30_Ar7000.c and Eth_30_Ar7000_Irq.c
 *            2016-08-15  vissop  ESCAN00091471 Add: Define all SPI API's and data types in _Eth_30_Ar7000_Spi.h
 *  06.00.01  2016-11-14  vissop  ESCAN00092039 Fix: Remove local static variables
 *            2016-11-14  vissop  ESCAN00092044 Fix: Split up controller mode and initialized state
 *  06.00.02  2017-08-10  vissop  ESCAN00095639 Fix: SPI communication stops, extend critical section (remove IsProcLocked)
 *  06.00.03  2017-11-29  visfmo  ESCAN00097593 Add: Add Component Detailed Design (CDD)
 *  06.01.00  2018-02-12  vissop  STORYC-4254   Add: Implementation review integration from 6.00.03
 *            2018-02-12  vissop  ESCAN00099858 Fix: SPI buffer error detection call back may be called with a wrong value
 *  07.00.00  2018-07-03  vissop  STORYC-3891   Add: Process 3.0
 *            2018-07-03  vissop  ESCAN00099839 Fix: SPI out of sync detection is called before controller init is called
 *            2018-08-20  vissop  -             Fix: Rename local variables to fix MISRA findings
 *  07.00.01  2018-09-28  vissop  ESCAN00100719 Fix: Det_ReportError in Eth_30_Ar7000_Ar7000IrqHdlr if multiple Ethernet-Controller are available
 *            2018-09-28  vissop  ESCAN00100447 Fix: Compiler error: In function Eth_30_Ar7000_Init in case MAC write access is enabled
 *  07.00.02  2019-01-09  vissop  ESCAN00100760 Fix: Possible frame loss in case PLC packets are received directly after each other
 *            2019-01-09  vissop  ESCAN00101424 Fix: Out-of-Sync detection issues an error even if all signature values are correct
 *  07.00.03  2019-01-21  vissop  STORYC-7490   Fix: Tool findings
 *  07.00.04  2019-04-18  vissop  ESCAN00102922 Fix: Compiler error: E_PENDING is not defined
 *  08.00.00  2019-11-08  vissop  V2G-225       Add: Multiplexing for vendor specific MME frames to Trcv and general to EthIf
 *  09.00.00  2020-03-12  visiay  V2G-499       Add: Changed to MISRA2012
 *            2020-03-30  vissop  ESCAN00105328 Fix: Possible array out of bounds access in API Eth_30_Ar7000_GetReadSpiResult and Eth_30_Ar7000_VSMStateEnd
 *  09.00.01  2020-07-13  vissop  ESCAN00106167 Fix: Compiler error: Spi_DataType unknown identifier with MCAL version 4.1.1 and later
 *  09.00.02  2021-01-19  vissop  ESCAN00108106 Fix: Interrupt section ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0 is enabled twice
 *            2021-01-20  vissop  ESCAN00107284 Fix: States and counters may get invalid values due to missing interrupt lock sections
 *            2021-01-20  vissop  ESCAN00107458 Fix: Wrong controller index conversion in the API Eth_30_Ar7000_VReceive
 **********************************************************************************************************************/

#ifndef ETH_30_AR7000_H
#define ETH_30_AR7000_H


/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
#include "Eth_30_Ar7000_Lcfg.h"

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/* ##V_CFG_MANAGEMENT ##CQProject :   DrvEth_Ar7000EthAsr CQComponent : Implementation */
/* BCD coded version number */
#define DRVETH_AR7000ETHASR_VERSION                   0x0900U
/* BCD coded release version number  */
#define DRVETH_AR7000ETHASR_RELEASE_VERSION           0x02U

/* Component Version Information, decimal encoded */
#define ETH_30_AR7000_SW_MAJOR_VERSION                9U
#define ETH_30_AR7000_SW_MINOR_VERSION                0U
#define ETH_30_AR7000_SW_PATCH_VERSION                2U


/* AUTOSAR 4.x Software Specification Version Information */
#define ETH_30_AR7000_AR_RELEASE_MAJOR_VERSION       (0x04U)
#define ETH_30_AR7000_AR_RELEASE_MINOR_VERSION       (0x01U)
#define ETH_30_AR7000_AR_RELEASE_REVISION_VERSION    (0x01U)

/* vendor and module identification */
#define ETH_30_AR7000_VENDOR_ID                      (30U)
#define ETH_30_AR7000_MODULE_ID                      (88U)
/* ETH ApiIds */
#define ETH_30_AR7000_API_ID_INIT                    (0x01U)
#define ETH_30_AR7000_API_ID_CONTROLLER_INIT         (0x02U)
#define ETH_30_AR7000_API_ID_SET_CONTROLLER_MODE     (0x03U)
#define ETH_30_AR7000_API_ID_GET_CONTROLLER_MODE     (0x04U)
#define ETH_30_AR7000_API_ID_WRITE_SPI               (0x05U)
#define ETH_30_AR7000_API_ID_READ_SPI                (0x06U)
#define ETH_30_AR7000_API_ID_GET_COUNTER_STATE       (0x07U)
#define ETH_30_AR7000_API_ID_GET_PHYS_ADDR           (0x08U)
#define ETH_30_AR7000_API_ID_SET_PHYS_ADDR           (0x09U)
#define ETH_30_AR7000_API_ID_UPDATE_PHYS_ADDR_FILTER (0x0AU)
#define ETH_30_AR7000_API_ID_PROVIDE_TX_BUFFER       (0x0BU)
#define ETH_30_AR7000_API_ID_TRANSMIT                (0x0CU)
#define ETH_30_AR7000_API_ID_RECEIVE                 (0x0DU)
#define ETH_30_AR7000_API_ID_TX_CONFIRMATION         (0x0EU)
#define ETH_30_AR7000_API_ID_GET_VERSION_INFO        (0x0FU)
#define ETH_30_AR7000_API_ID_GET_READ_SPI_RESULT     (0x10U)
#define ETH_30_AR7000_API_ID_SPI_FLOW_HDLR           (0x11U)
#define ETH_30_AR7000_API_ID_AR7000_IRQ_HDLR         (0x12U)
#define ETH_30_AR7000_API_ID_MAIN_FUNCTION           (0x13U)
#define ETH_30_AR7000_API_ID_GET_PACKET              (0x14U)

/* ETH DET errors */
typedef uint8 Eth_30_Ar7000_DetErrorType;
#define ETH_30_AR7000_E_NO_ERROR                     (0x00U)
#define ETH_30_AR7000_E_INV_CTRL_IDX                 (0x01U)
#define ETH_30_AR7000_E_NOT_INITIALIZED              (0x02U)
#define ETH_30_AR7000_E_INV_POINTER                  (0x03U)
#define ETH_30_AR7000_E_INV_PARAM                    (0x04U)
#define ETH_30_AR7000_E_INV_CONFIG                   (0x05U)
#define ETH_30_AR7000_E_INV_MODE                     (0x06U)
#define ETH_30_AR7000_E_SPI_PROT_ERROR               (0x07U)

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define ETH_30_AR7000_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Eth_30_Ar7000_InitMemory
 **********************************************************************************************************************/
/*! \brief         Power-up memory initialization
 *  \details       Initializes component variables in *_INIT_* sections at power up.
 *  \pre           Module is uninitialized.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \note          Use this function in case these variables are not initialized by the startup code.
 *  \trace         CREQ-137660
 **********************************************************************************************************************/
FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_InitMemory( void );

/***********************************************************************************************************************
 *  Eth_30_Ar7000_Init
 **********************************************************************************************************************/
/*! \brief         Initializes component
 *  \details       Initializes all component variables and sets the component state to initialized.
 *  \param[in]     CfgPtr             Component configuration structure
 *  \pre           Interrupts are disabled.
 *  \pre           Module is uninitialized.
 *  \pre           Eth_30_Ar7000_InitMemory has been called unless Eth_30_Ar7000_ModuleInitialized is initialized
 *                 by start-up code.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \trace         CREQ-137660
 **********************************************************************************************************************/
FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_Init(
     P2CONST(Eth_30_Ar7000_ConfigType, AUTOMATIC, ETH_30_AR7000_CONST) CfgPtr);

/***********************************************************************************************************************
 *  Eth_30_Ar7000_ControllerInit
 **********************************************************************************************************************/
/*! \brief         Initialize a Ethernet controller
 *  \details       Initializes the Ethernet controller and the related variables so it is possible to set it in
 *                 operation afterwards.
 *  \param[in]     GlobalCtrlIdx         Identifier of the Ethernet controller
 *  \param[in]     CfgIdx                Identifier of the configuration (only 0 allowed)
 *  \return        E_OK                  Ethernet controller initialized
 *  \return        E_NOT_OK              Initialization of Ethernet controller failed
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE for different Ethernet controllers
 *  \synchronous   TRUE
 *  \trace         CREQ-137690
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_ControllerInit(
     uint8 GlobalCtrlIdx,
     uint8 CfgIdx);

/***********************************************************************************************************************
 *  Eth_30_Ar7000_SetControllerMode
 **********************************************************************************************************************/
/*! \brief         Sets the operation mode of a Ethernet controller
 *  \details       Sets the operation mode of the Ethernet controller so it is either turned off (no frame reception and
 *                 transmission) or turned on (frames can be transmitted and received).
 *  \param[in]     GlobalCtrlIdx         Identifier of the Ethernet controller
 *  \param[in]     CtrlMode              Operation mode that shall be applied
 *  \return        E_OK                  Operation mode successfully applied
 *  \return        E_NOT_OK              Operation mode couldn't be applied
 *  \pre           Ethernet controller must be initialized
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \trace         CREQ-137691
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_SetControllerMode(
     uint8        GlobalCtrlIdx,
     Eth_ModeType CtrlMode);

/***********************************************************************************************************************
 *  Eth_30_Ar7000_GetControllerMode
 **********************************************************************************************************************/
/*! \brief         Retrieves the current operation mode of the Ethernet controller
 *  \details       -
 *  \param[in]     GlobalCtrlIdx         Identifier of the Ethernet controller
 *  \param[out]    CtrlModePtr           Operation mode retrieved
 *  \return        E_OK                  Operation mode successfully retrieved
 *  \return        E_NOT_OK              Retrieval of operation mode failed
 *  \pre           Ethernet controller must be initialized
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \trace         CREQ-137692
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_GetControllerMode(
           uint8                                             GlobalCtrlIdx,
     P2VAR(Eth_ModeType, AUTOMATIC, ETH_30_AR7000_APPL_DATA) CtrlModePtr);

/***********************************************************************************************************************
 *  Eth_30_Ar7000_GetPhysAddr
 **********************************************************************************************************************/
/*! \brief         Retrieves the currently active MAC address of a Ethernet controller
 *  \details       -
 *  \param[in]     GlobalCtrlIdx         Identifier of the Ethernet controller
 *  \param[out]    PhysAddrPtr           Buffer of at least 6 byte to pass the MAC address
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \trace         CREQ-137698
 **********************************************************************************************************************/
FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_GetPhysAddr(
           uint8                                      GlobalCtrlIdx,
     P2VAR(uint8, AUTOMATIC, ETH_30_AR7000_APPL_DATA) PhysAddrPtr);

/***********************************************************************************************************************
 *  Eth_30_Ar7000_SetPhysAddr
 **********************************************************************************************************************/
/*! \brief         Sets the MAC address of the Ethernet controller
 *  \details       Sets the MAC address of the Ethernet controller. Dependent on the configuration of the "Write
 *                 MAC address" feature the change is persisted in non-volatile RAM and also available after a power-
 *                 cycle of the MCU.
 *  \param[in]     GlobalCtrlIdx         Identifier of the Ethernet controller
 *  \param[in]     PhysAddrPtr           Buffer holding the MAC address that shall be applied
 *  \pre           The link of the specific controller has to be down before a new physical address is set
 *  \context       TASK|ISR2
 *  \reentrant     TRUE for different Ethernet controller
 *  \synchronous   TRUE
 *  \trace         CREQ-137698
 *  \note          In case ETH_30_AR7000_ENABLE_MAC_ADDR_CBK is enabled a call to this API will changed the content of
 *                 the pointer provided by the call back configured at ETH_30_AR7000_APPL_CBK_GET_MAC_ADDR
 **********************************************************************************************************************/
FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_SetPhysAddr(
             uint8                                      GlobalCtrlIdx,
     P2CONST(uint8, AUTOMATIC, ETH_30_AR7000_APPL_DATA) PhysAddrPtr);

#if ( ETH_30_AR7000_ENABLE_UPDATE_PHYS_ADDR_FILTER == STD_ON )
/***********************************************************************************************************************
 *  Eth_30_Ar7000_UpdatePhysAddrFilter
 **********************************************************************************************************************/
/*! \brief         Updates the reception MAC address filter of a Ethernet controller
 *  \details       Add or remove MAC address from the reception filter of the Ethernet controller so Ethernet frames
 *                 addressed to the respective MAC address can be received or will be blocked from reception.
 *  \param[in]     GlobalCtrlIdx         Identifier of the Ethernet controller
 *  \param[in]     PhysAddrPtr           Pointer to buffer holding the MAC address the filter shall be adapted for \n
 *                                       in network byte order.
 *  \param[in]     Action                Action that shall be applied for the filter: \n
 *                                       ETH_REMOVE_FROM_FILTER - MAC address shall be blocked \n
 *                                       ETH_ADD_TO_FILTER      - MAC address shall be allowed
 *  \return        E_OK                  Filter successfully updated
 *  \return        E_NOT_OK              Filter modification failed
 *  \pre           Ethernet controller is initialized
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \config        ETH_30_AR7000_ENABLE_UPDATE_PHYS_ADDR_FILTER
 *  \trace         CREQ-137699
 *  \note          This driver does only support multicast and broadcast addresses to be added/removed
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_UpdatePhysAddrFilter(
             uint8                                      GlobalCtrlIdx,
     P2CONST(uint8, AUTOMATIC, ETH_30_AR7000_APPL_DATA) PhysAddrPtr,
             Eth_FilterActionType                       Action);
#endif /* ETH_30_AR7000_ENABLE_UPDATE_PHYS_ADDR_FILTER */

/***********************************************************************************************************************
 *  Eth_30_Ar7000_WriteSpi
 **********************************************************************************************************************/
/*! \brief         Triggers a register write request
 *  \details       Sends a write request to the QCA7005 via the SPI interface.
 *  \param[in]     GlobalCtrlIdx         Identifier of the Ethernet controller
 *  \param[in]     RegAddr               Address of the register that shall be written \n
 *                                       (see Programmer's Guide of AR7000)
 *  \param[in]     RegVal                Value that shall be written to the register \n
 *                                       (see Programmer's Guide of AR7000)
 *  \return        ETH_30_AR7000_SPI_ACCESS_OK                      Write request successfully sent
 *  \return        ETH_30_AR7000_SPI_ACCESS_NOT_OK                  Writing SPI register failed
 *  \return        ETH_30_AR7000_SPI_ACCESS_ERROR_BUT_SEQ_SCHEDULED Error during SPI sequence processing,
 *                                                                  but this sequence has been added to the queue
 *  \pre           Ethernet controller is operational in mode ACTIVE and controller index must be valid
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \trace         CREQ-137766
 **********************************************************************************************************************/
FUNC(Eth_30_Ar7000_SpiAccessReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_WriteSpi(
     uint8  GlobalCtrlIdx,
     uint16 RegAddr,
     uint16 RegVal);

/***********************************************************************************************************************
 *  Eth_30_Ar7000_ReadSpi
 **********************************************************************************************************************/
/*! \brief         Triggers a register read request
 *  \details       Sends a read request to the QCA7005 via the SPI interface. Use Eth_30_Ar7000_GetReadSpiResult to get
 *                 the register value.
 *  \param[in]     GlobalCtrlIdx         Identifier of the Ethernet controller
 *  \param[out]    FlowId                Index of flow associated with the register data.\n
 *                                       The flow id may be used to get status and result of the request via the \n
 *                                       Eth_30_Ar7000_GetReadSpiResult API.
 *  \param[in]     EndNotification       Pointer to a notification function. The interface the notification must apply \n
 *                                       to is stated below: \n
 *                                       void <Eth_30_Ar7000_EndNotification>(uint8 CtrlIdx, uint8 FlowId);\n
 *                                       The FlowId complies with the FlowId returned by the parameter FlowId.
 *  \param[in]     RegAddr               Address of the register that shall be read from \n
 *                                       (see Programmer's Guide of AR7000)
 *  \return        ETH_30_AR7000_SPI_ACCESS_OK                      Write request successfully sent
 *  \return        ETH_30_AR7000_SPI_ACCESS_NOT_OK                  Writing SPI register failed
 *  \return        ETH_30_AR7000_SPI_ACCESS_ERROR_BUT_SEQ_SCHEDULED Error during SPI sequence processing,
 *                                                                  but this sequence has been added to the queue
 *  \pre           Ethernet controller is operational in mode ACTIVE and controller index must be valid
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   FALSE
 *  \trace         CREQ-137767
 **********************************************************************************************************************/
FUNC(Eth_30_Ar7000_SpiAccessReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_ReadSpi(
           uint8                                      GlobalCtrlIdx,
     P2VAR(uint8, AUTOMATIC, ETH_30_AR7000_APPL_DATA) FlowId,
           Eth_30_Ar7000_EndNotificationFctType       EndNotification,
           uint16                                     RegAddr);

/***********************************************************************************************************************
 *  Eth_30_Ar7000_GetReadSpiResult
 **********************************************************************************************************************/
/*! \brief         Reads the status and result data of a SPI register read request
 *  \details       -
 *  \param[in]     GlobalCtrlIdx         Identifier of the Ethernet controller
 *  \param[in]     FlowId                Index of flow associated with the register data. See FlowId parameter of \n
 *                                       Eth_30_Ar7000_ReadSpi API.
 *  \param[out]    RegValPtr             Pointer to register value destination buffer.\n
 *                                       Range:\n
 *                                       - NULL_PTR in case of E_NOT_OK\n
 *                                       - !NULL_PTR in case of E_OK
 *  \return        ETHTRCV_30_AR7000_RT_OK      Data available for the given FlowId.
 *  \return        ETHTRCV_30_AR7000_RT_NOT_OK  No data available for FlowId.
 *  \return        ETHTRCV_30_AR7000_RT_PENDING Flow processing still active.
 *  \pre           The read has to be requested by Eth_30_Ar7000_ReadSpi().
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \trace         CREQ-137767
 **********************************************************************************************************************/
FUNC(Eth_30_Ar7000_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_GetReadSpiResult(
           uint8                                       GlobalCtrlIdx,
           uint8                                       FlowId,
     P2VAR(uint16, AUTOMATIC, ETH_30_AR7000_APPL_DATA) RegValPtr);

/***********************************************************************************************************************
 *  Eth_30_Ar7000_GetCounterState
 **********************************************************************************************************************/
/*! \brief         Retrieves the value of a Ethernet statistics counter
 *  \details       Retrieves the value of a Ethernet statistics counter by addressing the counter with the help
 *                 of a offset into the Ethernet statistics counter register space.
 *  \param[in]     GlobalCtrlIdx         Identifier of the Ethernet controller
 *  \param[in]     CtrOffs               Offset of the counter into the Ethernet statistics counter register space
 *  \param[out]    CtrValPtr             Pointer to counter value destination buffer
 *  \return        E_OK                  Counter successfully retrieved
 *  \return        E_NOT_OK              Counter retrieval failed
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \trace         CREQ-137705
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_GetCounterState(
           uint8                                       GlobalCtrlIdx,
           uint16                                      CtrOffs,
     P2VAR(uint32, AUTOMATIC, ETH_30_AR7000_APPL_DATA) CtrValPtr);

/***********************************************************************************************************************
 *  Eth_30_Ar7000_ProvideTxBuffer
 **********************************************************************************************************************/
/*! \brief         Provides a buffer that can be used to transmit a Ethernet frame
 *  \details       Requests a buffer for the payload and the ethernet header of a ethernet frame which can be
 *                 transmitted. The buffer is locked and therefore protected against reuse until the transmission of
 *                 the frame is confirmed after transmission was triggered (Eth_30_Ar7000_Transmit() and consecutive
 *                 Eth_30_Ar7000_TxConfirmation()) or buffer is intentionally released by calling Eth_Transmit()
 *                 with LenByte=0.
 *  \param[in]     GlobalCtrlIdx         Identifier of the Ethernet controller
 *  \param[out]    BufIdxPtr             Identifier of the buffer provided on successful buffer provision
 *  \param[out]    BufPtrPtr             Pointer to the buffer provided on successful buffer provision
 *  \param[in,out] LenBytePtr            Pointer to the destination of the requested and the provide length of the buffer: \n
 *                                         [in]  Length of the data the caller wants to transmit (only payload length) \n
 *                                         [out] Actual length of the provided buffer (only payload length)
 *  \return        BUFREQ_OK             Buffer successfully provided
 *  \return        BUFREQ_E_NOT_OK       Development error check failed
 *  \return        BUFREQ_E_BUSY         Any buffer able to hold the requested length is already in use
 *  \return        BUFREQ_E_OVFL         No buffer with the requested length available by configuration
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \trace         CREQ-137700
 **********************************************************************************************************************/
FUNC(BufReq_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_ProvideTxBuffer(
           uint8                                              GlobalCtrlIdx,
     P2VAR(uint8,        AUTOMATIC, ETH_30_AR7000_APPL_DATA)  BufIdxPtr,
     P2VAR(Eth_DataType, AUTOMATIC, ETH_30_AR7000_APPL_DATA) *BufPtrPtr,
     P2VAR(uint16,       AUTOMATIC, ETH_30_AR7000_APPL_DATA)  LenBytePtr);

/***********************************************************************************************************************
 *  Eth_30_Ar7000_Transmit
 **********************************************************************************************************************/
/*! \brief         Triggers the transmission of an Ethernet frame
 *  \details       Function takes the buffer previously provided by Eth_30_Ar7000_ProvideTxBuffer() enhances it with
 *                 the Ethernet header and triggers the transmission of the Ethernet frame.
 *  \param[in]     GlobalCtrlIdx         Identifier of the Ethernet controller
 *  \param[in]     BufIdx                Identifier of the buffer provided by Eth_ProvideTxBuffer()
 *  \param[in]     FrameType             Ethernet type, according to type field of IEEE802.3
 *  \param[in]     TxConfirmation        Request for a transmission confirmation: \n
 *                                         FALSE - No transmission confirmation desired \n
 *                                         TRUE - Transmission confirmation desired \n
 *  \param[in]     LenByte               Length of the data to be transmitted (Payload length)
 *  \param[in]     PhysAddrPtr           Pointer to Destination-MAC address buffer the frame shall be sent to
 *  \return        E_OK                  Frame transmission triggered
 *  \return        E_NOT_OK              Triggering of frame transmission wasn't possible
 *  \pre           Buffer was acquired by Eth_30_Ar7000_ProvideTxBuffer()
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   FALSE
 *  \trace         CREQ-137701
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_Transmit(
             uint8                                  GlobalCtrlIdx,
             uint8                                  BufIdx,
             Eth_FrameType                          FrameType,
             boolean                                TxConfirmation,
             uint16                                 LenByte,
     P2CONST(uint8, AUTOMATIC, ETH_30_AR7000_CONST) PhysAddrPtr);

/***********************************************************************************************************************
 *  Eth_30_Ar7000_VTransmit
 **********************************************************************************************************************/
/*! \brief         Trigger the transmission of an Ethernet frame with a specific source MAC
 *  \details       Function takes the buffer previously provided by Eth_30_Ar7000_ProvideTxBuffer() enhances it with
 *                 the Ethernet header (using a specific source MAC address instead of the Ethernet controllers one)
 *                 and triggers the transmission of the Ethernet frame.
 *  \param[in]     GlobalCtrlIdx         Identifier of the Ethernet controller
 *  \param[in]     BufIdx                Identifier of the buffer provided by Eth_ProvideTxBuffer()
 *  \param[in]     FrameType             Ethernet type, according to type field of IEEE802.3
 *  \param[in]     TxConfirmation        Request for a transmission confirmation: \n
 *                                         FALSE - No transmission confirmation desired \n
 *                                         TRUE - Transmission confirmation desired
 *  \param[in]     LenByte               Length of the data to be transmitted (Payload length)
 *  \param[in]     DestMacAddrPtr        Pointer to Destination-MAC address buffer
 *  \param[in]     SrcMacAddrPtr         Pointer to Source-MAC address buffer
 *  \return        E_OK                  Frame transmission triggered
 *  \return        E_NOT_OK              Triggering of frame transmission wasn't possible
 *  \pre           Buffer was acquired by Eth_30_Ar7000_ProvideTxBuffer()
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   FALSE
 *  \trace         CREQ-137701
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETH_30_AR7000_CODE) Eth_30_Ar7000_VTransmit(
             uint8                                  GlobalCtrlIdx,
             uint8                                  BufIdx,
             Eth_FrameType                          FrameType,
             boolean                                TxConfirmation,
             uint16                                 LenByte,
     P2CONST(uint8, AUTOMATIC, ETH_30_AR7000_CONST) DestMacAddrPtr,
     P2CONST(uint8, AUTOMATIC, ETH_30_AR7000_CONST) SrcMacAddrPtr);

/***********************************************************************************************************************
 *  Eth_30_Ar7000_Receive
 **********************************************************************************************************************/
/*! \brief         Calls the reception callback of all fully received Ethernet frames.
 *  \details       -
 *  \param[in]     GlobalCtrlIdx         Identifier of the Ethernet controller
 *  \param[out]    RxStatusPtr           Indicates the result of the reception trigger
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \note          - RxStatusPtr is in interrupt mode unused because information is not used by interrupt handler
 *                 - When interrupt mode is enabled this function must not be called except from the interrupt handler
 *  \trace         CREQ-137702
 **********************************************************************************************************************/
FUNC(void, ETH_30_AR7000_CODE_ISR) Eth_30_Ar7000_Receive(
           uint8                                                GlobalCtrlIdx,
     P2VAR(Eth_RxStatusType, AUTOMATIC, ETH_30_AR7000_APPL_VAR) RxStatusPtr);

/***********************************************************************************************************************
 *  Eth_30_Ar7000_TxConfirmation
 **********************************************************************************************************************/
/*! \brief         Unlocks the buffers of fully transmitted ethernet frames
 *  \details       Function triggers the transmission confirmation of a previously Ethernet transmitted frame and
 *                 unlocks the buffer associated to the Ethernet frame so it is able to be used for frame transmission
 *                 again.
 *  \param[in]     GlobalCtrlIdx       Identifier of the Ethernet controller
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \note          When interrupt mode is enabled this function must not be called except from the interrupt handler
 *  \trace         SPEC-2743323
 **********************************************************************************************************************/
FUNC(void, ETH_30_AR7000_CODE_ISR) Eth_30_Ar7000_TxConfirmation(
     uint8 GlobalCtrlIdx);

/***********************************************************************************************************************
 *  Eth_30_Ar7000_SpiFlowHdlr
 **********************************************************************************************************************/
/*! \brief         Controls the flow of SPI bus protocol.
 *  \details       -
 *  \param[in]     GlobalCtrlIdx         Identifier of the Ethernet controller
 *  \pre           -
 *  \context       ISR2
 *  \reentrant     TRUE
 *  \synchronous   FALSE
 *  \note          Eth_30_Ar7000_SpiFlowHdlr must not be called by the user application.
 **********************************************************************************************************************/
FUNC(void, ETH_30_AR7000_CODE_ISR) Eth_30_Ar7000_SpiFlowHdlr(
     uint8 GlobalCtrlIdx);

#if ((ETH_30_AR7000_ENABLE_TX_INTERRUPT == STD_ON) && (ETH_30_AR7000_ENABLE_RX_INTERRUPT == STD_ON))
/***********************************************************************************************************************
 *  Eth_30_Ar7000_Ar7000IrqHdlr
 **********************************************************************************************************************/
/*! \brief         Handles external interrupts of AR7000
 *  \details       -
 *  \param[in]     GlobalCtrlIdx         Identifier of the Ethernet controller
 *  \pre           -
 *  \context       ISR2
 *  \reentrant     TRUE
 *  \synchronous   FALSE
 *  \config        ETH_30_AR7000_ENABLE_TX_INTERRUPT, ETH_30_AR7000_ENABLE_RX_INTERRUPT
 **********************************************************************************************************************/
FUNC(void, ETH_30_AR7000_CODE_ISR) Eth_30_Ar7000_Ar7000IrqHdlr(
     uint8 GlobalCtrlIdx);
#endif /* ETH_30_AR7000_ENABLE_TX_INTERRUPT && ETH_30_AR7000_ENABLE_RX_INTERRUPT */

#if ( ETH_30_AR7000_VERSION_INFO_API == STD_ON )
/***********************************************************************************************************************
 *  Eth_30_Ar7000_GetVersionInfo
 **********************************************************************************************************************/
/*! \brief         Returns the version information
 *  \details       Returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]    VersionInfoPtr   Pointer to where to store the version information. Parameter must not be NULL.
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \config        ETH_30_AR7000_VERSION_INFO_API
 *  \trace         SPEC-2743330
 *  \trace         CREQ-137688
 **********************************************************************************************************************/
FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_GetVersionInfo(
     P2VAR(Std_VersionInfoType, ETH_30_AR7000_APPL_DATA, ETH_30_AR7000_APPL_DATA) VersionInfoPtr);
#endif /* ETH_30_AR7000_VERSION_INFO_API */

/***********************************************************************************************************************
 *  Eth_30_Ar7000_MainFunction
 **********************************************************************************************************************/
/*! \brief         Cyclic main function
 *  \details       Function performes cyclic checks if enabled (errors and itnerrupts) as well as it implements error
 *                 handling. Typical call cycles are 10-20 ms.
 *  \pre           Module must be initialized
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 **********************************************************************************************************************/
FUNC(void, ETH_30_AR7000_CODE) Eth_30_Ar7000_MainFunction( void );

/***********************************************************************************************************************
 *  Eth_30_Ar7000_SpiSeqEndCbk_0
 **********************************************************************************************************************/
/*! \brief         First SPI notification callback method.
 *  \details       -
 *  \pre           -
 *  \context       ISR2
 *  \reentrant     TRUE
 *  \synchronous   FALSE
 *  \note          It is not relevant which notification callback is mapped to a SPI sequence.
 **********************************************************************************************************************/
FUNC(void, ETH_30_AR7000_CODE_ISR) Eth_30_Ar7000_SpiSeqEndCbk_0( void );

/***********************************************************************************************************************
 *  Eth_30_Ar7000_SpiSeqEndCbk_1
 **********************************************************************************************************************/
/*! \brief         Second SPI notification callback method.
 *  \details       -
 *  \pre           -
 *  \context       ISR2
 *  \reentrant     TRUE
 *  \synchronous   FALSE
 *  \note          It is not relevant which notification callback is mapped to a SPI sequence.
 **********************************************************************************************************************/
FUNC(void, ETH_30_AR7000_CODE_ISR) Eth_30_Ar7000_SpiSeqEndCbk_1( void );

#if ( ETH_30_AR7000_ENABLE_SPI_PADDING == STD_ON )
/***********************************************************************************************************************
 *  Eth_30_Ar7000_SpiSeqEndCbk_2
 **********************************************************************************************************************/
/*! \brief         Third SPI notification callback method.
 *  \details       -
 *  \pre           -
 *  \context       ISR2
 *  \reentrant     TRUE
 *  \synchronous   FALSE
 *  \config        ETH_30_AR7000_ENABLE_SPI_PADDING
 *  \note          It is not relevant which notification callback is mapped to a SPI sequence.
 **********************************************************************************************************************/
FUNC(void, ETH_30_AR7000_CODE_ISR) Eth_30_Ar7000_SpiSeqEndCbk_2( void );
#endif /* ETH_30_AR7000_ENABLE_SPI_PADDING */

#if ((ETH_30_AR7000_ENABLE_TX_INTERRUPT == STD_ON) && (ETH_30_AR7000_ENABLE_RX_INTERRUPT == STD_ON))
/***********************************************************************************************************************
 *  Eth_30_Ar7000_Ar7000INTRNotification
 **********************************************************************************************************************/
/*! \brief         Notification function for external edge-triggered interrupt.
 *  \details       -
 *  \pre           -
 *  \context       ISR2
 *  \reentrant     TRUE
 *  \synchronous   FALSE
 *  \config        ETH_30_AR7000_ENABLE_TX_INTERRUPT, ETH_30_AR7000_ENABLE_RX_INTERRUPT
 *  \note          The notification function is either called from ASR ICU module or a handwritten ISR wrapper
 **********************************************************************************************************************/
FUNC(void, ETH_30_AR7000_CODE_ISR) Eth_30_Ar7000_Ar7000INTRNotification( void );
#endif /* ETH_30_AR7000_ENABLE_TX_INTERRUPT && ETH_30_AR7000_ENABLE_RX_INTERRUPT */


#define ETH_30_AR7000_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*!
 * \exclusivearea ETH_30_AR7000_EXCLUSIVE_AREA_0
 * Ensures consistency of accesses to global variable and SPI sequence sort order.
 * \protects Multiple variable, function accesses and sort order of SPI sequences
 * \usedin Eth_30_Ar7000_VSendNextSpiSeq, Eth_30_Ar7000_VGetPacket, Eth_30_Ar7000_VWriteSpiConfirmation, 
 *         Eth_30_Ar7000_VReceive, Eth_30_Ar7000_VCheckSpiHeader, Eth_30_Ar7000_VTxConfirmation, 
 *         Eth_30_Ar7000_VSMStateEnd, Eth_30_Ar7000_WriteSpi, Eth_30_Ar7000_ReadSpi, Eth_30_Ar7000_GetReadSpiResult, 
 *         Eth_30_Ar7000_VInterruptCauseNotification, Eth_30_Ar7000_VOnCpuRunning, Eth_30_Ar7000_ProvideTxBuffer, 
 *         Eth_30_Ar7000_VTransmit, Eth_30_Ar7000_MainFunction
 * \exclude All functions provided by Eth_30_Ar7000 (and SPI and ICU calls to this module).
 * \length LONG due to multiple sub functions.
 * \endexclusivearea
 *
 * \exclusivearea ETH_30_AR7000_EXCLUSIVE_AREA_1
 * Ensures the sort order of the interrupt disable and interrupt cause register SPI sequence as well as the 
 * consistency of the interrupt disable retry variable.
 * Inside this exclusive area the area ETH_30_AR7000_EXCLUSIVE_AREA_0 is activated in sub functions.
 * \protects SPI sequence sort order
 * \usedin Eth_30_Ar7000_VInterruptCauseNotification, Eth_30_Ar7000_VOnCpuRunning, Eth_30_Ar7000_VReceive, 
 *         Eth_30_Ar7000_Ar7000IrqHdlr, Eth_30_Ar7000_MainFunction
 * \exclude All functions provided by Eth_30_Ar7000 (and SPI and ICU calls to this module).
 * \length LONG due to multiple sub functions.
 * \endexclusivearea
 */

#endif /* ETH_30_AR7000_H */

/***********************************************************************************************************************
 *  END OF FILE: Eth_30_Ar7000.h
 **********************************************************************************************************************/
