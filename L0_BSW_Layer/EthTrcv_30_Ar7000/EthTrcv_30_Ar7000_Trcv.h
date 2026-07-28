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
/**        \file  EthTrcv_30_Ar7000_Trcv.h
 *        \brief  Ethernet transceiver driver QCA 7005 SPI specific header file
 *
 *      \details  Vector static code SPI specific header file for the Ethernet transceiver driver QCA 7005. This header
 *                file contains module declarations that are specific for the QCA 7005 SPI protocol.
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

#if !defined (ETHTRCV_30_AR7000_TRCV_H)
# define ETHTRCV_30_AR7000_TRCV_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Platform_Types.h" /*lint !e451 */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Register addresses */
#define ETHTRCV_30_AR7000_ETH_SPI_REG_BFR_SIZE                      0x0100u
#define ETHTRCV_30_AR7000_ETH_SPI_REG_WRBUF_SPC_AVA                 0x0200u
#define ETHTRCV_30_AR7000_ETH_SPI_REG_RDBUF_BYTE_AVA                0x0300u
#define ETHTRCV_30_AR7000_ETH_SPI_REG_CONFIG                        0x0400u
#define ETHTRCV_30_AR7000_ETH_SPI_REG_STATUS                        0x0500u
#define ETHTRCV_30_AR7000_ETH_SPI_REG_INTR_CAUSE                    0x0C00u
#define ETHTRCV_30_AR7000_ETH_SPI_REG_INTR_ENABLE                   0x0D00u
#define ETHTRCV_30_AR7000_ETH_SPI_REG_RDBUF_WATERMARK               0x1200u
#define ETHTRCV_30_AR7000_ETH_SPI_REG_WRBUF_WATERMARK               0x1300u

/* SPI Config register Fields */
#define ETHTRCV_30_AR7000_SPI_IO_ENABLE                             0x0080u
#define ETHTRCV_30_AR7000_SPI_IO_DISABLE                            0x0000u
#define ETHTRCV_30_AR7000_SPI_SOC_CORE_RESET                        0x0040u

/* Host Actions Required Fields, also used for EthTrcv_30_Ar7000_AppletNrLocked */
#define ETHTRCV_30_AR7000_HST_ACT_LOADER_READY                      0x00u
#define ETHTRCV_30_AR7000_HST_ACT_FW_UPGRADE_READY                  0x01u
#define ETHTRCV_30_AR7000_HST_ACT_PIB_UPDATE_READY                  0x02u
#define ETHTRCV_30_AR7000_HST_ACT_FW_PIB_READY                      0x03u
#define ETHTRCV_30_AR7000_HST_ACT_LOADER_READY_FOR_SDRAM            0x04u
#define ETHTRCV_30_AR7000_HST_ACT_BGR_PIB_UPDATE_READY              0x06u
#define ETHTRCV_30_AR7000_HST_ACT_DEVICE_REBOOTED                   0x07u
#define ETHTRCV_30_AR7000_HST_ACT_DEVICE_READY_FOR_HIF_COM          0x08u
#define ETHTRCV_30_AR7000_HST_ACT_DEVICE_READY_FOR_PLC_COM          0x09u
#define ETHTRCV_30_AR7000_HST_ACT_MEMBER_OF_AVLN_WITH_PEERS         0x0Au

/* No applet locked value used in EthTrcv_30_Ar7000_AppletNrLocked */
#define ETHTRCV_30_AR7000_NO_APPLET_LOCKED                          0xFFu

/* Module operations */
#define ETHTRCV_30_AR7000_MODOP_RD_MEM                              0x00u
#define ETHTRCV_30_AR7000_MODOP_RD_NVM                              0x01u
#define ETHTRCV_30_AR7000_MODOP_STRT_WR                             0x10u
#define ETHTRCV_30_AR7000_MODOP_WR                                  0x11u
#define ETHTRCV_30_AR7000_MODOP_COMMIT                              0x12u
#define ETHTRCV_30_AR7000_MODOP_READ                                0x10u

/* Module operation header lengths */
#define ETHTRCV_30_AR7000_MODOP_RD_HDR_LEN                          18u
#define ETHTRCV_30_AR7000_MODOP_MAX_DATA_SIZE                       1380u

/* Module IDs */
#define ETHTRCV_30_AR7000_MOD_ID_FW                                 0x7001u
#define ETHTRCV_30_AR7000_MOD_ID_PIB                                0x7002u
#define ETHTRCV_30_AR7000_MOD_ID_SL                                 0x7003u
#define ETHTRCV_30_AR7000_MOD_ID_PM                                 0x7005u

