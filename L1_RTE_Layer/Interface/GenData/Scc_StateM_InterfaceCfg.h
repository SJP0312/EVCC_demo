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
 *              File: Scc_StateM_InterfaceCfg.h
 *   Generation Time: 2025-08-28 10:22:05
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#if !defined(SCC_STATEM_INTERFACECFG_H)
#define SCC_STATEM_INTERFACECFG_H

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Scc_Types.h"
#include "Scc_Lcfg.h"

#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * RX INTERFACE - information to be sent is going to be fetched from upper layers
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_ChargingControl 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_ChargingControl(P2VAR(Scc_StateM_ChargingControlType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_ControlPilotState 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_ControlPilotState(P2VAR(Scc_StateM_ControlPilotStateType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_EnergyTransferMode 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_EnergyTransferMode(P2VAR(Scc_StateM_EnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_EVTimeStamp 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_EVTimeStamp(P2VAR(Scc_TimestampType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_FunctionControl 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_FunctionControl(P2VAR(Scc_StateM_FunctionControlType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_PWMState 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_PWMState(P2VAR(Scc_StateM_PWMStateType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_PLCActive 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_PLCActive(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_SupportedServiceIDs 
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
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_SupportedServiceIDs(P2VAR(Exi_ISO_20_CM_10_ServiceIDListType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_ServiceDetailEnergyService 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_ServiceDetailEnergyService(P2VAR(Scc_ISO15118_20_ServiceIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_ServiceDetailVAService 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_ServiceDetailVAService(P2VAR(Scc_ISO15118_20_ServiceIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_SelectedServiceId 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_SelectedServiceId(P2VAR(Scc_ISO15118_20_ServiceIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_SelectedParameterSetId 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_SelectedParameterSetId(P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_ControlMode 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_ControlMode(P2VAR(Scc_ISO15118_20_ControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_ChargingSession 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_ChargingSession(P2VAR(Exi_ISO_20_CM_10_chargingSessionType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Get_StartMetering 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Get_StartMetering(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);


/**********************************************************************************************************************
 * TX INTERFACE - received information is going to be propagated to upper layers
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_EnergyTransferModeFlags 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_EnergyTransferModeFlags(uint8 Data);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_InternetAvailable 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_InternetAvailable(boolean Data);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_StateMachineError 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_StateMachineError(Scc_StateM_StateMachineErrorType Data);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_StateMachineMessageState 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_StateMachineMessageState(Scc_StateM_MsgStateType Data);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_StateMachineStatus 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_StateMachineStatus(Scc_StateM_StateMachineStatusType Data);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_VASReqServiceDetails 
 *********************************************************************************************************************/
/*! \brief          Propagates the information of a VAS service provided by EVSE to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      ServiceId The ServiceId received from EVSE.
 *  \param[in]      IsFreeService Flag for free service identification.
 *  \param[in,out]  RequestDetails Set to TRUE if application wants to request details. Otherwise FALSE.
 *  \param[in,out]  ApplicationPending Set to TRUE if application needs more time to make a decision. Otherwise FALSE.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_VASReqServiceDetails(uint16 ServiceId, boolean IsFreeService, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) RequestDetails, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) ApplicationPending);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_ServiceRenegotiationSupported 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_ServiceRenegotiationSupported(boolean Data);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_EnergyTransferServiceList 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_EnergyTransferServiceList(P2CONST(Exi_ISO_20_CM_10_ServiceListType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_VASList 
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
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_VASList(P2CONST(Exi_ISO_20_CM_10_ServiceListType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_VASServiceDetails 
 *********************************************************************************************************************/
/*! \brief          Propagates the information of a VAS service details provided by EVSE to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      ServiceId The ServiceId received from EVSE.
 *  \param[in]      ParameterSet Received parameter set list.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_VASServiceDetails(uint16 ServiceId, P2CONST(Exi_ISO_ServiceParameterListType, AUTOMATIC, SCC_APPL_DATA) ParameterSet);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_ServiceIDTx 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_ServiceIDTx(Scc_ISO15118_20_ServiceIDType Data);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_SelectedServicesList 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in,out]  ServiceListPtr The ServiceId to select.
 *  \param[in]      ServiceListMaxLen Optional flag. TRUE: the ParameterSetId has to be set.
 *  \param[in,out]  ServiceListLen When called it contains the amount of entries in ServiceListPtr. If list is modified this index must be adjusted accordingly.
 *  \param[in,out]  ApplicationPending TRUE: Application needs more time to make the decision. Scc tries again later.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_SelectedServicesList(P2VAR(Exi_ISO_SelectedServiceType, AUTOMATIC, SCC_APPL_DATA) ServiceListPtr, uint8 ServiceListMaxLen, P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) ServiceListLen, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) ApplicationPending);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_CurrentChannel 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_CurrentChannel(Scc_CoreChannelType Data);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_FinishProcessingCurrentChannel 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_FinishProcessingCurrentChannel(Scc_CoreChannelType Data);

/**********************************************************************************************************************
 *  Scc_StateM_InterfaceCfg_Set_ContractStatus 
 *********************************************************************************************************************/
/*! \brief          Propagates the information of the contract status evaluation to the configured callback.
 *  \details        Provides the expiration date of the contract in use, the time that was used for the check and the result to upper layers
 *  \param[in]      NotAfter The NotAfter time in unix timestamp format of the contract in use.
 *  \param[in]      DateTimeNow The time in unix timestamp format that was used to perform the contract check.
 *  \param[in]      Status The result of contract status evaluation
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InterfaceCfg_Set_ContractStatus(Scc_TimestampType NotAfter, Scc_TimestampType DateTimeNow, Scc_CertificateStatusType Status);



#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_STATEM_INTERFACECFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Scc_StateM_InterfaceCfg.h
 *********************************************************************************************************************/

