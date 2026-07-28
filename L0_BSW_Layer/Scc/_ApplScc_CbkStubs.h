/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  _ApplScc_CbkStubs.h
 *        \brief  Smart Charging Communication Stub Header File
 *
 *      \details  Provides callback stubs for the parameter interface.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/
#if !defined (SCC_CBK_STUBS_H)
#define SCC_CBK_STUBS_H

/**********************************************************************************************************************
*  FILE REQUIRES USER MODIFICATIONS
*  Template Scope: whole file
*  -------------------------------------------------------------------------------------------------------------------
*  This file includes template code that must be completed and/or adapted during BSW integration.
*  The template code is incomplete and only intended for providing a signature and an empty implementation. It is
*  neither intended nor qualified for use in series production without applying suitable quality measures. The template
*  code must be completed as described in the instructions given within this file and/or in the Technical Reference.
*  The completed implementation must be tested with diligent care and must comply with all quality requirements which
*  are necessary according to the state of the art before its use.
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Types.h"
#include "Scc_Cfg.h"
#include "Scc_Lcfg.h"
#include "Exi_ISO_20_WPT_10_SchemaTypes.h"
#include "Scc_Appl_Type_Fallbacks.h"
#include "Appl_IntegrationStubs.h"

/* Callbacks */

/* Rx Core */
void Appl_SccCbk_Get_Core_CyclicMsgTrigRx(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) CyclicMsgTrig);
void Appl_SccCbk_Get_Core_MsgTrig(P2VAR(Scc_MsgTrigType, AUTOMATIC, SCC_APPL_DATA) MsgTrig);
#if (defined(SCC_ENABLE_TLS_ISO20_CLIENTAUTH) && (SCC_ENABLE_TLS_ISO20_CLIENTAUTH == STD_ON))
void Appl_SccCbk_Get_Core_SccTlsClientAuthParam(P2CONST(Scc_ISO20PotentialVehicleChainList, AUTOMATIC, SCC_APPL_DATA) VehicleChainList, uint8 VehicleChainListLen, P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) SccPreferredSelection, P2VAR(Scc_ISO20VehicleChainSelectionType, AUTOMATIC, SCC_APPL_DATA) ApplState, P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) SelectedChainIdx);
#endif
void Appl_SccCbk_Get_Core_SDPSecurityRx(P2VAR(Scc_SDPSecurityType, AUTOMATIC, SCC_APPL_DATA) SDPSecurity);
void Appl_SccCbk_Get_Core_SAPSchemaList(P2VAR(Scc_SAP_SchemaListStructType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) ApplicationPending);
void Appl_SccCbk_Get_Core_SccTlsPEUsage(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_Core_MsgChannel(uint8 Channel);
#if ( defined SCC_ENABLE_TLS ) && ( SCC_ENABLE_TLS != 0 )
void Appl_SccCbk_Get_Core_PrioritizationCipherAndSignature(
  P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) AvailableCipherSuites,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) AvailableCipherSuitesLen,
  P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) AvailableSignatureAlgorithms,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) AvailableSignatureAlgorithmsLen,
  P2VAR(TcpIp_TlsChangeCipherStatusType, AUTOMATIC, SCC_APPL_DATA) ApplState);

void Appl_SccCbk_Get_Core_IsPushButtonModeInUsage(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);
#endif /* SCC_ENABLE_TLS */

/* Tx Core */
void Appl_SccCbk_Set_Core_CyclicMsgRcvd(boolean CyclicMsgRcvd);
void Appl_SccCbk_Set_Core_CyclicMsgTrigTx(boolean CyclicMsgTrig);
void Appl_SccCbk_Set_Core_IPAssigned(boolean IPAssigned);
void Appl_SccCbk_Set_Core_MsgState(Scc_MsgStateType MsgState);
void Appl_SccCbk_Set_Core_MsgRxIndication(void);
void Appl_SccCbk_Set_Core_MsgStatus(Scc_MsgStatusType MsgStatus);
void Appl_SccCbk_Set_Core_SAPResponseCode(Exi_SAP_responseCodeType SAPResponseCode);
void Appl_SccCbk_Set_Core_SAPSchemaID(Scc_SAPSchemaIDType SAPSchemaID);
void Appl_SccCbk_Set_Core_SECCIPAddress(P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) SECCIPAddress);
void Appl_SccCbk_Set_Core_SDPSecurityTx(Scc_SDPSecurityType SDPSecurityTx);
void Appl_SccCbk_Set_Core_SDPTransportProtocol(Scc_SDPTransportProtocolType SDPTransportProtocol);
void Appl_SccCbk_Set_Core_SECCPort(uint16 SECCPort);
void Appl_SccCbk_Set_Core_StackError(Scc_StackErrorType StackError);
void Appl_SccCbk_Set_Core_TrcvLinkState(boolean TrcvLinkState);
void Appl_SccCbk_Set_Core_TCPSocketState(Scc_TCPSocketStateType TCPSocketStateType);
void Appl_SccCbk_Set_Core_TLS_CertChain(uint32 Data, P2CONST(TcpIp_CertValidationStatusType, AUTOMATIC, SCC_APPL_DATA) CertChainStatusPtr, P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) ValidationResult);
void Appl_SccCbk_Set_Core_SECCLeafDCIdentifierFound(boolean Data);
void Appl_SccCbk_Set_Core_UnsupportedEncryptedKeyCurve(uint8 Data);
void Appl_SccCbk_Set_Core_SessionResumed(boolean Data);
void Appl_SccCbk_Set_Core_TLS_CertChainIsPrivate(boolean Data);
void Appl_SccCbk_Set_Core_V2GResponse(P2CONST(Scc_TxRxBufferPointerType, AUTOMATIC, SCC_APPL_DATA) V2GResponse);
void Appl_SccCbk_Set_Core_V2GRequest(P2CONST(Scc_TxRxBufferPointerType, AUTOMATIC, SCC_APPL_DATA) V2GRequest);
void Appl_SccCbk_Set_Core_DetailedError(Scc_DetailedErrorEnumType DetailedError);
void Appl_SccCbk_Set_Core_OcspValid(boolean OcspValid);
void Appl_SccCbk_Set_Core_CurrentChannel(Scc_CoreChannelType Data);
void Appl_SccCbk_Set_Core_FinishProcessingCurrentChannel(Scc_CoreChannelType Data);
void Appl_SccCbk_Set_Core_OnHoldTimeout(void);