/* Module Entry Typex */
#define ETHTRCV_30_AR7000_ENTRY_TYPE_PIB                            0x0000000Fu
#define ETHTRCV_30_AR7000_ENTRY_TYPE_FW                             0x00000004u

/* General MME header fields */
#define ETHTRCV_30_AR7000_MME_MMV                                   0x0000u
#define ETHTRCV_30_AR7000_MME_MMTYPE                                0x0001u
#define ETHTRCV_30_AR7000_MME_MSTATUS                               0x0006u
#define ETHTRCV_30_AR7000_MME_LINKSTATUS                            0x0007u
#define ETHTRCV_30_AR7000_MME_MODULEID                              0x000Au
#define ETHTRCV_30_AR7000_MME_LENGTH                                0x000Cu
#define ETHTRCV_30_AR7000_MME_OFFSET                                0x000Eu
#define ETHTRCV_30_AR7000_MME_DATA                                  0x0016u

/* Host Action Request indication fields of HAR MME */
#define ETHTRCV_30_AR7000_MME_HAREQ_HOST_ACTION_REQ                 0x0006u /*  8 Bit */
#define ETHTRCV_30_AR7000_MME_HAREQ_MAJOR_VERSION                   0x0007u /*  8 Bit */
#define ETHTRCV_30_AR7000_MME_HAREQ_MINOR_VERSION                   0x0008u /*  8 Bit */
#define ETHTRCV_30_AR7000_MME_HAREQ_SESSION_ID                      0x0009u /*  8 Bit */
#define ETHTRCV_30_AR7000_MME_HAREQ_OUTSTANDING_RETRIES             0x000Au /* 16 Bit */
#define ETHTRCV_30_AR7000_MME_HAREQ_RETRY_TIMER_10MS                0x000Cu /* 16 Bit */

/* Host Action Request response fields of HAR MME */
#define ETHTRCV_30_AR7000_MME_HARES_MAJOR_VERSION                   0x0007u /*  8 Bit */
#define ETHTRCV_30_AR7000_MME_HARES_MINOR_VERSION                   0x0008u /*  8 Bit */
#define ETHTRCV_30_AR7000_MME_HARES_HOST_ACTION_REQ                 0x0009u /*  8 Bit */
#define ETHTRCV_30_AR7000_MME_HARES_SESSION_ID                      0x000Au /*  8 Bit */
#define ETHTRCV_30_AR7000_MME_HARES_OUTSTANDING_RETRIES             0x000Bu /* 16 Bit */

/* Status fields of the PBEncryption MME */
#define ETHTRCV_30_AR7000_MME_MS_MSTATUS                            0x0003u
#define ETHTRCV_30_AR7000_MME_MS_AVLNSTATUS                         0x0004u

/* VS fields */
#define ETHTRCV_30_AR7000_MME_VS_MSTATUS                            0x0006u
#define ETHTRCV_30_AR7000_MME_VS_MVERLENGTH                         0x0008u
#define ETHTRCV_30_AR7000_MME_VS_MVERSION                           0x0009u

/* MStatus Return values */
#define ETHTRCV_30_AR7000_MSTATUS_OK                                0x00u

/* Write and Execute Fields, each field has a size of 4 bytes */
#define ETHTRCV_30_AR7000_MME_WAE_STATUS                            0x0000u
#define ETHTRCV_30_AR7000_MME_WAE_CLIENT_SID                        0x0001u
#define ETHTRCV_30_AR7000_MME_WAE_SERVER_SID                        0x0002u
#define ETHTRCV_30_AR7000_MME_WAE_FLAGS                             0x0003u
#define ETHTRCV_30_AR7000_MME_WAE_ALOW_MEM_TYPES                    0x0004u
#define ETHTRCV_30_AR7000_MME_WAE_TOT_LENGTH                        0x0006u
#define ETHTRCV_30_AR7000_MME_WAE_CUR_PART_LENGTH                   0x0007u
#define ETHTRCV_30_AR7000_MME_WAE_CUR_PART_ADDR                     0x0008u
#define ETHTRCV_30_AR7000_MME_WAE_CUR_START_ADDR                    0x0009u
#define ETHTRCV_30_AR7000_MME_WAE_CUR_CHECKSUM                      0x000Au
/* Header Length */
#define ETHTRCV_30_AR7000_MME_WAE_HEADER_LEN                        0x0036u
/* Flags */
#define ETHTRCV_30_AR7000_MME_WAE_FLAG_EXECUTE                      0x00000001u
#define ETHTRCV_30_AR7000_MME_WAE_FLAG_ABS_ADDR                     0x00000002u

/* generic frame header size */
#define ETHTRCV_30_AR7000_MME_GEN_HEADER_SIZE                       5u


