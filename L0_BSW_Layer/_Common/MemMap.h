/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
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
 *         File:  _MemMap.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the MemMap.h
 *                This file has to be extended with the memory section defined for all BSW modules
 *                which are used.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  01.01.00  2007-12-14  Jk                    Component specific defines filtering added
 *  01.01.02  2008-11-04  Jk                    Component specific defines filtering added
 *  01.01.03  2008-12-17  Ht                    Improve list of components  (Tp_AsrTpCan,Tp_AsrTpFr,DrvMcu,DrvIcu added)
 *  01.01.04  2009-04-27  Ht                    improve list of components  (Cp_XcpOnCanAsr, Il_AsrIpduM, If_VxFblDcm,
 *                                              If_VxFblVpm_Volvo_ab, DrvFls added)
 *  01.01.05  2009-04-24  Msr                   Renamed J1939_AsrBase as TpJ1939_AsrBase
 *  01.01.06  2009-06-03  Ht                    Improve list of components (Adc, Dio, Gpt, Pwm, Spi, Wdg, Fls, Port, Fim)
 *  01.02.00  2009-08-01  Ht                    Improve list of components (Fee_30_Inst2, Can, ...Sub)
 *                                              Support filtering for RTE
 *  01.02.01  2009-08-18  HH                    replaced C++ comment by C comment
 *  01.02.02  2009-09-02  Lo                    add external Flash driver support
 *  01.02.03  2009-09-12  Lo                    add DrvFls_Mcs12xFslftm01ExtVx
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
 *  01.03.02  2010-02-15  Ht                    support SysService_SswRcs_Daimler, SysService_Tls, Tp_Http,
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
 *  01.05.04  2010-11-16  Ht                    add SysService_Exi, DrvTrans_Int6400EthAsr, Cdd_AsrCdd_Fiat, Diag_AsrDem_Fiat
 *  01.05.05  2010-12-17  Ht                    add SysService_AsrSchM, DrvEep_XXStubAsr, DrvIcu_Tms570Tinhet01ExtVx
 *                                                  DrvWd_XTle4278gEAsr, DrvWd_XXStubAsr
 *  01.05.06  2011-02-17  Ht                    add DrvEed, SysService_AsrBswM
 *  01.05.07  2011-03-04  Ht                    add DrvTrans_Tja1055CandioAsr
 *                                              rename CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1040
 *                                              add SysService_XmlEngine
 *  01.06.00  2011-03-15  Ht                    support ASR4.0
 *                                              add Ccl_Asr4ComM, Ccl_Asr4SmCan, Nm_Asr4NmIf, Nm_AsrNmDirOsek
 *  01.06.01  2011-04-15  Ht                    add Diag_AsrDcm_<OEM>
 *  01.06.02  2011-06-17  Ht                    correct Diag_AsrDcm_<OEM>
 *                                              add Monitoring_AsrDlt and Monitoring_GenericMeasurement
 *  01.06.03  2011-09-20  Ht                    add DrvTrans_Tja1145CanSpiAsr, DrvTrans_E52013CanspiAsr, DrvFls_XXStubAsr,
 *                                              If_AsrIfFeeV85xNec05Sub, If_AsrIfFeeV85xNec06Sub, If_AsrIfFeeV85xNec07Sub
 *                                              SysService_AsrWdMTttechSub and If_AsrIfWdTttechSub
 *  01.06.04  2011-11-22  Ht                    add If_AsrIfFeeTiSub,
 *                                              ESCAN00054718: add Cdd_AsrCdd
 *  01.06.05  2011-12-09  Ht                    add Tp_IpV4, Tp_IpV6
 *  01.06.06  2011-12-14  Ht                    add Monitoring_RuntimeMeasurement
 *  01.06.07  2012-01-03  Ht                    add DrvI2c, SysService_Asr4BswM
 *  01.06.08  2012-01-31  Ht                    add DrvTrans_Ar7000EthAsr, DrvTrans_GenericEthmiiAsr
 *  01.06.09  2012-03-06  Ht                    add If_AsrIfFeeMb9df126Fuji01Sub,
 *                                              Infineon_Tc1767Inf01Sub, Infineon_Tc178xInf01Sub, Infineon_Tc1797Inf01Sub, Infineon_Tc1797Inf02Sub
 *  01.06.10  2012-03-13  Ht                    add Gw_AsrPduRCfg5, Il_AsrComCfg5, Il_AsrIpduMCfg5, Cdd_AsrCddCfg5,
 *                                              Tp_Asr4TpCan, Diag_Asr4Dcm, Diag_Asr4Dem
 *  01.06.11  2012-03-20  Ht                    add Cp_AsrCcp, Cp_XcpOnTcpIpAsr
 *  01.07.00  2012-07-26  Ht                    ESCAN00059365: [AUTOSAR4, compiler warning]: Wrong define name in #undef statement causes re-definition warning
 *                                              add Nm_Asr4NmCan, Nm_Asr4NmFr, Infineon_Xc2000Inf01Sub, Ccl_Asr4ComMCfg5, SysService_Asr4BswMCfg5, SysService_Asr4EcuM, SysService_AsrRamTst,
 *                                                  Ccl_Asr4SmLin
 *            2012-09-04  Ht                    add support for ASR specification 4.0 R3
 *  01.07.01  2012-10-23  Seu                   add SysService_XmlSecurity
 *  01.07.02  2013-01-10  Seu                   MISRA deviation comments added
 *  01.08.00  2013-03-01  Seu    ESCAN00065501  AR4-325: Add support for Post-build RAM memory section
 *            2013-04-12  Seu    ESCAN00066614  Add the deviation for violation of MISRA rule 19.6
 *  01.09.00  2013-12-10  Seu    ESCAN00072537  Add *_NOCACHE_* memory sections for variables
 *            2013-12-16  Seu                   MISRA compliance: usage of character "'" removed, typos corrected
 *  01.10.00  2016-09-27  Seu                   FEATC-317: FEAT-2002: CommonAsr__Common: Support 64 Bit Signal Types for COM according to ASR 4.2.2
 *  01.11.00  2017-07-05  Seu    ESCAN00095756  FEAT-2455: Support ASR4.2 compatible MemMap for MCALs
 *            2017-08-01  Seu    ESCAN00096129  MEMMAP_SW_MINOR_VERSION / MEM_SW_MINOR_VERSION is not correct
 *  01.12.00  2018-10-17  visdfe ESCAN00095695  Add support for Os_CoreGen7 within _MemMap.h (Include of Os_MemMap.h)
 *                               TASK-78775     Change MemMap_Common.h to Template
 *  01.13.00  2021-05-06  virmfr HALBE-3985     CommonAsr_MemMap shall include Common_MemMap generated compatibility header
 *  02.00.00  2021-06-09  visto  HALBE-4594     Create a branch for >=R27 Features
 *  02.01.00  2021-08-25  virmfr HALBE-4526     MemMap_Common.h removed
 *  02.01.01  2021-09-07  virmfr HALBE-5304     MemMapIncludesList removed
 *  02.02.00  2022-08-18  virmfr HALBE-7504     Interchange include order of MemMap_Common.h and MemMap_Compatibility.h
 *            2022-08-18  virmfr                ASR3 defines removed
 *  02.02.01  2022-08-26  virmfr                Correction of small non-functional findings
 *********************************************************************************************************************/

/* PRQA S 0841 MEMMAP_0841_TAG */ /* MD_MSR_19.6 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#ifdef MICROSAR_DISABLE_MEMMAP

# include "MemMap_NoOp.h"

#else

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

 /* PRQA S 0883 1 */ /* MD_MemMap_19.15 */
#undef MEMMAP_VENDOR_ID /* PRQA S 0841 */ /* MD_MSR_19.6 */

#define MEMMAP_VENDOR_ID        (30u)

/* AUTOSAR Software Specification Version Information */

