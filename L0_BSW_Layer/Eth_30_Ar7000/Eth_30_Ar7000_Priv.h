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
/**        \file  Eth_30_Ar7000_Priv.h
 *        \brief  Ethernet driver QCA 7005 private header file
 *
 *      \details  Vector static code private header file for the Ethernet driver QCA 7005 module. This header
 *                file contains module internal declarations.
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

#ifndef ETH_30_AR7000_PRIV_H
#define ETH_30_AR7000_PRIV_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Eth_30_Ar7000_PrivateCfg.h"
#if (ETH_30_AR7000_DEM_ERROR_DETECT == STD_ON)
#include "Dem.h"
#endif /* ETH_30_AR7000_DEM_ERROR_DETECT */
#if (ETH_30_AR7000_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* ETH_30_AR7000_DEV_ERROR_DETECT */
#include "SchM_Eth_30_Ar7000.h"
#include "_Eth_30_Ar7000_Spi.h"

/**********************************************************************************************************************
 *  CONSISTENCY CHECK
 *********************************************************************************************************************/
# if (ETH_30_AR7000_ENABLE_TX_INTERRUPT != ETH_30_AR7000_ENABLE_RX_INTERRUPT)
# error "TX and RX interrupt must be set to the same value, check: /MICROSAR/Eth_Ar7000/Eth/EthConfigSet/EthCtrlConfig/EthCtrlEnable*xInterrupt"
#endif
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* only one instance is supported */
#define ETH_30_AR7000_INSTANCE_ID                                0U
/* only one configuration supported */
#define ETH_30_AR7000_MAX_CFGS_TOTAL                             1U
#define ETH_30_AR7000_RING_IDX                                   0U

/* ETH_30_AR7000 Frame offsets (including offset) */
#define ETH_30_AR7000_RX_SPI_HWLEN_OFFSET_U8                     2U
#define ETH_30_AR7000_RX_SPI_HWLEN_OFFSET_U16                    1U
#define ETH_30_AR7000_RX_SPI_SOF_OFFSET_U8                       2U
#define ETH_30_AR7000_RX_SPI_SOF_OFFSET_U16                      1U
#define ETH_30_AR7000_RX_SPI_LEN_OFFSET_U8                       6U
#define ETH_30_AR7000_RX_SPI_LEN_OFFSET_U16                      3U
#define ETH_30_AR7000_RX_SPI_RSVD_OFFSET_U8                      8U
#define ETH_30_AR7000_RX_SPI_RSVD_OFFSET_U16                     4U
#define ETH_30_AR7000_RX_DST_OFFSET_U8                          10U
#define ETH_30_AR7000_RX_DST_OFFSET_U16                          5U
#define ETH_30_AR7000_RX_SRC_OFFSET_U8                          16U
#define ETH_30_AR7000_RX_SRC_OFFSET_U16                          8U
#define ETH_30_AR7000_RX_TYPE_OFFSET_U8                         22U
#define ETH_30_AR7000_RX_TYPE_OFFSET_U16                        11U
#define ETH_30_AR7000_RX_DATA_OFFSET_U8                         24U
#define ETH_30_AR7000_RX_DATA_OFFSET_U16                        12U
#define ETH_30_AR7000_RX_DATA_OFFSET_U32                         6U

#define ETH_30_AR7000_TX_SPI_SOF_OFFSET_U8                       0U
#define ETH_30_AR7000_TX_SPI_SOF_OFFSET_U16                      0U
#define ETH_30_AR7000_TX_SPI_SOF_OFFSET_U32                      0U
#define ETH_30_AR7000_TX_SPI_LEN_OFFSET_U8                       4U
#define ETH_30_AR7000_TX_SPI_LEN_OFFSET_U16                      2U
#define ETH_30_AR7000_TX_SPI_LEN_OFFSET_U32                      1U
#define ETH_30_AR7000_TX_SPI_RSVD_OFFSET_U8                      6U
#define ETH_30_AR7000_TX_SPI_RSVD_OFFSET_U16                     3U
#define ETH_30_AR7000_TX_DST_OFFSET_U8                           8U
#define ETH_30_AR7000_TX_DST_OFFSET_U16                          4U
#define ETH_30_AR7000_TX_SRC_OFFSET_U8                          14U
#define ETH_30_AR7000_TX_SRC_OFFSET_U16                          7U
#define ETH_30_AR7000_TX_TYPE_OFFSET_U8                         20U
#define ETH_30_AR7000_TX_TYPE_OFFSET_U16                        10U
#define ETH_30_AR7000_TX_DATA_OFFSET_U8                         22U
#define ETH_30_AR7000_TX_DATA_OFFSET_U16                        11U

/* Tx Confirmation */
#define ETH_30_AR7000_TX_STATE_CONFIRMATION_NOT_PENDING       0x00U
#define ETH_30_AR7000_TX_STATE_CONFIRMATION_PENDING           0x01U

#define ETH_30_AR7000_CONFIRMATION_NOT_CALLED                 0x00U
#define ETH_30_AR7000_CONFIRMATION_CALLED                     0x01U

/* Buffer status */
#define ETH_30_AR7000_BUFFER_BUSY                             0x01U
#define ETH_30_AR7000_BUFFER_NOT_BUSY                         0x00U

