/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2007 - 2013 by Vector Informatik GmbH.                                           All rights reserved.
 *
 *                Please note, that this file contains example configuration used by the 
 *                MICROSAR BSW. This code may influence the behaviour of the MICROSAR BSW
 *                in principle. Therefore, great care must be taken to verify
 *                the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples respectively 
 *                implementation proposals. With regard to the fact that these functions
 *                are meant for demonstration purposes only, the liability of Vector Informatik
 *                shall be expressly excluded in cases of ordinary negligence, 
 *                to the extent admissible by law or statute.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  _Compiler_Cfg.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the Compiler_Cfg.h
 *                This file has to be extended with the memory and pointer classes for all BSW modules
 *                which where used.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Joachim Kalmbach              Jk            Vector Informatik GmbH
 *  Heike Honert                  Ht            Vector Informatik GmbH
 *  Eugen Stripling               Seu           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  01.01.00  2007-12-14  Jk                    Component specific defines filtering added
 *  01.01.01  2008-12-17  Ht                    Improve list of components  (Tp_AsrTpCan,Tp_AsrTpFr,DrvMcu,DrvIcu added)
 *  01.01.02  2009-04-27  Ht                    support OEM specific _compiler_cfg.inc file, improve list of components 
 *                                              (Cp_XcpOnCanAsr, Il_AsrIpduM, If_VxFblDcm, If_VxFblVpm_Volvo_ab, DrvFls added)
 *  01.01.03  2009-04-24  Msr                   Renamed J1939_AsrBase as TpJ1939_AsrBase
 *  01.01.04  2009-06-03  Ht                    Improve list of components (Adc, Dio, Gpt, Pwm, Spi, Wdg, Fls, Port, Fim)
 *  01.02.00  2009-08-01  Ht                    Improve list of components (Fee_30_Inst2, Can, ...Sub)
 *                                              Support filtering for RTE
 *  01.02.01  2009-09-02  Lo                    add external Flash driver support
 *  01.02.02  2009-09-21  Lo                    add DrvFls_Mcs12xFslftm01ExtVx
 *                        Ht                    Improve list of components (CanTrcv_30_Tja1040dio,
 *                                                Eth, EthTrcv, EthIf, SoAd, TcpIp, EthSM)
 *  01.03.00  2009-10-30  Ht                    support R8: change EthTrcv to EthTrcv_30_Canoeemu
 *                                              support EthTrcv_30_Dp83848
 *                                              change CanTrcv_30_Xdio to CanTrcv_30___Your_Trcv__
 *                                              change CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1041
 *                                              change name FrTrcv to FrTrcv_30_Tja1080dio
 *                        Lo                    add Cp_AsrXcp
 *                        Ht                    add Cp_XcpOnFrAsr
 *  01.03.01  2010-01-13  Ht                    support SysService_AsrCal
 *  01.03.02  2010-02-15  Ht                   support SysService_SswRcs_Daimler, SysService_Tls, Tp_Http, 
 *                                                      SysService_Dns, SysService_Json, DrvTrans_GenericLindioAsr
 *                        Lo                    add Diag_AsrDem for all OEMs
 *                                              rename internal variables and filter methods
 *  01.04.00  2010-03-04  Ht                    change name FrTrcv_30_Tja1080dio to FrTrcv_30_Tja1080
 *  01.04.01  2010-03-10  Ht                    support DrvTrans_GenericFrAsr, DrvTrans_As8223FrspiAsr, DrvEep and If_AsrIfEa
 *  01.04.02  2010-04-07  Lo                    change IfFee to real components and add If_AsrIfWdV85xNec01Sub
 *  01.04.03  2010-06-11  Ht                    add CanTrcv_30_Tja1043
 *                        Lo                    add Il_AsrIpduMEbBmwSub
 *  01.04.04  2010-08-24  Ht                    add CanTrcv_30_Tle62512G, DrvEep_XAt25128EAsr, Tp_AsrTpFrEbBmwSub
 *  01.05.00  2010-08-24  Ht                    support R10:
 *                                              change LinTrcv_30_Tle7259dio to LinTrcv_30_Tle7259
 *  01.05.01  2010-10-14  Ht                    add VStdLib, SysService_SswScc, SysService_IpBase, SysService_Crypto
 *  01.05.02  2010-10-20  Ht                    support comments for Package Merge Tool
 *  01.05.03  2010-11-03  Ht                    add SysService_E2eLibTttechSub, SysService_E2ePwTttechSub
 *  01.05.04  2010-11-16  Ht                    add SysService_Exi, DrvTrans_Int6400EthAsr, Cdd_AsrCdd_Fiat, Diag_AsrDem_Fiat,
 *  01.05.05  2010-12-17  Ht                    add SysService_AsrSchM, DrvEep_XXStubAsr, DrvIcu_Tms570Tinhet01ExtVx
 *                                                  DrvWd_XTle4278gEAsr, DrvWd_XXStubAsr
 *  01.05.06  2011-02-17  Ht                    add DrvEed, SysService_AsrBswM
 *  01.05.07  2011-03-04  Ht                    add DrvTrans_Tja1055CandioAsr
 *                                              rename CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1040
 *                                              add SysService_XmlEngine
 *  01.06.00  2011-03-04  Ht                    support ASR4.0
 *                                              add Ccl_Asr4ComM, Ccl_Asr4SmCan, Nm_Asr4NmIf, Nm_AsrNmDirOsek
 *  01.06.01  2011-04-15  Ht                    add Diag_AsrDcm_<OEM>
 *  01.06.02  2011-06-17  Ht                    correct Diag_AsrDcm_<OEM>
 *                                              add Monitoring_AsrDlt and Monitoring_GenericMeasurement
 *  01.06.03  2011-09-01  Ht                    add DrvTrans_Tja1145CanSpiAsr, DrvTrans_E52013CanspiAsr, DrvFls_XXStubAsr,
 *                                              If_AsrIfFeeV85xNec05Sub, If_AsrIfFeeV85xNec06Sub, If_AsrIfFeeV85xNec07Sub
 *                                              SysService_AsrWdMTttechSub and If_AsrIfWdTttechSub
 *  01.06.04  2011-10-20  Ht                    ESCAN00054334: add If_AsrIfFeeTiSub
 *                                              ESCAN00054719: add Cdd_AsrCdd
 *  01.06.05  2011-12-09  Ht                    add Tp_IpV4, Tp_IpV6
 *  01.06.06  2011-12-14  Ht                    add Monitoring_RuntimeMeasurement
 *  01.06.07  2012-01-03  Ht                    add DrvI2c, SysService_Asr4BswM
 *  01.06.08  2012-01-31  Ht                    add DrvTrans_Ar7000EthAsr, DrvTrans_GenericEthmiiAsr
 *  01.06.09  2012-03-06  Ht                    add If_AsrIfFeeMb9df126Fuji01Sub, 
 *                                              Infineon_Tc1767Inf01Sub, Infineon_Tc178xInf01Sub, Infineon_Tc1797Inf01Sub, Infineon_Tc1797Inf02Sub
 *  01.06.10  2012-03-13  Ht                    add Gw_AsrPduRCfg5, Il_AsrComCfg5, Il_AsrIpduMCfg5, Cdd_AsrCddCfg5,
 *                                              Tp_Asr4TpCan, Diag_Asr4Dcm, Diag_Asr4Dem
 *  01.06.11  2012-03-20  Ht                    add Cp_AsrCcp, Cp_XcpOnTcpIpAsr
 *  01.07.00  2012-07-26  Ht                    add Nm_Asr4NmCan, Nm_Asr4NmFr, Infineon_Xc2000Inf01Sub, Ccl_Asr4ComMCfg5, SysService_Asr4BswMCfg5, SysService_Asr4EcuM, SysService_AsrRamTst,
 *                                                  Ccl_Asr4SmLin
 *                                              add define REGSPACE - add support for ASR specification 4.0 R3
 *  01.07.01  2012-10-23  Seu                   add SysService_XmlSecurity
 *  01.07.02  2013-12-16  Seu                   MISRA compliance: usage of character "'" removed, typos corrected
 *********************************************************************************************************************/
