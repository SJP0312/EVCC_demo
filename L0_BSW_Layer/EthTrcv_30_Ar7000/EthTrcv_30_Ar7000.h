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
/**        \file  EthTrcv_30_Ar7000.h
 *        \brief  Ethernet transceiver driver QCA 7005 main header file
 *
 *      \details  Vector static code main header file for the Ethernet transceiver driver QCA 7005 module.
 *
 *********************************************************************************************************************/

 /*********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2011-05-30  haw     -             Creation
 *  01.00.01  2012-01-09  haw     ESCAN00055876 MMType field must not be swapped to network byte order by
 *                                              the Transceiver Driver since EthIf already does
 *  02.00.00  2012-01-27  haw     ESCAN00056949 Adapted implementation to QCA7000 behavior.
 *                                              PL14 board is not supported anymore!
 *                                ESCAN00056340 Compiler Abstractions are partly wrong
 *                                ESCAN00056947 API EthTrcv_30_Ar7000_EraseFlash for erasing the connected flash introduced.
 *  02.00.01  2012-03-26  haw     ESCAN00057867 PIB checksum calculation changed. SetNMK and WritePhysAddr APIs
 *                                              are affected and do not work properly.
 *  02.00.02  2012-04-10  haw     ESCAN00058198 Compiler error: Compiler errors with some SchM versions compiler
 *                                              due to missing semikolon behind SchM macro
 *                                ESCAN00058255 Depending on some configuration variants there may occur
 *                                              unresolved symbols
 *                                ESCAN00058265 PIB fields in RAM are accessed in a wrong way on Big-Endian platforms
 *  02.01.00  2012-05-30  haw     ESCAN00059183 Enable error detection for Out-Of-Sync situations and add runtime
 *                                              error handling
 *  02.02.00  2012-07-02  haw     ESCAN00059792 Call Firmware download callback not until the firmware
 *                                              is started and ready to answer requests
 *                                ESCAN00059515 AR4-125: Remove support for v_cfg.h in Cfg5 systems
 *                                ESCAN00059237 Compiler error: Declaration of EthTrcv_30_Ar7000_ApiCallRetCnt uses
 *                                              a wrong compiler abstraction
 *                                ESCAN00056446 Use ETHTRCV_30_AR7000_USE_DUMMY_STATEMENT define instead
 *                                              of V_USE_DUMMY_STATEMENT
 *                                ESCAN00059878 Introduced SLAC functionality according to ISO15118-3
 *                                ESCAN00059959 Compiler error: Disabling the firmware download option causes a
 *                                              compiler error
 *                                ESCAN00060216 MISRA-C:2004 compliance
 *                                ESCAN00060233 Remove Erasing Flash Api. MME is not supported anymore by QCA7000
 *                                              firmware
 *                                ESCAN00060298 Add a API for DAK write access when firmware download is enabled.
 *  02.02.01  2012-10-12  haw     ESCAN00062122 ASR4 Enhancement
 *                                ESCAN00062252 AR4-220: Remove STATIC
 *                                ESCAN00062484 Last Trcv Link State is reported if Trcv Chip is not responding
 *  02.03.00  2012-11-26  haw     ESCAN00063266 Introduce SetPibData API to change PIB block dynamically during runtime
 *                                ESCAN00063271 Extended SLAC implementation by missing requirements. Release 02.02.xx
 *                                              does not contain the entire functionality
 *  02.04.00  2013-02-20  haw     ESCAN00083958 Introduce application callback function for PLC address
 *                                ESCAN00064243 Compiler error: NvM Include missing under some SLAC related
 *                                              circumstances
 *                                ESCAN00063801 Compiler warning: On disabled API optimization and enabled firmware
 *                                              download
 *                                ESCAN00064152 Default length of MMEs is wrong. The padding is not according to
 *                                              GreenPhy specification
 *                                ESCAN00064831 Granularity of configurable T_TOGGLE time  is not sufficient
 *                                ESCAN00062447 Provide a slow firmware download mechanism to reduce interrupt load
 *                                ESCAN00064836 Missing field checks in SLAC messages
 *                                ESCAN00064837 SLAC fields RESP_TYPE and FORWARDING_STA got another assignment by
 *                                              ISO specification
 *                                ESCAN00065233 CM_SLAC_MATCH message assembly is wrong
 *                                ESCAN00065436 Support CM_SET_KEY AND VS_SET_KEY message after a SLAC session
 *  02.05.00  2013-02-12  haw     ESCAN00065787 Nested exclusive areas avoid usage of OS resources instead of
 *                                              disabling all interrupts
 *                                ESCAN00065794 Introduce a EthTrcv_30_Ar7000_Slac_DiagDataReadAccess API that reads
 *                                              out the amplitude map and calibration data block
 *                                ESCAN00065827 Compiler error: Physical Address Callback is enabled whereas other
 *                                              features that operates on PIB are disabled
 *  02.06.00  2013-04-22  haw     ESCAN00066752 Avoid Reset of QCA7005 (take advantage of new Firmware)
 *                                ESCAN00066769 SLAC: Introduce validation start mode that never trigger validation,
 *                                              even when several EVSE are found or POT_FOUND
 *  02.06.01  2013-04-26  haw     ESCAN00067010 EthTrcv_30_Ar7000_TriggerDwld need to be secured by a critical section
 *  02.06.02  2013-05-07  haw     ESCAN00067208 Provide a global array populated with SLAC EVSE attenuations for
 *                                              diagnostic service
 *  02.06.03  2013-05-21  haw     ESCAN00067509 Compiler error: Disabled SLAC leads to a compiler error
 *  02.07.00  2013-08-19  haw     ESCAN00068825 SLAC: Default Length of SLAC message ATTEN_CHAR.RSP is wrong
 *                                ESCAN00069759 SLAC: Eliminate all timing and error handling deviations with respect
 *                                                    to the current ISO/DIN working results
 *                                ESCAN00069765 SLAC: The field checks of SLAC messages shall be configurable
 *                                ESCAN00069820 SLAC: Ethernet Source address of Validation-, Matching- and
 *                                                    Amplitude Map-Requests are not checked
 *  02.07.01  2013-09-19  haw     ESCAN00069765 SLAC: The field checks of SLAC messages shall be configurable
 *                                                    --> added further check
 *                                ESCAN00070273 SLAC: Memory fault when validation is used and more EVSEs are available
 *                                                    that can be handled
 *                                ESCAN00071078 SLAC Reset/Terminate does not leave the PLC network occasionally
 *  02.07.02  2013-10-15  haw     ESCAN00071078 SLAC Reset/Terminate does not leave the PLC network occasionally
 *                                ESCAN00070965 Firmware download may be repeated a few times because not always
 *                                              successful
 *  02.08.00  2013-12-09  haw     ESCAN00071078 SLAC Reset/Terminate does not leave the PLC network occasionally
 *                                ESCAN00070965 Firmware download may be repeated a few times because not always
 *                                              successful
 *                                ESCAN00071057 Unaligned memory access trap on Tricore platforms when enabling option
 *                                              "PIB Upload"
 *                                ESCAN00072378 Firmware download attempts could be less than expected
 *                                ESCAN00056353 VAR_INIT / VAR_ZERO_INIT Memory Mapping sections
 *                                ESCAN00072173 RH850: Unaligned memory access exception in function _VFrameHeader and
 *                                              _MME_WriteAndExecuteApplet
 *                                ESCAN00069268 AR4-450: Usage of section PBCFG in PB files
 *                                ESCAN00072521 Improved Callback signatures and added further APIs
 *                                ESCAN00072559 Need of transceiver reset is now indicated by QCA.
 *                                              State must not be kept by driver.
 *                                ESCAN00072750 ISO15118 FDIS candidate conformity changes
 *  02.09.00  2014-04-15  haw     ESCAN00075027 Further adaptions to ensure ISO FDIS candidate conformity
 *                                ESCAN00075026 Support Amplitude Map Exchange as optional SLAC step
 *                                ESCAN00075153 Formal and minor code changes due to code review to increase quality
 *                                              and readability
 *  03.00.00  2014-08-04  haw     ESCAN00077577 Breaking Change ASR4 Release 8/ Java7
 *  03.01.00  2014-09-10  haw     ESCAN00078205 Include structure makes it hard to use transceiver types within
 *                                              callback methods
 *                                ESCAN00078282 Compiler error: If API optimization is disabled,
 *                                              EthTrcv_30_Ar7000_Slac_VSelectEvseAndValidate is called with a wrong
 *                                              amount of arguments
 *                                ESCAN00078320 Provide a callback that reports the SLAC state currently processed
 *  03.01.01  2014-11-03  haw     ESCAN00079256 Compiler error: identifier "ETHTRCV_30_AR7000_VTRCVIDX_FIRST" is
 *                                              undefined
 *  03.02.00  2015-06-29  vismha  ESCAN00083423 Timeout/failure handling related to missing/late CM_ATTEN_CHAR.IND
 *                                              wrong
 *                                -             Lifted to MICROSAR4 R12
 *                                ESCAN00082056 AR4-535: RTM Runtime Measurement Points
 *  03.03.00  2015-07-17  vismha  ESCAN00084075 Support Eth controller API infixing
 *            2015-07-21  vismha  ESCAN00084094 Wrong matching decision after validation when one EVSE returns wrong
 *                                              toggling count
 *                                ESCAN00083309 Misalignment exception on V850/RH850
 *            2015-07-24  vismha  ESCAN00084199 Extend Firmware Start Application callout by information about
 *                                              successful Firmware Start
 *  04.00.00  2016-03-24  vissop  ESCAN00089091 Update to MSR4 R14
 *            2016-03-24  vissop  ESCAN00085790 Add: Implement FW download start call back
 *  04.00.01  2016-06-13  vissop  ESCAN00090449 Fix: Dont use EthIfCtrlIdx as TrcvIdx in MME_RxIndication
 *  04.00.02  2016-06-13  vissop  ESCAN00090488 Fix: Filter for QCA7005 controller in Slac_TrcvLinkStateChgCbk
 *  04.00.03  2016-11-14  vissop  ESCAN00091179 Fix: Use correct source file define for EthTrcv_30_Ar7000_Slac.c file
 *            2016-11-15  vissop  ESCAN00092038 Fix: Move local static variables to global variable section
 *            2016-11-15  vissop  ESCAN00092045 Fix: Add initialization to ZERO_INIT variables
 *            2016-11-15  vissop  ESCAN00091149 Fix: NULL_PTR exception after reset during validation2
 *            2016-11-16  vissop  ESCAN00092829 Fix: Compiler error with link state function if SLAC is disabled
 *  05.00.00  2016-11-29  vissop  ESCAN00093210 Add: Support for FW 1.2.1 features
 *            2016-11-29  vissop  ESCAN00091683 Add: EthTrcv_30_Ar7000_ResetAndLeave API
 *            2016-11-29  vissop  ESCAN00085789 Implement FW download start call back
 *            2016-11-29  vissop  ESCAN00089959 Fix: NMK and NID are stored now for DLINK CBK if SetNmk* API was used
 *  05.01.00  2017-05-23  vissop  ESCAN00095269 Add: Split up Ethernet layer MAC checks and SLAC message MAC checks
 *  05.01.01  2017-08-01  vissop  ESCAN00096145 Fix: Firmware download stops due to no Ethernet buffers are available
 *            2017-08-11  vissop  ESCAN00096285 Fix: Do not allow SLAC start if QCA7005 hasn't sent HAR 9 with enabled FW 1.2.1+ features
 *  05.01.02  2017-09-08  vissop  ESCAN00086186 Fix: Call DLink_Ready(DOWN) in case of a link loss
 *  05.01.03  2018-01-03  visfmo  ESCAN00097859 Add: Add Component Detailed Design (CDD)
 *  06.00.00  2018-03-07  vissop  STORYC-4477   Implementation review integration from 5.01.02
 *            2018-03-07  vissop  ESCAN00088196 Fix: Unaligned memory access trap on Tricore platforms when enabling option "FW turbo download"
 *            2018-03-07  vissop  ESCAN00081546 Fix: Description of EthTrcv_SetNmk() and EthTrcv_SetNmkAndNid()
 *            2018-03-08  vissop  ESCAN00098633 Fix: Invalid link state is reported after reset or leave (link does toggle)
 *            2018-03-14  vissop  ESCAN00098750 Fix: Subsequent SLAC session cannot be started without a manual Slac_Reset call after AmpMap timed out
 *            2018-03-14  vissop  ESCAN00098751 Fix: SLAC cannot be triggered with optional AmpMap exchange started by EVSE
 *  07.00.00  2018-07-17  vissop  STORYC-3892   [V2G] Proc3.0 for EthTrcv_Ar7000
 *            2018-07-17  vissop  ESCAN00100065 Fix: Compiler error: Unknown variable/macro ETHTRCV_E_ACCESS
 *            2018-07-31  vissop  ESCAN00100257 Fix: Firmware download may stop in case ResetDevice is called directly after a new firmware download was started
 *            2018-07-31  vissop  ESCAN00099154 Fix: Compiler error: Message defines are unknown if SLAC is disabled
 *  07.00.01  2018-09-28  vissop  ESCAN00100633 Fix: Compiler error: identifier EthTrcv_30_Ar7000_SetKeyCnt not declared
 *            2018-09-28  vissop  ESCAN00100806 Fix: Compiler error: Symbol EthTrcv_30_Ar7000_LinkStateLockCnt is not defined
 *            2018-09-28  vissop  ESCAN00100639 Fix: Det_ReportError can not be disabled
 *            2018-09-28  vissop  ESCAN00100632 Fix: Compiler error: identifier slacIdx not declared
 *  08.00.00  2019-04-09  vissop  STORYC-6009   Fix: Multiple configuration variants had compile errors or warnings
 *            2019-04-09  vissop  -             Vector internal: Remove package dependency to DrvTrans__coreEthAsr
 *            2019-04-18  vissop  ESCAN00102920 Fix: Compiler error: E_PENDING is not defined
 *  09.00.00  2019-11-04  vissop  V2G-34        Add: Change the Slac submodule to an independent module
 *            2019-11-04  vissop  ESCAN00104689 Fix: API EthTrcv_30_Ar7000_ModuleOperation may access invalid memory depending on received data
 *  09.00.01  2020-01-23  vissop  ESCAN00105296 Fix: New EthIf APIs are missing
 *  09.00.02  2020-03-17  visiay  ESCAN00105700 Fix: Invalid API name GetPhySignalQuality
 *  10.00.00  2020-04-28  vissop  V2G-497       Add: MISRA-C:2012 (Helix QAC9.7)
 *  10.00.01  2021-01-28  vissop  ESCAN00106359 Fix: Compiler error: ETHTRCV_30_AR7000_PIB_SIZE is not defined
 *            2021-02-01  vissop  ESCAN00107294 Fix: States and counters may get invalid values due to missing interrupt lock sections
 *  10.00.02  2023-09-11  virpab  ESCAN00114141 Fix: ECU memory can be read out via SPI
 *  10.01.00  2024-03-20  virpab  ETHPLAY-4557  Add: Pause Link state polling after SET_KEY
 *  10.01.01  2024-06-27  virpab  ETHPLAY-4810  Fix: Update to QAC 2023.2
 *********************************************************************************************************************/