/* Descriptor status */
#define ETH_30_AR7000_DESCRIPTOR_TRANSMITTED                  0x02U
#define ETH_30_AR7000_DESCRIPTOR_READY                        0x01U
#define ETH_30_AR7000_DESCRIPTOR_NOT_READY                    0x00U

/* Receive status */
#define ETH_30_AR7000_FRAME_RECEIVED                          0x01U
#define ETH_30_AR7000_FRAME_NOT_RECEIVED                      0x00U

/* Transmission status */
#define ETH_30_AR7000_NOTHING_TO_TRANSMIT                     0x00U
#define ETH_30_AR7000_MORE_TO_TRANSMIT                        0x01U

/* State used for current processed SPI flow
   - NA        : Currently no flow is processed
   - REGDATA1  : First register transaction is running
   - REGDATA2  : Second register transaction is running
   - DATA      : Data transaction is running
   - END       : Flow ended
*/
#define ETH_30_AR7000_SPI_FLOW_STATE_NA                          0U
#define ETH_30_AR7000_SPI_FLOW_STATE_REGDATA1                    1U
#define ETH_30_AR7000_SPI_FLOW_STATE_REGDATA2                    2U
#define ETH_30_AR7000_SPI_FLOW_STATE_DATA                        3U
#define ETH_30_AR7000_SPI_FLOW_STATE_END                         4U

/* Flow flags */
#define ETH_30_AR7000_SPI_FLOW_FLAG_USED_MASK                 0x01U
#define ETH_30_AR7000_SPI_FLOW_FLAG_USED_SHIFT                   0U
#define ETH_30_AR7000_SPI_FLOW_FLAG_READ_MASK                 0x02U
#define ETH_30_AR7000_SPI_FLOW_FLAG_READ_SHIFT                   1U
#define ETH_30_AR7000_SPI_FLOW_FLAG_LINKED_MASK               0x04U
#define ETH_30_AR7000_SPI_FLOW_FLAG_LINKED_SHIFT                 2U

/* Flow types */
#define ETH_30_AR7000_SPI_FLOW_TYPE_BUF                          0U
#define ETH_30_AR7000_SPI_FLOW_TYPE_REG                          1U

/* Return types */
#define ETH_30_AR7000_SEND_NEXT_SPI_SEQ_OK                       0U
#define ETH_30_AR7000_SEND_NEXT_SPI_SEQ_END                      1U
#define ETH_30_AR7000_SEND_NEXT_SPI_SEQ_BUSY                     2U
#define ETH_30_AR7000_SEND_NEXT_SPI_SEQ_NOT_OK                   3U
#define ETH_30_AR7000_SEND_NEXT_SPI_SEQ_CONTINUE                 4U

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined(ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0)
#define ETH_30_AR7000_BEGIN_CRITICAL_SECTION_0() SchM_Enter_Eth_30_Ar7000_ETH_30_AR7000_EXCLUSIVE_AREA_0()
#endif
#if !defined(ETH_30_AR7000_END_CRITICAL_SECTION_0)
#define ETH_30_AR7000_END_CRITICAL_SECTION_0()   SchM_Exit_Eth_30_Ar7000_ETH_30_AR7000_EXCLUSIVE_AREA_0()
#endif
/* second exclusive area used to preserver SPI flow order and to protect the retry of writes to the QCA ISR enable register*/
#if !defined(ETH_30_AR7000_BEGIN_CRITICAL_SECTION_1)
#define ETH_30_AR7000_BEGIN_CRITICAL_SECTION_1() SchM_Enter_Eth_30_Ar7000_ETH_30_AR7000_EXCLUSIVE_AREA_1()
#endif
#if !defined(ETH_30_AR7000_END_CRITICAL_SECTION_1)
#define ETH_30_AR7000_END_CRITICAL_SECTION_1()   SchM_Exit_Eth_30_Ar7000_ETH_30_AR7000_EXCLUSIVE_AREA_1()
#endif

#if ((defined ETH_30_AR7000_ENABLE_MAC_ADDR_CBK) && (STD_ON==ETH_30_AR7000_ENABLE_MAC_ADDR_CBK))
# define Eth_30_Ar7000_VCfgGetPhysSrcAddr()                               (ETH_30_AR7000_APPL_CBK_GET_MAC_ADDR())
#else
 #define Eth_30_Ar7000_VCfgGetPhysSrcAddr()                               (Eth_30_Ar7000_VPhysSrcAddr_0)
#endif /* ETH_30_AR7000_ENABLE_MAC_ADDR_CBK */

/* Diagnostic Event Manager */
#if ( ETH_30_AR7000_DEM_ERROR_DETECT == STD_ON )
/* PRQA S 3453 2 */ /* MD_MSR_FctLikeMacro */
#define ETH_30_AR7000_DEM_REPORT_ERROR_STATUS_ETH_30_AR7000_E_ACCESS(CtrlIdx) \
  (Dem_ReportErrorStatus(ETH_30_AR7000_E_ACCESS, DEM_EVENT_STATUS_FAILED))
#else
/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define ETH_30_AR7000_DEM_REPORT_ERROR_STATUS_ETH_30_AR7000_E_ACCESS(CtrlIdx)
#endif /* ETH_30_AR7000_DEM_ERROR_DETECT */

#endif /* ETH_30_AR7000_PRIV_H */

/**********************************************************************************************************************
 *  END OF FILE: Eth_30_Ar7000_priv.h
 *********************************************************************************************************************/
