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
 *              File: Scc_Lcfg.h
 *   Generation Time: 2025-08-28 10:22:05
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#if !defined(SCC_LCFG_H)
#define SCC_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Types.h"

 
/**********************************************************************************************************************
 *  DYNAMIC GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum Scc_dynConfigParamsType
{
  Scc_DynConfigParam_StateM_ParamCfg_ServiceRenegotiation
} Scc_DynConfigParamsType;


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


typedef enum Scc_StateTypeDef
{
  Scc_State_Uninitialized, 
  Scc_State_Initialized, 
  Scc_State_SDPComplete, 
  Scc_State_TLConnecting, 
  Scc_State_TLConnected, 
  Scc_State_SAPComplete, 
  Scc_State_Connected, 
  Scc_State_Disconnected, 
  Scc_State_ShuttingDown, 
  Scc_State_ShutDown
} Scc_StateType;

typedef enum Scc_StackErrorTypeDef
{
  Scc_StackError_NoError, 
  Scc_StackError_SLAC, 
  Scc_StackError_TransportLayer, 
  Scc_StackError_InvalidTxParameter, 
  Scc_StackError_Timeout, 
  Scc_StackError_IpBase, 
  Scc_StackError_Exi, 
  Scc_StackError_XmlSecurity, 
  Scc_StackError_XmlSecurityMissingReference, 
  Scc_StackError_Crypto, 
  Scc_StackError_InvalidKeyPair, 
  Scc_StackError_InvalidRxMessage, 
  Scc_StackError_InvalidRxParameter, 
  Scc_StackError_NegativeResponseCode, 
  Scc_StackError_PBufToSmall, 
  Scc_StackError_RxQueue, 
  Scc_StackError_KeyM, 
  Scc_StackError_BufferPool, 
  Scc_StackError_Unspecified
} Scc_StackErrorType;

typedef enum Scc_MsgStatusTypeDef
{
  Scc_MsgStatus_None, 
  Scc_MsgStatus_SLAC_OK,
  Scc_MsgStatus_SLAC_Failed, 
  Scc_MsgStatus_SECCDiscoveryProtocol_OK,
  Scc_MsgStatus_SECCDiscoveryProtocol_Failed, 
  Scc_MsgStatus_TransportLayer_OK,
  Scc_MsgStatus_TransportLayer_Failed, 
  Scc_MsgStatus_SupportedAppProtocol_OK,
  Scc_MsgStatus_SupportedAppProtocol_Failed, 
  Scc_MsgStatus_SessionSetup_OK,
  Scc_MsgStatus_SessionSetup_Failed, 
  Scc_MsgStatus_AuthorizationSetup_OK,
  Scc_MsgStatus_AuthorizationSetup_Failed, 
  Scc_MsgStatus_ServiceDiscovery_OK,
  Scc_MsgStatus_ServiceDiscovery_Failed, 
  Scc_MsgStatus_ReadContrCertChain_OK,
  Scc_MsgStatus_ReadContrCertChain_Failed, 
  Scc_MsgStatus_ServiceDetail_OK,
  Scc_MsgStatus_ServiceDetail_Failed, 
  Scc_MsgStatus_PaymentServiceSelection_OK,
  Scc_MsgStatus_PaymentServiceSelection_Failed, 
  Scc_MsgStatus_ReadRootCerts_OK,
  Scc_MsgStatus_ReadRootCerts_Failed, 
  Scc_MsgStatus_ReadOemProvCert_OK,
  Scc_MsgStatus_ReadOemProvCert_Failed, 
  Scc_MsgStatus_CertificateInstallation_OK,
  Scc_MsgStatus_CertificateInstallation_Failed, 
  Scc_MsgStatus_CertificateUpdate_OK,
  Scc_MsgStatus_CertificateUpdate_Failed, 
  Scc_MsgStatus_PaymentDetails_OK,
  Scc_MsgStatus_PaymentDetails_Failed, 
  Scc_MsgStatus_Authorization_OK,
  Scc_MsgStatus_Authorization_Failed, 
  Scc_MsgStatus_ChargeParameterDiscovery_OK,
  Scc_MsgStatus_ChargeParameterDiscovery_Failed, 
  Scc_MsgStatus_ScheduleExchange_OK,
  Scc_MsgStatus_ScheduleExchange_Failed, 
  Scc_MsgStatus_PowerDelivery_OK,
  Scc_MsgStatus_PowerDelivery_Failed, 
  Scc_MsgStatus_ChargeLoop_OK,
  Scc_MsgStatus_ChargeLoop_Failed, 
  Scc_MsgStatus_MeteringReceipt_OK,
  Scc_MsgStatus_MeteringReceipt_Failed, 
  Scc_MsgStatus_CableCheck_OK,
  Scc_MsgStatus_CableCheck_Failed, 
  Scc_MsgStatus_PreCharge_OK,
  Scc_MsgStatus_PreCharge_Failed, 
  Scc_MsgStatus_CurrentDemand_OK,
  Scc_MsgStatus_CurrentDemand_Failed, 
  Scc_MsgStatus_WeldingDetection_OK,
  Scc_MsgStatus_WeldingDetection_Failed, 
  Scc_MsgStatus_SessionStop_OK,
  Scc_MsgStatus_SessionStop_Failed, 
  Scc_MsgStatus_StopCommunicationSession_OK,
  Scc_MsgStatus_StopCommunicationSession_Failed, 
  Scc_MsgStatus_LeavePLCNetwork_OK,
  Scc_MsgStatus_LeavePLCNetwork_Failed, 
  Scc_MsgStatus_Error_LeavePLCNetwork_OK,
  Scc_MsgStatus_Error_LeavePLCNetwork_Failed
} Scc_MsgStatusType;

typedef enum Scc_MsgTrigTypeDef
{
  Scc_MsgTrig_None, 
  Scc_MsgTrig_SLAC, 
  Scc_MsgTrig_SECCDiscoveryProtocol, 
  Scc_MsgTrig_TransportLayer, 
  Scc_MsgTrig_SupportedAppProtocol, 
  Scc_MsgTrig_SessionSetup, 
  Scc_MsgTrig_ServiceDiscovery, 
  Scc_MsgTrig_AuthorizationSetup, 
  Scc_MsgTrig_ReadContrCertChain, 
  Scc_MsgTrig_ServiceDetail, 
  Scc_MsgTrig_PaymentServiceSelection /* Scc_MsgTrig_ServicePaymentSelection */ , 
  Scc_MsgTrig_ReadRootCerts, 
  Scc_MsgTrig_ReadOemProvCert, 
  Scc_MsgTrig_CertificateInstallation, 
  Scc_MsgTrig_CertificateUpdate, 
  Scc_MsgTrig_PaymentDetails, 
  Scc_MsgTrig_Authorization /* Scc_MsgTrig_ContractAuthentication */ , 
  Scc_MsgTrig_ChargeParameterDiscovery, 
  Scc_MsgTrig_ScheduleExchange, 
  Scc_MsgTrig_PowerDelivery, 
  Scc_MsgTrig_ChargeLoop, 
  Scc_MsgTrig_MeteringReceipt, 
  Scc_MsgTrig_CableCheck, 
  Scc_MsgTrig_PreCharge, 
  Scc_MsgTrig_CurrentDemand, 
  Scc_MsgTrig_WeldingDetection, 
  Scc_MsgTrig_SessionStop, 
  Scc_MsgTrig_StopCommunicationSession, 
  Scc_MsgTrig_LeavePLCNetwork, 
  Scc_MsgTrig_Error_LeavePLCNetwork
} Scc_MsgTrigType;