# undef MEMMAP_AR_RELEASE_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_AR_RELEASE_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_AR_RELEASE_REVISION_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

/* AUTOSAR release 4.0 R3 */
# define MEMMAP_AR_RELEASE_MAJOR_VERSION       (4u)
# define MEMMAP_AR_RELEASE_MINOR_VERSION       (0u)
# define MEMMAP_AR_RELEASE_REVISION_VERSION    (3u)

/* compatiblity to older versions */
# undef MEM_AR_RELEASE_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_AR_RELEASE_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_AR_RELEASE_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEM_AR_RELEASE_MAJOR_VERSION          MEMMAP_AR_RELEASE_MAJOR_VERSION
# define MEM_AR_RELEASE_MINOR_VERSION          MEMMAP_AR_RELEASE_MINOR_VERSION
# define MEM_AR_RELEASE_PATCH_VERSION          MEMMAP_AR_RELEASE_REVISION_VERSION


# undef MEMMAP_SW_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_SW_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_SW_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEMMAP_SW_MAJOR_VERSION     (2u)
# define MEMMAP_SW_MINOR_VERSION     (2u)
# define MEMMAP_SW_PATCH_VERSION     (0u)

/* compatiblity to older versions */
# undef MEM_SW_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_SW_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_SW_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEM_SW_MAJOR_VERSION        MEMMAP_SW_MAJOR_VERSION
# define MEM_SW_MINOR_VERSION        MEMMAP_SW_MINOR_VERSION
# define MEM_SW_PATCH_VERSION        MEMMAP_SW_PATCH_VERSION

#define MEMMAP_ERROR

/* Package Merger: Start Section MemMapModuleList */


/**********************************************************************************************************************
 *  ETH_30_AR7000 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETH_30_AR7000_START_SEC_CODE
  #undef ETH_30_AR7000_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef ETH_30_AR7000_STOP_SEC_CODE
  #undef ETH_30_AR7000_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef ETH_30_AR7000_START_SEC_CODE_ISR
  #undef ETH_30_AR7000_START_SEC_CODE_ISR
  #define START_SEC_CODE_ISR                        /* mapped to default ISR code section */
#endif
#ifdef ETH_30_AR7000_STOP_SEC_CODE_ISR
  #undef ETH_30_AR7000_STOP_SEC_CODE_ISR
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ETH_30_AR7000_START_SEC_CONST_8BIT
# undef ETH_30_AR7000_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef ETH_30_AR7000_STOP_SEC_CONST_8BIT
# undef ETH_30_AR7000_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef ETH_30_AR7000_START_SEC_CONST_16BIT
# undef ETH_30_AR7000_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef ETH_30_AR7000_STOP_SEC_CONST_16BIT
# undef ETH_30_AR7000_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETH_30_AR7000_START_SEC_CONST_32BIT
# undef ETH_30_AR7000_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETH_30_AR7000_STOP_SEC_CONST_32BIT
# undef ETH_30_AR7000_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETH_30_AR7000_START_SEC_CONST_UNSPECIFIED
# undef ETH_30_AR7000_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETH_30_AR7000_STOP_SEC_CONST_UNSPECIFIED
# undef ETH_30_AR7000_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETH_30_AR7000_START_SEC_VAR_NOINIT_8BIT
# undef ETH_30_AR7000_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_8BIT
# undef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_AR7000_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETH_30_AR7000_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETH_30_AR7000_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETH_30_AR7000_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_AR7000_START_SEC_VAR_NOINIT_16BIT
# undef ETH_30_AR7000_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_16BIT
# undef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_AR7000_START_SEC_VAR_NOINIT_32BIT
# undef ETH_30_AR7000_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_32BIT
# undef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_AR7000_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETH_30_AR7000_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_AR7000_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETH_30_AR7000_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETH_30_AR7000_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETH_30_AR7000_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_AR7000_START_SEC_VAR_NOINIT_DESCRIPTOR
# undef ETH_30_AR7000_START_SEC_VAR_NOINIT_DESCRIPTOR
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_DESCRIPTOR
# undef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_DESCRIPTOR
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_AR7000_START_SEC_VAR_NOINIT_BUFFER
# undef ETH_30_AR7000_START_SEC_VAR_NOINIT_BUFFER
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_BUFFER
# undef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_BUFFER
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETH_30_AR7000 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHTRCV_30_AR7000 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHTRCV_30_AR7000_START_SEC_CODE
  #undef ETHTRCV_30_AR7000_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_CODE
  #undef ETHTRCV_30_AR7000_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/
#ifdef ETHTRCV_30_AR7000_START_SEC_CONST_8BIT
# undef ETHTRCV_30_AR7000_START_SEC_CONST_8BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_CONST_8BIT
# undef ETHTRCV_30_AR7000_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_AR7000_START_SEC_CONST_16BIT
# undef ETHTRCV_30_AR7000_START_SEC_CONST_16BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_CONST_16BIT
# undef ETHTRCV_30_AR7000_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_AR7000_START_SEC_CONST_32BIT
# undef ETHTRCV_30_AR7000_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_CONST_32BIT
# undef ETHTRCV_30_AR7000_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_AR7000_START_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_AR7000_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_AR7000_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_AR7000_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_AR7000_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_AR7000_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/*******  NVM sections  **********************************************************************************************/

#ifdef ETHTRCV_30_AR7000_START_SEC_CONST_UNSPECIFIED_NVM
# undef ETHTRCV_30_AR7000_START_SEC_CONST_UNSPECIFIED_NVM
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_CONST_UNSPECIFIED_NVM
# undef ETHTRCV_30_AR7000_STOP_SEC_CONST_UNSPECIFIED_NVM
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_UNSPECIFIED_NVM
# undef ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_UNSPECIFIED_NVM
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_UNSPECIFIED_NVM
# undef ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_UNSPECIFIED_NVM
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHTRCV_30_AR7000 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
* 3rdParty_Mcal START
*********************************************************************************************************************/

#ifdef ADC_START_SEC_CODE_ASIL_B_GLOBAL
  #undef ADC_START_SEC_CODE_ASIL_B_GLOBAL
  #define START_SEC_CODE
#endif

#ifdef ADC_STOP_SEC_CODE_ASIL_B_GLOBAL
  #undef ADC_STOP_SEC_CODE_ASIL_B_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #undef ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #undef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #undef ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #undef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #undef ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #undef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #undef ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #undef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #undef ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #undef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #undef ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #undef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #define STOP_SEC_CONST
#endif
#ifdef ADC_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef ADC_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_CONST_ASIL_B_GLOBAL_8
  #undef ADC_START_SEC_CONST_ASIL_B_GLOBAL_8
  #define START_SEC_CONST_8BIT
#endif

#ifdef ADC_STOP_SEC_CONST_ASIL_B_GLOBAL_8
  #undef ADC_STOP_SEC_CONST_ASIL_B_GLOBAL_8
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #undef ADC_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #undef ADC_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
  #undef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
  #undef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
  #undef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
  #undef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
  #undef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
  #undef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
  #undef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
  #undef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
  #undef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
  #undef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
  #undef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
  #undef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef ADC_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define STOP_SEC_VAR
#endif

#ifdef CRC_START_SEC_CODE_ASIL_B_GLOBAL
  #undef CRC_START_SEC_CODE_ASIL_B_GLOBAL
  #define START_SEC_CODE
#endif

#ifdef CRC_STOP_SEC_CODE_ASIL_B_GLOBAL
  #undef CRC_STOP_SEC_CODE_ASIL_B_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef CRC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #undef CRC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #undef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #undef CRC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #undef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #undef CRC_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #undef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #undef CRC_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #undef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #undef CRC_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #undef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #undef CRC_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #undef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
  #undef CRC_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
  #undef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
  #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_64
  #undef CRC_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_64
  #define START_SEC_CONST_64BIT