#if !defined (ETHTRCV_30_AR7000_H)
# define ETHTRCV_30_AR7000_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "EthTrcv_30_Ar7000_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
#define ETHTRCV_30_AR7000_VENDOR_ID                                30U
#define ETHTRCV_30_AR7000_MODULE_ID                                73U

/* AUTOSAR Software specification version information */
#define ETHTRCV_30_AR7000_AR_RELEASE_MAJOR_VERSION               (0x04)
#define ETHTRCV_30_AR7000_AR_RELEASE_MINOR_VERSION               (0x01)
#define ETHTRCV_30_AR7000_AR_RELEASE_REVISION_VERSION            (0x01)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
#define ETHTRCV_30_AR7000_SW_MAJOR_VERSION                         10U
#define ETHTRCV_30_AR7000_SW_MINOR_VERSION                          1U
#define ETHTRCV_30_AR7000_SW_PATCH_VERSION                          1U

/* ----- Module instance IDs ----- */
/* only one instance is supported */
#define ETHTRCV_30_AR7000_INSTANCE_ID_DET                           0U

/* ----- API service IDs ----- */
#define ETHTRCV_30_AR7000_API_ID_INIT                            0x01U
#define ETHTRCV_30_AR7000_API_ID_TRANSCEIVER_INIT                0x02U
#define ETHTRCV_30_AR7000_API_ID_SET_TRANSCEIVER_MODE            0x03U
#define ETHTRCV_30_AR7000_API_ID_GET_TRANSCEIVER_MODE            0x04U
#define ETHTRCV_30_AR7000_API_ID_START_AUTO_NEG                  0x05U
#define ETHTRCV_30_AR7000_API_ID_GET_LINK_STATE                  0x06U
#define ETHTRCV_30_AR7000_API_ID_GET_BAUD_RATE                   0x07U
#define ETHTRCV_30_AR7000_API_ID_GET_DUPLEX_MODE                 0x08U
#define ETHTRCV_30_AR7000_API_ID_SET_NMK                         0x09U
#define ETHTRCV_30_AR7000_API_ID_READ_NMK                        0x0AU
#define ETHTRCV_30_AR7000_API_ID_RESET_DEVICE                    0x0BU
#define ETHTRCV_30_AR7000_API_ID_JOIN_SC_STATE                   0x0CU
#define ETHTRCV_30_AR7000_API_ID_LEAVE_SC_STATE                  0x0DU
#define ETHTRCV_30_AR7000_API_ID_READ_AVLN_STATUS                0x0EU
#define ETHTRCV_30_AR7000_API_ID_GET_VERSION_INFO                0x0FU
#define ETHTRCV_30_AR7000_API_ID_MAINFUNCTION                    0x10U
#define ETHTRCV_30_AR7000_API_ID_RXINDICATION                    0x11U
#define ETHTRCV_30_AR7000_API_ID_WRITE_PHYS_ADDR                 0x13U
#define ETHTRCV_30_AR7000_API_ID_WRITE_DAK                       0x14U
#define ETHTRCV_30_AR7000_API_ID_GET_SW_VERSION                  0x15U
#define ETHTRCV_30_AR7000_API_ID_WRITE_AND_EXECUTE_APPLET        0x16U
#define ETHTRCV_30_AR7000_API_ID_SET_PROPERTY                    0x17U
#define ETHTRCV_30_AR7000_API_ID_SET_PIB_DATA                    0x18U
#define ETHTRCV_30_AR7000_API_ID_SET_KEY_STATUS                  0x1Bu
#define ETHTRCV_30_AR7000_API_ID_HST_ACTION_REQ                  0x1Cu
#define ETHTRCV_30_AR7000_API_ID_HST_ACTION_REQ_SECOND_PHASE     0x1Du
#define ETHTRCV_30_AR7000_API_ID_PAUSE_LINK_STATE_POLLING        0x1EU
/* Internal API's */
#define ETHTRCV_30_AR7000_API_ID_V_FRAME_HEADER                  0x20u

