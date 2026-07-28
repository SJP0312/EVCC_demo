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
/**        \file  _Eth_30_Ar7000_Spi.h
 *        \brief  Ethernet driver QCA 7005 SPI template header file
 *
 *      \details  Vector template header file for the Ethernet driver QCA 7005 module. This header file contains
 *                a SPI module abstraction that is used by other all files of the module.
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

#ifndef _ETH_30_AR7000_SPI_H
#define _ETH_30_AR7000_SPI_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Eth_30_Ar7000_Cfg.h"
#include "Spi.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */

/* SPI API abstractions */
#define ETH_30_AR7000_SPI_SYNCTRANSMIT(Seq)                  Spi_SyncTransmit(Seq)
#define ETH_30_AR7000_SPI_ASYNCTRANSMIT(Seq)                 Spi_AsyncTransmit(Seq)
#define ETH_30_AR7000_SPI_GETSEQUENCERESULT(Seq)             Spi_GetSequenceResult(Seq)
#define ETH_30_AR7000_SPI_SETUPEB(Chl, TxBuff, RxBuff, Len)  Spi_SetupEB(Chl, TxBuff, RxBuff, Len)
/* Only used for legacy mode */
#define ETH_30_AR7000_SPI_WRITEIB(Chl, DataBufPtr)           Spi_WriteIB(Chl, DataBufPtr)
#define ETH_30_AR7000_SPI_READIB(Chl, DataBufPtr)            Spi_ReadIB(Chl, DataBufPtr)
/* SPI compiler abstraction used for pointer casts, only used for legacy mode */
#define ETH_30_AR7000_SPI_CONST SPI_CONST
#define ETH_30_AR7000_SPI_VAR   SPI_VAR

/* SPI data type used by the Ethernet driver */
#if (((defined SPI_AR_RELEASE_MAJOR_VERSION) && (SPI_AR_RELEASE_MAJOR_VERSION == 4)) && \
      ((defined SPI_AR_RELEASE_MINOR_VERSION) && (SPI_AR_RELEASE_MINOR_VERSION >= 1)))
 /* Is ASR 4.1 or higher */
typedef Spi_DataBufferType Eth_30_Ar7000_SpiDataType;
#else
 /* Is ASR 4.0 */
typedef Spi_DataType Eth_30_Ar7000_SpiDataType;
#endif


/* SPI result type used by the Ethernet driver */
typedef Spi_SeqResultType Eth_30_Ar7000_SpiSeqResultType;
#define ETH_30_AR7000_SPI_SEQ_OK        SPI_SEQ_OK
#define ETH_30_AR7000_SPI_SEQ_FAILED    SPI_SEQ_FAILED
#define ETH_30_AR7000_SPI_SEQ_CANCELLED SPI_SEQ_CANCELLED


/* Setup external buffers */
#define ETH_30_AR7000_SPI_SETUP_EB_CHL_CMD_1(BaseFlow) ETH_30_AR7000_SPI_SETUPEB(                                                \
                                 ETH_30_AR7000_SPI_REF_CHL_CMD_REG_0,                                                            \
                                 (P2VAR(Eth_30_Ar7000_SpiDataType, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT))((BaseFlow)->cmdWord_1), \
                                 (P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA))NULL_PTR,                                        \
                                 2U / sizeof(Eth_30_Ar7000_SpiDataType)                                                          \
                               )

#define ETH_30_AR7000_SPI_SETUP_EB_CHL_REG_1_RX(BaseFlow)  ETH_30_AR7000_SPI_SETUPEB(                                            \
                                 ETH_30_AR7000_SPI_REF_CHL_CMD_REG_1,                                                            \
                                 (P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA))NULL_PTR,                                        \
                                 (P2VAR(Eth_30_Ar7000_SpiDataType, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT))((BaseFlow)->regData_1), \
                                 2U / sizeof(Eth_30_Ar7000_SpiDataType)                                                          \
                               )

