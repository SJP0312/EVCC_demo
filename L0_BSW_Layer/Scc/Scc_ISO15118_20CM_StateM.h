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
/*!        \file  Scc_ISO15118_20CM_StateM.h
 *        \brief  Smart Charging Communication Header File
 *
 *      \details  Implements Vehicle 2 Grid communication according to ISO 15118-20 common messages schema
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/
#if !defined (SCC_ISO15118_20CM_STATEM_H)
# define SCC_ISO15118_20CM_STATEM_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON && (defined(SCC_SCHEMA_ISO_20) && SCC_SCHEMA_ISO_20 != 0u) )

#include "Scc_StateMachineGeneric.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Init
 *********************************************************************************************************************/
/*! \brief          Initialization function
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Init(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM<StateMachineState>_Prepare
 *********************************************************************************************************************/
/*! \brief          Prepares all parameters needed to transmit the associated request message
 *  \details        Set all parameters, the message trigger and the cyclic message trigger.
 *  \param[out]     ErrorInformation    Pointer to error information to set. The error information is valid if
 *                                      Scc_StateMachineState_Failed is returned
 *  \return         Scc_StateMachineState_Done    Preparation succeeded
 *  \return         Scc_StateMachineState_Failed  An error occurred
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Prepare */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMSessionSetup_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Prepare */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMReadContrCertChain_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Prepare */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMAuthorizationSetup_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Prepare */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMAuthorization_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Prepare */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMReadRootCertificate_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Prepare */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMReadOemProvCert_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Prepare */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMCertificateInstallation_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Prepare */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMServiceDiscovery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Prepare */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMServiceDetail_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Prepare */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMServiceSelection_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Prepare */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMScheduleExchange_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Prepare */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMPowerDelivery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Prepare */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMSessionStop_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Prepare */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_RestoreOldSessionInformation_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM<StateMachineState>_Wait
 *********************************************************************************************************************/
/*! \brief          Wait for reception of the associated response message.
 *  \details        -
 *  \param[out]     ErrorInformation    Pointer to error information to set. The error information is valid if
 *                                      Scc_StateMachineState_Failed is returned
 *  \return         Scc_StateMachineState_Done    Waiting is finished
 *  \return         Scc_StateMachineState_Pending The operation is still ongoing
 *  \return         Scc_StateMachineState_Failed  An error occurred
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Wait */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMSessionSetup_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Wait */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMReadContrCertChain_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Wait */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMAuthorizationSetup_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Wait */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMAuthorization_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Wait */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMReadRootCertificate_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Wait */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMReadOemProvCert_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Wait */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMCertificateInstallation_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Wait */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMServiceDiscovery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Wait */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMServiceDetail_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Wait */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMServiceSelection_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Wait */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMScheduleExchange_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Wait */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMPowerDelivery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Wait */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMSessionStop_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM<StateMachineState>_Process
 *********************************************************************************************************************/
/*! \brief          Processes the received response message
 *  \details        -
 *  \param[out]     NextState           Pointer to the next state to set. The error information is valid if
 *                                      Scc_StateMachineState_Done is returned
 *  \param[out]     ErrorInformation    Pointer to error information to set. The error information is valid if
 *                                      Scc_StateMachineState_Failed is returned
 *  \return         Scc_StateMachineState_Done    Processing succeeded
 *  \return         Scc_StateMachineState_Pending The operation is still ongoing
 *  \return         Scc_StateMachineState_Failed  An error occurred
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Process */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMSessionSetup_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Process */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMReadContrCertChain_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Process */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMAuthorizationSetup_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Process */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMAuthorization_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Process */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMReadRootCertificate_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Process */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMReadOemProvCert_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Process */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMCertificateInstallation_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Process */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMServiceDiscovery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Process */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMServiceDetail_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Process */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMServiceSelection_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Process */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMScheduleExchange_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Process */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMPowerDelivery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20CM_StateM<StateMachineState>_Process */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMSessionStop_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_StateM_<StateMachineState>_Process */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_RestoreOldSessionInformation_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/**********************************************************************************************************************/
/* State Machine Callouts                                                                                             */
/**********************************************************************************************************************/
/***************************************************************************************
 * AuthorizationSetupRes
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_AuthorizationServices
 *********************************************************************************************************************/
