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
 *              File: Scc_ISO15118_20_InterfaceCfg.c
 *   Generation Time: 2025-08-28 10:22:05
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#define SCC_ISO15118_20_INTERFACECFG_SOURCE 

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Scc_ISO15118_20_InterfaceCfg.h"
/* The following includes are based on configuration parameter /MICROSAR/Scc/SccParameterMapping/SccCbkIncludeHeader */
#include "_ApplScc_CbkStubs.h"

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/
/* PRQA S 3673 EOF */ /* MD_Scc_VariantDependent */


#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Section: Common Message
 * Description: Configuration for parameters defined in the Common Messages schema
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * RX INTERFACE
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_InterfaceCfg_ExiTx_Get_TimeStamp 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_InterfaceCfg_ExiTx_Get_TimeStamp(
  P2VAR(Exi_UInt64, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="TimeStamp" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20_TimeStamp(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_InterfaceCfg_ExiTx_Get_ControlMode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_InterfaceCfg_ExiTx_Get_ControlMode(
  P2VAR(Scc_ISO15118_20_ControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="ControlMode" */
  /* Call the state machine related callback function */
  Scc_ISO15118_20_StateM_Get_ControlMode(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVCCID 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVCCID(
  P2VAR(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="EVCCID" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20CM_EVCCID(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedAuthorizationService 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedAuthorizationService(
  P2VAR(Exi_ISO_20_CM_10_authorizationType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="SelectedAuthorizationService" */
  /* Call the state machine related callback function */
  Scc_ISO15118_20CM_StateM_Get_SelectedAuthorizationService(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SupportedServiceIDs 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SupportedServiceIDs(
  P2VAR(Exi_ISO_20_CM_10_ServiceIDListType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="SupportedServiceIDs" */
  /* Call the state machine related callback function */
  Scc_ISO15118_20CM_StateM_Get_SupportedServiceIDs(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ServiceIDRx 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ServiceIDRx(
  P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="ServiceIDRx" */
  /* Call the state machine related callback function */
  Scc_ISO15118_20CM_StateM_Get_ServiceIDRx(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedEnergyTransferService 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedEnergyTransferService(
  P2VAR(Exi_ISO_20_CM_10_SelectedServiceType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="SelectedEnergyTransferService" */
  /* Call the state machine related callback function */
  Scc_ISO15118_20CM_StateM_Get_SelectedEnergyTransferService(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedVASListPtr 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedVASListPtr(
  P2VAR(Exi_ISO_20_CM_10_SelectedServiceListType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="SelectedVASListPtr" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20CM_SelectedVASListPtr(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVTargetVoltage 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVTargetVoltage(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="EVTargetVoltage" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20CM_EVTargetVoltage(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_MeterInfoRequested 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_MeterInfoRequested(
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="MeterInfoRequested" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20CM_MeterInfoRequested(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_DisplayParameters 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_DisplayParameters(
  P2VAR(Exi_ISO_20_CT_10_DisplayParametersType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="DisplayParameters" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20CM_DisplayParameters(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_MaximumSupportingPoints 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_MaximumSupportingPoints(
  P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="MaximumSupportingPoints" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20CM_MaximumSupportingPoints(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ScheduleExchangeReqChoice 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ScheduleExchangeReqChoice(
  P2VAR(Exi_ISO_20_CM_10_ScheduleExchangeReqChoiceType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="ScheduleExchangeReqChoice" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20CM_ScheduleExchangeReqChoice(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVProcessing 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVProcessing(
  P2VAR(Exi_ISO_20_CT_10_processingType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="EVProcessing" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20CM_EVProcessing(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ChargeProgress 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ChargeProgress(
  P2VAR(Exi_ISO_20_CM_10_chargeProgressType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="ChargeProgress" */
  /* Call the state machine related callback function */
  Scc_ISO15118_20CM_StateM_Get_ChargeProgress(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVPowerProfile 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVPowerProfile(
  P2VAR(Exi_ISO_20_CM_10_EVPowerProfileType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="EVPowerProfile" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20CM_EVPowerProfile(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_BPT_ChannelSelection 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_BPT_ChannelSelection(
  P2VAR(Exi_ISO_20_CM_10_channelSelectionType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="BPT_ChannelSelection" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20CM_BPT_ChannelSelection(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedScheduleTupleID 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedScheduleTupleID(
  P2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="SelectedScheduleTupleID" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20CM_SelectedScheduleTupleID(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_MeterInfoRx 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Use the configured default value
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_MeterInfoRx(
  P2VAR(Exi_ISO_20_CT_10_MeterInfoType*, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="MeterInfoRx" */
  /* Use the configured default value */
  *DataPtr = (Exi_ISO_20_CT_10_MeterInfoType*)0; /* PRQA S 4332 */ /* MD_SCC_GENERIC_CFG_PARAMETER */ 
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ReceiptRx 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Use the configured default value
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ReceiptRx(
  P2VAR(Exi_ISO_20_CT_10_ReceiptType*, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="ReceiptRx" */
  /* Use the configured default value */
  *DataPtr = (Exi_ISO_20_CT_10_ReceiptType*)0; /* PRQA S 4332 */ /* MD_SCC_GENERIC_CFG_PARAMETER */ 
  *Flag = TRUE;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ChargingSession 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ChargingSession(
  P2VAR(Exi_ISO_20_CM_10_chargingSessionType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="ChargingSession" */
  /* Call the state machine related callback function */
  Scc_ISO15118_20CM_StateM_Get_ChargingSession(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVTerminationCode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVTerminationCode(
  P2VAR(Exi_ISO_20_CT_10_nameType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="EVTerminationCode" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20CM_EVTerminationCode(DataPtr, Flag);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVTerminationExplanation 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVTerminationExplanation(
  P2VAR(Exi_ISO_20_CT_10_descriptionType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonRxParam" && name=="EVTerminationExplanation" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20CM_EVTerminationExplanation(DataPtr, Flag);
}



/**********************************************************************************************************************
 * TX INTERFACE
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEProcessing 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEProcessing(
  Exi_ISO_20_CT_10_processingType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonTxParam" && name=="EVSEProcessing" */
  /* Call the related state machine callback */
  Scc_ISO15118_20_StateM_Set_EVSEProcessing(Data);
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20_EVSEProcessing(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(
  Exi_ISO_20_CT_10_responseCodeType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonTxParam" && name=="ResponseCode" */
  /* Call the related state machine callback */
  Scc_ISO15118_20_StateM_Set_ResponseCode(Data);
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20_ResponseCode(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(
  Exi_UInt64 Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonTxParam" && name=="TimeStampTx" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20_TimeStampTx(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_MeterInfo 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_MeterInfo(
  P2CONST(Exi_ISO_20_CT_10_MeterInfoType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonTxParam" && name=="MeterInfo" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20_MeterInfo(DataPtr, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_Receipt 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_Receipt(
  P2CONST(Exi_ISO_20_CT_10_ReceiptType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonTxParam" && name=="Receipt" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20_Receipt(DataPtr, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_AuthorizationServices 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_AuthorizationServices(
  P2CONST(Exi_ISO_20_CM_10_authorizationType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  uint8 AuthorizationServicesCount)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonTxParam" && name=="AuthorizationServices" */
  /* Call the related state machine callback */
  Scc_ISO15118_20CM_StateM_Set_AuthorizationServices(DataPtr, AuthorizationServicesCount);
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20CM_AuthorizationServices(DataPtr, AuthorizationServicesCount); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_CertificateInstallationService 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_CertificateInstallationService(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonTxParam" && name=="CertificateInstallationService" */
  /* Call the related state machine callback */
  Scc_ISO15118_20CM_StateM_Set_CertificateInstallationService(Data);
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20CM_CertificateInstallationService(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_AuthorizationMode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_AuthorizationMode(
  P2CONST(Exi_ISO_20_CM_10_AuthorizationSetupResChoiceType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonTxParam" && name=="AuthorizationMode" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20CM_AuthorizationMode(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_RemainingContractCertificateChains 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_RemainingContractCertificateChains(
  uint8 Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonTxParam" && name=="RemainingContractCertificateChains" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20CM_RemainingContractCertificateChains(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_SessionID 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_SessionID(
  P2CONST(Exi_ISO_20_CT_10_sessionIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonTxParam" && name=="SessionID" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20CM_SessionID(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_EVSEID 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_EVSEID(
  P2CONST(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonTxParam" && name=="EVSEID" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20CM_EVSEID(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ServiceRenegotiationSupported 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ServiceRenegotiationSupported(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonTxParam" && name=="ServiceRenegotiationSupported" */
  /* Call the related state machine callback */
  Scc_ISO15118_20CM_StateM_Set_ServiceRenegotiationSupported(Data);
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20CM_ServiceRenegotiationSupported(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_EnergyTransferServiceList 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_EnergyTransferServiceList(
  P2CONST(Exi_ISO_20_CM_10_ServiceListType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonTxParam" && name=="EnergyTransferServiceList" */
  /* Call the related state machine callback */
  Scc_ISO15118_20CM_StateM_Set_EnergyTransferServiceList(DataPtr);
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20CM_EnergyTransferServiceList(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_VASList 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_VASList(
  P2CONST(Exi_ISO_20_CM_10_ServiceListType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonTxParam" && name=="VASList" */
  /* Call the related state machine callback */
  Scc_ISO15118_20CM_StateM_Set_VASList(DataPtr, Flag);
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20CM_VASList(DataPtr, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ServiceIDTx 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ServiceIDTx(
  uint16 Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonTxParam" && name=="ServiceIDTx" */
  /* Call the related state machine callback */
  Scc_ISO15118_20CM_StateM_Set_ServiceIDTx(Data);
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20CM_ServiceIDTx(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ServiceParameterList 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ServiceParameterList(
  P2CONST(Exi_ISO_20_CM_10_ServiceParameterListType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonTxParam" && name=="ServiceParameterList" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20CM_ServiceParameterList(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEStatus 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEStatus(
  P2CONST(Exi_ISO_20_CT_10_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonTxParam" && name=="EVSEStatus" */
  /* Call the related state machine callback */
  Scc_ISO15118_20_StateM_Set_EVSEStatus(DataPtr, Flag);
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20_EVSEStatus(DataPtr, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_GoToPause 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_GoToPause(
  boolean Data,
  Exi_BitType Flag)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonTxParam" && name=="GoToPause" */
  /* Call the related state machine callback */
  Scc_ISO15118_20CM_StateM_Set_GoToPause(Data, Flag);
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20CM_GoToPause(Data, Flag); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ScheduleExchangeResChoice 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ScheduleExchangeResChoice(
  P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeResChoiceType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20CommonMessages/SccIso_20CommonTxParam" && name=="ScheduleExchangeResChoice" */
  /* Call the related state machine callback */
  Scc_ISO15118_20CM_StateM_Set_ScheduleExchangeResChoice(DataPtr);
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20CM_ScheduleExchangeResChoice(DataPtr); /*lint !e522 */ /* Application specific implementation */
}




/**********************************************************************************************************************
 * Section: DC Message
 * Description: Configuration for parameters defined in the DC specific schema
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * RX INTERFACE - information to be sent is going to be fetched from upper layers
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_DC_CPDReqEnergyTransferMode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_DC_CPDReqEnergyTransferMode(
  P2VAR(Exi_ISO_20_DC_10_DC_CPDReqEnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20DcMessages/SccIso_20DcRxParam" && name=="DC_CPDReqEnergyTransferMode" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20DC_DC_CPDReqEnergyTransferMode(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_BPT_DC_CPDReqEnergyTransferMode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_BPT_DC_CPDReqEnergyTransferMode(
  P2VAR(Exi_ISO_20_DC_10_BPT_DC_CPDReqEnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20DcMessages/SccIso_20DcRxParam" && name=="BPT_DC_CPDReqEnergyTransferMode" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20DC_BPT_DC_CPDReqEnergyTransferMode(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_BPT_Dynamic_DC_CLReqControlMode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_BPT_Dynamic_DC_CLReqControlMode(
  P2VAR(Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20DcMessages/SccIso_20DcRxParam" && name=="BPT_Dynamic_DC_CLReqControlMode" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20DC_BPT_Dynamic_DC_CLReqControlMode(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_BPT_Scheduled_DC_CLReqControlMode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_BPT_Scheduled_DC_CLReqControlMode(
  P2VAR(Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20DcMessages/SccIso_20DcRxParam" && name=="BPT_Scheduled_DC_CLReqControlMode" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20DC_BPT_Scheduled_DC_CLReqControlMode(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_Dynamic_DC_CLReqControlMode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_Dynamic_DC_CLReqControlMode(
  P2VAR(Exi_ISO_20_DC_10_Dynamic_DC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20DcMessages/SccIso_20DcRxParam" && name=="Dynamic_DC_CLReqControlMode" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20DC_Dynamic_DC_CLReqControlMode(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_Scheduled_DC_CLReqControlMode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_Scheduled_DC_CLReqControlMode(
  P2VAR(Exi_ISO_20_DC_10_Scheduled_DC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20DcMessages/SccIso_20DcRxParam" && name=="Scheduled_DC_CLReqControlMode" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20DC_Scheduled_DC_CLReqControlMode(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_EVPresentVoltage 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_EVPresentVoltage(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20DcMessages/SccIso_20DcRxParam" && name=="EVPresentVoltage" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_ISO_20DC_EVPresentVoltage(DataPtr);
}

 
/**********************************************************************************************************************
 * TX INTERFACE - received information is going to be propagated to upper layers
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_CPDResEnergyTransferMode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_CPDResEnergyTransferMode(
  P2CONST(Exi_ISO_20_DC_10_DC_CPDResEnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20DcMessages/SccIso_20DcTxParam" && name=="DC_CPDResEnergyTransferMode" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20DC_DC_CPDResEnergyTransferMode(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_BPT_DC_CPDResEnergyTransferMode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_BPT_DC_CPDResEnergyTransferMode(
  P2CONST(Exi_ISO_20_DC_10_BPT_DC_CPDResEnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20DcMessages/SccIso_20DcTxParam" && name=="BPT_DC_CPDResEnergyTransferMode" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20DC_BPT_DC_CPDResEnergyTransferMode(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEPresentCurrent 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEPresentCurrent(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20DcMessages/SccIso_20DcTxParam" && name=="DC_EVSEPresentCurrent" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20DC_DC_EVSEPresentCurrent(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEPresentVoltage 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEPresentVoltage(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20DcMessages/SccIso_20DcTxParam" && name=="DC_EVSEPresentVoltage" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20DC_DC_EVSEPresentVoltage(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEPowerLimitAchieved 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEPowerLimitAchieved(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20DcMessages/SccIso_20DcTxParam" && name=="DC_EVSEPowerLimitAchieved" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20DC_DC_EVSEPowerLimitAchieved(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSECurrentLimitAchieved 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSECurrentLimitAchieved(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20DcMessages/SccIso_20DcTxParam" && name=="DC_EVSECurrentLimitAchieved" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20DC_DC_EVSECurrentLimitAchieved(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEVoltageLimitAchieved 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEVoltageLimitAchieved(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20DcMessages/SccIso_20DcTxParam" && name=="DC_EVSEVoltageLimitAchieved" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20DC_DC_EVSEVoltageLimitAchieved(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_Scheduled_DC_CLResControlMode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_Scheduled_DC_CLResControlMode(
  P2CONST(Exi_ISO_20_DC_10_Scheduled_DC_CLResControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20DcMessages/SccIso_20DcTxParam" && name=="Scheduled_DC_CLResControlMode" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20DC_Scheduled_DC_CLResControlMode(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_BPT_Scheduled_DC_CLResControlMode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_BPT_Scheduled_DC_CLResControlMode(
  P2CONST(Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLResControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20DcMessages/SccIso_20DcTxParam" && name=="BPT_Scheduled_DC_CLResControlMode" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20DC_BPT_Scheduled_DC_CLResControlMode(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_Dynamic_DC_CLResControlMode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_Dynamic_DC_CLResControlMode(
  P2CONST(Exi_ISO_20_DC_10_Dynamic_DC_CLResControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20DcMessages/SccIso_20DcTxParam" && name=="Dynamic_DC_CLResControlMode" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20DC_Dynamic_DC_CLResControlMode(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_BPT_Dynamic_DC_CLResControlMode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_BPT_Dynamic_DC_CLResControlMode(
  P2CONST(Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLResControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccIso15118_20/SccIso15118_20DcMessages/SccIso_20DcTxParam" && name=="BPT_Dynamic_DC_CLResControlMode" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_ISO_20DC_BPT_Dynamic_DC_CLResControlMode(DataPtr); /*lint !e522 */ /* Application specific implementation */
}




#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20_InterfaceCfg.c
 *********************************************************************************************************************/

