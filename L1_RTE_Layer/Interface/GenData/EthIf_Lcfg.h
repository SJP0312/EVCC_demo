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
 *            Module: EthIf
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EthIf_Lcfg.h
 *   Generation Time: 2025-09-11 13:39:32
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/


#if !defined (ETHIF_LCFG_H)
# define ETHIF_LCFG_H

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0777 EOF */ /* MD_MSR_5.1_777 */
/* PRQA S 0779 EOF */ /* MD_MSR_5.1_779 */

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/

/*********************************************************************************************************
 * Predefined file includes based on \trace DSGN-EthIfDiag1977
 *********************************************************************************************************/
# include "EthIf_GenTypes.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# if !defined (ETHIF_LOCAL_INLINE)
#  define ETHIF_LOCAL_INLINE LOCAL_INLINE
# endif

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES (NOT COMSTACKLIB GENERATED)
**********************************************************************************************************************/
/**********************************************************************************************************************
  EthIf_ConfigDataPtr
**********************************************************************************************************************/
/**
  \var    EthIf_ConfigDataPtr
  \brief  Points to the currently active configuration for EthIf
  \details
  Pointer is initialized during EthIf_Init() and holds the active configuration for EthIf were all configuration data
  is retrieved from during runtime.
*/
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
extern P2CONST(EthIf_ConfigType, ETHIF_VAR_NO_INIT, ETHIF_INIT_DATA) EthIf_ConfigDataPtr;
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  EthIfPCGetRootDataMacros  EthIf Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define EthIf_GetEthCtrlInitCntOfPCConfig()                                                         EthIf_ConfigDataPtr->EthCtrlInitCntOfPCConfig
#define EthIf_GetEthCtrlModeCntOfPCConfig()                                                         EthIf_ConfigDataPtr->EthCtrlModeCntOfPCConfig
#define EthIf_GetEthCtrlOfPCConfig()                                                                EthIf_ConfigDataPtr->EthCtrlOfPCConfig
#define EthIf_GetEthCtrlRxFrameCntOfPCConfig()                                                      EthIf_ConfigDataPtr->EthCtrlRxFrameCntOfPCConfig
#define EthIf_GetEthCtrlStateOfPCConfig()                                                           EthIf_ConfigDataPtr->EthCtrlStateOfPCConfig
#define EthIf_GetEthDrvApiOfPCConfig()                                                              EthIf_ConfigDataPtr->EthDrvApiOfPCConfig
#define EthIf_GetEthIfClkUnitOfPCConfig()                                                           EthIf_ConfigDataPtr->EthIfClkUnitOfPCConfig
#define EthIf_GetEthIfCtrlInitStateOfPCConfig()                                                     EthIf_ConfigDataPtr->EthIfCtrlInitStateOfPCConfig
#define EthIf_GetEthIfCtrlLinkCountOfPCConfig()                                                     EthIf_ConfigDataPtr->EthIfCtrlLinkCountOfPCConfig
#define EthIf_GetEthIfCtrlLinkStateOfPCConfig()                                                     EthIf_ConfigDataPtr->EthIfCtrlLinkStateOfPCConfig
#define EthIf_GetEthIfCtrlModeOfPCConfig()                                                          EthIf_ConfigDataPtr->EthIfCtrlModeOfPCConfig
#define EthIf_GetEthIfCtrlOfEthTrcvIndOfPCConfig()                                                  EthIf_ConfigDataPtr->EthIfCtrlOfEthTrcvIndOfPCConfig
#define EthIf_GetEthIfCtrlOfPCConfig()                                                              EthIf_ConfigDataPtr->EthIfCtrlOfPCConfig
#define EthIf_GetEthIfCtrlOfPortGroupIndOfPCConfig()                                                EthIf_ConfigDataPtr->EthIfCtrlOfPortGroupIndOfPCConfig
#define EthIf_GetEthIfCtrlRxStatsOfPCConfig()                                                       EthIf_ConfigDataPtr->EthIfCtrlRxStatsOfPCConfig
#define EthIf_GetEthIfCtrlTxStatsOfPCConfig()                                                       EthIf_ConfigDataPtr->EthIfCtrlTxStatsOfPCConfig
#define EthIf_GetEthIfMeasurementDataOfPCConfig()                                                   EthIf_ConfigDataPtr->EthIfMeasurementDataOfPCConfig
#define EthIf_GetEthIfPhysCtrlCfgOfPCConfig()                                                       EthIf_ConfigDataPtr->EthIfPhysCtrlCfgOfPCConfig
#define EthIf_GetEthIfSwtPortGroupStateOfPCConfig()                                                 EthIf_ConfigDataPtr->EthIfSwtPortGroupStateOfPCConfig
#define EthIf_GetEthSwtDrvApiOfPCConfig()                                                           EthIf_ConfigDataPtr->EthSwtDrvApiOfPCConfig
#define EthIf_GetEthSwtDrvOfPCConfig()                                                              EthIf_ConfigDataPtr->EthSwtDrvOfPCConfig
#define EthIf_GetEthSwtIndOfPCConfig()                                                              EthIf_ConfigDataPtr->EthSwtIndOfPCConfig
#define EthIf_GetEthSwtInitCntOfPCConfig()                                                          EthIf_ConfigDataPtr->EthSwtInitCntOfPCConfig
#define EthIf_GetEthSwtOfPCConfig()                                                                 EthIf_ConfigDataPtr->EthSwtOfPCConfig
#define EthIf_GetEthSwtPortInEthSwtContextOfPCConfig()                                              EthIf_ConfigDataPtr->EthSwtPortInEthSwtContextOfPCConfig
#define EthIf_GetEthSwtPortIndOfPCConfig()                                                          EthIf_ConfigDataPtr->EthSwtPortIndOfPCConfig
#define EthIf_GetEthSwtPortLinkStateOfPCConfig()                                                    EthIf_ConfigDataPtr->EthSwtPortLinkStateOfPCConfig
#define EthIf_GetEthSwtPortModeCntOfPCConfig()                                                      EthIf_ConfigDataPtr->EthSwtPortModeCntOfPCConfig
#define EthIf_GetEthSwtPortOfPCConfig()                                                             EthIf_ConfigDataPtr->EthSwtPortOfPCConfig
#define EthIf_GetEthTrcvDrvApiOfPCConfig()                                                          EthIf_ConfigDataPtr->EthTrcvDrvApiOfPCConfig
#define EthIf_GetEthTrcvInitCntOfPCConfig()                                                         EthIf_ConfigDataPtr->EthTrcvInitCntOfPCConfig
#define EthIf_GetEthTrcvLinkStateOfPCConfig()                                                       EthIf_ConfigDataPtr->EthTrcvLinkStateOfPCConfig
#define EthIf_GetEthTrcvModeCntOfPCConfig()                                                         EthIf_ConfigDataPtr->EthTrcvModeCntOfPCConfig
#define EthIf_GetEthTrcvOfPCConfig()                                                                EthIf_ConfigDataPtr->EthTrcvOfPCConfig
#define EthIf_GetEthTrcvStateOfPCConfig()                                                           EthIf_ConfigDataPtr->EthTrcvStateOfPCConfig
#define EthIf_GetExplicitBufReleaseFilterOfPCConfig()                                               EthIf_ConfigDataPtr->ExplicitBufReleaseFilterOfPCConfig
#define EthIf_GetGatewaySrcMacBlackListOfPCConfig()                                                 EthIf_ConfigDataPtr->GatewaySrcMacBlackListOfPCConfig
#define EthIf_GetInitLockedOfPCConfig()                                                             EthIf_ConfigDataPtr->InitLockedOfPCConfig
#define EthIf_GetLinkStateChgIndicationsOfPCConfig()                                                EthIf_ConfigDataPtr->LinkStateChgIndicationsOfPCConfig
#define EthIf_GetLinkStateChgMainReloadOfPCConfig()                                                 EthIf_ConfigDataPtr->LinkStateChgMainReloadOfPCConfig
#define EthIf_GetMainFuncStateDecoupleFreqCntOfPCConfig()                                           EthIf_ConfigDataPtr->MainFuncStateDecoupleFreqCntOfPCConfig
#define EthIf_GetMaxFrameRxPerEthCtrlOfPCConfig()                                                   EthIf_ConfigDataPtr->MaxFrameRxPerEthCtrlOfPCConfig
#define EthIf_GetMaxTxBufPerEthCtrlOfPCConfig()                                                     EthIf_ConfigDataPtr->MaxTxBufPerEthCtrlOfPCConfig
#define EthIf_GetMirrorDestOfPCConfig()                                                             EthIf_ConfigDataPtr->MirrorDestOfPCConfig
#define EthIf_GetMirrorTxInfoOfPCConfig()                                                           EthIf_ConfigDataPtr->MirrorTxInfoOfPCConfig
#define EthIf_GetModeChangeLockedOfPCConfig()                                                       EthIf_ConfigDataPtr->ModeChangeLockedOfPCConfig
#define EthIf_GetPhysLayerInitElemsOfPCConfig()                                                     EthIf_ConfigDataPtr->PhysLayerInitElemsOfPCConfig
#define EthIf_GetPhysLayerModeElemsOfPCConfig()                                                     EthIf_ConfigDataPtr->PhysLayerModeElemsOfPCConfig
#define EthIf_GetPortGroupHostOrUpLinkPortRoleLinkCountOfPCConfig()                                 EthIf_ConfigDataPtr->PortGroupHostOrUpLinkPortRoleLinkCountOfPCConfig
#define EthIf_GetPortGroupIndOfPCConfig()                                                           EthIf_ConfigDataPtr->PortGroupIndOfPCConfig
#define EthIf_GetPortGroupLaxLinkAggregationCountOfPCConfig()                                       EthIf_ConfigDataPtr->PortGroupLaxLinkAggregationCountOfPCConfig
#define EthIf_GetPortGroupLinkStateOfPCConfig()                                                     EthIf_ConfigDataPtr->PortGroupLinkStateOfPCConfig
#define EthIf_GetPortGroupModeOfPCConfig()                                                          EthIf_ConfigDataPtr->PortGroupModeOfPCConfig
#define EthIf_GetPortGroupNoRoleLinkCountOfPCConfig()                                               EthIf_ConfigDataPtr->PortGroupNoRoleLinkCountOfPCConfig
#define EthIf_GetPortGroupOfPCConfig()                                                              EthIf_ConfigDataPtr->PortGroupOfPCConfig
#define EthIf_GetPortSignalQualityResultOfPCConfig()                                                EthIf_ConfigDataPtr->PortSignalQualityResultOfPCConfig
#define EthIf_GetPortStartupActiveTimeCounterOfPCConfig()                                           EthIf_ConfigDataPtr->PortStartupActiveTimeCounterOfPCConfig
#define EthIf_GetPortStartupActiveTimeFreqOfPCConfig()                                              EthIf_ConfigDataPtr->PortStartupActiveTimeFreqOfPCConfig
#define EthIf_GetPortStartupActiveTimerActiveOfPCConfig()                                           EthIf_ConfigDataPtr->PortStartupActiveTimerActiveOfPCConfig
#define EthIf_GetRxIndicationsIndOfPCConfig()                                                       EthIf_ConfigDataPtr->RxIndicationsIndOfPCConfig
#define EthIf_GetRxIndicationsOfPCConfig()                                                          EthIf_ConfigDataPtr->RxIndicationsOfPCConfig
#define EthIf_GetSignalQualityChgMainReloadOfPCConfig()                                             EthIf_ConfigDataPtr->SignalQualityChgMainReloadOfPCConfig
#define EthIf_GetSignalQualityDecoupleFreqCntOfPCConfig()                                           EthIf_ConfigDataPtr->SignalQualityDecoupleFreqCntOfPCConfig
#define EthIf_GetSignalQualityResultOfPCConfig()                                                    EthIf_ConfigDataPtr->SignalQualityResultOfPCConfig
#define EthIf_GetSizeOfEthCtrlOfPCConfig()                                                          EthIf_ConfigDataPtr->SizeOfEthCtrlOfPCConfig
#define EthIf_GetSizeOfEthCtrlRxFrameCntOfPCConfig()                                                EthIf_ConfigDataPtr->SizeOfEthCtrlRxFrameCntOfPCConfig
#define EthIf_GetSizeOfEthDrvApiOfPCConfig()                                                        EthIf_ConfigDataPtr->SizeOfEthDrvApiOfPCConfig
#define EthIf_GetSizeOfEthIfClkUnitOfPCConfig()                                                     EthIf_ConfigDataPtr->SizeOfEthIfClkUnitOfPCConfig
#define EthIf_GetSizeOfEthIfCtrlOfEthTrcvIndOfPCConfig()                                            EthIf_ConfigDataPtr->SizeOfEthIfCtrlOfEthTrcvIndOfPCConfig
#define EthIf_GetSizeOfEthIfCtrlOfPCConfig()                                                        EthIf_ConfigDataPtr->SizeOfEthIfCtrlOfPCConfig
#define EthIf_GetSizeOfEthIfCtrlOfPortGroupIndOfPCConfig()                                          EthIf_ConfigDataPtr->SizeOfEthIfCtrlOfPortGroupIndOfPCConfig
#define EthIf_GetSizeOfEthIfMeasurementDataOfPCConfig()                                             EthIf_ConfigDataPtr->SizeOfEthIfMeasurementDataOfPCConfig
#define EthIf_GetSizeOfEthIfPhysCtrlCfgOfPCConfig()                                                 EthIf_ConfigDataPtr->SizeOfEthIfPhysCtrlCfgOfPCConfig
#define EthIf_GetSizeOfEthSwtDrvApiOfPCConfig()                                                     EthIf_ConfigDataPtr->SizeOfEthSwtDrvApiOfPCConfig
#define EthIf_GetSizeOfEthSwtDrvOfPCConfig()                                                        EthIf_ConfigDataPtr->SizeOfEthSwtDrvOfPCConfig
#define EthIf_GetSizeOfEthSwtIndOfPCConfig()                                                        EthIf_ConfigDataPtr->SizeOfEthSwtIndOfPCConfig
#define EthIf_GetSizeOfEthSwtOfPCConfig()                                                           EthIf_ConfigDataPtr->SizeOfEthSwtOfPCConfig
#define EthIf_GetSizeOfEthSwtPortInEthSwtContextOfPCConfig()                                        EthIf_ConfigDataPtr->SizeOfEthSwtPortInEthSwtContextOfPCConfig
#define EthIf_GetSizeOfEthSwtPortIndOfPCConfig()                                                    EthIf_ConfigDataPtr->SizeOfEthSwtPortIndOfPCConfig
#define EthIf_GetSizeOfEthSwtPortOfPCConfig()                                                       EthIf_ConfigDataPtr->SizeOfEthSwtPortOfPCConfig
#define EthIf_GetSizeOfEthTrcvDrvApiOfPCConfig()                                                    EthIf_ConfigDataPtr->SizeOfEthTrcvDrvApiOfPCConfig
#define EthIf_GetSizeOfEthTrcvOfPCConfig()                                                          EthIf_ConfigDataPtr->SizeOfEthTrcvOfPCConfig
#define EthIf_GetSizeOfExplicitBufReleaseFilterOfPCConfig()                                         EthIf_ConfigDataPtr->SizeOfExplicitBufReleaseFilterOfPCConfig
#define EthIf_GetSizeOfGatewaySrcMacBlackListOfPCConfig()                                           EthIf_ConfigDataPtr->SizeOfGatewaySrcMacBlackListOfPCConfig
#define EthIf_GetSizeOfLinkStateChgIndicationsOfPCConfig()                                          EthIf_ConfigDataPtr->SizeOfLinkStateChgIndicationsOfPCConfig
#define EthIf_GetSizeOfMirrorDestOfPCConfig()                                                       EthIf_ConfigDataPtr->SizeOfMirrorDestOfPCConfig
#define EthIf_GetSizeOfMirrorTxInfoOfPCConfig()                                                     EthIf_ConfigDataPtr->SizeOfMirrorTxInfoOfPCConfig
#define EthIf_GetSizeOfPhysLayerInitElemsOfPCConfig()                                               EthIf_ConfigDataPtr->SizeOfPhysLayerInitElemsOfPCConfig
#define EthIf_GetSizeOfPhysLayerModeElemsOfPCConfig()                                               EthIf_ConfigDataPtr->SizeOfPhysLayerModeElemsOfPCConfig
#define EthIf_GetSizeOfPortGroupIndOfPCConfig()                                                     EthIf_ConfigDataPtr->SizeOfPortGroupIndOfPCConfig
#define EthIf_GetSizeOfPortGroupOfPCConfig()                                                        EthIf_ConfigDataPtr->SizeOfPortGroupOfPCConfig
#define EthIf_GetSizeOfRxIndicationsIndOfPCConfig()                                                 EthIf_ConfigDataPtr->SizeOfRxIndicationsIndOfPCConfig
#define EthIf_GetSizeOfRxIndicationsOfPCConfig()                                                    EthIf_ConfigDataPtr->SizeOfRxIndicationsOfPCConfig
#define EthIf_GetSizeOfTxConfirmationsIndOfPCConfig()                                               EthIf_ConfigDataPtr->SizeOfTxConfirmationsIndOfPCConfig
#define EthIf_GetSizeOfTxConfirmationsOfPCConfig()                                                  EthIf_ConfigDataPtr->SizeOfTxConfirmationsOfPCConfig
#define EthIf_GetSizeOfTxContextOfPCConfig()                                                        EthIf_ConfigDataPtr->SizeOfTxContextOfPCConfig
#define EthIf_GetSizeOfUserOfPCConfig()                                                             EthIf_ConfigDataPtr->SizeOfUserOfPCConfig
#define EthIf_GetSizeOfWakeupMapOfPCConfig()                                                        EthIf_ConfigDataPtr->SizeOfWakeupMapOfPCConfig
#define EthIf_GetSrcMacAddrBufferOfPCConfig()                                                       EthIf_ConfigDataPtr->SrcMacAddrBufferOfPCConfig
#define EthIf_GetTxConfirmationsIndOfPCConfig()                                                     EthIf_ConfigDataPtr->TxConfirmationsIndOfPCConfig
#define EthIf_GetTxConfirmationsOfPCConfig()                                                        EthIf_ConfigDataPtr->TxConfirmationsOfPCConfig
#define EthIf_GetTxContextOfPCConfig()                                                              EthIf_ConfigDataPtr->TxContextOfPCConfig
#define EthIf_GetUserOfPCConfig()                                                                   EthIf_ConfigDataPtr->UserOfPCConfig
#define EthIf_GetWakeupMapOfPCConfig()                                                              EthIf_ConfigDataPtr->WakeupMapOfPCConfig
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCGetDuplicatedRootDataMacros  EthIf Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define EthIf_GetSizeOfEthCtrlInitCntOfPCConfig()                                                   EthIf_GetSizeOfEthCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthCtrlInitCnt */
#define EthIf_GetSizeOfEthCtrlModeCntOfPCConfig()                                                   EthIf_GetSizeOfEthCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthCtrlModeCnt */
#define EthIf_GetSizeOfEthCtrlStateOfPCConfig()                                                     EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthCtrlState */
#define EthIf_GetSizeOfEthIfCtrlInitStateOfPCConfig()                                               EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthIfCtrlInitState */
#define EthIf_GetSizeOfEthIfCtrlLinkCountOfPCConfig()                                               EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthIfCtrlLinkCount */
#define EthIf_GetSizeOfEthIfCtrlLinkStateOfPCConfig()                                               EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthIfCtrlLinkState */
#define EthIf_GetSizeOfEthIfCtrlModeOfPCConfig()                                                    EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthIfCtrlMode */
#define EthIf_GetSizeOfEthIfCtrlRxStatsOfPCConfig()                                                 EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthIfCtrlRxStats */
#define EthIf_GetSizeOfEthIfCtrlTxStatsOfPCConfig()                                                 EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthIfCtrlTxStats */
#define EthIf_GetSizeOfEthIfSwtPortGroupStateOfPCConfig()                                           EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthIfSwtPortGroupState */
#define EthIf_GetSizeOfEthSwtInitCntOfPCConfig()                                                    EthIf_GetSizeOfEthSwtOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthSwtInitCnt */
#define EthIf_GetSizeOfEthSwtPortLinkStateOfPCConfig()                                              EthIf_GetSizeOfEthSwtPortOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthSwtPortLinkState */
#define EthIf_GetSizeOfEthSwtPortModeCntOfPCConfig()                                                EthIf_GetSizeOfEthSwtPortOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthSwtPortModeCnt */
#define EthIf_GetSizeOfEthTrcvInitCntOfPCConfig()                                                   EthIf_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthTrcvInitCnt */
#define EthIf_GetSizeOfEthTrcvLinkStateOfPCConfig()                                                 EthIf_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthTrcvLinkState */
#define EthIf_GetSizeOfEthTrcvModeCntOfPCConfig()                                                   EthIf_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthTrcvModeCnt */
#define EthIf_GetSizeOfEthTrcvStateOfPCConfig()                                                     EthIf_GetSizeOfEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_EthTrcvState */
#define EthIf_GetSizeOfPortGroupHostOrUpLinkPortRoleLinkCountOfPCConfig()                           EthIf_GetSizeOfPortGroupOfPCConfig()  /**< the number of accomplishable value elements in EthIf_PortGroupHostOrUpLinkPortRoleLinkCount */
#define EthIf_GetSizeOfPortGroupLaxLinkAggregationCountOfPCConfig()                                 EthIf_GetSizeOfPortGroupOfPCConfig()  /**< the number of accomplishable value elements in EthIf_PortGroupLaxLinkAggregationCount */
#define EthIf_GetSizeOfPortGroupLinkStateOfPCConfig()                                               EthIf_GetSizeOfPortGroupOfPCConfig()  /**< the number of accomplishable value elements in EthIf_PortGroupLinkState */
#define EthIf_GetSizeOfPortGroupModeOfPCConfig()                                                    EthIf_GetSizeOfPortGroupOfPCConfig()  /**< the number of accomplishable value elements in EthIf_PortGroupMode */
#define EthIf_GetSizeOfPortGroupNoRoleLinkCountOfPCConfig()                                         EthIf_GetSizeOfPortGroupOfPCConfig()  /**< the number of accomplishable value elements in EthIf_PortGroupNoRoleLinkCount */
#define EthIf_GetSizeOfPortSignalQualityResultOfPCConfig()                                          EthIf_GetSizeOfEthSwtPortOfPCConfig()  /**< the number of accomplishable value elements in EthIf_PortSignalQualityResult */
#define EthIf_GetSizeOfSignalQualityResultOfPCConfig()                                              EthIf_GetSizeOfEthTrcvOfPCConfig()  /**< the number of accomplishable value elements in EthIf_SignalQualityResult */
#define EthIf_GetSizeOfSrcMacAddrBufferOfPCConfig()                                                 EthIf_GetSizeOfEthCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthIf_SrcMacAddrBuffer */
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCGetDataMacros  EthIf Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define EthIf_GetEthDrvApiIdxOfEthCtrl(Index)                                                       (EthIf_GetEthCtrlOfPCConfig()[(Index)].EthDrvApiIdxOfEthCtrl)
#define EthIf_GetSnvOfEthCtrl(Index)                                                                (EthIf_GetEthCtrlOfPCConfig()[(Index)].SnvOfEthCtrl)
#define EthIf_GetTxContextEndIdxOfEthCtrl(Index)                                                    (EthIf_GetEthCtrlOfPCConfig()[(Index)].TxContextEndIdxOfEthCtrl)
#define EthIf_GetTxContextStartIdxOfEthCtrl(Index)                                                  (EthIf_GetEthCtrlOfPCConfig()[(Index)].TxContextStartIdxOfEthCtrl)
#define EthIf_GetEthCtrlInitCnt(Index)                                                              (EthIf_GetEthCtrlInitCntOfPCConfig()[(Index)])
#define EthIf_GetEthCtrlModeCnt(Index)                                                              (EthIf_GetEthCtrlModeCntOfPCConfig()[(Index)])
#define EthIf_GetEthCtrlRxFrameCnt(Index)                                                           (EthIf_GetEthCtrlRxFrameCntOfPCConfig()[(Index)])
#define EthIf_GetEthCtrlState(Index)                                                                (EthIf_GetEthCtrlStateOfPCConfig()[(Index)])
#define EthIf_GetCtrlInitOfEthDrvApi(Index)                                                         (EthIf_GetEthDrvApiOfPCConfig()[(Index)].CtrlInitOfEthDrvApi)
#define EthIf_GetEnableEgressTimeStampOfEthDrvApi(Index)                                            (EthIf_GetEthDrvApiOfPCConfig()[(Index)].EnableEgressTimeStampOfEthDrvApi)
#define EthIf_GetGetBandwidthLimitOfEthDrvApi(Index)                                                (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetBandwidthLimitOfEthDrvApi)
#define EthIf_GetGetCtrlModeOfEthDrvApi(Index)                                                      (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetCtrlModeOfEthDrvApi)
#define EthIf_GetGetCurrentTimeOfEthDrvApi(Index)                                                   (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetCurrentTimeOfEthDrvApi)
#define EthIf_GetGetEgressTimeStampOfEthDrvApi(Index)                                               (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetEgressTimeStampOfEthDrvApi)
#define EthIf_GetGetIngressTimeStampOfEthDrvApi(Index)                                              (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetIngressTimeStampOfEthDrvApi)
#define EthIf_GetGetPhysAddrOfEthDrvApi(Index)                                                      (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetPhysAddrOfEthDrvApi)
#define EthIf_GetGetRxHeaderPtrOfEthDrvApi(Index)                                                   (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetRxHeaderPtrOfEthDrvApi)
#define EthIf_GetGetRxStatsOfEthDrvApi(Index)                                                       (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetRxStatsOfEthDrvApi)
#define EthIf_GetGetTxHeaderPtrOfEthDrvApi(Index)                                                   (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetTxHeaderPtrOfEthDrvApi)
#define EthIf_GetGetTxStatsOfEthDrvApi(Index)                                                       (EthIf_GetEthDrvApiOfPCConfig()[(Index)].GetTxStatsOfEthDrvApi)
#define EthIf_GetProvideExtTxBufferOfEthDrvApi(Index)                                               (EthIf_GetEthDrvApiOfPCConfig()[(Index)].ProvideExtTxBufferOfEthDrvApi)
#define EthIf_GetProvideTxBufferOfEthDrvApi(Index)                                                  (EthIf_GetEthDrvApiOfPCConfig()[(Index)].ProvideTxBufferOfEthDrvApi)
#define EthIf_GetReceiveOfEthDrvApi(Index)                                                          (EthIf_GetEthDrvApiOfPCConfig()[(Index)].ReceiveOfEthDrvApi)
#define EthIf_GetReleaseRxBufferOfEthDrvApi(Index)                                                  (EthIf_GetEthDrvApiOfPCConfig()[(Index)].ReleaseRxBufferOfEthDrvApi)
#define EthIf_GetSetBandwidthLimitOfEthDrvApi(Index)                                                (EthIf_GetEthDrvApiOfPCConfig()[(Index)].SetBandwidthLimitOfEthDrvApi)
#define EthIf_GetSetCtrlModeOfEthDrvApi(Index)                                                      (EthIf_GetEthDrvApiOfPCConfig()[(Index)].SetCtrlModeOfEthDrvApi)
#define EthIf_GetSetPhysAddrOfEthDrvApi(Index)                                                      (EthIf_GetEthDrvApiOfPCConfig()[(Index)].SetPhysAddrOfEthDrvApi)
#define EthIf_GetTransmitOfEthDrvApi(Index)                                                         (EthIf_GetEthDrvApiOfPCConfig()[(Index)].TransmitOfEthDrvApi)
#define EthIf_GetTxConfOfEthDrvApi(Index)                                                           (EthIf_GetEthDrvApiOfPCConfig()[(Index)].TxConfOfEthDrvApi)
#define EthIf_GetUpdatePhysAddrFilterOfEthDrvApi(Index)                                             (EthIf_GetEthDrvApiOfPCConfig()[(Index)].UpdatePhysAddrFilterOfEthDrvApi)
#define EthIf_GetVTransmitOfEthDrvApi(Index)                                                        (EthIf_GetEthDrvApiOfPCConfig()[(Index)].VTransmitOfEthDrvApi)
#define EthIf_GetEthClkUnitIdxOfEthIfClkUnit(Index)                                                 (EthIf_GetEthIfClkUnitOfPCConfig()[(Index)].EthClkUnitIdxOfEthIfClkUnit)
#define EthIf_GetEthIfClkUnitIdxOfEthIfClkUnit(Index)                                               (EthIf_GetEthIfClkUnitOfPCConfig()[(Index)].EthIfClkUnitIdxOfEthIfClkUnit)
#define EthIf_GetEthCtrlIdxOfEthIfCtrl(Index)                                                       (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].EthCtrlIdxOfEthIfCtrl)
#define EthIf_GetEthIfPhysCtrlCfgIdxOfEthIfCtrl(Index)                                              (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].EthIfPhysCtrlCfgIdxOfEthIfCtrl)
#define EthIf_GetEthSwtDrvApiIdxOfEthIfCtrl(Index)                                                  (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].EthSwtDrvApiIdxOfEthIfCtrl)
#define EthIf_GetGatewayDestEthIfCtrlIdxIdxOfEthIfCtrl(Index)                                       (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].GatewayDestEthIfCtrlIdxIdxOfEthIfCtrl)
#define EthIf_GetGatewayDestEthIfCtrlIdxOfEthIfCtrl(Index)                                          (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].GatewayDestEthIfCtrlIdxOfEthIfCtrl)
#define EthIf_GetLinkAggrThresholdOfEthIfCtrl(Index)                                                (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].LinkAggrThresholdOfEthIfCtrl)
#define EthIf_GetMacSecTypeOfEthIfCtrl(Index)                                                       (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].MacSecTypeOfEthIfCtrl)
#define EthIf_GetMirrorRxDestIdxIdxOfEthIfCtrl(Index)                                               (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].MirrorRxDestIdxIdxOfEthIfCtrl)
#define EthIf_GetMirrorRxDestIdxOfEthIfCtrl(Index)                                                  (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].MirrorRxDestIdxOfEthIfCtrl)
#define EthIf_GetMirrorTxDestIdxIdxOfEthIfCtrl(Index)                                               (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].MirrorTxDestIdxIdxOfEthIfCtrl)
#define EthIf_GetMirrorTxDestIdxOfEthIfCtrl(Index)                                                  (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].MirrorTxDestIdxOfEthIfCtrl)
#define EthIf_GetMtuOfEthIfCtrl(Index)                                                              (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].MtuOfEthIfCtrl)
#define EthIf_GetPhysLayerInitElemsIdxOfEthIfCtrl(Index)                                            (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].PhysLayerInitElemsIdxOfEthIfCtrl)
#define EthIf_GetPhysLayerModeElemsIdxOfEthIfCtrl(Index)                                            (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].PhysLayerModeElemsIdxOfEthIfCtrl)
#define EthIf_GetSnvOfEthIfCtrl(Index)                                                              (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].SnvOfEthIfCtrl)
#define EthIf_GetTypeOfEthIfCtrl(Index)                                                             (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].TypeOfEthIfCtrl)
#define EthIf_GetVlanIdOfEthIfCtrl(Index)                                                           (EthIf_GetEthIfCtrlOfPCConfig()[(Index)].VlanIdOfEthIfCtrl)
#define EthIf_GetEthIfCtrlInitState(Index)                                                          (EthIf_GetEthIfCtrlInitStateOfPCConfig()[(Index)])
#define EthIf_GetEthIfCtrlLinkCount(Index)                                                          (EthIf_GetEthIfCtrlLinkCountOfPCConfig()[(Index)])
#define EthIf_GetEthIfCtrlLinkState(Index)                                                          (EthIf_GetEthIfCtrlLinkStateOfPCConfig()[(Index)])
#define EthIf_GetEthIfCtrlMode(Index)                                                               (EthIf_GetEthIfCtrlModeOfPCConfig()[(Index)])
#define EthIf_GetEthIfCtrlOfEthTrcvInd(Index)                                                       (EthIf_GetEthIfCtrlOfEthTrcvIndOfPCConfig()[(Index)])
#define EthIf_GetEthIfCtrlOfPortGroupInd(Index)                                                     (EthIf_GetEthIfCtrlOfPortGroupIndOfPCConfig()[(Index)])
#define EthIf_GetNumRxBytesOfEthIfCtrlRxStats(Index)                                                (EthIf_GetEthIfCtrlRxStatsOfPCConfig()[(Index)].NumRxBytesOfEthIfCtrlRxStats)
#define EthIf_GetNumRxPktsOfEthIfCtrlRxStats(Index)                                                 (EthIf_GetEthIfCtrlRxStatsOfPCConfig()[(Index)].NumRxPktsOfEthIfCtrlRxStats)
#define EthIf_GetNumTxBytesOfEthIfCtrlTxStats(Index)                                                (EthIf_GetEthIfCtrlTxStatsOfPCConfig()[(Index)].NumTxBytesOfEthIfCtrlTxStats)
#define EthIf_GetNumTxPktsOfEthIfCtrlTxStats(Index)                                                 (EthIf_GetEthIfCtrlTxStatsOfPCConfig()[(Index)].NumTxPktsOfEthIfCtrlTxStats)
#define EthIf_GetDropCtrlIdxOfEthIfMeasurementData(Index)                                           (EthIf_GetEthIfMeasurementDataOfPCConfig()[(Index)].DropCtrlIdxOfEthIfMeasurementData)
#define EthIf_GetUnknownEtherTypeOfEthIfMeasurementData(Index)                                      (EthIf_GetEthIfMeasurementDataOfPCConfig()[(Index)].UnknownEtherTypeOfEthIfMeasurementData)
#define EthIf_GetVlanDoubleTaggedOfEthIfMeasurementData(Index)                                      (EthIf_GetEthIfMeasurementDataOfPCConfig()[(Index)].VlanDoubleTaggedOfEthIfMeasurementData)
#define EthIf_GetEthCtrlIdxOfEthIfPhysCtrlCfg(Index)                                                (EthIf_GetEthIfPhysCtrlCfgOfPCConfig()[(Index)].EthCtrlIdxOfEthIfPhysCtrlCfg)
#define EthIf_GetEthDrvApiIdxOfEthIfPhysCtrlCfg(Index)                                              (EthIf_GetEthIfPhysCtrlCfgOfPCConfig()[(Index)].EthDrvApiIdxOfEthIfPhysCtrlCfg)
#define EthIf_GetEthIfClkUnitEndIdxOfEthIfPhysCtrlCfg(Index)                                        (EthIf_GetEthIfPhysCtrlCfgOfPCConfig()[(Index)].EthIfClkUnitEndIdxOfEthIfPhysCtrlCfg)
#define EthIf_GetEthIfClkUnitStartIdxOfEthIfPhysCtrlCfg(Index)                                      (EthIf_GetEthIfPhysCtrlCfgOfPCConfig()[(Index)].EthIfClkUnitStartIdxOfEthIfPhysCtrlCfg)
#define EthIf_GetEthIfPhysControllerIdxOfEthIfPhysCtrlCfg(Index)                                    (EthIf_GetEthIfPhysCtrlCfgOfPCConfig()[(Index)].EthIfPhysControllerIdxOfEthIfPhysCtrlCfg)
#define EthIf_IsEthPhcSupportAvailableOfEthIfPhysCtrlCfg(Index)                                     ((EthIf_GetEthIfPhysCtrlCfgOfPCConfig()[(Index)].EthPhcSupportAvailableOfEthIfPhysCtrlCfg) != FALSE)
#define EthIf_GetEthIfSwtPortGroupState(Index)                                                      (EthIf_GetEthIfSwtPortGroupStateOfPCConfig()[(Index)])
#define EthIf_GetEthSwtDrvApiIdxOfEthSwt(Index)                                                     (EthIf_GetEthSwtOfPCConfig()[(Index)].EthSwtDrvApiIdxOfEthSwt)
#define EthIf_GetEthSwtPortInEthSwtContextEndIdxOfEthSwt(Index)                                     (EthIf_GetEthSwtOfPCConfig()[(Index)].EthSwtPortInEthSwtContextEndIdxOfEthSwt)
#define EthIf_GetEthSwtPortInEthSwtContextStartIdxOfEthSwt(Index)                                   (EthIf_GetEthSwtOfPCConfig()[(Index)].EthSwtPortInEthSwtContextStartIdxOfEthSwt)
#define EthIf_GetSnvOfEthSwt(Index)                                                                 (EthIf_GetEthSwtOfPCConfig()[(Index)].SnvOfEthSwt)
#define EthIf_GetEthSwtEndIdxOfEthSwtDrv(Index)                                                     (EthIf_GetEthSwtDrvOfPCConfig()[(Index)].EthSwtEndIdxOfEthSwtDrv)
#define EthIf_GetEthSwtStartIdxOfEthSwtDrv(Index)                                                   (EthIf_GetEthSwtDrvOfPCConfig()[(Index)].EthSwtStartIdxOfEthSwtDrv)
#define EthIf_GetEnableVlanOfEthSwtDrvApi(Index)                                                    (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].EnableVlanOfEthSwtDrvApi)
#define EthIf_GetGetArlTableOfEthSwtDrvApi(Index)                                                   (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetArlTableOfEthSwtDrvApi)
#define EthIf_GetGetBaudRateOfEthSwtDrvApi(Index)                                                   (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetBaudRateOfEthSwtDrvApi)
#define EthIf_GetGetBufferLevelOfEthSwtDrvApi(Index)                                                (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetBufferLevelOfEthSwtDrvApi)
#define EthIf_GetGetDropCountOfEthSwtDrvApi(Index)                                                  (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetDropCountOfEthSwtDrvApi)
#define EthIf_GetGetDuplexModeOfEthSwtDrvApi(Index)                                                 (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetDuplexModeOfEthSwtDrvApi)
#define EthIf_GetGetLinkStateOfEthSwtDrvApi(Index)                                                  (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetLinkStateOfEthSwtDrvApi)
#define EthIf_GetGetMacLearningModeOfEthSwtDrvApi(Index)                                            (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetMacLearningModeOfEthSwtDrvApi)
#define EthIf_GetGetPortCableDiagnosticsResultOfEthSwtDrvApi(Index)                                 (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetPortCableDiagnosticsResultOfEthSwtDrvApi)
#define EthIf_GetGetPortMacAddrOfEthSwtDrvApi(Index)                                                (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetPortMacAddrOfEthSwtDrvApi)
#define EthIf_GetGetPortSignalQualityOfEthSwtDrvApi(Index)                                          (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetPortSignalQualityOfEthSwtDrvApi)
#define EthIf_GetGetRxMgmtObjectOfEthSwtDrvApi(Index)                                               (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetRxMgmtObjectOfEthSwtDrvApi)
#define EthIf_GetGetSwtPortModeOfEthSwtDrvApi(Index)                                                (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetSwtPortModeOfEthSwtDrvApi)
#define EthIf_GetGetTxMgmtObjectOfEthSwtDrvApi(Index)                                               (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].GetTxMgmtObjectOfEthSwtDrvApi)
#define EthIf_GetPortEnableTimeStampOfEthSwtDrvApi(Index)                                           (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].PortEnableTimeStampOfEthSwtDrvApi)
#define EthIf_GetResetConfigOfEthSwtDrvApi(Index)                                                   (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].ResetConfigOfEthSwtDrvApi)
#define EthIf_GetRunPortCableDiagnosticOfEthSwtDrvApi(Index)                                        (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].RunPortCableDiagnosticOfEthSwtDrvApi)
#define EthIf_GetSetCorrectionTimeOfEthSwtDrvApi(Index)                                             (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].SetCorrectionTimeOfEthSwtDrvApi)
#define EthIf_GetSetMacLearningModeOfEthSwtDrvApi(Index)                                            (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].SetMacLearningModeOfEthSwtDrvApi)
#define EthIf_GetSetSwtMgmtInfoOfEthSwtDrvApi(Index)                                                (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].SetSwtMgmtInfoOfEthSwtDrvApi)
#define EthIf_GetSetSwtPortModeOfEthSwtDrvApi(Index)                                                (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].SetSwtPortModeOfEthSwtDrvApi)
#define EthIf_GetStartQbvScheduleOfEthSwtDrvApi(Index)                                              (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].StartQbvScheduleOfEthSwtDrvApi)
#define EthIf_GetStartSwtPortAutoNegOfEthSwtDrvApi(Index)                                           (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].StartSwtPortAutoNegOfEthSwtDrvApi)
#define EthIf_GetStopQbvScheduleOfEthSwtDrvApi(Index)                                               (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].StopQbvScheduleOfEthSwtDrvApi)
#define EthIf_GetStoreConfigOfEthSwtDrvApi(Index)                                                   (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].StoreConfigOfEthSwtDrvApi)
#define EthIf_GetSwtInitOfEthSwtDrvApi(Index)                                                       (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].SwtInitOfEthSwtDrvApi)
#define EthIf_GetUpdateMCastPortAssignmentOfEthSwtDrvApi(Index)                                     (EthIf_GetEthSwtDrvApiOfPCConfig()[(Index)].UpdateMCastPortAssignmentOfEthSwtDrvApi)
#define EthIf_GetEthSwtInd(Index)                                                                   (EthIf_GetEthSwtIndOfPCConfig()[(Index)])
#define EthIf_GetEthSwtInitCnt(Index)                                                               (EthIf_GetEthSwtInitCntOfPCConfig()[(Index)])
#define EthIf_GetEthSwtIdxOfEthSwtPort(Index)                                                       (EthIf_GetEthSwtPortOfPCConfig()[(Index)].EthSwtIdxOfEthSwtPort)
#define EthIf_GetEthSwtPortHostOrUpLinkPortIdxOfEthSwtPort(Index)                                   (EthIf_GetEthSwtPortOfPCConfig()[(Index)].EthSwtPortHostOrUpLinkPortIdxOfEthSwtPort)
#define EthIf_IsMacSecSecuredOfEthSwtPort(Index)                                                    ((EthIf_GetEthSwtPortOfPCConfig()[(Index)].MacSecSecuredOfEthSwtPort) != FALSE)
#define EthIf_GetMkaPaeIdxOfEthSwtPort(Index)                                                       (EthIf_GetEthSwtPortOfPCConfig()[(Index)].MkaPaeIdxOfEthSwtPort)
#define EthIf_GetPortGroupIndEndIdxOfEthSwtPort(Index)                                              (EthIf_GetEthSwtPortOfPCConfig()[(Index)].PortGroupIndEndIdxOfEthSwtPort)
#define EthIf_GetPortGroupIndStartIdxOfEthSwtPort(Index)                                            (EthIf_GetEthSwtPortOfPCConfig()[(Index)].PortGroupIndStartIdxOfEthSwtPort)
#define EthIf_GetPortRoleOfEthSwtPort(Index)                                                        (EthIf_GetEthSwtPortOfPCConfig()[(Index)].PortRoleOfEthSwtPort)
#define EthIf_GetSnvOfEthSwtPort(Index)                                                             (EthIf_GetEthSwtPortOfPCConfig()[(Index)].SnvOfEthSwtPort)
#define EthIf_GetEthSwtPortIdxOfEthSwtPortInEthSwtContext(Index)                                    (EthIf_GetEthSwtPortInEthSwtContextOfPCConfig()[(Index)].EthSwtPortIdxOfEthSwtPortInEthSwtContext)
#define EthIf_GetEthSwtPortInd(Index)                                                               (EthIf_GetEthSwtPortIndOfPCConfig()[(Index)])
#define EthIf_GetEthSwtPortLinkState(Index)                                                         (EthIf_GetEthSwtPortLinkStateOfPCConfig()[(Index)])
#define EthIf_GetEthSwtPortModeCnt(Index)                                                           (EthIf_GetEthSwtPortModeCntOfPCConfig()[(Index)])
#define EthIf_GetEthIfCtrlOfEthTrcvIndEndIdxOfEthTrcv(Index)                                        (EthIf_GetEthTrcvOfPCConfig()[(Index)].EthIfCtrlOfEthTrcvIndEndIdxOfEthTrcv)
#define EthIf_GetEthIfCtrlOfEthTrcvIndStartIdxOfEthTrcv(Index)                                      (EthIf_GetEthTrcvOfPCConfig()[(Index)].EthIfCtrlOfEthTrcvIndStartIdxOfEthTrcv)
#define EthIf_GetEthTrcvDrvApiIdxOfEthTrcv(Index)                                                   (EthIf_GetEthTrcvOfPCConfig()[(Index)].EthTrcvDrvApiIdxOfEthTrcv)
#define EthIf_IsMacSecSecuredOfEthTrcv(Index)                                                       ((EthIf_GetEthTrcvOfPCConfig()[(Index)].MacSecSecuredOfEthTrcv) != FALSE)
#define EthIf_GetMkaPaeIdxOfEthTrcv(Index)                                                          (EthIf_GetEthTrcvOfPCConfig()[(Index)].MkaPaeIdxOfEthTrcv)
#define EthIf_GetSnvOfEthTrcv(Index)                                                                (EthIf_GetEthTrcvOfPCConfig()[(Index)].SnvOfEthTrcv)
#define EthIf_GetCheckWakeupOfEthTrcvDrvApi(Index)                                                  (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].CheckWakeupOfEthTrcvDrvApi)
#define EthIf_GetGetBaudRateOfEthTrcvDrvApi(Index)                                                  (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].GetBaudRateOfEthTrcvDrvApi)
#define EthIf_GetGetCableDiagnosticsResultOfEthTrcvDrvApi(Index)                                    (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].GetCableDiagnosticsResultOfEthTrcvDrvApi)
#define EthIf_GetGetDuplexModeOfEthTrcvDrvApi(Index)                                                (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].GetDuplexModeOfEthTrcvDrvApi)
#define EthIf_GetGetLinkStateOfEthTrcvDrvApi(Index)                                                 (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].GetLinkStateOfEthTrcvDrvApi)
#define EthIf_GetGetPhySignalQualityOfEthTrcvDrvApi(Index)                                          (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].GetPhySignalQualityOfEthTrcvDrvApi)
#define EthIf_GetGetTrcvModeOfEthTrcvDrvApi(Index)                                                  (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].GetTrcvModeOfEthTrcvDrvApi)
#define EthIf_GetGetTrcvWakeupModeOfEthTrcvDrvApi(Index)                                            (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].GetTrcvWakeupModeOfEthTrcvDrvApi)
#define EthIf_GetRunCableDiagnosticOfEthTrcvDrvApi(Index)                                           (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].RunCableDiagnosticOfEthTrcvDrvApi)
#define EthIf_GetSetPhyLoopbackModeOfEthTrcvDrvApi(Index)                                           (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].SetPhyLoopbackModeOfEthTrcvDrvApi)
#define EthIf_GetSetPhyTestModeOfEthTrcvDrvApi(Index)                                               (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].SetPhyTestModeOfEthTrcvDrvApi)
#define EthIf_GetSetPhyTxModeOfEthTrcvDrvApi(Index)                                                 (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].SetPhyTxModeOfEthTrcvDrvApi)
#define EthIf_GetSetTrcvModeOfEthTrcvDrvApi(Index)                                                  (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].SetTrcvModeOfEthTrcvDrvApi)
#define EthIf_GetSetTrcvWakeupModeOfEthTrcvDrvApi(Index)                                            (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].SetTrcvWakeupModeOfEthTrcvDrvApi)
#define EthIf_GetStartAutoNegOfEthTrcvDrvApi(Index)                                                 (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].StartAutoNegOfEthTrcvDrvApi)
#define EthIf_GetTrcvInitOfEthTrcvDrvApi(Index)                                                     (EthIf_GetEthTrcvDrvApiOfPCConfig()[(Index)].TrcvInitOfEthTrcvDrvApi)
#define EthIf_GetEthTrcvInitCnt(Index)                                                              (EthIf_GetEthTrcvInitCntOfPCConfig()[(Index)])
#define EthIf_GetEthTrcvLinkState(Index)                                                            (EthIf_GetEthTrcvLinkStateOfPCConfig()[(Index)])
#define EthIf_GetEthTrcvModeCnt(Index)                                                              (EthIf_GetEthTrcvModeCntOfPCConfig()[(Index)])
#define EthIf_GetEthTrcvState(Index)                                                                (EthIf_GetEthTrcvStateOfPCConfig()[(Index)])
#define EthIf_GetEthIfCtrlIdxOfExplicitBufReleaseFilter(Index)                                      (EthIf_GetExplicitBufReleaseFilterOfPCConfig()[(Index)].EthIfCtrlIdxOfExplicitBufReleaseFilter)
#define EthIf_GetUserIdxOfExplicitBufReleaseFilter(Index)                                           (EthIf_GetExplicitBufReleaseFilterOfPCConfig()[(Index)].UserIdxOfExplicitBufReleaseFilter)
#define EthIf_GetMacAddrOfGatewaySrcMacBlackList(Index)                                             (EthIf_GetGatewaySrcMacBlackListOfPCConfig()[(Index)].MacAddrOfGatewaySrcMacBlackList)
#define EthIf_IsInitLocked()                                                                        (((*(EthIf_GetInitLockedOfPCConfig()))) != FALSE)
#define EthIf_GetLinkStateChgIndications(Index)                                                     (EthIf_GetLinkStateChgIndicationsOfPCConfig()[(Index)])
#define EthIf_GetMainFuncStateDecoupleFreqCnt()                                                     ((*(EthIf_GetMainFuncStateDecoupleFreqCntOfPCConfig())))
#define EthIf_GetEthCtrlIdxOfMirrorDest(Index)                                                      (EthIf_GetMirrorDestOfPCConfig()[(Index)].EthCtrlIdxOfMirrorDest)
#define EthIf_IsKeepSrcMacEnabledOfMirrorDest(Index)                                                ((EthIf_GetMirrorDestOfPCConfig()[(Index)].KeepSrcMacEnabledOfMirrorDest) != FALSE)
#define EthIf_GetDestEthTxBufferIdxOfMirrorTxInfo(Index)                                            (EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].DestEthTxBufferIdxOfMirrorTxInfo)
#define EthIf_GetDestPayloadPtrOfMirrorTxInfo(Index)                                                (EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].DestPayloadPtrOfMirrorTxInfo)
#define EthIf_GetEthIfCtrlIdxOfMirrorTxInfo(Index)                                                  (EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].EthIfCtrlIdxOfMirrorTxInfo)
#define EthIf_IsInfoValidOfMirrorTxInfo(Index)                                                      ((EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].InfoValidOfMirrorTxInfo) != FALSE)
#define EthIf_GetSrcEthTxBufferIdxOfMirrorTxInfo(Index)                                             (EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].SrcEthTxBufferIdxOfMirrorTxInfo)
#define EthIf_GetSrcPayloadPtrOfMirrorTxInfo(Index)                                                 (EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].SrcPayloadPtrOfMirrorTxInfo)
#define EthIf_IsUsedOfMirrorTxInfo(Index)                                                           ((EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].UsedOfMirrorTxInfo) != FALSE)
#define EthIf_IsModeChangeLocked()                                                                  (((*(EthIf_GetModeChangeLockedOfPCConfig()))) != FALSE)
#define EthIf_GetEthSwtIndEndIdxOfPhysLayerInitElems(Index)                                         (EthIf_GetPhysLayerInitElemsOfPCConfig()[(Index)].EthSwtIndEndIdxOfPhysLayerInitElems)
#define EthIf_GetEthSwtIndStartIdxOfPhysLayerInitElems(Index)                                       (EthIf_GetPhysLayerInitElemsOfPCConfig()[(Index)].EthSwtIndStartIdxOfPhysLayerInitElems)
#define EthIf_GetEthTrcvIdxOfPhysLayerInitElems(Index)                                              (EthIf_GetPhysLayerInitElemsOfPCConfig()[(Index)].EthTrcvIdxOfPhysLayerInitElems)
#define EthIf_GetEthTrcvIdxOfPhysLayerModeElems(Index)                                              (EthIf_GetPhysLayerModeElemsOfPCConfig()[(Index)].EthTrcvIdxOfPhysLayerModeElems)
#define EthIf_GetPortGroupIdxOfPhysLayerModeElems(Index)                                            (EthIf_GetPhysLayerModeElemsOfPCConfig()[(Index)].PortGroupIdxOfPhysLayerModeElems)
#define EthIf_GetEthIfCtrlOfPortGroupIndEndIdxOfPortGroup(Index)                                    (EthIf_GetPortGroupOfPCConfig()[(Index)].EthIfCtrlOfPortGroupIndEndIdxOfPortGroup)
#define EthIf_GetEthIfCtrlOfPortGroupIndStartIdxOfPortGroup(Index)                                  (EthIf_GetPortGroupOfPCConfig()[(Index)].EthIfCtrlOfPortGroupIndStartIdxOfPortGroup)
#define EthIf_GetEthSwtPortIndEndIdxOfPortGroup(Index)                                              (EthIf_GetPortGroupOfPCConfig()[(Index)].EthSwtPortIndEndIdxOfPortGroup)
#define EthIf_GetEthSwtPortIndStartIdxOfPortGroup(Index)                                            (EthIf_GetPortGroupOfPCConfig()[(Index)].EthSwtPortIndStartIdxOfPortGroup)
#define EthIf_GetHostAndUpLinkPortThresholdOfPortGroup(Index)                                       (EthIf_GetPortGroupOfPCConfig()[(Index)].HostAndUpLinkPortThresholdOfPortGroup)
#define EthIf_IsLaxLinkAggregationEnabledOfPortGroup(Index)                                         ((EthIf_GetPortGroupOfPCConfig()[(Index)].LaxLinkAggregationEnabledOfPortGroup) != FALSE)
#define EthIf_GetLinkAggrThresholdOfPortGroup(Index)                                                (EthIf_GetPortGroupOfPCConfig()[(Index)].LinkAggrThresholdOfPortGroup)
#define EthIf_GetNoRolePortThresholdOfPortGroup(Index)                                              (EthIf_GetPortGroupOfPCConfig()[(Index)].NoRolePortThresholdOfPortGroup)
#define EthIf_GetSemanticOfPortGroup(Index)                                                         (EthIf_GetPortGroupOfPCConfig()[(Index)].SemanticOfPortGroup)
#define EthIf_GetSnvOfPortGroup(Index)                                                              (EthIf_GetPortGroupOfPCConfig()[(Index)].SnvOfPortGroup)
#define EthIf_GetPortGroupHostOrUpLinkPortRoleLinkCount(Index)                                      (EthIf_GetPortGroupHostOrUpLinkPortRoleLinkCountOfPCConfig()[(Index)])
#define EthIf_GetPortGroupInd(Index)                                                                (EthIf_GetPortGroupIndOfPCConfig()[(Index)])
#define EthIf_GetPortGroupLaxLinkAggregationCount(Index)                                            (EthIf_GetPortGroupLaxLinkAggregationCountOfPCConfig()[(Index)])
#define EthIf_GetPortGroupLinkState(Index)                                                          (EthIf_GetPortGroupLinkStateOfPCConfig()[(Index)])
#define EthIf_GetPortGroupMode(Index)                                                               (EthIf_GetPortGroupModeOfPCConfig()[(Index)])
#define EthIf_GetPortGroupNoRoleLinkCount(Index)                                                    (EthIf_GetPortGroupNoRoleLinkCountOfPCConfig()[(Index)])
#define EthIf_GetPortSignalQualityResult(Index)                                                     (EthIf_GetPortSignalQualityResultOfPCConfig()[(Index)])
#define EthIf_GetPortStartupActiveTimeCounter()                                                     ((*(EthIf_GetPortStartupActiveTimeCounterOfPCConfig())))
#define EthIf_IsPortStartupActiveTimerActive()                                                      (((*(EthIf_GetPortStartupActiveTimerActiveOfPCConfig()))) != FALSE)
#define EthIf_GetRxIndications(Index)                                                               (EthIf_GetRxIndicationsOfPCConfig()[(Index)])
#define EthIf_GetRxIndicationsInd(Index)                                                            (EthIf_GetRxIndicationsIndOfPCConfig()[(Index)])
#define EthIf_GetSignalQualityDecoupleFreqCnt()                                                     ((*(EthIf_GetSignalQualityDecoupleFreqCntOfPCConfig())))
#define EthIf_GetSignalQualityResult(Index)                                                         (EthIf_GetSignalQualityResultOfPCConfig()[(Index)])
#define EthIf_GetSrcMacOfSrcMacAddrBuffer(Index)                                                    (EthIf_GetSrcMacAddrBufferOfPCConfig()[(Index)].SrcMacOfSrcMacAddrBuffer)
#define EthIf_IsValidOfSrcMacAddrBuffer(Index)                                                      ((EthIf_GetSrcMacAddrBufferOfPCConfig()[(Index)].ValidOfSrcMacAddrBuffer) != FALSE)
#define EthIf_GetTxConfirmations(Index)                                                             (EthIf_GetTxConfirmationsOfPCConfig()[(Index)])
#define EthIf_GetTxConfirmationsInd(Index)                                                          (EthIf_GetTxConfirmationsIndOfPCConfig()[(Index)])
#define EthIf_GetEthIfCtrlIdxOfTxContext(Index)                                                     (EthIf_GetTxContextOfPCConfig()[(Index)].EthIfCtrlIdxOfTxContext)
#define EthIf_GetFrameHdrOfTxContext(Index)                                                         (EthIf_GetTxContextOfPCConfig()[(Index)].FrameHdrOfTxContext)
#define EthIf_GetPayloadLenOfTxContext(Index)                                                       (EthIf_GetTxContextOfPCConfig()[(Index)].PayloadLenOfTxContext)
#define EthIf_GetPayloadPtrOfTxContext(Index)                                                       (EthIf_GetTxContextOfPCConfig()[(Index)].PayloadPtrOfTxContext)
#define EthIf_IsTxPendingOfTxContext(Index)                                                         ((EthIf_GetTxContextOfPCConfig()[(Index)].TxPendingOfTxContext) != FALSE)
#define EthIf_GetUserIdxOfTxContext(Index)                                                          (EthIf_GetTxContextOfPCConfig()[(Index)].UserIdxOfTxContext)
#define EthIf_IsValidOfTxContext(Index)                                                             ((EthIf_GetTxContextOfPCConfig()[(Index)].ValidOfTxContext) != FALSE)
#define EthIf_GetEtherTypeOfUser(Index)                                                             (EthIf_GetUserOfPCConfig()[(Index)].EtherTypeOfUser)
#define EthIf_GetRxIndicationsIndEndIdxOfUser(Index)                                                (EthIf_GetUserOfPCConfig()[(Index)].RxIndicationsIndEndIdxOfUser)
#define EthIf_GetRxIndicationsIndStartIdxOfUser(Index)                                              (EthIf_GetUserOfPCConfig()[(Index)].RxIndicationsIndStartIdxOfUser)
#define EthIf_GetTxConfirmationsIndEndIdxOfUser(Index)                                              (EthIf_GetUserOfPCConfig()[(Index)].TxConfirmationsIndEndIdxOfUser)
#define EthIf_GetTxConfirmationsIndStartIdxOfUser(Index)                                            (EthIf_GetUserOfPCConfig()[(Index)].TxConfirmationsIndStartIdxOfUser)
#define EthIf_GetEthTrcvIdxOfWakeupMap(Index)                                                       (EthIf_GetWakeupMapOfPCConfig()[(Index)].EthTrcvIdxOfWakeupMap)
#define EthIf_GetWakeupSourceOfWakeupMap(Index)                                                     (EthIf_GetWakeupMapOfPCConfig()[(Index)].WakeupSourceOfWakeupMap)
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCGetDeduplicatedDataMacros  EthIf Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define EthIf_IsEthSwtDrvApiUsedOfEthIfCtrl(Index)                                                  (((boolean)(EthIf_GetEthSwtDrvApiIdxOfEthIfCtrl(Index) != ETHIF_NO_ETHSWTDRVAPIIDXOFETHIFCTRL)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_EthSwtDrvApi */
#define EthIf_IsGatewayDestEthIfCtrlIdxUsedOfEthIfCtrl(Index)                                       (((boolean)(EthIf_GetGatewayDestEthIfCtrlIdxIdxOfEthIfCtrl(Index) != ETHIF_NO_GATEWAYDESTETHIFCTRLIDXIDXOFETHIFCTRL)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_EthIfCtrl */
#define EthIf_IsMirrorRxDestIdxUsedOfEthIfCtrl(Index)                                               (((boolean)(EthIf_GetMirrorRxDestIdxIdxOfEthIfCtrl(Index) != ETHIF_NO_MIRRORRXDESTIDXIDXOFETHIFCTRL)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_MirrorDest */
#define EthIf_IsMirrorTxDestIdxUsedOfEthIfCtrl(Index)                                               (((boolean)(EthIf_GetMirrorTxDestIdxIdxOfEthIfCtrl(Index) != ETHIF_NO_MIRRORTXDESTIDXIDXOFETHIFCTRL)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_MirrorDest */
#define EthIf_IsEthIfClkUnitUsedOfEthIfPhysCtrlCfg(Index)                                           (((boolean)(EthIf_GetEthIfClkUnitStartIdxOfEthIfPhysCtrlCfg(Index) != ETHIF_NO_ETHIFCLKUNITSTARTIDXOFETHIFPHYSCTRLCFG)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_EthIfClkUnit */
#define EthIf_IsEthSwtPortInEthSwtContextUsedOfEthSwt(Index)                                        (((boolean)(EthIf_GetEthSwtPortInEthSwtContextStartIdxOfEthSwt(Index) != ETHIF_NO_ETHSWTPORTINETHSWTCONTEXTSTARTIDXOFETHSWT)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_EthSwtPortInEthSwtContext */
#define EthIf_IsEthSwtPortUsedOfEthSwtPortInEthSwtContext(Index)                                    (((boolean)(EthIf_GetEthSwtPortIdxOfEthSwtPortInEthSwtContext(Index) != ETHIF_NO_ETHSWTPORTIDXOFETHSWTPORTINETHSWTCONTEXT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_EthSwtPort */
#define EthIf_IsEthIfCtrlOfEthTrcvIndUsedOfEthTrcv(Index)                                           (((boolean)(EthIf_GetEthIfCtrlOfEthTrcvIndStartIdxOfEthTrcv(Index) != ETHIF_NO_ETHIFCTRLOFETHTRCVINDSTARTIDXOFETHTRCV)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_EthIfCtrlOfEthTrcvInd */
#define EthIf_IsUserUsedOfExplicitBufReleaseFilter(Index)                                           (((boolean)(EthIf_GetUserIdxOfExplicitBufReleaseFilter(Index) != ETHIF_NO_USERIDXOFEXPLICITBUFRELEASEFILTER)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_User */
#define EthIf_GetLinkStateChgMainReload()                                                           EthIf_GetLinkStateChgMainReloadOfPCConfig()
#define EthIf_GetMaxFrameRxPerEthCtrl()                                                             EthIf_GetMaxFrameRxPerEthCtrlOfPCConfig()
#define EthIf_GetMaxTxBufPerEthCtrl()                                                               EthIf_GetMaxTxBufPerEthCtrlOfPCConfig()
#define EthIf_IsEthSwtIndUsedOfPhysLayerInitElems(Index)                                            (((boolean)(EthIf_GetEthSwtIndStartIdxOfPhysLayerInitElems(Index) != ETHIF_NO_ETHSWTINDSTARTIDXOFPHYSLAYERINITELEMS)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_EthSwtInd */
#define EthIf_IsEthTrcvUsedOfPhysLayerInitElems(Index)                                              (((boolean)(EthIf_GetEthTrcvIdxOfPhysLayerInitElems(Index) != ETHIF_NO_ETHTRCVIDXOFPHYSLAYERINITELEMS)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_EthTrcv */
#define EthIf_IsEthTrcvUsedOfPhysLayerModeElems(Index)                                              (((boolean)(EthIf_GetEthTrcvIdxOfPhysLayerModeElems(Index) != ETHIF_NO_ETHTRCVIDXOFPHYSLAYERMODEELEMS)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_EthTrcv */
#define EthIf_IsPortGroupUsedOfPhysLayerModeElems(Index)                                            (((boolean)(EthIf_GetPortGroupIdxOfPhysLayerModeElems(Index) != ETHIF_NO_PORTGROUPIDXOFPHYSLAYERMODEELEMS)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthIf_PortGroup */
#define EthIf_IsEthIfCtrlOfPortGroupIndUsedOfPortGroup(Index)                                       (((boolean)(EthIf_GetEthIfCtrlOfPortGroupIndStartIdxOfPortGroup(Index) != ETHIF_NO_ETHIFCTRLOFPORTGROUPINDSTARTIDXOFPORTGROUP)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_EthIfCtrlOfPortGroupInd */
#define EthIf_GetPortStartupActiveTimeFreq()                                                        EthIf_GetPortStartupActiveTimeFreqOfPCConfig()
#define EthIf_GetSignalQualityChgMainReload()                                                       EthIf_GetSignalQualityChgMainReloadOfPCConfig()
#define EthIf_GetSizeOfEthCtrl()                                                                    EthIf_GetSizeOfEthCtrlOfPCConfig()
#define EthIf_GetSizeOfEthCtrlInitCnt()                                                             EthIf_GetSizeOfEthCtrlInitCntOfPCConfig()
#define EthIf_GetSizeOfEthCtrlModeCnt()                                                             EthIf_GetSizeOfEthCtrlModeCntOfPCConfig()
#define EthIf_GetSizeOfEthCtrlRxFrameCnt()                                                          EthIf_GetSizeOfEthCtrlRxFrameCntOfPCConfig()
#define EthIf_GetSizeOfEthCtrlState()                                                               EthIf_GetSizeOfEthCtrlStateOfPCConfig()
#define EthIf_GetSizeOfEthDrvApi()                                                                  EthIf_GetSizeOfEthDrvApiOfPCConfig()
#define EthIf_GetSizeOfEthIfClkUnit()                                                               EthIf_GetSizeOfEthIfClkUnitOfPCConfig()
#define EthIf_GetSizeOfEthIfCtrl()                                                                  EthIf_GetSizeOfEthIfCtrlOfPCConfig()
#define EthIf_GetSizeOfEthIfCtrlInitState()                                                         EthIf_GetSizeOfEthIfCtrlInitStateOfPCConfig()
#define EthIf_GetSizeOfEthIfCtrlLinkCount()                                                         EthIf_GetSizeOfEthIfCtrlLinkCountOfPCConfig()
#define EthIf_GetSizeOfEthIfCtrlLinkState()                                                         EthIf_GetSizeOfEthIfCtrlLinkStateOfPCConfig()
#define EthIf_GetSizeOfEthIfCtrlMode()                                                              EthIf_GetSizeOfEthIfCtrlModeOfPCConfig()
#define EthIf_GetSizeOfEthIfCtrlOfEthTrcvInd()                                                      EthIf_GetSizeOfEthIfCtrlOfEthTrcvIndOfPCConfig()
#define EthIf_GetSizeOfEthIfCtrlOfPortGroupInd()                                                    EthIf_GetSizeOfEthIfCtrlOfPortGroupIndOfPCConfig()
#define EthIf_GetSizeOfEthIfCtrlRxStats()                                                           EthIf_GetSizeOfEthIfCtrlRxStatsOfPCConfig()
#define EthIf_GetSizeOfEthIfCtrlTxStats()                                                           EthIf_GetSizeOfEthIfCtrlTxStatsOfPCConfig()
#define EthIf_GetSizeOfEthIfMeasurementData()                                                       EthIf_GetSizeOfEthIfMeasurementDataOfPCConfig()
#define EthIf_GetSizeOfEthIfPhysCtrlCfg()                                                           EthIf_GetSizeOfEthIfPhysCtrlCfgOfPCConfig()
#define EthIf_GetSizeOfEthIfSwtPortGroupState()                                                     EthIf_GetSizeOfEthIfSwtPortGroupStateOfPCConfig()
#define EthIf_GetSizeOfEthSwt()                                                                     EthIf_GetSizeOfEthSwtOfPCConfig()
#define EthIf_GetSizeOfEthSwtDrv()                                                                  EthIf_GetSizeOfEthSwtDrvOfPCConfig()
#define EthIf_GetSizeOfEthSwtDrvApi()                                                               EthIf_GetSizeOfEthSwtDrvApiOfPCConfig()
#define EthIf_GetSizeOfEthSwtInd()                                                                  EthIf_GetSizeOfEthSwtIndOfPCConfig()
#define EthIf_GetSizeOfEthSwtInitCnt()                                                              EthIf_GetSizeOfEthSwtInitCntOfPCConfig()
#define EthIf_GetSizeOfEthSwtPort()                                                                 EthIf_GetSizeOfEthSwtPortOfPCConfig()
#define EthIf_GetSizeOfEthSwtPortInEthSwtContext()                                                  EthIf_GetSizeOfEthSwtPortInEthSwtContextOfPCConfig()
#define EthIf_GetSizeOfEthSwtPortInd()                                                              EthIf_GetSizeOfEthSwtPortIndOfPCConfig()
#define EthIf_GetSizeOfEthSwtPortLinkState()                                                        EthIf_GetSizeOfEthSwtPortLinkStateOfPCConfig()
#define EthIf_GetSizeOfEthSwtPortModeCnt()                                                          EthIf_GetSizeOfEthSwtPortModeCntOfPCConfig()
#define EthIf_GetSizeOfEthTrcv()                                                                    EthIf_GetSizeOfEthTrcvOfPCConfig()
#define EthIf_GetSizeOfEthTrcvDrvApi()                                                              EthIf_GetSizeOfEthTrcvDrvApiOfPCConfig()
#define EthIf_GetSizeOfEthTrcvInitCnt()                                                             EthIf_GetSizeOfEthTrcvInitCntOfPCConfig()
#define EthIf_GetSizeOfEthTrcvLinkState()                                                           EthIf_GetSizeOfEthTrcvLinkStateOfPCConfig()
#define EthIf_GetSizeOfEthTrcvModeCnt()                                                             EthIf_GetSizeOfEthTrcvModeCntOfPCConfig()
#define EthIf_GetSizeOfEthTrcvState()                                                               EthIf_GetSizeOfEthTrcvStateOfPCConfig()
#define EthIf_GetSizeOfExplicitBufReleaseFilter()                                                   EthIf_GetSizeOfExplicitBufReleaseFilterOfPCConfig()
#define EthIf_GetSizeOfGatewaySrcMacBlackList()                                                     EthIf_GetSizeOfGatewaySrcMacBlackListOfPCConfig()
#define EthIf_GetSizeOfLinkStateChgIndications()                                                    EthIf_GetSizeOfLinkStateChgIndicationsOfPCConfig()
#define EthIf_GetSizeOfMirrorDest()                                                                 EthIf_GetSizeOfMirrorDestOfPCConfig()
#define EthIf_GetSizeOfMirrorTxInfo()                                                               EthIf_GetSizeOfMirrorTxInfoOfPCConfig()
#define EthIf_GetSizeOfPhysLayerInitElems()                                                         EthIf_GetSizeOfPhysLayerInitElemsOfPCConfig()
#define EthIf_GetSizeOfPhysLayerModeElems()                                                         EthIf_GetSizeOfPhysLayerModeElemsOfPCConfig()
#define EthIf_GetSizeOfPortGroup()                                                                  EthIf_GetSizeOfPortGroupOfPCConfig()
#define EthIf_GetSizeOfPortGroupHostOrUpLinkPortRoleLinkCount()                                     EthIf_GetSizeOfPortGroupHostOrUpLinkPortRoleLinkCountOfPCConfig()
#define EthIf_GetSizeOfPortGroupInd()                                                               EthIf_GetSizeOfPortGroupIndOfPCConfig()
#define EthIf_GetSizeOfPortGroupLaxLinkAggregationCount()                                           EthIf_GetSizeOfPortGroupLaxLinkAggregationCountOfPCConfig()
#define EthIf_GetSizeOfPortGroupLinkState()                                                         EthIf_GetSizeOfPortGroupLinkStateOfPCConfig()
#define EthIf_GetSizeOfPortGroupMode()                                                              EthIf_GetSizeOfPortGroupModeOfPCConfig()
#define EthIf_GetSizeOfPortGroupNoRoleLinkCount()                                                   EthIf_GetSizeOfPortGroupNoRoleLinkCountOfPCConfig()
#define EthIf_GetSizeOfPortSignalQualityResult()                                                    EthIf_GetSizeOfPortSignalQualityResultOfPCConfig()
#define EthIf_GetSizeOfRxIndications()                                                              EthIf_GetSizeOfRxIndicationsOfPCConfig()
#define EthIf_GetSizeOfRxIndicationsInd()                                                           EthIf_GetSizeOfRxIndicationsIndOfPCConfig()
#define EthIf_GetSizeOfSignalQualityResult()                                                        EthIf_GetSizeOfSignalQualityResultOfPCConfig()
#define EthIf_GetSizeOfSrcMacAddrBuffer()                                                           EthIf_GetSizeOfSrcMacAddrBufferOfPCConfig()
#define EthIf_GetSizeOfTxConfirmations()                                                            EthIf_GetSizeOfTxConfirmationsOfPCConfig()
#define EthIf_GetSizeOfTxConfirmationsInd()                                                         EthIf_GetSizeOfTxConfirmationsIndOfPCConfig()
#define EthIf_GetSizeOfTxContext()                                                                  EthIf_GetSizeOfTxContextOfPCConfig()
#define EthIf_GetSizeOfUser()                                                                       EthIf_GetSizeOfUserOfPCConfig()
#define EthIf_GetSizeOfWakeupMap()                                                                  EthIf_GetSizeOfWakeupMapOfPCConfig()
#define EthIf_IsRxIndicationsIndUsedOfUser(Index)                                                   (((boolean)(EthIf_GetRxIndicationsIndStartIdxOfUser(Index) != ETHIF_NO_RXINDICATIONSINDSTARTIDXOFUSER)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_RxIndicationsInd */
#define EthIf_IsTxConfirmationsIndUsedOfUser(Index)                                                 (((boolean)(EthIf_GetTxConfirmationsIndStartIdxOfUser(Index) != ETHIF_NO_TXCONFIRMATIONSINDSTARTIDXOFUSER)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthIf_TxConfirmationsInd */
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCSetDataMacros  EthIf Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define EthIf_SetEthCtrlInitCnt(Index, Value)                                                       EthIf_GetEthCtrlInitCntOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthCtrlModeCnt(Index, Value)                                                       EthIf_GetEthCtrlModeCntOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthCtrlRxFrameCnt(Index, Value)                                                    EthIf_GetEthCtrlRxFrameCntOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthCtrlState(Index, Value)                                                         EthIf_GetEthCtrlStateOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthIfCtrlInitState(Index, Value)                                                   EthIf_GetEthIfCtrlInitStateOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthIfCtrlLinkCount(Index, Value)                                                   EthIf_GetEthIfCtrlLinkCountOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthIfCtrlLinkState(Index, Value)                                                   EthIf_GetEthIfCtrlLinkStateOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthIfCtrlMode(Index, Value)                                                        EthIf_GetEthIfCtrlModeOfPCConfig()[(Index)] = (Value)
#define EthIf_SetNumRxBytesOfEthIfCtrlRxStats(Index, Value)                                         EthIf_GetEthIfCtrlRxStatsOfPCConfig()[(Index)].NumRxBytesOfEthIfCtrlRxStats = (Value)
#define EthIf_SetNumRxPktsOfEthIfCtrlRxStats(Index, Value)                                          EthIf_GetEthIfCtrlRxStatsOfPCConfig()[(Index)].NumRxPktsOfEthIfCtrlRxStats = (Value)
#define EthIf_SetNumTxBytesOfEthIfCtrlTxStats(Index, Value)                                         EthIf_GetEthIfCtrlTxStatsOfPCConfig()[(Index)].NumTxBytesOfEthIfCtrlTxStats = (Value)
#define EthIf_SetNumTxPktsOfEthIfCtrlTxStats(Index, Value)                                          EthIf_GetEthIfCtrlTxStatsOfPCConfig()[(Index)].NumTxPktsOfEthIfCtrlTxStats = (Value)
#define EthIf_SetDropCtrlIdxOfEthIfMeasurementData(Index, Value)                                    EthIf_GetEthIfMeasurementDataOfPCConfig()[(Index)].DropCtrlIdxOfEthIfMeasurementData = (Value)
#define EthIf_SetUnknownEtherTypeOfEthIfMeasurementData(Index, Value)                               EthIf_GetEthIfMeasurementDataOfPCConfig()[(Index)].UnknownEtherTypeOfEthIfMeasurementData = (Value)
#define EthIf_SetVlanDoubleTaggedOfEthIfMeasurementData(Index, Value)                               EthIf_GetEthIfMeasurementDataOfPCConfig()[(Index)].VlanDoubleTaggedOfEthIfMeasurementData = (Value)
#define EthIf_SetEthIfSwtPortGroupState(Index, Value)                                               EthIf_GetEthIfSwtPortGroupStateOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthSwtInitCnt(Index, Value)                                                        EthIf_GetEthSwtInitCntOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthSwtPortLinkState(Index, Value)                                                  EthIf_GetEthSwtPortLinkStateOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthSwtPortModeCnt(Index, Value)                                                    EthIf_GetEthSwtPortModeCntOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthTrcvInitCnt(Index, Value)                                                       EthIf_GetEthTrcvInitCntOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthTrcvLinkState(Index, Value)                                                     EthIf_GetEthTrcvLinkStateOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthTrcvModeCnt(Index, Value)                                                       EthIf_GetEthTrcvModeCntOfPCConfig()[(Index)] = (Value)
#define EthIf_SetEthTrcvState(Index, Value)                                                         EthIf_GetEthTrcvStateOfPCConfig()[(Index)] = (Value)
#define EthIf_SetInitLocked(Value)                                                                  (*(EthIf_GetInitLockedOfPCConfig())) = (Value)
#define EthIf_SetMainFuncStateDecoupleFreqCnt(Value)                                                (*(EthIf_GetMainFuncStateDecoupleFreqCntOfPCConfig())) = (Value)
#define EthIf_SetDestEthTxBufferIdxOfMirrorTxInfo(Index, Value)                                     EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].DestEthTxBufferIdxOfMirrorTxInfo = (Value)
#define EthIf_SetDestPayloadPtrOfMirrorTxInfo(Index, Value)                                         EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].DestPayloadPtrOfMirrorTxInfo = (Value)
#define EthIf_SetEthIfCtrlIdxOfMirrorTxInfo(Index, Value)                                           EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].EthIfCtrlIdxOfMirrorTxInfo = (Value)
#define EthIf_SetInfoValidOfMirrorTxInfo(Index, Value)                                              EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].InfoValidOfMirrorTxInfo = (Value)
#define EthIf_SetSrcEthTxBufferIdxOfMirrorTxInfo(Index, Value)                                      EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].SrcEthTxBufferIdxOfMirrorTxInfo = (Value)
#define EthIf_SetSrcPayloadPtrOfMirrorTxInfo(Index, Value)                                          EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].SrcPayloadPtrOfMirrorTxInfo = (Value)
#define EthIf_SetUsedOfMirrorTxInfo(Index, Value)                                                   EthIf_GetMirrorTxInfoOfPCConfig()[(Index)].UsedOfMirrorTxInfo = (Value)
#define EthIf_SetModeChangeLocked(Value)                                                            (*(EthIf_GetModeChangeLockedOfPCConfig())) = (Value)
#define EthIf_SetPortGroupHostOrUpLinkPortRoleLinkCount(Index, Value)                               EthIf_GetPortGroupHostOrUpLinkPortRoleLinkCountOfPCConfig()[(Index)] = (Value)
#define EthIf_SetPortGroupLaxLinkAggregationCount(Index, Value)                                     EthIf_GetPortGroupLaxLinkAggregationCountOfPCConfig()[(Index)] = (Value)
#define EthIf_SetPortGroupLinkState(Index, Value)                                                   EthIf_GetPortGroupLinkStateOfPCConfig()[(Index)] = (Value)
#define EthIf_SetPortGroupMode(Index, Value)                                                        EthIf_GetPortGroupModeOfPCConfig()[(Index)] = (Value)
#define EthIf_SetPortGroupNoRoleLinkCount(Index, Value)                                             EthIf_GetPortGroupNoRoleLinkCountOfPCConfig()[(Index)] = (Value)
#define EthIf_SetPortSignalQualityResult(Index, Value)                                              EthIf_GetPortSignalQualityResultOfPCConfig()[(Index)] = (Value)
#define EthIf_SetPortStartupActiveTimeCounter(Value)                                                (*(EthIf_GetPortStartupActiveTimeCounterOfPCConfig())) = (Value)
#define EthIf_SetPortStartupActiveTimerActive(Value)                                                (*(EthIf_GetPortStartupActiveTimerActiveOfPCConfig())) = (Value)
#define EthIf_SetSignalQualityDecoupleFreqCnt(Value)                                                (*(EthIf_GetSignalQualityDecoupleFreqCntOfPCConfig())) = (Value)
#define EthIf_SetSignalQualityResult(Index, Value)                                                  EthIf_GetSignalQualityResultOfPCConfig()[(Index)] = (Value)
#define EthIf_SetSrcMacOfSrcMacAddrBuffer(Index, Value)                                             EthIf_GetSrcMacAddrBufferOfPCConfig()[(Index)].SrcMacOfSrcMacAddrBuffer = (Value)
#define EthIf_SetValidOfSrcMacAddrBuffer(Index, Value)                                              EthIf_GetSrcMacAddrBufferOfPCConfig()[(Index)].ValidOfSrcMacAddrBuffer = (Value)
#define EthIf_SetEthIfCtrlIdxOfTxContext(Index, Value)                                              EthIf_GetTxContextOfPCConfig()[(Index)].EthIfCtrlIdxOfTxContext = (Value)
#define EthIf_SetFrameHdrOfTxContext(Index, Value)                                                  EthIf_GetTxContextOfPCConfig()[(Index)].FrameHdrOfTxContext = (Value)
#define EthIf_SetPayloadLenOfTxContext(Index, Value)                                                EthIf_GetTxContextOfPCConfig()[(Index)].PayloadLenOfTxContext = (Value)
#define EthIf_SetPayloadPtrOfTxContext(Index, Value)                                                EthIf_GetTxContextOfPCConfig()[(Index)].PayloadPtrOfTxContext = (Value)
#define EthIf_SetTxPendingOfTxContext(Index, Value)                                                 EthIf_GetTxContextOfPCConfig()[(Index)].TxPendingOfTxContext = (Value)
#define EthIf_SetUserIdxOfTxContext(Index, Value)                                                   EthIf_GetTxContextOfPCConfig()[(Index)].UserIdxOfTxContext = (Value)
#define EthIf_SetValidOfTxContext(Index, Value)                                                     EthIf_GetTxContextOfPCConfig()[(Index)].ValidOfTxContext = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCGetAddressOfDataMacros  EthIf Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define EthIf_GetAddrEthCtrlInitCnt(Index)                                                          (&EthIf_GetEthCtrlInitCnt(Index))
#define EthIf_GetAddrEthCtrlModeCnt(Index)                                                          (&EthIf_GetEthCtrlModeCnt(Index))
#define EthIf_GetAddrEthCtrlRxFrameCnt(Index)                                                       (&EthIf_GetEthCtrlRxFrameCnt(Index))
#define EthIf_GetAddrEthCtrlState(Index)                                                            (&EthIf_GetEthCtrlState(Index))
#define EthIf_GetAddrEthIfCtrlInitState(Index)                                                      (&EthIf_GetEthIfCtrlInitState(Index))
#define EthIf_GetAddrEthIfCtrlLinkCount(Index)                                                      (&EthIf_GetEthIfCtrlLinkCount(Index))
#define EthIf_GetAddrEthIfCtrlLinkState(Index)                                                      (&EthIf_GetEthIfCtrlLinkState(Index))
#define EthIf_GetAddrEthIfCtrlMode(Index)                                                           (&EthIf_GetEthIfCtrlMode(Index))
#define EthIf_GetAddrNumRxBytesOfEthIfCtrlRxStats(Index)                                            (&EthIf_GetNumRxBytesOfEthIfCtrlRxStats(Index))
#define EthIf_GetAddrNumRxPktsOfEthIfCtrlRxStats(Index)                                             (&EthIf_GetNumRxPktsOfEthIfCtrlRxStats(Index))
#define EthIf_GetAddrNumTxBytesOfEthIfCtrlTxStats(Index)                                            (&EthIf_GetNumTxBytesOfEthIfCtrlTxStats(Index))
#define EthIf_GetAddrNumTxPktsOfEthIfCtrlTxStats(Index)                                             (&EthIf_GetNumTxPktsOfEthIfCtrlTxStats(Index))
#define EthIf_GetAddrDropCtrlIdxOfEthIfMeasurementData(Index)                                       (&EthIf_GetDropCtrlIdxOfEthIfMeasurementData(Index))
#define EthIf_GetAddrUnknownEtherTypeOfEthIfMeasurementData(Index)                                  (&EthIf_GetUnknownEtherTypeOfEthIfMeasurementData(Index))
#define EthIf_GetAddrVlanDoubleTaggedOfEthIfMeasurementData(Index)                                  (&EthIf_GetVlanDoubleTaggedOfEthIfMeasurementData(Index))
#define EthIf_GetAddrEthIfSwtPortGroupState(Index)                                                  (&EthIf_GetEthIfSwtPortGroupState(Index))
#define EthIf_GetAddrEthSwtInitCnt(Index)                                                           (&EthIf_GetEthSwtInitCnt(Index))
#define EthIf_GetAddrEthSwtPortLinkState(Index)                                                     (&EthIf_GetEthSwtPortLinkState(Index))
#define EthIf_GetAddrEthSwtPortModeCnt(Index)                                                       (&EthIf_GetEthSwtPortModeCnt(Index))
#define EthIf_GetAddrEthTrcvInitCnt(Index)                                                          (&EthIf_GetEthTrcvInitCnt(Index))
#define EthIf_GetAddrEthTrcvLinkState(Index)                                                        (&EthIf_GetEthTrcvLinkState(Index))
#define EthIf_GetAddrEthTrcvModeCnt(Index)                                                          (&EthIf_GetEthTrcvModeCnt(Index))
#define EthIf_GetAddrEthTrcvState(Index)                                                            (&EthIf_GetEthTrcvState(Index))
#define EthIf_GetAddrInitLocked()                                                                   (&EthIf_IsInitLocked())
#define EthIf_GetAddrMainFuncStateDecoupleFreqCnt()                                                 (&EthIf_GetMainFuncStateDecoupleFreqCnt())
#define EthIf_GetAddrDestEthTxBufferIdxOfMirrorTxInfo(Index)                                        (&EthIf_GetDestEthTxBufferIdxOfMirrorTxInfo(Index))
#define EthIf_GetAddrDestPayloadPtrOfMirrorTxInfo(Index)                                            (&EthIf_GetDestPayloadPtrOfMirrorTxInfo(Index))
#define EthIf_GetAddrEthIfCtrlIdxOfMirrorTxInfo(Index)                                              (&EthIf_GetEthIfCtrlIdxOfMirrorTxInfo(Index))
#define EthIf_GetAddrInfoValidOfMirrorTxInfo(Index)                                                 (&EthIf_IsInfoValidOfMirrorTxInfo(Index))
#define EthIf_GetAddrSrcEthTxBufferIdxOfMirrorTxInfo(Index)                                         (&EthIf_GetSrcEthTxBufferIdxOfMirrorTxInfo(Index))
#define EthIf_GetAddrSrcPayloadPtrOfMirrorTxInfo(Index)                                             (&EthIf_GetSrcPayloadPtrOfMirrorTxInfo(Index))
#define EthIf_GetAddrUsedOfMirrorTxInfo(Index)                                                      (&EthIf_IsUsedOfMirrorTxInfo(Index))
#define EthIf_GetAddrModeChangeLocked()                                                             (&EthIf_IsModeChangeLocked())
#define EthIf_GetAddrPortGroupHostOrUpLinkPortRoleLinkCount(Index)                                  (&EthIf_GetPortGroupHostOrUpLinkPortRoleLinkCount(Index))
#define EthIf_GetAddrPortGroupLaxLinkAggregationCount(Index)                                        (&EthIf_GetPortGroupLaxLinkAggregationCount(Index))
#define EthIf_GetAddrPortGroupLinkState(Index)                                                      (&EthIf_GetPortGroupLinkState(Index))
#define EthIf_GetAddrPortGroupMode(Index)                                                           (&EthIf_GetPortGroupMode(Index))
#define EthIf_GetAddrPortGroupNoRoleLinkCount(Index)                                                (&EthIf_GetPortGroupNoRoleLinkCount(Index))
#define EthIf_GetAddrPortSignalQualityResult(Index)                                                 (&EthIf_GetPortSignalQualityResult(Index))
#define EthIf_GetAddrPortStartupActiveTimeCounter()                                                 (&EthIf_GetPortStartupActiveTimeCounter())
#define EthIf_GetAddrPortStartupActiveTimerActive()                                                 (&EthIf_IsPortStartupActiveTimerActive())
#define EthIf_GetAddrSignalQualityDecoupleFreqCnt()                                                 (&EthIf_GetSignalQualityDecoupleFreqCnt())
#define EthIf_GetAddrSignalQualityResult(Index)                                                     (&EthIf_GetSignalQualityResult(Index))
#define EthIf_GetAddrSrcMacOfSrcMacAddrBuffer(Index)                                                (&EthIf_GetSrcMacOfSrcMacAddrBuffer(Index))
#define EthIf_GetAddrValidOfSrcMacAddrBuffer(Index)                                                 (&EthIf_IsValidOfSrcMacAddrBuffer(Index))
#define EthIf_GetAddrEthIfCtrlIdxOfTxContext(Index)                                                 (&EthIf_GetEthIfCtrlIdxOfTxContext(Index))
#define EthIf_GetAddrFrameHdrOfTxContext(Index)                                                     (&EthIf_GetFrameHdrOfTxContext(Index))
#define EthIf_GetAddrPayloadLenOfTxContext(Index)                                                   (&EthIf_GetPayloadLenOfTxContext(Index))
#define EthIf_GetAddrPayloadPtrOfTxContext(Index)                                                   (&EthIf_GetPayloadPtrOfTxContext(Index))
#define EthIf_GetAddrTxPendingOfTxContext(Index)                                                    (&EthIf_IsTxPendingOfTxContext(Index))
#define EthIf_GetAddrUserIdxOfTxContext(Index)                                                      (&EthIf_GetUserIdxOfTxContext(Index))
#define EthIf_GetAddrValidOfTxContext(Index)                                                        (&EthIf_IsValidOfTxContext(Index))
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCHasMacros  EthIf Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define EthIf_HasEthCtrl()                                                                          (EthIf_GetEthCtrlOfPCConfig() != NULL_PTR)
#define EthIf_HasEthDrvApiIdxOfEthCtrl()                                                            (TRUE != FALSE)
#define EthIf_HasSnvOfEthCtrl()                                                                     (TRUE != FALSE)
#define EthIf_HasTxContextEndIdxOfEthCtrl()                                                         (TRUE != FALSE)
#define EthIf_HasTxContextStartIdxOfEthCtrl()                                                       (TRUE != FALSE)
#define EthIf_HasEthCtrlInitCnt()                                                                   (EthIf_GetEthCtrlInitCntOfPCConfig() != NULL_PTR)
#define EthIf_HasEthCtrlModeCnt()                                                                   (EthIf_GetEthCtrlModeCntOfPCConfig() != NULL_PTR)
#define EthIf_HasEthCtrlRxFrameCnt()                                                                (EthIf_GetEthCtrlRxFrameCntOfPCConfig() != NULL_PTR)
#define EthIf_HasEthCtrlState()                                                                     (EthIf_GetEthCtrlStateOfPCConfig() != NULL_PTR)
#define EthIf_HasEthDrvApi()                                                                        (EthIf_GetEthDrvApiOfPCConfig() != NULL_PTR)
#define EthIf_HasCtrlInitOfEthDrvApi()                                                              (TRUE != FALSE)
#define EthIf_HasEnableEgressTimeStampOfEthDrvApi()                                                 (TRUE != FALSE)
#define EthIf_HasGetBandwidthLimitOfEthDrvApi()                                                     (TRUE != FALSE)
#define EthIf_HasGetCtrlModeOfEthDrvApi()                                                           (TRUE != FALSE)
#define EthIf_HasGetCurrentTimeOfEthDrvApi()                                                        (TRUE != FALSE)
#define EthIf_HasGetEgressTimeStampOfEthDrvApi()                                                    (TRUE != FALSE)
#define EthIf_HasGetIngressTimeStampOfEthDrvApi()                                                   (TRUE != FALSE)
#define EthIf_HasGetPhysAddrOfEthDrvApi()                                                           (TRUE != FALSE)
#define EthIf_HasGetRxHeaderPtrOfEthDrvApi()                                                        (TRUE != FALSE)
#define EthIf_HasGetRxStatsOfEthDrvApi()                                                            (TRUE != FALSE)
#define EthIf_HasGetTxHeaderPtrOfEthDrvApi()                                                        (TRUE != FALSE)
#define EthIf_HasGetTxStatsOfEthDrvApi()                                                            (TRUE != FALSE)
#define EthIf_HasProvideExtTxBufferOfEthDrvApi()                                                    (TRUE != FALSE)
#define EthIf_HasProvideTxBufferOfEthDrvApi()                                                       (TRUE != FALSE)
#define EthIf_HasReceiveOfEthDrvApi()                                                               (TRUE != FALSE)
#define EthIf_HasReleaseRxBufferOfEthDrvApi()                                                       (TRUE != FALSE)
#define EthIf_HasSetBandwidthLimitOfEthDrvApi()                                                     (TRUE != FALSE)
#define EthIf_HasSetCtrlModeOfEthDrvApi()                                                           (TRUE != FALSE)
#define EthIf_HasSetPhysAddrOfEthDrvApi()                                                           (TRUE != FALSE)
#define EthIf_HasTransmitOfEthDrvApi()                                                              (TRUE != FALSE)
#define EthIf_HasTxConfOfEthDrvApi()                                                                (TRUE != FALSE)
#define EthIf_HasUpdatePhysAddrFilterOfEthDrvApi()                                                  (TRUE != FALSE)
#define EthIf_HasVTransmitOfEthDrvApi()                                                             (TRUE != FALSE)
#define EthIf_HasEthIfClkUnit()                                                                     (EthIf_GetEthIfClkUnitOfPCConfig() != NULL_PTR)
#define EthIf_HasEthClkUnitIdxOfEthIfClkUnit()                                                      (TRUE != FALSE)
#define EthIf_HasEthIfClkUnitIdxOfEthIfClkUnit()                                                    (TRUE != FALSE)
#define EthIf_HasEthIfCtrl()                                                                        (EthIf_GetEthIfCtrlOfPCConfig() != NULL_PTR)
#define EthIf_HasEthCtrlIdxOfEthIfCtrl()                                                            (TRUE != FALSE)
#define EthIf_HasEthIfPhysCtrlCfgIdxOfEthIfCtrl()                                                   (TRUE != FALSE)
#define EthIf_HasEthSwtDrvApiIdxOfEthIfCtrl()                                                       (TRUE != FALSE)
#define EthIf_HasEthSwtDrvApiUsedOfEthIfCtrl()                                                      (TRUE != FALSE)
#define EthIf_HasGatewayDestEthIfCtrlIdxIdxOfEthIfCtrl()                                            (TRUE != FALSE)
#define EthIf_HasGatewayDestEthIfCtrlIdxOfEthIfCtrl()                                               (TRUE != FALSE)
#define EthIf_HasGatewayDestEthIfCtrlIdxUsedOfEthIfCtrl()                                           (TRUE != FALSE)
#define EthIf_HasLinkAggrThresholdOfEthIfCtrl()                                                     (TRUE != FALSE)
#define EthIf_HasMacSecTypeOfEthIfCtrl()                                                            (TRUE != FALSE)
#define EthIf_HasMirrorRxDestIdxIdxOfEthIfCtrl()                                                    (TRUE != FALSE)
#define EthIf_HasMirrorRxDestIdxOfEthIfCtrl()                                                       (TRUE != FALSE)
#define EthIf_HasMirrorRxDestIdxUsedOfEthIfCtrl()                                                   (TRUE != FALSE)
#define EthIf_HasMirrorTxDestIdxIdxOfEthIfCtrl()                                                    (TRUE != FALSE)
#define EthIf_HasMirrorTxDestIdxOfEthIfCtrl()                                                       (TRUE != FALSE)
#define EthIf_HasMirrorTxDestIdxUsedOfEthIfCtrl()                                                   (TRUE != FALSE)
#define EthIf_HasMtuOfEthIfCtrl()                                                                   (TRUE != FALSE)
#define EthIf_HasPhysLayerInitElemsIdxOfEthIfCtrl()                                                 (TRUE != FALSE)
#define EthIf_HasPhysLayerModeElemsIdxOfEthIfCtrl()                                                 (TRUE != FALSE)
#define EthIf_HasSnvOfEthIfCtrl()                                                                   (TRUE != FALSE)
#define EthIf_HasTypeOfEthIfCtrl()                                                                  (TRUE != FALSE)
#define EthIf_HasVlanIdOfEthIfCtrl()                                                                (TRUE != FALSE)
#define EthIf_HasEthIfCtrlInitState()                                                               (EthIf_GetEthIfCtrlInitStateOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlLinkCount()                                                               (EthIf_GetEthIfCtrlLinkCountOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlLinkState()                                                               (EthIf_GetEthIfCtrlLinkStateOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlMode()                                                                    (EthIf_GetEthIfCtrlModeOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlOfEthTrcvInd()                                                            (EthIf_GetEthIfCtrlOfEthTrcvIndOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlOfPortGroupInd()                                                          (EthIf_GetEthIfCtrlOfPortGroupIndOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlRxStats()                                                                 (EthIf_GetEthIfCtrlRxStatsOfPCConfig() != NULL_PTR)
#define EthIf_HasNumRxBytesOfEthIfCtrlRxStats()                                                     (TRUE != FALSE)
#define EthIf_HasNumRxPktsOfEthIfCtrlRxStats()                                                      (TRUE != FALSE)
#define EthIf_HasEthIfCtrlTxStats()                                                                 (EthIf_GetEthIfCtrlTxStatsOfPCConfig() != NULL_PTR)
#define EthIf_HasNumTxBytesOfEthIfCtrlTxStats()                                                     (TRUE != FALSE)
#define EthIf_HasNumTxPktsOfEthIfCtrlTxStats()                                                      (TRUE != FALSE)
#define EthIf_HasEthIfMeasurementData()                                                             (EthIf_GetEthIfMeasurementDataOfPCConfig() != NULL_PTR)
#define EthIf_HasDropCtrlIdxOfEthIfMeasurementData()                                                (TRUE != FALSE)
#define EthIf_HasUnknownEtherTypeOfEthIfMeasurementData()                                           (TRUE != FALSE)
#define EthIf_HasVlanDoubleTaggedOfEthIfMeasurementData()                                           (TRUE != FALSE)
#define EthIf_HasEthIfPhysCtrlCfg()                                                                 (EthIf_GetEthIfPhysCtrlCfgOfPCConfig() != NULL_PTR)
#define EthIf_HasEthCtrlIdxOfEthIfPhysCtrlCfg()                                                     (TRUE != FALSE)
#define EthIf_HasEthDrvApiIdxOfEthIfPhysCtrlCfg()                                                   (TRUE != FALSE)
#define EthIf_HasEthIfClkUnitEndIdxOfEthIfPhysCtrlCfg()                                             (TRUE != FALSE)
#define EthIf_HasEthIfClkUnitStartIdxOfEthIfPhysCtrlCfg()                                           (TRUE != FALSE)
#define EthIf_HasEthIfClkUnitUsedOfEthIfPhysCtrlCfg()                                               (TRUE != FALSE)
#define EthIf_HasEthIfPhysControllerIdxOfEthIfPhysCtrlCfg()                                         (TRUE != FALSE)
#define EthIf_HasEthPhcSupportAvailableOfEthIfPhysCtrlCfg()                                         (TRUE != FALSE)
#define EthIf_HasEthIfSwtPortGroupState()                                                           (EthIf_GetEthIfSwtPortGroupStateOfPCConfig() != NULL_PTR)
#define EthIf_HasEthSwt()                                                                           (EthIf_GetEthSwtOfPCConfig() != NULL_PTR)
#define EthIf_HasEthSwtDrvApiIdxOfEthSwt()                                                          (TRUE != FALSE)
#define EthIf_HasEthSwtPortInEthSwtContextEndIdxOfEthSwt()                                          (TRUE != FALSE)
#define EthIf_HasEthSwtPortInEthSwtContextStartIdxOfEthSwt()                                        (TRUE != FALSE)
#define EthIf_HasEthSwtPortInEthSwtContextUsedOfEthSwt()                                            (TRUE != FALSE)
#define EthIf_HasSnvOfEthSwt()                                                                      (TRUE != FALSE)
#define EthIf_HasEthSwtDrv()                                                                        (EthIf_GetEthSwtDrvOfPCConfig() != NULL_PTR)
#define EthIf_HasEthSwtEndIdxOfEthSwtDrv()                                                          (TRUE != FALSE)
#define EthIf_HasEthSwtStartIdxOfEthSwtDrv()                                                        (TRUE != FALSE)
#define EthIf_HasEthSwtDrvApi()                                                                     (EthIf_GetEthSwtDrvApiOfPCConfig() != NULL_PTR)
#define EthIf_HasEnableVlanOfEthSwtDrvApi()                                                         (TRUE != FALSE)
#define EthIf_HasGetArlTableOfEthSwtDrvApi()                                                        (TRUE != FALSE)
#define EthIf_HasGetBaudRateOfEthSwtDrvApi()                                                        (TRUE != FALSE)
#define EthIf_HasGetBufferLevelOfEthSwtDrvApi()                                                     (TRUE != FALSE)
#define EthIf_HasGetDropCountOfEthSwtDrvApi()                                                       (TRUE != FALSE)
#define EthIf_HasGetDuplexModeOfEthSwtDrvApi()                                                      (TRUE != FALSE)
#define EthIf_HasGetLinkStateOfEthSwtDrvApi()                                                       (TRUE != FALSE)
#define EthIf_HasGetMacLearningModeOfEthSwtDrvApi()                                                 (TRUE != FALSE)
#define EthIf_HasGetPortCableDiagnosticsResultOfEthSwtDrvApi()                                      (TRUE != FALSE)
#define EthIf_HasGetPortMacAddrOfEthSwtDrvApi()                                                     (TRUE != FALSE)
#define EthIf_HasGetPortSignalQualityOfEthSwtDrvApi()                                               (TRUE != FALSE)
#define EthIf_HasGetRxMgmtObjectOfEthSwtDrvApi()                                                    (TRUE != FALSE)
#define EthIf_HasGetSwtPortModeOfEthSwtDrvApi()                                                     (TRUE != FALSE)
#define EthIf_HasGetTxMgmtObjectOfEthSwtDrvApi()                                                    (TRUE != FALSE)
#define EthIf_HasPortEnableTimeStampOfEthSwtDrvApi()                                                (TRUE != FALSE)
#define EthIf_HasResetConfigOfEthSwtDrvApi()                                                        (TRUE != FALSE)
#define EthIf_HasRunPortCableDiagnosticOfEthSwtDrvApi()                                             (TRUE != FALSE)
#define EthIf_HasSetCorrectionTimeOfEthSwtDrvApi()                                                  (TRUE != FALSE)
#define EthIf_HasSetMacLearningModeOfEthSwtDrvApi()                                                 (TRUE != FALSE)
#define EthIf_HasSetSwtMgmtInfoOfEthSwtDrvApi()                                                     (TRUE != FALSE)
#define EthIf_HasSetSwtPortModeOfEthSwtDrvApi()                                                     (TRUE != FALSE)
#define EthIf_HasStartQbvScheduleOfEthSwtDrvApi()                                                   (TRUE != FALSE)
#define EthIf_HasStartSwtPortAutoNegOfEthSwtDrvApi()                                                (TRUE != FALSE)
#define EthIf_HasStopQbvScheduleOfEthSwtDrvApi()                                                    (TRUE != FALSE)
#define EthIf_HasStoreConfigOfEthSwtDrvApi()                                                        (TRUE != FALSE)
#define EthIf_HasSwtInitOfEthSwtDrvApi()                                                            (TRUE != FALSE)
#define EthIf_HasUpdateMCastPortAssignmentOfEthSwtDrvApi()                                          (TRUE != FALSE)
#define EthIf_HasEthSwtInd()                                                                        (EthIf_GetEthSwtIndOfPCConfig() != NULL_PTR)
#define EthIf_HasEthSwtInitCnt()                                                                    (EthIf_GetEthSwtInitCntOfPCConfig() != NULL_PTR)
#define EthIf_HasEthSwtPort()                                                                       (EthIf_GetEthSwtPortOfPCConfig() != NULL_PTR)
#define EthIf_HasEthSwtIdxOfEthSwtPort()                                                            (TRUE != FALSE)
#define EthIf_HasEthSwtPortHostOrUpLinkPortIdxOfEthSwtPort()                                        (TRUE != FALSE)
#define EthIf_HasMacSecSecuredOfEthSwtPort()                                                        (TRUE != FALSE)
#define EthIf_HasMkaPaeIdxOfEthSwtPort()                                                            (TRUE != FALSE)
#define EthIf_HasPortGroupIndEndIdxOfEthSwtPort()                                                   (TRUE != FALSE)
#define EthIf_HasPortGroupIndStartIdxOfEthSwtPort()                                                 (TRUE != FALSE)
#define EthIf_HasPortRoleOfEthSwtPort()                                                             (TRUE != FALSE)
#define EthIf_HasSnvOfEthSwtPort()                                                                  (TRUE != FALSE)
#define EthIf_HasEthSwtPortInEthSwtContext()                                                        (EthIf_GetEthSwtPortInEthSwtContextOfPCConfig() != NULL_PTR)
#define EthIf_HasEthSwtPortIdxOfEthSwtPortInEthSwtContext()                                         (TRUE != FALSE)
#define EthIf_HasEthSwtPortUsedOfEthSwtPortInEthSwtContext()                                        (TRUE != FALSE)
#define EthIf_HasEthSwtPortInd()                                                                    (EthIf_GetEthSwtPortIndOfPCConfig() != NULL_PTR)
#define EthIf_HasEthSwtPortLinkState()                                                              (EthIf_GetEthSwtPortLinkStateOfPCConfig() != NULL_PTR)
#define EthIf_HasEthSwtPortModeCnt()                                                                (EthIf_GetEthSwtPortModeCntOfPCConfig() != NULL_PTR)
#define EthIf_HasEthTrcv()                                                                          (EthIf_GetEthTrcvOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlOfEthTrcvIndEndIdxOfEthTrcv()                                             (TRUE != FALSE)
#define EthIf_HasEthIfCtrlOfEthTrcvIndStartIdxOfEthTrcv()                                           (TRUE != FALSE)
#define EthIf_HasEthIfCtrlOfEthTrcvIndUsedOfEthTrcv()                                               (TRUE != FALSE)
#define EthIf_HasEthTrcvDrvApiIdxOfEthTrcv()                                                        (TRUE != FALSE)
#define EthIf_HasMacSecSecuredOfEthTrcv()                                                           (TRUE != FALSE)
#define EthIf_HasMkaPaeIdxOfEthTrcv()                                                               (TRUE != FALSE)
#define EthIf_HasSnvOfEthTrcv()                                                                     (TRUE != FALSE)
#define EthIf_HasEthTrcvDrvApi()                                                                    (EthIf_GetEthTrcvDrvApiOfPCConfig() != NULL_PTR)
#define EthIf_HasCheckWakeupOfEthTrcvDrvApi()                                                       (TRUE != FALSE)
#define EthIf_HasGetBaudRateOfEthTrcvDrvApi()                                                       (TRUE != FALSE)
#define EthIf_HasGetCableDiagnosticsResultOfEthTrcvDrvApi()                                         (TRUE != FALSE)
#define EthIf_HasGetDuplexModeOfEthTrcvDrvApi()                                                     (TRUE != FALSE)
#define EthIf_HasGetLinkStateOfEthTrcvDrvApi()                                                      (TRUE != FALSE)
#define EthIf_HasGetPhySignalQualityOfEthTrcvDrvApi()                                               (TRUE != FALSE)
#define EthIf_HasGetTrcvModeOfEthTrcvDrvApi()                                                       (TRUE != FALSE)
#define EthIf_HasGetTrcvWakeupModeOfEthTrcvDrvApi()                                                 (TRUE != FALSE)
#define EthIf_HasRunCableDiagnosticOfEthTrcvDrvApi()                                                (TRUE != FALSE)
#define EthIf_HasSetPhyLoopbackModeOfEthTrcvDrvApi()                                                (TRUE != FALSE)
#define EthIf_HasSetPhyTestModeOfEthTrcvDrvApi()                                                    (TRUE != FALSE)
#define EthIf_HasSetPhyTxModeOfEthTrcvDrvApi()                                                      (TRUE != FALSE)
#define EthIf_HasSetTrcvModeOfEthTrcvDrvApi()                                                       (TRUE != FALSE)
#define EthIf_HasSetTrcvWakeupModeOfEthTrcvDrvApi()                                                 (TRUE != FALSE)
#define EthIf_HasStartAutoNegOfEthTrcvDrvApi()                                                      (TRUE != FALSE)
#define EthIf_HasTrcvInitOfEthTrcvDrvApi()                                                          (TRUE != FALSE)
#define EthIf_HasEthTrcvInitCnt()                                                                   (EthIf_GetEthTrcvInitCntOfPCConfig() != NULL_PTR)
#define EthIf_HasEthTrcvLinkState()                                                                 (EthIf_GetEthTrcvLinkStateOfPCConfig() != NULL_PTR)
#define EthIf_HasEthTrcvModeCnt()                                                                   (EthIf_GetEthTrcvModeCntOfPCConfig() != NULL_PTR)
#define EthIf_HasEthTrcvState()                                                                     (EthIf_GetEthTrcvStateOfPCConfig() != NULL_PTR)
#define EthIf_HasExplicitBufReleaseFilter()                                                         (EthIf_GetExplicitBufReleaseFilterOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlIdxOfExplicitBufReleaseFilter()                                           (TRUE != FALSE)
#define EthIf_HasUserIdxOfExplicitBufReleaseFilter()                                                (TRUE != FALSE)
#define EthIf_HasUserUsedOfExplicitBufReleaseFilter()                                               (TRUE != FALSE)
#define EthIf_HasGatewaySrcMacBlackList()                                                           (EthIf_GetGatewaySrcMacBlackListOfPCConfig() != NULL_PTR)
#define EthIf_HasMacAddrOfGatewaySrcMacBlackList()                                                  (TRUE != FALSE)
#define EthIf_HasInitLocked()                                                                       (EthIf_GetInitLockedOfPCConfig() != NULL_PTR)
#define EthIf_HasLinkStateChgIndications()                                                          (EthIf_GetLinkStateChgIndicationsOfPCConfig() != NULL_PTR)
#define EthIf_HasLinkStateChgMainReload()                                                           (TRUE != FALSE)
#define EthIf_HasMainFuncStateDecoupleFreqCnt()                                                     (EthIf_GetMainFuncStateDecoupleFreqCntOfPCConfig() != NULL_PTR)
#define EthIf_HasMaxFrameRxPerEthCtrl()                                                             (TRUE != FALSE)
#define EthIf_HasMaxTxBufPerEthCtrl()                                                               (TRUE != FALSE)
#define EthIf_HasMirrorDest()                                                                       (EthIf_GetMirrorDestOfPCConfig() != NULL_PTR)
#define EthIf_HasEthCtrlIdxOfMirrorDest()                                                           (TRUE != FALSE)
#define EthIf_HasKeepSrcMacEnabledOfMirrorDest()                                                    (TRUE != FALSE)
#define EthIf_HasMirrorTxInfo()                                                                     (EthIf_GetMirrorTxInfoOfPCConfig() != NULL_PTR)
#define EthIf_HasDestEthTxBufferIdxOfMirrorTxInfo()                                                 (TRUE != FALSE)
#define EthIf_HasDestPayloadPtrOfMirrorTxInfo()                                                     (TRUE != FALSE)
#define EthIf_HasEthIfCtrlIdxOfMirrorTxInfo()                                                       (TRUE != FALSE)
#define EthIf_HasInfoValidOfMirrorTxInfo()                                                          (TRUE != FALSE)
#define EthIf_HasSrcEthTxBufferIdxOfMirrorTxInfo()                                                  (TRUE != FALSE)
#define EthIf_HasSrcPayloadPtrOfMirrorTxInfo()                                                      (TRUE != FALSE)
#define EthIf_HasUsedOfMirrorTxInfo()                                                               (TRUE != FALSE)
#define EthIf_HasModeChangeLocked()                                                                 (EthIf_GetModeChangeLockedOfPCConfig() != NULL_PTR)
#define EthIf_HasPhysLayerInitElems()                                                               (EthIf_GetPhysLayerInitElemsOfPCConfig() != NULL_PTR)
#define EthIf_HasEthSwtIndEndIdxOfPhysLayerInitElems()                                              (TRUE != FALSE)
#define EthIf_HasEthSwtIndStartIdxOfPhysLayerInitElems()                                            (TRUE != FALSE)
#define EthIf_HasEthSwtIndUsedOfPhysLayerInitElems()                                                (TRUE != FALSE)
#define EthIf_HasEthTrcvIdxOfPhysLayerInitElems()                                                   (TRUE != FALSE)
#define EthIf_HasEthTrcvUsedOfPhysLayerInitElems()                                                  (TRUE != FALSE)
#define EthIf_HasPhysLayerModeElems()                                                               (EthIf_GetPhysLayerModeElemsOfPCConfig() != NULL_PTR)
#define EthIf_HasEthTrcvIdxOfPhysLayerModeElems()                                                   (TRUE != FALSE)
#define EthIf_HasEthTrcvUsedOfPhysLayerModeElems()                                                  (TRUE != FALSE)
#define EthIf_HasPortGroupIdxOfPhysLayerModeElems()                                                 (TRUE != FALSE)
#define EthIf_HasPortGroupUsedOfPhysLayerModeElems()                                                (TRUE != FALSE)
#define EthIf_HasPortGroup()                                                                        (EthIf_GetPortGroupOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlOfPortGroupIndEndIdxOfPortGroup()                                         (TRUE != FALSE)
#define EthIf_HasEthIfCtrlOfPortGroupIndStartIdxOfPortGroup()                                       (TRUE != FALSE)
#define EthIf_HasEthIfCtrlOfPortGroupIndUsedOfPortGroup()                                           (TRUE != FALSE)
#define EthIf_HasEthSwtPortIndEndIdxOfPortGroup()                                                   (TRUE != FALSE)
#define EthIf_HasEthSwtPortIndStartIdxOfPortGroup()                                                 (TRUE != FALSE)
#define EthIf_HasHostAndUpLinkPortThresholdOfPortGroup()                                            (TRUE != FALSE)
#define EthIf_HasLaxLinkAggregationEnabledOfPortGroup()                                             (TRUE != FALSE)
#define EthIf_HasLinkAggrThresholdOfPortGroup()                                                     (TRUE != FALSE)
#define EthIf_HasNoRolePortThresholdOfPortGroup()                                                   (TRUE != FALSE)
#define EthIf_HasSemanticOfPortGroup()                                                              (TRUE != FALSE)
#define EthIf_HasSnvOfPortGroup()                                                                   (TRUE != FALSE)
#define EthIf_HasPortGroupHostOrUpLinkPortRoleLinkCount()                                           (EthIf_GetPortGroupHostOrUpLinkPortRoleLinkCountOfPCConfig() != NULL_PTR)
#define EthIf_HasPortGroupInd()                                                                     (EthIf_GetPortGroupIndOfPCConfig() != NULL_PTR)
#define EthIf_HasPortGroupLaxLinkAggregationCount()                                                 (EthIf_GetPortGroupLaxLinkAggregationCountOfPCConfig() != NULL_PTR)
#define EthIf_HasPortGroupLinkState()                                                               (EthIf_GetPortGroupLinkStateOfPCConfig() != NULL_PTR)
#define EthIf_HasPortGroupMode()                                                                    (EthIf_GetPortGroupModeOfPCConfig() != NULL_PTR)
#define EthIf_HasPortGroupNoRoleLinkCount()                                                         (EthIf_GetPortGroupNoRoleLinkCountOfPCConfig() != NULL_PTR)
#define EthIf_HasPortSignalQualityResult()                                                          (EthIf_GetPortSignalQualityResultOfPCConfig() != NULL_PTR)
#define EthIf_HasPortStartupActiveTimeCounter()                                                     (EthIf_GetPortStartupActiveTimeCounterOfPCConfig() != NULL_PTR)
#define EthIf_HasPortStartupActiveTimeFreq()                                                        (TRUE != FALSE)
#define EthIf_HasPortStartupActiveTimerActive()                                                     (EthIf_GetPortStartupActiveTimerActiveOfPCConfig() != NULL_PTR)
#define EthIf_HasRxIndications()                                                                    (EthIf_GetRxIndicationsOfPCConfig() != NULL_PTR)
#define EthIf_HasRxIndicationsInd()                                                                 (EthIf_GetRxIndicationsIndOfPCConfig() != NULL_PTR)
#define EthIf_HasSignalQualityChgMainReload()                                                       (TRUE != FALSE)
#define EthIf_HasSignalQualityDecoupleFreqCnt()                                                     (EthIf_GetSignalQualityDecoupleFreqCntOfPCConfig() != NULL_PTR)
#define EthIf_HasSignalQualityResult()                                                              (EthIf_GetSignalQualityResultOfPCConfig() != NULL_PTR)
#define EthIf_HasSizeOfEthCtrl()                                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfEthCtrlInitCnt()                                                             (TRUE != FALSE)
#define EthIf_HasSizeOfEthCtrlModeCnt()                                                             (TRUE != FALSE)
#define EthIf_HasSizeOfEthCtrlRxFrameCnt()                                                          (TRUE != FALSE)
#define EthIf_HasSizeOfEthCtrlState()                                                               (TRUE != FALSE)
#define EthIf_HasSizeOfEthDrvApi()                                                                  (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfClkUnit()                                                               (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrl()                                                                  (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlInitState()                                                         (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlLinkCount()                                                         (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlLinkState()                                                         (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlMode()                                                              (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlOfEthTrcvInd()                                                      (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlOfPortGroupInd()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlRxStats()                                                           (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlTxStats()                                                           (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfMeasurementData()                                                       (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfPhysCtrlCfg()                                                           (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfSwtPortGroupState()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwt()                                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtDrv()                                                                  (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtDrvApi()                                                               (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtInd()                                                                  (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtInitCnt()                                                              (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtPort()                                                                 (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtPortInEthSwtContext()                                                  (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtPortInd()                                                              (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtPortLinkState()                                                        (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtPortModeCnt()                                                          (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcv()                                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvDrvApi()                                                              (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvInitCnt()                                                             (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvLinkState()                                                           (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvModeCnt()                                                             (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvState()                                                               (TRUE != FALSE)
#define EthIf_HasSizeOfExplicitBufReleaseFilter()                                                   (TRUE != FALSE)
#define EthIf_HasSizeOfGatewaySrcMacBlackList()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfLinkStateChgIndications()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfMirrorDest()                                                                 (TRUE != FALSE)
#define EthIf_HasSizeOfMirrorTxInfo()                                                               (TRUE != FALSE)
#define EthIf_HasSizeOfPhysLayerInitElems()                                                         (TRUE != FALSE)
#define EthIf_HasSizeOfPhysLayerModeElems()                                                         (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroup()                                                                  (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupHostOrUpLinkPortRoleLinkCount()                                     (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupInd()                                                               (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupLaxLinkAggregationCount()                                           (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupLinkState()                                                         (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupMode()                                                              (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupNoRoleLinkCount()                                                   (TRUE != FALSE)
#define EthIf_HasSizeOfPortSignalQualityResult()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfRxIndications()                                                              (TRUE != FALSE)
#define EthIf_HasSizeOfRxIndicationsInd()                                                           (TRUE != FALSE)
#define EthIf_HasSizeOfSignalQualityResult()                                                        (TRUE != FALSE)
#define EthIf_HasSizeOfSrcMacAddrBuffer()                                                           (TRUE != FALSE)
#define EthIf_HasSizeOfTxConfirmations()                                                            (TRUE != FALSE)
#define EthIf_HasSizeOfTxConfirmationsInd()                                                         (TRUE != FALSE)
#define EthIf_HasSizeOfTxContext()                                                                  (TRUE != FALSE)
#define EthIf_HasSizeOfUser()                                                                       (TRUE != FALSE)
#define EthIf_HasSizeOfWakeupMap()                                                                  (TRUE != FALSE)
#define EthIf_HasSrcMacAddrBuffer()                                                                 (EthIf_GetSrcMacAddrBufferOfPCConfig() != NULL_PTR)
#define EthIf_HasSrcMacOfSrcMacAddrBuffer()                                                         (TRUE != FALSE)
#define EthIf_HasValidOfSrcMacAddrBuffer()                                                          (TRUE != FALSE)
#define EthIf_HasTxConfirmations()                                                                  (EthIf_GetTxConfirmationsOfPCConfig() != NULL_PTR)
#define EthIf_HasTxConfirmationsInd()                                                               (EthIf_GetTxConfirmationsIndOfPCConfig() != NULL_PTR)
#define EthIf_HasTxContext()                                                                        (EthIf_GetTxContextOfPCConfig() != NULL_PTR)
#define EthIf_HasEthIfCtrlIdxOfTxContext()                                                          (TRUE != FALSE)
#define EthIf_HasFrameHdrOfTxContext()                                                              (TRUE != FALSE)
#define EthIf_HasPayloadLenOfTxContext()                                                            (TRUE != FALSE)
#define EthIf_HasPayloadPtrOfTxContext()                                                            (TRUE != FALSE)
#define EthIf_HasTxPendingOfTxContext()                                                             (TRUE != FALSE)
#define EthIf_HasUserIdxOfTxContext()                                                               (TRUE != FALSE)
#define EthIf_HasValidOfTxContext()                                                                 (TRUE != FALSE)
#define EthIf_HasUser()                                                                             (EthIf_GetUserOfPCConfig() != NULL_PTR)
#define EthIf_HasEtherTypeOfUser()                                                                  (TRUE != FALSE)
#define EthIf_HasRxIndicationsIndEndIdxOfUser()                                                     (TRUE != FALSE)
#define EthIf_HasRxIndicationsIndStartIdxOfUser()                                                   (TRUE != FALSE)
#define EthIf_HasRxIndicationsIndUsedOfUser()                                                       (TRUE != FALSE)
#define EthIf_HasTxConfirmationsIndEndIdxOfUser()                                                   (TRUE != FALSE)
#define EthIf_HasTxConfirmationsIndStartIdxOfUser()                                                 (TRUE != FALSE)
#define EthIf_HasTxConfirmationsIndUsedOfUser()                                                     (TRUE != FALSE)
#define EthIf_HasWakeupMap()                                                                        (EthIf_GetWakeupMapOfPCConfig() != NULL_PTR)
#define EthIf_HasEthTrcvIdxOfWakeupMap()                                                            (TRUE != FALSE)
#define EthIf_HasWakeupSourceOfWakeupMap()                                                          (TRUE != FALSE)
#define EthIf_HasPCConfig()                                                                         (TRUE != FALSE)
#define EthIf_HasEthCtrlInitCntOfPCConfig()                                                         (TRUE != FALSE)
#define EthIf_HasEthCtrlModeCntOfPCConfig()                                                         (TRUE != FALSE)
#define EthIf_HasEthCtrlOfPCConfig()                                                                (TRUE != FALSE)
#define EthIf_HasEthCtrlRxFrameCntOfPCConfig()                                                      (TRUE != FALSE)
#define EthIf_HasEthCtrlStateOfPCConfig()                                                           (TRUE != FALSE)
#define EthIf_HasEthDrvApiOfPCConfig()                                                              (TRUE != FALSE)
#define EthIf_HasEthIfClkUnitOfPCConfig()                                                           (TRUE != FALSE)
#define EthIf_HasEthIfCtrlInitStateOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasEthIfCtrlLinkCountOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasEthIfCtrlLinkStateOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasEthIfCtrlModeOfPCConfig()                                                          (TRUE != FALSE)
#define EthIf_HasEthIfCtrlOfEthTrcvIndOfPCConfig()                                                  (TRUE != FALSE)
#define EthIf_HasEthIfCtrlOfPCConfig()                                                              (TRUE != FALSE)
#define EthIf_HasEthIfCtrlOfPortGroupIndOfPCConfig()                                                (TRUE != FALSE)
#define EthIf_HasEthIfCtrlRxStatsOfPCConfig()                                                       (TRUE != FALSE)
#define EthIf_HasEthIfCtrlTxStatsOfPCConfig()                                                       (TRUE != FALSE)
#define EthIf_HasEthIfMeasurementDataOfPCConfig()                                                   (TRUE != FALSE)
#define EthIf_HasEthIfPhysCtrlCfgOfPCConfig()                                                       (TRUE != FALSE)
#define EthIf_HasEthIfSwtPortGroupStateOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasEthSwtDrvApiOfPCConfig()                                                           (TRUE != FALSE)
#define EthIf_HasEthSwtDrvOfPCConfig()                                                              (TRUE != FALSE)
#define EthIf_HasEthSwtIndOfPCConfig()                                                              (TRUE != FALSE)
#define EthIf_HasEthSwtInitCntOfPCConfig()                                                          (TRUE != FALSE)
#define EthIf_HasEthSwtOfPCConfig()                                                                 (TRUE != FALSE)
#define EthIf_HasEthSwtPortInEthSwtContextOfPCConfig()                                              (TRUE != FALSE)
#define EthIf_HasEthSwtPortIndOfPCConfig()                                                          (TRUE != FALSE)
#define EthIf_HasEthSwtPortLinkStateOfPCConfig()                                                    (TRUE != FALSE)
#define EthIf_HasEthSwtPortModeCntOfPCConfig()                                                      (TRUE != FALSE)
#define EthIf_HasEthSwtPortOfPCConfig()                                                             (TRUE != FALSE)
#define EthIf_HasEthTrcvDrvApiOfPCConfig()                                                          (TRUE != FALSE)
#define EthIf_HasEthTrcvInitCntOfPCConfig()                                                         (TRUE != FALSE)
#define EthIf_HasEthTrcvLinkStateOfPCConfig()                                                       (TRUE != FALSE)
#define EthIf_HasEthTrcvModeCntOfPCConfig()                                                         (TRUE != FALSE)
#define EthIf_HasEthTrcvOfPCConfig()                                                                (TRUE != FALSE)
#define EthIf_HasEthTrcvStateOfPCConfig()                                                           (TRUE != FALSE)
#define EthIf_HasExplicitBufReleaseFilterOfPCConfig()                                               (TRUE != FALSE)
#define EthIf_HasGatewaySrcMacBlackListOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasInitLockedOfPCConfig()                                                             (TRUE != FALSE)
#define EthIf_HasLinkStateChgIndicationsOfPCConfig()                                                (TRUE != FALSE)
#define EthIf_HasLinkStateChgMainReloadOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasMainFuncStateDecoupleFreqCntOfPCConfig()                                           (TRUE != FALSE)
#define EthIf_HasMaxFrameRxPerEthCtrlOfPCConfig()                                                   (TRUE != FALSE)
#define EthIf_HasMaxTxBufPerEthCtrlOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasMirrorDestOfPCConfig()                                                             (TRUE != FALSE)
#define EthIf_HasMirrorTxInfoOfPCConfig()                                                           (TRUE != FALSE)
#define EthIf_HasModeChangeLockedOfPCConfig()                                                       (TRUE != FALSE)
#define EthIf_HasPhysLayerInitElemsOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasPhysLayerModeElemsOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasPortGroupHostOrUpLinkPortRoleLinkCountOfPCConfig()                                 (TRUE != FALSE)
#define EthIf_HasPortGroupIndOfPCConfig()                                                           (TRUE != FALSE)
#define EthIf_HasPortGroupLaxLinkAggregationCountOfPCConfig()                                       (TRUE != FALSE)
#define EthIf_HasPortGroupLinkStateOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasPortGroupModeOfPCConfig()                                                          (TRUE != FALSE)
#define EthIf_HasPortGroupNoRoleLinkCountOfPCConfig()                                               (TRUE != FALSE)
#define EthIf_HasPortGroupOfPCConfig()                                                              (TRUE != FALSE)
#define EthIf_HasPortSignalQualityResultOfPCConfig()                                                (TRUE != FALSE)
#define EthIf_HasPortStartupActiveTimeCounterOfPCConfig()                                           (TRUE != FALSE)
#define EthIf_HasPortStartupActiveTimeFreqOfPCConfig()                                              (TRUE != FALSE)
#define EthIf_HasPortStartupActiveTimerActiveOfPCConfig()                                           (TRUE != FALSE)
#define EthIf_HasRxIndicationsIndOfPCConfig()                                                       (TRUE != FALSE)
#define EthIf_HasRxIndicationsOfPCConfig()                                                          (TRUE != FALSE)
#define EthIf_HasSignalQualityChgMainReloadOfPCConfig()                                             (TRUE != FALSE)
#define EthIf_HasSignalQualityDecoupleFreqCntOfPCConfig()                                           (TRUE != FALSE)
#define EthIf_HasSignalQualityResultOfPCConfig()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfEthCtrlInitCntOfPCConfig()                                                   (TRUE != FALSE)
#define EthIf_HasSizeOfEthCtrlModeCntOfPCConfig()                                                   (TRUE != FALSE)
#define EthIf_HasSizeOfEthCtrlOfPCConfig()                                                          (TRUE != FALSE)
#define EthIf_HasSizeOfEthCtrlRxFrameCntOfPCConfig()                                                (TRUE != FALSE)
#define EthIf_HasSizeOfEthCtrlStateOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfEthDrvApiOfPCConfig()                                                        (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfClkUnitOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlInitStateOfPCConfig()                                               (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlLinkCountOfPCConfig()                                               (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlLinkStateOfPCConfig()                                               (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlModeOfPCConfig()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlOfEthTrcvIndOfPCConfig()                                            (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlOfPCConfig()                                                        (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlOfPortGroupIndOfPCConfig()                                          (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlRxStatsOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfCtrlTxStatsOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfMeasurementDataOfPCConfig()                                             (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfPhysCtrlCfgOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasSizeOfEthIfSwtPortGroupStateOfPCConfig()                                           (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtDrvApiOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtDrvOfPCConfig()                                                        (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtIndOfPCConfig()                                                        (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtInitCntOfPCConfig()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtOfPCConfig()                                                           (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtPortInEthSwtContextOfPCConfig()                                        (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtPortIndOfPCConfig()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtPortLinkStateOfPCConfig()                                              (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtPortModeCntOfPCConfig()                                                (TRUE != FALSE)
#define EthIf_HasSizeOfEthSwtPortOfPCConfig()                                                       (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvDrvApiOfPCConfig()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvInitCntOfPCConfig()                                                   (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvLinkStateOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvModeCntOfPCConfig()                                                   (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvOfPCConfig()                                                          (TRUE != FALSE)
#define EthIf_HasSizeOfEthTrcvStateOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfExplicitBufReleaseFilterOfPCConfig()                                         (TRUE != FALSE)
#define EthIf_HasSizeOfGatewaySrcMacBlackListOfPCConfig()                                           (TRUE != FALSE)
#define EthIf_HasSizeOfLinkStateChgIndicationsOfPCConfig()                                          (TRUE != FALSE)
#define EthIf_HasSizeOfMirrorDestOfPCConfig()                                                       (TRUE != FALSE)
#define EthIf_HasSizeOfMirrorTxInfoOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfPhysLayerInitElemsOfPCConfig()                                               (TRUE != FALSE)
#define EthIf_HasSizeOfPhysLayerModeElemsOfPCConfig()                                               (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupHostOrUpLinkPortRoleLinkCountOfPCConfig()                           (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupIndOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupLaxLinkAggregationCountOfPCConfig()                                 (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupLinkStateOfPCConfig()                                               (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupModeOfPCConfig()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupNoRoleLinkCountOfPCConfig()                                         (TRUE != FALSE)
#define EthIf_HasSizeOfPortGroupOfPCConfig()                                                        (TRUE != FALSE)
#define EthIf_HasSizeOfPortSignalQualityResultOfPCConfig()                                          (TRUE != FALSE)
#define EthIf_HasSizeOfRxIndicationsIndOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasSizeOfRxIndicationsOfPCConfig()                                                    (TRUE != FALSE)
#define EthIf_HasSizeOfSignalQualityResultOfPCConfig()                                              (TRUE != FALSE)
#define EthIf_HasSizeOfSrcMacAddrBufferOfPCConfig()                                                 (TRUE != FALSE)
#define EthIf_HasSizeOfTxConfirmationsIndOfPCConfig()                                               (TRUE != FALSE)
#define EthIf_HasSizeOfTxConfirmationsOfPCConfig()                                                  (TRUE != FALSE)
#define EthIf_HasSizeOfTxContextOfPCConfig()                                                        (TRUE != FALSE)
#define EthIf_HasSizeOfUserOfPCConfig()                                                             (TRUE != FALSE)
#define EthIf_HasSizeOfWakeupMapOfPCConfig()                                                        (TRUE != FALSE)
#define EthIf_HasSrcMacAddrBufferOfPCConfig()                                                       (TRUE != FALSE)
#define EthIf_HasTxConfirmationsIndOfPCConfig()                                                     (TRUE != FALSE)
#define EthIf_HasTxConfirmationsOfPCConfig()                                                        (TRUE != FALSE)
#define EthIf_HasTxContextOfPCConfig()                                                              (TRUE != FALSE)
#define EthIf_HasUserOfPCConfig()                                                                   (TRUE != FALSE)
#define EthIf_HasWakeupMapOfPCConfig()                                                              (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCIncrementDataMacros  EthIf Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define EthIf_IncEthCtrlInitCnt(Index)                                                              EthIf_GetEthCtrlInitCnt(Index)++
#define EthIf_IncEthCtrlModeCnt(Index)                                                              EthIf_GetEthCtrlModeCnt(Index)++
#define EthIf_IncEthCtrlRxFrameCnt(Index)                                                           EthIf_GetEthCtrlRxFrameCnt(Index)++
#define EthIf_IncEthIfCtrlLinkCount(Index)                                                          EthIf_GetEthIfCtrlLinkCount(Index)++
#define EthIf_IncNumRxBytesOfEthIfCtrlRxStats(Index)                                                EthIf_GetNumRxBytesOfEthIfCtrlRxStats(Index)++
#define EthIf_IncNumRxPktsOfEthIfCtrlRxStats(Index)                                                 EthIf_GetNumRxPktsOfEthIfCtrlRxStats(Index)++
#define EthIf_IncNumTxBytesOfEthIfCtrlTxStats(Index)                                                EthIf_GetNumTxBytesOfEthIfCtrlTxStats(Index)++
#define EthIf_IncNumTxPktsOfEthIfCtrlTxStats(Index)                                                 EthIf_GetNumTxPktsOfEthIfCtrlTxStats(Index)++
#define EthIf_IncDropCtrlIdxOfEthIfMeasurementData(Index)                                           EthIf_GetDropCtrlIdxOfEthIfMeasurementData(Index)++
#define EthIf_IncUnknownEtherTypeOfEthIfMeasurementData(Index)                                      EthIf_GetUnknownEtherTypeOfEthIfMeasurementData(Index)++
#define EthIf_IncVlanDoubleTaggedOfEthIfMeasurementData(Index)                                      EthIf_GetVlanDoubleTaggedOfEthIfMeasurementData(Index)++
#define EthIf_IncEthSwtInitCnt(Index)                                                               EthIf_GetEthSwtInitCnt(Index)++
#define EthIf_IncEthSwtPortModeCnt(Index)                                                           EthIf_GetEthSwtPortModeCnt(Index)++
#define EthIf_IncEthTrcvInitCnt(Index)                                                              EthIf_GetEthTrcvInitCnt(Index)++
#define EthIf_IncEthTrcvModeCnt(Index)                                                              EthIf_GetEthTrcvModeCnt(Index)++
#define EthIf_IncMainFuncStateDecoupleFreqCnt()                                                     EthIf_GetMainFuncStateDecoupleFreqCnt()++
#define EthIf_IncDestEthTxBufferIdxOfMirrorTxInfo(Index)                                            EthIf_GetDestEthTxBufferIdxOfMirrorTxInfo(Index)++
#define EthIf_IncEthIfCtrlIdxOfMirrorTxInfo(Index)                                                  EthIf_GetEthIfCtrlIdxOfMirrorTxInfo(Index)++
#define EthIf_IncSrcEthTxBufferIdxOfMirrorTxInfo(Index)                                             EthIf_GetSrcEthTxBufferIdxOfMirrorTxInfo(Index)++
#define EthIf_IncPortGroupHostOrUpLinkPortRoleLinkCount(Index)                                      EthIf_GetPortGroupHostOrUpLinkPortRoleLinkCount(Index)++
#define EthIf_IncPortGroupLaxLinkAggregationCount(Index)                                            EthIf_GetPortGroupLaxLinkAggregationCount(Index)++
#define EthIf_IncPortGroupNoRoleLinkCount(Index)                                                    EthIf_GetPortGroupNoRoleLinkCount(Index)++
#define EthIf_IncPortStartupActiveTimeCounter()                                                     EthIf_GetPortStartupActiveTimeCounter()++
#define EthIf_IncSignalQualityDecoupleFreqCnt()                                                     EthIf_GetSignalQualityDecoupleFreqCnt()++
#define EthIf_IncEthIfCtrlIdxOfTxContext(Index)                                                     EthIf_GetEthIfCtrlIdxOfTxContext(Index)++
#define EthIf_IncPayloadLenOfTxContext(Index)                                                       EthIf_GetPayloadLenOfTxContext(Index)++
#define EthIf_IncUserIdxOfTxContext(Index)                                                          EthIf_GetUserIdxOfTxContext(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCDecrementDataMacros  EthIf Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define EthIf_DecEthCtrlInitCnt(Index)                                                              EthIf_GetEthCtrlInitCnt(Index)--
#define EthIf_DecEthCtrlModeCnt(Index)                                                              EthIf_GetEthCtrlModeCnt(Index)--
#define EthIf_DecEthCtrlRxFrameCnt(Index)                                                           EthIf_GetEthCtrlRxFrameCnt(Index)--
#define EthIf_DecEthIfCtrlLinkCount(Index)                                                          EthIf_GetEthIfCtrlLinkCount(Index)--
#define EthIf_DecNumRxBytesOfEthIfCtrlRxStats(Index)                                                EthIf_GetNumRxBytesOfEthIfCtrlRxStats(Index)--
#define EthIf_DecNumRxPktsOfEthIfCtrlRxStats(Index)                                                 EthIf_GetNumRxPktsOfEthIfCtrlRxStats(Index)--
#define EthIf_DecNumTxBytesOfEthIfCtrlTxStats(Index)                                                EthIf_GetNumTxBytesOfEthIfCtrlTxStats(Index)--
#define EthIf_DecNumTxPktsOfEthIfCtrlTxStats(Index)                                                 EthIf_GetNumTxPktsOfEthIfCtrlTxStats(Index)--
#define EthIf_DecDropCtrlIdxOfEthIfMeasurementData(Index)                                           EthIf_GetDropCtrlIdxOfEthIfMeasurementData(Index)--
#define EthIf_DecUnknownEtherTypeOfEthIfMeasurementData(Index)                                      EthIf_GetUnknownEtherTypeOfEthIfMeasurementData(Index)--
#define EthIf_DecVlanDoubleTaggedOfEthIfMeasurementData(Index)                                      EthIf_GetVlanDoubleTaggedOfEthIfMeasurementData(Index)--
#define EthIf_DecEthSwtInitCnt(Index)                                                               EthIf_GetEthSwtInitCnt(Index)--
#define EthIf_DecEthSwtPortModeCnt(Index)                                                           EthIf_GetEthSwtPortModeCnt(Index)--
#define EthIf_DecEthTrcvInitCnt(Index)                                                              EthIf_GetEthTrcvInitCnt(Index)--
#define EthIf_DecEthTrcvModeCnt(Index)                                                              EthIf_GetEthTrcvModeCnt(Index)--
#define EthIf_DecMainFuncStateDecoupleFreqCnt()                                                     EthIf_GetMainFuncStateDecoupleFreqCnt()--
#define EthIf_DecDestEthTxBufferIdxOfMirrorTxInfo(Index)                                            EthIf_GetDestEthTxBufferIdxOfMirrorTxInfo(Index)--
#define EthIf_DecEthIfCtrlIdxOfMirrorTxInfo(Index)                                                  EthIf_GetEthIfCtrlIdxOfMirrorTxInfo(Index)--
#define EthIf_DecSrcEthTxBufferIdxOfMirrorTxInfo(Index)                                             EthIf_GetSrcEthTxBufferIdxOfMirrorTxInfo(Index)--
#define EthIf_DecPortGroupHostOrUpLinkPortRoleLinkCount(Index)                                      EthIf_GetPortGroupHostOrUpLinkPortRoleLinkCount(Index)--
#define EthIf_DecPortGroupLaxLinkAggregationCount(Index)                                            EthIf_GetPortGroupLaxLinkAggregationCount(Index)--
#define EthIf_DecPortGroupNoRoleLinkCount(Index)                                                    EthIf_GetPortGroupNoRoleLinkCount(Index)--
#define EthIf_DecPortStartupActiveTimeCounter()                                                     EthIf_GetPortStartupActiveTimeCounter()--
#define EthIf_DecSignalQualityDecoupleFreqCnt()                                                     EthIf_GetSignalQualityDecoupleFreqCnt()--
#define EthIf_DecEthIfCtrlIdxOfTxContext(Index)                                                     EthIf_GetEthIfCtrlIdxOfTxContext(Index)--
#define EthIf_DecPayloadLenOfTxContext(Index)                                                       EthIf_GetPayloadLenOfTxContext(Index)--
#define EthIf_DecUserIdxOfTxContext(Index)                                                          EthIf_GetUserIdxOfTxContext(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCAddDataMacros  EthIf Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define EthIf_AddEthCtrlInitCnt(Index, Value)                                                       EthIf_SetEthCtrlInitCnt(Index, (EthIf_GetEthCtrlInitCnt(Index) + Value))
#define EthIf_AddEthCtrlModeCnt(Index, Value)                                                       EthIf_SetEthCtrlModeCnt(Index, (EthIf_GetEthCtrlModeCnt(Index) + Value))
#define EthIf_AddEthCtrlRxFrameCnt(Index, Value)                                                    EthIf_SetEthCtrlRxFrameCnt(Index, (EthIf_GetEthCtrlRxFrameCnt(Index) + Value))
#define EthIf_AddEthIfCtrlLinkCount(Index, Value)                                                   EthIf_SetEthIfCtrlLinkCount(Index, (EthIf_GetEthIfCtrlLinkCount(Index) + Value))
#define EthIf_AddNumRxBytesOfEthIfCtrlRxStats(Index, Value)                                         EthIf_SetNumRxBytesOfEthIfCtrlRxStats(Index, (EthIf_GetNumRxBytesOfEthIfCtrlRxStats(Index) + Value))
#define EthIf_AddNumRxPktsOfEthIfCtrlRxStats(Index, Value)                                          EthIf_SetNumRxPktsOfEthIfCtrlRxStats(Index, (EthIf_GetNumRxPktsOfEthIfCtrlRxStats(Index) + Value))
#define EthIf_AddNumTxBytesOfEthIfCtrlTxStats(Index, Value)                                         EthIf_SetNumTxBytesOfEthIfCtrlTxStats(Index, (EthIf_GetNumTxBytesOfEthIfCtrlTxStats(Index) + Value))
#define EthIf_AddNumTxPktsOfEthIfCtrlTxStats(Index, Value)                                          EthIf_SetNumTxPktsOfEthIfCtrlTxStats(Index, (EthIf_GetNumTxPktsOfEthIfCtrlTxStats(Index) + Value))
#define EthIf_AddDropCtrlIdxOfEthIfMeasurementData(Index, Value)                                    EthIf_SetDropCtrlIdxOfEthIfMeasurementData(Index, (EthIf_GetDropCtrlIdxOfEthIfMeasurementData(Index) + Value))
#define EthIf_AddUnknownEtherTypeOfEthIfMeasurementData(Index, Value)                               EthIf_SetUnknownEtherTypeOfEthIfMeasurementData(Index, (EthIf_GetUnknownEtherTypeOfEthIfMeasurementData(Index) + Value))
#define EthIf_AddVlanDoubleTaggedOfEthIfMeasurementData(Index, Value)                               EthIf_SetVlanDoubleTaggedOfEthIfMeasurementData(Index, (EthIf_GetVlanDoubleTaggedOfEthIfMeasurementData(Index) + Value))
#define EthIf_AddEthSwtInitCnt(Index, Value)                                                        EthIf_SetEthSwtInitCnt(Index, (EthIf_GetEthSwtInitCnt(Index) + Value))
#define EthIf_AddEthSwtPortModeCnt(Index, Value)                                                    EthIf_SetEthSwtPortModeCnt(Index, (EthIf_GetEthSwtPortModeCnt(Index) + Value))
#define EthIf_AddEthTrcvInitCnt(Index, Value)                                                       EthIf_SetEthTrcvInitCnt(Index, (EthIf_GetEthTrcvInitCnt(Index) + Value))
#define EthIf_AddEthTrcvModeCnt(Index, Value)                                                       EthIf_SetEthTrcvModeCnt(Index, (EthIf_GetEthTrcvModeCnt(Index) + Value))
#define EthIf_AddMainFuncStateDecoupleFreqCnt(Value)                                                EthIf_SetMainFuncStateDecoupleFreqCnt((EthIf_GetMainFuncStateDecoupleFreqCnt() + Value))
#define EthIf_AddDestEthTxBufferIdxOfMirrorTxInfo(Index, Value)                                     EthIf_SetDestEthTxBufferIdxOfMirrorTxInfo(Index, (EthIf_GetDestEthTxBufferIdxOfMirrorTxInfo(Index) + Value))
#define EthIf_AddEthIfCtrlIdxOfMirrorTxInfo(Index, Value)                                           EthIf_SetEthIfCtrlIdxOfMirrorTxInfo(Index, (EthIf_GetEthIfCtrlIdxOfMirrorTxInfo(Index) + Value))
#define EthIf_AddSrcEthTxBufferIdxOfMirrorTxInfo(Index, Value)                                      EthIf_SetSrcEthTxBufferIdxOfMirrorTxInfo(Index, (EthIf_GetSrcEthTxBufferIdxOfMirrorTxInfo(Index) + Value))
#define EthIf_AddPortGroupHostOrUpLinkPortRoleLinkCount(Index, Value)                               EthIf_SetPortGroupHostOrUpLinkPortRoleLinkCount(Index, (EthIf_GetPortGroupHostOrUpLinkPortRoleLinkCount(Index) + Value))
#define EthIf_AddPortGroupLaxLinkAggregationCount(Index, Value)                                     EthIf_SetPortGroupLaxLinkAggregationCount(Index, (EthIf_GetPortGroupLaxLinkAggregationCount(Index) + Value))
#define EthIf_AddPortGroupNoRoleLinkCount(Index, Value)                                             EthIf_SetPortGroupNoRoleLinkCount(Index, (EthIf_GetPortGroupNoRoleLinkCount(Index) + Value))
#define EthIf_AddPortStartupActiveTimeCounter(Value)                                                EthIf_SetPortStartupActiveTimeCounter((EthIf_GetPortStartupActiveTimeCounter() + Value))
#define EthIf_AddSignalQualityDecoupleFreqCnt(Value)                                                EthIf_SetSignalQualityDecoupleFreqCnt((EthIf_GetSignalQualityDecoupleFreqCnt() + Value))
#define EthIf_AddEthIfCtrlIdxOfTxContext(Index, Value)                                              EthIf_SetEthIfCtrlIdxOfTxContext(Index, (EthIf_GetEthIfCtrlIdxOfTxContext(Index) + Value))
#define EthIf_AddPayloadLenOfTxContext(Index, Value)                                                EthIf_SetPayloadLenOfTxContext(Index, (EthIf_GetPayloadLenOfTxContext(Index) + Value))
#define EthIf_AddUserIdxOfTxContext(Index, Value)                                                   EthIf_SetUserIdxOfTxContext(Index, (EthIf_GetUserIdxOfTxContext(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCSubstractDataMacros  EthIf Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define EthIf_SubEthCtrlInitCnt(Index, Value)                                                       EthIf_SetEthCtrlInitCnt(Index, (EthIf_GetEthCtrlInitCnt(Index) - Value))
#define EthIf_SubEthCtrlModeCnt(Index, Value)                                                       EthIf_SetEthCtrlModeCnt(Index, (EthIf_GetEthCtrlModeCnt(Index) - Value))
#define EthIf_SubEthCtrlRxFrameCnt(Index, Value)                                                    EthIf_SetEthCtrlRxFrameCnt(Index, (EthIf_GetEthCtrlRxFrameCnt(Index) - Value))
#define EthIf_SubEthIfCtrlLinkCount(Index, Value)                                                   EthIf_SetEthIfCtrlLinkCount(Index, (EthIf_GetEthIfCtrlLinkCount(Index) - Value))
#define EthIf_SubNumRxBytesOfEthIfCtrlRxStats(Index, Value)                                         EthIf_SetNumRxBytesOfEthIfCtrlRxStats(Index, (EthIf_GetNumRxBytesOfEthIfCtrlRxStats(Index) - Value))
#define EthIf_SubNumRxPktsOfEthIfCtrlRxStats(Index, Value)                                          EthIf_SetNumRxPktsOfEthIfCtrlRxStats(Index, (EthIf_GetNumRxPktsOfEthIfCtrlRxStats(Index) - Value))
#define EthIf_SubNumTxBytesOfEthIfCtrlTxStats(Index, Value)                                         EthIf_SetNumTxBytesOfEthIfCtrlTxStats(Index, (EthIf_GetNumTxBytesOfEthIfCtrlTxStats(Index) - Value))
#define EthIf_SubNumTxPktsOfEthIfCtrlTxStats(Index, Value)                                          EthIf_SetNumTxPktsOfEthIfCtrlTxStats(Index, (EthIf_GetNumTxPktsOfEthIfCtrlTxStats(Index) - Value))
#define EthIf_SubDropCtrlIdxOfEthIfMeasurementData(Index, Value)                                    EthIf_SetDropCtrlIdxOfEthIfMeasurementData(Index, (EthIf_GetDropCtrlIdxOfEthIfMeasurementData(Index) - Value))
#define EthIf_SubUnknownEtherTypeOfEthIfMeasurementData(Index, Value)                               EthIf_SetUnknownEtherTypeOfEthIfMeasurementData(Index, (EthIf_GetUnknownEtherTypeOfEthIfMeasurementData(Index) - Value))
#define EthIf_SubVlanDoubleTaggedOfEthIfMeasurementData(Index, Value)                               EthIf_SetVlanDoubleTaggedOfEthIfMeasurementData(Index, (EthIf_GetVlanDoubleTaggedOfEthIfMeasurementData(Index) - Value))
#define EthIf_SubEthSwtInitCnt(Index, Value)                                                        EthIf_SetEthSwtInitCnt(Index, (EthIf_GetEthSwtInitCnt(Index) - Value))
#define EthIf_SubEthSwtPortModeCnt(Index, Value)                                                    EthIf_SetEthSwtPortModeCnt(Index, (EthIf_GetEthSwtPortModeCnt(Index) - Value))
#define EthIf_SubEthTrcvInitCnt(Index, Value)                                                       EthIf_SetEthTrcvInitCnt(Index, (EthIf_GetEthTrcvInitCnt(Index) - Value))
#define EthIf_SubEthTrcvModeCnt(Index, Value)                                                       EthIf_SetEthTrcvModeCnt(Index, (EthIf_GetEthTrcvModeCnt(Index) - Value))
#define EthIf_SubMainFuncStateDecoupleFreqCnt(Value)                                                EthIf_SetMainFuncStateDecoupleFreqCnt((EthIf_GetMainFuncStateDecoupleFreqCnt() - Value))
#define EthIf_SubDestEthTxBufferIdxOfMirrorTxInfo(Index, Value)                                     EthIf_SetDestEthTxBufferIdxOfMirrorTxInfo(Index, (EthIf_GetDestEthTxBufferIdxOfMirrorTxInfo(Index) - Value))
#define EthIf_SubEthIfCtrlIdxOfMirrorTxInfo(Index, Value)                                           EthIf_SetEthIfCtrlIdxOfMirrorTxInfo(Index, (EthIf_GetEthIfCtrlIdxOfMirrorTxInfo(Index) - Value))
#define EthIf_SubSrcEthTxBufferIdxOfMirrorTxInfo(Index, Value)                                      EthIf_SetSrcEthTxBufferIdxOfMirrorTxInfo(Index, (EthIf_GetSrcEthTxBufferIdxOfMirrorTxInfo(Index) - Value))
#define EthIf_SubPortGroupHostOrUpLinkPortRoleLinkCount(Index, Value)                               EthIf_SetPortGroupHostOrUpLinkPortRoleLinkCount(Index, (EthIf_GetPortGroupHostOrUpLinkPortRoleLinkCount(Index) - Value))
#define EthIf_SubPortGroupLaxLinkAggregationCount(Index, Value)                                     EthIf_SetPortGroupLaxLinkAggregationCount(Index, (EthIf_GetPortGroupLaxLinkAggregationCount(Index) - Value))
#define EthIf_SubPortGroupNoRoleLinkCount(Index, Value)                                             EthIf_SetPortGroupNoRoleLinkCount(Index, (EthIf_GetPortGroupNoRoleLinkCount(Index) - Value))
#define EthIf_SubPortStartupActiveTimeCounter(Value)                                                EthIf_SetPortStartupActiveTimeCounter((EthIf_GetPortStartupActiveTimeCounter() - Value))
#define EthIf_SubSignalQualityDecoupleFreqCnt(Value)                                                EthIf_SetSignalQualityDecoupleFreqCnt((EthIf_GetSignalQualityDecoupleFreqCnt() - Value))
#define EthIf_SubEthIfCtrlIdxOfTxContext(Index, Value)                                              EthIf_SetEthIfCtrlIdxOfTxContext(Index, (EthIf_GetEthIfCtrlIdxOfTxContext(Index) - Value))
#define EthIf_SubPayloadLenOfTxContext(Index, Value)                                                EthIf_SetPayloadLenOfTxContext(Index, (EthIf_GetPayloadLenOfTxContext(Index) - Value))
#define EthIf_SubUserIdxOfTxContext(Index, Value)                                                   EthIf_SetUserIdxOfTxContext(Index, (EthIf_GetUserIdxOfTxContext(Index) - Value))
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/

# if !defined(ETHIF_UNIT_TEST)
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/

# endif /* ETHIF_UNIT_TEST */

#endif /* ETHIF_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: EthIf_Lcfg.h
 *********************************************************************************************************************/