typedef enum Scc_MsgStateTypeDef
{
  Scc_MsgState_WaitForNextRequest /* Wait for the application to trigger a request message. In case of SAP and EXI messages go to Scc_MsgState_PrepareMessageData. In case of SDP send the Req in this state itself */ , 
  Scc_MsgState_PrepareMessageData /* Prepare SAP and EXI Req message to be sent. All Csm and other preparation tasks are done here */ , 
  Scc_MsgState_ReadyToSendRequest /* Message has been prepared. Check if no other message is being transmitted and go to SendRequest */ , 
  Scc_MsgState_SendRequest /* Send the request on TcpIp through CopyTxData */ , 
  Scc_MsgState_WaitingForV2GTpHeader /* Wait for a response message with V2GTpHeader */ , 
  Scc_MsgState_CheckV2GTpHeader /* Check the received V2GTpHeader */ , 
  Scc_MsgState_WaitingForMessageData /* Once message with V2GTpHeader is received and checked, wait for rest of the message to be received */ , 
  Scc_MsgState_HandleResponseData /* Process the received response message */ , 
  Scc_MsgState_DiscardV2GTpHeader /* Discard the data of the received V2GTP header */ , 
  Scc_MsgState_DiscardResponseData /* Discard the data of the received response message */ , 
  Scc_MsgState_RxFatalError /* Fatal error occurred, Scc_Reset needed */ 
} Scc_MsgStateType;