#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
/* Package Merger: Start Section CompilerCfgIncludes */



/* Package Merger: Stop Section CompilerCfgIncludes */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define AUTOSAR_COMSTACKDATA

#define MSR_REGSPACE  REGSPACE

/* Configurable memory class for pointers to registers (e.g. static volatile CONSTP2VAR(uint16, PWM_CONST, REGSPACE)). */
#define REGSPACE


/* due to compatibility to ASR 2.1 */
#define _STATIC_   STATIC
#define _INLINE_   INLINE

/* Package Merger: Start Section CompilerCfgModuleList */


/**********************************************************************************************************************
 *  ETHSM START 
 *********************************************************************************************************************/

#define ETHSM_CODE

#define ETHSM_CONST
#define ETHSM_PBCFG

#define ETHSM_VAR_NO_INIT
#define ETHSM_VAR_CLEARED

#define ETHSM_APPL_DATA
/**********************************************************************************************************************
 *  ETHSM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CRYPTO_30_LIBCV START
 *********************************************************************************************************************/

#define CRYPTO_30_LIBCV_CODE
#define CRYPTO_30_LIBCV_APPL_CODE

#define CRYPTO_30_LIBCV_CONST

#define CRYPTO_30_LIBCV_VAR_NOINIT
#define CRYPTO_30_LIBCV_VAR_ZERO_INIT
#define CRYPTO_30_LIBCV_APPL_VAR
#define CRYPTO_30_LIBCV_APPL_DATA

