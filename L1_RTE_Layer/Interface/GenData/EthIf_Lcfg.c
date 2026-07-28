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
 *              File: EthIf_Lcfg.c
 *   Generation Time: 2025-09-11 13:39:32
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#define ETHIF_LCFG_SOURCE

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0777 EOF */ /* MD_MSR_5.1_777 */
/* PRQA S 0779 EOF */ /* MD_MSR_5.1_779 */

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/

/*********************************************************************************************************
 * Predefined file includes based on \trace DSGN-EthIfDiag1977
 *********************************************************************************************************/
#include "EthIf_Lcfg.h"

/*********************************************************************************************************
 * Dynamic includes depending on configuration
 *********************************************************************************************************/

#include "TcpIp.h"
#include "Slac.h"
#include "Slac_Cbk.h"
#include "Scc_Cbk.h"

#include "Eth_30_Ar7000.h"

#include "EthTrcv_30_Ar7000.h"


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  EthIf_EthCtrl
**********************************************************************************************************************/
/** 
  \var    EthIf_EthCtrl
  \brief  Eth controllers abstracted by the EthIf
  \details
  Element              Description
  Snv                  SNV of the Eth controller
  EthDrvApiIdx         the index of the 1:1 relation pointing to EthIf_EthDrvApi
  TxContextEndIdx      the end index of the 1:n relation pointing to EthIf_TxContext
  TxContextStartIdx    the start index of the 1:n relation pointing to EthIf_TxContext
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthIf_EthCtrlType, ETHIF_CONST) EthIf_EthCtrl[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Snv                                  EthDrvApiIdx                       TxContextEndIdx                                                           TxContextStartIdx                                                                 Referable Keys */
  { /*     0 */ EthConf_EthCtrlConfig_EthCtrlConfig,           0u  /* Eth_30_Ar7000 */,              2u  /* /ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig */,                0u  /* /ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig */ }   /* [/ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig, /ActiveEcuC/EthIf/EthIfConfigSet/EthIfController] */
};
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthDrvApi
**********************************************************************************************************************/
/** 
  \var    EthIf_EthDrvApi
  \brief  APIs of the Ethernet drivers abstracted by EthIf
  \details
  Element                  Description
  CtrlInit                 Eth_ControllerInit() of Eth driver
  EnableEgressTimeStamp    Eth_EnableEgressTimeStamp() of Eth driver.
  GetBandwidthLimit        Eth_GetBandwidthLimit() of Eth driver.
  GetCtrlMode              Eth_GetControllerMode() of Eth driver
  GetCurrentTime           Eth_GetCurrentTime() of Eth driver.
  GetEgressTimeStamp       Eth_GetEgressTimeStamp() of Eth driver.
  GetIngressTimeStamp      Eth_GetIngressTimeStamp() of Eth driver.
  GetPhysAddr              Eth_GetPhysAddr() of Eth driver
  GetRxHeaderPtr           Eth_GetRxHeaderPtr() of Eth driver.
  GetRxStats               Eth_GetRxStats() of Eth driver
  GetTxHeaderPtr           Eth_GetTxHeaderPtr() of Eth driver.
  GetTxStats               Eth_GetTxStats() of Eth driver
  ProvideExtTxBuffer       Eth_ProvideExtTxBuffer() of Eth driver.
  ProvideTxBuffer          Eth_ProvideTxBuffer() of Eth driver
  Receive                  Eth_Receive() of Eth driver
  ReleaseRxBuffer          Eth_ReleaseRxBuffer() of Eth driver.
  SetBandwidthLimit        Eth_SetBandwidthLimit() of Eth driver.
  SetCtrlMode              Eth_SetControllerMode() of Eth driver
  SetPhysAddr              Eth_SetPhysAddr() of Eth driver
  Transmit                 Eth_Transmit() of Eth driver
  TxConf                   Eth_TxConfirmation() of Eth driver
  UpdatePhysAddrFilter     Eth_UpdatePhysAddrFilter() of Eth driver
  VTransmit                Eth_VTransmit() of Eth driver
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthIf_EthDrvApiType, ETHIF_CONST) EthIf_EthDrvApi[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CtrlInit                      EnableEgressTimeStamp  GetBandwidthLimit  GetCtrlMode                      GetCurrentTime  GetEgressTimeStamp  GetIngressTimeStamp  GetPhysAddr                GetRxHeaderPtr  GetRxStats  GetTxHeaderPtr  GetTxStats  ProvideExtTxBuffer  ProvideTxBuffer                Receive                ReleaseRxBuffer  SetBandwidthLimit  SetCtrlMode                      SetPhysAddr                Transmit                TxConf                        UpdatePhysAddrFilter                VTransmit                      Referable Keys */
  { /*     0 */ Eth_30_Ar7000_ControllerInit, NULL_PTR             , NULL_PTR         , Eth_30_Ar7000_GetControllerMode, NULL_PTR      , NULL_PTR          , NULL_PTR           , Eth_30_Ar7000_GetPhysAddr, NULL_PTR      , NULL_PTR  , NULL_PTR      , NULL_PTR  , NULL_PTR          , Eth_30_Ar7000_ProvideTxBuffer, Eth_30_Ar7000_Receive, NULL_PTR       , NULL_PTR         , Eth_30_Ar7000_SetControllerMode, Eth_30_Ar7000_SetPhysAddr, Eth_30_Ar7000_Transmit, Eth_30_Ar7000_TxConfirmation, Eth_30_Ar7000_UpdatePhysAddrFilter, Eth_30_Ar7000_VTransmit }   /* [Eth_30_Ar7000, /ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig] */
};
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfCtrl
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfCtrl
  \brief  EthIf controllers
  \details
  Element                       Description
  Snv                           SNV of the EthIf Controller
  Mtu                           Maximum transfer unit of the EthIf Controller
  VlanId                        VLAN ID associated with the EthIf Controller
  EthCtrlIdx                    the index of the 1:1 relation pointing to EthIf_EthCtrl
  EthIfPhysCtrlCfgIdx           the index of the 1:1 relation pointing to EthIf_EthIfPhysCtrlCfg
  EthSwtDrvApiIdx               the index of the 0:1 relation pointing to EthIf_EthSwtDrvApi
  GatewayDestEthIfCtrlIdx   
  GatewayDestEthIfCtrlIdxIdx    the index of the 0:1 relation pointing to EthIf_EthIfCtrl
  LinkAggrThreshold             Threshold when a link is issued on EthIf controller level.
  MacSecType                    MACsec Type of the EthIf Controller
  MirrorRxDestIdx           
  MirrorRxDestIdxIdx            the index of the 0:1 relation pointing to EthIf_MirrorDest
  MirrorTxDestIdx           
  MirrorTxDestIdxIdx            the index of the 0:1 relation pointing to EthIf_MirrorDest
  PhysLayerInitElemsIdx         the index of the 1:1 relation pointing to EthIf_PhysLayerInitElems
  PhysLayerModeElemsIdx         the index of the 1:1 relation pointing to EthIf_PhysLayerModeElems
  Type                          Type of the EthIf Controller
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthIf_EthIfCtrlType, ETHIF_CONST) EthIf_EthIfCtrl[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Snv                                        Mtu    VlanId             EthCtrlIdx                                                           EthIfPhysCtrlCfgIdx                                                              EthSwtDrvApiIdx                                                                              GatewayDestEthIfCtrlIdx                      GatewayDestEthIfCtrlIdxIdx                                     LinkAggrThreshold  MacSecType                             MirrorRxDestIdx                      MirrorRxDestIdxIdx                                                                              MirrorTxDestIdx                      MirrorTxDestIdxIdx                                                                              PhysLayerInitElemsIdx                                                          PhysLayerModeElemsIdx                                                          Type                                                 Referable Keys */
  { /*     0 */ EthIfConf_EthIfController_EthIfController, 1500u, ETHIF_INV_VLAN_ID,         0u  /* /ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig */,                  0u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIfPhysController */, ETHIF_NO_ETHSWTDRVAPIIDXOFETHIFCTRL  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIfController */, ETHIF_NO_GATEWAYDESTETHIFCTRLIDXOFETHIFCTRL, ETHIF_NO_GATEWAYDESTETHIFCTRLIDXIDXOFETHIFCTRL  /* No_Dest */,                1u, ETHIF_NO_MACSEC_MACSECTYPEOFETHIFCTRL, ETHIF_NO_MIRRORRXDESTIDXOFETHIFCTRL, ETHIF_NO_MIRRORRXDESTIDXIDXOFETHIFCTRL  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIfController */, ETHIF_NO_MIRRORTXDESTIDXOFETHIFCTRL, ETHIF_NO_MIRRORTXDESTIDXIDXOFETHIFCTRL  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIfController */,                    0u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIfController */,                    0u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIfController */, ETHIF_ETHIFCTRL_TYPE_PHYSICAL_TYPEOFETHIFCTRL }   /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIfController, /ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig, /ActiveEcuC/EthTrcv_Ar7000/EthTrcvConfigSet/EthTrcvConfig] */
};
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfCtrlOfEthTrcvInd
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfCtrlOfEthTrcvInd
  \brief  the indexes of the 1:1 sorted relation pointing to EthIf_EthIfCtrl