typedef enum Scc_CoreChannelTypeDef
{
  SCC_CHANNEL_DEFAULT, 
  SCC_CHANNEL_MAX
} Scc_CoreChannelType;

typedef enum Scc_StateMachineGenericSubStateEnumTypeDef
{
  Scc_StateMachineGeneric_Prepare, 
  Scc_StateMachineGeneric_Wait, 
  Scc_StateMachineGeneric_Process, 
  Scc_StateMachineGeneric_Error, 
  Scc_StateMachineGeneric_Finish, 
  Scc_StateMachineGeneric_Abort, 
  Scc_StateMachineGeneric_WaitForApplication
} Scc_StateMachineGenericSubStateEnumType;

typedef enum Scc_StateM_StateTypeDef
{
  Scc_SMS_Uninitialized, 
  Scc_SMS_Initialized, 
  Scc_SMS_SLAC, 
  Scc_SMS_WaitForIPAddress, 
  Scc_SMS_SECCDiscoveryProtocol, 
  Scc_SMS_TLConnection, 
  Scc_SMS_SupportedAppProtocol, 
  Scc_SMS_SchemaSpecificState, 
  Scc_SMS_SessionSetup, 
  Scc_SMS_AuthorizationSetup, 
  Scc_SMS_ReadOEMProvCert, 
  Scc_SMS_ServiceDiscovery, 
  Scc_SMS_ReadContractCertificate, 
  Scc_SMS_ReadRootCertificate, 
  Scc_SMS_DeterminePaymentOption, 
  Scc_SMS_VASList, 
  Scc_SMS_ServiceDetail, 
  Scc_SMS_PaymentServiceSelection, 
  Scc_SMS_CertificateInstallation, 
  Scc_SMS_CertificateUpdate, 
  Scc_SMS_PaymentDetails, 
  Scc_SMS_Authorization, 
  Scc_SMS_ChargeParameterDiscovery, 
  Scc_SMS_ScheduleExchange, 
  Scc_SMS_CableCheck, 
  Scc_SMS_PreCharge, 
  Scc_SMS_PowerDelivery, 
  Scc_SMS_ChargeLoop, 
  Scc_SMS_CurrentDemand, 
  Scc_SMS_MeteringReceipt, 
  Scc_SMS_WeldingDetection, 
  Scc_SMS_SessionStop, 
  Scc_SMS_StopCommunicationSession, 
  Scc_SMS_AbortCommunicationSession, 
  Scc_SMS_RestoreOldSessionInformation, 
  Scc_SMS_LeavePLCNetwork, 
  Scc_SMS_Error_LeavePLCNetwork, 
  Scc_SMS_WaitingForRetry, 
  Scc_SMS_Error_WaitingForRetry, 
  Scc_SMS_Stopped, 
  Scc_SMS_Error_Stopped
} Scc_StateM_StateType;