#define CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR

/**********************************************************************************************************************
 *  CRYPTO_30_LIBCV END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  ETH_30_AR7000 START 
 *********************************************************************************************************************/
 
#define ETH_30_AR7000_CODE
#define ETH_30_AR7000_CODE_ISR

#define ETH_30_AR7000_CONST
#define ETH_30_AR7000_APPL_CONST
#define ETH_30_AR7000_APPL_VAR
#define ETH_30_AR7000_APPL_DATA

#define ETH_30_AR7000_VAR_NOINIT
#define ETH_30_AR7000_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  ETH_30_AR7000 END 
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETH_30_WRAPPER START 
 *********************************************************************************************************************/


#define ETH_30_WRAPPER_CODE
#define ETH_30_WRAPPER_CODE_ISR
#define ETH_30_WRAPPER_CONST
#define ETH_30_WRAPPER_PBCFG
#define ETH_30_WRAPPER_VAR_NO_INIT
#define ETH_30_WRAPPER_VAR_CLEARED
#define ETH_30_WRAPPER_VAR_PBCFG
#define ETH_30_WRAPPER_APPL_VAR
#define ETH_30_WRAPPER_APPL_DATA
#define ETH_30_WRAPPER_APPL_CONST
#define ETH_30_WRAPPER_NVM_DATA

/**********************************************************************************************************************
 *  ETH_30_WRAPPER END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_AR7000 START 
 *********************************************************************************************************************/

#define ETHTRCV_30_AR7000_CODE

#define ETHTRCV_30_AR7000_CONST

#define ETHTRCV_30_AR7000_APPL_CONST
#define ETHTRCV_30_AR7000_APPL_DATA
#define ETHTRCV_30_AR7000_APPL_VAR

#define ETHTRCV_30_AR7000_VAR_NOINIT
#define ETHTRCV_30_AR7000_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  ETHTRCV_30_AR7000 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CRYIF START
 *********************************************************************************************************************/

#define CRYIF_CODE
#define CRYIF_CONST