#endif

#ifdef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_64
  #undef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_64
  #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef CRC_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
  #undef CRC_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
  #undef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONST_ASIL_B_GLOBAL_16
  #undef CRC_START_SEC_CONST_ASIL_B_GLOBAL_16
  #define START_SEC_CONST_16BIT
#endif

#ifdef CRC_STOP_SEC_CONST_ASIL_B_GLOBAL_16
  #undef CRC_STOP_SEC_CONST_ASIL_B_GLOBAL_16
  #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONST_ASIL_B_GLOBAL_32
  #undef CRC_START_SEC_CONST_ASIL_B_GLOBAL_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef CRC_STOP_SEC_CONST_ASIL_B_GLOBAL_32
  #undef CRC_STOP_SEC_CONST_ASIL_B_GLOBAL_32
  #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONST_ASIL_B_GLOBAL_8
  #undef CRC_START_SEC_CONST_ASIL_B_GLOBAL_8
  #define START_SEC_CONST_8BIT
#endif

#ifdef CRC_STOP_SEC_CONST_ASIL_B_GLOBAL_8
  #undef CRC_STOP_SEC_CONST_ASIL_B_GLOBAL_8
  #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #undef CRC_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef CRC_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #undef CRC_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_VAR_INIT_ASIL_B_CORE0_32
  #undef CRC_START_SEC_VAR_INIT_ASIL_B_CORE0_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef CRC_STOP_SEC_VAR_INIT_ASIL_B_CORE0_32
  #undef CRC_STOP_SEC_VAR_INIT_ASIL_B_CORE0_32
  #define STOP_SEC_VAR
#endif

#ifdef CRC_START_SEC_VAR_INIT_ASIL_B_CORE1_32
  #undef CRC_START_SEC_VAR_INIT_ASIL_B_CORE1_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef CRC_STOP_SEC_VAR_INIT_ASIL_B_CORE1_32
  #undef CRC_STOP_SEC_VAR_INIT_ASIL_B_CORE1_32
  #define STOP_SEC_VAR
#endif

#ifdef CRC_START_SEC_VAR_INIT_ASIL_B_CORE2_32
  #undef CRC_START_SEC_VAR_INIT_ASIL_B_CORE2_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef CRC_STOP_SEC_VAR_INIT_ASIL_B_CORE2_32
  #undef CRC_STOP_SEC_VAR_INIT_ASIL_B_CORE2_32
  #define STOP_SEC_VAR
#endif

#ifdef CRC_START_SEC_VAR_INIT_ASIL_B_CORE3_32
  #undef CRC_START_SEC_VAR_INIT_ASIL_B_CORE3_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef CRC_STOP_SEC_VAR_INIT_ASIL_B_CORE3_32
  #undef CRC_STOP_SEC_VAR_INIT_ASIL_B_CORE3_32
  #define STOP_SEC_VAR
#endif

#ifdef CRC_START_SEC_VAR_INIT_ASIL_B_CORE4_32
  #undef CRC_START_SEC_VAR_INIT_ASIL_B_CORE4_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef CRC_STOP_SEC_VAR_INIT_ASIL_B_CORE4_32
  #undef CRC_STOP_SEC_VAR_INIT_ASIL_B_CORE4_32
  #define STOP_SEC_VAR
#endif

#ifdef CRC_START_SEC_VAR_INIT_ASIL_B_CORE5_32
  #undef CRC_START_SEC_VAR_INIT_ASIL_B_CORE5_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef CRC_STOP_SEC_VAR_INIT_ASIL_B_CORE5_32
  #undef CRC_STOP_SEC_VAR_INIT_ASIL_B_CORE5_32
  #define STOP_SEC_VAR
#endif

#ifdef CRC_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #undef CRC_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef CRC_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #undef CRC_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #define STOP_SEC_VAR
#endif

#ifdef CRC_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
  #undef CRC_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef CRC_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
  #undef CRC_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef CRC_START_SEC_VAR_INIT_ASIL_B_GLOBAL_8
  #undef CRC_START_SEC_VAR_INIT_ASIL_B_GLOBAL_8
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef CRC_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_8
  #undef CRC_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_8
  #define STOP_SEC_VAR
#endif

#ifdef DIO_START_SEC_CODE_ASIL_B_GLOBAL
  #undef DIO_START_SEC_CODE_ASIL_B_GLOBAL
  #define START_SEC_CODE
#endif

#ifdef DIO_STOP_SEC_CODE_ASIL_B_GLOBAL
  #undef DIO_STOP_SEC_CODE_ASIL_B_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef DIO_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef DIO_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DIO_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef DIO_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef DIO_START_SEC_CONST_ASIL_B_GLOBAL_16
  #undef DIO_START_SEC_CONST_ASIL_B_GLOBAL_16
  #define START_SEC_CONST_16BIT
#endif

#ifdef DIO_STOP_SEC_CONST_ASIL_B_GLOBAL_16
  #undef DIO_STOP_SEC_CONST_ASIL_B_GLOBAL_16
  #define STOP_SEC_CONST
#endif

#ifdef DIO_START_SEC_CONST_ASIL_B_GLOBAL_32
  #undef DIO_START_SEC_CONST_ASIL_B_GLOBAL_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef DIO_STOP_SEC_CONST_ASIL_B_GLOBAL_32
  #undef DIO_STOP_SEC_CONST_ASIL_B_GLOBAL_32
  #define STOP_SEC_CONST
#endif

#ifdef DMA_START_SEC_CODE
  #undef DMA_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef DMA_STOP_SEC_CODE
  #undef DMA_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef DMA_START_SEC_CODE_ASIL_B_GLOBAL
  #undef DMA_START_SEC_CODE_ASIL_B_GLOBAL
  #define START_SEC_CODE
#endif

#ifdef DMA_STOP_SEC_CODE_ASIL_B_GLOBAL
  #undef DMA_STOP_SEC_CODE_ASIL_B_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_256
  #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_256
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_256
  #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_256
  #define STOP_SEC_CONST
#endif

#ifdef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE1_256
  #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE1_256
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_256
  #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_256
  #define STOP_SEC_CONST
#endif

#ifdef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE2_256
  #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE2_256
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_256
  #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_256
  #define STOP_SEC_CONST
#endif

#ifdef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE3_256
  #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE3_256
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_256
  #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_256
  #define STOP_SEC_CONST
#endif

#ifdef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE4_256
  #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE4_256
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_256
  #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_256
  #define STOP_SEC_CONST
#endif

#ifdef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE5_256
  #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE5_256
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_256
  #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_256
  #define STOP_SEC_CONST
#endif

#ifdef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef DMA_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef DMA_START_SEC_CONST_ASIL_B_GLOBAL_32
  #undef DMA_START_SEC_CONST_ASIL_B_GLOBAL_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef DMA_STOP_SEC_CONST_ASIL_B_GLOBAL_32
  #undef DMA_STOP_SEC_CONST_ASIL_B_GLOBAL_32
  #define STOP_SEC_CONST
#endif

#ifdef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE0_8
  #undef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE0_8
  #define START_SEC_VAR_ZERO_INIT_8BIT
#endif

#ifdef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_8
  #undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_8
  #define STOP_SEC_VAR
#endif

#ifdef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE1_8
  #undef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE1_8
  #define START_SEC_VAR_ZERO_INIT_8BIT
#endif

#ifdef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_8
  #undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_8
  #define STOP_SEC_VAR
#endif

#ifdef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE2_8
  #undef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE2_8
  #define START_SEC_VAR_ZERO_INIT_8BIT
#endif

#ifdef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_8
  #undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_8
  #define STOP_SEC_VAR
#endif

#ifdef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE3_8
  #undef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE3_8
  #define START_SEC_VAR_ZERO_INIT_8BIT