typedef enum Scc_StateM_StateMachineErrorTypeDef
{
  Scc_SMER_NoError, 
  Scc_SMER_Timer_IPAddressWaitTimer, 
  Scc_SMER_Timer_SequencePerformanceTimer, 
  Scc_SMER_Timer_CommunicationSetupTimer, 
  Scc_SMER_Timer_ReadyToChargeTimer, 
  Scc_SMER_Timer_FinePositioningOngoingTimer, 
  Scc_SMER_Timer_PairingOngoingTimer, 
  Scc_SMER_Timer_AuthorizationOngoingTimer, 
  Scc_SMER_Timer_ChargeParameterDiscoveryOngoingTimer, 
  Scc_SMER_Timer_ScheduleExchangeOngoingTimer, 
  Scc_SMER_Timer_InitialAlignmentCheckOngoingTimer, 
  Scc_SMER_Timer_CableCheckOngoingTimer, 
  Scc_SMER_Timer_CableCheckTimer, 
  Scc_SMER_Timer_PreChargeOngoingTimer, 
  Scc_SMER_Timer_PreChargeTimer, 
  Scc_SMER_Timer_WeldingDetectionOngoingTimer, 
  Scc_SMER_Timer_NotificationMaxDelayRenegotiationTimer, 
  Scc_SMER_Initialization_ContractSelectionFailed, 
  Scc_SMER_SECCDiscoveryProtocol_NoSharedSecurityOption, 
  Scc_SMER_SECCDiscoveryProtocol_DiagStatusOngoingTimeout, 
  Scc_SMER_ServiceDiscovery_InvalidEnergyTransferMode, 
  Scc_SMER_ServiceDiscovery_InvalidEnergyTransferServiceAndSchemaMissmatch, 
  Scc_SMER_ServiceDiscovery_NoSharedPaymentOption, 
  Scc_SMER_ServiceDetail_ServiceIdMissmatchFromEVSE, 
  Scc_SMER_ServiceDetail_InvalidServiceIdFromApplication, 
  Scc_SMER_ServiceDetail_UnknownServiceIdFromApplication, 
  Scc_SMER_ServiceSelection_InvalidApplicationValue, 
  Scc_SMER_ServiceSelection_NoContractAndNoCertificateServiceAvailable, 
  Scc_SMER_ServiceSelection_NoContractAndNoInstallationServiceAvailable, 
  Scc_SMER_Authorization_NoCertificatesAvailable, 
  Scc_SMER_Authorization_InvalidApplicationValue, 
  Scc_SMER_Authorization_SwapError, 
  Scc_SMER_Authorization_KeyMReadError, 
  Scc_SMER_InvalidControlPilotState, 
  Scc_SMER_StackError, 
  Scc_SMER_MeteringReceipt_UnsupportedEnergyTransferMode, 
  Scc_SMER_Reset, 
  Scc_SMER_InvalidChargingControl, 
  Scc_SMER_NoSharedPaymentOption, 
  Scc_SMER_UnexpectedMessage, 
  Scc_SMER_Timer_NotificationMaxDelayMeterTimer, 
  Scc_SMER_Timer_NotificationMaxDelayServiceRenegotiationTimer, 
  Scc_SMER_NumOfTaxCostsExceeded, 
  Scc_SMER_NumOfSupportedProvidersExceeded, 
  Scc_SMER_ReadContrCertChain_SwapError, 
  Scc_SMER_ReadContrCertChain_CertChainIndexInUse, 
  Scc_SMER_ChargeLoop_InvalidMeteringRequested, 
  Scc_SMER_Timer_CertificateInstallationOngoingTimer, 
  Scc_SMER_CertificateInstallation_InvalidApplicationValue, 
  Scc_SMER_CertificateInstallation_SwapError, 
  Scc_SMER_CertificateInstallation_CertChainIndexInUse, 
  Scc_SMER_CertificateInstallation_KeyMReadError, 
  Scc_SMER_InvalidPlcActiveValue, 
  Scc_SMER_Timer_AlignmentCheckOngoingTimer, 
  Scc_SMER_Timer_DisconnectOngoingTimer, 
  Scc_SMER_Timer_ConnectOngoingTimer, 
  Scc_SMER_Timer_VehiclePositioningOngoingTimer
} Scc_StateM_StateMachineErrorType;

typedef enum Scc_StateM_ControlPilotStateTypeDef
{
  Scc_ControlPilotState_None, 
  Scc_ControlPilotState_State_A_E_F /* A: The EV is not connected to the Charging Station
                                       E: Problem with the grid or no grid connection
                                       F: Charging Station is not available. */ , 
  Scc_ControlPilotState_State_B /*     B: The EV is connected to the Charging Station but not yet ready for charging */ , 
  Scc_ControlPilotState_State_C_D /*   C/D: The EV is connected to the Charging Station and ready for charging */ 
} Scc_StateM_ControlPilotStateType;

typedef enum Scc_DIN70121_StateM_ErrorModeEnumTypeDef
{
  Scc_DinErrorBeforeChargeParameterDiscovery /* [V2G-DC-649] */ , 
  Scc_DinErrorAfterChargeParameterDiscovery /* [V2G-DC-649] */ 
} Scc_DIN70121_StateM_ErrorModeEnumType;

typedef enum Scc_CertificateStatusTypeDef
{
  Scc_CS_NoCertAvailable, 
  Scc_CS_CertAvailable, 
  Scc_CS_CertExpiresSoon, 
  Scc_CS_CertExpired
} Scc_CertificateStatusType;

typedef Std_ReturnType(*Scc_ChannelTimeoutHandling)(void);

/* Data which is required for parallel channels */
typedef struct
{
  boolean CyclicMsgTrig;
  Scc_MsgTrigType MsgTrig;
  volatile Scc_MsgStateType MsgState;
  uint32 TxDataSent;
  Std_ReturnType TimeoutRetval;
  boolean IsChannelEnabled;
  Scc_ChannelTimeoutHandling TimeoutHandlingFct;
  Scc_RxMsgWSStructType RxMsgWS;
  Scc_TxMsgProcWSStructType TxMsgWS;
  Scc_BufferPoolWSStructType BufferPoolWS;
}Scc_CoreChannelStructType;