/* ----- Error codes ----- */
typedef uint8 EthTrcv_30_Ar7000_DetErrorType;
#define ETHTRCV_30_AR7000_E_NO_ERROR                             0x00U
#define ETHTRCV_30_AR7000_E_INV_TRCV_IDX                         0x01U
#define ETHTRCV_30_AR7000_E_NOT_INITIALIZED                      0x02U
#define ETHTRCV_30_AR7000_E_INV_POINTER                          0x03U
#define ETHTRCV_30_AR7000_E_INV_CONFIG                           0x04U
#define ETHTRCV_30_AR7000_E_FW_DWLD                              0x05U
#define ETHTRCV_30_AR7000_E_TRCV_CONNECTION_LOST_OR_OVERLOADED   0x06U
#define ETHTRCV_30_AR7000_E_DISABLED_FEATURE                     0x07u
#define ETHTRCV_30_AR7000_E_FW_DOWNLOAD_TIMEOUT                  0x08u
#define ETHTRCV_30_AR7000_E_FW_READY_FOR_PLC_COM_TIMEOUT         0x09u
#define ETHTRCV_30_AR7000_E_QUEUE_SIZE_TOO_SMALL                 0x0Au
#define ETHTRCV_30_AR7000_E_APPLET_TIMEOUT                       0x0Bu
#define ETHTRCV_30_AR7000_E_MODOP_TIMEOUT                        0x0Cu

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define ETHTRCV_30_AR7000_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/***********************************************************************************************************************
 ******************************************** AUTOSAR API **************************************************************
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_InitMemory
 **********************************************************************************************************************/