*/ 
#define ETHIF_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthIf_EthIfCtrlOfEthTrcvIndType, ETHIF_CONST) EthIf_EthIfCtrlOfEthTrcvInd[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     EthIfCtrlOfEthTrcvInd      Referable Keys */
  /*     0 */                     0u   /* [/ActiveEcuC/EthTrcv_Ar7000/EthTrcvConfigSet/EthTrcvConfig] */
};
#define ETHIF_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfPhysCtrlCfg
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfPhysCtrlCfg
  \brief  Configuration of EthIfPhysController abstracted by EthIf
  \details
  Element                   Description
  EthCtrlIdx                SNV of the Eth controller
  EthIfPhysControllerIdx    Zero-based consecutive index of the physical Ethernet Controllers in EthIf context.
  EthPhcSupportAvailable    Indicates if the PhcSupport APIs (AR&gt;=23-11) are supported by the controller.
  EthDrvApiIdx              the index of the 1:1 relation pointing to EthIf_EthDrvApi
  EthIfClkUnitEndIdx        the end index of the 0:n relation pointing to EthIf_EthIfClkUnit
  EthIfClkUnitStartIdx      the start index of the 0:n relation pointing to EthIf_EthIfClkUnit
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthIf_EthIfPhysCtrlCfgType, ETHIF_CONST) EthIf_EthIfPhysCtrlCfg[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    EthCtrlIdx                           EthIfPhysControllerIdx                             EthPhcSupportAvailable  EthDrvApiIdx                       EthIfClkUnitEndIdx                                                                                         EthIfClkUnitStartIdx                                                                                               Referable Keys */
  { /*     0 */ EthConf_EthCtrlConfig_EthCtrlConfig, EthIfConf_EthIfPhysController_EthIfPhysController,                  FALSE,           0u  /* Eth_30_Ar7000 */, ETHIF_NO_ETHIFCLKUNITENDIDXOFETHIFPHYSCTRLCFG  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIfPhysController */, ETHIF_NO_ETHIFCLKUNITSTARTIDXOFETHIFPHYSCTRLCFG  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIfPhysController */ }   /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIfPhysController, /ActiveEcuC/EthIf/EthIfConfigSet/EthIfController] */
};
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthTrcv
**********************************************************************************************************************/
/** 
  \var    EthIf_EthTrcv
  \brief  Eth transceivers abstracted by EthIf
  \details
  Element                          Description
  Snv                              SNV of the EthTrcv
  MacSecSecured                    Indicates if transceiver is MACsec secured
  EthIfCtrlOfEthTrcvIndEndIdx      the end index of the 0:n relation pointing to EthIf_EthIfCtrlOfEthTrcvInd
  EthIfCtrlOfEthTrcvIndStartIdx    the start index of the 0:n relation pointing to EthIf_EthIfCtrlOfEthTrcvInd
  EthTrcvDrvApiIdx                 the index of the 1:1 relation pointing to EthIf_EthTrcvDrvApi
  MkaPaeIdx                        PaeIdx of transceiver
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthIf_EthTrcvType, ETHIF_CONST) EthIf_EthTrcv[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Snv                                      MacSecSecured  EthIfCtrlOfEthTrcvIndEndIdx                                                                   EthIfCtrlOfEthTrcvIndStartIdx                                                                   EthTrcvDrvApiIdx                           MkaPaeIdx        Referable Keys */
  { /*     0 */ EthTrcvConf_EthTrcvConfig_EthTrcvConfig,         FALSE,                          1u  /* /ActiveEcuC/EthTrcv_Ar7000/EthTrcvConfigSet/EthTrcvConfig */,                            0u  /* /ActiveEcuC/EthTrcv_Ar7000/EthTrcvConfigSet/EthTrcvConfig */,               0u  /* EthTrcv_30_Ar7000 */,        0u }   /* [/ActiveEcuC/EthTrcv_Ar7000/EthTrcvConfigSet/EthTrcvConfig, /ActiveEcuC/EthIf/EthIfConfigSet/EthIfController] */
};
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthTrcvDrvApi
**********************************************************************************************************************/
/** 
  \var    EthIf_EthTrcvDrvApi
  \brief  APIs of the EthTrcv drivers abstracted by EthIf
  \details
  Element                      Description
  CheckWakeup                  EthTrcv_CheckWakeupe() of the EthTrcv driver
  GetBaudRate                  EthTrcv_GetBaudRate() of the EthTrcv driver
  GetCableDiagnosticsResult    EthTrcv_GetCableDiagnosticsResult() of the EthTrcv driver
  GetDuplexMode                EthTrcv_GetDuplexMode() of the EthTrcv driver
  GetLinkState                 EthTrcv_GetLinkState() of the EthTrcv driver
  GetPhySignalQuality          EthTrcv_GetPhySignalQuality() of the EthTrcv driver
  GetTrcvMode                  EthTrcv_GetTransceiverMode() of the EthTrcv driver
  GetTrcvWakeupMode            EthTrcv_GetTransceiverWakeupMode() of the EthTrcv driver
  RunCableDiagnostic           RunCableDiagnostic() of the EthTrcv driver
  SetPhyLoopbackMode           SetPhyLoopbackMode() of the EthTrcv driver
  SetPhyTestMode               EthTrcv_SetPhyTestMode() of the EthTrcv driver
  SetPhyTxMode                 EthTrcv_SetPhyTxMode() of the EthTrcv driver
  SetTrcvMode                  EthTrcv_SetTransceiverMode() of the EthTrcv driver
  SetTrcvWakeupMode            EthTrcv_SetTransceiverWakeupMode() of the EthTrcv driver
  StartAutoNeg                 EthTrcv_StartAutoNegotiation() of the EthTrcv driver
  TrcvInit                     EthTrcv_TransceiverInit() of the EthTrcv driver
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthIf_EthTrcvDrvApiType, ETHIF_CONST) EthIf_EthTrcvDrvApi[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CheckWakeup  GetBaudRate                    GetCableDiagnosticsResult                    GetDuplexMode                    GetLinkState                    GetPhySignalQuality                    GetTrcvMode                           GetTrcvWakeupMode  RunCableDiagnostic  SetPhyLoopbackMode  SetPhyTestMode                    SetPhyTxMode                    SetTrcvMode                           SetTrcvWakeupMode  StartAutoNeg                            TrcvInit                                 Referable Keys */
  { /*     0 */ NULL_PTR   , EthTrcv_30_Ar7000_GetBaudRate, EthTrcv_30_Ar7000_GetCableDiagnosticsResult, EthTrcv_30_Ar7000_GetDuplexMode, EthTrcv_30_Ar7000_GetLinkState, EthTrcv_30_Ar7000_GetPhySignalQuality, EthTrcv_30_Ar7000_GetTransceiverMode, NULL_PTR         , NULL_PTR          , NULL_PTR          , EthTrcv_30_Ar7000_SetPhyTestMode, EthTrcv_30_Ar7000_SetPhyTxMode, EthTrcv_30_Ar7000_SetTransceiverMode, NULL_PTR         , EthTrcv_30_Ar7000_StartAutoNegotiation, EthTrcv_30_Ar7000_TransceiverInit }   /* [EthTrcv_30_Ar7000, /ActiveEcuC/EthTrcv_Ar7000/EthTrcvConfigSet/EthTrcvConfig] */
};
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_LinkStateChgIndications
**********************************************************************************************************************/
/** 
  \var    EthIf_LinkStateChgIndications
  \brief  Link State change indications of the EthIf users.
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthIf_LinkStateChgIndFctPtrType, ETHIF_CONST) EthIf_LinkStateChgIndications[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     LinkStateChgIndications                 */
  /*     0 */ Slac_Cbk_TrcvLinkStateChanged          ,
  /*     1 */ Scc_Cbk_Eth_TransceiverLinkStateChange 
};
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_PhysLayerInitElems
**********************************************************************************************************************/
/** 
  \var    EthIf_PhysLayerInitElems
  \brief  Hardware that the EthIf controllers trigger initialization for
  \details
  Element              Description
  EthSwtIndEndIdx      the end index of the 0:n relation pointing to EthIf_EthSwtInd
  EthSwtIndStartIdx    the start index of the 0:n relation pointing to EthIf_EthSwtInd
  EthTrcvIdx           the index of the 0:1 relation pointing to EthIf_EthTrcv
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthIf_PhysLayerInitElemsType, ETHIF_CONST) EthIf_PhysLayerInitElems[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    EthSwtIndEndIdx                                                                                       EthSwtIndStartIdx                                                                                       EthTrcvIdx                                                                Referable Keys */
  { /*     0 */ ETHIF_NO_ETHSWTINDENDIDXOFPHYSLAYERINITELEMS  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIfController */, ETHIF_NO_ETHSWTINDSTARTIDXOFPHYSLAYERINITELEMS  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIfController */,         0u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIfController */ }   /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIfController] */
};
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_PhysLayerModeElems
**********************************************************************************************************************/
/** 
  \var    EthIf_PhysLayerModeElems
  \brief  Hardware that the EthIf controllers trigger mode changes for
  \details
  Element         Description
  EthTrcvIdx      the index of the 0:1 relation pointing to EthIf_EthTrcv
  PortGroupIdx    the index of the 0:1 relation pointing to EthIf_PortGroup
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthIf_PhysLayerModeElemsType, ETHIF_CONST) EthIf_PhysLayerModeElems[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    EthTrcvIdx                                                          PortGroupIdx                                                                                             Referable Keys */
  { /*     0 */         0u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIfController */, ETHIF_NO_PORTGROUPIDXOFPHYSLAYERMODEELEMS  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIfController */ }   /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIfController] */
};
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_RxIndications
**********************************************************************************************************************/
/** 
  \var    EthIf_RxIndications
  \brief  Rx indications of the EthIf users.
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthIf_RxIndFctPtrType, ETHIF_CONST) EthIf_RxIndications[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxIndications              Referable Keys */
  /*     0 */ Slac_Cbk_RxIndication ,  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIfRxIndicationConfig_Slac, /ActiveEcuC/EthIf/EthIfConfigSet/EthIfFrameOwnerConfig_Slac] */
  /*     1 */ IpV6_RxIndication        /* [/ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_IPv6_RxIndication, /ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_IPv6] */
};
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_RxIndicationsInd
**********************************************************************************************************************/
/** 
  \var    EthIf_RxIndicationsInd
  \brief  the indexes of the 1:1 sorted relation pointing to EthIf_RxIndications
*/ 
#define ETHIF_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthIf_RxIndicationsIndType, ETHIF_CONST) EthIf_RxIndicationsInd[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxIndicationsInd      Referable Keys */
  /*     0 */                1u,  /* [/ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_IPv6] */
  /*     1 */                0u   /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIfFrameOwnerConfig_Slac] */
};
#define ETHIF_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_TxConfirmations
**********************************************************************************************************************/
/** 
  \var    EthIf_TxConfirmations
  \brief  Tx confirmations of the EthIf users.
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthIf_TxConfFctPtrType, ETHIF_CONST) EthIf_TxConfirmations[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxConfirmations          Referable Keys */
  /*     0 */ IpV6_TxConfirmation    /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIfTxConfirmationConfig, /ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_IPv6] */
};
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_TxConfirmationsInd
**********************************************************************************************************************/
/** 
  \var    EthIf_TxConfirmationsInd
  \brief  the indexes of the 1:1 sorted relation pointing to EthIf_TxConfirmations
*/ 
#define ETHIF_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthIf_TxConfirmationsIndType, ETHIF_CONST) EthIf_TxConfirmationsInd[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxConfirmationsInd      Referable Keys */
  /*     0 */                  0u   /* [/ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_IPv6] */
};
#define ETHIF_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_User
**********************************************************************************************************************/
/** 
  \var    EthIf_User
  \brief  Users of the EthIf
  \details
  Element                       Description
  EtherType                     EtherType of the user
  RxIndicationsIndEndIdx        the end index of the 0:n relation pointing to EthIf_RxIndicationsInd
  RxIndicationsIndStartIdx      the start index of the 0:n relation pointing to EthIf_RxIndicationsInd
  TxConfirmationsIndEndIdx      the end index of the 0:n relation pointing to EthIf_TxConfirmationsInd
  TxConfirmationsIndStartIdx    the start index of the 0:n relation pointing to EthIf_TxConfirmationsInd
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthIf_UserType, ETHIF_CONST) EthIf_User[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    EtherType  RxIndicationsIndEndIdx                                                                     RxIndicationsIndStartIdx                                                                     TxConfirmationsIndEndIdx                                                                                    TxConfirmationsIndStartIdx                                                                                          Referable Keys */
  { /*     0 */   0x86DDu,                     1u  /* /ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_IPv6 */                ,                       0u  /* /ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_IPv6 */                ,                                      1u  /* /ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_IPv6 */                ,                                        0u  /* /ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_IPv6 */                 },  /* [/ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_IPv6] */
  { /*     1 */   0x88E1u,                     2u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIfFrameOwnerConfig_Slac */,                       1u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIfFrameOwnerConfig_Slac */, ETHIF_NO_TXCONFIRMATIONSINDENDIDXOFUSER  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIfFrameOwnerConfig_Slac */, ETHIF_NO_TXCONFIRMATIONSINDSTARTIDXOFUSER  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIfFrameOwnerConfig_Slac */ }   /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIfFrameOwnerConfig_Slac] */
};
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthCtrlInitCnt
**********************************************************************************************************************/
/** 
  \var    EthIf_EthCtrlInitCnt
  \brief  Initialization counts for the Eth controllers abstracted by EthIf
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthIf_EthCtrlInitCntType, ETHIF_VAR_NO_INIT) EthIf_EthCtrlInitCnt[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig, /ActiveEcuC/EthIf/EthIfConfigSet/EthIfController] */