typedef enum Scc_StateMachineTimerEnumTypeDef
{
  Scc_StateMachineTimer_GeneralDelay, 
  Scc_StateMachineTimer_DIN70121_CommunicationSetup, 
  Scc_StateMachineTimer_ISO15118_2_CommunicationSetup, 
  Scc_StateMachineTimer_ISO15118_20_CommunicationSetup, 
  Scc_StateMachineTimer_ReadyToCharge, 
  Scc_StateMachineTimer_Ongoing, 
  Scc_StateMachineTimer_IPAddressWait, 
  Scc_StateMachineTimer_SequencePerformance, 
  Scc_StateMachineTimer_CableCheck, 
  Scc_StateMachineTimer_PreCharge, 
  Scc_StateMachineTimer_SequencePerformanceRenegotiation, 
  Scc_StateMachineTimer_GeneralDelayRenegotiation, 
  Scc_StateMachineTimer_OngoingRenegotiation, 
  Scc_StateMachineTimer_NotificationMaxDelayRenegotiation, 
  Scc_StateMachineTimer_NotificationMaxDelayMeter, 
  Scc_StateMachineTimer_NotificationMaxDelayServiceReneg, 
  Scc_StateMachineTimer_NumOfTimers
} Scc_StateMachineTimerEnumType;

typedef enum Scc_StateMachineReturnTypeDef
{
  Scc_StateMachine_Pending, 
  Scc_StateMachine_Finished, 
  Scc_StateMachine_Aborted
} Scc_StateMachineReturnType;

typedef enum Scc_StateMachineStatesReturnTypeDef
{
  Scc_StateMachineState_Failed, 
  Scc_StateMachineState_Done, 
  Scc_StateMachineState_Pending, 
  Scc_StateMachineState_Finished
} Scc_StateMachineStatesReturnType;

typedef P2FUNC(Scc_StateMachineStatesReturnType, SCC_CODE, Scc_StateMachineGenericSubState_PrepareFctType)(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation /**< [out] Error information of the current state. Only evaluated if return value indicates an error. */
  );

typedef P2FUNC(Scc_StateMachineStatesReturnType, SCC_CODE, Scc_StateMachineGenericSubState_WaitFctType)(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation /**< [out] Error information of the current state. Only evaluated if return value indicates an error. */
  );

typedef P2FUNC(Scc_StateMachineStatesReturnType, SCC_CODE, Scc_StateMachineGenericSubState_ProcessFctType)(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState, /**< [out] The next state requested. Only evaluated if return value indicates success. */
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation /**< [out] Error information of the current state. Only evaluated if return value indicates an error. */
  );

typedef struct
{
  Scc_StateMachineGenericSubState_PrepareFctType PrepareFunctionPtr;
  Scc_StateMachineGenericSubState_WaitFctType WaitFunctionPtr;
  Scc_StateMachineGenericSubState_ProcessFctType ProcessResponseFunctionPtr;
}Scc_StateMachineGenericStateStructType;

typedef P2FUNC(Scc_StateMachineStatesReturnType, SCC_CODE, Scc_StateMachineGeneric_TimeoutFctType)(
  Scc_StateM_StateType CurrentState, /**< [in] The current state information */
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation /**< [out] Error information of the timeout handler. Only evaluated if return value indicates an error. */
  );

typedef P2FUNC(Scc_StateMachineStatesReturnType, SCC_CODE, Scc_StateMachineGeneric_ParamCheckFctType)(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation /**< [out] Error information of the parameter handler. Only evaluated if return value indicates an error. */
  );

typedef P2FUNC(Scc_StateMachineStatesReturnType, SCC_CODE, Scc_StateMachineGeneric_ErrorFctType)(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState, /**< [out] The next state requested. Only evaluated if return value indicates success. */
  Scc_StateM_StateMachineErrorType ErrorInformation /**< [in] Error information for the error handling function. */
  );

typedef P2FUNC(void, SCC_CODE, Scc_StateMachineGeneric_SetupFunctionsFctType)(
  Scc_StateM_StateType StateToSetup, /**< [in] State that should be setup. */
  P2VAR(Scc_StateMachineGenericStateStructType, AUTOMATIC, SCC_APPL_DATA) CommonStatePtr /**< [in,out] Pointer to structure that should be setup based on passed state. */
  );