/*! \brief         Power-up memory initialization
 *  \details       Initializes component variables in *_INIT_* sections at power up.
 *  \pre           Module is uninitialized.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \note          Use this function in case these variables are not initialized by the startup code.
 *  \trace         CREQ-137828
 **********************************************************************************************************************/
FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_InitMemory(void);

/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_Init
 **********************************************************************************************************************/
/*! \brief         Initializes component
 *  \details       Initializes all component variables and sets the component state to initialized.
 *  \param[in]     ConfigPtr             Component configuration structure
 *  \pre           Interrupts are disabled.
 *  \pre           Module is uninitialized.
 *  \pre           EthTrcv_30_Ar7000_InitMemory has been called unless EthTrcv_30_Ar7000_ModuleInitialized is
 *                 initialized by start-up code.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \trace         CREQ-137828
 **********************************************************************************************************************/
FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_Init(
  P2CONST(EthTrcv_30_Ar7000_ConfigType, AUTOMATIC, AUTOMATIC) CfgPtr);

/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_TransceiverInit
 **********************************************************************************************************************/
/*! \brief       Initializes an Ethernet transceiver (register configuration)
 *  \details     This function initializes the transceiver's registers to realize its functionality according to the
 *               configuration.
 *  \param[in]   TrcvIdx               Zero based index of the transceiver
 *  \param[in]   CfgIdx                Configuration index
 *  \return      E_OK                  success
 *  \return      E_NOT_OK              Function has been called with invalid parameters or at least one of the
 *                                     hardware operations (read/write) has failed.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-137830
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_TransceiverInit(
  uint8 TrcvIdx,
  uint8 CfgIdx);

#if ( ETHTRCV_30_AR7000_ENABLE_SET_TRCV_MODE == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_SetTransceiverMode
 **********************************************************************************************************************/
/*! \brief       Sets the transceiver's mode
 *  \details     This function sets the transceiver to active or down.
 *  \param[in]   TrcvIdx               Zero based index of the transceiver
 *  \param[in]   TrcvMode              Transceiver mode to set:
 *                                     ETHTRCV_MODE_DOWN - shut down the Ethernet transceiver
 *                                     ETHTRCV_MODE_ACTIVE - activate the Ethernet transceiver
 *  \return      E_OK       success
 *  \return      E_NOT_OK   Function has been called with invalid parameters or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      ETHTRCV_30_AR7000_ENABLE_SET_TRCV_MODE
 *  \trace       CREQ-137839
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_SetTransceiverMode(
  uint8            TrcvIdx,
  EthTrcv_ModeType TrcvMode);
#endif /* ETHTRCV_30_AR7000_ENABLE_SET_TRCV_MODE */

#if ( ETHTRCV_30_AR7000_ENABLE_GET_TRCV_MODE == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_GetTransceiverMode
 **********************************************************************************************************************/
/*! \brief       Gets the transceiver's mode
 *  \details     This function returns the transceiver's current mode.
 *  \param[in]   TrcvIdx               Zero based index of the transceiver.
 *  \param[in]   TrcvModePtr           Pointer for retrieved transceiver mode:
 *                                     ETHTRCV_MODE_DOWN - transceiver is turned off
 *                                     ETHTRCV_MODE_ACTIVE - transceiver is active
 *  \return      E_OK       success
 *  \return      E_NOT_OK   Function has been called with invalid parameters or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      ETHTRCV_30_AR7000_ENABLE_GET_TRCV_MODE
 *  \trace       CREQ-137983
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_GetTransceiverMode(
        uint8                                   TrcvIdx,
  P2VAR(EthTrcv_ModeType, AUTOMATIC, AUTOMATIC) TrcvModePtr);
#endif /* ETHTRCV_30_AR7000_ENABLE_GET_TRCV_MODE */

#if ( ETHTRCV_30_AR7000_ENABLE_START_AUTO_NEG == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_StartAutoNegotiation
 **********************************************************************************************************************/
/*! \brief       Starts automatic negotiation
 *  \details     This function starts the process to automatically negotiate the transceivers master-slave role,
 *               duplex mode and link speed, if available.
 *  \param[in]   TrcvIdx               Zero based index of the transceiver.
 *  \return      E_OK       success
 *  \return      E_NOT_OK   Function has been called with invalid parameter or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      ETHTRCV_30_AR7000_ENABLE_START_AUTO_NEG
 *  \trace       CREQ-137984
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_StartAutoNegotiation(
  uint8 TrcvIdx);
#endif /* ETHTRCV_30_AR7000_ENABLE_START_AUTO_NEG */