#define ETHIF_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthCtrlModeCnt
**********************************************************************************************************************/
/** 
  \var    EthIf_EthCtrlModeCnt
  \brief  Mode request counts for the Eth controllers abstracted by EthIf
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthIf_EthCtrlModeCntType, ETHIF_VAR_NO_INIT) EthIf_EthCtrlModeCnt[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig, /ActiveEcuC/EthIf/EthIfConfigSet/EthIfController] */

#define ETHIF_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthCtrlState
**********************************************************************************************************************/
/** 
  \var    EthIf_EthCtrlState
  \brief  State of Eth controllers in context of their specific EthIf controllers
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Eth_ModeType, ETHIF_VAR_NO_INIT) EthIf_EthCtrlState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIfController, /ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig, /ActiveEcuC/EthTrcv_Ar7000/EthTrcvConfigSet/EthTrcvConfig] */

#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfCtrlInitState
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfCtrlInitState
  \brief  Initialization state of the EthIf controllers
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthIf_EthIfCtrlInitStateType, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlInitState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIfController, /ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig, /ActiveEcuC/EthTrcv_Ar7000/EthTrcvConfigSet/EthTrcvConfig] */

#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfCtrlLinkCount
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfCtrlLinkCount
  \brief  Count of active links on the related hardware layer of the EthIf controllers
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthIf_EthIfCtrlLinkCountType, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlLinkCount[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIfController, /ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig, /ActiveEcuC/EthTrcv_Ar7000/EthTrcvConfigSet/EthTrcvConfig] */