/*! \brief          Scc -> Scc_StateMachine
 *  \details        Stores the received authorization services in the common workspace of the state machine
 *  \param[in]      AuthorizationServicesPtr    Pointer to the received authorization services
 *  \param[in]      AuthorizationServicesCount  The number of authorization services
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(void, AUTOMATIC) Scc_ISO15118_20CM_StateM_Set_AuthorizationServices(
  P2CONST(Exi_ISO_20_CM_10_authorizationType, AUTOMATIC, SCC_APPL_DATA) AuthorizationServicesPtr,
  uint8 AuthorizationServicesCount);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_CertificateInstallationService
 *********************************************************************************************************************/
/*! \brief          Scc -> Scc_StateMachine
 *  \details        Stores the received information if the certificate installation service is available
 *                  in the common workspace of the state machine
 *  \param[in]      CertificateInstallationService  The received certificate installation service.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(void, AUTOMATIC) Scc_ISO15118_20CM_StateM_Set_CertificateInstallationService(
  boolean CertificateInstallationService);

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_AuthorizationMode
 *********************************************************************************************************************/
/*! \brief          Scc -> Scc_StateMachine
 *  \details        Stores the received information of AuthorizationMode in the common workspace of the state machine
 *  \param[in]      DataPtr  The received AuthorizationSetupResChoiceType.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Set_AuthorizationMode(
  P2CONST(Exi_ISO_20_CM_10_AuthorizationSetupResChoiceType, AUTOMATIC, SCC_APPL_DATA) DataPtr);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */


/***************************************************************************************
 * AuthorizationReq
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_SelectedAuthorizationService
 *********************************************************************************************************************/
/*! \brief          Scc <- Scc_StateMachine
 *  \details        Sets the chosen AuthorizationService to be transmitted
 *  \param[out]     SelectedAuthorizationServicePtr  Pointer to the chosen authorization mode. Must not be NULL_PTR.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(void, AUTOMATIC) Scc_ISO15118_20CM_StateM_Get_SelectedAuthorizationService(
  P2VAR(Exi_ISO_20_CM_10_authorizationType, AUTOMATIC, SCC_APPL_DATA) SelectedAuthorizationServicePtr);


/***************************************************************************************
 * CertificateInstallationReq
 ***************************************************************************************/
#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_RemainingContractCertificateChains
 *********************************************************************************************************************/
/*! \brief          Scc -> Scc_StateMachine
 *  \details        Stores the received information in the common workspace of the state machine
 *  \param[in]      Data  The received RemainingContractCertificateChains.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Set_RemainingContractCertificateChains(uint8 Data);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_PrioritizedEMAIDs
 *********************************************************************************************************************/
/*! \brief          Scc <- Scc_StateMachine
 *  \details        Sets the PrioritizedEMAIDs to be transmitted
 *  \param[out]     DataPtr  Pointer to PrioritizedEMAIDs. Must not be NULL_PTR
 *  \param[out]     Flag     Pointer to the presence flag for PrioritizedEMAIDs. Must not be NULL_PTR
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Get_PrioritizedEMAIDs(
  P2VAR(Exi_ISO_20_CM_10_EMAIDListType*, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */


/***************************************************************************************
 * ServiceDiscoveryReq
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_SupportedServiceIDs
 *********************************************************************************************************************/
/*! \brief          Scc <- Scc_StateMachine
 *  \details        Sets the list of SupportedServiceIDs to be transmitted
 *  \param[out]     SupportedServiceIDsPtr  Pointer to the list of supported service IDs. Must not be NULL_PTR
 *  \param[out]     Flag                    Pointer to the presence flag for SupportedServiceIDsPtr. Must not be NULL_PTR
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(void, AUTOMATIC) Scc_ISO15118_20CM_StateM_Get_SupportedServiceIDs(
  P2VAR(Exi_ISO_20_CM_10_ServiceIDListType, AUTOMATIC, SCC_APPL_DATA) SupportedServiceIDsPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);


/***************************************************************************************
 * ServiceDiscoveryRes
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_ServiceRenegotiationSupported
 *********************************************************************************************************************/
