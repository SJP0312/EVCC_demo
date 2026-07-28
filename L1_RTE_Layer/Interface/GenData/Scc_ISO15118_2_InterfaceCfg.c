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
 *              File: Scc_ISO15118_2_InterfaceCfg.c
 *   Generation Time: 2025-08-28 10:22:05
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#define SCC_ISO15118_2_INTERFACECFG_SOURCE 

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Scc_ISO15118_2_InterfaceCfg.h"
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
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_ChargeProgress 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_ChargeProgress(
  P2VAR(Exi_ISO_chargeProgressType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonRxParam" && name=="ChargeProgress" */
  /* Call the state machine related callback function */
  Scc_ISO15118_2_StateM_Get_ChargeProgress(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_ChargingProfilePtr 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_ChargingProfilePtr(
  P2VAR(Exi_ISO_ChargingProfileType*, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonRxParam" && name=="ChargingProfilePtr" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_ChargingProfilePtr(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_ChargingSession 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_ChargingSession(
  P2VAR(Scc_ISO_ChargingSessionType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonRxParam" && name=="ChargingSession" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_ChargingSession(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_DepartureTime 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_DepartureTime(
  P2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonRxParam" && name=="DepartureTime" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_DepartureTime(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_MaxEntriesSAScheduleTuple 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_MaxEntriesSAScheduleTuple(
  P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonRxParam" && name=="MaxEntriesSAScheduleTuple" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_MaxEntriesSAScheduleTuple(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_RequestedEnergyTransferMode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_RequestedEnergyTransferMode(
  P2VAR(Exi_ISO_EnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonRxParam" && name=="RequestedEnergyTransferMode" */
  /* Call the state machine related callback function */
  Scc_ISO15118_2_StateM_Get_RequestedEnergyTransferMode(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_SAScheduleTupleID 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_SAScheduleTupleID(
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonRxParam" && name=="SAScheduleTupleID" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_SAScheduleTupleID(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Get_SkipSAScheduleListCheck 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Get_SkipSAScheduleListCheck(
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonRxParam" && name=="SkipSAScheduleListCheck" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_SkipSAScheduleListCheck(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Get_SkipSalesTariffSignatureCheck 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Get_SkipSalesTariffSignatureCheck(
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonRxParam" && name=="SkipSalesTariffSignatureCheck" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_PnC_SkipSalesTariffSignatureCheck(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_SelectedPaymentOption 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_SelectedPaymentOption(
  P2VAR(Exi_ISO_paymentOptionType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonRxParam" && name=="SelectedPaymentOption" */
  /* Call the state machine related callback function */
  Scc_ISO15118_2_StateM_Get_SelectedPaymentOption(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_SelectedServiceListPtr 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_SelectedServiceListPtr(
  P2VAR(Exi_ISO_SelectedServiceListType*, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonRxParam" && name=="SelectedServiceListPtr" */
  /* Call the state machine related callback function */
  Scc_ISO15118_2_StateM_Get_SelectedServiceListPtr(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_ServiceCategory 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_ServiceCategory(
  P2VAR(Exi_ISO_serviceCategoryType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonRxParam" && name=="ServiceCategory" */
  /* Call the state machine related callback function */
  Scc_ISO15118_2_StateM_Get_ServiceCategory(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_ServiceIDRx 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_ServiceIDRx(
  P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonRxParam" && name=="ServiceIDRx" */
  /* Call the state machine related callback function */
  Scc_ISO15118_2_StateM_Get_ServiceIDRx(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_ServiceScope 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_ServiceScope(
  P2VAR(Exi_ISO_serviceScopeType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonRxParam" && name=="ServiceScope" */
  /* Call the state machine related callback function */
  Scc_ISO15118_2_StateM_Get_ServiceScope(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Get_InstallContract 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Get_InstallContract(
  P2VAR(Scc_ApplCheckContrChainStateEnumType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonRxParam" && name=="InstallContract" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_PnC_InstallContract(DataPtr);
}



/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_BulkChargingComplete 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_BulkChargingComplete(
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcRxParam" && name=="BulkChargingComplete" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_BulkChargingComplete(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_BulkSOC 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_BulkSOC(
  P2VAR(sint8, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcRxParam" && name=="BulkSOC" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_BulkSOC(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_ChargingComplete 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_ChargingComplete(
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcRxParam" && name=="ChargingComplete" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_ChargingComplete(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVEnergyCapacity 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVEnergyCapacity(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcRxParam" && name=="EVEnergyCapacity" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_EVEnergyCapacity(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVEnergyRequest 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVEnergyRequest(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcRxParam" && name=="EVEnergyRequest" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_EVEnergyRequest(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVErrorCode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVErrorCode(
  P2VAR(Exi_ISO_DC_EVErrorCodeType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcRxParam" && name=="EVErrorCode" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_DC_EVErrorCode(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVMaximumCurrentLimit 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVMaximumCurrentLimit(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcRxParam" && name=="EVMaximumCurrentLimit" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_EVMaximumCurrentLimit(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVMaximumPowerLimit 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVMaximumPowerLimit(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcRxParam" && name=="EVMaximumPowerLimit" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_EVMaximumPowerLimit(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVMaximumVoltageLimit 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVMaximumVoltageLimit(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcRxParam" && name=="EVMaximumVoltageLimit" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_EVMaximumVoltageLimit(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVPowerDeliveryParameterFlag 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Use the configured default value
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVPowerDeliveryParameterFlag(
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcRxParam" && name=="EVPowerDeliveryParameterFlag" */
  /* Use the configured default value */
  *DataPtr = TRUE;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVReady 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVReady(
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcRxParam" && name=="EVReady" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_EVReady(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVRESSSOC 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVRESSSOC(
  P2VAR(sint8, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcRxParam" && name=="EVRESSSOC" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_EVRESSSOC(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVTargetCurrent 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVTargetCurrent(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcRxParam" && name=="EVTargetCurrent" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_EVTargetCurrent(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVTargetVoltage 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVTargetVoltage(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcRxParam" && name=="EVTargetVoltage" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_EVTargetVoltage(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_FullSOC 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_FullSOC(
  P2VAR(sint8, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcRxParam" && name=="FullSOC" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_FullSOC(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_RemainingTimeToBulkSoC 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_RemainingTimeToBulkSoC(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcRxParam" && name=="RemainingTimeToBulkSoC" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_RemainingTimeToBulkSoC(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_RemainingTimeToFullSoC 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_RemainingTimeToFullSoC(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcRxParam" && name=="RemainingTimeToFullSoC" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_IsoDin_DC_RemainingTimeToFullSoC(DataPtr, Flag);
}



/**********************************************************************************************************************
 * TX INTERFACE
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ChargeService 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ChargeService(
  P2CONST(Exi_ISO_ChargeServiceType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonTxParam" && name=="ChargeService" */
  /* Call the related state machine callback */
  Scc_ISO15118_2_StateM_Set_ChargeService(DataPtr);
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_ChargeService(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_EVSEID 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_EVSEID(
  P2CONST(Exi_ISO_evseIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonTxParam" && name=="EVSEID" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_EVSEID(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_EVSENotification 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_EVSENotification(
  Exi_ISO_EVSENotificationType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonTxParam" && name=="EVSENotification" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_EVSENotification(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_EVSEProcessing 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_EVSEProcessing(
  Exi_ISO_EVSEProcessingType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonTxParam" && name=="EVSEProcessing" */
  /* Call the related state machine callback */
  Scc_ISO15118_2_StateM_Set_EVSEProcessing(Data);
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_EVSEProcessing(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_EVSETimeStamp 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_EVSETimeStamp(
  Exi_SInt64 Data,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonTxParam" && name=="EVSETimeStamp" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_EVSETimeStamp(Data, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_MeterInfo 
 *********************************************************************************************************************/
/*!
 * \internal
 * - No callback configured
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_MeterInfo(
  P2CONST(Exi_ISO_MeterInfoType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonTxParam" && name=="MeterInfo" */
  /* No callback configured */
  SCC_DUMMY_STATEMENT_CONST(DataPtr); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  SCC_DUMMY_STATEMENT_CONST(Flag); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_Notification 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_Notification(
  P2CONST(Exi_ISO_NotificationType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonTxParam" && name=="Notification" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_Notification(DataPtr, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_NotificationMaxDelay 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_NotificationMaxDelay(
  uint16 Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonTxParam" && name=="NotificationMaxDelay" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_NotificationMaxDelay(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_PaymentOptionList 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_PaymentOptionList(
  P2CONST(Exi_ISO_PaymentOptionListType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonTxParam" && name=="PaymentOptionList" */
  /* Call the related state machine callback */
  Scc_ISO15118_2_StateM_Set_PaymentOptionList(DataPtr);
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_PaymentOptionList(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(
  Exi_ISO_responseCodeType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonTxParam" && name=="ResponseCode" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_ResponseCode(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_SAScheduleList 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_SAScheduleList(
  P2CONST(Exi_ISO_SAScheduleListType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonTxParam" && name=="SAScheduleList" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_SAScheduleList(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ServiceIDTx 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ServiceIDTx(
  uint16 Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonTxParam" && name=="ServiceIDTx" */
  /* Call the related state machine callback */
  Scc_ISO15118_2_StateM_Set_ServiceIDTx(Data);
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_ServiceIDTx(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ServiceList 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ServiceList(
  P2CONST(Exi_ISO_ServiceListType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonTxParam" && name=="ServiceList" */
  /* Call the related state machine callback */
  Scc_ISO15118_2_StateM_Set_ServiceList(DataPtr, Flag);
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_ServiceList(DataPtr, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ServiceParameterList 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ServiceParameterList(
  P2CONST(Exi_ISO_ServiceParameterListType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonTxParam" && name=="ServiceParameterList" */
  /* Call the related state machine callback */
  Scc_ISO15118_2_StateM_Set_ServiceParameterList(DataPtr, Flag);
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_ServiceParameterList(DataPtr, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ReceiptRequired 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ReceiptRequired(
  boolean Data,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonTxParam" && name=="ReceiptRequired" */
  /* Call the related state machine callback */
  Scc_ISO15118_2_StateM_Set_ReceiptRequired(Data, Flag);
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_PnC_ReceiptRequired(Data, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_RetryCounter 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_RetryCounter(
  sint16 Data,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonTxParam" && name=="RetryCounter" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_PnC_RetryCounter(Data, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_SessionID 
 *********************************************************************************************************************/
/*!
 * \internal
 * - No callback configured
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_SessionID(
  P2CONST(Exi_ISO_sessionIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonTxParam" && name=="SessionID" */
  /* No callback configured */
  SCC_DUMMY_STATEMENT_CONST(DataPtr); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ContractToInstall 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ContractToInstall(
  P2CONST(Scc_PropagateContrCertsStructType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoCommon/SccIsoCommonTxParam" && name=="ContractToInstall" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_PnC_ContractToInstall(DataPtr); /*lint !e522 */ /* Application specific implementation */
}



/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSECurrentLimitAchieved 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSECurrentLimitAchieved(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcTxParam" && name=="EVSECurrentLimitAchieved" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSECurrentLimitAchieved(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSECurrentRegulationTolerance 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSECurrentRegulationTolerance(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcTxParam" && name=="EVSECurrentRegulationTolerance" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSECurrentRegulationTolerance(DataPtr, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEEnergyToBeDelivered 
 *********************************************************************************************************************/
/*!
 * \internal
 * - No callback configured
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEEnergyToBeDelivered(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcTxParam" && name=="EVSEEnergyToBeDelivered" */
  /* No callback configured */
  SCC_DUMMY_STATEMENT_CONST(DataPtr); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  SCC_DUMMY_STATEMENT_CONST(Flag); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEIsolationStatus 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEIsolationStatus(
  Exi_ISO_isolationLevelType Data,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcTxParam" && name=="EVSEIsolationStatus" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_DC_EVSEIsolationStatus(Data, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEMaximumCurrentLimit 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEMaximumCurrentLimit(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcTxParam" && name=="EVSEMaximumCurrentLimit" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSEMaximumCurrentLimit(DataPtr, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEMaximumPowerLimit 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEMaximumPowerLimit(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcTxParam" && name=="EVSEMaximumPowerLimit" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSEMaximumPowerLimit(DataPtr, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEMaximumVoltageLimit 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEMaximumVoltageLimit(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcTxParam" && name=="EVSEMaximumVoltageLimit" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSEMaximumVoltageLimit(DataPtr, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEMinimumCurrentLimit 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEMinimumCurrentLimit(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcTxParam" && name=="EVSEMinimumCurrentLimit" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSEMinimumCurrentLimit(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEMinimumVoltageLimit 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEMinimumVoltageLimit(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcTxParam" && name=="EVSEMinimumVoltageLimit" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSEMinimumVoltageLimit(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEPeakCurrentRipple 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEPeakCurrentRipple(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcTxParam" && name=="EVSEPeakCurrentRipple" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSEPeakCurrentRipple(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEPowerLimitAchieved 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEPowerLimitAchieved(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcTxParam" && name=="EVSEPowerLimitAchieved" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSEPowerLimitAchieved(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEPresentCurrent 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEPresentCurrent(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcTxParam" && name=="EVSEPresentCurrent" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSEPresentCurrent(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEPresentVoltage 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEPresentVoltage(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcTxParam" && name=="EVSEPresentVoltage" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSEPresentVoltage(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEStatusCode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEStatusCode(
  Exi_ISO_DC_EVSEStatusCodeType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcTxParam" && name=="EVSEStatusCode" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_DC_EVSEStatusCode(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEVoltageLimitAchieved 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEVoltageLimitAchieved(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso/SccIsoDc/SccIsoDcTxParam" && name=="EVSEVoltageLimitAchieved" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_IsoDin_DC_EVSEVoltageLimitAchieved(Data); /*lint !e522 */ /* Application specific implementation */
}



#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_2_InterfaceCfg.c
 *********************************************************************************************************************/