#define ETHIF_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfCtrlLinkState
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfCtrlLinkState
  \brief  Link state of the EthIf controllers.
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthIf_EthIfCtrlLinkStateType, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlLinkState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIfController, /ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig, /ActiveEcuC/EthTrcv_Ar7000/EthTrcvConfigSet/EthTrcvConfig] */

#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfCtrlMode
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfCtrlMode
  \brief  Mode of the EthIf controllers
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Eth_ModeType, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlMode[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIfController, /ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig, /ActiveEcuC/EthTrcv_Ar7000/EthTrcvConfigSet/EthTrcvConfig] */

#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfCtrlRxStats
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfCtrlRxStats
  \brief  Reception statistics for the EthIf controllers
  \details
  Element       Description
  NumRxBytes    Number of bytes received on EthIf controller
  NumRxPkts     Number of packets received on EthIf controller
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthIf_EthIfCtrlRxStatsType, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlRxStats[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIfController, /ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig, /ActiveEcuC/EthTrcv_Ar7000/EthTrcvConfigSet/EthTrcvConfig] */

#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfCtrlTxStats
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfCtrlTxStats
  \brief  Transmission statistics for the EthIf controllers
  \details
  Element       Description
  NumTxBytes    Number of bytes transmitted on EthIf controller
  NumTxPkts     Number of packets transmitted on EthIf controller
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthIf_EthIfCtrlTxStatsType, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlTxStats[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIfController, /ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig, /ActiveEcuC/EthTrcv_Ar7000/EthTrcvConfigSet/EthTrcvConfig] */

#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfMeasurementData
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfMeasurementData
  \brief  EthIf measurement data
  \details
  Element             Description
  DropCtrlIdx         Number of dropped datagrams caused by invalid CtrlIdx/VLAN
  UnknownEtherType    Number of dropped datagrams caused by unknown EtherType
  VlanDoubleTagged    Number of received datagrams with detected double VLAN tag
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthIf_EthIfMeasurementDataType, ETHIF_VAR_NO_INIT) EthIf_EthIfMeasurementData[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfSwtPortGroupState
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfSwtPortGroupState
  \brief  State of EthIf port groups in context of their specific EthIf controllers
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Eth_ModeType, ETHIF_VAR_NO_INIT) EthIf_EthIfSwtPortGroupState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIfController, /ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig, /ActiveEcuC/EthTrcv_Ar7000/EthTrcvConfigSet/EthTrcvConfig] */