#endif

#ifdef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_8
  #undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_8
  #define STOP_SEC_VAR
#endif

#ifdef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE4_8
  #undef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE4_8
  #define START_SEC_VAR_ZERO_INIT_8BIT
#endif

#ifdef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_8
  #undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_8
  #define STOP_SEC_VAR
#endif

#ifdef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE5_8
  #undef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE5_8
  #define START_SEC_VAR_ZERO_INIT_8BIT
#endif

#ifdef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_8
  #undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_8
  #define STOP_SEC_VAR
#endif

#ifdef DMA_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef DMA_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define STOP_SEC_VAR
#endif

#ifdef DMA_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
  #undef DMA_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
  #define START_SEC_VAR_ZERO_INIT_8BIT
#endif

#ifdef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
  #undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
  #define STOP_SEC_VAR
#endif

#ifdef DSADC_START_SEC_CODE_ASIL_B_LOCAL
  #undef DSADC_START_SEC_CODE_ASIL_B_LOCAL
  #define START_SEC_CODE
#endif

#ifdef DSADC_STOP_SEC_CODE_ASIL_B_LOCAL
  #undef DSADC_STOP_SEC_CODE_ASIL_B_LOCAL
  #define STOP_SEC_CODE
#endif

#ifdef DSADC_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
  #undef DSADC_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DSADC_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
  #undef DSADC_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef DSADC_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
  #undef DSADC_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef DSADC_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
  #undef DSADC_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
  #define STOP_SEC_VAR
#endif

#ifdef DSADC_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
  #undef DSADC_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
  #define START_SEC_VAR_ZERO_INIT_8BIT
#endif

#ifdef DSADC_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
  #undef DSADC_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
  #define STOP_SEC_VAR
#endif

#ifdef FEE_START_SEC_CODE
  #undef FEE_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef FEE_STOP_SEC_CODE
  #undef FEE_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FEE_START_SEC_CODE_ASIL_B_GLOBAL
  #undef FEE_START_SEC_CODE_ASIL_B_GLOBAL
  #define START_SEC_CODE
#endif

#ifdef FEE_STOP_SEC_CODE_ASIL_B_GLOBAL
  #undef FEE_STOP_SEC_CODE_ASIL_B_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef FEE_START_SEC_CODE_ASIL_B_ILLEGALNOTIF
  #undef FEE_START_SEC_CODE_ASIL_B_ILLEGALNOTIF
  #define START_SEC_CODE
#endif

#ifdef FEE_STOP_SEC_CODE_ASIL_B_ILLEGALNOTIF
  #undef FEE_STOP_SEC_CODE_ASIL_B_ILLEGALNOTIF
  #define STOP_SEC_CODE
#endif

#ifdef FEE_START_SEC_CODE_ASIL_B_JOBENDNOTIF
  #undef FEE_START_SEC_CODE_ASIL_B_JOBENDNOTIF
  #define START_SEC_CODE
#endif

#ifdef FEE_STOP_SEC_CODE_ASIL_B_JOBENDNOTIF
  #undef FEE_STOP_SEC_CODE_ASIL_B_JOBENDNOTIF
  #define STOP_SEC_CODE
#endif

#ifdef FEE_START_SEC_CODE_ASIL_B_JOBERRNOTIF
  #undef FEE_START_SEC_CODE_ASIL_B_JOBERRNOTIF
  #define START_SEC_CODE
#endif

#ifdef FEE_STOP_SEC_CODE_ASIL_B_JOBERRNOTIF
  #undef FEE_STOP_SEC_CODE_ASIL_B_JOBERRNOTIF
  #define STOP_SEC_CODE
#endif

#ifdef FEE_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
  #undef FEE_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FEE_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
  #undef FEE_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef FEE_START_SEC_CONST_ASIL_B_32
  #undef FEE_START_SEC_CONST_ASIL_B_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef FEE_STOP_SEC_CONST_ASIL_B_32
  #undef FEE_STOP_SEC_CONST_ASIL_B_32
  #define STOP_SEC_CONST
#endif

#ifdef FEE_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef FEE_START_SEC_CONST_ASIL_B_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FEE_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #undef FEE_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef FEE_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef FEE_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef FEE_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef FEE_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define STOP_SEC_VAR
#endif

#ifdef FEE_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #undef FEE_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef FEE_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #undef FEE_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef FEE_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #undef FEE_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef FEE_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #undef FEE_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #define STOP_SEC_VAR
#endif
#ifdef FEE_START_SEC_CODE_ASIL_B_LOCAL
  #undef FEE_START_SEC_CODE_ASIL_B_LOCAL
  #define START_SEC_CODE
#endif

#ifdef FEE_STOP_SEC_CODE_ASIL_B_LOCAL
  #undef FEE_STOP_SEC_CODE_ASIL_B_LOCAL
  #define STOP_SEC_CODE
#endif

#ifdef FEE_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
  #undef FEE_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FEE_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
  #undef FEE_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef FEE_START_SEC_CONST_ASIL_B_LOCAL_32
  #undef FEE_START_SEC_CONST_ASIL_B_LOCAL_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef FEE_STOP_SEC_CONST_ASIL_B_LOCAL_32
  #undef FEE_STOP_SEC_CONST_ASIL_B_LOCAL_32
  #define STOP_SEC_CONST
#endif

#ifdef FEE_START_SEC_ERASEERRORNOTI_CODE_ASIL_B_LOCAL
  #undef FEE_START_SEC_ERASEERRORNOTI_CODE_ASIL_B_LOCAL
  #define START_SEC_CODE
#endif

#ifdef FEE_STOP_SEC_ERASEERRORNOTI_CODE_ASIL_B_LOCAL
  #undef FEE_STOP_SEC_ERASEERRORNOTI_CODE_ASIL_B_LOCAL
  #define STOP_SEC_CODE
#endif

#ifdef FEE_START_SEC_ILLEGALNOTIF_CODE_ASIL_B_LOCAL
  #undef FEE_START_SEC_ILLEGALNOTIF_CODE_ASIL_B_LOCAL
  #define START_SEC_CODE
#endif

#ifdef FEE_STOP_SEC_ILLEGALNOTIF_CODE_ASIL_B_LOCAL
  #undef FEE_STOP_SEC_ILLEGALNOTIF_CODE_ASIL_B_LOCAL
  #define STOP_SEC_CODE
#endif

#ifdef FEE_START_SEC_JOBENDNOTIF_CODE_ASIL_B_LOCAL
  #undef FEE_START_SEC_JOBENDNOTIF_CODE_ASIL_B_LOCAL
  #define START_SEC_CODE
#endif

#ifdef FEE_STOP_SEC_JOBENDNOTIF_CODE_ASIL_B_LOCAL
  #undef FEE_STOP_SEC_JOBENDNOTIF_CODE_ASIL_B_LOCAL
  #define STOP_SEC_CODE
#endif

#ifdef FEE_START_SEC_JOBERRNOTIF_CODE_ASIL_B_LOCAL
  #undef FEE_START_SEC_JOBERRNOTIF_CODE_ASIL_B_LOCAL
  #define START_SEC_CODE
#endif

#ifdef FEE_STOP_SEC_JOBERRNOTIF_CODE_ASIL_B_LOCAL
  #undef FEE_STOP_SEC_JOBERRNOTIF_CODE_ASIL_B_LOCAL
  #define STOP_SEC_CODE
#endif

#ifdef FEE_START_SEC_PROGERRORNOTI_CODE_ASIL_B_LOCAL
  #undef FEE_START_SEC_PROGERRORNOTI_CODE_ASIL_B_LOCAL
  #define START_SEC_CODE
#endif

#ifdef FEE_STOP_SEC_PROGERRORNOTI_CODE_ASIL_B_LOCAL
  #undef FEE_STOP_SEC_PROGERRORNOTI_CODE_ASIL_B_LOCAL
  #define STOP_SEC_CODE