typedef struct
{
  Scc_StateMachineGeneric_SetupFunctionsFctType SetupFunctionsPtr;
  Scc_StateMachineGeneric_TimeoutFctType GlobalTimeoutFunctionPtr;
  Scc_StateMachineGeneric_ParamCheckFctType GlobalCheckFunctionPtr;
  Scc_StateMachineGeneric_ErrorFctType GlobalErrorFunctionPtr;
  Scc_StateMachineGenericStateStructType CurrentStateConfig;
  Scc_StateMachineGenericSubStateEnumType CurrentSubState;
  Scc_StateM_StateType CurrentState;
  Scc_StateM_StateType NextState;
  Scc_StateM_StateMachineErrorType LatestErrorInformation;
  Scc_StateMachineTimerEnumType SequencePerformanceTimerId;
  Scc_CoreChannelType ChannelNumber;
}Scc_StateMachineGenericStructType;

typedef struct
{
  Scc_BitType AC_1P : 1;
  Scc_BitType AC_3P : 1;
  Scc_BitType DC_Core : 1;
  Scc_BitType DC_Extended : 1;
  Scc_BitType DC_Combo_Core : 1;
  Scc_BitType DC_Unique : 1;
}Scc_StateM_EnergyTransferModeStructType;

/* Structure to keep track of user interactions. This information is updated inside the state machine only. */
typedef struct
{
  boolean ShutdownRequested; /* *< [V2G-DC-648], [V2G-DC-673] True: User requested a non-critical shutdown. False no shutdown requested. */
  boolean PowerDeliveryWithReadyToChargeSent;
  boolean MoveToProcess; /* Flag to tell that a request message was not triggered. Hence state machine should move to Process and not wait for a response from EVSE */
}Scc_DIN70121_StateM_UserInteractionStructType;

/* Structure to keep track of received data from an EVSE. It gets updated in the registered callouts of the core. */
typedef struct
{
  Scc_StateM_EVSEProcessingType EVSEProcessing; /* *< Received processing information of the EVSE */
  Scc_StateM_EnergyTransferModeStructType EnergyTransferMode; /* *< Received energy transfer mode that is supported by EVSE */
}Scc_DIN70121_RxEVSEStructType;

/* Structure to keep track of what the application/state machine wants to send. This information is fetched by the core by calling the registered callouts. */
typedef struct
{
  Scc_StateM_EnergyTransferModeType EnergyTransferMode; /* *< Chosen energy transfer mode of the application */
  Scc_StateM_ChargeStatusType ChargeStatus; /* *< Charge status that is set by the state machine */
}Scc_DIN70121_TxEVSEStructType;

/* Contains all state machine relevant information which may needs to be persisted over multiple main function cycles */
typedef struct
{
  Scc_StateMachineGenericStructType StateMachine; /* *< The state machine to execute */
  Scc_StateM_ControlPilotStateType LastControlPilotState; /* *< Last control pilot state. Is only updated if a change on CP is detected */
  boolean EnablePWMDutyCycleMonitoring; /* *< True if PWM should be monitored, otherwise false */
  Scc_DIN70121_StateM_UserInteractionStructType UserInteraction; /* *< Information related to user interaction */
  Scc_DIN70121_RxEVSEStructType RxEVSE; /* *< Information that was received by an EVSE */
  Scc_DIN70121_TxEVSEStructType TxEVSE; /* *< Information that is going to be send to an EVSE */
  Scc_DIN70121_StateM_ErrorModeEnumType ErrorMode; /* *< Current error mode of state machine */
}Scc_DIN70121_StateMLocalStructType;

#define SCC_ISO15118_2_SUPPORTEDSERVICELISTLEN 8u

#define SCC_ISO15118_2_SELECTEDSERVICELISTLEN 16u

/* States that define the handling of service details request */
typedef enum Scc_ISO15118_2_VASStateTypeDef
{
  Scc_ISO15118_2_VASState_NA /* *< Initial state a VAS service. Not Available */ , 
  Scc_ISO15118_2_VASState_Available /* *< VAS is supported by EVSE */ , 
  Scc_ISO15118_2_VASState_DisabledByScc /* *< VAS is disabled by Scc. E.g. service is not free */ , 
  Scc_ISO15118_2_VASState_NoDetails /* *< VAS was disabled and should not be used */ , 
  Scc_ISO15118_2_VASState_RequestDetails /* *< VAS should be requested for details */ , 
  Scc_ISO15118_2_VASState_RequestDetailsDone /* *< VAS details received */ 
} Scc_ISO15118_2_VASStateType;

/* Structure to handle a VAS */
typedef struct
{
  Scc_ServiceIDType ServiceId; /* *< The Id of VAS */
  boolean FreeService; /* *< Flag indicating free service if true */
  Scc_ISO15118_2_VASStateType State; /* *< The current state for details request handling */
}Scc_ISO15118_2_VASStructType;

