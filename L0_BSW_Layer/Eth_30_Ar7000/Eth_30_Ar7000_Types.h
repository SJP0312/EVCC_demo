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
/**        \file  Eth_30_Ar7000_Types.h
 *        \brief  Ethernet driver QCA 7005 types header file
 *
 *      \details  Vector static code types header header file for the Ethernet driver QCA 7005 module.
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

#ifndef ETH_30_AR7000_TYPES_H
#define ETH_30_AR7000_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Eth_30_Ar7000_Cfg.h"
#include "Eth_GeneralTypes.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ETH_30_AR7000 Header (field) lenghts */
#define ETH_30_AR7000_FRAME_TYPE_LEN_BYTE                     2U
#define ETH_30_AR7000_HDR_LEN_BYTE                           14U
#define ETH_30_AR7000_FCS_LEN_BYTE                            4U

/* MME frames for multiplexing */
#define ETH_30_AR7000_MME_ETHERNET_FRAME_TYPE            0x88E1U
#define ETH_30_AR7000_MME_TYPE_POS                            1U
#define ETH_30_AR7000_MME_VENDOR_SPECIFIC_RANGE          0x8000U

/* ETH_30_AR7000 Min Payload */
#define ETH_30_AR7000_MIN_PAYLOAD                            46U

/* ETH_30_AR7000 Alignment Padding */
#define ETH_30_AR7000_ALIGN_PADDING                           2U

/* ETH_30_AR7000 Transmit Status */
#define ETH_30_AR7000_TRANSMITTED                             0U
#define ETH_30_AR7000_NOT_TRANSMITTED                         1U
#define ETH_30_AR7000_TRANSMITTED_MORE_SENT                   2U

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
  ETH_30_AR7000_RT_OK      = E_OK,
  ETH_30_AR7000_RT_NOT_OK  = E_NOT_OK,
  ETH_30_AR7000_RT_PENDING = 2U
} Eth_30_Ar7000_ReturnType;

/* ETH_30_AR7000 Config Type */
typedef uint8 Eth_30_Ar7000_ConfigType;

/* ETH_30_AR7000 Notification Function Type */
typedef  P2FUNC(void, ETH_30_AR7000_CODE, Eth_30_Ar7000_EndNotificationFctType)(uint8 CtrlIdx, uint8 FlowId); /* (uint8 CtrlIdx, uint8 FlowId) */

/* ETH_30_AR7000 CPU Mode Type */
typedef uint8 Eth_30_Ar7000_CpuModeType;
/* CPU modes */
#define ETH_30_AR7000_CPU_OFF                                            0x00U
#define ETH_30_AR7000_CPU_ON                                             0x01U

/* ETH_30_AR7000 Out-of-sync Reset Type */
#if ( STD_ON == ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT )
typedef uint8 Eth_30_Ar7000_OsdResetType;
/* Out-of-sync detection modes */
#define ETH_30_AR7000_OSD_HARD_RESET_NECESSARY       (0x00U)
#define ETH_30_AR7000_OSD_SPI_RESET_NECESSARY        (0x01U)
#endif /* ETH_30_AR7000_ENABLE_OUT_OF_SYNC_DETECT */
  
/* ETH_30_AR7000 SPI buffer error Type */
#if ( STD_ON == ETH_30_AR7000_ENABLE_SPI_BUF_ERR_DETECT )
typedef uint8 Eth_30_Ar7000_SpiBufferErrorType;
/* SPI Buffer error types */
#define ETH_30_AR7000_READ_BUFFER_ERROR              (0x01U)
#define ETH_30_AR7000_WRITE_BUFFER_ERROR             (0x02U)
#endif /* ETH_30_AR7000_ENABLE_SPI_BUF_ERR_DETECT */

typedef uint8 Eth_30_Ar7000_SpiAccessReturnType;
#define ETH_30_AR7000_SPI_ACCESS_OK                      (E_OK)
#define ETH_30_AR7000_SPI_ACCESS_NOT_OK                  (E_NOT_OK)
#define ETH_30_AR7000_SPI_ACCESS_ERROR_BUT_SEQ_SCHEDULED (4U)

#endif /* ETH_30_AR7000_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Eth_30_Ar7000_Types.h
 *********************************************************************************************************************/