#endif

#ifdef FEE_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
  #undef FEE_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef FEE_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
  #undef FEE_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
  #define STOP_SEC_VAR
#endif

#ifdef FEE_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
  #undef FEE_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef FEE_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
  #undef FEE_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef FEE_START_SEC_VAR_INIT_ASIL_B_LOCAL_8
  #undef FEE_START_SEC_VAR_INIT_ASIL_B_LOCAL_8
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef FEE_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_8
  #undef FEE_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_8
  #define STOP_SEC_VAR
#endif


#ifdef FLS_17_DMU_START_SEC_CODE
  #undef FLS_17_DMU_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef FLS_17_DMU_STOP_SEC_CODE
  #undef FLS_17_DMU_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_17_DMU_START_SEC_CODE_ASIL_B_LOCAL
  #undef FLS_17_DMU_START_SEC_CODE_ASIL_B_LOCAL
  #define START_SEC_CODE
#endif

#ifdef FLS_17_DMU_STOP_SEC_CODE_ASIL_B_LOCAL
  #undef FLS_17_DMU_STOP_SEC_CODE_ASIL_B_LOCAL
  #define STOP_SEC_CODE
#endif

#ifdef FLS_17_DMU_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
  #undef FLS_17_DMU_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FLS_17_DMU_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
  #undef FLS_17_DMU_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
  #undef FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
  #undef FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
  #define STOP_SEC_VAR
#endif

#ifdef FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
  #undef FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
  #undef FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef FLSLOADER_START_SEC_BUSYLOOP_CALLOUT_CODE_QM_LOCAL
  #undef FLSLOADER_START_SEC_BUSYLOOP_CALLOUT_CODE_QM_LOCAL
  #define START_SEC_CODE
#endif

#ifdef FLSLOADER_STOP_SEC_BUSYLOOP_CALLOUT_CODE_QM_LOCAL
  #undef FLSLOADER_STOP_SEC_BUSYLOOP_CALLOUT_CODE_QM_LOCAL
  #define STOP_SEC_CODE
#endif

#ifdef FLSLOADER_START_SEC_CODE_QM_LOCAL
  #undef FLSLOADER_START_SEC_CODE_QM_LOCAL
  #define START_SEC_CODE
#endif

#ifdef FLSLOADER_STOP_SEC_CODE_QM_LOCAL
  #undef FLSLOADER_STOP_SEC_CODE_QM_LOCAL
  #define STOP_SEC_CODE
#endif

#ifdef FLSLOADER_START_SEC_CONST_QM_LOCAL_32
  #undef FLSLOADER_START_SEC_CONST_QM_LOCAL_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef FLSLOADER_STOP_SEC_CONST_QM_LOCAL_32
  #undef FLSLOADER_STOP_SEC_CONST_QM_LOCAL_32
  #define STOP_SEC_CONST
#endif

#ifdef FLSLOADER_START_SEC_CONST_QM_LOCAL_8
  #undef FLSLOADER_START_SEC_CONST_QM_LOCAL_8
  #define START_SEC_CONST_8BIT
#endif

#ifdef FLSLOADER_STOP_SEC_CONST_QM_LOCAL_8
  #undef FLSLOADER_STOP_SEC_CONST_QM_LOCAL_8
  #define STOP_SEC_CONST
#endif

#ifdef FLSLOADER_START_SEC_VAR_CLEARED_QM_LOCAL_32
  #undef FLSLOADER_START_SEC_VAR_CLEARED_QM_LOCAL_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef FLSLOADER_STOP_SEC_VAR_CLEARED_QM_LOCAL_32
  #undef FLSLOADER_STOP_SEC_VAR_CLEARED_QM_LOCAL_32
  #define STOP_SEC_VAR
#endif

#ifdef FLSLOADER_START_SEC_VAR_CLEARED_QM_LOCAL_8
  #undef FLSLOADER_START_SEC_VAR_CLEARED_QM_LOCAL_8
  #define START_SEC_VAR_ZERO_INIT_8BIT
#endif

#ifdef FLSLOADER_STOP_SEC_VAR_CLEARED_QM_LOCAL_8
  #undef FLSLOADER_STOP_SEC_VAR_CLEARED_QM_LOCAL_8
  #define STOP_SEC_VAR
#endif

#ifdef FLSLOADER_START_SEC_WRITEERASE_CODE_QM_LOCAL
  #undef FLSLOADER_START_SEC_WRITEERASE_CODE_QM_LOCAL
  #define START_SEC_CODE
#endif

#ifdef FLSLOADER_STOP_SEC_WRITEERASE_CODE_QM_LOCAL
  #undef FLSLOADER_STOP_SEC_WRITEERASE_CODE_QM_LOCAL
  #define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_CODE_ASIL_B_GLOBAL
  #undef GPT_START_SEC_CODE_ASIL_B_GLOBAL
  #define START_SEC_CODE
#endif

#ifdef GPT_STOP_SEC_CODE_ASIL_B_GLOBAL
  #undef GPT_STOP_SEC_CODE_ASIL_B_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_CODE_FAST_ASIL_B_GLOBAL
  #undef GPT_START_SEC_CODE_FAST_ASIL_B_GLOBAL
  #define START_SEC_CODE_FAST
#endif

#ifdef GPT_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL
  #undef GPT_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #undef GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #undef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #undef GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #undef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #undef GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #undef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #undef GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #undef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #undef GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #undef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #undef GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #undef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef GPT_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_CONST_ASIL_B_CORE0_8
  #undef GPT_START_SEC_CONST_ASIL_B_CORE0_8
  #define START_SEC_CONST_8BIT
#endif

#ifdef GPT_STOP_SEC_CONST_ASIL_B_CORE0_8
  #undef GPT_STOP_SEC_CONST_ASIL_B_CORE0_8
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_CONST_ASIL_B_CORE1_8
  #undef GPT_START_SEC_CONST_ASIL_B_CORE1_8
  #define START_SEC_CONST_8BIT
#endif

#ifdef GPT_STOP_SEC_CONST_ASIL_B_CORE1_8
  #undef GPT_STOP_SEC_CONST_ASIL_B_CORE1_8
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_CONST_ASIL_B_CORE2_8
  #undef GPT_START_SEC_CONST_ASIL_B_CORE2_8
  #define START_SEC_CONST_8BIT
#endif

#ifdef GPT_STOP_SEC_CONST_ASIL_B_CORE2_8
  #undef GPT_STOP_SEC_CONST_ASIL_B_CORE2_8
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_CONST_ASIL_B_CORE3_8
  #undef GPT_START_SEC_CONST_ASIL_B_CORE3_8
  #define START_SEC_CONST_8BIT
#endif

#ifdef GPT_STOP_SEC_CONST_ASIL_B_CORE3_8
  #undef GPT_STOP_SEC_CONST_ASIL_B_CORE3_8
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_CONST_ASIL_B_CORE4_8
  #undef GPT_START_SEC_CONST_ASIL_B_CORE4_8
  #define START_SEC_CONST_8BIT
#endif

#ifdef GPT_STOP_SEC_CONST_ASIL_B_CORE4_8
  #undef GPT_STOP_SEC_CONST_ASIL_B_CORE4_8
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_CONST_ASIL_B_CORE5_8
  #undef GPT_START_SEC_CONST_ASIL_B_CORE5_8
  #define START_SEC_CONST_8BIT
#endif

#ifdef GPT_STOP_SEC_CONST_ASIL_B_CORE5_8
  #undef GPT_STOP_SEC_CONST_ASIL_B_CORE5_8
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_CONST_ASIL_B_GLOBAL_32
  #undef GPT_START_SEC_CONST_ASIL_B_GLOBAL_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef GPT_STOP_SEC_CONST_ASIL_B_GLOBAL_32
  #undef GPT_STOP_SEC_CONST_ASIL_B_GLOBAL_32
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #undef GPT_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #undef GPT_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE0_8
  #undef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE0_8
  #define START_SEC_VAR_ZERO_INIT_8BIT
