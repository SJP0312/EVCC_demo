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
 *              File: Scc_Core_InterfaceCfg.h
 *   Generation Time: 2025-08-26 17:17:04
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#if !defined(SCC_CORE_INTERFACECFG_H)
#define SCC_CORE_INTERFACECFG_H

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
#include "Scc_Types.h"
#include "Scc_Lcfg.h"
#include "Slac.h"


#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * RX INTERFACE - information to be sent is going to be fetched from upper layers
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Get_CyclicMsgTrigRx 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Get_CyclicMsgTrigRx(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Get_MsgTrig 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Get_MsgTrig(P2VAR(Scc_MsgTrigType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Get_SccTlsClientAuthParam 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in]      VehicleChainList A list with information for configured vehicle certs.
 *  \param[in]      VehicleChainListLen Number of list entries of VehicleChainList.
 *  \param[in]      SccPreferredSelection Preferred vehicle chain idx of Scc.
 *  \param[in,out]  ApplState A flag indicating if application needs more time to make the decision.
 *  \param[in,out]  SelectedChainIdx The selected chain Idx.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Get_SccTlsClientAuthParam(P2CONST(Scc_ISO20PotentialVehicleChainList, AUTOMATIC, SCC_APPL_DATA) VehicleChainList, uint8 VehicleChainListLen, P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) SccPreferredSelection, P2VAR(Scc_ISO20VehicleChainSelectionType, AUTOMATIC, SCC_APPL_DATA) ApplState, P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) SelectedChainIdx);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Get_PrioritizationCipherAndSignature 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  AvailableCipherSuites The available cipher suites
 *  \param[in,out]  AvailableCipherSuitesLen The length of available cipher suites
 *  \param[in,out]  AvailableSignatureAlgorithms The length of available signature algorithms
 *  \param[in,out]  AvailableSignatureAlgorithmsLen The length of available signature algorithms
 *  \param[in,out]  ApplState The current status of Application doing resorting
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Get_PrioritizationCipherAndSignature(P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) AvailableCipherSuites, P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) AvailableCipherSuitesLen, P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) AvailableSignatureAlgorithms, P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) AvailableSignatureAlgorithmsLen, P2VAR(TcpIp_TlsChangeCipherStatusType, AUTOMATIC, SCC_APPL_DATA) ApplState);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Get_IsPushButtonModeInUsage 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Get_IsPushButtonModeInUsage(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Get_RejectedEllipticCurve 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Get_RejectedEllipticCurve(P2VAR(Scc_CertificateCurveEnumType, AUTOMATIC, SCC_APPL_DATA) DataPtr);


/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Get_AmpMapMode 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Get_AmpMapMode(P2VAR(Slac_AmpMapModeType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Get_ValidationInfo 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Get_ValidationInfo(P2VAR(Slac_ValidationExecutionType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Get_RandomData 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Get_RandomData(P2VAR(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Get_IsResume 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Get_IsResume(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Get_ResumeNMK 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Get_ResumeNMK(P2VAR(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Get_ResumeNID 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Get_ResumeNID(P2VAR(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Get_ResumeEvseMac 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Get_ResumeEvseMac(P2VAR(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Get_ExecuteLeave 
 *********************************************************************************************************************/
/*! \brief          Calls the configured callback for information that is requested by the core from upper layer.
 *  \details        The provided information is going to be used in the message that is going to be sent by Scc
 *  \param[in,out]  DataPtr The information that should be propagated to Scc core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Get_ExecuteLeave(P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) DataPtr);



/**********************************************************************************************************************
 * TX INTERFACE - received information is going to be propagated to upper layers
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_MsgRxIndication 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_MsgRxIndication(void);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(boolean Data);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_CyclicMsgTrigTx 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_CyclicMsgTrigTx(boolean Data);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_IPAssigned 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_IPAssigned(boolean Data);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_MsgState 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_MsgState(Scc_MsgStateType Data);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_MsgStatus 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_MsgStatus(Scc_MsgStatusType Data);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_StackError 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_StackError(Scc_StackErrorType Data);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_TCPSocketState 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_TCPSocketState(Scc_TCPSocketStateType Data);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_TrcvLinkState 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_TrcvLinkState(boolean Data);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_TLS_CertChain 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \param[in]      CertChainStatusPtr The certificate chain
 *  \param[in,out]  ValidationResult The validation result that may be overwritten by the application
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_TLS_CertChain(uint32 Data, P2CONST(TcpIp_CertValidationStatusType, AUTOMATIC, SCC_APPL_DATA) CertChainStatusPtr, P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) ValidationResult);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_TLS_CertChainIsPrivate 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_TLS_CertChainIsPrivate(boolean Data);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_V2GResponse 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_V2GResponse(P2CONST(Scc_TxRxBufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_V2GRequest 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_V2GRequest(P2CONST(Scc_TxRxBufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_DetailedError 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_DetailedError(Scc_DetailedErrorEnumType Data);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_CurrentChannel 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_CurrentChannel(Scc_CoreChannelType Data);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_FinishProcessingCurrentChannel 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_FinishProcessingCurrentChannel(Scc_CoreChannelType Data);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_SECCLeafDCIdentifierFound 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_SECCLeafDCIdentifierFound(boolean Data);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_UnsupportedEncryptedKeyCurve 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_UnsupportedEncryptedKeyCurve(uint8 Data);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_SessionResumed 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_SessionResumed(boolean Data);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_TLS_VersionUsed 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_TLS_VersionUsed(TcpIp_TlsVersionType Data);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_TLS_SignatureAlgorithmUsed 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_TLS_SignatureAlgorithmUsed(TcpIp_SignatureAlgorithmIdType Data);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_TLS_CipherSuiteUsed 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_TLS_CipherSuiteUsed(TcpIp_TlsCipherDataType Data);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_TLS_RootCertId 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_TLS_RootCertId(TcpIp_CertificateIdType Data);

/**********************************************************************************************************************
 *  Scc_Core_InterfaceCfg_Set_OnHoldTimeout 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_InterfaceCfg_Set_OnHoldTimeout(void);


/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Set_AssociationStatus 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Set_AssociationStatus(Slac_AssocStatusType Data);

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Set_NMK 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Set_NMK(P2CONST(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Set_NID 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Set_NID(P2CONST(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Set_BcbToggleState 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Set_BcbToggleState(Slac_ControlPilotStateType Data);

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Set_ReadyForSlac 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Set_ReadyForSlac(boolean Data);

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Set_EvseMac 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      DataPtr The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Set_EvseMac(P2CONST(Scc_BufferPointerType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Set_ExecuteValidationInfo 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Set_ExecuteValidationInfo(Slac_ValidationInfoType Data);

/**********************************************************************************************************************
 *  Scc_SLAC_InterfaceCfg_Set_DLinkReady 
 *********************************************************************************************************************/
/*! \brief          Propagates the information to the configured callback.
 *  \details        Propagates the information of the related received message by Scc to upper layers
 *  \param[in]      Data The information to propagate
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_SLAC_InterfaceCfg_Set_DLinkReady(Slac_DLinkStatusType Data);



#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_CORE_INTERFACECFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Scc_Core_InterfaceCfg.h
 *********************************************************************************************************************/

