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
/**        \file  Eth_30_Ar7000_AthEth.h
 *        \brief  Ethernet driver QCA 7005 chip specific header file
 *
 *      \details  Vector static code chip specific header file for the Ethernet driver QCA 7005. This header
 *                file contains module declarations that are specific for the QCA 7005 chip.
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

#ifndef ETH_30_AR7000_ATHETH_H
#define ETH_30_AR7000_ATHETH_H

 /**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Register addresses */
#define ETH_30_AR7000_SPI_REG_BFR_SIZE                   0x0100U
#define ETH_30_AR7000_SPI_REG_WRBUF_SPC_AVA              0x0200U
#define ETH_30_AR7000_SPI_REG_RDBUF_BYTE_AVA             0x0300U
#define ETH_30_AR7000_SPI_REG_CONFIG                     0x0400U
#define ETH_30_AR7000_SPI_REG_STATUS                     0x0500U
#define ETH_30_AR7000_SPI_REG_INTR_CAUSE                 0x0C00U /* Values -> Eth_30_Ar7000_SpiReqIntrCauseFlagsType */
#define ETH_30_AR7000_SPI_REG_INTR_ENABLE                0x0D00U
#define ETH_30_AR7000_SPI_REG_RDBUF_WATERMARK            0x1200U
#define ETH_30_AR7000_SPI_REG_WRBUF_WATERMARK            0x1300U
#define ETH_30_AR7000_SPI_REG_SIGNATURE                  0x1A00U
#define ETH_30_AR7000_SPI_REG_ACT_CTRL                   0x1B00U

/* Interrupt sources: ETH_30_AR7000_SPI_REG_INTR_CAUSE */
typedef uint16 Eth_30_Ar7000_SpiReqIntrCauseFlagsType;
# define ETH_30_AR7000_SPI_INTR_WRBUF_BELOW_WATERMARK    0x0400U
# define ETH_30_AR7000_SPI_INTR_CPU_ON                   0x0040U
# define ETH_30_AR7000_SPI_INTR_LOCAL_CPU_INTERRUPT      0x0010U
# define ETH_30_AR7000_SPI_INTR_ADDRESS_ERROR            0x0008U
# define ETH_30_AR7000_SPI_INTR_WRBUF_ERROR              0x0004U
# define ETH_30_AR7000_SPI_INTR_RDBUF_ERROR              0x0002U
# define ETH_30_AR7000_SPI_INTR_PACKET_AVAILABLE         0x0001U

/* Interrupt enable register values: ETH_30_AR7000_SPI_REG_INTR_ENABLE */
# define ETH_30_AR7000_SPI_INTEN_DISABLE                 0x0000U
# define ETH_30_AR7000_SPI_INTEN_ENABLE                  0x0001U

/* Spi Status Fields */
#define ETH_30_AR7000_SPI_REG_STATUS_RDBUF_ERR           0x0008U
#define ETH_30_AR7000_SPI_REG_STATUS_WRBUF_ERR           0x0010U

/* SPI Config register Fields */
#define ETH_30_AR7000_SPI_IO_ENABLE                      0x0080U
#define ETH_30_AR7000_SPI_IO_DISABLE                     0x0000U
#define ETH_30_AR7000_SPI_SOC_CORE_RESET                 0x0040U

/* ACT_CTRL register fields */
#define ETH_30_AR7000_SPI_REG_ACT_CTRL_INTR_MODE         0x0001U
#define ETH_30_AR7000_SPI_REG_ACT_CTRL_MULTI_CS_EN       0x0002U

/* Register size */
#define ETH_30_AR7000_SPI_REG_SIZE_BYTE                       2U

/* Signature pattern */
#define ETH_30_AR7000_SPI_SIGNATURE_PATTERN              0xAA55U

/* Command word assembly */
#define ETH_30_AR7000_SPI_CMD_WORD_ADDR_LOW_MASK         0x00FFU
#define ETH_30_AR7000_SPI_CMD_WORD_ADDR_LOW_SHIFT             0U
#define ETH_30_AR7000_SPI_CMD_WORD_ADDR_HIGH_MASK        0x3F00U
#define ETH_30_AR7000_SPI_CMD_WORD_ADDR_HIGH_SHIFT            0U
#define ETH_30_AR7000_SPI_CMD_WORD_I_FLAG_MASK             0x40U
#define ETH_30_AR7000_SPI_CMD_WORD_I_FLAG_SHIFT               6U
#define ETH_30_AR7000_SPI_CMD_WORD_R_FLAG_MASK             0x80U
#define ETH_30_AR7000_SPI_CMD_WORD_R_FLAG_SHIFT               7U

#define ETH_30_AR7000_SPI_CMD_WORD_I_FLAG_INTERNAL            1U
#define ETH_30_AR7000_SPI_CMD_WORD_I_FLAG_EXTERNAL            0U
#define ETH_30_AR7000_SPI_CMD_WORD_R_FLAG_READ                1U
#define ETH_30_AR7000_SPI_CMD_WORD_R_FLAG_WRITE               0U

/* SPI frame - Field lengths */
#define ETH_30_AR7000_SPI_OVERALL_FRAME_OVERHEAD             10U
#define ETH_30_AR7000_SPI_HEADER_LENGTH                       8U
#define ETH_30_AR7000_SPI_FOOTER_LENGTH                       2U
#define ETH_30_AR7000_SPI_PADDING_BYTES_LENGTH                2U

#define ETH_30_AR7000_SPI_HWGEN_LENGTH                        4U
#define ETH_30_AR7000_SPI_SOF_LENGTH                          4U
#define ETH_30_AR7000_SPI_FRAME_LENGTH                        2U
#define ETH_30_AR7000_SPI_RSV_FIELD_LENGTH                    2U
#define ETH_30_AR7000_SPI_EOF_LENGTH                          2U

#define ETH_30_AR7000_AND_SPI_OVERALL_FRAME_OVERHEAD_LEN     24U
#define ETH_30_AR7000_FRAME_AND_SPI_HEADER_OVERHEAD_LEN      22U
#define ETH_30_AR7000_MIN_FRAME_SIZE                         70U

#define ETH_30_AR7000_SPI_SOF_U8                           0xAAU
#define ETH_30_AR7000_SPI_SOF_U16                        0xAAAAU
#define ETH_30_AR7000_SPI_SOF_U32                    0xAAAAAAAAU

#define ETH_30_AR7000_SPI_EOF_BYTE                         0x55U

/*************************************f*********************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* ETH_30_AR7000_ATHETH_H */

/**********************************************************************************************************************
 *  END OF FILE: Eth_30_Ar7000_AthEth.h
 *********************************************************************************************************************/
