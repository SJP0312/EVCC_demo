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
 *            Module: EthTrcv_Ar7000
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EthTrcv_30_Ar7000_Cfg.h
 *   Generation Time: 2025-09-11 13:39:31
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/


#if !defined(ETHTRCV_30_AR7000_CFG_H)
#define ETHTRCV_30_AR7000_CFG_H

/* START of Checksum exclude for - EthTrcv_PrecompileCRC */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"



/**********************************************************************************************************************
 *  SYMBOLIC NAME VALUE DEFINES: TRCV
 *********************************************************************************************************************/
 #define EthTrcvConf_EthTrcvConfig_EthTrcvConfig (0u) 


/**********************************************************************************************************************
 *  LINKTIME / PRECOMPILE CRC
 *********************************************************************************************************************/
#define ETHTRCV_30_AR7000_CRC_CHECK                    STD_OFF
#define ETHTRCV_30_AR7000_PRECOMPILE_CRC               (uint32) 0xeb10f1ccU


/**********************************************************************************************************************
 *  GENERAL DEFINES
 *********************************************************************************************************************/
#ifndef ETHTRCV_30_AR7000_USE_DUMMY_STATEMENT
#define ETHTRCV_30_AR7000_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef ETHTRCV_30_AR7000_DUMMY_STATEMENT
#define ETHTRCV_30_AR7000_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef ETHTRCV_30_AR7000_DUMMY_STATEMENT_CONST
#define ETHTRCV_30_AR7000_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef ETHTRCV_30_AR7000_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define ETHTRCV_30_AR7000_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef ETHTRCV_30_AR7000_ATOMIC_VARIABLE_ACCESS
#define ETHTRCV_30_AR7000_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef ETHTRCV_30_AR7000_PROCESSOR_TC377T
#define ETHTRCV_30_AR7000_PROCESSOR_TC377T
#endif
#ifndef ETHTRCV_30_AR7000_COMP_DIAB
#define ETHTRCV_30_AR7000_COMP_DIAB
#endif
#ifndef ETHTRCV_30_AR7000_GEN_GENERATOR_MSR
#define ETHTRCV_30_AR7000_GEN_GENERATOR_MSR
#endif
#ifndef ETHTRCV_30_AR7000_CPUTYPE_BITORDER_LSB2MSB
#define ETHTRCV_30_AR7000_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef ETHTRCV_30_AR7000_CONFIGURATION_VARIANT_PRECOMPILE
#define ETHTRCV_30_AR7000_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef ETHTRCV_30_AR7000_CONFIGURATION_VARIANT_LINKTIME
#define ETHTRCV_30_AR7000_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef ETHTRCV_30_AR7000_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define ETHTRCV_30_AR7000_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef ETHTRCV_30_AR7000_CONFIGURATION_VARIANT
#define ETHTRCV_30_AR7000_CONFIGURATION_VARIANT ETHTRCV_30_AR7000_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef ETHTRCV_30_AR7000_POSTBUILD_VARIANT_SUPPORT
#define ETHTRCV_30_AR7000_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/**********************************************************************************************************************
 *  INTEGER DEFINES
 *********************************************************************************************************************/
/* START of Checksum include for - EthTrcv_PrecompileCRC */

#define ETHTRCV_30_AR7000_CONFIG_VARIANT            1U
#define ETHTRCV_30_AR7000_MAX_TRCVS_TOTAL           1u
#define ETHTRCV_30_AR7000_WAKEUP_TYPE               ETHTRCV_WAKEUP_NOT_SUPPORTED
#define ETHTRCV_30_AR7000_MAX_WAKEUP_MAP_NUM        0u

#define ETHTRCV_30_AR7000_HW_IDX              EthConf_EthCtrlConfig_EthCtrlConfig
#define ETHTRCV_30_AR7000_ETHIF_CTRL          EthIfConf_EthIfController_EthIfController
#define ETHTRCV_30_AR7000_MAINFUNC_CYCLE_TIME 20u

/* END of Checksum include for - EthTrcv_PrecompileCRC */


/**********************************************************************************************************************
 *  SWITCH DEFINES
 *********************************************************************************************************************/
/* START of Checksum include for - EthTrcv_PrecompileCRC */

#define ETHTRCV_30_AR7000_DEV_ERROR_DETECT          STD_ON
#define ETHTRCV_30_AR7000_DEM_ERROR_DETECT          STD_OFF
#define ETHTRCV_30_AR7000_VERSION_INFO_API          STD_OFF
#define ETHTRCV_30_AR7000_ENABLE_GET_TRCV_MODE      STD_ON
#define ETHTRCV_30_AR7000_ENABLE_SET_TRCV_MODE      STD_ON
#define ETHTRCV_30_AR7000_ENABLE_START_AUTO_NEG     STD_ON
#define ETHTRCV_30_AR7000_ENABLE_GET_LINK_STATE     STD_ON
#define ETHTRCV_30_AR7000_ENABLE_GET_BAUD_RATE      STD_ON
#define ETHTRCV_30_AR7000_ENABLE_GET_DUPLEX_MODE    STD_ON


/**********************************************************************************************************************
 *  AR7000 Firmware Download
 *********************************************************************************************************************/
