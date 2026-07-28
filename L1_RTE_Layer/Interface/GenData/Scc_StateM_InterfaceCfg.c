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
 *              File: Scc_StateM_InterfaceCfg.c
 *   Generation Time: 2025-08-28 10:22:05
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#define SCC_STATEM_INTERFACECFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Scc_StateM_InterfaceCfg.h"
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
 *  Scc_StateM_InterfaceCfg_Get_ChargingControl 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_ChargingControl(
  P2VAR(Scc_StateM_ChargingControlType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMRxParam" && name=="ChargingControl" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_StateM_ChargingControl(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_ControlPilotState 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_ControlPilotState(
  P2VAR(Scc_StateM_ControlPilotStateType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMRxParam" && name=="ControlPilotState" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_StateM_ControlPilotState(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_EnergyTransferMode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_EnergyTransferMode(
  P2VAR(Scc_StateM_EnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMRxParam" && name=="EnergyTransferMode" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_StateM_EnergyTransferMode(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_EVTimeStamp 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_EVTimeStamp(
  P2VAR(Scc_TimestampType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMRxParam" && name=="EVTimeStamp" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_StateM_EVTimeStamp(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_FunctionControl 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_FunctionControl(
  P2VAR(Scc_StateM_FunctionControlType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMRxParam" && name=="FunctionControl" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_StateM_FunctionControl(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_PWMState 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_PWMState(
  P2VAR(Scc_StateM_PWMStateType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMRxParam" && name=="PWMState" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_StateM_PWMState(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_PLCActive 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_PLCActive(
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMRxParam" && name=="PLCActive" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_StateM_PLCActive(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_SupportedServiceIDs 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_SupportedServiceIDs(
  P2VAR(Exi_ISO_20_CM_10_ServiceIDListType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMRxParam" && name=="SupportedServiceIDs" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20StateM_SupportedServiceIDs(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_ServiceDetailEnergyService 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_ServiceDetailEnergyService(
  P2VAR(Scc_ISO15118_20_ServiceIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMRxParam" && name=="ServiceDetailEnergyService" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20StateM_ServiceDetailEnergyService(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_ServiceDetailVAService 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_ServiceDetailVAService(
  P2VAR(Scc_ISO15118_20_ServiceIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMRxParam" && name=="ServiceDetailVAService" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20StateM_ServiceDetailVAService(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_SelectedServiceId 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_SelectedServiceId(
  P2VAR(Scc_ISO15118_20_ServiceIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMRxParam" && name=="SelectedServiceId" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20StateM_SelectedServiceId(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_SelectedParameterSetId 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_SelectedParameterSetId(
  P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMRxParam" && name=="SelectedParameterSetId" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20StateM_SelectedParameterSetId(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_ControlMode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_ControlMode(
  P2VAR(Scc_ISO15118_20_ControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMRxParam" && name=="ControlMode" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20StateM_ControlMode(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_ChargingSession 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_ChargingSession(
  P2VAR(Exi_ISO_20_CM_10_chargingSessionType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMRxParam" && name=="ChargingSession" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20StateM_ChargingSession(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_StartMetering 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_StartMetering(
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMRxParam" && name=="StartMetering" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20StateM_StartMetering(DataPtr);
}


/**********************************************************************************************************************
 * TX INTERFACE
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_EnergyTransferModeFlags 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_EnergyTransferModeFlags(
  uint8 Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMTxParam" && name=="EnergyTransferModeFlags" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_StateM_EnergyTransferModeFlags(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_InternetAvailable 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_InternetAvailable(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMTxParam" && name=="InternetAvailable" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_StateM_InternetAvailable(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_StateMachineError 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_StateMachineError(
  Scc_StateM_StateMachineErrorType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMTxParam" && name=="StateMachineError" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_StateM_StateMachineError(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_StateMachineMessageState 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_StateMachineMessageState(
  Scc_StateM_MsgStateType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMTxParam" && name=="StateMachineMessageState" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_StateM_StateMachineMessageState(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_StateMachineStatus 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_StateMachineStatus(
  Scc_StateM_StateMachineStatusType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMTxParam" && name=="StateMachineStatus" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_StateM_StateMachineStatus(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_VASReqServiceDetails 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_VASReqServiceDetails(
  uint16 ServiceId,
  boolean IsFreeService,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) RequestDetails,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) ApplicationPending)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMTxParam" && name=="VASReqServiceDetails" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_2StateM_VASReqServiceDetails(ServiceId, IsFreeService, RequestDetails, ApplicationPending); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_ServiceRenegotiationSupported 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_ServiceRenegotiationSupported(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMTxParam" && name=="ServiceRenegotiationSupported" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20StateM_ServiceRenegotiationSupported(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_EnergyTransferServiceList 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_EnergyTransferServiceList(
  P2CONST(Exi_ISO_20_CM_10_ServiceListType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMTxParam" && name=="EnergyTransferServiceList" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20StateM_EnergyTransferServiceList(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_VASList 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_VASList(
  P2CONST(Exi_ISO_20_CM_10_ServiceListType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMTxParam" && name=="VASList" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20StateM_VASList(DataPtr, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_VASServiceDetails 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_VASServiceDetails(
  uint16 ServiceId,
  P2CONST(Exi_ISO_ServiceParameterListType, AUTOMATIC, SCC_APPL_DATA) ParameterSet)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMTxParam" && name=="VASServiceDetails" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_2StateM_VASServiceDetails(ServiceId, ParameterSet); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_ServiceIDTx 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_ServiceIDTx(
  Scc_ISO15118_20_ServiceIDType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMTxParam" && name=="ServiceIDTx" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20StateM_ServiceIDTx(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_SelectedServicesList 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_SelectedServicesList(
  P2VAR(Exi_ISO_SelectedServiceType, AUTOMATIC, SCC_APPL_DATA) ServiceListPtr,
  uint8 ServiceListMaxLen,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) ServiceListLen,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) ApplicationPending)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMTxParam" && name=="SelectedServicesList" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_2StateM_SelectedServicesList(ServiceListPtr, ServiceListMaxLen, ServiceListLen, ApplicationPending); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_CurrentChannel 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_CurrentChannel(
  Scc_CoreChannelType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMTxParam" && name=="CurrentChannel" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_StateM_CurrentChannel(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_FinishProcessingCurrentChannel 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_FinishProcessingCurrentChannel(
  Scc_CoreChannelType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMTxParam" && name=="FinishProcessingCurrentChannel" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_StateM_FinishProcessingCurrentChannel(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_ContractStatus 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_ContractStatus(
  Scc_TimestampType NotAfter,
  Scc_TimestampType DateTimeNow,
  Scc_CertificateStatusType Status)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccStateM/SccStateMTxParam" && name=="ContractStatus" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_StateM_ContractStatus(NotAfter, DateTimeNow, Status); /*lint !e522 */ /* Application specific implementation */
}



#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Scc_StateM_InterfaceCfg.c
 *********************************************************************************************************************/