#if ( ETHTRCV_30_AR7000_ENABLE_GET_LINK_STATE == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_GetLinkState
 **********************************************************************************************************************/
/*! \brief       Gets the transceiver's link state
 *  \details     This function returns the transceiver's current link state
 *  \param[in]   TrcvIdx               Zero based index of the transceiver.
 *  \param[out]  LinkStatePtr          Pointer for the retrieved link state value:
 *                                     ETHTRCV_LINK_STATE_DOWN - link is down
 *                                     ETHTRCV_LINK_STATE_ACTIVE - link is up
 *  \return      E_OK       success
 *  \return      E_NOT_OK   Function has been called with invalid parameter or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      ETHTRCV_30_AR7000_ENABLE_GET_LINK_STATE
 *  \trace       CREQ-137985
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_GetLinkState(
        uint8                                        TrcvIdx,
  P2VAR(EthTrcv_LinkStateType, AUTOMATIC, AUTOMATIC) LinkStatePtr);
#endif /* ETHTRCV_30_AR7000_ENABLE_GET_LINK_STATE */

#if ( ETHTRCV_30_AR7000_ENABLE_GET_BAUD_RATE == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_GetBaudRate
 **********************************************************************************************************************/
/*! \brief       Gets the transceiver's baud rate
 *  \details     This function returns the transceiver's current baud rate.
 *  \param[in]   TrcvIdx               Zero based index of the transceiver.
 *  \param[out]  BaudRatePtr           pointer for the retrieved baud rate value:
 *                                     ETHTRCV_BAUD_RATE_10MBIT - Link speed is 10 Mbit/s
 *                                     ETHTRCV_BAUD_RATE_100MBIT - Link speed is 100 Mbit/s
 *                                     ETHTRCV_BAUD_RATE_1000MBIT - Link speed is 1000 Mbit/s
 *  \return      E_OK       success
 *  \return      E_NOT_OK   Function has been called with invalid parameter or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      ETHTRCV_30_AR7000_ENABLE_GET_BAUD_RATE
 *  \trace       CREQ-137986
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_GetBaudRate(
        uint8                                       TrcvIdx,
  P2VAR(EthTrcv_BaudRateType, AUTOMATIC, AUTOMATIC) BaudRatePtr);
#endif /* ETHTRCV_30_AR7000_ENABLE_GET_BAUD_RATE */

#if ( ETHTRCV_30_AR7000_ENABLE_GET_DUPLEX_MODE == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_GetDuplexMode
 **********************************************************************************************************************/
/*! \brief       Gets the transceiver's duplex mode
 *  \details     This function returns the transceiver's current duplex mode.
 *  \param[in]   TrcvIdx               Zero based index of the transceiver
 *  \param[out]  DuplexModePtr         Pointer for the retrieved duplex mode value:
 *                                     ETHTRCV_DUPLEX_MODE_HALF - transceiver operates in half duplex mode
 *                                     ETHTRCV_DUPLEX_MODE_FULL - transceiver operates in full duplex mode
 *  \return      E_OK       success
 *  \return      E_NOT_OK   Function has been called with invalid parameter or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      ETHTRCV_30_AR7000_ENABLE_GET_DUPLEX_MODE
 *  \trace       CREQ-137987
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_GetDuplexMode(
        uint8                                         TrcvIdx,
  P2VAR(EthTrcv_DuplexModeType, AUTOMATIC, AUTOMATIC) DuplexModePtr);
#endif /* ETHTRCV_30_AR7000_ENABLE_GET_DUPLEX_MODE */

#if ( ETHTRCV_30_AR7000_VERSION_INFO_API == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_GetVersionInfo
 **********************************************************************************************************************/
/*! \brief       Returns the version information
 *  \details     This function returns the version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  VersionInfoPtr        Pointer to where to store the version information. Parameter must not be NULL.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      ETHTRCV_30_AR7000_VERSION_INFO_API
 *  \trace       CREQ-137829
 *********************************************************************************************************************/
FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, AUTOMATIC) VersionInfoPtr);
#endif /* ETHTRCV_30_AR7000_VERSION_INFO_API == STD_ON */

/***********************************************************************************************************************
 ******************************************** EXTENDED API *************************************************************
 **********************************************************************************************************************/

#if ( ETHTRCV_30_AR7000_ENABLE_SET_NMK == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_SetNmk
 **********************************************************************************************************************/
/*! \brief       Sets a new network membership key
 *  \details     This API transmits a new NMK to the QCA7005 using a VS_SET_KEY.REQ message. This change is not 
 *               permanent. The NID will be calculated by the QCA7005 chip automatically.
 *  \param[in]   TrcvIdx         Index of selected Transceiver
 *  \param[in]   NmkPtr          Pointer to the new Network Membership Key to be used.
 *  \return      E_OK            NMK change request successful
 *  \return      E_NOT_OK        Failure
 *  \pre         The firmware download must be finished successful and the QCA7005 must be ready for SLAC.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ETHTRCV_30_AR7000_ENABLE_SET_NMK
 *  \trace       CREQ-145731
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_SetNmk(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) NmkPtr);
#endif /* ETHTRCV_30_AR7000_ENABLE_SET_NMK */

#if ( ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_PauseLinkStatePolling
 **********************************************************************************************************************/
/*! \brief       Pause the link state polling during this time
 *  \details     If called the link state polling will be paused for the configured period of time
 *               See: ETHTRCV_30_AR7000_LINKSTATE_LOCK_CYCLES.
 *  \param[in]   TrcvIdx         Index of selected Transceiver
 *  \param[in]   PauseDurationMs Specify the pause duration in milliseconds
 *  \pre         The firmware download must be finished successful and the QCA700X must be ready for SLAC.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD
 *  \trace       CREQ-333915
 **********************************************************************************************************************/
FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_PauseLinkStatePolling(
  uint8                                                            TrcvIdx,
  uint16                                                           PauseDurationMs);
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD */

#if ( ETHTRCV_30_AR7000_ENABLE_READ_NMK == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_ReadNmk
 **********************************************************************************************************************/