/* MMTYPE */
#define ETHTRCV_30_AR7000_MME_REQ                                   0x00u
#define ETHTRCV_30_AR7000_MME_CNF                                   0x01u
#define ETHTRCV_30_AR7000_MME_IND                                   0x02u
#define ETHTRCV_30_AR7000_MME_RSP                                   0x03u

/* Commands */
#define ETHTRCV_30_AR7000_MME_MS_PB_ENC                             0x8000u
#define ETHTRCV_30_AR7000_MME_VS_SW_VER                             0xA000u
#define ETHTRCV_30_AR7000_MME_VS_WR_MEM                             0xA004u
#define ETHTRCV_30_AR7000_MME_VS_RD_MEM                             0xA008u
#define ETHTRCV_30_AR7000_MME_VS_ST_MAC                             0xA00Cu
#define ETHTRCV_30_AR7000_MME_VS_GET_NVM                            0xA010u
#define ETHTRCV_30_AR7000_MME_VS_RS_DEV                             0xA01Cu
#define ETHTRCV_30_AR7000_MME_VS_WR_MOD                             0xA020u
#define ETHTRCV_30_AR7000_MME_VS_RD_MOD                             0xA024u
#define ETHTRCV_30_AR7000_MME_VS_MOD_NVM                            0xA028u
#define ETHTRCV_30_AR7000_MME_VS_WD_RPT                             0xA02Cu
#define ETHTRCV_30_AR7000_MME_VS_LNK_STATS                          0xA030u
#define ETHTRCV_30_AR7000_MME_VS_SNIFFER                            0xA034u
#define ETHTRCV_30_AR7000_MME_VS_NW_INFO                            0xA038u
#define ETHTRCV_30_AR7000_MME_VS_CP_RPT                             0xA040u
#define ETHTRCV_30_AR7000_MME_VS_SET_KEY                            0xA050u
#define ETHTRCV_30_AR7000_MME_VS_MFG_STRING                         0xA054u
#define ETHTRCV_30_AR7000_MME_VS_RD_CBLOCK                          0xA058u
#define ETHTRCV_30_AR7000_MME_VS_SET_SDRAM                          0xA05Cu
#define ETHTRCV_30_AR7000_MME_VS_HST_ACTION                         0xA060u
#define ETHTRCV_30_AR7000_MME_VS_OP_ATTRIBUTES                      0xA068u
#define ETHTRCV_30_AR7000_MME_VS_ENET_SETTINGS                      0xA06Cu
#define ETHTRCV_30_AR7000_MME_VS_TONE_MAP_CHAR                      0xA070u
#define ETHTRCV_30_AR7000_MME_VS_NW_INFO_STATS                      0xA074u
#define ETHTRCV_30_AR7000_MME_VS_FAC_DEFAULTS                       0xA07Cu
#define ETHTRCV_30_AR7000_MME_VS_ERASE_FLASH                        0xA080u
#define ETHTRCV_30_AR7000_MME_VS_CLASSIFICATION                     0xA088u
#define ETHTRCV_30_AR7000_MME_VS_RX_TONE_MAP_CHAR                   0xA090u
#define ETHTRCV_30_AR7000_MME_VS_SET_LED_BEHAVIOR                   0xA094u
#define ETHTRCV_30_AR7000_MME_VS_WRITE_AND_EXECUTE_APPLET           0xA098u
#define ETHTRCV_30_AR7000_MME_VS_MDIO_COMMAND                       0xA09Cu
#define ETHTRCV_30_AR7000_MME_VS_NWK_MITIGATION                     0xA0ACu
#define ETHTRCV_30_AR7000_MME_VS_MODULE_OPERATION                   0xA0B0u
#define ETHTRCV_30_AR7000_MME_VS_DIAG_NETWORK_PROBE                 0xA0B4u
#define ETHTRCV_30_AR7000_MME_VS_PL_LNK_STATUS                      0xA0B8u
#define ETHTRCV_30_AR7000_MME_VS_GPIO_STATE_CHANGE                  0xA0BCu
#define ETHTRCV_30_AR7000_MME_VS_CONN_AD                            0xA0C0u
#define ETHTRCV_30_AR7000_MME_VS_CONN_MOD                           0xA0C4u
#define ETHTRCV_30_AR7000_MME_VS_CONN_REL                           0xA0C8u
#define ETHTRCV_30_AR7000_MME_VS_CONN_INFO                          0xA0CCu
#define ETHTRCV_30_AR7000_MME_VS_MULTIPORT_LNK_STA                  0xA0D0u
#define ETHTRCV_30_AR7000_MME_VS_SET_PROPERTY                       0xA100u

#endif /* ETHTRCV_30_AR7000_TRCV_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_Ar7000_Trcv.h
 *********************************************************************************************************************/