#endif

#ifdef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_8
  #undef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_8
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32
  #undef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32
  #undef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32
  #undef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32
  #undef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32
  #undef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32
  #undef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32
  #undef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32
  #undef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32
  #undef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32
  #undef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32
  #undef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32
  #undef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef GPT_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_INIT_ASIL_B_CORE0_UNSPECIFIED
  #undef GPT_START_SEC_VAR_INIT_ASIL_B_CORE0_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE0_UNSPECIFIED
  #undef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_INIT_ASIL_B_CORE1_UNSPECIFIED
  #undef GPT_START_SEC_VAR_INIT_ASIL_B_CORE1_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE1_UNSPECIFIED
  #undef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE1_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_INIT_ASIL_B_CORE2_UNSPECIFIED
  #undef GPT_START_SEC_VAR_INIT_ASIL_B_CORE2_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE2_UNSPECIFIED
  #undef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE2_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_INIT_ASIL_B_CORE3_UNSPECIFIED
  #undef GPT_START_SEC_VAR_INIT_ASIL_B_CORE3_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE3_UNSPECIFIED
  #undef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE3_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_INIT_ASIL_B_CORE4_UNSPECIFIED
  #undef GPT_START_SEC_VAR_INIT_ASIL_B_CORE4_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE4_UNSPECIFIED
  #undef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE4_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_INIT_ASIL_B_CORE5_UNSPECIFIED
  #undef GPT_START_SEC_VAR_INIT_ASIL_B_CORE5_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE5_UNSPECIFIED
  #undef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE5_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #undef GPT_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #undef GPT_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef GPT_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef GPT_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ICU_17_TIMERIP_START_SEC_CODE_ASIL_B_GLOBAL
  #undef ICU_17_TIMERIP_START_SEC_CODE_ASIL_B_GLOBAL
  #define START_SEC_CODE
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_CODE_ASIL_B_GLOBAL
  #undef ICU_17_TIMERIP_STOP_SEC_CODE_ASIL_B_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #undef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #undef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #undef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #undef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #undef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #undef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #undef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #undef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #undef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #undef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #undef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #undef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ICU_17_TIMERIP_START_SEC_CONST_ASIL_B_GLOBAL_32
  #undef ICU_17_TIMERIP_START_SEC_CONST_ASIL_B_GLOBAL_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_CONST_ASIL_B_GLOBAL_32
  #undef ICU_17_TIMERIP_STOP_SEC_CONST_ASIL_B_GLOBAL_32
  #define STOP_SEC_CONST
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32
  #undef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32
  #undef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32
  #define STOP_SEC_VAR
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32
  #undef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32
  #undef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32
  #define STOP_SEC_VAR
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32
  #undef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32
  #undef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32
  #define STOP_SEC_VAR
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32
  #undef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32
  #undef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32
  #define STOP_SEC_VAR
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32
  #undef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32
  #undef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32
  #define STOP_SEC_VAR
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32
  #undef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32
  #undef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32
  #define STOP_SEC_VAR
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define STOP_SEC_VAR
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE0_32
  #undef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE0_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE0_32
  #undef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE0_32
  #define STOP_SEC_VAR
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE1_32
  #undef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE1_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE1_32
  #undef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE1_32
  #define STOP_SEC_VAR
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE2_32
  #undef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE2_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE2_32
  #undef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE2_32
  #define STOP_SEC_VAR
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE3_32
  #undef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE3_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE3_32
  #undef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE3_32
  #define STOP_SEC_VAR
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE4_32
  #undef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE4_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE4_32
  #undef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE4_32
  #define STOP_SEC_VAR
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE5_32
  #undef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE5_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE5_32
  #undef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE5_32
  #define STOP_SEC_VAR
#endif

#ifdef IRQ_START_SEC_CODE
  #undef IRQ_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef IRQ_STOP_SEC_CODE
  #undef IRQ_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef IRQ_START_SEC_CODE_QM_GLOBAL
  #undef IRQ_START_SEC_CODE_QM_GLOBAL
  #define START_SEC_CODE
#endif

#ifdef IRQ_STOP_SEC_CODE_QM_GLOBAL
  #undef IRQ_STOP_SEC_CODE_QM_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef MCALLIB_START_SEC_CODE
  #undef MCALLIB_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef MCALLIB_STOP_SEC_CODE
  #undef MCALLIB_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef MCALLIB_START_SEC_CODE_ASIL_B_GLOBAL
  #undef MCALLIB_START_SEC_CODE_ASIL_B_GLOBAL
  #define START_SEC_CODE
#endif

#ifdef MCALLIB_STOP_SEC_CODE_ASIL_B_GLOBAL
  #undef MCALLIB_STOP_SEC_CODE_ASIL_B_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef MCALLIB_START_SEC_CONST_ASIL_B_GLOBAL_32
  #undef MCALLIB_START_SEC_CONST_ASIL_B_GLOBAL_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef MCALLIB_STOP_SEC_CONST_ASIL_B_GLOBAL_32
  #undef MCALLIB_STOP_SEC_CONST_ASIL_B_GLOBAL_32
  #define STOP_SEC_CONST
#endif

#ifdef MCALLIB_START_SEC_CONST_ASIL_B_GLOBAL_8
  #undef MCALLIB_START_SEC_CONST_ASIL_B_GLOBAL_8
  #define START_SEC_CONST_8BIT
#endif

#ifdef MCALLIB_STOP_SEC_CONST_ASIL_B_GLOBAL_8
  #undef MCALLIB_STOP_SEC_CONST_ASIL_B_GLOBAL_8
  #define STOP_SEC_CONST
#endif

#ifdef MCALLIB_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
	#error "For Integrator: This section must be aligned to a 4-byte boundary!"
	   /* Pragma must be placed here. */
	   /* Example for Tasking compiler:  
		#pragma align 4
	   */
  #undef MCALLIB_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef MCALLIB_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
	#error "For Integrator: Alignment must be restored!"
	   /* Pragma must be restored here. */
	   /* Example for Tasking compiler:  
		#pragma align restore
	   */
  #undef MCALLIB_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define STOP_SEC_VAR
#endif

#ifdef MCU_17_TIMERIP_START_SEC_CODE_ASIL_B_GLOBAL
  #undef MCU_17_TIMERIP_START_SEC_CODE_ASIL_B_GLOBAL
  #define START_SEC_CODE
#endif

#ifdef MCU_17_TIMERIP_STOP_SEC_CODE_ASIL_B_GLOBAL
  #undef MCU_17_TIMERIP_STOP_SEC_CODE_ASIL_B_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef MCU_17_TIMERIP_START_SEC_CODE_FAST_ASIL_B_GLOBAL
  #undef MCU_17_TIMERIP_START_SEC_CODE_FAST_ASIL_B_GLOBAL
  #define START_SEC_CODE_FAST
#endif

#ifdef MCU_17_TIMERIP_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL
  #undef MCU_17_TIMERIP_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_16
  #undef MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_16
  #define START_SEC_CONST_16BIT
#endif

#ifdef MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_16
  #undef MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_16
  #define STOP_SEC_CONST
#endif

#ifdef MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
  #undef MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
  #undef MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
  #define STOP_SEC_CONST
#endif

#ifdef MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_8
  #undef MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_8
  #define START_SEC_CONST_8BIT
#endif

#ifdef MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_8
  #undef MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_8
  #define STOP_SEC_CONST
#endif

#ifdef MCU_17_TIMERIP_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #undef MCU_17_TIMERIP_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef MCU_17_TIMERIP_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #undef MCU_17_TIMERIP_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef MCU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #undef MCU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef MCU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #undef MCU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #define STOP_SEC_VAR
#endif

