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
 *              File: Scc_DIN70121_InterfaceCfg.c
 *   Generation Time: 2025-08-26 17:17:04
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#define SCC_DIN70121_INTERFACECFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Scc_DIN70121_InterfaceCfg.h"
/* The following includes are based on configuration parameter /MICROSAR/Scc/SccParameterMapping/SccCbkIncludeHeader */
#include "_ApplScc_CbkStubs.h"

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/
/* PRQA S 3673 EOF */ /* MD_Scc_VariantDependent */
 
 
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * RX INTERFACE
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_BulkChargingComplete 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_BulkChargingComplete(
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="BulkChargingComplete" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_BulkChargingComplete(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_BulkSOC 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_BulkSOC(
  P2VAR(sint8, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="BulkSOC" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_BulkSOC(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_ChargingComplete 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_ChargingComplete(
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="ChargingComplete" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_ChargingComplete(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_ChargingProfilePtr 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_ChargingProfilePtr(
  P2VAR(Exi_DIN_ChargingProfileType*, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="ChargingProfilePtr" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_DIN_ChargingProfilePtr(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVCabinConditioning 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVCabinConditioning(
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="EVCabinConditioning" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_DIN_EVCabinConditioning(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVEnergyCapacity 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVEnergyCapacity(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="EVEnergyCapacity" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_EVEnergyCapacity(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVEnergyRequest 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVEnergyRequest(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="EVEnergyRequest" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_EVEnergyRequest(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVErrorCode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVErrorCode(
  P2VAR(Exi_DIN_DC_EVErrorCodeType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="EVErrorCode" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_DIN_EVErrorCode(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVMaximumCurrentLimit 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVMaximumCurrentLimit(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="EVMaximumCurrentLimit" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_EVMaximumCurrentLimit(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVMaximumPowerLimit 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVMaximumPowerLimit(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="EVMaximumPowerLimit" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_EVMaximumPowerLimit(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVMaximumVoltageLimit 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVMaximumVoltageLimit(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="EVMaximumVoltageLimit" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_EVMaximumVoltageLimit(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVPowerDeliveryParameterFlag 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Use the configured default value
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVPowerDeliveryParameterFlag(
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="EVPowerDeliveryParameterFlag" */
  /* Use the configured default value */
  *DataPtr = TRUE;
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVReady 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVReady(
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="EVReady" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_EVReady(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVRESSConditioning 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVRESSConditioning(
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="EVRESSConditioning" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_DIN_EVRESSConditioning(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVRESSSOC 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVRESSSOC(
  P2VAR(sint8, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="EVRESSSOC" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_EVRESSSOC(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVTargetCurrent 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVTargetCurrent(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="EVTargetCurrent" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_EVTargetCurrent(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVTargetVoltage 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_EVTargetVoltage(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="EVTargetVoltage" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_EVTargetVoltage(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_FullSOC 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_FullSOC(
  P2VAR(sint8, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="FullSOC" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_FullSOC(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_ReadyToChargeState 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_ReadyToChargeState(
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="ReadyToChargeState" */
  /* Call the state machine related callback function */
  Scc_DIN70121_StateM_Get_ReadyToChargeState(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_RemainingTimeToBulkSoC 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_RemainingTimeToBulkSoC(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="RemainingTimeToBulkSoC" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_RemainingTimeToBulkSoC(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_RemainingTimeToFullSoC 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_RemainingTimeToFullSoC(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="RemainingTimeToFullSoC" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_RemainingTimeToFullSoC(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_RequestedEnergyTransferMode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_RequestedEnergyTransferMode(
  P2VAR(Exi_DIN_EVRequestedEnergyTransferType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="RequestedEnergyTransferMode" */
  /* Call the state machine related callback function */
  Scc_DIN70121_StateM_Get_RequestedEnergyTransferMode(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiTx_Get_ServiceCategory 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiTx_Get_ServiceCategory(
  P2VAR(Exi_DIN_serviceCategoryType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinRxParam" && name=="ServiceCategory" */
  /* Call the state machine related callback function */
  Scc_DIN70121_StateM_Get_ServiceCategory(DataPtr, Flag);
}


/**********************************************************************************************************************
 * TX INTERFACE
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_ChargeService 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_ChargeService(
  P2CONST(Exi_DIN_ServiceChargeType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="ChargeService" */
  /* Call the related state machine callback */
  Scc_DIN70121_StateM_Set_ChargeService(DataPtr);
  /* Call the configured application callback */
  Appl_SccCbk_Set_DIN_ChargeService(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_DateTimeNow 
 *********************************************************************************************************************/
/*!
 * \internal
 * - No callback configured
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_DateTimeNow(
  Exi_SInt64 Data,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="DateTimeNow" */
  /* No callback configured */
  SCC_DUMMY_STATEMENT_CONST(Data); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  SCC_DUMMY_STATEMENT_CONST(Flag); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSECurrentLimitAchieved 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSECurrentLimitAchieved(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="EVSECurrentLimitAchieved" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSECurrentLimitAchieved(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSECurrentRegulationTolerance 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSECurrentRegulationTolerance(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="EVSECurrentRegulationTolerance" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSECurrentRegulationTolerance(DataPtr, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEEnergyToBeDelivered 
 *********************************************************************************************************************/
/*!
 * \internal
 * - No callback configured
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEEnergyToBeDelivered(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="EVSEEnergyToBeDelivered" */
  /* No callback configured */
  SCC_DUMMY_STATEMENT_CONST(DataPtr); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  SCC_DUMMY_STATEMENT_CONST(Flag); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEID 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEID(
  P2CONST(Exi_DIN_evseIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="EVSEID" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_DIN_EVSEID(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEIsolationStatus 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEIsolationStatus(
  Exi_DIN_isolationLevelType Data,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="EVSEIsolationStatus" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_DIN_EVSEIsolationStatus(Data, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMaximumCurrentLimit 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMaximumCurrentLimit(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="EVSEMaximumCurrentLimit" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSEMaximumCurrentLimit(DataPtr, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMaximumPowerLimit 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMaximumPowerLimit(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="EVSEMaximumPowerLimit" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSEMaximumPowerLimit(DataPtr, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMaximumVoltageLimit 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMaximumVoltageLimit(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="EVSEMaximumVoltageLimit" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSEMaximumVoltageLimit(DataPtr, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMinimumCurrentLimit 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMinimumCurrentLimit(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="EVSEMinimumCurrentLimit" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSEMinimumCurrentLimit(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMinimumVoltageLimit 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEMinimumVoltageLimit(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="EVSEMinimumVoltageLimit" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSEMinimumVoltageLimit(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSENotification 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSENotification(
  Exi_DIN_EVSENotificationType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="EVSENotification" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_DIN_EVSENotification(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPeakCurrentRipple 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPeakCurrentRipple(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="EVSEPeakCurrentRipple" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSEPeakCurrentRipple(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPowerLimitAchieved 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPowerLimitAchieved(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="EVSEPowerLimitAchieved" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSEPowerLimitAchieved(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPresentCurrent 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPresentCurrent(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="EVSEPresentCurrent" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSEPresentCurrent(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPresentVoltage 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEPresentVoltage(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="EVSEPresentVoltage" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSEPresentVoltage(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEProcessing 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEProcessing(
  Exi_DIN_EVSEProcessingType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="EVSEProcessing" */
  /* Call the related state machine callback */
  Scc_DIN70121_StateM_Set_EVSEProcessing(Data);
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEStatusCode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEStatusCode(
  Exi_DIN_DC_EVSEStatusCodeType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="EVSEStatusCode" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_DIN_EVSEStatusCode(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEVoltageLimitAchieved 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_EVSEVoltageLimitAchieved(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="EVSEVoltageLimitAchieved" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSEVoltageLimitAchieved(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_NotificationMaxDelay 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_NotificationMaxDelay(
  uint32 Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="NotificationMaxDelay" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_DIN_NotificationMaxDelay(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_ResponseCode(
  Exi_DIN_responseCodeType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="ResponseCode" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_DIN_ResponseCode(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_SAScheduleList 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_SAScheduleList(
  P2CONST(Exi_DIN_SAScheduleListType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="SAScheduleList" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_DIN_SAScheduleList(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_DIN70121_InterfaceCfg_ExiRx_Set_SessionID 
 *********************************************************************************************************************/
/*!
 * \internal
 * - No callback configured
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_DIN70121_InterfaceCfg_ExiRx_Set_SessionID(
  P2CONST(Exi_DIN_sessionIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccDin/SccDinTxParam" && name=="SessionID" */
  /* No callback configured */
  SCC_DUMMY_STATEMENT_CONST(DataPtr); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
}


#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Scc_DIN70121_InterfaceCfg.c
 *********************************************************************************************************************/