#define CRYIF_VAR_ZERO_INIT
#define CRYIF_APPL_VAR
#define CRYIF_APPL_DATA

/**********************************************************************************************************************
 *  CRYIF END
 *********************************************************************************************************************/



/***********************************************************************************************************************
 *  ETHIF START
 **********************************************************************************************************************/

#define ETHIF_CODE
#define ETHIF_CODE_ISR
#define ETHIF_ETHCTRL_INLINE_CODE
#define ETHIF_ETHTRCV_INLINE_CODE
#define ETHIF_ETHSWT_INLINE_CODE
#define ETHIF_GW_INLINE_CODE
#define ETHIF_LINK_INLINE_CODE
#define ETHIF_MACSEC_INLINE_CODE
#define ETHIF_MIRROR_INLINE_CODE
#define ETHIF_MODE_INLINE_CODE
#define ETHIF_RX_INLINE_CODE
#define ETHIF_STATS_INLINE_CODE
#define ETHIF_TX_INLINE_CODE
#define ETHIF_UTILS_INLINE_CODE
#define ETHIF_ZEROCOPY_INLINE_CODE

#define ETHIF_CONST

#define ETHIF_APPL_VAR
#define ETHIF_APPL_DATA
#define ETHIF_APPL_CODE

#define ETHIF_VAR_NO_INIT
#define ETHIF_VAR_NO_INIT_FAST

#define ETHIF_VAR_INIT

/***********************************************************************************************************************
 *  ETHIF END
 **********************************************************************************************************************/



/* Added define to avoid Test include errors */
#define APP_SW 3

/**********************************************************************************************************************
 *  ADC START
 *********************************************************************************************************************/

#define ADC_CODE
#define ADC_VAR_NOINIT
#define ADC_VAR_POWER_ON_INIT
#define ADC_VAR_FAST
#define ADC_VAR
#define ADC_CONST
#define ADC_APPL_DATA
#define ADC_APPL_CONST
#define ADC_APPL_CODE
#define ADC_CALLOUT_CODE

/**********************************************************************************************************************
 *  ADC END
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  CRC START
 *********************************************************************************************************************/

#define CRC_CODE
#define CRC_VAR_NOINIT
#define CRC_VAR_POWER_ON_INIT
#define CRC_VAR_FAST
#define CRC_VAR
#define CRC_CONST
#define CRC_APPL_DATA
#define CRC_APPL_CONST
#define CRC_APPL_CODE
#define CRC_CALLOUT_CODE

/**********************************************************************************************************************
 *  ADC END
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  DIO START
 *********************************************************************************************************************/

#define DIO_CODE
#define DIO_VAR_NOINIT
#define DIO_VAR_POWER_ON_INIT
#define DIO_VAR_FAST
#define DIO_VAR
#define DIO_CONST
#define DIO_APPL_DATA
#define DIO_APPL_CONST
#define DIO_APPL_CODE
#define DIO_CALLOUT_CODE

/**********************************************************************************************************************
 *  DIO END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  DMA START
 *********************************************************************************************************************/

#define DMA_CODE
#define DMA_VAR_NOINIT
#define DMA_VAR_POWER_ON_INIT
#define DMA_VAR_FAST
#define DMA_VAR
#define DMA_CONST
#define DMA_APPL_DATA
#define DMA_APPL_CONST
#define DMA_APPL_CODE
#define DMA_CALLOUT_CODE
#define DMA_PBCFG

/**********************************************************************************************************************
 *  DMA END
 *********************************************************************************************************************/
 
  /**********************************************************************************************************************
 *  DSADC START
 *********************************************************************************************************************/

#define DSADC_CODE
#define DSADC_VAR_NOINIT
#define DSADC_VAR_POWER_ON_INIT
#define DSADC_VAR_FAST
#define DSADC_VAR
#define DSADC_CONST
#define DSADC_APPL_DATA
#define DSADC_APPL_CONST
#define DSADC_APPL_CODE
#define DSADC_CALLOUT_CODE
#define DSADC_PBCFG

  /**********************************************************************************************************************
 *  DSADC SEND
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  FEE START
 *********************************************************************************************************************/

