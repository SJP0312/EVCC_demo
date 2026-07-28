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
 *              File: Eth_30_Ar7000_Cfg.h
 *   Generation Time: 2025-09-11 13:39:31
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/


#if !defined(ETH_30_AR7000_CFG_H)
#define ETH_30_AR7000_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"



/**********************************************************************************************************************
 *  SYMBOLIC NAME VALUE DEFINES: CTRL
 *********************************************************************************************************************/
#define EthConf_EthCtrlConfig_EthCtrlConfig (0u)



/**********************************************************************************************************************
 *  GENERAL DEFINES
 *********************************************************************************************************************/
#ifndef ETH_30_AR7000_USE_DUMMY_STATEMENT
#define ETH_30_AR7000_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef ETH_30_AR7000_DUMMY_STATEMENT
#define ETH_30_AR7000_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef ETH_30_AR7000_DUMMY_STATEMENT_CONST
#define ETH_30_AR7000_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef ETH_30_AR7000_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define ETH_30_AR7000_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef ETH_30_AR7000_ATOMIC_VARIABLE_ACCESS
#define ETH_30_AR7000_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef ETH_30_AR7000_PROCESSOR_TC377T
#define ETH_30_AR7000_PROCESSOR_TC377T
#endif
#ifndef ETH_30_AR7000_COMP_DIAB
#define ETH_30_AR7000_COMP_DIAB
#endif
#ifndef ETH_30_AR7000_GEN_GENERATOR_MSR
#define ETH_30_AR7000_GEN_GENERATOR_MSR
#endif
#ifndef ETH_30_AR7000_CPUTYPE_BITORDER_LSB2MSB
#define ETH_30_AR7000_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef ETH_30_AR7000_CONFIGURATION_VARIANT_PRECOMPILE
#define ETH_30_AR7000_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef ETH_30_AR7000_CONFIGURATION_VARIANT_LINKTIME
#define ETH_30_AR7000_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef ETH_30_AR7000_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define ETH_30_AR7000_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef ETH_30_AR7000_CONFIGURATION_VARIANT
#define ETH_30_AR7000_CONFIGURATION_VARIANT ETH_30_AR7000_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef ETH_30_AR7000_POSTBUILD_VARIANT_SUPPORT
#define ETH_30_AR7000_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/**********************************************************************************************************************
 *  INTEGER DEFINES
 *********************************************************************************************************************/
#define ETH_30_AR7000_CONFIG_VARIANT                   1U

#define ETH_30_AR7000_RUNTIME_ENV_AUTOSAR_OS           (0U)
#define ETH_30_AR7000_RUNTIME_ENV_GREENHILLS_INTEGRITY (1U)
#define ETH_30_AR7000_RUNTIME_ENV                      ETH_30_AR7000_RUNTIME_ENV_AUTOSAR_OS

#define ETH_30_AR7000_RX_BUF_TOTAL                     2u
#define ETH_30_AR7000_TX_BUF_TOTAL                     2u
#define ETH_30_AR7000_CTRL_IDX_OFFSET                  0u
#define ETH_30_AR7000_TX_MAX_BUF_SIZE                  1518u
#define ETH_30_AR7000_MAX_CTRLS_TOTAL                  1u
#define ETH_30_AR7000_INTERRUPT_CATEGORY               ETH_30_AR7000_ISR_NO_OS_SUPPORT


#define ETH_30_AR7000_SPI_REG_RDBUF_WATERMARK_VALUE    1528u
#define ETH_30_AR7000_MAX_REG_FLOWS                    10u
#define ETH_30_AR7000_MAX_BUF_FLOWS                    6u
#define ETH_30_AR7000_MAX_FLOWS_TOTAL                  16u
#define ETH_30_AR7000_MAX_RETRY_CNT_TX                 30u
#define ETH_30_AR7000_IRQ_POLL_TICKS                   10u
#define ETH_30_AR7000_OUT_OF_SYNC_POLL_TICKS           25u
#define ETH_30_AR7000_RECOV_ATTEMPTS_AFTER_OSD         3u

/**********************************************************************************************************************
 *  SYMBOLIC NAME DEFINES: SPI SEQUENCES AND CHANNELS
 *********************************************************************************************************************/
