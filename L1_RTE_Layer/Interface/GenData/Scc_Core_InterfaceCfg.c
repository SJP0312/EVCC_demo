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
 *              File: Scc_Core_InterfaceCfg.c
 *   Generation Time: 2025-09-11 15:40:09
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#define SCC_CORE_INTERFACECFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Scc_Core_InterfaceCfg.h"
#include "Scc_StateM_Vector.h"
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
 *  Scc_Core_InterfaceCfg_Get_CyclicMsgTrigRx 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Get_CyclicMsgTrigRx(
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreRxParam" && name=="CyclicMsgTrigRx" */
  /* Call the state machine related callback function */
  Scc_StateM_Get_Core_CyclicMsgTrigRx(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Get_MsgTrig 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Get_MsgTrig(
  P2VAR(Scc_MsgTrigType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreRxParam" && name=="MsgTrig" */
  /* Call the state machine related callback function */
  Scc_StateM_Get_Core_MsgTrig(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Get_SccTlsClientAuthParam 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Get_SccTlsClientAuthParam(
  P2CONST(Scc_ISO20PotentialVehicleChainList, AUTOMATIC, SCC_APPL_DATA) VehicleChainList,
  uint8 VehicleChainListLen,
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) SccPreferredSelection,
  P2VAR(Scc_ISO20VehicleChainSelectionType, AUTOMATIC, SCC_APPL_DATA) ApplState,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) SelectedChainIdx)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreRxParam" && name=="SccTlsClientAuthParam" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_Core_SccTlsClientAuthParam(VehicleChainList, VehicleChainListLen, SccPreferredSelection, ApplState, SelectedChainIdx);
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Get_PrioritizationCipherAndSignature 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Get_PrioritizationCipherAndSignature(
  P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) AvailableCipherSuites,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) AvailableCipherSuitesLen,
  P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) AvailableSignatureAlgorithms,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) AvailableSignatureAlgorithmsLen,
  P2VAR(TcpIp_TlsChangeCipherStatusType, AUTOMATIC, SCC_APPL_DATA) ApplState)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreRxParam" && name=="PrioritizationCipherAndSignature" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_Core_PrioritizationCipherAndSignature(AvailableCipherSuites, AvailableCipherSuitesLen, AvailableSignatureAlgorithms, AvailableSignatureAlgorithmsLen, ApplState);
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Get_IsPushButtonModeInUsage 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Get_IsPushButtonModeInUsage(
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreRxParam" && name=="IsPushButtonModeInUsage" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_Core_IsPushButtonModeInUsage(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Get_RejectedEllipticCurve 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Get_RejectedEllipticCurve(
  P2VAR(Scc_CertificateCurveEnumType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreRxParam" && name=="RejectedEllipticCurve" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_Core_RejectedEllipticCurve(DataPtr);
}


/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Get_AmpMapMode 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the state machine related callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Get_AmpMapMode(
  P2VAR(Slac_AmpMapModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSlac/SccSlacRxParam" && name=="AmpMapMode" */
  /* Call the state machine related callback function */
  Scc_StateM_Get_SLAC_AmpMapMode(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Get_ValidationInfo 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Get_ValidationInfo(
  P2VAR(Slac_ValidationExecutionType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSlac/SccSlacRxParam" && name=="ValidationInfo" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_SLAC_ValidationInfo(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Get_RandomData 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Get_RandomData(
  P2VAR(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSlac/SccSlacRxParam" && name=="RandomData" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_SLAC_RandomData(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Get_IsResume 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Get_IsResume(
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSlac/SccSlacRxParam" && name=="IsResume" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_SLAC_IsResume(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Get_ResumeNMK 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Get_ResumeNMK(
  P2VAR(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSlac/SccSlacRxParam" && name=="ResumeNMK" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_SLAC_ResumeNMK(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Get_ResumeNID 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Get_ResumeNID(
  P2VAR(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSlac/SccSlacRxParam" && name=="ResumeNID" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_SLAC_ResumeNID(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Get_ResumeEvseMac 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Get_ResumeEvseMac(
  P2VAR(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSlac/SccSlacRxParam" && name=="ResumeEvseMac" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_SLAC_ResumeEvseMac(DataPtr);
}

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Get_ExecuteLeave 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured callback function
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Get_ExecuteLeave(
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSlac/SccSlacRxParam" && name=="ExecuteLeave" */
  /* Call the configured callback function */
  Appl_SccCbk_Get_SLAC_ExecuteLeave(DataPtr);
}



/**********************************************************************************************************************
 * TX INTERFACE
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_MsgRxIndication 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_MsgRxIndication(
  void)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="MsgRxIndication" */
  /* Call the related state machine callback */
  Scc_StateM_Set_Core_MsgRxIndication();
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="CyclicMsgRcvd" */
  /* Call the related state machine callback */
  Scc_StateM_Set_Core_CyclicMsgRcvd(Data);
  /* Call the configured application callback */
  Appl_SccCbk_Set_Core_CyclicMsgRcvd(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_CyclicMsgTrigTx 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_CyclicMsgTrigTx(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="CyclicMsgTrigTx" */
  /* Call the related state machine callback */
  Scc_StateM_Set_Core_CyclicMsgTrigTx(Data);
  /* Call the configured application callback */
  Appl_SccCbk_Set_Core_CyclicMsgTrigTx(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_IPAssigned 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_IPAssigned(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="IPAssigned" */
  /* Call the related state machine callback */
  Scc_StateM_Set_Core_IPAssigned(Data);
  /* Call the configured application callback */
  Appl_SccCbk_Set_Core_IPAssigned(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_MsgState 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_MsgState(
  Scc_MsgStateType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="MsgState" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_Core_MsgState(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_MsgStatus 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_MsgStatus(
  Scc_MsgStatusType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="MsgStatus" */
  /* Call the related state machine callback */
  Scc_StateM_Set_Core_MsgStatus(Data);
  /* Call the configured application callback */
  Appl_SccCbk_Set_Core_MsgStatus(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_StackError 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_StackError(
  Scc_StackErrorType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="StackError" */
  /* Call the related state machine callback */
  Scc_StateM_Set_Core_StackError(Data);
  /* Call the configured application callback */
  Appl_SccCbk_Set_Core_StackError(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_TCPSocketState 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_TCPSocketState(
  Scc_TCPSocketStateType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="TCPSocketState" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_Core_TCPSocketState(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_TrcvLinkState 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_TrcvLinkState(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="TrcvLinkState" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_Core_TrcvLinkState(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_TLS_CertChain 
 *********************************************************************************************************************/
/*!
 * \internal
 * - No callback configured
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_TLS_CertChain(
  uint32 Data,
  P2CONST(TcpIp_CertValidationStatusType, AUTOMATIC, SCC_APPL_DATA) CertChainStatusPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) ValidationResult)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="TLS_CertChain" */
  /* No callback configured */
  SCC_DUMMY_STATEMENT_CONST(Data); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  SCC_DUMMY_STATEMENT_CONST(CertChainStatusPtr); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  SCC_DUMMY_STATEMENT(*ValidationResult); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_TLS_CertChainIsPrivate 
 *********************************************************************************************************************/
/*!
 * \internal
 * - No callback configured
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_TLS_CertChainIsPrivate(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="TLS_CertChainIsPrivate" */
  /* No callback configured */
  SCC_DUMMY_STATEMENT_CONST(Data); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_V2GResponse 
 *********************************************************************************************************************/
/*!
 * \internal
 * - No callback configured
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_V2GResponse(
  P2CONST(Scc_TxRxBufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="V2GResponse" */
  /* No callback configured */
  SCC_DUMMY_STATEMENT_CONST(DataPtr); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_V2GRequest 
 *********************************************************************************************************************/
/*!
 * \internal
 * - No callback configured
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_V2GRequest(
  P2CONST(Scc_TxRxBufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="V2GRequest" */
  /* No callback configured */
  SCC_DUMMY_STATEMENT_CONST(DataPtr); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_DetailedError 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_DetailedError(
  Scc_DetailedErrorEnumType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="DetailedError" */
  /* Call the related state machine callback */
  Scc_StateM_Set_Core_DetailedError(Data);
  /* Call the configured application callback */
  Appl_SccCbk_Set_Core_DetailedError(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_CurrentChannel 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_CurrentChannel(
  Scc_CoreChannelType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="CurrentChannel" */
  /* Call the related state machine callback */
  Scc_StateM_Set_Core_CurrentChannel(Data);
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_FinishProcessingCurrentChannel 
 *********************************************************************************************************************/
/*!
 * \internal
 * - No callback configured
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_FinishProcessingCurrentChannel(
  Scc_CoreChannelType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="FinishProcessingCurrentChannel" */
  /* No callback configured */
  SCC_DUMMY_STATEMENT_CONST(Data); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_SECCLeafDCIdentifierFound 
 *********************************************************************************************************************/
/*!
 * \internal
 * - No callback configured
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_SECCLeafDCIdentifierFound(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="SECCLeafDCIdentifierFound" */
  /* No callback configured */
  SCC_DUMMY_STATEMENT_CONST(Data); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_UnsupportedEncryptedKeyCurve 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_UnsupportedEncryptedKeyCurve(
  uint8 Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="UnsupportedEncryptedKeyCurve" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_Core_UnsupportedEncryptedKeyCurve(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_SessionResumed 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_SessionResumed(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="SessionResumed" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_Core_SessionResumed(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_TLS_VersionUsed 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_TLS_VersionUsed(
  TcpIp_TlsVersionType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="TLS_VersionUsed" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_Core_TLS_VersionUsed(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_TLS_SignatureAlgorithmUsed 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_TLS_SignatureAlgorithmUsed(
  TcpIp_SignatureAlgorithmIdType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="TLS_SignatureAlgorithmUsed" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_Core_TLS_SignatureAlgorithmUsed(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_TLS_CipherSuiteUsed 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_TLS_CipherSuiteUsed(
  TcpIp_TlsCipherDataType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="TLS_CipherSuiteUsed" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_Core_TLS_CipherSuiteUsed(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_TLS_RootCertId 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_TLS_RootCertId(
  TcpIp_CertificateIdType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="TLS_RootCertId" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_Core_TLS_RootCertId(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_OnHoldTimeout 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_OnHoldTimeout(
  void)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccCore/SccCoreTxParam" && name=="OnHoldTimeout" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_Core_OnHoldTimeout(); /*lint !e522 */ /* Application specific implementation */
}


/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Set_AssociationStatus 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Set_AssociationStatus(
  Slac_AssocStatusType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSlac/SccSlacTxParam" && name=="AssociationStatus" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_SLAC_AssociationStatus(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Set_NMK 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Set_NMK(
  P2CONST(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSlac/SccSlacTxParam" && name=="NMK" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_SLAC_NMK(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Set_NID 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Set_NID(
  P2CONST(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSlac/SccSlacTxParam" && name=="NID" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_SLAC_NID(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Set_BcbToggleState 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Set_BcbToggleState(
  Slac_ControlPilotStateType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSlac/SccSlacTxParam" && name=="BcbToggleState" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_SLAC_BcbToggleState(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Set_ReadyForSlac 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Set_ReadyForSlac(
  boolean Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSlac/SccSlacTxParam" && name=="ReadyForSlac" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_SLAC_ReadyForSlac(Data); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Set_EvseMac 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Set_EvseMac(
  P2CONST(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSlac/SccSlacTxParam" && name=="EvseMac" */
  /* Call the configured application callback */
  Appl_SccCbk_Set_SLAC_EvseMac(DataPtr); /*lint !e522 */ /* Application specific implementation */
}

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Set_ExecuteValidationInfo 
 *********************************************************************************************************************/
/*!
 * \internal
 * - No callback configured
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Set_ExecuteValidationInfo(
  Slac_ValidationInfoType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSlac/SccSlacTxParam" && name=="ExecuteValidationInfo" */
  /* No callback configured */
  SCC_DUMMY_STATEMENT_CONST(Data); /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Set_DLinkReady 
 *********************************************************************************************************************/
/*!
 * \internal
 * - Call the related state machine callback
 * - Call the configured application callback
 * \endinternal
 */
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Set_DLinkReady(
  Slac_DLinkStatusType Data)
{
  /* FindView expression: definition=="/MICROSAR/Scc/SccParameterMapping/SccSlac/SccSlacTxParam" && name=="DLinkReady" */
  /* Call the related state machine callback */
  Scc_StateM_Set_SLAC_DLinkReady(Data);
  /* Call the configured application callback */
  Appl_SccCbk_Set_SLAC_DLinkReady(Data); /*lint !e522 */ /* Application specific implementation */
}


#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Scc_Core_InterfaceCfg.c
 *********************************************************************************************************************/