#define FEE_CODE
#define FEE_VAR_NOINIT
#define FEE_VAR_POWER_ON_INIT
#define FEE_VAR_FAST
#define FEE_VAR
#define FEE_CONST
#define FEE_APPL_DATA
#define FEE_APPL_CONST
#define FEE_APPL_CODE
#define FEE_CALLOUT_CODE
#define FEE_PBCFG
 
/**********************************************************************************************************************
 *  FEE END
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  FLS START
 *********************************************************************************************************************/

#define FLS_CODE
#define FLS_VAR_NOINIT
#define FLS_VAR_POWER_ON_INIT
#define FLS_VAR_FAST
#define FLS_VAR
#define FLS_CONST
#define FLS_APPL_DATA
#define FLS_APPL_CONST
#define FLS_APPL_CODE
#define FLS_CALLOUT_CODE
#define FLS_17_DMU_CODE

/**********************************************************************************************************************
 *  FLS END
 *********************************************************************************************************************/

   /**********************************************************************************************************************
 *  FLSLOADER START
 *********************************************************************************************************************/

#define FLSLOADER_CODE
#define FLSLOADER_VAR_NOINIT
#define FLSLOADER_VAR_POWER_ON_INIT
#define FLSLOADER_VAR_FAST
#define FLSLOADER_VAR
#define FLSLOADER_CONST
#define FLSLOADER_APPL_DATA
#define FLSLOADER_APPL_CONST
#define FLSLOADER_APPL_CODE
#define FLSLOADER_CALLOUT_CODE

/**********************************************************************************************************************
 *  FLSLOADER END
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  GPT START
 *********************************************************************************************************************/

#define GPT_CODE
#define GPT_VAR_NOINIT
#define GPT_VAR_POWER_ON_INIT
#define GPT_VAR_FAST
#define GPT_VAR
#define GPT_CONST
#define GPT_APPL_DATA
#define GPT_APPL_CONST
#define GPT_APPL_CODE
#define GPT_CALLOUT_CODE

/**********************************************************************************************************************
 *  GPT END
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  ICU START
 *********************************************************************************************************************/

#define ICU_CODE
#define ICU_VAR_NOINIT
#define ICU_VAR_POWER_ON_INIT
#define ICU_VAR_FAST
#define ICU_VAR
#define ICU_CONST
#define ICU_APPL_DATA
#define ICU_APPL_CONST
#define ICU_APPL_CODE
#define ICU_CALLOUT_CODE

/**********************************************************************************************************************
 *  ICU END
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  IRQ START
 *********************************************************************************************************************/

#define IRQ_CODE
#define IRQ_VAR_NOINIT
#define IRQ_VAR_POWER_ON_INIT
#define IRQ_VAR_FAST
#define IRQ_VAR
#define IRQ_CONST
#define IRQ_APPL_DATA
#define IRQ_APPL_CONST
#define IRQ_APPL_CODE
#define IRQ_CALLOUT_CODE

/**********************************************************************************************************************
 *  IRQ END
 *********************************************************************************************************************/
 
  /**********************************************************************************************************************
 *  MCALLIB START
 *********************************************************************************************************************/
#define MCALLIB_APPL_CODE
#define MCALLIB_APPL_CONST
#define MCALLIB_APPL_DATA
#define MCALLIB_CALLOUT_CODE
#define MCALLIB_CODE
#define MCALLIB_CONST
#define MCALLIB_VAR
#define MCALLIB_VAR_FAST
#define MCALLIB_VAR_NOINIT
#define MCALLIB_VAR_POWER_ON_INIT

/**********************************************************************************************************************
 *  MCALLIB END
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  MCU START
 *********************************************************************************************************************/