#if ( SCC_ENABLE_TLS == STD_ON)
void Appl_SccCbk_Set_Core_TLS_VersionUsed(TcpIp_TlsVersionType Data);
void Appl_SccCbk_Set_Core_TLS_SignatureAlgorithmUsed(TcpIp_SignatureAlgorithmIdType Data);
void Appl_SccCbk_Set_Core_TLS_CipherSuiteUsed(TcpIp_TlsCipherDataType Data);
void Appl_SccCbk_Set_Core_TLS_RootCertId(TcpIp_CertificateIdType Data);
void Appl_SccCbk_Set_Core_TlsSessionTicketInfo(Scc_SocketType SocketId, P2CONST(TcpIp_TlsSessionTicketUserInfoType, AUTOMATIC, SCC_APPL_DATA) SessionTicketInfoPtr);
#endif /* SCC_ENABLE_TLS */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )

/* Rx SLAC */
void Appl_SccCbk_Get_SLAC_AmpMapMode(P2VAR(Slac_AmpMapModeType, AUTOMATIC, SCC_APPL_DATA) SLACAmpMapMode);
void Appl_SccCbk_Get_SLAC_RandomData(P2VAR(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_SLAC_IsResume(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) SLAC_IsResume);
void Appl_SccCbk_Get_SLAC_ResumeNMK(P2VAR(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_SLAC_ResumeNID(P2VAR(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_SLAC_ResumeEvseMac(P2VAR(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_SLAC_ExecuteLeave(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) SLAC_ExecuteLeave);
void Appl_SccCbk_Get_SLAC_ValidationInfo(P2VAR(Slac_ValidationExecutionType, AUTOMATIC, SCC_APPL_DATA) validationExecution);
# if (defined (SCC_ENABLE_SLAC_CHANGEABLE_NMK_FOR_LEAVE) && (SCC_ENABLE_SLAC_CHANGEABLE_NMK_FOR_LEAVE == STD_ON))
void Appl_SccCbk_Get_SLAC_ResetAndLeaveNMK(P2VAR(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_SLAC_ResetAndLeaveNID(P2VAR(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
# endif /* SCC_ENABLE_SLAC_CHANGEABLE_NMK_FOR_LEAVE */

/* Tx SLAC */
void Appl_SccCbk_Set_SLAC_AssociationStatus(Slac_AssocStatusType AssocStatus);
void Appl_SccCbk_Set_SLAC_BcbToggleState(Slac_ControlPilotStateType NewCpState);
void Appl_SccCbk_Set_SLAC_DLinkReady(Slac_DLinkStatusType Data);
void Appl_SccCbk_Set_SLAC_EvseMac(P2CONST(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) EvseMacPtr);
void Appl_SccCbk_Set_SLAC_ExecuteValidationInfo(Slac_ValidationInfoType ValidationInfo);
void Appl_SccCbk_Set_SLAC_NID(P2CONST(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) NIDPtr);
void Appl_SccCbk_Set_SLAC_NMK(P2CONST(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) NMKPtr);
void Appl_SccCbk_Set_SLAC_ReadyForSlac(boolean ReadyForSlac);
#endif /* SCC_ENABLE_SLAC_HANDLING */

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON )

/* Rx StateM */
void Appl_SccCbk_Get_StateM_EnergyTransferServiceIDFlags(P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) TxEnergyTransferServiceIDFlags);
void Appl_SccCbk_Get_StateM_ChargingControl(P2VAR(Scc_StateM_ChargingControlType, AUTOMATIC, SCC_APPL_DATA) ChargingControl);
void Appl_SccCbk_Get_StateM_EnergyTransferMode(P2VAR(Scc_StateM_EnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) EnergyTransferMode);
void Appl_SccCbk_Get_StateM_EVTimeStamp(P2VAR(Scc_TimestampType, AUTOMATIC, SCC_APPL_DATA) EVTimeStamp);
void Appl_SccCbk_Get_StateM_FlowControl(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) FlowControl);
void Appl_SccCbk_Get_StateM_FunctionControl(P2VAR(Scc_StateM_FunctionControlType, AUTOMATIC, SCC_APPL_DATA) FunctionControl);
void Appl_SccCbk_Get_StateM_ControlPilotState(P2VAR(Scc_StateM_ControlPilotStateType, AUTOMATIC, SCC_APPL_DATA) ControlPilotState);
void Appl_SccCbk_Get_StateM_PWMState(P2VAR(Scc_StateM_PWMStateType, AUTOMATIC, SCC_APPL_DATA) PWMState);
void Appl_SccCbk_Get_StateM_RemainingContractCertificateChains(P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) RemainingContractCertificateChains);

#if (( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 ))
void Appl_SccCbk_Set_ISO_2StateM_VASReqServiceDetails(uint16 ServiceId, boolean IsFreeService, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) RequestDetails, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) ApplicationPending);
void Appl_SccCbk_Set_ISO_2StateM_VASServiceDetails(uint16 ServiceId, P2CONST(Exi_ISO_ServiceParameterListType, AUTOMATIC, SCC_APPL_DATA) ParameterSet);
void Appl_SccCbk_Set_ISO_2StateM_SelectedServicesList(P2VAR(Exi_ISO_SelectedServiceType, AUTOMATIC, SCC_APPL_DATA) ServiceListPtr, uint8 ServiceListMaxLen, P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) ServiceListLen, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) ApplicationPending);
#endif /* SCC_SCHEMA_ISO */

#if (( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 ))
void Appl_SccCbk_Get_StateM_ChargeProgress(P2VAR(Exi_ISO_20_CM_10_chargeProgressType, AUTOMATIC, SCC_APPL_DATA) ChargingProgress);
void Appl_SccCbk_Get_StateM_PLCActive(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20StateM_SupportedServiceIDs(P2VAR(Exi_ISO_20_CM_10_ServiceIDListType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_ISO_20StateM_ServiceDetailEnergyService(P2VAR(Scc_ISO15118_20_ServiceIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20StateM_ServiceDetailVAService(P2VAR(Scc_ISO15118_20_ServiceIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20StateM_SelectedServiceId(P2VAR(Scc_ISO15118_20_ServiceIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20StateM_SelectedParameterSetId(P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) DataPtr);
#endif /* SCC_SCHEMA_ISO_20 */

/* Tx StateM */
void Appl_SccCbk_Set_StateM_EnergyTransferServiceIDFlags(uint16 RxEnergyTransferServiceIDFlags);
void Appl_SccCbk_Set_StateM_VasIdFlags(uint8 VasIdFlags);
void Appl_SccCbk_Set_StateM_EnergyTransferModeFlags(uint8 EnergyTransferModeFlags);
void Appl_SccCbk_Set_StateM_InternetAvailable(boolean InternetAvailable);
void Appl_SccCbk_Set_StateM_StateMachineError(Scc_StateM_StateMachineErrorType StateMachineError);
void Appl_SccCbk_Set_StateM_StateMachineMessageState(Scc_StateM_MsgStateType StateMachineMessageState);
void Appl_SccCbk_Set_StateM_StateMachineStatus(Scc_StateM_StateMachineStatusType StateMachineStatus);
void Appl_SccCbk_Set_StateM_CurrentChannel(Scc_CoreChannelType Data);
void Appl_SccCbk_Set_StateM_FinishProcessingCurrentChannel(Scc_CoreChannelType Data);
void Appl_SccCbk_Set_StateM_ContractStatus(Scc_TimestampType NotAfter, Scc_TimestampType DateTimeNow, Scc_CertificateStatusType Status);
#if (( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 ))
void Appl_SccCbk_Set_ISO_20StateM_ProviderIdList(P2CONST(Scc_ISO15118_20_SupportedProvidersType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20StateM_ContractCertificateChainIds(P2CONST(Scc_AvailableCertStructType, AUTOMATIC, SCC_APPL_DATA) DataPtr, uint8 CertArrayIdLen);
void Appl_SccCbk_Set_ISO_20StateM_PreferredContractCertificateChainId(Scc_CertArrayIdType Data);
void Appl_SccCbk_Set_ISO_20StateM_CertificateInstallationService(boolean Data);
void Appl_SccCbk_Set_ISO_20StateM_ProvCertIds(
  P2CONST(Scc_CertArrayIdType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  uint8 CertArrayIdLen);
void Appl_SccCbk_Set_ISO_20StateM_PreferredProvCertId(
  Scc_CertArrayIdType Data);
void Appl_SccCbk_Set_ISO_20StateM_PrioritizedEmaid(
  P2CONST(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20StateM_ServiceRenegotiationSupported(boolean Data);
void Appl_SccCbk_Get_ISO_20StateM_ControlMode(P2VAR(Scc_ISO15118_20_ControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20StateM_ChargingSession(P2VAR(Exi_ISO_20_CM_10_chargingSessionType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20StateM_StartRenegotiation(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20StateM_StartMetering(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20StateM_ProceedToCertInstall(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20StateM_ContractCertificateChainId(P2VAR(Scc_CertArrayIdType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20StateM_ChangeToEim(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20StateM_ChangeToPnc(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20StateM_ProvCertId(
  P2VAR(Scc_CertArrayIdType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_ISO_20StateM_PrioritizedEmaids(
  P2VAR(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Set_ISO_20StateM_ServiceIDTx(Scc_ISO15118_20_ServiceIDType Data);
void Appl_SccCbk_Set_ISO_20StateM_EnergyTransferServiceList(P2CONST(Exi_ISO_20_CM_10_ServiceListType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20StateM_VASList(P2CONST(Exi_ISO_20_CM_10_ServiceListType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);
#endif /* SCC_SCHEMA_ISO_20 */
#endif /* SCC_ENABLE_STATE_MACHINE */

#if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )

/* Rx ISO */
void Appl_SccCbk_Get_ISO_ChargeProgress(P2VAR(Exi_ISO_chargeProgressType, AUTOMATIC, SCC_APPL_DATA) ChargeProgress);
void Appl_SccCbk_Get_ISO_ChargingSession(P2VAR(Scc_ISO_ChargingSessionType, AUTOMATIC, SCC_APPL_DATA) ChargingSession);
#if ( defined SCC_ENABLE_INTERNAL_CHARGING_PROFILE_BUFFER ) && ( SCC_ENABLE_INTERNAL_CHARGING_PROFILE_BUFFER == STD_ON )
void Appl_SccCbk_Get_ISO_ChargingProfilePtr(P2VAR(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) ChargingProfilePtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
#else
void Appl_SccCbk_Get_ISO_ChargingProfilePtr(P2VAR(Exi_ISO_ChargingProfileType*, AUTOMATIC, SCC_APPL_DATA) ChargingProfilePtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
#endif /* SCC_ENABLE_INTERNAL_CHARGING_PROFILE_BUFFER */
void Appl_SccCbk_Get_ISO_DepartureTime(P2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) DepartureTime, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_ISO_MaxEntriesSAScheduleTuple(P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) MaxEntriesSAScheduleTuple, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_ISO_RequestedEnergyTransferMode(P2VAR(Exi_ISO_EnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) RequestedEnergyTransferMode);
void Appl_SccCbk_Get_ISO_SAScheduleTupleID(P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) SAScheduleTupleID);
void Appl_SccCbk_Get_ISO_SkipSAScheduleListCheck(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) skipSAScheduleListCheck);
void Appl_SccCbk_Get_ISO_PnC_SkipSalesTariffSignatureCheck(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) skipSalesTariffSignatureCheck);
void Appl_SccCbk_Get_ISO_SelectedPaymentOption(P2VAR(Exi_ISO_paymentOptionType, AUTOMATIC, SCC_APPL_DATA) SelectedPaymentOption);
void Appl_SccCbk_Get_ISO_SelectedServiceListPtr(P2VAR(Exi_ISO_SelectedServiceListType*, AUTOMATIC, SCC_APPL_DATA) SelectedServiceListPtr);
void Appl_SccCbk_Get_ISO_ServiceCategory(P2VAR(Exi_ISO_serviceCategoryType, AUTOMATIC, SCC_APPL_DATA) ServiceCategory, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_ISO_ServiceIDRx(P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) ServiceIDRx);
void Appl_SccCbk_Get_ISO_ServiceScope(P2VAR(Exi_ISO_serviceScopeType, AUTOMATIC, SCC_APPL_DATA) ServiceScope, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_ISO_PnC_InstallContract(P2VAR(Scc_ApplCheckContrChainStateEnumType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

void Appl_SccCbk_Get_ISO_AC_EAmount(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EAmount);
void Appl_SccCbk_Get_ISO_AC_EVMaxVoltage(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVMaxVoltage);
void Appl_SccCbk_Get_ISO_AC_EVMaxCurrent(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVMaxCurrent);
void Appl_SccCbk_Get_ISO_AC_EVMinCurrent(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVMinCurrent);

void Appl_SccCbk_Get_ISO_DC_EVErrorCode(P2VAR(Exi_ISO_DC_EVErrorCodeType, AUTOMATIC, SCC_APPL_DATA) EVErrorCode);

/* Tx ISO */
void Appl_SccCbk_Set_ISO_ChargeService(P2CONST(Exi_ISO_ChargeServiceType, AUTOMATIC, SCC_APPL_DATA) ChargeService);
void Appl_SccCbk_Set_ISO_EVSEID(P2CONST(Exi_ISO_evseIDType, AUTOMATIC, SCC_APPL_DATA) EVSEID);
void Appl_SccCbk_Set_ISO_EVSENotification(Exi_ISO_EVSENotificationType EVSENotification);
void Appl_SccCbk_Set_ISO_EVSEProcessing(Exi_ISO_EVSEProcessingType EVSEProcessing);
void Appl_SccCbk_Set_ISO_EVSETimeStamp(Exi_SInt64 EVSETimeStamp, Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_MeterInfo(P2CONST(Exi_ISO_MeterInfoType, AUTOMATIC, SCC_APPL_DATA) MeterInfo, Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_Notification(P2CONST(Exi_ISO_NotificationType,  AUTOMATIC, SCC_APPL_DATA) Notification, Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_NotificationMaxDelay(uint16 NotificationMaxDelay);
void Appl_SccCbk_Set_ISO_PaymentOptionList(P2CONST(Exi_ISO_PaymentOptionListType, AUTOMATIC, SCC_APPL_DATA) PaymentOptionList);
void Appl_SccCbk_Set_ISO_ResponseCode(Exi_ISO_responseCodeType ResponseCode);
void Appl_SccCbk_Set_ISO_SAScheduleList(P2CONST(Exi_ISO_SAScheduleListType, AUTOMATIC, SCC_APPL_DATA) SAScheduleList);
void Appl_SccCbk_Set_ISO_ServiceIDTx(uint16 ServiceID);
void Appl_SccCbk_Set_ISO_ServiceList(P2CONST(Exi_ISO_ServiceListType, AUTOMATIC, SCC_APPL_DATA) ServiceList, Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_ServiceParameterList(P2CONST(Exi_ISO_ServiceParameterListType, AUTOMATIC, SCC_APPL_DATA) ServiceParameterList, Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_PnC_ReceiptRequired(boolean ReceiptRequired, Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_PnC_RetryCounter(sint16 RetryCounter, Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_SessionID(P2CONST(Exi_ISO_sessionIDType, AUTOMATIC, SCC_APPL_DATA) SessionID);

void Appl_SccCbk_Set_ISO_AC_EVSEMaxCurrent(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVSEMaxCurrent, Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_AC_EVSENominalVoltage(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVSENominalVoltage);
void Appl_SccCbk_Set_ISO_AC_RCD(boolean RCD);

void Appl_SccCbk_Set_ISO_DC_EVSEIsolationStatus(Exi_ISO_isolationLevelType EVSEIsolationStatus, Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_DC_EVSEStatusCode(Exi_ISO_DC_EVSEStatusCodeType EVSEStatusCode);
void Appl_SccCbk_Set_ISO_PnC_ContractToInstall(P2CONST(Scc_PropagateContrCertsStructType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
#endif /* SCC_SCHEMA_ISO */

#if ( (( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )) || (( defined SCC_SCHEMA_DIN ) && ( SCC_SCHEMA_DIN != 0 )) )

/* Rx IsoDin */
void Appl_SccCbk_Get_IsoDin_DC_BulkChargingComplete(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) BulkChargingComplete, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_IsoDin_DC_BulkSOC(P2VAR(sint8, AUTOMATIC, SCC_APPL_DATA) BulkSOC, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_IsoDin_DC_ChargingComplete(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) ChargingComplete);
void Appl_SccCbk_Get_IsoDin_DC_EVEnergyCapacity(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVEnergyCapacity, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_IsoDin_DC_EVEnergyRequest(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVEnergyRequest, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_IsoDin_DC_EVMaximumCurrentLimit(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVMaximumCurrentLimit, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_IsoDin_DC_EVMaximumPowerLimit(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVMaximumPowerLimit, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_IsoDin_DC_EVMaximumVoltageLimit(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVMaximumVoltageLimit, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_IsoDin_DC_EVPowerDeliveryParameterFlag(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) EVPowerDeliveryParameterFlag);
void Appl_SccCbk_Get_IsoDin_DC_EVReady(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) EVReady);
void Appl_SccCbk_Get_IsoDin_DC_EVRESSSOC(P2VAR(sint8, AUTOMATIC, SCC_APPL_DATA) EVRESSSOC);
void Appl_SccCbk_Get_IsoDin_DC_EVTargetCurrent(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVTargetCurrent);
void Appl_SccCbk_Get_IsoDin_DC_EVTargetVoltage(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVTargetVoltage);
void Appl_SccCbk_Get_IsoDin_DC_FullSOC(P2VAR(sint8, AUTOMATIC, SCC_APPL_DATA) FullSOC, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_IsoDin_DC_RemainingTimeToBulkSoC(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) RemainingTimeToBulkSOC, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_IsoDin_DC_RemainingTimeToFullSoC(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) RemainingTimeToFullSOC, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/* Tx IsoDin */
void Appl_SccCbk_Set_IsoDin_DC_EVSECurrentLimitAchieved(boolean EVSECurrentLimitAchieved);
void Appl_SccCbk_Set_IsoDin_DC_EVSECurrentRegulationTolerance(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVSECurrentRegulationTolerance, Exi_BitType Flag);
void Appl_SccCbk_Set_IsoDin_DC_EVSEEnergyToBeDelivered(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVSEEnergyToBeDelivered, Exi_BitType Flag);
void Appl_SccCbk_Set_IsoDin_DC_EVSEMaximumCurrentLimit(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVSEMaximumCurrentLimit, Exi_BitType Flag);
void Appl_SccCbk_Set_IsoDin_DC_EVSEMaximumPowerLimit(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVSEMaximumPowerLimit, Exi_BitType Flag);
void Appl_SccCbk_Set_IsoDin_DC_EVSEMaximumVoltageLimit(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVSEMaximumVoltageLimit, Exi_BitType Flag);
void Appl_SccCbk_Set_IsoDin_DC_EVSEMinimumCurrentLimit(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVSEMinimumCurrentLimit);
void Appl_SccCbk_Set_IsoDin_DC_EVSEMinimumVoltageLimit(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVSEMinimumVoltageLimit);
void Appl_SccCbk_Set_IsoDin_DC_EVSEPeakCurrentRipple(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVSEPeakCurrentRipple);
void Appl_SccCbk_Set_IsoDin_DC_EVSEPowerLimitAchieved(boolean EVSEPowerLimitAchieved);
void Appl_SccCbk_Set_IsoDin_DC_EVSEPresentCurrent(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVSEPresentCurrent);
void Appl_SccCbk_Set_IsoDin_DC_EVSEPresentVoltage(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) EVSEPresentVoltage);
void Appl_SccCbk_Set_IsoDin_DC_EVSEVoltageLimitAchieved(boolean EVSEVoltageLimitAchieved);

#endif /* SCC_SCHEMA_ISO || SCC_SCHEMA_DIN */

#if (( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 ))
void Appl_SccCbk_Get_ISO_20_TimeStamp(
  P2VAR(Exi_UInt64, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_Core_RejectedEllipticCurve(
  P2VAR(Scc_CertificateCurveEnumType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20CM_EVCCID(
  P2VAR(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20CM_SelectedAuthorizationService(
  P2VAR(Exi_ISO_20_CM_10_authorizationType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20CM_GenChallenge(
  P2VAR(Exi_ISO_20_CM_10_genChallengeType*, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20CM_SupportedServiceIDs(
  P2VAR(Exi_ISO_20_CM_10_ServiceIDListType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_ISO_20CM_ServiceIDRx(
  P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20CM_SelectedEnergyTransferService(
  P2VAR(Exi_ISO_20_CM_10_SelectedServiceType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20CM_SelectedVASListPtr(
  P2VAR(Exi_ISO_20_CM_10_SelectedServiceListType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_ISO_20CM_InstallContract(P2VAR(Scc_ApplCheckContrChainStateEnumType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20_EVSEProcessing(Exi_ISO_20_CT_10_processingType EVSEProcessing);
void Appl_SccCbk_Set_ISO_20_ResponseCode(Exi_ISO_20_CT_10_responseCodeType Data);
void Appl_SccCbk_Set_ISO_20_TimeStampTx(
  Exi_UInt64 Data);
void Appl_SccCbk_Set_ISO_20CM_AuthorizationServices(
  P2CONST(Exi_ISO_20_CM_10_authorizationType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  uint8 AuthorizationServicesCount);
void Appl_SccCbk_Set_ISO_20CM_CertificateInstallationService(
  boolean Data);
void Appl_SccCbk_Set_ISO_20CM_AuthorizationMode(
  P2CONST(Exi_ISO_20_CM_10_AuthorizationSetupResChoiceType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20CM_SessionID(
  P2CONST(Exi_ISO_20_CT_10_sessionIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20CM_EVSEID(
  P2CONST(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20CM_ServiceRenegotiationSupported(
  boolean Data);
void Appl_SccCbk_Set_ISO_20CM_EnergyTransferServiceList(
  P2CONST(Exi_ISO_20_CM_10_ServiceListType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20CM_VASList(
  P2CONST(Exi_ISO_20_CM_10_ServiceListType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_20_DepartureTime(
  uint32 Data,
  Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_20_MeterInfo(
  P2CONST(Exi_ISO_20_CT_10_MeterInfoType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_20_Receipt(
  P2CONST(Exi_ISO_20_CT_10_ReceiptType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_20AC_AC_CPDResEnergyTransferMode(
  P2CONST(Exi_ISO_20_AC_10_AC_CPDResEnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20AC_BPT_AC_CPDResEnergyTransferMode(
  P2CONST(Exi_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20AC_AC_EVSETargetFrequency(
  P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_20AC_Scheduled_AC_CLResControlMode(
  P2CONST(Exi_ISO_20_AC_10_Scheduled_AC_CLResControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20AC_BPT_Scheduled_AC_CLResControlMode(
  P2CONST(Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20AC_Dynamic_AC_CLResControlMode(
  P2CONST(Exi_ISO_20_AC_10_Dynamic_AC_CLResControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20AC_BPT_Dynamic_AC_CLResControlMode(
  P2CONST(Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20_EVSEStatus(
  P2CONST(Exi_ISO_20_CT_10_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_20CM_GoToPause(boolean Data, Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_20CM_ScheduleExchangeResChoice(
  P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeResChoiceType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20CM_ServiceParameterList(
  P2CONST(Exi_ISO_20_CM_10_ServiceParameterListType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20CM_ServiceIDTx(
  uint16 Data);
void Appl_SccCbk_Set_ISO_20CM_ContractToInstall(P2CONST(Scc_PropagateContrCertsStructType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20CM_RemainingContractCertificateChains(uint8 Data);



void Appl_SccCbk_Get_ISO_20AC_AC_CPDReqEnergyTransferMode(P2VAR(Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20AC_Dynamic_AC_CLReqControlMode(P2VAR(Exi_ISO_20_AC_10_Dynamic_AC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20DC_Dynamic_DC_CLReqControlMode(P2VAR(Exi_ISO_20_DC_10_Dynamic_DC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20CM_MaximumSupportingPoints(P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20CM_ScheduleExchangeReqChoice(P2VAR(Exi_ISO_20_CM_10_ScheduleExchangeReqChoiceType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20CM_EVProcessing(P2VAR(Exi_ISO_20_CT_10_processingType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20StateM_StartSystemStatus(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20CM_ChargeProgress(P2VAR(Exi_ISO_20_CM_10_chargeProgressType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20CM_EVPowerProfile(P2VAR(Exi_ISO_20_CM_10_EVPowerProfileType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_ISO_20CM_EVTerminationExplanation(P2VAR(Exi_ISO_20_CT_10_descriptionType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_ISO_20CM_MaximumContractCertificateChains(P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20_ControlMode(P2VAR(Scc_ISO15118_20_ControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20AC_BPT_AC_CPDReqEnergyTransferMode(P2VAR(Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20DC_DC_CPDReqEnergyTransferMode(P2VAR(Exi_ISO_20_DC_10_DC_CPDReqEnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20DC_BPT_DC_CPDReqEnergyTransferMode(P2VAR(Exi_ISO_20_DC_10_BPT_DC_CPDReqEnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20CM_EVTargetVoltage(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20CM_MeterInfoRequested(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20AC_Scheduled_AC_CLReqControlMode(P2VAR(Exi_ISO_20_AC_10_Scheduled_AC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20AC_BPT_Scheduled_AC_CLReqControlMode(P2VAR(Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20DC_BPT_Dynamic_DC_CLReqControlMode(P2VAR(Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20DC_BPT_Scheduled_DC_CLReqControlMode(P2VAR(Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20DC_Scheduled_DC_CLReqControlMode(P2VAR(Exi_ISO_20_DC_10_Scheduled_DC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20DC_EVPresentVoltage(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20CM_BPT_ChannelSelection(P2VAR(Exi_ISO_20_CM_10_channelSelectionType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_ISO_20CM_PrioritizedEMAIDs(P2VAR(Exi_ISO_20_CM_10_EMAIDListType*, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_ISO_20CM_SelectedScheduleTupleID(P2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20CM_MeterInfoRx(P2VAR(Exi_ISO_20_CT_10_MeterInfoType*, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20CM_ReceiptRx(
  P2VAR(Exi_ISO_20_CT_10_ReceiptType*, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_ISO_20CM_ChargingSession(P2VAR(Exi_ISO_20_CM_10_chargingSessionType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20CM_EVTerminationCode(P2VAR(Exi_ISO_20_CT_10_nameType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_ISO_20AC_BPT_Dynamic_AC_CLReqControlMode(P2VAR(Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20CM_DisplayParameters(
  P2VAR(Exi_ISO_20_CT_10_DisplayParametersType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Set_ISO_20DC_BPT_DC_CPDResEnergyTransferMode(
  P2CONST(Exi_ISO_20_DC_10_BPT_DC_CPDResEnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20DC_BPT_Dynamic_DC_CLResControlMode(P2CONST(Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLResControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20DC_BPT_Scheduled_DC_CLResControlMode(P2CONST(Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLResControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20DC_DC_CPDResEnergyTransferMode(
  P2CONST(Exi_ISO_20_DC_10_DC_CPDResEnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20DC_DC_EVSECurrentLimitAchieved(boolean Data);
void Appl_SccCbk_Set_ISO_20DC_DC_EVSEPowerLimitAchieved(boolean Data);
void Appl_SccCbk_Set_ISO_20DC_DC_EVSEPresentCurrent(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20DC_DC_EVSEPresentVoltage(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20DC_DC_EVSEVoltageLimitAchieved(boolean Data);
void Appl_SccCbk_Set_ISO_20DC_Dynamic_DC_CLResControlMode(P2CONST(Exi_ISO_20_DC_10_Dynamic_DC_CLResControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20DC_Scheduled_DC_CLResControlMode(P2CONST(Exi_ISO_20_DC_10_Scheduled_DC_CLResControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

void Appl_SccCbk_Get_ISO_20ACDP_EVMobilityStatus(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20ACDP_EVPositioningSupport(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20ACDP_EVElectricalChargingDeviceStatus(P2VAR(Exi_ISO_20_ACDP_10_electricalChargingDeviceStatusType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20ACDP_EVTechnicalStatus(P2VAR(Exi_ISO_20_ACDP_10_EVTechnicalStatusType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20ACDP_EVSEPositioningSupport(boolean Data);
void Appl_SccCbk_Set_ISO_20ACDP_EVRelativeXDeviation(sint16 Data);
void Appl_SccCbk_Set_ISO_20ACDP_EVRelativeYDeviation(sint16 Data);
void Appl_SccCbk_Set_ISO_20ACDP_ContactWindowXc(sint16 Data);
void Appl_SccCbk_Set_ISO_20ACDP_ContactWindowYc(sint16 Data);
void Appl_SccCbk_Set_ISO_20ACDP_EVInChargePosition(boolean Data);
void Appl_SccCbk_Set_ISO_20ACDP_EVSEElectricalChargingDeviceStatus(Exi_ISO_20_ACDP_10_electricalChargingDeviceStatusType Data);
void Appl_SccCbk_Set_ISO_20ACDP_EVSEMechanicalChargingDeviceStatus(Exi_ISO_20_ACDP_10_mechanicalChargingDeviceStatusType Data);
void Appl_SccCbk_Set_ISO_20ACDP_EVSEReadyToCharge(boolean Data);
void Appl_SccCbk_Set_ISO_20ACDP_EVSEIsolationStatus(Exi_ISO_20_ACDP_10_isolationStatusType Data);
void Appl_SccCbk_Set_ISO_20ACDP_EVSEDisabled(boolean Data);
void Appl_SccCbk_Set_ISO_20ACDP_EVSEUtilityInterruptEvent(boolean Data);
void Appl_SccCbk_Set_ISO_20ACDP_EVSEEmergencyShutdown(boolean Data);
void Appl_SccCbk_Set_ISO_20ACDP_EVSEMalfunction(boolean Data);
void Appl_SccCbk_Set_ISO_20ACDP_EVAssociationStatus(boolean Data);

void Appl_SccCbk_Get_ISO_20WPT_EVDeviceFinePositioningMethodList(P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningMethodListType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20WPT_EVDevicePairingMethodList(P2VAR(Exi_ISO_20_WPT_10_WPT_PairingMethodListType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20WPT_EVDeviceAlignmentCheckMethodList(P2VAR(Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodListType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20WPT_NaturalOffset(P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20WPT_VendorSpecificDataContainer(
  P2VAR(Exi_ISO_20_WPT_10_WPT_DataContainerType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_ISO_20WPT_LF_SystemSetupData(
  P2VAR(Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_ISO_20WPT_EVResultCode(P2VAR(Exi_ISO_20_WPT_10_WPT_EVResultType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20WPT_WPT_LF_DataPackageList(
  P2VAR(Exi_ISO_20_WPT_10_WPT_LF_DataPackageListType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_ISO_20WPT_ObservedIDCode(P2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_ISO_20WPT_EVPCMaxReceivablePower(P2VAR(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20WPT_EVPCNaturalFrequency(P2VAR(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20WPT_SDMaxGroundClearence(P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20WPT_SDMinGroundClearence(P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20WPT_EVPCDeviceLocalControl(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20WPT_EVPCPowerRequest(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20WPT_EVPCPowerOutput(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20WPT_EVPCChargeDiagnostics(P2VAR(Exi_ISO_20_WPT_10_WPT_EVPCChargeDiagnosticsType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20WPT_EVPCOperatingFrequency(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_ISO_20WPT_EVPCPowerControlParameter(P2VAR(Exi_ISO_20_WPT_10_WPT_EVPCPowerControlParameterType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_ISO_20WPT_ManufacturerSpecificDataContainer(P2VAR(Exi_ISO_20_WPT_10_WPT_DataContainerType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Set_ISO_20WPT_PrimaryDeviceFinePositioningMethodList(P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningMethodListType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20WPT_PrimaryDevicePairingMethodList(P2CONST(Exi_ISO_20_WPT_10_WPT_PairingMethodListType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20WPT_PrimaryDeviceAlignmentCheckMethodList(P2CONST(Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodListType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20WPT_NaturalOffsetRx(uint16 Data);
void Appl_SccCbk_Set_ISO_20WPT_VendorSpecificDataContainerRx(
  P2CONST(Exi_ISO_20_WPT_10_WPT_DataContainerType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_20WPT_LF_SystemSetupDataRx(
  P2CONST(Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_20WPT_WPT_LF_DataPackageListRx(
  P2CONST(Exi_ISO_20_WPT_10_WPT_LF_DataPackageListType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_20WPT_ObservedIDCodeRx(
  uint32 Data,
  Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_20WPT_AlternativeSECCList(
  P2CONST(Exi_ISO_20_WPT_10_AlternativeSECCListType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_20WPT_PDMaxCoilCurrent(P2CONST(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20WPT_PDMinCoilCurrent(P2CONST(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20WPT_SDMaxOutputPower(P2CONST(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20WPT_SDMinOutputPower(P2CONST(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20WPT_SDMaxGroundClearanceSupport(uint16 Data);
void Appl_SccCbk_Set_ISO_20WPT_SDMinGroundClearanceSupport(uint16 Data);
void Appl_SccCbk_Set_ISO_20WPT_PDInputPowerClass(Exi_ISO_20_WPT_10_WPT_PowerClassType Data);
void Appl_SccCbk_Set_ISO_20WPT_EVPCPowerRequestTx(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20WPT_SDPowerInput(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_20WPT_SPCMaxOutputPowerLimit(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20WPT_SPCMinOutputPowerLimit(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20WPT_SPCChargeDiagnostics(P2CONST(Exi_ISO_20_WPT_10_WPT_SPCChargeDiagnosticsType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_ISO_20WPT_SPCOperatingFrequencyTx(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_20WPT_SPCPowerControlParameter(P2CONST(Exi_ISO_20_WPT_10_WPT_SPCPowerControlParameterType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_20WPT_ManufacturerSpecificDataContainerTx(P2CONST(Exi_ISO_20_WPT_10_WPT_DataContainerType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);
#endif /* SCC_SCHEMA_ISO_20 */

#if ( defined SCC_SCHEMA_DIN ) && ( SCC_SCHEMA_DIN != 0 )

/* Rx DIN */
void Appl_SccCbk_Get_DIN_ChargingProfilePtr(P2VAR(Exi_DIN_ChargingProfileType*, AUTOMATIC, SCC_APPL_DATA) ChargingProfilePtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_DIN_EVCabinConditioning(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) EVCabinConditioning, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_DIN_EVRESSConditioning(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) EVRESSConditioning, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_DIN_EVErrorCode(P2VAR(Exi_DIN_DC_EVErrorCodeType, AUTOMATIC, SCC_APPL_DATA) EVErrorCode);
void Appl_SccCbk_Get_DIN_ReadyToChargeState(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) ReadyToChargeState);
void Appl_SccCbk_Get_DIN_RequestedEnergyTransferMode(P2VAR(Exi_DIN_EVRequestedEnergyTransferType, AUTOMATIC, SCC_APPL_DATA) RequestedEnergyTransferMode);
void Appl_SccCbk_Get_DIN_EVCCID(P2VAR(Exi_DIN_evccIDType, AUTOMATIC, SCC_APPL_DATA) EvccId);
void Appl_SccCbk_Get_DIN_ServiceCategory(P2VAR(Exi_DIN_serviceCategoryType, AUTOMATIC, SCC_APPL_DATA) ServiceCategory, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/* Tx DIN */
void Appl_SccCbk_Set_DIN_ChargeService(P2CONST(Exi_DIN_ServiceChargeType, AUTOMATIC, SCC_APPL_DATA) ChargeService);
void Appl_SccCbk_Set_DIN_DateTimeNow(Exi_SInt64 DateTimeNow, Exi_BitType Flag);
void Appl_SccCbk_Set_DIN_EVSEID(P2CONST(Exi_DIN_evseIDType, AUTOMATIC, SCC_APPL_DATA) EVSEID);
void Appl_SccCbk_Set_DIN_EVSEIsolationStatus(Exi_DIN_isolationLevelType EVSEIsolationStatus, Exi_BitType Flag);
void Appl_SccCbk_Set_DIN_EVSENotification(Exi_DIN_EVSENotificationType EVSENotification);
void Appl_SccCbk_Set_DIN_EVSEProcessing(Exi_DIN_EVSEProcessingType EVSEProcessing);
void Appl_SccCbk_Set_DIN_EVSEStatusCode(Exi_DIN_DC_EVSEStatusCodeType EVSEStatusCode);
void Appl_SccCbk_Set_DIN_NotificationMaxDelay(uint32 NotificationMaxDelay);
void Appl_SccCbk_Set_DIN_ResponseCode(Exi_DIN_responseCodeType ResponseCode);
void Appl_SccCbk_Set_DIN_SAScheduleList(P2CONST(Exi_DIN_SAScheduleListType, AUTOMATIC, SCC_APPL_DATA) SAScheduleList);
void Appl_SccCbk_Set_DIN_SessionID(P2CONST(Exi_DIN_sessionIDType, AUTOMATIC, SCC_APPL_DATA) SessionID);

#endif /* SCC_SCHEMA_DIN */

#if ( defined SCC_SCHEMA_OPP_CHARGE ) && ( SCC_SCHEMA_OPP_CHARGE != 0 )

/* Rx OppCharge */
void Appl_SccCbk_Get_OppCharge_BulkChargingComplete(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_OppCharge_BulkSOC(P2VAR(sint8, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_OppCharge_ChargingComplete(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_OppCharge_ChargingProfilePtr(P2VAR(Exi_DIN_ChargingProfileType*, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_OppCharge_EVCabinConditioning(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_OppCharge_EVEnergyCapacity(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_OppCharge_EVEnergyRequest(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_OppCharge_EVErrorCode(P2VAR(Exi_DIN_DC_EVErrorCodeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_OppCharge_EVMaximumCurrentLimit(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_OppCharge_EVMaximumPowerLimit(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_OppCharge_EVMaximumVoltageLimit(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_OppCharge_EVPowerDeliveryParameterFlag(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_OppCharge_EVReady(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_OppCharge_EVRESSConditioning(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_OppCharge_EVRESSSOC(P2VAR(sint8, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_OppCharge_EVTargetCurrent(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_OppCharge_EVTargetVoltage(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_OppCharge_FullSOC(P2VAR(sint8, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_OppCharge_ReadyToChargeState(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_OppCharge_RemainingTimeToBulkSoC(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_OppCharge_RemainingTimeToFullSoC(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
void Appl_SccCbk_Get_OppCharge_EVCCID(P2VAR(Exi_DIN_evccIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/* Tx OppCharge */
void Appl_SccCbk_Set_OppCharge_ChargeService(P2CONST(Exi_DIN_ServiceChargeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_OppCharge_DateTimeNow(Exi_SInt64 DateTimeNow, Exi_BitType Flag);
void Appl_SccCbk_Set_OppCharge_EVSECurrentLimitAchieved(boolean Data);
void Appl_SccCbk_Set_OppCharge_EVSECurrentRegulationTolerance(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);
void Appl_SccCbk_Set_OppCharge_EVSEEnergyToBeDelivered(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);
void Appl_SccCbk_Set_OppCharge_EVSEID(P2CONST(Exi_DIN_evseIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_OppCharge_EVSEIsolationStatus(Exi_DIN_isolationLevelType Data, Exi_BitType Flag);
void Appl_SccCbk_Set_OppCharge_EVSEMaximumCurrentLimit(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);
void Appl_SccCbk_Set_OppCharge_EVSEMaximumPowerLimit(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);
void Appl_SccCbk_Set_OppCharge_EVSEMaximumVoltageLimit(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);
void Appl_SccCbk_Set_OppCharge_EVSEMinimumCurrentLimit(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_OppCharge_EVSEMinimumVoltageLimit(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_OppCharge_EVSENotification(Exi_DIN_EVSENotificationType Data);
void Appl_SccCbk_Set_OppCharge_EVSEPeakCurrentRipple(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_OppCharge_EVSEPowerLimitAchieved(boolean Data);
void Appl_SccCbk_Set_OppCharge_EVSEPresentCurrent(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_OppCharge_EVSEPresentVoltage(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Set_OppCharge_EVSEProcessing(Exi_DIN_EVSEProcessingType Data);
void Appl_SccCbk_Set_OppCharge_EVSEStatusCode(Exi_DIN_DC_EVSEStatusCodeType Data);
void Appl_SccCbk_Set_OppCharge_EVSEVoltageLimitAchieved(boolean Data);
void Appl_SccCbk_Set_OppCharge_NotificationMaxDelay(uint32 Data);
void Appl_SccCbk_Set_OppCharge_ResponseCode(Exi_DIN_responseCodeType Data);
void Appl_SccCbk_Set_OppCharge_SessionID(P2CONST(Exi_DIN_sessionIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

#endif /* SCC_SCHEMA_OPP_CHARGE */

#if (defined SCC_SCHEMA_ISO_20WPT) && (SCC_SCHEMA_ISO_20WPT != 0)

/* SDP Rx */

void Appl_SccCbk_Get_SDP_SDPCouplingTypeRx(P2VAR(Scc_SDPCouplingType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_SDP_SDPEvId(P2VAR(Scc_SDPEvIdType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_SDP_SDPEvseIdRx(P2VAR(Scc_SDPEvseIdType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_SDP_SDPP2pPpd(P2VAR(Scc_SDPP2pPpdType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_Core_PhysicalLayerTypeRx(P2VAR(Scc_SDPPhysComLayerType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
void Appl_SccCbk_Get_ISO_20WPT_TargetCoilCurrent(P2VAR(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/* SDP Tx */

void Appl_SccCbk_Set_SDP_SDPCouplingTypeTx(Scc_SDPCouplingType Data);
void Appl_SccCbk_Set_SDP_SDPDiagData(Scc_SDPDiagDataType Data);
void Appl_SccCbk_Set_SDP_SDPEvseIdTx(P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) DataPtr, uint16 Length);
void Appl_SccCbk_Set_SDP_SDPPhysicalLayerTypeTx(Scc_SDPPhysComLayerType Data);
void Appl_SccCbk_Set_ISO_20WPT_PowerTransmitted(P2CONST(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);
void Appl_SccCbk_Set_ISO_20WPT_SupplyDeviceCurrent(P2CONST(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);

#endif /* SCC_SCHEMA_ISO_20WPT */


#endif /* SCC_CBK_STUBS_H */
/**********************************************************************************************************************
 *  END OF FILE: _ApplScc_CbkStubs.h
 *********************************************************************************************************************/