#define ETH_30_AR7000_ENABLE_SPI_PADDING               STD_OFF
#define ETH_30_AR7000_SPI_REF_SEQ_DATA SpiConf_SpiSequence_Spi_SeqData 
#define ETH_30_AR7000_SPI_REF_SEQ_REG SpiConf_SpiSequence_Spi_SeqReg 
#define ETH_30_AR7000_SPI_REF_CHL_CMD_REG_0 SpiConf_SpiChannel_Spi_ChlCmd 
#define ETH_30_AR7000_SPI_REF_CHL_CMD_REG_1 SpiConf_SpiChannel_Spi_ChlReg 
#define ETH_30_AR7000_SPI_REF_CHL_DATA SpiConf_SpiChannel_Spi_ChlData 


/**********************************************************************************************************************
 *  SWITCH DEFINES
 *********************************************************************************************************************/
#define ETH_30_AR7000_DEV_ERROR_DETECT                 STD_ON
#define ETH_30_AR7000_DEM_ERROR_DETECT                 STD_OFF
#define ETH_30_AR7000_ENABLE_RX_INTERRUPT              STD_ON
#define ETH_30_AR7000_ENABLE_TX_INTERRUPT              STD_ON
#define ETH_30_AR7000_MII_INTERFACE                    STD_ON
#define ETH_30_AR7000_VERSION_INFO_API                 STD_OFF
#define ETH_30_AR7000_ENABLE_UPDATE_PHYS_ADDR_FILTER   STD_ON
#define ETH_30_AR7000_ENABLE_MAC_WRITE_ACCESS          STD_OFF
#define ETH_30_AR7000_DYNAMIC_TRAFFIC_SHAPING_SUPPORT  STD_OFF
#define ETH_30_AR7000_ENABLE_CHECKSUM_OFFLOADING       STD_OFF
#define ETH_30_AR7000_ENABLE_QOS                       STD_OFF
#define ETH_30_AR7000_ENABLE_PTP                       STD_OFF
#define ETH_30_AR7000_ETHSWT_FRAME_MANAGMENT_SUPPORT   STD_OFF
#define ETH_30_AR7000_ZERO_COPY_EXTENSIONS_SUPPORT     STD_OFF
#define ETH_30_AR7000_HEADER_ACCESS_API_SUPPORT        STD_OFF
#define ETH_30_AR7000_ENABLE_PRE_CTRLINIT_CALL         STD_OFF
#define ETH_30_AR7000_ENABLE_POST_CTRLINIT_CALL        STD_OFF
#define ETH_30_AR7000_USE_PERIPHERAL_ACCESS_API        STD_OFF

#define ETH_30_AR7000_DEV_ERROR_REPORT                 (ETH_30_AR7000_DEV_ERROR_DETECT)
#define ETH_30_AR7000_ENABLE_MAC_ADDR_CBK              STD_OFF
#define ETH_30_AR7000_SPI_ASYNC_MODE_ENABLED           STD_ON
#define ETH_30_AR7000_ENABLE_DET_ON_SPI_BUS_ERROR      STD_ON
#define ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT        STD_ON
#define ETH_30_AR7000_ENABLE_SPI_BUF_ERR_DETECT        STD_ON
#define ETH_30_AR7000_ENABLE_FIRMWARE_DOWNLOAD         STD_ON


/**********************************************************************************************************************
 *  ETH ECUC GLOBAL CONFIGURATION CONTAINER NAME
 *********************************************************************************************************************/
#define Eth_30_Ar7000_ConfigSet                         Eth_30_Ar7000_Config

/**********************************************************************************************************************
 *  USER CONFIG FILE CONTENT
 *********************************************************************************************************************/
/* User Config File Start */
#define SpiConf_SpiSequence_Spi_SeqData Spi_SeqData
#define SpiConf_SpiSequence_Spi_SeqReg  Spi_SeqReg
#define SpiConf_SpiChannel_Spi_ChlCmd   Spi_ChlCmd
#define SpiConf_SpiChannel_Spi_ChlReg   Spi_ChlReg
#define SpiConf_SpiChannel_Spi_ChlData  Spi_ChlData
/* User Config File End */



#endif /* ETH_30_AR7000_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Eth_30_Ar7000_Cfg.h
 *********************************************************************************************************************/
 