#define MCU_CODE
#define MCU_VAR_NOINIT
#define MCU_VAR_POWER_ON_INIT
#define MCU_VAR_FAST
#define MCU_VAR
#define MCU_CONST
#define MCU_APPL_DATA
#define MCU_APPL_CONST
#define MCU_APPL_CODE
#define MCU_CALLOUT_CODE

#define GPTA_CODE
#define GPTA_VAR_NOINIT
#define GPTA_VAR_POWER_ON_INIT
#define GPTA_VAR_FAST
#define GPTA_VAR
#define GPTA_CONST
#define GPTA_APPL_DATA
#define GPTA_APPL_CONST
#define GPTA_APPL_CODE
#define GPTA_CALLOUT_CODE

/**********************************************************************************************************************
 *  MCU END
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  OCU START
 *********************************************************************************************************************/

#define OCU_CODE
#define OCU_VAR_NOINIT
#define OCU_VAR_POWER_ON_INIT
#define OCU_VAR_FAST
#define OCU_VAR
#define OCU_CONST
#define OCU_APPL_DATA
#define OCU_APPL_CONST
#define OCU_APPL_CODE
#define OCU_CALLOUT_CODE

/**********************************************************************************************************************
 *  OCU END
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  PORT START
 *********************************************************************************************************************/

#define PORT_CODE
#define PORT_VAR_NOINIT
#define PORT_VAR_POWER_ON_INIT
#define PORT_VAR_FAST
#define PORT_VAR
#define PORT_CONST
#define PORT_APPL_DATA
#define PORT_APPL_CONST
#define PORT_APPL_CODE
#define PORT_CALLOUT_CODE

/**********************************************************************************************************************
 *  PORT END
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  PWM START
 *********************************************************************************************************************/

#define PWM_CODE
#define PWM_VAR_NOINIT
#define PWM_VAR_POWER_ON_INIT
#define PWM_VAR_FAST
#define PWM_VAR
#define PWM_CONST
#define PWM_APPL_DATA
#define PWM_APPL_CONST
#define PWM_APPL_CODE
#define PWM_CALLOUT_CODE

/**********************************************************************************************************************
 *  PWM END
 *********************************************************************************************************************/

   /**********************************************************************************************************************
 *  SMU START
 *********************************************************************************************************************/

#define SMU_CODE
#define SMU_VAR_NOINIT
#define SMU_VAR_POWER_ON_INIT
#define SMU_VAR_FAST
#define SMU_VAR
#define SMU_CONST
#define SMU_APPL_DATA
#define SMU_APPL_CONST
#define SMU_APPL_CODE
#define SMU_CALLOUT_CODE

/**********************************************************************************************************************
 *  SMU END
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  SPI START
 *********************************************************************************************************************/

#define SPI_CODE
#define SPI_VAR_NOINIT
#define SPI_VAR_POWER_ON_INIT
#define SPI_VAR_FAST
#define SPI_VAR
#define SPI_CONST
#define SPI_APPL_DATA
#define SPI_APPL_CONST
#define SPI_APPL_CODE
#define SPI_CALLOUT_CODE

/**********************************************************************************************************************
 *  SPI END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  UART START
 *********************************************************************************************************************/

#define UART_CODE
#define UART_VAR_NOINIT
#define UART_VAR_POWER_ON_INIT
#define UART_VAR_FAST
#define UART_VAR
#define UART_CONST
#define UART_APPL_DATA
#define UART_APPL_CONST
#define UART_APPL_CODE
#define UART_CALLOUT_CODE

/**********************************************************************************************************************
 *  UART END
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  WDG START
 *********************************************************************************************************************/

#define WDG_CODE
#define WDG_VAR_NOINIT
#define WDG_VAR_POWER_ON_INIT
#define WDG_VAR_FAST
#define WDG_VAR
#define WDG_CONST
#define WDG_APPL_DATA
#define WDG_APPL_CONST
#define WDG_APPL_CODE
#define WDG_CALLOUT_CODE