#ifdef MCU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef MCU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef MCU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef MCU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_CODE
  #undef MCU_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef MCU_STOP_SEC_CODE
  #undef MCU_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef MCU_START_SEC_CODE_ASIL_B_GLOBAL
  #undef MCU_START_SEC_CODE_ASIL_B_GLOBAL
  #define START_SEC_CODE
#endif

#ifdef MCU_STOP_SEC_CODE_ASIL_B_GLOBAL
  #undef MCU_STOP_SEC_CODE_ASIL_B_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef MCU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef MCU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef MCU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef MCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef MCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef MCU_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef MCU_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define STOP_SEC_VAR
#endif

#ifdef OCU_START_SEC_CODE_ASIL_B_GLOBAL
  #undef OCU_START_SEC_CODE_ASIL_B_GLOBAL
  #define START_SEC_CODE
#endif

#ifdef OCU_STOP_SEC_CODE_ASIL_B_GLOBAL
  #undef OCU_STOP_SEC_CODE_ASIL_B_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #undef OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #undef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #undef OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #undef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #undef OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #undef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #undef OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #undef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #undef OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #undef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #undef OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #undef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef OCU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef OCU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef OCU_START_SEC_CONST_ASIL_B_GLOBAL_32
  #undef OCU_START_SEC_CONST_ASIL_B_GLOBAL_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef OCU_STOP_SEC_CONST_ASIL_B_GLOBAL_32
  #undef OCU_STOP_SEC_CONST_ASIL_B_GLOBAL_32
  #define STOP_SEC_CONST
#endif

#ifdef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32
  #undef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32
  #undef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32
  #define STOP_SEC_VAR
#endif

#ifdef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32
  #undef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32
  #undef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32
  #define STOP_SEC_VAR
#endif

#ifdef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32
  #undef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32
  #undef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32
  #define STOP_SEC_VAR
#endif

#ifdef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32
  #undef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32
  #undef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32
  #define STOP_SEC_VAR
#endif

#ifdef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32
  #undef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32
  #undef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32
  #define STOP_SEC_VAR
#endif

#ifdef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32
  #undef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32
  #undef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32
  #define STOP_SEC_VAR
#endif

#ifdef OCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef OCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define STOP_SEC_VAR
#endif

#ifdef PORT_START_SEC_CODE_ASIL_B_GLOBAL
  #undef PORT_START_SEC_CODE_ASIL_B_GLOBAL
  #define START_SEC_CODE
#endif

#ifdef PORT_STOP_SEC_CODE_ASIL_B_GLOBAL
  #undef PORT_STOP_SEC_CODE_ASIL_B_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef PORT_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef PORT_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef PORT_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef PORT_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef PORT_START_SEC_CONST_ASIL_B_GLOBAL_16
  #undef PORT_START_SEC_CONST_ASIL_B_GLOBAL_16
  #define START_SEC_CONST_16BIT
#endif

#ifdef PORT_STOP_SEC_CONST_ASIL_B_GLOBAL_16
  #undef PORT_STOP_SEC_CONST_ASIL_B_GLOBAL_16
  #define STOP_SEC_CONST
#endif

#ifdef PORT_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef PORT_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef PORT_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef PORT_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define STOP_SEC_VAR
#endif

#ifdef PORT_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
  #undef PORT_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
  #define START_SEC_VAR_ZERO_INIT_8BIT
#endif

#ifdef PORT_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
  #undef PORT_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
  #define STOP_SEC_VAR
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_CODE_ASIL_B_GLOBAL
  #undef PWM_17_GTMCCU6_START_SEC_CODE_ASIL_B_GLOBAL
  #define START_SEC_CODE
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_CODE_ASIL_B_GLOBAL
  #undef PWM_17_GTMCCU6_STOP_SEC_CODE_ASIL_B_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_CODE_FAST_ASIL_B_GLOBAL
  #undef PWM_17_GTMCCU6_START_SEC_CODE_FAST_ASIL_B_GLOBAL
  #define START_SEC_CODE_FAST
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL
  #undef PWM_17_GTMCCU6_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #undef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #undef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #undef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #undef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #undef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #undef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #undef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #undef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #undef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #undef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #undef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #undef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #undef PWM_17_GTMCCU6_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #undef PWM_17_GTMCCU6_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
  #undef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
  #undef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
  #undef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
  #undef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
  #undef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
  #undef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
  #undef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
  #undef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
  #undef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
  #undef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
  #undef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
  #undef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define STOP_SEC_VAR
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
  #undef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
  #define START_SEC_VAR_ZERO_INIT_8BIT
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
  #undef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
  #define STOP_SEC_VAR
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef PWM_17_GTMCCU6_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef PWM_17_GTMCCU6_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SMU_START_SEC_CODE_ASIL_B_GLOBAL
  #undef SMU_START_SEC_CODE_ASIL_B_GLOBAL
  #define START_SEC_CODE
#endif

#ifdef SMU_STOP_SEC_CODE_ASIL_B_GLOBAL
  #undef SMU_STOP_SEC_CODE_ASIL_B_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef SMU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef SMU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef SMU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef SMU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef SMU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #undef SMU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef SMU_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #undef SMU_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_CODE
  #undef SPI_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef SPI_STOP_SEC_CODE
  #undef SPI_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef SPI_START_SEC_CODE_ASIL_B_GLOBAL
  #undef SPI_START_SEC_CODE_ASIL_B_GLOBAL
  #define START_SEC_CODE
#endif

#ifdef SPI_STOP_SEC_CODE_ASIL_B_GLOBAL
  #undef SPI_STOP_SEC_CODE_ASIL_B_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
  #undef SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
  #undef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
  #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE1_32
  #undef SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE1_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_32
  #undef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_32
  #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE2_32
  #undef SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE2_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_32
  #undef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_32
  #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE3_32
  #undef SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE3_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_32
  #undef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_32
  #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE4_32
  #undef SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE4_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_32
  #undef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_32
  #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE5_32
  #undef SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE5_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_32
  #undef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_32
  #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
  #undef SPI_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
  #undef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
  #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef SPI_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #undef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE0_256
  #undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE0_256
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_256
  #undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_256
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32
  #undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32
  #undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE1_256
  #undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE1_256
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_256
  #undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_256
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32
  #undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32
  #undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE2_256
  #undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE2_256
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_256
  #undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_256
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32
  #undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32
  #undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE3_256
  #undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE3_256
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_256
  #undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_256
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32
  #undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32
  #undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE4_256
  #undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE4_256
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_256
  #undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_256
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32
  #undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32
  #undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE5_256
  #undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE5_256
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_256
  #undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_256
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32
  #undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32
  #undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef SPI_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define STOP_SEC_VAR
#endif

#ifdef UART_START_SEC_CODE
  #undef UART_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef UART_STOP_SEC_CODE
  #undef UART_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef UART_START_SEC_CODE_ASIL_B_LOCAL
  #undef UART_START_SEC_CODE_ASIL_B_LOCAL
  #define START_SEC_CODE
#endif

#ifdef UART_STOP_SEC_CODE_ASIL_B_LOCAL
  #undef UART_STOP_SEC_CODE_ASIL_B_LOCAL
  #define STOP_SEC_CODE
#endif

#ifdef UART_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
  #undef UART_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef UART_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
  #undef UART_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef UART_START_SEC_CONST_ASIL_B_LOCAL_32
  #undef UART_START_SEC_CONST_ASIL_B_LOCAL_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef UART_STOP_SEC_CONST_ASIL_B_LOCAL_32
  #undef UART_STOP_SEC_CONST_ASIL_B_LOCAL_32
  #define STOP_SEC_CONST
#endif