/*! \brief       This service reads the current used Network Management Key (NMK).
 *  \details     The function starts an asynchronous read request to the QCA7005 transceiver. While the request
 *               is pending, the function returns ETHTRCV_30_AR7000_RT_PENDING. A newly call of the function after a 
 *               succeeded or failed request starts a new read request. Refer to chapter "Asynchronous APIs" for an 
 *               exemplary usage of this API.
 *  \param[in]   TrcvIdx         Index of selected Transceiver
 *  \param[out]  NmkPtr          NMK read from the transceiver's PIB
 *  \return      ETHTRCV_30_AR7000_RT_OK      NMK valid
 *  \return      ETHTRCV_30_AR7000_RT_NOT_OK  MME handover to Ethernet Controller failed
 *  \return      ETHTRCV_30_AR7000_RT_PENDING Request is pending
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \config      ETHTRCV_30_AR7000_ENABLE_READ_NMK
 *  \trace       CREQ-145732
 **********************************************************************************************************************/
FUNC(EthTrcv_30_Ar7000_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_ReadNmk(
        uint8                                                          TrcvIdx,
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) NmkPtr);
#endif /* ETHTRCV_30_AR7000_ENABLE_READ_NMK */

#if (ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION == STD_ON)
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_GetSwVersion
 **********************************************************************************************************************/
/*! \brief       Returns the firmware version string of QCA7000.
 *  \details     The function sends an asynchronous request to the QCA7005 transceiver. While the request is pending,
 *               the function returns ETHTRCV_30_AR7000_RT_PENDING. A newly call of the function after a succeeded or 
 *               failed request starts a new asynchronous read request. Refer to chapter "Asynchronous APIs" for an 
 *               exemplary usage of this API.
 *  \param[in]   TrcvIdx         Index of selected Transceiver
 *  \param[out]  SwVersionPtr    QCA7000 firmware information string. Buffer needs a minimum size of 48 bytes.
 *  \return      ETHTRCV_30_AR7000_RT_OK      Firmware version string valid
 *  \return      ETHTRCV_30_AR7000_RT_NOT_OK  MME handover to Ethernet Controller failed
 *  \return      ETHTRCV_30_AR7000_RT_PENDING Request is pending
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous FALSE
 *  \config      ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION
 *  \trace       CREQ-145743
 *********************************************************************************************************************/
FUNC(EthTrcv_30_Ar7000_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_GetSwVersion(
        uint8                                                          TrcvIdx,
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) SwVersionPtr);
#endif /* ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION */

#if ( ETHTRCV_30_AR7000_ENABLE_RESET_DEVICE == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_ResetDevice
 **********************************************************************************************************************/
/*! \brief       Triggers a QCA firmware reset request.
 *  \details     -
 *  \param[in]   TrcvIdx         Index of selected Transceiver
 *  \return      E_OK            Reset MME successfully sent to transceiver
 *  \return      E_NOT_OK        Failed to send reset MME to transceiver
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous FALSE
 *  \config      ETHTRCV_30_AR7000_ENABLE_RESET_DEVICE
 *  \trace       CREQ-145727
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_ResetDevice(
  uint8 TrcvIdx);
#endif /* ETHTRCV_30_AR7000_ENABLE_RESET_DEVICE */

#if ( ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_JoinScState
 **********************************************************************************************************************/
/*! \brief       Joins a simple connect network.
 *  \details     Sends a Pushbutton Encryption MME with field PBACTION equals 1. The function starts an asynchronous
 *               request to the QCA7005 transceiver. While no confirmation was received, the function returns 
 *               ETHTRCV_30_AR7000_RT_PENDING. A newly call of the function after a succeeded or failed request starts 
 *               a new asynchronous request. The output parameter MStatus is only valid if the function returns E_OK.
 *               Refer to chapter "Asynchronous APIs" for an exemplary usage of this API.
 *  \param[in]   TrcvIdx          Index of selected Transceiver
 *  \param[in]   MStatus          According to MSTATUS field of MS_PB_ENC MME
 *  \return      ETHTRCV_30_AR7000_RT_OK      Success
 *  \return      ETHTRCV_30_AR7000_RT_NOT_OK  Failure
 *  \return      ETHTRCV_30_AR7000_RT_PENDING Request is pending
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous FALSE
 *  \config      ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API
 *  \trace       CREQ-145733
 **********************************************************************************************************************/
FUNC(EthTrcv_30_Ar7000_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_JoinScState(
        uint8                                                          TrcvIdx,
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) MStatus);

/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_LeaveScState
 **********************************************************************************************************************/
/*! \brief       Leaves a simple connect network.
 *  \details     Sends a Pushbutton Encryption MME with field PBACTION equals 2. The function starts an asynchronous
 *               request to the QCA7005 transceiver. While no confirmation was received, the function returns 
 *               ETHTRCV_30_AR7000_RT_PENDING. A newly call of the function after a succeeded or failed request starts 
 *               a new asynchronous request. The output parameter MStatus is only valid if the function returns E_OK.
 *               Refer to chapter "Asynchronous APIs" for an exemplary usage of this API.
 *  \param[in]   TrcvIdx          Index of selected Transceiver
 *  \param[in]   MStatus          According to MSTATUS field of MS_PB_ENC MME
 *  \return      ETHTRCV_30_AR7000_RT_OK      Success
 *  \return      ETHTRCV_30_AR7000_RT_NOT_OK  Failure
 *  \return      ETHTRCV_30_AR7000_RT_PENDING Request is pending
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous FALSE
 *  \config      ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API
 *  \trace       CREQ-145734
 **********************************************************************************************************************/
FUNC(EthTrcv_30_Ar7000_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_LeaveScState(
        uint8                                                          TrcvIdx,
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) MStatus);

/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_ReadAVLNStatus
 **********************************************************************************************************************/