/**********************************************************************************************************************
 *  WDG END
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  OS START
 *********************************************************************************************************************/

#define OS_CODE                         /* Regular OS code. */
#define OS_CODE_FAST                    /* Time critical OS code. (currently not used) */
#define OS_CODE_SLOW                    /* Not time critical OS code. (currently not used) */
#define OS_CODE_ISR                     /* OS ISRs. (currently not used) */

#define OS_PANICHOOK_CODE               /* Panic Hook */
#define OS_PRETASKHOOK_CODE             /* PreTask Hook */
#define OS_POSTTASKHOOK_CODE            /* PostTask Hook */
#define OS_STARTUPHOOK_CODE             /* Startup Hook */
#define OS_ERRORHOOK_CODE               /* Error Hook */
#define OS_PROTECTIONHOOK_CODE          /* Protection Hook */
#define OS_SHUTDOWNHOOK_CODE            /* Shutdown Hook */

#define OS_CONST                        /* Constant data. */
#define OS_CONST_FAST                   /* Constant data with fast access. (currently not used) */

#define OS_VAR_INIT                     /* Initialized dynamic data. (Not used by the OS) */
#define OS_VAR_NOINIT                   /* Not initialized dynamic data. */
#define OS_VAR_ZERO_INIT                /* Zero initialized dynamic data. */
#define OS_VAR_INIT_FAST                /* Initialized dynamic data with fast access. (Not used by the OS) */
#define OS_VAR_NOINIT_FAST              /* Not initialized dynamic data with fast access. */
#define OS_VAR_ZERO_INIT_FAST           /* Zero initialized dynamic data with fast access. */

#define OS_VAR_INIT_NOCACHE             /* Initialized dynamic data not cached. (Not used by the OS) */
#define OS_VAR_NOINIT_NOCACHE           /* Not initialized dynamic data not cached. */
#define OS_VAR_ZERO_INIT_NOCACHE        /* Zero initialized dynamic data not cached. */

#define OS_APPL_VAR                     /* Dynamic data from user space (always in RAM). */
#define OS_APPL_DATA                    /* Data from user space (maybe in RAM or ROM). */


// #include "Os_Compiler_Cfg.h"

/**********************************************************************************************************************
 *  OS END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CSM START
 *********************************************************************************************************************/

#define CSM_CODE
#define CSM_APPL_CODE
#define CSM_RTE_CODE

#define CSM_CONST

#define CSM_VAR_NOINIT
#define CSM_VAR_ZERO_INIT
#define CSM_APPL_VAR
#define CSM_APPL_CONST

/**********************************************************************************************************************
 *  CSM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  KEYM START
 *********************************************************************************************************************/

#define KEYM_CODE
#define KEYM_APPL_CODE
#define KEYM_RTE_CODE

#define KEYM_CONST
#define KEYM_PBCFG

#define KEYM_VAR_INIT
#define KEYM_VAR_NO_INIT
#define KEYM_VAR_ZERO_INIT
#define KEYM_APPL_VAR
#define KEYM_APPL_DATA

/**********************************************************************************************************************
 *  KEYM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VSECPRIM START
 *********************************************************************************************************************/

#define VSECPRIM_CODE
#define VSECPRIM_CONST
#define VSECPRIM_APPL_CONST
#define VSECPRIM_APPL_VAR
#define VSECPRIM_APPL_DATA

/**********************************************************************************************************************
 *  VSECPRIM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  EXI START
 *********************************************************************************************************************/

#define EXI_CODE

#define EXI_CONST

#define EXI_APPL_DATA
#define EXI_APPL_VAR

/**********************************************************************************************************************
 *  EXI END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  IPBASE START
 *********************************************************************************************************************/

#define IPBASE_CODE
#define IPBASE_CONST
#define IPBASE_APPL_DATA
#define IPBASE_VAR_NOINIT

