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
 *              File: Scc_ISO15118_20_InterfaceCfg.h
 *   Generation Time: 2025-08-28 10:22:05
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#if !defined(SCC_ISO15118_20_INTERFACECFG_H)
#define SCC_ISO15118_20_INTERFACECFG_H

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Scc_Types.h"
#include "Scc_ISO15118_20_StateM.h"
#include "Scc_ISO15118_20CM_StateM.h"



#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Section: Common Message
 * Description: Configuration for parameters defined in the Common Messages schema
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * RX INTERFACE - information to be sent is going to be fetched from upper layers
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_InterfaceCfg_ExiTx_Get_TimeStamp 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_InterfaceCfg_ExiTx_Get_TimeStamp(P2VAR(Exi_UInt64, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_InterfaceCfg_ExiTx_Get_ControlMode 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_InterfaceCfg_ExiTx_Get_ControlMode(P2VAR(Scc_ISO15118_20_ControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVCCID 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVCCID(P2VAR(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedAuthorizationService 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedAuthorizationService(P2VAR(Exi_ISO_20_CM_10_authorizationType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SupportedServiceIDs 
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
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SupportedServiceIDs(P2VAR(Exi_ISO_20_CM_10_ServiceIDListType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ServiceIDRx 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ServiceIDRx(P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedEnergyTransferService 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedEnergyTransferService(P2VAR(Exi_ISO_20_CM_10_SelectedServiceType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedVASListPtr 
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
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedVASListPtr(P2VAR(Exi_ISO_20_CM_10_SelectedServiceListType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVTargetVoltage 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVTargetVoltage(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_MeterInfoRequested 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_MeterInfoRequested(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_DisplayParameters 
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
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_DisplayParameters(P2VAR(Exi_ISO_20_CT_10_DisplayParametersType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_MaximumSupportingPoints 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_MaximumSupportingPoints(P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ScheduleExchangeReqChoice 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ScheduleExchangeReqChoice(P2VAR(Exi_ISO_20_CM_10_ScheduleExchangeReqChoiceType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVProcessing 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVProcessing(P2VAR(Exi_ISO_20_CT_10_processingType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ChargeProgress 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ChargeProgress(P2VAR(Exi_ISO_20_CM_10_chargeProgressType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVPowerProfile 
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
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVPowerProfile(P2VAR(Exi_ISO_20_CM_10_EVPowerProfileType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_BPT_ChannelSelection 
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
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_BPT_ChannelSelection(P2VAR(Exi_ISO_20_CM_10_channelSelectionType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedScheduleTupleID 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedScheduleTupleID(P2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_MeterInfoRx 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_MeterInfoRx(P2VAR(Exi_ISO_20_CT_10_MeterInfoType*, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ReceiptRx 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \param[in,out]  Flag A flag indicating if information is present
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ReceiptRx(P2VAR(Exi_ISO_20_CT_10_ReceiptType*, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ChargingSession 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ChargingSession(P2VAR(Exi_ISO_20_CM_10_chargingSessionType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVTerminationCode 
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
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVTerminationCode(P2VAR(Exi_ISO_20_CT_10_nameType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVTerminationExplanation 
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
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVTerminationExplanation(P2VAR(Exi_ISO_20_CT_10_descriptionType, AUTOMATIC, SCC_APPL_DATA) DataPtr, P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);


/**********************************************************************************************************************
 * TX INTERFACE - received information is going to be propagated to upper layers
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEProcessing 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEProcessing(Exi_ISO_20_CT_10_processingType Data);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(Exi_ISO_20_CT_10_responseCodeType Data);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(Exi_UInt64 Data);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_MeterInfo 
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
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_MeterInfo(P2CONST(Exi_ISO_20_CT_10_MeterInfoType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_Receipt 
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
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_Receipt(P2CONST(Exi_ISO_20_CT_10_ReceiptType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_AuthorizationServices 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \param[in]      AuthorizationServicesCount The number of services
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_AuthorizationServices(P2CONST(Exi_ISO_20_CM_10_authorizationType, AUTOMATIC, SCC_APPL_DATA) DataPtr, uint8 AuthorizationServicesCount);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_CertificateInstallationService 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_CertificateInstallationService(boolean Data);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_AuthorizationMode 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_AuthorizationMode(P2CONST(Exi_ISO_20_CM_10_AuthorizationSetupResChoiceType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_RemainingContractCertificateChains 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_RemainingContractCertificateChains(uint8 Data);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_SessionID 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_SessionID(P2CONST(Exi_ISO_20_CT_10_sessionIDType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_EVSEID 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_EVSEID(P2CONST(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ServiceRenegotiationSupported 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ServiceRenegotiationSupported(boolean Data);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_EnergyTransferServiceList 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_EnergyTransferServiceList(P2CONST(Exi_ISO_20_CM_10_ServiceListType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_VASList 
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
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_VASList(P2CONST(Exi_ISO_20_CM_10_ServiceListType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ServiceIDTx 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ServiceIDTx(uint16 Data);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ServiceParameterList 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ServiceParameterList(P2CONST(Exi_ISO_20_CM_10_ServiceParameterListType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEStatus 
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
FUNC(void, SCC_CODE) Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEStatus(P2CONST(Exi_ISO_20_CT_10_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA) DataPtr, Exi_BitType Flag);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_GoToPause 
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
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_GoToPause(boolean Data, Exi_BitType Flag);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ScheduleExchangeResChoice 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ScheduleExchangeResChoice(P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeResChoiceType, AUTOMATIC, SCC_APPL_DATA) DataPtr);



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
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_DC_CPDReqEnergyTransferMode(P2VAR(Exi_ISO_20_DC_10_DC_CPDReqEnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_BPT_DC_CPDReqEnergyTransferMode 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_BPT_DC_CPDReqEnergyTransferMode(P2VAR(Exi_ISO_20_DC_10_BPT_DC_CPDReqEnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_BPT_Dynamic_DC_CLReqControlMode 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_BPT_Dynamic_DC_CLReqControlMode(P2VAR(Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_BPT_Scheduled_DC_CLReqControlMode 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_BPT_Scheduled_DC_CLReqControlMode(P2VAR(Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_Dynamic_DC_CLReqControlMode 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_Dynamic_DC_CLReqControlMode(P2VAR(Exi_ISO_20_DC_10_Dynamic_DC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_Scheduled_DC_CLReqControlMode 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_Scheduled_DC_CLReqControlMode(P2VAR(Exi_ISO_20_DC_10_Scheduled_DC_CLReqControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_EVPresentVoltage 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiTx_Get_EVPresentVoltage(P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);


/**********************************************************************************************************************
 * TX INTERFACE - received information is going to be propagated to upper layers
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_CPDResEnergyTransferMode 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_CPDResEnergyTransferMode(P2CONST(Exi_ISO_20_DC_10_DC_CPDResEnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_BPT_DC_CPDResEnergyTransferMode 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_BPT_DC_CPDResEnergyTransferMode(P2CONST(Exi_ISO_20_DC_10_BPT_DC_CPDResEnergyTransferModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEPresentCurrent 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEPresentCurrent(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEPresentVoltage 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEPresentVoltage(P2CONST(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEPowerLimitAchieved 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEPowerLimitAchieved(boolean Data);

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSECurrentLimitAchieved 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSECurrentLimitAchieved(boolean Data);

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEVoltageLimitAchieved 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_DC_EVSEVoltageLimitAchieved(boolean Data);

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_Scheduled_DC_CLResControlMode 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_Scheduled_DC_CLResControlMode(P2CONST(Exi_ISO_20_DC_10_Scheduled_DC_CLResControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_BPT_Scheduled_DC_CLResControlMode 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_BPT_Scheduled_DC_CLResControlMode(P2CONST(Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLResControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_Dynamic_DC_CLResControlMode 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_Dynamic_DC_CLResControlMode(P2CONST(Exi_ISO_20_DC_10_Dynamic_DC_CLResControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_BPT_Dynamic_DC_CLResControlMode 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20DC_InterfaceCfg_ExiRx_Set_BPT_Dynamic_DC_CLResControlMode(P2CONST(Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLResControlModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);




#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* SCC_ISO15118_20_INTERFACECFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20_InterfaceCfg.h
 *********************************************************************************************************************/