#define ETH_30_AR7000_SPI_SETUP_EB_CHL_REG_1_TX(BaseFlow)  ETH_30_AR7000_SPI_SETUPEB(                                            \
                                 ETH_30_AR7000_SPI_REF_CHL_CMD_REG_1,                                                            \
                                 (P2VAR(Eth_30_Ar7000_SpiDataType, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT))((BaseFlow)->regData_1), \
                                 (P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA))NULL_PTR,                                        \
                                 2U / sizeof(Eth_30_Ar7000_SpiDataType)                                                          \
                               )

#define ETH_30_AR7000_SPI_SETUP_EB_CHL_CMD_2(BufFlow)  ETH_30_AR7000_SPI_SETUPEB(                                               \
                                 ETH_30_AR7000_SPI_REF_CHL_CMD_REG_0,                                                           \
                                 (P2VAR(Eth_30_Ar7000_SpiDataType, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT))((BufFlow)->cmdWord_2), \
                                 (P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA))NULL_PTR,                                       \
                                 2U / sizeof(Eth_30_Ar7000_SpiDataType)                                                         \
                               )

#define ETH_30_AR7000_SPI_SETUP_EB_CHL_REG_2(BufFlow)  ETH_30_AR7000_SPI_SETUPEB(                                               \
                                 ETH_30_AR7000_SPI_REF_CHL_CMD_REG_1,                                                           \
                                 (P2VAR(Eth_30_Ar7000_SpiDataType, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT))((BufFlow)->regData_2), \
                                 (P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA))NULL_PTR,                                       \
                                 2U / sizeof(Eth_30_Ar7000_SpiDataType)                                                         \
                               )

#define ETH_30_AR7000_SPI_SETUP_EB_CHL_CMD_3(BufFlow)  ETH_30_AR7000_SPI_SETUPEB(                                               \
                                 ETH_30_AR7000_SPI_REF_CHL_CMD_REG_0,                                                           \
                                 (P2VAR(Eth_30_Ar7000_SpiDataType, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT))((BufFlow)->cmdWord_3), \
                                 (P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA))NULL_PTR,                                       \
                                 2U / sizeof(Eth_30_Ar7000_SpiDataType)                                                         \
                               )

#define ETH_30_AR7000_SPI_SETUP_EB_CHL_DATA_RX(BaseFlow, BufferPtr)  ETH_30_AR7000_SPI_SETUPEB(                                                                                   \
                                 ETH_30_AR7000_SPI_REF_CHL_DATA,                                                                                                                  \
                                 (P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA))NULL_PTR,                                                                                         \
                                 (P2VAR(Eth_30_Ar7000_SpiDataType, AUTOMATIC, AUTOMATIC))(BufferPtr),                                                                             \
                                 (uint16)(((P2VAR(Eth_30_Ar7000_BufAccessSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT))(BaseFlow))->dataSize / sizeof(Eth_30_Ar7000_SpiDataType)) \
                               )

#define ETH_30_AR7000_SPI_SETUP_EB_CHL_DATA_TX(BaseFlow, BufferPtr)  ETH_30_AR7000_SPI_SETUPEB(                                                                                   \
                                 ETH_30_AR7000_SPI_REF_CHL_DATA,                                                                                                                  \
                                 (P2VAR(Eth_30_Ar7000_SpiDataType, AUTOMATIC, AUTOMATIC))(BufferPtr),                                                                             \
                                 (P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA))NULL_PTR,                                                                                         \
                                 (uint16)(((P2VAR(Eth_30_Ar7000_BufAccessSpiFlow, AUTOMATIC, ETH_30_AR7000_VAR_NOINIT))(BaseFlow))->dataSize / sizeof(Eth_30_Ar7000_SpiDataType)) \
                               )
/* PRQA L:L1 */ /* MD_MSR_FctLikeMacro */

#endif /* _ETH_30_AR7000_SPI_H */

/**********************************************************************************************************************
 *  END OF FILE: _Eth_30_Ar7000_Spi.h
 *********************************************************************************************************************/