/* List to handle all services during service discovery and service details */
typedef struct
{
  uint8 SupportedServicesLen;
  Scc_ISO15118_2_VASStructType SupportedServices[SCC_ISO15118_2_SUPPORTEDSERVICELISTLEN];
}Scc_ISO15118_2_VASListStructType;

typedef struct
{
  uint16 ChargeServiceID;
  Scc_StateM_PaymentPrioritizationType EVSEOfferedPaymentOptions;
  Scc_StateM_EVSEProcessingType EVSEProcessing;
  uint16 ProvServiceID;
  boolean ReceiptRequired;
  P2CONST(Exi_ISO_ServiceParameterListType, AUTOMATIC, SCC_VAR_NOINIT) ServiceParameterListPtr;
  Scc_ISO15118_2_VASListStructType SupportedServicesList;
}Scc_ISO15118_2_RxEVSEStructType;

typedef struct
{
  Scc_StateM_ChargeStatusType ChargeStatus;
  Scc_StateM_EnergyTransferModeType EnergyTransferMode;
  Scc_StateM_PaymentOptionType SelectedPaymentOption;
  uint16 ReqServiceID;
  Exi_ISO_SelectedServiceListType SelectedServiceList;
  Exi_ISO_SelectedServiceType SelectedServices[SCC_ISO15118_2_SELECTEDSERVICELISTLEN];
}Scc_ISO15118_2_TxEVSEStructType;

typedef struct
{
  Scc_StateMachineGenericStructType StateMachine;
  boolean CfgReqCertDetails;
  boolean CfgReqInetDetails;
  boolean InvalidEnergyTransferMode;
  Scc_CertificateStatusType ContrCertStatus;
  boolean CertDetailsRequested;
  uint8 SelectedCertChainIndex;
  boolean VASCertInstallationAvailable;
  boolean VASCertUpdateAvailable;
  boolean VASInternetHttpsAvailable;
  boolean VASWaitForApplication;
  uint8 VASServiceListIdx;
  Scc_StateM_ControlPilotStateType LastControlPilotState;
  Scc_ISO15118_2_RxEVSEStructType RxEVSE;
  Scc_ISO15118_2_TxEVSEStructType TxEVSE;
}Scc_ISO15118_2_StateMLocalStructType;

#define SCC_ISO15118_20_STATEM_NUMOFAUTHSERV (2u) /* Defined by the ISO15118-20 V2G_CI_CommonMessages schema */

#define SCC_ISO15118_20_STATEM_NUM_OF_VAS_SERVICES (8u) /* Defined by the ISO15118-20 V2G_CI_CommonMessages schema */

typedef enum Scc_ISO15118_20_ServiceStateTypeDef
{
  Scc_ISO15118_20_SST_NotOffered, 
  Scc_ISO15118_20_SST_ServiceReceived, 
  Scc_ISO15118_20_SST_DetailsRequested, 
  Scc_ISO15118_20_SST_DetailsReceived , 
  Scc_ISO15118_20_SST_ServiceRequested
} Scc_ISO15118_20_ServiceStateType;

typedef struct
{
  Scc_ISO15118_20_ServiceStateType ServiceStatus;
  Scc_ISO15118_20_ServiceIDType ServiceID;
  boolean FreeService;
}Scc_ISO15118_20_ServiceInfoType;

typedef struct
{
  Scc_ISO15118_20_ServiceInfoType AC;
  Scc_ISO15118_20_ServiceInfoType DC;
  Scc_ISO15118_20_ServiceInfoType WPT;
  Scc_ISO15118_20_ServiceInfoType DC_ACDP;
  Scc_ISO15118_20_ServiceInfoType AC_BPT;
  Scc_ISO15118_20_ServiceInfoType DC_BPT;
  Scc_ISO15118_20_ServiceInfoType DC_ACDP_BPT;
}Scc_ISO15118_20_EnergyTransferServicesType;

typedef struct
{
  Scc_ISO15118_20_ServiceInfoType Service[SCC_ISO15118_20_STATEM_NUM_OF_VAS_SERVICES];
  uint8 ListLength;
}Scc_ISO15118_20_VasServiceListType;

typedef struct
{
  Scc_ISO15118_20_ServiceIDType CurrentServiceId; /* Used during ServiceDetail message exchange */
}Scc_ISO15118_20_TemporaryDataType;

typedef struct
{
  Exi_UInt64 TimeAnchor;
  Exi_BitType AdditionalServicesCostsFlag : 1;
  Exi_BitType EnergyCostsFlag : 1;
  Exi_BitType OccupancyCostsFlag : 1;
  Exi_BitType OverstayCostsFlag : 1;
  Exi_BitType TaxCostsFlag : 1;
}Scc_ISO15118_20_ReceiptType;