#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthTrcvInitCnt
**********************************************************************************************************************/
/** 
  \var    EthIf_EthTrcvInitCnt
  \brief  Initialization counts for the Eth transceivers abstracted by EthIf
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthIf_EthTrcvInitCntType, ETHIF_VAR_NO_INIT) EthIf_EthTrcvInitCnt[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EthTrcv_Ar7000/EthTrcvConfigSet/EthTrcvConfig, /ActiveEcuC/EthIf/EthIfConfigSet/EthIfController] */

#define ETHIF_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthTrcvLinkState
**********************************************************************************************************************/
/** 
  \var    EthIf_EthTrcvLinkState
  \brief  Link state of the EthIf tranceivers.
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthIf_PhyElemLinkStateType, ETHIF_VAR_NO_INIT) EthIf_EthTrcvLinkState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EthTrcv_Ar7000/EthTrcvConfigSet/EthTrcvConfig, /ActiveEcuC/EthIf/EthIfConfigSet/EthIfController] */

#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthTrcvModeCnt
**********************************************************************************************************************/
/** 
  \var    EthIf_EthTrcvModeCnt
  \brief  Mode request counts for the Eth transceivers abstracted by EthIf
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthIf_EthTrcvModeCntType, ETHIF_VAR_NO_INIT) EthIf_EthTrcvModeCnt[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EthTrcv_Ar7000/EthTrcvConfigSet/EthTrcvConfig, /ActiveEcuC/EthIf/EthIfConfigSet/EthIfController] */

#define ETHIF_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthTrcvState
**********************************************************************************************************************/
/** 
  \var    EthIf_EthTrcvState
  \brief  State of Eth Transceiver in context of their specific EthIf controllers
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Eth_ModeType, ETHIF_VAR_NO_INIT) EthIf_EthTrcvState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIfController, /ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig, /ActiveEcuC/EthTrcv_Ar7000/EthTrcvConfigSet/EthTrcvConfig] */

#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_InitLocked
**********************************************************************************************************************/
/** 
  \var    EthIf_InitLocked
  \brief  Semaphore to protect EthIf_ControllerInit() against concurrent calls.
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthIf_InitLockedType, ETHIF_VAR_NO_INIT) EthIf_InitLocked;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHIF_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_MainFuncStateDecoupleFreqCnt
**********************************************************************************************************************/
/** 
  \var    EthIf_MainFuncStateDecoupleFreqCnt
  \brief  Counter used to decouple triggers for link state change observation within EthIf_MainFunctionTx()
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthIf_MainFuncStateDecoupleFreqCntType, ETHIF_VAR_NO_INIT) EthIf_MainFuncStateDecoupleFreqCnt;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHIF_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_ModeChangeLocked
**********************************************************************************************************************/
/** 
  \var    EthIf_ModeChangeLocked
  \brief  Semaphore to protect EthIf_SetControllerMode() against concurrent calls.
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthIf_ModeChangeLockedType, ETHIF_VAR_NO_INIT) EthIf_ModeChangeLocked;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHIF_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_PortStartupActiveTimeCounter
**********************************************************************************************************************/
/** 
  \var    EthIf_PortStartupActiveTimeCounter
  \brief  Counter used to trigger deactivation of switch port groups which were activated through EthIf_StartAllPorts API
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthIf_PortStartupActiveTimeCounterType, ETHIF_VAR_NO_INIT) EthIf_PortStartupActiveTimeCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHIF_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_PortStartupActiveTimerActive
**********************************************************************************************************************/
/** 
  \var    EthIf_PortStartupActiveTimerActive
  \brief  Flag to enable/disable EthIfPortStartupActiveTimer
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthIf_PortStartupActiveTimerActiveType, ETHIF_VAR_NO_INIT) EthIf_PortStartupActiveTimerActive;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHIF_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_SignalQualityDecoupleFreqCnt
**********************************************************************************************************************/
/** 
  \var    EthIf_SignalQualityDecoupleFreqCnt
  \brief  Counter used to decouple triggers for signal quality observation within EthIf_MainFunctionState()
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthIf_SignalQualityDecoupleFreqCntType, ETHIF_VAR_NO_INIT) EthIf_SignalQualityDecoupleFreqCnt;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHIF_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_SignalQualityResult
**********************************************************************************************************************/
/** 
  \var    EthIf_SignalQualityResult
  \brief  Signal Quality of the transceiver.
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthIf_SignalQualityResultType, ETHIF_VAR_NO_INIT) EthIf_SignalQualityResult[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EthTrcv_Ar7000/EthTrcvConfigSet/EthTrcvConfig, /ActiveEcuC/EthIf/EthIfConfigSet/EthIfController] */

#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_SrcMacAddrBuffer
**********************************************************************************************************************/
/** 
  \var    EthIf_SrcMacAddrBuffer
  \brief  Buffer holding latest MAC address used for the Ethernet-controller
  \details
  Element    Description
  Valid      Flag defining if buffer holds a vaild MAC address
  SrcMac     MAC address
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthIf_SrcMacAddrBufferType, ETHIF_VAR_NO_INIT) EthIf_SrcMacAddrBuffer[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig, /ActiveEcuC/EthIf/EthIfConfigSet/EthIfController] */

#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_TxContext
**********************************************************************************************************************/
/** 
  \var    EthIf_TxContext
  \brief  Context information of each tx buffer that can be provided by the Eth drivers
  \details
  Element         Description
  PayloadLen      Length of the frames payload
  EthIfCtrlIdx    Index of the EthIf controller the frame shall be send on
  TxPending       Flag indicating if transmission is pending
  UserIdx         Index of the EthIf user the frame is owned by
  Valid           Flag indicating if the context information is valid (buffer is in use)
  FrameHdr        Ethernet frame header information
  PayloadPtr      Pointer to the frames payload
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthIf_TxContextUType, ETHIF_VAR_NO_INIT) EthIf_TxContext;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig] */
  /*     1 */  /* [/ActiveEcuC/Eth_Ar7000/EthConfigSet/EthCtrlConfig] */

