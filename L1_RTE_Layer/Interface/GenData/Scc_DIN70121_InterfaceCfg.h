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
 *            Module: Scc
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Scc_DIN70121_InterfaceCfg.h
 *   Generation Time: 2025-08-26 17:17:04
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#if !defined(SCC_DIN70121_INTERFACECFG_H)
#define SCC_DIN70121_INTERFACECFG_H

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Scc_Types.h"
#include "Scc_DIN70121_StateM.h"


#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * RX INTERFACE - information to be sent is going to be fetched from upper layers
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_BulkChargingComplete 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \param[in,out]  Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_BulkChargingComplete(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_BulkSOC 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \param[in,out]  Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_BulkSOC(P2VAR(sint8, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_ChargingComplete 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_ChargingComplete(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_ChargingProfilePtr 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \param[in,out]  Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_ChargingProfilePtr(P2VAR(Exi_DIN_ChargingProfileType*, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVCabinConditioning 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \param[in,out]  Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVCabinConditioning(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVEnergyCapacity 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \param[in,out]  Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVEnergyCapacity(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVEnergyRequest 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \param[in,out]  Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVEnergyRequest(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVErrorCode 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVErrorCode(P2VAR(Exi_DIN_DC_EVErrorCodeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVMaximumCurrentLimit 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \param[in,out]  Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVMaximumCurrentLimit(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVMaximumPowerLimit 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \param[in,out]  Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVMaximumPowerLimit(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVMaximumVoltageLimit 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \param[in,out]  Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVMaximumVoltageLimit(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVPowerDeliveryParameterFlag 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVPowerDeliveryParameterFlag(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVReady 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVReady(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVRESSConditioning 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \param[in,out]  Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVRESSConditioning(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVRESSSOC 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVRESSSOC(P2VAR(sint8, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVTargetCurrent 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVTargetCurrent(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVTargetVoltage 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVTargetVoltage(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_FullSOC 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \param[in,out]  Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_FullSOC(P2VAR(sint8, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_ReadyToChargeState 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_ReadyToChargeState(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_RemainingTimeToBulkSoC 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \param[in,out]  Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_RemainingTimeToBulkSoC(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_RemainingTimeToFullSoC 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \param[in,out]  Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_RemainingTimeToFullSoC(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_RequestedEnergyTransferMode 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_RequestedEnergyTransferMode(P2VAR(Exi_DIN_EVRequestedEnergyTransferType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_ServiceCategory 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \param[in,out]  Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_ServiceCategory(P2VAR(Exi_DIN_serviceCategoryType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);


/**********************************************************************************************************************
 * TX INTERFACE - received information is going to be propagated to upper layers
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_ChargeService 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_ChargeService(P2CONST(Exi_DIN_ServiceChargeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_DateTimeNow 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \param[in]      Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_DateTimeNow(Exi_SInt64 Data, Exi_BitType Flag);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSECurrentLimitAchieved 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSECurrentLimitAchieved(boolean Data);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSECurrentRegulationTolerance 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \param[in]      Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSECurrentRegulationTolerance(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEEnergyToBeDelivered 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \param[in]      Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEEnergyToBeDelivered(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEID 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEID(P2CONST(Exi_DIN_evseIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEIsolationStatus 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \param[in]      Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEIsolationStatus(Exi_DIN_isolationLevelType Data, Exi_BitType Flag);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMaximumCurrentLimit 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \param[in]      Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMaximumCurrentLimit(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMaximumPowerLimit 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \param[in]      Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMaximumPowerLimit(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMaximumVoltageLimit 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \param[in]      Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMaximumVoltageLimit(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMinimumCurrentLimit 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMinimumCurrentLimit(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMinimumVoltageLimit 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMinimumVoltageLimit(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSENotification 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSENotification(Exi_DIN_EVSENotificationType Data);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPeakCurrentRipple 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPeakCurrentRipple(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPowerLimitAchieved 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPowerLimitAchieved(boolean Data);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPresentCurrent 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPresentCurrent(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPresentVoltage 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPresentVoltage(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEProcessing 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEProcessing(Exi_DIN_EVSEProcessingType Data);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEStatusCode 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEStatusCode(Exi_DIN_DC_EVSEStatusCodeType Data);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEVoltageLimitAchieved 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEVoltageLimitAchieved(boolean Data);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_NotificationMaxDelay 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_NotificationMaxDelay(uint32 Data);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(Exi_DIN_responseCodeType Data);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_SAScheduleList 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_SAScheduleList(P2CONST(Exi_DIN_SAScheduleListType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_SessionID 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_SessionID(P2CONST(Exi_DIN_sessionIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr);



#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* SCC_DIN70121_INTERFACECFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Scc_DIN70121_InterfaceCfg.h
 *********************************************************************************************************************/