#ifdef UART_START_SEC_CONST_ASIL_B_LOCAL_8
  #undef UART_START_SEC_CONST_ASIL_B_LOCAL_8
  #define START_SEC_CONST_8BIT
#endif

#ifdef UART_STOP_SEC_CONST_ASIL_B_LOCAL_8
  #undef UART_STOP_SEC_CONST_ASIL_B_LOCAL_8
  #define STOP_SEC_CONST
#endif

#ifdef UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
  #undef UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
  #undef UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
  #define STOP_SEC_VAR
#endif

#ifdef UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
  #undef UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
  #define START_SEC_VAR_ZERO_INIT_8BIT
#endif

#ifdef UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
  #undef UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
  #define STOP_SEC_VAR
#endif

#ifdef UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
  #undef UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
  #undef UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_17_SCU_START_SEC_CODE_ASIL_B_GLOBAL
  #undef WDG_17_SCU_START_SEC_CODE_ASIL_B_GLOBAL
  #define START_SEC_CODE
#endif

#ifdef WDG_17_SCU_STOP_SEC_CODE_ASIL_B_GLOBAL
  #undef WDG_17_SCU_STOP_SEC_CODE_ASIL_B_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef WDG_17_SCU_START_SEC_CODE_FAST_ASIL_B_GLOBAL
  #undef WDG_17_SCU_START_SEC_CODE_FAST_ASIL_B_GLOBAL
  #define START_SEC_CODE_FAST
#endif

#ifdef WDG_17_SCU_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL
  #undef WDG_17_SCU_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL
  #define STOP_SEC_CODE
#endif

#ifdef WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #undef WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #undef WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #undef WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #undef WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #undef WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #undef WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #undef WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #undef WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #undef WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #undef WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #undef WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #undef WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef WDG_17_SCU_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #undef WDG_17_SCU_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef WDG_17_SCU_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #undef WDG_17_SCU_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
  #undef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
  #undef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
  #undef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
  #undef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
  #undef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
  #undef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
  #undef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
  #undef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
  #undef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
  #undef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
  #undef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
  #undef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #undef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
  #define STOP_SEC_VAR
#endif

#ifdef WDG_17_SCU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef WDG_17_SCU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef WDG_17_SCU_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #undef WDG_17_SCU_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
* 3rdParty_Mcal END
*********************************************************************************************************************/


/**********************************************************************************************************************
 *  CSM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined (CSM_START_SEC_CODE)
# undef CSM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#if defined (CSM_STOP_SEC_CODE)
# undef CSM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#if defined (CSM_START_SEC_APPL_CODE)
# undef CSM_START_SEC_APPL_CODE  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#if defined (CSM_STOP_SEC_APPL_CODE)
# undef CSM_STOP_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined (CSM_START_SEC_CONST_8BIT)
# undef CSM_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif

#if defined (CSM_STOP_SEC_CONST_8BIT)
# undef CSM_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined (CSM_START_SEC_CONST_UNSPECIFIED)
# undef CSM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined (CSM_STOP_SEC_CONST_UNSPECIFIED)
# undef CSM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#if defined (CSM_START_SEC_VAR_NOINIT_8BIT)
# undef CSM_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined (CSM_STOP_SEC_VAR_NOINIT_8BIT)
# undef CSM_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined (CSM_START_SEC_VAR_NOINIT_16BIT)
# undef CSM_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined (CSM_STOP_SEC_VAR_NOINIT_16BIT)
# undef CSM_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#if defined (CSM_START_SEC_VAR_ZERO_INIT_8BIT)
# undef CSM_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined (CSM_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef CSM_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined (CSM_START_SEC_VAR_ZERO_INIT_32BIT)
# undef CSM_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined (CSM_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef CSM_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined (CSM_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CSM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined (CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CSM END
 *********************************************************************************************************************/


/***********************************************************************************************************************
 *  KEYM START
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef KEYM_START_SEC_CODE
# undef KEYM_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef KEYM_STOP_SEC_CODE
# undef KEYM_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

#ifdef KEYM_START_SEC_APPL_CODE
# undef KEYM_START_SEC_APPL_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef KEYM_STOP_SEC_APPL_CODE
# undef KEYM_STOP_SEC_APPL_CODE                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef KEYM_START_SEC_CONST_8
# undef KEYM_START_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8
#endif
#ifdef KEYM_STOP_SEC_CONST_8
# undef KEYM_STOP_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef KEYM_START_SEC_CONST_16
# undef KEYM_START_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16
#endif
#ifdef KEYM_STOP_SEC_CONST_16
# undef KEYM_STOP_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef KEYM_START_SEC_CONST_32
# undef KEYM_START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32
#endif
#ifdef KEYM_STOP_SEC_CONST_32
# undef KEYM_STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef KEYM_START_SEC_CONST_UNSPECIFIED
# undef KEYM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef KEYM_STOP_SEC_CONST_UNSPECIFIED
# undef KEYM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NO_INIT sections */

#ifdef KEYM_START_SEC_VAR_NO_INIT_8
# undef KEYM_START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_8
#endif
#ifdef KEYM_STOP_SEC_VAR_NO_INIT_8
# undef KEYM_STOP_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef KEYM_START_SEC_VAR_NO_INIT_16
# undef KEYM_START_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_16
#endif
#ifdef KEYM_STOP_SEC_VAR_NO_INIT_16
# undef KEYM_STOP_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef KEYM_START_SEC_VAR_NO_INIT_32
# undef KEYM_START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_32
#endif
#ifdef KEYM_STOP_SEC_VAR_NO_INIT_32
# undef KEYM_STOP_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#ifdef KEYM_START_SEC_VAR_CLEARED_8
# undef KEYM_START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_CLEARED_8
#endif
#ifdef KEYM_STOP_SEC_VAR_CLEARED_8
# undef KEYM_STOP_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef KEYM_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef KEYM_START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#ifdef KEYM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef KEYM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/***********************************************************************************************************************
 *  KEYM END
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  VSTDLIB START
 *********************************************************************************************************************/

#if defined(VSTDLIB_START_SEC_CODE)
# undef VSTDLIB_START_SEC_CODE                             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                    /* mapped to default code section */
#endif
#if defined(VSTDLIB_STOP_SEC_CODE)
# undef VSTDLIB_STOP_SEC_CODE                              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

#if defined(VSTDLIB_START_SEC_CONST_8BIT)
# undef VSTDLIB_START_SEC_CONST_8BIT                       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT                              /* mapped to const 8 bit section */
#endif
#if defined(VSTDLIB_STOP_SEC_CONST_8BIT)
# undef VSTDLIB_STOP_SEC_CONST_8BIT                        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST                                    /* default const stop section */
#endif

/**********************************************************************************************************************
 *  VSTDLIB END
 *********************************************************************************************************************/



/* PRQA L:MEMMAP_0841_TAG */

/* MEMMAP_REMAPPING_ONLY is set if the MemMap is only used to remap Memory Allocation Keywords.
   If not set the Memory Allocation Keywords will be resolved to pragmas */
#ifndef MEMMAP_REMAPPING_ONLY
# include "MemMap_Common.h"

/* MEMMAP_ERROR is
  - still defined if MemMap_Common.h did not contain a matching section
  - undefined, if MemMap_Common.h handled the section define. */
# ifdef MEMMAP_ERROR
/* contains all configured MemMap Sections */
#  include "MemMap_Compatibility.h" /* generated by module MemMap */
# endif

# ifdef MEMMAP_ERROR
#  error No MemMap section found in MemMap_Common.h and MemMap_Compatibility.h. Check your section define for validity.
# endif
#endif

#endif /* MICROSAR_DISABLE_MEMMAP */


/**********************************************************************************************************************
 *  END OF FILE: MemMap.h
 *********************************************************************************************************************/