/**********************************************************************************************************************
 *  IPBASE END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  SLAC START 
 *********************************************************************************************************************/

#define SLAC_CODE
#define SLAC_CODE_FAST
#define SLAC_CODE_ISR

#define SLAC_CONST
#define SLAC_CONST_FAST
#define SLAC_PBCFG
#define SLAC_VAR_PBCFG

#define SLAC_VAR_INIT
#define SLAC_VAR_NOINIT
#define SLAC_VAR_ZERO_INIT

#define SLAC_VAR_INIT_FAST
#define SLAC_VAR_NOINIT_FAST
#define SLAC_VAR_ZERO_INIT_FAST

#define SLAC_VAR_INIT_NOCACHE
#define SLAC_VAR_NOINIT_NOCACHE
#define SLAC_VAR_ZERO_INIT_NOCACHE

#define SLAC_APPL_DATA
#define SLAC_APPL_VAR

/**********************************************************************************************************************
 *  SLAC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SCC START
 *********************************************************************************************************************/

#define SCC_CODE
#define SCC_STATIC_CODE
#define SCC_RTE_CODE

#define SCC_CONST

#define SCC_APPL_DATA
#define SCC_RTE_DATA

#define SCC_VAR_INIT
#define SCC_VAR_NOINIT
#define SCC_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  SCC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  XMLSECURITY START
 *********************************************************************************************************************/

#define XMLSECURITY_CODE
#define XMLSECURITY_CBK_CODE

#define XMLSECURITY_CONST

#define XMLSECURITY_VAR_NOINIT
#define XMLSECURITY_VAR_ZERO_INIT

#define XMLSECURITY_APPL_DATA
#define XMLSECURITY_APPL_VAR

/**********************************************************************************************************************
 *  XMLSECURITY END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  TCPIP START
 *********************************************************************************************************************/

#define TCPIP_CODE
#define TCPIP_CODE_ISR

#define TCPIP_CONST
#define TCPIP_PBCFG

#define TCPIP_APPL_CODE
#define TCPIP_APPL_CONST
#define TCPIP_APPL_DATA
#define TCPIP_APPL_VAR

#define TCPIP_VAR_INIT
#define TCPIP_VAR_CLEARED
#define TCPIP_VAR_NO_INIT

/**********************************************************************************************************************
 *  TCPIP END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  VSTDLIB START
 *********************************************************************************************************************/

#define VSTDLIB_CODE
#define VSTDLIB_VAR_FAR
#define VSTDLIB_APPL_VAR
#define VSTDLIB_CONST

/**********************************************************************************************************************
 *  VSTDLIB END
 *********************************************************************************************************************/




#define _HITECH_C_S32K1XX_

#define _HITECH_C_S32K2XX_

#define _HITECH_C_S32S2XX_

#define _GNU_C_TRICORE_ 1

#define _HITECH_C_MPC564XC_
#define _HITECH_C_MPC56XXK_
#define _HITECH_C_MPC560XB_
#define _HITECH_C_XPC56XXL_

#define _HITECH_C_SPC560XB_
#define _HITECH_C_SPC56XXL_
#define _HITECH_C_SPC56XXP_

#define _HITECH_C_SPC574SX_
#define _HITECH_C_SPC570SX_
#define _HITECH_C_SPC574KX_

#define _HITECH_C_SPC58XH_
#define _HITECH_C_SPC58XBCGH_ 1
#define _HITECH_C_SPC58XBCG_
#define _HITECH_C_SPC58XEN_
#define _HITECH_C_SPC582B_

#define _HITECH_C_SR6G7_
#define _HITECH_C_SR6P6_
#define _HITECH_C_SR6PX_

#define _HITECH_C_SR5E1_

#define _HITECH_C_ALIOTHXX_



/* Package Merger: Stop Section CompilerCfgModuleList */

/**********************************************************************************************************************
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


#endif  /* COMPILER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Compiler_Cfg.h
 *********************************************************************************************************************/