#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_PCConfig
**********************************************************************************************************************/
/** 
  \var    EthIf_PCConfig
  \details
  Element                                   Description
  EthCtrl                                   the pointer to EthIf_EthCtrl
  EthCtrlInitCnt                            the pointer to EthIf_EthCtrlInitCnt
  EthCtrlModeCnt                            the pointer to EthIf_EthCtrlModeCnt
  EthCtrlRxFrameCnt                         the pointer to EthIf_EthCtrlRxFrameCnt
  EthCtrlState                              the pointer to EthIf_EthCtrlState
  EthDrvApi                                 the pointer to EthIf_EthDrvApi
  EthIfClkUnit                              the pointer to EthIf_EthIfClkUnit
  EthIfCtrl                                 the pointer to EthIf_EthIfCtrl
  EthIfCtrlInitState                        the pointer to EthIf_EthIfCtrlInitState
  EthIfCtrlLinkCount                        the pointer to EthIf_EthIfCtrlLinkCount
  EthIfCtrlLinkState                        the pointer to EthIf_EthIfCtrlLinkState
  EthIfCtrlMode                             the pointer to EthIf_EthIfCtrlMode
  EthIfCtrlOfEthTrcvInd                     the pointer to EthIf_EthIfCtrlOfEthTrcvInd
  EthIfCtrlOfPortGroupInd                   the pointer to EthIf_EthIfCtrlOfPortGroupInd
  EthIfCtrlRxStats                          the pointer to EthIf_EthIfCtrlRxStats
  EthIfCtrlTxStats                          the pointer to EthIf_EthIfCtrlTxStats
  EthIfMeasurementData                      the pointer to EthIf_EthIfMeasurementData
  EthIfPhysCtrlCfg                          the pointer to EthIf_EthIfPhysCtrlCfg
  EthIfSwtPortGroupState                    the pointer to EthIf_EthIfSwtPortGroupState
  EthSwt                                    the pointer to EthIf_EthSwt
  EthSwtDrv                                 the pointer to EthIf_EthSwtDrv
  EthSwtDrvApi                              the pointer to EthIf_EthSwtDrvApi
  EthSwtInd                                 the pointer to EthIf_EthSwtInd
  EthSwtInitCnt                             the pointer to EthIf_EthSwtInitCnt
  EthSwtPort                                the pointer to EthIf_EthSwtPort
  EthSwtPortInEthSwtContext                 the pointer to EthIf_EthSwtPortInEthSwtContext
  EthSwtPortInd                             the pointer to EthIf_EthSwtPortInd
  EthSwtPortLinkState                       the pointer to EthIf_EthSwtPortLinkState
  EthSwtPortModeCnt                         the pointer to EthIf_EthSwtPortModeCnt
  EthTrcv                                   the pointer to EthIf_EthTrcv
  EthTrcvDrvApi                             the pointer to EthIf_EthTrcvDrvApi
  EthTrcvInitCnt                            the pointer to EthIf_EthTrcvInitCnt
  EthTrcvLinkState                          the pointer to EthIf_EthTrcvLinkState
  EthTrcvModeCnt                            the pointer to EthIf_EthTrcvModeCnt
  EthTrcvState                              the pointer to EthIf_EthTrcvState
  ExplicitBufReleaseFilter                  the pointer to EthIf_ExplicitBufReleaseFilter
  GatewaySrcMacBlackList                    the pointer to EthIf_GatewaySrcMacBlackList
  InitLocked                                the pointer to EthIf_InitLocked
  LinkStateChgIndications                   the pointer to EthIf_LinkStateChgIndications
  MainFuncStateDecoupleFreqCnt              the pointer to EthIf_MainFuncStateDecoupleFreqCnt
  MirrorDest                                the pointer to EthIf_MirrorDest
  MirrorTxInfo                              the pointer to EthIf_MirrorTxInfo
  ModeChangeLocked                          the pointer to EthIf_ModeChangeLocked
  PhysLayerInitElems                        the pointer to EthIf_PhysLayerInitElems
  PhysLayerModeElems                        the pointer to EthIf_PhysLayerModeElems
  PortGroup                                 the pointer to EthIf_PortGroup
  PortGroupHostOrUpLinkPortRoleLinkCount    the pointer to EthIf_PortGroupHostOrUpLinkPortRoleLinkCount
  PortGroupInd                              the pointer to EthIf_PortGroupInd
  PortGroupLaxLinkAggregationCount          the pointer to EthIf_PortGroupLaxLinkAggregationCount
  PortGroupLinkState                        the pointer to EthIf_PortGroupLinkState
  PortGroupMode                             the pointer to EthIf_PortGroupMode
  PortGroupNoRoleLinkCount                  the pointer to EthIf_PortGroupNoRoleLinkCount
  PortSignalQualityResult                   the pointer to EthIf_PortSignalQualityResult
  PortStartupActiveTimeCounter              the pointer to EthIf_PortStartupActiveTimeCounter
  PortStartupActiveTimerActive              the pointer to EthIf_PortStartupActiveTimerActive
  RxIndications                             the pointer to EthIf_RxIndications
  RxIndicationsInd                          the pointer to EthIf_RxIndicationsInd
  SignalQualityDecoupleFreqCnt              the pointer to EthIf_SignalQualityDecoupleFreqCnt
  SignalQualityResult                       the pointer to EthIf_SignalQualityResult
  SrcMacAddrBuffer                          the pointer to EthIf_SrcMacAddrBuffer
  TxConfirmations                           the pointer to EthIf_TxConfirmations
  TxConfirmationsInd                        the pointer to EthIf_TxConfirmationsInd
  TxContext                                 the pointer to EthIf_TxContext
  User                                      the pointer to EthIf_User
  WakeupMap                                 the pointer to EthIf_WakeupMap
  LinkStateChgMainReload                    Amount of calls link state observation isn't triggerd if observation is done within EthIf_MainFunctionTx() instead of using an explicit EthIf_MainFunctionState().
  MaxFrameRxPerEthCtrl                      Maximum amount of frames that can be received during one call of EthIf_MainFunctionRx() in polling mode on one Ethernet controller
  MaxTxBufPerEthCtrl                        Maximum amount of Tx buffers configured for an Ethernet controller
  PortStartupActiveTimeFreq                 Port startup activation timer in terms of main function periodicity
  SignalQualityChgMainReload                Amount of calls signal quality observation in EthIf_MainFunctionState().
  SizeOfEthCtrl                             the number of accomplishable value elements in EthIf_EthCtrl
  SizeOfEthCtrlRxFrameCnt                   the number of accomplishable value elements in EthIf_EthCtrlRxFrameCnt
  SizeOfEthDrvApi                           the number of accomplishable value elements in EthIf_EthDrvApi
  SizeOfEthIfClkUnit                        the number of accomplishable value elements in EthIf_EthIfClkUnit
  SizeOfEthIfCtrl                           the number of accomplishable value elements in EthIf_EthIfCtrl
  SizeOfEthIfCtrlOfEthTrcvInd               the number of accomplishable value elements in EthIf_EthIfCtrlOfEthTrcvInd
  SizeOfEthIfCtrlOfPortGroupInd             the number of accomplishable value elements in EthIf_EthIfCtrlOfPortGroupInd
  SizeOfEthIfMeasurementData                the number of accomplishable value elements in EthIf_EthIfMeasurementData
  SizeOfEthIfPhysCtrlCfg                    the number of accomplishable value elements in EthIf_EthIfPhysCtrlCfg
  SizeOfEthSwt                              the number of accomplishable value elements in EthIf_EthSwt
  SizeOfEthSwtDrv                           the number of accomplishable value elements in EthIf_EthSwtDrv
  SizeOfEthSwtDrvApi                        the number of accomplishable value elements in EthIf_EthSwtDrvApi
  SizeOfEthSwtInd                           the number of accomplishable value elements in EthIf_EthSwtInd
  SizeOfEthSwtPort                          the number of accomplishable value elements in EthIf_EthSwtPort
  SizeOfEthSwtPortInEthSwtContext           the number of accomplishable value elements in EthIf_EthSwtPortInEthSwtContext
  SizeOfEthSwtPortInd                       the number of accomplishable value elements in EthIf_EthSwtPortInd
  SizeOfEthTrcv                             the number of accomplishable value elements in EthIf_EthTrcv
  SizeOfEthTrcvDrvApi                       the number of accomplishable value elements in EthIf_EthTrcvDrvApi
  SizeOfExplicitBufReleaseFilter            the number of accomplishable value elements in EthIf_ExplicitBufReleaseFilter
  SizeOfGatewaySrcMacBlackList              the number of accomplishable value elements in EthIf_GatewaySrcMacBlackList
  SizeOfLinkStateChgIndications             the number of accomplishable value elements in EthIf_LinkStateChgIndications
  SizeOfMirrorDest                          the number of accomplishable value elements in EthIf_MirrorDest
  SizeOfMirrorTxInfo                        the number of accomplishable value elements in EthIf_MirrorTxInfo
  SizeOfPhysLayerInitElems                  the number of accomplishable value elements in EthIf_PhysLayerInitElems
  SizeOfPhysLayerModeElems                  the number of accomplishable value elements in EthIf_PhysLayerModeElems
  SizeOfPortGroup                           the number of accomplishable value elements in EthIf_PortGroup
  SizeOfPortGroupInd                        the number of accomplishable value elements in EthIf_PortGroupInd
  SizeOfRxIndications                       the number of accomplishable value elements in EthIf_RxIndications
  SizeOfRxIndicationsInd                    the number of accomplishable value elements in EthIf_RxIndicationsInd
  SizeOfTxConfirmations                     the number of accomplishable value elements in EthIf_TxConfirmations
  SizeOfTxConfirmationsInd                  the number of accomplishable value elements in EthIf_TxConfirmationsInd
  SizeOfTxContext                           the number of accomplishable value elements in EthIf_TxContext
  SizeOfUser                                the number of accomplishable value elements in EthIf_User
  SizeOfWakeupMap                           the number of accomplishable value elements in EthIf_WakeupMap
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthIf_PCConfigsType, ETHIF_CONST) EthIf_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config] */
      EthIf_EthCtrl                            /**< the pointer to EthIf_EthCtrl */
    , EthIf_EthCtrlInitCnt                     /**< the pointer to EthIf_EthCtrlInitCnt */
    , EthIf_EthCtrlModeCnt                     /**< the pointer to EthIf_EthCtrlModeCnt */
    , NULL_PTR                                 /**< the pointer to EthIf_EthCtrlRxFrameCnt */
    , EthIf_EthCtrlState                       /**< the pointer to EthIf_EthCtrlState */
    , EthIf_EthDrvApi                          /**< the pointer to EthIf_EthDrvApi */
    , NULL_PTR                                 /**< the pointer to EthIf_EthIfClkUnit */
    , EthIf_EthIfCtrl                          /**< the pointer to EthIf_EthIfCtrl */
    , EthIf_EthIfCtrlInitState                 /**< the pointer to EthIf_EthIfCtrlInitState */
    , EthIf_EthIfCtrlLinkCount                 /**< the pointer to EthIf_EthIfCtrlLinkCount */
    , EthIf_EthIfCtrlLinkState                 /**< the pointer to EthIf_EthIfCtrlLinkState */
    , EthIf_EthIfCtrlMode                      /**< the pointer to EthIf_EthIfCtrlMode */
    , EthIf_EthIfCtrlOfEthTrcvInd              /**< the pointer to EthIf_EthIfCtrlOfEthTrcvInd */
    , NULL_PTR                                 /**< the pointer to EthIf_EthIfCtrlOfPortGroupInd */
    , EthIf_EthIfCtrlRxStats                   /**< the pointer to EthIf_EthIfCtrlRxStats */
    , EthIf_EthIfCtrlTxStats                   /**< the pointer to EthIf_EthIfCtrlTxStats */
    , EthIf_EthIfMeasurementData               /**< the pointer to EthIf_EthIfMeasurementData */
    , EthIf_EthIfPhysCtrlCfg                   /**< the pointer to EthIf_EthIfPhysCtrlCfg */
    , EthIf_EthIfSwtPortGroupState             /**< the pointer to EthIf_EthIfSwtPortGroupState */
    , NULL_PTR                                 /**< the pointer to EthIf_EthSwt */
    , NULL_PTR                                 /**< the pointer to EthIf_EthSwtDrv */
    , NULL_PTR                                 /**< the pointer to EthIf_EthSwtDrvApi */
    , NULL_PTR                                 /**< the pointer to EthIf_EthSwtInd */
    , NULL_PTR                                 /**< the pointer to EthIf_EthSwtInitCnt */
    , NULL_PTR                                 /**< the pointer to EthIf_EthSwtPort */
    , NULL_PTR                                 /**< the pointer to EthIf_EthSwtPortInEthSwtContext */
    , NULL_PTR                                 /**< the pointer to EthIf_EthSwtPortInd */
    , NULL_PTR                                 /**< the pointer to EthIf_EthSwtPortLinkState */
    , NULL_PTR                                 /**< the pointer to EthIf_EthSwtPortModeCnt */
    , EthIf_EthTrcv                            /**< the pointer to EthIf_EthTrcv */
    , EthIf_EthTrcvDrvApi                      /**< the pointer to EthIf_EthTrcvDrvApi */
    , EthIf_EthTrcvInitCnt                     /**< the pointer to EthIf_EthTrcvInitCnt */
    , EthIf_EthTrcvLinkState                   /**< the pointer to EthIf_EthTrcvLinkState */
    , EthIf_EthTrcvModeCnt                     /**< the pointer to EthIf_EthTrcvModeCnt */
    , EthIf_EthTrcvState                       /**< the pointer to EthIf_EthTrcvState */
    , NULL_PTR                                 /**< the pointer to EthIf_ExplicitBufReleaseFilter */
    , NULL_PTR                                 /**< the pointer to EthIf_GatewaySrcMacBlackList */
    , (&(EthIf_InitLocked))                    /**< the pointer to EthIf_InitLocked */
    , EthIf_LinkStateChgIndications            /**< the pointer to EthIf_LinkStateChgIndications */
    , (&(EthIf_MainFuncStateDecoupleFreqCnt))  /**< the pointer to EthIf_MainFuncStateDecoupleFreqCnt */
    , NULL_PTR                                 /**< the pointer to EthIf_MirrorDest */
    , NULL_PTR                                 /**< the pointer to EthIf_MirrorTxInfo */
    , (&(EthIf_ModeChangeLocked))              /**< the pointer to EthIf_ModeChangeLocked */
    , EthIf_PhysLayerInitElems                 /**< the pointer to EthIf_PhysLayerInitElems */
    , EthIf_PhysLayerModeElems                 /**< the pointer to EthIf_PhysLayerModeElems */
    , NULL_PTR                                 /**< the pointer to EthIf_PortGroup */
    , NULL_PTR                                 /**< the pointer to EthIf_PortGroupHostOrUpLinkPortRoleLinkCount */
    , NULL_PTR                                 /**< the pointer to EthIf_PortGroupInd */
    , NULL_PTR                                 /**< the pointer to EthIf_PortGroupLaxLinkAggregationCount */
    , NULL_PTR                                 /**< the pointer to EthIf_PortGroupLinkState */
    , NULL_PTR                                 /**< the pointer to EthIf_PortGroupMode */
    , NULL_PTR                                 /**< the pointer to EthIf_PortGroupNoRoleLinkCount */
    , NULL_PTR                                 /**< the pointer to EthIf_PortSignalQualityResult */
    , (&(EthIf_PortStartupActiveTimeCounter))  /**< the pointer to EthIf_PortStartupActiveTimeCounter */
    , (&(EthIf_PortStartupActiveTimerActive))  /**< the pointer to EthIf_PortStartupActiveTimerActive */
    , EthIf_RxIndications                      /**< the pointer to EthIf_RxIndications */
    , EthIf_RxIndicationsInd                   /**< the pointer to EthIf_RxIndicationsInd */
    , (&(EthIf_SignalQualityDecoupleFreqCnt))  /**< the pointer to EthIf_SignalQualityDecoupleFreqCnt */
    , EthIf_SignalQualityResult                /**< the pointer to EthIf_SignalQualityResult */
    , EthIf_SrcMacAddrBuffer                   /**< the pointer to EthIf_SrcMacAddrBuffer */
    , EthIf_TxConfirmations                    /**< the pointer to EthIf_TxConfirmations */
    , EthIf_TxConfirmationsInd                 /**< the pointer to EthIf_TxConfirmationsInd */
    , EthIf_TxContext.raw                      /**< the pointer to EthIf_TxContext */
    , EthIf_User                               /**< the pointer to EthIf_User */
    , NULL_PTR                                 /**< the pointer to EthIf_WakeupMap */
    , 5u
    , 5u
    , 2u
    , 100u
    , 0u
    , 1u                                       /**< the number of elements in EthIf_EthCtrl */
    , 0u                                       /**< the number of elements in EthIf_EthCtrlRxFrameCnt */
    , 1u                                       /**< the number of elements in EthIf_EthDrvApi */
    , 0u                                       /**< the number of elements in EthIf_EthIfClkUnit */
    , 1u                                       /**< the number of elements in EthIf_EthIfCtrl */
    , 1u                                       /**< the number of elements in EthIf_EthIfCtrlOfEthTrcvInd */
    , 0u                                       /**< the number of elements in EthIf_EthIfCtrlOfPortGroupInd */
    , 1u                                       /**< the number of elements in EthIf_EthIfMeasurementData */
    , 1u                                       /**< the number of elements in EthIf_EthIfPhysCtrlCfg */
    , 0u                                       /**< the number of elements in EthIf_EthSwt */
    , 0u                                       /**< the number of elements in EthIf_EthSwtDrv */
    , 0u                                       /**< the number of elements in EthIf_EthSwtDrvApi */
    , 0u                                       /**< the number of elements in EthIf_EthSwtInd */
    , 0u                                       /**< the number of elements in EthIf_EthSwtPort */
    , 0u                                       /**< the number of elements in EthIf_EthSwtPortInEthSwtContext */
    , 0u                                       /**< the number of elements in EthIf_EthSwtPortInd */
    , 1u                                       /**< the number of elements in EthIf_EthTrcv */
    , 1u                                       /**< the number of elements in EthIf_EthTrcvDrvApi */
    , 0u                                       /**< the number of elements in EthIf_ExplicitBufReleaseFilter */
    , 0u                                       /**< the number of elements in EthIf_GatewaySrcMacBlackList */
    , 2u                                       /**< the number of elements in EthIf_LinkStateChgIndications */
    , 0u                                       /**< the number of elements in EthIf_MirrorDest */
    , 0u                                       /**< the number of elements in EthIf_MirrorTxInfo */
    , 1u                                       /**< the number of elements in EthIf_PhysLayerInitElems */
    , 1u                                       /**< the number of elements in EthIf_PhysLayerModeElems */
    , 0u                                       /**< the number of elements in EthIf_PortGroup */
    , 0u                                       /**< the number of elements in EthIf_PortGroupInd */
    , 2u                                       /**< the number of elements in EthIf_RxIndications */
    , 2u                                       /**< the number of elements in EthIf_RxIndicationsInd */
    , 1u                                       /**< the number of elements in EthIf_TxConfirmations */
    , 1u                                       /**< the number of elements in EthIf_TxConfirmationsInd */
    , 2u                                       /**< the number of elements in EthIf_TxContext */
    , 2u                                       /**< the number of elements in EthIf_User */
    , 0u                                       /**< the number of elements in EthIf_WakeupMap */
  }
};
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA (NOT COMSTACKLIB GENERATED)
**********************************************************************************************************************/
/**********************************************************************************************************************
  EthIf_ConfigDataPtr
**********************************************************************************************************************/
/**
  \var    EthIf_ConfigDataPtr
  \brief  Points to the currently active configuration for EthIf
*/
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
P2CONST(EthIf_ConfigType, ETHIF_VAR_NO_INIT, ETHIF_INIT_DATA) EthIf_ConfigDataPtr;
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: EthIf_Lcfg.c
 *********************************************************************************************************************/