/*! \brief          Scc -> Scc_StateMachine
 *  \details        Sets the information about the support of the ServiceRenegotiation
 *  \param[in]      ServiceRenegotiationSupported  Flag indicating if ServiceRenegotiation is available.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(void, AUTOMATIC) Scc_ISO15118_20CM_StateM_Set_ServiceRenegotiationSupported(
  boolean ServiceRenegotiationSupported);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_EnergyTransferServiceList
 *********************************************************************************************************************/
/*! \brief          Scc -> Scc_StateMachine
 *  \details        Sets the list of available energy transfer services
 *  \param[in]      EnergyTransferServiceListPtr  List of the available services.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(void, AUTOMATIC) Scc_ISO15118_20CM_StateM_Set_EnergyTransferServiceList(
  P2CONST(Exi_ISO_20_CM_10_ServiceListType, AUTOMATIC, SCC_APPL_DATA) EnergyTransferServiceListPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_VASList
 *********************************************************************************************************************/
/*! \brief          Scc -> Scc_StateMachine
 *  \details        Sets the list of available value added services
 *  \param[in]      VASListPtr  List of the available services.
 *  \param[in]      Flag        Flag indicating if a service list is present.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(void, AUTOMATIC) Scc_ISO15118_20CM_StateM_Set_VASList(
  P2CONST(Exi_ISO_20_CM_10_ServiceListType, AUTOMATIC, SCC_APPL_DATA) VASListPtr,
  Exi_BitType Flag);


/***************************************************************************************
 * ServiceDetailReq
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_ServiceIDRx
 *********************************************************************************************************************/
/*! \brief          Scc <- Scc_StateMachine
 *  \details        Sets the service ID which shall be requested in the ServiceDetailReq
 *  \param[out]     ServiceIDPtr  Pointer to the chosen service ID. Must not be NULL_PTR.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(void, AUTOMATIC) Scc_ISO15118_20CM_StateM_Get_ServiceIDRx(
  P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) ServiceIDPtr);


/***************************************************************************************
 * ServiceDetailRes
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_ServiceIDTx
 *********************************************************************************************************************/
/*! \brief          Scc -> Scc_StateMachine
 *  \details        Sets the received service ID from the ServiceDetailRes
 *  \param[in]      ServiceID  Service ID.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(void, AUTOMATIC) Scc_ISO15118_20CM_StateM_Set_ServiceIDTx(uint16 ServiceID);


/***************************************************************************************
 * ServiceSelectionReq
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_SelectedEnergyTransferService
 *********************************************************************************************************************/
/*! \brief          Scc <- Scc_StateMachine
 *  \details        Sets the chosen EnergyTransferService to be transmitted
 *  \param[out]     SelecteEnergyTransferServicePtr  Pointer to the selected energy transfer service. Must not be NULL_PTR.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(void, AUTOMATIC) Scc_ISO15118_20CM_StateM_Get_SelectedEnergyTransferService(
  P2VAR(Exi_ISO_20_CM_10_SelectedServiceType, AUTOMATIC, SCC_APPL_DATA) SelecteEnergyTransferServicePtr);

/***************************************************************************************
 * ChargeLoopRes
 ***************************************************************************************/
#if ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_MeterInfo
 *********************************************************************************************************************/
/*! \brief          Scc -> Scc_StateMachine
 *  \details        Sets the received MeterInfo from the ChargeLoopRes
 *  \param[in]      DataPtr  Pointer to the MeterInfo.
 *  \param[in]      Flag     Flag if MeterInfo is present or not.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Set_MeterInfo(
  P2CONST(Exi_ISO_20_CT_10_MeterInfoType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag);
#endif /* SCC_ENABLE_METERING_RECEIPT */

#if ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_Receipt
 *********************************************************************************************************************/