#define ETHTRCV_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD                STD_ON
#define ETHTRCV_30_AR7000_ENABLE_TURBO_FW_DWLD                    STD_ON
#define ETHTRCV_30_AR7000_FW_DWLD_ATTEMPTS                        3u
#define ETHTRCV_30_AR7000_ETHBLOCKSIZE                            1400u
#define ETHTRCV_30_AR7000_DEFAULTBLOCKSIZE                        64u
#define ETHTRCV_30_AR7000_MAX_API_CALL_RET_CNT                    5u
#define ETHTRCV_30_AR7000_HST_ACTION_QUEUE_SIZE                   5u
#define ETHTRCV_30_AR7000_ENABLE_DET_ON_DISABLED_HST_ACT_EVENTS   STD_ON
#define ETHTRCV_30_AR7000_ENABLE_DEVICE_READY_FOR_HIF_COM_EVENT   STD_OFF
#define ETHTRCV_30_AR7000_ENABLE_DEVICE_READY_FOR_SLAC_COM_EVENT  STD_OFF
#define ETHTRCV_30_AR7000_ENABLE_MEMBER_OF_AVLN_WITH_PEERS_EVENT  STD_OFF
#define ETHTRCV_30_AR7000_FIRMWARE_DOWNLOAD_AND_START_CYCLES      3276u
#define ETHTRCV_30_AR7000_FIRMWARE_READY_FOR_SLAC_TIMEOUT_CYCLES  100u


/**********************************************************************************************************************
 *  AR7000 NMK 
 *********************************************************************************************************************/
#define ETHTRCV_30_AR7000_ENABLE_SET_NMK                                   STD_OFF
#define ETHTRCV_30_AR7000_ENABLE_READ_NMK                                  STD_OFF
#define ETHTRCV_30_AR7000_NMK_SIZE_BYTE                                    16u
#define ETHTRCV_30_AR7000_NID_SIZE_BYTE                                    7u
#define ETHTRCV_30_AR7000_ENABLE_HASH_NID_EXAMPLE_FUNCTION                 STD_OFF
#define ETHTRCV_30_AR7000_ENABLE_LINK_STATE_POLLING_PAUSE_AFTER_SET_NMK    STD_OFF

/**********************************************************************************************************************
 *  AR7000 Simple Connect
 *********************************************************************************************************************/
#define ETHTRCV_30_AR7000_ENABLE_SIMPLE_CONNECT_API               STD_OFF
 
/**********************************************************************************************************************
 *  AR7000 PIB Change
 *********************************************************************************************************************/
#define ETHTRCV_30_AR7000_ENABLE_PIB_BACKUP                       STD_OFF
#define ETHTRCV_30_AR7000_ENABLE_PIB_CHANGE_CBK                   STD_OFF
#define ETHTRCV_30_AR7000_ENABLE_SET_PIB_DATA_API                 STD_OFF

/**********************************************************************************************************************
 *  AR7000 Physical Address
 *********************************************************************************************************************/
/* QCA chip addres source */
#define ETHTRCV_30_AR7000_CFG_PAS_PIB     0U
#define ETHTRCV_30_AR7000_CFG_PAS_CONST   1U
#define ETHTRCV_30_AR7000_CFG_PAS_CALLOUT 2U
#define ETHTRCV_30_AR7000_CFG_PAS_NVM     3U

#define ETHTRCV_30_AR7000_CFG_PHYSICAL_ADDRESS_SOURCE        ETHTRCV_30_AR7000_CFG_PAS_CALLOUT

#define ETHTRCV_30_AR7000_MAC_PIB_OFFSET                     12u

/**********************************************************************************************************************
 *  AR7000 Reset Device
 *********************************************************************************************************************/
#define ETHTRCV_30_AR7000_ENABLE_RESET_DEVICE                     STD_OFF

/**********************************************************************************************************************
 *  AR7000 Firmware Version
 *********************************************************************************************************************/
#define ETHTRCV_30_AR7000_ENABLE_GET_SW_VERSION                   STD_OFF
 
/**********************************************************************************************************************
 *  AR7000 DAK
 *********************************************************************************************************************/
#define ETHTRCV_30_AR7000_ENABLE_WRITE_DAK                        STD_OFF

/**********************************************************************************************************************
 *  AR7000 Error Handling
 *********************************************************************************************************************/
#define ETHTRCV_30_AR7000_ENABLE_DET_ON_FW_OR_COM_ERROR           STD_ON
 
/**********************************************************************************************************************
 *  AR7000 Further QCA Specifics
 *********************************************************************************************************************/
#define ETHTRCV_30_AR7000_ENABLE_SM_HOOK_ROUTINE                  STD_OFF
#define ETHTRCV_30_AR7000_ENABLE_MODOP_API                        STD_OFF
#define ETHTRCV_30_AR7000_ENABLE_SET_PROPERTY_API                 STD_OFF
#define ETHTRCV_30_AR7000_MTYPE                                   0x88E1u
#define ETHTRCV_30_AR7000_LINKSTATEPOLLINGFREQ                    20u
#define ETHTRCV_30_AR7000_CONFTIMEOUT                             30u
#define ETHTRCV_30_AR7000_LINKSTATE_LOCK_CYCLES                   200u
#define ETHTRCV_30_AR7000_WRITE_APPLET_LOCK_CYCLES                20u
#define ETHTRCV_30_AR7000_HEARTBEAT_TIMEOUT                       100u



/* END of Checksum include for - EthTrcv_PrecompileCRC */


/**********************************************************************************************************************
 *  ETHTRCV ECUC GLOBAL CONFIGURATION CONTAINER NAME
 *********************************************************************************************************************/
/* START of Checksum include for - EthTrcv_PrecompileCRC */


#define EthTrcv_30_Ar7000_ConfigSet                     EthTrcv_30_Ar7000_Config

/* END of Checksum include for - EthTrcv_PrecompileCRC */




/* END of Checksum exclude for - EthTrcv_PrecompileCRC */

#endif /* ETHTRCV_30_AR7000_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Ar7000_Cfg.h
 *********************************************************************************************************************/
 