/*! \brief       Reads HomePlug AV Nework Membership Status.
 *  \details     Sends a Pushbutton Encryption MME with PBACTION equals 3 (AVLN Status) and waits for a response.
 *               The function starts an asynchronous request to the QCA7005 transceiver. While no confirmation was
 *               received, the function returns ETHTRCV_30_AR7000_RT_PENDING. A newly call of the function after a 
 *               succeeded or failed request starts a new asynchronous request. The output parameters MStatus and 
 *               AVLNStatus are only valid if the function returns ETHTRCV_30_AR7000_RT_OK. Refer to chapter 
 *               "Asynchronous APIs" for an exemplary usage of this API.
 *  \param[in]   TrcvIdx          Index of selected Transceiver
 *  \param[in]   MStatus          According to MSTATUS field of MS_PB_ENC MME
 *  \param[in]   AVLNStatus       According to AVLNStatus field of MS_PB_ENC_MME
 *  \return      ETHTRCV_30_AR7000_RT_OK             Success
 *  \return      ETHTRCV_30_AR7000_RT_NOT_OK         Failure
 *  \return      ETHTRCV_30_AR7000_RT_PENDING        Request is pending
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous FALSE
 *  \config      ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API
 *  \trace       CREQ-145735
 **********************************************************************************************************************/
FUNC(EthTrcv_30_Ar7000_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_ReadAVLNStatus(
        uint8                                                          TrcvIdx,
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) MStatus,
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) AVLNStatus);
#endif /* ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API */

#if ( ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE == ETHTRCV_30_AR7000_CFG_PAS_NVM )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_WritePhysAddr
 **********************************************************************************************************************/
/*! \brief       Writes the Physical Address for PLC into program information block (PIB).
 *  \details     After a call of NvM_WriteAll() the new MAC address is persistent. 
 *               In case ETHTRCV_30_AR7000_APPL_CBK_GET_PHYS_ADDR is set in the configuration, a call to this API will 
 *               check if the address provided by ETHTRCV_30_AR7000_APPL_CBK_GET_PHYS_ADDR is equal to the parameter 
 *               PhysAddr. The application has to ensure consistency of both addresses.
 *  \param[in]   PhysAddr        Physical Address
 *  \return      E_OK            Success
 *  \return      E_NOT_OK        Failure
 *  \pre         This API must not be called while a PIB file exchange is active
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE
 *  \note        The function can be called before firmware download was started. When the firmware was already
 *               running, the transceiver restarts and the firmware is downloaded again (Highly time-consuming).
 *  \trace       CREQ-145722
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_WritePhysAddr(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) PhysAddr);
#endif /* ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE == ETHTRCV_30_AR7000_CFG_PAS_NVM */

#if ( ETHTRCV_30_AR7000_ENABLE_WRITE_DAK == STD_ON )
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_WriteDak
 **********************************************************************************************************************/
/*! \brief       Writes the Device Access Key (DAK) for PLC into program information block (PIB).
 *  \details     After a call of NvM_WriteAll() the new DAK is persistent.
 *  \param[in]   TrcvIdx         Index of selected Transceiver
 *  \param[in]   Dak             Device Access Key
 *  \return      E_OK            Success
 *  \return      E_NOT_OK        Failure
 *  \pre         This API must not be called while a PIB file exchange is active
 *               exchange is active
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      ETHTRCV_30_AR7000_ENABLE_WRITE_DAK
 *  \note        The function can be called before firmware download was started. When the firmware was already
 *               running, the transceiver restarts and the firmware is downloaded again (Highly time-consuming).
 *  \trace       CREQ-145723
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_WriteDak(
                                                                                 uint8 TrcvIdx,
  CONSTP2CONST(uint8, ETHTRCV_30_AR7000_APPL_CONST, ETHTRCV_30_AR7000_APPL_DATA) Dak);
#endif /* ETHTRCV_30_AR7000_ENABLE_WRITE_DAK */

#if (ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API == STD_ON)
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_SetProperty
 **********************************************************************************************************************/
/*! \brief       Sets a property via VS_SET_PROPERTY MME.
 *  \details     The function sends an asynchronous request to the QCA7005 transceiver. While the request is pending,
 *               the function returns ETHTRCV_30_AR7000_RT_PENDING. A newly call of the function after a succeeded or 
 *               failed request starts a new asynchronous read request. Refer to chapter "Asynchronous APIs" for an 
 *               exemplary usage of this API.
 *  \param[in]   TrcvIdx          Index of selected Transceiver
 *  \param[in]   SetPropParams    A structure of type EthTrcv_30_Ar7000_SetPropertyParamterType, containing the field
 *                                values of the VS_SET_PROPERTY MME.
 *  \param[out]  MStatus          The MME status returned by VS_SET_PROPERTY.CNF:\n
 *                                  ETHTRCV_30_AR7000_SETPROP_SUCCESS : Property successfully set\n
 *                                  ETHTRCV_30_AR7000_SETPROP_FAILURE : Property failed to set\n
 *                                  ETHTRCV_30_AR7000_SETPROP_PROP_NOT_SUPPORTED : Property ID not supported\n
 *                                  ETHTRCV_30_AR7000_SETPROP_VER_NOT_SUPPORTED : Property Version not supported\n
 *                                  ETHTRCV_30_AR7000_SETPROP_PROP_NOT_PERSISTENT : Property not persistent\n
 *                                  ETHTRCV_30_AR7000_SETPROP_FLASH_FAILURE :     : Flash failure
 *  \return      ETHTRCV_30_AR7000_RT_OK      Property successfully set\n
 *  \return      ETHTRCV_30_AR7000_RT_NOT_OK  MME handover to Ethernet Controller failed\n
 *  \return      ETHTRCV_30_AR7000_RT_PENDING Request is pending
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous FALSE
 *  \config      ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API
 *  \trace       CREQ-145724
 *********************************************************************************************************************/