typedef struct
{
  Scc_StateM_EVSEProcessingType EVSEProcessing[SCC_CHANNEL_MAX];
  Exi_ISO_20_CT_10_responseCodeType ResponseCode[SCC_CHANNEL_MAX];
  Scc_StateM_PaymentOptionType AvailableAuthorizationServices[SCC_ISO15118_20_STATEM_NUMOFAUTHSERV];
  boolean CertificateInstallationAvailable;
  boolean ServiceRenegotiationSupported;
  Scc_ISO15118_20_EnergyTransferServicesType EnergyTransferServices;
  Scc_ISO15118_20_VasServiceListType VASList;
  boolean EnergyTransferServiceDetailDone;
  boolean ServiceDetailsWaitForReTransmission;
  boolean GoToPause;
  sint16 PowerScheduleEntryValue;
  Scc_ISO15118_20_TemporaryDataType TempData;
  uint16 NotificationMaxDelay;
  Exi_ISO_20_CT_10_evseNotificationType EvseNotification[SCC_CHANNEL_MAX];
  Exi_BitType EvseNotificationFlag[SCC_CHANNEL_MAX];
  boolean IsChargeLoopSent; /* [V2G20-1846], [V2G20-1964], [V2G20-1651], [V2G20-5080] Flag set to TRUE as soon as a ChargeLoopReq is sent */
}Scc_ISO15118_20_RxEVSEStructType;

typedef struct
{
  Scc_ISO15118_20_TemporaryDataType TempData;
  Scc_StateM_PaymentOptionType SelectedPaymentOption;
  Scc_ISO15118_20_ServiceIDType SelectedServiceId;
  Scc_ISO15118_20_ControlModeType SelectedControlMode;
  Scc_StateM_ChargeStatusType ChargeStatus;
  Exi_ISO_20_CM_10_chargingSessionType ChargingSession;
}Scc_ISO15118_20_TxEVSEStructType;

typedef struct
{
  Scc_StateMachineGenericStructType StateMachineMainChannel;
  Scc_StateM_ControlPilotStateType LastControlPilotState;
  boolean IsPaused;
  Scc_ISO15118_20_RxEVSEStructType RxEVSE;
  Scc_ISO15118_20_TxEVSEStructType TxEVSE;
}Scc_ISO15118_20_StateMWsStructType;


/**********************************************************************************************************************
 *  GLOBAL VAR DATA PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_VAR_NO_INIT_16_NVM
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* 16-bit variables */

extern VAR(uint16, SCC_VAR_NOINIT) Scc_DynConfigParamsNvm[1U];

#define SCC_STOP_SEC_VAR_NO_INIT_16_NVM
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */             


#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern volatile VAR(Scc_CsmJobInfoType, SCC_VAR_NOINIT) Scc_CsmJobInfo[8];

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

 
/**********************************************************************************************************************
 *  GLOBAL CONST DATA PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CONST_16_NVM
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* 16-bit constants */

extern CONST(uint16, SCC_CONST) Scc_DynConfigParamsNvmRomDefault[1U];

#define SCC_STOP_SEC_CONST_16_NVM
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define SCC_START_SEC_CONST_32
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* CSM config */
extern CONST(Scc_CsmJobInfoIndirectionType, SCC_CONST) Scc_CsmJobInfoIndirection[8];

#define SCC_STOP_SEC_CONST_32
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define SCC_START_SEC_CONST_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* unspecified constants */

extern CONST(Scc_CsmConfigurationStructType, SCC_CONST) Scc_ISO2CsmConfig;
extern CONST(Scc_ISO2CertConfigStructType, SCC_CONST) Scc_ISO2CertConfig;

extern CONST(Scc_CsmJobType, SCC_CONST) Scc_ISO20SHA512Job;
extern CONST(Scc_ISO20CertConfigStructType, SCC_CONST) Scc_ISO20CertConfig;
extern CONST(Scc_CsmConfigurationStructType, SCC_CONST) Scc_ISO20CsmSecp521r1Config;

extern CONST(Scc_TlsCertStructType, SCC_CONST) Scc_TlsCertConfig[SCC_TLS_CERT_CNT];


extern CONST(Scc_BufferPoolArrayType, SCC_CONST) Scc_PoolBufferArray[SCC_NUM_OF_POOL_BUFF];

#define SCC_STOP_SEC_CONST_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/
/* PRQA L:VAR_LEN */

#endif /* SCC_LCFG_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_Lcfg.h
 *********************************************************************************************************************/