/*! \brief          Scc -> Scc_StateMachine
 *  \details        Sets the received Receipt from the ChargeLoopRes
 *  \param[in]      DataPtr  Pointer to the Receipt.
 *  \param[in]      Flag     Flag if Receipt is present or not.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Set_Receipt(
  P2CONST(Exi_ISO_20_CT_10_ReceiptType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag);
#endif /* SCC_ENABLE_METERING_RECEIPT */


/***************************************************************************************
 * PowerDeliveryReq
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_ChargeProgress
 *********************************************************************************************************************/
/*! \brief          Scc <- Scc_StateMachine
 *  \details        Sets the chosen ChargeProgress to be transmitted
 *  \param[out]     ChargeProgressPtr  Pointer to the ChargeProgress. Must not be NULL_PTR.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Get_ChargeProgress(P2VAR(Exi_ISO_20_CM_10_chargeProgressType, AUTOMATIC, SCC_VAR_NOINIT) ChargeProgressPtr);


/***************************************************************************************
 * MeteringConfirmationReq
 ***************************************************************************************/
#if ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_MeterInfoRx
 *********************************************************************************************************************/
/*! \brief          Scc <- Scc_StateMachine
 *  \details        Sets the MeterInfo to be transmitted
 *  \param[out]     MeterInfoPtr  Pointer to the MeterInfo. Must not be NULL_PTR.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Get_MeterInfoRx(P2VAR(Exi_ISO_20_CT_10_MeterInfoType*, AUTOMATIC, SCC_APPL_DATA) MeterInfoPtr);
#endif /* SCC_ENABLE_METERING_RECEIPT */

#if ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_ReceiptRx
 *********************************************************************************************************************/
/*! \brief          Scc <- Scc_StateMachine
 *  \details        Sets the Receipt to be transmitted
 *  \param[out]     ReceiptPtr  Pointer to the Receipt. Must not be NULL_PTR.
 *  \param[out]     Flag        Pointer to the presence flag for Receipt. Must not be NULL_PTR
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Get_ReceiptRx(
  P2VAR(Exi_ISO_20_CT_10_ReceiptType*, AUTOMATIC, SCC_APPL_DATA) ReceiptPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
#endif /* SCC_ENABLE_METERING_RECEIPT */


/***************************************************************************************
 * SessionStopReq
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_ChargingSession
 *********************************************************************************************************************/
/*! \brief          Scc <- Scc_StateMachine
 *  \details        Sets the ChargingSession to be transmitted
 *  \param[out]     ChargingSessionPtr  Pointer to the ChargingSession. Must not be NULL_PTR.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Get_ChargingSession(P2VAR(Exi_ISO_20_CM_10_chargingSessionType, AUTOMATIC, SCC_APPL_DATA) ChargingSessionPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_GoToPause
 *********************************************************************************************************************/
/*! \brief          Stores the passed GoToPause information
 *  \details        Scc Core propagates the variable to the state machine
 *  \param[in]      GoToPause to set
 *  \param[in]      Flag     Flag whether or not the DataPtr was sent by EVSE or not
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Set_GoToPause(
  boolean GoToPause,
  Exi_BitType Flag);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_ScheduleExchangeResChoice
 *********************************************************************************************************************/
/*! \brief          Stores the passed first PowerScheduleEntry power information
 *  \details        Scc Core propagates the variable to the state machine
 *  \param[in]      DataPtr  Exi_ISO_20_CM_10_ScheduleExchangeResChoice to set
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Set_ScheduleExchangeResChoice(P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeResChoiceType, AUTOMATIC, SCC_APPL_DATA) DataPtr);

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_GenChallenge
 *********************************************************************************************************************/
/*! \brief          Scc <- Scc_StateMachine
 *  \details        Sets the GenChallenge to be transmitted
 *  \param[out]     GenChallengePtr  Pointer to the GenChallenge.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Get_GenChallenge(P2VAR(Exi_ISO_20_CM_10_genChallengeType*, AUTOMATIC, SCC_APPL_DATA) GenChallengePtr);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE && SCC_SCHEMA_ISO_20 */

#endif /* SCC_ISO15118_20CM_STATEM_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20CM_StateM.h
 *********************************************************************************************************************/