FUNC(EthTrcv_30_Ar7000_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_SetProperty(
  uint8 TrcvIdx,
  CONSTP2CONST(EthTrcv_30_Ar7000_SetPropertyParamterType, ETHTRCV_30_AR7000_APPL_CONST, ETHTRCV_30_AR7000_APPL_CONST)
    SetPropParams,
  P2VAR(EthTrcv_30_Ar7000_SetPropType, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) MStatus);
#endif /* ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API */

#if (ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API == STD_ON)
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_SetPibData
 **********************************************************************************************************************/
/*! \brief       Sets the pointer to the local Parameter Information Block(PIB) to be used during a firmware download.
 *  \details     The user must call the API between EthTrcv_30_Ar7000_Init() and EthTrcv_30_Ar7000_TransceiverInit() to
 *               overwrite the default PIB during the initial Firmware Download. Otherwise he needs to call
 *               the Reset Device API to carry out the changes to the QCA7000.\n
 *               In case the "Write Physical Address" or "Write DAK" API is enabled the desired physical address or the
 *               DAK is written into the newly set PIB.
 *  \param[in]   TrcvIdx         Index of selected Transceiver
 *  \param[in]   Pib             Pointer to the Parameter Information Block to be used.
 *                               NULL_PTR restores the default PIB
 *  \return      E_OK            PIB pointer successfully set
 *  \return      E_NOT_OK        Failed to write the physical address or the DAK into PIB.
 *  \pre         This API must not be called while a PIB file exchange is active
 *               exchange is active
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous FALSE
 *  \config      ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API
 *  \trace       CREQ-145729
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_SetPibData(
          uint8                                                            TrcvIdx,
  P2CONST(uint8, ETHTRCV_30_AR7000_APPL_DATA, ETHTRCV_30_AR7000_APPL_DATA) Pib);
#endif /* ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API */

#if ( STD_ON == ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD ) && ( STD_OFF == ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD)
/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_TriggerDwld
 **********************************************************************************************************************/
/*! \brief       Triggers a data transfer of a firmware data chunk.
 *  \details     -
 *  \param[in]   TrcvIdx         Index of selected Transceiver
 *  \return      ETHTRCV_30_AR7000_RT_OK      The transfer is finished. All subsequent calls return E_OK.
 *  \return      ETHTRCV_30_AR7000_RT_NOT_OK  The transfer of current data chunk failed. This happened most likely 
 *                                            because of a missing Ethernet buffer. Try again later (it is 
 *                                            recommended to use a retry counter).
 *  \return      ETHTRCV_30_AR7000_RT_PENDING The transfer is ongoing, call API again
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \config      ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD && ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD
 *  \trace       CREQ-145728
 **********************************************************************************************************************/
FUNC(EthTrcv_30_Ar7000_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_TriggerDwld(
  uint8 TrcvIdx);
#endif /* ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD, ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD */

/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MainFunction
 **********************************************************************************************************************/
/*! \brief       Cyclic main function
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 **********************************************************************************************************************/
/* FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MainFunction(void); */

/***********************************************************************************************************************
 *  EthTrcv_30_Ar7000_MME_RxIndication
 **********************************************************************************************************************/
/*! \brief       This service is called by a lower layer (EthIf normally) if a MME message is received.
 *  \details     -
 *  \param[in]   EthIfCtrlIdx   The Ethernet interface Index from which this message originates
 *  \param[in]   FrameType      Ethernet frame type
 *  \param[in]   IsBroadcast    Broadcast indication
 *  \param[in]   PhysAddrPtr    Pointer to MAC address
 *  \param[in]   DataPtr        Pointer to received data frame
 *  \param[in]   LenByte        Length of received frame
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \trace       CREQ-145736
 **********************************************************************************************************************/
FUNC(void, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_MME_RxIndication(
        uint8                                                          EthIfCtrlIdx,
        Eth_FrameType                                                  FrameType,
        boolean                                                        IsBroadcast,
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) PhysAddrPtr,
  P2VAR(uint8, ETHTRCV_30_AR7000_APPL_VAR, ETHTRCV_30_AR7000_APPL_VAR) DataU8Ptr,
        uint16                                                         LenByte );

/**********************************************************************************************************************
 * EthTrcv_30_Ar7000_SetPhyTxMode
 **********************************************************************************************************************/
/*! \brief        Activates a given transmission mode of the related hardware driver
 *  \details      This is an empty dummy API only, it is required by the EthIf. It will return E_NOT_OK.
 *  \param[in]    TrcvIdx  Index of the transceiver within the context of the Ethernet Interface.
 *  \param[in]    Mode     Transmission mode to be activated.
 *  \return       E_NOT_OK - Not supported
 *  \pre          -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \trace        CREQ-232554
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_SetPhyTxMode(
  uint8                 TrcvIdx,
  EthTrcv_PhyTxModeType Mode);

/**********************************************************************************************************************
 * EthTrcv_30_Ar7000_GetCableDiagnosticsResult
 **********************************************************************************************************************/
/*! \brief        Retrieves the cable diagnostics result of a given transceiver.
 *  \details      This is an empty dummy API only, it is required by the EthIf. It will return E_NOT_OK.
 *  \param[in]    TrcvIdx    Index of the transceiver within the context of the Ethernet Interface.
 *  \param[out]   ResultPtr  Pointer to the location where the cable diagnostics result shall be stored.
 *  \return       E_NOT_OK - Not supported
 *  \pre          -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \trace        CREQ-232554
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_GetCableDiagnosticsResult (
        uint8                                                               TrcvIdx,
  P2VAR(EthTrcv_CableDiagResultType, AUTOMATIC, ETHTRCV_30_AR7000_APPL_VAR) ResultPtr);

/**********************************************************************************************************************
 * EthTrcv_30_Ar7000_SetPhyTestMode
 **********************************************************************************************************************/
/*! \brief        Activates a given test mode of the related hardware driver
 *  \details      This is an empty dummy API only, it is required by the EthIf. It will return E_NOT_OK.
 *  \param[in]    TrcvIdx  Index of the transceiver within the context of the Ethernet Interface.
 *  \param[in]    Mode     Test mode to be activated.
 *  \return       E_NOT_OK - Not supported
 *  \pre          -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \trace        CREQ-232554
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_SetPhyTestMode(
  uint8                    TrcvIdx,
  EthTrcv_PhyTestModeType  Mode);

/**********************************************************************************************************************
 * EthTrcv_30_Ar7000_GetPhySignalQuality
 **********************************************************************************************************************/
/*! \brief        Retrieves the signal quality of the related hardware driver
 *  \details      This is an empty dummy API only, it is required by the EthIf. It will return E_NOT_OK.
 *  \param[in]    TrcvIdx    Index of the transceiver within the context of the Ethernet Interface.
 *  \param[out]   ResultPtr  Pointer to the memory where the signal quality in percent shall be stored.
 *  \return       E_NOT_OK - Not supported
 *  \pre          -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \trace        CREQ-232554
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_AR7000_CODE) EthTrcv_30_Ar7000_GetPhySignalQuality(
        uint8                                         TrcvIdx,
  P2VAR(uint8, AUTOMATIC, ETHTRCV_30_AR7000_APPL_VAR) ResultPtr);

#define ETHTRCV_30_AR7000_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#endif /* ETHTRCV_30_AR7000_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTrcv.h
 *********************************************************************************************************************/

